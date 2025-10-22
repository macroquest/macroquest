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

#include "MacroQuest.h"
#include "ProcessMonitor.h"

#include "mq/base/String.h"

#include "fmt/os.h"
#include "wil/com.h"
#include "wil/resource.h"
#include "spdlog/spdlog.h"

#include <chrono>
#include <memory>
#include <comutil.h>
#include <wrl.h>

using namespace std::chrono_literals;

using Microsoft::WRL::ComPtr;

ProcessMonitorEvents* gpProcessMonitorEvents = nullptr;

class ProcessMonitor
{
public:
	virtual ~ProcessMonitor() = default;

	virtual void Start() = 0;
	virtual void Stop() = 0;
};

std::unique_ptr<ProcessMonitor> pMonitor;

#pragma region WMI Process Monitor

// https://github.com/MvkZ/ServiceProcessWorks/tree/master/process_notify/process_notify

_COM_SMARTPTR_TYPEDEF(IWbemClassObject, __uuidof(IWbemClassObject));
_COM_SMARTPTR_TYPEDEF(IUnsecuredApartment, __uuidof(IUnsecuredApartment));

class WmiQueryEventSink : public IWbemObjectSink
{
public:
	WmiQueryEventSink(bool bCreate)
	{
		m_bIsCreation = bCreate;
		m_lRef = 0;
	}
	~WmiQueryEventSink()
	{
		m_bDone = true;
	}

	virtual ULONG STDMETHODCALLTYPE AddRef() override
	{
		return InterlockedIncrement(&m_lRef);
	}

	virtual ULONG STDMETHODCALLTYPE Release() override
	{
		LONG lRef = InterlockedDecrement(&m_lRef);
		if (lRef == 0)
			delete this;

		return lRef;
	}

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override
	{
		if (riid == IID_IUnknown || riid == IID_IWbemObjectSink)
		{
			*ppv = (IWbemObjectSink*)this;
			AddRef();

			return WBEM_S_NO_ERROR;
		}

		return E_NOINTERFACE;
	}

	virtual HRESULT STDMETHODCALLTYPE Indicate(LONG lObjectCount, IWbemClassObject** apObjArray) override
	{
		for (int i = 0; i < lObjectCount; i++)
		{
			IWbemClassObject* pObj = apObjArray[i];

			VARIANT vInst_;
			HRESULT hres = pObj->Get(L"TargetInstance", 0, &vInst_, nullptr, nullptr);
			if (FAILED(hres))
			{
				continue;
			}

			try
			{
				variant_t vInst;
				vInst.Attach(vInst_);

				IWbemClassObjectPtr pWin32ProcessObj(vInst);
				VARIANT vPid;

				hres = pWin32ProcessObj->Get(L"ProcessID", 0, &vPid, nullptr, nullptr);
				if (FAILED(hres))
				{
					SPDLOG_ERROR("Failed to get ProcessID");
				}
				else
				{
					if (m_bIsCreation)
					{
						HandleProcessCreation(vPid.ulVal);
					}
					else
					{
						HandleProcessDestruction(vPid.ulVal);
					}
				}
			}
			catch (_com_error& err)
			{
				UNREFERENCED_PARAMETER(err);
				SPDLOG_ERROR("caught _com_error: {}", err.ErrorMessage());
			}
		}

		return WBEM_S_NO_ERROR;
	}

	virtual HRESULT STDMETHODCALLTYPE SetStatus(LONG lFlags, HRESULT hResult, BSTR strParam, IWbemClassObject* pObjParam) override
	{
		return WBEM_S_NO_ERROR;
	}

	void HandleProcessCreation(DWORD processId)
	{
		gpProcessMonitorEvents->HandleProcessCreation(processId);
	}

	void HandleProcessDestruction(DWORD processId)
	{
		gpProcessMonitorEvents->HandleProcessDestruction(processId);
	}

private:
	LONG m_lRef = 0;
	bool m_bDone = false;
	bool m_bIsCreation = false;
};

class WmiProcessMonitor : public ProcessMonitor
{
public:
	WmiProcessMonitor() = default;
	~WmiProcessMonitor() = default;

	void Start() override;
	void Stop() override;

private:
	wil::com_ptr<IWbemServices> m_wbemServices;
	wil::com_ptr<WmiQueryEventSink> m_creationSink;
	wil::com_ptr<IWbemObjectSink> m_creationSinkStub;
	wil::com_ptr<WmiQueryEventSink> m_destructionSink;
	wil::com_ptr<IWbemObjectSink> m_destructionSinkStub;
};

void WmiProcessMonitor::Start()
{
	// Set general COM Security levels
	THROW_IF_FAILED(CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT,
		RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr));

	// Obtain the initial locator to WMI
	wil::com_ptr<IWbemLocator> wbemLocator = wil::CoCreateInstance<IWbemLocator>(CLSID_WbemLocator);

	// Connect to WMI through the IWbemLocator::ConnectServer method
	wil::com_ptr<IWbemServices> wbemServices;
	THROW_IF_FAILED(wbemLocator->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), nullptr, nullptr, nullptr, 0, nullptr, nullptr, &wbemServices));

	// Set security levels on the proxy
	THROW_IF_FAILED(CoSetProxyBlanket(wbemServices.get(), RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, nullptr, RPC_C_AUTHN_LEVEL_CALL,
		RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE));

	// Receive event notifications

	// Use an unsecured apartment for security
	auto pUnsecApp = wil::CoCreateInstance<IUnsecuredApartment>(CLSID_UnsecuredApartment, CLSCTX_LOCAL_SERVER);

	//----------------------------------------------------------------------------
	// Create the creation sink
	m_creationSink = new WmiQueryEventSink(true);

	wil::com_ptr<IUnknown> pStubUnkCreation;
	pUnsecApp->CreateObjectStub(m_creationSink.get(), &pStubUnkCreation);
	auto creationSinkStub = pStubUnkCreation.query<IWbemObjectSink>();

	THROW_IF_FAILED(wbemServices->ExecNotificationQueryAsync(
		bstr_t("WQL"),
		bstr_t("SELECT * FROM __InstanceCreationEvent WITHIN 1 WHERE TargetInstance ISA 'Win32_Process' AND TargetInstance.Name = 'eqgame.exe'"),
		WBEM_FLAG_SEND_STATUS, nullptr, creationSinkStub.get()));

	//----------------------------------------------------------------------------
	// Create the destruction sink

	m_destructionSink = new WmiQueryEventSink(false);

	wil::com_ptr<IUnknown> pStubUnkDeletion;
	pUnsecApp->CreateObjectStub(m_destructionSink.get(), &pStubUnkDeletion);
	auto destructionSinkStub = pStubUnkDeletion.query<IWbemObjectSink>();

	THROW_IF_FAILED(wbemServices->ExecNotificationQueryAsync(
		bstr_t("WQL"),
		bstr_t("SELECT * FROM __InstanceDeletionEvent WITHIN 1 WHERE TargetInstance ISA 'Win32_Process' AND TargetInstance.Name = 'eqgame.exe'"),
		WBEM_FLAG_SEND_STATUS, nullptr, destructionSinkStub.get()));

	m_wbemServices = wbemServices;
	m_creationSinkStub = creationSinkStub;
	m_destructionSinkStub = destructionSinkStub;
}

void WmiProcessMonitor::Stop()
{
	if (m_wbemServices)
	{
		if (m_creationSinkStub)
		{
			m_wbemServices->CancelAsyncCall(m_creationSinkStub.get());
		}

		if (m_destructionSinkStub)
		{
			m_wbemServices->CancelAsyncCall(m_destructionSinkStub.get());
		}
	}
}

bool StartWMIProcessMonitor()
{
	// Try to start a WmiProcess monitor
	try
	{
		auto monitor = std::make_unique<WmiProcessMonitor>();
		monitor->Start();
		pMonitor = std::move(monitor);
		SPDLOG_INFO("Process monitor using WMI started");
		return true;
	}
	catch (const std::exception& err)
	{
		SPDLOG_ERROR("Failed to start wmi process monitor: {}", err.what());

		return false;
	}
}

#pragma endregion

#pragma region ToolHelp Process Monitor

class ToolHelpProcessMonitor : public ProcessMonitor
{
public:
	ToolHelpProcessMonitor();
	~ToolHelpProcessMonitor();

	virtual void Start() override;
	virtual void Stop() override;

private:
	void ThreadProc();

	wil::unique_event m_event;
	std::atomic_bool m_running{ false };
	std::thread m_thread;
};

ToolHelpProcessMonitor::ToolHelpProcessMonitor()
{
}

ToolHelpProcessMonitor::~ToolHelpProcessMonitor()
{
	Stop();
}

void ToolHelpProcessMonitor::Start()
{
	if (m_running)
		return;

	m_thread = std::thread([this]() { ThreadProc(); });
	m_running = true;
	m_event.create(wil::EventOptions::ManualReset);
}

void ToolHelpProcessMonitor::Stop()
{
	if (!m_running)
		return;

	m_running = false;
	m_event.SetEvent();
	if (m_thread.joinable())
		m_thread.join();
}

void ToolHelpProcessMonitor::ThreadProc()
{
	// vector of open processes. the unique_process_handle will keep the handle
	// open while we wait on it.
	std::vector<std::pair<DWORD, wil::unique_process_handle>> allProcesses;
	std::vector<DWORD> processList;
	std::vector<HANDLE> waitList;
	waitList.push_back(m_event.get());
	bool initial = true;
	bool switchToWMI = false;

	do
	{
		processList.clear();
		processList.reserve(allProcesses.size()); // Assume that nothing changed

		// Retrieve process list
		wil::unique_tool_help_snapshot hSnapshot(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

		if (hSnapshot.is_valid())
		{
			PROCESSENTRY32 proc = { sizeof(PROCESSENTRY32) };

			if (Process32First(hSnapshot.get(), &proc))
			{
				do
				{
					if (mq::ci_equals(proc.szExeFile, "eqgame.exe"))
					{
						processList.push_back(proc.th32ProcessID);
					}
				} while (Process32Next(hSnapshot.get(), &proc));
			}
		}

		// Compare with the currently known list.
		for (DWORD processId : processList)
		{
			if (std::find_if(std::begin(allProcesses), std::end(allProcesses),
				[processId](const auto& pi) { return pi.first == processId; })
				== std::end(allProcesses))
			{
				// not found, this is a new process.
				wil::unique_process_handle hProcess(OpenProcess(SYNCHRONIZE, FALSE, processId));
				if (hProcess)
				{
					waitList.push_back(hProcess.get());
					allProcesses.emplace_back(processId, std::move(hProcess));

					if (!initial)
						gpProcessMonitorEvents->HandleProcessCreation(processId);
				}
			}
		}

		// Now we wait. The first element is always the event.
		DWORD result = ::WaitForMultipleObjects((DWORD)waitList.size(), &waitList[0], FALSE, 5000);

		if (result == WAIT_FAILED)
		{
			if (waitList.size() >= MAXIMUM_WAIT_OBJECTS)
			{
				// SPDLOG_ERROR("Encountered more than the maximum number of processes while waiting on ToolhelpThread: {}! "
				// 	"Switching to WMI process monitor.", waitList.size());
				// switchToWMI = true;
				// m_running = false;

				Sleep(2500); // Well, we were going to sleep for 5 seconds as a timeout anyway.
			}
			else
			{
				SPDLOG_WARN("{}",
					fmt::windows_error(GetLastError(), "ToolHelpThread: failed in WaitForMultipleObjects").what());
			}
		}
		else if (result != WAIT_TIMEOUT)
		{
			if (result >= WAIT_OBJECT_0 && result <= WAIT_OBJECT_0 + waitList.size())
			{
				int index = result - WAIT_OBJECT_0;
				HANDLE hHandle = waitList[index];

				// If its index 0, then the wake up event was signaled. Everything else is a process handle.
				if (index > 0)
				{
					waitList.erase(waitList.begin() + index);

					DWORD processId = allProcesses[index - 1].first;
					allProcesses.erase(allProcesses.begin() + index - 1);

					gpProcessMonitorEvents->HandleProcessDestruction(processId);
				}
			}
		}

		initial = false;
	} while (m_running);

	SPDLOG_DEBUG("Process Monitor Thread Exit");

	if (switchToWMI)
	{
		// Detach this thread so we can destroy the process monitor.
		m_thread.detach();

		StartWMIProcessMonitor();
	}
}

bool StartToolHelpProcessMonitor()
{
	try
	{
		auto monitor = std::make_unique<ToolHelpProcessMonitor>();
		monitor->Start();
		pMonitor = std::move(monitor);
		SPDLOG_INFO("Process monitor using ToolHelp started");
		return true;
	}
	catch (const std::exception& err)
	{
		SPDLOG_ERROR("Failed to start toolhelp process monitor: {}", err.what());
		return false;
	}
}

#pragma endregion

void StartProcessMonitor(ProcessMonitorEvents* pEvents)
{
	gpProcessMonitorEvents = pEvents;

	// Try to start the tooltip process monitor
	bool success = StartToolHelpProcessMonitor();
	if (!success)
	{
		success = StartWMIProcessMonitor();
	}

	if (!success)
	{
		SPDLOG_ERROR("Unable to start a process monitor. Will not be able to inject!!");
	}
}

void StopProcessMonitor()
{
	if (pMonitor)
	{
		pMonitor->Stop();
		pMonitor.reset();
	}

	gpProcessMonitorEvents = nullptr;
}