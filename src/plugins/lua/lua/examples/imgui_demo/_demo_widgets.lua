---@diagnostic disable: empty-block

local mq = require('mq')
local imgui = require('ImGui')


local FLT_MIN, FLT_MAX = mq.NumericLimits_Float()


-- Helper to replace ImColor:HSV
---@param h number
---@param s number
---@param v number
---@return ImVec4
function HSV(h, s, v)
    local r, g, b
    r, g, b = imgui.ColorConvertHSVtoRGB(h, s, v)
    return ImVec4(r, g, b, 1.0)
end


--
-- Widgets Demo - Basic
--

local WidgetsDemo_Basic = {
    clicked = 0,
    check = true,
    e = 1,
    counter = 0,
    str0 = 'Hello, world!',
    str1 = '',
    i0 = 123,
    f0 = 0.001,
    d0 = 999999.00000001,
    f1 = 1.e10,
    vec4a = { 0.10, 0.20, 0.30, 0.44 },
    i1 = 50,
    i2 = 42,
    drags_f1 = 1.00,
    drags_f2 = 0.0067,
    sliders_i1 = 0,
    sliders_f1 = 0.123,
    sliders_f2 = 0.0,
    angle = 0,
    elem = 1,
    elem_count = 4,
    elem_names = {
        "Fire", "Earth", "Air", "Water"
    },
    col1 = { 1.0, 0.0, 0.2 },
    col2 = { 0.4, 0.7, 0.0, 0.5 },
    combo_items = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIIIIII", "JJJJ", "KKKKKKK" },
    combo_item_current = 1,
    list_items =  { "Apple", "Banana", "Cherry", "Kiwi", "Mango", "Orange", "Pineapple", "Strawberry", "Watermelon" },
    list_item_current = 2,
}

function WidgetsDemo_Basic:Draw()
    imgui.SeparatorText('General')

    if imgui.Button('Button') then
        self.clicked = self.clicked + 1
    end
    if bit32.band(self.clicked, 1) ~= 0 then
        imgui.SameLine()
        imgui.Text('Thanks for clicking me!')
    end

    self.check = imgui.Checkbox('checkbox', self.check)

    self.e = imgui.RadioButton('radio a', self.e, 1); imgui.SameLine()
    self.e = imgui.RadioButton('radio b', self.e, 2); imgui.SameLine()
    self.e = imgui.RadioButton('radio c', self.e, 3)

    -- Color buttons, demonstrate using PushID() to add unique identifier to the ID stack, and changing style
    for i = 0, 6 do
        if i > 0 then imgui.SameLine() end
        imgui.PushID(i)
        imgui.PushStyleColor(ImGuiCol.Button, HSV(i / 7.0, 0.6, 0.6))
        imgui.PushStyleColor(ImGuiCol.ButtonHovered, HSV(i / 7.0, 0.7, 0.7))
        imgui.PushStyleColor(ImGuiCol.ButtonActive, HSV(i /  7.0, 0.8, 0.8))
        imgui.Button('Click')
        imgui.PopStyleColor(3)
        imgui.PopID()
    end

    -- Use AlignTextToFramePadding() to align text baseline to the baseline of framed widgets elements
    -- (otherwise a Text+SameLine+Button sequence will have the text a little too high by default!)
    -- See 'Demo->Layout->Text Baseline Alignment' for details.
    imgui.AlignTextToFramePadding()
    imgui.Text('Hold to repeat:')
    imgui.SameLine()

    -- Arrow buttons with Repeater
    local spacing = imgui.GetStyle().ItemInnerSpacing.x
    imgui.PushButtonRepeat(true)
    if imgui.ArrowButton('##left', ImGuiDir.Left) then
        self.counter = self.counter - 1
    end
    imgui.SameLine(0.0, spacing)
    if imgui.ArrowButton('##right', ImGuiDir.Right) then
        self.counter = self.counter + 1
    end
    imgui.PopButtonRepeat()
    imgui.SameLine()
    imgui.Text("%d", self.counter)

    imgui.Button('Tooltip')
    imgui.SetItemTooltip('I am a tooltip')

    imgui.LabelText('label', 'Value')

    --
    -- Inputs
    --
    imgui.SeparatorText('Inputs')

    self.str0 = imgui.InputText('input text', self.str0)
    imgui.SameLine()
    imgui.HelpMarker(
        "Hold SHIFT or use mouse to select text.\n" ..
        "CTRL+Left/Right to word jump.\n" ..
        "CTRL+A or Double-Click to select all.\n" ..
        "CTRL+X,CTRL+C,CTRL+V clipboard.\n" ..
        "CTRL+Z,CTRL+Y undo/redo.\n" ..
        "ESCAPE to revert."
    )

    self.str1 = imgui.InputTextWithHint('input text (w/ hint)', 'enter text here', self.str1)
    self.i0 = imgui.InputInt('input int', self.i0)
    self.f0 = imgui.InputFloat('input float', self.f0, 0.01, 1.0, "%.3f")
    self.d0 = imgui.InputDouble('input double', self.d0, 0.01, 1.0, "%.8f")

    self.f1 = imgui.InputFloat('input scientific', self.f1, 0.0, 0.0, "%e")
    imgui.SameLine()
    imgui.HelpMarker(
        "You can input value using the scientific notation,\n" ..
        "  e.g. \"1e+8\" becomes \"100000000\"."
    )

    self.vec4a = imgui.InputFloat3('input float3', self.vec4a)

    --
    -- Drags
    --
    imgui.SeparatorText('Drags')

    self.i1 = imgui.DragInt('drag int', self.i1, 1)
    imgui.SameLine()
    imgui.HelpMarker(
        "Click and drag to edit value.\n" ..
        "Hold SHIFT/ALT for faster/slower edit.\n" ..
        "Double-click or CTRL+click to input value."
    )

    self.i2 = imgui.DragInt('drag int 0..100', self.i2, 1, 0, 100, '%d%%', ImGuiSliderFlags.AlwaysClamp)

    self.drags_f1 = imgui.DragFloat('drag float', self.drags_f1, 0.005)
    self.drags_f2 = imgui.DragFloat('drag small float', self.drags_f2, 0.0001, 0.0, 0.0, '%.06f ns')

    --
    -- Sliders
    --
    imgui.SeparatorText('Sliders')


    self.sliders_i1 = imgui.SliderInt('slider int', self.sliders_i1, -1, 3)
    imgui.SameLine()
    imgui.HelpMarker("CTRL+click to input value.")

    self.sliders_f1 = imgui.SliderFloat('slider float', self.sliders_f1, 0.0, 1.0, 'ratio = %.3f')
    self.sliders_f2 = imgui.SliderFloat('slider float (log)', self.sliders_f2, -10.0, 10.0, '%.4f', ImGuiSliderFlags.Logarithmic)

    self.angle = imgui.SliderAngle('slider angle', self.angle)

    -- Using the format string to display a name instead of an integer.
    -- Here we completely omit '%d' from the format string, so it'll only display a name.
    -- This technique can also be used with DragInt().
    local elem = self.elem
    local elem_name = (elem >= 1 and elem <= self.elem_count) and self.elem_names[elem] or 'Unknown'
    self.elem = imgui.SliderInt('slider enum', elem, 1, self.elem_count, elem_name) -- UseImGuiSlidersNoInput flag to disable CTRL+Click here
    imgui.SameLine()
    imgui.HelpMarker("Using the format string parameter to display a name instead of the underlying integer")

    --
    -- Selectors/Pickers
    --
    imgui.SeparatorText('Selectors/Pickers')

    self.col1 = imgui.ColorEdit3('color 1', self.col1)
    imgui.SameLine()
    imgui.HelpMarker(
        "Click on the color square to open a color picker.\n" ..
        "Click and hold to use drag and drop.\n" ..
        "Right-click on the color square to show options.\n" ..
        "CTRL+click on individual component to input value."
    )

    self.col2 = imgui.ColorEdit4('color 2', self.col2)

    -- Using the _simplified_ one-liner Combo() api here
    -- See "Combo" section for examples of how to use the more flexible BeginCombo()/EndCombo() api.
    self.combo_item_current = imgui.Combo('combo', self.combo_item_current, self.combo_items)
    imgui.SameLine()
    imgui.HelpMarker(
        "Using the simplified one-liner Combo API here.\nRefer to the \"Combo\" section below for an explanation of how to use the more flexible and general BeginCombo/EndCombo API."
    )

    -- Using the _simplified_ one-liner ListBox() api here
    -- See "List boxes" section for examples of how to use the more flexible BeginListBox()/EndListBox() api.
    self.list_item_current = imgui.ListBox('listbox', self.list_item_current, self.list_items, #self.list_items, 4)
    imgui.SameLine()
    imgui.HelpMarker(
        "Using the simplified one-liner ListBox API here.\nRefer to the \"List boxes\" section below for an explanation of how to use the more flexible and general BeginListBox/EndListBox API."
    )
end


--
-- Widgets Demo - Tooltips
--

local WidgetsDemo_Tooltips = {
    arr = { 0.6, 0.1, 1.0, 0.5, 0.92, 0.1, 0.2 },
    always_on = 1,
}

function WidgetsDemo_Tooltips:Draw()
    -- Tooltips are windows following the mouse. They do not take focus away.
    imgui.SeparatorText('General')

    -- Typical use cases:
    -- - Short-form (text only):      SetItemTooltip("Hello")
    -- - Short-form (any contents):   if BeginItemTooltip() then Text("Hello"); EndTooltip() end

    -- - Full-form (text only):       if IsItemHovered(...) then SetTooltip("Hello") end
    -- - Full-form (any contents):    if IsItemHovered(...) and BeginTooltip() then Text("Hello"); EndTooltip() end

    imgui.HelpMarker(
        "Tooltip are typically created by using a IsItemHovered() + SetTooltip() sequence.\n\n" ..
        "We provide a helper SetItemTooltip() function to perform the two with standards flags."
    )

    local sz = ImVec2(-FLT_MIN, 0.0)

    imgui.Button('Basic', sz)
    imgui.SetItemTooltip('I am a tooltip')

    imgui.Button('Fancy', sz)
    if imgui.BeginItemTooltip() then
        imgui.Text('I am a fancy tooltip')
        imgui.PlotLines('Curve', self.arr)
        imgui.Text('Sin(time) = %f', math.sin(imgui.GetTime()))

        imgui.EndTooltip()
    end

    --
    -- Always On
    --
    imgui.SeparatorText('Always On')

    self.always_on = imgui.RadioButton('Off', self.always_on, 1)
    imgui.SameLine()
    self.always_on = imgui.RadioButton('Always On (Simple)', self.always_on, 2)
    imgui.SameLine()
    self.always_on = imgui.RadioButton('Always On (Advanced)', self.always_on, 3)

    if self.always_on == 2 then
        imgui.SetTooltip('I am following you around.')
    elseif self.always_on == 3 and imgui.BeginTooltip() then
        imgui.ProgressBar(math.sin(imgui.GetTime()) * 0.5 + 0.5, ImVec2(imgui.GetFontSize() * 25, 0))
        imgui.EndTooltip()
    end

    --
    -- Custom
    --
    imgui.SeparatorText('Custom')

    imgui.HelpMarker(
        "Passing ImGuiHoveredFlags_ForTooltip to IsItemHovered() is the preferred way to standardize" ..
        "tooltip activation details across your application. You may however decide to use custom" ..
        "flags for a specific tooltip instance."
    )

    -- The following examples are passed for documentation purpose but may not be useful to most users.
    -- Passing ImGuiHoveredFlags_ForTooltip to IsItemHovered() will pull ImGuiHoveredFlags flags values from
    -- 'style.HoverFlagsForTooltipMouse' or 'style.HoverFlagsForTooltipNav' depending on whether mouse or gamepad/keyboard is being used.
    -- With default settings, ImGuiHoveredFlags.ForTooltip is equivalent to ImGuiHoveredFlags.DelayShort + ImGuiHoveredFlags.Stationary.
    imgui.Button('Manual', sz)
    if imgui.IsItemHovered(ImGuiHoveredFlags.ForTooltip) then
        imgui.SetTooltip('I am a manually emitted tooltip.')
    end

    imgui.Button('DelayNone', sz)
    if imgui.IsItemHovered(ImGuiHoveredFlags.DelayNone) then
        imgui.SetTooltip('I am a tooltip with no delay.')
    end

    imgui.Button('DelayShort', sz)
    if imgui.IsItemHovered(bit32.bor(ImGuiHoveredFlags.DelayShort, ImGuiHoveredFlags.NoSharedDelay)) then
        imgui.SetTooltip('I am a tooltip with a short delay (%.02f sec).', imgui.GetStyle().HoverDelayShort)
    end

    imgui.Button('DelayLong', sz)
    if imgui.IsItemHovered(bit32.bor(ImGuiHoveredFlags.DelayNormal, ImGuiHoveredFlags.NoSharedDelay)) then
        imgui.SetTooltip('I am a tooltip with a long delay (%.02f sec).', imgui.GetStyle().HoverDelayNormal)
    end

    imgui.Button('Stationary', sz)
    if imgui.IsItemHovered(ImGuiHoveredFlags.Stationary) then
        imgui.SetTooltip('I am a tooltip requiring mouse to be stationary before activating.')
    end

    -- Using ImGuiHoveredFlags.ForTooltip will pull flags from 'style.HoverFlagsForTooltipMouse' or 'style.HoverFlagsForTooltipNav',
    -- which default value include the ImGuiHoveredFlags.AllowWhenDisabled flag.
    -- As a result, Set
    imgui.BeginDisabled()
    imgui.Button('Disabled item', sz)
    imgui.EndDisabled()
    if imgui.IsItemHovered(ImGuiHoveredFlags.ForTooltip) then
        imgui.SetTooltip('I am a tooltip for a disabled item')
    end
end

--
-- Widgets Demo - Images
--

local WidgetsDemo_Images = {
    pressed_count = 0,
    use_text_color_for_tint = false,
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

    self.use_text_color_for_tint = imgui.Checkbox('Use Text Color for Tint', self.use_text_color_for_tint)
    imgui.Text(string.format("%.0fx%.0f", my_tex_w, my_tex_h))
    local pos = imgui.GetCursorScreenPosVec()
    local uv_min = ImVec2(0, 0)
    local uv_max = ImVec2(1, 1)
    local tint_col = self.use_text_color_for_tint and imgui.GetStyleColorVec4(ImGuiCol.Text) or ImVec4(1, 1, 1, 1)
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
    if imgui.BeginListBox('##listbox 2', ImVec2(mq.NumericLimits_Float(), 5 * imgui.GetTextLineHeightWithSpacing())) then
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

local disable_all = false



function ShowDemoWindowWidgets()
    if not imgui.CollapsingHeader("Widgets") then
        return
    end

    if disable_all then
         imgui.BeginDisabled()
    end

    if imgui.TreeNode('Basic') then
        WidgetsDemo_Basic:Draw()
        imgui.TreePop()
    end

    if imgui.TreeNode('Tooltips') then
        WidgetsDemo_Tooltips:Draw()
        imgui.TreePop()
    end

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

    if disable_all then
        imgui.EndDisabled()
    end

    if imgui.TreeNode("Disable block") then
        disable_all = imgui.Checkbox("Disable entire section above", disable_all)
        imgui.SameLine()
        imgui.HelpMarker("Demonstrate using BeginDisabled()/EndDisabled() across this section")
        imgui.TreePop()
    end
end

return ShowDemoWindowWidgets
