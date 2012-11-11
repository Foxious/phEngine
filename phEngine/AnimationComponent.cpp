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
const char* animKeys[6] = {"Texture", "CellSize", "Anims", "Name", "Start", "Duration"};
enum AnimKeysEnum
{
	texture,
	cellSize,
	anims,
	animName,
	animStart,
	animData,

	NUM_KEYS
};

Animation DeserializeAnimation(const std::string& jsonData, jsmntok_t* tokens, size_t numToks)
{
	size_t i = 0;
	std::string tokStr;

	std::string name;
	unsigned int startFrame;
	std::vector<float>frameData;

	while (i < numToks)
	{
		jsmntok_t & thisTok = tokens[i];
		tokStr = SubstringFromToken(jsonData, thisTok); 

		if (tokStr.compare(animKeys[animName]) == 0)
		{
			name = SubstringFromToken(jsonData, tokens[++i]);
		}

		else if (tokStr.compare(animKeys[animStart]) == 0)
		{
			std::string startFrameStr = SubstringFromToken(jsonData, tokens[++i]);
			startFrame = strtoul(startFrameStr.c_str(), NULL, 0);
		}
		else if (tokStr.compare(animKeys[animData]) == 0)
		{
			jsmntok_t & collectionTok = tokens[++i];
			frameData.reserve(collectionTok.size);
			for (int x = 0; x < collectionTok.size; ++x)
			{
				frameData.push_back(FloatFromToken(jsonData, tokens[++i]));
			}
		}
		++i;
	}

	return Animation(startFrame, name, frameData);
}

// CTORS ////////////////////////////////////////////////////////////////////////////////
AnimationComponent::AnimationComponent(const std::string& jsonData)
	: mTime(0.0f)
{
	ParseJsonData(jsonData);
}

void AnimationComponent::PlayAnim(unsigned int index)
{
	// if this asserts, the index is past the range.
	assert(index < mAnims.size());

	mCurrentAnimIndex = index;
	GetCurrentAnim().Reset();
}

void AnimationComponent::PlayAnim(const char* name)
{
	PlayAnim(std::string(name));
}

void AnimationComponent::PlayAnim(const std::string& name)
{
	unsigned int anim = FindAnim(name);
	if (anim != NOT_FOUND)
	{
		PlayAnim(anim);
	}
}

void AnimationComponent::Update(float dt)
{
	GetCurrentAnim().Update(dt);

	unsigned int currentFrame = GetCurrentAnim().GetCurrentFrame();
	unsigned int framesPerRow = (unsigned int)(1.0f / mUV.mScale.x);
	
	mUV.mPos.x = (currentFrame % framesPerRow) * mUV.mScale.x;
	mUV.mPos.y = (currentFrame / framesPerRow) * mUV.mScale.y;

}

Animation& AnimationComponent::GetCurrentAnim()
{
	assert(!mAnims.empty());
	return mAnims[mCurrentAnimIndex];
}

void AnimationComponent::ParseJsonData(const std::string& jsonData)
{
	jsmn_parser parser;
	jsmn_init(&parser);

	jsmntok_t tokens[20];
	jsmnerr_t r = jsmn_parse(&parser, jsonData.c_str(), tokens, 20);

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

		 if (keyStr.compare(animKeys[texture]) == 0)
		 {
			 // load texture here
		 }

		 else if (keyStr.compare(animKeys[cellSize])==0)
		 {
			 // pH TODO - test this shit
			 jsmntok_t & cellTok = tokens[++i];
			 mUV.mScale.x = FloatFromToken(jsonData, tokens[++i]);
			 mUV.mScale.y = FloatFromToken(jsonData, tokens[++i]);
		 }

		 else if (keyStr.compare(animKeys[anims]) == 0)
		 {
			 // we have an animation
			 jsmntok_t & animTok = tokens[++i];
			 for (int j = 0; j < animTok.size; ++j)
			 {
				jsmntok_t *animData = &tokens[++i];
				mAnims.push_back(DeserializeAnimation(jsonData, animData, animData->size));
			 }

			 i += animTok.size;
		 }
		++i;

	}
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
	std::vector<Animation>::iterator it = mAnims.begin();
	std::vector<Animation>::iterator end = mAnims.end();

	for (; it!= end; ++it)
	{
		if (it->GetName() == name)
		{
			return it - mAnims.begin();
		}
	}

	return NOT_FOUND;

}