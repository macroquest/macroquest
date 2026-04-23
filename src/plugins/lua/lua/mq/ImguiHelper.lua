local ImguiHelper = { _version = '1.0', author = 'Knightly' }

local mq = require('mq')
require 'ImGui'

ImguiHelper.Popup = {
    Modal = function(title, text, buttons)
            if not buttons or #buttons == 0 then
                return 0
            end
            if not mq.canDelay() then
                print("ImguiHelper.Popup.Modal cannot block in the current context (yielding is disabled, typically during require). Ensure the caller is not loading as a module.", 2)
                mq.exit()
            end
            local last_return = 0
            local openGUI = true

            local function DisplayModalGUI()
                if not openGUI then return end
                ImGui.OpenPopup(title)
                local vp = ImGui.GetMainViewport()
                ImGui.SetNextWindowPos(vp:GetCenter(), ImGuiCond.Appearing, ImVec2(0.5, 0.5))
                local wrapW = math.min(ImGui.GetFontSize() * 40, vp.WorkSize.x * 0.6)
                local popupFlags = bit32.bor(ImGuiWindowFlags.AlwaysAutoResize, ImGuiWindowFlags.NoResize, ImGuiWindowFlags.NoSavedSettings)
                if ImGui.BeginPopupModal(title, nil, popupFlags) then
                    ImGui.PushTextWrapPos(ImGui.GetCursorPosX() + wrapW)
                    ImGui.TextWrapped(text)
                    ImGui.PopTextWrapPos()
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