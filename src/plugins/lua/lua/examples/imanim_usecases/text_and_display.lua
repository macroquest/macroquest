local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 11: Animated Counter / Statistics
-- ============================================================
local function ShowUsecase_AnimatedCounter()
    -- TODO: Implement Animated Counter Usecase
end

-- ============================================================
-- USECASE 12: Typewriter Text Effect
-- ============================================================
local function ShowUsecase_TypewriterText()
    -- TODO: Implement Typewriter Text Effect
end

-- ============================================================
-- 35. Animated Tags/Chips
-- Removable tags with smooth add/remove animations
-- ============================================================
local function ShowUsecase_AnimatedTags()
    -- TODO: Implement Animated Tags/Chips
end

-- ============================================================
-- USECASE: Highlight Text
-- ============================================================
local function ShowUsecase_HighlightText()
    -- TODO: Implement Highlight Text
end

-- ============================================================
-- USECASE: Animated Label
-- ============================================================
local function ShowUsecase_AnimatedLabel()
    -- TODO: Implement Animated Label
end

-- ============================================================
-- USECASE: Scrolling Marquee
-- ============================================================
local function ShowUsecase_ScrollingMarquee()
    -- TODO: Implement Scrolling Marquee
end

-- ============================================================
-- USECASE: Countdown Display
-- ============================================================
local function ShowUsecase_CountdownDisplay()
    -- TODO: Implement Countdown Display
end

-- ============================================================
-- USECASE: Word Cloud
-- ============================================================
local function ShowUsecase_WordCloud()
    -- TODO: Implement Word Cloud
end

-- ============================================================
-- USECASE: Animated Tooltip
-- ============================================================
local function ShowUsecase_AnimatedTooltipText()
    -- TODO: Implement Animated Tooltip
end

-- ============================================================
-- USECASE: Character Reveal
-- ============================================================
local function ShowUsecase_CharacterReveal()
    -- TODO: Implement Character Reveal
end

local function RunTextAndDisplayDemo()
    -- ========================================
    -- TEXT & DISPLAY
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Text & Display") then
        imgui.Indent()
        common.USECASE_ITEM('Animated Counter', ShowUsecase_AnimatedCounter)
        common.USECASE_ITEM('Typewriter Text', ShowUsecase_TypewriterText)
        common.USECASE_ITEM('Animated Tags', ShowUsecase_AnimatedTags)
        common.USECASE_ITEM('Highlight Text', ShowUsecase_HighlightText)
        common.USECASE_ITEM('Animated Label', ShowUsecase_AnimatedLabel)
        common.USECASE_ITEM('Scrolling Marquee', ShowUsecase_ScrollingMarquee)
        common.USECASE_ITEM('Countdown Display', ShowUsecase_CountdownDisplay)
        common.USECASE_ITEM('Word Cloud', ShowUsecase_WordCloud)
        common.USECASE_ITEM('Animated Tooltip Text', ShowUsecase_AnimatedTooltipText)
        common.USECASE_ITEM('Character Reveal', ShowUsecase_CharacterReveal)
        imgui.Unindent()
    end
end

return RunTextAndDisplayDemo
