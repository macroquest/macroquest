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
#include "lua_Bindings.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <string>

namespace mq::lua::bindings {

//============================================================================

// Widgets: Combo Box

// Combo 1: Takes list of items
static std::tuple<int, bool> Combo(const char* label, int currentItem, const sol::table& items, int itemsCount, int popupMaxHeightInItems)
{
	std::vector<const char*> strings;
	for (int i = 1; i <= itemsCount; i++)
	{
		const sol::optional<const char*>& stringItem = items.get<sol::optional<const char*>>(i);
		strings.push_back(stringItem.value_or("Missing Value"));
	}

	currentItem -= 1;
	bool clicked = ImGui::Combo(label, &currentItem, strings.data(), itemsCount, popupMaxHeightInItems);
	return std::make_tuple(currentItem + 1, clicked);
}

// Combo 2: Takes a string containing null separated items
static std::tuple<int, bool> Combo(const char* label, int currentItem, const char* itemsSeparatedByZeros, int popupMaxHeightInItems)
{
	currentItem -= 1;
	bool clicked = ImGui::Combo(label, &currentItem, itemsSeparatedByZeros, popupMaxHeightInItems);
	return std::make_tuple(currentItem + 1, clicked);
}


static bool LuaComboGetter(void* ptr, int idx, const char** out_text)
{
	auto& getter = *static_cast<sol::function*>(ptr);

	sol::function_result result = getter(idx + 1);
	const sol::optional<const char*>& value = result.get<sol::optional<const char*>>();

	if (!value.has_value())
		return false;

	*out_text = *value;
	return true;
}

// Combo 3: Takes callback function to get list of items
static std::tuple<int, bool> Combo(const char* label, int currentItem, sol::function getter, int itemsCount, int popupMaxHeightInItems)
{
	currentItem -= 1;

	bool clicked = ImGui::Combo(label, &currentItem, LuaComboGetter, &getter, itemsCount, popupMaxHeightInItems);
	return std::make_tuple(currentItem + 1, clicked);
}

// Widgets: Drags
static std::tuple<float, bool> DragFloat(const char* label, float v) { bool used = ImGui::DragFloat(label, &v); return std::make_tuple(v, used); }
static std::tuple<float, bool> DragFloat(const char* label, float v, float v_speed) { bool used = ImGui::DragFloat(label, &v, v_speed); return std::make_tuple(v, used); }
static std::tuple<float, bool> DragFloat(const char* label, float v, float v_speed, float v_min) { bool used = ImGui::DragFloat(label, &v, v_speed, v_min); return std::make_tuple(v, used); }
static std::tuple<float, bool> DragFloat(const char* label, float v, float v_speed, float v_min, float v_max) { bool used = ImGui::DragFloat(label, &v, v_speed, v_min, v_max); return std::make_tuple(v, used); }
static std::tuple<float, bool> DragFloat(const char* label, float v, float v_speed, float v_min, float v_max, const char* format) { bool used = ImGui::DragFloat(label, &v, v_speed, v_min, v_max, format); return std::make_tuple(v, used); }
static std::tuple<float, bool> DragFloat(const char* label, float v, float v_speed, float v_min, float v_max, const char* format, float power) { bool used = ImGui::DragFloat(label, &v, v_speed, v_min, v_max, format, power); return std::make_tuple(v, used); }

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat2(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::DragFloat2(label.c_str(), value);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat2(const std::string& label, const sol::table& v, float v_speed)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::DragFloat2(label.c_str(), value, v_speed);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat2(const std::string& label, const sol::table& v, float v_speed, float v_min)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::DragFloat2(label.c_str(), value, v_speed, v_min);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat2(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::DragFloat2(label.c_str(), value, v_speed, v_min, v_max);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat2(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::DragFloat2(label.c_str(), value, v_speed, v_min, v_max, format.c_str());

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat2(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max, const std::string& format, float power)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::DragFloat2(label.c_str(), value, v_speed, v_min, v_max, format.c_str(), power);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat3(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::DragFloat3(label.c_str(), value);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat3(const std::string& label, const sol::table& v, float v_speed)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::DragFloat3(label.c_str(), value, v_speed);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat3(const std::string& label, const sol::table& v, float v_speed, float v_min)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::DragFloat3(label.c_str(), value, v_speed, v_min);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat3(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::DragFloat3(label.c_str(), value, v_speed, v_min, v_max);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat3(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::DragFloat3(label.c_str(), value, v_speed, v_min, v_max, format.c_str());

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat3(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max, const std::string& format, float power)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::DragFloat3(label.c_str(), value, v_speed, v_min, v_max, format.c_str(), power);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat4(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::DragFloat4(label.c_str(), value);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat4(const std::string& label, const sol::table& v, float v_speed)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::DragFloat4(label.c_str(), value, v_speed);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat4(const std::string& label, const sol::table& v, float v_speed, float v_min)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::DragFloat4(label.c_str(), value, v_speed, v_min);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat4(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::DragFloat4(label.c_str(), value, v_speed, v_min, v_max);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat4(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::DragFloat4(label.c_str(), value, v_speed, v_min, v_max, format.c_str());

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloat4(const std::string& label, const sol::table& v, float v_speed, float v_min, float v_max, const std::string& format, float power)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::DragFloat4(label.c_str(), value, v_speed, v_min, v_max, format.c_str(), power);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static void DragFloatRange2() { /* TODO: DragFloatRange2(...) ==> UNSUPPORTED */ }

static std::tuple<int, bool> DragInt(const std::string& label, int v)
{
	bool used = ImGui::DragInt(label.c_str(), &v);
	return std::make_tuple(v, used);
}

static std::tuple<int, bool> DragInt(const std::string& label, int v, float v_speed)
{
	bool used = ImGui::DragInt(label.c_str(), &v, v_speed);
	return std::make_tuple(v, used);
}

static std::tuple<int, bool> DragInt(const std::string& label, int v, float v_speed, int v_min)
{
	bool used = ImGui::DragInt(label.c_str(), &v, v_speed, v_min);
	return std::make_tuple(v, used);
}

static std::tuple<int, bool> DragInt(const std::string& label, int v, float v_speed, int v_min, int v_max)
{
	bool used = ImGui::DragInt(label.c_str(), &v, v_speed, v_min, v_max);
	return std::make_tuple(v, used);
}

static std::tuple<int, bool> DragInt(const std::string& label, int v, float v_speed, int v_min, int v_max, const std::string& format)
{
	bool used = ImGui::DragInt(label.c_str(), &v, v_speed, v_min, v_max, format.c_str());
	return std::make_tuple(v, used);
}

static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt2(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::DragInt2(label.c_str(), value);

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt2(const std::string& label, const sol::table& v, float v_speed)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::DragInt2(label.c_str(), value, v_speed);

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt2(const std::string& label, const sol::table& v, float v_speed, int v_min)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::DragInt2(label.c_str(), value, v_speed, v_min);

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt2(const std::string& label, const sol::table& v, float v_speed, int v_min, int v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::DragInt2(label.c_str(), value, v_speed, v_min, v_max);

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt2(const std::string& label, const sol::table& v, float v_speed, int v_min, int v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::DragInt2(label.c_str(), value, v_speed, v_min, v_max, format.c_str());

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt3(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::DragInt3(label.c_str(), value);

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt3(const std::string& label, const sol::table& v, float v_speed)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::DragInt3(label.c_str(), value, v_speed);

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt3(const std::string& label, const sol::table& v, float v_speed, int v_min)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::DragInt3(label.c_str(), value, v_speed, v_min);

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt3(const std::string& label, const sol::table& v, float v_speed, int v_min, int v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::DragInt3(label.c_str(), value, v_speed, v_min, v_max);

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt3(const std::string& label, const sol::table& v, float v_speed, int v_min, int v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::DragInt3(label.c_str(), value, v_speed, v_min, v_max, format.c_str());

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt4(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::DragInt4(label.c_str(), value);

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt4(const std::string& label, const sol::table& v, float v_speed)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::DragInt4(label.c_str(), value, v_speed);

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt4(const std::string& label, const sol::table& v, float v_speed, int v_min)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::DragInt4(label.c_str(), value, v_speed, v_min);

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt4(const std::string& label, const sol::table& v, float v_speed, int v_min, int v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::DragInt4(label.c_str(), value, v_speed, v_min, v_max);

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragInt4(const std::string& label, const sol::table& v, float v_speed, int v_min, int v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::DragInt4(label.c_str(), value, v_speed, v_min, v_max, format.c_str());

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}
static void DragIntRange2()  { /* TODO: DragIntRange2(...) ==> UNSUPPORTED */ }
static void DragScalar()     { /* TODO: DragScalar(...) ==> UNSUPPORTED */ }
static void DragScalarN()    { /* TODO: DragScalarN(...) ==> UNSUPPORTED */ }

// Widgets: Sliders
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat2(const std::string& label, const sol::table& v, float v_min, float v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::SliderFloat2(label.c_str(), value, v_min, v_max);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat2(const std::string& label, const sol::table& v, float v_min, float v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::SliderFloat2(label.c_str(), value, v_min, v_max, format.c_str());

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat2(const std::string& label, const sol::table& v, float v_min, float v_max, const std::string& format, float power)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::SliderFloat2(label.c_str(), value, v_min, v_max, format.c_str(), power);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat3(const std::string& label, const sol::table& v, float v_min, float v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::SliderFloat3(label.c_str(), value, v_min, v_max);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[3]
	});

	return std::make_tuple(float3, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat3(const std::string& label, const sol::table& v, float v_min, float v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::SliderFloat3(label.c_str(), value, v_min, v_max, format.c_str());

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[3]
	});

	return std::make_tuple(float3, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat3(const std::string& label, const sol::table& v, float v_min, float v_max, const std::string& format, float power)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::SliderFloat3(label.c_str(), value, v_min, v_max, format.c_str(), power);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[3]
	});

	return std::make_tuple(float3, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat4(const std::string& label, const sol::table& v, float v_min, float v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::SliderFloat4(label.c_str(), value, v_min, v_max);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat4(const std::string& label, const sol::table& v, float v_min, float v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::SliderFloat4(label.c_str(), value, v_min, v_max, format.c_str());

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloat4(const std::string& label, const sol::table& v, float v_min, float v_max, const std::string& format, float power)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::SliderFloat4(label.c_str(), value, v_min, v_max, format.c_str(), power);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<float, bool> SliderAngle(const std::string& label, float v_rad)
{
	bool used = ImGui::SliderAngle(label.c_str(), &v_rad);
	return std::make_tuple(v_rad, used);
}

static std::tuple<float, bool> SliderAngle(const std::string& label, float v_rad, float v_degrees_min)
{
	bool used = ImGui::SliderAngle(label.c_str(), &v_rad, v_degrees_min);
	return std::make_tuple(v_rad, used);
}

static std::tuple<float, bool> SliderAngle(const std::string& label, float v_rad, float v_degrees_min, float v_degrees_max)
{
	bool used = ImGui::SliderAngle(label.c_str(), &v_rad, v_degrees_min, v_degrees_max);
	return std::make_tuple(v_rad, used);
}

static std::tuple<float, bool> SliderAngle(const std::string& label, float v_rad, float v_degrees_min, float v_degrees_max, const std::string& format)
{
	bool used = ImGui::SliderAngle(label.c_str(), &v_rad, v_degrees_min, v_degrees_max, format.c_str());
	return std::make_tuple(v_rad, used);
}

static std::tuple<int, bool> SliderInt(const std::string& label, int v, int v_min, int v_max)
{
	bool used = ImGui::SliderInt(label.c_str(), &v, v_min, v_max);
	return std::make_tuple(v, used);
}

static std::tuple<int, bool> SliderInt(const std::string& label, int v, int v_min, int v_max, const std::string& format)
{
	bool used = ImGui::SliderInt(label.c_str(), &v, v_min, v_max, format.c_str());
	return std::make_tuple(v, used);
}

static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderInt2(const std::string& label, const sol::table& v, int v_min, int v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::SliderInt2(label.c_str(), value, v_min, v_max);

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderInt2(const std::string& label, const sol::table& v, int v_min, int v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::SliderInt2(label.c_str(), value, v_min, v_max, format.c_str());

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderInt3(const std::string& label, const sol::table& v, int v_min, int v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::SliderInt3(label.c_str(), value, v_min, v_max);

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderInt3(const std::string& label, const sol::table& v, int v_min, int v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::SliderInt3(label.c_str(), value, v_min, v_max, format.c_str());

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderInt4(const std::string& label, const sol::table& v, int v_min, int v_max)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::SliderInt4(label.c_str(), value, v_min, v_max);

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}
static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderInt4(const std::string& label, const sol::table& v, int v_min, int v_max, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::SliderInt4(label.c_str(), value, v_min, v_max, format.c_str());

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}

static void SliderScalar()                                                                          { /* TODO: SliderScalar(...) ==> UNSUPPORTED */ }
static void SliderScalarN()                                                                         { /* TODO: SliderScalarN(...) ==> UNSUPPORTED */ }
static std::tuple<float, bool> VSliderFloat(const std::string& label, float sizeX, float sizeY, float v, float v_min, float v_max) { bool used = ImGui::VSliderFloat(label.c_str(), { sizeX, sizeY }, &v, v_min, v_max); return std::make_tuple(v, used); }
static std::tuple<float, bool> VSliderFloat(const std::string& label, float sizeX, float sizeY, float v, float v_min, float v_max, const std::string& format) { bool used = ImGui::VSliderFloat(label.c_str(), { sizeX, sizeY }, &v, v_min, v_max, format.c_str()); return std::make_tuple(v, used); }
static std::tuple<float, bool> VSliderFloat(const std::string& label, float sizeX, float sizeY, float v, float v_min, float v_max, const std::string& format, int power) { bool used = ImGui::VSliderFloat(label.c_str(), { sizeX, sizeY }, &v, v_min, v_max, format.c_str(), static_cast<ImGuiSliderFlags>(power)); return std::make_tuple(v, used); }
static std::tuple<int, bool> VSliderInt(const std::string& label, float sizeX, float sizeY, int v, int v_min, int v_max) { bool used = ImGui::VSliderInt(label.c_str(), { sizeX, sizeY }, &v, v_min, v_max); return std::make_tuple(v, used); }
static std::tuple<int, bool> VSliderInt(const std::string& label, float sizeX, float sizeY, int v, int v_min, int v_max, const std::string& format) { bool used = ImGui::VSliderInt(label.c_str(), { sizeX, sizeY }, &v, v_min, v_max, format.c_str()); return std::make_tuple(v, used); }
static void VSliderScalar()                                                                         { /* TODO: VSliderScalar(...) ==> UNSUPPORTED */ }

// Widgets: Input with Keyboard
static std::tuple<float, bool> InputFloat(const std::string& label, float v)                        { bool selected = ImGui::InputFloat(label.c_str(), &v); return std::make_tuple(v, selected); }
static std::tuple<float, bool> InputFloat(const std::string& label, float v, float step)            { bool selected = ImGui::InputFloat(label.c_str(), &v, step); return std::make_tuple(v, selected); }
static std::tuple<float, bool> InputFloat(const std::string& label, float v, float step, float step_fast) { bool selected = ImGui::InputFloat(label.c_str(), &v, step, step_fast); return std::make_tuple(v, selected); }
static std::tuple<float, bool> InputFloat(const std::string& label, float v, float step, float step_fast, const std::string& format) { bool selected = ImGui::InputFloat(label.c_str(), &v, step, step_fast, format.c_str()); return std::make_tuple(v, selected); }
static std::tuple<float, bool> InputFloat(const std::string& label, float v, float step, float step_fast, const std::string& format, int flags) { bool selected = ImGui::InputFloat(label.c_str(), &v, step, step_fast, format.c_str(), static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(v, selected); }

static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat2(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::InputFloat2(label.c_str(), value);

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat2(const std::string& label, const sol::table& v, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::InputFloat2(label.c_str(), value, format.c_str());

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat2(const std::string& label, const sol::table& v, const std::string& format, int flags)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[2] = { float(v1), float(v2) };
	bool used = ImGui::InputFloat2(label.c_str(), value, format.c_str(), static_cast<ImGuiInputTextFlags>(flags));

	sol::as_table_t float2 = sol::as_table(std::vector<float>{
		value[0], value[1]
	});

	return std::make_tuple(float2, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat3(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::InputFloat3(label.c_str(), value);

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat3(const std::string& label, const sol::table& v, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::InputFloat3(label.c_str(), value, format.c_str());

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat3(const std::string& label, const sol::table& v, const std::string& format, int flags)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[3] = { float(v1), float(v2), float(v3) };
	bool used = ImGui::InputFloat3(label.c_str(), value, format.c_str(), static_cast<ImGuiInputTextFlags>(flags));

	sol::as_table_t float3 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(float3, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat4(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::InputFloat4(label.c_str(), value);

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat4(const std::string& label, const sol::table& v, const std::string& format)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::InputFloat4(label.c_str(), value, format.c_str());

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}
static std::tuple <sol::as_table_t<std::vector<float>>, bool> InputFloat4(const std::string& label, const sol::table& v, const std::string& format, int flags)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float value[4] = { float(v1), float(v2), float(v3), float(v4) };
	bool used = ImGui::InputFloat4(label.c_str(), value, format.c_str(), static_cast<ImGuiInputTextFlags>(flags));

	sol::as_table_t float4 = sol::as_table(std::vector<float>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(float4, used);
}

static std::tuple<int, bool> InputInt(const std::string& label, int v)
{
	bool selected = ImGui::InputInt(label.c_str(), &v);
	return std::make_tuple(v, selected);
}

static std::tuple<int, bool> InputInt(const std::string& label, int v, int step)
{
	bool selected = ImGui::InputInt(label.c_str(), &v, step);
	return std::make_tuple(v, selected);
}

static std::tuple<int, bool> InputInt(const std::string& label, int v, int step, int step_fast)
{
	bool selected = ImGui::InputInt(label.c_str(), &v, step, step_fast);
	return std::make_tuple(v, selected);
}

static std::tuple<int, bool> InputInt(const std::string& label, int v, int step, int step_fast, int flags)
{
	bool selected = ImGui::InputInt(label.c_str(), &v, step, step_fast, static_cast<ImGuiInputTextFlags>(flags));
	return std::make_tuple(v, selected);
}

static std::tuple <sol::as_table_t<std::vector<int>>, bool> InputInt2(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::InputInt2(label.c_str(), value);

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}

static std::tuple <sol::as_table_t<std::vector<int>>, bool> InputInt2(const std::string& label, const sol::table& v, int flags)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[2] = { int(v1), int(v2) };
	bool used = ImGui::InputInt2(label.c_str(), value, static_cast<ImGuiInputTextFlags>(flags));

	sol::as_table_t int2 = sol::as_table(std::vector<int>{
		value[0], value[1]
	});

	return std::make_tuple(int2, used);
}

static std::tuple <sol::as_table_t<std::vector<int>>, bool> InputInt3(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::InputInt3(label.c_str(), value);

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}

static std::tuple <sol::as_table_t<std::vector<int>>, bool> InputInt3(const std::string& label, const sol::table& v, int flags)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[3] = { int(v1), int(v2), int(v3) };
	bool used = ImGui::InputInt3(label.c_str(), value, static_cast<ImGuiInputTextFlags>(flags));

	sol::as_table_t int3 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2]
	});

	return std::make_tuple(int3, used);
}

static std::tuple <sol::as_table_t<std::vector<int>>, bool> InputInt4(const std::string& label, const sol::table& v)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::InputInt4(label.c_str(), value);

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}

static std::tuple <sol::as_table_t<std::vector<int>>, bool> InputInt4(const std::string& label, const sol::table& v, int flags)
{
	const lua_Number    v1{ v[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v2{ v[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v3{ v[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    v4{ v[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	int value[4] = { int(v1), int(v2), int(v3), int(v4) };
	bool used = ImGui::InputInt4(label.c_str(), value, static_cast<ImGuiInputTextFlags>(flags));

	sol::as_table_t int4 = sol::as_table(std::vector<int>{
		value[0], value[1], value[2], value[3]
	});

	return std::make_tuple(int4, used);
}

static std::tuple<double, bool> InputDouble(const std::string& label, double v)
{
	bool selected = ImGui::InputDouble(label.c_str(), &v);
	return std::make_tuple(v, selected);
}

static std::tuple<double, bool> InputDouble(const std::string& label, double v, double step)
{
	bool selected = ImGui::InputDouble(label.c_str(), &v, step);
	return std::make_tuple(v, selected);
}

static std::tuple<double, bool> InputDouble(const std::string& label, double v, double step, double step_fast)
{
	bool selected = ImGui::InputDouble(label.c_str(), &v, step, step_fast);
	return std::make_tuple(v, selected);
}

static std::tuple<double, bool> InputDouble(const std::string& label, double v, double step, double step_fast, const std::string& format)
{
	bool selected = ImGui::InputDouble(label.c_str(), &v, step, step_fast, format.c_str());
	return std::make_tuple(v, selected);
}

static std::tuple<double, bool> InputDouble(const std::string& label, double v, double step, double step_fast, const std::string& format, int flags)
{
	bool selected = ImGui::InputDouble(label.c_str(), &v, step, step_fast, format.c_str(), static_cast<ImGuiInputTextFlags>(flags));
	return std::make_tuple(v, selected);
}

static void InputScalar()    { /* TODO: InputScalar(...) ==> UNSUPPORTED */ }
static void InputScalarN()   { /* TODO: InputScalarN(...) ==> UNSUPPORTED */ }

// Widgets: Color Editor / Picker
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorEdit3(const char* label, const sol::table& col, int flags)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[3] = { float(r), float(g), float(b) };
    bool used = ImGui::ColorEdit3(label, color, ImGuiColorEditFlags(flags));

    sol::as_table_t rgb = sol::as_table(std::vector<float>{
        color[0], color[1], color[2]
    });

    return std::make_tuple(rgb, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorEdit4(const std::string& label, const sol::table& col)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[4] = { float(r), float(g), float(b), float(a) };
    bool used = ImGui::ColorEdit4(label.c_str(), color);

    sol::as_table_t rgba = sol::as_table(std::vector<float>{
        color[0], color[1], color[2], color[3]
    });

    return std::make_tuple(rgba, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorEdit4(const std::string& label, const sol::table& col, int flags)
{
	const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
		g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
		b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
		a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float color[4] = { float(r), float(g), float(b), float(a) };
	bool used = ImGui::ColorEdit4(label.c_str(), color, static_cast<ImGuiColorEditFlags>(flags));

	sol::as_table_t rgba = sol::as_table(std::vector<float>{
		color[0], color[1], color[2], color[3]
	});

	return std::make_tuple(rgba, used);
}

static std::tuple<ImVec4, bool> ColorEdit4(const std::string& label, ImVec4 col)
{
	bool used = ImGui::ColorEdit4(label.c_str(), &col.x);

	return std::make_tuple(col, used);
}

static std::tuple<ImVec4, bool> ColorEdit4(const std::string& label, ImVec4 col, int flags)
{
	bool used = ImGui::ColorEdit4(label.c_str(), &col.x, static_cast<ImGuiColorEditFlags>(flags));

	return std::make_tuple(col, used);
}

static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorPicker3(const std::string& label, const sol::table& col)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[3] = { float(r), float(g), float(b) };
    bool used = ImGui::ColorPicker3(label.c_str(), color);

    sol::as_table_t rgb = sol::as_table(std::vector<float>{
        color[0], color[1], color[2]
    });

    return std::make_tuple(rgb, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorPicker3(const std::string& label, const sol::table& col, int flags)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[3] = { float(r), float(g), float(b) };
    bool used = ImGui::ColorPicker3(label.c_str(), color, static_cast<ImGuiColorEditFlags>(flags));

    sol::as_table_t rgb = sol::as_table(std::vector<float>{
        color[0], color[1], color[2]
    });

    return std::make_tuple(rgb, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorPicker4(const std::string& label, const sol::table& col)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[4] = { float(r), float(g), float(b), float(a) };
    bool used = ImGui::ColorPicker4(label.c_str(), color);

    sol::as_table_t rgba = sol::as_table(std::vector<float>{
        color[0], color[1], color[2], color[3]
    });

    return std::make_tuple(rgba, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorPicker4(const std::string& label, const sol::table& col, int flags)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[4] = { float(r), float(g), float(b), float(a) };
    bool used = ImGui::ColorPicker4(label.c_str(), color, static_cast<ImGuiColorEditFlags>(flags));

    sol::as_table_t rgba = sol::as_table(std::vector<float>{
        color[0], color[1], color[2], color[3]
    });

    return std::make_tuple(rgba, used);
}
static bool ColorButton(const std::string& desc_id, const sol::table& col)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    const ImVec4 color{ float(r), float(g), float(b), float(a) };
    return ImGui::ColorButton(desc_id.c_str(), color);
}
static bool ColorButton(const std::string& desc_id, const sol::table& col, int flags)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    const ImVec4 color{ float(r), float(g), float(b), float(a) };
    return ImGui::ColorButton(desc_id.c_str(), color, static_cast<ImGuiColorEditFlags>(flags));
}
static bool ColorButton(const std::string& desc_id, const sol::table& col, int flags, float sizeX, float sizeY)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        a{ col[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    const ImVec4 color{ float(r), float(g), float(b), float(a) };
    return ImGui::ColorButton(desc_id.c_str(), color, static_cast<ImGuiColorEditFlags>(flags), { sizeX, sizeY });
}
static void SetColorEditOptions(int flags)                                                          { ImGui::SetColorEditOptions(static_cast<ImGuiColorEditFlags>(flags)); }

// Widgets: Trees
static bool TreeNode(const std::string& label)                                                      { return ImGui::TreeNode(label.c_str()); }
static bool TreeNode(const std::string& label, const std::string& fmt)                              { return ImGui::TreeNode(label.c_str(), fmt.c_str()); }
static bool TreeNodeEx(const std::string& label)                                                    { return ImGui::TreeNodeEx(label.c_str()); }
static bool TreeNodeEx(const std::string& label, int flags)                                         { return ImGui::TreeNodeEx(label.c_str(), static_cast<ImGuiTreeNodeFlags>(flags)); }
static bool TreeNodeEx(const std::string& label, int flags, const std::string& fmt)                 { return ImGui::TreeNodeEx(label.c_str(), static_cast<ImGuiTreeNodeFlags>(flags), fmt.c_str()); }
/* TODO: TreePush(const void*) ==> UNSUPPORTED */

// Widgets: List Boxes
static std::tuple<int, bool> ListBox(const char* label, int current_item, const sol::table& items, int items_count, int height_in_items)
{
	std::vector<const char*> strings;
	strings.reserve(items_count);
	for (int i = 1; i <= items_count; i++)
	{
		const sol::optional<const char*>& stringItem = items.get<sol::optional<const char*>>(i);
		strings.push_back(stringItem.value_or("Missing String"));
	}

	current_item -= 1;
	bool clicked = ImGui::ListBox(label, &current_item, strings.data(), items_count);
	return std::make_tuple(current_item + 1, clicked);
}

static std::tuple<int, bool> ListBox(const char* label, int current_item, const sol::table& items, int items_count)
{
	return ListBox(label, current_item, items, items_count, -1);
}


// Widgets: Data Plotting
/* TODO: Widgets Data Plotting ==> UNSUPPORTED (barely used and quite long functions) */

// Widgets: Value() helpers
static void Value(const std::string& prefix, bool b)                                                { ImGui::Value(prefix.c_str(), b); }
static void Value(const std::string& prefix, int v)                                                 { ImGui::Value(prefix.c_str(), v); }
static void Value(const std::string& prefix, unsigned int v)                                        { ImGui::Value(prefix.c_str(), v); }
static void Value(const std::string& prefix, float v)                                               { ImGui::Value(prefix.c_str(), v); }
static void Value(const std::string& prefix, float v, const std::string& float_format)              { ImGui::Value(prefix.c_str(), v, float_format.c_str()); }

// Tooltips
static void BeginTooltip()                                                                          { ImGui::BeginTooltip(); }
static void EndTooltip()                                                                            { ImGui::EndTooltip(); }
static void SetTooltip(const std::string& fmt)                                                      { ImGui::SetTooltip(fmt.c_str()); }
static void SetTooltipV()                                                                           { /* TODO: SetTooltipV(...) ==> UNSUPPORTED */ }

// Tables
static bool BeginTable(const std::string& str_id, int columns_count)                                { return ImGui::BeginTable(str_id.c_str(), columns_count); }
static bool BeginTable(const std::string& str_id, int columns_count, int flags)                     { return ImGui::BeginTable(str_id.c_str(), columns_count, static_cast<ImGuiTableFlags>(flags)); }
static bool BeginTable(const std::string& str_id, int columns_count, int flags, float outer_sizeX, float outer_sizeY) { return ImGui::BeginTable(str_id.c_str(), columns_count, static_cast<ImGuiTableFlags>(flags), ImVec2(outer_sizeX, outer_sizeY)); }
static bool BeginTable(const std::string& str_id, int columns_count, int flags, float outer_sizeX, float outer_sizeY, float inner_width) { return ImGui::BeginTable(str_id.c_str(), columns_count, static_cast<ImGuiTableFlags>(flags), ImVec2(outer_sizeX, outer_sizeY), inner_width); }
static void EndTable()                                                                              { ImGui::EndTable(); }
static void TableNextRow()                                                                          { ImGui::TableNextRow(); }
static void TableNextRow(int row_flags)                                                             { ImGui::TableNextRow(static_cast<ImGuiTableRowFlags>(row_flags)); }
static void TableNextRow(int row_flags, float min_row_height)                                       { ImGui::TableNextRow(static_cast<ImGuiTableRowFlags>(row_flags), min_row_height); }
static void TableNextColumn()                                                                       { ImGui::TableNextColumn(); }
static bool TableSetColumnIndex(int column_n)                                                       { return ImGui::TableSetColumnIndex(column_n); }

static void TableSetupColumn(const std::string& label)                                              { ImGui::TableSetupColumn(label.c_str()); }
static void TableSetupColumn(const std::string& label, int flags)                                   { ImGui::TableSetupColumn(label.c_str(), static_cast<ImGuiTableColumnFlags>(flags)); }
static void TableSetupColumn(const std::string& label, int flags, float init_width_or_weight)       { ImGui::TableSetupColumn(label.c_str(), static_cast<ImGuiTableColumnFlags>(flags), init_width_or_weight); }
static void TableSetupColumn(const std::string& label, int flags, float init_width_or_weight, uint32_t user_id)       { ImGui::TableSetupColumn(label.c_str(), static_cast<ImGuiTableColumnFlags>(flags), init_width_or_weight, user_id); }
static void TableSetupScrollFreeze(int cols, int rows)                                              { ImGui::TableSetupScrollFreeze(cols, rows); }
static void TableHeadersRow()                                                                       { ImGui::TableHeadersRow(); }
static void TableHeader(const std::string& label)                                                   { ImGui::TableHeader(label.c_str()); }

static int TableGetColumnCount()                                                                    { return ImGui::TableGetColumnCount(); }
static int TableGetColumnFlags(int column_n)                                                        { return ImGui::TableGetColumnFlags(column_n); }
static std::string TableGetColumnName()                                                             { const char* name = ImGui::TableGetColumnName(); if (name) return std::string(name); return std::string(); }
static std::string TableGetColumnName(int column_n)                                                 { const char* name = ImGui::TableGetColumnName(column_n); if (name) return std::string(name); return std::string(); }
static bool TableGetColumnHasFlag(ImGuiTableColumnFlags flag)                                       { return (ImGui::TableGetColumnFlags() & flag) != 0; }
static bool TableGetColumnHasFlag(int column_n, ImGuiTableColumnFlags flag)                         { return (ImGui::TableGetColumnFlags(column_n) & flag) != 0; }
static bool TableGetColumnIsVisible()                                                               { return (ImGui::TableGetColumnFlags() & ImGuiTableColumnFlags_IsVisible) != 0; }
static bool TableGetColumnIsVisible(int column_n)                                                   { return (ImGui::TableGetColumnFlags(column_n) & ImGuiTableColumnFlags_IsVisible) != 0; }
static bool TableGetColumnIsSorted()                                                                { return (ImGui::TableGetColumnFlags() & ImGuiTableColumnFlags_IsSorted) != 0; }
static bool TableGetColumnIsSorted(int column_n)                                                    { return (ImGui::TableGetColumnFlags(column_n) & ImGuiTableColumnFlags_IsSorted) != 0; }
static int TableGetHoveredColumn()                                                                  { return ImGui::TableGetHoveredColumn(); }
static ImGuiTableSortSpecs* TableGetSortSpecs()                                                     { return ImGui::TableGetSortSpecs(); }
static void TableSetBgColor(int bg_target, int col)                                                 { ImGui::TableSetBgColor(static_cast<ImGuiTableBgTarget>(bg_target), ImU32(col)); }
static void TableSetBgColor(int bg_target, int col, int column_n)                                   { ImGui::TableSetBgColor(static_cast<ImGuiTableBgTarget>(bg_target), ImU32(col), column_n); }
static void TableSetBgColor(int bg_target, float colR, float colG, float colB, float colA)          { ImGui::TableSetBgColor(static_cast<ImGuiTableBgTarget>(bg_target), ImGui::GetColorU32({ colR, colG, colB, colA })); }
static void TableSetBgColor(int bg_target, float colR, float colG, float colB, float colA, int column_n)          { ImGui::TableSetBgColor(static_cast<ImGuiTableBgTarget>(bg_target), ImGui::GetColorU32({ colR, colG, colB, colA }), column_n); }

// Columns
static void Columns()                                                                               { ImGui::Columns(); }
static void Columns(int count)                                                                      { ImGui::Columns(count); }
static void Columns(int count, const std::string& id)                                               { ImGui::Columns(count, id.c_str()); }
static void Columns(int count, const std::string& id, bool border)                                  { ImGui::Columns(count, id.c_str(), border); }
static void NextColumn()                                                                            { ImGui::NextColumn(); }
static int GetColumnIndex()                                                                         { return ImGui::GetColumnIndex(); }
static float GetColumnWidth()                                                                       { return ImGui::GetColumnWidth(); }
static float GetColumnWidth(int column_index)                                                       { return ImGui::GetColumnWidth(column_index); }
static void SetColumnWidth(int column_index, float width)                                           { ImGui::SetColumnWidth(column_index, width); }
static float GetColumnOffset()                                                                      { return ImGui::GetColumnOffset(); }
static float GetColumnOffset(int column_index)                                                      { return ImGui::GetColumnOffset(column_index); }
static void SetColumnOffset(int column_index, float offset_x)                                       { ImGui::SetColumnOffset(column_index, offset_x); }
static int GetColumnsCount()                                                                        { return ImGui::GetColumnsCount(); }

// Tab Bars, Tabs
static bool BeginTabBar(const std::string& str_id)                                                  { return ImGui::BeginTabBar(str_id.c_str()); }
static bool BeginTabBar(const std::string& str_id, int flags)                                       { return ImGui::BeginTabBar(str_id.c_str(), static_cast<ImGuiTabBarFlags>(flags)); }
static void EndTabBar()                                                                             { ImGui::EndTabBar(); }
static bool BeginTabItem(const std::string& label)                                                  { return ImGui::BeginTabItem(label.c_str()); }
static std::tuple<bool, bool> BeginTabItem(const std::string& label, bool open)                     { bool selected = ImGui::BeginTabItem(label.c_str(), &open); return std::make_tuple(open, selected); }
static std::tuple<bool, bool> BeginTabItem(const std::string& label, bool open, int flags)          { bool selected = ImGui::BeginTabItem(label.c_str(), &open, static_cast<ImGuiTabItemFlags>(flags)); return std::make_tuple(open, selected); }
static void EndTabItem()                                                                            { ImGui::EndTabItem(); }
static void SetTabItemClosed(const std::string& tab_or_docked_window_label)                         { ImGui::SetTabItemClosed(tab_or_docked_window_label.c_str()); }

// Docking
static unsigned int DockSpaceOverViewport()                                                         { return 0; /* TODO: DockSpaceOverViwport(...) ==> UNSUPPORTED */ }
static void SetNextWindowDockID(unsigned int dock_id)                                               { ImGui::SetNextWindowDockID(dock_id); }
static void SetNextWindowDockID(unsigned int dock_id, int cond)                                     { ImGui::SetNextWindowDockID(dock_id, static_cast<ImGuiCond>(cond)); }
static void SetNextWindowClass()                                                                    {  /* TODO: SetNextWindowClass(...) ==> UNSUPPORTED */ }
static unsigned int GetWindowDockID()                                                               { return ImGui::GetWindowDockID(); }
static bool IsWindowDocked()                                                                        { return ImGui::IsWindowDocked(); }

// Drag and Drop
// Create a type to add as a lua usertype
struct LuaImGuiPayload
{
	// TODO: expand this variant to handle more complex types. The issue with that is that SetDragDropPayload will
	// shallow copy data (with memcpy), so we need to specially handle any complex types (like sol::function) that
	// would lose their refs on both the Set and Accept ends
	using VarType = std::variant<int, float, std::string>;
	VarType Data;

	LuaImGuiPayload(const ImGuiPayload* payload)
		: Data(*static_cast<VarType*>(payload->Data)) {}
};
static bool BeginDragDropSource()                                                                   { return ImGui::BeginDragDropSource(); }
static bool BeginDragDropSource(int flags)                                                          { return ImGui::BeginDragDropSource(static_cast<ImGuiDragDropFlags>(flags)); }
static bool SetDragDropPayload(const std::string& type, sol::object data, int cond)
{
	if (data.get_type() == sol::type::nil)
		return false;

	auto vardata = data.as<LuaImGuiPayload::VarType>();
	return ImGui::SetDragDropPayload(type.c_str(), &vardata, sizeof(vardata), static_cast<ImGuiCond>(cond));
}
static bool SetDragDropPayload(const std::string& type, sol::object data)                           { return SetDragDropPayload(type, data, ImGuiCond_None); }
static void EndDragDropSource()                                                                     { ImGui::EndDragDropSource(); }
static bool BeginDragDropTarget()                                                                   { return ImGui::BeginDragDropTarget(); }

static std::unique_ptr<LuaImGuiPayload> AcceptDragDropPayload(const std::string& type, int flags)
{
	auto payload = ImGui::AcceptDragDropPayload(type.c_str(), static_cast<ImGuiDragDropFlags>(flags));
	return payload == nullptr ? nullptr : std::make_unique<LuaImGuiPayload>(payload);
}
static std::unique_ptr<LuaImGuiPayload> AcceptDragDropPayload(const std::string& type)              { return AcceptDragDropPayload(type, ImGuiDragDropFlags_None); }
static void EndDragDropTarget()                                                                     { ImGui::EndDragDropTarget(); }
static std::unique_ptr<LuaImGuiPayload> GetDragDropPayload()
{
	auto payload = ImGui::GetDragDropPayload();
	return payload == nullptr ? nullptr : std::make_unique<LuaImGuiPayload>(payload);
}

void RegisterBindings_ImGuiWidgets(sol::table& ImGui)
{
	#pragma region Widgets: Text
	ImGui.set_function("TextUnformatted",   [](std::string_view text) { ImGui::TextUnformatted(text.data(), text.data() + text.size()); });
	ImGui.set_function("Text", sol::overload(
		[](std::string_view text) { ImGui::TextUnformatted(text.data(), text.data() + text.size()); },
		[](sol::variadic_args va, sol::this_state s) { sol::function string_format = sol::state_view(s)["string"]["format"]; std::string text = string_format(va); ImGui::Text("%s", text.c_str()); }
	));
	ImGui.set_function("TextColored", sol::overload(
		[](float r, float g, float b, float a, const char* text) { ImGui::TextColored({ r, g, b, a }, text); },
		[](int col, const char* text) { ImGui::TextColored(ImColor(col), text); },
		[](const ImVec4& col, const char* text) { ImGui::TextColored(col, text); },
		[](float r, float g, float b, float a, sol::variadic_args va, sol::this_state s) { sol::function string_format = sol::state_view(s)["string"]["format"]; std::string text = string_format(va); ImGui::TextColored({ r, g, b, a }, text.c_str()); },
		[](int col, sol::variadic_args va, sol::this_state s) { sol::function string_format = sol::state_view(s)["string"]["format"]; std::string text = string_format(va); ImGui::TextColored(ImColor(col), text.c_str()); },
		[](const ImVec4& col, sol::variadic_args va, sol::this_state s) { sol::function string_format = sol::state_view(s)["string"]["format"]; std::string text = string_format(va); ImGui::TextColored(col, text.c_str()); }
	));
	ImGui.set_function("TextDisabled", sol::overload(
		[](const char* text) { ImGui::TextDisabled("%s", text); },
		[](sol::variadic_args va, sol::this_state s) { sol::function string_format = sol::state_view(s)["string"]["format"]; std::string text = string_format(va); ImGui::TextDisabled("%s", text.c_str()); }
	));
	ImGui.set_function("TextWrapped", sol::overload(
		[](const char* text) { ImGui::TextWrapped("%s", text); },
		[](sol::variadic_args va, sol::this_state s) { sol::function string_format = sol::state_view(s)["string"]["format"]; std::string text = string_format(va); ImGui::Text("%s", text.c_str()); }
	));
	ImGui.set_function("LabelText",         [](const char* label, const char* text) { ImGui::LabelText(label, "%s", text); });
	ImGui.set_function("BulletText",        [](const char* text) { ImGui::BulletText("%s", text); });
	#pragma endregion

	#pragma region Widgets: Main
	ImGui.set_function("Button", sol::overload(
		                                    [](const char* label) { return ImGui::Button(label); },
		                                    [](const char* label, float sizeX, float sizeY) { return ImGui::Button(label, { sizeX, sizeY }); },
		                                    [](const char* label, const ImVec2& size) { return ImGui::Button(label, size); }));
	ImGui.set_function("SmallButton",       [](const char* label) { return ImGui::SmallButton(label); });
	ImGui.set_function("InvisibleButton", sol::overload(
		                                    [](const char* stringID, float sizeX, float sizeY) { return ImGui::InvisibleButton(stringID, { sizeX, sizeY }); },
		                                    [](const char* stringID, const ImVec2& size) { return ImGui::InvisibleButton(stringID, size); },
		                                    [](const char* stringID, const ImVec2& size, int flags) { return ImGui::InvisibleButton(stringID, size, ImGuiButtonFlags(flags)); }));
	ImGui.set_function("ArrowButton",       [](const char* stringID, int dir) { return ImGui::ArrowButton(stringID, ImGuiDir(dir));  });

	ImGui.set_function("Image", sol::overload(
		                                    [](ImTextureID texture_id, const ImVec2& size) { ImGui::Image(texture_id, size); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0) { ImGui::Image(texture_id, size, uv0); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1) { ImGui::Image(texture_id, size, uv0, uv1); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col) { ImGui::Image(texture_id, size, uv0, uv1, tint_col); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, const ImVec4& tint_col, const ImVec4& border_col) { ImGui::Image(texture_id, size, uv0, uv1, tint_col, border_col); }
	));
	ImGui.set_function("ImageButton", sol::overload(
		                                    [](ImTextureID texture_id, const ImVec2& size) { return ImGui::ImageButton(texture_id, size); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0) { return ImGui::ImageButton(texture_id, size, uv0); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1) { return ImGui::ImageButton(texture_id, size, uv0, uv1); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding) { return ImGui::ImageButton(texture_id, size, uv0, uv1, frame_padding); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col) { return ImGui::ImageButton(texture_id, size, uv0, uv1, frame_padding, bg_col); },
		                                    [](ImTextureID texture_id, const ImVec2& size, const ImVec2& uv0, const ImVec2& uv1, int frame_padding, const ImVec4& bg_col, const ImVec4& tint_col) { return ImGui::ImageButton(texture_id, size, uv0, uv1, frame_padding, bg_col, tint_col); }
	));

	ImGui.set_function("Checkbox",          [](const char* label, bool v) -> std::tuple<bool, bool> { bool value = v; bool pressed = ImGui::Checkbox(label, &value); return std::make_tuple(value, pressed); });
	ImGui.set_function("CheckboxFlags",     [](const char* label, uint32_t flags, uint32_t flagsValue) -> std::tuple<uint32_t, bool> { uint32_t mutableFlags = flags; bool pressed = ImGui::CheckboxFlags(label, &mutableFlags, flagsValue); return std::make_tuple(mutableFlags, pressed); });
	ImGui.set_function("RadioButton", sol::overload(
		                                    [](const char* label, bool active) { return ImGui::RadioButton(label, active); },
		                                    [](const char* label, int v, int vButton) -> std::tuple<int, bool> { bool ret = ImGui::RadioButton(label, &v, vButton); return std::make_tuple(v, ret); }
	));
	ImGui.set_function("ProgressBar", sol::overload(
		                                    [](float fraction) { ImGui::ProgressBar(fraction); },
		                                    [](float fraction, const ImVec2& size) { ImGui::ProgressBar(fraction, size); },
		                                    [](float fraction, const ImVec2& size, const char* overlay) { ImGui::ProgressBar(fraction, size, overlay); },
		                                    [](float fraction, float sizeX, float sizeY) { ImGui::ProgressBar(fraction, { sizeX, sizeY }); },
		                                    [](float fraction, float sizeX, float sizeY, const char* overlay) { ImGui::ProgressBar(fraction, { sizeX, sizeY }, overlay); }
	));
	ImGui.set_function("Bullet",            &ImGui::Bullet);
	#pragma endregion

	#pragma region Widgets: Combo Box
	ImGui.set_function("BeginCombo", sol::overload(
		                                    [](const char* label, const char* previewValue) { return ImGui::BeginCombo(label, previewValue); },
		                                    [](const char* label, const char* previewValue, int flags) {  return ImGui::BeginCombo(label, previewValue, ImGuiComboFlags(flags)); }
	));
	ImGui.set_function("EndCombo",          &ImGui::EndCombo);
	ImGui.set_function("Combo", sol::overload(
		                                    [](const char* label, int currentItem, const sol::table& items, int itemsCount) { return Combo(label, currentItem, items, itemsCount, -1); },
		                                    sol::resolve<std::tuple<int, bool>(const char*, int, const sol::table&, int, int)>(Combo),
		                                    [](const char* label, int currentItem, const char* itemsSeparatedByZeros) { return Combo(label, currentItem, itemsSeparatedByZeros, -1); },
		                                    sol::resolve<std::tuple<int, bool>(const char*, int, const char*, int)>(Combo),
		                                    [](const char* label, int currentItem, sol::function getter, int itemsCount) { return Combo(label, currentItem, getter, itemsCount, -1); },
		                                    sol::resolve<std::tuple<int, bool>(const char*, int, sol::function, int, int)>(Combo)
	));
	#pragma endregion

	#pragma region Widgets: Drags
	ImGui.set_function("DragFloat", sol::overload(
		sol::resolve<std::tuple<float, bool>(const char*, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const char*, float, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const char*, float, float, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const char*, float, float, float, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const char*, float, float, float, float, const char*)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const char*, float, float, float, float, const char*, float)>(DragFloat)
	));
	ImGui.set_function("DragFloat2", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(DragFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float)>(DragFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float)>(DragFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float)>(DragFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float, const std::string&)>(DragFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float, const std::string&, float)>(DragFloat2)
	));
	ImGui.set_function("DragFloat3", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(DragFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float)>(DragFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float)>(DragFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float)>(DragFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float, const std::string&)>(DragFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float, const std::string&, float)>(DragFloat3)
	));
	ImGui.set_function("DragFloat4", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(DragFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float)>(DragFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float)>(DragFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float)>(DragFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float, const std::string&)>(DragFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, float, const std::string&, float)>(DragFloat4)
	));
	ImGui.set_function("DragInt", sol::overload(
		sol::resolve<std::tuple<int, bool>(const std::string&, int)>(DragInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, float)>(DragInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, float, int)>(DragInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, float, int, int)>(DragInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, float, int, int, const std::string&)>(DragInt)
	));
	ImGui.set_function("DragInt2", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&)>(DragInt2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float)>(DragInt2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int)>(DragInt2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int, int)>(DragInt2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int, int, const std::string&)>(DragInt2)
	));
	ImGui.set_function("DragInt3", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&)>(DragInt3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float)>(DragInt3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int)>(DragInt3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int, int)>(DragInt3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int, int, const std::string&)>(DragInt3)
	));
	ImGui.set_function("DragInt4", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&)>(DragInt4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float)>(DragInt4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int)>(DragInt4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int, int)>(DragInt4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, float, int, int, const std::string&)>(DragInt4)
	));
	#pragma endregion

	#pragma region Widgets: Sliders
	ImGui.set_function("SliderFloat", sol::overload(
		// This form is deprecated. Use the flags form instead.
		[](const char* label, float v, float v_min, float v_max, const char* format, float power)
		{
			ImGuiSliderFlags slider_flags = ImGuiSliderFlags_None;
			if (power != 1.0f) slider_flags |= ImGuiSliderFlags_Logarithmic;
			bool changed = ImGui::SliderFloat(label, &v, v_min, v_max, format, slider_flags);
			return std::make_tuple(v, changed);
		},
		[](const char* label, float v, float v_min, float v_max, const sol::optional<const char*>& format_, const sol::optional<ImGuiSliderFlags>& flags_)
		{
			const char* format = format_.value_or("%.3f");
			ImGuiSliderFlags slider_flags = flags_.value_or(0);
			bool changed = ImGui::SliderFloat(label, &v, v_min, v_max, format, slider_flags);
			return std::make_tuple(v, changed);
		}
	));

	ImGui.set_function("SliderFloat2", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float)>(SliderFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, const std::string&)>(SliderFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, const std::string&, float)>(SliderFloat2)
	));
	ImGui.set_function("SliderFloat3", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float)>(SliderFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, const std::string&)>(SliderFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, const std::string&, float)>(SliderFloat3)
	));
	ImGui.set_function("SliderFloat4", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float)>(SliderFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, const std::string&)>(SliderFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, float, float, const std::string&, float)>(SliderFloat4)
	));
	ImGui.set_function("SliderAngle", sol::overload(
		sol::resolve<std::tuple<float, bool>(const std::string&, float)>(SliderAngle),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float)>(SliderAngle),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float)>(SliderAngle),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, const std::string&)>(SliderAngle)
	));
	ImGui.set_function("SliderInt", sol::overload(
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int, int)>(SliderInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int, int, const std::string&)>(SliderInt)
	));
	ImGui.set_function("SliderInt2", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int, int)>(SliderInt2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int, int, const std::string&)>(SliderInt2)
	));
	ImGui.set_function("SliderInt3", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int, int)>(SliderInt3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int, int, const std::string&)>(SliderInt3)
	));
	ImGui.set_function("SliderInt4", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int, int)>(SliderInt4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int, int, const std::string&)>(SliderInt4)
	));
	ImGui.set_function("VSliderFloat", sol::overload(
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, float, float)>(VSliderFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, float, float, const std::string&)>(VSliderFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, float, float, const std::string&, int)>(VSliderFloat)
	));
	ImGui.set_function("VSliderInt", sol::overload(
		sol::resolve<std::tuple<int, bool>(const std::string&, float, float, int, int, int)>(VSliderInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, float, float, int, int, int, const std::string&)>(VSliderInt)
	));
	#pragma endregion

	#pragma region Widgets: Inputs using Keyboard
	ImGui.set_function("InputText", sol::overload(
		[](const char* label, std::string text) { bool selected = ImGui::InputText(label, &text); return std::make_tuple(text, selected); },
		[](const char* label, std::string text, int flags) { bool selected = ImGui::InputText(label, &text, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); }
	));
	ImGui.set_function("InputTextMultiline", sol::overload(
		[](const char* label, std::string text) { bool selected = ImGui::InputTextMultiline(label, &text); return std::make_tuple(text, selected); },
		[](const char* label, std::string text, float sizeX, float sizeY) { bool selected = ImGui::InputTextMultiline(label, &text, { sizeX, sizeY }); return std::make_tuple(text, selected); },
		[](const char* label, std::string text, float sizeX, float sizeY, int flags) { bool selected = ImGui::InputTextMultiline(label, &text, { sizeX, sizeY }, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); },
		[](const char* label, std::string text, const ImVec2& size) { bool selected = ImGui::InputTextMultiline(label, &text, size); return std::make_tuple(text, selected); },
		[](const char* label, std::string text, const ImVec2& size, int flags) { bool selected = ImGui::InputTextMultiline(label, &text, size, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); }
	));
	ImGui.set_function("InputTextWithHint", sol::overload(
		[](const char* label, const char* hint, std::string text) { bool selected = ImGui::InputTextWithHint(label, hint, &text); return std::make_tuple(text, selected); },
		[](const char* label, const char* hint, std::string text, int flags) { bool selected = ImGui::InputTextWithHint(label, hint, &text, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); }
	));
	ImGui.set_function("InputFloat", sol::overload(
		sol::resolve<std::tuple<float, bool>(const std::string&, float)>(InputFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float)>(InputFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float)>(InputFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, const std::string&)>(InputFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, const std::string&, int)>(InputFloat)
	));
	ImGui.set_function("InputFloat2", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(InputFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, const std::string&)>(InputFloat2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, const std::string&, int)>(InputFloat2)
	));
	ImGui.set_function("InputFloat3", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(InputFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, const std::string&)>(InputFloat3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, const std::string&, int)>(InputFloat3)
	));
	ImGui.set_function("InputFloat4", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(InputFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, const std::string&)>(InputFloat4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, const std::string&, int)>(InputFloat4)
	));
	ImGui.set_function("InputInt", sol::overload(
		sol::resolve<std::tuple<int, bool>(const std::string&, int)>(InputInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int)>(InputInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int, int)>(InputInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int, int)>(InputInt),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int, int, int)>(InputInt)
	));
	ImGui.set_function("InputInt2", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&)>(InputInt2),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int)>(InputInt2)
	));
	ImGui.set_function("InputInt3", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&)>(InputInt3),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int)>(InputInt3)
	));
	ImGui.set_function("InputInt4", sol::overload(
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&)>(InputInt4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<int>>, bool>(const std::string&, const sol::table&, int)>(InputInt4)
	));
	ImGui.set_function("InputDouble", sol::overload(
		sol::resolve<std::tuple<double, bool>(const std::string&, double)>(InputDouble),
		sol::resolve<std::tuple<double, bool>(const std::string&, double, double)>(InputDouble),
		sol::resolve<std::tuple<double, bool>(const std::string&, double, double, double)>(InputDouble),
		sol::resolve<std::tuple<double, bool>(const std::string&, double, double, double, const std::string&)>(InputDouble),
		sol::resolve<std::tuple<double, bool>(const std::string&, double, double, double, const std::string&, int)>(InputDouble)
	));
	#pragma endregion

	#pragma region Widgets: Color Editor / Picker
	ImGui.set_function("ColorEdit3", sol::overload(
		[](const char* label, ImVec4 col) { bool used = ImGui::ColorEdit3(label, &col.x); return std::make_tuple(col, used); },
		[](const char* label, ImVec4 col, int flags) { bool used = ImGui::ColorEdit3(label, &col.x); return std::make_tuple(col, used, ImGuiColorEditFlags(flags)); },
		[](const char* label, const sol::table& col) { return ColorEdit3(label, col, 0); },
		[](const char* label, const sol::table& col, int flags) { return ColorEdit3(label, col, flags); }
	));
	ImGui.set_function("ColorEdit4", sol::overload(
		sol::resolve<std::tuple<ImVec4, bool>(const std::string&, ImVec4)>(ColorEdit4),
		sol::resolve<std::tuple<ImVec4, bool>(const std::string&, ImVec4, int)>(ColorEdit4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(ColorEdit4),
		sol::resolve<std::tuple<sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, int)>(ColorEdit4)
	));
	ImGui.set_function("ColorPicker3", sol::overload(
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(ColorPicker3),
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, int)>(ColorPicker3)
	));
	ImGui.set_function("ColorPicker4", sol::overload(
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(ColorPicker4),
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, int)>(ColorPicker4)
	));
	#pragma endregion

	#pragma region Widgets: Trees
	ImGui.set_function("TreeNode", sol::overload(
		sol::resolve<bool(const std::string&)>(TreeNode),
		sol::resolve<bool(const std::string&, const std::string&)>(TreeNode)
	));
	ImGui.set_function("TreeNodeEx", sol::overload(
		sol::resolve<bool(const std::string&)>(TreeNodeEx),
		sol::resolve<bool(const std::string&, int)>(TreeNodeEx),
		sol::resolve<bool(const std::string&, int, const std::string&)>(TreeNodeEx)
	));
	ImGui.set_function("TreePush", sol::overload(
		[]() { ImGui::TreePush(); },
		[](const char* strId) { ImGui::TreePush(strId); },
		[](sol::object obj) { ImGui::TreePush(obj.pointer()); }
	));
	ImGui.set_function("TreePop", &ImGui::TreePop);
	ImGui.set_function("GetTreeNodeToLabelSpacing", &ImGui::GetTreeNodeToLabelSpacing);
	ImGui.set_function("CollapsingHeader", sol::overload(
		[](const char* label) { return ImGui::CollapsingHeader(label); },
		[](const char* label, int flags) { return ImGui::CollapsingHeader(label, ImGuiTreeNodeFlags(flags)); },
		[](const char* label, nullptr_t, int flags) { bool show = ImGui::CollapsingHeader(label, ImGuiTreeNodeFlags(flags)); return std::make_tuple(true, show); },
		[](const char* label, bool open) { bool show = ImGui::CollapsingHeader(label, &open); return std::make_tuple(open, show); },
		[](const char* label, bool open, int flags) { bool show = ImGui::CollapsingHeader(label, &open, ImGuiTreeNodeFlags(flags)); return std::make_tuple(open, show); }
	));
	ImGui.set_function("SetNextItemOpen", sol::overload(
		[](bool is_open) { ImGui::SetNextItemOpen(is_open); },
		[](bool is_open, int cond) { ImGui::SetNextItemOpen(is_open, static_cast<ImGuiCond>(cond)); }
	));
	ImGui.set_function("TreeAdvanceToLabelPos", ImGui::TreeAdvanceToLabelPos);
	#pragma endregion

	#pragma region Widgets: Selectables
	ImGui.set_function("Selectable", sol::overload(
		[](const char* label) { return ImGui::Selectable(label); },
		[](const char* label, bool selected) { bool clicked = ImGui::Selectable(label, &selected); return std::make_tuple(selected, clicked); },
		[](const char* label, bool selected, int flags) { bool clicked = ImGui::Selectable(label, &selected, static_cast<ImGuiSelectableFlags>(flags)); return std::make_tuple(selected, clicked); },
		[](const char* label, bool selected, int flags, const ImVec2& size) { bool clicked = ImGui::Selectable(label, &selected, static_cast<ImGuiSelectableFlags>(flags), size); return std::make_tuple(selected, clicked); },
		[](const char* label, bool selected, int flags, float sizeX, float sizeY) { bool clicked = ImGui::Selectable(label, &selected, static_cast<ImGuiSelectableFlags>(flags), { sizeX, sizeY }); return std::make_tuple(selected, clicked); }
	));
	#pragma endregion

	#pragma region Widgets: List Boxes
	ImGui.set_function("BeginListBox", sol::overload(
		[](const char* label) { return ImGui::BeginListBox(label); },
		[](const char* label, const ImVec2& size) { return ImGui::BeginListBox(label, size); }
	));
	ImGui.set_function("EndListBox", &ImGui::EndListBox);
	ImGui.set_function("ListBox", sol::overload(
		sol::resolve<std::tuple<int, bool>(const char*, int, const sol::table&, int)>(ListBox),
		sol::resolve<std::tuple<int, bool>(const char*, int, const sol::table&, int, int)>(ListBox)
	));
	#pragma endregion

	#pragma region Widgets: Value() Helpers
	ImGui.set_function("Value", sol::overload(
		sol::resolve<void(const std::string&, bool)>(Value),
		sol::resolve<void(const std::string&, int)>(Value),
		sol::resolve<void(const std::string&, unsigned int)>(Value),
		sol::resolve<void(const std::string&, float)>(Value),
		sol::resolve<void(const std::string&, float, const std::string&)>(Value)
	));
	#pragma endregion

	#pragma region Widgets: Menu
	ImGui.set_function("BeginMenuBar", &ImGui::BeginMenuBar);
	ImGui.set_function("EndMenuBar", &ImGui::EndMenuBar);
	ImGui.set_function("BeginMainMenuBar", &ImGui::BeginMainMenuBar);
	ImGui.set_function("EndMainMenuBar", &ImGui::EndMainMenuBar);
	ImGui.set_function("BeginMenu", sol::overload(
		[](const char* label) { return ImGui::BeginMenu(label); },
		[](const char* label, bool enabled) { return ImGui::BeginMenu(label, enabled); }
	));
	ImGui.set_function("EndMenu", &ImGui::EndMenu);
	ImGui.set_function("MenuItem",
		[](const char* label, sol::optional<const char*> shortcut, sol::optional<bool> selected, std::optional<bool> enabled) {
			bool value = selected.value_or(false);
			bool activated = ImGui::MenuItem(label, shortcut.value_or(nullptr), &value, enabled.value_or(true));
			return std::make_tuple(activated, selected.has_value() ? value : activated);
		}
	);
	#pragma endregion

	#pragma region Tooltips
	ImGui.set_function("BeginTooltip", BeginTooltip);
	ImGui.set_function("EndTooltip", EndTooltip);
	ImGui.set_function("SetTooltip", SetTooltip);
	#pragma endregion

	#pragma region Popups, Modals
	ImGui.set_function("BeginPopup", sol::overload(
		[](const char* str_id) { return ImGui::BeginPopup(str_id); },
		[](const char* str_id, int flags) { return ImGui::BeginPopup(str_id, ImGuiWindowFlags(flags)); }
	));
	ImGui.set_function("BeginPopupModal", sol::overload(
		[](const char* name) { return ImGui::BeginPopupModal(name); },
		[](const char* name, nullptr_t, int flags) { return ImGui::BeginPopupModal(name, nullptr, flags); },
		[](const char* name, bool open) { bool show = ImGui::BeginPopupModal(name, &open); return std::make_tuple(open, show); },
		[](const char* name, bool open, int flags) { bool show = ImGui::BeginPopupModal(name, &open, ImGuiWindowFlags(flags)); return std::make_tuple(open, show); }
	));
	ImGui.set_function("EndPopup", &ImGui::EndPopup);
	ImGui.set_function("OpenPopup", sol::overload(
		[](const char* str_id) { ImGui::OpenPopup(str_id); },
		[](const char* str_id, int popup_flags) { ImGui::OpenPopup(str_id, ImGuiPopupFlags(popup_flags)); }
	));
	ImGui.set_function("OpenPopupOnItemClick", sol::overload(
		[]() { ImGui::OpenPopupOnItemClick(); },
		[](const char* str_id) { ImGui::OpenPopupOnItemClick(str_id); },
		[](const char* str_id, int flags) { ImGui::OpenPopupOnItemClick(str_id, ImGuiPopupFlags(flags)); }
	));
	ImGui.set_function("CloseCurrentPopup", &ImGui::CloseCurrentPopup);
	ImGui.set_function("BeginPopupContextItem", sol::overload(
		[]() { return ImGui::BeginPopupContextItem(); },
		[](const char* str_id) { return ImGui::BeginPopupContextItem(str_id); },
		[](const char* str_id, int popup_flags) { return ImGui::BeginPopupContextItem(str_id, ImGuiPopupFlags(popup_flags)); }
	));
	ImGui.set_function("BeginPopupContextWindow", sol::overload(
		[]() { return ImGui::BeginPopupContextWindow(); },
		[](const char* str_id) { return ImGui::BeginPopupContextWindow(str_id); },
		[](const char* str_id, int popup_flags) { return ImGui::BeginPopupContextWindow(str_id, ImGuiPopupFlags(popup_flags)); }
	));
	ImGui.set_function("BeginPopupContextVoid", sol::overload(
		[]() { return ImGui::BeginPopupContextVoid(); },
		[](const char* str_id) { return ImGui::BeginPopupContextVoid(str_id); },
		[](const char* str_id, int popup_flags) { return ImGui::BeginPopupContextVoid(str_id, ImGuiPopupFlags(popup_flags)); }
	));
	ImGui.set_function("IsPopupOpen", sol::overload(
		[](const char* str_id) { return ImGui::IsPopupOpen(str_id); },
		[](const char* str_id, int popup_flags) { return ImGui::IsPopupOpen(str_id, popup_flags); }
	));
	#pragma endregion

	#pragma region Tables
	ImGui.set_function("BeginTable", sol::overload(
		sol::resolve<bool(const std::string&, int)>(BeginTable),
		sol::resolve<bool(const std::string&, int, int)>(BeginTable),
		sol::resolve<bool(const std::string&, int, int, float, float)>(BeginTable),
		sol::resolve<bool(const std::string&, int, int, float, float, float)>(BeginTable)
	));
	ImGui.set_function("EndTable", EndTable);
	ImGui.set_function("TableNextRow", sol::overload(
		sol::resolve<void()>(TableNextRow),
		sol::resolve<void(int)>(TableNextRow),
		sol::resolve<void(int, float)>(TableNextRow)
	));
	ImGui.set_function("TableNextColumn", TableNextColumn);
	ImGui.set_function("TableSetColumnIndex", TableSetColumnIndex);

	ImGui.set_function("TableSetupColumn", sol::overload(
		sol::resolve<void(const std::string&)>(TableSetupColumn),
		sol::resolve<void(const std::string&, int)>(TableSetupColumn),
		sol::resolve<void(const std::string&, int, float)>(TableSetupColumn),
		sol::resolve<void(const std::string&, int, float, uint32_t)>(TableSetupColumn)
	));
	ImGui.set_function("TableSetupScrollFreeze", TableSetupScrollFreeze);
	ImGui.set_function("TableHeadersRow", TableHeadersRow);
	ImGui.set_function("TableHeader", TableHeader);

	ImGui.set_function("TableGetColumnCount", TableGetColumnCount);
	ImGui.set_function("TableGetColumnName", sol::overload(
		sol::resolve<std::string()>(TableGetColumnName),
		sol::resolve<std::string(int)>(TableGetColumnName)
	));
	ImGui.set_function("TableGetColumnIsVisible", sol::overload(
		sol::resolve<bool()>(TableGetColumnIsVisible),
		sol::resolve<bool(int)>(TableGetColumnIsVisible)
	));
	ImGui.set_function("TableGetColumnIsSorted", sol::overload(
		sol::resolve<bool()>(TableGetColumnIsSorted),
		sol::resolve<bool(int)>(TableGetColumnIsSorted)
	));
	ImGui.set_function("TableGetHoveredColumn", TableGetHoveredColumn);
	ImGui.set_function("TableGetSortSpecs", TableGetSortSpecs);

	ImGui.set_function("TableSetBgColor", sol::overload(
		sol::resolve<void(int, int)>(TableSetBgColor),
		sol::resolve<void(int, int, int)>(TableSetBgColor),
		sol::resolve<void(int, float, float, float, float)>(TableSetBgColor),
		sol::resolve<void(int, float, float, float, float, int)>(TableSetBgColor)
	));
	#pragma endregion

	#pragma region Columns
	ImGui.set_function("Columns", sol::overload(
		sol::resolve<void()>(Columns),
		sol::resolve<void(int)>(Columns),
		sol::resolve<void(int, const std::string&)>(Columns),
		sol::resolve<void(int, const std::string&, bool)>(Columns)
	));
	ImGui.set_function("NextColumn", NextColumn);
	ImGui.set_function("GetColumnIndex", GetColumnIndex);
	ImGui.set_function("GetColumnWidth", sol::overload(
		sol::resolve<float()>(GetColumnWidth),
		sol::resolve<float(int)>(GetColumnWidth)
	));
	ImGui.set_function("SetColumnWidth", SetColumnWidth);
	ImGui.set_function("GetColumnOffset", sol::overload(
		sol::resolve<float()>(GetColumnOffset),
		sol::resolve<float(int)>(GetColumnOffset)
	));
	ImGui.set_function("SetColumnOffset", SetColumnOffset);
	ImGui.set_function("GetColumnsCount", GetColumnsCount);
	#pragma endregion

	#pragma region Tab Bars, Tabs
	ImGui.set_function("BeginTabBar", sol::overload(
		sol::resolve<bool(const std::string&)>(BeginTabBar),
		sol::resolve<bool(const std::string&, int)>(BeginTabBar)
	));
	ImGui.set_function("EndTabBar", EndTabBar);
	ImGui.set_function("BeginTabItem", sol::overload(
		sol::resolve<bool(const std::string&)>(BeginTabItem),
		sol::resolve<std::tuple<bool, bool>(const std::string&, bool)>(BeginTabItem),
		sol::resolve<std::tuple<bool, bool>(const std::string&, bool, int)>(BeginTabItem)
	));
	ImGui.set_function("EndTabItem", EndTabItem);
	ImGui.set_function("SetTabItemClosed", SetTabItemClosed);
	#pragma endregion

	#pragma region Docking
	ImGui.set_function("DockSpace", sol::overload(
		[](ImGuiID id) { ImGui::DockSpace(id); },
		[](ImGuiID id, float sizeX, float sizeY) { ImGui::DockSpace(id, { sizeX, sizeY }); },
		[](ImGuiID id, float sizeX, float sizeY, int flags) { ImGui::DockSpace(id, { sizeX, sizeY }, ImGuiDockNodeFlags(flags)); },
		[](ImGuiID id, const ImVec2& size) { ImGui::DockSpace(id, size); },
		[](ImGuiID id, const ImVec2& size, int flags) { ImGui::DockSpace(id, size, ImGuiDockNodeFlags(flags)); }
	));
	ImGui.set_function("SetNextWindowDockID", sol::overload(
		sol::resolve<void(unsigned int)>(SetNextWindowDockID),
		sol::resolve<void(unsigned int, int)>(SetNextWindowDockID)
	));
	ImGui.set_function("GetWindowDockID", GetWindowDockID);
	ImGui.set_function("IsWindowDocked", IsWindowDocked);
	#pragma endregion Docking

	#pragma region Drag Drop
	ImGui.new_usertype<LuaImGuiPayload>(
		"ImGuiPayload", sol::no_constructor,
		"Data", sol::readonly(&LuaImGuiPayload::Data)
		//"Data", [](const ImGuiPayload* self)
		//{
		//    return *static_cast<sol::object*>(self->Data);
		//},
		//"DataSize", sol::readonly(&ImGuiPayload::DataSize),
		//"SourceId", sol::readonly(&ImGuiPayload::SourceId),
		//"SourceParentId", sol::readonly(&ImGuiPayload::SourceParentId),
		//"DataFrameCount", sol::readonly(&ImGuiPayload::DataFrameCount),
		//"DataType", sol::readonly(&ImGuiPayload::DataType),
		//"Preview", sol::readonly(&ImGuiPayload::Preview),
		//"Delivery", sol::readonly(&ImGuiPayload::Delivery),
		//"Clear", &ImGuiPayload::Clear,
		//"IsDataType", &ImGuiPayload::IsDataType,
		//"IsPreview", &ImGuiPayload::IsPreview,
		//"IsDelivery", &ImGuiPayload::IsDelivery
		);
	ImGui.set_function("BeginDragDropSource", sol::overload(
		sol::resolve<bool()>(BeginDragDropSource),
		sol::resolve<bool(int)>(BeginDragDropSource)
	));
	ImGui.set_function("SetDragDropPayload", sol::overload(
		sol::resolve<bool(const std::string&, sol::object, int)>(SetDragDropPayload),
		sol::resolve<bool(const std::string&, sol::object)>(SetDragDropPayload)
	));
	ImGui.set_function("EndDragDropSource", EndDragDropSource);
	ImGui.set_function("BeginDragDropTarget", BeginDragDropTarget);
	ImGui.set_function("AcceptDragDropPayload", sol::overload(
		sol::resolve<std::unique_ptr<LuaImGuiPayload>(const std::string&, int)>(AcceptDragDropPayload),
		sol::resolve<std::unique_ptr<LuaImGuiPayload>(const std::string&)>(AcceptDragDropPayload)
	));
	ImGui.set_function("EndDragDropTarget", EndDragDropTarget);
	ImGui.set_function("GetDragDropPayload", GetDragDropPayload);
	#pragma endregion
}

} // namespace mq::lua::bindings
