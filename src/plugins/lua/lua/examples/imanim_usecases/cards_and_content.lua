local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')



-- ============================================================
-- USECASE 5: Card Hover Effects
-- ============================================================
local function ShowUsecase_CardHover()
    -- TODO: Implement Card Hover Effects
end

-- ============================================================
-- USECASE 17: Swipe Cards (Tinder-style)
-- ============================================================
local function ShowUsecase_SwipeCards()
    -- TODO: Implement Swipe Cards (Tinder-style)
end

-- ============================================================
-- USECASE 21: Flip Card
-- ============================================================
local function ShowUsecase_FlipCard()
    -- TODO: Implement Flip Card
end

-- ============================================================
-- USECASE 22: Carousel / Image Slider
-- ============================================================
local function ShowUsecase_Carousel()
    -- TODO: Implement Carousel / Image Slider
end

-- ============================================================
-- USECASE: Expandable List Item
-- ============================================================
local function ShowUsecase_ExpandableListItem()
    -- TODO: Implement Expandable List Item
end

-- ============================================================
-- USECASE: Image Gallery Grid
-- ============================================================
local function ShowUsecase_ImageGalleryGrid()
    -- TODO: Implement Image Gallery Grid
end

-- ============================================================
-- USECASE: Stacked Cards
-- ============================================================
local function ShowUsecase_StackedCards()
    -- TODO: Implement Stacked Cards
end

-- ============================================================
-- USECASE: Notification Card
-- ============================================================
local function ShowUsecase_NotificationCard()
    -- TODO: Implement Notification Card
end

-- ============================================================
-- USECASE: Music Player
-- ============================================================
local function ShowUsecase_ProductCard()
    -- TODO: Implement Music Player
end

-- ============================================================
-- USECASE: Timeline Card
-- ============================================================
local function ShowUsecase_TimelineCard()
    -- TODO: Implement Timeline Card
end


local function RunCardsAndContentDemo()
    -- ========================================
    -- CARDS & CONTENT
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Cards & Content") then
        imgui.Indent()
        common.USECASE_ITEM('Card Hover Effects', ShowUsecase_CardHover)
        common.USECASE_ITEM('Flip Card', ShowUsecase_FlipCard)
        common.USECASE_ITEM('Swipe Cards', ShowUsecase_SwipeCards)
        common.USECASE_ITEM('Carousel / Image Slider', ShowUsecase_Carousel)
        common.USECASE_ITEM('Expandable List Item', ShowUsecase_ExpandableListItem)
        common.USECASE_ITEM('Image Gallery Grid', ShowUsecase_ImageGalleryGrid)
        common.USECASE_ITEM('Stacked Cards', ShowUsecase_StackedCards)
        common.USECASE_ITEM('Notification Card', ShowUsecase_NotificationCard)
        common.USECASE_ITEM('Music Player', ShowUsecase_ProductCard)
        common.USECASE_ITEM('Timeline Card', ShowUsecase_TimelineCard)
        imgui.Unindent()
    end
end

return RunCardsAndContentDemo
