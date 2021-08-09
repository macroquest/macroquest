/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
#include "MQ2DeveloperTools.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "mq/imgui/Widgets.h"

namespace mq::imgui {

bool DrawUITexture(const CUITextureInfo& textureInfo, const CXRect& rect/* = CXRect(0, 0, -1, -1)*/,
	const CXSize& size /* = CXSize()*/,
	bool drawBorder /* = false */)
{
	if (textureInfo.TextureId == -1)
	{
		if (pEQSuiteTextureLoader)
		{
			// break the rules to lazy init the texture id.
			const_cast<CUITextureInfo&>(textureInfo).TextureId = pEQSuiteTextureLoader->CreateTexture(textureInfo);
		}

		// if the texture is still missing then stop
		if (textureInfo.TextureId == -1)
			return false;
	}

	// Try to extract texture info from the texture manager, if it exists already.
	// This won't work at login until we map the texture loader to the login instance.

	if (!pEQSuiteTextureLoader)
		return false;

	BMI* bitmap = pEQSuiteTextureLoader->GetTexture(textureInfo);
	if (!bitmap)
		return false;

	CEQGBitmap* pEQGBitmap = bitmap->pBmp;
	if (!pEQGBitmap)
		return false;

	if (pEQGBitmap->pD3DTexture == nullptr)
		return false;

	ImVec2 minUV = ImVec2(0, 0);
	ImVec2 maxUV = ImVec2(1, 1);
	ImVec2 textureSize = ImVec2((float)textureInfo.TextureSize.cx, (float)textureInfo.TextureSize.cy);

	ImVec2 imageSize;
	if (size.cx != 0 && size.cy != 0)
		imageSize = ImVec2(static_cast<float>(size.cx), static_cast<float>(size.cy));
	else
		imageSize = textureSize;

	if (!rect.IsAbnormal())
	{
		minUV.x = rect.left / textureSize.x;
		minUV.y = rect.top / textureSize.y;

		maxUV.x = rect.right / textureSize.x;
		maxUV.y = rect.bottom / textureSize.y;

		textureSize.x = (float)rect.GetWidth();
		textureSize.y = (float)rect.GetHeight();
	}

	ImGui::Image(
		(ImTextureID)pEQGBitmap->pD3DTexture, imageSize,
		minUV, maxUV,
		ImVec4(1, 1, 1, 1),
		drawBorder ? ImVec4(1, 1, 1, 0.5f) : ImVec4()
	);
	return true;
}

bool DrawTexturePiece(const CUITexturePiece& texturePiece, const CXRect& srcRect, const CXSize& imageSize, bool drawBorder)
{
	return DrawUITexture(texturePiece.GetTextureInfo(), srcRect, imageSize, drawBorder);
}

bool DrawTexturePiece(const CUITexturePiece& texturePiece, const CXSize& imageSize, bool drawBorder)
{
	return DrawTexturePiece(texturePiece, texturePiece.GetRect(), imageSize, drawBorder);
}

bool DrawTextureAnimation(const CTextureAnimation* pAnim, const CXSize& size, bool drawBorder)
{
	CXSize theSize = size.cx != 0 && size.cy != 0 ? size : (pAnim->bGrid ? pAnim->CellRect.GetSize() : pAnim->Size);

	if (pAnim->Frames.IsEmpty())
	{
		ImGui::ItemSize(ImVec2(static_cast<float>(theSize.cx), static_cast<float>(theSize.cy)));
		// TODO: Draw box with the current size.
		return false;
	}

	int frameNum = pAnim->GetCurFrame();
	if (frameNum < 0 || frameNum >= pAnim->Frames.GetLength())
		return false;

	const STextureAnimationFrame& frame = pAnim->Frames[frameNum];

	if (pAnim->bGrid)
	{
		if (pAnim->CurCell != -1)
		{
			return DrawTexturePiece(frame.Piece, pAnim->CellRect, theSize, drawBorder);
		}
	}
	else
	{
		return DrawTexturePiece(frame.Piece, theSize, drawBorder);
	}

	return false;
}

//----------------------------------------------------------------------------

bool ItemLinkTextV(const char* fmt, va_list args)
{
	ImVec2 pos = ImGui::GetCursorPos();
	MQColor textLinkColor = GetColorForChatColor(USERCOLOR_LINK);
	ImGui::TextColoredV(textLinkColor.ToImColor(), fmt, args);

	bool clicked = ImGui::IsItemClicked(0);

	if (ImGui::IsItemHovered())
	{
		ImGui::SetCursorPos(pos);

		// HACK: Render text again with different color.
		ImGui::TextColoredV(MQColor(0, 0, 128).ToImColor(), fmt, args);
	}

	return clicked;
}

bool ItemLinkText(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	bool result = ItemLinkTextV(fmt, args);
	va_end(args);
	return result;
}


} // namespace mq::imgui
