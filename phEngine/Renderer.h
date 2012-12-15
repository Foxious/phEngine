#ifndef __RENDERER_H
#define __RENDERER_H

#include <D3D9.h>
#include <d3dx9.h>

#include "IRenderer.h"
#include "Vertex.h"
#include "Camera.h"
#include "Mesh.h"
#include "Controller.h"
#include "Actor.h"

struct SceneObject
{
	MeshBuffers* buffers;
	ITexture* tex;
	XForm xf;
	XForm uv;
	unsigned int vc;
	unsigned int tc;
};

class Renderer : public IRenderer
{
public:
	Renderer(HWND hWnd);
	~Renderer();

	virtual void Init(HWND hWnd);

	virtual void Update(float dt);
	virtual void DrawScene();
	virtual void CreateBuffers(Mesh& mesh);
	virtual ITexture* CreateTexture(const char* name); // pH TODO - get rid of this crap
	virtual MeshInstance* GetMesh(const char* name);
	virtual MeshInstance* CopyMesh(const MeshInstance* instance);

	virtual void Render(MeshInstance* mesh);


private:
	void BuildTris();
	void GetWindowSize();

	IDirect3D9 * mDx9;
	IDirect3DDevice9 * mDevice;
	D3DPRESENT_PARAMETERS mPresentParams;

	D3DXMATRIX mProjMatrix;

	Camera mCamera;

	int mWidth;
	int mHeight;
	HWND mhWnd;

	std::vector<SceneObject> mRenderQueue;

	MeshBuilder mMeshBuilder;

	//Actor mPlayer;


	// pH TODO - This should probably not
	// be the responsibility of the renderer,
	// but ATM there's only one
	// shader, so it doesn't seeem SO bad?
	// Should refactor tho.
	void SetupShader();
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