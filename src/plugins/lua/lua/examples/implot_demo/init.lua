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

    if imgui.BeginTabBar('ImPlotDemoTabs') then
        if imgui.BeginTabItem('Plots') then
            self:DemoHeader('Line Plots', self.Demo_LinePlots)
            self:DemoHeader("Filled Line Plots", self.Demo_FilledLinePlots);
            self:DemoHeader("Shaded Plots##", self.Demo_ShadedPlots)
            self:DemoHeader("Scatter Plots", self.Demo_ScatterPlots)
            self:DemoHeader("Stairstep Plots", self.Demo_StairstepPlots)
            self:DemoHeader("Bar Plots", self.Demo_BarPlots)
            self:DemoHeader("Bar Groups", self.Demo_BarGroups)

            imgui.EndTabItem()
        end
        if imgui.BeginTabItem('Subplots') then
            imgui.EndTabItem()
        end
        if imgui.BeginTabItem('Axes') then
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
            imgui.EndTabItem()
        end
        imgui.EndTabBar()
    end

    imgui.End()

    return open
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

    for i = 1, 1001 do
        data.xs1[i] = (i - 1) * 0.001
        data.ys1[i] = 0.5 + 0.5 * math.sin(50 * (data.xs1[i] + imgui.GetTime() / 10))
    end

    for i = 1, 20 do
        local x = (i - 1) * 1/19.0
        data.xs2[i] = x
        data.ys2[i] = x * x
    end

    if implot.BeginPlot("Line Plots") then
        implot.SetupAxes('x', 'y')
        implot.PlotLine('f(x)', data.xs1, data.ys1)
        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.PlotLine('g(x)', data.xs2, data.ys2, ImPlotLineFlags.Segments)

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
        data.xs1[i] = i
        data.ys1[i] = RandomRange(400, 450)
        data.ys2[i] = RandomRange(275, 350)
        data.ys3[i] = RandomRange(150, 225)
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
            implot.PlotShaded("Stock 1", data.xs1, data.ys1, shade_mode, data.flags)
            implot.PlotShaded("Stock 2", data.xs1, data.ys2, shade_mode, data.flags)
            implot.PlotShaded("Stock 3", data.xs1, data.ys3, shade_mode, data.flags)
            implot.PopStyleVar()
        end

        if data.show_lines then
            implot.PlotLine("Stock 1", data.xs1, data.ys1)
            implot.PlotLine("Stock 2", data.xs1, data.ys2)
            implot.PlotLine("Stock 3", data.xs1, data.ys3)
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
}

function ImPlotDemo:Demo_ShadedPlots()
    local data = Demo_ShadedPlots_Data
    math.randomseed(3)

    for i = 0, 1000 do
        data.xs[i] = i * 0.001
        data.ys[i] = 0.25 + 0.25 * math.sin(25 * data.xs[i]) * math.sin(5 * data.xs[i]) + RandomRange(-0.01, 0.01);
        data.ys1[i] = data.ys[i] + RandomRange(0.1, 0.12)
        data.ys2[i] = data.ys[i] - RandomRange(0.1, 0.12)
        data.ys3[i] = 0.75 + 0.2 * math.sin(25 * data.xs[i])
        data.ys4[i] = 0.75 + 0.1 * math.cos(25 * data.xs[i])
    end

    data.alpha = imgui.DragFloat("Alpha", data.alpha, 0.01, 0, 1)

    if implot.BeginPlot("Shaded Plots") then
        implot.PushStyleVar(ImPlotStyleVar.FillAlpha, data.alpha)
        implot.PlotShaded("Uncertain Data", data.xs, data.ys1, data.ys2)
        implot.PlotLine("Uncertain Data", data.xs, data.ys)

        implot.PlotShaded("Overlapping", data.xs, data.ys3, data.ys4)
        implot.PlotLine("Overlapping", data.xs, data.ys3)
        implot.PlotLine("Overlapping", data.xs, data.ys4)
        implot.PopStyleVar()
        implot.EndPlot()
    end
end

local Demo_ScatterPlots_Data = {
    xs1 = {},
    ys1 = {},
    xs2 = {},
    ys2 = {},
}

function ImPlotDemo:Demo_ScatterPlots()
    local data = Demo_ScatterPlots_Data
    math.randomseed(0)

    for i = 0, 99 do
        data.xs1[i] = i * 0.01
        data.ys1[i] = data.xs1[i] + 0.1 * math.random()
    end

    for i = 0, 49 do
        data.xs2[i] = .25 + 0.2 * math.random()
        data.ys2[i] = .75 + 0.2 * math.random()
    end

    if implot.BeginPlot("Scatter Plot") then
        implot.PlotScatter("Data 1", data.xs1, data.ys1)
        implot.PushStyleVar(ImPlotStyleVar.FillAlpha, 0.25)
        implot.SetNextMarkerStyle(ImPlotMarker.Square, 6, implot.GetColormapColor(1), IMPLOT_AUTO, implot.GetColormapColor(1))
        implot.PlotScatter("Data 2", data.xs2, data.ys2)
        implot.PopStyleVar()
        implot.EndPlot()
    end
end

local Demo_StairstepPlots_Data = {
    ys1 = {},
    ys2 = {},
    flags = 0,
}

function ImPlotDemo:Demo_StairstepPlots()
    local data = Demo_StairstepPlots_Data

    for i = 0, 20 do
        data.ys1[i] = 0.75 + 0.2 * math.sin(10 * i * 0.05)
        data.ys2[i] = 0.25 + 0.2 * math.sin(10 * i * 0.05)
    end

    data.flags = imgui.CheckboxFlags("ImPlotStairsFlags.Shaded", data.flags, ImPlotStairsFlags.Shaded)
    if implot.BeginPlot("Stairstep Plot") then
        implot.SetupAxes("x", "f(x)")
        implot.SetupAxesLimits(0, 1, 0, 1)
        
        implot.PushStyleColor(ImPlotCol.Line, ImVec4(0.5, 0.5, 0.5, 1.0))
        implot.PlotLine("##1", data.ys1, 0.05)
        implot.PlotLine("##2", data.ys2, 0.05)
        implot.PopStyleColor()

        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.SetNextFillStyle(IMPLOT_AUTO_COL, 0.25)
        implot.PlotStairs("Post Step (default)", data.ys1, 0.05, 0, data.flags)
        implot.SetNextMarkerStyle(ImPlotMarker.Circle)
        implot.SetNextFillStyle(IMPLOT_AUTO_COL, 0.25)
        implot.PlotStairs("Pre Step", data.ys2, 0.05, 0, bit32.bor(data.flags, ImPlotStairsFlags.PreStep))

        implot.EndPlot()
    end
end

local Demo_BarPlots_Data = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
}

function ImPlotDemo:Demo_BarPlots()
    local data = Demo_BarPlots_Data
    
    if implot.BeginPlot("Bar Plot") then
        implot.PlotBars("Vertical", data, 0.7, 1)
        implot.PlotBars("Horizontal", data, 0.4, 1, ImPlotBarsFlags.Horizontal)
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
