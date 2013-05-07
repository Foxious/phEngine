#include "stdafx.h"
#include "Vertex.h"
#include "Helper.h"

IDirect3DVertexDeclaration9* VertexPNT::Decl = 0;

void InitAllVertexDeclarations(IDirect3DDevice9* device)
{
	D3DVERTEXELEMENT9 VertexPNTElements [] =
	{
		{0, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0},
		{0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0},
		{0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0},
		D3DDECL_END()
	};
	
	device->CreateVertexDeclaration(VertexPNTElements, &VertexPNT::Decl);

	assert(VertexPNT::Decl);
}

void ReleaseAllVertexDeclarations()
{
	RELEASE(VertexPNT::Decl);
}