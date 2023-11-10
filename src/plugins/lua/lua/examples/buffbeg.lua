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

-- store a list of buffs and who can cast them
local buffers = {}
local function addbuffer(buff, sender)
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

-- these are message handlers, so handle all messages we expect
-- this could be safer if we test the type to be a table, I'll
-- leave that as an exercise for the reader
local buffer
if mybuffs then
    -- only register the buffer actor if we have buffs to give
    buffer = actors.register('buffer', function (message)
        if message.content then
            -- this message is a request to send a list of buffs I can cast
            if message.content.id == 'buffs' and message.sender and mybuffs then
                for _, buff in ipairs(mybuffs) do
                    buffer:send(message.sender, {id='announce', buff=buff})
                end
            -- this message is a request to buff someone else
            elseif message.content.id == 'beg' then
                -- make sure to notify the beggar that we are still here
                message:reply(0, {})
                printf('Casting %s on %s...', message.content.buff, message.content.name)
                mq.cmdf('/target %s', message.content.name)
                mq.delay(5000, function () return mq.TLO.Target.CleanName() == message.content.name end)
                if mq.TLO.Target.CleanName() == message.content.name then
                    mq.cmdf('/cast "%s"', message.content.buff)
                end
            end
        end
    end)
end

-- always register ther beggar actor, everyone can receive buffs
local beggar = actors.register('beggar', function (message)
    -- the message we receive here are simply tracking potential buffers (self included)
    if message.content then
        if message.content.id == 'announce' then
            addbuffer(message.content.buff, message.sender)
        elseif message.content.id == 'drop' then
            removebuffer(message.sender)
        end
    end
end)

-- buffer login, notify all beggars of available buffs
local function bufferlogin()
    for _, buff in ipairs(mybuffs) do
        -- need to specify the actor here because we're sending to beggars
        -- from the buffer actor but leave it loose so that _all_ beggars
        -- receive this message
        buffer:send({mailbox='beggar'}, {id='announce', buff=buff})
    end
end

-- beggar login, request buffer buffs
local function beggarlogin()
    beggar:send({mailbox='buffer'}, {id='buffs'})
end

-- beggar buff request, choose from local list of buffers
local function checkbuffs()
    for buff, senders in pairs(buffers) do
        if not mq.TLO.Me.Buff(buff)() then
            -- get a random buffer that can cast the buff we want
            local buffers = {}
            for buffer, _ in pairs(senders) do
                table.insert(buffers, buffer)
            end

            -- once we have the random buffer, ask them to cast the buff
            local random_buffer = buffers[math.random(#buffers)]
            if random_buffer then
                printf('Requesting %s from %d...', buff, random_buffer.pid)
                beggar:send(random_buffer, {id='beg', buff=buff, name=mq.TLO.Me.CleanName()}, function (status, message)
                    -- we have a reply here so that we can remove any buffers that didn't
                    -- clean up nicely (by calling /stopbuffbeg)
                    if status < 0 then removebuffer(random_buffer) end
                end)
            end
        end
    end
end

if buffer then bufferlogin() end
beggarlogin()

-- we want to cleanup nicely so that all beggars know that we are done buffing
local runscript = true
mq.bind('/stopbuffbeg', function () runscript = false end)

while runscript do
    checkbuffs()
    mq.delay(10000)
end

if buffer then buffer:send({mailbox='beggar'}, {id='drop'}) end