
#pragma once

#include "im_anim.h"
#include "imgui/imgui_internal.h"

namespace iam_scroll_detail {

struct scroll_anim {
	ImGuiID window_id;
	float start_x, start_y;
	float target_x, target_y;
	float duration;
	float elapsed;
	iam_ease_desc ease;
	bool active_x, active_y;
	unsigned last_frame;
};

} // namespace iam_scroll_detail

namespace iam_clip_detail {

struct iam_clip_system {
	ImVector<iam_clip_data>		clips;
	ImVector<iam_instance_data>	instances;
	ImGuiStorage				clip_map;		// clip_id -> index+1
	ImGuiStorage				inst_map;		// inst_id -> index+1
	unsigned					frame_counter;
	bool						initialized;

	iam_clip_system() : frame_counter(0), initialized(false) {}
};

} // namespace iam_clip_detail

// ----------------------------------------------------
// Internal: parameterized easing LUT cache (ImPool)
// ----------------------------------------------------
namespace iam_detail {

struct ease_lut {
	iam_ease_desc		desc;
	ImVector<float>		samples;
	int					count;
	ease_lut() { count = 0; }
};

struct ease_lut_pool {
	ImPool<ease_lut>	pool;
	ImGuiStorage		map;
	int					sample_count;
	ease_lut_pool() { sample_count = 129; }

	static ImGuiID hash_desc(iam_ease_desc const& d) { return ImHashData(&d, sizeof(d)); }

	static float bounce_out(float t);
	static float elastic_core(float t, float a, float p);
	static float back_core(float t, float s);
	static float cubic_bezier_y(float x, float x1, float y1, float x2, float y2);
	static float spring_unit(float u, float mass, float k, float c, float v0);

	void build_lut(ease_lut& lut);
	float eval_lut(iam_ease_desc const& d, float t);
};

// ----------------------------------------------------
// Channel interpolation traits - define how each type lerps
// ----------------------------------------------------
template<typename T> struct chan_traits;

template<> struct chan_traits<float> {
	static float default_value() { return 0.0f; }
	static float lerp(float a, float b, float k) { return a + (b - a) * k; }
};

template<> struct chan_traits<ImVec2> {
	static ImVec2 default_value() { return ImVec2(0, 0); }
	static ImVec2 lerp(ImVec2 a, ImVec2 b, float k) {
		return ImVec2(a.x + (b.x - a.x) * k, a.y + (b.y - a.y) * k);
	}
};

template<> struct chan_traits<ImVec4> {
	static ImVec4 default_value() { return ImVec4(1, 1, 1, 1); }
	static ImVec4 lerp(ImVec4 a, ImVec4 b, float k) {
		return ImVec4(a.x + (b.x - a.x) * k, a.y + (b.y - a.y) * k,
			a.z + (b.z - a.z) * k, a.w + (b.w - a.w) * k);
	}
};

template<> struct chan_traits<int> {
	static int default_value() { return 0; }
	static int lerp(int a, int b, float k) {
		float v = (float)a + ((float)b - (float)a) * k;
		return (int)ImFloor(v + 0.5f);
	}
};

// ----------------------------------------------------
// Base channel template - shared logic for all channel types
// ----------------------------------------------------
template<typename T>
struct base_chan {
	T		current, start, target;
	float	dur, t;  // t is cached progress for backward compatibility
	double	start_time;
	iam_ease_desc ez;
	int		policy;
	unsigned last_seen_frame;
	unsigned has_pending;
	unsigned sleeping;
	T		pending_target;

	base_chan();

	void set(T trg, float d, iam_ease_desc const& e, int pol);
	float progress();
	T evaluate();

	void tick(float) { evaluate(); }
};

// Concrete channel types using the base template
using float_chan = base_chan<float>;
using vec2_chan = base_chan<ImVec2>;
using vec4_chan = base_chan<ImVec4>;
using int_chan = base_chan<int>;

// Color channel needs special handling for color space blending
struct color_chan {
	ImVec4	current, start, target;
	float	dur, t;
	double	start_time;
	iam_ease_desc ez;
	int		policy;
	int		space;
	unsigned last_seen_frame;
	unsigned sleeping;

	color_chan();

	void set(ImVec4 trg, float d, iam_ease_desc const& e, int pol, int sp);
	float progress();
	ImVec4 evaluate();

	void tick(float) { evaluate(); }
};

// Per-type pools
template<typename T>
struct pool_t {
	ImPool<T> pool;
	unsigned frame = 0;
	void begin() { ++frame; }
	T* get(ImGuiID key) { T* c = pool.GetOrAddByKey(key); c->last_seen_frame = frame; return c; }
	T* try_get(ImGuiID key) { T* c = pool.GetByKey(key); if (c) c->last_seen_frame = frame; return c; }  // Returns nullptr if not found
	bool exists(ImGuiID key) { return pool.GetByKey(key) != nullptr; }
	void gc(unsigned max_age) {
		for (int i = 0; i < pool.GetMapSize(); ++i) {
			if (T* c = pool.TryGetMapData(i)) {
				if (frame - c->last_seen_frame > max_age) {
					ImGuiID k = pool.Map.Data[i].key;
					pool.Remove(k, pool.GetIndex(c));
				}
			}
		}
	}
};

} // namespace iam_detail

// iam_instance_data definition
struct iam_instance_data {
	ImGuiID		inst_id;
	ImGuiID		clip_id;		// Store clip ID instead of pointer to avoid invalidation
	float		time;
	float		time_scale;
	float		weight;
	float		delay_left;
	bool		playing;
	bool		paused;
	bool		begin_called;	// iam_track whether on_begin has been called
	int			dir_sign;
	int			loops_left;
	unsigned	last_seen_frame;

	// Per-channel current values (cached after evaluation)
	ImGuiStorage	values_float;
	ImGuiStorage	values_int;
	// vec2/vec4/color stored as float pairs/quads in separate arrays
	struct vec2_entry { ImGuiID ch; ImVec2 v; };
	struct vec4_entry { ImGuiID ch; ImVec4 v; };
	struct color_entry { ImGuiID ch; ImVec4 v; int color_space; };
	// Relative types need 8 floats: percent(4) + px_bias(4)
	struct vec4_rel_entry { ImGuiID ch; ImVec4 percent; ImVec4 px_bias; };
	struct color_rel_entry { ImGuiID ch; ImVec4 percent; ImVec4 px_bias; int color_space; };
	ImVector<vec2_entry> values_vec2;
	ImVector<vec4_entry> values_vec4;
	ImVector<color_entry> values_color;
	ImVector<vec4_rel_entry> values_vec4_rel;
	ImVector<color_rel_entry> values_color_rel;

	// Layered blending output (written by iam_layer_end)
	ImGuiStorage	blended_float;
	ImGuiStorage	blended_int;
	ImVector<vec2_entry> blended_vec2;
	ImVector<vec4_entry> blended_vec4;
	ImVector<color_entry> blended_color;
	bool			has_blended;	// true if blended values are valid

	// Marker tracking - bitset for triggered markers (reset on loop)
	ImVector<bool>	markers_triggered;
	float			prev_time;		// Previous time for marker crossing detection

	// Animation chaining - next clip to play when this one completes
	ImGuiID		chain_next_clip_id;		// Clip to play next (0 = none)
	ImGuiID		chain_next_inst_id;		// Instance ID for next clip (0 = auto-generate)
	float		chain_delay;			// Delay before starting chained clip

	// Loop variation tracking
	int			current_loop;			// Current loop iteration (0-based), used for variation calculations
	unsigned int var_rng_state;			// RNG state for deterministic variation random

	iam_instance_data() : inst_id(0), clip_id(0), time(0), time_scale(1.0f), weight(1.0f),
		delay_left(0), playing(false), paused(false), begin_called(false), dir_sign(1), loops_left(0), last_seen_frame(0),
		has_blended(false), prev_time(0), chain_next_clip_id(0), chain_next_inst_id(0), chain_delay(0),
		current_loop(0), var_rng_state(12345) {}
};

namespace iam_osc_detail {

struct osc_state {
	float time;
	unsigned last_frame;
	osc_state() : time(0), last_frame(0) {}
};

} // namespace iam_osc_detail

namespace iam_shake_detail {

struct shake_state {
	float time_since_trigger;
	float noise_time;
	unsigned last_frame;
	bool triggered;
	// Simple noise state
	float noise_val[4];
	int noise_idx;
	shake_state() : time_since_trigger(0), noise_time(0), last_frame(0), triggered(false), noise_idx(0) {
		for (int i = 0; i < 4; i++) noise_val[i] = 0;
	}
};

} // namespace iam_shake_detail

namespace iam_detail {

// Layering support - blends multiple instance outputs into one
struct iam_layer_state {
	ImGuiID target_id;
	float total_weight;
	// Accumulated weighted values
	ImGuiStorage acc_float;
	ImGuiStorage acc_int;
	ImVector<iam_instance_data::vec2_entry> acc_vec2;
	ImVector<iam_instance_data::vec4_entry> acc_vec4;
	// Weight sums per channel (for normalization)
	ImGuiStorage weight_float;
	ImGuiStorage weight_int;
	ImVector<iam_instance_data::vec2_entry> weight_vec2;  // stores weight in v.x
	ImVector<iam_instance_data::vec4_entry> weight_vec4;  // stores weight in v.x
};

} // namespace iam_detail

namespace iam_path_detail {

// Path segment storage
struct path_segment {
	int type;           // iam_path_segment_type
	ImVec2 p0, p1, p2, p3;  // Control points (usage depends on type)
	float tension;      // For catmull-rom
	float length;       // Approximate segment length

	ImVec2 evaluate(float t) const;

	ImVec2 derivative(float t) const;
};

// Arc-length LUT entry
struct arc_lut_entry {
	float distance;   // Cumulative arc-length distance
	float t;          // Global t parameter [0,1]
};

// Path data storage
struct path_data {
	ImVector<path_segment> segments;
	ImVec2 start_point;
	float total_length;
	bool closed;

	// Arc-length LUT for constant-speed evaluation
	ImVector<arc_lut_entry> arc_lut;
	bool has_arc_lut;

	path_data() : start_point(0, 0), total_length(0), closed(false), has_arc_lut(false) {}

	void compute_lengths() ;

	// Find segment and local t for global t in [0,1]
	void find_segment(float global_t, int* out_seg_idx, float* out_local_t) const;

	ImVec2 evaluate(float t) const;

	ImVec2 derivative(float t) const;

	// Build arc-length lookup table for constant-speed evaluation
	void build_arc_lut(int subdivisions);

	// Convert arc-length distance to t parameter using LUT (binary search)
	float distance_to_t(float distance) const;

	// Evaluate at arc-length distance
	ImVec2 evaluate_at_distance(float distance) const;

	// Get angle at arc-length distance
	float angle_at_distance(float distance) const;

	// Get tangent at arc-length distance
	ImVec2 tangent_at_distance(float distance) const;
};

} // namespace iam_detail

namespace iam_morph_detail {

struct morph_state {
	float blend;         // Current blend value (0 = path_a, 1 = path_b)
	float path_t;        // Current position along morphed path
	ImGuiID last_frame;
};

} // namespace iam_morph_detail

namespace iam_noise_detail {

struct noise_state {
	float time;
	ImGuiID last_frame;
};

} // iam_noise_detail

namespace iam_style_detail {

struct registered_style {
	ImGuiStyle style;
	bool valid;
};

// Style tween state
struct style_tween_state {
	ImGuiID target_style;
	ImGuiID source_style;
	float t;
	float duration;
	iam_ease_desc ease;
	int color_space;
	bool active;
};

} // namespace iam_style_detail

namespace iam_gradient_detail {

struct gradient_chan {
	iam_gradient current, start, target;
	float dur, t;  // t is cached progress for backward compatibility
	double start_time;
	iam_ease_desc ez;
	int policy;
	int color_space;
	unsigned last_seen_frame;
	unsigned sleeping;

	gradient_chan() {
		dur = 1e-6f; t = 1.0f; start_time = 0;
		ez = { iam_ease_out_cubic, 0, 0, 0, 0 };
		policy = iam_policy_crossfade;
		color_space = iam_col_oklab;
		last_seen_frame = 0;
		sleeping = 1;
	}

	void set(iam_gradient const& trg, float d, iam_ease_desc const& e, int pol, int cs);
	float progress();
	iam_gradient evaluate();

	void tick(float) { evaluate(); }
};

} // namespace iam_gradient_detial

namespace iam_transform_detail {

struct transform_chan {
	iam_transform current, start, target;
	float dur, t;  // t is cached progress for backward compatibility
	double start_time;
	iam_ease_desc ez;
	int policy;
	int rotation_mode;
	unsigned last_seen_frame;
	unsigned sleeping;

	transform_chan() : current(), start(), target() {
		dur = 1e-6f; t = 1.0f; start_time = 0;
		ez = { iam_ease_out_cubic, 0, 0, 0, 0 };
		policy = iam_policy_crossfade;
		rotation_mode = iam_rotation_shortest;
		last_seen_frame = 0;
		sleeping = 1;
	}

	void set(iam_transform const& trg, float d, iam_ease_desc const& e, int pol, int rot_mode);
	float progress();
	iam_transform evaluate();

	void tick(float) { evaluate(); }
};

} // namespace iam_transform_detail

namespace iam_detail {

struct drag_state {
	ImVec2 start_pos;
	ImVec2 current_pos;
	ImVec2 prev_pos;
	ImVec2 velocity;
	bool is_dragging;
	bool is_snapping;
	float snap_progress;
	ImVec2 snap_start;
	ImVec2 snap_target;
	float snap_duration;
	int snap_ease;
};

} // namespace iam_detail

struct iam_context {
	void* user_data = nullptr;

	ImVector<iam_scroll_detail::scroll_anim> scroll_anims;
	iam_clip_detail::iam_clip_system clip_sys;
	iam_ease_fn custom_ease[16] = {};
	iam_detail::ease_lut_pool ease_lut_pool;
	iam_detail::pool_t<iam_detail::float_chan> g_float;
	iam_detail::pool_t<iam_detail::vec2_chan> g_vec2;
	iam_detail::pool_t<iam_detail::vec4_chan> g_vec4;
	iam_detail::pool_t<iam_detail::int_chan> g_int;
	iam_detail::pool_t<iam_detail::color_chan> g_color;
	iam_detail::iam_layer_state layer_state = { 0, 0 };
	ImGuiStorage osc_map;
	ImGuiStorage shake_map;

	// Global path storage
	ImPool<iam_path_detail::path_data> paths;
	ImGuiStorage path_map;

	// Currently building path
	iam_path_detail::path_data* building_path = nullptr;
	ImGuiID building_path_id = 0;
	ImVec2 current_point;
	ImVector<ImVec2> catmull_points;  // For collecting catmull-rom points

	// State for morph tweens
	ImPool<iam_morph_detail::morph_state> morph_states;

	// Noise channel state
	ImPool<iam_noise_detail::noise_state> noise_states;

	ImPool<iam_style_detail::registered_style> styles;
	ImPool<iam_style_detail::style_tween_state> style_tweens;

	ImPool<iam_gradient_detail::gradient_chan> gradient_pool;
	uint32_t gradient_frame = 0;

	ImPool<iam_transform_detail::transform_chan> transform_pool;
	uint32_t transform_frame = 0;

	ImGuiStorage drag_states;
};
