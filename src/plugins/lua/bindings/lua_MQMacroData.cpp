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
#include "lua_MQBindings.h"

#include "LuaThread.h"

#include <mq/Plugin.h>
#include <mq/api/MacroAPI.h>

namespace mq::lua {

std::tuple<const std::string&, const std::string&, int, bool> GetArgInfo(sol::function func)
{
	sol::state_view s = func.lua_state();

	return s["__command_arginfo"](func);
}

} // namespace mq::lua

namespace mq::lua::bindings {

//============================================================================

static bool ConvertCallbackResultToMacroType(sol::function_result& result, MQTypeVar& Dest);

class LuaTableType;
static LuaTableType* s_luaTableType = nullptr;

class LuaProxyType;
std::vector<LuaProxyType*> s_proxyTypes;

static sol::object CloneObject(sol::object object, lua_State* state)
{
	// Try our best to copy things into another state. We can't generically handle everything,
	// especially things like functions. But if we have the same state, just return the object
	// back, which will allow us to call functions from outside our state, as long as we don't
	// attempt to copy the object into a local state first.
	if (object.lua_state() == state)
		return object;

	sol::type type = object.get_type();
	if (type == sol::type::string)
	{
		auto val = object.as<std::string>();
		return sol::make_object(state, val);
	}

	if (type == sol::type::number)
	{
		auto val = object.as<double>();
		return sol::make_object(state, val);
	}

	if (type == sol::type::boolean)
	{
		auto val = object.as<bool>();
		return sol::make_object(state, val);
	}

	if (type == sol::type::table)
	{
		auto val = object.as<sol::table>();
		auto new_table = sol::state_view(state).create_table();
		for (auto& [k, v] : val)
		{
			new_table.set(CloneObject(k, state), CloneObject(v, state));
		}

		return new_table;
	}

	// any type we don't support will automatically become nil (specifically thread, userdata, and lightuserdata)
	// userdata could potentially be copyable if we require that there is a :copy() function on it, but that 
	// can be added later if it is actually important. 
	return sol::make_object(state, sol::lua_nil);
}

static sol::table FillExtent(const std::shared_ptr<datatypes::CDataArray>& arr, int extent, int curr_index, sol::state_view s)
{
	int localSize = arr->GetExtents(extent);
	sol::table table = s.create_table(localSize);

	if (extent + 1 == arr->GetNumExtents())
	{
		// this is the final extent, we need to build values
		for (int index = 0; index < localSize; ++index)
		{
			MQTypeVar var;
			var.Type = arr->GetType();
			var.SetVarPtr(arr->GetData((curr_index * localSize) + index));

			table.add(lua_MQTypeVar(var));
		}
	}
	else
	{
		for (int index = 0; index < localSize; ++index)
			table.add(FillExtent(arr, extent + 1, index, s));
	}

	return table;
}

static sol::object ConvertTypeVarToLua(sol::this_state L, const MQTypeVar& result)
{
	if (result.Type == nullptr)
		return sol::object(L, sol::in_place, sol::lua_nil);

	if (result.Type == mq::datatypes::pArrayType)
		return sol::object(L, sol::in_place, FillExtent(result.Get<datatypes::CDataArray>(), 0, 0, sol::state_view(L)));
	if (result.Type == mq::datatypes::pBoolType)
		return sol::object(L, sol::in_place, result.Get<bool>());
	if (result.Type == mq::datatypes::pIntType)
		return sol::object(L, sol::in_place, result.Get<int>());
	if (result.Type == mq::datatypes::pInt64Type)
		return sol::object(L, sol::in_place, result.Get<int64_t>());
	if (result.Type == mq::datatypes::pByteType)
		return sol::object(L, sol::in_place, result.Get<uint8_t>());
	if (result.Type == mq::datatypes::pFloatType)
		return sol::object(L, sol::in_place, result.Get<float>());
	if (result.Type == mq::datatypes::pDoubleType)
		return sol::object(L, sol::in_place, result.Get<double>());
	if (result.Type == mq::datatypes::pStringType)
		return sol::object(L, sol::in_place, (const char*)result.Ptr);
	if (result.Type == mq::datatypes::pTimeStampType)
		return sol::object(L, sol::in_place, result.Get<int64_t>());

	// Transfer a table type over to the new lua state
	if (result.Type == s_luaTableType)
	{
		if (auto obj = result.Get<sol::object>())
			return CloneObject(*obj, L);

		return sol::nil;
	}

	// by default run it through the tostring conversion because we are assuming calling with empty parens means
	// to actualize the data in the native lua space
	char buf[MAX_STRING] = { 0 };
	if (result.Type->ToString(result.GetVarPtr(), buf))
		return sol::object(L, sol::in_place, buf);

	return sol::object(L, sol::in_place, sol::lua_nil);
}

template <typename T>
bool ConvertToMacroType(sol::object object, MQVarPtr& Dest)
{
	// This will return false if the value doesn't come back as the correct type because we want
	// to be able to assume that the user, who specified the type, correctly knows what they 
	// wanted to get from the return value
	auto maybe = object.as<std::optional<T>>();
	if (maybe)
	{
		Dest.Set(*maybe);
		return true;
	}

	return false;
}

// Convert from lua to macro type when we know the target type
static bool ConvertLuaToMacroType(sol::object object, MQTypeVar& Dest)
{
	if (Dest.Type == nullptr)
		return false;

	if (Dest.Type == mq::datatypes::pBoolType)
		return ConvertToMacroType<bool>(object, Dest);
	if (Dest.Type == mq::datatypes::pIntType)
		return ConvertToMacroType<int>(object, Dest);
	if (Dest.Type == mq::datatypes::pInt64Type)
		return ConvertToMacroType<int64_t>(object, Dest);
	if (Dest.Type == mq::datatypes::pByteType)
		return ConvertToMacroType<uint8_t>(object, Dest);
	if (Dest.Type == mq::datatypes::pFloatType)
		return ConvertToMacroType<float>(object, Dest);
	if (Dest.Type == mq::datatypes::pDoubleType)
		return ConvertToMacroType<double>(object, Dest);
	if (Dest.Type == mq::datatypes::pDoubleType)
		return ConvertToMacroType<double>(object, Dest);
	if (Dest.Type == mq::datatypes::pTimeStampType)
		return ConvertToMacroType<int64_t>(object, Dest);

	// we want to specifically specialize the lua generic type because we need to copy from
	// another lua state in general.
	if (sorted_contains(s_proxyTypes, Dest.Type))
	{
		Dest.Set(object);
		return true;
	}

	if (Dest.Type == s_luaTableType)
	{
		if (object.is<sol::table>())
		{
			Dest.Set(object);
			return true;
		}

		LuaError("No conversion to type \"%s\" available.", Dest.Type->GetName());
		return false;
	}

	if (Dest.Type == mq::datatypes::pStringType)
	{
		if (auto maybe = object.as<std::optional<const char*>>())
		{
			strcpy_s(&DataTypeTemp[0], DataTypeTemp.size(), *maybe);
			Dest.Ptr = DataTypeTemp;
		}
		else
		{
			// Serialize whatever we were given into a string.
			auto pp = sol::stack::push_pop(object);
			auto stack_val = sol::stack_object(object.lua_state(), -1);
			const char* val_str = luaL_tolstring(stack_val.lua_state(), stack_val.stack_index(), nullptr);
			lua_pop(stack_val.lua_state(), 1);

			strcpy_s(&DataTypeTemp[0], DataTypeTemp.size(), val_str);
			Dest.Ptr = DataTypeTemp;
		}
		return true;
	}

	LuaError("No conversion to type \"%s\" available.", Dest.Type->GetName());
	return false;
}

// Convert from lua to macro when we don't know the target type
static bool CreateMacroTypeFromLua(sol::object object, MQTypeVar& Dest)
{
	if (object == sol::lua_nil)
		return false;

	switch (object.get_type())
	{
	case sol::type::none:
	case sol::type::lua_nil:
		return false;

	case sol::type::string:
		Dest.Type = mq::datatypes::pStringType;
		strcpy_s(&DataTypeTemp[0], DataTypeTemp.size(), object.as<const char*>());
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case sol::type::number:
		Dest.Type = mq::datatypes::pDoubleType; // numbers in lua are double.
		Dest.Double = object.as<lua_Number>();
		return true;

	case sol::type::boolean:
		Dest.Type = mq::datatypes::pBoolType;
		Dest.Set(object.as<bool>());
		return true;

	case sol::type::table:
		Dest.Type = s_luaTableType;
		Dest.Set<sol::object>(object);
		return true;
	}

	return false;
}

//============================================================================

#pragma region Macro Data Bindings

lua_MQTypeVar::lua_MQTypeVar(const std::string& str)
{
	auto* const type = FindMQ2DataType(str.c_str());
	if (type != nullptr)
	{
		m_self.Type = type;
	}
}

lua_MQTypeVar::lua_MQTypeVar(const MQTypeVar& self)
	: m_self(self)
{
}

bool lua_MQTypeVar::operator==(const lua_MQTypeVar& right) const
{
	return EvaluateMember() == right.EvaluateMember();
}

bool lua_MQTypeVar::EqualNil(const sol::lua_nil_t&) const
{
	if (m_self.Type == nullptr)
		return true;

	return EvaluateMember().Type == nullptr;
}

MQTypeVar lua_MQTypeVar::EvaluateMember(const char* index) const
{
	if (m_self.Type == nullptr || m_member.empty())
		return m_self;

	// the ternary in index is because datatypes are all over the place on whether or not they can
	// accept null pointers. They all seem to agree that an empty string is the same thing, though.
	char buffer[1] = "";
	MQTypeVar var;

	if (EvaluateMacroDataMember(m_self.Type, m_self.GetVarPtr(), var, m_member.c_str(), const_cast<char*>(index ? index : buffer)) == 1)
		return var;

	// can't guarantee result didn't Get modified, but we want to return nil if GetMember was false
	return MQTypeVar();
}

MQ2Type* lua_MQTypeVar::GetType() const
{
	return EvaluateMember().Type;
}

std::string lua_MQTypeVar::ToString(const lua_MQTypeVar& obj)
{
	MQTypeVar var = obj.EvaluateMember();

	if (var.Type != nullptr)
	{
		char buf[MAX_STRING] = { 0 };
		if (var.Type->ToString(var, buf))
			return std::string(buf);
	}

	return "NULL";
}

sol::object lua_MQTypeVar::Call(std::string index, sol::this_state L) const
{
	return sol::object(L, sol::in_place, lua_MQTypeVar(EvaluateMember(index.c_str())));
}

sol::object lua_MQTypeVar::CallInt(int index, sol::this_state L) const
{
	return Call(std::to_string(index), L);
}

sol::object lua_MQTypeVar::CallVA(sol::this_state L, sol::variadic_args args) const
{
	return Call(lua_join(L, ",", args), L);
}

sol::object lua_MQTypeVar::CallEmpty(sol::this_state L) const
{
	MQTypeVar result = EvaluateMember();

	return ConvertTypeVarToLua(L, result);
}

sol::object lua_MQTypeVar::Get(sol::stack_object key, sol::this_state L) const
{
	lua_MQTypeVar var = EvaluateMember();

	if (var.m_self.Type && var.m_self.Type == datatypes::pArrayType)
	{
		auto arr = var.m_self.Get<datatypes::CDataArray>();
		if (auto maybe_index = key.as<std::optional<int>>())
		{
			// we have an integer -- let's just assume single extent for now
			// TODO: will need to keep track of extents to allow for access like this: arr[2][1]
			// would rather return an array with a subset, but that would require slicing and copying the underlying array data
			var.m_member = "";
			var.m_self.Type = arr->GetType();
			var.m_self.SetVarPtr(arr->GetData(*maybe_index));
		}
		else if (auto maybe_index = key.as<std::optional<std::string_view>>())
		{
			// we have a string, so we can use the array's internal string index parsing here
			if (!arr->GetElement(*maybe_index, var.m_self))
			{
				return sol::object(L, sol::in_place, sol::lua_nil);
			}

			var.m_member = "";
		}
	}
	else if (auto maybe_key = key.as<std::optional<std::string_view>>())
	{
		// the nominal case is that the index is the key to the type member
		var.m_member = *maybe_key;

		// make sure that the macro data member even exists if we have the type info
		if (var.m_self.Type && !FindMacroDataMember(var.m_self.Type, var.m_member))
		{
			return sol::object(L, sol::in_place, sol::lua_nil);
		}
	}

	return sol::object(L, sol::in_place, std::move(var));
}

//----------------------------------------------------------------------------

lua_MQTopLevelObject::lua_MQTopLevelObject(sol::this_state L, const std::string& str)
	: self(FindTopLevelObject(str.c_str()))
{
	if (self)
	{
		if (auto thread_ptr = LuaThread::get_from(L))
		{
			thread_ptr->AssociateTopLevelObject(self);
		}
	}
}

lua_MQTopLevelObject::lua_MQTopLevelObject(sol::this_state L, const MQTopLevelObject* const self)
	: self(self)
{
	if (self && self->Owner != nullptr)
	{
		if (auto thread_ptr = LuaThread::get_from(L))
		{
			thread_ptr->AssociateTopLevelObject(self);
		}
	}
}

lua_MQTypeVar lua_MQTopLevelObject::EvaluateSelf() const
{
	MQTypeVar result;
	if (self != nullptr)
		self->Function("", result);

	return lua_MQTypeVar(result);
}

bool lua_MQTopLevelObject::operator==(const lua_MQTopLevelObject& right) const
{
	return EvaluateSelf() == right.EvaluateSelf();
}

bool lua_MQTopLevelObject::EqualVar(const lua_MQTypeVar& right) const
{
	return EvaluateSelf() == right;
}

bool lua_MQTopLevelObject::EqualNil(const sol::lua_nil_t&) const
{
	return EvaluateSelf().m_self.Type == nullptr;
}

std::string lua_MQTopLevelObject::ToString(const lua_MQTopLevelObject& data)
{
	return lua_MQTypeVar::ToString(data.EvaluateSelf());
}

MQ2Type* lua_MQTopLevelObject::GetType() const
{
	return EvaluateSelf().m_self.Type;
}

sol::object lua_MQTopLevelObject::Call(const std::string& index, sol::this_state L) const
{
	MQTypeVar result;
	if (self != nullptr && self->Function(index.c_str(), result))
		return sol::object(L, sol::in_place, lua_MQTypeVar(result));

	return sol::object(L, sol::in_place, lua_MQTypeVar(MQTypeVar()));
}

sol::object lua_MQTopLevelObject::CallInt(int index, sol::this_state L) const
{
	return Call(std::to_string(index), L);
}

sol::object lua_MQTopLevelObject::CallVA(sol::this_state L, sol::variadic_args args) const
{
	return Call(lua_join(L, ",", args), L);
}

sol::object lua_MQTopLevelObject::CallEmpty(sol::this_state L) const
{
	MQTypeVar result;
	if (self != nullptr && self->Function("", result))
		return lua_MQTypeVar(result).CallEmpty(L);

	return sol::object(L, sol::in_place, sol::lua_nil);
}

sol::object lua_MQTopLevelObject::Get(sol::stack_object key, sol::this_state L) const
{
	MQTypeVar result;
	if (self != nullptr && self->Function("", result))
		return lua_MQTypeVar(result).Get(key, L);

	return sol::object(L, sol::in_place, lua_MQTypeVar(MQTypeVar()));
}

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQTopLevelObject>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQTopLevelObject>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQTopLevelObject sol_lua_get(sol::types<lua_MQTopLevelObject>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQTopLevelObject>(L, index))
	{
		lua_MQTopLevelObject& data = sol::stack::get_usertype<lua_MQTopLevelObject>(L, index, tracking);
		return data;
	}

	return lua_MQTopLevelObject();
}

bool lua_MQTypeVar::EqualData(const lua_MQTopLevelObject& right) const
{
	return *this == right.EvaluateSelf();
}

//----------------------------------------------------------------------------

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQTypeVar>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQTypeVar>(L, index) &&
		!sol::stack::check_usertype<lua_MQTopLevelObject>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQTypeVar sol_lua_get(sol::types<lua_MQTypeVar>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQTypeVar>(L, index))
	{
		lua_MQTypeVar& var = sol::stack::get_usertype<lua_MQTypeVar>(L, index, tracking);
		return lua_MQTypeVar(var.EvaluateMember());
	}

	if (sol::stack::check_usertype<lua_MQTopLevelObject>(L, index))
	{
		lua_MQTopLevelObject& data = sol::stack::get_usertype<lua_MQTopLevelObject>(L, index, tracking);
		return data.EvaluateSelf();
	}

	return lua_MQTypeVar(MQTypeVar()); // this will eventually evaluate to a nil, but we need it to stay in userdata until actual evaluation
}

struct lua_MQTLO
{
	sol::object Get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			MQTopLevelObject* result = FindMQ2Data(maybe_key->c_str());
			if (result != nullptr)
				return sol::object(L, sol::in_place, lua_MQTopLevelObject(L, result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

std::string to_string(const lua_MQTopLevelObject& item)
{
	return lua_MQTopLevelObject::ToString(item);
}

std::string to_string(const lua_MQTypeVar& item)
{
	return lua_MQTypeVar::ToString(item);
}

std::string to_string(const lua_MQTLO& item)
{
	return "TLO";
}

const char* mq_gettype_MQTopLevelObject(lua_MQTopLevelObject* item)
{
	MQ2Type* type = item ? item->GetType() : nullptr;
	if (!type)
		return nullptr;

	return type->GetName();
}

const char* mq_gettype_MQTypeVar(lua_MQTypeVar* item)
{
	MQ2Type* type = item ? item->GetType() : nullptr;
	if (!type)
		return nullptr;

	return type->GetName();
}

static sol::table lua_getDataTypes(sol::this_state s)
{
	sol::state_view lua(s);
	sol::table result = lua.create_table();

	const auto dataTypes = GetDataTypeNames();
	int index = 1;
	for (const auto& name : dataTypes)
	{
		result[index++] = name;
	}

	return result;
}

#pragma endregion

//============================================================================

#pragma region Lua DataTypes

class LuaAbstractDataType
{
public:
	friend class LuaProxyType;

	LuaAbstractDataType(const std::string& typeName, sol::table parameters, sol::this_state s)
		: m_typeName(typeName)
		, m_state(s)
	{
		if (m_typeName.empty())
		{
			luaL_error(s, "DataType must have a name.");
		}

		// Initialize members
		auto members = parameters.get<std::optional<sol::table>>("Members");
		if (members)
		{
			InitializeMembers(*members, false);
		}

		// Initialize methods
		auto methods = parameters.get<std::optional<sol::table>>("Methods");
		if (methods)
		{
			InitializeMembers(*methods, true);
		}

		// Initialize ToString
		auto toString = parameters.get<sol::function>("ToString");
		if (toString)
		{
			m_toString = toString;
		}
		else
		{
			auto state = sol::state_view{ s };
			m_toString = state.script(R"(
				return function()
					return 'NULL'
				end
			)");
		}

		// Create a thread for our data type so that it always has its own stack.
		auto thread_ptr = LuaThread::get_from(s);
		m_thread = sol::thread::create(thread_ptr->GetLuaThread().state());

		// If we made it this far, we can construct the proxy type.
		m_proxyType = std::make_unique<LuaProxyType>(m_typeName, this);

		// Register methods and members with the type.
		m_proxyType->RegisterMembers();
	}

	~LuaAbstractDataType()
	{
	}

	static std::shared_ptr<LuaAbstractDataType> MakeLuaAbstractDataType(
		const std::string& typeName,
		sol::table parameters,
		sol::this_state s)
	{
		return std::make_shared<LuaAbstractDataType>(typeName, parameters, s);
	}

	static void RegisterType(sol::table& mq)
	{
		mq.new_usertype<LuaAbstractDataType>("DataType",
			sol::factories(MakeLuaAbstractDataType),
			"TypeName", sol::readonly(&LuaAbstractDataType::m_typeName),
			"ToString", &LuaAbstractDataType::m_toString,
			"FromData", &LuaAbstractDataType::m_fromData,
			"FromString", &LuaAbstractDataType::m_fromString
		);
	}

	LuaProxyType* GetType() const { return m_proxyType.get(); }

private:
	struct MemberRecord {
		sol::function func;
		bool          method;

		MemberRecord(sol::function func, bool method)
			: func(std::move(func)), method(method) {}
	};
	using LuaMemberMap = std::unordered_map<std::string, MemberRecord>;

	void InitializeMembers(sol::table table, bool method)
	{
		for (const auto& [key, value] : table)
		{
			auto name = key.as<std::string>();
			auto func = value.as<sol::function>();

			m_members.emplace(
				std::piecewise_construct,
				std::forward_as_tuple(name),
				std::forward_as_tuple(func, method));
		}
	}

private:
	std::string m_typeName;
	sol::state_view m_state;
	sol::function m_toString;
	sol::function m_fromData;
	sol::function m_fromString;

	LuaMemberMap m_members;
	sol::thread m_thread;

	std::unique_ptr<LuaProxyType> m_proxyType;
};

//----------------------------------------------------------------------------

LuaProxyType::LuaProxyType(const std::string& typeName, LuaAbstractDataType* luaType)
	: MQ2Type(typeName)
	, m_luaType(luaType)
{
	insert_unique_sorted(s_proxyTypes, this);
}

LuaProxyType::~LuaProxyType()
{
	remove_sorted(s_proxyTypes, this);
}

bool LuaProxyType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	// TODO: Implement me
	return false;
}

bool LuaProxyType::FromString(MQVarPtr& VarPTr, const char* Source)
{
	// TODO: Implement me
	return false;
}

bool LuaProxyType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto iter = m_luaType->m_members.find(Member);
	if (iter != m_luaType->m_members.end())
	{
		// Lua datatypes always store their data as a sol::object
		auto data = VarPtr.Get<sol::object>();
		if (data)
		{
			// Execute the function in the context of the state that owns the type.
			const LuaAbstractDataType::MemberRecord& record = iter->second;
			auto& thread = m_luaType->m_thread;

			if (auto thread_ptr = LuaThread::get_from(m_luaType->m_state))
			{
				ScopedYieldDisabler disabler(thread_ptr);
				auto callable = sol::function(thread.state(), record.func);

				sol::function_result result = callable(Index, *data);
				if (!result.valid())
				{
					LuaError("A lua error occurred while evaluating data member %s.%s, Index=\"%s\"\n%s",
						m_typeName.c_str(), Member, Index,
						sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
					result.abandon();

					return false;
				}

				if (record.method)
				{
					return true;
				}

				return ConvertCallbackResultToMacroType(result, Dest);
			}
		}
	}

	return false;
}

bool LuaProxyType::ToString(MQVarPtr VarPtr, char* Destination)
{
	// Lua datatypes always store their data as a sol::object
	auto data = VarPtr.Get<sol::object>();
	if (data)
	{
		auto& thread = m_luaType->m_thread;

		if (auto thread_ptr = LuaThread::get_from(m_luaType->m_state))
		{
			ScopedYieldDisabler disabler(thread_ptr);
			auto callable = sol::function(thread.state(), m_luaType->m_toString);

			sol::function_result result = callable(*data);
			if (!result.valid())
			{
				LuaError("A lua error occurred while converting datatype \"%s\" to string\n%s",
					m_typeName.c_str(),
					sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
				result.abandon();

				return false;
			}

			auto value = result.get<std::optional<const char*>>();
			if (value.has_value())
			{
				strcpy_s(Destination, MAX_STRING, *value);
				return true;
			}

		}
	}
	return false;
}

void LuaProxyType::RegisterMembers()
{
	int id = 0;

	for (const auto& [name, value] : m_luaType->m_members)
	{
		if (value.method)
			AddMethod(id++, name.c_str());
		else
			AddMember(id++, name.c_str());
	}
}

//============================================================================

static bool ConvertCallbackResultToMacroType(sol::function_result& result, MQTypeVar& Dest)
{
	if (result.valid() && result.return_count() > 1)
	{
		auto [nameValue, typeValue] = result.get<std::tuple<sol::object, sol::object>>();
		if (nameValue != sol::lua_nil && typeValue != sol::lua_nil)
		{
			const auto& typeName = nameValue.as<std::optional<const char*>>();
			if (typeName.has_value())
			{
				if (MQ2Type* type = FindMQ2DataType(*typeName))
				{
					Dest.Type = type;
					return ConvertLuaToMacroType(typeValue, Dest);
				}
			}
			else
			{
				const auto& typeObject = nameValue.as<std::optional<LuaAbstractDataType*>>();
				if (typeObject)
				{
					Dest.Type = (*typeObject)->GetType();
					return ConvertLuaToMacroType(typeValue, Dest);
				}
			}
		}
	}

	return false;
}

bool lua_AddTopLevelObject(const char* name, sol::function func, sol::this_state s)
{
	auto [_1, _2, numArgs, varargs] = GetArgInfo(func);

	if (!name || name[0] == 0)
	{
		luaL_error(s, "Invalid name passed to AddTopLevelObject");
	}
	else if (FindMQ2Data(name) != nullptr)
	{
		LuaError("Cannot create TLO %s, already exists.", name);
	}
	else if (varargs)
	{
		luaL_error(s, "Invalid TLO %s: TLOs do not support variadic arguments.",
			name);
	}
	else if (numArgs != 1)
	{
		luaL_error(s, "Invalid number of arguments (%d)", numArgs);
	}
	else
	{
		if (auto thread_ptr = LuaThread::get_from(s))
		{
			// Each invocation of this TLO will reuse the same lua stack created for it, although We
			// could technically use one thread stack for all TLOs/datatypes for a given lua context.
			auto thread = sol::thread::create(thread_ptr->GetLuaThread().state());

			auto tloFunction =
				[name = std::string(name), func, thread_ptr_ = std::weak_ptr(thread_ptr),
				thread = std::move(thread)](const char* Index, MQTypeVar& Dest)
			{
				if (auto thread_ptr = thread_ptr_.lock())
				{
					ScopedYieldDisabler disabler(thread_ptr);
					auto callable = sol::function(thread.state(), func);

					sol::function_result result = callable(Index);
					if (!result.valid())
					{
						LuaError("A lua error occurred while evaluating TLO: %s, Index=\"%s\"\n%s",
							name.c_str(), Index,
							sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
						result.abandon();

						return false;
					}

					return ConvertCallbackResultToMacroType(result, Dest);
				}

				return false;
			};

			return thread_ptr->AddTopLevelObject(name, tloFunction);
		}
	}
	return false;
}

bool lua_RemoveTopLevelObject(const char* name, sol::this_state s)
{
	if (!name || name[0] == 0)
	{
		luaL_error(s, "Invalid name passed to AddTopLevelObject");
	}
	else if (auto thread_ptr = LuaThread::get_from(s))
	{
		return thread_ptr->RemoveTopLevelObject(name);
	}
	return false;
}

#pragma endregion

//============================================================================

#pragma region Table DataType

enum class TypeMembers
{
	Length,
	Empty,
	Index,
	Key,
	Keys,
};

LuaTableType::LuaTableType()
	: MQ2Type( "table")
{
	ScopedTypeMember(TypeMembers, Length);
	ScopedTypeMember(TypeMembers, Empty);
	ScopedTypeMember(TypeMembers, Index);
	ScopedTypeMember(TypeMembers, Key);
	ScopedTypeMember(TypeMembers, Keys);
}

bool LuaTableType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	auto data = VarPtr.Get<sol::object>();
	if (!data)
		return false;

	sol::table table = data->as<sol::table>();

	switch (static_cast<TypeMembers>(pMember->ID))
	{
	case TypeMembers::Length:
		Dest.Int = static_cast<int>(table.size());
		Dest.Type = datatypes::pIntType;
		return true;

	case TypeMembers::Empty:
		Dest.Set(table.empty());
		Dest.Type = datatypes::pBoolType;
		return true;

	case TypeMembers::Index:
	{
		if (!Index[0])
			return false;

		int index = GetIntFromString(Index, 0);
		auto value = table.get<sol::object>(index);
			
		return CreateMacroTypeFromLua(value, Dest);
	}

	case TypeMembers::Key:
	{
		if (!Index[0])
			return false;

		auto value = table.get<sol::object>(Index);

		return CreateMacroTypeFromLua(value, Dest);
	}

	case TypeMembers::Keys:
	{
		sol::table keyTable = sol::table::create(table.lua_state(), (int)table.size());
		int keyIndex = 1;
		for (auto& [k, _] : table)
		{
			keyTable.set(keyIndex++, k);
		}

		return CreateMacroTypeFromLua(keyTable, Dest);
	}

	default:
		break;
	}

	return false;
}

bool LuaTableType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto data = VarPtr.Get<sol::object>();
	if (!data)
		return false;

	sol::table table = data->as<sol::table>();

	// Serialize whatever we were given into a string.
	auto pp = sol::stack::push_pop(table);
	auto stack_val = sol::stack_object(table.lua_state(), -1);
	const char* val_str = luaL_tolstring(stack_val.lua_state(), stack_val.stack_index(), nullptr);
	lua_pop(stack_val.lua_state(), 1);

	strcpy_s(Destination, MAX_STRING, val_str);
	return true;
}

#pragma endregion

//============================================================================

void RegisterBindings_MQMacroData(sol::table& mq)
{
	mq.new_usertype<lua_MQTypeVar>(
		"type",                                  sol::constructors<
		                                             lua_MQTypeVar(const std::string&)>(),
		sol::meta_function::call,                sol::overload(
			                                         &lua_MQTypeVar::Call,
			                                         &lua_MQTypeVar::CallInt,
			                                         &lua_MQTypeVar::CallEmpty,
			                                         &lua_MQTypeVar::CallVA),
		sol::meta_function::index,               &lua_MQTypeVar::Get,
		sol::meta_function::equal_to,            sol::overload(
			                                         &lua_MQTypeVar::operator==,
			                                         &lua_MQTypeVar::EqualData,
			                                         &lua_MQTypeVar::EqualNil));

	mq.new_usertype<lua_MQTopLevelObject>(
		"data",                                  sol::constructors<
		                                             lua_MQTopLevelObject(sol::this_state, const std::string&)>(),
		sol::meta_function::call,                sol::overload(
			                                         &lua_MQTopLevelObject::Call,
			                                         &lua_MQTopLevelObject::CallInt,
			                                         &lua_MQTopLevelObject::CallEmpty,
			                                         &lua_MQTopLevelObject::CallVA),
		sol::meta_function::index,               &lua_MQTopLevelObject::Get,
		sol::meta_function::equal_to,            sol::overload(
			                                         &lua_MQTopLevelObject::operator==,
			                                         &lua_MQTopLevelObject::EqualVar,
			                                         &lua_MQTopLevelObject::EqualNil));

	mq.new_usertype<lua_MQTLO>(
		"tlo",                                   sol::no_constructor,
		sol::meta_function::index,               &lua_MQTLO::Get);
	mq.set("TLO",                                lua_MQTLO());
	mq.set("null",                               lua_MQTypeVar(MQTypeVar()));
	mq.set("gettype",                            sol::overload(
		                                             &mq_gettype_MQTypeVar,
		                                             &mq_gettype_MQTopLevelObject
		                                         ));
	mq.set_function("GetDataTypeNames",              &lua_getDataTypes);

	//----------------------------------------------------------------------------
	// DataTypes and TLOs

	LuaAbstractDataType::RegisterType(mq);

	mq.set_function("AddTopLevelObject", &lua_AddTopLevelObject);
	mq.set_function("RemoveTopLevelObject", &lua_RemoveTopLevelObject);
}

void InitializeBindings_MQMacroData()
{
	s_luaTableType = new LuaTableType();
}

void ShutdownBindings_MQMacroData()
{
	delete s_luaTableType;
	s_luaTableType = nullptr;
}

} // namespace mq::lua::bindings
