local mq = require('mq')
local ImGui = require('ImGui')
local isRunning = true

local selectedFlag = "RoundCornersAll"
local roundingSize = 0
local rectSize = { width = 100, height = 100, }
local startCol = ImVec4(1, 1, 0, 1)
local endCol = ImVec4(0,1, 0 ,1)

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

local gradientDir = {
	['Horizontal'] = ImGradientDir.Horizontal,
	['Vertical'] = ImGradientDir.Vertical,
	['DiagTopLeftToBottomRight'] = ImGradientDir.DiagTopLeftBottomRight,
	['DiagTopRightToBottomLeft'] = ImGradientDir.DiagTopRightBottomLeft,
}

local selectedGradientDir = 'Horizontal'

local function RenderWin()
	ImGui.SetNextWindowSize(ImVec2(400, 400), ImGuiCond.FirstUseEver)
	local open, draw = ImGui.Begin("Gradient Fill Demo", true, ImGuiWindowFlags.None)
	if not open then isRunning = false end
	if draw then
		ImGui.Text("This is a demo of the 2 color Gradient Rect")

		ImGui.Spacing()

		ImGui.SeparatorText("Demo 1: Basic Usage")
		ImGui.Text("This demonstrates the basic usage of 2 color Gradient Rect and options")

		rectSize.width = ImGui.SliderFloat("Rect Width", rectSize.width, 4, 400)
		rectSize.height = ImGui.SliderFloat("Rect Height", rectSize.height, 4, 400)

		-- The rounding size should not be larger than half of the smaller dimension of the rectangle, otherwise it will look strange. So we calculate the larger dimension and use that to limit the rounding size.
		local tmpLarger = rectSize.width < rectSize.height and rectSize.width or rectSize.height
		if roundingSize > tmpLarger / 2 then roundingSize = tmpLarger / 2 end
		roundingSize = ImGui.SliderFloat("Rounding Size", roundingSize, 0, tmpLarger / 2)

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

		if ImGui.RadioButton("Horizontal Gradient", selectedGradientDir == 'Horizontal') then
			selectedGradientDir = 'Horizontal'
		end
		ImGui.SameLine()
		if ImGui.RadioButton("Vertical Gradient", selectedGradientDir == 'Vertical') then
			selectedGradientDir = 'Vertical'
		end

		if ImGui.RadioButton("Diagonal TL-BR Gradient", selectedGradientDir == 'DiagTopLeftToBottomRight') then
			selectedGradientDir = 'DiagTopLeftToBottomRight'
		end
		ImGui.SameLine()
		if ImGui.RadioButton("Diagonal TR-BL Gradient", selectedGradientDir == 'DiagTopRightToBottomLeft') then
			selectedGradientDir = 'DiagTopRightToBottomLeft'
		end

		startCol = ImGui.ColorEdit4("StartColor", startCol, ImGuiColorEditFlags.NoInputs)
		ImGui.SameLine()
		endCol = ImGui.ColorEdit4("EndColor", endCol, ImGuiColorEditFlags.NoInputs)

		ImGui.Spacing()

		ImGui.Dummy(0, 10)

		local dl = ImGui.GetWindowDrawList()
		local top_left = ImGui.GetCursorScreenPosVec()
		local bottom_right = ImVec2(top_left.x + rectSize.width, top_left.y + rectSize.height)
		local startPos = ImGui.GetCursorPosVec()

		dl:AddRectGradientFilled(
			top_left, bottom_right,
			ImGui.GetColorU32(startCol),
			ImGui.GetColorU32(endCol),
			gradientDir[selectedGradientDir],
			roundingSize,
			drawFlags[selectedFlag]
		)
		ImGui.SetCursorPos(startPos.x, startPos.y + rectSize.height + 5)
		ImGui.Dummy(0, 0)
	end
	ImGui.End()
end

mq.imgui.init("Gradient Fill Demo", RenderWin)

while isRunning do
	mq.delay(100)
end
