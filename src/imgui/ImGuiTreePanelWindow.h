/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#pragma once

#include "mq/base/String.h"

#include "imgui/ImGuiUtils.h"
#include "imgui/imgui.h"

#include <memory>
#include <string>
#include <vector>

namespace mq {
namespace imgui {

class ImGuiTreePanelWindow
{
	ImVec2 m_defaultSize;

public:
	ImGuiTreePanelWindow(const char* title, const ImVec2& size = ImVec2(520, 600))
		: m_title(title)
		, m_defaultSize(size)
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

		bool selectRequested = false;
	};

	void Clear()
	{
		m_treeRoot.reset();
		m_panels.clear();
		m_selectedPanel = nullptr;
	}

	void Draw(bool* pOpen)
	{
		ImGui::SetNextWindowSize(m_defaultSize, ImGuiCond_FirstUseEver);
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
			ImGui::BeginChild("TreeListView", ImVec2(m_leftPaneSize, ImGui::GetContentRegionAvail().y - 1), ImGuiChildFlags_Borders);
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
			ImGui::BeginChild("ContentView", ImVec2(rightPaneContentSize.x, rightPaneContentSize.y - 1), ImGuiChildFlags_Borders);

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

	void FocusPanel(std::string_view id)
	{
		for (auto& panel : m_panels)
		{
			if (mq::ci_equals(panel->name, id))
			{
				panel->selectRequested = true;
				break;
			}
		}
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
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanFullWidth;
		bool isLeaf = node->children.empty();

		if (node->def != nullptr && (m_selectedPanel == nullptr || node->def->selectRequested))
		{
			m_selectedPanel = node->def;
			node->def->selectRequested = false;
		}

		if (isLeaf)
			flags |= ImGuiTreeNodeFlags_Leaf;
		if (node->def == m_selectedPanel)
			flags |= ImGuiTreeNodeFlags_Selected;

		// Check if we need to force open a node due to a child.
		for (const auto& child : node->children)
		{
			if (child->def && child->def->selectRequested)
			{
				ImGui::SetNextItemOpen(true);
				break;
			}
		}

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

