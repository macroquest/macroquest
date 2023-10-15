/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

	ImTextureID TexID = (ImTextureID)pEQGBitmap->GetTexture();
	if (TexID == nullptr)
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
		TexID, imageSize,
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

MQColor DefaultLinkHoverColor = MQColor(0, 0, 255);

bool ItemLinkTextV_Internal(ImGuiID id, MQColor color, const char* fmt, va_list args)
{
	ImGui::PushID(id);

	static ImGuiID hoveredID = 0;
	ImGuiID thisID = ImGui::GetItemID();

	bool isHovered = (hoveredID == thisID);
	MQColor textLinkColor = isHovered ? DefaultLinkHoverColor : color;

	ImGui::TextColoredV(textLinkColor.ToImColor(), fmt, args);

	bool clicked = ImGui::IsItemClicked(0);

	if (ImGui::IsItemHovered())
	{
		hoveredID = thisID;
	}
	else if (isHovered)
	{
		hoveredID = 0;
	}

	ImGui::PopID();

	return clicked;
}

bool ItemLinkText(std::string_view sv, MQColor color, MQColor colorHovered)
{
	const char* str_begin = sv.data();
	const char* str_end = sv.data() + sv.length();

	ImGuiID thisID = ImGui::GetID(str_begin, str_end);
	ImGui::PushOverrideID(thisID);

	static ImGuiID hoveredID = 0;

	bool isHovered = (hoveredID == thisID);
	MQColor textLinkColor = isHovered ? colorHovered : color;

	ImGui::PushStyleColor(ImGuiCol_Text, textLinkColor.ToImU32());

	ImGui::TextUnformatted(str_begin, str_end);

	bool clicked = ImGui::IsItemClicked();

	if (ImGui::IsItemHovered())
		hoveredID = thisID;
	else if (isHovered)
		hoveredID = 0;

	ImGui::PopStyleColor();
	ImGui::PopID();

	return clicked;
}

bool ItemLinkTextV_Internal(const char* str_id, MQColor color, MQColor colorHovered, const char* fmt, va_list args)
{
	ImGui::PushID(str_id);

	static ImGuiID hoveredID = 0;
	ImGuiID thisID = ImGui::GetID(str_id);

	bool isHovered = (hoveredID == thisID);
	MQColor textLinkColor = isHovered ? colorHovered : color;

	ImGui::PushStyleColor(ImGuiCol_Text, textLinkColor.ToImU32());

	ImGui::TextV(fmt, args);

	bool clicked = ImGui::IsItemClicked();

	if (ImGui::IsItemHovered())
		hoveredID = thisID;
	else if (isHovered)
		hoveredID = 0;

	ImGui::PopStyleColor();
	ImGui::PopID();

	return clicked;
}

bool ItemLinkTextV(const char* str_id, MQColor color, const char* fmt, va_list args)
{
	return ItemLinkTextV_Internal(str_id, color, DefaultLinkHoverColor, fmt, args);
}

bool ItemLinkText(const char* str_id, MQColor color, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	bool result = ItemLinkTextV_Internal(str_id, color, DefaultLinkHoverColor, fmt, args);
	va_end(args);
	return result;
}

} // namespace mq::imgui
