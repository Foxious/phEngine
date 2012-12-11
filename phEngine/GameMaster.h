#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>

#include "Component.h"
#include "IRenderer.h"

class GameMaster
{
public:
	inline void SetRenderer(IRenderer* theRenderer) { renderer = theRenderer; }
	inline IRenderer& GetRenderer(IRenderer* theRenderer) { return *renderer; }
	void RegisterComponent(Component* component);
	int Run();

private:
	void Update(float dt);
private:
	IRenderer* renderer;
	std::vector<Component*> components;
};

#endif