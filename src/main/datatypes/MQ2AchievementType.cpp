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
#include "MQ2DataTypes.h"

namespace mq::datatypes {


//============================================================================

enum class AchievementManagerTypeMembers
{
	Achievement,
	AchievementByIndex,
	AchievementCount,
	Category,
	CategoryByIndex,
	CategoryCount,
	Points,
	CompletedAchievements,
	TotalAchievements,
	Ready,
};

MQ2AchievementManagerType::MQ2AchievementManagerType() : MQ2Type("achievementmgr")
{
	ScopedTypeMember(AchievementManagerTypeMembers, Achievement);
	ScopedTypeMember(AchievementManagerTypeMembers, AchievementByIndex);
	ScopedTypeMember(AchievementManagerTypeMembers, AchievementCount);
	ScopedTypeMember(AchievementManagerTypeMembers, Category);
	ScopedTypeMember(AchievementManagerTypeMembers, CategoryByIndex);
	ScopedTypeMember(AchievementManagerTypeMembers, CategoryCount);
	ScopedTypeMember(AchievementManagerTypeMembers, Points);
	ScopedTypeMember(AchievementManagerTypeMembers, CompletedAchievements);
	ScopedTypeMember(AchievementManagerTypeMembers, TotalAchievements);
	ScopedTypeMember(AchievementManagerTypeMembers, Ready);
}

bool MQ2AchievementManagerType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	AchievementManager& mgr = AchievementManager::Instance();

	switch (static_cast<AchievementManagerTypeMembers>(pMember->ID))
	{
	case AchievementManagerTypeMembers::Achievement:
		Dest.Int = -1; // invalid index
		Dest.Type = pAchievementType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				Dest.Int = mgr.GetAchievementIndexById(GetIntFromString(Index, -1));
			}
			else
			{
				Dest.Int = mgr.GetAchievementIndexByName(Index);
			}
		}
		return true;

	case AchievementManagerTypeMembers::AchievementByIndex:
		Dest.Int = -1;
		Dest.Type = pAchievementType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index >= 0 && index < mgr.GetAchievementCount())
			{
				Dest.Int = index;
			}
		}
		return true;

	case AchievementManagerTypeMembers::AchievementCount:
		Dest.Type = pIntType;
		Dest.Int = mgr.GetAchievementCount();
		return true;

	case AchievementManagerTypeMembers::Category:
		Dest.Int = -1; // invalid index
		Dest.Type = pAchievementCategoryType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				Dest.Int = mgr.GetAchievementCategoryIndexById(GetIntFromString(Index, -1));
			}
			else
			{
				Dest.Int = mgr.GetAchievementCategoryIndexByName(Index);
			}
		}
		return true;

	case AchievementManagerTypeMembers::CategoryByIndex:
		Dest.Int = -1;
		Dest.Type = pAchievementCategoryType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index >= 0 && index < mgr.GetAchievementCategoryCount())
			{
				Dest.Int = index;
			}
		}
		return true;

	case AchievementManagerTypeMembers::CategoryCount:
		Dest.Type = pIntType;
		Dest.Int = mgr.GetAchievementCategoryCount();
		return true;

	case AchievementManagerTypeMembers::Points:
		Dest.Type = pIntType;
		Dest.Int = mgr.completedAchievementScore;
		return true;

	case AchievementManagerTypeMembers::CompletedAchievements:
		Dest.Type = pIntType;
		Dest.Int = mgr.completedAchievementCount;
		return true;

	case AchievementManagerTypeMembers::TotalAchievements:
		Dest.Type = pIntType;
		Dest.Int = mgr.completedAchievementCount + mgr.lockedAchievemmentCount + mgr.openAchievementCount;
		return true;

	case AchievementManagerTypeMembers::Ready:
		Dest.Type = pBoolType;
		Dest.Set(mgr.achievementClientReadOnlyDataSet && mgr.achievementClientStatesSet);
		return true;

	default: break;
	}

	return false;
}

bool MQ2AchievementManagerType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, "Achievements");
	return true;
}

bool MQ2AchievementManagerType::dataAchievement(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		AchievementManager& mgr = AchievementManager::Instance();

		Ret.Type = pAchievementType;

		// If an index is provided we are looking up an achievement by id or name.
		if (IsNumber(szIndex))
		{
			Ret.Int = mgr.GetAchievementIndexById(GetIntFromString(szIndex, -1));
		}
		else
		{
			Ret.Int = mgr.GetAchievementIndexByName(szIndex);
		}
		return true;
	}

	// If no index is provided then we're utilizing the achievement manager type
	Ret.Type = pAchievementManagerType;
	return true;
}

//============================================================================

enum class AchievementTypeMembers
{
	ID,
	Name,
	Description,
	Points,
	Objective,
	ObjectiveByIndex,
	ObjectiveCount,
	Link,
	Index,
	IconID,
	State,
	Completed,
	Open,
	Locked,
	Hidden,
	CompletedTime,
};

enum class AchievementTypeMethods
{
	Inspect,
};

MQ2AchievementType::MQ2AchievementType() : MQ2Type("achievement")
{
	ScopedTypeMember(AchievementTypeMembers, ID);
	ScopedTypeMember(AchievementTypeMembers, Name);
	ScopedTypeMember(AchievementTypeMembers, Description);
	ScopedTypeMember(AchievementTypeMembers, Points);
	ScopedTypeMember(AchievementTypeMembers, Objective);
	ScopedTypeMember(AchievementTypeMembers, ObjectiveByIndex);
	ScopedTypeMember(AchievementTypeMembers, ObjectiveCount);
	ScopedTypeMember(AchievementTypeMembers, Link);
	ScopedTypeMember(AchievementTypeMembers, Index);
	ScopedTypeMember(AchievementTypeMembers, IconID);
	ScopedTypeMember(AchievementTypeMembers, State);
	ScopedTypeMember(AchievementTypeMembers, Completed);
	ScopedTypeMember(AchievementTypeMembers, Open);
	ScopedTypeMember(AchievementTypeMembers, Locked);
	ScopedTypeMember(AchievementTypeMembers, Hidden);
	ScopedTypeMember(AchievementTypeMembers, CompletedTime);
	ScopedTypeMethod(AchievementTypeMethods, Inspect);
}

bool MQ2AchievementType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	AchievementManager& mgr = AchievementManager::Instance();

	int achievementIndex = VarPtr.Int;
	const eqlib::Achievement* achievement = mgr.GetAchievementByIndex(VarPtr.Int);
	if (!achievement)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
	{
		MQTypeMember* pMethod = FindMethod(Member);
		if (pMethod)
		{
			switch (static_cast<AchievementTypeMethods>(pMethod->ID))
			{
			case AchievementTypeMethods::Inspect:
			{
				char buffer[512] = { 0 };
				FormatAchievementLink(buffer, 512, achievement, Index[0] ? Index : pLocalPC->Name);
				TextTagInfo info = ExtractLink(buffer);
				ExecuteTextLink(info);
				return true;
			}
			default:
				return false;
			}
		}

		return false;
	}

	switch (static_cast<AchievementTypeMembers>(pMember->ID))
	{
	case AchievementTypeMembers::ID:
		Dest.Int = achievement->id;
		Dest.Type = pIntType;
		return true;

	case AchievementTypeMembers::Name:
		strcpy_s(DataTypeTemp, achievement->name.c_str());
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case AchievementTypeMembers::Description:
		strcpy_s(DataTypeTemp, achievement->description.c_str());
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;
		
	case AchievementTypeMembers::Points:
		Dest.Int = achievement->points;
		Dest.Type = pIntType;
		return true;

	case AchievementTypeMembers::Objective:
		// Init with invalid component index
		Dest.LowPart = achievementIndex;
		Dest.HighPart = 0;
		Dest.Type = pAchievementObjectiveType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int componentId = GetIntFromString(Index, -1);
				if (componentId >= 0)
				{
					Dest.HighPart = (uint32_t)componentId;
				}
			}
			else
			{
				for (int componentType = AchievementComponentUnlock; componentType < AchievementComponentCount; ++componentType)
				{
					for (const AchievementComponent& component : achievement->componentsByType[componentType])
					{
						if (ci_equals(component.description, Index))
						{
							Dest.HighPart = (uint32_t)component.id;
							break;
						}
					}
				}
			}
		}
		return true;

	case AchievementTypeMembers::ObjectiveByIndex:
		// Init with invalid component id
		Dest.LowPart = achievementIndex;
		Dest.HighPart = 0;
		Dest.Type = pAchievementObjectiveType;

		if (Index[0])
		{
			int componentIndex = GetIntFromString(Index, 0);
			if (componentIndex >= 0)
			{
				AchievementState state = mgr.GetAchievementStateByIndex(achievementIndex);

				// This uses the visual sequence num.
				if (state == AchievementLocked)
				{
					for (int index = 0; index < achievement->componentsByType[AchievementComponentUnlock].GetCount(); ++index)
					{
						if (achievement->componentsByType[AchievementComponentUnlock][index].sequenceNum == componentIndex)
						{
							Dest.HighPart = achievement->componentsByType[AchievementComponentUnlock][index].id;
							return true;
						}
					}
				}
				else
				{
					for (int index = 0; index < achievement->componentsByType[AchievementComponentCompletion].GetCount(); ++index)
					{
						if (achievement->componentsByType[AchievementComponentCompletion][index].sequenceNum == componentIndex)
						{
							Dest.HighPart = achievement->componentsByType[AchievementComponentCompletion][index].id;
							return true;
						}
					}

					for (int index = 0; index < achievement->componentsByType[AchievementComponentIndirect].GetCount(); ++index)
					{
						if (achievement->componentsByType[AchievementComponentIndirect][index].sequenceNum == componentIndex)
						{
							Dest.HighPart = achievement->componentsByType[AchievementComponentIndirect][index].id;
							return true;
						}
					}
				}
			}
		}
		return true;

	case AchievementTypeMembers::ObjectiveCount:
		Dest.Int = mgr.GetAchievementStateByIndex(achievementIndex) == AchievementLocked
			? achievement->componentsByType[AchievementComponentUnlock].GetCount()
			: (achievement->componentsByType[AchievementComponentCompletion].GetCount() + achievement->componentsByType[AchievementComponentIndirect].GetCount());
		Dest.Type = pIntType;
		return true;

	case AchievementTypeMembers::Link:
		FormatAchievementLink(DataTypeTemp, DataTypeTemp.size(), achievement, Index[0] ? Index : pLocalPC->Name);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case AchievementTypeMembers::IconID:
		Dest.Int = achievement->iconId;
		Dest.Type = pIntType;
		return true;

	case AchievementTypeMembers::Index:
		Dest.Int = achievementIndex + 1;
		Dest.Type = pIntType;
		return true;

	case AchievementTypeMembers::State:
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;

		switch (mgr.GetAchievementStateByIndex(achievementIndex))
		{
		case AchievementOpen: strcpy_s(DataTypeTemp, "OPEN"); break;
		case AchievementComplete: strcpy_s(DataTypeTemp, "COMPLETED"); break;
		case AchievementLocked: strcpy_s(DataTypeTemp, "LOCKED"); break;
		case AchievementNotVisible: strcpy_s(DataTypeTemp, "HIDDEN"); break;
		default: strcpy_s(DataTypeTemp, "NONE"); break;
		}
		return true;;

	case AchievementTypeMembers::Completed: {
		AchievementState state = mgr.GetAchievementStateByIndex(achievementIndex);
		Dest.Set(state == AchievementComplete);
		Dest.Type = pBoolType;
		return true;
	}

	case AchievementTypeMembers::Open: {
		AchievementState state = mgr.GetAchievementStateByIndex(achievementIndex);
		Dest.Set(state == AchievementOpen);
		Dest.Type = pBoolType;
		return true;
	}

	case AchievementTypeMembers::Locked: {
		AchievementState state = mgr.GetAchievementStateByIndex(achievementIndex);
		Dest.Set(state == AchievementLocked);
		Dest.Type = pBoolType;
		return true;
	}

	case AchievementTypeMembers::Hidden: {
		AchievementState state = mgr.GetAchievementStateByIndex(achievementIndex);
		Dest.Set(state == AchievementNotVisible);
		Dest.Type = pBoolType;
		return true;
	}

	case AchievementTypeMembers::CompletedTime:
		if (const SingleAchievementAndComponentsInfo* clientInfo = mgr.GetAchievementClientInfoByIndex(achievementIndex))
		{
			if (clientInfo->completionTimestamp != 0)
			{
				Dest = pTimeType->MakeTypeVar(clientInfo->completionTimestamp);
				return true;
			}
		}
		return false;

	default: break;
	}
	return false;
}

bool MQ2AchievementType::ToString(MQVarPtr VarPtr, char* Destination)
{
	const eqlib::Achievement* achievement = GetAchievement(VarPtr);
	if (!achievement)
		return false;
	
	strcpy_s(Destination, MAX_STRING, achievement->name.c_str());
	return true;
}

void MQ2AchievementType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr.Int = -1;
}

bool MQ2AchievementType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pAchievementType)
		return false;

	VarPtr.Int = Source.Int;
	return true;
}

bool MQ2AchievementType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	AchievementManager& mgr = AchievementManager::Instance();

	if (IsNumber(Source))
	{
		VarPtr.Int = mgr.GetAchievementIndexById(GetIntFromString(Source, -1));
	}
	else
	{
		VarPtr.Int = mgr.GetAchievementIndexByName(Source);
	}

	return VarPtr.Int != -1;
}


const Achievement* MQ2AchievementType::GetAchievement(const MQVarPtr& VarPtr)
{
	if (!VarPtr.IsType(MQVarPtr::VariantIdx::UInt64))
		return nullptr;

	AchievementManager& mgr = AchievementManager::Instance();

	return mgr.GetAchievementByIndex(VarPtr.Int);
}

//============================================================================

enum class AchievementCategoryTypeMembers
{
	ID,
	Name,
	Description,
	Achievement,
	AchievementByIndex,
	AchievementCount,
	Category,
	CategoryByIndex,
	CategoryCount,
	Points,
	CompletedAchievements,
	TotalAchievements,
	ImageTextureName,
	Index,
};

MQ2AchievementCategoryType::MQ2AchievementCategoryType() : MQ2Type("achievementcat")
{
	ScopedTypeMember(AchievementCategoryTypeMembers, ID);
	ScopedTypeMember(AchievementCategoryTypeMembers, Name);
	ScopedTypeMember(AchievementCategoryTypeMembers, Description);
	ScopedTypeMember(AchievementCategoryTypeMembers, Achievement);
	ScopedTypeMember(AchievementCategoryTypeMembers, AchievementByIndex);
	ScopedTypeMember(AchievementCategoryTypeMembers, AchievementCount);
	ScopedTypeMember(AchievementCategoryTypeMembers, Category);
	ScopedTypeMember(AchievementCategoryTypeMembers, CategoryByIndex);
	ScopedTypeMember(AchievementCategoryTypeMembers, CategoryCount);
	ScopedTypeMember(AchievementCategoryTypeMembers, Points);
	ScopedTypeMember(AchievementCategoryTypeMembers, CompletedAchievements);
	ScopedTypeMember(AchievementCategoryTypeMembers, TotalAchievements);
	ScopedTypeMember(AchievementCategoryTypeMembers, ImageTextureName);
	ScopedTypeMember(AchievementCategoryTypeMembers, Index);
}

bool MQ2AchievementCategoryType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	AchievementManager& mgr = AchievementManager::Instance();

	int categoryIndex = VarPtr.Int;
	const AchievementCategory* category = mgr.GetAchievementCategoryByIndex(categoryIndex);
	if (!category)
		return false;

	switch (static_cast<AchievementCategoryTypeMembers>(pMember->ID))
	{
	case AchievementCategoryTypeMembers::ID:
		Dest.Int = category->id;
		Dest.Type = pIntType;
		return true;

	case AchievementCategoryTypeMembers::Name:
		strcpy_s(DataTypeTemp, category->name.c_str());
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case AchievementCategoryTypeMembers::Description:
		strcpy_s(DataTypeTemp, category->description.c_str());
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case AchievementCategoryTypeMembers::Achievement:
		Dest.Int = -1; // invalid index
		Dest.Type = pAchievementType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int achievementId = GetIntFromString(Index, -1);

				if (category->HasAchievementId(achievementId))
				{
					Dest.Int = mgr.GetAchievementIndexById(achievementId);
				}
			}
			else
			{
				for (const AchievementInfo& info : category->achievements)
				{
					int achievementIndex = mgr.GetAchievementIndexById(info.achievementId);
					if (achievementIndex >= 0)
					{
						const Achievement* achievement = mgr.GetAchievementByIndex(achievementIndex);
						if (achievement && ci_equals(achievement->name, Index))
						{
							Dest.Int = achievementIndex;
							break;
						}
					}
				}
			}
		}
		return true;

	case AchievementCategoryTypeMembers::AchievementByIndex:
		Dest.Int = -1;
		Dest.Type = pAchievementType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index >= 0 && index < category->GetAchievementCount())
			{
				Dest.Int = mgr.GetAchievementIndexById(category->GetAchievementId(index));
			}
		}
		return true;

	case AchievementCategoryTypeMembers::AchievementCount:
		Dest.Type = pIntType;
		Dest.Int = category->GetAchievementCount();
		return true;

	case AchievementCategoryTypeMembers::Category:
		Dest.Int = -1; // invalid index
		Dest.Type = pAchievementCategoryType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int childCategoryId = GetIntFromString(Index, -1);
				
				for (int index = 0; index < category->GetChildrenCount(); ++index)
				{
					if (category->GetChildCategoryId(index) == childCategoryId)
					{
						Dest.Int = mgr.GetAchievementCategoryIndexById(childCategoryId);
					}
				}
			}
			else
			{
				for (int index = 0; index < category->GetChildrenCount(); ++index)
				{
					int categoryIndex = mgr.GetAchievementCategoryIndexById(category->GetChildCategoryId(index));
					if (const AchievementCategory* childCategory = mgr.GetAchievementCategoryByIndex(categoryIndex))
					{
						if (ci_equals(childCategory->name, Index))
						{
							Dest.Int = categoryIndex;
						}
					}
				}
			}
		}
		return true;

	case AchievementCategoryTypeMembers::CategoryByIndex:
		Dest.Int = -1;
		Dest.Type = pAchievementCategoryType;

		if (Index[0])
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index >= 0 && index < category->GetChildrenCount())
			{
				int childCategoryId = category->GetChildCategoryId(index);
				if (childCategoryId >= 0)
				{
					Dest.Int = mgr.GetAchievementCategoryIndexById(childCategoryId);
				}
			}
		}
		return true;

	case AchievementCategoryTypeMembers::CategoryCount:
		Dest.Type = pIntType;
		Dest.Int = category->GetChildrenCount();
		return true;

	case AchievementCategoryTypeMembers::Points:
		Dest.Int = category->completedAchievementScore;
		Dest.Type = pIntType;
		return true;

	case AchievementCategoryTypeMembers::CompletedAchievements:
		Dest.Int = category->completedAchievementCount;
		Dest.Type = pIntType;
		return true;

	case AchievementCategoryTypeMembers::TotalAchievements:
		Dest.Int = category->completedAchievementCount + category->openAchievementCount + category->lockedAchievementCount;
		Dest.Type = pIntType;
		return true;

	case AchievementCategoryTypeMembers::ImageTextureName:
		strcpy_s(DataTypeTemp, category->bitmapId.c_str());
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case AchievementCategoryTypeMembers::Index:
		Dest.Int = categoryIndex + 1;
		Dest.Type = pIntType;
		return true;

	default: break;
	}
	return false;
}

bool MQ2AchievementCategoryType::ToString(MQVarPtr VarPtr, char* Destination)
{
	AchievementManager& mgr = AchievementManager::Instance();

	int categoryIndex = VarPtr.Int;
	const AchievementCategory* category = mgr.GetAchievementCategoryByIndex(categoryIndex);
	if (!category)
		return false;

	strcpy_s(Destination, MAX_STRING, category->name.c_str());
	return true;
}

bool MQ2AchievementCategoryType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pAchievementCategoryType)
		return false;

	VarPtr.Int = Source.Int;
	return true;
}

//============================================================================

static const AchievementComponent* GetComponent(const MQVarPtr& VarPtr, AchievementComponentType& outType, int& outIndex)
{
	AchievementManager& mgr = AchievementManager::Instance();

	int achievementIndex = VarPtr.LowPart;
	const eqlib::Achievement* achievement = mgr.GetAchievementByIndex(VarPtr.Int);
	if (!achievement)
		return nullptr;

	int componentId = VarPtr.HighPart;
	const eqlib::AchievementComponent* component = nullptr;

	AchievementComponentType types[] = { AchievementComponentCompletion, AchievementComponentIndirect, AchievementComponentUnlock };
	for (AchievementComponentType type : types)
	{
		for (int index = 0; index < achievement->componentsByType[type].GetCount(); ++index)
		{
			if (achievement->componentsByType[type][index].id == componentId)
			{
				outType = type;
				outIndex = index;

				component = &achievement->componentsByType[type][index];
				break;
			}
		}
	}

	return component;
}

enum class AchievementComponentTypeMembers
{
	ID,
	Description,
	Count,
	RequiredCount,
	Completed,
	Index,
};

MQ2AchievementObjectiveType::MQ2AchievementObjectiveType() : MQ2Type("achievementobj")
{
	ScopedTypeMember(AchievementComponentTypeMembers, ID);
	ScopedTypeMember(AchievementComponentTypeMembers, Description);
	ScopedTypeMember(AchievementComponentTypeMembers, Count);
	ScopedTypeMember(AchievementComponentTypeMembers, RequiredCount);
	ScopedTypeMember(AchievementComponentTypeMembers, Completed);
	ScopedTypeMember(AchievementComponentTypeMembers, Index);
}

bool MQ2AchievementObjectiveType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC)
		return false;

	MQTypeMember* pMember = FindMember(Member);
	if (!pMember)
		return false;

	AchievementManager& mgr = AchievementManager::Instance();
	AchievementComponentType componentType;
	int componentIndex;
	int achievementIndex = VarPtr.LowPart;

	const eqlib::AchievementComponent* component = GetComponent(VarPtr, componentType, componentIndex);
	if (!component)
		return false;

	switch (static_cast<AchievementComponentTypeMembers>(pMember->ID))
	{
	case AchievementComponentTypeMembers::ID:
		Dest.Int = component->id;
		Dest.Type = pIntType;
		return true;

	case AchievementComponentTypeMembers::Description:
		strcpy_s(DataTypeTemp, component->description.c_str());
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case AchievementComponentTypeMembers::Count:
		Dest.Int = component->count;
		Dest.Type = pIntType;
		return true;

	case AchievementComponentTypeMembers::RequiredCount:
		Dest.Int = component->requiredCount;
		Dest.Type = pIntType;
		return true;

	case AchievementComponentTypeMembers::Completed: 
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (const SingleAchievementAndComponentsInfo* info = mgr.GetAchievementClientInfoByIndex(achievementIndex))
		{
			Dest.Set(info->IsComponentComplete(componentType, componentIndex));
		}
		return true;

	case AchievementComponentTypeMembers::Index:
		Dest.Int = component->sequenceNum;
		Dest.Type = pIntType;
		return true;

	default: break;
	}
	return false;
}

bool MQ2AchievementObjectiveType::ToString(MQVarPtr VarPtr, char* Destination)
{
	AchievementManager& mgr = AchievementManager::Instance();
	AchievementComponentType componentType;
	int componentIndex;
	int achievementIndex = VarPtr.LowPart;

	const eqlib::AchievementComponent* component = GetComponent(VarPtr, componentType, componentIndex);
	if (!component)
		return false;

	strcpy_s(Destination, MAX_STRING, component->description.c_str());
	return true;
}

bool MQ2AchievementObjectiveType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pAchievementObjectiveType)
		return false;

	VarPtr.LowPart = Source.LowPart;
	VarPtr.HighPart = Source.HighPart;
	return true;
}

} // namespace mq::datatypes
