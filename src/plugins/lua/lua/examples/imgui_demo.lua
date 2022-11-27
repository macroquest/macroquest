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
    },

    simple_overlay_state = {
        corner = 0,
    },

    fullscreen_state = {
        flags = bit32.bor(ImGuiWindowFlags.NoDecoration, ImGuiWindowFlags.NoMove, ImGuiWindowFlags.NoResize, ImGuiWindowFlags.NoSavedSettings),
        use_work_area = true,
    },

    window_title_state = {
        chars = { "|", "/", "-", "\\" }
    },

    dockspace_state = {
        opt_fullscreen = true,
        opt_padding = false,
        dockspace_flags = ImGuiDockNodeFlags.None,
    },
}

function ImGuiDemo:ShowDemoWindow(open)

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
    if self.show_app_simple_overlay then
        self.show_app_simple_overlay = self:ShowExampleAppSimpleOverlay(
            self.simple_overlay_state, self.show_app_simple_overlay)
    end
    if self.show_app_fullscreen then
        self.show_app_fullscreen = self:ShowExampleAppFullscreen(
            self.fullscreen_state, self.show_app_fullscreen)
    end
    if self.show_app_window_titles then
        self.show_app_window_titles = self:ShowExampleAppWindowTitles(
            self.window_title_state, self.show_app_window_titles)
    end
    if self.show_app_custom_rendering then
        self.show_app_custom_rendering = ShowExampleAppCustomRendering(self.show_app_custom_rendering)
    end
    if self.show_app_dockspace then
        self.show_app_dockspace = self:ShowExampleAppDockSpace(self.dockspace_state, self.show_app_dockspace)
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
            _, self.show_app_simple_overlay = imgui.MenuItem("Simple overlay", nil, self.show_app_simple_overlay)
            _, self.show_app_fullscreen = imgui.MenuItem("Fullscreen window", nil, self.show_app_fullscreen)
            _, self.show_app_window_titles = imgui.MenuItem("Manipulating window titles", nil, self.show_app_window_titles)
            _, self.show_app_custom_rendering = imgui.MenuItem("Custom Rendering", nil, self.show_app_custom_rendering)
            _, self.show_app_dockspace = imgui.MenuItem("Dockspace", nil, self.show_app_dockspace)
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

    --
    -- Help
    --

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

function ImGuiDemo:ShowDockingDisabledMessage()
    local io = imgui.GetIO()
    imgui.Text("ERROR: Docking is not enabled! See Demo > Configuration.");
    imgui.Text("Set io.ConfigFlags |= ImGuiConfigFlags_DockingEnable in your code, or ");
    imgui.SameLine(0.0, 0.0);

    if imgui.SmallButton("click here") then
        io.ConfigFlags = bit32.bor(io.ConfigFlags, ImGuiConfigFlags.DockingEnable)
    end
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
    local _, FLT_MAX = mq.NumericLimits_Float()

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

-- Demonstrate creating a simple static window with no decoration
-- + a context-menu to choose which corner of the screen to use.
function ImGuiDemo:ShowExampleAppSimpleOverlay(state, open)
    local io = imgui.GetIO()
    local window_flags = bit32.bor(ImGuiWindowFlags.NoDecoration, ImGuiWindowFlags.NoDocking, ImGuiWindowFlags.AlwaysAutoResize,
        ImGuiWindowFlags.NoSavedSettings, ImGuiWindowFlags.NoFocusOnAppearing, ImGuiWindowFlags.NoNav)

    if state.corner ~= -1 then
        local PAD = 10.0
        local viewport = imgui.GetMainViewport()

        local work_pos = viewport.WorkPos
        local work_size = viewport.WorkSize
        local window_pos = ImVec2(
            bit32.band(state.corner, 1) ~= 0 and (work_pos.x + work_size.x - PAD) or (work_pos.x + PAD),
            bit32.band(state.corner, 2) ~= 0 and (work_pos.y + work_size.y - PAD) or (work_pos.y + PAD)
        )
        local window_pos_pivot = ImVec2(
            bit32.band(state.corner, 1) ~= 0 and 1.0 or 0.0,
            bit32.band(state.corner, 2) ~= 0 and 1.0 or 0.0
        )

        imgui.SetNextWindowPos(window_pos, ImGuiCond.Always, window_pos_pivot)
        imgui.SetNextWindowViewport(viewport.ID)
        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoMove)
    end
    imgui.SetNextWindowBgAlpha(0.35)

    local draw
    open, draw = imgui.Begin("Example: Simple overlay (lua)", open, window_flags)
    if draw then
        imgui.Text("Simple overlay\nin the corner of the screen.\n(right-click to change)")
        imgui.Separator()
        if imgui.IsMousePosValid() then
            imgui.Text("Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y)
        else
            imgui.Text("Mouse Position: <invalid>")
        end
        if imgui.BeginPopupContextWindow() then
            if imgui.MenuItem("Custom",       nil, state.corner == -1) then state.corner = -1 end
            if imgui.MenuItem("Top-left",     nil, state.corner == 0) then state.corner = 0 end
            if imgui.MenuItem("Top-right",    nil, state.corner == 1) then state.corner = 1 end
            if imgui.MenuItem("Bottom-left",  nil, state.corner == 2) then state.corner = 2 end
            if imgui.MenuItem("Bottom-right", nil, state.corner == 3) then state.corner = 3 end
            if imgui.MenuItem("Close") then open = false end
            imgui.EndPopup()
        end
    end
    imgui.End()

    return open
end

-- Demonstrate creating a window covering the entire screen/viewport
function ImGuiDemo:ShowExampleAppFullscreen(state, open)
    -- We demonstrate using the full viewport area or the work area (without menu-bars, task-bars etc.)
    -- Based on your use case you may want one of the other.
    local viewport = imgui.GetMainViewport()
    imgui.SetNextWindowPos(state.use_work_area and viewport.WorkPos or viewport.Pos)
    imgui.SetNextWindowSize(state.use_work_area and viewport.WorkSize or viewport.Size)

    local show
    open, show = imgui.Begin("Example: Fullscreen Window (lua)", open, state.flags)
    if show then
        state.use_work_area = imgui.Checkbox("Use work area instead of main area", state.use_work_area)
        imgui.SameLine()
        imgui.HelpMarker("Main Area = entire viewport,\nWork Area = entire viewport minus sections used by the main menu bars, task bars etc.\n\nEnable the main-menu bar in Examples menu to see the difference.")

        state.flags = imgui.CheckboxFlags("ImGuiWindowFlags.NoBackground", state.flags, ImGuiWindowFlags.NoBackground)
        state.flags = imgui.CheckboxFlags("ImGuiWindowFlags.NoDecoration", state.flags, ImGuiWindowFlags.NoDecoration)
        imgui.Indent()
        state.flags = imgui.CheckboxFlags("ImGuiWindowFlags.NoTitleBar", state.flags, ImGuiWindowFlags.NoTitleBar)
        state.flags = imgui.CheckboxFlags("ImGuiWindowFlags.NoCollapse", state.flags, ImGuiWindowFlags.NoCollapse)
        state.flags = imgui.CheckboxFlags("ImGuiWindowFlags.NoScrollbar", state.flags, ImGuiWindowFlags.NoScrollbar)
        imgui.Unindent()

        if open and imgui.Button("Close this window") then
            open = false
        end
    end
    imgui.End()
    return open
end

-- Demonstrate using "##" and "###" in identifiers to manipulate ID generation.
-- This apply to all regular items as well.
-- Read FAQ section "How can I have multiple widgets with the same label?" for details.
function ImGuiDemo:ShowExampleAppWindowTitles(state, open)
    local viewport = imgui.GetMainViewport()
    local base_pos = viewport.Pos

    -- By default, windows are uniquely identified by their title.
    -- You can use the "##" and "###" markers to manipulate the display/ID.

    -- Using "##" to display same titl ebut have unique identifier.
    imgui.SetNextWindowPos(base_pos.x + 100, base_pos.y + 100, ImGuiCond.FirstUseEver)
    imgui.Begin("Same title as another window##1")
    imgui.Text("This is window 1.\nMy title is the same as window 2, but my identifier is unique.");
    imgui.End()

    imgui.SetNextWindowPos(base_pos.x + 100, base_pos.y + 200, ImGuiCond.FirstUseEver)
    imgui.Begin("Same title as another window##2")
    imgui.Text("This is window 2.\nMy title is the same as window 1, but my identifier is unique.")
    imgui.End()

    -- Using "###" to display a changing title but keep a static identifier "AnimatedTitle"
    local title = string.format("Animated title %s %d###AnimatedTitle", state.chars[bit32.band(math.floor(imgui.GetTime() / 0.25), 3) + 1], imgui.GetFrameCount())
    imgui.SetNextWindowPos(base_pos.x + 100, base_pos.y + 300, ImGuiCond.FirstUseEver)
    imgui.Begin(title)
    imgui.Text("This window has a changing title.")
    imgui.End()
    return open
end

-- Demonstrate using DockSpace() to create an explicit docking node within an existing window.
-- Note: You can use most Docking facilities without calling any API. You DO NOT need to call DockSpace() to use Docking!
-- - Drag from window title bar or their tab to dock/undock. Hold SHIFT to disable docking.
-- - Drag from window menu button (upper-left button) to undock an entire node (all windows).
-- About dockspaces:
-- - Use DockSpace() to create an explicit dock node _within_ an existing window.
-- - Use DockSpaceOverViewport() to create an explicit dock node covering the screen or a specific viewport.
--   This is often used with ImGuiDockNodeFlags_PassthruCentralNode.
-- - Important: Dockspaces need to be submitted _before_ any window they can host. Submit it early in your frame! (*)
-- - Important: Dockspaces need to be kept alive if hidden, otherwise windows docked into it will be undocked.
--   e.g. if you have multiple tabs with a dockspace inside each tab: submit the non-visible dockspaces with ImGuiDockNodeFlags_KeepAliveOnly.
-- (*) because of this constraint, the implicit \"Debug\" window can not be docked into an explicit DockSpace() node,
-- because that window is submitted as part of the part of the NewFrame() call. An easy workaround is that you can create
-- your own implicit "Debug##2" window after calling DockSpace() and leave it in the window stack for anyone to use.
function ImGuiDemo:ShowExampleAppDockSpace(state, open)

    -- We are using the ImGuiWindowFlags.NoDocking flag to make the parent window not dockable into,
    -- because it would be confusing to have two docking targets within each other.
    local window_flags = bit32.bor(ImGuiWindowFlags.MenuBar, ImGuiWindowFlags.NoDocking)
    if state.opt_fullscreen then
        local viewport = imgui.GetMainViewport()
        imgui.SetNextWindowPos(viewport.WorkPos)
        imgui.SetNextWindowSize(viewport.WorkSize)
        imgui.SetNextWindowViewport(viewport.ID)
        imgui.PushStyleVar(ImGuiStyleVar.WindowRounding, 0.0)
        imgui.PushStyleVar(ImGuiStyleVar.WindowBorderSize, 0.0)
        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoTitleBar, ImGuiWindowFlags.NoCollapse, ImGuiWindowFlags.NoResize, ImGuiWindowFlags.NoMove)
        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoBringToFrontOnFocus, ImGuiWindowFlags.NoNavFocus)
    else
        state.dockspace_flags = bit32.setflag(state.dockspace_flags, ImGuiDockNodeFlags.PassthruCentralNode, false)
    end

    -- When using ImGuiDockNodeFlags.PassthruCentralNode, Dockspace() will render our background
    -- and handle the pass-thru hole, so we ask Begin() to not render a background.
    if bit32.band(state.dockspace_flags, ImGuiDockNodeFlags.PassthruCentralNode) then
        window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoBackground)
    end

    -- Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    -- This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    -- all active windows docked into it will lose their parent and become undocked.
    -- We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    -- any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    if not state.opt_padding then
        imgui.PushStyleVar(ImGuiStyleVar.WindowPadding, ImVec2(0.0, 0.0))
    end

    open = imgui.Begin("DockSpace Demo (lua)", open, window_flags)
    if not state.opt_padding then
        imgui.PopStyleVar()
    end
    if state.opt_fullscreen then
        imgui.PopStyleVar(2)
    end

    -- Submit the DockSpace
    local io = imgui.GetIO()
    if bit32.band(io.ConfigFlags, ImGuiConfigFlags.DockingEnable) then
        local dockspace_id = imgui.GetID("MyDockSpace")
        imgui.DockSpace(dockspace_id, 0.0, 0.0, state.dockspace_flags)
    else
        self:ShowDockingDisabledMessage()
    end

    if imgui.BeginMenuBar() then
        if imgui.BeginMenu("Options") then
            -- Disabling fullscreen would allow the window to be moved to the front of other windows,
            -- which we can't undo at the moment without finer window depth/z control.
            _, state.opt_fullscreen = imgui.MenuItem("Fullscreen", nil, state.opt_fullscreen)
            _, state.opt_padding = imgui.MenuItem("Padding", nil, state.opt_padding)
            imgui.Separator()

            if imgui.MenuItem("Flag: NoSplit",                nil, bit32.band(state.dockspace_flags, ImGuiDockNodeFlags.NoSplit) ~= 0) then state.dockspace_flags = bit32.bxor(state.dockspace_flags, ImGuiDockNodeFlags.NoSplit) end
            if imgui.MenuItem("Flag: NoResize",               nil, bit32.band(state.dockspace_flags, ImGuiDockNodeFlags.NoResize) ~= 0) then state.ockspace_flags = bit32.bxor(state.dockspace_flags, ImGuiDockNodeFlags.NoResize) end
            if imgui.MenuItem("Flag: NoDockingInCentralNode", nil, bit32.band(state.dockspace_flags, ImGuiDockNodeFlags.NoDockingInCentralNode) ~= 0) then state.dockspace_flags = bit32.bxor(state.dockspace_flags, ImGuiDockNodeFlags.NoDockingInCentralNode) end
            if imgui.MenuItem("Flag: AutoHideTabBar",         nil, bit32.band(state.dockspace_flags, ImGuiDockNodeFlags.AutoHideTabBar) ~= 0) then state.dockspace_flags = bit32.bxor(state.dockspace_flags, ImGuiDockNodeFlags.AutoHideTabBar) end
            if imgui.MenuItem("Flag: PassthruCentralNode",    nil, bit32.band(state.dockspace_flags, ImGuiDockNodeFlags.PassthruCentralNode) ~= 0, state.opt_fullscreen) then state.dockspace_flags = bit32.bxor(state.dockspace_flags, ImGuiDockNodeFlags.PassthruCentralNode) end

            imgui.Separator()
            if imgui.MenuItem("Close", nil, false, open) then
                open = false
            end
            imgui.EndMenu()
        end

        imgui.HelpMarker(
            "When docking is enabled, you can ALWAYS dock MOST window into another! Try it now!\n" ..
            "- Drag from window title bar or their tab to dock/undock.\n" ..
            "- Drag from window menu button (upper-left button) to undock an entire node (all windows).\n" ..
            "- Hold SHIFT to disable docking.\n" ..
            "This demo app has nothing to do with it!\n\n" ..
            "This demo app only demonstrate the use of ImGui::DockSpace() which allows you to manually create a docking node _within_ another window.\n\n" ..
            "Read comments in ShowExampleAppDockSpace() for more details.")

        imgui.EndMenuBar()
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
