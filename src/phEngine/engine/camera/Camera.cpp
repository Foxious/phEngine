#include "stdafx.h"

#include "Camera.h"

Camera::Camera()
	: mPos(0.0f, 0.0f, -10.0f)
	, mLookAt(0.0f, 0.0f, 0.0f)
	, mDirty(true)
{
}

Camera::Camera(D3DXMATRIX world, D3DXMATRIX projection)
	: mPos(0.0f, 0.0f, -10.0f)
	, mLookAt(0.0f, 0.0f, 0.0f)
	, mDirty(true)
	, mWorldMatrix(world)
	, mProjMatrix(projection)
{
}

D3DXMATRIX& Camera::GetMatrix()
{
	if (mDirty)
		CalcMatrix();

	return mCombinedMatrix;
}

void Camera::SetPos(float x, float y, float z)
{
	mPos.x = x;
	mPos.y = y;
	mPos.z = z;

	mDirty = true;
}

void Camera::SetLookAt(float x, float y, float z)
{
	mLookAt.x = x;
	mLookAt.y = y;
	mLookAt.z = z;

	mDirty = true;
}

void Camera::CalcMatrix()
{
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&mCamMatrix, &mPos, &mLookAt, &up);
	mCombinedMatrix = (mWorldMatrix * mCamMatrix * mProjMatrix);
	mDirty = false;
}