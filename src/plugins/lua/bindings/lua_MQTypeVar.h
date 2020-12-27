#pragma once
#include "LuaCommon.h"

namespace mq {
struct MQTypeVar;
}

namespace mq::lua::bindings {
struct lua_MQDataItem;
struct lua_MQTypeVar
{
	std::unique_ptr<MQTypeVar> Self;
	std::string Member;

	lua_MQTypeVar(const std::string& str);

	/**
	 * \brief wraps an MQ type var in a lua implementation
	 * \param self the MQ type var data source to be represented in lua
	 */
	lua_MQTypeVar(const MQTypeVar& self);
	bool operator==(const lua_MQTypeVar& right) const;
	bool equal_data(const lua_MQDataItem& right) const;
	MQTypeVar& evaluate_member(char* index = nullptr) const;
	static std::string to_string(const lua_MQTypeVar& obj);
	sol::object call(std::string index, sol::this_state L) const;
	sol::object call_int(int index, sol::this_state L) const;
	sol::object call_va(sol::this_state L, sol::variadic_args args) const;
	sol::object call_empty(sol::this_state L) const;
	sol::object get(sol::stack_object key, sol::this_state L) const;
	static void register_binding(sol::table& lua);
};
}
