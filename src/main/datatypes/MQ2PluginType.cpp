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
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2PluginType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQPlugin* pPlugin = reinterpret_cast<MQPlugin*>(VarPtr.Ptr);
	if (!pPlugin)
		return false;

	MQTypeMember* pMember = MQ2PluginType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<PluginMembers>(pMember->ID))
	{
	case Name:
		Dest.Ptr = pPlugin->szFilename;
		Dest.Type = pStringType;
		return true;

	case Version:
		Dest.Float = pPlugin->fpVersion;
		Dest.Type = pFloatType;
		return true;

	default: break;
	}

	return false;
}
