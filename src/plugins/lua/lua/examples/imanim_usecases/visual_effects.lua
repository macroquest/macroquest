local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 18: Gradient Background Animation
-- ============================================================
local function ShowUsecase_GradientAnimation()
    imgui.TextWrapped("Animated gradient backgrounds that shift colors smoothly.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    if not ShowUsecase_GradientAnimation_time then ShowUsecase_GradientAnimation_time = 0.0 end
    ShowUsecase_GradientAnimation_time = ShowUsecase_GradientAnimation_time + dt * 0.5

    local cp = imgui.GetCursorScreenPosVec()
    local avail = imgui.GetContentRegionAvailVec()
    local pos = ImVec2(cp.x, cp.y)
    local size = ImVec2(avail.x, 120)

    local gradient_time = ShowUsecase_GradientAnimation_time

    local hue1 = (gradient_time * 0.1) % 1.0
    local hue2 = (gradient_time * 0.1 + 0.3) % 1.0
    local hue3 = (gradient_time * 0.1 + 0.6) % 1.0

    local function HueToColor(h, c, l)
        local r = 0.5 + 0.5 * math.cos((h + 0.0 / 3.0) * 6.28318)
        local g = 0.5 + 0.5 * math.cos((h + 1.0 / 3.0) * 6.28318)
        local b = 0.5 + 0.5 * math.cos((h + 2.0 / 3.0) * 6.28318)
        r = l + (r - 0.5) * c
        g = l + (g - 0.5) * c
        b = l + (b - 0.5) * c
        return IM_COL32(math.floor(r * 255), math.floor(g * 255), math.floor(b * 255), 255)
    end

    local col1 = HueToColor(hue1, 0.6, 0.3)
    local col2 = HueToColor(hue2, 0.6, 0.25)
    local col3 = HueToColor(hue3, 0.6, 0.35)

    local segments = 20
    local segment_width = size.x / segments
    local function BlendColors(a, b, t)
        local ra = bit32.band(a, 0xFF)
        local ga = bit32.band(bit32.rshift(a, 8), 0xFF)
        local ba = bit32.band(bit32.rshift(a, 16), 0xFF)
        local rb = bit32.band(b, 0xFF)
        local gb = bit32.band(bit32.rshift(b, 8), 0xFF)
        local bb = bit32.band(bit32.rshift(b, 16), 0xFF)
        local r = math.floor(ra + (rb - ra) * t)
        local g = math.floor(ga + (gb - ga) * t)
        local bch = math.floor(ba + (bb - ba) * t)
        return IM_COL32(r, g, bch, 255)
    end

    for i = 0, segments - 1 do
        local t1 = i / segments
        local t2 = (i + 1) / segments
        local wave = math.sin(t1 * 3.14159 * 2.0 + gradient_time * 2.0) * 0.5 + 0.5
        local left_col = BlendColors(BlendColors(col1, col2, t1), col3, wave)
        local right_col = BlendColors(BlendColors(col1, col2, t2), col3, wave)
        dl:AddRectFilledMultiColor(ImVec2(pos.x + i * segment_width, pos.y), ImVec2(pos.x + (i + 1) * segment_width, pos.y + size.y), left_col, right_col, right_col, left_col)
    end

    local text = "Animated Gradient"
    local text_size = imgui.CalcTextSizeVec(text)
    dl:AddText(ImVec2(pos.x + (size.x - text_size.x) * 0.5, pos.y + (size.y - text_size.y) * 0.5), IM_COL32(255, 255, 255, 200), text)

    imgui.Dummy(size)
end

-- ============================================================
-- USECASE 15: Ripple Effect (Material Design)
-- ============================================================
local ShowUsecase_RippleEffect_state = {
    ripple_origin = ImVec2(0, 0),
    ripple_time = -1.0,
    ripple_active = false
}

local function ShowUsecase_RippleEffect()
    local state = ShowUsecase_RippleEffect_state
    imgui.TextWrapped("Material Design-style ripple effect on click.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    local cp = imgui.GetCursorScreenPosVec()
    local pos = ImVec2(cp.x, cp.y)
    local btn_size = ImVec2(200, 50)

    -- Button background
    dl:AddRectFilled(pos, ImVec2(pos.x + btn_size.x, pos.y + btn_size.y), IM_COL32(91, 194, 231, 255), 8.0)

    -- Invisible button for interaction
    imgui.SetCursorScreenPos(pos.x, pos.y)
    if imgui.InvisibleButton("##ripple_btn", btn_size) then
        state.ripple_origin = imgui.GetMousePosVec()
        state.ripple_time = 0.0
        state.ripple_active = true
    end
    local hovered = imgui.IsItemHovered()

    -- Update ripple
    if state.ripple_active then
        state.ripple_time = state.ripple_time + dt

        -- Calculate max radius (corner to corner)
        local max_dist = 0.0
        local corners = {
            ImVec2(pos.x, pos.y),
            ImVec2(pos.x + btn_size.x, pos.y),
            ImVec2(pos.x + btn_size.x, pos.y + btn_size.y),
            ImVec2(pos.x, pos.y + btn_size.y),
        }
        for i = 1, #corners do
            local dx = corners[i].x - state.ripple_origin.x
            local dy = corners[i].y - state.ripple_origin.y
            local d = math.sqrt(dx * dx + dy * dy)
            if d > max_dist then max_dist = d end
        end

        local duration = 0.6
        local progress = state.ripple_time / duration

        if progress < 1.0 then
            local ease_progress = iam.EvalPreset(iam.EasePreset(IamEaseType.EaseOutCubic), progress)
            local radius = max_dist * ease_progress
            local alpha = 0.3 * (1.0 - progress)

            dl:PushClipRect(pos, ImVec2(pos.x + btn_size.x, pos.y + btn_size.y), true)
            dl:AddCircleFilled(state.ripple_origin, radius, IM_COL32(255, 255, 255, math.floor(alpha * 255)))
            dl:PopClipRect()
        else
            state.ripple_active = false
        end
    end

    -- Hover highlight
    if hovered and not state.ripple_active then
        dl:AddRectFilled(pos, ImVec2(pos.x + btn_size.x, pos.y + btn_size.y), IM_COL32(255, 255, 255, 20), 8.0)
    end

    -- Text
    local label = "Ripple"
    local text_size = imgui.CalcTextSizeVec(label)
    dl:AddText(ImVec2(pos.x + (btn_size.x - text_size.x) * 0.5, pos.y + (btn_size.y - text_size.y) * 0.5), common.IM_COL32_WHITE, label)

    imgui.SetCursorScreenPos(pos.x, pos.y + btn_size.y + 16)
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- 34. Shake Animation
-- Error feedback shake effect for form validation
-- ============================================================
local ShowUsecase_ShakeAnimation_state = {
    is_shaking = false,
    shake_time = 0.0,
    input_text = "",
}

local function ShowUsecase_ShakeAnimation()
    local state = ShowUsecase_ShakeAnimation_state
    imgui.TextWrapped("Click 'Submit' with empty input to see shake animation:")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetStyle().FontScaleMain

    if state.is_shaking then
        state.shake_time = state.shake_time - dt
        if state.shake_time <= 0 then
            state.is_shaking = false
            state.shake_time = 0
        end
    end

    local shake_offset = 0.0
    if state.is_shaking then
        local shake_freq = 25.0
        local shake_decay = state.shake_time / 0.4
        shake_offset = math.sin(state.shake_time * shake_freq) * 8.0 * scale * shake_decay
    end

    local pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(300, 120)

    -- Background
    dl:AddRectFilled(pos, ImVec2(pos.x + canvas_size.x, pos.y + canvas_size.y), IM_COL32(30, 35, 45, 255), 8.0)

    -- Input box (visual)
    local input_y = pos.y + 24 * scale
    local input_width = 200 * scale
    local input_height = 32 * scale
    local input_min = ImVec2(pos.x + 16 * scale + shake_offset, input_y)
    local input_max = ImVec2(input_min.x + input_width, input_y + input_height)

    local input_bg = state.is_shaking and IM_COL32(80, 40, 40, 255) or IM_COL32(45, 50, 60, 255)
    local input_border = state.is_shaking and IM_COL32(220, 80, 80, 255) or IM_COL32(70, 75, 90, 255)

    dl:AddRectFilled(input_min, input_max, input_bg, 4.0)
    dl:AddRect(input_min, input_max, input_border, 4.0)

    imgui.PushItemWidth(input_width - 16 * scale)
    imgui.PushStyleColor(ImGuiCol.FrameBg, IM_COL32(0, 0, 0, 0))
    imgui.PushStyleColor(ImGuiCol.Border, IM_COL32(0, 0, 0, 0))
    imgui.SetCursorScreenPos(ImVec2(input_min.x + 8 * scale, input_y + (input_height - imgui.GetFontSize()) * 0.5))
    state.input_text = imgui.InputText("##shake_input", state.input_text)
    imgui.PopStyleColor(2)
    imgui.PopItemWidth()

    -- Placeholder
    if state.input_text == "" then
        dl:AddText(ImVec2(input_min.x + 8 * scale, input_y + (input_height - imgui.GetFontSize()) * 0.5), IM_COL32(100, 100, 110, 255), "Enter your name...")
    end

    -- Submit button
    local btn_min = ImVec2(pos.x + 16 * scale + shake_offset, input_y + input_height + 12 * scale)
    local btn_max = ImVec2(btn_min.x + 80 * scale, btn_min.y + 28 * scale)
    dl:AddRectFilled(btn_min, btn_max, IM_COL32(76, 175, 80, 255), 4.0)
    local btn_text_size = imgui.CalcTextSizeVec("Submit")
    dl:AddText(ImVec2(btn_min.x + (80 * scale - btn_text_size.x) * 0.5, btn_min.y + (28 * scale - btn_text_size.y) * 0.5), IM_COL32(255, 255, 255, 255), "Submit")

    imgui.SetCursorScreenPos(btn_min.x, btn_min.y)
    if imgui.InvisibleButton("##submit", ImVec2(80 * scale, 28 * scale)) then
        if state.input_text == "" then
            state.is_shaking = true
            state.shake_time = 0.4
        end
    end

    if state.is_shaking then
        dl:AddText(ImVec2(btn_max.x + 12 * scale, btn_min.y + (28 * scale - imgui.GetFontSize()) * 0.5), IM_COL32(220, 80, 80, 255), "Required field!")
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + canvas_size.y + 8)
    imgui.Dummy(ImVec2(canvas_size.x, 80 * scale))
end

-- ============================================================
-- USECASE 14: Avatar Stack with Hover Expansion
-- ============================================================
local function ShowUsecase_AvatarStack()
    imgui.TextWrapped("Stacked avatars that expand on hover to reveal all members.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    if not ShowUsecase_AvatarStack_state then
        ShowUsecase_AvatarStack_state = { stack_hovered = false, id = ImHashStr("avatar_stack") }
    end
    local state = ShowUsecase_AvatarStack_state

    local pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 80)

    -- Background
    dl:AddRectFilled(pos, ImVec2(pos.x + canvas_size.x, pos.y + canvas_size.y), IM_COL32(25, 27, 35, 255), 4.0)

    local avatar_count = 5
    local avatar_colors = {
        IM_COL32(91, 194, 231, 255), IM_COL32(204, 120, 88, 255), IM_COL32(130, 200, 130, 255), IM_COL32(200, 180, 100, 255), IM_COL32(180, 130, 200, 255)
    }
    local initials = { "JD", "AS", "MK", "RB", "TW" }

    local avatar_radius = 20.0
    local collapsed_overlap = 28.0
    local expanded_spacing = avatar_radius * 2.2

    local stack_width_collapsed = avatar_radius * 2 + (avatar_count - 1) * (avatar_radius * 2 - collapsed_overlap)
    local stack_width_expanded = avatar_count * expanded_spacing

    local stack_pos = ImVec2(pos.x + 20.0, pos.y + canvas_size.y * 0.5)

    imgui.SetCursorScreenPos(stack_pos.x - avatar_radius, stack_pos.y - avatar_radius)
    imgui.InvisibleButton("##avatar_stack", ImVec2(stack_width_expanded, avatar_radius * 2))
    state.stack_hovered = imgui.IsItemHovered()

    local target_expand = state.stack_hovered and 1.0 or 0.0
    local expand = iam.TweenFloat(state.id, ImHashStr("expand"), target_expand, 0.3, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    for i = avatar_count, 1, -1 do
        local idx = i - 1
        local collapsed_x = stack_pos.x + idx * (avatar_radius * 2 - collapsed_overlap)
        local expanded_x = stack_pos.x + idx * expanded_spacing
        local x = collapsed_x + (expanded_x - collapsed_x) * expand

        local av_id = state.id + i
        local target_lift = 0.0
        if expand > 0.5 then
            local dx = imgui.GetMousePosVec().x - x
            local dy = imgui.GetMousePosVec().y - stack_pos.y
            if dx * dx + dy * dy < avatar_radius * avatar_radius * 1.5 then target_lift = -8.0 end
        end

        local lift = iam.TweenFloat(av_id, ImHashStr("lift"), target_lift, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
        local target_scale = (target_lift < 0) and 1.15 or 1.0
        local scale = iam.TweenFloat(av_id, ImHashStr("scale"), target_scale, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        local av_center = ImVec2(x, stack_pos.y + lift)

        dl:AddCircleFilled(ImVec2(av_center.x + 2, av_center.y + 3), avatar_radius * scale, IM_COL32(0, 0, 0, 30))
        dl:AddCircleFilled(av_center, avatar_radius * scale, avatar_colors[i])
        dl:AddCircle(av_center, avatar_radius * scale, IM_COL32(255, 255, 255, 50), 0, 2.0)

        local text_size = imgui.CalcTextSizeVec(initials[i])
        dl:AddText(ImVec2(av_center.x - text_size.x * 0.5, av_center.y - text_size.y * 0.5), common.IM_COL32_WHITE, initials[i])
    end

    if expand < 0.5 then
        local badge_alpha = 1.0 - expand * 2.0
        local badge_x = stack_pos.x + stack_width_collapsed + 10.0
        dl:AddText(ImVec2(badge_x, stack_pos.y - imgui.GetTextLineHeight() * 0.5), IM_COL32(140, 140, 150, math.floor(255 * badge_alpha)), "+5")
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + canvas_size.y + 8)
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- USECASE: Particle Burst
-- ============================================================
local ShowUsecase_ParticleBurst_state = { burst_time = -1.0, burst_pos = ImVec2(0, 0) }

local function ShowUsecase_ParticleBurst()
    local state = ShowUsecase_ParticleBurst_state
    imgui.TextWrapped("Particle burst effect triggered on click.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 120 * scale)
    local dl = imgui.GetWindowDrawList()

    dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), IM_COL32(30, 35, 45, 255), 6 * scale)

    if state.burst_time < 0 then
        local hint = "Click anywhere!"
        local hint_size = imgui.CalcTextSizeVec(hint)
        dl:AddText(ImVec2(canvas_pos.x + (canvas_size.x - hint_size.x) * 0.5, canvas_pos.y + (canvas_size.y - hint_size.y) * 0.5), IM_COL32(150, 155, 165, 255), hint)
    end

    local mouse = imgui.GetMousePosVec()
    if imgui.IsMouseClicked(0) and mouse.x >= canvas_pos.x and mouse.x <= canvas_pos.x + canvas_size.x and mouse.y >= canvas_pos.y and mouse.y <= canvas_pos.y + canvas_size.y then
        state.burst_time = 0.0
        state.burst_pos = mouse
    end

    local num_particles = 16
    local burst_duration = 1.0
    if state.burst_time >= 0 then
        state.burst_time = state.burst_time + dt
        local t = state.burst_time / burst_duration
        if t > 1.0 then
            state.burst_time = -1.0
        else
            for i = 0, num_particles - 1 do
                local angle = i / num_particles * 6.28318
                local speed = 80.0 + (i % 3) * 30.0
                local size = 4.0 + (i % 4) * 2.0

                local eased_t = iam.EvalPreset(iam.EasePreset(IamEaseType.EaseOutExpo), t)
                local dist = speed * eased_t * scale

                local p = ImVec2(
                    state.burst_pos.x + math.cos(angle) * dist,
                    state.burst_pos.y + math.sin(angle) * dist + t * t * 50 * scale
                )

                local alpha = 1.0 - t
                local particle_size = size * scale * (1.0 - t * 0.5)

                local colors = {
                    IM_COL32(255, 100, 100, math.floor(alpha * 255)),
                    IM_COL32(100, 255, 100, math.floor(alpha * 255)),
                    IM_COL32(100, 100, 255, math.floor(alpha * 255)),
                    IM_COL32(255, 255, 100, math.floor(alpha * 255))
                }

                dl:AddCircleFilled(p, particle_size, colors[(i % 4) + 1])
            end
        end
    end

    imgui.Dummy(canvas_size)
end

-- ============================================================
-- USECASE: Glowing Border
-- ============================================================
local function ShowUsecase_GlowingBorder()
    imgui.TextWrapped("Animated glowing border effect for highlighting elements.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain

    if not ShowUsecase_GlowingBorder_time then ShowUsecase_GlowingBorder_time = 0.0 end
    ShowUsecase_GlowingBorder_time = ShowUsecase_GlowingBorder_time + dt

    local glow_time = ShowUsecase_GlowingBorder_time

    local pos = imgui.GetCursorScreenPosVec()
    local dl = imgui.GetWindowDrawList()
    local box_size = ImVec2(200 * scale, 80 * scale)

    local pulse = (math.sin(glow_time * 3.0) + 1.0) * 0.5
    local glow_alpha = 0.3 + pulse * 0.4
    local glow_size = 8 * scale + pulse * 4 * scale

    for i = 3, 0, -1 do
        local layer_size = glow_size * (1.0 + i * 0.3)
        local layer_alpha = glow_alpha * (1.0 - i * 0.25)
        dl:AddRect(ImVec2(pos.x - layer_size, pos.y - layer_size), ImVec2(pos.x + box_size.x + layer_size, pos.y + box_size.y + layer_size), IM_COL32(100, 180, 255, math.floor(layer_alpha * 255)), 12 * scale + i * 2 * scale, 0, 2.0 + i)
    end

    dl:AddRectFilled(pos, ImVec2(pos.x + box_size.x, pos.y + box_size.y), IM_COL32(40, 45, 55, 255), 8 * scale)
    dl:AddRect(pos, ImVec2(pos.x + box_size.x, pos.y + box_size.y), IM_COL32(100, 180, 255, 255), 8 * scale, 0, 2.0)

    local text = "Featured Item"
    local text_size = imgui.CalcTextSizeVec(text)
    dl:AddText(ImVec2(pos.x + (box_size.x - text_size.x) * 0.5, pos.y + (box_size.y - text_size.y) * 0.5), IM_COL32(255, 255, 255, 255), text)

    imgui.Dummy(ImVec2(box_size.x, box_size.y + 20 * scale))
end

-- ============================================================
-- USECASE: Pulse Ring
-- ============================================================
local pulse_ring_state = {
    pulse_time = 0.0,
}

local function ShowUsecase_PulseRing()
    local state = pulse_ring_state

    imgui.TextWrapped("Pulsating ring effect for attention/notification.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    state.pulse_time = state.pulse_time + dt

    local cp = imgui.GetCursorScreenPosVec()
    local center = ImVec2(cp.x + 50 * scale, cp.y + 50 * scale)

    -- Multiple expanding rings
    for i = 1, 3 do
        local ring_time = math.fmod(state.pulse_time + i * 0.5, 1.5)
        local ring_radius = 15 * scale + ring_time * 30 * scale
        local ring_alpha = 1.0 - (ring_time / 1.5)

        dl:AddCircle(center, ring_radius, IM_COL32(100, 150, 255, math.floor(ring_alpha * 200)), 0, 2 * scale)
    end

    -- Center dot
    dl:AddCircleFilled(center, 12 * scale, IM_COL32(100, 150, 255, 255))

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + 110 * scale))
end

-- ============================================================
-- USECASE: Morphing Shape
-- ============================================================
local morphing_state = {
    is_circle = true,
    morph_c_id = ImHashStr("morph_c"),
    mc_id = ImHashStr("mc"),
}

local function ShowUsecase_MorphingShape()
    local state = morphing_state

    imgui.TextWrapped("Shape morphing between circle and square.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local cp = imgui.GetCursorScreenPosVec()
    local center = ImVec2(cp.x + 60 * scale, cp.y + 60 * scale)
    local size = 40 * scale

    -- Morph animation (corner radius)
    local corner = iam.TweenFloat(state.morph_c_id, state.mc_id,
        state.is_circle and size or 8 * scale, 0.4,
        iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    dl:AddRectFilled(ImVec2(center.x - size, center.y - size),
        ImVec2(center.x + size, center.y + size),
        IM_COL32(70, 130, 180, 255), corner)

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + 130 * scale))
    if imgui.Button(state.is_circle and "To Square" or "To Circle") then
        state.is_circle = not state.is_circle
    end
end

-- ============================================================
-- USECASE: Bouncing Dots
-- ============================================================
local bouncing_state = {
    bounce_time = 0.0,
}

local function ShowUsecase_BouncingDots()
    local state = bouncing_state

    imgui.TextWrapped("Bouncing dots loading animation.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    state.bounce_time = state.bounce_time + dt * 3.0

    local cp = imgui.GetCursorScreenPosVec()

    for i = 1, 3 do
        local phase = state.bounce_time + i * 0.5
        local bounce = math.abs(math.sin(phase)) * 20 * scale

        local dot_pos = ImVec2(cp.x + 30 * scale + i * 25 * scale, cp.y + 40 * scale - bounce)
        dl:AddCircleFilled(dot_pos, 8 * scale, IM_COL32(100, 150, 255, 255))
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + 60 * scale))
end

-- ============================================================
-- USECASE: Confetti Burst
-- ============================================================
local confetti_state = {
    burst_time = -1.0,
}

local function ShowUsecase_ConfettiBurst()
    local state = confetti_state

    imgui.TextWrapped("Celebration confetti burst animation.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    if state.burst_time >= 0 then state.burst_time = state.burst_time + dt end
    if state.burst_time > 2.0 then state.burst_time = -1.0 end

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(200 * scale, 100 * scale)
    local center = ImVec2(cp.x + cs.x * 0.5, cp.y + cs.y * 0.5)

    -- Container
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y),
        IM_COL32(30, 35, 45, 255), 8 * scale)

    if state.burst_time >= 0 and state.burst_time < 2.0 then
        -- Draw confetti particles
        for i = 1, 20 do
            local angle = i / 20.0 * 6.28318
            local speed = 50 + (i % 5) * 30
            local x = center.x + math.cos(angle) * speed * state.burst_time * scale
            local y = center.y + math.sin(angle) * speed * state.burst_time * scale + state.burst_time * state.burst_time * 100 * scale
            local alpha = 1.0 - state.burst_time * 0.5

            local colors = {
                IM_COL32(255, 100, 100, math.floor(alpha * 255)),
                IM_COL32(100, 255, 100, math.floor(alpha * 255)),
                IM_COL32(100, 100, 255, math.floor(alpha * 255)),
                IM_COL32(255, 255, 100, math.floor(alpha * 255))
            }

            dl:AddRectFilled(ImVec2(x - 3 * scale, y - 3 * scale),
                ImVec2(x + 3 * scale, y + 3 * scale), colors[i % 4 + 1])
        end
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 10 * scale))
    if imgui.Button("Celebrate!") then state.burst_time = 0.0 end
end

local function RunVisualEffectsDemo()
    -- ========================================
    -- VISUAL EFFECTS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Visual Effects") then
        imgui.Indent()
        common.USECASE_ITEM('Gradient Animation', ShowUsecase_GradientAnimation)
        common.USECASE_ITEM('Ripple Effect', ShowUsecase_RippleEffect)
        common.USECASE_ITEM('Shake Animation (Form Validation)', ShowUsecase_ShakeAnimation)
        common.USECASE_ITEM('Avatar Stack', ShowUsecase_AvatarStack)
        common.USECASE_ITEM('Particle Burst', ShowUsecase_ParticleBurst)
        common.USECASE_ITEM('Glowing Border', ShowUsecase_GlowingBorder)
        common.USECASE_ITEM('Pulse Ring', ShowUsecase_PulseRing)
        common.USECASE_ITEM('Morphing Shape', ShowUsecase_MorphingShape)
        common.USECASE_ITEM('Bouncing Dots', ShowUsecase_BouncingDots)
        common.USECASE_ITEM('Confetti Burst', ShowUsecase_ConfettiBurst)
        imgui.Unindent()
    end
end

return RunVisualEffectsDemo
