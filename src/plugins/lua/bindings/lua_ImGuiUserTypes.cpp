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

#include "eqlib/game/UITextures.h"
#include "mq/imgui/Widgets.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "sol/sol.hpp"

#include <optional>
#include <string>

namespace mq::lua::bindings {

//============================================================================

ImVec4 TableToColor(sol::this_state L, sol::table table);

// Wrapper function to simulate inheritance with ImVec4 for simpler usage in lua
ImVec4 LuaImcolor()
{
	return ImVec4();
}

ImVec4 LuaImColor(float r, float g, float b)
{
	return ImVec4(r, g, b, 1.0f);
}

ImVec4 LuaImColor(float r, float g, float b, float a)
{
	return ImVec4(r, g, b, a);
}

ImVec4 LuaImColor(sol::this_state L, sol::table table)
{
	return TableToColor(L, table);
}

ImVec4 LuaImColor(const ImVec4& vec)
{
	return vec;
}

void RegisterBindings_ImGuiUserTypes(sol::state_view lua)
{
	// ImVec2
	lua.new_usertype<ImVec2>(
		"ImVec2"                                        , sol::call_constructor
		                                                , sol::constructors<ImVec2(), ImVec2(float, float)>(),
		"x"                                             , &ImVec2::x,
		"y"                                             , &ImVec2::y,
		sol::meta_function::to_string                   , [](const ImVec2& mThis) { return fmt::format("({},{})", mThis.x, mThis.y); },
		sol::meta_function::addition                    , sol::overload(
			                                              [](const ImVec2& a, const ImVec2& b) { return a + b; },
			                                              [](const ImVec2& a, float b)         { return ImVec2(a.x + b, a.y + b); }),
		sol::meta_function::subtraction                 , sol::overload(
			                                              [](const ImVec2& a, const ImVec2& b) { return a - b; },
			                                              [](const ImVec2& a, float b)         { return ImVec2(a.x - b, a.y - b); }),
		sol::meta_function::multiplication              , sol::overload(
			                                              [](const ImVec2& a, const ImVec2& b) { return a * b; },
			                                              [](const ImVec2& a, float b)         { return a * b; }),
		sol::meta_function::division                    , sol::overload(
			                                              [](const ImVec2& a, const ImVec2& b) { return a / b; },
			                                              [](const ImVec2& a, float b)         { return a / b; }),
		sol::meta_function::equal_to                    , [](const ImVec2& a, const ImVec2& b) { return a.x == b.x && a.y == b.y; },
		sol::meta_function::less_than                   , [](const ImVec2& a, const ImVec2& b) { return std::tie(a.x, a.y) < std::tie(b.x, b.y); },
		sol::meta_function::less_than_or_equal_to       , [](const ImVec2& a, const ImVec2& b) { return std::tie(a.x, a.y) <= std::tie(b.x, b.y); }

		// TODO: operator[] ?
	);

	// ImVec4
	lua.new_usertype<ImVec4>(
		"ImVec4"                                        , sol::call_constructor
		                                                , sol::constructors<ImVec4(), ImVec4(float, float, float, float)>(),
		"x"                                             , &ImVec4::x,
		"y"                                             , &ImVec4::y,
		"z"                                             , &ImVec4::z,
		"w"                                             , &ImVec4::w,

		"FromImU32"                                     , &ImVec4::FromImU32,
		"ToImU32"                                       , &ImVec4::ToImU32,

		sol::meta_function::to_string                   , [](ImVec4& a) { return fmt::format("({},{},{},{})", a.x, a.y, a.z, a.w); },

		sol::meta_function::addition                    , sol::overload(
			                                              [](const ImVec4& a, const ImVec4& b) { return a + b; },
			                                              [](const ImVec4& a, float b) { return ImVec4(a.x + b, a.y + b, a.z + b, a.w + b); }),
		sol::meta_function::subtraction                 , sol::overload(
			                                              [](const ImVec4& a, const ImVec4& b) { return a - b; },
			                                              [](const ImVec4& a, float b) { return ImVec4(a.x - b, a.y - b, a.z - b, a.w - b); }),
		sol::meta_function::multiplication              , sol::overload(
			                                              [](const ImVec4& a, const ImVec4& b) { return a * b; },
			                                              [](const ImVec4& a, float b) { return ImVec4(a.x * b, a.y * b, a.z * b, a.w * b); }),
		sol::meta_function::division                    , sol::overload(
			                                              [](const ImVec4& a, const ImVec4& b) { return ImVec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); },
			                                              [](const ImVec4& a, float b) { return ImVec4(a.x / b, a.y / b, a.z / b, a.w / b); }),
		sol::meta_function::equal_to                    , [](const ImVec4& a, const ImVec4& b) { return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w; },
		sol::meta_function::less_than                   , [](const ImVec4& a, const ImVec4& b) { return std::tie(a.x, a.y, a.z, a.w) < std::tie(b.x, b.y, b.z, b.w); },
		sol::meta_function::less_than_or_equal_to       , [](const ImVec4& a, const ImVec4& b) { return std::tie(a.x, a.y, a.z, a.w) <= std::tie(b.x, b.y, b.z, b.w); }
	);

	// ImColor, function pretends to be a constructor, but returns an ImVec4
	lua.set_function("ImColor", sol::overload(
		static_cast<ImVec4(*)()>(&LuaImcolor),
		static_cast<ImVec4(*)(float, float, float)>(&LuaImColor),
		static_cast<ImVec4(*)(float, float, float, float)>(&LuaImColor),
		static_cast<ImVec4(*)(sol::this_state, sol::table)>(&LuaImColor),
		static_cast<ImVec4(*)(const ImVec4&)>(&LuaImColor)
	));

	// ImGuiStyle
	lua.new_usertype<ImGuiStyle>(
		"ImGuiStyle"                                    , sol::no_constructor,

		"FontSizeBase"                                  , &ImGuiStyle::FontSizeBase,
		"FontScaleMain"                                 , &ImGuiStyle::FontScaleMain,
		"FontScaleDpi"                                  , &ImGuiStyle::FontScaleDpi,

		"Alpha"                                         , &ImGuiStyle::Alpha,
		"DisabledAlpha"                                 , &ImGuiStyle::DisabledAlpha,
		"WindowPadding"                                 , &ImGuiStyle::WindowPadding,
		"WindowRounding"                                , &ImGuiStyle::WindowRounding,
		"WindowBorderSize"                              , &ImGuiStyle::WindowBorderSize,
		"WindowBorderHoverPadding"                      , &ImGuiStyle::WindowBorderHoverPadding,
		"WindowMinSize"                                 , &ImGuiStyle::WindowMinSize,
		"WindowTitleAlign"                              , &ImGuiStyle::WindowTitleAlign,
		"WindowMenuButtonPosition"                      , &ImGuiStyle::WindowMenuButtonPosition,
		"ChildRounding"                                 , &ImGuiStyle::ChildRounding,
		"ChildBorderSize"                               , &ImGuiStyle::ChildBorderSize,
		"PopupRounding"                                 , &ImGuiStyle::PopupRounding,
		"PopupBorderSize"                               , &ImGuiStyle::PopupBorderSize,
		"FramePadding"                                  , &ImGuiStyle::FramePadding,
		"FrameRounding"                                 , &ImGuiStyle::FrameRounding,
		"FrameBorderSize"                               , &ImGuiStyle::FrameBorderSize,
		"ItemSpacing"                                   , &ImGuiStyle::ItemSpacing,
		"ItemInnerSpacing"                              , &ImGuiStyle::ItemInnerSpacing,
		"CellPadding"                                   , &ImGuiStyle::CellPadding,
		"TouchExtraPadding"                             , &ImGuiStyle::TouchExtraPadding,
		"IndentSpacing"                                 , &ImGuiStyle::IndentSpacing,
		"ColumnsMinSpacing"                             , &ImGuiStyle::ColumnsMinSpacing,
		"ScrollbarSize"                                 , &ImGuiStyle::ScrollbarSize,
		"ScrollbarRounding"                             , &ImGuiStyle::ScrollbarRounding,
		"ScrollbarPadding"                              , &ImGuiStyle::ScrollbarPadding,
		"GrabMinSize"                                   , &ImGuiStyle::GrabMinSize,
		"GrabRounding"                                  , &ImGuiStyle::GrabRounding,
		"LayoutAlign"                                   , &ImGuiStyle::LayoutAlign,
		"LogSliderDeadzone"                             , &ImGuiStyle::LogSliderDeadzone,
		"ImageBordersize"                               , &ImGuiStyle::ImageBorderSize,
		"TabRounding"                                   , &ImGuiStyle::TabRounding,
		"TabBorderSize"                                 , &ImGuiStyle::TabBorderSize,
		"TabMinWidthBase"                               , &ImGuiStyle::TabMinWidthBase,
		"TabMinWidthShrink"                             , &ImGuiStyle::TabMinWidthShrink,
		"TabCloseButtonMinWidthSelected"                , &ImGuiStyle::TabCloseButtonMinWidthSelected,
		"TabCloseButtonMinWidthUnselected"              , &ImGuiStyle::TabCloseButtonMinWidthUnselected,
		"TabBarBorderSize"                              , &ImGuiStyle::TabBarBorderSize,
		"TabBarOverlineSize"                            , &ImGuiStyle::TabBarOverlineSize,
		"TableAngledHeadersAngle"                       , &ImGuiStyle::TableAngledHeadersAngle,
		"TableAngledHeadersTextAlign"                   , &ImGuiStyle::TableAngledHeadersTextAlign,
		"TreeLinesFlags"                                , &ImGuiStyle::TreeLinesFlags,
		"TreeLinesSize"                                 , &ImGuiStyle::TreeLinesSize,
		"TreeLinesRounding"                             , &ImGuiStyle::TreeLinesRounding,
		"DragDropTargetRounding"                        , &ImGuiStyle::DragDropTargetRounding,
		"DragDropTargetBorderSize"                      , &ImGuiStyle::DragDropTargetBorderSize,
		"DragDropTargetPadding"                         , &ImGuiStyle::DragDropTargetPadding,
		"ColorButtonPosition"                           , &ImGuiStyle::ColorButtonPosition,
		"ButtonTextAlign"                               , &ImGuiStyle::ButtonTextAlign,
		"SelectableTextAlign"                           , &ImGuiStyle::SelectableTextAlign,
		"SeparatorTextBorderSize"                       , &ImGuiStyle::SeparatorTextBorderSize,
		"SeparatorTextAlign"                            , &ImGuiStyle::SeparatorTextAlign,
		"SeparatorTextPadding"                          , &ImGuiStyle::SeparatorTextPadding,
		"DisplayWindowPadding"                          , &ImGuiStyle::DisplayWindowPadding,
		"DisplaySafeAreaPadding"                        , &ImGuiStyle::DisplaySafeAreaPadding,
		"DockingNodeHasCloseButton"                     , &ImGuiStyle::DockingNodeHasCloseButton,
		"DockingSeparatorSize"                          , &ImGuiStyle::DockingSeparatorSize,
		"MouseCursorScale"                              , &ImGuiStyle::MouseCursorScale,
		"AntiAliasedLines"                              , &ImGuiStyle::AntiAliasedLines,
		"AntiAliasedLinesUseTex"                        , &ImGuiStyle::AntiAliasedLinesUseTex,
		"AntiAliasedFill"                               , &ImGuiStyle::AntiAliasedFill,
		"CurveTessellationTol"                          , &ImGuiStyle::CurveTessellationTol,
		"CircleSegmentMaxError"                         , &ImGuiStyle::CircleTessellationMaxError,
		"Colors"                                        , &ImGuiStyle::Colors,

		// Behaviors
		"HoverStationaryDelay"                          , &ImGuiStyle::HoverStationaryDelay,
		"HoverDelayShort"                               , &ImGuiStyle::HoverDelayShort,
		"HoverDelayNormal"                              , &ImGuiStyle::HoverDelayNormal,
		"HoverFlagsForTooltipMouse"                     , &ImGuiStyle::HoverFlagsForTooltipMouse,
		"HoverFlagsForTooltipNav"                       , &ImGuiStyle::HoverFlagsForTooltipNav,

		"ScaleAllSizes"                                 , &ImGuiStyle::ScaleAllSizes,

		// Deprecated
		"CircleSegmentMaxError"                         , &ImGuiStyle::CircleTessellationMaxError,
		"TabMinWidthForCloseButton"                     , &ImGuiStyle::TabCloseButtonMinWidthUnselected
	);

	// ImGuiIO
	lua.new_usertype<ImGuiIO>(
		"ImGuiIO"                                       , sol::no_constructor,

		"ConfigFlags"                                   , sol::readonly(&ImGuiIO::ConfigFlags),
		"BackendFlags"                                  , sol::readonly(&ImGuiIO::BackendFlags),
		"DisplaySize"                                   , sol::readonly(&ImGuiIO::DisplaySize),
		"DisplayFramebufferScale"                       , sol::readonly(&ImGuiIO::DisplayFramebufferScale),
		"DeltaTime"                                     , sol::readonly(&ImGuiIO::DeltaTime),
		"IniSavingRate"                                 , sol::readonly(&ImGuiIO::IniSavingRate),
		"IniFilename"                                   , sol::readonly(&ImGuiIO::IniFilename),
		"LogFilename"                                   , sol::readonly(&ImGuiIO::LogFilename),

		"Fonts"                                         , sol::readonly(&ImGuiIO::Fonts),
		"FontDefault"                                   , sol::readonly(&ImGuiIO::FontDefault),
		"FontAllowUserScaling"                          , sol::readonly(&ImGuiIO::FontAllowUserScaling),
		"FontGlobalScale"                               , sol::readonly(&ImGuiIO::FontGlobalScale), // OBSOLETE -> Moved to style.FontScaleMain

		"Framerate"                                     , sol::readonly(&ImGuiIO::Framerate),
		"MouseDelta"                                    , sol::readonly(&ImGuiIO::MouseDelta),
		"MousePos"                                      , sol::readonly(&ImGuiIO::MousePos),

		"KeyCtrl"                                       , sol::readonly(&ImGuiIO::KeyCtrl),
		"KeyShift"                                      , sol::readonly(&ImGuiIO::KeyShift),
		"KeyAlt"                                        , sol::readonly(&ImGuiIO::KeyAlt),
		"KeySuper"                                      , sol::readonly(&ImGuiIO::KeySuper)
	);

	// ImGuiListClipper
	lua.new_usertype<ImGuiListClipper>(
		"ImGuiListClipper"                              ,
		"Begin"                                         , sol::overload(
			                                              [](ImGuiListClipper& mthis, int items_count) { mthis.Begin(items_count); },
			                                              &ImGuiListClipper::Begin),
		"End"                                           , &ImGuiListClipper::End,
		"Step"                                          , &ImGuiListClipper::Step,
		"DisplayStart"                                  , &ImGuiListClipper::DisplayStart,
		"DisplayEnd"                                    , &ImGuiListClipper::DisplayEnd,

		"IncludeItemByIndex"                            , &ImGuiListClipper::IncludeItemByIndex,
		"IncludeItemsByIndex"                           , &ImGuiListClipper::IncludeItemsByIndex,
		"SeekCursorForItem"                             , &ImGuiListClipper::SeekCursorForItem
	);

	//----------------------------------------------------------------------------
	// Multi-selection system

	// Flags for BeginMultiSelect()
	lua.new_enum("ImGuiMultiSelectFlags", std::initializer_list<std::pair<std::string_view, int>>{
		{ "None"                                        , ImGuiMultiSelectFlags_None },
		{ "SingleSelect"                                , ImGuiMultiSelectFlags_SingleSelect },
		{ "NoSelectAll"                                 , ImGuiMultiSelectFlags_NoSelectAll },
		{ "NoRangeSelect"                               , ImGuiMultiSelectFlags_NoRangeSelect },
		{ "NoAutoSelect"                                , ImGuiMultiSelectFlags_NoAutoSelect },
		{ "NoAutoClear"                                 , ImGuiMultiSelectFlags_NoAutoClear },
		{ "NoAutoClearOnReselect"                       , ImGuiMultiSelectFlags_NoAutoClearOnReselect },
		{ "BoxSelect1d"                                 , ImGuiMultiSelectFlags_BoxSelect1d },
		{ "BoxSelect2d"                                 , ImGuiMultiSelectFlags_BoxSelect2d },
		{ "BoxSelectNoScroll"                           , ImGuiMultiSelectFlags_BoxSelectNoScroll },
		{ "ClearOnEscape"                               , ImGuiMultiSelectFlags_ClearOnEscape },
		{ "ClearOnClickVoid"                            , ImGuiMultiSelectFlags_ClearOnClickVoid },
		{ "ScopeWindow"                                 , ImGuiMultiSelectFlags_ScopeWindow },
		{ "ScopeRect"                                   , ImGuiMultiSelectFlags_ScopeRect },
		{ "SelectOnClick"                               , ImGuiMultiSelectFlags_SelectOnClick },
		{ "SelectOnClickRelease"                        , ImGuiMultiSelectFlags_SelectOnClickRelease },
		{ "NavWrapX"                                    , ImGuiMultiSelectFlags_NavWrapX },
		{ "NoSelectOnRightClick"                        , ImGuiMultiSelectFlags_NoSelectOnRightClick },
	});

	lua.new_usertype<ImGuiMultiSelectIO>(
		"ImGuiMultiSelectIO"                            , sol::no_constructor

		// TODO
	);

	lua.new_enum("ImGuiSelectionRequestType", std::initializer_list<std::pair<std::string_view, int>>{
		{ "None"                                        , ImGuiSelectionRequestType_None },
		{ "SetAll"                                      , ImGuiSelectionRequestType_SetAll },
		{ "SetRange"                                    , ImGuiSelectionRequestType_SetRange },
	});


	lua.new_usertype<ImGuiSelectionRequest>(
		"ImGuiSelectionRequest"                         , sol::no_constructor

		// TODO
	);

	// ImGuiSelectionBasicStorage?
	// ImGuiSelectionExternalStorage?

	// BeginMultiSelect
	// EndMultiSelect
	// SetNextItemSelectionUserData
	// IsItemToggledSelection

	//----------------------------------------------------------------------------
	// ImDrawListSharedData
	lua.new_usertype<ImDrawListSharedData>(
		"ImDrawListSharedData"                          , sol::no_constructor,

		"TexUvWhitePixel"                               , &ImDrawListSharedData::TexUvWhitePixel,
		"TexUvLines"                                    , &ImDrawListSharedData::TexUvLines,
		"FontAtlas"                                     , &ImDrawListSharedData::FontAtlas,
		"Font"                                          , &ImDrawListSharedData::Font,
		"FontSize"                                      , &ImDrawListSharedData::FontSize,
		"FontScale"                                     , &ImDrawListSharedData::FontScale,
		"CurveTessellationTol"                          , &ImDrawListSharedData::CurveTessellationTol,
		"CircleSegmentMaxError"                         , &ImDrawListSharedData::CircleSegmentMaxError,
		"InitialFringeScale"                            , &ImDrawListSharedData::InitialFringeScale,
		"InitialFlags"                                  , &ImDrawListSharedData::InitialFlags,
		"ClipRectFullscreen"                            , &ImDrawListSharedData::ClipRectFullscreen,
		// DrawLists

		"SetCircleTessellationMaxError"                 , &ImDrawListSharedData::SetCircleTessellationMaxError
	);

	//----------------------------------------------------------------------------
	// ImDrawList
	auto imDrawList = lua.new_usertype<ImDrawList>(
		"ImDrawList", sol::constructors<ImDrawList(ImDrawListSharedData*)>(),

		// Variables
		"Flags", &ImDrawList::Flags
	);

	// Functions
	imDrawList.set_function("PushClipRect", sol::overload(
		[](ImDrawList& mThis, ImVec2 clip_rect_min, ImVec2 clip_rect_max) { mThis.PushClipRect(clip_rect_min, clip_rect_min); },
		&ImDrawList::PushClipRect));
	imDrawList.set_function("PushClipRectFullScreen", &ImDrawList::PushClipRectFullScreen);
	imDrawList.set_function("PopClipRect", &ImDrawList::PopClipRect);
	imDrawList.set_function("PushTexture", &ImDrawList::PushTexture);
	imDrawList.set_function("PopTexture", &ImDrawList::PopTexture);
	imDrawList.set_function("PushTextureID", &ImDrawList::PushTexture);
	imDrawList.set_function("PopTextureID", &ImDrawList::PopTexture);
	imDrawList.set_function("GetClipRectMin", &ImDrawList::GetClipRectMin);
	imDrawList.set_function("GetClipRectMax", &ImDrawList::GetClipRectMax);
	imDrawList.set_function("ChannelsSplit", &ImDrawList::ChannelsSplit);
	imDrawList.set_function("ChannelsSetCurrent", &ImDrawList::ChannelsSetCurrent);
	imDrawList.set_function("ChannelsMerge", &ImDrawList::ChannelsMerge);

	// Primitives
	imDrawList.set_function("AddLine", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col) { mThis.AddLine(p1, p2, ImU32(col)); },
		&ImDrawList::AddLine));
	imDrawList.set_function("AddRect", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col) { mThis.AddRect(p1, p2, ImU32(col)); },
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col, float rounding) { mThis.AddRect(p1, p2, ImU32(col), rounding); },
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col, float rounding, int flags) { mThis.AddRect(p1, p2, ImU32(col), rounding, ImDrawFlags(flags)); },
		&ImDrawList::AddRect));
	imDrawList.set_function("AddRectFilled", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col) { mThis.AddRectFilled(p1, p2, ImU32(col)); },
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, int col, float rounding) { mThis.AddRectFilled(p1, p2, ImU32(col), rounding); },
		&ImDrawList::AddRectFilled));
	imDrawList.set_function("AddRectFilledMultiColor", &ImDrawList::AddRectFilledMultiColor);
	imDrawList.set_function("AddQuad", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col) { mThis.AddQuad(p1, p2, p3, p4, ImU32(col)); },
		&ImDrawList::AddQuad));
	imDrawList.set_function("AddQuadFilled", &ImDrawList::AddQuadFilled);
	imDrawList.set_function("AddTriangle", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col) { mThis.AddTriangle(p1, p2, p3, ImU32(col)); },
		&ImDrawList::AddTriangle));
	imDrawList.set_function("AddTriangleFilled", &ImDrawList::AddTriangleFilled);
	imDrawList.set_function("AddCircle", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col) { mThis.AddCircle(center, radius, ImU32(col)); },
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col, int num_segments) { mThis.AddCircle(center, radius, ImU32(col), num_segments); },
		&ImDrawList::AddCircle));
	imDrawList.set_function("AddCircleFilled", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col, int num_segments) { mThis.AddCircleFilled(center, radius, ImU32(col), num_segments); },
		&ImDrawList::AddCircleFilled));
	imDrawList.set_function("AddNgon", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, int col, int num_segments) { mThis.AddNgon(center, radius, col, num_segments); },
		&ImDrawList::AddNgon));
	imDrawList.set_function("AddNgonFilled", &ImDrawList::AddNgonFilled);
	// AddEllipse
	// AddEllipseFilled
	imDrawList.set_function("AddText", sol::overload(
		[](ImDrawList& mThis, const ImVec2& pos, int col, std::string_view text) { mThis.AddText(pos, ImU32(col), text.data(), text.data() + text.size()); },
		[](ImDrawList& mThis, ImFont* font, float font_size, const ImVec2& pos, int col, std::string_view text) { mThis.AddText(font, font_size, pos, ImU32(col), text.data(), text.data() + text.size()); }));
	imDrawList.set_function("AddBezierCubic", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int col, float thickness) { mThis.AddBezierCubic(p1, p2, p3, p4, ImU32(col), thickness); },
		&ImDrawList::AddBezierCubic));
	imDrawList.set_function("AddBezierQuadratic", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, int col, float thickness) { mThis.AddBezierQuadratic(p1, p2, p3, ImU32(col), thickness); },
		&ImDrawList::AddBezierQuadratic));
	imDrawList.set_function("AddPolyline", [](ImDrawList& mThis, const sol::as_table_t<std::vector<ImVec2>>& points, int col, int flags, float thickness)
		{
			const std::vector<ImVec2>& vecs = points.value();
			mThis.AddPolyline(&vecs[0], (int)vecs.size(), ImU32(col), ImDrawFlags(flags), thickness);
		});
	imDrawList.set_function("AddConvexPolyFilled", [](ImDrawList& mThis, const sol::as_table_t<std::vector<ImVec2>>& points, int col)
		{
			const std::vector<ImVec2>& vecs = points.value();
			mThis.AddConvexPolyFilled(&vecs[0], (int)vecs.size(), ImU32(col));
		});

	// Image primitives
	imDrawList.set_function("AddImage", sol::overload(
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p_min, const ImVec2& p_max) { mThis.AddImage(tex_ref, p_min, p_max);  },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min) { mThis.AddImage(tex_ref, p_min, p_max, uv_min); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max) { mThis.AddImage(tex_ref, p_min, p_max, uv_min, uv_max); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, int col) { mThis.AddImage(tex_ref, p_min, p_max, uv_min, uv_max, ImU32(col)); }
	));
	imDrawList.set_function("AddImageQuad", sol::overload(
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4) { mThis.AddImageQuad(tex_ref, p1, p2, p3, p4); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1) { mThis.AddImageQuad(tex_ref, p1, p2, p3, p4, uv1); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2) { mThis.AddImageQuad(tex_ref, p1, p2, p3, p4, uv1, uv2); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3) { mThis.AddImageQuad(tex_ref, p1, p2, p3, p4, uv1, uv2, uv3); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3, const ImVec2& uv4) { mThis.AddImageQuad(tex_ref, p1, p2, p3, p4, uv1, uv2, uv3, uv4); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& uv1, const ImVec2& uv2, const ImVec2& uv3, const ImVec2& uv4, int col) { mThis.AddImageQuad(tex_ref, p1, p2, p3, p4, uv1, uv2, uv3, uv4, ImU32(col)); }
	));
	imDrawList.set_function("AddImageRounded", sol::overload(
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, int col, float rounding) { mThis.AddImageRounded(tex_ref, p_min, p_max, uv_min, uv_max, ImU32(col), rounding); },
		[](ImDrawList& mThis, const ImTextureRef& tex_ref, const ImVec2& p_min, const ImVec2& p_max, const ImVec2& uv_min, const ImVec2& uv_max, int col, float rounding, int flags) { mThis.AddImageRounded(tex_ref, p_min, p_max, uv_min, uv_max, ImU32(col), rounding, ImDrawFlags(flags)); }
	));

	imDrawList.set_function("AddTextureAnimation",
		[](ImDrawList& mThis, const std::unique_ptr<eqlib::CTextureAnimation>& anim, const ImVec2& pos, std::optional<ImVec2> size) {
			return imgui::DrawTextureAnimation(&mThis, anim.get(), pos, size.has_value() ? eqlib::CXSize(*size) : eqlib::CXSize());
		});

	// Stateful Path API
	imDrawList.set_function("PathClear", &ImDrawList::PathClear);
	imDrawList.set_function("PathLineTo", &ImDrawList::PathLineTo);
	imDrawList.set_function("PathLineToMergeDuplicate", &ImDrawList::PathLineToMergeDuplicate);
	imDrawList.set_function("PathFillConvex", &ImDrawList::PathFillConvex);
	// PathFillConcave
	imDrawList.set_function("PathStroke", sol::overload(
		[](ImDrawList& mThis, int col) { mThis.PathStroke(ImU32(col)); },
		[](ImDrawList& mThis, int col, int flags) { mThis.PathStroke(ImU32(col), ImDrawFlags(flags)); },
		[](ImDrawList& mThis, int col, int flags, float thickness) { mThis.PathStroke(ImU32(col), ImDrawFlags(flags), thickness); }
	));
	imDrawList.set_function("PathArcTo", sol::overload(
		[](ImDrawList& mThis, const ImVec2& center, float radius, float a_min, float a_max) { mThis.PathArcTo(center, radius, a_min, a_max); },
		[](ImDrawList& mThis, const ImVec2& center, float radius, float a_min, float a_max, int num_segments) { mThis.PathArcTo(center, radius, a_min, a_max, num_segments); }
	));
	imDrawList.set_function("PathArcToFast", &ImDrawList::PathArcToFast);
	// EllipticalArcTo
	imDrawList.set_function("PathBezierCubicCurveTo", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4) { mThis.PathBezierCubicCurveTo(p2, p3, p4); },
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, int num_segments) { mThis.PathBezierCubicCurveTo(p2, p3, p4, num_segments); }
	));
	imDrawList.set_function("PathBezierQuadraticCurveTo", sol::overload(
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3) { mThis.PathBezierQuadraticCurveTo(p2, p3); },
		[](ImDrawList& mThis, const ImVec2& p2, const ImVec2& p3, int num_segments) { mThis.PathBezierQuadraticCurveTo(p2, p3, num_segments); }
	));
	imDrawList.set_function("PathRect", sol::overload(
		[](ImDrawList& mThis, const ImVec2& rect_min, const ImVec2& rect_max) { mThis.PathRect(rect_min, rect_max); },
		[](ImDrawList& mThis, const ImVec2& rect_min, const ImVec2& rect_max, float rounding) { mThis.PathRect(rect_min, rect_max, rounding); },
		[](ImDrawList& mThis, const ImVec2& rect_min, const ImVec2& rect_max, float rounding, int flags) { mThis.PathRect(rect_min, rect_max, rounding, ImDrawFlags(flags)); }
	));
	// AddCallback
	// AddDrawCmd
	// CloneOutput

	// PrimReserve
	// PrimUnreserve
	// PrimRect
	// PrimRectUV
	// PrimQuadUV
	// PrimWriteVtx
	// PrimWriteIdx
	// PrimVtx

	lua.new_usertype<ImGuiTableColumnSortSpecs>(
		"ImGuiTableSortSpecsColumn"    , sol::no_constructor,
		"ColumnUserID"                 , sol::readonly(&ImGuiTableColumnSortSpecs::ColumnUserID),
		"ColumnIndex"                  , sol::readonly(&ImGuiTableColumnSortSpecs::ColumnIndex),
		"SortOrder"                    , sol::readonly(&ImGuiTableColumnSortSpecs::SortOrder),
		"SortDirection"                , sol::property([](ImGuiTableColumnSortSpecs* spec) { return spec->SortDirection;})
	);
	lua.new_usertype<ImGuiTableSortSpecs>(
		"ImGuiTableSortSpecs"          , sol::no_constructor,
		"Specs"                        , [](ImGuiTableSortSpecs* spec, int index) -> ImGuiTableColumnSortSpecs* { if (index > 0 && index <= spec->SpecsCount) return (ImGuiTableColumnSortSpecs*)&spec->Specs[index - 1]; return nullptr; },
		"SpecsCount"                   , sol::readonly(&ImGuiTableSortSpecs::SpecsCount),
		"SpecsDirty"                   , &ImGuiTableSortSpecs::SpecsDirty
	);

	// ImGuiFontAtlas
	lua.new_usertype<ImFontAtlas>(
		"ImFontAtlas"                  , sol::no_constructor,

		"Flags"                        , &ImFontAtlas::Flags,
		"TexID"                        , &ImFontAtlas::TexID,
		"TexRef"                       , &ImFontAtlas::TexRef
		//"TexWidth"                     , sol::readonly(&ImFontAtlas::TexWidth),
		//"TexHeight"                    , sol::readonly(&ImFontAtlas::TexHeight)
	);


	// ImGuiViewport
	lua.new_usertype<ImGuiViewport>(
		"ImGuiViewport"                , sol::no_constructor,

		"ID"                           , sol::readonly(&ImGuiViewport::ID),
		"Flags"                        , sol::readonly(&ImGuiViewport::Flags),
		"Pos"                          , sol::readonly(&ImGuiViewport::Pos),
		"Size"                         , sol::readonly(&ImGuiViewport::Size),
		// FramebufferScale
		"WorkPos"                      , sol::readonly(&ImGuiViewport::WorkPos),
		"WorkSize"                     , sol::readonly(&ImGuiViewport::WorkSize),
		"DpiScale"                     , sol::readonly(&ImGuiViewport::DpiScale),
		"ParentViewportId"             , sol::readonly(&ImGuiViewport::ParentViewportId),
		// ParentViewport
		// DrawData

		"GetCenter"                    , &ImGuiViewport::GetCenter,
		"GetWorkCenter"                , &ImGuiViewport::GetWorkCenter
	);

	// ImGuiInputTextCallbackData
	lua.new_usertype<ImGuiInputTextCallbackData>(
		"ImGuiInputTextCallbackData"   , sol::no_constructor,

		"EventFlag"                    , sol::readonly(&ImGuiInputTextCallbackData::EventFlag),
		"Flags"                        , sol::readonly(&ImGuiInputTextCallbackData::Flags),

		"EventChar"                    , sol::property([](ImGuiInputTextCallbackData* pThis) { return (wchar_t)pThis->EventChar; }, [](ImGuiInputTextCallbackData* pThis, wchar_t value) { pThis->EventChar = (ImWchar)value; }),
		"EventKey"                     , sol::readonly(&ImGuiInputTextCallbackData::EventKey),
		"Buffer"                       , sol::readonly(&ImGuiInputTextCallbackData::Buf),
		"CursorPos"                    , &ImGuiInputTextCallbackData::CursorPos,
		"SelectionStart"               , &ImGuiInputTextCallbackData::SelectionStart,
		"SelectionEnd"                 , &ImGuiInputTextCallbackData::SelectionEnd,

		"DeleteChars"                  , [](ImGuiInputTextCallbackData& mThis, int pos, int bytesCount) { mThis.DeleteChars(pos, bytesCount); },
		"InsertChars"                  , [](ImGuiInputTextCallbackData& mThis, int pos, const char* text) { mThis.InsertChars(pos, text); },
		"SelectAll"                    , [](ImGuiInputTextCallbackData& mThis) { mThis.SelectAll(); },
		"ClearSelection"               , [](ImGuiInputTextCallbackData& mThis) { mThis.ClearSelection(); },
		"HasSelection"                 , [](ImGuiInputTextCallbackData& mThis) { return mThis.HasSelection(); }
	);

	// ImTextureRef - opaque type
	lua.new_usertype<ImTextureRef>(
		"ImTextureRef"                 , sol::no_constructor,

		"GetTexID"                     , &ImTextureRef::GetTexID
	);
}

} // namespace mq::lua::bindings
