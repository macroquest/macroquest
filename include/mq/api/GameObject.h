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

#include <cstdint>
#include <string>

namespace eqlib {
class CActorInterface;
}

namespace mq {

enum class eGameObjectType {
	None,
	GroundItem,
	PlaceableItem,
	Spawn,
	SpawnTarget,
	Location,
	Switch,
};

// generic structure for storing positional information about an object
struct MQGameObject
{
	eGameObjectType type = eGameObjectType::None;
	uint32_t id = 0;
	uint32_t subId = 0;
	std::string name;

	float y = 0.f;
	float x = 0.f;
	float z = 0.f;
	float heading = 0.f;
	std::string displayName;

	// optional params
	float velocityY = 0.f;
	float velocityX = 0.f;
	float velocityZ = 0.f;
	float height = 0.f;
	eqlib::CActorInterface* actor = nullptr;

	bool valid = false;

	const std::string& GetDisplayName() const
	{
		if (!displayName.empty())
			return displayName;

		return name;
	}
};

} // namespace mq
