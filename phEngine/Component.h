#ifndef COMPONENT_H
#define COMPONENT_H

#include "GameMaster.h"

class Component
{
public:
	virtual void Update (float dt)= 0;
	inline void SetGameMaster(GameMaster* gm) 
	{ 
		gameMaster = gm;
		OnRegister();
	}
	virtual void OnRegister(){};

protected:
	GameMaster* gameMaster;
};

#endif