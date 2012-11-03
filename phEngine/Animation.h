#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

// class to represent a single animation.
// right now, all that should be needed is
// a list of frame durations and some
// bookkeepping for what frame we're
// currently on
class Animation
{
public:
	Animation();
	Animation(unsigned int startFrame, const std::string& name, const std::vector<float>& frameData);

	void Update(float dt);
	void Reset();
	unsigned int GetCurrentFrame() const;
	const std::string & GetName() const;
private:
	unsigned int mStartFrame;
	unsigned int mCurrentFrame;
	float mTime;
	std::vector<float> mFrames;
	std::string mName;
};

#endif