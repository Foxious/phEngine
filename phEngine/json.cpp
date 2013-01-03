#include "stdafx.h"
#include "json.h"

#include <fstream>

std::string SubstringFromToken(const std::string& jsonData, const jsmntok_t& token)
{
	return jsonData.substr(token.start, token.end - token.start);
}

unsigned int UnsignedFromToken(const std::string& jsonData, const jsmntok_t& token)
{
	return strtoul(SubstringFromToken(jsonData, token).c_str(), NULL, 0);
}

float FloatFromToken(const std::string& jsonData, const jsmntok_t& token)
{
	return atof(SubstringFromToken(jsonData, token).c_str());
}

std::string JsonStringFromFile(const char* file)
{
	int length = 0;
	char* buffer = 0;
	std::fstream f;
	f.open(file, std::fstream::in);

	f.seekg(0, std::ios::end);
	length = f.tellg();
	f.seekg(0, std::ios::beg);

	buffer = new char [length];

	f.read(buffer, length);
	f.close();

	std::string fileData(buffer);
	delete [] buffer;

	return fileData;
}