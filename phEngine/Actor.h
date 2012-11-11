#ifndef ACTOR_H
#define ACTOR_H

#include "Vector.h"
#include "Mesh.h"

class Actor
{
	// an Actor is a thing on the stage.
public:
	Actor();
	void SetSprite(MeshInstance* sprite);
	void MoveX(float value);
	void MoveY(float value);

private:
	MeshInstance* mSprite;
};

#endif