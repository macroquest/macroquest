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

#include "imgui/imgui_internal.h"
#include "imgui/imanim/im_anim.h"
#include "sol/sol.hpp"

#include <optional>
#include <string>
#include <unordered_map>
#include <array>
#include <mutex>

#include "LuaImGui.h"
#include "LuaThread.h"

namespace mq::lua::bindings {

//============================================================================
// Callback trampolines
//============================================================================

static LuaImAnimState* GetLuaImAnimState()
{
	if (void* user_data = iam_context_get_user_data())
		return static_cast<LuaImAnimState*>(user_data);

	return nullptr;
}

// Custom ease adapters - read context/user_data to find the right Lua function
template <int Slot>
static float LuaEaseAdapter(float t)
{
	if (LuaImAnimState* state = GetLuaImAnimState())
	{
		if (state->ease_functions[Slot].valid())
		{
			sol::function_result result = state->ease_functions[Slot](t);
			return result.get<float>();
		}
	}

	return t;
}

using EaseAdapterFn = float(*)(float);

static constexpr EaseAdapterFn s_easeAdapters[16] =
{
	&LuaEaseAdapter<0>,  &LuaEaseAdapter<1>,  &LuaEaseAdapter<2>,  &LuaEaseAdapter<3>,
	&LuaEaseAdapter<4>,  &LuaEaseAdapter<5>,  &LuaEaseAdapter<6>,  &LuaEaseAdapter<7>,
	&LuaEaseAdapter<8>,  &LuaEaseAdapter<9>,  &LuaEaseAdapter<10>, &LuaEaseAdapter<11>,
	&LuaEaseAdapter<12>, &LuaEaseAdapter<13>, &LuaEaseAdapter<14>, &LuaEaseAdapter<15>,
};

template <typename T>
static T LuaResolverTrampoline(void* user)
{
	auto* fn = static_cast<sol::function*>(user);
	if (fn && fn->valid())
	{
		sol::function_result result = (*fn)();
		return result.get<T>();
	}

	return T();
}

// Clip/marker callback trampolines
static void LuaClipCallbackTrampoline(ImGuiID inst_id, void* user_data)
{
	auto* fn = static_cast<sol::function*>(user_data);
	if (fn && fn->valid())
	{
		(*fn)(inst_id);
	}
}

static void LuaMarkerCallbackTrampoline(ImGuiID inst_id, ImGuiID marker_id, float marker_time, void* user_data)
{
	auto* fn = static_cast<sol::function*>(user_data);
	if (fn && fn->valid())
	{
		(*fn)(inst_id, marker_id, marker_time);
	}
}

// Helper to extract optional bezier4 from Lua (table of 4 floats or nil)
static bool ExtractBezier4(const std::optional<sol::table>& tbl, float out[4])
{
	if (!tbl.has_value())
		return false;

	const sol::table& t = tbl.value();
	if (t.size() < 4)
		return false;

	for (int i = 0; i < 4; ++i)
		out[i] = t.get<float>(i + 1);
	return true;
}

static iam_spring_params IamSpringParamsFromTable(sol::table table)
{
	return iam_spring_params{
		.mass = table["mass"].get<float>(),
		.stiffness = table["stiffness"].get<float>(),
		.damping = table["damping"].get<float>(),
		.initial_velocity = table["initial_velocity"].get<float>()
	};
}

sol::table RegisterBindings_ImAnim(sol::this_state L)
{
	sol::state_view state{ L };

	sol::table ImAnim = state.create_table();

	std::shared_ptr<LuaThread> threadPtr = LuaThread::get_from(state);
	LuaImGuiProcessor* imguiProcessor = threadPtr->GetImGuiProcessor();

	// This will inform the lua imgui system that we want to have an iam_context for
	// this lua script.
	imguiProcessor->InitImAnimContext();

	// ========================================================================
	// Enums
	// ========================================================================

	state.new_enum("IamEaseType", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Linear"                       , iam_ease_linear },
		{ "InQuad"                       , iam_ease_in_quad },
		{ "OutQuad"                      , iam_ease_out_quad },
		{ "InOutQuad"                    , iam_ease_in_out_quad },
		{ "InCubic"                      , iam_ease_in_cubic },
		{ "OutCubic"                     , iam_ease_out_cubic },
		{ "InOutCubic"                   , iam_ease_in_out_cubic },
		{ "InQuart"                      , iam_ease_in_quart },
		{ "OutQuart"                     , iam_ease_out_quart },
		{ "InOutQuart"                   , iam_ease_in_out_quart },
		{ "InQuint"                      , iam_ease_in_quint },
		{ "OutQuint"                     , iam_ease_out_quint },
		{ "InOutQuint"                   , iam_ease_in_out_quint },
		{ "InSine"                       , iam_ease_in_sine },
		{ "OutSine"                      , iam_ease_out_sine },
		{ "InOutSine"                    , iam_ease_in_out_sine },
		{ "InExpo"                       , iam_ease_in_expo },
		{ "OutExpo"                      , iam_ease_out_expo },
		{ "InOutExpo"                    , iam_ease_in_out_expo },
		{ "InCirc"                       , iam_ease_in_circ },
		{ "OutCirc"                      , iam_ease_out_circ },
		{ "InOutCirc"                    , iam_ease_in_out_circ },
		{ "InBack"                       , iam_ease_in_back },
		{ "OutBack"                      , iam_ease_out_back },
		{ "InOutBack"                    , iam_ease_in_out_back },
		{ "InElastic"                    , iam_ease_in_elastic },
		{ "OutElastic"                   , iam_ease_out_elastic },
		{ "InOutElastic"                 , iam_ease_in_out_elastic },
		{ "InBounce"                     , iam_ease_in_bounce },
		{ "OutBounce"                    , iam_ease_out_bounce },
		{ "InOutBounce"                  , iam_ease_in_out_bounce },
		{ "Steps"                        , iam_ease_steps },
		{ "CubicBezier"                  , iam_ease_cubic_bezier },
		{ "Spring"                       , iam_ease_spring },
		{ "Custom"                       , iam_ease_custom },
	});

	state.new_enum("IamPolicy", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Crossfade"                    , iam_policy_crossfade },
		{ "Cut"                          , iam_policy_cut },
		{ "Queue"                        , iam_policy_queue },
	});

	state.new_enum("IamColorSpace", std::initializer_list<std::pair<std::string_view, int>>{
		{ "SRGB"                         , iam_col_srgb },
		{ "SRGBLinear"                   , iam_col_srgb_linear },
		{ "HSV"                          , iam_col_hsv },
		{ "OKLAB"                        , iam_col_oklab },
		{ "OKLCH"                        , iam_col_oklch },
	});

	state.new_enum("IamAnchorSpace", std::initializer_list<std::pair<std::string_view, int>>{
		{ "WindowContent"                , iam_anchor_window_content },
		{ "Window"                       , iam_anchor_window },
		{ "Viewport"                     , iam_anchor_viewport },
		{ "LastItem"                     , iam_anchor_last_item },
	});

	// ========================================================================
	// User Types
	// ========================================================================

	// iam_ease_desc
	state.new_usertype<iam_ease_desc>(
		"IamEaseDesc"                    , sol::call_constructor,
		                                   sol::constructors<iam_ease_desc()>(),
		"type"                           , &iam_ease_desc::type,
		"p0"                             , &iam_ease_desc::p0,
		"p1"                             , &iam_ease_desc::p1,
		"p2"                             , &iam_ease_desc::p2,
		"p3"                             , &iam_ease_desc::p3
	);

	// ========================================================================
	// Functions
	// ========================================================================

	// Custom easing functions
	ImAnim.set_function("RegisterCustomEase", [](int slot, sol::function fn) {
		if (slot < 0 || slot >= 16)
			return;

		LuaImAnimState* state = GetLuaImAnimState();

		state->ease_functions[slot] = fn;
		iam_register_custom_ease(slot, s_easeAdapters[slot]);
	});

	// Debug UI
	ImAnim.set_function("ShowUnifiedInspector", [](std::optional<bool> open)
	{
		bool open_ = open.value_or(true);
		iam_show_unified_inspector(open.has_value() ? &open_ : nullptr);
		return open_;
	});
	ImAnim.set_function("ShowDebugTimeline", &iam_show_debug_timeline);

	// Performance Profiler
	ImAnim.set_function("ProfilerIsEnabled", &iam_profiler_is_enabled);
	ImAnim.set_function("ProfilerBegin", &iam_profiler_begin);
	ImAnim.set_function("ProfilerEnd", &iam_profiler_end);

	// Drag Feedback - animated feedback for drag operations
	state.new_usertype<iam_drag_opts>(
		"IamDragOpts"                    , sol::call_constructor,
		                                   sol::constructors<iam_drag_opts()>(),
		"snap_grid"                      , &iam_drag_opts::snap_grid,
		"snap_duration"                  , &iam_drag_opts::snap_duration,
		"overshoot"                      , &iam_drag_opts::overshoot,
		"ease_type"                      , &iam_drag_opts::ease_type
	);

	state.new_usertype<iam_drag_feedback>(
		"IamDragFeedback"                , sol::no_constructor,
		"position"                       , sol::readonly(&iam_drag_feedback::position),
		"offset"                         , sol::readonly(&iam_drag_feedback::offset),
		"velocity"                       , sol::readonly(&iam_drag_feedback::velocity),
		"is_dragging"                    , sol::readonly(&iam_drag_feedback::is_dragging),
		"is_snapping"                    , sol::readonly(&iam_drag_feedback::is_snapping),
		"snap_progress"                  , sol::readonly(&iam_drag_feedback::snap_progress)
	);

	ImAnim.set_function("DragBegin", &iam_drag_begin);
	ImAnim.set_function("DragUpdate", &iam_drag_update);
	ImAnim.set_function("DragRelease", &iam_drag_release);
	ImAnim.set_function("DragCancel", &iam_drag_cancel);

	// Oscillators - continuous periodic animations
	state.new_enum("IamWaveType", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Sine"                         , iam_wave_sine },
		{ "Triangle"                     , iam_wave_triangle },
		{ "Sawtooth"                     , iam_wave_sawtooth },
		{ "Square"                       , iam_wave_square },
	});

	ImAnim.set_function("Oscillate", &iam_oscillate);
	ImAnim.set_function("OscillateInt", &iam_oscillate_int);
	ImAnim.set_function("OscillateVec2", &iam_oscillate_vec2);
	ImAnim.set_function("OscillateVec4", &iam_oscillate_vec4);
	ImAnim.set_function("OscillateColor", &iam_oscillate_color);

	// Shake/Wiggle - procedural noise animations
	ImAnim.set_function("Shake", &iam_shake);
	ImAnim.set_function("ShakeInt", &iam_shake_int);
	ImAnim.set_function("ShakeVec2", &iam_shake_vec2);
	ImAnim.set_function("ShakeVec4", &iam_shake_vec4);
	ImAnim.set_function("ShakeColor", &iam_shake_color);
	ImAnim.set_function("Wiggle", &iam_wiggle);
	ImAnim.set_function("WiggleInt", &iam_wiggle_int);
	ImAnim.set_function("WiggleVec2", &iam_wiggle_vec2);
	ImAnim.set_function("WiggleVec4", &iam_wiggle_vec4);
	ImAnim.set_function("WiggleColor", &iam_wiggle_color);
	ImAnim.set_function("TriggerShake", &iam_trigger_shake);

	// Easing evaluation
	ImAnim.set_function("EvalPreset", &iam_eval_preset);

	// Tween API - smoothly interpolate values over time
	ImAnim.set_function("TweenFloat", [](ImGuiID id, ImGuiID channel_id, float target, float dur, iam_ease_desc const& ez, int policy, float dt, std::optional<float> init_value) {
		return iam_tween_float(id, channel_id, target, dur, ez, policy, dt, init_value.value_or(0.0f));
	});
	ImAnim.set_function("TweenVec2", [](ImGuiID id, ImGuiID channel_id, ImVec2 target, float dur, iam_ease_desc const& ez, int policy, float dt, std::optional<ImVec2> init_value) {
		return iam_tween_vec2(id, channel_id, target, dur, ez, policy, dt, init_value.value_or(ImVec2(0, 0)));
	});
	ImAnim.set_function("TweenVec4", [](ImGuiID id, ImGuiID channel_id, ImVec4 target, float dur, iam_ease_desc const& ez, int policy, float dt, std::optional<ImVec4> init_value) {
		return iam_tween_vec4(id, channel_id, target, dur, ez, policy, dt, init_value.value_or(ImVec4(0, 0, 0, 0)));
	});
	ImAnim.set_function("TweenInt", [](ImGuiID id, ImGuiID channel_id, int target, float dur, iam_ease_desc const& ez, int policy, float dt, std::optional<int> init_value) {
		return iam_tween_int(id, channel_id, target, dur, ez, policy, dt, init_value.value_or(0));
	});
	ImAnim.set_function("TweenColor", [](ImGuiID id, ImGuiID channel_id, ImVec4 target_srgb, float dur, iam_ease_desc const& ez, int policy, int color_space, float dt, std::optional<ImVec4> init_value) {
		return iam_tween_color(id, channel_id, target_srgb, dur, ez, policy, color_space, dt, init_value.value_or(ImVec4(1, 1, 1, 1)));
	});

	// Resize-friendly helpers
	ImAnim.set_function("AnchorSize", &iam_anchor_size);

	// Relative target tweens (percent of anchor + pixel offset) - survive window resizes
	ImAnim.set_function("TweenFloatRel", &iam_tween_float_rel);
	ImAnim.set_function("TweenVec2Rel", &iam_tween_vec2_rel);
	ImAnim.set_function("TweenVec4Rel", &iam_tween_vec4_rel);
	ImAnim.set_function("TweenColorRel", &iam_tween_color_rel);

	// Resolved tweens - target computed dynamically by callback each frame
	ImAnim.set_function("TweenFloatResolved", [](ImGuiID id, ImGuiID channel_id, sol::function fn, float dur, iam_ease_desc const& ez, int policy, float dt) {
		return iam_tween_float_resolved(id, channel_id, LuaResolverTrampoline<float>, &fn, dur, ez, policy, dt);
	});
	ImAnim.set_function("TweenVec2Resolved", [](ImGuiID id, ImGuiID channel_id, sol::function fn, float dur, iam_ease_desc const& ez, int policy, float dt) {
		return iam_tween_vec2_resolved(id, channel_id, LuaResolverTrampoline<ImVec2>, &fn, dur, ez, policy, dt);
	});
	ImAnim.set_function("TweenVec4Resolved", [](ImGuiID id, ImGuiID channel_id, sol::function fn, float dur, iam_ease_desc const& ez, int policy, float dt) {
		return iam_tween_vec4_resolved(id, channel_id, LuaResolverTrampoline<ImVec4>, &fn, dur, ez, policy, dt);
	});
	ImAnim.set_function("TweenColorResolved", [](ImGuiID id, ImGuiID channel_id, sol::function fn, float dur, iam_ease_desc const& ez, int policy, int color_space, float dt) {
		return iam_tween_color_resolved(id, channel_id, LuaResolverTrampoline<ImVec4>, &fn, dur, ez, policy, color_space, dt);
	});
	ImAnim.set_function("TweenIntResolved", [](ImGuiID id, ImGuiID channel_id, sol::function fn, float dur, iam_ease_desc const& ez, int policy, float dt) {
		return iam_tween_int_resolved(id, channel_id, LuaResolverTrampoline<int>, &fn, dur, ez, policy, dt);
	});

	// Rebase functions - change target of in-progress animation without restarting
	ImAnim.set_function("RebaseFloat", &iam_rebase_float);
	ImAnim.set_function("RebaseVec2", &iam_rebase_vec2);
	ImAnim.set_function("RebaseVec4", &iam_rebase_vec4);
	ImAnim.set_function("RebaseColor", &iam_rebase_color);
	ImAnim.set_function("RebaseInt", &iam_rebase_int);

	// Color blending utility
	ImAnim.set_function("GetBlendedColor", &iam_get_blended_color);

	// Convenience shorthands for common easings
	ImAnim.set_function("EasePreset", &iam_ease_preset);
	ImAnim.set_function("EaseBezier", &iam_ease_bezier);
	ImAnim.set_function("EaseStepsDesc", &iam_ease_steps_desc);
	ImAnim.set_function("EaseBack", &iam_ease_back);
	ImAnim.set_function("EaseElastic", &iam_ease_elastic);
	ImAnim.set_function("EaseSpringDesc", &iam_ease_spring_desc);
	ImAnim.set_function("EaseCustomFn", &iam_ease_custom_fn);

	// Scroll animation - smooth scrolling for ImGui windows
	ImAnim.set_function("ScrollToY", [](float target_y, float duration, std::optional<iam_ease_desc> ez) {
		iam_scroll_to_y(target_y, duration, ez.value_or(iam_ease_preset(iam_ease_out_cubic)));
	});
	ImAnim.set_function("ScrollToX", [](float target_x, float duration, std::optional<iam_ease_desc> ez) {
		iam_scroll_to_x(target_x, duration, ez.value_or(iam_ease_preset(iam_ease_out_cubic)));
	});
	ImAnim.set_function("ScrollToTop", [](std::optional<float> duration, std::optional<iam_ease_desc> ez) {
		iam_scroll_to_top(duration.value_or(0.3f), ez.value_or(iam_ease_preset(iam_ease_out_cubic)));
	});
	ImAnim.set_function("ScrollToBottom", [](std::optional<float> duration, std::optional<iam_ease_desc> ez) {
		iam_scroll_to_bottom(duration.value_or(0.3f), ez.value_or(iam_ease_preset(iam_ease_out_cubic)));
	});

	// ----------------------------------------------------
	// Per-axis easing - different easing per component
	// ----------------------------------------------------

	// Per-axis easing descriptor (for vec2/vec4/color)
	state.new_usertype<iam_ease_per_axis>(
		"IamEasePerAxis"                 , sol::call_constructor,
		                                  sol::constructors<
		                                      iam_ease_per_axis(),
		                                      iam_ease_per_axis(iam_ease_desc),
		                                      iam_ease_per_axis(iam_ease_desc, iam_ease_desc),
		                                      iam_ease_per_axis(iam_ease_desc, iam_ease_desc, iam_ease_desc, iam_ease_desc)
		                                   >(),
		"x"                              , &iam_ease_per_axis::x,
		"y"                              , &iam_ease_per_axis::y,
		"z"                              , &iam_ease_per_axis::z,
		"w"                              , &iam_ease_per_axis::w
	);

	// Tween with per-axis easing - each component uses its own easing curve
	ImAnim.set_function("TweenVec2PerAxis", &iam_tween_vec2_per_axis);
	ImAnim.set_function("TweenVec4PerAxis", &iam_tween_vec4_per_axis);
	ImAnim.set_function("TweenColorPerAxis", &iam_tween_color_per_axis);

	// ----------------------------------------------------
	// Motion Paths - animate along curves and splines
	// ----------------------------------------------------

	// Path segment types
	state.new_enum("IamPathSegmentType", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Line"                         , iam_seg_line },
		{ "QuadraticBezier"              , iam_seg_quadratic_bezier },
		{ "CubicBezier"                  , iam_seg_cubic_bezier },
		{ "CatmullRom"                   , iam_seg_catmull_rom },
	});

	// Single-curve evaluation functions (stateless, for direct use)
	ImAnim.set_function("BezierQuadratic", &iam_bezier_quadratic);
	ImAnim.set_function("BezierCubic", &iam_bezier_cubic);
	ImAnim.set_function("CatmullRom", [](ImVec2 p0, ImVec2 p1, ImVec2 p2, ImVec2 p3, float t, std::optional<float> tension) {
		return iam_catmull_rom(p0, p1, p2, p3, t, tension.value_or(0.5f));
	});

	// Derivatives (for tangent/velocity)
	ImAnim.set_function("BezierQuadraticDeriv", &iam_bezier_quadratic_deriv);
	ImAnim.set_function("BezierCubicDeriv", &iam_bezier_cubic_deriv);
	ImAnim.set_function("CatmullRomDeriv", [](ImVec2 p0, ImVec2 p1, ImVec2 p2, ImVec2 p3, float t, std::optional<float> tension) {
		return iam_catmull_rom_deriv(p0, p1, p2, p3, t, tension.value_or(0.5f));
	});

	// iam_path - fluent API for building multi-segment motion paths
	state.new_usertype<iam_path>(
		"IamPath"                        , sol::no_constructor,
		"Begin"                          , &iam_path::begin,
		"LineTo"                         , &iam_path::line_to,
		"QuadraticTo"                    , &iam_path::quadratic_to,
		"CubicTo"                        , &iam_path::cubic_to,
		"CatmullTo"                      , [](iam_path& self, ImVec2 end, std::optional<float> tension) -> iam_path& { return self.catmull_to(end, tension.value_or(0.5f)); },
		"Close"                          , &iam_path::close,
		"End"                            , &iam_path::end,
		"Id"                             , &iam_path::id
	);

	// Query path info
	ImAnim.set_function("PathExists", &iam_path_exists);
	ImAnim.set_function("PathLength", &iam_path_length);
	ImAnim.set_function("PathEvaluate", &iam_path_evaluate);
	ImAnim.set_function("PathTangent", &iam_path_tangent);
	ImAnim.set_function("PathAngle", &iam_path_angle);

	// Tween along a path
	ImAnim.set_function("TweenPath", &iam_tween_path);
	ImAnim.set_function("TweenPathAngle", &iam_tween_path_angle);

	// ----------------------------------------------------
	// Arc-length parameterization (for constant-speed animation)
	// ----------------------------------------------------

	// Build arc-length lookup table for a path (call once per path, improves accuracy)
	ImAnim.set_function("PathBuildArcLut", [](ImGuiID path_id, std::optional<int> subdivisions) {
		iam_path_build_arc_lut(path_id, subdivisions.value_or(64));
	});
	ImAnim.set_function("PathHasArcLut", &iam_path_has_arc_lut);

	// Distance-based path evaluation (uses arc-length LUT for constant speed)
	ImAnim.set_function("PathDistanceToT", &iam_path_distance_to_t);
	ImAnim.set_function("PathEvaluateAtDistance", &iam_path_evaluate_at_distance);
	ImAnim.set_function("PathAngleAtDistance", &iam_path_angle_at_distance);
	ImAnim.set_function("PathTangentAtDistance", &iam_path_tangent_at_distance);

	// ----------------------------------------------------
	// Path Morphing - interpolate between two paths
	// ----------------------------------------------------

	// Morph options for path interpolation
	state.new_usertype<iam_morph_opts>(
		"IamMorphOpts"                   , sol::call_constructor,
		                                   sol::constructors<iam_morph_opts()>(),
		"samples"                        , &iam_morph_opts::samples,
		"match_endpoints"                , &iam_morph_opts::match_endpoints,
		"use_arc_length"                 , &iam_morph_opts::use_arc_length
	);

	ImAnim.set_function("PathMorph", [](ImGuiID path_a, ImGuiID path_b, float t, float blend, std::optional<iam_morph_opts> opts) {
		return iam_path_morph(path_a, path_b, t, blend, opts.value_or(iam_morph_opts()));
	});
	ImAnim.set_function("PathMorphTangent", [](ImGuiID path_a, ImGuiID path_b, float t, float blend, std::optional<iam_morph_opts> opts) {
		return iam_path_morph_tangent(path_a, path_b, t, blend, opts.value_or(iam_morph_opts()));
	});
	ImAnim.set_function("PathMorphAngle", [](ImGuiID path_a, ImGuiID path_b, float t, float blend, std::optional<iam_morph_opts> opts) {
		return iam_path_morph_angle(path_a, path_b, t, blend, opts.value_or(iam_morph_opts()));
	});

	ImAnim.set_function("TweenPathMorph", [](ImGuiID id, ImGuiID channel_id, ImGuiID path_a, ImGuiID path_b, float target_blend, float dur, iam_ease_desc const& path_ease, iam_ease_desc const& morph_ease, int policy, float dt, std::optional<iam_morph_opts> opts) {
		return iam_tween_path_morph(id, channel_id, path_a, path_b, target_blend, dur, path_ease, morph_ease, policy, dt, opts.value_or(iam_morph_opts()));
	});
	ImAnim.set_function("GetMorphBlend", &iam_get_morph_blend);

	// ----------------------------------------------------
	// Text along motion paths
	// ----------------------------------------------------

	state.new_enum("IamTextPathAlign", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Start", iam_text_align_start },
		{ "Center"                       , iam_text_align_center },
		{ "End"                          , iam_text_align_end },
	});

	// iam_text_path_opts
	state.new_usertype<iam_text_path_opts>(
		"IamTextPathOpts"                , sol::call_constructor,
		                                   sol::constructors<iam_text_path_opts()>(),
		"origin"                         , &iam_text_path_opts::origin,
		"offset"                         , &iam_text_path_opts::offset,
		"letter_spacing"                 , &iam_text_path_opts::letter_spacing,
		"align"                          , &iam_text_path_opts::align,
		"flip_y"                         , &iam_text_path_opts::flip_y,
		"color"                          , &iam_text_path_opts::color,
		"font_scale"                     , &iam_text_path_opts::font_scale
	);

	ImAnim.set_function("TextPath", [](ImGuiID path_id, const char* text, std::optional<iam_text_path_opts> opts) {
		iam_text_path(path_id, text, opts.value_or(iam_text_path_opts()));
	});
	ImAnim.set_function("TextPathAnimated", [](ImGuiID path_id, const char* text, float progress, std::optional<iam_text_path_opts> opts) {
		iam_text_path_animated(path_id, text, progress, opts.value_or(iam_text_path_opts()));
	});
	ImAnim.set_function("TextPathWidth", [](const char* text, std::optional<iam_text_path_opts> opts) {
		return iam_text_path_width(text, opts.value_or(iam_text_path_opts()));
	});

	// ----------------------------------------------------
	// Quad transform helpers (for advanced custom rendering)
	// ----------------------------------------------------

	ImAnim.set_function("TransformQuad", [](sol::table quad_table, ImVec2 center, float angle_rad, ImVec2 translation) {
		ImVec2 quad[4];
		for (int i = 0; i < 4; ++i)
			quad[i] = quad_table.get<ImVec2>(i + 1);
		iam_transform_quad(quad, center, angle_rad, translation);
		for (int i = 0; i < 4; ++i)
			quad_table[i + 1] = quad[i];
		return quad_table;
	});
	ImAnim.set_function("MakeGlyphQuad", [](sol::this_state L, ImVec2 pos, float angle_rad, float glyph_width, float glyph_height, std::optional<float> baseline_offset) {
		ImVec2 quad[4];
		iam_make_glyph_quad(quad, pos, angle_rad, glyph_width, glyph_height, baseline_offset.value_or(0.0f));
		sol::state_view sv(L);
		sol::table result = sv.create_table();
		for (int i = 0; i < 4; ++i)
			result[i + 1] = quad[i];
		return result;
	});

	// ----------------------------------------------------
	// Text Stagger - per-character animation effects
	// ----------------------------------------------------

	state.new_enum("IamTextStaggerEffect", std::initializer_list<std::pair<std::string_view, int>>{
		{ "None"                         , iam_text_fx_none },
		{ "Fade"                         , iam_text_fx_fade },
		{ "Scale"                        , iam_text_fx_scale },
		{ "SlideUp"                      , iam_text_fx_slide_up },
		{ "SlideDown"                    , iam_text_fx_slide_down },
		{ "SlideLeft"                    , iam_text_fx_slide_left },
		{ "SlideRight"                   , iam_text_fx_slide_right },
		{ "Rotate"                       , iam_text_fx_rotate },
		{ "Bounce"                       , iam_text_fx_bounce },
		{ "Wave"                         , iam_text_fx_wave },
		{ "Typewriter"                   , iam_text_fx_typewriter },
	});

		// iam_text_stagger_opts
	state.new_usertype<iam_text_stagger_opts>(
		"IamTextStaggerOpts"             , sol::call_constructor,
		                                   sol::constructors<iam_text_stagger_opts()>(),
		"pos"                            , &iam_text_stagger_opts::pos,
		"effect"                         , &iam_text_stagger_opts::effect,
		"char_delay"                     , &iam_text_stagger_opts::char_delay,
		"char_duration"                  , &iam_text_stagger_opts::char_duration,
		"effect_intensity"               , &iam_text_stagger_opts::effect_intensity,
		"ease"                           , &iam_text_stagger_opts::ease,
		"color"                          , &iam_text_stagger_opts::color,
		"font_scale"                     , &iam_text_stagger_opts::font_scale,
		"letter_spacing"                 , &iam_text_stagger_opts::letter_spacing
	);

	ImAnim.set_function("TextStagger", [](ImGuiID id, const char* text, float progress, std::optional<iam_text_stagger_opts> opts) {
		iam_text_stagger(id, text, progress, opts.value_or(iam_text_stagger_opts()));
	});
	ImAnim.set_function("TextStaggerWidth", [](const char* text, std::optional<iam_text_stagger_opts> opts) {
		return iam_text_stagger_width(text, opts.value_or(iam_text_stagger_opts()));
	});
	ImAnim.set_function("TextStaggerDuration", [](const char* text, std::optional<iam_text_stagger_opts> opts) {
		return iam_text_stagger_duration(text, opts.value_or(iam_text_stagger_opts()));
	});

	// ----------------------------------------------------
	// Noise Channels - Perlin/Simplex noise for organic movement
	// ----------------------------------------------------

	state.new_enum("IamNoiseType", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Perlin"                       , iam_noise_perlin },
		{ "Simplex"                      , iam_noise_simplex },
		{ "Value"                        , iam_noise_value },
		{ "Worley"                       , iam_noise_worley },
	});

	state.new_usertype<iam_noise_opts>(
		"IamNoiseOpts"                   , sol::call_constructor,
		                                   sol::constructors<iam_noise_opts()>(),
		"type"                           , &iam_noise_opts::type,
		"octaves"                        , &iam_noise_opts::octaves,
		"persistence"                    , &iam_noise_opts::persistence,
		"lacunarity"                     , &iam_noise_opts::lacunarity,
		"seed"                           , &iam_noise_opts::seed
	);

	// Sample noise at a point (returns value in [-1, 1])
	ImAnim.set_function("Noise2D", [](float x, float y, std::optional<iam_noise_opts> opts) {
		return iam_noise_2d(x, y, opts.value_or(iam_noise_opts()));
	});
	ImAnim.set_function("Noise3D", [](float x, float y, float z, std::optional<iam_noise_opts> opts) {
		return iam_noise_3d(x, y, z, opts.value_or(iam_noise_opts()));
	});

	// Animated noise channels - continuous noise that evolves over time
	ImAnim.set_function("NoiseChannelFloat", &iam_noise_channel_float);
	ImAnim.set_function("NoiseChannelVec2", &iam_noise_channel_vec2);
	ImAnim.set_function("NoiseChannelVec4", &iam_noise_channel_vec4);
	ImAnim.set_function("NoiseChannelColor", &iam_noise_channel_color);

	// Convenience: smooth random movement (like wiggle but using noise)
	ImAnim.set_function("SmoothNoiseFloat", &iam_smooth_noise_float);
	ImAnim.set_function("SmoothNoiseVec2", &iam_smooth_noise_vec2);
	ImAnim.set_function("SmoothNoiseVec4", &iam_smooth_noise_vec4);
	ImAnim.set_function("SmoothNoiseColor", &iam_smooth_noise_color);

	// ----------------------------------------------------
	// Style Interpolation - animate between ImGuiStyle themes
	// ----------------------------------------------------

	// Register a named style for interpolation
	ImAnim.set_function("StyleRegister", &iam_style_register);
	ImAnim.set_function("StyleRegisterCurrent", &iam_style_register_current);

	// Blend between two registered styles (result applied to ImGui::GetStyle())
	// Uses iam_color_space for color blending mode (iam_col_oklab recommended)
	ImAnim.set_function("StyleBlend", [](ImGuiID style_a, ImGuiID style_b, float t, std::optional<int> color_space) {
		iam_style_blend(style_a, style_b, t, color_space.value_or(iam_col_oklab));
	});

	// Tween between styles over time
	ImAnim.set_function("StyleTween", &iam_style_tween);

	// Get interpolated style without applying
	ImAnim.set_function("StyleBlendTo", [](ImGuiID style_a, ImGuiID style_b, float t, std::optional<int> color_space) {
		ImGuiStyle out_style;
		iam_style_blend_to(style_a, style_b, t, &out_style, color_space.value_or(iam_col_oklab));
		return out_style;
	});

	// Check if a style is registered
	ImAnim.set_function("StyleExists", &iam_style_exists);

	// Remove a registered style
	ImAnim.set_function("StyleUnregister", &iam_style_unregister);

	// ----------------------------------------------------
	// Gradient Interpolation - animate between color gradients
	// ----------------------------------------------------

	// iam_gradient
	state.new_usertype<iam_gradient>(
		"IamGradient"                    , sol::call_constructor,
		                                   sol::constructors<iam_gradient()>(),
		"Add"                            , sol::overload(
			[](iam_gradient& self, float position, ImVec4 color) -> iam_gradient& { return self.add(position, color); },
			[](iam_gradient& self, float position, ImU32 color) -> iam_gradient& { return self.add(position, color); }
		),
		"StopCount"                      , &iam_gradient::stop_count,
		"Sample"                         , [](iam_gradient& self, float t, std::optional<int> color_space) { return self.sample(t, color_space.value_or(iam_col_oklab)); },
		"Solid"                          , &iam_gradient::solid,
		"TwoColor"                       , &iam_gradient::two_color,
		"ThreeColor"                     , &iam_gradient::three_color
	);

	ImAnim.set_function("GradientLerp", [](iam_gradient const& a, iam_gradient const& b, float t, std::optional<int> color_space) {
		return iam_gradient_lerp(a, b, t, color_space.value_or(iam_col_oklab));
	});
	ImAnim.set_function("TweenGradient", &iam_tween_gradient);

	// ----------------------------------------------------
	// Transform Interpolation - animate 2D transforms
	// ----------------------------------------------------

	state.new_enum("IamRotationMode", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Shortest"                     , iam_rotation_shortest },
		{ "Longest"                      , iam_rotation_longest },
		{ "CW"                           , iam_rotation_cw },
		{ "CCW"                          , iam_rotation_ccw },
		{ "Direct"                       , iam_rotation_direct },
	});

	// iam_transform
	state.new_usertype<iam_transform>(
		"IamTransform"                   , sol::call_constructor,
		                                   sol::constructors<
		                                       iam_transform(),
		                                       iam_transform(ImVec2, float, ImVec2)
		                                   >(),
		"position"                       , &iam_transform::position,
		"scale"                          , &iam_transform::scale,
		"rotation"                       , &iam_transform::rotation,
		"Identity"                       , &iam_transform::identity,
		"Apply"                          , &iam_transform::apply,
		"Inverse"                        , &iam_transform::inverse,
		sol::meta_function::multiplication, &iam_transform::operator*
	);

	// Blend between two transforms with rotation interpolation
	ImAnim.set_function("TransformLerp", [](iam_transform const& a, iam_transform const& b, float t, std::optional<int> rotation_mode) {
		return iam_transform_lerp(a, b, t, rotation_mode.value_or(iam_rotation_shortest));
	});

	// Tween between transforms over time
	ImAnim.set_function("TweenTransform", &iam_tween_transform);

	// Decompose a 3x2 matrix into transform components
	ImAnim.set_function("TransformFromMatrix", &iam_transform_from_matrix);

	// Convert transform to 3x2 matrix (row-major: [m00 m01 tx; m10 m11 ty])
	ImAnim.set_function("TransformToMatrix", [](sol::this_state L, iam_transform const& t) {
		float m[6];
		iam_transform_to_matrix(t, m);
		sol::state_view sv(L);
		sol::table result = sv.create_table();
		for (int i = 0; i < 6; ++i)
			result[i + 1] = m[i];
		return result;
	});

	// ============================================================
	// CLIP-BASED ANIMATION SYSTEM
	// ============================================================

	// Direction for looping animations
	state.new_enum("IamDirection", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Normal"                       , iam_dir_normal },
		{ "Reverse"                      , iam_dir_reverse },
		{ "Alternate"                    , iam_dir_alternate },
	});

	// Channel types for keyframes
	state.new_enum("IamChannelType", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Float"                        , iam_chan_float },
		{ "Vec2"                         , iam_chan_vec2 },
		{ "Vec4"                         , iam_chan_vec4 },
		{ "Int"                          , iam_chan_int },
		{ "Color"                        , iam_chan_color },
		{ "FloatRel"                     , iam_chan_float_rel },
		{ "Vec2Rel"                      , iam_chan_vec2_rel },
		{ "Vec4Rel"                      , iam_chan_vec4_rel },
		{ "ColorRel"                     , iam_chan_color_rel },
	});

	// Result codes
	state.new_enum("IamResult", std::initializer_list<std::pair<std::string_view, int>>{
		{ "Ok"                           , iam_ok },
		{ "ErrNotFound"                  , iam_err_not_found },
		{ "ErrBadArg"                    , iam_err_bad_arg },
		{ "ErrNoMem"                     , iam_err_no_mem },
	});

	// Spring parameters for physics-based animation
	state.new_usertype<iam_spring_params>(
		"IamSpringParams"                , sol::call_constructor,
		sol::factories(
			&IamSpringParamsFromTable,
			[]{ return iam_spring_params(); },
			[](float mass, float stiffness, float damping, float initial_velocity) { return iam_spring_params{ mass, stiffness, damping, initial_velocity }; }
		),
		"mass"                           , &iam_spring_params::mass,
		"stiffness"                      , &iam_spring_params::stiffness,
		"damping"                        , &iam_spring_params::damping,
		"initial_velocity"               , &iam_spring_params::initial_velocity
	);

	// ----------------------------------------------------
	// Repeat with Variation - per-loop parameter changes
	// ----------------------------------------------------

	// Variation modes for repeat animations
	state.new_enum("IamVariationMode", std::initializer_list<std::pair<std::string_view, int>>{
		{ "None"                         , iam_var_none },
		{ "Increment"                    , iam_var_increment },
		{ "Decrement"                    , iam_var_decrement },
		{ "Multiply"                     , iam_var_multiply },
		{ "Random"                       , iam_var_random },
		{ "RandomAbs"                    , iam_var_random_abs },
		{ "Pingpong"                     , iam_var_pingpong },
		{ "Callback"                     , iam_var_callback },
	});

	// Float variation
	state.new_usertype<iam_variation_float>(
		"IamVariationFloat"              , sol::call_constructor,
		                                   sol::constructors<iam_variation_float()>(),
		"mode"                           , &iam_variation_float::mode,
		"amount"                         , &iam_variation_float::amount,
		"min_clamp"                      , &iam_variation_float::min_clamp,
		"max_clamp"                      , &iam_variation_float::max_clamp,
		"seed"                           , &iam_variation_float::seed
	);

	// Int variation
	state.new_usertype<iam_variation_int>(
		"IamVariationInt"                , sol::call_constructor,
		                                   sol::constructors<iam_variation_int()>(),
		"mode"                           , &iam_variation_int::mode,
		"amount"                         , &iam_variation_int::amount,
		"min_clamp"                      , &iam_variation_int::min_clamp,
		"max_clamp"                      , &iam_variation_int::max_clamp,
		"seed"                           , &iam_variation_int::seed
	);

	// Vec2 variation (global mode or per-axis)
	state.new_usertype<iam_variation_vec2>(
		"IamVariationVec2"               , sol::call_constructor,
		                                   sol::constructors<iam_variation_vec2()>(),
		"mode"                           , &iam_variation_vec2::mode,
		"amount"                         , &iam_variation_vec2::amount,
		"min_clamp"                      , &iam_variation_vec2::min_clamp,
		"max_clamp"                      , &iam_variation_vec2::max_clamp,
		"seed"                           , &iam_variation_vec2::seed,
		"x"                              , &iam_variation_vec2::x,
		"y"                              , &iam_variation_vec2::y
	);

	// Vec4 variation (global mode or per-axis)
	state.new_usertype<iam_variation_vec4>(
		"IamVariationVec4"               , sol::call_constructor,
		                                   sol::constructors<iam_variation_vec4()>(),
		"mode"                           , &iam_variation_vec4::mode,
		"amount"                         , &iam_variation_vec4::amount,
		"min_clamp"                      , &iam_variation_vec4::min_clamp,
		"max_clamp"                      , &iam_variation_vec4::max_clamp,
		"seed"                           , &iam_variation_vec4::seed,
		"x"                              , &iam_variation_vec4::x,
		"y"                              , &iam_variation_vec4::y,
		"z"                              , &iam_variation_vec4::z,
		"w"                              , &iam_variation_vec4::w
	);

	// Color variation (global mode or per-channel)
	state.new_usertype<iam_variation_color>(
		"IamVariationColor"              , sol::call_constructor,
		                                   sol::constructors<iam_variation_color()>(),
		"mode"                           , &iam_variation_color::mode,
		"amount"                         , &iam_variation_color::amount,
		"min_clamp"                      , &iam_variation_color::min_clamp,
		"max_clamp"                      , &iam_variation_color::max_clamp,
		"color_space"                    , &iam_variation_color::color_space,
		"seed"                           , &iam_variation_color::seed,
		"r"                              , &iam_variation_color::r,
		"g"                              , &iam_variation_color::g,
		"b"                              , &iam_variation_color::b,
		"a"                              , &iam_variation_color::a
	);

	// ----------------------------------------------------
	// Variation helper functions (C11-style inline)
	// ----------------------------------------------------

	// Float variation helpers
	ImAnim.set_function("VarfNone", &iam_varf_none);
	ImAnim.set_function("VarfInc", &iam_varf_inc);
	ImAnim.set_function("VarfDec", &iam_varf_dec);
	ImAnim.set_function("VarfMul", &iam_varf_mul);
	ImAnim.set_function("VarfRand", &iam_varf_rand);
	ImAnim.set_function("VarfRandAbs", &iam_varf_rand_abs);
	ImAnim.set_function("VarfPingpong", &iam_varf_pingpong);
	ImAnim.set_function("VarfClamp", &iam_varf_clamp);
	ImAnim.set_function("VarfSeed", &iam_varf_seed);

	// Int variation helpers
	ImAnim.set_function("VariNone", &iam_vari_none);
	ImAnim.set_function("VariInc", &iam_vari_inc);
	ImAnim.set_function("VariDec", &iam_vari_dec);
	ImAnim.set_function("VariRand", &iam_vari_rand);
	ImAnim.set_function("VariClamp", &iam_vari_clamp);
	ImAnim.set_function("VariSeed", &iam_vari_seed);

	// Vec2 variation helpers (global)
	ImAnim.set_function("Varv2None", &iam_varv2_none);
	ImAnim.set_function("Varv2Inc", &iam_varv2_inc);
	ImAnim.set_function("Varv2Dec", &iam_varv2_dec);
	ImAnim.set_function("Varv2Mul", &iam_varv2_mul);
	ImAnim.set_function("Varv2Rand", &iam_varv2_rand);

	// Vec2 per-axis helper
	ImAnim.set_function("Varv2Axis", &iam_varv2_axis);
	ImAnim.set_function("Varv2Clamp", &iam_varv2_clamp);
	ImAnim.set_function("Varv2Seed", &iam_varv2_seed);

	// Vec4 variation helpers (global)
	ImAnim.set_function("Varv4None", &iam_varv4_none);
	ImAnim.set_function("Varv4Inc", &iam_varv4_inc);
	ImAnim.set_function("Varv4Dec", &iam_varv4_dec);
	ImAnim.set_function("Varv4Mul", &iam_varv4_mul);
	ImAnim.set_function("Varv4Rand", &iam_varv4_rand);

	// Vec4 per-axis helper
	ImAnim.set_function("Varv4Axis", &iam_varv4_axis);
	ImAnim.set_function("Varv4Clamp", &iam_varv4_clamp);
	ImAnim.set_function("Varv4Seed", &iam_varv4_seed);

	// Color variation helpers (global)
	ImAnim.set_function("VarcNone", &iam_varc_none);
	ImAnim.set_function("VarcInc", &iam_varc_inc);
	ImAnim.set_function("VarcDec", &iam_varc_dec);
	ImAnim.set_function("VarcMul", &iam_varc_mul);
	ImAnim.set_function("VarcRand", &iam_varc_rand);

	// Color per-channel helper
	ImAnim.set_function("VarcChannel", &iam_varc_channel);
	ImAnim.set_function("VarcSpace", &iam_varc_space);
	ImAnim.set_function("VarcClamp", &iam_varc_clamp);
	ImAnim.set_function("VarcSeed", &iam_varc_seed);

	// ----------------------------------------------------
	// iam_clip - fluent API for authoring animations
	// ----------------------------------------------------

	state.new_usertype<iam_clip>(
		"IamClip", sol::no_constructor,

		// Start building a new clip with the given ID
		"Begin", [](ImGuiID clip_id) -> iam_clip { return iam_clip::begin(clip_id); },

		// Keyframes
		"KeyFloat", [](iam_clip& self, ImGuiID channel, float time, float value, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_float(channel, time, value, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyVec2", [](iam_clip& self, ImGuiID channel, float time, ImVec2 value, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_vec2(channel, time, value, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyVec4", [](iam_clip& self, ImGuiID channel, float time, ImVec4 value, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_vec4(channel, time, value, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyInt", [](iam_clip& self, ImGuiID channel, float time, int value, std::optional<int> ease_type) -> iam_clip& {
			return self.key_int(channel, time, value, ease_type.value_or(iam_ease_linear));
		},
		"KeyColor", [](iam_clip& self, ImGuiID channel, float time, ImVec4 value, std::optional<int> color_space, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_color(channel, time, value, color_space.value_or(iam_col_oklab), ease_type.value_or(iam_ease_linear), bp);
		},

		// Keyframes with repeat variation (value changes per loop iteration)
		"KeyFloatVar", [](iam_clip& self, ImGuiID channel, float time, float value, iam_variation_float const& var, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_float_var(channel, time, value, var, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyVec2Var", [](iam_clip& self, ImGuiID channel, float time, ImVec2 value, iam_variation_vec2 const& var, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_vec2_var(channel, time, value, var, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyVec4Var", [](iam_clip& self, ImGuiID channel, float time, ImVec4 value, iam_variation_vec4 const& var, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_vec4_var(channel, time, value, var, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyIntVar", [](iam_clip& self, ImGuiID channel, float time, int value, iam_variation_int const& var, std::optional<int> ease_type) -> iam_clip& {
			return self.key_int_var(channel, time, value, var, ease_type.value_or(iam_ease_linear));
		},
		"KeyColorVar", [](iam_clip& self, ImGuiID channel, float time, ImVec4 value, iam_variation_color const& var, std::optional<int> color_space, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_color_var(channel, time, value, var, color_space.value_or(iam_col_oklab), ease_type.value_or(iam_ease_linear), bp);
		},

		// Spring-based keyframe (float only)
		"KeyFloatSpring", &iam_clip::key_float_spring,

		// Anchor-relative keyframes (values resolved relative to window/viewport at get time)
		"KeyFloatRel", [](iam_clip& self, ImGuiID channel, float time, float percent, float px_bias, int anchor_space, int axis, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_float_rel(channel, time, percent, px_bias, anchor_space, axis, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyVec2Rel", [](iam_clip& self, ImGuiID channel, float time, ImVec2 percent, ImVec2 px_bias, int anchor_space, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_vec2_rel(channel, time, percent, px_bias, anchor_space, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyVec4Rel", [](iam_clip& self, ImGuiID channel, float time, ImVec4 percent, ImVec4 px_bias, int anchor_space, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_vec4_rel(channel, time, percent, px_bias, anchor_space, ease_type.value_or(iam_ease_linear), bp);
		},
		"KeyColorRel", [](iam_clip& self, ImGuiID channel, float time, ImVec4 percent, ImVec4 px_bias, int color_space, int anchor_space, std::optional<int> ease_type, std::optional<sol::table> bezier4) -> iam_clip& {
			float b[4]; float* bp = ExtractBezier4(bezier4, b) ? b : nullptr;
			return self.key_color_rel(channel, time, percent, px_bias, color_space, anchor_space, ease_type.value_or(iam_ease_linear), bp);
		},

		// Timeline grouping - sequential and parallel keyframe blocks
		"SeqBegin", &iam_clip::seq_begin,
		"SeqEnd", &iam_clip::seq_end,
		"ParBegin", &iam_clip::par_begin,
		"ParEnd", &iam_clip::par_end,

		// Timeline markers - callbacks at specific times during playback
		"Marker", sol::overload(
			[](iam_clip& self, float time, ImGuiID marker_id, sol::function cb) -> iam_clip&
			{
				LuaImAnimState* state = GetLuaImAnimState();

				auto [iter, _] = state->marker_callbacks.insert_or_assign(LuaImAnimState::MarkerCallbackKey{ self.id(), marker_id }, cb);
				return self.marker(time, marker_id, LuaMarkerCallbackTrampoline, &iter->second);
			},
			[](iam_clip& self, float time, sol::function cb) -> iam_clip&
			{
				LuaImAnimState* state = GetLuaImAnimState();

				ImGuiID marker_id = ImHashData(&(++state->marker_counter), sizeof(state->marker_counter), self.id());
				auto [iter, _] = state->marker_callbacks.insert_or_assign({ self.id(), marker_id }, cb);
				return self.marker(time, LuaMarkerCallbackTrampoline, &iter->second);
			}
		),

		// Clip options
		"SetLoop", [](iam_clip& self, bool loop, std::optional<int> direction, std::optional<int> loop_count) -> iam_clip& {
			return self.set_loop(loop, direction.value_or(iam_dir_normal), loop_count.value_or(-1));
		},
		"SetDelay", & iam_clip::set_delay,
		"SetStagger", [](iam_clip& self, int count, float each_delay, std::optional<float> from_center_bias) -> iam_clip& {
			return self.set_stagger(count, each_delay, from_center_bias.value_or(0.0f));
		},

		// Timing variation per loop iteration
		"SetDurationVar", &iam_clip::set_duration_var,
		"SetDelayVar", &iam_clip::set_delay_var,
		"SetTimescaleVar", &iam_clip::set_timescale_var,

		// Callbacks
		"OnBegin", [](iam_clip& self, sol::function cb) -> iam_clip&
		{
			LuaImAnimState* state = GetLuaImAnimState();

			auto [iter, _] = state->clip_callbacks.insert_or_assign(LuaImAnimState::ClipCallbackKey{ self.id(), LuaImAnimState::CB_Begin }, cb);
			return self.on_begin(LuaClipCallbackTrampoline, &iter->second);
		},
		"OnUpdate", [](iam_clip& self, sol::function cb) -> iam_clip& {
			LuaImAnimState* state = GetLuaImAnimState();

			auto [iter, _] = state->clip_callbacks.insert_or_assign(LuaImAnimState::ClipCallbackKey{ self.id(), LuaImAnimState::CB_Update }, cb);
			return self.on_update(LuaClipCallbackTrampoline, &iter->second);
		},
		"OnComplete", [](iam_clip& self, sol::function cb) -> iam_clip& {
			LuaImAnimState* state = GetLuaImAnimState();

			auto [iter, _] = state->clip_callbacks.insert_or_assign(LuaImAnimState::ClipCallbackKey{ self.id(), LuaImAnimState::CB_Complete }, cb);
			return self.on_complete(LuaClipCallbackTrampoline, &iter->second);
		},

		// Finalize the clip
		"End", &iam_clip::end,

		// Get the clip ID
		"Id", &iam_clip::id
	);

	// iam_instance
	state.new_usertype<iam_instance>(
		"IamInstance"                    , sol::constructors<iam_instance(), iam_instance(ImGuiID)>(),
		"Pause"                          , &iam_instance::pause,
		"Resume"                         , &iam_instance::resume,
		"Stop"                           , &iam_instance::stop,
		"Destroy"                        , &iam_instance::destroy,
		"Seek"                           , &iam_instance::seek,
		"SetTimeScale"                   , &iam_instance::set_time_scale,
		"SetWeight"                      , &iam_instance::set_weight,
		"Then"                           , sol::overload(
		                                   sol::resolve<iam_instance&(ImGuiID)>(&iam_instance::then),
		                                   sol::resolve<iam_instance&(ImGuiID, ImGuiID)>(&iam_instance::then)
		                                 ),
		"ThenDelay"                      , &iam_instance::then_delay,
		"Time"                           , &iam_instance::time,
		"Duration"                       , &iam_instance::duration,
		"IsPlaying"                      , &iam_instance::is_playing,
		"IsPaused"                       , &iam_instance::is_paused,
		"GetFloat", [](iam_instance& self, ImGuiID channel) -> std::tuple<float, bool> {
			float v = 0; bool ok = self.get_float(channel, &v); return { v, ok };
		},
		"GetVec2", [](iam_instance& self, ImGuiID channel) -> std::tuple<ImVec2, bool> {
			ImVec2 v(0, 0); bool ok = self.get_vec2(channel, &v); return { v, ok };
		},
		"GetVec4", [](iam_instance& self, ImGuiID channel) -> std::tuple<ImVec4, bool> {
			ImVec4 v(0, 0, 0, 0); bool ok = self.get_vec4(channel, &v); return { v, ok };
		},
		"GetInt", [](iam_instance& self, ImGuiID channel) -> std::tuple<int, bool> {
			int v = 0; bool ok = self.get_int(channel, &v); return { v, ok };
		},
		"GetColor", [](iam_instance& self, ImGuiID channel, std::optional<int> color_space) -> std::tuple<ImVec4, bool> {
			ImVec4 v(1, 1, 1, 1); bool ok = self.get_color(channel, &v, color_space.value_or(iam_col_oklab)); return { v, ok };
		},
		"Valid"                          , &iam_instance::valid,
		"Id"                             , &iam_instance::id
	);

	// ----------------------------------------------------
	// Clip System API
	// ----------------------------------------------------

	// Initialize/shutdown (optional - auto-init on first use)
	ImAnim.set_function("ClipInit", [](std::optional<int> initial_clip_cap, std::optional<int> initial_inst_cap) {
		iam_clip_init(initial_clip_cap.value_or(256), initial_inst_cap.value_or(4096));
	});
	ImAnim.set_function("ClipShutdown", &iam_clip_shutdown);

	// Garbage collection for instances
	ImAnim.set_function("ClipGC", [](std::optional<int> max_age_frames) {
		iam_clip_gc(max_age_frames.value_or(600));
	});

	// Play a clip on an instance (creates or reuses instance)
	ImAnim.set_function("Play", &iam_play);

	// Get an existing instance (returns invalid iam_instance if not found)
	ImAnim.set_function("GetInstance", &iam_get_instance);

	// Query clip info
	ImAnim.set_function("ClipDuration", &iam_clip_duration);
	ImAnim.set_function("ClipExists", &iam_clip_exists);

	// Stagger helpers - compute delay for indexed instances
	ImAnim.set_function("StaggerDelay", &iam_stagger_delay);
	ImAnim.set_function("PlayStagger", &iam_play_stagger);

	// Layering support - blend multiple animation instances
	ImAnim.set_function("LayerBegin", &iam_layer_begin);
	ImAnim.set_function("LayerAdd", &iam_layer_add);
	ImAnim.set_function("LayerEnd", &iam_layer_end);
	ImAnim.set_function("GetBlendedFloat", [](ImGuiID instance_id, ImGuiID channel) -> std::tuple<bool, float> {
		float v = 0; bool ok = iam_get_blended_float(instance_id, channel, &v); return { ok, v };
	});
	ImAnim.set_function("GetBlendedVec2", [](ImGuiID instance_id, ImGuiID channel) -> std::tuple<bool, ImVec2> {
		ImVec2 v(0, 0); bool ok = iam_get_blended_vec2(instance_id, channel, &v); return { ok, v };
	});
	ImAnim.set_function("GetBlendedVec4", [](ImGuiID instance_id, ImGuiID channel) -> std::tuple<bool, ImVec4> {
		ImVec4 v(0, 0, 0, 0); bool ok = iam_get_blended_vec4(instance_id, channel, &v); return { ok, v };
	});
	ImAnim.set_function("GetBlendedInt", [](ImGuiID instance_id, ImGuiID channel) -> std::tuple<bool, int> {
		int v = 0; bool ok = iam_get_blended_int(instance_id, channel, &v); return { ok, v };
	});

	// ========================================================================
	// Constants
	// ========================================================================

	ImAnim.set("VERSION", IMANIM_VERSION);
	ImAnim.set("VERSION_NUM", IMANIM_VERSION_NUM);

	return ImAnim;
}

} // namespace mq::lua::bindings
