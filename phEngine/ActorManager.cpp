#include "stdafx.h"
#include "ActorManager.h"

#include "ActorScript.h"
#include "json.h"

enum ActorKeysEnum
{
	sprite=0,
	controller,
	scripts,
	
	NUM_KEYS
};

const char* actorKeys[NUM_KEYS] = {"Sprite", "Controller", "Scripts"};


/////////////////////////////////////////////////////////////////////////////////////////
ActorPtr ActorManager::GetActor(const std::string& resourceFile)
{
	if (actorDefinitions.find(resourceFile) == actorDefinitions.end())
	{
		return DeserializeActor(JsonStringFromFile(resourceFile.c_str()), resourceFile);
	}

	return actors.Insert(actorDefinitions[resourceFile]);
}

ActorPtr ActorManager::DeserializeActor(const std::string& actorData, const std::string& resourceName)
{
	Actor newActor;
	newActor.SetController(&propController);
	MeshInstancePtr sprite;

	jsmn_parser parser;
	jsmn_init(&parser);

	jsmntok_t tokens[256];
	jsmnerr_t r = jsmn_parse(&parser, actorData.c_str(), tokens, 256);

	int i = 1;
	std::string keyStr;
	jsmntok_t *keyTok;
	int count=0;
	while(tokens[count].type >= 0) ++count;
	while(i < count)
	{
		keyTok = &tokens[i];
		keyStr = SubstringFromToken(actorData, *keyTok);

		if (keyStr.compare( actorKeys[ActorKeysEnum::sprite]) == 0)
		{
			sprite = gameMaster->GetRenderer().GetMesh( SubstringFromToken(actorData, tokens[++i]).c_str() );
		}
		else if (keyStr.compare(actorKeys[ActorKeysEnum::controller]) == 0)
		{
			std::string controller = SubstringFromToken(actorData, tokens[++i]);
			if (controller.compare("playerController") == 0)
			{
				newActor.SetController(playerController);
			}
		}
		else if (keyStr.compare(actorKeys[ActorKeysEnum::scripts])==0)
		{
			jsmntok_t collectionTok = tokens[++i];
			jsmntok_t scriptTok;
			for (size_t j = 0; j = collectionTok.size; ++j)
			{
				scriptTok = tokens[++i];
				newActor.SetScriptEvent(j, VM::LoadCompiledScript( SubstringFromToken(actorData, scriptTok)) );
			}
		}
		++i;
	} // end while
	newActor.SetSprite(sprite);
	actorDefinitions.insert(actorDefinitions.begin(), std::unordered_map<std::string, Actor>::value_type(resourceName, newActor) );
	return actors.Insert( newActor );
}

// ACTOR MANAGER ////////////////////////////////////////////////////////////////////////
ActorManager::ActorManager()
	: actors(1000)
	, collider(Vector2(-512.0f, -512.0f), 512.0f, 3)
{
	playerController = new PlayerController(0, this);
}

// PUBLIC //////////////////////////////////////////////////////////////////////////////
void ActorManager::OnRegister()
{
	ActorPtr player = CreateActorStub();
	player->SetController(playerController);

	VM::Script collisionScript;
	char playName[10];
	VM::ptr size = strlen("Jump") + 1;
	memcpy(&playName[0], &size, VM::ptr_size);
	memcpy(&playName[VM::ptr_size], "Jump", size);
	collisionScript.push_back( VM::Instruction(VM::op_push, (unsigned char*)playName, VM::ptr_size + size) );


	unsigned char playData[2] = { 0, 8 };
	collisionScript.push_back( VM::Instruction(VM::op_playanim, playData, 2*sizeof(unsigned char) ) );

	VM::scriptID id = VM::AddScript(collisionScript);
	
	player->SetScriptEvent(ev_collision, id);
}

void ActorManager::Update(float dt)
{
	collider.Clear();
	ObjectPool<Actor>::Iterator it = actors.Begin();

	for (; it.IsValid(); ++it)
	{
		it->Update(dt);
		collider.ResolveCollisions(&(*it));
		collider.Classify(&(*it));

		if ( it->IsDead() )
		{
			gameMaster->GetRenderer().RemoveMeshInstance(it->GetSprite());
			it->ClearScripts();
			actors.Remove(it);
		}
	}

	collider.Clear();
}

ActorPtr ActorManager::CreateActorStub()
{
	Actor newActor;
	MeshInstancePtr sprite = gameMaster->GetRenderer().GetMesh("testSpriteDef.json");
	newActor.SetSprite(sprite);
	newActor.SetController(&propController);
	VM::Script collisionScript;
	VM::ptr data[2] = {0, 4};
	collisionScript.push_back( VM::Instruction(VM::op_forceout, data, 2* VM::ptr_size) );
	VM::scriptID id = VM::AddScript(collisionScript);
	newActor.SetScriptEvent(ev_collision, id);
	ActorPtr actor = actors.Insert(newActor);
	return actor;
}

ActorPtr ActorManager::CloneActor(const ActorPtr source)
{
	Actor newActor;
	MeshInstancePtr sprite = gameMaster->GetRenderer().CopyMesh( source->GetSprite() );
	ActorPtr actor = actors.Insert(newActor);
	return actor;
}

// PLAYER CONTROLLER ////////////////////////////////////////////////////////////////////
void PlayerController::Update(Actor* actor, float dt)
{
	inputMapper->Update(dt); // todo - this should just be taken care of by the GM

	float multiplier = 1.0f;
	if ( inputMapper->GetButtonState(InputMapper::runBtn) )
	{
		multiplier = 2.0f;
	}

	Vector2 move;
	float moveSpeed = actor->speed * dt * multiplier;
	move.x = inputMapper->GetAxisState(InputMapper::lrAxis) * moveSpeed;
	move.y = inputMapper->GetAxisState(InputMapper::duAxis) * moveSpeed;

	char leftButton		= inputMapper->GetButtonStateToggle(InputMapper::leftBtn);
	char rightButton	= inputMapper->GetButtonStateToggle(InputMapper::rightBtn);
	char upButton		= inputMapper->GetButtonStateToggle(InputMapper::upBtn);
	char downButton		= inputMapper->GetButtonStateToggle(InputMapper::downBtn);

	if (leftButton || rightButton)
	{
		move.x = (rightButton - leftButton) * moveSpeed;
	}
	if (upButton || downButton)
	{
		move.y = (upButton - downButton) * moveSpeed;
	}
		
	if (move != Vector2::Zero )
	{
		actor->Move(move);
		actor->GetAnimComponent()->PlayAnim("Walk");
		actor->GetAnimComponent()->SetPlaybackSpeed(multiplier * 0.5f);
	}

	if (inputMapper->GetButtonState(InputMapper::atkBtn) == BTN_DOWN)
	{
		actor->GetAnimComponent()->PlayAnim(0U);

		ActorPtr subActor = actorManager->CreateActorStub();
		subActor->WarpTo(actor->GetPosition() + actor->GetDirection() * 350.0f);
		subActor->GetAnimComponent()->PlayAnim(0U);
			
		/*VM::ScriptNode* killActor = new KillActorNode();
		VM::ScriptNode* delay = new TimerNode(3.0f);
		delay->AddScriptCompleteCallback(killActor);

		subActor->updateScript.push_back(delay);*/
	}

	if ( !actor->GetAnimComponent()->IsPlaying() )
	{
		actor->GetAnimComponent()->PlayAnim("Idle", Anim_Loop);
	}
}