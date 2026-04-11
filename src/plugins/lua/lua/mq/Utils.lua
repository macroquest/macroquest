local Utils = { _version = '1.0', author = 'Knightly' }

Utils.File = {
    -- Need to rely on the OS for this
    ---@param path string
    ---@return boolean
    Exists = function(path)
            local f=io.open(path,"r")
            if f~=nil then
                io.close(f)
                return true 
            end
            return false
        end,
    ---@param filename string
    ---@return string
    Sanitize = function(filename)
            return filename:gsub("[^%w%-%._]", "")
        end,
}

Utils.Library = {
    Include = function(...)
        local status, lib = pcall(require, ...)
        if(status) then
            return lib
        end
        return nil
    end,
}

Utils.String = {
    ---@param s string
    ---@param delimiter string
    ---@return string[]
    Split = function(s, delimiter)
        local result = {}
        local escaped = delimiter:gsub("([%(%)%.%%%+%-%*%?%[%]%^%$])", "%%%1")
        for match in (s..delimiter):gmatch("(.-)"..escaped) do
            table.insert(result, match)
        end
        return result
    end,
}

Utils.URL = {
    ---@param url string
    ---@return string
    Sanitize = function(url)
        return url:gsub("[^%w%-%._~:/?#%[%]@!%$&'%(%)%*%+,;=%%]", "")
    end,
}

return Utils