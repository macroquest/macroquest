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

#include "imgui/ImGuiUtils.h"
#include "imgui/fonts/IconsFontAwesome.h"
#include "imgui/implot/implot.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "imgui/imgui_internal.h"
#include "mq/imgui/Widgets.h"

#include "fmt/format.h"
#include "fmt/ranges.h"
#include "glm/glm.hpp"
#include "spdlog/spdlog.h"

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <cfenv>
#include <cinttypes>

using namespace std::chrono_literals;

namespace mq {

static void DeveloperTools_Initialize();
static void DeveloperTools_Shutdown();
static void DeveloperTools_SetGameState(int gameState);
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

extern std::vector<std::unique_ptr<MQBenchmark>> gBenchmarks;

static inline void  TreeAdvanceToLabelPos() { ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetTreeNodeToLabelSpacing()); }

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

		float widthAvail = ImGui::GetContentRegionAvail().x;
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
			eq_ctime(completedTime, 64, &info->completionTimestamp);

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
			ImGui::Text("Reward Set: %d", achievement->rewardSet);
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TOL)
			ImGui::Text("Unknown1: %d", achievement->unknown1);
			ImGui::Text("Unknown2: %d", achievement->unknown2);
#endif

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
	int m_selectedAchievementCategoryId = -1;

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
		if (test_and_set(m_selectedAchievementCategoryId, -1))
			m_selectionChanged = true;
	}

	void SetSelectedAchievementCategoryId(int achievementCategoryId)
	{
		if (test_and_set(m_selectedAchievementId, -1))
			m_selectionChanged = true;
		if (test_and_set(m_selectedAchievementCategoryId, achievementCategoryId))
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

#pragma warning(suppress : 4312)
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

		if (m_selectedAchievementCategoryId == category.id)
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

			ImGui::Text("Completed achievements: %d / %d (%.2f%%)", category.completedAchievementCount, totalAchievements, completedPct);
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

#pragma region Alt Ability Inspector

class AltAbilityInspector : public ImGuiWindowBase
{
	CAltAbilityData* m_selectedAbility = nullptr;
	bool m_foundSelected = false;
	bool m_showVisible = true;
	char m_searchText[256] = { 0 };

public:
	AltAbilityInspector() : ImGuiWindowBase("Alt Abilities Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~AltAbilityInspector()
	{
	}

	bool IsEnabled() const override
	{
		return GetPcProfile() != nullptr && GetGameState() == GAMESTATE_INGAME && pAltAdvManager != nullptr;
	}

	void Update() override
	{
		if (!IsEnabled())
		{
			// Clear cached data
			m_selectedAbility = nullptr;
		}

		ImGuiWindowBase::Update();
	}

	void DrawAltAbilityTableRow(CAltAbilityData* altAbility)
	{
		DatabaseStringTable* dbStr = pDBStr;

		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		const char* AAName = dbStr->GetString(altAbility->nName, eAltAbilityName);
		if (!AAName)
			AAName = "Unknown";

		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
		if (m_selectedAbility == altAbility)
			flags |= ImGuiTreeNodeFlags_Selected;

		ImGui::TreeNodeEx((void*)altAbility, flags, "%s", AAName);

		if (ImGui::IsItemClicked())
		{
			m_selectedAbility = altAbility;
		}

		ImGui::TableNextColumn();
		if (altAbility->DisplayCategory > 0)
		{
			if (const char* CategoryName = dbStr->GetString(altAbility->DisplayCategory, eAltAbilityCategory))
			{
				ImGui::Text("%s (%d)", CategoryName, altAbility->DisplayCategory);
			}
			else
			{
				ImGui::Text("UNKNOWN (%d)", altAbility->DisplayCategory);
			}
		}
		else
		{
			if (const char* CategoryName = dbStr->GetString(altAbility->Expansion, eExpansionName))
			{
				ImGui::Text("%s (%d)", CategoryName, altAbility->Expansion);
			}
			else
			{
				ImGui::Text("UNKNOWN (%d)", altAbility->Expansion);
			}
		}

		ImGui::TableNextColumn();
		if (const char* AADescription = dbStr->GetString(altAbility->nDesc, eAltAbilityDescription))
		{
			ImGui::Text("%s", AADescription);
		}
	}

	void DrawPlayerAbilities()
	{
		ImVec2 size(0, 0);
		if (m_selectedAbility)
			size.y = 400;

		CAltAbilityData* nextSelection = nullptr;

		ImGui::Checkbox("Show Visible Only", &m_showVisible);

		ImGui::Text("Search: ");
	
		ImGui::InputText("##AASearchText", m_searchText, 256);

		if (ImGui::BeginTable("##AltAbilityTable", 3, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY, size))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Category");
			ImGui::TableSetupColumn("Description");
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			// Range-based For loop isn't working here for some reason. Need to figure it out.
			const auto& abilities = *pAltAdvManager->abilities;
			m_foundSelected = false;

			CAltAbilityData** ppAltAbility = abilities.WalkFirst();
			while (ppAltAbility)
			{
				CAltAbilityData* altAbility = *ppAltAbility;
				if (!m_showVisible || pAltAdvManager->CanSeeAbility(pLocalPC, altAbility))
				{
					if (!m_searchText[0] ||
							ci_find_substr(altAbility->GetNameString(), m_searchText) != -1 ||
							ci_find_substr(altAbility->GetCategoryString(), m_searchText) != -1 ||
							ci_find_substr(altAbility->GetDescriptionString(), m_searchText) != -1 ||
							ci_find_substr(altAbility->GetExpansionString(), m_searchText) != -1)
					{
						DrawAltAbilityTableRow(altAbility);
					}
				}

				if (altAbility == m_selectedAbility)
					m_foundSelected = true;

				ppAltAbility = abilities.WalkNext(ppAltAbility);
			}

			if (!m_foundSelected)
			{
				m_selectedAbility = nullptr;
			}

			ImGui::EndTable();
		}

		if (m_selectedAbility)
		{
			if (ImGui::BeginChild("##AltAbilityDisplay"))
			{
				ImGui::Text("Name: %s", pDBStr->GetString(m_selectedAbility->nName, eAltAbilityName));
				ImGui::Text("ID: %d", m_selectedAbility->Index);
				ImGui::TextWrapped("Description: %s", m_selectedAbility->GetDescriptionString());
				ImGui::Text("Expansion: %s", m_selectedAbility->GetExpansionString());
				ImGui::Text("Category: %s", m_selectedAbility->GetCategoryString());

				if (m_selectedAbility->nShortName != -1)
					ImGui::Text("Button 1: %s", m_selectedAbility->GetShortName1());
				if (m_selectedAbility->nShortName2 != -1)
					ImGui::Text("Button 2: %s", m_selectedAbility->GetShortName2());

				ImGui::Text("Level Requirement: %d", m_selectedAbility->MinLevel);
				ImGui::Text("Cost: %d", m_selectedAbility->Cost);
				ImGui::Text("Group ID: %d", m_selectedAbility->GroupID);
				ImGui::Text("Group Level: %d", m_selectedAbility->CurrentRank);
				ImGui::Text("Type: %d", m_selectedAbility->Type);
				ImGui::Text("Spell ID: %d", m_selectedAbility->SpellID);
				if (m_selectedAbility->bRefund)
					ImGui::Text("Refund: %d", m_selectedAbility->bRefund);

				if (!m_selectedAbility->RequiredGroups.empty() && (m_selectedAbility->RequiredGroups.size() > 1 || m_selectedAbility->RequiredGroups[0] != 0))
				{
					ImGui::Separator();
					ImGui::Text("Group Requirements:");
					for (int i = 0; i < (int)m_selectedAbility->RequiredGroups.size(); ++i)
					{
						int groupId = m_selectedAbility->RequiredGroups[i];
						int groupRank = m_selectedAbility->RequiredGroupLevels[i];

						if (groupRank != 0 && groupId != 0)
						{
							CAltAbilityData* pFoundRequirement = nullptr;

							// Find something with that group id
							for (CAltAbilityData** pRequirement = pAltAdvManager->abilities->WalkFirst();
								pRequirement != nullptr; pRequirement = pAltAdvManager->abilities->WalkNext(pRequirement))
							{
								if ((*pRequirement)->ID == groupId)
								{
									pFoundRequirement = *pRequirement;
									break;
								}
							}

							if (pFoundRequirement)
							{
								ImGui::Text("%s (%d): Rank %d", pDBStr->GetString(pFoundRequirement->nName, eAltAbilityName),
									groupId, groupRank);
								ImGui::SameLine();
								if (ImGui::Button("View"))
								{
									nextSelection = pFoundRequirement;
								}
							}
							else
							{
								ImGui::Text("Unknown (%d): Rank %d", groupId, groupRank);
							}
						}
					}
				}

				if (!m_selectedAbility->TimerIds.empty() && (m_selectedAbility->TimerIds.size() > 1 || m_selectedAbility->TimerIds[0] != 0))
				{
					ImGui::Separator();
					ImGui::Text("Timers:");

					for (int i : m_selectedAbility->TimerIds)
					{
						if (i > 0)
							ImGui::Text("%d", i);
					}
				}

				ImGui::Separator();

				ImGui::Text("Reuse Timer: %d", m_selectedAbility->ReuseTimer);

				char szClasses[256] = { 0 };
				for (int classIndex = Warrior; classIndex <= Berserker; ++classIndex)
				{
					if ((m_selectedAbility->Classes & (1 << classIndex)) != 0)
					{
						if (szClasses[0] != 0)
							strcat_s(szClasses, ", ");
						strcat_s(szClasses, ClassInfo[classIndex].UCShortName);
					}
				}
				ImGui::Text("Usable Classes: %s", szClasses);

				ImGui::Text("Max Rank: %d", m_selectedAbility->MaxRank);
				ImGui::Text("Total Points: %d", m_selectedAbility->TotalPoints);

				if (m_selectedAbility->PreviousGroupAbilityId != -1)
				{
					CAltAbilityData* previousAbility = pAltAdvManager->GetAAById(m_selectedAbility->PreviousGroupAbilityId);
					if (previousAbility)
					{
						ImGui::Text("Previous Ability:"); ImGui::SameLine();

						char szName[256];
						sprintf_s(szName, "%s (%d)", pDBStr->GetString(previousAbility->nName, eAltAbilityName), previousAbility->Index);
						if (ImGui::Button(szName))
						{
							nextSelection = previousAbility;
						}
					}
				}

				if (m_selectedAbility->NextGroupAbilityId != -1)
				{
					CAltAbilityData* nextAbility = pAltAdvManager->GetAAById(m_selectedAbility->NextGroupAbilityId);
					if (nextAbility)
					{
						ImGui::Text("Next Ability:"); ImGui::SameLine();

						char szName[256];
						sprintf_s(szName, "%s (%d)", pDBStr->GetString(nextAbility->nName, eAltAbilityName), nextAbility->Index);
						if (ImGui::Button(szName))
						{
							nextSelection = nextAbility;
						}
					}
				}

				ImGui::Text("Quest: %s", m_selectedAbility->QuestOnly ? "Yes" : "No");
				ImGui::Text("Charges: %d", m_selectedAbility->Charges);
				ImGui::Text("Ignored De-level: %s", m_selectedAbility->bIgnoreDeLevel ? "Yes" : "No");
				ImGui::Text("AutoGrant: %s", m_selectedAbility->bAutogrant ? "Yes" : "No");

				if (!m_selectedAbility->PersistentEffects.empty())
				{
					ImGui::Separator();
					ImGui::Text("Persistent Effects:");
					for (const AltAbilityEffectData& data : m_selectedAbility->PersistentEffects)
					{
						ImGui::Text("Attrib=%d Base1=%d Base2=%d Slot=%d",
							data.effectType, data.baseEffect1, data.baseEffect2, data.slot);
					}
				}
			}

			ImGui::EndChild();
		}

		if (nextSelection)
			m_selectedAbility = nextSelection;
	}

#if HAS_MERCENARY_AA
	void DrawMercenaryAbilityRow(const MercenaryAbilitiesData* mercData, const char* szLabel = nullptr,
		bool colorCanTrain = false)
	{
		auto& data = MercenaryAlternateAdvancementManagerClient::Instance();

		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		if (colorCanTrain)
		{
			bool canTrain = data.CanTrainAbility(mercData->AbilityID);
			ImGui::PushStyleColor(ImGuiCol_Text,
				canTrain ? MQColor(0, 255, 0).ToImU32() : MQColor(255, 0, 0).ToImU32());
		}

		char label[256];
		if (szLabel)
			sprintf_s(label, "%s##%p", szLabel, (void*)mercData);
		else
			sprintf_s(label, "%s (Rank %d)##%p", mercData->GetNameString(), mercData->GroupRank, (void*)mercData);
		bool expand = ImGui::TreeNode(label);

		if (colorCanTrain)
		{
			ImGui::PopStyleColor();
		}

		ImGui::TableNextColumn();
		ImGui::Text("%s", mercData->GetDescriptionString());

		if (expand)
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Ability ID");
			ImGui::TableNextColumn(); ImGui::Text("%d", mercData->AbilityID);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Name");
			ImGui::TableNextColumn(); ImGui::Text("%s", mercData->GetNameString());

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Description");
			ImGui::TableNextColumn(); ImGui::TextWrapped("%s", mercData->GetDescriptionString());

			ImGui::TableNextRow();
			if (colorCanTrain)
			{
				ImGui::PushStyleColor(ImGuiCol_Text,
					(pLocalPC->MercAAPoints >= mercData->Cost) ? MQColor(0, 255, 0).ToImU32() : MQColor(255, 0, 0).ToImU32());
			}

			ImGui::TableNextColumn(); ImGui::Text("Cost");
			ImGui::TableNextColumn(); ImGui::Text("%d", mercData->Cost);

			if (colorCanTrain)
			{
				ImGui::PopStyleColor();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Group ID");
			ImGui::TableNextColumn(); ImGui::Text("%d", mercData->GroupID);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Group Rank");
			ImGui::TableNextColumn(); ImGui::Text("%d", mercData->GroupRank);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Type");
			ImGui::TableNextColumn(); ImGui::Text("%s (%d)",
				pDBStr->GetString(mercData->Type, eMercenaryAbilityType), mercData->Type);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Min Level");
			ImGui::TableNextColumn(); ImGui::Text("%d", mercData->MinPlayerLevel);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("Requirement ID");
			ImGui::TableNextColumn(); ImGui::Text("%d", mercData->RequirementAssociationID);

			if (mercData->Refund != 0)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Refund");
				ImGui::TableNextColumn(); ImGui::Text("%d", mercData->Refund);
			}

			if (!mercData->AbilityReqs.empty())
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				ImGui::PushStyleColor(ImGuiCol_Text,
					mercData->IsRequirementsMet() ? MQColor(0, 255, 0).ToImU32() : MQColor(255, 0, 0).ToImU32());

				if (ImGui::TreeNode("Ability Requirements"))
				{
					for (int i = 0; i < mercData->AbilityReqs.GetCount(); ++i)
					{
						const MercenaryAbilityReq& req = mercData->AbilityReqs[i];

						const int* entry = data.GetFirstMercenaryAbilityIdByGroupId(req.ReqGroupID);
						while (entry)
						{
							const MercenaryAbilitiesData* mercAbility = data.GetMercenaryAbility(*entry);
							if (mercAbility && mercAbility->GroupRank >= req.ReqGroupRank)
							{
								ImGui::TableNextRow();
								ImGui::TableNextColumn();
								ImGui::Text("%s (Rank %d)", mercAbility->GetNameString(), req.ReqGroupRank);
								break;
							}

							entry = data.GetNextMercenaryAbilityIdByGroupId(entry);
						}
					}

					ImGui::TreePop();
				}

				ImGui::PopStyleColor();
			}

			ImGui::TreePop();
		}
	}

	void DrawMercenaryAbilities()
	{

		if (ImGui::BeginTable("MercenaryAbilities", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name");
			ImGui::TableSetupColumn("Value");
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			auto& data = MercenaryAlternateAdvancementManagerClient::Instance();

			//----------------------------------------------------------------------------
			// Mercenary Types
			if (!data.MercenaryTypes.empty())
			{
				auto& types = data.MercenaryTypes;

				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				if (ImGui::TreeNode("Mercenary Types"))
				{
					auto pValue = types.GetFirst();
					while (pValue)
					{
						auto* pNode = types.NodeGet(pValue);

						ImGui::TableNextRow();

						ImGui::TableNextColumn();
						ImGui::Text("%d", pNode->key());

						ImGui::TableNextColumn();
						ImGui::Text("%s (%d)", pDBStr->GetString(pNode->value(), eMercenaryAbilityType), pNode->value());

						pValue = types.GetNext(pValue);
					}

					ImGui::TreePop();
				}
			}

			//----------------------------------------------------------------------------
			// Mercenary Abilities
			if (!data.MercenaryAbilities.empty())
			{
				auto& abilities = data.MercenaryAbilities;

				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				if (ImGui::TreeNode("Mercenary Abilities"))
				{
					const MercenaryAbilitiesData* mercData = abilities.GetFirst();
					while (mercData != nullptr)
					{
						DrawMercenaryAbilityRow(mercData);

						mercData = abilities.GetNext(mercData);
					}
					ImGui::TreePop();
				}
			}

			//----------------------------------------------------------------------------
			// Mercenary Ability Groups
			if (!data.MercenaryAbilityGroups.empty())
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				if (ImGui::TreeNode("Mercenary Ability Groups"))
				{
					MercenaryAbilityGroup* group = data.MercenaryAbilityGroups.GetFirst();
					while (group)
					{
						int groupId = data.MercenaryAbilityGroups.GetKey(group);

						if (const int* abilityId = data.GetFirstMercenaryAbilityIdByGroupId(groupId))
						{
							if (const MercenaryAbilitiesData* mercData = data.GetMercenaryAbility(*abilityId))
							{
								ImGui::TableNextRow();
								ImGui::TableNextColumn();

								char label[256];
								sprintf_s(label, "%s", mercData->GetNameString());

								bool expand = ImGui::TreeNode(label);

								ImGui::TableNextColumn();
								ImGui::Text("%s", mercData->GetTypeString());

								if (expand)
								{
									while (mercData)
									{
										DrawMercenaryAbilityRow(mercData);

										if (abilityId = data.GetNextMercenaryAbilityIdByGroupId(abilityId))
										{
											mercData = data.GetMercenaryAbility(*abilityId);
										}
										else
										{
											mercData = nullptr;
										}
									}

									ImGui::TreePop();
								}
							}
						}

						group = data.MercenaryAbilityGroups.GetNext(group);
					}

					ImGui::TreePop();
				}
			}

			//----------------------------------------------------------------------------
			// Mercenary Ability Groups (Owned)
			if (!data.MercenaryAbilitiesOwnedByGroupID.empty())
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				if (ImGui::TreeNode("Mercenary Abilities (Owned)"))
				{
					int* abilityId = data.MercenaryAbilitiesOwnedByGroupID.GetFirst();
					while (abilityId)
					{
						if (const MercenaryAbilitiesData* mercData = data.GetMercenaryAbility(*abilityId))
						{
							int maxRanks = data.GetMercenaryMaxGroupRank(*abilityId);
							int curRank = data.GetMercenaryMaxOwnedGroupRank(*abilityId);

							char label[256];
							sprintf_s(label, "%s (%d/%d)", mercData->GetNameString(), curRank, maxRanks);

							DrawMercenaryAbilityRow(mercData, label);
						}

						abilityId = data.MercenaryAbilitiesOwnedByGroupID.GetNext(abilityId);
					}

					ImGui::TreePop();
				}
			}

			//----------------------------------------------------------------------------
			// Mercenary Ability Groups (Unowned)
			if (!data.MercenaryAbilityGroups.empty())
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				if (ImGui::TreeNode("Mercenary Abilities (Unowned)"))
				{
					MercenaryAbilityGroup* group = data.MercenaryAbilityGroups.GetFirst();
					while (group)
					{
						int groupId = data.MercenaryAbilityGroups.GetKey(group);

						if (const MercenaryAbilitiesData* unownedAbility = data.GetFirstUnownedAbilityByGroupId(groupId))
						{
							int curRank = data.GetMercenaryMaxOwnedGroupRank(unownedAbility->AbilityID) + 1;
							int maxRank = data.GetMercenaryMaxGroupRank(unownedAbility->AbilityID);

							char label[256];
							sprintf_s(label, "%s (%d/%d)", unownedAbility->GetNameString(), curRank, maxRank);

							DrawMercenaryAbilityRow(unownedAbility, label, true);
						}

						group = data.MercenaryAbilityGroups.GetNext(group);
					}

					ImGui::TreePop();
				}
			}

			ImGui::EndTable();
		}
	}
#endif // HAS_MERCENARY_AA

	void Draw() override
	{
		if (ImGui::BeginTabBar("##AbilitySections"))
		{
			if (ImGui::BeginTabItem("Player AA"))
			{
				DrawPlayerAbilities();
				ImGui::EndTabItem();
			}

#if HAS_MERCENARY_AA
			if (ImGui::BeginTabItem("Mercenary AA"))
			{
				DrawMercenaryAbilities();
				ImGui::EndTabItem();
			}
#endif // HAS_MERCENARY_AA

			ImGui::EndTabBar();
		}
	}
};
static AltAbilityInspector* s_altAbilityInspector = nullptr;

#pragma endregion

#pragma region Character Data Inspector

class CharacterDataInspector : public ImGuiWindowBase
{
public:
	CharacterDataInspector() : ImGuiWindowBase("Character Data Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~CharacterDataInspector()
	{
	}

	bool IsEnabled() const override
	{
		return pLocalPC != nullptr && GetGameState() == GAMESTATE_INGAME;
	}

	void Draw() override
	{
		if (ImGui::BeginTable("##CharacterData", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			static std::unordered_map<int, std::string> ConsumableFeatureNames = {
				{ EQFeature_MerchantPerk, "Merchant Perk" },
				{ EQFeature_DragonHoard, "Dragon Hoard" },
				{ EQFeature_TradeskillDepot, "Tradeskill Depot" },
				{ EQFeature_TradeskillDepotSlots, "Tradeskill Depot Slots" },
			};

			if (ImGui::TreeNode("Consumable Features"))
			{
				for (const auto& ClaimData : pLocalPC->ConsumableFeatures.claimData)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					int featureId = ClaimData.featureId;

					if (const ClaimFeatureData* featureData = pClaimWnd->claimFeatureData.GetClaimFeatureDataByFeatureId(featureId))
					{
						bool expand = false;
						char szLabel[128];

						if (featureData->itemCount > 0)
						{
							sprintf_s(szLabel, "%s (%d)", featureData->items[0].itemName.c_str(), featureId);
						}
						else
						{
							sprintf_s(szLabel, "%d", featureId);
						}

						expand = ImGui::TreeNode(szLabel);

						ImGui::TableNextColumn();
						ImGui::Text("%d", featureData->featureCount);

						if (expand)
						{
							ImGui::TableNextRow();
							ImGui::TableNextColumn();

							if (featureData->itemCount > 0)
							{
								char szLabel[32];
								if (featureData->itemCount == 1)
									strcpy_s(szLabel, "1 Item");
								else
									sprintf_s(szLabel, "%d Items", featureData->itemCount);

								if (ImGui::TreeNode(szLabel))
								{
									for (int itemIdx = 0; itemIdx < featureData->itemCount; ++itemIdx)
									{
										const ClaimItemData& itemData = featureData->items[itemIdx];

										ImGui::TableNextRow();
										ImGui::TableNextColumn(); ImGui::Text("%s (%d)", itemData.itemName.c_str(), itemData.itemId);
										ImGui::TableNextColumn(); ImGui::Text("%d", itemData.itemCount);
									}

									ImGui::TreePop();

								}
							}

							ImGui::TableNextRow();
							ImGui::TableNextColumn(); ImGui::Text("Description");
							ImGui::TableNextColumn(); ImGui::Text("%s", pDBStr->GetString(featureData->stringId, eClaimFeatureDescription));

							ImGui::TableNextRow();
							ImGui::TableNextColumn(); ImGui::Text("Requirements Met");
							ImGui::TableNextColumn(); ImGui::Text("%s", featureData->meetsRequirements ? "Yes": "No");

							ImGui::TreePop();
						}
					}
					else
					{
						ImGui::Indent();
						auto iter = ConsumableFeatureNames.find(ClaimData.featureId);
						if (iter != ConsumableFeatureNames.end())
						{
							ImGui::Text("%s (%d)", iter->second.c_str(), ClaimData.featureId);
						}
						else
						{
							ImGui::Text("%d", ClaimData.featureId);
						}

						ImGui::TableNextColumn();
						ImGui::Text("%d", ClaimData.count);
						ImGui::Unindent();
					}
				}

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("Game Features"))
			{
				FreeToPlayClient& client = FreeToPlayClient::Instance();

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Membership Level");
				ImGui::TableNextColumn(); ImGui::Text("%s (%d)", FreeToPlayClient::ToString(client.MembershipLevel),
					client.MembershipLevel);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Subscription days");
				ImGui::TableNextColumn(); ImGui::Text("%d", pLocalPC->SubscriptionDays);

				for (int i = 0; i < (int)GameFeature::Max; ++i)
				{
					const RestrictionInfo& info = FreeToPlayClient::RestrictionInfo[i];
					GameFeature feature = static_cast<GameFeature>(i);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("%s", info.string);

					int data = pLocalPC->GetGameFeature(feature);
					if (info.boolean)
					{
						ImGui::TableNextColumn();
						if (data != 0)
							ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "Enabled");
						else
							ImGui::TextColored(MQColor(255, 0, 0).ToImColor(), "Disabled");
					}
					else
					{
						ImGui::TableNextColumn();

						if (data == -1)
							ImGui::TextColored(MQColor(127, 127, 127).ToImColor(), "Unrestricted");
						else
							ImGui::Text("%d", data);
					}
				}

				ImGui::TreePop();
			}

#if HAS_ALTERNATE_PERSONAS
			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("Personas"))
			{
				for (int i = 0; i < MAX_PLAYER_CLASSES; ++i)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					ImGui::Text("%s", GetClassDesc(i + 1));

					ImGui::TableNextColumn();
					ImGui::Text("%d", pLocalPC->ProfileManager.GetAltClassLevel(i));
					
				}

				ImGui::TreePop();
			}
#endif
			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("Group"))
			{
				ImGui::TableNextRow();

				if (pLocalPC->Group)
				{
					ImGui::TableNextColumn(); ImGui::Text("ID");
					ImGui::TableNextColumn(); ImGui::Text("%d", pLocalPC->Group->GetID());

					DrawGroupMember("Leader", pLocalPC->Group->GetGroupLeader());

					for (uint32_t i = 0; i < pLocalPC->Group->GetMaxGroupSize(); ++i)
					{
						CGroupMember* groupMember = pLocalPC->Group->GetGroupMember(i);

						char label[32] = {};
						sprintf_s(label, "Member %d", i);
						DrawGroupMember(label, groupMember);
					}
				}
				else
				{
					ImGui::TableNextColumn(); ImGui::Text("No Group");
				}

				ImGui::TreePop();
			}

			ImGui::EndTable();
		}
	}

	void DrawGroupMember(const char* text, CGroupMember* groupMember)
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn();

		if (groupMember)
		{
			bool expand = ImGui::TreeNode(text);
			ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->GetName());

			if (expand)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Name");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->GetName());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Type");
				ImGui::TableNextColumn(); ImGui::Text("%d", (int)groupMember->Type);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Owner Name");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->GetOwnerName());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Level");
				ImGui::TableNextColumn(); ImGui::Text("%d", groupMember->GetLevel());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Is Offline");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->IsOffline() ? "Yes" : "No");

#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF)
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Unique Player ID");
				ImGui::TableNextColumn(); ImGui::Text("%d", groupMember->UniquePlayerID);
#endif

#if IS_CLIENT_DATE(20250513u)
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Unknown 0x30");
				ImGui::TableNextColumn(); ImGui::Text("%" PRIx64, groupMember->Unknown0x30);
#endif

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Is Main Tank");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->IsMainTank() ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Is Main Assist");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->IsMainAssist() ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Is Puller");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->IsPuller() ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Is Mark NPC");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->IsMarkNPC() ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Is Master Looter");
				ImGui::TableNextColumn(); ImGui::Text("%s", groupMember->IsMasterLooter() ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Role Bits");
				ImGui::TableNextColumn(); ImGui::Text("0x%08x", groupMember->CurrentRoleBits);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Online Timestamp");
				ImGui::TableNextColumn(); ImGui::Text("%" PRId64, groupMember->GetOnlineTimestamp());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Group Index");
				ImGui::TableNextColumn(); ImGui::Text("%d", groupMember->GroupIndex);

				ImGui::TreePop();
			}
		}
		else
		{
			TreeAdvanceToLabelPos(); ImGui::Text("%s", text);
			ImGui::TableNextColumn(); ImGui::TextColored(ImColor(1.0f, 1.0f, 1.0f, .5f), "None");
		}
	}
};
static CharacterDataInspector* s_characterDataInspector = nullptr;

#pragma endregion

#pragma region Engine Inspector

static const char* DeferModeToString(eDeferMode mode)
{
	switch (mode)
	{
	case cNonDeferred:
		return "Non-Deferred";
	case cDeferredWad:
		return "Deferred (Wad)";
	case cDeferredWadLoading:
		return "Deferred - Loading (Wad)";
	case cDeferredFile:
		return "Deferred (File)";
	case cDeferredFileLoading:
		return "Deferred - Loading (File)";
	case cDeferredForeground:
		return "Deferred - Foreground";
	case cDeferredError:
		return "Deferred - Error";

	default: return "Unknown";
	}
}

static const char* TextureQualityToString(eBitmapTextureQuality quality)
{
	switch (quality)
	{
	case eBitmapTextureQualityInvalid: return "Invalid";
	case eBitmapTextureQualityHigh: return "High";
	case eBitmapTextureQualityMedium: return "Medium";
	case eBitmapTextureQualityLow: return "Low";

	default: return "Unknown";
	}
}

static const char* TrackingTypeToString(int trackingType)
{
	switch (trackingType)
	{
	case 0: return "WLD";
	case 1: return "WLD/PCLOUD";
	case 2: return "EQG";
	case 3: return "EQG/SMODEL";
	case 4: return "EQG/HMODEL";
	case 5: return "Particle";
	case 6: return "Downsampled";
	case -1:
	default: return "Unknown";
	}
}

class EngineInspector : public ImGuiWindowBase
{
public:
	EngineInspector() : ImGuiWindowBase("Engine Inspector")
	{
		SetDefaultSize(ImVec2(800, 600));
	}

	~EngineInspector() override
	{
	}

	bool IsEnabled() const override
	{
		return true;
	}

	void Draw() override
	{
		if (ImGui::BeginTabBar("##EngineTabBar"))
		{
			if (ImGui::BeginTabItem("General"))
			{
				DrawGeneral();

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Bitmaps"))
			{
				DrawBitmaps();

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Fonts"))
			{
				DrawFonts();

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
	}

	void DrawGeneral()
	{
		int round = fegetround();

		const char* roundingMode = "";
		switch (round)
		{
		case FE_TONEAREST: roundingMode = "FE_TONEAREST"; break;
		case FE_UPWARD: roundingMode = "FE_UPWARD"; break;
		case FE_DOWNWARD: roundingMode = "FE_DOWNWARD"; break;
		case FE_TOWARDZERO: roundingMode = "FE_TOWARDZERO"; break;
		default: roundingMode = "UNKNOWN"; break;
		}

		ImGui::Text("Rounding Mode: %s", roundingMode);
	}

	void DrawFonts()
	{
		if (!pGraphicsEngine) return;
		auto resourceMgr = pGraphicsEngine->pResourceManager;
		if (!resourceMgr) return;

		CCachedFont* pCachedFont;
		CCachedFont* pSelectedFont = nullptr;
		EStatus status = eStatusFailure;

		// GetCachedFont may crash here if the font manager hasn't been created yet, but we're
		// using this routine to get access to the font manager. If it throws an access violation,
		// the application state is fine, we can just bail on this attempt.
		__try {
			status = resourceMgr->GetCachedFont(0, reinterpret_cast<CCachedFontInterface**>(&pCachedFont));
		} __except (EXCEPTION_EXECUTE_HANDLER) {
			status = eStatusFailure;
		}

		if (status != eStatusSuccess) return;
		CFontManager* fontMgr = pCachedFont->pFontManager;
		if (!fontMgr) return;

		ImVec2 availSize = ImGui::GetContentRegionAvail();
		if (m_rightPaneSize == 0.0f)
			m_rightPaneSize = availSize.x - m_leftPaneSize - 1;

		imgui::DrawSplitter(false, 9.0f, &m_leftPaneSize, &m_rightPaneSize, 50, 250);

		// Left Pane
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
			ImGui::BeginChild("TreeListView", ImVec2(m_leftPaneSize, ImGui::GetContentRegionAvail().y - 1), true);
			ImGui::PopStyleVar();

			for (int fontIndex = 0; fontIndex < NumFontStyles; ++fontIndex)
			{
				resourceMgr->GetCachedFont(fontIndex, reinterpret_cast<CCachedFontInterface**>(&pCachedFont));

				ImGui::PushID(pCachedFont);

				char szLabel[64];
				sprintf_s(szLabel, "%d: %s", fontIndex, pCachedFont->strFontName.c_str());

				if (ImGui::Selectable(szLabel, m_selectedFont == fontIndex))
					m_selectedFont = fontIndex;

				if (m_selectedFont == fontIndex)
					pSelectedFont = pCachedFont;

				ImGui::PopID();
			}

			ImGui::EndChild();
		}

		ImGui::SameLine();

		// Right Pane
		{
			ImVec2 rightPaneContentSize = ImGui::GetContentRegionAvail();
			ImGui::BeginChild("ContentView", ImVec2(rightPaneContentSize.x, rightPaneContentSize.y - 1), true);

			if (pSelectedFont)
			{
				ImGui::Text("Font: %s", pSelectedFont->strFontName.c_str());
				ImGui::Text("Font ID: %d", pSelectedFont->eFontId);

				if (ImGui::CollapsingHeader("Textures"))
				{
					int index = 0;
					for (CD3DTexturePointerNode* ptr : pSelectedFont->arTextures)
					{
						ImGui::Text("%d:", index++);

						ImTextureID TexID = ptr->pTexture;

						ImGui::Image(TexID, ImVec2(pSelectedFont->fTextureSize, pSelectedFont->fTextureSize));
					}
				}
			}

			ImGui::EndChild();
		}
	}

	void DrawBitmaps()
	{
		ImVec2 availSize = ImGui::GetContentRegionAvail();
		if (m_rightPaneSize == 0.0f)
			m_rightPaneSize = availSize.x - m_leftPaneSize - 1;

		imgui::DrawSplitter(false, 9.0f, &m_leftPaneSize, &m_rightPaneSize, 50, 250);

		// Left Pane
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
			ImGui::BeginChild("TreeListView", ImVec2(m_leftPaneSize, ImGui::GetContentRegionAvail().y - 1), true);
			ImGui::PopStyleVar();

			const CEQGBitmap* pLastSelectedBitmap = m_selectedBitmap;
			m_selectedBitmap = nullptr;

			std::vector<std::vector<CEQGBitmap*>> bitmapsByPool;
			bitmapsByPool.resize(eNumMemoryPoolManagerTypes);
			{
				CEQGBitmap* pEQBitmap = CEQGBitmap::GetFirstBitmap();
				while (pEQBitmap != nullptr)
				{
					bitmapsByPool[pEQBitmap->m_eMemoryPoolManagerType].push_back(pEQBitmap);

					if (pEQBitmap == pLastSelectedBitmap)
						m_selectedBitmap = pEQBitmap;

					pEQBitmap = pEQBitmap->GetNextBitmap();
				}
			}

			//for (auto& bitmaps : bitmapsByPool)
			//{
			//	std::sort(bitmaps.begin(), bitmaps.end(),
			//		[](CEQGBitmap* p1, CEQGBitmap* p2)
			//		{
			//			return mq::ci_less()(p1->m_pszFileName, p2->m_pszFileName);
			//		});
			//}

			ImGuiTableFlags tableFlags = ImGuiTableFlags_ScrollY
				| ImGuiTableFlags_BordersV
				| ImGuiTableFlags_BordersOuterH
				| ImGuiTableFlags_Resizable
				| ImGuiTableFlags_RowBg;

			if (ImGui::BeginTable("##eqgbitmaps", 2, tableFlags))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn("Index");
				ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
				ImGui::TableHeadersRow();



				for (int pool = 0; pool < (int)bitmapsByPool.size(); ++pool)
				{
					auto& bitmaps = bitmapsByPool[pool];
					EMemoryPoolManagerType poolType = static_cast<EMemoryPoolManagerType>(pool);

					char label[64];
					switch (poolType)
					{
					case eMemoryPoolManagerTypePersistent:
						sprintf_s(label, "Pool: Persistent (%d)", static_cast<int>(bitmaps.size()));
						break;
					case eMemoryPoolManagerTypeOnDemand:
						sprintf_s(label, "Pool: On Demand (%d)", static_cast<int>(bitmaps.size()));
						break;
					case eMemoryPoolManagerTypeZone:
						sprintf_s(label, "Pool: Zone (%d)", static_cast<int>(bitmaps.size()));
						break;

					default:
						sprintf_s(label, "Other: %d (%d)", poolType, static_cast<int>(bitmaps.size()));
						break;
					}

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNodeEx(reinterpret_cast<void*>(poolType), 0, "%s", label))
					{
						for (int i = 0; i < (int)bitmaps.size(); ++i)
						{
							bool selectThis = false;
							const CEQGBitmap* pEQBitmap = bitmaps[i];

							ImGui::PushID(pEQBitmap);
							ImGui::TableNextRow();
							ImGui::TableNextColumn();

							const bool selected = pEQBitmap == pLastSelectedBitmap;
							ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth
								| ImGuiTreeNodeFlags_SpanAvailWidth
								| ImGuiTreeNodeFlags_Leaf
								| ImGuiTreeNodeFlags_NoTreePushOnOpen;
							if (selected)
							{
								flags |= ImGuiTreeNodeFlags_Selected;
							}

							ImGui::TreeNodeEx(pEQBitmap, flags, "%d", i);

							if (m_selectedBitmap == nullptr || ImGui::IsItemClicked())
							{
								m_selectedBitmap = pEQBitmap;
							}

							ImGui::TableNextColumn(); ImGui::Text("%s", pEQBitmap->m_pszFileName);
							ImGui::PopID();
						}

						ImGui::TreePop();
					}
				}

				ImGui::EndTable();
			}

			ImGui::EndChild();
		}

		ImGui::SameLine();

		// Right Pane
		{
			ImVec2 rightPaneContentSize = ImGui::GetContentRegionAvail();
			ImGui::BeginChild("ContentView", ImVec2(rightPaneContentSize.x, rightPaneContentSize.y - 1), true);

			if (m_selectedBitmap)
			{
				const CEQGBitmap* pPrevious = m_selectedBitmap->GetPreviousBitmap();
				ImGui::BeginDisabled(pPrevious == nullptr);
				if (ImGui::Button("Prev") && pPrevious)
					m_selectedBitmap = pPrevious;
				ImGui::EndDisabled();

				ImGui::SameLine();

				const CEQGBitmap* pNext = m_selectedBitmap->GetNextBitmap();
				ImGui::BeginDisabled(pNext == nullptr);
				if (ImGui::Button("Next") && pNext)
					m_selectedBitmap = pNext;
				ImGui::EndDisabled();

				const CEQGBitmap* pBitmap = m_selectedBitmap;

				const char* typeLabel = "Unknown";
				switch (pBitmap->m_eType)
				{
				case eBitmapTypeNormal: typeLabel = "Normal"; break;
				case eBitmapTypeLayer: typeLabel = "Layer"; break;
				case eBitmapTypeSingleDetail: typeLabel = "Single Detail"; break;
				case eBitmapTypePaletteDetailMain: typeLabel = "Palette Detail - Main"; break;
				case eBitmapTypePaletteDetailPalette: typeLabel = "Palette Detail - Palette"; break;
				case eBitmapTypePaletteDetailDetail: typeLabel = "Palette Detail - Detail"; break;
				default: break;
				}
				ImGui::Text("Bitmap Type: %s", typeLabel);

				const char* memoryPoolLabel = "Unknown";
				switch (pBitmap->m_eMemoryPoolManagerType)
				{
				case eMemoryPoolManagerTypePersistent: memoryPoolLabel = "Persistent"; break;
				case eMemoryPoolManagerTypeOnDemand: memoryPoolLabel = "On Demand"; break;
				case eMemoryPoolManagerTypeZone: memoryPoolLabel = "Zone"; break;
				default: break;
				}
				ImGui::Text("Memory Pool: %s", memoryPoolLabel);

				ImGui::Text("File Name: %s", pBitmap->m_pszFileName);
				ImGui::Text("Size: %d x %d", pBitmap->m_uWidth, pBitmap->m_uHeight);
				ImGui::Text("Source Size: %d x %d", pBitmap->m_uSourceWidth, pBitmap->m_uSourceHeight);

				ImGui::Text("Has Texture: %s", pBitmap->m_bHasTexture ? "Yes" : "No");
				ImGui::Text("Object Index: %d", pBitmap->m_uObjectIndex);
				ImGui::Text("Distance Squared: %.2f", pBitmap->m_distanceSq);
				ImGui::Text("Last Distance Time: %d", pBitmap->m_lastDistanceTime);
				ImGui::Text("Last Render Time: %d", pBitmap->m_lastRenderTime);
				ImGui::Text("Loaded Time: %d", pBitmap->m_loadedTime);
				ImGui::Text("Defer Mode: %s", DeferModeToString(pBitmap->m_eDeferMode));
				ImGui::Text("Defer Mode (original): %s", DeferModeToString(pBitmap->m_eOriginalDeferMode));
				ImGui::Text("Deferred Filename: %s", pBitmap->m_DeferredFilename.c_str());

				ImGui::Text("Texture Quality: %s", TextureQualityToString(pBitmap->m_eTextureQuality));
				ImGui::Text("Can Reclaim: %s", pBitmap->m_canReclaim ? "Yes" : "No");
				ImGui::Text("Tracking Type: %s", TrackingTypeToString(pBitmap->m_nTrackingType));

#if HAS_DIRECTX_11
				ImTextureID TexID = pBitmap;
#else
				ImTextureID TexID = pBitmap->GetTexture();
#endif

				if (TexID != nullptr)
				{
					ImGui::Separator();

					bool drawBorder = true;
					ImVec2 minUV = ImVec2(0, 0);
					ImVec2 maxUV = ImVec2(1, 1);
					ImVec2 textureSize = ImVec2(static_cast<float>(pBitmap->m_uWidth),
						static_cast<float>(pBitmap->m_uHeight));

					ImVec2 imageSize = textureSize;

					ImGui::Image(
						TexID, imageSize,
						minUV, maxUV,
						ImVec4(1, 1, 1, 1),
						drawBorder ? ImVec4(1, 1, 1, 0.5f) : ImVec4()
					);
				}
			}

			ImGui::EndChild();
		}
	}

private:
	float m_leftPaneSize = 150.0f; // initial size of left column
	float m_rightPaneSize = 0.0f;  // size of right column. Initial value calculated from left.
	const CEQGBitmap* m_selectedBitmap = nullptr;

	int m_selectedFont = 0;
};

static EngineInspector* s_engineInspector = nullptr;

#pragma endregion

#pragma region EverQuest Data Inspector

void DeveloperTools_DrawHotButtonData(const HotButtonData& data)
{
	// Item
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("Item");
	if (ItemPtr pItem = data.Item)
	{
		ImGui::TableNextColumn();
		if (imgui::ItemLinkText(pItem->GetName(), GetColorForChatColor(USERCOLOR_LINK)))
			pItemDisplayManager->ShowItem(pItem);
	}

	// ItemGuid
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("ItemGuid");
	ImGui::TableNextColumn(); ImGui::Text("%s", data.ItemGuid.guid);

	// Label
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("Label");
	ImGui::TableNextColumn(); ImGui::Text("%s", data.Label);

	// Item Name
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("Item Name");
	ImGui::TableNextColumn(); ImGui::Text("%s", data.ItemName);

	// ItemID
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("ItemID");
	ImGui::TableNextColumn(); ImGui::Text("%d", data.ItemId);

	// IconType
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("IconType");
	ImGui::TableNextColumn(); ImGui::Text("%d", data.IconType);

	// IconSlot
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("IconSlot");
	ImGui::TableNextColumn(); ImGui::Text("%d", data.IconSlot);

	// IconId
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("IconID");
	ImGui::TableNextColumn(); ImGui::Text("%d", data.IconId);

	// Slot
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("Slot");
	ImGui::TableNextColumn(); ImGui::Text("%d", data.Slot);

	// Type
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("Type");
	ImGui::TableNextColumn(); ImGui::Text("%d", (int)data.Type);

	// Item Valid
	ImGui::TableNextRow();
	ImGui::TableNextColumn(); ImGui::Text("ItemValid");
	ImGui::TableNextColumn(); ImGui::Text("%d", (int)data.ItemValid);
}

class EverQuestDataInspector : public ImGuiWindowBase
{
public:
	EverQuestDataInspector() : ImGuiWindowBase("EverQuest Data Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~EverQuestDataInspector()
	{
	}

	void Draw() override
	{
		if (ImGui::BeginTable("##EverQuestData", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			auto& eq = *pEverQuestInfo;

			if (ImGui::TreeNode("System"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("HWND");
				ImGui::TableNextColumn(); ImGui::Text("%p", eq.Wnd);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("HInstance");
				ImGui::TableNextColumn(); ImGui::Text("%p", eq.hInst);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Render Min X/Y");
				ImGui::TableNextColumn(); ImGui::SliderInt2("##eq.Render_MinX", &eq.Render_MinX, 0, 10000);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Render Max X/Y");
				ImGui::TableNextColumn(); ImGui::SliderInt2("##eq.Render_MaxX", &eq.Render_MaxX, 0, 10000);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Render Scale X/Y");
				ImGui::TableNextColumn(); ImGui::SliderInt2("##eq.Render_XScale", &eq.Render_XScale, 0, 10000);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Render Scale W/H");
				ImGui::TableNextColumn(); ImGui::SliderInt2("##eq.Render_WidthScale", &eq.Render_WidthScale, 0, 10000);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Render Resolution X/Y");
				ImGui::TableNextColumn(); ImGui::SliderInt2("##eq.ScreenXRes", &eq.ScreenXRes, 0, 10000);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Fullscreen Mode");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.FullscreenMode ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Locale");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.Locale);

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Input - Keyboard"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Keyboard Mode");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.KeyboardMode);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Keyboard Modifiers");

				fmt::memory_buffer buffer;
				auto buf = std::back_inserter(buffer);
				if (eq.bIsPressedShift)
					fmt::format_to(buf, "SHIFT ");
				if (eq.bIsPressedLShift)
					fmt::format_to(buf, "LSHIFT ");
				if (eq.bIsPressedRShift)
					fmt::format_to(buf, "RSHIFT ");
				if (eq.bIsPressedControl)
					fmt::format_to(buf, "CTRL ");
				if (eq.bIsPressedLControl)
					fmt::format_to(buf, "LCTRL ");
				if (eq.bIsPressedRControl)
					fmt::format_to(buf, "RCTRL ");
				if (eq.bIsPressedAlt)
					fmt::format_to(buf, "ALT ");
				if (eq.bIsPressedLAlt)
					fmt::format_to(buf, "LALT ");
				if (eq.bIsPressedRAlt)
					fmt::format_to(buf, "RALT ");
				ImGui::TableNextColumn(); ImGui::Text("%s", to_string(buffer).c_str());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Current Keypress");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.Currkeypress);

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Input - Mouse"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Cntrl");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MouseCntrl);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Active");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MouseActive);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("MouseX/Y/Z");
				ImGui::TableNextColumn(); ImGui::Text("%d, %d, %d", eq.MouseX, eq.MouseY, eq.MouseZ);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Last Mouse X/Y");
				ImGui::TableNextColumn(); ImGui::Text("%d, %d", eq.LastMX, eq.LastMY);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse In Client Rect");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.MouseInClientRect ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Sensitivity");
				ImGui::TableNextColumn(); ImGui::Text("%d, %d", eq.MXSensitivity, eq.MYSensitivity);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Pointer Speed Mod");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MousePointerSpeedMod);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Inverse");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MInverse);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Buttons");
				ImGui::TableNextColumn(); ImGui::Text("%s", fmt::format("{}", fmt::join(g_pDeviceInputProxy->mouse.CurrentClickState, ", ")).c_str());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Buttons Old");
				ImGui::TableNextColumn(); ImGui::Text("%s", fmt::format("{}", fmt::join(g_pDeviceInputProxy->mouse.LastClickState, ", ")).c_str());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Right Handed Mouse");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.bIsMouseRightHanded ? "Yes" : "No");

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Pointer Speed Mod");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MousePointerSpeedMod);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mouse Look");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MouseLook);

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Input - Commands"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Command");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.Command);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Run Mode");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.RunMode);

				fmt::memory_buffer buffer; auto buf = std::back_inserter(buffer);
				for (int i = 0; i < nEQMappableCommands; ++i)
				{
					if (eq.keyDown[i])
					{
						fmt::format_to(buf, "{} ", szEQMappableCommands[i]);
					}
				}

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Active Commands");
				ImGui::TableNextColumn(); ImGui::Text("%s", to_string(buffer).c_str());

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Game"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Run Mode");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.RunMode);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Current Channel");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.CurrentChan);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Current Language");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.CurrentLang);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Tell Target");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.TellTarget);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Display NetStat");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.bNetstat);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Infravision Color");
				ImVec4 infra(eq.InfraRed / 255.0f, eq.InfraGreen / 255.0f, eq.InfraBlue / 255.0f, 1.0f);
				ImGui::TableNextColumn(); ImGui::ColorButton("##Infravision Color", infra);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Ultravision Color");
				ImVec4 ultra(eq.UltraRed / 255.0f, eq.UltraGreen / 255.0f, eq.UltraBlue / 255.0f, 1.0f);
				ImGui::TableNextColumn(); ImGui::ColorButton("##Ultravision Color", ultra);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Zone ID");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.ZoneID);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Primary/Secondary Attack Ready");
				ImGui::TableNextColumn(); ImGui::Text("%d, %d", eq.PrimaryAttackReady, eq.SecondaryAttackReady);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Expansion Flags");
				ImGui::TableNextColumn(); ImGui::Text("%" PRIX64, (int64_t)eq.ExpansionsFlagBitmask);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Attack On Assist");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.AttackOnAssist ? "Yes" : "No");

#if HAS_AUTOSKILLS
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Auto Skills");
				ImGui::TableNextColumn(); ImGui::Text("%s", fmt::format("{}", fmt::join(eq.AutoSkills, ", ")).c_str());
#endif

				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				if (ImGui::TreeNode("Last Tell History"))
				{
					for (int i = 0; i < NUM_REPLY_NAMES; ++i)
					{
						if (eq.LastTellFromList[i][0] == 0)
							break;

						ImGui::TableNextRow();
						ImGui::TableNextColumn(); ImGui::Text("%s", eq.LastTellFromList[i]);
						ImGui::TableNextColumn(); if (i == eq.LastTellFromIndex) ImGui::Text("<-- Last Active");
					}

					ImGui::TreePop();
				}

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Combat Skills");
				ImGui::TableNextColumn(); ImGui::Text("%s", fmt::format("{}", fmt::join(eq.combatSkill, ", ")).c_str());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Abilities");
				ImGui::TableNextColumn(); ImGui::Text("%s", fmt::format("{}", fmt::join(eq.abilities, ", ")).c_str());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Combat Abilities");
				ImGui::TableNextColumn(); ImGui::Text("%s", fmt::format("{}", fmt::join(eq.combatAbilities, ", ")).c_str());

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Server Name");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.WorldServerShortname);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Show Names");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.npcNames);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("PC Names");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.pcNames);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Use Tell Windows");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.bUseTellWindows);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Inviter");
				ImGui::TableNextColumn(); ImGui::Text("%s", eq.Inviter);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Auto Attack");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.bAutoAttack);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Auto Range Attack");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.bAutoRangeAttack);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Show Names Level");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.iShowNamesLevel);

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Game Options"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Gamma");
				ImGui::TableNextColumn(); ImGui::Text("%.2f", eq.gOpt.gamma);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Anonymous");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.anonymous);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Trade");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.trade);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("GuildInvites");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.guildInvites);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Sky");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.sky);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("LoD");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.lod);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("PCNames");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.pcNames);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("NPCNames");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.npcNames);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("PetOwnerNames");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.petNames);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("MercOwnerNames");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.mercNames);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("TargetHealth");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.targetHealth);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("ItemPlacementHideUI");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.itemPalcementHideUI);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("ItemPlacementDefaultModeCursor");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.gOpt.itemPlacementDefaultModeCursor);


				ImGui::TreePop();
			}

			if (pConnection)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				if (ImGui::TreeNode("Network"))
				{
					UdpLibrary::UdpConnectionStatistics stats;
					pConnection->GetStats(&stats);

					char temp[64];

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Total Bytes Sent");
					FormatBytes(temp, stats.totalBytesSent);
					ImGui::TableNextColumn(); ImGui::TextUnformatted(temp);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Total Bytes Received");
					FormatBytes(temp, stats.totalBytesReceived);
					ImGui::TableNextColumn(); ImGui::TextUnformatted(temp);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Total Packets Sent");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.totalPacketsSent);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Total Packets Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.totalPacketsReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("CRC Rejected Packets");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.crcRejectedPackets);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Order Rejected Packets");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.orderRejectedPackets);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Out Of Order Packets Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.outOfOrderPacketsReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Duplicate Packets Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.duplicatePacketsReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Out Of Range Packets Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.outOfRangePacketsReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Resent Packets Accelerated");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.resentPacketsAccelerated);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Resent Packets Timed Out");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.resentPacketsTimedOut);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Application Packets Sent");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.applicationPacketsSent);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Application Packets Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.applicationPacketsReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Iterations");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.iterations);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Corrupt Packet Errors");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.corruptPacketErrors);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Master Ping Age");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.masterPingAge);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Master Ping Time");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.masterPingTime);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Average Ping Time");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.averagePingTime);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Low Ping Time");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.highPingTime);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("High Ping Time");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.highPingTime);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Last Ping Time");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.lastPingTime);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Reliable Average Ping");
					ImGui::TableNextColumn(); ImGui::Text("%d", stats.reliableAveragePing);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Sync Our Sent");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.syncOurSent);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Sync Our Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.syncOurReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Sync Their Sent");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.syncTheirSent);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Sync Their Received");
					ImGui::TableNextColumn(); ImGui::Text("%lld", stats.syncTheirReceived);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Packet Loss: Sent");
					ImGui::TableNextColumn(); ImGui::Text("%.2f%%", (1.0 - stats.percentSentSuccess) * 100);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Packet Loss: Received");
					ImGui::TableNextColumn(); ImGui::Text("%.2f%%", (1.0 - stats.percentReceivedSuccess) * 100);

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Connection Strength");
					ImGui::TableNextColumn(); ImGui::Text("%.2f%%", pConnection->GetConnectionStrength() * 100);

					ImGui::TreePop();
				}
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Server"))
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Ruleset");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.Ruleset);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Rp Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##RpServer", &eq.bRpServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Accelerated Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##AccelServer", &eq.bAcceleratedServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Progression Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##ProgServer", &eq.bProgressionServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Progression Expansions");
				ImGui::TableNextColumn(); ImGui::Text("%" PRIX64, (int64_t)eq.ProgressionOpenExpansions);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Heroic Flag");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.bHeroicCharacterFlag);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Progression Level Cap");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.ProgressionLevelCap);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Dev Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##DevServer", &eq.bIsDevServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Beta Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##BetaServer", &eq.bIsBetaServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Test Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##TestServer", &eq.bIsTestServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Staging Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##StageServer", &eq.bIsStageServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Mail System");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##MailSystem", &eq.bUseMailSystem);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Escape Server");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##EscServer", &eq.bIsEscapeServer);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Tutorial Enabled");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##Tutorial", &eq.bIsTutorialEnabled);

#if IS_CLIENT_DATE(20250203)
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Heroic Character Related");
				ImGui::TableNextColumn(); ImGui::Text("%d, %d", (int32_t)eq.bHeroicCharacterRelated1, (int32_t)eq.bHeroicCharacterRelated2);
#endif

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Head Start Char");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##HeadStart", &eq.bCanCreateHeadStartCharacter);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Heroic Char");
				ImGui::TableNextColumn(); ImGui::SetNextItemWidth(-1); ImGui::Checkbox("##HeroicChar", &eq.bCanCreateHeroicCharacter);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Monthly Claim");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.nMonthlyClaim);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Marketplace Related");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.MarketPlaceRelated);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Heroic 85 Slots");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.Heroic85Slots);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Heroic 100 Slots");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.Heroic100Slots);

#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_TOL)
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Legacy Characters Ruleset");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.LegacyCharactersRuleset);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Num Max Characters");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.NumMaxCharacters);

				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Legacy Experience Bonus");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.LegacyExperienceBonus);
#endif
#if HAS_ALTERNATE_PERSONAS
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Num Available Personas");
				ImGui::TableNextColumn(); ImGui::Text("%d", eq.NumAvailablePersonas);
#endif

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Socials"))
			{
				for (int i = 0; i < NUM_SOCIAL_PAGES; ++i)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNode((void*)&eq.socials[i][0], "Page %d", i + 1))
					{
						for (int j = 0; j < SOCIALS_PER_PAGE; ++j)
						{
							auto& soc = eq.socials[i][j];

							ImGui::TableNextRow();
							ImGui::TableNextColumn();
							bool expand = ImGui::TreeNode(&soc, "Social %d", j + 1);
							ImGui::TableNextColumn(); ImGui::Text("%s", soc.Name);

							if (expand)
							{
								for (int l = 0; l < SOCIAL_NUM_LINES; ++l)
								{
									ImGui::TableNextRow();
									ImGui::TableNextColumn(); ImGui::Text("Line %d", l + 1);
									ImGui::TableNextColumn(); ImGui::Text("%s", soc.Line[l]);
								}

								ImGui::TableNextRow();
								ImGui::TableNextColumn(); ImGui::Text("Color Index");
								ImGui::TableNextColumn(); ImGui::Text("%d", soc.Color);

								ImGui::TableNextRow();
								ImGui::TableNextColumn(); ImGui::Text("Timer Data");
								ImGui::TableNextColumn(); ImGui::Text("%d, %d", soc.TimerBegin, soc.TimerDuration);

								ImGui::TableNextRow();
								ImGui::TableNextColumn(); ImGui::Text("Changed");
								ImGui::TableNextColumn(); ImGui::Checkbox("##Changed", &eq.bSocialChanged[i][j]);

								ImGui::TreePop();
							}
						}

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("HotButtons"))
			{
				for (int window = 0; window < NUM_HOTBUTTON_WINDOWS; ++window)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNode((void*)&eq.hotButtons[window][0][0], "Window %d", window + 1))
					{
						for (int page = 0; page < NUM_HOTBUTTON_PAGES; ++page)
						{
							ImGui::TableNextRow();
							ImGui::TableNextColumn();

							if (ImGui::TreeNode((void*)&eq.hotButtons[window][page][0], "Page %d", page + 1))
							{
								for (int button = 0; button < HOTBUTTONS_PER_PAGE; ++button)
								{
									HotButtonData& data = eq.hotButtons[window][page][button];

									ImGui::TableNextRow();
									ImGui::TableNextColumn();
									if (ImGui::TreeNode((void*)&data, "Button %d", button + 1))
									{
										DeveloperTools_DrawHotButtonData(data);

										ImGui::TreePop();
									}
								}

								ImGui::TreePop();
							}
						}

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			ImGui::TableNextRow();
			ImGui::TableNextColumn();
			if (ImGui::TreeNode("Spell Loadouts"))
			{
				for (int i = 0; i < NUM_SPELL_SETS; ++i)
				{
					auto& sl = eq.spellLoadouts[i];

					if (!sl.inuse) continue;

					// calculate upper bound;
					int last = NUM_SPELL_GEMS - 1;
					for (; last >= 0 && sl.SpellId[last] == -1; --last);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();
					bool expand = ImGui::TreeNode(&sl, "Loadout %d", i + 1);
					ImGui::TableNextColumn(); ImGui::Text("%s", sl.Name);
					if (expand)
					{
						for (int j = 0; j < last + 1; ++j)
						{
							ImGui::TableNextRow();
							ImGui::TableNextColumn(); ImGui::Text("Gem %d", j + 1);

							EQ_Spell* pSpell = GetSpellByID(sl.SpellId[j]);
							ImGui::TableNextColumn();
							if (pSpell)
								ImGui::Text("%s", pSpell->Name);
							else
								ImGui::Text("Unknown(%d)", sl.SpellId[j]);
						}

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}


			ImGui::EndTable();
		}
	}
};
static EverQuestDataInspector* s_everquestDataInspector = nullptr;

#pragma endregion

#pragma region RealEstate Inspector

class RealEstateInspector : public ImGuiWindowBase
{
public:
	RealEstateInspector() : ImGuiWindowBase("RealEstate Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~RealEstateInspector()
	{
	}

	bool IsEnabled() const override
	{
		return GetPcProfile() != nullptr && GetGameState() == GAMESTATE_INGAME;
	}

	void DrawRealEstateItemRow(const RealEstateItem* item)
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Real Estate ID");
		ImGui::TableNextColumn(); ImGui::Text("%d", item->GetRealEstateId());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Real Estate Item ID");
		ImGui::TableNextColumn(); ImGui::Text("%d", item->GetRealEstateItemId());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Item");
		if (ItemPtr pItem = item->GetItem())
		{
			ImGui::TableNextColumn();
			if (imgui::ItemLinkText(pItem->GetName(), GetColorForChatColor(USERCOLOR_LINK)))
				pItemDisplayManager->ShowItem(pItem);
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Owner Name");
		ImGui::TableNextColumn(); ImGui::Text("%s", item->GetOwnerName().c_str());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Owner Handle");
		ImGui::TableNextColumn(); ImGui::Text("%s", item->GetOwnerHandle().c_str());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Owner Name Hash Key");
		ImGui::TableNextColumn(); ImGui::Text("%d", item->GetOwnerNameHashKey());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Is Placed");
		ImGui::TableNextColumn(); ImGui::Text("%s", item->IsPlaced() ? "true" : "false");

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Upkeep Expired Time");
		ImGui::TableNextColumn(); ImGui::Text("%d", item->GetUpkeepExpiredTime());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Position");
		ImGui::TableNextColumn(); ImGui::Text("%.2f %.2f %.2f", item->GetX(), item->GetY(), item->GetZ());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Heading");
		ImGui::TableNextColumn(); ImGui::Text("%.2f", item->GetHeading());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Pitch");
		ImGui::TableNextColumn(); ImGui::Text("%.2f", item->GetPitch());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("Roll");
		ImGui::TableNextColumn(); ImGui::Text("%.2f", item->GetRoll());
	}

	void DrawRealEstateAccessListRow(const RealEstateAccess* access)
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		if (ImGui::TreeNode("Access Groups"))
		{
			for (int i = 0; i < RealEstateAccessGroup::eNumGroups; ++i)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				char szLabel[64];
				sprintf_s(szLabel, "%s (%d)", RealEstateAccessGroupToString(static_cast<RealEstateAccessGroups>(i)), i);

				if (ImGui::TreeNode(szLabel))
				{
					const RealEstateAccessGroup& group = access->accessGroups[i];

					ImGui::TableNextRow();
					ImGui::TableNextColumn(); ImGui::Text("Group");
					ImGui::TableNextColumn(); ImGui::Text("%s (%d)", RealEstateAccessGroupToString(group.group), group.group);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();
					if (ImGui::TreeNode("Capabilities"))
					{
						for (int bit = 0; bit < group.capabilities.GetNumBits(); ++bit)
						{
							if (group.capabilities.IsBitSet(bit))
							{
								ImGui::TableNextRow();
								ImGui::TableNextColumn();
								ImGui::Text("%s (%d)", RealEstateCapabilityToString(static_cast<RealEstateCapabilities>(bit)), bit);
							}
						}

						ImGui::TreePop();
					}

					ImGui::TreePop();
				}
			}

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("Members"))
		{
			for (auto& p : access->playersToGroups)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("%s", p.key().c_str());
				ImGui::TableNextColumn(); ImGui::Text("%s (%d)",
					RealEstateAccessGroupToString(static_cast<RealEstateAccessGroups>(p.value())), p.value());
			}

			ImGui::TreePop();
		}
	}

	void DrawRealEstateItemsRow(const RealEstateItems* items)
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("realEstateId");
		ImGui::TableNextColumn(); ImGui::Text("%d", items->realEstateId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("nonRealEstateItemCount");
		ImGui::TableNextColumn(); ImGui::Text("%d", items->nonRealEstateItemCount);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("npcItemCount");
		ImGui::TableNextColumn(); ImGui::Text("%d", items->npcItemCount);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("upkeepItemCount");
		ImGui::TableNextColumn(); ImGui::Text("%d", items->upkeepItemCount);

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		if (ImGui::TreeNode("realEstateItems"))
		{
			for (const auto& [id, item] : *items)
			{
				char label[256];
				sprintf_s(label, "%s (%d)", item->GetItem()->GetName(), item->GetRealEstateItemId());

				ImGui::TableNextRow();
				ImGui::TableNextColumn();

				if (ImGui::TreeNode(label))
				{
					DrawRealEstateItemRow(item);

					ImGui::TreePop();
				}
			}

			ImGui::TreePop();
		}
	}

	void DrawRealEstateDefinitionRow(const RealEstateDefinition* definition)
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("id");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->id);

		if (!definition->name.empty())
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("name");
			ImGui::TableNextColumn(); ImGui::Text("%s", definition->name.c_str());
		}

		if (!definition->description.empty())
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("description");
			ImGui::TableNextColumn(); ImGui::Text("%s", definition->description.c_str());
		}

		if (!definition->address.empty())
		{
			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("address");
			ImGui::TableNextColumn(); ImGui::Text("%s", definition->address.c_str());
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("zoneInCoords");
		ImGui::TableNextColumn(); ImGui::Text("%.2f %.2f %.2f", definition->zoneInCoords.X,
			definition->zoneInCoords.Y, definition->zoneInCoords.Z);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("areaId");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->areaId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("costDefinition");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->costDefinition);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("upkeepDefinition");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->upkeepDefinition);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("maxItems");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->maxItems);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("maxNonRealEstateItems");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->maxNonRealEstateItems);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("maxChildren");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->maxChildren);

		// 35642 = guildhall3
		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("zoneId");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->zoneId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("dzId");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->dzId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("type");
		ImGui::TableNextColumn(); ImGui::Text("%s (%d)", RealEstateTypeToString(definition->type), definition->type);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("groupId");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->groupId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("icon");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->icon);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("maxNpcItems");
		ImGui::TableNextColumn(); ImGui::Text("%d", definition->maxNpcItems);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("switchCoords");
		ImGui::TableNextColumn(); ImGui::Text("%.2f %.2f %.2f", definition->switchCoords.X,
			definition->switchCoords.Y, definition->switchCoords.Z);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("switchHeading");
		ImGui::TableNextColumn(); ImGui::Text("%.2f", definition->switchHeading);

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		if (ImGui::TreeNode("Child Definitions"))
		{
			for (int i = 0; i < definition->childDefinitions.GetCount(); ++i)
			{
				int definitionId = definition->childDefinitions[i];

				char label[64];
				sprintf_s(label, "%d", definitionId);

				ImGui::TableNextRow();
				ImGui::TableNextColumn();
				if (ImGui::TreeNode(label))
				{
					RealEstateDefinition* pDefinition = pRealEstate->definitions->definitions.FindFirst(definitionId);
					if (pDefinition)
					{
						DrawRealEstateDefinitionRow(pDefinition);
					}

					ImGui::TreePop();
				}
			}

			ImGui::TreePop();
		}
	}

	void DrawRealEstateTableRow(RealEstate* realEstate)
	{
		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("id");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->GetId());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("staticId");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->GetStaticId());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("parentId");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->GetParentId());

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		bool expandDefinition = ImGui::TreeNode("definition");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->definitionId);
		if (expandDefinition)
		{
			if (const RealEstateDefinition* pDefinition = pRealEstate->definitions->GetDefinition(realEstate->definitionId))
			{
				DrawRealEstateDefinitionRow(pDefinition);
			}

			ImGui::TreePop();
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("guildId");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->guildId.UniqueEntityID);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("fellowshipId");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->fellowshipId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("primaryOwner");
		ImGui::TableNextColumn(); ImGui::Text("%s", realEstate->primaryOwner.c_str());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("primaryHandle");
		ImGui::TableNextColumn(); ImGui::Text("%s", realEstate->primaryHandle.c_str());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("defaultPermissionLevel");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->defaultPermissionLevel);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("dynamicName");
		ImGui::TableNextColumn(); ImGui::Text("%s", realEstate->dynamicName.c_str());

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("defaultUpkeepId");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->defaultUpkeepId);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("upkeepExpiredTime");
		ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->upkeepExpiredTime);

		ImGui::TableNextRow();
		ImGui::TableNextColumn(); ImGui::Text("votingOptedOut");
		ImGui::TableNextColumn(); ImGui::Text("%s", realEstate->votingOptedOut ? "true" : "false");

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		if (ImGui::TreeNode("Escrow Account"))
		{
			for (auto [id, amount] : realEstate->escrowAccount)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("Type %d", id);
				ImGui::TableNextColumn(); ImGui::Text("%.2f", amount);
			}

			ImGui::TreePop();
		}

		ImGui::TableNextRow();
		ImGui::TableNextColumn();
		if (ImGui::TreeNode("Children"))
		{
			for (int i = 0; i < realEstate->childIds.GetCount(); ++i)
			{
				ImGui::TableNextRow();
				ImGui::TableNextColumn(); ImGui::Text("%d", i + 1);
				ImGui::TableNextColumn(); ImGui::Text("%d", realEstate->childIds[i].UniqueEntityID);
			}

			ImGui::TreePop();
		}
	}

	void Draw() override
	{
		RealEstateManagerClient* pMgr = pRealEstate;

		if (ImGui::BeginTable("##RealEstateTable", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			//----------------------------------------------------------------------------
			// realEstates - RealEstate by realEstateId

			if (ImGui::TreeNode("realEstates"))
			{
				for (const auto& p : pMgr->realEstates)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					char label[64];
					sprintf_s(label, "%d##%p", p.key(), (void*)&p);

					if (ImGui::TreeNode(label))
					{
						RealEstate* realEstate = p.value();

						DrawRealEstateTableRow(realEstate);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			//----------------------------------------------------------------------------
			// realEstatesByOwnerName

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("realEstatesByOwnerName"))
			{
				for (const auto& p : pMgr->realEstatesByOwnerName)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					char label[64];
					sprintf_s(label, "%s##%p", p.key().c_str(), (void*)&p);

					if (ImGui::TreeNode(label))
					{
						RealEstate* realEstate = p.value();

						DrawRealEstateTableRow(realEstate);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			//----------------------------------------------------------------------------
			// guildPlotsByGuildId

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("guildPlotsByGuildId"))
			{
				RealEstateManager::RealEstateHolder* ppRealEstate = pMgr->guildPlotsByGuildId.GetFirst();
				if (ppRealEstate)
				{
					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					RealEstate* realEstate = ppRealEstate->realEstate;
					EqGuid key = pMgr->guildPlotsByGuildId.GetKey(ppRealEstate);


					char label[64];
					sprintf_s(label, "%d##%p", key.UniqueEntityID, (void*)ppRealEstate);

					if (ImGui::TreeNode(label))
					{
						DrawRealEstateTableRow(realEstate);

						ImGui::TreePop();
					}

					ppRealEstate = pMgr->guildPlotsByGuildId.GetNext(ppRealEstate);
				}

				ImGui::TreePop();
			}

			//----------------------------------------------------------------------------
			// realEstateAccessLists

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("accessLists"))
			{
				for (auto& [realEstateId, accessList] : pMgr->accessLists)
				{
					char label[64];
					sprintf_s(label, "%d", realEstateId);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNode(label))
					{
						DrawRealEstateAccessListRow(accessList);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}


			//----------------------------------------------------------------------------
			// realEstateItemLists

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("itemLists"))
			{
				for (auto& [realEstateId, itemsClient] : pMgr->itemLists)
				{
					char label[64];
					sprintf_s(label, "%d", realEstateId);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNode(label))
					{
						DrawRealEstateItemsRow(itemsClient);

						ImGui::TreePop();
					}
				}

				ImGui::TreePop();
			}

			//----------------------------------------------------------------------------
			// definitions

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("definitions"))
			{
				for (const auto& p : pMgr->definitions->definitions)
				{
					const RealEstateDefinition& def = p.value();

					char label[64];
					sprintf_s(label, "%d", def.id);

					ImGui::TableNextRow();
					ImGui::TableNextColumn();

					if (ImGui::TreeNode(label))
					{
						DrawRealEstateDefinitionRow(&def);

						ImGui::TreePop();
					}

				}
				ImGui::TreePop();
			}

			//----------------------------------------------------------------------------
			// RealEstateManager data

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("zoneRealEstateId");
			ImGui::TableNextColumn(); ImGui::Text("%d", pMgr->zoneRealEstateId);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("zoneRealEstateType");
			ImGui::TableNextColumn(); ImGui::Text("%s (%d)", RealEstateTypeToString(pMgr->zoneRealEstateType), pMgr->zoneRealEstateType);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("currentRealEstateId");
			ImGui::TableNextColumn(); ImGui::Text("%d", pMgr->currentRealEstateId);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("currentYardId");
			ImGui::TableNextColumn(); ImGui::Text("%d", pMgr->currentYardId);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("currentHouseId");
			ImGui::TableNextColumn(); ImGui::Text("%d", pMgr->currentHouseId);

			ImGui::TableNextRow();
			ImGui::TableNextColumn(); ImGui::Text("currentMovingCrateId");
			ImGui::TableNextColumn(); ImGui::Text("%d", pMgr->currentMovingCrateId);

			ImGui::EndTable();
		}
	}
};
static RealEstateInspector* s_realEstateInspector = nullptr;

#pragma endregion

#pragma region Spells Inspector

class SpellsInspector : public ImGuiWindowBase
{
	CTextureAnimation* m_pTASpellIcon = nullptr;
public:
	SpellsInspector() : ImGuiWindowBase("Spells & Buffs Developer Tools")
	{
		SetDefaultSize(ImVec2(700, 400));
	}

	~SpellsInspector() override
	{
		if (m_pTASpellIcon)
		{
			delete m_pTASpellIcon;
			m_pTASpellIcon = nullptr;
		}
	}

	static void DoSpellBuffTableHeaders()
	{
		ImGui::TableSetupColumn("Index");
		ImGui::TableSetupColumn("Icon");
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
			ImGui::TableSetupColumn(temp);
		}

		ImGui::TableHeadersRow();
	}

	void DoSpellBuffTableRow(int index, EQ_Affect& buff)
	{
		EQ_Spell* spell = GetSpellByID(buff.SpellID);
		if (!spell)
			return;

		ImGui::PushID((void*)&buff);

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

		if (ImGui::BeginPopupContextItem("BuffContextMenu"))
		{
			if (ImGui::Selectable("Inspect"))
			{
				char buffer[512] = { 0 };
				FormatSpellLink(buffer, 512, spell);

				TextTagInfo info = ExtractLink(buffer);
				ExecuteTextLink(info);
			}

			ImGui::Separator();

			if (ImGui::Selectable("Remove by Index"))
			{
				int nBuff = pLocalPC->GetEffectSlot(&buff);
				RemoveBuffByIndex(nBuff);
			}

			if (spell && ImGui::Selectable("Remove by Name"))
			{
				RemoveBuffByName(spell->Name);
			}

			if (ImGui::Selectable("Remove by Spell ID"))
			{
				RemoveBuffBySpellID(buff.SpellID);
			}

			ImGui::EndPopup();
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
			int64_t Value = slotData.Value;

			if (Slot != -1)
				ImGui::Text("%d: %I64", Slot, Value);
		}

		ImGui::PopID();
	}

	template <typename Iter>
	int DoSpellAffectTable(const char* name, Iter first, Iter second, bool showEmpty = false)
	{
		ImGuiTableFlags tableFlags = 0
			| ImGuiTableFlags_SizingFixedFit
			| ImGuiTableFlags_ScrollY | ImGuiTableFlags_ScrollX
			| ImGuiTableFlags_RowBg
			| ImGuiTableFlags_Borders
			| ImGuiTableFlags_Resizable;

		int count = 2; // start with space for header and possible scroll bar

		// calculate the size
		for (auto iter = first; iter != second; ++iter)
		{
			EQ_Affect& buff = *iter;
			if (buff.SpellID == 0 && !showEmpty)
				continue;

			count++;
		}
		count = 0;

		if (ImGui::BeginTable(name, 17 + NUM_SLOTDATA, tableFlags))
		{
			ImGui::TableSetupScrollFreeze(2, 1);
			DoSpellBuffTableHeaders();
			int i = 0;

			for (auto iter = first; iter != second; ++iter)
			{
				EQ_Affect& buff = *iter;
				++i;

				if (buff.SpellID == 0 && !showEmpty)
					continue;

				DoSpellBuffTableRow(i, buff);
				count++;
			}

			ImGui::EndTable();
		}
		return count;
	}

	static void FormatBuffDuration(char* timeLabel, size_t size, int buffTimer)
	{
		if (buffTimer < 0)
		{
			strcpy_s(timeLabel, size, "Permanent");
		}
		else if (buffTimer > 0)
		{
			int hours = 0;
			int minutes = 0;
			int seconds = 0;

			int totalSeconds = buffTimer / 1000;

			if (totalSeconds > 0)
			{
				hours = totalSeconds / 3600;
				minutes = (totalSeconds % 3600) / 60;
				seconds = totalSeconds % 60;
			}

			if (hours > 0)
			{
				if (minutes > 0 && seconds > 0)
				{
					sprintf_s(timeLabel, size, "%dh %dm %ds", hours, minutes, seconds);
				}
				else if (minutes > 0)
				{
					sprintf_s(timeLabel, size, "%dh %dm", hours, minutes);
				}
				else if (seconds > 0)
				{
					sprintf_s(timeLabel, size, "%dh %ds", hours, seconds);
				}
				else
				{
					sprintf_s(timeLabel, size, "%dh", hours);
				}
			}
			else if (minutes > 0)
			{
				if (seconds > 0)
				{
					sprintf_s(timeLabel, size, "%dm %ds", minutes, seconds);
				}
				else
				{
					sprintf_s(timeLabel, size, "%dm", minutes);
				}
			}
			else
			{
				sprintf_s(timeLabel, size, "%ds", seconds);
			}
		}
		else
		{
			strcpy_s(timeLabel, size, "0s");
		}
	}

	template <typename T>
	void DoBuffsTable(const char* name, IteratorRange<PlayerBuffInfoWrapper::Iterator<T>> Buffs,
		bool petBuffs = false, bool playerBuffs = false, int baseIndex = 0)
	{
		ImGuiTableFlags tableFlags = 0
			| ImGuiTableFlags_SizingFixedFit
			| ImGuiTableFlags_ScrollY | ImGuiTableFlags_ScrollX
			| ImGuiTableFlags_RowBg
			| ImGuiTableFlags_Borders
			| ImGuiTableFlags_Resizable;

		if (ImGui::BeginTable(name, 6, tableFlags))
		{
			ImGui::TableSetupScrollFreeze(2, 1);
			
			ImGui::TableSetupColumn("Index", ImGuiTableColumnFlags_WidthFixed, 30.0f);
			ImGui::TableSetupColumn("Icon", ImGuiTableColumnFlags_WidthFixed, 24.0f);
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Spell ID", ImGuiTableColumnFlags_WidthFixed, 46.0f);
			ImGui::TableSetupColumn("Duration", ImGuiTableColumnFlags_WidthFixed, 78.0f);
			ImGui::TableSetupColumn("Caster", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableHeadersRow();

			for (const auto& buffInfo : Buffs)
			{
				EQ_Spell* spell = buffInfo.GetSpell();
				if (!spell)
					continue;

				ImGui::PushID(buffInfo.GetIndex());

				if (!m_pTASpellIcon)
				{
					m_pTASpellIcon = new CTextureAnimation();
					if (CTextureAnimation* temp = pSidlMgr->FindAnimation("A_SpellGems"))
						*m_pTASpellIcon = *temp;
				}

				ImGui::TableNextRow();

				// Index
				ImGui::TableNextColumn();
				ImGui::Text("%d", buffInfo.GetIndex() + 1 + baseIndex);

				// Icon
				ImGui::TableNextColumn();
				if (spell)
				{
					m_pTASpellIcon->SetCurCell(spell->SpellIcon);
					imgui::DrawTextureAnimation(m_pTASpellIcon);
				}

				// Name
				ImGui::TableNextColumn();
				if (spell)
				{
					ImGui::Text("%s", spell->Name);
				}
				else
				{
					ImGui::Text("");
				}

				if (spell)
				{
					if (ImGui::BeginPopupContextItem("BuffContextMenu"))
					{
						if (ImGui::Selectable("Inspect"))
						{
							char buffer[512] = { 0 };
							FormatSpellLink(buffer, 512, spell);

							TextTagInfo info = ExtractLink(buffer);
							ExecuteTextLink(info);
						}

						if (petBuffs)
						{
							ImGui::Separator();

							if (ImGui::Selectable("Remove Pet Buff"))
							{
								RemovePetBuffByName(spell->Name);
							}
						}
						else if (playerBuffs)
						{
							if (ImGui::Selectable("Remove by Index"))
							{
								RemoveBuffByIndex(buffInfo.GetIndex() + baseIndex);
							}

							if (ImGui::Selectable("Remove by Name"))
							{
								RemoveBuffByName(spell->Name);
							}

							if (ImGui::Selectable("Remove by Spell ID"))
							{
								RemoveBuffBySpellID(buffInfo.GetSpellID());
							}
						}

						ImGui::EndPopup();
					}
				}

				// ID
				ImGui::TableNextColumn();
				ImGui::Text("%d", buffInfo.GetSpellID());

				// Duration
				ImGui::TableNextColumn();

				char timeLabel[64];
				FormatBuffDuration(timeLabel, 64, buffInfo.GetBuffTimer());
				ImGui::Text("%s", timeLabel);

				// Caster
				ImGui::TableNextColumn();
				ImGui::Text("%s", buffInfo.GetCaster());

				ImGui::PopID();
			}

			ImGui::EndTable();
		}
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

	void DoSpellStackingTests()
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

	virtual void Draw() override
	{
		PcProfile* pcProfile = GetPcProfile();
		if (!pcProfile)
		{
			ImGui::TextColored(ImColor(255, 0, 0), "You must be in game to use this");
			return;
		}

		if (ImGui::BeginTabBar("##SpellTabs"))
		{
			int arrayLength = MAX_TOTAL_BUFFS;
			int count = 0;

			// calculate the size
			for (int i = 0; i < pcProfile->GetMaxEffects(); ++i)
			{
				if (pcProfile->GetEffect(i).SpellID > 0)
					count++;
			}

			char szLabel[64];

			if (pBuffWnd)
			{
				sprintf_s(szLabel, "Buffs (%d)###Buffs", pBuffWnd->GetTotalBuffCount());

				if (ImGui::BeginTabItem(szLabel))
				{
					DoBuffsTable("BuffsTable", pBuffWnd->GetBuffRange(), false, true, pBuffWnd->firstEffectSlot);

					ImGui::EndTabItem();
				}
			}

			if (pSongWnd)
			{
				sprintf_s(szLabel, "Short Buffs (%d)###ShortBuffs", pSongWnd->GetTotalBuffCount());

				if (ImGui::BeginTabItem(szLabel))
				{
					DoBuffsTable("ShortBuffsTable", pSongWnd->GetBuffRange(), false, true, pSongWnd->firstEffectSlot);

					ImGui::EndTabItem();
				}
			}

			if (pPetInfoWnd)
			{
				sprintf_s(szLabel, "Pet Buffs (%d)###PetBuffs", pPetInfoWnd->GetTotalBuffCount());

				if (ImGui::BeginTabItem(szLabel))
				{
					DoBuffsTable("PetBuffsTable", pPetInfoWnd->GetBuffRange(), true);

					ImGui::EndTabItem();
				}
			}

			if (pTargetWnd)
			{
				sprintf_s(szLabel, "Target Buffs (%d)###TargetBuffs", pTargetWnd->GetTotalBuffCount());

				if (ImGui::BeginTabItem(szLabel))
				{
					DoBuffsTable("TargetBuffsTable", pTargetWnd->GetBuffRange(), false);

					ImGui::EndTabItem();
				}
			}

			if (ImGui::BeginTabItem("Stacking Tests"))
			{
				DoSpellStackingTests();

				ImGui::EndTabItem();
			}

			sprintf_s(szLabel, "Spell Affects (%d)###SpellBuffs", count);

			if (ImGui::BeginTabItem(szLabel))
			{
				DoSpellAffectTable("SpellAffectBuffsTable", std::begin(pcProfile->Buffs), std::end(pcProfile->Buffs), arrayLength);
				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
	}
};
static SpellsInspector* s_spellsInspector = nullptr;

#pragma endregion

#pragma region Benchmarks Inspector

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
		SetDefaultSize(ImVec2(1000, 600));
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

		DrawPlot();

		if (ImGui::CollapsingHeader("Benchmark Table"))
		{
			DrawTable();
		}

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



		if (ImPlot::BeginPlot("##Benchmarks", ImVec2(-1, -1), 0))
		{
			ImPlot::SetupAxis(ImAxis_X1, "Time");
			ImPlot::SetupAxis(ImAxis_Y1, "Milliseconds", ImPlotAxisFlags_LockMin);
			ImPlot::SetupAxis(ImAxis_Y2, "Percent", ImPlotAxisFlags_LockMin);
			ImPlot::SetupAxis(ImAxis_Y3, "Frames Per Second", ImPlotAxisFlags_LockMin | ImPlotAxisFlags_Opposite);
			ImPlot::SetupAxisLimits(ImAxis_X1, static_cast<double>(m_time) - m_history, m_time, ImGuiCond_Always);
			ImPlot::SetupAxisLimits(ImAxis_Y1, 0, 40, ImGuiCond_Appearing);
			ImPlot::SetupAxisLimits(ImAxis_Y2, 0, 100, ImGuiCond_Always);
			ImPlot::SetupAxisLimits(ImAxis_Y3, 0, 60, ImGuiCond_Appearing);
			ImPlot::SetAxes(ImAxis_X1, ImAxis_Y1);


			for (const auto& p : m_data)
			{
				auto& data = p.second;
				ImPlot::PlotLine(data->Name.c_str(), &data->Data[0].x, &data->Data[0].y,
					data->Data.size(), ImPlotLineFlags_None, data->Offset, sizeof(ImVec2));
			}

			if (!m_fpsData.Data.empty())
			{
				ImPlot::SetAxes(ImAxis_X1, ImAxis_Y3);
				ImPlot::PushStyleColor(ImPlotCol_Line, IM_COL32(127, 255, 0, 255));
				ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, 2);
				ImPlot::PlotLine("Frame Rate", &m_fpsData.Data[0].x, &m_fpsData.Data[0].y,
					m_fpsData.Data.size(), ImPlotLineFlags_None, m_fpsData.Offset, sizeof(ImVec2));
				ImPlot::PopStyleVar();
				ImPlot::PopStyleColor();
			}

			if (!m_cpuData.Data.empty())
			{
				ImPlot::SetAxes(ImAxis_X1, ImAxis_Y2);
				ImPlot::PushStyleColor(ImPlotCol_Line, IM_COL32(127, 127, 255, 255));
				ImPlot::PushStyleVar(ImPlotStyleVar_LineWeight, 2);
				ImPlot::PlotLine("CPU Usage %", &m_cpuData.Data[0].x, &m_cpuData.Data[0].y,
					m_cpuData.Data.size(), ImPlotLineFlags_None, m_cpuData.Offset, sizeof(ImVec2));
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

#pragma region Switch Inspector

// FIXME: Pull these helpers out
inline bool IsSwitchStationary(EQSwitch* pSwitch)
{
	int typeId = pSwitch->Type;

	return (typeId != 53 && typeId >= 50 && typeId < 59)
		|| (typeId >= 153 && typeId <= 155);
}

inline bool IsSwitchTeleporter(EQSwitch* pSwitch)
{
	int typeId = pSwitch->Type;
	DWORD TableSize = *(DWORD*)Teleport_Table_Size;

	return (typeId == 57 || typeId == 58) && pSwitch->SpellID > -1 && (pSwitch->SpellID < (int)TableSize);
}

class ImGuiSwitchViewer
{
	int m_instanceId = 0;
	std::string m_windowDisplayName;
	std::string m_viewerTitle;
	bool m_needDock = true;
	bool m_needFocus = false;
	ImGuiID m_windowId = 0;

	int m_id = -1;

public:
	ImGuiSwitchViewer()
	{
		static int nextInstanceId = 1;
		m_instanceId = nextInstanceId++;
	}

	void SetNeedDock(bool dock) { m_needDock = dock; }
	bool GetNeedDock() const { return m_needDock; }

	void SetNeedFocus(bool needFocus) { m_needFocus = needFocus; }
	const char* GetWindowIdStr() const { return m_viewerTitle.c_str(); }

	int GetInstanceId() const { return m_instanceId; }
	ImGuiID GetWindowId() const { return m_windowId; }

	void SetSwitchId(int id)
	{
		if (!test_and_set(m_id, id))
			return;

		m_needFocus = true;

		if (m_id >= 0)
		{
			const EQSwitch* pSwitch = pSwitchMgr->GetSwitchById(m_id);
			if (pSwitch)
			{
				m_windowDisplayName = fmt::format("{} ({})", pSwitch->Name, pSwitch->ID);
			}
			else
			{
				m_windowDisplayName = fmt::format("Switch {}", m_id);
			}

		}

		m_viewerTitle = fmt::format("{}###SwitchViewer{}", m_windowDisplayName, m_instanceId);
	}
	int GetSwitchId() const { return m_id; }

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

			if (!pSwitchMgr)
			{
				open = false;
			}
			else
			{
				EQSwitch* pSwitch = pSwitchMgr->GetSwitchById(m_id);
				if (!pSwitch)
				{
					open = false;
				}
				else
				{
					DisplaySwitchData(pSwitch);
				}
			}
		}
		ImGui::End();

		return open;
	}

	void DisplaySwitchData(EQSwitch* pSwitch)
	{
		if (ImGui::SmallButton("Click"))
		{
			pSwitch->UseSwitch(pLocalPlayer->SpawnID, -1, 0, nullptr);
		}
		ImGui::SameLine();
		if (ImGui::SmallButton("Target"))
		{
			DoCommandf("/doortarget id %d", pSwitch->ID);
		}

		if (ImGui::BeginTable("##SwitchPropertiesTable", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Value", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("ID"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->ID);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Name"); ImGui::TableNextColumn(); ImGui::Text("%s", pSwitch->Name);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Type"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->Type);

			if (IsSwitchTeleporter(pSwitch))
			{
				ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Zone Point"); ImGui::TableNextColumn();

				DWORD TableSize = *(DWORD*)Teleport_Table_Size;

				const char* zone = GetTeleportName(pSwitch->SpellID);
				ImGui::TextColored(ImColor(0, 255, 0), "%s (%d)", zone, pSwitch->SpellID);
				if (pSwitch->SpellID < (int)TableSize)
				{
					tp_coords* tp = ((tp_coords*)Teleport_Table) + pSwitch->SpellID;

					ImGui::SameLine();
					ImGui::Text("(%.2f, %.2f, %.2f)", tp->Y, tp->X, tp->Z);
				}
			}

			if (pSwitch->AdventureDoorID > 0)
			{
				ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Adventure Switch ID"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->AdventureDoorID);
			}

			if (pSwitch->DynDoorID > 0)
			{
				ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Dynamic Switch ID"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->DynDoorID);
			}

			if (pSwitch->RealEstateDoorID > 0)
			{
				ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Real Estate Door ID"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->RealEstateDoorID);
			}


			ImGui::Separator();

			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("State"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->State);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Position"); ImGui::TableNextColumn(); ImGui::Text("%.2f, %.2f, %.2f",
				pSwitch->Y, pSwitch->X, pSwitch->Z);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Heading"); ImGui::TableNextColumn(); ImGui::Text("%.2f", pSwitch->Heading);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Angle"); ImGui::TableNextColumn(); ImGui::Text("%.2f", pSwitch->DoorAngle);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Scale"); ImGui::TableNextColumn(); ImGui::Text("%.2f",
				static_cast<float>(pSwitch->ScaleFactor) / 100.0f);

			ImGui::Separator();

			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Default State"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->DefaultState);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Default Position"); ImGui::TableNextColumn(); ImGui::Text("%.2f, %.2f, %.2f",
				pSwitch->DefaultY, pSwitch->DefaultX, pSwitch->DefaultZ);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Default Heading"); ImGui::TableNextColumn(); ImGui::Text("%.2f", pSwitch->DefaultHeading);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Default Angle"); ImGui::TableNextColumn(); ImGui::Text("%.2f", pSwitch->DefaultDoorAngle);

			ImGui::Separator();

			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Top Speed"); ImGui::TableNextColumn(); ImGui::Text("%.2f, %.2f",
				pSwitch->TopSpeed1, pSwitch->TopSpeed2);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Self Activated"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->SelfActivated);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Dependent"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->Dependent);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Template"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bTemplate);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Difficulty"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->Difficulty);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Key"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->Key);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Custom Data"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->SpellID);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Script"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->Script);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("TimeStamp"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->TimeStamp);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Always Active"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->AlwaysActive);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Return Position"); ImGui::TableNextColumn(); ImGui::Text("%.2f, %.2f, %.2f",
				pSwitch->ReturnY, pSwitch->ReturnX, pSwitch->ReturnZ);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Has Script"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bHasScript);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Filter ID"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->SomeID);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Usable"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bUsable);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Remain Open"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bRemainOpen);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Visible"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bVisible);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Heading Changed"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bHeadingChanged);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Allow Corpse Drag"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->bAllowCorpseDrag);

			ImGui::Separator();

			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Target Slots"); ImGui::TableNextColumn(); ImGui::Text("%d %d %d %d %d", pSwitch->AffectSlots[0], pSwitch->AffectSlots[1], pSwitch->AffectSlots[2], pSwitch->AffectSlots[3], pSwitch->AffectSlots[4]);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Target"); ImGui::TableNextColumn(); ImGui::Text("%d %d %d %d %d", pSwitch->TargetID[0], pSwitch->TargetID[1], pSwitch->TargetID[2], pSwitch->TargetID[3], pSwitch->TargetID[4]);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Current Combo"); ImGui::TableNextColumn(); ImGui::Text("%d %d %d %d %d", pSwitch->CurrentCombination[0], pSwitch->CurrentCombination[1], pSwitch->CurrentCombination[2], pSwitch->CurrentCombination[3], pSwitch->CurrentCombination[4]);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Required Combo"); ImGui::TableNextColumn(); ImGui::Text("%d %d %d %d %d", pSwitch->ReqCombination[0], pSwitch->ReqCombination[1], pSwitch->ReqCombination[2], pSwitch->ReqCombination[3], pSwitch->ReqCombination[4]);
			ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text("Random Combo"); ImGui::TableNextColumn(); ImGui::Text("%d", pSwitch->RandomCombo);

			ImGui::EndTable();
		}
	}
};

class SwitchInspector : public ImGuiWindowBase
{
	std::unordered_map<int, float> m_distanceCache;
	glm::vec3 m_lastPos;
	std::vector<EQSwitch*> m_switches;
	const EQSwitch* m_lastFirstSwitch = nullptr;
	bool m_sortingByDistance = false;
	bool m_positionChanged = false;
	int m_lastDoorTargetId = -1;

	int m_selectedSwitchId = -1;
	bool m_selectionChanged = false;

	std::map<int, ImGuiSwitchViewer> m_viewers;
	ImGuiID m_topNode = 0;
	ImGuiID m_bottomNode = 0;
	ImGuiID m_mainDockID = 0;

public:
	SwitchInspector() : ImGuiWindowBase("Switch Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~SwitchInspector()
	{
	}

	bool IsEnabled() const override
	{
		return pSwitchMgr != nullptr;
	}

	void UpdateSwitches()
	{
		if (!pSwitchMgr)
		{
			m_switches.clear();
			m_distanceCache.clear();
		}

		glm::vec3 myPos{ pLocalPlayer->X, pLocalPlayer->Y, pLocalPlayer->Z };
		if (myPos != m_lastPos)
		{
			m_lastPos = myPos;
			m_positionChanged = true;
			m_distanceCache.clear();
		}

		if (m_switches.size() != pSwitchMgr->NumEntries
			|| m_lastFirstSwitch != pSwitchMgr->GetSwitch(0))
		{
			m_switches.resize(pSwitchMgr->NumEntries);
			m_lastFirstSwitch = pSwitchMgr->GetSwitch(0);
			m_distanceCache.clear();

			for (int i = 0; i < pSwitchMgr->NumEntries; ++i)
			{
				m_switches[i] = pSwitchMgr->GetSwitch(i);
			}
		}

		m_lastDoorTargetId = pSwitchTarget ? pSwitchTarget->ID : -1;
	}

	void SetSelectedSwitchId(int switchId)
	{
		if (test_and_set(m_selectedSwitchId, switchId))
			m_selectionChanged = true;
	}

	void DrawSwitchesInspectorWindow()
	{
		if (!pSwitchMgr || !pLocalPlayer) return;

		UpdateSwitches();

		ImGui::Text("%d switch objects", m_switches.size());

		enum MyItemColumnID
		{
			ColumnID_ID,
			ColumnID_Name,
			ColumnID_Type,
			ColumnID_Distance,
			ColumnID_Extras,
		};

		if (ImGui::BeginTable("##SwitchTable", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti
			| ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_PreferSortAscending, 40.f);
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, 50.f);
			ImGui::TableSetupColumn("Distance", ImGuiTableColumnFlags_WidthFixed, 100.f);
			ImGui::TableSetupColumn("##Extras", ImGuiTableColumnFlags_WidthStretch | ImGuiTableColumnFlags_NoSort);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGuiTableSortSpecs* sort_specs = ImGui::TableGetSortSpecs();

			if (sort_specs->SpecsDirty || (m_sortingByDistance && m_positionChanged))
			{
				std::sort(m_switches.begin(), m_switches.end(),
					[&](const EQSwitch* a, const EQSwitch* b)
				{
					m_sortingByDistance = false;
					for (int n = 0; n < sort_specs->SpecsCount; ++n)
					{
						const ImGuiTableColumnSortSpecs* sort_spec = &sort_specs->Specs[n];
						int delta = 0;

						switch (sort_spec->ColumnIndex)
						{
						case ColumnID_ID: delta = a->ID - b->ID; break;
						case ColumnID_Name: delta = _stricmp(a->Name, b->Name); break;
						case ColumnID_Type: delta = a->Type - b->Type; break;
						case ColumnID_Distance: {
							float deltaF = GetDistance(a) - GetDistance(b);
							m_sortingByDistance = true;
							if (deltaF < 0)
								return sort_spec->SortDirection == ImGuiSortDirection_Ascending;
							if (deltaF > 0)
								return sort_spec->SortDirection == ImGuiSortDirection_Descending;
							continue;
						};
						default: break;
						}

						if (delta < 0)
							return sort_spec->SortDirection == ImGuiSortDirection_Ascending;
						if (delta > 0)
							return sort_spec->SortDirection == ImGuiSortDirection_Descending;
					}

					return a->ID < b->ID;
				});

				sort_specs->SpecsDirty = false;
				m_positionChanged = false;
			}

			for (EQSwitch* pSwitch : m_switches)
			{
				bool targetted = (m_lastDoorTargetId == pSwitch->ID);
				bool selected = (m_selectedSwitchId == pSwitch->ID);

				ImGui::PushID(pSwitch->ID);
				ImGui::TableNextRow();

				if (targetted)
					ImGui::PushStyleColor(ImGuiCol_Text, MQColor(0, 255, 0).ToImU32());

				ImGui::TableNextColumn();

				char label[32];
				sprintf_s(label, "%d", pSwitch->ID);

				if (ImGui::Selectable(label, selected, ImGuiSelectableFlags_SpanAllColumns | ImGuiSelectableFlags_AllowOverlap))
				{
					if (ImGui::GetIO().KeyCtrl)
						ShowSwitchViewer(pSwitch->ID, true);
					else
						SetSelectedSwitchId(pSwitch->ID);
				}

				ImGui::TableNextColumn();
				ImGui::Text("%s", pSwitch->Name);

				if (ImGui::BeginPopupContextItem(""))
				{
					ImGui::TextColored(achGoldColor.ToImColor(), "%s", pSwitch->Name);
					ImGui::Separator();

					if (ImGui::Selectable("Open in new viewer"))
						ShowSwitchViewer(pSwitch->ID, true);
					if (ImGui::Selectable("Copy ID"))
					{
						char idText[32];
						sprintf_s(idText, "%d", pSwitch->ID);

						ImGui::SetClipboardText(idText);
					}
					if (ImGui::Selectable("Copy Name"))
						ImGui::SetClipboardText(pSwitch->Name);

					ImGui::EndPopup();
				}

				ImGui::TableNextColumn();
				ImGui::Text("%d", pSwitch->Type);

				ImGui::TableNextColumn();
				ImGui::Text("%.2f", GetDistance(pSwitch));

				ImGui::TableNextColumn();

				if (targetted)
					ImGui::PopStyleColor();

				if (ImGui::SmallButton("Click"))
				{
					pSwitch->UseSwitch(pLocalPlayer->SpawnID, -1, 0, nullptr);
				}

				if (targetted)
				{
					ImGui::SameLine();
					ImGui::Text("<target>");
				}
				else
				{
					ImGui::SameLine();
					if (ImGui::SmallButton("Target"))
					{
						DoCommandf("/doortarget id %d", pSwitch->ID);
					}
				}

				if (IsSwitchStationary(pSwitch))
				{
					ImGui::SameLine();
					ImGui::Text("*stationary*");
				}

				if (IsSwitchTeleporter(pSwitch))
				{
					ImGui::SameLine();

					const char* dest = GetTeleportName(pSwitch->SpellID);
					ImGui::Text("*teleporter: %s*", dest);
				}

				ImGui::PopID();
			}

			ImGui::EndTable();
		}
	}

	void Update() override
	{
		if (m_mainDockID == 0)
		{
			m_mainDockID = ImGui::GetID("SwitchInspector");
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

			ImGui::DockBuilderDockWindow(m_windowId.c_str(), m_topNode);
			ImGui::DockBuilderFinish(m_mainDockID);
		}

		if (m_open)
		{
			bool doShow = ImGui::Begin("Switch Inspector", m_open.get_ptr());
			m_open.Update();
			if (doShow)
			{
				DrawSwitchesInspectorWindow();
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
			if (m_selectedSwitchId != -1)
				ShowSwitchViewer(m_selectedSwitchId, false);

			m_selectionChanged = false;
		}

		DrawSwitchViewers();
	}

	void ShowSwitchViewer(int switchId, bool createNew)
	{
		if (!createNew)
		{
			auto iter = std::find_if(std::begin(m_viewers), std::end(m_viewers),
				[switchId](const auto& p) { return p.second.GetSwitchId() == switchId; });
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
					iter->second.SetSwitchId(switchId);
					return;
				}
			}
		}

		auto [iter, _] = m_viewers.emplace(
			std::piecewise_construct,
			std::forward_as_tuple(switchId),
			std::forward_as_tuple());
		iter->second.SetSwitchId(switchId);
	}

	void RemoveAchievementViewers(int achievementId)
	{
		m_viewers.erase(achievementId);
	}

	void DrawSwitchViewers()
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

	float GetDistance(const EQSwitch* pSwitch)
	{
		auto iter = m_distanceCache.find(static_cast<int>(pSwitch->ID));
		if (iter != m_distanceCache.end())
			return iter->second;

		glm::vec3 switchPos{ pSwitch->DefaultX, pSwitch->DefaultY, pSwitch->DefaultZ };
		float distance = glm::distance(m_lastPos, switchPos);

		m_distanceCache[static_cast<int>(pSwitch->ID)] = distance;
		return distance;
	}
};
static SwitchInspector* s_switchInspector = nullptr;

#pragma endregion

#pragma region Zone Inspector


class ZoneInspector : public ImGuiWindowBase
{
public:
	ZoneInspector() : ImGuiWindowBase("Zone Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~ZoneInspector()
	{
	}

	bool IsEnabled() const override
	{
		return GetPcProfile() != nullptr && GetGameState() == GAMESTATE_INGAME;
	}

	void Draw() override
	{
		if (ImGui::BeginTable("##ZoneDataTable", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

			if (ImGui::TreeNode("zone Header"))
			{
				zoneHeader* hdr = pZoneInfo;

#define TableRow(label, format, ...) \
	ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text(label); \
	ImGui::TableNextColumn(); ImGui::Text(format, __VA_ARGS__);

				TableRow("Short Name", "%s", hdr->ShortName);
				TableRow("Long Name", "%s", hdr->LongName);
				TableRow("Weather Type", "%s", hdr->WeatherType);
				TableRow("Weather Type Override", "%s", hdr->WeatherTypeOverride);
				TableRow("Sky Type", "%s", hdr->SkyType); // short name (lowercase?)
				TableRow("Sky Type Override", "%s", hdr->SkyTypeOverride);
				TableRow("Zone Type", "%d", hdr->ZoneType);
				TableRow("Designer ZoneID", "%d", hdr->ZoneID);
				TableRow("Zone XP Modifier", "%f", hdr->ZoneExpModifier);
				TableRow("Fog Density", "%f", hdr->FogDensity);

				const char* seasons[4] = {
					"Winter",
					"Spring",
					"Summer",
					"Fall"
				};

				for (int i = 0; i < 4; ++i)
				{
					char label[32];
					sprintf_s(label, "%s Environment", seasons[i]);

					ImGui::TableNextRow(); ImGui::TableNextColumn();
					if (ImGui::TreeNode(label))
					{
						TableRow("Fog Start", "%f", hdr->FogStart[i]);
						TableRow("Fog End", "%f", hdr->FogEnd[i]);

						float colors[3] = {hdr->FogRed[i] / 255.f, hdr->FogGreen[i] / 255.f, hdr->FogBlue[i] / 255.f };
						ImGui::ColorEdit3("Fog Color", colors);

						TableRow("Rain Chance", "%d%%", hdr->RainChance[i]);
						TableRow("Rain Duration", "%d", hdr->RainDuration[i]);
						TableRow("Snow Chance", "%d%%", hdr->SnowChance[i]);
						TableRow("Snow Duration", "%d", hdr->SnowDuration[i]);

						ImGui::TreePop();
					}
				}

				TableRow("Precipitation Type", "%d", (int)hdr->PrecipitationType);
				TableRow("Bloom Intensity", "%f", hdr->BloomIntensity);
				TableRow("Zone Gravity", "%f", hdr->ZoneGravity);
				TableRow("Lava Damage", "%d", hdr->LavaDamage);
				TableRow("Lava Damage Min", "%d", hdr->MinLavaDamage);
				TableRow("Time String ID", "%d", hdr->TimeStringID);
				TableRow("Sky Lock", "%d", hdr->SkyLock);
				TableRow("Sky Lock Override", "%d", hdr->SkyLockOverride);
				TableRow("Safe Location", "(%.2f, %.2f, %.2f)", hdr->SafeYLoc, hdr->SafeXLoc, hdr->SafeZLoc);
				TableRow("Safe Heading", "%.2f", hdr->SafeHeading);
				TableRow("Floor/Ceiling", "%.2f, %.2f", hdr->Floor, hdr->Ceiling);
				TableRow("Min/Max Clip", "%.2f, %.2f", hdr->MinClip, hdr->MaxClip);
				TableRow("Fallthrough World Teleport ID", "%d", hdr->FallThroughWorldTeleportID);
				TableRow("Fast Regen HP", "%d", hdr->FastRegenHP);
				TableRow("Fast Regen Mana", "%d", hdr->FastRegenMana);
				TableRow("Fast Regen Endurance", "%d", hdr->FastRegenEndurance);

				TableRow("New Engine Zone", "%d", (int)hdr->NewEngineZone);
				TableRow("Sky Enabled", "%d", (int)hdr->SkyEnabled);
				TableRow("Fog On/Off", "%d", (int)hdr->FogOnOff);
				TableRow("Climate Type", "%d", (int)hdr->ClimateType);
				TableRow("No Player Light", "%d", (int)hdr->bNoPlayerLight);
				TableRow("No Attack", "%d", (int)hdr->bNoAttack);
				TableRow("PVP Enabled", "%d", (int)hdr->bAllowPVP);
				TableRow("No Encumber", "%d", (int)hdr->bNoEncumber);
				TableRow("No Levitate", "%d", (int)hdr->bNoLevitate);
				TableRow("No Buff Expiration", "%d", (int)hdr->bNoBuffExpiration);
				TableRow("No Manastone", "%d", (int)hdr->bDisallowManaStone);
				TableRow("No Bind", "%d", (int)hdr->bNoBind);
				TableRow("No Call of the Hero", "%d", (int)hdr->bNoCallOfTheHero);
				TableRow("No Fear", "%d", (int)hdr->bNoFear);

#undef TableRow
				ImGui::TreePop();
			}


			ImGui::EndTable();
		}
	}
};
static ZoneInspector* s_zoneInspector = nullptr;

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
	void Draw() override
	{
		int deleteRow = -1;
		for (int i = 0; i < (int)m_expressions.size(); ++i)
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
			ParseMacroParameter(szTemp);

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

#pragma region GameFace Inspector
#if HAS_GAMEFACE_UI

class GameFaceInspector : public ImGuiWindowBase
{
public:
	GameFaceInspector() : ImGuiWindowBase("GameFace Inspector")
	{
		SetDefaultSize(ImVec2(600, 400));
	}

	~GameFaceInspector()
	{
	}

	bool IsEnabled() const override
	{
		return GetPcProfile() != nullptr && GetGameState() == GAMESTATE_INGAME;
	}

	void Draw() override
	{
		auto gf = pGFViewListener.get();

		if (!gf)
		{
			ImGui::Text("GameFace is not running");
			return;
		}

		if (ImGui::BeginTable("##GameFaceUI", 2, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_ScrollY))
		{
			ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_WidthFixed);
			ImGui::TableSetupColumn("Data", ImGuiTableColumnFlags_WidthStretch);
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableHeadersRow();

			ImGui::TableNextRow();
			ImGui::TableNextColumn();

#define TableRow(label, format, ...) \
	ImGui::TableNextRow(); ImGui::TableNextColumn(); ImGui::Text(label); \
	ImGui::TableNextColumn(); ImGui::Text(format, __VA_ARGS__);

			if (ImGui::TreeNode("object1"))
			{
				auto& object1 = gf->object1;

				TableRow("unordered_map", "%d Items", object1.unordered_map_00.size());

				ImGui::TableNextRow(); ImGui::TableNextColumn();
				if (ImGui::TreeNode("Items##map00"))
				{
					for (auto& [key, value] : object1.unordered_map_00)
					{
						ImGui::TableNextRow();

						ImGui::TableNextColumn(); ImGui::Text("%s", key.c_str());
						ImGui::TableNextColumn(); ImGui::Text("%p", value);

					}
					ImGui::TreePop();
				}

				TableRow("pointer_40", "%p", object1.pointer_40);
				TableRow("pointer_48", "%p", object1.pointer_48);
				TableRow("pointer_50", "%p", object1.pointer_50);

				ImGui::TreePop();
			}

			TableRow("map_1e0", "%d Items", gf->map_1e0.size());
			ImGui::TableNextRow(); ImGui::TableNextColumn();
			if (ImGui::TreeNode("Items##map1e0"))
			{
				for (auto& [key, value] : gf->map_1e0)
				{
					ImGui::TableNextRow();

					ImGui::TableNextColumn(); ImGui::Text("%p", key);
					ImGui::TableNextColumn(); ImGui::Text("%p", value);

				}
				ImGui::TreePop();
			}

			GF::ViewListener_Object3* objects[3] = {
				&gf->object3,
				&gf->object4,
				&gf->object5
			};

			TableRow("u64_220[0]", "%p", gf->u64_220[0]);
			TableRow("u64_220[1]", "%p", gf->u64_220[1]);
			TableRow("u32_238[0]", "%d", gf->u32_238[0]);
			TableRow("u32_238[1]", "%d", gf->u32_238[1]);

			int i = 3;

			for (auto object : objects)
			{
				char label[26];
				sprintf_s(label, "object%d", i++);

				ImGui::TableNextRow(); ImGui::TableNextColumn();
				if (ImGui::TreeNode(label))
				{
					TableRow("string_00", "%s", object->string_00.c_str());
					TableRow("map_20", "%d Items", object->map_20.size());

					ImGui::TableNextRow(); ImGui::TableNextColumn();
					ImGui::PushID(i);
					if (ImGui::TreeNode("Items##map_20"))
					{
						for (auto& [key, value] : object->map_20)
						{
							ImGui::TableNextRow(); ImGui::TableNextColumn();
							if (ImGui::TreeNode(key.c_str()))
							{
								TableRow("fileName", "%s", value.fileName.c_str());
								TableRow("size", "%d, %d", value.width, value.height);

								if (value.string_ptr_28)
								{
									TableRow("string_ptr_28", "%s", value.string_ptr_28->c_str());
								}
								else
								{
									TableRow("string_ptr_28", "NULL");
								}

								TableRow("data[0]", "%p", value.data[0]);
								TableRow("data[1]", "%p", value.data[1]);

								ImGui::TreePop();
							}
						}
						ImGui::TreePop();
					}
					ImGui::PopID();

					TableRow("map_60", "%d Items", object->map_60.size());
					ImGui::TableNextRow(); ImGui::TableNextColumn();
					if (ImGui::TreeNode("Items##map_60"))
					{
						for (auto& [key, value] : object->map_60)
						{
							ImGui::TableNextRow(); ImGui::TableNextColumn();
							if (ImGui::TreeNode(key.c_str()))
							{
								TableRow("pieceName", "%s", value.pieceName.c_str());
								TableRow("data[0]", "%p", value.data[0]);
								TableRow("data[1]", "%p", value.data[1]);
								TableRow("data[2]", "%p", value.data[2]);
								TableRow("data[3]", "%p", value.data[3]);
								TableRow("data[4]", "%p", value.data[4]);

								ImGui::TreePop();
							}
						}
						ImGui::TreePop();
					}

					ImGui::TreePop();
				}
			}

			TableRow("string_420", "%s", gf->string_420.c_str());
			TableRow("bool_440", "%d", (int)gf->bool_440);
			TableRow("string_448", "%s", gf->string_448.c_str());
			TableRow("bool_468", "%d", (int)gf->bool_468);
			TableRow("u32_46c", "%d", (int)gf->u32_46c);

			for (int i = 0; i < 5; ++i)
			{
				TableRow("u64_470", "[%d] %p", i, gf->u64_470[i]);
			}

#undef TableRow

			ImGui::EndTable();
		}
	}
};
static GameFaceInspector* s_gameFaceInspector = nullptr;

#endif
#pragma endregion

//============================================================================
//============================================================================

struct ConsoleMenuEntry
{
	ImGuiWindowBase* window;
	std::string command;
	std::string menuName;
	std::string itemName;
};
static std::vector<ConsoleMenuEntry> s_inspectorMenus;
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
			if (entry.window != nullptr)
			{
				if (ImGui::MenuItem(entry.itemName.c_str(), nullptr, entry.window->IsOpen()))
					entry.window->Toggle();
			}
			else
			{
				if (ImGui::MenuItem(entry.itemName.c_str(), nullptr, false))
					DoCommand(entry.command.c_str(), false);
			}
		}
	}

	if (lastMenu && isMenuOpen)
	{
		ImGui::EndMenu();
	}
}

void DeveloperTools_RegisterMenuItem(ImGuiWindowBase* window, const char* itemName, const char* menuName)
{
	s_inspectorMenus.push_back(ConsoleMenuEntry{ window, "", menuName ? menuName : "Tools", itemName });

	s_inspectorMenusDirty = true;
}

void DeveloperTools_RegisterMenuItem(const char* command, const char* itemName, const char* menuName)
{
	s_inspectorMenus.push_back(ConsoleMenuEntry{ nullptr, command, menuName ? menuName : "Tools", itemName });

	s_inspectorMenusDirty = true;
}

void DeveloperTools_UnregisterMenuItem(ImGuiWindowBase* window)
{
	s_inspectorMenus.erase(
		std::remove_if(std::begin(s_inspectorMenus), std::end(s_inspectorMenus),
			[&](const auto& p) { return p.window == window; }),
		std::end(s_inspectorMenus));
}

void DeveloperTools_UnregisterMenuItem(const char* itemName)
{
	s_inspectorMenus.erase(
		std::remove_if(std::begin(s_inspectorMenus), std::end(s_inspectorMenus),
			[&](const auto& p) { return p.itemName == itemName; }),
		std::end(s_inspectorMenus));
}

//============================================================================

void DeveloperTools_WindowInspector_Initialize();
void DeveloperTools_WindowInspector_Shutdown();
void DeveloperTools_WindowInspector_SetGameState(int gameState);

static void DeveloperTools_Initialize()
{
	s_benchmarksInspector = new BenchmarksInspector();
	DeveloperTools_RegisterMenuItem(s_benchmarksInspector, "Benchmarks", s_menuNameInspectors);

	s_achievementsInspector = new AchievementsInspector();
	DeveloperTools_RegisterMenuItem(s_achievementsInspector, "Achievements", s_menuNameInspectors);

	s_altAbilityInspector = new AltAbilityInspector();
	DeveloperTools_RegisterMenuItem(s_altAbilityInspector, "Alt Abilities", s_menuNameInspectors);

	s_characterDataInspector = new CharacterDataInspector();
	DeveloperTools_RegisterMenuItem(s_characterDataInspector, "Character Data", s_menuNameInspectors);

	s_engineInspector = new EngineInspector();
	DeveloperTools_RegisterMenuItem(s_engineInspector, "Engine Inspector", s_menuNameInspectors);

	s_everquestDataInspector = new EverQuestDataInspector();
	DeveloperTools_RegisterMenuItem(s_everquestDataInspector, "EverQuest Data", s_menuNameInspectors);

	s_realEstateInspector = new RealEstateInspector();
	DeveloperTools_RegisterMenuItem(s_realEstateInspector, "Real Estate", s_menuNameInspectors);

	s_spellsInspector = new SpellsInspector();
	DeveloperTools_RegisterMenuItem(s_spellsInspector, "Spells & Buffs", s_menuNameInspectors);

	s_switchInspector = new SwitchInspector();
	DeveloperTools_RegisterMenuItem(s_switchInspector, "Switches", s_menuNameInspectors);

	s_zoneInspector = new ZoneInspector();
	DeveloperTools_RegisterMenuItem(s_zoneInspector, "Zone", s_menuNameInspectors);

	s_stringInspector = new StringInspector();
	DeveloperTools_RegisterMenuItem(s_stringInspector, "CXStr Metrics", s_menuNameInspectors);

	s_macroEvaluator = new MacroExpressionEvaluator();
	DeveloperTools_RegisterMenuItem(s_macroEvaluator, "Macro Expression Evaluator", s_menuNameTools);

	DeveloperTools_RegisterMenuItem("/squelch /lua run mq/eval", "Lua Expression Evaluator", s_menuNameTools);

#if HAS_GAMEFACE_UI
	s_gameFaceInspector = new GameFaceInspector();
	DeveloperTools_RegisterMenuItem(s_gameFaceInspector, "GameFace UI Inspector", s_menuNameInspectors);
#endif

	DeveloperTools_WindowInspector_Initialize();
}

static void DeveloperTools_Shutdown()
{
	DeveloperTools_UnregisterMenuItem(s_benchmarksInspector);
	delete s_benchmarksInspector; s_benchmarksInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_achievementsInspector);
	delete s_achievementsInspector; s_achievementsInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_altAbilityInspector);
	delete s_altAbilityInspector; s_altAbilityInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_characterDataInspector);
	delete s_characterDataInspector; s_characterDataInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_engineInspector);
	delete s_engineInspector; s_engineInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_everquestDataInspector);
	delete s_everquestDataInspector; s_everquestDataInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_realEstateInspector);
	delete s_realEstateInspector; s_realEstateInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_spellsInspector);
	delete s_spellsInspector; s_spellsInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_stringInspector);
	delete s_stringInspector; s_stringInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_switchInspector);
	delete s_switchInspector; s_switchInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_zoneInspector);
	delete s_zoneInspector; s_zoneInspector = nullptr;

	DeveloperTools_UnregisterMenuItem(s_macroEvaluator);
	delete s_macroEvaluator; s_macroEvaluator = nullptr;

	DeveloperTools_UnregisterMenuItem("Lua Expression Evaluator");

#if HAS_GAMEFACE_UI
	DeveloperTools_UnregisterMenuItem(s_gameFaceInspector);
	delete s_gameFaceInspector; s_gameFaceInspector = nullptr;
#endif

	DeveloperTools_WindowInspector_Shutdown();
}

static void DeveloperTools_SetGameState(int gameState)
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
