#include "stdafx.h"
#include "Mesh.h"

#include <algorithm>
#include <fstream>

#include "Vector.h"
#include "json.h"

const char* spriteKeys[2] = {"Texture", "Animations"};
enum SpriteKeysEnum
{
	texture,
	anims,
	
	NUM_KEYS
};

void CloneMesh(const MeshInstance* source, MeshInstance* destination)
{
	destination->mParent = source->mParent;
	destination->mAnimComponent = source->mAnimComponent;
	destination->mTexture = source->mTexture;
}

Mesh::Mesh()
{
	buffers = 0;
}

Mesh::~Mesh()
{
	if (buffers)
	{
		delete buffers; // maybe the renderer should hold these?
		buffers = 0;
	}
}


size_t MeshInstance::VertCount()
{
	return mParent->verts.size();
}

size_t MeshInstance::TriCount()
{
	return mParent->GetNumTris();
}

void MeshInstance::Update(float dt)
{
	mAnimComponent.Update(dt);
}

void MeshInstance::SetTexture(ITexture* texture)
{
	this->mTexture = texture;
	Vector3 textureSizeVec((float)texture->GetWidth(), (float)texture->GetHeight(), 1.0f);
	this->mXform.scale = mAnimComponent.GetXForm().scale * textureSizeVec;
}

// CTOR /////////////////////////////////////////////////////////////////////////////////
MeshBuilder::MeshBuilder()
{
}

MeshBuilder::~MeshBuilder()
{
}


// PUBLIC ///////////////////////////////////////////////////////////////////////////////
void MeshBuilder::SetRenderer(IRenderer* renderer)
{
	// pH TODO - do I even need this?
	mRenderer = renderer;
	mTextureManager.SetRenderer(renderer);
	MakeSprite();
}

void MeshBuilder::Update(float dt)
{
	std::vector<MeshInstance>::iterator it = mInstances.begin();
	std::vector<MeshInstance>::iterator end = mInstances.end();

	for (; it != end; ++it)
	{
		it->Update(dt);
		mRenderer->Render(&(*it));
	}
}

MeshInstance* MeshBuilder::GetSprite(const std::string& fileName)
{
	std::unordered_map<std::string, MeshInstance>::iterator it = mDefinitions.find(fileName);
	if (it != mDefinitions.end())
	{
		mInstances.push_back(MeshInstance());
		CloneMesh( &it->second, &mInstances.back() );
	}

	return LoadSpriteFromFile(fileName);
}

void MeshBuilder::DeserializeSprite(const std::string& spriteData, const std::string& name)
{
	MeshInstance newSprite;
	newSprite.mParent = &mSpriteDef;
	jsmn_parser parser;
	jsmn_init(&parser);

	jsmntok_t tokens[256];
	jsmnerr_t r = jsmn_parse(&parser, spriteData.c_str(), tokens, 256);

	char str[255];

	int i = 1;
	std::string keyStr;
	jsmntok_t *keyTok;
	int count=0;
	while(tokens[count].type >= 0) ++count;
	while(i < count)
	{
		keyTok = &tokens[i];
		keyStr = SubstringFromToken(spriteData, *keyTok);

		if (keyStr.compare(spriteKeys[texture])==0)
		{
			ITexture* newTex = mTextureManager.GetTexture( SubstringFromToken(spriteData, tokens[++i]) );
			newSprite.SetTexture(newTex);
		}
		else if (keyStr.compare(spriteKeys[anims]) == 0)
		{
			newSprite.mAnimComponent.LoadFromJSON( SubstringFromToken(spriteData, tokens[++i]) );
		}
		++i;
	} // end while
	mDefinitions.insert(mDefinitions.begin(), std::unordered_map<std::string, MeshInstance>::value_type(name, newSprite) );
	mInstances.push_back(newSprite);
	CloneMesh( &mDefinitions[name], &mInstances.back() );
}

// PRIVATE //////////////////////////////////////////////////////////////////////////////

void MeshBuilder::MakeSprite()
{
	mSpriteDef.verts.reserve(4);
	mSpriteDef.indices.reserve(6);

	// remember, the V follows screen space. 0.0V is at the top of the texture.
	mSpriteDef.verts.push_back( VertexPNT(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f) );		// bot left
	mSpriteDef.verts.push_back( VertexPNT(-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f) );		// top left
	mSpriteDef.verts.push_back( VertexPNT(0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f) );		// bot right
	mSpriteDef.verts.push_back( VertexPNT(0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f) );		// top right

	mSpriteDef.indices.push_back(0);
	mSpriteDef.indices.push_back(1);
	mSpriteDef.indices.push_back(2);

	mSpriteDef.indices.push_back(2);
	mSpriteDef.indices.push_back(1);
	mSpriteDef.indices.push_back(3);

	mRenderer->CreateBuffers(mSpriteDef);
}

MeshInstance* MeshBuilder::LoadSpriteFromFile(const std::string& fileName)
{
	// pH TODO - make dumping a file into a string its own function - you do it a lot.
	int length = 0;
	char* buffer = 0;
	std::fstream f;
	f.open(fileName.c_str(), std::fstream::in);

	f.seekg(0, std::ios::end);
	length = f.tellg();
	f.seekg(0, std::ios::beg);

	buffer = new char [length];

	f.read(buffer, length);
	f.close();

	std::string fileData(buffer);

	DeserializeSprite(fileData, fileName);

	delete [] buffer;

	return &mInstances.back();
}
