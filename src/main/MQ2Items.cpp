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
static void Items_SetGameState(int gameState);
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
#if HAS_TELEPORTATION_KEYRING
	case eTeleportationItem:
#endif
#if HAS_ACTIVATED_ITEM_KEYRING
	case eActivatedItem:
#endif
#if HAS_EQUIPMENT_KEYRING
	case eEquipmentKeyRing:
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
int GetTeleportationItemCount()
{
#if HAS_TELEPORTATION_KEYRING
	return GetKeyRingCount(eTeleportationItem);
#else
	return 0;
#endif
}

int GetActivatedItemCount()
{
#if HAS_ACTIVATED_ITEM_KEYRING
	return GetKeyRingCount(eActivatedItem);
#else
	return 0;
#endif
}

int GetEquipmentItemCount()
{
#if HAS_EQUIPMENT_KEYRING
	return GetKeyRingCount(eEquipmentKeyRing);
#else
	return 0;
#endif
}

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
#if IS_CLIENT_DATE(20251103)
		constexpr int columns = 8;
#else
		constexpr int columns = 6;
#endif

		if (ImGui::BeginTable("##InvSlotTable", columns, tableFlags, ImGui::GetContentRegionAvail()))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("##Index", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize, -1.0f);
			ImGui::TableSetupColumn("##Icon", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize, -1.0f);
			ImGui::TableSetupColumn("Container", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableSetupColumn("Item Index", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableSetupColumn("Item", ImGuiTableColumnFlags_WidthStretch, -1.0f);
#if IS_CLIENT_DATE(20251103)
			ImGui::TableSetupColumn("Usable", ImGuiTableColumnFlags_WidthFixed, 20.0f);
			ImGui::TableSetupColumn("Locked", ImGuiTableColumnFlags_WidthFixed, 20.0f);
#endif
			ImGui::TableSetupColumn("Screen ID", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableHeadersRow();

			for (int i = 0; i < pInvSlotMgr->TotalSlots; ++i)
			{
				CInvSlot* pInvSlot = pInvSlotMgr->SlotArray[i];
				if (!pInvSlot || !pInvSlot->bEnabled) continue;

				ImGui::PushID(pInvSlot);

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

#if IS_CLIENT_DATE(20251103)
				ImGui::TableNextColumn(); // Usable
				ImGui::Checkbox("##usable", &pInvSlot->bUsable);

				ImGui::TableNextColumn(); // Locked
				ImGui::Checkbox("##locked", &pInvSlot->bLocked);
#endif

				ImGui::TableNextColumn(); // Template
				if (pInvSlot->pInvSlotWnd)
				{
					if (CXMLData* pXMLData = pInvSlot->pInvSlotWnd->GetXMLData())
					{
						ImGui::Text("%s", pXMLData->ScreenID.c_str());
					}
				}

				ImGui::PopID();
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

#pragma region ItemContainerInspector

class ItemContainerInspector : public ImGuiWindowBase
{
	ItemContainerInstance m_selectedContainerType = eItemContainerPossessions;
	std::unique_ptr<CTextureAnimation> m_iconsTexture;

public:
	ItemContainerInspector()
		: ImGuiWindowBase("ItemContainer Inspector")
	{
		SetDefaultSize(ImVec2(640, 450));

		
	}

	bool IsEnabled() const override
	{
		return pInvSlotMgr != nullptr;
	}

	void Draw() override
	{
		char comboLabel[64];
		sprintf_s(comboLabel, "Container Type: %d###containerCombo", m_selectedContainerType);
		if (ImGui::BeginCombo(comboLabel, GetNameForContainerInstance(m_selectedContainerType)))
		{
			for (ItemContainerInstance type = eItemContainerPossessions; type < eNumItemContainers;
				type = (ItemContainerInstance)(type + 1))
			{
				bool isSelected = m_selectedContainerType == type;

				if (ImGui::Selectable(GetNameForContainerInstance(type), isSelected))
				{
					m_selectedContainerType = type;
				}

				if (isSelected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}

			ImGui::EndCombo();
		}

		ItemContainer* pItemContainer = GetItemContainerByType(m_selectedContainerType);
		if (!pItemContainer)
		{
			ImGui::Text("No instance of item container found");
			return;
		}

		int size = pItemContainer->GetSize();
		int count = pItemContainer->GetCount();

		ImGui::Text("Item Count: %d / %d", count, size);
		if (pItemContainer->IsDynamic())
		{
			ImGui::SameLine();
			ImGui::Text("(Dynamic)");
		}

		switch (m_selectedContainerType)
		{
#if HAS_DRAGON_HOARD
		case eItemContainerDragonHoard:
			ImGui::Text("Dragon Hoard Max Capacity: %d", pLocalPC->DragonHoardCapacity);
			ImGui::Text("Dragon Hoard Populated: %d", pLocalPC->DragonHoardPopulated ? 1 : 0);
			break;
#endif

#if HAS_TRADESKILL_DEPOT
		case eItemContainerTradeskillDepot:
			ImGui::Text("Tradeskill Depot Max Capacity: %d", pLocalPC->TradeskillDepotCapacity);
			ImGui::Text("Tradeskill Depot Populated: %d", pLocalPC->TradeskillDepotPopulated);
			break;
#endif

#if HAS_KEYRING_WINDOW
		case eItemContainerMountKeyRingItems:
			ImGui::Text("Mount Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eMount]);
			break;

		case eItemContainerIllusionKeyRingItems:
			ImGui::Text("Illusion Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eIllusion]);
			break;

		case eItemContainerFamiliarKeyRingItems:
			ImGui::Text("Familiar Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eFamiliar]);
			break;

		case eItemContainerHeroForgeKeyRingItems:
			ImGui::Text("Hero Forge Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eHeroForge]);
			break;

#if HAS_TELEPORTATION_KEYRING
		case eItemContainerTeleportationKeyRingItems:
			ImGui::Text("Teleportation Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eTeleportationItem]);
			break;
#endif
#if HAS_ACTIVATED_ITEM_KEYRING
		case eItemContainerActivatedKeyRingItems:
			ImGui::Text("Activated Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eActivatedItem]);
			break;
#endif
#if HAS_EQUIPMENT_KEYRING
		case eItemContainerEquipmentKeyRingItems:
			ImGui::Text("Equipment Key Ring Max Capacity: %d (base)", pLocalPC->BaseKeyRingSlots[eEquipmentKeyRing]);
			break;
#endif
#endif // HAS_KEYRING_WINDOW

		// This case is just to remove warnings when all above cases are gated
		case eItemContainerInvalid:
		default: break;
		}

		ImGuiTableFlags tableFlags = ImGuiTableFlags_SizingFixedFit
			| ImGuiTableFlags_ScrollY
			| ImGuiTableFlags_BordersV
			| ImGuiTableFlags_BordersOuterH
			| ImGuiTableFlags_Resizable
			| ImGuiTableFlags_RowBg;

		if (!m_iconsTexture)
		{
			if (CTextureAnimation* tex = pSidlMgr->FindAnimation("A_DragItem"))
			{
				m_iconsTexture = std::make_unique<CTextureAnimation>(*tex);
			}
		}

		if (ImGui::BeginTable("##ItemTable", 6, tableFlags, ImGui::GetContentRegionAvail()))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn("Item", ImGuiTableColumnFlags_WidthStretch, -1.0f);
			ImGui::TableSetupColumn("##Icon", ImGuiTableColumnFlags_WidthFixed, -1.0f);
			ImGui::TableSetupColumn("Item Index", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableSetupColumn("Count", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableSetupColumn("RefCount", ImGuiTableColumnFlags_WidthFixed, 40.0f);
			ImGui::TableSetupColumn("##View", ImGuiTableColumnFlags_WidthFixed, 60.0f);
			ImGui::TableHeadersRow();

			ItemIndex cursor = pItemContainer->CreateItemIndex(0);

			for (const ItemPtr& pItem : *pItemContainer)
			{
				Draw_ItemRow(pItem, pItem->GetItemLocation());
			}

			ImGui::EndTable();
		}
	}

	void Draw_ItemRow(const ItemPtr& itemPtr, const ItemGlobalIndex & index)
	{
		if (!itemPtr) return;

		char szItemIndex[32];
		ImGui::TableNextRow();
		ImGui::PushID((void*)itemPtr.get());

		ImGui::TableNextColumn(); // name and tree node

		// If this item has childrent then we are a tree node.
		bool hasChildren = !itemPtr->IsEmpty();
		bool open = false;
		ImGuiTreeNodeFlags flags = 0;

		if (hasChildren)
		{
			open = ImGui::TreeNodeEx(itemPtr.get(), flags, "%s", itemPtr->GetName());
		}
		else
		{
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
			ImGui::TreeNodeEx(itemPtr.get(), flags, "%s", itemPtr->GetName());
		}

		ImGui::TableNextColumn(); // Item Name
		if (m_iconsTexture)
		{
			m_iconsTexture->SetCurCell(itemPtr->GetIconID() ? itemPtr->GetIconID() - 500 : 336);
			imgui::DrawTextureAnimation(m_iconsTexture.get(), CXSize(16, 16));
		}

		ImGui::TableNextColumn(); // ItemIndex
		if (index.IsValidIndex())
		{
			index.GetIndex().FormatItemIndex(szItemIndex, lengthof(szItemIndex));
			ImGui::Text("%s", szItemIndex);
		}

		ImGui::TableNextColumn(); // Item Count
		ImGui::Text("%d", itemPtr->GetItemCount());

		ImGui::TableNextColumn(); // Ref Count
		ImGui::Text("%d", itemPtr.use_count());

		ImGui::TableNextColumn(); // View
		if (ImGui::SmallButton("View"))
		{
			pItemDisplayManager->ShowItem(itemPtr);
		}

		if (open)
		{
			if (auto pChildContainer = itemPtr->GetChildItemContainer())
			{
				for (const ItemPtr& pItem : *pChildContainer)
				{
					Draw_ItemRow(pItem, pItem->GetItemLocation());
				}
			}

			ImGui::TreePop();
		}

		ImGui::PopID();
	}
};

ItemContainerInspector* s_itemContainerInspector = nullptr;

#pragma endregion

//----------------------------------------------------------------------------

static void Items_Initialize()
{
	s_invSlotInspector = new InvSlotInspector();
	DeveloperTools_RegisterMenuItem(s_invSlotInspector, "Inventory Slots", s_menuNameInspectors);

	s_itemContainerInspector = new ItemContainerInspector();
	DeveloperTools_RegisterMenuItem(s_itemContainerInspector, "Item Containers", s_menuNameInspectors);
}

static void Items_Shutdown()
{
	DeveloperTools_UnregisterMenuItem(s_invSlotInspector);
	delete s_invSlotInspector; s_invSlotInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_itemContainerInspector);
	delete s_itemContainerInspector; s_itemContainerInspector = nullptr;
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

static void Items_SetGameState(int gameState)
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
