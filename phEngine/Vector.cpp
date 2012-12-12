#include "stdafx.h"
#include "Vector.h"


Vector2 Vector2::operator=(const Vector2& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;

	return *this;
}

Vector2 Vector2::operator*(const Vector2& rhs)
{
	Vector2 temp(*this);
	temp.x *= rhs.x;
	temp.y *= rhs.y;

	return temp;
}

Vector2 Vector2::operator*(float rhs)
{
	Vector2 temp(*this);
	temp.x *= rhs;
	temp.y *= rhs;

	return temp;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 temp(*this);
	temp.x += rhs.x;
	temp.y += rhs.y;

	return temp;
}

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

Vector3 Vector3::operator*(const Vector3& rhs)
{
	Vector3 temp(*this);

	temp.x *= rhs.x;
	temp.y *= rhs.y;
	temp.z *= rhs.z;

	return temp;
}

Vector3 Vector3::operator*(float rhs)
{
	Vector3 temp(*this);

	temp.x *= rhs;
	temp.y *= rhs;
	temp.z *= rhs;

	return temp;
}

Vector3 Vector3::operator+(const Vector2& rhs)
{
	Vector3 temp(*this);

	temp.x += rhs.x;
	temp.y += rhs.y;

	return temp;
}

Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 temp(*this);

	temp.x += rhs.x;
	temp.y += rhs.y;
	temp.z += rhs.z;

	return temp;
}