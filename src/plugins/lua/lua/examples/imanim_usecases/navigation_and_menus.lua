local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

local alpha_id = ImHashStr('alpha')
local dist_id = ImHashStr('dist')
local glow_id = ImHashStr('glow')
local hover_id = ImHashStr('hover_id')
local rotation_id = ImHashStr('rotation')
local scale_id = ImHashStr('scale')
local width_id = ImHashStr('width')

-- ============================================================
-- USECASE 3: Sidebar Navigation with Slide Animation
-- ============================================================
local sidebar_state = {
    open = true,
    menu_items = {'Dashboard', 'Analytics', 'Projects', 'Settings', 'Help'},
}

local function ShowUsecase_SidebarNavigation()
    imgui.TextWrapped("Collapsible sidebar with smooth slide animation. Menu items stagger their entrance for a polished feel.")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    if imgui.Button(sidebar_state.open and "Close Sidebar" or "Open Sidebar") then
        sidebar_state.open = not sidebar_state.open
        sidebar_toggle_time = 0.0
    end

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 300)

    -- Background (main content area)
    dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(30, 32, 40, 255), 4.0)

    -- Animate sidebar width
    local id = imgui.GetID('sidebar')
    local target_width = sidebar_state.open and 180.0 or 0.0
    local sidebar_width = iam.TweenFloat(id, width_id, target_width, 0.35,
        iam.EasePreset(IamEaseType.OutExpo), IamPolicy.Crossfade, dt)

    -- Draw sidebar
    if sidebar_width > 1.0 then
        dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + sidebar_width, canvas_pos.y + canvas_size.y),
            IM_COL32(45, 48, 60, 255), 4.0, ImDrawFlags.RoundCornersLeft)

        -- Menu items with stagger
        local item_height = 36.0
        local stagger_delay = 0.05

        for i = 1, #sidebar_state.menu_items do
            -- Calculate stagger offset for each item
            local item_delay = (i - 1) * stagger_delay
            local item_progress = 0.0

            if sidebar_state.open then
                -- Items slide in with stagger
                local t = math.max(0, math.min(1, (sidebar_width / 180.0 - item_delay * 2.0) * 3.0))
                item_progress = iam.EvalPreset(IamEaseType.OutCubic, t)
            else
                item_progress = sidebar_width / 180.0
            end

            local item_x = canvas_pos.x + 12.0 + (1.0 - item_progress) * (-50.0)
            local item_y = canvas_pos.y + 16.0 + (i - 1) * item_height
            local alpha = item_progress * 255

            dl:AddText(ImVec2(item_x, item_y + (item_height - imgui.GetTextLineHeight()) * 0.5),
                IM_COL32(200, 200, 210, alpha), sidebar_state.menu_items[i])
        end
    end

    -- Content area indicator
    local content_x = canvas_pos.x + sidebar_width + 20.0
    dl:AddText(ImVec2(content_x, canvas_pos.y + canvas_size.y * 0.5 - 8.0),
        IM_COL32(100, 100, 110, 255), "Main Content Area")

    imgui.Dummy(canvas_size)
end

-- ============================================================
-- USECASE 6: Tab Transition Animation
-- ============================================================
local function ShowUsecase_TabTransitions()
    -- TODO: Implement Tab Transition Animation
end


-- ============================================================
-- USECASE 9: Accordion/Collapsible Sections
-- ============================================================
local function ShowUsecase_Accordion()
    -- TODO: Implement Accordion/Collapsible Sections
end

-- ============================================================
-- USECASE 10: Floating Action Button (FAB) Menu
-- ============================================================
local fab_state = {
    open = false,
    fab_id = ImHashStr('fab'),

    child_count = 4,
    child_icons = {'A', 'B', 'C', 'D'},
    child_colors = {
        IM_COL32(230, 102, 102, 255),
        IM_COL32(102, 204, 102, 255),
        IM_COL32(102, 153, 230, 255),
        IM_COL32(230, 179, 77, 255),
    },
    child_hovered = { false, false, false, false },
}

local function ShowUsecase_FABButton()
    local state = fab_state

    imgui.TextWrapped(
        'Floating action button that expands into a radial arc menu. ' ..
        'Uses staggered animations for child buttons.')

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 180)

    -- Background
    dl:AddRectFilled(canvas_pos, canvas_pos+ canvas_size, IM_COL32(25, 27, 35, 255), 4.0)

    -- FAB position (bottom-right corner)
    local fab_center = canvas_pos + canvas_size - 50.0
    local fab_radius = 28.0

    -- Animate FAB rotation
    local target_rotation = state.fab_open and 45.0 or 0.0
    local fab_rotation = iam.TweenFloat(state.fab_id, rotation_id, target_rotation, 0.25,
        iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    -- Child button positions (arc going up-left from bottom-right)
    local child_count = 4
    local child_radius = 22
    local arc_radius = 80

    -- Arc from 180 degrees (left) to 270 degrees (up) - upper-left quadrant
    local start_angle = 3.14159     -- 180 degrees (pointing left)
    local end_angle = 3.14159 * 1.5 -- 270 degrees (pointing up)

    -- Draw child buttons (arc pattern)
    for i = 1, state.child_count do
        -- Calculate angle for this button
        local angle_t = (i - 1) / (child_count - 1)
        local angle = start_angle + (end_angle - start_angle) * angle_t

        -- Staggered animation
        local stagger_delay = i * 0.05
        local target_dist = state.fab_open and arc_radius or 0.0
        local target_alpha = state.fab_open and 1.0 or 0.0
        local target_scale = state.fab_open and 1.0 or 0.5

        local child_id = state.fab_id + i
        local dist = iam.TweenFloat(child_id, dist_id, target_dist, 0.3 - stagger_delay,
            iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)
        local alpha = iam.TweenFloat(child_id, alpha_id, target_alpha, 0.2,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
        local base_scale = iam.TweenFloat(child_id, scale_id, target_scale, 0.25,
            iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

        if alpha > 0.01 then
            -- Child buttons positioned in arc
            local child_center = ImVec2(fab_center.x + math.cos(angle) * dist, fab_center.y + math.sin(angle) * dist)

            -- Check hover on child button
            imgui.SetCursorScreenPos(ImVec2(child_center.x - child_radius, child_center.y - child_radius))
            imgui.InvisibleButton('##fab_child_' .. i, ImVec2(child_radius * 2, child_radius * 2))
            state.child_hovered[i] = imgui.IsItemHovered() and state.fab_open

            -- Animate hover scale
            local hover_target = state.child_hovered[i] and 1.2 or 1.0
            local hover_scale = iam.TweenFloat(child_id, hover_id, hover_target, 0.15,
                iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

            local scale = base_scale * hover_scale

            -- Shadow (larger when hovered)
            local shadow_alpha = state.child_hovered[i] and 50.0 or 30.0
            dl:AddCircleFilled(ImVec2(child_center.x + 2, child_center.y + 3), child_radius * scale,
                IM_COL32(0.0, 0.0, 0.0, shadow_alpha * alpha))

            -- Glow effect on hover
            if state.child_hovered[i] then
                local glow_anim = iam.TweenFloat(child_id, glow_id, 1.0, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
                local glow_col = state.child_colors[i]
                dl:AddCircleFilled(child_center, child_radius * scale + 4 * glow_anim,
                    common.ColorAlpha(glow_col, 60 * alpha * glow_anim))
            else
                iam.TweenFloat(child_id, glow_id, 0.0, 0.15, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
            end

            -- Button
            local col = state.child_colors[i]
            dl:AddCircleFilled(child_center, child_radius * scale, common.ColorAlpha(col, 255 * alpha))

            -- Icon
            local text_size = imgui.CalcTextSizeVec(state.child_icons[i])
            dl:AddText(child_center - text_size * 0.5, IM_COL32(255, 255, 255, 255 * alpha), state.child_icons[i])
        end
    end

    -- Main FAB button
    imgui.SetCursorScreenPos(ImVec2(fab_center.x - fab_radius, fab_center.y - fab_radius))
    if imgui.InvisibleButton('##fab', ImVec2(fab_radius * 2, fab_radius * 2)) then
        state.fab_open = not state.fab_open
    end

    local fab_hovered = imgui.IsItemHovered()

    -- FAB hover animation
    local target_fab_scale = fab_hovered and 1.1 or 1.0
    local fab_scale = iam.TweenFloat(state.fab_id, scale_id, target_fab_scale, 0.15,
        iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Shadow
    dl:AddCircleFilled(ImVec2(fab_center.x + 2, fab_center.y + 4), fab_radius * fab_scale, IM_COL32(0, 0, 0, 40))

    -- FAB background
    dl:AddCircleFilled(fab_center, fab_radius * fab_scale, IM_COL32(91, 194, 231, 255))

    -- Rotated plus icon
    local rad = fab_rotation * math.pi / 180.0
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

-- ============================================================
-- USECASE 16: Hamburger Menu Morph
-- ============================================================
local function ShowUsecase_HamburgerMorph()
    -- TODO: Implement Hamburger Menu Morph
end

-- ============================================================
-- USECASE 24: Search Bar Expansion
-- ============================================================
local function ShowUsecase_SearchExpand()
    -- TODO: Implement Search Bar Expansion
end

-- ============================================================
-- 31. Slide-in Drawer
-- Side panel that slides in/out smoothly
-- ============================================================
local function ShowUsecase_SlideDrawer()
    -- TODO: Implement Slide-in Drawer
end

-- ============================================================
-- USECASE: Pill Navigation
-- ============================================================
local function ShowUsecase_PillNavigation()
    -- TODO: Implement Pill Navigation
end

-- ============================================================
-- USECASE: Dropdown Menu
-- ============================================================
local function ShowUsecase_DropdownMenu()
    -- TODO: Implement Dropdown Menu
end

-- ============================================================
-- USECASE: Context Menu
-- ============================================================
local function ShowUsecase_ContextMenu()
    -- TODO: Implement Context Menu
end

local function RunNavigationAndMenusDemo()
    -- ========================================
    -- NAVIGATION & MENUS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Navigation & Menus") then
        imgui.Indent()
        common.USECASE_ITEM('Sidebar Navigation', ShowUsecase_SidebarNavigation)
        common.USECASE_ITEM('Tab Transitions', ShowUsecase_TabTransitions)
        common.USECASE_ITEM('Accordion Sections', ShowUsecase_Accordion)
        common.USECASE_ITEM('FAB Menu', ShowUsecase_FABButton)
        common.USECASE_ITEM('Hamburger Menu Morph', ShowUsecase_HamburgerMorph)
        common.USECASE_ITEM('Slide-in Drawer', ShowUsecase_SlideDrawer)
        common.USECASE_ITEM('Search Bar Expansion', ShowUsecase_SearchExpand)
        common.USECASE_ITEM('Pill Navigation', ShowUsecase_PillNavigation)
        common.USECASE_ITEM('Dropdown Menu', ShowUsecase_DropdownMenu)
        common.USECASE_ITEM('Context Menu', ShowUsecase_ContextMenu)
        imgui.Unindent()
    end
end

return RunNavigationAndMenusDemo
