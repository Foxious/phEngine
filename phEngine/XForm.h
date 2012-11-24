#ifndef XFORM_H
#define XFORM_H

#include "Vector.h"

class XForm
{
public:
	XForm() :scale(1.0f, 1.0f, 1.0f), position(0.0f, 0.0f, 0.0f)
	{}

	Vector3 scale;
	Vector3 position;
	// no rotation yet, not needed ATM
};

#endif