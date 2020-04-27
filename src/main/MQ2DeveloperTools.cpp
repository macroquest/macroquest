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

#include <algorithm>
#include <string>
#include <unordered_map>

#include <spdlog/spdlog.h>

namespace mq {

static void DeveloperTools_Initialize();
static void DeveloperTools_Shutdown();

static MQModule s_developerToolsModule = {
	"DeveloperTools",              // Name
	true,                          // CanUnload
	DeveloperTools_Initialize,
	DeveloperTools_Shutdown,
};
DECLARE_MODULE_INITIALIZER(s_developerToolsModule);

//----------------------------------------------------------------------------

#pragma region Common Tools

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

inline void DisplayCXSize(const char* label, const CXSize& size)
{
	ImGui::LabelText(label, "w=%d, h=%d", size.cx, size.cy);
}

inline void DisplayCXRect(const char* label, const CXRect& rect)
{
	ImGui::LabelText(label, "x=%d, y=%d, w=%d, h=%d", rect.left, rect.top, rect.GetWidth(), rect.GetHeight());
}

inline void DisplayCXPoint(const char* label, const CXPoint& point)
{
	ImGui::LabelText(label, "x=%d, y=%d", point.x, point.y);
}

inline void DisplayColor(const char* label, const COLORREF& color)
{
	//ImGui::ColorButton(id, ImGui::ColorConvertU32ToFloat4(color), 
	//ColorButton(const char* desc_id, const ImVec4& col, ImGuiColorEditFlags flags = 0, ImVec2 size = ImVec2(0, 0));

	ImColor colors{ color };

	ImGui::ColorEdit4(label, (float*)&colors, ImGuiColorEditFlags_NoInputs);
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

void DisplayUITextureInfo(const char* label, const CUITextureInfo& textureInfo)
{
	if (ImGui::TreeNode((const void*)&textureInfo, "%s: %s", label, textureInfo.Name.c_str()))
	{
		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Name", "%s", textureInfo.Name.empty() ? "(UITextureInfo)" : textureInfo.Name.c_str());
			ImGui::LabelText("Valid", textureInfo.bValid ? "true" : "false");
			ImGui::LabelText("Directory", "%s", UIDirectoryToString(textureInfo.Directory));
			DisplayCXSize("Texture Size", textureInfo.TextureSize);
			ImGui::LabelText("Texture Id", "%d", textureInfo.TextureId);
			RenderUITextureInfoTexture(textureInfo);
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		ImGui::TreePop();
	}
}

void DisplayUITexturePiece(const char* label, const CUITexturePiece& texturePiece)
{
	const char* name = texturePiece.GetTextureInfo().Name.empty() ? "(UITexturePiece)" : texturePiece.GetTextureInfo().Name.c_str();

	if (ImGui::TreeNode((const void*)&texturePiece, "%s: %s", label, name))
	{
		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Name", "%s", name);
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		DisplayUITextureInfo("TextureInfo", texturePiece.GetTextureInfo());

		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			DisplayCXRect("Rect", texturePiece.GetRect());
			DisplayCXSize("Size", texturePiece.GetSize());
			RenderUITextureInfoTexture(texturePiece.GetTextureInfo(), texturePiece.GetRect());
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		ImGui::TreePop();
	}
}

void DisplayTextureAnimation(const char* label, const CTextureAnimation* textureAnim)
{
	const char* name = textureAnim ? textureAnim->Name.empty() ? "(TextureAnimation)" : textureAnim->Name.c_str() : "(null)";

	if (ImGui::TreeNode((const void*)textureAnim, "%s: %s", label, name))
	{
		if (textureAnim)
		{
			ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
				ImGui::LabelText("Name", "%s", name);
			ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

			if (ImGui::TreeNode((const void*)&textureAnim->Frames, "Frames (%d)", textureAnim->Frames.GetLength()))
			{
				for (int i = 0; i < textureAnim->Frames.GetLength(); ++i)
				{
					const STextureAnimationFrame& frame = textureAnim->Frames[i];

					if (ImGui::TreeNode((const void*)&frame, "Frame %d", i + 1))
					{
						DisplayUITexturePiece("TexturePiece", frame.Piece);

						ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
							ImGui::LabelText("Ticks", "%d", frame.Ticks);
							DisplayCXPoint("Hotspot", frame.Hotspot);
						ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
				DisplayCXSize("Size", textureAnim->Size);
				ImGui::LabelText("Paused", textureAnim->bPaused ? "true" : "false");
				ImGui::LabelText("Vertical", textureAnim->bVertical ? "true" : "false");
				ImGui::LabelText("Grid", textureAnim->bGrid ? "true" : "false");

				if (textureAnim->bGrid)
				{
					DisplayCXSize("Cell size", CXSize(textureAnim->CellWidth, textureAnim->CellHeight));
					DisplayCXRect("Cell rect", textureAnim->CellRect);
					ImGui::LabelText("Current cell", "%d", textureAnim->CurCell);
				}

				if (textureAnim->ZeroFrame != 0)
				{
					ImGui::LabelText("Zero frame", "%d", textureAnim->ZeroFrame);
				}

				ImGui::LabelText("Cycle animation", textureAnim->bCycle ? "true" : "false");
				ImGui::LabelText("Total ticks", "%d", textureAnim->TotalTicks);
				ImGui::LabelText("Start ticks", "%d", textureAnim->StartTicks);
			ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());
		}

		ImGui::TreePop();
	}
}

void DisplayTAFrameDraw(const char* label, const CTAFrameDraw& frameDraw)
{
	const char* name = frameDraw.GetName().empty() ? "(TAFrameDraw)" : frameDraw.GetName().c_str();

	if (ImGui::TreeNode((const void*)&frameDraw, "%s: %s", label, name))
	{
		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Name", "%s", name);
			DisplayCXSize("Frame size", frameDraw.GetFrameSize());
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		for (int i = 0; i < CTAFrameDraw::FrameDraw_Max; ++i)
		{
			DisplayTextureAnimation(
				CTAFrameDraw::FrameDrawPieceToString(static_cast<CTAFrameDraw::EFrameDrawPiece>(i)),
				frameDraw.GetAnimation(static_cast<CTAFrameDraw::EFrameDrawPiece>(i)));
		}

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CButtonDrawTemplate& drawTemplate)
{
	const char* name = drawTemplate.strName.empty() ? "(ButtonDrawTemplate)" : drawTemplate.strName.c_str();

	if (ImGui::TreeNode((const void*)&drawTemplate, "%s: %s", label, name))
	{
		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Name", "%s", name);
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		DisplayTextureAnimation("Normal", drawTemplate.ptaNormal);
		DisplayTextureAnimation("Pressed", drawTemplate.ptaPressed);
		DisplayTextureAnimation("Hover", drawTemplate.ptaFlyby);
		DisplayTextureAnimation("Disabled", drawTemplate.ptaDisabled);
		DisplayTextureAnimation("Pressed hover", drawTemplate.ptaPressedFlyby);
		DisplayTextureAnimation("Pressed disabled", drawTemplate.ptaPressedDisabled);
		DisplayTextureAnimation("Normal decal", drawTemplate.ptaNormalDecal);
		DisplayTextureAnimation("Pressed decal", drawTemplate.ptaPressedDecal);
		DisplayTextureAnimation("Hover decal", drawTemplate.ptaFlybyDecal);
		DisplayTextureAnimation("Disabled decal", drawTemplate.ptaDisabledDecal);
		DisplayTextureAnimation("Pressed hover decal", drawTemplate.ptaPressedFlybyDecal);
		DisplayTextureAnimation("Pressed disabled decal", drawTemplate.ptaPressedDisabledDecal);

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CScrollbarTemplate& drawTemplate)
{
	const char* name = drawTemplate.strName.empty() ? "(ScrollbarTemplate)" : drawTemplate.strName.c_str();

	if (ImGui::TreeNode((const void*)&drawTemplate, "%s: %s", label, name))
	{
		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Name", "%s", name);
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		DisplayDrawTemplate("Up Button", drawTemplate.bdtUp);
		DisplayDrawTemplate("Down Button", drawTemplate.bdtDown);
		DisplayTAFrameDraw("Thumb", drawTemplate.frameThumb);
		DisplayUITextureInfo("Middle", drawTemplate.tiMiddle);

		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			DisplayColor("Middle tint", drawTemplate.colorMiddleTint);
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		ImGui::TreePop();
	}
}

void DisplayDrawTemplate(const char* label, const CXWndDrawTemplate& drawTemplate)
{
	const char* name = drawTemplate.strName.empty() ? "(XWndDrawTemplate)" : drawTemplate.strName.c_str();

	if (ImGui::TreeNode((const void*)&drawTemplate, "%s: %s", label, name))
	{
		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Name", "%s", name);
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		DisplayUITextureInfo("Background texture", drawTemplate.tiBackground);

		ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
			ImGui::LabelText("Background draw type", "%s",
				XWndBackgroundDrawTypeToString(static_cast<XWndBackgroundDrawType>(drawTemplate.nBackgroundDrawType)));
		ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());

		DisplayDrawTemplate("Vertical scroll bar", drawTemplate.sbtVScroll);
		DisplayDrawTemplate("Horizontal scroll bar", drawTemplate.sbtHScroll);
		DisplayDrawTemplate("Close box", drawTemplate.bdtCloseBox);
		DisplayDrawTemplate("Help box", drawTemplate.bdtQMarkBox);
		DisplayDrawTemplate("Minimize box", drawTemplate.bdtMinimizeBox);
		DisplayDrawTemplate("Maximize box", drawTemplate.bdtMaximizeBox);
		DisplayDrawTemplate("Tile box", drawTemplate.bdtTileBox);
		DisplayTAFrameDraw("Border", drawTemplate.frameBorder);
		DisplayTAFrameDraw("Title bar", drawTemplate.frameTitlebar);

		ImGui::TreePop();
	}
}

#pragma endregion

#pragma region Windows Developer Tool

class ImGuiWindowsDeveloperTool
{
	CXWnd* m_pSelectedWnd = nullptr;
	CXWnd* m_pHoveredWnd = nullptr;

	// Never dereference this. the window might be deleted. We just use it to track
	// what is selected.
	CXWnd* m_pLastSelected = nullptr;
	bool m_foundSelected = false;
	bool m_selectionChanged = false;

	float m_topPaneSize = -1.0f;
	float m_bottomPaneSize = -1.0f;

	bool m_picking = false;
	bool m_selectPicking = false;
	CXWnd* m_pPickingWnd = nullptr;

public:
	ImGuiWindowsDeveloperTool() = default;

	void Draw()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_ScrollFreezeTopRow | ImGuiTableFlags_ScrollY | ImGuiTableFlags_BordersV | ImGuiTableFlags_BordersHOuter | ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg;

		// This is so we can reset the selected window if it is not found.
		m_foundSelected = false;
		m_pHoveredWnd = nullptr;
		m_pPickingWnd = nullptr;

		ImVec2 availSize = ImGui::GetContentRegionAvail();
		if (m_topPaneSize == -1.0f)
			m_topPaneSize = availSize.y * .75f;
		if (m_bottomPaneSize == -1.0f)
			m_bottomPaneSize = availSize.y - m_topPaneSize - 1;

		if (m_picking)
		{
			m_pPickingWnd = pWndMgr->LastMouseOver;
		}

		if (ImGui::Button("Pick"))
		{
			m_picking = !m_picking;
		}

		imgui::DrawSplitter(true, 9.0f, &m_topPaneSize, &m_bottomPaneSize, 50, 50);

		if (ImGui::BeginTable("##WindowTable", 2, tableFlags, ImVec2(0, m_topPaneSize)))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 100);
			ImGui::TableAutoHeaders();

			if (pWndMgr)
			{
				for (CXWnd* pWnd : pWndMgr->ParentAndContextMenuWindows)
				{
					if (pWnd->ParentWindow == nullptr)
						DisplayWindowTreeNode(pWnd);
					else
						__noop;
				}
			}

			ImGui::EndTable();
		}

		// if the selected window was not found, then clear it.
		if (!m_foundSelected)
		{
			m_pSelectedWnd = nullptr;
		}

		if (ImGui::BeginChild("2"))
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 9);

			if (m_pSelectedWnd)
			{
				ImGui::Text("Selected Window: %s", m_pSelectedWnd->GetXMLName().c_str());

				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

				CXRect clientRect = m_pSelectedWnd->GetClientRect();
				drawList->AddRect(
					ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
					ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
					IM_COL32(124, 252, 0, 200));
			}
			else
			{
				ImGui::Text("Selected Window: None");
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
				ImGui::Text("Hovered Window: %s", m_pHoveredWnd->GetXMLName().c_str());

				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImDrawList* drawList = ImGui::GetBackgroundDrawList(viewport);

				CXRect clientRect = m_pHoveredWnd->GetClientRect();
				drawList->AddRect(
					ImVec2(clientRect.left + viewport->Pos.x, clientRect.top + viewport->Pos.y),
					ImVec2(clientRect.right + viewport->Pos.x, clientRect.bottom + viewport->Pos.y),
					m_pHoveredWnd->IsReallyVisible() ? IM_COL32(255, 215, 0, 200) : IM_COL32(200, 20, 60, 200));
			}
			else
			{
				ImGui::Text("Hovered Window: None");
			}

			if (m_pPickingWnd)
			{
				ImGui::Text("Picking: %s", m_pPickingWnd->GetXMLName().c_str());
			}
			else if (m_picking)
			{
				ImGui::Text("Picking...");
			}

			ImGui::Separator();

			DisplayDetailsPanel();
		}
		ImGui::EndChild();

		// update last selected to remember selection for next iteration
		m_selectionChanged = test_and_set(m_pLastSelected, m_pSelectedWnd);

		if (m_picking && m_selectPicking)
		{
			m_selectPicking = false;
			m_picking = false;
		}
	}

	void DisplayWindowTreeNode(CXWnd* pWnd)
	{
		if (pWnd->GetType() == UI_Unknown)
			return;
		ImGui::TableNextRow();
		const bool hasChildren = pWnd->GetFirstChildWnd() != nullptr;

		CXStr pName = pWnd->GetXMLName();
		CXMLData* pXMLData = pWnd->GetXMLData();
		CXStr typeName = pWnd->GetTypeName();
		//const char* szWindowName = pName ? pName->c_str() : "";
		//const char* szXmlName = pXMLData ? pXMLData->Name.c_str() : "";
		//const char* szXmlScreenID = pXMLData ? pXMLData->ScreenID.c_str() : "";
		//if (strlen(szWindowName) == 0)
		//	szWindowName = szXmlName;

		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth;
		bool open = false;
		bool selected = (m_pLastSelected == pWnd);
		bool selectPicking = false;

		if (m_picking)
		{
			if (m_pPickingWnd == pWnd)
			{
				selected = true;
				selectPicking = true;
			}
		}

		if (selected)
		{
			flags |= ImGuiTreeNodeFlags_Selected;
			m_foundSelected = true;
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

			open = ImGui::TreeNodeEx(pWnd, flags, "%s", pName.c_str());
		}
		else
		{
			ImGui::TreeNodeEx(pWnd, flags, "%s", pName.c_str());
		}

		if (selectPicking)
		{
			ImGui::SetScrollHere();
		}

		if (ImGui::IsItemHovered())
		{
			m_pHoveredWnd = pWnd;
		}
		if (ImGui::IsItemClicked() || (selectPicking && m_selectPicking))
		{
			m_pSelectedWnd = pWnd;
			m_foundSelected = true;
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

			// If this is a list box, then also traverse its child list windows.
			if (pWnd->GetType() == UI_Listbox)
			{
				CListWnd* listWnd = static_cast<CListWnd*>(pWnd);

				for (SListWndLine& line : listWnd->ItemsArray)
				{
					// TODO: Expand into columns/rows but for now just list the children.
					for (SListWndCell& cell : line.Cells)
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

			ImGui::TreePop();
		}
	}

	bool IsPicking() const { return m_picking; }

	void Pick()
	{
		if (m_picking)
			m_selectPicking = true;
	}

	void DisplayDetailsPanel()
	{
		if (!m_pSelectedWnd)
			return;

		switch (m_pSelectedWnd->GetType())
		{
		case UI_Screen:
			DisplayDetailsSection(static_cast<CSidlScreenWnd*>(m_pSelectedWnd));
			break;

		case UI_Button:
			DisplayDetailsSection(static_cast<CButtonWnd*>(m_pSelectedWnd));
			break;

		default:
			DisplayDetailsSection(m_pSelectedWnd);
			break;
		}
	}

	void DisplayDetailsSection(CXMLData* pXMLData)
	{
		if (!pXMLData) return;

		if (ImGui::CollapsingHeader("XML Properties", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::LabelText("Type", "%s (%d)", pXMLData->TypeName.c_str(), pXMLData->Type);
			ImGui::LabelText("Name", "%s", pXMLData->Name.c_str());
			ImGui::LabelText("Screen ID", "%s", pXMLData->ScreenID.c_str());
		}
	}

	void DisplayDetailsSection(CXWnd* pWnd)
	{
		DisplayDetailsSection(pWnd->GetXMLData());

		// Add CXWnd specific details here
		if (ImGui::CollapsingHeader("CXWnd Properties", ImGuiTreeNodeFlags_DefaultOpen))
		{
			ImGui::Checkbox("Visible", &pWnd->dShow);
			ImGui::Checkbox("Enabled", &pWnd->Enabled);

			if (ImGui::TreeNode("Style", "Style (0x%08x)", pWnd->WindowStyle))
			{
				ImGui::CheckboxFlags("Vertical Scroll", &pWnd->WindowStyle, CWS_VSCROLL);
				ImGui::CheckboxFlags("Horizontal Scroll", &pWnd->WindowStyle, CWS_HSCROLL);
				ImGui::CheckboxFlags("Title Bar", &pWnd->WindowStyle, CWS_TITLE);
				ImGui::CheckboxFlags("Close Box", &pWnd->WindowStyle, CWS_CLOSE);
				ImGui::CheckboxFlags("Tile Box", &pWnd->WindowStyle, CWS_TILEBOX);
				ImGui::CheckboxFlags("Minimize Box", &pWnd->WindowStyle, CWS_MINIMIZE);
				ImGui::CheckboxFlags("Border", &pWnd->WindowStyle, CWS_BORDER);
				ImGui::CheckboxFlags("Relative Rect", &pWnd->WindowStyle, CWS_RELATIVERECT);
				ImGui::CheckboxFlags("Vertical Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCHV);
				ImGui::CheckboxFlags("Horizontal Auto Stretch", &pWnd->WindowStyle, CWS_AUTOSTRETCH);
				ImGui::CheckboxFlags("Resizable", &pWnd->WindowStyle, CWS_RESIZEALL);
				ImGui::CheckboxFlags("Transparent", &pWnd->WindowStyle, CWS_TRANSPARENT);
				ImGui::CheckboxFlags("Use My Alpha", &pWnd->WindowStyle, CWS_USEMYALPHA);
				ImGui::CheckboxFlags("Docking Enabled", &pWnd->WindowStyle, CWS_DOCKING);
				ImGui::CheckboxFlags("Immediate Tooltip", &pWnd->WindowStyle, CWS_TOOLTIP_NODELAY);
				ImGui::CheckboxFlags("Frame", &pWnd->WindowStyle, CWS_FRAMEWND);
				ImGui::CheckboxFlags("No Hit Test", &pWnd->WindowStyle, CWS_NOHITTEST);
				ImGui::CheckboxFlags("QMark Box", &pWnd->WindowStyle, CWS_QMARK);
				ImGui::CheckboxFlags("Disable Move", &pWnd->WindowStyle, CWS_NOMOVABLE);
				ImGui::CheckboxFlags("Maximize Box", &pWnd->WindowStyle, CWS_MAXIMIZE);
				ImGui::CheckboxFlags("Vertical Auto Scroll", &pWnd->WindowStyle, CWS_AUTOVSCROLL);
				ImGui::CheckboxFlags("Horizontal Auto Scroll", &pWnd->WindowStyle, CWS_AUTOHSCROLL);
				ImGui::CheckboxFlags("Client Movable", &pWnd->WindowStyle, CWS_CLIENTMOVABLE);
				ImGui::CheckboxFlags("Transparent Control", &pWnd->WindowStyle, CWS_TRANSPARENTCONTROL);
				ImGui::TreePop();
			}

			if (pWnd->DrawTemplate)
			{
				DisplayDrawTemplate("Template", *pWnd->DrawTemplate);
			}
			else
			{
				ImGui::LabelText("Template", "(none)");
			}
		}
	}

	void DisplayDetailsSection(CSidlScreenWnd* pWnd)
	{
		DisplayDetailsSection(static_cast<CXWnd*>(pWnd));

		// Add CSidlScreenWnd specific details here
	}

	void DisplayDetailsSection(CButtonWnd* pWnd)
	{
		DisplayDetailsSection(static_cast<CXWnd*>(pWnd));

		if (ImGui::CollapsingHeader("CButtonWnd Properties", ImGuiTreeNodeFlags_DefaultOpen))
		{
			DisplayDrawTemplate("Template", pWnd->DrawTemplate);
		}
	}
};

#pragma endregion

static ImGuiWindowsDeveloperTool s_windowDebugPanel;

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

//============================================================================

void DeveloperTools_Initialize()
{
	AddDebugPanel("Windows", []() { s_windowDebugPanel.Draw(); });
}

void DeveloperTools_Shutdown()
{
	RemoveDebugPanel("Windows");
}


} // namespace mq
