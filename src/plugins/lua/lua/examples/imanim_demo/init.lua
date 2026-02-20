-- imanim_demo.lua — Demo window showcasing ImAnim features
-- Ported from im_anim_demo.cpp
-- Original Author: Soufiane KHIAT
--
-- Usage: /lua run examples/imanim_demo

local mq = require('mq')
local imgui = require('ImGui')
local iam = require('ImAnim')

local openGUI = true
local show_debug_window = false
local s_open_all = 0
local io = imgui.GetIO()

local function GetSafeDeltaTime()
    local dt = imgui.GetIO().DeltaTime
    if dt <= 0 then dt = 1.0 / 60.0 end
    if dt > 0.1 then dt = 0.1 end
    return dt
end

local function ApplyOpenAll()
    if s_open_all ~= 0 then
        imgui.SetNextItemOpen(s_open_all > 0, ImGuiCond.Always)
    end
end

-- ============================================================
-- SECTION: Hero Animation - Dynamic Brand Showcase
-- ============================================================

---@enum ParticleShape
local ParticleShape = {
    Circle = 0,
    Rect = 1,
    Ellipse = 2
}

---@class Particle
---@field pos ImVec2
---@field vel ImVec2
---@field life number
---@field max_life number
---@field size number
---@field shape ParticleShape
---@field angle number
---@field spin number
---@field color_idx number

---@return Particle
local function CreateParticle()
    return {
        pos = ImVec2(0, 0),
        vel = ImVec2(0, 0),
        life = 0,
        max_life = 0,
        size = 0,
        shape = 0,
        angle = 0,
        spin = 0,
        color_idx = 0
    }
end

---@return Particle[]
local function CreateParticles(count)
    local particles = {}
    for i = 1, count do
        table.insert(particles, CreateParticle())
    end
    return particles
end

---@param dl ImDrawList
---@param ctr ImVec2
---@param size ImVec2
---@param angle number
---@param fill ImU32
---@param border ImU32
local function DrawRotatedRect(dl, ctr, size, angle, fill, border)
    local c = math.cos(angle)
    local s = math.sin(angle)
    local corners = {
        ImVec2(-size.x * 0.5, -size.y * 0.5),
        ImVec2( size.x * 0.5, -size.y * 0.5),
        ImVec2( size.x * 0.5,  size.y * 0.5),
        ImVec2(-size.x * 0.5,  size.y * 0.5)
    }
    local pts = {
        ImVec2(ctr.x + corners[1].x * c - corners[1].y * s, ctr.y + corners[1].x * s + corners[1].y * c),
        ImVec2(ctr.x + corners[2].x * c - corners[2].y * s, ctr.y + corners[2].x * s + corners[2].y * c),
        ImVec2(ctr.x + corners[3].x * c - corners[3].y * s, ctr.y + corners[3].x * s + corners[3].y * c),
        ImVec2(ctr.x + corners[4].x * c - corners[4].y * s, ctr.y + corners[4].x * s + corners[4].y * c),
    }

    dl:AddConvexPolyFilled(pts, fill)
    if bit32.band(border, 0xff000000) > 0 then
        dl:AddPolyline(pts, border, ImDrawFlags.Closed, 1.5)
    end
end

-- === COLORS ===
local CYAN = IM_COL32(91, 194, 231, 255)
local CORAL = IM_COL32(204, 120, 88, 255)
local TEAL = IM_COL32(100, 220, 180, 255)
local PURPLE = IM_COL32(160, 120, 200, 255)
local GOLD = IM_COL32(230, 190, 90, 255)

---@param dl ImDrawList
---@param ctr ImVec2
---@param radii ImVec2
---@param angle number
---@param fill ImU32
---@param segments? number
local function DrawRotatedEllipse(dl, ctr, radii, angle, fill, segments)
    local c = math.cos(angle)
    local s = math.sin(angle)
    segments = segments or 32
    local pts = {}
    for i = 1, segments do
        local a = i / segments * math.pi * 2.0
        local lx = math.cos(a) * radii.x
        local ly = math.sin(a) * radii.y
        table.insert(pts, ImVec2(ctr.x + lx * c - ly * s, ctr.y + lx * s + ly * c))
    end

    dl:AddConvexPolyFilled(pts, fill)
end

local ShowHeroAnimation_State = {
    T = 0,
    particles = CreateParticles(64),
    particle_count = 0,
    last_mouse = ImVec2(0, 0),
    spawn_accum = 0,
    colors = { CYAN, CORAL, TEAL, PURPLE, GOLD },
    -- Hover animation state
    hover_anim = 0.0,
    was_hovered = false,
}

local function fade_alpha(local_, fade_in, fade_out)
    if local_ < fade_in then return iam.EvalPreset(IamEaseType.OutQuad, local_ / fade_in) end
    if local_ > fade_out then return 1.0 - iam.EvalPreset(IamEaseType.InExpo, (local_ - fade_out) / (1.0 - fade_out)) end
    return 1.0
end

local function ColorAlpha(col, a)
    return bit32.bor(bit32.band(col, 0xffffff), bit32.lshift(a, 24))
end

local function ShowHeroAnimation()
    local state = ShowHeroAnimation_State

    local dt = GetSafeDeltaTime()
    state.T = state.T + dt

    local CYCLE = 10
    local t = math.fmod(state.T, CYCLE)

    local dl = imgui.GetWindowDrawList()
    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(imgui.GetContentRegionAvailVec().x, 300)
    local cc = ImVec2(cp.x + cs.x * 0.5, cp.y + cs.y * 0.5)

    -- === MOUSE TRAIL PARTICLES ===

    -- Corner positions
    local TL = ImVec2(cp.x + 50, cp.y + 50)
    local TR = ImVec2(cp.x + cs.x - 50, cp.y + 50)
    local BL = ImVec2(cp.x + 50, cp.y + cs.y - 50)
    local BR = ImVec2(cp.x + cs.x - 50, cp.y + cs.y - 50)

    -- Edge midpoints (avoiding center)
    local ML = ImVec2(cp.x + 30, cc.y)
    local MR = ImVec2(cp.x + cs.x - 30, cc.y)
    local MT = ImVec2(cc.x, cp.y + 30)
    local MB = ImVec2(cc.x, cp.y + cs.y - 30)

    -- === BACKGROUND ===
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y), IM_COL32(15, 18, 30, 255))

    -- === MOUSE TRAIL: Spawn particles when mouse moves inside hero area ===
    do
        local mouse = imgui.GetMousePosVec()
        local in_area = mouse.x >= cp.x and mouse.x <= cp.x + cs.x and mouse.y >= cp.y and mouse.y <= cp.y + cs.y

        if in_area then
            local dx = mouse.x - state.last_mouse.x
            local dy = mouse.y - state.last_mouse.y
            local dist = math.sqrt(dx * dx + dy * dy)

            -- Skip if mouse teleported (e.g., screen capture tool, window switching)
            if dist > 200 then
                state.last_mouse = mouse
                state.spawn_accum = 0
            end

            state.spawn_accum = state.spawn_accum + dist
            local SPAWN_DIST = 15

            local spawned = 0
            local MAX_SPAWN_PER_FRAME = 4

            while state.spawn_accum >= SPAWN_DIST and spawned < MAX_SPAWN_PER_FRAME do
                spawned = spawned + 1
                state.spawn_accum = state.spawn_accum - SPAWN_DIST

                -- Find free slot (expired particle) or use oldest
                local slot = -1
                local oldest_ratio = -1
                local oldest_slot = 1

                for i = 1, 64 do
                    -- Check if particle is dead/expired
                    if state.particles[1].max_life <= 0 or state.particles[i].life >= state.particles[i].max_life then
                        slot = i
                        break
                    end
                    -- Track oldest
                    local ratio = state.particles[i].life / state.particles[i].max_life
                    if ratio > oldest_ratio then
                        oldest_ratio = ratio
                        oldest_slot = i
                    end
                end
                if slot < 0 then
                    slot = oldest_slot -- Reuse oldest if no free slot
                end

                local p = state.particles[slot]
                p.pos = mouse
                -- Velocity: perpendicular to movement + some randomness
                local spread = ((slot % 7) - 3) * 0.5
                local speed = 30 + (slot % 5) * 15
                p.vel = ImVec2(-dy * 0.3 + spread * 20, dx * 0.3 + (slot % 3 - 1) * 30)
                p.vel.x = p.vel.x + ((slot * 7) % 11 - 5) * 8.0
                p.vel.y = p.vel.y - speed * 0.5 -- slight upward bias
                p.life = 0
                p.max_life = 0.8 + (slot % 4) * 0.2
                p.size = 6.0 + (slot % 5) * 3.0
                p.shape = slot % 3
                p.angle = (slot % 10) * .0628
                p.spin = ((slot % 7) - 3) * 2.0
                p.color_idx = (slot % 5) + 1
            end
        end

        state.last_mouse = mouse

        -- Update and render particles
        for i = 1, 64 do
            local p = state.particles[i]
            if p.life < p.max_life and p.max_life > 0 then
                p.life = p.life + dt
                local lt = p.life / p.max_life

                -- Physics
                p.pos.x = p.pos.x + p.vel.x * dt
                p.pos.y = p.pos.y + p.vel.y * dt
                p.vel.y = p.vel.y + 80.0 * dt -- gravity
                p.vel.x = p.vel.x * 0.98 -- drag
                p.vel.y = p.vel.y * 0.98
                p.angle = p.angle + p.spin * dt

                -- Render with eased alpha and scale
                local alpha = 1.0 - iam.EvalPreset(IamEaseType.InQuad, lt)
                local scale = iam.EvalPreset(IamEaseType.OutBack, math.min(lt * 5.0, 1.0)) * (1.0 - lt * 0.3)
                local a = math.modf(alpha * 200)

                if a > 5 and p.pos.x >= cp.x and p.pos.x <= cp.x + cs.x and p.pos.y >= cp.y and p.pos.y <= cp.y + cs.y then
                    local col = ColorAlpha(state.colors[p.color_idx], a)
                    local sz = p.size * scale

                    if p.shape == ParticleShape.Circle then
                        dl:AddCircleFilled(p.pos, sz, col, 0)
                    elseif p.shape == ParticleShape.Rect then
                        DrawRotatedRect(dl, p.pos, ImVec2(sz * 1.4, sz * 0.6), p.angle, col, 0)
                    elseif p.shape == ParticleShape.Ellipse then
                        DrawRotatedEllipse(dl, p.pos, ImVec2(sz, sz * 0.6), p.angle, col)
                    end
                end
            end
        end
    end

    -- ================================================================
    -- LAYER 1: CONTINUOUS CORNER PULSES (0.0 - 10.0)
    -- Four corners emit pulses at different rates, overlapping
    -- ================================================================

    do
        local pulses = {
            { pos = TL, period = 1.8, phase = 0.0, col = CYAN },
            { pos = TR, period = 2.2, phase = 0.3, col = CORAL },
            { pos = BL, period = 2.0, phase = 0.6, col = TEAL },
            { pos = BR, period = 1.6, phase = 0.9, col = PURPLE }
        }
        for i = 1, 4 do
            p = pulses[i]
            local pt = math.fmod(t + p.phase, p.period) / p.period
            local expand = iam.EvalPreset(IamEaseType.OutExpo, pt)
            local alpha = (1.0 - pt) * 0.4
            if alpha > 0.02 then
                local a = math.modf(alpha * 255)
                local radius = 15 + expand * 80
                dl:AddCircle(p.pos, radius, ColorAlpha(p.col, a), 32, 2.0)
            end
        end
    end

    -- ================================================================
    -- LAYER 2: CORNER LAUNCHES (0.2 - 2.5)
    -- All 4 corners launch shapes simultaneously that travel along edges
    -- ================================================================

    do
        -- TL -> TR (top edge)
        for i = 0, 3 do
            local start = 0.2 + i * 0.15
            local dur = 2.0
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local travel = iam.EvalPreset(IamEaseType.InOutCubic, local_)
                local alpha = fade_alpha(local_, 0.1, 0.85)
                local px = TL.x + (TR.x - TL.x) * travel
                local py = TL.y + math.sin(local_ * 6.28) * 15
                local a = math.modf(alpha * 200)
                local size = 14.0 + i * 3.0
                DrawRotatedRect(dl, ImVec2(px, py), ImVec2(size, size * 0.6), local_ * 4.0, ColorAlpha(CYAN, a), 0)
            end
        end

        -- TR -> BR (right edge)
        for i = 0, 3 do
            local start = 0.3 + i * 0.15
            local dur = 2.0
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local travel = iam.EvalPreset(IamEaseType.InOutCubic, local_)
                local alpha = fade_alpha(local_, 0.1, 0.85)
                local px = TR.x + math.sin(local_ * 6.28) * 15
                local py = TR.y + (BR.y - TR.y) * travel
                local a = math.modf(alpha * 200)
                local size = 12.0 + i * 3.0
                DrawRotatedEllipse(dl, ImVec2(px, py), ImVec2(size, size * 0.7), -local_ * 3.0, ColorAlpha(CORAL, a))
            end
        end

        -- BR -> BL (bottom edge)
        for i = 0, 3 do
            local start = 0.4 + i * 0.15
            local dur = 2.0
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local travel = iam.EvalPreset(IamEaseType.InOutCubic, local_)
                local alpha = fade_alpha(local_, 0.1, 0.85)
                local px = BR.x - (BR.x - BL.x) * travel
                local py = BR.y + math.sin(local_ * 6.28 + 1.57) * 15
                local a = math.modf(alpha * 200)
                local size = 13.0 + i * 2.0
                DrawRotatedRect(dl, ImVec2(px, py), ImVec2(size, size * 0.5), local_ * 5.0, ColorAlpha(TEAL, a), 0)
            end
        end

        -- BL -> TL (left edge)
        for i = 0, 3 do
            local start = 0.5 + i * 0.15
            local dur = 2.0
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local travel = iam.EvalPreset(IamEaseType.InOutCubic, local_)
                local alpha = fade_alpha(local_, 0.1, 0.85)
                local px = BL.x + math.sin(local_ * 6.28 + 3.14) * 15
                local py = BL.y - (BL.y - TL.y) * travel
                local a = math.modf(alpha * 200)
                local size = 11.0 + i * 3.0
                dl:AddCircleFilled(ImVec2(px, py), size, ColorAlpha(PURPLE, a))
            end
        end
    end

    -- ================================================================
    -- LAYER 3: DIAGONAL CROSS-STREAMS (1.5 - 4.5)
    -- TL->BR and TR->BL simultaneously, shapes "pass" each other
    -- ================================================================

    do
        -- TL -> BR diagonal
        for i = 0, 5 do
            local start = 1.5 + i * 0.12
            local dur = 2.5
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local travel = iam.EvalPreset(IamEaseType.InOutQuad, local_)
                local alpha = fade_alpha(local_, 0.08, 0.8)
                -- Curve outward to avoid center
                local curve = math.sin(local_ * 3.14159) * 60
                local px = TL.x + (BR.x - TL.x) * travel - curve
                local py = TL.y + (BR.y - TL.y) * travel
                local a = math.modf(alpha * 180)
                local size = 10.0 + (i % 3) * 5.0
                local rot = local_ * 6.0 + i
                DrawRotatedRect(dl, ImVec2(px, py), ImVec2(size * 1.2, size * 0.6), rot, ColorAlpha(state.colors[(i % 5) + 1], a), 0)
            end
        end

        -- TR -> BL diagonal
        for i = 0, 5 do
            local start = 1.6 + i * 0.12
            local dur = 2.5
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local travel = iam.EvalPreset(IamEaseType.InOutQuad, local_)
                local alpha = fade_alpha(local_, 0.08, 0.8)
                -- Curve outward to avoid center
                local curve = math.sin(local_ * 3.14159) * 60
                local px = TR.x - (TR.x - BL.x) * travel + curve
                local py = TR.y + (BL.y - TR.y) * travel
                local a = math.modf(alpha * 180)
                local size = 9.0 + (i % 3) * 4.0
                DrawRotatedEllipse(dl, ImVec2(px, py), ImVec2(size, size * 0.7), -local_ * 5.0, ColorAlpha(state.colors[((i + 2) % 5) + 1], a))
            end
        end
    end

    -- ================================================================
    -- LAYER 4: FOUR CORNER SIMULTANEOUS BURST (3.0 - 5.5)
    -- All corners explode shapes outward at once
    -- ================================================================

    do
        local corners = { TL, TR, BL, BR }
        local corner_cols = { CYAN, CORAL, TEAL, PURPLE }
        local corner_angles = { 0.785, 2.356, -0.785, -2.356 } --  45deg directions away from center

        for c = 0, 3 do
            for i = 0, 4 do
                local start = 3.0 + c * 0.05 + i * 0.08
                local dur = 2.0
                if t >= start and t < start + dur then
                    local local_ = (t - start) / dur
                    local explode = iam.EvalPreset(IamEaseType.OutBack, math.min(local_ * 1.5, 1.0))
                    local alpha = fade_alpha(local_, 0.05, 0.7)
                    local angle = corner_angles[c + 1] + (i - 2) * 0.4
                    local dist = 20 + explode * 100
                    local px = corners[c + 1].x + math.cos(angle) * dist
                    local py = corners[c + 1].y + math.sin(angle) * dist
                    local a = math.modf(alpha * 200)
                    local size = 8.0 + i * 3.0
                    local scale = 1.0 + (1.0 - local_) * 0.5
                    if i % 2 == 0 then
                        dl:AddCircleFilled(ImVec2(px, py), size * scale, ColorAlpha(corner_cols[c + 1], a))
                    else
                        DrawRotatedRect(dl, ImVec2(px, py), ImVec2(size * scale * 1.3, size * scale * 0.6), local_ * 4, ColorAlpha(corner_cols[c + 1], a), 0)
                    end
                end
            end
        end
    end

    -- ================================================================
    -- LAYER 5: WAVE FROM EDGES (4.5 - 7.0)
    -- Left and right edges launch waves that meet and bounce
    -- ================================================================

    do
        -- Left wave moving right
        for i = 0, 7 do
            local start = 4.5 + i * 0.06
            local dur = 2.0
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                -- Move right, bounce back at 70%
                local move = (local_ < 0.7) and iam.EvalPreset(IamEaseType.OutQuad, local_ / 0.7) or
                    1.0 - iam.EvalPreset(IamEaseType.OutBounce, (local_ - 0.7) / 0.3) * 0.3
                local alpha = fade_alpha(local_, 0.05, 0.85)
                local px = cp.x + 30 + move * (cs.x * 0.35)
                local py = cp.y + 40 + i * 30
                local a = math.modf(alpha * 180)
                local size = 12.0 + (i % 3) * 4.0
                DrawRotatedEllipse(dl, ImVec2(px, py), ImVec2(size, size * 0.6), local_ * 3, ColorAlpha(state.colors[(i % 5) + 1], a))
            end
        end

        -- Right wave moving left
        for i = 0, 7 do
            local start = 4.6 + i * 0.06
            local dur = 2.0
            if t >= start and t < start + dur then
                local local_ = (t - start) / dur
                local move = (local_ < 0.7) and iam.EvalPreset(IamEaseType.OutQuad, local_ / 0.7) or
                    1.0 - iam.EvalPreset(IamEaseType.OutBounce, (local_ - 0.7) / 0.3) * 0.3
                local alpha = fade_alpha(local_, 0.05, 0.85)
                local px = cp.x + cs.x - 30 - move * (cs.x * 0.35)
                local py = cp.y + 55 + i * 30
                local a = math.modf(alpha * 180)
                local size = 11.0 + (i % 3) * 4.0
                DrawRotatedRect(dl, ImVec2(px, py), ImVec2(size * 1.2, size * 0.5), -local_ * 4, ColorAlpha(state.colors[((i + 2) % 5) + 1], a), 0)
            end
        end
    end

    -- ================================================================
    -- LAYER 6: ORBITING SHAPES AROUND CORNERS (5.5 - 8.0)
    -- Each corner has shapes orbiting it
    -- ================================================================

    do
        local orbit_centers = { TL, TR, BL, BR }
        local orbit_cols = { GOLD, TEAL, CORAL, CYAN }
        local orbit_speeds = { 3.0, -2.5, 2.8, -3.2 }

        for c = 0, 3 do
            for i = 0, 2 do
                local start = 5.5 + c * 0.1
                local dur = 2.5
                if t >= start and t < start + dur then
                    local local_ = (t - start) / dur
                    local alpha = fade_alpha(local_, 0.1, 0.85)
                    local angle = (t - start) * orbit_speeds[c + 1] + i * 2.094
                    local radius = (35 + i * 15)
                    local px = orbit_centers[c + 1].x + math.cos(angle) * radius
                    local py = orbit_centers[c + 1].y + math.sin(angle) * radius
                    local a = math.modf(alpha * 200)
                    local size = 7.0 + i * 3.0
                    if i % 2 == 0 then
                        dl:AddCircleFilled(ImVec2(px, py), size, ColorAlpha(orbit_cols[c + 1], a))
                    else
                        DrawRotatedRect(dl, ImVec2(px, py), ImVec2(size * 1.4, size * 0.5), angle, ColorAlpha(orbit_cols[c + 1], a), 0)
                    end
                end
            end
        end
    end

    -- ================================================================
    -- LAYER 7: CONNECTING LINES BETWEEN CORNERS (6.5 - 9.0)
    -- Lines draw between corners, creating a frame effect
    -- ================================================================

    do
        local lines = {
            { from = TL, to = TR, start = 6.5, col = CYAN },
            { from = TR, to = BR, start = 6.7, col = CORAL },
            { from = BR, to = BL, start = 6.9, col = TEAL },
            { from = BL, to = TL, start = 7.1, col = PURPLE },
            { from = TL, to = BR, start = 7.3, col = GOLD },
            { from = TR, to = BL, start = 7.5, col = CYAN },
        }

        for i = 0, 5 do
            local l = lines[i + 1]
            local dur = 2.0
            if t >= l.start and t < l.start + dur then
                local local_ = (t - l.start) / dur
                local draw = iam.EvalPreset(IamEaseType.OutExpo, math.min(local_ * 2.0, 1.0))
                local alpha = fade_alpha(local_, 0.05, 0.8)
                local a = math.modf(alpha * 150)
                local end_ = ImVec2(l.from.x + (l.to.x - l.from.x) * draw, l.from.y + (l.to.y - l.from.y) * draw)
                dl:AddLine(l.from, end_, ColorAlpha(l.col, a), 2.0)
                -- Dot at the drawing tip
                if draw < 0.95 then
                    dl:AddCircleFilled(end_, 5.0, ColorAlpha(l.col, a))
                end
            end
        end
    end

    -- ================================================================
    -- LAYER 8: FINAL CORNER COLLAPSE (8.5 - 10.0)
    -- All corners send shapes toward each other but they curve away
    -- ================================================================

    do
        local corners = { TL, TR, BL, BR }
        local targets = { BR, BL, TR, TL } -- opposite corners
        local cols = { CYAN, CORAL, TEAL, PURPLE }

        for c = 0, 3 do
            for i = 0, 3 do
                local start = 8.5 + c * 0.08 + i * 0.05
                local dur = 1.3
                if t >= start and t < start + dur then
                    local local_ = (t - start) / dur
                    local travel = iam.EvalPreset(IamEaseType.InOutQuad, local_)
                    local alpha = fade_alpha(local_, 0.05, 0.75)
                    -- Curve away from center
                    local curve = math.sin(local_ * math.pi) * 80 * ((c % 2 == 0) and 1.0 or -1.0)
                    local px = corners[c + 1].x + (targets[c + 1].x - corners[c + 1].x) * travel * 0.4
                    local py = corners[c + 1].y + (targets[c + 1].y - corners[c + 1].y) * travel * 0.4
                    px = px + (c < 2 and curve or -curve)
                    local a = math.modf(alpha * 180)
                    local size = 10.0 + i * 3.0
                    local shrink = 1.0 - local_ * 0.5
                    DrawRotatedEllipse(dl, ImVec2(px, py), ImVec2(size * shrink, size * shrink * 0.6), local_ * 5, ColorAlpha(cols[c + 1], a))
                end
            end
        end
    end

    -- ================================================================
    -- "ImAnim" LOGO - Stays in center, shapes work around it
    -- Hoverable with scale animation after reveal
    -- ================================================================

    do
        local logo = "ImAnim"
        local base_size = imgui.GetFontSize()
        local logo_scale = 3.2
        local logo_alpha = 1.0
        local logo_y = 0.0

        if t < 0.15 then
            local e = t / 0.15
            logo_scale = 3.2 * iam.EvalPreset(IamEaseType.OutExpo, e)
            logo_alpha = iam.EvalPreset(IamEaseType.OutQuad, e)
            logo_y = (1.0 - iam.EvalPreset(IamEaseType.OutExpo, e)) * -80
        elseif t < 9.5 then
            local pulse = math.sin(state.T * 4.0) * 0.02
            logo_scale = 3.2 * (1.0 + pulse)
        else
            local e = (t - 9.5) / 0.5
            logo_alpha = 1.0 - iam.EvalPreset(IamEaseType.InExpo, e)
        end

        if logo_alpha > 0.01 then
            local font_size = base_size * logo_scale
            local text_size = imgui.CalcTextSizeVec(logo)
            local total_w = text_size.x * logo_scale
            local start_x = cc.x - total_w * 0.5
            local base_y = cc.y - font_size * 0.4 + logo_y

            -- Check hover (only after reveal, t > 0.3)
            local is_hovered = false
            if t > 0.3 and t < 9.5 then
                local mouse = imgui.GetMousePosVec()
                local hover_pad = 10.0
                local logo_min = ImVec2(start_x - hover_pad, base_y - hover_pad)
                local logo_max = ImVec2(start_x + total_w + hover_pad, base_y + font_size + hover_pad)
                is_hovered = mouse.x >= logo_min.x and mouse.x <= logo_max.x and mouse.y >= logo_min.y and mouse.y <= logo_max.y
            end

            -- Animate hover state
            local hover_speed = 8.0
            if is_hovered then
                state.hover_anim = state.hover_anim + (dt * hover_speed)
                if state.hover_anim > 1.0 then
                    state.hover_anim = 1.0
                end
            else
                state.hover_anim = state.hover_anim - (dt * hover_speed)
                if state.hover_anim < 0.0 then
                    state.hover_anim = 0.0
                end
            end

            -- Apply hover scale with bounce easing
            local hover_scale = 1.0 + 0.15 * iam.EvalPreset(IamEaseType.OutBack, state.hover_anim)
            logo_scale = logo_scale * hover_scale
            font_size = base_size * logo_scale
            total_w = text_size.x * logo_scale
            start_x = cc.x - total_w * 0.5

            local char_x = start_x
            for i = 0, 5 do
                local ch = logo:sub(i + 1, i + 1)
                local ch_size = imgui.CalcTextSizeVec(ch)

                local char_delay = i * 0.02
                local char_scale = 1.0
                if t < 0.3 and t > char_delay then
                    local ce = (t - char_delay) / 0.15
                    if ce < 1.0 then
                        char_scale = 1.0 + 0.3 * (1.0 - iam.EvalPreset(IamEaseType.OutQuad, ce))
                    end 
                end

                local hue_t = i / 5.0
                local r = math.modf(91 + (204 - 91) * hue_t)
                local g = math.modf(194 + (120 - 194) * hue_t)
                local b = math.modf(231 + (88 - 231) * hue_t)
                local a = math.modf(logo_alpha * 255)

                local char_size_scaled = font_size * char_scale
                local y_adjust = (char_scale - 1.0) * font_size * 0.3

                dl:AddText(nil, char_size_scaled, ImVec2(char_x + 2, base_y - y_adjust + 2), IM_COL32(0, 0, 0, a / 2), ch)
                dl:AddText(nil, char_size_scaled, ImVec2(char_x, base_y - y_adjust), IM_COL32(r, g, b, a), ch)

                char_x = char_x + (ch_size.x * logo_scale * 1.05)
            end

            local line_y = base_y + font_size + 10
            local line_w = total_w * 0.75
            if t < 0.25 then
                line_w = line_w * iam.EvalPreset(IamEaseType.OutExpo, t / 0.25)
            end

            if line_w > 1.0 and logo_alpha > 0.1 then
                local la = math.modf(logo_alpha * 200)
                dl:AddLine(ImVec2(cc.x - line_w * 0.5, line_y), ImVec2(cc.x, line_y), IM_COL32(91, 194, 231, la), 3.0)
                dl:AddLine(ImVec2(cc.x, line_y), ImVec2(cc.x + line_w * 0.5, line_y), IM_COL32(204, 120, 88, la), 3.0)
            end

            -- === "1.0.0" VERSION TEXT ===
            do
                local version = "1.0.0"
                local ver_scale = 1.8
                local ver_alpha = logo_alpha

                -- Delayed entrance after logo (starts at 0.3s)
                if t < 0.3 then
                    ver_alpha = 0.0
                elseif t < 0.5 then
                    local ve = (t - 0.3) / 0.2
                    ver_alpha = logo_alpha * iam.EvalPreset(IamEaseType.OutQuad, ve)
                    ver_scale = 1.8 * (0.5 + 0.5 * iam.EvalPreset(IamEaseType.OutBack, ve))
                end

                if ver_alpha > 0.01 then
                    local ver_font_size = base_size * ver_scale
                    local ver_text_size = imgui.CalcTextSizeVec(version)
                    local ver_w = ver_text_size.x * ver_scale
                    local ver_x = cc.x - ver_w * 0.5
                    local ver_y = line_y + 8

                    -- Draw each character with slight color variation
                    local vchar_x = ver_x
                    for vi = 0, 4 do
                        local vch = version:sub(vi + 1, vi + 1)
                        local vch_size = imgui.CalcTextSizeVec(vch)

                        -- Gold color with slight variation
                        local vr = 230
                        local vg = 190 - vi * 5
                        local vb = 90 + vi * 10
                        local va = math.modf(ver_alpha * 255)

                        -- Shadow
                        dl:AddText(nil, ver_font_size, ImVec2(vchar_x + 1, ver_y + 1), IM_COL32(0, 0, 0, va / 3), vch)
                        -- Main text
                        dl:AddText(nil, ver_font_size, ImVec2(vchar_x, ver_y), IM_COL32(vr, vg, vb, va), vch)

                        vchar_x = vchar_x + (vch_size.x * ver_scale * 1.1)
                    end
                end
            end
        end
    end

    -- ================================================================
    -- FRAME CORNERS
    -- ================================================================

    do
        local corner_alpha = 1.0
        if t < 0.2 then
            corner_alpha = iam.EvalPreset(IamEaseType.OutExpo, t / 0.2)
        elseif t > 9.5 then
            corner_alpha = 1.0 - iam.EvalPreset(IamEaseType.InExpo, (t - 9.5) / 0.5)
        end

        local len = 30.0
        local a = math.modf(corner_alpha * 180)
        local m = 10.0

        dl:AddLine(ImVec2(cp.x + m, cp.y + m), ImVec2(cp.x + m + len, cp.y + m), IM_COL32(91, 194, 231, a), 2.5)
        dl:AddLine(ImVec2(cp.x + m, cp.y + m), ImVec2(cp.x + m, cp.y + m + len), IM_COL32(91, 194, 231, a), 2.5)
        dl:AddLine(ImVec2(cp.x + cs.x - m, cp.y + m), ImVec2(cp.x + cs.x - m - len, cp.y + m), IM_COL32(91, 194, 231, a), 2.5)
        dl:AddLine(ImVec2(cp.x + cs.x - m, cp.y + m), ImVec2(cp.x + cs.x - m, cp.y + m + len), IM_COL32(91, 194, 231, a), 2.5)
        dl:AddLine(ImVec2(cp.x + m, cp.y + cs.y - m), ImVec2(cp.x + m + len, cp.y + cs.y - m), IM_COL32(204, 120, 88, a), 2.5)
        dl:AddLine(ImVec2(cp.x + m, cp.y + cs.y - m), ImVec2(cp.x + m, cp.y + cs.y - m - len), IM_COL32(204, 120, 88, a), 2.5)
        dl:AddLine(ImVec2(cp.x + cs.x - m, cp.y + cs.y - m), ImVec2(cp.x + cs.x - m - len, cp.y + cs.y - m), IM_COL32(204, 120, 88, a), 2.5)
        dl:AddLine(ImVec2(cp.x + cs.x - m, cp.y + cs.y - m), ImVec2(cp.x + cs.x - m, cp.y + cs.y - m - len), IM_COL32(204, 120, 88, a), 2.5)
    end

    -- ================================================================
    -- PROGRESS BAR - White line tracing the border anti-clockwise
    -- Starts from middle of right edge, completes in 10 seconds
    -- ================================================================

    do
        -- Progress 0-1 over the 10 second cycle
        local progress = t / CYCLE

        -- Border coordinates (inset by 1 pixel so line is visible within bounds)
        local left = cp.x
        local right = cp.x + cs.x - 1.0
        local top = cp.y
        local bottom = cp.y + cs.y - 1.0
        local width = right - left
        local height = bottom - top

        -- Calculate perimeter segments (anti-clockwise from mid-right):
        -- Segment 1: Right edge UP (mid -> top): height/2
        -- Segment 2: Top edge LEFT (right -> left): width
        -- Segment 3: Left edge DOWN (top -> bottom): height
        -- Segment 4: Bottom edge RIGHT (left -> right): width
        -- Segment 5: Right edge UP (bottom -> mid): height/2
        local perimeter = 2.0 * width + 2.0 * height
        local seg1 = height * 0.5
        local seg2 = seg1 + width
        local seg3 = seg2 + height
        local seg4 = seg3 + width
        -- seg5 ends at perimeter

        local dist = progress * perimeter -- distance traveled

        -- Starting point: middle of right edge
        local start = ImVec2(right, top + height * 0.5)

        -- Helper to get point at distance along the path
        local get_point = function(d)
            if d <= seg1 then
                -- Segment 1: going UP on right edge
                return ImVec2(right, top + height * 0.5 - d)
            elseif d <= seg2 then
                -- Segment 2: going LEFT on top edge
                local local_ = d - seg1
                return ImVec2(right - local_, top)
            elseif d <= seg3 then
                -- Segment 3: going DOWN on left edge
                local local_ = d - seg2
                return ImVec2(left, top + local_)
            elseif d <= seg4 then
                -- Segment 4: going RIGHT on bottom edge
                local local_ = d - seg3
                return ImVec2(left + local_, bottom)
            else
                -- Segment 5: going UP on right edge (bottom half)
                local local_ = d - seg4
                return ImVec2(right, bottom - local_)
            end
        end

        -- Draw the progress line as multiple segments
        local prog_col = IM_COL32(255, 255, 255, 220)
        local line_thick = 1.0

        -- Draw completed segments
        if dist > 0 then
            -- Segment 1
            if dist > 0 then
                local d1 = math.min(dist, seg1)
                dl:AddLine(start, get_point(d1), prog_col, line_thick)
            end
            -- Segment 2
            if dist > seg1 then
                local d2 = math.min(dist, seg2)
                dl:AddLine(get_point(seg1), get_point(d2), prog_col, line_thick)
            end
            -- Segment 3
            if dist > seg2 then
                local d3 = math.min(dist, seg3)
                dl:AddLine(get_point(seg2), get_point(d3), prog_col, line_thick)
            end
            -- Segment 4
            if dist > seg3 then
                local d4 = math.min(dist, seg4)
                dl:AddLine(get_point(seg3), get_point(d4), prog_col, line_thick)
            end
            -- Segment 5
            if dist > seg4 then
                dl:AddLine(get_point(seg4), get_point(dist), prog_col, line_thick)
            end

            -- Draw a bright dot at the current position
            local head = get_point(dist)
            dl:AddCircleFilled(head, 5.0, IM_COL32(255, 255, 255, 255))
            dl:AddCircle(head, 8.0, IM_COL32(255, 255, 255, 100), 12, 2.0)
        end
    end

    imgui.Dummy(cs)
    imgui.Spacing()
end

-- ============================================================
-- SECTION: Easing Functions
-- ============================================================

local easing_state = {
    selected_ease = 6,
    preview_time = 0.0,
    preview_playing = false,
    ease_names = {
        "iam_ease_linear",
        "iam_ease_in_quad", "iam_ease_out_quad", "iam_ease_in_out_quad",
        "iam_ease_in_cubic", "iam_ease_out_cubic", "iam_ease_in_out_cubic",
        "iam_ease_in_quart", "iam_ease_out_quart", "iam_ease_in_out_quart",
        "iam_ease_in_quint", "iam_ease_out_quint", "iam_ease_in_out_quint",
        "iam_ease_in_sine", "iam_ease_out_sine", "iam_ease_in_out_sine",
        "iam_ease_in_expo", "iam_ease_out_expo", "iam_ease_in_out_expo",
        "iam_ease_in_circ", "iam_ease_out_circ", "iam_ease_in_out_circ",
        "iam_ease_in_back", "iam_ease_out_back", "iam_ease_in_out_back",
        "iam_ease_in_elastic", "iam_ease_out_elastic", "iam_ease_in_out_elastic",
        "iam_ease_in_bounce", "iam_ease_out_bounce", "iam_ease_in_out_bounce",
    },
    -- Easing info: name, enum value
    eases = {
        { name = "Linear",        type = IamEaseType.Linear },
        { name = "In Quad",       type = IamEaseType.InQuad },
        { name = "Out Quad",      type = IamEaseType.OutQuad },
        { name = "InOut Quad",    type = IamEaseType.InOutQuad },
        { name = "In Cubic",      type = IamEaseType.InCubic },
        { name = "Out Cubic",     type = IamEaseType.OutCubic },
        { name = "InOut Cubic",   type = IamEaseType.InOutCubic },
        { name = "In Quart",      type = IamEaseType.InQuart },
        { name = "Out Quart",     type = IamEaseType.OutQuart },
        { name = "InOut Quart",   type = IamEaseType.InOutQuart },
        { name = "In Quint",      type = IamEaseType.InQuint },
        { name = "Out Quint",     type = IamEaseType.OutQuint },
        { name = "InOut Quint",   type = IamEaseType.InOutQuint },
        { name = "In Sine",       type = IamEaseType.InSine },
        { name = "Out Sine",      type = IamEaseType.OutSine },
        { name = "InOut Sine",    type = IamEaseType.InOutSine },
        { name = "In Expo",       type = IamEaseType.InExpo },
        { name = "Out Expo",      type = IamEaseType.OutExpo },
        { name = "InOut Expo",    type = IamEaseType.InOutExpo },
        { name = "In Circ",       type = IamEaseType.InCirc },
        { name = "Out Circ",      type = IamEaseType.OutCirc },
        { name = "InOut Circ",    type = IamEaseType.InOutCirc },
        { name = "In Back",       type = IamEaseType.InBack },
        { name = "Out Back",      type = IamEaseType.OutBack },
        { name = "InOut Back",    type = IamEaseType.InOutBack },
        { name = "In Elastic",    type = IamEaseType.InElastic },
        { name = "Out Elastic",   type = IamEaseType.OutElastic },
        { name = "InOut Elastic", type = IamEaseType.InOutElastic },
        { name = "In Bounce",     type = IamEaseType.InBounce },
        { name = "Out Bounce",    type = IamEaseType.OutBounce },
        { name = "InOut Bounce",  type = IamEaseType.InOutBounce },
    },

    bezier = { 0.25, 0.1, 0.25, 1.0 },
    bezier_preview_time = 0.0,
    bezier_playing = false,

    mass = 1.0,
    stiffness = 120.0,
    damping = 20.0,
    v0 = 0.0,
    spring_preview_time = 0.0,
    spring_playing = false,

    step_count = 5,
    step_mode = 1,
    steps_preview_time = 0.0,
    steps_playing = false,

    gallery_time = 0.0,
    gallery_playing = true,
    gallery_duration = 1.5,
}

local function ShowEasingDemo()
    local dt = GetSafeDeltaTime()
    local state = easing_state

    imgui.TextWrapped(
        "im_anim supports 30+ easing functions inspired by anime.js and CSS transitions. " ..
        "Each easing controls the rate of change during an animation.")

    imgui.Spacing()

    -- Easing preview
    imgui.AlignTextToFramePadding()
    imgui.Text("Preset:")
    imgui.SameLine()
    imgui.SetNextItemWidth(350)
    state.selected_ease = imgui.Combo("##iam_ease_preset", state.selected_ease, state.ease_names, #state.ease_names)

    imgui.SameLine()
    if imgui.Button(state.preview_playing and "Reset##EasePreview" or "Play##EasePreview") then
        state.preview_playing = not state.preview_playing
        state.preview_time = 0.0
    end

    local ease_enum = state.selected_ease - 1

    -- Show parameter info for eases that have them
    if ease_enum >= IamEaseType.InBack and ease_enum <= IamEaseType.InOutBack then
        imgui.TextDisabled("Parameters: overshoot (default: 1.70158)")
    elseif ease_enum >= IamEaseType.InElastic and ease_enum <= IamEaseType.InOutElastic then
        imgui.TextDisabled("Parameters: amplitude (default: 1.0), period (default: 0.3)")
    end

    if state.preview_playing then
        state.preview_time = state.preview_time + dt
        if state.preview_time > 2.0 then state.preview_time = 0.0 end
    end

    -- Draw easing curve
    imgui.Spacing()
    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(300, 300)
    local draw_list = imgui.GetWindowDrawList()

    -- Background
    draw_list:AddRectFilled(canvas_pos,
        ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(40, 40, 45, 255))
    draw_list:AddRect(canvas_pos,
        ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
        IM_COL32(80, 80, 85, 255))

    -- Grid lines
    for i = 1, 3 do
        local x = canvas_pos.x + canvas_size.x * (i / 4.0)
        local y = canvas_pos.y + canvas_size.y * (i / 4.0)
        draw_list:AddLine(ImVec2(x, canvas_pos.y), ImVec2(x, canvas_pos.y + canvas_size.y), IM_COL32(60, 60, 65, 255))
        draw_list:AddLine(ImVec2(canvas_pos.x, y), ImVec2(canvas_pos.x + canvas_size.x, y), IM_COL32(60, 60, 65, 255))
    end

    -- Draw curve using direct evaluation
    local prev_pt = ImVec2(canvas_pos.x, canvas_pos.y + canvas_size.y)

    for i = 1, 100 do
        local t = i / 100.0
        local val = iam.EvalPreset(ease_enum, t)

        -- Clamp for display (elastic/back can overshoot)
        local display_val = val
        if display_val < -0.2 then display_val = -0.2 end
        if display_val > 1.2 then display_val = 1.2 end

        local pt = ImVec2(
            canvas_pos.x + canvas_size.x * t,
            canvas_pos.y + canvas_size.y * (1.0 - display_val))

        draw_list:AddLine(prev_pt, pt, IM_COL32(100, 180, 255, 255), 2.0)
        prev_pt = pt
    end

    -- Animated ball
    if state.preview_playing and state.preview_time <= 1.5 then
        local t = state.preview_time / 1.5  -- Normalize to 0-1 over 1.5 seconds
        if t > 1.0 then t = 1.0 end

        local eased = iam.EvalPreset(ease_enum, t)

        -- Clamp for display
        local display_eased = eased
        if display_eased < -0.2 then display_eased = -0.2 end
        if display_eased > 1.2 then display_eased = 1.2 end

        local ball_x = canvas_pos.x + canvas_size.x * t
        local ball_y = canvas_pos.y + canvas_size.y * (1.0 - display_eased)
        draw_list:AddCircleFilled(ImVec2(ball_x, ball_y), 8.0, IM_COL32(255, 100, 100, 255))

        -- Also show horizontal position bar
        local bar_y = canvas_pos.y + canvas_size.y + 20
        draw_list:AddRectFilled(ImVec2(canvas_pos.x, bar_y),
            ImVec2(canvas_pos.x + canvas_size.x, bar_y + 20),
            IM_COL32(40, 40, 45, 255))
        local bar_x = canvas_pos.x + canvas_size.x * math.max(0.0, math.min(eased, 1.0))
        draw_list:AddCircleFilled(ImVec2(bar_x, bar_y + 10), 8.0, IM_COL32(100, 255, 100, 255))
    end

    imgui.Dummy(ImVec2(canvas_size.x, canvas_size.y + 40))

    -- Custom easing section
    ApplyOpenAll()
    if imgui.TreeNode("Custom Bezier Curve") then
        state.bezier[1] = imgui.SliderFloat("x1", state.bezier[1], 0.0, 1.0)
        state.bezier[2] = imgui.SliderFloat("y1", state.bezier[2], -1.0, 2.0)
        state.bezier[3] = imgui.SliderFloat("x2", state.bezier[3], 0.0, 1.0)
        state.bezier[4] = imgui.SliderFloat("y2", state.bezier[4], -1.0, 2.0)

        if imgui.Button(state.bezier_playing and "Reset##bezier" or "Play##bezier") then
            state.bezier_playing = not state.bezier_playing
            state.bezier_preview_time = 0.0
        end

        if state.bezier_playing then
            state.bezier_preview_time = state.bezier_preview_time + dt
            if state.bezier_preview_time > 2.0 then state.bezier_preview_time = 0.0 end
        end

        -- Draw bezier curve
        local bezier_canvas_pos = imgui.GetCursorScreenPosVec()
        local bezier_canvas_size = ImVec2(300, 300)
        local bezier_draw_list = imgui.GetWindowDrawList()

        bezier_draw_list:AddRectFilled(bezier_canvas_pos,
            ImVec2(bezier_canvas_pos.x + bezier_canvas_size.x, bezier_canvas_pos.y + bezier_canvas_size.y),
            IM_COL32(40, 40, 45, 255))
        bezier_draw_list:AddRect(bezier_canvas_pos,
            ImVec2(bezier_canvas_pos.x + bezier_canvas_size.x, bezier_canvas_pos.y + bezier_canvas_size.y),
            IM_COL32(80, 80, 85, 255))

        -- Draw control points and handles
        local p0 = ImVec2(bezier_canvas_pos.x, bezier_canvas_pos.y + bezier_canvas_size.y)
        local p1 = ImVec2(bezier_canvas_pos.x + state.bezier[1] * bezier_canvas_size.x,
            bezier_canvas_pos.y + bezier_canvas_size.y * (1.0 - state.bezier[2]))
        local p2 = ImVec2(bezier_canvas_pos.x + state.bezier[3] * bezier_canvas_size.x,
            bezier_canvas_pos.y + bezier_canvas_size.y * (1.0 - state.bezier[4]))
        local p3 = ImVec2(bezier_canvas_pos.x + bezier_canvas_size.x, bezier_canvas_pos.y)

        -- Draw control handles
        bezier_draw_list:AddLine(p0, p1, IM_COL32(255, 100, 100, 150), 1.0)
        bezier_draw_list:AddLine(p3, p2, IM_COL32(100, 100, 255, 150), 1.0)
        bezier_draw_list:AddCircleFilled(p1, 5.0, IM_COL32(255, 100, 100, 255))
        bezier_draw_list:AddCircleFilled(p2, 5.0, IM_COL32(100, 100, 255, 255))

        -- Draw bezier curve
        bezier_draw_list:AddBezierCubic(p0, p1, p2, p3, IM_COL32(100, 255, 100, 255), 2.0, 64)

        -- Animated ball on curve
        if state.bezier_playing and state.bezier_preview_time <= 1.5 then
            local t = state.bezier_preview_time / 1.5
            if t > 1.0 then t = 1.0 end

            -- Evaluate cubic bezier for Y (the eased value)
            local function cubic_bezier_y(x, x1, y1, x2, y2)
                local t_guess = x
                for _ = 1, 5 do
                    local mt = 1.0 - t_guess
                    local bx = 3.0*mt*mt*t_guess*x1 + 3.0*mt*t_guess*t_guess*x2 + t_guess*t_guess*t_guess
                    local dx = 3.0*mt*mt*x1 + 6.0*mt*t_guess*(x2 - x1) + 3.0*t_guess*t_guess*(1.0 - x2)
                    if dx ~= 0.0 then t_guess = t_guess - (bx - x) / dx end
                    if t_guess < 0.0 then t_guess = 0.0 end
                    if t_guess > 1.0 then t_guess = 1.0 end
                end
                local mt = 1.0 - t_guess
                return 3.0*mt*mt*t_guess*y1 + 3.0*mt*t_guess*t_guess*y2 + t_guess*t_guess*t_guess
            end

            local eased = cubic_bezier_y(t, state.bezier[1], state.bezier[2], state.bezier[3], state.bezier[4])
            local ball_x = bezier_canvas_pos.x + bezier_canvas_size.x * t
            local ball_y = bezier_canvas_pos.y + bezier_canvas_size.y * (1.0 - math.max(-0.2, math.min(eased, 1.2)))
            bezier_draw_list:AddCircleFilled(ImVec2(ball_x, ball_y), 6.0, IM_COL32(255, 255, 100, 255))
        end

        imgui.Dummy(bezier_canvas_size)
        imgui.TextDisabled("Usage: iam.EaseBezier(%.2f, %.2f, %.2f, %.2f)",
            state.bezier[1], state.bezier[2], state.bezier[3], state.bezier[4])
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode("Spring Physics") then
        state.mass = imgui.SliderFloat("Mass", state.mass, 0.1, 5.0)
        state.stiffness = imgui.SliderFloat("Stiffness", state.stiffness, 10.0, 500.0)
        state.damping = imgui.SliderFloat("Damping", state.damping, 1.0, 50.0)
        state.v0 = imgui.SliderFloat("Initial Velocity", state.v0, -10.0, 10.0)

        if imgui.Button(state.spring_playing and "Reset##spring" or "Play##spring") then
            state.spring_playing = not state.spring_playing
            state.spring_preview_time = 0.0
        end

        if state.spring_playing then
            state.spring_preview_time = state.spring_preview_time + dt
            if state.spring_preview_time > 3.0 then state.spring_preview_time = 0.0 end
        end

        -- Draw spring response curve
        local spring_canvas_pos = imgui.GetCursorScreenPosVec()
        local spring_canvas_size = ImVec2(300, 180)
        local spring_draw_list = imgui.GetWindowDrawList()

        spring_draw_list:AddRectFilled(spring_canvas_pos,
            ImVec2(spring_canvas_pos.x + spring_canvas_size.x, spring_canvas_pos.y + spring_canvas_size.y),
            IM_COL32(40, 40, 45, 255))
        spring_draw_list:AddRect(spring_canvas_pos,
            ImVec2(spring_canvas_pos.x + spring_canvas_size.x, spring_canvas_pos.y + spring_canvas_size.y),
            IM_COL32(80, 80, 85, 255))

        -- Draw target line at y=1
        local target_y = spring_canvas_pos.y + spring_canvas_size.y * 0.2
        spring_draw_list:AddLine(ImVec2(spring_canvas_pos.x, target_y),
            ImVec2(spring_canvas_pos.x + spring_canvas_size.x, target_y), IM_COL32(100, 100, 100, 100), 1.0)

        -- Spring evaluation function
        local function eval_spring(u, m, k, c, vel0)
            local wn = math.sqrt(k / m)
            local zeta = c / (2.0 * math.sqrt(k * m))
            if zeta < 1.0 then
                local wdn = wn * math.sqrt(1.0 - zeta * zeta)
                local A = 1.0
                local B = (zeta * wn * A + vel0) / wdn
                local e = math.exp(-zeta * wn * u)
                return 1.0 - e * (A * math.cos(wdn * u) + B * math.sin(wdn * u))
            elseif zeta == 1.0 then
                local e = math.exp(-wn * u)
                return 1.0 - e * (1.0 + wn * u)
            else
                local wd = wn * math.sqrt(zeta * zeta - 1.0)
                local e1 = math.exp(-(zeta * wn - wd) * u)
                local e2 = math.exp(-(zeta * wn + wd) * u)
                return 1.0 - 0.5 * (e1 + e2)
            end
        end

        -- Draw spring curve
        local spring_prev_pt = ImVec2(spring_canvas_pos.x, spring_canvas_pos.y + spring_canvas_size.y)
        for i = 1, 100 do
            local t = i / 100.0
            local val = eval_spring(t * 2.0, state.mass, state.stiffness, state.damping, state.v0)  -- 2 seconds worth

            local display_val = math.max(-0.2, math.min(val, 1.4))
            local pt = ImVec2(
                spring_canvas_pos.x + spring_canvas_size.x * t,
                spring_canvas_pos.y + spring_canvas_size.y * (1.0 - display_val * 0.8))

            spring_draw_list:AddLine(spring_prev_pt, pt, IM_COL32(100, 200, 255, 255), 2.0)
            spring_prev_pt = pt
        end

        -- Animated ball
        if state.spring_playing and state.spring_preview_time <= 2.0 then
            local t = state.spring_preview_time / 2.0
            if t > 1.0 then t = 1.0 end

            local val = eval_spring(t * 2.0, state.mass, state.stiffness, state.damping, state.v0)
            local display_val = math.max(-0.2, math.min(val, 1.4))
            local ball_x = spring_canvas_pos.x + spring_canvas_size.x * t
            local ball_y = spring_canvas_pos.y + spring_canvas_size.y * (1.0 - display_val * 0.8)
            spring_draw_list:AddCircleFilled(ImVec2(ball_x, ball_y), 6.0, IM_COL32(255, 100, 100, 255))
        end

        imgui.Dummy(spring_canvas_size)
        imgui.TextDisabled("Usage: iam.EaseSpringDesc(%.1f, %.1f, %.1f, %.1f)",
            state.mass, state.stiffness, state.damping, state.v0)
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode("Steps Easing") then
        state.step_count = imgui.SliderInt("Step Count", state.step_count, 1, 12)
        local mode_names = { "Jump End (0)", "Jump Start (1)", "Jump Both (2)" }
        state.step_mode = imgui.Combo("Step Mode", state.step_mode, mode_names, 3)

        imgui.SameLine()
        if imgui.Button(state.steps_playing and "Reset##steps" or "Play##steps") then
            state.steps_playing = not state.steps_playing
            state.steps_preview_time = 0.0
        end

        if state.steps_playing then
            state.steps_preview_time = state.steps_preview_time + dt
            if state.steps_preview_time > 2.0 then state.steps_preview_time = 0.0 end
        end

        -- Draw steps curve
        local steps_canvas_pos = imgui.GetCursorScreenPosVec()
        local steps_canvas_size = ImVec2(250, 150)
        local steps_draw_list = imgui.GetWindowDrawList()

        steps_draw_list:AddRectFilled(steps_canvas_pos,
            ImVec2(steps_canvas_pos.x + steps_canvas_size.x, steps_canvas_pos.y + steps_canvas_size.y),
            IM_COL32(40, 40, 45, 255))
        steps_draw_list:AddRect(steps_canvas_pos,
            ImVec2(steps_canvas_pos.x + steps_canvas_size.x, steps_canvas_pos.y + steps_canvas_size.y),
            IM_COL32(80, 80, 85, 255))

        -- Steps evaluation function
        local function eval_steps(t, steps, mode)
            if steps < 1 then steps = 1 end
            local s = steps
            if mode == 1 then      -- jump-start
                return math.floor(t * s + 1.0) / s
            elseif mode == 2 then  -- jump-both
                return (math.floor(t * s) + 1.0) / (s + 1.0)
            else                   -- jump-end (default)
                return math.floor(t * s) / s
            end
        end

        local step_mode_0 = state.step_mode - 1

        -- Draw horizontal step lines
        for i = 0, state.step_count do
            local y = steps_canvas_pos.y + steps_canvas_size.y * (1.0 - i / state.step_count)
            steps_draw_list:AddLine(
                ImVec2(steps_canvas_pos.x, y),
                ImVec2(steps_canvas_pos.x + steps_canvas_size.x, y),
                IM_COL32(60, 60, 65, 100), 1.0)
        end

        -- Draw step function
        local prev_val = eval_steps(0.0, state.step_count, step_mode_0)
        for i = 1, 100 do
            local t = i / 100.0
            local val = eval_steps(t, state.step_count, step_mode_0)

            local x0 = steps_canvas_pos.x + steps_canvas_size.x * ((i - 1) / 100.0)
            local x1 = steps_canvas_pos.x + steps_canvas_size.x * t
            local y0 = steps_canvas_pos.y + steps_canvas_size.y * (1.0 - prev_val)
            local y1 = steps_canvas_pos.y + steps_canvas_size.y * (1.0 - val)

            -- Draw horizontal segment
            steps_draw_list:AddLine(ImVec2(x0, y0), ImVec2(x1, y0), IM_COL32(255, 180, 100, 255), 2.0)
            -- Draw vertical jump
            if val ~= prev_val then
                steps_draw_list:AddLine(ImVec2(x1, y0), ImVec2(x1, y1), IM_COL32(255, 180, 100, 100), 1.0)
            end
            prev_val = val
        end

        -- Animated indicator
        if state.steps_playing and state.steps_preview_time <= 1.5 then
            local t = state.steps_preview_time / 1.5
            if t > 1.0 then t = 1.0 end

            local val = eval_steps(t, state.step_count, step_mode_0)
            local ball_x = steps_canvas_pos.x + steps_canvas_size.x * t
            local ball_y = steps_canvas_pos.y + steps_canvas_size.y * (1.0 - val)
            steps_draw_list:AddCircleFilled(ImVec2(ball_x, ball_y), 6.0, IM_COL32(100, 255, 200, 255))
        end

        imgui.Dummy(steps_canvas_size)
        imgui.TextDisabled("Usage: iam.EaseStepsDesc(%d, %d)", state.step_count, step_mode_0)
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode("Easing Gallery") then
        imgui.TextWrapped(
            "Visual grid showing all standard easing functions side-by-side. "
            .. "Red disc shows X (time), green disc shows Y (eased value).")

        state.gallery_playing = imgui.Checkbox("Auto-play", state.gallery_playing)
        imgui.SameLine()
        if imgui.Button("Reset##gallery") then
            state.gallery_time = 0.0
        end
        imgui.SameLine()
        state.gallery_duration = imgui.SliderFloat("Duration##EaseGallery", state.gallery_duration, 0.5, 3.0, "%.1fs")

        if state.gallery_playing then
            state.gallery_time = state.gallery_time + dt
            if state.gallery_time > state.gallery_duration + 0.5 then state.gallery_time = 0.0 end
        end

        local t = state.gallery_time / state.gallery_duration
        if t > 1.0 then t = 1.0 end

        local num_eases = #state.eases

        -- Grid layout - larger cells
        local cell_size = ImVec2(300, 300)
        local avail = imgui.GetContentRegionAvailVec()
        local cols = math.floor(avail.x / (cell_size.x + 10))
        if cols < 1 then cols = 1 end
        if cols > 4 then cols = 4 end

        local gallery_draw_list = imgui.GetWindowDrawList()

        for i = 1, num_eases do
            if (i - 1) % cols ~= 0 then imgui.SameLine() end

            imgui.BeginGroup()

            local cell_pos = imgui.GetCursorScreenPosVec()
            local margin = 12.0
            local label_h = 20.0
            local graph_x = cell_pos.x + margin
            local graph_y = cell_pos.y + label_h
            local graph_w = cell_size.x - margin * 2
            local graph_h = cell_size.y - label_h - margin

            -- Cell background
            gallery_draw_list:AddRectFilled(cell_pos,
                ImVec2(cell_pos.x + cell_size.x, cell_pos.y + cell_size.y),
                IM_COL32(30, 30, 35, 255), 4.0)
            gallery_draw_list:AddRect(cell_pos,
                ImVec2(cell_pos.x + cell_size.x, cell_pos.y + cell_size.y),
                IM_COL32(60, 60, 70, 255), 4.0)

            -- Graph background
            gallery_draw_list:AddRectFilled(ImVec2(graph_x, graph_y),
                ImVec2(graph_x + graph_w, graph_y + graph_h),
                IM_COL32(20, 20, 25, 255), 2.0)

            -- Grid lines
            for g = 1, 3 do
                local gx = graph_x + graph_w * (g / 4.0)
                local gy = graph_y + graph_h * (g / 4.0)
                gallery_draw_list:AddLine(ImVec2(gx, graph_y), ImVec2(gx, graph_y + graph_h), IM_COL32(50, 50, 55, 100))
                gallery_draw_list:AddLine(ImVec2(graph_x, gy), ImVec2(graph_x + graph_w, gy), IM_COL32(50, 50, 55, 100))
            end

            -- Y=0 and Y=1 reference lines
            local y0_line = graph_y + graph_h
            local y1_line = graph_y
            gallery_draw_list:AddLine(ImVec2(graph_x, y0_line), ImVec2(graph_x + graph_w, y0_line), IM_COL32(80, 80, 80, 150))
            gallery_draw_list:AddLine(ImVec2(graph_x, y1_line), ImVec2(graph_x + graph_w, y1_line), IM_COL32(80, 80, 80, 150))

            -- Draw easing curve
            local prev_curve_pt = ImVec2(graph_x, graph_y + graph_h)
            for j = 1, 60 do
                local ct = j / 60.0
                local val = iam.EvalPreset(state.eases[i].type, ct)
                val = math.max(-0.2, math.min(val, 1.2))

                local pt = ImVec2(
                    graph_x + graph_w * ct,
                    graph_y + graph_h - graph_h * val)

                gallery_draw_list:AddLine(prev_curve_pt, pt, IM_COL32(100, 180, 255, 255), 2.0)
                prev_curve_pt = pt
            end

            -- Animated indicators
            if t <= 1.0 then
                local eased = iam.EvalPreset(state.eases[i].type, t)
                local eased_clamped = math.max(-0.2, math.min(eased, 1.2))

                local ball_x = graph_x + graph_w * t
                local ball_y = graph_y + graph_h - graph_h * eased_clamped

                -- X axis indicator (red) - horizontal line with disc
                gallery_draw_list:AddLine(ImVec2(graph_x, ball_y), ImVec2(ball_x, ball_y), IM_COL32(255, 80, 80, 150), 1.0)
                gallery_draw_list:AddCircleFilled(ImVec2(graph_x - 6, ball_y), 5.0, IM_COL32(255, 80, 80, 255))

                -- Y axis indicator (green) - vertical line with disc
                gallery_draw_list:AddLine(ImVec2(ball_x, graph_y + graph_h), ImVec2(ball_x, ball_y), IM_COL32(80, 255, 80, 150), 1.0)
                gallery_draw_list:AddCircleFilled(ImVec2(ball_x, graph_y + graph_h + 6), 5.0, IM_COL32(80, 255, 80, 255))

                -- Ball on curve (yellow)
                gallery_draw_list:AddCircleFilled(ImVec2(ball_x, ball_y), 6.0, IM_COL32(255, 220, 100, 255))
                gallery_draw_list:AddCircle(ImVec2(ball_x, ball_y), 6.0, IM_COL32(255, 255, 255, 200), 0, 1.5)
            end

            -- Label at top
            local text_size = imgui.CalcTextSizeVec(state.eases[i].name)
            local text_pos = ImVec2(cell_pos.x + (cell_size.x - text_size.x) * 0.5, cell_pos.y + 3)
            gallery_draw_list:AddText(text_pos, IM_COL32(220, 220, 220, 255), state.eases[i].name)

            imgui.Dummy(cell_size)
            imgui.EndGroup()
        end

        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Custom Easing
-- ============================================================
---@param t number
---@return number
local function CustomEaseSmooth(t)
    -- Attempt a smoothstep-like ease
    return t * t * (3.0 - 2.0 * t)
end

---@param t number
---@return number
local function CustomEaseBouncy(t)
    -- Custom bouncy effect
    local n = 7.5625
    local d = 2.75

    if t < 1.0 / d then
        return n * t * t
    end

    if (t < 2.0 / d) then
       t = t - (1.5 / d)
       return n * t * t + 0.75
    end

    if t < 2.5 / d then
        t = t - (2.25 / d)
        return n * t * t + 0.9375
    end

    t = t - (2.625 / d)
    return n * t * t + 0.984375
end

---@param t number
---@return number
local function CustomEaseWobble(t)
    -- Wobble with overshoot
    local result = t + math.sin(t * math.pi * 3.0) * (1.0 - t) * 0.3
    return result
end

local custom_easing_state = {
    initialized = false,
    selected_slot = 0,
    playing = false,
    target = 0.0,
    id = ImHashStr('custom_ease_demo'),
    pos_id = ImHashStr('pos')
}

local function ShowCustomEasingDemo()
    local dt = GetSafeDeltaTime()
    local state = custom_easing_state

    imgui.TextWrapped(
        "Register your own easing functions using iam_register_custom_ease(). " ..
        "You get 16 slots (0-15) for custom easing callbacks.")

    if not state.initialized then
        iam.RegisterCustomEase(0, CustomEaseSmooth)
        iam.RegisterCustomEase(1, CustomEaseBouncy)
        iam.RegisterCustomEase(2, CustomEaseWobble)
        state.initialized = true
    end

    imgui.Spacing()

    -- Show registered slots
    imgui.Text('Registered Custom Easings:')
    imgui.BulletText('Slot 0: Smooth (smoothstep)')
    imgui.BulletText('Slot 1: Bouncy (bounce variation)')
    imgui.BulletText('Slot 2: Wobble (overshoot with sine)')

    imgui.Spacing()
    imgui.Separator()

    -- Interactive demo
    imgui.Text('Test Custom Easing:')
    state.selected_slot = imgui.RadioButton('Smooth##custom', state.selected_slot, 0)
    imgui.SameLine()
    state.selected_slot = imgui.RadioButton('Bouncy##custom', state.selected_slot, 1)
    imgui.SameLine()
    state.selected_slot = imgui.RadioButton('Wobble##custom', state.selected_slot, 2)

    if imgui.Button(state.playing and 'Reset##custom' or 'Play##custom') then
        state.playing = not state.playing
        state.target = state.playing and 1.0 or 0.0
    end

    local value = iam.TweenFloat(state.id, state.pos_id, state.target, 1.0,
        iam.EaseCustomFn(state.selected_slot), IamPolicy.Crossfade, dt)

    -- Draw animated bar
    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_w = imgui.GetContentRegionAvailVec().x
    local canvas_h = 30.0
    local draw_list = imgui.GetWindowDrawList()

    draw_list:AddRectFilled(canvas_pos,
        ImVec2(canvas_pos.x + canvas_w, canvas_pos.y + canvas_h),
        IM_COL32(40, 42, 48, 255), 4.0)

    local bar_w = value * (canvas_w - 10.0)
    draw_list:AddRectFilled(
        ImVec2(canvas_pos.x + 5, canvas_pos.y + 5),
        ImVec2(canvas_pos.x + 5 + bar_w, canvas_pos.y + canvas_h - 5),
        IM_COL32(100, 180, 255, 255), 3.0)

    imgui.Dummy(ImVec2(canvas_w, canvas_h))

    -- Show code example
    imgui.Spacing()
    imgui.TextDisabled('Usage:')
    imgui.TextDisabled('  iam.RegisterCustomEase(0, MyEaseFunc)')
    imgui.TextDisabled('  iam.TweenFloat(id, ch, target, dur, iam.EaseCustomFn(0), policy, dt)')
end

-- ============================================================
-- SECTION: Basic Tweens
-- ============================================================
local basic_tweens_state = {
    float_target = 50.0,
    float_id = ImHashStr('float_demo'),

    vec2_target = ImVec2(150.0, 80.0),
    vec2_id = ImHashStr('vec2_demo'),

    int_target = 50,
    int_id = ImHashStr('int_demo'),

    vec4_target = ImVec4(1.0, 0.5, 0.2, 1.0),
    vec4_id = ImHashStr('vec4_demo'),

    multi_prop_id = ImHashStr('multi_prop_demo'),
    multi_prop_expanded = false,

    wave_active = false,
    wave_time = 0.0,

    spring_stiffness = 180.0,
    spring_damping = 15.0,
    spring_triggered = false,

    counter_target = 0,
    counter_id = ImHashStr('counter_demo'),
}

local function ShowBasicTweensDemo()
    local state = basic_tweens_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        "Tweens smoothly interpolate values over time. Each tween is identified by a unique (id, channel) pair. " ..
        "Call the tween function every frame with your target value - the library handles the animation.")

    imgui.Spacing()
    imgui.Separator()

    -- Float tween
    ApplyOpenAll()
    if imgui.TreeNode('Float Tween') then
        state.float_target = imgui.SliderFloat('Target', state.float_target, 0, 100)
        local value = iam.TweenFloat(state.float_id, 0, state.float_target, 1.0, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        imgui.ProgressBar(value / 100.0, ImVec2(-1, 0), "")
        imgui.SameLine()
        imgui.Text('%.1f', value)

        imgui.TextDisabled('iam.TweenFloat(id, channel, %.1f, 1.0, IamEaseType.OutCubic, IamPolicy.Crossfade, dt)', state.float_target)
        imgui.TreePop()
    end

    -- Vec2 tween
    ApplyOpenAll()
    if imgui.TreeNode('Vec2 Tween') then
        state.vec2_target = imgui.SliderFloatVec2('Target', state.vec2_target, 0.0, 280.0)
        local value = iam.TweenVec2(state.vec2_id, 0, state.vec2_target, 1.0, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Draw a dot at the animated position
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300, 300)
        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
            IM_COL32(40, 40, 45, 255))
        draw_list:AddRect(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
            IM_COL32(80, 80, 85, 255))

        -- Clamp position to canvas
        local draw_x = math.max(0.0, math.min(value.x, canvas_size.x - 10.0))
        local draw_y = math.max(0.0, math.min(value.y, canvas_size.y - 10.0))
        draw_list:AddCircleFilled(ImVec2(canvas_pos.x + draw_x + 10, canvas_pos.y + draw_y + 10), 10.0,
            IM_COL32(100, 200, 255, 255))
        imgui.Dummy(canvas_size)

        imgui.Text('Position: (%.1f, %.1f)', value.x, value.y)
        imgui.TreePop()
    end

    -- Int tween
    ApplyOpenAll()
    if imgui.TreeNode('Int Tween') then
        state.int_target = imgui.SliderInt('Target', state.int_target, 0, 100)
        local value = iam.TweenInt(state.int_id, 0, state.int_target, 1.5, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)

        imgui.Text('Value: %d', value)
        imgui.TextDisabled('Useful for step-based animations, frame indices, etc.')
        imgui.TreePop()
    end

    -- Vec4 tween
    ApplyOpenAll()
    if imgui.TreeNode('Vec4 Tween') then
        state.vec4_target = imgui.ColorEdit4('Target', state.vec4_target)
        local value = iam.TweenVec4(state.vec4_id, 0, state.vec4_target, 1.0, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        imgui.ColorButton('Animated', value, 0, ImVec2(100, 30))
        imgui.SameLine()
        imgui.Text('(%.2f, %.2f, %.2f, %.2f)', value.x, value.y, value.z, value.w)
        imgui.TreePop()
    end

    -- Multi-property animation
    ApplyOpenAll()
    if imgui.TreeNodeEx('Multi-Property Animation') then
        imgui.TextDisabled('Animate multiple properties on the same object with different timings')
        imgui.Spacing()

        if imgui.Button(state.multi_prop_expanded and 'Collapse' or 'Expand') then
            state.multi_prop_expanded = not state.multi_prop_expanded
        end
        imgui.SameLine()

        local id = state.multi_prop_id

        -- Animate multiple properties
        local scale = iam.TweenFloat(id, ImHashStr('scale'), state.multi_prop_expanded and 1.2 or 1.0, 0.4,
            iam.EaseSpringDesc(1.0, 180.0, 15.0, 0.0), IamPolicy.Crossfade, dt)
        local rotation = iam.TweenFloat(id, ImHashStr('rotation'), state.multi_prop_expanded and 45.0 or 0.0, 0.5,
            iam.EasePreset(IamEaseType.OutBack), IamPolicy.Crossfade, dt)
        local alpha = iam.TweenFloat(id, ImHashStr('alpha'), state.multi_prop_expanded and 1.0 or 0.7, 0.3,
            iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, dt)
        local color = iam.TweenColor(id, ImHashStr('color'),
            state.multi_prop_expanded and ImVec4(0.3, 0.8, 0.5, 1.0) or ImVec4(0.5, 0.5, 0.5, 1.0),
            0.6, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)

        -- Draw animated shape
        local center = imgui.GetCursorScreenPosVec()
        center.x = center.x + 80
        center.y = center.y + 60

        local draw_list = imgui.GetWindowDrawList()

        -- Draw rotated and scaled rectangle
        local size = 40.0 * scale
        local rad = rotation * math.pi / 180.0
        local corners = {}
        for i = 1, 4 do
            local angle = rad + (i - 1) * math.pi * 0.5 + math.pi * 0.25
            corners[i] = ImVec2(
                center.x + math.cos(angle) * size * 0.707,
                center.y + math.sin(angle) * size * 0.707
            )
        end

        local col = imgui.ColorConvertFloat4ToU32(ImVec4(color.x, color.y, color.z, alpha))
        draw_list:AddQuadFilled(corners[1], corners[2], corners[3], corners[4], col)
        draw_list:AddQuad(corners[1], corners[2], corners[3], corners[4], IM_COL32(255, 255, 255, math.floor(alpha * 100)), 2.0)

        imgui.Dummy(ImVec2(160, 120))

        imgui.Text('Scale: %.2f  Rotation: %.1f  Alpha: %.2f', scale, rotation, alpha)
        imgui.TreePop()
    end

    -- Staggered wave animation
    ApplyOpenAll()
    if imgui.TreeNode('Staggered Wave Animation') then
        imgui.TextDisabled('Multiple items with offset timing create a wave effect')
        imgui.Spacing()

        if imgui.Button(state.wave_active and 'Reset' or 'Start Wave') then
            state.wave_active = not state.wave_active
            state.wave_time = 0.0
        end

        if state.wave_active then state.wave_time = state.wave_time + dt end
        if state.wave_time > 3.0 then state.wave_time = 0.0 end

        local origin = imgui.GetCursorScreenPosVec()
        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(origin, ImVec2(origin.x + 400, origin.y + 80), IM_COL32(40, 40, 45, 255))

        local num_dots = 12
        for i = 0, num_dots - 1 do
            local id = i + 100
            local stagger_delay = i * 0.08
            local local_time = state.wave_active and math.max(0.0, state.wave_time - stagger_delay) or 0.0
            local normalized_t = math.max(0.0, math.min(local_time / 0.6, 1.0))

            -- Animate Y position with bounce
            local y_offset = iam.TweenFloat(id, ImHashStr('wave_y'),
                state.wave_active and (normalized_t > 0.0 and -25.0 or 0.0) or 0.0,
                0.5, iam.EasePreset(IamEaseType.OutBounce), IamPolicy.Crossfade, dt)

            -- Animate scale (slower for smoother effect)
            local dot_scale = iam.TweenFloat(id, ImHashStr('wave_scale'),
                state.wave_active and (normalized_t > 0.0 and 1.3 or 1.0) or 1.0,
                0.8, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

            -- Animate color
            local dot_color = iam.TweenColor(id, ImHashStr('wave_color'),
                state.wave_active and ImVec4(0.3, 0.7 + i * 0.02, 1.0, 1.0) or ImVec4(0.5, 0.5, 0.5, 1.0),
                0.4, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)

            local x = origin.x + 20 + i * 32
            local y = origin.y + 50 + y_offset
            local radius = 10.0 * dot_scale

            draw_list:AddCircleFilled(ImVec2(x, y), radius, imgui.ColorConvertFloat4ToU32(dot_color))
        end

        imgui.Dummy(ImVec2(400, 80))
        imgui.TreePop()
    end

    -- Spring physics comparison
    ApplyOpenAll()
    if imgui.TreeNode('Spring Physics Comparison') then
        imgui.TextDisabled('Compare different spring parameters - adjust stiffness and damping')
        imgui.Spacing()

        state.spring_stiffness = imgui.SliderFloat('Stiffness', state.spring_stiffness, 50.0, 400.0)
        state.spring_damping = imgui.SliderFloat('Damping', state.spring_damping, 5.0, 40.0)
        if imgui.Button('Trigger Spring') then state.spring_triggered = not state.spring_triggered end

        imgui.Spacing()

        local origin = imgui.GetCursorScreenPosVec()
        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(origin, ImVec2(origin.x + 300, origin.y + 180), IM_COL32(40, 40, 45, 255))

        local spring_configs = {
            { name = 'Bouncy', stiffness = 120.0,                    damping = 8.0,                   color = IM_COL32(255, 100, 100, 255) },
            { name = 'Smooth', stiffness = 200.0,                    damping = 25.0,                  color = IM_COL32(100, 255, 100, 255) },
            { name = 'Stiff',  stiffness = 300.0,                    damping = 30.0,                  color = IM_COL32(100, 100, 255, 255) },
            { name = 'Custom', stiffness = state.spring_stiffness,   damping = state.spring_damping,  color = IM_COL32(255, 255, 100, 255) },
        }

        local vis_width = 300.0
        local text_width = 100.0
        for i = 1, 4 do
            local id = i + 200 - 1
            local cfg = spring_configs[i]
            local x_pos = iam.TweenFloat(id, ImHashStr('spring_x'),
                state.spring_triggered and (vis_width - 20.0) or 20.0,
                1.5, iam.EaseSpringDesc(1.0, cfg.stiffness, cfg.damping, 0.0),
                IamPolicy.Crossfade, dt)

            local y = origin.y + 25 + (i - 1) * 38
            draw_list:AddCircleFilled(ImVec2(origin.x + x_pos, y), 12.0, cfg.color)
            draw_list:AddText(ImVec2(origin.x + vis_width + 10, y - 8), IM_COL32(200, 200, 200, 255), cfg.name)
        end

        imgui.Dummy(ImVec2(vis_width + text_width, 180))
        imgui.TreePop()
    end

    -- Smooth counter animation
    ApplyOpenAll()
    if imgui.TreeNode('Animated Counter') then
        imgui.TextDisabled('Smooth number counting animation using int tweens')
        imgui.Spacing()

        if imgui.Button('+100') then state.counter_target = state.counter_target + 100 end
        imgui.SameLine()
        if imgui.Button('+1000') then state.counter_target = state.counter_target + 1000 end
        imgui.SameLine()
        if imgui.Button('Reset') then state.counter_target = 0 end

        local animated_value = iam.TweenInt(state.counter_id, 0, state.counter_target, 0.8,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        local style = imgui.GetStyle()
        imgui.PushFont(nil, style.FontSizeBase * 2.0)
        imgui.Text('%d', animated_value)
        imgui.PopFont()

        imgui.TextDisabled('Target: %d', state.counter_target)
        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Color Tweens
-- ============================================================
local color_tweens_state = {
    color_a = ImVec4(1.0, 0.0, 0.0, 1.0),
    color_b = ImVec4(0.0, 0.0, 1.0, 1.0),
    toggle = false,
    id = ImHashStr('color_space_demo'),
}

local function ShowColorTweensDemo()
    local state = color_tweens_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        "Color tweening supports multiple color spaces for perceptually pleasing transitions. " ..
        "OKLAB produces the most visually uniform interpolation.")

    imgui.Spacing()

    state.color_a = imgui.ColorEdit4('Color A', state.color_a, ImGuiColorEditFlags.NoInputs)
    imgui.SameLine()
    state.color_b = imgui.ColorEdit4('Color B', state.color_b, ImGuiColorEditFlags.NoInputs)
    imgui.SameLine()
    if imgui.Button('Toggle') then state.toggle = not state.toggle end

    local target = state.toggle and state.color_b or state.color_a

    imgui.Spacing()

    local space_names = { 'sRGB', 'Linear sRGB', 'HSV', 'OKLAB', 'OKLCH' }
    local spaces = { IamColorSpace.SRGB, IamColorSpace.SRGBLinear, IamColorSpace.HSV, IamColorSpace.OKLAB, IamColorSpace.OKLCH }

    for i = 1, #space_names do
        local value = iam.TweenColor(state.id, i - 1, target, 1.5,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, spaces[i], dt)

        imgui.ColorButton(space_names[i], value, 0, ImVec2(120, 40))
        imgui.SameLine()
        imgui.Text('%s', space_names[i])
    end

    imgui.Spacing()
    imgui.TextDisabled('OKLAB/OKLCH avoid muddy middle colors. OKLCH uses cylindrical coords (hue interpolation).')
end

-- ============================================================
-- SECTION: Per-Axis Easing
-- ============================================================
local per_axis_easing_state = {
    -- Vec2 Per-Axis
    ease_x = 3,   -- Out Cubic
    ease_y = 11,  -- Out Bounce
    vec2_target_pos = ImVec2(300, 100),
    vec2_toggle = false,
    vec2_id = ImHashStr('per_axis_vec2_demo'),

    -- Color Per-Channel
    color_ease_r = 3,  -- Out Cubic
    color_ease_g = 6,  -- Out Bounce
    color_ease_b = 5,  -- Out Elastic
    color_toggle = false,
    color_id = ImHashStr('per_axis_color_demo'),

    -- Bounce Landing
    drop_timer = 0.0,
    dropping = false,
    landing_id = ImHashStr('bounce_landing_demo'),
}

local function ShowPerAxisEasingDemo()
    local state = per_axis_easing_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        "Per-axis easing allows different easing functions for each axis of a vector or color. " ..
        "This enables effects like elastic bounce on one axis while smooth motion on another.")

    imgui.Spacing()

    -- Demo 1: Vec2 with different X and Y easing
    ApplyOpenAll()
    if imgui.TreeNode('Vec2 Per-Axis') then
        local ease_names = {
            'Linear', 'Out Quad', 'Out Cubic', 'Out Quart', 'Out Quint',
            'Out Sine', 'Out Expo', 'Out Circ', 'Out Back', 'Out Elastic', 'Out Bounce'
        }
        local ease_vals = {
            IamEaseType.Linear, IamEaseType.OutQuad, IamEaseType.OutCubic, IamEaseType.OutQuart, IamEaseType.OutQuint,
            IamEaseType.OutSine, IamEaseType.OutExpo, IamEaseType.OutCirc, IamEaseType.OutBack, IamEaseType.OutElastic, IamEaseType.OutBounce
        }

        imgui.SetNextItemWidth(150)
        state.ease_x = imgui.Combo('X Easing##vec2', state.ease_x, ease_names)
        imgui.SameLine()
        imgui.SetNextItemWidth(150)
        state.ease_y = imgui.Combo('Y Easing##vec2', state.ease_y, ease_names)

        if imgui.Button('Toggle Position##vec2') then
            state.vec2_toggle = not state.vec2_toggle
            state.vec2_target_pos = state.vec2_toggle and ImVec2(400, 150) or ImVec2(50, 50)
        end

        -- Draw area
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(500, 200)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), IM_COL32(30, 30, 40, 255))
        imgui.Dummy(canvas_size)

        -- Animate with per-axis easing
        local per_axis = IamEasePerAxis(
            iam.EasePreset(ease_vals[state.ease_x]),
            iam.EasePreset(ease_vals[state.ease_y])
        )

        local pos = iam.TweenVec2PerAxis(state.vec2_id, 1, state.vec2_target_pos, 1.5, per_axis, IamPolicy.Crossfade, dt)

        -- Draw animated circle
        draw:AddCircleFilled(ImVec2(canvas_pos.x + pos.x, canvas_pos.y + pos.y), 15.0, IM_COL32(100, 200, 255, 255))

        -- Draw ghost targets
        draw:AddCircle(ImVec2(canvas_pos.x + 50, canvas_pos.y + 50), 18.0, IM_COL32(100, 100, 100, 128), 0, 2.0)
        draw:AddCircle(ImVec2(canvas_pos.x + 400, canvas_pos.y + 150), 18.0, IM_COL32(100, 100, 100, 128), 0, 2.0)

        imgui.TextDisabled('Notice X uses %s, Y uses %s', ease_names[state.ease_x], ease_names[state.ease_y])
        imgui.TreePop()
    end

    -- Demo 2: Color with per-channel easing
    ApplyOpenAll()
    if imgui.TreeNode('Color Per-Channel') then
        local ease_names = {
            'Linear', 'Out Quad', 'Out Cubic', 'Out Back', 'Out Elastic', 'Out Bounce'
        }
        local ease_vals = {
            IamEaseType.Linear, IamEaseType.OutQuad, IamEaseType.OutCubic, IamEaseType.OutBack, IamEaseType.OutElastic, IamEaseType.OutBounce
        }

        imgui.SetNextItemWidth(120)
        state.color_ease_r = imgui.Combo('R Easing', state.color_ease_r, ease_names)
        imgui.SameLine()
        imgui.SetNextItemWidth(120)
        state.color_ease_g = imgui.Combo('G Easing', state.color_ease_g, ease_names)
        imgui.SameLine()
        imgui.SetNextItemWidth(120)
        state.color_ease_b = imgui.Combo('B Easing', state.color_ease_b, ease_names)

        if imgui.Button('Toggle Color##peraxis') then
            state.color_toggle = not state.color_toggle
        end

        local target_color = state.color_toggle and ImVec4(1.0, 0.8, 0.0, 1.0) or ImVec4(0.2, 0.4, 1.0, 1.0)

        local per_axis = IamEasePerAxis(
            iam.EasePreset(ease_vals[state.color_ease_r]),
            iam.EasePreset(ease_vals[state.color_ease_g]),
            iam.EasePreset(ease_vals[state.color_ease_b]),
            iam.EasePreset(IamEaseType.Linear) -- Alpha stays linear
        )

        local color = iam.TweenColorPerAxis(state.color_id, 1, target_color, 2.0, per_axis, IamPolicy.Crossfade, IamColorSpace.SRGB, dt)

        imgui.ColorButton('##color_result', color, 0, ImVec2(200, 60))

        imgui.SameLine()
        imgui.BeginGroup()
        imgui.Text('R: %.2f (ease: %s)', color.x, ease_names[state.color_ease_r])
        imgui.Text('G: %.2f (ease: %s)', color.y, ease_names[state.color_ease_g])
        imgui.Text('B: %.2f (ease: %s)', color.z, ease_names[state.color_ease_b])
        imgui.EndGroup()

        imgui.TextDisabled('Each color channel animates with its own easing function.')
        imgui.TreePop()
    end

    -- Demo 3: Practical example - bounce landing effect
    ApplyOpenAll()
    if imgui.TreeNode('Bounce Landing Effect') then
        if imgui.Button('Drop!') then
            state.dropping = true
            state.drop_timer = 0.0
        end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 200)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), IM_COL32(30, 30, 40, 255))

        -- Ground line
        local ground_y = canvas_pos.y + canvas_size.y - 30
        draw:AddLine(ImVec2(canvas_pos.x, ground_y), ImVec2(canvas_pos.x + canvas_size.x, ground_y), IM_COL32(100, 100, 100, 255), 2.0)
        imgui.Dummy(canvas_size)

        -- Animate: X moves linearly, Y bounces on landing
        local start_pos = ImVec2(50, 20)
        local end_pos = ImVec2(350, canvas_size.y - 50)

        local per_axis = IamEasePerAxis(
            iam.EasePreset(IamEaseType.Linear),     -- X: linear motion
            iam.EasePreset(IamEaseType.OutBounce)   -- Y: bounce on landing
        )

        local target = state.dropping and end_pos or start_pos
        local pos = iam.TweenVec2PerAxis(state.landing_id, 1, target, 1.2, per_axis, IamPolicy.Crossfade, dt)

        -- Draw ball
        draw:AddCircleFilled(ImVec2(canvas_pos.x + pos.x, canvas_pos.y + pos.y), 20.0, IM_COL32(255, 100, 100, 255))

        -- Reset after animation
        if state.dropping then
            state.drop_timer = state.drop_timer + dt
            if state.drop_timer > 2.0 then state.dropping = false end
        end

        imgui.TextDisabled('X: linear motion, Y: bounce on landing - creates natural drop effect.')
        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Tween Policies
-- ============================================================
local policies_state = {
    target = 0.0,
    id_crossfade = ImHashStr('policy_crossfade'),
    id_cut = ImHashStr('policy_cut'),
    id_queue = ImHashStr('policy_queue'),

    target_x_positions = { 30.0, 120.0, 220.0, 320.0 },
    visual_target_idx = 1,
    id_visual_cut = ImHashStr('policy_visual_cut'),
    id_visual_crossfade = ImHashStr('policy_visual_crossfade'),
    id_visual_queue = ImHashStr('policy_visual_queue'),
}

local function ShowPoliciesDemo()
    local state = policies_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        "Policies control how tweens behave when the target changes mid-animation:")

    imgui.BulletText('Crossfade: Smoothly blend into new target (default)')
    imgui.BulletText('Cut: Instantly snap to new target')
    imgui.BulletText('Queue: Finish current animation, then start new one')

    imgui.Spacing()
    imgui.Separator()

    if imgui.Button('Target = 0') then state.target = 0.0 end
    imgui.SameLine()
    if imgui.Button('Target = 50') then state.target = 50.0 end
    imgui.SameLine()
    if imgui.Button('Target = 100') then state.target = 100.0 end

    imgui.Spacing()

    local ez = iam.EasePreset(IamEaseType.OutCubic)

    -- Crossfade
    do
        local value = iam.TweenFloat(state.id_crossfade, 0, state.target, 1.5, ez, IamPolicy.Crossfade, dt)
        imgui.ProgressBar(value / 100.0, ImVec2(250, 0))
        imgui.SameLine()
        imgui.Text('Crossfade: %.1f', value)
    end

    -- Cut
    do
        local value = iam.TweenFloat(state.id_cut, 0, state.target, 1.5, ez, IamPolicy.Cut, dt)
        imgui.ProgressBar(value / 100.0, ImVec2(250, 0))
        imgui.SameLine()
        imgui.Text('Cut: %.1f', value)
    end

    -- Queue
    do
        local value = iam.TweenFloat(state.id_queue, 0, state.target, 1.5, ez, IamPolicy.Queue, dt)
        imgui.ProgressBar(value / 100.0, ImVec2(250, 0))
        imgui.SameLine()
        imgui.Text('Queue: %.1f', value)
    end

    imgui.Spacing()
    imgui.Separator()
    imgui.Spacing()

    -- Visual policy comparison - each policy in its own horizontal lane
    ApplyOpenAll()
    if imgui.TreeNode('Visual Comparison') then
        imgui.TextWrapped("Each row shows the same animation with different policies. " ..
            "Click buttons rapidly to see differences:")
        imgui.BulletText('Cut (green): Jumps instantly to target')
        imgui.BulletText('Crossfade (red): Smoothly transitions, interrupts on new target')
        imgui.BulletText('Queue (blue): Finishes current animation before starting next')
        imgui.Spacing()

        if imgui.Button('A (Left)') then state.visual_target_idx = 1 end
        imgui.SameLine()
        if imgui.Button('B') then state.visual_target_idx = 2 end
        imgui.SameLine()
        if imgui.Button('C') then state.visual_target_idx = 3 end
        imgui.SameLine()
        if imgui.Button('D (Right)') then state.visual_target_idx = 4 end

        local target_x = state.target_x_positions[state.visual_target_idx]

        local origin = imgui.GetCursorScreenPosVec()
        local vis_width = 360.0
        local text_width = 80.0
        local canvas_size = ImVec2(vis_width, 130)
        local draw_list = imgui.GetWindowDrawList()

        -- Background
        draw_list:AddRectFilled(origin, ImVec2(origin.x + vis_width, origin.y + canvas_size.y),
            IM_COL32(40, 40, 45, 255))
        draw_list:AddRect(origin, ImVec2(origin.x + vis_width, origin.y + canvas_size.y),
            IM_COL32(80, 80, 85, 255))

        -- Draw vertical lines at target positions
        for i = 1, 4 do
            local x = origin.x + state.target_x_positions[i]
            local col = (i == state.visual_target_idx) and IM_COL32(255, 255, 100, 100) or IM_COL32(80, 80, 80, 100)
            draw_list:AddLine(ImVec2(x, origin.y), ImVec2(x, origin.y + canvas_size.y), col, 1.0)
        end

        -- Lane labels (on right side)
        local lane_height = 40.0
        local y_cut = origin.y + 20.0
        local y_crossfade = origin.y + 20.0 + lane_height
        local y_queue = origin.y + 20.0 + lane_height * 2

        draw_list:AddText(ImVec2(origin.x + vis_width + 10, y_cut - 4), IM_COL32(100, 255, 100, 180), 'Cut')
        draw_list:AddText(ImVec2(origin.x + vis_width + 10, y_crossfade - 4), IM_COL32(255, 100, 100, 180), 'Crossfade')
        draw_list:AddText(ImVec2(origin.x + vis_width + 10, y_queue - 4), IM_COL32(100, 100, 255, 180), 'Queue')

        local ez_vis = iam.EasePreset(IamEaseType.OutCubic)

        -- Cut square (green) - top lane - should jump instantly
        do
            local x = iam.TweenFloat(state.id_visual_cut, 0, target_x, 0.8, ez_vis, IamPolicy.Cut, dt)
            draw_list:AddRectFilled(
                ImVec2(origin.x + x - 14, y_cut - 14),
                ImVec2(origin.x + x + 14, y_cut + 14),
                IM_COL32(100, 255, 100, 255))
        end

        -- Crossfade square (red) - middle lane - smooth transition
        do
            local x = iam.TweenFloat(state.id_visual_crossfade, 0, target_x, 0.8, ez_vis, IamPolicy.Crossfade, dt)
            draw_list:AddRectFilled(
                ImVec2(origin.x + x - 14, y_crossfade - 14),
                ImVec2(origin.x + x + 14, y_crossfade + 14),
                IM_COL32(255, 100, 100, 255))
        end

        -- Queue square (blue) - bottom lane - finishes before starting next
        do
            local x = iam.TweenFloat(state.id_visual_queue, 0, target_x, 0.8, ez_vis, IamPolicy.Queue, dt)
            draw_list:AddRectFilled(
                ImVec2(origin.x + x - 14, y_queue - 14),
                ImVec2(origin.x + x + 14, y_queue + 14),
                IM_COL32(100, 100, 255, 255))
        end

        imgui.Dummy(ImVec2(vis_width + text_width, canvas_size.y))
        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Clip System
-- ============================================================

-- Clip IDs
local CLIP_FADE_IN = 0x1001
local CLIP_BOUNCE = 0x1002
local CLIP_COLOR_CYCLE = 0x1003
local CLIP_COMPLEX = 0x1004
local CLIP_DELAYED = 0x1005
local CLIP_WITH_CALLBACKS = 0x1006
local CLIP_INT_ANIM = 0x1007
local CLIP_SEQUENTIAL = 0x1008
local CLIP_PARALLEL = 0x1009
local CLIP_STAGGER = 0x100A
local CLIP_STAGGER_LIST = 0x100B
local CLIP_STAGGER_GRID = 0x100C
local CLIP_STAGGER_CARDS = 0x100D
local CLIP_COLOR_OKLCH = 0x100E
local CLIP_VAR_BOUNCE = 0x100F
local CLIP_VAR_DECAY = 0x1010
local CLIP_VAR_RANDOM = 0x1011
local CLIP_VAR_COLOR = 0x1012
local CLIP_VAR_TIMING = 0x1013
local CLIP_VAR_PARTICLES = 0x1014
local CLIP_VAR_RACE = 0x1015

-- Channel IDs for clips
local CLIP_CH_ALPHA = 0x2001
local CLIP_CH_SCALE = 0x2002
local CLIP_CH_OFFSET = 0x2003
local CLIP_CH_COLOR = 0x2004
local CLIP_CH_ROTATION = 0x2005
local CLIP_CH_COUNTER = 0x2006
local CLIP_CH_POS_X = 0x2007
local CLIP_CH_POS_Y = 0x2008

-- Callback state for demo
local s_callback_begin_count = 0
local s_callback_update_count = 0
local s_callback_complete_count = 0

local s_clips_initialized = false

local function InitDemoClips()
    if s_clips_initialized then
        return
    end
    s_clips_initialized = true

    -- Clip 1: Simple fade in with scale
    IamClip.Begin(CLIP_FADE_IN)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_ALPHA, 0.8, 1.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.5, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_SCALE, 0.8, 1.0, IamEaseType.OutCubic)
        :End()

    -- Clip 2: Bounce with multiple keyframes
    local spring = IamSpringParams{mass = 1.0, stiffness = 180.0, damping = 22.0, initial_velocity = 0.0 }
    IamClip.Begin(CLIP_BOUNCE)
        :KeyVec2(CLIP_CH_OFFSET, 0.0, ImVec2(0, -50), IamEaseType.Linear)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.6, IamEaseType.Linear)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.3, IamEaseType.Linear)
        :KeyVec2(CLIP_CH_OFFSET, 0.3, ImVec2(0, 10), IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_ALPHA, 0.3, 1.0, IamEaseType.OutQuad)
        :KeyVec2(CLIP_CH_OFFSET, 0.5, ImVec2(0, -15), IamEaseType.OutQuad)
        :KeyVec2(CLIP_CH_OFFSET, 0.7, ImVec2(0, 5), IamEaseType.OutQuad)
        :KeyVec2(CLIP_CH_OFFSET, 0.9, ImVec2(0, 0), IamEaseType.OutBounce)
        :KeyFloatSpring(CLIP_CH_SCALE, 0.3, 1.0, spring)
        :End()

    -- Clip 3: Color cycle (looping)
    IamClip.Begin(CLIP_COLOR_CYCLE)
        :KeyVec4(CLIP_CH_COLOR, 0.0, ImVec4(1.0, 0.3, 0.3, 1.0), IamEaseType.InOutSine)
        :KeyVec4(CLIP_CH_COLOR, 1.5, ImVec4(1.0, 1.0, 0.3, 1.0), IamEaseType.InOutSine)
        :KeyVec4(CLIP_CH_COLOR, 3.0, ImVec4(0.3, 1.0, 0.3, 1.0), IamEaseType.InOutSine)
        :KeyVec4(CLIP_CH_COLOR, 4.5, ImVec4(0.3, 1.0, 1.0, 1.0), IamEaseType.InOutSine)
        :KeyVec4(CLIP_CH_COLOR, 6.0, ImVec4(0.3, 0.3, 1.0, 1.0), IamEaseType.InOutSine)
        :KeyVec4(CLIP_CH_COLOR, 7.5, ImVec4(1.0, 0.3, 1.0, 1.0), IamEaseType.InOutSine)
        :KeyVec4(CLIP_CH_COLOR, 9.0, ImVec4(1.0, 0.3, 0.3, 1.0), IamEaseType.InOutSine)
        :SetLoop(true, IamDirection.Normal, -1)
        :End();

    -- Clip 4: Complex multi-channel animation (slower)
    IamClip.Begin(CLIP_COMPLEX)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0,  IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_ALPHA, 0.8, 1.0,  IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.3,  IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_SCALE, 0.6, 1.08,  IamEaseType.InOutCubic)
        :KeyFloat(CLIP_CH_SCALE, 1.0, 0.97,  IamEaseType.InOutSine)
        :KeyFloat(CLIP_CH_SCALE, 1.5, 1.0,  IamEaseType.OutCubic)
        :KeyVec2(CLIP_CH_OFFSET, 0.0, ImVec2(-80, 0),  IamEaseType.OutCubic)
        :KeyVec2(CLIP_CH_OFFSET, 0.5, ImVec2(8, 0),  IamEaseType.InOutCubic)
        :KeyVec2(CLIP_CH_OFFSET, 1.0, ImVec2(0, 0),  IamEaseType.OutCubic)
        :KeyVec4(CLIP_CH_COLOR, 0.0, ImVec4(1.0, 1.0, 1.0, 1.0),  IamEaseType.OutCubic)
        :KeyVec4(CLIP_CH_COLOR, 0.6, ImVec4(1.0, 0.8, 0.3, 1.0),  IamEaseType.InOutCubic)
        :KeyVec4(CLIP_CH_COLOR, 1.5, ImVec4(0.3, 0.7, 1.0, 1.0),  IamEaseType.OutCubic)
        :End()

    -- Clip 6: Animation with callbacks
    IamClip.Begin(CLIP_WITH_CALLBACKS)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.5, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_SCALE, 0.5, 1.2, IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_SCALE, 1.0, 1.0, IamEaseType.InOutSine)
        :OnBegin(function () s_callback_begin_count = s_callback_begin_count + 1 end)
        :OnUpdate(function () s_callback_update_count = s_callback_update_count + 1 end)
        :OnComplete(function () s_callback_complete_count = s_callback_complete_count + 1 end)
        :End()
end

local clip_state = {
    basic_fade_inst_id = ImHashStr('fade_inst'),
    basic_bounce_inst_id = ImHashStr('bounce_inst'),
    basic_complex_inst_id = ImHashStr('complex_inst'),

    looping_inst_id = ImHashStr('loop_inst'),
    looping_playing = false,

    calbacks_inst_id = ImHashStr('callback_inst'),
}

local function ShowClipSystemDemo()
    local dt = GetSafeDeltaTime()
    InitDemoClips()

    imgui.TextWrapped(
        "The Clip system provides timeline-based animations with multiple keyframes. " ..
        "Define clips once, then play them on instances with full playback control.")

    imgui.Spacing()
    imgui.Separator()

    -- Basic clip playback
    ApplyOpenAll()
    if imgui.TreeNodeEx('Basic Playback') then
        -- Fade In with scale
        do
            local inst_id = clip_state.basic_fade_inst_id
            if imgui.Button('Play Fade+Scale') then
                iam.Play(CLIP_FADE_IN, inst_id)
            end
            imgui.SameLine()

            local inst = iam.GetInstance(inst_id)
            local alpha = 1.0
            local scale = 1.0

            if inst:Valid() then
                _, alpha = inst:GetFloat(CLIP_CH_ALPHA)
                _, scale = inst:GetFloat(CLIP_CH_SCALE)
            end
            -- Clamp scale to valid range for SetWindowFontScale
            if scale < 0.1 then scale = 0.1 end
            if scale > 10.0 then scale = 10.0 end

            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushFont(imgui.GetDefaultFont(), 16 * scale)
            imgui.Text('Fading Text (a:%.2f s:%.2f)', alpha, scale)
            imgui.PopFont()
            imgui.PopStyleVar()
        end

        imgui.Spacing()

        -- Bounce
        do
            local inst_id = clip_state.basic_bounce_inst_id
            if imgui.Button('Play Bounce') then
                iam.Play(CLIP_BOUNCE, inst_id)
            end
            imgui.SameLine()

            local inst = iam.GetInstance(inst_id)
            local offset = ImVec2(0, 0)
            local scale = 1.0
            local alpha = 1.0

            if inst:Valid() then
                _, offset = inst:GetVec2(CLIP_CH_OFFSET)
                _, scale = inst:GetFloat(CLIP_CH_SCALE)
                _, alpha = inst:GetFloat(CLIP_CH_ALPHA)
            end
            -- Clamp scale to valid range for SetWindowFontScale
            if scale < 0.1 then scale = 0.1 end
            if scale > 10.0 then scale = 10.0 end

            local cur = imgui.GetCursorPosVec()
            imgui.SetCursorPos(cur + offset)
            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushFont(imgui.GetDefaultFont(), 16 * scale)
            imgui.Text('Bouncing!')
            imgui.PopFont()
            imgui.PopStyleVar()
        end

        imgui.Spacing()

        -- Complex
        do
            local inst_id = clip_state.basic_complex_inst_id
            if imgui.Button('Play Complex') then
                iam.Play(CLIP_COMPLEX, inst_id)
            end
            imgui.SameLine()

            local inst = iam.GetInstance(inst_id)
            local alpha = 1.0
            local scale = 1.0
            local offset = ImVec2(0, 0)
            local color = ImVec4(1, 1, 1, 1)
            if inst:Valid() then
                _, alpha = inst:GetFloat(CLIP_CH_ALPHA)
                _, scale = inst:GetFloat(CLIP_CH_SCALE)
                _, offset = inst:GetVec2(CLIP_CH_OFFSET)
                _, color = inst:GetVec4(CLIP_CH_COLOR)
            end
            -- Clamp scale to valid range for SetWindowFontScale
            if scale < 0.1 then scale = 0.1 end
            if scale > 10.0 then scale = 10.0 end

            local cur = imgui.GetCursorPosVec()
            imgui.SetCursorPos(cur + offset)
            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushFont(imgui.GetDefaultFont(), 16 * scale)
            imgui.TextColored(color, 'Multi-channel Animation')
            imgui.PopFont()
            imgui.PopStyleVar()
        end

        imgui.Spacing()
        imgui.TextWrapped("Note: Font scale animations may appear slightly jumpy due to text rasterization. " ..
            "Small scale changes (e.g. 1.05 to 1.0) produce sub-pixel differences that don't render smoothly.")

        imgui.TreePop()
    end

    -- Looping animations
    ApplyOpenAll()
    if imgui.TreeNode('Looping Animations') then
        local inst_id = clip_state.looping_inst_id

        if not clip_state.looping_playing then
            if imgui.Button('Start Color Cycle') then
                iam.Play(CLIP_COLOR_CYCLE, inst_id)
                clip_state.looping_playing = true
            end
        else
            if imgui.Button('Stop') then
                local inst = iam.GetInstance(inst_id)
                if inst:Valid() then
                    inst:Stop()
                end
            end
        end

        imgui.SameLine()

        local inst = iam.GetInstance(inst_id)
        local color = ImVec4(1, 1, 1, 1)
        local time = 0.0
        if inst:Valid() then
            _, color = inst:GetVec4(CLIP_CH_COLOR)
            time = inst:Time()
        end

        -- Draw as a larger square
        local pos = imgui.GetCursorScreenPosVec()
        local draw_list = imgui.GetWindowDrawList()
        local square_size = ImVec2(100, 100)

        draw_list:AddRectFilled(pos, pos + square_size, imgui.ColorConvertFloat4ToU32(color), 8.0)
        imgui.Dummy(square_size)

        imgui.SameLine()
        imgui.Text('Time: %.2fs / 9.0s', time)

        imgui.TreePop()
    end

    -- Playback control

    -- Delayed Playback

    -- Callbacks
    ApplyOpenAll()
    if imgui.TreeNode('Callbacks') then
        imgui.TextWrapped(
            "on_begin(), on_update(), and on_complete() let you hook into animation lifecycle events.")

        local inst_id = clip_state.calbacks_inst_id

        if imgui.Button('Play with Callbacks') then
            iam.Play(CLIP_WITH_CALLBACKS, inst_id)
        end

        imgui.SameLine()

        if imgui.Button('Reset Counters') then
            s_callback_begin_count = 0
            s_callback_update_count = 0
            s_callback_complete_count = 0
        end

        local inst = iam.GetInstance(inst_id)
        local scale = 1.0
        if inst:Valid() then
            _, scale = inst:GetFloat(CLIP_CH_SCALE)
        end
        -- Clamp scale to valid range for SetWindowFontScale
        if scale < 0.1 then scale = 0.1 end
        if scale > 10.0 then scale = 10.0 end

        imgui.SameLine()
        imgui.PushFont(imgui.GetDefaultFont(), 16 * scale)
        imgui.Text('Scaling')
        imgui.PopFont()

        imgui.Text('on_begin called:    %d times', s_callback_begin_count)
        imgui.Text('on_update called:   %d times', s_callback_update_count)
        imgui.Text('on_complete called: %d times', s_callback_complete_count)
        
        imgui.TreePop()
    end
end

local function ImAnimDemoWindow()
    if not openGUI then
        return
    end

    imgui.SetNextWindowSize(ImVec2(650, 750), ImGuiCond.FirstUseEver)
    local draw
    openGUI, draw = imgui.Begin('Anim Demo (lua)', openGUI)
    if not draw then
        imgui.End()
        return
    end

    imgui.Text('Anim %s', '1.0')
    imgui.TextDisabled('Animation helpers for Dear ImGui')

    -- Debug window toggle
    show_debug_window = imgui.Checkbox('Show Debug Window', show_debug_window)
    imgui.SameLine()
    imgui.TextDisabled('(time scale, stats, profiler)')

    -- Open/Close all sections (uses global s_open_all)
    if imgui.Button('Open All') then
        s_open_all = 1
    end
    imgui.SameLine()
    if imgui.Button('Close All') then
        s_open_all = -1
    end

    imgui.Separator()

    -- Begin scrollable child for all demo content
    imgui.BeginChild('DemoContent', ImVec2(0, 0), ImGuiChildFlags.None, ImGuiWindowFlags.None)

    -- ========================================
    -- HERO ANIMATION (Showcase)
    -- ========================================
    iam.ProfilerBegin('Hero Animation (lua)')
    ShowHeroAnimation()
    iam.ProfilerEnd()

    imgui.Separator()
    imgui.Spacing()

    -- ========================================
    -- 1. EASING & TWEENS
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Easing & Tweens') then
        iam.ProfilerBegin('Easing & Tweens (lua)')

        ApplyOpenAll()
        if imgui.TreeNode('Easing Function') then
            ShowEasingDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Custom Easing') then
            ShowCustomEasingDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Basic Tweens') then
            ShowBasicTweensDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Color Tweens') then
            ShowColorTweensDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Per-Axis Easing') then
            ShowPerAxisEasingDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Tween Policies') then
            ShowPoliciesDemo()
            imgui.TreePop()
        end
    end

    -- ========================================
    -- 2. INTERACTIVE WIDGETS
    -- ========================================

    -- ========================================
    -- 3. CLIP-BASED ANIMATIONS
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Clip-Based Animations') then
        iam.ProfilerBegin('Clip-Based Animations (lua)')

        ApplyOpenAll()
        if imgui.TreeNode('Clip System') then
            ShowClipSystemDemo()
            imgui.TreePop()
        end
    end

    -- Reset open/class all state after processing all headers
    s_open_all = 0

    -- Footer (inside child)
    imgui.Separator()
    imgui.TextDisabled('%.2f ms/frame (%.1f FPS)', io.DeltaTime * 1000, io.Framerate)

    imgui.EndChild() -- End scrollable content
    imgui.End()

    if show_debug_window then
        iam.ProfilerBegin('Unified Inspector (lua)')
        show_debug_window = iam.ShowUnifiedInspector(show_debug_window)
        iam.ProfilerEnd()
    end
end


imgui.Register('ImAnimDemo', function()
    ImAnimDemoWindow()
end)

while openGUI do
    mq.delay(1000)
end
