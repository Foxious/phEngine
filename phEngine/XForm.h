#ifndef XFORM_H
#define XFORM_H

#include "Vector.h"

class XForm
{
public:
	XForm() :mScale(1.0f, 1.0f, 1.0f), mPos(0.0f, 0.0f, 0.0f)
	{}

	Vector3 mScale;
	Vector3 mPos;
	// no rotation yet, not needed ATM
};

#endif