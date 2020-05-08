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

#pragma once

#include "ImGuiUtils.h"

#include <imgui.h>

#include <memory>
#include <string>
#include <vector>

namespace mq {
namespace imgui {

class ImGuiTreePanelWindow
{
public:
	ImGuiTreePanelWindow(const char* title)
		: m_title(title)
	{
	}

	~ImGuiTreePanelWindow()
	{
		Clear();
	}

	struct PanelDef
	{
		std::string name;

		using Function = void(*)();
		Function func = nullptr;
	};

	void Clear()
	{
		m_treeRoot.reset();
		m_panels.clear();
		m_selectedPanel = nullptr;
	}

	void Draw(bool* pOpen)
	{
		ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
		if (!ImGui::Begin(m_title.c_str(), pOpen))
		{
			ImGui::End();
			return;
		}

		if (m_dirtyTree)
		{
			m_dirtyTree = false;
			RegenerateTree();
		}

		ImVec2 availSize = ImGui::GetContentRegionAvail();
		if (m_rightPaneSize == 0.0f)
			m_rightPaneSize = availSize.x - m_leftPaneSize - 1;

		DrawSplitter(false, 9.0f, &m_leftPaneSize, &m_rightPaneSize, 50, 250);

		// Left Pane
		{
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
			ImGui::BeginChild("TreeListView", ImVec2(m_leftPaneSize, ImGui::GetContentRegionAvail().y - 1), true);
			ImGui::PopStyleVar();

			if (m_treeRoot)
			{
				for (const auto& node : m_treeRoot->children)
				{
					DrawTreeNode(node.get());
				}
			}


			ImGui::EndChild();
		}

		ImGui::SameLine();

		// Right Pane
		{
			ImVec2 rightPaneContentSize = ImGui::GetContentRegionAvail();
			ImGui::BeginChild("ContentView", ImVec2(rightPaneContentSize.x, rightPaneContentSize.y - 1), true);

			if (!m_selectedPanel)
			{
				ImGui::Text("Select a section on the left.");
			}
			else
			{
				if (m_selectedPanel->func)
				{
					m_selectedPanel->func();
				}
			}

			ImGui::EndChild();
		}

		ImGui::End();
	}

	void AddPanel(std::string_view id, PanelDef::Function func)
	{
		auto panelDef = std::make_unique<PanelDef>();
		panelDef->func = func;
		panelDef->name = id;

		m_panels.push_back(std::move(panelDef));
		m_dirtyTree = true;
	}

	void RemovePanel(std::string_view id)
	{
		auto iter = std::find_if(std::begin(m_panels), std::end(m_panels),
			[&id](const auto& panelDef) { return panelDef->name == id; });
		if (iter == std::end(m_panels))
			return;

		PanelDef* panel = iter->get();
		if (panel == m_selectedPanel)
			m_selectedPanel = nullptr;
		m_panels.erase(iter);
		m_dirtyTree = true;
	}

private:
	void RegenerateTree()
	{
		m_treeRoot.reset();

		m_treeRoot = std::make_unique<PanelTreeNode>();
		m_treeRoot->displayName = "";
		m_treeRoot->def = nullptr;

		for (const auto& def : m_panels)
		{
			std::string_view name = def->name;
			PanelTreeNode* node = GetNode(m_treeRoot.get(), name);
			node->def = def.get();
		}

		// Sort everything
		SortNodes(m_treeRoot.get());
	}

	struct PanelTreeNode
	{
		std::string_view displayName;
		PanelDef* def = nullptr;

		std::vector<std::unique_ptr<PanelTreeNode>> children;
	};

	static PanelTreeNode* GetNode(PanelTreeNode* node, std::string_view name)
	{
		std::string_view tail, head;

		// get the name of the next node.
		size_t pos = name.find_first_of("/");
		if (pos == std::string::npos)
		{
			// we're at the leaf.
			head = name;
		}
		else
		{
			head = name.substr(0, pos);
			tail = name.substr(pos + 1);
		}

		// find head.
		auto iter = std::find_if(std::begin(node->children), std::end(node->children),
			[&](const std::unique_ptr<PanelTreeNode>& node) { return ci_equals(node->displayName, head); });

		PanelTreeNode* childNode = nullptr;

		if (iter != std::end(node->children))
		{
			// already exists, return it.
			childNode = iter->get();
		}
		else
		{
			// node doesn't exist. create it.
			auto nodePtr = std::make_unique<PanelTreeNode>();
			nodePtr->def = nullptr;
			nodePtr->displayName = head;
			childNode = nodePtr.get();

			node->children.push_back(std::move(nodePtr));
		}

		if (!tail.empty())
		{
			return GetNode(childNode, tail);
		}

		return childNode;
	}

	void DrawTreeNode(PanelTreeNode* node)
	{
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanFullWidth;
		bool isLeaf = node->children.empty();

		if (m_selectedPanel == nullptr && node->def != nullptr)
			m_selectedPanel = node->def;

		if (isLeaf)
			flags |= ImGuiTreeNodeFlags_Leaf;
		if (node->def == m_selectedPanel)
			flags |= ImGuiTreeNodeFlags_Selected;

		bool nodeOpen = ImGui::TreeNodeEx((void*)node, flags, "%.*s", node->displayName.length(), node->displayName.data());

		if (ImGui::IsItemClicked() && node->def != nullptr)
			m_selectedPanel = node->def;

		if (nodeOpen)
		{
			for (const auto& child : node->children)
			{
				DrawTreeNode(child.get());
			}

			ImGui::TreePop();
		}
	}

	void SortNodes(PanelTreeNode* node)
	{
		// Sort our children
		std::sort(std::begin(node->children), std::end(node->children),
			[](const auto& ptrA, const auto& ptrB) { return ci_less()(ptrA->displayName, ptrB->displayName); });

		for (const auto& ptr : node->children)
		{
			SortNodes(ptr.get());
		}
	}

private:
	std::string m_title;
	float m_leftPaneSize = 150.0f; // initial size of left column
	float m_rightPaneSize = 0.0f;  // size of right column. Initial value calculated from left.
	bool m_dirtyTree = false;
	std::unique_ptr<PanelTreeNode> m_treeRoot;
	std::vector<std::unique_ptr<PanelDef>> m_panels;
	PanelDef* m_selectedPanel = nullptr;
};

}} // namespace mq::imgui

