#ifndef COMPONENT_H
#define COMPONENT_H

class GameMaster;

class Component
{
public:
	virtual void Update (float dt)= 0;
	inline void SetGameMaster(GameMaster* gm) { gameMaster = gm; }

protected:
	GameMaster* gameMaster;
};

#endif