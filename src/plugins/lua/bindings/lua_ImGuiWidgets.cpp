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
#include "lua_Bindings.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <optional>
#include <string>

namespace mq::lua::bindings {

//============================================================================

std::string format_text(sol::this_state s, sol::variadic_args va);

#pragma region Widgets: Combo Box
// Widgets: Combo Box

// Combo 1: Takes a string containing null separated items
static std::tuple<int, bool> Combo1(const char* label, int currentItem, const char* itemsSeparatedByZeros, std::optional<int> popupMaxHeightInItems)
{
	currentItem -= 1;
	bool clicked = ImGui::Combo(label, &currentItem, itemsSeparatedByZeros, popupMaxHeightInItems.value_or(-1));
	return std::make_tuple(currentItem + 1, clicked);
}

// Combo 2: Takes list of items
static std::tuple<int, bool> Combo2(const char* label, int currentItem, const sol::table& items, std::optional<int> itemsCount, std::optional<int> popupMaxHeightInItems)
{
	std::vector<const char*> strings;
	int count = itemsCount.value_or(items.size());
	strings.reserve(count);

	for (int i = 1; i <= count; i++)
	{
		std::optional<const char*> stringItem = items.get<std::optional<const char*>>(i);
		strings.push_back(stringItem.value_or("Missing Value"));
	}

	currentItem -= 1;
	bool clicked = ImGui::Combo(label, &currentItem, strings.data(), count, popupMaxHeightInItems.value_or(-1));
	return std::make_tuple(currentItem + 1, clicked);
}

static bool LuaComboGetter(void* ptr, int idx, const char** out_text)
{
	auto& getter = *static_cast<sol::function*>(ptr);

	sol::function_result result = getter(idx + 1);
	std::optional<const char*> value = result.get<std::optional<const char*>>();

	if (!value.has_value())
		return false;

	*out_text = *value;
	return true;
}

// Combo 3: Takes callback function to get list of items
static std::tuple<int, bool> Combo3(const char* label, int currentItem, sol::function getter, int itemsCount, std::optional<int> popupMaxHeightInItems)
{
	currentItem -= 1;

	bool clicked = ImGui::Combo(label, &currentItem, LuaComboGetter, &getter, itemsCount, popupMaxHeightInItems.value_or(-1));
	return std::make_tuple(currentItem + 1, clicked);
}
#pragma endregion

#pragma region Widgets: Drag Sliders
// Widgets: Drag Sliders

static std::tuple<float, bool> DragFloat(const char* label, float v,
	std::optional<float> v_speed, std::optional<float> v_min, std::optional<float> v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::DragFloat(label, &v, v_speed.value_or(1.0f), v_min.value_or(0.0f), v_max.value_or(0.0f), format.value_or("%.3f"), flags.value_or(0));
	return std::make_tuple(v, changed);
}

static std::tuple<float, bool> DragFloat_Obsolete(const char* label, float v, float v_speed, float v_min, float v_max, const char* format, float power)
{
	return DragFloat(label, v, v_speed, v_min, v_max, format, power != 1.0f ? ImGuiSliderFlags_Logarithmic : ImGuiSliderFlags_None);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloatN(const char* label, const sol::table& v,
	std::optional<float> v_speed, std::optional<float> v_min, std::optional<float> v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	float value[N];
	for (int i = 0; i < N; ++i)
		value[i] = (float)v[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;

	if constexpr (N == 2)
		changed = ImGui::DragFloat2(label, value, v_speed.value_or(1.0f), v_min.value_or(0.0f), v_max.value_or(0.0f), format.value_or("%.3f"), flags.value_or(0));
	else if constexpr (N == 3)
		changed = ImGui::DragFloat3(label, value, v_speed.value_or(1.0f), v_min.value_or(0.0f), v_max.value_or(0.0f), format.value_or("%.3f"), flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::DragFloat4(label, value, v_speed.value_or(1.0f), v_min.value_or(0.0f), v_max.value_or(0.0f), format.value_or("%.3f"), flags.value_or(0));

	sol::as_table_t float2 = sol::as_table(std::vector<float>(std::begin(value), std::end(value)));

	return std::make_tuple(float2, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> DragFloatN_Obsolete(
	const char* label, const sol::table& v, float v_speed, float v_min, float v_max, const char* format, float power)
{
	return DragFloatN<N>(label, v, v_speed, v_min, v_max, format, power != 1.0f ? ImGuiSliderFlags_Logarithmic : ImGuiSliderFlags_None);
}

static std::tuple<float, float, bool> DragFloatRange2(const char* label, float v_current_min, float v_current_max, std::optional<float> v_speed,
	std::optional<float> v_min, std::optional<float> v_max, std::optional<const char*> format,
	std::optional<const char*> format_max, std::optional<int> flags)
{
	bool changed = ImGui::DragFloatRange2(label, &v_current_min, &v_current_max, v_speed.value_or(1.0f), v_min.value_or(0.0f), v_max.value_or(0.0f), format.value_or("%.3f"),
		format_max.value_or(nullptr), flags.value_or(0));

	return std::make_tuple(v_current_min, v_current_max, changed);
}

static std::tuple<int, bool> DragInt(const char* label, int v,
	std::optional<float> v_speed, std::optional<int> v_min, std::optional<int> v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::DragInt(label, &v, v_speed.value_or(1.0f), v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));
	return std::make_tuple(v, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<int>>, bool> DragIntN(const char* label, const sol::table& v,
	std::optional<float> v_speed, std::optional<int> v_min, std::optional<int> v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	int value[N];
	for (int i = 0; i < N; ++i)
		value[i] = (int)v[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;
	if constexpr (N == 2)
		changed = ImGui::DragInt2(label, value, v_speed.value_or(1.0f), v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));
	if constexpr (N == 3)
		changed = ImGui::DragInt3(label, value, v_speed.value_or(1.0f), v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));
	if constexpr (N == 4)
		changed = ImGui::DragInt4(label, value, v_speed.value_or(1.0f), v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));

	sol::as_table_t int2 = sol::as_table(std::vector<int>(std::begin(value), std::end(value)));

	return std::make_tuple(int2, changed);
}

static std::tuple<int, int, bool> DragIntRange2(const char* label, int v_current_min, int v_current_max, std::optional<float> v_speed,
	std::optional<int> v_min, std::optional<int> v_max, std::optional<const char*> format,
	std::optional<const char*> format_max, std::optional<int> flags)
{
	bool changed = ImGui::DragIntRange2(label, &v_current_min, &v_current_max, v_speed.value_or(1.0f), v_min.value_or(0), v_max.value_or(0), format.value_or("%d"),
		format_max.value_or(nullptr), flags.value_or(0));

	return std::make_tuple(v_current_min, v_current_max, changed);
}

template <typename T>
static std::tuple<sol::object, bool> DragScalarNT(sol::this_state L, const char* label, int dataType, sol::table table, int components, std::optional<float> v_speed, std::optional<double> p_min, std::optional<double> p_max, std::optional<const char*> format, std::optional<int> flags)
{
	std::vector<T> data = table.as<std::vector<T>>();
	data.resize(components, T());

	T min_val = (T)(p_min.value_or(0));
	T max_val = (T)(p_max.value_or(0));

	bool changed = ImGui::DragScalarN(label, dataType, data.data(), components, v_speed.value_or(1), p_min.has_value() ? &min_val : nullptr, p_max.has_value() ? &max_val : nullptr, format.value_or(nullptr), flags.value_or(0));

	sol::table t = sol::state_view(L).create_table();
	for (T v : data)
		t.add(v);

	return std::make_tuple(t, changed);
}

static std::tuple<sol::object, bool> DragScalarN(const char* label, int dataType, sol::table data, int components, std::optional<float> v_speed, std::optional<double> p_min, std::optional<double> p_max, std::optional<const char*> format, std::optional<int> flags, sol::this_state L)
{
	switch (dataType)
	{
	case ImGuiDataType_S8:
		return DragScalarNT<int8_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_U8:
		return DragScalarNT<uint8_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_S16:
		return DragScalarNT<int16_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_U16:
		return DragScalarNT<uint16_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_S32:
		return DragScalarNT<int32_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_U32:
		return DragScalarNT<uint32_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_S64:
		return DragScalarNT<int64_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_U64:
		return DragScalarNT<uint16_t>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_Float:
		return DragScalarNT<float>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	case ImGuiDataType_Double:
		return DragScalarNT<double>(L, label, dataType, data, components, v_speed, p_min, p_max, format, flags);
	default:
		luaL_error(L, "Invalid datatype: %d", dataType);
	}

	return std::make_tuple(sol::nil, false);
}

#pragma endregion

#pragma region Widgets: Sliders
// Widgets: Sliders

static std::tuple<float, bool> SliderFloat(const char* label, float v,
	std::optional<float> v_min, std::optional<float> v_max, std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::SliderFloat(label, &v, v_min.value_or(0.0f), v_max.value_or(0.0f), format.value_or("%.3f"), flags.value_or(0));
	return std::make_tuple(v, changed);
}

static std::tuple<float, bool> SliderFloat_Obsolete(const char* label, float v, float v_min, float v_max, const char* format, float power)
{
	return SliderFloat(label, v, v_min, v_max, format, power != 1.0f ? ImGuiSliderFlags_Logarithmic : ImGuiSliderFlags_None);
}

static std::tuple<ImVec2, bool> SliderFloat2_ImVec2(const char* label, ImVec2 value, float v_min, float v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::SliderFloat2(label, &value.x, v_min, v_max, format.value_or("%.3f"), flags.value_or(0));
	return std::make_tuple(value, changed);
}

static std::tuple<ImVec4, bool> SliderFloat4_ImVec4(const char* label, ImVec4 value, float v_min, float v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::SliderFloat4(label, &value.x, v_min, v_max, format.value_or("%.3f"), flags.value_or(0));
	return std::make_tuple(value, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloatN(const char* label, const sol::table& v,
	float v_min, float v_max, std::optional<const char*> format, std::optional<int> flags)
{
	float value[N];
	for (int i = 0; i < N; ++i)
		value[i] = (float)v[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;

	if constexpr (N == 2)
		changed = ImGui::SliderFloat2(label, value, v_min, v_max, format.value_or("%.3f"), flags.value_or(0));
	else if constexpr (N == 3)
		changed = ImGui::SliderFloat3(label, value, v_min, v_max, format.value_or("%.3f"), flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::SliderFloat4(label, value, v_min, v_max, format.value_or("%.3f"), flags.value_or(0));

	sol::as_table_t float2 = sol::as_table(std::vector<float>(std::begin(value), std::end(value)));

	return std::make_tuple(float2, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> SliderFloatN_Obsolete(
	const char* label, const sol::table& v, float v_min, float v_max, const char* format, float power)
{
	return SliderFloatN<N>(label, v, v_min, v_max, format, power != 1.0f ? ImGuiSliderFlags_Logarithmic : ImGuiSliderFlags_None);
}

static std::tuple<int, bool> SliderInt(const char* label, int v,
	std::optional<int> v_min, std::optional<int> v_max, std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::SliderInt(label, &v, v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));
	return std::make_tuple(v, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<int>>, bool> SliderIntN(const char* label, const sol::table& v,
	std::optional<int> v_min, std::optional<int> v_max, std::optional<const char*> format, std::optional<int> flags)
{
	int value[N];
	for (int i = 0; i < N; ++i)
		value[i] = (int)v[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;
	if constexpr (N == 2)
		changed = ImGui::SliderInt2(label, value, v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));
	if constexpr (N == 3)
		changed = ImGui::SliderInt3(label, value, v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));
	if constexpr (N == 4)
		changed = ImGui::SliderInt4(label, value, v_min.value_or(0), v_max.value_or(0), format.value_or("%d"), flags.value_or(0));

	sol::as_table_t int2 = sol::as_table(std::vector<int>(std::begin(value), std::end(value)));

	return std::make_tuple(int2, changed);
}

static std::tuple<float, bool> SliderAngle(const char* label, float v_rad,
	std::optional<float> v_degrees_min, std::optional<float> v_degrees_max, std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::SliderAngle(label, &v_rad, v_degrees_min.value_or(-360.0f), v_degrees_max.value_or(360.0f), format.value_or("%.0f deg"), flags.value_or(0));

	return std::make_tuple(v_rad, changed);
}

static std::tuple<float, bool> VSliderFloatVec2(const char* label, const ImVec2& size, float value, float v_min, float v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::VSliderFloat(label, size, &value, v_min, v_max, format.value_or("%.3f"), flags.value_or(0));
	return std::make_tuple(value, changed);
}

static std::tuple<float, bool> VSliderFloat(const char* label, float sizeX, float sizeY, float value, float v_min, float v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	return VSliderFloatVec2(label, { sizeX, sizeY }, value, v_min, v_max, format, flags);
}

static std::tuple<int, bool> VSliderIntVec2(const char* label, const ImVec2& size, int value, int v_min, int v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::VSliderInt(label, size, &value, v_min, v_max, format.value_or("%d"), flags.value_or(0));
	return std::make_tuple(value, changed);
}

static std::tuple<int, bool> VSliderInt(const char* label, float sizeX, float sizeY, int value, int v_min, int v_max,
	std::optional<const char*> format, std::optional<int> flags)
{
	return VSliderIntVec2(label, { sizeX, sizeY }, value, v_min, v_max, format, flags);
}
#pragma endregion

#pragma region Widgets: Input with Keyboard
// Widgets: Input with Keyboard
static int LuaInputTextCallback(ImGuiInputTextCallbackData* data)
{
	auto& getter = *static_cast<sol::function*>(data->UserData);
	ImGuiInputTextFlags EventFlag = data->EventFlag;

	sol::function_result result = getter(EventFlag, data);
	std::optional<int> value = result.get<std::optional<int>>();

	return value.value_or(0);
}

static std::tuple<std::string, bool> InputText1(const char* label, std::string text, std::optional<int> flags, std::optional<sol::function> callback)
{
	bool changed = false;

	if (callback.has_value())
	{
		sol::function func = callback.value();
		changed = ImGui::InputText(label, &text, flags.value_or(0), LuaInputTextCallback, &func);
	}
	else
	{
		changed = ImGui::InputText(label, &text, flags.value_or(0));
	}

	return std::make_tuple(text, changed);
}

static std::tuple<std::string, bool> InputTextMultiline1(const char* label, std::string text, float sizeX, float sizeY, std::optional<int> flags, std::optional<sol::function> callback)
{
	bool changed = false;
	if (callback.has_value())
	{
		sol::function func = callback.value();
		changed = ImGui::InputTextMultiline(label, &text, { sizeX, sizeY }, flags.value_or(0), LuaInputTextCallback, &func);
	}
	else
	{
		changed = ImGui::InputTextMultiline(label, &text, { sizeX, sizeY }, flags.value_or(0));
	}

	return std::make_tuple(text, changed);
}

static std::tuple<std::string, bool> InputTextMultiline2(const char* label, std::string text, std::optional<ImVec2> size, std::optional<int> flags, std::optional<sol::function> callback)
{
	bool changed = false;
	if (callback.has_value())
	{
		sol::function func = callback.value();
		changed = ImGui::InputTextMultiline(label, &text, size.value_or(ImVec2(0, 0)), flags.value_or(0), LuaInputTextCallback, &func);
	}
	else
	{
		changed = ImGui::InputTextMultiline(label, &text, size.value_or(ImVec2(0, 0)), flags.value_or(0));
	}

	return std::make_tuple(text, changed);
}

static std::tuple<std::string, bool> InputTextWithHint(const char* label, const char* hint, std::string text, std::optional<int> flags, std::optional<sol::function> callback)
{
	bool changed = false;
	if (callback.has_value())
	{
		sol::function func = callback.value();
		changed = ImGui::InputTextWithHint(label, hint, &text, flags.value_or(0), LuaInputTextCallback, &func);
	}
	else
	{
		changed = ImGui::InputTextWithHint(label, hint, &text, flags.value_or(0));
	}

	return std::make_tuple(text, changed);
}

static std::tuple<float, bool> InputFloat(const char* label, float value, std::optional<float> step, std::optional<float> step_fast,
	std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::InputFloat(label, &value, step.value_or(0.0f), step_fast.value_or(0.0f), format.value_or("%.3f"), flags.value_or(0));
	return std::make_tuple(value, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> InputFloatN(const char* label, const sol::table& v,
	std::optional<const char*> format, std::optional<int> flags)
{
	float value[N];
	for (int i = 0; i < N; ++i)
		value[i] = (float)v[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;

	if constexpr (N == 2)
		changed = ImGui::InputFloat2(label, value, format.value_or("%.3f"), flags.value_or(0));
	else if constexpr (N == 3)
		changed = ImGui::InputFloat3(label, value, format.value_or("%.3f"), flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::InputFloat4(label, value, format.value_or("%.3f"), flags.value_or(0));

	sol::as_table_t float2 = sol::as_table(std::vector<float>(std::begin(value), std::end(value)));

	return std::make_tuple(float2, changed);
}

static std::tuple<int, bool> InputInt(const char* label, int value, std::optional<int> step, std::optional<int> step_fast, std::optional<int> flags)
{
	bool changed = ImGui::InputInt(label, &value, step.value_or(1), step_fast.value_or(100), flags.value_or(0));
	return std::make_tuple(value, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<int>>, bool> InputIntN(const char* label, const sol::table& v, std::optional<int> flags)
{
	int value[N];
	for (int i = 0; i < N; ++i)
		value[i] = (int)v[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;

	if constexpr (N == 2)
		changed = ImGui::InputInt2(label, value, flags.value_or(0));
	else if constexpr (N == 3)
		changed = ImGui::InputInt3(label, value, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::InputInt4(label, value, flags.value_or(0));

	sol::as_table_t int2 = sol::as_table(std::vector<int>(std::begin(value), std::end(value)));
	return std::make_tuple(int2, changed);
}

static std::tuple<double, bool> InputDouble(const char* label, double value,
	std::optional<double> step, std::optional<double> step_fast, std::optional<const char*> format, std::optional<int> flags)
{
	bool changed = ImGui::InputDouble(label, &value, step.value_or(0.0), step_fast.value_or(0.0), format.value_or("%.6f"), flags.value_or(0));
	return std::make_tuple(value, changed);
}
#pragma endregion

#pragma region Widgets: Color Editor / Picker
// Widgets: Color Editor / Picker
template <int N>
static std::tuple<ImVec4, bool> ColorEditN1(const char* label, ImVec4 col, std::optional<int> flags)
{
	bool changed = false;
	if constexpr (N == 3)
		changed = ImGui::ColorEdit3(label, &col.x, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::ColorEdit4(label, &col.x, flags.value_or(0));

	return std::make_tuple(col, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorEditN2(const char* label, const sol::table& col, std::optional<int> flags)
{
	float color[N];
	for (int i = 0; i < N; ++i)
		color[i] = (float)col[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;
	if constexpr (N == 3)
		changed = ImGui::ColorEdit3(label, color, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::ColorEdit4(label, color, flags.value_or(0));

	sol::as_table_t rgb = sol::as_table(std::vector<float>(std::begin(color), std::end(color)));
	return std::make_tuple(rgb, changed);
}

template <int N>
static std::tuple<ImU32, bool> ColorEditN3(const char* label, ImU32 col, std::optional<int> flags)
{
	ImVec4 vec4 = ImGui::ColorConvertU32ToFloat4(col);

	bool changed = false;
	if constexpr (N == 3)
		changed = ImGui::ColorEdit3(label, &vec4.x, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::ColorEdit4(label, &vec4.x, flags.value_or(0));

	return std::make_tuple(ImGui::ColorConvertFloat4ToU32(vec4), changed);
}

template <int N>
static std::tuple<ImVec4, bool> ColorPickerN1(const char* label, ImVec4 col, std::optional<int> flags)
{
	bool changed = false;
	if constexpr (N == 3)
		changed = ImGui::ColorPicker3(label, &col.x, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::ColorPicker4(label, &col.x, flags.value_or(0));

	return std::make_tuple(col, changed);
}

template <int N>
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorPickerN2(const char* label, const sol::table& col, std::optional<int> flags)
{
	float color[N];
	for (int i = 0; i < N; ++i)
		color[i] = (float)col[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	bool changed = false;
	if constexpr (N == 3)
		changed = ImGui::ColorPicker3(label, color, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::ColorPicker4(label, color, flags.value_or(0));

	sol::as_table_t rgb = sol::as_table(std::vector<float>(std::begin(color), std::end(color)));
	return std::make_tuple(rgb, changed);
}

template <int N>
static std::tuple<ImU32, bool> ColorPickerN3(const char* label, ImU32 col, std::optional<int> flags)
{
	ImVec4 vec4 = ImGui::ColorConvertU32ToFloat4(col);

	bool changed = false;
	if constexpr (N == 3)
		changed = ImGui::ColorPicker3(label, &vec4.x, flags.value_or(0));
	else if constexpr (N == 4)
		changed = ImGui::ColorPicker4(label, &vec4.x, flags.value_or(0));

	return std::make_tuple(ImGui::ColorConvertFloat4ToU32(vec4), changed);
}

static bool ColorButton1(const char* desc_id, const ImVec4& color, std::optional<int> flags, std::optional<ImVec2> size)
{
	return ImGui::ColorButton(desc_id, color, flags.value_or(0), size.value_or(ImVec2(0, 0)));
}

static bool ColorButton2(const char* desc_id, const sol::table& col, std::optional<int> flags, std::optional<ImVec2> size)
{
	ImVec4 color;
	for (int i = 0; i < 4; ++i)
		(&color.x)[i] = (float)col[i + 1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0));

	return ImGui::ColorButton(desc_id, color, flags.value_or(0), size.value_or(ImVec2(0, 0)));
}

static bool ColorButton3(const char* desc_id, ImU32 color, std::optional<int> flags, std::optional<ImVec2> size)
{
	ImVec4 vec4 = ImGui::ColorConvertU32ToFloat4(color);

	return ImGui::ColorButton(desc_id, vec4, flags.value_or(0), size.value_or(ImVec2(0, 0)));
}
#pragma endregion

#pragma region Widgets: List Boxes
// Widgets: List Boxes
static std::tuple<int, bool> ListBox1(const char* label, int current_item, const sol::table& items, std::optional<int> items_count, std::optional<int> height_in_items)
{
	std::vector<const char*> strings;
	int count = items_count.value_or(items.size());
	strings.reserve(count);

	for (int i = 1; i <= count; i++)
	{
		std::optional<const char*> stringItem = items.get<std::optional<const char*>>(i);
		strings.push_back(stringItem.value_or("Missing String"));
	}

	current_item -= 1;
	bool changed = ImGui::ListBox(label, &current_item, strings.data(), count, height_in_items.value_or(-1));
	return std::make_tuple(current_item + 1, changed);
}

static const char* LuaListboxGetter(void* ptr, int idx)
{
	auto& getter = *static_cast<sol::function*>(ptr);

	sol::function_result result = getter(idx + 1);
	std::optional<const char*> value = result.get<std::optional<const char*>>();

	return value.value_or("");
}

static std::tuple<int, bool> ListBox2(const char* label, int current_item, sol::function getter, int itemsCount, std::optional<int> height_in_items)
{
	current_item -= 1;
	bool changed = ImGui::ListBox(label, &current_item, LuaListboxGetter, &getter, itemsCount, height_in_items.value_or(-1));
	return std::make_tuple(current_item + 1, changed);
}
#pragma endregion

#pragma region Widgets:: Data Plotting
static void PlotLines1(const char* label, const sol::table& values_, std::optional<int> values_count, std::optional<int> values_offset,
	std::optional<const char*> overlay_text, std::optional<float> scale_min, std::optional<float> scale_max, std::optional<ImVec2> graph_size)
{
	std::vector<float> values;
	int count = values_count.value_or(values_.size());
	values.reserve(count);

	for (int i = 1; i <= count; i++)
	{
		values.push_back(values_.get<std::optional<float>>(i).value_or(0.0f));
	}

	ImGui::PlotLines(label, values.data(), count, values_offset.value_or(0), overlay_text.value_or(nullptr),
		scale_min.value_or(FLT_MAX), scale_max.value_or(FLT_MAX), graph_size.value_or(ImVec2(0, 0)), sizeof(float));
}

static float LuaPlotLinesGetter(void* ptr, int idx)
{
	auto& getter = *static_cast<sol::function*>(ptr);

	sol::function_result result = getter(idx + 1);
	std::optional<float> value = result.get<std::optional<float>>();

	return value.value_or(0.0f);
}

static void PlotLines2(const char* label, sol::function getter, int values_count, std::optional<int> values_offset,
	std::optional<const char*> overlay_text, std::optional<float> scale_min, std::optional<float> scale_max,
	std::optional<ImVec2> graph_size)
{
	ImGui::PlotLines(label, LuaPlotLinesGetter, &getter, values_count, values_offset.value_or(0), overlay_text.value_or(nullptr),
		scale_min.value_or(FLT_MAX), scale_max.value_or(FLT_MAX), graph_size.value_or(ImVec2(0, 0)));
}

static void PlotHistogram1(const char* label, const sol::table& values_, std::optional<int> values_count, std::optional<int> values_offset,
	std::optional<const char*> overlay_text, std::optional<float> scale_min, std::optional<float> scale_max, std::optional<ImVec2> graph_size)
{
	std::vector<float> values;
	int count = values_count.value_or(values_.size());
	values.reserve(count);

	for (int i = 1; i <= count; i++)
	{
		values.push_back(values_.get<std::optional<float>>(i).value_or(0.0f));
	}

	ImGui::PlotHistogram(label, values.data(), count, values_offset.value_or(0), overlay_text.value_or(nullptr),
		scale_min.value_or(FLT_MAX), scale_max.value_or(FLT_MAX), graph_size.value_or(ImVec2(0, 0)), sizeof(float));
}

static void PlotHistogram2(const char* label, sol::function getter, int values_count, std::optional<int> values_offset,
	std::optional<const char*> overlay_text, std::optional<float> scale_min, std::optional<float> scale_max,
	std::optional<ImVec2> graph_size)
{
	ImGui::PlotHistogram(label, LuaPlotLinesGetter, &getter, values_count, values_offset.value_or(0), overlay_text.value_or(nullptr),
		scale_min.value_or(FLT_MAX), scale_max.value_or(FLT_MAX), graph_size.value_or(ImVec2(0, 0)));
}
#pragma endregion

void RegisterBindings_ImGuiWidgets(sol::table& ImGui)
{
	#pragma region Widgets: Text
	ImGui.set_function("TextUnformatted", [](std::string_view text) { ImGui::TextUnformatted(text.data(), text.data() + text.size()); });
	ImGui.set_function("Text", sol::overload(
		[](std::string_view text) { ImGui::TextUnformatted(text.data(), text.data() + text.size()); },
		[](sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::Text("%s", text.c_str()); }
	));
	ImGui.set_function("TextColored", sol::overload(
		[](float r, float g, float b, float a, const char* text) { ImGui::TextColored({ r, g, b, a }, "%s", text); },
		[](float r, float g, float b, float a, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::TextColored({ r, g, b, a }, "%s", text.c_str()); },
		[](int col, const char* text) { ImGui::TextColored(ImColor(col), "%s", text); },
		[](int col, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::TextColored(ImColor(col), "%s", text.c_str()); },
		[](const ImVec4& col, const char* text) { ImGui::TextColored(col, "%s", text); },
		[](const ImVec4& col, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::TextColored(col, "%s", text.c_str()); }
	));
	ImGui.set_function("TextDisabled", sol::overload(
		[](const char* text) { ImGui::TextDisabled("%s", text); },
		[](sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::TextDisabled("%s", text.c_str()); }
	));
	ImGui.set_function("TextWrapped", sol::overload(
		[](const char* text) { ImGui::TextWrapped("%s", text); },
		[](sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::Text("%s", text.c_str()); }
	));
	ImGui.set_function("LabelText", sol::overload(
		[](const char* label, const char* text) { ImGui::LabelText(label, "%s", text); },
		[](const char* label, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::LabelText(label, "%s", text.c_str()); }
	));
	ImGui.set_function("BulletText", sol::overload(
		[](const char* text) { ImGui::BulletText("%s", text); },
		[](sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::BulletText("%s", text.c_str()); }
	));
	ImGui.set_function("SeparatorText", sol::overload(
		[](const char* text) { ImGui::SeparatorText(text); },
		[](sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::SeparatorText(text.c_str()); }
	));
	#pragma endregion

	#pragma region Widgets: Main
	ImGui.set_function("Button", sol::overload(
		[](const char* label, std::optional<ImVec2> size) { return ImGui::Button(label, size.value_or(ImVec2(0, 0))); },
		[](const char* label, float sizeX, float sizeY) { return ImGui::Button(label, { sizeX, sizeY }); }
	));
	ImGui.set_function("SmallButton", &ImGui::SmallButton);
	ImGui.set_function("InvisibleButton", sol::overload(
		[](const char* str_id, float sizeX, float sizeY, std::optional<int> flags) { return ImGui::InvisibleButton(str_id, { sizeX, sizeY }, flags.value_or(0)); },
		[](const char* str_id, const ImVec2& size, std::optional<int> flags) { return ImGui::InvisibleButton(str_id, size, flags.value_or(0)); }
	));
	ImGui.set_function("ArrowButton", &ImGui::ArrowButton);
	ImGui.set_function("Checkbox", [](const char* label, bool v) -> std::tuple<bool, bool> { bool value = v; bool pressed = ImGui::Checkbox(label, &value); return std::make_tuple(value, pressed); });
	ImGui.set_function("CheckboxFlags", [](const char* label, uint32_t flags, uint32_t flagsValue) -> std::tuple<uint32_t, bool> { uint32_t mutableFlags = flags; bool pressed = ImGui::CheckboxFlags(label, &mutableFlags, flagsValue); return std::make_tuple(mutableFlags, pressed); });
	ImGui.set_function("RadioButton", sol::overload(
		[](const char* label, bool active) { return ImGui::RadioButton(label, active); },
		[](const char* label, int v, int vButton) -> std::tuple<int, bool> { bool ret = ImGui::RadioButton(label, &v, vButton); return std::make_tuple(v, ret); }
	));
	ImGui.set_function("ProgressBar", sol::overload(
		[](float fraction, std::optional<ImVec2> size, std::optional<const char*> overlay) { ImGui::ProgressBar(fraction, size.value_or(ImVec2(-FLT_MIN, 0)), overlay.value_or(nullptr)); },
		[](float fraction, float sizeX, float sizeY, std::optional<const char*> overlay) { ImGui::ProgressBar(fraction, { sizeX, sizeY }, overlay.value_or(nullptr)); }
	));
	ImGui.set_function("Bullet", &ImGui::Bullet);
	ImGui.set_function("TextLink", sol::overload(
		[](const char* text) { ImGui::TextLink(text); },
		[](sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); ImGui::TextLink(text.c_str()); }
	));
	ImGui.set_function("TextLinkOpenURL", sol::overload(
		[](const char* text, const char* url) { ImGui::TextLinkOpenURL(text, url); },
		[](const char* text) { ImGui::TextLinkOpenURL(text); }
	));
	#pragma endregion

	#pragma region Widgets: Images
	ImGui.set_function("Image", sol::overload(
		[](const ImTextureRef& tex_ref, const ImVec2& image_size, std::optional<ImVec2> uv0, std::optional<ImVec2> uv1)
		{
			ImGui::Image(tex_ref, image_size, uv0.value_or(ImVec2(0, 0)), uv1.value_or(ImVec2(1, 1)));
		},
		// DEPRECATED
		[](const ImTextureRef& tex_ref, const ImVec2& size, std::optional<ImVec2> uv0, std::optional<ImVec2> uv1,
			std::optional<ImVec4> tint_col, std::optional<ImVec4> border_col)
		{
			ImGui::Image(tex_ref, size, uv0.value_or(ImVec2(0, 0)), uv1.value_or(ImVec2(1, 1)), tint_col.value_or(ImVec4(1, 1, 1, 1)), border_col.value_or(ImVec4(0, 0, 0, 0)));
		}
	));
	ImGui.set_function("ImageWithBg",
		[](const ImTextureRef& tex_ref, const ImVec2& image_size, std::optional<ImVec2> uv0, std::optional<ImVec2> uv1,
			std::optional<ImVec4> bg_col, std::optional<ImVec4> tint_col)
		{
			ImGui::ImageWithBg(tex_ref, image_size, uv0.value_or(ImVec2(0, 0)), uv1.value_or(ImVec2(1, 1)), 
				bg_col.value_or(ImVec4(0, 0, 0, 0)), tint_col.value_or(ImVec4(1, 1, 1, 1)));
		});
	ImGui.set_function("ImageButton", sol::overload(
		[](const char* str_id, const ImTextureRef& tex_ref, const ImVec2& image_size, std::optional<ImVec2> uv0, std::optional<ImVec2> uv1,
			std::optional<ImVec4> bg_col, std::optional<ImVec4> tint_col)
		{
			return ImGui::ImageButton(str_id, tex_ref, image_size, uv0.value_or(ImVec2(0, 0)), uv1.value_or(ImVec2(1, 1)),
				bg_col.value_or(ImVec4(0, 0, 0, 0)), tint_col.value_or(ImVec4(1, 1, 1, 1)));
		},
		// OBSOLETE:
		[](const ImTextureRef& tex_ref, const ImVec2& size, std::optional<ImVec2> uv0, std::optional<ImVec2> uv1, std::optional<int> frame_padding,
			std::optional<ImVec4> bg_col, std::optional<ImVec4> tint_col)
		{
			return ImGui::ImageButton(
				"##NOID",
				tex_ref,
				size,
				uv0.value_or(ImVec2(0, 0)),
				uv1.value_or(ImVec2(1, 1)),
				bg_col.value_or(ImVec4(0, 0, 0, 0)),
				tint_col.value_or(ImVec4(1, 1, 1, 1))
			);
		}
	));
	#pragma endregion

	#pragma region Widgets: Combo Box
	ImGui.set_function("BeginCombo", [](const char* label, const char* previewValue, std::optional<int> flags) { return ImGui::BeginCombo(label, previewValue, flags.value_or(0)); });
	ImGui.set_function("EndCombo", &ImGui::EndCombo);
	ImGui.set_function("Combo", sol::overload(&Combo1, &Combo2, &Combo3));
	#pragma endregion

	#pragma region Widgets: Drags
	ImGui.set_function("DragFloat", sol::overload(&DragFloat, &DragFloat_Obsolete));
	ImGui.set_function("DragFloat2", sol::overload(&DragFloatN<2>, &DragFloatN_Obsolete<2>));
	ImGui.set_function("DragFloat3", sol::overload(&DragFloatN<3>, &DragFloatN_Obsolete<3>));
	ImGui.set_function("DragFloat4", sol::overload(&DragFloatN<4>, &DragFloatN_Obsolete<4>));
	ImGui.set_function("DragFloatRange2", &DragFloatRange2);
	ImGui.set_function("DragInt", &DragInt);
	ImGui.set_function("DragInt2", &DragIntN<2>);
	ImGui.set_function("DragInt3", &DragIntN<3>);
	ImGui.set_function("DragInt4", &DragIntN<4>);
	ImGui.set_function("DragIntRange2", &DragIntRange2);
	// DragScalar
	ImGui.set_function("DragScalarN", &DragScalarN);
	#pragma endregion

	#pragma region Widgets: Sliders
	ImGui.set_function("SliderFloat", sol::overload(&SliderFloat, &SliderFloat_Obsolete));
	ImGui.set_function("SliderFloat2", sol::overload(&SliderFloatN<2>, &SliderFloatN_Obsolete<2>));
	ImGui.set_function("SliderFloatVec2", &SliderFloat2_ImVec2);
	ImGui.set_function("SliderFloat3", sol::overload(&SliderFloatN<3>, &SliderFloatN_Obsolete<3>));
	ImGui.set_function("SliderFloat4", sol::overload(&SliderFloatN<4>, &SliderFloatN_Obsolete<4>));
	ImGui.set_function("SliderFloatVec4", &SliderFloat4_ImVec4);
	ImGui.set_function("SliderAngle", &SliderAngle);
	ImGui.set_function("SliderInt", &SliderInt);
	ImGui.set_function("SliderInt2", &SliderIntN<2>);
	ImGui.set_function("SliderInt3", &SliderIntN<3>);
	ImGui.set_function("SliderInt4", &SliderIntN<4>);
	// SliderScalar
	// SliderScalarN
	ImGui.set_function("VSliderFloat", sol::overload(&VSliderFloatVec2, &VSliderFloat));
	ImGui.set_function("VSliderInt", sol::overload(&VSliderIntVec2, &VSliderInt));
	// VSliderScalar
	#pragma endregion

	#pragma region Widgets: Inputs using Keyboard
	ImGui.set_function("InputText", &InputText1);
	ImGui.set_function("InputTextMultiline", sol::overload(&InputTextMultiline1, &InputTextMultiline2));
	ImGui.set_function("InputTextWithHint", &InputTextWithHint);
	ImGui.set_function("InputFloat", &InputFloat);
	ImGui.set_function("InputFloat2", &InputFloatN<2>);
	ImGui.set_function("InputFloat3", &InputFloatN<3>);
	ImGui.set_function("InputFloat4", &InputFloatN<4>);
	ImGui.set_function("InputInt", &InputInt);
	ImGui.set_function("InputInt2", &InputIntN<2>);
	ImGui.set_function("InputInt3", &InputIntN<3>);
	ImGui.set_function("InputInt4", &InputIntN<4>);
	ImGui.set_function("InputDouble", &InputDouble);
	#pragma endregion

	#pragma region Widgets: Color Editor / Picker
	ImGui.set_function("ColorEdit3", sol::overload(&ColorEditN1<3>, &ColorEditN2<3>, &ColorEditN3<3>));
	ImGui.set_function("ColorEdit4", sol::overload(&ColorEditN1<4>, &ColorEditN2<4>, &ColorEditN3<4>));
	ImGui.set_function("ColorPicker3", sol::overload(&ColorPickerN1<3>, &ColorPickerN2<3>, &ColorPickerN3<3>));
	ImGui.set_function("ColorPicker4", sol::overload(&ColorPickerN1<4>, &ColorPickerN2<4>, &ColorPickerN3<4>));
	ImGui.set_function("ColorButton", sol::overload(&ColorButton1, &ColorButton2, &ColorButton3));
	ImGui.set_function("SetColorEditOptions", [](int flags) { ImGui::SetColorEditOptions(flags); });
	#pragma endregion

	#pragma region Widgets: Trees
	ImGui.set_function("TreeNode", sol::overload(
		[](const char* label) { return ImGui::TreeNode(label); },
		[](const char* str_id, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); return ImGui::TreeNode(str_id, "%s", text.c_str()); },
		[](sol::object obj, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); return ImGui::TreeNode(obj.pointer(), "%s", text.c_str()); }
	));
	ImGui.set_function("TreeNodeEx", sol::overload(
		[](const char* label, std::optional<int> flags) { return ImGui::TreeNodeEx(label, flags.value_or(0)); },
		[](const char* str_id, int flags, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); return ImGui::TreeNodeEx(str_id, flags, "%s", text.c_str()); },
		[](sol::object obj, int flags, sol::variadic_args va, sol::this_state s) { std::string text = format_text(s, va); return ImGui::TreeNodeEx(obj.pointer(), flags, "%s", text.c_str()); }
	));
	ImGui.set_function("TreePush", sol::overload(
		[](const char* strId) { ImGui::TreePush(strId); },
		[](std::optional<sol::object> obj) { if (obj.has_value()) ImGui::TreePush(obj->pointer()); else ImGui::TreePush(static_cast<void*>(nullptr)); }
	));
	ImGui.set_function("TreePop", &ImGui::TreePop);
	ImGui.set_function("GetTreeNodeToLabelSpacing", &ImGui::GetTreeNodeToLabelSpacing);
	ImGui.set_function("CollapsingHeader", sol::overload(
		[](const char* label, std::optional<int> flags) { return ImGui::CollapsingHeader(label, flags.value_or(0)); },
		[](const char* label, std::optional<bool> open_, std::optional<int> flags) { bool open = open_.value_or(true); bool show = ImGui::CollapsingHeader(label, open_.has_value() ? &open : nullptr, flags.value_or(0)); return std::make_tuple(open, show); }
	));
	ImGui.set_function("SetNextItemOpen", [](bool is_open, std::optional<int> cond) { ImGui::SetNextItemOpen(is_open, cond.value_or(0)); });
	// SetNextItemStorageID
	ImGui.set_function("TreeAdvanceToLabelPos", []() { ImGui::SetCursorPosX(ImGui::GetCursorPosX() + ImGui::GetTreeNodeToLabelSpacing()); });
	#pragma endregion

	#pragma region Widgets: Selectables
	ImGui.set_function("Selectable", sol::overload(
		[](const char* label, std::optional<bool> selected_, std::optional<int> flags, std::optional<ImVec2> size){
			bool selected = selected_.value_or(false); bool pressed = ImGui::Selectable(label, &selected, flags.value_or(0), size.value_or(ImVec2(0, 0))); return std::make_tuple(selected, pressed); },
		[](const char* label, bool selected, int flags, float sizeX, float sizeY) { bool pressed = ImGui::Selectable(label, &selected, flags, { sizeX, sizeY }); return std::make_tuple(selected, pressed); }
	));
	#pragma endregion

	// MultiSelect?

	#pragma region Widgets: List Boxes
	ImGui.set_function("BeginListBox", [](const char* label, std::optional<ImVec2> size) { return ImGui::BeginListBox(label, size.value_or(ImVec2(0, 0))); });
	ImGui.set_function("EndListBox", &ImGui::EndListBox);
	ImGui.set_function("ListBox", sol::overload(&ListBox1, &ListBox2));
	#pragma endregion

	#pragma region Widgets: Data Plotting
	ImGui.set_function("PlotLines", sol::overload(&PlotLines1, &PlotLines2));
	ImGui.set_function("PlotHistogram", sol::overload(&PlotHistogram1, &PlotHistogram2));
	#pragma endregion

	#pragma region Widgets: Value() Helpers
	ImGui.set_function("Value", sol::overload(
		[](const char* prefix, bool b) { ImGui::Value(prefix, b); },
		[](const char* prefix, int v) { ImGui::Value(prefix, v); },
		[](const char* prefix, unsigned int v) { ImGui::Value(prefix, v); },
		[](const char* prefix, float v, std::optional<const char*> float_format) { ImGui::Value(prefix, v, float_format.value_or(nullptr)); }
	));
	#pragma endregion

	#pragma region Widgets: Menu
	ImGui.set_function("BeginMenuBar", &ImGui::BeginMenuBar);
	ImGui.set_function("EndMenuBar", &ImGui::EndMenuBar);
	ImGui.set_function("BeginMainMenuBar", &ImGui::BeginMainMenuBar);
	ImGui.set_function("EndMainMenuBar", &ImGui::EndMainMenuBar);
	ImGui.set_function("BeginMenu", [](const char* label, std::optional<bool> enabled) { return ImGui::BeginMenu(label, enabled.value_or(true)); });
	ImGui.set_function("EndMenu", &ImGui::EndMenu);
	ImGui.set_function("MenuItem",
		[](const char* label, std::optional<const char*> shortcut, std::optional<bool> selected, std::optional<bool> enabled) {
			bool value = selected.value_or(false);
			bool activated = ImGui::MenuItem(label, shortcut.value_or(nullptr), &value, enabled.value_or(true));
			return std::make_tuple(activated, selected.has_value() ? value : activated);
		}
	);
	#pragma endregion
}

} // namespace mq::lua::bindings
