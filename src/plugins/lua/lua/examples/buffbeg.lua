local mq = require('mq')
local actors = require('actors')

-- some example buffs, for demonstration purposes
local mybuffs = {
    CLR={'Aegolism'},
    DRU={'Protection of the Glades', 'Shield of Blades', 'Spirit of Wolf'},
    SHM={'Riotous Health', 'Focus of Spirit', 'Spirit of Wolf'},
    ENC={'Speed of the Shissar'}
}
mybuffs = mybuffs[mq.TLO.Me.Class.ShortName()]

local buff_queue = {}
local function dobuffs()
    for name, buff in pairs(buff_queue) do
        printf('Casting %s on %s...', buff, name)
        mq.cmdf('/target %s', name)
        mq.delay(5000, function() return mq.TLO.Target.CleanName() == name end)
        if mq.TLO.Target.CleanName() == name then
            mq.cmdf('/cast "%s"', buff)
        end
    end

    buff_queue = {}
end

-- store a list of buffs and who can cast them
local buffers = {}
local function addbuffer(buff, sender)
    printf('Received buffer %s casting %s', sender.character, buff)
    if buff and sender then
        if not buffers[buff] then buffers[buff] = {} end

        if not buffers[buff][sender] then
            buffers[buff][sender] = true
        end
    end
end

-- whenever a buffer disconnects, handle that
local function removebuffer(sender)
    for buff, _ in pairs(buffers) do
        buffers[buff][sender] = nil
    end
end

-- this is then message handler, so handle all messages we expect
-- we are guaranteed that the only messages here we receive are
-- ones that we send, so assume the structure of the message
local actor = actors.register(function (message)
    if message.content.id == 'buffs' and message.sender and mybuffs then
        -- request to send a list of buffs I can cast
        for _, buff in ipairs(mybuffs) do
            message:send({id='announce', buff=buff })
        end
    elseif message.content.id == 'beg' then
        -- request for a buff, send back a reply to indicate we are a valid buffer
        message:reply(0, {})
        buff_queue[message.sender.character] = message.content.buff
    elseif message.content.id == 'announce' then
        -- a buffer has announced themselves, add them to the list
        addbuffer(message.content.buff, message.sender)
    elseif message.content.id == 'drop' then
        -- a buffer has dropped, remove them from the list
        removebuffer(message.sender)
    end
end)

-- buffer login, notify all beggars of available buffs
local function bufferlogin()
    for _, buff in ipairs(mybuffs) do
        -- need to specify the actor here because we're sending to beggars
        -- from the buffer actor but leave it loose so that _all_ beggars
        -- receive this message
        printf('Registering %s on beggars', buff)
        actor:send({id='announce', buff=buff})
    end
end

-- beggar login, request buffer buffs
local function beggarlogin()
    actor:send({id='buffs'})
end

-- beggar buff request, choose from local list of buffers
local function checkbuffs()
    for buff, senders in pairs(buffers) do
        if not mq.TLO.Me.Buff(buff)() then
            -- get a random buffer that can cast the buff we want
            local candidates = {}
            for buffer, _ in pairs(senders) do
                table.insert(candidates, buffer)
            end

            -- once we have the random buffer, ask them to cast the buff
            local random_buffer = candidates[math.random(#candidates)]
            if random_buffer then
                printf('Requesting %s from %s...', buff, random_buffer.character)
                actor:send(random_buffer, {id='beg', buff=buff}, function (status, message)
                    -- we have a reply here so that we can remove any buffers that didn't
                    -- clean up nicely (by calling /stopbuffbeg)
                    if status < 0 then removebuffer(random_buffer) end
                end)
            end
        end
    end
end

if mybuffs then bufferlogin() end
mq.delay(100)
beggarlogin()

-- we want to cleanup nicely so that all beggars know that we are done buffing
local runscript = true
mq.bind('/stopbuffbeg', function () runscript = false end)

while runscript do
    checkbuffs()
    dobuffs()
    mq.delay(1000)
end

actor:send({id='drop'})
