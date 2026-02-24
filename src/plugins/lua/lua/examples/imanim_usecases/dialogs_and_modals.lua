local imgui = require('ImGui')
local iam = require('ImAnim')

local common = require('common')

-- ============================================================
-- USECASE 2: Notification Toast System
-- ============================================================
local function ShowUsecase_ToastNotifications()
    -- TODO: Implement Notification Toast System
end

-- ============================================================
-- USECASE 8: Modal Dialog Animation
-- ============================================================
local function ShowUsecase_ModalDialog()
    -- TODO: Implement Modal Dialog Animation
end

-- ============================================================
-- USECASE 19: Tooltip Animation
-- ============================================================
local function ShowUsecase_TooltipAnimation()
    -- TODO: Implement Tooltip Animation
end

-- ============================================================
-- USECASE: Popover Menu
-- ============================================================
local function ShowUsecase_PopoverMenu()
    -- TODO: Implement Popover Menu
end

-- ============================================================
-- USECASE: Alert Banner
-- ============================================================
local function ShowUsecase_AlertBanner()
    -- TODO: Implement Alert Banner
end

-- ============================================================
-- USECASE: Bottom Sheet
-- ============================================================
local function ShowUsecase_BottomSheet()
    -- TODO: Implement Bottom Sheet
end

-- ============================================================
-- USECASE: Cookie Consent Banner
-- ============================================================
local function ShowUsecase_Snackbar()
    -- TODO: Implement Cookie Consent Banner
end

-- ============================================================
-- USECASE: Lightbox
-- ============================================================
local function ShowUsecase_Lightbox()
    -- TODO: Implement Lightbox
end

-- ============================================================
-- USECASE: Command Palette
-- ============================================================
local function ShowUsecase_CommandPalette()
    -- TODO: Implement Command Palette
end

-- ============================================================
-- USECASE: Inline Confirmation
-- ============================================================
local function ShowUsecase_InlineConfirmation()
    -- TODO: Implement Inline Confirmation
end

local function RunDialogsAndModalsDemo()
    -- ========================================
    -- DIALOGS & MODALS
    -- ========================================
    common.ApplyOpenAll()
    if imgui.CollapsingHeader("Dialogs & Modals") then
        imgui.Indent()
        common.USECASE_ITEM('Modal Dialog', ShowUsecase_ModalDialog)
        common.USECASE_ITEM('Toast Notifications', ShowUsecase_ToastNotifications)
        common.USECASE_ITEM('Tooltip Animation', ShowUsecase_TooltipAnimation)
        common.USECASE_ITEM('Popover Menu', ShowUsecase_PopoverMenu)
        common.USECASE_ITEM('Alert Banner', ShowUsecase_AlertBanner)
        common.USECASE_ITEM('Bottom Sheet', ShowUsecase_BottomSheet)
        common.USECASE_ITEM('Consent Banner', ShowUsecase_Snackbar)
        common.USECASE_ITEM('Lightbox', ShowUsecase_Lightbox)
        common.USECASE_ITEM('Command Palette', ShowUsecase_CommandPalette)
        common.USECASE_ITEM('Inline Confirmation', ShowUsecase_InlineConfirmation)
        imgui.Unindent()
    end
end

return RunDialogsAndModalsDemo
