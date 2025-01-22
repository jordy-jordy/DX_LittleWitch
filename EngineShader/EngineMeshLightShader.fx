#include "Light.hlsli"
#include "Transform.hlsli"

struct EngineVertex
{
	float4 POSITION : POSITION;
	float4 TEXCOORD : TEXCOORD; // UV���̶�� �Ҹ��� ����� �ؽ�ó�� ���εǴ� ������ �������ݴϴ�.
	float4 COLOR : COLOR;
	float4 NORMAL : NORMAL; // ���� ���� ���Ͱ� �ʿ��ϴ�.
	float4 BINORMAL : BINORMAL; // ���� ������ ���� �����Ͱ� ź��Ʈ ������ ����� ���Ѱ�.
	float4 TANGENT : TANGENT; // ���� ������ ���� �����Ͱ� ź��Ʈ ������ ����� ���Ѱ�.
};

// ���ؽ� ���̴��� ������ ���ϰ��� �־�� �մϴ�.
// ��ǲ�����2�� �ѱ� ���� ����������ϴµ�.
// �̶��� ��Ģ�� �ֽ��ϴ�.

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
	// ���� �Ϲ������� ��������� ����մϴ�.
	// �� �����غ���
	OutPut.NORMAL = mul(_Vertex.POSITION, World * View);
	OutPut.BINORMAL = mul(_Vertex.POSITION, World * View);
	OutPut.TANGENT = mul(_Vertex.POSITION, World * View);
	
	// �� �������� ���⿡�� �ع����� �ѱ�� ��ν��̵��̶�� �Ѵ�.
	// OutPut.LIGHTCOLOR = 
	
	return OutPut;
}

cbuffer MeshColor : register(b0)
{
	float4 SettingColor;
};

float4 MeshLight_PS(VertexShaderOutPut _Vertex) : SV_Target0
{
	// � ���� ������ �༮��
	float4 Color = CalDiffusLight(_Vertex.NORMAL, LightArr[0]);
	return Color;
	// return float4(1.0f, 0.0f, 0.0f, 1.0f);
};

