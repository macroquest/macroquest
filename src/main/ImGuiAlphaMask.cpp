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
#include "mq/imgui/AlphaMask.h"
#include "ImGuiBackend.h"

#include "eqlib/BuildType.h"
#include "imgui/imgui.h"
#include "mq/api/RenderDoc.h"

#if HAS_DIRECTX_11
#include <d3d11.h>
#endif
#if HAS_DIRECTX_9
#include <d3d9.h>
#endif

namespace mq::imgui {

struct MaskEntry
{
	uint8_t WriteMask;  // the single bit assigned to this CreateAlphaMaskLayer call
	uint8_t AccumMask;  // all active bits at the time this layer was pushed (includes WriteMask)
};

static std::vector<MaskEntry> s_mask_stack;
static uint8_t s_next_bit = 1;
static uint8_t s_accum_bits = 0;

struct AlphaMaskParams
{
	uint8_t WriteMask = 0;  // the bit assigned to this Begin
	uint8_t AccumMask = 0;  // all active bits (used by End to compute the test ref)
	uint8_t Op = 0;         // AlphaMaskOp cast to uint8_t
};

#if HAS_DIRECTX_11

static void CreateAlphaMaskLayer_ImplDX11(const ImDrawList*, const ImDrawCmd* cmd)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs || !rs->StencilDSV)
		return;

	RenderDoc_ScopedEvent e(MQColor(173, 39, 245), L"CreateAlphaMaskLayer");

	auto* params = static_cast<AlphaMaskParams*>(cmd->UserCallbackData);
	ID3D11DeviceContext* ctx = rs->DeviceContext;

	// Find the 0-based bit index from WriteMask.
	int bit_idx = 0;
	for (uint8_t m = params->WriteMask; !(m & 1) && bit_idx < 7; m >>= 1, ++bit_idx) {}

	// Bind our dedicated stencil DSV alongside the current RTV.
	ID3D11RenderTargetView* rtv = nullptr;
	ID3D11DepthStencilView* prevDSV = nullptr;
	ctx->OMGetRenderTargets(1, &rtv, &prevDSV);
	ctx->OMSetRenderTargets(1, &rtv, rs->StencilDSV);
	if (rtv)
		rtv->Release();
	if (prevDSV)
		prevDSV->Release();

	// Write only this bit, colour writes disabled (stencil only).
	ctx->OMSetBlendState(rs->NoColorBlendState, nullptr, 0xFFFFFFFF);
	ctx->OMSetDepthStencilState(rs->StencilWriteDSS[bit_idx], params->WriteMask);

	// Switch to the alpha-discard PS so only texels with alpha >= 0.5 write the stencil bit.
	if (rs->AlphaDiscardPS)
		ctx->PSSetShader(rs->AlphaDiscardPS, nullptr, 0);
}

static void BeginMaskedDraw_ImplDX11(const ImDrawList*, const ImDrawCmd* cmd)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs || !rs->StencilDSV)
		return;

	RenderDoc_ScopedEvent e(MQColor(173, 39, 245), L"BeginMaskedDraw");

	auto* params = static_cast<AlphaMaskParams*>(cmd->UserCallbackData);
	ID3D11DeviceContext* ctx = rs->DeviceContext;

	ID3D11DepthStencilState* dss;
	UINT ref;

	// Find 0-based bit index from WriteMask
	int bit_idx = 0;
	for (uint8_t m = params->WriteMask; !(m & 1) && bit_idx < 7; m >>= 1, ++bit_idx) {}

	switch (static_cast<AlphaMaskOp>(params->Op))
	{
	case AlphaMaskOp::Union:
		dss = rs->StencilTestNotEqualDSS;
		ref = 0;
		break;
	case AlphaMaskOp::Subtract:
		dss = rs->StencilTestEqualDSS;
		ref = params->AccumMask & ~params->WriteMask;
		break;
	case AlphaMaskOp::Complement:
		dss = rs->StencilTestEqualDSS;
		ref = 0;
		break;
	case AlphaMaskOp::Intersect:
	default:
		dss = rs->StencilTestEqualDSS;
		ref = params->AccumMask;
		break;
	}

	ctx->OMSetBlendState(rs->DefaultBlendState, nullptr, 0xFFFFFFFF);
	ctx->OMSetDepthStencilState(dss, ref);

	// Restore the default PS
	if (rs->DefaultPS)
		ctx->PSSetShader(rs->DefaultPS, nullptr, 0);
}

static void EndMaskedDraw_ImplDX11(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs || !rs->StencilDSV)
		return;

	RenderDoc_ScopedEvent e(MQColor(173, 39, 245), L"EndMaskedDraw");

	ID3D11DeviceContext* ctx = rs->DeviceContext;

	// Restore default DSS (stencil disabled) and normal blend state.
	ctx->OMSetDepthStencilState(rs->DefaultDSS, 0);
	ctx->OMSetBlendState(rs->DefaultBlendState, nullptr, 0xFFFFFFFF);

	// Restore render targets
	ID3D11RenderTargetView* rtv = nullptr;
	ID3D11DepthStencilView* ignoredDSV = nullptr;
	ctx->OMGetRenderTargets(1, &rtv, &ignoredDSV);
	ctx->OMSetRenderTargets(1, &rtv, nullptr);
	if (rtv)
		rtv->Release();
	if (ignoredDSV)
		ignoredDSV->Release();

	// Clear the stencil so the next mask session in this frame starts with a clean buffer.
	ctx->ClearDepthStencilView(rs->StencilDSV, D3D11_CLEAR_STENCIL, 1.0f, 0);
}

static void ClearFbAlpha_ImplDX11(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	RenderDoc_ScopedEvent e(MQColor(100, 180, 255), L"ClearFbAlpha");

	// Force fb alpha to exactly 0 in the masked region - vertex alpha is irrelevant.
	rs->DeviceContext->OMSetBlendState(rs->ZeroAlphaBlendState, nullptr, 0xFFFFFFFF);
	rs->DeviceContext->OMSetDepthStencilState(rs->DefaultDSS, 0);
}

static void CreateCoverageMaskLayer_ImplDX11(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	RenderDoc_ScopedEvent e(MQColor(100, 180, 255), L"CreateAlphaLayerMask");

	// Write only framebuffer alpha - tex.a becomes coverage for subsequent content draws.
	rs->DeviceContext->OMSetBlendState(rs->AlphaWriteBlendState, nullptr, 0xFFFFFFFF);
	rs->DeviceContext->OMSetDepthStencilState(rs->DefaultDSS, 0);
}

static void BeginAlphaBlendedDraw_ImplDX11(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	RenderDoc_ScopedEvent e(MQColor(100, 180, 255), L"BeginAlphaBlendedDraw");

	// Blend RGB using framebuffer alpha: out.rgb = src * coverage + dest * (1 - coverage).
	rs->DeviceContext->OMSetBlendState(rs->DestAlphaBlendState, nullptr, 0xFFFFFFFF);
	rs->DeviceContext->OMSetDepthStencilState(rs->DefaultDSS, 0);
}

static void EndAlphaBlendedDraw_ImplDX11(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX11_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	RenderDoc_ScopedEvent e(MQColor(100, 180, 255), L"EndAlphaBlendedDraw");

	rs->DeviceContext->OMSetBlendState(rs->DefaultBlendState, nullptr, 0xFFFFFFFF);
	rs->DeviceContext->OMSetDepthStencilState(rs->DefaultDSS, 0);
}

#endif // HAS_DIRECTX_11

#if HAS_DIRECTX_9

static void CreateAlphaMaskLayer_ImplDX9(const ImDrawList*, const ImDrawCmd* cmd)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs || !rs->StencilSurface)
		return;

	auto* params = static_cast<AlphaMaskParams*>(cmd->UserCallbackData);
	IDirect3DDevice9* device = rs->Device;

	// Write only this bit into the stencil; suppress all color output.
	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0);
	device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
	device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
	device->SetRenderState(D3DRS_STENCILREF, params->WriteMask);
	device->SetRenderState(D3DRS_STENCILMASK, 0xFF);
	device->SetRenderState(D3DRS_STENCILWRITEMASK, params->WriteMask);
	device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
	device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
	device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);

	// Enable alpha testing so only texels with alpha >= 0.5 write to the stencil.
	device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	device->SetRenderState(D3DRS_ALPHAREF, 128);
}

static void BeginMaskedDraw_ImplDX9(const ImDrawList*, const ImDrawCmd* cmd)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs || !rs->StencilSurface)
		return;

	auto* params = static_cast<AlphaMaskParams*>(cmd->UserCallbackData);
	IDirect3DDevice9* device = rs->Device;

	DWORD ref;
	DWORD mask;
	D3DCMPFUNC func;

	switch (static_cast<AlphaMaskOp>(params->Op))
	{
	case AlphaMaskOp::Union:
		func = D3DCMP_NOTEQUAL;
		mask = 0xFF;
		ref = 0;
		break;
	case AlphaMaskOp::Subtract:
		func = D3DCMP_EQUAL;
		mask = 0xFF;
		ref = params->AccumMask & ~params->WriteMask;
		break;
	case AlphaMaskOp::Complement:
		func = D3DCMP_EQUAL;
		mask = 0xFF;
		ref = 0;
		break;
	case AlphaMaskOp::Intersect:
	default:
		func = D3DCMP_EQUAL;
		mask = 0xFF;
		ref = params->AccumMask;
		break;
	}

	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);   // enable RGBA writes
	device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
	device->SetRenderState(D3DRS_STENCILFUNC, func);
	device->SetRenderState(D3DRS_STENCILREF, ref);
	device->SetRenderState(D3DRS_STENCILMASK, mask);
	device->SetRenderState(D3DRS_STENCILWRITEMASK, 0);     // no writes to stencil during test
	device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
	device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
	device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);

	// Disable alpha testing enabled by CreateAlphaMaskLayer.
	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

static void EndMaskedDraw_ImplDX9(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs || !rs->StencilSurface)
		return;

	// Disable stencil test and restore color writes.
	// The DX9 state block at the end of RenderDrawData handles full state restoration.
	rs->Device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	rs->Device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);

	// Clear the stencil so the next mask session in this frame starts with a clean buffer.
	rs->Device->Clear(0, nullptr, D3DCLEAR_STENCIL, 0, 1.0f, 0);
}

static void ClearFbAlpha_ImplDX9(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	IDirect3DDevice9* device = rs->Device;

	// Zero the RT alpha channel in the masked region.
	// ZERO * src_a + ZERO * dst_a = 0 -> RT.a = 0.
	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0x8);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_ZERO);
	device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ZERO);
	device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
}

static void CreateCoverageMaskLayer_ImplDX9(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	IDirect3DDevice9* device = rs->Device;

	// Write mask alpha into RT alpha: RT.a = tex.a.
	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0x8);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_ONE);
	device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ZERO);
	device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

static void BeginAlphaBlendedDraw_ImplDX9(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	IDirect3DDevice9* device = rs->Device;

	// Blend content using RT.alpha as coverage: out.RGB = content * mask_a + dest * (1 - mask_a).
	// Preserve the mask with SRCBLENDALPHA = ZERO, DESTBLENDALPHA = ONE.
	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_DESTALPHA);
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVDESTALPHA);
	device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_ZERO);
	device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ONE);
	device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

static void EndAlphaBlendedDraw_ImplDX9(const ImDrawList*, const ImDrawCmd*)
{
	auto* rs = static_cast<ImGui_ImplDX9_RenderState*>(ImGui::GetPlatformIO().Renderer_RenderState);
	if (!rs)
		return;

	IDirect3DDevice9* device = rs->Device;

	// Restore normal imgui blend state.
	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_ONE);
	device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_INVSRCALPHA);
}

#endif // HAS_DIRECTX_9

static ImDrawCallback s_createLayerCallback = nullptr;
static ImDrawCallback s_beginMaskedDrawCallback = nullptr;
static ImDrawCallback s_endMaskedDrawCallback = nullptr;
static ImDrawCallback s_clearFbAlphaCallback = nullptr;
static ImDrawCallback s_createCoverageMaskLayerCallback = nullptr;
static ImDrawCallback s_beginAlphaBlendedDrawCallback = nullptr;
static ImDrawCallback s_endAlphaBlendedDrawCallback = nullptr;

static void EnsureCallbacksResolved()
{
	if (s_createLayerCallback)
		return;

#if HAS_DIRECTX_11
	s_createLayerCallback = CreateAlphaMaskLayer_ImplDX11;
	s_beginMaskedDrawCallback = BeginMaskedDraw_ImplDX11;
	s_endMaskedDrawCallback = EndMaskedDraw_ImplDX11;
	s_clearFbAlphaCallback = ClearFbAlpha_ImplDX11;
	s_createCoverageMaskLayerCallback = CreateCoverageMaskLayer_ImplDX11;
	s_beginAlphaBlendedDrawCallback = BeginAlphaBlendedDraw_ImplDX11;
	s_endAlphaBlendedDrawCallback = EndAlphaBlendedDraw_ImplDX11;
#endif

#if HAS_DIRECTX_9
	s_createLayerCallback = CreateAlphaMaskLayer_ImplDX9;
	s_beginMaskedDrawCallback = BeginMaskedDraw_ImplDX9;
	s_endMaskedDrawCallback = EndMaskedDraw_ImplDX9;
	s_clearFbAlphaCallback = ClearFbAlpha_ImplDX9;
	s_createCoverageMaskLayerCallback = CreateCoverageMaskLayer_ImplDX9;
	s_beginAlphaBlendedDrawCallback = BeginAlphaBlendedDraw_ImplDX9;
	s_endAlphaBlendedDrawCallback = EndAlphaBlendedDraw_ImplDX9;
#endif
}

void CreateMaskLayer(ImDrawList* draw_list)
{
	EnsureCallbacksResolved();

	if (s_next_bit == 0)
		return; // all 8 bits exhausted for this session

	const uint8_t bit = s_next_bit;
	s_next_bit <<= 1;
	s_accum_bits |= bit;
	s_mask_stack.emplace_back(bit, s_accum_bits);

	AlphaMaskParams params = {
		.WriteMask = bit,
		.AccumMask = s_accum_bits,
		.Op = static_cast<uint8_t>(AlphaMaskOp::Intersect)
	};
	draw_list->AddCallback(s_createLayerCallback, &params, sizeof(params));
}

void BeginMaskedDraw(ImDrawList* draw_list, AlphaMaskOp op)
{
	EnsureCallbacksResolved();

	if (s_mask_stack.empty())
		return;

	const MaskEntry& top = s_mask_stack.back();
	AlphaMaskParams params = {
		.WriteMask = top.WriteMask,
		.AccumMask = top.AccumMask,
		.Op = static_cast<uint8_t>(op)
	};
	draw_list->AddCallback(s_beginMaskedDrawCallback, &params, sizeof(params));
}

void EndMaskedDraw(ImDrawList* draw_list)
{
	EnsureCallbacksResolved();

	AlphaMaskParams params = {};
	draw_list->AddCallback(s_endMaskedDrawCallback, &params, sizeof(params));

	// Reset build-time state for the next session.
	s_mask_stack.clear();
	s_accum_bits = 0;
	s_next_bit = 1;
}

void CreateCoverageMaskLayer(ImDrawList* draw_list, const ImVec2& p_min, const ImVec2& p_max)
{
	EnsureCallbacksResolved();

	draw_list->PushClipRect(p_min, p_max, true);

	// Step 1: force fb alpha to exactly 0 in the masked region.
	draw_list->AddCallback(s_clearFbAlphaCallback, nullptr, 0);
	draw_list->AddRectFilled(p_min, p_max, IM_COL32(0, 0, 0, 255));

	// Step 2: switch to alpha-write mode so the mask image writes its alpha to fb.
	draw_list->AddCallback(s_createCoverageMaskLayerCallback, nullptr, 0);
}

void BeginCoverageMaskedDraw(ImDrawList* draw_list)
{
	EnsureCallbacksResolved();

	draw_list->AddCallback(s_beginAlphaBlendedDrawCallback, nullptr, 0);
}

void EndCoverageMaskedDraw(ImDrawList* draw_list)
{
	EnsureCallbacksResolved();

	draw_list->AddCallback(s_endAlphaBlendedDrawCallback, nullptr, 0);
	draw_list->PopClipRect();
}

} // namespace mq::imgui
