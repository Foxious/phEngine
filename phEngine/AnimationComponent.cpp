#include "stdafx.h"
#include "AnimationComponent.h"

#include <assert.h>
#include <limits.h>
#include <string>

// pH TODO - migrate this elsewhere
#include "json.h"

#include <fstream>

// HELPERS //////////////////////////////////////////////////////////////////////////////

#define NOT_FOUND UINT_MAX


// pH Warnning - these need to stay in sync
const char* animKeys[5] = {"CellSize", "Anims", "Name", "Start", "Duration"};
enum AnimKeysEnum
{
	cellSize,
	animsKey,
	animName,
	animStart,
	animData,

	NUM_KEYS
};

AnimationData DeserializeAnimation(const std::string& jsonData, jsmntok_t* tokens, size_t* start, size_t numToks)
{
	size_t end = numToks + *start;
	std::string tokStr;

	AnimationData data;

	while (*start < end)
	{
		jsmntok_t & thisTok = tokens[*start];
		tokStr = SubstringFromToken(jsonData, thisTok); 

		if (tokStr.compare(animKeys[animName]) == 0)
		{
			data.name = SubstringFromToken(jsonData, tokens[++(*start)]);
		}

		else if (tokStr.compare(animKeys[animStart]) == 0)
		{
			std::string startFrameStr = SubstringFromToken(jsonData, tokens[++(*start)]);
			data.startFrame = strtoul(startFrameStr.c_str(), NULL, 0);
		}
		else if (tokStr.compare(animKeys[animData]) == 0)
		{
			jsmntok_t & collectionTok = tokens[++(*start)];
			data.frames.reserve(collectionTok.size);
			for (int x = 0; x < collectionTok.size; ++x)
			{
				data.frames.push_back(FloatFromToken(jsonData, tokens[++(*start)]));
			}
		}
		++(*start);
	}

	return data;
}

// CTORS ////////////////////////////////////////////////////////////////////////////////
AnimationComponent::AnimationComponent(const std::string& jsonData)
	: time(0.0f)
	, currentFrame(0)
	, state (0)
{
	ParseJsonData(jsonData);
}

// PUBLIC ///////////////////////////////////////////////////////////////////////////////
void AnimationComponent::PlayAnim(unsigned int index, int flags)
{
	// if this asserts, the index is past the range.
	assert(index < anims.size());

	playbackFlags = flags;

	if (index == currentAnimIndex && IsPlaying())
	{
		return;
	}
	state = Anim_Playing;
	currentAnimIndex = index;
	time = 0.0f;
	currentFrame = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::PlayAnim(const char* name, int flags)
{
	PlayAnim(std::string(name), flags);
}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::PlayAnim(const std::string& name, int flags)
{
	unsigned int anim = FindAnim(name);
	if (anim != NOT_FOUND)
	{
		PlayAnim(anim, flags);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::PauseAnim()
{
	state |= Anim_Paused;
}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::ResumeAnim()
{
	state &= ~Anim_Paused;
}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::Update(float dt)
{
	if (IsPaused() || !IsPlaying())
	{
		return;
	}
	AnimationData thisAnim = GetCurrentAnim();
	int startFrame = thisAnim.startFrame;

	float dur = thisAnim.frames[currentFrame];
	time += dt;
	while (time > dur && currentFrame < thisAnim.frames.size())
	{
		time -= dur;
		++currentFrame;
		if (playbackFlags & Anim_Loop)
		{
			currentFrame %= thisAnim.frames.size();
		}
		else if (currentFrame >= thisAnim.frames.size())
		{
			state = 0;
			return;
		}
		dur = thisAnim.frames[currentFrame];
	}

	unsigned int framesPerRow = (unsigned int)(1.0f / mUV.scale.x);
	
	mUV.position.x = ( (currentFrame + startFrame) % framesPerRow) * mUV.scale.x;
	mUV.position.y = ( (currentFrame + startFrame) / framesPerRow) * mUV.scale.y;

}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::LoadFromJSON(const std::string& name)
{
	ParseJsonData( JsonStringFromFile( name.c_str() ) );
}

// PRIVATE //////////////////////////////////////////////////////////////////////////////
unsigned int AnimationComponent::FindAnim(const std::string& name)
{
	std::vector<AnimationData>::iterator it = anims.begin();
	std::vector<AnimationData>::iterator end = anims.end();

	for (; it!= end; ++it)
	{
		if (it->name == name)
		{
			return it - anims.begin();
		}
	}

	return NOT_FOUND;

}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::ClearData()
{
	anims.clear();
}

/////////////////////////////////////////////////////////////////////////////////////////
void AnimationComponent::ParseJsonData(const std::string& jsonData)
{
	ClearData();

	jsmn_parser parser;
	jsmn_init(&parser);

	jsmntok_t tokens[256];
	jsmnerr_t r = jsmn_parse(&parser, jsonData.c_str(), tokens, 256);

	char str[255];

	size_t i = 1;
	std::string keyStr;
	jsmntok_t *keyTok;
	size_t count=0;
	while(tokens[count].type >= 0) ++count;
	while (i < count)
	{
		 keyTok = &tokens[i];

		 keyStr = SubstringFromToken(jsonData, *keyTok);

		if (keyStr.compare(animKeys[cellSize])==0)
		{
			jsmntok_t & cellTok = tokens[++i];
			mUV.scale.x = FloatFromToken(jsonData, tokens[++i]);
			mUV.scale.y = FloatFromToken(jsonData, tokens[++i]);
		}

		else if (keyStr.compare(animKeys[animsKey]) == 0)
		{
			// we have an animation
			jsmntok_t & animTok = tokens[++i];
			++i;
			for (int j = 0; j < animTok.size; ++j)
			{
				jsmntok_t *animData = &tokens[i];
				anims.push_back(DeserializeAnimation(jsonData, tokens, &i, animData->size));
				//i += animData->size;
			}

			i += animTok.size;
		}
		++i;

	}
}

/////////////////////////////////////////////////////////////////////////////////////////
const AnimationData& AnimationComponent::GetCurrentAnim()
{
	assert(!anims.empty());
	return anims[currentAnimIndex];
}