local ImguiHelper = { _version = '1.0', author = 'Knightly' }

local mq = require('mq')
require 'ImGui'

ImguiHelper.Popup = {
    Modal = function(title, text, buttons)
            if not buttons or #buttons == 0 then
                return 0
            end
            local last_return = 0
            local openGUI = true
            local shouldDrawGUI = true

            local function DisplayModalGUI()
                if not openGUI then return end
                local flags = bit32.bor(ImGuiWindowFlags.NoDecoration, ImGuiWindowFlags.NoInputs, ImGuiWindowFlags.NoNav, ImGuiWindowFlags.NoDocking)
                ImGui.SetNextWindowBgAlpha(0)
                ImGui.SetNextWindowSize(0, 0)
                openGUI, shouldDrawGUI = ImGui.Begin('##' .. title, openGUI, flags)
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
                        ImGui.EndPopup()
                    end
                end
                ImGui.End()
            end

            ImGui.Register(title, DisplayModalGUI)

            local startModal = os.time()
            while openGUI and os.difftime(os.time(), startModal) < 30 do
                mq.delay(10)
            end

            ImGui.Unregister(title)

            return last_return
        end,
}

return ImguiHelper