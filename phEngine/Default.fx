uniform extern float4x4 gWVP;
uniform extern texture gTex;
uniform extern float3 gPos;
uniform extern float3 gScale;

uniform extern float3 gUVPos;
uniform extern float3 gUVScale;

sampler TexS = sampler_state
{
	Texture = <gTex>;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
	mipfilter = NONE;
};

struct OutputVS
{
	float4 posH : POSITION0;
	float2 tex0 : TEXCOORD0;
};

OutputVS TransformVS(float3 posL : POSITION0,
					 float3 normal : NORMAL0,
					 float2 tex0 : TEXCOORD0)
{
	// Zero output
	OutputVS outVS = (OutputVS)0;
	outVS.posH = mul(float4(posL * gScale + gPos, 1.0f), gWVP);

	outVS.tex0 = tex0 * gUVScale + gUVPos;

	return outVS;
}

float4 TransformPS(float2 tex0 : TEXCOORD0) : COLOR0
{
	return tex2D(TexS, tex0);
}

technique DefaultTech
{
	pass P0
	{
		AlphaBlendEnable = True;
		SrcBlend = SrcAlpha;
		DestBlend = InvSrcAlpha;

		vertexShader = compile vs_2_0 TransformVS();
		pixelShader	 = compile ps_2_0 TransformPS();
		FillMode = Solid;
		CullMode = ccw;
	}
}