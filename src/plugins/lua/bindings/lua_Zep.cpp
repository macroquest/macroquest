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
#include <sol/sol.hpp>
#include <mq/Plugin.h>

#include <optional>
#include <string>

#include "mq/imgui/MQConsoleDelegate.h"
#include "zep/buffer.h"
#include "zep/glyph_iterator.h"
#include "mq/zep/ImGuiZepEditor.h"
#include "mq/zep/ImGuiZepConsole.h"
#include "zep/mode.h"
#include "zep/window.h"

namespace mq::lua::bindings {

//============================================================================

class LuaZepConsole;
class LuaZepEditor;

//============================================================================

class LuaZepEditor : public ImGuiZepEditor
{
public:
	using ImGuiZepEditor::ImGuiZepEditor;

	sol::table GetSyntaxProviders(sol::this_state L)
	{
		sol::state_view state(L);

		sol::table syntaxProviders = state.create_table();
		for (auto& [key, value] : GetEditor().GetSyntaxProviders())
		{
			syntaxProviders.add(
				state.create_table_with(
					"id", key,
					"name", value->name
				)
			);
		}

		return syntaxProviders;
	}
};

//============================================================================

class LuaZepConsoleDelegate : public MQConsoleDelegate
{
public:
	LuaZepConsoleDelegate(LuaZepConsole* pConsole)
		: m_pConsole(pConsole)
	{
	}

	bool OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button, uint32_t modifiers,
		const std::string& hyperlinkData, int hyperlinkId) override;

private:
	LuaZepConsole* m_pConsole;
};

class LuaZepConsole : public ImGuiZepConsole
{
public:
	LuaZepConsole(sol::this_state L, std::string_view id = "")
		: ImGuiZepConsole(id)
		, m_state(L)
	{
		SetDelegate(std::make_shared<LuaZepConsoleDelegate>(this));
	}

	void SetEventCallback(sol::function func)
	{
		m_eventCallback = func;
	}

	sol::function GetEventCallback() const
	{
		return m_eventCallback;
	}

	bool OnHyperlinkClicked(Zep::ZepMouseButton button, uint32_t modifiers,
		const std::string& hyperlinkData, int hyperlinkId)
	{
		if (m_eventCallback)
		{
			sol::table params = m_state.create_table();

			// Pretend its an ImGuiMouseButton
			params["button"] = static_cast<int>(button); 

			// Convert ModifierKey to ImGuiMod_XXX
			uint32_t modKeys = 0;
			if (modifiers & Zep::ModifierKey::Ctrl)
				modKeys |= ImGuiMod_Ctrl;
			if (modifiers & Zep::ModifierKey::Alt)
				modKeys |= ImGuiMod_Alt;
			if (modifiers & Zep::ModifierKey::Shift)
				modKeys |= ImGuiMod_Shift;
			params["modifiers"] = modKeys;

			params["data"] = hyperlinkData;
			params["hyperlinkId"] = hyperlinkId;

			sol::protected_function_result result = m_eventCallback("link", params);
			if (result.valid())
			{
				std::optional<bool> handled = result.get<std::optional<bool>>();

				return handled.value_or(false);
			}
			
			sol::error err = result;
			LuaError("Error handling link event: %s", err.what());
		}

		return false;
	}

	sol::safe_function m_eventCallback;
	sol::state_view m_state;
};

bool LuaZepConsoleDelegate::OnHyperlinkClicked(ImGuiZepConsole* console, Zep::ZepMouseButton button, uint32_t modifiers,
	const std::string& hyperlinkData, int hyperlinkId)
{
	if (MQConsoleDelegate::OnHyperlinkClicked(console, button, modifiers, hyperlinkData, hyperlinkId))
	{
		return true;
	}

	return m_pConsole->OnHyperlinkClicked(button, modifiers, hyperlinkData, hyperlinkId);
}

//============================================================================

sol::table RegisterBindings_Zep(sol::this_state L)
{
	// The creation of this namespace is gated by the ImGui namespace.
	sol::state_view lua{ L };

	sol::table Z = lua.create_table();

	using namespace Zep;

	// Zep::LineLocation
	Z.new_enum<LineLocation>(
		"LineLocation", {
		{ "None"                   , LineLocation::None },
		{ "LineFirstGraphChar"     , LineLocation::LineFirstGraphChar },
		{ "LineLastGraphChar"      , LineLocation::LineLastGraphChar },
		{ "LineLastNonCR"          , LineLocation::LineLastNonCR },
		{ "LineBegin"              , LineLocation::LineBegin },
		{ "BeyondLineEnd"          , LineLocation::BeyondLineEnd },
		{ "LineCRBegin"            , LineLocation::LineCRBegin },
	});

	Z.new_enum<FileFlags::Enum>(
		"BufferFlags", {
		{ "None"                   , FileFlags::None },
		{ "WindowsLineEndings"     , FileFlags::StrippedCR },        // Its CRLF line endings whe we strip the CR...
		{ "ReadOnly"               , FileFlags::ReadOnly },
		{ "Locked"                 , FileFlags::Locked },
		{ "Dirty"                  , FileFlags::Dirty },
		{ "HasWarnings"            , FileFlags::HasWarnings },
		{ "HasErrors"              , FileFlags::HasErrors },
		{ "DefaultBuffer"          , FileFlags::DefaultBuffer },
		{ "InsertTabs"             , FileFlags::InsertTabs }
	});

	Z.new_enum<WindowFlags::Enum>(
		"WindowFlags", {
		{ "None"                   , WindowFlags::None },
		{ "ShowWhiteSpace"         , WindowFlags::ShowWhiteSpace },
		{ "ShowCR"                 , WindowFlags::ShowCR },
		{ "ShowLineNumbers"        , WindowFlags::ShowLineNumbers },
		{ "ShowIndicators"         , WindowFlags::ShowIndicators },
		{ "ShowLineBackground"     , WindowFlags::ShowLineBackground },
		{ "ShowWrappedLineNumbers" , WindowFlags::ShowWrappedLineNumbers },
		{ "ShowAirLine"            , WindowFlags::ShowAirLine },
	});

	Z.new_enum<ImGuiZepConsoleCol_>(
		"ConsoleCol", {
		{ "Text"                   , ImGuiZepConsoleCol_Text },
		{ "Link"                   , ImGuiZepConsoleCol_Link },
		{ "LinkHover"              , ImGuiZepConsoleCol_LinkHover },
	});

	// Zep::Buffer
	Z.new_usertype<ZepBuffer>(
		"Buffer"                   , sol::no_constructor,
		"Clear"                    , &ZepBuffer::Clear,

		// Get/Set text - these are not a property as they are expensive and properties usually imply cheap access.
		"SetText"                  , [](ZepBuffer* pThis, std::string_view text) { pThis->SetText(text, true); },
		"GetText"                  , &ZepBuffer::GetText,

		"syntax"                   , sol::property(&ZepBuffer::GetSyntaxID, &ZepBuffer::SetSyntaxID),
		"name"                     , sol::readonly_property(&ZepBuffer::GetName),
		"displayName"              , sol::readonly_property(&ZepBuffer::GetDisplayName),
		"filePath"                 , sol::property([](ZepBuffer* pThis) { return pThis->GetFilePath().string(); }, &ZepBuffer::SetFilePath),
		"fileExtension"            , sol::readonly_property(&ZepBuffer::GetFileExtension),
		"Load"                     , [](ZepBuffer* pThis, std::string_view file) { pThis->Load(file); },
		"Save"                     , [](ZepBuffer* pThis) { int64_t size = 0; bool success = pThis->Save(size); return std::make_tuple(success, size); },

		// Flags
		"HasFlag"                  , &ZepBuffer::HasFileFlags,
		"ToggleFlag"               , &ZepBuffer::ToggleFileFlag,
		"SetFlags"                 , &ZepBuffer::SetFileFlags,
		"ClearFlags"               , &ZepBuffer::ClearFileFlags,
		"dirty"                    , sol::property([](ZepBuffer* pThis) { return pThis->HasFileFlags(Zep::FileFlags::Dirty); }, [](ZepBuffer* pThis, bool dirty) { pThis->SetFileFlags(Zep::FileFlags::Dirty, dirty); }),
		"readonly"                 , sol::property([](ZepBuffer* pThis) { return pThis->HasFileFlags(Zep::FileFlags::ReadOnly); }, [](ZepBuffer* pThis, bool readOnly) { pThis->SetFileFlags(Zep::FileFlags::ReadOnly, readOnly); }),

		"Find"                     , [](ZepBuffer* pThis, GlyphIterator start, std::string_view text) { pThis->Find(start, (uint8_t*)text.data(), (uint8_t*)(text.data() + text.size())); }
	);

	Z.new_usertype<GlyphIterator>(
		"GlyphIterator"            , sol::constructors<GlyphIterator(), GlyphIterator(const ZepBuffer*), GlyphIterator(const ZepBuffer*, unsigned long)>(),
		"index"                    , sol::readonly_property(&GlyphIterator::Index),
		"valid"                    , sol::readonly_property(&GlyphIterator::Valid),

		sol::meta_function::to_string            , [](GlyphIterator* pThis) { return fmt::format("GlyphIterator({})", pThis->Index()); },
		sol::meta_function::addition             , [](const GlyphIterator& a, int b) { return a + b; },
		sol::meta_function::subtraction          , [](const GlyphIterator& a, int b) { return a - b; },
		sol::meta_function::equal_to             , [](const GlyphIterator& a, const GlyphIterator& b) { return a == b; },
		sol::meta_function::less_than            , [](const GlyphIterator& a, const GlyphIterator& b) { return a < b; },
		sol::meta_function::less_than_or_equal_to, [](const GlyphIterator& a, const GlyphIterator& b) { return a <= b; },
		sol::meta_function::call                 , [](GlyphIterator* pThis) { return pThis->operator*(); },

		"Invalidate"               , &GlyphIterator::Invalidate,
		"MoveClamped"              , [](GlyphIterator* pThis, int count, std::optional<int> clamp) { return pThis->MoveClamped(count, static_cast<LineLocation>(clamp.value_or(0))); },
		"Move"                     , &GlyphIterator::Move,
		"Copy"                     , [](GlyphIterator* pThis) { return GlyphIterator(*pThis); },
		"Clamp"                    , &GlyphIterator::Clamp,
		"Peek"                     , &GlyphIterator::Peek,
		"PeekClamped"              , [](GlyphIterator* pThis, int count, std::optional<int> clamp) { return pThis->PeekLineClamped(count, static_cast<LineLocation>(clamp.value_or(0))); },
		"Clamped"                  , &GlyphIterator::Clamped
	);

	Z.new_usertype<LuaZepEditor>(
		"Editor"                   , sol::constructors<LuaZepEditor(), LuaZepEditor(std::string_view)>(),

		"Render"                   , sol::overload(
			[](LuaZepEditor* pThis, std::optional<ImVec2> displaySize) { pThis->Render(displaySize.value_or(ImVec2())); },
			[](LuaZepEditor* pThis, const char* id, std::optional<ImVec2> displaySize) { pThis->Render(id, displaySize.value_or(ImVec2())); }),

		// Flags
		"windowFlags"              , sol::property(&LuaZepEditor::GetWindowFlags, &ImGuiZepEditor::SetWindowFlags),
		"ToggleFlag"               , &LuaZepEditor::ToggleFlag,

		// Buffers
		"activeBuffer"             , sol::property(&LuaZepEditor::GetActiveBuffer, &ImGuiZepEditor::SetActiveBuffer),
		"buffers"                  , sol::readonly_property([](LuaZepEditor* pThis) { return sol::as_table(pThis->GetEditor().GetBuffers()); }),
		"CreateFileBuffer"         , [](LuaZepEditor* pThis, std::string_view file) { return pThis->CreateFileBuffer(file); },
		"CreateBuffer"             , [](LuaZepEditor* pThis, std::string_view name, std::optional<std::string_view> text) { return pThis->CreateBuffer(name, text.value_or("")); },
		"RemoveBuffer"             , &LuaZepEditor::RemoveBuffer,

		// Cursor
		"beginPos"                 , sol::readonly_property(&LuaZepEditor::Begin),
		"endPos"                   , sol::readonly_property(&LuaZepEditor::End),
		"cursor"                   , sol::property([](LuaZepEditor* pThis) { return pThis->GetWindow().GetBufferCursor(); },
			                                       [](LuaZepEditor* pThis, GlyphIterator location) { pThis->GetWindow().SetBufferCursor(location); }),
		"cursorPos"                , sol::readonly_property([](LuaZepEditor* pThis) { return mq::toImVec2(pThis->GetWindow().BufferToDisplay()); }),
		"mouseCursor"              , sol::readonly_property([](LuaZepEditor* pThis) { return pThis->GetWindow().GetMouseCursor(); }),

		// Misc
		"GetSyntaxList"            , &LuaZepEditor::GetSyntaxProviders
	);

	// Console is a specialized editor
	Z.new_usertype<LuaZepConsole>(
		"Console"                  , sol::constructors<LuaZepConsole(sol::this_state), LuaZepConsole(sol::this_state, std::string_view)>(),

		"Render", sol::overload(
			[](LuaZepConsole* pThis, std::optional<ImVec2> displaySize) { pThis->Render(displaySize.value_or(ImVec2())); },
			[](LuaZepConsole* pThis, const char* id, std::optional<ImVec2> displaySize) { pThis->Render(id, displaySize.value_or(ImVec2())); }
		),

		"Clear"                    , &LuaZepConsole::Clear,
		"IsCursorAtEnd"            , &LuaZepConsole::IsCursorAtEnd,
		"ScrollToBottom"           , &LuaZepConsole::ScrollToBottom,

		"autoScroll"               , sol::property(&LuaZepConsole::GetAutoScroll, &LuaZepConsole::SetAutoScroll),
		"maxBufferLines"           , sol::property(&ImGuiZepConsole::GetMaxBufferLines, &LuaZepConsole::SetMaxBufferLines),
		"opacity"                  , sol::property(&LuaZepConsole::GetOpacity, &LuaZepConsole::SetOpacity),
		"eventCallback"            , sol::property(&LuaZepConsole::GetEventCallback, &LuaZepConsole::SetEventCallback),

		"AppendText", sol::overload(
			// AppendText(text, ...)
			[](LuaZepConsole* pThis, std::string_view text) { pThis->AppendText(text, MQColor(0, 0, 0, 0), true); },
			[](LuaZepConsole* pThis, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(0, 0, 0, 0), true);
				return pThis;
			},
			// AppendText(color: int, text, ...)
			[](LuaZepConsole* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_abgr, col), true); },
			[](LuaZepConsole* pThis, int col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(MQColor::format_abgr, col), true);
				return pThis;
			},
			// AppendText(color: ImVec4, text, ...)
			[](LuaZepConsole* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), true); return pThis; },
			[](LuaZepConsole* pThis, const ImVec4& col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(col), true);
				return pThis;
			}),

		"AppendTextUnformatted", sol::overload(
			[](LuaZepConsole* pThis, std::string_view text) { pThis->AppendText(text, MQColor(0, 0, 0, 0), false); return pThis; },
			[](LuaZepConsole* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_abgr, col), false); return pThis; },
			[](LuaZepConsole* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), false); return pThis; }),

		"AppendHyperlink", sol::overload(
			// AppendHyperlink(hyperlinkData, text, ...)
			[](LuaZepConsole* pThis, std::string hyperlinkData, std::string_view text) { pThis->InsertHyperlink(pThis->End(), text, std::move(hyperlinkData)); return pThis; },
			[](LuaZepConsole* pThis, std::string hyperlinkData, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->InsertHyperlink(pThis->End(), text, std::move(hyperlinkData));
				return pThis;
			}
		),

		"PushStyleColor", sol::overload(
			[](LuaZepConsole* pThis, int idx, int col) { pThis->PushStyleColor(idx, ImU32(col)); },
			[](LuaZepConsole* pThis, int idx, float colR, float colG, float colB, float colA) { pThis->PushStyleColor(idx, ImVec4(colR, colG, colB, colA)); },
			[](LuaZepConsole* pThis, int idx, const ImVec4& col) { pThis->PushStyleColor(idx, col); }),
		"PopStyleColor",
			[](LuaZepConsole* pThis, std::optional<int> count) { pThis->PopStyleColor(count.value_or(1)); }
	);

	return Z;
}

} // namespace mq::lua::bindings
