#include "stdafx.h"
#include "Collision.h"

#include <assert.h>

bool IsWithin (Box box, const Vector2* points)
{
	for (int i = 0; i < 4; ++i)
	{
		if (points[i].x >= box.position.x
			&& points[i].x <= box.position.x + box.size.x
			&& points[i].y >= box.position.y
			&& points[i].y <= box.position.y + box.size.y)
		{
			return true;
		}
	}

	return false;
}

// PUBLIC ///////////////////////////////////////////////////////////////////////////////
void SpatialHash::Classify(Actor* collider)
{
	Box collision = *collider->GetCollision();
	int index;
	
	// upper left corner
	index = HashPosition(collision.position); 
	buckets[index].push_back(collider);

	// lower right corner
	index = HashPosition( collision.position + collision.size ); 
	buckets[index].push_back(collider);
}

/////////////////////////////////////////////////////////////////////////////////////////
void SpatialHash::GetNearbyActors(const Actor* actor, std::vector<Actor*>& outActors)
{
	Box collision = *actor->GetCollision();
	unsigned int index = HashPosition(collision.position);
	unsigned int index2 = HashPosition(collision.position + collision.size);

	std::vector<Actor*> upperCornerList = buckets[index];
	std::vector<Actor*> lowerCornerList;

	outActors.clear();

	if (index != index2)
	{
		lowerCornerList = buckets[index2];
	}

	outActors.reserve(upperCornerList.size() + lowerCornerList.size());
	outActors.insert(outActors.end(), upperCornerList.begin(),  upperCornerList.end());
	outActors.insert(outActors.end(), lowerCornerList.begin(), lowerCornerList.end());
}

/////////////////////////////////////////////////////////////////////////////////////////
void SpatialHash::Clear()
{
	std::vector< std::vector<Actor*> >::iterator it = buckets.begin();
	std::vector< std::vector<Actor*> >::iterator end = buckets.end();

	for (; it != end; ++it)
	{
		it->clear();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void SpatialHash::ResolveCollisions(Actor* actor)
{
	std::vector<Actor*> possibleCollisions;
	GetNearbyActors(actor, possibleCollisions);

	Box actorBox = *actor->GetCollision();
	Vector2 points[4];

	points[0] = actorBox.position;
	points[1] = actorBox.position + actorBox.size;
	points[2] = actorBox.position + Vector2(actorBox.size.x, 0.0f);
	points[3] = actorBox.position + Vector2(0.0f, actorBox.size.y);

	std::vector<Actor*>::iterator it = possibleCollisions.begin();
	std::vector<Actor*>::iterator end = possibleCollisions.end();

	for (; it != end; ++it)
	{
		Actor* testActor = *it;
		if ( AnyPointsWithinBox(testActor->GetCollision(), points, 4) )
		{
			// pH todo - the world hash should
			// behave a bit differently.
			actor->OnCollide(testActor);
			testActor->OnCollide(actor);
		}
	}
}

// OPERATORS ////////////////////////////////////////////////////////////////////////////
const std::vector<Actor*>& SpatialHash::operator[](unsigned int index)
{
	assert(index < stride * stride);

	return buckets[index];
}


// PRIVATE //////////////////////////////////////////////////////////////////////////////
unsigned int SpatialHash::HashPosition (Vector2 position)
{
	unsigned int bucketX = (unsigned int)(position.x / size);
	unsigned int bucketY = (unsigned int)(position.y / size);

	return (bucketY * stride) + bucketX;
}