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

#pragma once

#include "MQ2Main.h"

#include <string_view>

namespace mq {

void DeveloperTools_CloseLoginFrontend();
void DeveloperTools_DrawMenu();

class ImGuiWindowBase;

// Some constants for creating menus.
const char s_menuNameInspectors[] = "Inspectors";
const char s_menuNameTools[] = "Tools";

// Register inspector window
void DeveloperTools_RegisterMenuItem(ImGuiWindowBase* window, const char* itemName, const char* menuName = nullptr);
void DeveloperTools_UnregisterMenuItem(ImGuiWindowBase* window);

// Developer Tools - Window Inspector panel
void DeveloperTools_WindowInspector_Show(CXWnd* pWnd);
void DeveloperTools_WindowInspector_RemoveWindow(CXWnd* pWnd);
void DeveloperTools_WindowInspector_SetSelectedWindow(CXWnd* pWnd);

bool DeveloperTools_WindowInspector_HandleClick(int mouseButton, bool clicked);

//----------------------------------------------------------------------------

struct PersistedBool
{
	PersistedBool(std::string_view section, std::string_view key, bool init = false);

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

	MQLIB_OBJECT void Save();
	MQLIB_OBJECT void Load();
	MQLIB_OBJECT void Update();

private:
	bool m_value;
	const bool m_defaultValue;
	bool m_lastValue;
	bool m_isLoaded;

	std::string m_section;
	std::string m_key;
};

//----------------------------------------------------------------------------

class ImGuiWindowBase
{
public:
	MQLIB_OBJECT ImGuiWindowBase(std::string_view windowId, std::string_view windowTitle = {});
	MQLIB_OBJECT virtual ~ImGuiWindowBase();

	inline bool IsOpen() const { return m_open && IsEnabled(); }
	MQLIB_OBJECT virtual bool IsEnabled() const { return true; }

	MQLIB_OBJECT virtual void Show() { m_open = true; }
	MQLIB_OBJECT virtual void Close() { m_open = false; }

	MQLIB_OBJECT void Toggle() { if (m_open) Close(); else Show(); }
	MQLIB_OBJECT virtual void Update();

	MQLIB_OBJECT ImGuiWindowBase* GetNext() { return m_next; }
	MQLIB_OBJECT void SetDefaultSize(const ImVec2& size) { m_defaultSize = size; }

	MQLIB_OBJECT void SetWindowTitle(std::string_view windowTitle);
	inline const std::string& GetWindowTitle() const { return m_windowTitle; }

protected:
	// Override this to set some properties before the window is drawn. If this returns false
	// the update is aborted.
	MQLIB_OBJECT virtual bool Begin()
	{
		ImGui::SetNextWindowSize(m_defaultSize, ImGuiCond_FirstUseEver);
		return ImGui::Begin(m_windowId.c_str(), m_open.get_ptr());
	}

	// Override to draw the window
	MQLIB_OBJECT virtual void Draw() {}

	//------------------------------------------------------------------------
	std::string m_windowId;
	std::string m_windowTitle;                                 // WindowTitle###WindowId
	PersistedBool m_open;

private:
	ImGuiWindowBase* m_next = nullptr;
	ImGuiWindowBase* m_prev = nullptr;
	ImVec2 m_defaultSize;
};

} // namespace mq

