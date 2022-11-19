---@type Mq
local mq = require('mq')
---@type ImGui
local imgui = require 'ImGui'

local w = {
    disable_all = false
}

-- structure holding globals for the combo demo
local cg = {
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

function ShowDemoWindowWidgets()
    local pressed = false

    -- if w.disable_all then
    --     imgui.BeginDisabled()
    -- end

    if imgui.TreeNode('Text') then
        
        imgui.TreePop()
    end

    if imgui.TreeNode('Images') then
        imgui.TreePop()
    end

    if imgui.TreeNode('Combo') then
        cg.flags = imgui.CheckboxFlags("ImGuiComboFlags.PopupAlignLeft", cg.flags, ImGuiComboFlags.PopupAlignLeft)
        imgui.SameLine()
        imgui.HelpMarker("Only makes a difference if the popup is larger than the combo")
        cg.flags, pressed = imgui.CheckboxFlags("ImGuiComboFlags.NoArrowButton", cg.flags, ImGuiComboFlags.NoArrowButton)
        if pressed then  -- clear the other flag, as we cannot combine both
            cg.flags = bit32.setflag(cg.flags, ImGuiComboFlags.NoPreview, false)
        end
        cg.flags, pressed = imgui.CheckboxFlags("ImGuiComboFlags.NoPreview", cg.flags, ImGuiComboFlags.NoPreview)
        if pressed then  -- clear the other flag, as we cannot combine both
            cg.flags = bit32.setflag(cg.flags, ImGuiComboFlags.NoArrowButton, false)
        end

        -- Using the generic BeginCombo() API, you have full control over how to display the combo contents.
        -- (your selection data could be an index, a pointer to the object, an id for the object, a flag intrusively
        -- stored in the object itself, etc.)
        local combo_preview_value = cg.items[cg.item_current_idx]  -- pass the preview value visible before opening the combo

        if imgui.BeginCombo("combo 1", combo_preview_value, cg.flags) then
            for n = 1, #cg.items do
                local is_selected = cg.item_current_idx == n
                if imgui.Selectable(cg.items[n], is_selected) then -- fixme: selectable
                    cg.item_current_idx = n
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
        cg.item_current_2 = imgui.Combo("combo 2 (one-liner)", cg.item_current_2, "aaaa\0bbbb\0cccc\0dddd\0eeee\0\0")

        -- Simplified one-liner Combo() using an array of strings.
        -- This is not very useful (may obsolete): prefer using BeginCombo()/EndCombo() for full control.
        cg.item_current_3 = imgui.Combo("combo 3 (array)", cg.item_current_3, cg.items, #cg.items)

        -- Simplified one-liner Combo() using an accessor function
        cg.item_current_4 = imgui.Combo("combo 4 (function)", cg.item_current_4, function (idx) return cg.items[idx] end, #cg.items)

        imgui.TreePop()
    end
end

local openGUI = true
local shouldDrawGUID = true

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