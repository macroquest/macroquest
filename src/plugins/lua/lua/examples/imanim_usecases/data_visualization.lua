local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

local val_id = ImHashStr("val")

-- ============================================================
-- 44. Animated Bar Chart
-- Bar chart with animated height transitions
-- ============================================================
local function ShowUsecase_AnimatedBarChart()
    -- TODO: Implement Animated Bar Chart
end

-- ============================================================
-- 45. Animated Line Chart
-- Real-time line chart with smooth data updates
-- ============================================================
local line_chart_state = {
    id = ImHashStr("linechart"),
    data_points = {},
    target_points = {},
    initialized = false,
    update_timer = 0.0,
}

local function ShowUsecase_AnimatedLineChart()
    imgui.TextWrapped("Line chart with animated real-time data:")

    if not line_chart_state.initialized then
        for i=1,20 do
            line_chart_state.data_points[i] = 0.3 + (i % 5) * 0.1 + math.sin(i * 0.5) * 0.2
            line_chart_state.target_points[i] = line_chart_state.data_points[i]
        end
        line_chart_state.initialized = true
    end

    local dt = common.GetDeltaTime()

    -- Auto-update data periodically
    line_chart_state.update_timer = line_chart_state.update_timer + dt
    if line_chart_state.update_timer > 1.5 then
        line_chart_state.update_timer = 0.0
        -- Shift data left and add new point
        for i=1,19 do
            line_chart_state.target_points[i] = line_chart_state.target_points[i + 1]
        end
        line_chart_state.target_points[20] = 0.2 + (math.random(100) % 60) / 100.0
    end

    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetFontSize() / 13.0

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(imgui.GetContentRegionAvailVec().x, 140)

    -- Background
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y),
        IM_COL32(25, 28, 35, 255), 4.0)

    local margin = 20 * scale
    local chart_width = cs.x - margin * 2
    local chart_height = cs.y - margin * 2

    -- Grid lines
    for i=1,5 do
        local y = cp.y + margin + (i - 1) / 4.0 * chart_height
        dl:AddLine(ImVec2(cp.x + margin, y), ImVec2(cp.x + cs.x - margin, y),
            IM_COL32(45, 50, 60, 255))
    end

    -- Animate and draw line only (no dots, no fill)
    local prev_pt
    for i=1,20 do
        -- Animate each point
        local id = line_chart_state.id + i
        line_chart_state.data_points[i] = iam.TweenFloat(id, val_id, line_chart_state.target_points[i], 0.4,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        local x = cp.x + margin + (i - 1) / 19.0 * chart_width
        local y = cp.y + margin + (1.0 - line_chart_state.data_points[i]) * chart_height
        local pt = ImVec2(x, y)

        if i > 1 then
            -- Line segment only
            dl:AddLine(prev_pt, pt, IM_COL32(91, 194, 231, 255), 2 * scale)
        end

        prev_pt = pt
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 8))
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- 46. Animated Pie Chart
-- Donut chart with animated segments
-- ============================================================
local function ShowUsecase_AnimatedPieChart()
    -- TODO: Implement Animated Pie Chart
end

-- ============================================================
-- 47. Heat Map
-- Animated heat map grid visualization
-- ============================================================
local function ShowUsecase_HeatMap()
    -- TODO: Implement Heat Map
end

-- ============================================================
-- 48. Sparkline
-- Mini inline chart for data trends
-- ============================================================
local function ShowUsecase_Sparkline()
    -- TODO: Implement Sparkline
end

-- ============================================================
-- 48. Radar Chart
-- Animated radar/spider chart for multi-dimensional data
-- ============================================================
local function ShowUsecase_RadarChart()
    -- TODO: Implement Radar Chart
end

-- ============================================================
-- 49. Gauge Meter
-- Animated gauge/speedometer visualization
-- ============================================================
local gauge_meter_state = {
    id = ImHashStr("gauge"),
    gauge_value = 0.65,
    target_value = 0.65,
}

local function ShowUsecase_GaugeMeter()
    imgui.TextWrapped("Gauge meter with animated needle and gradient arc:")

    gauge_meter_state.target_value, _ = imgui.SliderFloat("Value", gauge_meter_state.target_value, 0.0, 1.0)

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetFontSize() / 13.0

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(imgui.GetContentRegionAvailVec().x, 250) -- 25% taller canvas

    -- Background
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y),
        IM_COL32(25, 28, 35, 255), 4.0)

    -- Center positioned near bottom for upward-facing arc (gauge sits at bottom)
    local center = ImVec2(cp.x + cs.x * 0.5, cp.y + cs.y * 0.92)
    local outer_radius = 65 * scale
    local inner_radius = 45 * scale

    -- Animate value
    gauge_meter_state.gauge_value = iam.TweenFloat(gauge_meter_state.id, val_id, gauge_meter_state.target_value, 0.6,
        iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

    -- Draw arc segments with gradient (semicircle pointing UP)
    local start_angle = 3.14159     -- 180 degrees (left)
    local end_angle = 3.14159 * 2   -- 360 degrees (right) - arc goes UP
    local segments = 50

    for s=0,segments do
        local t = s / segments
        local a1 = start_angle + (end_angle - start_angle) * t
        local a2 = start_angle + (end_angle - start_angle) * (t + 1.0 / segments)

        -- Color gradient: green -> yellow -> red
        local r, g, b
        if t < 0.5 then
            local lt = t * 2
            r = 76 + (255 - 76) * lt
            g = 175 + (193 - 175) * lt
            b = 80 - 80 * lt
        else
            local lt = (t - 0.5) * 2
            r = 255
            g = 193 - 193 * lt
            b = 0
        end

        local p1 = ImVec2(center.x + math.cos(a1) * inner_radius, center.y + math.sin(a1) * inner_radius)
        local p2 = ImVec2(center.x + math.cos(a1) * outer_radius, center.y + math.sin(a1) * outer_radius)
        local p3 = ImVec2(center.x + math.cos(a2) * outer_radius, center.y + math.sin(a2) * outer_radius)
        local p4 = ImVec2(center.x + math.cos(a2) * inner_radius, center.y + math.sin(a2) * inner_radius)

        dl:AddQuadFilled(p1, p2, p3, p4, IM_COL32(r, g, b, 255))
    end

    -- Draw tick marks
    for i=0,10 do
        local t = i / 10.0
        local angle = start_angle + (end_angle - start_angle) * t
        local tick_inner = outer_radius + 3 * scale
        local tick_outer = outer_radius + (i % 5 == 0 and 10 or 6) * scale

        dl:AddLine(
            ImVec2(center.x + math.cos(angle) * tick_inner, center.y + math.sin(angle) * tick_inner),
            ImVec2(center.x + math.cos(angle) * tick_outer, center.y + math.sin(angle) * tick_outer),
            IM_COL32(180, 180, 190, 255), (i % 5 == 0 and 2 or 1) * scale)

        -- Labels for major ticks
        if i % 5 == 0 then
            local label = string.format('%d', i * 10)
            local label_size = imgui.CalcTextSizeVec(label)
            local label_r = outer_radius + 18 * scale
            dl:AddText(
                ImVec2(center.x + math.cos(angle) * label_r - label_size.x * 0.5,
                    center.y + math.sin(angle) * label_r - label_size.y * 0.5),
                IM_COL32(150, 150, 160, 255), label)
        end
    end

    -- Draw needle
    local needle_angle = start_angle + (end_angle - start_angle) * gauge_meter_state.gauge_value
    local needle_length = inner_radius - 5 * scale

    local needle_tip = ImVec2(center.x + math.cos(needle_angle) * needle_length,
        center.y + math.sin(needle_angle) * needle_length)
    local needle_base1 = ImVec2(center.x + math.cos(needle_angle + 3.14159 * 0.5) * 4 * scale,
        center.y + math.sin(needle_angle + 3.14159 * 0.5) * 4 * scale)
    local needle_base2 = ImVec2(center.x + math.cos(needle_angle - 3.14159 * 0.5) * 4 * scale,
        center.y + math.sin(needle_angle - 3.14159 * 0.5) * 4 * scale)

    dl:AddTriangleFilled(needle_tip, needle_base1, needle_base2, IM_COL32(220, 220, 230, 255))
    dl:AddCircleFilled(center, 8 * scale, IM_COL32(50, 55, 70, 255))
    dl:AddCircleFilled(center, 5 * scale, IM_COL32(220, 220, 230, 255))

    -- Value display (above the gauge)
    local value_str = string.format('%.0f%%', gauge_meter_state.gauge_value * 100)
    local value_size = imgui.CalcTextSizeVec(value_str)
    dl:AddText(ImVec2(center.x - value_size.x * 0.5, cp.y + 20 * scale),
        IM_COL32(220, 220, 230, 255), value_str)

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 8))
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- 50. Sankey Flow
-- Animated flow diagram showing data relationships
-- ============================================================
local sankey_flow_state = {
    flow_time = 0.0,
    sources = { "Direct", "Search", "Social" },
    source_colors = {
        IM_COL32(91, 194, 231, 255),
        IM_COL32(76, 175, 80, 255),
        IM_COL32(255, 152, 0, 255)
    },
    source_weights = { 0.4, 0.35, 0.25 },
    targets = { "Sales", "Signup", "Bounce" },
    target_colors = {
        IM_COL32(156, 39, 176, 255),
        IM_COL32(0, 188, 212, 255),
        IM_COL32(233, 30, 99, 255)
    },
    target_weights = { 0.45, 0.30, 0.25 },
    flows = {
        {from=1, to=1, weight=0.20}, {from=1, to=2, weight=0.15}, {from=1, to=3, weight=0.05},
        {from=2, to=1, weight=0.18}, {from=2, to=2, weight=0.10}, {from=2, to=3, weight=0.07},
        {from=3, to=1, weight=0.07}, {from=3, to=2, weight=0.05}, {from=3, to=3, weight=0.13}
    }
}

local function ShowUsecase_SankeyFlow()
    imgui.TextWrapped("Animated flow diagram with particle effects:")

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetFontSize() / 13.0

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(imgui.GetContentRegionAvailVec().x, 320)

    sankey_flow_state.flow_time = sankey_flow_state.flow_time + dt

    -- Background
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y),
        IM_COL32(25, 28, 35, 255), 4.0)

    local left_x = cp.x + 100 * scale
    local right_x = cp.x + cs.x - 100 * scale
    local flow_height = cs.y - 80 * scale
    local node_width = 35 * scale

    -- Draw source nodes
    local y_offset = cp.y + 30 * scale
    for i=1,3 do
        local node_height = flow_height * sankey_flow_state.source_weights[i]

        -- Node rectangle
        dl:AddRectFilled(
            ImVec2(left_x, y_offset),
            ImVec2(left_x + node_width, y_offset + node_height),
            sankey_flow_state.source_colors[i], 4.0)

        -- Label
        local label_size = imgui.CalcTextSizeVec(sankey_flow_state.sources[i])
        dl:AddText(ImVec2(left_x - label_size.x - 8 * scale, y_offset + (node_height - label_size.y) * 0.5),
            IM_COL32(180, 180, 190, 255), sankey_flow_state.sources[i])

        y_offset = y_offset + node_height + 10 * scale
    end

    -- Draw target nodes
    y_offset = cp.y + 30 * scale
    for i=1,3 do
        local node_height = flow_height * sankey_flow_state.target_weights[i]

        -- Node rectangle
        dl:AddRectFilled(
            ImVec2(right_x, y_offset),
            ImVec2(right_x + node_width, y_offset + node_height),
            sankey_flow_state.target_colors[i], 4.0)

        -- Label
        dl:AddText(ImVec2(right_x + node_width + 8 * scale, y_offset + (node_height - imgui.GetFontSize()) * 0.5),
            IM_COL32(180, 180, 190, 255), sankey_flow_state.targets[i])

        y_offset = y_offset + node_height + 10 * scale
    end

    -- Draw flow connections with bezier curves

    -- Calculate node positions
    local source_y, source_heights = {}, {}
    local target_y, target_heights = {}, {}

    local sy = cp.y + 30 * scale
    for i=1,3 do
        source_y[i] = sy
        source_heights[i] = flow_height * sankey_flow_state.source_weights[i]
        sy = sy + source_heights[i] + 10 * scale
    end

    local ty = cp.y + 30 * scale
    for i=1,3 do
        target_y[i] = ty
        target_heights[i] = flow_height * sankey_flow_state.target_weights[i]
        ty = ty + target_heights[i] + 10 * scale
    end

    -- Track used height on each node
    local source_used = {0, 0, 0}
    local target_used = {0, 0, 0}

    for f=1,9 do
        local from = sankey_flow_state.flows[f].from
        local to = sankey_flow_state.flows[f].to
        local weight = sankey_flow_state.flows[f].weight

        local band_height = flow_height * weight

        local from_y = source_y[from] + source_used[from]
        local to_y = target_y[to] + target_used[to]

        source_used[from] = source_used[from] + band_height
        target_used[to] = target_used[to] + band_height

        -- Draw gradient band using bezier
        local p1 = ImVec2(left_x + node_width, from_y)
        local p2 = ImVec2(left_x + node_width, from_y + band_height)
        local p3 = ImVec2(right_x, to_y)
        local p4 = ImVec2(right_x, to_y + band_height)

        local ctrl_offset = (right_x - left_x - node_width) * 0.4

        -- Cubic bezier for top edge
        local function bezier(a, b, c, d, t)
            local u = 1 - t
            return ImVec2(
                u*u*u*a.x + 3*u*u*t*b.x + 3*u*t*t*c.x + t*t*t*d.x,
                u*u*u*a.y + 3*u*u*t*b.y + 3*u*t*t*c.y + t*t*t*d.y)
        end

        -- Draw filled bezier band
        local steps = 20
        for s=1,steps do
            local t1 = (s - 1) / steps
            local t2 = s / steps

            local ctrl1_top = ImVec2(p1.x + ctrl_offset, p1.y)
            local ctrl2_top = ImVec2(p3.x - ctrl_offset, p3.y)
            local ctrl1_bot = ImVec2(p2.x + ctrl_offset, p2.y)
            local ctrl2_bot = ImVec2(p4.x - ctrl_offset, p4.y)

            local top1 = bezier(p1, ctrl1_top, ctrl2_top, p3, t1)
            local top2 = bezier(p1, ctrl1_top, ctrl2_top, p3, t2)
            local bot1 = bezier(p2, ctrl1_bot, ctrl2_bot, p4, t1)
            local bot2 = bezier(p2, ctrl1_bot, ctrl2_bot, p4, t2)

            -- bit32.bor(bit32.band(col, 0xffffff), bit32.lshift(a, 24))
            -- Blend color from source to target
            local blend = (t1 + t2) * 0.5
            local col1 = sankey_flow_state.source_colors[from]
            local col2 = sankey_flow_state.target_colors[to]
            local r = ((1 - blend) * (bit32.band(bit32.rshift(col1, 0), 0xFF)) + blend * (bit32.band(bit32.rshift(col2, 0), 0xFF)))
            local g = ((1 - blend) * (bit32.band(bit32.rshift(col1, 8), 0xFF)) + blend * (bit32.band(bit32.rshift(col2, 8), 0xFF)))
            local b = ((1 - blend) * (bit32.band(bit32.rshift(col1, 16), 0xFF)) + blend * (bit32.band(bit32.rshift(col2, 16), 0xFF)))
            
            dl:AddQuadFilled(top1, top2, bot2, bot1, IM_COL32(r, g, b, 120))
        end

        -- Animated flow particles
        local particle_count = weight * 20
        for p=1,particle_count do
            local pt = math.fmod(sankey_flow_state.flow_time * 0.3 + p / particle_count + f * 0.1, 1.0)

            local mid_top = ImVec2(p1.x, (p1.y + p2.y) * 0.5)
            local mid_bot = ImVec2(p3.x, (p3.y + p4.y) * 0.5)
            local ctrl1 = ImVec2(mid_top.x + (right_x - left_x) * 0.4, mid_top.y)
            local ctrl2 = ImVec2(mid_bot.x - (right_x - left_x) * 0.4, mid_bot.y)

            local particle_pos = bezier(mid_top, ctrl1, ctrl2, mid_bot, pt)

            local alpha = math.sin(pt * 3.14159)
            dl:AddCircleFilled(particle_pos, 3 * scale, IM_COL32(255, 255, 255, 180 * alpha))
        end
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 8))
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- 51. Funnel Chart
-- Animated funnel chart showing conversion stages
-- ============================================================
local function ShowUsecase_FunnelChart()
    -- TODO: Implement Funnel Chart
end

-- ============================================================
-- 52. Animated Scatter Plot
-- Scatter plot with animated point transitions
-- ============================================================
local function ShowUsecase_ScatterPlot()
    -- TODO: Implement Animated Scatter Plot
end

-- ============================================================
-- 53. Progress Dashboard
-- Multi-metric dashboard with animated progress rings
-- ============================================================
local progress_dashboard_state = {
    id = ImHashStr("dashboard"),
    metrics = { 0.72, 0.45, 0.88, 0.33 },
    targets = { 0.72, 0.45, 0.88, 0.33 },
    labels = { "CPU", "Memory", "Network", "Disk" },
    colors = {
        IM_COL32(91, 194, 231, 255),
        IM_COL32(76, 175, 80, 255),
        IM_COL32(255, 152, 0, 255),
        IM_COL32(233, 30, 99, 255)
    }
}

local function ShowUsecase_ProgressDashboard()
    imgui.TextWrapped("Dashboard with animated progress indicators:")

    if imgui.Button("Update Metrics##Dashboard") then
        for i=1,4 do
            progress_dashboard_state.targets[i] = 0.1 + (math.random(100) % 90) / 100.0
        end
    end

    local dt = common.GetDeltaTime()
    local dl = imgui.GetWindowDrawList()
    local scale = imgui.GetFontSize() / 13.0

    local cp = imgui.GetCursorScreenPosVec()
    local cs = ImVec2(imgui.GetContentRegionAvailVec().x, 250) -- 25% taller canvas

    -- Background
    dl:AddRectFilled(cp, ImVec2(cp.x + cs.x, cp.y + cs.y),
        IM_COL32(25, 28, 35, 255), 4.0)

    local ring_spacing = cs.x / 4
    local ring_radius = 28 * scale
    local ring_thickness = 6 * scale

    for i=1,4 do
        -- Animate value
        local id = progress_dashboard_state.id + i
        progress_dashboard_state.metrics[i] = iam.TweenFloat(id, val_id, progress_dashboard_state.targets[i], 0.6,
            iam.EasePreset(IamEaseType.OutCubic), IamPolicy.Crossfade, dt)

        local center = ImVec2(cp.x + ring_spacing * (i - 1 + 0.5), cp.y + cs.y * 0.45)

        -- Background ring
        dl:AddCircle(center, ring_radius, IM_COL32(50, 55, 70, 255), 0, ring_thickness)

        -- Progress arc
        local start_angle = -3.14159 * 0.5
        local sweep = progress_dashboard_state.metrics[i] * 3.14159 * 2
        local segments = math.floor((sweep / 0.1) + 1)

        for s=1,segments do
            local t1 = s / segments
            local t2 = (s + 1) / segments
            local a1 = start_angle + sweep * t1
            local a2 = start_angle + sweep * t2

            local p1 = ImVec2(center.x + math.cos(a1) * (ring_radius - ring_thickness * 0.5),
                center.y + math.sin(a1) * (ring_radius - ring_thickness * 0.5))
            local p2 = ImVec2(center.x + math.cos(a1) * (ring_radius + ring_thickness * 0.5),
                center.y + math.sin(a1) * (ring_radius + ring_thickness * 0.5))
            local p3 = ImVec2(center.x + math.cos(a2) * (ring_radius + ring_thickness * 0.5),
                center.y + math.sin(a2) * (ring_radius + ring_thickness * 0.5))
            local p4 = ImVec2(center.x + math.cos(a2) * (ring_radius - ring_thickness * 0.5),
                center.y + math.sin(a2) * (ring_radius - ring_thickness * 0.5))

            dl:AddQuadFilled(p1, p2, p3, p4, progress_dashboard_state.colors[i])
        end

        -- Value text
        local val_str = string.format('%.0f%%', progress_dashboard_state.metrics[i] * 100)
        local val_size = imgui.CalcTextSizeVec(val_str)
        dl:AddText(ImVec2(center.x - val_size.x * 0.5, center.y - val_size.y * 0.5),
            IM_COL32(220, 220, 230, 255), val_str)

        -- Label
        local label_size = imgui.CalcTextSizeVec(progress_dashboard_state.labels[i])
        dl:AddText(ImVec2(center.x - label_size.x * 0.5, center.y + ring_radius + 12 * scale),
            IM_COL32(150, 150, 160, 255), progress_dashboard_state.labels[i])
    end

    imgui.SetCursorScreenPos(ImVec2(cp.x, cp.y + cs.y + 8))
    imgui.Dummy(ImVec2(1, 1))
end

-- ============================================================
-- 54. Area Chart
-- Stacked area chart with animated fill
-- ============================================================
local function ShowUsecase_AreaChart()
    -- TODO: Implement Area Chart
end

local function RunDataVisualizationDemo()
    -- ========================================
    -- DATA VISUALIZATION
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Data Visualization") then
        imgui.Indent()
        common.USECASE_ITEM('Animated Bar Chart', ShowUsecase_AnimatedBarChart)
        common.USECASE_ITEM('Animated Line Chart', ShowUsecase_AnimatedLineChart)
        common.USECASE_ITEM('Animated Pie Chart', ShowUsecase_AnimatedPieChart)
        common.USECASE_ITEM('Area Chart', ShowUsecase_AreaChart)
        common.USECASE_ITEM('Heat Map', ShowUsecase_HeatMap)
        common.USECASE_ITEM('Sparkline', ShowUsecase_Sparkline)
        common.USECASE_ITEM('Radar Chart', ShowUsecase_RadarChart)
        common.USECASE_ITEM('Gauge Meter', ShowUsecase_GaugeMeter)
        common.USECASE_ITEM('Sankey Flow', ShowUsecase_SankeyFlow)
        common.USECASE_ITEM('Funnel Chart', ShowUsecase_FunnelChart)
        common.USECASE_ITEM('Scatter Plot', ShowUsecase_ScatterPlot)
        common.USECASE_ITEM('Progress Dashboard', ShowUsecase_ProgressDashboard)
        imgui.Unindent()
    end
end

return RunDataVisualizationDemo
