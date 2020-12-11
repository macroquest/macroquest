#include "lua_MQDataItem.h"
#include "lua_MQTypeVar.h"

#include <mq/Plugin.h>

using namespace mq::lua;
using namespace mq::lua::bindings;

lua_MQTypeVar lua_MQDataItem::evaluate_self() const
{
	MQTypeVar result;
	if (Self != nullptr)
		Self->Function("", result);

	return lua_MQTypeVar(result);
}

bool lua_MQDataItem::operator==(const lua_MQDataItem& right) const
{
	return evaluate_self() == right.evaluate_self();
}

bool lua_MQDataItem::equal_var(const lua_MQTypeVar& right) const
{
	return evaluate_self() == right;
}

std::string lua_MQDataItem::to_string(const lua_MQDataItem& data)
{
	return lua_MQTypeVar::to_string(data.evaluate_self());
}

sol::object lua_MQDataItem::call(const std::string& index, sol::this_state L) const
{
	MQTypeVar result;
	if (Self != nullptr && Self->Function(index.c_str(), result))
		return sol::object(L, sol::in_place, lua_MQTypeVar(result));

	return sol::object(L, sol::in_place, lua_MQTypeVar(MQTypeVar()));
}

sol::object lua_MQDataItem::call_int(int index, sol::this_state L) const
{
	return call(std::to_string(index), L);
}

sol::object lua_MQDataItem::call_va(sol::this_state L, sol::variadic_args args) const
{
	return call(join(L, ",", args), L);
}

sol::object lua_MQDataItem::call_empty(sol::this_state L) const
{
	MQTypeVar result;
	if (Self != nullptr && Self->Function("", result))
		return lua_MQTypeVar(result).call_empty(L);

	return sol::object(L, sol::in_place, sol::lua_nil);
}

sol::object lua_MQDataItem::get(sol::stack_object key, sol::this_state L) const
{
	MQTypeVar result;
	if (Self != nullptr && Self->Function("", result))
		return lua_MQTypeVar(result).get(key, L);

	return sol::object(L, sol::in_place, lua_MQTypeVar(MQTypeVar()));
}

lua_MQDataItem::lua_MQDataItem(const std::string& str) : Self(FindMQ2Data(str.c_str())) {}

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQDataItem>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQDataItem>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQDataItem sol_lua_get(sol::types<lua_MQDataItem>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQDataItem>(L, index))
	{
		lua_MQDataItem& data = sol::stack::get_usertype<lua_MQDataItem>(L, index, tracking);
		return data;
	}

	return lua_MQDataItem();
}

sol::object lua_MQTLO::get(sol::stack_object key, sol::this_state L) const
{
	auto maybe_key = key.as<std::optional<std::string>>();
	if (maybe_key)
	{
		MQDataItem* result = FindMQ2Data(maybe_key->c_str());
		if (result != nullptr)
			return sol::object(L, sol::in_place, bindings::lua_MQDataItem(result));
	}

	return sol::object(L, sol::in_place, sol::lua_nil);
}

void lua_MQDataItem::register_binding(sol::state& lua)
{
	lua.new_usertype<lua_MQDataItem>("mqdata",
		sol::constructors<lua_MQDataItem(const std::string&)>(),
		sol::meta_function::call, sol::overload(&lua_MQDataItem::call, &lua_MQDataItem::call_int, &lua_MQDataItem::call_empty, &lua_MQDataItem::call_va),
		sol::meta_function::index, &lua_MQDataItem::get,
		sol::meta_function::to_string, lua_MQDataItem::to_string,
		sol::meta_function::equal_to, sol::overload(&lua_MQDataItem::operator==, &lua_MQDataItem::equal_var));

	lua.new_usertype<lua_MQTLO>("mqtlo",
		sol::no_constructor,
		sol::meta_function::index, &lua_MQTLO::get);

	lua["TLO"] = lua_MQTLO();
}
