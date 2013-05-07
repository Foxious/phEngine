#include "stdafx.h"
#include "Texture.h"

// TEXTURE MANAGER ////////////////////////////////////////////////////////////

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	// pH todo - make sure this deletes the textures
	mStaticTex.erase(mStaticTex.begin(), mStaticTex.end());
}

ITexture* TextureManager::GetTexture(const char* texName)
{
	TexMap::iterator it = mStaticTex.find(texName);
	if (it != mStaticTex.end())
	{
		return it->second;
	}

	ITexture* newTex = mRenderer->CreateTexture(texName);
	mStaticTex.insert(mStaticTex.begin(), TexMap::value_type(newTex->GetName(), newTex) );
	return newTex;
}

ITexture* TextureManager::GetTexture(const std::string& texName)
{
	return GetTexture(texName.c_str());
}