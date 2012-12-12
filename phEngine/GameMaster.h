#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>

#include "IRenderer.h"

class Component;

class GameMaster
{
public:
	inline void SetRenderer(IRenderer* theRenderer) { renderer = theRenderer; }
	inline IRenderer& GetRenderer() { return *renderer; }
	void RegisterComponent(Component* component);
	int Run();

private:
	void Update(float dt);
private:
	IRenderer* renderer;
	std::vector<Component*> components;
};

#endif