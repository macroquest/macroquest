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

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <string>

namespace mq::lua::bindings {

//============================================================================

void RegisterBindings_ImGuiEnums(sol::state_view lua)
{
	// Window Flags
	lua.new_enum("ImGuiWindowFlags",
		"None"                         , ImGuiWindowFlags_None,
		"NoTitleBar"                   , ImGuiWindowFlags_NoTitleBar,
		"NoResize"                     , ImGuiWindowFlags_NoResize,
		"NoMove"                       , ImGuiWindowFlags_NoMove,
		"NoScrollbar"                  , ImGuiWindowFlags_NoScrollbar,
		"NoScrollWithMouse"            , ImGuiWindowFlags_NoScrollWithMouse,
		"NoCollapse"                   , ImGuiWindowFlags_NoCollapse,
		"AlwaysAutoResize"             , ImGuiWindowFlags_AlwaysAutoResize,
		"NoBackground"                 , ImGuiWindowFlags_NoBackground,
		"NoSavedSettings"              , ImGuiWindowFlags_NoSavedSettings,
		"NoMouseInputs"                , ImGuiWindowFlags_NoMouseInputs,
		"MenuBar"                      , ImGuiWindowFlags_MenuBar,
		"HorizontalScrollbar"          , ImGuiWindowFlags_HorizontalScrollbar,
		"NoFocusOnAppearing"           , ImGuiWindowFlags_NoFocusOnAppearing,
		"NoBringToFrontOnFocus"        , ImGuiWindowFlags_NoBringToFrontOnFocus,
		"AlwaysVerticalScrollbar"      , ImGuiWindowFlags_AlwaysVerticalScrollbar,
		"AlwaysHorizontalScrollbar"    , ImGuiWindowFlags_AlwaysHorizontalScrollbar,
		"AlwaysUseWindowPadding"       , ImGuiWindowFlags_AlwaysUseWindowPadding,
		"NoNavInputs"                  , ImGuiWindowFlags_NoNavInputs,
		"NoNavFocus"                   , ImGuiWindowFlags_NoNavFocus,
		"UnsavedDocument"              , ImGuiWindowFlags_UnsavedDocument,
		"NoDocking"                    , ImGuiWindowFlags_NoDocking,

		"NoNav"                        , ImGuiWindowFlags_NoNav,
		"NoDecoration"                 , ImGuiWindowFlags_NoDecoration,
		"NoInputs"                     , ImGuiWindowFlags_NoInputs,

		"NavFlattened"                 , ImGuiWindowFlags_NavFlattened,
		"ChildWindow"                  , ImGuiWindowFlags_ChildWindow,
		"Tooltip"                      , ImGuiWindowFlags_Tooltip,
		"Popup"                        , ImGuiWindowFlags_Popup,
		"Modal"                        , ImGuiWindowFlags_Modal,
		"ChildMenu"                    , ImGuiWindowFlags_ChildMenu,

#ifdef CUSTOM_IMGUI
		"DockNodeHost"                 , ImGuiWindowFlags_DockNodeHost,
		"NoClose"                      , ImGuiWindowFlags_NoClose,
		"NoDockTab"                    , ImGuiWindowFlags_NoDockTab
#else
		"DockNodeHost"                 , ImGuiWindowFlags_DockNodeHost
#endif
	);

	// Focused Flags
	lua.new_enum("ImGuiFocusedFlags",
		"None"                         , ImGuiFocusedFlags_None,
		"ChildWindows"                 , ImGuiFocusedFlags_ChildWindows,
		"RootWindow"                   , ImGuiFocusedFlags_RootWindow,
		"AnyWindow"                    , ImGuiFocusedFlags_AnyWindow,
		"RootAndChildWindows"          , ImGuiFocusedFlags_RootAndChildWindows
	);

	// DragDrop Flags
	lua.new_enum("ImGuiDragDropFlags",
		"None"                         , ImGuiDragDropFlags_None,
		"SourceNoPreviewTooltip"       , ImGuiDragDropFlags_SourceNoPreviewTooltip,
		"SourceNoDisableHover"         , ImGuiDragDropFlags_SourceNoDisableHover,
		"SourceNoHoldToOpenOthers"     , ImGuiDragDropFlags_SourceNoHoldToOpenOthers,
		"SourceAllowNullID"            , ImGuiDragDropFlags_SourceAllowNullID,
		"SourceExtern"                 , ImGuiDragDropFlags_SourceExtern,
		"SourceAutoExpirePayload"      , ImGuiDragDropFlags_SourceAutoExpirePayload,
		"AcceptBeforeDelivery"         , ImGuiDragDropFlags_AcceptBeforeDelivery,
		"AcceptNoDrawDefaultRect"      , ImGuiDragDropFlags_AcceptNoDrawDefaultRect,
		"AcceptNoPreviewTooltip"       , ImGuiDragDropFlags_AcceptNoPreviewTooltip,
		"AcceptPeekOnly"               , ImGuiDragDropFlags_AcceptPeekOnly
	);

	// Hovered Flags
	lua.new_enum("ImGuiHoveredFlags",
		"None"                         , ImGuiHoveredFlags_None,
		"ChildWindows"                 , ImGuiHoveredFlags_ChildWindows,
		"RootWindow"                   , ImGuiHoveredFlags_RootWindow,
		"AnyWindow"                    , ImGuiHoveredFlags_AnyWindow,
		"AllowWhenBlockedByPopup"      , ImGuiHoveredFlags_AllowWhenBlockedByPopup,
		"AllowWhenBlockedByActiveItem" , ImGuiHoveredFlags_AllowWhenBlockedByActiveItem,
		"AllowWhenOverlapped"          , ImGuiHoveredFlags_AllowWhenOverlapped,
		"AllowWhenDisabled"            , ImGuiHoveredFlags_AllowWhenDisabled,
		"RectOnly"                     , ImGuiHoveredFlags_RectOnly,
		"RootAndChildWindows"          , ImGuiHoveredFlags_RootAndChildWindows
	);

	// Cond
	lua.new_enum("ImGuiCond",
		"None"                         , ImGuiCond_None,
		"Always"                       , ImGuiCond_Always,
		"Once"                         , ImGuiCond_Once,
		"FirstUseEver"                 , ImGuiCond_FirstUseEver,
		"Appearing"                    , ImGuiCond_Appearing
	);

	// Col
	lua.new_enum("ImGuiCol",
		"Text"                         , ImGuiCol_Text,
		"TextDisabled"                 , ImGuiCol_TextDisabled,
		"WindowBg"                     , ImGuiCol_WindowBg,
		"ChildBg"                      , ImGuiCol_ChildBg,
		"PopupBg"                      , ImGuiCol_PopupBg,
		"Border"                       , ImGuiCol_Border,
		"BorderShadow"                 , ImGuiCol_BorderShadow,
		"FrameBg"                      , ImGuiCol_FrameBg,
		"FrameBgHovered"               , ImGuiCol_FrameBgHovered,
		"FrameBgActive"                , ImGuiCol_FrameBgActive,
		"TitleBg"                      , ImGuiCol_TitleBg,
		"TitleBgActive"                , ImGuiCol_TitleBgActive,
		"TitleBgCollapsed"             , ImGuiCol_TitleBgCollapsed,
		"MenuBarBg"                    , ImGuiCol_MenuBarBg,
		"ScrollbarBg"                  , ImGuiCol_ScrollbarBg,
		"ScrollbarGrab"                , ImGuiCol_ScrollbarGrab,
		"ScrollbarGrabHovered"         , ImGuiCol_ScrollbarGrabHovered,
		"ScrollbarGrabActive"          , ImGuiCol_ScrollbarGrabActive,
		"CheckMark"                    , ImGuiCol_CheckMark,
		"SliderGrab"                   , ImGuiCol_SliderGrab,
		"SliderGrabActive"             , ImGuiCol_SliderGrabActive,
		"Button"                       , ImGuiCol_Button,
		"ButtonHovered"                , ImGuiCol_ButtonHovered,
		"ButtonActive"                 , ImGuiCol_ButtonActive,
		"Header"                       , ImGuiCol_Header,
		"HeaderHovered"                , ImGuiCol_HeaderHovered,
		"HeaderActive"                 , ImGuiCol_HeaderActive,
		"Separator"                    , ImGuiCol_Separator,
		"SeparatorHovered"             , ImGuiCol_SeparatorHovered,
		"SeparatorActive"              , ImGuiCol_SeparatorActive,
		"ResizeGrip"                   , ImGuiCol_ResizeGrip,
		"ResizeGripHovered"            , ImGuiCol_ResizeGripHovered,
		"ResizeGripActive"             , ImGuiCol_ResizeGripActive,
		"Tab"                          , ImGuiCol_Tab,
		"TabHovered"                   , ImGuiCol_TabHovered,
		"TabActive"                    , ImGuiCol_TabActive,
		"TabUnfocused"                 , ImGuiCol_TabUnfocused,
		"TabUnfocusedActive"           , ImGuiCol_TabUnfocusedActive,
		"DockingPreview"               , ImGuiCol_DockingPreview,
		"DockingEmptyBg"               , ImGuiCol_DockingEmptyBg,
		"PlotLines"                    , ImGuiCol_PlotLines,
		"PlotLinesHovered"             , ImGuiCol_PlotLinesHovered,
		"PlotHistogram"                , ImGuiCol_PlotHistogram,
		"PlotHistogramHovered"         , ImGuiCol_PlotHistogramHovered,
		"TextSelectedBg"               , ImGuiCol_TextSelectedBg,
		"DragDropTarget"               , ImGuiCol_DragDropTarget,
		"NavHighlight"                 , ImGuiCol_NavHighlight,
		"NavWindowingHighlight"        , ImGuiCol_NavWindowingHighlight,
		"NavWindowingDimBg"            , ImGuiCol_NavWindowingDimBg,
		"ModalWindowDimBg"             , ImGuiCol_ModalWindowDimBg,
		"ModalWindowDarkening"         , ImGuiCol_ModalWindowDimBg,
		"COUNT"                        , ImGuiCol_COUNT
	);

	// Style
	lua.new_enum("ImGuiStyleVar",
		"Alpha"                        , ImGuiStyleVar_Alpha,
		"WindowPadding"                , ImGuiStyleVar_WindowPadding,
		"WindowRounding"               , ImGuiStyleVar_WindowRounding,
		"WindowBorderSize"             , ImGuiStyleVar_WindowBorderSize,
		"WindowMinSize"                , ImGuiStyleVar_WindowMinSize,
		"WindowTitleAlign"             , ImGuiStyleVar_WindowTitleAlign,
		"ChildRounding"                , ImGuiStyleVar_ChildRounding,
		"ChildBorderSize"              , ImGuiStyleVar_ChildBorderSize,
		"PopupRounding"                , ImGuiStyleVar_PopupRounding,
		"PopupBorderSize"              , ImGuiStyleVar_PopupBorderSize,
		"FramePadding"                 , ImGuiStyleVar_FramePadding,
		"FrameRounding"                , ImGuiStyleVar_FrameRounding,
		"FrameBorderSize"              , ImGuiStyleVar_FrameBorderSize,
		"ItemSpacing"                  , ImGuiStyleVar_ItemSpacing,
		"ItemInnerSpacing"             , ImGuiStyleVar_ItemInnerSpacing,
		"IndentSpacing"                , ImGuiStyleVar_IndentSpacing,
		"CellPadding"                  , ImGuiStyleVar_CellPadding,
		"ScrollbarSize"                , ImGuiStyleVar_ScrollbarSize,
		"ScrollbarRounding"            , ImGuiStyleVar_ScrollbarRounding,
		"GrabMinSize"                  , ImGuiStyleVar_GrabMinSize,
		"GrabRounding"                 , ImGuiStyleVar_GrabRounding,
		"TabRounding"                  , ImGuiStyleVar_TabRounding,
		//"SelectableRounding"         , ImGuiStyleVar_SelectableRounding,
		"SelectableTextAlign"          , ImGuiStyleVar_SelectableTextAlign,
		"ButtonTextAlign"              , ImGuiStyleVar_ButtonTextAlign,
		"COUNT"                        , ImGuiStyleVar_COUNT
	);

	// Dir
	lua.new_enum("ImGuiDir",
		"None"                         , ImGuiDir_None,
		"Left"                         , ImGuiDir_Left,
		"Right"                        , ImGuiDir_Right,
		"Up"                           , ImGuiDir_Up,
		"Down"                         , ImGuiDir_Down,
		"COUNT"                        , ImGuiDir_COUNT
	);

	// Sort Direction
	lua.new_enum("ImGuiSortDirection",
		"None"                         , ImGuiSortDirection_None,
		"Ascending"                    , ImGuiSortDirection_Ascending,
		"Descending"                   , ImGuiSortDirection_Descending
	);

	// Combo Flags
	lua.new_enum("ImGuiComboFlags",
		"None"                         , ImGuiComboFlags_None,
		"PopupAlignLeft"               , ImGuiComboFlags_PopupAlignLeft,
		"HeightSmall"                  , ImGuiComboFlags_HeightSmall,
		"HeightRegular"                , ImGuiComboFlags_HeightRegular,
		"HeightLarge"                  , ImGuiComboFlags_HeightLarge,
		"HeightLargest"                , ImGuiComboFlags_HeightLargest,
		"NoArrowButton"                , ImGuiComboFlags_NoArrowButton,
		"NoPreview"                    , ImGuiComboFlags_NoPreview,
		"HeightMask"                   , ImGuiComboFlags_HeightMask_
	);

	// InputText Flags
	lua.new_enum("ImGuiInputTextFlags",
		"None"                         , ImGuiInputTextFlags_None,
		"CharsDecimal"                 , ImGuiInputTextFlags_CharsDecimal,
		"CharsHexadecimal"             , ImGuiInputTextFlags_CharsHexadecimal,
		"CharsUppercase"               , ImGuiInputTextFlags_CharsUppercase,
		"CharsNoBlank"                 , ImGuiInputTextFlags_CharsNoBlank,
		"AutoSelectAll"                , ImGuiInputTextFlags_AutoSelectAll,
		"EnterReturnsTrue"             , ImGuiInputTextFlags_EnterReturnsTrue,
		"CallbackCompletion"           , ImGuiInputTextFlags_CallbackCompletion,
		"CallbackHistory"              , ImGuiInputTextFlags_CallbackHistory,
		"CallbackAlways"               , ImGuiInputTextFlags_CallbackAlways,
		"CallbackCharFilter"           , ImGuiInputTextFlags_CallbackCharFilter,
		"AllowTabInput"                , ImGuiInputTextFlags_AllowTabInput,
		"CtrlEnterForNewLine"          , ImGuiInputTextFlags_CtrlEnterForNewLine,
		"NoHorizontalScroll"           , ImGuiInputTextFlags_NoHorizontalScroll,
		"AlwaysInsertMode"             , ImGuiInputTextFlags_AlwaysInsertMode,
		"ReadOnly"                     , ImGuiInputTextFlags_ReadOnly,
		"Password"                     , ImGuiInputTextFlags_Password,
		"NoUndoRedo"                   , ImGuiInputTextFlags_NoUndoRedo,
		"CharsScientific"              , ImGuiInputTextFlags_CharsScientific,
		"CallbackResize"               , ImGuiInputTextFlags_CallbackResize,
		"Multiline"                    , ImGuiInputTextFlags_Multiline,
		"NoMarkEdited"                 , ImGuiInputTextFlags_NoMarkEdited
	);

	// ColorEdit Flags
	lua.new_enum("ImGuiColorEditFlags",
		"None"                        , ImGuiColorEditFlags_None,
		"NoAlpha"                     , ImGuiColorEditFlags_NoAlpha,
		"NoPicker"                    , ImGuiColorEditFlags_NoPicker,
		"NoOptions"                   , ImGuiColorEditFlags_NoOptions,
		"NoSmallPreview"              , ImGuiColorEditFlags_NoSmallPreview,
		"NoInputs"                    , ImGuiColorEditFlags_NoInputs,
		"NoTooltip"                   , ImGuiColorEditFlags_NoTooltip,
		"NoLabel"                     , ImGuiColorEditFlags_NoLabel,
		"NoSidePreview"               , ImGuiColorEditFlags_NoSidePreview,
		"NoDragDrop"                  , ImGuiColorEditFlags_NoDragDrop,
		"NoBorder"                    , ImGuiColorEditFlags_NoBorder,

		"AlphaBar"                    , ImGuiColorEditFlags_AlphaBar,
		"AlphaPreview"                , ImGuiColorEditFlags_AlphaPreview,
		"AlphaPreviewHalf"            , ImGuiColorEditFlags_AlphaPreviewHalf,
		"HDR"                         , ImGuiColorEditFlags_HDR,
		"DisplayRGB"                  , ImGuiColorEditFlags_DisplayRGB,
		"DisplayHSV"                  , ImGuiColorEditFlags_DisplayHSV,
		"DisplayHex"                  , ImGuiColorEditFlags_DisplayHex,
		"Uint8"                       , ImGuiColorEditFlags_Uint8,
		"Float"                       , ImGuiColorEditFlags_Float,
		"PickerHueBar"                , ImGuiColorEditFlags_PickerHueBar,
		"PickerHueWheel"              , ImGuiColorEditFlags_PickerHueWheel,
		"InputRGB"                    , ImGuiColorEditFlags_InputRGB,
		"InputHSV"                    , ImGuiColorEditFlags_InputHSV,

		"DefaultOptions_"             , ImGuiColorEditFlags_DefaultOptions_,
		"DisplayMask_"                , ImGuiColorEditFlags_DisplayMask_,
		"DataTypeMask_"               , ImGuiColorEditFlags_DataTypeMask_,
		"PickerMask_"                 , ImGuiColorEditFlags_PickerMask_,
		"InputMask_"                  , ImGuiColorEditFlags_InputMask_,

		// Deprecated
		"_OptionsDefault"             , ImGuiColorEditFlags_DefaultOptions_,
		"_DisplayMask"                , ImGuiColorEditFlags_DisplayMask_,
		"_DataTypeMask"               , ImGuiColorEditFlags_DataTypeMask_,
		"_PickerMask"                 , ImGuiColorEditFlags_PickerMask_,
		"_InputMask"                  , ImGuiColorEditFlags_InputMask_,

		"RGB"                         , ImGuiColorEditFlags_RGB
	);

	// TreeNode Flags
	lua.new_enum("ImGuiTreeNodeFlags",
		"None"                         , ImGuiTreeNodeFlags_None,
		"Selected"                     , ImGuiTreeNodeFlags_Selected,
		"Framed"                       , ImGuiTreeNodeFlags_Framed,
		"AllowItemOverlap"             , ImGuiTreeNodeFlags_AllowItemOverlap,
		"NoTreePushOnOpen"             , ImGuiTreeNodeFlags_NoTreePushOnOpen,
		"NoAutoOpenOnLog"              , ImGuiTreeNodeFlags_NoAutoOpenOnLog,
		"DefaultOpen"                  , ImGuiTreeNodeFlags_DefaultOpen,
		"OpenOnDoubleClick"            , ImGuiTreeNodeFlags_OpenOnDoubleClick,
		"OpenOnArrow"                  , ImGuiTreeNodeFlags_OpenOnArrow,
		"Leaf"                         , ImGuiTreeNodeFlags_Leaf,
		"Bullet"                       , ImGuiTreeNodeFlags_Bullet,
		"FramePadding"                 , ImGuiTreeNodeFlags_FramePadding,
		"SpanAvailWidth"               , ImGuiTreeNodeFlags_SpanAvailWidth,
		"SpanFullWidth"                , ImGuiTreeNodeFlags_SpanFullWidth,
		"NavLeftJumpsBackHere"         , ImGuiTreeNodeFlags_NavLeftJumpsBackHere,
		"CollapsingHeader"             , ImGuiTreeNodeFlags_CollapsingHeader
	);

	// Selectable Flags
	lua.new_enum("ImGuiSelectableFlags",
		"None"                         , ImGuiSelectableFlags_None,
		"DontClosePopups"              , ImGuiSelectableFlags_DontClosePopups,
		"SpanAllColumns"               , ImGuiSelectableFlags_SpanAllColumns,
		"AllowDoubleClick"             , ImGuiSelectableFlags_AllowDoubleClick,
		"Disabled"                     , ImGuiSelectableFlags_Disabled,
		"AllowItemOverlap"             , ImGuiSelectableFlags_AllowItemOverlap
	);

	// Popup Flags
	lua.new_enum("ImGuiPopupFlags",
		"None"                         , ImGuiPopupFlags_None,
		"MouseButtonLeft"              , ImGuiPopupFlags_MouseButtonLeft,
		"MouseButtonRight"             , ImGuiPopupFlags_MouseButtonRight,
		"MouseButtonMiddle"            , ImGuiPopupFlags_MouseButtonMiddle,
		"MouseButtonMask_"             , ImGuiPopupFlags_MouseButtonMask_,
		"MouseButtonDefault_"          , ImGuiPopupFlags_MouseButtonDefault_,
		"NoOpenOverExistingPopup"      , ImGuiPopupFlags_NoOpenOverExistingPopup,
		"NoOpenOverItems"              , ImGuiPopupFlags_NoOpenOverItems,
		"AnyPopupId"                   , ImGuiPopupFlags_AnyPopupId,
		"AnyPopupLevel"                , ImGuiPopupFlags_AnyPopupLevel,
		"AnyPopup"                     , ImGuiPopupFlags_AnyPopup
	);

	// TabBar Flags
	lua.new_enum("ImGuiTabBarFlags",
		"None"                         , ImGuiTabBarFlags_None,
		"Reorderable"                  , ImGuiTabBarFlags_Reorderable,
		"AutoSelectNewTabs"            , ImGuiTabBarFlags_AutoSelectNewTabs,
		"TabListPopupButton"           , ImGuiTabBarFlags_TabListPopupButton,
		"NoCloseWithMiddleMouseButton" , ImGuiTabBarFlags_NoCloseWithMiddleMouseButton,
		"NoTabListScrollingButtons"    , ImGuiTabBarFlags_NoTabListScrollingButtons,
		"NoTooltip"                    , ImGuiTabBarFlags_NoTooltip,
		"FittingPolicyResizeDown"      , ImGuiTabBarFlags_FittingPolicyResizeDown,
		"FittingPolicyScroll"          , ImGuiTabBarFlags_FittingPolicyScroll,
		"FittingPolicyMask_"           , ImGuiTabBarFlags_FittingPolicyMask_,
		"FittingPolicyDefault_"        , ImGuiTabBarFlags_FittingPolicyDefault_
	);

	// TabItem Flags
	lua.new_enum("ImGuiTabItemFlags",
		"None"                         , ImGuiTabItemFlags_None,
		"UnsavedDocument"              , ImGuiTabItemFlags_UnsavedDocument,
		"SetSelected"                  , ImGuiTabItemFlags_SetSelected,
		"NoCloseWithMiddleMouseButton" , ImGuiTabItemFlags_NoCloseWithMiddleMouseButton,
		"NoPushId"                     , ImGuiTabItemFlags_NoPushId,
		"NoTooltip"                    , ImGuiTabItemFlags_NoTooltip
	);

	// Table Flags
	lua.new_enum("ImGuiTableFlags",
		// Features
		"None"                         , ImGuiTableFlags_None,
		"Resizable"                    , ImGuiTableFlags_Resizable,
		"Reorderable"                  , ImGuiTableFlags_Reorderable,
		"Hideable"                     , ImGuiTableFlags_Hideable,
		"Sortable"                     , ImGuiTableFlags_Sortable,
		"NoSavedSettings"              , ImGuiTableFlags_NoSavedSettings,
		"ContextMenuInBody"            , ImGuiTableFlags_ContextMenuInBody,
		// Decorations
		"RowBg"                        , ImGuiTableFlags_RowBg,
		"BordersInnerH"                , ImGuiTableFlags_BordersInnerH,
		"BordersOuterH"                , ImGuiTableFlags_BordersOuterH,
		"BordersInnerV"                , ImGuiTableFlags_BordersInnerV,
		"BordersOuterV"                , ImGuiTableFlags_BordersOuterV,
		"BordersH"                     , ImGuiTableFlags_BordersH,
		"BordersV"                     , ImGuiTableFlags_BordersV,
		"BordersInner"                 , ImGuiTableFlags_BordersInner,
		"BordersOuter"                 , ImGuiTableFlags_BordersOuter,
		"Borders"                      , ImGuiTableFlags_Borders,
		"NoBordersInBody"              , ImGuiTableFlags_NoBordersInBody,
		"NoBordersInBodyUntilResize"   , ImGuiTableFlags_NoBordersInBodyUntilResize,
		// Sizing Policy
		"SizingFixedFit"               , ImGuiTableFlags_SizingFixedFit,
		"SizingFixedSame"              , ImGuiTableFlags_SizingFixedSame,
		"SizingStretchProp"            , ImGuiTableFlags_SizingStretchProp,
		"SizingStretchSame"            , ImGuiTableFlags_SizingStretchSame,
		// Sizing Extra Options
		"NoHostExtendX"                , ImGuiTableFlags_NoHostExtendX,
		"NoHostExtendY"                , ImGuiTableFlags_NoHostExtendY,
		"NoKeepColumnsVisible"         , ImGuiTableFlags_NoKeepColumnsVisible,
		"PreciseWidths"                , ImGuiTableFlags_PreciseWidths,
		// Clipping
		"NoClip"                       , ImGuiTableFlags_NoClip,
		// Padding
		"PadOuterX"                    , ImGuiTableFlags_PadOuterX,
		"NoPadOuterX"                  , ImGuiTableFlags_NoPadOuterX,
		"NoPadInnerX"                  , ImGuiTableFlags_NoPadInnerX,
		// Scrolling
		"ScrollX"                      , ImGuiTableFlags_ScrollX,
		"ScrollY"                      , ImGuiTableFlags_ScrollY,
		// Sorting
		"SortMulti"                    , ImGuiTableFlags_SortMulti,
		"SortTristate"                 , ImGuiTableFlags_SortTristate,

		// Deprecated
		"MultiSortable"                , ImGuiTableFlags_SortMulti,
		"SizingPolicyFixedX"           , ImGuiTableFlags_SizingFixedFit,
		"SizingPolicyStretchX"         , ImGuiTableFlags_SizingStretchProp,
		"Scroll"                       , (ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY),
		"NoHeadersWidth"               , 0 // removed
	);

	// TableColumn Flags
	lua.new_enum("ImGuiTableColumnFlags",
		"None"                         , ImGuiTableColumnFlags_None,
		"DefaultHide"                  , ImGuiTableColumnFlags_DefaultHide,
		"DefaultSort"                  , ImGuiTableColumnFlags_DefaultSort,
		"WidthFixed"                   , ImGuiTableColumnFlags_WidthFixed,
		"WidthStretch"                 , ImGuiTableColumnFlags_WidthStretch,
		"WidthAuto"                    , (ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize),
		"NoResize"                     , ImGuiTableColumnFlags_NoResize,
		"NoClip"                       , ImGuiTableColumnFlags_NoClip,
		"NoSort"                       , ImGuiTableColumnFlags_NoSort,
		"NoSortAscending"              , ImGuiTableColumnFlags_NoSortAscending,
		"NoSortDescending"             , ImGuiTableColumnFlags_NoSortDescending,
		"NoHide"                       , ImGuiTableColumnFlags_NoHide,
		"NoHeaderWidth"                , ImGuiTableColumnFlags_NoHeaderWidth,
		"PreferSortAscending"          , ImGuiTableColumnFlags_PreferSortAscending,
		"PreferSortDescending"         , ImGuiTableColumnFlags_PreferSortDescending,
		"IndentEnable"                 , ImGuiTableColumnFlags_IndentEnable,
		"IndentDisable"                , ImGuiTableColumnFlags_IndentDisable,
		"NoReorder"                    , ImGuiTableColumnFlags_NoReorder,

		// Deprecated
		"WidthAlwaysAutoResize"        , ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize,
		"NoClipX"                      , ImGuiTableColumnFlags_NoClip
	);

	// TableRow Flags
	lua.new_enum("ImGuiTableRowFlags",
		"None"                         , ImGuiTableRowFlags_None,
		"Headers"                      , ImGuiTableRowFlags_Headers
	);

	// Table Bg Target Flags
	lua.new_enum("ImGuiTableBgTarget",
		"None"                         , ImGuiTableBgTarget_None,
		"RowBg0"                       , ImGuiTableBgTarget_RowBg0,
		"RowBg1"                       , ImGuiTableBgTarget_RowBg1,
		"RowBg0"                       , ImGuiTableBgTarget_RowBg0,
		"CellBg"                       , ImGuiTableBgTarget_CellBg,

		// Deprecated
		"ColumnBg0"                    , 0,
		"ColumnBg1"                    , 0
	);

	// DockNode Flags
	lua.new_enum("ImGuiDockNodeFlags",
		"None"                         , ImGuiDockNodeFlags_None,
		"KeepAliveOnly"                , ImGuiDockNodeFlags_KeepAliveOnly,
		"NoDockingInCentralNode"       , ImGuiDockNodeFlags_NoDockingInCentralNode,
		"PassthruCentralNode"          , ImGuiDockNodeFlags_PassthruCentralNode,
		"NoSplit"                      , ImGuiDockNodeFlags_NoSplit,
		"NoResize"                     , ImGuiDockNodeFlags_NoResize,
		"AutoHideTabBar"               , ImGuiDockNodeFlags_AutoHideTabBar
	);

	// Slider Flags
	lua.new_enum("ImGuiSliderFlags",
		"None"                         , ImGuiSliderFlags_None,
		"AlwaysClamp"                  , ImGuiSliderFlags_AlwaysClamp,
		"Logarithmic"                  , ImGuiSliderFlags_Logarithmic,
		"NoRoundToFormat"              , ImGuiSliderFlags_NoRoundToFormat,
		"NoInput"                      , ImGuiSliderFlags_NoInput
	);

	// MouseButton
	lua.new_enum("ImGuiMouseButton",
		"Left"                         , ImGuiMouseButton_Left,
		"Right"                        , ImGuiMouseButton_Right,
		"Middle"                       , ImGuiMouseButton_Middle,
		"COUNT"                        , ImGuiMouseButton_COUNT,

		// BAD:
		"ImGuiMouseButton_Left"        , ImGuiMouseButton_Left,
		"ImGuiMouseButton_Right"       , ImGuiMouseButton_Right,
		"ImGuiMouseButton_Middle"      , ImGuiMouseButton_Middle,
		"ImGuiMouseButton_COUNT"       , ImGuiMouseButton_COUNT
	);

	// Key
	lua.new_enum("ImGuiKey",
		"Tab"                          , ImGuiKey_Tab,
		"LeftArrow"                    , ImGuiKey_LeftArrow,
		"RightArrow"                   , ImGuiKey_RightArrow,
		"UpArrow"                      , ImGuiKey_UpArrow,
		"DownArrow"                    , ImGuiKey_DownArrow,
		"PageUp"                       , ImGuiKey_PageUp,
		"PageDown"                     , ImGuiKey_PageDown,
		"Home"                         , ImGuiKey_Home,
		"End"                          , ImGuiKey_End,
		"Insert"                       , ImGuiKey_Insert,
		"Delete"                       , ImGuiKey_Delete,
		"Backspace"                    , ImGuiKey_Backspace,
		"Space"                        , ImGuiKey_Space,
		"Enter"                        , ImGuiKey_Enter,
		"Escape"                       , ImGuiKey_Escape,
		"KeyPadEnter"                  , ImGuiKey_KeyPadEnter,
		"A"                            , ImGuiKey_A,
		"C"                            , ImGuiKey_C,
		"V"                            , ImGuiKey_V,
		"X"                            , ImGuiKey_X,
		"Y"                            , ImGuiKey_Y,
		"Z"                            , ImGuiKey_Z,
		"COUNT"                        , ImGuiKey_COUNT
	);

	// MouseCursor
	lua.new_enum("ImGuiMouseCursor",
		"None"                         , ImGuiMouseCursor_None,
		"Arrow"                        , ImGuiMouseCursor_Arrow,
		"TextInput"                    , ImGuiMouseCursor_TextInput,
		"ResizeAll"                    , ImGuiMouseCursor_ResizeAll,
		"ResizeNS"                     , ImGuiMouseCursor_ResizeNS,
		"ResizeEW"                     , ImGuiMouseCursor_ResizeEW,
		"ResizeNESW"                   , ImGuiMouseCursor_ResizeNESW,
		"ResizeNWSE"                   , ImGuiMouseCursor_ResizeNWSE,
		"Hand"                         , ImGuiMouseCursor_Hand,
		"NotAllowed"                   , ImGuiMouseCursor_NotAllowed,
		"COUNT"                        , ImGuiMouseCursor_COUNT
	);

	// ImDrawFlags
	lua.new_enum("ImDrawFlags",
		"None"                         , ImDrawFlags_None,
		"Closed"                       , ImDrawFlags_Closed,
		"RoundCornersTopLeft"          , ImDrawFlags_RoundCornersTopLeft,
		"RoundCornersTopRight"         , ImDrawFlags_RoundCornersTopRight,
		"RoundCornersBottomLeft"       , ImDrawFlags_RoundCornersBottomLeft,
		"RoundCornersBottomRight"      , ImDrawFlags_RoundCornersBottomRight,
		"RoundCornersNone"             , ImDrawFlags_RoundCornersNone,
		"RoundCornersTop"              , ImDrawFlags_RoundCornersTop,
		"RoundCornersBottom"           , ImDrawFlags_RoundCornersBottom,
		"RoundCornersLeft"             , ImDrawFlags_RoundCornersLeft,
		"RoundCornersRight"            , ImDrawFlags_RoundCornersRight,
		"RoundCornersAll"              , ImDrawFlags_RoundCornersAll
	);

	// ImDrawListFlags
	lua.new_enum("ImDrawListFlags",
		"None"                         , ImDrawListFlags_None,
		"AntiAliasedLines"             , ImDrawListFlags_AntiAliasedLines,
		"AntiAliasedLinesUseTex"       , ImDrawListFlags_AntiAliasedLinesUseTex,
		"AntiAliasedFill"              , ImDrawListFlags_AntiAliasedFill,
		"AllowVtxOffset"               , ImDrawListFlags_AllowVtxOffset
	);

	// ImGuiButtonFlags
	lua.new_enum("ImGuiButtonFlags",
		"None"                         , ImGuiButtonFlags_None,
		"MouseButtonLeft"              , ImGuiButtonFlags_MouseButtonLeft,
		"MouseButtonRight"             , ImGuiButtonFlags_MouseButtonRight,
		"MouseButtonMiddle"            , ImGuiButtonFlags_MouseButtonMiddle
	);

	// ImGuiConfigFlags
	lua.new_enum("ImGuiConfigFlags",
		"None"                         , ImGuiConfigFlags_None,
		"NavEnableKeyboard"            , ImGuiConfigFlags_NavEnableKeyboard,
		"NavEnableGamepad"             , ImGuiConfigFlags_NavEnableGamepad,
		"NavEnableSetMousePos"         , ImGuiConfigFlags_NavEnableSetMousePos,
		"NavNoCaptureKeyboard"         , ImGuiConfigFlags_NavNoCaptureKeyboard,
		"NoMouse"                      , ImGuiConfigFlags_NoMouse,
		"NoMouseCursorChange"          , ImGuiConfigFlags_NoMouseCursorChange,
		"DockingEnable"                , ImGuiConfigFlags_DockingEnable,
		"ViewportsEnable"              , ImGuiConfigFlags_ViewportsEnable,
		"DpiEnableScaleViewports"      , ImGuiConfigFlags_DpiEnableScaleViewports,
		"DpiEnableScaleFonts"          , ImGuiConfigFlags_DpiEnableScaleFonts,
		"IsSRGB"                       , ImGuiConfigFlags_IsSRGB,
		"IsTouchScreen"                , ImGuiConfigFlags_IsTouchScreen
	);
}

} // namespace mq::lua::bindings
