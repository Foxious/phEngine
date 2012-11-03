#ifndef IRENDERER_H
#define IRENDERER_H

#include "TypesFwdDecl.h"

class IRenderer
{
public:
	virtual int Run()=0;

	virtual void Update(float dt)=0;
	virtual void DrawScene()=0;
	virtual void CreateBuffers(Mesh& mesh)=0;
	virtual ITexture* CreateTexture(const char* name)=0;
	
	virtual void Render(MeshInstance* mesh)=0;

	// services
	virtual TextureManager& GetTextureManager()=0;
	virtual MeshBuilder& GetMeshBuilder()=0;
	virtual AnimationManager& GetAnimationManager()=0;
};

#endif