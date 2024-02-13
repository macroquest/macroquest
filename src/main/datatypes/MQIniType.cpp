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
#include "MQ2DataTypes.h"

namespace mq::datatypes {

static std::string MQIniFile;
static std::string MQIniFileSection;
static std::string MQIniFileSectionKey;

enum class IniFileSectionKeyTypeMembers
{
	Count,
	Exists,
	KeyAtIndex,
	Value,
	ValueAtIndex,
};

MQIniFileSectionKeyType::MQIniFileSectionKeyType() : MQ2Type("iniadvfilesectionkey")
{
	ScopedTypeMember(IniFileSectionKeyTypeMembers, Count);
	ScopedTypeMember(IniFileSectionKeyTypeMembers, Exists);
	ScopedTypeMember(IniFileSectionKeyTypeMembers, KeyAtIndex);
	ScopedTypeMember(IniFileSectionKeyTypeMembers, Value);
	ScopedTypeMember(IniFileSectionKeyTypeMembers, ValueAtIndex);
}

bool MQIniFileSectionKeyType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	const MQTypeMember* pMember = FindMember(Member);

	if (!pMember)
		return false;

	switch (static_cast<IniFileSectionKeyTypeMembers>(pMember->ID))
	{
	case IniFileSectionKeyTypeMembers::Count:
	{
		Dest.Type = pIntType;
		Dest.Set(0);
		auto keys = GetPrivateProfileKeys<MAX_STRING * 10>(MQIniFileSection, MQIniFile);
		if (MQIniFileSectionKey.empty())
		{
			Dest.Set(keys.size());
		}
		else
		{
			Dest.Set(std::count_if(keys.begin(), keys.end(), [](std::string i) {
				return ci_equals(i, MQIniFileSectionKey);
			}));
		}
		return true;
	}
	case IniFileSectionKeyTypeMembers::Exists:
		Dest.Type = pBoolType;
		Dest.Set(PrivateProfileKeyExists(MQIniFileSection, MQIniFileSectionKey, MQIniFile));
		return true;
	case IniFileSectionKeyTypeMembers::Value:
	{
		Dest.Type = pStringType;
		std::string defaultReturn = "NULL";
		if (Index[0] != '\0')
		{
			defaultReturn = Index;
		}

		if (MQIniFileSectionKey.empty())
		{
			strcpy_s(DataTypeTemp, defaultReturn.c_str());
		}
		else
		{
			strcpy_s(DataTypeTemp, GetPrivateProfileString(MQIniFileSection, MQIniFileSectionKey, defaultReturn, MQIniFile).c_str());
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}
	case IniFileSectionKeyTypeMembers::KeyAtIndex:
	case IniFileSectionKeyTypeMembers::ValueAtIndex:
	{
		if (Index[0] == '\0')
		{
			MacroError("Ini AtIndex requires an Index.");
		}
		else
		{
			const int indexNum = GetIntFromString(Index, 0);
			if (indexNum < 1)
			{
				MacroError("Ini AtIndex requires the index to be a number greater than zero.");
			}
			else
			{
				Dest.Type = pStringType;
				auto keyvalues = GetPrivateProfileKeyValues<MAX_STRING * 10>(MQIniFileSection, MQIniFile);

				if (MQIniFileSectionKey.empty())
				{
					if (static_cast<int>(keyvalues.size()) < indexNum)
					{
						MacroError("Ini AtIndex requested position is larger than the number of keys.");
					}
					else
					{
						if (static_cast<IniFileSectionKeyTypeMembers>(pMember->ID) == IniFileSectionKeyTypeMembers::KeyAtIndex)
						{
							strcpy_s(DataTypeTemp, std::get<0>(keyvalues[indexNum - 1]).c_str());
						}
						else
						{
							strcpy_s(DataTypeTemp, std::get<1>(keyvalues[indexNum - 1]).c_str());
						}
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
				}
				else
				{
					int currentCount = 0;
					for (const auto& keyvalue : keyvalues)
					{
						if (ci_equals(std::get<0>(keyvalue), MQIniFileSectionKey))
						{
							++currentCount;
							if (currentCount == indexNum)
							{
								if (static_cast<IniFileSectionKeyTypeMembers>(pMember->ID) == IniFileSectionKeyTypeMembers::KeyAtIndex)
								{
									strcpy_s(DataTypeTemp, std::get<0>(keyvalue).c_str());
								}
								else
								{
									strcpy_s(DataTypeTemp, std::get<1>(keyvalue).c_str());
								}
								Dest.Ptr = &DataTypeTemp[0];
								return true;
							}
						}
					}
					MacroError("Ini AtIndex requested position is larger than the number of matching keys.");
				}
			}
		}
		break;
	}
	default:
		break;
	}

	return false;
}

bool MQIniFileSectionKeyType::dataIniFileSectionKey(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pIniFileSectionKeyType;
	return true;
}

enum class IniFileSectionTypeMembers
{
	Count,
	Exists,
	Key,
};

MQIniFileSectionType::MQIniFileSectionType() : MQ2Type("iniadvfilesection")
{
	ScopedTypeMember(IniFileSectionTypeMembers, Count);
	ScopedTypeMember(IniFileSectionTypeMembers, Exists);
	ScopedTypeMember(IniFileSectionTypeMembers, Key);
}

bool MQIniFileSectionType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQIniFileSectionKey = "";

	const MQTypeMember* pMember = FindMember(Member);

	if (!pMember)
		return false;

	switch (static_cast<IniFileSectionTypeMembers>(pMember->ID))
	{
	case IniFileSectionTypeMembers::Count:
	{
		Dest.Type = pIntType;
		Dest.Set(0);
		auto sections = GetPrivateProfileSections<MAX_STRING * 10>(MQIniFile);
		if (MQIniFileSection.empty())
		{
			Dest.Set(sections.size());
		}
		else
		{
			Dest.Set(std::count_if(sections.begin(), sections.end(), [](std::string i) {
				return ci_equals(i, MQIniFileSection);
			}));
		}
		return true;
	}
	case IniFileSectionTypeMembers::Exists:
		Dest.Type = pBoolType;
		Dest.Set(PrivateProfileSectionExists(MQIniFileSection, MQIniFile));
		return true;
	case IniFileSectionTypeMembers::Key:
		Dest.Type = pIniFileSectionKeyType;
		MQIniFileSectionKey = Index;
		Dest.Ptr = &MQIniFileSectionKey[0];
		return true;
	default:
		break;
	}

	return false;
}

bool MQIniFileSectionType::dataIniFileSection(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pIniFileSectionType;
	return true;
}

enum class IniFileTypeMembers
{
	Exists,
	Section,
};

MQIniFileType::MQIniFileType() : MQ2Type("iniadvfile")
{
	ScopedTypeMember(IniFileTypeMembers, Exists);
	ScopedTypeMember(IniFileTypeMembers, Section);
}

bool MQIniFileType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQIniFileSection = "";
	const MQTypeMember* pMember = FindMember(Member);

	if (!pMember)
		return false;

	switch (static_cast<IniFileTypeMembers>(pMember->ID))
	{
	case IniFileTypeMembers::Exists:
	{
		std::error_code ec;
		Dest.Type = pBoolType;
		Dest.Set(std::filesystem::exists(MQIniFile, ec));
		return true;
	}
	case IniFileTypeMembers::Section:
		Dest.Type = pIniFileSectionType;
		MQIniFileSection = Index;
		Dest.Ptr = &MQIniFileSection[0];
		return true;
	default:
		break;
	}

	return false;
}

bool MQIniFileType::dataIniFile(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pIniFileType;
	return true;
}

enum class IniTypeMembers
{
	File,
};

MQIniType::MQIniType() : MQ2Type("iniadv")
{
	ScopedTypeMember(IniTypeMembers, File);
}

bool MQIniType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQIniFile = "";

	const MQTypeMember* pMember = FindMember(Member);

	if (!pMember)
		return false;

	switch (static_cast<IniTypeMembers>(pMember->ID))
	{
	case IniTypeMembers::File:
		Dest.Type = pIniFileType;

		if (Index[0] != '\0')
		{
			MQIniFile = GetMacroIni(internal_paths::Config, internal_paths::Macros, Index);
			Dest.Ptr = &MQIniFile[0];
			return true;
		}
		break;
	default:
		break;
	}

	return false;
}

bool MQIniType::dataIni(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex || szIndex[0] == 0)
	{
		Ret.Ptr = nullptr;
		Ret.Type = pIniType;
		return true;
	}

	std::string sTemp = szIndex;

	int count = 0;
	std::map<int, DWORD> argMap;

	// lets see how many commas are in the string
	for (auto i = sTemp.begin(); i != sTemp.end(); i++)
	{
		if (i[0] == ',' && i + 1 != sTemp.end() && i[1] != ' ')
		{
			argMap[count] = static_cast<DWORD>(std::distance(sTemp.begin(), i));
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
					const std::string Parse = sTemp.substr(argMap[3] + 1);

					if (ci_equals(Parse, "noparse"))
						bNoParse = true;
				}
			}
		}
	}

	if (IniFile.empty())
		return false;

	const std::filesystem::path pathIniFile = GetMacroIni(internal_paths::Config, internal_paths::Macros, IniFile);

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

} // namespace mq::datatypes
