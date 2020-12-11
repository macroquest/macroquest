#pragma once
#include "LuaCommon.h"

namespace mq {
struct MQDataItem;
}

namespace mq::lua::bindings {
struct lua_MQTypeVar;
struct lua_MQDataItem
{
	const MQDataItem* const Self;
	lua_MQDataItem() : Self(nullptr) {}

	// this will allow users an alternate way to get data items
	lua_MQDataItem(const std::string& str);
	lua_MQDataItem(const MQDataItem* const self) : Self(self) {}
	lua_MQTypeVar evaluate_self() const;
	bool operator==(const lua_MQDataItem& right) const;
	bool equal_var(const lua_MQTypeVar& right) const;
	static std::string to_string(const lua_MQDataItem& data);
	sol::object call(const std::string& index, sol::this_state L) const;
	sol::object call_int(int index, sol::this_state L) const;
	sol::object call_va(sol::this_state L, sol::variadic_args args) const;
	sol::object call_empty(sol::this_state L) const;
	sol::object get(sol::stack_object key, sol::this_state L) const;
	static void register_binding(sol::state& lua);
};

struct lua_MQTLO
{
	sol::object get(sol::stack_object key, sol::this_state L) const;
};
}
