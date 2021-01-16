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

#include "pch.h"
#include "MQ2Main.h"

namespace mq::datatypes {

bool dataSelect(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	// I hate this GetArg shit - Lax
	char szArg[MAX_STRING] = { 0 };
	char szArg1[MAX_STRING] = { 0 };
	int N = 2;
	// FIXME: const
	GetArg(szArg1, (char*)szIndex, 1, false, false, true);
	while (true)
	{
		// FIXME: const
		GetArg(szArg, (char*)szIndex, N, false, false, true);
		N++;
		if (!szArg[0])
		{
			Ret.DWord = 0;
			Ret.Type = pIntType;
			return true;
		}

		if (!_stricmp(szArg1, szArg))
		{
			Ret.DWord = N - 2;
			Ret.Type = pIntType;
			return true;
		}
	}
}

bool dataIf(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		int nDelimiter = 0;
		const char* pDelimiter = strchr(szIndex, gIfAltDelimiter);

		while (pDelimiter != nullptr)
		{
			nDelimiter++;
			pDelimiter = strchr(pDelimiter + 1, gIfAltDelimiter);
		}

		char szTemp[MAX_STRING];
		strcpy_s(szTemp, szIndex);

		// condition| whentrue| whenfalse
		if (nDelimiter == 2)
		{
			if (char* pTrue = strchr(szTemp, gIfAltDelimiter))
			{
				*pTrue = 0;
				pTrue++;
				if (char* pFalse = strchr(pTrue, gIfAltDelimiter))
				{
					*pFalse = 0;
					pFalse++;
					double CalcResult;
					if (!Calculate(szTemp, CalcResult))
						return false;

					if (CalcResult != 0.0f)
					{
						strcpy_s(DataTypeTemp, pTrue);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
					else
					{
						strcpy_s(DataTypeTemp, pFalse);
						Ret.Ptr = &DataTypeTemp[0];
						Ret.Type = pStringType;
						return true;
					}
				}
			}
		}

		// condition, whentrue, whenfalse
		if (char* pTrue = strchr(szTemp, gIfDelimiter))
		{
			*pTrue = 0;
			pTrue++;
			if (char* pFalse = strchr(pTrue, gIfDelimiter))
			{
				*pFalse = 0;
				pFalse++;
				double CalcResult;
				if (!Calculate(szTemp, CalcResult))
					return false;

				if (CalcResult != 0.0f)
				{
					strcpy_s(DataTypeTemp, pTrue);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
				else
				{
					strcpy_s(DataTypeTemp, pFalse);
					Ret.Ptr = &DataTypeTemp[0];
					Ret.Type = pStringType;
					return true;
				}
			}
		}
	}
	return false;
}


bool dataGameTime(const char* szIndex, MQTypeVar& Ret)
{
	struct tm* pTime = (struct tm*)&DataTypeTemp[0];
	ZeroMemory(pTime, sizeof(struct tm));
	pTime->tm_sec = 0;
	pTime->tm_min = pWorldData->Minute;
	pTime->tm_hour = pWorldData->Hour - 1;
	pTime->tm_mday = pWorldData->Day;
	pTime->tm_mon = pWorldData->Month - 1;
	pTime->tm_year = pWorldData->Year - 1900;
	pTime->tm_wday = (pWorldData->Day - 1) % 7;
	pTime->tm_isdst = 0;

	Ret.Ptr = pTime;
	Ret.Type = pTimeType;
	return true;
}

bool dataIni(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex || szIndex[0] == 0)
		return false;

	std::string sTemp = szIndex;

	int count = 0;
	std::map<int, DWORD> argMap;

	// lets see how many commas are in the string
	for (auto i = sTemp.begin(); i != sTemp.end(); i++)
	{
		if (i[0] == ',' && i + 1 != sTemp.end() && i[1] != ' ')
		{
			argMap[count] = std::distance(sTemp.begin(), i);
			count++;
		}
	}

	std::string IniFile = sTemp;
	bool bNoParse = false;

	std::string Section;
	std::string Key;
	std::string Default;

	if (!argMap.empty())
	{
		IniFile.erase(argMap[0]);
		Section = sTemp.substr(argMap[0] + 1);
		if (argMap.size() >= 2)
		{
			Section.erase(argMap[1] - argMap[0] - 1);
			Key = sTemp.substr(argMap[1] + 1);
			if (argMap.size() >= 3)
			{
				Key.erase(argMap[2] - argMap[1] - 1);
				Default = sTemp.substr(argMap[2] + 1);
				if (argMap.size() >= 4)
				{
					Default.erase(argMap[3] - argMap[2] - 1);
					std::string Parse = sTemp.substr(argMap[3] + 1);

					if (Parse == "noparse")
						bNoParse = true;
				}
			}
		}
	}

	if (IniFile.empty())
		return false;

	std::filesystem::path pathIniFile = IniFile;
	if (!pathIniFile.has_extension())
	{
		pathIniFile += ".ini";
	}

	if (pathIniFile.is_relative())
	{
		// Config is the primary path, but fall back to the old path if needed
		if (!exists(internal_paths::Config / pathIniFile) && exists(internal_paths::Macros / pathIniFile))
		{
			pathIniFile = internal_paths::Macros / pathIniFile;
		}
		else
		{
			pathIniFile = mq::internal_paths::Config / pathIniFile;
		}
	}

	std::error_code ec_exists;
	if (std::filesystem::exists(pathIniFile, ec_exists))
	{
		const int nSize = GetPrivateProfileString(Section, Key, Default, DataTypeTemp, MAX_STRING, pathIniFile.string());

		if (nSize)
		{
			if (nSize > 2)
			{
				for (int index = 0; index < nSize - 2; index++)
				{
					if (DataTypeTemp[index] == 0)
						DataTypeTemp[index] = '|';
				}
			}

			if ((Section.empty() || Key.empty()) && (nSize < MAX_STRING - 3))
				strcat_s(DataTypeTemp, "||");

			if (bNoParse)
			{
				if (gParserVersion == 2)
				{
					// If we are not supposed to parse and there is a ${
					if (strstr(DataTypeTemp, "${"))
					{
						// Modify Macro String with parameter to wrap Parse Zero
						strcpy_s(DataTypeTemp, ModifyMacroString(DataTypeTemp, true, ModifyMacroMode::Wrap).data());
					}
				}
				else if (strchr(DataTypeTemp, '$'))
				{
					bAllowCommandParse = false;
				}
			}

			Ret.Ptr = &DataTypeTemp[0];
			Ret.Type = pStringType;
			return true;
		}
	}

	if (!Default.empty())
	{
		if (bNoParse)
		{
			if (gParserVersion == 2)
			{
				// If we're set not to parse and there's a ${
				if (Default.find("${") != std::string::npos)
				{

					// Modify Macro String with parameter to wrap Parse Zero
					Default = ModifyMacroString(Default, true, ModifyMacroMode::Wrap);
				}
			}

			// I think the below is actually wrong, since it's checking whatever was stored in
			// DataTypeTemp BEFORE instead of checking what's in Default, but I didn't track it down
			// to see if DataTypeTemp was getting set to default somewhere else and this is how
			// it was originally in parser v1. So I left it.  -- Knightly
			else if (strchr(DataTypeTemp, '$'))
			{
				bAllowCommandParse = false;
			}
		}

		strcpy_s(DataTypeTemp, Default.c_str());
		Ret.Ptr = &DataTypeTemp[0];
		Ret.Type = pStringType;
		return true;
	}

	return false;
}

bool dataDefined(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.Set(FindMQ2DataVariable(szIndex) != 0);
	Ret.Type = pBoolType;
	return true;
}

bool dataSubDefined(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;
	Ret.Set(gMacroBlock && (gMacroSubLookupMap.find(szIndex) != gMacroSubLookupMap.end()));
	Ret.Type = pBoolType;
	return true;
}

bool dataLineOfSight(const char* szIndex, MQTypeVar& Ret)
{
	if (!GetCharInfo() && !GetCharInfo()->pSpawn)
		return false;

	if (szIndex[0])
	{
		float P1[3];
		float P2[3];
		P1[0] = P2[0] = ((SPAWNINFO*)pCharSpawn)->Y;
		P1[1] = P2[1] = ((SPAWNINFO*)pCharSpawn)->X;
		P1[2] = P2[2] = ((SPAWNINFO*)pCharSpawn)->Z;

		char szTemp[MAX_STRING];
		strcpy_s(szTemp, szIndex);

		// TODO:  This code appears in MQ2MathType Distance, possibly clean and combine
		if (char* pColon = strchr(szTemp, ':'))
		{
			*pColon = 0;
			if (char* pComma = strchr(&pColon[1], ','))
			{
				*pComma = 0;
				P2[0] = GetFloatFromString(&pColon[1], P2[0]);
				*pComma = ',';
				if (char* pComma2 = strchr(&pComma[1], ','))
				{
					*pComma2 = 0;
					P2[1] = GetFloatFromString(&pComma[1], P2[1]);
					*pComma2 = ',';
					P2[2] = GetFloatFromString(&pComma2[1], P2[2]);
				}
				else
				{
					P2[1] = GetFloatFromString(&pComma[1], P2[1]);
				}
			}
			else
				P2[0] = GetFloatFromString(&pColon[1], P2[0]);
		}

		if (char* pComma = strchr(szTemp, ','))
		{
			*pComma = 0;
			P1[0] = GetFloatFromString(szTemp, P1[0]);
			*pComma = ',';
			if (char* pComma2 = strchr(&pComma[1], ','))
			{
				*pComma2 = 0;
				P1[1] = GetFloatFromString(&pComma[1], P1[1]);
				*pComma2 = ',';
				P1[2] = GetFloatFromString(&pComma2[1], P1[2]);
			}
			else
			{
				P1[1] = GetFloatFromString(&pComma[1], P1[1]);
			}
		}
		else
			P1[0] = GetFloatFromString(szTemp, P1[0]);

		// FIXME: Can't copy data like this. Refactor to use line of sight calculation
		// without using a SPAWNINFO.
		SPAWNINFO Temp = *GetCharInfo()->pSpawn;
		Temp.Y = P2[0];
		Temp.X = P2[1];
		Temp.Z = P2[2];

		SPAWNINFO Temp2 = *GetCharInfo()->pSpawn;
		Temp2.Y = P1[0];
		Temp2.X = P1[1];
		Temp2.Z = P1[2];

		Ret.Set(LineOfSight(&Temp, &Temp2));
		Ret.Type = pBoolType;
		return true;
	}

	return false;
}

bool dataAlias(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (IsAlias(szIndex))
		{
			Ret.Set(true);
			Ret.Type = pBoolType;
			return true;
		}
	}
	return false;
}

} // namespace mq::datatypes
