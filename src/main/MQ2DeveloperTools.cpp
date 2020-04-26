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

class ImGuiWindowDebugPanel
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
	ImGuiWindowDebugPanel() = default;

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


		//ImGui::BeginChild("1");
		{
			if (ImGui::Button("Pick"))
			{
				m_picking = !m_picking;
			}

			if (ImGui::BeginTable("##WindowTable", 2, tableFlags, ImVec2(0, m_topPaneSize)))
			{
				ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide | ImGuiTableColumnFlags_WidthStretch);
				ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 100);
				ImGui::TableAutoHeaders();

				if (pWndMgr)
				{
					for (CXWnd* pWnd : pWndMgr->ParentAndContextMenuWindows)
					{
						DisplayWindowTreeNode(pWnd);
					}
				}

				ImGui::EndTable();
			}
		}
		//ImGui::EndChild();

		// if the selected window was not found, then clear it.
		if (!m_foundSelected)
		{
			m_pSelectedWnd = nullptr;
		}

		imgui::DrawSplitter(true, 9.0f, &m_topPaneSize, &m_bottomPaneSize, 50, 50);


		//ImGui::BeginChild("2");
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
		//ImGui::EndChild();

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
		}
	}

	void DisplayDetailsSection(CSidlScreenWnd* pWnd)
	{
		DisplayDetailsSection(static_cast<CXWnd*>(pWnd));

		// Add CSidlScreenWnd specific details here
	}
};

static ImGuiWindowDebugPanel s_windowDebugPanel;

static void WindowsDebugPanel()
{
	s_windowDebugPanel.Draw();
}

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
	AddDebugPanel("Windows", WindowsDebugPanel);
}

void DeveloperTools_Shutdown()
{
	RemoveDebugPanel("Windows");
}


} // namespace mq
