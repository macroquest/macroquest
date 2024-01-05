-- Example script for how to use PackageMan to load each of the luarocks available on the MQ rocks server.
local PackageMan = require('mq.PackageMan')

-- Storage modules

-- http://lua.sqlite.org/index.cgi/doc/tip/doc/lsqlite3.wiki
local lsqlite3 = PackageMan.Require('lsqlite3')
local lsqlite3complete = PackageMan.Require('lsqlite3complete')

-- https://lunarmodules.github.io/luafilesystem/
-- module name for luafilesystem luarock is lfs
local lfs = PackageMan.Require('luafilesystem', 'lfs')

-- Format modules

-- http://gvvaughan.github.io/lyaml/
local lyaml = PackageMan.Require('lyaml')
-- https://kyne.com.au/~mark/software/lua-cjson-manual.html
-- module name for lua-cjson luarock is cjson
local cjson = PackageMan.Require('lua-cjson', 'cjson')

-- Networking modules

-- https://github.com/lunarmodules/luasec/wiki
-- main module of luasec luarock is ssl
local ssl = PackageMan.Require('luasec', 'ssl')
-- https://lunarmodules.github.io/luasocket/reference.html
-- x86_64 only, main module of luasocket luarock is socket
local socket = PackageMan.Require('luasocket', 'socket')
-- part of socket luarock
local http = require('socket.http')
local itn12 = require('ltn12')
-- part of luasec luarock
local https = require('ssl.https')

-- Other modules

-- https://luafun.github.io/
local fun = PackageMan.Require('fun')
-- http://tieske.github.io/uuid/
local uuid = PackageMan.Require('uuid')