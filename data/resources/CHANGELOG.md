September 17, 2025:
- live: Update for live patch

September 14, 2025:
- test: Update for test patch

September 7, 2025:
- live: Update for live patch

August 27, 2025:
- test: Update for test patch

August 26, 2025:
- live: Update for live patch

August 21, 2025:
- live: Update for live patch
- test: Sync changes from live branch

August 17, 2025:
- test: Update for the last 3 test patches

July 27, 2025:
- test: Update for test patch

July 20, 2025:
- live: Update for live patch

July 16, 2025:
- live: Update for live patch

July 14, 2025:
- test: Update for test patch

Jun 18, 2025:
- live: Update for live patch
- test: Fix Me.CombatState

June 13, 2025:
- test: Update for test patch

May 21, 2025:
- live: Update for live patch

May 16, 2025:
- test: Fix broken group members (#931)

May 15, 2025:
- test: update for test patch

April 23, 2025:
- test: update for test patch

April 17, 2025:
- live: Update for live hotfix patch

April 17, 2025:
- Fix broken AdvancedLootItem

April 16, 2025:
- live: Update for live patch

April 12, 2025:
- test: Update for test patch

March 26, 2025:
- test: Update for test patch

March 18, 2025:
- live: Update for live patch

March 12, 2025:
- test: Update for test patch
- live: Update for live patch
- Improve file permission checks to reduce the number of false positives

Feb 15, 2025:
- Fix EverQuest.WinTitle not returning the window title

Feb 12, 2025:
- live: Update for patch

Feb 10, 2025:
- test: Update for patch

Jan 29, 2025:
- test: Update for patch

Jan 15, 2025:
- live: Update for patch
- lua: Add error handling to mq.delay, failures inside the callback should now propagate to the caller properly

Jan 12, 2025:
- test: Update for patch
- Added ${Pet.ProcHold} and ${Pet.Resume}

Jan 11, 2025:
- ImGui has been updated to version 1.91.6
- Fix date format string of output from /mqlog

Dec 13, 2024:
- test: Update for test patch

Dec 5, 2024:
- live: Update for patch

Dec 3, 2024:
- live: Update for TOB expansion patch
- Fix /useitem not interacting with activated item keyring

Dec 1, 2024:
- test: Update for TOB expansion patch

Nov 21, 2024:
- Fix a couple crashes

Nov 20, 2024:
- live: Update for live patch
- test: Update for test patch

Note to plugin authors: the name labels of CGiveWnd and CTradeWnd changed from CLabel to CStmlWnd
For compatibility between versions of the client, a new GetText() method is added to both to get
the widget's text.

Nov 17, 2024:
- lua: Fix issues with mq.getFilteredSpawns returning nil or taking multiple frames.
  This reverts back to the previous behavior before optimizations were implemented, but retains some of those optimizations.

Nov 10, 2024:
- lua: New Zep text editor and console widgets are now integrated. (See the updated console and texteditor
  lua example in the lua/examples folder)

Nov 8, 2024:
- live: Update for live patch

Oct 30, 2024:
- test: Update for test patch

Oct 24, 2024:
- Fix new spawns getting mq captions applied when mqcaptions are disabled
- Fix crash that could occur when using /lua stop in some circumstances (#906)
- Fix crash when joining too many chat channels
- Add parameter to mq/eval script to pass an expression to evaluate

Oct 19, 2024:
- Fixed some missing console/editor keybinds. Some new functionality includes ctrl+[ +, -, 0 ] to zoom the font.
- lua: Starting a script will now also search require dirs if script is not found in main lua dir.

Oct 16, 2024:
- live: Update for live patch

Oct 15, 2024:
- test: Update for test patch

Sep 30, 2024:
- test: Update for test patch

Sep 18, 2024:
- live: Update for live patch

Sep 12, 2024:
- test: Update for test patch

Sep 7, 2024:
- emu: Fix bug that kept OnBeginZone events to fire. This fix will
  resolve severael bugs, including nav not stopping when zoning.
- emu: Added new Emu Extensions section in settings, with new option
  to automatically set cpu affinity. This is on by default.

Sep 5, 2024:
- lua: events can now preserve links:
    - mq.event('linkDetector', '#*#', linkDetector, { keepLinks = true })
- lua: New set of APIs for manipulating links.
    - See the [definitions](https://github.com/macroquest/mq-definitions/blob/master/mq/_itemlinks.lua) for a full listing.
    - lua: New examples/linkdetector.lua script in the lua folder provides some examples.
- lua: Add support for Macro token expansion in event patterns:
    - mq.event('meDetector', '#*#|${Me.Name}|#*#', meDetector)

Aug 21, 2024:
- Update for live patch
- Add SpellHold to Pet TLO (#893)

Aug 19, 20924:
- Update for test patch

July 28, 2024:
- Update for test patch

July 22, 2024:
- Update for live hotfix patch

July 18, 2024:
- Update for live hotfix patch

July 17, 2024:
- Update for live patch

July 14, 2024:
- test: Update for test patch

July 7, 2024:
- Add new HotButton window type: ${Window[HotButtonWnd2/HB_Button6].HotButton}
- See docs at: https://docs.macroquest.org/reference/data-types/datatype-hotbuttonwindow/
- Me.CombatState no longer depends on the player window being visible (#123).

July 5, 2024:
- emu: Fix RaidMember accessors (#685), (#861)

July 4, 2024:
- emu: Fix Spell.Inspect (#831).

July 3, 2024:
- Fix EverQuest.Ping, add EverQuest.ConnectionStrength - these are the value from the net meter.
- Fix UI not working after persona swap (#797).

July 1, 2024:
- emu: Fix CTAFrameDraw, fixes several issues with window inspector (#871)
- emu: Fix CBazaarSearchWnd, fixes several issues with /bzsrch (#872)

June 24, 2024:
- Update for live hotfix patch

June 20, 2024:
- Fix a bug in EverQuest so the window doesn't constantly resize/restore
  itself whenever common system events happen.

June 19, 2024:
- Update for live patch

June 16, 2024:
- Update for test patch
- Fix MacroQuest.exe now shutting down properly
- FIx /removeaura not parsing macro arguments (#869).

May 26, 2024:
- Update for test patch

May 23, 2024:
- Update for live hotfix patch
- Please refrain from using MQ on truebox servers.

May 15, 2024:
- Update for live patch

May 10, 2024:
- Update for test patch

April 25, 2024:
- Adjust timestamps in chat and logging to be in local time (#853, #852).
- Add logging auto cleanup feature to launcher (#419).

March 27, 2024:
- Updated emu client to catch it up with the latest features

March 13, 2024:
- Update for live patch

March 7, 2024:
- Update for test patch

Feb 29, 2024:
- autologin: Fix bug causing the wrong account to be assigned to characters at character select.
- autologin: Fix bug causing blank password to be assigned to accounts at character select.
- autologin: Add error message when launching game if everquest path is invalid.

Feb 28, 2024:
- test: Updated for latest patch

Feb 26, 2024:
- autologin: Fix loader losing track of logged in sessions when it is restarted
- autologin: Fix several issues related to tracking the logged in state of characters
- autologin: Fix in-game commands to now use state machine to properly handle character changes.
- autologin: Menus will now indicate when a character is logged in, but on a different profile.
  Selecting that profile will apply the profile to the currently logged in character.
- autologin: Menus will now indicate when an account is already logged in, but on a different
  character.
- autologin: The "Show hidden characters" option is now persisted
- autologin: Profile groups panel is now a resizable side bar instead of a drop down menu
- autologin: Added ability to double click to expand in tree view panel
- autologin: It is now possible to switch to any character on any account on any server, from anywhere.
- autologin: Fix infinite loop that could occur during login.

Feb 23, 2024:
- autologin: Fix ini import creating blank passwords when stationnames entries exist.
- autologin: Add right click option to Characters UI to add a character to a profile group.
- autologin: Fix process tracking for loaded profiles.
- loader: Add process list to show processes currently being tracked.

Feb 22, 2024:
- live: updated for live patch
- autologin: Profile context menus can now toggle their state with ctrl+click
- autologin: Profile context menus now use a star instead of check mark. Functionality is the same.
- autologin: Profiles can now be freely re-ordered independent of star state.
- autologin: Increase default delay when launching multiple instances.
- autologin: Various improvements to context menus (still have issues with loaded state...)
- autologin: Add logged in indicators to UI

- autologin: Fix crash that could occur when the MQ launcher starts up
- autologin: Fix remove profile showing group
- autologin: Fix tray icon disappearing if explorer crashes or restarts
- autologin: Fix an issue that might cause an extra instance of EQ to start unintentionally.
- autologin: Add "Launch All" item to profile menu
- autologin: Add first pass at online indicator to context menus. More to come in the future.
- autologin: Changed check marks in autologin ui to check boxes. Single click on the check box will toggle, and tooltip will describe its behavior.
- autologin: Add text to indicate that profile rows can be reordered via drag & drop.

Feb 21, 2024:
- live: Updated for latest patch
- Add EQ cursor emulation for ImGui windows. This can be toggled in overlay settings (on by default).
  When this feature is enabled, the EQ cursor and its attachments will appear over imgui windows.

Feb 18, 2024:
- test: Updated for latest patch

Feb 16, 2024:
- Changes to AutoLogin:
- added sorting for characters that persists to context menu
- added filter to hide characters from context menu
- added ordering to profiles for login order and display
- added sorting and searching to accounts
- added some tooltips 

Feb 14, 2024:
- test: Fix Me.Platinum etc always returning 0.

Feb 13, 2024:
- test: Updated for latest patch
- Completely revamped the autologin interface and storage
- MQ's context menu is now driven by imgui
- Added an extendable window gui to MQ
- login profiles and character management is now driven through the main gui
- removed sessions and replaced station names with single-entry profiles
- passing the profile name to /login will load the first character in the profile
- removed the autologin ini, replaced with sqlite db that can be copied across computers
- a master pass has been added to provide encryption for account passwords _only_
- the user will be prompted for a master password at first startup on a computer
- the master password will be stored locally outside of the db (in the registry)
- if the autologin plugin is running, logging in a new account will store the account name and associated characters in the database
- manually editing the server list mapping is no longer needed (it is auto detected the first time you see that server in your list)

Feb 3, 2024:
- emu: Fix /timestamp showing seconds to the decimal

Feb 2, 2024:
- Add Social TLO (#825)

Feb 1, 2024
- live: Updated for latest patch

Jan 30, 2024:
- Disable jit when delaying so that delays are not optimized away (#822)
- /doability will now accept quoted or unquoted ability names
- /doability will now work for innate skills like slam (#371)
- mq.TLO.Me.Ability is now a boolean. It returns true or false based on whether you have the ability.
- mq.TLO.Me.AbilityReady will no longer say an ability is ready if you don't have that ability.
- Added mq.TLO.Me.AbilityTimerTotal which will return the total amount of time an ability takes to refresh. This is only available while the ability is in cooldown, otherwise it returns 0. Useful for converting mq.TLO.Me.AbilityTimer into a percentage. (#823)
- mq.TLO.Me.AltCurrency now works with the singular or plural name of the currency
- plugins: GetZoneExpansionName(0) would previously return "Original EQ" but now returns "EverQuest"

Jan 27, 2024:
- test: Updated for latest patch

Jan 20, 2024:
- Fix Mercenary.State reporting unknown when mercenary is active (#811)
- Fix Heading.Name/Heading.ShortName potentially going out of bounds (#813)
- Change Me.BoundLocation.Heading to return heading type instead of a 512 unit float

Jan 19, 2024:
- Fix mq.pickle not properly escaping backslashes and not properly serializing numbers. (#815, #771).

Jan 18, 2024:
- Fix issue where textures would not draw if they had not already been preloaded.
- Fix FPS plot in benchmark window to use its own axis.

Jan 17, 2024:
- live: Updated for latest patch
- live: DirectX 11 is now on the live client, some visual features may be
  missing or not working correctly.

Jan 15, 2024:
- Update CrashDetected popup with reminder that text can be copied and also add PID (#765).
- Update faction names by using dbstr_us.txt (#806)
- Fix Me.Origin (#807)
- Fix several window properties that had been swapped (Click Through, Show Border, Escapable)

Jan 14, 2024:
- test: Updated for latest patch

Jan 11, 2024:
- Prospective fix for map crash (#798)
- PackageMan now accepts the debug parameter (see docs)
- luarocks cache has been moved to the modules folder

Jan 8, 2024:
- Fix clipping of ImGuiConsole, add opacity. (#805)
- Fix Window.SetText correctly sending change event.

Dec 18, 2023:
- Update ImGui to 1.90
- Update ImPlot to 0.17
- lua: ImGui and ImPlot lua bindings fully refreshed with 100% coverage of definitions.
- lua: mq-definitions VSCode extension available at https://marketplace.visualstudio.com/items?itemName=ZenithCodeForge.mq-defs
- datatypes: add TradeskillDepot.DepositItem
- datatypes: add Type.InheritedType
- datatypes: add Me.LaurionInnVoucher, Me.ShalowainsPrivateReserve

Dec 13, 2023:
- test: Updated for latest patch

Dec 12, 2023:
- live: Updated for latest patch
- live: Updated for latest patch (again)

Dec 9, 2023:
- Fix formatting of links in console when line contains multiple links

Dec 8, 2023:
- live: Fix spawn manager crash
- test: Fix spawn manager crash

Dec 5, 2023:
- live: Updated for latest expansion

Dec 4, 2023:
- test: Fix ZoneGuide
- Add Me.PersonaLevel - takes class shortname as param, returns level of that class persona.
  e.g. ${Me.PersonaLevel[DRU]} returns level of druid class persona.

Dec 2, 2023:
- test: Updated for latest patch

Nov 28, 2023:
- Actors are now live for use in plugins, see https://docs.macroquest.org/plugins/developing/actors/
- Actors are also now live for use in lua scripts, see examples/buffbeg.lua for example usage.

Nov 22, 2023:
- Update vcpkg dependencies

Nov 19, 2023:
- Add ability to create textures from image files. See examples/texture.lua for example usage.

Nov 15, 2023:
- live: Fix spell display window (#782).
- autologin: Enable /camp fast when switching characters
- live: Updated for latest patch

Nov 11, 2023:
- test: Fixed some crashes involving the buff window

Nov 9, 2023:
- Lua modules will no longer be loaded relative to the lua folder.
- Developers should use PackageMan or (for their own internal use) the modules folder.

Nov 8, 2023:
- Fixed some issues with autologin
- Fixed some crashes related to target window
- test: Updated for latest patch

Nov 7, 2023:
- Added support for datatypes implemented in lua scripts. This includes support
  for lua tables in lua datatypes. See examples and definitions for details.
  Detailed documentation coming soon. (#716)
- Added preliminary support for actors in c++ plugins. (#674)
- Exposed ConsoleWidget to c++ and lua (see definitions for details)
- lua: Added Set helper class (#770)

Oct 21, 2023:
- tlo: Add Inventory TLO (currently only has the Bank datatype)
- Inventory.Bank has members: BagSlots, FreeSlots, TotalSlots, and each currency
- See https://docs.macroquest.org/reference/top-level-objects/tlo-inventory/

Oct 18, 2023:
- live: Updated for latest patch
- live: Additional servers that are no longer flagged as truebox are now supported

Oct 15, 2023:
- Fix double input on imgui windows

Oct 14, 2023:
- test: updated for latest patch
- Added DX11 support and re-enabled the ImGui overlay. Nav rendering is still disabled.

Sep 25, 2023:
- live: Update eqlib, should fix reading some game options. (#755, #756)

Sep 21, 2023:
- Fix crash in CDragonHoardWnd and CBarterSearchWnd.
- test: Fix crash in GetMembershipLevel

Sep 20, 2023:
- live: updated for latest patch
- Fixed calculation of HasSPA, which should fix some properties such as Me.Silenced (#739)
- Expand the coverage of game feature and claim data (developer tools)
- Lifetime All-access should now appear as GOLD in ${Me.Subscription} instead of UNKNOWN

Aug 26, 2023:
- test: updated for latest patch

Aug 24, 2023:
- live: updated for latest patch

Aug 16, 2023:
- live: updated for latest patch

Aug 12, 2023:
- test: updated for latest patch

Aug 10, 2023:
- autologin: Add AutoLogin TLO to provide access to profile data (#737)
- lua: add mq.getAllGroundItems (#740)
- lua: Fix some issues caused by errors while requiring a file
- window datatype: Add Window.SetText, which can be used to change the
  contents of edit controls

Jul 19, 2023:
- live: Updated for patch
- Add FreeGrab to AdvLootType (#733)
- Hotkey will now restore minimized window (#735)

Jul 10, 2023:
- test: updated for test patch

Jul 8, 2023:
- Fix PackageMan issue with loading submodules in a single line

Jul 6, 2023:
- Fix scoping issues in PackageMan causing lua errors (#731)

Jun 29, 2023:
- test: updated for test patch

Jun 26, 2023:
- Fix CTextureAnimation (#729). This should fix ImGui drawing of game icons
- Fix MQMouseInfo, should fix crashes with /mouseto (#698).
- Fix overlay blocking input while it is hidden (#699).
- lua: Disallow the use of mq.delay while a module is being imported (#730)
- Add spell.MinCasterLevel to report the minimum class level of a spell (#722).

June 21, 2023:
- live: Updated for live patch

June 19, 2023:
- test: Updated for test patch

May 24, 2023:
- live: Updated for live patch

May 19, 2023:
- live: Updated for live patch

May 17, 2023:
- test: Updated for test patch
- live: Updated for live patch. This patch introduces the new UI system,
  there may be issues involving UI components.

May 14, 2023:
- test: Updated for test patch
- test: Fixed Me.Combat again

May 13, 2023:
- Fix issue where OnRemoveSpawn would be called twice in some instances

May 4, 2023:
- Disable previous launcher change pending further refinement. For now, the log
  spam should be disabled. (#717)

April 26, 2023:
- test: Updated for patch

April 24, 2023:
- Fix an issue where the loader would spam the log file with an error if more than
  64 eqgame.exe processes were running. Instead, it will swap to the WMI process
  monitor to retain functionality.
- Add experimental feature that resizes the game's render viewport to fit the central
  docking area when imgui windows are docked to edges of the screen. This can be enabled
  in Settings under Overlay (/mqsettings overlay).

April 19, 2023:
- live: Updated for patch

April 12, 2023:
- test: Updated for patch
- test: Fixes for autologin
- test: Fix Me.Combat, add EverQuest.UiScale

April 2, 2023:
- test: Fix WindowOverride implementation. Fixes crashes in MQ2Map, MQ2ItemDisplay, etc.

April 1, 2023:
- Happy april fools
- test: Updated for patch

March 15, 2023:
- live: Updated for patch
- live: fixed zone guide structure

March 8, 2023:
- test: Updated for patch

February 24, 2023:
- Fix CryptAcquireContext error when importing Autologin profiles

February 23, 2023:
- test: Updated for patch

February 21, 2023:
- GetSpellDuration now returns correct duration. Deprecated EQGetSpellDuration.

February 20, 2023:
- emu: MQ Console will now allow GM commands (#zone)

February 15, 2023:
- live: Update for patch

February 10, 2023:
- Made some improvements to the performance of the mq console window.
- Added an option to the mq console window to adjust the number of lines
  of history that are stored.
- Fix bug where a file dialog could be docked in another window, resulting in
  the window flickering and becoming unusable.
- lua: Calling mq.delay in an ImGui callback will now trigger an error instead
  of silently failing.

January 30, 2023:
- lua: calling mq.delay from an imgui thread will now throw an error (#692).
- added missing RecommendedLevel to item (#691).

January 28, 2023:
- Frame limiter is now called Frame Limiter in the settings panel (previously FPS Limiter)
- MQ Console: Fixed last \ax so that it uses the previous default color instead of white
- Missing plugins will now report when the file is not found rather than the LoadLibrary error

January 23, 2023:
- Add /executelink command that will simulate a click from raw link text.
- spell datatype: Add Link member to generate clickable link text.
- spell datatype: Add Inspect method to open the spell display window.
- spell datatype: Added /vardata and /varset support for spell variables. Assigning
  a string or number will reassign the spell variable by spell name or id.
- achievement datatype: Add Inspect method to open achievement display window.
- emu: Fix crash when declaring a spell var (#688).

January 19, 2023:
- live: Fix for broken world container

January 18, 2023:
- live: Updated for live patch

January 17, 2023:
- item datatype: Add Item.Inspect method to open item display window on a particular item.

January 10, 2023:
- test: updated for patch

January 8, 2023:
- fix /removeaug (#669).
- imgui: Fix nested BeginDisabled calls (#672).
- emu: Fix TradeReady flags (#666).
- emu: Fix /itemnotify when matching invslot is also in a hotbutton.

January 6, 2023:
- lua: Added mq/Icons.lua for Icon usage in imgui
- tlo: Added Spell.Dispellable which returns true if a spell can be dispelled (#655)

December 14, 2022:
- test: updated for patch

December 8, 2022:
- live: updated for patch

December 6, 2022:
- live: Update for expansion patch
- live: Fixed Switch ids and names
- Added currency for NoS
- Added ${TradeskillDepot}, see the docs for full description of the members:
  https://docs.macroquest.org/reference/top-level-objects/tlo-tradeskilldepot/
- lua: Running "/lua run scriptname" will now prefer lua/scriptname/init.lua over
  lua/scriptname.lua. this is to make it easier to transition to the new directory layout.

November 29, 2022:
- emu: Fix PctExp and PctAAExp calculations
- tlo: Added BazaarItem.FullName
- lua: Fixed bug where /lua pause would not pause imgui thread
- lua: added -on and -off arguments to /lua pause

November 28, 2022:
- Huge update to settings window for MQ2Map plugin settings - /mqsettings plugin/map (#657)
- lua: Many more improvements to imgui bindings for lua.
- lua: Consolidated imgui demo scripts into examples/imgui_demo
- lua: Scripts can now be started by specifying a folder name if the folder contains init.lua.
- lua: Scripts can now require files relative to the directory that the script runs in.

November 24, 2022:
- test: fix zone count
- test: fix keybinds

November 23, 2022:
- test: updated for test patch
- Message box will now appear when overlay is stopped due to an error.
- lua: Many improvements to imgui bindings for lua. Notably, ImDrawList support has been
  added. Some of these features are evolving, check out examples/imgui_demo.lua for example lua code.
- lua: Added support for converting macro array types to lua tables (#641).
- lua: event and bind add/remove will now return true/false based on if the action was successful.
  These actions may fail if the event already exists with the specified name, for example.

November 16, 2022:
- live: Updated for latest patch
- Updated MQ2TargetInfoPHs.txt (#661)
- Updated Fish.mac (#605)
- Added refcounting to item and itemspell datatypes. This should fix a crash where a lua script
  consumes the last charge of an item causing it to disappear.
- plugins: Deprecated old item spell enum values. See deprecation warnings for replacements.
- lua: Added imgui bindings for TableGetColumnFlags (#658)

November 9, 2022:
- test: Updated for patch

November 3, 2022:
- test: Updated for patch

October 31, 2022:
- Added upper bounds check on ReagentID, NoExpendReagentID, and ReagentCount. The max number 
  of reagents for a spell is 4. ReagentCount[n] explains how many ReagentID[n] you need.
  For NoExpendReagentID is always just need 1 of the item.

October 26, 2022:
- live: Updated for live patch

October 16, 2022:
- test: Updated for patch

October 15, 2022:
- emu: Fix max pet buff count being incorrect

October 14, 2022:
- Add MaxFPS and MaxBGFPS to EverQuest TLO. Reports the settings found on the options window.
- Improved Macro TLO functionality to be able to retrieve some values while a macro isn't running.
- Fixed achievement categories not being found properly.

October 10, 2022:
- emu: Improved ability to capture crash reports.
- emu: Fixed CharSelect data (#627).

October 9, 2022:
- emu: Fixed issue causing custom UIs to create instability and other problems (#639).

October 6, 2022:
- Remove Spell.SPA - this wasn't actually a SPA and was some other meaningless value.
- Add Spell.CategoryID and Spell.SubcategoryID - the integer values of Category and Subcategory

October 2, 2022 (test):
- Updated for test patch

October 2, 2022:
- Autobank and related functionality has been moved from mq2main into its own autobank plugin. (#580)
- autobank: Added tradeskill item filter
- framelimiter: Fix framelimiter not bypassing built-in limiter when it is enabled.

September 26, 2022:
- Fix Me.Levitating (#632)
- Add more robust ini handling options - see http://docs.macroquest.org/reference/data-types/datatype-inifilesectionkey
- Add .StripLinks memember to string types which will return the plain text version of a string containing links

September 21, 2022 (live):
- Fix achievement crash (#629).
- Updated for live patch

September 18, 2022:
- emu: Added back /timestamp for emulator builds to add timestamps to chat. Added checkbox
  to the mq settings window under a new "Chat" section. (#618)
- emu: Fix title bar click events on MQ2ChatWnd. (#616)
- emu: Fix tabselect crash. (#622)
- emu: Fix crash when checking spell stacking. (#624)
- emu: Fix crash when interacting with merchants. (#626)
- emu: Re-introduce GroupLeaderExp, GroupLeaderPoints, PctGroupLeaderExp, RaidLeaderExp,
  RaidLeaderPoints, PctRaidLeaderExp. (#625)
- emu: Re-introduce support for LAMarkNPC, LANPCHealth, LADelegateMA, LADelegateMarkNPC,
  LAInspectBuffs, LASpellAwareness, LAOffenseEnhancement, LAManaEnhancement, LAHealthEnhancement,
  LAHealthRegen, LAFindPathPC, LAHoTT (#625)

September 16, 2022 (test):
- Updated for latest test patch

September 7, 2022:
- /captioncolor will work when typed in EQ chat windows again (#619)
- Autologin profiles launched from MQ will now work properly for servers with spaces in
  their shortname
- Fixed a crash that would occur in macros when declaring an array of invalid size
- The "noparse" parameter in the Ini TLO is no longer case sensitive

Aug 19, 2022:
- Add ${MacroQuest.BuildName} to get the name of the build target (Live/Test/Emu)

Aug 17, 2022:
- Fix autoskills not returning proper values

Aug 17, 2022 (live):
- Updated for patch

Aug 12, 2022:
- /mapfilter will now store Radius values instead of toggle information (Fixes #600)
- Lua: Added mq.getAllSpawns and mq.getFilteredSpawns to return tables of spawns.
- LuaRocks is now distributed with MQ for using prebuilt Lua Modules from the MQ repo
- PackageMan is now distributed with MQ for a method of using LuaRocks in lua scripts
- Plugins that fail to unload will now be flagged as having failed and will not allow reload
  of the plugin or unload of MQ.  With this change, /unload now has the parameter "force"
  which will try to force unload stuck plugins and prompt for action if that cannot be
  accomplished.
- The tray util has a new option to "Unload All Instances (Forced)" which will send the
  "/unload force" command to all registered MQ instances.
- More info can be found at docs.macroquest.org

Jul 29, 2022:
- Added a modules folder primarily for storing architecture dependent lua modules
- mq.TLO.Lua.Dir now supports arguments (lua, and modules) to return the corresponding folder

Jul 27, 2022:
- Fix item statistics not matching item

Jul 22, 2022:
- Fix Corpse type to properly inherit from Spawn. Support checking for .ID and .Open when no
  corpse is currently active.

Jul 21, 2022:
- Fix achievements

Jul 20, 2022:
- Updated for patch

Jul 12, 2022:
- Fix MyRange Spell member (#563)

Jun 29, 2022:
- Fix EQ Exiting when MQ is loaded and an invalid UI is loaded (#572)
- Add parse function for lua scripts.  You can now parse any arbitrary macro data.
  - Usage Example:  mq.parse("${Me.Name}")
  - The return will always be a string and you will always be using the version 2 parser
  - It is still preferable to use the mq.TLO syntax when retrieving data from an existing TLO
  - The purpose of this function is to allow you to perform more complex operations when doing
    macro/ini conversions.

Jun 15, 2022:
- Updated for live patch.
- Potential fix for WinEQ2022 interoperability

Jun 9, 2022:
- ${Int[x]} is now capable of parsing numbers up to 64-bits, and will truncate the result.
- Fix reporting of spell buff counters.

Jun 8, 2022:
- Fix detection of aura and campfire spawns (#561)
- Fix ${Target.ID} now returns 0 instead of NULL to be consistent with
  other spawn type objects.

Jun 1, 2022:
- Fix ${Me.SkillCap} (#568)

May 27, 2022:
- datatype: ItemSpell: add members OverrideName, OverrideDescription.
  - OverrideName replaces the OtherName member. This is a name that overrides the spell name
    when the spell is on an item.
  - OverrideDescription overrides the description string from the spell, similar to OverrideName.
- datatype: Item: fixed off-by-one error with AugSlot. The Correct range is now 1-6 and now
  matches the Slot value as expected.

May 26, 2022:
- lua: Throw error if string argument to mq.delay contains no time unit.

May 20, 2022:
- Fix /drop (#564)

May 18, 2022:
- Updated for patch
- Number of buffs has changed for player and target. Buff arrays are now dynamically sized,
  and require some attention when using them in plugins:
  - Use GetPcProfile()->GetMaxEffects() to get the total number of effects (short and
    long buffs) for player
  - Use pPetInfoWnd->GetMaxBuffs() for the max number of buffs on the pet window.
  - Use pTargetWnd->GetMaxBuffs() for the max number of buffs on the target window.

May 13, 2022:
- Add Fellowship.Exists
- Move Inviter, Invited and IsBerserk from Spawn to Character (Me).
- Removed a bunch of unused members from Spawn
- plugins: Converted a bunch of globals into members of the pEverQuestInfo class. This
  includes a lot of globals that start with EQADDR_ and a few that don't. See the commit
  log for the full list.
- plugins: the keyboard movement defines __pulForward, __pulBackward etc have been removed.
  these are primarily used for movement. They are replaced with pEverQuestInfo->keyDown[cmd].
  cmd is a member of the KeybindCommand enumeration. For example: __pulForward can be replaced
  with pEverquestInfo->keyDown[CMD_FORWARD]

May 5, 2022:
- /exec no longer requires the fg or bg parameter.  The syntax has been updated and
  the functionality corrected to match what the previous syntax showed.

April 25, 2022:
- Updated for live hotfix patch.
- Fix potential issue with pcnames.

April 20, 2022:
- Updated for live patch.
- Fix netstat/hud display
- Fix /makemevisible
- Fix issue with Me.CombatAbility (and maybe others) not returning the correct values.
- plugins: PcProfile.Buff and PcProfile.ShortBuff have been deprecated and replaced with
  accessor functions GetEffect and GetTempEffect, respectively. Deprecation warnings have
  been added for this change. For accessing all buffs, both short and long, GetEffect can
  be used with MAX_TOTAL_BUFFS as the upper bound.

April 13, 2022:
- Fix Group.Members: Empty group will now report 0 instead of nil/NULL (#481).
- Fix Math.Rand: Replace with new number generator. There are no longer any limits on the
  upper or lower bounds of the random number range. The only requirement is that the
  minimum value must not be greater than the maximum.
- Fix Spell.Stacks to now only consider a duration if a nonzero value is provdied,
  otherwise the stacks check will ignore duration. Also applies to StacksPet.
- Fix crash in MapObject.cpp (#455).
- Fix Macro TLO to allow IsTLO and IsVariable while a macro is not running (#452).
- Fix non-functional /removeaug, and cleaned up the usage message (#485).
- Fix /mqanon cause hp bars to be empty (#483).
- Fix errant deprecation message when using ${Ground} (#445).
- Fix MacroQuest.LastTell (#463).
- Fix passing nil to mq.event or mq.bind causing crash. A lua error will be generated instead (#451).
- Add double click to select file in imgui file dialog (#453).
- Add Group.LowMana to report group member with lowest mana below threshold. Works like
  Group.Injured (#477).
- Add /alias reload (#478).
- lua: event text will now have mq color codes stripped (#486).

March 9, 2022:
- Updated for patch.
- Me.AssistComplete is temporarily disabled. Its been broken since x64 but
  the disabling is purposeful now to avoid crashing.

March 8, 2022:
- Spell SPA data for base, base2, and max are now 64 bit values.
- Spell Buff counters are now 64 bit values.
- GetSpellBase, GetSpellBase2, GetSpellMax, CalcValue all return int64_t now.
- GetSpellCounters, GetMySpellCounters, GetTotalSpellCounters, GetMyTotalSpellCounters all return int64_t now
- The associated macro data members for these return Int64 instead of Int datatypes.
- Plugins may exhibit warnings due to int64_t -> int conversions. These warnings ought to be addressed
  as appropriate by utilizing int64_t where arbitrary values may occur (like damage or healing values)
  and cast to int where they do not (like SPA or spell id values).

March 2, 2022:
- Fixed an issue with chat events cutting off chat
- Added Spawn types for BodyWet and HeadWet to complimenet FeetWet
- Updated FeetWet to include when standing in other liquids like lava or slime.  Underwater is still just water.
- Added WritePrivateProfileValue for plugin authors

February 25, 2022:
- Fixed some potential issues with detours. Possibly fixes issue with unloading/reloading
  causing problems with commands
- Moved GetSubscriptionLevel to core. If you have a copy of this function in your plugin,
  you can remove it now.
- Added GetClass(), GetClassString(), GetRace(), GetRaceString(), GetClassThreeLetterCode()
  to PlayerClient (SPAWNINFO) as convenience helpers for plugin code.
- Reverted an earlier change to MQ2Map during 64-bit conversion to potentially address an
  issue with the map.
- Fixed an event crash when text is marked as Spam

February 15, 2022:
- Updated for patch. Welcome to 64-bit MacroQuest.

January 25, 2022:
- Fix crash in ItemDisplay when viewing new merchant perk bag.

January 19, 2022:
- Updated for patch.
- Add missing ToL entry to GetZoneExpansionName() (#444)
- Fix Me.AmIGroupLeader not returning a proper bool.
- Fix a bug with /itemnotify and rightmouseup
- Fix /plugin command so that it parses the command line
- Add settings panel for ChatWnd
- lua: Added mq.gettime() which returns current time in microseconds

- Add DynamicZone.MinMembers
- Fix crash when reading DynamicZone.Leader and maybe others
- Fix crash casued be Me.Aura[0] (#449)

December 31, 2021:
- lua: Fix crash when using format string with ImGui.Text (hint: Format your string in lua instead)
- lua: Update table flags from latest integration of imgui
- lua: Fix ImGui.GetClipboardText bug
- main: /mqsettings now takes an optional parameter, the name of a section to focus.
    example: /mqsettings plugins/lua
- devtools: implement new switch inspector. This is a work in progress but is fully functional. Working on
    bringing over functionality that was originally implemented in Nav

December 27, 2021:
- Added IsSpellTooPowerful utility function that mimics client logic and incorporated it into StacksTarget and StacksSpawn

December 25, 2021:
- Added "clear" to /itemtarget and /doortarget to individually remove those targets

December 16, 2021:
- Fixed ${Me.SpellRankCap} (#430)
- Added Option to toggle Local Echo to the MacroQuest Console (#117)
- Toggling AutoScroll in the MacroQuest Console will now persist through subsequent loads

December 15, 2021:
- Fix ${Me.Invis[SOS]} showing true for rogues who have Rk 2 of SoS (#416)
- Fix an issue where ${Me.Moving} reported false when moving backwards
- Added ${Me.VitalityCap} and ${Me.AAVitalityCap} for parity of numerical output

December 9, 2021:
- Updated for patch

December 7, 2021:
- Happy Terror of Luclin Day!
- Added full support for the merchant perk and bag slot 11 and 12.
- Added ${Me.NumBagSlots} which returns the number of bag slots enabled in main inventory.
- Added ${TeleportationItem} TLO to access the teleportation item keyring.
- Fix crash when selling items using button from find item window (#426).
- Fix spell display for SPA_TRIGGER_SPELL_NON_ITEM
- Fix ${DisplayItem.Collected} (#420).

November 30, 2021:
- MacroQuest tray utility will now check Application Compatibility layers on startup.  To disable this check set
  DisableAppCompatCheck=true in the MacroQuest section of your MacroQuest.ini
- Added ShowAnon setting to TargetInfo - this will allow toggling displaying "ANON" or "ROLEPLAYING" in the window

November 17, 2021:
- Updated for latest patch
- Fixed crash where the running vector is modified during execution and invalidated the iterator

November 16, 2021:
- Add a potential workaround for a graphics engine crash
- Fix typo in XTARGET_MY_MERCENTARY_TARGET. Use XTARGET_MY_MERCENARY_TARGET instead (#409)
- Fix Me.Song not returning proper value when Me.Buff also has a match (#411).
- Add BaseEffectsFocusCap (SongCap) as a member of the Spells TLO

November 10, 2021:
- Changed the operation of delays in lua so that a delay will no longer block the entire script, only the running thread

November 8, 2021:
- Fixed the lingering lua crash issues caused by events with delays

November 2, 2021:
- When performing a spawn search, NPC Pets are now also considered NPCs (use nopet if you do not want this when searching NPC)
- The timestamp data type will now interpret correctly in Lua
- Bards are now considered "Slowers"

October 27, 2021:
- Restored hooks on Find Item window
- Implement more robust method of window switching. This improves /foreground behavior and
  profile keybinds from the launcher. This method utilizes the launcher to assist in foregrounding
  background instances of EQ. If this method fails, then it falls back to the existing method (#380)
- itemdisplay: Fix hang when inspecting items with certain kinds of spells.

October 26, 2021:
- Lua command is no longer case sensitive about script names (#403).
- Removed debug message from ItemDisplay
- Bzsrch: Fixed berserkers and searching for things that start with numbers (#398).
- Bzsrch: Better handling of queries that return no results (#335).
- Map: fix /mapshow not displaying map objects properly (#225)

October 26, 2021:
- ItemDisplay plugin has been rewritten with a focus on improving existing features:
  - Loot and Lucy buttons have been relocated nearby to an area that shouldn't overlap with existing controls
  - Spell and Item display information now updates correctly when the last window is recycled. This info
    will also be properly removed when the plugin is unloaded.
  - ${DisplayItem} will now track the most recently opened item display window, and will
    fall back to the next-most-recently-opened window if that one is closed, and so on.
  - ${DisplayItem[x]} is now 1-based, with valid values ranging from 1-6 representing one
    of the six possible item display window.
  - ${DisplayItem[<itemname>]} is now supported and will return the Item display window for
    the specified item name, if one exists.
  - Added Item and Window members to DisplayItem, which will return the related item and window.
    This can be used to do something like /invoke ${DisplayItem.Window.DoClose}
  - A settings menu in /mqsettings has been added with a whole bunch of options.
  - Added /itemdisplay reload to reload settings from ini.
  - Spell links in item display text will now link to spells. (Note, spell names in spell slots is not yet supported).
- /convertitem, /insertaug, /removeaug moved to main from ItemDisplay
- core: Removed reliance on undefined behavior from AddDetourf, now uses a type-checked implementation
  that can detect errors in setting up detours, and supports proper pointer-to-member and class hierarchies.
  If type-checking is problematic, an EzDetourUnchecked has been added.
- core: moved detour api declarations to include/mq/base/Detours.h
- spell display: Improved the behavior of finding spell names by category.
- autologin: Cancel autologin if cannot enter premium server due to free-to-play status. (#401).


October 21, 2021:
- Update for latest patch

October 20, 2021:
- Update for latest patch
- Fixed Map

October 9, 2021:
- Upgrade ImGui to 1.84 with new font renderer (FreeType) enabled
- overlay: VIEWPORTS feature is now OFF by default. Visit the overlay settings (/mqsettings)
  to turn it on.
- overlay: Implemented new revision of the ImGui overlay, hopefully squashing a bunch of
  issues and not creating very many new ones...
- overlay: /mqoverlay command has a couple new arguments: reload, resume, debug, stop, start
- Fix flickering issue caused by frame limiter when rendering UI at sim rate
- framelimiter: Restructured the framelimiter settings. Added some help tooltips too.
- framelimiter: Moved some options to only take effect when the frame limiter is active in the background.
- framelimiter: Added separate option for enabling frame limiting when in the foreground.

October 7, 2021:
- eqbugfix: Possible fix for "Mage" crash when casting spells from items.

October 5, 2021:
- Improved buff removal handling (#182).
- plugins: Added RemoveBuffByName, RemoveBuffBySpellID
- plugins: Renamed FindBuffID to FindBuffIndex, renamed RemoveBuffAt to RemoveBuffByIndex
- plugins: Removed RemoveBuff

October 1, 2021:
- Fix EverQuest.CurrentUI not getting updated after reinjection (#388).
- Add Stat and Count members to Keyring types (Mount, Familiar, Illusion) (#393).
- macros: keyring datatype renamed to keyringitem.

September 29, 2021:
- Added per-character settings for frame limiter. per-character settings are stored in
  servername_charactername.ini (#210).
- Added `/framelimiter reloadsettings` to re-read settings from ini.
- Fix ResetDevice crash after reloading mq
- Fix mouse scroll in imgui leaking into eq (#242).
- Fix imgui leaking into other render targets and causing issues (#286).

September 22, 2021:
- SpawnSearch:  Pets without PC masters will be assumed to be NPC Pets.  This fixes an issue where a
  spawn search for npcpet would fail to find a pet whose master was killed.

September 21, 2021:
- zoned.cfg and any of the Zone ShortName cfg files will no longer activate unles you're in game (#214)

September 19, 2021:
- lua: Fix plugin not initializing properly when an exception occurs while loading settings
- framelimiter: Fix UI not drawing when blind. (#285)
- framelimiter: Fix UI not drawing correctly when tied to simulation rate.
- framelimiter: Fix crash when logging out while in the background
- overlay: Fix edge case crash when graphics device is null (#363).

September 16, 2021
- Plugins can now be loaded via commands without requiring a MQ2 or MQ prefix.
  For example: "/plugin easyfind toggle" works to toggle the easyfind plugin.
- Fix /cleanup making inventory window appear instead of disappear
- Fix a crash that might occur if a plugin tries to execute a keypress when
  not in game.
- Fix a crash when /unload causes nav to unload before easyfind.
- Fix issue with RankName returning incorrect spell (#383) - really this time.
- Fix framelimiter not properly replacing the built-in throttler (#385).

September 15, 2021
- Updated for patch. Released before servers are up, there could be issues!
- Fixed issue with RankName returning the incorrect spell (#383)
- lua: fixed error message when script file doesn't exist
- lua: fix crash when checking for paused threads during OnWriteChat calls
- devtools: Added initial version RealEstate inspector that shows raw data about real estate
  plots and items. More work real estate capabilities coming in the future.
- devtools: added memory viewer to window inspector. Right click a window in the tree to access it.
- itemdisplay: Remove compare window. Use the one that is built in!

September 8, 2021
- eqlib: New code supporting mercenary aa's added, making mercenary aa access available to plugins.
- devtools: New alt ability inspector added for viewing data from player aa's and merc aa's.
- plugins: Added GetAAById to replace GetAAByIdWrapper.
- AltAbility type: Added Category (string), ShortName2 (string), GroupID (int)
- Switch type: Added state (int).

August 30, 2021
- Fix incompatibility with Innerspace/WinEQ when loaded at startup (#304)

August 29, 2021
- Added the following members to Window type for accessing tabs in a tabbed window: (#369)
   - TabCount, Tab, CurrentTab, CurrentTabIndex
- Added SetCurrentTab method to Window type for changing the current tab.
- More details on these can be found in the datatype docs at docs.macroquest.org

August 27, 2021
- Updated /mqanon command so that commands now work.  (Fixes #277, #280)
- Shortened the /mqanon "class" strategy to just the level and the class short name (Partially addresses #282)
- Added self (me) to the /mqanon all strategy for quick setup

August 25, 2021
- lua: **breaking** ImGui.Begin with flags now always requires a ImGui.End, unconditionally. Sorry, I
  missed this one the last time I was updating ImGui.Begin
- imgui: Fix a crash when too many End() calls occur
- autologin: Clean up duplicate logic and fix /switchchar (Fixes #311)
- autologin: Allow /switchchar and /switchserver to work if you didn't initally log in with Autologin
- autologin: Update Pause and Unpause to only work if the state machine is on (Fixes #151)
- autologin: Add Override for stopping at character select for Sessions and Station names (Partially addresses #145)
- autologin: Add new setting for CharSelectDelay with override for Sessions and Station names (Fixes #146)
- autologin: Change /relog command to only be available when logged in (it previously only WORKED when logged in)
- autologin: Add writing of global config when WriteAllConfig is set to true

August 24, 2021
- Added some error handling to catch imgui errors before they crash the game. These errors will
  suspend plugin ImGui usage. Fix the error and then run the command "/mqoverlay resume" 
- lua: Added missing overload for ImGui.SameLine(number, number)

August 20, 2021
- Added command for clearing mq console - /mqconsole clear
- Fix issue where /advloot shared # giveto name would not work when master looter was ungrouped in a raid

August 19, 2021
- Potential fix for mouse buttons getting stuck and causing issues with imgui
- Fix crash when performing /lua commands from within an imgui window.

August 15, 2021
- Fix ImGui lua threads from yielding after calling a command. ImGui thread isn't designed to yield. (#373).
- Fix MQCopyLayout command

August 14, 2021
- New TLO: ${Achievement} is now available for accessing achievements, achievement categories, and objectives.
- New DataTypes: achievementmgr, achievement, achievementcat, achievementobj
- For more details on these new types, please see the documentation at https://docs.macroquest.org

August 9, 2021
- Developer Tools: implemented new achievements inspector. Accessible from inspectors menu on the console.

August 8, 2021
- Added InGame.cfg which will execute for all characters once they are in game (#189)
- The cfg file search path will now search in Config\AutoExec before falling back to Config so that cfg files can be organized better (#170)

August 7, 2021
- lua: Further fixes for evaluating TLO object data members.
- lua: Partially reverted nil changes. see comments in #362 .
- lua: added mq.gettype to inspect the underlying data type of a data member usertype.
- Possible fix for a crash when the imgui overlay gets reset due to a lua exception.

August 6, 2021
- lua: /lua parse now prints the result of an expression to the console. (#365)
- lua: Empty/Invalid Macro data objects will now evaluate to nil, instead of "null" (#362)
- lua: os.exit will no longer crash the client and will instead exit the script (#297)

August 5, 2021
- Removed some old hooks for EQPlayNice. Consider using the built-in performance tools instead.
- Fix Target.bShowHelm (#331).
- Remove Spawn.BearingToTarget (#330). This is an internal state that is only updated when using /follow
  and its purpose or usage is extremely unclear.
- Fix Item.StackCount (#342).
- Fix Indexing group members in Group TLO (#346).
- Parse array index in Macro.Variable (#347).
- Fix Me.CashBank (#360).
- Fix Initialization of the lua directory (#361).
- dev tools: Added ZoneGuideWnd and ZonePathWnd customizations to WindowInspector
- dev tools: Added friendly tooltip to zone names in WindowInspector
- Evaluating Spawn.ID on a NULL Spawn will now return 0 instead of a parse error. This is intended as
  a convenience for utilizing Spawn variables that are set via ID.
- Fix auto scroll menu item in console window (#140).

July 31, 2021
- Added /mqsettings command to toggle the MacroQuest Settings window (you can still get to it from the EQ button as well)
- Added ShowMacroQuestConsole option to the MacroQuest.ini which allows you to default the Console to On if you'd like
- Fixed custom filters not being added properly (#327)
- Fixed /itemnotify (by name) choosing the wrong item when the item name started with a number, even though it was quoted ("1 lb. Cragbeast Meat" for example)

July 30, 2021
- Adding missing imgui mouse button enum values (#354).
- Reset the imgui overlay when a lua exception occurs on the imgui thread (#355). This will
  help prevent crashes when encounding lua errors, but not in all cases.
- Fixed some issues with type conversions in lua (#359).
- Fixed console commands not working at login.
- Refactored of MQ2Lua, please report any new bugs that might come up as a result!

July 24, 2021
- Added back the String TLO after a 16 year hiatus. Usage: ${String[foo].Right[2]} etc.

July 21, 2021
- Updated for patch

July 19, 2021
- Comands executed from console are now deferred so that they do not inherit the
  temporary floating point state of the imgui renderer (#351).
- Fix skeleton and other similar race checks when computing if character can mount.
- Fix ${Zone[xyz]} not returning correct value when 'xyz' is the current zone.

July 17, 2021
- Added /mqtarget and /eqtarget commands.  /mqtarget is the equivalent of the current /target commmand while
/eqtarget will use the game's existing command.  Macro authors can begin migrating to /mqtarget when they want
to use MacroQuest specific targeting.  Partially addresses #298

July 9, 2021
- Fixed /removebuff and /removepetbuff so they now accept quoted or unquoted strings (#184, #344, #345)
Updates to MQ2Lua:
** BREAKING CHANGE **
- If you are a Lua script author, a change has been made to ImGui.Begin: it must now
  **always** be followed by a ImGui.End, even if it returns false values. This
  was necessary to resolve the issue where it was ambiguous whether End should be
  called or not. Now, we just always expect you to call it if you called Begin.

- Added bit32.bnot, bit32.band, bit32.bor, bit32.bxor, bit32.lshift, bit32.rshift, bit32.ror, and bit32.rol
  These functions are provided to allow bitwise operations on 32bit integers.
- Exposed the following general functions to lua:
    PushStyleVar, PopStyleVar, TreeAdvanceToLabelPos, PushID (with arbitrary object), CheckboxFlags, GetStyle
- Exposed the ImGui Tables API to lua. It includes access to the following functions:
    BeginTable, EndTable, TableNextRow, TableNextColumn, TableSetColumnIndex, TableSetupColumn,
    TableSetupScrollFreeze, TableHeadersRow, TableHeader, TableGetColumnCount, TableGetColumnName,
    TableGetColumnIsVisible, TableGetColumnIsSorted, TableGetHoveredColumn, TableGetSortSpecs, TableSetBgColor
- Added the following enum types to lua:
    ImGuiSortDirection, ImGuiTableFlags, ImGuiTableColumnFlags, ImGuiTableRowFlags, ImGuiTableBgTarget, ImGuiStyle
- Added the following user types to lua:
    ImVec2, ImVec4, ImGuiListClipper, ImGuiTableSortSpecs, ImGuiTableSortSpecsColumn
- Added new way to import and ui ImGui. This has the advantage of allowing the use of ImGui in
  a global context

    require 'ImGui'
    local TEXT_BASE_WIDTH, _ = ImGui.CalcTextSize("A")
    function DemoFeatureImGui()
        -- do update
    end
    ImGui.Register('DemoFeature', DemoFeatureImGui)

- For an example of how to use most of these new apis, see lua/examples/demo_tables.lua

Updates to Timestamp type:
- Added TimeDHM to Timestamp type to express Days:Hours:Minutes
- Added Days to Timestamp type.
- Added MaxTimers and Timer to DynamicZone. Timer returns a type dztimer:

updates to DynamicZone:
* ${DynamicZone.MaxTimers}
  - returns the number of timers
* ${DynamicZone.Timer[N]}
  - access the timer by index
* ${DynamicZone.Timer[ExpeditionName|EventName]}
  - access a specific timer by its expedition and event name. Event
    name is optional and it will return the next expedition timer to
    expire if it is omitted.
- Added dztimer type with the following members: ExpeditionName, EventName,
  Timer, EventID.
- Fixed DzMember access

July 3, 2021
- Fix chat events in other languages not being able to use .equal for the matched text (#333)
- Fix ctrl+c to copy in the console window

June 24, 2021
- Fix crash that would occur for some characters while zoning
- Fix Task.Select and Task.Timer (#329)

June 12, 2021
- Added Macro Expression Evaluator tool. Can be used to display the result of a macro expression
  in real time. Find it underneath the Tools menu in the console.
- Added the following int members to Me: AirSupply, MaxAirSupply, PctAirSupply.
- Fix GetSpellByName returning wrong spell when multiple options are available with the same name
  by preferring a spell with a category over one that does not. (#321).

June 11, 2021
- Fix issue where invalid escape sequences would crash when printing to console (#322).
- Fix /doors not searching text properly
- static library build outputs are now written to build/lib in order to remove them from the
  output folder and also separate 32-bit and 64-bit versions.

May 28, 2021
- Fixed issue with keyboard input not working on popped-out windows
- Implemented new console editor with support for word wrap and item links.
- Fixed buyer window sorting (#238)

May 24, 2021
- Added the ability to render EQ icons in lua imgui bindings

May 23, 2021
- Corrected a long standing issue where you couldn't store mq userdata in lua variabls (#252)

May 17, 2021
- Added specific updates in frame limiter to allow for scribing and memming with no rendering (#279 & #167)

May 15, 2021
- Added variadic string arguments to mq.doevents() to allow for a list of specific events processing (#292)
- Added a command mq.flushevents() that takes variadic string arguments to drop events without processing them (#292)

May 14, 2021
- Added drag/drop interface to lua imgui bindings

May 7, 2021
- Plugins using pLocalPC->zoneId (GetCharInfo()->zoneId) will once again function properly (#287)

May 5, 2021
- Fixed InputText ImGui functions in the lua binding, also removed the buffer size argument.
- /mqlog will no longer force a parse on items sent to the log (#177)

May 1, 2021
- Fixed an issue with inventory slots being out of order due to ui load order (#247)
- Updated MQ2Bzsrch structure and fix bzsrch crash (#108)
- Fixed /maploc
- Fixed MQ2LinkDB and improved item link behaviors in general
- Misc fixes to mqanon (#278, #275)
- Add Select method to MQ2Bzsrch: /invoke ${Bazaar.Item[1].Select} (#202)
- Add SortedItem to MQ2Bzsrch, to return results sorted the same way as the search window.
    ${Bazaar.SortedItem[1]} returns first item in the bazaar search results.

April 26, 2021
- Allowed access to TreeView members as if they were list entries
- Added ${Macro.Variable[]} member to get macro variables outside the macro environment

April 18, 2021
- Fixed spawn datatype Buff member index to use MaybeExactCompare (and allow for =)

April 11, 2021
- Added file dialog to imgui infrastructure
- Added Lua gui that can launch scripts and observe script status

April 7, 2021
- Changed the Lua event callback signature to take the entire matched line as the first argument

April 6, 2021
- Fixed LineOfSight (#260)
- Various fixes to the assignment of macro data to spawn variable types.
- Removed blanket [MQ2] from WriteChat lines (#112)

Mar 26 2021
- Fix noauto being missed when using /plugin someplugin load noauto
- noauto in the engine command and in the plugin command is no longer case sensitive
- Fix loading of config for MQ2CustomBinds (#243)

Mar 20 2021
- Fix ${MacroQuest.Version} (#232)
- Fix News window not appearing at character select
- Fix coloring on the news window after date format change in changelog

Mar 17 2021
- Fix cached buffs not being able to look up buffs (#229)
- Fix ${Pet} defaulting to my pet (#230)
- Fix a crash in mq2chatwnd if /style is used before window is created (#231)
- Added right click menu to window inspector tree which gives the option to copy the window TLO
  text as well as opening up a new window inspector. (#224)

Mar 16 2021
- Fix Me.Pet (#227)
- Fix /face fast (#226)
- Add ${Me.Pet.Focus} - bool type, reflects the Focus state if your pet. (#228)

Mar 14 2021
- Implementation of SPAWNINFO has been switched over to use the new class hierarchy
  based on PlayerClient. SPAWNINFO and PlayerClient are now synonymous. Typecasts
  should no longer be needed.
- SPAWNINFO can now be assigned and copied between macro vars using the "spawn" type.
- An int can be assigned to a spawn var to look up the spawn by id.
- SPAWNINFO is no longer copyable or createable, all existing code paths that used
  SPAWNINFO as a container for mq2 data has been rewritten.
- Work-in-progress iteration of settings window for MQ2Map added. more to come in the
  future.
- ItemTarget no longer returns Spawn type. It now returns Ground type. It behaves the
  same way as Ground except that the default search is of the current ground item target.
- Certain SPAWNINFO global such as EnviroTarget or DoorEnviroTarget are now removed
  and no longer supported.
- Fixed FindItem window column sorting. Fixed money sorting to teach items with
  no vendor value as being the least valuable.
- Added bounds check to /notify to avoid crashing

Mar 07 2021
- Fix EQ_Spell structure misalignment
- Changed /doability so it now takes fake ID 1-6 where it previously only took 1-5
  because people were confused when fake IDs did not work.
    I strongly recommend you never use fake ID 1-8, it's incredibly stupid, just use the real
    name, for example /doability Hide or the REAL ID which in the example of Hide is 29, so /doability 29.
- Fix ${Me.PctExpToAA}
- Added sorting capability to the /buyer buy lines list
- Added sorting capability to the /barter inventory list
- Added Value column to the /barter inventory list so we can sort by merchant value.
- Added Rightclick on item feature to /barter inventory list so it opens up the item inspect window.
- Added FellowshipMember.Sharing

Mar 01 2021
- Fix :OnExit so that it processes even while paused.  This also fixes the behavior where you
  would have to /endmac twice on a paused macro with an :OnExit routine

Feb 16 2021
- Added Plugin TLO boolean member IsLoaded
  Example:  ${Plugin[mq2lua].IsLoaded}
- Added Me TLO int member MaxLevel to get the current max level based on your expansion
  This should help with TLP Max Level checks in scripts
  Example:  ${Me.MaxLevel}
  Would return 60 if you were currently on a TLP in Kunark/Velious/Luclin

Feb 12 2021
- Split MQ2TargetInfo into individual window components
  - MQ2TargetInfo deals with the target window
    - Use /targetinfo to see help
    - Use MQ2TargetInfo.ini to adjust UI specific settings
    - Added command line arguments perchar, distance, info, placeholder, and sight toggle options to modify each of the options.
  - MQ2XTarInfo deals with the Extended Target Window
    - Use /xtarinfo to see help
    - Use MQ2XTarInfo.ini to adjust UI specific settings
    - Added command line arguments perchar and distance toggle options to toggle options.
    - Fixed an issue where your Extended target window would be extended even if you did not have the slots available yet
  - MQ2GroupInfo deals with the Group Window
    - See MQ2GroupInfo Changelog

Feb 4 2021
- Fixed issues with custom UIs being reset when /reloadui is issued
- Fixed issues with having to reload plugins that modify the UI when using a custom UI
- Fixed issues with /multiline appending extra characters
- Deprecated IsXMLFilePresent -- this doesn't give you any indication of whether the XML
  file is usable, so we can rely on file checks for that and AddXML for the error messages.
- Added a helper function IsScreenPieceLoaded that can be used to check to make sure your
  custom UI addition is loaded (or not).

Jan 24 2021
- Implementation of CHARINFO has been switched over to use new class hierarchy based
  on PcBase and CharacterBase. Removed old CHARINFO/CHARINFONEW definitions. There should
  be no functional changes.
- Update /ini to create folder if it doesn't exist
- Fix PickupItem/DropItem (function used by itemnotify) to allow picking up and dropping
  items when they are in a closed bag.

Jan 20 2021
- Removed HTML Window code that was deleted from EverQuest.
- Added CLICKABLE parameter to Item.ItemLink datatype member.
- Update filename references from MacroQuest2 to plain MacroQuest.
- Fix listselect/comboselect: selecting out of range will deselect current item. Enables
  comboselect without using screen coordinates or opening combobox popup first.
- Fix /ini improper handling of NULL or absent parameters.
- Deleted gearscore code from MQ2ItemDisplay. Use the standalone plugin instead.

Jan 8 2021
- Fixed raid assist indexing
- Added WillLand and WillLandPet to Spell datatype. Checks if the buff will stack but without
  a duration component. This provides a raw "this will land on your target" check.
- Fix bool properly handling empty string as falsey
- Add warning when invalid datatype conversion is happening
- Added chance spells to Spell.Trigger member

Dec 10 2020
- Fixes to new alt currency
- Fixes for num expansions
- Fixed ZONE_COUNT, this should fix misc plugins that rely on it being correct.

Dec 08 2020
- Added .Move to the Window TLO Methods
	Usage: /invoke ${Window[GroupWindow].Move[100,200,300,400]} ([x,y,width,height])
	Omitting a parameter will use the existing value
- Added .SetBGColor to the Window TLO Methods
	Usage: /invoke ${Window[GroupWindow].SetBGColor[FF000000]} ([argb])
- Added .SetAlpha to the Window TLO Methods
	Usage: /invoke ${Window[GroupWindow].SetAlpha[255]} (0-255)
- Added .SetFadeAlpha to the Window TLO Methods
	Usage: /invoke ${Window[GroupWindow].SetFadeAlpha[255]} (0-255)

Dec 07 2020
- Fixed malo/tash detection problems

Dec 05 2020
- Chatwindow at charselect now saves it's position independently from in game

Dec 03 2020
- Added WarforgedEmblem and RestlessMark Currencies
- Added .Sharing to the fellowship tlo it returns true of false if exp sharing is on for the member
	Usage: /echo ${Me.Fellowship.Sharing[x]} where x is fellowship member 1-12

Dec 02 2020
- Added MarkNPC to the raid tlo

Nov 19 2020
- All instances of CFacePick has been changed to CPlayerCustomizationWnd

Nov 06 2020
- Update RaidType.MainAssist to support index by number or name.

Oct 31 2020
- Fixed a few spell and spellmgr bugs

Oct 21 2020
- Added raid to chat events - Cred Kaen01

Oct 13 2020
- Added a fix for stopping movement in mq2targetinfo

Aug 20 2020
- Fixed the findwindow feature

Aug 19 2020
- Fixed CButtonWnd::SetCheck
- Added CHotButton::SetCheck

May 14 2020
- Filled in the CGuild class

Apr 30 2020
- Me.Invis now takes an optional index or a name to return invis vs undead and animals
  Example 1: /echo ${Me.Invis} just return the normal one like before, are u invis of any kind.
  Example 2: /echo ${Me.Invis[ANY]} or just ${Me.Invis[0]} returns true if you are invis of any kind, same as just doing ${Me.Invis}
  Example 3: /echo ${Me.Invis[NORMAL]} or just ${Me.Invis[1]} returns true if you are normal invis.
  Example 4: /echo ${Me.Invis[UNDEAD]} or just ${Me.Invis[2]} returns true if you are invis vs undead
  Example 5: /echo ${Me.Invis[ANIMAL]} or just ${Me.Invis[3]} returns true if you are invis vs animal
  Example 6: /echo ${Me.Invis[SOS]} or just ${Me.Invis[4]} returns true IF you are a ROG AND in fact hidden AND have a skill of at least 100 in HIDE AND have the AA for SoS

Apr 29 2020
- Added ms to /delay
  Usage: /delay 1500ms
  will delay 1.5 seconds...

Apr 28 2020
- Optimized the GetGroupMainAssistTargetID inline.
- Fixed /foreground to respect maximizzed window pos - bug reported by Kaen01
- Added .SpellRankCap to the character TLO. It returns an in representing your characters spell rank cap.
  if it returns:
  1 = you CAN cast Rk. I spells
  2 = you CAN cast Rk. II spells
  3 = you CAN cast Rk. III spells

Apr 24 2020
- Optimized GetRaidMainAssistTargetID.

Apr 15 2020
- Fixed ${Me.CanMount} for some indoor zones that where not flagged as nomount and added bazaar, nexus to zones where its ok to mount.

Apr 14 2020
- Updated the FellowShip struct for LIVE

Apr 06 2020
- Added .MyDuration to the Spell TLO. It returns a ticktype of YOUR duration for the spell in question.
- Caption redrawing has been optimized to use less cpu cycles.

Apr 02 2020
- Add bSeeInvis, bSeeSOS and bSeeIVU to SpawnSearch - CTWN

Apr 01 2020
- Fixed ZoneFlags
- Fixed the _ZONELIST struct
- Added .CanMount to the Character TLO it's a bool it returns true if u can mount in the zone u are in and if it won't collide with an illusion u have on. 
- Added .ToiletPaper to the Character TLO it returns true if you need to go out and get more.

Mar 31 2020
- Fixed all Spell Stack checks. (yes again, hopefully for good this time.)

Mar 28 2020
- Removed a WriteChatf from Task.Timer
- Added a function which can be used by plugins to format numbers:
    EQLIB_API void PrettifyNumber(char* string, size_t bufferSize, int decimals = 0);
  If the given string is a number, it will add commas and set the desired number of decimals.
  For integers, leave decimals as 0. For floats, a value of 2 is recommended. Min is 0, max is 9.
- Added .Prettify to Int, Int64, Float and Double types. 
    Example: ${Me.MaxHPs.Prettify} => 30,103
    Example: ${Target.Distance.Prettify} => 1,151.24
  Prettify takes a number of decimals of precision as a parameter:
    Example: ${Target.Distance.Prettify[4]} => 1,151.2395

Mar 26 2020
- Added CAAWnd__UpdateSelected_x
- Added CAAWnd__Update_x
- Changed ShowSpellSlotInfo so it takes a custom linebreak.

Mar 25 2020 by ChatWithThisName
- MQ2ChatWnd: Added ingame toggles for SaveByChar, Autoscroll, NoCharSelect to the /mqchat command
  Available options are:
    no parameter, will output what it's currently set to. Example: /mqchat SaveByChar
    On - Turn on the option. Example: /mqchat autoscroll on
    Off - Turn off the option. Example: /mqchat NoCharSelect off

Mar 19 2020
- Added CXRect__operator_and
- Fixed CTextureFont::DrawWrappedText
- Added CTextureAnimation::Draw
- Added CTAFrameDraw::Draw

Mar 19 2020 by brainiac
- Made a couple additional changes to /taskquit from the update on Mar 16 2020:
    fix /taskquit <name> to search solo tasks when a shared task is present.
    fix /taskquit <name> to be exact match only
    change /taskquit <name> to no longer use quotes.

Mar 16 2020
- Extended the /taskquit command. It now takes an optional argument, "Name of Task" so we can use it to remove solo tasks as well. -Feature Cred: drwhomphd
   /taskquit without any argument works like before, i.e it removes the shared task if there is one.
- Usage /taskquit "Basic Training"

Mar 15 2020
- Fixed a bug with ${Macro.CurSub} it will now correctly return the sub its used in.
- Fixed a bug where tells you would not be detected in all languages. Thanks Kaen01 for report.

Mar 14 2020 by Sic
- Added ParcelStatus to the character TLO.
  Usage: /echo ${Me.ParcelStatus}

Mar 09 2020
- Updated for TEST
- Updated for LIVE
- Fixed ${Spell[permanent spell here].Stack} so it actually returns true when they DO stack.

Mar 06 2020
- Added CTabWnd::RemovePage
- Fixed CXWnd::DrawColoredRect crash

Mar 03 2020
- Updated for TEST
- Updated for LIVE
- Added CPageWnd::FlashTab

Feb 27 2020
- Updated for TEST
- Updated for LIVE
- Added support for spaces in /hotbutton Name. Use /hotbutton "Button Name With Spaces" in quotes.
- Fixed GetChildWndAt
- Updated CAAWnd::ShowAbility
- Filled in CPageWnd members
- Updated CHARINFO struct etc.
- Previously Updated:
- Fixed the CursorAttachment Struct
- Macro Authors, take notice: Fixed ${Me.AltAbility[blah].Rank} it now properly returns 0 if you don't have any points spent in a AA.

Feb 18 2020
-Updated for TEST
-Updated for LIVE

Feb 14 2020
-Updated for LIVE

Feb 11 2020
-Updated for LIVE

Feb 09 2020
- Fixed a bug where our version of /hotbutton would not save the button to the ini. - reported by DrWhomPhd

Feb 06 2020
- Updated for TEST

Feb 05 2020
- Updated for TEST

Jan 25 2020
-// ***************************************************************************
-// Function:    DoHotbutton
-// Description: our '/hotbutton' command
-//              Extends the built in /hotbutton command with multiple lines support
-// Usage:       /hotbutton [Name] <color> <Line:><Cursor:>[Text]
-//				<Line can be 1-5
-//				<Cursor can ONLY be 0 which means DO NOT put the hotbutton on the cursor.
-//				Usage:
-//				/hotbutton TheName 14 1:0:/echo hi	(Where 14 1:0: in this case means use color 14, then place /echo hi on LINE 1 and NO Cursor Attachment.)
-//				/hotbutton TheName 14 1:/echo hi	(Where 14 1: in this case means use color 14, then place /echo hi on LINE 1.)
-//				/hotbutton TheName 1:0:/echo hi		(Where 1:0: in this case means place /echo hi on LINE 1 and NO Cursor Attachment.)
-//				/hotbutton TheName 1:/echo hi		(Where 1: in this case means place /echo hi on LINE 1.)
-//				/hotbutton TheName 0:/echo hi		(Where 0: in this case means NO Cursor Attachment.)
-//				Finally, just doing /hotbutton TheName 14 /echo hi OR /hotbutton TheName /echo hi just calls the eq function like before.
-// ***************************************************************************

Jan 21 2020
- Added .Size to the Window TLO, it returns a string x,y
  Usage: /echo ${EverQuest.LastMouseOver.Size}
  Output: 100,200
- Added feature to be able to load tga files (animations) from local uifiles directory. -brainiac

Jan 20 2020
- Misc Fixes to triggers etc - braniac
- Me.CountersXXX now also count ShortBuffs (${Me.Cursed} now returns Restless Ice, for example.)

Jan 15 2020
- Added /invoke to the list of commands that can trigger a bind.
- Updated for LIVE

Jan 14 2020 by Sic
- Updated MQ2Melee
- If you use builder don't forget to recheck it.

Jan 13 2020
- Updated max level to 115
- Updated the skillmanager for all builds.

Jan 13 2020 by Chatwiththisname
- Added MQ2SpellType Members: HastePct, SlowPct.
- Added GetMeleeSpeedPctFromSpell(PSPELL, bool) (Exported in Main)
- Added GetMeleeSpeedFromTriggers(PSPELL, bool) (not exported)
- Added HasTrigger(PSPELL) (not exported)
		GetMeleeSpeedPctFromSpell is used in HastePct and SlowPct.
		If the pSpell has a trigger it will automatically check the triggers for the modification speed. 
		Examples: 
			${Target.Slowed.SlowPct}
			${Me.Hasted.HastePct}
			${Spell[Slowing Helix].SlowPct}
			etc etc.
- Fixed GetSelfBuffBySPA(int, bool, int);
- Fixed GetTargetBuffBySPA(int, bool, int);
- Fixed GetSelfShortBuffBySPA(int, bool, int);
- Fixed HasCachedTargetBuffSPA(int, bool, PSPAWNINFO, PcTargetBuff);

	In all the above SPA buff checks if the SPA matched, but wasn't the increase or decrease
	desired, it would stop checking anymore buffs. 
	Example: ${Target.Slowed} should return a pSpellType of a slow debuff on the target. But
		if the target had a haste buff before the slow buff it would find SPA 11 and since it was
		an increase instead of a decrease it would return -1, or NULL. Changing it to break; for those
		SPA's allows it to continue checking the buffs and find any subsequent SPA 11's correctly.

Jan 12 2020
- Fixed the ZoneGuideManagerClient class for LIVE build.
- Updated for TEST

Jan 11 2020
- Fixed the ZoneGuideManagerClient class for TEST build.

Jan 10 2020
- ${Me.Spell[blah]} now searches for rank spells as well - brainiac
  Example:  You have Demand For Power Rk. II in your spellbook.
  Usage:    /echo ${Me.Spell[Demand for Power]}
  Output:   Demand For Power Rk. II
- MQ2Melee has been updated for ToV - Sic
- (If you use builder don't forget to recheck it.)

Jan 09 2020
- Added Me.Spell it return a SpellType selecting spells only from YOUR SpellBook. - brainiac
  Usage: /echo ${Me.Spell[Spirit of Wolf].ID}
  Output: 278
  Usage: /echo ${Me.Spell[278].Name}
  Output: Spirit of Wolf
- Fixed a wrong offset for pinstCBlockedBuffWnd_x for TEST build - SwiftyMuse
- Book Icon and Gem Icon IDs will no longer be shown in ItemDisplay when they are 0 - SwiftyMuse

Jan 08 2020
- Updated for TEST
- CONTENTS changed by dbg. The evolving stuff is now in its own struct, plugins that use it need to be edited.
  Example: PrePatch: pCont->EvolvingCurrentLevel
  Now: pCont->pEvolutionData->EvolvingCurrentLevel
  The Following are members of pEvolutionData: GroupID, EvolvingCurrentLevel, EvolvingExpPct, EvolvingMaxLevel, LastEquipped;
- ItemColor is now gone from CONTENTS.

Dec 21 2019
- Fixed a crash in mq2chatwnd.cpp on /camp desktop
- Fixed the chatwindow disappearing act.
- Fixed mq2eqbc window disappearing act.
  Don't forget to recheck it in builder.

Dec 20 2019
- Updated for LIVE
- If your chatwindow does not show up type /mqchat reset

Dec 19 2019
- Updated for TEST
- /plugin without specifying unload now acts like a toggle, if plugin is loaded it unloads it.

Dec 18 2019 Torment of Velious Build
- Updated for LIVE

Dec 06 2019
- Added .SpellIcon and .GemIcon to the Spell TLO.
- Fixed the Button structure

Nov 26 2019
- Added SubscriptionDays to the Character TLO it returns an int. Cred request: @sic
  Usage: /echo I have ${Me.SubscriptionDays} left before my all access expires.
- Updated MQ2AutoForage at https://www.macroquest2.com/phpBB3/viewtopic.php?f=50&t=9588&p=70471

Nov 23 2019
- MQ2Main (ChatWithThisName) Add /removelev command. typing /removelev will remove any levitation in the buff or shortbuff window. 

Nov 22 2019
- Fixed a bug where /aa wouldn't parse input

Nov 20 2019
- Fixed ${Me.SpellInCooldown}
- Fixed ${Me.InInstance}

Nov 20 2019
- Updated for LIVE
- Added .LeaderFlagged to the DynamicZoneType TLO it returns true if the dzleader can successfully enter the dz (this also means the dz is actually Loaded.)
- Usage: ${DynamicZone.LeaderFlagged}
- Added .Flagged to the DZMemberType TLO it returns true if the dzmember can successfully enter the dz.
- Usage: ${DynamicZone.Member[x].Flagged} where x is either index or the name.

Nov 14 2019 by brainiac
- Re-fixed EQINVSLOTWND
- Added ALT_MEMBER_GETTER macro that defines an alternate name that a member can be
  accessed with, thereby removing the need to immediately update all code to use new
  variable names.
- You can now use the old, or the new names for Slot1, Slot2, Slot3, Location and *suprise* Wnd.

Nov 13 2019
- Fixed EQINVSLOTWND.
- Renamed WindowType in the EQINVSLOTWND struct to Location
- Renamed InvSlot in the EQINVSLOTWND struct to Slot1
- Renamed BagSlot in the EQINVSLOTWND struct to Slot2
- Renamed GlobalSlot in the EQINVSLOTWND struct to Slot3

Nov 05 2019
- Right Clicking the Lucy button on the item display window will now open Lucy in your external default browser.
  Left Click opens it inside of eq as usual.

Nov 04 2019
- Task TLO can now be accessed by index to make iteration possible.
  Example: /echo ${Task[2].Title}
  NOTE: THIS INDEX IS NOT THE SAME INDEX AS THE ONE YOU SEE IN THE QUEST WINDOW LIST.
        We are iterating through the IN MEMORY quest entries, we are NOT
		iterating the window list, if you want to do that, use the Window TLO.
- Added .WindowIndex to the Task TLO it returns the Quest Window List Index. (if the window actually have the list filled...)
  Usage: /echo ${Task[3].WindowIndex}
  Usage: /echo ${Task[Into The Muck].WindowIndex}

Nov 02 2019
- Added item search by number to the ${Ground} TLO
- Example: /echo ${Ground[4]} will return the 4th closest item it finds.
- You should probably check that there actually are 4 items on the ground 
  with ${GroundItemCount} though, or it will obviously return NULL if there is'nt.
  I don't know how useful this feature is since we can iterate through .Next anyway, but someone asked for it so...

Nov 01 2019
- Added ${Me.Origin} which returns a pZoneType of your starting city.

Oct 26 2019 by SwiftyMUSE
- Fixed ${Spawn.State} so DEAD spawns don't show as STUN

Oct 22 2019 by Eqmule
- Fixed ${Task[blah].Select}

Oct 21 2019 by Eqmule
- Fixed SetEscapable and SetEscapableLocked

Oct 20 2019 by Chatwiththisname
- More /caption anon fixes.

Oct 16 2019 by Eqmule
- Updated for LIVE
- I am aware the .Select for the task tlo needs a fix, I can't get that in right now but will be looking at a fix the next couple days.
- Use the window tlo meanwhile if u need to select in that window.

Oct 09 2019 by Chatwiththisname
- Added two new /mapfilter options for CampRadius and PullRadius.
- They add two new circles that work like SpellRadius except it's stationary where set.
- Type /mapfilter for help.

Oct 02 2019 by Eqmule
- Made some changes to the ${Task} TLO
- It's likely some macros will break due to these changes, but
  I felt the upside with not having to rely on the window warrants that.

- New Feature: It's no longer needed to have the task window open to access the TLO.
- Added .Type to the TaskObjective TLO
  It returns a string that can be one of the following:
  Unknown,None,Deliver,Kill,Loot,Hail,Explore,Tradeskill,Fishing,
  Foraging,Cast,UseSkill,DZSwitch,DestroyObject,Collect,Dialogue
- Added .CurrentCount which returns the current count of the .Type needed to complete a objective.
- Added .RequiredCount which returns the required count of the .Type needed to complete a objective.
- Added .Optional which returns true or false if a objective is optional
- Added .RequiredItem which returns a string of the required item to complete a objective.
- Added .RequiredSkill which returns a string of the required skill to complete a objective.
- Added .RequiredSpell which returns a string of the required spell to complete a objective.
- Added .DZSwitchID which returns a int of the switch used in a objective.
- Example: /echo ${Task[The Grand Illusion].Objective[1].CurrentCount}
- Added .ID to the ${Task} TLO it returns an int of the task ID
- Example: /echo ${Task[The Grand Illusion].ID}
- Ok so fair warning, the taskwindow doesn't add items by index, unless sorted by first column,
  and even then, it can be "off" (because reasons)
  so... if you are smart don't use ${Task[1].ID} and expect it to be whatever is the first list item.
  ALWAYS refer to taks by their NAME.
  so like: ${Task[The Grand Illusion].Step.Index} WILL absolutely always return the correct index
  as returned by the taskmanager, but it might not be the index you "see" in the window.
  Bottomline, we should not rely on the window anymore.
  It's useful to look up the name of the tasks, basically.

Sep 18 2019 by Eqmule
- Updated for LIVE

Aug 26 2019 by Knightly
- Removed #knightlyparse
- New TLO ${MacroQuest.Parser}
- New slash command /engine parser <x> [noauto]      (where X is the version of the parser, right now 1 or 2 and noauto if you don't want it in your ini)
- New macro command #engine parser <x> 
- Parser gets reset to the default in your ini whenever a macro ends
- Full documentation at https://gitlab.com/Knightly1/mq2-parser-changes

Aug 21 2019 by EqMule
- Updated for LIVE
- Fixed the parser so it can run at charselect again. (Don't run macros there that need access to ingame variables...)

Aug 16 2019 by EqMule
- #knightlyparse is now a macro keyword, add it to the top of your macros if you want to use this version of the parser.
- Previously Fixed: EQGroundItemListManager

Aug 15 2019 by EqMule
- Fixed a zoning crash
- Fixed a crash on TEST in mq2itemdisplay when inspecting spells.

Aug 13 2019 by EqMule
- Updated for TEST

Jul 31 2019 by EqMule
- Fixed a clear target bug in mq2targetinfo -dannuic -knighty
- Next release:
- TODO: Fix EQGroundItemListManager so we can get /itemtarget working for guild objects again.

Jul 27 2019 by EqMule
- Turned on Knightlyparse.
- Added support for mq2dannet to mq2targetinfo.
- You can now confgure the mimic me feature in mq2targetinfo.ini to use dannet (or any other plugin u use for it's commands.)
- Added ${Me.LastZoned} to the character TLO. It returns a timestamp of last time you zoned.
- Removed EQ_END_ZONE and EQ_BEGIN_ZONE.
- Added new detours for zonechange detection.
- ${Me.Zoning} is depreciated, use ${Me.LastZoned} or just wait for ${Zone.ID} to change.

Jul 17 2019 by EqMule
- Updated for LIVE

Jul 15 2019 by EqMule
- Updated for TEST

Jul 11 2019 by EqMule
- Updated for TEST
- Updated for LIVE
- updated for EMU
- Fixed a crash when /echo ${InvSlot[enviro1].Item.ID} - cred report kaen01

Jun 22 2019 by EqMule
- Updated for TEST
- Updated for LIVE

Jun 20 2019 by EqMule
- Fixed Me.PctExp and Me.PctAAExp
- Fixed /advloot
- Fixed a mq2ic crash. cred: psxoxo

Jun 19 2019 by EqMule
- Updated for LIVE
- Added ${Macro.CurSub} returns the name of the current Sub being executed. -cred alynel
- Added ${SubDefined[blah]} it returns a bool if a Macro Sub is defined. -cred alynel
- Previously Added: .CachedBuff[x] to the spawn tlo where x is a spellid if its a number and a spell name if not. It returns a MQ2CachedBuffType.
- Previously Added: .CachedBuff[#x] to the spawn tlo where #x is a buffslot between 1-97. It returns a MQ2CachedBuffType.
- Previously Added: .CachedBuff[*x] to the spawn tlo where *x is a index (buffslots are not sorted). It returns a MQ2CachedBuffType.
- Previously Added: .CachedBuff[^x] to the spawn tlo where ^x is a keyword. It returns a MQ2CachedBuffType.
	^x keywords: Slowed Rooted Mezzed Crippled Maloed Tashed Snared and Beneficial

- MQ2CachedBuffType has the following members:
	.CasterName .Count .Slot .SpellID .Duration

- Previously Added: .CachedBuffCount to the spawn tlo. it returns -1 if no buffs are cached for the spawn or number of buffs cached.
- Using CachedBuff to get buff info on targets, group members etc, only requires you to target the entity once. after thats done, buffs are cached.
- The upside is obviously that we don't have to target back and forth constantly.
- Usage: well lets say you are a druid and you want to know if a group members sow buff has worn off, you can just check CachedBuff without having to retarget the group member.
- /echo ${Group.Member[2].CachedBuff[Spirit of Wolf].Duration}

Jun 14 2019 by EqMule
- Updated for TEST

Jun 05 2019 by EqMule
- Fixed a crash in the TEST build.

Jun 01 2019 by EqMule
- Fixed Events for text that contain 'x12' tags
- Added Me.BlockedBuff and Me.BlockedPetBuff both return a pSpellType idea cred: chatwiththisname
- Usage: /echo ${Me.BlockedBuff[x].ID} where x is 1-40

May 30 2019 by EqMule
- Fixed /dosocial
- Some other stuff I'll documment later.

May 24 2019 by EqMule
- BuffsPopulated returns 1 for a empty buff list and a number above 1 if there was some buffs received.
  So if you do /echo ${Target.BuffsPopulated} and it returns 1 it means the target does not have any actual buffs, but the list was received (and it was empty).
  any number above 1 means the list was not empty...
  NOTE: Use ${Target.BuffCount} to get the ACTUAL VISIBLE buffs (BuffsPopulated is BuffCount + 1)
- Some other stuff I'll documment later.

May 23 2019 by EqMule
- Added the possibility to login new characters using plaintext credentials, no mq2 login profile needed:
	Usage:
	/loginchar servername^login^charname^password
	AND if you want to stop at charselect don't specify charname:
	/loginchar servername^login^password
- Made /quit command work at charselect
- Added a Syntax Error to the parser when you try to parse strings greater than 2048 instead of crashing you.

May 22 2019 by SwiftyMuse & EqMule
- Fixed ${Me.SpellInCooldown}
- Fixed some parsing bugs.
- 
May 17 2019 by EqMule
- Updated for TEST

May 16 2019 by EqMule
- Fixed Get Current Mana and Get Current Endurance
- Fixed MQ2Rez spam (yes really this time)
- MQ2Rez will now wait 1/10 of a second before clicking rez.
- Added /rez delay #### parameter where #### is milliseconds.
  default is 100 milliseconds.
- Added a /mqchat reset command. It resets mq2 window location in case it got moved off screen.
- All instances of the CSidlScreenWnd constructor has been fixed to use CXStr& instad of CXStr* (because it should be)
  Change plugins accordingly.
  Examples:
	change:
	CEQBCWnd(CXStr* Template) : CCustomWnd(Template)
	to 
	CEQBCWnd(CXStr& Template) : CCustomWnd(Template)

	change:
	class CXStr ChatWnd("ChatWindow");
	BCWnd = new CEQBCWnd(&ChatWnd);
	to
	BCWnd = new CEQBCWnd(CXStr("ChatWindow"));

May 15 2019 by Brainiac
- MQUI XML files may now be loaded from the MQ2 directory. Place them in
  the MQ2 directory under uifiles/default, or the name of your ui like you
  would in the EQ directory. When loading ui files, MQ2 will check for ui files
  in the MQ2 dir before checking in the EQ dir as it did before.

  To be clear, this is the search order for ui files:
  * <MQDir>\uifiles\<skin>
  * <MQDir>\uifiles\default
  * <EQDir>\uifiles\<skin>
  * <EQDir>\uifiles\default

  This lets you store your MQ2 ui files in your MQ2 directory, as well as giving
  you the option of storing your MQ2-specific custom uis outside the EQ folder.

- added c++ function: bool IsXMLFilePresent(const char*) for plugin authors to easily
  check if an XML file is available to be loaded. This will check all four locations where
  a ui file might be stored.
- added command: /reloadui
  It works just like "/loadskin <skinname> 1" but with less typing

May 15 2019 by EqMule
- Updated for LIVE

May 09 2019 by Brainiac & EqMule
- Multiple stuff
- Fixed a bug in CListWnd::AddString
  ALL instances of: AddString(&CXStr
  should be changed to: AddString(CXStr

May 07 2019 by EqMule
- Updated for TEST
- Events are not caught for system messages anymore.

May 02 2019 by Brainiac
- Fixed the CXWnd__IsActive_x offset

May 01 2019 by EqMule
- Fixed a crash in /caption anon on
- Fixed a crash in /unload

Apr 30 2019 by EqMule
- TBL plavceholder info will again display correctly on the targetwindow if you use mq2targetinfo.
- Changed a bunch of stuff, plugin authors you have until next patch to update your plugins.
- If you ned help mail the plugin to me and ill send it back fixed: eqmule@hotmail.com
  ALL global plugins in builder have been updated by me already, look at them for examples.
  No more direct access to the window struct members in prep for moving to classes.
  From now on call functions to get/put data out/in:
  Example: too many to list see CSW struct.
  I'll list 4 examples:  previously pWnd->XMLIndex now: pWnd->GetXMLIndex()
                         previously pWnd->dShow==false now: pWnd->IsVisible()==false
						 previously pWnd->dShow = true now: pWnd->SetVisible(true)
						 previously SetCXStr(&pWnd->WindowText,"blah"); now pWnd->CSetWindowText("blah");
						 previously GetCXStr(pWnd->WindowText,szOut); now GetCXStr(pWnd->CGetWindowText(),szOut);
- Added .NoExpendReagentID to the Spell tlo.
  Usage: /echo ${Spell[Burst of Fire].NoExpendReagentID[x]} where x can be 1-4
  This returns the ID of the needed Reagent you have to have in your inventory but will not be spent.

Apr 22 2019 by EqMule
- Updated for TEST & LIVE
- Find Item Window is now displaying merchant sell prices.
- Added sorting to find item window for the sell value column
- Added sorting to find location window for the distance column
- Fixed .NewStacks
- Fixed a autologin bug

Apr 20 2019 by EqMule
- Added Colors to Quest items and Tradeskill items in the FindItem Window list.
  Yellow=Quest
  Magenta=Tradeskill
  (No this is not configurable, I might add an option later.)

- Added a Value(Price) column to the FindItem window.
- Enjoy marking items for sale in the FindItem Window.
  Usage: mark some items while you have a merchant open, then click the Sell Marked button.
  Still Todo: display real merchant price instead of item value.
  Maybe add sort functionallity to Price column.

Apr 19 2019 by EqMule
- Updated for TEST
- Updated for LIVE

Apr 18 2019 by EqMule
- Added ${EverQuest.ValidLoc}
  Usage: /echo ${EverQuest.ValidLoc[123 456 789]}
  it returns true or false if the X Y Z location in the world is a valid player location.
  in other words: can I go to this loc or is it inside a wall or a mountain or a tree or whatever invalid location?(those locs will return false obviously)

- Fixed the ZoneGuideManagerClient class.

Apr 17 2019 by EqMule
- Updated for LIVE
- Previous updates see Apr 12 2019 by EqMule entry below.
- Added more anonymizing to chat when using /caption anon - chatwiththisname
- Moved advloot checkboxes dynamically to not cover fuse item button on mq2itemdisplay window  - chatwiththisname
- 
Apr 14 2019 by brainiac
- Fix crash/freeze from starting macro from within another macro

Apr 12 2019 by EqMule
- Updated for TEST
- Updated for LIVE
- Uncheck and Recheck the following Builder Plugins because they have been updated:
  MQ2Cast
  MQ2Radar

- In preperation for next weeks live patch the following offsets has been removed:
	pinstAggroInfo_x
	pinstAuraMgr_x
	pinstEQItemList_x
	pinstMercAltAbilities_x
	pinstRealEstateItems_x
	pinstCTargetManager_x
	pinstCTextOverlay_x
	pinstEQObjectList_x
- All of the above offsets are no longer static in the client so I have replaced them with 
  calls to the proper Instance/Get functions instead.

- Plugin authors, you need to make a few changes to access some SPAWNINFO members from now on:
  (don't change any other struct members if they happen to have the same name!)
  All instances of ->SpellCooldownETA needs to be changed to ->GetSpellCooldownETA()
  All instances of ->spawneqc_info needs to be changed to ->GetCharacter()
  All instances of ->ManaMax needs to be changed to ->GetMaxMana()
  All instances of ->ManaCurrent needs to be changed to ->GetCurrentMana()
  All instances of ->EnduranceMax needs to be changed to ->GetMaxEndurance()
  All instances of ->EnduranceCurrent needs to be changed to ->GetCurrentEndurance()
  All instances of ->Zone needs to be changed to ->GetZoneID()


Mar 29 2019 by EqMule
- Fixed MQ2Autologin
- Added .SelectedItem to the Merchant TLO
  it returns the currently selected item in the merchant window as a pItemType

Mar 26 2019 by EqMule
- Fixed multiple problems in arrayclass.h due to client changes.

Mar 23 2019 by EqMule
- GetAACastingTimeModifier has been renamed to GetCastingTimeModifier (because it is)
- GetCastingTimeModifier and GetFocusRangeModifier has been changed to deal with a ctd.
- All plugin that call these needs to be changed, search for them and see how I fixed it in core.
- No plugins should call the EQ_Character1::GetCastingTimeModifier and EQ_Character1::GetFocusRangeModifier directly
- ALWAYS call the wrappers in mq2inlines. (well you can continue calling them directly but good luck with the crashes)
- Fixed crashes in the spell tlo members .MyCastTime and .MyRange
- CONTENTS member ItemType has been renamed to RefCount
- This member should never ever be set or changed manually in plugins,
- it's an internal eqgame counter, if you mess with it you are going to screw up checksums and get disconnected.
- MQ2Cast needs to be updated look at the builder global version if you need help.
- 
Mar 18 2019 by EqMule
- Fixed a bug when doing /ctrl /itemnotify and OpenContainer needed to be called
- Added Make Me Leader to mq2targetinfo rightclick on group member menu

Mar 16 2019 by EqMule
- Updated for TEST

Mar 14 2019 by EqMule
- Fixed a crash when doing: /echo ${Window[MarketplaceWnd].Child[MKPW_AvailableFundsUpper].Text}
- Fixed ${Math.Abs} - SwiftyMUSE

Mar 13 2019 by EqMule
- Updated for LIVE

Mar 06 2019 by EqMule
- Updated for TEST
- All instances of CWChatInput has been changed to CW_ChatInput due to a client change.
- All instances of CWChatOutput has been changed to CW_ChatOutput due to a client change.
- If your plugin uses these, YOU need to change these as well.
- Plugins affected: mq2eqbc, mq2irc, mq2moveutils

Feb 22 2019 by EqMule
- Updated for TEST

Feb 21 2019 #2 by EqMule
- Fixed /ranged crash, yes really this time. It got another parameter, don't know what it is.

Feb 21 2019 by EqMule
- Fixed the spawninfo struct this means most weird crashes in mq2main and all kinds of plugins like mq2heals,mq2posse etc are now fixed.
- I will realign address comments for it later in practice it works.

Feb 20 2019 by EqMule
- Updated for LIVE

Feb 15 2019 by EqMule
- Updated for TEST

Feb 14 2019 by SwiftyMUSE
- MQ2ItemDisplay fixes:
  Crash bug for ${DisplayItem} and fix to handle display of links via raid/group/tells.

Feb 13 2019 by EqMule
- Updated for TEST

Feb 09 2019 by EqMule
- Added .StacksTarget to the Spell TLO it returns true or false
  Usage: /echo ${Spell[Shield of the Void].StacksTarget}
- Fixed IsSTackBlocked once and for all. Yes really this time.

Feb 08 2019 by EqMule
- Added /convertitem to mq2itemdisplay
- Example: /convertitem Wishing Lamp:

Feb 05 2019 by EqMule
- Fixed a bug in /unload
- Misc Stability fixes all over the place.
- Fixed a nasty stack overflow crash in mq2log

Jan 21 2019 by SwiftyMUSE
- Resync of code with ROF2EMU

Jan 21 2019 by EqMule
- Dump file directory will now be created if it doesn't exist
  this fixes the bug where you see a crash dialog that just say "Dump saved to"
- Added a lock on tlo member and tlo method access so the maps used there wont get corrupted by plugin that use threads to query or change members.
- The above change should fix a couple crashes i have gotten dumps for.
- I spent most of the day looking at crash dumps, I made several adjustments and fixes.
  Thanks to everyone that sent in dumps, please don't send anymore until u have updated.

Jan 19 2019 by EqMule
- Fixed a crash in Find Item Window when character had more than 1000 items.
- Fixed a bug where turning off Find Item Window Checkboxes setting would not save properly.

Jan 18 2019 by EqMule
- Fixed a crash when switching character.
- Added some code to catch crashes.
  I guess I'll find out if it works once people report if they see the dialog.
  It will save dump files as well. send those to eqmule@hotmail.com


Jan 16 2019 by EqMule
-Updated for LIVE

Jan 15 2019 by EqMule
- Added a fixed up version of Inventory.mac - wired420

Jan 15 2019 by SwiftyMUSE
- Resync of code with ROF2EMU

Jan 14 2019 by EqMule
- Added a new column to the Find Item Window which will let you mark items for delete or add them to never loot filter.
  Usage: mark some items by checking the ckecboxes, then click the Never Loot button to set their never loot advloot filter.
  Usage: mark some items by checking the ckecboxes, then click the Destroy Items button to delete them.

- It goes without saying, that if you have no idea what you are doing or if you are a complete imbecile, this feature might
  be too dangerous for you to have enabled, in which case you can disable it by right clicking the Destroy Item or the Never Loot button
  and then toggle the "Cool Checkbox Feature" on the menu that pops up. Default is ON.

Jan 09 2019 by EqMule
-Updated for TEST

Jan 07 2019 by SwiftyMUSE
- Added .Dotted to ${Me} and ${Target}
- Added .MaxMeleeTo to ${Target}
- Updated .Foreground in EverQuest TLO
  While not technically required... (although it improves performance)
  Anyone using GetForegroundWindow() call should change their code
  to use the new exported gbInForeground instead of making calls in the plugin pulse function.
  These Global builder plugins are updated so as not unnecessarily using cpu in pulse:
  MQ2AdvPath, MQ2CpuLoad, MQ2FPS and MQ2Radar
  These Personal plugins should be updated, including, but not limited to:
  MQ2Clip, MQ2Focus, MQ2Nav, MQ2SoD, MQ2Task, MQ2ViewPort, MQ2WinPath

Jan 03 2019 by EqMule
- ${Me.Ability[#|X]} now return the real ID/Name of a Ability...
  Example /echo ${Me.Ability[Hide]}
  returns: 29
  /echo ${Me.Ability[29]}
  returns: Hide

  Before this change doing ${Me.Ability[Hide]} would return whatever number 1-6 you had assigned to Hide in Abilities.
  NOW it returns 29, which is the actual ability ID for Hide.

- /doability # now takes REAL ability IDs as well as the "fake ones", which are 1-6
  This means you can do /doability 29 and it will activate the Hide ability since it's REAL ID is 29...
  You can also still do /doability 1 and if you have Hide assigned as 1 in your abilities tab on the actions window, it will activate it.
  This is kinda stupid though, so I recommend just doing /doability Hide instead, and 
  don't worry about where its assigned or not assigned at all...
- Added Run To, to the groupwindow rightclick menu, it will run you over to the group member you clicked.

Dec 19 2018 by SwiftyMUSE
- Added .Feared, .Silenced, .Invulnerable to ${Me} and ${Target}
- Added new .Named checking algorithm. You can use the new version by adding UseNewNamedTest=1 to the
  [MacroQuest] section in macroquest.ini
- Updated new SPA effects and corrected display of some others
- Added .Foreground to EverQuest TLO
- Added .BaseName to Spell TLO (spell name w/o any Rk. XXX crap)
- Fixed Me.GemTimer to clamp return to 0 after spell is ready to cast 

Dec 18 2018 by eqmule
- Updated for LIVE
- Updated for TEST
- Added Quest items to the autobank button rightclick menu
- Added an option Autoinventory from bank back to inventory (reverse AutoBank basically).
- /loadskin and /camp out/in out will not break this new feature anymore.

Dec 17 2018 by eqmule
- New Fature: AutoBank Filter : idea cred Kaen01
- Basically rightclick the autobank button to set options for items you like to autobank
  Click AutoBank Button WITHOUT anything on the cursor.
  If you have something on cursor AutoBank will just work like it always have and autobank the item
  BUT if your cursor is empty it will autobank:
  Collectibles if you have that option set. (off by default)
  Tradeskill Items if you have that option set. (off by default)
  Right now those are the two types of items it works for, I'm not against other item types so if anyone has some clever ideas let me know.
  Known Issue: need to add reloadui support so it's a little bit beta still, but anyway, I'll fix that later.

Dec 13 2018 by eqmule
- Updated for LIVE
- Updated the LOOTITEM struct
  This fix will break plugins that use that struct.
  Search the source for ->LootDetails.m_array to see how it should be fixed.
- NotifyOnServerUP in mq2autologin.ini can be left at =1 or =2 now, it will only trigger on server is up after server is detected as LOCKED or DOWN when the plugin first checks it.

Dec 11 2018 by eqmule TBL Launch
- Updated for LIVE
- Placeholders in mq2targetinfo for the PH button on the target window has been updated for TBL
- Made mq2autologin not try to join a locked/down server.
- Added NotifyOnServerUP to the mq2autologin inifile in the [Settings] section.
  If you set it to NotifyOnServerUP=1 it will BEEEEEEEEEEEEEEEP when server is up.
  If you set it to NotifyOnServerUP=2 it will also email you if you have the mq2gmail plugin loaded and correctly configured.
  You can try /gmail "hi there" "test" in game, if u get that, u will also get the autologin notification.
  Or just leave the setting as NotifyOnServerUP=0 and it wont bother u at all.
  I find it useful to enable it on patchday's when servers are LOCKED/DOWN
  Under normal circumstances, it should be set to 0, unless u really like 10 seconds of BEEEEEEPING everytime u login...

Dec 10 2018 by eqmule
- Updated for TEST
- Updated mq2auth.exe so it can be run silently now using the /silent switch - idea cred: brainiac
- Right Clicking the AutoBank button brings up a menu now in TEST and EQBETA builds.
  This menu is NOT useful atm, it's work in progress, just ignore it.

Dec 10 2018 by eqmule & SwiftyMUSE
- Updated for BETA

Dec 09 2018 by eqmule
- Updated for BETA

Dec 08 2018 by eqmule
- Updated for BETA

Dec 07 2018 by eqmule
- Updated for BETA
- The following feature has been on my todo list forever and was brought to life by @Knightly, all hail Knightly!
  Thanks for your support.
- Added the ability to interact with menus - cred : Knightly
  Example: /notify "open the door to the lobby" menuselect
  It will search the currently open menu for the words "open the door" and click that menu item if it finds it.
  the search is case insensitive and sub strings are fine
  thus you could just do /notify "open the" menuselect and it would still find and click that item
- 
- Added a new TLO: MQ2MenuType it inherits the Window TLO.
  It has 1 method:
	.Select : It will select a menu item (click it)
	usage: /invoke ${Menu.Select[open the door]}
	Output: none, it just clicks that entry if it finds it.

  It has 6 members:
	.Address : pIntType it returns the address of the currently open menu.
	.NumVisibleMenus : pIntType it returns number of currently visible menus. Ordinarily this is going to be 1 if a menu is showing and 0 if not
	.CurrMenu : pIntType it returns the index for the currently visible menu. Ordinarily this will be 0 if a menu is open and -1 if not
	.Name : pStringType it returns the name of the menu or the first items name.
	.NumItems = : pIntType it returns number of items in the currently open menu.
	.Items : pStringType it returns the Itemname specified by Index
--  Usage Examples:
--	/echo ${Menu.Name}
	Output: Shabby Lobby Door
	/echo ${Menu.Open} (it inherits Window TLO, remember?)
	Output: TRUE
	/echo ${Menu.NumItems}
	Output: 4
	/echo ${Menu.Items[2]}
	Output: Adjust Placement
- Added some door defines.

Dec 06 2018 by eqmule
- Updated to include all faction names - SwiftyMUSE
- Updated for BETA
- I made some changes to /itemtarget /items and the ground tlo
  I don't want to say to much about it really there isn't much to say
  from a users perspective everything works like before.
  Basically the only difference should be that /items now display grounditems in guild halls as well.
  if ${Ground} or /itemtarget or whatever does not work as before let me know.
- Added /click right item
  this is mostly useful for like grounditems like shabby lobby door and so on that pops up
  a menu when you rightclick them.
- Work in progress -> adding a method to click menu items in the currently open menu.

Dec 05 2018 by eqmule & SwiftyMUSE
- Updated for BETA

Dec 04 2018 by eqmule & SwiftyMUSE
- Updated for BETA
- Updated for TEST

Dec 03 2018 by eqmule
- Updated for BETA
- Added /groupinfo mimicme on|off - it will do what the button does but from commandline
- Added /groupinfo followme on|off - it will do what the button does but from commandline
- Added /groupinfo cometome - it will do what the button does but from commandline
- This means if you dont want those buttons on the group window, just rightclick
  a group member and hide them, then create your own hotbuttons
  and put them wherever you like to get the same functionallity.
- Fixed a bug in mq2targetinfo that would change the alpha of the targetwindow/groupwindow/exttargetwindow
  it had no business doing that, sorry.

Dec 02 2018 by eqmule
- Updated for BETA

Dec 01 2018 by eqmule
- Updated for BETA

Nov 30 2018 by eqmule
- Updated for BETA

Nov 29 2018 by eqmule
- Updated for BETA
- Fixed Mimic Me to do /keypress HAIL instead of /say Hail, blah
  This should make hail repeating work for all NPCs.

Nov 29 2018 by eqmule
- Updated for BETA
- Fixed a issue with MQ2Hud stuttering. - SwiftyMUSE

Nov 28 2018 by eqmule
- Updated for BETA
- Updated for LIVE
- Added "Follow Me" to the rightclick menu for the groupwindow. - idea cred: sl968
  For this to work yuo need to have mq2eqbc loaded as well as mq2advpath and mq2targetinfo.
  It will issue a /bct <toon> //afollow command to the toon you rightclicked on.
- MQ2HUD Tweaks - dannuic

Nov 27 2018 by eqmule
- Updated for BETA

Nov 26 2018 by eqmule
- Let's pretend yesterday's release didnt happen, mq2targetinfo was bugged, so we try again:
- Updated for BETA, LIVE and TEST
- Added /groupinfo reset if you have ANY problem at all with default UI, just run this command it will reset to WORKING ini.
  Old settings will be saved in MQ2TargetInfo.bak

- Added /groupinfo reload
  you can use it to reload the ini when you make changes to button locations etc.
- I made a lot of changes to how mq2targetinfo adds itself to the UI
  Basically if you have a custom UI it will now save button locations and so on in it's own section of the ini file.
  Example ini:
  [code]
	[Default]
	UsePerCharSettings=0
	ShowComeToMeButton=1
	ShowFollowMeButton=1
	ShowMimicMeButton=1
	ShowHotButtons=1
	ShowDistance=1
	ShowExtDistance=1
	ComeToMeText=Come To Me
	ComeToMeCommand=/bcg //nav id ${Me.ID}
	ComeToMeToolTip=/bcg //nav id ${Me.ID}
	FollowMeText=Follow Me
	FollowMeCommand=/bcg //afollow spawn ${Me.ID}
	FollowMeeToolTip=/bcg //afollow spawn ${Me.ID}

	[UI_default]
	DynamicUI=1
	GroupDistanceLoc=0,-20,70,0
	ComeToMeLoc=61,27,6,46
	FollowMeLoc=61,27,48,88
	MimicMeLoc=61,27,90,130
	HotButton0Loc=97,64,6,46
	HotButton1Loc=97,64,49,89
	HotButton2Loc=97,64,92,132
	TargetInfoAnchoredToRight=0
	TargetInfoLoc=34,48,0,40
	TargetDistanceLoc=34,48,90,0
	ExtDistanceLoc=0,-20,70,0

	[UI_zliz]
	DynamicUI=0
	GroupDistanceLoc=0,-8,60,0
	ComeToMeLoc=41,1,1,41
	FollowMeLoc=41,1,42,82
	MimicMeLoc=41,1,83,123
	HotButton0Loc=76,36,2,42
	HotButton1Loc=76,36,44,84
	HotButton2Loc=76,36,86,126
	TargetInfoAnchoredToRight=0
	TargetInfoLoc=1,12,90,0
	TargetDistanceLoc=14,26,140,180
	ExtDistanceLoc=0,-20,70,0

	[UI_Melee]
	DynamicUI=0
	GroupDistanceLoc=-3,-15,120,-70
	ComeToMeLoc=36,2,4,44
	FollowMeLoc=36,2,46,86
	MimicMeLoc=36,2,88,128
	HotButton0Loc=36,0,134,174
	HotButton1Loc=36,0,174,214
	HotButton2Loc=36,0,214,254
	TargetInfoAnchoredToRight=0
	TargetInfoLoc=1,13,90,60
	TargetDistanceLoc=50,62,140,0
	ExtDistanceLoc=0,-20,90,0

	[UI_sars]
	DynamicUI=0
	GroupDistanceOffset=0
	UseGroupLayoutBox=1
	GroupDistanceLoc=0,12,70,-5
	GroupDistanceElementPrefix=GW_Gauge
	ComeToMeLoc=33,3,0,30
	FollowMeLoc=33,3,32,62
	MimicMeLoc=33,3,64,94
	HotButton0Loc=69,39,2,32
	HotButton1Loc=69,39,34,64
	HotButton2Loc=69,39,66,96
	TargetInfoAnchoredToRight=0
	TargetInfoLoc=74,86,140,0
	TargetDistanceLoc=112,124,0,230
	UseExtLayoutBox=1
	ExtDistanceLoc=0,12,30,-20
  [/code]



Nov 24 2018 by eqmule
- Updated for BETA
- Custom UI Extended Target Window crash fixed in MQ2TargetInfo.

Nov 23 2018 by eqmule
- Updated for BETA
- Added MORE support for custom UI's to MQ2targetInfo
  I don't know much about custom UI' as I have only used a couple of them
  and my experience with them, well i was not impressed, the reason is that they are outdated
  they dont show aggro percentages, they use hardcoded sizes and thus cant be resized, cant be moved, has no title, etc.
  Honestly, its a mess, if u have a good UI that has all the same controls as default, you are lucky.
  Now, to workaround these limitations, I have made some changes to MQ2targetInfo:
  First of all if your group window is not resizable, ill change it so it is.
  Second if it doesnt have proper .TopOffset I'll use Location.top instead and so on.
  Suffice to say, I have done my best to make this work for everyone.
  If this still isnt enough, you are going to have to actually edit either mq2targetinfo.ini
  and set the button locations there, or edit your UI's XML files.
  Well, or just unload mq2targetinfo...

  Bottomline is, the code I added now, should at a minimum not crash your custom UI
  and there is a good chance it actually works for it as well, although u might have to resize the window
  in order to see all buttons and distance etc.

Nov 22 2018 by eqmule thanksgiving edition.
- Updated for BETA
- I now disable MQ2TargetInfo for incompatible UI's
  I plan on fixing it but I dont have time today.

- Started the Task TLO overhaul, we are going to be able to access these things without having to have the window open.
  This also means we can now add some new members to it, like the type of task, reward, npc to turn into etc.
  More to come.

Nov 21 2018 by eqmule
- Updated for BETA
- Moved Mimic Me default position to where old hotbutton was.
- Moved old hotbutton to old Mimic Me default position to be more consistent because:
- I Added 2 more hotbuttons to the group window. There was unused space next to hotbutton 1... - idea cred: sl968
  Rightclick groupwindow and check or uncheck the menu for it to hide/show them.
  or use /groupinfo help
  There is no way to selectivly show only one or two, the show is either for all three or none.
  Because, well it makes the most sense and I dont want to clutter up the menu with 3 settings for it.

Nov 20 2018 by eqmule
- Updated for BETA

Nov 19 2018 by eqmule
- Updated for TEST

Nov 19 2018 by eqmule
- Updated for BETA
- Added distance for targets on the Extended Target Window
  You can control the feature by: /groupinfo show/hide extdistance
  Because distance label needs a few pixels to display, u *might* need to make the window a bit wider,
  it depends how many letters are in the mobs name that u fight.
- MQ2TargetInfo.ini now lets you customize what commands, texts and tooltips are executed/displayed for the Follow Me and Come To Me buttons
  Default entries are:
  [code]
	ComeToMeText=Come To Me
	ComeToMeCommand=/bcg //nav id ${Me.ID}
	ComeToMeToolTip=/bcg //nav id ${Me.ID}
	FollowMeText=Follow Me
	FollowMeCommand=/bcg //afollow spawn ${Me.ID}
	FollowMeeToolTip=/bcg //afollow spawn ${Me.ID}
  [/code]

Nov 18 2018 by eqmule
- Updated for BETA

Nov 17 2018 by eqmule
- Updated for BETA

Nov 16 2018 by eqmule
- Updated for BETA

Nov 15 2018 by eqmule
- Updated for BETA

Nov 14 2018 by eqmule
- Updated for LIVE
- Updated for BETA

Nov 13 2018 by SwiftyMUSE
- Updated ROF2EMU build to bring to current.
- Fixed a GetItemLinkHash crash on BETA.

Nov 13 2018 by eqmule
- Updated for BETA
- Updated InvSlotMgr for TEST and BETA it has 0x900 slots now.
  This means /itemnotify in <pack#> <slot#> rightmouseup will work again.
- FirstFreeSlot now returns -1 if no freeslot is found.
- FirstFreeSlot returns 0-whatever, it does NOT start counting on 1 anymore.
  This means: if it return 0 the FIRST slot is in fact empty.
  if it returns 1 the SECOND slot is in fact empty, etc.
  We do this because in real life, from a coders perpective, arrays start at 0. not 1.
  and, thats just the way it should be.

Nov 12 2018 by eqmule
- Updated for BETA
- Added LoreEquipped, Luck, MinLuck and MaxLuck to the itemtype tlo for BETA
- Added some more fixes to /caption anon for spawn corpses etc - chatwiththisname

Nov 11 2018 by eqmule
- Updated for BETA

Nov 10 2018 by eqmule
- Updated for BETA

Nov 09 2018 by eqmule
- Fixed a /endmacro crash in the LIVE build
- Fixed a /endmacro crash in the TEST build
- Fixed a /endmacro crash in the BETA build
- Fixed ITEMINFO wrong size crash for TEST
- Updated for BETA

Nov 08 2018 by eqmule
- MQ2TargetInfo has been updated.
  You can now set UsePerCharSettings=1 if you want that in MQ2TargetInfo.ini.
  0 is default and means it reads settings from the [Default] section.
  I realized that having per char settings is cumbersome if you have A LOT of chars.
  The buttons on the groupwindow will only show when you are in a group now.
  Except the Hotbutton which will always show unless you change its show/hide setting. see /groupinfo help for more info.
- Added a tooltip for /groupinfo help on the main groupwindow.
- Fixed a bug in mq2targetinfo which would cause the groupwindow hotbutton "hitbox" to overlap the disband button making it difficult to click.
- Added CheckMenu items for showing/hiding the groupinfo buttons to the rightclick group window menu.

- Updated for TEST
- Updated for BETA
- GLOBAL gMacroPause is gone now. Use gMacroBlock->Paused instead.

Nov 07 2018 by eqmule
- Updated for BETA
- FirstFreeSlot now returns 0 if there is no free slot found

Nov 06 2018 by eqmule & SwiftyMUSE
- Updated for BETA
- Brought ROF2 client in sync with current source.

Nov 05 2018 by eqmule & SwiftyMUSE
- Updated for BETA
- Even More Stuff

Nov 04 2018 by eqmule & SwiftyMUSE
- Updated for BETA
- More Stuff

Nov 03 2018 by eqmule & SwiftyMUSE
- Updated for BETA
- Stuff

Nov 02 2018 by SwiftyMUSE
- Updated Charinfo structure to add luck.
- Updated MQ2TargetInfo to remove compile warnings.

Nov 02 2018 by eqmule
- Updated for BETA

Nov 01 2018 by eqmule
- Updated for BETA

Oct 29 2018 by eqmule
- Updated for TEST (and LIVE)
- If you have been crashing I strongly recommend you update to this version.
- Fixed IsStackBlocked call that would corrupt the stack and lead to crashes in mq2melee etc - thanks htw for help looking into it.
- Fixed multiple problems with CHARINFO and CHARINFO2 that would cause a rare crash.

Oct 27 2018 by eqmule
- Added ${EverQuest.HWND} returns the everquest window handle.
- Added /foreground command it puts eq in the foreground.
  Usage: /bct <toon> //foreground
- Added a "Switch to..." menu item to the groupwindow rightclick menu, It will switch over to another group member easily.
  This menu only exist if mq2targetinfo is loaded.
- Fixed a ${Merchant.SelectItem[=blah blah]} bug, it should work properly now.

Oct 26 2018 by SwiftyMUSE
- Added debugging logic for stacks.
    Add BuffStackTestDebug=1 to your [MacroQuest] section of MacroQuest.ini
    to allow debugging information to be put in the log file for review by
    the developers.

Oct 26 2018 by eqmule
- Previously Added: ${Merchant.ItemsReceived} its true if the merchants itemlist has been filled in.

- Fixed a issue that prevented isboxer from launching eqgame processes without them crashing.
- Added a /groupinfo command to hide/show buttons on the group window
  Usage: /groupinfo help
- GroupWindow Button locations are now configurable in mq2targetinfo.ini
  plugin unload and reload is needed if you change button locations.

Oct 25 2018 by eqmule && Chatwiththisname
- Updated for LIVE
- Fixed /selectitem it selects items in your inventory when you have a merchant open.
  Usage: /selectitem "bottle of" will select a "bottle of vinegar" you can also do "=bottle of vinegar" to match EXACT name (its not case sensitive though)
- Added Methods to the Merchant TLO: .SelectItem .Buy .Sell .OpenWindow
  Usage:
  /invoke ${Merchant.OpenWindow} //will open the merchant closest to you, or if you have a merchant target, that mrchant
  /invoke ${Merchant.SelectItem[bottle of]} for a partial match OR ${Merchant.SelectItem[=bottle of vinegar]} if you need the name to match EXACTLY (its not case sensitive though)
  /invoke ${Merchant.Buy[100]} //buys 100 of whatever is selected with Merchant.SelectItem[blah]
  /invoke ${Merchant.Sell[100]} //sells 100 of whatever is selected with /selectitem
- Fixed /caption anon - Chatwiththisname
- Added Anon Caption string to ini file - Chatwiththisname
- Added command /caption reload to reread the ini on the fly - Chatwiththisname

Oct 23 2018 by eqmule
- MQ2TargetInfo is now part of Core.

Oct 22 2018 by eqmule
- Added some more good stuff to mq2targetinfo
- Fixed clicking playername in group window.
- Added a button called "Mimic Me" to the group window.
	If you have mq2eqbc loaded the button will work and will
	make your whole group do what you do, if u target someone they will all target your target.
	if you say something they will all repeat what you say.
	This is great for tasks etc.
- Added "Pick up nearest ground item" to the rightclick menu in the groupwindow.
    This makes the character you selected the menu on pick up the nearest grounditem to him/her
- Added "Click nearest door" to the rightclick menu in the groupwindow.
   This makes the character you selected the menu on click the nearest door to him/her
- Added a real Hotbutton to the groupwindow, you can now put a custom hotbutton there that does whatever you like.

Oct 19 2018 by eqmule
- mq2melee.cpp has been updated for Me->AAList changes in the builder go click the file and diff it to the old one to see what changed.
- MQ2TargetInfo has been updated.
- Added Distance to group members next to their name in the groupwindow.
- Added a button to the group window called "Come to Me"
	If you have mq2eqbc, mq2nav and mq2advpath and a proper mq2nav mesh loaded
	the button will work and will make your whole group come running to you.

- Added a button called "Follow Me" to the group window.
	If you have mq2eqbc and mq2advpath loaded the button will work and will
	make your whole group follow you around.

- Added a new character TLO member: Bandolier it has 4 members: Index,Active,Name,Item
    it has one method: Activate
	Usage: (assuming you have a bandoiler saved as "1HB")
	| check if its active:
	[code]
	/if (!${Me.Bandolier[${Bandolier[1HB].Active}) {
		/echo [${Time}] player want us to activate Bandolier: 1HB.
		/invoke ${Me.Bandolier[1HB].Activate}
	}
	/echo I have a ${Me.Bandolier[1HB].Item[1].Name} in my primary bandoilier slot
	Output: I have a Snowreaver in my primary bandoilier slot
	Item returns a bandolieritemtype which has 4 members: Index,ID,IconID,Name
	[/code]

- Made some adjustments to the ${Ground} TLO and added .First and .Last members to it.
	  /echo ${Ground} will now return the FIRST item in the list if you DO NOT done a /itemtarget
	  in which case it will return that item.
	  Prior to this change ${Ground} would just return NULL if an /itemtarget had not been performed.
	- Fixed a bug in ${Ground} which prevented it from be used as a type
	  Example:
	  [code]
	  |a Macro to show how to use /vardata
	|/vardata does NOT work like /varset
	|Opening and closing the dataportion must NOT use ${}

	#turbo 120

	Sub Main
		/declare MyGroundItem		ground		local
		/declare Count			int		local
	
		|Start by just setting it to the first entry found in the grounditems list:
		| NOTE that I DO NOT USE ${Ground.First}, but Ground.First that's just how /vardata works, so accept it.
		/vardata MyGroundItem Ground.First

		/for Count 1 to ${GroundItemCount}
			/echo \a-w${Count}. \awID: \at${MyGroundItem.ID} \awDist: \ay${MyGroundItem.Distance} \ag${MyGroundItem.DisplayName}
        		|move to next:
			/if (${Bool[${MyGroundItem.Next}]}) {
				/vardata MyGroundItem MyGroundItem.Next
			} else {
				/break
			}
		/next Count
	/return
	[/code]

- Fixed AAPointsAssigned in the CHARINFO2 struct, it is actually an array.
	Prior to this fix we used it like this: pChar2->AAPointsAssigned;
	Now we use it like this: pChar2->AAPointsAssigned[0];
	It contains points spent in each aa category. the first one is just total...

Oct 10 2018 by eqmule
- Updated for TEST

Oct 01 2018 by eqmule
- Fixed a bug in SpawnMatchesSearch which *could* cause group members to look like they gone offline.
- Added click to nav on map - dannuic
  Usage: hold down alt + leftclick anywhere on the mapwindow and nav will run u there if its loaded.

Sep 25 2018 by eqmule
- Updated for TEST

Sep 21 2018 by eqmule
- Updated for LIVE

Sep 19 2018 by eqmule
- Updated for LIVE
- Fixed a bug with /advloot giveto
- Cleaned up and completed the _EQCASTSPELLGEM struct, we have been using it wrong for years it seems.
- TimeStamp in the EQCASTSPELLGEM has been removed and is now (correctly) part of the CBUTTONWND struct
  it is named (correctly) CoolDownBeginTime there.

- RecastTime in the EQCASTSPELLGEM has been removed and is now (correctly) part of the CBUTTONWND struct
  it is named (correctly) CoolDownDuration there.

- The 2 above changes means plugins might need to be edited if they used the old struct.
  Here is an example of how to fix this:
  change:
  return g->TimeStamp + g->RecastTime - EQGetTime();
  to:
  return g->Wnd.CoolDownBeginTime + g->Wnd.CoolDownDuration - EQGetTime();
- Started on adding support for the UF emu client, no eta for when it will build.
- The EMU #define has been renamed to ROF2EMU
- Added a #define for UFEMU
  This means if you plugin was previously using #if defined(EMU) !defined or #ifdef or #ifndef
  it need to to properly add in defined(ROF2EMU) && defined(UFEMU) or the !defined in the proper places

Sep 12 2018 by SwiftyMUSE
- Added Banker for searches.
- Fixed .NumGems so it will give up to 14 based on your spellbar.

Sep 12 2018 by eqmule
- Updated for TEST
- Fixed /removeaug
- Added support for RewardSelectionWnd through the /notify command -Plure
- Added .StacksWithDiscs to the Spell TLO its a true/false
  I don't know if it works, its untested.
- Advloot giveto now works for raid members as well.
- Added .Collected and .CollectedRecieved and .Scribed and .ScribedRecieved to the DisplayItem TLO they return true/false

Sep 05 2018 by eqmule
- Updated for TEST

Aug 18 2018 by eqmule
- Updated for TEST

Aug 15 2018 by eqmule
- Updated for LIVE

Aug 09 2018 by eqmule
- Updated for TEST

Jul 20 2018 by eqmule
- Updated for TEST
- MQ2 contains NO active hacks, you can't warp and you can't "gank" etc.
  Now, I bring this up since there is a thread on the official forum right now about cheat programs.
  They are NOT talking about mq2, but another program which I will NOT link to or promote in any way, in fact we condemn it.

Jul 19 2018 by eqmule
- Updated for LIVE

Jul 14 2018 by eqmule
- Updated for TEST

Jul 11 2018 by eqmule
- Updated for TEST

Jul 09 2018 by eqmule
- Added support for MQ2Radar

Jun 22 2018 by eqmule
- Updated for TEST
- Fixed a bug in mq2itemdisplay that would spam uierrors.txt

Jun 20 2018 by eqmule
- Updated for LIVE
- They removed the heroic resists from iteminfo, so I did to.
  I dont think anyone was using those anyway.

Jun 19 2018 by eqmule
- Updated for TEST

Jun 18 2018 by eqmule
- Added support for emu mq2labels plugin

Jun 16 2018 by eqmule
- Fixed a bug for TEST

Jun 13 2018 by eqmule
- Fixed ITEMINFO for TEST
- Fixed invslot charm

Jun 13 2018 by eqmule
- Updated for TEST

Jun 08 2018 by eqmule
- Added ActorDef to the spawn tlo it returns the name of the actor as a string

Jun 07 2018 by eqmule
- Fixed a crash in mq2linkdb
- Fixed multiple potential null ptr crashes in core
- synced some rof2 emu code to latest live

May 30 2018 by eqmule
- Fixed a bug in .FirstFreeSlot it returned 0 if all slots in a container was empty, but it should return 1 as in slot 1 is the first empty slot
- Added support for the InvSlot TLO to return .Item (as a ItemType) for worldcontainers
  Example: /echo ${InvSlot[enviro].Item.FirstFreeSlot}
  it will echo the first free slot in the currently open worldcontainer (forge,loom etc)

May 29 2018 by eqmule
- Fixed ${InvSlot[tradex].Item} where x is 1-16 for trading with players and 1-4 for NPCs
- Fixed a potential NULL pointer crash in mq2hud
- Fixed a potential NULL pointer crash in mq2chathook
- Fixed a potential NULL pointer crash in mq2moveutils
- Fixed a rare invalid pointer crash in mq2targetinfo

May 25 2018 by eqmule
- Added .Trigger and .HasSPA to the Spell TLO
  .Trigger[x] returns a SpellType.
  .HasSPA[x] returns true or false
  Usage:
  Sub Main
	/declare i int local
	/if (${Spell[Livio's Malosenia].HasSPA[470]}==TRUE) {
		/for i 1 to ${Spell[Livio's Malosenia].NumEffects}
			/if (${Spell[Livio's Malosenia].Attrib[${i}]}==470) {
				/echo the spell Livio's Malosenia triggers ${Spell[Livio's Malosenia].Trigger[${i}].Name}
			}
		/next i	
	}
  /return

May 22 2018 by eqmule
-Fixed PCHARINFONEW

May 21 2018 by SwiftyMUSE
- Corrected stacking for changes to spa 148
- Corrected display of spa 148 to use new data format

May 18 2018 by eqmule
- Updated for TEST
- Added .Next and .Prev to the grounditem type. - cred Alynel
  Usage: /declare NextItem ground local
		 /echo ${Ground[thing i'm looking for].Next.ID}
- Fixed Me.XTAggroCount

May 16 2018 by eqmule
- Updated for LIVE
- Updated for TEST

May 13 2018 by SwiftyMUSE
- Added MQ2SoundControl to global build.
- Removed patterns from MQ2Camera, MQ2Moveutils, MQ2SoundControl
- Fixed keybinds, you can no longer bind to the 22 additional keybind names
- Changed ${Me} and ${Buff} TLO's
  Added DiseaseCounters, PoisonCounters, CurseCounters, CorruptionCounters
  Changed Counters to TotalCounters
  Updated all counters to correctly pull the spelldata values

May 08 2018 by eqmule
- Updated or TEST

May 07 2018 by eqmule
- ${FindItem} and ${FindBankItem} and ${FindItemCount} now takes item ids as well
  Example: /echo ${FindItemCount[12345]} will find how many items with the id 12345 you have.
- /itemnotify now takes item ids as well.
  Example: /itemnotify #12345 leftmouseup will pick up an item with the id 12345 if one exist.
  NOTE: the hash (#) IS mandatory when using it this way.

Apr 27 2018 by eqmule
- Added .Solvent to the Augslot TLO it returns a SolvenType and if empty just the Name :cred and nagging for weeks: maskoi
  SolventType has 4 members: Name which is a string type, ID as int, Item as itemtype and Count as int.
  Example 1: /echo ${FindItem[Cloth Cap].AugSlot[0].Solvent.Name}
  Output: Class I Augmentation Distiller
  Example 2: /echo ${FindItem[Cloth Cap].AugSlot[0].Solvent.ID}
  Output: 47001
  //if you dont have the solvent in your inventory:
  Example 3: /echo ${FindItem[Cloth Cap].AugSlot[0].Solvent.Item.Name}
  Output: NULL
  Example 4: /echo ${FindItem[Cloth Cap].AugSlot[0].Solvent.Count}
  Output: 0

Apr 24 2018 by eqmule
- Updated for TEST

Apr 23 2018 by eqmule
- Fixed Me.XTAggroCount and Me.XTHaterCount
- Added ${MacroQuest.Version} it will grab whatever version is set in the resource for fileversion for mq2main.dll
- Added ${MacroQuest.InternalName} it will grab whatever internal name is set in resource for the internalname for mq2main.dll
- Fixed a crash in /itemnotify

Apr 21 2018 by eqmule
- Updated for LIVE
- .Replace can once again take an empty second argument example ${Target.Name.Replace[mule,]} output Eq if targets name is Eqmule

Apr 20 2018 by eqmule
- Bugfixes.
- Fixed a null pointer crash in MQ2FPS thanks to almar for the report and dump file.

Apr 19 2018 by eqmule
- Fixed a bug in _SPELLBUFF, it had the wrong size and members
  this will fix any problems with casting spells etc.

Apr 18 2018 by eqmule and SwiftyMUSE
- Updated for LIVE
- You should remove DataCompare, FindOffsets and GetDWordAt from your plugins, they exist as inlines from now on in core.

Apr 17 2018 by eqmule and SwiftyMUSE
- Updated for TEST

Mar 17 2018 by eqmule
- Added .Path to the MacroQuest TLO
  Usage /echo ${MacroQuest.Path}
  returns the path to the folder mq2main.dll is in
- Added Name, Level and Count to the CharSelectList mermber of the EverQuest TLO
  Usage: /echo ${EverQuest.CharSelectList[1].Name}
  Usage: /echo ${EverQuest.CharSelectList[1].Count} yes I know it should be ${EverQuest.CharSelectList.Count} but just work with it like that.
  it returns the actual count of the characters in the list.

Mar 16 2018 by eqmule
- Updated for LIVE and TEST Fixed the ITEMINFO struct so things like StackSize works again.

Mar 14 2018 by eqmule
- Updated for LIVE

Mar 11 2018 by SwiftyMUSE
- Updated hotkey processing. You are now able to use any/all of the allowed modifiers win/alt/ctrl/shift keys.
  hotkey processing will allow characters `/~, 0-9, A-Z, NUMPAD0-9 as the keycode. For example, you might want
  win+ctrl+~ to be a valid hotkey.
  F12 is RESERVED for the debugger and can not be used as a hotkey. You can use F12 with a modifier.
- Updated XTAggroCount to return a value when only 1 mob is on xtarget.
- Added XTHaterCount as the number of mob on xtarget with AUTO-HATER.

Mar 11 2018 by eqmule
-Fixed another crash on TEST -brainiac

Mar 10 2018 by eqmule
- Updated the TEST build. If you crash use REBUILD on mq2main then build the rest again.
- mapcrash fixed - brainiac

Mar 09 2018 by eqmule
- Updated for TEST

Feb 27 2018 by eqmule
- Updated for TEST

Feb 22 2018 by swiftymuse
- Updated for LIVE
- Updated for TEST
- Fixed a crash that would occur in plugins that use the __msgTokenTextParam_x offset which was wrong. -eqmule
  If you unloaded a plugin and that stopped the crashing, you can now safely load it again.

Feb 21 2018 by eqmule and SwiftyMUSE
- Updated the TEST build.
- Updated the LIVE build.
  Look, we don't know for sure which plugins work and which don't after todays patch
  there was just too many things that changed but i can say that I know mq2cast needed an update here:
  from:
  [code]
  if (Cast->CastOnYou[0]) {
	sprintf_s(Temps, "%s#*#", Cast->CastOnYou);
  [/code]
  changed to
  [code]
		/*CastByMe,CastByOther,CastOnYou,CastOnAnother,WearOff*/
		if (char*str = GetSpellString(Cast->ID,2)) { 
			sprintf_s(Temps, "%s#*#", str);
  [/code]
  So from now on if you need the strings from spell use GetSpellString
- Updated mq2moveutils in the builder with new patterns

Feb 13 2018 by eqmule
- Added MQ2TargetInfo plugin to core
  It adds 3 features to the target window:
  1. Distance to target
  2. Can See
  3. PH - if the mob you target is a place holder for a named, it will show info on the named when clicked.

Jan 31 2018 by eqmule
- Added a toggle to the item display window to add/remove loot filter
- Moved the button so its always paralell to the modified label
- Fixed a crash when typing % in chat - cred: jimbob

Jan 24 2018 by eqmule
- Attempted to fix the empty char select list bug that pops up a window and says "Loading Characters" by going back to serverselect.
  I cant tell if the fix works or not since the bug is so rare.
- The itemdisplay window has a new button for looking up the item on lucy.
- New command: /itemdisplay
- Usage: /itemdisplay LootButton off/on if not specified its a toggle
- Usage: /itemdisplay LucytButton off/on if not specified its a toggle

- The following APIs where incorrectly named and has been changed to their correct names:
- CHtmlWnd__OpenUrl_x is now  CWebManager__CreateHtmlWnd_x
- CHtmlComponent__CheckUrl_x has is now CHtmlComponentWnd__ValidateUri_x
- pWebBrowser is now pCWebManager
- pinstCHtmlWnd_x is now pinstCWebManager_x
- All instances of CCharacterSelect are now CCharacterListWnd

Jan 23 2018 by eqmule
- Updated for TEST

Jan 17 2018 by eqmule
- Updated for LIVE Go build it at www.macroquest2.com/builder
- Added a "Add to loot filters" button on the itemdisplay window.
  Usage: click it and it will add the item as always greed and roll.
  This feature is only present if you have the mq2itemdisplay plugin loaded.

Jan 17 2018 by SwiftyMUSE
- Fix for tunare deity

Jan 15 2018 by eqmule
- Added /AddLootFilter syntax:  /AddLootFilter <itemID> <ItemIconID> \"Item Name\"
  Example: /AddLootFilter ${Cursor.ID} ${Cursor.IconID} "${Cursor.Name}"
  will add whateveris on your cursor to the advloot filters as always greed and roll.
- Added a AddLootFilter method to the DisplayItem TLO.
- Usage: /invoke ${DisplayItem.AddLootFilter} or ${DisplayItem[x].AddLootFilter} where x is 1 to 6
- this will add whatever item is in the DisplayItem to advloot filters as AG and Roll

- Added a new TLO MQ2ItemSpellType as pItemSpellType:
- Added some new pItemType members:
	Clicky,Proc,Worn,Focus,Scroll,Focus2,Mount,Illusion and Familiar
	they all return the new pItemSpellType
	which has the following members:
	SpellID,RequiredLevel,EffectType,EffectiveCasterLevel,
	MaxCharges,CastTime,TimerID,RecastType,
	ProcRate,OtherName,OtherID and Spell (Spell returns a spelltype)
- Added the .CanUse member to the itemtype.
  Usage: /echo ${Cursor.CanUse} or ${FindItem[whatever].CanUse} or ${DsiplayItem.CanUse}
  returns true or false if u can use the item on your cursor.
  NOTE: if your item does NOT have a class set, i.e. None/None it will return FALSE.
  I am just calling the original eq function so dont blame me for anomolies.

Jan 10 2018 by eqmule
- Updated for TEST Go build it at www.macroquest2.com/builder

Jan 07 2018 by SwiftyMUSE
- Corrected ${Me.Rooted}, credit Plure.
- Updated spell SPA displays with new SPA's.
- Added ${Me.MercAAPoints}, ${Me.MercAAPointsSpent}
- Corrected ${Me.CursorKrono}

Jan 07 2018 by brainiac
- Updated solution and project files to use latest Visual Studio 2017.
  If you're not using VS2017 yet, go download community edition for free: 
  https://www.visualstudio.com/downloads/

Jan 05 2018 by eqmule
- Updated for LIVE Go build it at www.macroquest2.com/builder

Jan 04 2018 by eqmule
- Updated for TEST Go build it at www.macroquest2.com/builder

Jan 01 2018 by eqmule
- Updated for LIVE Go build it at www.macroquest2.com/builder
- /tar npc now correctly targets the closest npc using distance3d.

Dec 28 2017 by eqmule
- Updated for LIVE Go build it at www.macroquest2.com/builder
- ${Group.Cleric} will now return the cleric as a spawntype if a cleric is in the group (not a mercenary but a REAL cleric)
- ${Group.Injured[90]} will return the numbers of people in the group that has a hp percent lower than 90

Dec 19 2017 by eqmule
- Updated for LIVE Go build it at www.macroquest2.com/builder

Dec 16 2017 by eqmule
- Updated for TEST Go build it at www.macroquest2.com/builder

Dec 12 2017 by eqmule
- Updated for TEST Go build it at www.macroquest2.com/builder
- Updated for LIVE Go build it at www.macroquest2.com/builder

Dec 11 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 10 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 09 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 08 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 07 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder
- Fixed the UIType enumeration so things like ${Window[MerchantWnd].Child[ItemList].List[1,2]} etc, will work again.

Dec 06 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder
- Updated for TEST Go build it at www.macroquest2.com/builder
- Fixed /loginchar server:charname it should once again work.

Dec 05 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 04 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 04 2017 by SwiftyMUSE
- Added new TLO member XTAggroCount to ${Me}
  Usage: /echo ${Me.XTAggroCount} or ${Me.XTAggroCount[100]}
  it returns the number of AUTO-HATER mobs on the extended
  target window where your aggro is less than the optional
  parameter N. N must be between 1-100 inclusive or it will be
  set to 100 (the default value).
  So, ${Me.XTAggroCount} and ${Me.XTAggroCount[100]} are identical.

Dec 03 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 02 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Dec 01 2017 by eqmule
- Added new TLO member BardSongPlaying to ${Me}
  Usage: /echo ${Me.BardSongPlaying}
  it returns true if a bard song is playing and false if not.
- Fixed ${Me.SpellReady} to take bard songs playing into account properly so it returns true even if a song is playing.
- Added Category and Subcategory to the SpellDisplay Window.
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 30 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 29 2017 by eqmule
- Updated for TEST Go build it at www.macroquest2.com/builder
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 28 2017 by SwiftyMUSE credit plure
- Updated all FindItem code to allow partial matches and consistently check
  your cursor, inventory (including bags), keyrings for the item. Will now
  allow partial and exact match checks for all.
- Update to consistently check bank/shared bank slots/bags and to allow
  partial and exact match checks for all.

Nov 28 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 27 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 26 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 25 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 24 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 23 2017 by eqmule HAPPY THANKSGIVING
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 22 2017 by eqmule
- Updated for BETA Go build it at www.macroquest2.com/builder

Nov 21 2017 by eqmule
- Updated for LIVE Go build it at www.macroquest2.com/builder
- Updated for BETA

Nov 20 2017 by eqmule
- Updated for BETA

Nov 19 2017 by eqmule
- Updated for BETA

Nov 18 2017 by eqmule
- Updated for BETA

Nov 17 2017 by eqmule
- Updated for BETA

Nov 16 2017 by eqmule
- Updated for BETA

Nov 15 2017 by eqmule
- Updated for BETA
- Updated for LIVE

Nov 14 2017 by eqmule
- Updated for BETA

Nov 13 2017 by eqmule
- Updated for BETA

Nov 12 2017 by eqmule
- Updated for BETA

Nov 11 2017 by eqmule
- Updated for BETA

Nov 10 2017 by eqmule
- Updated for BETA

Nov 09 2017 by eqmule
- Updated for BETA

Nov 08 2017 by eqmule
- Updated for TEST
- Updated for BETA
- Added a new command: /usercamera - feature request by Bogreaper
  You can use it to set the current camera as well as save/load settings for user camera 1
  NOTE: "User Camera 1" is actually camera number 3 in the client...
  Cameras are defined as follows:
  0 = First Person Cam
  1 = Overhead Cam
  2 = Chase Cam
  3 = User Cam 1
  4 = User Cam 2
  5 = Tether Cam
  6 = Zoom Cam
  7 = Internal Cam (don't ask, it just is ok. It is used for things like when you edit the facial features of your character etc.)

  Just type /usercamera without any arguments to see help for it.
  It will display the current active camera in the Selector Window titlebar, this can be toggled with /usercamera on/off default is on.
  Example: switch to camrea 3 by doing /usercamera 3
           Then, adjust it how you like it, type /usercamera save
		   Ok, that's it, next time u want to get back to that EXACT camera position, you just do /usercamera load
		   You can create hotkey(s) as well.
		   Optional: you can do /usercamera save eqmule and it will save it for eqmule (or whatever your chanracter name is), same thing with load.
		   if you omit the character name, it just saves is as a global camera.


Nov 07 2017 by eqmule
- Updated for BETA

Nov 06 2017 by eqmule
- Updated for BETA #2

Nov 06 2017 by eqmule
- Updated for BETA

Nov 05 2017 by eqmule
- Updated for BETA

Nov 04 2017 by eqmule
- Updated for BETA

Nov 03 2017 by eqmule
- Updated for BETA
- Merchant Window TLO Fixed.

Nov 02 2017 by eqmule
- Updated for BETA

Nov 01 2017 by eqmule
- Updated for BETA

Oct 31 2017 by eqmule
- Updated for BETA

Oct 30 2017 by eqmule
- Updated for BETA

Oct 29 2017 by eqmule
- Updated for BETA

Oct 28 2017 by eqmule
- Updated for BETA

Oct 27 2017 by eqmule
- Updated for BETA

Oct 26 2017 by eqmule
- Updated for BETA

Oct 25 2017 by eqmule
- Updated for BETA

Oct 24 2017 by demonstar55
- Added ${Target.MyBuffDuration} it returns your buffs duration on the target.

Oct 24 2017 by eqmule
- Updated for BETA

Oct 23 2017 by eqmule
- Updated for BETA

Oct 22 2017 by eqmule
- Updated for BETA

Oct 21 2017 by eqmule
- Updated for BETA
- Updated for TEST
- We are currently testing the new build server for LIVE builds, pm me for an invite.

Oct 18 2017 by eqmule
- Updated for LIVE
- The latest zip is located here: http://www.mq2update.com/MQ2-Latest.zip

Oct 13 2017 by eqmule
- Updated for TEST
- MQ2Auth.exe now produces truly unique hashes, everyone needs to rerun it.
- You can now see what your MQ2Auth is by clicking the Show MQ2Auth menu item on the trayicon.
  this also optionally let you copy it to the clipboard.
- EQ_CHAT_HISTORY_OFFSET has been removed it was a pita to keep updated
	From now on do :
	OutputBox->MaxLines = 0x190;
	instead of
    (DWORD*)&(((PCHAR)OutputBox)[EQ_CHAT_HISTORY_OFFSET])=0x190; 

Oct 12 2017 by eqmule
- Updated for TEST
- Updated for TEST #2

Oct 11 2017 by eqmule
- Updated for TEST

Oct 03 2017 by eqmule
- /removebuff now takes parameters: -pet and -both | cred MacQ
  /removebuff -pet buffname removes the buff from your pet ( same functionality as /removepetbuff buffname)
  /removebuff -both buffname removes the buff from both you and your pet.

Sep 28 2017 by eqmule
- Added MQ2FamKiller
- Added MQ2Bandolier
- Fixed MQ2Cursor
- Removed the voice "help" in group for mq2rez.

Sep 26 2017 by eqmule
- Updated the SPELL struct:
- CARecastTimerID has been renamed to ReuseTimerIndex
- Mana has been renamed to ManaCost
- FizzleTime has been renamed to RecoveryTime
- ReagentId has been renamed to ReagentID
- DescriptionNumber has been renamed to DescriptionIndex
- SubSpellGroup has been renamed to SpellSubGroup
- Location has been renamed to ZoneType
- DurationValue1 has been renamed to DurationCap
plugins changed:
MQ2NetBots
MQ2NetHeal
MQ2Debuffs
MQ2Cast
MQ2Melee

Sep 25 2017 by eqmule
- MAXTURBO has been moved to the ini file. cred: silverj
- Set TurboLimit under the [MacroQuest] section in the macroquest.ini to whatever, it defaults to 240.

- Obviously people are going to set this to 1000000000000000
- and then completely lock up their game, cause the engine will never ever yield time to eq, but hey... its their choice now I guess.
- I suggest you dont mess with it at all, and leave it at 240 max.

- this: http://www.macroquest2.com/phpBB3/viewtopic.php?f=28&t=20394
- and this: http://www.macroquest2.com/phpBB3/viewtopic.php?f=28&t=20393
  has also been implemented, thanks silverj

Sep 24 2017 by SwiftyMUSE
- Updated FindItemCount to include items on the cursor in the count.

Sep 23 2017 by eqmule
- Updated for TEST

Sep 21 2017 by eqmule
- Added ${Spell[x].IllusionOkWhenMounted} it returns true if the illusion spell will land when you are on a mount
  you can call this using any spell, but it will always return true if the spell is NOT an illusion spell.
  in fact it wont even evaluate it further if its not a illusion spell
- Fixed the pinstCTimeLeftWnd_x offset

Sep 20 2017 by eqmule
- Updated for LIVE

There will be no more public mq2 updates until I catch the guy that released the mq2 for agnarr.

send me a pm or skype text: eq.mule
if you have information. you can be anonymous.

longtime friends and loyal users here that I know and trust will be given the updates by me only from now on. (at no charge of course.) mq2 is still open source and free, its just that equistructs.h eqgame.h and eqdata.h wont be distributed or updated by me anymore. those change every patch and everything prior to this day is under gpl and can of course be requested or downloaded, but from now on until this crap is resolved, I have my own NEW includes that are NOT under the gpl.

I'm sick of having my hard work being taken and passed of by some leech on a server that I specifically requested we stay away from. I wont tolerate it.

mq2 is free and staying off of truebox was the only price people had to pay, cant do that? no mq2 for anyone anymore.

wanna step in and update it? lol go for it, it must be "easy" if eqmule can do it in a couple hours... pfft... yeah right...

/eqmule (yeah I'm bitter)

19 Sep 2017 by SwiftyMUSE
- Modified Math.Clamp to use the parameter list of (N, Min, Max). ie, will clamp the value N between Min and Max.
- Added ${Group.AvgHPs} guess what it returns? - eqmule

18 Sep 2017 by eqmule
- Fixed an infinite loop bug and a variable parse bug in Eval functions. -cred bug report: creamo
- Eval functions that take multiple arguments MUST separate those with comma(s) from now on
  Example: (run with a cleric, war or shaman)
  [code]
  Sub Main
	/declare c_argueString string outer shm clr war
	/declare ChatSender string local ${Me} 

	/if (!${checkbot["shm war clr", ${ChatSender}]}) { <-NOTE the COMMA
		/echo ${Time} Only Func3: FALSE, this should be TRUE
	} else {
		/echo ${Time} Only Func3: TRUE, this should be TRUE
	}
  /return

  Sub checkbot(selectedBots, chatSender)
    /declare botSelected bool local FALSE
	/echo ${Time} in Sub checkbot selectedBots=${selectedBots} chatSender=${chatSender}
    /if (${Select[${Me.Class.ShortName},${selectedBots}]}) /varset botSelected TRUE
  /return ${botSelected}
  [/code]

17 Sep 2017 by eqmule
- Fixed ${Me.GukEarned}, ${Me.MMEarned}, ${Me.RujEarned}, ${Me.TakEarned}, ${Me.MirEarned} and ${Me.LDoNPoints}
- Added a new TLO PointMercant it only have one member : Item which is a pPointMerchantItemType.
  The pPointMerchantitemType has the following members: Name, ItemID, Price, ThemeID, IsStackable, IsLore, RaceMask, ClassMask, bCanUse
  Usage:
  /echo ${PointMercant} returns true if the LDON Mercant window is open and FALSE if not.
  /echo ${PointMercant.Item[1].Price} OR /echo ${PointMercant.Item[Ebon Hammer].Price}
  returns the Price for index 1 or whatever index Ebon Hammer is in if you do it by name.
  etc.

15 Sep 2017 starring SwiftyMUSE as "the captain", eqmule as "crew member number 6" and special guest star: eqholic
- Updated to handle the new SPA's
- Fixed a bug in /next not taking its argument into account for nested for loops.
- Fix for labels
- Fixed the CSIDLWND struct (the SIDL define...) so since we have never had this right it was time, but note that
  if your plugin uses stuff like: pwnd->SidlText and its NOT an actual CSidlScreenWnd then you need to change it to whatever window it actually is.
  I guess questions about this should be directed to me (eqmule)

plugins changed outside of core are attached here:
http://www.macroquest2.com/phpBB3/viewtopic.php?f=29&t=11451&p=174467#p174467
MQ2Rez

14 Sep 2017 by eqmule
- Updated for TEST
- Fixed ${Familiar[x].} it will return familiars and not illusions now...

- Fixed a bunch of window structs that we where completely misusing anyway.
  this could require some plugin changes, contact me for help if you get errors.

- Fix: Variables that are undeclared but supplied as paramters now default to an actual NULL or 0 not the string "NULL"

- Inspecting the Blessed Spiritstaff of the Heyokah will no longer ctd you.
- Added Math.Clamp ${Math.Clamp[Min, N, Max]} will clamp N between Min and Max. - cred derple
  Example:
  ${Math.Clamp[1, 15, 30]} => 15
  ${Math.Clamp[20, 15, 30]} => 20
  ${Math.Clamp[1, 15, 10]} => 10
  Practical usage:
  /bct ranger //stick id ${Target.ID} ${Math.Clamp[25,${Target.Distance},150]} 
  this will make your ranger stay put if he is already between 25-150 meters away
  otherwise it will move him at most 150 away and at least 25 away.

12 Sep 2017 by eqmule and eqholic
- All plugin sources for this zip are attached to this post:
  http://www.macroquest2.com/phpBB3/viewtopic.php?f=29&t=11451&p=174415#p174415
- Changed MQ2MoveUtils to save stuff faster.
- MQ2ChatWnd got a new tlo /echo ${ChatWnd.Title}
- MQ2ChatWnd got a new command /setchattitle
- MQ2Melee updated - it has flags for down and holyshits called downflag0-60 and holyflag0-60
  you SHOULD set those flags to 2 if you parse ANY macro variables.
  Example:
  [code]
  downflag0=2
  downshit0=/if (${Macro.Paused}) /echo ${Macro} is PAUSED!
  [/code]
- MQ2Hud now updated with a new type HUDTYPE_MACRO which is 16
  This means you can now set the type to any combination of 1 2 4 8 and 16
  see http://www.macroquest2.com/wiki/index.php/MQ2HUD for more info.
  Basically using a hud that tries to parse variables that are used in macros, before they are declared will fail.
  This new flag lets mq2hud know to not even try unless its set.

- Adding events from a macro will now also automatically /declare variable as outer if used.
  Example: #Event Burn              "[MQ2] |${BurnText}|"
  As you can see this event uses the variable ${BurnText} and it will therefor /declare it as well.
  This means you can remove /declare BurnText in your Sub Main since adding the event did it for you already.

- Added ${Macro.IsOuterVariable[xxx]} which returns TRUE/FALSE, it checks if a outer variable exists. (read is declared)
  I would recommend NOT using this in macros unless its for debug purposes because it can get quickly get expensive in terms of cpu cycles.

- Added ${Macro.IsTLO[xxx]} which returns TRUE/FALSE, it checks if a Top Level Object exists. This should be faster than checking if a plugin is loaded. *should*
  Usage:
    [code]
    /if (${Macro.IsTLO[Melee]}) {
        /echo yes there is a Melee Top Level Object loaded...
		/echo this means I CAN actually do stuff with it without it throwing the Undeclared warning:
		/delay 25 !${Melee.Combat}
    } else {
        /echo no there is no such TLO, maybe you should load mq2melee?
		/end
    }
    [/code]

07 Sep 2017 by eqmule and eqholic
- All Plugin Sources changed outside of core for this zip are attached to the post here:
http://www.macroquest2.com/phpBB3/viewtopic.php?f=29&t=11451&p=174399#p174399
- using namespace std; has been removed from mq2main.h
  THIS MEANS your plugins will ERROR with lines like this:
  error C2143: syntax error: missing ';' before '<'
  The line: map<string, class CXWnd2 *> WindowMap;
  To fix: Find #include "../MQ2Plugin.h" in your plugin and add using namespace std; under the LAST #include below it.
  Example:
	[code]
	#include "../MQ2Plugin.h"
	#include <otherheader>
	...
	using namespace std;
	[/code]
	OR just change the line to say std:: map<std::string, class CXWnd2 *> WindowMap;

-  The reason for that change is that right now we litter ALL projects with the std namespace and it is just not good.
   Let everyone that needs that namespace use it in their own projects from now on.

- #bind(s) are now fixed and won't screw up the macrostack anymore.
- Todays update is significant because I rebuilt the macro engine to improve performance,
  it was well overdue. The biggest change is that gMacroBlock is now a map.
- Undeclared Variables are no longer tolerated, and the macroengine will not run at optimal speed
  if they exist. I have added a TLO to check for them because of this and a new macro keyword #warning as well
  so there is no good reason to run old macros where these kinds of variables hog cpu power:
AGAIN:   IMPORTANT: Undeclared variables will slow down macro performance a LOT if they are used over and over, so, fix your macros.

- The Macro TLO has a new method: .Undeclared
  Usage: /invoke ${Macro.Undeclared} and it will list all undeclared variables.
- New macro keyword: #warning
  add it at the top of your macro, and you will get warnings if there are undeclared variables used in it.

- /while and /for loops can now be nested inside each other.
- /continue and /break should work properly inside /for loops now.
- /continue and /break works in /while loops now.

- Updated MQ2Rez and MQ2Cast to not hog the cpu looking up windows over and over.
- Other stuff to optimize and cut down on cpu intensive tasks.

Files changed outside of core:
\MQ2Cast\MQ2Cast.cpp
\MQ2Rez\MQ2Rez.cpp

01 Sep 2017 by eqmule and eqholic
- You can now call functions inside if statements in your macros
  Use [] after your sub inside the if statement to tell the macro its a sub
  so /if (blah[]) /call dostuff
  or if it actually have parameters
  /if (blah[${arg1} "hi there" 0]) /call dostuff

  Example:
  [code]
Sub Testsub
    /echo Enter Testsub
    /return Hello world
/return

Sub Testargs(int arg1,int arg2)
    /if (${arg1} > ${arg2}) {
        /return Testargs: ${arg1} > ${arg2}
    } else {
        /return Testargs: ${arg1} <= ${arg2}
    }
/return

Sub IsHuuge(int arg1)
    /echo IsHuuge ${arg1} ?
    /if (${arg1} > 1000) {
        /echo TRUE
        /return TRUE
    } else {
        /echo FALSE
        /return FALSE
    }
/return

Sub Main 
    /echo ${Testsub[]}
    /echo ${Testargs[10 9]}
    /if (${IsHuuge[2000]} && !${IsHuuge[1]}) /echo Huuge and smaaal
/return
  [/code]

19 Aug 2017 by eqmule
- Updated for TEST

17 Aug 2017 by eqmule
- Fixed Me.Aego and some other stuff related to it.
  Unfortunately for us and everyone else that parses the spells db
  Category and Subcategory are now 0 for all spells that cannot be scribed.
  Lets hope this was just a mistake and it will be reversed in a future patch.

- Me.Aura now returns a pAuraType cred: xowis
  Members: ID, Name, SpawnID
  Methods: Remove
- Me.Aura[] now accept partial matches

16 Aug 2017 by eqmule
- Updated for LIVE

11 Aug 2017 by eqmule
- Fixed a crash in the TEST build.

10 Aug 2017 by eqmule
- Updated for TEST
- Improved AddAlias, RemoveAlias and the rest of the alias stuff.
  macros that use /addalias should notice a significant increase in performance.

03 Aug 2017 by SwiftyMUSE
- Updated /cast to cast the memorized rank of the spell when the rank is not given in the name.
- Fixed random crashes with /click when zoning.

31 Jul 2017 by eqmule
- /cast now takes an optional loc x y z argument useful for splashspells.
  Example: /cast "Reforming Splash" loc 123 456 789
  would cast the splash spell at that location...
  just doing a /cast "Reforming Splash" will cast it either on your targets location
  and if you have no target on your own location.

- Added IsSummoned to the spawn tlo, returns true/false if its a summoned being (pet for example)
- MQ2Template now (correcty) creates OnBeginZone & OnEndZone functions. - cred htw
- Distances in searchspawn now return the true 3D distance (instead of 2d distance)
- Added zLoc to searchspawn. cred ctaylor
  this means you can search location and zradius at a specific zloc.
  Example:
  /echo ${Spawn[npc loc 10 20 30 radius 20 zradius 15]}
  IF there is a npc within 20 radius of loc 10,20 AND within +-15 Z of 30 (so max 45 or min 15)
  THEN it will return that spawn...
  NOTE: You can still use ${Spawn[npc loc 10 20 radius 20 zradius 15]}
  like before this addition, and then it will just use YOUR Z (thats how it has worked up til now.)
  If you use the loc keyword and there is a NUMBER as parameter 3, it will ALWAYS be assumed its the z loc...
  IF there is NO NUMBER as the third parameter after loc, then its NOT a Z.
  Just to make this perfectly clear: ALWAYS specify the radius keyword AFTER your loc keyword, and you will
  be fine no matter if you feed it 2 or 3 args.
  Makes sense? yeah... right...

27 Jul 2017 by eqmule
- Polished up the window manager a bit, it was overdue.
  This means some plugins might break, but its easy to fix.
	Example:
	[code]PCSIDLWND* ppWnd = pWindowManager->pWindows;
	PCSIDLWND pWnd=*ppWnd;
	while (pWnd = *ppWnd)
	...
	[/code]
	becomes:
	[code]for(int i=0;i<pWindowManager->pWindows.Count;i++)
	{
		if (PCXWND pWnd = pWindowManager->pWindows[i]) {
		...
	[/code]

25 Jul 2017 by eqmule
- Minor Maintenance Release
- IsGroupMember returns true for mercenaries as well now.
- Fixed a buffer overflow in mq2chatwindow

23 Jul 2017 by eqmule
- Updated for LIVE
- Updated for TEST

20 Jul 2017 by eqmule
- Improved /face to mimic exactly how the client AI faces mobs.
  This means its looks very natural and smooth now.
  Please don't use /face fast anymore, it looks "bottish"
  and there is no good reason to use it.

19 Jul 2017 by eqmule
- Updated for LIVE
- The crash callback will once again produce dump files and zip them.
- Math.Rand now takes an optional min argument so you can get a random number between 2 variables.
  Example: /echo ${Math.Rand[5,10]}
  this would return a randum number between 5 and 10.
  You can still use the original just specifying the max.
  Example: ${Math.Rand[10]}
  in which case it behaves as before. (in this example, rand between 1 and 10) 

17 Jul 2017 by SwiftyMUSE
- Added ${Me.Beneficial}, ${Me.BASExxx} back into the source code.
- Added ${Me.CursorKrono}

12 Jul 2017 by eqmule
- Updated for TEST
- All instances of "Malod" has been renamed to "Maloed"
- Darkened Malosenia is now correctly returned when doing a ${Target.Maloed}

10 Jul 2017 by SwiftyMUSE
- added optional <z> parameter to /face loc

21 Jun 2017 by eqmule
- Updated for TEST
- Updated for LIVE

21 Jun 2017 by SwiftyMUSE
- Updated ground spawn names
- Update MQ2Hud for occasional crash - cred demonstar55

17 Jun 2017 by eqmule
- Updated for ISXEQ so it once again builds...
  I loaded the ISXEQ.sln in VS 2015 and set the projects to the v140_xp toolset, and it built.
  Report bugs or problems on the forum.

15 Jun 2017 by eqmule
- Updated for TEST

14 Jun 2017 by eqmule
- Changed ${Switch.Distance} and  ${Switch.Distance3D} so they report distance to the switch outer bounds, not its center.
- Fixed /click left door to take character reach and door radius into account.
  This means doors that previously couldn't be opened because there was no way to get within 20 feet of them
  can now be opened (the plane of justice door in pot comes to mind)
  In retrospect it kinda makes sense that if a door radius is huge, you dont have to get as close to it to open it...
  Thanks to Derple reporting this bug.
- Doors that require lock picking can now be opened as well if you have lockpicks on your cursor.
- Updated for TEST

02 Jun 2017 by eqmule
- Updated for TEST

18 May 2017 by SwiftyMUSE
- Updated faction names

17 May 2017 by The Undertaker
- Updated for LIVE

15 May 2017 by maskoi
- EverQuest.CurrentUI now return a string representing the currently loaded UI skin.
- EverQuest.IsDefaultUILoaded returns a bool true or false if the "Default" UI skin is the one loaded.

10 May 2017 by The Undertaker
- Updated for TEST

01 May 2017 by The Undertaker
- Fixed a bug in the new noparse ini thingy

01 May 2017 by The Undertaker
- ${Ini} now takes an optional 5th argument "noparse"
  This means you can now (finally) read ini settings into a variable without parsing the actual setting.
Example:
INIFILE:
[code]
[DPS]
DPSCondition1=${Me.XTarget[1].PctHPs} > 50
[/code]
[code]
Sub Main
	/declare DPSCondition1 string local
	/echo This is the actual setting for DPSCondition1 : ${Ini[MySettings.ini,DPS,DPSCondition1,NULL,noparse]}
	/varset DPS1Condition ${Ini[MySettings.ini,DPS,DPSCondition1,NULL,noparse]}

	|looping it here so you can see the condition actually changes as the xtarget mobs HP changes and no need 
	|for reading the ini over and over anymore... you're welcome...
:loop
	/echo ${DPSCondition1}
	/delay 1s
	/goto :loop
/return
[/code]

29 Apr 2017 by The Undertaker
- Updated for TEST

25 Apr 2017 by The Undertaker
- Updated for LIVE

24 Apr 2017 by htw
- Added a new TLO ${Range} which returns a pRangeType
  pRangeType has 2 members:
  Between which returns TRUE or FALSE
  and
  Inside which also returns TRUE or FALSE
  Usage Example:
  /echo ${Range.Inside[10,5:9]}
  which will return TRUE since 5 and 9 are both within the 10 range.
  /echo ${Range.Between[85,95:100]}
  which will return FALSE since 85 is not a number between 95 and 100

24 Apr 2017 by The Undertaker
- Maintenance Update

21 Apr 2017 by Derple
- Added new #bind command for macros.
  Short Explaination, this allows you to execute macro sub routines.
  Long Explaination:
  Binds are triggered when a macro runs either:
  /varset or /echo or /call or if a Sub is executed.
#bind allows you to bind an ingame slash command to a macro function.
Before you had to do this with #events and capture text that you sent to yourself for example: 
#event SayMana "#*#SayManaPercent#*#"
Now you can do 
#bind SayMana /saymana
Instead of sending yourself the keyword you can just type /saymana and it will execute the function called "Sub Bind_SayMana"
Example:
[code]
| Old Way
| #event StartCoh "#*#COH --GRP--#*#"
| New Way you can now just type /coh or /bcaa //coh or /bct mage //coh
#bind StartCoh /coh

Sub CastSpell(string spellToCast)
    /declare delayTime int local 0
    /echo Casting: ${Target.Name} with ${spellToCast}
    /casting "${spellToCast}" -maxtries|5
    /call WaitCastFinish
/return

Sub Event_StartCoh
    /if ( ${Bool[${Me.Book["Call of the Hero"]}]} == FALSE ) {
        /echo I don't have COH - Bailing...
        /return
    }
 
    /declare i int local 0
    /declare GroupCount int local ${Group.Members}
    /for i 1 to ${GroupCount}
        /doevents
        /if ( ${Group.Member[${i}].Distance} > 50 ) {
            /target id ${Group.Member[${i}].ID}
            /call CastSpell "Call of the Hero"
        }
        /call WaitCastReady "Call of the Hero"
    /next i
/return

Sub Bind_StartCoh
    /call Event_StartCoh
/return

Sub Main
    :Loop
    /doevents
    /delay 1s
    /goto :Loo
/return
[/code]

21 Apr 2017 by The Undertaker
- Updated for TEST
- Fixed a couple offsets that where wrong for LIVE.

19 Apr 2017 by Dr. Sneerstell
- Updated for LIVE
- ${Skill[someskill].Auto} returns true or false if the skill is set to use /autoskill on/off
- ${Me.AutoSkill[1]} returns a pSkillType
- ${Me.AutoSkill[2]} returns a pSkillType
- Example usage:
- ${Me.AutoSkill[1].Name} returns the name of whatever skill is set as the first autoskill.
- ${Me.AutoSkill[2].ID} returns the ID of whatever skill is set as the second autoskill.
- Fixed /items crash
- The previous change to the GROUNDITEM Struct member "ID", the renaming of it to "ItemPtr",
  caused a crash, and has been reverted.
- Reorganized skills a bit. NUM_SKILLS is now 0x64 (it always was) so change plugins if needed.

15 Apr 2017 by eqmule
- Fix for /ranged crash in the TEST build.
- The GROUNDITEM Struct member "ID" has been renamed to "ItemPtr". (just accept it)
  Added some missing members to that struct as well.

14 Apr 2017 by eqmule
- Fix for /doability crash in the TEST build.

13 Apr 2017 by eqmule
- Updated for TEST

08 Apr 2017 by eqmule
- Changed max npc level to 125
  this fixes spawnsearch etc where npc's higher than level 115 would not show up.

19 Mar 2017 by eqmule
- Updated for TEST

15 Mar 2017 by eqmule
- Updated for LIVE
- Stuff

10 Mar 2017 by eqmule
- Updated for TEST
- Stuff

23 Feb 2017 by eqmule
- Added the offline trader acceptance to mq2autologin.

22 Feb 2017 by eqmule
- Tip for macro authors:
- Added FloorZ to the Spawn TLO it returns a float.
  FloorZ usage: ok so... eh, spawns are sometimes (always?) "planted" a few inches below or above the floor...
  This member represent where the floor is ACTUALLY at.
  So if you for example do a /echo ${Target.Z} and it returns 219
  and then you do a ${Target.FloorZ} it will return like 216 or something...
  Why is this important, well for brainiacs new mq2nav, I discovered that
  sometimes, when a spawns z location is outside of the geometry... (above or below)
  you cannot just do a /nav target or a /nav locxyz ${Target.X} ${Target.Y} ${Target.Z}
  BUT doing a /nav locxyz ${Target.X} ${Target.Y} ${Target.FloorZ} works.
  So... this is how you get /nav working correctly with problematic spawns which have their feet outside of the geometry.

15 Feb 2017 by eqmule
- Updated for LIVE
- XTARGETDATA has been renamed to XTARGETSLOT
- New include added SharedClasses.h
- the XTARGETSLOT struct has been moved to SharedClasses.h
- Unknown0x4 in the XTARGETSLOT struct has been renamed to XTargetSlotStatus, change plugins accordingly.
- XTarget stuff has gone through a make over, this will break plugins.
  Here are ONE example of how to fix this:
  MQ2Melee.cpp:
  change:
  [code]case XTaggro:
		{
			Dest.DWord = true;
			Dest.Type = pBoolType;
			if (PCHARINFO pChar = GetCharInfo()) {
				if (PXTARGETMGR xtm = pChar->pXTargetMgr) {
					if (PXTARGETARRAY xta = xtm->pXTargetArray) {
						DWORD x = 0;
						for (DWORD n = 0; n < xtm->TargetSlots; n++)
						{
							if (xta->pXTargetData[n].xTargetType == XTARGET_AUTO_HATER && xta->pXTargetData[n].Unknown0x4)
							{
								x++;
							}
						}
						if (x>1) {
							if (pAggroInfo) {
								for (DWORD i = 0; i<xtm->TargetSlots; i++) {
									if (DWORD spID = xta->pXTargetData[i].SpawnID) {
										if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(spID)) {
											if (pTarget && ((PSPAWNINFO)pTarget)->SpawnID == pSpawn->SpawnID)
												continue;
											if (pSpawn->Type == SPAWN_NPC && xta->pXTargetData[i].xTargetType == XTARGET_AUTO_HATER) {
												DWORD agropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;
												//WriteChatf("Checking aggro on %s its %d",xta->pXTargetData[i].Name,agropct);
												if (agropct<100) {
													Dest.DWord = false;
													break;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}[/code]
			to
			[code]case XTaggro:
				{
					Dest.DWord = true;
					Dest.Type = pBoolType;
					if (PCHARINFO pChar = GetCharInfo()) {
						if (ExtendedTargetList *xtm = pChar->pXTargetMgr) {
							DWORD x = 0;
							for (int n = 0; n < xtm->XTargetSlots.Count; n++)
							{
								XTARGETSLOT xts = xtm->XTargetSlots[n];
								if (xts.xTargetType == XTARGET_AUTO_HATER && xts.XTargetSlotStatus)
								{
									x++;
								}
							}
							if (x > 1) {
								if (pAggroInfo) {
									for (int i = 0; i < xtm->XTargetSlots.Count; i++) {
										XTARGETSLOT xts = xtm->XTargetSlots[i];
										if (DWORD spID = xts.SpawnID) {
											if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(spID)) {
												if (pTarget && ((PSPAWNINFO)pTarget)->SpawnID == pSpawn->SpawnID)
													continue;
												if (pSpawn->Type == SPAWN_NPC && xts.xTargetType == XTARGET_AUTO_HATER) {
													DWORD agropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;
													//WriteChatf("Checking aggro on %s its %d",xta->pXTargetData[i].Name,agropct);
													if (agropct < 100) {
														Dest.DWord = false;
														break;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}[/code]
- Good Luck.

13 Feb 2017 by derple
- Fixed ${Target.Buff[x].Caster} so it takes multiple casters of the same spell into account.
  Before this fix, only the first caster of a spell would be returned.
- Added ${Target.MyBuff[x]} it returns a pSpellType
  Example Usage:
  [code]holyshit0=/if (!${Debuff.Silenced} && ${Me.PctMana} > 10 && ${Target.MyBuff[Envenomed Breath].ID} == NULL && ${Target.CurrentHPs}<95) /casting "Envenomed Breath"[/code]
- Added ${Target.MyBuffCount} it returns a int of all buffs YOU have casted on the target.

08 Feb 2017 by eqmule
- Fixed a few places which would use pInvSlotMgr without NULL checking it
- Added .TimeBeenDead to the spawn tlo You can use it to figure out how long a corpse has been dead.
  NOTE: The timer is dependant on if you where in the zone when the corpse spawned.
  If you enter a zone and check this tlo member it will display the time of the death 
  as the time you entered the zone.
- Fixed a potential stack corruption in EndMacro
- Updated for TEST
- Made some changes to MacroQuest2.exe to deal with it not detecting eqgame version correctly sometimes.

03 Feb 2017 by eqmule
- Updated for TEST, yes there was a new patch.
- Fixed a issue that would hang the client and sometimes even crash it.
  this should fix the problem with using Untamed Rage on a berserker
  as well as other buff stacking check problems.

03 Feb 2017 by eqmule
- Updated for latest LIVE and TEST patches

01 Feb 2017 by eqmule
- Crash handling is now somewhat configurable
  See the MQ2CrashCallBack function and GetCrashDialogMessage

30 Jan 2017 by eqmule
- Added ${MacroQuest.Build} it returns an int where LIVE = 1 TEST = 2 BETA = 3 and EMU = 4
- Added Start EQBC Server to the tray icon menu.

29 Jan 2017 by eqmule
- I finally had time to sit down and look at the crash reporting
  it has been given a major overhaul
  you will know what I mean next time you crash.
  Please READ the crash message carefully.
  Do what it says. Or not.

24 Jan 2017 by eqmule
- Fix for ${Me.HaveExpansion[Empires of Kunark]} crash - cred maskoi
- A few changes to mq2chatwnd to deal with potential memleaks - cred Derple

21 Jan 2017 by eqmule
- Updated for TEST

20 Jan 2017 by eqmule
- Fixed a bug in the EQINVSLOTWND struct where slots where WORD instead of short
  this will take care of any remaining problems with /itemnotify
- stuff in progress, nothing to see here yet...
- Fixed a buffer overflow in the UPCNotificationFlush_Detour -Thanks Maskoi

19 Jan 2017 by SwiftyMUSE
- Fixed BuffStackTest to correctly test spells with triggering spas.

18 Jan 2017 by eqmule
- Updated for LIVE
- Bunch of other stuff, thanks Brainiac for the arrayclass mod
- Exp has been changed to a __int64, because, well it is, and has been for a few years...

14 Jan 2017 by SwiftyMUSE
- Corrected potential crashes in the following routines: GetAdjustedSkill, GetBaseSkill, GetModCap, 
  GetCastingTimeModifier, GetFocusCastingTimeModifier, GetFocusRangeModifier, HasSkill, MakeMeVisible.
- Corrected a bug in BuffStackTest when checking triggering spas.

13 Jan 2017 by SwiftyMUSE
- Added SkillBase to character. This will give you the static base maximum for your skills.
- Updated Skill and SkillCap to handle the new TS aas allowing for above the cap values.

13 jan 2017 by eqmule
- Added ${Macro.MemUse} it returns a pIntType letting u know how much memory your macro is using.
  its useful if you suspect you have a leak.
- Ok so here is a NEW FEATURE which was brought to us by Brainiac, Thanks Brainiac!
  It allows us to extend any existing TLO's in our own plugins.
  Example:
  You want to add a new member to for example the character TLO
  named .CursorKrono which tells you how many Krono you have on your cursor
  you could then do /echo ${Me.CursorKrono}

  Below is a plugin example for how you would do this: (tags added for forum post to show up correctly)
[CODE]
// MQ2ExtensionTest.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.


#include "../MQ2Plugin.h"

PreSetup("MQ2ExtensionTest");

//----------------------------------------------------------------------------
// test the mq2 datatype extension code

class MQ2CharacterExtensionType* pCharExtType = nullptr;

class MQ2CharacterExtensionType : public MQ2Type
{
public:
	enum ExtensionMembers {
		CursorKrono = 1,
	};
	MQ2CharacterExtensionType() : MQ2Type("MQ2TestCharacterExtension")
	{
		TypeMember(CursorKrono);
	}
	bool GETMEMBER()
	{
		PMQ2TYPEMEMBER pMember = FindMember(Member);
		if (!pMember)
			return false;
		switch (pMember->ID)
		{
			case CursorKrono:
			{
				if(PCHARINFO pCharInf = GetCharInfo()) {
					Dest.DWord = pCharInf->CursorKrono;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}
	bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
	{
		return false;
	}
	bool FromData(MQ2VARPTR& VarPtr, MQ2TYPEVAR& Source)
	{
		if (Source.Type != pCharExtType)
			return false;
		VarPtr.Ptr = Source.Ptr;
		return true;
	}
	bool FromString(MQ2VARPTR& VarPtr, PCHAR Source)
	{
		return false;
	}
};
PLUGIN_API VOID InitializePlugin(VOID)
{
	pCharExtType = new MQ2CharacterExtensionType;
	// This is where you add it to an existing TLO
	// in this case the one named "character" aka our ${Me} tlo...
	AddMQ2TypeExtension("character", pCharExtType);
}
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	//dont forget to remove it on plugin shutdown...(aka plugin unload)
	RemoveMQ2TypeExtension("character", pCharExtType);
	delete pCharExtType;
}[/CODE]

12 Jan 2017 by eqmule
- Updated for TEST
- ZonePoint in the DOORS struct has been renamed to SpellID

06 Jan 2017 by SwiftyMUSE
- Updated spell effects display
- Updated buff stacking testing

06 Jan 2017 by eqmule
- Fixed the _EQCASTSPELLGEM struct, thanks JimBob
  this should make features that relies on the spellicon and spellstate members of that struct work again.
- Updated the TEST build so its synced with LIVE.
- Added some new Spawn TLO members: (DISCLAIMER:  I reserve the right to remove/alter and or depreciate any of these as I'm still testing this stuff.)
	IsBerserk (pBoolType), pTouchingSwitch (pIntType), bShowHelm (pBoolType), CorpseDragCount (pIntType), bBetaBuffed (pBoolType), CombatSkillTicks[x] 0-1 (pIntType), 
	FD (pIntType), InPvPArea (pBoolType), bAlwaysShowAura (pBoolType), GMRank (pIntType), WarCry (pIntType), IsPassenger (pBoolType), 
	LastCastTime (pIntType), DragNames[x] 0-1 (pStringType), DraggingPlayer (pStringType), bStationary (pBoolType), BearingToTarget (pFloatType), bTempPet (pBoolType), 
	HoldingAnimation (pIntType), Blind (pIntType), LastCastNum (pIntType), CollisionCounter (pIntType), CeilingHeightAtCurrLocation (pFloatType), AssistName (pStringType), 
	SeeInvis[x] 0-2 (pIntType), SpawnStatus[x] 0-5 (pIntType), bWaitingForPort (pBoolType)

- SolventNeeded in the iteminfo struct has been renamed to SolventItemID 
- Added some new members to the iteminfo struct and cleaned it up a little.
- Added MQ2AugType TLO, it has these members: Slot (pIntType), Type (pIntType), Visible (pBoolType), Infusable (pBoolType), Empty (pBoolType), Name (pStringType), Item (pItemType)
- New Member: AugSlot added to the item TLO 
  it returns a pAugType
  Usage: (Items can have MAX 6 slots for augs so... [x] can ONLY be 0-5)
        /echo ${Cursor.AugSlot[0].Type}
        /echo ${Cursor.AugSlot[1].Visible}
        /echo ${Cursor.AugSlot[2].Infusable}
        /echo ${Cursor.AugSlot[3].Empty}
        /echo ${Cursor.AugSlot[4].Name}
        /echo ${Cursor.AugSlot[5].Item.Purity}
- Added 2 new commands: /removeaug and /insertaug to the mq2itemdisplay plugin
  type /removeaug or /insertaug for help
  /removeaug will pop a dialog if a perfect augmentation distiller needs to be used...
  I would be extremely careful with these 2 commands unless you understand
  how they work... if you augment the wrong item or remove an augment from the wrong item or whatever... its not my fault.
- Added the MQ2WorldLocationType TLO it has the following members: ID (pIntType),Y (pFloatType), X (pFloatType), Z (pFloatType),Heading (pFloatType), Zone (pZoneType),
- Added BoundLocation to the Charatcer TLO its size is 0-4 for up to 5 bind points.
  Usage:
		 /echo ${Me.BoundLocation[0].ID} returns the zone id of your first bind point
		 /echo ${Me.BoundLocation[1].ID} returns the zone id of your second bind point
- Changed pChar2->ZoneBoundX it's now pChar2->BoundLocations[0].ZoneBoundX; 
          as well as all the other ->ZoneBo****** members.

20 Dec 2016 by eqmule
- Updated for TEST

18 Dec 2016 by eqmule
- OK ILL PUT THIS FIRST SO YOU DON'T MISS IT:
- I have changed ALL instances of GuildID to __int64 (cause DBG did)
  PLEASE! be aware of this change as it WILL break some plugins.
  NOW, as for macros: IF your macros uses ${Me.GuildID} NOTE that it returns a pInt64Type
  from now on.
  This is the reason I have added 2 new members to the pInt64Type TLO
  Namely: .LowPart and .HighPart
  SO: IF you have a macro that relies on GuildID being 4 bytes...
  Then you NEED to change it from: ${Me.GuildID} to ${Me.GuildID.LowPart}
  mkay...
- Now onto the fixes:
- FIX: /pet attack <id>
- FIX: barter and trader "tells" no longer trigger beepontells
- FIX: /mqclear no longer crashes
- FIX: /itemnotify "name of item" lefmouseup can pick up
  items from top level slots once again.
- For completeness sake I also added .LowPart and .HighPart to the pIntType TLO

15 Dec 2016 by eqmule
- Fix: double timestamps in the eqlog is no longer happening so you can turn on /timestamp again.
- Fixed a bug in FindItem and its derivatives where it needed signed parameters.
- Fixed the EQINVSLOTWND struct, it was off by a few bytes.
  Yes that means .InvSlot will once again "work" (dont effing use it. in your macros, use ItemSlot and ItemSlot2)

14 Dec 2016 by eqmule
- GuildID in SPAWNINFO is a __int64 now... not by my design, it just is
  I have tried to make it backwards compaible with the spawn guild tlo which is still a DWORD
  report any bugs related to this change on the forum. Plugins are gonna have to be updated accodingly.
- Fix Errors like this for example: error C2660: 'GetGuildByID': function does not take 1 arguments
  char  *pGuild = GetGuildByID( GetCharInfo()->GuildID ); becomes
  LARGE_INTEGER guildlarge = {0};
  guildlarge.QuadPart = GetCharInfo()->GuildID;
  char  *pGuild = GetGuildByID( guildlarge.LowPart,guildlarge.HighPart );

- I started correcting the iteminfo struct it's a work in progress so expect more changes to fully implement this.
- Initially the Augment members has gotten a review (and a fix since they where broken)
- So... AugSlot1 etc is now part of its own class
- therefor:
- pitem->AugSlot1 is now pitem->AugData.Sockets[0].Type
- and so on...
- pitem->AugSlot1_Visible is now pitem->AugData.Sockets[0].bVisible
- and so on...
- CListWnd no longer inherits CSidlScreenWnd BUT it has access to the CXWnd class members.
- CComboWnd no longer inherits CSidlScreenWnd BUT it has access to the CXWnd class members.
  Fix Errors like these:
  list->Items becomes list->ItemsArray.Count
  CListWnd*pListWnd = (CListWnd*)pCombo->Items becomes CListWnd*pListWnd = pCombo->pListWnd (it was kinda confusing before, but less so after this change)

13 Dec 2016 by SwiftyMUSE
- Updated GetClassesFromMask to display "ALL" or "ALL EXCEPT:" when appropriate based on the class
  mask.

08 Dec 2016 by eqmule
- Updated for TEST
- Fixed a bug where FindItem and all its derivatives wouldn't look deeper than 20 slots into a bag.
  Now it doesn't matter how many slots a bag has, it is dynamic.
- I #pragma pack(8) where I need it now, dont change them.
- In preparation for automatic updating of the CONTENTS struct
-  I HAD to reorganise it.
-  Therefor:
-	NumOfSlots1 has been renamed to ContentSize Ths also effects macros that use the NumOfSlots1 member.
-	NumOfSlots2 has been renamed to Size

-	MOST of these changes affect core only, I dont think there will be many plugins that needs updating
-	BUT here are some examples of how to fix errors that I have seen:
-	change:
-	pItem->ItemSlot TO pItem->GlobalIndex.Index.Slot1
-	cSlot->pContentsArray TO cSlot->Contents.ContainedItems.pItems
-	cSlot->pContentsArray->Contents[iPack] to cSlot->GetContent(iPack)
-	pInvSlot->pContentsArray TO pInvSlot->Contents.ContainedItems.pItems
-	pInvSlot->pContentsArray->Contents[ucPack] TO EITHER:
-	pInvSlot->Contents.ContainedItems.pItems->Item[ucPack] OR SIMPLY JUST
-	pInvSlot->GetContent(ucPack) BOTH return the exact same thing.

06 Dec 2016 by SwiftyMUSE
- Fixed up the new SPA descriptions in spell display

28 Nov 2016 by eqmule
- Fixed ${Me.ManaRegen}
- CButtonWnd now inherits CXWnd (cause it does).
- GetItemTimerValue has been renamed to GetItemRecastTimer
- Removed ManaGained, HealthGained, EnduranceGained from Pulse() and the exports.
  Use GetEnduranceRegen(), GetHPRegen() and GetManaRegen() instead.
  This change should make Pulse() a bit faster since we dont check that stuff constantly.

20 Nov 2016 by SwiftyMUSE
- Fixed bug waiting for familiars keyring to load

19 Nov 2016 by SwiftyMUSE/eqmule
- Updated for TEST
- Added GuildID and ExpansionFlags to MQ2CharacterType
- Added support for familiars keyring in /cast and /useitem

17 Nov 2016 by eqmule
- Added ${Me.Vitality} ${Me.PctVitality} ${Me.AAVitality} ${Me.AAVitality}
- Fixed CampfireDuration
- Fixed the Task tlo
- Fixed ${Me.Exp} and ${Me.PctExp}
  Thanks to william12 for reporting these bugs.

16 Nov 2016 by eqmule
- Updated for LIVE
- Reorganized SPAWNINFO to reflect how its laid out in memory.
- Feet in Spawninfo has been renamed to FloorHeight
- AvatarHeight2 in Spawninfo has been renamed to Width
- HoldingType in Spawninfo has been renamed to HoldingAnimation
- InnateETA in Spawninfo is now part of SpellGemETA as its LAST member because... well it should be.
- GetMeleeRangeVar2 has been renamed to MeleeRadius
- Class in the spawninfo struct has been moved to its correct location which is inside ActorClient.
  Therefor: (and I know people will post even though the answer is right here)
  ITS NOT pSpawn->Class anymore, its now pSpawn->mActorClient.Class
  same thing goes for Race.
  pSpawn->mPlayerPhysicsClient.Levitate instead of pSpawn->Levitate
  pSpawn->mPlayerPhysicsClient.pSpawn instead of  pSpawn->pSpawn

- mkay...

14 Nov 2016 by eqmule
- Updated for BETA
- GetSpellEffectNameByID fixed to not return a temp buffer - cred HTW
- ReadWindowINI in MQ2AdvPath correctly read the ini but never set the window value
  this has been corrected - cred Brainiac
  a zip which has the corrected version in it is located here : http://www.macroquest2.com/phpBB3/viewtopic.php?f=29&t=11451&p=172713#p172713

- Corrected the zoneinfo struct 
  What we previously had been refering to as "ZoneType" was not in fact it, so it has been renamed to FOgOnOff which is what its for.
  This means that ${Zone.Type} has changed a bit...
  it now returns 0-5 see the EOutDoor enum for more info. And whoever wants to update the wiki should refer to that.
  in short: 0=Indoor Dungeon 1=Outdoor 2=Outdoor City 3=Dungeon City 4=Indoor City 5=Outdoor Dungeon

13 Nov 2016 by eqmule
- Added some missing members to the test cxwnd struct
- Fixed the 4Byte error.

12 Nov 2016 by eqmule
- Updated for TEST

12 Nov 2016 by SwiftyMUSE
- Updated spell effects display

11 Nov 2016 by eqmule
- Updated for BETA

10 Nov 2016 by eqmule
- Updated for BETA
- In preparation for the expansion on the 16th and for future faster patching,
  THE FOLLOWING STUFF has undergone some serious changes:
  You have 5 days to adjust your personal builds and plugins.

- BGColor is now a COLORREF change plugins accordingly.
  and no, it CANNOT be changed back to a ARGBCOLOR since that contains a union with bytes and that screws up the 4 aligned padding.
- UnknownCW has been renamed to CRNormal change plugins accordingly.
- Locked is now a bool
- TimeMouseOver has been renamed to FadeDelay
- dShow is now a bool
- We are using 4 byte alignemnt from now on, set ur plugins to 4 byte alignment.
- ONE MORE TIME, WE ARE NOT USING 1 byte ALIGNMENT ANYMORE.
- the CXWnd struct grew somewhat to make patching of it easier for me.
- Fixed a bug in MQ2EQBC that would crash u on /unload
- The following plugins has had changes made to them:
	MQ2AvdPath.cpp
	MQ2DPSAdv.cpp
	MQ2EQBC.cpp
	MQ2Melee.cpp
	MQ2MoveUtils.cpp
	MQ2Spawns.cpp
- They are located in this post: http://www.macroquest2.com/phpBB3/viewtopic.php?f=29&t=11451&p=172713#p172713

10 Nov 2016 by SwiftyMUSE
- Updated RankName to find an exact match for name. The results from Spell.ID and Spell.RankName will now be
  from the same spell (if it exists in the spellbook).

09 Nov 2016 by eqmule
- Updated for BETA

08 Nov 2016 by eqmule
- Updated for TEST
- Updated for BETA

04 Nov 2016 by eqmule
- Updated for BETA

03 Nov 2016 by eqmule
- Updated for BETA

02 Nov 2016 by eqmule
- Updated for BETA

01 Nov 2016 by eqmule
- Updated for BETA

31 Oct 2016 by eqmule
- Updated for BETA

30 Oct 2016
- Updated for BETA -eqmule
- ChatWindow will again allow itself to be hidden behind other windows when ingame. -SwiftyMUSE

29 Oct 2016 by eqmule
- Updated for BETA

28 Oct 2016 by eqmule
- Updated for BETA
- ChatWindow is now top dog at charselect and will no longer go awol there.
- ChatWindow will no longer crash at charselect when it's children are clicked.
- Made some changes to MQ2DInput.cpp in preparation for going full scale c++
  since CINTERFACE is going bye bye in a future update.

27 Oct 2016 by eqmule
- Updated for BETA

25 Oct 2016 by eqmule
- Updated for BETA

24 Oct 2016 by eqmule
- Updated for BETA

22 Oct 2016 by eqmule
- Updated for BETA

21 Oct 2016 by eqmule
- Updated for BETA

19 Oct 2016 by eqmule
- Updated for LIVE
- Updated for BETA

18 Oct 2016 by eqmule
- Updated for BETA

15 Oct 2016 by eqmule
- Updated for BETA

13 Oct 2016 by eqmule
- Updated for BETA
- Updated for TEST

12 Oct 2016 by eqmule
- Updated for BETA
- Added CharSelectList to the EverQuest TLO, it only has 1 member for now: ZoneID
  it returns the zoneid the character is currently in.
  Usage: /echo Im at charsselect and ${Window[CharacterListWnd].Child[CLW_Character_List].List[1,3]} is in ${EverQuest.CharSelectList[1].ZoneID}
  Output:  (if a char named Eqmule is the first in your charlist) Im at charselect and Eqmule is in 202
  OR:
  /echo Im at charsselect and Eqmule is in ${EverQuest.CharSelectList[Eqmule].ZoneID}
  Output: same as above.

11 Oct 2016 by eqmule
- Updated for BETA
- I had a lot to do and it was difficult to get this working, so it's not tested properly.
  I basically wanted to get it out before they patch again.

01 Oct 2016 by eqmule
- some new stuff added to the map by JudgeD
	/mapactivelayer
	/maploc
	/clearloc
	see this post for more info: http://www.macroquest2.com/phpBB3/viewtopic.php?f=17&t=19987

29 Sep 2016 by eqmule
- Added fellowship to the spawnsearch tlo - Idea Cred: mwilliam
  Example usage:
   /if ${SpawnCount[fellowship loc ${Me.X} ${Me.Y} radius 50]} >= 3) {
		/echo its ok to place a campfire now.
   } else {
		/echo not enough fellowship members here to place a campfire right now
   }
- RemoveBuff now accepts buffnames that are quoted "some buff"
- pinstCSystemInfoDialogBox HAS BEEN RENAMED TO pinstCLargeDialogWnd cause thats what it is.
- /loginchar server:charname will now launch eq and log the char in.
  NOTE: if you run this command and server:char is already running, you will kill his game and
  he will be logged in again, this command ALWAYS launches a new client.
  this is for advanced users only, I use it personally to launch and get back into a game when 
  one of my clients has crashed. (easily detected with the ${Group.Member[soandso].Offline} tlo member... or lets say I havent seen the guy for 15 minutes)
  NOTE2: this command only works if you are using the mq2 login system and have a profile for the character.
  Example: /loginchar tunare:eqmule
  will search all mq2 profile sets for the tunare server and the char eqmule
  if it finds it, it will launch eq and log in that character.
- The ~ key should now be able to cycle full screen windows and in order - SwiftyMUSE

21 Sep 2016 by eqmule
- Updated for LIVE

18 Sep 2016 by eqmule
Sunday is funday... so here is some fluff:
- Added a "Boss Mode" hotkey, alt+~, (alt+tilde) if u click that all your eq windows will be instantly hidden. It's a toggle.
  the hotkey can be changed in the [MacroQuest] section, the value is called BossMode=
  setting BossMode=0 disables it.
- You can now "cycle" eq windows now with the '~' key.... (also known as tilde)
  its not obvious but you CAN change it by editing the macroquest.ini
  in the [MacroQuest] section add a CycleNextWindow=somekey
  Example: (and this is what it defaults to when this entry does not exist)
           CycleNextWindow=shift+`
  u can do alt+ and ctrl+ as well but thats it.
  you cannot combine alt+shift+, i didnt want to make this to complex.
  you CAN however drop the prefixes altogether and just specify it as
  CycleNextWindow=b
  that would make the lettere "b" on your keyboard cycle the windows... (not recommended unless u plan on never using the letter b for any other reason...)
  Setting CycleNextWindow=0 will disable it completely.
----- fluff end -----
- /loadspells no longer "loads them" even when a load technically isn't needed. -code cred: Vyco Dynn
- Fixed a bug related to keyring locations.

16 Sep 2016 by eqmule
- Fixed a crash bug in listwnd::addstring for the test build -report cred: fry
- ISXEQ once again compiles... sorry about the long wait.
  BIG NOTE: it now includes ISXDK 35, this means you should use VS 2015 with toolset 140 to build it.
  one thing though... mq2ic doesnt load for some reason for it
  I have contacted Lax and hope we can figure out a workaround.
  Bottomline... yeah... you CAN build isxeq now...
  but its not protected by mq2ic, so run at your own risk.
  I really didnt want to wait any longer to get something out.
  but if you are the paranoid type, id hold off a couple more days
  until we can figure out a way to load it...

15 Sep 2016 by eqmule
- Updated for TEST
- The Loader now detects if a profile is loaded or not and reloads if needed if clicked,
  prior to this update sessions that u did /unload in game for had their profile name set
  as character (Loaded) and if you clicked such a profile, it would not reload.
- Fixed a bug in GetItemContentsByName
- Fixed a bug in GetItemLink -cred demonstar55 and SwiftyMUSE
- Added a new parameter to FindItemBySlot so we can specify which locations to search.
- NEW FEATIRE: The EverQuest TLO has a new member .LastMouseOver
  it returns a windowtype of the last window the mouse was hovering.
  Want to know the name of a window or its children? Tired of doing /windows and look through a list of a million windows?
  Well now it's easy:
  Example: Place the mouse over a window and do a /echo ${EverQuest.LastMouseOver.Name}
  Example2: /echo ${EverQuest.LastMouseOver.Tooltip}
- NEW FEATURE: Added .MouseOver to the Group TLO
  Usage1: /echo Im hovering my mouse over ${Group.MouseOver.Name} which has ths spawnid: ${Group.MouseOver.ID}
  Usage2: /bct ${Group.MouseOver.Name} hi there I dont want to change my target just to tell u: please heal ${Me.Mame}
  Usage3: /bct eqmule //casting "Complete Heal" -targetid|${Group.MouseOver.ID}
  Usage4: /bct ${Group.MouseOver.CleanName} //setprio 2
  Final Note: YOU CAN hover over your own name in the player window where u see your hp and it will return you.
  There are many more usages for this im sure...
- Fixed GetItemLink
- Fixed AltAbilityReady to only return true for active abilities - cred desgn
- Fixed multiple buffer overflows all over the place in core.
- Note to self:
  The following plugins has had some kind of modification made to them to work with this release:
  MQ2Twist, MQ2SpawnMaster, MQ2LinkDB, MQ2EQBC I should post them on the forum.
  NavigationType.cpp MQ2Netheal.cpp MQ2SpawnMaster.cpp MQ2Twist.cpp


02 Sep 2016 by eqmule
- Reverted a "fix" to the /while command that instead of fixing it made it worse
  im not happy with this command, im gonna have to spend more time on it.

01 Sep 2016 by eqmule
- Misc Fixes to improve stability.
- The Launcher can now launch single sessions without logging u in, i basically just "launches clean"
  rightclick the "Launch Clean" menu item to toggle starting eqgame in suspended mode (for power users)
- The Launcher can now export and import login profiles.
- Added some missing itemtypes.
- The ALTABILITY struct has gotten an overhaul
  CurrentRank is now GroupLevel
  RequirementCount is now RequiredGroups
  RequiresAbility is now RequiredGroupLevels
  grant_only is now QuestOnly
  next_id is now NextGroupAbilityId
  last_id is now PreviousGroupAbilityId
  PointsSpent is now TotalPoints
- PLUGIN AUTHORS: GetAAById has a second parameter, its level, use it or it will default to -1 this is only important when you try to find a aa by name.
	example:
	int level = -1;
	if (PSPAWNINFO pMe = (PSPAWNINFO)pLocalPlayer) {
		level = pMe->Level;
	}
	if (PALTABILITY pAbility = pAltAdvManager->GetAAById(index, level)) {
- I added a wrapper for GetAAById so we can build emu builds.
  its called GetAAByIdWrapper and is exported.

- CTargetWnd__UpdateBuffs is now CTargetWnd__RefreshTargetBuffs (cause it is)
- Bunch of other stuff

17 Aug 2016 by eqmule
- Updated for LIVE
- TRUEBOX nerfed.

15 Aug 2016 by SwiftyMUSE
- Updated to include CreateHtmlWnd in base code. You can now load MQ2Web and MQ2NoNag in the same session.

12 Aug 2016 by eqmule
- Updated for TEST
- EzDetour is now EzDetourwName all EzDetour( calls should be replaced to use the new EzDetourwName
  I did this because debugging /unload crashes is much easier now.
  EzDetour is still in the compile for awhile to give everyone time for the transition but expect it to be gone in due time.
- Misc updates, fixed a bug in macroquest2.exe which would prevent loading profiles that where not checked.
  made edit and delete work on (Loaded) profiles
- Fixed a bug in mq2autologin which would prevent it from working correctly if eqmain was already loaded on its initialization.
- TRUEBOX will not load mq2eqbc, mq2cast, mq2moveutils or mq2melee anymore. It proved to be to much of an nuisance to me and other players.
  And frankly too much negative attention is bad for mq2 as well. I'll take full responsibility for what went down, and I dont want that again.
  We didn't create mq2 to get people banned, we created it to add utility.
  TRUEBOX is likely to be scrapped altogether on the 17th although i might resurrect it in another form in the future.
  BUT IF we ever go down this path again, expect only utility like audio triggers and maybe a dpsparser, think GINA and gamparse etc.

9 Aug 2016
- Added .LayoutCopyInProgress to the EverQuest TLO
  it returns TRUE if a layoutcopy is in progress and FALSE if not.
- Fixed a couple buffer overflow bugs.
- Misc stuff.

8 Aug 2016 by eqmule
- The integrity checker is now 714% faster (or something).
- Updated mq2autologin, its not going to crash you ever again (well in theory at least)
  So, look, mq2autologin has been overhauled, and I also figured out where the serverids
  are being stored, this means that from now on you can place server shortnames in the mq2autologin.ini
  and as long as they have a server LONGNAME that matches what you see in the server select list it will be able to log you in.
  This is particularly useful on emulator login servers that assign dynamic IDs.
  NOTE2: for live servers, like tunare and drinal for example, those really ARE the real shortnames so I use those.
         BUT for emu servers, I have no idea what their shortanmes are, sometimes they dont even use a "short name", but instead, they use like a really long one with
		 spaces in it and so on, so I HIGHLY recommend you stick to a short name with no spaces in it, especially IF you are using the new MQ2 login feature on
		 the tray icon because eqgame only accepts 30 character commandlines so having a really long "shortname" will definaltely break that type of login for you...
		 bottomline, the mq2 login feature doesn't really care if the shortname is fake or real, it will use whatever is in your profile when it look them up in the ini.
  NOTE3: for live and test servers, obviously the static id of those servers is still valid, and mq2autologin will still be able to look those up internally
  like it always have, this new ini setting is mainly for emu servers, but you can of course add any server u like, even live ones.
  so without further ado here is an:
    Example of a [Servers] section in mq2autologin.ini (note that I have no idea if these servers even allow mq2, this is just an example)
	[Servers]
	tunare=Tunare - The Seventh Hammer
	drinal=Drinal - Maelin Starpyre
	firiona=Firiona Vie (Roleplaying Preferred)
	peqtgc=[] [PEQ]The Grand Creation [legit-god]
	ezserv=[] EZ Server - Custom Zones, Vendors, Quests, Items, etc
	stormhav=[] Storm Haven - High-Quality Custom Content
	alkabor=[] The Al'Kabor Project [www.takproject.net]

25 Jul 2016 by eqmule
- THE BIG #pragma warnings SHOULD DIE patch...
- I have removed the #pragma warnings for depreciated string functions.
- This will absolutely break ALL your plugins.
- I am available on skype to help you fix every single one. eq.mule
- This is NOT going to be easy, but I have posted updated plugins
  on macroquest2.com in every thread that I had plugin source for.
- When you get WARNINGS while buidling this version, IT MEANS, you need a fix.
- DO NOT I REPEAT DO NOT ADD A PRAGMA TO FIX IT
- I'm seriously going to go ballistic if i see any more #pragma warnings
  If a #pragam warning is needed we are doing it wrong.

- So... the whambulance will be comming for sure when you update to this version.
  Sorry about that, but it was needed because I'm sick of all the buffer overflows
  that are crashing us randomly and I can never get a good call stack in order to fix them.
  This fix is years overdue, and I consider it crucial in order to move forward
  towards a 100% stable mq2.

- Anyway... I made a whole bunch of stuff stringsafe
  too much to list, if u have plugins that wont build
  post about it or message me and ill help u fix them.
  Here is a link to a post that has all my personal versions of the plugins I use, that I have fixed for this release:
- http://www.macroquest2.com/phpBB3/viewtopic.php?f=50&t=20053
- pMQ2Blech is no longer an export, create your own Blechs, cause hooking into that one is no longer an option.
  (this means mq2moveutils need to be updated see above link for updated plugins.)

13 Jul 2016
- Updated for LIVE
- Updated for TRUEBOX
  Yes... you can probably bypass my code thats in place to make a TRUEBOX version that
  has all the stuff the LIVE one has, but I am appealing to your decency now.
  Please dont. We have a good thing going with dbg now and I hate to see that ruined by someone
  for their own personal gain. -eqmule
- 
- To build a TRUEBOX version of mq2, uncomment //TRUEBOX in mq2main.
- If I find out that people are abusing this newfound power, I WILL have no other choice than
  moving more stuff into mq2ic, please dont make me do that. I like to keep mq2 as open
  as possible.

12 Jul 2016
- Updated for TEST
- winter is comming.

06 Jul 2016
- Updated for LIVE
- You can now enable/disable MQ2login from the tasktray menu.

02 Jul 2016
- Added a check for "You have a character logged into a world server as an OFFLINE TRADER from this account" to mq2autologin
- Added a check for "failed login attempts on your account since the last time you logged in."  to mq2autologin
- Added a check for "This login requires that the account be activated.  Please make sure your account is active in order to login"  to mq2autologin
- Added a check for "Error - A timeout occurred"  to mq2autologin

- Added a setting for the "Trade when you have something on the cursor and click on the name of the target in the target window" feature
  its in macroquest.ini as UseTradeOnTarget. default is 1. (on)

01 Jul 2016
- Updated for TEST
- The Create new Profile window no longer closes after u create a profile.
  you can close it on the [X] when you are done adding profiles, this was a requested feature.
- To celebrate that it looks like we are getting all our accounts back, I decided to comply with some users requests
  so I:
- Added a popupmenu to the Profilemenu on the trayicon
  you can now rightclick the profile and you will see Edit, Delete and Check/Uncheck
  The browse button is active now as well.
  Happy Boxing!, this should make it easier.

30 Jun 2016
- Updated for TEST
- Updated MQ2AutoLogin.cpp - cred: derple.
- Updated Blech - cred derple
  change was done to fix a crash in blech.
- Fixed Spell Dmg in MQ2ItemDisplay - cred: dewey2461
- Misc Stuff to improve stability.
- Changed the way Profile for Login works, you will need to recreate your profiles. -cred: dewey2461
  Im really sorry about that, but its better we get this done now than in 6 months
  when it will affect more people.
  This is new feature to me as well, and im doing my best to make it work the way people want it,
  based on the feedback I get.
  The good news is, next version will have a browse to path button (that works)
  an edit and a delete option for the profiles, this change lays the groundwork for that.

28 Jun 2016
- MQ2AutoLogin is now part of the core zip
- NEW FEATURE: Profiled Logins:
	Basically it's a new menu on the task icon called Profiles.
	The first time you click it you will see a Create New... menu item.
	You click it and a small window asking for 5 things will pop up.
	Server, login, pass, character name and path to eqgame.exe
	Once you have that filled in you click an OK button and your profile will be encrypted and saved in mq2autologin.ini
	You can save as many profiles as you want and they will sort per server on the menu.
	Each server profile has a Load/Unload All option so once you have added all your accounts for a server you just click the Load All and away it goes,
	it will login all of the characters under that server. (Well all that are check marked)

- Check marks: each character can be marked for loading by simply right clicking the character name to toggle it marked on or off.

- Loading individual accounts:
	You just left click on a character name and if it is check marked, it will load and the name will be changed to <Charname> (Loaded)

- Unloading individual accounts:
	If a char is loaded and has the text (Loaded) behind it you just left click it to unload.
	I kept this as simple as I possibly could so its a Toggle.

- I can add window positioning and stuff I guess but for now it's just a easy way to login a box team on a server.

- Batch Files and hotkeys:
	If you currently use batch files or hotkeys or whatever, those should still be usable if you don't want to click the menu.
	Example: (this example assumes you HAVE profiles created with "Create New..." in mq2autologin.ini)
	Batch file can launch your accounts by sending the server_charname to the eqgame client like this: <path to eqgame.exe> patchme /login:drinal_eqmule
	And that's really all there is to it... You would of course change the server and Charname to your server and your char (drinal and eqmule)

- Encryption:
	I strongly recommend getting this setup though, because it encrypts your password in a way that in "theory" makes it only decryptable on YOUR computer,
	this means that even if you accidently post your mq2autologin.ini somewhere, or someone gets hold of it, the information inside it will be useless to them.
-	Finally, no, you don't "HAVE" to use this feature, mq2autologin is backwards compatible to handle any old way you feel more comfortable with.


22 Jun 2016
- Updated for LIVE
- Updated for TEST
- BeepOnTells and FlashOnTells fixed to not beep and flash on pet tells.
- Added .ScreenMode to the EverQuest TLO, it returns the ScreenMode as a integer.
- Added a new command: /screenmode which sets the screenmode.
  Usage: /screenmode <#> Where 2 is Normal and 3 is No Windows
  This is experimental, I noticed you can decrease the memory footprint by setting it to 3 and then back to 2
  in 3 only the main window is drawn and I suspect memory gets freed then.

17 Jun 2016
- Added .PPriority to the EverQuest TLO, it returns the Process Priority as a string.
- Added a new command: /setprio which sets process priority (like in Task Manager)
  Usage: /setprio <1-6>
  Where 1 is Low 2 is below Normal 3 is Normal 4 is Above Normal 5 is High and 6 is RealTime
  Example: You need to build something quick in Visual Studio
  just do a /bcga //setprio 2 and it will zoom by real fast.
- Added .Corrupted and .Cursed to the Me. and Target. TLO's

16 Jun 2016
- Fixed the ISXEQ build errors.
- Fixed a few arrays related bugs:
- ${Me.Book[0]} will now return NULL again instead of assuming the macro author meant ${Me.Book[1]}.
  This fix should make macros and some plugins that relied on NULL returns for invalid tlo member usage work again.
  (hint: there is no such thing as ${Me.Book[0]} all macro arrays start at 1... but whatever...)
- Fixed a /unload crash in mq2autologin
  it has been posted here: http://www.macroquest2.com/phpBB3/viewtopic.php?f=50&t=16427

15 Jun 2016
- Updated for LIVE
- Added xtarhater to the spawnsearch tlo - Idea Cred: Maskoi
  Example usage:
   /if (${SpawnCount[npc xtarhater loc ${Target.X} ${Target.Y} radius ${Spell[Deadening Wave Rk. II].AERange}]} >= ${SpawnCount[npc loc ${Target.X} ${Target.Y} radius ${Spell[Deadening Wave Rk. II].AERange}]}) {
		/echo its ok to cast the aemez it wont aggro more mobs than whats on xtarget.
		/casting "Deadening Wave Rk. II"
   } else {
		/echo if you cast your aemez now, you will agro more mobs than are on your xtarget, which would be stupid.
		/casting "Bewilder Rk. II"
   }
- Fixed a bug in .RankName which would cause it to return the wrong spell.

10 Jun 2016
- .MyCastTime in the spell TLO is now a timestamptype (cause it is)
  OK FINE... LOOK THESE THINGS WILL BREAK "SOME" MACROS:
  Since I changed all these recast and cast timers and so on in the last few days
  A LOT of macros will break...
  Sorry about that but these timers should never have been floats in the first place
  and we better get this done now or it will cause problems down the road for us, when we add new stuff.
  TO DEAL WITH THIS I have Added .Raw to the timestamp TLO it will just output total milliseconds
  And IF you really need the old Float output I also added .Float
  this will allow you to still see things as floats if that's what you prefered.
  Example: /echo ${Me.Book[1].MyCastTime.Float}
  Output: 1.50

09 Jun 2016
- Updated for TEST (yes really)
- Added .DurationValue1 to the Spell TLO
- Changed the way /unload and re/inject works, those things are now part of the Processgame detour
  that should prevent some crashes related to us interfering with the window drawing.
  In fact direct calls to eqgame functions from mq2start or any other thread is asking for trouble.
  This change should minimize that behaviour.
- .CastTime in the spell TLO is now a timestamptype (cause it is)
- .RecoveryTime in the spell TLO is now a timestamptype (cause it is)
- .FizzleTime in the spell TLO is now a timestamptype (cause it is)

  See yesterdays changes for an example of usage using .RecastTime

09 Jun 2016 by SwiftyMUSE
- Additional updates for spell effects

08 Jun 2016
- Sorry TEST players this update is NOT for todays TEST patch. Expect one tomorrow.
- Added .IsSkill to the spell tlo
- Fixed a crash in Me.CombatAbility when doing ${Me.CombatAbility[0]}
- Fixed some potential crashes that could occur because of signed/unsigned integer misuse.
- Added .DoOpen and .DoClose Methods to the Window TLO
  Usage: /echo ${Window[somewindow].Child[somechild].DoOpen}
  Expected Result: it will echo TRUE and open it.
- Addded .NumGems to the character TLO it returns the number of spellgems you currently have.
  Usage: /echo ${Me.NumGems}
  Expected output for a level 1 character: 8
  Expected output for a level 105 character which has Mnemonic Retention AA at rank 4: 12
- .RecastTime in the spell TLO is now a timestamptype (cause it is)
  Usage: /echo ${Spell[Steadfast Stance Rk. II].RecastTime.TotalSeconds}
  Expected Output: 150

01 Jun 2016
- fixed a bug that would always return NULL instead of TRUE or FALSE
when doing ${AdvLoot.SList[x].AlwaysGreed} - cred hoosierbilly

25 May 2016
- Updated for TEST

24 May 2016
- Updated for TEST

23 May 2016
- Updated for TEST

22 May 2016
- Updated for TEST

18 May 2016
- Fixed a crash in MQ2itemDisplay
- Fixed a crash in merchinfo (/mac scribe)

18 May 2016
- Updated for LIVE
- /echo now accepts colorcodes -cred htw see http://www.macroquest2.com/phpBB3/viewtopic.php?f=47&t=17141&p=152508#p152508
- Fixed a few bugs related to aa indexes.
- Dont make a big thing out of this but:
- /caption now takes a new argument "anon"
  You can use this to anonymize your session.
  It was brought to my attention that there was an interest in recording/streaming video - cred: maskoi
  while at the same time protecting the privacy of the player as well as other players.
  NOTE 1: This is cosmetic and LOCAL only, in other words NOT AN ACTIVE HACK.
  NOTE 2: You are NOT anonymous to other players OR the server.
  NOTE 3: I recommend leaving this option OFF at all times unless you really need to use it, because it WILL use a lot of cpu time.
  NOTE 4: The mq2labels plugin need to be loaded for the "full anonymity effect".
  NOTE 5: Chat is NOT anonymized at all. Although if people want that, we can certainly make it happen in a future update.
  Usage: /caption anon on
- And finally see changes for test in changes below from 13 May 2016, they apply to LIVE now as well.

13 May 2016
- Updated for TEST
- Note that the following Values was removed from the ITEMINFO Struct in the TEST build:
  	.Accuracy
	.StrikeThrough
	.Avoidance
	.DoTShielding
	.SpellShield
	.StunResist
	.CombatEffects
	.Shielding
	.DamageShieldMitigation
	Its unlikely that these will return, but I will know in a few days when I have had more time to investigate this.
	I *MIGHT* create wrapper functions for these values like ((EQ_Item*)pItem)->GetAccuracy();.
	BUT IF YOU HAVE PLUGINS OR MACROS THAT USE THESE VALUES: //Comment them out for now...
	I will know more before this stuff gets pushed to the LIVE client next week...
- Updated for LIVE

12 May 2016 by SwiftyMUSE
- Finally... move the NetStatus indicator on the screen. You are no longer limited to the upper left corner.
  Using NetStatusXPos and NetStatusYPos these will be added the to default (0,0) coordinates to allow placement
  at other areas on the screen.
- Added commands /netstatusxpos, /netstatusypos to update the (x,y) screen coordinates for the NetStatus indicator.

10 May 2016
- Updated for TEST
  This will get u in game, but there are still some stuff that needs fixed, 
  the Caps needs calced for example.
  I just wont spend to much time on it now, since one or more repatches are likely.

08 May 2016
- Maintenance release PART II:
- Added .IsSwarmSpell to the Spell TLO, it return TRUE/FALSE if a spell is a swarmspell or not.
 Usage: /echo ${Spell[Chattering Bones].IsSwarmSpell}
 Output: TRUE
- Fixed the offset for EQ_PC__GetCombatAbilityTimer_x (again)
- Fixed another crash in mq2map.

06 May 2016
- Fixed a crash in mq2map. Thanks to everyone that sent in crash dumps.
- Fixed a /unload crash.

04 May 2016 by SwiftyMUSE
- Added to Zone TLO
  ZoneType, NoBind, Indoor, Outdoor, Dungeon
- Added to Spawn TLO
  EQLoc, MQLoc
- Added to Spell TLO
  Location

02 May 2016
- Maintenance release PART I: I highly recommend everyone update to this release.
- NEW STUFF:
- Added ${Me.ItemReady[xxx]} it returns a bool true or false, it was 10 years overdue, and yes i know we can check it with Item Timer but
  I like the consistency of having SpellReady, AltAbilityReady, CombatAbilityReady and now ItemReady
  it also makes it easier to remember to macro writers. -Idea cred: Maskoi
- Usage: /echo ${Me.ItemReady[=worn totem]}
- will look for an item name that exactly matches "worn totem" and return true if its ready to click/cast/use and false if not.
- Usage: /echo ${Me.ItemReady[drunkard]}
- will look for an item name that has the word "drunkard" in it and return true if its ready to click/cast/use and false if not.
- the item name is not case sensitive.

- CHANGES:
- MacroQuest2.exe should once again be winxp compatible.
- ${Me.AltAbilityTimer[xxxx]} does NOT return a pTickType anymore, its NOW a pTimeStampType, so update your macros.
- Changed the name of __bCommandEnabled_x to g_eqCommandStates_x (cause thats what it is)

- FIXES:
- Created a wrapper for ExecuteCmd cause it has 4 paramters now, and i didnt want to break plugins.
- This should fix multiple crashes as well as the "mash hotkeys too quickly crash". (yes that was likely us)
- Fixed the offset for EQ_PC__GetCombatAbilityTimer_x
- Corrected the _ZONEINFO struct(s)
- Corrected the function declaration for CSidlScreenWnd::GetChildItem note that it takes 2 arguments now.
- Corrected the function declaration for CXWnd::GetChildWndAt note that it takes 3 arguments now.
- Corrected the function declaration for CXWnd::Move (for the CXWnd__Move1_x offset).
- Corrected the function declaration for EQPlayer__DoAttack_x on EMU builds.

26 Apr 2016
- Updated for TEST
- Removed fancy progressbar message for now, it might return or not, dont know yet but im hunting a memory leak so... we'll see.

23 Apr 2016
- Fixed a crash in ${Merchant.Item[x]}

22 Apr 2016
- Updated for LIVE

20 Apr 2016
- Updated for LIVE

15 Apr 2016
- Fixed broken spell stuff for TEST - cred demonstar55
- Added support for specifying buildtype (TEST/LIVE/BETA/EMU) in the preprocessor.
- Updated Macroquest.exe to only inject in the right eqgame.
  Example: you have macroquest loaded in the tasktray from your
  Releast(test) directory it will not try to inject into a live eqgame session.
  if you have live macroquest running and start eqgame for test it will not try
  to inject into the live client.
  This means you can have 2 macroquest.exes running and they will only inject in
  the exe that mq2main.dll is built for. (it knows what dir it was started from).

14 Apr 2016
- Updated for TEST
- Fixed ${Me.AbilityReady[Taunt]} and other abilites not on hotkeys so they work even when not "hotkeyed"
  Thanks mwilliam for the bug report
- Added some more items to actordef.

12 Apr 2016
- Updated for TEST

11 Apr 2016
- Fixed /face to use pCharSpawn instead of pLocalPlayer
  this should make moving work while mounted again... sorry about that...

07 Apr 2016 by SwiftyMUSE
- Updated Charmed, Brells to correctly identify buffs on yourself.

07 Apr 2016
- Updated for TEST

06 Apr 2016
- Updated for TEST

02 Apr 2016
- Updated for TEST
- Added the missing members to the Spell struct. - demonstar55

01 Apr 2016
- Updated for TEST

31 Mar 2016
- Moved the charinfo pIllusionsArray cause it was in the wrong place.
  This prevented FindItem from finding items in the illusion keyring.

30 Mar 2016
- I think I got Advloot under control now, go for it, test it as hard as u can.
- Added a new Member .LootInProgress to the AdvLoot TLO
  use it or face imminent doom!
  Usage Example:
  [code]
  /if (!${AdvLoot.LootInProgress}) {
		/echo its safe to loot
		if (${AdvLoot.SCount}>=1) {
			/echo im going to give 1 ${AdvLoot.SList[1].Name} to myself
			/advloot shared 1 giveto ${Me.Name} 1
		}
  } else {
		/echo do something else, loot is in progress...
  }
  [/code]

29 Mar 2016
- Made some adjustments to make advloot more stable
- Made some adjustments to doors , thanks htw

25 Mar 2016
- Fixed GetFriendlyNameForGroundItem to support instanced zones
- Misc fixes

24 Mar 2016
- Fix for ISXEQ build, it will compile again, report any weirdness on the forum.
- Fix to make /itemtarget select the closest item first
- Update to /items and /doors so they sort by Distance3D
- Updated /doortarget let me know if it fails to target
- Updated /click left door let me know if u find a door it cant open.
- Added a .DoTarget Method to the Ground TLO
  Usage: /if (${Ground[egg].DoTarget.ID}) {
               /echo we just targeted a ${Ground[egg]}
         }
- Added a .DoFace Method to the Ground TLO
  Usage: /echo (${Ground[egg].Doface.Distance3D}) {
  Will face the closest item on the ground which has the word "egg" in it.
  and then echo the distance to it in the mq2 window.
  well if it finds an item with the word "egg" in it on the ground that is, otherwise it will just echo NULL
  .DoFace does NOT target the ground item, it just faces it.

- Changed how /items <filter> work, its now case insensitive and takes any part of a word into account
  Usage: /items egg will display all items on the ground that has the word "egg" in them.
- Changed how /doors <filter> work, its now case insensitive and takes any part of a word into account
  Usage: /doors pok will display all doors in the zone which has the word "pok" in them.


23 Mar 2016
- Updated for LIVE
- WARNING! Task TLO has changed, update your macros.
- Well, I was gonna release the new Task TLO in the next zip
  but then dbg decided to patch so you guys get whatever I could finish
  before I had to release the zip.
  It needs more documantation and definately more testing as well,
  but I can say this much for now:
  /echo Task 1 is ${Task[1]}
  Output: Task 1 is Hatching a Plan
  /echo The task with "hatch" in is name is called: ${Task[hatch]} 
  Output: The task with "hatch" in is name is called: Hatching a Plan
  /echo ${Task[hatch]} is listed as number ${Task[hatch].Index} in the tasklist.
  Output: Hatching a Plan is listed as number 1 in the tasklist.
  /echo The ${Task[hatch]} first objective is to ${Task[hatch].Objective[1].Instruction}
  Output: The Hatching a Plan first objective is to find where the eggs are being incubated
  /echo The ${Task[hatch]} first objective status is ${Task[hatch].Objective[1].Status} 
  Output: The Hatching a Plan first objective status is 0/1
  /echo The ${Task[hatch]} first objective should be completed in ${Task[hatch].Objective[1].Zone}
  Output: The Hatching a Plan first objective should be completed in Hatchery Wing
  /echo I should be working on ${Task[hatch].Step} in ${Task[hatch].Step.Zone}
  Output: I should be working on find where the eggs are being incubated in Hatchery Wing
- Added .Type to the Task TLO: it outputs a string Quest or Shared depending on the task:
  Usage: /echo ${Task[hatch].Type}
  Output: Shared
- The Task TLO also has a .Select "Method" (see below for an explaination of TLO methods.)
  .Select can select list items and combobox items.
  .Select returns TRUE if a selection was made and FALSE if not.
  Usage: /if (${Task[hatch].Select}) {
			/echo I just Selected a task that has the name "hatch" in it...
		} else {
			/echo I did not find a task that has the word "hatch" in it, so nothing was selected.
		}

- Fixed a racecondition crash in mq2bzsrch.
- Fixed a plugin unload/load crash
- Made some changes to mutex locks.
- Fixed the loot and the trade struct for the test build.
- Added a new command /invoke to invoke TLO Methods...
  Basically we have had TypeMethods in the source for years, but it was never finished.
  Consider these methods beta for now.
  So from the command line or hotbuttons you can do stuff like: /invoke ${Spawn[eqmule].DoTarget}
  and it will execute the DoTarget method of the Spawn TLO... (and /target eqmule IF it finds that spawn)
  In macros it should make things more simple but at the same time add more power
  because now you can do stuff that saves a few lines, like:
  /if (${Spawn[eqmule].DoTarget.ID}) {
		/echo i just targeted ${Target}
  }
  or
  /if (${Spawn[eqmule].DoFace.ID}) {
		/echo i just faced eqmule
  }
  the following Methods are available for use and testing as of this patch:
  For the Task TLO:
	.Select
  For the Spawn[]. TLO:
	.DoTarget
	.DoFace
	.DoAssist
	.LeftClick
	.RightClick
  For the Me. TLO:
	.Stand
	.Sit
	.Dismount
	.StopCast
  For the Me.Buff TLO Member:
	.Remove
  For the Switch TLO:
	.Toggle
  For the Ground TLO:
	.Grab
  For the Window TLO:
	.LeftMouseDown
	.LeftMouseUp
	.LeftMouseHeld
	.LeftMouseHeldUp
	.RightMouseDown
	.RightMouseUp
	.RightMouseHeld
	.RightMouseHeldUp
	.Select

- And finally, there seem to be some problem with /click left door
  I will have a look at that tomorrow.

17 Mar 2016
- Fixed a crash in the ${Merchant} TLO
- Fixed a crash in the ${Task} TLO

16 Mar 2016
- Updated for LIVE
- Added a new TLO: GroundItemCount
  usage: /echo There are ${GroundItemCount[apple]} Apples on the ground
  Output: There are 5 Apples on the ground
- usage: /echo There are ${GroundItemCount} items on the ground in this zone.
  Output: There are 12 items on the ground in this zone.
- Extended the Ground TLO to accept searches
  usage: /echo The closest ${Ground[brew].DisplayName} is ${Ground[brew].Distance3D} away from you.
  output: The closest Brew Barrel is 26.4 away from you.
  Note that both of the searchfunctions are case insensitive and are sorted by distance colosest to you.
  The only acceptale parameter in the search filter is by name or partial name.

- Added .Distance3D and .DisplayName to the Ground tlo
  DisplayName will display the actual name of the ground item, .Name will still display the actorname...
  ${Ground} now defaults to ${Ground.DisplayName} instead of ${Ground.ID}
- Doortargets as well as GroundTargets are now cleared when you do a /target clear

15 Mar 2016
- Maintenance Release, bunch of cleanups and stuff that should improve overall stability.

-Updated all vcxproj files and solutions to use build.props for easier administration - Cred: brainiac

- Fixed Me.Dar, Me.Counters, Buff Dar and Buff Counters - Cred: Demonstar55
- Community can provide input if we should separate them into their elements.
- For now they return combined, which might be useless.

- FRIENDLY DEV TIP OF THE DAY:
- Some people has been asking me how to run VS as admin by default in windows 8-10:
- There is a simple trick to it, and I recommend that everyone do this, but
- especially if you are going to debug MQ2 OR build ISXEQ because it needs
- to copy files to your InnerSpace directory and that is usually located
- under Program Files (which requires admin privs).
- Anyway... to do this, paste the following link in your browser:
- http://lmgtfy.com/?q=make+visual+studio+always+run+as+administrator
- When you have followed those steps, navigate to this directory:
- C:\Program Files (x86)\Common Files\Microsoft Shared\MSEnv
- Now locate the VSLauncher.exe in that dir, rightclick it, select properties
- Go to the compatability tab, and check the "Run this proram as an administrator" box.
- Click ok. That's it. From that point on, your VS will always start itself as admin.

12 Mar 2016
- Updated for TEST

09 Mar 2016
- Updated for TEST
- New SPA's added
- IsBodyType has been renamed to HasProperty (cause thats what it is)
- Bunch of changes to mq2windows, lets see if it works as intended.

- Added a new TLO Member to ${Me} .AssistComplete
. You can check it after you do a /assist. It will be true when the assist request has been completed.
.  Usage Example: /assist Eqmule
.                 /delay 5s ${Me.AssistComplete}==TRUE
.				  /if (${Target.ID}) {
.				      /echo EqMule wants me to help fighting ${Target}
.				  }
- Turned on Exception Handling (/EHsc) for all projects except mq2main
- when we move to the v140xp toolset we can use the noexcept keyword to turn it on for mq2main as well...

- --------------------> VERY IMPORTANT STUFF BEGIN <-------------------
- It's time to upgrade to Visual Studio 2013 Community or newer.
- From this version and onward we will not support older compilers.
- There just isn't any good reason now that Microsoft has free Community Editions
- which can build mq2 just fine.
- Therefor:
- All vcxproj files has been updated to use the vs2013 toolset (v120xp) (thanks Brainiac)
- We want to move to 2015, but we will have to wait until ISXDK supports that version.
- If you use 2015, just install the vs 2013 community edition if you want to build ISXEQ
- For mq2 it doesn't really matter, you can build it with 2015 toolset (v140 or v140xp)
- just let it upgrade if it asks for it.

- Older solution files has been removed:
- For building MQ2 use MacroQuest2.sln
- --------------------> VERY IMPORTANT STUFF END <---------------------

- If you have no interest in building ISXEQ you can stop reading now.

- For building ISXEQ use ISXEQ.sln PLEASE NOTE: --------------->
- The red headed stepchild ISXEQ has gotten some love this week.
- You might have noticed that the zip grew a bit in size this release
- the reason is that it now includes all files needed to build ISXEQ.
- So...
- This means that from now on, you can just open ISXEQ.sln and build it.
- DO NOT LET IT UPGRADE THE TOOLSET! it only works with the v120xp toolset.
- Having said that, No more additional downloads, googling for libs, headers, updating paths
- patching files, reading pages and pages of forum threads, and all that extra
- shiz that we all love to spend time on...
- In other words we made it easier to build ISXEQ "out of the box" (aka the zip)

24 Feb 2016
- Updated for TEST
- Changed how GroupAssistTarget and RaidAssistTarget works
  before this change you could get a return that was invalid when no mainassist was assigned.
  since I make sure there actually is a mainassist in the group or raid
  this is no longer possible.
- Fixed /pickzone so picks above 9 can be picked - cred: derple

19 feb 2016
- Added .BuffsPoplulated to ${Target}
-  Usage example:
-  /target pet
-  /delay 5s ${Target.ID}==${Pet.ID} && ${Target.BuffsPopulated}==TRUE
-  /echo ${Target} has ${Target.BuffCount} buffs on him.

- Trampoline following - cred: brainiac

18 Feb 2016 by SwiftyMUSE
- Updated to make GetNumSpellEffects inline.
- Updated MQ2Map to use layer 2 again.
- Updated more groundspawn names.

17 feb 2016
- Updated for LIVE
- I refer you all to the change message from 12 feb 2016
  the changes described in it, now applies for LIVE build as well.
- Fixed SpellReady so it's 111% reliable now.

14 feb 2016 HAPPY VALENTINES DAY!
- Removed most of the holes I punched in the source with #if defined(TEST) in the last version cred: brainiac
- Updated some stacking code cred: demonstar55
- Fixed SpellReady so it's 110% reliable now.
- minor fixes

12 feb 2016
- Fixed SpellReady so it's 100% reliable now.
- Other stuff
- Updated for TEST
- BELOW THIS LINE ARE TEST RELATED CHANGES, BUT LIVE BUILDERS SHOULD READ IT AS WELL (cause it is comming your way)

- Added CalcIndex to ${Spell} (on TEST)
- Added NumEffects to ${Spell} (on TEST)
-  Both of them SHOULD be used in macros that enumurate Base, Base2, Calc,Attrib and Max
-  Example: lets say your macro does this:
-		/for i 1 to 12
-			/echo Base ${i} is : ${Spell[Augmentation].Base[${i}]}
-		/next i
-	FROM NOW ON: IT SHOULD LOOK LIKE THIS: (or you will get errors running it)
-		/varcalc count ${Spell[Augmentation].NumEffects} + 1
-		/for i 1 to ${count}
-			/echo Base ${i} is : ${Spell[Augmentation].Base[${i}]}
-		/next i
-							

- Ok, listen PEOPLE WHO BUILD MQ2 FOR -> TEST <- : this is IMPORTANT!:
-  This patch punched a bunch of holes in mq2, and Im telling you folks right now:
-  IF YOU DONT UPDATE YOUR PLUGINS THEY WILL Fail to build.
-  ok and here is how to update them:
-  Search EVERY single plugin you have for references to ->Base[, ->Base2[, ->Calc[, ->Attrib[ and ->Max[
-  Replace EVERY result with a proper call to the corrosponding new APIs:
-	LONG GetSpellAttrib(PSPELL pSpell, int index);
-	LONG GetSpellBase(PSPELL pSpell, int index);
-	LONG GetSpellBase2(PSPELL pSpell, int index);
-	LONG GetSpellMax(PSPELL pSpell, int index);
-	LONG GetSpellCalc(PSPELL pSpell, int index);
-	Let me give and example: You do the search and you find this code:
-	for (int a = 0; a < 12; a++) {
-		switch (spell->Attrib[a])
-	YOU MUST replace that code... with this:
-	if (PSPELL spell = GetSpellByID(SpellID)) {
-		for (int a = 0; a < GetSpellNumEffects(spell); a++) {
-			switch (GetSpellAttrib(spell, a))

-	Notice what I did there? you CANNOT and SHOULD NOT use hardcoded "12" anymore
-	It just isn't how spell effects are stored anymore, they only store
-	the ACTUAL number of effects in memory, not all 12 slots...
-	So... the new Spell member function GetSpellNumEffects(x) SHOULD ALWAYS be used from now on.

-	Mkay? questions?, come talk to us on irc/skype/email whatever...
-	And finally, for the LIVE people... this is comming your way within a week or so when
-	they patch for LIVE, so get ready, cause I'm not going to repeat this info again.
-  This message will self destruct in 3...2...1...

28 Jan 2016
- The changes to the Task TLO from the Jan 14 patch has been reverted, they where not ready for production yet.
- Me.Pet has been fixed for TEST along with a bunch of other spawninfo offsets that where all off.
- Me.Trader has been fixed for LIVE
- Me.Buyer has been fixed for LIVE
- Added Poisoned and Diseased to ${Target}
- Added Poisoned and Diseased to ${Me}
- RewriteMQ2Plugins has been removed, it was a dangerous function that could set all plugins to 0 if you crashed while doing /plugin someunstableplugin unload
- RewriteMQ2Plugins has been replaced with SaveMQ2PluginLoadStatus
- Added Krono to ${Me}
- Added XTargetSlots to ${Me}
- Misc other fixes.
- Stuff

22 Jan 2016
- Updated for TEST
- Updated for LIVE

20 Jan 2016 by MacroQuest2.com Devs
- Updated for LIVE
- Fixes to the task tlo by dewey2461 see: http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=19912
- New feature map highlights see http://www.macroquest2.com/phpBB3/viewtopic.php?f=17&t=19895
  code cred: JudgeD

17 Jan 2015 by MacroQuest2.com Devs
-Added CursorPlatinum,CursorGold,CursorSilver and CursorCopper to the ${Me} tlo

16 Jan 2016 by MacroQuest2.com Devs
- Fixed Open in the CONTENTS struct
- Added .Open to the itemtype, it works for containers. its a boolean.

14 Jan 2016 by MacroQuest2.com Devs
- Updated for TEST
- Added a new feature. cred: dewey2461
- Description: Extends the Task TLO with the TaskElementList's Objective[ ]

- The TaskElementList is a row,column address where column 0 is the text, 1 is the status, etc.

- Examples: 

- /echo ${Task.Objective} The first objective
- /echo ${Task.Objective[0]} The first objective
- /echo ${Task.Objective[0,1]} The first objective's status
- /echo ${Task.Objective[0,2]} The first objective's zone
- /echo ${Task.Objective[1]} The second objective

16 Dec 2015 by MacroQuest2.com Devs
- Updated for LIVE
- Change: LoreGroup and LinkDBValue in the CONTENTS struct has been renamed
  to GroupID and OrnamentationIcon (cause thats what they are)
  Make changes to your plugins if you use them.
- switches got some love - thanks brainiac.

14 Dec 2015 by SwiftyMUSE
- Added Slowed, Rooted, Mezzed, Crippled, Maloed, Tashed, Snared, Hasted, Aego,
	Skin, Focus, Regen, Symbol, Clarity, Pred, Strength, Brells, SV, SE,
	HybridHP, Growth, Shining, Beneficial, DSed, RevDSed, Charmed to ${Target}
- Added Aego, Skin, Focus, Regen, Symbol, Clarity, Pred, Strength, Brells, SV, SE,
	HybridHP, Growth, Shining, Beneficial, DSed, RevDSed, Charmed to ${Me}
- Updated MQ2Linkdb code to generate links for most all items (98.04% of lucy items)
- Added new groundspawns for MQ2Map

12 Dec 2015 by Eqmule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST

09 Dec 2015 by Eqmule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE
- Dont try to use mq2 or any other third party tool on the Phinigel server.
  Consider this a friendly warning.

08 Dec 2015 by Eqmule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Misc Buffer Overflow fixes.

07 Dec 2015 by Eqmule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST

05 Dec 2015 by Eqmule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST

03 Dec 2015 by Devs
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Updated mq2ic for isxeq, copy it to your extensions folder and isxeq will load it for you.

02 Dec 2015 by Devs
- Well... This is probably the most important update to MQ2 in years.
  Recent changes to the client released with the new Broken Mirror expansion
  added a new type of MQ2 detection which is meant to prevent mq2 usage on the new Phinigel server.
  We fully support the NO MQ2 policy on Phinigel, and we want to continue
  supporting that policy and backup DBG any way we can that’s within reason.
  We have therefor decided to add a new type of integrity checker to MQ2.
  We have placed the code in a MQ2 plugin that has been named MQ2Ic.dll. (MQ2 Integrity checker)
  We feel strongly that MQ2 is in a symbiosis with Everquest, and it’s important to us
  that all MQ2 users feel safe while they use MQ2.
  MQ2 users are an important part of the Everquest community and we wish to keep it that way.
  In short, we recommend you keep MQ2Ic.dll loaded while you are playing Everquest.
  It will protect your integrity on all servers EXCEPT Phinigel.
  It will be included in every zip from now on, and will be maintained by active mq2 devs.
  Its usage is optional though, and you can unload and load it like any other plugin, but it comes loaded by default.
  This plugin will also fix some recent plugin issues and crashes as well as improve the fps performance.
  All questions about this plugin should be directed to eqmule@hotmail.com

26 Nov 2015 by EqMule and Braniac
- HAPPY THANKSGIVING EDITION!
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Fixed a few annoying issues with mq2 message wrapping multiple lines in tools like DebugView. -Brainiac
- Updated ITEMINFO. AugRestrictions was in the wrong place.
- Added code to ${Target.AggroHolder} so it returns yourself as well as other now.

23 Nov 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed some ISXEQ stuff
- The following commands now work in ISXEQ:
  - /beepontells
  - /flashontells
  - /timestamp
  - /click left door (remember to do /doortarget before u do that though)
  - /click left item (remember to do /itemtarget before u do that though)
  - /click left target
  - /click right target
  - /useitem "some item" (or partial name) or without the quotes... this one works for items in keyrings as well (illusions, mounts)

22 Nov 2015 by EqMule and Demonstar55
- Please don't use MQ2 for unattended gameplay (afk botting)
- Added .Index to the AltAbility TLO.
- Added .NextIndex to the AltAbility TLO.
- Added .CanTrain to the AltAbility TLO.
  Usage: /if (${AltAbility[Companion's Aegis].CanTrain}) /alt buy ${AltAbility[Companion's Aegis].NextIndex}  
- Added a few new APIs:
- AltAdvManager::CanSeeAbility
- AltAdvManager::CanTrainAbility
- PcZoneClient::HasAlternateAbility
- Added the /pick # command to the ISXEQ build.

20 Nov 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Updated for LIVE

19 Nov 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed the /ranged crash

18 Nov 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE
- Updated for TEST
- Change the MQ2MountType TLO has been renamed to MQ2KeyRingType
  it works exactly like the mount tlo would, but it also take illusions now
  so u can do:
  Usage: /echo ${Mount[1].Name}
  Outputs: [MQ2] Whirligig Flyer Control Device
  Usage: /echo ${Illusion[2].Name}
  Outputs: [MQ2] Polymorph Wand: Steam Suit
  Usage: /echo ${Illusion[Polymorph Wand: Steam Suit].Index}
  Outputs: [MQ2] 2
- New Feature: you can now use /useitem on illusion items even if they are in the keyring
  usage: /useitem Polymorph Wand: Steam Suit
- Change: there used to be a value in the itemstruct called CastTime
  I noticed it was actully FoodDuration, so it has been renamed.
  If you have any plugins that used "someitem->CastTime" from that struct,
  you need to change that to whatever you intend it to do, cause for whatever
  reason you have been using it up til this point, you have gotten FoodDuration back...
  Im guessing that was a bug, and you really wanted someitem->Clicky.CastTime instead...
  so adjust accordingly.

11 Nov 2015 by EqMule and Demonstar55
- Please don't use MQ2 for unattended gameplay (afk botting)
- BIG NEWS!
- After a really long time, messing with this on and off
  I'm proud to present support for splash spells in the cast command.
  You can now cast any splash spell as long as you have a target.
  If you dont have a target it will just cast it at your own location.
  There is no need for window in focus, or full screen or any of that stuff
  you dont even have to be facing the target.
  Basically the only requirement is that its in lineofsight and in range.
  The splash feature was brought to you as a joined effort
  with Demonstar55 as the main contributor, his tireless dissasembling
  and reverse engineering as well as updates on the progress on skype, irc etc
  was a major help in bringing this to you all, so give him a shoutout!
  I need to mention ctaylor22 as well for pushing me to work on it at all.
  Anyway... enjoy.
- Added a new member to the Spawn TLO: CanSplashLand, it returns true or false
  usage: /echo ${Target.CanSplashLand}
  I suggest you use this tlo member in your macros BEFORE you try to cast a splashspell
  there is no point in casting it if it wont land due to a line of sight problem.
  NOTE! This check is ONLY for line of sight to the targetindicator (red/green circle)
  its NOT a range check, you need to check range yourself like for every other spell
  before you cast it...
  
01 Nov 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for BETA

31 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for BETA

30 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for BETA
- Misc other stuff

29 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for BETA
- Fixed some ISXEQ code

 28 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Updated for BETA

26 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE
- Updated for BETA
- Misc other stuff

25 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for BETA
- Misc other stuff

24 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Updated for BETA
- Corrected address of AugRestrictions in the iteminfo struct

23 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- note that /useitem <some mount> doesnt work in the beta client yet, ill see what i can do...
- Added .SkillModMax to the ItemType TLO
- Fixed a crash in mq2map when doing /loadskin

21 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE
- Fixed and cleaned a bunch of small stuff but it is possible I broke some stuff as well,
 report if u find something that worked in last zip and not in this one.
- ${DisplayItem} now takes an index as an option parameter index can be 0-5
  you can still just do ${DsiplayItem} and it will just pick whatever you inspected last.
  Example: /echo ${DisplayItem[5]}
- Added a few new members to the DisplayItem TLO:
		Info = 1,
		WindowTitle = 2,
		AdvancedLore = 3,
		MadeBy = 4,
		Information = 5,
		DisplayIndex = 6
  There is a difference between .Info and .Information .Info contains for example:
  .Info can return text like; this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
  .Information can return text like Item Information: Placing this augment into blah blah, this armor can only be used in blah blah

17 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Fixed a few VS 2015 compile warnings.

07 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Added some stuff to the ALTABILITY struct, cred demonstar55
- Renamed AARankRequired to CurrentRank in the ALTABILITY struct
- Added .PointsSpent to the altbility TLO it returns points you spent on an AA
- Added .Rank to the altbility TLO it returns current rank of an AA
- Reminder: .MaxRank in the altbility TLO it returns max rank of an AA
- I'm sorry (not really) but in my ongoing efforts to clean up the API
  I had to rename a couple functions, so take notice and go over your plugins:
  mq2cast and mq2melee calls these for example. See below:
- Renamed GetAltAbility to GetAAById (cause thats what it is)
- Renamed GetAltAbilityIndex to GetAlternateAbilityId (cause thats what it is)

01 Oct 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed a bunch of POSIX stuff
- Made sure Target.Buff and Target.BuffDuration now works on spells without having to specify Rank
  example: /echo ${Target.BuffDuration[Pyromancy]} would FAIL prior to todays patch
  now it wont.
  example 2: /echo ${Target.Buff[Pyromancy]} would return NULL prior to todays patch
  now it returns the correct name including its rank: so Pyromancy XV for example...

30 Sep 2015 by EqMule (ALERTS AND MORE ALERTS AND STUFF)
- THIS IS A MACROBREAKING PATCH! (so read these notes)
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed .Mercenary in the spawnstruct for TEST -cred demonstar55
- GetGuildIDByName now returns 0xFFFFFFFF and not 0x0000FFFF if a guild is NOT found, so if you use this function in a plugin adjust acordingly.
- Fixed a problem with searching through spawns for guild members
  This might break you macros so pay attention!:
  Prior to THIS patch there was a difference in CASE with guild/GUILD in spawn searches:
  IF you wanted to search for a spawn like this:
  /echo ${Spawn[radius 75 pc guild noalert 6]}
  THAT WOULD MAKE MQ2 THINK the guild you where looking for was called "noalert" 
  now if that was not your intention, you should have used UPPERCASE GUILD instead
  and it would just search for people in YOUR guild.
  In order to not use this confusing method of searching through spawns
  I have decided to rename lowercase guild to guildname
  so from this point and onward, you CAN specify guild OR GUILD and it will just pick your own guild
  in order to search for players of a specific guild use "guildname" and note that if there are spaces in the guildname you need encase with "".
  Example: ${Spawn[radius 75 pc guildname "Some Cool Guild" noalert 6]}
- Added a new TLO: ${Alert}
  it has 2 members: List which returns a AlertListType and Size which returns a IntType
  Usage Example 1: /alert add 1 ${Me.Name}
		 /echo ${Alert[1].List[0].Name}
		 Outputs: eqmule
		 /echo ${Alert[1].List[0].Spawn.Race}
		 Outputs: Dark Elf (or whatever my Class is)
  Usage Example 2: /alert add 1 id ${Me.ID}
         /echo ${Alert[1].List[0].SpawnID}
		 Output: 12345 (or whatever my spawnid is)
         /echo ${Alert[1].Size}
		 Output: 2 (or whatever size your alert list for 1 is)
  Usage Example 3: /alert remove 1 id ${Me.ID}
         removes the list entry from alert 1 that matches: id ${Me.ID}
- Added a new TLO Type: MQ2AlertListType which has the following members:
  well it has a crapload of members look at the source to list them but basically
  it has all the members SEARCHSPAWN has plus one extra that I call Spawn
  Spawn inherits the spawntype see the example above...
  Note that: .Spawn will only work if your alert has either .Name or .SpawnID set.
- Bunch of other stuff fixed/added/fightclub/updated/rewritten etc.
- ${Spell[some spell]} now looks through your aa list as well if it cant find a spell
  I did that to take the new ranks into account for example prior to this patch
  /echo ${Spell[Boastful Bellow].Range} would fail because the Boastful Bellow spell
  has been renamed to Boastful Bellow I
  anyway the fix is now in and it also means .RankName will return ranks for these kinds
  of alt abilities.

25 Sep 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST again... (cmon man are u trying to kill me?!!, scowls at hludwolf ready to attack ;)
- So... when they patch at 8.30pm I have 2 choices:
  1. wait until the morning and go over it manually.
  2. run a quickpatch, cross fingers and release without proper testing.
  Well, I did 2. and went to bed, I guess it didnt work as intended
  uhm, so the structs has been corrected, castready and so on
  should be working again...

24 Sep 2015 #2 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE

24 Sep 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Corrected the wwsCrashReportCheckForUploader_x offset and detour. :cred SwiftyMUSE

23 Sep 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE

19 Sep 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- fixed a compile error in CustomPopup when building isxeq. 

19 Sep 2015 by SwiftyMUSE
- Updated autorun to allow for all toons instead of having to specify them individually.
  I did not change the /autorun command which is used to set the autorun value for the current
  toon.
  Eg., add ALL=<command> under [Autorun]
- Modified ground spawn detection to allow the value based on the actual zone.
- Updated pluginhandler to fix a timing issue with running zoned.cfg.

17 Sep 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- DmgBonusType in the itemstruct has been renamed to ElementalFlag (because thats what it is)
- DmgBonusVal in the itemstruct has been renamed to ElementalDamage (because thats what it is)
  if you have plugins that refer to these make sure u rename as well.
- the size of the _AGGROINFO struct changed. Cred: demonstar55
- Added .Icon to the MQ2ItemType TLO
- Added Scroll to the mouseinfo struct. Thanks Brainiac,
- Fixed a crash in /windowstate that could happen when using a (bad) Custom UI. Thanks demonstar55
- since GetCombatAbilityTimer now accepts -1 as a timer, I have removed that check
  this means you should remove it from mq2melee as well for example:
  this line: if (EFFECT->ReuseTimerIndex && TYPE != AA && EFFECT->ReuseTimerIndex != -1)
  becomes this: if (EFFECT->ReuseTimerIndex!=0 && TYPE != AA)

26 Aug 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- New feature: you can now search spawns by if they are aggresive or not
  for more info see this post by demonstar55 http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=19813
- Added new command: /removepetbuff
  it will remove a pet buff by name or partial name.
  Usage: /removepetbuff Spirit of Wolf
  Feature requested by: standred
- New Commands: /popcustom and /popupecho
  for more info on these 2 commands see this post: http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=15800&p=142608#p142608
  Cred: PMS
- Added new TLO member for the Character TLO: SpellInCooldown
  it returns TRUE if you have a spell in cooldown and FALSE when not.
  Cred:demonstar55 see this topic for more info: http://www.macroquest2.com/phpBB3/viewtopic.php?f=47&t=19689

21 Aug 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST
- Updated for LIVE
- Made a few changes to how the zoned.cfg is processed
  hopefully that should fix a crash I have gotten reports about.
  *crossing fingers*

19 Aug 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for LIVE
- This is a heads up:
  In the near future I will restrict /target to a radius of 360
  I do this because its unreasonable to target stuff across zones.
  There is absolutely no scenario where you have a reason to target a mob
  until its within that range. So change your macros now if they do this.
  If you have line of sight to a mob there will be no radius restriction.

14 Aug 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST

08 Aug 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for ninjapatch.
- Updated mkplugin.exe mkplugin.cpp and ISXEQ\PostBuild.bat with changes by D2U
  See http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=19790
- Updated TelnetServer.cpp with changes by rmaxm
  See http://www.macroquest2.com/phpBB3/viewtopic.php?f=28&t=19793
- Updated the _LOOTITEM struct with addition by dewey2461
- Bugfix: ${Me.Inventory[someslot].Augs} now returns correct number of augslots the item has.
  example: /echo My gloves has ${Me.Inventory[Hands].Augs} augslots.
  NOTE: I dont know how this worked in the past, but this only counts how
  many augslots an item has, it doesnt check if there is actually an augment
  in the slot...
  Cred: Nytemyst for the report.
- Updated MQ2ItemDisplay.cpp with changes by dewey2461
  Added ${GearScore.UpgradeName}
  Added ${GearScore.UpgradeSlot}
  See http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=19792

03 Aug 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed a 10 year old bug where GetSpellDuration would use pCharSpawn (which can be a level 30 mount)
  instad of the correct pLocalPlayer (which is actually your characters spawn with correct level)
  the impact of this would be that spells that scale their duration by the level of the caster
  would return a shorter duartion when on a mount...
  example: doing /echo ${Spell[Enticer's Command].Duration.Minutes} on a level 105 enc would return 4 when on a mount and 7 when not
  bug report: Maskoi

24 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for todays TEST ninja patch
- Fixed a struct that would crash eq if mq2hud was used.
- same struct messed up keypresses as well...
- /mouseto is back... and thats all I have to say about that at 
   this point, more on this some other time.

23 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for todays LIVE ninja patch

2 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for todays LIVE client

21 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for the TEST client
- Fixed a bug with finding items in bags for the test build.

16 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for TEST build.
- Removed SetForegroundWindow from the FlashOnTells feature.
  (it was not working as intended when using ISBoxer)
  It will still flash the window.

15 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- New Command: /flashontells
  You can use it to turn flashing of the eq window on or off when you recieve a tell.
  Usage:
  You either do /flashontells [on|off] or just /flashontells for a toggle.
  Or just set it in MacroQuest.ini to FlashOnTells=1 in the [MacroQuest] section.
  NOTE: You have to have tell windows enabled in options for this to work.
- TimeStampChat, BeepOnTells and FlashOnTells are now default ON if no setting is found in MacroQuest.ini.

14 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed a problem with combat abilities (thanks to William12 for the report)
  Before this change you could buy a rank 1 combatability, lets say Rest
  Then you bought Rest Rk. II
  At that point BOTH are saved in your combatabilities array...
  (I think thats a eq bug cause it sure isn't needed)
  Anyway... doing something like ${Spell[Rest].RankName}
  would then fail cause it would find "Rest" first...
  The fix is basically calling pCombatSkillsSelectWnd->ShouldDisplayThisSkill
   in every place NUM_COMBAT_ABILITIES is used...

06 Jul 2015 by SwiftyMUSE
- Updated to include new currencies (Fists of Bayle, Arx Energy Crystals, Pieces of Eight)
- Fixed ${Me.AltCurrency} to be able to use Medals of Heroism not Marks of Heroism

01 Jul 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for the LIVE Client
- Updated for the TEST Client
- Fixed ${Me.Drunk}
- Fixed ${Me.Trader}
- Fixed ${Me.Buyer}

25 Jun 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for the TEST Client

18 Jun 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed ${Me.UseAdvancedLooting} thanks to william12 for reporting it as broken.

17 Jun 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated for today's LIVE patch
- GetCombatAbilityTimer for the LIVE build now takes 2 arguments pSpell->ReuseTimerIndex and pSpell->SpellGroup
  do a search for GetCombatAbilityTimer in your plugins and change accordingly.

11 Jun 2015 by EqMule
- Updated for the TEST build
- GetCombatAbilityTimer for the TEST build now takes 2 arguments pSpell->ReuseTimerIndex and pSpell->SpellGroup
  do a search for GetCombatAbilityTimer in your plugins and change accordingly.
  GetCombatAbilityTimer for the LIVE build has not changed. (but it will next patch.)
- Clicking on the name of someone in the targetwindow will now open a trade if you have coin (or an item) on the cursor.

08 Jun 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Fixed /pickzone you can now do /pick 5 or whatever and it WILL send you to the 5 instance (if it exist)
  /pick 0 will just pick MAIN instance.

28 May 2015 by EqMule
- Please don't use MQ2 for unattended gameplay (afk botting)
- Updated LIVE build.
- Comming in next zip: /pickzone will take a instance number as an argument
  Usage: /pickzone 3 will pick instance 3 and zone you in (provided its valid)
  /pickzone 0 will select the main instance
  this might be buggy its a work in progress.
  NOTE: You should only use this in zones where /pickzone can be used.

23 May 2015 by EqMule
- Fixed ${Me.DSed} and ${Me.RevDSed} crashes thanks to klaarg for the bug report
- consolidated some other stuff and event related things

19 May 2015 by EqMule
- Updated for today's LIVE and BETA patches.

18 May 2015 by EqMule
- Added .NoDrop to the advlootitemtype tlo it returns TRUE if an item is NoDrop and FALSE if not.
  Usage: /echo ${AdvLoot.PList[1].NoDrop}
- Updated BETA build.

16 May 2015 by EqMule
- Updated TEST and BETA builds.
- Fixed an issue with the TEST build which prevented it from building correctly.
- Fixed a ctd in ${DisplayItem} if used after a /unload and reload but no item displayed. reporter: SwiftyMUSE
- Added ItemLink to the Item TLO it just prints the actual hexlink for an item (not clickable)
  this is useful for when creating hotbuttons with links in them manually...
  Usage: /echo ${Cursor.ItemLink}

15 May 2015 by SwiftyMUSE
- Updated GetItemLink to return a clickable or non-clickable link based on a parameter.

13 May 2015 by EqMule
- Added .IconID to the AdvlootItemType TLO it returns an int - cred randyleo
  usage: /echo ${AdvLoot.PList[1].IconID}
- Added .UseAdvancedLooting to the character TLO it returns TRUE if advanced looting is turned on otherwise FALSE -cred maskoi
  Usage: /echo ${Me.UseAdvancedLooting}

12 May 2015 by SwiftyMUSE
- Corrected GetSpellByID to return NULL when the spell is not found. (necessary to fix mq2cast, where it tries to cast
  an item that is not a clicky item and causes a CTD).

07 May 2015 by EqMule & demonstar55
- AltTimer in the _SKILL struct has been renamed to (the correct name) SkillCombatType (whatever that is...)
- Added .Stuck to the SpawnType TLO, i never seen it return TRUE, so more testing is needed...
- Added .PlayerState to the SpawnType TLO, it returns a mask as an inttype which has the following meaning:
  0=Idle 1=Open 2=WeaponSheathed 4=Aggressive 8=ForcedAggressive 0x10=InstrumentEquipped 0x20=Stunned
  0x40=PrimaryWeaponEquipped 0x80=SecondaryWeaponEquipped
  This too needs more testing.
- Added .Stunned to the spawntype TLO it returns TRUE or FALSE if a mob is stunned or not
  NOTE: .Stunned DID exist in the spawntype TLO before, but it only returned your character's Stunstate
  THIS MEANS IF YOU RELY ON THIS IN YOUR MACROS, use ${Me.Stunned} in your macros from now on instead
  when you need YOUR stunstate and the below examples when you need a SPAWNS stunstate, you have been warned...
  Usage: /echo ${Target.Stunned} or ${Spawn[npc somespawnname].Stunned}
- Added .Aggressive to the spawntype TLO it returns TRUE or FALSE if a mob is aggressive or not
- Cred .PlayerState and .Stuck: demonstar55
- Couple additions to /advloot
- /advloot shared # now accepts leave and giveto as arguments
  Usage:
  /advloot shared <#(index) or "item name"> giveto <name> <opt:qty> (qty is optional, if you leave it out it will give full stack)
  /advloot shared <#(index) or "item name"> leave
  Examples:
  Lets say there is a stack of 4 spiderling silks in the first list item of the shared lootwindow
  /advloot shared 1 giveto eqmule 1
  /advloot shared 1 giveto SwiftyMUSE
  Will give 1 spiderling silks to eqmule
  Will give the remaining 3 spiderling silk to SwiftyMUSE (we didnt specify qty, so it just gave the rest)
  /advloot shared "spiderling silk" leave
  Will just leave the first "spiderling silk" it finds in the shared list on the corpse...
  or /advloot shared 1 leave
  Will just leave whatever is in list index 1 in the shared list on the corpse... (in our example spiderling silk)

05 May 2015 by SwiftyMUSE
- Fixed bug with Me.AltAbility where it would not identify alt abilities that were granted but have
  no cost associated.
- Updated ItemDB.txt with new summoned items.

02 May 2015 by SwiftyMUSE
- Added .TankMercCount, .HealerMercCount, .MeleeMercCount, CasterMercCount to the Group TLO

30 Apr 2015 by SwiftyMUSE
- Fixed crash in MQ2Map when zoning with a custom filter

29 Apr 2015 by eqmule
- Updated for the latest LIVE client
- Fixed /bzsrch command
  this means it works again...
  Usage Example: see this post: http://www.macroquest2.com/phpBB3/viewtopic.php?f=17&t=19699&p=169467#p169467
- Fixed a crash that would happen if you logged all the way into the game
  then all the way out to server select, and back in again
  and at that point tried to call GetSpellByName or any
  of the TLO's that calls it.
- Added a few more members to the AdvLoot TLO: all return TRUE or FALSE if checkbox is checked
  .AutoRoll .Need .Greed .No .AlwaysNeed .AlwaysGreed .Never
  Usage Example: /if (${AdvLoot.SList[1].Need}==TRUE) item 1 in the shared list has Need checked. 
- Added PWantCount and SWantCount which counts the number of items in each list that has a checkmark
  in any of the need and greed boxes.
  Usage Example: /echo /if (${AdvLoot.SCount} && ${AdvLoot.SWantCount}) /advloot shared set ${Me.Name}

24 Apr 2015 by SwiftyMUSE
- Allow any case of NULL, TRUE, FALSE to be accurately calculated by our evaluation used in math.calc (and therefore
  in any IF condition.

23 Apr 2015 by SwiftyMUSE
- Fixed missing ground spawn names on the map

23 Apr 2015 by eqmule
- Updated for the LIVE client dated Apr 22 2015 15:38:04

22 Apr 2015 by SwiftyMUSE
- Added .MercenaryCount to the Group TLO

22 Apr 2015 by eqmule
- Updated for the latest LIVE client

21 Apr 2015 by SwiftyMUSE
- Removed unnecessary CleanName useage, as DisplayedName already has the cleaned up name
- Added LocYXZ to spawntype TLO

18 Apr 2015 by eqmule
- /itemnotify "${FindItem[${spellname}].Name}" rightmouseup
  will now actually mem spells...

17 Apr 2015 by eqmule
- Fixed GroupNumber in the raid TLO
  This means : /echo ${Raid.Member[xxxx].Group} will work again.
- Added MasterLooter as a member to the Raid TLO
  Usage: /echo ${Raid.MasterLooter}

16 Apr 2015 by eqmule
- Updated for latest TEST Client
- /notify now takes address as an argument (useful when a window have nested children and you cant find it by name...)
  Usage: /notify ${Window[SomeWindow].FirstChild.FirstChild.Next.Address} leftmouseup
  Usage: /notify ${Window[SomeWindow].Next.Child[Alist].Address} listselect 2

15 Apr 2015 by eqmule
- Added a new TLO for AdvLoot, this is a first draft, test it, report bugs, and so on to me.
  I need a volunteer to update the wiki with this new TLO and its usage/members
  It has a few members SList,PList,SCount and PCount
  /echo ${AdvLoot.PList[1].Name}
  Output: [MQ2] Bone Chips
  /echo there are ${AdvLoot.PCount} items in the personal loot list
  Output: [MQ2] there are 3 items in the personal lootlist
  /echo the item in index 1 has a StackSize of ${AdvLoot.PList[1].StackSize}
  Output: [MQ2] the item in index 1 has a StackSize of 2
  Alright at this point we know the item in index one is a stack of 2 bone chips
  Now we can decide to do something about it:
  /advloot personal/shared 1 leave
  That will click the leave button...
  /advloot personal/shared 1 ag
  That will click the ag checkbox
  And so on...
  Finally you can do
  /advloot shared set Eqmule 
  Or whatever other group member or Never or Leave on corpse or 
  any of all the other choices in the combobox for shared loot and it will set it...
- Added Support for the 6th Augslot in all TLO's dealing with Augs
  Thanks to demonstar55 for reminding me.
- Fixed multiple bugs where CleanName was used to clean names directly on pointers we werent supposed to modify.
  Thanks to Ceedopey for reporting the bug.

31 Mar 2015 by eqmule
- Updated for the latest TEST client
- Updated for the latest LIVE client

30 Mar 2015 by eqmule
- Fixed CSidlScreenWnd__CalculateVSBRange_x offset

28 Mar 2015 by eqmule
- Updated for the latest TEST client
- Updated for the latest LIVE client

27 Mar 2015 by eqmule
- Updated for the latest TEST client
- Updated for the latest LIVE client
- Spell.Dar is back in its full glory (Dar means DamageAbsorbRemaining) -cred demonstar55
  This is useful.
- Spell.Counter is back in its full glory -cred demonstar55
  This is useful for getting for example poisioncounters.

25 Mar 2015 by eqmule
- Updated for the latest LIVE client patch
- Added MarkNpc and MasterLooter to the groupmember TLO
- Fixed a potential crash in case FreeInventory: - cred htw

25 Mar 2015 by SwiftyMUSE
- Fix to /multiline command that would potentially cause incorrect parsing of the commands.

24 Mar 2015 by eqmule
- Fixed NewVardata cred: ctaylor22 
- Added a catch section to GetSpellByName to not try so hard to crash your eqgame(s)
- SwiftyMUSE added a fix from the future.

22 Mar 2015 by eqmule
- Updated for the latest TEST Client patch

19 Mar 2015 by eqmule
- Updated for the latest TEST Client patch
- Fixed Group.MainTank and the other roles

16 Mar 2015 by EqMule
- Added a sanitycheck for GetSpellByName - cred htw
- Misc Fixes
- HAPPY 16th EQ!

12 Mar 2015 by SwiftyMUSE
- Updated ${If[]} to allow one of two user-defined delimiters. The default delimiters are ',' and '~'.
  In the MacroQuest.ini file, you can change the delimiters using IfDelimiter and IfAltDelimiter values.

11 Mar 2015 by eqmule
- Updated for the latest TEST Client patch
- Updated for the latest LIVE Client patch
- Misc Fixes

07 Mar 2015 by eqmule
- Updated for the latest TEST Client patch
- the Alias TLO has been updated to be compatible with ISXEQ

04 Mar 2015 by eqmule & SwiftyMUSE
- made a few changes to how GetSpellByName works
  from now on I placed all of the spelldb in a map.
  the main reason for this is so we can pick spells that best matches our class
  and if it doesnt , at least pick a spell that is class usable.
  if both of those selections fails, we will just revert to old pick, which is to select whichever spell comes first
  in the db...
  Using this map has made spell lookup between 20-200 times faster than before.
  If you are interested in testing this, add a QueryPerformanceCounter before and after
  the call and you will see this for yourself.
- this also fixes problems with getting correct spells for .RankName
- Misc Fixes & Code cleanup
- ${Zone[xxxxx] if xxxxx is larger than MAX_ZONES no longer crashes the client.
- .RankName now returns the input spell if there is no rank found or if the character you do the query on doesnt have the spell.

27 Feb 2015 by eqmule
- Updated for the latest TEST Client patch

25 Feb 2015 by eqmule
- Updated for the latest LIVE Client patch

23 Feb 2015 by eqmule
- Added .Instance to the character TLO
  Usage: /echo ${Me.Instance} will return a int representing the instance ID
- ${Zone.ID} should now return the correct zone id even for instances and neighborhoods.
  as well as campfire zone id's and so on...
- Misc Fixes
- Fixed GROUPMEMBER struct for the test build
  This should fix a crash reported by dogstar, thanks for the reports buddy!


20 Feb 2015 by eqmule
- Updated for test client patch
- Changed all qsort calls to std::sort -Cred demonstar55
- Fixed /who sort guild (has it ever worked?)
  it will display all non guilded players first then sort the rest by guild.
- Fixed a bug where unloading mq2 while the ProcessGameEvents detour was in use would crash the game...
  This means using /unload should be safer than ever now.
- Misc fixes -Cred Htw and uploaders of minidumps.

13 Feb 2015 by eqmule
- Updated for the Test Client patch.

10 Feb 2015 by eqmule
- Updated for the Live Client patch.

07 Feb 2015 by eqmule
- Updated for the Test Client patch.

06 Feb 2015 by eqmule
- Fixed Task.Timer , it can now be trusted even when the task window is closed.
  ALSO TAKE NOTE: it returns a TimeStampType from now on. (used to be a TicksType)

03 Feb 2015 by eqmule
- Added new TLO Alias - Code by Cr4zyb4rd
  see this post for more info: http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=19240&p=167005&hilit=alias#p167005
- Added IsActiveAA to the Spell TLO
  Usage: /echo ${Spell[Origin].IsActiveAA}
  returns: TRUE since Origin is a "Active" AltAbility as opposite to a Passive ability.
- Fixed the EQMisc__GetActiveFavorCost_x offset how long has it been broken?
- Added some stuff to make ISXEQ compile

02 Feb 2015 by eqmule
 - Added .Expansion to the Me.AltAbillity TLO it returns a inttype
 - Added .Flags to the Me.AltAbillity TLO it returns a inttype
 - Added .Passive to the Me.AltAbillity TLO it returns a booltype TRUE if its a passive ability and false if its an active.
 - Added a check for plugin unloading to not try to unload plugins that has already been unloaded...
   not exactly sure if it will help, but im trying to mitigate a crash i have seen when doing /unload
   time will tell.
- Added pcpet and npcpet to searchspawn
  This means you can do stuff like /who pcpet and see a list of all pets that belong to players
  OR /who npcpet and you only see a list of pets that belong to NPCs
  OR /echo ${SpawnCount[npcpet]} to get a count of all npc pets in a zone...
  just specifying pet works as it always have and returns all pets... npc and pc owned...
  Idea: Nytemyst
- Added /mercswitch functionality it will now accept Healer, Damage Caster, Melee Damage and Tank as arguments
  usage: /mercswitch Damage Caster
  and it will switch your merc to the Damage Caster (if you have one and its not already active
  which brings us to:
- Added Mercenary.Index which returns your mercenary's Current list index
- Added Me.MercListInfo which is used in the following ways:
  usage1: /echo ${Me.MercListInfo[1]} returns whatever mercenary type is in Index 1 (there are max 7) as a string and it can be : Healer, Damage Caster, Melee Damage or Tank
  usage2: /echo ${Me.MercListInfo[Healer]} returns the index to the first Healer it finds... as a IntType or 0 if not found.
  This is new code, so there might be some changes to it in the future depending on feedback.

29 Jan 2015 by eqmule
- Updated for test client
- New Command (Idea Cred:brihua) /removeaura
  Usage: /removeaura someaura
  It will take partial auranames as well.
- Added ${Macro.CurLine} Idea:Maskoi
  It will tell you what line you are on in your macro
  usage: /if (${something}) /echo blah blah something happened on Line ${Macro.CurLine}
- Updated Instructions: .Equipment[x].ID doesnt exist, see example below:
  .Equipment in the Spawn TLO returns a inttype, it takes numbers 0-8 or names: head chest arms wrists hands legs feet primary offhand
  Usage: /if (${Pet.Equipment[primary]}==12507) /echo my pet is holding a Frightforged Ragesword in his primary hand
  Usage: /if (${Group.Member[mymagesname].Pet.Equipment[primary]}==12507) /echo my mages pet is holding a Frightforged Ragesword in his primary hand

24 Jan 2015 by SwiftyMUSE
- Modified .RankName to handle spells and potions with the same name

23 Jan 2015 by eqmule
- Updated for today's live client patch

22 Jan 2015 by eqmule
- Removed a MacroError from the ini TLO (sigh)
- I need a vacation...

22 Jan 2015 by eqmule
- Fixed ${Ini (which I broke yesterday)
  It now reads sections and keys correctly again.
  Thanks for the reports.
- Fixed /alert clear #

21 Jan 2015 by eqmule
- Updated for live patch
- Made a change to the Ini TLO (Requester: TreeHuginDruid)
  it should be able to read Section names with commas in them now
  Let me know if this breaks any macros.

19 Jan 2015 by eqmule
- Updated for test server

18 Jan 2015 by eqmule
- Added a workaround for a wineq2 crash.
- Added CCustomMenu so we can create custom menus...
  This is still a work in progress and Ill have more
  to say about it in a later release.
- Stackchecks have been slightly modified to try to take higher level version override into account. -SwiftyMUSE
  Report any issues with this on the forum.

15 Jan 2015 by SwiftyMUSE
- added /break and /continue for /for loops.

14 Jan 2015 by eqmule
- Updated for test patch
- This is a pretty extensive patch, please do a FULL Rebuild.
- New Feature see: http://www.macroquest2.com/phpBB3/viewtopic.php?f=17&t=19610
  you can now have your pet attack a mob without having to target the mob first.
  Usage: /pet attack/qattack # where # is the spawnid of the mob u want the pet to attack
  Example: /pet attack ${Spawn[npc targetable los radius 200 range 1 20].ID}
- Changed the way crashreports are handled.
  You will get an option to break into debugger now.
  I also added some info to the crash detected messagebox
  that lets you know where you can find a copy of the crashdump.
  Not every crash is related to mq2, but if you have a call stack
  where you see mq2main.dll, mail the .dmp to me.
- Added .InInstance to the character TLO
  it returns true if you are in an instance.
  Credit: PeteSampras
- Added a line of code to prevent a ctd in chatwindow
- Added .Offline to the Group.Member TLO
  Usage: /echo ${Group.Member[x].Offline}
  will return a Bool TRUE if offline and FALSE if online
- Added .OtherZone to the Group.Member TLO
  Usage: /echo ${Group.Member[x].OtherZone}
  will return a Bool TRUE if online but in another zone and FALSE if online and in same zone as you.
- Added .AnyoneMissing to the Group TLO
  Usage: /echo ${Group.AnyoneMissing}
  returns TRUE if someone is missing in group, offline, in other zone or simply just dead...
- Rewrote /Alerts again, I wasn't happy with the last version
  lets see if this one is better.

31 Dec 2014 Happy New Year Edition by eqmule
- New Feature see: http://www.macroquest2.com/phpBB3/viewtopic.php?f=17&t=19608
  if you have an item on your cursor and click the name on the targetwindow
  a trade will be initiated and the tradewindow will open.
  Good for tradeing stuff quickly in crowded places like raids or guildhall
- Added a new argument to the /Alerts command [remove]
  it just removes an alert from a list
  Example: /Alert remove 1 npc los
  will remove a previously added alert from list 1 that has is alert on npc and los
  Also alerts are now in a std::list, let me know if there are any problems with this.
  I really hope this wont break any macros, cause code seems to execute a bit faster...

31 Dec 2014 by SwiftyMUSE
- Updated spell stacking (stacks, stackspet, stackswith, willstack)
  Allow stacking of spells that have a greater effect over a lesser one. Used with damage absorption, spell haste, aggro multiplier.
  The change should not break anything existing as I have just put the triggered effects override in the stackswith/willstack code.
  Only updated the stackswith code, willstack is using the old code for comparison purposes. Once we determine the fix doesn't break
  anything, the willstack code will be converted to the new code.
- Added .Hour12 to Time TLO
  returns a string of the format ## AM/PM.
- Change: included "told you," in chat events.

29 Dec 2014 by eqmule
- Botauthors, you can stop summoning pet weapons when its not needed:
- Added .Primary and .Secondary to the Spawn TLO
  both return a inttype which is the idfile id for whatever the spawn is holding in his primary or secondary slot.
- Added .Equipment to the Spawn TLO
  it returns a inttype, it takes numbers 0-8 or names: head chest arms wrists hands legs feet primary offhand
  Usage: /if (${Pet.Equipment[primary]}==12507) /echo my pet is holding a Frightforged Ragesword in his primary hand
  Usage: /if (${Group.Member[mymagesname].Pet.Equipment[primary]}==12507) /echo my mages pet is holding a Frightforged Ragesword in his primary hand
- Change: spawn tlo member .Holding is now a booltype.
  it will return 0 of spawn is not holding anything and 1 if it is.
- BugFix: InitializeMQ2Commands is now called before InitializeMQ2Pulse so we wont end up with a race condition in HideDoCommand...
  the only reason this has worked mostly? fine the last 10 years or whenever it was added in this order
  is cause computers where slower back in the day...
  Anyway if the gCommandCS Critical Section is not initialized when used in HideDoCommand ( CAutoLock DoCommandLock(&gCommandCS);)
  we will hang... (Also changed EnterCriticalSection to a TryEnterCriticalSection, cause there is no reason to get stuck if its the same thread calling it, or is there?
  I'm prepared to revisit this topic if any weird problems arises, let me know...)
- Fix/New Feature: /notify QuantityWnd QTYW_slider newvalue # works now/again (did it ever?) Thanks to nytemyst for the report.
- /windows open now only returns actual open and visible windows.
  I dont know if we need to make an adjustment to this, lets see what people who use that command think.

27 Dec 2014 by SwiftyMUSE
- Fix for /sellitem, the offset was wrong.

24 Dec 2014 Christmas Edition by Santa
- I finally managed to bring perfect LineOfSight to MQ2
  This means no more false positives... Ever...
  Now, poeple ask me, why did it take you 10 years to fix this when it was
  such a simple fix? Well, I actually had to write 1000 lines of code to know which 999 to throw away...
  Anyway Enjoy it, Please see:
  http://www.macroquest2.com/phpBB3/viewtopic.php?f=35&t=19601

  -Usage ${Target.LineOfSight} or ${LineOfSight[${Me.Y},${Me.X},${Me.Z}:${Target.Y},${Target.X},${Target.Z}]}
   Example: /echo there are ${SpawnCount[npc los radius 200 range 100 110]} mobs within a radius of 200 that i can see between level 100 and 110
   Ouptut there are 3 mobs within a radius of 200 that i can see between level 100 and 110

- Splitted ${Target.Maloed} and ${Target.Tashed}
  Maloed only returns a spelltype if the mob actually has a resist debuff casted by a mage or a shaman
  and Tashed only returns a spelltype if the mob actually has a resist debuff casted by a enchanter.

11 Dec 2014 by eqmule
- Updated for patch
- /useitem now works for mounts in the mount key ring.
  Please see change message from the 09 Dec 2014
  for more info on this.

09 Dec 2014 by eqmule
- Added Feature:
  /useitem now works for mounts in the mount key ring.
  /useitem now accepts both quoted and unquoted arguments.
  /useitem now accepts partial arguments.
  Example: /useitem 1 0 or /useitem "Abyssal Steed" or /useitem Abyssal Steed or /useitem Abyssal
  NOTE: if you enclose the argument with quotes, it WILL expect that whats inside the quotes is
  an exact name, so /useitem "Abyssal" wont work, but /useitem Abyssal will...
  also, its not case sensitive, so /useitem abyssal will work as well.
- Added Feature:
  ${FindItem[blah blah]} now finds mounts that are in the mount keyring as well.
- Added MQ2MountType TLO for now it only have 2 members, Index and Name
  Usage: /echo ${Mount[1].Name}
  Outputs: [MQ2] Whirligig Flyer Control Device
  Usage: /echo ${Mount[2].Name}
  Outputs: [MQ2] Abyssal Steed
  Usage: /echo ${Mount[Abyssal Steed].Index}
  Outputs: [MQ2] 2

03 Dec 2014 by eqmule
- Updated for Test patch
- Fixed a problem with /setwintitle
  it wasnt checking for windowclass which would result in
  title not being set for the correct window at all times.

22 Nov 2014 by eqmule
- Added a fix (to a eqbug) which affects Target.Beneficial.
  the player buffs "leak" and shows up briefly in the target buff window
  you can see this if you make target buff window large enough.
  Of course the best fix would be if the eqdevs just made sure player buffs
  dont show up in the targetbuff window, but I dont know if they
  see this a bug or a feature, or even if they are aware.

19 Nov 2014 by eqmule
-Updated for patch
- Added Me.DSed and Me.RevDSed, both return a spelltype
  Usage:
  /if (${Bool[${Me.DSed.ID}]}==TRUE) {
		/echo I have a Damage Shield on its: ${Me.DSed}.
  }
  /if (${Bool[${Me.RevDSed.ID}]}==TRUE) {
		/echo I have a Reverse Damage Shield on its: ${Me.RevDSed}.
  }
- Changes since last zip where made to the following file(s):
	EQData.h
	eqgame.h
	EQUIStructs.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2Utilities.h

13 Nov 2014 by eqmule
- Fixed QuestItem in the Iteminfo struct, it was off by four bytes.
- Added .Quest and .Expendable to the Item TLO.
  both return a pBoolType
  Usage:
  /echo ${FindItem[Drachnid Carapace].Quest}
  Outputs: [MQ2] TRUE
- Changes since last zip where made to the following file(s):
	EQData.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h

12 Nov 2014 by eqmule
- Added Target.Beneficial, Target.DSed and Target.RevDSed
  they all return spelltype
  Usage:
  /if (${Bool[${Target.Beneficial.ID}]}==TRUE) {
		/echo need to debuff cause the target has ${Target.Beneficial} on.
  }
  /if (${Bool[${Target.DSed.ID}]}==TRUE) {
		/echo the target has a Damage Shield on its: ${Target.DSed}.
  }
  /if (${Bool[${Target.RevDSed.ID}]}==TRUE) {
		/echo the target has a Reverse Damage Shield on its: ${Target.RevDSed}.
  }
- Added Spell[somespell].Beneficial
  Usage:
  /echo ${Spell[Skin Like Wood].Beneficial}
  Outputs: TRUE
- Changes since last zip where made to the following file(s):
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2Utilities.cpp

07 Nov 2014 by eqmule
- Fixed a few Buffer Overflow bugs in our somethingsomething(char* szFormat, ...) functions...
  was long overdue...
- Fixed /buyitem and /sellitem
- Changes since last zip where made to the following file(s):
	eqgame.h
	MQ2Commands.cpp
	MQ2DataVars.cpp
	MQ2PluginHandler.cpp
	MQ2Utilities.cpp

06 Nov 2014 by eqmule
- Changed NUM_BOOK_SLOTS to 0x320 (yes really this time)
  this will fix any problems with the charinfo2 struct...
- Changes since last zip where made to the following file(s):
	EQData.h

04 Nov 2014 by eqmule
- Changed NUM_BOOK_SLOTS to 0x320
  Thanks to woobs for reporting this bug
  This should also fix .RankName
  Thanks to Gnits for reporting that bug.

31 October 2014 by eqmule
- Added Heirloom, Collectible and NoDestroy to the Item TLO.
  They all return pBoolType.
  Been on my todo list forever, so it was long overdue.
- Changes since last zip where made to the following file(s):
	EQData.h
	EQUIStructs.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h

30 October 2014 by eqmule
- Updated for the patch
- Changes since last zip where made to the following file(s):
	eqgame.h

29 October 2014 by eqmule
- Fixed an ISXEQ bug thanks to Kannkor for reporting it.
- Fixed Me.Shrouded thanks to dewey2461 for reporting it.
- Fixed Merchant.Item thanks to Fry for reporting it.
- Added Support for Test Server compile
- Changes since last zip where made to the following file(s):
	EQData.h
	EQUIStructs.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2Main.h
	zipit.lst

28 October 2014 by eqmule
- Updated for the patch
- Fixed offset for __ProcessGameEvents_x
  I dont think there is much of a difference but it was
  pointing to __ProcessMouseEvent_x before this change
  I have no idea if that was intentional or not...
- Changes since last zip where made to the following file(s):
	EQData.h
	eqgame.h
	EQUIStructs.h
	MQ2Main.cpp
	MQ2Main.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2Internal.h
	MQ2Benchmarks.cpp

15 October 2014 by eqmule
- Change: struct _MQBENCH Count member is now a ULONGLONG

01 October 2014 by eqmule
- Added .Endurance to the Item TLO it returns IntType
- Added .PctMana to the Spawn TLO it returns IntType
- Added .Zoning to the Character TLO it returns BoolType TRUE if Zoning FALSE if not.

27 September 2014 by eqmule
-Added support for beta server compile

26 September 2014 by eqmule
- Added a new member to the MQ2FloatType TLO: .Raw it returns a pIntType
  Usage: /echo My heading is: ${Me.Heading.Degrees.Raw.Hex} (${Me.Heading.Degrees})
  Outputs: [MQ2] My heading is: 0x43334C00 (179.30)
- The format for all .Hex members are now "0x%X" instead of "%x"
  Let me know if this has any adverse effects on your MQ2 usage.

19 September 2014 by eqmule
- Updated for the patch for the patch for the patch.
- Fixed a couple ISXEQ bugs, see post:
  http://www.macroquest2.com/phpBB3/viewtopic.php?f=48&t=19538
- Changes where made to the following file(s):
	EQData.h
	eqgame.h
	EQUIStructs.h
	MQ2ChatHook.cpp
	MQ2Template\ISXEQTemplate.cpp

17 September 2014 by eqmule
- Updated for the patch for the patch
- Changes where made to the following file(s):
	eqgame.h

17 September 2014 by eqmule
- Updated for the patch
- Support for the new alt currency "Noble" is hereby announced.
  (it was added on the 12th of Sep)
- Changes where made to the following file(s):
	EQData.h
	eqgame.h
	EQUIStructs.h

13 September 2014 by eqmule
- Fixed ${Me.Fellowship.CampfireZone.ShortName}
- Added BuffDuration to the Pet TLO, it returns a pTimeStampType
  Usage: /echo My pets haste will fade in ${Pet.BuffDuration[Hastening of Sviir Rk. II].TotalSeconds} seconds.
  Outputs: [MQ2] My pets haste will fade in 3200 seconds.
- Added support for getting Duration on Songs.
  See notes (below) from 12 September 2014 updates.

12 September 2014 by eqmule
- WARNING!!! MACRO BREAKING CHANGES!
- I have continued my effort to get a higher resolution on timers in MQ2...
  I just can't do them all at once cause it will
  wreak to much havoc in your macros...
- I have updated the following TLOs:
  MQ2TargetBuffType and MQ2BuffType
  The BuffDuration and Duration members.
  They NO longer return a pTicksType.
  Both return a pTimeStampType now.
  This means you can get a higher resolution since default return is milliseconds.
  BUT IT ALSO MEANS ALL MACROS THAT EXPECT TICKS WILL BREAK...
  So go through all you macros and search for ".Duration"
  and ".BuffDuration" and make sure they are working.
  Usage examples:
  /echo ${Target.Hasted.Duration.TotalSeconds}
  returns: 3668
  /echo ${Target.BuffDuration[Hastening of Sviir Rk. II].TotalSeconds}
  returns: 3537
  /echo ${Me.Buff[Hastening of Sviir Rk. II].Duration.TotalSeconds}
  returns: 3432
- Changes where made to the following file(s):
	EQData.h
	EQUIStructs.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2Main.h
	MQ2Utilities.cpp

08 September 2014 by eqmule
- Added support for clicking Sell in barter window.
  Usage: /notify BarterSearchWnd BuyLineList listselect 2
         /notify BarterSearchWnd Sellbutton leftmouseup
- Added support for clicking Buy in bazaar window.
  Usage: /notify BazaarSearchWnd BZR_ItemList listselect 17
         /notify BazaarSearchWnd BZR_BuyButton leftmouseup
- Changes where made to the following file(s):
	MQ2Windows.cpp

25 August 2014 by eqmule
- Updated for patch.
- Added Maloed and Tashed to the Target TLO
  they both return a pTargetBuffType TLO which has 3 members:
  Address (pIntType), Index (pIntType) and Duration (pTicksType).
  It also inherits pSpellType.
  This means that you can to stuff like:
  /if (${Bool[${Target.Tashed]}==TRUE) /echo ${Target.Tashed.Name} will fade in ${Target.Tashed.Duration.TotalSeconds}s
  [MQ2] Tashania will fade in 114s
 
21 Aug 2014 by eqmule
- Added .Slowed.Rooted.Mezzed.Snared and .Hasted to the Character TLO.
  it returns a pBuffType
	Usage: /echo ${Me.Snared}
	Output: [MQ2] Ensnare
- Changes where made to the following file(s):
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2KeyBinds.cpp
	MQ2Main.h
	MQ2Utilities.cpp

20 August 2014 by eqmule
- Updated for patch.

05 August 2014 by eqmule
- Updated for patch.

30 July 2014 by eqmule
- Added MercID to the spawn TLO it returns an inttype
  if the spawn is player and has a merc up this is it's spawn ID
  Usage: /echo Eqmule has a merc up, it's a ${Spawn[${Spawn[=Eqmule].MercID}].Class} named ${Spawn[${Spawn[=Eqmule].MercID}].Name}
  Output: [MQ2] Eqmule has a merc up, it's a Cleric named kandrella_012345

- Added ContractorID to the spawn TLO it returns an inttype
  if the spawn is a merc this is its contractor's spawn ID
  Usage: /echo My target (${Target.Name}) is contracted by ${Spawn[${Target.ContractorID}].Name}
  Output: [MQ2] My target (kandrella_012345) is contracted by Eqmule

24 July 2014 by eqmule
- Attempting to fix charselect crashes when macros are running there.
- Changes where made to the following file(s):
	eqgame.h
	MQ2Commands.cpp
	MQ2Globals.cpp
	MQ2Globals.h
	MQ2Mouse.cpp

22 July 2014 by eqmule
- Fixed the CListWnd__Sort_x offset
- Changes where made to the following file(s):
	EQData.h
	eqgame.h
	MQ2DataTypes.cpp
	MQ2DataTypes.h
	MQ2KeyBinds.cpp
	MQ2Main.cpp

21 July 2014 by eqmule
- Added FirstFreeSlot to the Item TLO, it returns an Int.
  Usage:
  /echo ${FindItem[Spell Research Kit].FirstFreeSlot}
  [MQ2] 5
- Added SlotsUsedByItem to the Item TLO, it returns an Int.
  NOTE: it only works for containers and checks only each slot of the container
  this means you CAN have a stack of 100 water flask in slot 1 of the container
  it will still just return 1 cause it counts only how many slots that has "Water Flask"
  in them not the actual stacksize of the item.
  Usage:
  /echo My Spell Research Kit has ${FindItem[Spell Research Kit].SlotsUsedByItem[Water Flask]}} slots that has Water Flask(s) in them.
  [MQ2] My Spell Research Kit has 4 slots that has Water Flask(s) in them.

19 July 2014 by eqmule
- Fix for missing offset

18 July 2014 by eqmule
- Updated for friday night ninja patch...
- Added 2H Piercing to skill definitions.

16 July 2014 by eqmule
- Updated for patch
- NUM_SPELL_SETS is now 30
- /useitem now searches for items by exact name.
  Example: /useitem "Philter of the Wolf V"
  will uee that potion
  /useitem "Philter of the Wolf VI"
  will use that one...
  prior to this patch doing a /useitem "Philter of the Wolf VI"
  would use "Philter of the Wolf V" if it found that one first...

30 June 2014 by eqmule
- Added new command: /removebuff
  it will remove a buff or a song by name or partial name.
  Usage: /removebuff Summon Drogmor
- Added new command: /makemevisible
  it will make you visible.
  Usage: /makemevisible

26 June 2014 by eqmule
- Fixed MercAAExp,MercAAPoints and MercAAPointsSpent
  this means /echo ${Mercenary.AAPoints} works again.
- Added Leader to the Task TLO it returns a pStringType
  Usage: /echo The task leader is ${Task.Leader}
  Outputs: The task leader is eqmule

23 Jun 2014 by SwiftyMUSE
- Corrected several CTD bugs when a character did not have anything in
  their bank and/or shared bank.

21 Jun 2014 by SwiftyMUSE
- Fixed a bug with pMacroQuestType where pEverQuestType members wouldn't
  inherit correctly. All old ${MacroQuest.} members should work correctly
  now again.

20 Jun 2014 by eqmule
- Updated for patch
- Fixed a problem with writing plugins to MacroQuest.ini when ReadOnly.
  Bug Reported by: Xath
  See: http://www.macroquest2.com/phpBB3/viewtopic.php?f=47&t=19458

19 Jun 2014 by eqmule
- Added back Windows XP Support for GetTickCount64()
  Plugins should change all calls from GetTickCount64()
  to GetTickCount642() which detects if its on winxp
  and calls the old function instead of the new one.
  As a sidenote, if you are still using winxp, know that right this
  moment you have already been pwned and with 100% certainty you are part
  of someones botnet. If you are lucky they wont steal you eqlogin
  just use your computer to click ads or something...
- Fixed a bug with .RankName where two different spells
  can belong to same spellgroup.
  The solution was to compare by SpellGroup AND the spellname.
  Bug Reported by: MacQ
  See http://www.macroquest2.com/phpBB3/viewtopic.php?f=48&t=19455

18 Jun 2014 by eqmule
- Updated for patch.
- The Spell TLO member .RankName now works for combatabilities as well
  Example: /echo My version of Rest is: ${Spell[Rest].RankName}
  Outputs: [MQ2] My version of Rest is: Rest Rk. II

17 Jun 2014 by eqmule
- ${Me.PID} ha been moved to the EverQuest TLO
  so it is now ${EverQuest.PID}
- ${Me.WinTitle} has been moved to the EverQuest TLO
  so it is now ${EverQuest.WinTitle}
- New TLO: EverQuest - Cred: Cybertech
  it has basically the same members as the old MacroQuest TLO
  but I think most of them are more fitting under the EverQuest TLO.
  MacroQuest TLO will inherit EverQuest TLO so backward compatibility is maintained
  BUT new macros should use EverQuest instead.
- Added SpellGroup and SubSpellGroup to the Spell TLO
- Added RankName to the Spell TLO - Cred: petesampras,htw,maskoi
  it returns a pSpellType rather than a pStringType, but since default is the .Name
  and I think thats how most people will use it, its called "RankName"
  Usage: /echo I have the ${Spell[Certitude].RankName} version of Certitude its ID is: ${Spell[Certitude].RankName.ID}
  Output:
  [MQ2] I have the Certitude Rk. II version of Ceritude its ID is:
  Second example: Lets say you have Vinespur Rk. II in your spellbook (and memmed)
  then doing a /cast "${Spell[Vinespur].RankName}" in your macro will cast it, since its
  going to be resolved as /cast "Vinespur Rk. II"
  This should decrease the edititing of inifiles everytime you buy a new rank of a spell.

Friday the 13th!! (of June 2014 by eqmule)
- Added Rank to the Spell TLO, it returns a pIntType thats either 1, 2 or 3 for spells
  and 4-30 for clickys and potions. - Cred: petesampras
  This represents the spell rank, i.e a Rk. II Spell will return a 2.
  Usage: /echo ${Spell[Certitude Rk. II].Rank}
  Outputs: [MQ2] 2
- Added 3 new members to the Character TLO: (a while ago, just forgot to mention it.)
    ZoneBoundX, ZoneBoundY, ZoneBoundZ
	they return a pFloatType
- ${Me.Name}, ${Me.Surname} ${Me.Level} ${Me.ID} now works at charselect as well.
  There is no good reason to duplicate them, so from now on they are fetched from
  LocalPlayer instead since that one exist at charselect, but pCharInfo does not.
- Removed the follow since they are no longer in the client:
	TypeMember(GroupLeaderExp);
	TypeMember(RaidLeaderExp);
	TypeMember(GroupLeaderPoints);
	TypeMember(RaidLeaderPoints);
	TypeMember(PctGroupLeaderExp);
	TypeMember(PctRaidLeaderExp);

10 Jun 2014 by eqmule
- Since someone asked me this:
  -Q: Can you make the /setwintitle set it each time u zone?
  -A: Yes, create a file called zoned.cfg into your Release\Configs Folder
  and paste for example: /SetWinTitle EverQuest - ${Me.Name} (${Zone.ShortName})
  into it.
- Fixed a problem with Auras being detected as a Named spawn. Cred Maskoi.
- Fixed a bug in SearchSpawn where it would return Untargetable mobs
  even though the untargetable flag wasnt set.
  This means ${Spawn[npc radius 100]} wont return Arcane Distillect anymore,
  but ${Spawn[npc untargetable radius 100]} will. (if one is in radius)
- IsInGroup and IsInRaid now checks for Player's corpse as well as Player
  (as long as you specify [pccorpse] in the spawnsearch.)
  This means you can now do stuff like:
  /echo ${SpawnCount[pccorpse Group zradius 50 radius 110]}
  /echo ${SpawnCount[pccorpse Raid zradius 50 radius 110]}

09 Jun 2014 by eqmule
- Fixed? /while
  Feel free to test it and report any bugs.
- Added /GetWinTitle and /SetWinTitle Commands
- Added WinTitle to the Character TLO: it returns a pStringType
- Added PID (Process ID) to the Character TLO: it returns a pIntType
  Usage:
  /SetWinTitle [${EverQuest.PID}] EverQuest - ${Me.Name} (Lvl:${Me.Level} ${Me.Class})
  /echo ${EverQuest.WinTitle}
  [MQ2] [2319] EverQuest - Eqmule (Lvl:100 Shadow Knight)

01 Jun 2014 by eqmule
- Added three new MQ2Type(s): MQ2TimeStampType, MQ2Int64Type and MQ2DoubleType
  MQ2TimeStampType has the same submembers as pTicksType
  with the difference being that the default return value is milliseconds.

- MACRO-BREAKING CHANGE! (if your macro uses Me.GemTimer)
  Look, for years we relied on updating stuff every 6 seconds (1 tick)...
  I had to make this change since the client updates more often nowadays.
  Which is why:
  ${Me.GemTimer[x]} now returns a pTimeStamp.
  The default return is milliseconds until gem is refreshed.
  Usage Example: /echo ${Me.GemTimer[5].TotalSeconds}
  Outputs: [MQ2] 25

- All references to GetTickCount() have been replaced with GetTickCount64()
  This will fix problems related to all timers for people who dont do a complete
  shutdown of their computer earlier or on every 49.7th day.
  Plugin authors should replace all references to GetTickCount() in their plugins
  with GetTickCount64() as well.
- ${Macro.Runtime} now returns a pInt64Type to be able to hold the return of GetTickCount64
  if you are using ${Macro.Runtime} in your macro, make sure it works as intended. 

23 May 2014 by eqmule
- Fixed a fix...
  Sorry but I was in the middle of testing stuff yesterday and today they patched so
  in order to get everything out quick for x2 weekend
  I missed a bug in GetSpellByID, its fixed now (again)

23 May 2014 by eqmule
- Updated for patch

22 May 2014 by eqmule
- Secured a few functions that calls GetSpellByID against buffer overflows.

21 May 2014 by eqmule
- Updated for patch

15 May 2014 by eqmule
- Updated for patch

14 May 2014 by eqmule
- Updated for patch

12 May 2014 by eqmule
- Added nogroup to searchspawn - cred htw
  This means you can do stuff like /echo ${Bool[${NearestSpawn[1, nogroup pc radius 300]}]}
  it will return TRUE if there is at least 1 player within 300 radius of you thats NOT in your group.
- Added case Range: to ItemType

08 May 2014 by SwiftyMUSE
- Update of SpellSlotInfo for SPA's 157 to format as a ranged value
- Added MaxBuffSlots, changed FreeBuffSlots to use the new function that gets the max buff slots

29 Apr 2014 by eqmule
- Updated for patch

26 Apr 2014 by eqmule
- If using an old ItemDB.txt you will now see a message asking you to update it.

24 Apr 2014 by SwiftyMUSE
- Fix for reuse timer in spell slot information
- Fix for random CTD on some spell display
- Fix for CTD when item missing in ItemDB
- Added command /SpellSlotInfo [#|"spell name"]. You can use this to see the spell slot
  information for any spell without having to right-click display through the MQ2ItemDisplay plugin.
- Ground spawn updates

18 Apr 2014 by eqmule
- Fixed a bug in GetSpellByID that would make it return "Unknown Spell" when it 
  should just return 0
  This means macros like scribe.mac will work again.

16 Apr 2014 by eqmule
- Fixed the EQRAIDWINDOW struct
  This means caption classcolors for raidmembers will again work as intended.
- Changed how plugins are loaded from MacroQuest.ini
  I don't think this will affect anyone, but from now on
  when a plugin is unloaded the [Plugins] section will not be erased
  The old mq2plugin=mq2plugin is still valid, but eventually
  you will end up with a list of plugins where the entries
  will look like mq2plugin=1 or mq2plugin=0
  I did this because I'm preparing the loader for being able to unload/load
  plugins directly from its iconmenu.

13 Apr 2014 by SwiftyMUSE
- Added GemIcon, HateGenerated, PvPCalc, Unknown182, Unknown222, Unknown223 to the SPELL struct
- Added HateGenerated to MQ2ItemDisplay output

11 Apr 2014 by SwiftyMUSE
- Merged the MQ2GearScore logic into the base code for MQ2ItemDisplay. This means that MQ2GearScore
  is no longer necessary and MQ2Bzsrch will work correctly for those that want scores.
  In order to use the new functionality, rename your old ini file to MQ2ItemDisplay.ini to get all
  the same values. You can stop using MQ2GearScore and go back to use the base code MQ2ItemDisplay

10 Apr 2014 by SwiftyMUSE
- Update of SpellSlotInfo for SPA's 124/125/132 to format as a ranged percent and specify that SPA 132
  is a # of tick(s)

08 Apr 2014 by SwiftyMUSE
- Rewrite of SpellSlotInfo, uses new function ParseSpellEffect. Pass a pSpell structure, slot number,
  character buffer and it will return a character buffer with the spell effect information
- Fixed issue with MQ2ItemDisplay that would sometimes display the wrong usable classes

08 Apr 2014 by SwiftyMUSE, eqmule
- Corrected datatype refactor to allow for correct type inheritence in MQ2 parser

08 Apr 2014 by eqmule
- Added MaxTargets to the SPELL struct
  This means we can check how many targets a spell will affect, 12 for example.
- Added SpellGroup to the SPELL struct
  This is used to display the spell family for the "Limit: SpellGroup"

06 Apr 2014 by SwiftyMUSE
- Fixed issues with GetSpellNameByID and GetSpellbyID that would cause undefined results or CTD

05 Apr 2014 by eqmule
- Fixed a crash in GetSpellEffectName
- MacroQuest2.exe should work on windows 8.x now

04 Apr 2014 by eqmule
- Update for patch

02 Apr 2014 by SwiftyMUSE
- TEMPORARY fix for C2065 compiler issue on vs2008

02 Apr 2014 by eqmule
- Update for patch
- MacroQuest.ini is now created (from the _default template) if it doesnt exist.
- The item and spelldisplay plugin should display more correct info now
  SwiftyMUSE did most of that grunt work, big props to him for taking it on.
  We will carefully monitor this code and add more fixes as we go to make stacking
  and spell/iteminfo 100% perfect.

30 Mar 2014 by SwiftyMUSE
- Added CreateMQ2NewsWindow for Macroquest.ini file to turn on/off the creation of
  the news window
- Updated stacking checking to ignore bard songs and song window illusions
- Removed the stat change portion of the additional checks for stacking introduced
  on 23 Mar 2014

30 Mar 2014 by eqmule
- Fixed /lootall
- Added Caster to the Spell TLO
  returns a pStringType of the caster of a buff
  Usage: /echo ${Target.Buff[Ancient Flames].Caster}
  [MQ2] eqmule

27 Mar 2014 by CyberTech
- Refactor datatype definitions for MQ2 and ISEQ code
    All datatypes are declared in one file (DataTypeList.h), one time, for both ISXEQ and MQ2.
    Inheritance and Persistence are defined at the same time and location.
    This will avoid the ISXEQ build breaking or falling behind when new datatypes are added to MQ2.
    Additionally, it simplifies the code required for a new MQ2 datatype -- 1 line of code instead of 4

26 Mar 2014 by eqmule
- Fixed Spell[some spell].Description
  it now returns the correct string.
- Added a Slowed,Rooted,Mezzed,Crippled,Snared and Hasted
  to the TargetType TLO.
  they all return a pTargetBuffType TLO which has 3 members:
  Address (pIntType), Index (pIntType) and Duration (pTicksType).
  It also inherits pSpellType.
  This means that you can to stuff like:
  /echo ${Target.Slowed.Name} will fade in ${Target.Slowed.Duration.TotalSeconds}s
  [MQ2] Tepid Deeds will fade in 114s
  /echo ${Target} will break mezz in ${Target.Mezzed.Duration.TotalSeconds}s
  [MQ2] a_pyre_beetle48 will break mezz in 66s

24 Mar 2014 by eqmule
- Added exact match option to spawn searches (Suggested by: petesampras)
 example: /echo ${Spawn[=eqmule]} will find eqmule but not eqmulee.
- Fixed GroupMemberTargeted (this means /target clear works again)
- Added new TLO Member 'Inviter' to the character TLO. (its a pStringType)
 You can check ${Me.Invited} to see if you have a
 group invitation so I figured it would be useful
 to know who actually sent the invite:
 Usage: /echo ${Me.Inviter} just invited me to join their group
 Output: [MQ2] uberplayer00 just invited me to join their group

23 Mar 2014 by SwiftyMUSE
- Corrected itemdisplay to show useable classes for the spell when over level 70
- Corrected to make sure cfg files are executed during refresh injections
- Additional checks for spell stacking.
  (Buffs/Songs will stack (both land) if they are benefical spells and it's some type
  of stat change that was currently causing it to fail)

22 Mar 2014 by SwiftyMUSE
- Corrected useable class name in itemdisplay extension.
- Additional updates for spell effects
- Updates for spell stacking. Added .StacksWith as an alias
  for .WillStack

22 Mar 2014 by eqmule
-NOTE, THIS UPDATE WILL BREAK PLUGINS. (but not that much see below)
 SPELL struct member Level is now ClassLevel
 this was done cause i want you to know which plugins to update.
 ANY place that refers to Level-1 muct be changed to ClassLevel
 do NOT forget to remove the -1
-Updated the launcher.
-Injecting is now faster, it will happen even when eq is not in focus.
 This means injecting will no longer attach to any process it feels like.
 it will only attach to eqgame.exe.
 This is a good thing, (cause it means you wont have to kill the tasktray icon)
 if you need to /unload to do a rebuild for example.
 Also, since mq2main only attaches to eqgame, launchpad will now
 run just fine without dying even when the tasktray icon is up...
 If you /unload you can "reload" from the tasktray icon by selecting
 "Refresh Injections"
 If you start a new session of eqgame.exe mq2main.dll will be autoinjected.
 "Refresh Injections" will only reattach to eqgame.exe(s) that doesn't already
 have a mq2main.dll loaded in its address-space. 
 If one is loaded already it will move on to the next eqgame.exe it finds and try there
 until it has made sure all running eqgame.exe has mq loaded...

18 Mar 2014 by SwiftyMUSE
- Added CountSongs
- Changed .Stacks and .StacksPet to allow the comparison of the songs too
- Added MercType to the list of PlayerClasses
- Added the ability to allow custom offsets for those that need that (See the new privates files, MQ2Globals-private.cpp/.h)
- Added an actordef list to define the names for the various groundspawns.
  (If you find any missing (there are some), please post and they can be added.) Use "/items drop" to see
  the value that needs to be added. I removed the use of weapons.h and grounds.h. They were merged into
  the actordef list.
- Added some missing expansion names
- Added additional spelltype members (thanks PeteSampras)

18 Mar 2014 by eqmule
-IMPORTANT: MacroQuest.ini has been renamed to MacroQuest_default.ini
 I did this because I got tired of that unzipping would overwrite
 mine (which has custom settings in it) everytime there was a new zip.
 New Users that never run MacroQuest2.exe before
 SHOULD remove the _default extension on that file before they start MacroQues2.exe.
 (I want to make MacroQuest2.exe automatically do that at some point if no ini exist,
 but for now its a manual thing)
-Fixed a ctd when you did a /echo ${FindItemBankCount[blah]} with an empty shared bank...
-Fixed EQRAID struct (again)
-Added all known SPAs (458 of them), this means you should not get any more Unknown Spell Effects
 in the Spell Display. (You will get "Please Check" instead but thats for me
 so I know which ones I need to look closer at, dont worry about that for now.
-Added Spell restrictions as well to the spell display info - cred htw

-This is mainly a maintenance release, which means, it has code i am going to finetune later
 as well as some code that is now redundant and will be removed at a later point so we can avoid bloat.
 Hopefully releasing this now, will give those of you that maintain your own versions enough time
 to merge in the new stuff with your own builds before next patch...

-The Readme.chm file is back! (Click ReadMe on the macroquest2 icon...)
 it has compile instructions for VS 2012...

 more can be done to update other sections of it, but we need to start somewhere.
 contact me if you are interested in helping out with that.

16 Mar 2014 by eqmule
-Fixed EQRAIDMEMBER struct
 This means /echo ${Raid.Member[${Me}].Class} (and the likes) will work again.
-Fixed a bug with pRaidType where pSpawnType members wouldn't inherit correctly.
 This means things like /echo ${Raid.Member[${Me}].Race} will work properly (again)... (did it ever work?)

15 Mar 2014 by eqmule
-Fixed the EQRAID struct 
 This means, things like /echo ${Raid.Members} will work again.

13 Mar 2014 by eqmule
-Updated for patch
-Fixed a problem with MQ2Labels showing up as Unknown

12 Mar 2014 by eqmule
-Updated for patch
-The MQ2Type destructor is now virtual Cred: TypePun

09 Mar 2014 by eqmule
-Added Distance3D float member to the Switch TLO
-/click left item is back!! (in all its old days glory...)
 To use: first /itemtarget then /click left item
 Yes you can pick up stuff from the ground without facing it.
 Yes you can open a tradeskill container without facing it.
 BUT make sure you are in range. (20)
 Even though you do not have to be facing the item I still recommend
 you do a /face item (for appearances) before you issue a click left item...
 Please dont abuse this.

01 Mar 2014 by eqmule
-Fixed InvitedToGroup (it was in the wrong place in the struct)

26 Feb 2014 by eqmule
-Made some preparations for future updates related to Custom Help Windows
 Not a critical update unless you are a hardcore plugin author.

23 Feb 2014 by eqmule
-Corrected some offsets that where wrong.
 This should fix a couple ctd's reported on the forum (hopefully)
 Sorry about any downtime this may have caused to your crews...
-CampfireZone wont ctd in neigboirhoods or greater guild halls anymore
 however it wont return anything either until I figure out where that info is located.
-Updated /beepontells and /timestamp to take on AND off as arguments.
 no argument will just toggle, just like before this change.
 This is also saved to macroquest.ini from now on.

21 Feb 2014 by SwiftyMUSE, eqmule
- Updated for patch

20 Feb 2014 by eqmule
-Fixed EQRAID struct 
 This means, things like /echo ${Raid.Members} will again work.

19 Feb 2014 by eqmule
-Updated for patch
-Added LoreGroup and LinkDBValue to CONTENTS struct
 It is used in the linkdb plugin. Cred: SwiftyMUSE

-Added a new TLO Member for Song/Buff, HitCount which will return a pIntType of how many hits a song/buff has left before it fades.
 Usage /echo ${Me.Song[Lich Sting Recourse].HitCount}

-made some adjustments to /itemnotify
 Im not really finished with it, more testing is needed
 but now it can select items when merchantwindow is open.

 and /ctrl /itemnotify should pick up single items as well... *should*
 more to come on this, its complicated... I know the code looks like a complete mess
 but I will clean it up when I know exactly how I want it to work...

05 Feb 2014 by eqmule
-Changed /ini to work in the following way (see below), apperantly there was a bug in my understanding
 of how people wanted it to work.
//	/ini "someini.ini" "the section" "NULL" "NULL"
//	adds a key named NULL and a value named NULL under the [the section]:
//	to remove the key named NULL:
//	/ini "someini.ini" "the section" "NULL" NULL
//	OR /ini "someini.ini" "the section" "NULL"
//	to remove section "the section":
//	/ini "someini.ini" "the section" NULL
//	OR /ini "someini.ini" "the section"
//
//	Basically leaving the third and/or fourth parameter blank will be interpreted as NULL
//	enclosing NULL in quotes will interpret it as an actual string "NULL"

29 Jan 2014 by eqmule
-Fixed a bug in MQ2DataVars.cpp
 itemlinks now works as intended. (again)
-Added some support for ISXEQ and some new commands(/beepoontell,/timestamp) + a lineofsight code change
 cred: Red-One

28 Jan 2014 by eqmule
-Updated for patch

27 Jan 2014 by eqmule
-New Feature: /useitem "item name here"
-New Feature: /itemnotify "item name here" left/rightmouseup
 This means no more need to figure out which slot an item is in, as long as its in our inventory
 it will be "clicked".
 For obvious reasons, rightmouseup only works on clicky items...

-NOTE! MACRO AUTHORS:
Keeping with my modus operandi of "breaking things that are'nt fixed" (properly)
I have made changes to the following:
Macro breaking changes: (please dont panic, its easy to adjust)
1. TLO ${Me.XTarget[x].Type} is now ${Me.XTarget[x].TargetType}
 Reason: XTarget inherits Spawn and since that already contains a .Type member, it was necasary to change it.

2. Ok , so I noticed that everquest sometimes mark chat as SPAM
and in order to do that, they "tag" say,tell, and the rest of the chat if it orignates from another player.
This messes up our eventhandling, and I believe it has for several years.
So, its well overdue for a change, I am sorry about this though, cause this WILL
break some macros (and possibly plugins) that "fixes" this internally...
Here is an example of how a macro would deal with this:

#event healme "#1# says,#*#heal me#*#"

Sub Event_healme(line, Sender)
	/varset Sender ${Sender.Right[-2].Left[-1]}
	/if (${Sender.Equal[eqmule]}) {
		/echo eqmule needs a heal
		/varset healneeded 1
	}
/return

As you can see, unless we "strip" ${Sender} it will never be equal to "eqmule"
cause "eqmule" is actually "\x12\x31eqmule\x12"

Now, the fix for this obviously should be taken care of by core mq, and not your individial macros.
So I have done precicely that.
After building this version of mq, the new event should look like this instead:
Sub Event_tagged(line, Sender)
	/if (${Sender.Equal[eqmule]}) {
		/echo eqmule needs a heal
		/varset healneeded 1
	}
/return

Ok? questions? post on the forum, im releasing this version a month or so before next patch, 
so u should all have plently of time to adjust to this change.

22 Jan 2014 by eqmule
-Updated for patch

21 Jan 2014 by eqmule
-Added two new features
-New Command: /beepontells which is a toggle, can be set in MacroQuest.ini BeepOnTells=1 in the [MacroQuest] section.
 well... thats what it does, u get a tell... it beeps...
-New Command: /timestamp which is a toggle, can be set in MacroQuest.ini TimeStampChat=1 in the [MacroQuest] section.
 Basically it timestamps all chat when its on...
 NOTE: The timestamp takes place AFTER chatevents are handled, so at least in theory
 this should NOT have any adverse effects when turned on.

20 Jan 2014 by eqmule
-pinstCTaskWnd is back, dont know when it got lost...
-Added new TLO "Task" its useful for shared tasks(quests).
 it has the following members:
 -Title returns a pStringType of the shared task.
 -Timer returns a pTicksType of the amount of time left before task expires.
 -Members returns a pIntType of how many members the task has.
 -Member returns a pTaskMemberType
  pTaskMemberType has the following members:
  -Name returns a pStringType
  -Leader returns a pBoolType of TRUE or FALSE if the member is the task leader or not
  -Index returns a pIntType of the members taskindex, i.e where in the list it is... 1-6
Usage:
       /if (${Task.Member[Eqmule].Leader}) {
              /echo I am the leader of ${Task.Title} which expires in ${Task.Timer.TotalMinutes}...
	   }
	   /echo Task Member 2 is ${Task.Member[2]}
Output:
      [MQ2] I am the leader of Hatching a Plan which expires in 243 minutes...
      [MQ2] Task Member 2 is Eluidiaan

-XTarget now inherits pSpawnType
 this means that you can now do stuff like:
 /echo ${Me.XTarget[1].PctHPs}
 [MQ2] 93
 /echo ${Me.XTarget[8].Level}
 [MQ2] 16
 NOTE: max XTarget is 10... I dont think doing /echo ${Me.XTarget[11].Level} will turn out good for anyone...

 Please update ALL macros that targets mobs around you *when fighting* to check their HP to use XTarget[x].PctHPs instead.
 HINT: This is not a suggestion, its a very strong recommendation/borderline order.
 The reason for this is that:
 1. Targeting multiple mobs over and over just to check their HP, SLAMS the eq servers with targetpackets.
 2. It is BAD practice and it slows down YOUR macro, as well as the eq servers.
 3. For your own good, detecting botters are extremely easy by just watching how your character targets.
    no "real" player will target 50 mobs around him in a couple seconds, just to select the one with the lowest HP.

04 Jan 2014 by eqmule
-Added ActiveDisc to the Character TLO, it returns a pSpellType if a discipline is active. (otherwise NULL)

 usage: /if (${Me.ActiveDisc.ID}) {
			/echo Yes I am using a Discipline, and its ${Me.ActiveDisc.Name}, the spell id is ${Me.ActiveDisc.ID}
		}
 
02 Jan 2014 by eqmule

								HAPPY NEW YEAR!!!
We have had a good 2013, I expect to add some exciting new things as well as continue
work on updating and making MQ2 better and better this year.
Stay tuned, and thank you for all of your support!

-This is NOT a critical update (no need to update unless you really need the following:)
-Added GetCurrencyIDByName
-Added new Character TLO Member AltCurrency which returns a pIntType
 usage: /echo ${Me.AltCurrency[Marks of Valor]}
        /echo ${Me.AltCurrency[31]}
 Cred: desgn
-Added ZoneFlags to the pZoneType TLO, it returns a pIntType
-Added Category and Subcategory Members to the Spell TLO, they return pStringType
-Fixed a CTD in ${DisplayItem.StackSize}
-Added delete functionality to the /ini command
 usage: NULL required: http://www.macroquest2.com/phpBB3/viewtopic.php?t=12574&highlight=delete
       no NULL needed: http://www.macroquest2.com/phpBB3/viewtopic.php?f=28&t=18467

 Both approaches are valid and will work for backward compatability.

15 Dec 2013 by eqmule
-This is NOT a critical update (no need to update unless you really need the following:)
 I just added FindItemByID and renamed FindItem to FindItemByName
-Updated ${Mercenary.State} to return "NOMERC" if you dont have a merc.

-There is a /while command in right now (has been for a while -pun intended)
 I just wasnt ready to announce it earlier, look, this is extremely beta.
 IF you are gonna try it, you cannot expect it to work perfectly
 I basically only tried:
 /while (${Target.ID}) {
	/delay 1s <--- IMPORTANT
	/echo Hi there we have a target
 }
 You can NOT do:
 /while (something) /echo hi there
 
 right now it NEEDS the {} enclosure...
 and please unless you want your cpu to freak out... use a "/delay something" within that closure...
 see my example above (the <-- IMPORTANT)

11 Dec 2013 by eqmule
-Updated for patch
-Updated AltAdvManager::GetAltAbility with second parameter, I dont know what it is yet, rank? level?
-Fix for SpawnInfo->Trader and SpawnInfo->Buyer

06 Dec 2013 by eqmule
-Fixed void CTabWnd::SetPage(int,bool,bool);
(this means aapurchase and the likes works again...)
your're welcome...

05 Dec 2013 by eqmule
-Updated for patch

27 Nov 2013 by SwiftyMUSE
-Added AAPointsAssigned to Me TLO

16 Nov 2013 by EqMule
-Fix for ${Target.AggroHolder} it now properly return Pets and Mercenary SpawnTypes as well as Players.
 There is still some work to do on this TLO, for example it wont return
 yourself, this is not intentional, its on my todo list.

-Added support for /itemnotify with bags closed for bank and shared bank as well.

-Fixed a bug where if you sent a /itemnotify in <pack> <slot> leftmouseup 
 and you had the item on a hotbutton, instead of picking it up, it would activate it.
 This means that from now on, if you issue a /itemnotify leftmouseup command... you can be 100% sure
 it WILL pick up the item, not activate it...

14 Nov 2013 by EqMule
-Updated for patch
-"/itemnotify in" changed to work even if bags are closed.
 example: /itemnotify in pack1 1 leftmouseup ( Will pick up the item in pack1 slot 1 even if the bag is closed...)

 Note: that this is pretty much untested right now, let me know of any issues.

10 Nov 2013 by SwiftyMUSE
- added MaxLevel to Spell TLO
  the purpose was to allow autobot to get the max mezz level automatically
  and avoid hardcoding it in the macro itself.

07 Nov 2013 by EqMule
-Fix for Contents.Power
-Added a manifest to MacroQuest2.exe so it will requireAdmin automatically.
-Updated all visual studio vcxproj files to use the v110xp toolset.

its time for you guys to update to vs2012 sp3 or newer if you want to use the vs2012 .sln
For the rest of you, this shouldnt have an impact, just use old MacroQuest2.sln

as for the strcpy_s error, this is intentional, upgrade your visual studio to a version released after 2006.
you cannot use vs 6.0 anymore (unless you change them all back to strcpy)

06 Nov 2013 by EqMule
-Updated for patch
- Changed top #turbo to 80, still defaults to 20
-Brought back an old friend from the dead... /click left door
 You do not *HAVE* to face the door to "click" it but I still recommend that you do, your char doesn't need the attention...
Usage:
Sub OpenDoor
:retrydoortarget
	/doortarget DOOR1
	/delay 1
	/if (!${Switch.ID}) {
		/goto :retrydoortarget
	}
	/face door nolook
	/delay 1
:retryopendoor
	/if (!${Switch.Open}) {
		/click left door
		/delay 1s
		/goto :retryopendoor
	}
/return

29 Oct 2013 by EqMule
-Cast item works on items in bags now if you have VoA or higher expansion.
cred to desgn for code/suggestion

26 Oct 2013 by EqMule
-Added a new member to the Target TLO:
${Target.AggroHolder} it returns a pSpawnType of whoever your target is most angry with and currently attacking, 
i.e they guy that has the most aggro.
This can be used for ANY Target, you dont even have to have aggro yourself or even be in group with them.
You can run by someone fighting, select their target and this will return whoever its most angry with...
/echo ${Target.AggroHolder}
[MQ2] EqMule

***OK THE NEXT FIX "might" break some macros, BUT, this is how it is meant to work for consistency, so... deal with it please.***
-Fixed ${Group.Member[<thename>].PctAggro and ${Group.Member[x].PctAggro
/echo ${Group.Member[eqmule].Index}
[MQ2] 3			<-- im groupmember 3
/echo ${Group.Member[3].Name}
[MQ2] Eqmule	<-- see?
/echo ${Group.Member[3].PctAggro	<-- it works with the number
[MQ2] 54		<-- my aggro
/echo ${Group.Member[Eqmule].PctAggro	<-- as well as the name
[MQ2] 54		<-- my aggro

23 Oct 2013 by EqMule
-NOTE TO: Macroauthors, Macro breaking CHANGE!

 Look, to prepare for a PctAggro fix, I needed to make a change to how ${Group.Member[<TheName>]} works
 This will most likely BREAK some people macros
 BUT it is going to be consistant with how other TLO's work that deal with Names and so on.
 so in the end you will thank me for making this change.
 From Now On: ${Group.Member[<TheName>} returns a pGroupMemberType NOT a pIntType
 SO IF you need the Index of a GroupMember, I have added a new member called: Index
 Example of how it worked BEFORE THIS PATCH:
 /echo ${Group.Member[${Me.Name}]}
 [MQ2] 0
 Example of how it works AFTER THIS PATCH:
 /echo ${Group.Member[${Me.Name}]}
 [MQ2] Soandso
 BECAUSE the new type is a pGroupMemberType, it also inherits pSpawnType which is why you can also do:
 /echo ${Group.Member[${Me.Name}].Class}
 [MQ2] Wizard
 I hope you all can see the benefit of being able to directly access the pSpawnType in this way...
 But, to get back to the index:
 To actually get the index do a:
 /echo ${Group.Member[${Me.Name}].Index}
 [MQ2] 0

 We good?

21 Oct 2013 by EqMule
-Fixed ${Pet.Body.ID} and ${Mercenary.Body.ID} crashes (when no pet/mercenary was up)

20 Oct 2013 by EqMule
-Added Prestige to the Item TLO:
usage: /echo ${Cursor.Prestige} returns a pBoolType TRUE if its a Prestige item otherwise FALSE

19 Oct 2013 by EqMule
-Added Subscription to the Character TLO:
usage: /echo ${Me.Subscription} returns a pStringType "UNKNOWN","FREE","SILVER" or "GOLD"

15 Oct 2013 by EqMule
-Added EnduranceCost to the Spell TLO:
usage: /echo ${Spell[Malarian Mantle].EnduranceCost} returns a pIntType
-Added PctPower to Item TLO:
usage /echo ${Me.Inventory[powersource].PctPower} returns a pFloatType

14 Oct 2013 by EqMule
-Added 2 new Members to the Character TLO:
${Me.PctMercAAExp} which returns a float of the current percent of exp your mercenary has.
and
${Me.MercAAExp} which returns the actual pIntType

13 Oct 2013 by EqMule
-Fix For macros not loading...

13 Oct 2013 by EqMule
-Fix for ${Group.Member[x].Pet}

12 Oct 2013 by EqMule
-Added Support for CustomPlugins.ini
 it only have 2 sections and in the Macroquest Section only DebugSpewToFile is valid
 in the Plugins section you can add as many plugins as u like...
 /plugin unload on a custom plugin will unload it (as it should), but it will NOT write the change to the CustomPlugins.ini.
 That behaviour is by design. If you dont want a plugin to be loaded, you should manually remove it from the list.
 Example of what my CustomPlugins.ini looks like:
 [MacroQuest]
 DebugSpewToFile=1

 [Plugins]
 mq2AutoLogin=mq2AutoLogin

12 Oct 2013 by EqMule
-Fix for a crash in the "Clearing A Path" instance in Dead Hills
 this will most likely fix other instance crashes as well in the new zones.
 however i couldnt log in game to test, so report in bugs forum if u still crash
 when zoning in.

12 Oct 2013 by EqMule
-Fix for ${Me.Pet.Following} and ${Me.Mercenary.Following}
-Todo: Fix ${Me.Inventory[powersource].Power}

11 Oct 2013 by EqMule
-Removed PetTarget and PetCombat
-Added new TLO members for ${Me.Pet}
- Buff		example: /echo ${Me.Pet.Buff[1]} returns a pSpellType
			example: /echo ${Me.Pet.Buff[Spirit of Wolf]} returns a pIntType (The slot the buff is in)
- Combat	example: /echo ${Me.Pet.Combat} returns a pBoolType TRUE or FALSE (on/off)
- GHold		example: /echo ${Me.Pet.GHold} returns a pBoolType TRUE or FALSE (on/off)
- Hold		example: /echo ${Me.Pet.Hold} returns a pBoolType TRUE or FALSE (on/off)
- ReGroup	example: /echo ${Me.Pet.ReGroup} returns a pBoolType TRUE or FALSE (on/off)
- Stance	example: /echo ${Me.Pet.Stance} returns a pStringType "FOLLOW" or "GUARD"
- Stop		example: /echo ${Me.Pet.Stop} returns a pBoolType TRUE or FALSE (on/off)
- Target	example: /echo ${Me.Pet.Target} returns a pSpawnType of the pets current target
- Taunt		example: /echo ${Me.Pet.Taunt} returns a pBoolType TRUE or FALSE (on/off)

10 Oct 2013 by EqMule
-Updated for patch
-Added new TLO ${Mercenary}
It returns a SpawnType so you have access to all spawnmembers.
As well as these four new ones:
${Mercenary.State} (stringtype) which returns strings: "DEAD" "SUSPENDED" "ACTIVE" or "UNKNOWN";
${Mercenary.StateID} (int) which returns the state as a number (mostly good for debugging)
${Mercenary.Stance} (stringtype) which return the Stance as a string
${Mercenary.AAPoints} (int) returns how many unspent mercenary AA you have.
I Plan to add more stuff later if needed. Those are the most useful for now...

09 Oct 2013 by EqMule
-Fix for Bank and SharedBank members in CHARINFO struct
(thanks to Drakhhen for making me aware of this bug)

08 Oct 2013 by EqMule
- Updated for Oct 7-8 2013 patch
- Shared Bank now has 4 slots
- I will add a TLO for the new mercenary AA
 but I need more time to look into it, unless someone beats me to it.
 For now use the UI...
- Added a couple new TLO's
 /echo ${Me.PetTarget}
 will return the spawn your pet has targeted.
 so you can do /echo ${Me.PetTarget.ID} and so on to get more info out... 
- /echo ${Me.PetCombat}
 is the pet attacking something? 
 returns TRUE or FALSE 

Im pretty sure these 2 can use some more work, but should work in most situations I think...

22 Sep 2013 by EqMule
- Added Me.ZoneBound which returns Zone information for the zone you are bound in
  Usage:
	/if (${Zone.ID}==${Me.ZoneBound.ID}) {
		/echo crap im back at bindpoint, did I die?
	}
18 Sep 2013 by EqMule
- Updated for patch
21 Aug 2013 by EqMule
- Updated for patch
18 July 2013 by EqMule
- Added support for /useitem
  Example: /useitem ${FindItem[=worn totem].ItemSlot} ${FindItem[=worn totem].ItemSlot2}
  Note: you need VOA expansion or newer for /useitem to work, its a soe, not an mq2 command
- Fixed listselect *
	Example: /notify MMTW_MerchantWnd SubtypeListBox listselect 10
			 Will select the Tier V Healer listitem in the Mercenary Merchant Window.
	
	*listselect wasnt able to actually "select" items, it only "highlighted" them prior to this fix.
17 July 2013 by EqMule
- Added comboselect*
	Example: /notify MMTW_MerchantWnd TypeComboBox comboselect 2
			 Will select Journeyman Mercenaries in the Mercenary Merchant Window.
	
	*listselect still works when you just need to "set" an item in a combobox
	but when you want it to actually do the "select" use comboselect.

16 July 2013 by EqMule
- Updated for Jul 16 patch
- Added Item.Damage (thanks to nod77)
- Added new TLO GetCurSel (thanks to Dewey2461) see http://www.macroquest2.com/phpBB3/viewtopic.php?f=30&t=18947
- report bugs to me on irc or on the forum

22 June 2013 by ieatacid
- Fixed window.Enabled

20 June 2013 by EqMule, ieatacid
- Updated for Jun 19th patch

2 June 2013 by ieatacid
- MacroQuest.GameState now returns 'PRECHARSELECT' when applicable

17 May 2013 by EqMule, ieatacid
- Updated for May 14th patch

21 April 2013 by ieatacid
- MQ2Map fixed

21 April 2013 by ieatacid, EqMule
- Updated for April 17th patch

21 March 2013 by ieatacid
- Fixed keybind issues (?)

16 March 2013 by ieatacid
- Updated for March 13th/14th patch

16 February 2013 by ieatacid
- Updated for Feb. 13th/14th patch

20 January 2013 by ieatacid
- Fixed _CXWND.pParentWindow crash
- Fixed MQ2ItemDisplay crash

19 January 2013 by ieatacid
- Fixed MQ2ItemDisplay
- Fix corpse crashes
- Fixed a couple inventory struct members that were off -- item.stack and some others should work correctly now
- Fixed Me.Pet

18 January 2013 by ieatacid
- Updated for January 16/17 patch

4 January 2013 by ieatacid
- Fixed _ITEMINFO.Clairvoyance
- Fixed HasExpansion function

24 December 2012 by ieatacid
- MQ2ItemDisplay: fixed duplicate spell data being displayed

13 December 2012 by ieatacid
- Updated for December 12th patch
- FIXED OLD COMPILER WARNINGS

9 December 2012 by ieatacid
- Added ability to check if your account has a specific expansion enabled
... bool character.HaveExpansion[n]: Check if you have an expansion by number
... bool character.HaveExpansion[name]: Check if you have an expansion by name (full name not abbreviation)
... Added function for checking expansion availability. See HasExpansion function in MQ2Utilities.cpp for more info
- Added access to aggro data
... int character.PctAggro: Your aggro percentage
... int character.SecondaryPctAggro: Secondary aggro percentage
... spawn character.SecondaryAggroPlayer: spawninfo for secondary aggro player
... spawn character.AggroLock: spawninfo for aggro lock player
... int target.PctAggro: target's aggro percentage on you (same as character.PctAggro)
... int target.SecondaryPctAggro: target's secondary aggro percent (same as character.SecondaryPctAggro)
... spawn target.SecondaryAggroPlayer: spawninfo for target's secondary aggro player (same as character.SecondaryAggroPlayer)
... int groupmember.PctAggro: group member's aggro percentage
... int xtarget.PctAggro: xtarget's aggro percentage

3 December 2012 by ieatacid
- Fixed MQ2Bzsrch.  bazaaritem.Value has been removed because it's no longer sent with the item data

29 November 2012 by ieatacid
- Fixed alternate ability bug
- Fixed Me.CombatState
- MQ2Bzsrch is still broken, don't load it

28 November 2012 by ieatacid
- Updated for today's patch

23 November 2012 by ieatacid
- Fixed MQ2FPS (it once again stops rendering)

15 November 2012 by ieatacid
- Fixed custom chat channel join/leave messages not firing

12 November 2012 by ieatacid
- Fixed UI crashes

10 November 2012 by ieatacid
- Fixed alt ability bug

9 November 2012 by ieatacid
- Updated for November 7th patch
- Due to the introduction of ASLR into the client, offset names in eqgame.h have been changed as it was the easiest route to take in adapting the code base
- A function has been added to MQ2Inlines.h for plugins that need to adjust their own offsets for ASLR: DWORD FixOffset(DWORD nOffset);
... It takes the offset as a parameter and returns the recalculated offset

18 September 2012 by ieatacid
- Updated for patch on the 16th

25 September 2012 by ieatacid
- Updated for patch

19 September 2012 by ieatacid
- Updated for patch

16 August 2012 by ieatacid
- Updated for patch

19 July 2012 by dkaa, ieatacid
- Updated for patch

27 June 2012 by ieatacid
- Updated for patch

13 April 2012 by ieatacid
- Updated for patch

31a March 2012 by dkaa
-- Fixed DeleteAll, which was crashing MQ2Tracking...

31 March 2012 by dkaa
-- Fixed MyTradeReady, etc
-- Fixed various window crashes
-- Broke all the plugins that create their own window.  While consolidating some code, I ran into the problem that Show is both member data and function.  Do the data member changed to dShow, which means plugins like MQ2BagWnd have to change too.

23 March 2012 by ieatacid, dkaa
- Updated for March 22nd patch
- Added mapfilter TargetPath
... when enabled, right-clicking a spawn on the map will make it your target and draw a path to it on the map and in the world
... off by default

03 February 2012 by dkaa
- Kill launchpad if we are injected.  Launchpad is snooping into all processes.

15 January 2012 by dkaa
- Updated to fix /lootall

17 December 2011 by ieatacid
- Updated for today's patch

15 December 2011 by ieatacid
- Fixed spell manager crash

14 December 2011 by ieatacid
- Updated for today's patch

23 November 2011 by ieatacid
- Fixed _EQINVSLOTWND struct
- Added Me.GemTimer to retrieve the refresh time on spell gems, returns ticks type

18 November 2011 by ieatacid
- Updated for November 15th patch

11 October 2011 by ieatacid
- Fixed Me.TributeTimer

15 September 2011 by ieatacid
- Updated for today's patch

19 August 2011 by ieatacid
- Fixed some campfire stuff

30 June 2011 by ieatacid, dkaa
- Updated for today's patch

28 April 2011 by dkaa
- updated for the patch

20 April 2011 by dkaa
- fix for XTarget -- thanks, drkrain

19 April 2011 by dkaa
- added Me.SkillCap

14 April 2011 by ieatacid
- Updated for April 13th patch

6 April 2011 by ieatacid
- Added Me.MercenaryStance -- returns current active mercenary stance as a string, default is NULL

23 March 2011 by dkaa
- Fixed GetSTMLText -- you need the new eqbcs
- Fixed SetSTMLText -- you need the new eqbcs
- Fixed AppendSTMLText -- you need the new eqbcs
- Added a constant for the chat font offset so the /bcfont will work again
- Added the class CXStr &  CXStr::operator=(class CXStr const &) offset.
- This is all brainiac's fault.

17 March 2011 by dkaa
-  Jaysus, a patch on Paddy's day.

9 March 2011 by ieatacid
- Updated for today's patch

5 March 2011 by dkaa
- Fixed window.Enabled

19 February 2011 by ieatacid
- Me.Aura now returns the effect name as a string instead of a spell type.  If you need access to the spell data, look it up using the Spell TLO

17 February 2011 by ieatacid
- Updated for today's patch

15 February 2011 by dkaa
- fixed NoDrop again

13 February 2011 by ieatacid
- Fixed item.NoDrop
- Me.Aura now returns the name of the effect in the aura window if it can't find the matching spell
- _FELLOWSHIPINFO fix (thanks, Drakhhen)
- Fixed CListWnd::DeleteAll function offset (thanks, brainiac)

12 February 2011 by ieatacid, dkaa
- Updated for February 9th and 11th patches

16 January 2011 by dkaa
- Fixed IsNamed for some of the newer zone.  Thanks, el_nene.

16 January 2011 by ieatacid
- Fixed spawn.Levitate
- Fixed Me.FreeInventory

13 January 2011 by ieatacid
- Updated for today's patch

8 December 2010 by ieatacid
- Updated for today's patch

7 December 2010 by ieatacid
- Fixed "/click left" crash

4 December 2010 by ieatacid
- Added Me.Haste which reports total haste as it appears in the stats tab of the inventory window
- Changed EQ_Character::DoCombatAbility to return bool instead of void, as it is in the client

16 November 2010 by ieatacid
- Fixed for Me.FreeInventory

10 November 2010 by ieatacid
- Updated for today's patch

9 November 2010 by ieatacid
- Fixed /lootall crash

5 November 2010 by dkaa
- Fixed RightClickedOnPlayer
- Fixed item.Stacks, item.FreeStacks, and item.StackCount

1 November 2010 by ieatacid
- Fixed GetFullZone and GetShortZone crashes

29 October 2010 by dkaa
- Fixed SelectedItem and some crashes

26 October 2010 by ieatacid
- Updated for today's patch

23 October 2010 by dkaa
- Fixed the loot window and looting

22 October 2010 by dkaa
- Fixed the VC6 compile issue.
- Fixed some crashes.
- Fixed FindItem so it returns the correct slot.

21 October 2010 by ieatacid, dkaa
- Updated for today's patch
- Bug fixes and code changes for the October 16th patch

16 October 2010 by ieatacid, dkaa
- Updated for October 12th patch

15 September 2010 by ieatacid, dkaa
- Updated for today's patch

8 September 2010 by ieatacid, dkaa
- Updated for today's patch

18 August 2010 by ieatacid
- Updated for today's patch

29 July 2010 by dkaa
- Fixed a problem with Dar.  Thanks, Minymezz

28 July 2010 by ieatacid
- Updated for today's patch
- Adjusted /doability to look for your abilities in a similar way the client does, further eliminating it relying on abilities being mapped to action window buttons

14 July 2010 by ieatacid, dkaa
- Updated for today's patch

9 June 2010 by ieatacid
- Updated for today's patch

13 May 2010 by dkaa
- made the chat window history a constant to promote harmony

13 May 2010 by ieatacid
- Updated for today's patch
- Fixed Me.Dar and Me.Buff.Dar

12 May 2010 by ieatacid
- Updated for today's patch

10 May 2010 by ieatacid
- Fixed the 'listselect' window notification so you no longer need to 'leftmouse' and 'leftmouseup' after. Macros will need to be adjusted accordingly

14 April 2010 by ieatacid
- Updated for today's patch

10 March 2010 by ieatacid
- Updated for today's patch

13 January 2010 by ieatacid
- Updated for today's patch

7 January 2010 by dkaa
- Fixed the buff count to 30, song count to 20

24 December 2009 by ieatacid
- Added Me.XTarget.  See wiki for details: http://www.macroquest2.com/wiki/index.php/DataType:xtarget

18 December 2009 by SwiftyMUSE
- Updated for today's patch

15 December 2009 by SwiftyMUSE
- Updated for today's patch

14 December 2009 by dkaa
- Fix for AltAblity and Underfoot

8 December 2009 by ieatacid, SwiftyMUSE
- Updated for today's patch

19 November 2009 by ieatacid
- Updated for today's patch

18 November 2009 by dkaa
- added npccorpse and pccorpse to the spawn search filters

14 November 2009 by ieatacid
- Fix for EQMERCHWINDOW struct which will fix various things that reference it

14 November 2009 by dkaa
- Fix for labels -- added CLABELWND which is not, in fact, a CSIDLWND

13 November 2009 by dkaa
- Fix for inventory problems (corrected InvSlotWnd)

12 November 2009 by ieatacid, dkaa, SwiftyMUSE
- Updated for November 11th patch

21 October 2009 by ieatacid
- Updated for today's patch

8 October 2009 by ieatacid
- Updated for today's patch

21 September 2009 by ieatacid
- FindItemCount TLO now searches for augs on items

15 September 2009 by SwiftyMUSE
- Updated for today's patch

6 September 2009 by dkaa
- added el_nene's FromData changes

6 September 2009 by ieatacid
- Added spawn.Following which returns the spawn that a player is /following, or your pet's target

31 August 2009 by ieatacid
- Fixed _SPELL struct that changed in July
- Changed GAMESTATE_PRECHARSELECT from '6' to '-1'

19 August 2009 by ieatacid
- Updated offsets for today's patch

17 August 2009 by ieatacid
- Mouse_Aux3, Mouse_Aux4, Mouse_Aux5 added to dikeys.h

16 August 2009 by ieatacid
- Added mouse buttons to dikeys.h (Mouse_Mid, Mouse_Aux1, Mouse_Aux2).  This should let you /bind them now and eliminate associated crashes

14 August 2009 by pms
- fix for shownames
  http://www.macroquest2.com/phpBB2/viewtopic.php?t=16365

14 August 2009 by brainiac, dkaa
- Updated for the 08/12 patch

15 July 2009 by SwiftyMUSE
- Updated for today's patch

14 July 2009 by SwiftyMUSE
- Changed NUM_SPELL_GEMS to reflect the additional 2 added by the devs.

3 July 2009 by ieatacid
- Fixed /loadspells and other functions that rely on the _SPELLFAVORITE struct
- Updated MQ2ItemDisplay -- it now shows our extra item info when the modified/unmodified button is pressed (thanks pms for the idea)

29 June 2009 by ieatacid
- gGameState now gets set correctly when camping to desktop or server-select screen

24 June 2009 by ieatacid
- Reverted changes to CleanUI detour to fix MQ2ChatWnd crash when reloading the UI
- Changed tooltip handling in MQItemdisplay to work more efficiently and fix a bug with the left ear slot

24 June 2009 by SwiftyMUSE
- Updated for today's patch

21 June 2009 by ieatacid
- Fixed suffix display bug in captions (the error was in _SPAWNINFO)

20 June 2009 by SwiftyMUSE
- Backed out bug fix for MQ captions.
- Generate correct gGameState when camping (server/desktop).  This should fix random crashes in plugins when they think they are still "INGAME" but are really at server select screen.

18 June 2009 by SwiftyMUSE, ieatacid
- Updated for today's patch
- Added NUM_BUFF_SLOTS to handle the everchanging number of buffs in the target and pet windows.

17 June 2009 by SwiftyMUSE
- Added the command history functionality to MQ2ChatWnd (thanks PMS)

15 June 2009 by dkaa
- Fixed bug NoDrop on items on FV and other special servers

15 June 2009 by SwiftyMUSE
- Fixed bug with flashing MQ captions.
- Fixed bug with tooltips.  If you had a clicky item equipped in the left ear, the target window (and possibly others) would show tooltips baseed on "item name(ready)" instead of "buff name (time remaining)".
- Added filtering of macro ended messages.
- Added additional functionality to MQ2ChatWnd (thanks PMS)
   The window will redraw right away when you reload your UI in game, rather than waiting for the first text output request to recreate itself. 
   AutoScroll - on by default/normal behavior 
   NoCharSelect - off by default/normal behavior 
   SaveByChar - on by default/normal behavior 

12 June 2009 by SwiftyMUSE
- Updated for today's patch

11 June 2009 by ieatacid
- Fixed /unload crash on Windows 7 (and Vista?)

11 June 2009 by SwiftyMUSE, dkaa
- Fixed target.buff

10 June 2009 by ieatacid, SwiftyMUSE
- Updated for today's patch

21 May 2009 by SwiftyMUSE
- Updated for today's patch

15 May 2009 by ieatacid, dkaa
- Fixed guild struct and related functions
- Fixed pet window struct
- Removed MAX_GUILDS as it is no longer used

14 May 2009 by SwiftyMUSE
- Updated for today's patch

6 May 2009 by ieatacid
- Added spawn.Owner which returns a spawn type for a mercenary's owner

26 April 2009 by ieatacid
- Fixed group role issues

08 April 2009 by ieatacid
- TOTAL_SPELL_COUNT fix

07 April 2009 by SwiftyMUSE, dkaa, ieatacid
- Updated for today's patch

29 March 2009 by ieatacid
- Added Me.Mercenary which returns one of the following: SUSPEND, ACTIVE, NULL, UNKNOWN

21 March 2009 by ieatacid
- Me.CombatAbilityTimer and Me.CombatAbilityReady should now function correctly

19 March 2009 by SwiftyMUSE
- Updated for today's patch

15 March 2009 by ieatacid
- Fix for active leadership abilities
- Fix for GetCombatAbilityTimer crash (dkaa)

12 March 2009 by ieatacid, SwiftyMUSE
- Updated for today's patch

09 March 2009 by SwiftyMUSE
- Fixed aura (by name).  You can determine if an aura is active with Me.Aura[#aura name effect].ID
- Fix for buff stacking issue
- Cleaned up merc names for Group.Member[#]

12 February 2009 by dkaa, ieatacid, SwiftyMUSE
- Fixed pet buff window information/stackspet
- Fixed NPCCorpse mapfilter toggle

12 February 2009 by ieatacid, SwiftyMUSE
- Updated for the patch on the 11th

9 February 2009 by SwiftyMUSE
- Added exact match option to spawn searchs (use a "=" immediately preceeding the name being searched for)
- Updated named mob identification.  Named mobs will not exist in non-combat zones and warders, familiars, etc. have been demoted from their named status.
- Added /mapfilter option for named spawns (will toggle between named/normal npcs when npc filtering is active)
- Updated /mapfilter corpse as a master toggle for PC/NPC corpses.  When active, you can toggle PC/NPC filtering using PCCorpse/NPCCorpse respectively.
- Added Faycites, Chronobines as additional alternate currencies

31 January 2009 by dkaa
- added "targetable" as a spawn search modifier

20 January 2009 by ieatacid, dkaa
- Updated for today's patch

18 January 2009 by ieatacid
- Adjusted spawn types for banners.  The client lists the following races as banners: 500, 553-557, 586

17 January 2009 by ieatacid
- Added "/mqclear" command to MQ2ChatWnd which, you guessed it, clears the MQ2 chat window.  This does it the right way and removes all text from the window, unlike some plugins I've seen that just add 11ty new lines (\n) to the chat window
- Fixed "/setautorun".  It was saving incorrectly so AutoRun ini entries would never be processed (thanks pms)
- The "/dosocial" command should now work properly

11 January 2009 by ieatacid, SwiftyMUSE
- Events will once again trigger on "You have entered <zone name>."
- Completed formatting corrections for using spaces vs. tabs
- Corrected bug with spawnsearch.  Spawn[id 0] WILL NO LONGER return the same values as ${Me}.  You have been warned.
- Corrected spell stacking bug with some new spells (.Stacks/.WillStack)

29 December 2008 by dkaa
- added params to the /exec command (thanks three-p-o)

11 December 2008 by dkaa
- fixed a bug in the pet window with BuffFadeETA
- turned of macro error logging by default because it causes crashes if the log file is unwriteable

11 December 2008 by SwiftyMUSE
- updated for today's patch

10 December 2008 by SwiftyMUSE, ieatacid, dkaa
- updated for today's patch

10 December 2008 by dkaa
- Macro errors are now logged to a file

29 November 2008 by ieatacid
- Removed window manager drawing of the cursor on each pulse while in screen mode 3 (UI hidden) -- not needed since EQ switched to using Windows' cursor

05 November 2008 by ieatacid
- Fixed caption crash that happened on some untargetables
- Added "Flyer" spawn type for spawns that appear in some zones with NaN location data, which will filter them from NPC spawns
- Fixed Me.Aura bug when passing a number to it

03 November 2008 by dkaa
- added Triple Attack to skills.h

29 October 2008 by SwiftyMUSE
- Updated for today's patch

27 October 2008 by ieatacid
- Removed BuffUpdate from the target type. It's no longer cleared when you switch/release targets and, as such, serves no real purpose

22 October 2008 by ieatacid
- Added mercenary as a spawn type and map filter option
- Added bool mercenary to groupmember type
- Me.Aura now can now receive an index to access more than one aura (no index defaults to the first aura)

21 October 2008 by SwiftyMUSE
- Updated for October 21st patch

19 October 2008 by dkaa
- fixed the problem with the first line of macro not being run if /macro 
    was invoke within a macro.

17 October 2008 by SwiftyMUSE
- Added Spawn.Loc and .LocYX.  Loc is a float formatted string, LocYX is an int formatted string.
- Display permanent buff timers as "Perm" not "-0:18"
- Misc source cleanup

12 October 2008 by ieatacid
- Added BuffDuration to target type. It takes the buff name or number as a parameter and returns a ticks type.
- Added to Group TLO: string MainTank, string MainAssist, string Puller
- Added to groupmember type: bool MainTank, bool MainAssist, bool Puller

11 October 2008 by SwiftyMUSE
- Update mappable commands with all correct values, looks like it was not done in initial patch
- Update for Me.State.  If you are on a mount it will return "MOUNT" instead of continuing on and returning "STAND"

11 October 2008 by dkaa
- Fix for mappable commands -- thanks, brainiac
- Fix for class type 71, merc liaison.

10 October 2008 by dkaa
- Fix for VC6 compile problems.

09 October 2008 by ieatacid
- Changed target TLO. It now uses the new TargetType which inherits the spawn type.  The TargetType contains the following members:
   Buff (access to spell type): returns the target's spell by index (${Target.Buff[n]}) or name (${Target.Buff[name]}).  If no index is given (${Target.Buff}) it returns the first spell name or "NULL" if the target has no buffs
   BuffCount: returns the number of buffs on the target
   BuffUpdate: since there's a delay between when you target a spawn and when you get their buff data, this lets you know if the buff data is available
      
09 October 2008 by ieatacid, dkaa, SwiftyMUSE
- Updated for October 7th patch
- Added spawn type members: CurrentMana, MaxMana, Current Endurance, MaxEndurance -- these behave like CurrentHPs (only updated when you target a spawn)

08 September 2008 by ieatacid
- Added Level to groupmember type

07 September 2008 by SwiftyMUSE, ieatacid
- Fixed Group.Member[x].Name and .Leader 

06 September 2008 by SwiftyMUSE
- Fixed Group.Member[x].Name

05 September 2008 by SwiftyMUSE
- Fixes for group CTD issues
- Added Group.GroupSize back in... it's in the html manual but wasn't in the source

05 September 2008 by SwiftyMUSE, dkaa
- Fix for v6 compiles

05 September 2008 by ieatacid, SwiftyMUSE, dkaa
- Updated for today's patch

21 August 2008 by dkaa
- Add Tradeskills to TLO Item courtesy of brainiac

20 August 2008 by ieatacid
- Added Counters to the character type (total number of detrimental counters you have) and Counter to the buff type (counters per buff)

11 August 2008 by ieatacid
- Updated for today's patch

17 July 2008 by ieatacid, SwiftyMUSE
- Updated for today's patch
- Added a bunch of stat bonus stuff to the character type (differentiation).  See this thread for more info: http://macroquest2.com/phpBB2/viewtopic.php?t=15646

14 July 2008 by ieatacid
- Added "PCCorpse" map filter to MQ2Map, "Corpse" filter now just works on NPC corpses. Default color is the same as default NPC corpse color.

14 July 2008 by dkaa
- Fixed the pet info wnd struct

9 July 2008 by ieatacid, SwiftyMUSE
- Updated for today's patch

19 June 2008 by dkaa
- added augs to item TLO -- thanks dewey2461

19 June 2008 by dkaa
- HeroicWIZ is now HeroicWIS -- thanks dewey2461

09 June 2008 by ieatacid
- Added raidmember Raid.MainAssist
- Added function EQPlayer *GetSpawnByName(char *spawnName)
- Changed some stuff that used map::SpawnByName to use GetSpawnByName (should fix other stuff)

29 May 2008 by ieatacid, dkaa, SwiftyMUSE
- Updated for today's patch

23 May 2008 by SwiftyMUSE
- Updated class descriptions (DoN Merchants / Fellowship Registrar)

22 May 2008 by SwiftyMUSE, ieatacid
- Updated for today's patch

22 May 2008 by SwiftyMUSE
- Added dead, stunned, hovering to Spawn TLO
- Fixes to getspellduration

12 May 2008 by dkaa
- Added Friends TLO

7 May 2008 by SwiftyMUSE, ieatacid
- Updated for today's patch

24 April 2008 by SwiftyMUSE, ieatacid
- Updated for today's patch

17 April 2008 by SwiftyMUSE, ieatacid, dkaa
- Updated for today's patch

1 April 2008 by ieatacid, dkaa
- Updated for today's patch

17 March 2008 by ieatacid
- Redid item tooltip timers to just use one hook.  This also allows timers to be displayed when all bag tooltips are displayed (i.e., <alt>+<mouse over> a bag)

10 March 2008 by dkaa
- Fix for #XXXXXX color processing. Thanks QuestionTheAnswers.

7 March 2008 by ieatacid
- "some dev please do a new zip and be sure it contains the new ISXEQ.NET folder, thx (Lax)"

28 February 2008 by SwiftyMUSE, ieatacid
- Updated for today's patch

7 February 2008 by ieatacid
- Fixed /buyitem and /sellitem to work with stacks of up to 100 -- includes a sanity check so you don't request a stack size from the server that's greater than what's allowed for that item (so, theoretically, you can do "/buyitem 100" on everything to always buy the max stack size of the selected item)

6 February 2008 by ieatacid, SwiftyMUSE
- Updated for today's patch

26 January 2008 by ieatacid
- Added ticks type Me.Downtime (the time left on your combat timer)
- Added to the item TLO: EnduranceRegen, HealAmount, Clairvoyance,
  DamageShieldMitigation, SpellDamage, and all the Heroic stats

21 January 2008 by dkaa
- Added a list of actor defs for ground items.

19 January 2008 by SwiftyMUSE
- Fixed /lootall command

18 January 2008 by SwiftyMUSE
- Added Macro.Paused, Spawn.StandState

17 January 2008 by ieatacid, SwiftyMUSE, dkaa
- Updated for latest patch

2 January 2008 by ieatacid
- Changed "/cast item" so that it should now work on all items

24 December 2007 by ieatacid
- Added adjustable HUD font size (off by default)
   To enable it set "UseFontSize=on" in the [MQ2HUD] section
   in MQ2HUD.ini and edit each HUD line to match this format:
      TYPE,SIZE,X,Y,RED,GREEN,BLUE,TEXT
   Example:
      LastTell=3,2,401,0,255,0,LastTell:  ${MacroQuest.LastTell}
   becomes this with a font size of 4:
      LastTell=3,4,2,401,0,255,0,LastTell:  ${MacroQuest.LastTell}
   * Valid sizes are 0-11.

17 December 2007 by dkaa
- Added brainiac's /mqfont fix

12 December 2007 by ieatacid, dkaa
- Updated for today's patch

7 December 2007 by SwiftyMUSE
- added new /lootall command
- removed rk. II/III spell handling... use exact spell names
- fixed /zonehud command and hud zone processing
- added MQ2 crash detection processing back in

5 December 2007 by ieatacid
- Updated for today's patch

25 November 2007 by ieatacid
- "/shift /click right target" will now loot all items on a corpse

20 November 2007 by SwiftyMUSE, ieatacid
- Updated for today's patch

17 November 2007 by dkaa
- fixed SPELLFAVORITE
- fixed the crappy Rk. II/III handling
- fixed a crash on zoning

14 November 2007 by ieatacid, SwiftyMUSE, dkaa
- Updated for November 13th patch

8 November 2007 by SwiftyMUSE, ieatacid
- Updated for today's patch

30 October 2007 by ieatacid, SwiftyMUSE
- Updated for today's patch

08 October 2007 by dkaa
- fixed calc where '...) - <expr>' was treated as negate instead of subtract

27 September 2007 by dkaa
- fixed /next

17 September 2007 by ieatacid
- Added Me.Fellowship
  * fellowship  type members:
      int ID: fellowship ID
      string Leader: leader's name
      string MotD: message of the day
      int Members: number of members in fellowship
      fellowshipmember Member: member info by index (1-9) or name
      ticks CampfireDuration: how much time is left on campfire
      float CampfireY: self explanatory
      float CampfireX: "
      float CampfireZ: "
      zone CampfireZone: zoneinfo for the campfire
      bool Campfire: TRUE if campfire is up, FALSE if not
      to string: TRUE or FALSE
  * fellowshipmember type members:
      zone Zone: zoneinfo for this player
      int Level: this player's level
      class Class: class info for this player
      ticks LastOn: when this player was last online
      to string: player name

7 September 2007 by ieatacid
- Updated for patch

6 September 2007 by ieatacid
- Updated for patch

15 August 2007 by ieatacid, SwiftyMUSE, dkaa
- Updated for patch(es)

25 July 2007 by ieatacid, dkaa
- Updated for today's patch

23 July 2007 by SwiftyMUSE
- Added Campfires to spawn searchs and mapfilters

16 July 2007 by dkaa
- fixed NearestSpawn to work correctly with loc

12 July 2007 by ieatacid
- Updated for Today's patch
- Wrote our own version of EQ's get_melee_range function (thanks Purple for the help with fcomp flags!).
- Added more stuff to item TLO

6 July 2007 by ieatacid, SwiftyMUSE
- Updated for July 5th patch
- Some of the text coloring was removed from MQ2ItemDisplay since EQ now colors the item name green or red if you can or can't use the item (EQ also handles this text differently now).

17 June 2007 by ieatacid
- '/click left <x> <y>' works again.  It's now possible to
  click tradeskill containers and ground spawns.  This only
  works on the actual game play environment.  It does not
  work on UI windows (there are existing commands for that)
  or anything out of the viewport area.
- Added '/click left center' to click the center of the viewport area
- Added the following to the macroquest TLO:
  * ViewportX - left edge of the viewport area
  * ViewportY - top edge of the viewport area
  * ViewportXMax - right edge of the viewport area
  * ViewportYMax - bottom edge of the viewport are
  * ViewportXCenter - center of the viewport area going from left to right
  * ViewportYCenter - center of the viewport area going from top to bottom
  * LClickedObject - successfully clicking a ground spawn, TS container,
    NPC, or PC (using '/click left center|<x> <y>') will set this to TRUE
- Removed the /mouseto command since it no longer did anything

10 June 2007 by SwiftyMUSE, dkaa
- Added clicking links with /notify.  Use /notify ChatWindow CW_ChatOutput link <link structure>
  The link structure consists of 44 characters of the link starting with the 2nd character of the item id (ie, drop the leading 0).

9 June 2007 by ieatacid
- Tell windows will now trigger events and '#chat tell'

6 June 2007 by ieatacid
- Updated for today's patch

28 May 2007 by ieatacid
- Added character TLO members Doubloons, Orux, Phosphenes and Phosphites (alternate currencies)

20 May 2007 by ieatacid
- Added item TLO members Power and MaxPower (both for power sources) and Purity

19 May 2007 by dkaa
- added a bunch more stuff to the item TLO

18 May 2007 by dkaa
- added AC, HP, STR, STA, AGI, DEX, CHA, INT, WIS, Mana for items.  thanks equser2002.

17 May 2007 by dkaa
- Fixed the chat wnd

16 May 2007 by ieatacid
- Updated for today's patch

20 April 2007 by ieatacid
- Updated for today's patch

19 April 2007 by dkaa, ieatacid, eqmule
- fix for opcode detection to restore plugin zoning functions
- outgoing messages via SendEQMessage are disabled.  this means
    /click left item, /bzsrch, and /pricecheck are not functional

18 April 2007 by ieatacid, dkaa
- Updated for today's patch
- Updated MQ2EQBugFix to stop a crash that occurs when going from character select to server select (thanks cronic).  This may only be WinEQ2-related, but it's there should you want to use it.

6 April 2007 by SwiftyMUSE
- Added Banners to spawn searchs and mapfilters
- Spell stacking changes are back...
.. Stacking of spells with themselves will occur again.  For .Stacks and .StacksPet they take
.. a new parameter [###].  This will check the duration left on the spell, if the duration left is
.. less then the parameter value the spell will show it stacks with itself.  To retain old behavior
.. use [0] for the parameter (.Stacks[0] and .StacksPet[0] retain old behavior)
.. example - .Stacks[4] will return TRUE when less then 4 ticks remain on the spell buff in question

5 April 2007 by ieatacid
- Updated for today's patch

15 March 2007 by ieatacid, dkaa
- Updated for March 14th patch

21 February 2007 by ieatacid
- Updated for today's patch

19 February 2007 by SwiftyMUSE
- Fix for campfire objects
- Fix for short buffs
- Fix for label of last target on map

17 February 2007 by ieatacid
- Fixed _SPAWNINFO.Mount

17 February 2007 by ieatacid
- Fixed item Clicky/Proc/Worn/Focus stuff not working
- Added dkaa's _EQLOOTWINDOW fix (${Corpse.Item} stuff should now work correctly)

17 February 2007 by dkaa
- changed the EQ_END_ZONE to the correct value
- changed the bag slot numbers to start at 262 from 251.  See: http://www.eqinterface.com/forums/showthread.php?p=94698&highlight=262#post94698

16 February 2007 by ieatacid, dkaa
- Updated for The Buried Sea expansion.  New "Power Source" item slot means slot changes:
 * Slots charm through waist are the same (0-20), "Power Source" is 21, 22 is ammo, 23 - 30 are inventory (bag) slots

17 January 2007 by ieatacid
- Updated for today's patch

14 January 2007 by SwiftyMUSE
- Fix for zone translocate spell information crash displaying items
- Changes to spell stacking (spells will say they stack with themselves)

12 January 2007 by ieatacid
- Fix for Me.Aura for Monk auras (spelling error on SoE's part :o)
- dkaa told me about an AuraMgr struct and how it relates to AuraInfo -.-
- Added charinfo svChromatic, svPrismatic (Charisa)

2 January 2007 by SwiftyMUSE
- Fix for npcs and objects

30 December 2006 by ieatacid
- Added DynamicZone TLO which has the following members
.. string Name
.. int Members
.. int MaxMembers
.. dzmember Member (number or string as a parameter)
.. dzmember Leader
.. to string - same as Name
- Added dzmember type, with members:
.. string Name
.. string Status - returns: Unknown, Online, Offline, In Dynamic Zone (no idea what this
   is, it's in the exe), Link Dead
.. to string - same as Name

23 December 2006 by SwiftyMUSE
- Updates for GetSpellEffectName, ShowSpellSlotInfo (differentiation, pinkfloydx33)
- Updates for Counters in datatypes (pinkfloydx33)

14 December 2006 by ieatacid
- Updated for today's patch

7 December 2006 by dkaa
- Fix for NoDrop & NoRent

6 December 2006 by ieatacid, dkaa
- Fixed for Dec 5th patch

7 November 2006 by ieatacid
- MQ2ChatWnd should now remain visible while in hover state

31 October 2006 by ieatacid
- Fix for Halloween crash

25 October 2006 by ieatacid, SwiftyMUSE
- Updated for today's patch

23 October 2006 by ieatacid
- Added Spell.MyRange.  This is YOUR actual cast range, including extended range from focus effects.

10 October 2006 by ieatacid
- Added "HOVER" for use with Me.State
- Added bool InHoverState() to MQ2Utilities.cpp

4 October 2006 by SwiftyMUSE
- Updated for today's patch

2 October 2006 by ieatacid
- Added "object" to /mapfilter. Objects are things like catapults, tents, practice dummies, etc.

27 September 2006 by ieatacid
- Updated for today's patch

23 September 2006 by dkaa, ieatacid
- fix for gbInZone, Me.FreeBuffSlots, AA-related stuff, MQ2EQIM compile errors

19 September 2006 by ieatacid
- Updated for Serpent's Spine expansion release. Many new changes - the important stuff is listed below
- Skill members SkillCapPre50, SkillCapPre65 and SkillCapPre70 were removed and replaced with int SkillCap.  This returns the skill cap based on your class and current level
- New character members:
    1) string CombatState - returns one of the following: COMBAT, DEBUFFED, COOLDOWN, ACTIVE, RESTING.  The same as the new icon in the player info window
    2) int svCorruption - character's Corruption resist
- Added Prismatic and Corruption to spell ResistType
- MQ2ItemDisplay now shows corruption resist
- "GREY" added to spawn.ConColor
- Plugin authors:
  * Skill stuff has been changed
      Lines like this:
        if(SkillDict[EQADDR_DOABILITYLIST[nSkill]]->AltTimer==2)
      Need to be changed to this:
        if(pSkillMgr->pSkill[EQADDR_DOABILITYLIST[nSkill]]->AltTimer==2)

3 September 2006 by ieatacid
- Changed the way we handle con-colors.  We now use EQ's function rather than calculate it ourselves.

30 Aug 2006 by dkaa
- incorporate change from Ceghkmv and teabag to fix the xml file stuff

28 August 2006 by ieatacid
- Changed spawninfo's pCharInfo member to 'void *pCharInfo_vtable2' since it points to vtable2 in charinfo and made changes where necessary to reflect this.
  Now things like "/itemnotify in bank1 1 leftmouseup" should work properly.
- Added spawn.Buyer

25 Aug 2006 by dkaa
- duel->dual
- aura fix for when you don't have an aura

15 August 2006 by ieatacid
- Added Me.ActiveFavorCost

5 August 2006 by Amadeus
* Added a new member to the 'string' datatype.
  1. Replace[ToReplace,ReplaceWith]
     a. This member will return a string replacing every instance of
        'ToReplace' with 'ReplaceWith'.  It will work for both strings 
        and individual characters.  IT IS CASE SENSITIVE.   
     ~ Example: echo ${Me.Name.Replace["Amadeus","Maestro"]}
                echo ${Me.Name.Replace[",","."]}  
* Added a custom 'label' that you can put in your macros -- ":OnExit".
  Anything included after that label will be called whenever an /endmacro
  command is issued.  To use this feature, the label must be at the end 
  of your 'Sub Main' function and end with a /return.  Please note that 
  this is NOT required of macros, so no macros will have to be altered 
  unless you wish to take advantage of this feature.  (See my posting
  on the messageboards for an example of how to use this.)

25 July 2006 by ieatacid
- Added leadership ability members to character type that return
  the ability level of *active* leader abilities.
  ** LAMarkNPC, LANPCHealth, LADelegateMA, LADelegateMarkNPC,
     LAInspectBuffs, LASpellAwareness, LAOffenseEnhancement,
     LAManaEnhancement, LAHealthEnhancement, LAHealthRegen,
     LAFindPathPC, LAHoTT.

20 July 2006 by dkaa
- Fix for the 7/18 patch
- Fix to the ITEMINFO size 

17 July 2006 by ieatacid
- Added spell Me.Aura (this applies to your self-aura that is shown in the aura window)

13 July 2006 by ieatacid
- Added to item type: Evolving which has the following members
      ExpPct
      ExpOn
      Level
      MaxLevel
    Example: ${FindItem[some evolving item].Evolving.ExpPct} 
- Some UI struct fixes
- /windowstate now works without screwing up the UI state

8 July 2006 by Amadeus
- Updated ISXEQ to compile a bit better with Visual Studio 2005
- Added ISXEQ project/solution file(s) for Visual Studio 2005.
  1. Double-click on "MQ2Auth.exe" (duh)
  2. Open Visual Studio 2005
  3. Click on File->Open->Project/Solution ..and select "ISXEQ-VS2005"
  4. Build All.
  5. The DLL files will be built in a directory in your primary MQ folder 
     called "ISXEQ Release Files".  Simply move all of the DLL files from
     that directory to your /InnerSpace/Extensions directory.
  ** You will get a few warnings; however, if your library/headers are set  
     up correctly and the ISXDK is installed properly, you should be able
     to compile out-of-the-box.
- Updated the VS2003 solution file ("ISXEQ") to include only ISXEQ projects
  and disable compilation of ISXEQLegacy (since it is currently broken).
- Please note that these VS2005 project files are only for ISXEQ.  If you
  still use MQ2, you can ignore this.



5 July 2006 by ieatacid
- added Me.Language (ex. ${Me.Language[1]} returns "Common Tongue"; ${Me.Language[Common Tongue]} returns 1)
- fixed zoned.cfg to load properly after zoning, also .cfg files that use zone short names

29 June 2006 by ieatacid
- added int MacroQuest.ChatChannels (returns number of channels currently joined)
- added MacroQuest.ChatChannel (ex. ${MacroQuest.ChatChannel[MQChat]} returns true if the channel "MQChat" is joined (bool); ${MacroQuest.ChatChannel[1]} returns the name of chat channel 1 (string))

28 June 2006 by SwiftyMUSE, ieatacid
- fix for 6/28 patch
- fix for gbInZone on initial load

27 June 2006 by ieatacid
- added bool Me.AutoFire

16 June 2006 by SwiftyMUSE, dkaa, ieatacid, and others...
- fix for 6/16 patch

10 June 2006 by SwiftyMUSE
- added Aura to spawn searches and mapfilter
- added spellradius to map for a second radius circle on the map

1 May 2006 by dkaa
- fix the previous fix

30 Apr 2006 by SwiftyMUSE
- added Me.TributeTimer, Me.RadiantCrystals, Me.EbonCrystals
- added Me.Shrouded, UseSkill, LoH/HT Ready (ieatacid)

20 Apr 2006 by SwiftyMUSE
- fix for isxeq compile issue

19 Apr 2006 by dkaa, SwiftyMUSE
- updated for 4/19 patch
- added spawn.IsNamed
- added personal tribute and radiant/ebon crystals to CHARINFO

31a Mar 2006 by dkaa
- fixed the VS6 build

31 Mar 2006 by dkaa
- Added stuff to item type
    Classes
    Class
    Races
    Race
    Deities
    Deity
    RequiredLevel
- Added DisplayItem TLO as item type to mq2itemdisplay
- Added /ireset to reset DisplayItem ID 

29 Mar 2006 by dkaa
- Fixed /sellitem

27 Mar 2006 by dkaa
- Fixed the CSidlScreenWnd struct

24 Mar 2006 by dkaa
- Fix the container manager struct

23 Mar 2006 by SwiftyMUSE
- Various cleanup from PoR patch
- Access to the 8 new bank slots

22 Mar 2006 by dkaa
- Added a message box for plugin load failure

16 Mar 2006 by Lax
- Various ISXEQ-related updates
- Blech updated to fix Feed reentrancy issue (not a problem in MQ2 macros, but with
  plugins it would have introduced crashes)

14 Mar 2006 by dkaa
- Added MacroQuest.Ping from ieatacid

04 Mar 2006 by Lax
- Various ISXEQ-related fixes.  Removed the &s from EzDetour to be consistent, and
  added the &s manually where required

03 Mar 2006 by dkaa
- fixed the loading screen captions
- fixed crash on right click on map on ground item

late Feb 2006 by lots of people
- stuff to get up and running after expansion
    
29 Jan 2006 by SwiftyMUSE
- Fix to spawninfo struct from merge

29 Jan 2006 by SwiftyMUSE
- Fix to re-add class based cfg file loading upon entering game
- Added global bool for telling if you are zoning or not (gbInZone)
- Added .GroupSize
- Fix to allow non-stackable items to return counts in .Stacks, .StackCount, .FreeStack
- Added LoS parameter to spawn searches

18 Jan 2006 by SwiftyMUSE
- Updated for 01/18 patch

05 Jan 2006 by dkaa
- Fixed the crash on re-entering the game

20 December 2005 by SwiftyMUSE
- Fixed to compile in VC++ 6.0

19 December 2005 by SwiftyMUSE
- Corrected offset comments in several structures
- Fixed Item.Timer issue for insta-click/instant refresh items
- Added item timers to potion belt window tooltips
- Added Item.StackSize, .Stacks, .StackCount, .FreeStack, .TimerReady
- Added class based cfg file loading upon entering game

16 December 2005 by dkaa
- Fix for Merchant.BuyPrice

15 December 2005 by SwiftyMUSE
- Fix for MaxMana, MaxEndurance

15 December 2005 by SwiftyMUSE, dkaa
- Fix for MaxHPs
- Fix for Item.timer

15 December 2005 by SwiftyMUSE
- Updated for 12/15 patch
- Fixes Item.Timer returning 0 too early
- Added Merchant.Full (thanks cronic)

13 December 2005 by SwiftyMUSE
- Fixed SWho display of primary/offhand for spawns
- Fixed blocking issue in .Stacks for heal conversion type spells
- Located more missing fields from 12/07 patch
- Added MQ2LoadingMsg to macroquest2.ini to allow you to configure 
  the MQ2 evolution in action message to be displayed or not.

12 December 2005 by SwiftyMUSE
- Fixed Me.Levitating

11 December 2005 by SwiftyMUSE
- Corrected offset comments in several structures
- Added /classhud and /zonehud commands. Automatically load [class] or [zonename] huds.
- Added SpeedMultiplier into spawninfo
- Fixed Item.Stack
- Fixed /doors command (_DOORS and _EQSWITCH structures changed). Other switches may have
  been effected and fixed with this also.

10 December 2005 by SwiftyMUSE, dkaa
- Updated for 12/07 patch
- PACTORINFO was removed, _ACTORINFO fields were merged into _SPAWNINFO
- Changed item.timer to a ticks type

5 December 2005 by SwiftyMUSE
- More cleanup of several class function declarations
- Another fix to .Stacks/.WillStack to not fail if the same slot is a blocking slot
- Added endurancecost to SPELL (thanks s0rCieR)
- Added item timer to tooltips (thanks ieatacid)

30 November 2005 by SwiftyMUSE
- Clean up of several class function declarations
- Cleanup of CombatAbilility, CombatAbilityReady and CombatAbilityTimer. They are now using
  the EQ functions. Cleanup of several functions to use EQ function GetAltAbilityIndex
  instead of accessing the charinfo structs directly.
- Fixed Me.State so it recognizes "STUN" correctly
- Fixed GetAAIndexByName, GetAAIndexByID
- Fixed Me.FreeBuffSlots to include the additional slot you get when you get either the
  "Embrace of the Keepers" or "Embrace of the Dark Reign" aa's.
- Fixed bounds issues on RequiresAbility, GetAANameByIndex, GetAAIndexByName, and GetAAIndexByID
- Fixed .Stacks/.WillStack to allow self buffs (with a healing component) to stack correctly
- Added: Spawn.Fleeing
    Currently this works with your target that is engaged in combat. If it turns to flee
    this flag is set for use in macros. It checks to see if the heading of the spawn is
    facing in a direction that is not in an arc of 120 degrees facing you.
- If you are crashing on switching toons at character select,
  you can comment out the autorun (per character) section in
  MQ2Pulse.cpp. This is only needed if you want to automatically
  process commands upon initial entering of world for a
  character. If you don't use the feature commenting it out will
  not cause any lose of functionality for you. Please post any CTD
  crash dumps to assist with locating this bug.

22 November 2005 by SwiftyMUSE
- Added Item.ItemDelay
- Config files can contain comment lines. Use ";" as the first character on the line to make it a comment.
- Updated resistadj location in _SPELL struct

18 November 2005 by SwiftyMUSE
- Fixed resists bug

18 November 2005 by dkaa
- Added TLOs DoorTarget and ItemTarget

17 November 2005 by Lax
- Separated functionality from do_ranged command for use from plugins.  Do this for any case where
  DoCommand has been used, and submit code changes.  This example has been done for you.

17 November 2005 by dkaa
- Added Cr4zyb4rd's hud extensions

16 November 2005 by SwiftyMUSE
- updated offset for 11/16 patch
- updated changes to charinfo struct for 11/16 patch

15 November 2005 by Lax
- Turned MacroQuest into swiss cheese with some more #ifdef blocks to support new ISXEQ functionality
  that allows it to run legacy MQ2 "macros"

11 November 2005 by dkaa
- remove the ability to use "fake" targets (door & items)
- added item timers to itemdisplay

01 November 2005 by dkaa
- updated offset for 11/01 patch
- /caption <list|type <value>|update #|MQCaptions <on|off>>

19 October 2005 by dkaa
- added item timers from ieatacid
- added stacks from pinkfloydx33

4 August 2005 by Lax
- Optimized stristr routine in Blech.h, resulting in a little bit of improved performance from Blech

31 Jul 2005 by Lax
- Nobody reported that Select didnt work until now, but the AddMQ2Data line is now added so it
  will work ;)

16 Jul 2005 by dkaa
- further fixes for else 

12 Jul 2005 by Lax
- Added Top-Level Object:
  * int Select[value,...]
    This replaces ${String[ x y z ].Find[ ${Stuff} ]}, like so: ${Select[${Stuff},x,y,z]}
    The result will be 0 for none, 1 for the first, 2 for the second, ad infinitum (no limit)
 
11 Jul 2005 by dkaa
- fixed the AltAbilityTimer members
- fixed else processing if there is not a "{" on the else line

05 Jul 2005 by dkaa
- fixed the AltAbilityReady and AltAbility members

04 Jul 2005 by dkaa
- prototypes for CListWnd::AddString changed (fixes mq2tracking)
- SwiftyMUSE change to XMLRead

03 Jul 2005 by dkaa
- prototypes for CSidlManager::FindScreenPieceTemplate and CComboWnd::InsertChoice changed

02 Jul 2005 by dkaa
- /aa list all should work now -- fixing AAs in progress
- CCustomWnd actually works with char * param in constructor

02 Jul 2005 by dkaa
- opcodes updated for zoning

02 Jul 2005 by dkaa
- String is still out
- fixed the AA stuff in CHARINFO
- CCustomWnd constructor now takes char * or CXStr *

26 May 2005 by Lax
- Fixed negation math operator, which was rounding the value negated

26 May 2005 by DKAA
- Plugins must have compile time later than mq2main.dll or they won't load

25 May 2005 by Amadeus
- Added Me.CombatAbilityReady and Me.CombatAbilityTimer
- Added:  /doability <combat ability>
- Added Me.Running 
- Added the command "/inote" for those running the ItemDisplay plugin,
  which is most everyone :)
- Currently AltAbilityReady returns TRUE when you inquire about 
  aa's you have not yet purchased. MQ2 now changes that behavior 
  to verify that you own the aa prior to saying its READY. 
- Fixed Me.SpellReady

21 May 2005 by Amadeus
- The MQ command known as '/charinfo' is now known as '/char'.  This allows
  for players to use both the EQ and MQ commands seperately.
- Fixed various structs
- Returned Me.Underwater and Me.FeetWet
  
13 May 2005 by DKAA
- Added optional param to Windows.List[...] to indicate column

11 May 2005 by Amadeus/DKAA
- Updated MQ2 to work with the 5/11/2005 patch
- Fixed Mapwindow structure
- Fixed Spellbuff structure
- Fixed Actorinfo structure
- Lots of other little fixes 

20 April 2005 by Amadeus
- Added some new offsets to eqgame.h including
  * pinstCGuildTributeMasterWnd
  * pinstCVoiceMacroWnd	
  * pinstCLFGuildWnd
  * pinstCGuildBankWnd
  * pinstCBarterWnd	
  * pinstCBarterMerchantWnd	
  * pinstCBarterSearchWnd
  * pinstCTicketWnd	
  * pinstCTicketCommentWnd]
  * pinstLargeDialogWnd	
  * pinstCTaskWnd
  * pinstCTaskSelectWnd	
  * pinstCPointMerchantWnd
  * pinstCPvpLeaderboardWnd	
  * pinstCTitleWnd	
  * pinstCPvpStatsWnd
  * pinstCMailWnd
  * pinstCMailCompositionWnd
  
4 May 2005 by Lax
- Fixed calculation bugs

17 April 2005 by Amadeus
- Added "Suffix" information to structs
- Added ${Me.Suffix} and ${Target.Suffix} 

8 March 2005 by Lax
- Blech 1.6.8 - fixes a crash

23 March 2005 by Lax
- Fixed this group member bug nonsense.  Now uses correct group structure.
- Fixed redundancy in GetSpawnType

11 March 2005 by Lax
- item.Spell fixed for scroll, proc, focus, and worn (previously did only clicky)

10 March 2005 by Lax
- CHARINFO update from htw, fixes the new Group stuff

9 March 2005 by dkaa
- refix the include file issue

8 March 2005 by Lax
- Fixed /itemslots
- Fixed problem with group.Leader when you are the leader and the group has members
- Added ISXEQ client templates to mkplugin

7 March 2005 by Lax
- Fixed the new group data types. Also added To String values:
  groupmember: Same as Name
  group: Same as Members

7 March 2005 by dkaa
- Fixed the Buff and Song ID members

6 March 2005 by Lax
- Added group datatype. members are as follows:
  * groupmember Member[n]: n is 1 to 5 (0 gives self)
  * int Member[name]: Gives the number, as used above
  * int Members: Total group members, excluding self
  * groupmember Leader: The leader of the group
- Added groupmember datatype. inherits spawn. members are as follows:
  * string Name: Name of the group member.  Should work regardless of whether they are in zone
  * spawn Spawn: Direct access to the group member's spawn type
  * bool Leader: Is this the group leader?
- Dropped GroupLeader TLO, now you should use Group.Leader
- Dropped GroupLeaderName TLO, now you should use Group.Leader.Name
- Group TLO now gives group datatype

3 March 2005 by Lax
- Fixed character.CurrentHPS, character.MaxHPS, character.PctHPS to use the "stable" versions..
- Added character members STR, STA, AGI, DEX, WIS, INT, CHA, svMagic, svFire, svCold, svPoison, 
  svDisease, CurrentWeight .. all of them ints
- Fixed buff slot counts

27 February 2005 by Lax
- Fixed INI bug in /mapnames
- Fixed bug in /mapfilter with "help"

26 February 2005 by Lax
- Optimized some stuff with the buff data type

25 February 2005 by Lax
- Removed bmpwad8.s3d file which was no longer being used, but was 33% of the size of the zip
- ISXEQ-related changes not affecting MQ2

23 February 2005 by Lax
- Cleaned up a bunch utility functions from MQ2Commands.cpp, they are now in MQ2Utilities.cpp

22 February 2005 by Lax
- Fix a Blech bug.

18 February 2005 by dkaa
- Update the ground interaction opcode

15 February 2005 by Amadeus
- Adjusted MQ2 to work properly with the new expansion
- Fixed some very small things

12 February 2005 by dkaa
- Fix an issue with /emote

11 February 2005 by Amadeus
- Added/Fixed some more spell slot information (item/spell display)
- Fixed the OnZoning callbacks in the Detour API
- Updated MAX_GUILDS (should fix guild name display problems)
- Updated MAX_ZONES in preparation for next expansion

8 February 2005 by Amadeus
- Fixed MQ2 to work with the latest patch
- Added spell information to the item display plugin
- There is now a file in the /release folder called "Changes-ISXEQ.txt", which will
  contain patch notes for the InnerSpace extension that is now included with MQ2.

31 January 2005 by Amadeus
- Fixed MQ2 to work with the latest patch
- The format of eqgame.h has CHANGED.  Be sure to get this zip. [SwiftyMuse]
- Browsing the wares of an adventure merchant still crashes EQ.  MQ2 is not to blame.

29 January 2005 by dkaa
- Fixed the map crash on /loadskin

29 January 2005 by Lax
- Split MQ2Main.h into a couple extra header files
- Added second project (ISXEQ.vcproj, no .dsp file at this time) to MQ2Main folder for 
  adaptation to Inner Space.  This project builds ISXEQ.dll and does NOT currently link (it
  compiles, then gives linker errors. some things need to be done before it will link)
  ISXEQ project needs separate implementations of each command, datatype, and top-level object.
- Added a lot of "#ifndef ISXEQ" to various files

26-28 January 2005 by Amadeus
- Once over, formatting/syntax check, re-package
- Fixed structs and offsets to be compatable with the new patch
- Fixed a variety of other small things to be compatable with the new patch
- Added a few little things from the boards as well as original work

4 January 2005 by Lax
- Updated copyright notices for 2005
- Updated Blech to 1.6.4, which fixed a tree traversal bug.  The bug prevented some 
  events from firing

31 December 2004 by Amadeus/DKAA 
- Fixed a line that was causing compile problems with VC++ 6.0 

30 December 2004 by Amadeus
-  Lots of little fixes
-  Fixed DOOR struct (which was causing some bugs with door related macro commands)
~  User Submitted Fixes (from message boards)
   * Added 'Me.FreeBuffSlots' to MQ2. [cr4zyb4rd]
   * Fixed Item "Stackable" flag [Valerian]
   * (Changed 'SpellReady' so SpellReady[] returns true when Gems are fading back 
     in from the disabled state. [Brettido]
   * Fixed 'MyCastTime' [cr4zyb4rd]
   * Added 'BuildDate' to the MacroQuest data members. [cr4zyb4rd]

19 December 2004 by Amadeus
- Cr4azyb4rd's code for the new item stuff, outlined in this thread:
  http://www.macroquest2.com/phpBB2/viewtopic.php?t=10270
- The Item Datatype 'Stackable' seems to be broken at the moment.  We will be looking
  into it over the next few days.
- Added "GuildFavor" to the ItemDisplay plugin (Ziggy)
- Added Ziggy's /mapshow patch
- Added Cronic's new Plugin API additions: OnBeginZone() and OnEndZone().  Folks may want
  to bookmark http://www.macroquest2.com/phpBB2/viewtopic.php?t=9959 as an example of how
  to add features to the plugin API.  (Hopefully this thread/example will make it in the 
  manual.)
- Added ${Me.EnduranceRegen} (submitted by Pooz).  It returns returns the amount of 
  endurance gained in the last tick. 

18 December 2004 by Amadeus
- Various structs/offsets taken from the boards to make MQ2 compatable
  with the latest patch
- Fixed keybinds
- Various small things from the boards over the past couple months
- Fixed spawninfo and actorinfo
** Note:  This is an initial zip release to get MQ up and running.  Expect another
          release in the next couple of days to resolve all remaining issues and
          to add code submitted on the boards. **

13 December 2004 by Lax
- Blech updated to version 1.6.3 which solves a new issue

8 December 2004 by Lax
- Blech updated to version 1.6.1 which solves remaining known Blech issues

22 November 2004 by Lax
- Blech updated to version 1.6 which solves parsing problems such as the one
  described here: http://www.macroquest2.com/phpBB2/viewtopic.php?p=75390#75390
- MQ2CustomBinds updated to solve a race condition issue, which also appears in
  older MQ2MoveUtils versions.  The race condition causes a crash when starting
  EQ via WinEQ 2.0
- The MQ2 initialization process now has a short delay to help alleviate the
  race condition issue for people who have not updated MQ2MoveUtils

25 October 2004 by Amadeus
- ${Me.AltAbility[]} is now back!   However, with one change.  Instead of 
  returning the 'rank', it now returns the total number of points you have
  spent in that ability.  Therefore, to determine if a player has bought an
  ability, all you have to do is check if the value is greater than zero.
- Added AALIST struct to eqdata.h and AA information to CHARINFO
- Fixed "/aa list xx" to stop showing multiple versions of the same AAs
- Fixed "/aa list timers" to only show AAs you have bought
- Added some new utility functions to the source (C++, NOT MACRO CODE)
  * bool PlayerHasAAAbility (PCHARINFO pChar, DWORD AAIndex);
  * PCHAR GetAANameByIndex(DWORD AAIndex)
  * DWORD GetAAIndexByName(PCHAR AAName)
  * DWORD GetAAIndexByID(DWORD ID)
~ User Submitted Fixes (from message boards)
  *  Add a "noauto" flag to your '/plugin' command to prevent 
     updating the macroquest.ini when a plugin is loaded/unloaded. 
  *  Added some more USERCOLOR_* definitions to eqdata.h
  *  Small fix to '/loadspells list'
  *  Added more spell information to the spell information display
  *  Added CastOnYou, CastOnAnother, and WearOff to the MQ2SpellType class
  *  Major upgrades to MQ2Irc plugin, see this thread for more information 
     http://www.macroquest2.com/phpBB2/viewtopic.php?p=73390#73390
     
14 October 2004 by Amadeus
- Removed the BuildData datatype for the moment.  The code, as it was originally 
  conceived was causing compile problems on Visual Studio 6.0.  Moreover, it was 
  determined that it was not reliable on all partition types.   It may be added
  again at some point in the future after rigorous testing across different
  partition types and both vs 6.0 and vs.net compilers.

13 October 2004 by Amadeus
- [*LAX*]  New Memcheck0 routine
- [*DKAA*] New Memcheck4 routine (the routine previously known as memcheck4 
           is now memchecks)
- New offsets/structs for latest patch
- Con Colors should be working properly to lvl 70
- spawn.CleanName should now return the name without the '#' symbol
- More work on mq2map ...it's still in heavy testing and needs more work though
- Added 'BuildDate' to the MacroQuest data members.  Returns an int representing
  the date in which the current MQ2Main.dll was built.
- Added a short message to warn you of a running macro when /camping.

23 September 2004 by Amadeus
- Fixed the MacroQuest2.exe to have correct links and added a few new links!
- Offsets fixed for recent patch
- Couple more spell gem 9 fixes

19 September 2004 by Amadeus
- Fixes related to the extra buff slots and extra spell gem for Omens of War.

17 September 2004 by Amadeus
- MQ2Map has issues and is being debugged in house.  I suggest turning it
  off until it officially fixed if you are having problems.
- Added ${xxx.Attuneable} for items ..returns TRUE if item is Attuneable, 
  FALSE if it is not.
- Added some code to MQ2MapApi.cpp in the debugging stage.  Most of it is
  redundant code hoping to cut down on problems.
- Miscellanous fixes throughout the source

14 September 2004 by Amadeus
- All the fixes needed to make MQ2 work with Omens of War
- The way that EQ handles the initial splash screen has changed dramatically.
  MQ's custom SplashScreen is disabled.
- Almost all structs were modified/fixed.
- Removed the offset CEverQuest__GetTitleDesc
- Added Title to spawninfo structure
- Added ${xxx.Title} ..it returns a string that is your title.  Please note that 
  ${xxx.AATitle} will return the same thing.  I'm leaving both in for backwards
  compatability of macros although "Title" should be used in the future since 
  Titles are no longer exclusively AA based.
- updated TOTAL_SPELL_COUNT 
- Added TOTAL_SPELLS_ALLOCATED
- EQ_Character__Max_Mana removed ...it's a virtual function now (This means that 
  the MaxMana and PctMana datatypes are disabled for now)

26 August 2004 by Amadeus 
- Fixed /filter name on/off to work correctly [Efudd]

20 August 2004 by Amadeus
- Removed ${Me.GroupMember[]} and ${Me.GroupLeader} since it is already in as 
  ${Group[n].Name} and ${GroupLeaderName}.  Even though the information is stored in
  two locations, it was causing confusion.
- Tweaked ${Me.Grouped} some more ...I think I have it fixed now.

19 August 2004 by Amadeus
- Fixed ${Me.AltAbilityReady[]}
- Fixed ${Me.AltAbilityTimer[]}
- Added ${AltAbility[].MyReuseTime}  (proper reuse time if you hastened AA abilties)
- Added NEW COMMAND:  /aa
*** Syntax ***
/aa list all            -- lists all of your AA abilities in format [ID : name]
/aa list timers         -- lists just the AA you have that have timers
/aa info [ability name] -- gives information about a particular AA ability
/aa act [ability name]  -- works like "/alt act ##", but takes the name instead of ##
   (note:  You will notice a fraction of a second delay using this method vs.
           the /alt act ## method.)
***
(Note:  Yes, they do not list in any particular order (No, I don't know why).  No, 
I do not know why some abilities are duplicated.  Yes, it may have bugs 
that need testing.)
- Slight tweak to code to make it compile on Vc++ 6.0 cleanly
- Fixed GetSpellDuration (per corrections posted on the messageboard)
- Added an offset to eqgame.h and removed one from eqgame.h (Those that help find
  offsets..please note this change!)

18 August 2004 by Amadeus
- Fixed EQRAIDWINDOW and EQRAID structs
- Some tweaking to attempt to make ${xxx.Grouped} more consistant
- Added:  ${Me.GroupMember[n]}  (1-5) ...returns string
- Added:  ${Me.AmIGroupLeader}  ...return TRUE or FALSE
- Added:  ${Me.GroupList} ..simply returns a string of your group members (excluding you)
- Fixed ${xxx.Lore} for items
- Fixed {AltAbility[ability].xxx} ...all of these are now working
- Fixed All the AltAbility structs
(Note:  ${Me.AltAbilityReady.xxX}, ${Me.AltAbilityTimer.xxx} and ${Me.AltAbility[]} are 
        still BROKEN)
-----------
** SOE Coding Change (technical folks only)**  
EQ no longer stores information for ALL AA abilities in your memory space as it once did.
It allocates the space for all of the abilities;however, if your character is incapable of
using the ability, the pointer location for that ability is now 00000000.
-----------

14 August 2004 by Amadeus
- Fixed offsets to work with 8/13 "emergency" patch
- Updated TOTAL_SPELL_COUNT and MAX_ZONES
- Added dman's ${Target.HeadingToLoc[Y,X]} and ${Me.HeadingToLoc[Y,X].Degrees} routines

12 August 2004 by Amadeus
- Various fixes (including ${Me.Casting}, etc.)

11 Auguest 2004 by Amadeus
- Fixed to work with the 8/11 patch

27 July 2004 by DKAA
- Fixed ${Plugin}

23 July 2004 by Amadeus
- Lots of struct updates from the boards
- Added the following variables:  ${Me.EnduranceBonus}, ${Me.CombatEffectsBonus},
  ${Me.ShieldingBonus}, ${Me.SpellShieldBonus}, ${Me.AvoidanceBonus}, ${Me.AccuracyBonus},
  ${Me.StunResistBonus}, ${Me.StrikeThroughBonus}, ${Me.AttackBonus}, 
  ${Me.HPRegenBonus}, ${Me.ManaRegenBonus}, ${Me.DamageShieldBonus},
  ${Me.AttackSpeed}, ${Me.DoTShieldBonus}
- Added showbonuses.mac to the release/macros directory.  It will display your current
  stat bonuses as added by your gear.
- Added ${Me.LanguageSkill[languagename]} (ie, ${Me.LanguageSkill[Dark Speech]}.  You can
  also use a number (as given with /lang help) in place of the languagename parameter.

21 July 2004 by DKAA
- Fixed the macro not found error message.

18 July 2004 by Lax
- EQPlayNice 1.11+ compatibility

17 July 2004 by Amadeus
- Updated source to be compatable with the July 16 patch
- ${Me.AltAbilityTimer...} and ${Me.AltAbilityReady...} datatypes are broken atm and 
  have been disabled.

12 July 2004 by DKAA
- slot hand is now hands to be consistent
- updated some of the distributed macros

9 July 2004 by Lax:
- Newest version of the readme.chm from Wassup
- Added/changed MQ2Data type members
  int item.Tribute: Tribute value

3 July 2004 by DKAA
- added /who noguild

3 July 2004 by Amadeus:
- Added new command:  /substitute 
  ** Syntax: 
  **        - /substitute list
  **        - /substitute <orig> delete
  **        - /substitute <orig> <substitution>   (see examples below)
  ** This new command allows you to create custom midline substitutions that will work
  ** anywhere in a command.  It works VERY similarly to aliases in some respects, esp.
  ** in how it is saved in the .ini file and how the commandline syntax is structured. 
  ** Substitutes are called from any alias or commandline by using the percent sign (%)
  ** followed by your orig. text.
  **
  ** Examples:  "/substitute mom Mother"
  **            "/substitute omg Oh my god!"
  **            "/substitute k %omg, kill %t before I tell your %mom"
  **
  ** The final example if you typed "/say %k" would produce:  "/say Oh my god!, kill
  ** TARGET before I tell your Mother"
  **
  ** Please note the following rules/reminders:
  ** 
  ** 1.  You don't use the percent signs when creating the substitutions or editing your
  **     config file.
  ** 2.  You can use MQ's subsitutions without spaces around them (unlike EQs!) (ie: 
  **     "/echo %omg%mom" would return "/echo Oh my god!Mother"
  ** 3.  Substitutions do not currently work in macros.
  ** 4.  "/sub" is currently a valid shorthand for "/subsitute"
  ** 5.  You can use EQ's wildcards (ie: %t) within your substitutions; however, you 
  **     have to leave spaces around them (yes, they suck)
  ** 6.  You cannot CURRENTLY replace EQ wildcards with MQ substitutions (ie, you can't
  **     make a replacement for %m (This may be supported in the future.)
  **
- Fixed CONTENTS struct (thanks ieatacid)
- Fixed routines.mac, arrows.mac, and arraytest.mac (Dont_know_at_all)

2 July 2004 by Amadeus:
- Fixed "/who guild <guildname>" on some servers (It seems that on some servers, SOE
  removed guilds but left the entry giving bogus guild entries in the list where the
  'name' was blank, thus ending the search loop prematurely.)
- Added "/who knight"  (returns Paladins and Shadowknights in the zone)
- Added "/who tank"    (returns paladins, shadowknights, and warriors in the zone)
- Added "/who healer"  (returns druids and clerics in the zone)
- Added "/who dps"     (returns wizards, rangers, and rogues in the zone)
- Added "/who slower"  (returns shamans, enchanters, and beastlords in the zone)

30 June 2004 by Amadeus:
- Refined "/who npc named" to work a bit better
- Added "/who npc merchant"
- Added "/who npc tribute" (returns tribute masters)
- Added "/who npc gm" (returns GUILDmasters)
- Removed the Old SPAWNINFO struct

28 June 2004 by Lax:
- Added MQ2Data Top Level Object:
  bool LineOfSight[y,x,z:y,x,z]: Determines Line of Sight in 1, 2 or 3 dimensions.  Any not given will default to your character's current x y or z.
- Added MQ2Data type members:
  bool spawn.LineOfSight: Determines if your character has Line of Sight to this spawn
  bool switch.LineOfSight: Determines if your character has Line of Sight to this switch
  bool ground.LineOfSight: Determines if your character has Line of Sight to this ground item
- API now has static inline BOOL LineOfSight(PSPAWNINFO Origin, PSPAWNINFO CanISeeThis)

27 June 2004 by Amadeus:
- Added 'named' flag to the superwho filters.  It simply checks to 
  see if the spawn's name begins with a capital letter or with a
  pound (#) sign.  (examples:  '/who npc named', '/who npc named 65')
  ** This works best in places like the Plane of Hate.

23 June 2004 by Amadeus:
- ieatacid's CHARINFO update (primarily just offset locations updated)
- ieatacid's update to EQRAIDWINDOW struct
- Removed OLDCHARINFO struct

23 June 2004 by Lax:
- Fixed Bank stuff in CHARINFO
- "listselect" notify now works in combo boxes
- Fixed minor problem with operator precedence in Calculate (1-1-1 previously evaluated to
  positive 1, now it correctly evaluates to negative 1)
- Changed/Added MQ2Data members:
  int window.Items: Number of items in a list or combo box
  int window.List[text]: Find an item in a list or combo box by partial match (use window.List[=text] for exact)  Example: ${Window[TradeskillWnd].Child[RecipeList].List[=Inky Shadow Silk]}

21 june 2004 by DKAA:
- Fixed a crash in echo when the lines are longer than 2043

21 june 2004 by DKAA:
- Fixed the EQMERCHWND alignment and renumbered the CSIDLWND struct.

19 June 2004 by Lax:
- Fixed FastCalculate and EvaluateRPN functions.  Calculate works fine now, stfu rtfm etc ;)
- DKAA fixed some struct stuff
- Amadeus fixed some struct stuff

14 June 2004 by Lax:
- Replaced Calculate function with a much faster version. Also added an operator or two.
  I'll make sure they get added to the manual. How much faster? The existing calculate
  ran on my system 4,200 times in a short amount of time and took one full second of CPU
  time to do so. The same calculations ran with the new calculate 77,000 times and took 
  only 620ms. Extrapolating the data it would have taken about 124,000 times calling 
  calculate to match the old 4,200... or about 29.5 times faster (that's a lot).
- Added sub lookup map from Gus to speed up macros a little bit
- Undid MQ2EQBugFix, which was currently creating a bug (note to self: in future bug fixes,
  make sure it's only going to try to fix it for the correct version)
- Fixed an offset
- Standard search spawn now allows multi-word names.
- /mqlog no longer adds an extra line

3 June 2004 by Lax:
- Fixed string.Arg, string.Token, NearestSpawn, spawn.NearestSpawn, LastSpawn

2 June 2004 by Lax:
- Fixed some stuff, yadda yadda.  I forget now.
- Bodytype 10 has been identified as Dain, thank you for the reports

29 May 2004 by EqMule:
- Fixed EQ_INTERACTGROUNDITEM so click left item works again...
- Updated zipit.lst (personal reminder: dir * /s /N /A-D /B > zipit.lst)

28 May 2004 by DKAA:
- Fixed the message ID for mq2bzsrch.

27 May 2004 by Lax (more):
- Fixed stack overflow bug in one of the functions that handles window names.  I fixed it in one
  before putting up the update but didn't in an exact copy of it above it.  Lax truly lacks. ;)
- Added pet weapon procced pet body type to the list of known body types.
- Fixed captioncolors not working correctly
- /who <level> will work properly, as you would have expected previously.  e.g. /who 65.
  Coincidentally this now works with the other spawn searches, /who /target /highlight /mapshow
  /maphide, ${Spawn[search]} etc.

27 May 2004 by Lax:
- Added "chest" to the standard spawn searches used by /who, /target, /highlight, /mapshow, 
  /maphide, etc
- Fixed some problems with the window suff introduced in the May 16 zip
- Added/changed MQ2Data members:
  string spawn.Type: PC NPC Untargetable Mount Pet Corpse Chest Trigger Trap Timer Item 
- New MQ2Data Top-Level Object:
  int SpawnCount: Total number of spawns in current zone
  int SpawnCount[search]: Total number of spawns in current zone matching the search

24 May 2004 by DKAA:
-Fixed a couple problems with the makefiles (mq2chat wasn't building)
-A special update for mq2safe users

16 May 2004 by Lax:
- UI subsystem of MQ2 is now smarter.  All window and control names are now case insensitive,
  and controls can be used by ScreenID *or* Piece name.  /windows <windowname> now shows, for 
  each child of the given window, ScreenID, Piece name, and the TYPE of control (e.g. label,
  button, invslot, spellgem, etc).
- window.List now only works on list boxes (will not crash on other types, just give NULL)
- Added/changed MQ2Data members:
  string window.Name: Name of window piece (e.g. "ChatWindow" for top level windows, or the Piece name (NOTE: CUSTOM UI DEPENDANT) for child windows)
  string window.ScreenID: ScreenID of window piece (ScreenID is NOT custom ui dependant, this *must be* the same on ALL UIs)
  string window.Type: Type of window piece (Screen for top level windows, or Listbox, Button, Gauge, Label, Editbox, Slider, etc)
- Fixed /target next, as well as targeting the origin of the search (e.g. you, or the spawn
  already targeted)
- Fixed turbo problem with using /macro from within a macro

16 May 2004 by DKAA:
- Fixed a where using loc and radius in spawn searches would return spawns further than the radius

15 May 2004 by Lax:
- Fixed bug in /who that made it show no spawns for some people, even though there were spawns...
- Standard search spawns will accept class names or short names without using the "class" keyword.
  Shadowknight is used without a space, and short names are all 3 letters ("shd", not "sk").  
  Note that cleric's short name is "clr" not "cle".
- Bug with MQ2Chat plugin that caused events to be processed twice has been fixed
- MQ2IRC will now process all lines as custom events.  Note that it does not process them as 
  #chat events.
- Turned off the PCClass captioncolor option, PC caption colors will default to EQ's settings.
  It was left on by mistake after testing a bug fix.  You can turn them back on if you wish by
  using the /captioncolor command like so: /captioncolor pcclass on

14 May 2004 by Lax:
- MQ2ChatWnd (the MQ2 Chat Window support) got some upgrades.  First of all the window was not
  limiting the size of its scrollback, so after so much went on in the MQ2 window, your framerate
  would drop like a rock.  To achieve proper scrollback limiting without lagging you too much,
  I put in a system to make it buffer the chat that goes to it, and only display so many lines
  per frame.  The MQ2ChatWnd font size option now works somewhat...  The font sizes are not the
  same as EQ's chat window sizes yet, so be aware of that.  I'll work on it ;)  You will probably
  want somewhere from -3 to 2.  /mqfont <#>
- MQ2Map filters added: untargetable, trap, timer
- /who has been changed a little bit.  When a TRIGGER, TRAP, TIMER, or UNTARGETABLE is listed,
  that will be noted at the end of the line in red (very helpful).  The routine has also been
  updated for efficiency, so there is less lag with large /who result sets.
- Standard spawn searches (This includes /who, /target, ${Spawn[search]}, etc) have been 
  slightly modified.  "invis" is NO LONGER A VALID KEYWORD.  If you have this in macros, etc 
  you will need to change it.  The updated spawn types ARE valid keywords (trigger, trap, 
  timer, untargetable). If your search is for type "npc" you WILL get untargetable types in
  your search results (particularly helpful for /who).
- Added/changed MQ2Data members:
  string spawn.Type: PC NPC Untargetable Mount Pet Corpse Trigger Trap Timer Item 
  string string.Token[n,separator]: Retrieve a token from the string using a custom separator.  Unlike Arg, this will not skip empty values
  spell item.Spell: Spell effect
  float item.CastTime: Spell effect's cast time
  string item.EffectType: Spell effect type
  ticks character.AltAbilityTimer[n]: Alt ability reuse time left, by number
  ticks character.AltAbilityTimer[name]: Alt ability reuse time left, by name
- spawn.Hunger and spawn.Thirst have returned to active duty
- You can now list child windows from in-game with the /windows command, like so:
  /windows <name>
  e.g.: /windows InventoryWindow
- /itemnotify in <pack> <#> <notification>  now works with sharedbank slots.

13 May 2004 by Lax:
- Fixed "by class" caption colors
- Fixed some bodytypes being identified as triggers (note that untargetable NPCs *are* 
  triggers)
- Fixed target caption leakage (would stay drawn after switching targets)
- /who will show "invis" spawns if any parameters are given.  Spawn search functions,
  including /who and /target, will probably get updated soon.	
- Fixed problem with leading spaces in sub parameter declarations
- MQ2HUD now allows for different HUDs.  Each different HUD is stored in MQ2HUD.ini, but
  in different sections.  The default HUD is "Elements" because that's what it originally
  used.  To load a different HUD, the command is "/loadhud <name>" like "/loadhud bard".
  In this case, the [bard] section (not case sensitive, so it could also be [BARD]) of
  MQ2HUD.ini will be used.  To load the default HUD specifically, the command is 
  "/defaulthud".  MQ2HUD also now adds the following MQ2Data Top-Level Object:
  string HUD: Name of currently loaded HUD.
- MQ2FPS now fixes the bug where CTRL ALT and SHIFT keys stick when you switch windows.
  This is a bug in EQ that happens because the release of the key is not captured by EQ after
  it has been swapped to the background.  MQ2FPS now releases the keys as soon as EQ goes
  to the background, so this will no longer be an issue.
- New command to complement the /ctrlkey /altkey /shiftkey commands:
  Usage: /nomodkey <command>
  This command will release all ctrl/alt/shift keys for the duration of executing the 
  given command.
- Added/changed MQ2Data members:
  bool spawn.Anonymous: Anonymous?
  bool spawn.Roleplaying: Roleplaying?
  string string.Token[n,separators]: Retrieve a token from the string

12 May 2004 by Lax:
- Fixed the mysteriously disappearing #event handling in macros ;)

11 May 2004 by Lax:
- Added nifty changes.txt reader to character select screen.  Now you have no excuse!
- Fixed problem with events mysteriously having parameters disappear
- Updated Blech to fix a bug with some #events disappearing (and not firing)
- Your target's caption will now always be drawn
- Added LDoN Recruiters and Merchants to the list of full class names.
- Added /captioncolor command, which allows a lot of custom spawn caption coloring.  For example,
  the caption of marked NPCs or assist NPCs can be a specific color.. the caption of bankers and
  merchants can be a set color.  NPCs can be done by con color.  All spawns can be done by
  CLASS color (using the raid settings).  Note that you can only set the raid class colors right
  now through the raid options window.  You can open this window by typing
  /windowstate raidoptionswindow show
  Usage: /captioncolor <list|<name off|on|#>>
  Examples:
  /captioncolor list
  /captioncolor pcclass on
  /captioncolor pctrader on
  /captioncolor pctrader 255 128 0
- Changed /windowstate command to use the window mapping used by ${Window[name]}, /windows, etc.
- Fixed issues with "charm" and the invslot type
- raidmember MQ2Data type now inherits "spawn" (when they are in zone)
- Added/changed MQ2Data members:
  class raidmember.Class: Raid member's class (works without being in zone)
  int raidmember.Level: Raid member's level (works without being in zone)
  int item.WornSlots: The number of invslots this item can be worn in (fingers/ears count as 2 slots)
  invslot item.WornSlot[n]: The nth invslot this item can be worn in (fingers/ears count as 2 slots)
  bool item.WornSlot[name]: Can item be worn in invslot with this name? (worn slots only..)

10 May 2004 by Lax (more):
- Fixed once and for all the crash bugs relating to spawn captions (WHICH ARE *NOT* THE HUD)

10 May 2004 by Lax:
- Fixed problem relating to false negatives determining if a spawn is a TRIGGER (e.g. flavor
  text, trap, etc).  This solves crash issues in the latest zip with the custom caption
  system.  This also solves non-crash issues identifying "invisible spawns" in spawn searches,
  as well as spawns that were previously identified as NPCs in MQ2Map.

09 May 2004 by Lax (more):
- Fixed VS6 compile errors in Blech
- Fixed reported crash bug
- Fixed possible crash with HUDs
- Added MQ2HUD "type" 8, for character select screen.  This should fix some potential
  crashes when using custom HUDs and entering char select.

09 May 2004 by Lax:
- Removed remnants of MQ2Parms system.  Rest in peace.  Phase 4.
- Cleaned up a lot of old code that was being kept in comments
- Removed mount captions, they just crash the client
- Added optional parameter to /delay.
  Usage: /delay <time> [condition to end early]
  This lets you use a delay that has a possibility to end early.  For example...
  /keypress forward hold
  /delay 1s ${Spawn[1234].Distance}<${Spawn[1234].MaxMeleeTo}
  /keypress forward
- New command /noparse
  Usage: /noparse <command>
  Prevents a command from being parsed for MQ2Data.  For example..
  /noparse /ini blah blah blah ${stuff}
  Will actually write the ${stuff} literally instead of changing it to the current value
  of stuff.
- Added/changed MQ2Data members:
  int macroquest.MouseX: Mouse's x location
  int macroquest.MouseY: Mouse's y location
  string ticks.Time: Time in the form mm:ss
  string ticks.TimeHMS: Time in the form hh:mm:ss (if there are no hours, the form will be mm:ss)
  int character.CountBuffs: Total number of buffs (not including short duration buffs)

07 May 2004 by Lax:
- Added "Lax/Blech" support to custom events.  The Blech system allows much easier parsing of
  incoming chat.  Custom events will now support more parameters that are automatically
  parsed based on the match text.
- Fixed up EQ's handling of spawn captions (name above their head). Only the nearest 35 spawn
  captions will be updated by default (and even then, only those close enough that you'd see 
  their name).  EQ itself constantly updates the name of every spawn in the zone, even though 
  only a small portion of those are displayed.
- Added an option to /caption command
  Usage: /caption <list|type <value>|update #>
  "/caption update #" will set the number of nearest spawns for MQ2 to update the name of
  each pass.  By default, this is 35.  If you have performance issues after this update,
  please post about it on the forums.  Find a happy update number and let us know.
- Added marked NPC and assist target leadership stuff to default captions, also put guilds on
  the line below the name.  The defaults should mostly look like EQ's now.
- Fixed macro.Params
- Fixed invslot names
- Added/Changed MQ2Data Members:
	spawn character.TargetOfTarget: Target of target   (moved to character type)
	bool spawn.Assist: Current Raid or Group assist target?
	int spawn.Mark: Current Raid or Group marked npc mark number (raid first)
	spawn character.RaidAssistTarget[n]: Current raid assist target (1-3)
	spawn character.GroupAssistTarget: Current group assist target
	spawn character.RaidMarkNPC[n]: Current raid marked NPC (1-3)
	spawn character.GroupMarkNPC[n]: Current group marked NPC (1-3)

05 May 2004 by Lax (even more):
- Plenty of positive feedback on the custom spawn captioning.  Plenty also asking why shownames
  was not working properly.  There are now 4 levels of captions for Players, according to the
  shownames level, to solve this issue.  Therefore the ini options are now Player1, Player2, 
  Player3, Player4 rather than just Player.  Also, the guild status indicator now 
  capitalizes Leader and Officer, and added a "LDR" tag to your group leader.
- Added /caption command to set the custom captions from in-game.
  Usage: /caption <list|type <value>>
  To clear the specific setting, just do /caption <type> like so:
  /caption player1
- DKAA fixed the bzsrch problems
- Added MQ2Data member:
  bool spawn.GroupLeader: Is this your group's leader?
- Fixed CHARINFO struct.  Some Stuff appeared slightly wrong, like leadership exp and bank
  stuff.

05 May 2004 by Lax (more):
- Fixed crash on zoning relating to the new HUD functionality. Dont ask.

05 Max 2004 by Lax:
- Updated for patch and added README.CHM.  Keep an eye out, we should have the manual
  available in more formats (including printable) soon

04 May 2004 by Lax:
- New command
  Usage: /hud <normal|underui|always>
  * "Normal" will make the HUD display as it would normally on top of UI, not at char select
     or in "f10 mode"
  * "UnderUI" will make the HUD display as it would normally except UNDER the UI, and not at
     char select or in "f10 mode"
  * "Always" will make the HUD display under the UI, at char select, and in "f10 mode"
- New Plugin MQ2HUD.  Edit MQ2HUD.INI to add custom elements to your HUD.  You pick the spot
  on the screen, the color, and what gets displayed.  Every element gets parsed for MQ2Data
  each time it is displayed.
  Example MQ2HUD.INI:
    [Elements]
		TargetInfo=3,5,35,255,255,255,${Target}
		GMIndicator=3,5,45,0,0,255,${Spawn[gm]}
		CursorItemName=7,-15,-15,255,255,255,${If[${Cursor.ID},${Cursor},]}
		ClickMeForFun=6,-25,-25,255,255,255,${If[!${Cursor.ID},click me,]}
  The order is TYPE,X,Y,RED,GREEN,BLUE,TEXT.
  Type is currently any combination of the following:
    1 - Display in non-full screen mode
    2 - Display in full screen mode ("f10 mode")
    4 - X,Y is based on cursor location
  e.g. 1+2+4=7.  7 means all 3 of the above. 6 means 2 and 4. 3 means 1 and 2. Just add them
    together.  There is no way to end up with a number that could mean two different 
     combinations.
  Red, Green and Blue are each from 0 to 255. 255,255,255 is white, 0,0,0 is black.
  ** There is currently not a command to add or remove these from inside the game.  One will
     probably be added soon.  The plugin will automatically re-load the list from the .ini
     when you modify and save the .ini.
- Seeing as how the mouse functions perfectly fine in full screen mode, I've forced the cursor
  to display the same as it would in UI-visible mode.  The only difference is the item is not
  displayed on your cursor.  With MQ2HUD and the "CursorItemName" example, you could have it
  show the name of the item attached to your cursor in full screen mode (use type 6 if you
  want it to follow your cursor in full screen mode only).
- Added custom spawn captioning.  Set them in MacroQuest.ini [Captions].  Empty the setting 
  to make it use EQ's default.  By default our player caption is slightly different -  
  it shows their guild status if they are officer or leader of a guild.  Pet captions are a
  little different also - it will display the name of its master if it is a player's pet.
  Use "\n" to mean a new line when setting captions.
- Added MQ2Data Top-Level Object:
  spawn NamingSpawn: Spawn currently being captioned.  NULL when not captioning.
- Added/changed MQ2Data members:
  bool spawn.LFG: LFG?
  bool spawn.Linkdead: Linkdead?
  bool spawn.Trader: Trader?
  bool spawn.AFK: AFK?
  string spawn.AATitle: Actual AA title (e.g. Sage, Impresario, etc)
- MQ2Map adds Top-Level Object: spawn MapSpawn: If your cursor is on a spawn on the map, this is it
- Fixed ticks.Time

02 May 2004 by Lax:
- Added a popup box to the crash detected hook, explaining that the user should visit the
  MQ2::Bug Reports forum.
- Removed EasyDetour and EasyClassDetour.  There is a single replacement for the both of them
  called EzDetour.  EzDetourwName(offset,detour,trampoline).  Examples (which are all over in MQ2Main
  and plugins):
  EzDetourwName(ProcessGameEvents,Detour_ProcessGameEvents,Trampoline_ProcessGameEvents);
  EzDetourwName(CEverQuest__EnterZone,CEverQuestHook::EnterZone_Detour,CEverQuestHook::EnterZone_Trampoline);
- Renamed the REVERSE_DETOUR functions to reduce confusion.  These really had nothing to do
  with detours.  What it really does is lets you call a function at a given offset.  
  So, they are now:
  FUNCTION_AT_ADDRESS(function,offset)
  FUNCTION_AT_VARIABLE_ADDRESS(function,variable)
  FUNCTION_AT_VIRTUAL_ADDRESS(function,offset)
- Fixed small issue in MQ2Data parser
- Fixed /memspell not finding some spells correctly (Heroic Bond for example)
- MQ2 will now fix the string table by removing extraneous spaces from the end of strings,
  since EQ isnt smart enough to do it itself.  This fixes issues such as finding the AA
  "Bestial Alignment", which has two spaces after it in eqstr_us.txt.  
  ${AltAbility[Bestial Alignment]} previously did not work because of this issue.  It works
  now because of this fix.
- Added MQ2Data types
  raid, raidmember   (see reference for members)
- Added MQ2Data Top-Level Objects
  raid Raid: Raid you're in...
- Added/changed MQ2Data members
  string ticks.Time: Time in the form hh:mm:ss (if there are no hours, the form will be mm:ss)
  int skill.MinLevel: Minimum level for your class
  int skill.StartingSkill: Base skill level for your class
  int skill.SkillCapPre50: Skill cap pre-50 for your class
  int skill.SkillCapPost50: Skill cap post-50 for your class
  int character.FreeInventory: Count of free inventory spaces
  int character.FreeInventory[n]: Count of free inventory spaces of at least this size (giant=4)
  int character.LargestFreeInventory: Size of largest free inventory space
- LaxColor is now defaulted to off since most people now realize that it exists.  If you wish
  to turn it back on, LaxColor=1 in MacroQuest.ini.
- Fixed spawn.NearestSpawn issues
- Fixed ${Ini} absolute path issues
- Fixed some other issues that were brought up on the boards

30 Apr 2004 by Lax:
- Added MQ2Data members
  int macro.Params: Number of parameters to current sub

29 Apr 2004 by Lax (even more):
- Added option so that MQ2Data errors and normal errors (but not syntax errors that show
  /usage etc) will dump the macro stack.  This is ON by default.  To turn it off, set
  AllErrorsDumpStack=0 in MAcroQuest.ini section [MacroQuest]
- Added option so that the above errors will end the macro, aka makes them "fatal".  This is
  OFF by default. To set this, set AllErrorsFatal=1 in MacroQuest.ini section [MacroQuest]
- If for some reason you need to clear all GLOBAL SCOPE variables,
  /deletevar * global
  will do the trick.  For example, after you try to run an old macro and then realize the
  global scope changed and /zapvars no longer exists, but you can't make the variables outer
  scope because theyre already in global scope and you dont want to delete them all one by
  one....
- Perfected Multi-dimensional arrays

29 Apr 2004 by Lax (more):
- Fixed Multi-dimensional arrays

29 Apr 2004 by Lax:
- Fixed SPAWNINFO structure.
- NOTICE: Some MQ2Data members are currently MIA.  They may come back soon.  These include:
  character.Hunger
  character.Thirst
  character.GukEarned
  character.MMEarned
  character.RujEarned
  character.TakEarned
  character.MirEarned
  character.LDoNPoints

27 Apr 2004 by Lax (more):
- MQ2DataVars is now default.  Share and enjoy, share and enjoy!
- Fixed timer type member availability
- Added MQ2Data type: altability
- Added MQ2Data Top-Level Objects:
  altability AltAbility[n]: Alt ability by number
  altability AltAbility[name]: Alt ability by name
- Changed/Added MQ2Data Members:
  float spawn.MaxRange: Max distance from this spawn for it to hit you
  float spawn.MaxRangeTo: Max distance from this spawn for you to hit it
  int character.AltAbility[n]: Alt ability rank by number
  int character.AltAbility[name]: Alt ability rank by name
  bool character.AltAbilityReady[n]: Alt ability readiness by number
  bool character.AltAbilityReady[name]: Alt ability readiness by name
  int character.AltAbilityTimer[n]: Alt ability reuse time (seconds) left by number
  int character.AltAbilityTimer[name]: Alt ability reuse time (seconds) left by name
  spell character.CombatAbility[n]: Combat ability by number in your list (not same as others lists!)
  int character.CombatAbility[name]: Combat ability number in your list by name (not same as others lists!)
- Added an option to MQ2Map:  The "TargetMelee" mapfilter when set to 1 will draw a circle 
  representing how close to this spawn you must be to hit it.  Set to anything but 0 or 1 
  will draw a circle representing how close to this spawn you must be for it to hit you.
- Added some flavor for error messages.  Set LaxColor=0 in MacroQuest.ini [MacroQuest] to
  disable.  It's on by default or it wouldn't be as fun.

27 Apr 2004 by Lax:
- spawn.MaxRange now uses the proper melee range algorithm
- Fixed a crash bug in the Ini TLO
- Added proper relative/absolute path detection to /ini
- Fixed window.Checked
- Added MQ2Data members:
  int window.Style: Window style code
  bool window.Enabled: Enabled?
  bool window.Highlighted: Highlighted/mouse over?

26 Apr 2004 by Lax:
- Various error messages have been updated to be more specific.
- Fixed "outer" scope not being cleared by /endmacro.  Removed /zapvars in MQ2DataVars 
  since all it did was clear the outer scope.  It's no longer needed because the old global
  scope is separated into two scopes in MQ2DataVars.
- Fixed FindInvSlotForContents function (used in item.InvSlot.  item.InvSlot will no longer
  give NULL for valid items in your inventory/bank)
- Sub parameters (including those for events) are now allowed to have a type other than 
  string, when MQ2DataVars is enabled, like so:
  Sub MySub(int A, string B, float C)
- Fixed out-of-bounds by 1 crash in MQ2DataVar arrays
- MQ2FPS now allows you to disable the framerate display with /fps off (/fps on to enable again)
- MQ2EQIM feature set adjusted.  Now keeps your list of buddies (per character) and the last
  time they were seen online or on eqim (by any character).  Your friends list is automatically
  added as buddies.  A member was also added to the "buddy" type EQIM adds, time buddy.LastSeen.
- ${Ini} will allow either relative or absolute paths.  Also slightly modified what it gives
  you when you try to get a list of keys and supply a default (previously it would ignore
  the default and give NULL if there was no list).
- Improved parsing of " and ] within MQ2Data indexing.
  ${String["hi"]}: hi
  ${String["hi","hi"]}: hi,hi
  ${String[""hi""]}: "hi"
  ${String[hi"hi"hi]}: hi"hi"hi
  ${String[[MQ2] - Hi]}: [MQ2] - Hi
  ${String["""]}: "
- MQ2BzSrch plugin is now updated for MQ2Data.
  MQ2Data reference for MQ2BzSrch (because it's a plugin, not in main reference)
  -------
  Types added- bazaar, bazaaritem
  TLO's added- bazaar Bazaar: Bazaar search info
  ---
  bazaar 
  Members:
  ...bool Done: Search complete?
  ...int Count: Result count
  ...bazaaritem Item[n]: Result info by index (1-based)
  To String: Same as Done
  ---
  bazaaritem 
  Members:
  ...string Name: Item name
  ...spawn Trader: The guy selling it
  ...int Price: Price the guy is selling it for
  ...int Quantity: Number of this item this guy has
  ...int ItemID: The item's ID number
  ...int Value: Value of the item?
  To String: Same as Name
  -------
  
25 Apr 2004 by Lax (revision C changes):
- Fixed merchant.Item[=name] and corpse.Item[=name]
- Fixed character.PctEndurance
- Fixed problems with tabs in macros, and also with leading and trailing whitespace
- MQ2DataVars is READY.  Keep an eye out for important announcements about this!
- Added MQ2Data types for MQ2DataVars: array, timer

25 Apr 2004 by Lax (even more):
- Hopefully fixed crash caused by fixing the "LastCommand" stuff...
- Added MQ2Data Members:
  int character.MaxEndurance: Max endurance
  int character.PctEndurance: Percent endurance

25 Apr 2004 by Lax (more):
- Fixed spawn.NearestSpawn
- Changed buff.ID so that it gives the song # or buff # instead of the spell's ID

25 Apr 2004 by Lax:
- Fixed once and for all the /itemnotify and /notify crashes
- Fixed the rendering rate defaults (will no longer flicker like a strobe light ;)

23 Apr 2004 by Lax (more):
- Added MQ2Data Type:
  skill (see reference for members)
- Added MQ2Data Top-Level Objects:
  string GroupLeaderName: group leader's name (works even if they are out of zone)
  spawn GroupLeader: group leader (only works if they are in zone)
  skill Skill[n]: Skill by number
  skill Skill[name]: Skill by name
- Added/Changed MQ2Data Members:
  spawn spawn.NearestSpawn[search]: Find the nearest spawn matching this search, to this spawn (most efficient on yourself)
  spawn spawn.NearestSpawn[n,search]: Find the nth nearest spawn matching this search, to this spawn (most efficient on yourself)
  string window.List[n]: Get the first-column text for the nth item in a list box.  Example: ${Window[TradeskillWnd].Child[RecipeList].List[1]}
  int window.List[text]: Find an item in a list box by partial match (use window.List[=text] for exact)  Example: ${Window[TradeskillWnd].Child[RecipeList].List[=Inky Shadow Silk]}
  int string.Count[char]: Count the number of occurrences of a particular character in the string
  bool window.Checked: Checked? (useful for buttons)
  string string.Left[-length]: The left ("all but" length) of the string.. Left[-1] of "Left" will be "Lef"
  string string.Right[-length]: The right ("all but" length) of the string.. Right[-1] of "Left" will be "eft"
  bool character.RangedReady: Ranged attack ready?
  bool character.AltTimerReady: Alternate timer ready? (Bash/Slam/Frenzy/Backstab.  Note that AbilityReady works fine with most of these)
  int macroquest.Running: Running time of current MQ2 session, in milliseconds
- Fixed AbilityReady for the alternate timer abilities (Bash, Slam, Frenzy, Backstab, possibly others)
- Fixed /ctrlkey /shiftkey and /altkey.  They would sometimes "stick" the key down.
- Added a notification to /notify "listselect", used to select the nth item in a list box.
  Example: /notify TradeskillWnd RecipeList listselect 1
  Use 0 to clear your selection.
- ${Group[0]} is now the same as ${Me}.  Group members are still 1-5.
- Added command to MQ2FPS:
  /render <fg|bg> <#|~#>
  Sets the foreground or background rendering rate.  This is how many out of n frames MQ2FPS
  will allow to be drawn.  You keep moving full speed, the client responds to mouse or keys,
  the UI is still drawn... but, the world itself will not be drawn as often.
  Use with ~ to draw n-1 out of n frames, or without to draw 1 out of n frames.
  e.g. /render bg ~3 will draw 2 out of 3 frames.  /render bg 3 will draw 1 out of 3 frames.

23 Apr 2004 by Lax:
- Changed top #turbo to 40, still defaults to 20
- Fixed Ini Top-Level Object again
- Fixed "enviro" slots so that they work for enviro1-10 not just 1-8

22 Apr 2004 by Lax:
- Readme.html has been removed from the zip by request of its author.  It is being worked on
  and will return.
- /selectitem GONE
- /finditem GONE
- /click functionality has been SEVERELY reduced.  It will now function given an x,y,
  and on an item or spawn (target).  Upgrade to /notify for UI interaction.
  /notify <window> <button screen id> <notification>
  example:
  /notify LootWnd DoneButton leftmouseup
  Window names and control ScreenID's are found in the XML files, and are NOT screwed up
  by custom interfaces (unless your UI does not have the button)
- Fixed item slot name discrepancies.  What was previously "primary" and "secondary" is
  "mainhand" and "offhand".  It was one thing in some places, but not in others.  Should
  be all the same now.
- Underscores(_) are again valid in variable names
- Added "STUN" to spawn.State
- Fixed Ini Top-Level Object
- ** Added/changed MQ2Data type members
  string macroquest.Error: Last normal error message (replaces $getlasterror but will NOT have the old values!)
  string macroquest.SyntaxError: Last syntax error message (usage: /blahblah)
  string macroquest.MQ2DataError: Last MQ2Data parsing error message
  spawn spawn.TargetOfTarget: Target of target (May only work in "Me": ${Me.TargetOfTarget.PctHps}, etc)
  int item.BuyPrice: Price to buy this item at this merchant
  int item.SellPrice: Price to sell this item at this merchant
  item merchant.Item[name]: Finds an item by partial name at this merchant (use merchant.Item[=name] for exact)
  item corpse.Item[name]: Finds an item by partial name in this corpse (use corpse.Item[=name] for exact)
  float character.PctGroupLeaderExp: Group leadership exp as a %
  float character.PctRaidLeaderExp: Raid leadership exp as a %- bool character.Stunned: Stunned?
  bool spawn.Sitting: Sitting?
  bool spawn.Standing: Standing?
  bool spawn.Ducking: Ducking?
  bool spawn.Binding: Binding wounds?
  bool spawn.Feigning: Feigning?
  bool spawn.Invited: Invited to group?
  bool class.PetClass: Pet class? (shaman, necromancer, mage, beastlord)
  bool class.PureCaster: Pure caster? (can gate!)
  bool class.CanCast: Can usually cast? (not melee only)
  bool class.DruidType: Druid/Ranger?
  bool class.ShamanType: Shaman/Beastlord?
  bool class.NecromancerType: Necromancer/Shadowknight?
  bool class.ClericType: Cleric/Paladin?
  float math.Sqrt[formula]: The square root of formula
- New MQ2Data type "plugin"
- New TLOs
  plugin Plugin[name]: Finds plugin by name
  plugin Plugin[n]: Plugin by number, starting with 1 and stopping whenever the list runs out of plugins.
- Fixed LastSpawn[n] and LastSpawn[-n], also added them to reference.
- New command: /combine <pack> - hits combine on this container
- New command: /drop - drops item on cursor
- New command: /clearerrors - clears each of the "last errors"

21 Apr 2004 by Lax:
- Fixed if/newif

20 Apr 2004 by Lax:
- /if is now GONE.  /if is now the same as what /newif was.  /newif is aliased to /if.
- /sendkey and /press are now GONE.  Please update to /keypress, which as of 15 Apr 2004 allows
  pressing key combinations as well as the actual command.  Example:  /keypress alt+f
- /filter macros will now hide the output of /endmacro (if successful) and /zapvars (always)
- MQ2Labels updated for MQ2Data
- Fixed time.Year and time.Date
- Fixed charm invslot (number 0)
- Fixed ${If[]} handling of conditions
- Fixed FindItemCount to give the number of individual items rather than stacks
- MQ2EQIM plugin (which notifies you when someone on your EQIM buddy list changes) now keeps
  track of your buddy list and adds a MQ2Data type and Top-Level Objects:
  ** buddy type
  Members:
  ...string Name: Buddy's name (may be fennin.Name or just Name, depending on how you added them)
  ...string Status: "Removed from list",  	"Offline",	"EQIM",	"EQIM (AFK)",	"Unknown Status(4)",	"Playing",	"Playing (AFK)"
  ...int StatusID: Numeric representation of the above (0,1,2,3,4,5,6)
  To String: Same as Name
  ** Top-Level Objects
  buddy Buddy[name]: Info on buddy with this name
  buddy Buddy[n]: Buddy with this index number in the system
  int Buddies: Size of the buddy index (will not necessarily be equal to the number of buddies, but n in Buddy[n] will never exceed this number)
- Added Top-Level Object:
  int FindItemBankCount[name]: Count of items in bank by partial name match.  FindItemBankCount[=name] will find exact
- Changed "character" member "PlatShared" to "PlatinumShared"

19 Apr 2004 by Lax:
- ** MQ2DATA PHASE TWO ** If something is missing from MQ2Data it's because you never opened
  your damn mouth.  If you need something in MQ2Data whether it was previously available or
  not, speak up.  You're on your own if you want to figure out how to enable MQ2Parm at this
  point, good luck (I'm making it difficult on you so you will get your ass in gear)!  The
  readme is not yet updated.
- Fixed alerts being missing from SpawnMatchesSearch.  They worked in some spawn searches but
  not others.
- character.Inventory now uses the same numbering as InvSlot
- Added/changed MQ2Data members
  invslot invslot.Pack: Container that must be opened to access the slot with /itemnotify
  int invslot.Slot: Slot # inside that pack
  string invslot.Name: For inventory slots not inside packs, the slot name
  string spawn.ConColor: GREEN, LIGHT BLUE, BLUE, WHITE, YELLOW, RED
  int character.PetBuff[name]: Finds slot with this spell name
  spell character.PetBuff[n]: The spell in this slot (1-29)
  int character.GroupLeaderExp: Group leadership exp
  int character.GroupLeaderPoints: Group leadership points
  int character.RaidLeaderExp: Raid leadership exp
  int character.RaidLeaderPoints: Raid leadership points
  int character.Platinum: Platinum
  int character.Gold: Gold
  int character.Silver: Silver
  int character.Copper: Copper
  int character.PlatinumBank: Platinum in bank
  int character.GoldBank: Gold in bank
  int character.SilverBank: Silver in bank
  int character.CopperBank: Copper in bank
- New MQ2Data Top-Level Objects
  int FindItemCount[name]: Count of items on character by partial name match.  FindItemCount[=name] will find exact
- MQ2FPS plugin now adds these Top-Level Objects (these are NOT in the reference because they
  are from a plugin not built in):
  float FPS - Current frames per second
  int MaxFPS - Current max frames per second
  bool Foreground - Is this session in the foreground?

17 Apr 2004 by Lax:
- Fixed "window" data type's "To String"
- Fixed all VC6 project files so PDB/MAP files are produced for debugging
- New MQ2Data type
  invslot - Inventory slot (not necessarily "in your inventory", this may be in merchant window, bank, etc)
  see reference for current list of members.
- Added/changed MQ2Data members
  invslot item.InvSlot: Inventory slot for this item
- New MQ2Data Top-Level Objects
  invslot InvSlot[name]: Inventory slot by name
  invslot InvSlot[#]: Inventory slot by number
  item FindItem[name]: Find item on character by partial name match.  FindItem[=name] will find exact
  item FindItemBank[name]: Find item in bank by partial name match.  FindItemBank[=name] will find exact
  item SelectedItem: When using a merchant, etc. this is the selected item
  
15 Apr 2004 by Lax:
- Fixed /destroy crash
- Fixed "random" crash on zoning with MQ2Map loaded, due to a bug in the recently revised ConColor
- Fixed /cast issue casting "Bane" instead of "Bane of Nife" etc
- Fixed spell manager structure
- Fixed /doortarget id #, which would invariably crash
- Fixed and changed /keypress so that it also accepts key combinations, and will not crash no matter how hard you try.
  /keypress with key combinations will have the same effect as /keypress using the command name, it will not
  type the key into the chat window.  If you need to type into a window specifically (chat windows, social edit, etc)
  /keypress <key> chat
  example: /keypress e chat
  Note that you cannot use both hold and chat, and chat is only valid for the key not a command name.
  ** /sendkey and /press will give a warning the first time per session they are used that they are
     now completely obsolete and you should switch to /keypress.  they will be removed soon.
- Fixed and tested "heading" type's "To String"
- /newif will no longer quietly execute the "false" branch when it fails to parse the conditions.  The conditions
  after parsing MQ2Data/MQ2Parm will be displayed in an error message, and the macro will end.
- Other minor issues fixed

14 Apr 2004 by Lax:
- Fixed MQ2KeyBinds
- Fixed MQ2ChatWnd.ini

13 Apr 2004 by Lax:
- Fixed ! in Calculate (worked most of the time, but not in some special cases)
- Fixed heading's "To String" to give the correct heading.  heading.Name/heading.ShortName were fine
- Fixed time.Time12 to be 12 hour (oops)

9 Apr 2004 by Lax:
- Fixed != in Calculate (and therefore in /newif, math.Calc, etc), and implemented ! as
  the unary NOT operator.  This gives 0 if your calculation is non-zero, or 1 if your
  calculation is zero.
- MQ2Data changes:
  -- Swapped Y and X back to being backwards-backwards or backwards-forwards, or whatever they
     originally were
  -- Added "NWU" coordinates (North/West/Up), the three positively oriented directions in EQ.  
     Spawns also have a shortcut for SED (South/East/Down).  All type member names involving 
     XYZ have a NWU complement (none necessary for the "index" bracketed part, of Heading[y,x] 
     for example)
  -- Fixed character.AbilityReady
  -- Fixed item (TO STRING)
  Top Level Objects
  * spawn LastSpawn: The last spawn chronologically.
  * spawn LastSpawn[n]: The nth from last spawn.. LastSpawn[1] is the LastSpawn.. LastSpawn[2] is 2nd from last, LastSpawn[3] is 3rd from last, and so on
  * spawn LastSpawn[-n]: The nth from FIRST spawn.. LastSpawn[-1] is you, LastSpawn[-2] is the second spawn, LastSpawn[-3] is the third spawn, and so on
  Additions/Changes to existing types:
  * heading Heading[y,x]: Heading from player's current position to y,x
  * float math.Distance[y,x,z:y,x,z]: Performs distance calculations in 1, 2 or 3 dimensions.
    Any not given will default to your character's current x y or z.
  * bool item.Stackable: Stackable?
  * bool merchant.Open: Merchant open?
  * float merchant.Markup: The amount used to calculate item values on this merchant 
    (Markup is what your charisma, faction, etc change).  Markup*Cost=Merchant's sell price.
    Cost*(1/Markup)=Your sell price. Markup of 1.05 is highest no matter what, so there might
    not be any actual cap based on charisma.
  * int merchant.Items: Item count on the merchant
  * item merchant.Item[n]: nth item on the merchant  
  * bool corpse.Open: Corpse open?
  * int corpse.Items: Item count on the corpse
  * item corpse.Item[n]: nth item on the corpse
  * item character.Inventory[slotname]: Item in this slot (inventory slots only, but 
    same names as /itemnotify)
  * bool character.SpellReady[name]: Gem with this spell name ready for cast?
  * bool character.SpellReady[slot]: Spell in this gem ready for cast?

8 Apr 2004 by Lax (more)
- MQ2Data changes:
  Top level objects:
  * heading Heading[x,y]: Heading from player's current position to x,y
  Additions/Changes to existing types:
  * int item.Container: The number of slots, if this is a container
  * int item.Items: The number of contained items, if this is a container
  * item item.Item[n]: The item in this slot, if this is a container
- Item links were apparently not working in the MQ2ChatWnd, nobody reported this until now.
  Thanks people who noticed it and never reported it!  Anyway, item links in MQ2ChatWnd are
  simply stripped until I figure out the issue.  Item links in MQ2Chat still work fine.

8 Apr 2004 by Lax
- MQ2Data changes:
  - macro.Defined is now a top level object instead
    bool Defined[name]
  - Fixed all variable parsing when MQ2Parms is not on
- Fixed a major problem with /newif, should now "work as intended"
- Fixed (I think) problem with /face which let the macro continue before facing the target
  completed

7 Apr 2004 by Lax
- Changes to MQ2Data system:
  *** NOTICE: All X and Y coordinates used by the MQ2Data system have been REVERSED.
      Internally, MQ2 stays the same as it has been forever.  However, you will now
      notice that "/echo ${Me.X}, ${Me.Y}, ${Me.Z}" will give the same order as seen
      by typing /loc
  Top level objects:
  * currentzone Zone: Zone information about current zone
  * zone Zone[id]: Zone information for zone with this id
  * zone Zone[shortname]: Zone information for zone with this name
  * time Time: Your local time in real life
  * time GameTime: Game time
  * type Type[name]: Info about the type with this name
  * heading Heading[degrees]: Forms a heading type in the given direction in degrees
  * string Ini[filename,section,key,default]: Reads from an ini file.  section, key, 
    and default do not need to be given.  section and key may be set to -1 to skip them 
    and give a new value.  If section or key are not given, multiple values are read...
  Additions/Changes to existing types:
  * bool string.Equal[text]: Strings equal? Case does not count...
  * bool string.NotEqual[text]: Strings not equal? Case does not count...
  * bool string.EqualCS[text]: Strings equal? Case counts!
  * bool string.NotEqualCS[text]: Strings not equal? Case counts!
  * string string.Arg[n,separator]: Gets nth argument using separator as the separator (single character). If separator is not given, defaults to space
  * zone character.Bound: The zone you are bound in
  * int character.Skill[name]: Skill level of skill with this name
  * int character.Skill[n]: Skill level of skill with this index
  * int character.Ability[name]: Doability button number this skill name is on
  * string character.Ability[slot]: Skill name assigned to this doability button
  * bool character.AbilityReady[name]: Ability with this name ready?
  * bool character.AbilityReady[slot]: Ability on this button ready?
  * spell character.Book[slot]: Spell assigned to this slot in your spellbook
  * int character.Book[name]: Spell slot the spell with this name is assigned to in your spellbook
  * float (TOSTRING): Changed to ###.## instead of .###
  * heading spawn.Heading: (changed to "heading" type)
  * heading spawn.HeadingTo: (changed to "heading" type)
  * heading switch.Heading: (changed to "heading" type)
  * heading switch.DefaultHeading: (changed to "heading" type)
  * heading switch.HeadingTo: (changed to "heading" type)
  * heading ground.Heading: (changed to "heading" type)
  * heading ground.HeadingTo: (changed to "heading" type)
  New types:
  * currentzone
  * time
  * heading
  * type
  *** Special handling is used for casting to "type", such that the new data is equal 
      to the old type, and the new type is "type".
  -- Fixed type casting so that members of the new type may be accessed as expected (this
     was incorrectly ending the parsing at the type cast until now)
- ConColor changed to take 1 parameter
- FindMount tweaked/inlined
- Changed the "RunNextCommand" to remain to TRUE until set to FALSE, so only cases where
  the next command should not be run need to be explicitly set (this should increase
  macro performance in most cases, but some commands may need to be correctly updated)
- /declare will no longer spam you if the variable previously existed.  If the variable
  previously existed, it will be quietly deleted and replaced by the new one.  This might
  cause some people problems but they will learn quickly ;)
- New command /deletevar <name> - Deletes an existing variable.  Gives a message if the
  variable did not exist, but no message if the variable did exist.
- /notify modified to work for clicking off buffs and other things it would not previously
  work for.  However, items must still be clicked using /itemnotify.  /notify now accepts
  all of the same clicks as /itemnotify (leftmouse,leftmouseup,leftmouseheld,etc)

31 Mar 2004 by Lax (more)
- Fixed character member PctExp
- Added character members:
  float PctAAExp: % AA exp..
  bool Moving: Moving? (includes the mount hack so you're not constantly "moving" when sitting on a mount)
- Added spawn members:
  bool Swimming: Swimming?
  bool Underwater: Underwater?
  bool FeetWet: Feet at least wet?
  int Animation: Animation id
  int Holding: Holding id
  float Look: Look angle
- Added "gm" to standard searchspawn, works with anything that uses that including MQ2Map commands,
  /target, ${Spawn[search]}, etc
- Modified the if block parsing in FailIf so that it only looks for } and { as the first and last characters on a line

31 Mar 2004 by Lax
- Fixed /newif so variables/parms/data get parsed
- string.Mid and string.Find are now 1-based instead of 0-based
- Calculate (and stuff that uses it) now supports parentheses, and will treat 
  "NULL" and "FALSE" as 0, and "TRUE" as 1
- Added float math.Distance[x,y,z:x,y,z]: Performs distance calculations in 1, 2 or 3 dimensions.  Any not given will default to your character's current x y or z.

30 Mar 2004 by Lax
- Added a distance-sorted spawn list in MQ2Main
- Added MQ2Data top-level object:
  * spawn NearestSpawn[n]: The nth nearest spawn
  * spawn NearestSpawn[search]: The nearest spawn matching this search (same as Spawn[search])
  * spawn NearestSpawn[n,search]: The nth nearest spawn matching this search

29 Mar 2004 by Lax (even more)
- Added /ctrl /alt and /shift commands:
  /ctrl <command>
  /alt <command>
  /shift <command>
  These execute a command while telling the window manager that a key is pressed.  This can
  be used in conjunction with /itemnotify to pick up a stack or a single item... example:
  pick up a single item from a stack: /ctrl /itemnotify pack1 leftmouseup
  pick up an entire stack: /shift /itemnotify pack1 leftmouseup
  Because they execute a command, they can also be used together, as in 
  /ctrl /alt /shift <command>...
- Fixed character.Buff[slot]
- Fixed character.Gem[name]
- Fixed If top level object crashing on false
- Added MQ2CHAT bind to start typing in the MQ2 Chat Window, also added MQ2CSCHAT bind which
  gets forced to bind as "/" at character select, and does not exist while in game.
- Added /timed command, which executes a command after a specified duration (in deciseconds like pause)
  /timed <deciseconds> <command>
  Example: /timed 10 /echo 1 second has passed
  Note: This does NOT "pause" successive commands.
- Added /newif command, which ONLY does numeric compares -- use MQ2Data string comparison to 
  turn string compares into numeric compares -- and note that this means you do NOT use the "n"
  stuff.  This will replace the current /if command in MQ2Data phase 3.  Until then, you may 
  "/alias /if /newif" if you wish to use newif exclusively.
  /newif <calculations> <command>
  <calculations> gets evaluated down to a single term from however many terms there are (You
  may use && and || freely.) *BE WARNED* that in calculations parentheses are still not
  officially supported.. that's on my TODO list.
  

29 Mar 2004 by Lax (more)
- Added < <= == >= > && & || | to the Calculate function (someone rewrite if please... 
  fail if zero, fall through if non-zero)
- MQ2Data updates:
  * Added top level object: string If[conditions,whentrue,whenfalse]
  * Added type corpse, top level object: corpse Corpse
  * Added top level object: item Cursor
  * Added string members:
    - int Compare[text]: -1 if the string is alphabetically before text, 0 if equal, 1 if after. Case does not count.
    - int CompareCS[text]: -1 if the string is alphabetically before text, 0 if equal, 1 if after. Case counts.
  * Lots of others...
- Fixed MQ2Parm slowness from debug spew if MQ2Data is also in use
 
29 Mar 2004 by Lax
- Phase 1 of MQ2Data system rollout begins! Please start updating macros, custom uis, plugins,  
  etc to use this sytem.
  To use MQ2Data modify these MQ2Main lines
   #define USEMQ2PARMS
   //#define USEMQ2DATATYPES  
  Uncomment the USEMQ2DATATYPES #define to allow MQ2Data parsing.  If you wish to disable
  MQ2Parms parsing, comment the USEMQ2PARMS #define.  You may use both or just one.
  See this thread to see how MQ2Parms will be phased out 
      http://macroquest.sourceforge.net/phpBB2/viewtopic.php?t=6008
  See this thread to see how to use MQ2Data instead 
      http://macroquest.sourceforge.net/phpBB2/viewtopic.php?t=6022
  Specific information for plugins to add types and Top Level Objects will be available soon
- Moved a few functions to MQ2Inlines.h
- Fixed a performance issue in GetSpellByName
- Trying to detour an already detoured address will now fail instead of crashing
- Added some offsets to eqgame.h (mostly CListWnd), removed some offsets that were virtual
  functions and probably not used anyway.  If you are adding basic UI offsets to your plugins
  ask to have them in eqgame.h please (people were doing this with CListWnd offsets).

23 Mar 2004 by Amadeus
- Removed DisplayZem function and calls and $zone(ZEM)  ...rest in peace.

20 Mar 2004 by Lax
** eqgame.ini is no longer used/needed by MQ2!  All offsets have been integrated 
   into eqgame.h.  The client DATE/TIME are in eqgame.h also.
- Fixed /itemnotify
- Renamed the "SpawnListTail" stuff to "LocalPlayer", added "ControlledPlayer".  These are
  both EQPlayer and correspond to .. you.  If you're on a mount, the one thats moving is
  ControlledPlayer. ** Things that use PCHARINFO to get your spawn should be phased out.
- Added /docommand
- Added /dosocial
- Made some minor improvements in MQ2UserVars

16 Mar 2004 by Lax (after patch)
- Changed exe date/time checking to use the date/time strings compiled into the exe

16 Mar 2004 by Amadeus
- Updated the Spell Information Window with code provided by Koad in his Spell Search
  Plugin.

16 Mar 2004 by Lax
- Fixed remaining issues with binds and custom binds

15 Mar 2004 by Lax (more)
- Added remaining, un-named EQ binds to the MQ2 bind system.  Some are still unknown, and
  some I'm surprised exist enabled in the client in the first place, and you should be 
  careful with those...
- Added /dumpbinds command.  Example: "/dumpbinds bill" will dump all current binds to
  Configs\bill.cfg to be loaded later.
- Added "/filter mq [on|off]", which prevents anything at all from being displayed by MQ2
- Added "/squelch <command>", which does the following:
  * Step 1: turns mq filter off
  * Step 2: executes the command
  * Step 3: turns mq filter back to the state it was in before step 1
  In other words, executes a command and prevents any output from the command
  
  ** It is recommended that you do this in your .CFG files that you dont want to see output from
  /squelch /filter mq on
  < do your stuff here>
  /squelch /filter mq off
- I promise this is my last update for a few days at least!

15 Mar 2004 by Lax
- Fixed some bugs with binds and the MQ2CustomBinds plugin
- Modified bind system so that the same key can be bound to an MQ2 bind and an EQ bind and
  both will work
- Added a system to run .CFG files, similar to quake .cfg files I suppose.  The file must
  contain commands the same as you would use them normally.  Each command will be executed
  in order, there are NO macro blocks, events, etc, in a cfg file.
  * CFG files may be present in <release>\Configs\, in <release>\, or potentially in the
    EverQuest directory.  Note that <release> would be the same as wherever your Macroquest.ini is.
  * Added /loadcfg <filename> command.
  * Plugins can use LoadCfgFile(filename)
  * Configs that are automatically loaded:
		AutoExec.CFG - Executed on the first pulse
		CharSelect.CFG - Executed when you are put at character select
		<server>_<character>.CFG - Executed when this character enters the world
		<mapshortname>.CFG - Executed when you zone into this zone
		<pluginname>-AutoExec.CFG - Executed when this plugin is loaded (after its initialization is complete)

		Examples of file names:
		tallon_lordsoth.cfg - character
		oot.cfg, soldungb.cfg, soldunga.cfg, take.cfg - maps
		MQ2Map-AutoExec.CFG, MQ2ChatWnd-AutoExec.CFG - plugins 

14 Mar 2004 by Lax
- Added /ranged [#] command.  Run with no parameters to do a ranged attack on your current
  target, or with a spawn ID to do a ranged attack on that spawn.
- Modified MQ2Spawns, hopefully this will solve the remaining stack corruption problems...
- Introduction of the new MQ2 key binding system
  * New command /bind <list|eqlist|[~]name <combo|clear>>
  * "/bind list" will list all MQ2 binds
  * "/bind eqlist" will list all non-MQ2 binds
  * The following work on both MQ2 and EQ binds the same way
  * "/bind <name> <combo>" will set a bind's normal key combo (example: "/bind forward e")
  * "/bind ~<name> <combo>" will set a bind's alternate key combo (example: "/bind ~forward up")
  * Combos use any combination of "alt", "shift" and "ctrl" plus a key.  Specific keys follow the 
    same rules as the /sendkey and /press 
    Example combos:
    shift+n
    alt+shift+f1
    -- Always separate with +'s or spaces.
  * Note that "clear" combo is to clear the bind, and also note that changing EQ binds will not
    immediately update the display in the options window.  Change the bind list selection in the
    options window to see the updated keys.
  * /keypress works the same way with all MQ2 and non-MQ2 binds
  * API additions include:
     BOOL AddMQ2KeyBind(PCHAR name, fMQExecuteCmd Function);
     BOOL SetMQ2KeyBind(PCHAR name, BOOL Alternate, KeyCombo &Combo);
     BOOL RemoveMQ2KeyBind(PCHAR name);
     BOOL ParseKeyCombo(PCHAR text, KeyCombo &Dest);
     PCHAR DescribeKeyCombo(KeyCombo &Combo, PCHAR szDest);

     typedef VOID    (__cdecl *fMQExecuteCmd)(PCHAR Name,BOOL Down);
     -- Note: This function will be called when the key goes down as well as up.  If you create a
        MQ2 bind function make sure to account for this.  The "Name" parameter is the name of the
        bind
  * /hotkey command is now removed, the new bind system will take over
- MQ2CustomBinds plugin is now live.  This plugin allows you to specify custom commands to execute
  on a key combination.  There may be a command for the keys being pressed (down), and another for them
  being released (up).
  * /custombind <list|add <name>|delete <name>|clear <name><-down|-up>|set <name><-down|-up> <command>>
  * "/custombind list" will list all of your custom binds names and commands (the key combinations must be set using /bind)
  * "/custombind add <name>" will add a new bind name for use here, with /keypress, /bind, etc.
  * "/custombind delete <name>" will remove a custom bind
  * "/custombind clear <name><-down|-up>" will clear a specific command for a custom bind.  If up or down is not specified, defaults to down.
  * "/custombind set <name><-down|up> <command>" will set a specific command for a custom bind.  If up or down is not specified, defaults to down.
  * Example usage (NOTE: MQ2's very first bind command is "RANGED" so you do not need to do this, but for example...)
    /custombind add mybind
    /custombind set mybind /ranged
    /bind bind n
    -- To set the real RANGED bind, do "/bind ranged <key>"
   
13 Mar 2004 by Lax
- Added /multiline <delimiter> <command[delimiter[command[delimiter[...]]]]>
  Executes all commands.  Example: /multiline ; /stand;/rude;/sit
- Wave 3 of MQ2Map updates:
  * Added /maphide command to hide spawns on the map given a search string.  Hidden spawns
    only take effect until the mapped spawns are re-generated (such as changing some map
    filters)
    "/maphide reset" will re-generate the spawn list.
  * Added /mapshow command, to explicitly show spawns on the map given a search string.
    These will only take effect until the mapped spawns are re-generated (same as maphide).
    "/mapshow reset" will re-generate the spawn list.
  * Added /mapclick command and special right click commands (hold a combination of
    shift, control, left alt, right alt to execute a special command when right clicking
    on a spawn).  Defaults include left-alt right-click to highlight and control r-click to
    hide.
  * Added Group filter (requires PC) and NormalLabels filter (shows/hides non-MQ2 labels)  
- Added notice when a new XML file is added to the list while in game.  The notice
  says which file was added and that the user must reload the ui for it to take effect.
- Fixed crash when adding a custom XML file that doesnt exist in the default UI directory
- Fixed $macro crash

12 Mar 2004 by Lax
- MQ2Map overhaul completed
- Fixed /keypress crash bug when you're an idiot and type an invalid command name :)
- Fixed client override problem

11 Mar 2004 by Lax 
- I forgot to update the changes.txt file, so Amadeus is putting this here
  so the masses will know I added/fixed/updated a bunch of shit.

11 Mar 2004 by Amadeus
- Updated tons of shit too
- MQ2 should be fully functional now with the 3/10 patch

11 Mar 2004 by Plazmic
- Complete rewrite of the way Guild ID tags are handled
- __Guild offset now points to the GUILD structure instead of the random offset
  that shows the beginning of the list
- GUILD structure added to eqgame.h
- EQADDR_GUILDLIST should now be pGuildList always
- Added EQSWITCH structure
- Updated DOOR & GROUNDITEM structs to reflect the new EQSWITCH struct

08 Mar 2004 by Lax
- Wave 2 of MQ2Map upgrades:
  /mapnames command added to change the naming scheme used for spawns on the map
  Map filters/options system updated, each option can now have a "requirement"
  When listing filters with /mapfilters, only options that have requirements are displayed
  Concolor filter is now PCConColor and NPCConColor
  Target filter now has 3 separate options - Target, TargetLine, TargetRadius

05 Mar 2004 by Amadeus
- Put in new CXWnd offsets [vzmule]
- Added structs in EQUIStruct.h for the Guildwindow and RaidWindow (work in progress)

05 Mar 2004 by Lax
- MQ2Map upgrade is now live.  It uses the new OnAddSpawn/OnRemoveSpawn API to increase efficiency.
  /highlight <spawn search string> will temporarily highlight these spawns
  /highlight color <#> <#> <#> will set the highlight color
  /highlight reset to reset the currently highlighted spawns
  Right clicking on spawns on the map now targets them
- /keypress command is now live. /keypress <name> <hold> like so:
  /keypress clear_target
  /keypress forward hold
  To release the key after holding, simply use the command again without the hold keyword.
- /itemnotify command is now live.  /itemnotify <slot> <notification>, or /itemnotify in <bag slot> <#> <notification>
  Bag slots are pack1-8, bank1-16 (and sharedbank1-2 and trade1-8 but these are not yet implemented in /itemnotify)
- Added OnAddGroundSpawn/OnRemoveGroundSpawn to plugin callbacks
- Fixed random crash on exit dealing with breakpoints

01 Mar 2004 by Zaphod
- Another bugfix in MQ2DetourAPI.cpp. 

29 Feb 2004 by Zaphod
- More optimization of ParseMacroParameter() and some of the parameter routines it calls.
- Minor bugfix in MQ2DetourAPI.cpp. 

28 Feb 2004 by Lax
- Added API to automatically maintain a list of all initialized windows 
  This will only have the most recent one initialized for each "screen item" name
  Functions are in place to add/remove windows to the list with different names, etc.
- Added /notify and /windows commands
- eSpawnType enum (NONE,PC,MOUNT,PET,NPC,CORPSE,TRIGGER,ITEM) and GetSpawnType function 

28 Feb 2004 by Zaphod
- Major optimization/cleanup of ParseMacroParameter().

22 Feb 2004 by Amadeus
- Updated readme.html [thanks Wassup!]

22 Feb 2004 by Lax
- Updated license notice in each source file for 2004 and made sure each had one
- Added MQ2Spawns.cpp, which gives us hooks when a spawn is added to or removed from a zone.
  This could be used, for example, to increase the efficiency of MQ2Map.
  PLUGIN_API VOID OnAddSpawn(PSPAWNINFO pNewSpawn)
  PLUGIN_API VOID OnRemoveSpawn(PSPAWNINFO pSpawn)
  
19 Feb 2004 by Amadeus
- General Cleanup and offset updates for 02/18/2004 patch
- Added Endurance to CHARINFO and $char(endurance,cur)  [Teh_ish]

17 Feb 2004 by Amadeus
- Added initial EQTRADESKILLWINDOW & EQTRADESKILLRECIPE struct
- Added pet window to the /windowstate command (ie:  /windowstate pet open/close)
- Added initial EQPETINFOWINDOW struct 
- Updated the mq2irc plugin to have the new irc server information
- Added a bunch of new parameters:
  * $pet(buff,"<spellname>")   [returns buff slot number]
  * $pet(buff,#,id)            [returns the spellID for the buff slot # given]
  * $pet(buff,#,name)          [returns the name for the buff slot # given]
  * $pet(level)
  * $pet(id)
  * $pet(x)
  * $pet(y)
  * $pet(z)
  * $pet(name)
  * $pet(class)
  * $pet(race)

16 Feb 2004 by Amadeus
- Fixed EQ_CONTAINERWND_MANAGER  (which fixes $envopen )
- Added "Frenzy" to skills.h [daerck]
- Fixed EQLOOTWINDOW struct (which fixes $corpse(empty) and $corpse(has,xxx)

15 Feb 2004 by Amadeus
- 'Grouped' location fixed in CHARINFO (thereby fixing $char(grouped))
- Fixed WhoFollowing in Actorinfo (thereby fixing $char(following)
- Added IsABoat to Spawninfo
- Went ahead and added the dx9.0 dinput.h to the cvs to be ready for next patch
  * As far as I can tell, the changes between 8.1 and 9.0 for dinput.h are VERY
    minimal.

14 Feb 2004 by Amadeus
- Fixed a LOT of wrong offsets in eqgame.h
- Added four offsets to eqgame.h:
  * pinstTextMessageWnd 
  * pinstCDynamicZoneWnd 
  * pinstCTargetOfTargetWnd
  * pinstCTradeskillWnd 

13 Feb 2004 by Amadeus
- Added CareerFavor and CurrFavor to CharInfo [Macrofiend]
- Added $char(favor,cur) & $char(favor,career) [Macrofiend]

12 Feb 2004 by Amadeus
- ACTORINFO struct fixes :: fixed $char(pet)
- Added a bunch of code by ml2517
   * $char(height), $spawn(#,height), $target(height)
   * $target(maxrange), $spawn(#,maxrange)
   * $distance(y,x[,z][:y,x[,z]])

11 Feb 2004 by Amadeus
- Fixed Attacks offset in eqgame.ini
- Added an emergency placeholder in the ACTORINFO struct to fix $char(casting)
  (This structure will be fixed soon.)

11 Feb 2004 by Zaphod (dohpaZ)
- Added Beserker to the classes and Gates of Discord to the expansions.
- Fixed my name in the readme.html

10 Feb 2004 by Amadeus
- Updated structs and offsets
- Added 'favor' (Tribute Value) to ITEMINFO
- Added code to MQ2ITemDisplay to show item tribute value

09 Feb 2004 by Amadeus
- UPDATED SOURCEFORGE CVS!
- Small additions to the structs from suggestions on the message boards and
  a couple new things to the ItemDisplay plugin.

20 Jan 2004 by dkaa
    According to Pragma:
        1 bug: in the code for $rand(), there needs to be a srand(time(0));
        2 bug: in the code for $gamestate, $servername, and $loginname, the 
            value returned is 1 too high. You need to return length-1, which 
            is 8 for loginname and gamestate, and 9 for servername, this will 
            fix parsing issues.

18 Jan 2004 by Amadeus
- SpellID in _SPELLBUFF is now a DWORD vs. WORD 
- Updated SpellInfo formulas used in the itemdisplay mod
- Added Instrument mod information to the itemdisplay mod (thanks TheColonel)

17 Jan 2004 by Valerian
- Fixed _ITEMINFO struct -- minor correction to the size of one of the unknowns to realign.

11 Jan 2004 by DKAA
- Fixed the $combat to reflect the status of autoattack (Thanks Sharp of Fairlight)

7 Jan 2004 by EqMUle
- added Readme.html updated by Wassup

5 Jan 2004 by EqMUle
- Added [bzrtrader_start] and [pc_trade_yes] to locations.txt. Thanks to Zacaria for theese.

1 Jan 2004 by Lax
- Chat hook is no longer responsible for when zoning is finished or game is entered
- Added $merchant(markup)

31 Dec 2003 by Lax
- ESC no longer hides the MQ2ChatWnd or MQ2IRC windows and they are no longer closable
- Fixed STMLToPlainText
- Made MQ2Labels use STMLToPlainText to convert the tooltip tags (this means you can
  use < and > by using "&lt;" and "&gt;", respectively)

31 Dec 2003 by Amadeus
- Added $spell(xx,spelltype),$spell(xx,targettype),$spell(xx,name),$spell(xx,aerange),
  $spell(xx,pushback),$spell(xx,resisttype),$spell(xx,resistadj),$spell(xx,fizzletime)
- Removed $spawn(#,castingspellid) & $target(castingspellid)  
  [http://macroquest.sourceforge.net/phpBB2/viewtopic.php?p=33124#33124]
- Added Uninterruptable and Autocast to SPELL along with other fixes (thanks SoF & Koad)
- Added more functionality to the Spell Inspect Window.  You will now see the Effect of the 
  spell and the classes that can use it.  You might really find it interesting to 
  Alt-LeftClick on some of your buffs and find out exactly what they are doing to you!  It's
  almost like having an ingame Lucy connection -- and we owe a great deal of this functionality
  to Koad and borrowed code from his spellsearch plugin.
  
  **NOTE:  The formulas for this are still being tweaked.  If you wish to help iron these
           out, please post under Koad's thread on MQ2:Plugins board.  He is the keeper of 
           of the spell effects/slots formula. **


30 Dec 2003 by Lax
- Updated version number since it's not Christmas anymore..
- Fixed commands that werent supposed to be working at char select so they dont crash
- Removed some extraneous offsets from eqgame.h
- Fixed RemoveOurDetours() so it doesnt hang
- Add something very special that everyone will love!
- Fixed a bunch of $target(xxx) crashes when no target

30 DEC 2003 by EqMule
- fixed a couple unsigned/signed warnings when compiling in VC6

29 Dec 2003 by Amadeus
- Added Levitating and Sneaking; Fixed AARank and Linkdead in SPAWNINFO (thanks source)
- Added $char(levitating), $target(levitating), $spawn(#,levitating) -- returns TRUE or FALSE
- Added $char(sneaking), $target(sneaking), $spawn(#,sneaking) -- returns TRUE or FALSE
- Went through all macro routines and made sure that everything uses lower case 
  ie, $target(castingspellid) rather than $target(CastingSpellID).
- Added <Sneak> to the superwho (thanks vzmule/source)

29 Dec 2003 by Lax
- MQ2Auth modified.
    * MQ2Auth now produces MQ2Auth0.h instead of MQ2Auth1.h and MQ2Auth2.h
    * MQ2Auth will import existing MQ2Auth2.h into MQ2Auth0.h if MQ2Auth0.h does not
      already exist but MQ2Auth2.h (in other words, it will import your "keyring" to
      MQ2Auth0.h)
    * MQ2Auth now accepts a command line parameter telling it the path to use
- Merged BOOK, COMMON, CONTAINER structs into ITEMINFO (the individual structs no
  longer exist!)

29 DEC 2003 by EqMule
- fixed /click left item

28 Dec 2003 by Amadeus
- Added PushBack and ResistAdj to Spell struct
- Added functionality to the ItemDisplay Plugin that shows the following information
  about spells when you "examine" a spell from a gem or your spellbook: ID, Duration, 
  RecoveryTime, RecastTime, Range, AERange, PushBack, Resist Type and Resist Adjust.  
  You will notice that if a spell doesn't have any of these values, then that field 
  will not be shown at all.  (**More functionality to come later**)
- Added MQ2Bzrsearch to the VS.net solution file.

27 Dec 2003 by Lax
- Changed around plenty of stuff
- EQUIPMENT struct no longer uses names for its union members...
- SPELLLIST changed to SPELL, SPELLPOINTER changed to SPELLMGR
- Added O(1) access to GetSpawnByID
- Added O(1) access to GetSpellByID
- Most window base classes set up correctly
- MQ2ChatWnd updated to use a custom window, and allows typing in edit box.  Also shows up at char select to annoy you all.
- MQ2IRC updated to allow typing in edit box (goes to channel...)
- Tons of function offsets added for UI stuff, have fun with that
- Added functionality so commands can be set to work in-game only (will be ignored outside of game, at char select for example)

26 Dec 2003 by Amadeus
* Added szBaneDmgType (thanks to TheColonel)
* _CONTENTS tweak (thanks to TheColonel)
* "Price" added to _CONTENTS (thanks to Pragma)
* SPELLLIST update (thanks to Sharp of Fairlight)
* Updated MQ2Ext
* Added $spell(id,xxx) -- **$spell() will now accept either ID# or Name as first parameter**

25 Dec 2003 by Amadeus
* Added CastingSpellID to Actorinfo struct (thanks to Sharp of Fairlight)
* Reworked $char(casting) to use more efficient CastingSpellID
* Added $char(castingspellid), $spawn(#,castingspellid), $target(castingspellid)  
* Fixed $char(held,left), $char(held,right), $char(held,shield)
* Added $char(held,primary), $char(held,offhand) 
* Fixed $target(held,left), $target(held,right), $target(held,shield)
* Added $target(held,primary), $target(held,offhand) 
* Fixed $spawn(#,held,right), $spawn(#,held,left), $spawn(#,held,shield)
* Added $spawn(#,held,primary), $spawn(#,held,offhand)
* Added AERange to SPELLLIST struct (thanks to Sharp of Fairlight)
* More changes to ActorInfo (Timestamp stuff) thanks to Sharp of Fairlight

25 Dec 2003 by EqMule
- fixed /banklist crash
- fixed $char(ismoving) - thanks to ml2517
- added makezip.bat to make zip file creation easier...

24 Dec 2003 by Lax
- Updated offsets with correct ones
- Replaced remaining calls to AddDetour with EasyDetour and EasyClassDetour
- Updated EasyDetour/EasyClassDetour defines to explicitly cast the offset to DWORD
- Updated MQ2IRC with current version from forum
- Modified CHARINFO struct to use Inventory and InventoryArray for inventory member names.
- Fixed $lastcommand
- Fixed $char(hp,cur), $char(hp,max), $char(hp,pct)

24 Dec 2003 by Amadeus
- Fixed CHARINFO (thanks to TheColonel for new stuff)
    * CHARINFO now has:
  	+ HPBonus
	+ ManaBonus
	+ PercentEXPtoAA
	+ GukEarned
	+ MMEarned
 	+ RujEarned
	+ TakEarned
	+ LDoNPoints
- Removed Stamina from all references in parser and struct
+ Added $char(HPBonus), $char(ManaBonus), $char(PercentEXPtoAA), $char(GukEarned),
  $char(MMEarned), $char(RujEarned), $char(TakEarned), $char(LDoNPoints)
+ Updated _COMMON (thanks again to TheColonel)
   	* Added BaneDMG;
   	* Added Lore
   	* Added BaneDMGType
   	* Added InstrumentType
   	* Added InstrumentMod
   	* Added DmgBonusType
   	* Added DmgBonusVal
   	* Fixed Range
+ Added szTheme[]
+ Added szDmgBonusType[]
+ Updated ItemDisplay Plugin to include LDoN stuff (TheColonel)
+ Updated itemtypes.h with "All Instruments" as type 51 (thanks TheColonel)
+ Removed $item(lore) & $cursor(lore)
+ Added $item(LDTheme) & $cursor(LDTheme)
+ Added $item(DmgBonusType) & cursor(DmgBonusType)
+ Fixed $char(Mounted)


21 Dec 2003
+ Added MQ2Mouse2.cpp.  Don't need to compile this, it's the new mouse code.  Incomplete and inop.

21 Dec 2003 by Amadeus
- Fix for MQ2Ext

19 Dec 2003 by EqMule
+updated offsets, structs for todays patch...

15 Dec 2003 by Amadeus
- Fix for $target(sclass)
- Fix for FullClassToShort
* Thanks to Schark for these*

13 Dec 2003 by Amadeus
- Added MQ2Ext to the project

06 Dec 2003 by Lax
- Added benchmark system.
- Modified pulse behavior so that executing macro commands is separate from other pulse stuff
- Modified MQ2FPS to take the above into account (it no longer needs to know about macros)
- Updated MQ2IRC to be current with the version posted in forums
- Added /bench command which with no parameters outputs currently active benchmark stats to chat
  When used with parameters, /bench will benchmark a command.  /bench [command]
  Example: /bench /who all friends

05 Dec 2003 by Mckorr
+Fix for CTD when using /click left|right target when nothing was targetted (motd2k)

05 Dec 2003 by EqMule
+Fixed $searchspawn(pc,loc:x:y,radius:100) using Ohmz code. see
http://macroquest.sourceforge.net/phpBB2/viewtopic.php?t=3394&highlight=searchspawn+loc
for more info
+Fixed /selectitem to look in all 80 merchantslots, previously it would stop at 79
+misc small fixes

03 Dec 2003 by Lax
- Added custom windows system:
** CCustomWnd base class for your windows
** AddXMLFile, RemoveXMLFile to manage custom xml files
** More info / example coming
- Added MQ2IRC plugin to CVS with some changes
- Added MQ2EQIM plugin, which handles buddy list info (custom window soon, also auto loading buddy list)
- Updated MQ2EQBugFix plugin to solve current journal npc window crash (and it shouldnt make it not show anything this time)
- Added OnReloadUI callback, called after /loadskin command is used
- Fixed hangups compiling with VC6
- Added EasyDetour and EasyClassDetour to ease the pain of hooking functions

02 Dec 2003 by Mckorr
- Fixed SHA in short classes, is now SHM.  Added Rogue/ROG (I missed that one before)
- Added $spawn(#,sclass)

27 Nov 2003 by Lax
- / command correctly does EQ /who by default
- MQ2Telnet redone.
- Plugins using DoCommand() will execute it on the next pulse instead of immediately (corrects problems unloading the plugin)
- MQ2FPS shouldn't cause major problems when switching from absolute to calculate mode
- MQ2Template removed from VS6 workspace and .NET solution

25 Nov 2003 by Lax
- MQ2FPS now has a /fps command that can change some other settings.  Selecting "absolute" mode will switch to "cpu limiter" style, while "calculate" mode will switch to "fps limiter" style.  FPS limiter is default.  The same command will allow you to reposition the FPS indicator display.
- MQ2FPS display now shows a * if using absolute mode, and will show /MACRO if a macro is being executed that causes the limiting to be minimal
- Added aliases /g and /gu to the default list
- Macroquest2.exe now pops up a message box if the system failed to load MQ2Main.dll

20 Nov 2003 by EqMule
fix for $merchant(name)

20 Nov 2003 by Lax
*** MacroQuest2.exe is now pre-compiled, you no longer compile this yourself.  MQ2Auth implemented.  Run it before compiling on each machine.

- MacroQuest program will no longer use loadlibrary, it loads our library directly.
- The version number is now stored in MQ2Main.h as the top line, and not in macroquest.ini.  When compiled it becomes a global variable.  Comparing the global variable gszVersion with the #define in MQ2Main.h will cause the tray icon tooltip to suggest recompiling if necessary.
- Removed EQADDR_SLOTLIST, which is now ppInvSlotMgr/pInvSlotMgr
- Fixed MQ2Telnet crashes (for real)
- Added DebugSpewNoFile which does not write to file even if debugspewtofile=1.  This is useful for when we can't put up with the file access times.  All Macro commands and parser api debug spew has been changed to this form.  Note that this debug spew is still useful for when you attach a debugger.

19 Nov 2003 by EqMule
+Added new command /destroy
will destroy whatever you have on your cursor. Use with care.
example: /if "$cursor(name)"~~"rusty" /destroy
In order to get that to work I had to declare EQ_PC (MQ2Globals.h(250):EQLIB_VAR EQ_PC **ppPCData;)

19 Nov 2003 by Lax
- Fixed MQ2Telnet to not crash on unload (probably).  Critical sections were getting deleted twice.
- Fixed aliases to work when given parameters

18 Nov 2003 by EqMule
+fix: mouseto and click by changing ScreenX and ScreenY to ScrX and ScrY)
+Added  EQLIB_API VOID AddParm(PCHAR Name, fMQParm Function);
    EQLIB_API VOID RemoveParm(PCHAR Name);
to MQ2Main.h so that custom plugins will find them...
+updated $merchant(has,xxx) with HanzO's code for it, thank you.
+Updated $selecteditem() with new (count) for easier usage of /sellitem and /buyitem
example: /sellitem $selecteditem(count) self
+misc fixes...

