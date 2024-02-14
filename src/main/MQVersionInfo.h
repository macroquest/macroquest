/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#define MQMAIN_VERSION_MAJOR 3
#define MQMAIN_VERSION_MINOR 1
#define MQMAIN_VERSION_REV   0
#define MQMAIN_VERSION_BUILD 0

#define MQMAIN_GIT_HASH "nohash"

#define STRINGIFY_MACRO_(x) #x
#define STRINGIFY_MACRO(x) STRINGIFY_MACRO_(x)

#define MQMAIN_VERSION STRINGIFY_MACRO(MQMAIN_VERSION_MAJOR) "." STRINGIFY_MACRO(MQMAIN_VERSION_MINOR) "." STRINGIFY_MACRO(MQMAIN_VERSION_REV) "." STRINGIFY_MACRO(MQMAIN_VERSION_BUILD)
