#include "stdafx.h"
#include "Utils.h"

float Signum(float num)
{
	return (0.0f < num) - (num < 0.0f);
}