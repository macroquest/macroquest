-- imanim_demo.lua — Mockup UI usecases showcasing im_anim.h in real-world scenarios.
-- Ported from im_anim_usecases.cpp
-- Original Author: Soufiane KHIAT
--
-- Usage: /lua run examples/imanim_usecases

local mq = require('mq')
local imgui = require('ImGui')
local iam = require('ImAnim')

local openGUI, showGUI = true, true
local s_open_all = 0

local function GetSafeDeltaTime()
    local dt = imgui.GetIO().DeltaTime
    if dt <= 0 then dt = 1.0 / 60.0 end
    if dt > 0.1 then dt = 0.1 end
    return dt
end

local function ColorAlpha(col, a)
    return bit32.bor(bit32.band(col, 0xffffff), bit32.lshift(a, 24))
end

local function ShowUsecase_FABButton()
    imgui.TextWrapped("Floating action button that expands into a radial arc menu. Uses staggered animations for child buttons.")

    local dt = GetSafeDeltaTime()
    local dl = imgui.GetWindowDrawList()

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(imgui.GetContentRegionAvailVec().x, 180)

    -- Background
	dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y), IM_COL32(25, 27, 35, 255), 4.0)

    -- FAB position (bottom-right corner)
    local fab_center = ImVec2(cp.x + cs.x - 50.0, cp.y + cs.y - 50.0);
    local fab_radius = 28.0

    local id = imgui.GetID('fab')

    -- Animate FAB rotation
    local target_rotation = fab_open and 45.0 or 0.0
    local fab_rotation = iam.TweenFloat(id, imgui.GetID('rotation'), target_rotation, 0.25,
            iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    -- Child button positions (arc going up-left from bottom-right)
    local child_count = 4
    local child_icons = {'A', 'B', 'C', 'D'}
    local child_colors = {
        IM_COL32(230, 102, 102, 255),
        IM_COL32(102, 204, 102, 255),
        IM_COL32(102, 153, 230, 255),
        IM_COL32(230, 179, 77, 255),
    }
    local child_radius = 22
    local arc_radius = 80

    -- Arc from 180 degrees (left) to 270 degrees (up) - upper-left quadrant
    local start_angle = 3.14159 -- 180 degrees (pointing left)
    local end_angle = 3.14159 * 1.5 -- 270 degrees (pointing up)

    -- Track hover state for each child
    local child_hovered = { false, false, false, false }

    -- Draw child buttons (arc pattern)
    for i=1,4,1 do
        -- Calculate angle for this button
        local angle_t = (i-1) / (child_count-1)
        local angle = start_angle + (end_angle - start_angle) * angle_t

        -- Staggered animation
        local stagger_delay = i * 0.05
        local target_dist = fab_open and arc_radius or 0.0
        local target_alpha = fab_open and 1.0 or 0.0
        local target_scale = fab_open and 1.0 or 0.5

        local child_id = id + i
        local dist = iam.TweenFloat(child_id, imgui.GetID('dist'), target_dist, 0.3 - stagger_delay, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)
        local alpha = iam.TweenFloat(child_id, imgui.GetID('alpha'), target_alpha, 0.2, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
        local base_scale = iam.TweenFloat(child_id, imgui.GetID('scale'), target_scale, 0.25, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        if alpha > 0.01 then
            -- Child buttons positioned in arc
            local child_center = ImVec2(fab_center.x + math.cos(angle) * dist, fab_center.y + math.sin(angle) * dist)

            -- Check hover on child button
            imgui.SetCursorScreenPos(ImVec2(child_center.x - child_radius, child_center.y - child_radius))
            local child_btn_id = '##fab_child_'..i
            imgui.InvisibleButton(child_btn_id, ImVec2(child_radius * 2, child_radius * 2))
            child_hovered[i] = imgui.IsItemHovered() and fab_open

            -- Animate hover scale
            local hover_target = child_hovered[i] and 1.2 or 1.0
            local hover_scale = iam.TweenFloat(child_id, imgui.GetID('hover'), hover_target, 0.15, iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

            local scale = base_scale * hover_scale

            -- Shadow (larger when hovered)
            local shadow_alpha = child_hovered[i] and 50.0 or 30.0
            dl:AddCircleFilled(ImVec2(child_center.x + 2, child_center.y + 3), child_radius * scale, IM_COL32(0.0, 0.0, 0.0, shadow_alpha * alpha))

            -- Glow effect on hover
            if child_hovered[i] then
                local glow_anim = iam.TweenFloat(child_id, imgui.GetID('glow'), 1.0, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
                local glow_col = child_colors[i]
                dl:AddCircleFilled(child_center, child_radius * scale + 4 * glow_anim, ColorAlpha(glow_col, 60 * alpha * glow_anim))
            else
                iam.TweenFloat(child_id, imgui.GetID('glow'), 0.0, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
            end

            -- Button
            local col = child_colors[i]
            dl:AddCircleFilled(child_center, child_radius * scale, ColorAlpha(col, 255 * alpha))

            -- Icon
            local text_x, text_y = imgui.CalcTextSize(child_icons[i])
            dl:AddText(ImVec2(child_center.x - text_x * 0.5, child_center.y - text_y * 0.5), IM_COL32(255, 255, 255, 255 * alpha), child_icons[i])
        end
    end

    -- Main FAB button
    imgui.SetCursorScreenPos(ImVec2(fab_center.x - fab_radius, fab_center.y - fab_radius))
    if imgui.InvisibleButton('##fab', ImVec2(fab_radius * 2, fab_radius * 2)) then
        fab_open = not fab_open
    end

    local hovered = imgui.IsItemHovered()

    -- FAB hover animation
    local target_fab_scale = hovered and 1.1 or 1.0
    local fab_scale = iam.TweenFloat(id, imgui.GetID('scale'), target_fab_scale, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Shadow
    dl:AddCircleFilled(ImVec2(fab_center.x + 2, fab_center.y + 4), fab_radius * fab_scale, IM_COL32(0.0, 0.0, 0.0, 40))
    -- FAB background
    dl:AddCircleFilled(fab_center, fab_radius * fab_scale, IM_COL32(91, 194, 231, 255))

    -- Rotated plus icon
    local rad = fab_rotation * 3.14159 / 180.0
    local icon_size = 12.0
    local c = math.cos(rad)
    local s = math.sin(rad)

    local h1 = ImVec2(fab_center.x - icon_size * c, fab_center.y - icon_size * s)
    local h2 = ImVec2(fab_center.x + icon_size * c, fab_center.y + icon_size * s)
    local v1 = ImVec2(fab_center.x + icon_size * s, fab_center.y - icon_size * c)
    local v2 = ImVec2(fab_center.x - icon_size * s, fab_center.y + icon_size * c)

    dl:AddLine(h1, h2, IM_COL32(255, 255, 255, 255), 3.0)
    dl:AddLine(v1, v2, IM_COL32(255, 255, 255, 255), 3.0)
end

local function DrawUseCasesUI()
    if not openGUI then
        return
    end

    openGUI, showGUI = imgui.Begin('ImAnim Usecases - UI Mockups (Lua)', openGUI)
    if showGUI then
        imgui.SetWindowSize(ImVec2(500, 700), ImGuiCond.FirstUseEver)
        
        imgui.PushStyleColor(ImGuiCol.Text, 0.4, 0.8, 0.9, 1.0)
        imgui.Text('Real World UI Animation Patterns')
        imgui.PopStyleColor()
        imgui.TextWrapped("This window showcases practical animation patterns commonly used in modern UI design. Each example demonstrates how ImAnim's tween API can create polished, responsive interfaces.")
        imgui.Separator()
        imgui.Spacing()
        
        if imgui.Button('Expand All') then s_open_all = 1 end
        imgui.SameLine()
        if imgui.Button('Collapse All') then s_open_all = -1 end
        imgui.Spacing()

        local current_open_all = s_open_all
        s_open_all = 0

        local function USECASE_ITEM(name, func)
            if current_open_all ~= 0 then imgui.SetNextItemOpen(current_open_all > 0, ImGuiCond.Always) end
            if imgui.TreeNode(name) then func() imgui.TreePop() end
            imgui.Spacing()
        end

        -- ================================
        -- BUTTONS & INDICATORS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Buttons & Indicators") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- NAVIGATION & MENUS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Navigation & Menus") then
            imgui.Indent()
            USECASE_ITEM('FAB Menu', ShowUsecase_FABButton)
            imgui.Unindent()
        end

        -- ================================
        -- DIALOGS & MODALS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Dialogs & Modals") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- LOADING & PROGRESS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Loading & Progress") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- INPUT CONTROLS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Input Controls") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- CARDS & CONTENT
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Cards & Content") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- TEXT & DISPLAY
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Text & Display") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- VISUAL EFFECTS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Visual Effects") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- VFX / GAME / TIMELINE TOOLS
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("VFX / Game / Timeline Tools") then
            imgui.Indent()

            imgui.Unindent()
        end

        -- ================================
        -- DATA VISUALIZATION
        -- ================================
        if current_open_all ~= 0 then imgui.SetNextItemOpen( current_open_all > 0, ImGuiCond.Always ) end
        if imgui.CollapsingHeader("Data Visualization") then
            imgui.Indent()

            imgui.Unindent()
        end

    end
    imgui.End()
end

imgui.Register('imanimusecases', DrawUseCasesUI)

while true do
    mq.delay(1000)
end
