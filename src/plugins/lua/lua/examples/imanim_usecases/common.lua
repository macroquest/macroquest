local imgui = require('ImGui')

local common = {
    open_all = 0,
    IM_COL32_WHITE = IM_COL32(255, 255, 255, 255)
}

function common.ApplyOpenAll()
    if common.open_all ~= 0 then
        imgui.SetNextItemOpen(common.open_all > 0, ImGuiCond.Always)
    end
end

function common.GetDeltaTime()
    local dt = imgui.GetIO().DeltaTime
    if dt <= 0 then dt = 1.0 / 60.0 end
    if dt > 0.1 then dt = 0.1 end
    return dt
end

function common.ColorAlpha(col, a)
    return bit32.bor(bit32.band(col, 0xffffff), bit32.lshift(math.floor(a), 24))
end

function common.USECASE_ITEM(name, func)
    common.ApplyOpenAll()
    if imgui.TreeNode(name) then func() imgui.TreePop() end
    imgui.Spacing()
end

return common
