#include "stdafx.h"
#include "Vector.h"

Vector3 Vector3::operator=(const Vector3& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;

	return *this;
}

Vector3 Vector3::operator=(const Vector2& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = 0.0f;

	return *this;
}