#include "stdafx.h"
#include "Vector.h"


Vector2 Vector2::operator=(const Vector2& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}

bool Vector2::operator==(const Vector2& rhs)
{
	return (x == rhs.x && y == rhs.y);
}

bool Vector2::operator!=(const Vector2& rhs)
{
	return !(*this == rhs);
}

Vector2 Vector2::operator*(const Vector2& rhs) const
{
	Vector2 temp(*this);
	temp.x *= rhs.x;
	temp.y *= rhs.y;

	return temp;
}

Vector2 Vector2::operator*(float rhs) const
{
	Vector2 temp(*this);
	temp.x *= rhs;
	temp.y *= rhs;

	return temp;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	Vector2 temp(*this);
	temp.x += rhs.x;
	temp.y += rhs.y;

	return temp;
}

const Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);


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

bool Vector3::operator==(const Vector3& rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

bool Vector3::operator!=(const Vector3& rhs)
{
	return !(*this == rhs);
}

Vector3 Vector3::operator*(const Vector3& rhs) const
{
	Vector3 temp(*this);

	temp.x *= rhs.x;
	temp.y *= rhs.y;
	temp.z *= rhs.z;

	return temp;
}

Vector3 Vector3::operator*(float rhs) const
{
	Vector3 temp(*this);

	temp.x *= rhs;
	temp.y *= rhs;
	temp.z *= rhs;

	return temp;
}

Vector3 Vector3::operator+(const Vector2& rhs) const
{
	Vector3 temp(*this);

	temp.x += rhs.x;
	temp.y += rhs.y;

	return temp;
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
	Vector3 temp(*this);

	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;

	return temp;
}

const Vector3 Vector3::Zero = Vector3(0.0f, 0.0f, 0.0f);