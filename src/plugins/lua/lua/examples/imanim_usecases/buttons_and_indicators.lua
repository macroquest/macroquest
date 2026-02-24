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
    local fill_color = IM_COL32(91, 194, 231, fill_alpha * 255)
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
    dl:AddCircleFilled(center, btn_size.x * 0.5, IM_COL32(255, 255, 255, bg_alpha * 255))

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
local function ShowUsecase_ProgressBar()
    -- TODO: Implement Progress Bar with Segments
end

-- ============================================================
-- USECASE 20: Pulse Notification Badge
-- ============================================================
local function ShowUsecase_PulseBadge()
    -- TODO: Implement Pulse Notification Badge
end

-- ============================================================
-- 36. Pending Button
-- Button with loading spinner when processing
-- ============================================================
local function ShowUsecase_PendingButton()
    -- TODO: Implement Pending Button
end

-- ============================================================
-- 37. Animated Slider
-- Custom slider with smooth thumb and track animation
-- ============================================================
local function ShowUsecase_AnimatedSlider()
    -- TODO: Implement Animated Slider
end

-- ============================================================
-- USECASE: Icon Button Rotation
-- ============================================================
local function ShowUsecase_IconButtonRotation()
    -- TODO: Implement Icon Button Rotation
end

-- ============================================================
-- USECASE: Like Heart Button
-- ============================================================
local function ShowUsecase_LikeHeartButton()
    -- TODO: Implement Like Heart Button
end

-- ============================================================
-- USECASE: Button Glow Effect
-- ============================================================
local function ShowUsecase_ButtonGlow()
    -- TODO: Implement Button Glow Effect
end

-- ============================================================
-- USECASE: Download Progress Button
-- ============================================================
local function ShowUsecase_DownloadProgressButton()
    -- TODO: Implement Download Progress Button
end

-- ============================================================
-- USECASE: Submit Button States
-- ============================================================
local function ShowUsecase_SubmitButtonStates()
    -- TODO: Implement Submit Button States
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
