#include "stdafx.h"
#include "json.h"

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