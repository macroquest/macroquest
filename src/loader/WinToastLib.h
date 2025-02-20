/**
 * MIT License
 *
 * Copyright (C) 2016-2023 WinToast v1.3.0 - Mohammed Boujemaoui <mohabouje@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <Windows.h>
#include <sdkddkver.h>
#include <WinUser.h>
#include <ShObjIdl.h>
#include <wrl/implements.h>
#include <wrl/event.h>
#include <windows.ui.notifications.h>
#include <strsafe.h>
#include <Psapi.h>
#include <ShlObj.h>
#include <roapi.h>
#include <propvarutil.h>
#include <functiondiscoverykeys.h>
#include <iostream>
#include <winstring.h>
#include <string.h>
#include <vector>
#include <map>
#include <memory>

namespace WinToastLib {

class IWinToastHandler
{
public:
	enum WinToastDismissalReason
	{
		UserCanceled = ABI::Windows::UI::Notifications::ToastDismissalReason::ToastDismissalReason_UserCanceled,
		ApplicationHidden = ABI::Windows::UI::Notifications::ToastDismissalReason::ToastDismissalReason_ApplicationHidden,
		TimedOut = ABI::Windows::UI::Notifications::ToastDismissalReason::ToastDismissalReason_TimedOut
	};

	virtual ~IWinToastHandler() = default;
	virtual void toastActivated() = 0;
	virtual void toastActivated(int actionIndex) = 0;
	virtual void toastActivated(const char* response) = 0;
	virtual void toastDismissed(WinToastDismissalReason state) = 0;
	virtual void toastFailed() = 0;
};

class WinToastTemplate
{
public:
	enum class Scenario { Default, Alarm, IncomingCall, Reminder };
	enum Duration { System, Short, Long };
	enum AudioOption { Default, Silent, Loop };
	enum TextField { FirstLine, SecondLine, ThirdLine };

	enum WinToastTemplateType
	{
		ImageAndText01 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastImageAndText01,
		ImageAndText02 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastImageAndText02,
		ImageAndText03 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastImageAndText03,
		ImageAndText04 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastImageAndText04,
		Text01 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastText01,
		Text02 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastText02,
		Text03 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastText03,
		Text04 = ABI::Windows::UI::Notifications::ToastTemplateType::ToastTemplateType_ToastText04
	};

	enum AudioSystemFile
	{
		DefaultSound,
		IM,
		Mail,
		Reminder,
		SMS,
		Alarm,
		Alarm2,
		Alarm3,
		Alarm4,
		Alarm5,
		Alarm6,
		Alarm7,
		Alarm8,
		Alarm9,
		Alarm10,
		Call,
		Call1,
		Call2,
		Call3,
		Call4,
		Call5,
		Call6,
		Call7,
		Call8,
		Call9,
		Call10,
	};

	enum CropHint
	{
		Square,
		Circle,
	};

	WinToastTemplate(WinToastTemplateType type = WinToastTemplateType::ImageAndText02);
	~WinToastTemplate();

	void setFirstLine(const std::wstring& text);
	void setFirstLine(const std::string& text);

	void setSecondLine(const std::wstring& text);
	void setSecondLine(const std::string& text);

	void setThirdLine(const std::wstring& text);
	void setThirdLine(const std::string& text);

	void setTextField(const std::wstring& txt, TextField pos);
	void setTextField(const std::string& txt, TextField pos);

	void setAttributionText(const std::wstring& attributionText);
	void setImagePath(const std::wstring& imgPath, CropHint cropHint = CropHint::Square);
	void setHeroImagePath(const std::wstring& imgPath, bool inlineImage = false);
	void setAudioPath(WinToastTemplate::AudioSystemFile audio);
	void setAudioPath(const std::wstring& audioPath);
	void setAudioOption(WinToastTemplate::AudioOption audioOption);
	void setDuration(Duration duration);
	void setExpiration(int64_t millisecondsFromNow);
	void setScenario(Scenario scenario);

	void addAction(const std::wstring& label);
	void addAction(const std::string& label);

	void addInput();

	std::size_t textFieldsCount() const;
	std::size_t actionsCount() const;
	bool hasImage() const;
	bool hasHeroImage() const;
	std::vector<std::wstring> const& textFields() const;
	const std::wstring& textField(TextField pos) const;
	const std::wstring& actionLabel(std::size_t pos) const;
	const std::wstring& imagePath() const;
	const std::wstring& heroImagePath() const;
	const std::wstring& audioPath() const;
	const std::wstring& attributionText() const;
	const std::wstring& scenario() const;
	int64_t expiration() const;
	WinToastTemplateType type() const;
	WinToastTemplate::AudioOption audioOption() const;
	Duration duration() const;
	bool isToastGeneric() const;
	bool isInlineHeroImage() const;
	bool isCropHintCircle() const;
	bool isInput() const;

private:
	bool m_hasInput = false;

	std::vector<std::wstring> m_textFields;
	std::vector<std::wstring> m_actions;
	std::wstring m_imagePath;
	std::wstring m_heroImagePath;
	bool m_inlineHeroImage = false;
	std::wstring m_audioPath;
	std::wstring m_attributionText;
	std::wstring m_scenario = L"Default";
	int64_t m_expiration = 0;
	AudioOption m_audioOption = WinToastTemplate::AudioOption::Default;
	WinToastTemplateType m_type = WinToastTemplateType::Text01;
	Duration m_duration = Duration::System;
	CropHint m_cropHint = CropHint::Square;
};

class WinToast
{
public:
	enum WinToastError
	{
		NoError = 0,
		NotInitialized,
		SystemNotSupported,
		ShellLinkNotCreated,
		InvalidAppUserModelID,
		InvalidParameters,
		InvalidHandler,
		NotDisplayed,
		UnknownError
	};

	enum ShortcutResult
	{
		SHORTCUT_UNCHANGED = 0,
		SHORTCUT_WAS_CHANGED = 1,
		SHORTCUT_WAS_CREATED = 2,

		SHORTCUT_MISSING_PARAMETERS = -1,
		SHORTCUT_INCOMPATIBLE_OS = -2,
		SHORTCUT_COM_INIT_FAILURE = -3,
		SHORTCUT_CREATE_FAILED = -4
	};

	enum ShortcutPolicy {
		/* Don't check, create, or modify a shortcut. */
		SHORTCUT_POLICY_IGNORE = 0,
		/* Require a shortcut with matching AUMI, don't create or modify an existing one. */
		SHORTCUT_POLICY_REQUIRE_NO_CREATE = 1,
		/* Require a shortcut with matching AUMI, create if missing, modify if not matching. This is the default. */
		SHORTCUT_POLICY_REQUIRE_CREATE = 2,
	};

	WinToast();
	virtual ~WinToast();

	static WinToast* instance();
	static bool isCompatible();
	static bool isSupportingModernFeatures();
	static bool isWin10AnniversaryOrHigher();
	static std::wstring configureAUMI(const std::wstring& companyName, const std::wstring& productName,
		const std::wstring& subProduct = std::wstring(),
		const std::wstring& versionInformation = std::wstring());
	static const std::wstring& strerror(WinToastError error);

	bool initialize(WinToastError* error = nullptr);
	bool isInitialized() const;
	bool hideToast(int64_t id);
	int64_t showToast(WinToastTemplate const& toast, std::shared_ptr<IWinToastHandler> eventHandler, WinToastError* error = nullptr);
	void clear();
	ShortcutResult createShortcut();

	const std::wstring& appName() const;
	const std::wstring& appUserModelId() const;
	void setAppUserModelId(const std::wstring& aumi);
	void setAppName(const std::wstring& appName);
	void setShortcutPolicy(ShortcutPolicy policy);

protected:
	struct NotifyData
	{
		NotifyData() = default;

		NotifyData(const Microsoft::WRL::ComPtr<ABI::Windows::UI::Notifications::IToastNotification>& notify,
			EventRegistrationToken activatedToken,
			EventRegistrationToken dismissedToken,
			EventRegistrationToken failedToken)
			: m_notify(notify)
			, m_activatedToken(activatedToken)
			, m_dismissedToken(dismissedToken)
			, m_failedToken(failedToken)
		{
		}

		~NotifyData()
		{
			RemoveTokens();
		}

		NotifyData(const NotifyData&) = delete;
		NotifyData& operator=(const NotifyData&) = delete;

		void RemoveTokens()
		{
			if (!m_readyForDeletion)
			{
				return;
			}

			if (m_previouslyTokenRemoved)
			{
				return;
			}

			if (!m_notify.Get())
			{
				return;
			}

			m_notify->remove_Activated(m_activatedToken);
			m_notify->remove_Dismissed(m_dismissedToken);
			m_notify->remove_Failed(m_failedToken);
			m_previouslyTokenRemoved = true;
		}

		void markAsReadyForDeletion()
		{
			m_readyForDeletion = true;
		}

		bool isReadyForDeletion() const
		{
			return m_readyForDeletion;
		}

		ABI::Windows::UI::Notifications::IToastNotification* notification()
		{
			return m_notify.Get();
		}

	private:
		Microsoft::WRL::ComPtr<ABI::Windows::UI::Notifications::IToastNotification> m_notify;
		EventRegistrationToken m_activatedToken{};
		EventRegistrationToken m_dismissedToken{};
		EventRegistrationToken m_failedToken{};
		bool m_readyForDeletion = false;
		bool m_previouslyTokenRemoved = false;
	};

	bool m_isInitialized = false;
	bool m_hasCoInitialized = false;
	ShortcutPolicy m_shortcutPolicy = SHORTCUT_POLICY_REQUIRE_CREATE ;
	std::wstring m_appName;
	std::wstring m_aumi;
	std::map<int64_t, NotifyData> m_buffer;

	void markAsReadyForDeletion(int64_t id);
	HRESULT validateShellLinkHelper(bool& wasChanged);
	HRESULT createShellLinkHelper();
	HRESULT setImageFieldHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& path, bool isToastGeneric, bool isCropHintCircle);
	HRESULT setHeroImageHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& path, bool isInlineImage);
	HRESULT setBindToastGenericHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml);
	HRESULT setAudioFieldHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& path, WinToastTemplate::AudioOption option = WinToastTemplate::AudioOption::Default);
	HRESULT setTextFieldHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& text, UINT32 pos);
	HRESULT setAttributionTextFieldHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& text);
	HRESULT addActionHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& action, const std::wstring& arguments);
	HRESULT addDurationHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& duration);
	HRESULT addScenarioHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml, const std::wstring& scenario);
	HRESULT addInputHelper(ABI::Windows::Data::Xml::Dom::IXmlDocument* xml);
	Microsoft::WRL::ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> notifier(bool* succeded) const;
	void setError(WinToastError* error, WinToastError value);
};

} // namespace WinToastLib
