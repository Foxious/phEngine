#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include <string>
#include <vector>

#include "Animation.h"
#include "Texture.h"
#include "Vector.h"
#include "XForm.h"


// Class that handles the interaction betweeen animations and
// the textures they run on
class AnimationComponent
{
public:
	AnimationComponent() : mTime(0.0f)
	{
		mCurrentAnimIndex = 0;
		LoadFromJSON("testAnim.json");
	}

	AnimationComponent(const std::string& jsonData);

	void Update(float dt);

	void PlayAnim(unsigned int index);
	void PlayAnim(const std::string& name);
	void PlayAnim(const char* name);

	Animation& GetCurrentAnim();
	XForm GetXForm() { return mUV; }

	void LoadFromJSON(const std::string& name);

private:
	unsigned int FindAnim(const std::string& name);
	void ParseJsonData(const std::string& jsonData);

	float mTime;
	XForm mUV;
	std::vector<Animation> mAnims;
	unsigned int mCurrentAnimIndex;

};

#endif