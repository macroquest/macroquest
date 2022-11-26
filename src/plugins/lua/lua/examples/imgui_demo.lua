---@type Mq
local mq = require('mq')
---@type ImGui
local imgui = require 'ImGui'

local ShowDemoWindowWidgets = require 'examples.demo_imgui_widgets'
local ShowExampleAppCustomRendering = require 'examples.demo_imgui_drawlist'
local ShowDemoWindowTables = require 'examples.demo_tables'

local ImGuiDemo = {
    -- Example apps (accessible from the "Examples" menu)
    show_app_main_menu_bar = false,
    show_app_dockspace = false,
    show_app_documents = false,

    show_app_console = false,
    show_app_log = false,
    show_app_layout = false,
    show_app_property_editor = false,
    show_app_long_text = false,
    show_app_auto_resize = false,
    show_app_constrained_resize = false,
    show_app_simple_overlay = false,
    show_app_fullscreen = false,
    show_app_window_titles = false,
    show_app_custom_rendering = false,

    -- Dear ImGui Apps (accessible from the "Tools" menu)
    show_app_metrics = false,
    show_app_style_editor = false,
    show_app_about = false,

    -- Window flags
    no_titlebar = false,
    no_scrollbar = false,
    no_menu = false,
    no_move = false,
    no_resize = false,
    no_collapse = false,
    no_close = false,
    no_nav = false,
    no_background = false,
    no_bring_to_front = false,
    no_docking = false,
    unsaved_document = false,

    constrained_resize_state = {
        test_desc = {
            "Resize vertical only",
            "Resize horizontal only",
            "Width > 100, Height > 100",
            "Width 400-500",
            "Height 400-500",
            "Custom: Always Square",
            "Custom: Fixed Steps (100)",
        },
        auto_resize = false,
        type = 1,
        display_lines = 10,
    }
}

function ImGuiDemo:ShowDemoWindow(open)
    if self.show_app_custom_rendering then ShowExampleAppCustomRendering() end

    if self.show_app_metrics then self.show_app_metrics = imgui.ShowMetricsWindow(self.show_app_metrics) end
    if self.show_app_about then self.show_app_about = imgui.ShowAboutWindow(self.show_app_about) end
    if self.show_app_style_editor then
        self.show_app_style_editor = imgui.Begin("Dear Imgui Style Editor (lua)", self.show_app_style_editor)
        imgui.ShowStyleEditor()
        imgui.End()
    end

    if self.show_app_constrained_resize then
        self.show_app_constrained_resize = self:ShowExampleAppConstrainedResize(
            self.constrained_resize_state, self.show_app_constrained_resize)
    end

    -- Demonstrate the various window flags. Typically you would just use the default!
    --- @type ImGuiWindowFlags
    local window_flags = 0
    if self.no_titlebar then        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoTitleBar) end
    if self.no_scrollbar then       window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoScrollbar) end
    if not self.no_menu then        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.MenuBar) end
    if self.no_move then            window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoMove) end
    if self.no_resize then          window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoResize) end
    if self.no_collapse then        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoCollapse) end
    if self.no_nav then             window_flags = bit32.bor(window_flags, ImGuiWindowFlags.no_nav) end
    if self.no_background then      window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoBackground) end
    if self.no_bring_to_front then  window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoBringToFrontOnFocus) end
    if self.no_docking then         window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoDocking) end
    if self.unsaved_document then   window_flags = bit32.bor(window_flags, ImGuiWindowFlags.UnsavedDocument) end

    -- We specify a default position/size in case there's no data in the .ini file.
    -- We only do it to make the demo applications a little more welcoming, but typically this isn't required.
    local main_viewport = imgui.GetMainViewport()
    imgui.SetNextWindowPos(main_viewport.WorkPos.x + 650, main_viewport.WorkPos.y + 20, ImGuiCond.FirstUseEver)
    imgui.SetNextWindowSize(550, 680, ImGuiCond.FirstUseEver)

    local show = false
    if self.no_close then
        show = imgui.Begin("Dear ImGui Window (lua)", nil, window_flags)
    else
        open, show = imgui.Begin("Dear ImGu Window (lua)", open, window_flags)
    end

    if not show then
        ImGui.End()
        return open
    end

    -- Most "big" widgets share a common width settings by default. See 'Demo->Layout->Widgets Width' for details.

    -- e.g. Use 2/3 of the space for widgets and 1/3 for labels (right align)
    --ImGui.PushItemWidth(-ImGui.GetWindowWidth() * 0.35f);

    -- e.g. Leave a fixed amount of width for labels (by passing a negative value), the rest goes to widgets.
    ImGui.PushItemWidth(ImGui.GetFontSize() * -12);

    -- Menu Bar
    if imgui.BeginMenuBar() then
        if imgui.BeginMenu("Menu") then
            self:ShowExampleMenuFile()
            imgui.EndMenu()
        end

        if imgui.BeginMenu("Examples") then
            -- _, self.show_app_main_menu_bar = imgui.MenuItem("Main menu bar", nil, self.show_app_main_menu_bar)
            -- _, self.show_app_console = imgui.MenuItem("Console", nil, self.show_app_console)
            -- _, self.show_app_log = imgui.MenuItem("Log", nil, self.show_app_log)
            -- _, self.show_app_layout = imgui.MenuItem("Simple layout", nil, self.show_app_layout)
            -- _, self.show_app_property_editor = imgui.MenuItem("Property editor", nil, self.show_app_property_editor)
            -- _, self.show_app_long_text = imgui.MenuItem("Long text display", nil, self.show_app_long_text)
            -- _, self.show_app_auto_resize = imgui.MenuItem("Auto-resizing window", nil, self.show_app_auto_resize)
            _, self.show_app_constrained_resize = imgui.MenuItem("Constrained-resizing window", nil, self.show_app_constrained_resize)
            -- _, self.show_app_simple_overlay = imgui.MenuItem("Simple overlay", nil, self.show_app_simple_overlay)
            -- _, self.show_app_fullscreen = imgui.MenuItem("Fullscreen window", nil, self.show_app_fullscreen)
            -- _, self.show_app_window_titles = imgui.MenuItem("Manipulating window titles", nil, self.show_app_window_titles)
            _, self.show_app_custom_rendering = imgui.MenuItem("Custom Rendering", nil, self.show_app_custom_rendering)
            -- _, self.show_app_dockspace = imgui.MenuItem("Dockspace", nil, self.show_app_dockspace)
            -- _, self.show_app_documents = imgui.MenuItem("Documents", nil, self.show_app_documents)

            imgui.EndMenu()
        end

        if imgui.BeginMenu("Tools") then
            _, self.show_app_metrics = imgui.MenuItem("Metrics/Debugger", nil, self.show_app_metrics)
            _, self.show_app_style_editor = imgui.MenuItem("Style Editor", nil, self.show_app_style_editor)
            _, self.show_app_about = imgui.MenuItem("About Dear ImGui", nil, self.show_app_about)

            imgui.EndMenu()
        end
        
        imgui.EndMenuBar()
    end

    imgui.Text("dear imgui says hello. (%s)", imgui.GetVersion())
    imgui.Spacing()

    if imgui.CollapsingHeader("Help") then
        ImGui.Text("ABOUT THIS DEMO:");
        ImGui.BulletText("Sections below are demonstrating many aspects of the library.");
        ImGui.BulletText("The \"Examples\" menu above leads to more demo contents.");
        ImGui.BulletText("The \"Tools\" menu above gives access to: About Box, Style Editor,\n" ..
                         "and Metrics/Debugger (general purpose Dear ImGui debugging tool).");
        ImGui.Separator();

        ImGui.Text("PROGRAMMER GUIDE:");
        ImGui.BulletText("See the ShowDemoWindow() code in examples/imgui_demo.lua. <- you are here!");
        ImGui.BulletText("See comments in imgui.cpp.");
        ImGui.BulletText("See example applications in the examples/ folder.");
        ImGui.BulletText("Read the FAQ at http://www.dearimgui.org/faq/");
        ImGui.BulletText("Set 'io.ConfigFlags |= NavEnableKeyboard' for keyboard controls.");
        ImGui.BulletText("Set 'io.ConfigFlags |= NavEnableGamepad' for gamepad controls.");
        ImGui.Separator();

        ImGui.Text("USER GUIDE:");
        ImGui.ShowUserGuide();
    end

    ShowDemoWindowWidgets()
    -- ShowDemoWindowLayout
    -- ShowDemoWindowPopups
    ShowDemoWindowTables()
    -- ShowDemoWindowMisc

    imgui.PopItemWidth()
    imgui.End()
    return open
end

function ImGuiDemo:ShowExampleMenuFile()
end

---@param desiredSize ImVec2
---@return ImVec2
local function CustomSize_Square(_, _, desiredSize)
    local m = math.max(desiredSize.x, desiredSize.y)
    return ImVec2(m, m)
end

---@param step number
---@param desiredSize ImVec2
---@return ImVec2
local function CustomSize_Step(step, _, _, desiredSize)
    return ImVec2(
        math.floor(desiredSize.x / step + 0.5) * step,
        math.floor(desiredSize.y / step + 0.5) * step
    )
end

-- Demonstrate creating a window with custom resize constraints
function ImGuiDemo:ShowExampleAppConstrainedResize(state, open)
    local FLT_MIN, FLT_MAX = mq.NumericLimits_Float()

    if state.type == 1 then imgui.SetNextWindowSizeConstraints(ImVec2(-1, 0),    ImVec2(-1, FLT_MAX)) end       -- Vertical only
    if state.type == 2 then imgui.SetNextWindowSizeConstraints(ImVec2(0, -1),    ImVec2(FLT_MAX, -1)) end       -- Horizontal only
    if state.type == 3 then imgui.SetNextWindowSizeConstraints(ImVec2(100, 100), ImVec2(FLT_MAX, FLT_MAX)) end  -- Width > 100, Height > 100
    if state.type == 4 then imgui.SetNextWindowSizeConstraints(ImVec2(400, -1),  ImVec2(500, -1)) end           -- Width 400-500
    if state.type == 5 then imgui.SetNextWindowSizeConstraints(ImVec2(-1, 400),  ImVec2(-1, 500)) end           -- Height 400-500
    if state.type == 6 then imgui.SetNextWindowSizeConstraints(ImVec2(0, 0),     ImVec2(FLT_MAX, FLT_MAX), CustomSize_Square) end  -- always square
    if state.type == 7 then imgui.SetNextWindowSizeConstraints(ImVec2(0, 0),     ImVec2(FLT_MAX, FLT_MAX),
        function(pos, currentSize, desiredSize) return CustomSize_Step(100, pos, currentSize, desiredSize) end) end  -- step

    local flags = state.auto_resize and ImGuiWindowFlags.AlwaysAutoResize or 0
    local show
    open, show = imgui.Begin("Example: Constrained Resize", open, flags)
    if show then
        if imgui.IsWindowDocked() then
            imgui.Text("Warning: Sizing Constraints won't work if the window is docked!")
        end

        if imgui.Button('200x200') then imgui.SetWindowSize(200, 200) end; imgui.SameLine()
        if imgui.Button('500x500') then imgui.SetWindowSize(500, 500) end; imgui.SameLine()
        if imgui.Button('800x200') then imgui.SetWindowSize(800, 200) end;
        imgui.SetNextItemWidth(200)
        state.type = imgui.Combo("Constraint", state.type, state.test_desc, #state.test_desc)
        imgui.Text("State: %s", state.type)
        imgui.SetNextItemWidth(200)
        state.display_lines = imgui.DragInt("Lines", state.display_lines, 0.2, 1, 100)
        state.auto_resize = imgui.Checkbox("Auto-resize", state.auto_resize)
        for i = 1, state.display_lines do
            imgui.Text("%sHello, sailor! Making this line long enough for the example.", string.rep(" ", i * 4))
        end
    end
    imgui.End()

    return open
end

local openGUI = true

ImGui.Register('DemoWidgets', function()
    openGUI = ImGuiDemo:ShowDemoWindow(openGUI)
end)

while openGUI do
    mq.delay(1000) -- equivalent to '1s'
end
