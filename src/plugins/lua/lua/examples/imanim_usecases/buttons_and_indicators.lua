local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

local color_id = ImHashStr('color')
local border_id = ImHashStr('border')
local fill_id = ImHashStr('fill')
local rotation_id = ImHashStr('rotation')
local bg_id = ImHashStr('bg')
local scale_id = ImHashStr('scale')
local primary_btn_id = ImHashStr('btn_primary')
local ghost_btn_id = ImHashStr('btn_ghost')
local rotate_btn_id = ImHashStr('btn_icon')

local IM_COL32_WHITE = IM_COL32(255,255,255,255)

-- ============================================================
-- USECASE 1: Animated Button with Hover/Press States
-- ============================================================
local function ShowUsecase_AnimatedButton()
    imgui.TextWrapped("Buttons that respond with smooth animations on hover, press, and release. Demonstrates crossfade policy for seamless state transitions.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    -- Button states
    local btn1_hovered = false
    local btn1_pressed = false
    local btn2_hovered = false
    local btn2_pressed = false
    local btn3_hovered = false
    local btn3_pressed = false

    local cursor = imgui.GetCursorScreenPosVec()
    local spacing = 20.0

    -- Primary Button (Scale + Color)
    local btn_size = ImVec2(140, 44)
    local btn_pos = cursor

    imgui.SetCursorScreenPos(btn_pos)
    imgui.InvisibleButton('##btn_primary', btn_size)
    btn1_hovered = imgui.IsItemHovered()
    btn1_pressed = imgui.IsItemActive()

    -- Determine target scale
    local target_scale = 1.0
    if btn1_pressed then
        target_scale = 0.95
    elseif btn1_hovered then
        target_scale = 1.05
    end

    -- Animate scale
    local scale = iam.TweenFloat(primary_btn_id, scale_id, target_scale, 0.15,
        iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    -- Animate color
    local base_color = ImVec4(0.2, 0.5, 0.9, 1.0)
    local hover_color = ImVec4(0.3, 0.6, 1.0, 1.0)
    local press_color = ImVec4(0.15, 0.4, 0.7, 1.0)
    local target_color = btn1_pressed and press_color or (btn1_hovered and hover_color or base_color)
    local color = iam.TweenColor(primary_btn_id, color_id, target_color, 0.2,
        iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)

    -- Draw scaled button
    local center = ImVec2(btn_pos.x + btn_size.x * 0.5, btn_pos.y + btn_size.y * 0.5)
    local half_size = ImVec2(btn_size.x * 0.5 * scale, btn_size.y * 0.5 * scale)
    dl:AddRectFilled(
        ImVec2(center.x - half_size.x, center.y - half_size.y),
        ImVec2(center.x + half_size.x, center.y + half_size.y),
        imgui.ColorConvertFloat4ToU32(color), 8.0)

    -- Text
    local label = "Primary"
    local text_x, text_y = imgui.CalcTextSize(label)
    dl:AddText(ImVec2(center.x - text_x * 0.5, center.y - text_y * 0.5),
        IM_COL32(255, 255, 255, 255), label)

    cursor.x = cursor.x + btn_size.x + spacing

    -- Ghost Button (Border animation)
    btn_size = ImVec2(140, 44)
    btn_pos = cursor

    imgui.SetCursorScreenPos(btn_pos)
    imgui.InvisibleButton('##btn_ghost', btn_size)
    btn2_hovered = imgui.IsItemHovered()
    btn2_pressed = imgui.IsItemActive()

    -- Animate border thickness
    local target_border = btn2_hovered and 2.5 or 1.5
    local border = iam.TweenFloat(ghost_btn_id, border_id, target_border, 0.2,
        iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Animate fill alpha
    local target_fill = btn2_pressed and 0.15 or (btn2_hovered and 0.08 or 0.0)
    local fill_alpha = iam.TweenFloat(ghost_btn_id, fill_id, target_fill, 0.15,
        iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Draw
    local border_color = IM_COL32(91, 194, 231, 255)
    local fill_color = IM_COL32(91, 194, 231, math.floor(fill_alpha * 255))
    dl:AddRectFilled(btn_pos, ImVec2(btn_pos.x + btn_size.x, btn_pos.y + btn_size.y),
        fill_color, 8.0)
    dl:AddRect(btn_pos, ImVec2(btn_pos.x + btn_size.x, btn_pos.y + btn_size.y),
        border_color, 8.0, 0, border)

    label = "Ghost"
    text_x, text_y = imgui.CalcTextSize(label)
    center = ImVec2(btn_pos.x + btn_size.x * 0.5, btn_pos.y + btn_size.y * 0.5)
    dl:AddText(ImVec2(center.x - text_x * 0.5, center.y - text_y * 0.5),
        border_color, label)

    cursor.x = cursor.x + btn_size.x + spacing

    -- Icon Button with Rotation
    btn_size = ImVec2(44, 44)
    btn_pos = cursor

    imgui.SetCursorScreenPos(btn_pos)
    imgui.InvisibleButton('##btn_icon', btn_size)
    btn3_hovered = imgui.IsItemHovered()
    btn3_pressed = imgui.IsItemActive()

    -- Animate rotation on hover
    local target_rotation = btn3_hovered and 90.0 or 0.0
    local rotation = iam.TweenFloat(rotate_btn_id, rotation_id, target_rotation, 0.3,
        iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    -- Animate background
    local target_bg = btn3_hovered and 0.15 or 0.0
    local bg_alpha = iam.TweenFloat(rotate_btn_id, bg_id, target_bg, 0.2,
        iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Draw background
    center = ImVec2(btn_pos.x + btn_size.x * 0.5, btn_pos.y + btn_size.y * 0.5)
    dl:AddCircleFilled(center, btn_size.x * 0.5, IM_COL32(255, 255, 255, math.floor(bg_alpha * 255)))

    -- Draw rotated "+" icon
    local rad = rotation * 3.14159 / 180.0
    local icon_size = 10.0
    local c = math.cos(rad)
    local s = math.sin(rad)

    local h1 = ImVec2(center.x - icon_size * c, center.y - icon_size * s)
    local h2 = ImVec2(center.x + icon_size * c, center.y + icon_size * s)
    local v1 = ImVec2(center.x - icon_size * (-s), center.y - icon_size * c)
    local v2 = ImVec2(center.x + icon_size * (-s), center.y + icon_size * c)

    local icon_color = btn3_pressed and IM_COL32(200, 200, 200, 255) or IM_COL32(255, 255, 255, 255)
    dl:AddLine(h1, h2, icon_color, 2.5)
    dl:AddLine(v1, v2, icon_color, 2.5)

    imgui.SetCursorScreenPos(imgui.GetCursorScreenPosVec().x, cursor.y + 60)
end


-- ============================================================
-- USECASE 7: Progress Bar with Segments
-- ============================================================
local progress_bar_state = {
    shimmer_time = 0.0,
    target_progress = 0.65,
    id = ImHashStr("progress_bar"),
    value_id = ImHashStr("value")
}

local function ShowUsecase_ProgressBar()
    local state = progress_bar_state

    imgui.TextWrapped("Animated progress bar with segmented fill and glow effects. Uses color interpolation in OKLAB for smooth gradients.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    -- small helper: slider returns nil in some bindings, preserve value
    local ok, v = pcall(function() return imgui.SliderFloat("Progress", state.target_progress, 0.0, 1.0) end)
    if ok and type(v) == 'number' then state.target_progress = v end

    local progress = iam.TweenFloat(state.id, state.value_id, state.target_progress, 0.5,
        iam.EasePreset(IamEaseType.OutExpo), IamPolicy.Crossfade, dt)

    local bar_pos = imgui.GetCursorScreenPosVec()
    local avail = imgui.GetContentRegionAvailVec()
    local bar_size = ImVec2(avail.x - 20.0, 24.0)

    dl:AddRectFilled(bar_pos, ImVec2(bar_pos.x + bar_size.x, bar_pos.y + bar_size.y), IM_COL32(30, 32, 40, 255), 6.0)

    local filled_width = bar_size.x * progress
    if filled_width > 2.0 then
        local start_col = ImVec4(0.2, 0.6, 0.9, 1.0)
        local end_col = ImVec4(0.2, 0.9, 0.5, 1.0)
        local fill_color = iam.GetBlendedColor(start_col, end_col, progress, IamColorSpace.OKLAB)

        dl:AddRectFilled(bar_pos, ImVec2(bar_pos.x + filled_width, bar_pos.y + bar_size.y), imgui.ColorConvertFloat4ToU32(fill_color), 6.0, ImDrawFlags.RoundCornersLeft)

        local glow_x = bar_pos.x + filled_width - 4.0
        for i = 0, 3 do
            local alpha = 0.3 * (1.0 - i * 0.25)
            local offset = i * 4.0
            dl:AddRectFilled(ImVec2(glow_x - offset, bar_pos.y), ImVec2(glow_x + 4.0, bar_pos.y + bar_size.y), IM_COL32(255, 255, 255, math.floor(alpha * 255)), 4.0)
        end

        state.shimmer_time = state.shimmer_time + dt
        local shimmer_pos = ((state.shimmer_time * 0.5) % 1.0) * filled_width
        local shimmer_width = 60.0
        if shimmer_pos < filled_width then
            local shimmer_alpha = 0.15 * math.sin(shimmer_pos / filled_width * 3.14159)
            dl:AddRectFilledMultiColor(ImVec2(bar_pos.x + shimmer_pos, bar_pos.y), ImVec2(bar_pos.x + shimmer_pos + shimmer_width, bar_pos.y + bar_size.y),
                IM_COL32(255,255,255,0), IM_COL32(255,255,255,math.floor(shimmer_alpha*255)), IM_COL32(255,255,255,math.floor(shimmer_alpha*255)), IM_COL32(255,255,255,0))
        end
    end

    local percent_text = string.format("%.0f%%", progress * 100.0)
    local tx, ty = imgui.CalcTextSize(percent_text)
    local text_pos = ImVec2(bar_pos.x + (bar_size.x - tx) * 0.5, bar_pos.y + (bar_size.y - ty) * 0.5)
    dl:AddText(text_pos, IM_COL32(255,255,255,200), percent_text)

    imgui.Dummy(bar_size.x, bar_size.y + 16.0)
end

-- ============================================================
-- USECASE 20: Pulse Notification Badge
-- ============================================================
local pulse_badge_state = {
    pulse_time = 0.0,
    badge_counts = {3, 99, 0}
}

local function ShowUsecase_PulseBadge()
    local state = pulse_badge_state

    imgui.TextWrapped("Notification badges that pulse to draw attention. Common for unread messages, alerts, and status indicators.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    state.pulse_time = state.pulse_time + dt

    if imgui.Button("Reset Badges") then
        state.pulse_time = 0
        state.badge_counts[1] = 3; state.badge_counts[2] = 99; state.badge_counts[3] = 0
    end
    imgui.SameLine()
    if imgui.Button("Add Notification") then
        state.badge_counts[1] = state.badge_counts[1] + 1
        state.badge_counts[2] = state.badge_counts[2] + 1
        state.pulse_time = 0
    end

    local pos = imgui.GetCursorScreenPosVec()
    local avail = imgui.GetContentRegionAvailVec()
    local canvas_size = ImVec2(avail.x, 80)

    dl:AddRectFilled(pos, ImVec2(pos.x + canvas_size.x, pos.y + canvas_size.y), IM_COL32(25,27,35,255), 4.0)

    local items = {
        { offset = ImVec2(0.2, 0.5), count = state.badge_counts[1], pulse = true },
        { offset = ImVec2(0.5, 0.5), count = state.badge_counts[2], pulse = true },
        { offset = ImVec2(0.8, 0.5), count = state.badge_counts[3], pulse = false }
    }

    for i, it in ipairs(items) do
        local icon_center = ImVec2(pos.x + canvas_size.x * it.offset.x, pos.y + canvas_size.y * it.offset.y)
        local icon_size = 24.0
        dl:AddCircleFilled(icon_center, icon_size, IM_COL32(60,65,80,255))
        dl:AddCircleFilled(ImVec2(icon_center.x, icon_center.y - 4), icon_size * 0.6, IM_COL32(80,85,100,255))

        local badge_center = ImVec2(icon_center.x + icon_size * 0.7, icon_center.y - icon_size * 0.5)

        local pulse = 0.0; local pulse2 = 0.0; local badge_scale = 1.0
        if it.pulse and it.count > 0 then
            local phase = state.pulse_time * 3.0 + (i-1) * 0.5
            pulse = phase % 1.0
            pulse2 = (phase + 0.5) % 1.0
            local scale_phase = state.pulse_time * 4.0 + (i-1) * 0.3
            badge_scale = 1.0 + math.sin(scale_phase) * 0.15
        end

        if pulse > 0.01 and it.count > 0 then
            local ring_radius = 10.0 + pulse * 20.0
            local ring_alpha = (1.0 - pulse) * 180
            dl:AddCircle(badge_center, ring_radius, IM_COL32(231,76,60,math.floor(ring_alpha)), 0, 2.5)

            local ring_radius2 = 10.0 + pulse2 * 20.0
            local ring_alpha2 = (1.0 - pulse2) * 180
            dl:AddCircle(badge_center, ring_radius2, IM_COL32(231,76,60,math.floor(ring_alpha2)), 0, 2.5)
        end

        local badge_radius = 10.0 * badge_scale
        dl:AddCircleFilled(badge_center, badge_radius, IM_COL32(231,76,60,255))

        if it.count > 0 then
            local count_text = (it.count > 99) and "99+" or tostring(it.count)
            local tx, ty = imgui.CalcTextSize(count_text)
            dl:AddText(ImVec2(badge_center.x - tx * 0.5, badge_center.y - ty * 0.5), IM_COL32_WHITE, count_text)
        end
    end

    imgui.Dummy(canvas_size.x, canvas_size.y)
end

-- ============================================================
-- 36. Pending Button
-- Button with loading spinner when processing
-- ============================================================
local pending_button_state = {
    is_pending = {false, false, false},
    pending_time = {0, 0, 0},
    spinner_angle = {0, 0, 0},
}

local function ShowUsecase_PendingButton()
    local state = pending_button_state

    imgui.TextWrapped("Click the button to trigger a loading state with spinner:")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetStyle().FontScaleMain

    local labels = {"Save","Submit","Upload"}
    local pos = imgui.GetCursorScreenPosVec()
    local button_width = 100.0 * scale
    local button_height = 40.0 * scale
    local spacing = 20.0 * scale

    for i = 1, 3 do
        imgui.PushID(i)
        local x = pos.x + (i-1) * (button_width + spacing)
        local btn_min = ImVec2(x, pos.y)
        local btn_max = ImVec2(x + button_width, pos.y + button_height)
        local btn_center = ImVec2((btn_min.x + btn_max.x)*0.5, (btn_min.y + btn_max.y)*0.5)

        if state.is_pending[i] then
            state.pending_time[i] = state.pending_time[i] + dt
            state.spinner_angle[i] = state.spinner_angle[i] + dt * 8.0
            if state.pending_time[i] > 2.0 then
                state.is_pending[i] = false
                state.pending_time[i] = 0
            end
        end

        local btn_color = state.is_pending[i] and IM_COL32(60,65,80,255) or IM_COL32(76,175,80,255)
        dl:AddRectFilled(btn_min, btn_max, btn_color, 6.0 * scale)

        imgui.SetCursorScreenPos(btn_min)
        if imgui.InvisibleButton("##btn", ImVec2(button_width, button_height)) and not state.is_pending[i] then
            state.is_pending[i] = true
            state.pending_time[i] = 0
        end

        local label = state.is_pending[i] and "..." or labels[i]
        local tx, ty = imgui.CalcTextSize(label)
        local text_x = btn_center.x - tx * 0.5
        if state.is_pending[i] then text_x = text_x - 8 * scale end
        dl:AddText(ImVec2(text_x, btn_center.y - ty * 0.5), IM_COL32(255,255,255,255), label)

        if state.is_pending[i] then
            local spinner_radius = 8.0 * scale
            local spinner_center = ImVec2(btn_max.x - 16 * scale, btn_min.y + 16 * scale)
            local start_angle = state.spinner_angle[i]
            local arc_length = math.pi * 1.5
            local segments = 20
            for s = 0, segments - 1 do
                local t1 = s / segments
                local t2 = (s+1) / segments
                local a1 = start_angle + t1 * arc_length
                local a2 = start_angle + t2 * arc_length
                local alpha = math.floor(255 * t2)
                dl:AddLine(ImVec2(spinner_center.x + math.cos(a1) * spinner_radius, spinner_center.y + math.sin(a1) * spinner_radius), ImVec2(spinner_center.x + math.cos(a2) * spinner_radius, spinner_center.y + math.sin(a2) * spinner_radius), IM_COL32(255,255,255,alpha), 2.0 * scale)
            end
        end

        imgui.PopID()
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + button_height + 16)
    imgui.Dummy(ImVec2(1,1))
end

-- ============================================================
-- 37. Animated Slider
-- Custom slider with smooth thumb and track animation
-- ============================================================
local animated_slider_state = {
    slider_values = {0.3, 0.7},
    slider_id = ImHashStr("slider"),
    scale_id = ImHashStr("scale")
}

local function ShowUsecase_AnimatedSlider()
    local state = animated_slider_state

    imgui.TextWrapped("Custom slider with animated thumb and glowing track:")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetStyle().FontScaleMain

    local labels = {"Volume","Brightness"}
    local pos = imgui.GetCursorScreenPosVec()
    local slider_width = 250.0 * scale
    local slider_height = 8.0 * scale
    local thumb_radius = 12.0 * scale
    local line_height = 50.0 * scale

    for i = 1, 2 do
        imgui.PushID(i)
        local y = pos.y + (i-1) * line_height
        dl:AddText(ImVec2(pos.x, y), IM_COL32(200,200,210,255), labels[i])

        local track_x = pos.x + 100 * scale
        local track_y = y + imgui.GetFontSize() * 0.5 - slider_height * 0.5

        dl:AddRectFilled(ImVec2(track_x, track_y), ImVec2(track_x + slider_width, track_y + slider_height), IM_COL32(50,55,65,255), slider_height * 0.5)

        local fill_width = state.slider_values[i] * slider_width
        local fill_color = (i == 1) and IM_COL32(76,175,80,255) or IM_COL32(255,193,7,255)
        dl:AddRectFilled(ImVec2(track_x, track_y), ImVec2(track_x + fill_width, track_y + slider_height), fill_color, slider_height * 0.5)

        local thumb_x = track_x + fill_width
        local thumb_y = track_y + slider_height * 0.5

        imgui.SetCursorScreenPos(ImVec2(track_x - thumb_radius, track_y - thumb_radius))
        if imgui.InvisibleButton("##slider", ImVec2(slider_width + thumb_radius * 2, slider_height + thumb_radius * 2)) then end

        if imgui.IsItemActive() then
            local mouse_x = imgui.GetIO().MousePos.x
            state.slider_values[i] = math.max(0.0, math.min(1.0, (mouse_x - track_x) / slider_width))
        end

        local hovered = imgui.IsItemHovered() or imgui.IsItemActive()
        local id = state.slider_id
        local target_scale = hovered and 1.3 or 1.0
        local thumb_scale = iam.TweenFloat(id, state.scale_id, target_scale, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        if thumb_scale > 1.1 then
            dl:AddCircleFilled(ImVec2(thumb_x, thumb_y), thumb_radius * thumb_scale * 1.5, IM_COL32(255,255,255,30))
        end

        dl:AddCircleFilled(ImVec2(thumb_x, thumb_y), thumb_radius * thumb_scale, IM_COL32(255,255,255,255))
        dl:AddCircle(ImVec2(thumb_x, thumb_y), thumb_radius * thumb_scale, fill_color, 0, 2.0 * scale)

        local value_text = string.format("%.0f%%", state.slider_values[i] * 100)
        dl:AddText(ImVec2(track_x + slider_width + 10 * scale, y), IM_COL32(180,180,190,255), value_text)

        imgui.PopID()
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + 2 * line_height + 8)
    imgui.Dummy(ImVec2(1,1))
end

-- ============================================================
-- USECASE: Icon Button Rotation
-- ============================================================
local icon_button_state = {
    hovered = {false,false,false},
    rot_base = ImHashStr("icon_rot"),
    rot_name = ImHashStr("rot"),
    scl_base = ImHashStr("icon_scl"),
    scl_name = ImHashStr("scl")
}

local function ShowUsecase_IconButtonRotation()
    local state = icon_button_state

    imgui.TextWrapped("Icon button that rotates its icon shape on hover using iam_tween_float.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local labels = {"Settings","Menu","Add"}

    local pos = imgui.GetCursorScreenPosVec()
    local btn_size = 50 * scale
    local spacing = 70 * scale

    for i = 1, 3 do
        local btn_pos = ImVec2(pos.x + (i-1) * spacing, pos.y)
        local btn_center = ImVec2(btn_pos.x + btn_size * 0.5, btn_pos.y + btn_size * 0.5)

        imgui.SetCursorScreenPos(btn_pos)
        imgui.PushID(i)
        imgui.InvisibleButton("icon_btn", ImVec2(btn_size, btn_size))
        state.hovered[i] = imgui.IsItemHovered()
        imgui.PopID()

        local target_rot = state.hovered[i] and (math.pi * 0.5) or 0.0
        local rotation = iam.TweenFloat(state.rot_base + (i-1), state.rot_name, target_rot, 0.3, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)
        local target_scl = state.hovered[i] and 1.15 or 1.0
        local btn_scale = iam.TweenFloat(state.scl_base + (i-1), state.scl_name, target_scl, 0.2, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        local bg_col = state.hovered[i] and IM_COL32(70,130,180,255) or IM_COL32(60,65,75,255)
        dl:AddCircleFilled(btn_center, btn_size * 0.45 * btn_scale, bg_col)

        local icon_r = 12 * scale * btn_scale
        local cos_r = math.cos(rotation)
        local sin_r = math.sin(rotation)

        if i == 1 then
            for j = 0, 3 do
                local angle = rotation + j * (math.pi * 0.5)
                local c = math.cos(angle); local s = math.sin(angle)
                dl:AddLine(ImVec2(btn_center.x + c * 5 * scale, btn_center.y + s * 5 * scale), ImVec2(btn_center.x + c * icon_r, btn_center.y + s * icon_r), IM_COL32(255,255,255,255), 3 * scale)
            end
            dl:AddCircle(btn_center, 6 * scale * btn_scale, IM_COL32(255,255,255,255), 0, 2 * scale)
        elseif i == 2 then
            for j = -1, 1 do
                local offset = j * 5 * scale
                local rx = -offset * sin_r
                local ry = offset * cos_r
                dl:AddLine(ImVec2(btn_center.x + rx - 8 * scale * cos_r, btn_center.y + ry - 8 * scale * sin_r), ImVec2(btn_center.x + rx + 8 * scale * cos_r, btn_center.y + ry + 8 * scale * sin_r), IM_COL32(255,255,255,255), 2.5 * scale)
            end
        else
            dl:AddLine(ImVec2(btn_center.x - sin_r * icon_r, btn_center.y + cos_r * icon_r), ImVec2(btn_center.x + sin_r * icon_r, btn_center.y - cos_r * icon_r), IM_COL32(255,255,255,255), 3 * scale)
            dl:AddLine(ImVec2(btn_center.x - cos_r * icon_r, btn_center.y - sin_r * icon_r), ImVec2(btn_center.x + cos_r * icon_r, btn_center.y + sin_r * icon_r), IM_COL32(255,255,255,255), 3 * scale)
        end

        local label_size_x, label_size_y = imgui.CalcTextSize(labels[i])
        dl:AddText(ImVec2(btn_center.x - label_size_x * 0.5, btn_pos.y + btn_size + 5 * scale), IM_COL32(150,150,160,255), labels[i])
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + btn_size + 30 * scale)
    imgui.Dummy(ImVec2(1,1))
end

-- ============================================================
-- USECASE: Like Heart Button
-- ============================================================
local like_heart_state = {
    liked = false,
    like_time = 0.0,
    hover_id = ImHashStr("heart_hover"),
    hh_id = ImHashStr("hh"),
    scale_id = ImHashStr("heart_scale"),
    hs_id = ImHashStr("hs"),
    col_id = ImHashStr("heart_col"),
    hc_id = ImHashStr("hc"),
    glow_id = ImHashStr("heart_glow"),
    hg_id = ImHashStr("hg")
}

local function ShowUsecase_LikeHeartButton()
    local state = like_heart_state

    imgui.TextWrapped("Instagram-style heart button with hover grow, click bounce, and particle burst animations.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local heart_size = 40 * scale
    local center = ImVec2(pos.x + heart_size, pos.y + heart_size)

    imgui.InvisibleButton("heart_btn", ImVec2(heart_size * 2, heart_size * 2))
    local hovered = imgui.IsItemHovered()
    if imgui.IsItemClicked() then state.liked = not state.liked; state.like_time = 0 end

    state.like_time = state.like_time + dt

    local hover_scale = iam.TweenFloat(state.hover_id, state.hh_id, hovered and 1.15 or 1.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
    local click_scale = iam.TweenFloat(state.scale_id, state.hs_id, state.liked and 1.2 or 1.0, 0.25, iam.EasePreset(IamEaseType.OutElastic), IamPolicy.Crossfade, dt)
    local heart_scale = hover_scale * click_scale

    local color_t = iam.TweenFloat(state.col_id, state.hc_id, state.liked and 1.0 or 0.0, 0.2, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
    local glow_alpha = iam.TweenFloat(state.glow_id, state.hg_id, hovered and 0.4 or 0.0, 0.2, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    local heart_col = IM_COL32( math.floor(150 + 105 * color_t), math.floor(150 - 100 * color_t), math.floor(150 - 100 * color_t), 255)

    if glow_alpha > 0.01 then
        local hs_glow = heart_size * 0.5 * heart_scale
        dl:AddCircleFilled(center, hs_glow * 1.5, IM_COL32(255,100,100, math.floor(glow_alpha * 100)))
    end

    local hs = heart_size * 0.4 * heart_scale
    dl:AddCircleFilled(ImVec2(center.x - hs * 0.5, center.y - hs * 0.2), hs * 0.55, heart_col)
    dl:AddCircleFilled(ImVec2(center.x + hs * 0.5, center.y - hs * 0.2), hs * 0.55, heart_col)
    dl:AddTriangleFilled(ImVec2(center.x - hs * 1.0, center.y), ImVec2(center.x + hs * 1.0, center.y), ImVec2(center.x, center.y + hs * 1.1), heart_col)

    if state.liked and state.like_time < 0.6 then
        for i = 0, 11 do
            local angle = i * math.pi * 2.0 / 12.0 + state.like_time * 0.5
            local dist = state.like_time * 100 * scale
            local alpha = 1.0 - state.like_time * 1.7
            if alpha > 0 then
                local p = ImVec2(center.x + math.cos(angle) * dist, center.y + math.sin(angle) * dist)
                local particle_size = (3 + (i % 3)) * scale * alpha
                dl:AddCircleFilled(p, particle_size, IM_COL32(255,100,100, math.floor(alpha * 255)))
            end
        end
    end

    local text = state.liked and "Liked!" or (hovered and "Click me!" or "Hover & Click")
    local tx, ty = imgui.CalcTextSize(text)
    dl:AddText(ImVec2(center.x - tx * 0.5, pos.y + heart_size * 2 + 10 * scale), IM_COL32(180,180,190,255), text)

    imgui.SetCursorScreenPos(pos.x, pos.y + heart_size * 2 + 35 * scale)
end

-- ============================================================
-- USECASE: Button Glow Effect
-- ============================================================
local button_glow_state = {
    focused = false,
    glow_id = ImHashStr("glow"),
    g_id = ImHashStr("g"),
    pulse_id = ImHashStr("pulse")
}

local function ShowUsecase_ButtonGlow()
    local state = button_glow_state

    imgui.TextWrapped("Button with animated glow effect on focus/hover using iam_oscillate.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local btn_size = ImVec2(180 * scale, 45 * scale)

    imgui.InvisibleButton("glow_btn", btn_size)
    local hovered = imgui.IsItemHovered()
    if imgui.IsItemClicked() then state.focused = not state.focused end

    local glow_target = (state.focused or hovered) and 1.0 or 0.0
    local glow = iam.TweenFloat(state.glow_id, state.g_id, glow_target, 0.3, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    local pulse = 0.0
    if state.focused then pulse = 0.5 + 0.5 * iam.Oscillate(state.pulse_id, 1.0, 2.0, IamWaveType.Sine, 0.0, dt) end

    if glow > 0.01 then
        for i = 3, 0, -1 do
            local offset = (4 - i) * 4 * scale * glow
            local alpha = math.floor(30 * glow * (1.0 + pulse * 0.5) / (i + 1))
            dl:AddRectFilled(ImVec2(pos.x - offset, pos.y - offset), ImVec2(pos.x + btn_size.x + offset, pos.y + btn_size.y + offset), IM_COL32(100,150,255,alpha), 12 * scale)
        end
    end

    local bg_col = state.focused and IM_COL32(70,120,200,255) or IM_COL32(60,65,75,255)
    dl:AddRectFilled(pos, ImVec2(pos.x + btn_size.x, pos.y + btn_size.y), bg_col, 8 * scale)

    local text = state.focused and "Focused (click)" or "Click to focus"
    local tx, ty = imgui.CalcTextSize(text)
    dl:AddText(ImVec2(pos.x + (btn_size.x - tx) * 0.5, pos.y + (btn_size.y - ty) * 0.5), IM_COL32(255,255,255,255), text)

    imgui.SetCursorScreenPos(pos.x, pos.y + btn_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Download Progress Button
-- ============================================================
local download_progress_state = {
    state = 0,
    progress = 0.0,
    width_id = ImHashStr("dl_width"),
    w_id = ImHashStr("w")
}

local function ShowUsecase_DownloadProgressButton()
    local state = download_progress_state

    imgui.TextWrapped("Button that transforms into a progress indicator during download.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    if state.state == 1 then
        state.progress = state.progress + dt * 0.4
        if state.progress >= 1.0 then state.progress = 1.0; state.state = 2 end
    end

    local pos = imgui.GetCursorScreenPosVec()
    local btn_size = ImVec2(200 * scale, 50 * scale)

    imgui.InvisibleButton("download_btn", btn_size)
    if imgui.IsItemClicked() and state.state ~= 1 then
        if state.state == 2 then state.state = 0; state.progress = 0 else state.state = 1 end
    end

    local target_width = (state.state == 1) and btn_size.y or btn_size.x
    local current_width = iam.TweenFloat(state.width_id, state.w_id, target_width, 0.3, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    local center = ImVec2(pos.x + btn_size.x * 0.5, pos.y + btn_size.y * 0.5)
    local half_w = current_width * 0.5
    local half_h = btn_size.y * 0.5

    local bg_col = (state.state == 2) and IM_COL32(76,175,80,255) or IM_COL32(70,130,180,255)
    dl:AddRectFilled(ImVec2(center.x - half_w, center.y - half_h), ImVec2(center.x + half_w, center.y + half_h), bg_col, half_h)

    if state.state == 1 then
        local start_angle = -math.pi * 0.5
        local end_angle = start_angle + state.progress * math.pi * 2.0
        dl:PathArcTo(center, 15 * scale, start_angle, end_angle, 32)
        dl:PathStroke(IM_COL32(255,255,255,255), 0, 3 * scale)
        local pct = string.format("%.0f%%", state.progress * 100)
        local tsx, tsy = imgui.CalcTextSize(pct)
        dl:AddText(ImVec2(center.x - tsx * 0.5, center.y - tsy * 0.5), IM_COL32(255,255,255,255), pct)
    else
        local text = (state.state == 2) and "Complete!" or "Download"
        local tsx, tsy = imgui.CalcTextSize(text)
        dl:AddText(ImVec2(center.x - tsx * 0.5, center.y - tsy * 0.5), IM_COL32(255,255,255,255), text)
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + btn_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Submit Button States
-- ============================================================
local submit_button_states = {
    state = 0,
    state_time = 0,
    spinner_angle = 0,
}

local function ShowUsecase_SubmitButtonStates()
    local state = submit_button_states

    imgui.TextWrapped("Form submit button with idle/loading/success/error state transitions.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    state.state_time = state.state_time + dt
    state.spinner_angle = state.spinner_angle + dt * 5.0

    if state.state == 1 and state.state_time > 2.0 then
        if math.floor(state.state_time * 100) % 2 == 0 then state.state = 2 else state.state = 3 end
        state.state_time = 0
    end

    if (state.state == 2 or state.state == 3) and state.state_time > 1.5 then
        state.state = 0; state.state_time = 0
    end

    local pos = imgui.GetCursorScreenPosVec()
    local btn_size = ImVec2(180 * scale, 45 * scale)

    imgui.InvisibleButton("submit_btn", btn_size)
    if imgui.IsItemClicked() and state.state == 0 then state.state = 1; state.state_time = 0 end

    local colors = {IM_COL32(70,130,180,255), IM_COL32(100,100,110,255), IM_COL32(76,175,80,255), IM_COL32(244,67,54,255)}
    local bg_col = colors[state.state+1]
    dl:AddRectFilled(pos, ImVec2(pos.x + btn_size.x, pos.y + btn_size.y), bg_col, 6 * scale)

    local center = ImVec2(pos.x + btn_size.x * 0.5, pos.y + btn_size.y * 0.5)
    if state.state == 1 then
        local r = 10 * scale
        dl:PathArcTo(center, r, state.spinner_angle, state.spinner_angle + 4.0, 16)
        dl:PathStroke(IM_COL32(255,255,255,255), 0, 2 * scale)
    else
        local texts = {"Submit","","Success!","Error"}
        local text = texts[state.state+1]
        local tsx, tsy = imgui.CalcTextSize(text)
        dl:AddText(ImVec2(center.x - tsx * 0.5, center.y - tsy * 0.5), IM_COL32(255,255,255,255), text)
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + btn_size.y + 10 * scale)
end

local function RunButtonsAndIndicatorsDemo()
    -- ========================================
    -- BUTTONS & INDICATORS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Buttons & Indicators") then
        imgui.Indent()
        common.USECASE_ITEM('Animated Buttons', ShowUsecase_AnimatedButton)
        common.USECASE_ITEM('Progress Bar', ShowUsecase_ProgressBar)
        common.USECASE_ITEM('Pulse Badge', ShowUsecase_PulseBadge)
        common.USECASE_ITEM('Pending Button', ShowUsecase_PendingButton)
        common.USECASE_ITEM('Animated Slider', ShowUsecase_AnimatedSlider)
        common.USECASE_ITEM('Icon Button Rotation', ShowUsecase_IconButtonRotation)
        common.USECASE_ITEM('Button Glow Effect', ShowUsecase_ButtonGlow)
        common.USECASE_ITEM('Like Heart Button', ShowUsecase_LikeHeartButton)
        common.USECASE_ITEM('Download Progress Button', ShowUsecase_DownloadProgressButton)
        common.USECASE_ITEM('Submit Button States', ShowUsecase_SubmitButtonStates)
        imgui.Unindent()
    end
end

return RunButtonsAndIndicatorsDemo
