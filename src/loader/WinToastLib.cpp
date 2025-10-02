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

#include "WinToastLib.h"

#include "mq/base/WString.h"
#include "mq/base/String.h"

#include <spdlog/spdlog.h>
#include <memory>
#include <assert.h>
#include <unordered_map>
#include <array>
#include <functional>

#pragma comment(lib, "shlwapi")
#pragma comment(lib, "user32")

#define DEFAULT_SHELL_LINKS_PATH L"\\Microsoft\\Windows\\Start Menu\\Programs\\"
#define DEFAULT_LINK_FORMAT      L".lnk"
#define STATUS_SUCCESS           (0x00000000)

using namespace Microsoft::WRL;
using namespace ABI::Windows::Data::Xml::Dom;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::UI::Notifications;
using namespace Windows::Foundation;

// Quickstart: Handling toast activations from Win32 apps in Windows 10
// https://blogs.msdn.microsoft.com/tiles_and_toasts/2015/10/16/quickstart-handling-toast-activations-from-win32-apps-in-windows-10/

namespace WinToastLib {

namespace DllImporter
{
	// Function load a function from library
	template <typename Function>
	HRESULT loadFunctionFromLibrary(HINSTANCE library, LPCSTR name, Function& func)
	{
		if (!library)
		{
			return E_INVALIDARG;
		}

		func = (Function)::GetProcAddress(library, name);
		return (func != nullptr) ? S_OK : E_FAIL;
	}

	using f_SetCurrentProcessExplicitAppUserModelID = HRESULT(__stdcall*)(PCWSTR AppID);
	using f_PropVariantToString = HRESULT(__stdcall*)(REFPROPVARIANT propvar, PWSTR psz, UINT cch);
	using f_RoGetActivationFactory = HRESULT(__stdcall*)(HSTRING activatableClassId, REFIID iid, void** factory);
	using f_WindowsCreateStringReference = HRESULT(__stdcall*)(PCWSTR sourceString, uint32_t length, HSTRING_HEADER* hstringHeader, HSTRING* string);
	using f_WindowsGetStringRawBuffer = PCWSTR(__stdcall*)(HSTRING string, uint32_t* length);
	using f_WindowsDeleteString = HRESULT(__stdcall*)(HSTRING string);

	static f_SetCurrentProcessExplicitAppUserModelID SetCurrentProcessExplicitAppUserModelID;
	static f_PropVariantToString PropVariantToString;
	static f_RoGetActivationFactory RoGetActivationFactory;
	static f_WindowsCreateStringReference WindowsCreateStringReference;
	static f_WindowsGetStringRawBuffer WindowsGetStringRawBuffer;
	static f_WindowsDeleteString WindowsDeleteString;

	template <typename T>
	FORCEINLINE HRESULT _1_GetActivationFactory(HSTRING activatableClassId, T** factory)
	{
		return RoGetActivationFactory(activatableClassId, IID_INS_ARGS(factory));
	}

	template <typename T>
	FORCEINLINE HRESULT Wrap_GetActivationFactory(HSTRING activatableClassId, Details::ComPtrRef<T> factory) noexcept
	{
		return _1_GetActivationFactory(activatableClassId, factory.ReleaseAndGetAddressOf());
	}

	HRESULT initialize()
	{
		HINSTANCE LibShell32 = LoadLibraryW(L"SHELL32.DLL");

		HRESULT hr = loadFunctionFromLibrary(LibShell32, "SetCurrentProcessExplicitAppUserModelID", SetCurrentProcessExplicitAppUserModelID);
		if (SUCCEEDED(hr))
		{
			HINSTANCE LibPropSys = LoadLibraryW(L"PROPSYS.DLL");

			hr = loadFunctionFromLibrary(LibPropSys, "PropVariantToString", PropVariantToString);
			if (SUCCEEDED(hr))
			{
				HINSTANCE LibComBase = LoadLibraryW(L"COMBASE.DLL");

				const bool succeded =
					SUCCEEDED(loadFunctionFromLibrary(LibComBase, "RoGetActivationFactory", RoGetActivationFactory)) &&
					SUCCEEDED(loadFunctionFromLibrary(LibComBase, "WindowsCreateStringReference", WindowsCreateStringReference)) &&
					SUCCEEDED(loadFunctionFromLibrary(LibComBase, "WindowsGetStringRawBuffer", WindowsGetStringRawBuffer)) &&
					SUCCEEDED(loadFunctionFromLibrary(LibComBase, "WindowsDeleteString", WindowsDeleteString));
				return succeded ? S_OK : E_FAIL;
			}
		}
		return hr;
	}
} // namespace DllImporter

class WinToastStringWrapper
{
public:
	WinToastStringWrapper(PCWSTR stringRef, uint32_t length)
	{
		HRESULT hr = DllImporter::WindowsCreateStringReference(stringRef, length, &m_header, &m_hstring);
		if (FAILED(hr))
		{
			RaiseException(STATUS_INVALID_PARAMETER, EXCEPTION_NONCONTINUABLE, 0, nullptr);
		}
	}

	WinToastStringWrapper(const std::wstring& stringRef)
	{
		HRESULT hr = DllImporter::WindowsCreateStringReference(stringRef.c_str(), static_cast<uint32_t>(stringRef.length()), &m_header, &m_hstring);
		if (FAILED(hr))
		{
			RaiseException(STATUS_INVALID_PARAMETER, EXCEPTION_NONCONTINUABLE, 0, nullptr);
		}
	}

	~WinToastStringWrapper()
	{
		DllImporter::WindowsDeleteString(m_hstring);
	}

	HSTRING Get() const noexcept
	{
		return m_hstring;
	}

private:
	HSTRING m_hstring;
	HSTRING_HEADER m_header;
};

class InternalDateTime : public IReference<DateTime>
{
public:
	static int64_t Now()
	{
		FILETIME now;
		GetSystemTimeAsFileTime(&now);
		return static_cast<int64_t>(now.dwHighDateTime) << 32 | now.dwLowDateTime;
	}

	InternalDateTime(DateTime dateTime) : m_dateTime(dateTime)
	{
	}

	InternalDateTime(int64_t millisecondsFromNow)
	{
		m_dateTime.UniversalTime = Now() + millisecondsFromNow * 10000;
	}

	virtual ~InternalDateTime() = default;

	operator int64_t()
	{
		return m_dateTime.UniversalTime;
	}

	HRESULT STDMETHODCALLTYPE get_Value(DateTime* dateTime) override
	{
		*dateTime = m_dateTime;
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE QueryInterface(const IID& riid, void** ppvObject) override
	{
		if (!ppvObject)
		{
			return E_POINTER;
		}

		if (riid == __uuidof(IUnknown) || riid == __uuidof(IReference))
		{
			*ppvObject = static_cast<IUnknown*>(static_cast<IReference*>(this));
			return S_OK;
		}

		return E_NOINTERFACE;
	}

	ULONG STDMETHODCALLTYPE Release() override
	{
		return 1;
	}

	ULONG STDMETHODCALLTYPE AddRef() override
	{
		return 2;
	}

	HRESULT STDMETHODCALLTYPE GetIids(ULONG*, IID**) override
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE GetRuntimeClassName(HSTRING*) override
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel*) override
	{
		return E_NOTIMPL;
	}

protected:
	DateTime m_dateTime;
};

namespace Util
{
	using NTSTATUS = LONG;
	using PNTSTATUS = LONG*;
	using RtlGetVersionPtr = NTSTATUS(WINAPI*)(PRTL_OSVERSIONINFOW);

	RTL_OSVERSIONINFOW getRealOSVersion()
	{
		if (HMODULE hMod = ::GetModuleHandleW(L"ntdll.dll"))
		{
			RtlGetVersionPtr fxPtr = reinterpret_cast<RtlGetVersionPtr>(::GetProcAddress(hMod, "RtlGetVersion"));
			if (fxPtr != nullptr)
			{
				RTL_OSVERSIONINFOW rovi = { 0 };
				rovi.dwOSVersionInfoSize = sizeof(rovi);
				if (STATUS_SUCCESS == fxPtr(&rovi))
				{
					return rovi;
				}
			}
		}

		RTL_OSVERSIONINFOW rovi = {};
		return rovi;
	}

	HRESULT defaultExecutablePath(WCHAR* path, DWORD nSize = MAX_PATH)
	{
		DWORD written = GetModuleFileNameExW(GetCurrentProcess(), nullptr, path, nSize);
		//SPDLOG_DEBUG("Default executable path: {}", mq::wstring_to_utf8(path));
		return (written > 0) ? S_OK : E_FAIL;
	}

	HRESULT defaultShellLinksDirectory(WCHAR* path, DWORD nSize = MAX_PATH)
	{
		DWORD written = GetEnvironmentVariableW(L"APPDATA", path, nSize);

		HRESULT hr = written > 0 ? S_OK : E_INVALIDARG;
		if (SUCCEEDED(hr))
		{
			errno_t result = wcscat_s(path, nSize, DEFAULT_SHELL_LINKS_PATH);
			hr = (result == 0) ? S_OK : E_INVALIDARG;

			//SPDLOG_DEBUG("Default shell link path: {}", mq::wstring_to_utf8(path));
		}
		return hr;
	}

	HRESULT defaultShellLinkPath(const std::wstring& appname, WCHAR* path, DWORD nSize = MAX_PATH)
	{
		HRESULT hr = defaultShellLinksDirectory(path, nSize);
		if (SUCCEEDED(hr))
		{
			const std::wstring appLink(appname + DEFAULT_LINK_FORMAT);
			errno_t result = wcscat_s(path, nSize, appLink.c_str());
			hr = (result == 0) ? S_OK : E_INVALIDARG;

			//SPDLOG_DEBUG("Default shell link file path: {}", mq::wstring_to_utf8(path));
		}
		return hr;
	}

	std::string AsString(ComPtr<IXmlDocument>& xmlDocument)
	{
		HSTRING xml;
		ComPtr<IXmlNodeSerializer> ser;

		xmlDocument.As<IXmlNodeSerializer>(&ser);
		HRESULT hr = ser->GetXml(&xml);
		if (SUCCEEDED(hr))
		{
			return mq::wstring_to_utf8(DllImporter::WindowsGetStringRawBuffer(xml, nullptr));
		}

		return {};
	}

	std::string AsString(HSTRING hstring)
	{
		return mq::wstring_to_utf8(DllImporter::WindowsGetStringRawBuffer(hstring, nullptr));
	}

	inline HRESULT setNodeStringValue(const std::wstring& string, IXmlNode* node, IXmlDocument* xml)
	{
		ComPtr<IXmlText> textNode;

		HRESULT hr = xml->CreateTextNode(WinToastStringWrapper(string).Get(), &textNode);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> stringNode;
			hr = textNode.As(&stringNode);

			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlNode> appendedChild;
				hr = node->AppendChild(stringNode.Get(), &appendedChild);
			}
		}

		return hr;
	}

	template<typename FunctorT>
	HRESULT setEventHandlers(
		IToastNotification* notification,
		const std::shared_ptr<IWinToastHandler>& eventHandler,
		int64_t expirationTime,
		EventRegistrationToken& activatedToken,
		EventRegistrationToken& dismissedToken,
		EventRegistrationToken& failedToken,
		FunctorT markAsReadyForDeletionFunc)
	{
		HRESULT hr = notification->add_Activated(
			Callback<Implements<RuntimeClassFlags<ClassicCom>, ITypedEventHandler<ToastNotification*, IInspectable*>>>(
				[eventHandler, markAsReadyForDeletionFunc](IToastNotification* notify, IInspectable* inspectable)
				{
					ComPtr<IToastActivatedEventArgs> activatedEventArgs;
					HRESULT hr = inspectable->QueryInterface(activatedEventArgs.GetAddressOf());
					if (SUCCEEDED(hr))
					{
						HSTRING argumentsHandle;
						hr = activatedEventArgs->get_Arguments(&argumentsHandle);
						if (SUCCEEDED(hr))
						{
							std::string arguments = Util::AsString(argumentsHandle);
							if (arguments == "action=reply")
							{
								ComPtr<IToastActivatedEventArgs2> inputBoxActivatedEventArgs;
								HRESULT hr2 = inspectable->QueryInterface(inputBoxActivatedEventArgs.GetAddressOf());

								if (SUCCEEDED(hr2))
								{
									ComPtr<Collections::IPropertySet> replyHandle;
									inputBoxActivatedEventArgs->get_UserInput(&replyHandle);

									ComPtr<__FIMap_2_HSTRING_IInspectable> replyMap;
									hr = replyHandle.As(&replyMap);

									if (SUCCEEDED(hr))
									{
										IInspectable* propertySet;
										hr = replyMap.Get()->Lookup(WinToastStringWrapper(L"textBox").Get(), &propertySet);
										if (SUCCEEDED(hr))
										{
											ComPtr<IPropertyValue> propertyValue;
											hr = propertySet->QueryInterface(IID_PPV_ARGS(&propertyValue));

											if (SUCCEEDED(hr))
											{
												// Successfully queried IPropertyValue, now extract the value
												HSTRING userInput;

												hr = propertyValue->GetString(&userInput);
												if (SUCCEEDED(hr))
												{
													std::string str = AsString(userInput);
													eventHandler->toastActivated(str.c_str());
													return S_OK;
												}
											}
										}
									}
								}
							}

							if (!arguments.empty())
							{
								eventHandler->toastActivated(mq::GetIntFromString(arguments, 0));
								DllImporter::WindowsDeleteString(argumentsHandle);
								markAsReadyForDeletionFunc();
								return S_OK;
							}

							DllImporter::WindowsDeleteString(argumentsHandle);
						}
					}

					eventHandler->toastActivated();
					markAsReadyForDeletionFunc();
					return S_OK;
				})
			.Get(),
			&activatedToken);

		if (SUCCEEDED(hr))
		{
			hr = notification->add_Dismissed(
				Callback<Implements<RuntimeClassFlags<ClassicCom>, ITypedEventHandler<ToastNotification*, ToastDismissedEventArgs*>>>(
					[eventHandler, expirationTime, markAsReadyForDeletionFunc](IToastNotification* notify, IToastDismissedEventArgs* e)
					{
						ToastDismissalReason reason;
						if (SUCCEEDED(e->get_Reason(&reason)))
						{
							if (reason == ToastDismissalReason_UserCanceled && expirationTime
								&& InternalDateTime::Now() >= expirationTime)
							{
								reason = ToastDismissalReason_TimedOut;
							}

							eventHandler->toastDismissed(static_cast<IWinToastHandler::WinToastDismissalReason>(reason));
						}

						markAsReadyForDeletionFunc();
						return S_OK;
					})
				.Get(),
				&dismissedToken);

			if (SUCCEEDED(hr))
			{
				hr = notification->add_Failed(
					Callback<Implements<RuntimeClassFlags<ClassicCom>, ITypedEventHandler<ToastNotification*, ToastFailedEventArgs*>>>(
						[eventHandler, markAsReadyForDeletionFunc](IToastNotification* notify, IToastFailedEventArgs* e)
						{
							eventHandler->toastFailed();
							markAsReadyForDeletionFunc();
							return S_OK;
						})
					.Get(),
					&failedToken);
			}
		}
		return hr;
	}

	HRESULT addAttribute(IXmlDocument* xml, const std::wstring& name, IXmlNamedNodeMap* attributeMap)
	{
		ComPtr<ABI::Windows::Data::Xml::Dom::IXmlAttribute> srcAttribute;

		HRESULT hr = xml->CreateAttribute(WinToastStringWrapper(name).Get(), &srcAttribute);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> node;

			hr = srcAttribute.As(&node);
			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlNode> pNode;
				hr = attributeMap->SetNamedItem(node.Get(), &pNode);
			}
		}

		return hr;
	}

	HRESULT createElement(IXmlDocument* xml, const std::wstring& root_node, const std::wstring& element_name, const std::vector<std::wstring>& attribute_names)
	{
		ComPtr<IXmlNodeList> rootList;

		HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(root_node).Get(), &rootList);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> root;

			hr = rootList->Item(0, &root);
			if (SUCCEEDED(hr))
			{
				ComPtr<ABI::Windows::Data::Xml::Dom::IXmlElement> audioElement;

				hr = xml->CreateElement(WinToastStringWrapper(element_name).Get(), &audioElement);
				if (SUCCEEDED(hr))
				{
					ComPtr<IXmlNode> audioNodeTmp;

					hr = audioElement.As(&audioNodeTmp);
					if (SUCCEEDED(hr))
					{
						ComPtr<IXmlNode> audioNode;

						hr = root->AppendChild(audioNodeTmp.Get(), &audioNode);
						if (SUCCEEDED(hr))
						{
							ComPtr<IXmlNamedNodeMap> attributes;

							hr = audioNode->get_Attributes(&attributes);
							if (SUCCEEDED(hr))
							{
								for (const auto& it : attribute_names)
								{
									hr = addAttribute(xml, it, attributes.Get());
								}
							}
						}
					}
				}
			
			}
		}
		return hr;
	}

} // namespace Util

WinToast* WinToast::instance()
{
	thread_local WinToast instance;
	return &instance;
}

WinToast::WinToast()
{
	if (!isCompatible())
	{
		SPDLOG_WARN("Warning: Your system is not compatible with notifications");
	}
}

WinToast::~WinToast()
{
	clear();

	if (m_hasCoInitialized)
	{
		CoUninitialize();
	}
}

void WinToast::setAppName(const std::wstring& appName)
{
	m_appName = appName;
}

void WinToast::setAppUserModelId(const std::wstring& aumi)
{
	m_aumi = aumi;
	//SPDLOG_DEBUG("Default App User Model Id: {}", mq::wstring_to_utf8(m_aumi));
}

void WinToast::setShortcutPolicy(ShortcutPolicy shortcutPolicy)
{
	m_shortcutPolicy = shortcutPolicy;
}

bool WinToast::isCompatible()
{
	DllImporter::initialize();

	return !(DllImporter::SetCurrentProcessExplicitAppUserModelID == nullptr ||
		DllImporter::PropVariantToString == nullptr ||
		DllImporter::RoGetActivationFactory == nullptr ||
		DllImporter::WindowsCreateStringReference == nullptr ||
		DllImporter::WindowsDeleteString == nullptr);
}

bool WinToastLib::WinToast::isSupportingModernFeatures()
{
	constexpr int MinimumSupportedVersion = 6;

	return Util::getRealOSVersion().dwMajorVersion > MinimumSupportedVersion;
}

bool WinToastLib::WinToast::isWin10AnniversaryOrHigher()
{
	return Util::getRealOSVersion().dwBuildNumber >= 14393;
}

std::wstring WinToast::configureAUMI(
	const std::wstring& companyName,
	const std::wstring& productName,
	const std::wstring& subProduct,
	const std::wstring& versionInformation)
{
	std::wstring aumi = companyName;
	aumi += L"." + productName;

	if (!subProduct.empty())
	{
		aumi += L"." + subProduct;
		if (!versionInformation.empty())
		{
			aumi += L"." + versionInformation;
		}
	}

	if (aumi.length() >= SCHAR_MAX)
	{
		SPDLOG_ERROR("Error: max size allowed for AUMI: 128 characters.");
	}

	return aumi;
}

const std::wstring& WinToast::strerror(WinToastError error)
{
	static const std::unordered_map<WinToastError, std::wstring> Labels =
	{
		{ WinToastError::NoError,               L"No error. The process was executed correctly"                                   },
		{ WinToastError::NotInitialized,        L"The library has not been initialized"                                           },
		{ WinToastError::SystemNotSupported,    L"The OS does not support WinToast"                                               },
		{ WinToastError::ShellLinkNotCreated,   L"The library was not able to create a Shell Link for the app"                    },
		{ WinToastError::InvalidAppUserModelID, L"The AUMI is not a valid one"                                                    },
		{ WinToastError::InvalidParameters,     L"Invalid parameters, please double-check the AUMI or App Name"                   },
		{ WinToastError::NotDisplayed,          L"The toast was created correctly but WinToast was not able to display the toast" },
		{ WinToastError::UnknownError,          L"Unknown error"                                                                  }
	};

	auto const iter = Labels.find(error);
	assert(iter != Labels.end());
	return iter->second;
}

WinToast::ShortcutResult WinToast::createShortcut()
{
	if (m_aumi.empty() || m_appName.empty())
	{
		SPDLOG_ERROR("Error: App User Model Id or Appname is empty!");
		return SHORTCUT_MISSING_PARAMETERS;
	}

	if (!isCompatible())
	{
		SPDLOG_WARN("Your OS is not compatible with this windows notifications!");
		return SHORTCUT_INCOMPATIBLE_OS;
	}

	if (!m_hasCoInitialized)
	{
		HRESULT initHr = CoInitializeEx(nullptr, COINIT::COINIT_MULTITHREADED);
		if (initHr != RPC_E_CHANGED_MODE)
		{
			if (FAILED(initHr) && initHr != S_FALSE)
			{
				SPDLOG_ERROR("Error on COM library initialization: {}", initHr);
				return SHORTCUT_COM_INIT_FAILURE;
			}
			
			m_hasCoInitialized = true;
		}
	}

	bool wasChanged;
	HRESULT hr = validateShellLinkHelper(wasChanged);
	if (SUCCEEDED(hr))
	{
		return wasChanged ? SHORTCUT_WAS_CHANGED : SHORTCUT_UNCHANGED;
	}

	hr = createShellLinkHelper();
	return SUCCEEDED(hr) ? SHORTCUT_WAS_CREATED : SHORTCUT_CREATE_FAILED;
}

bool WinToast::initialize(WinToastError* error)
{
	m_isInitialized = false;
	setError(error, WinToastError::NoError);

	if (!isCompatible())
	{
		setError(error, WinToastError::SystemNotSupported);
		SPDLOG_ERROR("Error: system not supported.");
		return false;
	}

	if (m_aumi.empty() || m_appName.empty())
	{
		setError(error, WinToastError::InvalidParameters);

		SPDLOG_ERROR("Error while initializing, did you set up a valid AUMI and App name?");
		return false;
	}

	if (m_shortcutPolicy != SHORTCUT_POLICY_IGNORE)
	{
		if (createShortcut() < 0)
		{
			setError(error, WinToastError::ShellLinkNotCreated);

			SPDLOG_ERROR("Error while attaching the AUMI to the current proccess");
			return false;
		}
	}

	if (FAILED(DllImporter::SetCurrentProcessExplicitAppUserModelID(m_aumi.c_str())))
	{
		setError(error, WinToastError::InvalidAppUserModelID);

		SPDLOG_ERROR("Error while attaching the AUMI to the current proccess");
		return false;
	}

	m_isInitialized = true;
	return m_isInitialized;
}

bool WinToast::isInitialized() const
{
	return m_isInitialized;
}

const std::wstring& WinToast::appName() const
{
	return m_appName;
}

const std::wstring& WinToast::appUserModelId() const
{
	return m_aumi;
}

HRESULT WinToast::validateShellLinkHelper(bool& wasChanged)
{
	WCHAR path[MAX_PATH] = { L'\0' };
	Util::defaultShellLinkPath(m_appName, path);

	// Check if the file exist
	DWORD attr = GetFileAttributesW(path);
	if (attr >= 0xFFFFFFF)
	{
		SPDLOG_ERROR("Error, shell link not found. Try to create a new one in: {}", mq::wstring_to_utf8(path));
		return E_FAIL;
	}

	// Let's load the file as shell link to validate.
	// - Create a shell link
	// - Create a persistant file
	// - Load the path as data for the persistant file
	// - Read the property AUMI and validate with the current
	// - Review if AUMI is equal.

	ComPtr<IShellLink> shellLink;
	HRESULT hr = CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&shellLink));
	if (SUCCEEDED(hr))
	{
		ComPtr<IPersistFile> persistFile;

		hr = shellLink.As(&persistFile);
		if (SUCCEEDED(hr))
		{
			hr = persistFile->Load(path, STGM_READWRITE);
			if (SUCCEEDED(hr))
			{
				ComPtr<IPropertyStore> propertyStore;

				hr = shellLink.As(&propertyStore);
				if (SUCCEEDED(hr))
				{
					PROPVARIANT appIdPropVar;

					hr = propertyStore->GetValue(PKEY_AppUserModel_ID, &appIdPropVar);
					if (SUCCEEDED(hr))
					{
						WCHAR AUMI[MAX_PATH];

						hr = DllImporter::PropVariantToString(appIdPropVar, AUMI, MAX_PATH);
						wasChanged = false;
						if (FAILED(hr) || m_aumi != AUMI)
						{
							if (m_shortcutPolicy == SHORTCUT_POLICY_REQUIRE_CREATE)
							{
								// AUMI Changed for the same app, let's update the current value! =)
								wasChanged = true;
								PropVariantClear(&appIdPropVar);

								hr = InitPropVariantFromString(m_aumi.c_str(), &appIdPropVar);
								if (SUCCEEDED(hr))
								{
									hr = propertyStore->SetValue(PKEY_AppUserModel_ID, appIdPropVar);
									if (SUCCEEDED(hr))
									{
										hr = propertyStore->Commit();
										if (SUCCEEDED(hr) && SUCCEEDED(persistFile->IsDirty()))
										{
											hr = persistFile->Save(path, TRUE);
										}
									}
								}
							}
							else
							{
								// Not allowed to touch the shortcut to fix the AUMI
								hr = E_FAIL;
							}
						}

						PropVariantClear(&appIdPropVar);
					}
				}
			}
		}
	}
	return hr;
}

HRESULT WinToast::createShellLinkHelper()
{
	if (m_shortcutPolicy != SHORTCUT_POLICY_REQUIRE_CREATE)
	{
		return E_FAIL;
	}

	WCHAR exePath[MAX_PATH]{ L'\0' };
	WCHAR slPath[MAX_PATH]{ L'\0' };

	Util::defaultShellLinkPath(m_appName, slPath);
	Util::defaultExecutablePath(exePath);

	ComPtr<IShellLinkW> shellLink;

	HRESULT hr = CoCreateInstance(CLSID_ShellLink, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&shellLink));
	if (SUCCEEDED(hr))
	{
		hr = shellLink->SetPath(exePath);
		if (SUCCEEDED(hr))
		{
			hr = shellLink->SetArguments(L"");
			if (SUCCEEDED(hr))
			{
				hr = shellLink->SetWorkingDirectory(exePath);
				if (SUCCEEDED(hr))
				{
					ComPtr<IPropertyStore> propertyStore;

					hr = shellLink.As(&propertyStore);
					if (SUCCEEDED(hr))
					{
						PROPVARIANT appIdPropVar;

						hr = InitPropVariantFromString(m_aumi.c_str(), &appIdPropVar);
						if (SUCCEEDED(hr))
						{

							hr = propertyStore->SetValue(PKEY_AppUserModel_ID, appIdPropVar);
							if (SUCCEEDED(hr))
							{
								hr = propertyStore->Commit();
								if (SUCCEEDED(hr))
								{
									ComPtr<IPersistFile> persistFile;

									hr = shellLink.As(&persistFile);
									if (SUCCEEDED(hr))
									{
										hr = persistFile->Save(slPath, TRUE);
									}
								}
							}
							PropVariantClear(&appIdPropVar);
						}
					}
				}
			}
		}
	}

	return hr;
}

int64_t WinToast::showToast(const WinToastTemplate& toast, std::shared_ptr<IWinToastHandler> handler, WinToastError* error)
{
	setError(error, WinToastError::NoError);
	int64_t id = -1;

	if (!isInitialized())
	{
		setError(error, WinToastError::NotInitialized);

		SPDLOG_ERROR("Error when launching the toast. WinToast is not initialized.");
		return id;
	}

	if (!handler)
	{
		setError(error, WinToastError::InvalidHandler);

		SPDLOG_ERROR("Error when launching the toast. Handler cannot be nullptr.");
		return id;
	}

	ComPtr<IToastNotificationManagerStatics> notificationManager;

	HRESULT hr = DllImporter::Wrap_GetActivationFactory(
		WinToastStringWrapper(RuntimeClass_Windows_UI_Notifications_ToastNotificationManager).Get(), &notificationManager);
	if (SUCCEEDED(hr))
	{
		ComPtr<IToastNotifier> notifier;

		hr = notificationManager->CreateToastNotifierWithId(WinToastStringWrapper(m_aumi).Get(), &notifier);
		if (SUCCEEDED(hr))
		{
			ComPtr<IToastNotificationFactory> notificationFactory;

			hr = DllImporter::Wrap_GetActivationFactory(
				WinToastStringWrapper(RuntimeClass_Windows_UI_Notifications_ToastNotification).Get(), &notificationFactory);
			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlDocument> xmlDocument;

				hr = notificationManager->GetTemplateContent(ToastTemplateType(toast.type()), &xmlDocument);
				if (SUCCEEDED(hr) && toast.isToastGeneric())
				{
					hr = setBindToastGenericHelper(xmlDocument.Get());
				}

				if (SUCCEEDED(hr))
				{
					for (uint32_t i = 0, fieldsCount = static_cast<uint32_t>(toast.textFieldsCount()); i < fieldsCount && SUCCEEDED(hr); i++)
					{
						hr = setTextFieldHelper(xmlDocument.Get(), toast.textField(WinToastTemplate::TextField(i)), i);
					}

					// Modern feature are supported Windows > Windows 10
					if (SUCCEEDED(hr) && isSupportingModernFeatures())
					{
						// Note that we do this *after* using toast.textFieldsCount() to
						// iterate/fill the template's text fields, since we're adding yet another text field.
						if (SUCCEEDED(hr) && !toast.attributionText().empty())
						{
							hr = setAttributionTextFieldHelper(xmlDocument.Get(), toast.attributionText());
						}

						std::array<WCHAR, 12> buf;
						for (std::size_t i = 0, actionsCount = toast.actionsCount(); i < actionsCount && SUCCEEDED(hr); i++)
						{
							_snwprintf_s(buf.data(), buf.size(), _TRUNCATE, L"%zd", i);
							hr = addActionHelper(xmlDocument.Get(), toast.actionLabel(i), buf.data());
						}

						if (SUCCEEDED(hr))
						{
							hr = (toast.audioPath().empty() && toast.audioOption() == WinToastTemplate::AudioOption::Default)
								? hr
								: setAudioFieldHelper(xmlDocument.Get(), toast.audioPath(), toast.audioOption());
						}

						if (SUCCEEDED(hr) && toast.duration() != WinToastTemplate::Duration::System)
						{
							hr = addDurationHelper(xmlDocument.Get(),
								(toast.duration() == WinToastTemplate::Duration::Short) ? L"short" : L"long");
						}

						if (SUCCEEDED(hr) && toast.isInput())
						{
							hr = addInputHelper(xmlDocument.Get());
						}

						if (SUCCEEDED(hr))
						{
							hr = addScenarioHelper(xmlDocument.Get(), toast.scenario());
						}

					}
					else
					{
						SPDLOG_DEBUG("Modern features (Actions/Sounds/Attributes) not supported in this os version");
					}

					if (SUCCEEDED(hr))
					{
						bool isWin10AnniversaryOrAbove = WinToast::isWin10AnniversaryOrHigher();
						bool isCircleCropHint = isWin10AnniversaryOrAbove && toast.isCropHintCircle();

						hr = toast.hasImage()
							? setImageFieldHelper(xmlDocument.Get(), toast.imagePath(), toast.isToastGeneric(), isCircleCropHint)
							: hr;
						if (SUCCEEDED(hr) && isWin10AnniversaryOrAbove && toast.hasHeroImage())
						{
							hr = setHeroImageHelper(xmlDocument.Get(), toast.heroImagePath(), toast.isInlineHeroImage());
						}

						if (SUCCEEDED(hr))
						{
							ComPtr<IToastNotification> notification;

							hr = notificationFactory->CreateToastNotification(xmlDocument.Get(), &notification);
							if (SUCCEEDED(hr))
							{
								int64_t expiration = 0, relativeExpiration = toast.expiration();
								if (relativeExpiration > 0)
								{
									InternalDateTime expirationDateTime(relativeExpiration);
									expiration = expirationDateTime;
									hr = notification->put_ExpirationTime(&expirationDateTime);
								}

								EventRegistrationToken activatedToken, dismissedToken, failedToken;
								GUID guid;
								HRESULT hrGuid = CoCreateGuid(&guid);

								id = guid.Data1;
								if (SUCCEEDED(hr) && SUCCEEDED(hrGuid))
								{
									hr = Util::setEventHandlers(notification.Get(), handler, expiration, activatedToken, dismissedToken,
										failedToken, [this, id]() { markAsReadyForDeletion(id); });

									if (FAILED(hr))
									{
										setError(error, WinToastError::InvalidHandler);
									}
								}

								if (SUCCEEDED(hr))
								{
									if (SUCCEEDED(hr))
									{
										m_buffer.emplace(std::piecewise_construct,
											std::forward_as_tuple(id),
											std::forward_as_tuple(notification, activatedToken, dismissedToken, failedToken));

										//SPDLOG_DEBUG("xml: {}", Util::AsString(xmlDocument));

										hr = notifier->Show(notification.Get());
										if (FAILED(hr))
										{
											setError(error, WinToastError::NotDisplayed);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return FAILED(hr) ? -1 : id;
}

ComPtr<IToastNotifier> WinToast::notifier(bool* succeded) const
{
	ComPtr<IToastNotificationManagerStatics> notificationManager;
	ComPtr<IToastNotifier> notifier;

	HRESULT hr = DllImporter::Wrap_GetActivationFactory(
		WinToastStringWrapper(RuntimeClass_Windows_UI_Notifications_ToastNotificationManager).Get(), &notificationManager);
	if (SUCCEEDED(hr))
	{
		hr = notificationManager->CreateToastNotifierWithId(WinToastStringWrapper(m_aumi).Get(), &notifier);
	}

	*succeded = SUCCEEDED(hr);
	return notifier;
}

void WinToast::markAsReadyForDeletion(int64_t id)
{
	// Flush the buffer by removing all the toasts that are ready for deletion
	for (auto it = m_buffer.begin(); it != m_buffer.end();)
	{
		if (it->second.isReadyForDeletion())
		{
			it->second.RemoveTokens();
			it = m_buffer.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Mark the toast as ready for deletion (if it exists) so that it will be removed from the buffer in the next iteration
	auto const iter = m_buffer.find(id);
	if (iter != m_buffer.end())
	{
		m_buffer[id].markAsReadyForDeletion();
	}
}

bool WinToast::hideToast(int64_t id)
{
	if (!isInitialized())
	{
		SPDLOG_ERROR("Error when hiding the toast. WinToast is not initialized.");
		return false;
	}

	auto iter = m_buffer.find(id);
	if (iter == m_buffer.end())
	{
		return false;
	}

	auto succeded = false;
	auto notify = notifier(&succeded);
	if (!succeded)
	{
		return false;
	}

	auto& notifyData = iter->second;
	auto result = notify->Hide(notifyData.notification());
	if (FAILED(result))
	{
		SPDLOG_ERROR("Error when hiding the toast. Error code: {}", result);
		return false;
	}

	notifyData.RemoveTokens();
	m_buffer.erase(iter);
	return SUCCEEDED(result);
}

void WinToast::clear()
{
	auto succeded = false;
	auto notify = notifier(&succeded);
	if (!succeded)
	{
		return;
	}

	for (auto& data : m_buffer)
	{
		auto& notifyData = data.second;
		notify->Hide(notifyData.notification());
		notifyData.RemoveTokens();
	}

	m_buffer.clear();
}

//
// Available as of Windows 10 Anniversary Update
// Ref: https://docs.microsoft.com/en-us/windows/uwp/design/shell/tiles-and-notifications/adaptive-interactive-toasts
//
// NOTE: This will add a new text field, so be aware when iterating over
//       the toast's text fields or getting a count of them.
//
HRESULT WinToast::setAttributionTextFieldHelper(IXmlDocument* xml, const std::wstring& text)
{
	Util::createElement(xml, L"binding", L"text", { L"placement" });
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"text").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		uint32_t nodeListLength;

		hr = nodeList->get_Length(&nodeListLength);
		if (SUCCEEDED(hr))
		{
			for (uint32_t i = 0; i < nodeListLength; i++)
			{
				ComPtr<IXmlNode> textNode;

				hr = nodeList->Item(i, &textNode);
				if (SUCCEEDED(hr))
				{
					ComPtr<IXmlNamedNodeMap> attributes;

					hr = textNode->get_Attributes(&attributes);
					if (SUCCEEDED(hr))
					{
						ComPtr<IXmlNode> editedNode;
						if (SUCCEEDED(hr))
						{
							hr = attributes->GetNamedItem(WinToastStringWrapper(L"placement").Get(), &editedNode);
							if (FAILED(hr) || !editedNode)
							{
								continue;
							}

							hr = Util::setNodeStringValue(L"attribution", editedNode.Get(), xml);
							if (SUCCEEDED(hr))
							{
								return setTextFieldHelper(xml, text, i);
							}
						}
					}
				}
			}
		}
	}
	return hr;
}

HRESULT WinToast::addDurationHelper(IXmlDocument* xml, const std::wstring& duration)
{
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"toast").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		uint32_t length;
		hr = nodeList->get_Length(&length);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> toastNode;

			hr = nodeList->Item(0, &toastNode);
			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlElement> toastElement;

				hr = toastNode.As(&toastElement);
				if (SUCCEEDED(hr))
				{
					hr = toastElement->SetAttribute(WinToastStringWrapper(L"duration").Get(), WinToastStringWrapper(duration).Get());
				}
			}
		}
	}

	return hr;
}

HRESULT WinToast::addScenarioHelper(IXmlDocument* xml, const std::wstring& scenario)
{
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"toast").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		uint32_t length;

		hr = nodeList->get_Length(&length);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> toastNode;

			hr = nodeList->Item(0, &toastNode);
			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlElement> toastElement;

				hr = toastNode.As(&toastElement);
				if (SUCCEEDED(hr))
				{
					hr = toastElement->SetAttribute(WinToastStringWrapper(L"scenario").Get(), WinToastStringWrapper(scenario).Get());
				}
			}
		}
	}

	return hr;
}

HRESULT WinToast::addInputHelper(IXmlDocument* xml)
{
	std::vector<std::wstring> attrbs;
	attrbs.push_back(L"id");
	attrbs.push_back(L"type");
	attrbs.push_back(L"placeHolderContent");

	std::vector<std::wstring> attrbs2;
	attrbs2.push_back(L"content");
	attrbs2.push_back(L"arguments");

	Util::createElement(xml, L"toast", L"actions", {});

	Util::createElement(xml, L"actions", L"input", attrbs);
	Util::createElement(xml, L"actions", L"action", attrbs2);

	ComPtr<IXmlNodeList> nodeList;
	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"input").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		ComPtr<IXmlNode> inputNode;

		hr = nodeList->Item(0, &inputNode);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlElement> toastElement;

			hr = inputNode.As(&toastElement);
			if (SUCCEEDED(hr))			
			{
				toastElement->SetAttribute(WinToastStringWrapper(L"id").Get(), WinToastStringWrapper(L"textBox").Get());
				toastElement->SetAttribute(WinToastStringWrapper(L"type").Get(), WinToastStringWrapper(L"text").Get());
				toastElement->SetAttribute(WinToastStringWrapper(L"placeHolderContent").Get(), WinToastStringWrapper(L"...").Get());
			}
		}
	}

	ComPtr<IXmlNodeList> nodeList2;

	hr = xml->GetElementsByTagName(WinToastStringWrapper(L"action").Get(), &nodeList2);
	if (SUCCEEDED(hr))
	{
		ComPtr<IXmlNode> actionNode;

		hr = nodeList2->Item(0, &actionNode);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlElement> actionElement;

			hr = actionNode.As(&actionElement);
			if (SUCCEEDED(hr)) {
				actionElement->SetAttribute(WinToastStringWrapper(L"content").Get(), WinToastStringWrapper(L"Reply").Get());
				actionElement->SetAttribute(WinToastStringWrapper(L"arguments").Get(), WinToastStringWrapper(L"action=reply").Get());
				actionElement->SetAttribute(WinToastStringWrapper(L"hint-inputId").Get(), WinToastStringWrapper(L"textBox").Get());
			}
		}
	}

	return hr;
}

HRESULT WinToast::setTextFieldHelper(IXmlDocument* xml, const std::wstring& text, uint32_t pos)
{
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"text").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		ComPtr<IXmlNode> node;

		hr = nodeList->Item(pos, &node);
		if (SUCCEEDED(hr))
		{
			hr = Util::setNodeStringValue(text, node.Get(), xml);
		}
	}

	return hr;
}

HRESULT WinToast::setBindToastGenericHelper(IXmlDocument* xml)
{
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"binding").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		uint32_t length;

		hr = nodeList->get_Length(&length);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> toastNode;

			hr = nodeList->Item(0, &toastNode);
			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlElement> toastElement;

				hr = toastNode.As(&toastElement);
				if (SUCCEEDED(hr))
				{
					hr = toastElement->SetAttribute(WinToastStringWrapper(L"template").Get(), WinToastStringWrapper(L"ToastGeneric").Get());
				}
			}
		}
	}

	return hr;
}

HRESULT WinToast::setImageFieldHelper(IXmlDocument* xml, const std::wstring& path, bool isToastGeneric, bool isCropHintCircle)
{
	assert(path.size() < MAX_PATH);
	wchar_t imagePath[MAX_PATH] = L"file:///";

	HRESULT hr = StringCchCatW(imagePath, MAX_PATH, path.c_str());
	if (SUCCEEDED(hr))
	{
		ComPtr<IXmlNodeList> nodeList;

		HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"image").Get(), &nodeList);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> node;
			hr = nodeList->Item(0, &node);

			ComPtr<IXmlElement> imageElement;

			HRESULT hrImage = node.As(&imageElement);
			if (SUCCEEDED(hr) && SUCCEEDED(hrImage) && isToastGeneric)
			{
				hr = imageElement->SetAttribute(WinToastStringWrapper(L"placement").Get(), WinToastStringWrapper(L"appLogoOverride").Get());
				if (SUCCEEDED(hr) && isCropHintCircle)
				{
					hr = imageElement->SetAttribute(WinToastStringWrapper(L"hint-crop").Get(), WinToastStringWrapper(L"circle").Get());
				}
			}

			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlNamedNodeMap> attributes;

				hr = node->get_Attributes(&attributes);
				if (SUCCEEDED(hr))
				{
					ComPtr<IXmlNode> editedNode;

					hr = attributes->GetNamedItem(WinToastStringWrapper(L"src").Get(), &editedNode);
					if (SUCCEEDED(hr))
					{
						Util::setNodeStringValue(imagePath, editedNode.Get(), xml);
					}
				}
			}
		}
	}

	return hr;
}

HRESULT WinToast::setAudioFieldHelper(IXmlDocument* xml, const std::wstring& path, WinToastTemplate::AudioOption option)
{
	std::vector<std::wstring> attrs;

	if (!path.empty())
	{
		attrs.push_back(L"src");
	}

	if (option == WinToastTemplate::AudioOption::Loop)
	{
		attrs.push_back(L"loop");
	}

	if (option == WinToastTemplate::AudioOption::Silent)
	{
		attrs.push_back(L"silent");
	}

	Util::createElement(xml, L"toast", L"audio", attrs);

	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"audio").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		ComPtr<IXmlNode> node;

		hr = nodeList->Item(0, &node);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNamedNodeMap> attributes;

			hr = node->get_Attributes(&attributes);
			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlNode> editedNode;
				if (!path.empty())
				{
					if (SUCCEEDED(hr))
					{
						hr = attributes->GetNamedItem(WinToastStringWrapper(L"src").Get(), &editedNode);
						if (SUCCEEDED(hr))
						{
							hr = Util::setNodeStringValue(path, editedNode.Get(), xml);
						}
					}
				}

				if (SUCCEEDED(hr))
				{
					switch (option)
					{
					case WinToastTemplate::AudioOption::Loop:
						hr = attributes->GetNamedItem(WinToastStringWrapper(L"loop").Get(), &editedNode);
						if (SUCCEEDED(hr))
						{
							hr = Util::setNodeStringValue(L"true", editedNode.Get(), xml);
						}
						break;

					case WinToastTemplate::AudioOption::Silent:
						hr = attributes->GetNamedItem(WinToastStringWrapper(L"silent").Get(), &editedNode);
						if (SUCCEEDED(hr))
						{
							hr = Util::setNodeStringValue(L"true", editedNode.Get(), xml);
						}

					default:
						break;
					}
				}
			}
		}
	}

	return hr;
}

HRESULT WinToast::addActionHelper(IXmlDocument* xml, const std::wstring& content, const std::wstring& arguments)
{
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"actions").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		uint32_t length;

		hr = nodeList->get_Length(&length);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> actionsNode;

			if (length > 0)
			{
				hr = nodeList->Item(0, &actionsNode);
			}
			else
			{
				hr = xml->GetElementsByTagName(WinToastStringWrapper(L"toast").Get(), &nodeList);
				if (SUCCEEDED(hr))
				{
					hr = nodeList->get_Length(&length);
					if (SUCCEEDED(hr))
					{
						ComPtr<IXmlNode> toastNode;
						hr = nodeList->Item(0, &toastNode);
						if (SUCCEEDED(hr))
						{
							ComPtr<IXmlElement> toastElement;

							hr = toastNode.As(&toastElement);
							if (SUCCEEDED(hr))
							{
								hr = toastElement->SetAttribute(WinToastStringWrapper(L"template").Get(),
									WinToastStringWrapper(L"ToastGeneric").Get());
							}

							if (SUCCEEDED(hr))
							{
								hr = toastElement->SetAttribute(WinToastStringWrapper(L"duration").Get(),
									WinToastStringWrapper(L"long").Get());
							}

							if (SUCCEEDED(hr))
							{
								ComPtr<IXmlElement> actionsElement;

								hr = xml->CreateElement(WinToastStringWrapper(L"actions").Get(), &actionsElement);
								if (SUCCEEDED(hr))
								{
									hr = actionsElement.As(&actionsNode);
									if (SUCCEEDED(hr))
									{
										ComPtr<IXmlNode> appendedChild;
										hr = toastNode->AppendChild(actionsNode.Get(), &appendedChild);
									}
								}
							}
						}
					}
				}
			}

			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlElement> actionElement;

				hr = xml->CreateElement(WinToastStringWrapper(L"action").Get(), &actionElement);
				if (SUCCEEDED(hr))
				{
					hr = actionElement->SetAttribute(WinToastStringWrapper(L"content").Get(), WinToastStringWrapper(content).Get());
				}

				if (SUCCEEDED(hr))
				{
					hr = actionElement->SetAttribute(WinToastStringWrapper(L"arguments").Get(), WinToastStringWrapper(arguments).Get());
				}

				if (SUCCEEDED(hr))
				{
					ComPtr<IXmlNode> actionNode;

					hr = actionElement.As(&actionNode);
					if (SUCCEEDED(hr))
					{
						ComPtr<IXmlNode> appendedChild;
						hr = actionsNode->AppendChild(actionNode.Get(), &appendedChild);
					}
				}
			}
		}
	}

	return hr;
}

HRESULT WinToast::setHeroImageHelper(IXmlDocument* xml, const std::wstring& path, bool isInlineImage)
{
	ComPtr<IXmlNodeList> nodeList;

	HRESULT hr = xml->GetElementsByTagName(WinToastStringWrapper(L"binding").Get(), &nodeList);
	if (SUCCEEDED(hr))
	{
		uint32_t length;

		hr = nodeList->get_Length(&length);
		if (SUCCEEDED(hr))
		{
			ComPtr<IXmlNode> bindingNode;

			if (length > 0)
			{
				hr = nodeList->Item(0, &bindingNode);
			}

			if (SUCCEEDED(hr))
			{
				ComPtr<IXmlElement> imageElement;

				hr = xml->CreateElement(WinToastStringWrapper(L"image").Get(), &imageElement);
				if (SUCCEEDED(hr) && isInlineImage == false)
				{
					hr = imageElement->SetAttribute(WinToastStringWrapper(L"placement").Get(), WinToastStringWrapper(L"hero").Get());
				}

				if (SUCCEEDED(hr))
				{
					hr = imageElement->SetAttribute(WinToastStringWrapper(L"src").Get(), WinToastStringWrapper(path).Get());
				}

				if (SUCCEEDED(hr))
				{
					ComPtr<IXmlNode> actionNode;

					hr = imageElement.As(&actionNode);
					if (SUCCEEDED(hr))
					{
						ComPtr<IXmlNode> appendedChild;
						hr = bindingNode->AppendChild(actionNode.Get(), &appendedChild);
					}
				}
			}
		}
	}
	return hr;
}

void WinToast::setError(WinToastError* error, WinToastError value)
{
	if (error)
	{
		*error = value;
	}
}

WinToastTemplate::WinToastTemplate(WinToastTemplateType type)
	: m_type(type)
{
	static const std::size_t TextFieldsCount[] = { 1, 2, 2, 3, 1, 2, 2, 3 };

	m_textFields = std::vector<std::wstring>(TextFieldsCount[type], L"");
}

WinToastTemplate::~WinToastTemplate()
{
}

void WinToastTemplate::setTextField(const std::wstring& txt, WinToastTemplate::TextField pos)
{
	const size_t position = static_cast<std::size_t>(pos);

	if (position >= m_textFields.size())
	{
		SPDLOG_WARN("The selected template type supports only {} text lines", m_textFields.size());
		return;
	}

	m_textFields[position] = txt;
}

void WinToastTemplate::setTextField(const std::string& txt, WinToastTemplate::TextField pos)
{
	setTextField(mq::utf8_to_wstring(txt), pos);
}

void WinToastTemplate::setImagePath(const std::wstring& imgPath, CropHint cropHint)
{
	m_imagePath = imgPath;
	m_cropHint = cropHint;
}

void WinToastTemplate::setHeroImagePath(const std::wstring& imgPath, bool inlineImage)
{
	m_heroImagePath = imgPath;
	m_inlineHeroImage = inlineImage;
}

void WinToastTemplate::setAudioPath(const std::wstring& audioPath)
{
	m_audioPath = audioPath;
}

void WinToastTemplate::setAudioPath(AudioSystemFile file)
{
	static const std::unordered_map<AudioSystemFile, std::wstring> Files =
	{
		{ AudioSystemFile::DefaultSound, L"ms-winsoundevent:Notification.Default"         },
		{ AudioSystemFile::IM,           L"ms-winsoundevent:Notification.IM"              },
		{ AudioSystemFile::Mail,         L"ms-winsoundevent:Notification.Mail"            },
		{ AudioSystemFile::Reminder,     L"ms-winsoundevent:Notification.Reminder"        },
		{ AudioSystemFile::SMS,          L"ms-winsoundevent:Notification.SMS"             },
		{ AudioSystemFile::Alarm,        L"ms-winsoundevent:Notification.Looping.Alarm"   },
		{ AudioSystemFile::Alarm2,       L"ms-winsoundevent:Notification.Looping.Alarm2"  },
		{ AudioSystemFile::Alarm3,       L"ms-winsoundevent:Notification.Looping.Alarm3"  },
		{ AudioSystemFile::Alarm4,       L"ms-winsoundevent:Notification.Looping.Alarm4"  },
		{ AudioSystemFile::Alarm5,       L"ms-winsoundevent:Notification.Looping.Alarm5"  },
		{ AudioSystemFile::Alarm6,       L"ms-winsoundevent:Notification.Looping.Alarm6"  },
		{ AudioSystemFile::Alarm7,       L"ms-winsoundevent:Notification.Looping.Alarm7"  },
		{ AudioSystemFile::Alarm8,       L"ms-winsoundevent:Notification.Looping.Alarm8"  },
		{ AudioSystemFile::Alarm9,       L"ms-winsoundevent:Notification.Looping.Alarm9"  },
		{ AudioSystemFile::Alarm10,      L"ms-winsoundevent:Notification.Looping.Alarm10" },
		{ AudioSystemFile::Call,         L"ms-winsoundevent:Notification.Looping.Call"    },
		{ AudioSystemFile::Call1,        L"ms-winsoundevent:Notification.Looping.Call1"   },
		{ AudioSystemFile::Call2,        L"ms-winsoundevent:Notification.Looping.Call2"   },
		{ AudioSystemFile::Call3,        L"ms-winsoundevent:Notification.Looping.Call3"   },
		{ AudioSystemFile::Call4,        L"ms-winsoundevent:Notification.Looping.Call4"   },
		{ AudioSystemFile::Call5,        L"ms-winsoundevent:Notification.Looping.Call5"   },
		{ AudioSystemFile::Call6,        L"ms-winsoundevent:Notification.Looping.Call6"   },
		{ AudioSystemFile::Call7,        L"ms-winsoundevent:Notification.Looping.Call7"   },
		{ AudioSystemFile::Call8,        L"ms-winsoundevent:Notification.Looping.Call8"   },
		{ AudioSystemFile::Call9,        L"ms-winsoundevent:Notification.Looping.Call9"   },
		{ AudioSystemFile::Call10,       L"ms-winsoundevent:Notification.Looping.Call10"  },
	};

	auto const iter = Files.find(file);
	assert(iter != Files.end());
	m_audioPath = iter->second;
}

void WinToastTemplate::setAudioOption(WinToastTemplate::AudioOption audioOption)
{
	m_audioOption = audioOption;
}

void WinToastTemplate::setFirstLine(const std::wstring& text)
{
	setTextField(text, WinToastTemplate::FirstLine);
}

void WinToastTemplate::setFirstLine(const std::string& text)
{
	setTextField(mq::utf8_to_wstring(text), WinToastTemplate::FirstLine);
}

void WinToastTemplate::setSecondLine(const std::wstring& text)
{
	setTextField(text, WinToastTemplate::SecondLine);
}

void WinToastTemplate::setSecondLine(const std::string& text)
{
	setTextField(mq::utf8_to_wstring(text), WinToastTemplate::SecondLine);
}

void WinToastTemplate::setThirdLine(const std::wstring& text)
{
	setTextField(text, WinToastTemplate::ThirdLine);
}

void WinToastTemplate::setThirdLine(const std::string& text)
{
	setTextField(mq::utf8_to_wstring(text), WinToastTemplate::ThirdLine);
}

void WinToastTemplate::setDuration(Duration duration)
{
	m_duration = duration;
}

void WinToastTemplate::setExpiration(int64_t millisecondsFromNow)
{
	m_expiration = millisecondsFromNow;
}

void WinToastLib::WinToastTemplate::setScenario(Scenario scenario)
{
	switch (scenario)
	{
	case Scenario::Default:
		m_scenario = L"Default";
		break;
	case Scenario::Alarm:
		m_scenario = L"Alarm";
		break;
	case Scenario::IncomingCall:
		m_scenario = L"IncomingCall";
		break;
	case Scenario::Reminder:
		m_scenario = L"Reminder";
		break;
	}
}

void WinToastTemplate::setAttributionText(const std::wstring& attributionText)
{
	m_attributionText = attributionText;
}

void WinToastTemplate::addAction(const std::wstring& label)
{
	m_actions.push_back(label);
}

void WinToastTemplate::addAction(const std::string& label)
{
	m_actions.push_back(mq::utf8_to_wstring(label));
}

void WinToastTemplate::addInput()
{
	m_hasInput = true;
}

std::size_t WinToastTemplate::textFieldsCount() const
{
	return m_textFields.size();
}

std::size_t WinToastTemplate::actionsCount() const
{
	return m_actions.size();
}

bool WinToastTemplate::hasImage() const
{
	return m_type < WinToastTemplateType::Text01;
}

bool WinToastTemplate::hasHeroImage() const
{
	return hasImage() && !m_heroImagePath.empty();
}

const std::vector<std::wstring>& WinToastTemplate::textFields() const
{
	return m_textFields;
}

const std::wstring& WinToastTemplate::textField(TextField pos) const
{
	auto const position = static_cast<std::size_t>(pos);
	assert(position < m_textFields.size());

	return m_textFields[position];
}

const std::wstring& WinToastTemplate::actionLabel(std::size_t position) const
{
	assert(position < m_actions.size());
	return m_actions[position];
}

const std::wstring& WinToastTemplate::imagePath() const
{
	return m_imagePath;
}

const std::wstring& WinToastTemplate::heroImagePath() const
{
	return m_heroImagePath;
}

const std::wstring& WinToastTemplate::audioPath() const
{
	return m_audioPath;
}

const std::wstring& WinToastTemplate::attributionText() const
{
	return m_attributionText;
}

const std::wstring& WinToastLib::WinToastTemplate::scenario() const
{
	return m_scenario;
}

int64_t WinToastTemplate::expiration() const
{
	return m_expiration;
}

WinToastTemplate::WinToastTemplateType WinToastTemplate::type() const
{
	return m_type;
}

WinToastTemplate::AudioOption WinToastTemplate::audioOption() const
{
	return m_audioOption;
}

WinToastTemplate::Duration WinToastTemplate::duration() const
{
	return m_duration;
}

bool WinToastTemplate::isToastGeneric() const
{
	return hasHeroImage() || m_cropHint == WinToastTemplate::Circle;
}

bool WinToastTemplate::isInlineHeroImage() const
{
	return m_inlineHeroImage;
}

bool WinToastTemplate::isCropHintCircle() const
{
	return m_cropHint == CropHint::Circle;
}

bool WinToastTemplate::isInput() const
{
	return m_hasInput;
}

} // namespace WinToastLib
