#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>

#include "IRenderer.h"
#include "InputManager.h"

class Component;

class GameMaster
{
public:
	inline void SetRenderer(IRenderer* theRenderer) { renderer = theRenderer; }
	inline void SetInput(InputManager* inputManager) { input = inputManager; }

	inline IRenderer& GetRenderer() { return *renderer; }
	inline InputManager& GetInput() { return *input;} 

	void RegisterComponent(Component* component);
	int Run();

private:
	void Update(float dt);
private:
	IRenderer* renderer;
	InputManager* input;
	std::vector<Component*> components;
};

#endif