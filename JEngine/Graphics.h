#pragma once
#include "JException.h"
#include "GraphicsMacro.h"
#include "DxgiInfoManager.h"
#include <d3d11.h>
#include <vector>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <memory>
#include <random>


class Graphics
{
	friend class GraphicsResource;
public:
	class GfxException : public JException
	{
		using JException::JException;
	};
	class HRException : public GfxException
	{
	public:
		HRException(int line, const char* file, HRESULT hr, std::vector<std::string> infoMsgs = {}) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorString() const noexcept;
		std::string GetErrorDescription() const noexcept;
		std::string GetErrorInfo() const noexcept;
	private:
		HRESULT hr;
		std::string info;
	};
	class InfoException : public GfxException
	{
	public:
		InfoException(int line, const char* file, std::vector<std::string> infoMsgs) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		std::string GetErrorInfo() const noexcept;
	private:
		std::string info;
	};
	class DeviceRemovedException : public HRException
	{
		using HRException::HRException;
	public:
		const char* GetType() const noexcept override;
	private:
		std::string reason;
	};


public:
	Graphics(HWND hWnd, int W, int H);
	Graphics(const Graphics&) = delete;
	Graphics& operator= (const Graphics&) = delete;
	~Graphics();

	void EndFrame();
	void BeginFrame(float red, float green, float blue) noexcept;
	void SetProjection(DirectX::FXMMATRIX proj) noexcept { projection = proj; };
	DirectX::XMMATRIX GetProjection() const noexcept { return projection; };
	UINT GetWidth() const noexcept { return width; };
	UINT GetHeight() const noexcept { return height; };

private:
	UINT width;
	UINT height;
	DirectX::XMMATRIX projection;

#ifndef NDEBUG
		DxgiInfoManager infoManager;
#endif
	Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwap;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;
};

