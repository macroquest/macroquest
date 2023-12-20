---@diagnostic disable: empty-block

local mq = require('mq')
local imgui = require('ImGui')
local implot = require('ImPlot')

local FLT_MIN, FLT_MAX = mq.NumericLimits_Float()

local ImPlotDemo = {
    show_implot_metrics = false,
    show_implot_style_editor = false,
    show_imgui_metrics = false,
    show_imgui_style_editor = false,
    show_imgui_demo = false,
}

---@param min number
---@param max number
---@return number
function RandomRange(min, max)
    return min + math.random() * (max - min)
end

---@class ScrollingBuffer
---@field MaxSize number
---@field Offset number
---@field DataX number[]
---@field DataY number[]
local ScrollingBuffer = {}

---@param max_size? number
---@return ScrollingBuffer
function ScrollingBuffer:new(max_size)
    max_size = max_size or 2000
    local newObject = setmetatable({}, self)
    self.__index = self
    newObject.MaxSize = max_size
    newObject.Offset = 1
    newObject.DataX = {}
    newObject.DataY = {}
    return newObject
end

---@param x number
---@param y number
function ScrollingBuffer:AddPoint(x, y)
    if #self.DataX < self.MaxSize then
        table.insert(self.DataX, x)
        table.insert(self.DataY, y)
    else
        self.DataX[self.Offset] = x
        self.DataY[self.Offset] = y
        self.Offset = self.Offset + 1
        if self.Offset > self.MaxSize then
            self.Offset = 1
        end
    end
end

function ScrollingBuffer:Erase()
    self.DataX = {}
    self.DataY = {}
end


---@class RollingBuffer
---@field DataX number[]
---@field DataY number[]
---@field Span number
local RollingBuffer = {}

---@return RollingBuffer
function RollingBuffer:new()
    local newObject = setmetatable({}, self)
    self.__index = self
    newObject.Span = 10.0
    newObject.DataX = {}
    newObject.DataY = {}
    return newObject
end

---@param x number
---@param y number
function RollingBuffer:AddPoint(x, y)
    local xmod = math.fmod(x, self.Span)
    if #self.DataX > 0 and xmod < self.DataX[#self.DataX] then
        self.DataX = {}
        self.DataY = {}
    end

    table.insert(self.DataX, xmod)
    table.insert(self.DataY, y)
end

local RandomGauss_Data = {
    V1 = 0,
    V2 = 0,
    S = 0,
    X = 0,
    phase = 0,
}

function RandomGauss()
    local data = RandomGauss_Data

    if data.phase == 0 then
        repeat
            local U1 = RandomRange(0, 1)
            local U2 = RandomRange(0, 1)
            data.V1 = 2 * U1 - 1
            data.V2 = 2 * U2 - 1
            data.S = data.V1 * data.V1 + data.V2 * data.V2
        until data.S ~= 0 and data.S < 1

        data.X = data.V1 * math.sqrt(-2 * math.log(data.S) / data.S)
    else
        data.X = data.V2 * math.sqrt(-2 * math.log(data.S) / data.S)
    end

    data.phase = 1 - data.phase
    return data.X
end

function NormalDistribution(mean, sd, count)
    local data = {}
    for i = 1, count do
        data[i] = RandomGauss() * sd + mean
    end
    return data
end

---@param id string
---@param values number[]
---@param minValue number
---@param maxValue number
---@param offset integer
---@param col ImVec4
---@param size ImVec2
function Sparkline(id, values, minValue, maxValue, offset, col, size)
    implot.PushStyleVar(ImPlotStyleVar.PlotPadding, ImVec2(0, 0))
    if implot.BeginPlot(id, size, ImPlotFlags.CanvasOnly) then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoDecorations, ImPlotAxisFlags.NoDecorations)
        implot.SetupAxesLimits(0, #values, minValue, maxValue, ImGuiCond.Always)
        implot.SetNextLineStyle(col)
        implot.SetNextFillStyle(col, 0.25)
        implot.PlotLine(id, values, #values, 1, 0, ImPlotLineFlags.Shaded, offset)
        implot.EndPlot()
    end
    implot.PopStyleVar()
end



---@param label string
---@param demo fun(ImPlotDemo): nil
function ImPlotDemo:DemoHeader(label, demo)
    if imgui.TreeNodeEx(label) then
        demo(self)
        imgui.TreePop()
    end
end

function ImPlotDemo:ShowDemoWindow(open)
    if self.show_implot_metrics then
        self.show_implot_metrics = implot.ShowMetricsWindow(self.show_implot_metrics)
    end
    if self.show_implot_style_editor then
        imgui.SetNextWindowSize(ImVec2(415, 762), ImGuiCond.Appearing)
        self.show_implot_style_editor = imgui.Begin('Style Editor (ImPlot)', self.show_implot_style_editor)
        implot.ShowStyleEditor()
        imgui.End()
    end
    if self.show_imgui_style_editor then
        self.show_imgui_style_editor = imgui.Begin('Style Editor (ImGui)', self.show_imgui_style_editor)
        imgui.ShowStyleEditor()
        imgui.End()
    end
    if self.show_imgui_metrics then
        self.show_imgui_metrics = imgui.ShowMetricsWindow(self.show_imgui_metrics)
    end
    if self.show_imgui_demo then
        self.show_imgui_demo = imgui.ShowDemoWindow(self.show_imgui_demo)
    end

    imgui.SetNextWindowPos(ImVec2(50, 50), ImGuiCond.FirstUseEver)
    imgui.SetNextWindowSize(ImVec2(600, 750), ImGuiCond.FirstUseEver)
    open = imgui.Begin("ImPlot Demo (Lua)", open, ImGuiWindowFlags.MenuBar)

    if imgui.BeginMenuBar() then
        if imgui.BeginMenu('Tools') then
            _, self.show_implot_metrics = imgui.MenuItem('Metrics', nil, self.show_implot_metrics)
            _, self.show_implot_style_editor = imgui.MenuItem('Style Editor', nil, self.show_implot_style_editor)
            imgui.Separator()
            _, self.show_imgui_metrics = imgui.MenuItem('ImGui Metrics', nil, self.show_imgui_metrics)
            _, self.show_imgui_style_editor = imgui.MenuItem('ImGui Style Editor', nil, self.show_imgui_style_editor)
            _, self.show_imgui_demo = imgui.MenuItem('ImGui Demo', nil, self.show_imgui_demo)
            imgui.EndMenu()
        end
        imgui.EndMenuBar()
    end

    imgui.Text('ImPlot says hello. (%s)', implot.GetVersion())
    imgui.Spacing()

    if imgui.BeginTabBar("ImPlotDemoTabs") then
        if imgui.BeginTabItem('Plots') then
            self:DemoHeader("Line Plots", self.Demo_LinePlots)
            self:DemoHeader("Filled Line Plots", self.Demo_FilledLinePlots);
            self:DemoHeader("Shaded Plots##", self.Demo_ShadedPlots)
            self:DemoHeader("Scatter Plots", self.Demo_ScatterPlots)
            self:DemoHeader("Realtime Plots", self.Demo_RealtimePlots)
            self:DemoHeader("Stairstep Plots", self.Demo_StairstepPlots)
            self:DemoHeader("Bar Plots", self.Demo_BarPlots)
            self:DemoHeader("Bar Groups", self.Demo_BarGroups)
            self:DemoHeader("Bar Stacks", self.Demo_BarStacks)
            self:DemoHeader("Error Bars", self.Demo_ErrorBars)
            self:DemoHeader("Stem Plots", self.Demo_StemPlots)
            self:DemoHeader("Infinite Lines", self.Demo_InfiniteLines)
            self:DemoHeader("Pie Charts", self.Demo_PieCharts)
            self:DemoHeader("Heatmaps", self.Demo_Heatmaps)
            self:DemoHeader("Histogram", self.Demo_Histogram)
            self:DemoHeader("Histogram 2D", self.Demo_Histogram2D)
            self:DemoHeader("Digital Plots", self.Demo_DigitalPlots)
            self:DemoHeader("Images", self.Demo_Images)
            self:DemoHeader("Markers and Text", self.Demo_MarkersAndText)
            self:DemoHeader("NaN Values", self.Demo_NaNValues)

            imgui.EndTabItem()
        end
        if imgui.BeginTabItem("Subplots") then
            self:DemoHeader("Sizing", self.Demo_SubplotsSizing)
            self:DemoHeader("Item Sharing", self.Demo_SubplotItemSharing)
            self:DemoHeader("Axis Linking", self.Demo_SubplotAxisLinking)
            self:DemoHeader("Tables", self.Demo_Tables)
            imgui.EndTabItem()
        end
        if imgui.BeginTabItem("Axes") then
            self:DemoHeader("Log Scale", self.Demo_LogScale)
            self:DemoHeader("Symmetric Log Scale", self.Demo_SymmetricLogScale)
            self:DemoHeader("Time Scale", self.Demo_TimeScale)
            self:DemoHeader("Custom Scale", self.Demo_CustomScale)
            self:DemoHeader("Multiple Axes", self.Demo_MultipleAxes)
            self:DemoHeader("Tick Labels", self.Demo_TickLabels)
            self:DemoHeader("Linked Axes", self.Demo_LinkedAxes)
            self:DemoHeader("Axis Constraints", self.Demo_AxisConstraints)
            self:DemoHeader("Equal Axes", self.Demo_EqualAxes)
            self:DemoHeader("Auto-Fitting Data", self.Demo_AutoFittingData)
            imgui.EndTabItem()
        end
        if imgui.BeginTabItem('Tools') then
            imgui.EndTabItem()
        end
        if imgui.BeginTabItem('Custom') then
            imgui.EndTabItem()
        end
        if imgui.BeginTabItem('Config') then
            imgui.EndTabItem()
        end
        if imgui.BeginTabItem('Help') then
            ImPlotDemo:Demo_Help()
            imgui.EndTabItem()
        end
        imgui.EndTabBar()
    end

    imgui.End()

    return open
end

function ImPlotDemo:Demo_Help()
    imgui.Text("ABOUT THIS DEMO:");
    imgui.BulletText("Sections below are demonstrating many aspects of the library.")
    imgui.BulletText("The \"Tools\" menu above gives access to: Style Editors (ImPlot/ImGui)\n" ..
                        "and Metrics (general purpose Dear ImGui debugging tool).");

    imgui.Separator()
    imgui.Text("USER GUIDE:")
    implot.ShowUserGuide();
end


--
-- Line Plots
--

local Demo_LinePlots_Data = {
    xs1 = {},
    ys1 = {},
    xs2 = {},
    ys2 = {},
}

function ImPlotDemo:Demo_LinePlots()
    local data = Demo_LinePlots_Data

    for i = 0, 1000 do
        local x = i * 0.001
        data.xs1[i+1] = x
        data.ys1[i+1] = 0.5 + 0.5 * math.sin(50 * (x + imgui.GetTime() / 10))
    end

    for i = 0, 19 do
        local x = i * 1/19.0
        data.xs2[i+1] = x
        data.ys2[i+1] = x * x
    end

    if implot.BeginPlot("Line Plots") then
        implot.SetupAxes('x', 'y')
        implot.PlotLine('f(x)', data.xs1, data.ys1, 1001)
        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.PlotLine('g(x)', data.xs2, data.ys2, 20, ImPlotLineFlags.Segments)

        implot.EndPlot()
    end
end

local Demo_FilledLinePlots_Data = {
    xs1 = {},
    ys1 = {},
    ys2 = {},
    ys3 = {},

    show_lines = true,
    show_fills = true,
    fill_ref = 0,
    shade_mode = 0,
    flags = ImPlotShadedFlags.None,
}

function ImPlotDemo:Demo_FilledLinePlots()
    local data = Demo_FilledLinePlots_Data
    math.randomseed(0)
    for i = 0, 100 do
        data.xs1[i+1] = i
        data.ys1[i+1] = RandomRange(400, 450)
        data.ys2[i+1] = RandomRange(275, 350)
        data.ys3[i+1] = RandomRange(150, 225)
    end

    data.show_lines = imgui.Checkbox("Lines", data.show_lines); imgui.SameLine()
    data.show_fills = imgui.Checkbox("Fills", data.show_fills)
    if data.show_fills then
        imgui.SameLine()
        if imgui.RadioButton('To -INF', data.shade_mode == 0) then
            data.shade_mode = 0
        end
        imgui.SameLine()
        if imgui.RadioButton('To +INF', data.shade_mode == 1) then
            data.shade_mode = 1
        end
        imgui.SameLine()
        if imgui.RadioButton('To Ref', data.shade_mode == 2) then
            data.shade_mode = 2
        end

        if data.shade_mode == 2 then
            imgui.SameLine()
            imgui.SetNextItemWidth(100)
            data.fill_ref = imgui.DragFloat("##Ref", data.fill_ref, 1, -100, 500)
        end
    end

    if implot.BeginPlot("Stock Prices") then
        implot.SetupAxes("Days", "Prices")
        implot.SetupAxesLimits(0, 100, 0, 500)

        if data.show_fills then
            implot.PushStyleVar(ImPlotStyleVar.FillAlpha, 0.25)
            local shade_mode = (data.shade_mode == 0 and -math.huge) or (data.shade_mode == 1 and math.huge) or data.fill_ref
            implot.PlotShaded("Stock 1", data.xs1, data.ys1, 101, shade_mode, data.flags)
            implot.PlotShaded("Stock 2", data.xs1, data.ys2, 101, shade_mode, data.flags)
            implot.PlotShaded("Stock 3", data.xs1, data.ys3, 101, shade_mode, data.flags)
            implot.PopStyleVar()
        end

        if data.show_lines then
            implot.PlotLine("Stock 1", data.xs1, data.ys1, 101)
            implot.PlotLine("Stock 2", data.xs1, data.ys2, 101)
            implot.PlotLine("Stock 3", data.xs1, data.ys3, 101)
        end
        implot.EndPlot()
    end
end

local Demo_ShadedPlots_Data = {
    xs = {},
    ys = {},
    ys1 = {},
    ys2 = {},
    ys3 = {},
    ys4 = {},

    alpha = .25,
    init = false
}

function ImPlotDemo:Demo_ShadedPlots()
    local data = Demo_ShadedPlots_Data

    if not data.init then
        data.init = true
        math.randomseed(0)

        for i = 0, 1000 do
            local x = i * 0.001
            data.xs[i+1] = x
            data.ys[i+1] = 0.25 + 0.25 * math.sin(25 * x) * math.sin(5 * x) + RandomRange(-0.01, 0.01);
            data.ys1[i+1] = data.ys[i+1] + RandomRange(0.1, 0.12)
            data.ys2[i+1] = data.ys[i+1] - RandomRange(0.1, 0.12)
            data.ys3[i+1] = 0.75 + 0.2 * math.sin(25 * x)
            data.ys4[i+1] = 0.75 + 0.1 * math.cos(25 * x)
        end
    end

    data.alpha = imgui.DragFloat("Alpha", data.alpha, 0.01, 0, 1)

    if implot.BeginPlot("Shaded Plots") then
        implot.PushStyleVar(ImPlotStyleVar.FillAlpha, data.alpha)
        implot.PlotShaded("Uncertain Data", data.xs, data.ys1, data.ys2, 1001)
        implot.PlotLine("Uncertain Data", data.xs, data.ys, 1001)

        implot.PlotShaded("Overlapping", data.xs, data.ys3, data.ys4, 1001)
        implot.PlotLine("Overlapping", data.xs, data.ys3, 1001)
        implot.PlotLine("Overlapping", data.xs, data.ys4, 1001)
        implot.PopStyleVar()
        implot.EndPlot()
    end
end

local Demo_ScatterPlots_Data = {
    xs1 = {},
    ys1 = {},
    xs2 = {},
    ys2 = {},
    init = false,
}

function ImPlotDemo:Demo_ScatterPlots()
    local data = Demo_ScatterPlots_Data

    if not data.init then
        data.init = true
        math.randomseed(0)

        for i = 0, 99 do
            local x = i * 0.01
            data.xs1[i+1] = x
            data.ys1[i+1] = x + 0.1 * math.random()
        end

        for i = 0, 49 do
            data.xs2[i+1] = .25 + 0.2 * math.random()
            data.ys2[i+1] = .75 + 0.2 * math.random()
        end
    end

    if implot.BeginPlot("Scatter Plot") then
        implot.PlotScatter("Data 1", data.xs1, data.ys1, 100)
        implot.PushStyleVar(ImPlotStyleVar.FillAlpha, 0.25)
        implot.SetNextMarkerStyle(ImPlotMarker.Square, 6, implot.GetColormapColor(1), IMPLOT_AUTO, implot.GetColormapColor(1))
        implot.PlotScatter("Data 2", data.xs2, data.ys2, 50)
        implot.PopStyleVar()
        implot.EndPlot()
    end
end

local Demo_StairstepPlots_Data = {
    ys1 = {},
    ys2 = {},
    flags = 0,
    init = false
}

function ImPlotDemo:Demo_StairstepPlots()
    local data = Demo_StairstepPlots_Data

    if not data.init then
        data.init = true
        for i = 0, 20 do
            data.ys1[i+1] = 0.75 + 0.2 * math.sin(10 * i * 0.05)
            data.ys2[i+1] = 0.25 + 0.2 * math.sin(10 * i * 0.05)
        end
    end

    data.flags = imgui.CheckboxFlags("ImPlotStairsFlags.Shaded", data.flags, ImPlotStairsFlags.Shaded)
    if implot.BeginPlot("Stairstep Plot") then
        implot.SetupAxes("x", "f(x)")
        implot.SetupAxesLimits(0, 1, 0, 1)

        implot.PushStyleColor(ImPlotCol.Line, ImVec4(0.5, 0.5, 0.5, 1.0))
        implot.PlotLine("##1", data.ys1, 21, 0.05)
        implot.PlotLine("##2", data.ys2, 21, 0.05)
        implot.PopStyleColor()

        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.SetNextFillStyle(IMPLOT_AUTO_COL, 0.25)
        implot.PlotStairs("Post Step (default)", data.ys1, 21, 0.05, 0, data.flags)
        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.SetNextFillStyle(IMPLOT_AUTO_COL, 0.25)
        implot.PlotStairs("Pre Step", data.ys2, 21, 0.05, 0, bit32.bor(data.flags, ImPlotStairsFlags.PreStep))

        implot.EndPlot()
    end
end

local Demo_BarPlots_Data = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
}

function ImPlotDemo:Demo_BarPlots()
    local data = Demo_BarPlots_Data

    if implot.BeginPlot("Bar Plot") then
        implot.PlotBars("Vertical", data, 10, 0.7, 1)
        implot.PlotBars("Horizontal", data, 10, 0.4, 1, ImPlotBarsFlags.Horizontal)
        implot.EndPlot()
    end
end

local Demo_BarGroups_Data = {
    data = {83, 67, 23, 89, 83, 78, 91, 82, 85, 90,  -- midterm
            80, 62, 56, 99, 55, 78, 88, 78, 90, 100, -- final
            80, 69, 52, 92, 72, 78, 75, 76, 89, 95}, -- course
    ilabels = {"Midterm Exam", "Final Exam", "Course Grade"},
    glabels = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10"},
    positions = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    items = 3,
    groups = 10,
    size = 0.67,
    flags = 0,
    horz = false
}

function ImPlotDemo:Demo_BarGroups()
    local data = Demo_BarGroups_Data

    data.flags = imgui.CheckboxFlags("Stacked", data.flags, ImPlotBarGroupsFlags.Stacked)
    imgui.SameLine()
    data.horz = imgui.Checkbox("Horizontal", data.horz)

    data.items = imgui.SliderInt("Items", data.items, 1, 3)
    data.size = imgui.SliderFloat("Size", data.size, 0, 1)

    if implot.BeginPlot("Bar Group") then
        implot.SetupLegend(ImPlotLocation.East, ImPlotLegendFlags.Outside)

        if data.horz then
            implot.SetupAxes("Score", "Student", ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.AutoFit)
            implot.SetupAxisTicks(ImAxis.Y1, data.positions, data.glabels)
            implot.PlotBarGroups(data.ilabels, data.data, data.items, data.groups, data.size, 0, bit32.bor(data.flags, ImPlotBarGroupsFlags.Horizontal))
        else
            implot.SetupAxes("Student", "Score", ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.AutoFit)
            implot.SetupAxisTicks(ImAxis.X1, data.positions, data.glabels)
            implot.PlotBarGroups(data.ilabels, data.data, data.items, data.groups, data.size, 0, data.flags)
        end

        implot.EndPlot()
    end
end

local Demo_BarStacks_Data = {
    Liars_Data = {4282515870, 4282609140, 4287357182, 4294630301, 4294945280, 4294921472},
    Liars = -1,

    diverging = true,
    politicians = {"Trump","Bachman","Cruz","Gingrich","Palin","Santorum","Walker","Perry","Ryan","McCain","Rubio","Romney","Rand Paul","Christie","Biden","Kasich","Sanders","J Bush","H Clinton","Obama"},
    data_reg = {18,26,7,14,10,8,6,11,4,4,3,8,6,8,6,5,0,3,1,2,                -- Pants on Fire
                43,36,30,21,30,27,25,17,11,22,15,16,16,17,12,12,14,6,13,12,  -- False
                16,13,28,22,15,21,15,18,30,17,24,18,13,10,14,15,17,22,14,12, -- Mostly False
                17,10,13,25,12,22,19,26,23,17,22,27,20,26,29,17,18,22,21,27, -- Half True
                5,7,16,10,10,12,23,13,17,20,22,16,23,19,20,26,36,29,27,26,   -- Mostly True
                1,8,6,8,23,10,12,15,15,20,14,15,22,20,19,25,15,18,24,21},    -- True
    labels_reg = {"Pants on Fire","False","Mostly False","Half True","Mostly True","True"},
    data_div = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                                         -- Pants on Fire (dummy, to order legend logically)
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                                         -- False         (dummy, to order legend logically)
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                                         -- Mostly False  (dummy, to order legend logically)
                -16,-13,-28,-22,-15,-21,-15,-18,-30,-17,-24,-18,-13,-10,-14,-15,-17,-22,-14,-12, -- Mostly False
                -43,-36,-30,-21,-30,-27,-25,-17,-11,-22,-15,-16,-16,-17,-12,-12,-14,-6,-13,-12,  -- False
                -18,-26,-7,-14,-10,-8,-6,-11,-4,-4,-3,-8,-6,-8,-6,-5,0,-3,-1,-2,                 -- Pants on Fire
                17,10,13,25,12,22,19,26,23,17,22,27,20,26,29,17,18,22,21,27,                     -- Half True
                5,7,16,10,10,12,23,13,17,20,22,16,23,19,20,26,36,29,27,26,                       -- Mostly True
                1,8,6,8,23,10,12,15,15,20,14,15,22,20,19,25,15,18,24,21},                        -- True
    labels_div = {"Pants on Fire","False","Mostly False","Mostly False","False","Pants on Fire","Half True","Mostly True","True"},
}

function ImPlotDemo:Demo_BarStacks()
    local data = Demo_BarStacks_Data

    if data.Liars == -1 then
        data.Liars = implot.AddColormap("Liars", data.Liars_Data)
    end

    data.diverging = imgui.Checkbox("Diverging", data.diverging)
    implot.PushColormap(data.Liars)
    if implot.BeginPlot("PolitiFact: Who Lies More?", ImVec2(-1, 400), ImPlotFlags.NoMouseText) then
        implot.SetupLegend(ImPlotLocation.South, bit32.bor(ImPlotLegendFlags.Outside, ImPlotLegendFlags.Horizontal))
        implot.SetupAxes(nil, nil, bit32.bor(ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.NoDecorations), bit32.bor(ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.Invert))
        implot.SetupAxisTicks(ImAxis.Y1, 0, 19, 20, data.politicians, false)
        if data.diverging then
            implot.PlotBarGroups(data.labels_div, data.data_div, 9, 20, 0.75, 0, bit32.bor(ImPlotBarGroupsFlags.Stacked, ImPlotBarGroupsFlags.Horizontal))
        else
            implot.PlotBarGroups(data.labels_reg, data.data_reg, 6, 20, 0.75, 0, bit32.bor(ImPlotBarGroupsFlags.Stacked, ImPlotBarGroupsFlags.Horizontal))
        end
        implot.EndPlot()
    end

    implot.PopColormap()
end

local Demo_ErrorBars_Data = {
    xs = {1,2,3,4,5},
    bar = {1,2,5,3,4},
    lin1 = {8,8,9,7,8},
    lin2 = {6,7,6,9,6},
    err1 = {0.2, 0.4, 0.2, 0.6, 0.4},
    err2 = {0.4, 0.2, 0.4, 0.8, 0.6},
    err3 = {0.09, 0.14, 0.09, 0.12, 0.16},
    err4 = {0.02, 0.08, 0.15, 0.05, 0.2},
}

function ImPlotDemo:Demo_ErrorBars()
    local data = Demo_ErrorBars_Data

    if implot.BeginPlot("##ErrorBars") then
        implot.SetupAxesLimits(0, 6, 0, 10)
        implot.PlotBars("Bar", data.xs, data.bar, 5, 0.5)
        implot.PlotErrorBars("Bar", data.xs, data.bar, data.err1, 5)
        implot.SetNextErrorBarStyle(implot.GetColormapColor(1), 0)
        implot.PlotErrorBars("Line", data.xs, data.lin1, data.err1, data.err2, 5)
        implot.SetNextMarkerStyle(ImPlotMarker.Square)
        implot.PlotLine("Line", data.xs, data.lin1, 5)
        implot.PushStyleColor(ImPlotCol.ErrorBar, implot.GetColormapColor(2))
        implot.PlotErrorBars("Scatter", data.xs, data.lin2, data.err2, 5)
        implot.PlotErrorBars("Scatter", data.xs, data.lin2, data.err3, data.err4, 5, ImPlotErrorBarsFlags.Horizontal)
        implot.PopStyleColor()
        implot.PlotScatter("Scatter", data.xs, data.lin2, 5)
        implot.EndPlot()
    end
end

local Demo_StemPlots_Data = {
    xs = {},
    ys1 = {},
    ys2 = {},
    init = false,
}

function ImPlotDemo:Demo_StemPlots()
    local data = Demo_StemPlots_Data

    if not data.init then
        data.init = true
        for i = 0, 50 do
            local x = i * 0.02
            data.xs[i+1] = x
            data.ys1[i+1] = 1.0 + 0.5 * math.sin(25 * x) * math.cos(2 * x);
            data.ys2[i+1] = 0.5 + 0.25  * math.sin(10 * x) * math.sin(x);
        end
    end

    if implot.BeginPlot("Stem Plots") then
        implot.SetupAxisLimits(ImAxis.X1, 0, 1.0)
        implot.SetupAxisLimits(ImAxis.Y1, 0, 1.6)
        implot.PlotStems("Stems 1", data.xs, data.ys1, 51)
        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.PlotStems("Stems 2", data.xs, data.ys2, 51)
        implot.EndPlot()
    end
end

local Demo_InfiniteLines_Data = {
    vals = {0.25, 0.5, 0.75}
}

function ImPlotDemo:Demo_InfiniteLines()
    local data = Demo_InfiniteLines_Data

    if implot.BeginPlot("##Infinite") then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoInitialFit, ImPlotAxisFlags.NoInitialFit)
        implot.PlotInfLines("Vertical", data.vals, 3)
        implot.PlotInfLines("Horizontal", data.vals, 3, ImPlotInfLinesFlags.Horizontal)
        implot.EndPlot()
    end
end

local Demo_PieCharts_Data = {
    labels1 = {"Frogs","Hogs","Dogs","Logs"},
    data1   = {0.15,  0.30,  0.2, 0.05},
    labels2 = {"A","B","C","D","E"},
    data2   = {1,1,2,3,5},
    flags = 0
}

function ImPlotDemo:Demo_PieCharts()
    local data = Demo_PieCharts_Data

    imgui.SetNextItemWidth(250)
    data.data1 = imgui.DragFloat4("Values", data.data1, 0.01, 1)
    data.flags = imgui.CheckboxFlags("ImPlotPieChartFlags.Normalize", data.flags, ImPlotPieChartFlags.Normalize)
    data.flags = imgui.CheckboxFlags("ImPlotPieChartFlags.IgnoreHidden", data.flags, ImPlotPieChartFlags.IgnoreHidden)

    if implot.BeginPlot("##Pei1", ImVec2(250, 250), bit32.bor(ImPlotFlags.Equal, ImPlotFlags.NoMouseText)) then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoDecorations, ImPlotAxisFlags.NoDecorations)
        implot.SetupAxesLimits(0, 1, 0, 1)
        implot.PlotPieChart(data.labels1, data.data1, 4, 0.5, 0.5, 0.4, "%.2f", 90, data.flags)
        implot.EndPlot()
    end

    imgui.SameLine()

    implot.PushColormap(ImPlotColormap.Pastel)
    if implot.BeginPlot("##Pie2", ImVec2(250, 250), bit32.bor(ImPlotFlags.Equal, ImPlotFlags.NoMouseText)) then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoDecorations, ImPlotAxisFlags.NoDecorations)
        implot.SetupAxesLimits(0, 1, 0, 1)
        implot.PlotPieChart(data.labels2, data.data2, 5, 0.5, 0.5, 0.4, "%.0f", 180, data.flags)
        implot.EndPlot()
    end
    implot.PopColormap()
end

local Demo_Heatmaps_Data = {
    values1         = {0.8, 2.4, 2.5, 3.9, 0.0, 4.0, 0.0,
                       2.4, 0.0, 4.0, 1.0, 2.7, 0.0, 0.0,
                       1.1, 2.4, 0.8, 4.3, 1.9, 4.4, 0.0,
                       0.6, 0.0, 0.3, 0.0, 3.1, 0.0, 0.0,
                       0.7, 1.7, 0.6, 2.6, 2.2, 6.2, 0.0,
                       1.3, 1.2, 0.0, 0.0, 0.0, 3.2, 5.1,
                       0.1, 2.0, 0.0, 1.4, 0.0, 1.9, 6.3},
    scale_min       = 0,
    scale_max       = 6.3,
    xlabels         = {"C1","C2","C3","C4","C5","C6","C7"},
    ylabels         = {"R1","R2","R3","R4","R5","R6","R7"},
    map             = ImPlotColormap.Viridis,
    hm_flags        = 0,
    axes_flags      = bit32.bor(ImPlotAxisFlags.Lock, ImPlotAxisFlags.NoGridLines, ImPlotAxisFlags.NoTickMarks),

    size            = 80,
    values2         = {},
}

function ImPlotDemo:Demo_Heatmaps()
    local data = Demo_Heatmaps_Data

    if implot.ColormapButton(implot.GetColormapName(data.map), ImVec2(225, 0), data.map) then
        data.map = math.fmod(data.map, implot.GetColormapCount())

        -- We bust the color cache of our plots so that item colors will
        -- resample the new colormap in the event that they have already
        -- been created. See documentation in implot.h
        implot.BustColorCache("##Heatmap1")
        implot.BustColorCache("##Heatmap2")
    end

    imgui.SameLine()
    imgui.LabelText("##Colormap Index", "%s", "Change Colormap")
    imgui.SetNextItemWidth(225)
    data.scale_min, data.scale_max = imgui.DragFloatRange2("Min / Max", data.scale_min, data.scale_max, 0.01, -20, 20)

    data.hm_flags = imgui.CheckboxFlags("Column Major", data.hm_flags, ImPlotHeatmapFlags.ColMajor)

    implot.PushColormap(data.map)

    if implot.BeginPlot("##Heatmap1", ImVec2(225, 225), bit32.bor(ImPlotFlags.NoLegend, ImPlotFlags.NoMouseText)) then
        implot.SetupAxes(nil, nil, data.axes_flags, data.axes_flags)
        implot.SetupAxisTicks(ImAxis.X1, 0 + 1.0 / 14.0, 1 - 1.0 / 14.0, 7, data.xlabels)
        implot.SetupAxisTicks(ImAxis.Y1, 1 - 1.0 / 14.0, 0 + 1.0 / 14.0, 7, data.ylabels)
        implot.PlotHeatmap("heat", data.values1, 7, 7, data.scale_min, data.scale_max, "%g", ImPlotPoint(0, 0), ImPlotPoint(1, 1), data.hm_flags)
        implot.EndPlot()
    end

    imgui.SameLine()
    implot.ColormapScale("##HeadScale", data.scale_min, data.scale_max, ImVec2(60, 226))

    imgui.SameLine()

    math.randomseed(imgui.GetTime() * 1000000)
    for i = 1, data.size * data.size do
        data.values2[i] = RandomRange(0.0, 1.0)
    end

    if implot.BeginPlot("##Heatmap2", ImVec2(225, 225)) then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoDecorations, ImPlotAxisFlags.NoDecorations)
        implot.SetupAxesLimits(-1, 1, -1, 1)
        implot.PlotHeatmap("heat1", data.values2, data.size, data.size, 0, 1, "")
        implot.PlotHeatmap("heat2", data.values2, data.size, data.size, 0, 1, "", ImPlotPoint(-1, -1), ImPlotPoint(0, 0))
        implot.EndPlot()
    end

    implot.PopColormap()
end

local Demo_Histogram_Data = {
    hist_flags = ImPlotHistogramFlags.Density,
    bins = 50,
    mu = 5,
    sigma = 2,
    range = false,
    r = {-3, 13},
    dist = NormalDistribution(5, 2, 10000),
    x = {},
    y = {},
}

function ImPlotDemo:Demo_Histogram()
    local data = Demo_Histogram_Data

    imgui.SetNextItemWidth(200)

    if imgui.RadioButton("Sqrt", data.bins == ImPlotBin.Sqrt) then
        data.bins = ImPlotBin.Sturges
    end
    imgui.SameLine()
    if imgui.RadioButton("Sturges", data.bins == ImPlotBin.Sturges) then
        data.bins = ImPlotBin.Sturges
    end
    imgui.SameLine()
    if imgui.RadioButton("Rice", data.bins == ImPlotBin.Rice) then
        data.bins = ImPlotBin.Rice
    end
    imgui.SameLine()
    if imgui.RadioButton("Scott", data.bins == ImPlotBin.Scott) then
        data.bins = ImPlotBin.Scott
    end
    imgui.SameLine()
    if imgui.RadioButton("N Bins", data.bins >= 0) then
        data.bins = 50
    end

    if data.bins >= 0 then
        imgui.SameLine()
        imgui.SetNextItemWidth(200)
        data.bins = imgui.SliderInt("##Bins", data.bins, 1, 100)
    end

    data.hist_flags = imgui.CheckboxFlags("Horizontal", data.hist_flags, ImPlotHistogramFlags.Horizontal); imgui.SameLine()
    data.hist_flags = imgui.CheckboxFlags("Density", data.hist_flags, ImPlotHistogramFlags.Density); imgui.SameLine()
    data.hist_flags = imgui.CheckboxFlags("Cumulative", data.hist_flags, ImPlotHistogramFlags.Cumulative)

    data.range = imgui.Checkbox("Range", data.range)
    if data.range then
        imgui.SameLine()
        imgui.SetNextItemWidth(200)
        data.r = imgui.DragFloat2("##Range", data.r, 0.1, -3, 13)
        imgui.SameLine()
        data.hist_flags = imgui.CheckboxFlags("Exclude Outliers", data.hist_flags, ImPlotHistogramFlags.NoOutliers)
    end

    if bit32.band(data.hist_flags, ImPlotHistogramFlags.Density) ~= 0 then
        for i = 1, 100 do
            local x = -3 + 16 * i/99.0
            data.x[i] = x;
            data.y[i] = math.exp(-(x-data.mu)*(x-data.mu) / (2*data.sigma*data.sigma)) / (data.sigma * math.sqrt(2*3.141592653589793238));
        end
        if bit32.band(data.hist_flags, ImPlotHistogramFlags.Cumulative) ~= 0 then
            for i = 2, 100 do
                data.y[i] = data.y[i] + data.y[i-1];
            end
            for i = 1, 100 do
                data.y[i] = data.y[i] / data.y[100];
            end
        end
    end

    if implot.BeginPlot("##Histograms") then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.AutoFit)
        implot.SetNextFillStyle(IMPLOT_AUTO_COL, 0.5)
        implot.PlotHistogram("Empirical", data.dist, data.bins, 1.0, data.range and ImPlotRange(data.r[1], data.r[2]) or ImPlotRange(), data.hist_flags)

        if bit32.band(data.hist_flags, ImPlotHistogramFlags.Density) ~= 0 and bit32.band(data.hist_flags, ImPlotHistogramFlags.NoOutliers) == 0 then
            if bit32.band(data.hist_flags, ImPlotHistogramFlags.Horizontal) ~= 0 then
                implot.PlotLine("Theoretical", data.y, data.x, 100)
            else
                implot.PlotLine("Theoretical", data.x, data.y, 100)
            end
        end

        implot.EndPlot()
    end
end

local Demo_Histogram2D_Data = {
    count = 50000,
    xybins = {100, 100},
    hist_flags = 0,
    dist1 = NormalDistribution(1, 2, 100000),
    dist2 = NormalDistribution(1, 1, 100000),
    max_count = 0,
}

function ImPlotDemo:Demo_Histogram2D()
    local data = Demo_Histogram2D_Data

    data.count = imgui.SliderInt("Count", data.count, 100, 100000)
    data.xybins = imgui.SliderInt2("Bins", data.xybins, 1, 500)
    imgui.SameLine()
    data.hist_flags = imgui.CheckboxFlags("Density", data.hist_flags, ImPlotHistogramFlags.Density)

    local flags = bit32.bor(ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.Foreground)
    implot.PushColormap("Hot")
    if implot.BeginPlot("##Hist2D", ImVec2(imgui.GetContentRegionAvailVec().x - 100 - imgui.GetStyle().ItemSpacing.x, 0)) then
        implot.SetupAxes(nil, nil, flags, flags)
        implot.SetupAxesLimits(-6, 6, -6, 6)
        data.max_count = implot.PlotHistogram2D("Hist2D", data.dist1, data.dist2, data.count, data.xybins[1], data.xybins[2], ImPlotRect(-6, 6, -6, 6), data.hist_flags)
        implot.EndPlot()
    end
    imgui.SameLine()
    implot.ColormapScale(bit32.band(data.hist_flags, ImPlotHistogramFlags.Density) ~= 0 and "Density" or "Count", 0, data.max_count, ImVec2(100, 0))

    implot.PopColormap()
end

local Demo_DigitalPlots_Data = {
    paused = false,
    dataDigital = { ScrollingBuffer:new(), ScrollingBuffer:new() },
    dataAnalog = { ScrollingBuffer:new(), ScrollingBuffer:new() },
    showDigital = { true, false },
    showAnalog = { true, false },
    t = 0,
}

function ImPlotDemo:Demo_DigitalPlots()
    local data = Demo_DigitalPlots_Data

    imgui.BulletText("Digital plots do not respond to Y drag and zoom, so that")
    imgui.Indent()
    imgui.Text("you can drag analog plots over the rising/falling digital edge.")
    imgui.Unindent()

    data.showDigital[1] = imgui.Checkbox("digital_0", data.showDigital[1]); imgui.SameLine()
    data.showDigital[2] = imgui.Checkbox("digital_1", data.showDigital[2]); imgui.SameLine()
    data.showAnalog[1] = imgui.Checkbox("analog_0", data.showAnalog[1]); imgui.SameLine()
    data.showAnalog[2] = imgui.Checkbox("analog_1", data.showAnalog[2])

    if not data.paused then
        data.t = data.t + imgui.GetIO().DeltaTime

        -- digital signal values
        if data.showDigital[1] then
            data.dataDigital[1]:AddPoint(data.t, math.sin(2 * data.t) > 0.45 and 1 or 0)
        end
        if data.showDigital[2] then
            data.dataDigital[2]:AddPoint(data.t, math.sin(2 * data.t) < 0.45 and 1 or 0)
        end

        -- analog signal values
        if data.showAnalog[1] then
            data.dataAnalog[1]:AddPoint(data.t, math.sin(2 * data.t))
        end
        if data.showAnalog[2] then
            data.dataAnalog[2]:AddPoint(data.t, math.cos(2 * data.t))
        end
    end

    if implot.BeginPlot("##Digital") then
        implot.SetupAxisLimits(ImAxis.X1, data.t - 10.0, data.t, data.paused and ImGuiCond.Once or ImGuiCond.Always)
        implot.SetupAxisLimits(ImAxis.Y1, -1, 1)

        for i = 1, 2 do
            if data.showDigital[i] and #data.dataDigital[i].DataX > 0 then
                implot.PlotDigital(string.format("digital_%d", i - 1), data.dataDigital[i].DataX, data.dataDigital[i].DataY, #data.dataDigital[i].DataX, 0, data.dataDigital[i].Offset - 1)
            end
        end

        for i = 1, 2 do
            if data.showAnalog[i] and #data.dataAnalog[i].DataX > 0 then
                implot.PlotLine(string.format("analog_%d", i - 1), data.dataAnalog[i].DataX, data.dataAnalog[i].DataY, #data.dataAnalog[i].DataX, 0, data.dataAnalog[i].Offset - 1)
            end
        end

        implot.EndPlot()
    end
end

local Demo_Images_Data = {
    bmin = ImVec2(0, 0),
    bmax = ImVec2(1, 1),
    uv0 = ImVec2(0, 0),
    uv1 = ImVec2(1, 1),
    tint = ImVec4(1, 1, 1, 1)
}

function ImPlotDemo:Demo_Images()
    local data = Demo_Images_Data

    imgui.BulletText("Below we are displaying the font texture, which is the only texture we have\naccess to in this demo.")
    imgui.BulletText("Use the 'ImTextureID' type as storage to pass pointers or identifiers to your\nown texture data.")
    imgui.BulletText("See ImGui Wiki page 'Image Loading and Displaying Examples'.")

    data.bmin = imgui.SliderFloatVec2("Min", data.bmin, -2, 2, "%.1f")
    data.bmax = imgui.SliderFloatVec2("Max", data.bmax, -2, 2, "%.1f")
    data.uv0 = imgui.SliderFloatVec2("UV0", data.uv0, -2, 2, "%.1f")
    data.uv1 = imgui.SliderFloatVec2("UV1", data.uv1, -2, 2, "%.1f")
    data.tint = imgui.ColorEdit4("Tint", data.tint)

    if implot.BeginPlot("##image") then
        implot.PlotImage("my image", imgui.GetIO().Fonts.TexID, ImPlotPoint(data.bmin), ImPlotPoint(data.bmax), data.uv0, data.uv1, data.tint)
        implot.EndPlot()
    end
end

local Demo_RealtimePlots_Data = {
    sdata1 = ScrollingBuffer:new(),
    sdata2 = ScrollingBuffer:new(),
    rdata1 = RollingBuffer:new(),
    rdata2 = RollingBuffer:new(),
    t = 0,
    history = 10.0,
    flags = ImPlotAxisFlags.NoTickLabels,
}

function ImPlotDemo:Demo_RealtimePlots()
    local data = Demo_RealtimePlots_Data

    imgui.BulletText("Move your mouse to change the data!")
    imgui.BulletText("This example assumes 60 FPS. Higher FPS requires larger buffer size.")

    local mouse = imgui.GetMousePosVec()
    data.t = data.t + imgui.GetIO().DeltaTime
    data.sdata1:AddPoint(data.t, mouse.x * 0.0005)
    data.rdata1:AddPoint(data.t, mouse.x * 0.0005)
    data.sdata2:AddPoint(data.t, mouse.y * 0.0005)
    data.rdata2:AddPoint(data.t, mouse.y * 0.0005)

    data.history = imgui.SliderFloat("History", data.history, 1, 30, "%.1f s")
    data.rdata1.Span = data.history
    data.rdata2.Span = data.history

    if implot.BeginPlot("##Scrolling", ImVec2(-1, 150)) then
        implot.SetupAxes(nil, nil, data.flags, data.flags)
        implot.SetupAxisLimits(ImAxis.X1, data.t - data.history, data.t, ImGuiCond.Always)
        implot.SetupAxisLimits(ImAxis.Y1, 0, 1)
        implot.SetNextFillStyle(IMPLOT_AUTO_COL, 0.5)
        implot.PlotShaded("Mouse X", data.sdata1.DataX, data.sdata1.DataY, #data.sdata1.DataX, -math.huge, 0, data.sdata1.Offset - 1)
        implot.PlotLine("Mouse Y", data.sdata2.DataX, data.sdata2.DataY, #data.sdata2.DataX, 0, data.sdata2.Offset - 1)
        implot.EndPlot()
    end

    if implot.BeginPlot("##Rolling", ImVec2(-1, 150)) then
        implot.SetupAxes(nil, nil, data.flags, data.flags)
        implot.SetupAxisLimits(ImAxis.X1, 0, data.history, ImGuiCond.Always)
        implot.SetupAxisLimits(ImAxis.Y1, 0, 1)
        implot.PlotLine("Mouse X", data.rdata1.DataX, data.rdata1.DataY, #data.rdata1.DataX, 0, 0)
        implot.PlotLine("Mouse Y", data.rdata2.DataX, data.rdata2.DataY, #data.rdata2.DataX, 0, 0)
        implot.EndPlot()
    end
end

local Demo_MarkersAndText_Data = {
    mk_size = implot.GetStyle().MarkerSize,
    mk_weight = implot.GetStyle().MarkerWeight,
}

function ImPlotDemo:Demo_MarkersAndText()
    local data = Demo_MarkersAndText_Data

    data.mk_size = imgui.DragFloat("Marker Size", data.mk_size, 0.1, 2.0, 10.0, "%.2f px")
    data.mk_weight = imgui.DragFloat("Marker Weight", data.mk_weight, 0.05, 0.5, 3.0, "%.2f px")

    if implot.BeginPlot("##MarkerStyles", ImVec2(-1, 0), ImPlotFlags.CanvasOnly) then
        implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoDecorations, ImPlotAxisFlags.NoDecorations)
        implot.SetupAxesLimits(0, 10, 0, 12)

        local xs = {1, 4}
        local ys = {10, 11}

        for m = 0, ImPlotMarker.COUNT - 1 do
            imgui.PushID(m)
            implot.SetNextMarkerStyle(m, data.mk_size, IMPLOT_AUTO_COL, data.mk_weight)
            implot.PlotLine("##Filled", xs, ys, 2)
            imgui.PopID()

            ys[1] = ys[1] - 1
            ys[2] = ys[2] - 1
        end

        xs = {6, 9}
        ys = {10, 11}

        for m = 0, ImPlotMarker.COUNT - 1 do
            imgui.PushID(m)
            implot.SetNextMarkerStyle(m, data.mk_size, ImVec4(0, 0, 0, 0), data.mk_weight)
            implot.PlotLine("##Open", xs, ys, 2)
            imgui.PopID()

            ys[1] = ys[1] - 1
            ys[2] = ys[2] - 1
        end

        implot.PlotText("Filled Markers", 2.5, 6.0)
        implot.PlotText("Open Markers", 7.5, 6.0)

        implot.PushStyleColor(ImPlotCol.InlayText, ImVec4(1, 0, 1, 1))
        implot.PlotText("Vertical Text", 5.0, 6.0, ImVec2(0, 0), ImPlotTextFlags.Vertical)
        implot.PopStyleColor()
        implot.EndPlot()
    end
end

local Demo_NaNValues_Data = {
    include_nan = true,
    flags = 0,
    data1 = {0.0, 0.25, 0.5, 0.75, 1.0},
    data2 = {0.0, 0.25, 0.5, 0.75, 1.0},
}

function ImPlotDemo:Demo_NaNValues()
    local data = Demo_NaNValues_Data

    if data.include_nan then
        data.data1[3] = 0/0
    else
        data.data1[3] = 0.5
    end

    data.include_nan = imgui.Checkbox("Include NaN", data.include_nan)
    imgui.SameLine()
    data.flags = imgui.CheckboxFlags("Skip NaN", data.flags, ImPlotLineFlags.SkipNaN)

    if implot.BeginPlot("##NaNValues") then
        implot.SetNextMarkerStyle(ImPlotMarker.Square)
        implot.PlotLine("line", data.data1, data.data2, 5, data.flags)
        implot.PlotBars("bars", data.data1, 5)
        implot.EndPlot()
    end
end

local Demo_SubplotsSizing_Data = {
    flags = bit32.bor(ImPlotSubplotFlags.ShareItems, ImPlotSubplotFlags.NoLegend),
    rows = 3,
    cols = 3,
    rratios = {5, 1, 1, 1, 1, 1},
    cratios = {5, 1, 1, 1, 1, 1},
}

---@param idx number
---@param fi number
---@return ImPlotPoint
function SinewaveGetter(idx, fi)
    return ImPlotPoint(idx, math.sin(fi * idx * 10))
end

function ImPlotDemo:Demo_SubplotsSizing()
    local data = Demo_SubplotsSizing_Data

    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.NoResize", data.flags, ImPlotSubplotFlags.NoResize)
    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.NoTitle", data.flags, ImPlotSubplotFlags.NoTitle)

    data.rows = imgui.SliderInt("Rows", data.rows, 1, 5)
    data.cols = imgui.SliderInt("Cols", data.cols, 1, 5)
    if data.rows < 1 or data.cols < 1 then
        imgui.TextColored(ImVec4(1, 0, 0, 1), "Nice try, but the number of rows and columns must be greater than 0!")
        return
    end

    data.rratios = imgui.DragScalarN("Row Ratios", ImGuiDataType.Float, data.rratios, data.rows, 0.01)
    data.cratios = imgui.DragScalarN("Col Ratios", ImGuiDataType.Float, data.cratios, data.cols, 0.01)
    if implot.BeginSubplots("My Subplots", data.rows, data.cols, ImVec2(-1, 400), data.flags, data.rratios, data.cratios) then
        local id = 0
        for i = 1, data.rows * data.cols do
            if implot.BeginPlot("", ImVec2(), ImPlotFlags.NoLegend) then
                implot.SetupAxes(nil, nil, ImPlotAxisFlags.NoDecorations, ImPlotAxisFlags.NoDecorations)
                local fi = 0.01 * i
                if data.rows * data.cols > 1 then
                    implot.SetNextLineStyle(implot.SampleColormap(i / (data.rows * data.cols - 1), ImPlotColormap.Jet))
                end
                local label = string.format("data%d", id)
                implot.PlotLine(label, function(idx) return SinewaveGetter(idx, fi) end, 100)
                implot.EndPlot()
            end
        end
        implot.EndSubplots()
    end
end

local Demo_SubplotItemSharing_Data = {
    flags = ImPlotSubplotFlags.ShareItems,
    rows = 2,
    cols = 3,
    id = {1, 2, 3, 4, 5, 6},
    curj = -1,
}

function ImPlotDemo:Demo_SubplotItemSharing()
    local data = Demo_SubplotItemSharing_Data

    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.ShareItems", data.flags, ImPlotSubplotFlags.ShareItems)
    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.ColMajor", data.flags, ImPlotSubplotFlags.ColMajor)

    imgui.BulletText("Drag and drop items from the legend onto plots (except for 'common')")

    if implot.BeginSubplots("##ItemSharing", data.rows, data.cols, ImVec2(-1, 400), data.flags) then
        implot.SetupLegend(ImPlotLocation.South, bit32.bor(ImPlotLegendFlags.Sort, ImPlotLegendFlags.Horizontal))

        for i = 1, data.rows * data.cols do
            if implot.BeginPlot("") then
                local fc = 0.01
                implot.PlotLine("common", function(idx) return SinewaveGetter(idx, fc) end, 100)
                for j = 1, 6 do
                    if data.id[j] == i then
                        local fj = 0.01 * (j + 2)
                        local label = string.format("data%d", j)
                        implot.PlotLine(label, function(idx) return SinewaveGetter(idx, fj) end, 100)
                        if implot.BeginDragDropSourceItem(label) then
                            data.curj = j
                            imgui.SetDragDropPayload("MY_DND", nil, 0)
                            implot.ItemIcon(implot.GetLastItemColor()); imgui.SameLine()
                            imgui.TextUnformatted(label)
                            implot.EndDragDropSource()
                        end
                    end
                end
                if implot.BeginDragDropTargetPlot() then
                    if imgui.AcceptDragDropPayload("MY_DND") then
                        data.id[data.curj] = i
                    end
                    implot.EndDragDropTarget()
                end
                implot.EndPlot()
            end
        end

        implot.EndSubplots()
    end
end

local Demo_SubplotAxisLinking_Data = {
    flags = bit32.bor(ImPlotSubplotFlags.LinkRows, ImPlotSubplotFlags.LinkCols),
    rows = 2,
    cols = 2,
}

function ImPlotDemo:Demo_SubplotAxisLinking()
    local data = Demo_SubplotAxisLinking_Data

    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.LinkRows", data.flags, ImPlotSubplotFlags.LinkRows)
    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.LinkCols", data.flags, ImPlotSubplotFlags.LinkCols)
    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.LinkAllX", data.flags, ImPlotSubplotFlags.LinkAllX)
    data.flags = imgui.CheckboxFlags("ImPlotSubplotFlags.LinkAllY", data.flags, ImPlotSubplotFlags.LinkAllY)

    if implot.BeginSubplots("##AxisLinking", data.rows, data.cols, ImVec2(-1, 400), data.flags) then
        for i = 1, data.rows * data.cols do
            if implot.BeginPlot("") then
                implot.SetupAxesLimits(0, 100, -1, 1)
                implot.PlotLine("common", function(idx) return SinewaveGetter(idx, 0.01) end, 100)
                implot.EndPlot()
            end
        end
        implot.EndSubplots()
    end
end

local Demo_Tables_Data = {
    flags = bit32.bor(ImGuiTableFlags.BordersOuter, ImGuiTableFlags.BordersV,
        ImGuiTableFlags.RowBg, ImGuiTableFlags.Resizable, ImGuiTableFlags.Reorderable),
    anim = true,
    offset = 0,
    data = {}
}

function ImPlotDemo:Demo_Tables()
    local data = Demo_Tables_Data

    imgui.BulletText("Plots can be used inside of ImGui tables as another means of creating subplots.")
    data.anim = imgui.Checkbox("Animate", data.anim)

    if data.anim then
        data.offset = (data.offset + 1) % 100
    end

    if imgui.BeginTable("##table", 3, data.flags, ImVec2(-1, 0)) then
        imgui.TableSetupColumn("Electrode", ImGuiTableColumnFlags.WidthFixed, 75.0)
        imgui.TableSetupColumn("Voltage", ImGuiTableColumnFlags.WidthFixed, 75.0)
        imgui.TableSetupColumn("EMG Signal")
        imgui.TableHeadersRow()

        implot.PushColormap(ImPlotColormap.Cool)
        for row = 1, 10 do
            imgui.TableNextRow()
            math.randomseed(row)
            for i = 1, 100 do
                data.data[i] = math.random(0, 10)
            end
            imgui.TableSetColumnIndex(0)
            imgui.Text("EMG %d", row)
            imgui.TableSetColumnIndex(1)
            imgui.Text("%.3f V", data.data[data.offset + 1])
            imgui.TableSetColumnIndex(2)
            imgui.PushID(row)
            Sparkline("##spark", data.data, 0, 11, data.offset, implot.GetColormapColor(row), ImVec2(-1, 35))
            imgui.PopID()
        end
        implot.PopColormap()
        imgui.EndTable()
    end
end

local Demo_LogScale_Data = {
    xs = {},
    ys1 = {},
    ys2 = {},
    ys3 = {},
    init = false
}

function ImPlotDemo:Demo_LogScale()
    local data = Demo_LogScale_Data

    if not data.init then
        data.init = true

        for i = 1, 1001 do
            local x = i * 0.1
            data.xs[i] = x
            data.ys1[i] = math.sin(x) + 1
            data.ys2[i] = math.log(x)
            data.ys3[i] = math.pow(1.0, x)
        end
    end

    if implot.BeginPlot("Log Plot", ImVec2(-1, 0)) then
        implot.SetupAxisScale(ImAxis.X1, ImPlotScale.Log10)
        implot.SetupAxesLimits(0.1, 100, 0, 10)
        implot.PlotLine("f(x) = x", data.xs, data.xs, 1001)
        implot.PlotLine("f(x) = sin(x) + 1", data.xs, data.ys1, 1001)
        implot.PlotLine("f(x) = log(x)", data.xs, data.ys2, 1001)
        implot.PlotLine("f(x) = 10^x", data.xs, data.ys3, 1001)
        implot.EndPlot()
    end
end

local Demo_SymmetricLogScale_Data = {
    xs = {},
    ys1 = {},
    ys2 = {},
    init = false,
}

function ImPlotDemo:Demo_SymmetricLogScale()
    local data = Demo_SymmetricLogScale_Data

    if not data.init then
        data.init = true
        for i = 1, 1001 do
            data.xs[i] = i * 0.1 - 50
            data.ys1[i] = math.sin(data.xs[i])
            data.ys2[i] = i * 0.002 - 1
        end
    end

    if implot.BeginPlot("SymLog Plot", ImVec2(-1, 0)) then
        implot.SetupAxisScale(ImAxis.X1, ImPlotScale.SymLog)
        implot.PlotLine("f(x) = a*x + b", data.xs, data.ys2, 1001)
        implot.PlotLine("f(x) = sin(x)", data.xs, data.ys1, 1001)
        implot.EndPlot()
    end
end

local Demo_TimeScale_Data = {
    t_min = 1609459200, -- 01/01/2021 @ 12:00:00am (UTC)
    t_max = 1640995200, -- 01/01/2022 @ 12:00:00am (UTC)
    init = false,
    data = {
        Ts = {},
        Ys = {},
    },
    size = 60 * 60 * 24 * 366,

    GetY = function (t)
        return 0.5 + 0.25 * math.sin(t / 86400 / 12) + 0.005 * math.sin(t / 3600)
    end
}

function ImPlotDemo:Demo_TimeScale()
    local data = Demo_TimeScale_Data

    -- if not data.init then
    --     data.init = true

    --     local Ts = {}
    --     local Ys = {}

    --     for i = 1, data.size do
    --         Ts[i] = data.t_min + i
    --         Ys[i] = data.GetY(Ts[i])
    --     end

    --     data.Ts = slice.make(double_t, Ts)
    --     data.Ys = slice.make(double_t, Ys)
    -- end

    imgui.BulletText("When ImPlotAxisFlags_Time is enabled on the X-Axis, values are interpreted as\n" ..
                     "UNIX timestamps in seconds and axis labels are formated as date/time.")
    imgui.BulletText("By default, labels are in UTC time but can be set to use local time instead.")

    local Style = implot.GetStyle()

    Style.UseLocalTime = imgui.Checkbox("Local Time", Style.UseLocalTime)
    imgui.SameLine()
    Style.UseISO8601 = imgui.Checkbox("ISO 8601", Style.UseISO8601)
    imgui.SameLine()
    Style.Use24HourClock = imgui.Checkbox("24 Hour CLock", Style.Use24HourClock)

    if implot.BeginPlot("##Time", ImVec2(-1, 0)) then
        implot.SetupAxisScale(ImAxis.X1, ImPlotScale.Time)
        implot.SetupAxesLimits(data.t_min, data.t_max, 0, 1)

        imgui.Text("Not Implemented")
        --
        -- TODO: Its just too big right now. Need a native collection type
        --

        -- -- downsample data
        -- local downsample = implot.GetPlotLimits().X:Size() / 1000 + 1
        -- local start = math.floor(implot.GetPlotLimits().X.Min) - data.t_min
        -- start = start < 0 and 0 or (start > data.size and data.size or start)
        -- local end_ = math.floor(implot.GetPlotLimits().X.Max) - data.t_min  + 1000
        -- end_ = end_ < 0 and 0 or (end_ > data.size and data.size or end_)
        -- local size = math.floor((end_ - start) / downsample)

        -- -- plot it
        -- implot.PlotLine("Time Series", data.Ts.table, data.Ys.table, size, 0, 0, downsample)

        -- plot time now
        local t_now = implot.GetTime()
        local y_now = data.GetY(t_now)

        implot.PlotScatter("Now", {t_now}, {y_now}, 1)
        implot.Annotation(t_now, y_now, implot.GetLastItemColor(), ImVec2(10, 10), false, "Now")
        implot.EndPlot()
    end
end



local Demo_CustomScale_Data = {
    v = {},
}

function ImPlotDemo:Demo_CustomScale()
    local data = Demo_CustomScale_Data

    --
    -- TODO: The SetAxisScale function with callbacks is not implemented
    --

    imgui.Text("Not Implemented")
end

local Demo_MultipleAxes_Data = {
    xs = {},
    xs2 = {},
    ys1 = {},
    ys2 = {},
    ys3 = {},
    x2_axis = true,
    y2_axis = true,
    y3_axis = true,
    init = false,
}

function ImPlotDemo:Demo_MultipleAxes()
    local data = Demo_MultipleAxes_Data

    if not data.init then
        data.init = true

        for i = 1, 1001 do
            local x = (i - 1) * 0.1
            data.xs[i] = x
            data.xs2[i] = x + 10
            data.ys1[i] = math.sin(x) * 3 + 1
            data.ys2[i] = math.cos(x) * 0.2 + 0.5
            data.ys3[i] = math.sin(x + 0.5) * 100 + 200
        end
    end

    data.x2_axis = imgui.Checkbox("X-Axis 2", data.x2_axis); imgui.SameLine()
    data.y2_axis = imgui.Checkbox("Y-Axis 2", data.y2_axis); imgui.SameLine()
    data.y3_axis = imgui.Checkbox("Y-Axis 3", data.y3_axis)

    imgui.BulletText("You can drag axes to the opposite side of the plot.")
    imgui.BulletText("Hover over legend items to see which axis they are plotted on.")

    if implot.BeginPlot("Multi-Axis Plot", ImVec2(-1, 0)) then
        implot.SetupAxes("X-Axis 1", "Y-Axis 1")
        implot.SetupAxesLimits(0, 100, 0, 10)
        if data.x2_axis then
            implot.SetupAxis(ImAxis.X2, "X-Axis 2", ImPlotAxisFlags.AuxDefault)
            implot.SetupAxisLimits(ImAxis.X2, 0, 100)
        end
        if data.y2_axis then
            implot.SetupAxis(ImAxis.Y2, "Y-Axis 2", ImPlotAxisFlags.AuxDefault)
            implot.SetupAxisLimits(ImAxis.Y2, 0, 1)
        end
        if data.y3_axis then
            implot.SetupAxis(ImAxis.Y3, "Y-Axis 3", ImPlotAxisFlags.AuxDefault)
            implot.SetupAxisLimits(ImAxis.Y3, 0, 300)
        end

        implot.PlotLine("f(x) = x", data.xs, data.xs, 1001)
        if data.x2_axis then
            implot.SetAxes(ImAxis.X2, ImAxis.Y1)
            implot.PlotLine("f(x) = sin(x) * 3 + 1", data.xs2, data.ys1, 1001)
        end
        if data.y2_axis then
            implot.SetAxes(ImAxis.X1, ImAxis.Y2)
            implot.PlotLine("f(x) = cos(x) * .25 + .5)", data.xs, data.ys2, 1001)
        end
        if data.y3_axis and data.x2_axis then
            implot.SetAxes(ImAxis.X2, ImAxis.Y3)
            implot.PlotLine("f(x) = sin(x + 0.5) * 100 + 200", data.xs2, data.ys3, 1001)
        end
        implot.EndPlot()
    end
end

local Demo_TickLabels_Data = {

}

function ImPlotDemo:Demo_TickLabels()
    local data = Demo_TickLabels_Data

    --
    -- TODO
    --

    imgui.Text("Not Implemented")
end

local Demo_LinkedAxes_Data = {
    lims = ImPlotRect(0, 1, 0, 1),
    linkx = true,
    linky = true
}

function ImPlotDemo:Demo_LinkedAxes()
    local data = Demo_LinkedAxes_Data

    --
    -- TODO: Need to implement SetupAxisLinks
    --

    imgui.Text("Not Implemented")
end

local Demo_AxisConstraints_Data = {
    constraints1 = {-10, 10},
    constraints2 = {  1, 20},
    flags = 0,
}

function ImPlotDemo:Demo_AxisConstraints()
    local data = Demo_AxisConstraints_Data

    data.constraints1 = imgui.DragFloat2("Limits Constraints", data.constraints1, 0.01)
    data.constraints2 = imgui.DragFloat2("Zoom Constraints", data.constraints2, 0.01)
    data.flags = imgui.CheckboxFlags("ImPlotAxisFlags.PanStretch", data.flags, ImPlotAxisFlags.PanStretch)

    if implot.BeginPlot("##AxisConstraints", ImVec2(-1, 0)) then
        implot.SetupAxes("X", "Y", data.flags, data.flags)
        implot.SetupAxesLimits(-1, 1, -1, 1)
        implot.SetupAxisLimitsConstraints(ImAxis.X1, data.constraints1[1], data.constraints1[2])
        implot.SetupAxisZoomConstraints(ImAxis.X1, data.constraints2[1], data.constraints2[2])
        implot.SetupAxisLimitsConstraints(ImAxis.Y1, data.constraints1[1], data.constraints1[2])
        implot.SetupAxisZoomConstraints(ImAxis.Y1, data.constraints2[1], data.constraints2[2])
        implot.EndPlot()
    end
end

local Demo_EqualAxes_Data = {
    xs1 = {},
    xs2 = {-1, 0, 1, 0, -1},
    ys1 = {},
    ys2 = {0, 1, 0, -1, 0},
    init = false,
}

function ImPlotDemo:Demo_EqualAxes()
    local data = Demo_EqualAxes_Data

    if not data.init then
        data.init = true
        for i = 1, 360 do
            local angle = (i - 1) * 2 * math.pi / 359
            data.xs1[i] = math.cos(angle)
            data.ys1[i] = math.sin(angle)
        end
    end

    if implot.BeginPlot("##EqualAxes", ImVec2(-1, 0), ImPlotFlags.Equal) then
        implot.SetupAxis(ImAxis.X2, nil, ImPlotAxisFlags.AuxDefault)
        implot.SetupAxis(ImAxis.Y2, nil, ImPlotAxisFlags.AuxDefault)
        implot.PlotLine("Circle", data.xs1, data.ys1, 360)
        implot.SetAxes(ImAxis.X2, ImAxis.Y2)
        implot.PlotLine("Diamond", data.xs2, data.ys2, 5)
        implot.EndPlot()
    end
end

local Demo_AutoFittingData_Data = {
    xflags = ImPlotAxisFlags.None,
    yflags = bit32.bor(ImPlotAxisFlags.AutoFit, ImPlotAxisFlags.RangeFit),
    data = {},
    init = false
}

function ImPlotDemo:Demo_AutoFittingData()
    local data = Demo_AutoFittingData_Data

    if not data.init then
        data.init = true
        math.randomseed(0)
        for i = 1, 101 do
            data.data[i] = 1 + math.sin((i - 1) / 10.0)
        end
    end

    imgui.BulletText("The Y-axis has been configured to auto-fit to only the data visible in X-axis range.")
    imgui.BulletText("Zoom and pan the X-axis. Disable Stems to see a difference in fit.")
    imgui.BulletText("If ImPlotAxisFlags_RangeFit is disabled, the axis will fit ALL data.")

    imgui.TextUnformatted("X: "); imgui.SameLine()
    data.xflags = imgui.CheckboxFlags("ImPlotAxisFlags.AutoFit##X", data.xflags, ImPlotAxisFlags.AutoFit); imgui.SameLine()
    data.xflags = imgui.CheckboxFlags("ImPlotAxisFlags.RangeFit##X", data.xflags, ImPlotAxisFlags.RangeFit)
    imgui.TextUnformatted("Y: "); imgui.SameLine()
    data.yflags = imgui.CheckboxFlags("ImPlotAxisFlags.AutoFit##Y", data.yflags, ImPlotAxisFlags.AutoFit); imgui.SameLine()
    data.yflags = imgui.CheckboxFlags("ImPlotAxisFlags.RangeFit##Y", data.yflags, ImPlotAxisFlags.RangeFit)

    if implot.BeginPlot("##DataFitting") then
        implot.SetupAxes("X", "Y", data.xflags, data.yflags)
        implot.PlotLine("Line", data.data, 101)
        implot.PlotStems("Stems", data.data, 101)
        implot.EndPlot()
    end
end


--
-- Main Loop
--

local openGUI = true

ImGui.Register('ImPlot Demo', function()
    openGUI = ImPlotDemo:ShowDemoWindow(openGUI)
end)

while openGUI do
    mq.delay(1000) -- equivalent to '1s'
end
