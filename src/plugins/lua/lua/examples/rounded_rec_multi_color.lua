local mq = require('mq')
local ImGui = require('ImGui')
local isRunning = true

local selectedFlag = "RoundCornersAll"
local roundingSize = 15
local rectSize = { width = 100, height = 100, }
local c_blue = ImVec4(0.093, 0.123, 0.612, 255.000)
local c_red = ImVec4(0.840, 0.076, 0.028, 255.000)

local drawFlags = {
    ["None"] = ImDrawFlags.None,
    ["RoundCornersAll"] = ImDrawFlags.RoundCornersAll,
    ["RoundCornersTop"] = ImDrawFlags.RoundCornersTop,
    ["RoundCornersBottom"] = ImDrawFlags.RoundCornersBottom,
    ["RoundCornersLeft"] = ImDrawFlags.RoundCornersLeft,
    ["RoundCornersRight"] = ImDrawFlags.RoundCornersRight,
    ["RoundCornersTopLeft"] = ImDrawFlags.RoundCornersTopLeft,
    ["RoundCornersTopRight"] = ImDrawFlags.RoundCornersTopRight,
    ["RoundCornersBottomLeft"] = ImDrawFlags.RoundCornersBottomLeft,
    ["RoundCornersBottomRight"] = ImDrawFlags.RoundCornersBottomRight,
}

local function RenderWin()
    ImGui.SetNextWindowSize(ImVec2(400, 400), ImGuiCond.FirstUseEver)
    local open, draw = ImGui.Begin("Rounded Multi Demo", true, ImGuiWindowFlags.None)
    if not open then isRunning = false end
    if draw then
        ImGui.Text("This is a demo of the Rounded Multicolor Rect")

        ImGui.Spacing()

        ImGui.SeparatorText("Demo 1: Basic Usage")
        ImGui.Text("This demonstrates the basic usage of Rounded Multicolor Rect with default settings.")

        if ImGui.BeginCombo("Rounding Flags", selectedFlag) then
            for k, v in pairs(drawFlags) do
                local isSelected = (selectedFlag == k)
                if ImGui.Selectable(k, isSelected) then
                    selectedFlag = k
                end
                if isSelected then ImGui.SetItemDefaultFocus() end
            end
            ImGui.EndCombo()
        end

        rectSize.width = ImGui.SliderFloat("Rect Width", rectSize.width, 4, 400)
        rectSize.height = ImGui.SliderFloat("Rect Height", rectSize.height, 4, 400)

        -- The rounding size should not be larger than half of the smaller dimension of the rectangle, otherwise it will look strange. So we calculate the larger dimension and use that to limit the rounding size.
        local tmpLarger = rectSize.width > rectSize.height and rectSize.width or rectSize.height
        if roundingSize > tmpLarger / 2 then roundingSize = tmpLarger / 2 end
        roundingSize = ImGui.SliderFloat("Rounding Size", roundingSize, 0, tmpLarger / 2)

        c_blue = ImGui.ColorEdit4("Color1", c_blue, ImGuiColorEditFlags.NoInputs)
        ImGui.SameLine()
        c_red = ImGui.ColorEdit4("Color2", c_red, ImGuiColorEditFlags.NoInputs)

        ImGui.Spacing()

        ImGui.Dummy(0, 10)

        local dl = ImGui.GetWindowDrawList()
        if ImGui.CollapsingHeader("Rects") then
            local top_left = ImGui.GetCursorScreenPosVec()
            local bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)
            local startPos = ImGui.GetCursorPosVec()
            dl:AddRectFilledMultiColorRounded(
                top_left,                              -- top left corner
                bottom_right,                          -- bottom right corner
                ImGui.ColorConvertFloat4ToU32(c_blue), -- UL color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- UR color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- BR color
                ImGui.ColorConvertFloat4ToU32(c_blue), -- BL color
                roundingSize,
                drawFlags[selectedFlag]
            )

            top_left.x = top_left.x + rectSize.width + 10
            bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)

            dl:AddRectFilledMultiColorRounded(
                top_left,
                bottom_right,
                ImGui.ColorConvertFloat4ToU32(c_blue), -- UL color
                ImGui.ColorConvertFloat4ToU32(c_blue), -- UR color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- BR color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- BL color
                roundingSize,
                drawFlags[selectedFlag]
            )

            top_left.x = top_left.x + rectSize.width + 10
            bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)

            dl:AddRectFilledMultiColorRounded(
                top_left,
                bottom_right,
                ImGui.ColorConvertFloat4ToU32(c_blue), -- color for top left
                ImGui.ColorConvertFloat4ToU32(c_red),  -- color for top right
                ImGui.ColorConvertFloat4ToU32(c_blue), -- color for bottom right
                ImGui.ColorConvertFloat4ToU32(c_red),  -- color for bottom left
                roundingSize,
                drawFlags[selectedFlag]
            )

            ImGui.SetCursorPos(startPos.x, startPos.y + rectSize.height + 2)
            ImGui.Dummy(0, 0)
            top_left = ImGui.GetCursorScreenPosVec()
            bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)
            startPos = ImGui.GetCursorPosVec()
        end


        if ImGui.CollapsingHeader("AddRectFilledMultiColorRoundedAnimated") then
            ImGui.TextWrapped("This demonstrates the animated version of Rounded Multicolor Rect. \nChange the colors and see the animation. ")

            ImGui.Spacing()

            ImGui.TextWrapped(
                "This uses ImAnim color blending for smother transitions between color changes. \nThe animation is tracked using the provided ID, so changing the colors will animate from the previous colors to the new ones.  \nIf you change the colors quickly, it will blend from the current color to the new color, creating a smooth transition effect.")

            local top_left = ImGui.GetCursorScreenPosVec()
            local bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)
            local startPos = ImGui.GetCursorPosVec()

            dl:AddRectFilledMultiColorRoundedAnimated(
                1,                                     -- integer ID for animation tracking
                top_left,                              -- top left corner
                bottom_right,                          -- bottom right corner
                ImGui.ColorConvertFloat4ToU32(c_blue), -- UL color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- UR color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- BR color
                ImGui.ColorConvertFloat4ToU32(c_blue), -- BL color
                roundingSize,
                drawFlags[selectedFlag]
            )


            top_left.x = top_left.x + rectSize.width + 10
            bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)

            dl:AddRectFilledMultiColorRoundedAnimated(
                2, -- "ID_Value", -- integer ID for animation tracking
                top_left,
                bottom_right,
                ImGui.ColorConvertFloat4ToU32(c_blue), -- UL color
                ImGui.ColorConvertFloat4ToU32(c_blue), -- UR color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- BR color
                ImGui.ColorConvertFloat4ToU32(c_red),  -- BL color
                roundingSize,
                drawFlags[selectedFlag]
            )

            top_left.x = top_left.x + rectSize.width + 10
            bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)

            dl:AddRectFilledMultiColorRoundedAnimated(
                3, -- "ID_Value", -- integer ID for animation tracking
                top_left,
                bottom_right,
                ImGui.ColorConvertFloat4ToU32(c_blue), -- color for top left
                ImGui.ColorConvertFloat4ToU32(c_red),  -- color for top right
                ImGui.ColorConvertFloat4ToU32(c_blue), -- color for bottom right
                ImGui.ColorConvertFloat4ToU32(c_red),  -- color for bottom left
                roundingSize,
                drawFlags[selectedFlag]
            )

            ImGui.SetCursorPos(startPos.x, startPos.y + rectSize.height + 2)
            ImGui.Dummy(0, 0)
        end
    end
    ImGui.End()
end

mq.imgui.init("Rounded Multi Demo", RenderWin)

while isRunning do
    mq.delay(100)
end
