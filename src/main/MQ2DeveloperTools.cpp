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

#include "imgui/ImGuiUtils.h"
#include "imgui/fonts/IconsFontAwesome.h"
#include "imgui/implot/implot.h"
#include "imgui/misc/cpp/imgui_stdlib.h"

#include <mq/imgui/Widgets.h>

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>

#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <imgui_internal.h>

using namespace std::chrono_literals;

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

PersistedBool::PersistedBool(std::string_view section, std::string_view key, bool init)
	: m_section(section)
	, m_key(key)
	, m_defaultValue(init)
	, m_value(init)
{
	Load();
}

void PersistedBool::Save()
{
	mq::WritePrivateProfileBool(m_section, m_key, m_value, mq::internal_paths::MQini);
	m_isLoaded = true;
}

void PersistedBool::Load()
{
	if (!mq::internal_paths::MQini.empty())
	{
		m_value = mq::GetPrivateProfileBool(m_section, m_key, m_defaultValue, mq::internal_paths::MQini);
		m_isLoaded = true;
	}
}

void PersistedBool::Update()
{
	if (mq::test_and_set(m_lastValue, m_value))
		Save();
}

class ImGuiWindowBase;
ImGuiWindowBase* s_imguiBaseWindows = nullptr;
ImGuiWindowBase* s_lastImguiBaseWindow = nullptr;

ImGuiWindowBase::ImGuiWindowBase(std::string_view windowId, std::string_view windowTitle)
	: m_open("Developer Tools", windowId)
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

ImGuiWindowBase::~ImGuiWindowBase()
{
	// Unlink from the chain
	if (m_next)
		m_next->m_prev = m_prev;
	if (m_prev)
		m_prev->m_next = m_next;
}

void ImGuiWindowBase::Update()
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

void ImGuiWindowBase::SetWindowTitle(std::string_view windowTitle)
{
	m_windowTitle = fmt::format("{}###{}", windowTitle, m_windowId);
}

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

#pragma region ImPlot Demo Container

class ImPlotDemoWindow : public ImGuiWindowBase
{
public:
	ImPlotDemoWindow() : ImGuiWindowBase("ImPlotDemoWindow") {}

	virtual void Update() override
	{
		if (m_open)
		{
			ImPlot::ShowDemoWindow(m_open.get_ptr());
			m_open.Update();
		}
	}
};
static ImPlotDemoWindow s_imPlotDemoWindow;

#pragma endregion

#pragma region Achievements Developer Tool

static const MQColor achGoldColor{ 248, 189, 33 };
static const MQColor achDarkGoldColor{ 176, 141, 66 };
static const MQColor achCheckMarkColor{ 24, 255, 41 };
static const MQColor achLightGoldColor{ 247, 220, 111 };
static const MQColor achLockedColor{ 255, 64, 64 };

class ImGuiAchievementViewer
{
	int m_instanceId = 0;
	int m_achievementId = -1;
	std::string m_windowDisplayName;
	std::string m_viewerTitle;
	bool m_needDock = true;
	bool m_needFocus = false;
	ImGuiID m_windowId = 0;

	std::unique_ptr<CTextureAnimation> m_iconsTexture;

	struct ComponentInfo {
		const AchievementComponent* component;
		bool completed = false;
	};
	std::vector<ComponentInfo> m_components;

public:
	ImGuiAchievementViewer()
	{
		static int nextInstanceId = 1;
		m_instanceId = nextInstanceId++;
	}

	void SetNeedDock(bool dock) { m_needDock = dock; }
	bool GetNeedDock() const { return m_needDock; }

	void SetNeedFocus(bool needFocus) { m_needFocus = needFocus; }
	const char* GetWindowIdStr() const { return m_viewerTitle.c_str(); }

	void SetAchievementId(int achievementId)
	{
		if (!test_and_set(m_achievementId, achievementId))
			return;

		m_needFocus = true;
		m_components.clear();

		if (m_achievementId >= 0)
		{
			const Achievement* ach = AchievementManager::Instance().GetAchievementById(m_achievementId);
			if (ach)
			{
				m_windowDisplayName = ach->name;
			}
			else
			{
				m_windowDisplayName = fmt::format("Achievement {}", m_achievementId);
			}

		}

		m_viewerTitle = fmt::format("{}###AchievementViewer{}", m_windowDisplayName, m_instanceId);
	}

	int GetAchievementId() const { return m_achievementId; }
	int GetInstanceId() const { return m_instanceId; }
	ImGuiID GetWindowId() const { return m_windowId; }

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
			if (m_windowId == 0)
				m_windowId = ImGui::GetCurrentWindow()->ID;

			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 9);

			DisplayAchievementData();
		}
		ImGui::End();

		return open;
	}

	static void AchDisplayComponent(bool indent, bool checked, const AchievementComponent& component)
	{
		ImGui::PushID(component.description.c_str());

		if (indent)
			ImGui::Indent();

		ImGui::PushStyleColor(ImGuiCol_Text, achDarkGoldColor.ToImU32());
		ImGui::PushStyleColor(ImGuiCol_CheckMark, achCheckMarkColor.ToImU32());
		ImGui::PushStyleColor(ImGuiCol_Border, achDarkGoldColor.ToImU32());
		ImGui::PushStyleColor(ImGuiCol_FrameBg, MQColor(0, 0, 0).ToImU32());
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4.0f, -1.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);

		bool hovered = false;

		ImGui::Checkbox("", &checked);
		if (ImGui::IsItemHovered())
			hovered = true;
		ImGui::SameLine();

		float widthAvail = ImGui::GetContentRegionAvailWidth();
		ImGui::PushTextWrapPos(widthAvail - 60.0f);
		ImGui::Text("%s", component.description.c_str());
		if (ImGui::IsItemHovered())
			hovered = true;
		ImGui::PopTextWrapPos();


		if (ImGui::BeginPopupContextItem("ComponentContextMenu"))
		{
			ImGui::TextColored(achGoldColor.ToImColor(), "%s", component.description.c_str());
			ImGui::Separator();
			ImGui::PushStyleColor(ImGuiCol_Text, MQColor(255, 255, 255).ToImU32());

			if (ImGui::Selectable("Copy ID"))
			{
				char idText[32];
				sprintf_s(idText, "%d", component.id);
				ImGui::SetClipboardText(idText);
			}
			if (ImGui::Selectable("Copy description"))
				ImGui::SetClipboardText(component.description.c_str());

			ImGui::PopStyleColor();
			ImGui::EndPopup();
		}

		if (component.requiredCount > 0)
		{
			ImGui::SameLine(widthAvail - 55.0f);
			ImGui::Text("%d / %d", component.count, component.requiredCount);
		}

		ImGui::PopStyleVar(2);
		ImGui::PopStyleColor(4);

		if (indent)
			ImGui::Unindent();

		if (hovered)
		{
			ImGui::BeginTooltip();

			ImGui::PushTextWrapPos(300.0f);
			ImGui::TextColored(achGoldColor.ToImColor(), "%s", component.description.c_str());

			ImGui::Separator();
			ImGui::TextColored(achLightGoldColor.ToImColor(), "Component ID: %d", component.id);
			ImGui::PopTextWrapPos();

			ImGui::EndTooltip();
		}

		ImGui::PopID();
	}

	void DisplayAchievementData()
	{
		if (!m_iconsTexture)
		{
			if (CTextureAnimation* tex = pSidlMgr->FindAnimation("A_DragItem"))
			{
				m_iconsTexture = std::make_unique<CTextureAnimation>(*tex);
			}
		}

		AchievementManager& mgr = AchievementManager::Instance();
		int achievementIndex = mgr.GetAchievementIndexById(m_achievementId);
		const Achievement* achievement = mgr.GetAchievementByIndex(achievementIndex);
		if (!achievement)
			return;

		const SingleAchievementAndComponentsInfo* info = mgr.GetAchievementClientInfoByIndex(achievementIndex);
		if (!info)
			return;

		bool showPopup = false;

		if (m_iconsTexture)
		{
			m_iconsTexture->SetCurCell(achievement->iconId > 0 ? achievement->iconId - 500 : 336);
			imgui::DrawTextureAnimation(m_iconsTexture.get());

			if (ImGui::IsMouseReleased(ImGuiMouseButton_Right) && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup))
				ImGui::OpenPopup("##AchievementPopup");
		}
		ImGui::PushFont(imgui::LargeTextFont);
		ImGui::SameLine();
		ImGui::Text("%s (%d Points)", achievement->name.c_str(), achievement->points);
		ImGui::PopFont();
		if (ImGui::IsMouseReleased(ImGuiMouseButton_Right) && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup))
			ImGui::OpenPopup("##AchievementPopup");
		ImGui::TextColored(achLightGoldColor.ToImColor(), "Achievement ID: %d", achievement->id);

		if (ImGui::BeginPopup("##AchievementPopup", ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings))
		{
			ImGui::TextColored(achGoldColor.ToImColor(), "%s", achievement->name.c_str());
			ImGui::Separator();

			if (ImGui::Selectable("Copy ID"))
			{
				char idText[32];
				sprintf_s(idText, "%d", achievement->id);
				ImGui::SetClipboardText(idText);
			}
			if (ImGui::Selectable("Copy name"))
				ImGui::SetClipboardText(achievement->name.c_str());

			ImGui::EndPopup();
		}

		ImGui::PushStyleColor(ImGuiCol_Text, achGoldColor.ToImU32());
		if (info->achievementState == AchievementComplete)
		{
			char completedTime[64];
			_ctime32_s(completedTime, 64, &info->completionTimestamp);

			ImGui::Text("Completed: %s", completedTime);
		}
		else if (info->achievementState == AchievementLocked)
		{
			ImGui::TextColored(achLockedColor.ToImColor(), "Locked");
		}
		else
		{
			ImGui::Text("Not Completed");
		}

		ImGui::TextWrapped("%s", achievement->description.c_str());

		ImGui::Separator();

		if (info->achievementState == AchievementLocked)
		{
			ImGui::Text("This achievement is locked because the following requirements are not met:");

			ImGui::PushID(AchievementComponentUnlock);
			for (int index = 0; index < achievement->componentsByType[AchievementComponentUnlock].GetCount(); ++index)
			{
				const AchievementComponent& component = achievement->componentsByType[AchievementComponentUnlock][index];
				AchDisplayComponent(false, info->IsComponentComplete(AchievementComponentUnlock, index), component);
			}
			ImGui::PopID();

			ImGui::Text("Once unlocked these are the requirements:");
		}

		// Now we list out the components
		if (m_components.empty())
		{
			// build list of components
			for (int index = 0; index < achievement->componentsByType[AchievementComponentCompletion].GetCount(); ++index)
			{
				const AchievementComponent& component = achievement->componentsByType[AchievementComponentCompletion][index];
				m_components.push_back({ &component, info->IsComponentComplete(AchievementComponentCompletion, index) });
			}
			for (int index = 0; index < achievement->componentsByType[AchievementComponentIndirect].GetCount(); ++index)
			{
				const AchievementComponent& component = achievement->componentsByType[AchievementComponentIndirect][index];
				m_components.push_back({ &component, info->IsComponentComplete(AchievementComponentIndirect, index) });
			}

			std::sort(m_components.begin(), m_components.end(),
				[](const auto& a, const auto& b) { return a.component->sequenceNum < b.component->sequenceNum; });
		}

		for (const ComponentInfo& componentInfo : m_components)
		{
			const AchievementComponent* component = componentInfo.component;
			bool completed = componentInfo.completed;

			AchDisplayComponent(component->type == AchievementComponentIndirect, completed, *component);
		}

		if (!achievement->componentsByType[AchievementComponentDisplay].empty())
		{
			ImGui::Text("Hidden display requirements:");

			// We aren't explicitly told if these conditions are met, but we can infer it by whether
			// the achievement is hidden or not.
			bool complete = (info->achievementState != AchievementNotVisible);
			ImGui::PushID(AchievementComponentDisplay);
			for (int index = 0; index < achievement->componentsByType[AchievementComponentDisplay].GetCount(); ++index)
			{
				const AchievementComponent& component = achievement->componentsByType[AchievementComponentDisplay][index];
				AchDisplayComponent(false, complete, component);
			}
			ImGui::PopID();
		}

		ImGui::PopStyleColor();
		ImGui::NewLine();

		if (ImGui::CollapsingHeader("Achievement Details"))
		{
			ImGui::Text("Version: %d", achievement->version);
			ImGui::Text("Persistent: %s", achievement->persistent ? "yes" : "no");
			ImGui::Text("Reward Set: %d", achievement->rewardSet);
			ImGui::Text("Unknown: %d", achievement->unknown0x60);

			ImGui::Separator();
			ImGui::Text("Components:");

			ImGui::Indent();
			for (int type = 0; type < AchievementComponentCount; ++type)
			{
				const AchievementComponentArray& componentArray = achievement->componentsByType[type];
				for (const AchievementComponent& component : componentArray)
				{
					ImGui::Text("Component String: %s", component.description.c_str());
					ImGui::Indent();
					switch (component.type)
					{
					case AchievementComponentUnlock: ImGui::TextUnformatted("Unlock Components"); break;
					case AchievementComponentCompletion: ImGui::TextUnformatted("Completion Components"); break;
					case AchievementComponentIndirect: ImGui::TextUnformatted("Indirect Components"); break;
					case AchievementComponentDisplay: ImGui::TextUnformatted("Display Components"); break;
					case AchievementComponentNone:
					default:
						ImGui::TextUnformatted("None"); break;
					}
					ImGui::Text("Component Id: %d", component.id);
					ImGui::Text("Sequence Num: %d", component.sequenceNum);
					ImGui::Text("Count: %d", component.count);
					ImGui::Text("Required Count: %d", component.requiredCount);
					
					ImGui::Unindent();
				}
			}
			ImGui::Unindent();

			ImGui::Separator();
			ImGui::Text("Component Status:");

			ImGui::Indent();
				ImGui::Text("Completion component status:");
				ImGui::Indent();
					for (int i = 0; i < info->completionComponentStatusBitField.GetNumBits(); ++i)
					{
						ImGui::Text("%d: %s", i, info->completionComponentStatusBitField.IsBitSet(i) ? "yes" : "no");
					}

				ImGui::Unindent();
				ImGui::Text("Indirect component Status:");
				ImGui::Indent();
					for (int i = 0; i < info->indirectComponentStatusBitField.GetNumBits(); ++i)
					{
						ImGui::Text("%d: %s", i, info->indirectComponentStatusBitField.IsBitSet(i) ? "yes" : "no");
					}

				ImGui::Unindent();
				ImGui::Text("Unlocked component Status:");
				ImGui::Indent();
					for (int i = 0; i < info->unlockedComponentStatusBitField.GetNumBits(); ++i)
					{
						ImGui::Text("%d: %s", i, info->unlockedComponentStatusBitField.IsBitSet(i) ? "yes" : "no");
					}

				ImGui::Unindent();
			ImGui::Unindent();
		}
	}
};

class AchievementsInspector : public ImGuiWindowBase
{
	std::vector<int> m_filteredAchievements;
	int m_selectedAchievementId = -1;
	int m_selectedAchivementCategoryId = -1;

	std::map<int, ImGuiAchievementViewer> m_viewers;
	ImGuiID m_topNode = 0;
	ImGuiID m_bottomNode = 0;
	bool m_firstTime = true;
	ImGuiID m_mainDockID = 0;
	bool m_selectionChanged = false;

	PersistedBool m_showCompleted{ "AchievementsInspector", "ShowCompleted", true };
	PersistedBool m_showOpen{ "AchievementsInspector", "ShowOpen", true };
	PersistedBool m_showLocked{ "AchievementsInspector", "ShowLocked", true };
	PersistedBool m_showHidden{ "AchievementsInspector", "ShowHidden", false };
	PersistedBool m_showCategories{ "AchievementsInspector", "ShowCategories", true };

public:
	AchievementsInspector() : ImGuiWindowBase("Achievements Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}
	~AchievementsInspector() {}

	void SetSelectedAchievementId(int achievementId)
	{
		if (test_and_set(m_selectedAchievementId, achievementId))
			m_selectionChanged = true;
		if (test_and_set(m_selectedAchivementCategoryId, -1))
			m_selectionChanged = true;
	}

	void SetSelectedAchievementCategoryId(int achievementCategoryId)
	{
		if (test_and_set(m_selectedAchievementId, -1))
			m_selectionChanged = true;
		if (test_and_set(m_selectedAchivementCategoryId, achievementCategoryId))
			m_selectionChanged = true;
	}

	void DrawAchievementTableRow(int achievementId, const AchievementManager& manager)
	{
		int achievementIndex = manager.GetAchievementIndexById(achievementId);
		if (const Achievement* achievement = manager.GetAchievementByIndex(achievementIndex))
		{
			AchievementState state = manager.GetAchievementStateByIndex(achievementIndex);
			if (state == AchievementComplete && !m_showCompleted)
				return;
			if (state == AchievementLocked && !m_showLocked)
				return;
			if (state == AchievementOpen && !m_showOpen)
				return;
			if (state == AchievementNotVisible && !m_showHidden)
				return;

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
			if (m_selectedAchievementId == achievementId)
				flags |= ImGuiTreeNodeFlags_Selected;

			if (state == AchievementComplete)
				ImGui::PushStyleColor(ImGuiCol_Text, achGoldColor.ToImU32());
			else if (state == AchievementLocked)
				ImGui::PushStyleColor(ImGuiCol_Text, achLockedColor.ToImU32());
			else if (state == AchievementNotVisible)
				ImGui::PushStyleColor(ImGuiCol_Text, MQColor(127, 127, 127).ToImU32());
			
			ImGui::TreeNodeEx((void*)achievementId, flags, "%s (%d Points)", achievement->name.c_str(), achievement->points);

			if (state == AchievementComplete || state == AchievementLocked || state == AchievementNotVisible)
				ImGui::PopStyleColor();

			if (ImGui::IsItemClicked())
			{
				if (ImGui::GetIO().KeyCtrl)
					ShowAchievementViewer(achievementId, true);
				else
					SetSelectedAchievementId(achievementId);
			}

			if (ImGui::BeginPopupContextItem())
			{
				ImGui::TextColored(achGoldColor.ToImColor(), "%s", achievement->name.c_str());
				ImGui::Separator();

				if (ImGui::Selectable("Open in new viewer"))
					ShowAchievementViewer(achievement->id, true);

				if (ImGui::Selectable("Copy ID"))
				{
					char idText[32];
					sprintf_s(idText, "%d", achievement->id);
					ImGui::SetClipboardText(idText);
				}
				if (ImGui::Selectable("Copy name"))
					ImGui::SetClipboardText(achievement->name.c_str());

				ImGui::EndPopup();
			}

			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();

				ImGui::PushTextWrapPos(300.0f);
				ImGui::TextColored(achGoldColor.ToImColor(), "%s", achievement->name.c_str());

				ImGui::Separator();
				ImGui::TextColored(achLightGoldColor.ToImColor(), "Achievement ID: %d", achievement->id);

				ImGui::Text("State:"); ImGui::SameLine(0.0f, 4.0f);
				switch (state)
				{
				case AchievementComplete: ImGui::Text("Completed"); break;
				case AchievementOpen: ImGui::Text("Open"); break;
				case AchievementLocked: ImGui::Text("Locked"); break;
				case AchievementNotVisible: ImGui::Text("Hidden"); break;
				case AchievementNone:
				default: ImGui::Text("None"); break;
				}

				ImGui::PopTextWrapPos();
				ImGui::EndTooltip();
			}

			ImGui::TableNextColumn();
			ImGui::Text("%s", achievement->description.c_str());

			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();

				ImGui::PushTextWrapPos(300.0f);
				ImGui::TextColored(achGoldColor.ToImColor(), "%s", achievement->name.c_str());

				ImGui::Separator();
				ImGui::TextColored(achLightGoldColor.ToImColor(), "Achievement ID: %d", achievement->id);

				ImGui::Text("%s", achievement->description.c_str());

				ImGui::PopTextWrapPos();
				ImGui::EndTooltip();
			}
		}
	}

	void DrawAchievementCategory(const AchievementCategory& category, const AchievementManager& manager)
	{
		ImGui::TableNextRow();

		ImGui::TableNextColumn();
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth;

		if (m_selectedAchivementCategoryId == category.id)
			flags |= ImGuiTreeNodeFlags_Selected;

		bool hovered = false;

		CTextureAnimation* tex = pSidlMgr->FindAnimation(category.bitmapId);
		if (tex)
		{
			flags |= ImGuiTreeNodeFlags_FramePadding;
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4.0f, (float)(tex->Size.cy / 2) - 8));
		}

		bool open = false;
		if (category.HasChildren() || category.GetAchievementCount() > 0)
		{
			open = ImGui::TreeNodeEx(&category, flags, "%s", tex ? "" : category.name.c_str());
		}
		else
		{
			flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
			ImGui::TreeNodeEx(&category, flags, "%s", tex ? "" : category.name.c_str());
		}

		if (ImGui::IsItemHovered())
			hovered = true;

		if (ImGui::BeginPopupContextItem())
		{
			ImGui::TextColored(achGoldColor.ToImColor(), "%s", category.name.c_str());
			ImGui::Separator();

			if (ImGui::Selectable("Copy ID"))
			{
				char idText[32];
				sprintf_s(idText, "%d", category.id);
				ImGui::SetClipboardText(idText);
			}
			if (ImGui::Selectable("Copy name"))
				ImGui::SetClipboardText(category.name.c_str());

			ImGui::EndPopup();
		}

		if (tex)
		{
			ImGui::PopStyleVar();

			ImGui::SameLine();
			imgui::DrawTextureAnimation(tex);
		}

		if (ImGui::IsItemHovered())
			hovered = true;

		if (ImGui::IsItemClicked())
		{
			SetSelectedAchievementCategoryId(category.id);
		}

		ImGui::TableNextColumn();
		ImGui::Text("%s", category.description.c_str());

		if (ImGui::IsItemHovered())
			hovered = true;

		if (hovered)
		{
			ImGui::BeginTooltip();

			ImGui::PushTextWrapPos(300.0f);
			ImGui::TextColored(achGoldColor.ToImColor(), "%s", category.name.c_str());

			ImGui::Separator();
			ImGui::TextColored(achLightGoldColor.ToImColor(), "Category ID: %d", category.id);
			ImGui::Text("Completed achievement score: %d", category.completedAchievementScore);

			int totalAchievements = category.completedAchievementCount + category.openAchievementCount + category.lockedAchievementCount;
			float completedPct = 0.0f;
			if (totalAchievements > 0)
				completedPct = 100.0f * ((float)category.completedAchievementCount / (float)totalAchievements);

			ImGui::Text("Completed achivements: %d / %d (%.2f%%)", category.completedAchievementCount, totalAchievements, completedPct);
			ImGui::PopTextWrapPos();

			ImGui::EndTooltip();
		}

		if (open)
		{
			for (int index = 0; index < category.GetChildrenCount(); ++index)
			{
				int categoryId = category.GetChildCategoryId(index);

				if (const AchievementCategory* childCategory = manager.GetAchievementCategoryById(categoryId))
				{
					DrawAchievementCategory(*childCategory, manager);
				}
			}

			for (int index = 0; index < category.GetAchievementCount(); ++index)
			{
				int achievementId = category.GetAchievementId(index);

				DrawAchievementTableRow(achievementId, manager);
			}

			ImGui::TreePop();
		}
	}

	void DrawCategoriesTable(const AchievementManager& achievements)
	{
		if (ImGui::BeginTable("##AchievementsTable", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Description", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			for (const AchievementCategory& cat : achievements.categories)
			{
				if (!cat.HasParent())
				{
					DrawAchievementCategory(cat, achievements);
				}
			}

			ImGui::EndTable();
		}
	}

	void DrawFilteredAchievements(const AchievementManager& manager, std::string_view searchFilter, bool updateFilter)
	{
		if (updateFilter || m_filteredAchievements.empty())
		{
			m_filteredAchievements.clear();

			std::vector<const Achievement*> achievements;

			for (int index = 0; index < manager.GetAchievementCount(); ++index)
			{
				const Achievement* achievement = manager.GetAchievementByIndex(index);
				AchievementState state = manager.GetAchievementStateByIndex(index);
				if (state == AchievementComplete && !m_showCompleted)
					continue;
				if (state == AchievementLocked && !m_showLocked)
					continue;
				if (state == AchievementOpen && !m_showOpen)
					continue;
				if (state == AchievementNotVisible && !m_showHidden)
					continue;

				if (searchFilter.empty() || ci_find_substr(achievement->name, searchFilter) != -1)
				{
					achievements.push_back(achievement);
				}
			}

			std::sort(std::begin(achievements), std::end(achievements),
				[&](const Achievement* idA, const Achievement* idB)
			{
				return ci_less()(idA->name, idB->name);
			});

			m_filteredAchievements.reserve(achievements.size());

			for (const Achievement* ach : achievements)
				m_filteredAchievements.push_back(ach->id);
		}

		if (ImGui::BeginTable("##AchievementsFilteredList", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Description", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGuiListClipper clipper;
			clipper.Begin((int)m_filteredAchievements.size());

			while (clipper.Step())
			{
				for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; ++row)
				{
					int achievementId = m_filteredAchievements[row];

					DrawAchievementTableRow(achievementId, manager);
				}
			}
			ImGui::EndTable();
		}
	}

	void DrawAchievementsInspectorWindow()
	{
		const AchievementManager& achievements = AchievementManager::Instance();

		static char szSearchFilter[256] = { 0 };
		ImGui::Text("Filter Achievements:"); ImGui::SameLine();
		ImGui::SetNextItemWidth(-51);
		bool changed = ImGui::InputText("##AchievementFilter", szSearchFilter, 256);
		ImGui::SameLine();
		if (ImGui::Button("Clear", ImVec2(50, 0)))
		{
			szSearchFilter[0] = 0;
			changed = true;
		}
		ImGui::Text("Show:"); ImGui::SameLine();
		if (ImGui::Checkbox("Categories", m_showCategories.get_ptr()))
			changed = true;
		ImGui::SameLine();
		if (ImGui::Checkbox("Open", m_showOpen.get_ptr()))
			changed = true;
		ImGui::SameLine();
		if (ImGui::Checkbox("Locked", m_showLocked.get_ptr()))
			changed = true;
		ImGui::SameLine();
		if (ImGui::Checkbox("Completed", m_showCompleted.get_ptr()))
			changed = true;
		ImGui::SameLine();
		if (ImGui::Checkbox("Hidden", m_showHidden.get_ptr()))
			changed = true;

		if (changed)
		{
			m_showCategories.Update();
			m_showOpen.Update();
			m_showLocked.Update();
			m_showCompleted.Update();
			m_showHidden.Update();
		}

		if (szSearchFilter[0] != 0 || !m_showCategories)
		{
			DrawFilteredAchievements(achievements, szSearchFilter, changed);
		}
		else
		{
			DrawCategoriesTable(achievements);
		}
	}

	virtual bool IsEnabled() const override
	{
		return GetPcProfile() != nullptr && GetGameState() == GAMESTATE_INGAME;
	}

	virtual void Update() override
	{
		if (m_mainDockID == 0)
		{
			m_mainDockID = ImGui::GetID("AchievementInspector");
		}

		if (!IsEnabled())
			return;

		ImGuiDockNode* node = ImGui::DockBuilderGetNode(m_mainDockID);
		if (!node || m_bottomNode == 0)
		{
			if (node)
			{
				ImGui::DockBuilderRemoveNodeChildNodes(m_mainDockID);
			}
			else
			{
				ImGui::DockBuilderRemoveNode(m_mainDockID);
				ImGui::DockBuilderAddNode(m_mainDockID, ImGuiDockNodeFlags_None);
				ImGui::DockBuilderSetNodeSize(m_mainDockID, ImVec2(480, 640));

				ImGuiViewport* viewport = ImGui::GetMainViewport();
				ImGui::DockBuilderSetNodePos(m_mainDockID, ImVec2(viewport->Pos.x + 100, viewport->Pos.y + 100));

				node = ImGui::DockBuilderGetNode(m_mainDockID);
			}

			ImGuiDockNode* topNode = nullptr;

			if (!node->IsSplitNode())
			{
				ImGui::DockBuilderSplitNode(m_mainDockID, ImGuiDir_Up, 0.5f, &m_topNode, &m_bottomNode);
				topNode = ImGui::DockBuilderGetNode(m_topNode);
			}
			else
			{
				topNode = node->ChildNodes[0];
				m_topNode = topNode->ID;
			}

			topNode->LocalFlags |= ImGuiDockNodeFlags_NoWindowMenuButton;

			ImGui::DockBuilderDockWindow("Achievements Inspector", m_topNode);
			ImGui::DockBuilderFinish(m_mainDockID);
		}

		if (m_open)
		{
			bool doShow = ImGui::Begin("Achievements Inspector", m_open.get_ptr());
			m_open.Update();
			if (doShow)
			{
				DrawAchievementsInspectorWindow();
			}

			ImGui::End();

			if (!m_open)
			{
				for (auto iter = m_viewers.begin(); iter != m_viewers.end();)
				{
					const auto& [_, viewer] = *iter;

					if (ImGuiWindow* window = ImGui::FindWindowByID(viewer.GetWindowId()))
					{
						if (window->DockId == m_bottomNode || window->DockId == m_topNode)
						{
							iter = m_viewers.erase(iter);
							continue;
						}
					}

					++iter;
				}
			}
		}

		if (m_selectionChanged)
		{
			if (m_selectedAchievementId != -1)
				ShowAchievementViewer(m_selectedAchievementId, false);

			m_selectionChanged = false;
		}

		DrawAchievementViewers();
	}

	void ShowAchievementViewer(int achievementId, bool createNew)
	{
		if (!createNew)
		{
			auto iter = std::find_if(std::begin(m_viewers), std::end(m_viewers),
				[achievementId](const auto& p) { return p.second.GetAchievementId() == achievementId; });
			if (iter != m_viewers.end())
			{
				iter->second.SetNeedFocus(true);
				return;
			}

			// don't create new. Reuse the currently selected window (which is it?)
			if (ImGuiDockNode* node = ImGui::DockBuilderGetNode(m_bottomNode))
			{
				ImGuiID selectedTabId = node->SelectedTabId;

				iter = std::find_if(std::begin(m_viewers), std::end(m_viewers),
					[selectedTabId](const auto& p) { return p.second.GetWindowId() == selectedTabId; });
				if (iter != m_viewers.end())
				{
					iter->second.SetAchievementId(achievementId);
					return;
				}
			}
		}

		auto [iter, _] = m_viewers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(achievementId),
			std::forward_as_tuple());
		iter->second.SetAchievementId(achievementId);
	}

	void RemoveAchievementViewers(int achievementId)
	{
		m_viewers.erase(achievementId);
	}

	void DrawAchievementViewers()
	{
		for (auto iter = m_viewers.begin(); iter != m_viewers.end();)
		{
			if (iter->second.GetNeedDock())
			{
				ImGui::DockBuilderDockWindow(iter->second.GetWindowIdStr(), m_bottomNode);
				iter->second.SetNeedDock(false);
			}

			if (!iter->second.Draw())
			{
				iter = m_viewers.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
};
static AchievementsInspector* s_achievementsInspector = nullptr;

#pragma endregion

#pragma region Spells Developer Tool

class SpellsInspector : public ImGuiWindowBase
{
	CTextureAnimation* m_pTASpellIcon = nullptr;
public:
	SpellsInspector() : ImGuiWindowBase("Spells Developer Tools") {}

	~SpellsInspector()
	{
		if (m_pTASpellIcon)
		{
			delete m_pTASpellIcon;
			m_pTASpellIcon = nullptr;
		}
	}

	void DoSpellBuffTableHeaders()
	{
		ImGui::TableSetupColumn("Index", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Icon", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Level", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Duration", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("InitialDuration", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("HitCount", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("ChargesRemaining", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("ViralTimer", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Flags", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Modifier", ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		ImGui::TableSetupColumn("Activatable", ImGuiTableColumnFlags_WidthAlwaysAutoResize);

		for (int i = 0; i < NUM_SLOTDATA; ++i)
		{
			char temp[20];
			sprintf_s(temp, "Slot%d", i);
			ImGui::TableSetupColumn(temp, ImGuiTableColumnFlags_WidthAlwaysAutoResize);
		}

		ImGui::TableHeadersRow();
	}

	void DoSpellBuffTableRow(int index, EQ_Affect& buff)
	{
		EQ_Spell* spell = GetSpellByID(buff.SpellID);
		if (!spell)
			return;

		if (!m_pTASpellIcon)
		{
			m_pTASpellIcon = new CTextureAnimation();
			if (CTextureAnimation* temp = pSidlMgr->FindAnimation("A_SpellGems"))
				*m_pTASpellIcon = *temp;
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		// Index
		ImGui::Text("%d", index);

		// Icon
		ImGui::TableNextColumn();
		m_pTASpellIcon->SetCurCell(spell->SpellIcon);
		imgui::DrawTextureAnimation(m_pTASpellIcon);
		//m_pTASpellIcon->SetCurCell(spell->GemIcon);
		//RenderTextureAnimation(m_pTASpellIcon);
		//m_pTASpellIcon->SetCurCell(spell->BookIcon);
		//RenderTextureAnimation(m_pTASpellIcon);

		// Name
		ImGui::TableNextColumn();
		if (spell)
		{
			ImGui::Text("%s", spell->Name);
		}
		else
		{
			ImGui::Text("null");
		}

		// ID
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.SpellID);

		// Level
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.Level);

		// Duration
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.Duration);

		// InitialDuration
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.InitialDuration);

		// HitCount
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.HitCount);

		// Type
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.Type);

		// ChargesRemaining
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.ChargesRemaining);

		// ViralTimer
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.ViralTimer);

		// Flags
		ImGui::TableNextColumn();
		ImGui::Text("%x", buff.Flags);

		// Modifier
		ImGui::TableNextColumn();
		ImGui::Text("%.2f", buff.Modifier);

		// Activatable
		ImGui::TableNextColumn();
		ImGui::Text("%d", buff.Activatable);

		// SlotData[0]
		for (auto& slotData : buff.SlotData)
		{
			ImGui::TableNextColumn();

			int Slot = slotData.Slot;
			int Value = slotData.Value;

			if (Slot != -1)
				ImGui::Text("%d: %d", Slot, Value);
		}
	}

	int DoSpellAffectTable(const char* name, EQ_Affect* affect, int numAffects, bool showEmpty = false)
	{
		ImGuiTableFlags tableFlags = 0
			| ImGuiTableFlags_SizingPolicyFixedX
			| ImGuiTableFlags_Scroll
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

		if (ImGui::BeginTable(name, 17 + NUM_SLOTDATA, tableFlags, size))
		{
			ImGui::TableSetupScrollFreeze(2, 1);
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
					true, -1, affectToPass ? affectToPass : nullptr, affectToPass ? 1 : 0);

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
static SpellsInspector* s_spellsInspector = nullptr;

#pragma endregion

#pragma region Benchmarks Developer Tool

struct ScrollingData
{
	int MaxSize = 4096;
	int Offset = 0;
	ImVector<ImVec2> Data;
	std::string Name;
	bool Updated = false;

	ScrollingData()
	{
		Data.reserve(MaxSize);
	}

	void AddPoint(float x, float y)
	{
		if (Data.size() < MaxSize)
			Data.push_back(ImVec2(x, y));
		else
		{
			Data[Offset] = ImVec2(x, y);
			Offset = (Offset + 1) % MaxSize;
		}
	}
	void Erase()
	{
		if (!Data.empty())
		{
			Data.shrink(0);
			Offset = 0;
		}
	}
};

extern float gCurrentFPS;
extern float gCurrentCPU;

class BenchmarksInspector : public ImGuiWindowBase
{
public:
	BenchmarksInspector() : ImGuiWindowBase("Benchmarks")
	{
	}

	void ResetLastTimes()
	{
		// Reset last times
		for (auto& bm : gBenchmarks)
		{
			if (bm != nullptr)
				bm->LastTime = std::chrono::microseconds::zero();
		}
	}

	virtual void Show() override
	{
		m_resetNext = true;
		ImGuiWindowBase::Show();
	}

	virtual void Draw() override
	{
		if (m_resetNext)
		{
			ResetLastTimes();
			m_resetNext = false;
		}
		//ImGui::SetNextTreeNodeOpen(true, ImGuiCond_Once);
		//if (ImGui::CollapsingHeader("Benchmark Plot"))
		{
			DrawPlot();
		}

		//if (ImGui::CollapsingHeader("Benchmark Table"))
		//{
		//	DrawTable();
		//}

		ResetLastTimes();
	}

	void DrawPlot()
	{
		ImGui::SliderFloat("History", &m_history, 10.0f, 120.0f, "%.1f s");

		ImGui::SameLine();
		if (ImGui::Button("Clear"))
		{
			m_data.clear();
			m_fpsData.Erase();
			m_cpuData.Erase();
		}
		ImGui::SameLine();
		if (ImGui::Button(m_paused ? "Resume" : "Pause"))
			m_paused = !m_paused;

		if (!m_paused)
		{
			m_time += ImGui::GetIO().DeltaTime;

			// mark everything fresh
			for (const auto& p : m_data)
				p.second->Updated = false;

			for (const auto& bm : gBenchmarks)
			{
				if (bm == nullptr)
					continue;

				ScrollingData* data = nullptr;

				auto iter = m_data.find(bm->Name);
				if (iter == m_data.end())
				{
					auto pData = std::make_unique<ScrollingData>();
					pData->Name = bm->Name;
					data = pData.get();

					m_data.emplace(bm->Name, std::move(pData));
				}
				else
				{
					data = iter->second.get();
				}

				data->AddPoint(m_time, static_cast<float>(bm->LastTime.count()) / 1000.f);
				data->Updated = true;
			}

			// erase everything not updated
			for (auto iter = m_data.begin(); iter != m_data.end();)
			{
				if (iter->second->Updated)
					++iter;
				else
					iter = m_data.erase(iter);
			}
			auto now = std::chrono::steady_clock::now();
			if (now - m_lastUpdate > 50ms)
			{
				m_fpsData.AddPoint(m_time, gCurrentFPS);
				m_cpuData.AddPoint(m_time, gCurrentCPU);

				m_lastUpdate = now;
			}
		}

		ImPlot::SetNextPlotLimitsX(static_cast<double>(m_time) - m_history, m_time, ImGuiCond_Always);
		ImPlot::SetNextPlotLimitsY(0, 20, ImGuiCond_Once, 0);
		ImPlot::SetNextPlotLimitsY(0, 100, ImGuiCond_Always, 1);

		static int rt_axis = ImPlotAxisFlags_Default;

		if (ImPlot::BeginPlot("##Benchmarks", "Time", "Milliseconds", ImVec2(-1, -1), ImPlotFlags_Default | ImPlotFlags_YAxis2,
			rt_axis, rt_axis | ImPlotAxisFlags_LockMin, ImPlotAxisFlags_LockMin | ImPlotAxisFlags_TickLabels))
		{
			ImPlot::SetPlotYAxis(0);

			for (const auto& p : m_data)
			{
				auto& data = p.second;

				ImPlot::PlotLine(data->Name.c_str(), &data->Data[0], data->Data.size(), data->Offset);
			}

			if (!m_fpsData.Data.empty())
			{
				ImPlot::SetPlotYAxis(1);
				ImPlot::PushStyleColor(ImPlotCol_Line, IM_COL32(127, 255, 0, 255));
				ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, 2);
				ImPlot::PlotLine("Frame Rate", &m_fpsData.Data[0], m_fpsData.Data.size(), m_fpsData.Offset);
				ImPlot::PopStyleVar();
				ImPlot::PopStyleColor();
			}

			if (!m_cpuData.Data.empty())
			{
				ImPlot::SetPlotYAxis(1);
				ImPlot::PushStyleColor(ImPlotCol_Line, IM_COL32(127, 127, 255, 255));
				ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, 2);
				ImPlot::PlotLine("CPU Usage %", &m_cpuData.Data[0], m_cpuData.Data.size(), m_cpuData.Offset);
				ImPlot::PopStyleVar();
				ImPlot::PopStyleColor();
			}

			ImPlot::EndPlot();
		}
	}

	void DrawTable()
	{
		if (ImGui::BeginTable("##BenchmarksTable", 4))
		{
			ImGui::TableSetupColumn("Name");
			ImGui::TableSetupColumn("Count");
			ImGui::TableSetupColumn("Total");
			ImGui::TableSetupColumn("Last");
			ImGui::TableHeadersRow();

			for (const auto& bm : gBenchmarks)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				ImGui::Text(bm->Name.c_str()); ImGui::TableNextColumn();
				ImGui::Text("%d", bm->Count); ImGui::TableNextColumn();
				ImGui::Text("%.3f ms", static_cast<float>(bm->TotalTime.count() / 1000.f)); ImGui::TableNextColumn();
				ImGui::Text("%.3f ms", static_cast<float>(bm->LastTime.count() / 1000.f));
			}

			ImGui::EndTable();
		}
	}

private:
	std::map<std::string, std::unique_ptr<ScrollingData>> m_data;
	float m_history = 30.0f; // 30 seconds
	float m_time = 0.0f;
	std::chrono::steady_clock::time_point m_lastUpdate;
	bool m_paused = false;
	bool m_resetNext = true;

	ScrollingData m_fpsData;
	ScrollingData m_cpuData;
};
static BenchmarksInspector* s_benchmarksInspector = nullptr;

#pragma endregion

#pragma region String Inspector

class StringInspector : public ImGuiWindowBase
{
public:
	StringInspector() : ImGuiWindowBase("String Inspector")
	{
	}

	~StringInspector()
	{
	}

protected:
	void Draw() override
	{
		ImGui::LabelText("StrRep Allocations", "%d", eqlib::internal::gStrRepAllocations);
		ImGui::LabelText("StrRep Live Objects", "%d", eqlib::internal::gStrRepLiveObjects);

		ImGui::Text("CXStr FreeLists:");

		eqlib::internal::LockCXStrMutex();
		CXFreeList* freeList = eqlib::internal::GetCXFreeList();
		if (freeList)
		{
			if (ImGui::BeginTable("##CXFreeListTable", 2))
			{
				ImGui::TableSetupColumn("Block Size");
				ImGui::TableSetupColumn("Count");
				ImGui::TableHeadersRow();

				while (freeList->blockSize > 0)
				{
					ImGui::TableNextRow();

					ImGui::TableNextColumn();
					ImGui::Text("%d", freeList->blockSize);

					size_t count = 0;
					CStrRep* rep = freeList->repList;
					while (rep)
					{
						++count;
						rep = rep->next;
					}

					ImGui::TableNextColumn();
					ImGui::Text("%d", count);

					++freeList;
				}

				ImGui::EndTable();
			}
		}
		else
		{
			ImGui::Text("<no freelist>");
		}

		eqlib::internal::UnlockCXStrMutex();
	}
};
static StringInspector* s_stringInspector = nullptr;

#pragma endregion

#pragma region Macro Expression Evaluator

class MacroExpressionEvaluator : public ImGuiWindowBase
{
	using CharBuffer = std::unique_ptr<char[]>;
public:
	MacroExpressionEvaluator() : ImGuiWindowBase("Macro Expression Evaluator")
	{
		SetDefaultSize(ImVec2(480, 60));
	}

	~MacroExpressionEvaluator()
	{
	}

protected:
	// Seems to be crashing MQ2Overlay when done from login window. Need to figure out why...
	virtual bool IsEnabled() const override
	{
		return GetGameState() == GAMESTATE_CHARSELECT
			|| GetGameState() == GAMESTATE_INGAME;
	}

	void Draw() override
	{
		int deleteRow = -1;
		for (size_t i = 0; i < m_expressions.size(); ++i)
		{
			ImGui::PushID(i);
			ImGui::SetNextItemWidth(-20);
			ImGui::InputText("##Expression", m_expressions[i].get(), MAX_STRING);
			ImGui::SameLine();
			if (ImGui::Button("X"))
				deleteRow = i;

			// Evaluate the row
			static char szTemp[MAX_STRING];
			strcpy_s(szTemp, m_expressions[i].get());
			ParseMacroParameter(nullptr, szTemp);

			ImGui::Text("%s", szTemp);
			ImGui::Separator();

			ImGui::PopID();
		}
		if (deleteRow != -1)
			m_expressions.erase(m_expressions.begin() + deleteRow);
		if (ImGui::Button("Add"))
		{
			auto buf = std::make_unique<char[]>(MAX_STRING);
			buf[0] = 0;

			m_expressions.push_back(std::move(buf));
		}
	}

private:
	std::vector<CharBuffer> m_expressions;
};

static MacroExpressionEvaluator* s_macroEvaluator = nullptr;


#pragma endregion

//============================================================================
//============================================================================

struct WindowMenuEntry
{
	ImGuiWindowBase* window;
	std::string menuName;
	std::string itemName;
};
static std::vector<WindowMenuEntry> s_inspectorMenus;
static bool s_inspectorMenusDirty = false;

void DeveloperTools_DrawMenu()
{
	if (ImGui::BeginMenu("Windows"))
	{
		ImGui::Separator();

		if (ImGui::MenuItem("ImGui Demo", nullptr, s_demoWindow.IsOpen()))
			s_demoWindow.Toggle();
		if (ImGui::MenuItem("ImPlot Demo", nullptr, s_imPlotDemoWindow.IsOpen()))
			s_imPlotDemoWindow.Toggle();

		ImGui::EndMenu();
	}

	if (s_inspectorMenusDirty)
	{
		std::sort(s_inspectorMenus.begin(), s_inspectorMenus.end(),
			[](const auto& l, const auto& r)
		{
			return std::tie(l.menuName, l.itemName) < std::tie(r.menuName, r.itemName);
		});
	}

	bool isMenuOpen = false;
	const std::string* lastMenu = nullptr;

	for (const auto& entry : s_inspectorMenus)
	{
		if (!lastMenu || *lastMenu != entry.menuName)
		{
			if (lastMenu && isMenuOpen)
				ImGui::EndMenu();

			isMenuOpen = ImGui::BeginMenu(entry.menuName.c_str());
			lastMenu = &entry.menuName;
		}

		if (isMenuOpen)
		{
			if (ImGui::MenuItem(entry.itemName.c_str(), nullptr, entry.window->IsOpen()))
				entry.window->Toggle();
		}
	}

	if (lastMenu && isMenuOpen)
	{
		ImGui::EndMenu();
	}
}

void DeveloperTools_RegisterMenuItem(ImGuiWindowBase* window, const char* itemName, const char* menuName)
{
	s_inspectorMenus.push_back(WindowMenuEntry{ window, menuName ? menuName : "Tools", itemName });

	s_inspectorMenusDirty = true;
}

void DeveloperTools_UnregisterMenuItem(ImGuiWindowBase* window)
{
	s_inspectorMenus.erase(
		std::remove_if(std::begin(s_inspectorMenus), std::end(s_inspectorMenus),
			[&](const auto& p) { return p.window == window; }),
		std::end(s_inspectorMenus));
}

//============================================================================

void DeveloperTools_WindowInspector_Initialize();
void DeveloperTools_WindowInspector_Shutdown();
void DeveloperTools_WindowInspector_SetGameState(uint32_t gameState);

static void DeveloperTools_Initialize()
{
	s_benchmarksInspector = new BenchmarksInspector();
	DeveloperTools_RegisterMenuItem(s_benchmarksInspector, "Benchmarks", s_menuNameInspectors);

	s_achievementsInspector = new AchievementsInspector();
	DeveloperTools_RegisterMenuItem(s_achievementsInspector, "Achievements", s_menuNameInspectors);

	s_spellsInspector = new SpellsInspector();
	DeveloperTools_RegisterMenuItem(s_spellsInspector, "Spells", s_menuNameInspectors);

	s_stringInspector = new StringInspector();
	DeveloperTools_RegisterMenuItem(s_stringInspector, "CXStr Metrics", s_menuNameInspectors);

	s_macroEvaluator = new MacroExpressionEvaluator();
	DeveloperTools_RegisterMenuItem(s_macroEvaluator, "Macro Expression Evaluator", s_menuNameTools);

	DeveloperTools_WindowInspector_Initialize();
}

static void DeveloperTools_Shutdown()
{
	DeveloperTools_UnregisterMenuItem(s_benchmarksInspector);
	delete s_benchmarksInspector; s_benchmarksInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_achievementsInspector);
	delete s_achievementsInspector; s_achievementsInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_spellsInspector);
	delete s_spellsInspector; s_spellsInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_stringInspector);
	delete s_stringInspector; s_stringInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_macroEvaluator);
	delete s_macroEvaluator; s_macroEvaluator = nullptr;

	DeveloperTools_WindowInspector_Shutdown();
}

static void DeveloperTools_SetGameState(DWORD gameState)
{
	DeveloperTools_WindowInspector_SetGameState(gameState);
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
