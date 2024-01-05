/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "mq/base/Common.h"

namespace mq {

/**
 * Returns the minimum class level of the specified spell.
 *
 * @param pSpell The spell
 * @return The minimum class level of the spell.
 */
MQLIB_API int CalcMinSpellLevel(EQ_Spell* pSpell);

} // namespace mq
