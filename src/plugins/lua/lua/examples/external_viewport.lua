local mq = require('mq')
local imgui = require('ImGui')

local openGUI = true
local shouldDrawGUI = true
local showGUI = true
local window_class = nil
local topMost = true
local attachToGameWindow = false
local terminate = false

local function GUI()
    if not showGUI then
        return
    end
    if window_class == nil then
        window_class = ImGuiWindowClass()
    end
    if attachToGameWindow then
        local mainViewport = imgui.GetMainViewport()
        window_class.ParentViewportId = mainViewport and mainViewport.ID or 0
        topMost = false
    else
        window_class.ParentViewportId = 0
    end
    local viewport_flags = 0
    if not attachToGameWindow then
        viewport_flags = ImGuiViewportFlags.NoAutoMerge
        if topMost then
            viewport_flags = bit32.bor(viewport_flags, ImGuiViewportFlags.TopMost)
        end
    end
    window_class.ViewportFlagsOverrideSet = viewport_flags
    window_class.ViewportFlagsOverrideClear = ImGuiViewportFlags.NoTaskBarIcon

    imgui.SetNextWindowClass(window_class)
    local window_flags = attachToGameWindow and 0 or ImGuiWindowFlags.NoDocking
    openGUI, shouldDrawGUI = imgui.Begin('Detached Game State', openGUI, window_flags)
    if not openGUI then
        showGUI = false
        terminate = true
        imgui.End()
        return
    end
    if not shouldDrawGUI then
        imgui.End()
        return
    end

    local gameState = mq.TLO.EverQuest.GameState() or -1
    local zone = mq.TLO.Zone.ShortName() or 'Unknown'
    local me = mq.TLO.Me
    local meName = me.Name() or 'None'
    local meHP = me.PctHPs() or 0
    local meMana = me.PctMana() or 0
    local meEnd = me.PctEndurance() or 0
    local meX = me.X() or 0
    local meY = me.Y() or 0
    local meZ = me.Z() or 0

    imgui.Text('GameState: ' .. tostring(gameState))
    imgui.Text('Zone: ' .. tostring(zone))
    imgui.Separator()
    imgui.Text('Me: ' .. tostring(meName))
    imgui.Text('HP: ' .. tostring(meHP) .. '%  Mana: ' .. tostring(meMana) .. '%  End: ' .. tostring(meEnd) .. '%')
    imgui.Text('Pos: ' .. tostring(meX) .. ', ' .. tostring(meY) .. ', ' .. tostring(meZ))
    attachToGameWindow = imgui.Checkbox('Attach to Game Window', attachToGameWindow)
    imgui.BeginDisabled(attachToGameWindow)
    topMost = imgui.Checkbox('TopMost', topMost)
    imgui.EndDisabled()

    imgui.End()
end

mq.imgui.init('DetachedGameState', GUI)
mq.bind('/extwin', function() showGUI = not showGUI end)
mq.bind('/extend', function() terminate = true end)

while not terminate do
    mq.delay(100)
end
