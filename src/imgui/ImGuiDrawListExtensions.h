#pragma once

#include "imgui/imgui.h"

namespace mq {
namespace imgui {

// Gradient direction options
enum class ImGradientDir
{
	Horizontal,        // Left -> Right
	Vertical,          // Top -> Bottom
	DiagTopLeftBottomRight,
	DiagTopRightBottomLeft,
};

IMGUI_API void AddRectGradientFilled(ImDrawList& draw_list, const ImVec2& p_min, const ImVec2& p_max, ImU32 col_start, ImU32 col_end, ImGradientDir dir = ImGradientDir::Horizontal, float rounding = 0.0f, ImDrawFlags flags = 0);

}} // namespace mq::imgui
