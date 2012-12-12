#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include <string>
#include <vector>

#include "Texture.h"
#include "Vector.h"
#include "XForm.h"

struct AnimationData
{
	unsigned int startFrame;
	std::vector<float> frames;
	std::string name;
};

enum PlaybackFlags
{
	Anim_Loop = 0x01,
};

enum AnimationStates
{
	Anim_Playing = 0x01,
	Anim_Paused = 0x02,
	Anim_Finished = 0x04,
};


// Class that handles the interaction betweeen animations

// ph TODO : change this into a factory/manager thingamy so that
// we're not constantly reading from disk to load these.
class AnimationComponent
{
public:
	AnimationComponent() 
		: time(0.0f)
		, currentFrame(0)
		, playbackFlags(0)
	{
		currentAnimIndex = 0;
		LoadFromJSON("testAnim.json");
	}

	AnimationComponent(const std::string& jsonData);

	//AnimationComponent(const AnimationComponent& rhs);

	void Update(float dt);

	void PlayAnim(unsigned int index, int flags = 0);
	void PlayAnim(const std::string& name, int flags = 0);
	void PlayAnim(const char* name, int flags = 0);

	void PauseAnim();
	void ResumeAnim();

	bool IsPlaying() { return (state & Anim_Playing) > 0; }
	bool IsPaused() { return (state & Anim_Paused) > 0; }

	XForm GetXForm() { return mUV; }

	void LoadFromJSON(const std::string& name);

private:
	unsigned int FindAnim(const std::string& name);
	void ParseJsonData(const std::string& jsonData);
	const AnimationData& GetCurrentAnim();
	void ClearData();

private:

	float time;
	unsigned int currentFrame;
	XForm mUV;
	std::vector<AnimationData> anims;
	unsigned int currentAnimIndex;
	int playbackFlags;
	int state;

};

#endif