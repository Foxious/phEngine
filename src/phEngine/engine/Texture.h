#ifndef TEXTURE_H
#define TEXTURE_H

#include <unordered_map>
#include <string>
#include "IRenderer.h"

#include <d3dx9.h>

class ITexture
{
public:
	virtual ~ITexture(){};

	virtual unsigned int GetWidth() const=0;
	virtual unsigned int GetHeight() const=0;
	virtual const std::string& GetName() const=0;
};

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void SetRenderer(IRenderer* renderer) { mRenderer = renderer; }

	ITexture* GetTexture(const char* texName);
	ITexture* GetTexture(const std::string& texName);

private:
	TextureManager(TextureManager&);
	TextureManager& operator=(TextureManager&);
	IRenderer* mRenderer;
	typedef std::unordered_map<std::string, ITexture*> TexMap;
	TexMap mStaticTex;
	TexMap mAnimTex;
};



#endif