local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- 39. Timeline Scrubber
-- Video/animation timeline with animated playhead
-- ============================================================
local function ShowUsecase_TimelineScrubber()
    -- TODO: Implement Timeline Scrubber
end

-- ============================================================
-- 40. Keyframe Curve Editor
-- Animation curve with editable keyframe points
-- ============================================================
local function ShowUsecase_KeyframeCurve()
    -- TODO: Implement Keyframe Curve Editor
end

-- ============================================================
-- 41. Layer Stack
-- Layer panel with visibility toggles and reorder animation
-- ============================================================
local function ShowUsecase_LayerStack()
    -- TODO: Implement Layer Stack
end

-- ============================================================
-- 42. Node Connector
-- Animated connection line between nodes (node-based editor)
-- ============================================================
local function ShowUsecase_NodeConnector()
    -- TODO: Implement Node Connector
end

-- ============================================================
-- USECASE: Animated Graph Node
-- ============================================================
local function ShowUsecase_AnimatedGraphNode()
    -- TODO: Implement Animated Graph Node
end

-- ============================================================
-- USECASE: Playback Controls
-- ============================================================
local function ShowUsecase_PlaybackControls()
    -- TODO: Implement Playback Controls
end

-- ============================================================
-- USECASE: Health Bar
-- ============================================================
local health_bar_state = {
    health = 100.0,
    displayed_health = 100.0,
    hp_val_id = ImHashStr("hp_val"),
    hv_id = ImHashStr("hv"),
}

local function ShowUsecase_HealthBar()
    local state = health_bar_state

    imgui.TextWrapped("Game-style health bar with damage animation.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    -- Damage animation (red flash)
    state.displayed_health = iam.TweenFloat(state.hp_val_id, state.hv_id,
        state.health, 0.3, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

    local cp = imgui.GetCursorScreenPosVec()
    local bar_width = 200 * scale
    local bar_height = 20 * scale

    -- Background
    dl:AddRectFilled(cp, ImVec2(cp.x + bar_width, cp.y + bar_height),
        IM_COL32(40, 20, 20, 255), 4 * scale)

    -- Damage ghost (shows previous health)
    if state.displayed_health < state.health + 0.1 then
        local ghost_width = bar_width * (state.health / 100.0)
        dl:AddRectFilled(cp, ImVec2(cp.x + ghost_width, cp.y + bar_height),
            IM_COL32(200, 50, 50, 150), 4 * scale)
    end

    -- Current health
    local health_width = bar_width * (state.displayed_health / 100.0)
    local health_col = state.displayed_health > 50 and IM_COL32(76, 175, 80, 255) or
        (state.displayed_health > 25 and IM_COL32(255, 200, 50, 255) or IM_COL32(220, 60, 60, 255))
    dl:AddRectFilled(cp, ImVec2(cp.x + health_width, cp.y + bar_height),
        health_col, 4 * scale)

    -- Health text
    local hp_text = string.format('%.0f / 100', state.displayed_health)
    local text_size = imgui.CalcTextSizeVec(hp_text)
    dl:AddText(ImVec2(cp.x + (bar_width - text_size.x) * 0.5, cp.y + (bar_height - text_size.y) * 0.5),
        IM_COL32(255, 255, 255, 255), hp_text)

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + bar_height + 10 * scale))
    if imgui.Button("Take Damage") and state.health > 0 then
        state.health = state.health - 15.0
    end
    imgui.SameLine()
    if imgui.Button("Heal") and state.health < 100 then
        state.health = state.health + 20.0
    end
    state.health = math.min(100.0, math.max(0.0, state.health))
end

-- ============================================================
-- USECASE: Cooldown Timer
-- ============================================================
local cooldown_timer_state = {
    cooldown = 0.0,
}

local function ShowUsecase_CooldownTimer()
    local state = cooldown_timer_state

    imgui.TextWrapped("Ability cooldown with circular sweep animation.")

    local max_cooldown = 3.0
    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    if state.cooldown > 0 then state.cooldown = state.cooldown - dt end

    local cp = imgui.GetCursorScreenPosVec()
    local btn_size = 50 * scale
    local center = ImVec2(cp.x + btn_size * 0.5, cp.y + btn_size * 0.5)

    -- Button background
    dl:AddRectFilled(cp, ImVec2(cp.x + btn_size, cp.y + btn_size),
        state.cooldown > 0 and IM_COL32(40, 45, 55, 255) or IM_COL32(70, 130, 180, 255), 8 * scale)

    -- Cooldown overlay
    if state.cooldown > 0 then
        local progress = state.cooldown / max_cooldown
        local angle = -1.5708 + progress * 6.28318

        dl:PathArcTo(center, btn_size * 0.4, -1.5708, angle, 32)
        dl:PathLineTo(center)
        dl:PathFillConvex(IM_COL32(0, 0, 0, 150))

        -- Time remaining
        local time_str = string.format('%.1f', state.cooldown)
        local time_size = imgui.CalcTextSizeVec(time_str)
        dl:AddText(ImVec2(center.x - time_size.x * 0.5, center.y - time_size.y * 0.5),
            IM_COL32(255, 255, 255, 255), time_str)
    else
        dl:AddText(ImVec2(center.x - 4 * scale, center.y - 6 * scale),
            IM_COL32(255, 255, 255, 255), "Q")
    end

    imgui.SetCursorScreenPos(cp)
    if imgui.InvisibleButton("ability", ImVec2(btn_size, btn_size)) and state.cooldown <= 0 then
        state.cooldown = max_cooldown
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + btn_size + 10 * scale))
end

-- ============================================================
-- USECASE: Damage Number
-- ============================================================
local damage_number_state = {
    dmg_time = -1.0,
    dmg_value = 0,
}

local function ShowUsecase_DamageNumber()
    local state = damage_number_state

    imgui.TextWrapped("Floating damage number with pop and fade.")

    local dt = common.GetDeltaTime()
    local scale = imgui.GetStyle().FontScaleMain
    local dl = imgui.GetWindowDrawList()

    if state.dmg_time >= 0 then state.dmg_time = state.dmg_time + dt end
    if state.dmg_time >= 1.5 then state.dmg_time = -1.0 end

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(150 * scale, 80 * scale)

    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y), IM_COL32(30, 35, 45, 255), 8 * scale)

    local target_center = ImVec2(cp.x + cs.x * 0.5, cp.y + cs.y * 0.5)
    dl:AddCircleFilled(target_center, 20 * scale, IM_COL32(100, 60, 60, 255))

    if state.dmg_time >= 0 then
        local pop_scale = state.dmg_time < 0.2 and (1.0 + state.dmg_time * 2.0) or 1.4 - (state.dmg_time - 0.2) * 0.3
        local float_y = state.dmg_time * 40 * scale
        local alpha = 1.0 - math.min(1.0, math.max(0.0, (state.dmg_time - 0.8) / 0.7))

        local dmg_str = tostring(state.dmg_value)

        imgui.SetWindowFontScale(pop_scale * 1.5)
        local dmg_size = imgui.CalcTextSizeVec(dmg_str)
        dl:AddText(ImVec2(target_center.x - dmg_size.x * 0.5, target_center.y - 30 * scale - float_y), IM_COL32(255, 100, 100, alpha*255), dmg_str)
        imgui.SetWindowFontScale(1.0)
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 10 * scale))
    if imgui.Button('Hit!') then
        state.dmg_time = 0.0
        state.dmg_value = 50 + math.random(100) % 100
    end
end

-- ============================================================
-- USECASE: XP Progress
-- ============================================================
local function ShowUsecase_XPProgress()
    -- TODO: Implement XP Progress
end

local function RunVfxGameTimelineToolsDemo()
    -- ========================================
    -- VFX / GAME / TIMELINE TOOLS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("VFX / Game / Timeline Tools") then
        imgui.Indent()
        common.USECASE_ITEM('Timeline Scrubber', ShowUsecase_TimelineScrubber)
        common.USECASE_ITEM('Keyframe Curve Editor', ShowUsecase_KeyframeCurve)
        common.USECASE_ITEM('Layer Stack', ShowUsecase_LayerStack)
        common.USECASE_ITEM('Node Connector', ShowUsecase_NodeConnector)
        common.USECASE_ITEM('Animated Graph Node', ShowUsecase_AnimatedGraphNode)
        common.USECASE_ITEM('Playback Controls', ShowUsecase_PlaybackControls)
        common.USECASE_ITEM('Health Bar', ShowUsecase_HealthBar)
        common.USECASE_ITEM('Cooldown Timer', ShowUsecase_CooldownTimer)
        common.USECASE_ITEM('Damage Number', ShowUsecase_DamageNumber)
        common.USECASE_ITEM('XP Progress', ShowUsecase_XPProgress)
        imgui.Unindent()
    end
end

return RunVfxGameTimelineToolsDemo
