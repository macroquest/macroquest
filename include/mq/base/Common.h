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

#include "mq/base/Base.h"

#include <cstdint>

#if defined(MQ_NO_EXPORTS) || defined(MQLIB_STATIC)
#define MQLIB_API extern "C"
#define MQLIB_VAR extern "C"
#define MQLIB_OBJECT
#elif defined(MQ2MAIN_EXPORTS)
#define MQLIB_API extern "C" __declspec(dllexport)
#define MQLIB_VAR extern "C" __declspec(dllexport)
#define MQLIB_OBJECT __declspec(dllexport)
#else
#define MQLIB_API extern "C" __declspec(dllimport)
#define MQLIB_VAR extern "C" __declspec(dllimport)
#define MQLIB_OBJECT __declspec(dllimport)
#endif
