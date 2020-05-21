/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#include "imgui/ImGuiUtils.h"
#include "imgui/fonts/IconsFontAwesome.h"

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <imgui_internal.h>

namespace mq {

static void DeveloperTools_Initialize();
static void DeveloperTools_Shutdown();
static void DeveloperTools_SetGameState(DWORD gameState);
static void DeveloperTools_UpdateImGui();

static MQModule s_developerToolsModule = {
	"DeveloperTools",              // Name
	true,                          // CanUnload
	DeveloperTools_Initialize,
	DeveloperTools_Shutdown,
	nullptr,
	DeveloperTools_SetGameState,
	DeveloperTools_UpdateImGui,
};
DECLARE_MODULE_INITIALIZER(s_developerToolsModule);

//----------------------------------------------------------------------------

struct PersistedBool
{
	PersistedBool(const std::string& Section, const std::string& Key, bool init = false)
		: m_section(Section)
		, m_key(Key)
		, m_defaultValue(init)
		, m_value(init)
	{
		Load();
	}

	bool& operator=(bool value)
	{
		if (mq::test_and_set(m_value, value))
		{
			m_lastValue = value;
			Save();
		}

		return m_value;
	}

	operator bool& ()
	{
		if (!m_isLoaded)
			Load();
		return m_value;
	}

	operator bool() const
	{
		// lazy load if we haven't done it yet
		if (!m_isLoaded)
			const_cast<PersistedBool*>(this)->Load();
		return m_value;
	}

	bool* get_ptr()
	{
		if (!m_isLoaded)
			Load();
		return &m_value;
	}

	void Save()
	{
		mq::WritePrivateProfileBool(m_section, m_key, m_value, mq::internal_paths::MQini);
		m_isLoaded = true;
	}

	void Load()
	{
		if (!mq::internal_paths::MQini.empty())
		{
			m_value = mq::GetPrivateProfileBool(m_section, m_key, m_defaultValue, mq::internal_paths::MQini);
			m_isLoaded = true;
		}
	}

	void Update()
	{
		if (mq::test_and_set(m_lastValue, m_value))
			Save();
	}

private:
	bool m_value;
	bool m_lastValue;
	bool m_isLoaded = false;
	const bool m_defaultValue;
	std::string m_section;
	std::string m_key;
};

// TODO: Use TList/TLinkNode
class ImGuiWindowBase;
ImGuiWindowBase* s_imguiBaseWindows = nullptr;
ImGuiWindowBase* s_lastImguiBaseWindow = nullptr;

class ImGuiWindowBase
{
public:
	ImGuiWindowBase(const std::string& windowId, const std::string& windowTitle = {})
		: m_open("Developer Tools", windowId.c_str())
		, m_windowId(windowId)
	{
		SetWindowTitle(windowTitle);

		if (!s_lastImguiBaseWindow)
		{
			s_imguiBaseWindows = s_lastImguiBaseWindow = this;
		}
		else
		{
			m_prev = s_lastImguiBaseWindow;
			m_prev->m_next = this;
			s_lastImguiBaseWindow = this;
		}
	}

	virtual ~ImGuiWindowBase()
	{
		// Unlink from the chain
		if (m_next)
			m_next->m_prev = m_prev;
		if (m_prev)
			m_prev->m_next = m_next;
	}

	bool IsOpen() const { return m_open && IsEnabled(); }
	virtual bool IsEnabled() const { return true; }

	void Show()
	{
		m_open = true;
	}

	void Close()
	{
		m_open = false;
	}

	void Toggle()
	{
		m_open = !m_open;
	}

	ImGuiWindowBase* GetNext() { return m_next; }

	virtual void Update()
	{
		if (!IsEnabled())
			return;

		if (m_open)
		{
			if (Begin())
			{
				Draw();
			}
			ImGui::End();
		}

		m_open.Update();
	}

	void SetWindowTitle(std::string_view windowTitle)
	{
		m_windowTitle = fmt::format("{}###{}", windowTitle, m_windowId);
	}

	void SetDefaultSize(const ImVec2& size)
	{
		m_defaultSize = size;
	}

protected:
	// Override this to set some properties before the window is drawn. If this returns false
	// the update is aborted.
	virtual bool Begin()
	{
		ImGui::SetNextWindowSize(m_defaultSize, ImGuiCond_FirstUseEver);
		return ImGui::Begin(m_windowId.c_str(), m_open.get_ptr());
	}

	virtual void Draw() {}

	//----------------------------------------------------------------------------
	std::string m_windowId;                      //
	std::string m_windowTitle;                   // WindowTitle###WindowId
	PersistedBool m_open;

private:
	ImGuiWindowBase* m_next = nullptr;
	ImGuiWindowBase* m_prev = nullptr;
	ImVec2 m_defaultSize;
};

#pragma region Common Tools

bool IsEmptyValue(const char* val)
{
	return val[0] == '('
		&& (strcmp(val, "(empty)")
			|| strcmp(val, "(null)")
			|| strcmp(val, "(none)"));
}

static void ColumnValue(const char* fmt, va_list args)
{
	if (IsEmptyValue(fmt))
	{
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "%s", fmt);
	}
	else if (strcmp(fmt, "%s") == 0)
	{
		const char* str = va_arg(args, const char*);

		if (IsEmptyValue(str))
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), str);
		else
			ImGui::Text("%s", str);
	}
	else
	{
		ImGui::TextV(fmt, args);
	}
}

static void ColumnText(const char* Label, const char* fmt, ...)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);

	ImGui::TableNextRow();
}

static void ColumnTextType(const char* Label, const char* Type, const char* fmt, ...)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);
	ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
}

static bool ColumnCheckBox(const char* Label, bool* value)
{
	bool result = false;
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();
	ImGui::PushID(Label); result = ImGui::Checkbox("", value); ImGui::PopID();
	ImGui::TableNextRow();
	return result;
}

static bool ColumnCheckBox(const char* Label, bool value)
{
	bool result = false;
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();
	bool value2 = value;
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.6f);
	ImGui::PushID(Label); result = ImGui::Checkbox("", &value2); ImGui::PopID();
	ImGui::PopStyleVar();
	ImGui::TableNextRow();
	return result;
}

static bool ColumnCheckBoxFlags(const char* Label, unsigned int* flags, unsigned int flags_value)
{
	bool result = false;
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();
	ImGui::PushID(Label); result = ImGui::CheckboxFlags("", flags, flags_value); ImGui::PopID();
	ImGui::TableNextRow();
	return result;
}

static bool ColumnTreeNode(const char* Label, const char* fmt, ...)
{
	bool result = ImGui::TreeNode(Label); ImGui::TableNextCell();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);

	ImGui::TableNextRow();
	return result;
}

static bool ColumnTreeNodeType(const char* Label, const char* Type, const char* fmt, ...)
{
	bool result = ImGui::TreeNode(Label); ImGui::TableNextCell();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);
	ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
	return result;
}

static bool ColumnTreeNodeType2(const void* Id, const char* Label, const char* Type, const char* fmt, ...)
{
	bool result = ImGui::TreeNode(Id, Label); ImGui::TableNextCell();

	va_list args;
	va_start(args, fmt);
	ColumnValue(fmt, args);
	va_end(args);
	ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), Type);
	ImGui::TableNextRow();
	return result;
}

static bool InputCXRect(const char* label, CXRect& rect)
{
	return ImGui::InputInt4(label, (int*)&rect);
}

inline bool InputCXSize(const char* label, CXSize& size)
{
	return ImGui::InputInt2(label, (int*)&size);
}

inline bool InputCXPoint(const char* label, CXPoint& point)
{
	return ImGui::InputInt2(label, (int*)&point);
}

inline bool InputColorRef(const char* label, COLORREF& color)
{
	ImColor colors{ color };

	if (ImGui::ColorEdit4(label, (float*)&colors))
	{
		color = colors;
		return true;
	}

	return false;
}

inline void ColumnCXStr(const char* Label, const CXStr& str)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	if (str.empty())
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
	else
		ImGui::Text("%s", str.c_str());
	ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXStr");
	ImGui::TableNextRow();
}

inline void ColumnCXSize(const char* Label, const CXSize& size)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	ImGui::Text("{ w=%d, h=%d }", size.cx, size.cy); ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXSize");
	ImGui::TableNextRow();
}

inline void ColumnCXRect(const char* Label, const CXRect& rect)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	ImGui::Text("{ x=%d, y=%d, w=%d, h=%d }", rect.left, rect.top, rect.GetWidth(), rect.GetHeight()); ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXRect");
	ImGui::TableNextRow();
}

inline void ColumnCXPoint(const char* Label, const CXPoint& point)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	ImGui::Text("{ x=%d, y=%d }", point.x, point.y); ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXPoint");
	ImGui::TableNextRow();
}

inline void ColumnColor(const char* Label, const COLORREF& color)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	//ImGui::ColorButton(id, ImGui::ColorConvertU32ToFloat4(color),
	//ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2(0, 0));

	// colors are in BGRA form

	ImGui::PushID(Label);
	ImColor colors(
		(int)((color >> 16) & 0xff),
		(int)((color >> 8) & 0xff),
		(int)(color & 0xff),
		(int)((color >> 24) & 0xff)
	);

	ImGui::ColorEdit4("", (float*)&colors, ImGuiColorEditFlags_NoInputs); ImGui::TableNextCell();
	ImGui::PopID();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "Color");
	ImGui::TableNextRow();
}

//----------------------------------------------------------------------------

inline const char* UIDirectoryToString(enDir dir)
{
	switch (dir)
	{
	case cUIDirectory: return "UI Directory";
	case cUIDirectoryAtlas: return "Altas Directory";
	case cUIDirectoryTexture: return "Texture Directory";
	case cUIDirectoryMaps: return "Maps Directory";
	default: return "Unknown Directory";
	}
}

bool RenderUITextureInfoTexture(const CUITextureInfo& textureInfo, const CXRect& rect = CXRect(0, 0, -1, -1))
{
	if (textureInfo.TextureId == -1)
		return false;

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

	if (!rect.IsAbnormal())
	{
		minUV.x = rect.left / textureSize.x;
		minUV.y = rect.top / textureSize.y;

		maxUV.x = rect.right / textureSize.x;
		maxUV.y = rect.bottom / textureSize.y;

		textureSize.x = (float)rect.GetWidth();
		textureSize.y = (float)rect.GetHeight();
	}

	ImGui::Image((ImTextureID)pEQGBitmap->pD3DTexture, textureSize, minUV, maxUV, ImVec4(1, 1, 1, 1), ImVec4(1, 1, 1, 0.5f));
	return true;
}

bool RenderTexturePiece(const CUITexturePiece& texturePiece, const CXRect& srcRect)
{
	return RenderUITextureInfoTexture(texturePiece.GetTextureInfo(), srcRect);
}

bool RenderTexturePiece(const CUITexturePiece& texturePiece)
{
	return RenderTexturePiece(texturePiece, texturePiece.GetRect());
}

// TODO: Move to a helper for CTextureAnimation that can draw with imgui.
bool RenderTextureAnimation(const CTextureAnimation* pAnim)
{
	if (pAnim->Frames.IsEmpty())
	{
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
			return RenderTexturePiece(frame.Piece, pAnim->CellRect);
		}
	}
	else
	{
		return RenderTexturePiece(frame.Piece);
	}

	return false;
}

void ColumnTextureAnimationPreview(const char* Label, const CTextureAnimation* pAnim)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	if (!pAnim)
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(null)");
	else
	{
		if (!RenderTextureAnimation(pAnim))
		{
			ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(empty)");
		}
	}

	ImGui::TableNextRow();
}

bool ColumnTextureInfoPreview(const char* Label, const CUITextureInfo& textureInfo, const CXRect& rect = CXRect(0, 0, -1, -1))
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	bool result = RenderUITextureInfoTexture(textureInfo, rect);
	ImGui::TableNextRow();
	return result;
}

void DisplayUITextureInfo(const char* Label, const CUITextureInfo& textureInfo)
{
	bool show = ColumnTreeNodeType2((const void*)&textureInfo, Label, "CUITextureInfo", "%s", textureInfo.Name.c_str());
	if (show)
	{
		//ColumnCXStr("Name", textureInfo.Name);
		ColumnTextureInfoPreview("Texture", textureInfo);
		ColumnCXSize("Size", textureInfo.TextureSize);
		ColumnText("Texture Id", "%d", textureInfo.TextureId);
		ColumnText("Valid", "%s", textureInfo.bValid ? "true" : "false");
		ColumnText("Directory", "%s", UIDirectoryToString(textureInfo.Directory));

		ImGui::TreePop();
	}
}

void DisplayUITexturePiece(const char* Label, const CUITexturePiece& texturePiece)
{
	bool show = ColumnTreeNodeType2((const void*)&texturePiece, Label, "CUITexturePiece", "%s", texturePiece.GetTextureInfo().Name.c_str());
	if (show)
	{
		ColumnCXStr("Name", texturePiece.GetTextureInfo().Name);
		DisplayUITextureInfo("TextureInfo", texturePiece.GetTextureInfo());
		ColumnCXRect("Rect", texturePiece.GetRect());
		ColumnCXSize("Size", texturePiece.GetSize());
		ColumnTextureInfoPreview("Preview", texturePiece.GetTextureInfo(), texturePiece.GetRect());

		ImGui::TreePop();
	}
}

void DisplaySTextureAnimationFrame(int frameId, const STextureAnimationFrame& frame, bool showNumber)
{
	char labelText[20];
	if (showNumber)
		sprintf_s(labelText, "Frame %d", frameId + 1);
	else
		strcpy_s(labelText, "Frame");

	bool showFrame = ColumnTreeNodeType2((const void*)&frame, labelText, "STextureAnimationFrame", "");
	if (showFrame)
	{
		DisplayUITexturePiece("TexturePiece", frame.Piece);
		ColumnText("Ticks", "%d", frame.Ticks);
		ColumnCXPoint("Hotspot", frame.Hotspot);

		ImGui::TreePop();
	}
}

void DisplayTextureAnimation(const char* Label, const CTextureAnimation* textureAnim, bool doEmpty = true)
{
	if (!textureAnim)
	{
		if (doEmpty)
			ColumnTextType(Label, "CTextureAnimation*", "(null)");
		return;
	}

	bool show = ColumnTreeNodeType(Label, "CTextureAnimation*", "%s", textureAnim->Name.c_str());
	if (show)
	{
		ColumnTextureAnimationPreview("Texture", textureAnim);
		ColumnCXSize("Size", textureAnim->bGrid ? textureAnim->CellRect.GetSize() : textureAnim->Size);

		if (ColumnTreeNode("Details", ""))
		{
			ColumnCXStr("Name", textureAnim->Name);

			if (textureAnim->Frames.GetLength() > 1)
			{
				bool showFrames = ColumnTreeNodeType("Frames", "STextureAnimationFrame[]", "%d", textureAnim->Frames.GetLength());
				if (showFrames)
				{
					for (int i = 0; i < textureAnim->Frames.GetLength(); ++i)
					{
						const STextureAnimationFrame& frame = textureAnim->Frames[i];

						DisplaySTextureAnimationFrame(i, frame, true);
					}

					ImGui::TreePop();
				}
			}
			else
			{
				const STextureAnimationFrame& frame = textureAnim->Frames[0];

				DisplaySTextureAnimationFrame(0, frame, false);
			}

			ColumnText("Paused", textureAnim->bPaused ? "true" : "false");
			ColumnText("Vertical", textureAnim->bVertical ? "true" : "false");
			ColumnText("Grid", textureAnim->bGrid ? "true" : "false");

			if (textureAnim->bGrid)
			{
				ColumnCXSize("Cell size", CXSize(textureAnim->CellWidth, textureAnim->CellHeight));
				ColumnCXRect("Cell rect", textureAnim->CellRect);
				ColumnText("Current cell", "%d", textureAnim->CurCell);
			}

			if (textureAnim->ZeroFrame != 0)
			{
				ColumnText("Zero frame", "%d", textureAnim->ZeroFrame);
			}

			ColumnText("Cycle animation", textureAnim->bCycle ? "true" : "false");
			ColumnText("Total ticks", "%d", textureAnim->TotalTicks);
			ColumnText("Start ticks", "%d", textureAnim->StartTicks);

			ImGui::TreePop();
		}

		ImGui::TreePop();
	}
}

void DisplayTAFrameDraw(const char* Label, const CTAFrameDraw& frameDraw)
{
	bool show = ColumnTreeNodeType2((const void*)&frameDraw, Label, "CTAFrameDraw", "%s", frameDraw.GetName().c_str());
	if (show)
	{
		ColumnCXStr("Name", frameDraw.GetName());
		ColumnCXSize("Frame size", frameDraw.GetFrameSize());

		for (int i = 0; i < CTAFrameDraw::FrameDraw_Max; ++i)
		{
			CTextureAnimation* anim = frameDraw.GetAnimation(static_cast<CTAFrameDraw::EFrameDrawPiece>(i));
			if (!anim)
				continue;

			DisplayTextureAnimation(
				CTAFrameDraw::FrameDrawPieceToString(static_cast<CTAFrameDraw::EFrameDrawPiece>(i)),
				anim);
		}

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CButtonDrawTemplate& drawTemplate)
{

	bool show = ColumnTreeNodeType2((const void*)&drawTemplate, label, "CButtonDrawTemplate", "%s", drawTemplate.strName.c_str());
	if (show)
	{
		ColumnCXStr("Name", drawTemplate.strName);
		DisplayTextureAnimation("Normal", drawTemplate.ptaNormal, false);
		DisplayTextureAnimation("Pressed", drawTemplate.ptaPressed, false);
		DisplayTextureAnimation("Hover", drawTemplate.ptaFlyby, false);
		DisplayTextureAnimation("Disabled", drawTemplate.ptaDisabled, false);
		DisplayTextureAnimation("Pressed hover", drawTemplate.ptaPressedFlyby, false);
		DisplayTextureAnimation("Pressed disabled", drawTemplate.ptaPressedDisabled, false);
		DisplayTextureAnimation("Normal decal", drawTemplate.ptaNormalDecal, false);
		DisplayTextureAnimation("Pressed decal", drawTemplate.ptaPressedDecal, false);
		DisplayTextureAnimation("Hover decal", drawTemplate.ptaFlybyDecal, false);
		DisplayTextureAnimation("Disabled decal", drawTemplate.ptaDisabledDecal, false);
		DisplayTextureAnimation("Pressed hover decal", drawTemplate.ptaPressedFlybyDecal, false);
		DisplayTextureAnimation("Pressed disabled decal", drawTemplate.ptaPressedDisabledDecal, false);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CSpellGemDrawTemplate& drawTemplate)
{
	if (ColumnTreeNodeType2((const void*)&drawTemplate, label, "CSpellGemDrawTemplate", "%s", drawTemplate.strName.c_str()))
	{
		ColumnCXStr("Name", drawTemplate.strName);

		DisplayTextureAnimation("Background", drawTemplate.ptaBackground);
		DisplayTextureAnimation("Holder", drawTemplate.ptaHolder);
		DisplayTextureAnimation("Highlight", drawTemplate.ptaHighlight);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CScrollbarTemplate& drawTemplate)
{
	bool show = ColumnTreeNodeType2((const void*)&drawTemplate, label, "CScrollbarTemplate", "%s", drawTemplate.strName.c_str());
	if (show)
	{
		ColumnCXStr("Name", drawTemplate.strName);
		DisplayDrawTemplate("Up Button", drawTemplate.bdtUp);
		DisplayDrawTemplate("Down Button", drawTemplate.bdtDown);
		DisplayTAFrameDraw("Thumb", drawTemplate.frameThumb);
		DisplayUITextureInfo("Middle", drawTemplate.tiMiddle);
		ColumnColor("Middle tint", drawTemplate.colorMiddleTint);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CXWndDrawTemplate* drawTemplate)
{
	if (!drawTemplate)
	{
		ColumnTextType(label, "CXWndDrawTemplate*", "(null)");
		return;
	}

	bool show = ColumnTreeNodeType2(drawTemplate, label, "CXWndDrawTemplate*", "%s", drawTemplate->strName.c_str());
	if (show)
	{
		ColumnCXStr("Name", drawTemplate->strName);
		DisplayUITextureInfo("Background texture", drawTemplate->tiBackground);
		ColumnText("Background type",
			XWndBackgroundDrawTypeToString(static_cast<XWndBackgroundDrawType>(drawTemplate->nBackgroundDrawType)));
		DisplayDrawTemplate("Vertical scroll bar", drawTemplate->sbtVScroll);
		DisplayDrawTemplate("Horizontal scroll bar", drawTemplate->sbtHScroll);
		DisplayDrawTemplate("Close box", drawTemplate->bdtCloseBox);
		DisplayDrawTemplate("Help box", drawTemplate->bdtQMarkBox);
		DisplayDrawTemplate("Minimize box", drawTemplate->bdtMinimizeBox);
		DisplayDrawTemplate("Maximize box", drawTemplate->bdtMaximizeBox);
		DisplayDrawTemplate("Tile box", drawTemplate->bdtTileBox);
		DisplayTAFrameDraw("Border", drawTemplate->frameBorder);
		DisplayTAFrameDraw("Title bar", drawTemplate->frameTitlebar);

		ImGui::TreePop();
	}
}

void DisplayTextObject(const char* label, CTextObjectInterface* pTextObjectInterface)
{
	if (!pTextObjectInterface)
	{
		ColumnTextType(label, "CTextObject*", "(null)");
		return;
	}

	CTextObjectBase* pTextObject = static_cast<CTextObjectBase*>(pTextObjectInterface);

	if (ColumnTreeNodeType2(pTextObject, label, "CTextObject*", "%s", pTextObject->GetText().c_str()))
	{
		ColumnCXStr("Text", pTextObject->GetText());
		ColumnColor("Color", pTextObject->GetColor());

		ImGui::TreePop();
	}
}

void ColumnWindow(const char* Label, CXWnd* window)
{
	ImGui::TreeAdvanceToLabelPos(); ImGui::Text(Label); ImGui::TableNextCell();

	if (!window)
		ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "(null)");
	else
	{
		if (ImGui::Button("view"))
		{
			DeveloperTools_ShowWindowInspector(window);
		}
		ImGui::SameLine();

		// TODO: function for deciding on a name.
		ImGui::Text("%s", window->GetXMLName().c_str());
	}
	ImGui::TableNextCell();

	ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "CXWnd");
	ImGui::TableNextRow();
}

//----------------------------------------------------------------------------

void DisplayDynamicTemplateExpand(const char* label, const CScreenPieceTemplate* pTemplate);

void DisplayLayoutStrategyTemplate(const CLayoutStrategyTemplate* pTemplate)
{
	ColumnCXStr("Name", pTemplate->strName);
	ColumnText("Padding", "%d", pTemplate->nPadding);
	ColumnText("Type", "%d", pTemplate->nType);
	ColumnCheckBox("Resize Horizontal", pTemplate->bResizeHorizontal);
	ColumnCheckBox("Resize Vertical", pTemplate->bResizeVertical);
}

void DisplayListboxColumnTemplate(const CListboxColumnTemplate* pTemplate)
{
}

void DisplayScreenPieceTemplate(const CScreenPieceTemplate* pTemplate)
{
	uint32_t uParamObjectId = pTemplate->uParamObjectId;

	if (CXMLData* pXMLData = pSidlMgr->GetParamManager()->GetXMLData(uParamObjectId))
	{
		// Type
		ColumnText("Type", "%s (%d)", pXMLData->TypeName.c_str(), pXMLData->Type);
	}

	ColumnCXStr("Name", pTemplate->strName);
	ColumnText("Object Id", "%d", pTemplate->uParamObjectId);
	ColumnCXStr("Screen ID", pTemplate->strScreenId);
	// TODO: RuntimeTypes
	// TODO: Font
	// TODO: RelativePosition
	// TODO: AutoStretchVertical
	// TODO: AutoStretchHorizontal
	// TODO: TopAnchorToTop
	// TODO: BottomAnchorToTop
	// TODO: LeftAnchorToLeft
	// TODO: RightAnchorToRight
	// TODO: TopOffset
	// TODO: BottomOffset
	// TODO: LeftOffset
	// TODO: RightOffset
	// TODO: MinVSize
	// TODO: MinHSize
	// TODO: MaxVSize
	// TODO: MaxHSize
	// TODO: UseInLayoutHorizontal
	// TODO: UseInLayoutVertical

	if (ColumnTreeNode("Colors", ""))
	{
		ColumnCXRect("Rect", pTemplate->rect);
		ColumnCXStr("Text", pTemplate->strText);
		ColumnColor("Text Color", pTemplate->colorText);
		ColumnColor("Disabled Color", pTemplate->colorDisabled);
		ColumnColor("Enabled Color", pTemplate->colorEnabled);
		ColumnColor("Background Texture Tint", pTemplate->colorBackgroundTextureTint);
		ColumnColor("Disabled Background Texture Tint", pTemplate->colorDisabledBackgroundTextureTint);

		ImGui::TreePop();
	}
}

void DisplayStaticAnimationTemplate(const CStaticAnimationTemplate* pTemplate)
{
	DisplayScreenPieceTemplate(pTemplate);
	DisplayTextureAnimation("Texture", pTemplate->ptaTextureAnimation, true);
}

void DisplayStaticScreenPieceTemplate(const CStaticScreenPieceTemplate* pTemplate)
{
	DisplayScreenPieceTemplate(pTemplate);
	ColumnCheckBox("Auto Draw", pTemplate->bAutoDraw);
}

void DisplayStaticTintedBlendAnimationTemplate(const CStaticTintedBlendAnimationTemplate* pTemplate)
{
	DisplayStaticScreenPieceTemplate(pTemplate);

	DisplayTextureAnimation("Layer 1", pTemplate->ptaLayerOneTexture);
	DisplayTextureAnimation("Layer 2", pTemplate->ptaLayerTwoTexture);
	ColumnColor("Layer 1 Tint", pTemplate->colorLayerOneTint);
	ColumnColor("Layer 2 Tint", pTemplate->colorLayerTwoTint);
}

void DisplayControlTemplate(const CControlTemplate* pTemplate)
{
	DisplayScreenPieceTemplate(pTemplate);

	// TODO: StyleBits
	// TODO: SizableMask
	ColumnCheckBox("Escapable", pTemplate->bEscapable);
	ColumnCXStr("Tooltip", pTemplate->strTooltip);
	DisplayDrawTemplate("Draw Template", pTemplate->pDrawTemplate);
	ColumnCXStr("Controller", pTemplate->strController);

	if (pTemplate->pLayoutStrategyTemplate)
	{
		if (ColumnTreeNodeType("Layout Strategy", "CLayoutStrategyTemplate*", "%s",
			pTemplate->pLayoutStrategyTemplate->strName.c_str()))
		{
			DisplayLayoutStrategyTemplate(pTemplate->pLayoutStrategyTemplate);

			ImGui::TreePop();
		}
	}
	else
	{
		ColumnTextType("Layout Strategy", "CLayoutStrategyTemplate*", "(null)");
	}
}

void DisplayLayoutBoxTemplate(const CLayoutBoxTemplate* pTemplate)
{
	DisplayControlTemplate(pTemplate);
}

const char* UITypeToScreenPieceTemplateType(UIType type)
{
	switch (type)
	{
	case UI_LayoutStrategy: return "CLayoutStrategyTemplate*";
	case UI_LayoutVertical: return "CLayoutVerticalTemplate*";
	case UI_LayoutHorizontal: return "CLayoutHorizontalTemplate*";
	case UI_StaticScreenPiece: return "CStaticScreenPieceTemplate*";
	case UI_StaticAnimation: return "CStaticAnimationTemplate*";
	case UI_StaticText: return "CStaticTextTemplate*";
	case UI_StaticFrame: return "CStaticFrameTemplate*";
	case UI_StaticHeader: return "CStaticHeaderTemplate*";
	case UI_StaticTintedBlendAnimation: return "CStaticTintedBlendAnimationTemplate*";
	case UI_Control: return "CControlTemplate*";
	case UI_ListboxColumn: return "CListboxColumnTemplate*";
	case UI_Listbox: return "CListboxTemplate*";
	case UI_EditBox: return "CEditboxTemplate*";
	case UI_Slider: return "CSliderTemplate*";
	case UI_Label: return "CLabelTemplate*";
	case UI_STMLBox: return "CSTMLboxTemplate*";
	case UI_TreeView: return "CTreeViewTemplate*";
	case UI_Combobox: return "CComboboxTemplate*";
	case UI_Button: return "CButtonTemplate*";
	case UI_Gauge: return "CGaugeTemplate*";
	case UI_SpellGem: return "CSpellGemTemplate*";
	case UI_InvSlot: return "CInvSlotTemplate*";
	case UI_Page: return "CPageTemplate*";
	case UI_TabBox: return "CTabBoxTemplate*";
	case UI_LayoutBox: return "CLayoutBoxTemplate*";
	case UI_HorizontalLayoutBox: return "CHorizontalLayoutBoxTemplate*";
	case UI_VerticalLayoutBox: return "CVerticalLayoutBoxTemplate*";
	case UI_TileLayoutBox: return "CTileLayoutBoxTemplate*";
	case UI_Screen: return "CScreenTemplate*";
	case UI_HtmlComponent: return "CHtmlComponentTemplate*";
	case UI_TemplateContainer: return "CTemplateContainerTemplate*";
	case UI_HotButton: return "CHotButtonTemplate*";
	default:
		return "(other template)";
	}
}

void DisplayScreenTemplate(const CScreenTemplate* pTemplate);

// Looks up the type and casts it to the appropriate template type.
void DisplayDynamicTemplate(CXMLData* pXMLData, const CScreenPieceTemplate* pTemplate)
{
	switch (pXMLData->Type)
	{
	case UI_Screen:
		DisplayScreenTemplate(static_cast<const CScreenTemplate*>(pTemplate));
		break;

	case UI_Control:
	case UI_HotButton:
	case UI_Listbox:
	case UI_EditBox:
	case UI_Slider:
	case UI_Label:
	case UI_STMLBox:
	case UI_TreeView:
	case UI_Combobox:
	case UI_Button:
	case UI_Gauge:
	case UI_SpellGem:
	case UI_InvSlot:
	case UI_Page:
	case UI_TabBox:
	case UI_LayoutBox:
	case UI_HorizontalLayoutBox:
	case UI_VerticalLayoutBox:
	case UI_TileLayoutBox:
	case UI_HtmlComponent:
	case UI_TemplateContainer:
		DisplayControlTemplate(static_cast<const CControlTemplate*>(pTemplate));
		break;

	case UI_ListboxColumn:
		break; // not a screen piece

	case UI_StaticAnimation:
		DisplayStaticAnimationTemplate(static_cast<const CStaticAnimationTemplate*>(pTemplate));
		break;

	case UI_StaticScreenPiece:
		DisplayStaticScreenPieceTemplate(static_cast<const CStaticScreenPieceTemplate*>(pTemplate));
		break;

	case UI_StaticTintedBlendAnimation:
		DisplayStaticTintedBlendAnimationTemplate(static_cast<const CStaticTintedBlendAnimationTemplate*>(pTemplate));
		break;

	case UI_StaticText:
	case UI_StaticFrame:
	case UI_StaticHeader:
	default:
		DisplayScreenPieceTemplate(pTemplate);
	}
}

void DisplayDynamicTemplateExpand(const char* label, const CScreenPieceTemplate* pTemplate)
{
	if (!pTemplate)
	{
		ColumnTextType(label, "CScreenPieceTemplate*", "(null)");
		return;
	}

	uint32_t uParamObjectId = pTemplate->uParamObjectId;
	if (CXMLData* pXMLData = pSidlMgr->GetParamManager()->GetXMLData(uParamObjectId))
	{
		if (ColumnTreeNodeType(label, UITypeToScreenPieceTemplateType(pXMLData->Type), "%s", pTemplate->strName.c_str()))
		{
			DisplayDynamicTemplate(pXMLData, pTemplate);

			ImGui::TreePop();
		}
	}
	else
	{
		if (ColumnTreeNodeType(label, "CScreenPieceTemplate*", "%s", pTemplate->strName.c_str()))
		{
			DisplayScreenPieceTemplate(pTemplate);

			ImGui::TreePop();
		}
	}
}

void DisplayScreenTemplate(const CScreenTemplate* pTemplate)
{
	DisplayControlTemplate(pTemplate);

	// TODO: Pieces
	int index = 0;
	for (CScreenPieceTemplate* pChildTemplate : pTemplate->Pieces)
	{
		char text[32];
		sprintf_s(text, "Piece[%d]", index++);

		DisplayDynamicTemplateExpand(text, pChildTemplate);
	}
}

template <typename T>
void DisplayTemplate(const char* label, const char* type, const T* pTemplate)
{
	if (!pTemplate)
	{
		ColumnTextType(label, type, "(null)");
		return;
	}

	if (ColumnTreeNodeType2(pTemplate, label, type, "%s", pTemplate->strName.c_str()))
	{
		DisplayScreenTemplate(pTemplate);

		ImGui::TreePop();
	}
}


#pragma endregion

#pragma region Property Viewer

struct WindowPropertiesTable
{
	inline static ImU32 s_propertyColors[] = {
		(ImU32)ImColor(4, 32, 39, 120),
		(ImU32)ImColor(39, 32, 4, 120),
		(ImU32)ImColor(70, 23, 10, 80),
		(ImU32)ImColor(42, 20, 68, 80),
		(ImU32)ImColor(66, 68, 20, 80),
		(ImU32)ImColor(68, 20, 67, 80),
	};

	int m_currentColor = 0;
	bool m_started = false;

public:
	void Reset()
	{
		m_currentColor = 0;
		m_started = false;
	}

	bool Begin()
	{
		ImGuiTableFlags tableFlags =
			ImGuiTableFlags_ScrollFreezeTopRow
			| ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersV
			| ImGuiTableFlags_BordersHOuter
			| ImGuiTableFlags_BordersHInner
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_RowBg
			;

		// Set up a table with three columns: Name, Value, Type
		if (!ImGui::BeginTable("##WindowDetailsTable", 3, tableFlags) && !m_started)
			return false;

		if (!m_started)
		{
			ImGui::TableSetupColumn("Property", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 75);
			ImGui::TableAutoHeaders();
		}

		m_started = true;
		ImGui::TableNextRow();

		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4);
		return true;
	}

	void End()
	{
		if (m_currentColor != 0)
			ImGui::PopStyleColor(2);

		ImGui::PopStyleVar();
		ImGui::EndTable();
	}

	bool StartNewSection(const char* sectionName, bool open)
	{
		if (m_currentColor != 0)
			ImGui::PopStyleColor(2);

		// black background for heading.
		ImU32 black = IM_COL32_BLACK;
		ImGui::PushStyleColor(ImGuiCol_TableRowBg, (ImU32)black);
		ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt, (ImU32)black);

		bool expand = ImGui::CollapsingHeader(sectionName, open ? ImGuiTreeNodeFlags_DefaultOpen : 0);
		ImGui::PopStyleColor(2);
		ImGui::TableNextRow();

		ImColor rowColor = s_propertyColors[m_currentColor++];
		if (m_currentColor >= (int)lengthof(s_propertyColors))
			m_currentColor = 0;

		ImGui::PushStyleColor(ImGuiCol_TableRowBg, (ImU32)rowColor);
		ImGui::PushStyleColor(ImGuiCol_TableRowBgAlt, (ImU32)rowColor);

		return expand;
	}
};

class ImGuiWindowPropertyViewer
{
	CXWnd* m_window = nullptr;
	std::string m_windowDisplayName;
	std::string m_viewerTitle;

	WindowPropertiesTable m_table;
	int m_instanceId = 0;
	bool m_needDock = true;
	bool m_needFocus = false;

public:
	ImGuiWindowPropertyViewer(int instanceId, CXWnd* pWnd = nullptr)
		: m_instanceId(instanceId)
	{
		SetWindow(pWnd);
	}

	void SetNeedDock(bool need) { m_needDock = need; }
	bool GetNeedDock() const { return m_needDock; }

	void SetNeedFocus(bool need) { m_needFocus = need; }

	int GetInstanceId() const { return m_instanceId; }
	const char* GetWindowId() const { return m_viewerTitle.c_str(); }

	void SetWindow(CXWnd* pWindow)
	{
		if (!test_and_set(m_window, pWindow))
			return;

		m_needFocus = true;

		if (m_window)
		{
			m_windowDisplayName = m_window->GetXMLName();

			// TODO: Might be empty string for dynamic windows.
		}
		else
		{
			m_windowDisplayName = "(none)";
		}

		if (m_instanceId == 1)
		{
			m_viewerTitle = fmt::format("Selected: {}###WindowPropertyViewer{}", m_windowDisplayName, m_instanceId);
		}
		else
		{
			m_viewerTitle = fmt::format("Wnd: {}###WindowPropertyViewer{}", m_windowDisplayName, m_instanceId);
		}
	}

	CXWnd* GetWindow() const { return m_window; }
	const char* GetWindowName() const { return m_windowDisplayName.c_str(); }

	bool Draw()
	{
		if (m_needFocus)
		{
			ImGui::SetNextWindowFocus();
			m_needFocus = false;
		}

		bool open = true;

		ImGui::SetNextWindowSize(ImVec2(480, 640), ImGuiCond_FirstUseEver);
		if (ImGui::Begin(m_viewerTitle.c_str(), &open))
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 9);

			if (!m_window)
			{
				ImGui::Text("Select a window to see details");
				return open;
			}

			DisplayPropertiesPanel();
		}

		ImGui::End(); // Begin properties
		return open;
	}

	void DisplayPropertiesPanel()
	{
		if (!m_window)
			return;

		m_table.Reset();
		if (!m_table.Begin())
			return;

		switch (m_window->GetType())
		{
		case UI_Screen:
			DisplayCSidlScreenWndProperties(static_cast<CSidlScreenWnd*>(m_window));
			break;

		case UI_Button:
			DisplayCButtonWndProperties(static_cast<CButtonWnd*>(m_window));
			break;

		case UI_SpellGem:
			DisplayCSpellGemWndProperties(static_cast<CSpellGemWnd*>(m_window));
			break;

		case UI_Label:
			// All labels with UI_Label were created by XML. they are CLabels.
			// Any other label with the WRT_LABEL type are only CLabelWnds.
			// Unless we are in login, then its all CLabelWnd
			if (gGameState == GAMESTATE_PRECHARSELECT)
				DisplayCLabelWndProperties(static_cast<CLabelWnd*>(m_window));
			else
				DisplayCLabelProperties(static_cast<CLabel*>(m_window));
			break;

		case UI_Gauge:
			DisplayCGaugeWndProperties(static_cast<CGaugeWnd*>(m_window));
			break;

		case UI_Listbox:
		case UI_Unknown:
		default:
			if (m_window->IsType(WRT_SIDLSCREENWND))
			{
				DisplayCSidlScreenWndProperties(static_cast<CSidlScreenWnd*>(m_window));
				break;
			}

			// Dynamic types have no XML type. So we use dynamic type to figure out what they are. Do these
			// in the correct order so we don't lose data!
			if (m_window->IsType(WRT_BUTTON))
			{
				DisplayCButtonWndProperties(static_cast<CButtonWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_LABEL))
			{
				DisplayCLabelWndProperties(static_cast<CLabelWnd*>(m_window));
				break;
			}

			if (m_window->IsType(WRT_LISTWND))
			{
				DisplayCListWndProperties(static_cast<CListWnd*>(m_window));
				break;
			}

			//WRT_LISTWND,
			//WRT_EDITWND,
			//WRT_TREEWND,
			//WRT_PAGEWND,
			//WRT_TABWND,
			//WRT_HTMLWND,
			//WRT_HOTKEYWND,
			//WRT_EDITHOTKEYWND,
			//WRT_RANGESLIDERWND,
			//WRT_STMLWND,
			//WRT_BROWSERWND,
			//WRT_MODALMESSAGEWND,
			//WRT_CHECKBOXWND,
			//WRT_SLIDERWND,
			//WRT_LABEL,
			//WRT_GAUGE,
			//WRT_COMBOBOX,
			//WRT_CHATWND,
			//WRT_HELPWND,

			//WRT_WND

			if (m_window->IsType(WRT_WND))
			{
				DisplayCXWndProperties(m_window);
				break;
			}


			break;
		}

		m_table.End();
	}

	bool BeginColorSection(const char* properties, bool open)
	{
		return m_table.StartNewSection(properties, open);
	}

	void DisplayCXMLDataProperties(CXWnd* pWnd,bool open = true)
	{
		CXMLData* pXMLData = pWnd->GetXMLData();
		if (!pXMLData) return;

		if (BeginColorSection("XML Properties", open))
		{
			// Type
			ColumnText("Type", "%s (%d)", pXMLData->TypeName.c_str(), pXMLData->Type);

			if (!pXMLData->ScreenID.empty())
			{
				// ScreenID
				ColumnText("Screen ID", "%s", pXMLData->ScreenID.c_str());
			}

			if (!pXMLData->Name.empty() && pXMLData->Name != pXMLData->ScreenID)
			{
				// Name
				ColumnText("Name", "%s", pXMLData->Name.c_str());
			}

			if (pSidlMgr)
			{
				if (CScreenPieceTemplate* pTemplate = pSidlMgr->FindScreenPieceTemplate(pWnd->GetXMLIndex()))
				{
					DisplayDynamicTemplateExpand("Template", pTemplate);
				}
			}
		}
	}

	void DisplayCXWndProperties(CXWnd* pWnd, bool open = true)
	{
		DisplayCXMLDataProperties(pWnd, open);

		// Add CXWnd specific details here
		if (BeginColorSection("CXWnd Properties", open))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);
			ColumnCXRect("Position", pWnd->Location);
			ColumnCXRect("Client rect", pWnd->ClientRect);
			ColumnCXStr("Text", pWnd->WindowText);
			ColumnCXStr("Tooltip", pWnd->Tooltip);
			ColumnWindow("Parent", pWnd->ParentWindow);

			// Style
			if (ColumnTreeNode("Style", "0x%08x", pWnd->WindowStyle))
			{
				ColumnCheckBoxFlags("Vertical Scroll", &pWnd->WindowStyle, CWS_VSCROLL);
				ColumnCheckBoxFlags("Horizontal Scroll", &pWnd->WindowStyle, CWS_HSCROLL);
				ColumnCheckBoxFlags("Title Bar", &pWnd->WindowStyle, CWS_TITLE);
				ColumnCheckBoxFlags("Close Box", &pWnd->WindowStyle, CWS_CLOSE);
				ColumnCheckBoxFlags("Tile Box", &pWnd->WindowStyle, CWS_TILEBOX);
				ColumnCheckBoxFlags("Minimize Box", &pWnd->WindowStyle, CWS_MINIMIZE);
				ColumnCheckBoxFlags("Border", &pWnd->WindowStyle, CWS_BORDER);
				ColumnCheckBoxFlags("Relative Rect", &pWnd->WindowStyle, CWS_RELATIVERECT);
				ColumnCheckBoxFlags("Vertical Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCHV);
				ColumnCheckBoxFlags("Horizontal Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCH);
				ColumnCheckBoxFlags("Resizable", &pWnd->WindowStyle, CWS_RESIZEALL);
				ColumnCheckBoxFlags("Transparent", &pWnd->WindowStyle, CWS_TRANSPARENT);
				ColumnCheckBoxFlags("Use My Alpha", &pWnd->WindowStyle, CWS_USEMYALPHA);
				ColumnCheckBoxFlags("Docking Enabled", &pWnd->WindowStyle, CWS_DOCKING);
				ColumnCheckBoxFlags("Immediate Tooltip", &pWnd->WindowStyle, CWS_TOOLTIP_NODELAY);
				ColumnCheckBoxFlags("Frame", &pWnd->WindowStyle, CWS_FRAMEWND);
				ColumnCheckBoxFlags("No Hit Test", &pWnd->WindowStyle, CWS_NOHITTEST);
				ColumnCheckBoxFlags("QMark Box", &pWnd->WindowStyle, CWS_QMARK);
				ColumnCheckBoxFlags("Disable Move", &pWnd->WindowStyle, CWS_NOMOVABLE);
				ColumnCheckBoxFlags("Maximize Box", &pWnd->WindowStyle, CWS_MAXIMIZE);
				ColumnCheckBoxFlags("Vertical Auto Scroll", &pWnd->WindowStyle, CWS_AUTOVSCROLL);
				ColumnCheckBoxFlags("Horizontal Auto Scroll", &pWnd->WindowStyle, CWS_AUTOHSCROLL);
				ColumnCheckBoxFlags("Client Movable", &pWnd->WindowStyle, CWS_CLIENTMOVABLE);
				ColumnCheckBoxFlags("Transparent Control", &pWnd->WindowStyle, CWS_TRANSPARENTCONTROL);

				ImGui::TreePop();
			}

			ColumnCheckBox("Visible", &pWnd->dShow);
			ColumnCheckBox("Enabled", &pWnd->Enabled);

			if (ColumnTreeNode("Details", ""))
			{
				DisplayDynamicTemplateExpand("TitlePiece 1", pWnd->TitlePiece);
				DisplayDynamicTemplateExpand("TitlePiece 2", pWnd->TitlePiece2);
				DisplayTextObject("Text object", pWnd->pTextObject);
				DisplayTextObject("Tooltip text object", pWnd->pTipTextObject);
				ColumnText("Z layer", "%d", pWnd->ZLayer);

				DisplayTextureAnimation("Icon", static_cast<CTextureAnimation*>(pWnd->IconTextureAnim));
				ColumnCXRect("Icon rect", pWnd->IconRect);

				ColumnCheckBox("Minimized", &pWnd->Minimized);
				ColumnCheckBox("Maximized", &pWnd->bMaximized);
				ColumnCheckBox("Maximizable", &pWnd->bMaximizable);
				ColumnCheckBox("Tiled", &pWnd->bTiled);
				ColumnCheckBox("Action", &pWnd->bAction);
				ColumnCheckBox("Bring to top when clicked", &pWnd->bBringToTopWhenClicked);
				ColumnCheckBox("Mouse over", &pWnd->MouseOver);

				// Background
				ColumnText("Background type", XWndBackgroundTypeToString(static_cast<XWndBackgroundType>(pWnd->BGType)));
				ColumnText("Background draw type", XWndBackgroundDrawTypeToString(static_cast<XWndBackgroundDrawType>(pWnd->BackgroundDrawType)));
				ColumnColor("Normal color", pWnd->CRNormal);
				ColumnColor("Background color", pWnd->BGColor);
				ColumnColor("Disabled background color", pWnd->DisabledBackground);

				ColumnCXStr("XML Tooltip", pWnd->XMLToolTip);

				// size
				ColumnCXSize("Min size", pWnd->MinClientSize);
				ColumnCXSize("Max size", pWnd->MaxClientSize);

				// escape-to-close
				ColumnCheckBox("Escapable", &pWnd->CloseOnESC);
				ColumnCheckBox("Escapable locked", &pWnd->bEscapableLocked);

				ColumnText("Horizontal scroll", "{ pos=%d, max=%d }", pWnd->HScrollPos, pWnd->HScrollMax);
				ColumnText("Vertical scroll", "{ pos=%d, max=%d }", pWnd->VScrollPos, pWnd->VScrollMax);

				ColumnCheckBox("Use in horizontal layout", &pWnd->bUseInLayoutHorizontal);
				ColumnCheckBox("Use in vertical layout", &pWnd->bUseInLayoutVertical);
				ColumnText("Anchors", "{ top=%d, right=%d, bottom=%d, left=%d }", pWnd->bTopAnchoredToTop, pWnd->bRightAnchoredToLeft, pWnd->bBottomAnchoredToTop, pWnd->bLeftAnchoredToLeft);
				ColumnText("Offsets", "{ top=%d, right=%d, bottom=%d, left=%d", pWnd->TopOffset, pWnd->RightOffset, pWnd->BottomOffset, pWnd->LeftOffset);

				// Alpha
				ColumnCheckBox("Fade enabled", &pWnd->Fades);
				ColumnText("Current fade alpha", "%d", pWnd->FadeAlpha);
				ColumnText("Current max alpha", "%d", pWnd->Alpha);

				// Mouse over / fading stuff
				ColumnCheckBox("Faded", &pWnd->Faded);
				ColumnText("Last time mouse over", "%d", pWnd->LastTimeMouseOver);
				ColumnText("Fade delay", "%d", pWnd->FadeDelay);
				ColumnText("Fade duration", "%d", pWnd->FadeDuration);
				ColumnText("Fade to alpha", "%d", pWnd->FadeToAlpha);

				// Transition effects
				if (ColumnTreeNode("Transition Properties", ""))
				{
					ColumnText("Start alpha", "%d", pWnd->StartAlpha);
					ColumnText("Target alpha", "%d", pWnd->TargetAlpha);
					ColumnText("Transition start tick", "%d", pWnd->TransitionStartTick);
					ColumnText("Transition duration", "%d", pWnd->TransitionDuration);
					ColumnCheckBox("Is transitioning", &pWnd->bIsTransitioning);
					ColumnText("Transition", "%d", pWnd->Transition);
					ColumnCXRect("Transition rect", pWnd->TransitionRect);

					ImGui::TreePop();
				}

				if (ColumnTreeNode("Blink Properties", ""))
				{
					ColumnText("Blink fade frequency", "%d", pWnd->BlinkFadeFreq);
					ColumnText("Last blink fade refresh time", "%d", pWnd->LastBlinkFadeRefreshTime);
					ColumnText("Blink fade duration", "%d", pWnd->BlinkFadeDuration);
					ColumnText("Blink fade start time", "%d", pWnd->BlinkFadeStartTime);
					ColumnText("Blink state", "%d", pWnd->BlinkState);
					ColumnText("Blink start timer", "%d", pWnd->BlinkStartTimer);
					ColumnText("Blink duration", "%d", pWnd->BlinkDuration);

					ImGui::TreePop();
				}

				ColumnText("Valid", pWnd->ValidCXWnd ? "true" : "false");
				ColumnCheckBox("Unlockable", &pWnd->Unlockable);
				ColumnCheckBox("Keep on screen", &pWnd->bKeepOnScreen);
				ColumnCheckBox("Locked", &pWnd->Locked);
				ColumnCheckBox("Clip to parent", &pWnd->bClipToParent);
				ColumnCheckBox("Clickable", &pWnd->Clickable);
				ColumnCheckBox("Click through", &pWnd->bClickThrough);
				ColumnCheckBox("Show click through menu item", &pWnd->bShowClickThroughMenuItem);
				ColumnCheckBox("Active", &pWnd->bActive);

				//ColumnText("Resizable mask", "0x%08x", pWnd->bResizableMask);
				//ColumnCheckBox("Border", &pWnd->bBorder);
				//ColumnCheckBox("Border 2", &pWnd->bBorder2);
				//ColumnCheckBox("Top anchored to top", &pWnd->bTopAnchoredToTop);
				//ColumnCheckBox("Right anchored to left", &pWnd->bRightAnchoredToLeft);
				//ColumnCheckBox("Bottom anchored to top", &pWnd->bBottomAnchoredToTop);
				//ColumnCheckBox("Left anchored to left", &pWnd->bLeftAnchoredToLeft);
				//ColumnText("Top offset", "%d", pWnd->TopOffset);
				//ColumnText("Right offset", "%d", pWnd->RightOffset);
				//ColumnText("Left offset", "%d", pWnd->LeftOffset);
				//ColumnText("Bottom offset", "%d", pWnd->BottomOffset);
				//ColumnText("Parent/Context Menu array index", "%d", pWnd->ParentAndContextMenuArrayIndex);
				//ColumnCheckBox("Click through menu item", &pWnd->bClickThroughMenuItemStatus);
				//ColumnText("Fully clipped", pWnd->bFullyScreenClipped ? "true" : "false");
				//ColumnCheckBox("Needs saving", &pWnd->bNeedsSaving);
				//ColumnCheckBox("Is parent/context menu window", &pWnd->bIsParentOrContextMenuWindow);
				//ColumnText("Data", "%lld", pWnd->Data);
				//ColumnCXStr("DataStr", pWnd->DataStr);
				//ColumnCXRect("Clip rect screen", pWnd->ClipRectScreen);
				//ColumnText("XML Index", "%d", pWnd->XMLIndex);
				//ColumnCheckBox("Capture title", &pWnd->bCaptureTitle);
				// TextObject
				// RuntimeTypes
				// bClientClipRectChanged
				// ParentWindow
				// pTipTextObject
				// bScreenClipRectChanged
				// FocusProxy
				// pFont
				// OldLocation
				// LayoutStrategy
				// TitlePiece
				//ColumnCXRect("Clip client rect", pWnd->ClipRectClient);

				ImGui::TreePop();
			}
		}
	}

	void DisplayCSidlScreenWndProperties(CSidlScreenWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(static_cast<CXWnd*>(pWnd), open);

		// Add CSidlScreenWnd specific details here
		if (BeginColorSection("CSidlScreenWnd Properties", open))
		{
			DisplayTemplate("SIDL Template", "CScreenTemplate*", pWnd->SidlPiece);

			if (ColumnTreeNode("INI Settings", ""))
			{
				ColumnText("Flags", pWnd->IniFlags == eIniFlag_All ? "(all)" : pWnd->IniFlags ? "0x%08x" : "(none)", pWnd->IniFlags);
				ColumnCXStr("INI Settings Group", pWnd->IniStorageName);
				ColumnText("INI Settings Version", "%d", pWnd->IniVersion);
				ColumnCheckBoxFlags("Position", (unsigned int*)&pWnd->IniFlags, eIniFlag_Position);
				ColumnCheckBoxFlags("Size", (unsigned int*)&pWnd->IniFlags, eIniFlag_Size);
				ColumnCheckBoxFlags("Font", (unsigned int*)&pWnd->IniFlags, eIniFlag_Font);
				ColumnCheckBoxFlags("Alpha", (unsigned int*)&pWnd->IniFlags, eIniFlag_Alpha);
				ColumnCheckBoxFlags("Color", (unsigned int*)&pWnd->IniFlags, eIniFlag_Color);
				ColumnCheckBoxFlags("Visibility", (unsigned int*)&pWnd->IniFlags, eIniFlag_Visibility);
				ColumnCheckBoxFlags("First Time Visibility", (unsigned int*)&pWnd->IniFlags, eIniFlag_FirstTimeVisibility);
				ColumnCheckBoxFlags("Min/Max State", (unsigned int*)&pWnd->IniFlags, eIniFlag_MinMaxState);

				ImGui::TreePop();
			}

			// TODO: RadioGroup
			//ColumnText("Last resolution pos", "{ x=%d, y=%d }", pWnd->LastResX, pWnd->LastResY);
			//ColumnText("Last resolution fullscreen", pWnd->bLastResFullscreen ? "true" : "false");
			//ColumnText("Context menu id", "%d", pWnd->ContextMenuID);
			//ColumnText("Context menu tip id", "%d", pWnd->ContextMenuTipID);
		}
	}

	void DisplayCButtonWndProperties(CButtonWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, open);

		if (BeginColorSection("CButtonWnd Properties", open))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);

			ColumnText("Picture button", pWnd->bPicture ? "true" : "false");
			// CRadioGroup
			ColumnCheckBox("Checked", &pWnd->bChecked);
			//ColumnText("Is check box", pWnd->bIsCheckbox ? "true" : "false");

			// bMouseOverLastFrame
			ColumnCXPoint("Decal offset", pWnd->DecalOffset);
			ColumnCXSize("Decal size", pWnd->DecalSize);
			ColumnColor("Decal tint", pWnd->DecalTint);

			ColumnCXRect("Text offsets", pWnd->TextOffsets);

			// TODO: flags for text mode
			ColumnText("Text mode bits", "%d", pWnd->TextModeBits);

			ColumnColor("Hover tint", pWnd->Mouseover);
			ColumnColor("Pressed tint", pWnd->Pressed);
			ColumnColor("Disabled tint", pWnd->Disabled);

			ColumnText("Cooldown time", "%d", pWnd->CoolDownBeginTime);
			ColumnText("Cooldown duration", "%d", pWnd->CoolDownDuration);

			ColumnCXStr("Indicator", pWnd->Indicator);
			ColumnText("Indicator value", "%d", pWnd->IndicatorVal);
			DisplayTextObject("Indicator", pWnd->pIndicatorTextObject);

			// pIndicatorTextObject
			// bAllowButtonClickThrough
			// bCoolDownDoDelayedStart
			// bIsDrawLasso
			//ColumnText("Button style", "0x%08x", pWnd->ButtonStyle);

			// CLabel
		}
	}

	void DisplayCSpellGemWndProperties(CSpellGemWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, false);

		if (BeginColorSection("CSpellGemWnd Properties", open))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);

			DisplayTextureAnimation("Spell icon texture", pWnd->SpellIconTexture);
			DisplayTextureAnimation("Custom icon texture", pWnd->CustomIconTexture);
		}
	}

	void DisplayCLabelWndProperties(CLabelWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CLabelWnd Properties", open))
		{
			ColumnCXStr("Text", pWnd->Text);
			ColumnCheckBox("No wrap", &pWnd->bNoWrap);
			ColumnCheckBox("Right align", &pWnd->bAlignRight);
			ColumnCheckBox("Center align", &pWnd->bAlignCenter);
			ColumnText("Offset", "%d", pWnd->xOffset);
			ColumnCheckBox("Resize height to text", &pWnd->bResizeHeightToText);
		}
	}

	void DisplayCLabelProperties(CLabel* pWnd, bool open = true)
	{
		DisplayCLabelWndProperties(pWnd, true);

		if (BeginColorSection("CLabel Properties", open))
		{
			ColumnText("EQ Type", "%d", pWnd->EQType);
		}
	}

	void DisplayCGaugeWndProperties(CGaugeWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CGaugeWnd Properties", open))
		{
			ColumnText("EQ Type", "%d", pWnd->EQType);
			ColumnColor("Fill tint", pWnd->FillTint);
			ColumnColor("Lines tint", pWnd->LinesFillTint);
			ColumnCheckBox("Draw lines fill", &pWnd->bDrawLinesFill);
			ColumnCXPoint("Text offset", CXPoint(pWnd->TextOffsetX, pWnd->TextOffsetY));
			ColumnCXSize("Gauge offset", CXSize(pWnd->GaugeOffsetX, pWnd->GaugeOffsetY));
			ColumnText("Last frame value", "%.2f", pWnd->LastFrameVal);
			ColumnCXStr("Last frame label", pWnd->LastFrameName);
			ColumnText("Last frame time", "%d", pWnd->LastFrameTime);
			ColumnText("Last frame target", "%d", pWnd->LastFrameTarget);
			ColumnCXStr("Gauge tooltip", pWnd->GaugeTooltip);
			ColumnText("Tooltip value", "%d", pWnd->TooltipVal);

			// DrawTemplate
			DisplayTextObject("Text object", pWnd->pTextObject);

			ColumnCXStr("Next draw string", pWnd->NextDrawStr);
			ColumnCheckBox("Smooth", &pWnd->bSmooth);
			ColumnText("Target value", "%d", pWnd->TargetVal);
			ColumnCheckBox("Use target value", &pWnd->bUseTargetVal);
		}
	}

	void DisplayCListWndProperties(CListWnd* pWnd, bool open = true)
	{
		DisplayCXWndProperties(pWnd, true);

		if (BeginColorSection("CListWnd Properties", open))
		{
			ColumnText("Rows", "%d", pWnd->ItemsArray.GetLength());
			ColumnText("Columns", "%d", pWnd->Columns.GetLength());

			if (ColumnTreeNodeType("Items", "SListWndLine[]", ""))
			{
				for (int i = 0; i < pWnd->ItemsArray.GetLength(); ++i)
				{
					const SListWndLine& line = pWnd->ItemsArray[i];

					char label[32];
					sprintf_s(label, "Row %d", i + 1);

					int cells = line.Cells.GetLength();

					static auto GetCellName = [](const SListWndCell& cell) -> const char*
					{
						const char* text = "(empty)";

						if (cell.pWnd)
							text = cell.pWnd->GetFirstChildWnd()->GetWindowText().c_str();
						else
							text = cell.Text.c_str();

						return text;
					};

					const char* text = "";

					if (cells >= 1)
					{
						text = GetCellName(line.Cells[0]);
					}

					if (ColumnTreeNodeType(label, "SListWndLine", "%s", text))
					{
						auto DoCell = [&](const SListWndCell& cell)
						{
							ColumnCXStr("Text", cell.Text);
							DisplayTextureAnimation("Texture", cell.pTA);
							ColumnColor("Color", cell.Color);
							ColumnWindow("Window", cell.pWnd);

							ColumnText("Texture only", cell.bOnlyDrawTexture ? "true" : "false");
							ColumnText("Unknown0x14", "%d", cell.Unknown0x14);
						};

						if (cells > 0)
						{
							bool show = false;

							if (cells == 1)
							{
								if (ColumnTreeNodeType("Cell", "SListWndCell", "%s", text))
								{
									// do the one cell
									DoCell(line.Cells[0]);

									ImGui::TreePop();
								}
							}
							else
							{
								if (ColumnTreeNodeType("Cells", "SListWndCell[]", "%d", line.Cells.GetLength()))
								{
									// iterate
									for (int j = 0; j < line.Cells.GetLength(); ++j)
									{
										sprintf_s(label, "Column %d", j + 1);
										const SListWndCell& cell = line.Cells[j];

										if (ColumnTreeNodeType(label, "SListWndCell", "%s", GetCellName(cell)))
										{
											DoCell(cell);

											ImGui::TreePop();
										}
									}

									ImGui::TreePop();
								}
							}
						}

						// I think these are all wrong.
						ColumnText("Selected", line.bSelected ? "true" : "false");
						ColumnText("Enabled", line.bEnabled ? "true" : "false");
						ColumnText("Visible", line.bVisible ? "true" : "false");
						//ColumnText("Tooltip", "%s", line.TooltipText);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			// Style
			if (ColumnTreeNode("List Style", "0x%08x", pWnd->ListWndStyle))
			{
				// TODO: Extract constants to eqlib
				ColumnCheckBoxFlags("Selectable", &pWnd->ListWndStyle,      0x10000);
				ColumnCheckBoxFlags("Multiselect", &pWnd->ListWndStyle,     0x20000);
				ColumnCheckBoxFlags("Autosort", &pWnd->ListWndStyle,        0x40000);
				ColumnCheckBoxFlags("Combobox", &pWnd->ListWndStyle,       0x100000);
				ColumnCheckBoxFlags("Header", &pWnd->ListWndStyle,         0x200000);
				ColumnCheckBoxFlags("HeaderSort", &pWnd->ListWndStyle,     0x400000);

				ImGui::TreePop();
			}

			if (ColumnTreeNode("List Details", ""))
			{
				ColumnColor("Header text color", pWnd->HeaderText);
				ColumnColor("Highlight color", pWnd->Highlight);
				ColumnColor("Selected color", pWnd->Selected);
				DisplayUITextureInfo("BG header", pWnd->BGHeader);
				ColumnColor("BG header tint", pWnd->BGHeaderTint);
				DisplayTextureAnimation("Row Separator", pWnd->pRowSep);
				DisplayTextureAnimation("Col Separator", pWnd->pColumnSep);

				ImGui::TreePop();
			}
		}
	}
};

#pragma endregion

#pragma region Windows Developer Tool

class ImGuiWindowsDeveloperTool : public ImGuiWindowBase
{
	CXWnd* m_pSelectedWnd = nullptr;
	CXWnd* m_pHoveredWnd = nullptr;
	CXWnd* m_pLastSelected = nullptr;
	bool m_selectionChanged = false;
	bool m_picking = false;
	bool m_selectPicking = false;
	bool m_pickWindowChanged = false;
	CXWnd* m_pPickingWnd = nullptr;
	int m_lastWindowCount = 0;

	// this is a pointer because we want to lazy init it
	std::unique_ptr<ImGuiWindowPropertyViewer> m_selectedViewer;
	std::map<CXWnd*, ImGuiWindowPropertyViewer> m_propertyViewers;
	ImGuiID m_topNode = 0;
	ImGuiID m_bottomNode = 0;
	bool m_firstTime = true;
	ImGuiID m_mainDockId = 0;

public:
	ImGuiWindowsDeveloperTool()
		: ImGuiWindowBase("Window Inspector")
	{
	}

	void Reset()
	{
		m_selectedViewer.reset();
		m_pSelectedWnd = nullptr;
		m_pHoveredWnd = nullptr;
		m_pPickingWnd = nullptr;
		m_pLastSelected = nullptr;
		m_picking = false;
		m_selectPicking = false;
	}

	void Update() override
	{
		m_mainDockId = ImGui::GetID("WindowDeveloperTool");
		ImGuiDockNode* node = ImGui::DockBuilderGetNode(m_mainDockId);
		if (!node || m_bottomNode == 0)
		{
			if (node)
			{
				ImGui::DockBuilderRemoveNodeChildNodes(m_mainDockId);
			}
			else
			{
				ImGui::DockBuilderRemoveNode(m_mainDockId);
				ImGui::DockBuilderAddNode(m_mainDockId, ImGuiDockNodeFlags_None);
				ImGui::DockBuilderSetNodeSize(m_mainDockId, ImVec2(480, 640));

				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::DockBuilderSetNodePos(m_mainDockId, ImVec2(viewport->Pos.x + 100, viewport->Pos.y + 100));
			}

			ImGui::DockBuilderSplitNode(m_mainDockId, ImGuiDir_Up, 0.5f, &m_topNode, &m_bottomNode);

			ImGuiDockNode* topNode = ImGui::DockBuilderGetNode(m_topNode);
			topNode->LocalFlags |= ImGuiDockNodeFlags_NoWindowMenuButton;

			ImGui::DockBuilderDockWindow("Window Inspector", m_topNode);
			ImGui::DockBuilderDockWindow("###WindowPropertyViewer1", m_bottomNode);
			ImGui::DockBuilderFinish(m_mainDockId);
		}

		//----------------------------------------------------------------------------
		// Top Part: Show the window tree

		m_pHoveredWnd = nullptr;
		m_pPickingWnd = nullptr;
		m_pickWindowChanged = false;
		bool clearPicking = true;

		if (m_open)
		{
			bool doShow = ImGui::Begin("Window Inspector", m_open.get_ptr());
			m_open.Update();
			if (doShow)
			{
				if (m_picking)
				{
					// Don't pick anything if the mouse is out of the viewport. This check
					// clears the pick window when we leave the window because LastMouseOver doesn't
					// get cleared if the mouse isn't hovering the window.
					CXWnd* lastMouseOver = nullptr;
					ImGuiViewport* viewPort = ImGui::GetMainViewport();
					if (viewPort == ImGui::GetCurrentContext()->MouseViewport)
						lastMouseOver = pWndMgr->LastMouseOver;
					m_pickWindowChanged = test_and_set(m_pPickingWnd, lastMouseOver);
				}

				if (m_picking && m_selectPicking)
				{
					m_selectPicking = false;
					m_picking = false;

					m_pSelectedWnd = m_pPickingWnd;
					m_pPickingWnd = nullptr;
				}

				bool clicked = false;

				if (m_picking)
				{
					ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.13f, 0.6f, 0.6f));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.13f, 0.7f, 0.7f));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.13f, 0.8f, 0.8f));
				}

				clicked = ImGui::Button(ICON_MD_LOCATION_SEARCHING);

				if (m_picking)
				{
					ImGui::PopStyleColor(3);
				}

				if (ImGui::IsItemHovered())
				{
					if (!m_picking)
					{
						ImGui::SetTooltip("Click to start picking\n"
							"\n"
							"While picking is enabled, hover over UI components to highlight and identify them in the tree.\n"
							"Click a UI component to select it in the tree.");
					}
				}

				if (clicked)
				{
					m_picking = !m_picking;

					if (m_picking)
					{
						// activate main viewport
						ImGuiViewport* mainViewport = ImGui::GetMainViewport();

						if (ImGui::GetCurrentWindow()->Viewport->ID != mainViewport->ID)
						{
							// Activate the main viewport window.
							::SetActiveWindow((HWND)mainViewport->PlatformHandle);
						}
					}
				}

				if (m_picking)
				{
					ImGui::SameLine();
					ImGui::Text("Pick:");
					ImGui::SameLine();

					if (m_pPickingWnd)
					{
						ImGui::TextColored(ImColor(0.f, 1.0f, 0.0f, 1.0f), "%s", m_pPickingWnd->GetXMLName().c_str());
					}
					else
					{
						ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, 0.5f), "(none)");
					}
				}

				if (m_lastWindowCount != 0)
				{
					ImGui::SameLine();
					ImGui::PushItemWidth(-1);
					ImGui::Text("%d Windows", m_lastWindowCount);
				}

				DisplayWindowTree();
			}
			ImGui::End();

			// Close this window and all windows that are children of the current dock
			if (!m_open)
			{
				// Remove any property viewers still attached to the window
				for (auto iter = m_propertyViewers.begin(); iter != m_propertyViewers.end();)
				{
					const auto& [_, viewer] = *iter;

					if (ImGuiWindow* window = ImGui::FindWindowByName(viewer.GetWindowId()))
					{
						if (window->DockId == m_bottomNode || window->DockId == m_topNode)
						{
							iter = m_propertyViewers.erase(iter);
							continue;
						}
					}

					++iter;
				}
			}
		}

		if (!m_open)
		{
			m_picking = false; // can't pick if not showing picker
			m_pSelectedWnd = nullptr;
		}

		// update last selected to remember selection for next iteration
		m_selectionChanged = test_and_set(m_pLastSelected, m_pSelectedWnd);

		//----------------------------------------------------------------------------
		// Bottom part: show the dock area of property windows

		// Update the targeted window inspector
		if (m_selectionChanged)
		{
			ShowWindowInspector(m_pSelectedWnd, true);
		}

		// Draw all the window inspectors
		DrawPropertyViewers();

		// Update background overlay showing whats currently highlighted or selected
		DrawBackgroundWindowHighlights();
	}

	void ShowWindowInspector(CXWnd* pWnd, bool isSelected = false)
	{
		if (isSelected)
		{
			if (pWnd)
			{
				if (!m_selectedViewer)
				{
					m_selectedViewer = std::make_unique<ImGuiWindowPropertyViewer>(1);
				}

				m_selectedViewer->SetWindow(pWnd);
				m_selectedViewer->SetNeedFocus(true);
				m_open = true;
			}
			else if (m_selectedViewer)
			{
				m_selectedViewer.reset();
			}
		}
		else if (pWnd)
		{
			// find pWnd.
			auto iter = m_propertyViewers.find(pWnd);
			if (iter == m_propertyViewers.end())
			{
				static int nextInstanceId = 2; // 1 = target viewer. start at 2.
				auto [iter, _] = m_propertyViewers.emplace(
					std::piecewise_construct,
					std::forward_as_tuple(pWnd),
					std::forward_as_tuple(nextInstanceId++, pWnd));
			}
			else
			{
				iter->second.SetNeedFocus(true);
			}
		}
	}

	void RemoveWindowInspector(CXWnd* pWnd)
	{
		if (pWnd == m_pSelectedWnd)
		{
			m_selectedViewer.reset();
			m_pSelectedWnd = nullptr;
		}
		m_propertyViewers.erase(pWnd);
	}

	void DrawPropertyViewers()
	{
		if (m_pSelectedWnd && m_selectedViewer)
		{
			if (!m_selectedViewer->Draw())
			{
				m_selectedViewer.reset();
				m_pSelectedWnd = nullptr;
			}
		}

		// Iterate over each property viewer and show it. If its closed then remove it from the map
		for (auto iter = m_propertyViewers.begin(); iter != m_propertyViewers.end();)
		{
			if (iter->second.GetNeedDock())
			{
				ImGui::DockBuilderDockWindow(iter->second.GetWindowId(), m_bottomNode);
				iter->second.SetNeedDock(false);
			}

			if (!iter->second.Draw())
			{
				iter = m_propertyViewers.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void DrawBackgroundWindowHighlights()
	{
		if (m_pSelectedWnd)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = m_pSelectedWnd->GetClientRect();
			drawList->AddRect(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				IM_COL32(124, 252, 0, 200));
		}

		if (m_pPickingWnd)
		{
			CXWnd* wnd = m_pPickingWnd ? m_pPickingWnd : m_pSelectedWnd;

			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = wnd->GetClientRect();
			drawList->AddRectFilled(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				IM_COL32(138, 179, 191, 128));
		}

		if (m_pHoveredWnd)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

			CXRect clientRect = m_pHoveredWnd->GetClientRect();
			drawList->AddRect(
				ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
				ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
				m_pHoveredWnd->IsReallyVisible() ? IM_COL32(255, 215, 0, 200) : IM_COL32(200, 20, 60, 200));
		}
	}

	std::vector<std::pair<std::string_view, CXWnd*>> m_windows;

	void DisplayWindowTree()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_ScrollFreezeTopRow | ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersHOuter | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg;

		if (ImGui::BeginTable("##WindowTable", 2, tableFlags))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 100);
			ImGui::TableAutoHeaders();

			m_windows.reserve(m_lastWindowCount);
			m_lastWindowCount = 0;

			if (pWndMgr)
			{
				m_windows.clear();

				for (CXWnd* pWnd : pWndMgr->ParentAndContextMenuWindows)
				{
					if (pWnd->ParentWindow == nullptr
						&& (pWnd->GetXMLData() != nullptr
							|| pWnd->GetFirstChildWnd() != nullptr
							|| !pWnd->GetWindowText().empty()
							|| !pWnd->GetXMLName().empty()))
					{
						m_windows.emplace_back(std::string_view{ pWnd->GetXMLName() }, pWnd);
					}
				}

				std::sort(std::begin(m_windows), std::end(m_windows),
					[](const auto& l, const auto& r) { return ci_less()(l.first, r.first); });

				for (const auto& [_, pWnd] : m_windows)
				{
					DisplayWindowTreeNode(pWnd);
				}

				m_lastWindowCount = m_windows.size();
			}

			ImGui::EndTable();
		}
	}

	void DisplayWindowTreeNode(CXWnd* pWnd)
	{
		ImGui::TableNextRow();
		const bool hasChildren = pWnd->GetFirstChildWnd() != nullptr;

		CXStr name = pWnd->GetXMLName();
		CXStr typeName = pWnd->GetTypeName();

		if (name.empty())
		{
			// Try to find something to display
			if (!pWnd->WindowText.empty())
			{
				name = pWnd->WindowText;
			}
			else if (pWnd->pTextObject)
			{
				name = pWnd->pTextObject->GetText();
			}

			if (name.empty())
			{
				name = "(no name)";
			}
		}

		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_SpanAvailWidth;
		bool open = false;
		bool selected = (m_pLastSelected == pWnd);
		bool selectPicking = false;

		if (m_picking)
		{
			if (m_pPickingWnd == pWnd && m_pickWindowChanged)
			{
				selected = true;
				selectPicking = true;
			}
		}

		if (selected)
		{
			flags |= ImGuiTreeNodeFlags_Selected;
		}

		if (!hasChildren)
		{
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
		}

		if (hasChildren)
		{
			if (m_pPickingWnd)
			{
				if (m_pPickingWnd->IsDescendantOf(pWnd))
					flags |= ImGuiTreeNodeFlags_DefaultOpen;
			}
			else if (m_pSelectedWnd && m_selectionChanged)
			{
				if (m_pSelectedWnd->IsDescendantOf(pWnd))
				{
					ImGui::SetNextItemOpen(true);
				}
			}

			open = ImGui::TreeNodeEx(pWnd, flags, "%s", name.c_str());
		}
		else
		{
			ImGui::TreeNodeEx(pWnd, flags, "%s", name.c_str());
		}

		if (selectPicking)
		{
			ImGui::SetScrollHere();
		}

		if (ImGui::IsItemHovered())
		{
			m_pHoveredWnd = pWnd;
		}

		if (ImGui::IsItemClicked())
		{
			// If ctrl key is pressed, create a secondary inspector instead
			if (ImGui::GetIO().KeyCtrl)
				DeveloperTools_ShowWindowInspector(pWnd);
			else
			{
				m_pSelectedWnd = pWnd;
				m_selectionChanged = true;
			}
		}

		ImGui::TableNextCell();
		ImGui::Text("%s", typeName.c_str());

		if (open)
		{
			CXWnd* pChild = pWnd->GetFirstChildWnd();
			while (pChild)
			{
				DisplayWindowTreeNode(pChild);
				pChild = pChild->GetNextSiblingWnd();
			}

#if 0
			// If this is a list box, then also traverse its child list windows.
			if (pWnd->GetType() == UI_Listbox)
			{
				CListWnd* listWnd = static_cast<CListWnd*>(pWnd);

				for (const SListWndLine& line : listWnd->ItemsArray)
				{
					// TODO: Expand into columns/rows but for now just list the children.
					for (const SListWndCell& cell : line.Cells)
					{
						// The children of the list are stored in wrapper windows. They show up
						// as Unknown types. We just skip past them.
						if (cell.pWnd && cell.pWnd->GetFirstChildWnd())
						{
							DisplayWindowTreeNode(cell.pWnd->GetFirstChildWnd());
						}
					}
				}
			}
#endif

			ImGui::TreePop();
		}
	}

	void OnWindowRemoved(CXWnd* pWnd)
	{
		// Clear the property viewer if its using this window.
		if (m_selectedViewer && m_selectedViewer->GetWindow() == pWnd)
		{
			m_selectedViewer.reset();
		}

		// Clear any matching selections in the window.
		if (m_pSelectedWnd == pWnd)
			m_pSelectedWnd = nullptr;
		if (m_pHoveredWnd == pWnd)
			m_pHoveredWnd = nullptr;
		if (m_pPickingWnd == pWnd)
			m_pPickingWnd = nullptr;
		if (m_pLastSelected == pWnd)
			m_pLastSelected = nullptr;

		RemoveWindowInspector(pWnd);
	}

	bool IsPicking() const { return m_picking; }

	void Pick()
	{
		if (m_picking)
			m_selectPicking = true;
	}

	void SetSelectedWindow(CXWnd* pWnd)
	{
		m_pSelectedWnd = pWnd;
	}
};
static ImGuiWindowsDeveloperTool s_windowDebugPanel;

#pragma endregion

#pragma region ImGui Demo Container

class ImGuiDemoWindow : public ImGuiWindowBase
{
public:
	ImGuiDemoWindow() : ImGuiWindowBase("ImGuiDemoWindow") {}

	virtual void Update() override
	{
		if (m_open)
		{
			ImGui::ShowDemoWindow(m_open.get_ptr());
			m_open.Update();
		}
	}
};
static ImGuiDemoWindow s_demoWindow;

#pragma endregion

#pragma region Spells Developer Tool

class SpellsDeveloperTool : public ImGuiWindowBase
{
public:
	SpellsDeveloperTool() : ImGuiWindowBase("Spells Developer Tools") {}

	void DoSpellBuffTableHeaders()
	{
		ImGui::TableSetupColumn("Index");
		ImGui::TableSetupColumn("Name");
		ImGui::TableSetupColumn("ID");
		ImGui::TableSetupColumn("Level");
		ImGui::TableSetupColumn("Duration");
		ImGui::TableSetupColumn("InitialDuration");
		ImGui::TableSetupColumn("HitCount");
		ImGui::TableSetupColumn("Type");
		ImGui::TableSetupColumn("ChargesRemaining");
		ImGui::TableSetupColumn("ViralTimer");
		ImGui::TableSetupColumn("Flags");
		ImGui::TableSetupColumn("Modifier");
		ImGui::TableSetupColumn("Activatable");

		for (int i = 0; i < NUM_SLOTDATA; ++i)
		{
			char temp[20];
			sprintf_s(temp, "Slot%d", i);
			ImGui::TableSetupColumn(temp, ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		}

		ImGui::TableSetupColumn("Y");
		ImGui::TableSetupColumn("X");
		ImGui::TableSetupColumn("Z");

		ImGui::TableAutoHeaders();
	}

	void DoSpellBuffTableRow(int index, SPELLBUFF& buff)
	{
		SPELL* spell = GetSpellByID(buff.SpellID);

		ImGui::TableNextRow();

		// Index
		ImGui::Text("%d", index);

		// Name
		ImGui::TableNextCell();
		if (spell)
		{
			ImGui::Text("%s", spell->Name);
		}
		else
		{
			ImGui::Text("null");
		}

		// ID
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.SpellID);

		// Level
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.Level);

		// Duration
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.Duration);

		// InitialDuration
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.InitialDuration);

		// HitCount
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.HitCount);

		// Type
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.Type);

		// ChargesRemaining
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.ChargesRemaining);

		// ViralTimer
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.ViralTimer);

		// Flags
		ImGui::TableNextCell();
		ImGui::Text("%x", buff.Flags);

		// Modifier
		ImGui::TableNextCell();
		ImGui::Text("%.2f", buff.Modifier);

		// Activatable
		ImGui::TableNextCell();
		ImGui::Text("%d", buff.Activatable);

		// SlotData[0]
		for (auto& slotData : buff.SlotData)
		{
			ImGui::TableNextCell();

			int Slot = slotData.Slot;
			int Value = slotData.Value;

			if (Slot != -1)
				ImGui::Text("%d: %d", Slot, Value);
		}

		// Y
		ImGui::TableNextCell();
		ImGui::Text("%.2f", buff.Y);

		// X
		ImGui::TableNextCell();
		ImGui::Text("%.2f", buff.X);

		// Z
		ImGui::TableNextCell();
		ImGui::Text("%.2f", buff.Z);
	}

	int DoSpellAffectTable(const char* name, EQ_Affect* affect, int numAffects, bool showEmpty = false)
	{
		ImGuiTableFlags tableFlags = 0
			| ImGuiTableFlags_SizingPolicyFixedX
			| ImGuiTableFlags_Scroll
			| ImGuiTableFlags_ScrollFreezeTopRow
			| ImGuiTableFlags_ScrollFreeze2Columns
			| ImGuiTableFlags_NoHostExtendY
			| ImGuiTableFlags_RowBg
			| ImGuiTableFlags_Borders
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_Reorderable;

		int count = 2; // start with space for header and possible scroll bar

		// calculate the size
		for (int i = 0; i < numAffects; ++i)
		{
			EQ_Affect& buff = affect[i];
			if (buff.SpellID == 0 && !showEmpty)
				continue;

			count++;
		}
		ImVec2 size = ImVec2(0, ImGui::GetTextLineHeightWithSpacing() * count);
		count = 0;

		if (ImGui::BeginTable(name, 16 + NUM_SLOTDATA, tableFlags, size))
		{
			DoSpellBuffTableHeaders();

			for (int i = 0; i < numAffects; ++i)
			{
				EQ_Affect& buff = affect[i];

				if (buff.SpellID == 0 && !showEmpty)
					continue;

				DoSpellBuffTableRow(count + 1, buff);
				count++;
			}

			ImGui::EndTable();
		}
		return count;
	}

	virtual bool IsEnabled() const override
	{
		PcProfile* pcProfile = GetPcProfile();
		if (!pcProfile)
		{
			return false;
		}

		return true;
	}

	virtual void Draw() override
	{
		PcProfile* pcProfile = GetPcProfile();
		if (!pcProfile)
		{
			ImGui::TextColored(ImColor(255, 0, 0), "You must be in game to use this");
			return;
		}

		if (ImGui::CollapsingHeader("Spell Buffs"))
		{
			int count = DoSpellAffectTable("SpellAffectBuffsTable", pcProfile->Buff, lengthof(pcProfile->Buff));
			ImGui::Text("%d Buff(s)", count);
		}

		if (ImGui::CollapsingHeader("Short Buffs"))
		{
			int count = DoSpellAffectTable("SpellAffectShortBuffsTable", pcProfile->ShortBuff, lengthof(pcProfile->ShortBuff));
			ImGui::Text("%d Short Buff(s)", count);
		}

		if (ImGui::CollapsingHeader("Stacks Test"))
		{
			static bool bCheckSpellBuffs = true;
			ImGui::Checkbox("Check buff stacking against active buffs", &bCheckSpellBuffs);

			if (bCheckSpellBuffs)
			{
				ImGui::Text("Enter the name of a spell to test buff stacking:");
			}
			else
			{
				ImGui::TextWrapped("Enter the name of two spells to test buff stacking. The test will check the second spell against the first.");
			}

			static char searchText[256] = { 0 };
			static char searchText2[256] = { 0 };

			if (bCheckSpellBuffs)
			{
				ImGui::InputText("Spell Name", searchText2, 256);
			}
			else
			{
				ImGui::InputText("Spell 1", searchText, 256);
				ImGui::InputText("Spell 2", searchText2, 256);
			}

			SPELL* pSpell = nullptr;
			SPELL* pSpell2 = nullptr;

			if (searchText[0])
			{
				pSpell = GetSpellByName(searchText);
				if (!pSpell)
				{
					ImGui::TextColored(ImColor(255, 0, 0), "No spell named '%s' found", searchText);
				}
			}

			if (searchText2[0])
			{
				pSpell2 = GetSpellByName(searchText2);
				if (!pSpell2)
				{
					ImGui::TextColored(ImColor(255, 0, 0), "No spell named '%s' found", searchText2);
				}
			}

			if (!bCheckSpellBuffs && ImGui::Button("Swap"))
			{
				char temp[256];
				strcpy_s(temp, searchText);
				strcpy_s(searchText, searchText2);
				strcpy_s(searchText2, temp);
			}

			if (pSpell2)
			{
				SPAWNINFO* pPlayer = pLocalPlayer;
				PcClient* pPcClient = pPlayer->GetPcClient();

				EQ_Affect affect;
				affect.Type = 2;
				EQ_Affect* affectToPass = nullptr;
				if (pSpell)
				{
					affect.SpellID = pSpell->ID;
					affectToPass = &affect;
				}
				int slotIndex = -1;

				EQ_Affect* ret = pPcClient->FindAffectSlot(pSpell2->ID, pPlayer, &slotIndex,
					true, -1, affectToPass ? affectToPass : nullptr, affectToPass ? 1 : 0, false);

				if (ret)
				{
					if (pSpell)
					{
						ImGui::TextColored(ImColor(0, 255, 0), "%s stacks with %s", pSpell2->Name, pSpell->Name);
					}
					else
					{
						ImGui::TextColored(ImColor(0, 255, 0), "%s stacks", pSpell2->Name);
					}
				}
				else
				{
					if (pSpell)
					{
						ImGui::TextColored(ImColor(255, 0, 0), "%s doesn't stack with %s", pSpell2->Name, pSpell->Name);
					}
					else
					{
						ImGui::TextColored(ImColor(255, 0, 0), "%s doesn't stack", pSpell2->Name);
					}
				}
			}
		}
	}
};
static SpellsDeveloperTool s_spellsTool;

#pragma endregion

//============================================================================
//============================================================================

bool DeveloperTools_HandleClick(int mouseButton, bool clicked)
{
	// If the picker is active, tell it that we clicked. Returns true (to consume the click) if this happens.
	if (mouseButton == 0 && clicked && s_windowDebugPanel.IsPicking())
	{
		s_windowDebugPanel.Pick();
		return true;
	}

	return false;
}

void DeveloperTools_RemoveWindow(CXWnd* pWnd)
{
	s_windowDebugPanel.OnWindowRemoved(pWnd);
}

void DeveloperTools_ShowWindowInspector(CXWnd* pWnd)
{
	s_windowDebugPanel.ShowWindowInspector(pWnd);
}

void DeveloperTools_SetSelectedWindow(CXWnd* pWnd)
{
	s_windowDebugPanel.SetSelectedWindow(pWnd);
}

void DeveloperTools_CloseLoginFrontend()
{
	s_windowDebugPanel.Reset();
}

void DeveloperTools_DrawMenu()
{
	if (ImGui::MenuItem("Window Inspector", nullptr, s_windowDebugPanel.IsOpen()))
		s_windowDebugPanel.Toggle();

	if (ImGui::MenuItem("Spells Inspector", nullptr, s_spellsTool.IsOpen(), s_spellsTool.IsEnabled()))
		s_spellsTool.Toggle();

	ImGui::Separator();

	if (ImGui::MenuItem("ImGui Demo", nullptr, s_demoWindow.IsOpen()))
		s_demoWindow.Toggle();
}

//============================================================================

static void DeveloperTools_Initialize()
{
}

static void DeveloperTools_Shutdown()
{
}

static void DeveloperTools_SetGameState(DWORD gameState)
{
	s_windowDebugPanel.Reset();
}

static void DeveloperTools_UpdateImGui()
{
	ImGuiWindowBase* baseWindow = s_imguiBaseWindows;
	while (baseWindow)
	{
		baseWindow->Update();
		baseWindow = baseWindow->GetNext();
	}

	//s_windowDebugPanel.Draw();
}

} // namespace mq
