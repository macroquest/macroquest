local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 25: Toggle Switch
-- ============================================================
local toggle_switch_state = {
    toggles = { true, false, true },
    labels = { 'Notifications', 'Dark Mode', 'Auto-save' },
    thumb_id = ImHashStr('toggle_thumb'),
    bg_id = ImHashStr('toggle_bg'),
}

local function ShowUsecase_ToggleSwitch()
    local state = toggle_switch_state

    imgui.TextWrapped('iOS-style toggle switches with smooth thumb animation. Includes color transition and bounce effect.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local switch_width = 50.0
    local switch_height = 28.0
    local row_height = 40.0

    for i = 0, 2 do
        local row_pos = ImVec2(pos.x, pos.y + i * row_height)
        local id = ImHashStr('toggle_' .. i)

        -- Switch position
        local switch_pos = ImVec2(pos.x, row_pos.y + (row_height - switch_height) * 0.5)

        -- Click handler
        imgui.SetCursorScreenPos(switch_pos.x, switch_pos.y)
        if imgui.InvisibleButton('##toggle_' .. i, ImVec2(switch_width, switch_height)) then
            state.toggles[i + 1] = not state.toggles[i + 1]
        end

        local hovered = imgui.IsItemHovered()

        -- Animate thumb position
        local target_thumb = state.toggles[i + 1] and 1.0 or 0.0
        local thumb_pos = iam.TweenFloat(id, state.thumb_id, target_thumb, 0.25, iam.EasePreset(IamEaseType.EaseOutBack), IamPolicy.Crossfade, dt)

        -- Animate background color (off: gray, on: green)
        local off_color = IM_COL32(76, 82, 97, 255)
        local on_color = IM_COL32(89, 194, 125, 255)
        local bg_color = state.toggles[i + 1] and on_color or off_color
        if thumb_pos > 0.01 and thumb_pos < 0.99 then
            local r = bit.band(off_color, 0xFF) + (bit.band(on_color, 0xFF) - bit.band(off_color, 0xFF)) * thumb_pos
            local g = bit.band(bit.rshift(off_color, 8), 0xFF) + (bit.band(bit.rshift(on_color, 8), 0xFF) - bit.band(bit.rshift(off_color, 8), 0xFF)) * thumb_pos
            local b = bit.band(bit.rshift(off_color, 16), 0xFF) + (bit.band(bit.rshift(on_color, 16), 0xFF) - bit.band(bit.rshift(off_color, 16), 0xFF)) * thumb_pos
            bg_color = IM_COL32(math.floor(r), math.floor(g), math.floor(b), 255)
        end

        -- Draw track
        local track_radius = switch_height * 0.5
        dl:AddRectFilled(switch_pos, ImVec2(switch_pos.x + switch_width, switch_pos.y + switch_height), bg_color, track_radius)

        -- Draw thumb
        local thumb_radius = switch_height * 0.5 - 3.0
        local thumb_x = switch_pos.x + track_radius + thumb_pos * (switch_width - switch_height)
        local thumb_y = switch_pos.y + switch_height * 0.5

        -- Thumb shadow
        dl:AddCircleFilled(ImVec2(thumb_x + 1, thumb_y + 2), thumb_radius, IM_COL32(0, 0, 0, 30))

        -- Thumb
        local thumb_color = hovered and IM_COL32(255, 255, 255, 255) or IM_COL32(245, 245, 245, 255)
        dl:AddCircleFilled(ImVec2(thumb_x, thumb_y), thumb_radius, thumb_color)

        -- Label (on the right of the toggle)
        local label_pos = ImVec2(pos.x + switch_width + 16, row_pos.y + (row_height - imgui.GetFontSize()) * 0.5)
        dl:AddText(label_pos, IM_COL32(200, 200, 210, 255), state.labels[i + 1])
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + 3 * row_height + 8)
end

-- ============================================================
-- USECASE 27: Rating Stars
-- ============================================================
local rating_stars_state = {
    rating = 3,
    hover_rating = 0,
    click_time = 0.0,
    clicked_star = -1,
}

local function ShowUsecase_RatingStars()
    local state = rating_stars_state

    imgui.TextWrapped('Interactive star rating with hover preview and click animation. Common pattern for reviews and feedback.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    if imgui.Button('Reset Rating') then
        state.rating = 0
        state.click_time = 0.0
    end

    local pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 80)

    -- Background
    dl:AddRectFilled(pos, ImVec2(pos.x + canvas_size.x, pos.y + canvas_size.y), IM_COL32(25, 27, 35, 255), 4.0)

    local star_count = 5
    local star_size = 24.0
    local star_spacing = 40.0
    local total_width = (star_count - 1) * star_spacing
    local start_x = pos.x + (canvas_size.x - total_width) * 0.5
    local center_y = pos.y + canvas_size.y * 0.5

    -- Update click animation
    if state.click_time > 0.0 then
        state.click_time = state.click_time - dt
    end

    state.hover_rating = 0

    for i = 0, star_count - 1 do
        local star_center = ImVec2(start_x + i * star_spacing, center_y)

        -- Hit testing
        imgui.SetCursorScreenPos(star_center.x - star_size, star_center.y - star_size)
        if imgui.InvisibleButton('##star_' .. i, ImVec2(star_size * 2, star_size * 2)) then
            state.rating = i + 1
            state.click_time = 0.5
            state.clicked_star = i
        end
        if imgui.IsItemHovered() then
            state.hover_rating = i + 1
        end

        -- Determine if star should be filled
        local display_rating = state.hover_rating > 0 and state.hover_rating or state.rating
        local filled = i < display_rating

        -- Click animation scale
        local scale = 1.0
        if state.clicked_star == i and state.click_time > 0.0 then
            local t = 1.0 - (state.click_time / 0.5)
            scale = 1.0 + iam.EvalPreset(iam.EaseOutBack, t) * 0.5 - t * 0.5
        end

        -- Draw star shape
        local fill_color = filled and IM_COL32(255, 200, 50, 255) or IM_COL32(60, 65, 80, 255)
        local outline_color = filled and IM_COL32(255, 220, 100, 255) or IM_COL32(80, 85, 100, 255)

        -- Star shape using concave polygon (5-pointed star)
        local outer_r = star_size * scale
        local inner_r = outer_r * 0.4

        local points = {}
        for j = 0, 9 do
            local angle = -math.pi * 0.5 + j * math.pi * 0.2
            local r = (j % 2 == 0) and outer_r or inner_r
            points[j + 1] = ImVec2(star_center.x + math.cos(angle) * r, star_center.y + math.sin(angle) * r)
        end
        -- Draw star (simplified as concave polygon equivalent)
        dl:AddConcavePolyFilled(points, fill_color)

        -- Draw outline edges
        for j = 0, 9 do
            dl:AddLine(points[j + 1], points[((j + 1) % 10) + 1], outline_color, 1.5)
        end
    end

    -- Display text
    local rating_text = string.format('Rating: %d / 5', state.rating)
    local text_size = imgui.CalcTextSizeVec(rating_text)
    imgui.SetCursorScreenPos(pos.x, pos.y + canvas_size.y - 20)
    dl:AddText(ImVec2(pos.x + (canvas_size.x - text_size.x) * 0.5, pos.y + canvas_size.y - 18), IM_COL32(180, 180, 190, 255), rating_text)

    imgui.SetCursorScreenPos(pos.x, pos.y + canvas_size.y + 8)
end

-- ============================================================
-- 30. Animated Checkbox
-- ============================================================
local checkbox_state = {
    checkboxes = { false, true, false },
    check_anims = { 0.0, 1.0, 0.0 },
    labels = { 'Enable notifications', 'Dark mode', 'Auto-save' },
    check_id = ImHashStr('checkbox_check'),
}

local function ShowUsecase_AnimatedCheckbox()
    local state = checkbox_state

    imgui.TextWrapped('Animated checkboxes with smooth checkmark drawing and scale effect:')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetStyle().FontScaleMain

    local pos = imgui.GetCursorScreenPosVec()
    local line_height = 32.0 * scale

    for i = 0, 2 do
        imgui.PushID(i)

        local box_size = 22.0 * scale
        local box_pos = ImVec2(pos.x, pos.y + i * line_height)
        local box_min = box_pos
        local box_max = ImVec2(box_pos.x + box_size, box_pos.y + box_size)

        -- Invisible button for interaction
        local label_size = imgui.CalcTextSizeVec(state.labels[i + 1])
        imgui.SetCursorScreenPos(box_pos.x, box_pos.y)
        if imgui.InvisibleButton('##check_' .. i, ImVec2(box_size + label_size.x + 10 * scale, box_size)) then
            state.checkboxes[i + 1] = not state.checkboxes[i + 1]
        end

        -- Animate check state
        local target = state.checkboxes[i + 1] and 1.0 or 0.0
        local id = ImHashStr('check_anim_' .. i)
        state.check_anims[i + 1] = iam.TweenFloat(id, state.check_id, target, 0.25, iam.EasePreset(IamEaseType.EaseOutBack), IamPolicy.Crossfade, dt)

        local anim = state.check_anims[i + 1]

        -- Box background with color lerp
        local r_off = bit.band(IM_COL32(50, 55, 65, 255), 0xFF)
        local g_off = bit.band(bit.rshift(IM_COL32(50, 55, 65, 255), 8), 0xFF)
        local b_off = bit.band(bit.rshift(IM_COL32(50, 55, 65, 255), 16), 0xFF)

        local r_on = bit.band(IM_COL32(76, 175, 80, 255), 0xFF)
        local g_on = bit.band(bit.rshift(IM_COL32(76, 175, 80, 255), 8), 0xFF)
        local b_on = bit.band(bit.rshift(IM_COL32(76, 175, 80, 255), 16), 0xFF)

        local r = math.floor(r_off + (r_on - r_off) * anim)
        local g = math.floor(g_off + (g_on - g_off) * anim)
        local b = math.floor(b_off + (b_on - b_off) * anim)
        local box_bg = IM_COL32(r, g, b, 255)

        local box_scale = 1.0 + iam.EvalPreset(iam.EaseOutBack, anim) * 0.1 - anim * 0.1

        local center = ImVec2((box_min.x + box_max.x) * 0.5, (box_min.y + box_max.y) * 0.5)
        local scaled_min = ImVec2(center.x - box_size * 0.5 * box_scale, center.y - box_size * 0.5 * box_scale)
        local scaled_max = ImVec2(center.x + box_size * 0.5 * box_scale, center.y + box_size * 0.5 * box_scale)

        dl:AddRectFilled(scaled_min, scaled_max, box_bg, 4.0 * scale)
        dl:AddRect(scaled_min, scaled_max, IM_COL32(255, 255, 255, 50), 4.0 * scale)

        -- Draw animated checkmark
        if anim > 0.01 then
            local check_progress = math.min(anim * 1.2, 1.0)

            -- Checkmark points (relative to box)
            local p1 = ImVec2(center.x - box_size * 0.25, center.y)
            local p2 = ImVec2(center.x - box_size * 0.05, center.y + box_size * 0.2)
            local p3 = ImVec2(center.x + box_size * 0.3, center.y - box_size * 0.2)

            local thickness = 2.5 * scale

            -- First segment (short down stroke)
            if check_progress > 0.0 then
                local seg1 = math.min(check_progress * 2.5, 1.0)
                local end1 = ImVec2(p1.x + (p2.x - p1.x) * seg1, p1.y + (p2.y - p1.y) * seg1)
                dl:AddLine(p1, end1, IM_COL32(255, 255, 255, 255), thickness)
            end

            -- Second segment (long up stroke)
            if check_progress > 0.4 then
                local seg2 = math.min((check_progress - 0.4) * 2.5, 1.0)
                local end2 = ImVec2(p2.x + (p3.x - p2.x) * seg2, p2.y + (p3.y - p2.y) * seg2)
                dl:AddLine(p2, end2, IM_COL32(255, 255, 255, 255), thickness)
            end
        end

        -- Label
        dl:AddText(ImVec2(box_max.x + 8 * scale, box_pos.y + (box_size - imgui.GetFontSize()) * 0.5), IM_COL32(220, 220, 230, 255), state.labels[i + 1])

        imgui.PopID()
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + 3 * line_height + 8)
end

-- ============================================================
-- 32. Animated Radio Buttons
-- ============================================================
local radio_state = {
    selected = 0,
    selection_anims = { 1.0, 0.0, 0.0, 0.0 },
    options = { 'Small', 'Medium', 'Large', 'Extra Large' },
    radio_id = ImHashStr('radio_select'),
}

local function ShowUsecase_AnimatedRadio()
    local state = radio_state

    imgui.TextWrapped('Radio button group with smooth selection transitions:')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetStyle().FontScaleMain

    local pos = imgui.GetCursorScreenPosVec()
    local line_height = 32.0 * scale
    local radio_size = 20.0 * scale

    for i = 0, 3 do
        imgui.PushID(i)

        local radio_pos = ImVec2(pos.x, pos.y + i * line_height)
        local center = ImVec2(radio_pos.x + radio_size * 0.5, radio_pos.y + radio_size * 0.5)

        -- Invisible button for interaction
        local option_size = imgui.CalcTextSizeVec(state.options[i + 1])
        imgui.SetCursorScreenPos(radio_pos.x, radio_pos.y)
        if imgui.InvisibleButton('##radio_' .. i, ImVec2(radio_size + option_size.x + 10 * scale, radio_size)) then
            state.selected = i
        end

        -- Animate selection
        local target = (state.selected == i) and 1.0 or 0.0
        local id = ImHashStr('radio_sel_' .. i)
        state.selection_anims[i + 1] = iam.TweenFloat(id, state.radio_id, target, 0.2, iam.EasePreset(IamEaseType.EaseOutCubic), IamPolicy.Crossfade, dt)

        local anim = state.selection_anims[i + 1]

        -- Outer circle (color transitions from gray to green)
        local r_off = bit.band(IM_COL32(80, 85, 100, 255), 0xFF)
        local g_off = bit.band(bit.rshift(IM_COL32(80, 85, 100, 255), 8), 0xFF)
        local b_off = bit.band(bit.rshift(IM_COL32(80, 85, 100, 255), 16), 0xFF)

        local r_on = bit.band(IM_COL32(76, 175, 80, 255), 0xFF)
        local g_on = bit.band(bit.rshift(IM_COL32(76, 175, 80, 255), 8), 0xFF)
        local b_on = bit.band(bit.rshift(IM_COL32(76, 175, 80, 255), 16), 0xFF)

        local r = math.floor(r_off + (r_on - r_off) * anim)
        local g = math.floor(g_off + (g_on - g_off) * anim)
        local b = math.floor(b_off + (b_on - b_off) * anim)
        local outer_color = IM_COL32(r, g, b, 255)

        dl:AddCircle(center, radio_size * 0.5, outer_color, 0, 2.0 * scale)

        -- Inner dot with scale animation
        if anim > 0.01 then
            local inner_radius = radio_size * 0.25 * iam.EvalPreset(iam.EaseOutBack, anim)
            dl:AddCircleFilled(center, inner_radius, IM_COL32(76, 175, 80, 255))
        end

        -- Label
        dl:AddText(ImVec2(radio_pos.x + radio_size + 8 * scale, radio_pos.y + (radio_size - imgui.GetFontSize()) * 0.5), IM_COL32(220, 220, 230, 255), state.options[i + 1])

        imgui.PopID()
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + 4 * line_height + 8)
end

-- ============================================================
-- 38. Color Swatch Animation
-- ============================================================
local function ShowUsecase_ColorSwatches()
    -- TODO: Implement Color Swatch Animation
end

-- ============================================================
-- USECASE: Segmented Control
-- ============================================================
local function ShowUsecase_SegmentedControl()
    -- TODO: Implement Segmented Control
end

-- ============================================================
-- USECASE: Rotary Dial
-- ============================================================
local function ShowUsecase_QuantityStepper()
    -- TODO: Implement Rotary Dial
end

-- ============================================================
-- USECASE: Password Strength Meter
-- ============================================================
local function ShowUsecase_StrengthMeter()
    -- TODO: Implement Password Strength Meter
end

-- ============================================================
-- USECASE: Analog Joystick Control
-- ============================================================
local function ShowUsecase_RangeSlider()
    -- TODO: Implement Analog Joystick Control
end

-- ============================================================
-- USECASE: Animated Reaction Buttons
-- ============================================================
local function ShowUsecase_SearchInput()
    -- TODO: Implement Animated Reaction Buttons
end

local function RunInputControlsDemo()
    -- ========================================
    -- INPUT CONTROLS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Input Controls") then
        imgui.Indent()
        common.USECASE_ITEM('Toggle Switch', ShowUsecase_ToggleSwitch)
        common.USECASE_ITEM('Animated Checkbox', ShowUsecase_AnimatedCheckbox)
        common.USECASE_ITEM('Animated Radio Buttons', ShowUsecase_AnimatedRadio)
        common.USECASE_ITEM('Rating Stars', ShowUsecase_RatingStars)
        common.USECASE_ITEM('Color Swatches', ShowUsecase_ColorSwatches)
        common.USECASE_ITEM('Segmented Control', ShowUsecase_SegmentedControl)
        common.USECASE_ITEM('Rotary Dial', ShowUsecase_QuantityStepper)
        common.USECASE_ITEM('Strength Meter', ShowUsecase_StrengthMeter)
        common.USECASE_ITEM('Joystick', ShowUsecase_RangeSlider)
        common.USECASE_ITEM('Reaction Picker', ShowUsecase_SearchInput)
        imgui.Unindent()
    end
end

return RunInputControlsDemo
