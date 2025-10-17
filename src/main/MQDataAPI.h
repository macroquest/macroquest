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

#if !defined(MQ2MAIN_IMPL) && !defined(__clang__)
#error This header should only be included from the MQ2Main project
#endif

#include "mq/base/Common.h"
#include "mq/base/PluginHandle.h"
#include "mq/api/MacroAPI.h"

#include <memory>
#include <unordered_map>

namespace mq {

//============================================================================

class MQDataAPI
{
public:
	MQDataAPI();
	~MQDataAPI();

	void Initialize();

	// Top Level Objects
	bool AddTopLevelObject(const char* szName, MQTopLevelObjectFunction Function, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool RemoveTopLevelObject(const char* szName, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	MQTopLevelObject* FindTopLevelObject(const char* szName) const;

	// DataTypes
	bool AddDataType(MQ2Type& TypeInstance, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool RemoveDataType(MQ2Type& TypeInstance, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	MQ2Type* FindDataType(const char* Name) const;

	// Type Extensions
	bool AddTypeExtension(const char* szName, MQ2Type* extension, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	bool RemoveTypeExtension(const char* szName, MQ2Type* extension, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	//
	bool FindMacroDataMember(MQ2Type* Type, const std::string& member) const;

	enum class EvaluateResult {
		Failure,
		Success,
		NotFound,
	};
	EvaluateResult EvaluateMacroDataMember(MQ2Type* type, MQVarPtr& VarPtr, MQTypeVar& Result,
		const std::string& Member, char* pIndex, bool checkFirst) const;

	bool EvaluateDataExpression(MQTypeVar& Result, const char* pStart, char* pIndex, bool allowFunction = false) const;

	static int EvaluateResultToInt(MQDataAPI::EvaluateResult result)
	{
		switch (result)
		{
		case MQDataAPI::EvaluateResult::NotFound:
			return -1;
		case MQDataAPI::EvaluateResult::Success:
			return 1;
		case MQDataAPI::EvaluateResult::Failure:
		default:
			return 0;
		}
	}

	// TODO: Change to string_view when we have c++20 support for transparent containers
	bool IsReservedName(const std::string& name) const;

	bool ParseMQ2DataPortion(char* szOriginal, MQTypeVar& Result) const;

private:
	void RegisterTopLevelObjects();

	struct TLORec
	{
		std::unique_ptr<MQTopLevelObject> tlo;
		MQPluginHandle owner;
	};
	std::unordered_map<std::string, TLORec> m_tloMap;

	struct TypeRec
	{
		MQ2Type* type;
		MQPluginHandle owner;
	};
	std::unordered_map<std::string, TypeRec> m_dataTypeMap;

	struct ExtensionRec
	{
		MQ2Type* extentionType;
		MQPluginHandle owner;
	};
	std::unordered_map<std::string, std::vector<ExtensionRec>> m_typeExtensions;

	mutable std::recursive_mutex m_mutex;
};

extern MQDataAPI* pDataAPI;

std::string HandleParseParam(std::string_view strOriginal, bool bParseOnce = false);

enum class ModifyMacroMode { Default, Wrap, WrapNoDoubles };

std::string ModifyMacroString(std::string_view strOriginal, bool bParseOnce = false,
	ModifyMacroMode iOperation = ModifyMacroMode::Default);

//============================================================================

bool AddMQ2DataVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default);
bool AddMQ2DataVariableFromData(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, MQTypeVar Default);
MQDataVar** FindVariableScope(const char* Name);
bool DeleteMQ2DataVariable(const char* Name);
void ClearMQ2DataVariables(MQDataVar** ppHead);


} // namespace mq
