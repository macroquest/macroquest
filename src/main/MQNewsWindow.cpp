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

#include "ModuleSystem.h"
#include "MQ2Main.h"

using namespace eqlib;

namespace mq {


class CMQNewsWnd final : public CCustomWnd
{
public:
	CMQNewsWnd() : CCustomWnd("ChatWindow")
	{
		AddStyle(CWS_TITLE | CWS_MINIMIZE);
		RemoveStyle(CWS_TRANSPARENT | CWS_CLOSE);
		SetBGColor(0xFF000000);
		SetLocation({ 230,620,850,920 });
		SetWindowText("MacroQuest Recent Changes");
		SetZLayer(1);

		m_outputBox = (CStmlWnd*)GetChildItem("CW_ChatOutput");
		m_outputBox->SetParentWindow(this);

		// Disable the input box since it doesn't handle anything anyway.
		m_inputBox = (CEditWnd*)GetChildItem("CW_ChatInput");
		m_inputBox->SetParentWindow(this);
		m_inputBox->Enabled = false;
	}

	virtual ~CMQNewsWnd() override
	{
	}

	virtual int WndNotification(CXWnd* pWnd, unsigned int Message, void* unknown) override
	{
		if (pWnd == nullptr)
		{
			if (Message == XWM_CLOSE)
			{
				this->SetVisible(true);
				return 1;
			}
		}

		return CCustomWnd::WndNotification(pWnd, Message, unknown);
	};

	void AddNewsLine(const char* Line, int inColor)
	{
		COLORREF color = pChatManager->GetRGBAFromIndex(inColor);

		char szProcessed[MAX_STRING] = { 0 };
		MQToSTML(Line, szProcessed, MAX_STRING, color);

		strcat_s(szProcessed, "<br>");
		CXStr NewText(szProcessed);
		ConvertItemTags(NewText, false);

		m_outputBox->AppendSTML(NewText);
	}

private:
	CStmlWnd* m_outputBox;
	CEditWnd* m_inputBox;
};


class RecentChangesModule : public MQModule
{
public:
	RecentChangesModule() : MQModule("RecentChanges",
		static_cast<int>(ModulePriority::Default), ModuleFlags::CanUnload)
	{
	}

	virtual void Initialize() override
	{
		m_createNewsWindow = GetPrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", m_createNewsWindow, mq::internal_paths::MQini);

		if (gbWriteAllConfig)
		{
			WritePrivateProfileBool("MacroQuest", "CreateMQ2NewsWindow", m_createNewsWindow, mq::internal_paths::MQini);
		}
	}

	virtual void Shutdown() override
	{
	}

	virtual void OnCleanUI() override
	{
		DeleteNewsWindow();
	}

	virtual void OnReloadUI(const eqlib::ReloadUIParams& params) override
	{
	}

	virtual void OnProcessFrame() override
	{
		if (gGameState == GAMESTATE_CHARSELECT && !m_shownNews)
		{
			m_shownNews = true;

			if (m_createNewsWindow)
			{
				CreateNewsWindow();
			}
		}
	}

private:
	void CreateNewsWindow()
	{
		// NOTE: This change log search logic is duplicated in the launcher menu item.
		// This is one of the few places we want to hardcode the path since if the user redirects their resources we would not have distributed that file and they would always have old news.
		const std::filesystem::path pathMQRootChangeLog = std::filesystem::path(internal_paths::MQRoot) / "resources" / "CHANGELOG.md";
		const std::filesystem::path pathResourceChangeLog = std::filesystem::path(internal_paths::Resources) / "CHANGELOG.md";
		// Default to the one in the resource path.
		std::filesystem::path pathChangeLog = pathResourceChangeLog;

		std::error_code ec;
		// If the paths are different, and the Resource Change Log doesn't exist or is older than the Root\Resource changelog
		if (pathMQRootChangeLog != pathResourceChangeLog
			&& (!exists(pathResourceChangeLog, ec)
				|| last_write_time(pathMQRootChangeLog, ec) > last_write_time(pathResourceChangeLog, ec)))
		{
			pathChangeLog = pathMQRootChangeLog;
		}
		// END Duplicate logic

		FILE* file = _fsopen(pathChangeLog.string().c_str(), "rb", _SH_DENYNO);
		if (!file)
		{
			DeleteNewsWindow(); // shouldn't actually exist
			return;
		}

		if (!m_newsWindow)
		{
			m_newsWindow = new CMQNewsWnd();
		}

		m_newsWindow->AddNewsLine("Recent changes...", CONCOLOR_RED);

		char szLine[MAX_STRING] = { 0 };
		int nLines = 0;

		while (fgets(szLine, MAX_STRING, file))
		{
			char* Next_Token1 = nullptr;

			if (char* Cmd = strtok_s(szLine, "\r\n", &Next_Token1))
			{
				// TODO:  Move this to a method that isn't going to hit false positives.  Change the colors to be nicer on the eyes.
				if (GetIntFromString(Cmd, 0) != 0
					|| ci_starts_with(Cmd, "Jan")
					|| ci_starts_with(Cmd, "Feb")
					|| ci_starts_with(Cmd, "Mar")
					|| ci_starts_with(Cmd, "Apr")
					|| ci_starts_with(Cmd, "May")
					|| ci_starts_with(Cmd, "Jun")
					|| ci_starts_with(Cmd, "Jul")
					|| ci_starts_with(Cmd, "Aug")
					|| ci_starts_with(Cmd, "Sep")
					|| ci_starts_with(Cmd, "Oct")
					|| ci_starts_with(Cmd, "Nov")
					|| ci_starts_with(Cmd, "Dec"))
					m_newsWindow->AddNewsLine(Cmd, CONCOLOR_YELLOW);
				else
					m_newsWindow->AddNewsLine(Cmd, CONCOLOR_GREEN);
			}
			else
			{
				m_newsWindow->AddNewsLine("", CONCOLOR_GREEN);
			}

			nLines++;

			if (nLines > 200)
			{
				m_newsWindow->AddNewsLine("...read CHANGELOG.md for more.", CONCOLOR_RED);
				break;
			}
		}

		fclose(file);
	}

	void DeleteNewsWindow()
	{
		delete m_newsWindow;
		m_newsWindow = nullptr;
	}

	CMQNewsWnd* m_newsWindow = nullptr;
	bool m_shownNews = false;
	bool m_createNewsWindow = true;
};

DECLARE_MODULE_FACTORY(RecentChangesModule)

} // namespace mq
