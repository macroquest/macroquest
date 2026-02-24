local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 1: Animated Button with Hover/Press States
-- ============================================================
local function ShowUsecase_AnimatedButton()
    -- TODO: Implement me
end


-- ============================================================
-- USECASE 7: Progress Bar with Segments
-- ============================================================
local function ShowUsecase_ProgressBar()
    -- TODO: Implement Progress Bar with Segments
end

-- ============================================================
-- USECASE 20: Pulse Notification Badge
-- ============================================================
local function ShowUsecase_PulseBadge()
    -- TODO: Implement Pulse Notification Badge
end

-- ============================================================
-- 36. Pending Button
-- Button with loading spinner when processing
-- ============================================================
local function ShowUsecase_PendingButton()
    -- TODO: Implement Pending Button
end

-- ============================================================
-- 37. Animated Slider
-- Custom slider with smooth thumb and track animation
-- ============================================================
local function ShowUsecase_AnimatedSlider()
    -- TODO: Implement Animated Slider
end

-- ============================================================
-- USECASE: Icon Button Rotation
-- ============================================================
local function ShowUsecase_IconButtonRotation()
    -- TODO: Implement Icon Button Rotation
end

-- ============================================================
-- USECASE: Like Heart Button
-- ============================================================
local function ShowUsecase_LikeHeartButton()
    -- TODO: Implement Like Heart Button
end

-- ============================================================
-- USECASE: Button Glow Effect
-- ============================================================
local function ShowUsecase_ButtonGlow()
    -- TODO: Implement Button Glow Effect
end

-- ============================================================
-- USECASE: Download Progress Button
-- ============================================================
local function ShowUsecase_DownloadProgressButton()
    -- TODO: Implement Download Progress Button
end

-- ============================================================
-- USECASE: Submit Button States
-- ============================================================
local function ShowUsecase_SubmitButtonStates()
    -- TODO: Implement Submit Button States
end

local function RunButtonsAndIndicatorsDemo()
    -- ========================================
    -- BUTTONS & INDICATORS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Buttons & Indicators") then
        imgui.Indent()
        common.USECASE_ITEM('Animated Buttons', ShowUsecase_AnimatedButton)
        common.USECASE_ITEM('Progress Bar', ShowUsecase_ProgressBar)
        common.USECASE_ITEM('Pulse Badge', ShowUsecase_PulseBadge)
        common.USECASE_ITEM('Pending Button', ShowUsecase_PendingButton)
        common.USECASE_ITEM('Animated Slider', ShowUsecase_AnimatedSlider)
        common.USECASE_ITEM('Icon Button Rotation', ShowUsecase_IconButtonRotation)
        common.USECASE_ITEM('Button Glow Effect', ShowUsecase_ButtonGlow)
        common.USECASE_ITEM('Like Heart Button', ShowUsecase_LikeHeartButton)
        common.USECASE_ITEM('Download Progress Button', ShowUsecase_DownloadProgressButton)
        common.USECASE_ITEM('Submit Button States', ShowUsecase_SubmitButtonStates)
        imgui.Unindent()
    end
end

return RunButtonsAndIndicatorsDemo
