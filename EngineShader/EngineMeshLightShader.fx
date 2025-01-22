#include "Light.hlsli"
#include "Transform.hlsli"

struct EngineVertex
{
	float4 POSITION : POSITION;
	float4 TEXCOORD : TEXCOORD; // UV값이라고 불리는 존재로 텍스처가 매핑되는 비율을 지정해줍니다.
	float4 COLOR : COLOR;
	float4 NORMAL : NORMAL; // 면의 법선 백터가 필요하다.
	float4 BINORMAL : BINORMAL; // 범프 매핑을 위한 데이터가 탄젠트 공간을 만들기 위한것.
	float4 TANGENT : TANGENT; // 범프 매핑을 위한 데이터가 탄젠트 공간을 만들기 위한것.
};

// 버텍스 쉐이더는 무조건 리턴값이 있어야 합니다.
// 인풋어셈블러2로 넘길 값을 리턴해줘야하는데.
// 이때도 규칙이 있습니다.

struct VertexShaderOutPut
{
	float4 SVPOSITION : SV_POSITION; 
	float4 TEXCOORD : TEXCOORD; 
	float4 COLOR : COLOR;
	float4 NORMAL : NORMAL; 
	float4 BINORMAL : BINORMAL; 
	float4 TANGENT : TANGENT; 
	
	float4 LIGHTCOLOR : LIGHTCOLOR;
};




VertexShaderOutPut MeshLight_VS(EngineVertex _Vertex /*, int _DataIndex*/)
{
	VertexShaderOutPut OutPut;
	
	OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	OutPut.TEXCOORD = _Vertex.TEXCOORD;
	OutPut.COLOR = _Vertex.COLOR;
	// 빛은 일반적으로 뷰공간에서 계산합니다.
	// 잘 생각해봐라
	OutPut.NORMAL = mul(_Vertex.POSITION, World * View);
	OutPut.BINORMAL = mul(_Vertex.POSITION, World * View);
	OutPut.TANGENT = mul(_Vertex.POSITION, World * View);
	
	// 빛 계산공식을 여기에서 해버리고 넘기면 고로쉐이딩이라고 한다.
	// OutPut.LIGHTCOLOR = 
	
	return OutPut;
}

cbuffer MeshColor : register(b0)
{
	float4 SettingColor;
};

float4 MeshLight_PS(VertexShaderOutPut _Vertex) : SV_Target0
{
	// 어떤 값을 연산한 녀석이
	float4 Color = CalDiffusLight(_Vertex.NORMAL, LightArr[0]);
	return Color;
	// return float4(1.0f, 0.0f, 0.0f, 1.0f);
};

