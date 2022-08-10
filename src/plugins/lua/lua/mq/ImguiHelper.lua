ImguiHelper = { _version = '1.0', author = 'Knightly' }

local mq = require('mq')
require 'ImGui'

ImguiHelper.Popup = {
    Modal = function(title, text, buttons)
            last_return = 0
            openGUI = true
            shouldDrawGUI = true

            function DisplayModalGUI()
                if not openGUI then return end
                local flags = bit32.bor(ImGuiWindowFlags.NoDecoration, ImGuiWindowFlags.NoInputs, ImGuiWindowFlags.NoNav, ImGuiWindowFlags.NoDocking)
                ImGui.SetNextWindowBgAlpha(0)
                ImGui.SetNextWindowSize(0, 0)
                openGUI, shouldDrawGUI = ImGui.Begin('Modal Demo', openGUI, flags)
                if shouldDrawGUI then
                    ImGui.OpenPopup(title)
                    if ImGui.BeginPopupModal(title) then
                        ImGui.Text(text)
                        ImGui.Separator()
                        for order, button in ipairs(buttons) do
                            if ImGui.Button(button) then
                                openGUI = false
                                last_return = order
                                ImGui.CloseCurrentPopup()
                            end
                            ImGui.SameLine()
                        end
                    end
                    ImGui.EndPopup()
                end
                ImGui.End()
            end

            ImGui.Register('DisplayModalGUI'..title, DisplayModalGUI)

            while openGUI do
                mq.delay(10)
            end

            return last_return
        end,
}

return ImguiHelper