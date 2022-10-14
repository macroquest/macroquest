-- plugintemplate.lua : Defines the plugin table that defines a lua plugin.

-- All existing callbacks at this time are shown below. Remove the ones your
-- plugin does not use. Always use InitializePlugin and ShutdownPlugin for
-- setup and cleanup, respectively.

--- The mq require is mandatory to provide the plugin table factory
---@class Mq
---@field public plugin fun(name:string, version:string):Plugin
local mq = require("mq")

--- If the imgui callback is to be used, be sure to also require the ImGui
--- interface
---@type ImGui
local imgui = require("ImGui")

--- The plugin table factory will instantiate a plugin object that is used to
--- define all the functionality of the plugin. A name and version is supplied
--- to the factory function and both are required strings.
---@class Plugin
---@field public name string the name of the plugin, specified in this factory
---@field public version string the version of the plugin, specified in this factory
---@field public addcommand fun(self:Plugin, command:string, func:fun(line:string))
---@field public removecommand fun(self:Plugin, command:string):boolean
---@field public addtype fun(self:Plugin, type:string, definition:table)
---@field public removetype fun(self:Plugin, type:string)
---@field public addtlo fun(self:Plugin, tlo:string, func:fun(index:string):any)
---@field public removetlo fun(self:Plugin, tlo:string):boolean
local plugin = mq.plugin("name", "version")

--- Plugin "global" state can be stored as variables on the plugin object, and
--- any functions can be defined on the object, they will be persisted with the
--- plugin object and can be used in any registered functions, provided a self
--- argument is provided to access them
plugin.is_open = false
function plugin:ToggleOpen()
	self.is_open = not self.is_open
end

--- Plugin commands, datatypes, and TLOs will need definitions that will be
--- passed into the add functions during initialization
function plugin:mycommand(Line)
	printf("Received mycommand with line: %s", Line)
end

---@class MyType
---@field value string the value of my type

--- function to assign to the Echo member
---@param self Plugin optionally specify a self plugin
---@param val string the storage value of the type, can be any type
---@param index string an index if required (must still have the parameter specified)
---@return string the name of the type that is returned
---@return string the storage value of the type, our storage type is a string
function plugin:Echo(val, index)
	return "string", val
end

--- function to open the ImGui window
---@param self Plugin optionally specify a self plugin
---@param val string the storage value of the type, can be any type
---@param index string an index if required (must still have the parameter specified)
function plugin:Open(val, index)
	self.is_open = true
end

--- function for the ToString callback
---@param self Plugin optionally specify a self plugin
---@param val string the storage value of the type, can be any type, our storage type is a string
---@return string the string representation of val
function plugin:ToString(val)
	return val
end

--- function for the FromData callback
---@param self Plugin optionally specify a self plugin
---@param source string the storage value of the type, can be any type, our storage type is a string
---@return string the storage value of the type, our storage type is a string
function plugin:FromData(source)
	return source
end

--- function for the FromString callback
---@param self Plugin optionally specify a self plugin
---@param source string the string representation of the storage value
---@return string the storage value of the type, our storage type is a string
function plugin:FromString(source)
	return source -- our storage type is a string
end

-- datatypes are defined by tables with 5 (all optional) members: Members, Methods,
-- ToString, FromData, and FromString.
---@class Datatype
---@field public Members table
---@field public Methods table
---@field public ToString fun(self:Plugin, val:any):any
---@field public FromData fun(self:Plugin, source:any):any
---@field public FromString fun(self:Plugin, source:string):any
plugin.mytype = {
	Members = {
		Echo = plugin.Echo,
	},
	Methods = {
		Open = plugin.Open,
	},
	ToString = plugin.ToString,
	FromData = plugin.FromData,
	FromString = plugin.FromString,
}

-- tlo functions return a tuple of typename (which can be any valid MQ typename
-- like 'string' or 'spawn' and then the data required to assign the value)
function plugin:mytlo(Index)
	return "mytype", Index
end

--- InitializePlugin
---
--- This is called once on plugin initialization and can be considered the startup
--- routine for the plugin.
---
---@param self Plugin optionally specify a self plugin
function plugin:InitializePlugin()
	printf("%s::Initializing version %f", self.name, self.version)

	self:addcommand("/mycommand", self.mycommand)
	self:addtype("mytype", self.mytype)
	self:addtlo("mytlo", self.mytlo)
end

--- ShutdownPlugin
---
--- This is called once when the plugin has been asked to shutdown. The plugin has
--- not actually shut down until this completes.
---
---@param self Plugin optionally specify a self plugin
function plugin:ShutdownPlugin()
	printf("%s::Shutting down", self.name)

	self:removecommand("/mycommand")
	self:removetype("mytype")
	self:removetlo("mytlo")
end

--- @fn OnCleanUI
---
--- This is called once just before the shutdown of the UI system and each time the
--- game requests that the UI be cleaned. Most commonly this happens when a
--- /loadskin command is issued, but it also occurs when reaching the character
--- select screen and when first entering the game.
---
--- One purpose of this function is to allow you to destroy any custom windows that
--- you have created and cleanup any UI items that need to be removed.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnCleanUI()
	printf("%s::OnCleanUI()", self.name)
end

--- OnReloadUI
---
--- This is called once just after the UI system is loaded. Most commonly this
--- happens when a /loadskin command is issued, but it also occurs when first
--- entering the game.
---
--- One purpose of this function is to allow you to recreate any custom windows
--- that you have setup.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnReloadUI()
	printf("%s::OnReloadUI()", self.name)
end

--- OnDrawHUD
---
--- This is called each time the Heads Up Display (HUD) is drawn. The HUD is
--- responsible for the net status and packet loss bar.
---
--- Note that this is not called at all if the HUD is not shown (default F11 to
--- toggle).
---
--- Because the net status is updated frequently, it is recommended to have a
--- timer or counter at the start of this call to limit the amount of times the
--- code in this section is executed.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnDrawHUD()
	if not self.DrawHUDTimer then
		self.DrawHUDTimer = os.clock()
	end
	if os.clock() > self.DrawHUDTimer then
		-- Wait half a second before running again
		self.DrawHUDTimer = os.clock() + 0.5
		printf("%s::OnDrawHUD()", self.name)
	end
end

--- SetGameState
---
--- This is called when the GameState changes. It is also called once after the
--- plugin is initialized.
---
--- For a list of known GameState values, see the constants that begin with
--- GAMESTATE_. The most commonly used of these is GAMESTATE_INGAME.
---
--- When zoning, this is called once after OnBeginZone OnRemoveSpawn
--- and OnRemoveGroundItem are all done and then called once again after
--- OnEndZone and OnAddSpawn are done but prior to OnAddGroundItem
--- and OnZoned
---
---@param self Plugin optionally specify a self plugin
---@param GameState number The integer value of GameState at the time of the call
function plugin:SetGameState(GameState)
	printf("%s::SetGameState(%d)", self.name, GameState)
end

--- OnPulse
---
--- This is called each time MQ2 goes through its heartbeat (pulse) function.
---
--- Because this happens very frequently, it is recommended to have a timer or
--- counter at the start of this call to limit the amount of times the code in
--- this section is executed.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnPulse()
	if not self.PulseTimer then
		self.PulseTimer = os.clock()
	end
	if os.clock() > self.PulseTimer then
		-- Wait 5 seconds before running again
		self.PulseTimer = os.clock() + 5
		printf("%s::OnPulse()", self.name)
	end
end

--- OnWriteChatColor
---
--- This is called each time WriteChatColor is called (whether by MQ2Main or by any
--- plugin). This can be considered the "when outputting text from MQ" callback.
---
--- This ignores filters on display, so if they are needed either implement them in
--- this section or see OnIncomingChat where filters are already handled.
---
--- If CEverQuest::dsp_chat is not called, and events are required, they'll need to
--- be implemented here as well. Otherwise, see OnIncomingChat where that is
--- already handled.
---
--- For a list of Color values, see the constants for USERCOLOR_. The default is
--- USERCOLOR_DEFAULT.
---
---@param self Plugin optionally specify a self plugin
---@param Line string The line that was passed to WriteChatColor
---@param Color number The integer type of chat text this is to be sent as
---@param Filter number default 0
function plugin:OnWriteChatColor(Line, Color, Filter)
	printf("%s::OnWriteChatColor(%s, %d, %d)", self.name, Line, Color, Filter)
end

--- OnIncomingChat
---
--- This is called each time a line of chat is shown. It occurs after MQ filters
--- and chat events have been handled. If you need to know when MQ2 has sent chat,
--- consider using OnWriteChatColor instead.
---
--- For a list of Color values, see the constants for USERCOLOR_. The default is
--- USERCOLOR_DEFAULT.
---
---@param self Plugin optionally specify a self plugin
---@param Line string The line of text that was shown
---@param Color number The type of chat text this was sent as
---
---@return boolean Whether to filter this chat from display
function plugin:OnIncomingChat(Line, Color)
	printf("%s::OnIncomingChat(%s, %d)", self.name, Line, Color)
	return false
end

--- OnAddSpawn
---
--- This is called each time a spawn is added to a zone (ie, something spawns). It is
--- also called for each existing spawn when a plugin first initializes.
---
--- When zoning, this is called for all spawns in the zone after OnEndZone is
--- called and before OnZoned is called.
---
---@param self Plugin optionally specify a self plugin
---@param NewSpawnID number The id of the spawn that was added
function plugin:OnAddSpawn(NewSpawnID)
	printf("%s::OnAddSpawn(%s)", self.name, mq.TLO.Spawn(NewSpawnID).Name())
end

--- OnRemoveSpawn
---
--- This is called each time a spawn is removed from a zone (ie, something despawns
--- or is killed). It is NOT called when a plugin shuts down.
---
--- When zoning, this is called for all spawns in the zone after OnBeginZone is
--- called.
---
---@param self Plugin optionally specify a self plugin
---@param SpawnID number The id of the spawn that was removed
function plugin:OnRemoveSpawn(SpawnID)
	printf("%s::OnRemoveSpawn(%s)", self.name, mq.TLO.Spawn(SpawnID).Name())
end

--- OnAddGroundItem
---
--- This is called each time a ground item is added to a zone (ie, something spawns).
--- It is also called for each existing ground item when a plugin first initializes.
---
--- When zoning, this is called for all ground items in the zone after OnEndZone
--- is called and before OnZoned is called.
---
---@param self Plugin optionally specify a self plugin
---@param NewGroundDropID number The id of the ground item that was added
function plugin:OnAddGroundItem(NewGroundDropID)
	printf("%s::OnAddGroundItem(%d)", self.name, NewGroundDropID)
end

--- OnRemoveGroundItem
---
--- This is called each time a ground item is removed from a zone (ie, something
--- despawns or is picked up). It is NOT called when a plugin shuts down.
---
--- When zoning, this is called for all ground items in the zone after
--- OnBeginZone is called.
---
---@param self Plugin optionally specify a self plugin
---@param GroundDropID number The id of the ground item that was removed
function plugin:OnRemoveGroundItem(GroundDropID)
	printf("%s::OnRemoveGroundItem(%d)", self.name, GroundDropID)
end

--- OnBeginZone
---
--- This is called just after entering a zone line and as the loading screen appears.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnBeginZone()
	printf("%s::OnBeginZone()", self.name)
end

--- OnEndZone
---
--- This is called just after the loading screen, but prior to the zone being fully
--- loaded.
---
--- This should occur before OnAddSpawn and OnAddGroundItem are called. It
--- always occurs before OnZoned is called.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnEndZone()
	printf("%s::OnEndZone()", self.name)
end

--- OnZoned
---
--- This is called after entering a new zone and the zone is considered "loaded."
---
--- It occurs after OnEndZone OnAddSpawn and OnAddGroundItem have
--- been called.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnZoned()
	printf("%s::OnZoned()", self.name)
end

--- OnUpdateImGui
---
--- This is called each time that the ImGui Overlay is rendered. Use this to render
--- and update plugin specific widgets.
---
--- Because this happens extremely frequently, it is recommended to move any actual
--- work to a separate call and use this only for updating the display.
---
---@param self Plugin optionally specify a self plugin
function plugin:OnUpdateImGui()
	if not self.is_open then
		return
	end
	local is_drawn = false
	self.is_open, is_drawn = imgui.Begin("MQPluginTemplate", self.is_open, ImGuiWindowFlags.MenuBar)
	if is_drawn then
		if imgui.BeginMenuBar() then
			imgui.Text("MQPluginTemplate is loaded!")
			imgui.EndMenuBar()
		end
	end
	imgui.End()
end

--- OnMacroStart
---
--- This is called each time a macro starts (ex: /mac somemacro.mac), prior to
--- launching the macro.
---
---@param self Plugin optionally specify a self plugin
---@param Name string The name of the macro that was launched
function plugin:OnMacroStart(Name)
	printf("%s::OnMacroStart(%s)", self.name, Name)
end

--- OnMacroStop
---
--- This is called each time a macro stops (ex: /endmac), after the macro has ended.
---
---@param self Plugin optionally specify a self plugin
---@param Name string The name of the macro that was stopped.
function plugin:OnMacroStop(Name)
	printf("%s::OnMacroStop(%s)", self.name, Name)
end

--- OnLoadPlugin
---
--- This is called each time a plugin is loaded (ex: /plugin someplugin), after the
--- plugin has been loaded and any associated -AutoExec.cfg file has been launched.
--- This means it will be executed after the plugin's InitializePlugin callback.
---
--- This is also called when THIS plugin is loaded, but initialization tasks should
--- still be done in InitializePlugin.
---
---@param self Plugin optionally specify a self plugin
---@param Name string The name of the plugin that was loaded
function plugin:OnLoadPlugin(Name)
	printf("%s::OnLoadPlugin(%s)", self.name, Name)
end

--- OnUnloadPlugin
---
--- This is called each time a plugin is unloaded (ex: /plugin someplugin unload),
--- just prior to the plugin unloading. This means it will be executed prior to that
--- plugin's ShutdownPlugin callback.
---
--- This is also called when THIS plugin is unloaded, but shutdown tasks should still
--- be done in ShutdownPlugin.
---
---@param self Plugin optionally specify a self plugin
---@param Name string The name of the plugin that is to be unloaded
function plugin:OnUnloadPlugin(Name)
	printf("%s::OnUnloadPlugin(%s)", self.name, Name)
end

--- The script must return the constructed plugin object
return plugin
