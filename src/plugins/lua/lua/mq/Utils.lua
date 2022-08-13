Utils = { _version = '1.0', author = 'Knightly' }

Utils.File = {
    -- Need to rely on the OS for this
    Exists = function(path)
            local f=io.open(path,"r")
            if f~=nil then
                io.close(f)
                return true 
            end
            return false
        end,
    Sanitize = function(filename)
            local invalid_chars = {
                '&',
                '|',
                ';',
                '"',
            }
            for order, char in ipairs(invalid_chars) do
                filename = filename:gsub(char, "")
            end
            return filename
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
    Split = function(s, delimiter)
        result = {};
        for match in (s..delimiter):gmatch("(.-)"..delimiter) do
            table.insert(result, match);
        end
        return result;
    end,
}

Utils.URL = {
    Sanitize = function(url)
        local invalid_chars = {
            '"',
        }
        for order, char in ipairs(invalid_chars) do
            url = url:gsub(char, "")
        end
        return url
    end,
}

return Utils