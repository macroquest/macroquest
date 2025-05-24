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

// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#if !defined(NOMINMAX)
#define NOMINMAX
#endif
#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif

 // targeting Windows 7+
#if defined(_WIN32_WINNT)
#undef _WIN32_WINNT
#endif
#define  _WIN32_WINNT          0x0601
#if defined(WINVER)
#undef WINVER
#endif
#define WINVER                 0x0601

#include "eqlib/EQLib.h"

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <filesystem>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <string_view>
#include <string>
#include <unordered_map>
#include <vector>

// Windows Header Files:
#include <windows.h>
#include <direct.h>
#include <fcntl.h>
#include <io.h>
#include <mmsystem.h>
#include <Shellapi.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctime>
#include <winsock.h>

#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

