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

#pragma once

#include "LuaCommon.h"
#include <mq/Plugin.h>

namespace mq {
	struct MQTypeVar;
	struct MQDataItem;
}

namespace mq::datatypes {
	class MQ2Type;
}

namespace mq::lua {
	std::tuple<const std::string&, const std::string&, int, bool> GetArgInfo(sol::function func);
}

namespace mq::lua::bindings {

//----------------------------------------------------------------------------

class lua_MQCommand
{
public:
	lua_MQCommand(std::string_view command);

	void operator()(sol::variadic_args va, sol::this_state s);

	std::string command;
};

//----------------------------------------------------------------------------

class lua_MQDataItem;

class lua_MQTypeVar
{
	friend class lua_MQDataItem;

public:
	lua_MQTypeVar(const std::string& str);

	/**
	 * \brief wraps an MQ type var in a lua implementation
	 * \param self the MQ type var data source to be represented in lua
	 */
	lua_MQTypeVar(const MQTypeVar& self);

	bool operator==(const lua_MQTypeVar& right) const;
	bool EqualData(const lua_MQDataItem& right) const;
	bool EqualNil(const sol::lua_nil_t&) const;
	MQTypeVar EvaluateMember(const char* index = nullptr) const;
	static std::string ToString(const lua_MQTypeVar& obj);
	sol::object Call(std::string index, sol::this_state L) const;
	sol::object CallInt(int index, sol::this_state L) const;
	sol::object CallVA(sol::this_state L, sol::variadic_args args) const;
	sol::object CallEmpty(sol::this_state L) const;
	sol::object Get(sol::stack_object key, sol::this_state L) const;
	datatypes::MQ2Type* GetType() const;

private:
	std::unique_ptr<MQTypeVar> m_self;
	std::string m_member;
};

//----------------------------------------------------------------------------

class lua_MQDataItem
{
public:
	lua_MQDataItem() = default;

	// this will allow users an alternate way to Get data items
	lua_MQDataItem(const std::string& str);
	lua_MQDataItem(const MQDataItem* const self);

	lua_MQTypeVar EvaluateSelf() const;
	bool operator==(const lua_MQDataItem& right) const;
	bool EqualVar(const lua_MQTypeVar& right) const;
	bool EqualNil(const sol::lua_nil_t&) const;

	static std::string ToString(const lua_MQDataItem& data);

	sol::object Call(const std::string& index, sol::this_state L) const;
	sol::object CallInt(int index, sol::this_state L) const;
	sol::object CallVA(sol::this_state L, sol::variadic_args args) const;
	sol::object CallEmpty(sol::this_state L) const;
	sol::object Get(sol::stack_object key, sol::this_state L) const;

	datatypes::MQ2Type* GetType() const;

private:
	const MQDataItem* const self = nullptr;
};

//----------------------------------------------------------------------------

class LuaAbstractDataType;

// A custom DataType implementation that serves as a proxy between the Macro
// interface and the lua bindings.
class LuaProxyType : public MQ2Type
{
public:
	LuaProxyType(const std::string& typeName, LuaAbstractDataType* luaType);
	virtual ~LuaProxyType();

	virtual bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) override;
	virtual bool FromString(MQVarPtr& VarPTr, const char* Source) override;

	virtual void InitVariable(MQVarPtr& VarPtr) override {}
	virtual void FreeVariable(MQVarPtr& VarPtr) override {}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	virtual bool ToString(MQVarPtr VarPtr, char* Destination) override;

	void RegisterMembers();

private:
	LuaAbstractDataType* m_luaType;
};

//----------------------------------------------------------------------------

class LuaTableType : public MQ2Type
{
public:
	LuaTableType();

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override;
	bool ToString(MQVarPtr VarPtr, char* Destination) override;
};

//----------------------------------------------------------------------------

} // namespace mq::lua::bindings
