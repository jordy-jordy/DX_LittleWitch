#pragma once
#include "EngineResources.h"
#include "EngineEnums.h"

#include "ThirdParty/DirectxTex/Inc/DirectXTex.h"

// 설명 :
class UEngineTexture : public UEngineResources
{
	friend class UEngineRenderTarget;

public:
	// constrcuter destructer
	ENGINEAPI UEngineTexture();
	ENGINEAPI ~UEngineTexture();

	// delete Function
	UEngineTexture(const UEngineTexture& _Other) = delete;
	UEngineTexture(UEngineTexture&& _Other) noexcept = delete;
	UEngineTexture& operator=(const UEngineTexture& _Other) = delete;
	UEngineTexture& operator=(UEngineTexture&& _Other) noexcept = delete;

	static std::shared_ptr<UEngineTexture> ThreadSafeLoad(std::string_view _Path)
	{
		UEnginePath EnginePath = UEnginePath(_Path);

		std::string FileName = EnginePath.GetFileName();

		return ThreadSafeLoad(FileName, _Path);
	}
	ENGINEAPI static std::shared_ptr<UEngineTexture> ThreadSafeLoad(std::string_view _Name, std::string_view _Path);

	static std::shared_ptr<UEngineTexture> Load(std::string_view _Path)
	{
		UEnginePath EnginePath = UEnginePath(_Path);

		std::string FileName = EnginePath.GetFileName();

		return Load(FileName, _Path);
	}

	ENGINEAPI static std::shared_ptr<UEngineTexture> Load(std::string_view _Name, std::string_view _Path);

	ID3D11ShaderResourceView* GetSRV()
	{
		return SRV.Get();
	}

	ID3D11DepthStencilView* GetDSV()
	{
		return DSV.Get();
	}

	ID3D11RenderTargetView* GetRTV()
	{
		return RTV.Get();
	}

	FVector GetTextureSize()
	{
		return Size;
	}


	void Setting(EShaderType _Type, UINT _BindIndex);

	void Reset(EShaderType _Type, UINT _BindIndex);

	ENGINEAPI void ResCreate(const D3D11_TEXTURE2D_DESC& _Value);
	ENGINEAPI void ResCreate(Microsoft::WRL::ComPtr<ID3D11Texture2D> _Texture2D);

	ENGINEAPI void CreateRenderTargetView();
	ENGINEAPI void CreateShaderResourceView();
	ENGINEAPI void CreateDepthStencilView();

protected:

private:
	ENGINEAPI void ResLoad();

	FVector Size;
	DirectX::TexMetadata Metadata;
	DirectX::ScratchImage ImageData;
	Microsoft::WRL::ComPtr<ID3D11Texture2D> Texture2D = nullptr; // 로드한 텍스처
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> SRV = nullptr; // 텍스처를 쉐이더 세팅할수 있는권한
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> RTV = nullptr; // 텍스처를 쉐이더 세팅할수 있는권한
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> DSV = nullptr; // 텍스처를 쉐이더 세팅할수 있는권한
	D3D11_TEXTURE2D_DESC Desc;
};
