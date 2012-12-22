#ifndef MESH_H
#define MESH_H

#include <unordered_map>
#include <vector>

#include "AnimationComponent.h"
#include "IRenderer.h"
#include "ObjectPool.h"
#include "Texture.h"
#include "Vertex.h"
#include "XForm.h"

struct MeshBuffers;

struct Mesh
{
	Mesh();
	~Mesh();

	std::vector<VertexPNT> verts;
	std::vector<unsigned short> indices;
	MeshBuffers* buffers;
	inline unsigned short GetNumTris() const { return indices.size() / 3; }
};

// todo - finish out this class
struct MeshInstance
{
	MeshInstance() : mParent(0), mTexture(0), mXform() {}

	void Update(float dt);
	void SetTexture(ITexture* texName);

	size_t VertCount();
	size_t TriCount();
	
	Mesh* mParent;
	ITexture * mTexture;
	XForm mXform;
	AnimationComponent mAnimComponent;
};

typedef ObjectPool<MeshInstance>::PoolItemPtr MeshInstancePtr;

class MeshBuilder
{
public:
	MeshBuilder();
	~MeshBuilder();

	void SetRenderer (IRenderer* renderer);
	MeshInstancePtr GetInstance(const std::string& fileName);
	MeshInstancePtr CopyInstance(MeshInstancePtr instance);
	void RemoveInstance(MeshInstancePtr instance);

	void Update(float dt);

private:
	void MakeSprite();

	// pH TODO - when you make something
	// to manage shaders, move this there.
	void SetupShader();
	ObjectPool<MeshInstance>::PoolItemPtr LoadSpriteFromFile(const std::string& fileName);
	ObjectPool<MeshInstance>::PoolItemPtr DeserializeSprite (const std::string& spriteData, const std::string& name);

private:
	MeshBuilder(const MeshBuilder &);

	IRenderer* mRenderer;
	Mesh mSpriteDef;
	TextureManager mTextureManager;

	//std::vector<MeshInstance*> mInstances;
	ObjectPool<MeshInstance> mInstances;

	std::unordered_map<std::string, MeshInstance> mDefinitions;

	// pH TODO - This should probably not
	// be the responsibility of the mesh
	// builder, but ATM there's only one
	// shader, so it doesn't seeem SO bad?
	// Should refactor tho.
	ID3DXEffect* mFX;
	D3DXHANDLE mShaderMVP;
	D3DXHANDLE mTechnique;
	D3DXHANDLE mTexture;
	D3DXHANDLE mPos;
	D3DXHANDLE mScale;
	D3DXHANDLE mUVPos;
	D3DXHANDLE mUVScale;

};


#endif