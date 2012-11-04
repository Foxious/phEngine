#include "stdafx.h"
#include "Animation.h"

Animation::Animation()
	: mStartFrame(0)
	, mCurrentFrame(0)
	, mTime(0.0f)
{
	// pH TODO - This is a hard coded thing to
	// test that the system is working. Make this
	// data driven.
	mFrames.resize(3);

	for (size_t i = 0; i < 3; ++i)
	{
		mFrames[i] = 0.25f;
	}
	mFrames[2] = 1.2f;
}

Animation::Animation(unsigned int startFrame, const std::string& name, const std::vector<float>& frameData)
	: mStartFrame(startFrame)
	, mCurrentFrame(0)
	, mTime(0.0f)
	, mName(name)
	, mFrames(frameData)
{
}

void Animation::Update(float dt)
{
	float dur = mFrames[mCurrentFrame];
	mTime += dt;
	if (mTime > dur)
	{
		mTime -= dur;
		mCurrentFrame = (mCurrentFrame +1) % mFrames.size();
	}
}

void Animation::Reset()
{
	mTime = 0.0f;
}

unsigned int Animation::GetCurrentFrame() const
{
	return mCurrentFrame + mStartFrame;
}

const std::string& Animation::GetName() const
{
	return mName;
}