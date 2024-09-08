local mq = require 'mq'

LINK_TYPES = {
    [mq.LinkTypes.Item] = 'Item',
    [mq.LinkTypes.Player] = 'Player',
    [mq.LinkTypes.Spam] = 'Spam',
    [mq.LinkTypes.Achievement] = 'Achievement',
    [mq.LinkTypes.Dialog] = 'Dialog',
    [mq.LinkTypes.Command] = 'Command',
    [mq.LinkTypes.Spell] = 'Spell',
    [mq.LinkTypes.Faction] = 'Faction',
}

---@param msg string
local function linkDetector(msg)
    if msg:find('found: ', 1, true) == 1 or msg:find('message: ', 1, true) == 1 then
        return
    end
    local links = mq.ExtractLinks(msg)

    if #links > 0 then
        printf('message: %s', msg)
    end

    for _, link in ipairs(links) do
        local output = string.format('found: %s (%s) - %s', LINK_TYPES[link.type] or 'Unknown', link.type, link.link)

        if link.type == mq.LinkTypes.Spell then
            local spell = mq.ParseSpellLink(link.link)
            output = output .. string.format(": Spell ID %d", spell.spellID)
        elseif link.type == mq.LinkTypes.Item then
            local item = mq.ParseItemLink(link.link)
            output = output .. string.format(": Item ID %d", item.itemID)
        elseif link.type == mq.LinkTypes.Dialog then
            local dialog = mq.ParseDialogLink(link.link)
            output = output .. string.format(": \"%s\"", dialog.text or dialog.keyword)
        end

        print(output)
    end
end

mq.event('linkDetector', '#*#', linkDetector, { keepLinks = true })

while true do
    mq.doevents()
    mq.delay(1000)
end
