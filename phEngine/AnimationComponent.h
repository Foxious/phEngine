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
	AnimationComponent() : mTex(0), mXform(), mTime(0.0f), mFramesPerRow(0), mCellSize(32.0f, 32.0f) 
	{
		mCurrentAnimIndex = 0;
		LoadFromJSON("testAnim.json");
	}

	AnimationComponent(const std::string& jsonData);

	void SetTexture (const ITexture * texture);
	void Update(float dt);
	inline XForm & GetUVXform() { return mXform; }
	Vector2 GetCellSize();

	void PlayAnim(unsigned int index);
	void PlayAnim(const std::string& name);
	void PlayAnim(const char* name);

	Animation& GetCurrentAnim();

	void LoadFromJSON(const std::string& name);

private:
	unsigned int FindAnim(const std::string& name);
	void ParseJsonData(const std::string& jsonData);

	const ITexture * mTex;
	XForm mXform;
	float mTime;
	unsigned int mFramesPerRow;
	Vector2 mCellSize;
	std::vector<Animation> mAnims;
	unsigned int mCurrentAnimIndex;

};

#endif