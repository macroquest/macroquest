local PackageMan = { _version = '1.2' }
-- This script uses ImguiHelper which currently relies on mq, so we can bring this in for ease of
-- other functions (like paths)
local mq = require('mq')

-- User facing settings
PackageMan.repoUrl = 'https://luarocks.macroquest.org/'
PackageMan.repoName = 'MacroQuest'
PackageMan.debug = false

-- Requirements
local ImguiHelper = require('mq/ImguiHelper')
local Utils = require('mq/Utils')

-- Internal settings
local jitVersion = Utils.String.Split(jit.version, ' ')[2]
local mqRepoUrl = 'https://luarocks.macroquest.org/' .. jitVersion .. '/'
local mqRepoName = 'MacroQuest'
PackageMan.repoUrl = mqRepoUrl

if PackageMan.debug then
    printf("PackageMan: Using LuaRocks repository '%s'", PackageMan.repoUrl)
end

local cliVersionArg = Utils.String.Split(_VERSION, ' ')[2]
local cliLuarocksPath = mq.TLO.MacroQuest.Path() .. '\\luarocks.exe'
local cliInstallPath = string.format("%s\\%s\\luarocks", mq.TLO.Lua.Dir('modules')(), jitVersion)
local cliCachePath = cliInstallPath .. '\\cache'

-- Exposed functions

-- Returns:
--    0 - success
--    1 - luarocks not installed
--    2 - user said no
--    3 - package install failed
--    4 - no package
--    5 - prompt timed out
--    6 - open process failed
---@param package_name string The package name
---@return integer InstallResult, string ResultMessage
PackageMan.Install = function(package_name)
    if not package_name then return 4, "no package" end

    local callString = 'unknown'
    local callerInfo = debug.getinfo(3,'Sl')
    if callerInfo and callerInfo.short_src ~= nil and callerInfo.short_src ~= '=[C]' then
        callString = callerInfo.short_src:match("[^\\^/]*.lua$")
    end

    if Utils.File.Exists(cliLuarocksPath) then
        local title = PackageMan.repoName
        local text = ''
        PackageMan.repoUrl = Utils.URL.Sanitize(PackageMan.repoUrl)
        package_name = Utils.File.Sanitize(package_name)
        if mqRepoUrl ~= PackageMan.repoUrl then
            text = string.format('***WARNING*** THIS IS NOT SOURCED FROM AN OFFICIAL REPOSITORY.  USE AT YOUR OWN RISK:\n%s\n\n', PackageMan.repoUrl)
            if title == mqRepoName then
                title = 'UNOFFICIAL'
            end
        end
        text = string.format("%sThe script '%s' is asking for package '%s' to be installed on your system from the '%s' repository.\nIf you trust this script, click Install.  Otherwise click Cancel.", text, callString, package_name, PackageMan.repoName)
        title = string.format("LuaRocks Install::%s Repository", title)
        local result = ImguiHelper.Popup.Modal(title, text, { "Install", "Cancel" })
        -- user said no
        if result == 2 then
            return 2, "user said no"
        end
        -- prompt timed out
        if result == 0 then
            return 5, "prompt timed out"
        end

        local execute_string = string.format('"%s" --cache "%s" --lua-version %s --skip-config-warning --only-server "%s" install --deps-mode none --tree "%s" "%s"', cliLuarocksPath, cliCachePath, cliVersionArg, PackageMan.repoUrl, cliInstallPath, package_name)
        if PackageMan.debug then
            print("DEBUG: Executing the following command:")
            print(execute_string)
        end
        local command = string.format('"%s"', execute_string)
        local handle = io.popen(command)
        if handle then
            local result = handle:read("*a")
            handle:close()
            if not string.find(result, "is now installed") then
                if PackageMan.debug then
                    print(result)
                end
                return 3, "package install failed"
            end
        else
            return 6, "open process failed"
        end
    else
        return 1, "luarocks not installed"
    end
    return 0, "success"
end

---@param package_name string The package name from luarocks
---@param require_name? string The package internal export name
---@return nil | any LoadedPackage, string ResultMessage
PackageMan.InstallAndLoad = function(package_name, require_name)
    local message = "no package name specified"
    local result = nil
    if package_name then
        require_name = require_name or package_name
        result, message = PackageMan.Install(package_name)
        if result == 0 then
            return Utils.Library.Include(require_name), message
        end
    end
    return result, message
end

---@param package_name string The package name from luarocks
---@param require_name? string The package internal export name
---@param fail_message? string Override fail message if package fails to load
---@return any
PackageMan.Require = function(package_name, require_name, fail_message)
    require_name = require_name or package_name

    if not fail_message then
        fail_message = "\arFailed to load package " .. package_name
        if require_name ~= package_name then
            fail_message = fail_message .. " with require " .. require_name
        end
    end

    if package_name then
        local my_package = Utils.Library.Include(require_name)
        local result_message = nil
        if not my_package then
            my_package, result_message = PackageMan.InstallAndLoad(package_name, require_name)
        end
        if my_package then
            return my_package
        end
        if result_message then
            fail_message = fail_message .. " :: " .. result_message
        end
    end

    print(fail_message)
    mq.exit()
end

return PackageMan