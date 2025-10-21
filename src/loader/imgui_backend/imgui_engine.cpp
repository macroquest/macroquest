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

#include "imgui_engine.h"

#include "imgui/ImGuiUtils.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"

#include <d3d11.h>

// Data
static ID3D11Device* s_d3dDevice = nullptr;
static ID3D11DeviceContext* s_d3dDeviceContext = nullptr;
static IDXGISwapChain* s_swapChain = nullptr;
static ID3D11RenderTargetView* s_mainRenderTargetView = nullptr;

// Helper function forward declarations
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void LauncherImGui::Backend::Init(HWND hWnd, const char* iniFilename, const char* logFilename)
{
	// Initialize D3D
	if (!CreateDeviceD3D(hWnd))
	{
		CleanupDeviceD3D();
        IM_ASSERT(false && "CreateDeviceD3D failed");
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.ConfigViewportsNoTaskBarIcon = false;
	io.ConfigViewportsNoDefaultParent = true;
	io.ConfigViewportsNoAutoMerge = false;
	io.ConfigViewportsNoDecoration = true;
	io.IniFilename = iniFilename;
	io.LogFilename = logFilename;

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;

	// set windows message hook here? Not sure we need it in our case

	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(s_d3dDevice, s_d3dDeviceContext);

	// setup fonts
	io.Fonts->Clear();
	mq::imgui::ConfigureFonts(io.Fonts);
	IM_ASSERT(io.Fonts->Build() && "ImGui::GetIO().Fonts->Build() failed!");

	mq::imgui::ConfigureStyle();
}

void LauncherImGui::Backend::DrawFrame(const std::function<void()>& drawFrame)
{
	// don't think we need to resize buffers

	// create frame
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// draw the user-defined windows
	drawFrame();

	ImGui::EndFrame();

	ImGuiContext& g = *ImGui::GetCurrentContext();
	if (g.HoveredWindow == nullptr)
	{
		if (g.NavWindow != nullptr)
		{
			if (ImGui::GetIO().MouseClicked[0])
			{
				ImGui::ClearActiveID();
			}
		}
	}
	if (g.HoveredWindow == nullptr && g.NavWindow != nullptr && ImGui::GetIO().MouseClicked[ImGuiMouseButton_Left])
	{
		ImGui::FocusWindow(nullptr, ImGuiFocusRequestFlags_None);
		ImGui::ClearActiveID();
	}

	// render
	ImGui::Render();
	ImVec4 clear_color = ImVec4(0.f, 0.f, 0.f, 0.f);
	const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
	s_d3dDeviceContext->OMSetRenderTargets(1, &s_mainRenderTargetView, nullptr);
	s_d3dDeviceContext->ClearRenderTargetView(s_mainRenderTargetView, clear_color_with_alpha);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();

	s_swapChain->Present(1, 0);
}

void LauncherImGui::Backend::Cleanup()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupDeviceD3D();
}

bool LauncherImGui::Backend::HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	return false;
}

bool CreateDeviceD3D(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	uint32_t createDeviceFlags = 0;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &s_swapChain, &s_d3dDevice, &featureLevel, &s_d3dDeviceContext);
	if (res == DXGI_ERROR_UNSUPPORTED)
		res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &s_swapChain, &s_d3dDevice, &featureLevel, &s_d3dDeviceContext);
	if (res != S_OK)
		return false;

	CreateRenderTarget();
	return true;
}

void CleanupDeviceD3D()
{
	CleanupRenderTarget();
	if (s_swapChain != nullptr)
	{
		s_swapChain->Release();
		s_swapChain = nullptr;
	}

	if (s_d3dDeviceContext != nullptr)
	{
		s_d3dDeviceContext->Release();
		s_d3dDeviceContext = nullptr;
	}

	if (s_d3dDevice != nullptr)
	{
		s_d3dDevice->Release();
		s_d3dDevice = nullptr;
	}
}

void CreateRenderTarget()
{
	ID3D11Texture2D* back_buffer;
	s_swapChain->GetBuffer(0, IID_PPV_ARGS(&back_buffer));
	s_d3dDevice->CreateRenderTargetView(back_buffer, nullptr, &s_mainRenderTargetView);
	back_buffer->Release();
}

void CleanupRenderTarget()
{
	if (s_mainRenderTargetView != nullptr)
	{
		s_mainRenderTargetView->Release();
		s_mainRenderTargetView = nullptr;
	}
}

