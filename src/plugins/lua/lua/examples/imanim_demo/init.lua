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
                local a = math.floor(alpha * 200)

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
                local a = math.floor(alpha * 255)
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
                local a = math.floor(alpha * 200)
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
                local a = math.floor(alpha * 200)
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
                local a = math.floor(alpha * 200)
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
                local a = math.floor(alpha * 200)
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
                local a = math.floor(alpha * 180)
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
                local a = math.floor(alpha * 180)
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
                    local a = math.floor(alpha * 200)
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
                local a = math.floor(alpha * 180)
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
                local a = math.floor(alpha * 180)
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
                    local a = math.floor(alpha * 200)
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
                local a = math.floor(alpha * 150)
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
                    local a = math.floor(alpha * 180)
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
                local r = math.floor(91 + (204 - 91) * hue_t)
                local g = math.floor(194 + (120 - 194) * hue_t)
                local b = math.floor(231 + (88 - 231) * hue_t)
                local a = math.floor(logo_alpha * 255)

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
                local la = math.floor(logo_alpha * 200)
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
                        local va = math.floor(ver_alpha * 255)

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
        local a = math.floor(corner_alpha * 180)
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
        canvas_pos + canvas_size,
        IM_COL32(40, 40, 45, 255))
    draw_list:AddRect(canvas_pos,
        canvas_pos + canvas_size,
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
        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(40, 40, 45, 255))
        draw_list:AddRect(canvas_pos, canvas_pos + canvas_size,
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

        imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * 2.0)
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
        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))
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
        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))

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
-- SECTION: Interactive Widgets
-- ============================================================
local widgets_demo_state = {
    toggle = false,
    -- Animated Buttons channel IDs
    alpha_id = ImHashStr('alpha'),
    scale_id = ImHashStr('scale'),
    offset_id = ImHashStr('offset'),
    color_id = ImHashStr('color'),
    -- Animated Toggle IDs
    toggle_id = ImHashStr('toggle_demo'),
    bg_id = ImHashStr('bg'),
    knob_id = ImHashStr('knob'),
    -- Hover Card IDs
    card_id = ImHashStr('card_demo'),
    elevation_id = ImHashStr('elevation'),
    lift_id = ImHashStr('lift'),
}

local function ShowWidgetsDemo()
    local state = widgets_demo_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        'Combining tweens with ImGui widgets creates polished UI interactions.')

    imgui.Spacing()
    imgui.Separator()

    -- Animated buttons - using fixed layout to prevent movement
    ApplyOpenAll()
    if imgui.TreeNodeEx('Animated Buttons') then
        imgui.TextDisabled('Hover over buttons to see animation effects')
        imgui.Spacing()

        -- Use a child window with fixed size to prevent layout shifts
        local buttons_area = ImVec2(400, 60)
        imgui.BeginChild('##buttons_area', buttons_area, ImGuiChildFlags.None, ImGuiWindowFlags.NoScrollbar)

        for i = 1, 3 do
            local label = string.format('Button %d', i)

            local id = imgui.GetID(label)
            local size = ImVec2(110, 35)

            -- Fixed position for each button
            local btn_x = (i - 1) * 125.0
            imgui.SetCursorPos(ImVec2(btn_x, 10))

            -- Invisible button for interaction at fixed position
            local clicked = imgui.InvisibleButton(label, size)
            local hovered = imgui.IsItemHovered()
            local active = imgui.IsItemActive()

            -- Animate properties
            local ez = iam.EasePreset(IamEaseType.OutCubic)
            local alpha = iam.TweenFloat(id, state.alpha_id, hovered and 1.0 or 0.6, 0.4, ez, IamPolicy.Crossfade, dt)
            local scale = iam.TweenFloat(id, state.scale_id, hovered and 1.08 or 1.0, 0.3,
                iam.EaseSpringDesc(1.0, 200.0, 15.0, 0.0), IamPolicy.Crossfade, dt)
            local offset = iam.TweenVec2(id, state.offset_id, active and ImVec2(0, 2) or ImVec2(0, 0), 0.15, ez, IamPolicy.Crossfade, dt)
            local color = iam.TweenColor(id, state.color_id,
                hovered and ImVec4(0.3, 0.6, 1.0, 1.0) or ImVec4(0.2, 0.2, 0.25, 1.0),
                0.4, iam.EasePreset(IamEaseType.OutQuad), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)

            -- Calculate scaled button size (scale from center)
            local scaled_size = ImVec2(size.x * scale, size.y * scale)
            local size_diff = ImVec2((size.x - scaled_size.x) * 0.5, (size.y - scaled_size.y) * 0.5)

            -- Draw at fixed position with offset
            imgui.SetCursorPos(ImVec2(btn_x + offset.x + size_diff.x, 10 + offset.y + size_diff.y))
            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushStyleColor(ImGuiCol.Button, color)
            imgui.PushStyleColor(ImGuiCol.ButtonHovered, color)
            imgui.PushStyleColor(ImGuiCol.ButtonActive, color)
            imgui.PushID(i + 1000)
            imgui.Button(label, scaled_size)
            imgui.PopID()
            imgui.PopStyleColor(3)
            imgui.PopStyleVar()
        end

        imgui.EndChild()
        imgui.TreePop()
    end

    -- Animated toggle
    ApplyOpenAll()
    if imgui.TreeNode('Animated Toggle') then
        local id = state.toggle_id
        local toggle_size = ImVec2(60, 30)

        -- Draw toggle background
        local pos = imgui.GetCursorScreenPosVec()
        local draw_list = imgui.GetWindowDrawList()

        -- Animate background color
        local bg_color = iam.TweenColor(id, state.bg_id,
            state.toggle and ImVec4(0.2, 0.7, 0.3, 1.0) or ImVec4(0.3, 0.3, 0.35, 1.0),
            0.4, iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)

        -- Animate knob position
        local knob_x = iam.TweenFloat(id, state.knob_id,
            state.toggle and (toggle_size.x - 15.0 - 4.0) or 4.0,
            0.5, iam.EaseSpringDesc(1.0, 180.0, 18.0, 0.0), IamPolicy.Crossfade, dt)

        draw_list:AddRectFilled(pos, ImVec2(pos.x + toggle_size.x, pos.y + toggle_size.y),
            imgui.ColorConvertFloat4ToU32(bg_color), toggle_size.y * 0.5)
        draw_list:AddCircleFilled(ImVec2(pos.x + knob_x + 11, pos.y + toggle_size.y * 0.5), 11.0,
            IM_COL32(255, 255, 255, 255))

        -- Invisible button for interaction
        if imgui.InvisibleButton('##toggle', toggle_size) then
            state.toggle = not state.toggle
        end

        imgui.SameLine()
        imgui.Text(state.toggle and 'ON' or 'OFF')
        imgui.TreePop()
    end

    -- Hover card - larger
    ApplyOpenAll()
    if imgui.TreeNode('Hover Card') then
        local id = state.card_id

        local card_size = ImVec2(480, 140)
        local pos = imgui.GetCursorScreenPosVec()

        imgui.InvisibleButton('##card', card_size)
        local hovered = imgui.IsItemHovered()

        -- Animate elevation/shadow
        local elevation = iam.TweenFloat(id, state.elevation_id, hovered and 16.0 or 4.0, 0.4,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)
        local y_offset = iam.TweenFloat(id, state.lift_id, hovered and -6.0 or 0.0, 0.4,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        local draw_list = imgui.GetWindowDrawList()

        -- Shadow
        local shadow_pos = ImVec2(pos.x + elevation, pos.y + y_offset + elevation)
        draw_list:AddRectFilled(shadow_pos, ImVec2(shadow_pos.x + card_size.x, shadow_pos.y + card_size.y),
            IM_COL32(255, 255, 255, math.floor(40 + elevation * 3)), 12.0)

        -- Card
        local card_pos = ImVec2(pos.x, pos.y + y_offset)
        draw_list:AddRectFilled(card_pos, ImVec2(card_pos.x + card_size.x, card_pos.y + card_size.y),
            IM_COL32(60, 60, 70, 255), 12.0)
        draw_list:AddRect(card_pos, ImVec2(card_pos.x + card_size.x, card_pos.y + card_size.y),
            IM_COL32(80, 80, 90, 255), 12.0)

        -- Text
        draw_list:AddText(ImVec2(card_pos.x + 20, card_pos.y + 20), IM_COL32(255, 255, 255, 255), 'Hover Card')
        draw_list:AddText(ImVec2(card_pos.x + 20, card_pos.y + 50), IM_COL32(180, 180, 180, 255), 'Hover to see lift effect')
        draw_list:AddText(ImVec2(card_pos.x + 20, card_pos.y + 80), IM_COL32(140, 140, 140, 255), 'Shadow grows on hover')

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

    -- Clip 5: Animation with delay
    IamClip.Begin(CLIP_DELAYED)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_ALPHA, 0.5, 1.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.5, IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_SCALE, 0.5, 1.0, IamEaseType.OutBack)
        :SetDelay(1.0)
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

    -- Clip 7: Integer keyframes (counter animation)
    IamClip.Begin(CLIP_INT_ANIM)
        :KeyInt(CLIP_CH_COUNTER, 0.0, 0, IamEaseType.Linear)
        :KeyInt(CLIP_CH_COUNTER, 2.0, 100, IamEaseType.OutCubic)
        :End()

    -- Clip 8: Sequential timeline (animations play one after another)
    -- Total duration: 0.5 + 0.5 + 0.5 = 1.5s
    IamClip.Begin(CLIP_SEQUENTIAL)
        :SeqBegin()
            -- First: move right
            :KeyFloat(CLIP_CH_POS_X, 0.0, 0.0, IamEaseType.OutCubic)
            :KeyFloat(CLIP_CH_POS_X, 0.5, 100.0, IamEaseType.OutCubic)
        :SeqEnd()
        :SeqBegin()
            -- Then: move down
            :KeyFloat(CLIP_CH_POS_Y, 0.0, 0.0, IamEaseType.OutCubic)
            :KeyFloat(CLIP_CH_POS_Y, 0.5, 50.0, IamEaseType.OutCubic)
        :SeqEnd()
        :SeqBegin()
            -- Finally: scale up
            :KeyFloat(CLIP_CH_SCALE, 0.0, 1.0, IamEaseType.OutBack)
            :KeyFloat(CLIP_CH_SCALE, 0.5, 1.5, IamEaseType.OutBack)
        :SeqEnd()
        :End()

    -- Clip 9: Parallel timeline (all animations start at the same time)
    -- Total duration: max(0.6, 0.6, 0.6, 0.6) = 0.6s
    IamClip.Begin(CLIP_PARALLEL)
        :ParBegin()
            -- All at once: move, scale, and fade
            :KeyFloat(CLIP_CH_POS_X, 0.0, 0.0, IamEaseType.OutCubic)
            :KeyFloat(CLIP_CH_POS_X, 0.6, 100.0, IamEaseType.OutCubic)
            :KeyFloat(CLIP_CH_POS_Y, 0.0, 0.0, IamEaseType.OutCubic)
            :KeyFloat(CLIP_CH_POS_Y, 0.6, 50.0, IamEaseType.OutCubic)
            :KeyFloat(CLIP_CH_SCALE, 0.0, 0.5, IamEaseType.OutElastic)
            :KeyFloat(CLIP_CH_SCALE, 0.6, 1.2, IamEaseType.OutElastic)
            :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutQuad)
            :KeyFloat(CLIP_CH_ALPHA, 0.6, 1.0, IamEaseType.OutQuad)
        :ParEnd()
        :End()

    -- Clip 10: Stagger animation - cascading wave effect
    IamClip.Begin(CLIP_STAGGER)
        -- Pop in from below with scale
        :KeyFloat(CLIP_CH_POS_Y, 0.0, 40.0, IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_POS_Y, 0.5, 0.0, IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.0, IamEaseType.OutElastic)
        :KeyFloat(CLIP_CH_SCALE, 0.6, 1.0, IamEaseType.OutElastic)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_ALPHA, 0.3, 1.0, IamEaseType.OutQuad)
        :SetStagger(12, 0.06, 0.0) -- 12 items, 60ms delay for smooth wave
        :End()

    -- Clip 11: Stagger list items - slide in from left
    IamClip.Begin(CLIP_STAGGER_LIST)
        :KeyFloat(CLIP_CH_POS_X, 0.0, -50.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_POS_X, 0.4, 0.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_ALPHA, 0.3, 1.0, IamEaseType.OutQuad)
        :SetStagger(6, 0.08, 0.0)
        :End()

    -- Clip 12: Stagger grid - scale in with rotation feel
    IamClip.Begin(CLIP_STAGGER_GRID)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.0, IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_SCALE, 0.5, 1.0, IamEaseType.OutBack)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_ALPHA, 0.25, 1.0, IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_ROTATION, 0.0, -15.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_ROTATION, 0.5, 0.0, IamEaseType.OutCubic)
        :SetStagger(16, 0.04, 0.0)
        :End()

    -- Clip 13: Stagger cards - drop from top with bounce
    IamClip.Begin(CLIP_STAGGER_CARDS)
        :KeyFloat(CLIP_CH_POS_Y, 0.0, -80.0, IamEaseType.OutBounce)
        :KeyFloat(CLIP_CH_POS_Y, 0.6, 0.0, IamEaseType.OutBounce)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 0.0, IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_ALPHA, 0.2, 1.0, IamEaseType.OutQuad)
        :KeyFloat(CLIP_CH_SCALE, 0.0, 0.8, IamEaseType.OutCubic)
        :KeyFloat(CLIP_CH_SCALE, 0.4, 1.0, IamEaseType.OutCubic)
        :SetStagger(5, 0.12, 0.0)
        :End()

    -- Color keyframe clips - demonstrating different color spaces
    -- 5-color cycle in OKLCH (perceptually uniform with smooth hue transitions)
    IamClip.Begin(CLIP_COLOR_OKLCH)
        :KeyColor(CLIP_CH_COLOR, 0.0, ImVec4(1.0, 0.2, 0.2, 1.0), IamColorSpace.OKLCH, IamEaseType.InOutCubic)   -- Red
        :KeyColor(CLIP_CH_COLOR, 1.0, ImVec4(1.0, 0.7, 0.1, 1.0), IamColorSpace.OKLCH, IamEaseType.InOutCubic)   -- Orange
        :KeyColor(CLIP_CH_COLOR, 2.0, ImVec4(0.2, 0.9, 0.3, 1.0), IamColorSpace.OKLCH, IamEaseType.InOutCubic)   -- Green
        :KeyColor(CLIP_CH_COLOR, 3.0, ImVec4(0.2, 0.5, 1.0, 1.0), IamColorSpace.OKLCH, IamEaseType.InOutCubic)   -- Blue
        :KeyColor(CLIP_CH_COLOR, 4.0, ImVec4(0.8, 0.2, 0.9, 1.0), IamColorSpace.OKLCH, IamEaseType.InOutCubic)   -- Purple
        :KeyColor(CLIP_CH_COLOR, 5.0, ImVec4(1.0, 0.2, 0.2, 1.0), IamColorSpace.OKLCH, IamEaseType.InOutCubic)   -- Back to Red
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    -- Variation clips - demonstrating per-loop parameter variations
    -- Bouncing ball with decaying height
    IamClip.Begin(CLIP_VAR_BOUNCE)
        :KeyFloatVar(CLIP_CH_POS_Y, 0.0, 0.0, iam.VarfNone(), IamEaseType.OutQuad)
        :KeyFloatVar(CLIP_CH_POS_Y, 0.25, -100.0, iam.VarfMul(0.7), IamEaseType.OutQuad)  -- Height decays 70% each loop
        :KeyFloatVar(CLIP_CH_POS_Y, 0.5, 0.0, iam.VarfNone(), IamEaseType.InQuad)
        :SetDurationVar(iam.VarfMul(0.85))  -- Duration also shortens
        :SetLoop(true, IamDirection.Normal, 8)
        :End()

    -- Scale decay animation - gets smaller each loop
    IamClip.Begin(CLIP_VAR_DECAY)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 1.0, IamEaseType.Linear)
        :KeyFloatVar(CLIP_CH_SCALE, 0.0, 1.0, iam.VarfMul(0.8), IamEaseType.OutCubic)
        :KeyFloatVar(CLIP_CH_SCALE, 0.5, 1.2, iam.VarfMul(0.8), IamEaseType.InOutCubic)
        :KeyFloatVar(CLIP_CH_SCALE, 1.0, 1.0, iam.VarfMul(0.8), IamEaseType.InCubic)
        :SetLoop(true, IamDirection.Normal, 6)
        :End()

    -- Random position variation - jitter effect
    IamClip.Begin(CLIP_VAR_RANDOM)
        :KeyVec2Var(CLIP_CH_OFFSET, 0.0, ImVec2(0, 0),
            iam.Varv2Axis(iam.VarfRand(20.0), iam.VarfRand(20.0)), IamEaseType.OutElastic)
        :KeyVec2Var(CLIP_CH_OFFSET, 0.3, ImVec2(0, 0),
            iam.Varv2Axis(iam.VarfRand(20.0), iam.VarfRand(20.0)), IamEaseType.OutCubic)
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    -- Color hue shift variation - cycles through colors
    IamClip.Begin(CLIP_VAR_COLOR)
        :KeyColorVar(CLIP_CH_COLOR, 0.0, ImVec4(1.0, 0.3, 0.3, 1.0),
            iam.VarcChannel(iam.VarfNone(), iam.VarfInc(0.15), iam.VarfNone(), iam.VarfNone()), IamColorSpace.OKLCH, IamEaseType.InOutCubic)
        :KeyColorVar(CLIP_CH_COLOR, 0.5, ImVec4(1.0, 0.5, 0.5, 1.0),
            iam.VarcChannel(iam.VarfNone(), iam.VarfInc(0.15), iam.VarfNone(), iam.VarfNone()), IamColorSpace.OKLCH, IamEaseType.InOutCubic)
        :KeyColorVar(CLIP_CH_COLOR, 1.0, ImVec4(1.0, 0.3, 0.3, 1.0),
            iam.VarcChannel(iam.VarfNone(), iam.VarfInc(0.15), iam.VarfNone(), iam.VarfNone()), IamColorSpace.OKLCH, IamEaseType.InOutCubic)
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    -- Timing variation - accelerating animation
    IamClip.Begin(CLIP_VAR_TIMING)
        :KeyFloat(CLIP_CH_ROTATION, 0.0, 0.0, IamEaseType.InOutCubic)
        :KeyFloat(CLIP_CH_ROTATION, 1.0, 360.0, IamEaseType.InOutCubic)
        :SetTimescaleVar(iam.VarfMul(1.2))  -- Gets 20% faster each loop
        :SetLoop(true, IamDirection.Normal, 10)
        :End()

    -- Grid of elements - staggered start, scale and speed pingpong up/down
    IamClip.Begin(CLIP_VAR_PARTICLES)
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 1.0, IamEaseType.Linear)
        :KeyFloatVar(CLIP_CH_SCALE, 0.0, 0.5, iam.VarfPingpong(0.08), IamEaseType.OutBack)
        :KeyFloatVar(CLIP_CH_SCALE, 0.5, 1.0, iam.VarfPingpong(0.08), IamEaseType.InOutCubic)
        :KeyFloatVar(CLIP_CH_SCALE, 1.0, 0.5, iam.VarfPingpong(0.08), IamEaseType.InCubic)
        :KeyFloatVar(CLIP_CH_ROTATION, 0.0, 0.0, iam.VarfInc(15.0), IamEaseType.InOutCubic)
        :KeyFloatVar(CLIP_CH_ROTATION, 1.0, 30.0, iam.VarfInc(15.0), IamEaseType.InOutCubic)
        :SetTimescaleVar(iam.VarfPingpong(0.15))  -- Speed oscillates: faster then slower
        :SetStagger(15, 0.08, 0.0)
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    -- Race: 5 squares with stagger delay, timescale set per-instance to sync arrival
    -- Single clip with 3s duration, stagger adds 0.5s delay per index
    -- After play, we set timescale per instance: speed = T / (T - delay)
    -- Using key_float_rel so position is automatically relative to window content width
    IamClip.Begin(CLIP_VAR_RACE)
        :KeyFloatRel(CLIP_CH_POS_X, 0.0, 0.0, 35.0, IamAnchorSpace.WindowContent, 0, IamEaseType.Linear)   -- Start at margin (35px)
        :KeyFloatRel(CLIP_CH_POS_X, 3.0, 1.0, -35.0, IamAnchorSpace.WindowContent, 0, IamEaseType.Linear)  -- End at 100% - margin
        :KeyFloat(CLIP_CH_ALPHA, 0.0, 1.0, IamEaseType.Linear)
        :SetStagger(5, 0.5, 0.0)  -- 5 items, 0.5s delay between each
        :End()
end

local clip_state = {
    basic_fade_inst_id = ImHashStr('fade_inst'),
    basic_bounce_inst_id = ImHashStr('bounce_inst'),
    basic_complex_inst_id = ImHashStr('complex_inst'),

    looping_inst_id = ImHashStr('loop_inst'),
    looping_playing = false,

    calbacks_inst_id = ImHashStr('callback_inst'),

    control_inst_id = ImHashStr('control_inst'),
    control_time_scale = 1.0,

    delayed_inst_id = ImHashStr('delayed_inst'),
    delayed_elapsed = 0.0,
    delayed_was_playing = false,

    int_inst_id = ImHashStr('int_inst'),
    seq_inst_id = ImHashStr('seq_inst'),
    par_inst_id = ImHashStr('par_inst'),

    stagger_inst_ids = (function()
        local t = {}
        for i = 1, 12 do t[i] = ImHashStr('stagger_dot_' .. i) end
        return t
    end)(),

    stagger_list_inst_ids = (function()
        local t = {}
        for i = 1, 6 do t[i] = ImHashStr('stagger_list_' .. i) end
        return t
    end)(),

    stagger_grid_inst_ids = (function()
        local t = {}
        for i = 1, 16 do t[i] = ImHashStr('stagger_grid_' .. i) end
        return t
    end)(),

    stagger_cards_inst_ids = (function()
        local t = {}
        for i = 1, 5 do t[i] = ImHashStr('stagger_card_' .. i) end
        return t
    end)(),

    var_bounce_inst = ImHashStr('var_bounce_inst'),
    var_decay_inst = ImHashStr('var_decay_inst'),

    var_random_inst = ImHashStr('var_random_inst'),
    var_random_started = false,

    var_color_inst = ImHashStr('var_color_inst'),
    var_color_started = false,

    var_timing_inst = ImHashStr('var_timing_inst'),

    var_particles_inst_ids = (function()
        local t = {}
        for i = 0, 15 do t[i] = ImHashStr('var_grid_' .. i) end
        return t
    end)(),

    var_race_inst_ids = (function()
        local t = {}
        for i = 1, 5 do t[i] = ImHashStr('var_racer_' .. i) end
        return t
    end)(),

    color_oklch_inst = ImHashStr('color_oklch_inst'),
    color_oklch_started = false,
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
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
                scale = inst:GetFloat(CLIP_CH_SCALE)
            end
            -- Clamp scale to valid range for SetWindowFontScale
            if scale < 0.1 then scale = 0.1 end
            if scale > 10.0 then scale = 10.0 end

            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * scale)
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
                offset = inst:GetVec2(CLIP_CH_OFFSET)
                scale = inst:GetFloat(CLIP_CH_SCALE)
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
            end
            -- Clamp scale to valid range for SetWindowFontScale
            if scale < 0.1 then scale = 0.1 end
            if scale > 10.0 then scale = 10.0 end

            local cur = imgui.GetCursorPosVec()
            imgui.SetCursorPos(cur + offset)
            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * scale)
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
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
                scale = inst:GetFloat(CLIP_CH_SCALE)
                offset = inst:GetVec2(CLIP_CH_OFFSET)
                color = inst:GetVec4(CLIP_CH_COLOR)
            end
            -- Clamp scale to valid range for SetWindowFontScale
            if scale < 0.1 then scale = 0.1 end
            if scale > 10.0 then scale = 10.0 end

            local cur = imgui.GetCursorPosVec()
            imgui.SetCursorPos(cur + offset)
            imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
            imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * scale)
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
            color = inst:GetVec4(CLIP_CH_COLOR)
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
    ApplyOpenAll()
    if imgui.TreeNode('Playback Control') then
        local inst_id = clip_state.control_inst_id

        imgui.Text('Controls:')
        if imgui.Button('Play##ClipPlayback') then iam.Play(CLIP_COMPLEX, inst_id) end
        imgui.SameLine()

        local inst = iam.GetInstance(inst_id)

        if imgui.Button('Pause') then if inst:Valid() then inst:Pause() end end
        imgui.SameLine()
        if imgui.Button('Resume') then if inst:Valid() then inst:Resume() end end
        imgui.SameLine()
        if imgui.Button('Stop##playback') then if inst:Valid() then inst:Stop() end end

        -- Seek slider
        local time = inst:Valid() and inst:Time() or 0.0
        local duration = inst:Valid() and inst:Duration() or 1.5
        local new_time, seek_changed = imgui.SliderFloat('Seek', time, 0.0, duration, '%.2f s')
        if seek_changed and inst:Valid() then inst:Seek(new_time) end

        -- Time scale (applied continuously so it works for new plays and during playback)
        clip_state.control_time_scale = imgui.SliderFloat('Time Scale', clip_state.control_time_scale, 0.1, 3.0)
        if inst:Valid() then inst:SetTimeScale(clip_state.control_time_scale) end

        -- Status
        local status
        if not inst:Valid() then
            status = 'Not started'
        elseif inst:IsPlaying() then
            status = inst:IsPaused() and 'Paused' or 'Playing'
        else
            status = 'Stopped'
        end
        imgui.Text('Status: %s  Duration: %.2fs', status, duration)

        -- Show current values
        if inst:Valid() then
            local alpha = inst:GetFloat(CLIP_CH_ALPHA)
            local scale = inst:GetFloat(CLIP_CH_SCALE)
            local offset = inst:GetVec2(CLIP_CH_OFFSET)
            imgui.Text('Values: alpha=%.2f scale=%.2f offset=(%.1f,%.1f)', alpha, scale, offset.x, offset.y)
        end

        imgui.TreePop()
    end

    -- Delayed Playback
    ApplyOpenAll()
    if imgui.TreeNode('Delayed Playback') then
        imgui.TextWrapped('set_delay() adds a delay before the animation starts playing.')

        local inst_id = clip_state.delayed_inst_id

        if imgui.Button('Play (1s Delay)') then
            iam.Play(CLIP_DELAYED, inst_id)
            clip_state.delayed_elapsed = 0.0
            clip_state.delayed_was_playing = true
        end

        local inst = iam.GetInstance(inst_id)
        if clip_state.delayed_was_playing and inst:Valid() then
            clip_state.delayed_elapsed = clip_state.delayed_elapsed + dt
        end
        if inst:Valid() and not inst:IsPlaying() then
            clip_state.delayed_was_playing = false
        end

        imgui.SameLine()
        local alpha = 1.0
        local scale = 1.0
        if inst:Valid() then
            alpha = inst:GetFloat(CLIP_CH_ALPHA)
            scale = inst:GetFloat(CLIP_CH_SCALE)
        end
        if scale < 0.1 then scale = 0.1 end
        if scale > 10.0 then scale = 10.0 end

        imgui.PushStyleVar(ImGuiStyleVar.Alpha, alpha)
        imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * scale)
        imgui.Text('Delayed Text')
        imgui.PopFont()
        imgui.PopStyleVar()

        if clip_state.delayed_was_playing then
            imgui.Text('Elapsed: %.2fs (delay: 1.0s, anim starts after delay)', clip_state.delayed_elapsed)
        end

        imgui.TreePop()
    end

    -- Callbacks demo
    ApplyOpenAll()
    if imgui.TreeNode('Callbacks') then
        imgui.TextWrapped(
            "OnBegin(), OnUpdate(), and OnComplete() let you hook into animation lifecycle events.")

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
            scale = inst:GetFloat(CLIP_CH_SCALE)
        end
        if scale < 0.1 then scale = 0.1 end
        if scale > 10.0 then scale = 10.0 end

        imgui.SameLine()
        imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * scale)
        imgui.Text('Scaling')
        imgui.PopFont()

        imgui.Text('OnBegin called:    %d times', s_callback_begin_count)
        imgui.Text('OnUpdate called:   %d times', s_callback_update_count)
        imgui.Text('OnComplete called: %d times', s_callback_complete_count)

        imgui.TreePop()
    end

    -- Integer Keyframes demo
    ApplyOpenAll()
    if imgui.TreeNode('Integer Keyframes') then
        imgui.TextWrapped(
            'KeyInt() animates integer values (useful for counters, frame indices, etc.).')

        local inst_id = clip_state.int_inst_id

        if imgui.Button('Count to 100') then
            iam.Play(CLIP_INT_ANIM, inst_id)
        end

        local inst = iam.GetInstance(inst_id)
        local counter = 0
        if inst:Valid() then
            counter = inst:GetInt(CLIP_CH_COUNTER)
        end

        imgui.SameLine()
        imgui.Text('Counter: %d', counter)

        -- Progress bar
        imgui.ProgressBar(counter / 100.0, ImVec2(-1, 0), '')

        imgui.TreePop()
    end

    -- Sequential Timeline demo
    ApplyOpenAll()
    if imgui.TreeNode('Sequential Timeline (SeqBegin/End)') then
        imgui.TextWrapped(
            'SeqBegin()/SeqEnd() groups keyframes that play in sequence. ' ..
            'Each group starts after the previous one completes.')

        local inst_id = clip_state.seq_inst_id
        if imgui.Button('Play Sequential') then
            iam.Play(CLIP_SEQUENTIAL, inst_id)
        end

        local inst = iam.GetInstance(inst_id)
        local pos_x = 0.0
        local pos_y = 0.0
        local scale = 1.0
        if inst:Valid() then
            pos_x = inst:GetFloat(CLIP_CH_POS_X)
            pos_y = inst:GetFloat(CLIP_CH_POS_Y)
            scale = inst:GetFloat(CLIP_CH_SCALE)
        end
        if scale < 0.1 then scale = 0.1 end
        if scale > 10.0 then scale = 10.0 end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(200, 100)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(40, 40, 45, 255))

        -- Draw animated square
        local sq_size = 20.0 * scale
        local sq_pos = ImVec2(canvas_pos.x + 20 + pos_x, canvas_pos.y + 20 + pos_y)
        draw_list:AddRectFilled(sq_pos, ImVec2(sq_pos.x + sq_size, sq_pos.y + sq_size),
            IM_COL32(100, 200, 255, 255), 4.0)

        imgui.Dummy(canvas_size)
        imgui.Text('Step 1: Move right | Step 2: Move down | Step 3: Scale up')
        imgui.Text('X: %.1f  Y: %.1f  Scale: %.2f', pos_x, pos_y, scale)

        imgui.TreePop()
    end

    -- Parallel Timeline demo
    ApplyOpenAll()
    if imgui.TreeNode('Parallel Timeline (ParBegin/End)') then
        imgui.TextWrapped(
            'ParBegin()/ParEnd() groups keyframes that play simultaneously. ' ..
            'All animations in the group start at the same time.')

        local inst_id = clip_state.par_inst_id
        if imgui.Button('Play Parallel') then
            iam.Play(CLIP_PARALLEL, inst_id)
        end

        local inst = iam.GetInstance(inst_id)
        local pos_x = 0.0
        local pos_y = 0.0
        local scale = 1.0
        local alpha = 1.0
        if inst:Valid() then
            pos_x = inst:GetFloat(CLIP_CH_POS_X)
            pos_y = inst:GetFloat(CLIP_CH_POS_Y)
            scale = inst:GetFloat(CLIP_CH_SCALE)
            alpha = inst:GetFloat(CLIP_CH_ALPHA)
        end
        if scale < 0.1 then scale = 0.1 end
        if scale > 10.0 then scale = 10.0 end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(200, 100)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(40, 40, 45, 255))

        -- Draw animated circle
        local radius = 15.0 * scale
        local circ_pos = ImVec2(canvas_pos.x + 30 + pos_x, canvas_pos.y + 30 + pos_y)
        local a = math.floor(alpha * 255)
        draw_list:AddCircleFilled(circ_pos, radius, IM_COL32(255, 150, 100, a))

        imgui.Dummy(canvas_size)
        imgui.Text('All at once: Move + Scale + Fade')
        imgui.Text('X: %.1f  Y: %.1f  Scale: %.2f  Alpha: %.2f', pos_x, pos_y, scale, alpha)

        imgui.TreePop()
    end

    -- Stagger demo
    ApplyOpenAll()
    if imgui.TreeNode('Stagger Animation') then
        imgui.TextWrapped(
            'SetStagger() applies progressive delays for animating multiple items. ' ..
            'Each element pops in with a cascading wave effect.')

        local NUM_ITEMS = 12
        local inst_ids = clip_state.stagger_inst_ids

        if imgui.Button('Play Wave') then
            for i = 1, NUM_ITEMS do
                iam.PlayStagger(CLIP_STAGGER, inst_ids[i], i - 1)
            end
        end
        imgui.SameLine()
        if imgui.Button('Reset##stagger') then
            for i = 1, NUM_ITEMS do
                local inst = iam.GetInstance(inst_ids[i])
                if inst:Valid() then inst:Destroy() end
            end
        end

        imgui.Spacing()

        -- Draw cascading circles with rainbow colors
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_w = 400.0
        local canvas_h = 80.0
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_w, canvas_pos.y + canvas_h),
            IM_COL32(25, 25, 30, 255), 8.0)

        local spacing = canvas_w / (NUM_ITEMS + 1)
        local base_y = canvas_pos.y + canvas_h * 0.5

        for i = 1, NUM_ITEMS do
            local inst = iam.GetInstance(inst_ids[i])
            local alpha = 0.0
            local pos_y = 40.0
            local scale = 0.0
            if inst:Valid() then
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
                pos_y = inst:GetFloat(CLIP_CH_POS_Y)
                scale = inst:GetFloat(CLIP_CH_SCALE)
            end

            local x = canvas_pos.x + spacing * i
            local y = base_y + pos_y
            local radius = 12.0 * scale

            -- Rainbow hue based on index
            local hue = (i - 1) / NUM_ITEMS
            local r, g, b = imgui.ColorConvertHSVtoRGB(hue, 0.8, 0.9)
            local ai = math.floor(alpha * 255)

            if radius > 0.5 then
                -- Glow effect
                draw_list:AddCircleFilled(ImVec2(x, y), radius * 1.5,
                    IM_COL32(math.floor(r * 255), math.floor(g * 255), math.floor(b * 255), math.floor(alpha * 40)))
                -- Main circle
                draw_list:AddCircleFilled(ImVec2(x, y), radius,
                    IM_COL32(math.floor(r * 255), math.floor(g * 255), math.floor(b * 255), ai))
                -- Highlight
                draw_list:AddCircleFilled(ImVec2(x - radius * 0.3, y - radius * 0.3), radius * 0.25,
                    IM_COL32(255, 255, 255, math.floor(alpha * 150)))
            end
        end

        imgui.Dummy(ImVec2(canvas_w, canvas_h))

        imgui.TreePop()
    end

    -- Stagger List demo
    ApplyOpenAll()
    if imgui.TreeNode('Stagger: List Slide-In') then
        imgui.TextWrapped(
            'Classic list animation with items sliding in from the left.')

        local NUM_LIST_ITEMS = 6
        local list_inst_ids = clip_state.stagger_list_inst_ids

        if imgui.Button('Play List') then
            for i = 1, NUM_LIST_ITEMS do
                iam.PlayStagger(CLIP_STAGGER_LIST, list_inst_ids[i], i - 1)
            end
        end
        imgui.SameLine()
        if imgui.Button('Reset##list') then
            for i = 1, NUM_LIST_ITEMS do
                local inst = iam.GetInstance(list_inst_ids[i])
                if inst:Valid() then inst:Destroy() end
            end
        end

        imgui.Spacing()

        local frame_h = imgui.GetFrameHeight()
        local item_spacing = 4.0
        local padding = 8.0
        local list_canvas_w = 250.0
        local list_canvas_h = padding * 2 + NUM_LIST_ITEMS * frame_h + (NUM_LIST_ITEMS - 1) * item_spacing

        local list_canvas_pos = imgui.GetCursorScreenPosVec()
        local list_draw_list = imgui.GetWindowDrawList()

        list_draw_list:AddRectFilled(list_canvas_pos,
            ImVec2(list_canvas_pos.x + list_canvas_w, list_canvas_pos.y + list_canvas_h),
            IM_COL32(30, 32, 38, 255), 6.0)

        local list_labels = { 'Dashboard', 'Projects', 'Tasks', 'Calendar', 'Settings', 'Help' }
        for i = 1, NUM_LIST_ITEMS do
            local inst = iam.GetInstance(list_inst_ids[i])
            local alpha = 0.0
            local pos_x = -50.0
            if inst:Valid() then
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
                pos_x = inst:GetFloat(CLIP_CH_POS_X)
            end

            local y = list_canvas_pos.y + padding + (i - 1) * (frame_h + item_spacing)
            local a = math.floor(alpha * 255)

            -- Draw list item background
            list_draw_list:AddRectFilled(
                ImVec2(list_canvas_pos.x + padding + pos_x, y),
                ImVec2(list_canvas_pos.x + list_canvas_w - padding + pos_x, y + frame_h),
                IM_COL32(50, 55, 65, a), 4.0)

            -- Draw icon placeholder
            list_draw_list:AddCircleFilled(
                ImVec2(list_canvas_pos.x + padding + 14 + pos_x, y + frame_h * 0.5),
                6.0, IM_COL32(100, 140, 200, a))

            -- Draw label
            local text_y = y + (frame_h - imgui.GetFontSize()) * 0.5
            list_draw_list:AddText(
                ImVec2(list_canvas_pos.x + padding + 28 + pos_x, text_y),
                IM_COL32(220, 220, 230, a), list_labels[i])
        end

        imgui.Dummy(ImVec2(list_canvas_w, list_canvas_h))
        imgui.TreePop()
    end

    -- Stagger Grid demo
    ApplyOpenAll()
    if imgui.TreeNode('Stagger: Grid Reveal') then
        imgui.TextWrapped(
            'Grid items appearing with scale and subtle rotation.')

        local GRID_COLS = 4
        local GRID_ROWS = 4
        local NUM_GRID_ITEMS = GRID_COLS * GRID_ROWS
        local grid_inst_ids = clip_state.stagger_grid_inst_ids

        if imgui.Button('Play Grid') then
            for i = 1, NUM_GRID_ITEMS do
                iam.PlayStagger(CLIP_STAGGER_GRID, grid_inst_ids[i], i - 1)
            end
        end
        imgui.SameLine()
        if imgui.Button('Reset##sgrid') then
            for i = 1, NUM_GRID_ITEMS do
                local inst = iam.GetInstance(grid_inst_ids[i])
                if inst:Valid() then inst:Destroy() end
            end
        end

        imgui.Spacing()

        local grid_canvas_pos = imgui.GetCursorScreenPosVec()
        local cell_size = 45.0
        local grid_spacing = 8.0
        local grid_canvas_w = GRID_COLS * (cell_size + grid_spacing) + grid_spacing
        local grid_canvas_h = GRID_ROWS * (cell_size + grid_spacing) + grid_spacing
        local grid_draw_list = imgui.GetWindowDrawList()

        grid_draw_list:AddRectFilled(grid_canvas_pos,
            ImVec2(grid_canvas_pos.x + grid_canvas_w, grid_canvas_pos.y + grid_canvas_h),
            IM_COL32(25, 28, 35, 255), 8.0)

        for row = 0, GRID_ROWS - 1 do
            for col = 0, GRID_COLS - 1 do
                local idx = row * GRID_COLS + col + 1
                local inst = iam.GetInstance(grid_inst_ids[idx])
                local alpha = 0.0
                local scale = 0.0
                local rotation = 0.0
                if inst:Valid() then
                    alpha = inst:GetFloat(CLIP_CH_ALPHA)
                    scale = inst:GetFloat(CLIP_CH_SCALE)
                    rotation = inst:GetFloat(CLIP_CH_ROTATION)
                end

                local cx = grid_canvas_pos.x + grid_spacing + col * (cell_size + grid_spacing) + cell_size * 0.5
                local cy = grid_canvas_pos.y + grid_spacing + row * (cell_size + grid_spacing) + cell_size * 0.5

                local a = math.floor(alpha * 255)
                local half = cell_size * 0.5 * scale

                -- Pastel colors based on position
                local hue = (row * GRID_COLS + col) / NUM_GRID_ITEMS
                local r, g, b = imgui.ColorConvertHSVtoRGB(hue, 0.5, 0.85)

                if scale > 0.01 then
                    -- Draw rotated rounded rect
                    local rad = rotation * math.pi / 180.0
                    local corner_angles = { -0.785, 0.785, 2.356, 3.927 } -- 45, 135, 225, 315 degrees
                    local dist = half * 1.414
                    local corners = {}
                    for ci = 1, 4 do
                        local ca = corner_angles[ci] + rad
                        corners[ci] = ImVec2(cx + math.cos(ca) * dist, cy + math.sin(ca) * dist)
                    end
                    grid_draw_list:AddQuadFilled(corners[1], corners[2], corners[3], corners[4],
                        IM_COL32(math.floor(r * 255), math.floor(g * 255), math.floor(b * 255), a))
                end
            end
        end

        imgui.Dummy(ImVec2(grid_canvas_w, grid_canvas_h))
        imgui.TreePop()
    end

    -- Stagger Cards demo
    ApplyOpenAll()
    if imgui.TreeNode('Stagger: Dropping Cards') then
        imgui.TextWrapped(
            'Cards dropping in from above with a bounce effect.')

        local NUM_CARDS = 5
        local card_inst_ids = clip_state.stagger_cards_inst_ids

        if imgui.Button('Drop Cards') then
            for i = 1, NUM_CARDS do
                iam.PlayStagger(CLIP_STAGGER_CARDS, card_inst_ids[i], i - 1)
            end
        end
        imgui.SameLine()
        if imgui.Button('Reset##cards') then
            for i = 1, NUM_CARDS do
                local inst = iam.GetInstance(card_inst_ids[i])
                if inst:Valid() then inst:Destroy() end
            end
        end

        imgui.Spacing()

        local cards_canvas_pos = imgui.GetCursorScreenPosVec()
        local card_w = 70.0
        local card_h = 90.0
        local card_spacing = 12.0
        local cards_canvas_w = NUM_CARDS * (card_w + card_spacing) + card_spacing
        local cards_canvas_h = card_h + 100.0 -- Extra space for drop animation
        local cards_draw_list = imgui.GetWindowDrawList()

        cards_draw_list:AddRectFilled(cards_canvas_pos,
            ImVec2(cards_canvas_pos.x + cards_canvas_w, cards_canvas_pos.y + cards_canvas_h),
            IM_COL32(20, 25, 35, 255), 8.0)

        -- Card suits for visual interest
        local suits = { 'A', 'K', 'Q', 'J', '10' }
        local card_colors = {
            IM_COL32(220, 60, 60, 255),   -- Red
            IM_COL32(40, 40, 50, 255),    -- Black
            IM_COL32(220, 60, 60, 255),   -- Red
            IM_COL32(40, 40, 50, 255),    -- Black
            IM_COL32(220, 60, 60, 255),   -- Red
        }

        for i = 1, NUM_CARDS do
            local inst = iam.GetInstance(card_inst_ids[i])
            local alpha = 0.0
            local pos_y = -80.0
            local scale = 0.8
            if inst:Valid() then
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
                pos_y = inst:GetFloat(CLIP_CH_POS_Y)
                scale = inst:GetFloat(CLIP_CH_SCALE)
            end

            local x = cards_canvas_pos.x + card_spacing + (i - 1) * (card_w + card_spacing)
            local y = cards_canvas_pos.y + 80.0 + pos_y

            local scaled_w = card_w * scale
            local scaled_h = card_h * scale
            local offset_x = (card_w - scaled_w) * 0.5
            local offset_y = (card_h - scaled_h) * 0.5
            local a = math.floor(alpha * 255)

            if alpha > 0.01 then
                -- Card shadow
                cards_draw_list:AddRectFilled(
                    ImVec2(x + offset_x + 3, y + offset_y + 3),
                    ImVec2(x + offset_x + scaled_w + 3, y + offset_y + scaled_h + 3),
                    IM_COL32(0, 0, 0, math.floor(a / 3)), 6.0)

                -- Card background
                cards_draw_list:AddRectFilled(
                    ImVec2(x + offset_x, y + offset_y),
                    ImVec2(x + offset_x + scaled_w, y + offset_y + scaled_h),
                    IM_COL32(250, 250, 245, a), 6.0)

                -- Card border
                cards_draw_list:AddRect(
                    ImVec2(x + offset_x, y + offset_y),
                    ImVec2(x + offset_x + scaled_w, y + offset_y + scaled_h),
                    IM_COL32(180, 180, 175, a), 6.0, 0, 1.5)

                -- Suit text
                local text_col = ColorAlpha(card_colors[i], a)
                cards_draw_list:AddText(
                    ImVec2(x + offset_x + 8, y + offset_y + 6),
                    text_col, suits[i])
            end
        end

        imgui.Dummy(ImVec2(cards_canvas_w, cards_canvas_h))
        imgui.TreePop()
    end

    -- ============================================================
    -- Variation Demos
    -- ============================================================
    ApplyOpenAll()
    if imgui.TreeNode('Variation: Bouncing Ball Decay') then
        imgui.TextWrapped(
            'A bouncing ball where each bounce gets lower (70%% of previous height) ' ..
            'and faster (85%% of previous duration). Uses VarfMul() for multiplicative decay.')

        local inst_bounce = clip_state.var_bounce_inst

        if imgui.Button('Start Bounce') then
            iam.Play(CLIP_VAR_BOUNCE, inst_bounce)
        end
        imgui.SameLine()
        if imgui.Button('Reset##bounce') then
            local inst = iam.GetInstance(inst_bounce)
            if inst:Valid() then inst:Destroy() end
        end

        imgui.Spacing()

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_w = 300.0
        local canvas_h = 150.0
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_w, canvas_pos.y + canvas_h),
            IM_COL32(20, 25, 35, 255), 8.0)

        -- Ground line
        draw_list:AddLine(
            ImVec2(canvas_pos.x + 10, canvas_pos.y + canvas_h - 20),
            ImVec2(canvas_pos.x + canvas_w - 10, canvas_pos.y + canvas_h - 20),
            IM_COL32(100, 100, 100, 255), 2.0)

        local pos_y = 0.0
        local inst = iam.GetInstance(inst_bounce)
        if inst:Valid() then
            pos_y = inst:GetFloat(CLIP_CH_POS_Y)
        end

        local ball_x = canvas_pos.x + canvas_w * 0.5
        local ball_y = canvas_pos.y + canvas_h - 35 + pos_y
        local ball_radius = 15.0

        draw_list:AddCircleFilled(ImVec2(ball_x, ball_y), ball_radius, IM_COL32(255, 120, 50, 255))
        draw_list:AddCircle(ImVec2(ball_x, ball_y), ball_radius, IM_COL32(255, 180, 100, 255), 0, 2.0)

        imgui.Dummy(ImVec2(canvas_w, canvas_h))
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Variation: Scale Decay') then
        imgui.TextWrapped(
            'A pulsing element that gets smaller with each loop. Scale decreases by ' ..
            '20%% each iteration using VarfMul(0.8).')

        local inst_decay = clip_state.var_decay_inst

        if imgui.Button('Start Decay') then
            iam.Play(CLIP_VAR_DECAY, inst_decay)
        end
        imgui.SameLine()
        if imgui.Button('Reset##decay') then
            local inst = iam.GetInstance(inst_decay)
            if inst:Valid() then inst:Destroy() end
        end

        imgui.Spacing()

        local alpha = 1.0
        local scale = 1.0
        local inst = iam.GetInstance(inst_decay)
        if inst:Valid() then
            alpha = inst:GetFloat(CLIP_CH_ALPHA)
            scale = inst:GetFloat(CLIP_CH_SCALE)
        end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = 150.0
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_size, canvas_pos.y + canvas_size),
            IM_COL32(20, 25, 35, 255), 8.0)

        local center_x = canvas_pos.x + canvas_size * 0.5
        local center_y = canvas_pos.y + canvas_size * 0.5
        local rect_size = 50.0 * scale
        local a = math.floor(alpha * 255)

        draw_list:AddRectFilled(
            ImVec2(center_x - rect_size, center_y - rect_size),
            ImVec2(center_x + rect_size, center_y + rect_size),
            IM_COL32(100, 200, 255, a), 8.0)

        imgui.Dummy(ImVec2(canvas_size, canvas_size))
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Variation: Random Jitter') then
        imgui.TextWrapped(
            'Each loop iteration applies a random offset to the position using ' ..
            'VarfRand(). The offset varies between -20 and +20 pixels per axis.')

        if not clip_state.var_random_started then
            iam.Play(CLIP_VAR_RANDOM, clip_state.var_random_inst)
            clip_state.var_random_started = true
        end

        if imgui.Button('Restart##random') then
            iam.Play(CLIP_VAR_RANDOM, clip_state.var_random_inst)
        end
        imgui.SameLine()
        if imgui.Button('Stop##random') then
            local inst = iam.GetInstance(clip_state.var_random_inst)
            if inst:Valid() then inst:Destroy() end
        end

        imgui.Spacing()

        local offset = ImVec2(0, 0)
        local inst = iam.GetInstance(clip_state.var_random_inst)
        if inst:Valid() then
            offset = inst:GetVec2(CLIP_CH_OFFSET)
        end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = 150.0
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_size, canvas_pos.y + canvas_size),
            IM_COL32(20, 25, 35, 255), 8.0)

        local cx = canvas_pos.x + canvas_size * 0.5 + offset.x
        local cy = canvas_pos.y + canvas_size * 0.5 + offset.y
        draw_list:AddCircleFilled(ImVec2(cx, cy), 20.0, IM_COL32(255, 200, 100, 255))

        imgui.Dummy(ImVec2(canvas_size, canvas_size))
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Variation: Color Shift') then
        imgui.TextWrapped(
            'Each loop increments the hue in OKLCH color space using VarfInc(). ' ..
            'The color smoothly cycles through the spectrum.')

        if not clip_state.var_color_started then
            iam.Play(CLIP_VAR_COLOR, clip_state.var_color_inst)
            clip_state.var_color_started = true
        end

        if imgui.Button('Restart##color') then
            iam.Play(CLIP_VAR_COLOR, clip_state.var_color_inst)
        end
        imgui.SameLine()
        if imgui.Button('Stop##color') then
            local inst = iam.GetInstance(clip_state.var_color_inst)
            if inst:Valid() then inst:Destroy() end
        end

        imgui.Spacing()

        local color = ImVec4(1.0, 0.3, 0.3, 1.0)
        local inst = iam.GetInstance(clip_state.var_color_inst)
        if inst:Valid() then
            color = inst:GetColor(CLIP_CH_COLOR)
        end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_w = 200.0
        local canvas_h = 80.0
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_w, canvas_pos.y + canvas_h),
            IM_COL32(20, 25, 35, 255), 8.0)

        local col = IM_COL32(
            math.floor(color.x * 255),
            math.floor(color.y * 255),
            math.floor(color.z * 255),
            math.floor(color.w * 255))

        draw_list:AddRectFilled(
            ImVec2(canvas_pos.x + 20, canvas_pos.y + 15),
            ImVec2(canvas_pos.x + canvas_w - 20, canvas_pos.y + canvas_h - 15),
            col, 12.0)

        imgui.Dummy(ImVec2(canvas_w, canvas_h))
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Variation: Accelerating Spin') then
        imgui.TextWrapped(
            'A spinning element that gets 20%% faster each loop using SetTimescaleVar(). ' ..
            'Demonstrates timing variation.')

        local inst_timing = clip_state.var_timing_inst

        if imgui.Button('Start Spin') then
            iam.Play(CLIP_VAR_TIMING, inst_timing)
        end
        imgui.SameLine()
        if imgui.Button('Reset##timing') then
            local inst = iam.GetInstance(inst_timing)
            if inst:Valid() then inst:Destroy() end
        end

        imgui.Spacing()

        local rotation = 0.0
        local inst = iam.GetInstance(inst_timing)
        if inst:Valid() then
            rotation = inst:GetFloat(CLIP_CH_ROTATION)
        end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = 150.0
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_size, canvas_pos.y + canvas_size),
            IM_COL32(20, 25, 35, 255), 8.0)

        local center_x = canvas_pos.x + canvas_size * 0.5
        local center_y = canvas_pos.y + canvas_size * 0.5
        local arm_length = 40.0

        -- Convert degrees to radians
        local rad = rotation * math.pi / 180.0

        -- Draw a spinning line/arm
        local end_pos = ImVec2(
            center_x + math.cos(rad) * arm_length,
            center_y + math.sin(rad) * arm_length)

        draw_list:AddLine(ImVec2(center_x, center_y), end_pos, IM_COL32(100, 255, 150, 255), 4.0)
        draw_list:AddCircleFilled(end_pos, 8.0, IM_COL32(100, 255, 150, 255))
        draw_list:AddCircleFilled(ImVec2(center_x, center_y), 6.0, IM_COL32(200, 200, 200, 255))

        imgui.Dummy(ImVec2(canvas_size, canvas_size))
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Variation: Staggered Grid (N Instances)') then
        imgui.TextWrapped(
            'A grid with staggered timing (top-left to bottom-right). Scale and speed use ' ..
            'pingpong variation (grow then shrink), rotation increments continuously.')

        local GRID_COLS = 5
        local GRID_ROWS = 3
        local NUM_ITEMS = GRID_COLS * GRID_ROWS
        local vgrid_ids = clip_state.var_particles_inst_ids

        if imgui.Button('Start') then
            for i = 1, NUM_ITEMS do
                iam.PlayStagger(CLIP_VAR_PARTICLES, vgrid_ids[i], i - 1)
            end
        end
        imgui.SameLine()
        if imgui.Button('Reset##grid') then
            for i = 1, NUM_ITEMS do
                local inst = iam.GetInstance(vgrid_ids[i])
                if inst:Valid() then inst:Destroy() end
            end
        end

        imgui.Spacing()
        imgui.TextDisabled('Pingpong: scale/speed increase then decrease, loops forever')
        imgui.Spacing()

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local cell_size = 50.0
        local spacing = 10.0
        local canvas_w = GRID_COLS * (cell_size + spacing) + spacing
        local canvas_h = GRID_ROWS * (cell_size + spacing) + spacing
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_w, canvas_pos.y + canvas_h),
            IM_COL32(20, 25, 35, 255), 8.0)

        for row = 0, GRID_ROWS - 1 do
            for col = 0, GRID_COLS - 1 do
                local idx = row * GRID_COLS + col + 1

                local cx = canvas_pos.x + spacing + col * (cell_size + spacing) + cell_size * 0.5
                local cy = canvas_pos.y + spacing + row * (cell_size + spacing) + cell_size * 0.5

                local alpha = 0.3
                local scale = 0.6
                local rotation = 0.0
                local inst = iam.GetInstance(vgrid_ids[idx])
                if inst:Valid() then
                    alpha = inst:GetFloat(CLIP_CH_ALPHA)
                    scale = inst:GetFloat(CLIP_CH_SCALE)
                    rotation = inst:GetFloat(CLIP_CH_ROTATION)
                end

                local rad = rotation * math.pi / 180.0
                local cos_r = math.cos(rad)
                local sin_r = math.sin(rad)
                local half = (cell_size * 0.35) * scale

                -- Rotated square corners
                local corners = {
                    ImVec2(cx + (-half * cos_r - -half * sin_r), cy + (-half * sin_r + -half * cos_r)),
                    ImVec2(cx + ( half * cos_r - -half * sin_r), cy + ( half * sin_r + -half * cos_r)),
                    ImVec2(cx + ( half * cos_r -  half * sin_r), cy + ( half * sin_r +  half * cos_r)),
                    ImVec2(cx + (-half * cos_r -  half * sin_r), cy + (-half * sin_r +  half * cos_r)),
                }

                local a = alpha * 255
                -- Gradient based on grid position
                local t = (idx - 1) / (NUM_ITEMS - 1)
                local r = 100 + 155 * t
                local g = 180 - 80 * t
                local b = 220 - 120 * t

                draw_list:AddQuadFilled(corners[1], corners[2], corners[3], corners[4],
                    IM_COL32(math.floor(r), math.floor(g), math.floor(b), math.floor(a)))
                draw_list:AddQuad(corners[1], corners[2], corners[3], corners[4],
                    IM_COL32(255, 255, 255, a * 2 / 3), 2.0)
            end
        end

        imgui.Dummy(ImVec2(canvas_w, canvas_h))
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Variation: Synchronized Race') then
        imgui.TextWrapped(
            '5 squares start at different times with different speeds, but all arrive ' ..
            'at the right edge simultaneously. Uses stagger + per-instance SetTimeScale().')

        local NUM_RACERS = 5
        local TOTAL_TIME = 3.0
        local DELAY_STEP = 0.5
        local racer_ids = clip_state.var_race_inst_ids

        if imgui.Button('Start Race') then
            for i = 1, NUM_RACERS do
                local inst = iam.PlayStagger(CLIP_VAR_RACE, racer_ids[i], i - 1)
                -- Set timescale so all arrive at the same time
                -- Row i has delay = i * DELAY_STEP, so travel time = TOTAL_TIME - delay
                -- Speed = TOTAL_TIME / travel_time
                local delay = (i - 1) * DELAY_STEP
                local travel_time = TOTAL_TIME - delay
                local speed = TOTAL_TIME / travel_time
                inst:SetTimeScale(speed)
            end
        end
        imgui.SameLine()
        if imgui.Button('Reset##race') then
            for i = 1, NUM_RACERS do
                local inst = iam.GetInstance(racer_ids[i])
                if inst:Valid() then inst:Destroy() end
            end
        end

        imgui.Spacing()
        imgui.TextDisabled('Top=slow start, Bottom=fast start. All finish together!')
        imgui.TextDisabled('Using KeyFloatRel() - position auto-scales with window width')
        imgui.Spacing()

        -- Canvas sizing - width comes from content region
        local content_size = iam.AnchorSize(IamAnchorSpace.WindowContent)
        local canvas_w = content_size.x
        local row_h = 35.0
        local canvas_h = NUM_RACERS * row_h + 10.0
        local square_size = 25.0
        local margin = 35.0  -- Matches the px_bias in clip definition

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + canvas_w, canvas_pos.y + canvas_h),
            IM_COL32(20, 25, 35, 255), 8.0)

        -- Finish line
        draw_list:AddLine(
            ImVec2(canvas_pos.x + canvas_w - margin, canvas_pos.y + 5),
            ImVec2(canvas_pos.x + canvas_w - margin, canvas_pos.y + canvas_h - 5),
            IM_COL32(255, 100, 100, 150), 2.0)

        -- Start line
        draw_list:AddLine(
            ImVec2(canvas_pos.x + margin, canvas_pos.y + 5),
            ImVec2(canvas_pos.x + margin, canvas_pos.y + canvas_h - 5),
            IM_COL32(100, 255, 100, 150), 2.0)

        for i = 1, NUM_RACERS do
            local pos_x = margin  -- Default to start position
            local alpha = 0.5
            local inst = iam.GetInstance(racer_ids[i])
            if inst:Valid() then
                -- GetFloat returns actual pixel position thanks to KeyFloatRel!
                pos_x = inst:GetFloat(CLIP_CH_POS_X)
                alpha = inst:GetFloat(CLIP_CH_ALPHA)
            end

            -- pos_x is now the actual X position relative to content area
            local x = canvas_pos.x + pos_x
            local y = canvas_pos.y + 5 + (i - 1) * row_h + row_h * 0.5

            local a = math.floor(alpha * 255)
            -- Color gradient: green (fast) to red (slow)
            local t = (i - 1) / (NUM_RACERS - 1)
            local ri = math.floor(100 + 155 * (1.0 - t))
            local gi = math.floor(100 + 155 * t)
            local bi = 100

            local half = square_size * 0.5
            draw_list:AddRectFilled(
                ImVec2(x - half, y - half),
                ImVec2(x + half, y + half),
                IM_COL32(ri, gi, bi, a), 4.0)
        end

        imgui.Dummy(ImVec2(canvas_w, canvas_h))
        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Color Keyframe Demo
-- ============================================================
local function ShowColorKeyframeDemo()
    local state = clip_state

    InitDemoClips()

    imgui.TextWrapped(
        'key_color() animates colors with 5 keyframes in OKLCH color space, ' ..
        'providing perceptually uniform transitions with smooth hue interpolation.')

    imgui.Spacing()
    imgui.Separator()
    imgui.Spacing()

    -- Start animation on first run
    local inst_oklch = state.color_oklch_inst
    if not state.color_oklch_started then
        iam.Play(CLIP_COLOR_OKLCH, inst_oklch)
        state.color_oklch_started = true
    end

    if imgui.Button('Restart') then
        iam.Play(CLIP_COLOR_OKLCH, inst_oklch)
    end

    imgui.Spacing()
    imgui.Text('5-color cycle: Red -> Orange -> Green -> Blue -> Purple')
    imgui.Spacing()

    -- Get current color from animation
    local color = ImVec4(1, 1, 1, 1)
    local inst = iam.GetInstance(inst_oklch)
    if inst:Valid() then
        color = inst:GetColor(CLIP_CH_COLOR)
    end

    -- Draw color bar
    local bar_width = imgui.GetContentRegionAvailVec().x
    local bar_height = 50.0
    local pos = imgui.GetCursorScreenPosVec()
    local dl = imgui.GetWindowDrawList()

    local col32 = IM_COL32(
        math.floor(color.x * 255),
        math.floor(color.y * 255),
        math.floor(color.z * 255),
        255)
    dl:AddRectFilled(pos, ImVec2(pos.x + bar_width, pos.y + bar_height), col32, 4.0)
    dl:AddRect(pos, ImVec2(pos.x + bar_width, pos.y + bar_height), IM_COL32(100, 100, 100, 255), 4.0)

    imgui.Dummy(ImVec2(bar_width, bar_height + 8.0))
end

-- ============================================================
-- SECTION: Resize-Aware Helpers
-- ============================================================
local resize_state = {
    percent = {0.5, 0.5},
    px_bias = {0.0, 0.0},
    resolver_angle = 0.0,
    rebase_target_x = 150.0,
    rebase_target_y = 75.0,
    dragging = false,
}

local function ShowResizeHelpersDemo()
    local state = resize_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        'When windows resize or dock, absolute positions become invalid. ' ..
        'The resize-aware helpers use relative coordinates that adapt to container size changes.')

    imgui.Spacing()

    ApplyOpenAll()
    if imgui.TreeNode('Relative Positioning') then
        imgui.TextWrapped('Position as percentage of container + pixel offset:')

        state.percent = imgui.SliderFloat2('Percent', state.percent, 0.0, 1.0)
        state.px_bias = imgui.SliderFloat2('Pixel Bias', state.px_bias, -50.0, 50.0)

        -- Draw indicator in a fixed-size canvas
        local origin = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 200)

        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(origin, ImVec2(origin.x + canvas_size.x, origin.y + canvas_size.y), IM_COL32(40, 40, 45, 255))
        draw_list:AddRect(origin, ImVec2(origin.x + canvas_size.x, origin.y + canvas_size.y), IM_COL32(80, 80, 85, 255))

        -- Calculate target position based on percentage of canvas
        local target_pos = ImVec2(canvas_size.x * state.percent[1] + state.px_bias[1],
            canvas_size.y * state.percent[2] + state.px_bias[2])

        local id = ImHashStr('rel_pos_demo')
        local pos = iam.TweenVec2(id, 0, target_pos, 0.5,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Clamp position to stay within canvas
        local radius = 12.0
        local draw_x = math.max(radius, math.min(pos.x, canvas_size.x - radius))
        local draw_y = math.max(radius, math.min(pos.y, canvas_size.y - radius))

        draw_list:AddCircleFilled(ImVec2(origin.x + draw_x, origin.y + draw_y), radius, IM_COL32(100, 200, 255, 255))

        imgui.Dummy(canvas_size)
        imgui.Text('Position: (%.1f, %.1f)', pos.x, pos.y)

        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Anchor Spaces Showcase') then
        imgui.TextWrapped('Each anchor space measures from a different reference:')

        imgui.Spacing()

        -- Window Content anchor
        do
            imgui.Text('window_content: GetContentRegionAvail()')
            local content_avail = imgui.GetContentRegionAvailVec()
            local content_size = ImVec2(content_avail.x, 60)
            local origin = imgui.GetCursorScreenPosVec()

            local draw_list = imgui.GetWindowDrawList()
            draw_list:AddRectFilled(origin, ImVec2(origin.x + content_size.x, origin.y + content_size.y), IM_COL32(40, 50, 40, 255))
            draw_list:AddRect(origin, ImVec2(origin.x + content_size.x, origin.y + content_size.y), IM_COL32(80, 120, 80, 255))

            local id = ImHashStr('anchor_content')
            local pos = iam.TweenVec2Rel(id, 0, ImVec2(0.5, 0.5), ImVec2(0, 0), 0.5,
                iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamAnchorSpace.WindowContent, dt)

            -- Draw dot clamped to this region
            local draw_x = math.max(10.0, math.min(pos.x, content_size.x - 10.0))
            local draw_y = math.max(10.0, math.min(pos.y, content_size.y - 10.0))
            draw_list:AddCircleFilled(ImVec2(origin.x + draw_x, origin.y + draw_y), 8.0, IM_COL32(100, 255, 100, 255))
            draw_list:AddText(ImVec2(origin.x + 5, origin.y + 5), IM_COL32(180, 255, 180, 255), 'Content Region')

            imgui.Dummy(content_size)
        end

        imgui.Spacing()

        -- Window anchor
        do
            imgui.Text('window: GetWindowSize()')
            local win_size = imgui.GetWindowSizeVec()
            local display_size = ImVec2(math.min(win_size.x - 20, 400.0), 60)
            local origin = imgui.GetCursorScreenPosVec()

            local draw_list = imgui.GetWindowDrawList()
            draw_list:AddRectFilled(origin, ImVec2(origin.x + display_size.x, origin.y + display_size.y), IM_COL32(40, 40, 50, 255))
            draw_list:AddRect(origin, ImVec2(origin.x + display_size.x, origin.y + display_size.y), IM_COL32(80, 80, 120, 255))

            local id = ImHashStr('anchor_window')
            local pos = iam.TweenVec2Rel(id, 0, ImVec2(0.5, 0.5), ImVec2(0, 0), 0.5,
                iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamAnchorSpace.Window, dt)

            -- Scale position to display size
            local scale_x = display_size.x / win_size.x
            local scale_y = display_size.y / win_size.y
            local draw_x = math.max(10.0, math.min(pos.x * scale_x, display_size.x - 10.0))
            local draw_y = math.max(10.0, math.min(pos.y * scale_y, display_size.y - 10.0))
            draw_list:AddCircleFilled(ImVec2(origin.x + draw_x, origin.y + draw_y), 8.0, IM_COL32(100, 100, 255, 255))
            draw_list:AddText(ImVec2(origin.x + 5, origin.y + 5), IM_COL32(180, 180, 255, 255), 'Window Size (scaled preview)')

            imgui.Dummy(display_size)
            imgui.Text('Actual window size: (%.0f, %.0f), Center pos: (%.1f, %.1f)', win_size.x, win_size.y, pos.x, pos.y)
        end

        imgui.Spacing()

        -- Viewport anchor
        do
            imgui.Text('viewport: GetWindowViewport()->Size')
            local vp_size = imgui.GetWindowViewport().Size
            local display_size = ImVec2(math.min(vp_size.x * 0.3, 400.0), 60)
            local origin = imgui.GetCursorScreenPosVec()

            local draw_list = imgui.GetWindowDrawList()
            draw_list:AddRectFilled(origin, ImVec2(origin.x + display_size.x, origin.y + display_size.y), IM_COL32(50, 40, 40, 255))
            draw_list:AddRect(origin, ImVec2(origin.x + display_size.x, origin.y + display_size.y), IM_COL32(120, 80, 80, 255))

            local id = ImHashStr('anchor_viewport')
            local pos = iam.TweenVec2Rel(id, 0, ImVec2(0.5, 0.5), ImVec2(0, 0), 0.5,
                iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamAnchorSpace.Viewport, dt)

            -- Scale position to display size
            local scale_x = display_size.x / vp_size.x
            local scale_y = display_size.y / vp_size.y
            local draw_x = math.max(10.0, math.min(pos.x * scale_x, display_size.x - 10.0))
            local draw_y = math.max(10.0, math.min(pos.y * scale_y, display_size.y - 10.0))
            draw_list:AddCircleFilled(ImVec2(origin.x + draw_x, origin.y + draw_y), 8.0, IM_COL32(255, 100, 100, 255))
            draw_list:AddText(ImVec2(origin.x + 5, origin.y + 5), IM_COL32(255, 180, 180, 255), 'Viewport Size (scaled preview)')

            imgui.Dummy(display_size)
            imgui.Text('Actual viewport size: (%.0f, %.0f), Center pos: (%.1f, %.1f)', vp_size.x, vp_size.y, pos.x, pos.y)
        end

        imgui.Spacing()

        -- Last item anchor
        do
            imgui.Text('last_item: GetItemRectSize()')
            imgui.Button('Reference Button', ImVec2(200, 40))
            local item_size = imgui.GetItemRectSizeVec()

            local origin = imgui.GetCursorScreenPosVec()
            local display_size = ImVec2(200, 40)

            local draw_list = imgui.GetWindowDrawList()
            draw_list:AddRectFilled(origin, ImVec2(origin.x + display_size.x, origin.y + display_size.y), IM_COL32(50, 50, 40, 255))
            draw_list:AddRect(origin, ImVec2(origin.x + display_size.x, origin.y + display_size.y), IM_COL32(120, 120, 80, 255))

            local id = ImHashStr('anchor_item')
            local pos = iam.TweenVec2Rel(id, 0, ImVec2(0.5, 0.5), ImVec2(0, 0), 0.5,
                iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, IamAnchorSpace.LastItem, dt)

            -- Scale position to display size
            local scale_x = display_size.x / item_size.x
            local scale_y = display_size.y / item_size.y
            local draw_x = math.max(10.0, math.min(pos.x * scale_x, display_size.x - 10.0))
            local draw_y = math.max(10.0, math.min(pos.y * scale_y, display_size.y - 10.0))
            draw_list:AddCircleFilled(ImVec2(origin.x + draw_x, origin.y + draw_y), 8.0, IM_COL32(255, 255, 100, 255))
            draw_list:AddText(ImVec2(origin.x + 5, origin.y + 5), IM_COL32(255, 255, 180, 255), 'Last Item Size')

            imgui.Dummy(display_size)
            imgui.Text('Button size: (%.0f, %.0f), Center pos: (%.1f, %.1f)', item_size.x, item_size.y, pos.x, pos.y)
        end

        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Resolver Callback') then
        imgui.TextWrapped(
            'iam.TweenVec2Resolved() uses a callback to compute the target position dynamically. ' ..
            'Useful when the target depends on runtime state.')

        -- Resolver function that calculates position based on time
        state.resolver_angle = state.resolver_angle + dt * 1.5

        -- Store resolver data for the callback
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300, 150)
        local center = ImVec2(canvas_size.x * 0.5, canvas_size.y * 0.5)
        local radius = 50.0
        local angle = state.resolver_angle

        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(canvas_pos,
            canvas_pos + canvas_size,
            IM_COL32(40, 40, 45, 255))
        draw_list:AddRect(canvas_pos,
            canvas_pos + canvas_size,
            IM_COL32(80, 80, 85, 255))

        -- Draw orbit path
        draw_list:AddCircle(
            ImVec2(canvas_pos.x + center.x, canvas_pos.y + center.y),
            radius, IM_COL32(60, 60, 80, 255), 32, 1.0)

        -- Resolver callback
        local resolver = function()
            return ImVec2(
                center.x + math.cos(angle) * radius,
                center.y + math.sin(angle) * radius
            )
        end

        local id = ImHashStr('resolver_demo')
        local pos = iam.TweenVec2Resolved(id, 0, resolver, 0.3,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Draw the animated dot (smoothly following the orbit)
        draw_list:AddCircleFilled(
            ImVec2(canvas_pos.x + pos.x, canvas_pos.y + pos.y),
            10.0, IM_COL32(100, 200, 255, 255))

        -- Draw the instant target position (without smoothing)
        local instant = resolver()
        draw_list:AddCircle(
            ImVec2(canvas_pos.x + instant.x, canvas_pos.y + instant.y),
            12.0, IM_COL32(255, 100, 100, 150), 12, 2.0)

        imgui.Dummy(canvas_size)
        imgui.TextDisabled('Blue: smoothed position, Red circle: instant target')
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Rebase Animation') then
        imgui.TextWrapped(
            'iam.RebaseVec2() allows changing the target of an in-progress animation ' ..
            'without snapping or restarting. Useful for drag operations.')

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300, 150)

        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(canvas_pos,
            canvas_pos + canvas_size,
            IM_COL32(40, 45, 40, 255))
        draw_list:AddRect(canvas_pos,
            canvas_pos + canvas_size,
            IM_COL32(80, 100, 80, 255))

        imgui.InvisibleButton('rebase_canvas', canvas_size)
        local hovered = imgui.IsItemHovered()
        local clicked = imgui.IsItemClicked(0)

        if clicked then
            local mouse = imgui.GetMousePosVec()
            state.rebase_target_x = mouse.x - canvas_pos.x
            state.rebase_target_y = mouse.y - canvas_pos.y

            -- Rebase the animation to the new target
            local id = ImHashStr('rebase_demo')
            iam.RebaseVec2(id, 0, ImVec2(state.rebase_target_x, state.rebase_target_y), dt)
            state.dragging = true
        end
        if state.dragging and imgui.IsMouseDown(0) and hovered then
            local mouse = imgui.GetMousePosVec()
            state.rebase_target_x = mouse.x - canvas_pos.x
            state.rebase_target_y = mouse.y - canvas_pos.y
            local id = ImHashStr('rebase_demo')
            iam.RebaseVec2(id, 0, ImVec2(state.rebase_target_x, state.rebase_target_y), dt)
        end
        if imgui.IsMouseReleased(0) then
            state.dragging = false
        end

        local id = ImHashStr('rebase_demo')
        local target = ImVec2(state.rebase_target_x, state.rebase_target_y)
        local pos = iam.TweenVec2(id, 0, target, 0.4,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        -- Draw target crosshair
        draw_list:AddLine(
            ImVec2(canvas_pos.x + target.x - 10, canvas_pos.y + target.y),
            ImVec2(canvas_pos.x + target.x + 10, canvas_pos.y + target.y),
            IM_COL32(255, 100, 100, 200), 1.0)
        draw_list:AddLine(
            ImVec2(canvas_pos.x + target.x, canvas_pos.y + target.y - 10),
            ImVec2(canvas_pos.x + target.x, canvas_pos.y + target.y + 10),
            IM_COL32(255, 100, 100, 200), 1.0)

        -- Draw animated circle
        draw_list:AddCircleFilled(
            ImVec2(canvas_pos.x + pos.x, canvas_pos.y + pos.y),
            15.0, IM_COL32(100, 255, 150, 255))

        imgui.TextDisabled('Click anywhere to rebase the target')
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Anchor Size Query') then
        imgui.TextWrapped(
            'AnchorSize() returns the dimensions of each anchor space. ' ..
            'Useful for manual calculations.')

        local content = iam.AnchorSize(IamAnchorSpace.WindowContent)
        local window = iam.AnchorSize(IamAnchorSpace.Window)
        local viewport = iam.AnchorSize(IamAnchorSpace.Viewport)
        local last_item = iam.AnchorSize(IamAnchorSpace.LastItem)

        imgui.Text('Content Region: %.0f x %.0f', content.x, content.y)
        imgui.Text('Window Size:    %.0f x %.0f', window.x, window.y)
        imgui.Text('Viewport Size:  %.0f x %.0f', viewport.x, viewport.y)
        imgui.Text('Last Item Size: %.0f x %.0f', last_item.x, last_item.y)

        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Layering System
-- ============================================================

-- Layering clip IDs and channels
local LAYER_CLIP_A = 0x3001
local LAYER_CLIP_B = 0x3002
local LAYER_CLIP_C = 0x3003
local LAYER_CH_X = 0x3101

local s_layer_clips_initialized = false

local function InitLayerClips()
    if s_layer_clips_initialized then return end
    s_layer_clips_initialized = true

    -- Animation A: moves right slowly
    IamClip.Begin(LAYER_CLIP_A)
        :KeyFloat(LAYER_CH_X, 0.0, 0.0, IamEaseType.InOutSine)
        :KeyFloat(LAYER_CH_X, 2.0, 200.0, IamEaseType.InOutSine)
        :SetLoop(true, IamDirection.Alternate)
        :End()

    -- Animation B: moves left faster
    IamClip.Begin(LAYER_CLIP_B)
        :KeyFloat(LAYER_CH_X, 0.0, 200.0, IamEaseType.InOutCubic)
        :KeyFloat(LAYER_CH_X, 1.5, 0.0, IamEaseType.InOutCubic)
        :SetLoop(true, IamDirection.Alternate)
        :End()

    -- Animation C: bouncy center pulse
    IamClip.Begin(LAYER_CLIP_C)
        :KeyFloat(LAYER_CH_X, 0.0, 100.0, IamEaseType.OutElastic)
        :KeyFloat(LAYER_CH_X, 0.8, 50.0, IamEaseType.InOutQuad)
        :KeyFloat(LAYER_CH_X, 1.6, 150.0, IamEaseType.InOutQuad)
        :KeyFloat(LAYER_CH_X, 2.4, 100.0, IamEaseType.OutBounce)
        :SetLoop(true, IamDirection.Normal)
        :End()
end

local layer_state = {
    basic_inst_a = ImHashStr('layer_inst_a'),
    basic_inst_b = ImHashStr('layer_inst_b'),
    basic_inst_c = ImHashStr('layer_inst_c'),
    basic_weight_a = 0.33,
    basic_weight_b = 0.33,
    basic_weight_c = 0.34,
    basic_playing = false,
    basic_composite = ImHashStr('layer_composite'),
    weight_inst_id = ImHashStr('weight_inst'),
    weight_value = 1.0,
}

local function ShowLayeringDemo()
    local state = layer_state
    InitLayerClips()

    imgui.TextWrapped(
        'The layering system allows blending multiple animation instances together. ' ..
        'Use LayerBegin/LayerAdd/LayerEnd to combine animations with weights.')

    imgui.Spacing()

    ApplyOpenAll()
    if imgui.TreeNode('Basic Layer Blending (3 Layers)') then
        imgui.TextWrapped(
            'Three animations move dots with different patterns. ' ..
            'Adjust the weight sliders to blend between them.')

        local inst_a = state.basic_inst_a
        local inst_b = state.basic_inst_b
        local inst_c = state.basic_inst_c

        if not state.basic_playing then
            if imgui.Button('Start Animations') then
                iam.Play(LAYER_CLIP_A, inst_a)
                iam.Play(LAYER_CLIP_B, inst_b)
                iam.Play(LAYER_CLIP_C, inst_c)
                state.basic_playing = true
            end
        else
            if imgui.Button('Stop') then
                local a = iam.GetInstance(inst_a)
                local b = iam.GetInstance(inst_b)
                local c = iam.GetInstance(inst_c)
                if a:Valid() then a:Stop() end
                if b:Valid() then b:Stop() end
                if c:Valid() then c:Stop() end
                state.basic_playing = false
            end
        end

        state.basic_weight_a = imgui.SliderFloat('Weight A', state.basic_weight_a, 0.0, 1.0)
        state.basic_weight_b = imgui.SliderFloat('Weight B', state.basic_weight_b, 0.0, 1.0)
        state.basic_weight_c = imgui.SliderFloat('Weight C', state.basic_weight_c, 0.0, 1.0)

        local a = iam.GetInstance(inst_a)
        local b = iam.GetInstance(inst_b)
        local c = iam.GetInstance(inst_c)

        -- Get individual values for visualization
        local x_a = 100.0
        local x_b = 100.0
        local x_c = 100.0
        if a:Valid() then x_a = a:GetFloat(LAYER_CH_X) end
        if b:Valid() then x_b = b:GetFloat(LAYER_CH_X) end
        if c:Valid() then x_c = c:GetFloat(LAYER_CH_X) end

        -- Use the layering API to blend animations
        local composite_id = state.basic_composite
        iam.LayerBegin(composite_id)
        if a:Valid() then iam.LayerAdd(a, state.basic_weight_a) end
        if b:Valid() then iam.LayerAdd(b, state.basic_weight_b) end
        if c:Valid() then iam.LayerAdd(c, state.basic_weight_c) end
        iam.LayerEnd(composite_id)

        local blended_x = iam.GetBlendedFloat(composite_id, LAYER_CH_X)

        -- Draw visualization
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local vis_width = 250.0
        local text_width = 120.0
        local row_height = 35.0
        local canvas_size = ImVec2(vis_width, row_height * 4 + 20.0)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            ImVec2(canvas_pos.x + vis_width, canvas_pos.y + canvas_size.y),
            IM_COL32(40, 40, 45, 255))
        draw_list:AddRect(canvas_pos,
            ImVec2(canvas_pos.x + vis_width, canvas_pos.y + canvas_size.y),
            IM_COL32(80, 80, 85, 255))

        -- Draw individual positions (faded) with labels on right
        local y_row = canvas_pos.y + row_height * 0.5 + 10.0
        draw_list:AddCircleFilled(ImVec2(canvas_pos.x + 25 + x_a * 0.5, y_row), 8.0, IM_COL32(255, 100, 100, 100))
        draw_list:AddText(ImVec2(canvas_pos.x + vis_width + 10, y_row - 6), IM_COL32(255, 100, 100, 200), 'A (right)')

        y_row = canvas_pos.y + row_height * 1.5 + 10.0
        draw_list:AddCircleFilled(ImVec2(canvas_pos.x + 25 + x_b * 0.5, y_row), 8.0, IM_COL32(100, 100, 255, 100))
        draw_list:AddText(ImVec2(canvas_pos.x + vis_width + 10, y_row - 6), IM_COL32(100, 100, 255, 200), 'B (left)')

        y_row = canvas_pos.y + row_height * 2.5 + 10.0
        draw_list:AddCircleFilled(ImVec2(canvas_pos.x + 25 + x_c * 0.5, y_row), 8.0, IM_COL32(255, 200, 100, 100))
        draw_list:AddText(ImVec2(canvas_pos.x + vis_width + 10, y_row - 6), IM_COL32(255, 200, 100, 200), 'C (bouncy)')

        -- Draw blended position (solid)
        y_row = canvas_pos.y + row_height * 3.5 + 10.0
        draw_list:AddCircleFilled(ImVec2(canvas_pos.x + 25 + blended_x * 0.5, y_row), 10.0, IM_COL32(100, 255, 100, 255))
        draw_list:AddText(ImVec2(canvas_pos.x + vis_width + 10, y_row - 6), IM_COL32(100, 255, 100, 255), 'Blended')

        imgui.Dummy(ImVec2(vis_width + text_width, canvas_size.y))
        -- Calculate normalized weights for display
        local total = state.basic_weight_a + state.basic_weight_b + state.basic_weight_c
        if total < 0.001 then total = 1.0 end
        imgui.Text('Weights: A=%.0f%% B=%.0f%% C=%.0f%%',
            (state.basic_weight_a / total) * 100,
            (state.basic_weight_b / total) * 100,
            (state.basic_weight_c / total) * 100)

        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('Instance Weights') then
        imgui.TextWrapped(
            'SetWeight() on an instance controls its contribution when used with the layering API.')

        local inst_id = state.weight_inst_id

        if imgui.Button('Play##weight') then
            iam.Play(LAYER_CLIP_A, inst_id)
        end

        imgui.SameLine()
        imgui.SetNextItemWidth(150)
        state.weight_value = imgui.SliderFloat('Weight', state.weight_value, 0.0, 2.0)

        local inst = iam.GetInstance(inst_id)
        if inst:Valid() then
            inst:SetWeight(state.weight_value)
        end

        local x = 0.0
        if inst:Valid() then x = inst:GetFloat(LAYER_CH_X) end

        -- Apply weight to the position for visualization
        local weighted_x = x * state.weight_value

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300, 50)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos,
            canvas_pos + canvas_size,
            IM_COL32(40, 40, 45, 255))

        -- Original position
        draw_list:AddCircle(
            ImVec2(canvas_pos.x + 50 + x * 0.5, canvas_pos.y + 25),
            10.0, IM_COL32(255, 255, 255, 100), 12, 1.0)

        -- Weighted position
        draw_list:AddCircleFilled(
            ImVec2(canvas_pos.x + 50 + weighted_x * 0.5, canvas_pos.y + 25),
            8.0, IM_COL32(255, 200, 100, 255))

        imgui.Dummy(canvas_size)
        imgui.Text('Original: %.1f, Weighted (x%.1f): %.1f', x, state.weight_value, weighted_x)

        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: ImDrawList Animations with ImAnim
-- ============================================================

-- Clip IDs for DrawList demos
local CLIP_DL_CUBE_X = 0x3001
local CLIP_DL_CUBE_Y = 0x3002
local CLIP_DL_CUBE_Z = 0x3003
local CLIP_DL_RING = 0x3004

-- Channel IDs for DrawList demos
local CLIP_DL_CH_ANGLE = 0x3101
local CLIP_DL_CH_RADIUS = 0x3102
local CLIP_DL_CH_ALPHA = 0x3103

local s_drawlist_clips_initialized = false

local function InitDrawListClips()
    if s_drawlist_clips_initialized then return end
    s_drawlist_clips_initialized = true

    -- Cube rotation clips - continuous looping with "whoosh" easing
    -- Using in_out_cubic for smooth acceleration/deceleration per rotation
    IamClip.Begin(CLIP_DL_CUBE_X)
        :KeyFloat(CLIP_DL_CH_ANGLE, 0.0, 0.0, IamEaseType.InOutCubic)
        :KeyFloat(CLIP_DL_CH_ANGLE, 3.0, 6.28318, IamEaseType.InOutCubic)  -- Full rotation in 3s
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    IamClip.Begin(CLIP_DL_CUBE_Y)
        :KeyFloat(CLIP_DL_CH_ANGLE, 0.0, 0.0, IamEaseType.InOutCubic)
        :KeyFloat(CLIP_DL_CH_ANGLE, 1.9, 6.28318, IamEaseType.InOutCubic)  -- Full rotation in 1.9s
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    IamClip.Begin(CLIP_DL_CUBE_Z)
        :KeyFloat(CLIP_DL_CH_ANGLE, 0.0, 0.0, IamEaseType.InOutCubic)
        :KeyFloat(CLIP_DL_CH_ANGLE, 7.0, 6.28318, IamEaseType.InOutCubic)  -- Full rotation in 7s
        :SetLoop(true, IamDirection.Normal, -1)
        :End()

    -- Pulsing ring - expand and fade
    IamClip.Begin(CLIP_DL_RING)
        :KeyFloat(CLIP_DL_CH_RADIUS, 0.0, 10.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_DL_CH_RADIUS, 2.0, 70.0, IamEaseType.OutCubic)
        :KeyFloat(CLIP_DL_CH_ALPHA, 0.0, 1.0, IamEaseType.Linear)
        :KeyFloat(CLIP_DL_CH_ALPHA, 2.0, 0.0, IamEaseType.Linear)
        :SetStagger(4, 0.5, 0.0)  -- 4 rings, 0.5s apart
        :SetLoop(true, IamDirection.Normal, -1)
        :End()
end

local drawlist_state = {
    inst_x = ImHashStr('dl_cube_x'),
    inst_y = ImHashStr('dl_cube_y'),
    inst_z = ImHashStr('dl_cube_z'),
    cube_started = false,
    ring_inst_ids = {
        ImHashStr('dl_ring_0'),
        ImHashStr('dl_ring_1'),
        ImHashStr('dl_ring_2'),
        ImHashStr('dl_ring_3'),
    },
    rings_started = false,
}

local function ShowDrawListDemo()
    local dt = GetSafeDeltaTime()
    local state = drawlist_state
    InitDrawListClips()

    imgui.TextWrapped(
        'Custom ImDrawList rendering animated with ImAnim clips and tweens. ' ..
        'All animations use the clip system for clean, declarative control.')

    imgui.Spacing()
    imgui.Separator()

    -- Rotating 3D Cube using clips
    ApplyOpenAll()
    if imgui.TreeNodeEx('3D Rotating Cube') then
        imgui.TextDisabled('Wireframe cube animated with 3 looping rotation clips')

        if not state.cube_started then
            iam.Play(CLIP_DL_CUBE_X, state.inst_x)
            iam.Play(CLIP_DL_CUBE_Y, state.inst_y)
            iam.Play(CLIP_DL_CUBE_Z, state.inst_z)
            state.cube_started = true
        end

        if imgui.Button('Restart##cube') then
            iam.Play(CLIP_DL_CUBE_X, state.inst_x)
            iam.Play(CLIP_DL_CUBE_Y, state.inst_y)
            iam.Play(CLIP_DL_CUBE_Z, state.inst_z)
        end

        -- Get rotation angles from clips
        local angle_x, angle_y, angle_z = 0.0, 0.0, 0.0
        local ix = iam.GetInstance(state.inst_x)
        local iy = iam.GetInstance(state.inst_y)
        local iz = iam.GetInstance(state.inst_z)
        if ix:Valid() then angle_x = ix:GetFloat(CLIP_DL_CH_ANGLE) end
        if iy:Valid() then angle_y = iy:GetFloat(CLIP_DL_CH_ANGLE) end
        if iz:Valid() then angle_z = iz:GetFloat(CLIP_DL_CH_ANGLE) end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(250, 200)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(20, 20, 30, 255))

        local center = canvas_pos + canvas_size * 0.5
        local cube_size = 60.0

        local vertices = {
            {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
            {-1, -1,  1}, {1, -1,  1}, {1, 1,  1}, {-1, 1,  1}
        }

        local projected = {}
        local rotated_z = {}
        for i = 1, 8 do
            local x = vertices[i][1]
            local y = vertices[i][2]
            local z = vertices[i][3]

            local y1 = y * math.cos(angle_x) - z * math.sin(angle_x)
            local z1 = y * math.sin(angle_x) + z * math.cos(angle_x)
            y = y1; z = z1

            local x1 = x * math.cos(angle_y) + z * math.sin(angle_y)
            z1 = -x * math.sin(angle_y) + z * math.cos(angle_y)
            x = x1; z = z1

            x1 = x * math.cos(angle_z) - y * math.sin(angle_z)
            y1 = x * math.sin(angle_z) + y * math.cos(angle_z)
            x = x1; y = y1

            rotated_z[i] = z
            local perspective = 3.0 / (3.0 + z)
            projected[i] = center + ImVec2(x, y) * cube_size * perspective
        end

        local edges = {
            {1, 2}, {2, 3}, {3, 4}, {4, 1},
            {5, 6}, {6, 7}, {7, 8}, {8, 5},
            {1, 5}, {2, 6}, {3, 7}, {4, 8},
        }

        for i = 1, 12 do
            local v0 = edges[i][1]
            local v1 = edges[i][2]
            local avg_z = (rotated_z[v0] + rotated_z[v1]) * 0.5
            local brightness = math.max(80, math.min(255, 180 + avg_z * 50))
            draw_list:AddLine(projected[v0], projected[v1],
                IM_COL32(math.floor(brightness), math.floor(brightness / 2), math.floor(brightness), 255), 2.0)
        end

        for i = 1, 8 do
            local brightness = math.max(100, math.min(255, 200 + math.floor(rotated_z[i] * 40)))
            draw_list:AddCircleFilled(projected[i], 4.0, IM_COL32(100, brightness, 255, 255))
        end

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end

    imgui.Spacing()

    -- Pulsing Rings using staggered clips
    ApplyOpenAll()
    if imgui.TreeNode('Pulsing Rings') then
        imgui.TextDisabled('4 rings animated with staggered clip instances')

        local NUM_RINGS = 4

        if not state.rings_started then
            for i = 1, NUM_RINGS do
                iam.PlayStagger(CLIP_DL_RING, state.ring_inst_ids[i], i - 1)
            end
            state.rings_started = true
        end

        if imgui.Button('Restart##rings') then
            for i = 1, NUM_RINGS do
                iam.PlayStagger(CLIP_DL_RING, state.ring_inst_ids[i], i - 1)
            end
        end

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(250, 150)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(15, 15, 25, 255))

        local center = canvas_pos + canvas_size * 0.5

        for i = 1, NUM_RINGS do
            local radius, alpha = 10.0, 0.0
            local inst = iam.GetInstance(state.ring_inst_ids[i])
            if inst:Valid() then
                radius = inst:GetFloat(CLIP_DL_CH_RADIUS)
                alpha = inst:GetFloat(CLIP_DL_CH_ALPHA)
            end

            if alpha > 0.01 then
                local a = math.floor(alpha * 200)
                draw_list:AddCircle(center, radius, IM_COL32(100, 150, 255, a), 0, 2.0)
            end
        end

        draw_list:AddCircleFilled(center, 6.0, IM_COL32(100, 200, 255, 255))

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end

    imgui.Spacing()

    -- Pendulum Wave - mesmerizing physics visualization
    ApplyOpenAll()
    if imgui.TreeNode('Pendulum Wave') then
        imgui.TextDisabled('15 pendulums with slightly different frequencies using iam_oscillate')

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(320, 180)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(15, 15, 25, 255))

        -- Draw the top bar
        local bar_y = canvas_pos.y + 20.0
        draw_list:AddLine(ImVec2(canvas_pos.x + 20.0, bar_y), ImVec2(canvas_pos.x + canvas_size.x - 20.0, bar_y),
            IM_COL32(80, 80, 100, 255), 3.0)

        local NUM_PENDULUMS = 15
        local spacing = (canvas_size.x - 40.0) / (NUM_PENDULUMS - 1)
        local base_length = 120.0

        for i = 0, NUM_PENDULUMS - 1 do
            local pivot_x = canvas_pos.x + 20.0 + i * spacing
            local pivot_y = bar_y

            -- Each pendulum has slightly different frequency
            -- After 30 seconds, they realign (wave pattern)
            local freq_mult = 1.0 + i * 0.02  -- 1.0, 1.02, 1.04, ..., 1.28

            local pend_id = ImHashStr('pendulum') + i
            local angle = iam.Oscillate(pend_id, 0.4, 0.4 * freq_mult, IamWaveType.Sine, 0.0, dt)

            -- Pendulum length decreases slightly for visual appeal
            local length = base_length - i * 2.0
            local bob_x = pivot_x + math.sin(angle) * length
            local bob_y = pivot_y + math.cos(angle) * length

            -- Draw string
            draw_list:AddLine(ImVec2(pivot_x, pivot_y), ImVec2(bob_x, bob_y),
                IM_COL32(100, 100, 120, 200), 1.5)

            -- Draw bob with gradient color based on position
            local t = i / (NUM_PENDULUMS - 1)
            local r = 100 + math.floor(155 * t)
            local g = 200 - math.floor(100 * t)
            local b = 255 - math.floor(155 * t)
            draw_list:AddCircleFilled(ImVec2(bob_x, bob_y), 8.0, IM_COL32(r, g, b, 255))
            draw_list:AddCircle(ImVec2(bob_x, bob_y), 8.0, IM_COL32(255, 255, 255, 100), 0, 1.5)
        end

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end

    imgui.Spacing()

    -- Lissajous Curve - beautiful mathematical pattern from two oscillators
    ApplyOpenAll()
    if imgui.TreeNode('Lissajous Curve') then
        imgui.TextDisabled('Two oscillators at different frequencies create evolving patterns')

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(280, 180)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(10, 10, 20, 255))

        local center = canvas_pos + canvas_size * 0.5
        local radius_x = canvas_size.x * 0.4
        local radius_y = canvas_size.y * 0.4

        -- Two oscillators with frequency ratio that slowly changes
        -- This creates evolving Lissajous patterns
        local phase_id = ImHashStr('lissajous_phase')
        local phase_shift = iam.Oscillate(phase_id, math.pi, 0.02, IamWaveType.Sawtooth, 0.0, dt)

        -- Draw the curve trail (history of points)
        local TRAIL_POINTS = 200
        local trail = {}

        local freq_x = 3.0
        local freq_y = 2.0

        for i = 1, TRAIL_POINTS do
            local t = (i - 1) / TRAIL_POINTS * 2.0 * math.pi
            local x = math.sin(freq_x * t + phase_shift)
            local y = math.sin(freq_y * t)
            trail[i] = ImVec2(center.x + x * radius_x, center.y + y * radius_y)
        end

        -- Draw gradient trail
        for i = 2, TRAIL_POINTS do
            local t = i / TRAIL_POINTS
            local r = 100 + math.floor(155 * t)
            local g = 50 + math.floor(100 * (1.0 - t))
            local b = 200 + math.floor(55 * t)
            local a = 50 + math.floor(200 * t)
            draw_list:AddLine(trail[i-1], trail[i], IM_COL32(r, g, b, a), 2.0)
        end

        -- Draw moving dot at current position
        local dot_id = ImHashStr('lissajous_dot')
        local dot_t = iam.Oscillate(dot_id, math.pi, 0.3, IamWaveType.Sawtooth, 0.0, dt)
        dot_t = (dot_t + math.pi) / (2.0 * math.pi) * 2.0 * math.pi  -- Normalize to 0-2PI

        local dot_x = center.x + math.sin(freq_x * dot_t + phase_shift) * radius_x
        local dot_y = center.y + math.sin(freq_y * dot_t) * radius_y

        -- Glow
        draw_list:AddCircleFilled(ImVec2(dot_x, dot_y), 12.0, IM_COL32(150, 100, 255, 50))
        draw_list:AddCircleFilled(ImVec2(dot_x, dot_y), 8.0, IM_COL32(200, 150, 255, 100))
        draw_list:AddCircleFilled(ImVec2(dot_x, dot_y), 5.0, IM_COL32(255, 255, 255, 255))

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end

    imgui.Spacing()

    -- Breathing Heartbeat - pulsing heart with ECG line
    ApplyOpenAll()
    if imgui.TreeNode('Breathing Heartbeat') then
        imgui.TextDisabled('Heart pulse animation using iam_oscillate with custom timing')

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(320, 180)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y),
            IM_COL32(15, 10, 15, 255))

        -- Heart position (left side)
        local heart_center = ImVec2(canvas_pos.x + 80.0, canvas_pos.y + canvas_size.y * 0.45)

        -- Heartbeat oscillation - double bump pattern
        local heart_id = ImHashStr('heartbeat')
        local beat_phase = iam.Oscillate(heart_id, 1.0, 1.2, IamWaveType.Sawtooth, 0.0, dt)
        beat_phase = (beat_phase + 1.0) * 0.5  -- Normalize to 0-1

        -- Create double-bump heartbeat curve
        local pulse = 0.0
        if beat_phase < 0.1 then
            -- First bump (quick rise)
            pulse = beat_phase / 0.1
        elseif beat_phase < 0.2 then
            -- First bump (quick fall)
            pulse = 1.0 - (beat_phase - 0.1) / 0.1
        elseif beat_phase < 0.25 then
            -- Brief pause
            pulse = 0.0
        elseif beat_phase < 0.35 then
            -- Second bump (smaller, slower rise)
            pulse = 0.6 * (beat_phase - 0.25) / 0.1
        elseif beat_phase < 0.5 then
            -- Second bump (slower fall)
            pulse = 0.6 * (1.0 - (beat_phase - 0.35) / 0.15)
        end
        -- Rest of cycle is 0

        local heart_scale = 35.0 + pulse * 8.0
        local heart_alpha = 180 + math.floor(pulse * 75.0)

        -- Draw heart shape
        local HEART_SEGMENTS = 32
        local heart_points = {}
        for i = 1, HEART_SEGMENTS do
            local t = (i - 1) / HEART_SEGMENTS * 2.0 * math.pi
            -- Heart parametric equation
            local x = 16.0 * math.sin(t) ^ 3.0
            local y = -(13.0 * math.cos(t) - 5.0 * math.cos(2*t) - 2.0 * math.cos(3*t) - math.cos(4*t))
            heart_points[i] = ImVec2(
                heart_center.x + x * heart_scale / 16.0,
                heart_center.y + y * heart_scale / 16.0)
        end

        -- Glow effect
        for g = 3, 1, -1 do
            local glow_alpha = math.floor(pulse * 30.0 / g)
            draw_list:AddPolyline(heart_points, IM_COL32(255, 50, 80, glow_alpha),
                ImDrawFlags.Closed, 2.0 + g * 3.0)
        end

        draw_list:AddConvexPolyFilled(heart_points, IM_COL32(180, 30, 60, heart_alpha))
        draw_list:AddPolyline(heart_points, IM_COL32(255, 80, 100, 255),
            ImDrawFlags.Closed, 2.0)

        -- ECG Line (right side)
        local ecg_left = canvas_pos.x + 160.0
        local ecg_right = canvas_pos.x + canvas_size.x - 20.0
        local ecg_width = ecg_right - ecg_left
        local ecg_center_y = canvas_pos.y + canvas_size.y * 0.5

        -- Draw ECG background line
        draw_list:AddLine(ImVec2(ecg_left, ecg_center_y), ImVec2(ecg_right, ecg_center_y),
            IM_COL32(40, 60, 40, 255), 1.0)

        -- Draw ECG waveform
        local ECG_POINTS = 60
        local ecg_pts = {}
        for i = 1, ECG_POINTS do
            local x_norm = (i - 1) / (ECG_POINTS - 1)
            local phase = math.fmod(x_norm + beat_phase, 1.0)

            -- ECG waveform shape
            local y = 0.0
            if phase < 0.05 then
                -- P wave (small bump)
                y = 10.0 * math.sin(phase / 0.05 * math.pi)
            elseif phase >= 0.1 and phase < 0.12 then
                -- Q dip
                y = -15.0 * (phase - 0.1) / 0.02
            elseif phase >= 0.12 and phase < 0.15 then
                -- R spike (main peak)
                local t = (phase - 0.12) / 0.03
                y = -15.0 + 65.0 * (t < 0.5 and t * 2.0 or (1.0 - t) * 2.0)
            elseif phase >= 0.15 and phase < 0.18 then
                -- S dip
                y = -20.0 * (1.0 - (phase - 0.15) / 0.03)
            elseif phase >= 0.25 and phase < 0.4 then
                -- T wave (recovery bump)
                y = 15.0 * math.sin((phase - 0.25) / 0.15 * math.pi)
            end

            ecg_pts[i] = ImVec2(ecg_left + x_norm * ecg_width, ecg_center_y - y)
        end

        draw_list:AddPolyline(ecg_pts, IM_COL32(80, 255, 80, 255), 0, 2.0)

        -- Scanning dot
        local dot_x = ecg_left + beat_phase * ecg_width
        draw_list:AddCircleFilled(ImVec2(dot_x, ecg_center_y), 4.0, IM_COL32(150, 255, 150, 255))

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end
end

-- ============================================================
-- OSCILLATORS DEMO
-- ============================================================

local oscillators_state = {
    wave_type_idx = 1,
    frequency = 1.0,
    amplitude = 50.0,
    freq_2d = ImVec2(1.0, 2.0),
    amp_2d = ImVec2(40.0, 40.0),

    wave_types = { IamWaveType.Sine, IamWaveType.Triangle, IamWaveType.Sawtooth, IamWaveType.Square },
    colors = {
        IM_COL32(255, 100, 100, 255),
        IM_COL32(100, 255, 100, 255),
        IM_COL32(100, 100, 255, 255),
        IM_COL32(255, 255, 100, 255)
    },
}

local function ShowOscillatorsDemo()
    local state = oscillators_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Oscillators provide continuous periodic animations without managing state. ' ..
        'Four wave types available: sine, triangle, sawtooth, and square.')

    -- Wave type selector
    state.wave_type_idx = imgui.Combo('Wave Type', state.wave_type_idx, 'Sine\0Triangle\0Sawtooth\0Square\0')
    local wave_type = state.wave_types[state.wave_type_idx]

    state.frequency = imgui.SliderFloat('Frequency', state.frequency, 0.1, 5.0, '%.1f Hz')
    state.amplitude = imgui.SliderFloat('Amplitude', state.amplitude, 10.0, 100.0, '%.0f px')

    -- Visual demo - oscillating circles
    imgui.Separator()
    imgui.Text('Visual Demo (4 circles with different phases):')

    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 120.0)
    local draw_list = imgui.GetWindowDrawList()

    -- Background
    draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
        IM_COL32(30, 30, 40, 255), 4.0)

    -- Center line
    local center_y = canvas_pos.y + canvas_size.y * 0.5
    draw_list:AddLine(ImVec2(canvas_pos.x, center_y), ImVec2(canvas_pos.x + canvas_size.x, center_y),
        IM_COL32(100, 100, 100, 100), 1.0)

    -- Draw 4 circles with different phases
    for i = 1, 4 do
        local phase = (i - 1) * 0.25
        local x = canvas_pos.x + 50.0 + (i - 1) * (canvas_size.x - 100.0) / 3.0
        local offset_y = iam.Oscillate(imgui.GetID('osc_demo_' .. i), state.amplitude, state.frequency, wave_type, phase, dt)
        draw_list:AddCircleFilled(ImVec2(x, center_y + offset_y), 12.0, state.colors[i])
        draw_list:AddCircle(ImVec2(x, center_y + offset_y), 12.0, IM_COL32(255, 255, 255, 100), 0, 2.0)
    end

    imgui.Dummy(canvas_size)

    -- Vec2 oscillation demo
    ApplyOpenAll()
    if imgui.TreeNode('2D Oscillation (Lissajous)') then
        state.freq_2d = imgui.SliderFloatVec2('Frequency X/Y', state.freq_2d, 0.5, 4.0, '%.1f')
        state.amp_2d = imgui.SliderFloatVec2('Amplitude X/Y', state.amp_2d, 10.0, 60.0, '%.0f')

        local canvas_pos2 = imgui.GetCursorScreenPosVec()
        local canvas_size2 = ImVec2(200.0, 200.0)
        local center = canvas_pos2 + canvas_size2 * 0.5

        draw_list:AddRectFilled(canvas_pos2, canvas_pos2 + canvas_size2,
            IM_COL32(30, 30, 40, 255), 4.0)

        local offset = iam.OscillateVec2(imgui.GetID('lissajous'), state.amp_2d, state.freq_2d, IamWaveType.Sine, ImVec2(0, 0), dt)
        draw_list:AddCircleFilled(ImVec2(center.x + offset.x, center.y + offset.y), 10.0, IM_COL32(100, 200, 255, 255))

        imgui.Dummy(canvas_size2)
        imgui.TreePop()
    end

    -- Practical UI example
    ApplyOpenAll()
    if imgui.TreeNode('Practical: Pulsing Button') then
        local pulse = iam.Oscillate(imgui.GetID('pulse_btn'), 0.1, 2.0, IamWaveType.Sine, 0.0, dt)
        local scale = 1.0 + pulse

        -- Fixed height container to prevent layout shifts
        local max_scale = 1.1 -- 1.0 + max amplitude
        local fixed_height = 40 * max_scale + imgui.GetStyle().ItemSpacing.y
        imgui.BeginChild('##PulsingButtonContainer', ImVec2(0, fixed_height), ImGuiChildFlags.None, ImGuiWindowFlags.NoScrollbar)

        imgui.PushFont(nil, imgui.GetStyle().FontSizeBase * scale)
        imgui.PushStyleColor(ImGuiCol.Button, ImVec4(0.2 + pulse * 0.5, 0.5, 0.8, 1.0))
        imgui.Button('Click Me!', ImVec2(120 * scale, 40 * scale))
        imgui.PopStyleColor()
        imgui.PopFont()

        imgui.SameLine()
        imgui.TextDisabled('Button pulses continuously')

        imgui.EndChild()
        imgui.TreePop()
    end
end

-- ============================================================
-- SHAKE/WIGGLE DEMO
-- ============================================================

local shake_wiggle_state = {
    shake_intensity = 10.0,
    shake_frequency = 20.0,
    shake_decay = 0.5,
    wiggle_amplitude = 5.0,
    wiggle_frequency = 3.0,
    input_buf = '',
    show_error = false,
}

local function ShowShakeWiggleDemo()
    local state = shake_wiggle_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Shake provides decaying random motion (for error feedback, impacts). ' ..
        'Wiggle provides continuous smooth random movement (for idle animations, organic feel).')

    -- Shake demo
    ApplyOpenAll()
    if imgui.TreeNodeEx('Shake (Decaying)') then
        state.shake_intensity = imgui.SliderFloat('Intensity', state.shake_intensity, 1.0, 30.0, '%.0f px')
        state.shake_frequency = imgui.SliderFloat('Frequency', state.shake_frequency, 5.0, 50.0, '%.0f Hz')
        state.shake_decay = imgui.SliderFloat('Decay Time', state.shake_decay, 0.1, 2.0, '%.1f s')

        local shake_id = imgui.GetID('shake_demo')
        if imgui.Button('Trigger Shake!') then
            iam.TriggerShake(shake_id)
        end

        local offset = iam.ShakeVec2(shake_id, ImVec2(state.shake_intensity, state.shake_intensity),
            state.shake_frequency, state.shake_decay, dt)

        -- Visual
        local box_pos = imgui.GetCursorScreenPosVec()
        local box_size = ImVec2(180.0, 60.0)
        local center = ImVec2(box_pos.x + 150.0 + offset.x, box_pos.y + 40.0 + offset.y)

        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddRectFilled(
            ImVec2(center.x - box_size.x * 0.5, center.y - box_size.y * 0.5),
            ImVec2(center.x + box_size.x * 0.5, center.y + box_size.y * 0.5),
            IM_COL32(255, 100, 100, 255), 8.0)
        draw_list:AddText(ImVec2(center.x - 25, center.y - 8), IM_COL32(255, 255, 255, 255), 'SHAKE')

        imgui.Dummy(ImVec2(300, 100))
        imgui.TreePop()
    end

    -- Wiggle demo
    ApplyOpenAll()
    if imgui.TreeNode('Wiggle (Continuous)') then
        state.wiggle_amplitude = imgui.SliderFloat('Amplitude##wiggle', state.wiggle_amplitude, 1.0, 20.0, '%.0f px')
        state.wiggle_frequency = imgui.SliderFloat('Frequency##wiggle', state.wiggle_frequency, 0.5, 10.0, '%.1f Hz')

        local offset = iam.WiggleVec2(imgui.GetID('wiggle_demo'),
            ImVec2(state.wiggle_amplitude, state.wiggle_amplitude), state.wiggle_frequency, dt)

        -- Visual - floating icon
        local icon_pos = imgui.GetCursorScreenPosVec()
        local center = ImVec2(icon_pos.x + 150.0 + offset.x, icon_pos.y + 40.0 + offset.y)

        local draw_list = imgui.GetWindowDrawList()
        draw_list:AddCircleFilled(center, 30.0, IM_COL32(100, 200, 100, 255))
        draw_list:AddCircle(center, 30.0, IM_COL32(255, 255, 255, 150), 0, 2.0)
        draw_list:AddText(ImVec2(center.x - 10, center.y - 8), IM_COL32(255, 255, 255, 255), ':)')

        imgui.Dummy(ImVec2(300, 100))
        imgui.SameLine()
        imgui.TextDisabled('Continuous organic movement')
        imgui.TreePop()
    end

    -- Practical example
    ApplyOpenAll()
    if imgui.TreeNode('Practical: Error Feedback') then
        local error_shake_id = imgui.GetID('error_shake')

        local shake_offset = iam.Shake(error_shake_id, 8.0, 30.0, 0.3, dt)

        imgui.SetCursorPosX(imgui.GetCursorPosX() + shake_offset)
        imgui.PushItemWidth(200)

        if state.show_error then
            imgui.PushStyleColor(ImGuiCol.FrameBg, ImVec4(0.5, 0.1, 0.1, 1.0))
            imgui.PushStyleColor(ImGuiCol.Border, ImVec4(1.0, 0.3, 0.3, 1.0))
        end

        state.input_buf = imgui.InputText('##email', state.input_buf)

        if state.show_error then
            imgui.PopStyleColor(2)
        end
        imgui.PopItemWidth()

        imgui.SameLine()
        if imgui.Button('Validate') then
            state.show_error = (#state.input_buf == 0 or not state.input_buf:find('@', 1, true))
            if state.show_error then
                iam.TriggerShake(error_shake_id)
            end
        end

        if state.show_error then
            imgui.TextColored(ImVec4(1, 0.3, 0.3, 1), 'Invalid email format!')
        end
        imgui.TreePop()
    end
end

-- ============================================================
-- SECTION: Scroll Animation
-- ============================================================
local scroll_state = {
    duration = 0.5,
}

local function ShowScrollDemo()
    local state = scroll_state

    imgui.TextWrapped('Smooth animated scrolling within ImGui windows. ' ..
        'Use iam.ScrollToY() for custom positions or convenience functions for common cases.')

    -- Create a child window to demonstrate scrolling
    imgui.Text('Scroll Controls:')

    state.duration = imgui.SliderFloat('Duration##Scroll', state.duration, 0.1, 2.0, '%.1f s')

    local scroll_top = imgui.Button('Scroll to Top')
    imgui.SameLine()
    local scroll_middle = imgui.Button('Scroll to Middle')
    imgui.SameLine()
    local scroll_bottom = imgui.Button('Scroll to Bottom')

    imgui.Separator()

    -- Scrollable child window
    imgui.BeginChild('ScrollDemoChild', ImVec2(0, 300), ImGuiChildFlags.Borders)

    -- Apply scroll commands inside the child window
    if scroll_top then
        iam.ScrollToTop(state.duration)
    end
    if scroll_middle then
        iam.ScrollToY(500.0, state.duration)  -- Roughly middle
    end
    if scroll_bottom then
        iam.ScrollToBottom(state.duration)
    end

    -- Content - many items to scroll through
    for i = 0, 49 do
        local is_special = (i == 0 or i == 24 or i == 49)
        if is_special then
            imgui.PushStyleColor(ImGuiCol.Text, ImVec4(1.0, 0.8, 0.2, 1.0))
        end

        if i == 0 then imgui.Text('>>> TOP - Item %d <<<', i)
        elseif i == 24 then imgui.Text('>>> MIDDLE - Item %d <<<', i)
        elseif i == 49 then imgui.Text('>>> BOTTOM - Item %d <<<', i)
        else imgui.Text('Item %d - Some content here', i)
        end

        if is_special then
            imgui.PopStyleColor()
        end

        -- Add scroll-to buttons for specific items
        if i == 10 or i == 30 then
            imgui.SameLine()
            local btn_label = string.format('Scroll Here##%d', i)
            if imgui.SmallButton(btn_label) then
                iam.ScrollToY(imgui.GetCursorPosY() - 50.0, state.duration)
            end
        end
    end

    imgui.EndChild()

    imgui.TextDisabled('Current scroll Y: %.0f', imgui.GetScrollY())
end

-- ============================================================
-- MOTION PATHS DEMO
-- ============================================================

local motion_path_state = {
    paths_initialized = false,
    bezier_path_id = ImHashStr('bezier_demo_path'),
    catmull_path_id = ImHashStr('catmull_demo_path'),
    complex_path_id = ImHashStr('complex_demo_path'),
    path_duration = 2.0,
    selected_ease = IamEaseType.InOutCubic,
    -- Animation state: elapsed time for each path (-1 = not playing)
    path_elapsed = { -1.0, -1.0, -1.0 },

    ease_names = { 'Linear', 'In Quad', 'Out Quad', 'InOut Quad',
        'In Cubic', 'Out Cubic', 'InOut Cubic', 'In Quart', 'Out Quart', 'InOut Quart' },
}

local function ShowMotionPathsDemo()
    local state = motion_path_state

    imgui.TextWrapped('Motion paths allow animating positions along bezier curves and Catmull-Rom splines.')

    -- Initialize paths once
    if not state.paths_initialized then
        -- Quadratic bezier path
        print(state.bezier_path_id)
        IamPath.Begin(state.bezier_path_id, ImVec2(50, 100))
            :QuadraticTo(ImVec2(150, 20), ImVec2(250, 100))
            :QuadraticTo(ImVec2(350, 180), ImVec2(450, 100))
            :End()

        -- Catmull-Rom spline path
        IamPath.Begin(state.catmull_path_id, ImVec2(50, 50))
            :CatmullTo(ImVec2(150, 120))
            :CatmullTo(ImVec2(250, 30))
            :CatmullTo(ImVec2(350, 100))
            :CatmullTo(ImVec2(450, 50))
            :End()

        -- Complex cubic bezier path
        IamPath.Begin(state.complex_path_id, ImVec2(50, 80))
            :CubicTo(ImVec2(100, 10), ImVec2(150, 150), ImVec2(200, 80))
            :CubicTo(ImVec2(250, 10), ImVec2(300, 150), ImVec2(350, 80))
            :LineTo(ImVec2(450, 80))
            :End()

        state.paths_initialized = true
    end

    state.path_duration = imgui.SliderFloat('Duration##MotionPath', state.path_duration, 0.5, 5.0)
    state.selected_ease = imgui.Combo('Easing', state.selected_ease, state.ease_names, #state.ease_names)

    if imgui.Button('Play Bezier') then state.path_elapsed[1] = 0.0 end
    imgui.SameLine()
    if imgui.Button('Play Catmull-Rom') then state.path_elapsed[2] = 0.0 end
    imgui.SameLine()
    if imgui.Button('Play Complex') then state.path_elapsed[3] = 0.0 end

    -- Draw area
    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(500, 180)
    local draw = imgui.GetWindowDrawList()
    draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))
    imgui.Dummy(canvas_size)

    local dt = GetSafeDeltaTime()

    -- Draw paths and animate
    local function draw_path(path_id, path_color, elapsed_idx, idx)
        -- Draw the path
        for t = 0, 1, 0.01 do
            local p1 = iam.PathEvaluate(path_id, t)
            local p2 = iam.PathEvaluate(path_id, t + 0.01)
            draw:AddLine(
                ImVec2(canvas_pos.x + p1.x, canvas_pos.y + p1.y + idx * 60),
                ImVec2(canvas_pos.x + p2.x, canvas_pos.y + p2.y + idx * 60),
                path_color, 2.0)
        end

        -- Animate object along path using timer + easing
        if state.path_elapsed[elapsed_idx] >= 0.0 then
            state.path_elapsed[elapsed_idx] = state.path_elapsed[elapsed_idx] + dt
            local t = state.path_elapsed[elapsed_idx] / state.path_duration
            if t > 1.0 then
                t = 1.0
                state.path_elapsed[elapsed_idx] = -1.0  -- Stop animation
            end
            -- Apply easing
            local eased_t = iam.EvalPreset(state.selected_ease, t)
            local pos = iam.PathEvaluate(path_id, eased_t)
            draw:AddCircleFilled(
                ImVec2(canvas_pos.x + pos.x, canvas_pos.y + pos.y + idx * 60),
                8.0, IM_COL32(255, 255, 255, 255))
        end
    end

    draw_path(state.bezier_path_id, IM_COL32(100, 200, 255, 255), 1, 0)
    draw_path(state.catmull_path_id, IM_COL32(100, 255, 100, 255), 2, 1)
    draw_path(state.complex_path_id, IM_COL32(255, 150, 100, 255), 3, 2)

    -- Labels
    draw:AddText(ImVec2(canvas_pos.x + 5, canvas_pos.y + 5), IM_COL32(100, 200, 255, 255), 'Quadratic Bezier')
    draw:AddText(ImVec2(canvas_pos.x + 5, canvas_pos.y + 65), IM_COL32(100, 255, 100, 255), 'Catmull-Rom')
    draw:AddText(ImVec2(canvas_pos.x + 5, canvas_pos.y + 125), IM_COL32(255, 150, 100, 255), 'Cubic Bezier + Line')

    imgui.TextDisabled('Paths can mix bezier curves, Catmull-Rom splines, and lines.')
end

-- ============================================================
-- PATH MORPHING DEMO
-- ============================================================

local path_morph_state = {
    paths_initialized = false,
    path_circle_id = ImHashStr('morph_circle_path'),
    path_star_id = ImHashStr('morph_star_path'),
    path_wave_id = ImHashStr('morph_wave_path'),
    path_heart_id = ImHashStr('morph_heart_path'),

    -- Manual Morph Control
    blend = 0.0,
    path_a_idx = 1,
    path_b_idx = 2,

    -- Animated Shape Morph
    morph_timer = 0.0,
    animating = false,
    from_shape = 1,
    to_shape = 2,
    -- Object Along Morphing Path
    path_t = 0.0,
    path_blend = 0.0,
    animating_path = false,

    path_names_1 = { 'Circle', 'Star', 'Wave', 'Heart' },
    path_ids_1 = {},

    path_names_2 = { 'Circle', 'Star', 'Wave', 'Heart' },
    path_ids_2 = {},
}

local function ShowPathMorphingDemo()
    local state = path_morph_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped(
        'Path morphing allows smooth interpolation between two different paths, even if they have ' ..
        'different numbers of control points. Useful for shape transitions and metamorphosis effects.')

    imgui.Spacing()

    -- Initialize paths
    if not state.paths_initialized then
        -- Circle-like path (using bezier approximation)
        local cx, cy, r = 200, 100, 60
        local k = 0.5522847498 -- bezier circle constant
        IamPath.Begin(state.path_circle_id, ImVec2(cx + r, cy))
            :CubicTo(ImVec2(cx + r, cy + r * k), ImVec2(cx + r * k, cy + r), ImVec2(cx, cy + r))
            :CubicTo(ImVec2(cx - r * k, cy + r), ImVec2(cx - r, cy + r * k), ImVec2(cx - r, cy))
            :CubicTo(ImVec2(cx - r, cy - r * k), ImVec2(cx - r * k, cy - r), ImVec2(cx, cy - r))
            :CubicTo(ImVec2(cx + r * k, cy - r), ImVec2(cx + r, cy - r * k), ImVec2(cx + r, cy))
            :End()

        -- Star-like path
        local sr, sir = 70, 30 -- outer and inner radius
        local star_points = {}
        for i = 0, 9 do
            local angle = i * math.pi * 2.0 / 10.0 - math.pi / 2.0
            local rad = (i % 2 == 0) and sr or sir
            star_points[i + 1] = ImVec2(cx + rad * math.cos(angle), cy + rad * math.sin(angle))
        end
        IamPath.Begin(state.path_star_id, star_points[1])
            :LineTo(star_points[2]):LineTo(star_points[3]):LineTo(star_points[4])
            :LineTo(star_points[5]):LineTo(star_points[6]):LineTo(star_points[7])
            :LineTo(star_points[8]):LineTo(star_points[9]):LineTo(star_points[10])
            :LineTo(star_points[1])
            :End()

        -- Wave path
        IamPath.Begin(state.path_wave_id, ImVec2(100, cy))
            :CubicTo(ImVec2(130, cy - 50), ImVec2(170, cy - 50), ImVec2(200, cy))
            :CubicTo(ImVec2(230, cy + 50), ImVec2(270, cy + 50), ImVec2(300, cy))
            :End()

        -- Heart-like path
        IamPath.Begin(state.path_heart_id, ImVec2(cx, cy + 60))
            :CubicTo(ImVec2(cx + 5, cy + 40), ImVec2(cx + 40, cy + 20), ImVec2(cx + 60, cy - 10))
            :CubicTo(ImVec2(cx + 75, cy - 35), ImVec2(cx + 55, cy - 55), ImVec2(cx + 30, cy - 55))
            :CubicTo(ImVec2(cx + 10, cy - 55), ImVec2(cx, cy - 40), ImVec2(cx, cy - 30))
            :CubicTo(ImVec2(cx, cy - 40), ImVec2(cx - 10, cy - 55), ImVec2(cx - 30, cy - 55))
            :CubicTo(ImVec2(cx - 55, cy - 55), ImVec2(cx - 75, cy - 35), ImVec2(cx - 60, cy - 10))
            :CubicTo(ImVec2(cx - 40, cy + 20), ImVec2(cx - 5, cy + 40), ImVec2(cx, cy + 60))
            :End()

        state.path_ids_1 = { state.path_circle_id, state.path_star_id, state.path_wave_id, state.path_heart_id }
        state.path_ids_2 = { state.path_circle_id, state.path_star_id, state.path_wave_id, state.path_heart_id }
        state.paths_initialized = true
    end

    -- Demo 1: Manual blend slider
    ApplyOpenAll()
    if imgui.TreeNode('Manual Morph Control') then
        imgui.SetNextItemWidth(100)
        state.path_a_idx = imgui.Combo('Path A', state.path_a_idx, state.path_names_1, #state.path_names_1)
        imgui.SameLine()
        imgui.SetNextItemWidth(100)
        state.path_b_idx = imgui.Combo('Path B', state.path_b_idx, state.path_names_1, #state.path_names_1)
        imgui.SameLine()
        imgui.SetNextItemWidth(200)
        state.blend = imgui.SliderFloat('Blend', state.blend, 0.0, 1.0)

        -- Draw area
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 200)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), IM_COL32(30, 30, 40, 255))
        imgui.Dummy(canvas_size)

        -- Draw morphed path
        local pa = state.path_ids_2[state.path_a_idx]
        local pb = state.path_ids_2[state.path_b_idx]

        local opts = IamMorphOpts()
        opts.samples = 100

        local prev_pt
        for i = 0, 100 do
            local t = i / 100.0
            local pt = iam.PathMorph(pa, pb, t, state.blend, opts)
            pt = pt + canvas_pos
            if i > 0 then
                local col = IM_COL32(
                    math.floor(100 + 155 * state.blend),
                    math.floor(200 - 100 * state.blend),
                    math.floor(255 - 155 * state.blend),
                    255
                )
                draw:AddLine(prev_pt, pt, col, 3.0)
            end
            prev_pt = pt
        end

        imgui.TextDisabled('Drag the blend slider to morph between shapes.')
        imgui.TreePop()
    end

    -- Demo 2: Animated morph
    ApplyOpenAll()
    if imgui.TreeNode('Animated Shape Morph') then
        imgui.SetNextItemWidth(100)
        state.from_shape = imgui.Combo('From##anim', state.from_shape, state.path_names_2, #state.path_names_2)
        imgui.SameLine()
        imgui.SetNextItemWidth(100)
        state.to_shape = imgui.Combo('To##anim', state.to_shape, state.path_names_2, #state.path_names_2)
        imgui.SameLine()

        if imgui.Button(state.animating and 'Reset' or 'Morph!') then
            if state.animating then
                state.animating = false
                state.morph_timer = 0.0
            else
                state.animating = true
                state.morph_timer = 0.0
            end
        end

        -- Animate blend
        local duration = 2.0
        local blend = 0.0
        if state.animating then
            state.morph_timer = state.morph_timer + dt
            local t = math.max(0.0, math.min(1.0, state.morph_timer / duration))
            blend = iam.EvalPreset(IamEaseType.InOutCubic, t)
            if state.morph_timer > duration + 0.5 then
                state.animating = false
                state.morph_timer = 0.0
            end
        end

        -- Draw area
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 200)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + canvas_size.y), IM_COL32(30, 30, 40, 255))
        imgui.Dummy(canvas_size)

        -- Draw morphed shape
        local pa = state.path_ids_2[state.from_shape]
        local pb = state.path_ids_2[state.to_shape]
        local opts = IamMorphOpts()
        opts.samples = 100

        local prev_pt
        for i = 0, 100 do
            local t = i / 100.0
            local pt = iam.PathMorph(pa, pb, t, blend, opts)
            pt = pt + canvas_pos
            if i > 0 then
                draw:AddLine(prev_pt, pt, IM_COL32(100, 255, 150, 255), 3.0)
            end
            prev_pt = pt
        end

        imgui.Text('Blend: %.2f', blend)
        imgui.TextDisabled("Click 'Morph!' to animate the shape transition.")
        imgui.TreePop()
    end

    -- Demo 3: Object along morphing path
    ApplyOpenAll()
    if imgui.TreeNode('Object Along Morphing Path') then
        state.path_t = imgui.SliderFloat('Path T', state.path_t, 0.0, 1.0)
        state.path_blend = imgui.SliderFloat('Morph Blend', state.path_blend, 0.0, 1.0)

        if imgui.Button(state.animating_path and 'Stop' or 'Animate Along Path') then
            state.animating_path = not state.animating_path
            if state.animating_path then state.path_t = 0.0 end
        end

        if state.animating_path then
            state.path_t = state.path_t + dt * 0.5
            if state.path_t > 1.0 then state.path_t = 0.0 end
        end

        -- Draw area
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 200)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))
        imgui.Dummy(canvas_size)

        local opts = IamMorphOpts()
        opts.samples = 100

        -- Draw morphed path
        local prev_pt
        for i = 0, 100 do
            local t = i / 100.0
            local pt = iam.PathMorph(state.path_circle_id, state.path_star_id, t, state.path_blend, opts)
            pt = pt + canvas_pos
            if i > 0 then
                draw:AddLine(prev_pt, pt, IM_COL32(80, 80, 100, 255), 2.0)
            end
            prev_pt = pt
        end

        -- Draw object at current position
        local obj_pos = iam.PathMorph(state.path_circle_id, state.path_star_id, state.path_t, state.path_blend, opts)
        obj_pos = obj_pos + canvas_pos

        -- Get tangent for rotation
        local angle = iam.PathMorphAngle(state.path_circle_id, state.path_star_id, state.path_t, state.path_blend, opts)

        -- Draw rotated triangle
        local size = 12.0
        local p1 = ImVec2(obj_pos.x + size * math.cos(angle), obj_pos.y + size * math.sin(angle))
        local p2 = ImVec2(obj_pos.x + size * math.cos(angle + 2.5), obj_pos.y + size * math.sin(angle + 2.5))
        local p3 = ImVec2(obj_pos.x + size * math.cos(angle - 2.5), obj_pos.y + size * math.sin(angle - 2.5))
        draw:AddTriangleFilled(p1, p2, p3, IM_COL32(255, 200, 100, 255))

        imgui.TextDisabled('Object follows the morphed path with proper rotation.')
        imgui.TreePop()
    end
end

-- ============================================================
-- TEXT ALONG MOTION PATHS DEMO
-- ============================================================

local text_path_state = {
    paths_initialized = false,
    wave_path_id = ImHashStr('text_wave_path'),
    arc_path_id = ImHashStr('text_arc_path'),
    spiral_path_id = ImHashStr('text_spiral_path'),
    animation_progress = 0.0,
    auto_animate = false,
    animation_speed = 0.5,
    selected_align = 1,
    letter_spacing = 0.0,
    font_scale = 1.0,
}

local function ShowTextAlongPathDemo()
    local state = text_path_state

    imgui.TextWrapped('Text can be animated along motion paths with proper character rotation and constant-speed placement.')

    -- Initialize paths once
    if not state.paths_initialized then
        -- Wave path (sine wave using quadratic beziers)
        IamPath.Begin(state.wave_path_id, ImVec2(20, 60))
            :QuadraticTo(ImVec2(80, 20), ImVec2(140, 60))
            :QuadraticTo(ImVec2(200, 100), ImVec2(260, 60))
            :QuadraticTo(ImVec2(320, 20), ImVec2(380, 60))
            :End()

        -- Arc path (half circle using cubic bezier approximation)
        local r = 120.0
        local cx, cy = 200.0, 100.0
        IamPath.Begin(state.arc_path_id, ImVec2(cx - r, cy))
            :CubicTo(ImVec2(cx - r, cy - r * 0.55), ImVec2(cx - r * 0.55, cy - r), ImVec2(cx, cy - r))
            :CubicTo(ImVec2(cx + r * 0.55, cy - r), ImVec2(cx + r, cy - r * 0.55), ImVec2(cx + r, cy))
            :End()

        -- Spiral path using catmull-rom
        IamPath.Begin(state.spiral_path_id, ImVec2(200, 80))
            :CatmullTo(ImVec2(280, 40))
            :CatmullTo(ImVec2(340, 80))
            :CatmullTo(ImVec2(280, 120))
            :CatmullTo(ImVec2(200, 80))
            :CatmullTo(ImVec2(140, 50))
            :CatmullTo(ImVec2(60, 80))
            :End()

        -- Build arc-length LUTs for accurate text placement
        iam.PathBuildArcLut(state.wave_path_id, 128)
        iam.PathBuildArcLut(state.arc_path_id, 128)
        iam.PathBuildArcLut(state.spiral_path_id, 128)

        state.paths_initialized = true
    end

    -- Animation controls
    state.auto_animate = imgui.Checkbox('Auto Animate', state.auto_animate)
    imgui.SameLine()
    state.animation_speed = imgui.SliderFloat('Speed', state.animation_speed, 0.1, 2.0)

    if not state.auto_animate then
        state.animation_progress = imgui.SliderFloat('Progress', state.animation_progress, 0.0, 1.0)
    else
        local dt = GetSafeDeltaTime()
        state.animation_progress = state.animation_progress + dt * state.animation_speed
        if state.animation_progress > 1.0 then state.animation_progress = 0.0 end
    end

    local align_names = { 'Start', 'Center', 'End' }
    state.selected_align = imgui.Combo('Alignment', state.selected_align, align_names, #align_names)
    state.letter_spacing = imgui.SliderFloat('Letter Spacing', state.letter_spacing, -2.0, 10.0)
    state.font_scale = imgui.SliderFloat('Font Scale', state.font_scale, 0.5, 2.0)

    -- Demo 1: Wave text
    imgui.Separator()
    imgui.Text('Wave Path:')
    do
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 120)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(20, 25, 35, 255))
        imgui.Dummy(canvas_size)

        -- Draw path
        for t = 0, 0.99, 0.01 do
            local p1 = iam.PathEvaluate(state.wave_path_id, t)
            local p2 = iam.PathEvaluate(state.wave_path_id, t + 0.01)
            draw:AddLine(
                canvas_pos + p1,
                canvas_pos + p2,
                IM_COL32(60, 60, 80, 255), 1.0)
        end

        -- Draw text along path
        local opts = IamTextPathOpts()
        opts.origin = canvas_pos
        opts.align = state.selected_align - 1
        opts.letter_spacing = state.letter_spacing
        opts.font_scale = state.font_scale
        opts.color = IM_COL32(100, 200, 255, 255)
        iam.TextPathAnimated(state.wave_path_id, 'Hello World!', state.animation_progress, opts)
    end

    -- Demo 2: Arc text
    imgui.Text('Arc Path:')
    do
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 120)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(20, 25, 35, 255))
        imgui.Dummy(canvas_size)

        -- Draw path
        for t = 0, 0.99, 0.01 do
            local p1 = iam.PathEvaluate(state.arc_path_id, t)
            local p2 = iam.PathEvaluate(state.arc_path_id, t + 0.01)
            draw:AddLine(
                canvas_pos + p1,
                canvas_pos + p2,
                IM_COL32(60, 60, 80, 255), 1.0)
        end

        -- Draw text along path
        local opts = IamTextPathOpts()
        opts.origin = canvas_pos
        opts.align = IamTextPathAlign.Center
        opts.letter_spacing = state.letter_spacing
        opts.font_scale = state.font_scale
        opts.color = IM_COL32(255, 200, 100, 255)
        iam.TextPathAnimated(state.arc_path_id, 'CURVED TEXT', state.animation_progress, opts)
    end

    -- Demo 3: Spiral text (static, not animated)
    imgui.Text('Spiral Path (Static):')
    do
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(400, 140)
        local draw = imgui.GetWindowDrawList()
        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(20, 25, 35, 255))
        imgui.Dummy(canvas_size)

        -- Draw path
        for t = 0, 0.99, 0.01 do
            local p1 = iam.PathEvaluate(state.spiral_path_id, t)
            local p2 = iam.PathEvaluate(state.spiral_path_id, t + 0.01)
            draw:AddLine(
                canvas_pos + p1,
                canvas_pos + p2,
                IM_COL32(60, 60, 80, 255), 1.0)
        end

        -- Draw text along path (static)
        local opts = IamTextPathOpts()
        opts.origin = canvas_pos
        opts.align = state.selected_align - 1
        opts.letter_spacing = state.letter_spacing
        opts.font_scale = state.font_scale
        opts.color = IM_COL32(100, 255, 150, 255)
        iam.TextPath(state.spiral_path_id, 'Following the winding path...', opts)
    end

    imgui.TextDisabled('Text uses arc-length parameterization for constant character spacing.')
end

-- ============================================================
-- SECTION: Timeline Markers
-- ============================================================
local timeline_marker_state = {
    clip_initialized = false,
    marker_clip_id = ImHashStr('marker_demo_clip'),
    marker_inst = nil,
    marker_log = {},
    marker_log_time = 0.0,

    progress_id = ImHashStr('progress'),
    marker_inst_id = ImHashStr('marker_inst'),
}

local function ShowTimelineMarkersDemo()
    local state = timeline_marker_state
    imgui.TextWrapped('Timeline markers trigger callbacks at specific times during clip playback.')

    -- Initialize clip with markers
    if not state.clip_initialized then
        -- Marker callback
        local marker_callback = function(inst_id, marker_id, marker_time)
            table.insert(state.marker_log, string.format('Marker at %.2fs', marker_time))
            state.marker_log_time = 3.0 -- Show for 3 seconds
        end
        IamClip.Begin(state.marker_clip_id)
            :KeyFloat(state.progress_id, 0.0, 0.0, IamEaseType.Linear)
            :KeyFloat(state.progress_id, 3.0, 1.0, IamEaseType.Linear)
            :Marker(0.5, marker_callback)
            :Marker(1.0, marker_callback)
            :Marker(1.5, marker_callback)
            :Marker(2.0, marker_callback)
            :Marker(2.5, marker_callback)
            :End()
        state.clip_initialized = true
    end

    if imgui.Button('Play Clip with Markers') then
        -- Clear log
        state.marker_log = {}
        state.marker_inst = iam.Play(state.marker_clip_id, state.marker_inst_id)
    end

    -- Progress bar
    local progress = 0.0
    if state.marker_inst and state.marker_inst:Valid() then
        progress = state.marker_inst:GetFloat(state.progress_id)
    end
    imgui.ProgressBar(progress, ImVec2(-1, 0), '')

    -- Show markers on timeline
    local bar_pos = imgui.GetItemRectMinVec()
    local bar_size = imgui.GetItemRectSizeVec()
    local draw = imgui.GetWindowDrawList()
    local marker_times = { 0.5, 1.0, 1.5, 2.0, 2.5 }
    for i = 1, 5 do
        local t = marker_times[i] / 3.0
        local x = bar_pos.x + bar_size.x * t
        draw:AddLine(ImVec2(x, bar_pos.y), ImVec2(x, bar_pos.y + bar_size.y), IM_COL32(255, 200, 100, 255), 2.0)
    end

    -- Marker log
    imgui.Text('Marker Events:')
    state.marker_log_time = state.marker_log_time - GetSafeDeltaTime()
    if state.marker_log_time > 0 then
        for i = 1, #state.marker_log do
            imgui.BulletText('%s', state.marker_log[i])
        end
    end

    imgui.TextDisabled('Orange lines show marker positions on the timeline.')
end

-- ============================================================
-- ANIMATION CHAINING DEMO
-- ============================================================
local anim_chain_state = {
    clips_initialized = false,
    clip_a = ImHashStr('chain_clip_a'),
    clip_b = ImHashStr('chain_clip_b'),
    clip_c = ImHashStr('chain_clip_c'),
    chain_delay = 0.1,
    b_chain_set = false,

    x_id = ImHashStr('x'),
    y_id = ImHashStr('y'),
    color_id = ImHashStr('color'),

    inst_a_id = ImHashStr('chain_inst_a'),
    inst_b_id = ImHashStr('chain_inst_b'),
    inst_c_id = ImHashStr('chain_inst_c'),
}

local function ShowAnimationChainingDemo()
    local state = anim_chain_state
    imgui.TextWrapped('Animation chaining allows clips to automatically trigger another clip when they complete.')

    -- Initialize clips
    if not state.clips_initialized then
        -- Clip A: Move right
        IamClip.Begin(state.clip_a)
            :KeyFloat(state.x_id, 0.0, 50.0, IamEaseType.OutCubic)
            :KeyFloat(state.x_id, 0.5, 200.0, IamEaseType.OutCubic)
            :KeyVec4(state.color_id, 0.0, ImVec4(1, 0.3, 0.3, 1), IamEaseType.Linear)
            :KeyVec4(state.color_id, 0.5, ImVec4(1, 0.3, 0.3, 1), IamEaseType.Linear)
            :End()

        -- Clip B: Move down
        IamClip.Begin(state.clip_b)
            :KeyFloat(state.y_id, 0.0, 30.0, IamEaseType.OutCubic)
            :KeyFloat(state.y_id, 0.5, 100.0, IamEaseType.OutCubic)
            :KeyVec4(state.color_id, 0.0, ImVec4(0.3, 1, 0.3, 1), IamEaseType.Linear)
            :KeyVec4(state.color_id, 0.5, ImVec4(0.3, 1, 0.3, 1), IamEaseType.Linear)
            :End()

        -- Clip C: Move diagonally back
        IamClip.Begin(state.clip_c)
            :KeyFloat(state.x_id, 0.0, 200.0, IamEaseType.OutCubic)
            :KeyFloat(state.x_id, 0.5, 50.0, IamEaseType.OutCubic)
            :KeyFloat(state.y_id, 0.0, 100.0, IamEaseType.OutCubic)
            :KeyFloat(state.y_id, 0.5, 30.0, IamEaseType.OutCubic)
            :KeyVec4(state.color_id, 0.0, ImVec4(0.3, 0.3, 1, 1), IamEaseType.Linear)
            :KeyVec4(state.color_id, 0.5, ImVec4(0.3, 0.3, 1, 1), IamEaseType.Linear)
            :End()

        state.clips_initialized = true
    end

    state.chain_delay = imgui.SliderFloat('Delay Between Clips', state.chain_delay, 0.0, 0.5)

    if imgui.Button('Play A -> B -> C (Chained)') then
        -- Destroy any existing instances to start fresh
        local old_a = iam.GetInstance(state.inst_a_id)
        local old_b = iam.GetInstance(state.inst_b_id)
        local old_c = iam.GetInstance(state.inst_c_id)
        if old_a:Valid() then old_a:Destroy() end
        if old_b:Valid() then old_b:Destroy() end
        if old_c:Valid() then old_c:Destroy() end
        state.b_chain_set = false

        -- Start clip A with chain to B
        local inst_a = iam.Play(state.clip_a, state.inst_a_id)
        inst_a:Then(state.clip_b, state.inst_b_id):ThenDelay(state.chain_delay)
    end
    imgui.SameLine()
    imgui.TextDisabled('(with .Then())')

    -- Get instances
    local inst_a = iam.GetInstance(state.inst_a_id)
    local inst_b = iam.GetInstance(state.inst_b_id)
    local inst_c = iam.GetInstance(state.inst_c_id)

    -- Set up B -> C chain when B starts (can't do this upfront since B doesn't exist yet)
    if inst_b:Valid() and inst_b:IsPlaying() and not state.b_chain_set then
        inst_b:Then(state.clip_c, state.inst_c_id):ThenDelay(state.chain_delay)
        state.b_chain_set = true
    end

    -- Draw animated object
    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(300, 150)
    local draw = imgui.GetWindowDrawList()
    draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))

    -- Determine which instance is active and get values from it
    local x = 50.0
    local y = 30.0
    local color = ImVec4(0.5, 0.5, 0.5, 1.0)

    -- Only read from the currently active (or most recently finished) instance
    if inst_c:Valid() then
        x = inst_c:GetFloat(state.x_id)
        y = inst_c:GetFloat(state.y_id)
        color = inst_c:GetVec4(state.color_id)
    elseif inst_b:Valid() then
        -- Get x from A's final value
        if inst_a:Valid() then x = inst_a:GetFloat(state.x_id) end
        y = inst_b:GetFloat(state.y_id)
        color = inst_b:GetVec4(state.color_id)
    elseif inst_a:Valid() then
        x = inst_a:GetFloat(state.x_id)
        color = inst_a:GetVec4(state.color_id)
    end

    local obj_color = imgui.ColorConvertFloat4ToU32(color)
    draw:AddCircleFilled(ImVec2(canvas_pos.x + x, canvas_pos.y + y), 15.0, obj_color)

    imgui.Dummy(canvas_size)

    -- Status
    imgui.Text('Instance Status:')
    imgui.BulletText('A: %s', inst_a:Valid() and (inst_a:IsPlaying() and 'Playing' or 'Done') or 'Not started')
    imgui.BulletText('B: %s', inst_b:Valid() and (inst_b:IsPlaying() and 'Playing' or 'Done') or 'Not started')
    imgui.BulletText('C: %s', inst_c:Valid() and (inst_c:IsPlaying() and 'Playing' or 'Done') or 'Not started')
end

-- ============================================================
-- TEXT STAGGER DEMO
-- ============================================================

local text_stagger_state = {
    effect_idx = 2,
    effect_names = { 'None', 'Fade', 'Scale', 'Slide Up', 'Slide Down', 'Slide Left', 'Slide Right',
        'Rotate', 'Bounce', 'Wave', 'Typewriter'
    },
    effect_values = {
        IamTextStaggerEffect.None, IamTextStaggerEffect.Fade, IamTextStaggerEffect.Scale,
        IamTextStaggerEffect.SlideUp, IamTextStaggerEffect.SlideDown, IamTextStaggerEffect.SlideLeft,
        IamTextStaggerEffect.SlideRight, IamTextStaggerEffect.Rotate, IamTextStaggerEffect.Bounce,
        IamTextStaggerEffect.Wave, IamTextStaggerEffect.Typewriter
    },
    char_delay = 0.05,
    char_duration = 0.3,
    intensity = 20.0,
    progress = 0.0,
    playing = false,

    texts = { 'Fade In', 'Scale Up', 'Slide Up', 'Bounce!', 'Wave~' },
    effects = { IamTextStaggerEffect.Fade, IamTextStaggerEffect.Scale, IamTextStaggerEffect.SlideUp, IamTextStaggerEffect.Bounce, IamTextStaggerEffect.Wave },
}

local function ShowTextStaggerDemo()
    local state = text_stagger_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Text stagger animates text character-by-character with various effects. ' ..
        'Each character is animated individually with configurable delay and duration.')

    -- Effect selector
    state.effect_idx = imgui.Combo('Effect', state.effect_idx, state.effect_names, #state.effect_names)

    -- Parameters
    state.char_delay = imgui.SliderFloat('Char Delay', state.char_delay, 0.01, 0.2, '%.2f s')
    state.char_duration = imgui.SliderFloat('Char Duration', state.char_duration, 0.1, 1.0, '%.2f s')
    state.intensity = imgui.SliderFloat('Intensity', state.intensity, 5.0, 50.0, '%.0f')

    -- Animation control
    if imgui.Button(state.playing and 'Reset##TextStagger' or 'Play##TextStagger') then
        state.playing = not state.playing
        state.progress = 0.0
    end
    imgui.SameLine()
    state.progress = imgui.SliderFloat('Progress', state.progress, 0.0, 1.0)

    if state.playing then
        state.progress = state.progress + dt * 0.5 -- 2 seconds for full animation
        if state.progress > 1.0 then
            state.progress = 1.0
            state.playing = false
        end
    end

    -- Demo text
    local demo_text = 'Hello, ImAnim!'

    imgui.Separator()

    -- Visual demo
    local canvas_pos = imgui.GetCursorScreenPosVec()
    local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 80.0)
    local draw_list = imgui.GetWindowDrawList()

    draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
        IM_COL32(30, 30, 40, 255), 4.0)

    local opts = IamTextStaggerOpts()
    opts.pos = ImVec2(canvas_pos.x + 20.0, canvas_pos.y + canvas_size.y * 0.5 - 10.0)
    opts.effect = state.effect_values[state.effect_idx]
    opts.char_delay = state.char_delay
    opts.char_duration = state.char_duration
    opts.effect_intensity = state.intensity
    opts.color = IM_COL32(100, 200, 255, 255)

    iam.TextStagger(imgui.GetID('stagger_demo'), demo_text, state.progress, opts)

    imgui.Dummy(canvas_size)

    -- Duration info
    local total_duration = iam.TextStaggerDuration(demo_text, opts)
    imgui.Text('Total Duration: %.2f s', total_duration)

    -- Multiple effect comparison
    ApplyOpenAll()
    if imgui.TreeNode('Effect Comparison') then
        local pos = imgui.GetCursorScreenPosVec()
        local size = ImVec2(imgui.GetContentRegionAvailVec().x, 300.0)
        draw_list:AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), IM_COL32(25, 25, 35, 255), 4.0)

        for i = 1, 5 do
            local o = IamTextStaggerOpts()
            o.pos = ImVec2(pos.x + 20.0, pos.y + 30.0 + (i - 1) * 55.0)
            o.effect = state.effects[i]
            o.char_delay = 0.04
            o.char_duration = 0.25
            o.color = IM_COL32(255 - (i - 1) * 30, 150 + (i - 1) * 20, 100 + (i - 1) * 30, 255)
            iam.TextStagger(imgui.GetID('stagger_cmp_' .. i), state.texts[i], state.progress, o)
        end

        imgui.Dummy(size)
        imgui.TreePop()
    end
end

-- ============================================================
-- NOISE CHANNELS DEMO
-- ============================================================

local noise_state = {
    noise_type_idx = 1,
    noise_type_names = { 'Perlin', 'Simplex', 'Value', 'Worley' },
    noise_type_values = { IamNoiseType.Perlin, IamNoiseType.Simplex, IamNoiseType.Value, IamNoiseType.Worley },

    octaves = 4,
    persistence = 0.5,
    lacunarity = 2.0,
    frequency = 1.0,
    amplitude = 40.0,

    time_offset = 0.0,
}

local function ShowNoiseChannelsDemo()
    local state = noise_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Noise channels provide organic, natural-looking movement using Perlin, Simplex, ' ..
        'or other noise algorithms. Great for idle animations and procedural effects.')

    state.noise_type_idx = imgui.Combo('Noise Type', state.noise_type_idx, state.noise_type_names, #state.noise_type_names)
    local noise_type = state.noise_type_values[state.noise_type_idx]

    state.octaves = imgui.SliderInt('Octaves', state.octaves, 1, 8)
    state.persistence = imgui.SliderFloat('Persistence', state.persistence, 0.1, 1.0)
    state.lacunarity = imgui.SliderFloat('Lacunarity', state.lacunarity, 1.0, 4.0)

    state.frequency = imgui.SliderFloat('Frequency', state.frequency, 0.1, 5.0, '%.1f Hz')
    state.amplitude = imgui.SliderFloat('Amplitude', state.amplitude, 10.0, 100.0, '%.0f px')

    ApplyOpenAll()
    if imgui.TreeNodeEx('2D Noise Visualization') then
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(200, 200)
        local draw_list = imgui.GetWindowDrawList()

        local opts = IamNoiseOpts()
        opts.type = noise_type
        opts.octaves = state.octaves
        opts.persistence = state.persistence
        opts.lacunarity = state.lacunarity

        state.time_offset = state.time_offset + dt * 0.5

        local res = 50
        local cell_w = canvas_size.x / res
        local cell_h = canvas_size.y / res

        for y = 0, res - 1 do
            for x = 0, res - 1 do
                local nx = x * 0.1 + state.time_offset
                local ny = y * 0.1
                local n = iam.Noise2D(nx, ny, opts)
                n = (n + 1.0) * 0.5
                local c = math.floor(n * 255)
                local p0 = ImVec2(canvas_pos.x + x * cell_w, canvas_pos.y + y * cell_h)
                local p1 = ImVec2(p0.x + cell_w, p0.y + cell_h)
                draw_list:AddRectFilled(p0, p1, IM_COL32(c, c, c, 255))
            end
        end

        draw_list:AddRect(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(100, 100, 100, 255))

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNodeEx('Animated Noise Channel') then
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(imgui.GetContentRegionAvailVec().x, 120.0)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(30, 30, 40, 255), 4.0)

        local center_y = canvas_pos.y + canvas_size.y * 0.5
        draw_list:AddLine(ImVec2(canvas_pos.x, center_y), ImVec2(canvas_pos.x + canvas_size.x, center_y),
            IM_COL32(80, 80, 80, 100))

        local colors = {
            IM_COL32(255, 100, 100, 255),
            IM_COL32(100, 255, 100, 255),
            IM_COL32(100, 100, 255, 255),
            IM_COL32(255, 255, 100, 255)
        }

        for i = 0, 3 do
            local x = canvas_pos.x + 50.0 + i * (canvas_size.x - 100.0) / 3.0
            local opts = IamNoiseOpts()
            opts.type = noise_type
            opts.octaves = state.octaves
            opts.persistence = state.persistence
            opts.lacunarity = state.lacunarity
            opts.seed = i * 12345
            local offset = iam.NoiseChannelFloat(imgui.GetID('noise_demo_' .. i), state.frequency, state.amplitude, opts, dt)
            draw_list:AddCircleFilled(ImVec2(x, center_y + offset), 12.0, colors[i + 1])
            draw_list:AddCircle(ImVec2(x, center_y + offset), 12.0, IM_COL32(255, 255, 255, 100), 0, 2.0)
        end

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end

    ApplyOpenAll()
    if imgui.TreeNode('2D Noise Movement') then
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(200.0, 200.0)
        local center = ImVec2(canvas_pos.x + canvas_size.x * 0.5, canvas_pos.y + canvas_size.y * 0.5)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size,
            IM_COL32(30, 30, 40, 255), 4.0)

        local offset = iam.SmoothNoiseVec2(imgui.GetID('smooth_2d'), ImVec2(state.amplitude, state.amplitude), state.frequency, dt)
        draw_list:AddCircleFilled(ImVec2(center.x + offset.x, center.y + offset.y), 15.0, IM_COL32(100, 200, 255, 255))

        draw_list:AddCircle(center, 3.0, IM_COL32(100, 100, 100, 150))

        imgui.Dummy(canvas_size)
        imgui.TreePop()
    end
end

-- ============================================================
-- STYLE INTERPOLATION DEMO
-- ============================================================

local style_interpolation_state = {
    styles_registered = false,
    style_compact = ImHashStr('style_compact'),
    style_spacious = ImHashStr('style_spacious'),
    style_rounded = ImHashStr('style_rounded'),

    from_style = 1,
    to_style = 3,
    style_names = { 'Compact Dark', 'Spacious Light', 'Rounded Colorful' },

    color_space_idx = 4,
    color_space_names = { 'sRGB', 'sRGB Linear', 'HSV', 'OKLAB', 'OKLCH' },
    color_space_values = { IamColorSpace.SRGB, IamColorSpace.SRGBLinear, IamColorSpace.HSV, IamColorSpace.OKLAB, IamColorSpace.OKLCH },

    blend_t = 0.0,
    animating = false,
    anim_dir = 1.0,

    check1 = true,
    check2 = false,
    check3 = true,
    radio_val = 0,
    slider_val = 0.5,
    int_val = 50,
    drag_val = 25.0,
    text_buf = 'Sample text',
    combo_val = 2,
}

local function ShowStyleInterpolationDemo()
    local state = style_interpolation_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Style interpolation smoothly transitions between different ImGui themes. ' ..
        'Colors, padding, spacing, and rounding are all blended. Colors use perceptually uniform color spaces.')

    if not state.styles_registered then
        -- Compact dark style - tight spacing, sharp corners, small padding
        local compact = imgui.StyleColorsDark():Copy()
        compact.WindowPadding = ImVec2(4, 4)
        compact.FramePadding = ImVec2(4, 2)
        compact.CellPadding = ImVec2(2, 2)
        compact.ItemSpacing = ImVec2(4, 2)
        compact.ItemInnerSpacing = ImVec2(2, 2)
        compact.IndentSpacing = 12.0
        compact.ScrollbarSize = 10.0
        compact.GrabMinSize = 8.0
        compact.WindowRounding = 0.0
        compact.ChildRounding = 0.0
        compact.FrameRounding = 0.0
        compact.PopupRounding = 0.0
        compact.ScrollbarRounding = 0.0
        compact.GrabRounding = 0.0
        compact.TabRounding = 0.0
        compact.WindowBorderSize = 1.0
        compact.ChildBorderSize = 1.0
        compact.FrameBorderSize = 0.0
        compact.Colors[ImGuiCol.WindowBg] = ImVec4(0.08, 0.08, 0.10, 1.0)
        compact.Colors[ImGuiCol.ChildBg] = ImVec4(0.06, 0.06, 0.08, 1.0)
        compact.Colors[ImGuiCol.Button] = ImVec4(0.25, 0.25, 0.28, 1.0)
        compact.Colors[ImGuiCol.ButtonHovered] = ImVec4(0.35, 0.35, 0.40, 1.0)
        compact.Colors[ImGuiCol.ButtonActive] = ImVec4(0.45, 0.45, 0.50, 1.0)
        compact.Colors[ImGuiCol.Header] = ImVec4(0.20, 0.20, 0.25, 1.0)
        compact.Colors[ImGuiCol.HeaderHovered] = ImVec4(0.30, 0.30, 0.35, 1.0)
        compact.Colors[ImGuiCol.HeaderActive] = ImVec4(0.40, 0.40, 0.45, 1.0)
        compact.Colors[ImGuiCol.FrameBg] = ImVec4(0.15, 0.15, 0.18, 1.0)
        compact.Colors[ImGuiCol.FrameBgHovered] = ImVec4(0.22, 0.22, 0.25, 1.0)
        compact.Colors[ImGuiCol.FrameBgActive] = ImVec4(0.28, 0.28, 0.32, 1.0)
        compact.Colors[ImGuiCol.SliderGrab] = ImVec4(0.50, 0.50, 0.55, 1.0)
        compact.Colors[ImGuiCol.SliderGrabActive] = ImVec4(0.65, 0.65, 0.70, 1.0)
        compact.Colors[ImGuiCol.CheckMark] = ImVec4(0.70, 0.70, 0.75, 1.0)
        compact.Colors[ImGuiCol.Separator] = ImVec4(0.30, 0.30, 0.35, 1.0)
        compact.Colors[ImGuiCol.Border] = ImVec4(0.25, 0.25, 0.30, 1.0)
        iam.StyleRegister(state.style_compact, compact)

        -- Spacious light style - generous spacing, subtle borders
        local spacious = imgui.StyleColorsLight():Copy()
        spacious.WindowPadding = ImVec2(16, 16)
        spacious.FramePadding = ImVec2(12, 6)
        spacious.CellPadding = ImVec2(8, 6)
        spacious.ItemSpacing = ImVec2(12, 8)
        spacious.ItemInnerSpacing = ImVec2(8, 6)
        spacious.IndentSpacing = 24.0
        spacious.ScrollbarSize = 16.0
        spacious.GrabMinSize = 14.0
        spacious.WindowRounding = 4.0
        spacious.ChildRounding = 4.0
        spacious.FrameRounding = 4.0
        spacious.PopupRounding = 4.0
        spacious.ScrollbarRounding = 4.0
        spacious.GrabRounding = 4.0
        spacious.TabRounding = 4.0
        spacious.WindowBorderSize = 0.0
        spacious.ChildBorderSize = 0.0
        spacious.FrameBorderSize = 1.0
        spacious.Colors[ImGuiCol.WindowBg] = ImVec4(0.96, 0.96, 0.98, 1.0)
        spacious.Colors[ImGuiCol.ChildBg] = ImVec4(1.00, 1.00, 1.00, 1.0)
        spacious.Colors[ImGuiCol.Button] = ImVec4(0.85, 0.85, 0.88, 1.0)
        spacious.Colors[ImGuiCol.ButtonHovered] = ImVec4(0.78, 0.78, 0.82, 1.0)
        spacious.Colors[ImGuiCol.ButtonActive] = ImVec4(0.70, 0.70, 0.75, 1.0)
        spacious.Colors[ImGuiCol.Header] = ImVec4(0.88, 0.88, 0.92, 1.0)
        spacious.Colors[ImGuiCol.HeaderHovered] = ImVec4(0.80, 0.80, 0.85, 1.0)
        spacious.Colors[ImGuiCol.HeaderActive] = ImVec4(0.72, 0.72, 0.78, 1.0)
        spacious.Colors[ImGuiCol.FrameBg] = ImVec4(1.00, 1.00, 1.00, 1.0)
        spacious.Colors[ImGuiCol.FrameBgHovered] = ImVec4(0.95, 0.95, 0.98, 1.0)
        spacious.Colors[ImGuiCol.FrameBgActive] = ImVec4(0.90, 0.90, 0.95, 1.0)
        spacious.Colors[ImGuiCol.SliderGrab] = ImVec4(0.55, 0.55, 0.60, 1.0)
        spacious.Colors[ImGuiCol.SliderGrabActive] = ImVec4(0.40, 0.40, 0.45, 1.0)
        spacious.Colors[ImGuiCol.CheckMark] = ImVec4(0.25, 0.25, 0.30, 1.0)
        spacious.Colors[ImGuiCol.Text] = ImVec4(0.15, 0.15, 0.20, 1.0)
        spacious.Colors[ImGuiCol.Separator] = ImVec4(0.80, 0.80, 0.85, 1.0)
        spacious.Colors[ImGuiCol.Border] = ImVec4(0.75, 0.75, 0.80, 1.0)
        iam.StyleRegister(state.style_spacious, spacious)

        -- Rounded colorful style - pill shapes, vibrant colors
        local rounded = imgui.StyleColorsDark():Copy()
        rounded.WindowPadding = ImVec2(12, 12)
        rounded.FramePadding = ImVec2(10, 5)
        rounded.CellPadding = ImVec2(6, 4)
        rounded.ItemSpacing = ImVec2(10, 6)
        rounded.ItemInnerSpacing = ImVec2(6, 4)
        rounded.IndentSpacing = 20.0
        rounded.ScrollbarSize = 14.0
        rounded.GrabMinSize = 12.0
        rounded.WindowRounding = 12.0
        rounded.ChildRounding = 12.0
        rounded.FrameRounding = 12.0
        rounded.PopupRounding = 12.0
        rounded.ScrollbarRounding = 12.0
        rounded.GrabRounding = 12.0
        rounded.TabRounding = 12.0
        rounded.WindowBorderSize = 0.0
        rounded.ChildBorderSize = 0.0
        rounded.FrameBorderSize = 0.0
        rounded.Colors[ImGuiCol.WindowBg] = ImVec4(0.12, 0.08, 0.18, 1.0)
        rounded.Colors[ImGuiCol.ChildBg] = ImVec4(0.15, 0.10, 0.22, 1.0)
        rounded.Colors[ImGuiCol.Button] = ImVec4(0.45, 0.25, 0.70, 1.0)
        rounded.Colors[ImGuiCol.ButtonHovered] = ImVec4(0.55, 0.35, 0.80, 1.0)
        rounded.Colors[ImGuiCol.ButtonActive] = ImVec4(0.65, 0.45, 0.90, 1.0)
        rounded.Colors[ImGuiCol.Header] = ImVec4(0.40, 0.22, 0.60, 1.0)
        rounded.Colors[ImGuiCol.HeaderHovered] = ImVec4(0.50, 0.30, 0.70, 1.0)
        rounded.Colors[ImGuiCol.HeaderActive] = ImVec4(0.60, 0.40, 0.80, 1.0)
        rounded.Colors[ImGuiCol.FrameBg] = ImVec4(0.20, 0.14, 0.30, 1.0)
        rounded.Colors[ImGuiCol.FrameBgHovered] = ImVec4(0.28, 0.20, 0.40, 1.0)
        rounded.Colors[ImGuiCol.FrameBgActive] = ImVec4(0.35, 0.25, 0.50, 1.0)
        rounded.Colors[ImGuiCol.SliderGrab] = ImVec4(0.70, 0.45, 0.95, 1.0)
        rounded.Colors[ImGuiCol.SliderGrabActive] = ImVec4(0.85, 0.60, 1.00, 1.0)
        rounded.Colors[ImGuiCol.CheckMark] = ImVec4(0.85, 0.55, 1.00, 1.0)
        rounded.Colors[ImGuiCol.Text] = ImVec4(0.95, 0.92, 1.00, 1.0)
        rounded.Colors[ImGuiCol.Separator] = ImVec4(0.50, 0.35, 0.70, 1.0)
        rounded.Colors[ImGuiCol.Border] = ImVec4(0.45, 0.30, 0.65, 1.0)
        iam.StyleRegister(state.style_rounded, rounded)

        state.styles_registered = true
    end

    -- Style selector
    local style_ids = { state.style_compact, state.style_spacious, state.style_rounded }
    state.from_style = imgui.Combo('From Style', state.from_style, state.style_names, #state.style_names)
    state.to_style = imgui.Combo('To Style', state.to_style, state.style_names, #state.style_names)

    -- Color space selector (matches iam_color_space enum order)
    state.color_space_idx = imgui.Combo('Color Space', state.color_space_idx, state.color_space_names, #state.color_space_names)
    local color_space = state.color_space_values[state.color_space_idx]

    -- Blend control
    if imgui.Button('Animate') then
        state.animating = true
    end
    imgui.SameLine()
    state.blend_t = imgui.SliderFloat('Blend', state.blend_t, 0.0, 1.0)

    if state.animating then
        state.blend_t = state.blend_t + dt * 0.5 * state.anim_dir
        if state.blend_t >= 1.0 then state.blend_t = 1.0; state.anim_dir = -1.0 end
        if state.blend_t <= 0.0 then state.blend_t = 0.0; state.anim_dir = 1.0; state.animating = false end
    end

    -- Apply blended style to a child region
    imgui.Separator()
    imgui.Text('Preview (blended style applied to child window):')

    -- Get blended style
    local blended = iam.StyleBlendTo(style_ids[state.from_style], style_ids[state.to_style], state.blend_t, color_space)

    -- Apply all style vars
    imgui.PushStyleVar(ImGuiStyleVar.WindowPadding, blended.WindowPadding)
    imgui.PushStyleVar(ImGuiStyleVar.FramePadding, blended.FramePadding)
    imgui.PushStyleVar(ImGuiStyleVar.CellPadding, blended.CellPadding)
    imgui.PushStyleVar(ImGuiStyleVar.ItemSpacing, blended.ItemSpacing)
    imgui.PushStyleVar(ImGuiStyleVar.ItemInnerSpacing, blended.ItemInnerSpacing)
    imgui.PushStyleVar(ImGuiStyleVar.IndentSpacing, blended.IndentSpacing)
    imgui.PushStyleVar(ImGuiStyleVar.ScrollbarSize, blended.ScrollbarSize)
    imgui.PushStyleVar(ImGuiStyleVar.GrabMinSize, blended.GrabMinSize)
    imgui.PushStyleVar(ImGuiStyleVar.ChildRounding, blended.ChildRounding)
    imgui.PushStyleVar(ImGuiStyleVar.FrameRounding, blended.FrameRounding)
    imgui.PushStyleVar(ImGuiStyleVar.ScrollbarRounding, blended.ScrollbarRounding)
    imgui.PushStyleVar(ImGuiStyleVar.GrabRounding, blended.GrabRounding)
    imgui.PushStyleVar(ImGuiStyleVar.ChildBorderSize, blended.ChildBorderSize)
    imgui.PushStyleVar(ImGuiStyleVar.FrameBorderSize, blended.FrameBorderSize)

    -- Apply all colors
    imgui.PushStyleColor(ImGuiCol.ChildBg, blended.Colors[ImGuiCol.ChildBg])
    imgui.PushStyleColor(ImGuiCol.Button, blended.Colors[ImGuiCol.Button])
    imgui.PushStyleColor(ImGuiCol.ButtonHovered, blended.Colors[ImGuiCol.ButtonHovered])
    imgui.PushStyleColor(ImGuiCol.ButtonActive, blended.Colors[ImGuiCol.ButtonActive])
    imgui.PushStyleColor(ImGuiCol.FrameBg, blended.Colors[ImGuiCol.FrameBg])
    imgui.PushStyleColor(ImGuiCol.FrameBgHovered, blended.Colors[ImGuiCol.FrameBgHovered])
    imgui.PushStyleColor(ImGuiCol.FrameBgActive, blended.Colors[ImGuiCol.FrameBgActive])
    imgui.PushStyleColor(ImGuiCol.Text, blended.Colors[ImGuiCol.Text])
    imgui.PushStyleColor(ImGuiCol.Header, blended.Colors[ImGuiCol.Header])
    imgui.PushStyleColor(ImGuiCol.HeaderHovered, blended.Colors[ImGuiCol.HeaderHovered])
    imgui.PushStyleColor(ImGuiCol.HeaderActive, blended.Colors[ImGuiCol.HeaderActive])
    imgui.PushStyleColor(ImGuiCol.SliderGrab, blended.Colors[ImGuiCol.SliderGrab])
    imgui.PushStyleColor(ImGuiCol.SliderGrabActive, blended.Colors[ImGuiCol.SliderGrabActive])
    imgui.PushStyleColor(ImGuiCol.CheckMark, blended.Colors[ImGuiCol.CheckMark])
    imgui.PushStyleColor(ImGuiCol.Separator, blended.Colors[ImGuiCol.Separator])
    imgui.PushStyleColor(ImGuiCol.Border, blended.Colors[ImGuiCol.Border])

    imgui.BeginChild('StylePreview', ImVec2(0, 280), ImGuiChildFlags.Borders)

    -- Row 1: Buttons
    imgui.Text('Buttons')
    imgui.Button('Primary')
    imgui.SameLine()
    imgui.Button('Secondary')
    imgui.SameLine()
    imgui.SmallButton('Small')

    imgui.Separator()

    -- Row 2: Checkboxes and Radio
    imgui.Text('Toggles')
    state.check1 = imgui.Checkbox('Option A', state.check1)
    imgui.SameLine()
    state.check2 = imgui.Checkbox('Option B', state.check2)
    imgui.SameLine()
    state.check3 = imgui.Checkbox('Option C', state.check3)

    state.radio_val = imgui.RadioButton('Choice 1', state.radio_val, 0)
    imgui.SameLine()
    state.radio_val = imgui.RadioButton('Choice 2', state.radio_val, 1)
    imgui.SameLine()
    state.radio_val = imgui.RadioButton('Choice 3', state.radio_val, 2)

    imgui.Separator()

    -- Row 3: Sliders and Drags
    imgui.Text('Sliders & Inputs')
    state.slider_val = imgui.SliderFloat('Float Slider', state.slider_val, 0.0, 1.0)
    state.int_val = imgui.SliderInt('Int Slider', state.int_val, 0, 100)
    state.drag_val = imgui.DragFloat('Drag Float', state.drag_val, 0.5, 0.0, 100.0)

    imgui.Separator()

    -- Row 4: Text input and Combo
    imgui.Text('Text & Selection')
    state.text_buf = imgui.InputText('Text Input', state.text_buf)
    state.combo_val = imgui.Combo('Combo Box', state.combo_val, { 'Item A', 'Item B', 'Item C', 'Item D' }, 4)

    imgui.Separator()

    -- Row 5: Collapsing header
    if imgui.CollapsingHeader('Collapsible Section') then
        imgui.Text('Content inside collapsing header')
        imgui.BulletText('Bullet point 1')
        imgui.BulletText('Bullet point 2')
    end

    imgui.EndChild()

    imgui.PopStyleColor(16)
    imgui.PopStyleVar(14)

    -- Show current interpolated values
    ApplyOpenAll()
    if imgui.TreeNode('Interpolated Values') then
        imgui.Text('Rounding: Frame=%.1f, Child=%.1f, Grab=%.1f',
            blended.FrameRounding, blended.ChildRounding, blended.GrabRounding)
        imgui.Text('Padding: Frame=(%.0f,%.0f), Item=(%.0f,%.0f)',
            blended.FramePadding.x, blended.FramePadding.y,
            blended.ItemSpacing.x, blended.ItemSpacing.y)
        imgui.Text('Borders: Frame=%.0f, Child=%.0f',
            blended.FrameBorderSize, blended.ChildBorderSize)
        imgui.TreePop()
    end
end

-- ============================================================
-- DRAG FEEDBACK DEMO
-- ============================================================
local drag_state = {
    drag_pos = ImVec2(100, 60),
    dragging = false,
    grid_size = 50.0,
    snap_duration = 0.3,
    overshoot = 0.5,
    drag_pos2 = ImVec2(150, 100),
    dragging2 = false,

    ease_idx = 1,
    ease_names = { 'Out Cubic', 'Out Back', 'Out Elastic', 'Out Bounce' },
    ease_values = { IamEaseType.OutCubic, IamEaseType.OutBack, IamEaseType.OutElastic, IamEaseType.OutBounce },

    snap_points = {
        ImVec2(50, 50),  ImVec2(150, 50),  ImVec2(250, 50),
        ImVec2(50, 150), ImVec2(150, 150), ImVec2(250, 150),
        ImVec2(50, 250), ImVec2(150, 250), ImVec2(250, 250),
    },
}

local function ShowDragFeedbackDemo()
    local state = drag_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Drag feedback provides animated visual response during drag operations. ' ..
        'Features include grid snapping, snap points, overshoot, and velocity tracking.')

    imgui.Spacing()

    -- Snap grid demo
    ApplyOpenAll()
    if imgui.TreeNode('Grid Snapping') then
        state.grid_size = imgui.SliderFloat('Grid Size', state.grid_size, 20.0, 100.0)
        state.snap_duration = imgui.SliderFloat('Snap Duration', state.snap_duration, 0.1, 0.8)
        state.overshoot = imgui.SliderFloat('Overshoot', state.overshoot, 0.0, 2.0)
        state.ease_idx = imgui.Combo('Easing', state.ease_idx, state.ease_names, #state.ease_names)
        local ease_type = state.ease_values[state.ease_idx]

        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300.0, 200.0)
        local draw_list = imgui.GetWindowDrawList()

        -- Background
        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255), 4.0)

        -- Draw grid
        for x = 0, canvas_size.x, state.grid_size do
            draw_list:AddLine(ImVec2(canvas_pos.x + x, canvas_pos.y),
                ImVec2(canvas_pos.x + x, canvas_pos.y + canvas_size.y),
                IM_COL32(60, 60, 70, 150))
        end
        for y = 0, canvas_size.y, state.grid_size do
            draw_list:AddLine(ImVec2(canvas_pos.x, canvas_pos.y + y),
                ImVec2(canvas_pos.x + canvas_size.x, canvas_pos.y + y),
                IM_COL32(60, 60, 70, 150))
        end

        -- Handle dragging
        imgui.InvisibleButton('drag_canvas', canvas_size)
        local drag_id = imgui.GetID('grid_drag')

        if imgui.IsItemActive() and imgui.IsMouseDragging(0) then
            local mouse_pos = imgui.GetMousePosVec()
            local relative_pos = mouse_pos - canvas_pos

            if not state.dragging then
                iam.DragBegin(drag_id, relative_pos)
                state.dragging = true
            end
            local feedback = iam.DragUpdate(drag_id, relative_pos, dt)
            state.drag_pos = feedback.position
        elseif state.dragging then
            local opts = IamDragOpts()
            opts.snap_grid = ImVec2(state.grid_size, state.grid_size)
            opts.snap_duration = state.snap_duration
            opts.overshoot = state.overshoot
            opts.ease_type = ease_type

            local feedback = iam.DragRelease(drag_id, state.drag_pos, opts, dt)
            state.drag_pos = feedback.position

            if not feedback.is_snapping then
                state.dragging = false
            end
        else
            -- Continue snapping animation if active
            local opts = IamDragOpts()
            opts.snap_grid = ImVec2(state.grid_size, state.grid_size)
            opts.snap_duration = state.snap_duration
            opts.overshoot = state.overshoot
            opts.ease_type = ease_type

            local feedback = iam.DragRelease(drag_id, state.drag_pos, opts, dt)
            state.drag_pos = feedback.position
        end

        -- Draw draggable object
        local obj_pos = canvas_pos + state.drag_pos
        local obj_color = state.dragging and IM_COL32(255, 200, 100, 255) or IM_COL32(100, 200, 255, 255)
        draw_list:AddCircleFilled(obj_pos, 15.0, obj_color)
        draw_list:AddCircle(obj_pos, 15.0, IM_COL32(255, 255, 255, 150), 0, 2.0)

        imgui.TextDisabled('Drag the circle and release to see it snap to grid')

        imgui.TreePop()
    end

    -- Snap points demo
    ApplyOpenAll()
    if imgui.TreeNode('Snap Points') then
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300.0, 300.0)
        local draw_list = imgui.GetWindowDrawList()

        draw_list:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255), 4.0)

        -- Draw snap points
        for _, snap_point in ipairs(state.snap_points) do
            local pt = canvas_pos + snap_point
            draw_list:AddCircleFilled(pt, 6.0, IM_COL32(80, 80, 100, 255))
            draw_list:AddCircle(pt, 6.0, IM_COL32(120, 120, 140, 255))
        end

        -- Handle dragging
        imgui.InvisibleButton('snap_canvas', canvas_size)
        local drag_id = imgui.GetID('points_drag')

        if imgui.IsItemActive() and imgui.IsMouseDragging(0) then
            local relative_pos = imgui.GetMousePosVec() - canvas_pos

            if not state.dragging2 then
                iam.DragBegin(drag_id, relative_pos)
                state.dragging2 = true
            end
            local feedback = iam.DragUpdate(drag_id, relative_pos, dt)
            state.drag_pos2 = feedback.position
        elseif state.dragging2 then
            local opts = IamDragOpts()
            opts.snap_points = state.snap_points
            opts.snap_duration = 0.25
            opts.overshoot = 0.3
            opts.ease_type = IamEaseType.OutBack

            local feedback = iam.DragRelease(drag_id, state.drag_pos2, opts, dt)
            state.drag_pos2 = feedback.position

            if not feedback.is_snapping then
                state.dragging2 = false
            end
        else
            local opts = IamDragOpts()
            opts.snap_points = state.snap_points
            opts.snap_duration = 0.25
            opts.overshoot = 0.3
            opts.ease_type = IamEaseType.OutBack

            local feedback = iam.DragRelease(drag_id, state.drag_pos2, opts, dt)
            state.drag_pos2 = feedback.position
        end

        -- Draw draggable object
        local obj_pos = canvas_pos + state.drag_pos2
        local obj_color = state.dragging2 and IM_COL32(255, 200, 100, 255) or IM_COL32(200, 100, 255, 255)
        draw_list:AddCircleFilled(obj_pos, 12.0, obj_color)

        imgui.TextDisabled('Drag to snap to nearest point')

        imgui.TreePop()
    end
end

-- ============================================================
-- GRADIENT KEYFRAMES DEMO
-- ============================================================
local gradient_state = {
    blend = 0.5,
    -- Create two gradients
    grad_a = IamGradient()
        :Add(0.0, ImVec4(1.0, 0.0, 0.0, 1.0))   -- Red
        :Add(0.5, ImVec4(1.0, 1.0, 0.0, 1.0))   -- Yellow
        :Add(1.0, ImVec4(0.0, 1.0, 0.0, 1.0)),  -- Green

    grad_b = IamGradient()
        :Add(0.0, ImVec4(0.0, 0.5, 1.0, 1.0))   -- Blue
        :Add(0.5, ImVec4(0.5, 0.0, 1.0, 1.0))   -- Purple
        :Add(1.0, ImVec4(1.0, 0.0, 0.5, 1.0)),  -- Pink

    gradient_names = { 'Sunset', 'Ocean', 'Forest', 'Neon' },
    target_idx = 1,
    -- Define gradient presets
    presets = {
        -- Sunset
        IamGradient()
            :Add(0.0, ImVec4(1.0, 0.3, 0.0, 1.0))
            :Add(0.5, ImVec4(1.0, 0.6, 0.2, 1.0))
            :Add(1.0, ImVec4(0.4, 0.1, 0.3, 1.0)),
        -- Ocean
        IamGradient()
            :Add(0.0, ImVec4(0.0, 0.3, 0.6, 1.0))
            :Add(0.5, ImVec4(0.0, 0.6, 0.8, 1.0))
            :Add(1.0, ImVec4(0.0, 0.9, 0.9, 1.0)),
        -- Forest
        IamGradient()
            :Add(0.0, ImVec4(0.1, 0.3, 0.1, 1.0))
            :Add(0.5, ImVec4(0.2, 0.6, 0.2, 1.0))
            :Add(1.0, ImVec4(0.5, 0.8, 0.3, 1.0)),
        -- Neon
        IamGradient()
            :Add(0.0, ImVec4(1.0, 0.0, 1.0, 1.0))
            :Add(0.33, ImVec4(0.0, 1.0, 1.0, 1.0))
            :Add(0.66, ImVec4(1.0, 1.0, 0.0, 1.0))
            :Add(1.0, ImVec4(1.0, 0.0, 1.0, 1.0))
    },

    health = 0.75,
    -- Gradient from red (low) to yellow (mid) to green (high)
    health_gradient = IamGradient()
        :Add(0.0,  ImVec4(0.8, 0.1, 0.1, 1.0))  -- Red (critical)
        :Add(0.25, ImVec4(0.9, 0.4, 0.1, 1.0))  -- Orange (low)
        :Add(0.5,  ImVec4(0.9, 0.9, 0.2, 1.0))  -- Yellow (medium)
        :Add(0.75, ImVec4(0.4, 0.8, 0.3, 1.0))  -- Light green
        :Add(1.0,  ImVec4(0.2, 0.7, 0.2, 1.0)), -- Green (full)
}

local function ShowGradientKeyframesDemo()
    local state = gradient_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Gradient keyframes allow you to interpolate between multi-stop color gradients, ' ..
        'not just single colors. Great for animated backgrounds, health bars, and color themes.')

    -- Demo 1: Basic gradient interpolation
    ApplyOpenAll()
    if imgui.TreeNode('Basic Gradient Interpolation') then
        state.blend = imgui.SliderFloat('Blend##GradientBasic', state.blend, 0.0, 1.0)

        local result = iam.GradientLerp(state.grad_a, state.grad_b, state.blend)

        -- Draw gradient bar
        local bar_pos = imgui.GetCursorScreenPosVec()
        local bar_size = ImVec2(300.0, 30.0)
        local draw = imgui.GetWindowDrawList()

        local segs = 50
        for i = 1, segs do
            local t0 = (i - 1) / segs
            local t1 = i / segs
            local c0 = result:Sample(t0)
            local c1 = result:Sample(t1)
            local col0 = imgui.ColorConvertFloat4ToU32(c0)
            local col1 = imgui.ColorConvertFloat4ToU32(c1)
            draw:AddRectFilledMultiColor(
                ImVec2(bar_pos.x + t0 * bar_size.x, bar_pos.y),
                ImVec2(bar_pos.x + t1 * bar_size.x, bar_pos.y + bar_size.y),
                col0, col1, col1, col0)
        end
        imgui.Dummy(bar_size)

        imgui.TextDisabled('Top gradient: Red -> Yellow -> Green')
        imgui.TextDisabled('Bottom gradient: Blue -> Purple -> Pink')
        imgui.TreePop()
    end

    -- Demo 2: Animated gradient tween
    ApplyOpenAll()
    if imgui.TreeNode('Animated Gradient Tween') then

        for i = 1, 4 do
            if imgui.RadioButton(state.gradient_names[i], state.target_idx == i) then
                state.target_idx = i
            end
            if i < 4 then imgui.SameLine() end
        end

        local current = iam.TweenGradient(
            imgui.GetID('gradient_tween'),
            imgui.GetID('ch_gradient'),
            state.presets[state.target_idx],
            0.8,
            iam.EasePreset(IamEaseType.OutCubic),
            IamPolicy.Crossfade,
            IamColorSpace.OKLAB,
            dt
        )

        -- Draw animated gradient bar
        local bar_pos = imgui.GetCursorScreenPosVec()
        local bar_size = ImVec2(300.0, 40.0)
        local draw = imgui.GetWindowDrawList()

        local segs = 60
        for i = 1, segs do
            local t0 = (i - 1) / segs
            local t1 = i / segs
            local c0 = current:Sample(t0)
            local c1 = current:Sample(t1)
            local col0 = imgui.ColorConvertFloat4ToU32(c0)
            local col1 = imgui.ColorConvertFloat4ToU32(c1)
            draw:AddRectFilledMultiColor(
                ImVec2(bar_pos.x + t0 * bar_size.x, bar_pos.y),
                ImVec2(bar_pos.x + t1 * bar_size.x, bar_pos.y + bar_size.y),
                col0, col1, col1, col0)
        end
        imgui.Dummy(bar_size)

        imgui.TextDisabled('Click presets to see smooth gradient transitions.')
        imgui.TreePop()
    end

    -- Demo 3: Health bar with gradient
    ApplyOpenAll()
    if imgui.TreeNode('Health Bar with Gradient') then
        state.health = imgui.SliderFloat('Health', state.health, 0.0, 1.0)

        -- Draw health bar
        local bar_pos = imgui.GetCursorScreenPosVec()
        local bar_size = ImVec2(250.0, 25.0)
        local draw = imgui.GetWindowDrawList()

        draw:AddRectFilled(bar_pos, bar_pos + bar_size, IM_COL32(40, 40, 40, 255), 4.0)

        -- Filled portion with gradient
        local segs = 30
        local fill_width = bar_size.x * state.health
        for i = 1, segs do
            local t0 = (i - 1) / segs
            local t1 = i / segs
            if t1 * bar_size.x > fill_width then break end

            local sample_t = t0 * state.health  -- Sample gradient based on fill position
            local col = state.health_gradient:Sample(sample_t + (1.0 - state.health) * 0.5)
            local c = imgui.ColorConvertFloat4ToU32(col)
            draw:AddRectFilled(
                ImVec2(bar_pos.x + t0 * bar_size.x, bar_pos.y),
                ImVec2(bar_pos.x + math.min(t1 * bar_size.x, fill_width), bar_pos.y + bar_size.y),
                c, 4.0)
        end

        -- Border
        draw:AddRect(bar_pos, bar_pos + bar_size,
            IM_COL32(100, 100, 100, 255), 4.0)

        imgui.Dummy(bar_size)
        imgui.TextDisabled('Health bar color changes based on value.')
        imgui.TreePop()
    end
end

-- ============================================================
-- TRANSFORM INTERPOLATION DEMO
-- ============================================================
local transform_state = {
    blend = 0.5,
    t_a = IamTransform(ImVec2(50.0, 50.0), 0.0, ImVec2(1.0, 1.0)),
    t_b = IamTransform(ImVec2(200.0, 80.0), 1.57, ImVec2(1.5, 0.5)),

    pose_names = { 'Center', 'Top-Left', 'Bottom-Right', 'Spinning' },
    pose_idx = 1,
    poses = {
        -- Center (default)
        IamTransform(ImVec2(150.0, 75.0), 0.0, ImVec2(1.0, 1.0)),
        -- Top-left
        IamTransform(ImVec2(50.0, 30.0), -0.3, ImVec2(0.7, 0.7)),
        -- Bottom-right
        IamTransform(ImVec2(250.0, 120.0), 0.5, ImVec2(1.3, 1.3)),
        -- Spinning (rotated 180 degrees)
        IamTransform(ImVec2(150.0, 75.0), 3.14159, ImVec2(1.0, 1.0)),
    },

    rotation_mode = 0,
    target_angle = 0.0,
    time = 0.0,
}

local function ShowTransformInterpolationDemo()
    local state = transform_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Transform interpolation allows you to blend 2D transforms (position, rotation, scale) ' ..
        'with proper shortest-path rotation. Great for UI elements, sprites, and complex animations.')

    -- Demo 1: Basic transform interpolation
    ApplyOpenAll()
    if imgui.TreeNode('Basic Transform Blend') then
        state.blend = imgui.SliderFloat('Blend##TransformBasic', state.blend, 0.0, 1.0)

        local result = iam.TransformLerp(state.t_a, state.t_b, state.blend)

        -- Draw canvas
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300.0, 150.0)
        local draw = imgui.GetWindowDrawList()

        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))

        -- Draw transformed rectangle
        local hw = 30.0 * result.scale.x
        local hh = 20.0 * result.scale.y
        local cos_r = math.cos(result.rotation)
        local sin_r = math.sin(result.rotation)

        local center = canvas_pos + result.position
        local corners = {
            ImVec2(-hw, -hh), ImVec2(hw, -hh), ImVec2(hw, hh), ImVec2(-hw, hh)
        }

        local transformed = {
            ImVec2(center.x + corners[1].x * cos_r - corners[1].y * sin_r, center.y + corners[1].x * sin_r + corners[1].y * cos_r),
            ImVec2(center.x + corners[2].x * cos_r - corners[2].y * sin_r, center.y + corners[2].x * sin_r + corners[2].y * cos_r),
            ImVec2(center.x + corners[3].x * cos_r - corners[3].y * sin_r, center.y + corners[3].x * sin_r + corners[3].y * cos_r),
            ImVec2(center.x + corners[4].x * cos_r - corners[4].y * sin_r, center.y + corners[4].x * sin_r + corners[4].y * cos_r),
        }

        draw:AddQuadFilled(transformed[1], transformed[2], transformed[3], transformed[4],
            IM_COL32(100, 150, 255, 200))
        draw:AddQuad(transformed[1], transformed[2], transformed[3], transformed[4],
            IM_COL32(150, 200, 255, 255), 2.0)

        imgui.Dummy(canvas_size)
        imgui.TextDisabled('Blending position, rotation (90 deg), and non-uniform scale.')
        imgui.TreePop()
    end

    -- Demo 2: Animated transform tween
    ApplyOpenAll()
    if imgui.TreeNode('Animated Transform Tween') then
        for i = 1, 4 do
            if imgui.RadioButton(state.pose_names[i], state.pose_idx == i) then
                state.pose_idx = i
            end
            if i < 4 then imgui.SameLine() end
        end

        local current = iam.TweenTransform(
            imgui.GetID('transform_tween'),
            imgui.GetID('ch_transform'),
            state.poses[state.pose_idx],
            0.6,
            iam.EasePreset(IamEaseType.OutBack),
            IamPolicy.Crossfade,
            IamRotationMode.Shortest,
            dt
        )

        -- Draw canvas
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300.0, 150.0)
        local draw = imgui.GetWindowDrawList()

        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))

        -- Draw animated rectangle
        local hw = 25.0 * current.scale.x
        local hh = 25.0 * current.scale.y
        local cos_r = math.cos(current.rotation)
        local sin_r = math.sin(current.rotation)

        local center = canvas_pos + current.position
        local corners = {
            ImVec2(-hw, -hh), ImVec2(hw, -hh), ImVec2(hw, hh), ImVec2(-hw, hh)
        }
        local transformed = {
            ImVec2(center.x + corners[1].x * cos_r - corners[1].y * sin_r, center.y + corners[1].x * sin_r + corners[1].y * cos_r),
            ImVec2(center.x + corners[2].x * cos_r - corners[2].y * sin_r, center.y + corners[2].x * sin_r + corners[2].y * cos_r),
            ImVec2(center.x + corners[3].x * cos_r - corners[3].y * sin_r, center.y + corners[3].x * sin_r + corners[3].y * cos_r),
            ImVec2(center.x + corners[4].x * cos_r - corners[4].y * sin_r, center.y + corners[4].x * sin_r + corners[4].y * cos_r),
        }

        draw:AddQuadFilled(transformed[1], transformed[2], transformed[3], transformed[4],
            IM_COL32(255, 150, 100, 200))
        draw:AddQuad(transformed[1], transformed[2], transformed[3], transformed[4],
            IM_COL32(255, 200, 150, 255), 2.0)

        -- Draw direction indicator
        local arrow_end = ImVec2(center.x + 20.0 * cos_r, center.y + 20.0 * sin_r)
        draw:AddLine(center, arrow_end, IM_COL32(255, 255, 255, 255), 2.0)

        imgui.Dummy(canvas_size)
        imgui.TextDisabled('Uses IamRotationMode.Shortest (default).')
        imgui.TreePop()
    end

    -- Demo 3: Rotation Modes
    ApplyOpenAll()
    if imgui.TreeNode('Rotation Modes') then
        imgui.Text('Rotation Mode:')
        state.rotation_mode = imgui.RadioButton('Shortest##RotMode', state.rotation_mode, IamRotationMode.Shortest)
        imgui.SameLine()
        state.rotation_mode = imgui.RadioButton('Longest##RotMode', state.rotation_mode, IamRotationMode.Longest)
        imgui.SameLine()
        state.rotation_mode = imgui.RadioButton('Clockwise##RotMode', state.rotation_mode, IamRotationMode.CW)
        state.rotation_mode = imgui.RadioButton('Counter-CW##RotMode', state.rotation_mode, IamRotationMode.CCW)
        imgui.SameLine()
        state.rotation_mode = imgui.RadioButton('Direct##RotMode', state.rotation_mode, IamRotationMode.Direct)

        imgui.Separator()
        imgui.Text('Target Angle:')
        if imgui.Button('0 deg') then state.target_angle = 0.0 end
        imgui.SameLine()
        if imgui.Button('90 deg') then state.target_angle = 1.5708 end
        imgui.SameLine()
        if imgui.Button('180 deg') then state.target_angle = 3.14159 end
        imgui.SameLine()
        if imgui.Button('270 deg') then state.target_angle = 4.7124 end
        imgui.SameLine()
        if imgui.Button('360 deg') then state.target_angle = 6.28318 end

        local target = IamTransform(ImVec2(150.0, 75.0), state.target_angle, ImVec2(1.0, 1.0))
        local current = iam.TweenTransform(
            imgui.GetID('rotation_mode_demo'),
            imgui.GetID('ch_rot_mode'),
            target,
            1.0,
            iam.EasePreset(IamEaseType.OutCubic),
            IamPolicy.Crossfade,
            state.rotation_mode,
            dt
        )

        -- Draw canvas
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300.0, 150.0)
        local draw = imgui.GetWindowDrawList()

        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))

        -- Draw animated rectangle
        local hw = 40.0
        local hh = 25.0
        local cos_r = math.cos(current.rotation)
        local sin_r = math.sin(current.rotation)

        local center = canvas_pos + current.position
        local corners = {
            ImVec2(-hw, -hh), ImVec2(hw, -hh), ImVec2(hw, hh), ImVec2(-hw, hh)
        }
        local transformed = {
            ImVec2(center.x + corners[1].x * cos_r - corners[1].y * sin_r, center.y + corners[1].x * sin_r + corners[1].y * cos_r),
            ImVec2(center.x + corners[2].x * cos_r - corners[2].y * sin_r, center.y + corners[2].x * sin_r + corners[2].y * cos_r),
            ImVec2(center.x + corners[3].x * cos_r - corners[3].y * sin_r, center.y + corners[3].x * sin_r + corners[3].y * cos_r),
            ImVec2(center.x + corners[4].x * cos_r - corners[4].y * sin_r, center.y + corners[4].x * sin_r + corners[4].y * cos_r),
        }

        draw:AddQuadFilled(transformed[1], transformed[2], transformed[3], transformed[4],
            IM_COL32(100, 200, 150, 200))
        draw:AddQuad(transformed[1], transformed[2], transformed[3], transformed[4],
            IM_COL32(150, 255, 200, 255), 2.0)

        -- Draw direction indicator
        local arrow_end = ImVec2(center.x + 30.0 * cos_r, center.y + 30.0 * sin_r)
        draw:AddLine(center, arrow_end, IM_COL32(255, 255, 255, 255), 2.0)
        draw:AddCircleFilled(arrow_end, 4.0, IM_COL32(255, 255, 255, 255))

        imgui.Dummy(canvas_size)

        -- Display current angle
        local deg = current.rotation * 57.2958
        imgui.Text('Current: %.1f deg (%.2f rad)', deg, current.rotation)

        imgui.TextDisabled('Shortest: takes the short way (<180 deg)')
        imgui.TextDisabled('Longest: takes the long way (>180 deg)')
        imgui.TextDisabled('CW/CCW: always rotates in one direction')
        imgui.TextDisabled('Direct: raw lerp (can spin multiple times)')
        imgui.TreePop()
    end

    -- Demo 3: Transform composition
    ApplyOpenAll()
    if imgui.TreeNode('Transform Composition') then
        state.time = state.time + dt

        -- Parent transform (orbiting)
        local parent = IamTransform(
            ImVec2(150.0, 75.0),
            state.time * 0.5,
            ImVec2(1.0, 1.0))

        -- Child transform (relative to parent)
        local child = IamTransform(
            ImVec2(50.0, 0.0),  -- Offset from parent
            state.time * 2.0,   -- Spinning faster
            ImVec2(0.5, 0.5))

        -- Compose transforms
        local composed = parent * child

        -- Draw canvas
        local canvas_pos = imgui.GetCursorScreenPosVec()
        local canvas_size = ImVec2(300.0, 150.0)
        local draw = imgui.GetWindowDrawList()

        draw:AddRectFilled(canvas_pos, canvas_pos + canvas_size, IM_COL32(30, 30, 40, 255))

        -- Draw parent (larger square)
        do
            local hw = 20.0
            local hh = 20.0
            local cos_r = math.cos(parent.rotation)
            local sin_r = math.sin(parent.rotation)
            local center = canvas_pos + parent.position
            local corners = {
                ImVec2(-hw, -hh), ImVec2(hw, -hh), ImVec2(hw, hh), ImVec2(-hw, hh)
            }

            local transformed = {
                ImVec2(center.x + corners[1].x * cos_r - corners[1].y * sin_r, center.y + corners[1].x * sin_r + corners[1].y * cos_r),
                ImVec2(center.x + corners[2].x * cos_r - corners[2].y * sin_r, center.y + corners[2].x * sin_r + corners[2].y * cos_r),
                ImVec2(center.x + corners[3].x * cos_r - corners[3].y * sin_r, center.y + corners[3].x * sin_r + corners[3].y * cos_r),
                ImVec2(center.x + corners[4].x * cos_r - corners[4].y * sin_r, center.y + corners[4].x * sin_r + corners[4].y * cos_r),
            }
            draw:AddQuadFilled(transformed[1], transformed[2], transformed[3], transformed[4], 
                IM_COL32(100, 100, 200, 150))
        end

        -- Draw child (smaller square, orbiting)
        do
            local hw = 10.0 * composed.scale.x
            local hh = 10.0 * composed.scale.y
            local cos_r = math.cos(composed.rotation)
            local sin_r = math.sin(composed.rotation)
            local center = canvas_pos + composed.position
            local corners = {
                ImVec2(-hw, -hh), ImVec2(hw, -hh), ImVec2(hw, hh), ImVec2(-hw, hh)
            }

            local transformed = {
                ImVec2(center.x + corners[1].x * cos_r - corners[1].y * sin_r, center.y + corners[1].x * sin_r + corners[1].y * cos_r),
                ImVec2(center.x + corners[2].x * cos_r - corners[2].y * sin_r, center.y + corners[2].x * sin_r + corners[2].y * cos_r),
                ImVec2(center.x + corners[3].x * cos_r - corners[3].y * sin_r, center.y + corners[3].x * sin_r + corners[3].y * cos_r),
                ImVec2(center.x + corners[4].x * cos_r - corners[4].y * sin_r, center.y + corners[4].x * sin_r + corners[4].y * cos_r),
            }
            draw:AddQuadFilled(transformed[1], transformed[2], transformed[3], transformed[4],
                IM_COL32(255, 200, 100, 200))
        end

        -- Draw connection line
        local parent_center = canvas_pos + parent.position
        local child_center = canvas_pos + composed.position        
        draw:AddLine(parent_center, child_center, IM_COL32(150, 150, 150, 150), 1.0)

        imgui.Dummy(canvas_size)
        imgui.TextDisabled('Blue = parent, Orange = child (orbiting with own spin).')
        imgui.TreePop()
    end
end

-- ============================================================
-- ANIMATION INSPECTOR DEMO
-- ============================================================

local function ShowAnimationInspectorDemo()
	imgui.TextWrapped("The Unified Inspector provides a complete debug view of all active animations. " ..
		"Use the 'Show Debug Window' checkbox at the top of this demo to open it.")

	imgui.Separator()
	imgui.Text("Inspector Tabs:")
	imgui.BulletText("Stats - Time scale, tween counts, clip stats, custom easing slots")
	imgui.BulletText("Clips - Active instances with playback controls and scrubbing")
	imgui.BulletText("Paths - Registered motion paths with segment info")
	imgui.BulletText("Noise - Active noise channels with interactive preview")
	imgui.BulletText("Styles - Registered styles and active style tweens")
	imgui.BulletText("Performance - Profiler with per-section timing breakdown")

	imgui.Separator()
	imgui.TextDisabled("Tip: Use iam.ProfilerBegin/End() to instrument your code.")
end

-- ============================================================
-- SECTION: Stress Test
-- ============================================================
local stress_test_state = {
    anim_count = 1000,
    running = false,
    test_time = 0.0,
    ms_history = (function() local t = {} for i = 1, 120 do t[i] = 0.0 end return t end)(),
    ms_idx = 1,
    min_ms = 0.0,
    max_ms = 0.0,
    avg_ms = 0.0,
    stagger_amount = 0.02,
    anim_duration = 0.8,
    item_size = 24.0,
    items_per_row = 40,
    float_values = {},
    vec2_values = {},
    vec4_values = {},

    test_mode = 1,
    mode_names = { 'Float Tweens', 'Vec2 Tweens', 'Vec4 Tweens', 'Color Tweens', 'Mixed' },

    -- Stagger and animation parameters (outside running block so they persist)
    ease_idx = 1,
    ease_names = { 'Out Cubic', 'Out Elastic', 'Out Bounce', 'Out Back', 'In Out Quad' },
    ease_values = { IamEaseType.OutCubic, IamEaseType.OutElastic, IamEaseType.OutBounce, IamEaseType.OutBack, IamEaseType.InOutQuad },
}

local function ShowStressTestDemo()
    local state = stress_test_state
    local dt = GetSafeDeltaTime()

    imgui.TextWrapped('Stress test the animation system with thousands of concurrent animations. ' ..
        'Monitor ms/frame to measure performance impact.')

    imgui.Separator()

    -- Configuration
    imgui.Text('Configuration:')
    state.anim_count = imgui.SliderInt('Animation Count', state.anim_count, 100, 100000, '%d', ImGuiSliderFlags.Logarithmic)
    state.test_mode = imgui.Combo('Test Mode', state.test_mode, state.mode_names, #state.mode_names)

    imgui.Separator()

    -- Controls
    if not state.running then
        if imgui.Button('Start Test', 120, 0) then
            state.running = true
            state.test_time = 0.0
            state.min_ms = 999.0
            state.max_ms = 0.0
            state.avg_ms = 0.0
            for i = 1, 120 do state.ms_history[i] = 0.0 end
            state.ms_idx = 0
        end
    else
        if imgui.Button('Stop Test', 120, 0) then
            state.running = false
        end
    end
    imgui.SameLine()
    if imgui.Button('Reset Stats', 120, 0) then
        state.min_ms = 999.0
        state.max_ms = 0.0
        state.avg_ms = 0.0
        for i = 1, 120 do state.ms_history[i] = 0.0 end
        state.ms_idx = 0
    end

    imgui.Separator()

    -- Performance display
    local frame_ms = dt * 1000.0

    if state.running then
        state.test_time = state.test_time + dt
        state.ms_history[state.ms_idx + 1] = frame_ms
        state.ms_idx = (state.ms_idx + 1) % 120

        if frame_ms < state.min_ms and frame_ms > 0.0 then state.min_ms = frame_ms end
        if frame_ms > state.max_ms then state.max_ms = frame_ms end

        -- Calculate average
        local sum = 0.0
        local count = 0
        for i = 1, 120 do
            if state.ms_history[i] > 0.0 then
                sum = sum + state.ms_history[i]
                count = count + 1
            end
        end
        if count > 0 then state.avg_ms = sum / count end
    end

    -- Stats display
    imgui.Text('Performance (ms/frame - lower is better):')
    imgui.Columns(4, 'perf_cols', false)
    imgui.Text('Current') imgui.NextColumn()
    imgui.Text('Min') imgui.NextColumn()
    imgui.Text('Max') imgui.NextColumn()
    imgui.Text('Avg') imgui.NextColumn()

    -- Color code based on ms (lower is better: <16.67ms = 60fps, <33.33ms = 30fps)
    local ms_color
    if frame_ms <= 16.67 then
        ms_color = ImVec4(0.2, 1.0, 0.2, 1.0)
    elseif frame_ms <= 33.33 then
        ms_color = ImVec4(1.0, 1.0, 0.2, 1.0)
    else
        ms_color = ImVec4(1.0, 0.2, 0.2, 1.0)
    end

    imgui.TextColored(ms_color, '%.2f ms', frame_ms) imgui.NextColumn()
    imgui.Text('%.2f ms', state.min_ms < 999.0 and state.min_ms or 0.0) imgui.NextColumn()
    imgui.Text('%.2f ms', state.max_ms) imgui.NextColumn()
    imgui.Text('%.2f ms', state.avg_ms) imgui.NextColumn()
    imgui.Columns(1)

    imgui.Text('Test time: %.1f s', state.test_time)
    if state.running then
        imgui.Text('Animations: %d | us/anim: %.2f', state.anim_count, (frame_ms * 1000.0) / state.anim_count)
    end

    -- ms/frame Graph
    imgui.PlotLines('##ms_graph', state.ms_history, 120, state.ms_idx, 'ms/frame History',
        0.0, 50.0, ImVec2(imgui.GetContentRegionAvailVec().x, 60))

    imgui.Separator()

    -- Run the stress test
    if state.running then
        imgui.Text('Running %d %s...', state.anim_count, state.mode_names[state.test_mode])

        state.stagger_amount = imgui.SliderFloat('Stagger Delay', state.stagger_amount, 0.001, 0.1, '%.3f s')
        state.anim_duration = imgui.SliderFloat('Anim Duration', state.anim_duration, 0.1, 2.0, '%.2f s')
        state.ease_idx = imgui.Combo('Easing', state.ease_idx, state.ease_names, #state.ease_names)
        local ease_type = state.ease_values[state.ease_idx]

        -- Resize value storage if needed
        for i = #state.float_values + 1, state.anim_count do state.float_values[i] = 0.0 end
        for i = #state.vec2_values + 1, state.anim_count do state.vec2_values[i] = ImVec2(0, 0) end
        for i = #state.vec4_values + 1, state.anim_count do state.vec4_values[i] = ImVec4(0, 0, 0, 0) end

        -- Base ID for stress test animations
        local base_id = ImHashStr('stress_test')

        -- Profile the tween updates
        iam.ProfilerBegin('Stress: Tweens')

        -- Each animation has its own phase based on stagger
        -- They ping-pong between two states independently
        for i = 0, state.anim_count - 1 do
            local id = base_id + i

            -- Staggered phase - each animation starts at a different time
            local stagger_offset = i * state.stagger_amount
            local local_time = state.test_time - stagger_offset
            if local_time < 0.0 then local_time = 0.0 end

            -- Ping-pong cycle for this animation
            local cycle_duration = state.anim_duration * 2.0
            local cycle_pos = math.fmod(local_time, cycle_duration)
            local going_up = cycle_pos < state.anim_duration

            -- Determine target based on cycle phase and CAPTURE the animated value
            if state.test_mode == 1 then -- Float tweens - bounce between 0 and 1
                local target = going_up and 1.0 or 0.0
                state.float_values[i + 1] = iam.TweenFloat(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, dt)
            elseif state.test_mode == 2 then -- Vec2 tweens - move in unique circular patterns
                local angle_offset = i * 0.1
                local radius = going_up and 1.0 or 0.0
                local angle = angle_offset + (going_up and 0.0 or math.pi)
                local target = ImVec2(math.cos(angle) * radius, math.sin(angle) * radius)
                state.vec2_values[i + 1] = iam.TweenVec2(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, dt)
            elseif state.test_mode == 3 then -- Vec4 tweens - animate all components
                local base_hue = (i % 360) / 360.0
                local target
                if going_up then
                    target = ImVec4(base_hue, 0.9, 1.0, 1.0)
                else
                    target = ImVec4(math.fmod(base_hue + 0.5, 1.0), 0.3, 0.4, 1.0)
                end
                state.vec4_values[i + 1] = iam.TweenVec4(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, dt)
            elseif state.test_mode == 4 then -- Color tweens - cycle through hues
                local base_hue = (i % state.anim_count) / state.anim_count
                local target_hue = going_up and base_hue or math.fmod(base_hue + 0.33, 1.0)
                -- Convert hue to RGB
                local h = target_hue * 6.0
                local hi = math.floor(h) % 6
                local f = h - math.floor(h)
                local r, g, b
                if     hi == 0 then r = 1.0;     g = f;       b = 0.0
                elseif hi == 1 then r = 1.0 - f; g = 1.0;     b = 0.0
                elseif hi == 2 then r = 0.0;     g = 1.0;     b = f
                elseif hi == 3 then r = 0.0;     g = 1.0 - f; b = 1.0
                elseif hi == 4 then r = f;       g = 0.0;     b = 1.0
                else                r = 1.0;     g = 0.0;     b = 1.0 - f
                end
                local brightness = going_up and 1.0 or 0.5
                local target = ImVec4(r * brightness, g * brightness, b * brightness, 1.0)
                state.vec4_values[i + 1] = iam.TweenColor(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)
            elseif state.test_mode == 5 then -- Mixed - different animation per cell (store appropriately)
                local type_ = i % 4
                if type_ == 0 then
                    local target = going_up and 1.0 or 0.0
                    state.float_values[i + 1] = iam.TweenFloat(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, dt)
                elseif type_ == 1 then
                    local angle_offset = i * 0.15
                    local target = ImVec2(
                        going_up and math.cos(angle_offset) or -math.cos(angle_offset),
                        going_up and math.sin(angle_offset) or -math.sin(angle_offset))
                    state.vec2_values[i + 1] = iam.TweenVec2(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, dt)
                elseif type_ == 2 then
                    local hue = (i % 100) / 100.0
                    local target = going_up and ImVec4(hue, 1.0, 0.8, 1.0) or ImVec4(1.0 - hue, 0.3, 0.2, 1.0)
                    state.vec4_values[i + 1] = iam.TweenVec4(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, dt)
                elseif type_ == 3 then
                    local target = going_up and ImVec4(0.2, 0.8, 1.0, 1.0) or ImVec4(1.0, 0.3, 0.2, 1.0)
                    state.vec4_values[i + 1] = iam.TweenColor(id, 0, target, state.anim_duration, iam.EasePreset(ease_type), IamPolicy.Crossfade, IamColorSpace.OKLAB, dt)
                end
            end
        end

        iam.ProfilerEnd() -- End "Stress: Tweens"

        -- Visualization - render ALL animations
        imgui.Separator()
        imgui.Text('Visualization (%d animations):', state.anim_count)

        -- Configuration for visualization
        state.item_size = imgui.SliderFloat('Item Size', state.item_size, 8.0, 60.0)
        state.items_per_row = imgui.SliderInt('Items Per Row', state.items_per_row, 5, 100)

        -- Profile the rendering
        iam.ProfilerBegin('Stress: Render')

        -- Calculate grid dimensions
        local rows = math.floor((state.anim_count + state.items_per_row - 1) / state.items_per_row)
        local content_width = state.items_per_row * state.item_size
        local content_height = rows * state.item_size

        -- Scrollable child region
        local child_height = 300.0
        imgui.BeginChild('stress_viz', 0, child_height, ImGuiChildFlags.Borders, ImGuiWindowFlags.HorizontalScrollbar)

        local dl = imgui.GetWindowDrawList()
        local canvas_pos = imgui.GetCursorScreenPosVec()

        -- Reserve space for the content
        imgui.Dummy(ImVec2(content_width, content_height))

        -- Background
        dl:AddRectFilled(canvas_pos, ImVec2(canvas_pos.x + content_width, canvas_pos.y + content_height),
            IM_COL32(20, 20, 30, 255))

        -- Draw grid lines (subtle)
        for r = 0, rows do
            local y = canvas_pos.y + r * state.item_size
            dl:AddLine(ImVec2(canvas_pos.x, y), ImVec2(canvas_pos.x + content_width, y), IM_COL32(40, 40, 50, 255))
        end
        for c = 0, state.items_per_row do
            local x = canvas_pos.x + c * state.item_size
            dl:AddLine(ImVec2(x, canvas_pos.y), ImVec2(x, canvas_pos.y + content_height), IM_COL32(40, 40, 50, 255))
        end

        -- Draw each animation as a cell using STORED values (not re-querying the tween)
        local padding = 2.0
        for i = 0, state.anim_count - 1 do
            local grid_col = i % state.items_per_row
            local grid_row = math.floor(i / state.items_per_row)
            local cx = canvas_pos.x + grid_col * state.item_size + state.item_size * 0.5
            local cy = canvas_pos.y + grid_row * state.item_size + state.item_size * 0.5
            local cell_left = canvas_pos.x + grid_col * state.item_size + padding
            local cell_top = canvas_pos.y + grid_row * state.item_size + padding
            local cell_right = cell_left + state.item_size - padding * 2.0
            local cell_bottom = cell_top  + state.item_size - padding * 2.0

            if state.test_mode == 1 then -- Float - filled squares based on value
                local val = state.float_values[i + 1]
                local norm = math.max(0.0, math.min(1.0, val))
                local fill_height = (state.item_size - padding * 2.0) * norm
                local fill_top = cell_bottom - fill_height
                local col_fill = IM_COL32(80 + math.floor(norm * 175), 120 + math.floor(norm * 80), 255, 255)
                dl:AddRectFilled(ImVec2(cell_left, fill_top), ImVec2(cell_right, cell_bottom), col_fill)
            elseif state.test_mode == 2 then -- Vec2 - moving dot within cell
                local val = state.vec2_values[i + 1]
                local nx = math.max(-1.0, math.min(1.0, val.x))
                local ny = math.max(-1.0, math.min(1.0, val.y))
                local px = cx + nx * (state.item_size * 0.35)
                local py = cy + ny * (state.item_size * 0.35)
                local radius = state.item_size * 0.25
                dl:AddCircleFilled(ImVec2(px, py), radius, IM_COL32(100, 255, 150, 255))
                dl:AddCircle(ImVec2(px, py), radius, IM_COL32(150, 255, 200, 255), 0, 1.5)
            elseif state.test_mode == 3 then -- Vec4 - colored square
                local val = state.vec4_values[i + 1]
                local r = math.floor(math.max(0.0, math.min(1.0, val.x)) * 255)
                local g = math.floor(math.max(0.0, math.min(1.0, val.y)) * 255)
                local b = math.floor(math.max(0.0, math.min(1.0, val.z)) * 255)
                local a = math.floor(math.max(0.0, math.min(1.0, val.w)) * 255)
                dl:AddRectFilled(ImVec2(cell_left, cell_top), ImVec2(cell_right, cell_bottom), IM_COL32(r, g, b, a > 50 and a or 255))
            elseif state.test_mode == 4 then -- Color - colored square with border
                local val = state.vec4_values[i + 1]
                local r = math.floor(math.max(0.0, math.min(1.0, val.x)) * 255)
                local g = math.floor(math.max(0.0, math.min(1.0, val.y)) * 255)
                local b = math.floor(math.max(0.0, math.min(1.0, val.z)) * 255)
                dl:AddRectFilled(ImVec2(cell_left, cell_top), ImVec2(cell_right, cell_bottom), IM_COL32(r, g, b, 255))
                dl:AddRect(ImVec2(cell_left, cell_top), ImVec2(cell_right, cell_bottom), IM_COL32(255, 255, 255, 100), 0.0, 0, 1.0)
            elseif state.test_mode == 5 then -- Mixed - different visualization per cell type
                local type_ = i % 4
                if type_ == 0 then
                    local val = state.float_values[i + 1]
                    local norm = math.max(0.0, math.min(1.0, val))
                    local fill_height = (state.item_size - padding * 2.0) * norm
                    local fill_top = cell_bottom - fill_height
                    dl:AddRectFilled(ImVec2(cell_left, fill_top), ImVec2(cell_right, cell_bottom), IM_COL32(80 + math.floor(norm * 175), 120, 255, 255))
                elseif type_ == 1 then
                    local val = state.vec2_values[i + 1]
                    local px = cx + math.max(-1.0, math.min(1.0, val.x)) * (state.item_size * 0.35)
                    local py = cy + math.max(-1.0, math.min(1.0, val.y)) * (state.item_size * 0.35)
                    dl:AddCircleFilled(ImVec2(px, py), state.item_size * 0.25, IM_COL32(100, 255, 150, 255))
                else -- case 2 and 3
                    local val = state.vec4_values[i + 1]
                    local r = math.floor(math.max(0.0, math.min(1.0, val.x)) * 255)
                    local g = math.floor(math.max(0.0, math.min(1.0, val.y)) * 255)
                    local b = math.floor(math.max(0.0, math.min(1.0, val.z)) * 255)
                    dl:AddRectFilled(ImVec2(cell_left, cell_top), ImVec2(cell_right, cell_bottom), IM_COL32(r, g, b, 255))
                end
            end
        end

        imgui.EndChild()

        iam.ProfilerEnd() -- End "Stress: Render"
    else
        imgui.TextDisabled("Press 'Start Test' to begin the stress test.")
    end

    imgui.Separator()
    imgui.TextDisabled('Note: High animation counts will impact both computation and rendering performance.')
end

-- ============================================================
-- MAIN DEMO WINDOW
-- ============================================================
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

        iam.ProfilerEnd()
    end

    -- ========================================
    -- 2. INTERACTIVE WIDGETS
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Interactive Widgets') then
        iam.ProfilerBegin('Interactive Widgets (lua)')
        ShowWidgetsDemo()
        iam.ProfilerEnd()
    end

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

        ApplyOpenAll()
        if imgui.TreeNode('Color Keyframes') then
            ShowColorKeyframeDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Timeline Markers') then
            ShowTimelineMarkersDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Animation Chaining') then
            ShowAnimationChainingDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Layering System') then
            ShowLayeringDemo()
            imgui.TreePop()
        end

        iam.ProfilerEnd()
    end

    -- ========================================
    -- 4. PROCEDURAL ANIMATIONS
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Procedural Animations') then
        iam.ProfilerBegin('Procedural Animations (lua)')

        ApplyOpenAll()
        if imgui.TreeNode('Oscillators') then
            ShowOscillatorsDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Shake & Wiggle') then
            ShowShakeWiggleDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Noise Channels') then
            ShowNoiseChannelsDemo()
            imgui.TreePop()
        end

        iam.ProfilerEnd()
    end

    -- ========================================
    -- 5. MOTION PATHS
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Motion Paths') then
        iam.ProfilerBegin('Motion Paths (lua)')

        ApplyOpenAll()
        if imgui.TreeNode('Path Basics') then
            ShowMotionPathsDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Path Morphing') then
            ShowPathMorphingDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Text Along Paths') then
            ShowTextAlongPathDemo()
            imgui.TreePop()
        end

        iam.ProfilerEnd()
    end

    -- ========================================
    -- 6. ADVANCED INTERPOLATION
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Advanced Interpolation') then
        iam.ProfilerBegin('Advanced Interpolation (lua)')

        ApplyOpenAll()
        if imgui.TreeNode('Gradient Keyframes') then
            ShowGradientKeyframesDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Transform Interpolation') then
            ShowTransformInterpolationDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Style Interpolation') then
            ShowStyleInterpolationDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Text Stagger') then
            ShowTextStaggerDemo()
            imgui.TreePop()
        end

        iam.ProfilerEnd()
    end

    -- ========================================
    -- 7. UTILITIES
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Utilities') then
        iam.ProfilerBegin('Utilities (lua)')

        ApplyOpenAll()
        if imgui.TreeNode('ImDrawList Animations') then
            ShowDrawListDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Resize-Aware Helpers') then
            ShowResizeHelpersDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Scroll Animation') then
            ShowScrollDemo()
            imgui.TreePop()
        end

        ApplyOpenAll()
        if imgui.TreeNode('Drag Feedback') then
            ShowDragFeedbackDemo()
            imgui.TreePop()
        end

        iam.ProfilerEnd()
    end

    -- ========================================
    -- 8. DEBUG TOOLS
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Debug Tools') then
        iam.ProfilerBegin('Debug Tools (lua)')
        ShowAnimationInspectorDemo()
        iam.ProfilerEnd()
    end

    -- ========================================
    -- 9. STRESS TEST
    -- ========================================
    ApplyOpenAll()
    if imgui.CollapsingHeader('Stress Test') then
        iam.ProfilerBegin('Stress Test (lua)')
        ShowStressTestDemo()
        iam.ProfilerEnd()
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
