/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"
#include "eqlib/BuildType.h"

#if HAS_DIRECTX_11

#include "GraphicsEngine.h"
#include "ImGuiBackend.h"
#include "MQRenderDoc.h"
#include "Logging.h"

#include <d3d11.h>
#include <d3dcompiler.h>
#ifdef _MSC_VER
#pragma comment(lib, "d3dcompiler") // Automatically link with d3dcompiler.lib as we are using D3DCompile() below.
#endif

#include <wil/com.h>

namespace mq {

IDXGISwapChain* gpDXGISwapChain = nullptr;
ID3D11Device* gpD3D11Device = nullptr;

struct ScopedStateBlock
{
	uint32_t                    ScissorRectsCount, ViewportsCount;
	D3D11_RECT                  ScissorRects[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
	D3D11_VIEWPORT              Viewports[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
	ID3D11RasterizerState*      RS;
	ID3D11BlendState*           BlendState;
	float                       BlendFactor[4];
	uint32_t                    SampleMask;
	uint32_t                    StencilRef;
	ID3D11DepthStencilState*    DepthStencilState;
	ID3D11ShaderResourceView*   PSShaderResource;
	ID3D11SamplerState*         PSSampler;
	ID3D11PixelShader*          PS;
	ID3D11VertexShader*         VS;
	ID3D11GeometryShader*       GS;
	uint32_t                    PSInstancesCount, VSInstancesCount, GSInstancesCount;
	ID3D11ClassInstance         *PSInstances[256], *VSInstances[256], *GSInstances[256];   // 256 is max according to PSSetShader documentation
	D3D11_PRIMITIVE_TOPOLOGY    PrimitiveTopology;
	ID3D11Buffer*               IndexBuffer, *VertexBuffer, *VSConstantBuffer;
	uint32_t                    IndexBufferOffset, VertexBufferStride, VertexBufferOffset;
	DXGI_FORMAT                 IndexBufferFormat;
	ID3D11InputLayout*          InputLayout;

	ID3D11RenderTargetView*     RTV;
	ID3D11DepthStencilView*     DSV;

	ID3D11DeviceContext* ctx;

	ScopedStateBlock(ID3D11DeviceContext* ctx)
		: ctx(ctx)
	{
		Capture();
	}

	ScopedStateBlock::~ScopedStateBlock()
	{
		Release();
	}

	void Capture()
	{
		ScissorRectsCount = ViewportsCount = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
		ctx->RSGetScissorRects(&ScissorRectsCount, ScissorRects);
		ctx->RSGetViewports(&ViewportsCount, Viewports);
		ctx->RSGetState(&RS);
		ctx->OMGetBlendState(&BlendState, BlendFactor, &SampleMask);
		ctx->OMGetDepthStencilState(&DepthStencilState, &StencilRef);
		ctx->PSGetShaderResources(0, 1, &PSShaderResource);
		ctx->PSGetSamplers(0, 1, &PSSampler);
		PSInstancesCount = VSInstancesCount = GSInstancesCount = 256;
		ctx->PSGetShader(&PS, PSInstances, &PSInstancesCount);
		ctx->VSGetShader(&VS, VSInstances, &VSInstancesCount);
		ctx->VSGetConstantBuffers(0, 1, &VSConstantBuffer);
		ctx->GSGetShader(&GS, GSInstances, &GSInstancesCount);

		ctx->IAGetPrimitiveTopology(&PrimitiveTopology);
		ctx->IAGetIndexBuffer(&IndexBuffer, &IndexBufferFormat, &IndexBufferOffset);
		ctx->IAGetVertexBuffers(0, 1, &VertexBuffer, &VertexBufferStride, &VertexBufferOffset);
		ctx->IAGetInputLayout(&InputLayout);

		ctx->OMGetRenderTargets(1, &RTV, &DSV);
	}

	void Release()
	{
		// Restore modified DX state
		ctx->OMSetRenderTargets(1, &RTV, DSV); if (RTV) RTV->Release(); if (DSV) DSV->Release();
		ctx->RSSetScissorRects(ScissorRectsCount, ScissorRects);
		ctx->RSSetViewports(ViewportsCount, Viewports);
		ctx->RSSetState(RS); if (RS) RS->Release();
		ctx->OMSetBlendState(BlendState, BlendFactor, SampleMask); if (BlendState) BlendState->Release();
		ctx->OMSetDepthStencilState(DepthStencilState, StencilRef); if (DepthStencilState) DepthStencilState->Release();
		ctx->PSSetShaderResources(0, 1, &PSShaderResource); if (PSShaderResource) PSShaderResource->Release();
		ctx->PSSetSamplers(0, 1, &PSSampler); if (PSSampler) PSSampler->Release();
		ctx->PSSetShader(PS, PSInstances, PSInstancesCount); if (PS) PS->Release();
		for (uint32_t i = 0; i < PSInstancesCount; i++) if (PSInstances[i]) PSInstances[i]->Release();
		ctx->VSSetShader(VS, VSInstances, VSInstancesCount); if (VS) VS->Release();
		ctx->VSSetConstantBuffers(0, 1, &VSConstantBuffer); if (VSConstantBuffer) VSConstantBuffer->Release();
		ctx->GSSetShader(GS, GSInstances, GSInstancesCount); if (GS) GS->Release();
		for (uint32_t i = 0; i < VSInstancesCount; i++) if (VSInstances[i]) VSInstances[i]->Release();
		ctx->IASetPrimitiveTopology(PrimitiveTopology);
		ctx->IASetIndexBuffer(IndexBuffer, IndexBufferFormat, IndexBufferOffset); if (IndexBuffer) IndexBuffer->Release();
		ctx->IASetVertexBuffers(0, 1, &VertexBuffer, &VertexBufferStride, &VertexBufferOffset); if (VertexBuffer) VertexBuffer->Release();
		ctx->IASetInputLayout(InputLayout); if (InputLayout) InputLayout->Release();
	}
};

struct DXGISwapChainHook;

class MQGraphicsEngineDX11 : public MQGraphicsEngine
{
public:
	MQGraphicsEngineDX11();
	~MQGraphicsEngineDX11();

	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual OverlayHookStatus InitializeOverlayHooks() override;
	virtual void ImGuiRenderDebug_UpdateImGui() override;

	virtual void ImGui_DrawFrame() override;
	virtual void ImGui_RenderDrawData() override;

	virtual void InitializeImGui_Internal() override;
	virtual void ShutdownImGui_Internal() override;
	virtual void InvalidateDeviceObjects_Internal() override;
	virtual void CreateDeviceObjects_Internal() override;
	virtual void UpdateScene_Internal() override;
	virtual void PostEndScene_Internal() override;
	virtual void OnUpdateFrame_Internal() override;

	virtual bool IsFullScreen() const override;

	bool InstallHooks();

	void AcquireDevice(IDXGISwapChain* SwapChain);
	void OnDeviceLost(IDXGISwapChain* SwapChain);
	HRESULT OnPresent(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags);
	HRESULT OnSetFullscreenState(IDXGISwapChain* SwapChain, BOOL Fullscreen, IDXGIOutput* Target);
	HRESULT OnResizeBuffers(IDXGISwapChain* SwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

	wil::com_ptr<IDXGISwapChain> m_swapChain;
	wil::com_ptr<ID3D11Device> m_device;
	wil::com_ptr<ID3D11DeviceContext> m_deviceContext;

	bool m_deviceAcquired = false;
	bool m_lastFullScreenState = false;
};

static MQGraphicsEngineDX11* s_gfxEngine = nullptr;

//============================================================================

struct DXGISwapChainHook
{
	IDXGISwapChain* GetThisSwapChain() { return reinterpret_cast<IDXGISwapChain*>(this); }

	DETOUR_TRAMPOLINE_DEF(ULONG WINAPI, Release_Trampoline, ());
	ULONG WINAPI Release_Detour()
	{
		return Release_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(HRESULT WINAPI, Present_Trampoline, (UINT, UINT));
	HRESULT WINAPI Present_Detour(UINT SyncInterval, UINT Flags)
	{
		return s_gfxEngine->OnPresent(GetThisSwapChain(), SyncInterval, Flags);
	}

	static HRESULT Present(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
	{
		return reinterpret_cast<DXGISwapChainHook*>(pSwapChain)->Present_Trampoline(SyncInterval, Flags);
	}

	DETOUR_TRAMPOLINE_DEF(HRESULT WINAPI, SetFullscreenState_Trampoline, (BOOL, IDXGIOutput*));
	HRESULT WINAPI SetFullscreenState_Detour(BOOL Fullscreen, IDXGIOutput* target)
	{
		return s_gfxEngine->OnSetFullscreenState(GetThisSwapChain(), Fullscreen, target);
	}

	static HRESULT SetFullscreenState(IDXGISwapChain* pSwapChain, BOOL Fullscreen, IDXGIOutput* target)
	{
		return reinterpret_cast<DXGISwapChainHook*>(pSwapChain)->SetFullscreenState_Trampoline(Fullscreen, target);
	}

	DETOUR_TRAMPOLINE_DEF(HRESULT WINAPI, ResizeBuffers_Trampoline, (UINT, UINT, UINT, DXGI_FORMAT, UINT));
	HRESULT WINAPI ResizeBuffers_Detour(UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
	{
		return s_gfxEngine->OnResizeBuffers(GetThisSwapChain(), BufferCount, Width, Height, NewFormat, SwapChainFlags);
	}

	static inline HRESULT ResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
	{
		return reinterpret_cast<DXGISwapChainHook*>(pSwapChain)->ResizeBuffers_Trampoline(BufferCount, Width, Height, NewFormat, SwapChainFlags);
	}
};

constexpr const wchar_t WndClassName[] = L"MQDX11WindowClass";

static wil::unique_hwnd CreateTempWindow()
{
	WNDCLASSEXW wndClass;
	wndClass.cbSize = sizeof(wndClass);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = DefWindowProcW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = nullptr;
	wndClass.hIcon = nullptr;
	wndClass.hCursor = nullptr;
	wndClass.hbrBackground = nullptr;
	wndClass.lpszMenuName = nullptr;
	wndClass.lpszClassName = WndClassName;
	wndClass.hIconSm = nullptr;

	ATOM registerResult = RegisterClassExW(&wndClass);
	if (registerResult == 0)
	{
		LOG_ERROR("CreateTempWindow: Failed to register window class: {}", GetLastError());
		return nullptr;
	}

	HWND result = CreateWindowExW(
		WS_EX_TOOLWINDOW, WndClassName, L"", WS_POPUP, 100, 100, 100, 100, nullptr, nullptr, nullptr, nullptr);

	if (!result)
	{
		LOG_ERROR("CreateTempWindow: Failed to create window: {}", GetLastError());
		return nullptr;
	}

	return wil::unique_hwnd{ result };
}

bool MQGraphicsEngineDX11::InstallHooks()
{
	HMODULE d3d11 = GetModuleHandle("d3d11.dll");
	if (!d3d11)
	{
		return false;
	}

	HMODULE dxgi = GetModuleHandle("dxgi.dll");
	if (!dxgi)
	{
		return false;
	}

	using fptrCreateDXGIFactory = HRESULT(WINAPI*)(const IID& riid, void** ppFactory);
	fptrCreateDXGIFactory createDXGIFactory = (fptrCreateDXGIFactory)GetProcAddress(dxgi, "CreateDXGIFactory");

	PFN_D3D11_CREATE_DEVICE d3d11CreateDevice = (PFN_D3D11_CREATE_DEVICE)GetProcAddress(d3d11, "D3D11CreateDevice");
	UINT flags = 0;
	wil::com_ptr_nothrow<ID3D11Device> device;
	D3D_FEATURE_LEVEL featureLevel;
	wil::com_ptr_nothrow<ID3D11DeviceContext> context;

	HRESULT hr = d3d11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, nullptr, 0,
		D3D11_SDK_VERSION, &device, &featureLevel, &context);

	if (hr != S_OK)
	{
		LOG_ERROR("MQGraphicsEngineDX11::InstallHooks: Failed to create device");
		return false;
	}

	wil::com_ptr_nothrow<IDXGIDevice> dxgiDevice;
	hr = device->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);
	if (hr != S_OK)
	{
		LOG_ERROR("MQGraphicsEngineDX11::InstallHooks: Failed to query dxgi device");
		return false;
	}

	wil::com_ptr_nothrow<IDXGIAdapter> adapter;
	hr = dxgiDevice->GetAdapter(&adapter);
	if (hr != S_OK)
	{
		LOG_ERROR("MQGraphicsEngineDX11::InstallHooks: Failed to get adapter");
		return false;
	}

	wil::com_ptr_nothrow<IDXGIFactory> factory;
	hr = adapter->GetParent(__uuidof(IDXGIFactory), (void**)&factory);
	if (hr != S_OK)
	{
		LOG_ERROR("MQGraphicsEngineDX11::InstallHooks: Failed to get factory");
		return false;
	}

	bool success = false;

	{
		wil::unique_hwnd hTmpWnd = CreateTempWindow();

		DXGI_SWAP_CHAIN_DESC desc = { 0 };
		desc.BufferCount = 2;
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.BufferDesc.Width = 2;
		desc.BufferDesc.Height = 2;
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.SampleDesc.Count = 1;
		desc.Windowed = 1;
		desc.OutputWindow = hTmpWnd.get();

		wil::com_ptr_nothrow<IDXGISwapChain> swapChain;
		hr = factory->CreateSwapChain(device.get(), &desc, &swapChain);
		if (hr != S_OK)
		{
			LOG_ERROR("MQGraphicsEngineDX11::InstallHooks: Failed to create swap chain");
		}
		else
		{
			// Hook DXGISwapChain
			uintptr_t* vtable = *(uintptr_t**)swapChain.get();

			InstallDetour(vtable[2], &DXGISwapChainHook::Release_Detour,
				DXGISwapChainHook::Release_Trampoline_Ptr, "DXGISwapChainHook::Release");
			InstallDetour(vtable[8], &DXGISwapChainHook::Present_Detour,
				DXGISwapChainHook::Present_Trampoline_Ptr, "DXGISwapChainHook::Present");
			InstallDetour(vtable[10], &DXGISwapChainHook::SetFullscreenState_Detour,
				DXGISwapChainHook::SetFullscreenState_Trampoline_Ptr, "DXGISwapChainHook::SetFullscreenState");
			InstallDetour(vtable[13], &DXGISwapChainHook::ResizeBuffers_Detour,
				DXGISwapChainHook::ResizeBuffers_Trampoline_Ptr, "DXGISwapChainHook::ResizeBuffers");

			success = true;
		}
	}

	if (!UnregisterClassW(WndClassName, nullptr))
	{
		LOG_ERROR("MQGraphicsEngineDX11::InstallHooks: Failed to unregister window class: {}", GetLastError());
	}

	return success;
}

//============================================================================

MQGraphicsEngineDX11::MQGraphicsEngineDX11()
{
	s_gfxEngine = this;
}

MQGraphicsEngineDX11::~MQGraphicsEngineDX11()
{
	s_gfxEngine = nullptr;
}

void MQGraphicsEngineDX11::Initialize()
{
	MQGraphicsEngine::Initialize();
}

void MQGraphicsEngineDX11::Shutdown()
{
	MQGraphicsEngine::Shutdown();
}

OverlayHookStatus MQGraphicsEngineDX11::InitializeOverlayHooks()
{
	if (m_deviceHooksInstalled)
	{
		if (!m_deviceAcquired)
		{
			return OverlayHookStatus::MissingDevice;
		}

		return OverlayHookStatus::Success;
	}

	if (!pGraphicsEngine || !pGraphicsEngine->pRender || !pGraphicsEngine->pRender->pD3DDevice)
	{
		return OverlayHookStatus::MissingDevice;
	}

	if (!InstallHooks())
	{
		LOG_ERROR("MQGraphicsEngineDX11::InitializeOverlayHooks: Failed to hook DirectX11, We won't be able to render into the game!");
		return OverlayHookStatus::Failed;
	}

	m_deviceHooksInstalled = true;
	m_lastGameState = gGameState;

	return !m_deviceAcquired ? OverlayHookStatus::MissingDevice : OverlayHookStatus::Success;
}

static Direct3DDevice9* GetDeviceFromEQ()
{
	Direct3DDevice9* pDevice = nullptr;

	if (pGraphicsEngine && pGraphicsEngine->pRender && pGraphicsEngine->pRender->pD3DDevice)
	{
		return pGraphicsEngine->pRender->pD3DDevice;
	}

	return nullptr;
}

void MQGraphicsEngineDX11::AcquireDevice(IDXGISwapChain* SwapChain)
{
	if (SwapChain == m_swapChain)
		return;

	if (SwapChain != nullptr)
	{
		OnDeviceLost(SwapChain);
	}

	if (SwapChain == nullptr)
	{
		return;
	}

	if (m_resetOverlayFrameDelay == 0)
	{
		HRESULT hr;
		if ((hr = SwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&m_device)) == S_OK)
		{
			m_device->GetImmediateContext(&m_deviceContext);
			m_swapChain = SwapChain;
			gpDXGISwapChain = SwapChain;
			gpD3D9Device = GetDeviceFromEQ();
			gpD3D11Device = m_device.get();

			m_deviceAcquired = true;

			LOG_INFO("MQGraphicsEngineDX11::AcquireDevice: Device acquired.");

			ImGui_Initialize();
			CreateDeviceObjects();
		}
		else
		{
			m_device.reset();

			LOG_ERROR("MQGraphicsEngineDX11::AcquireDevice: Failed to acquire device from SwapChain: {}", hr);
		}
	}
	else
	{
		--m_resetOverlayFrameDelay;
	}
}

void MQGraphicsEngineDX11::OnDeviceLost(IDXGISwapChain* SwapChain)
{
	if (SwapChain == m_swapChain && SwapChain != nullptr)
	{
		LOG_INFO("MQGraphicsEngineDX11::OnDeviceLost: Device has been lost.");

		InvalidateDeviceObjects();

		m_swapChain.reset();
		m_device.reset();
		m_deviceContext.reset();

		gpDXGISwapChain = nullptr;
		gpD3D9Device = nullptr;
		gpD3D11Device = nullptr;

		m_deviceAcquired = false;
	}
}

HRESULT MQGraphicsEngineDX11::OnPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	// Prevent re-entrancy. This happens because we will render ImGui from this call, which also calls Present
	// on its own viewport swap chains.
	static bool sbInPresentDetour = false;
	if (sbInPresentDetour || (Flags & DXGI_PRESENT_TEST) != 0)
	{
		return DXGISwapChainHook::Present(pSwapChain, SyncInterval, Flags);
	}

	sbInPresentDetour = true;

	AcquireDevice(pSwapChain);

	HRESULT result = DXGISwapChainHook::Present(pSwapChain, SyncInterval, Flags);

	if (result == DXGI_ERROR_DEVICE_REMOVED || result == DXGI_ERROR_DEVICE_RESET)
	{
		OnDeviceLost(pSwapChain);
	}
	else
	{
		PostEndScene();
	}

	sbInPresentDetour = false;

	return result;
}

HRESULT MQGraphicsEngineDX11::OnSetFullscreenState(IDXGISwapChain* SwapChain, BOOL Fullscreen, IDXGIOutput* Target)
{
	bool fullscreenState = Fullscreen != 0;

	if (test_and_set(m_lastFullScreenState, fullscreenState))
	{
		OnDeviceLost(SwapChain);

		m_needResetOverlay = true;
	}

	return DXGISwapChainHook::SetFullscreenState(SwapChain, Fullscreen, Target);
}

HRESULT MQGraphicsEngineDX11::OnResizeBuffers(IDXGISwapChain* SwapChain, UINT BufferCount, UINT Width, UINT Height,
	DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	//OnDeviceLost(SwapChain);

	return DXGISwapChainHook::ResizeBuffers(SwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
}


void MQGraphicsEngineDX11::ImGui_DrawFrame()
{
	ScopedStateBlock state(m_deviceContext.get());

	// Prepare the new frame
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();

	MQGraphicsEngine::ImGui_DrawFrame();
}

void MQGraphicsEngineDX11::ImGui_RenderDrawData()
{
	RenderDoc_ScopedEvent e(MQColor(104, 149, 255), L"ImGui_RenderDrawData");

	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void MQGraphicsEngineDX11::InitializeImGui_Internal()
{
	assert(m_swapChain != nullptr);
	
	// Get window handle from swap chain
	DXGI_SWAP_CHAIN_DESC desc;
	m_swapChain->GetDesc(&desc);

	// Initialize the platform backend and renderer bindings
	ImGui_ImplWin32_Init(desc.OutputWindow);
	ImGui_ImplDX11_Init(m_device.get(), m_deviceContext.get());
}

void MQGraphicsEngineDX11::ShutdownImGui_Internal()
{
	ImGui_ImplDX11_Shutdown();

	m_swapChain = nullptr;
	m_device = nullptr;
	m_deviceContext = nullptr;
}

void MQGraphicsEngineDX11::InvalidateDeviceObjects_Internal()
{
	ImGui_ImplDX11_InvalidateDeviceObjects();

	m_imguiReady = false;
}

void MQGraphicsEngineDX11::CreateDeviceObjects_Internal()
{
	m_imguiReady = ImGui_ImplDX11_CreateDeviceObjects();
}

void MQGraphicsEngineDX11::UpdateScene_Internal()
{
	if (s_renderCallbacks.empty())
		return;

	ScopedStateBlock state(m_deviceContext.get());

	MQGraphicsEngine::UpdateScene_Internal();
}

void MQGraphicsEngineDX11::ImGuiRenderDebug_UpdateImGui()
{
}

void MQGraphicsEngineDX11::PostEndScene_Internal()
{
}

void MQGraphicsEngineDX11::OnUpdateFrame_Internal()
{
}

bool MQGraphicsEngineDX11::IsFullScreen() const
{
	BOOL fullscreenState = FALSE;
	HRESULT hr = m_swapChain->GetFullscreenState(&fullscreenState, nullptr);
	if (hr != S_OK)
	{
		LOG_ERROR("MQGraphicsEngineDX11::IsFullScreen: Failed to read fullscreen state from SwapChain: {}", hr);
	}

	return fullscreenState != 0;
}

MQGraphicsEngine* CreateRendererDX11()
{
	return new MQGraphicsEngineDX11();
}

} // namespace mq

#endif // HAS_DIRECTX_11
