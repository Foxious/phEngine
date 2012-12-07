#ifndef MESH_H
#define MESH_H

#include <unordered_map>
#include <vector>

#include "Helper.h"
#include "XForm.h"
#include "Vertex.h"
#include "Camera.h"
#include "Texture.h"
#include "AnimationComponent.h"
#include "IRenderer.h"

// pH TODO - figure out how to abstract this away.
#include <d3dx9.h>

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

class MeshBuilder
{
public:
	MeshBuilder();
	~MeshBuilder();

	void SetRenderer (IRenderer* renderer);
	MeshInstance* GetSprite(const std::string& fileName);
	void Update(float dt);

private:
	void MakeSprite();

	// pH TODO - when you make something
	// to manage shaders, move this there.
	void SetupShader();
	MeshInstance* LoadSpriteFromFile(const std::string& fileName);
	void DeserializeSprite (const std::string& spriteData, const std::string& name);

private:
	MeshBuilder(const MeshBuilder &);

	IRenderer* mRenderer;
	Mesh mSpriteDef;

	std::vector<MeshInstance> mInstances;
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