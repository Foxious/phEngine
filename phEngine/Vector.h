#ifndef VECTOR_H
#define VECTOR_H

struct Vector2
{
	Vector2() 
	{
		x = 0.0f;
		y=0.0f;
	}
	Vector2(float xx, float yy) 
		: x(0.0f)
		, y(0.0f)
	{
		x = xx;
		y = yy;
	}

	float x, y;
};

struct Vector3
{
	Vector3() 
		: x(0.0f)
		, y(0.0f)
		, z(0.0f)
	{
	}
	Vector3(float xx, float yy, float zz)
		: x(xx)
		, y(yy)
		, z(zz)
	{
	}

	Vector3 operator=(const Vector3& rhs);
	Vector3 operator=(const Vector2& rhs);

	float x,y,z;
};
#endif