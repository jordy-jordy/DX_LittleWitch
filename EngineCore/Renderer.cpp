#include "PreCompile.h"
#include "Renderer.h"

URenderer::URenderer()
{
}

URenderer::~URenderer()
{
	VertexBuffer->Release();

}

void URenderer::SetOrder(int _Order)
{
	int PrevOrder = GetOrder();
	UObject::SetOrder(_Order);
	ULevel* Level = GetActor()->GetWorld();
	// std::shared_ptr<URenderer> Render(this);
	// std::enable_shared_from_this<UObject> ��ӹ��� Ŭ������ �ڱ��ڽ��� this
	// std::shared_ptr�� ������� this�� ����ϰ� ������ ȣ���ϴ� �Լ�.
	// std::shared_ptr<UObject> ObjectPtr = UObject::shared_from_this();
	// dynmaic_cast�� ����ϴ� ����� ���� ���̴�. 
	// dynamic_cast <= �� ������ �����͸� ��ȯ��Ű�� �༮���� std::shared_ptr
	// std::shared_ptr<int> NewInt = std::make_shared<int>();
	// std::shared_ptr<URenderer> RendererPtr = std::dynamic_pointer_cast<URenderer>(ObjectPtr);
	std::shared_ptr<URenderer> RendererPtr = GetThis<URenderer>();
	Level->ChangeRenderGroup(PrevOrder, RendererPtr);
}

ENGINEAPI void URenderer::BeginPlay()
{
	SetOrder(0);

	// �⺻���� ������ ������������ ������ ���� 
	// ��� �⺻ �ڵ���� �� �ĺ� �����Դϴ�.

	InputAssembler1Init();
}

void URenderer::Render(float _DeltaTime)
{
	InputAssembler1Setting();

	// ���ؽ� ���۶�°� �����Ѵ�.
	// UEngineCore::Device.GetContext()->IASetVertexBuffers();

	// �����Ͷ������� �����Ѵ�.
	// UEngineCore::Device.GetContext()->RSSetState();

	// �׸��� ���� �����̰� ���� ���ҽ��� � ������ �ϰ� �ƹ��� �ǹ̵� ����.
	// �̰� �ѹ� ȣ���� ��ο��� 1���̴�.
	// UEngineCore::Device.GetContext()->Draw()


}



void URenderer::InputAssembler1Init()
{
	// ���ؽ� ���۸� �׷���ī�忡�� ����� �޶�� ��û

	// ����� �̹� ram
	// CPU
	std::vector<EngineVertex> Vertexs;
	Vertexs.resize(6);

	Vertexs[0] = EngineVertex{ FVector(-0.5f, 0.5f, -0.5f), {} };
	Vertexs[1] = EngineVertex{ FVector(0.5f, 0.5f, -0.5f), {} };
	Vertexs[2] = EngineVertex{ FVector(-0.5f, -0.5f, -0.5f), {} };
	Vertexs[3] = EngineVertex{ FVector(0.5f, 0.5f, -0.5f), {} };
	Vertexs[4] = EngineVertex{ FVector(0.5f, -0.5f, -0.5f), {} };
	Vertexs[5] = EngineVertex{ FVector(-0.5f, -0.5f, -0.5f), {} };


	D3D11_BUFFER_DESC BufferInfo = {0};

	BufferInfo.ByteWidth = sizeof(EngineVertex) * Vertexs.size();
	// �뵵�� ���ؽ� ����
	BufferInfo.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	// CPU���� �����Ҽ� �־�?
	BufferInfo.CPUAccessFlags = 0;
	// �߿� �޸� ��ġ�� �׷���ī��� �Ұų� cpu�� �Ұž�?
	// �������� �ɼ�

	// D3D11_USAGE_DEFAULT
	// GPU���� �б� �� ���� �׼����� �ʿ��� ���ҽ��Դϴ�.�̴� ���� �Ϲ����� ��� ������ �� �ֽ��ϴ�.
	
    // D3D11_USAGE_IMMUTABLE
	// GPU������ ���� �� �ִ� ���ҽ��Դϴ�.GPU���� �ۼ��� �� ������ CPU���� ���� �׼����� �� �����ϴ�.�� ������ ���ҽ��� ���� �Ŀ� ������ �� �����Ƿ� ���� �� �ʱ�ȭ�ؾ� �մϴ�.

	// D3D11_USAGE_DYNAMIC
	// GPU(�б� ����)�� CPU(���� ����)���� �׼����� �� �ִ� ���ҽ��Դϴ�.���� ���ҽ��� CPU���� �����Ӵ� �� �� �̻� ������Ʈ�Ǵ� ���ҽ��� �����մϴ�.���� ���ҽ��� ������Ʈ�Ϸ��� Map �޼��带 ����մϴ�.
	
	// ��Ʈ���� ä���Ҷ�. 
	// 	D3D11_USAGE_STAGING
	// GPU���� CPU���� ������ ����(����)�� �����ϴ� ���ҽ��Դϴ�.

	BufferInfo.Usage = D3D11_USAGE_DEFAULT;


	// �ʱⰪ
	D3D11_SUBRESOURCE_DATA Data;
	Data.pSysMem = &Vertexs[0];

	// GPU�� xxx ũ���� ���� ������ּ���� ��� �Ʒ��� �Լ��� ����ϴ�.
	if (S_OK != UEngineCore::Device.GetDevice()->CreateBuffer(&BufferInfo, &Data, &VertexBuffer))
	{
		MSGASSERT("���ؽ� ���� ������ �����߽��ϴ�.");
		return;
	}

	// ��ǲ ���̾ƿ� �̶�� ���� ������ �Ѵ�.
	// ���ؽ� ���̴��� �־�� ��ǲ���̾ƿ� �̶�� ���� ����� �ִ�.
}

void URenderer::InputAssembler1Setting()
{
	UINT VertexSize = sizeof(EngineVertex);
	// �� ���ؽ� ���۰� 10��¥���ε� 3��° ���ؽ� ���� ��������.
	UINT Offset = 0;

	// �ѹ��� �������� ���ؽ� ���۸� �����Ҽ� �ִ�.
	// ���ؽ����������� 1���� �迭�� �־��ִµ�.
	// 0�����Ժ��� 1�� ����ϰڴ�.
	// ���ؽ� �ϳ��� ũ��� VertexSize
	// Offset���� ���ؽ��� ����ϰڴ�.
	UEngineCore::Device.GetContext()->IASetVertexBuffers(0, 1, &VertexBuffer, &VertexSize, &Offset);
}
