--[[Quick starting UI interface programmed by Atomfusion
Target and group UI for pulling and healing 
Window fade 
Buttons with mq.cmd use
Text for target level, class, distance use
Color changing progress bar for health of target and group 
Icons linked to mq.TLO
USE Ctr`= to open macroquest console (Check this out and see everything it has to offer)
goto window and select dear imgui demo 
Also note Tools with Macro Expression Evaluator 
Test lua using /lua parse *expression*
Example: /lua parse mq.TLO.Me.Name
]]--

-- /lua run examples/GroupSample
local mq = require 'mq'

-- GUI Control variables
local openGUI = true
local shouldDrawGUI = true
local terminate = false
local AlphaBool = true

-- ImGui main function for rendering the UI window
local GroupSample = function()
    -- Window alpha settings on hover 
    if AlphaBool then
        ImGui.SetNextWindowBgAlpha(1) else ImGui.SetNextWindowBgAlpha(.1)
    end
    -- ImGui UI window startup must call ImGui.End()
    openGUI, shouldDrawGUI = ImGui.Begin('Target & Group', openGUI)
        -- Window alpha settings on hover 
        if ImGui.IsWindowHovered() then
            AlphaBool = true else AlphaBool = false
        end
    -- This is for refreshing client on EQ window crash when you are editing ImGui
    mq.cmd("/mqoverlay resume")
    if shouldDrawGUI then
        -- Setup button in a row
        if ImGui.Button("Stay", 42, 20) then mq.cmd('/g Stay') end
        ImGui.SameLine()
        ImGui.SetCursorPosX(57)
        if ImGui.Button("OTM", 42, 20) then mq.cmd('/g Follow Panther') end
        ImGui.SameLine()
        ImGui.SetCursorPosX(105)
        if ImGui.Button("Buff", 42, 20) then mq.cmd("/g Lets Buff") end
        ImGui.SameLine()
        ImGui.SetCursorPosX(175)
        if ImGui.Button("Button4", 60, 20) then mq.cmd("/g Button 4") end
        ImGui.SetCursorPosX(175)
        if ImGui.Button("Button5", 60, 20) then mq.cmd("/g Button 5") end
        ImGui.SetCursorPosX(175)
        if ImGui.Button("Button6", 60, 20) then print("Button 6") end
        ImGui.SetCursorPosX(175)
        if ImGui.Button("Button7", 60, 20) then print("Button 7") end

        -- Reset cursor pos to draw group health bars
        ImGui.SetCursorPos(5,60)
        -- Get HPs of target
        local pctHPs = mq.TLO.Target.PctHPs() or 0
        local ratioHPs = pctHPs / 100
        local targetName = mq.TLO.Target.DisplayName() or 'No Target'
        local targetLvl = mq.TLO.Target.Level() or '00'
        local targetDist = mq.TLO.Target.Distance3D.Int() or '00'
        local targetClass = mq.TLO.Target.Class.ShortName() or '     '
        -- Setup progress bar
        ImGui.PushStyleColor(ImGuiCol.PlotHistogram, 1 - ratioHPs, ratioHPs-.5, .5, 1)
        ImGui.PushStyleColor(ImGuiCol.Text, 0, 0, 0, 1)
        -- Create color changing bar for target health 
        ImGui.ProgressBar(ratioHPs, 150, 20, targetName..': '..pctHPs..'%')
        ImGui.PopStyleColor(2)
        ImGui.SetWindowFontScale(.9)
        ImGui.Text("LVL: "..targetLvl.." Class: "..targetClass.." Dist: "..targetDist)
        ImGui.SetWindowFontScale(1)
        -- For loop for displaying members health and Mana 
        local GroupNumber = mq.TLO.Group() or 0
        if GroupNumber == 0 then
            -- If you want to see your bar without grouppPut the code here 
        else
            for i=0,GroupNumber do
                -- Get pctHP and Mana
                local pctHPs = mq.TLO.Group.Member(i).PctHPs() or 0
                local pctMana = mq.TLO.Group.Member(i).PctMana()  or 0
                local ratioHPs = pctHPs / 100
                local ratioMana = pctMana / 100
                local targetName = mq.TLO.Group.Member(i).Name() or 'No Target'
                local StartOffset = 100
                -- Setup health bars and %
                ImGui.SetCursorPosY(i*30+StartOffset-i*5)
                ImGui.SetWindowFontScale(1)
                ImGui.PushStyleColor(ImGuiCol.PlotHistogram, 1 - ratioHPs, ratioHPs-.4, .2, 1)
                ImGui.PushStyleColor(ImGuiCol.Text, 0.8, 0.8, 0.8, 1)
                ImGui.ProgressBar(ratioHPs, 150, 15, targetName..': '..pctHPs..'%')
                -- Target player if clicked on 
                if ImGui.IsItemHovered() and ImGui.IsMouseReleased(0) then
                    mq.cmdf("/target %s",mq.TLO.Group.Member(i).Name())
                end
                ImGui.PopStyleColor(2)
                -- Setup mana bars and %
                ImGui.SetCursorPosY(i*30+StartOffset+15-i*5)
                ImGui.SetWindowFontScale(.4)
                ImGui.PushStyleColor(ImGuiCol.PlotHistogram, .2, .2 , ratioMana, 1)
                ImGui.PushStyleColor(ImGuiCol.Text, 1, 1, 1, .5)
                ImGui.ProgressBar(ratioMana, 150, 5)
                -- Target player if clicked on Health or Mana bar 
                if ImGui.IsItemHovered() and ImGui.IsMouseReleased(0) then
                    mq.cmdf("/target %s",mq.TLO.Group.Member(i).Name())
                end
                ImGui.PopStyleColor(2)
                -- Set window font to 1 so that the next window is normal Text
                ImGui.SetWindowFontScale(1)
            end
        end
            -- Icon Setup 
            ImGui.SetCursorPos(5,250)
            if mq.TLO.Me.Combat() then ImGui.TextColored(1, 0, 0, 1,'\xee\x9f\xbd') else
                ImGui.TextColored(0, 1, 1, 1,'\xee\x9f\xbd')
            end
            ImGui.SameLine()
            ImGui.SetCursorPosX(30)
            if false then ImGui.TextColored(1, 0, 0, 1,'\xef\x89\xa1') else
                ImGui.TextColored(0, 1, 1, 1,'\xef\x89\xa1')
            end
            ImGui.SameLine()
            ImGui.SetCursorPosX(60)
            if false then ImGui.TextColored(1, 0, 0, 1,'\xef\x8b\x9c') else
                ImGui.TextColored(0, 1, 1, 1,'\xef\x8b\x9c')
            end
            ImGui.SameLine()
            ImGui.SetCursorPosX(90)
            if mq.TLO.Me.Moving() then ImGui.TextColored(1, 0, 0, 1,'\xee\x95\xa6') else
                ImGui.TextColored(0, 1, 1, 1,'\xee\x95\xa6')
            end

            -- This stops screen flicker when pressing down the mouse or release of windows alpha fade 
            if ImGui.IsAnyItemHovered() and ImGui.IsMouseDown(0) or  ImGui.IsAnyItemHovered() and ImGui.IsMouseReleased(0)then
                AlphaBool = true
            end


        end
    ImGui.End()
    if not openGUI then
        terminate = true
    end
end

mq.imgui.init('GroupSample', GroupSample)

-- while loop waiting to close window 
while not terminate do
    mq.delay(100)
end

--[[
    SAMPLE ICONS NOT ALL 
    ["MD_3D_ROTATION"] = "\xee\xa1\x8d",
    ["MD_AC_UNIT"] = "\xee\xac\xbb",
    ["MD_ACCESS_ALARM"] = "\xee\x86\x90",
    ["MD_ACCESS_ALARMS"] = "\xee\x86\x91",
    ["MD_ACCESS_TIME"] = "\xee\x86\x92",
    ["MD_ACCESSIBILITY"] = "\xee\xa1\x8e",
    ["MD_ACCESSIBLE"] = "\xee\xa4\x94",
    ["MD_ACCOUNT_BALANCE"] = "\xee\xa1\x8f",
    ["MD_ACCOUNT_BALANCE_WALLET"] = "\xee\xa1\x90",
    ["MD_ACCOUNT_BOX"] = "\xee\xa1\x91",
    ["MD_ACCOUNT_CIRCLE"] = "\xee\xa1\x93",
    ["MD_ADB"] = "\xee\x98\x8e",
    ["MD_ADD"] = "\xee\x85\x85",
    ["MD_ADD_A_PHOTO"] = "\xee\x90\xb9",
    ["MD_ADD_ALARM"] = "\xee\x86\x93",

    ["MD_BUSINESS"] = "\xee\x82\xaf",
    ["MD_BUSINESS_CENTER"] = "\xee\xac\xbf",
    ["MD_CACHED"] = "\xee\xa1\xaa",
    ["MD_CAKE"] = "\xee\x9f\xa9",
    ["MD_CALL"] = "\xee\x82\xb0",
    ["MD_CALL_END"] = "\xee\x82\xb1",
    ["MD_CALL_MADE"] = "\xee\x82\xb2",
    ["MD_CALL_MERGE"] = "\xee\x82\xb3",
    ["MD_CALL_MISSED"] = "\xee\x82\xb4",
    ["MD_CALL_MISSED_OUTGOING"] = "\xee\x83\xa4",
    ["MD_CALL_RECEIVED"] = "\xee\x82\xb5",
    ["MD_CALL_SPLIT"] = "\xee\x82\xb6",
    ["MD_CALL_TO_ACTION"] = "\xee\x81\xac",
    ["MD_COLLECTIONS_BOOKMARK"] = "\xee\x90\xb1",
    ["MD_COLOR_LENS"] = "\xee\x8e\xb7",
    ["MD_COLORIZE"] = "\xee\x8e\xb8",
    ["MD_COMMENT"] = "\xee\x82\xb9",
    ["MD_COMPARE"] = "\xee\x8e\xb9",
    ["MD_COMPARE_ARROWS"] = "\xee\xa4\x95",
    ["MD_COMPUTER"] = "\xee\x8c\x8a",
    ["MD_CONFIRMATION_NUMBER"] = "\xee\x98\xb8",
    ["MD_CONTACT_MAIL"] = "\xee\x83\x90",
    ["MD_CONTACT_PHONE"] = "\xee\x83\x8f",
    ["MD_CONTACTS"] = "\xee\x82\xba",
    ["MD_CONTENT_COPY"] = "\xee\x85\x8d",
    ["MD_CONTENT_CUT"] = "\xee\x85\x8e",
    ["MD_CONTENT_PASTE"] = "\xee\x85\x8f",
    ["MD_CONTROL_POINT"] = "\xee\x8e\xba",
    ["MD_CONTROL_POINT_DUPLICATE"] = "\xee\x8e\xbb",
    ["MD_DEVICES_OTHER"] = "\xee\x8c\xb7",
    ["MD_DIALER_SIP"] = "\xee\x82\xbb",
    ["MD_DIALPAD"] = "\xee\x82\xbc",
    ["MD_DIRECTIONS"] = "\xee\x94\xae",
    ["MD_DIRECTIONS_BIKE"] = "\xee\x94\xaf",
    ["MD_DIRECTIONS_BOAT"] = "\xee\x94\xb2",
    ["MD_DIRECTIONS_BUS"] = "\xee\x94\xb0",
    ["MD_DIRECTIONS_CAR"] = "\xee\x94\xb1",
    ["MD_DIRECTIONS_RAILWAY"] = "\xee\x94\xb4",
    ["MD_DIRECTIONS_RUN"] = "\xee\x95\xa6",
    ["MD_DIRECTIONS_SUBWAY"] = "\xee\x94\xb3",
    ["MD_DIRECTIONS_TRANSIT"] = "\xee\x94\xb5",
    ["MD_DIRECTIONS_WALK"] = "\xee\x94\xb6",
    ["MD_DISC_FULL"] = "\xee\x98\x90",
    ["MD_DNS"] = "\xee\xa1\xb5",
    ["MD_DO_NOT_DISTURB"] = "\xee\x98\x92",
    ["MD_DO_NOT_DISTURB_ALT"] = "\xee\x98\x91",
    ["MD_PERM_IDENTITY"] = "\xee\xa2\xa6",
    ["MD_PERM_MEDIA"] = "\xee\xa2\xa7",
    ["MD_PERM_PHONE_MSG"] = "\xee\xa2\xa8",
    ["MD_PERM_SCAN_WIFI"] = "\xee\xa2\xa9",
    ["MD_PERSON"] = "\xee\x9f\xbd",
    ["MD_PERSON_ADD"] = "\xee\x9f\xbe",
    ["MD_PERSON_OUTLINE"] = "\xee\x9f\xbf",
    ["MD_PERSON_PIN"] = "\xee\x95\x9a",
    ["MD_PERSON_PIN_CIRCLE"] = "\xee\x95\xaa",
    ["MD_PERSONAL_VIDEO"] = "\xee\x98\xbb",
    ["MD_PETS"] = "\xee\xa4\x9d",
    ["FA_CIRCLE_O_NOTCH"] = "\xef\x87\x8e",
    ["FA_REBEL"] = "\xef\x87\x90",
    ["FA_EMPIRE"] = "\xef\x87\x91",
    ["FA_GIT_SQUARE"] = "\xef\x87\x92",
    ["FA_GIT"] = "\xef\x87\x93",
    ["FA_HACKER_NEWS"] = "\xef\x87\x94",
    ["FA_TENCENT_WEIBO"] = "\xef\x87\x95",
    ["FA_QQ"] = "\xef\x87\x96",
    ["FA_WEIXIN"] = "\xef\x87\x97",
    ["FA_PAPER_PLANE"] = "\xef\x87\x98",
    ["FA_PAPER_PLANE_O"] = "\xef\x87\x99",
    ["FA_HISTORY"] = "\xef\x87\x9a",
    ["FA_CIRCLE_THIN"] = "\xef\x87\x9b",
    ["FA_HEADER"] = "\xef\x87\x9c",
    ["FA_PARAGRAPH"] = "\xef\x87\x9d",
    ["FA_SLIDERS"] = "\xef\x87\x9e",
    ["FA_SHARE_ALT"] = "\xef\x87\xa0",
    ["FA_SHARE_ALT_SQUARE"] = "\xef\x87\xa1",
    ["FA_BOMB"] = "\xef\x87\xa2",
    ["FA_FUTBOL_O"] = "\xef\x87\xa3",
    ["FA_TTY"] = "\xef\x87\xa4",
    ["FA_BINOCULARS"] = "\xef\x87\xa5",
    ["FA_PLUG"] = "\xef\x87\xa6",
    ["FA_SLIDESHARE"] = "\xef\x87\xa7",
    ["FA_BUYSELLADS"] = "\xef\x88\x8d",
    ["FA_CONNECTDEVELOP"] = "\xef\x88\x8e",
    ["FA_DASHCUBE"] = "\xef\x88\x90",
    ["FA_FORUMBEE"] = "\xef\x88\x91",
    ["FA_LEANPUB"] = "\xef\x88\x92",
    ["FA_SELLSY"] = "\xef\x88\x93",
    ["FA_SHIRTSINBULK"] = "\xef\x88\x94",
    ["FA_SIMPLYBUILT"] = "\xef\x88\x95",
    ["FA_SKYATLAS"] = "\xef\x88\x96",
    ["FA_CART_PLUS"] = "\xef\x88\x97",
    ["FA_CART_ARROW_DOWN"] = "\xef\x88\x98",
    ["FA_DIAMOND"] = "\xef\x88\x99",
    ["FA_SHIP"] = "\xef\x88\x9a",
    ["FA_USER_SECRET"] = "\xef\x88\x9b",
    ["FA_MOTORCYCLE"] = "\xef\x88\x9c",
    ["FA_STREET_VIEW"] = "\xef\x88\x9d",
    ["FA_HEARTBEAT"] = "\xef\x88\x9e",
    ["FA_VENUS"] = "\xef\x88\xa1",
    ["FA_MARS"] = "\xef\x88\xa2",
    ["FA_MERCURY"] = "\xef\x88\xa3",
    ["FA_TRANSGENDER"] = "\xef\x88\xa4",
    ["FA_TRANSGENDER_ALT"] = "\xef\x88\xa5",
    ["FA_BATTERY_FULL"] = "\xef\x89\x80",
    ["FA_BATTERY_THREE_QUARTERS"] = "\xef\x89\x81",
    ["FA_BATTERY_HALF"] = "\xef\x89\x82",
    ["FA_BATTERY_QUARTER"] = "\xef\x89\x83",
    ["FA_BATTERY_EMPTY"] = "\xef\x89\x84",
    ["FA_MOUSE_POINTER"] = "\xef\x89\x85",
    ["FA_I_CURSOR"] = "\xef\x89\x86",
    ["FA_OBJECT_GROUP"] = "\xef\x89\x87",
    ["FA_OBJECT_UNGROUP"] = "\xef\x89\x88",
    ["FA_STICKY_NOTE"] = "\xef\x89\x89",
    ["FA_STICKY_NOTE_O"] = "\xef\x89\x8a",
    ["FA_CC_JCB"] = "\xef\x89\x8b",
    ["FA_CC_DINERS_CLUB"] = "\xef\x89\x8c",
    ["FA_CLONE"] = "\xef\x89\x8d",
    ["FA_BALANCE_SCALE"] = "\xef\x89\x8e",
    ["FA_HOURGLASS_O"] = "\xef\x89\x90",
    ["FA_HOURGLASS_START"] = "\xef\x89\x91",
    ["FA_HOURGLASS_HALF"] = "\xef\x89\x92",
    ["FA_HOURGLASS_END"] = "\xef\x89\x93",
    ["FA_HOURGLASS"] = "\xef\x89\x94",
    ["FA_TRIPADVISOR"] = "\xef\x89\xa2",
    ["FA_ODNOKLASSNIKI"] = "\xef\x89\xa3",
    ["FA_ODNOKLASSNIKI_SQUARE"] = "\xef\x89\xa4",
    ["FA_GET_POCKET"] = "\xef\x89\xa5",
    ["FA_WIKIPEDIA_W"] = "\xef\x89\xa6",
    ["FA_SAFARI"] = "\xef\x89\xa7",
    ["FA_CHROME"] = "\xef\x89\xa8",
    ["FA_FIREFOX"] = "\xef\x89\xa9",
    ["FA_OPERA"] = "\xef\x89\xaa",
    ["FA_INTERNET_EXPLORER"] = "\xef\x89\xab",
    ["FA_TELEVISION"] = "\xef\x89\xac",
    ["FA_CONTAO"] = "\xef\x89\xad",
    ["FA_500PX"] = "\xef\x89\xae",
    ["FA_AMAZON"] = "\xef\x89\xb0",
    ["FA_CALENDAR_PLUS_O"] = "\xef\x89\xb1",
    ["FA_CALENDAR_MINUS_O"] = "\xef\x89\xb2",
    ["FA_CALENDAR_TIMES_O"] = "\xef\x89\xb3",
    ["FA_CALENDAR_CHECK_O"] = "\xef\x89\xb4",
    ["FA_INDUSTRY"] = "\xef\x89\xb5",
    ["FA_MAP_PIN"] = "\xef\x89\xb6",
    ["FA_MAP_SIGNS"] = "\xef\x89\xb7",
    ["FA_MAP_O"] = "\xef\x89\xb8",
    ["FA_MAP"] = "\xef\x89\xb9",
    ["FA_COMMENTING"] = "\xef\x89\xba",
    ["FA_COMMENTING_O"] = "\xef\x89\xbb",
    ["FA_HOUZZ"] = "\xef\x89\xbc",
    ["FA_VIMEO"] = "\xef\x89\xbd",
    ["FA_BANDCAMP"] = "\xef\x8b\x95",
    ["FA_GRAV"] = "\xef\x8b\x96",
    ["FA_ETSY"] = "\xef\x8b\x97",
    ["FA_IMDB"] = "\xef\x8b\x98",
    ["FA_RAVELRY"] = "\xef\x8b\x99",
    ["FA_EERCAST"] = "\xef\x8b\x9a",
    ["FA_MICROCHIP"] = "\xef\x8b\x9b",
    ["FA_SNOWFLAKE_O"] = "\xef\x8b\x9c",
    ["FA_SUPERPOWERS"] = "\xef\x8b\x9d",
    ["FA_WPEXPLORER"] = "\xef\x8b\x9e",
    ["FA_MEETUP"] = "\xef\x8b\xa0",

]]