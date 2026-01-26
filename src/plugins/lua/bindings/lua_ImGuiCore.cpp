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
#include <imgui/imgui_stacklayout.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <optional>
#include <string>

namespace mq::lua::bindings {

//============================================================================

void RegisterBindings_ImGuiCustom(sol::table& ImGui);
void RegisterBindings_ImGuiWidgets(sol::table& ImGui);
void RegisterBindings_ImGuiUserTypes(sol::state_view state);
void RegisterBindings_ImGuiEnums(sol::state_view state);


template <typename... Ts> struct overload : Ts... { using Ts::operator()...; };
template <typename... Ts> overload(Ts...) -> overload<Ts...>;

std::string format_text(sol::this_state s, sol::variadic_args va)
{
	sol::function string_format = sol::state_view(s)["string"]["format"];
	std::string text = string_format(va);
	return text;
}

ImVec4 TableToColor(sol::this_state L, sol::table table)
{
	ImVec4 color(0.0f, 0.0f, 0.0f, 1.0f);
	float* floats = &color.x;

	for (size_t i = 0; i < table.size(); ++i)
	{
		auto value = table.get<std::optional<float>>(i + 1);
		if (value.has_value())
		{
			floats[i] = value.value();
		}
		else
		{
			auto value_proxy = table[i + 1];
			sol::type type = value_proxy.get_type();

			luaL_error(L, "PushStyleColor: Expected number in index %d, got %s", static_cast<int>(i + 1), sol::type_name(L, type).c_str());
		}
	}

	return color;
}

void ImGuiPushStyleColorTable(sol::this_state L, ImGuiCol idx, sol::table table)
{
	// Needs to have 3 or 4 elements.
	if (table.size() != 3 && table.size() != 4)
	{
		luaL_error(L, "PushStyleColor: Expected a color, found table with %zu values", table.size());
	}

	ImVec4 color = TableToColor(L, table);

	ImGui::PushStyleColor(idx, color);
}

#pragma region Drag and Drop

// Create a type to add as a lua usertype
struct LuaImGuiPayload
{
	// This may only contain serializable types. See SetDragDropPayload, etc.
	using VarType = std::variant<bool, int, lua_Number, std::string, std::vector<float>, ImVec4>;
	VarType data;

	const ImGuiPayload* payload;

	LuaImGuiPayload(const ImGuiPayload* payload)
		: payload(payload)
	{
	}

	const char* GetType() const
	{
		return payload ? payload->DataType : "";
	}

	sol::object GetData(sol::this_state L) const
	{
		return std::visit(overload{
			[&](bool value) { return sol::make_object(L, value); },
			[&](int value) { return sol::make_object(L, value); },
			[&](lua_Number value) { return sol::make_object(L, value); },
			[&](const std::string& value) { return sol::make_object(L, value); },
			[&](const std::vector<float>& value) { return sol::make_object(L, sol::as_table(value)); },
			[&](const ImVec4& value) { return sol::make_object(L, value); }
		}, data);
	}

	std::string GetRawDataAsString() const
	{
		return payload
			? std::string(static_cast<char*>(payload->Data), static_cast<char*>(payload->Data) + payload->DataSize)
			: std::string();
	}
};

enum class DragDropPayloadType : uint8_t
{
	Bool = 0,
	Int = 1,
	Number = 2,
	String = 3,
	NumberList = 4,
	Vec4 = 5,
};

static bool SetDragDropPayload(sol::this_state L, const char* type, bool boolVal, std::optional<int> cond)
{
	uint8_t buffer[1 + sizeof(bool)];
	buffer[0] = static_cast<uint8_t>(DragDropPayloadType::Bool);
	memcpy(&buffer[1], &boolVal, sizeof(bool));

	return ImGui::SetDragDropPayload(type, buffer, sizeof(buffer), cond.value_or(0));
}

static bool SetDragDropPayload(sol::this_state L, const char* type, int intVal, std::optional<int> cond)
{
	uint8_t buffer[1 + sizeof(int)];
	buffer[0] = static_cast<uint8_t>(DragDropPayloadType::Int);
	memcpy(&buffer[1], &intVal, sizeof(int));

	return ImGui::SetDragDropPayload(type, buffer, sizeof(buffer), cond.value_or(0));
}

static bool SetDragDropPayload(sol::this_state L, const char* type, lua_Number numVal, std::optional<int> cond)
{
	uint8_t buffer[1 + sizeof(lua_Number)];
	buffer[0] = static_cast<uint8_t>(DragDropPayloadType::Number);
	memcpy(&buffer[1], &numVal, sizeof(lua_Number));

	return ImGui::SetDragDropPayload(type, buffer, sizeof(buffer), cond.value_or(0));
}

static bool SetDragDropPayload(sol::this_state L, const char* type, std::string_view strVal, std::optional<int> cond)
{
	fmt::memory_buffer buffer;
	buffer.push_back(static_cast<char>(DragDropPayloadType::String));
	buffer.append(strVal);

	return ImGui::SetDragDropPayload(type, buffer.data(), buffer.size(), cond.value_or(0));
}

static bool SetDragDropPayload(sol::this_state L, const char* type, const std::vector<float>& vectorVal, std::optional<int> cond)
{
	if (strcmp(type, IMGUI_PAYLOAD_TYPE_COLOR_3F) == 0)
	{
		if (vectorVal.size() != 3)
			luaL_error(L, "Invalid payload for datatype: %s", IMGUI_PAYLOAD_TYPE_COLOR_3F);

		return ImGui::SetDragDropPayload(type, vectorVal.data(), sizeof(float) * vectorVal.size(), cond.value_or(0));
	}
	if (strcmp(type, IMGUI_PAYLOAD_TYPE_COLOR_4F) == 0)
	{
		if (vectorVal.size() != 4)
			luaL_error(L, "Invalid payload for datatype: %s", IMGUI_PAYLOAD_TYPE_COLOR_4F);

		return ImGui::SetDragDropPayload(type, vectorVal.data(), sizeof(float) * vectorVal.size(), cond.value_or(0));
	}

	size_t bufferSize = 1 + sizeof(int) + sizeof(float) * vectorVal.size();
	auto buffer = std::make_unique<uint8_t[]>(bufferSize);
	buffer[0] = static_cast<uint8_t>(DragDropPayloadType::NumberList);

	uint8_t* bufferPtr = buffer.get() + 1;
	int size = static_cast<int>(vectorVal.size());
	memcpy(bufferPtr, &size, sizeof(int));
	bufferPtr += sizeof(int);
	memcpy(bufferPtr, vectorVal.data(), sizeof(float) * vectorVal.size());

	return ImGui::SetDragDropPayload(type, buffer.get(), bufferSize, cond.value_or(0));
}

static bool SetDragDropPayload(sol::this_state L, const char* type, const ImVec4& vec4Val, std::optional<int> cond)
{
	// Special case: If we set _COL3F as our datatype, only store three components of the color val.
	if (strcmp(type, IMGUI_PAYLOAD_TYPE_COLOR_3F) == 0)
	{
		return ImGui::SetDragDropPayload(type, &vec4Val.x, sizeof(float) * 3, cond.value_or(0));
	}

	return ImGui::SetDragDropPayload(type, &vec4Val.x, sizeof(float) * 4, cond.value_or(0));
}

static std::unique_ptr<LuaImGuiPayload> DeserializePayload(const ImGuiPayload* payload)
{
	if (!payload)
		return nullptr;

	if (payload->DataSize <= 1)
		return nullptr;

	switch (DragDropPayloadType type = static_cast<DragDropPayloadType>(*(static_cast<uint8_t*>(payload->Data))))
	{
	case DragDropPayloadType::Bool:
	{
		if (payload->DataSize != 1 + sizeof(bool))
			return nullptr;

		bool boolVal;
		memcpy(&boolVal, static_cast<uint8_t*>(payload->Data) + 1, sizeof(bool));

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = { boolVal };
		return luaPayload;
	}

	case DragDropPayloadType::Int:
	{
		if (payload->DataSize != 1 + sizeof(int))
			return nullptr;

		int intVal;
		memcpy(&intVal, static_cast<uint8_t*>(payload->Data) + 1, sizeof(int));

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = { intVal };
		return luaPayload;
	}

	case DragDropPayloadType::Number:
	{
		if (payload->DataSize != 1 + sizeof(lua_Number))
			return nullptr;

		lua_Number numVal;
		memcpy(&numVal, static_cast<uint8_t*>(payload->Data) + 1, sizeof(lua_Number));

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = { numVal };
		return luaPayload;
	}

	case DragDropPayloadType::String:
	{
		std::string strVal{
			reinterpret_cast<char*>(static_cast<uint8_t*>(payload->Data) + 1),
			static_cast<size_t>(payload->DataSize - 1)
		};

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = { std::move(strVal) };
		return luaPayload;
	}

	case DragDropPayloadType::NumberList:
	{
		if (payload->DataSize < static_cast<int>(1 + sizeof(int)))
			return nullptr;

		uint8_t* data = static_cast<uint8_t*>(payload->Data) + 1;
		int size = *reinterpret_cast<int*>(data);
		data += sizeof(int);

		if (payload->DataSize != 1 + sizeof(int) + sizeof(float) * size)
			return nullptr;
		
		std::vector<float> floatList(size);
		memcpy(floatList.data(), data, sizeof(float) * size);

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = { std::move(floatList) };
		return luaPayload;
	}

	case DragDropPayloadType::Vec4:
	{
		if (payload->DataSize != sizeof(float) * 4)
			return nullptr;

		ImVec4* data = reinterpret_cast<ImVec4*>(static_cast<uint8_t*>(payload->Data) + 1);

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = { *data };
		return luaPayload;
	}

	default:
		return nullptr;
	}
}

static std::unique_ptr<LuaImGuiPayload> AcceptDragDropPayload(const char* type, std::optional<int> flags)
{
	const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(type, flags.value_or(0));

	if (payload == nullptr)
		return nullptr;

	if (strcmp(type, IMGUI_PAYLOAD_TYPE_COLOR_3F) == 0)
	{
		if (payload->DataSize != sizeof(float) * 3)
			return nullptr;

		float* payloadData = static_cast<float*>(payload->Data);
		std::vector<float> vectorVal(payloadData, payloadData + 3);

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = vectorVal;

		return luaPayload;
	}

	if (strcmp(type, IMGUI_PAYLOAD_TYPE_COLOR_4F) == 0)
	{
		if (payload->DataSize != sizeof(float) * 4)
			return nullptr;

		float* payloadData = static_cast<float*>(payload->Data);
		std::vector<float> vectorVal(payloadData, payloadData + 4);

		auto luaPayload = std::make_unique<LuaImGuiPayload>(payload);
		luaPayload->data = vectorVal;

		return luaPayload;
	}

	return DeserializePayload(payload);
}

static std::unique_ptr<LuaImGuiPayload> GetDragDropPayload()
{
	const ImGuiPayload* payload = ImGui::GetDragDropPayload();
	return DeserializePayload(payload);
}
#pragma endregion

#pragma region Color Utilities
static sol::as_table_t<std::vector<float>> ColorConvertU32ToFloat4(unsigned int in)
{
	const ImVec4 vec4 = ImGui::ColorConvertU32ToFloat4(in);
	sol::as_table_t rgba = sol::as_table(std::vector<float>{
		vec4.x, vec4.y, vec4.z, vec4.w
	});

	return rgba;
}
static unsigned int ColorConvertFloat4ToU32(const sol::table& rgba)
{
	const lua_Number
		r{ rgba[1].get<std::optional<lua_Number>>().value_or(lua_Number(0)) },
		g{ rgba[2].get<std::optional<lua_Number>>().value_or(lua_Number(0)) },
		b{ rgba[3].get<std::optional<lua_Number>>().value_or(lua_Number(0)) },
		a{ rgba[4].get<std::optional<lua_Number>>().value_or(lua_Number(0)) };

	return ImGui::ColorConvertFloat4ToU32({ float(r), float(g), float(b), float(a) });
}
#pragma endregion

sol::table RegisterBindings_ImGui(sol::state_view state)
{
	bool imguiRegistered = state.get_or("_imgui_registered", false);
	if (imguiRegistered) return state["ImGui"];
	state["_imgui_registered"] = true;

	sol::table ImGui = state.create_named_table("ImGui");
	bindings::RegisterBindings_ImGuiEnums(state);
	bindings::RegisterBindings_ImGuiUserTypes(state);

	// Main
	ImGui.set_function("GetIO", ImGui::GetIO);
	ImGui.set_function("GetStyle", []() { return &ImGui::GetStyle(); });

	#pragma region Demo, Debug, Information
	// Demo, Debug, Information
	ImGui.set_function("ShowDemoWindow", sol::overload(
		[]() { ImGui::ShowDemoWindow(); },
		[](bool show) { ImGui::ShowDemoWindow(&show); return show; }));
	ImGui.set_function("ShowMetricsWindow", sol::overload(
		[]() { ImGui::ShowMetricsWindow(); },
		[](bool show) { ImGui::ShowMetricsWindow(&show); return show; }));
	ImGui.set_function("ShowDebugLogWindow", sol::overload(
		[]() { ImGui::ShowDebugLogWindow(); },
		[](bool show) { ImGui::ShowDebugLogWindow(&show); return show; }));
	ImGui.set_function("ShowIDStackToolWindow", sol::overload(
		[]() { ImGui::ShowIDStackToolWindow(); },
		[](bool show) { ImGui::ShowIDStackToolWindow(&show); return show; }));
	ImGui.set_function("ShowAboutWindow", sol::overload(
		[]() { ImGui::ShowAboutWindow(); },
		[](bool show) { ImGui::ShowAboutWindow(&show); return show; }));
	ImGui.set_function("ShowStyleEditor", sol::overload(
		[]() { ImGui::ShowStyleEditor(); },
		[](ImGuiStyle* ref) { ImGui::ShowStyleEditor(ref); }
	));
	ImGui.set_function("ShowStyleSelector", &ImGui::ShowStyleSelector);
	ImGui.set_function("ShowFontSelector", &ImGui::ShowFontSelector);
	ImGui.set_function("ShowUserGuide", &ImGui::ShowUserGuide);
	ImGui.set_function("GetVersion", &ImGui::GetVersion);
	#pragma endregion

	#pragma region Styles
	// Styles
	ImGui.set_function("StyleColorsDark", []() { auto style = std::make_shared<ImGuiStyle>(); ImGui::StyleColorsDark(style.get()); return style; });
	ImGui.set_function("StyleColorsLight", []() { auto style = std::make_shared<ImGuiStyle>(); ImGui::StyleColorsLight(style.get()); return style; });
	ImGui.set_function("StyleColorsClassic", []() { auto style = std::make_shared<ImGuiStyle>(); ImGui::StyleColorsClassic(style.get()); return style; });
	#pragma endregion

	#pragma region Windows
	// Windows
	ImGui.set_function("Begin", sol::overload(
		[](const char* name) { return ImGui::Begin(name); },
		[](const char* name, std::optional<bool> open, std::optional<int> flags) {
			if (!open.has_value()) { bool show = ImGui::Begin(name, nullptr, ImGuiWindowFlags(flags.value_or(0))); return std::make_tuple(true, show); }
			else { bool open_ = open.value(); bool show = ImGui::Begin(name, &open_, ImGuiWindowFlags(flags.value_or(0))); return std::make_tuple(open_, show); }
		}));
	ImGui.set_function("End", &ImGui::End);
	#pragma endregion

	#pragma region Child Windows
	// Child Windows
	ImGui.set_function("BeginChild", sol::overload(
		// Old format with bool for border: Deprecated
		[](const char* str_id, std::optional<float> size_x, std::optional<float> size_y, std::optional<bool> border, std::optional<int> flags)
		{
			return ImGui::BeginChild(str_id, ImVec2(size_x.value_or(0.f), size_y.value_or(0.f)), border.value_or(false) ? ImGuiChildFlags_Border : 0, flags.value_or(0));
		},
		[](const char* str_id, const ImVec2& size, std::optional<bool> border, std::optional<int> flags)
		{
			return ImGui::BeginChild(str_id, size, border.value_or(false) ? ImGuiChildFlags_Border : 0, flags.value_or(0));
		},
		// New format with child flags param
		[](const char* str_id, std::optional<float> size_x, std::optional<float> size_y, std::optional<int> child_flags, std::optional<int> flags)
		{
			return ImGui::BeginChild(str_id, ImVec2(size_x.value_or(0.f), size_y.value_or(0.f)), child_flags.value_or(0), flags.value_or(0));
		},
		[](const char* str_id, const ImVec2& size, std::optional<int> child_flags, std::optional<int> flags)
		{
			return ImGui::BeginChild(str_id, size, child_flags.value_or(0), flags.value_or(0));
		}
	));
	ImGui.set_function("EndChild", &ImGui::EndChild);
	#pragma endregion

	#pragma region Window Utilities
	// Window Utilities
	ImGui.set_function("IsWindowAppearing", &ImGui::IsWindowAppearing);
	ImGui.set_function("IsWindowCollapsed", &ImGui::IsWindowCollapsed);
	ImGui.set_function("IsWindowFocused", [](std::optional<int> flags) { return ImGui::IsWindowFocused(flags.value_or(0)); });
	ImGui.set_function("IsWindowHovered", [](std::optional<int> flags) { return ImGui::IsWindowHovered(flags.value_or(0)); });
	ImGui.set_function("GetWindowDrawList", &ImGui::GetWindowDrawList);
	ImGui.set_function("GetWindowDpiScale", &ImGui::GetWindowDpiScale);
	ImGui.set_function("GetWindowPos", []() { ImVec2 vec = ImGui::GetWindowPos();  return std::make_tuple(vec.x, vec.y); });
	ImGui.set_function("GetWindowPosVec", ImGui::GetWindowPos);
	ImGui.set_function("GetWindowSize", []() { ImVec2 vec = ImGui::GetWindowSize();  return std::make_tuple(vec.x, vec.y); });
	ImGui.set_function("GetWindowSizeVec", ImGui::GetWindowSize);
	ImGui.set_function("GetWindowWidth", &ImGui::GetWindowWidth);
	ImGui.set_function("GetWindowHeight", &ImGui::GetWindowHeight);
	ImGui.set_function("GetWindowViewport", &ImGui::GetWindowViewport);
	#pragma endregion

	#pragma region Window Manipulation
	// Window Manipulation
	ImGui.set_function("SetNextWindowPos", sol::overload(
		[](float posX, float posY, std::optional<int> cond, std::optional<float> pivotX, std::optional<float> pivotY) { ImGui::SetNextWindowPos({ posX, posY }, cond.value_or(0), { pivotX.value_or(0.f), pivotY.value_or(0.f) }); },
		[](const ImVec2& pos, std::optional<int> cond, std::optional<ImVec2> pivot) { ImGui::SetNextWindowPos(pos, cond.value_or(0), pivot.value_or(ImVec2(0, 0))); }
	));
	ImGui.set_function("SetNextWindowSize", sol::overload(
		[](float sizeX, float sizeY, std::optional<int> cond) { ImGui::SetNextWindowSize({ sizeX, sizeY }, cond.value_or(0)); },
		[](const ImVec2& size, std::optional<int> cond) { ImGui::SetNextWindowSize(size, cond.value_or(0)); }
	));
	ImGui.set_function("SetNextWindowSizeConstraints", sol::overload(
		[](sol::this_state s, const ImVec2& min, const ImVec2& max, std::optional<sol::function> callback)
		{
			if (callback.has_value()) {
				ImGui::SetNextWindowSizeConstraints(min, max, [callback, L = s.lua_state()](ImGuiSizeCallbackData* data) {
					sol::function_result result = sol::function(L, callback.value())(data->Pos, data->CurrentSize, data->DesiredSize);
					std::optional<ImVec2> value = result.get<std::optional<ImVec2>>();
					if (value.has_value())
						data->DesiredSize = *value;
				});
			} else {
				ImGui::SetNextWindowSizeConstraints(min, max);
			}
		},
		[](float minX, float minY, float maxX, float maxY) { ImGui::SetNextWindowSizeConstraints({ minX, minY }, { maxX, maxY }); }
	));
	ImGui.set_function("SetNextWindowContentSize", sol::overload(
		[](float sizeX, float sizeY) { ImGui::SetNextWindowContentSize({ sizeX,  sizeY }); },
		[](const ImVec2& size) { ImGui::SetNextWindowContentSize(size); }
	));
	ImGui.set_function("SetNextWindowCollapsed", [](bool collapsed, std::optional<int> cond) { ImGui::SetNextWindowCollapsed(collapsed, cond.value_or(0)); });
	ImGui.set_function("SetNextWindowFocus", &ImGui::SetNextWindowFocus);
	ImGui.set_function("SetNextWindowScroll", &ImGui::SetNextWindowScroll);
	ImGui.set_function("SetNextWindowBgAlpha", &ImGui::SetNextWindowBgAlpha);
	ImGui.set_function("SetNextWindowViewport", &ImGui::SetNextWindowViewport);

	ImGui.set_function("SetWindowPos", sol::overload(
		[](float posX, float posY, std::optional<int> cond) { ImGui::SetWindowPos({ posX, posY }, cond.value_or(0)); },
		[](const ImVec2& pos, std::optional<int> cond) { ImGui::SetWindowPos(pos, cond.value_or(0)); },
		[](const char* name, float posX, float posY, std::optional<int> cond) { ImGui::SetWindowPos(name, { posX, posY }, cond.value_or(0)); },
		[](const char* name, const ImVec2& pos, std::optional<int> cond) { ImGui::SetWindowPos(name, pos, cond.value_or(0)); }
	));
	ImGui.set_function("SetWindowSize", sol::overload(
		[](float sizeX, float sizeY, std::optional<int> cond) { ImGui::SetWindowSize({ sizeX, sizeY }, cond.value_or(0)); },
		[](const char* name, float sizeX, float sizeY, std::optional<int> cond) { ImGui::SetWindowSize(name, { sizeX, sizeY }, cond.value_or(0)); },
		[](const ImVec2& size, std::optional<int> cond) { ImGui::SetWindowSize(size, cond.value_or(0)); },
		[](const char* name, const ImVec2& size, std::optional<int> cond) { ImGui::SetWindowSize(name, size, cond.value_or(0)); }
	));
	ImGui.set_function("SetWindowCollapsed", sol::overload(
		[](bool collapsed, std::optional<int> cond) { ImGui::SetWindowCollapsed(collapsed, cond.value_or(0)); },
		[](const char* name, bool collapsed, std::optional<int> cond) { ImGui::SetWindowCollapsed(name, collapsed, cond.value_or(0)); }
	));
	ImGui.set_function("SetWindowFocus", sol::overload(
		[]() { ImGui::SetWindowFocus(); },
		[](std::optional<const char*> name) { ImGui::SetWindowFocus(name.value_or(nullptr)); }
	));
	ImGui.set_function("SetWindowFontScale", &ImGui::SetWindowFontScale);
	#pragma endregion

	#pragma region Content Region
	// Content Region
	ImGui.set_function("GetContentRegionAvail", []() { ImVec2 vec = ImGui::GetContentRegionAvail(); return std::make_tuple(vec.x, vec.y); });
	ImGui.set_function("GetContentRegionAvailVec", ImGui::GetContentRegionAvail);
	ImGui.set_function("GetContentRegionMax", []() { ImVec2 vec = ImGui::GetContentRegionMax(); return std::make_tuple(vec.x, vec.y); });
	ImGui.set_function("GetContentRegionMaxVec", &ImGui::GetContentRegionMax);
	ImGui.set_function("GetWindowContentRegionMin", []() { ImVec2 vec = ImGui::GetWindowContentRegionMin(); return std::make_tuple(vec.x, vec.y); });
	ImGui.set_function("GetWindowContentRegionMinVec", ImGui::GetWindowContentRegionMin);
	ImGui.set_function("GetWindowContentRegionMax", []() { ImVec2 vec = ImGui::GetWindowContentRegionMax(); return std::make_tuple(vec.x, vec.y); });
	ImGui.set_function("GetWindowContentRegionMaxVec", ImGui::GetWindowContentRegionMax);
	ImGui.set_function("GetWindowContentRegionWidth", []() { return ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x; });
	#pragma endregion

	#pragma region Windows Scrolling
	// Windows Scrolling
	ImGui.set_function("GetScrollX", &ImGui::GetScrollX);
	ImGui.set_function("GetScrollY", &ImGui::GetScrollY);
	ImGui.set_function("SetScrollX", [](float scroll_x) { ImGui::SetScrollX(scroll_x); });
	ImGui.set_function("SetScrollY", [](float scroll_y) { ImGui::SetScrollY(scroll_y); });
	ImGui.set_function("GetScrollMaxX", ImGui::GetScrollMaxX);
	ImGui.set_function("GetScrollMaxY", ImGui::GetScrollMaxY);
	ImGui.set_function("SetScrollHereX", [](std::optional<float> center_x_ratio) { ImGui::SetScrollHereX(center_x_ratio.value_or(0.5f)); });
	ImGui.set_function("SetScrollHereY", [](std::optional<float> center_y_ratio) { ImGui::SetScrollHereY(center_y_ratio.value_or(0.5f)); });
	ImGui.set_function("SetScrolFromPosX", [](float local_x, std::optional<float> center_x_ratio) { ImGui::SetScrollFromPosX(local_x, center_x_ratio.value_or(0.5f)); });
	ImGui.set_function("SetScrolFromPosY", [](float local_y, std::optional<float> center_y_ratio) { ImGui::SetScrollFromPosY(local_y, center_y_ratio.value_or(0.5f)); });
	#pragma endregion

	#pragma region Parameters Stacks (Shared)
	// Parameters stacks (shared)
	ImGui.set_function("PushFont", [](std::optional<ImFont*> font) { ImGui::PushFont(font.value_or(nullptr)); });
	ImGui.set_function("PopFont", &ImGui::PopFont);
	ImGui.set_function("PushStyleColor", sol::overload(
		[](int idx, int col) { ImGui::PushStyleColor(static_cast<ImGuiCol>(idx), ImU32(col)); },
		[](int idx, float colR, float colG, float colB, float colA) { ImGui::PushStyleColor(static_cast<ImGuiCol>(idx), { colR, colG, colB, colA }); },
		[](int idx, const ImVec4& col) { ImGui::PushStyleColor(static_cast<ImGuiCol>(idx), col); },
		[](sol::this_state L, int idx, sol::table col) { ImGuiPushStyleColorTable(L, static_cast<ImGuiCol>(idx), col); }
	));
	ImGui.set_function("PopStyleColor", [](std::optional<int> count) { ImGui::PopStyleColor(count.value_or(1)); });
	ImGui.set_function("PushStyleVar", sol::overload(
		[](int idx, float val) { ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), val); },
		[](int idx, float valX, float valY) { ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), { valX, valY }); },
		[](int idx, const ImVec2& val) { ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), val); }
	));
	// PushStyleVarX
	// PushStyleVarY
	ImGui.set_function("PopStyleVar", [](std::optional<int> count) { ImGui::PopStyleVar(count.value_or(1)); });
	ImGui.set_function("PushTabStop", &ImGui::PushTabStop); // DEPRECATED
	ImGui.set_function("PopTabStop", &ImGui::PopTabStop); // DEPRECATED
	ImGui.set_function("PushButtonRepeat", &ImGui::PushButtonRepeat); // DEPRECATED
	ImGui.set_function("PopButtonRepeat", &ImGui::PopButtonRepeat); // DEPRECATED
	ImGui.set_function("PushItemFlag", &ImGui::PushItemFlag);
	ImGui.set_function("PopItemFlag", &ImGui::PopItemFlag);
	#pragma endregion

	#pragma region Parameters stacks (current window)
	// Parameters stacks (current window)
	ImGui.set_function("PushItemWidth", &ImGui::PushItemWidth);
	ImGui.set_function("PopItemWidth", &ImGui::PopItemWidth);
	ImGui.set_function("SetNextItemWidth", &ImGui::SetNextItemWidth);
	ImGui.set_function("CalcItemWidth", &ImGui::CalcItemWidth);
	ImGui.set_function("PushTextWrapPos", [](std::optional<float> wrap_local_pos_x) { ImGui::PushTextWrapPos(wrap_local_pos_x.value_or(0.0f)); });
	ImGui.set_function("PopTextWrapPos", &ImGui::PopTextWrapPos);
	#pragma endregion

	#pragma region Style read access
	// Style read access
	ImGui.set_function("GetFont", &ImGui::GetFont);
	ImGui.set_function("GetFontSize", &ImGui::GetFontSize);
	ImGui.set_function("GetFontTexUvWhitePixel", &ImGui::GetFontTexUvWhitePixel);
	ImGui.set_function("GetColorU32", sol::overload(
		[](int idx, float alpha_mul) { return ImGui::GetColorU32(static_cast<ImGuiCol>(idx), alpha_mul); },
		[](float colR, float colG, float colB, float colA) { return ImGui::GetColorU32({ colR, colG, colB, colA }); },
		[](const ImVec4& col) { return ImGui::GetColorU32(col); },
		[](int col) { return ImGui::GetColorU32(ImU32(col)); }
	));
	ImGui.set_function("GetStyleColor", [](int idx) { ImVec4 col = ImGui::GetStyleColorVec4(static_cast<ImGuiCol>(idx)); return std::make_tuple(col.x, col.y, col.z, col.w); });
	ImGui.set_function("GetStyleColorVec4", &ImGui::GetStyleColorVec4);
	#pragma endregion

	#pragma region Layout cursor positioning
	// Layout cursor positioning
	ImGui.set_function("GetCursorScreenPos", []() { ImVec2 pos = ImGui::GetCursorScreenPos(); return std::make_tuple(pos.x, pos.y); });
	ImGui.set_function("GetCursorScreenPosVec", &ImGui::GetCursorScreenPos);
	ImGui.set_function("SetCursorScreenPos", sol::overload(
		[](float posX, float posY) { ImGui::SetCursorScreenPos({ posX, posY }); },
		[](const ImVec2& pos) { ImGui::SetCursorScreenPos(pos); }
	));
	ImGui.set_function("GetCursorPos", []() { ImVec2 pos = ImGui::GetCursorPos(); return std::make_tuple(pos.x, pos.y); });
	ImGui.set_function("GetCursorPosVec", &ImGui::GetCursorPos);
	ImGui.set_function("GetCursorPosX", &ImGui::GetCursorPosX);
	ImGui.set_function("GetCursorPosY", &ImGui::GetCursorPosY);
	ImGui.set_function("SetCursorPos", sol::overload(
		[](float posX, float posY) { ImGui::SetCursorPos({ posX, posY }); },
		[](const ImVec2& pos) { ImGui::SetCursorPos(pos); }
	));
	ImGui.set_function("SetCursorPosX", &ImGui::SetCursorPosX);
	ImGui.set_function("SetCursorPosY", &ImGui::SetCursorPosY);
	ImGui.set_function("GetCursorStartPos", []() { ImVec2 pos = ImGui::GetCursorStartPos(); return std::make_tuple(pos.x, pos.y); });
	ImGui.set_function("GetCursorStartPosVec", &ImGui::GetCursorStartPos);
	#pragma endregion

	#pragma region Other layout functions
	// Other layout functions
	ImGui.set_function("Separator", &ImGui::Separator);
	ImGui.set_function("SameLine", [](std::optional<float> offset_from_start_x, std::optional<float> spacing) { ImGui::SameLine(offset_from_start_x.value_or(0.0f), spacing.value_or(-1.0f)); });
	ImGui.set_function("NewLine", &ImGui::NewLine);
	ImGui.set_function("Spacing", &ImGui::Spacing);
	ImGui.set_function("Dummy", sol::overload(
		[](float sizeX, float sizeY) { ImGui::Dummy({ sizeX, sizeY }); },
		[](const ImVec2& size) { ImGui::Dummy(size); }
	));
	ImGui.set_function("Indent", [](std::optional<float> indent_w) { ImGui::Indent(indent_w.value_or(0.0f)); });
	ImGui.set_function("Unindent", [](std::optional<float> indent_w) { ImGui::Unindent(indent_w.value_or(0.0f)); });
	ImGui.set_function("BeginGroup", &ImGui::BeginGroup);
	ImGui.set_function("EndGroup", &ImGui::EndGroup);
	ImGui.set_function("AlignTextToFramePadding", &ImGui::AlignTextToFramePadding);
	ImGui.set_function("GetTextLineHeight", &ImGui::GetTextLineHeight);
	ImGui.set_function("GetTextLineHeightWithSpacing", &ImGui::GetTextLineHeightWithSpacing);
	ImGui.set_function("GetFrameHeight", &ImGui::GetFrameHeight);
	ImGui.set_function("GetFrameHeightWithSpacing", &ImGui::GetFrameHeightWithSpacing);
	#pragma endregion

	#pragma region ID stack / scopes
	// ID stack / scopes
	ImGui.set_function("PushID", sol::overload(
		[](std::string_view str_id) { ImGui::PushID(str_id.data(), str_id.data() + str_id.length()); },
		[](int int_id) { ImGui::PushID(int_id); },
		[](sol::object obj) { ImGui::PushID(obj.pointer()); }
	));
	ImGui.set_function("PopID", &ImGui::PopID);
	ImGui.set_function("GetID", sol::overload(
		[](std::string_view str_id) { ImGui::GetID(str_id.data(), str_id.data() + str_id.length()); },
		[](sol::object obj) { ImGui::GetID(obj.pointer()); }
	));
	#pragma endregion

	// Widgets - see lua_ImGuiWidgets.cpp

	#pragma region Tooltips
	ImGui.set_function("BeginTooltip", &ImGui::BeginTooltip);
	ImGui.set_function("EndTooltip", &ImGui::EndTooltip);
	ImGui.set_function("SetTooltip", [](sol::variadic_args args, sol::this_state s) { std::string text = format_text(s, args); ImGui::SetTooltip("%s", text.c_str()); });
	ImGui.set_function("BeginItemTooltip", &ImGui::BeginItemTooltip);
	ImGui.set_function("SetItemTooltip", [](sol::variadic_args args, sol::this_state s) { std::string text = format_text(s, args); ImGui::SetItemTooltip("%s", text.c_str()); });
	#pragma endregion

	#pragma region Popups, Modals
	ImGui.set_function("BeginPopup", [](const char* str_id, std::optional<int> flags) { return ImGui::BeginPopup(str_id, flags.value_or(0)); });
	ImGui.set_function("BeginPopupModal", sol::overload(
		[](const char* name, std::optional<bool> open, std::optional<bool> flags)
		{
			bool open_ = open.value_or(true);
			bool show = ImGui::BeginPopupModal(name, open.has_value() ? &open_ : nullptr, flags.value_or(0));
			return std::make_tuple(show, open_);
		}
	));
	ImGui.set_function("EndPopup", &ImGui::EndPopup);
	ImGui.set_function("OpenPopup", sol::overload(
		[](const char* str_id, std::optional<int> popup_flags) { ImGui::OpenPopup(str_id, popup_flags.value_or(0)); },
		[](ImGuiID id, std::optional<int> popup_flags) { ImGui::OpenPopup(id, popup_flags.value_or(0)); }
	));
	ImGui.set_function("OpenPopupOnItemClick", [](std::optional<const char*> str_id, std::optional<int> popup_flags) { ImGui::OpenPopupOnItemClick(str_id.value_or(nullptr), popup_flags.value_or(ImGuiPopupFlags_MouseButtonRight)); });
	ImGui.set_function("CloseCurrentPopup", &ImGui::CloseCurrentPopup);
	ImGui.set_function("BeginPopupContextItem", [](std::optional<const char*> str_id, std::optional<int> popup_flags) { return ImGui::BeginPopupContextItem(str_id.value_or(nullptr), popup_flags.value_or(ImGuiPopupFlags_MouseButtonRight)); });
	ImGui.set_function("BeginPopupContextWindow", [](std::optional<const char*> str_id, std::optional<int> popup_flags) { return ImGui::BeginPopupContextWindow(str_id.value_or(nullptr), popup_flags.value_or(ImGuiPopupFlags_MouseButtonRight)); });
	ImGui.set_function("BeginPopupContextVoid", [](std::optional<const char*> str_id, std::optional<int> popup_flags) { return ImGui::BeginPopupContextVoid(str_id.value_or(nullptr), popup_flags.value_or(ImGuiPopupFlags_MouseButtonRight)); });
	ImGui.set_function("IsPopupOpen", [](const char* str_id, std::optional<int> flags) { return ImGui::IsPopupOpen(str_id, flags.value_or(0)); });
#pragma endregion

	#pragma region Tables
	ImGui.set_function("BeginTable", sol::overload(
		[](const char* str_id, int column, std::optional<int> flags, std::optional<ImVec2> outer_size, std::optional<float> inner_width) {
			return ImGui::BeginTable(str_id, column, flags.value_or(0), outer_size.value_or(ImVec2(0, 0)), inner_width.value_or(0.0f));
		},
		[](const char* str_id, int column, int flags, float outer_size_x, float outer_size_y, std::optional<float> inner_width) {
			return ImGui::BeginTable(str_id, column, flags, ImVec2(outer_size_x, outer_size_y), inner_width.value_or(0.0f));
		}
	));
	ImGui.set_function("EndTable", &ImGui::EndTable);
	ImGui.set_function("TableNextRow", [](std::optional<int> flags, std::optional<float> min_row_height) { ImGui::TableNextRow(flags.value_or(0), min_row_height.value_or(0.0f)); });
	ImGui.set_function("TableNextColumn", &ImGui::TableNextColumn);
	ImGui.set_function("TableSetColumnIndex", &ImGui::TableSetColumnIndex);

	ImGui.set_function("TableSetupColumn", [](const char* label, std::optional<int> flags, std::optional<float> init_width_or_weight, std::optional<int> user_id) { ImGui::TableSetupColumn(label, flags.value_or(0), init_width_or_weight.value_or(0.0f), (ImGuiID)user_id.value_or(0)); });
	ImGui.set_function("TableSetupScrollFreeze", &ImGui::TableSetupScrollFreeze);
	ImGui.set_function("TableHeader", &ImGui::TableHeader);
	ImGui.set_function("TableHeadersRow", &ImGui::TableHeadersRow);
	ImGui.set_function("TableAngledHeadersRow", &ImGui::TableAngledHeadersRow);

	ImGui.set_function("TableGetSortSpecs", []() -> std::optional<ImGuiTableSortSpecs*> { auto specs = ImGui::TableGetSortSpecs(); if (specs) return std::make_optional(specs); else return {}; });
	ImGui.set_function("TableGetColumnCount", &ImGui::TableGetColumnCount);
	ImGui.set_function("TableGetColumnIndex", &ImGui::TableGetColumnIndex);
	ImGui.set_function("TableGetRowIndex", &ImGui::TableGetRowIndex);
	ImGui.set_function("TableGetColumnName", [](std::optional<int> column_n) { return ImGui::TableGetColumnName(column_n.value_or(-1)); });
	ImGui.set_function("TableGetColumnFlags", [](std::optional<int> column_n) { return ImGui::TableGetColumnFlags(column_n.value_or(-1)); });
	ImGui.set_function("TableSetColumnEnabled", [](int column_n, bool v) { ImGui::TableSetColumnEnabled(column_n, v); });
	ImGui.set_function("TableSetBgColor", sol::overload(
		[](int target, const ImVec4& color, std::optional<int> column_n) { ImGui::TableSetBgColor(target, ImGui::ColorConvertFloat4ToU32(color), column_n.value_or(-1)); },
		[](int target, float colorR, float colorG, float colorB, float colorA, std::optional<int> column_n) { ImGui::TableSetBgColor(target, ImGui::ColorConvertFloat4ToU32({colorR, colorG, colorB, colorA}), column_n.value_or(-1)); },
		[](int target, ImU32 color, std::optional<int> column_n) { ImGui::TableSetBgColor(target, color, column_n.value_or(-1)); }
	));

	ImGui.set_function("TableGetColumnIsVisible", [](std::optional<int> column_n) { return (ImGui::TableGetColumnFlags(column_n.value_or(-1)) & ImGuiTableColumnFlags_IsVisible) != 0; });
	ImGui.set_function("TableGetColumnIsSorted", [](std::optional<int> column_n) { return (ImGui::TableGetColumnFlags(column_n.value_or(-1)) & ImGuiTableColumnFlags_IsSorted) != 0; });
	ImGui.set_function("TableGetHoveredColumn", &ImGui::TableGetHoveredColumn);
	ImGui.set_function("TableGetColumnHasFlag", [](int flag, std::optional<int> column_n) { return (ImGui::TableGetColumnFlags(column_n.value_or(-1)) & flag) != 0; });
	#pragma endregion

	#pragma region Columns
	ImGui.set_function("Columns", [](std::optional<int> count, std::optional<const char*> id, std::optional<bool> border) { ImGui::Columns(count.value_or(1), id.value_or(nullptr), border.value_or(true)); });
	ImGui.set_function("NextColumn", &ImGui::NextColumn);
	ImGui.set_function("GetColumnIndex", &ImGui::GetColumnIndex);
	ImGui.set_function("GetColumnWidth", [](std::optional<int> column_index) { return ImGui::GetColumnWidth(column_index.value_or(-1)); });
	ImGui.set_function("SetColumnWidth", &ImGui::SetColumnWidth);
	ImGui.set_function("GetColumnOffset", [](std::optional<int> column_index) { return ImGui::GetColumnOffset(column_index.value_or(-1)); });
	ImGui.set_function("SetColumnOffset", &ImGui::SetColumnOffset);
	ImGui.set_function("GetColumnsCount", &ImGui::GetColumnsCount);
	#pragma endregion

	#pragma region Tab Bars, Tabs
	ImGui.set_function("BeginTabBar", [](const char* str_id, std::optional<int> flags) { return ImGui::BeginTabBar(str_id, flags.value_or(0)); });
	ImGui.set_function("EndTabBar", &ImGui::EndTabBar);
	ImGui.set_function("BeginTabItem",
		[](const char* label, std::optional<bool> open, std::optional<int> flags) {
			bool open_ = open.value_or(true); bool show = ImGui::BeginTabItem(label, open.has_value() ? &open_ : nullptr, flags.value_or(0));
			return std::make_tuple(open.has_value() ? open_ : show, show);
		});
	ImGui.set_function("EndTabItem", &ImGui::EndTabItem);
	ImGui.set_function("TabItemButton", [](const char* label, std::optional<int> flags) { return ImGui::TabItemButton(label, flags.value_or(0)); });
	ImGui.set_function("SetTabItemClosed", &ImGui::SetTabItemClosed);
	#pragma endregion

	#pragma region Docking
	ImGui.set_function("DockSpace", sol::overload(
		[](ImGuiID id, std::optional<ImVec2> size, std::optional<int> flags, std::optional<ImGuiWindowClass*> window_class) { return ImGui::DockSpace(id, size.value_or(ImVec2(0, 0)), flags.value_or(0), window_class.value_or(nullptr)); },
		[](ImGuiID id, float sizeX, float sizeY, std::optional<int> flags, std::optional<ImGuiWindowClass*> window_class) { return ImGui::DockSpace(id, { sizeX, sizeY }, flags.value_or(0), window_class.value_or(nullptr)); }
	));
	ImGui.set_function("DockSpaceOverViewport", sol::overload(
		[](std::optional<ImGuiViewport*> viewport, std::optional<int> flags, std::optional<ImGuiWindowClass*> window_class)
		{
			return ImGui::DockSpaceOverViewport(0, viewport.value_or(nullptr), flags.value_or(0), window_class.value_or(nullptr));
		},
		[](ImGuiID dockspace_id, std::optional<ImGuiViewport*> viewport, std::optional<int> flags, std::optional<ImGuiWindowClass*> window_class)
		{
			return ImGui::DockSpaceOverViewport(dockspace_id, viewport.value_or(nullptr), flags.value_or(0), window_class.value_or(nullptr));
		}
	));
	ImGui.set_function("SetNextWindowDockID", [](ImGuiID dock_id, std::optional<int> cond) { ImGui::SetNextWindowDockID(dock_id, cond.value_or(0)); });
	ImGui.set_function("SetNextWindowClass", [](ImGuiWindowClass* window_class) { ImGui::SetNextWindowClass(window_class); });
	ImGui.set_function("GetWindowDockID", &ImGui::GetWindowDockID);
	ImGui.set_function("IsWindowDocked", &ImGui::IsWindowDocked);
	#pragma endregion

	#pragma region Logging/Capture
	// Logging / Capture
	ImGui.set_function("LogToTTY", [](std::optional<int> auto_open_depth) { ImGui::LogToTTY(auto_open_depth.value_or(-1)); });
	ImGui.set_function("LogToFile", [](std::optional<int> auto_open_depth, std::optional<const char*> filename) { ImGui::LogToFile(auto_open_depth.value_or(-1), filename.value_or(nullptr)); });
	ImGui.set_function("LogToClipboard", [](std::optional<int> auto_open_depth) { ImGui::LogToClipboard(auto_open_depth.value_or(-1)); });
	ImGui.set_function("LogFinish", &ImGui::LogFinish);
	ImGui.set_function("LogButtons", &ImGui::LogButtons);
	ImGui.set_function("LogText", [](const char* text) { ImGui::LogText("%s", text); });
	#pragma endregion

	#pragma region Drag Drop
	ImGui.set_function("BeginDragDropSource", [](std::optional<int> flags) { return ImGui::BeginDragDropSource(flags.value_or(0)); });
	ImGui.set_function("SetDragDropPayload", sol::overload(
		[](sol::this_state L, const char* type, int value, std::optional<int> cond) { SetDragDropPayload(L, type, value, cond); },
		[](sol::this_state L, const char* type, lua_Number value, std::optional<int> cond) { SetDragDropPayload(L, type, value, cond); },
		[](sol::this_state L, const char* type, bool value, std::optional<int> cond) { SetDragDropPayload(L, type, value, cond); },
		[](sol::this_state L, const char* type, sol::string_view data, std::optional<int> cond) { SetDragDropPayload(L, type, data, cond); },
		[](sol::this_state L, const char* type, const std::vector<float>& table, std::optional<int> cond) { SetDragDropPayload(L, type, table, cond); },
		[](sol::this_state L, const char* type, const ImVec4& value, std::optional<int> cond) { SetDragDropPayload(L, type, value, cond); }
	));
	ImGui.set_function("EndDragDropSource", &ImGui::EndDragDropSource);
	ImGui.set_function("BeginDragDropTarget", &ImGui::BeginDragDropTarget);
	ImGui.set_function("AcceptDragDropPayload", &AcceptDragDropPayload);
	ImGui.set_function("EndDragDropTarget", &ImGui::EndDragDropTarget);
	ImGui.set_function("GetDragDropPayload", &GetDragDropPayload);

	state.new_usertype<LuaImGuiPayload>(
		"ImGuiPayload", sol::no_constructor,
		"DataType",     sol::readonly_property(&LuaImGuiPayload::GetType),
		"Data",         sol::readonly_property(&LuaImGuiPayload::GetData),
		"RawData",      sol::readonly_property(&LuaImGuiPayload::GetRawDataAsString)
	);
	#pragma endregion

	#pragma region Disabling
	// Disabling
	ImGui.set_function("BeginDisabled", [](std::optional<bool> disabled) { ImGui::BeginDisabled(disabled.value_or(true)); });
	ImGui.set_function("EndDisabled", &ImGui::EndDisabled);
	#pragma endregion

	// Clipping
	ImGui.set_function("PushClipRect", sol::overload(
		[](float min_x, float min_y, float max_x, float max_y, bool intersect_current) { ImGui::PushClipRect({ min_x, min_y }, { max_x, max_y }, intersect_current); },
		[](const ImVec2& clip_rect_min, const ImVec2& clip_rect_max, bool intersect_with_current_clip_rect) { ImGui::PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect); }
	));
	ImGui.set_function("PopClipRect", &ImGui::PopClipRect);

	// Focus, Activation
	ImGui.set_function("SetItemDefaultFocus", &ImGui::SetItemDefaultFocus);
	ImGui.set_function("SetKeyboardFocusHere", [](std::optional<int> offset) { ImGui::SetKeyboardFocusHere(offset.value_or(0)); });

	// Overlapping mode
	ImGui.set_function("SetNextItemAllowOverlap", &ImGui::SetNextItemAllowOverlap);
#pragma warning(suppress: 4996)
	ImGui.set_function("SetItemAllowOverlap", &ImGui::SetItemAllowOverlap); // OBSOLETE

	#pragma region Item/Widgets Utilities and Query Functions
	// Item/Widgets Utilities
	ImGui.set_function("IsItemHovered", [](std::optional<int> flags) { return ImGui::IsItemHovered(flags.value_or(0)); });
	ImGui.set_function("IsItemActive", &ImGui::IsItemActive);
	ImGui.set_function("IsItemFocused", &ImGui::IsItemFocused);
	ImGui.set_function("IsItemClicked", [](std::optional<int> mouse_button) { return ImGui::IsItemClicked(mouse_button.value_or(0)); });
	ImGui.set_function("IsItemVisible", &ImGui::IsItemVisible);
	ImGui.set_function("IsItemEdited", &ImGui::IsItemEdited);
	ImGui.set_function("IsItemActivated", &ImGui::IsItemActivated);
	ImGui.set_function("IsItemDeactivated", &ImGui::IsItemDeactivated);
	ImGui.set_function("IsItemDeactivatedAfterEdit", &ImGui::IsItemDeactivatedAfterEdit);
	ImGui.set_function("IsItemToggledOpen", &ImGui::IsItemToggledOpen);
	ImGui.set_function("IsAnyItemHovered", &ImGui::IsAnyItemHovered);
	ImGui.set_function("IsAnyItemActive", &ImGui::IsAnyItemActive);
	ImGui.set_function("IsAnyItemFocused", &ImGui::IsAnyItemFocused);
	ImGui.set_function("GetItemRectMinVec", &ImGui::GetItemRectMin);
	ImGui.set_function("GetItemRectMin", []() { ImVec2 vec2 = ImGui::GetItemRectMin(); return std::make_tuple(vec2.x, vec2.y); });
	ImGui.set_function("GetItemRectMaxVec", &ImGui::GetItemRectMax);
	ImGui.set_function("GetItemRectMax", []() { ImVec2 vec2 = ImGui::GetItemRectMax(); return std::make_tuple(vec2.x, vec2.y); });
	ImGui.set_function("GetItemRectSizeVec", &ImGui::GetItemRectSize);
	ImGui.set_function("GetItemRectSize", []() { ImVec2 vec2 = ImGui::GetItemRectSize(); return std::make_tuple(vec2.x, vec2.y); });
	#pragma endregion

	// Viewports
	ImGui.set_function("GetMainViewport", &ImGui::GetMainViewport);

	// Background/Foreground Draw Lists
	ImGui.set_function("GetBackgroundDrawList", sol::overload(
		[] { return ImGui::GetBackgroundDrawList(); },
		sol::resolve<ImDrawList* (ImGuiViewport*)>(&ImGui::GetBackgroundDrawList)));
	ImGui.set_function("GetForegroundDrawList", sol::overload(
		[] { return ImGui::GetForegroundDrawList(); },
		sol::resolve<ImDrawList* (ImGuiViewport*)>(&ImGui::GetForegroundDrawList)));

	// Miscellaneous Utilities
	ImGui.set_function("IsRectVisible", sol::overload(
		[](const ImVec2& size) { return ImGui::IsRectVisible(size); },
		[](const ImVec2& rect_min, const ImVec2& rect_max) { return ImGui::IsRectVisible(rect_min, rect_max); },
		[](float sizeX, float sizeY) { return ImGui::IsRectVisible({ sizeX, sizeY }); },
		[](float minX, float minY, float maxX, float maxY) { return ImGui::IsRectVisible({ minX, minY }, { maxX, maxY }); }
	));
	ImGui.set_function("GetTime", &ImGui::GetTime);
	ImGui.set_function("GetFrameCount", &ImGui::GetFrameCount);
	ImGui.set_function("GetDrawListSharedData", ImGui::GetDrawListSharedData);
	ImGui.set_function("GetStyleColorName", &ImGui::GetStyleColorName);

	// Text Utilities
	ImGui.set_function("CalcTextSizeVec", [](const char* text, std::optional<bool> hide_text_after_double_hash, std::optional<float> wrap_width) { return ImGui::CalcTextSize(text, nullptr, hide_text_after_double_hash.value_or(false), wrap_width.value_or(-1.0f)); });
	ImGui.set_function("CalcTextSize", [](const char* text, std::optional<bool> hide_text_after_double_hash, std::optional<float> wrap_width) { ImVec2 size = ImGui::CalcTextSize(text, nullptr, hide_text_after_double_hash.value_or(false), wrap_width.value_or(-1.0f)); return std::make_tuple(size.x, size.y); });

	#pragma region Color Utilities
	// Color Utilities
	ImGui.set_function("ColorConvertU32ToFloat4", ColorConvertU32ToFloat4);
	ImGui.set_function("ColorConvertFloat4ToU32", ColorConvertFloat4ToU32);
	ImGui.set_function("ColorConvertRGBtoHSV", [](float r, float g, float b) { float h, s, v; ImGui::ColorConvertRGBtoHSV(r, g, b, h, s, v); return std::make_tuple(h, s, v); });
	ImGui.set_function("ColorConvertHSVtoRGB", [](float h, float s, float v) { float r, g, b; ImGui::ColorConvertHSVtoRGB(h, s, v, r, g, b); return std::make_tuple(r, g, b); });
	state.set_function("IM_COL32", [](int colR, int colG, int colB, std::optional<int> colA) -> int { return IM_COL32(colR, colG, colB, colA.value_or(255)); });
	#pragma endregion

	#pragma region Inputs Utilities: Keyboard
	// Inputs Utilities: Keyboard
	ImGui.set_function("IsKeyDown", [](ImGuiKey key) { return ImGui::IsKeyDown(key); });
	ImGui.set_function("IsKeyPressed", [](ImGuiKey key, std::optional<bool> repeat) { return ImGui::IsKeyPressed(key, repeat.value_or(true)); });
	ImGui.set_function("IsKeyReleased", [](ImGuiKey key) { ImGui::IsKeyReleased(key); });
	ImGui.set_function("IsKeyChordPressed", [](ImGuiKeyChord chord) { return ImGui::IsKeyChordPressed(chord); });
	ImGui.set_function("GetKeyPressedAmount", &ImGui::GetKeyPressedAmount);
	ImGui.set_function("GetKeyName", &ImGui::GetKeyName);
	ImGui.set_function("SetNextFrameWantCaptureKeyboard", &ImGui::SetNextFrameWantCaptureKeyboard);
	ImGui.set_function("GetKeyIndex", [](uint32_t key) { return key; }); // Deprecated
	#pragma endregion

	#pragma region Inputs Utilities: Mouse
	// Inputs Utilities: Mouse
	ImGui.set_function("IsMouseDown", [](int button) { return ImGui::IsMouseDown(button); });
	ImGui.set_function("IsMouseClicked", [](int button, std::optional<bool> repeat) { return ImGui::IsMouseClicked(button, repeat.value_or(true)); });
	ImGui.set_function("IsMouseReleased", [](int button) { return ImGui::IsMouseReleased(button); });
	ImGui.set_function("IsMouseDoubleClicked", [](int button) { return ImGui::IsMouseDoubleClicked(button); });
	ImGui.set_function("GetMouseClickedCount", [](int button) { return ImGui::GetMouseClickedCount(button); });
	ImGui.set_function("IsMouseHoveringRect", sol::overload(
		[](const ImVec2& r_min, const ImVec2& r_max, std::optional<bool> clip) { return ImGui::IsMouseHoveringRect(r_min, r_max, clip.value_or(true)); },
		[](float min_x, float min_y, float max_x, float max_y, std::optional<bool> clip) { return ImGui::IsMouseHoveringRect({ min_x, min_y }, { max_x, max_y }, clip.value_or(true)); }
	));
	ImGui.set_function("IsMousePosValid", [](std::optional<ImVec2> mouse_pos) { return ImGui::IsMousePosValid(mouse_pos.has_value() ? &mouse_pos.value() : nullptr); });
	ImGui.set_function("IsAnyMouseDown", &ImGui::IsAnyMouseDown);
	ImGui.set_function("GetMousePosVec", &ImGui::GetMousePos);
	ImGui.set_function("GetMousePos", []() { ImVec2 vec2 = ImGui::GetMousePos(); return std::make_tuple(vec2.x, vec2.y); });
	ImGui.set_function("GetMousePosOnOpeningCurrentPopupVec", &ImGui::GetMousePosOnOpeningCurrentPopup);
	ImGui.set_function("GetMousePosOnOpeningCurrentPopup", []() { ImVec2 vec2 = ImGui::GetMousePosOnOpeningCurrentPopup(); return std::make_tuple(vec2.x, vec2.y); });
	ImGui.set_function("IsMouseDragging", [](int button, std::optional<float> lock_threshold) { return ImGui::IsMouseDragging(button, lock_threshold.value_or(-1.0f)); });
	ImGui.set_function("GetMouseDragDelta", [](std::optional<int> button, std::optional<float> lock_threshold) { ImVec2 vec2 = ImGui::GetMouseDragDelta(button.value_or(0), lock_threshold.value_or(-1.0f)); return std::make_tuple(vec2.x, vec2.y); });
	ImGui.set_function("GetMouseDragDelta", [](std::optional<int> button, std::optional<float> lock_threshold) { return ImGui::GetMouseDragDelta(button.value_or(0), lock_threshold.value_or(-1.0f)); });
	ImGui.set_function("ResetMouseDragDelta", [](std::optional<int> button) { ImGui::ResetMouseDragDelta(button.value_or(0)); });
	ImGui.set_function("GetMouseCursor", &ImGui::GetMouseCursor);
	ImGui.set_function("SetMouseCursor", &ImGui::SetMouseCursor);
	ImGui.set_function("SetNextFrameWantCaptureMouse", &ImGui::SetNextFrameWantCaptureMouse);
	#pragma endregion

	// Clipboard Utilities
	ImGui.set_function("GetClipboardText", &ImGui::GetClipboardText);
	ImGui.set_function("SetClipboardText", &ImGui::SetClipboardText);

#if IMGUI_HAS_STACK_LAYOUT
#pragma region StackLayout Functions
	ImGui.set_function("BeginHorizontal", sol::overload(
		[](const char* str_id, std::optional<ImVec2> size, std::optional<float> align) { ImGui::BeginHorizontal(str_id, size.value_or(ImVec2(0, 0)), align.value_or(-1.0f)); },
		[](int int_id, std::optional<ImVec2> size, std::optional<float> align) { ImGui::BeginHorizontal(int_id, size.value_or(ImVec2(0, 0)), align.value_or(-1.0f)); },
		[](sol::object obj, std::optional<ImVec2> size, std::optional<float> align) { ImGui::BeginHorizontal(obj.pointer(), size.value_or(ImVec2(0, 0)), align.value_or(-1.0f)); }
	));
	ImGui.set_function("EndHorizontal", &ImGui::EndHorizontal);
	ImGui.set_function("BeginVertical", sol::overload(
		[](const char* str_id, std::optional<ImVec2> size, std::optional<float> align) { ImGui::BeginVertical(str_id, size.value_or(ImVec2(0, 0)), align.value_or(-1.0f)); },
		[](int int_id, std::optional<ImVec2> size, std::optional<float> align) { ImGui::BeginVertical(int_id, size.value_or(ImVec2(0, 0)), align.value_or(-1.0f)); },
		[](sol::object obj, std::optional<ImVec2> size, std::optional<float> align) { ImGui::BeginVertical(obj.pointer(), size.value_or(ImVec2(0, 0)), align.value_or(-1.0f)); }
	));
	ImGui.set_function("EndVertical", &ImGui::EndVertical);
	ImGui.set_function("Spring", [](std::optional<float> weight, std::optional<float> spacing) { ImGui::Spring(weight.value_or(1.0f), spacing.value_or(-1.0f)); });
	ImGui.set_function("SuspendLayout", &ImGui::SuspendLayout);
	ImGui.set_function("ResumeLayout", &ImGui::ResumeLayout);
#pragma endregion
#endif // IMGUI_HAS_STACK_LAYOUT

#pragma region Obsolete Functions
	// OBSOLETE 
	ImGui.set_function("PushAllowKeyboardFocus", [](bool tab_stop) { ImGui::PushItemFlag(ImGuiItemFlags_NoTabStop, !tab_stop); });
	ImGui.set_function("PopAllowKeyboardFocus", []() { ImGui::PopItemFlag(); });
	ImGui.set_function("CaptureKeyboardFromApp", [](std::optional<bool> want_capture_keyboard) { ImGui::SetNextFrameWantCaptureKeyboard(want_capture_keyboard.value_or(true)); });
	ImGui.set_function("CaptureMouseFromApp", [](std::optional<bool> want_capture_mouse) { ImGui::SetNextFrameWantCaptureMouse(want_capture_mouse.value_or(true)); });

	ImGui.set_function("BeginChildFrame", sol::overload(
		[](ImGuiID id, float sizeX, float sizeY, std::optional<int> flags) { return ImGui::BeginChild(id, { sizeX, sizeY }, ImGuiChildFlags_FrameStyle, flags.value_or(0)); },
		[](ImGuiID id, const ImVec2& size, std::optional<int> flags) { return ImGui::BeginChild(id, size, ImGuiChildFlags_FrameStyle, flags.value_or(0)); }
	));
	ImGui.set_function("EndChildFrame", &ImGui::EndChildFrame);
#pragma endregion

	bindings::RegisterBindings_ImGuiWidgets(ImGui);
	bindings::RegisterBindings_ImGuiCustom(ImGui);

	return ImGui;
}

} // namespace mq::lua::bindings
