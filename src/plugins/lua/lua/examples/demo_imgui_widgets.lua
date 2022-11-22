---@type Mq
local mq = require('mq')
---@type ImGui
local imgui = require 'ImGui'

local w = {
    disable_all = false
}

--
-- Widgest Demo - Images
--

local WidgetsDemo_Images = {
    pressed_count = 0
}

function WidgetsDemo_Images:Draw()
    local io = imgui.GetIO()
    imgui.TextWrapped(
        "Below we are displaying the font texture (which is the only texture we have access to in this demo). " ..
        "Use the 'ImTextureID' type as storage to pass pointers or identifier to your own texture data. " ..
        "Hover the texture for a zoomed view!")

    -- Below we are displaying the font texture because it is the only texture we have access to inside the demo!
    -- Remember that ImTextureID is just storage for whatever you want it to be. It is essentially a value that
    -- will be passed to the rendering backend via the ImDrawCmd structure.
    local my_tex_id = io.Fonts.TexID
    local my_tex_w = io.Fonts.TexWidth
    local my_tex_h = io.Fonts.TexHeight

    imgui.Text(string.format("%.0fx%.0f", my_tex_w, my_tex_h))
    local pos = imgui.GetCursorScreenPosVec()
    local uv_min = ImVec2(0, 0)
    local uv_max = ImVec2(1, 1)
    local tint_col = ImVec4(1, 1, 1, 1)
    local border_col = ImVec4(1, 1, 1, 0.5)

    imgui.Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), uv_min, uv_max, tint_col, border_col)

    if imgui.IsItemHovered() then
        imgui.BeginTooltip()

        local region_sz = 32
        local zoom = 4
        local region = io.MousePos - pos - region_sz * 0.5

        if region.x < 0.0 then
            region.x = 0
        elseif region.x > my_tex_w - region_sz then
            region.x = my_tex_w - region_sz
        end
        if region.y < 0.0 then
            region.y = 0
        elseif region.y > my_tex_h - region_sz then
            region.y = my_tex_h - region_sz
        end

        imgui.Text(string.format("Min: (%.2f, %.2f)", region.x, region.y))
        imgui.Text(string.format("Max: (%.2f, %.2f)", region.x + region_sz, region.y + region_sz))

        local uv0 = ImVec2(region.x / my_tex_w, region.y / my_tex_h)
        local uv1 = ImVec2((region.x + region_sz) / my_tex_w, (region.y + region_sz) / my_tex_h)

        imgui.Image(my_tex_id, ImVec2(region_sz * zoom, region_sz * zoom), uv0, uv1, tint_col, border_col)

        imgui.EndTooltip()
    end

    imgui.TextWrapped("And now some textured buttons..")
    for i = 0, 7 do
        imgui.PushID(i)
        local frame_padding = -1 + i  -- -1 == uses default padding (style.FramePadding)

        local size = ImVec2(32, 32)
        local uv0 = ImVec2(0, 0)
        local uv1 = ImVec2(32 / my_tex_w, 32 / my_tex_h)
        local bg_col = ImVec4(0, 0, 0, 1)

        if imgui.ImageButton(my_tex_id, size, uv0, uv1, frame_padding, bg_col, tint_col) then
            self.pressed_count = self.pressed_count + 1
        end
        imgui.PopID()
        imgui.SameLine()
    end

    imgui.NewLine()
    imgui.Text(string.format("Pressed %d times", self.pressed_count))
end

--
-- WidgetsDemo - Combo Select
--

local WidgetsDemo_Combos = {
    flags = 0,

    -- Example 1
    items = {
        "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO"
    },
    item_current_idx = 1,  -- here we store our selection data as an index

    -- Example 2
    item_current_2 = 1,

    -- Example 3
    item_current_3 = -1,

    -- Example 4
    item_current_4 = 1
}

function WidgetsDemo_Combos:Draw()
    self.flags = imgui.CheckboxFlags("ImGuiComboFlags.PopupAlignLeft", self.flags, ImGuiComboFlags.PopupAlignLeft)
    imgui.SameLine()
    imgui.HelpMarker("Only makes a difference if the popup is larger than the combo")
    self.flags, pressed = imgui.CheckboxFlags("ImGuiComboFlags.NoArrowButton", self.flags, ImGuiComboFlags.NoArrowButton)
    if pressed then  -- clear the other flag, as we cannot combine both
        self.flags = bit32.setflag(self.flags, ImGuiComboFlags.NoPreview, false)
    end
    self.flags, pressed = imgui.CheckboxFlags("ImGuiComboFlags.NoPreview", self.flags, ImGuiComboFlags.NoPreview)
    if pressed then  -- clear the other flag, as we cannot combine both
        self.flags = bit32.setflag(self.flags, ImGuiComboFlags.NoArrowButton, false)
    end

    -- Using the generic BeginCombo() API, you have full control over how to display the combo contents.
    -- (your selection data could be an index, a pointer to the object, an id for the object, a flag intrusively
    -- stored in the object itself, etc.)
    local combo_preview_value = self.items[self.item_current_idx]  -- pass the preview value visible before opening the combo

    if imgui.BeginCombo("combo 1", combo_preview_value, self.flags) then
        for n = 1, #self.items do
            local is_selected = self.item_current_idx == n
            if imgui.Selectable(self.items[n], is_selected) then -- fixme: selectable
                self.item_current_idx = n
            end

            -- Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if is_selected then
                imgui.SetItemDefaultFocus()
            end
        end

        imgui.EndCombo()
    end

    -- Simplified one-liner Combo() API, using values packed in a single constant string.
    -- This convenience for when the selection set is small and known at compile-time.
    self.item_current_2 = imgui.Combo("combo 2 (one-liner)", self.item_current_2, "aaaa\0bbbb\0cccc\0dddd\0eeee\0\0")

    -- Simplified one-liner Combo() using an array of strings.
    -- This is not very useful (may obsolete): prefer using BeginCombo()/EndCombo() for full control.
    self.item_current_3 = imgui.Combo("combo 3 (array)", self.item_current_3, self.items, #self.items)

    -- Simplified one-liner Combo() using an accessor function
    self.item_current_4 = imgui.Combo("combo 4 (function)", self.item_current_4, function (idx) return self.items[idx] end, #self.items)
end

--
-- WidgetsDemo - List boxes
--

local WidgetsDemo_ListBoxes = {
    items = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO" },
    item_current_idx = 1  -- Here we store our selection data as an index.
}

function WidgetsDemo_ListBoxes:Draw()
    -- Using the generic BeginListBox() API, you have full control over how to display the combo contents.
    -- (your selection data could be an index, a pointer to the object, an id for the object, a flag intrusively
    -- stored in the object itself, etc.)
    if imgui.BeginListBox('listbox 1') then
        for n, item in ipairs(self.items) do
            local is_selected = n == self.item_current_idx
            local _, clicked = imgui.Selectable(item, is_selected)
            if clicked then
                self.item_current_idx = n
            end

            -- Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if is_selected then
                imgui.SetItemDefaultFocus()
            end
        end
        imgui.EndListBox()
    end

    -- Custom size: use all width, 5 items tall
    imgui.Text('Full-width:')
    if imgui.BeginListBox('##listbox 2', ImVec2(mq.NumericLimits_Float()[1], 5 * imgui.GetTextLineHeightWithSpacing())) then
        for n, item in ipairs(self.items) do
            local is_selected = n == self.item_current_idx
            local _, clicked = imgui.Selectable(item, is_selected)
            if clicked then
                self.item_current_idx = n
            end

            -- Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
            if is_selected then
                imgui.SetItemDefaultFocus()
            end
        end
        imgui.EndListBox()
    end
end

--
-- WidgetsDemo - Selectables
--

local WidgetsDemo_Selectables = {
    -- part a
    a_selection = { false, true, false, false, false },

    -- part b
    b_selected = 0,

    -- part c
    c_selection = { false, false, false, false, false },

    -- part d
    d_selection = { false, false, false },

    -- part e: In Columns

    -- 10 values
    e_selection = {  false, false, false, false, false, false, false, false, false, false },

    -- part f: Grid

    -- 4x4 grid
    f_selection = { { true, false, false, false }, { false, true, false, false }, { false, false, true, false }, { false, false, false, true } },

    -- part g: alignment
    g_selection = { true, false, true, false, true, false, true, false, true },
}

function WidgetsDemo_Selectables:Draw()
    -- When selection state is bassed in to imgui.Selectable, the new selection state will be returned first, and the
    -- clicked flag will be return second.
    if imgui.TreeNode("Basic") then
        self.a_selection[1] = imgui.Selectable('1. I am selectable', self.a_selection[1])
        self.a_selection[2] = imgui.Selectable('2. I am selectable', self.a_selection[2])
        ImGui.Text('(I am not selectable)')
        self.a_selection[4] = imgui.Selectable('4. I am selectable', self.a_selection[4])
        local _, clicked = imgui.Selectable('5. I am double clickable', self.a_selection[4], ImGuiSelectableFlags.AllowDoubleClick)
        if clicked then
            if imgui.IsMouseDoubleClicked(ImGuiMouseButton.Left) then
                self.a_selection[4] = not self.a_selection[4]
            end
        end
        imgui.TreePop()
    end

    if imgui.TreeNode("Selection State: Single Selection") then
        for n = 1, 5 do
            local _, clicked = imgui.Selectable(string.format("Object %d", n), self.b_selected == n)
            if clicked then self.b_selected = n end
        end
        imgui.TreePop()
    end

    if imgui.TreeNode("Selection State: Multiple Selection") then
        imgui.HelpMarker("Hold CTRL and click to select multiple items.")
        local io = imgui.GetIO()
        for n = 1, 5 do
            local _, clicked = imgui.Selectable(string.format("Object %d", n), self.c_selection[n])
            if clicked then
                printf("clicked %d", n)
                if not io.KeyCtrl then
                    self.c_selection = { false, false, false, false, false }
                end
                printf("ctrl key %s", io.KeyCtrl)
                self.c_selection[n] = not self.c_selection[n]
            end
        end
        imgui.TreePop()
    end

    if imgui.TreeNode("Rendering more text into the same line") then
        self.d_selection[1] = imgui.Selectable("main.c", self.d_selection[1]); imgui.SameLine(300); imgui.Text(" 2,345 bytes")
        self.d_selection[2] = imgui.Selectable("Hello.cpp", self.d_selection[2]); imgui.SameLine(300); imgui.Text("12,345 bytes")
        self.d_selection[3] = imgui.Selectable("Hello.h", self.d_selection[3]); imgui.SameLine(300); imgui.Text(" 2,345 bytes")
        imgui.TreePop()
    end

    if imgui.TreeNode("In Columns") then
        if imgui.BeginTable("split1", 3, bit32.bor(ImGuiTableFlags.Resizable, ImGuiTableFlags.NoSavedSettings, ImGuiTableFlags.Borders)) then
            for n = 1, 10 do
                imgui.TableNextColumn()
                self.e_selection[n] = imgui.Selectable(string.format("Item %d", n), self.e_selection[n])
            end
            imgui.EndTable()

            imgui.Spacing()

            if imgui.BeginTable("split2", 3, bit32.bor(ImGuiTableFlags.Resizable, ImGuiTableFlags.NoSavedSettings, ImGuiTableFlags.Borders)) then
                for n = 1, 10 do
                    imgui.TableNextRow()
                    imgui.TableNextColumn()
                    self.e_selection[n] = imgui.Selectable(string.format("Item %d", n), self.e_selection[n])
                    imgui.TableNextColumn()
                    imgui.Text("Some other contents")
                    imgui.TableNextColumn()
                    imgui.Text("123456")
                end
                imgui.EndTable()
            end
        end
        imgui.TreePop()
    end

    if imgui.TreeNode("Grid") then
        local winningState = self:AllExampleFCellsSelected()
        if winningState then
            local time = imgui.GetTime()
            imgui.PushStyleVar(ImGuiStyleVar.SelectableTextAlign, ImVec2(
                0.5 + 0.5 * math.cos(time * 2.0), 0.5 + 0.5 * math.sin(time * 3.0)
            ))
        end

        for y = 1,4 do
            for x = 1,4 do
                if x > 1 then imgui.SameLine() end
                imgui.PushID(y * 4 + x)

                local _, clicked = imgui.Selectable("Sailor", self.f_selection[y][x], 0, ImVec2(50, 50))
                if clicked then
                    -- Toggle clicke dcell + toggle neighbors
                    self.f_selection[y][x] = not self.f_selection[y][x]
                    if x > 1 then self.f_selection[y][x - 1] = not self.f_selection[y][x - 1] end
                    if x < 4 then self.f_selection[y][x + 1] = not self.f_selection[y][x + 1] end
                    if y > 1 then self.f_selection[y - 1][x] = not self.f_selection[y - 1][x] end
                    if y < 4 then self.f_selection[y + 1][x] = not self.f_selection[y + 1][x] end
                end

                imgui.PopID()
            end
        end

        if winningState then imgui.PopStyleVar() end
        imgui.TreePop()
    end

    if imgui.TreeNode("Alignment") then
        imgui.HelpMarker(
            "By default, Selectables uses style.SelectableTextAlign but it can be overridden on a per-item " ..
            "basis using PushStyleVar(). You'll probably want to always keep your default situation to " ..
            "left-align otherwise it becomes difficult to layout multiple items on a same line")

        for y = 0, 2 do
            for x = 0, 2 do
                local alignment = ImVec2(x / 2, y / 2)
                if x > 0 then imgui.SameLine() end
                local index = y * 3 + x + 1

                imgui.PushStyleVar(ImGuiStyleVar.SelectableTextAlign, alignment)
                self.g_selection[index] = imgui.Selectable(string.format("(%.1f, %.1f)", alignment.x, alignment.y),
                    self.g_selection[index], ImGuiSelectableFlags.None, ImVec2(80, 80))
                imgui.PopStyleVar()
            end
        end
        imgui.TreePop()
    end
end

function WidgetsDemo_Selectables:AllExampleFCellsSelected()
    for x = 1, 4 do
        for y = 1, 4 do
            if not self.f_selection[x][y] then
                return false
           end
        end
    end
    return true
end

function ShowDemoWindowWidgets()

    -- if w.disable_all then
    --     imgui.BeginDisabled()
    -- end

    if imgui.TreeNode('Text') then

        imgui.TreePop()
    end

    if imgui.TreeNode('Images') then
        WidgetsDemo_Images:Draw()
        imgui.TreePop()
    end

    if imgui.TreeNode('Combo') then
        WidgetsDemo_Combos:Draw()
        imgui.TreePop()
    end

    if imgui.TreeNode('List boxes') then
        WidgetsDemo_ListBoxes:Draw()
        imgui.TreePop()
    end

    if imgui.TreeNode('Selectables') then
        WidgetsDemo_Selectables:Draw()
        imgui.TreePop()
    end
end

local openGUI = true
local shouldDrawGUI = true

function DemoWidgets()
    if not openGUI then return end
    openGUI, shouldDrawGUI = ImGui.Begin('Example: Widgets', openGUI)
    if shouldDrawGUI then
        ShowDemoWindowWidgets()
    end
    ImGui.End()
end
ImGui.Register('DemoWidgets', DemoWidgets)

while openGUI do
    mq.delay(1000) -- equivalent to '1s'
end