#ifndef CAMERA_H
#define CAMERA_H

#include <d3dx9.h>

class Camera
{
public:
	Camera();
	Camera(D3DXMATRIX world, D3DXMATRIX projection);

	inline void SetWorldMatrix(D3DXMATRIX world) { mWorldMatrix = world; }
	inline void SetProjectionMatrix(D3DXMATRIX projection) { mProjMatrix = projection; }

	D3DXMATRIX& GetMatrix();
	void SetPos(float x, float y, float z);
	void SetLookAt(float x, float y, float z);

private:
	void CalcMatrix();

private:
	D3DXVECTOR3 mPos;
	D3DXVECTOR3 mLookAt;

	bool mDirty;

	D3DXMATRIX mWorldMatrix;
	D3DXMATRIX mCamMatrix;
	D3DXMATRIX mProjMatrix;
	D3DXMATRIX mCombinedMatrix;
};

#endif