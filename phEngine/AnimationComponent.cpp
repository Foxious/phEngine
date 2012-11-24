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

AnimationData DeserializeAnimation(const std::string& jsonData, jsmntok_t* tokens, size_t numToks)
{
	size_t i = 0;
	std::string tokStr;

	AnimationData data;

	while (i < numToks)
	{
		jsmntok_t & thisTok = tokens[i];
		tokStr = SubstringFromToken(jsonData, thisTok); 

		if (tokStr.compare(animKeys[animName]) == 0)
		{
			data.name = SubstringFromToken(jsonData, tokens[++i]);
		}

		else if (tokStr.compare(animKeys[animStart]) == 0)
		{
			std::string startFrameStr = SubstringFromToken(jsonData, tokens[++i]);
			data.startFrame = strtoul(startFrameStr.c_str(), NULL, 0);
		}
		else if (tokStr.compare(animKeys[animData]) == 0)
		{
			jsmntok_t & collectionTok = tokens[++i];
			data.frames.reserve(collectionTok.size);
			for (int x = 0; x < collectionTok.size; ++x)
			{
				data.frames.push_back(FloatFromToken(jsonData, tokens[++i]));
			}
		}
		++i;
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

	if (index == currentAnimIndex && IsPaused())
	{
		ResumeAnim();
		return;
	}
	state = Anim_Playing;
	currentAnimIndex = index;
	time = 0.0f;
	currentFrame = 0;
}

void AnimationComponent::PlayAnim(const char* name, int flags)
{
	PlayAnim(std::string(name), flags);
}

void AnimationComponent::PlayAnim(const std::string& name, int flags)
{
	unsigned int anim = FindAnim(name);
	if (anim != NOT_FOUND)
	{
		PlayAnim(anim, flags);
	}
}

void AnimationComponent::PauseAnim()
{
	state |= Anim_Paused;
}

void AnimationComponent::ResumeAnim()
{
	state &= ~Anim_Paused;
}

void AnimationComponent::Update(float dt)
{
	if (IsPaused() || !IsPlaying())
	{
		return;
	}
	AnimationData thisAnim = GetCurrentAnim();

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
	
	mUV.position.x = (currentFrame % framesPerRow) * mUV.scale.x;
	mUV.position.y = (currentFrame / framesPerRow) * mUV.scale.y;

}

void AnimationComponent::LoadFromJSON(const std::string& name)
{
	int length = 0;
	char* buffer = 0;
	std::fstream f;
	f.open(name.c_str(), std::fstream::in);

	f.seekg(0, std::ios::end);
	length = f.tellg();
	f.seekg(0, std::ios::beg);

	buffer = new char [length];

	f.read(buffer, length);
	f.close();

	std::string fileData(buffer);

	ParseJsonData(fileData);

	delete [] buffer;
}

// PRIVATE ////////////////////////////////////////////////////////////////////
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
void AnimationComponent::ParseJsonData(const std::string& jsonData)
{
	jsmn_parser parser;
	jsmn_init(&parser);

	jsmntok_t tokens[256];
	jsmnerr_t r = jsmn_parse(&parser, jsonData.c_str(), tokens, 256);

	char str[255];

	int i = 1;
	std::string keyStr;
	jsmntok_t *keyTok;
	int count=0;
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
			for (int j = 0; j < animTok.size; ++j)
			{
				jsmntok_t *animData = &tokens[++i];
				anims.push_back(DeserializeAnimation(jsonData, animData, animData->size));
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