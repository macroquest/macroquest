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
#include "MQ2DeveloperTools.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "mq/imgui/Widgets.h"

namespace mq::imgui {

//
// Handle drawing of a UITexture.
//

static ImTextureID GetTextureID(const CUITextureInfo& textureInfo)
{
	if (static_cast<int>(textureInfo.TextureId) == -1)
	{
		if (pEQSuiteTextureLoader)
		{
			// break the rules to lazy init the texture id.
			const_cast<CUITextureInfo&>(textureInfo).TextureId = pEQSuiteTextureLoader->CreateTexture(textureInfo);
		}

		// if the texture is still missing then stop
		if (static_cast<int>(textureInfo.TextureId) == -1)
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

#if HAS_DIRECTX_11
	ImTextureID TexID = pEQGBitmap;
#else
	ImTextureID TexID = (ImTextureID)pEQGBitmap->GetTexture();
#endif

	return TexID;
}

static bool HandleFraming(ImDrawList* drawList, CXPoint& pos, CXSize& size, const MQColor& borderColor, bool addItem)
{
	bool hasBorder = borderColor.Alpha > 0;
	ImRect bb(pos, pos + size + (hasBorder ? 2 : 0));
	if (hasBorder) pos = pos + 1;

	if (addItem)
	{
		ImGui::ItemSize(size);

		if (!ImGui::ItemAdd(bb, 0))
			return false;
	}

	if (hasBorder)
	{
		// Draw border
		drawList->AddRect(bb.Min, bb.Max, borderColor.ToImU32(), 0.0f);
	}

	return true;
}

static CXSize GetEffectiveSize(const CXSize& size, const CTextureAnimation* textureAnimation)
{
	return size.cx != 0 && size.cy != 0 ? size : (textureAnimation->bGrid ? textureAnimation->CellRect.GetSize() : textureAnimation->Size);
}

static CXSize GetEffectiveSize(const CXSize& size, const CUITextureInfo& textureInfo)
{
	return size.cx != 0 && size.cy != 0 ? size : textureInfo.TextureSize;
}

//----------------------------------------------------------------------------

static bool DrawUITextureInternal(ImDrawList* drawList,
	const CUITextureInfo& textureInfo,
	const ImVec2& screenPos,
	const ImVec2& imageSize,
	const CXRect& sourceRect,
	const MQColor& tintColor)
{
	ImTextureID TexID = GetTextureID(textureInfo);
	if (TexID == nullptr)
		return false;

	ImVec2 minUV = ImVec2(0, 0);
	ImVec2 maxUV = ImVec2(1, 1);
	ImVec2 textureSize = textureInfo.TextureSize;

	if (!sourceRect.IsAbnormal())
	{
		minUV.x = static_cast<float>(sourceRect.left) / textureSize.x;
		minUV.y = static_cast<float>(sourceRect.top) / textureSize.y;

		maxUV.x = static_cast<float>(sourceRect.right) / textureSize.x;
		maxUV.y = static_cast<float>(sourceRect.bottom) / textureSize.y;
	}

	ImVec2 p_min = screenPos;
	ImVec2 p_max = screenPos + imageSize;

	drawList->AddImage(TexID, p_min, p_max, minUV, maxUV, tintColor.ToImU32());

	return true;
}

//----------------------------------------------------------------------------

bool DrawUITexture(
	const CUITextureInfo& textureInfo,
	const CXSize& size,
	const CXRect& sourceRect,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	CXPoint thePos = window->DC.CursorPos;
	CXSize theSize = GetEffectiveSize(size, textureInfo);

	if (!HandleFraming(window->DrawList, thePos, theSize, borderColor, true))
		return false;

	return DrawUITextureInternal(window->DrawList, textureInfo, CXPoint(), size, sourceRect, tintColor);
}

bool AddUITexture(
	ImDrawList* drawList,
	const CUITextureInfo& textureInfo,
	const CXPoint& screenPos,
	const CXSize& size,
	const CXRect& sourceRect,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	CXPoint thePos = screenPos;
	CXSize theSize = GetEffectiveSize(size, textureInfo);

	if (!HandleFraming(drawList, thePos, theSize, borderColor, false))
		return false;

	return DrawUITextureInternal(drawList, textureInfo, screenPos, size, sourceRect, tintColor);
}


//
// Handle drawing of a CUITexturePiece
//

bool DrawTexturePiece(
	const CUITexturePiece& texturePiece,
	const CXSize& size,
	const CXRect& sourceRect,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	CXPoint thePos = window->DC.CursorPos;
	CXSize theSize = GetEffectiveSize(size, texturePiece.GetTextureInfo());

	if (!HandleFraming(window->DrawList, thePos, theSize, borderColor, true))
		return false;

	return DrawUITextureInternal(window->DrawList, texturePiece.GetTextureInfo(), thePos, theSize, sourceRect, tintColor);
}

bool DrawTexturePiece(
	const CUITexturePiece& texturePiece,
	const CXSize& imageSize,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	return DrawTexturePiece(texturePiece, imageSize, texturePiece.GetRect(), tintColor, borderColor);
}

bool AddTexturePiece(
	ImDrawList* drawList,
	const CUITexturePiece& texturePiece,
	const CXPoint& pos,
	const CXSize& size,
	const CXRect& sourceRect,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	CXPoint thePos = pos;
	CXSize theSize = GetEffectiveSize(size, texturePiece.GetTextureInfo());

	if (!HandleFraming(drawList, thePos, theSize, borderColor, false))
		return false;

	return DrawUITextureInternal(drawList, texturePiece.GetTextureInfo(), thePos, theSize, sourceRect, tintColor);
}

bool AddTexturePiece(
	ImDrawList* drawList,
	const CUITexturePiece& texturePiece,
	const CXPoint& pos,
	const CXSize& size,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	return AddTexturePiece(drawList, texturePiece, pos, size, texturePiece.GetRect(), tintColor);
}

//
// Handle drawing of a CTextureAnimation
//

bool DrawTextureAnimation(
	const CTextureAnimation* textureAnimation,
	const CXSize& size,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	CXPoint thePos = window->DC.CursorPos;
	CXSize theSize = GetEffectiveSize(size, textureAnimation);

	if (!HandleFraming(window->DrawList, thePos, theSize, borderColor, true))
		return false;

	if (textureAnimation->Frames.IsEmpty())
		return true;

	int frameNum = textureAnimation->GetCurFrame();
	if (frameNum < 0 || frameNum >= textureAnimation->Frames.GetLength())
		return true;
	const STextureAnimationFrame& frame = textureAnimation->Frames[frameNum];

	if (textureAnimation->bGrid)
	{
		if (textureAnimation->CurCell != -1)
		{
			DrawUITextureInternal(window->DrawList, frame.Piece.GetTextureInfo(), thePos, theSize, textureAnimation->CellRect, tintColor);
		}
	}
	else
	{
		DrawUITextureInternal(window->DrawList, frame.Piece.GetTextureInfo(), thePos, theSize, frame.Piece.GetRect(), tintColor);
	}

	return true;
}

bool AddTextureAnimation(
	ImDrawList* drawList,
	const CTextureAnimation* textureAnimation,
	const CXPoint& pos,
	const CXSize& size,
	const MQColor& tintColor,
	const MQColor& borderColor)
{
	CXPoint thePos = pos;
	CXSize theSize = GetEffectiveSize(size, textureAnimation);

	if (!HandleFraming(drawList, thePos, theSize, borderColor, false))
		return false;

	if (textureAnimation->Frames.IsEmpty())
		return false;

	int frameNum = textureAnimation->GetCurFrame();
	if (frameNum < 0 || frameNum >= textureAnimation->Frames.GetLength())
		return false;

	const STextureAnimationFrame& frame = textureAnimation->Frames[frameNum];

	if (textureAnimation->bGrid)
	{
		if (textureAnimation->CurCell != -1)
		{
			return DrawUITextureInternal(drawList, frame.Piece.GetTextureInfo(), thePos, theSize, textureAnimation->CellRect, tintColor);
		}
	}
	else
	{
		return DrawUITextureInternal(drawList, frame.Piece.GetTextureInfo(), thePos, theSize, frame.Piece.GetRect(), tintColor);
	}

	return false;
}

//
// EQ UI Draw Routines
//

bool SpellGem(const char* strId, const eqlib::CSpellGemWnd* pSpellGem)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	CXSize theSize = pSpellGem->GetClientRect().GetSize();
	CXPoint thePos = window->DC.CursorPos;
	ImGuiID id = window->GetID(strId);

	ImGui::ItemSize(theSize);
	ImRect bb(thePos, thePos + theSize);

	if (!ImGui::ItemAdd(ImRect(thePos, thePos + theSize), id))
		return false;

	ImDrawList* drawList = window->DrawList;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, 0);

	AddSpellGem(drawList, pSpellGem, thePos, hovered);

	return pressed;
}

void AddSpellGem(ImDrawList* drawList,
	const eqlib::CSpellGemWnd* pSpellGem,
	const eqlib::CXPoint& position,
	bool hovered)
{
	CXSize theSize = pSpellGem->GetClientRect().GetSize();
	float scale = static_cast<float>(pSpellGem->Percent) / 100.0f;

	// Scale gem size by scale factor
	theSize = theSize * scale;

	drawList->PushClipRect(position, position + theSize);

	if (pSpellGem->SpellIconIndex < 0 && pSpellGem->CustomIconTexture == nullptr)
	{
		// No gem, just the background.
		if (pSpellGem->DrawTemplate.ptaHolder)
		{
			AddTextureAnimation(drawList, pSpellGem->DrawTemplate.ptaHolder, position, theSize);
		}
	}
	else
	{
		MQColor gemTint = pSpellGem->SpellGemTintArray[pSpellGem->TintIndex];

		// Draw gem background
		CTextureAnimation* pTA = pSpellGem->DrawTemplate.ptaBackground;
		if (pTA)
		{
			if (pSpellGem->bChecked)
			{
				AddTextureAnimation(drawList, pTA, position, theSize, MQColor(255, 255, 255, 255));
			}
			else if (hovered)
			{
				AddTextureAnimation(drawList, pTA, position, theSize, gemTint + MQColor(32, 32, 32, 0));
			}
			else
			{
				AddTextureAnimation(drawList, pTA, position, theSize, gemTint);
			}
		}

		// Draw gem icon
		CTextureAnimation* pTAIcon = pSpellGem->CustomIconTexture ? pSpellGem->CustomIconTexture : pSpellGem->SpellIconTexture;
		if (pTAIcon)
		{
			CXPoint iconPos = {
				position.x + static_cast<int>(pSpellGem->SpellIconOffsetX * scale),
				position.y + static_cast<int>(pSpellGem->SpellIconOffsetY * scale),
			};
			CXSize iconSize = {
				static_cast<int>(pSpellGem->SpellIconWidth * scale),
				static_cast<int>(pSpellGem->SpellIconHeight * scale),
			};

			if (pSpellGem->TintIndex == 0)
			{
				AddTextureAnimation(drawList, pTAIcon, iconPos, iconSize);
			}
			else
			{
				AddTextureAnimation(drawList, pTAIcon, iconPos, iconSize, MQColor(255, 255, 255, pSpellGem->SpellGemAlphaArray[pSpellGem->TintIndex]));
			}
		}

		// Draw highlight
		CTextureAnimation* pTAHighlight = pSpellGem->DrawTemplate.ptaHighlight;
		if (pTAHighlight)
		{
			AddTextureAnimation(drawList, pTAHighlight, position, theSize);
		}
	}

	drawList->PopClipRect();
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
