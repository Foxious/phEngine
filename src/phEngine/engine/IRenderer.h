#ifndef IRENDERER_H
#define IRENDERER_H

#include "TypesFwdDecl.h"
#include "ObjectPool.h"
#include "Vector.h"

class IRenderer
{
public:
	virtual void Update(float dt)=0;

	virtual void DrawScene()=0;
	virtual void CreateBuffers(Mesh& mesh)=0;
	virtual ITexture* CreateTexture(const char* name)=0;
	virtual ObjectPool<MeshInstance>::PoolItemPtr GetMesh(const char* name)=0;
	virtual ObjectPool<MeshInstance>::PoolItemPtr CopyMesh(const ObjectPool<MeshInstance>::PoolItemPtr instance)=0;
	virtual void RemoveMeshInstance(ObjectPool<MeshInstance>::PoolItemPtr)=0;

	virtual void Render(MeshInstance* mesh)=0;
};

#endif