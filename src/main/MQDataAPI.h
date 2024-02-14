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

#include "mq/base/Common.h"
#include "mq/api/MacroAPI.h"

#include <memory>
#include <unordered_map>

namespace mq {

//============================================================================

struct MQPlugin;

struct MQTopLevelObject
{
	std::string Name;
	MQTopLevelObjectFunction Function;
	MQPlugin* Owner;
};
using MQDataItem DEPRECATE("Use MQTopLevelObject instead of MQDataItem") = MQTopLevelObject;

struct MQDataVar
{
	char szName[MAX_STRING];
	MQTypeVar Var;

	MQDataVar* pNext;
	MQDataVar* pPrev;
	MQDataVar** ppHead;
};

//----------------------------------------------------------------------------

class MQDataAPI
{
public:
	MQDataAPI();
	~MQDataAPI();

	void Initialize();

	// Top Level Objects
	bool AddTopLevelObject(const char* szName, MQTopLevelObjectFunction Function, MQPlugin* Owner = nullptr);
	bool RemoveTopLevelObject(const char* szName, MQPlugin* Owner = nullptr);
	MQTopLevelObject* FindTopLevelObject(const char* szName) const;

	// DataTypes
	bool AddDataType(MQ2Type& TypeInstance, MQPlugin* Owner = nullptr);
	bool RemoveDataType(MQ2Type& TypeInstance, MQPlugin* Owner = nullptr);
	MQ2Type* FindDataType(const char* Name) const;

	// Type Extensions
	bool AddTypeExtension(const char* szName, MQ2Type* extension, MQPlugin* Owner = nullptr);
	bool RemoveTypeExtension(const char* szName, MQ2Type* extension, MQPlugin* Owner = nullptr);

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

	static inline int EvaluateResultToInt(MQDataAPI::EvaluateResult result)
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

private:
	std::unordered_map<std::string, std::unique_ptr<MQTopLevelObject>> m_tloMap;
	std::unordered_map<std::string, MQ2Type*> m_dataTypeMap;
	std::unordered_map<std::string, std::vector<MQ2Type*>> m_typeExtensions;
	mutable std::recursive_mutex m_mutex;
};

extern MQDataAPI* pDataAPI;

std::string HandleParseParam(std::string_view strOriginal, bool bParseOnce = false);

enum class ModifyMacroMode { Default, Wrap, WrapNoDoubles };

std::string ModifyMacroString(std::string_view strOriginal, bool bParseOnce = false,
	ModifyMacroMode iOperation = ModifyMacroMode::Default);

//============================================================================

// MQ2Hud is using this...
MQLIB_VAR MQDataVar* FindMQ2DataVariable(const char* Name);

bool AddMQ2DataVariable(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, const char* Default);
bool AddMQ2DataVariableFromData(const char* Name, const char* Index, MQ2Type* pType, MQDataVar** ppHead, MQTypeVar Default);
MQDataVar** FindVariableScope(const char* Name);
bool DeleteMQ2DataVariable(const char* Name);
void ClearMQ2DataVariables(MQDataVar** ppHead);


} // namespace mq
