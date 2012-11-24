#include "stdafx.h"
#include "Mesh.h"
#include <algorithm>
#include "Vector.h"

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

// CTOR ///////////////////////////////////////////////////////////////////////
MeshBuilder::MeshBuilder()
{
}

MeshBuilder::~MeshBuilder()
{
}

MeshInstance & MeshBuilder::AddNewSprite()
{
	mInstances.push_back(MeshInstance(&mSpriteDef));
	return mInstances.back();
}

// PUBLIC /////////////////////////////////////////////////////////////////////
void MeshBuilder::SetRenderer(IRenderer* renderer)
{
	// pH TODO - do I even need this?
	mRenderer = renderer;
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

// PRIVATE ////////////////////////////////////////////////////////////////////
bool MeshSortPredicate(const MeshInstance& m1, const MeshInstance& m2)
{
	return m1.mTexture < m2.mTexture;
}

void MeshBuilder::SortMeshes()
{
	std::sort(mInstances.begin(), mInstances.end(), MeshSortPredicate);
}

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