/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

// Widgets: Text
static void TextUnformatted(const std::string& text)                                                { ImGui::TextUnformatted(text.c_str()); }
static void TextUnformatted(const std::string& text, const std::string& textEnd)                    { ImGui::TextUnformatted(text.c_str(), textEnd.c_str()); }
static void Text(const std::string& text)                                                           { ImGui::Text("%s", text.c_str()); }
static void TextColored(float colR, float colG, float colB, float colA, const std::string& text)    { ImGui::TextColored({ colR, colG, colB, colA }, text.c_str()); }
static void TextDisabled(const std::string& text)                                                   { ImGui::TextDisabled(text.c_str()); }
static void TextWrapped(const std::string text)                                                     { ImGui::TextWrapped(text.c_str()); }
static void LabelText(const std::string& label, const std::string& text)                            { ImGui::LabelText(label.c_str(), text.c_str()); }
static void BulletText(const std::string& text)                                                     { ImGui::BulletText(text.c_str()); }

// Widgets: Main
static bool Button(const std::string& label)                                                        { return ImGui::Button(label.c_str()); }
static bool Button(const std::string& label, float sizeX, float sizeY)                              { return ImGui::Button(label.c_str(), { sizeX, sizeY }); }
static bool SmallButton(const std::string& label)                                                   { return ImGui::SmallButton(label.c_str()); }
static bool InvisibleButton(const std::string& stringID, float sizeX, float sizeY)                  { return ImGui::InvisibleButton(stringID.c_str(), { sizeX, sizeY }); }
static bool ArrowButton(const std::string& stringID, int dir)                                       { return ImGui::ArrowButton(stringID.c_str(), static_cast<ImGuiDir>(dir)); }
static void Image()                                                                                 { /* TODO: Image(...) ==> UNSUPPORTED */ }
static void ImageButton()                                                                           { /* TODO: ImageButton(...) ==> UNSUPPORTED */ }

static std::tuple<bool, bool> Checkbox(const std::string& label, bool v)
{
	bool value{ v };
	bool pressed = ImGui::Checkbox(label.c_str(), &value);

	return std::make_tuple(value, pressed);
}

static std::tuple<uint32_t, bool> CheckboxFlags(const std::string& label, uint32_t flags, uint32_t flagsValue)
{
	uint32_t mutableFlags = flags;
	bool pressed = ImGui::CheckboxFlags(label.c_str(), &mutableFlags, flagsValue);

	return std::make_tuple(mutableFlags, pressed);
}

static bool RadioButton(const std::string& label, bool active)                                      { return ImGui::RadioButton(label.c_str(), active); }
static std::tuple<int, bool> RadioButton(const std::string& label, int v, int vButton)              { bool ret{ ImGui::RadioButton(label.c_str(), &v, vButton) }; return std::make_tuple(v, ret); }

static void ProgressBar(float fraction)                                                             { ImGui::ProgressBar(fraction); }
static void ProgressBar(float fraction, float sizeX, float sizeY)                                   { ImGui::ProgressBar(fraction, { sizeX, sizeY }); }
static void ProgressBar(float fraction, float sizeX, float sizeY, const std::string& overlay)       { ImGui::ProgressBar(fraction, { sizeX, sizeY }, overlay.c_str()); }

static void Bullet()                                                                                { ImGui::Bullet(); }

// Widgets: Combo Box
static bool BeginCombo(const std::string& label, const std::string& previewValue)
{
	return ImGui::BeginCombo(label.c_str(), previewValue.c_str());
}

static bool BeginCombo(const std::string& label, const std::string& previewValue, int flags)
{
	return ImGui::BeginCombo(label.c_str(), previewValue.c_str(), static_cast<ImGuiComboFlags>(flags));
}

static void EndCombo()
{
	ImGui::EndCombo();
}

static std::tuple<int, bool> Combo(const std::string& label, int currentItem, const sol::table& items, int itemsCount)
{
	std::vector<std::string> strings;
	for (int i{ 1 }; i <= itemsCount; i++)
	{
		const auto& stringItem = items.get<sol::optional<std::string>>(i);
		strings.push_back(stringItem.value_or("Missing"));
	}

	std::vector<const char*> cstrings;
	for (auto& string : strings)
		cstrings.push_back(string.c_str());

	bool clicked = ImGui::Combo(label.c_str(), &currentItem, cstrings.data(), itemsCount);
	return std::make_tuple(currentItem, clicked);
}

static std::tuple<int, bool> Combo(const std::string& label, int currentItem, const sol::table& items, int itemsCount, int popupMaxHeightInItems)
{
	std::vector<std::string> strings;
	for (int i{ 1 }; i <= itemsCount; i++)
	{
		const auto& stringItem = items.get<sol::optional<std::string>>(i);
		strings.push_back(stringItem.value_or("Missing"));
	}

	std::vector<const char*> cstrings;
	for (auto& string : strings)
		cstrings.push_back(string.c_str());

	bool clicked = ImGui::Combo(label.c_str(), &currentItem, cstrings.data(), itemsCount, popupMaxHeightInItems);
	return std::make_tuple(currentItem, clicked);
}

static std::tuple<int, bool> Combo(const std::string& label, int currentItem, const std::string& itemsSeparatedByZeros)
{
	bool clicked = ImGui::Combo(label.c_str(), &currentItem, itemsSeparatedByZeros.c_str());
	return std::make_tuple(currentItem, clicked);
}

static std::tuple<int, bool> Combo(const std::string& label, int currentItem, const std::string& itemsSeparatedByZeros, int popupMaxHeightInItems)
{
	bool clicked = ImGui::Combo(label.c_str(), &currentItem, itemsSeparatedByZeros.c_str(), popupMaxHeightInItems);
	return std::make_tuple(currentItem, clicked);
}
// TODO: 3rd Combo from ImGui not Supported

// Widgets: Drags
static std::tuple<float, bool> DragFloat(const std::string& label, float v)
{
	bool used = ImGui::DragFloat(label.c_str(), &v);
	return std::make_tuple(v, used);
}

static std::tuple<float, bool> DragFloat(const std::string& label, float v, float v_speed)
{
	bool used = ImGui::DragFloat(label.c_str(), &v, v_speed);
	return std::make_tuple(v, used);
}

static std::tuple<float, bool> DragFloat(const std::string& label, float v, float v_speed, float v_min)
{
	bool used = ImGui::DragFloat(label.c_str(), &v, v_speed, v_min);
	return std::make_tuple(v, used);
}

static std::tuple<float, bool> DragFloat(const std::string& label, float v, float v_speed, float v_min, float v_max)
{
	bool used = ImGui::DragFloat(label.c_str(), &v, v_speed, v_min, v_max);
	return std::make_tuple(v, used);
}

static std::tuple<float, bool> DragFloat(const std::string& label, float v, float v_speed, float v_min, float v_max, const std::string& format)
{
	bool used = ImGui::DragFloat(label.c_str(), &v, v_speed, v_min, v_max, format.c_str());
	return std::make_tuple(v, used);
}

static std::tuple<float, bool> DragFloat(const std::string& label, float v, float v_speed, float v_min, float v_max, const std::string& format, float power)
{
	bool used = ImGui::DragFloat(label.c_str(), &v, v_speed, v_min, v_max, format.c_str(), power);
	return std::make_tuple(v, used);
}

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
static std::tuple<float, bool> SliderFloat(const std::string& label, float v, float v_min, float v_max) { bool used = ImGui::SliderFloat(label.c_str(), &v, v_min, v_max); return std::make_tuple(v, used); }
static std::tuple<float, bool> SliderFloat(const std::string& label, float v, float v_min, float v_max, const std::string& format) { bool used = ImGui::SliderFloat(label.c_str(), &v, v_min, v_max, format.c_str()); return std::make_tuple(v, used); }
static std::tuple<float, bool> SliderFloat(const std::string& label, float v, float v_min, float v_max, const std::string& format, float power) { bool used = ImGui::SliderFloat(label.c_str(), &v, v_min, v_max, format.c_str(), power); return std::make_tuple(v, used); }
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
static std::tuple<std::string, bool> InputText(const std::string& label, std::string text)          { bool selected = ImGui::InputText(label.c_str(), &text); return std::make_tuple(text, selected); }
static std::tuple<std::string, bool> InputText(const std::string& label, std::string text, int flags) { bool selected = ImGui::InputText(label.c_str(), &text, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); }
static std::tuple<std::string, bool> InputTextMultiline(const std::string& label, std::string text) { bool selected = ImGui::InputTextMultiline(label.c_str(), &text); return std::make_tuple(text, selected); }
static std::tuple<std::string, bool> InputTextMultiline(const std::string& label, std::string text, float sizeX, float sizeY) { bool selected = ImGui::InputTextMultiline(label.c_str(), &text, { sizeX, sizeY }); return std::make_tuple(text, selected); }
static std::tuple<std::string, bool> InputTextMultiline(const std::string& label, std::string text, float sizeX, float sizeY, int flags) { bool selected = ImGui::InputTextMultiline(label.c_str(), &text, { sizeX, sizeY }, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); }
static std::tuple<std::string, bool> InputTextWithHint(const std::string& label, const std::string& hint, std::string text) { bool selected = ImGui::InputTextWithHint(label.c_str(), hint.c_str(), &text); return std::make_tuple(text, selected); }
static std::tuple<std::string, bool> InputTextWithHint(const std::string& label, const std::string& hint, std::string text, int flags) { bool selected = ImGui::InputTextWithHint(label.c_str(), hint.c_str(), &text, static_cast<ImGuiInputTextFlags>(flags)); return std::make_tuple(text, selected); }
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
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorEdit3(const std::string& label, const sol::table& col)
{
	const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
	                    b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
	float color[3] = { float(r), float(g), float(b) };
	bool used = ImGui::ColorEdit3(label.c_str(), color);

	sol::as_table_t rgb = sol::as_table(std::vector<float>{
		color[0], color[1], color[2]
	});

    return std::make_tuple(rgb, used);
}
static std::tuple<sol::as_table_t<std::vector<float>>, bool> ColorEdit3(const std::string& label, const sol::table& col, int flags)
{
    const lua_Number    r{ col[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        g{ col[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
                        b{ col[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };
    float color[3] = { float(r), float(g), float(b) };
    bool used = ImGui::ColorEdit3(label.c_str(), color, static_cast<ImGuiColorEditFlags>(flags));

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
/* TODO: TreeNodeV(...) (2) ==> UNSUPPORTED */
static bool TreeNodeEx(const std::string& label)                                                    { return ImGui::TreeNodeEx(label.c_str()); }
static bool TreeNodeEx(const std::string& label, int flags)                                         { return ImGui::TreeNodeEx(label.c_str(), static_cast<ImGuiTreeNodeFlags>(flags)); }
static bool TreeNodeEx(const std::string& label, int flags, const std::string& fmt)                 { return ImGui::TreeNodeEx(label.c_str(), static_cast<ImGuiTreeNodeFlags>(flags), fmt.c_str()); }
/* TODO: TreeNodeExV(...) (2) ==> UNSUPPORTED */
static void TreePush(const std::string& str_id)                                                     { ImGui::TreePush(str_id.c_str()); }
/* TODO: TreePush(const void*) ==> UNSUPPORTED */
static void TreePop()                                                                               { ImGui::TreePop(); }
static float GetTreeNodeToLabelSpacing()                                                            { return ImGui::GetTreeNodeToLabelSpacing(); }
static bool CollapsingHeader(const std::string& label)                                              { return ImGui::CollapsingHeader(label.c_str()); }
static bool CollapsingHeader(const std::string& label, int flags)                                   { return ImGui::CollapsingHeader(label.c_str(), static_cast<ImGuiTreeNodeFlags>(flags)); }
static std::tuple<bool, bool> CollapsingHeader(const std::string& label, bool open)                 { bool notCollapsed = ImGui::CollapsingHeader(label.c_str(), &open); return std::make_tuple(open, notCollapsed); }
static std::tuple<bool, bool> CollapsingHeader(const std::string& label, bool open, int flags)      { bool notCollapsed = ImGui::CollapsingHeader(label.c_str(), &open, static_cast<ImGuiTreeNodeFlags>(flags)); return std::make_tuple(open, notCollapsed); }
static void SetNextItemOpen(bool is_open)                                                           { ImGui::SetNextItemOpen(is_open); }
static void SetNextItemOpen(bool is_open, int cond)                                                 { ImGui::SetNextItemOpen(is_open, static_cast<ImGuiCond>(cond)); }

// Widgets: Selectables
// TODO: Only one of Selectable variations is possible due to same parameters for Lua
static bool Selectable(const std::string& label)                                                    { return ImGui::Selectable(label.c_str()); }
static bool Selectable(const std::string& label, bool selected)                                     { ImGui::Selectable(label.c_str(), &selected); return selected; }
static bool Selectable(const std::string& label, bool selected, int flags)                          { ImGui::Selectable(label.c_str(), &selected, static_cast<ImGuiSelectableFlags>(flags)); return selected; }
static bool Selectable(const std::string& label, bool selected, int flags, float sizeX, float sizeY){ ImGui::Selectable(label.c_str(), &selected, static_cast<ImGuiSelectableFlags>(flags), { sizeX, sizeY }); return selected; }

// Widgets: List Boxes
static std::tuple<int, bool> ListBox(const std::string& label, int current_item, const sol::table& items, int items_count)
{
	std::vector<std::string> strings;
	for (int i{ 1 }; i <= items_count; i++)
	{
		const auto& stringItem = items.get<sol::optional<std::string>>(i);
		strings.push_back(stringItem.value_or("Missing"));
	}

	std::vector<const char*> cstrings;
	for (auto& string : strings)
		cstrings.push_back(string.c_str());

	bool clicked = ImGui::ListBox(label.c_str(), &current_item, cstrings.data(), items_count);
	return std::make_tuple(current_item, clicked);
}

static std::tuple<int, bool> ListBox(const std::string& label, int current_item, const sol::table& items, int items_count, int height_in_items)
{
	std::vector<std::string> strings;
	for (int i{ 1 }; i <= items_count; i++)
	{
		const auto& stringItem = items.get<sol::optional<std::string>>(i);
		strings.push_back(stringItem.value_or("Missing"));
	}

	std::vector<const char*> cstrings;
	for (auto& string : strings)
		cstrings.push_back(string.c_str());

	bool clicked = ImGui::ListBox(label.c_str(), &current_item, cstrings.data(), items_count, height_in_items);
	return std::make_tuple(current_item, clicked);
}

static bool ListBoxHeader(const std::string& label, float sizeX, float sizeY)                       { return ImGui::ListBoxHeader(label.c_str(), { sizeX, sizeY }); }
static bool ListBoxHeader(const std::string& label, int items_count)                                { return ImGui::ListBoxHeader(label.c_str(), items_count); }
static bool ListBoxHeader(const std::string& label, int items_count, int height_in_items)           { return ImGui::ListBoxHeader(label.c_str(), items_count, height_in_items); }
static void ListBoxFooter()                                                                         { ImGui::ListBoxFooter(); }

// Widgets: Data Plotting
/* TODO: Widgets Data Plotting ==> UNSUPPORTED (barely used and quite long functions) */

// Widgets: Value() helpers
static void Value(const std::string& prefix, bool b)                                                { ImGui::Value(prefix.c_str(), b); }
static void Value(const std::string& prefix, int v)                                                 { ImGui::Value(prefix.c_str(), v); }
static void Value(const std::string& prefix, unsigned int v)                                        { ImGui::Value(prefix.c_str(), v); }
static void Value(const std::string& prefix, float v)                                               { ImGui::Value(prefix.c_str(), v); }
static void Value(const std::string& prefix, float v, const std::string& float_format)              { ImGui::Value(prefix.c_str(), v, float_format.c_str()); }

// Widgets: Menus
static bool BeginMenuBar()                                                                          { return ImGui::BeginMenuBar(); }
static void EndMenuBar()                                                                            { ImGui::EndMenuBar(); }
static bool BeginMainMenuBar()                                                                      { return ImGui::BeginMainMenuBar(); }
static void EndMainMenuBar()                                                                        { ImGui::EndMainMenuBar(); }
static bool BeginMenu(const std::string& label)                                                     { return ImGui::BeginMenu(label.c_str()); }
static bool BeginMenu(const std::string& label, bool enabled)                                       { return ImGui::BeginMenu(label.c_str(), enabled); }
static void EndMenu()                                                                               { ImGui::EndMenu(); }
static bool MenuItem(const std::string& label)                                                      { return ImGui::MenuItem(label.c_str()); }
static bool MenuItem(const std::string& label, const std::string& shortcut)                         { return ImGui::MenuItem(label.c_str(), shortcut.c_str()); }
static std::tuple<bool, bool> MenuItem(const std::string& label, const std::string& shortcut, bool selected) { bool activated = ImGui::MenuItem(label.c_str(), shortcut.c_str(), &selected); return std::make_tuple(selected, activated); }
static std::tuple<bool, bool> MenuItem(const std::string& label, const std::string& shortcut, bool selected, bool enabled) { bool activated = ImGui::MenuItem(label.c_str(), shortcut.c_str(), &selected, enabled); return std::make_tuple(selected, activated); }

// Tooltips
static void BeginTooltip()                                                                          { ImGui::BeginTooltip(); }
static void EndTooltip()                                                                            { ImGui::EndTooltip(); }
static void SetTooltip(const std::string& fmt)                                                      { ImGui::SetTooltip(fmt.c_str()); }
static void SetTooltipV()                                                                           { /* TODO: SetTooltipV(...) ==> UNSUPPORTED */ }

// Popups, Modals
static bool BeginPopup(const std::string& str_id)                                                   { return ImGui::BeginPopup(str_id.c_str()); }
static bool BeginPopup(const std::string& str_id, int flags)                                        { return ImGui::BeginPopup(str_id.c_str(), static_cast<ImGuiWindowFlags>(flags)); }
static bool BeginPopupModal(const std::string& name)                                                { return ImGui::BeginPopupModal(name.c_str()); }
static bool BeginPopupModal(const std::string& name, bool open)                                     { return ImGui::BeginPopupModal(name.c_str(), &open); }
static bool BeginPopupModal(const std::string& name, bool open, int flags)                          { return ImGui::BeginPopupModal(name.c_str(), &open, static_cast<ImGuiWindowFlags>(flags)); }
static void EndPopup()                                                                              { ImGui::EndPopup(); }
static void OpenPopup(const std::string& str_id)                                                    { ImGui::OpenPopup(str_id.c_str()); }
static void OpenPopup(const std::string& str_id, int popup_flags)                                   { ImGui::OpenPopup(str_id.c_str(), static_cast<ImGuiPopupFlags>(popup_flags)); }
//static bool OpenPopupContextItem()                                                                { return ImGui::OpenPopupContextItem(); }
//static bool OpenPopupContextItem(const std::string& str_id)                                       { return ImGui::OpenPopupContextItem(str_id.c_str()); }
//static bool OpenPopupContextItem(const std::string& str_id, int popup_flags)                      { return ImGui::OpenPopupContextItem(str_id.c_str(), static_cast<ImGuiPopupFlags>(popup_flags)); }
static void CloseCurrentPopup()                                                                     { ImGui::CloseCurrentPopup(); }
static bool BeginPopupContextItem()                                                                 { return ImGui::BeginPopupContextItem(); }
static bool BeginPopupContextItem(const std::string& str_id)                                        { return ImGui::BeginPopupContextItem(str_id.c_str()); }
static bool BeginPopupContextItem(const std::string& str_id, int popup_flags)                       { return ImGui::BeginPopupContextItem(str_id.c_str(), static_cast<ImGuiPopupFlags>(popup_flags)); }
static bool BeginPopupContextWindow()                                                               { return ImGui::BeginPopupContextWindow(); }
static bool BeginPopupContextWindow(const std::string& str_id)                                      { return ImGui::BeginPopupContextWindow(str_id.c_str()); }
static bool BeginPopupContextWindow(const std::string& str_id, int popup_flags)                     { return ImGui::BeginPopupContextWindow(str_id.c_str(), static_cast<ImGuiPopupFlags>(popup_flags)); }
static bool BeginPopupContextVoid()                                                                 { return ImGui::BeginPopupContextVoid(); }
static bool BeginPopupContextVoid(const std::string& str_id)                                        { return ImGui::BeginPopupContextVoid(str_id.c_str()); }
static bool BeginPopupContextVoid(const std::string& str_id, int popup_flags)                       { return ImGui::BeginPopupContextVoid(str_id.c_str(), static_cast<ImGuiPopupFlags>(popup_flags)); }
static bool IsPopupOpen(const std::string& str_id)                                                  { return ImGui::IsPopupOpen(str_id.c_str()); }
static bool IsPopupOpen(const std::string& str_id, int popup_flags)                                 { return ImGui::IsPopupOpen(str_id.c_str(), popup_flags); }

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
static void DockSpace(unsigned int id)                                                              { ImGui::DockSpace(id); }
static void DockSpace(unsigned int id, float sizeX, float sizeY)                                    { ImGui::DockSpace(id, { sizeX, sizeY }); }
static void DockSpace(unsigned int id, float sizeX, float sizeY, int flags)                         { ImGui::DockSpace(id, { sizeX, sizeY }, static_cast<ImGuiDockNodeFlags>(flags)); }
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
	ImGui.set_function("TextUnformatted", sol::overload(
		sol::resolve<void(const std::string&)>(TextUnformatted),
		sol::resolve<void(const std::string&, const std::string&)>(TextUnformatted)
	));
	ImGui.set_function("Text", Text);
	ImGui.set_function("TextColored", TextColored);
	ImGui.set_function("TextDisabled", TextDisabled);
	ImGui.set_function("TextWrapped", TextWrapped);
	ImGui.set_function("LabelText", LabelText);
	ImGui.set_function("BulletText", BulletText);
	#pragma endregion

	#pragma region Widgets: Main
	ImGui.set_function("Button", sol::overload(
		sol::resolve<bool(const std::string&)>(Button),
		sol::resolve<bool(const std::string&, float, float)>(Button)
	));
	ImGui.set_function("SmallButton", SmallButton);
	ImGui.set_function("InvisibleButton", InvisibleButton);
	ImGui.set_function("ArrowButton", ArrowButton);
	ImGui.set_function("Checkbox", Checkbox);
	ImGui.set_function("CheckboxFlags", CheckboxFlags);
	ImGui.set_function("RadioButton", sol::overload(
		sol::resolve<bool(const std::string&, bool)>(RadioButton),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, int)>(RadioButton)
	));
	ImGui.set_function("ProgressBar", sol::overload(
		sol::resolve<void(float)>(ProgressBar),
		sol::resolve<void(float, float, float)>(ProgressBar),
		sol::resolve<void(float, float, float, const std::string&)>(ProgressBar)
	));
	ImGui.set_function("Bullet", Bullet);
	#pragma endregion

	#pragma region Widgets: Combo Box
	ImGui.set_function("BeginCombo", sol::overload(
		sol::resolve<bool(const std::string&, const std::string&)>(BeginCombo),
		sol::resolve<bool(const std::string&, const std::string&, int)>(BeginCombo)
	));
	ImGui.set_function("EndCombo", EndCombo);
	ImGui.set_function("Combo", sol::overload(
		sol::resolve<std::tuple<int, bool>(const std::string&, int, const sol::table&, int)>(Combo),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, const sol::table&, int, int)>(Combo),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, const std::string&)>(Combo),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, const std::string&, int)>(Combo)
	));
	#pragma endregion

	#pragma region Widgets: Drags
	ImGui.set_function("DragFloat", sol::overload(
		sol::resolve<std::tuple<float, bool>(const std::string&, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, float)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, float, const std::string&)>(DragFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, float, const std::string&, float)>(DragFloat)
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
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float)>(SliderFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, const std::string&)>(SliderFloat),
		sol::resolve<std::tuple<float, bool>(const std::string&, float, float, float, const std::string&, float)>(SliderFloat)
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
		sol::resolve<std::tuple<std::string, bool>(const std::string&, std::string)>(InputText),
		sol::resolve<std::tuple<std::string, bool>(const std::string&, std::string, int)>(InputText)
	));
	ImGui.set_function("InputTextMultiline", sol::overload(
		sol::resolve<std::tuple<std::string, bool>(const std::string&, std::string)>(InputTextMultiline),
		sol::resolve<std::tuple<std::string, bool>(const std::string&, std::string, float, float)>(InputTextMultiline),
		sol::resolve<std::tuple<std::string, bool>(const std::string&, std::string, float, float, int)>(InputTextMultiline)
	));
	ImGui.set_function("InputTextWithHint", sol::overload(
		sol::resolve<std::tuple<std::string, bool>(const std::string&, const std::string&, std::string)>(InputTextWithHint),
		sol::resolve<std::tuple<std::string, bool>(const std::string&, const std::string&, std::string, int)>(InputTextWithHint)
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
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(ColorEdit3),
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, int)>(ColorEdit3)
	));
	ImGui.set_function("ColorEdit4", sol::overload(
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&)>(ColorEdit4),
		sol::resolve<std::tuple <sol::as_table_t<std::vector<float>>, bool>(const std::string&, const sol::table&, int)>(ColorEdit4)
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
	ImGui.set_function("TreePush", TreePush);
	ImGui.set_function("TreePop", TreePop);
	ImGui.set_function("GetTreeNodeToLabelSpacing", GetTreeNodeToLabelSpacing);
	ImGui.set_function("CollapsingHeader", sol::overload(
		sol::resolve<bool(const std::string&)>(CollapsingHeader),
		sol::resolve<bool(const std::string&, int)>(CollapsingHeader),
		sol::resolve<std::tuple<bool, bool>(const std::string&, bool)>(CollapsingHeader),
		sol::resolve<std::tuple<bool, bool>(const std::string&, bool, int)>(CollapsingHeader)
	));
	ImGui.set_function("SetNextItemOpen", sol::overload(
		sol::resolve<void(bool)>(SetNextItemOpen),
		sol::resolve<void(bool, int)>(SetNextItemOpen)
	));
	ImGui.set_function("TreeAdvanceToLabelPos", ImGui::TreeAdvanceToLabelPos);
	#pragma endregion

	#pragma region Widgets: Selectables
	ImGui.set_function("Selectable", sol::overload(
		sol::resolve<bool(const std::string&)>(Selectable),
		sol::resolve<bool(const std::string&, bool)>(Selectable),
		sol::resolve<bool(const std::string&, bool, int)>(Selectable),
		sol::resolve<bool(const std::string&, bool, int, float, float)>(Selectable)
	));
	#pragma endregion

	#pragma region Widgets: List Boxes
	ImGui.set_function("ListBox", sol::overload(
		sol::resolve<std::tuple<int, bool>(const std::string&, int, const sol::table&, int)>(ListBox),
		sol::resolve<std::tuple<int, bool>(const std::string&, int, const sol::table&, int, int)>(ListBox)
	));
	ImGui.set_function("ListBoxHeader", sol::overload(
		sol::resolve<bool(const std::string&, float, float)>(ListBoxHeader),
		sol::resolve<bool(const std::string&, int)>(ListBoxHeader),
		sol::resolve<bool(const std::string&, int, int)>(ListBoxHeader)
	));
	ImGui.set_function("ListBoxFooter", ListBoxFooter);
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
	ImGui.set_function("BeginMenuBar", BeginMenuBar);
	ImGui.set_function("EndMenuBar", EndMenuBar);
	ImGui.set_function("BeginMainMenuBar", BeginMainMenuBar);
	ImGui.set_function("EndMainMenuBar", EndMainMenuBar);
	ImGui.set_function("BeginMenu", sol::overload(
		sol::resolve<bool(const std::string&)>(BeginMenu),
		sol::resolve<bool(const std::string&, bool)>(BeginMenu)
	));
	ImGui.set_function("EndMenu", EndMenu);
	ImGui.set_function("MenuItem", sol::overload(
		sol::resolve<bool(const std::string&)>(MenuItem),
		sol::resolve<bool(const std::string&, const std::string&)>(MenuItem),
		sol::resolve<std::tuple<bool, bool>(const std::string&, const std::string&, bool)>(MenuItem),
		sol::resolve<std::tuple<bool, bool>(const std::string&, const std::string&, bool, bool)>(MenuItem)
	));
	#pragma endregion

	#pragma region Tooltips
	ImGui.set_function("BeginTooltip", BeginTooltip);
	ImGui.set_function("EndTooltip", EndTooltip);
	ImGui.set_function("SetTooltip", SetTooltip);
	#pragma endregion

	#pragma region Popups, Modals
	ImGui.set_function("BeginPopup", sol::overload(
		sol::resolve<bool(const std::string&)>(BeginPopup),
		sol::resolve<bool(const std::string&, int)>(BeginPopup)
	));
	ImGui.set_function("BeginPopupModal", sol::overload(
		sol::resolve<bool(const std::string&)>(BeginPopupModal),
		sol::resolve<bool(const std::string&, bool)>(BeginPopupModal),
		sol::resolve<bool(const std::string&, bool, int)>(BeginPopupModal)
	));
	ImGui.set_function("EndPopup", EndPopup);
	ImGui.set_function("OpenPopup", sol::overload(
		sol::resolve<void(const std::string&)>(OpenPopup),
		sol::resolve<void(const std::string&, int)>(OpenPopup)
	));
	//ImGui.set_function("OpenPopupContextItem", sol::overload(
	//    sol::resolve<bool()>(OpenPopupContextItem),
	//    sol::resolve<bool(const std::string&)>(OpenPopupContextItem),
	//    sol::resolve<bool(const std::string&, int)>(OpenPopupContextItem)
	//));
	ImGui.set_function("CloseCurrentPopup", CloseCurrentPopup);
	ImGui.set_function("BeginPopupContextItem", sol::overload(
		sol::resolve<bool()>(BeginPopupContextItem),
		sol::resolve<bool(const std::string&)>(BeginPopupContextItem),
		sol::resolve<bool(const std::string&, int)>(BeginPopupContextItem)
	));
	ImGui.set_function("BeginPopupContextWindow", sol::overload(
		sol::resolve<bool()>(BeginPopupContextWindow),
		sol::resolve<bool(const std::string&)>(BeginPopupContextWindow),
		sol::resolve<bool(const std::string&, int)>(BeginPopupContextWindow)
	));
	ImGui.set_function("BeginPopupContextVoid", sol::overload(
		sol::resolve<bool()>(BeginPopupContextVoid),
		sol::resolve<bool(const std::string&)>(BeginPopupContextVoid),
		sol::resolve<bool(const std::string&, int)>(BeginPopupContextVoid)
	));
	ImGui.set_function("IsPopupOpen", sol::overload(
		sol::resolve<bool(const std::string&)>(IsPopupOpen),
		sol::resolve<bool(const std::string&, int)>(IsPopupOpen)
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
		sol::resolve<void(unsigned int)>(DockSpace),
		sol::resolve<void(unsigned int, float, float)>(DockSpace),
		sol::resolve<void(unsigned int, float, float, int)>(DockSpace)
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
