mq = require('mq')

local GroupAssist = function()
    local currentTargetID = mq.TLO.Target.ID()
    local groupAssist = function () return mq.TLO.Me.GroupAssistTarget end -- Note the lack of parentheses here
    local assistHPs = groupAssist().PctHPs()
    if currentTargetID ~= groupAssist().ID() and assistHPs ~= nil and assistHPs <= 98 then
        print('Targeting '..groupAssist().DisplayName())
        groupAssist().DoTarget()
    end
end

local openGUI = true
local shouldDrawGUI = true

local AssistGUI = function()
    openGUI, shouldDrawGUI = ImGui.Begin('Assist GUI', openGUI)
    if shouldDrawGUI then
        local pctHPs = mq.TLO.Me.GroupAssistTarget.PctHPs()
        if not pctHPs then pctHPs = 0 end
        local ratioHPs = pctHPs / 100

        local targetName = mq.TLO.Me.GroupAssistTarget.DisplayName()
        if not targetName then targetName = 'No Target' end

        ImGui.PushStyleColor(ImGuiCol.PlotHistogram, 1 - ratioHPs, ratioHPs, 0, 1)
        ImGui.PushStyleColor(ImGuiCol.Text, 0.5, 0.5, 0.5, 1)
        ImGui.ProgressBar(ratioHPs, -1, -1, targetName..': '..pctHPs..'%')
        ImGui.PopStyleColor(2)

        ImGui.End()
    end
end

mq.imgui.init('assistGUI', AssistGUI)
mq.bind('/assgui', function()
    openGUI = not openGUI
end)

local terminate = false
mq.bind('/assend', function() terminate = true end)

while not terminate do
    GroupAssist()
    mq.delay(1000) -- equivalent to '1s'
end