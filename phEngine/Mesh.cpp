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

void MeshInstance::SetTexture(const ITexture* texture)
{
	this->texture = texture;
	this->mAnimComponent.SetTexture(texture);

	this->mXform.mScale = mAnimComponent.GetCellSize();
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
	// pH - for now, I'm just going to hard code this
	// thing to circle
	//MeshInstance& sprite = mInstances[0];

	//static float tt =0;
	//tt += dt;

	//float dc = 100.0f;
	//float rate = 0.25f;

	//sprite.mPos.x = cosf(tt*rate)*dc;
	//sprite.mPos.y = sinf(tt*rate)*dc*0;

	std::vector<MeshInstance>::iterator it = mInstances.begin();
	std::vector<MeshInstance>::iterator end = mInstances.end();

	for (; it != end; ++it)
	{
		it->Update(dt);
		mRenderer->Render(&(*it));
	}

}

void MeshBuilder::Draw(D3DXMATRIX& WVP)
{
	// pH TODO - Refactor - ownership of setting material params
	// should go to a material class, and the Renderer should
	// do the actual rendering.
	//std::vector<MeshInstance>::iterator it = mInstances.begin();
	//std::vector<MeshInstance>::iterator end = mInstances.end();

	//for (; it != end; ++it)
	//{
	//	mFX->SetMatrix(mShaderMVP, &WVP);

	//	unsigned int numPasses = 0;
	//	mFX->Begin(&numPasses, 0);
	//	ITexture* tex = 0;
	//	for (unsigned int i = 0; i < numPasses; ++i)
	//	{
	//		if (tex != it->texture)
	//		{
	//			mFX->SetTexture(mTexture, it->texture->GetTexture());
	//		}

	//		mFX->SetValue(mPos, (void*)&it->mXform.mPos, sizeof(Vector3));
	//		mFX->SetValue(mScale, (void*)&it->mXform.mScale, sizeof(Vector3));

	//		XForm uvXform = it->mAnimComponent.GetUVXform();

	//		mFX->SetValue(mUVPos, (void*)&uvXform.mPos, sizeof(Vector3));
	//		mFX->SetValue(mUVScale, (void*)&uvXform.mScale, sizeof(Vector3));
	//		
	//		mFX->BeginPass(i);
	//		mDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, it->VertCount(), 0, it->TriCount());
	//		mFX->EndPass();
	//	}

	//	mFX->End();

	//}
}

// PRIVATE ////////////////////////////////////////////////////////////////////
bool MeshSortPredicate(const MeshInstance& m1, const MeshInstance& m2)
{
	return m1.texture < m2.texture;
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

void MeshBuilder::SetupShader()
{
	// load the shader
	/*ID3DXBuffer* errors = 0;
	D3DXCreateEffectFromFileA(mDevice, "Default.fx", 0, 0, D3DXSHADER_DEBUG, 0, &mFX, &errors);
	if (errors)
	{
		MessageBoxA(0, (LPCSTR)errors->GetBufferPointer(), "Shader load error!", 0);
		return;
	}

	mShaderMVP = mFX->GetParameterByName(0, "gWVP");
	mTexture = mFX->GetParameterByName(0, "gTex");
	mPos = mFX->GetParameterByName(0, "gPos");
	mScale = mFX->GetParameterByName(0, "gScale");

	mUVPos = mFX->GetParameterByName(0, "gUVPos");
	mUVScale = mFX->GetParameterByName(0, "gUVScale");*/
}