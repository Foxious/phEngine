#ifndef COLLISION_H
#define COLLISION_H

#include <vector>
#include "Actor.h"

#include "Shapes.h"
#include "Vector.h"

class SpatialHash
{
public:
	SpatialHash(float bucketSize, unsigned int bucketStride)
		: size(bucketSize)
		, stride(bucketStride)
	{
		buckets.resize(bucketStride * bucketStride);
	}

	void Classify(Actor* collider);
	void Clear();

	const std::vector<Actor*>& operator[] (unsigned int index);
	void GetNearbyActors(const Actor* actor, std::vector<Actor*>& outActors);
	void ResolveCollisions(Actor* actor);

private:
	unsigned int HashPosition(Vector2 position);

private:
	float size;
	unsigned int stride;

	std::vector< std::vector<Actor*> > buckets;
};
#endif