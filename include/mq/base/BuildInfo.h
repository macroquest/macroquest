/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

namespace mq {

enum class BuildTarget : int {
	Live = 1,
	Test = 2,
	Beta = 3,
	Emu  = 4
};

inline const char* GetBuildTargetName(BuildTarget id)
{
	switch(id)
	{
		case BuildTarget::Live: return "Live";
		case BuildTarget::Test: return "Test";
		case BuildTarget::Beta: return "Beta";
		case BuildTarget::Emu:  return "Emu";
	}
	return "unknown";
}

}
