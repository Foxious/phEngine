#ifndef __ANIMATION_MANAGER_H
#define __ANIMATION_MANAGER_H


#include <vector>

#include "Animation.h"
#include "AnimationComponent.h"
#include "IRenderer.h"

class AnimationManager
{
public:
	AnimationManager(){}

	void SetRenderer(IRenderer* renderer) { mRenderer = renderer; }

private:
	AnimationComponent& LoadFromFile(const std::string& filename);
	
private:
	IRenderer* mRenderer;
	std::vector<AnimationComponent> mAnimationComponents; // pH TODO: Evaluate if this would be better suited as an unordered_map
};

#endif