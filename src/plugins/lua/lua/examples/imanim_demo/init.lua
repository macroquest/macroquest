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

local easing_state = {}

local function ShowEasingDemo()
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
    float_id = ImHashStr('float_demo')
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
