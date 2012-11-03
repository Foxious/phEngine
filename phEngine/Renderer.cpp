#include "stdafx.h"
#include "Renderer.h"

#include "DXTexture.h"

struct MeshBuffers
{
	IDirect3DVertexBuffer9 * VB;
	IDirect3DIndexBuffer9 * IB;
};

Renderer::Renderer(HWND hWnd)
	: mDx9(0)
	, mDevice(0)
	, mController(0)
{
	Init(hWnd);
}

Renderer::~Renderer()
{
	ReleaseAllVertexDeclarations();
	mDevice->Release();
	mDx9->Release();
}

void Renderer::Init(HWND hWnd)
{
	// what do we do if this fails?
	// atm the burden is on the client,
	// which imo isn't great...

	// pH - I'm starting to do a fair amount of
	// Window management here, maybe I need 
	// to write a class to do window stuff
	// separate from the renderer.
	mhWnd = hWnd;
	GetWindowSize(); 

	memset (&mPresentParams, 0, sizeof(mPresentParams)) ;
	mPresentParams.Windowed = true;
	mPresentParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	mPresentParams.BackBufferWidth = mWidth;
	mPresentParams.BackBufferHeight = mHeight;
	mDx9 = Direct3DCreate9(D3D_SDK_VERSION);
	mDx9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, mhWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &mPresentParams, &mDevice);

	D3DXMATRIX worldTransform;
	D3DXMatrixIdentity(&worldTransform);
	mCamera.SetWorldMatrix(worldTransform);

	D3DXMATRIX projMatrix;
	D3DXMatrixOrthoLH(&projMatrix, 1280.0f, 800.0f, 0.0f, 5000.0f);	
	mCamera.SetProjectionMatrix(projMatrix);

	InitAllVertexDeclarations(mDevice);

	mMeshBuilder.SetRenderer(this);
	mTextureManager.SetRenderer(this);
	
	BuildTris();

	SetupShader();
}

void Renderer::BuildTris()
{
	MeshInstance * testQuad = &(mMeshBuilder.AddNewSprite());
	testQuad->SetTexture(mTextureManager.GetTexture("BigMacSq.tga"));
	mPlayer.SetSprite(testQuad);
}

ITexture* Renderer::CreateTexture(const char* name)
{
	return new DXTexture(mDevice, name);
}

int Renderer::Run()
{
	MSG msg;
	msg.message = WM_NULL;

	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	float secsPerCnt = 1.0f / (float)cntsPerSec;

	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage( &msg, 0, 0, 0, PM_REMOVE ))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			__int64 currTimeStamp = 0;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
			float dt = (currTimeStamp - prevTimeStamp) * secsPerCnt;

			Update(dt);
			DrawScene();

			prevTimeStamp = currTimeStamp;
		}
	}
	return (int)msg.wParam;
}

void Renderer::Update(float dt)
{
	float velocity = 100.0f;
	mController.Poll();
	if (mController.IsConnected())
	{
		mPlayer.MoveX(mController.ThumbLX() * velocity * dt);
		mPlayer.MoveY(mController.ThumbLY() * velocity * dt);
	}

	mMeshBuilder.Update(dt);
}

void Renderer::DrawScene()
{
	mDevice->Clear(0, NULL, D3DCLEAR_TARGET, 0xff000000, 1.0f, 0);
	mDevice->BeginScene();
	mDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	//mMeshBuilder.Draw(mCamera.GetMatrix());

	std::vector<MeshInstance>::iterator it = mRenderQueue.begin();
	std::vector<MeshInstance>::iterator end = mRenderQueue.end();

	for (; it != end ; ++it)
	{
		mFX->SetMatrix(mShaderMVP, &mCamera.GetMatrix());

		unsigned int numPasses = 0;
		mFX->Begin(&numPasses, 0);
		const DXTexture* tex = 0;
		for (unsigned int i = 0; i < numPasses; ++i)
		{
			if (tex != it->texture)
			{
				tex = static_cast<const DXTexture*>(it->texture);
				mFX->SetTexture(mTexture, tex->GetTexture());
			}

			mFX->SetValue(mPos, (void*)&it->mXform.mPos, sizeof(Vector3));
			mFX->SetValue(mScale, (void*)&it->mXform.mScale, sizeof(Vector3));

			XForm uvXform = it->mAnimComponent.GetUVXform();

			mFX->SetValue(mUVPos, (void*)&uvXform.mPos, sizeof(Vector3));
			mFX->SetValue(mUVScale, (void*)&uvXform.mScale, sizeof(Vector3));
			
			mFX->BeginPass(i);
			mDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, it->VertCount(), 0, it->TriCount());
			mFX->EndPass();
		}
	}

	mDevice->EndScene();
	mDevice->Present(NULL, NULL, NULL, NULL);

	mRenderQueue.clear();
}

void Renderer::CreateBuffers(Mesh& mesh)
{
	IDirect3DVertexBuffer9 * VB;
	IDirect3DIndexBuffer9 * IB;

	unsigned int vLen = mesh.verts.size() * sizeof(VertexPNT);
	unsigned short iLen = mesh.indices.size() * sizeof(unsigned short);

	mDevice->CreateVertexBuffer(vLen, D3DUSAGE_WRITEONLY, 0, D3DPOOL_MANAGED, &(VB), 0);
	VertexPNT * v = 0;
	VB->Lock(0, 0, (void**)&v, 0);

	memcpy( v, &mesh.verts[0], vLen );
	VB->Unlock();

	mDevice->CreateIndexBuffer(iLen, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &(IB), 0);
	unsigned short * k = 0;
	IB->Lock(0, 0, (void**)&k, 0);
	memcpy( k, &mesh.indices[0], iLen );
	IB->Unlock();

	mesh.buffers = new MeshBuffers();

	mesh.buffers->VB = VB;
	mesh.buffers->IB = IB;

	// pH - if ever this becomes more than just a sprite engine,
	// change this.
	mDevice->SetStreamSource(0, VB, 0, sizeof(VertexPNT));
	mDevice->SetIndices(IB);
	mDevice->SetVertexDeclaration(VertexPNT::Decl);

}

// PRIVATE ////////////////////////////////////////////////////////////////////
void Renderer::GetWindowSize()
{
	RECT wr;
	GetWindowRect(mhWnd, &wr);
	mWidth = wr.right-wr.left;
	mHeight = wr.bottom-wr.top;
}

void Renderer::SetupShader()
{
	// load the shader
	ID3DXBuffer* errors = 0;
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
	mUVScale = mFX->GetParameterByName(0, "gUVScale");
}