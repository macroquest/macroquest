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
#include <mq/Plugin.h>

#include <imgui/implot/implot.h>
#include <sol/sol.hpp>

#include <string>

#include "lua_MQBindings.h"

namespace mq::lua::bindings {

//============================================================================

std::string format_text(sol::this_state s, sol::variadic_args va);

static int LuaImPlotFormatter(double value, char* buff, int size, void* user_data)
{
	auto& formatter = *static_cast<sol::function*>(user_data);

	sol::function_result result = formatter(value);
	size_t outLen = 0;
	const char* outString = luaL_tolstring(result.lua_state(), result.stack_index(), &outLen);

	size = (int)std::min(size, (int)outLen);

	buff[0] = 0;
	if (outString != nullptr)
	{
		return snprintf(buff, size, "%s", outString);
	}

	return 0;
}

//void SetupAxisFormat(int axis, sol::function formatter)
//{
//	ImPlot::SetupAxisFormat(axis, LuaImPlotFormatter, &formatter);
//}

//----------------------------------------------------------------------------

static ImPlotPoint LuaImPlotGetter(int index, void* user_data)
{
	auto getter = *static_cast<sol::unsafe_function*>(user_data);

	sol::function_result result = getter(index);

	std::optional<ImPlotPoint> point = result.get<std::optional<ImPlotPoint>>();

	return point.value_or(ImPlotPoint(0, 0));
}

// Custom type used for creating links between plots. Must remain alive for as long as the links are active


//----------------------------------------------------------------------------

void PlotLine1(const char* label_id, std::vector<double> values, int count, std::optional<double> xscale, std::optional<double> xstart, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotLine<double>(label_id, values.data(), count, xscale.value_or(1), xstart.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotLine2(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotLine<double>(label_id, xs.data(), ys.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotLineG(const char* label_id, sol::unsafe_function getter, int count, std::optional<int> flags)
{
	ImPlot::PlotLineG(label_id, &LuaImPlotGetter, &getter, count, flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotScatter1(const char* label_id, std::vector<double> values, int count, std::optional<double> xscale, std::optional<double> xstart, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotScatter<double>(label_id, values.data(), count, xscale.value_or(1), xstart.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotScatter2(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotScatter<double>(label_id, xs.data(), ys.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotScatterG(const char* label_id, sol::unsafe_function getter, int count, std::optional<int> flags)
{
	ImPlot::PlotScatterG(label_id, &LuaImPlotGetter, &getter, count, flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotStairs1(const char* label_id, std::vector<double> values, int count, std::optional<double> xscale, std::optional<double> xstart, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotStairs<double>(label_id, values.data(), count, xscale.value_or(1), xstart.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotStairs2(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotStairs<double>(label_id, xs.data(), ys.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotStairsG(const char* label_id, sol::unsafe_function getter, int count, std::optional<int> flags)
{
	ImPlot::PlotStairsG(label_id, &LuaImPlotGetter, &getter, count, flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotShaded1(const char* label_id, std::vector<double> values, int count, std::optional<double> yref, std::optional<double> xscale, std::optional<double> xstart, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotShaded<double>(label_id, values.data(), count, yref.value_or(0), xscale.value_or(1), xstart.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotShaded2(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<double> yref, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotShaded<double>(label_id, xs.data(), ys.data(), count, yref.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotShaded3(const char* label_id, std::vector<double> xs, std::vector<double> ys1, std::vector<double> ys2, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotShaded<double>(label_id, xs.data(), ys1.data(), ys2.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotShadedG(const char* label_id, sol::unsafe_function getter1, sol::unsafe_function getter2, int count, std::optional<int> flags)
{
	ImPlot::PlotShadedG(label_id, &LuaImPlotGetter, &getter1, &LuaImPlotGetter, &getter2, count, flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotBars1(const char* label_id, std::vector<double> values, int count, std::optional<double> bar_size, std::optional<double> shift, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotBars<double>(label_id, values.data(), count, bar_size.value_or(0.67), shift.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotBars2(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, double bar_size, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotBars<double>(label_id, xs.data(), ys.data(), count, bar_size, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotBarsG(const char* label_id, sol::unsafe_function getter, int count, double bar_size, std::optional<int> flags)
{
	ImPlot::PlotBarsG(label_id, &LuaImPlotGetter, &getter, count, bar_size, flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotBarGroups(std::vector<const char*> label_ids, std::vector<double> values, int item_count, int group_count, std::optional<double> group_size, std::optional<double> shift, std::optional<int> flags)
{
	if (static_cast<int>(values.size()) < item_count * group_count)
		values.resize(item_count * group_count, 0);
	if (static_cast<int>(label_ids.size()) < item_count)
		label_ids.resize(item_count, "");

	ImPlot::PlotBarGroups(label_ids.data(), values.data(), item_count, group_count, group_size.value_or(0.67), shift.value_or(0), flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotErrorBars1(const char* label_id, std::vector<double> xs, std::vector<double> ys, std::vector<double> err, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotErrorBars<double>(label_id, xs.data(), ys.data(), err.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotErrorBars2(const char* label_id, std::vector<double> xs, std::vector<double> ys, std::vector<double> neg, std::vector<double> pos, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotErrorBars<double>(label_id, xs.data(), ys.data(), neg.data(), pos.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

//----------------------------------------------------------------------------

void PlotStems1(const char* label_id, std::vector<double> values, int count, std::optional<double> ref, std::optional<double> scale, std::optional<double> start, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotStems(label_id, values.data(), count, ref.value_or(0), scale.value_or(1), start.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotStems2(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<double> ref, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotStems(label_id, xs.data(), ys.data(), count, ref.value_or(0), flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

//----------------------------------------------------------------------------

void PlotInfLines(const char* label_id, std::vector<double> values, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotInfLines(label_id, values.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

//----------------------------------------------------------------------------

void PlotPieChart1(std::vector<const char*> label_ids, std::vector<double> values, int count, double x, double y, double radius, sol::function fmt, std::optional<double> angle0, std::optional<int> flags)
{
	ImPlot::PlotPieChart(label_ids.data(), values.data(), count, x, y, radius, &LuaImPlotFormatter, &fmt, angle0.value_or(90), flags.value_or(0));
}

void PlotPieChart2(std::vector<const char*> label_ids, std::vector<double> values, int count, double x, double y, double radius, std::optional<const char*> label_fmt, std::optional<double> angle0, std::optional<int> flags)
{
	ImPlot::PlotPieChart(label_ids.data(), values.data(), count, x, y, radius, label_fmt.value_or("%.1f"), angle0.value_or(90), flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotHeatmap(const char* label_id, std::vector<double> values, int rows, int cols, std::optional<double> scale_min, std::optional<double> scale_max,
	std::optional<const char*> label_fmt, std::optional<ImPlotPoint> bounds_min, std::optional<ImPlotPoint> bounds_max, std::optional<int>flags)
{
	int size = rows * cols;
	if ((int)values.size() < size)
		values.resize(size, 0);

	ImPlot::PlotHeatmap(label_id, values.data(), rows, cols, scale_min.value_or(0), scale_max.value_or(0), label_fmt.value_or("%.1f"),
		bounds_min.value_or(ImPlotPoint(0, 0)), bounds_max.value_or(ImPlotPoint(1, 1)), flags.value_or(0));
}

//----------------------------------------------------------------------------

double PlotHistogram(const char* label_id, std::vector<double> values, std::optional<int> bins, std::optional<double> bar_scale, std::optional<ImPlotRange> range, std::optional<int> flags)
{
	return ImPlot::PlotHistogram(label_id, values.data(), (int)values.size(), bins.value_or(ImPlotBin_Sturges), bar_scale.value_or(1.0), range.value_or(ImPlotRange()), flags.value_or(0));
}

double PlotHistogram2D(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<int> x_bins, std::optional<int> y_bins, std::optional<ImPlotRect> range, std::optional<int> flags)
{
	return ImPlot::PlotHistogram2D(label_id, xs.data(), ys.data(), count, x_bins.value_or(ImPlotBin_Sturges), y_bins.value_or(ImPlotBin_Sturges), range.value_or(ImPlotRect()), flags.value_or(0));
}

//----------------------------------------------------------------------------

void PlotDigital(const char* label_id, std::vector<double> xs, std::vector<double> ys, int count, std::optional<int> flags, std::optional<int> offset, std::optional<int> stride)
{
	ImPlot::PlotDigital(label_id, xs.data(), ys.data(), count, flags.value_or(0), offset.value_or(0), stride.value_or(1) * sizeof(double));
}

void PlotDigitalG(const char* label_id, sol::unsafe_function getter, int count, std::optional<int> flags)
{
	ImPlot::PlotDigitalG(label_id, &LuaImPlotGetter, &getter, count, flags.value_or(0));
}

//============================================================================
//============================================================================

sol::table RegisterBindings_ImPlot(sol::this_state L)
{
	// The creation of this namespace is gated by the ImGui namespace.
	sol::state_view state{ L };

	sol::table ImPlot = state.create_table();

	// Constants
	state.set("IMPLOT_AUTO", -1);
	state.set("IMPLOT_AUTO_COL", ImVec4(0, 0, 0, -1));

#pragma region Enums
	// Axis indices
	state.new_enum("ImAxis",
		"X1", ImAxis_X1,
		"X2", ImAxis_X2,
		"X3", ImAxis_X3,
		"Y1", ImAxis_Y1,
		"Y2", ImAxis_Y2,
		"Y3", ImAxis_Y3,

		"COUNT", ImAxis_COUNT
	);

	// Options for plots (see BeginPlot).
	state.new_enum("ImPlotFlags",
		"None", ImPlotFlags_None,
		"NoTitle", ImPlotFlags_NoTitle,
		"NoLegend", ImPlotFlags_NoLegend,
		"NoMouseText", ImPlotFlags_NoMouseText,
		"NoInputs", ImPlotFlags_NoInputs,
		"NoMenus", ImPlotFlags_NoMenus,
		"NoBoxSelect", ImPlotFlags_NoBoxSelect,
		"NoFrame", ImPlotFlags_NoFrame,
		"Equal", ImPlotFlags_Equal,
		"Crosshairs", ImPlotFlags_Crosshairs,
		"CanvasOnly", ImPlotFlags_CanvasOnly
	);

	// Options for plot axes (see SetupAxis).
	state.new_enum("ImPlotAxisFlags",
		"None", ImPlotAxisFlags_None,
		"NoLabel", ImPlotAxisFlags_NoLabel,
		"NoGridLines", ImPlotAxisFlags_NoGridLines,
		"NoTickMarks", ImPlotAxisFlags_NoTickMarks,
		"NoTickLabels", ImPlotAxisFlags_NoTickLabels,
		"NoInitialFit", ImPlotAxisFlags_NoInitialFit,
		"NoMenus", ImPlotAxisFlags_NoMenus,
		"NoSideSwitch", ImPlotAxisFlags_NoSideSwitch,
		"NoHighlight", ImPlotAxisFlags_NoHighlight,
		"Opposite", ImPlotAxisFlags_Opposite,
		"Foreground", ImPlotAxisFlags_Foreground,
		"Invert", ImPlotAxisFlags_Invert,
		"AutoFit", ImPlotAxisFlags_AutoFit,
		"RangeFit", ImPlotAxisFlags_RangeFit,
		"PanStretch", ImPlotAxisFlags_PanStretch,
		"LockMin", ImPlotAxisFlags_LockMin,
		"LockMax", ImPlotAxisFlags_LockMax,
		"Lock", ImPlotAxisFlags_Lock,
		"NoDecorations", ImPlotAxisFlags_NoDecorations,
		"AuxDefault", ImPlotAxisFlags_AuxDefault
	);

	// Options for subplots (see BeginSubplot)
	state.new_enum("ImPlotSubplotFlags",
		"None", ImPlotSubplotFlags_None,
		"NoTitle", ImPlotSubplotFlags_NoTitle,
		"NoLegend", ImPlotSubplotFlags_NoLegend,
		"NoMenus", ImPlotSubplotFlags_NoMenus,
		"NoResize", ImPlotSubplotFlags_NoResize,
		"NoAlign", ImPlotSubplotFlags_NoAlign,
		"ShareItems", ImPlotSubplotFlags_ShareItems,
		"LinkRows", ImPlotSubplotFlags_LinkRows,
		"LinkCols", ImPlotSubplotFlags_LinkCols,
		"LinkAllX", ImPlotSubplotFlags_LinkAllX,
		"LinkAllY", ImPlotSubplotFlags_LinkAllY,
		"ColMajor", ImPlotSubplotFlags_ColMajor
	);

	// Options for legends (see SetupLegend)
	state.new_enum("ImPlotLegendFlags",
		"None", ImPlotLegendFlags_None,
		"NoButtons", ImPlotLegendFlags_NoButtons,
		"NoHighlightItem", ImPlotLegendFlags_NoHighlightItem,
		"NoHighlightAxis", ImPlotLegendFlags_NoHighlightAxis,
		"NoMenus", ImPlotLegendFlags_NoMenus,
		"Outside", ImPlotLegendFlags_Outside,
		"Horizontal", ImPlotLegendFlags_Horizontal,
		"Sort", ImPlotLegendFlags_Sort
	);

	// Options for mouse hover text (see SetupMouseText)
	state.new_enum("ImPlotMouseTextFlags",
		"None", ImPlotMouseTextFlags_None,
		"NoAuxAxes", ImPlotMouseTextFlags_NoAuxAxes,
		"NoFormat", ImPlotMouseTextFlags_NoFormat,
		"ShowAlways", ImPlotMouseTextFlags_ShowAlways
	);

	// Options for DragPoint, DragLine, DragRect
	state.new_enum("ImPlotDragToolFlags",
		"None", ImPlotDragToolFlags_None,
		"NoCursors", ImPlotDragToolFlags_NoCursors,
		"NoFit", ImPlotDragToolFlags_NoFit,
		"NoInputs", ImPlotDragToolFlags_NoInputs,
		"Delayed", ImPlotDragToolFlags_Delayed
	);

	// Flags for ColormapScale
	state.new_enum("ImPlotColormapScaleFlags",
		"None", ImPlotColormapScaleFlags_None,
		"NoLabel", ImPlotColormapScaleFlags_NoLabel,
		"Opposite", ImPlotColormapScaleFlags_Opposite,
		"Invert", ImPlotColormapScaleFlags_Invert
	);

	// Flags for ANY PlotX function
	state.new_enum("ImPlotItemFlags",
		"None", ImPlotItemFlags_None,
		"NoLegend", ImPlotItemFlags_NoLegend,
		"NoFit", ImPlotItemFlags_NoFit
	);

	// Flags for PlotLine
	state.new_enum("ImPlotLineFlags",
		"None", ImPlotLineFlags_None,
		"Segments", ImPlotLineFlags_Segments,
		"Loop", ImPlotLineFlags_Loop,
		"SkipNaN", ImPlotLineFlags_SkipNaN,
		"NoClip", ImPlotLineFlags_NoClip,
		"Shaded", ImPlotLineFlags_Shaded
	);

	// Flags for PlotScatter
	state.new_enum("ImPlotScatterFlags",
		"None", ImPlotScatterFlags_None,
		"NoClip", ImPlotScatterFlags_NoClip
	);

	// Flags for PlotStairs
	state.new_enum("ImPlotStairsFlags",
		"None", ImPlotStairsFlags_None,
		"PreStep", ImPlotStairsFlags_PreStep,
		"Shaded", ImPlotStairsFlags_Shaded
	);

	// Flags for PlotShaded (placeholder)
	state.new_enum("ImPlotShadedFlags",
		"None", ImPlotShadedFlags_None
	);

	// Flags for PlotBars
	state.new_enum("ImPlotBarsFlags",
		"None", ImPlotBarsFlags_None,
		"Horizontal", ImPlotBarsFlags_Horizontal
	);

	// Flags for PlotBarGroups
	state.new_enum("ImPlotBarGroupsFlags",
		"None", ImPlotBarGroupsFlags_None,
		"Horizontal", ImPlotBarGroupsFlags_Horizontal,
		"Stacked", ImPlotBarGroupsFlags_Stacked
	);

	// Flags for PlotErrorBars
	state.new_enum("ImPlotErrorBarsFlags",
		"None", ImPlotErrorBarsFlags_None,
		"Horizontal", ImPlotErrorBarsFlags_Horizontal
	);

	// Flags for PlotStems
	state.new_enum("ImPlotStemsFlags",
		"None", ImPlotStemsFlags_None,
		"Horizontal", ImPlotStemsFlags_Horizontal
	);

	// Flags for PlotInfLines
	state.new_enum("ImPlotInfLinesFlags",
		"None", ImPlotInfLinesFlags_None,
		"Horizontal", ImPlotInfLinesFlags_Horizontal
	);

	// Flags for PlotPieChart
	state.new_enum("ImPlotPieChartFlags",
		"None", ImPlotPieChartFlags_None,
		"Normalize", ImPlotPieChartFlags_Normalize,
		"IgnoreHidden", ImPlotPieChartFlags_IgnoreHidden
	);

	// Flags for PlotHeatmap
	state.new_enum("ImPlotHeatmapFlags",
		"None", ImPlotHeatmapFlags_None,
		"ColMajor", ImPlotHeatmapFlags_ColMajor
	);

	// Flags for PlotHistogram and PlotHistogram2D
	state.new_enum("ImPlotHistogramFlags",
		"None", ImPlotHistogramFlags_None,
		"Horizontal", ImPlotHistogramFlags_Horizontal,
		"Cumulative", ImPlotHistogramFlags_Cumulative,
		"Density", ImPlotHistogramFlags_Density,
		"NoOutliers", ImPlotHistogramFlags_NoOutliers,
		"ColMajor", ImPlotHistogramFlags_ColMajor
	);

	// Flags for PlotDigital (placeholder)
	state.new_enum("ImPlotDigitalFlags",
		"None", ImPlotDigitalFlags_None
	);

	// Flags for PlotImage (placeholder)
	state.new_enum("ImPlotImageFlags",
		"None", ImPlotImageFlags_None
	);

	// Flags for PlotText
	state.new_enum("ImPlotTextFlags",
		"None", ImPlotTextFlags_None,
		"Vertical", ImPlotTextFlags_Vertical
	);

	// Flags for PlotDummy (placeholder)
	state.new_enum("ImPlotDummyFlags",
		"None", ImPlotDummyFlags_None
	);

	// Represents a condition for SetupAxisLimits etc. (same as ImGuiCond, but we only support a subset of those enums)
	state.new_enum("ImPlotCond",
		"None", ImPlotCond_None,
		"Always", ImPlotCond_Always,
		"Once", ImPlotCond_Once
	);

	// Plot styling colors.
	state.new_enum("ImPlotCol",
		// item styling colors
		"Line", ImPlotCol_Line,
		"Fill", ImPlotCol_Fill,
		"MarkerOutline", ImPlotCol_MarkerOutline,
		"MarkerFill", ImPlotCol_MarkerFill,
		"ErrorBar", ImPlotCol_ErrorBar,
		// plot styling colors
		"FrameBg", ImPlotCol_FrameBg,
		"PlotBg", ImPlotCol_PlotBg,
		"PlotBorder", ImPlotCol_PlotBorder,
		"LegendBg", ImPlotCol_LegendBg,
		"LegendBorder", ImPlotCol_LegendBorder,
		"LegendText", ImPlotCol_LegendText,
		"TitleText", ImPlotCol_TitleText,
		"InlayText", ImPlotCol_InlayText,
		"AxisText", ImPlotCol_AxisText,
		"AxisGrid", ImPlotCol_AxisGrid,
		"AxisTick", ImPlotCol_AxisTick,
		"AxisBg", ImPlotCol_AxisBg,
		"AxisBgHovered", ImPlotCol_AxisBgHovered,
		"AxisBgActive", ImPlotCol_AxisBgActive,
		"Selection", ImPlotCol_Selection,
		"Crosshairs", ImPlotCol_Crosshairs,
		"COUNT", ImPlotCol_COUNT
	);

	// Plot styling variables.
	state.new_enum("ImPlotStyleVar",
		// item styling variables
		"LineWeight", ImPlotStyleVar_LineWeight,
		"Marker", ImPlotStyleVar_Marker,
		"MarkerSize", ImPlotStyleVar_MarkerSize,
		"MarkerWeight", ImPlotStyleVar_MarkerWeight,
		"FillAlpha", ImPlotStyleVar_FillAlpha,
		"ErrorBarSize", ImPlotStyleVar_ErrorBarSize,
		"ErrorBarWeight", ImPlotStyleVar_ErrorBarWeight,
		"DigitalBitHeight", ImPlotStyleVar_DigitalBitHeight,
		"DigitalBitGap", ImPlotStyleVar_DigitalBitGap,
		// plot styling variables
		"PlotBorderSize", ImPlotStyleVar_PlotBorderSize,
		"MinorAlpha", ImPlotStyleVar_MinorAlpha,
		"MajorTickLen", ImPlotStyleVar_MajorTickLen,
		"MinorTickLen", ImPlotStyleVar_MinorTickLen,
		"MajorTickSize", ImPlotStyleVar_MajorTickSize,
		"MinorTickSize", ImPlotStyleVar_MinorTickSize,
		"MajorGridSize", ImPlotStyleVar_MajorGridSize,
		"MinorGridSize", ImPlotStyleVar_MinorGridSize,
		"PlotPadding", ImPlotStyleVar_PlotPadding,
		"LabelPadding", ImPlotStyleVar_LabelPadding,
		"LegendPadding", ImPlotStyleVar_LegendPadding,
		"LegendInnerPadding", ImPlotStyleVar_LegendInnerPadding,
		"LegendSpacing", ImPlotStyleVar_LegendSpacing,
		"MousePosPadding", ImPlotStyleVar_MousePosPadding,
		"AnnotationPadding", ImPlotStyleVar_AnnotationPadding,
		"FitPadding", ImPlotStyleVar_FitPadding,
		"PlotDefaultSize", ImPlotStyleVar_PlotDefaultSize,
		"PlotMinSize", ImPlotStyleVar_PlotMinSize,
		"COUNT", ImPlotStyleVar_COUNT
	);

	// Axis scale
	state.new_enum("ImPlotScale",
		"Linear", ImPlotScale_Linear,
		"Time", ImPlotScale_Time,
		"Log10", ImPlotScale_Log10,
		"SymLog", ImPlotScale_SymLog
	);

	// Marker specifications.
	state.new_enum("ImPlotMarker",
		"None", ImPlotMarker_None,
		"Circle", ImPlotMarker_Circle,
		"Square", ImPlotMarker_Square,
		"Diamond", ImPlotMarker_Diamond,
		"Up", ImPlotMarker_Up,
		"Down", ImPlotMarker_Down,
		"Left", ImPlotMarker_Left,
		"Right", ImPlotMarker_Right,
		"Cross", ImPlotMarker_Cross,
		"Plus", ImPlotMarker_Plus,
		"Asterisk", ImPlotMarker_Asterisk,
		"COUNT", ImPlotMarker_COUNT
	);

	// Built-in colormaps
	state.new_enum("ImPlotColormap",
		"Deep", ImPlotColormap_Deep,
		"Dark", ImPlotColormap_Dark,
		"Pastel", ImPlotColormap_Pastel,
		"Paired", ImPlotColormap_Paired,
		"Viridis", ImPlotColormap_Viridis,
		"Plasma", ImPlotColormap_Plasma,
		"Hot", ImPlotColormap_Hot,
		"Cool", ImPlotColormap_Cool,
		"Pink", ImPlotColormap_Pink,
		"Jet", ImPlotColormap_Jet,
		"Twilight", ImPlotColormap_Twilight,
		"RdBu", ImPlotColormap_RdBu,
		"BrBG", ImPlotColormap_BrBG,
		"PiYG", ImPlotColormap_PiYG,
		"Spectral", ImPlotColormap_Spectral,
		"Greys", ImPlotColormap_Greys
	);

	// Used to position items on a plot (e.g. legends, labels, etc.)
	state.new_enum("ImPlotLocation",
		"Center", ImPlotLocation_Center,
		"North", ImPlotLocation_North,
		"South", ImPlotLocation_South,
		"West", ImPlotLocation_West,
		"East", ImPlotLocation_East,
		"NorthWest", ImPlotLocation_NorthWest,
		"NorthEast", ImPlotLocation_NorthEast,
		"SouthWest", ImPlotLocation_SouthWest,
		"SouthEast", ImPlotLocation_SouthEast
	);

	// Enums for different automatic histogram binning methods (k = bin count or w = bin width)
	state.new_enum("ImPlotBin",
		"Sqrt", ImPlotBin_Sqrt,
		"Sturges", ImPlotBin_Sturges,
		"Rice", ImPlotBin_Rice,
		"Scott", ImPlotBin_Scott
	);
#pragma endregion

#pragma region User Types
	// Double precision version of ImVec2 used by ImPlot. Extensible by end users.
	state.new_usertype<ImPlotPoint>(
		"ImPlotPoint", sol::call_constructor
		, sol::constructors<ImPlotPoint(), ImPlotPoint(float, float), ImPlotPoint(const ImVec2&)>(),
		"x", &ImPlotPoint::x,
		"y", &ImPlotPoint::y,
		sol::meta_function::to_string, [](const ImPlotPoint& mThis) { return fmt::format("({},{})", mThis.x, mThis.y); },
		sol::meta_function::addition, sol::overload(
			[](const ImPlotPoint& a, const ImPlotPoint& b) { return ImPlotPoint(a.x + b.x, a.y + b.y); },
			[](const ImPlotPoint& a, double b) { return ImPlotPoint(a.x + b, a.y + b); }),
		sol::meta_function::subtraction, sol::overload(
			[](const ImPlotPoint& a, const ImPlotPoint& b) { return ImPlotPoint(a.x - b.x, a.y - b.y); },
			[](const ImPlotPoint& a, double b) { return ImPlotPoint(a.x - b, a.y - b); }),
		sol::meta_function::multiplication, sol::overload(
			[](const ImPlotPoint& a, const ImPlotPoint& b) { return ImPlotPoint(a.x * b.x, a.y * b.y); },
			[](const ImPlotPoint& a, double b) { return ImPlotPoint(a.x * b, a.y * b); }),
		sol::meta_function::division, sol::overload(
			[](const ImPlotPoint& a, const ImPlotPoint& b) { return ImPlotPoint(a.x / b.x, a.y / b.y); },
			[](const ImPlotPoint& a, double b) { return ImPlotPoint(a.x / b, a.y / b); }),
		sol::meta_function::equal_to, [](const ImPlotPoint& a, const ImPlotPoint& b) { return a.x == b.x && a.y == b.y; },
		sol::meta_function::less_than, [](const ImPlotPoint& a, const ImPlotPoint& b) { return std::tie(a.x, a.y) < std::tie(b.x, b.y); },
		sol::meta_function::less_than_or_equal_to, [](const ImPlotPoint& a, const ImPlotPoint& b) { return std::tie(a.x, a.y) <= std::tie(b.x, b.y); },

		sol::meta_function::index, [](const ImPlotPoint& point, int index, sol::this_state L) -> sol::object { if (index == 1 || index == 2) return sol::make_object(L, point[index]); return sol::make_object(L, sol::nil); }
	);

	state.new_usertype<ImPlotRange>(
		"ImPlotRange", sol::call_constructor,
		sol::constructors<ImPlotRange(), ImPlotRange(double, double)>(),
		"Min", &ImPlotRange::Min,
		"Max", &ImPlotRange::Max,
		"Contains", &ImPlotRange::Contains,
		"Size", &ImPlotRange::Size,
		"Clamp", &ImPlotRange::Clamp
	);

	state.new_usertype<ImPlotRect>(
		"ImPlotRect", sol::call_constructor,
		sol::constructors<ImPlotRect(), ImPlotRect(double, double, double, double)>(),
		"X", &ImPlotRect::X,
		"Y", &ImPlotRect::Y,
		"Contains", sol::overload(
			sol::resolve<bool(const ImPlotPoint&) const>(&ImPlotRect::Contains),
			sol::resolve<bool(double, double) const>(&ImPlotRect::Contains)
		),
		"Size", &ImPlotRect::Size,
		"Clamp", sol::overload(
			sol::resolve<ImPlotPoint(const ImPlotPoint&)>(&ImPlotRect::Clamp),
			sol::resolve<ImPlotPoint(double, double)>(&ImPlotRect::Clamp)
		),
		"Min", &ImPlotRect::Min,
		"Max", &ImPlotRect::Max
	);

	state.new_usertype<ImPlotStyle>(
		"ImPlotStyle", sol::no_constructor,

		"LineWeight", &ImPlotStyle::LineWeight,
		"Marker", &ImPlotStyle::Marker,
		"MarkerSize", &ImPlotStyle::MarkerSize,
		"MarkerWeight", &ImPlotStyle::MarkerWeight,
		"FillAlpha", &ImPlotStyle::FillAlpha,
		"ErrorBarSize", &ImPlotStyle::ErrorBarSize,
		"ErrorBarWeight", &ImPlotStyle::ErrorBarWeight,
		"DigitalBitHeight", &ImPlotStyle::DigitalBitHeight,
		"DigitalBitGap", &ImPlotStyle::DigitalBitGap,
		"PlotBorderSize", &ImPlotStyle::PlotBorderSize,
		"MinorAlpha", &ImPlotStyle::MinorAlpha,
		"MajorTickLen", &ImPlotStyle::MajorTickLen,
		"MinorTickLen", &ImPlotStyle::MinorTickLen,
		"MajorTickSize", &ImPlotStyle::MajorTickSize,
		"MinorTickSize", &ImPlotStyle::MinorTickSize,
		"MajorGridSize", &ImPlotStyle::MajorGridSize,
		"MinorGridSize", &ImPlotStyle::MinorGridSize,
		"PlotPadding", &ImPlotStyle::PlotPadding,
		"LabelPadding", &ImPlotStyle::LabelPadding,
		"LegendPadding", &ImPlotStyle::LegendPadding,
		"LegendInnerPadding", &ImPlotStyle::LegendInnerPadding,
		"LegendSpacing", &ImPlotStyle::LegendSpacing,
		"MousePosPadding", &ImPlotStyle::MousePosPadding,
		"AnnotationPadding", &ImPlotStyle::AnnotationPadding,
		"FitPadding", &ImPlotStyle::FitPadding,
		"PlotDefaultSize", &ImPlotStyle::PlotDefaultSize,
		"PlotMinSize", &ImPlotStyle::PlotMinSize,
		"Colors", &ImPlotStyle::Colors,
		"Colormap", &ImPlotStyle::Colormap,
		"UseLocalTime", &ImPlotStyle::UseLocalTime,
		"UseISO8601", &ImPlotStyle::UseISO8601,
		"Use24HourClock", &ImPlotStyle::Use24HourClock
	);

	state.new_usertype<ImPlotInputMap>(
		"ImPlotInputMap", sol::no_constructor,
		"Pan", &ImPlotInputMap::Pan,
		"PanMod", &ImPlotInputMap::PanMod,
		"Fit", &ImPlotInputMap::Fit,
		"Select", &ImPlotInputMap::Select,
		"SelectCancel", &ImPlotInputMap::SelectCancel,
		"SelectMod", &ImPlotInputMap::SelectMod,
		"SelectHorzMod", &ImPlotInputMap::SelectHorzMod,
		"SelectVertMod", &ImPlotInputMap::SelectVertMod,
		"Menu", &ImPlotInputMap::Menu,
		"OverrideMod", &ImPlotInputMap::OverrideMod,
		"ZoomMod", &ImPlotInputMap::ZoomMod,
		"ZoomRate", &ImPlotInputMap::ZoomRate
	);
#pragma endregion

#pragma region Functions
	// [SECTION] Begin/End Plot
	ImPlot.set_function("BeginPlot", [](const char* title_id, std::optional<ImVec2> size, std::optional<int> flags) { return ImPlot::BeginPlot(title_id, size.value_or(ImVec2(-1, 0)), flags.value_or(0)); });
	ImPlot.set_function("EndPlot", &ImPlot::EndPlot);

	// [SECTION] Begin/End Subplots
	ImPlot.set_function("BeginSubplots", [](const char* title_id, int rows, int cols, const ImVec2& size, std::optional<int> flags,
		std::optional<sol::table> row_ratios_vec, std::optional<sol::table> col_ratios_vec)
		{
			std::vector<float> row_ratios;
			if (row_ratios_vec.has_value())
			{
				row_ratios = row_ratios_vec->as<std::vector<float>>();
				if (static_cast<int>(row_ratios.size()) < rows)
					row_ratios.resize(rows, 0);
			}

			std::vector<float> col_ratios;
			if (col_ratios_vec.has_value())
			{
				col_ratios = col_ratios_vec->as<std::vector<float>>();
				if (static_cast<int>(col_ratios.size()) < cols)
					col_ratios.resize(cols);
			}

			return ImPlot::BeginSubplots(title_id, rows, cols, size, flags.value_or(0),
				row_ratios_vec.has_value() ? row_ratios.data() : nullptr,
				col_ratios_vec.has_value() ? col_ratios.data() : nullptr);
		});
	ImPlot.set_function("EndSubplots", &ImPlot::EndSubplots);

	// [SECTION] Setup
	ImPlot.set_function("SetupAxis", [](int axis, std::optional<const char*> label, std::optional<int> flags) { ImPlot::SetupAxis(axis, label.value_or(nullptr), flags.value_or(0)); });
	ImPlot.set_function("SetupAxisLimits", [](int axis, double v_min, double v_max, std::optional<int> cond) { ImPlot::SetupAxisLimits(axis, v_min, v_max, cond.value_or(ImPlotCond_Once)); });
	//ImPlot.set_function("SetupAxisLinks", []() {})
	// Missing SetupAxisFormat with callback
	ImPlot.set_function("SetupAxisFormat", [](int axis, const char* fmt) { ImPlot::SetupAxisFormat(axis, fmt); });
	ImPlot.set_function("SetupAxisTicks", sol::overload(
		[](int axis, std::vector<double> values, std::optional<sol::table> labelsTable, std::optional<bool> keepDefault)
		{
			const char** labels = nullptr;
			std::vector<const char*> labels_;
			if (labelsTable.has_value())
			{
				labels_ = labelsTable->as<std::vector<const char*>>();

				if (labels_.size() < values.size())
					labels_.resize(values.size(), "");
				labels = labels_.data();
			}
			ImPlot::SetupAxisTicks(axis, values.data(), (int)values.size(), labels, keepDefault.value_or(false));
		},
		[](int axis, double v_min, double v_max, int n_ticks, std::optional<sol::table> labelsTable, std::optional<bool> keepDefault)
		{
			const char** labels = nullptr;
			std::vector<const char*> labels_;
			if (labelsTable.has_value())
			{
				labels_ = labelsTable->as<std::vector<const char*>>();

				if (static_cast<int>(labels_.size()) < n_ticks)
					labels_.resize(n_ticks, "");
				labels = labels_.data();
			}
			ImPlot::SetupAxisTicks(axis, v_min, v_max, n_ticks, labels, keepDefault.value_or(false));
		}
	));
	// Missing SetupAxisScale with transform
	ImPlot.set_function("SetupAxisScale", [](int axis, int scale) { ImPlot::SetupAxisScale(axis, scale); });
	ImPlot.set_function("SetupAxisLimitsConstraints", &ImPlot::SetupAxisLimitsConstraints);
	ImPlot.set_function("SetupAxisZoomConstraints", &ImPlot::SetupAxisZoomConstraints);

	ImPlot.set_function("SetupAxes", [](std::optional<const char*> x_label, std::optional<const char*> y_label, std::optional<int> x_flags, std::optional<int> y_flags) { ImPlot::SetupAxes(x_label.value_or(nullptr), y_label.value_or(nullptr), x_flags.value_or(0), y_flags.value_or(0)); });
	ImPlot.set_function("SetupAxesLimits", [](double x_min, double x_max, double y_min, double y_max, std::optional<int> cond) { ImPlot::SetupAxesLimits(x_min, x_max, y_min, y_max, cond.value_or(ImPlotCond_Once)); });

	ImPlot.set_function("SetupLegend", [](int location, std::optional<int> flags) { ImPlot::SetupLegend(location, flags.value_or(0)); });
	ImPlot.set_function("SetupMouseText", [](int location, std::optional<int> flags) { ImPlot::SetupMouseText(location, flags.value_or(0)); });

	ImPlot.set_function("SetupFinish", &ImPlot::SetupFinish);

	// [SECTION] SetNext
	ImPlot.set_function("SetNextAxisLimits", [](int axis, double v_min, double v_max, std::optional<int> cond) { ImPlot::SetNextAxisLimits(axis, v_min, v_max, cond.value_or(ImPlotCond_Once)); });
	// SetNextAxisLinks
	ImPlot.set_function("SetNextAxisToFit", &ImPlot::SetNextAxisToFit);

	ImPlot.set_function("SetNextAxesLimits", [](double x_min, double x_max, double y_min, double y_max, std::optional<int> cond) { ImPlot::SetNextAxesLimits(x_min, x_max, y_min, y_max, cond.value_or(ImPlotCond_Once)); });
	ImPlot.set_function("SetNextAxesToFit", &ImPlot::SetNextAxesToFit);

	// [SECTION] Plot Items
	ImPlot.set_function("PlotLine", sol::overload(&PlotLine1, &PlotLine2, &PlotLineG));
	ImPlot.set_function("PlotScatter", sol::overload(&PlotScatter1, &PlotScatter2, &PlotScatterG));
	ImPlot.set_function("PlotStairs", sol::overload(&PlotStairs1, &PlotStairs2, &PlotStairsG));
	ImPlot.set_function("PlotShaded", sol::overload(&PlotShaded1, &PlotShaded2, &PlotShaded3, &PlotShadedG));
	ImPlot.set_function("PlotBars", sol::overload(&PlotBars1, &PlotBars2, &PlotBarsG));
	ImPlot.set_function("PlotBarGroups", &PlotBarGroups);
	ImPlot.set_function("PlotErrorBars", sol::overload(&PlotErrorBars1, &PlotErrorBars2));
	ImPlot.set_function("PlotStems", sol::overload(&PlotStems1, &PlotStems2));
	ImPlot.set_function("PlotInfLines", &PlotInfLines);
	ImPlot.set_function("PlotPieChart", sol::overload(&PlotPieChart1, &PlotPieChart2));
	ImPlot.set_function("PlotHeatmap", &PlotHeatmap);
	ImPlot.set_function("PlotHistogram", &PlotHistogram);
	ImPlot.set_function("PlotHistogram2D", &PlotHistogram2D);
	ImPlot.set_function("PlotDigital", sol::overload(&PlotDigital, &PlotDigitalG));
	ImPlot.set_function("PlotImage", [](const char* label_id, const ImTextureRef& tex_ref, const ImPlotPoint& bounds_min, const ImPlotPoint& bounds_max, std::optional<ImVec2> uv0, std::optional<ImVec2> uv1, std::optional<ImVec4> tint_col, std::optional<int> flags) {
		ImPlot::PlotImage(label_id, tex_ref, bounds_min, bounds_max, uv0.value_or(ImVec2(0, 0)), uv1.value_or(ImVec2(1, 1)), tint_col.value_or(ImVec4(1, 1, 1, 1)), flags.value_or(0));
	});
	ImPlot.set_function("PlotText", [](const char* text, double x, double y, std::optional<ImVec2> pix_offset, std::optional<int> flags) { ImPlot::PlotText(text, x, y, pix_offset.value_or(ImVec2(0, 0)), flags.value_or(0)); });
	ImPlot.set_function("PlotDummy", [](const char* label_id, std::optional<int> flags) { ImPlot::PlotDummy(label_id, flags.value_or(0)); });

	// TODO: More

	// [SECTION] Plot Tools
	ImPlot.set_function("DragPoint", [](int id, double x, double y, const ImVec4& col, std::optional<float> size, std::optional<int> flags) { bool clicked = false, hovered = false, held = false; bool modified = ImPlot::DragPoint(id, &x, &y, col, size.value_or(4), flags.value_or(0), &clicked, &hovered, &held); return std::make_tuple(modified, x, y, clicked, hovered, held); });
	ImPlot.set_function("DragLineX", [](int id, double x, const ImVec4& col, std::optional<float> thickness, std::optional<int> flags) { bool clicked = false, hovered = false, held = false; bool modified = ImPlot::DragLineX(id, &x, col, thickness.value_or(1), flags.value_or(0), &clicked, &hovered, &held); return std::make_tuple(modified, x, clicked, hovered, held); });
	ImPlot.set_function("DragLineY", [](int id, double y, const ImVec4& col, std::optional<float> thickness, std::optional<int> flags) { bool clicked = false, hovered = false, held = false; bool modified = ImPlot::DragLineX(id, &y, col, thickness.value_or(1), flags.value_or(0), &clicked, &hovered, &held); return std::make_tuple(modified, y, clicked, hovered, held); });
	ImPlot.set_function("DragRect", [](int id, double x1, double y1, double x2, double y2, const ImVec4& col, std::optional<int> flags) { bool clicked = false, hovered = false, held = false; bool modified = ImPlot::DragRect(id, &x1, &y1, &x2, &y2, col, flags.value_or(0), &clicked, &hovered, &held); return std::make_tuple(modified, x1, y1, x2, y2, clicked, hovered, held); });
	ImPlot.set_function("Annotation", sol::overload(
		[](double x, double y, const ImVec4& col, const ImVec2& pix_offset, bool clamp, std::optional<bool> round) { ImPlot::Annotation(x, y, col, pix_offset, clamp, round.value_or(false)); },
		[](double x, double y, const ImVec4& col, const ImVec2& pix_offset, bool clamp, sol::variadic_args args, sol::this_state s) { std::string text = format_text(s, args); ImPlot::Annotation(x, y, col, pix_offset, clamp, "%s", text.c_str()); }
	));
	ImPlot.set_function("TagX", sol::overload(
		[](double x, const ImVec4& col, std::optional<bool> round) { ImPlot::TagX(x, col, round.value_or(false)); },
		[](double x, const ImVec4& col, sol::variadic_args args, sol::this_state s) { ImPlot::TagX(x, col, "%s", format_text(s, args).c_str()); }
	));
	ImPlot.set_function("TagX", sol::overload(
		[](double y, const ImVec4& col, std::optional<bool> round) { ImPlot::TagY(y, col, round.value_or(false)); },
		[](double y, const ImVec4& col, sol::variadic_args args, sol::this_state s) { ImPlot::TagY(y, col, "%s", format_text(s, args).c_str()); }
	));

	// [SECTION] Plot Utils
	ImPlot.set_function("SetAxis", &ImPlot::SetAxis);
	ImPlot.set_function("SetAxes", &ImPlot::SetAxes);
	ImPlot.set_function("PixelsToPlot", sol::overload(
		[](const ImVec2& pix, std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::PixelsToPlot(pix, x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); },
		[](float x, float y, std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::PixelsToPlot(x, y, x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); }
	));
	ImPlot.set_function("PlotToPixels", sol::overload(
		[](const ImPlotPoint& point, std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::PlotToPixels(point, x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); },
		[](double x, double y, std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::PlotToPixels(x, y, x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); }
	));
	ImPlot.set_function("GetPlotPos", &ImPlot::GetPlotPos);
	ImPlot.set_function("GetPlotSize", &ImPlot::GetPlotSize);
	ImPlot.set_function("GetPlotMousePos", [](std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::GetPlotMousePos(x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("GetPlotLimits", [](std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::GetPlotLimits(x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("IsPlotHovered", &ImPlot::IsPlotHovered);
	ImPlot.set_function("IsAxisHovered", &ImPlot::IsAxisHovered);
	ImPlot.set_function("IsSubplotsHovered", &ImPlot::IsSubplotsHovered);
	ImPlot.set_function("IsPlotSelected", &ImPlot::IsPlotSelected);
	ImPlot.set_function("GetPlotSelection", [](std::optional<int> x_axis, std::optional<int> y_axis) { return ImPlot::GetPlotSelection(x_axis.value_or(IMPLOT_AUTO), y_axis.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("CancelPlotSelection", &ImPlot::CancelPlotSelection);
	ImPlot.set_function("HideNextItem", [](std::optional<bool> hidden, std::optional<int> cond) { ImPlot::HideNextItem(hidden.value_or(true), cond.value_or(ImPlotCond_Once)); });

	ImPlot.set_function("BeginAlignedPlots", [](const char* group_id, std::optional<bool> vertical) { return ImPlot::BeginAlignedPlots(group_id, vertical.value_or(true)); });
	ImPlot.set_function("EndAlignedPlots", &ImPlot::EndAlignedPlots);

	// [SECTION] Legend Utils
	ImPlot.set_function("BeginLegendPopup", [](const char* label_id, std::optional<int> mouse_button) { return ImPlot::BeginLegendPopup(label_id, mouse_button.value_or(1)); });
	ImPlot.set_function("EndLegendPopup", &ImPlot::EndLegendPopup);
	ImPlot.set_function("IsLegendEntryHovered", &ImPlot::IsLegendEntryHovered);

	// [SECTION] Drag and Drop
	ImPlot.set_function("BeginDragDropTargetPlot", &ImPlot::BeginDragDropTargetPlot);
	ImPlot.set_function("BeginDragDropTargetAxis", &ImPlot::BeginDragDropTargetAxis);
	ImPlot.set_function("BeginDragDropTargetLegend", &ImPlot::BeginDragDropTargetLegend);
	ImPlot.set_function("EndDragDropTarget", &ImPlot::EndDragDropTarget);
	ImPlot.set_function("BeginDragDropSourcePlot", [](std::optional<int> flags) { return ImPlot::BeginDragDropSourcePlot(flags.value_or(0)); });
	ImPlot.set_function("BeginDragDropSourceAxis", [](int axis, std::optional<int> flags) { return ImPlot::BeginDragDropSourceAxis(axis, flags.value_or(0)); });
	ImPlot.set_function("BeginDragDropSourceItem", [](const char* label_id, std::optional<int> flags) { return ImPlot::BeginDragDropSourceItem(label_id, flags.value_or(0)); });
	ImPlot.set_function("EndDragDropSource", &ImPlot::EndDragDropSource);

	// [SECTION] Styling
	ImPlot.set_function("GetStyle", []() { return &ImPlot::GetStyle(); });
	ImPlot.set_function("StyleColorsAuto", [](std::optional<ImPlotStyle*> dst) { ImPlot::StyleColorsAuto(dst.value_or(nullptr)); });
	ImPlot.set_function("StyleColorsClassic", [](std::optional<ImPlotStyle*> dst) { ImPlot::StyleColorsClassic(dst.value_or(nullptr)); });
	ImPlot.set_function("StyleColorsDark", [](std::optional<ImPlotStyle*> dst) { ImPlot::StyleColorsDark(dst.value_or(nullptr)); });
	ImPlot.set_function("StyleColorsLight", [](std::optional<ImPlotStyle*> dst) { ImPlot::StyleColorsLight(dst.value_or(nullptr)); });

	ImPlot.set_function("PushStyleColor", sol::overload(
		[](int idx, int col) { ImPlot::PushStyleColor(idx, ImU32(col)); },
		[](int idx, float colR, float colG, float colB, float colA) { ImPlot::PushStyleColor(idx, { colR, colG, colB, colA }); },
		[](int idx, const ImVec4& col) { ImPlot::PushStyleColor(idx, col); }
	));
	ImPlot.set_function("PopStyleColor", [](std::optional<int> count) { ImPlot::PopStyleColor(count.value_or(1)); });
	ImPlot.set_function("PushStyleVar", sol::overload(
		[](int idx, float val) { ImPlot::PushStyleVar(idx, val); },
		[](int idx, float valX, float valY) { ImPlot::PushStyleVar(idx, { valX, valY }); },
		[](int idx, const ImVec2& val) { ImPlot::PushStyleVar(idx, val); }
	));
	ImPlot.set_function("PopStyleVar", [](std::optional<int> count) { ImPlot::PopStyleVar(count.value_or(1)); });

	ImPlot.set_function("SetNextLineStyle", [](std::optional<ImVec4> col, std::optional<float> weight) { ImPlot::SetNextLineStyle(col.value_or(IMPLOT_AUTO_COL), weight.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("SetNextFillStyle", [](std::optional<ImVec4> col, std::optional<float> alpha_mod) { ImPlot::SetNextFillStyle(col.value_or(IMPLOT_AUTO_COL), alpha_mod.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("SetNextMarkerStyle", [](std::optional<int> marker, std::optional<float> size, std::optional<ImVec4> fill, std::optional<float> weight, std::optional<ImVec4> outline) { ImPlot::SetNextMarkerStyle(marker.value_or(IMPLOT_AUTO), size.value_or(IMPLOT_AUTO), fill.value_or(IMPLOT_AUTO_COL), weight.value_or(IMPLOT_AUTO), outline.value_or(IMPLOT_AUTO_COL)); });
	ImPlot.set_function("SetNextErrorBarStyle", [](std::optional<ImVec4> col, std::optional<float> size, std::optional<float> weight) { ImPlot::SetNextErrorBarStyle(col.value_or(IMPLOT_AUTO_COL), size.value_or(IMPLOT_AUTO), weight.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("GetLastItemColor", &ImPlot::GetLastItemColor);
	ImPlot.set_function("GetStyleColorName", &ImPlot::GetStyleColorName);
	ImPlot.set_function("GetMarkerName", &ImPlot::GetMarkerName);

	// [SECTION] Colormaps
	ImPlot.set_function("AddColormap", sol::overload(
		[](const char* name, std::vector<ImU32> cols, std::optional<bool> qual) { return ImPlot::AddColormap(name, cols.data(), (int)cols.size(), qual.value_or(true)); },
		[](const char* name, std::vector<ImVec4> cols, std::optional<bool> qual) { return ImPlot::AddColormap(name, cols.data(), (int)cols.size(), qual.value_or(true)); }
	));
	ImPlot.set_function("GetColormapCount", &ImPlot::GetColormapCount);
	ImPlot.set_function("GetColormapName", &ImPlot::GetColormapName);
	ImPlot.set_function("GetColormapIndex", &ImPlot::GetColormapIndex);

	ImPlot.set_function("PushColormap", sol::overload(
		sol::resolve<void(ImPlotColormap)>(&ImPlot::PushColormap),
		sol::resolve<void(const char*)>(&ImPlot::PushColormap)
	));
	ImPlot.set_function("PopColormap", [](std::optional<int> count) { ImPlot::PopColormap(count.value_or(1)); });
	ImPlot.set_function("NextColormapColor", &ImPlot::NextColormapColor);
	ImPlot.set_function("GetColormapSize", [](std::optional<int> cmap) { return ImPlot::GetColormapSize(cmap.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("GetColormapColor", [](int idx, std::optional<int> cmap) { return ImPlot::GetColormapColor(idx, cmap.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("SampleColormap", [](float t, std::optional<int> cmap) { return ImPlot::SampleColormap(t, cmap.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("ColormapScale", [](const char* label, double scale_min, double scale_max, std::optional<ImVec2> size, std::optional<const char*> format, std::optional<int> flags, std::optional<int> cmap) { ImPlot::ColormapScale(label, scale_min, scale_max, size.value_or(ImVec2(0, 0)), format.value_or("%g"), flags.value_or(0), cmap.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("ColormapSlider", [](const char* label, float t, std::optional<const char*> format, std::optional<int> cmap) { ImVec4 out;  bool changed = ImPlot::ColormapSlider(label, &t, &out, format.value_or(""), cmap.value_or(IMPLOT_AUTO)); return std::make_tuple(changed, t, out); });
	ImPlot.set_function("ColormapButton", [](const char* label, std::optional<ImVec2> size, std::optional<int> cmap) { return ImPlot::ColormapButton(label, size.value_or(ImVec2(0, 0)), cmap.value_or(IMPLOT_AUTO)); });
	ImPlot.set_function("BustColorCache", [](std::optional<const char*> plot_title_id) { ImPlot::BustColorCache(plot_title_id.value_or(nullptr)); });

	// [SECTION] Input Mapping
	ImPlot.set_function("GetInputMap", []() { return &ImPlot::GetInputMap(); });
	ImPlot.set_function("MapInputDefault", [](std::optional<ImPlotInputMap*> dst) { ImPlot::MapInputDefault(dst.value_or(nullptr)); });
	ImPlot.set_function("MapInputReverse", [](std::optional<ImPlotInputMap*> dst) { ImPlot::MapInputReverse(dst.value_or(nullptr)); });

	// [SECTION] Miscellaneous
	ImPlot.set_function("ItemIcon", sol::overload(
		sol::resolve<void(const ImVec4&)>(&ImPlot::ItemIcon),
		sol::resolve<void(ImU32)>(&ImPlot::ItemIcon)
	));
	ImPlot.set_function("ColormapIcon", &ImPlot::ColormapIcon);
	ImPlot.set_function("GetPlotDrawList", &ImPlot::GetPlotDrawList);
	ImPlot.set_function("PushPlotClipRect", [](std::optional<float> expand) { ImPlot::PushPlotClipRect(expand.value_or(0)); });
	ImPlot.set_function("PopPlotClipRect", &ImPlot::PopPlotClipRect);
	ImPlot.set_function("ShowStyleSelector", &ImPlot::ShowStyleSelector);
	ImPlot.set_function("ShowcolormapSelector", &ImPlot::ShowColormapSelector);
	ImPlot.set_function("ShowInputMapSelector", &ImPlot::ShowInputMapSelector);
	ImPlot.set_function("ShowStyleEditor", [](std::optional<ImPlotStyle*> ref) { ImPlot::ShowStyleEditor(ref.value_or(nullptr)); });
	ImPlot.set_function("ShowUserGuide", &ImPlot::ShowUserGuide);
	ImPlot.set_function("ShowMetricsWindow", [](std::optional<bool> open) { bool open_ = open.value_or(true); ImPlot::ShowMetricsWindow(open.has_value() ? &open_ : nullptr); return open_; });
	ImPlot.set_function("GetVersion", []() { return IMPLOT_VERSION; });

	// [SECTION] Demo
	ImPlot.set_function("ShowDemoWindow", [](std::optional<bool> open) { bool open_ = open.value_or(true); ImPlot::ShowDemoWindow(open.has_value() ? &open_ : nullptr); return open_; });
	ImPlot.set_function("GetTime", []() { return (double)time(nullptr); });
	#pragma endregion

	return ImPlot;

}

} // namespace mq::lua::bindings
