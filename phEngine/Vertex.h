#ifndef VERTEX_H
#define VERTEX_H

#include <d3dx9.h>

void InitAllVertexDeclarations(IDirect3DDevice9* device);
void ReleaseAllVertexDeclarations();


struct VertexPNT
{
	VertexPNT() : pos(0.0f, 0.0f, 0.0f){}
	VertexPNT(float x, float y, float z, float xn, float yn, float zn, float u, float v)
		: pos(x, y, z)
		, norm(xn, yn, zn)
		, tex(u, v)
	{}

	D3DXVECTOR3 pos;
	D3DXVECTOR3 norm;
	D3DXVECTOR2 tex;

	// this is the only kind of vertex we're making. This can be
	// owned by the DirectX renderer.
	static IDirect3DVertexDeclaration9* Decl;
};

#endif
