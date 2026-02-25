local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 8: Modal Dialog Animation
-- ============================================================
local modal_dialog_state = {
    open = false,
    modal_time = 0.0,
    modal_id = ImHashStr('modal'),
    backdrop_id = ImHashStr('modal_backdrop'),
    scale_id = ImHashStr('modal_scale'),
    opacity_id = ImHashStr('modal_opacity'),
}

local function ShowUsecase_ModalDialog()
    local state = modal_dialog_state
    imgui.TextWrapped('Modal dialog with backdrop fade and content scale-in animation. Demonstrates layered animations with different timing.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    if imgui.Button('Open Modal') then
        state.open = true
        state.modal_time = 0.0
    end

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local content_avail = imgui.GetContentRegionAvailVec()
    local canvas_size = ImVec2(content_avail.x, 200)

    -- Draw canvas background
    dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(25, 27, 35, 255), 4.0)

    -- Fake app content
    dl:AddText(ImVec2(canvas_pos.x + 20.0, canvas_pos.y + 20.0),
        IM_COL32(100, 100, 110, 255), 'Application Content')
    for i = 0, 2 do
        dl:AddRectFilled(
            ImVec2(canvas_pos.x + 20.0, canvas_pos.y + 50.0 + i * 40.0),
            ImVec2(canvas_pos.x + canvas_size.x * 0.7, canvas_pos.y + 80.0 + i * 40.0),
            IM_COL32(45, 48, 58, 255), 4.0)
    end

    if state.open then
        state.modal_time = state.modal_time + dt
        local id = state.modal_id

        -- Animate backdrop
        local backdrop = iam.TweenFloat(id, state.backdrop_id, 1.0, 0.25, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Animate modal scale and opacity
        local scale = iam.TweenFloat(id, state.scale_id, 1.0, 0.3, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        local opacity = iam.TweenFloat(id, state.opacity_id, 1.0, 0.2, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Draw backdrop
        dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
            IM_COL32(0, 0, 0, math.floor(backdrop * 150)), 4.0)

        -- Modal content
        local title = 'Confirm Action'
        local line1 = 'Are you sure you want to proceed?'
        local line2 = 'This action cannot be undone.'

        local title_size = imgui.CalcTextSizeVec(title)
        local line1_size = imgui.CalcTextSizeVec(line1)
        local line2_size = imgui.CalcTextSizeVec(line2)

        local content_width = math.max(math.max(title_size.x, line1_size.x), line2_size.x) + 48.0
        local modal_width = math.max(content_width, 300.0)
        local modal_height = 160.0

        local modal_size = ImVec2(modal_width, modal_height)
        local modal_center = ImVec2(canvas_pos.x + canvas_size.x * 0.5, canvas_pos.y + canvas_size.y * 0.5)
        local scaled_half = ImVec2(modal_size.x * 0.5 * scale, modal_size.y * 0.5 * scale)

        local modal_min = ImVec2(modal_center.x - scaled_half.x, modal_center.y - scaled_half.y)
        local modal_max = ImVec2(modal_center.x + scaled_half.x, modal_center.y + scaled_half.y)

        -- Shadow
        for s = 3, 0, -1 do
            local offset = 4.0 * (s + 1) * scale
            dl:AddRectFilled(
                ImVec2(modal_min.x + offset * 0.3, modal_min.y + offset),
                ImVec2(modal_max.x + offset * 0.3, modal_max.y + offset),
                IM_COL32(0, 0, 0, math.floor(15 * opacity)), 8.0)
        end

        -- Modal background
        dl:AddRectFilled(modal_min, modal_max, IM_COL32(50, 53, 65, math.floor(255 * opacity)), 8.0)

        -- Modal content
        local text_alpha = math.floor(255 * opacity)
        dl:AddText(ImVec2(modal_min.x + 24.0 * scale, modal_min.y + 20.0 * scale),
            IM_COL32(255, 255, 255, text_alpha), title)
        dl:AddText(ImVec2(modal_min.x + 24.0 * scale, modal_min.y + 52.0 * scale),
            IM_COL32(180, 180, 190, text_alpha), line1)
        dl:AddText(ImVec2(modal_min.x + 24.0 * scale, modal_min.y + 75.0 * scale),
            IM_COL32(140, 140, 150, text_alpha), line2)

        -- Close button
        local close_btn_min = ImVec2(modal_min.x + 24.0 * scale, modal_max.y - 50.0 * scale)
        local close_btn_max = ImVec2(modal_min.x + 110.0 * scale, modal_max.y - 18.0 * scale)
        dl:AddRectFilled(close_btn_min, close_btn_max, IM_COL32(91, 194, 231, math.floor(200 * opacity)), 6.0)

        local btn_text_size = imgui.CalcTextSizeVec('Close')
        local btn_text_x = close_btn_min.x + ((close_btn_max.x - close_btn_min.x) - btn_text_size.x) * 0.5
        local btn_text_y = close_btn_min.y + ((close_btn_max.y - close_btn_min.y) - btn_text_size.y) * 0.5
        dl:AddText(ImVec2(btn_text_x, btn_text_y), IM_COL32(255, 255, 255, text_alpha), 'Close')

        -- Handle close
        imgui.SetCursorScreenPos(close_btn_min.x, close_btn_min.y)
        if imgui.InvisibleButton('##close_modal', ImVec2(close_btn_max.x - close_btn_min.x, close_btn_max.y - close_btn_min.y)) then
            state.open = false
        end
    else
        -- Reset animations
        local id = state.modal_id
        iam.TweenFloat(id, state.backdrop_id, 0.0, 0.2, iam.EasePreset(IamEaseType.InCubic), IamPolicy.Crossfade, dt)
        iam.TweenFloat(id, state.scale_id, 0.9, 0.2, iam.EasePreset(IamEaseType.InCubic), IamPolicy.Crossfade, dt)
        iam.TweenFloat(id, state.opacity_id, 0.0, 0.15, iam.EasePreset(IamEaseType.InCubic), IamPolicy.Crossfade, dt)
    end

    imgui.Dummy(canvas_size)
end

-- ============================================================
-- USECASE 2: Notification Toast System
-- ============================================================
local toast_notifications_state = {
    active = { false, false, false },
    timers = { 0.0, 0.0, 0.0 },
    messages = {
        'Operation completed successfully!',
        'Warning: Check your settings',
        'Error: Something went wrong'
    },
    colors = {
        IM_COL32(51, 204, 102, 255),  -- Success
        IM_COL32(230, 179, 51, 255),  -- Warning
        IM_COL32(230, 77, 77, 255)    -- Error
    }
}

local function ShowUsecase_ToastNotifications()
    local state = toast_notifications_state
    imgui.TextWrapped('Toast notifications that slide in, hold, then fade out. Uses clip-based animation with stagger for multiple toasts.')

    local dt = common.GetDeltaTime()

    -- Buttons to trigger toasts
    if imgui.Button('Success Toast') then
        state.active[1] = true
        state.timers[1] = 0.0
    end
    imgui.SameLine()
    if imgui.Button('Warning Toast') then
        state.active[2] = true
        state.timers[2] = 0.0
    end
    imgui.SameLine()
    if imgui.Button('Error Toast') then
        state.active[3] = true
        state.timers[3] = 0.0
    end

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local content_avail = imgui.GetContentRegionAvailVec()
    local canvas_size = ImVec2(content_avail.x, 180)
    local dl = imgui.GetWindowDrawList()

    -- Background
    dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(20, 20, 25, 255), 4.0)

    local toast_height = 50.0
    local toast_spacing = 8.0
    local toast_padding = 32.0

    for i = 1, 3 do
        if not state.active[i] then goto toast_continue end

        state.timers[i] = state.timers[i] + dt
        local t = toast_notifications_state.timers[i]

        local slide_progress = 0.0
        local alpha = 1.0

        if t < 0.3 then
            slide_progress = iam.EvalPreset(IamEaseType.OutBack, t / 0.3)
        elseif t < 2.3 then
            slide_progress = 1.0
        elseif t < 2.6 then
            local fade_t = (t - 2.3) / 0.3
            slide_progress = 1.0
            alpha = 1.0 - iam.EvalPreset(IamEaseType.InQuad, fade_t)
        else
            state.active[i] = false
            goto toast_continue
        end

        local text_size = imgui.CalcTextSizeVec(state.messages[i])
        local toast_width = text_size.x + toast_padding

        local base_x = canvas_pos.x + canvas_size.x - toast_width - 16.0
        local base_y = canvas_pos.y + 16.0 + (i - 1) * (toast_height + toast_spacing)

        local x = base_x + (1.0 - slide_progress) * (toast_width + 32.0)
        local y = base_y

        -- Draw toast
        local bg_color = IM_COL32(40, 40, 50, math.floor(alpha * 230))

        dl:AddRectFilled(ImVec2(x, y), ImVec2(x + toast_width, y + toast_height), bg_color, 6.0)
        dl:AddRectFilled(ImVec2(x, y), ImVec2(x + 4.0, y + toast_height), state.colors[i], 6.0, ImDrawFlags.RoundCornersLeft)

        -- Text
        local text_color = IM_COL32(255, 255, 255, math.floor(alpha * 255))
        dl:AddText(ImVec2(x + 16.0, y + (toast_height - imgui.GetFontSize()) * 0.5), text_color, state.messages[i])

        ::toast_continue::
    end

    imgui.Dummy(canvas_size)
end

-- ============================================================
-- USECASE 19: Tooltip Animation
-- ============================================================
local tooltip_animation_state = {
    hovered_item = -1,
    tooltip_time = 0.0,
    items = {
        { label = '[?]', tooltip = 'This is a help icon with more information', x_offset = 0.2 },
        { label = '[i]', tooltip = 'Information tooltip with details', x_offset = 0.5 },
        { label = '[!]', tooltip = 'Warning: Important notice here', x_offset = 0.8 }
    }
}

local function ShowUsecase_TooltipAnimation()
    local state = tooltip_animation_state
    imgui.TextWrapped('Smooth tooltip animations that slide in with a slight bounce. Enhances UX by providing context without jarring popups.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local content_avail = imgui.GetContentRegionAvailVec()
    local canvas_size = ImVec2(content_avail.x, 100)

    -- Background
    dl:AddRectFilled(pos, ImVec2(pos.x + canvas_size.x, pos.y + canvas_size.y),
        IM_COL32(25, 27, 35, 255), 4.0)

    -- Interactive elements
    local new_hovered = -1
    local hover_radius = 18.0

    for i = 0, 2 do
        local item = state.items[i + 1]
        local text_size = imgui.CalcTextSizeVec(item.label)
        local item_center = ImVec2(pos.x + canvas_size.x * item.x_offset, pos.y + canvas_size.y * 0.5)
        local item_pos = ImVec2(item_center.x - text_size.x * 0.5, item_center.y - text_size.y * 0.5)

        -- Check hover using circular hit region
        local mouse = imgui.GetMousePosVec()
        local dx = mouse.x - item_center.x
        local dy = mouse.y - item_center.y
        local dist = math.sqrt(dx * dx + dy * dy)
        local item_hovered = dist < hover_radius
        if item_hovered then new_hovered = i end

        -- Draw hover disc background
        if item_hovered then
            dl:AddCircleFilled(item_center, hover_radius, IM_COL32(91, 194, 231, 40))
            dl:AddCircle(item_center, hover_radius, IM_COL32(91, 194, 231, 100), 0, 1.5)
        end

        -- Draw item text
        local text_color = item_hovered and IM_COL32(91, 194, 231, 255) or IM_COL32(150, 150, 160, 255)
        dl:AddText(item_pos, text_color, item.label)
    end

    -- Update tooltip state
    if new_hovered ~= state.hovered_item then
        state.hovered_item = new_hovered
        state.tooltip_time = 0.0
    elseif state.hovered_item >= 0 then
        state.tooltip_time = state.tooltip_time + dt
    end

    -- Draw tooltip
    if state.hovered_item >= 0 then
        -- Animate with delay - smooth fade without bouncing/flickering (accessibility)
        local delay = 0.15
        local anim_t = math.max(0.0, math.min((state.tooltip_time - delay) / 0.2, 1.0))
        local ease_t = iam.EvalPreset(IamEaseType.OutCubic, anim_t)  -- Smooth ease without overshoot

        if state.tooltip_time > delay then
            local item = state.items[state.hovered_item + 1]
            local anchor = ImVec2(pos.x + canvas_size.x * item.x_offset, pos.y + canvas_size.y * 0.5 - hover_radius)

            local tip_text = item.tooltip
            local text_size = imgui.CalcTextSizeVec(tip_text)
            local padding = ImVec2(12, 8)
            local tip_size = ImVec2(text_size.x + padding.x * 2, text_size.y + padding.y * 2)

            -- Position above with animation
            local y_offset = -tip_size.y - 10 + (1.0 - ease_t) * 10.0
            local tip_pos = ImVec2(anchor.x - tip_size.x * 0.5, anchor.y + y_offset)

            -- Clamp to canvas
            if tip_pos.x < pos.x then
                tip_pos = ImVec2(pos.x, tip_pos.y)
            end
            if tip_pos.x + tip_size.x > pos.x + canvas_size.x then
                tip_pos = ImVec2(pos.x + canvas_size.x - tip_size.x, tip_pos.y)
            end

            local alpha = math.floor(255 * ease_t)

            -- Shadow
            dl:AddRectFilled(ImVec2(tip_pos.x + 2, tip_pos.y + 3),
                ImVec2(tip_pos.x + tip_size.x + 2, tip_pos.y + tip_size.y + 3),
                IM_COL32(0, 0, 0, math.floor(alpha / 4)), 6.0)

            -- Background
            dl:AddRectFilled(tip_pos, ImVec2(tip_pos.x + tip_size.x, tip_pos.y + tip_size.y),
                IM_COL32(50, 54, 65, alpha), 6.0)

            -- Arrow
            local arrow_tip = ImVec2(anchor.x, tip_pos.y + tip_size.y + 6)
            local arrow_left = ImVec2(anchor.x - 6, tip_pos.y + tip_size.y)
            local arrow_right = ImVec2(anchor.x + 6, tip_pos.y + tip_size.y)
            dl:AddTriangleFilled(arrow_left, arrow_right, arrow_tip, IM_COL32(50, 54, 65, alpha))

            -- Text
            dl:AddText(ImVec2(tip_pos.x + padding.x, tip_pos.y + padding.y),
                IM_COL32(220, 220, 230, alpha), tip_text)
        end
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + canvas_size.y + 8)
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- USECASE: Popover Menu
-- ============================================================
local popover_menu_state = {
    show_popover = false,
    popover_time = 0.0,
    popover_id = ImHashStr('popover'),
    expand_id = ImHashStr('popover_expand'),
    item_fade_ids = {
        ImHashStr('popover_item_0'),
        ImHashStr('popover_item_1'),
        ImHashStr('popover_item_2'),
        ImHashStr('popover_item_3'),
    },
    items = { 'Edit', 'Duplicate', 'Share', 'Delete' },
    colors = {
        IM_COL32(255, 255, 255, 255),
        IM_COL32(255, 255, 255, 255),
        IM_COL32(100, 180, 255, 255),
        IM_COL32(255, 100, 100, 255)
    }
}

local function ShowUsecase_PopoverMenu()
    local state = popover_menu_state

    imgui.TextWrapped('Animated popover menu that expands from a button click. Items fade in with staggered timing.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain

    local btn_pos = imgui.GetCursorScreenPosVec()
    if imgui.Button('Options##PopoverTrigger') then
        state.show_popover = not state.show_popover
    end

    local dl = imgui.GetWindowDrawList()
    local popover_pos = ImVec2(btn_pos.x, btn_pos.y + 30 * scale)

    if state.show_popover then
        state.popover_time = state.popover_time + dt

        local expand = iam.TweenFloat(state.popover_id, state.expand_id,
            1.0, 0.2, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        local popover_size = ImVec2(140 * scale, 120 * scale * expand)

        -- Background
        dl:AddRectFilled(popover_pos,
            ImVec2(popover_pos.x + popover_size.x, popover_pos.y + popover_size.y),
            IM_COL32(55, 60, 70, 250), 8 * scale)
        dl:AddRect(popover_pos,
            ImVec2(popover_pos.x + popover_size.x, popover_pos.y + popover_size.y),
            IM_COL32(80, 85, 95, 255), 8 * scale)

        -- Menu items with staggered fade
        for i = 0, 3 do
            local delay = i * 0.05
            local item_alpha = state.popover_time > delay and
                iam.TweenFloat(state.popover_id, state.item_fade_ids[i + 1],
                    1.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt) or 0.0

            if expand > 0.3 + i * 0.15 then
                local y = popover_pos.y + 10 * scale + i * 26 * scale
                local col = state.colors[i + 1]
                local r = bit32.band(col, 0xFF)
                local g = bit32.band(bit32.rshift(col, 8), 0xFF)
                local b = bit32.band(bit32.rshift(col, 16), 0xFF)
                col = IM_COL32(r, g, b, math.floor(item_alpha * 255))
                dl:AddText(ImVec2(popover_pos.x + 15 * scale, y), col, state.items[i + 1])
            end
        end

        -- Close when clicking outside
        local mouse = imgui.GetMousePosVec()
        if imgui.IsMouseClicked(0) and
            (mouse.x < popover_pos.x or mouse.x > popover_pos.x + popover_size.x or
             mouse.y < popover_pos.y or mouse.y > popover_pos.y + popover_size.y) then
            if mouse.x < btn_pos.x or mouse.x > btn_pos.x + 60 * scale or
               mouse.y < btn_pos.y or mouse.y > btn_pos.y + 25 * scale then
                state.show_popover = false
                state.popover_time = 0.0
            end
        end
    else
        iam.TweenFloat(state.popover_id, state.expand_id, 0.0, 0.15,
            iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
        state.popover_time = 0.0
    end

    imgui.Dummy(ImVec2(0, popover_menu_state.show_popover and 130 * scale or 0))
end

-- ============================================================
-- USECASE: Alert Banner
-- ============================================================
local alert_banner_state = {
    alert_type = -1,
    alert_timer = 0.0,
    alert_id = ImHashStr('alert'),
    slide_id = ImHashStr('alert_slide'),
    messages = {
        'Information: This is an info message.',
        'Success: Operation completed successfully!',
        'Warning: Please review before continuing.',
        'Error: Something went wrong!'
    },
    icons = { 'i', '+', '!', 'X' },
    bg_colors = {
        IM_COL32(33, 150, 243, 230),   -- Info
        IM_COL32(76, 175, 80, 230),    -- Success
        IM_COL32(255, 152, 0, 230),    -- Warning
        IM_COL32(244, 67, 54, 230)     -- Error
    }
}

local function ShowUsecase_AlertBanner()
    local state = alert_banner_state

    imgui.TextWrapped('Animated alert banners that slide in from top with different severity levels. Auto-dismiss with progress indicator.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain

    if imgui.Button('Info##AlertBtn') then
        state.alert_type = 0
        state.alert_timer = 0.0
    end
    imgui.SameLine()
    if imgui.Button('Success##AlertBtn') then
        state.alert_type = 1
        state.alert_timer = 0.0
    end
    imgui.SameLine()
    if imgui.Button('Warning##AlertBtn') then
        state.alert_type = 2
        state.alert_timer = 0.0
    end
    imgui.SameLine()
    if imgui.Button('Error##AlertBtn') then
        state.alert_type = 3
        state.alert_timer = 0.0
    end

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local content_avail = imgui.GetContentRegionAvailVec()
    local canvas_size = ImVec2(content_avail.x, 80 * scale)
    local dl = imgui.GetWindowDrawList()

    dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(30, 32, 38, 255), 4 * scale)

    if state.alert_type >= 0 then
        state.alert_timer = state.alert_timer + dt

        local slide = iam.TweenFloat(state.alert_id, state.slide_id,
            1.0, 0.3, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        local banner_size = ImVec2(canvas_size.x - 20 * scale, 50 * scale)
        local y_offset = (1.0 - slide) * -60 * scale
        local banner_pos = ImVec2(canvas_pos.x + 10 * scale, canvas_pos.y + 15 * scale + y_offset)

        -- Banner background
        dl:AddRectFilled(banner_pos,
            ImVec2(banner_pos.x + banner_size.x, banner_pos.y + banner_size.y),
            state.bg_colors[state.alert_type + 1], 8 * scale)

        -- Icon
        local icon_center = ImVec2(banner_pos.x + 25 * scale, banner_pos.y + banner_size.y * 0.5)
        dl:AddCircleFilled(icon_center, 12 * scale, IM_COL32(255, 255, 255, 60))
        dl:AddText(ImVec2(icon_center.x - 4 * scale, icon_center.y - 7 * scale),
            IM_COL32(255, 255, 255, 255), state.icons[state.alert_type + 1])

        -- Message
        dl:AddText(ImVec2(banner_pos.x + 50 * scale, banner_pos.y + 17 * scale),
            IM_COL32(255, 255, 255, 255), state.messages[state.alert_type + 1])

        -- Progress bar
        local progress = math.min(math.max(state.alert_timer / 3.0, 0.0), 1.0)
        local bar_width = banner_size.x * (1.0 - progress)
        dl:AddRectFilled(
            ImVec2(banner_pos.x, banner_pos.y + banner_size.y - 4 * scale),
            ImVec2(banner_pos.x + bar_width, banner_pos.y + banner_size.y),
            IM_COL32(255, 255, 255, 100), 0, ImDrawFlags.RoundCornersBottom)

        if state.alert_timer >= 3.0 then
            state.alert_type = -1
        end
    else
        iam.TweenFloat(state.alert_id, state.slide_id, 0.0, 0.2,
            iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
    end

    imgui.Dummy(canvas_size)
end

-- ============================================================
-- USECASE: Bottom Sheet
-- ============================================================
local bottom_sheet_state = {
    open = false,
    sheet_id = ImHashStr('bottom_sheet'),
    sheet_y_id = ImHashStr('sheet_y'),
}

local function ShowUsecase_BottomSheet()
    local state = bottom_sheet_state

    imgui.TextWrapped('iOS-style bottom sheet that slides up from bottom.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local container_size = ImVec2(280 * scale, 180 * scale)

    -- Container
    dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
        IM_COL32(30, 35, 45, 255), 8 * scale)

    -- Clip content
    dl:PushClipRect(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y), true)

    -- Toggle button
    imgui.SetCursorScreenPos(pos.x + 10 * scale, pos.y + 10 * scale)
    if imgui.Button('Show Sheet') then
        state.open = true
    end

    -- Sheet animation
    local sheet_height = 120 * scale
    local sheet_y = iam.TweenFloat(state.sheet_id, state.sheet_y_id,
        state.open and container_size.y - sheet_height or container_size.y, 0.3, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    -- Backdrop
    if sheet_y < container_size.y - 1 then
        local backdrop_alpha = (container_size.y - sheet_y - 1) / sheet_height * 0.5
        dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
            IM_COL32(0, 0, 0, math.floor(backdrop_alpha * 255)))
    end

    -- Sheet
    local sheet_pos = ImVec2(pos.x, pos.y + sheet_y)
    dl:AddRectFilled(sheet_pos, ImVec2(sheet_pos.x + container_size.x, sheet_pos.y + sheet_height),
        IM_COL32(50, 55, 65, 255), 12 * scale, ImDrawFlags.RoundCornersTop)

    -- Handle
    dl:AddRectFilled(
        ImVec2(sheet_pos.x + container_size.x * 0.5 - 20 * scale, sheet_pos.y + 8 * scale),
        ImVec2(sheet_pos.x + container_size.x * 0.5 + 20 * scale, sheet_pos.y + 12 * scale),
        IM_COL32(100, 100, 110, 255), 2 * scale)

    -- Content
    if sheet_y < container_size.y - 10 then
        dl:AddText(ImVec2(sheet_pos.x + 15 * scale, sheet_pos.y + 30 * scale),
            IM_COL32(255, 255, 255, 255), 'Bottom Sheet')
        dl:AddText(ImVec2(sheet_pos.x + 15 * scale, sheet_pos.y + 55 * scale),
            IM_COL32(150, 150, 160, 255), 'Swipe down or tap backdrop')

        imgui.SetCursorScreenPos(sheet_pos.x + 15 * scale, sheet_pos.y + 80 * scale)
        if imgui.Button('Close##sheet') then
            state.open = false
        end
    end

    dl:PopClipRect()

    imgui.SetCursorScreenPos(pos.x, pos.y + container_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Cookie Consent Banner
-- ============================================================
local consent_banner_state = {
    show_banner = true,
    accepted = false,
    banner_id = ImHashStr('consent_banner'),
    banner_y_id = ImHashStr('cookie_banner_y'),
    wobble_id = ImHashStr('cookie_wobble'),
    btn_hover_ids = {
        ImHashStr('btn_accept_hover'),
        ImHashStr('btn_decline_hover'),
        ImHashStr('btn_settings_hover'),
    },
    btn_hovers = { 0.0, 0.0, 0.0 },
    button_labels = { 'Accept', 'Decline', 'Settings' },
    button_colors = {
        IM_COL32(76, 175, 80, 255),
        IM_COL32(100, 100, 110, 255),
        IM_COL32(70, 130, 180, 255)
    }
}

local function ShowUsecase_Snackbar()
    local state = consent_banner_state

    imgui.TextWrapped('Animated cookie consent banner with slide-up entrance and button hover effects.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local container_size = ImVec2(700 * scale, 350 * scale)

    -- Container (simulated webpage)
    dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
        IM_COL32(45, 50, 60, 255), 10 * scale)
    dl:PushClipRect(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y), true)

    -- Simulated page content - larger text and more lines
    dl:AddText(ImVec2(pos.x + 25 * scale, pos.y + 25 * scale),
        IM_COL32(200, 200, 210, 255), 'Welcome to Our Website')
    for i = 0, 4 do
        dl:AddRectFilled(
            ImVec2(pos.x + 25 * scale, pos.y + 60 * scale + i * 28 * scale),
            ImVec2(pos.x + container_size.x - 25 * scale, pos.y + 75 * scale + i * 28 * scale),
            IM_COL32(70, 75, 85, 255), 3 * scale)
    end

    -- Reset button
    if not state.show_banner then
        imgui.SetCursorScreenPos(pos.x + 20 * scale, pos.y + container_size.y - 50 * scale)
        if imgui.Button('Reset Banner') then
            state.show_banner = true
            state.accepted = false
        end
    end

    -- Banner slide-up animation - much taller banner
    local banner_height = 160 * scale
    local target_y = state.show_banner and (container_size.y - banner_height) or container_size.y
    local banner_y = iam.TweenFloat(state.banner_id, state.banner_y_id,
        target_y, 0.4, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    if banner_y < container_size.y - 1 then
        local banner_pos = ImVec2(pos.x, pos.y + banner_y)

        -- Banner background with gradient effect
        dl:AddRectFilled(banner_pos,
            ImVec2(banner_pos.x + container_size.x, banner_pos.y + banner_height),
            IM_COL32(30, 35, 50, 250), 12 * scale, ImDrawFlags.RoundCornersTop)

        -- Cookie icon (animated wobble) - larger
        local wobble = iam.Oscillate(state.wobble_id, 0.1, 2.0, 0, 0.0, dt)
        local cookie_center = ImVec2(banner_pos.x + 55 * scale, banner_pos.y + 55 * scale)
        local cookie_r = 30 * scale
        dl:AddCircleFilled(cookie_center, cookie_r, IM_COL32(210, 160, 90, 255))

        -- Cookie chips - larger
        for i = 0, 5 do
            local angle = (i * 1.1) + wobble
            local dist = (i % 2 == 0) and (12 * scale) or (18 * scale)
            local chip = ImVec2(cookie_center.x + math.cos(angle) * dist, cookie_center.y + math.sin(angle) * dist)
            dl:AddCircleFilled(chip, 5 * scale, IM_COL32(120, 80, 40, 255))
        end

        -- Text - better positioned with more spacing
        local text_x = banner_pos.x + 100 * scale
        dl:AddText(ImVec2(text_x, banner_pos.y + 20 * scale),
            IM_COL32(255, 255, 255, 255), 'We use cookies')
        dl:AddText(ImVec2(text_x, banner_pos.y + 50 * scale),
            IM_COL32(160, 165, 180, 255), 'This site uses cookies to improve your browsing experience.')
        dl:AddText(ImVec2(text_x, banner_pos.y + 75 * scale),
            IM_COL32(160, 165, 180, 255), 'By clicking Accept, you agree to our use of cookies.')

        -- Buttons with hover animation - larger buttons
        -- (using state.button_labels and state.button_colors defined in state table)

        local btn_x = text_x
        local btn_y = banner_pos.y + 110 * scale

        for i = 1, 3 do
            local text_size = imgui.CalcTextSizeVec(state.button_labels[i])
            local btn_w = text_size.x + 32 * scale  -- More padding
            local btn_h = 32 * scale  -- Taller buttons

            imgui.SetCursorScreenPos(btn_x, btn_y)
            imgui.PushID(i - 1)
            local hovered = imgui.IsMouseHoveringRect(ImVec2(btn_x, btn_y), ImVec2(btn_x + btn_w, btn_y + btn_h))

            -- Animate hover
            local hover_val = iam.TweenFloat(state.banner_id, state.btn_hover_ids[i],
                hovered and 1.0 or 0.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
            state.btn_hovers[i] = hover_val

            local btn_scale = 1.0 + hover_val * 0.08
            local scaled_w = btn_w * btn_scale
            local scaled_h = btn_h * btn_scale
            local offset_x = (scaled_w - btn_w) * 0.5
            local offset_y = (scaled_h - btn_h) * 0.5

            -- Button background with hover color brightening
            local col = state.button_colors[i]
            if hover_val > 0.01 then
                local r = bit32.band(col, 0xFF)
                local g = bit32.band(bit32.rshift(col, 8), 0xFF)
                local b = bit32.band(bit32.rshift(col, 16), 0xFF)
                r = math.min(255, math.floor(r + 30 * hover_val))
                g = math.min(255, math.floor(g + 30 * hover_val))
                b = math.min(255, math.floor(b + 30 * hover_val))
                col = IM_COL32(r, g, b, 255)
            end

            dl:AddRectFilled(
                ImVec2(btn_x - offset_x, btn_y - offset_y),
                ImVec2(btn_x + scaled_w - offset_x, btn_y + scaled_h - offset_y),
                col, 6 * scale)

            -- Button text - centered
            dl:AddText(
                ImVec2(btn_x + (btn_w - text_size.x) * 0.5 - offset_x, btn_y + (btn_h - imgui.GetFontSize()) * 0.5 - offset_y),
                IM_COL32(255, 255, 255, 255), state.button_labels[i])

            if imgui.InvisibleButton('btn', ImVec2(btn_w, btn_h)) then
                if i == 1 then
                    state.accepted = true
                    state.show_banner = false
                elseif i == 2 then
                    state.show_banner = false
                end
            end
            imgui.PopID()

            btn_x = btn_x + btn_w + 15 * scale  -- More gap between buttons
        end
    end

    dl:PopClipRect()
    imgui.SetCursorScreenPos(pos.x, pos.y + container_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Lightbox
-- ============================================================
local lightbox_state = {
    open = false,
    lightbox_id = ImHashStr('lightbox'),
    scale_id = ImHashStr('lightbox_scale'),
}

local function ShowUsecase_Lightbox()
    local state = lightbox_state

    imgui.TextWrapped('Image lightbox overlay with zoom animation.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local container_size = ImVec2(300 * scale, 150 * scale)

    -- Container
    dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
        IM_COL32(30, 35, 45, 255), 4 * scale)

    -- Thumbnail grid
    local thumb_size = 50 * scale
    for i = 0, 3 do
        local thumb_pos = ImVec2(pos.x + 15 * scale + i * (thumb_size + 10 * scale), pos.y + 15 * scale)
        local thumb_col = IM_COL32(100 + i * 30, 80 + i * 20, 120, 255)
        dl:AddRectFilled(thumb_pos, ImVec2(thumb_pos.x + thumb_size, thumb_pos.y + thumb_size), thumb_col, 4 * scale)

        imgui.SetCursorScreenPos(thumb_pos.x, thumb_pos.y)
        imgui.PushID(i)
        if imgui.InvisibleButton('thumb', ImVec2(thumb_size, thumb_size)) then
            state.open = true
        end
        imgui.PopID()
    end

    -- Lightbox overlay
    local lb_scale = iam.TweenFloat(state.lightbox_id, state.scale_id,
        state.open and 1.0 or 0.0, 0.25, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    if lb_scale > 0.01 then
        -- Backdrop
        dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
            IM_COL32(0, 0, 0, math.floor(lb_scale * 200)))

        -- Image
        local img_size = 100 * scale * lb_scale
        local img_pos = ImVec2(pos.x + (container_size.x - img_size) * 0.5, pos.y + (container_size.y - img_size) * 0.5)
        dl:AddRectFilled(img_pos, ImVec2(img_pos.x + img_size, img_pos.y + img_size),
            IM_COL32(130, 100, 150, 255), 8 * scale)

        -- Close button
        local close_radius = 12 * scale * lb_scale
        local close_center = ImVec2(img_pos.x + img_size - 15 * scale * lb_scale, img_pos.y + 15 * scale * lb_scale)
        dl:AddCircleFilled(close_center, close_radius, IM_COL32(200, 60, 60, math.floor(lb_scale * 255)))

        -- Draw X inside circle
        local x_size = 5 * scale * lb_scale
        dl:AddLine(ImVec2(close_center.x - x_size, close_center.y - x_size),
            ImVec2(close_center.x + x_size, close_center.y + x_size),
            IM_COL32(255, 255, 255, math.floor(lb_scale * 255)), 2 * scale)
        dl:AddLine(ImVec2(close_center.x + x_size, close_center.y - x_size),
            ImVec2(close_center.x - x_size, close_center.y + x_size),
            IM_COL32(255, 255, 255, math.floor(lb_scale * 255)), 2 * scale)

        -- Invisible button aligned with circle
        imgui.SetCursorScreenPos(close_center.x - close_radius, close_center.y - close_radius)
        if imgui.InvisibleButton('close_lb', ImVec2(close_radius * 2, close_radius * 2)) then
            state.open = false
        end
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + container_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Command Palette
-- ============================================================
local command_palette_state = {
    open = false,
    palette_id = ImHashStr('command_palette'),
    scale_id = ImHashStr('palette_scale'),
    alpha_id = ImHashStr('palette_alpha'),
    commands = {
        'New File',
        'Open Project',
        'Save All',
        'Find in Files',
        'Git Commit'
    }
}

local function ShowUsecase_CommandPalette()
    local state = command_palette_state

    imgui.TextWrapped('Spotlight/Command-K style search palette.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local container_size = ImVec2(380 * scale, 200 * scale)

    -- Container
    dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
        IM_COL32(30, 35, 45, 255), 4 * scale)

    -- Trigger
    imgui.SetCursorScreenPos(pos.x + 10 * scale, pos.y + 10 * scale)
    if imgui.Button('Press Ctrl/Cmd + K') or (imgui.IsKeyPressed(ImGuiKey.K) and imgui.GetIO().KeyCtrl) then
        state.open = not state.open
    end

    -- Palette animation
    local palette_scale = iam.TweenFloat(state.palette_id, state.scale_id,
        state.open and 1.0 or 0.8, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
    local palette_alpha = iam.TweenFloat(state.palette_id, state.alpha_id,
        state.open and 1.0 or 0.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    if palette_alpha > 0.01 then
        -- Backdrop
        dl:AddRectFilled(pos, ImVec2(pos.x + container_size.x, pos.y + container_size.y),
            IM_COL32(0, 0, 0, math.floor(palette_alpha * 150)))

        -- Palette
        local pal_width = 250 * scale * palette_scale
        local pal_height = 150 * scale
        local pal_pos = ImVec2(pos.x + (container_size.x - pal_width) * 0.5, pos.y + 30 * scale)

        dl:AddRectFilled(pal_pos, ImVec2(pal_pos.x + pal_width, pal_pos.y + pal_height),
            IM_COL32(45, 50, 60, math.floor(palette_alpha * 255)), 8 * scale)

        -- Search box
        dl:AddRectFilled(
            ImVec2(pal_pos.x + 10 * scale, pal_pos.y + 10 * scale),
            ImVec2(pal_pos.x + pal_width - 10 * scale, pal_pos.y + 35 * scale),
            IM_COL32(35, 40, 50, math.floor(palette_alpha * 255)), 4 * scale)
        dl:AddText(ImVec2(pal_pos.x + 15 * scale, pal_pos.y + 15 * scale),
            IM_COL32(100, 100, 110, math.floor(palette_alpha * 255)), 'Type a command...')

        -- Commands
        local cmd_count = #state.commands
        for i = 1, math.min(cmd_count, 4) do
            local item_y = pal_pos.y + 45 * scale + (i - 1) * 25 * scale
            dl:AddText(ImVec2(pal_pos.x + 15 * scale, item_y),
                IM_COL32(200, 200, 210, math.floor(palette_alpha * 255)), state.commands[i])
        end
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + container_size.y + 10 * scale)
end

-- ============================================================
-- USECASE: Inline Confirmation
-- ============================================================
local inline_confirmation_state = {
    confirming = false,
    confirm_id = ImHashStr('inline_confirm'),
    width_id = ImHashStr('confirm_width'),
    button_hovers = {
        delete_hover = 0.0,
        confirm_hover = 0.0,
        cancel_hover = 0.0,
    }
}

local function ShowUsecase_InlineConfirmation()
    local state = inline_confirmation_state

    imgui.TextWrapped('Inline delete confirmation that expands in place with hover effects.')

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    local pos = imgui.GetCursorScreenPosVec()
    local btn_height = 35 * scale
    local padding = 20 * scale
    local gap = 15 * scale  -- Gap between Confirm and Cancel

    -- Calculate text sizes for proper button widths
    local delete_size = imgui.CalcTextSizeVec('Delete')
    local confirm_size = imgui.CalcTextSizeVec('Confirm')
    local cancel_size = imgui.CalcTextSizeVec('Cancel')

    local collapsed_width = delete_size.x + padding * 2
    local confirm_btn_width = confirm_size.x + padding * 2
    local cancel_btn_width = cancel_size.x + padding * 2
    local expanded_total = confirm_btn_width + gap + cancel_btn_width

    -- Width animation
    local target_width = state.confirming and expanded_total or collapsed_width
    local animated_width = iam.TweenFloat(state.confirm_id, state.width_id,
        target_width, 0.2, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt, collapsed_width)

    -- Background
    local bg_col = state.confirming and IM_COL32(180, 60, 60, 255) or IM_COL32(60, 65, 75, 255)
    dl:AddRectFilled(pos, ImVec2(pos.x + animated_width, pos.y + btn_height), bg_col, 4 * scale)

    if not state.confirming then
        -- Delete button hover detection
        imgui.SetCursorScreenPos(pos.x, pos.y)
        imgui.InvisibleButton('delete_btn', ImVec2(animated_width, btn_height))
        local del_hovered = imgui.IsItemHovered()
        if imgui.IsItemClicked() then
            state.confirming = true
        end

        -- Animate delete button hover
        state.button_hovers.delete_hover = iam.TweenFloat(state.confirm_id, ImHashStr('dh'),
            del_hovered and 1.0 or 0.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

        -- Hover highlight
        if state.button_hovers.delete_hover > 0.01 then
            dl:AddRectFilled(pos, ImVec2(pos.x + animated_width, pos.y + btn_height),
                IM_COL32(255, 255, 255, math.floor(30 * state.button_hovers.delete_hover)), 4 * scale)
        end

        -- Center "Delete" text in button
        local text_x = pos.x + (animated_width - delete_size.x) * 0.5
        dl:AddText(ImVec2(text_x, pos.y + (btn_height - delete_size.y) * 0.5),
            IM_COL32(255, 255, 255, 255), 'Delete')
    else
        local mouse = imgui.GetMousePosVec()
        local cancel_start_x = pos.x + confirm_btn_width + gap

        -- Check hover for each button
        local confirm_hovered = (mouse.x >= pos.x and mouse.x < pos.x + confirm_btn_width and
            mouse.y >= pos.y and mouse.y < pos.y + btn_height)
        local cancel_hovered = (mouse.x >= cancel_start_x and mouse.x < cancel_start_x + cancel_btn_width and
            mouse.y >= pos.y and mouse.y < pos.y + btn_height)

        -- Animate hover states
        state.button_hovers.confirm_hover = iam.TweenFloat(state.confirm_id, ImHashStr('ch'),
            confirm_hovered and 1.0 or 0.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
        state.button_hovers.cancel_hover = iam.TweenFloat(state.confirm_id, ImHashStr('cah'),
            cancel_hovered and 1.0 or 0.0, 0.15, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

        -- Confirm button hover highlight
        if state.button_hovers.confirm_hover > 0.01 then
            dl:AddRectFilled(pos, ImVec2(pos.x + confirm_btn_width, pos.y + btn_height),
                IM_COL32(255, 255, 255, math.floor(40 * state.button_hovers.confirm_hover)), 4 * scale, ImDrawFlags.RoundCornersLeft)
        end

        -- Cancel button hover highlight
        if state.button_hovers.cancel_hover > 0.01 then
            dl:AddRectFilled(ImVec2(cancel_start_x, pos.y),
                ImVec2(cancel_start_x + cancel_btn_width, pos.y + btn_height),
                IM_COL32(255, 255, 255, math.floor(40 * state.button_hovers.cancel_hover)), 4 * scale, ImDrawFlags.RoundCornersRight)
        end

        -- Center "Confirm" text in its section
        local confirm_text_x = pos.x + (confirm_btn_width - confirm_size.x) * 0.5
        dl:AddText(ImVec2(confirm_text_x, pos.y + (btn_height - confirm_size.y) * 0.5),
            IM_COL32(255, 255, 255, 255), 'Confirm')

        -- Center "Cancel" text in its section
        local cancel_text_x = cancel_start_x + (cancel_btn_width - cancel_size.x) * 0.5
        dl:AddText(ImVec2(cancel_text_x, pos.y + (btn_height - cancel_size.y) * 0.5),
            IM_COL32(255, 255, 255, 255), 'Cancel')

        -- Handle clicks
        imgui.SetCursorScreenPos(pos.x, pos.y)
        imgui.InvisibleButton('conf_area', ImVec2(animated_width, btn_height))
        if imgui.IsItemClicked() then
            if mouse.x < pos.x + confirm_btn_width then
                state.confirming = false
                -- Action would be performed here
            else
                state.confirming = false
            end
        end
    end

    imgui.SetCursorScreenPos(pos.x, pos.y + btn_height + 10 * scale)
end

local function RunDialogsAndModalsDemo()
    -- ========================================
    -- DIALOGS & MODALS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Dialogs & Modals") then
        imgui.Indent()
        common.USECASE_ITEM('Modal Dialog', ShowUsecase_ModalDialog)
        common.USECASE_ITEM('Toast Notifications', ShowUsecase_ToastNotifications)
        common.USECASE_ITEM('Tooltip Animation', ShowUsecase_TooltipAnimation)
        common.USECASE_ITEM('Popover Menu', ShowUsecase_PopoverMenu)
        common.USECASE_ITEM('Alert Banner', ShowUsecase_AlertBanner)
        common.USECASE_ITEM('Bottom Sheet', ShowUsecase_BottomSheet)
        common.USECASE_ITEM('Consent Banner', ShowUsecase_Snackbar)
        common.USECASE_ITEM('Lightbox', ShowUsecase_Lightbox)
        common.USECASE_ITEM('Command Palette', ShowUsecase_CommandPalette)
        common.USECASE_ITEM('Inline Confirmation', ShowUsecase_InlineConfirmation)
        imgui.Unindent()
    end
end

return RunDialogsAndModalsDemo
