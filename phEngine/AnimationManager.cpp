#include "stdafx.h"
#include "AnimationManager.h"

#include <fstream>

#include "Animation.h"
#include "AnimationComponent.h"
#include "json.h"

AnimationComponent& AnimationManager::LoadFromFile(const std::string& filename)
{
	int length = 0;
	char* buffer = 0;
	std::fstream f;
	f.open(filename.c_str(), std::fstream::in);

	f.seekg(0, std::ios::end);
	length = f.tellg();
	f.seekg(0, std::ios::beg);

	buffer = new char [length];

	f.read(buffer, length);
	f.close();

	std::string fileData(buffer);

	AnimationComponent comp(fileData);

	delete [] buffer;

	return comp;
}