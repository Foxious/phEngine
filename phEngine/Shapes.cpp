#include "stdafx.h"

#include "Shapes.h"

bool AnyPointsWithinBox (const Box* box, Vector2* points, unsigned numPoints)
{
	for (unsigned i = 0; i < numPoints; ++i)
	{
		if (points[i].x >= box->position.x
			&& points[i].x <= box->position.x + box->size.x
			&& points[i].y >= box->position.y
			&& points[i].y <= box->position.y + box->size.y)
		{
			return true;
		}
	}

	return false;
}

bool BoxesIntersect (const Box* box1, const Box* box2)
{
	Vector2 points[4];

	points[0] = box2->position;
	points[1] = box2->position + box2->size;
	points[2] = box2->position + Vector2(box2->size.x, 0.0f);
	points[3] = box2->position + Vector2(0.0f, box2->size.y);

	return AnyPointsWithinBox(box1, points, 4);
}