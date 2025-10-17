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

#include "mq/base/Common.h"
#include "eqlib/game/Achievements.h"

namespace mq {

// Look up an achievement by name.
MQLIB_API const eqlib::Achievement* GetAchievementByName(std::string_view name);

// Look up an achievement by its id.
MQLIB_API const eqlib::Achievement* GetAchievementById(int id);

// Check if an achievement is completed
MQLIB_API bool IsAchievementComplete(const eqlib::Achievement* achievement);

// Get an achievement component by its description
MQLIB_API const eqlib::AchievementComponent* GetAchievementComponentByDescription(const eqlib::Achievement* achievement, std::string_view description);

// Get an achievement component by id
MQLIB_API const eqlib::AchievementComponent* GetAchievementComponentById(const eqlib::Achievement* achievement, int componentId);

// Check if an achievement component is completed
MQLIB_API bool IsAchievementComponentComplete(const eqlib::Achievement* achievement, const eqlib::AchievementComponent* component);

} // namespace mq

