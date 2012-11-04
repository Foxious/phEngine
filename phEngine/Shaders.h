#ifndef __SHADERS_H
#define __SHADERS_H

#include <string>

class PixelFragment;
class VertexFragment;

struct Shader
{
	PixelFragment* ps;
	VertexFragment* vs;
};

#endif // __SHADERS_H