#ifndef __JSON_H
#define __JSON_H

#include <string>

#include <jsmn.h>

std::string SubstringFromToken(const std::string& jsonData, const jsmntok_t& token);
unsigned int UnsignedFromToken(const std::string& jsonData, const jsmntok_t& token);
float FloatFromToken(const std::string& jsonData, const jsmntok_t& token);

#endif