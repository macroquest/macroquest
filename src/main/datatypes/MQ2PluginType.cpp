/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

enum class PluginMembers
{
	Name = 1,
	Version,
	IsLoaded,
};

MQ2PluginType::MQ2PluginType() : MQ2Type("plugin")
{
	ScopedTypeMember(PluginMembers, Name);
	ScopedTypeMember(PluginMembers, Version);
	ScopedTypeMember(PluginMembers, IsLoaded);
}

bool MQ2PluginType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = MQ2PluginType::FindMember(Member);
	if (!pMember)
		return false;

	MQPlugin* pPlugin = static_cast<MQPlugin*>(VarPtr.Ptr);
	if (!pPlugin && static_cast<PluginMembers>(pMember->ID) != PluginMembers::IsLoaded)
		return false;

	switch (static_cast<PluginMembers>(pMember->ID))
	{
	case PluginMembers::Name:
		Dest.Type = pStringType;
		Dest.Ptr = pPlugin->szFilename;
		return true;

	case PluginMembers::Version:
		Dest.Type = pFloatType;
		Dest.Set(pPlugin->fpVersion);
		return true;

	case PluginMembers::IsLoaded:
		Dest.Type = pBoolType;
		Dest.Set(pPlugin != nullptr);
		return true;

	default: break;
	}

	return false;
}

bool MQ2PluginType::dataPlugin(const char* szIndex, MQTypeVar& Ret)
{
	if (!szIndex[0])
		return false;

	if (IsNumber(szIndex))
	{
		int index = GetIntFromString(szIndex, 0) - 1;
		if (index < 0)
			index = 0;

		MQPlugin* pPlugin = pPlugins;
		while (index)
		{
			pPlugin = pPlugin->pNext;
			if (!pPlugin)
				return false;
			index--;
		}

		Ret.Ptr = pPlugin;
		Ret.Type = pPluginType;
		return true;
	}

	// name
	MQPlugin* pPlugin = pPlugins;
	while (pPlugin)
	{
		if (!_stricmp(pPlugin->szFilename, szIndex))
		{
			Ret.Ptr = pPlugin;
			Ret.Type = pPluginType;
			return true;
		}

		pPlugin = pPlugin->pNext;
	}

	// Let GetMember handle this since it was a name search that wasn't found
	Ret.Ptr = nullptr;
	Ret.Type = pPluginType;
	return true;
}

bool MQ2PluginType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (VarPtr.Ptr)
	{
		strcpy_s(Destination, MAX_STRING, ((MQPlugin*)VarPtr.Ptr)->szFilename);
		return true;
	}
	return false;
}

bool MQ2PluginType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pPluginType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

} // namespace mq::datatypes
