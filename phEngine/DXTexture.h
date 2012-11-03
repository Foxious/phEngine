#ifndef DXTEXTURE_H
#define DXTEXTURE_H


#include "Texture.h"

class DXTexture : public ITexture
{
public:
	DXTexture(IDirect3DDevice9* device, const char* name)
	{
		D3DXCreateTextureFromFileA(device, name, &mTex);
		mName = name;

		mTex->GetLevelDesc(0, &mDesc);
	}

	~DXTexture()
	{
		mTex->Release();
		mTex = 0;
	}

	virtual unsigned int GetCellWidth() const
	{
		return 32;
	}

	virtual unsigned int GetCellHeight() const
	{
		return 32;
	}

	virtual unsigned int GetWidth() const
	{
		return mDesc.Width;
	}

	virtual unsigned int GetHeight() const
	{
		return mDesc.Height;
	}

	virtual const std::string& GetName() const
	{
		return mName;
	}

	IDirect3DTexture9* GetTexture() const
	{
		return mTex;
	}

private:
	std::string mName;
	IDirect3DTexture9 * mTex;
	D3DSURFACE_DESC mDesc;
	unsigned int mCellW;
	unsigned int mCellH;
};

#endif