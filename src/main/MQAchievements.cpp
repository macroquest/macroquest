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

#include "pch.h"

#include "mq/base/String.h"
#include "mq/api/Achievements.h"

using namespace eqlib;

namespace mq {

static std::unordered_map<const eqlib::Achievement*, int> pointerToIndexMap;

// These are ordered by most likely to least likely
static eqlib::AchievementComponentType validComponentTypes[] = {
	eqlib::AchievementComponentCompletion,
	eqlib::AchievementComponentIndirect,
	eqlib::AchievementComponentUnlock,
	eqlib::AchievementComponentDisplay,
};

static int GetAchievementIndexFromAchievement(const eqlib::Achievement* achievement)
{
	if (!achievement) return -1;

	// Achievement array doesn't change over the duration of the session.

	auto iter = pointerToIndexMap.find(achievement);
	if (iter != pointerToIndexMap.end())
		return iter->second;

	eqlib::AchievementManager& mgr = eqlib::AchievementManager::Instance();
	auto [iter2, created] = pointerToIndexMap.emplace(achievement, mgr.GetAchievementIndexById(achievement->id));

	return iter2->second;
}

const eqlib::Achievement* GetAchievementByName(std::string_view name)
{
	eqlib::AchievementManager& mgr = eqlib::AchievementManager::Instance();
	const eqlib::Achievement* achievement = nullptr;

	int index = mgr.GetAchievementIndexByName(name);
	if (index >= 0)
	{
		achievement = mgr.GetAchievementByIndex(index);
		pointerToIndexMap.emplace(achievement, index);
	}

	return achievement;
}

const eqlib::Achievement* GetAchievementById(int id)
{
	eqlib::AchievementManager& mgr = eqlib::AchievementManager::Instance();
	const eqlib::Achievement* achievement = nullptr;

	int index = mgr.GetAchievementIndexById(id);
	if (index >= 0)
	{
		achievement = mgr.GetAchievementByIndex(index);
		pointerToIndexMap.emplace(achievement, index);
	}

	return achievement;
}

// Check if an achievement is completed
bool IsAchievementComplete(const eqlib::Achievement* achievement)
{
	int index = GetAchievementIndexFromAchievement(achievement);

	if (index >= 0)
	{
		eqlib::AchievementManager& mgr = eqlib::AchievementManager::Instance();

		const eqlib::SingleAchievementAndComponentsInfo* clientInfo = mgr.GetAchievementClientInfoByIndex(index);
		if (clientInfo)
		{
			return clientInfo->achievementState == eqlib::AchievementComplete;
		}
	}

	return false;
}

// Get an achievement component by its description
const eqlib::AchievementComponent* GetAchievementComponentByDescription(const eqlib::Achievement* achievement, std::string_view description)
{
	if (!achievement) return nullptr;

	for (eqlib::AchievementComponentType componentType : validComponentTypes)
	{
		for (const eqlib::AchievementComponent& component : achievement->componentsByType[componentType])
		{
			if (mq::ci_equals(component.description, description))
				return &component;
		}
	}

	return nullptr;
}

// Get an achievement component by id
const eqlib::AchievementComponent* GetAchievementComponentById(const eqlib::Achievement* achievement, int componentId)
{
	if (!achievement) return nullptr;

	for (eqlib::AchievementComponentType componentType : validComponentTypes)
	{
		for (const eqlib::AchievementComponent& component : achievement->componentsByType[componentType])
		{
			if (component.id == componentId)
				return &component;
		}
	}

	return nullptr;
}

// Check if an achievement component is completed
bool IsAchievementComponentComplete(const eqlib::Achievement* achievement, const eqlib::AchievementComponent* component)
{
	if (!achievement || !component) return false;

	int achievementIndex = GetAchievementIndexFromAchievement(achievement);
	int componentIndex = achievement->GetComponentIndexById(component->type, component->id);

	if (componentIndex >= 0)
	{
		eqlib::AchievementManager& mgr = eqlib::AchievementManager::Instance();
		const eqlib::SingleAchievementAndComponentsInfo* clientInfo = mgr.GetAchievementClientInfoByIndex(achievementIndex);
		if (clientInfo)
		{
			return clientInfo->IsComponentComplete(component->type, componentIndex);
		}
	}

	return false;
}

} // namespace mq
