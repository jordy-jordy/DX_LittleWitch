#include "Transform.hlsli"

struct EngineVertex
{
	float4 POSITION : POSITION;
};

// ���ؽ� ���̴��� ������ ���ϰ��� �־�� �մϴ�.
// ��ǲ�����2�� �ѱ� ���� ����������ϴµ�.
// �̶��� ��Ģ�� �ֽ��ϴ�.

struct VertexShaderOutPut
{
	float4 SVPOSITION : SV_POSITION; // ����Ʈ����� �������� �������Դϴ�.
};

VertexShaderOutPut Debug_VS(EngineVertex _Vertex)
{
	VertexShaderOutPut OutPut;
	OutPut.SVPOSITION = mul(_Vertex.POSITION, WVP);
	return OutPut;
}


// ex) �ȼ����̴������� 0�� �� ���� �ִ�.
cbuffer OutColor : register(b0)
{
	float4 Color;
};

// �̹����� ���ø��ؼ� �̹����� ���̰� �����
float4 PixelToWorld_PS(VertexShaderOutPut _Vertex) : SV_Target0
{
	return Color;
};
