local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 15: Ripple Effect (Material Design)
-- ============================================================
local function ShowUsecase_RippleEffect()
    -- TODO: Implement Ripple Effect (Material Design)
end

-- ============================================================
-- USECASE 18: Gradient Background Animation
-- ============================================================
local function ShowUsecase_GradientAnimation()
    -- TODO: Implement Gradient Background Animation
end

-- ============================================================
-- 34. Shake Animation
-- Error feedback shake effect for form validation
-- ============================================================
local function ShowUsecase_ShakeAnimation()
    -- TODO: Implement Shake Animation
end

-- ============================================================
-- USECASE 14: Avatar Stack with Hover Expansion
-- ============================================================
local function ShowUsecase_AvatarStack()
    -- TODO: Implement Avatar Stack with Hover Expansion
end

-- ============================================================
-- USECASE: Particle Burst
-- ============================================================
local function ShowUsecase_ParticleBurst()
    -- TODO: Implement Particle Burst
end

-- ============================================================
-- USECASE: Glowing Border
-- ============================================================
local function ShowUsecase_GlowingBorder()
    -- TODO: Implement Glowing Border
end

-- ============================================================
-- USECASE: Pulse Ring
-- ============================================================
local pulse_ring_state = {
    pulse_time = 0.0,
}

local function ShowUsecase_PulseRing()
    imgui.TextWrapped("Pulsating ring effect for attention/notification.")

    local dt = common.GetDeltaTime()
    local scale = 1.0
    local dl = imgui.GetWindowDrawList()

    pulse_ring_state.pulse_time = pulse_ring_state.pulse_time + dt

    local cp = imgui.GetCursorScreenPosVec()
    local center = ImVec2(cp.x + 50 * scale, cp.y + 50 * scale)

    -- Multiple expanding rings
    for i=1,3 do
        local ring_time = math.fmod(pulse_ring_state.pulse_time + i * 0.5, 1.5)
        local ring_radius = 15 * scale + ring_time * 30 * scale
        local ring_alpha = 1.0 - (ring_time / 1.5)

        dl:AddCircle(center, ring_radius, IM_COL32(100, 150, 255, ring_alpha * 200), 0, 2 * scale)
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
    imgui.TextWrapped("Shape morphing between circle and square.")

    local dt = common.GetDeltaTime()
    local scale = 1.0
    local dl = imgui.GetWindowDrawList()

    local cp = imgui.GetCursorScreenPosVec()
    local center = ImVec2(cp.x + 60 * scale, cp.y + 60 * scale)
    local size = 40 * scale

    -- Morph animation (corner radius)
    local corner = iam.TweenFloat(morphing_state.morph_c_id, morphing_state.mc_id,
        morphing_state.is_circle and size or 8 * scale, 0.4,
        iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)

    dl:AddRectFilled(ImVec2(center.x - size, center.y - size),
        ImVec2(center.x + size, center.y + size),
        IM_COL32(70, 130, 180, 255), corner)

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + 130 * scale))
    if imgui.Button(morphing_state.is_circle and "To Square" or "To Circle") then
        morphing_state.is_circle = not morphing_state.is_circle
    end
end

-- ============================================================
-- USECASE: Bouncing Dots
-- ============================================================
local bouncing_state = {
    bounce_time = 0.0,
}

local function ShowUsecase_BouncingDots()
    imgui.TextWrapped("Bouncing dots loading animation.")

    local dt = common.GetDeltaTime()
    local scale = 1.0
    local dl = imgui.GetWindowDrawList()

    bouncing_state.bounce_time = bouncing_state.bounce_time + dt * 3.0

    local cp = imgui.GetCursorScreenPosVec()

    for i=1,3 do
        local phase = bouncing_state.bounce_time + i * 0.5
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
    imgui.TextWrapped("Celebration confetti burst animation.")

    local dt = common.GetDeltaTime()
    local scale = 1.0
    local dl = imgui.GetWindowDrawList()

    if confetti_state.burst_time >= 0 then confetti_state.burst_time = confetti_state.burst_time + dt end
    if confetti_state.burst_time > 2.0 then confetti_state.burst_time = -1.0 end

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(200 * scale, 100 * scale)
    local center = ImVec2(cp.x + cs.x * 0.5, cp.y + cs.y * 0.5)

    -- Container
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y),
        IM_COL32(30, 35, 45, 255), 8 * scale)

    if confetti_state.burst_time >= 0 and confetti_state.burst_time < 2.0 then
        -- Draw confetti particles
        for i=1,20 do
            local angle = i / 20.0 * 6.28318
            local speed = 50 + (i % 5) * 30
            local x = center.x + math.cos(angle) * speed * confetti_state.burst_time * scale
            local y = center.y + math.sin(angle) * speed * confetti_state.burst_time * scale + confetti_state.burst_time * confetti_state.burst_time * 100 * scale
            local alpha = 1.0 - confetti_state.burst_time * 0.5

            local colors = {
                IM_COL32(255, 100, 100, alpha * 255),
                IM_COL32(100, 255, 100, alpha * 255),
                IM_COL32(100, 100, 255, alpha * 255),
                IM_COL32(255, 255, 100, alpha * 255)
            }

            dl:AddRectFilled(ImVec2(x - 3 * scale, y - 3 * scale),
                ImVec2(x + 3 * scale, y + 3 * scale), colors[i % 4 + 1])
        end
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 10 * scale))
    if imgui.Button("Celebrate!") then confetti_state.burst_time = 0.0 end
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
