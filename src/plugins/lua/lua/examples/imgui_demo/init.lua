---@diagnostic disable: empty-block

local mq = require('mq')
local imgui = require 'ImGui'

local ShowDemoWindowWidgets = require '_demo_widgets'
local ShowExampleAppCustomRendering = require '_demo_drawlist'
local ShowDemoWindowTables = require '_demo_tables'

local FLT_MIN, FLT_MAX = mq.NumericLimits_Float()

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

    window_flag_options = {
        { name = "No titlebar", key = 'no_titlebar' },
        { name = "No scrollbar", key = 'no_scrollbar' },
        { name = "No menu", key = 'no_menu' },
        { name = "No move", key = 'no_move' },
        { name = "No resize", key = 'no_resize' },
        { name = "No collapse", key = 'no_collapse' },
        { name = "No close", key = 'no_close' },
        { name = "No nav", key = 'no_nav' },
        { name = "No background", key = 'no_background' },
        { name = "No bring to front", key = 'no_bring_to_front' },
        { name = "No docking", key = 'no_docking' },
        { name = "Unsaved document", key = 'unsaved_document' },
    },

    menu_state = {
        enabled = true,
        f = 0.5,
        n = 1,
        b = true,
    },

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
    if self.show_app_documents then
        self.show_app_documents = self:ShowExampleAppDocuments(self.show_app_documents)
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
    if self.no_nav then             window_flags = bit32.bor(window_flags, ImGuiWindowFlags.NoNav) end
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
            _, self.show_app_documents = imgui.MenuItem("Documents", nil, self.show_app_documents)

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
        imgui.SeparatorText("ABOUT THIS DEMO:");
        imgui.BulletText("Sections below are demonstrating many aspects of the library.");
        imgui.BulletText("The \"Examples\" menu above leads to more demo contents.");
        imgui.BulletText("The \"Tools\" menu above gives access to: About Box, Style Editor,\n" ..
                         "and Metrics/Debugger (general purpose Dear ImGui debugging tool).");

        imgui.SeparatorText("PROGRAMMER GUIDE:");
        imgui.BulletText("See the ShowDemoWindow() code in examples/imgui_demo.lua. <- you are here!");
        imgui.BulletText("See comments in imgui.cpp.");
        imgui.BulletText("See example applications in the examples/ folder.");
        imgui.BulletText("Read the FAQ at http://www.dearimgui.org/faq/");
        imgui.BulletText("Set 'io.ConfigFlags |= NavEnableKeyboard' for keyboard controls.");
        imgui.BulletText("Set 'io.ConfigFlags |= NavEnableGamepad' for gamepad controls.");

        imgui.SeparatorText("USER GUIDE:");
        imgui.ShowUserGuide();
    end

    --
    -- Configuration
    -- We purposefully leave a few low level things out here relating to the platform integration
    --

    if imgui.CollapsingHeader('Configuration') then
        if imgui.TreeNode('Style') then
            imgui.HelpMarker("The same contents can be accessed in 'Tools->Style Editor' or by calling the ShowStyleEditor() function.")
            imgui.ShowStyleEditor()
            imgui.TreePop()
            imgui.Spacing()
        end

        if imgui.TreeNode('Capture/Logging') then
            imgui.HelpMarker(
                "The logging API redirects all text output so you can easily capture the content of " ..
                "a window or a block. Tree nodes can be automatically expanded.\n" ..
                "Try opening any of the contents below in this window and then click one of the \"Log To\" button.")
            imgui.LogButtons();

            imgui.HelpMarker("You can also call ImGui::LogText() to output directly to the log without a visual output.")
            if imgui.Button('Copy \"Hello, world!\" to clipboard') then
                imgui.LogToClipboard()
                imgui.LogText('Hello, world!')
                imgui.LogFinish()
            end
            imgui.TreePop()
        end
    end

    --
    -- Window options
    --

    if imgui.CollapsingHeader('Window options') then
        if imgui.BeginTable('split', 3) then
            for _, opts in ipairs(self.window_flag_options) do
                imgui.TableNextColumn()
                self[opts.key] = imgui.Checkbox(opts.name, self[opts.key]) --- @diagnostic disable-line: param-type-mismatch
            end
            imgui.EndTable()
        end
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
    ImGui.MenuItem("(demo menu)", nil, false, false)
    if ImGui.MenuItem("New") then
    end
    if ImGui.MenuItem("Open", "Ctrl+O") then
    end
    if ImGui.BeginMenu("Open Recent") then
        ImGui.MenuItem("fish_hat.c")
        ImGui.MenuItem("fish_hat.inl")
        ImGui.MenuItem("fish_hat.h")

        if ImGui.BeginMenu("More..") then
            ImGui.MenuItem("Hello")
            ImGui.MenuItem("Sailor")
            if ImGui.BeginMenu("Recurse..") then
                self:ShowExampleMenuFile()
                ImGui.EndMenu()
            end
            ImGui.EndMenu()
        end
        ImGui.EndMenu()
    end
    if ImGui.MenuItem("Save", "Ctrl+S") then
    end
    if ImGui.MenuItem("Save As...") then
    end

    ImGui.Separator()
    if ImGui.BeginMenu("Options") then
        _, self.menu_state.enabled = ImGui.MenuItem("Enabled", "", self.menu_state.enabled)
        ImGui.BeginChild("child", ImVec2(0, 60), ImGuiChildFlags.Border)
        for i = 1, 10 do
            ImGui.Text('Scrolling Text %d', i - 1)
        end
        ImGui.EndChild()
        self.menu_state.f = ImGui.SliderFloat("Value", self.menu_state.f, 0.0, 1.0)
        self.menu_state.f = ImGui.InputFloat("Input", self.menu_state.f, 0.1)
        self.menu_state.n = ImGui.Combo("Combo", self.menu_state.n, "Yes\0No\0Maybe\0\0")
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu("Colors") then
        local sz = ImGui.GetTextLineHeight()
        for i = 0, ImGuiCol.COUNT - 1 do
            local name = ImGui.GetStyleColorName(i)
            local p = ImGui.GetCursorScreenPosVec()

            ImGui.GetWindowDrawList():AddRectFilled(p, p + sz, ImGui.GetColorU32(i, 1.0))
            ImGui.Dummy(sz, sz)
            ImGui.SameLine()
            ImGui.MenuItem(name)
        end
        ImGui.EndMenu()
    end

    -- Here we demonstrate appending again to the "Options" menu (which we already created above)
    -- Of course in this demo it is a little bit silly that this function calls BeginMenu("Options") twice.
    -- In a real code-base using it would make senses to use this feature from very different code locations.
    if ImGui.BeginMenu("Options") then -- <-- Append!
        self.menu_state.b = ImGui.Checkbox("SomeOptions", self.menu_state.b)
        ImGui.EndMenu()
    end

    if ImGui.BeginMenu("Disabled", false) then
        -- should never get hit
        ---@diagnostic disable-next-line: undefined-field
        ImGui.ThisFunctionDoesntExist()
    end

    if ImGui.MenuItem("Checked", nil, true) then
    end
    ImGui.Separator()
    if ImGui.MenuItem("Quit", "Alt-F4") then
    end
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
    open, show = imgui.Begin("Example: Constrained Resize (lua)", open, flags)
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
    imgui.Begin("Same title as another window (lua)##1")
    imgui.Text("This is window 1.\nMy title is the same as window 2, but my identifier is unique.");
    imgui.End()

    imgui.SetNextWindowPos(base_pos.x + 100, base_pos.y + 200, ImGuiCond.FirstUseEver)
    imgui.Begin("Same title as another window (lua)##2")
    imgui.Text("This is window 2.\nMy title is the same as window 1, but my identifier is unique.")
    imgui.End()

    -- Using "###" to display a changing title but keep a static identifier "AnimatedTitle"
    local title = string.format("Animated title %s %d (lua)###AnimatedTitle", state.chars[bit32.band(math.floor(imgui.GetTime() / 0.25), 3) + 1], imgui.GetFrameCount())
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
        local dockspace_id = imgui.GetID("MyDockSpace (lua)")
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

--
-- Example App: Documents Handling
--

-- Simplified structure to mimic a document model

---@class MyDocument
---@field public Name string
---@field public Open boolean
---@field public OpenPrev boolean
---@field public Dirty boolean
---@field public WantClose boolean
---@field public Color ImVec4
local MyDocument = {}

---@param name string
---@param open? boolean
---@param color? ImVec4
---@return MyDocument
function MyDocument.new(name, open, color)
    MyDocument.__index = MyDocument
    ---@type MyDocument
    local o = setmetatable({}, MyDocument)
    o.Name = name
    o.Open = (open ~= nil and open or true)
    o.OpenPrev = o.Open
    o.Dirty = false
    o.WantClose = false
    o.Color = (color ~= nil and color or ImVec4(1.0, 1.0, 1.0, 1.0))
    return o
end

function MyDocument:DoOpen()
    self.Open = true
end

function MyDocument:DoQueueClose()
    self.WantClose = true
end

function MyDocument:DoForceClose()
    self.Open = false
    self.Dirty = false
end

function MyDocument:DoSave()
    self.Dirty = false
end

-- Display placeholder contents for the Document
function MyDocument:DisplayContents()
    imgui.PushID(self)
    imgui.Text("Document \"%s\"", self.Name)
    imgui.PushStyleColor(ImGuiCol.Text, self.Color)
    imgui.TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
    imgui.PopStyleColor()

    if imgui.Button("Modify", ImVec2(100, 0)) then
        self.Dirty = true
    end
    imgui.SameLine()
    if imgui.Button("Save", ImVec2(100, 0)) then
        self:DoSave()
    end
    self.Color = imgui.ColorEdit3("Color", self.Color)
    imgui.PopID()
end

-- Display context menu for the document
function MyDocument:DisplayContextMenu()
    if not imgui.BeginPopupContextItem() then
        return
    end

    if imgui.MenuItem(string.format("Save %s", self.Name), "CTRL+S", false, self.Open) then
        self:DoSave()
    end
    if imgui.MenuItem("Close", "CTRL+W", false, self.Open) then
        self:DoQueueClose()
    end

    imgui.EndPopup()
end

local Documents = {
    MyDocument.new("Lettuce",             true,  ImVec4(0.4, 0.8, 0.4, 1.0)),
    MyDocument.new("Eggplant",            true,  ImVec4(0.8, 0.5, 1.0, 1.0)),
    MyDocument.new("Carrot",              true,  ImVec4(1.0, 0.8, 0.5, 1.0)),
    MyDocument.new("Tomato",              false, ImVec4(1.0, 0.3, 0.4, 1.0)),
    MyDocument.new("A Rather Long Title", false),
    MyDocument.new("Some Document",       false),
}

local DocumentTarget = {
    None = 1,
    Tab = 2,                     -- Create documents as local tab in to a local tab bar
    DockSpaceAndWindow = 3       -- Create documents as regular windows, and create an embedded dockspace
}

-- [Optional] Notify the system of Tabs/Windows closure that happened outside the regular tab interface.
-- If a tab has been closed programmatically (aka closed from another source such as the Checkbox() in the demo,
-- as opposed to clicking on the regular tab closing button) and stops being submitted, it will take a frame for
-- the tab bar to notice its absence. During this frame there will be a gap in the tab bar, and if the tab that has
-- disappeared was the selected one, the tab bar will report no selected tab during the frame. This will effectively
-- give the impression of a flicker for one frame.
-- We call SetTabItemClosed() to manually notify the Tab Bar or Docking system of removed tabs to avoid this glitch.
-- Note that this completely optional, and only affect tab bars with the ImGuiTabBarFlags_Reorderable flag.

---@param documents MyDocument[]
local function NotifyOfDocumentsClosedElsewhere(documents)
    for _, doc in ipairs(documents) do
        if not doc.Open and doc.OpenPrev then
            imgui.SetTabItemClosed(doc.Name)
        end
        doc.OpenPrev = doc.Open
    end
end

local DocumentsState = {
    opt_target = DocumentTarget.Tab,
    opt_reorderable = true,
    opt_fitting_flags = ImGuiTabBarFlags.FittingPolicyDefault_,

    ---@type MyDocument[]
    close_queue = {},
}

function ImGuiDemo:ShowExampleAppDocuments(open)
    local state = DocumentsState
    -- When (opt_target == Target_DockSpaceAndWindow) there is the possibily that one of our child Document window (e.g. "Eggplant")
    -- that we emit gets docked into the same spot as the parent window ("Example: Documents").
    -- This would create a problematic feedback loop because selecting the "Eggplant" tab would make the "Example: Documents" tab
    -- not visible, which in turn would stop submitting the "Eggplant" window.
    -- We avoid this problem by submitting our documents window even if our parent window is not currently visible.
    -- Another solution may be to make the "Example: Documents" window use the ImGuiWindowFlags_NoDocking.
    local window_contents_visible
    open, window_contents_visible = imgui.Begin("Example: Documents (lua)", open, ImGuiWindowFlags.MenuBar)
    if not window_contents_visible and state.opt_target ~= DocumentTarget.DockSpaceAndWindow then
        imgui.End()
        return open
    end

    -- Menu
    if imgui.BeginMenuBar() then
        if imgui.BeginMenu("File") then
            local open_count = 0
            for _, doc in ipairs(Documents) do
                if doc.Open then
                    open_count = open_count + 1
                end
            end

            if imgui.BeginMenu("Open", open_count < #Documents) then
                for _, doc in ipairs(Documents) do
                    if not doc.Open then
                        if imgui.MenuItem(doc.Name) then
                            doc:DoOpen()
                        end
                    end
                end
                imgui.EndMenu()
            end

            if imgui.MenuItem("Close All Documents", nil, false, open_count > 0) then
                for _, doc in ipairs(Documents) do
                    doc:DoQueueClose()
                end
            end

            if imgui.MenuItem("Exit", "Alt+F4") then
                print("Requested to exit, but this is just a demo window")
            end

            imgui.EndMenu()
        end

        imgui.EndMenuBar()
    end

    -- [Debug] List documents with one checkbox for each
    for i, doc in ipairs(Documents) do
        if i > 1 then
            imgui.SameLine()
        end
        imgui.PushID(doc)
        local changed
        doc.Open, changed = imgui.Checkbox(doc.Name, doc.Open)
        if changed then
            if not doc.Open then
                doc:DoForceClose()
            end
        end
        imgui.PopID()
    end

    imgui.PushItemWidth(imgui.GetFontSize() * 12)
    state.opt_target = imgui.Combo("Output", state.opt_target, "None\0TabBar+Tabs\0DockSpace+Window\0")
    imgui.PopItemWidth()

    local redock_all = false
    if state.opt_target == DocumentTarget.Tab then
        imgui.SameLine()
        state.opt_reorderable = imgui.Checkbox("Reorderable Tabs", state.opt_reorderable)
    elseif state.opt_target == DocumentTarget.DockSpaceAndWindow then
        imgui.SameLine()
        redock_all = imgui.Button("Redock All")
    end

    imgui.Separator()

    -- About the ImGuiWindowFlags_UnsavedDocument / ImGuiTabItemFlags_UnsavedDocument flags.
    -- They have multiple effects:
    -- - Display a dot next to the title.
    -- - Tab is selected when clicking the X close button.
    -- - Closure is not assumed (will wait for user to stop submitting the tab).
    --   Otherwise closure is assumed when pressing the X, so if you keep submitting the tab may reappear at end of tab bar.
    --   We need to assume closure by default otherwise waiting for "lack of submission" on the next frame would leave an empty
    --   hole for one-frame, both in the tab-bar and in tab-contents when closing a tab/window.
    --   The rarely used SetTabItemClosed() function is a way to notify of programmatic closure to avoid the one-frame hole.

    -- Tabs
    if state.opt_target == DocumentTarget.Tab then
        local tab_bar_flags = bit32.bor(state.opt_fitting_flags, state.opt_reorderable and ImGuiTabBarFlags.Reorderable or 0)
        if imgui.BeginTabBar("##tabs", tab_bar_flags) then
            if state.opt_reorderable then
                NotifyOfDocumentsClosedElsewhere(Documents)
            end

            -- Submit Tabs
            for _, doc in ipairs(Documents) do
                if doc.Open then
                    local tab_flags = doc.Dirty and ImGuiTabItemFlags.UnsavedDocument or 0
                    local visible
                    doc.Open, visible = imgui.BeginTabItem(doc.Name, doc.Open, tab_flags)

                    -- Cancel attempt to close when unsaved. add to save queue so we can display a popup
                    if not doc.Open and doc.Dirty then
                        doc.Open = true
                        doc:DoQueueClose()
                    end

                    doc:DisplayContextMenu()

                    if visible then
                        doc:DisplayContents()
                        imgui.EndTabItem()
                    end
                end
            end
            imgui.EndTabBar()
        end
    elseif state.opt_target == DocumentTarget.DockSpaceAndWindow then
        if bit32.band(imgui.GetIO().ConfigFlags, ImGuiConfigFlags.DockingEnable) then
            NotifyOfDocumentsClosedElsewhere(Documents)

            -- Create a DockSpace node where any window can be docked.
            local dockspace_id = imgui.GetID("MyDockSpace")
            imgui.DockSpace(dockspace_id)

            -- Create Windows
            for _, doc in ipairs(Documents) do
                if doc.Open then
                    imgui.SetNextWindowDockID(dockspace_id, redock_all and ImGuiCond.Always or ImGuiCond.FirstUseEver)
                    local window_flags = doc.Dirty and ImGuiWindowFlags.UnsavedDocument or 0
                    local visible
                    doc.Open, visible = imgui.Begin(doc.Name, doc.Open, window_flags)
                    
                    -- Cancel attempt to close when unsaved, add to save queue so we can display a popup.
                    if not doc.Open and doc.Dirty then
                        doc.Open = true
                        doc:DoQueueClose()
                    end

                    doc:DisplayContextMenu()

                    if visible then
                        doc:DisplayContents()
                    end

                    imgui.End()
                end
            end
        else
            self:ShowDockingDisabledMessage()
        end
    end

    -- Early out other contents
    if not window_contents_visible then
        imgui.End()
        return open
    end

    -- Update closing queue
    if #state.close_queue == 0 then
        -- Close queue is locked once we started a popup
        for _, doc in ipairs(Documents) do
            if doc.WantClose then
                doc.WantClose = false
                table.insert(state.close_queue, doc)
            end
        end
    end

    -- Display closing confirmation UI
    if #state.close_queue ~= 0 then
        local close_queue_unsaved_documents = 0
        for _, doc in ipairs(state.close_queue) do
            if doc.Dirty then
                close_queue_unsaved_documents = close_queue_unsaved_documents + 1
            end
        end

        if close_queue_unsaved_documents == 0 then
            -- Close documents when all are saved
            for _, doc in ipairs(state.close_queue) do
                doc:DoForceClose()
            end

            state.close_queue = {}
        else
            if not imgui.IsPopupOpen("Save?") then
                imgui.OpenPopup("Save?")
            end

            if imgui.BeginPopupModal("Save?", nil, ImGuiWindowFlags.AlwaysAutoResize) then
                imgui.Text("Save change to the following items?")
                local item_height = imgui.GetTextLineHeightWithSpacing()
                if imgui.BeginChildFrame(imgui.GetID("frame"), ImVec2(-FLT_MIN, 6.25 * item_height)) then
                    for _, doc in ipairs(state.close_queue) do
                        if doc.Dirty then
                            imgui.Text(doc.Name)
                        end
                    end

                    imgui.EndChildFrame()
                end

                local button_size = ImVec2(imgui.GetFontSize() * 7, 0.0)
                if imgui.Button("Yes", button_size) then
                    for _, doc in ipairs(state.close_queue) do
                        if doc.Dirty then
                            doc:DoSave()
                        end

                        doc:DoForceClose()
                    end

                    state.close_queue = {}
                    imgui.CloseCurrentPopup()
                end

                imgui.SameLine()

                if imgui.Button("No", button_size) then
                    for _, doc in ipairs(state.close_queue) do
                        doc:DoForceClose()
                    end

                    state.close_queue = {}
                    imgui.CloseCurrentPopup()
                end

                imgui.SameLine()

                if imgui.Button("Cancel", button_size) then
                    state.close_queue = {}
                    imgui.CloseCurrentPopup()
                end

                imgui.EndPopup()
            end
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
