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
		"DockNodeHost"                 , ImGuiWindowFlags_DockNodeHost,

		"AlwaysUseWindowPadding"       , ImGuiWindowFlags_AlwaysUseWindowPadding  // Obsolete
	);

	// Child Window Flags
	lua.new_enum("ImGuiChildFlags",
		"None"                         , ImGuiChildFlags_None,
		"Border"                       , ImGuiChildFlags_Border,
		"AlwaysUseWindowPadding"       , ImGuiChildFlags_AlwaysUseWindowPadding,
		"ResizeX"                      , ImGuiChildFlags_ResizeX,
		"ResizeY"                      , ImGuiChildFlags_ResizeY,
		"AutoResizeX"                  , ImGuiChildFlags_AutoResizeX,
		"AutoResizeY"                  , ImGuiChildFlags_AutoResizeY,
		"AlwaysAutoResize"             , ImGuiChildFlags_AlwaysAutoResize,
		"FrameStyle"                   , ImGuiChildFlags_FrameStyle
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
		"AlwaysOverwrite"              , ImGuiInputTextFlags_AlwaysOverwrite,
		"ReadOnly"                     , ImGuiInputTextFlags_ReadOnly,
		"Password"                     , ImGuiInputTextFlags_Password,
		"NoUndoRedo"                   , ImGuiInputTextFlags_NoUndoRedo,
		"CharsScientific"              , ImGuiInputTextFlags_CharsScientific,
		"CallbackResize"               , ImGuiInputTextFlags_CallbackResize,
		"CallbackEdit"                 , ImGuiInputTextFlags_CallbackEdit,
		"EscapeClearsAll"              , ImGuiInputTextFlags_EscapeClearsAll,

		"AlwaysInsertMode"             , ImGuiInputTextFlags_AlwaysOverwrite // DEPRECATED
	);

	// TreeNode Flags
	lua.new_enum("ImGuiTreeNodeFlags",
		"None"                         , ImGuiTreeNodeFlags_None,
		"Selected"                     , ImGuiTreeNodeFlags_Selected,
		"Framed"                       , ImGuiTreeNodeFlags_Framed,
		"AllowOverlap"                 , ImGuiTreeNodeFlags_AllowOverlap,
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
		"SpanAllColumns"               , ImGuiTreeNodeFlags_SpanAllColumns,
		"NavLeftJumpsBackHere"         , ImGuiTreeNodeFlags_NavLeftJumpsBackHere,
		"CollapsingHeader"             , ImGuiTreeNodeFlags_CollapsingHeader,

		// Deprecated
		"AllowItemOverlap"             , ImGuiTreeNodeFlags_AllowItemOverlap
	);

	// Popup Flags
	lua.new_enum("ImGuiPopupFlags",
		"None"                         , ImGuiPopupFlags_None,
		"MouseButtonLeft"              , ImGuiPopupFlags_MouseButtonLeft,
		"MouseButtonRight"             , ImGuiPopupFlags_MouseButtonRight,
		"MouseButtonMiddle"            , ImGuiPopupFlags_MouseButtonMiddle,
		"NoOpenOverExistingPopup"      , ImGuiPopupFlags_NoOpenOverExistingPopup,
		"NoOpenOverItems"              , ImGuiPopupFlags_NoOpenOverItems,
		"AnyPopupId"                   , ImGuiPopupFlags_AnyPopupId,
		"AnyPopupLevel"                , ImGuiPopupFlags_AnyPopupLevel,
		"AnyPopup"                     , ImGuiPopupFlags_AnyPopup,

		"MouseButtonMask_"             , ImGuiPopupFlags_MouseButtonMask_,
		"MouseButtonDefault_"          , ImGuiPopupFlags_MouseButtonDefault_
	);

	// TreeNode Flags
	lua.new_enum("ImGuiTreeNodeFlags",
		"None"                         , ImGuiTreeNodeFlags_None,
		"Selected"                     , ImGuiTreeNodeFlags_Selected,
		"Framed"                       , ImGuiTreeNodeFlags_Framed,
		"AllowOverlap"                 , ImGuiTreeNodeFlags_AllowOverlap,
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
		"SpanAllColumns"               , ImGuiTreeNodeFlags_SpanAllColumns,
		"NavLeftJumpsBackHere"         , ImGuiTreeNodeFlags_NavLeftJumpsBackHere,
		"CollapsingHeader"             , ImGuiTreeNodeFlags_CollapsingHeader,

		// Deprecated
		"AllowItemOverlap"             , ImGuiTreeNodeFlags_AllowItemOverlap
	);

	// Popup Flags
	lua.new_enum("ImGuiPopupFlags",
		"None"                         , ImGuiPopupFlags_None,
		"MouseButtonLeft"              , ImGuiPopupFlags_MouseButtonLeft,
		"MouseButtonRight"             , ImGuiPopupFlags_MouseButtonRight,
		"MouseButtonMiddle"            , ImGuiPopupFlags_MouseButtonMiddle,
		"NoOpenOverExistingPopup"      , ImGuiPopupFlags_NoOpenOverExistingPopup,
		"NoOpenOverItems"              , ImGuiPopupFlags_NoOpenOverItems,
		"AnyPopupId"                   , ImGuiPopupFlags_AnyPopupId,
		"AnyPopupLevel"                , ImGuiPopupFlags_AnyPopupLevel,
		"AnyPopup"                     , ImGuiPopupFlags_AnyPopup,

		"MouseButtonMask_"             , ImGuiPopupFlags_MouseButtonMask_,
		"MouseButtonDefault_"          , ImGuiPopupFlags_MouseButtonDefault_
	);

	// Selectable Flags
	lua.new_enum("ImGuiSelectableFlags",
		"None"                         , ImGuiSelectableFlags_None,
		"DontClosePopups"              , ImGuiSelectableFlags_DontClosePopups,
		"SpanAllColumns"               , ImGuiSelectableFlags_SpanAllColumns,
		"AllowDoubleClick"             , ImGuiSelectableFlags_AllowDoubleClick,
		"Disabled"                     , ImGuiSelectableFlags_Disabled,
		"AllowOverlap"                 , ImGuiSelectableFlags_AllowOverlap,

		"AllowItemOverlap"             , ImGuiSelectableFlags_AllowOverlap
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
		"WidthFitPreview"              , ImGuiComboFlags_WidthFitPreview,
		"HeightMask_"                  , ImGuiComboFlags_HeightMask_
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
		"NoTooltip"                    , ImGuiTabItemFlags_NoTooltip,
		"NoReorder"                    , ImGuiTabItemFlags_NoReorder,
		"Leading"                      , ImGuiTabItemFlags_Leading,
		"Trailing"                     , ImGuiTabItemFlags_Trailing
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
		// Miscellaneous
		"HighlightHoveredColumn"       , ImGuiTableFlags_HighlightHoveredColumn,

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
		"Disabled"                     , ImGuiTableColumnFlags_Disabled,
		"DefaultHide"                  , ImGuiTableColumnFlags_DefaultHide,
		"DefaultSort"                  , ImGuiTableColumnFlags_DefaultSort,
		"WidthStretch"                 , ImGuiTableColumnFlags_WidthStretch,
		"WidthFixed"                   , ImGuiTableColumnFlags_WidthFixed,
		"NoResize"                     , ImGuiTableColumnFlags_NoResize,
		"NoReorder"                    , ImGuiTableColumnFlags_NoReorder,
		"NoHide"                       , ImGuiTableColumnFlags_NoHide,
		"NoClip"                       , ImGuiTableColumnFlags_NoClip,
		"NoSort"                       , ImGuiTableColumnFlags_NoSort,
		"NoSortAscending"              , ImGuiTableColumnFlags_NoSortAscending,
		"NoSortDescending"             , ImGuiTableColumnFlags_NoSortDescending,
		"NoHeaderLabel"                , ImGuiTableColumnFlags_NoHeaderLabel,
		"NoHeaderWidth"                , ImGuiTableColumnFlags_NoHeaderWidth,
		"PreferSortAscending"          , ImGuiTableColumnFlags_PreferSortAscending,
		"PreferSortDescending"         , ImGuiTableColumnFlags_PreferSortDescending,
		"IndentEnable"                 , ImGuiTableColumnFlags_IndentEnable,
		"IndentDisable"                , ImGuiTableColumnFlags_IndentDisable,
		"AngledHeader"                 , ImGuiTableColumnFlags_AngledHeader,

		// Output status flags, read-only via TableGetColumnFlags()
		"IsEnabled"                    , ImGuiTableColumnFlags_IsEnabled,
		"IsVisible"                    , ImGuiTableColumnFlags_IsVisible,
		"IsSorted"                     , ImGuiTableColumnFlags_IsSorted,
		"IsHovered"                    , ImGuiTableColumnFlags_IsHovered,

		// Deprecated
		"WidthAuto"                    , ImGuiTableColumnFlags_WidthFixed | ImGuiTableColumnFlags_NoResize,
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
		"CellBg"                       , ImGuiTableBgTarget_CellBg,

		// Deprecated
		"ColumnBg0"                    , 0,
		"ColumnBg1"                    , 0
	);

	// Focused Flags
	lua.new_enum("ImGuiFocusedFlags",
		"None"                         , ImGuiFocusedFlags_None,
		"ChildWindows"                 , ImGuiFocusedFlags_ChildWindows,
		"RootWindow"                   , ImGuiFocusedFlags_RootWindow,
		"AnyWindow"                    , ImGuiFocusedFlags_AnyWindow,
		"NoPopupHierarchy"             , ImGuiFocusedFlags_NoPopupHierarchy,
		"DockHierarchy"                , ImGuiFocusedFlags_DockHierarchy,
		"RootAndChildWindows"          , ImGuiFocusedFlags_RootAndChildWindows
	);

	// Hovered Flags
	lua.new_enum("ImGuiHoveredFlags",
		"None"                         , ImGuiHoveredFlags_None,
		"ChildWindows"                 , ImGuiHoveredFlags_ChildWindows,
		"RootWindow"                   , ImGuiHoveredFlags_RootWindow,
		"AnyWindow"                    , ImGuiHoveredFlags_AnyWindow,
		"NoPopupHierarchy"             , ImGuiHoveredFlags_NoPopupHierarchy,
		"DockHierarchy"                , ImGuiHoveredFlags_DockHierarchy,
		"AllowWhenBlockedByPopup"      , ImGuiHoveredFlags_AllowWhenBlockedByPopup,
		"AllowWhenBlockedByActiveItem" , ImGuiHoveredFlags_AllowWhenBlockedByActiveItem,
		"AllowWhenOverlappedByItem"    , ImGuiHoveredFlags_AllowWhenOverlappedByItem,
		"AllowWhenOverlappedByWindow"  , ImGuiHoveredFlags_AllowWhenOverlappedByWindow,
		"AllowWhenDisabled"            , ImGuiHoveredFlags_AllowWhenDisabled,
		"NoNavOverride"                , ImGuiHoveredFlags_NoNavOverride,
		"AllowWhenOverlapped"          , ImGuiHoveredFlags_AllowWhenOverlapped,
		"RectOnly"                     , ImGuiHoveredFlags_RectOnly,
		"RootAndChildWindows"          , ImGuiHoveredFlags_RootAndChildWindows,
		"ForTooltip"                   , ImGuiHoveredFlags_ForTooltip,
		"Stationary"                   , ImGuiHoveredFlags_Stationary,
		"DelayNone"                    , ImGuiHoveredFlags_DelayNone,
		"DelayShort"                   , ImGuiHoveredFlags_DelayShort,
		"DelayNormal"                  , ImGuiHoveredFlags_DelayNormal,
		"NoSharedDelay"                , ImGuiHoveredFlags_NoSharedDelay
	);

		// DockNode Flags
	lua.new_enum("ImGuiDockNodeFlags",
		"None"                         , ImGuiDockNodeFlags_None,
		"KeepAliveOnly"                , ImGuiDockNodeFlags_KeepAliveOnly,
		"NoDockingOverCentralNode"     , ImGuiDockNodeFlags_NoDockingOverCentralNode,
		"PassthruCentralNode"          , ImGuiDockNodeFlags_PassthruCentralNode,
		"NoDockingSplit"               , ImGuiDockNodeFlags_NoDockingSplit,
		"NoResize"                     , ImGuiDockNodeFlags_NoResize,
		"AutoHideTabBar"               , ImGuiDockNodeFlags_AutoHideTabBar,
		"NoUndocking"                  , ImGuiDockNodeFlags_NoUndocking,

		"NoSplit"                      , ImGuiDockNodeFlags_NoDockingSplit,
		"NoDockingInCentralNode"       , ImGuiDockNodeFlags_NoDockingOverCentralNode
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

	// A primary data type
	lua.new_enum("ImGuiDataType",
		"S8"                           ,  ImGuiDataType_S8,
		"U8"                           , ImGuiDataType_U8,
		"S16"                          , ImGuiDataType_S16,
		"U16"                          , ImGuiDataType_U16,
		"S32"                          , ImGuiDataType_S32,
		"U32"                          , ImGuiDataType_U32,
		"S64"                          , ImGuiDataType_S64,
		"U64"                          , ImGuiDataType_U64,
		"Float"                        , ImGuiDataType_Float,
		"Double"                       , ImGuiDataType_Double,
		"COUNT"                        , ImGuiDataType_COUNT
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

	lua.new_enum("ImGuiKey",
		"None"                         , ImGuiKey_None,
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
		"LeftCtrl"                     , ImGuiKey_LeftCtrl,
		"LeftShift"                    , ImGuiKey_LeftShift,
		"LeftAlt"                      , ImGuiKey_LeftAlt,
		"LeftSuper"                    , ImGuiKey_LeftSuper,
		"RightCtrl"                    , ImGuiKey_RightCtrl,
		"RightShift"                   , ImGuiKey_RightShift,
		"RightAlt"                     , ImGuiKey_RightAlt,
		"RightSuper"                   , ImGuiKey_RightSuper,
		"Menu"                         , ImGuiKey_Menu,
		"Key_0"                        , ImGuiKey_0,
		"Key_1"                        , ImGuiKey_1,
		"Key_2"                        , ImGuiKey_2,
		"Key_3"                        , ImGuiKey_3,
		"Key_4"                        , ImGuiKey_4,
		"Key_5"                        , ImGuiKey_5,
		"Key_6"                        , ImGuiKey_6,
		"Key_7"                        , ImGuiKey_7,
		"Key_8"                        , ImGuiKey_8,
		"Key_9"                        , ImGuiKey_9,
		"A"                            , ImGuiKey_A,
		"B"                            , ImGuiKey_B,
		"C"                            , ImGuiKey_C,
		"D"                            , ImGuiKey_D,
		"E"                            , ImGuiKey_E,
		"F"                            , ImGuiKey_F,
		"G"                            , ImGuiKey_G,
		"H"                            , ImGuiKey_H,
		"I"                            , ImGuiKey_I,
		"J"                            , ImGuiKey_J,
		"K"                            , ImGuiKey_K,
		"L"                            , ImGuiKey_L,
		"M"                            , ImGuiKey_M,
		"N"                            , ImGuiKey_N,
		"O"                            , ImGuiKey_O,
		"P"                            , ImGuiKey_P,
		"Q"                            , ImGuiKey_Q,
		"R"                            , ImGuiKey_R,
		"S"                            , ImGuiKey_S,
		"T"                            , ImGuiKey_T,
		"U"                            , ImGuiKey_U,
		"V"                            , ImGuiKey_V,
		"W"                            , ImGuiKey_W,
		"X"                            , ImGuiKey_X,
		"Y"                            , ImGuiKey_Y,
		"Z"                            , ImGuiKey_Z,
		"F1"                           , ImGuiKey_F1,
		"F2"                           , ImGuiKey_F2,
		"F3"                           , ImGuiKey_F3,
		"F4"                           , ImGuiKey_F4,
		"F5"                           , ImGuiKey_F5,
		"F6"                           , ImGuiKey_F6,
		"F7"                           , ImGuiKey_F7,
		"F8"                           , ImGuiKey_F8,
		"F9"                           , ImGuiKey_F9,
		"F10"                          , ImGuiKey_F10,
		"F11"                          , ImGuiKey_F11,
		"F12"                          , ImGuiKey_F12,
		"F13"                          , ImGuiKey_F13,
		"F14"                          , ImGuiKey_F14,
		"F15"                          , ImGuiKey_F15,
		"F16"                          , ImGuiKey_F16,
		"F17"                          , ImGuiKey_F17,
		"F18"                          , ImGuiKey_F18,
		"F19"                          , ImGuiKey_F19,
		"F20"                          , ImGuiKey_F20,
		"F21"                          , ImGuiKey_F21,
		"F22"                          , ImGuiKey_F22,
		"F23"                          , ImGuiKey_F23,
		"F24"                          , ImGuiKey_F24,
		"Apostrophe"                   , ImGuiKey_Apostrophe,
		"Comma"                        , ImGuiKey_Comma,
		"Minus"                        , ImGuiKey_Minus,
		"Period"                       , ImGuiKey_Period,
		"Slash"                        , ImGuiKey_Slash,
		"Semicolon"                    , ImGuiKey_Semicolon,
		"Equal"                        , ImGuiKey_Equal,
		"LeftBracket"                  , ImGuiKey_LeftBracket,
		"Backslash"                    , ImGuiKey_Backslash,
		"RightBracket"                 , ImGuiKey_RightBracket,
		"GraveAccent"                  , ImGuiKey_GraveAccent,
		"CapsLock"                     , ImGuiKey_CapsLock,
		"ScrollLock"                   , ImGuiKey_ScrollLock,
		"NumLock"                      , ImGuiKey_NumLock,
		"PrintScreen"                  , ImGuiKey_PrintScreen,
		"Pause"                        , ImGuiKey_Pause,
		"Keypad0"                      , ImGuiKey_Keypad0,
		"Keypad1"                      , ImGuiKey_Keypad1,
		"Keypad2"                      , ImGuiKey_Keypad2,
		"Keypad3"                      , ImGuiKey_Keypad3,
		"Keypad4"                      , ImGuiKey_Keypad4,
		"Keypad5"                      , ImGuiKey_Keypad5,
		"Keypad6"                      , ImGuiKey_Keypad6,
		"Keypad7"                      , ImGuiKey_Keypad7,
		"Keypad8"                      , ImGuiKey_Keypad8,
		"Keypad9"                      , ImGuiKey_Keypad9,
		"KeypadDecimal"                , ImGuiKey_KeypadDecimal,
		"KeypadDivide"                 , ImGuiKey_KeypadDivide,
		"KeypadMultiply"               , ImGuiKey_KeypadMultiply,
		"KeypadSubtract"               , ImGuiKey_KeypadSubtract,
		"KeypadAdd"                    , ImGuiKey_KeypadAdd,
		"KeypadEnter"                  , ImGuiKey_KeypadEnter,
		"KeypadEqual"                  , ImGuiKey_KeypadEqual,
		"AppBack"                      , ImGuiKey_AppBack,
		"AppForward"                   , ImGuiKey_AppForward,
		"GamepadStart"                 , ImGuiKey_GamepadStart,
		"GamepadBack"                  , ImGuiKey_GamepadBack,
		"GamepadFaceLeft"              , ImGuiKey_GamepadFaceLeft,
		"GamepadFaceRight"             , ImGuiKey_GamepadFaceRight,
		"GamepadFaceUp"                , ImGuiKey_GamepadFaceUp,
		"GamepadFaceDown"              , ImGuiKey_GamepadFaceDown,
		"GamepadDpadLeft"              , ImGuiKey_GamepadDpadLeft,
		"GamepadDpadRight"             , ImGuiKey_GamepadDpadRight,
		"GamepadDpadUp"                , ImGuiKey_GamepadDpadUp,
		"GamepadDpadDown"              , ImGuiKey_GamepadDpadDown,
		"GamepadL1"                    , ImGuiKey_GamepadL1,
		"GamepadR1"                    , ImGuiKey_GamepadR1,
		"GamepadL2"                    , ImGuiKey_GamepadL2,
		"GamepadR2"                    , ImGuiKey_GamepadR2,
		"GamepadL3"                    , ImGuiKey_GamepadL3,
		"GamepadR3"                    , ImGuiKey_GamepadR3,
		"GamepadLStickLeft"            , ImGuiKey_GamepadLStickLeft,
		"GamepadLStickRight"           , ImGuiKey_GamepadLStickRight,
		"GamepadLStickUp"              , ImGuiKey_GamepadLStickUp,
		"GamepadLStickDown"            , ImGuiKey_GamepadLStickDown,
		"GamepadRStickLeft"            , ImGuiKey_GamepadRStickLeft,
		"GamepadRStickRight"           , ImGuiKey_GamepadRStickRight,
		"GamepadRStickUp"              , ImGuiKey_GamepadRStickUp,
		"GamepadRStickDown"            , ImGuiKey_GamepadRStickDown,
		"MouseLeft"                    , ImGuiKey_MouseLeft,
		"MouseRight"                   , ImGuiKey_MouseRight,
		"MouseMiddle"                  , ImGuiKey_MouseMiddle,
		"MouseX1"                      , ImGuiKey_MouseX1,
		"MouseX2"                      , ImGuiKey_MouseX2,
		"MouseWheelX"                  , ImGuiKey_MouseWheelX,
		"MouseWheelY"                  , ImGuiKey_MouseWheelY,

		"NamedKey_BEGIN"               , ImGuiKey_NamedKey_BEGIN,
		"NamedKey_END"                 , ImGuiKey_NamedKey_END,
		"NamedKey_COUN"                , ImGuiKey_NamedKey_COUNT
	);

	// ImGuiMod - Not a real enum but we treat it like one.
	lua.new_enum("ImGuiMod",
		"None"                         , ImGuiMod_None,
		"Ctrl"                         , ImGuiMod_Ctrl,
		"Shift"                        , ImGuiMod_Shift,
		"Alt"                          , ImGuiMod_Alt,
		"Super"                        , ImGuiMod_Super,
		"Shortcut"                     , ImGuiMod_Shortcut,
		"Mask_"                        , ImGuiMod_Mask_
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
		"TableHeaderBg"                , ImGuiCol_TableHeaderBg,
		"TableBorderStrong"            , ImGuiCol_TableBorderStrong,
		"TableBorderLight"             , ImGuiCol_TableBorderLight,
		"TableRowBg"                   , ImGuiCol_TableRowBg,
		"TableRowBgAlt"                , ImGuiCol_TableRowBgAlt,
		"TextSelectedBg"               , ImGuiCol_TextSelectedBg,
		"DragDropTarget"               , ImGuiCol_DragDropTarget,
		"NavHighlight"                 , ImGuiCol_NavHighlight,
		"NavWindowingHighlight"        , ImGuiCol_NavWindowingHighlight,
		"NavWindowingDimBg"            , ImGuiCol_NavWindowingDimBg,
		"ModalWindowDimBg"             , ImGuiCol_ModalWindowDimBg,
		"ModalWindowDarkening"         , ImGuiCol_ModalWindowDimBg, // Previous deprecated/removed
		"COUNT"                        , ImGuiCol_COUNT
	);

	// Style
	lua.new_enum("ImGuiStyleVar",
		"Alpha"                        , ImGuiStyleVar_Alpha,
		"DisabledAlpha"                , ImGuiStyleVar_DisabledAlpha,
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
		"TabBarBorderSize"             , ImGuiStyleVar_TabBarBorderSize,
		"ButtonTextAlign"              , ImGuiStyleVar_ButtonTextAlign,
		"SelectableTextAlign"          , ImGuiStyleVar_SelectableTextAlign,
		"SeparatorTextBorderSize"      , ImGuiStyleVar_SeparatorTextBorderSize,
		"SeparatorTextAlign"           , ImGuiStyleVar_SeparatorTextAlign,
		"SeparatorTextPadding"         , ImGuiStyleVar_SeparatorTextPadding,
		"DockingSeparatorSize"         , ImGuiStyleVar_DockingSeparatorSize,
		"COUNT"                        , ImGuiStyleVar_COUNT
	);

	// ImGuiButtonFlags
	lua.new_enum("ImGuiButtonFlags",
		"None"                         , ImGuiButtonFlags_None,
		"MouseButtonLeft"              , ImGuiButtonFlags_MouseButtonLeft,
		"MouseButtonRight"             , ImGuiButtonFlags_MouseButtonRight,
		"MouseButtonMiddle"            , ImGuiButtonFlags_MouseButtonMiddle
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

		"RGB"                         , ImGuiColorEditFlags_DisplayRGB // DEPRECATED
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

	// Cond
	lua.new_enum("ImGuiCond",
		"None"                         , ImGuiCond_None,
		"Always"                       , ImGuiCond_Always,
		"Once"                         , ImGuiCond_Once,
		"FirstUseEver"                 , ImGuiCond_FirstUseEver,
		"Appearing"                    , ImGuiCond_Appearing
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
}

} // namespace mq::lua::bindings
