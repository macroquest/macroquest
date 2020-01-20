#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2MacroQuestType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2MacroQuestType::FindMember(Member);
	if (!pMember)
		return pEverQuestType->GetMember(*(MQVarPtr*)& VarPtr.Ptr, Member, Index, Dest);

	switch (static_cast<MacroQuestMembers>(pMember->ID))
	{
	case Error:
		if (gszLastNormalError[0]) // QUIT SETTING THIS MANUALLY, USE MacroError, FatalError, ETC
		{
			Dest.Ptr = &gszLastNormalError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case SyntaxError:
		if (gszLastSyntaxError[0])
		{
			Dest.Ptr = &gszLastSyntaxError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case MQ2DataError:
		if (gszLastMQ2DataError[0])
		{
			Dest.Ptr = &gszLastMQ2DataError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;

	case BuildDate: {
		SYSTEMTIME st;
		HANDLE hFile;
		WIN32_FIND_DATA FileData;
		std::filesystem::path pathMQ2Main = std::filesystem::path(mq::internal_paths::MQRoot) / "MQ2Main.dll";
		hFile = FindFirstFile(pathMQ2Main.string().c_str(), &FileData);
		// Convert the creation time time to local time.
		FileTimeToSystemTime(&FileData.ftLastWriteTime, &st);
		FindClose(hFile);
		sprintf_s(DataTypeTemp, "%04d%02d%02d", st.wYear, st.wMonth, st.wDay);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case Build:
		Dest.DWord = gBuild;
		Dest.Type = pIntType;
		return true;

	case Path:
		Dest.Type = pStringType;
		if (!Index[0] || ci_equals(Index, "root"))
		{
			Dest.Ptr = &mq::internal_paths::MQRoot[0];
		}
		else if (ci_equals(Index, "config"))
		{
			Dest.Ptr = &mq::internal_paths::Config[0];
		}
		else if (ci_equals(Index, "crashdumps"))
		{
			Dest.Ptr = &mq::internal_paths::CrashDumps[0];
		}
		else if (ci_equals(Index, "logs"))
		{
			Dest.Ptr = &mq::internal_paths::Logs[0];
		}
		else if (ci_equals(Index, "mqini"))
		{
			Dest.Ptr = &mq::internal_paths::MQini[0];
		}
		else if (ci_equals(Index, "macros"))
		{
			Dest.Ptr = &mq::internal_paths::Macros[0];
		}
		else if (ci_equals(Index, "plugins"))
		{
			Dest.Ptr = &mq::internal_paths::Plugins[0];
		}
		else if (ci_equals(Index, "resources"))
		{
			Dest.Ptr = &mq::internal_paths::Resources[0];
		}
		else
		{
			return false;
		}
		return true;

	case Version: {
		// Read the version resource and produce a version number

		// Get module handle to MQ2Main.dll
		HMODULE hMq2Main = nullptr;
		char szModulePath[2048];
		DataTypeTemp[0] = 0;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			reinterpret_cast<const char*>(&DataTypeTemp), &hMq2Main);
		GetModuleFileName(hMq2Main, szModulePath, 2048);

		// Get the size of the version information
		DWORD dwVerHnd = 0;
		uint32_t dwVerInfoSize = GetFileVersionInfoSizeA(szModulePath, &dwVerHnd);

		if (dwVerInfoSize)
		{
			// Retrieve the version information
			std::unique_ptr<uint8_t[]> pVersionInfo = std::make_unique<uint8_t[]>(dwVerInfoSize);
			GetFileVersionInfoA(szModulePath, dwVerHnd, dwVerInfoSize, pVersionInfo.get());

			uint32_t uVersionLen = 0;
			char* lpVersion = nullptr;
			bool bRetCode = VerQueryValueA(pVersionInfo.get(), "\\VarFileInfo\\Translation", (void**)&lpVersion, (uint32_t*)&uVersionLen);

			char szTranslation[20];
			if (bRetCode && uVersionLen && lpVersion)
			{
				sprintf_s(szTranslation, "%04x%04x", LOWORD(*lpVersion), HIWORD(*lpVersion));
			}
			else
			{
				strcpy_s(szTranslation, "041904b0");
			}

			char szGetName[256];
			sprintf_s(szGetName, "\\StringFileInfo\\%s\\FileVersion", szTranslation);

			uVersionLen = 0;
			char* lpString = nullptr;

			bRetCode = VerQueryValue((void*)pVersionInfo.get(), szGetName, (void**)& lpString, (uint32_t*)&uVersionLen);
			if (bRetCode && uVersionLen && lpString)
			{
				strcpy_s(DataTypeTemp, lpString);
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case InternalName: {
		// Read the version resource and produce an internal name string

		// Get module handle to MQ2Main.dll
		HMODULE hMq2Main = nullptr;
		char szModulePath[2048];
		DataTypeTemp[0] = 0;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			reinterpret_cast<const char*>(&DataTypeTemp), &hMq2Main);
		GetModuleFileName(hMq2Main, szModulePath, 2048);

		// Get the size of the version information
		DWORD dwVerHnd = 0;
		uint32_t dwVerInfoSize = GetFileVersionInfoSizeA(szModulePath, &dwVerHnd);

		if (dwVerInfoSize)
		{
			// Retrieve the version information
			std::unique_ptr<uint8_t[]> pVersionInfo = std::make_unique<uint8_t[]>(dwVerInfoSize);
			GetFileVersionInfoA(szModulePath, dwVerHnd, dwVerInfoSize, pVersionInfo.get());

			uint32_t uVersionLen = 0;
			uint32_t* lpVersion = nullptr;
			bool bRetCode = VerQueryValueA(pVersionInfo.get(), "\\VarFileInfo\\Translation", (void**)&lpVersion, (uint32_t*)&uVersionLen);

			char szTranslation[10];
			if (bRetCode && uVersionLen && lpVersion)
			{
				sprintf_s(szTranslation, "%04x%04x", LOWORD(*lpVersion), HIWORD(*lpVersion));
			}
			else
			{
				strcpy_s(szTranslation, "041904b0");
			}

			char szGetName[64];
			sprintf_s(szGetName, "\\StringFileInfo\\%s\\InternalName", szTranslation);

			uVersionLen = 0;
			char* lpString = nullptr;

			bRetCode = VerQueryValue((void*)pVersionInfo.get(), szGetName, (void**)& lpString, (uint32_t*)&uVersionLen);
			if (bRetCode && uVersionLen && lpString)
			{
				strcpy_s(DataTypeTemp, lpString);
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}

	case Parser:
		Dest.DWord = gParserVersion;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

