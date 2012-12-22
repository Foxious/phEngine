#ifndef SHAPES_H
#define SHAPES_H

#include "Vector.h"

struct Box
{
	Vector2 position;
	Vector2 size;

	Vector2 GetUpperLeft()	const { return position;									}
	Vector2 GetUpperRight() const { return Vector2(position.x + size.x, position.y);	}
	Vector2 GetLowerRight()	const { return Vector2(position.x, position.y + size.y);	}
	Vector2 GetLowerLeft()	const { return position + size;	}
};

bool AnyPointsWithinBox (const Box* box, Vector2* points, unsigned numPoints);
bool BoxesIntersect (const Box* box1, const Box* box2);

#endif