#ifndef IRENDERER_H
#define IRENDERER_H

#include "TypesFwdDecl.h"

class IRenderer
{
public:
	virtual void Update(float dt)=0;

	virtual void DrawScene()=0;
	virtual void CreateBuffers(Mesh& mesh)=0;
	virtual ITexture* CreateTexture(const char* name)=0;
	virtual MeshInstance* GetMesh(const char* name)=0;
	virtual MeshInstance* CopyMesh(const MeshInstance* instance)=0;
	
	virtual void Render(MeshInstance* mesh)=0;
};

#endif