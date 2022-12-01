/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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
#include "MQ2Main.h"
#include "MQ2DeveloperTools.h"

#include <mq/imgui/ImGuiUtils.h>
#include <mq/imgui/Widgets.h>

#include <chrono>

using namespace std::chrono_literals;

namespace mq {

static void Items_Initialize();
static void Items_Shutdown();
static void Items_Pulse();
static void Items_SetGameState(DWORD gameState);
static void Items_UpdateImGui();

static MQModule gItemsModule = {
	"Items",                      // Name
	false,                        // CanUnload
	Items_Initialize,             // Initialize
	Items_Shutdown,               // Shutdown
	Items_Pulse,                  // Pulse
	Items_SetGameState,           // SetGameState
	Items_UpdateImGui,            // UpdateImGui
};
MQModule* GetItemsModule() { return &gItemsModule; }

//----------------------------------------------------------------------------
// Keyring Handling
//----------------------------------------------------------------------------
#if HAS_KEYRING_WINDOW

int GetKeyRingCount(KeyRingType keyRingType)
{
	if (!pLocalPC)
		return 0;

	switch (keyRingType)
	{
	case eMount:
	case eIllusion:
	case eFamiliar:
	case eHeroForge:
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TOL)
	case eTeleportationItem:
#endif
		break;
	default: return 0;
	}

	return pLocalPC->GetKeyRingItems(keyRingType).GetCount();
}

int GetMountCount() { return GetKeyRingCount(eMount); }
int GetIllusionCount() { return GetKeyRingCount(eIllusion); }
int GetFamiliarCount() { return GetKeyRingCount(eFamiliar); }
int GetHeroForgeCount() { return GetKeyRingCount(eHeroForge); }
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TOL)
int GetTeleportationItemCount() { return GetKeyRingCount(eTeleportationItem); }
#endif

static bool gbDidUpdateKeyRing = false;
static uint64_t gLastKeyRingUpdate = 0;

void RefreshKeyRingWindow()
{
	if (gbDidUpdateKeyRing) // only need to update keyring every so often.
		return;
	if (!pKeyRingWnd)
		return;

	bool isVisible = pKeyRingWnd->IsVisible();
	auto currentPage = pKeyRingWnd->CurrentPage;
	int lastUpdateTime = pKeyRingWnd->LastUpdateTime;

	// We can update the keyring window simply by flagging it as visible,
	// resetting the timer, and calling OnProcessFrame. When we're done we
	// reset the state back to how we found it.

	if (!isVisible)
		pKeyRingWnd->Show(true);

	for (int type = CKeyRingWnd::ePageFirst; type <= CKeyRingWnd::ePageLast; ++type)
	{
		pKeyRingWnd->CurrentPage = (CKeyRingWnd::KeyRingPages)type;
		pKeyRingWnd->LastUpdateTime = 0;
		pKeyRingWnd->OnProcessFrame();
	}

	// Reset the state back to what it was.
	if (!isVisible)
		pKeyRingWnd->Show(false);
	else
		pKeyRingWnd->CurrentPage = currentPage;
	pKeyRingWnd->LastUpdateTime = lastUpdateTime;

	gbDidUpdateKeyRing = true;
	gLastKeyRingUpdate = MQGetTickCount64();
}
#endif // HAS_KEYRING_WINDOW

//----------------------------------------------------------------------------

#pragma region InvSlotInspector

class InvSlotInspector : public ImGuiWindowBase
{
public:
	InvSlotInspector()
		: ImGuiWindowBase("InvSlot Inspector")
	{
		SetDefaultSize(ImVec2(640, 450));
	}

	bool IsEnabled() const override
	{
		return pInvSlotMgr != nullptr;
	}

	void Draw() override
	{
		if (ImGui::BeginTabBar("##InvSlotInspector_TabBar", ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_NoCloseWithMiddleMouseButton))
		{
			if (ImGui::BeginTabItem("InvSlots"))
			{
				Draw_InvSlotList();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("InvSlot Mapping"))
			{
				Draw_InvSlotMapping();
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
	}

	void Draw_InvSlotList()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_SizingFixedFit
			| ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersV
			| ImGuiTableFlags_BordersOuterH
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_RowBg;

		// Columns:
		// Icon, Index, Container?, ItemIndex?, LinkedItem?, Template

		if (ImGui::BeginTable("##InvSlotTable", 6, tableFlags, ImGui::GetContentRegionAvail()))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("##Index", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize, -1.0f);
			ImGui::TableSetupColumn("##Icon", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize, -1.0f);
			ImGui::TableSetupColumn("Container", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableSetupColumn("Item Index", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableSetupColumn("Item", ImGuiTableColumnFlags_WidthStretch, -1.0f);
			ImGui::TableSetupColumn("Screen ID", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableHeadersRow();

			for (int i = 0; i < pInvSlotMgr->TotalSlots; ++i)
			{
				CInvSlot* pInvSlot = pInvSlotMgr->SlotArray[i];
				if (!pInvSlot || !pInvSlot->bEnabled) continue;

				ImGui::TableNextRow();

				ImGui::TableNextColumn(); // index
				ImGui::Text("%d", pInvSlot->Index);

				ImGui::TableNextColumn(); // icon
				imgui::DrawTextureAnimation(pInvSlot->pInvSlotAnimation, CXSize(16, 16));

				ItemGlobalIndex globalIndex = pInvSlot->pInvSlotWnd ? pInvSlot->pInvSlotWnd->ItemLocation : ItemGlobalIndex();
				ItemPtr pItem = pLocalPC->GetItemByGlobalIndex(globalIndex);

				ImGui::TableNextColumn(); // Container
				if (globalIndex.IsValidLocation())
					ImGui::Text("%s", GetNameForContainerInstance(globalIndex.GetLocation()));

				ImGui::TableNextColumn(); // ItemIndex
				if (globalIndex.IsValidIndex())
				{
					char szItemIndex[32];
					globalIndex.GetIndex().FormatItemIndex(szItemIndex, lengthof(szItemIndex));
					ImGui::Text("%s", szItemIndex);
				}

				ImGui::TableNextColumn(); // Item Name
				if (pItem)
				{
					ImGui::PushID((void*)pItem.get());
					if (imgui::ItemLinkText(pItem->GetName(), GetColorForChatColor(USERCOLOR_LINK)))
						pItemDisplayManager->ShowItem(pItem);
					ImGui::PopID();
				}

				ImGui::TableNextColumn(); // Template
				if (pInvSlot->pInvSlotWnd)
				{
					if (CXMLData* pXMLData = pInvSlot->pInvSlotWnd->GetXMLData())
					{
						ImGui::Text("%s", pXMLData->ScreenID.c_str());
					}
				}
			}

			ImGui::EndTable();
		}
	}

	void Draw_InvSlotMapping()
	{
		ImGuiTableFlags tableFlags = ImGuiTableFlags_SizingFixedFit
			| ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_Sortable
			| ImGuiTableFlags_BordersV
			| ImGuiTableFlags_BordersOuterH
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_RowBg;

		if (ImGui::BeginTable("##InvSlotMappingTable", 2, tableFlags, ImGui::GetContentRegionAvail()))
		{
			enum {
				ColumnId_Value = 1,
				ColumnId_Slot = 2,
			};

			// Columns:
			// Value, SlotId
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch | ImGuiTableColumnFlags_DefaultSort, -1.0f, ColumnId_Value);
			ImGui::TableSetupColumn("Slot ID", ImGuiTableColumnFlags_WidthStretch, -1.0f, ColumnId_Slot);
			ImGui::TableHeadersRow();

			static std::vector<std::pair<std::string, int>> slotMapping;
			static bool init = false;

			ImGuiTableSortSpecs* sort_specs = ImGui::TableGetSortSpecs();
			auto sortFunc = [&](const auto& lhs, const auto& rhs)
			{
				for (int n = 0; n < sort_specs->SpecsCount; n++)
				{
					const ImGuiTableColumnSortSpecs* sort_spec = &sort_specs->Specs[n];
					int delta = 0;

					switch (sort_spec->ColumnUserID)
					{
					case ColumnId_Slot:
						delta = lhs.second - rhs.second;
						if (delta != 0)
							break;
						// fallthrough
					case ColumnId_Value:
						delta = alphanum_comp(lhs.first, rhs.first);
						break;
					default: break;
					}
					if (delta > 0)
						return (sort_spec->SortDirection == ImGuiSortDirection_Ascending);
					if (delta < 0)
						return !(sort_spec->SortDirection == ImGuiSortDirection_Ascending);
				}

				return true;
			};

			if (!init)
			{
				for (auto& [key, value] : ItemSlotMap)
				{
					slotMapping.emplace_back(key, value);
				}

				init = true;
			}

			if (sort_specs->SpecsDirty)
			{
				std::sort(slotMapping.begin(), slotMapping.end(), sortFunc);
				sort_specs->SpecsDirty = false;
			}

			for (auto& [key, value] : slotMapping)
			{
				ImGui::TableNextRow();

				ImGui::TableNextColumn();
				ImGui::Text("%s", key.c_str());

				ImGui::TableNextColumn();
				ImGui::Text("%d", value);
			}

			ImGui::EndTable();
		}
	}
};

InvSlotInspector* s_invSlotInspector = nullptr;

#pragma endregion

//----------------------------------------------------------------------------

static void Items_Initialize()
{
	s_invSlotInspector = new InvSlotInspector();
	DeveloperTools_RegisterMenuItem(s_invSlotInspector, "Inventory Slots", s_menuNameInspectors);
}

static void Items_Shutdown()
{
	DeveloperTools_UnregisterMenuItem(s_invSlotInspector);
	delete s_invSlotInspector; s_invSlotInspector = nullptr;
}

static void Items_Pulse()
{
#if HAS_KEYRING_WINDOW
	// This may not be necessary if the data cannot be manipulated without the UI.
	// This resets the check for gbDidUpdateKeyRing 5 seconds after it is set.
	if (gbDidUpdateKeyRing)
	{
		if (gLastKeyRingUpdate + 5000 < MQGetTickCount64())
		{
			gbDidUpdateKeyRing = false;
		}
	}
#endif // HAS_KEYRING_WINDOW
}

static void Items_SetGameState(DWORD gameState)
{
#if HAS_KEYRING_WINDOW
	if (gameState == GAMESTATE_INGAME)
		gbDidUpdateKeyRing = false;
#endif // HAS_KEYRING_WINDOW
}

static void Items_UpdateImGui()
{
}

} // namespace mq
