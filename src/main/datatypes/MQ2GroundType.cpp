/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

using namespace mq;
using namespace mq::datatypes;

enum class GroundMembers
{
	ID,
	Distance,
	X,
	Y,
	Z,
	Heading,
	Name,
	HeadingTo,
	N,
	W,
	U,
	LineOfSight,
	Address,
	DisplayName,
	Distance3D,
	SubID,
	ZoneID,
	First,
	Last,
	Next,
	Prev
};

enum class GroundMethods
{
	Grab,
	DoTarget,
	DoFace
};

MQ2GroundType::MQ2GroundType() : MQ2Type("ground")
{
	ScopedTypeMember(GroundMembers, ID);
	ScopedTypeMember(GroundMembers, Distance);
	ScopedTypeMember(GroundMembers, X);
	ScopedTypeMember(GroundMembers, Y);
	ScopedTypeMember(GroundMembers, Z);
	ScopedTypeMember(GroundMembers, Heading);
	ScopedTypeMember(GroundMembers, Name);
	ScopedTypeMember(GroundMembers, HeadingTo);
	ScopedTypeMember(GroundMembers, LineOfSight);
	ScopedTypeMember(GroundMembers, Address);
	ScopedTypeMember(GroundMembers, DisplayName);
	ScopedTypeMember(GroundMembers, Distance3D);
	ScopedTypeMember(GroundMembers, SubID);
	ScopedTypeMember(GroundMembers, ZoneID);
	ScopedTypeMember(GroundMembers, First);
	ScopedTypeMember(GroundMembers, Last);
	ScopedTypeMember(GroundMembers, Next);
	ScopedTypeMember(GroundMembers, Prev);

	// methods
	ScopedTypeMethod(GroundMethods, Grab);
	ScopedTypeMethod(GroundMethods, DoTarget);
	ScopedTypeMethod(GroundMethods, DoFace);
}

bool MQ2GroundType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQGroundObject* pGroundObject = static_cast<MQGroundObject*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	if (pGroundObject->Type == GO_None)
		return false;

	SPAWNINFO* pMySpawn = pLocalPlayer;
	SPAWNINFO* pControlledSpawn = pCharSpawn;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2GroundType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<GroundMethods>(pMethod->ID))
		{
		case GroundMethods::Grab: {
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			EQSWITCH* pSwitch = nullptr;

			if (pGroundObject->Type == GO_GroundType)
			{
				pSwitch = pGroundObject->pGroundItem->pSwitch;
			}

			if (pSwitch)
			{
				if (GROUNDITEM* pGround = pGroundObject->pGroundItem)
				{
					char szName[256] = { 0 };
					GetFriendlyNameForGroundItem(pGround, szName, sizeof(szName));

					float dist3d = Get3DDistance(pControlledSpawn->X, pControlledSpawn->Y, pControlledSpawn->Z, pGround->X, pGround->Y, pGround->Z);
					if (dist3d <= 20.0f)
					{
						// FIXME: Do not ZeroMemory SPAWNINFO
						SPAWNINFO tSpawn;
						ZeroMemory(&tSpawn, sizeof(tSpawn));
						strcpy_s(tSpawn.Name, szName);
						strcpy_s(tSpawn.DisplayedName, szName);
						tSpawn.Y = pGround->Y;
						tSpawn.X = pGround->X;
						tSpawn.Z = pGround->pSwitch->Z;
						tSpawn.Type = SPAWN_NPC;
						tSpawn.HPCurrent = 1;
						tSpawn.HPMax = 1;
						tSpawn.Heading = pGround->Heading;
						tSpawn.mActorClient.Race = pGround->DropID;
						tSpawn.StandState = STANDSTATE_STAND; // im using this for /clicked left item -eqmule

						memcpy(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
						pGroundTarget = pGround;

						*((DWORD*)__LMouseHeldTime) = ((CDISPLAY*)pDisplay)->TimeStamp - 0x45;
						pEverQuest->LMouseUp(-10000, -10000);

						ZeroMemory(&EnviroTarget, sizeof(EnviroTarget));
						ZeroMemory(&GroundObject, sizeof(GroundObject));

						pGroundTarget = nullptr;
						Dest.DWord = 1;
						return true;
					}
					else
					{
						MacroError("You are %.2f away from the %s, move within 20 feet of it to Grab it.", dist3d, szName);
					}
				}
			}

			return true;
		}

		case GroundMethods::DoTarget:
		{
			char szName[256] = { 0 };

			// FIXME: Do not ZeroMemory SPAWNINFO
			SPAWNINFO tSpawn;
			ZeroMemory(&tSpawn, sizeof(tSpawn));

			if (pGroundObject->Type == GO_GroundType)
			{
				GetFriendlyNameForGroundItem(pGroundObject->pGroundItem, szName, sizeof(szName));
				tSpawn.Y = pGroundObject->pGroundItem->Y;
				tSpawn.X = pGroundObject->pGroundItem->X;
				tSpawn.Z = pGroundObject->pGroundItem->Z;
				tSpawn.Heading = pGroundObject->pGroundItem->Heading;
				tSpawn.mActorClient.Race = pGroundObject->pGroundItem->DropID;

				pGroundTarget = pGroundObject->pGroundItem;
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGroundTarget;
			}
			else
			{
				if (EQPlacedItem* Placed = static_cast<EQPlacedItem*>(pGroundObject->ObjPtr))
				{
					strcpy_s(szName, Placed->Name);
					tSpawn.Y = Placed->Y;
					tSpawn.X = Placed->X;
					tSpawn.Z = Placed->Z;
					tSpawn.Heading = Placed->Heading;
					tSpawn.mActorClient.Race = Placed->RealEstateItemID;
					GroundObject.Type = GO_ObjectType;
					GroundObject.ObjPtr = Placed;

					GroundObject.GroundItem.DropID = Placed->RealEstateItemID;
					GroundObject.GroundItem.DropSubID = Placed->RealEstateID;
					GroundObject.GroundItem.Expires = 0;
					GroundObject.GroundItem.Heading = Placed->Heading;
					GroundObject.GroundItem.pContents = nullptr;
					strcpy_s(GroundObject.GroundItem.Name, Placed->Name);
					GroundObject.GroundItem.Pitch = Placed->Angle;
					GroundObject.GroundItem.pNext = nullptr;
					GroundObject.GroundItem.pPrev = nullptr;
					GroundObject.GroundItem.pSwitch = reinterpret_cast<EQSWITCH*>(Placed->pActor);
					GroundObject.GroundItem.Roll = Placed->Roll;
					GroundObject.GroundItem.Scale = Placed->Scale;
					GroundObject.GroundItem.Weight = 0;
					GroundObject.GroundItem.X = Placed->X;
					GroundObject.GroundItem.Y = Placed->Y;
					GroundObject.GroundItem.Z = Placed->Z;
					GroundObject.GroundItem.ZoneID = pMySpawn->GetZoneID() & 0x7FFF;
					pGroundTarget = &GroundObject.GroundItem;
				}
			}

			strcpy_s(tSpawn.Name, szName);
			strcpy_s(tSpawn.DisplayedName, szName);
			tSpawn.Type = SPAWN_NPC;
			tSpawn.HPCurrent = 1;
			tSpawn.HPMax = 1;
			tSpawn.StandState = STANDSTATE_STAND; // im using this for /clicked left item -eqmule
			memcpy(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
			Dest.Ptr = pGroundObject;
			Dest.Type = pGroundType;
			return true;
		}

		case GroundMethods::DoFace: {
			float theDistance = 100000.0f;

			if (pGroundObject->Type == GO_GroundType)
			{
				gFaceAngle = atan2(
					pGroundObject->pGroundItem->X - pControlledSpawn->X,
					pGroundObject->pGroundItem->Y - pControlledSpawn->Y) * 256.0f / PI;

				theDistance = Get3DDistance(
					pControlledSpawn->X,
					pControlledSpawn->Y,
					pControlledSpawn->Z,
					pGroundObject->pGroundItem->X,
					pGroundObject->pGroundItem->Y,
					pGroundObject->pGroundItem->Z);

				gLookAngle = atan2(
					pGroundObject->pGroundItem->Z - pControlledSpawn->Z - pControlledSpawn->AvatarHeight * StateHeightMultiplier(pControlledSpawn->StandState),
					static_cast<float>(theDistance)) * 256.0f / PI;
			}
			else
			{
				if (EQPlacedItem* Placed = reinterpret_cast<EQPlacedItem*>(pGroundObject->ObjPtr))
				{
					gFaceAngle = atan2(
						Placed->X - pControlledSpawn->X,
						Placed->Y - pControlledSpawn->Y) * 256.0f / PI;

					theDistance = Get3DDistance(
						pControlledSpawn->X,
						pControlledSpawn->Y,
						pControlledSpawn->Z,
						Placed->X,
						Placed->Y,
						Placed->Z);

					gLookAngle = atan2(Placed->Z - pControlledSpawn->Z - pControlledSpawn->AvatarHeight * StateHeightMultiplier(pControlledSpawn->StandState),
						static_cast<float>(theDistance)) * 256.0f / PI;
				}
			}

			if (gFaceAngle >= 512.0f)
				gFaceAngle -= 512.0f;
			if (gFaceAngle < 0.0f)
				gFaceAngle += 512.0f;

			Dest.Ptr = pGroundObject;
			Dest.Type = pGroundType;
			return true;
		}

		}

		return false;
	}

	//----------------------------------------------------------------------------
	// member

	MQTypeMember* pMember = MQ2GroundType::FindMember(Member);
	if (!pMember)
		return false;

	if (pGroundObject->Type == GO_GroundType)
	{
		GROUNDITEM* pGround = pGroundObject->pGroundItem;
		switch (static_cast<GroundMembers>(pMember->ID))
		{
		case GroundMembers::Address:
			Dest.DWord = (DWORD)VarPtr.Ptr;
			Dest.Type = pIntType;
			return true;

		case GroundMembers::ID:
			Dest.DWord = pGround->DropID;
			Dest.Type = pIntType;
			return true;

		case GroundMembers::SubID:
			Dest.DWord = pGround->DropSubID;
			Dest.Type = pIntType;
			return true;

		case GroundMembers::ZoneID:
			Dest.DWord = (pGround->ZoneID & 0x7FFF);
			Dest.Type = pIntType;
			return true;

		case GroundMembers::W:
		case GroundMembers::X:
			Dest.Float = pGround->X;
			Dest.Type = pFloatType;
			return true;

		case GroundMembers::N:
		case GroundMembers::Y:
			Dest.Float = pGround->Y;
			Dest.Type = pFloatType;
			return true;

		case GroundMembers::U:
		case GroundMembers::Z:
			Dest.Float = pGround->Z;
			Dest.Type = pFloatType;
			return true;

		case GroundMembers::Name:
			strcpy_s(DataTypeTemp, pGround->Name);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case GroundMembers::DisplayName: {
			DataTypeTemp[0] = '\0';
			GetFriendlyNameForGroundItem(pGround, DataTypeTemp, sizeof(DataTypeTemp));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}

		case GroundMembers::Heading:
			Dest.Float = pGround->Heading * 0.703125f;
			Dest.Type = pHeadingType;
			return true;

		case GroundMembers::Distance:
			Dest.Float = GetDistance(pGround->X, pGround->Y);
			Dest.Type = pFloatType;
			return true;
		case GroundMembers::Distance3D: {
			float X = pControlledSpawn->X - pGround->X;
			float Y = pControlledSpawn->Y - pGround->Y;
			float Z = 0;

			if (pGround->pSwitch)
				Z = pControlledSpawn->Z - pGround->pSwitch->Z;
			else
				Z = pControlledSpawn->Z - pGround->Z;

			Dest.Float = sqrtf(X * X + Y * Y + Z * Z);
			Dest.Type = pFloatType;
			return true;
		}

		case GroundMembers::HeadingTo:
			Dest.Float = static_cast<float>(atan2f(
				pControlledSpawn->Y - pGround->Y,
				pGround->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);

			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;

			Dest.Type = pHeadingType;
			return true;

		case GroundMembers::LineOfSight:
			Dest.DWord = CastRay(GetCharInfo()->pSpawn, pGround->Y, pGround->X, pGround->Z);
			Dest.Type = pBoolType;
			return true;

		case GroundMembers::First:
			Dest.Type = pGroundType;

			if (GROUNDITEM* pItem = pGround)
			{
				while (pItem->pPrev)
				{
					pItem = pItem->pPrev;
				}

				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		case GroundMembers::Last:
			Dest.Type = pGroundType;

			if (GROUNDITEM* pItem = pGround)
			{
				while (pItem->pNext)
				{
					pItem = pItem->pNext;
				}

				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		case GroundMembers::Next:
			Dest.Type = pGroundType;
			if (pGround->pNext)
			{
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGround->pNext;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		case GroundMembers::Prev:
			Dest.Type = pGroundType;
			if (pGround->pPrev)
			{
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGround->pPrev;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;

		default: break;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// members

	EQPlacedItem* pGround = (EQPlacedItem*)pGroundObject->ObjPtr;

	switch (static_cast<GroundMembers>(pMember->ID))
	{
	case GroundMembers::Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case GroundMembers::ID:
		Dest.DWord = pGround->RealEstateItemID;
		Dest.Type = pIntType;
		return true;

	case GroundMembers::SubID:
		Dest.DWord = pGround->RealEstateID;
		Dest.Type = pIntType;
		return true;

	case GroundMembers::ZoneID:
		Dest.DWord = pMySpawn->GetZoneID() & 0x7FFF;
		Dest.Type = pIntType;
		return true;

	case GroundMembers::W:
	case GroundMembers::X:
		Dest.Float = pGround->X;
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::N:
	case GroundMembers::Y:
		Dest.Float = pGround->Y;
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::U:
	case GroundMembers::Z:
		Dest.Float = pGround->Z;
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::Name:
		strcpy_s(DataTypeTemp, pGround->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case GroundMembers::DisplayName: {
		Dest.Type = pStringType;

		RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
		const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pGround->RealEstateID, pGround->RealEstateItemID);
		if (pRealEstateItem)
		{
			if (VePointer<CONTENTS> pCont = pRealEstateItem->Object.pItemBase)
			{
				if (ITEMINFO* pItem = pCont->GetItemDefinition())
				{
					strcpy_s(DataTypeTemp, pItem->Name);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	}

	case GroundMembers::Heading:
		Dest.Float = pGround->Heading * 0.703125f;
		Dest.Type = pHeadingType;
		return true;

	case GroundMembers::Distance:
		Dest.Float = GetDistance(pGround->X, pGround->Y);
		Dest.Type = pFloatType;
		return true;

	case GroundMembers::Distance3D: {
		float X = pControlledSpawn->X - pGround->X;
		float Y = pControlledSpawn->Y - pGround->Y;
		float Z = pControlledSpawn->Z - pGround->Z;
		Dest.Float = sqrtf(X * X + Y * Y + Z * Z);
		Dest.Type = pFloatType;
		return true;
	}
	case GroundMembers::HeadingTo:
		Dest.Float = static_cast<float>(atan2f(
			pControlledSpawn->Y - pGround->Y,
			pGround->X - pControlledSpawn->X) * 180.0f / PI + 90.0f);

		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;

		Dest.Type = pHeadingType;
		return true;

	case GroundMembers::LineOfSight:
		Dest.DWord = CastRay(GetCharInfo()->pSpawn, pGround->Y, pGround->X, pGround->Z);
		Dest.Type = pBoolType;
		return true;

	case GroundMembers::First:
		Dest.Type = pGroundType;
		if (EQPlacedItem* pItem = pGround)
		{
			while (pItem->pPrev)
			{
				pItem = pItem->pPrev;
			}
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pItem;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	case GroundMembers::Last:
		Dest.Type = pGroundType;
		if (EQPlacedItem* pItem = pGround)
		{
			while (pItem->pNext)
			{
				pItem = pItem->pNext;
			}
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pItem;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	case GroundMembers::Next:
		Dest.Type = pGroundType;
		if (pGround->pNext)
		{
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pGround->pNext;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	case GroundMembers::Prev:
		Dest.Type = pGroundType;
		if (pGround->pPrev)
		{
			GroundObject.Type = GO_ObjectType;
			GroundObject.ObjPtr = (void*)pGround->pPrev;
			Dest.Ptr = &GroundObject;
			return true;
		}
		return false;

	default: break;
	}

	return false;
}

bool MQ2GroundType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!VarPtr.Ptr)
		return false;

	MQGroundObject* pObj = static_cast<MQGroundObject*>(VarPtr.Ptr);

	if (pObj->Type == GO_GroundType)
	{
		GetFriendlyNameForGroundItem(pObj->pGroundItem, Destination, MAX_STRING);
		return true;
	}

	if (pObj->Type == GO_ObjectType)
	{
		RealEstateManagerClient& manager = RealEstateManagerClient::Instance();

		if (EQPlacedItem* pPlaced = (EQPlacedItem*)pObj->ObjPtr)
		{
			const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pPlaced->RealEstateID, pPlaced->RealEstateItemID);
			if (pRealEstateItem)
			{
				if (VePointer<CONTENTS> pCont = pRealEstateItem->Object.pItemBase)
				{
					if (ITEMINFO* pItem = pCont->GetItemDefinition())
					{
						strcpy_s(Destination, MAX_STRING, pItem->Name);
						return true;
					}
				}
			}
		}
	}

	return true;
}

bool MQ2GroundType::FromString(MQVarPtr& VarPtr, char* Source)
{
	int id = GetIntFromString(Source, 0);

	EQGroundItem* pGroundItem = pItemList->Top;
	MQGroundObject go;

	while (pGroundItem)
	{
		if (pGroundItem->DropID == id)
		{
			go.pGroundItem = pGroundItem;
			go.Type = GO_GroundType;
			memcpy(VarPtr.Ptr, &go, sizeof(MQGroundObject));
			return true;
		}
		pGroundItem = pGroundItem->pNext;
	}

	// didn't find one, check objects...
	RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
	EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

	if (EQPlacedItem* top = pPIM.Top)
	{
		while (top)
		{
			if (top->RealEstateItemID == id)
			{
				go.ObjPtr = (void*)top;
				go.Type = GO_ObjectType;
				memcpy(VarPtr.Ptr, &go, sizeof(MQGroundObject));
				return true;
			}
			top = top->pNext;
		}
	}

	return false;
}

void MQ2GroundType::InitVariable(MQVarPtr& VarPtr)
{
	VarPtr.Ptr = new MQGroundObject();
}

void MQ2GroundType::FreeVariable(MQVarPtr& VarPtr)
{
	MQGroundObject* pGroundObject = static_cast<MQGroundObject*>(VarPtr.Ptr);
	delete pGroundObject;
}

bool MQ2GroundType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pGroundType)
		return false;

	memcpy(VarPtr.Ptr, Source.Ptr, sizeof(MQGroundObject));
	return true;
}

bool MQ2GroundType::dataGroundItem(const char* szIndex, MQTypeVar& Ret)
{
	SPAWNINFO* pSpawn = (SPAWNINFO*)pCharSpawn;

	// if they did ${Ground[name]}
	if (szIndex[0])
	{
		// holds a list of items stored by distance squared.
		std::map<float, MQGroundObject> itemMap;

		if (IsNumber(szIndex))
		{
			int index = std::max(GetIntFromString(szIndex, 0) - 1, 0);

			if (pItemList && pItemList->Top)
			{
				EQGroundItem* pItem = pItemList->Top;

				while (pItem)
				{
					float X = pSpawn->X - pItem->X;
					float Y = pSpawn->Y - pItem->Y;
					float Z = pSpawn->Z - (pItem->pSwitch ? pItem->pSwitch->Z : pItem->Z);

					float distSq = X * X + Y * Y + Z * Z;

					itemMap[distSq].Type = GO_GroundType;
					itemMap[distSq].pGroundItem = pItem;
					pItem = pItem->pNext;
				}
			}

			// lets see if there are any objects that match as well:
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

			for (EQPlacedItem* pObj = pPIM.Top; pObj != nullptr; pObj = pObj->pNext)
			{
				const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(
					pObj->RealEstateID, pObj->RealEstateItemID);
				if (!pRealEstateItem)
					continue;

				CONTENTS* pCont = pRealEstateItem->Object.pItemBase.get();
				if (!pCont)
					continue;

				ITEMINFO* pItem = pCont->GetItemDefinition();
				if (!pItem)
					continue;

				float X = pSpawn->X - pObj->X;
				float Y = pSpawn->Y - pObj->Y;
				float Z = pSpawn->Z - pObj->Z;

				float distSq = X * X + Y * Y + Z * Z;
				itemMap[distSq].Type = GO_ObjectType;
				itemMap[distSq].ObjPtr = pObj;
			}

			if (index < (int)itemMap.size())
			{
				auto it = itemMap.begin();
				std::advance(it, index);

				if (it != itemMap.end())
				{
					memcpy(&GroundObject, &it->second, sizeof(MQGroundObject));
					Ret.Ptr = &GroundObject;
					Ret.Type = pGroundType;
					return true;
				}
			}

			return false;
		}
		else
		{
			char szName[MAX_STRING] = { 0 };
			if (pItemList && pItemList->Top)
			{
				EQGroundItem* pItem = pItemList->Top;
				while (pItem)
				{
					GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));

					if (ci_find_substr(szName, szIndex) != -1)
					{
						float X = pSpawn->X - pItem->X;
						float Y = pSpawn->Y - pItem->Y;
						float Z = pSpawn->Z - (pItem->pSwitch ? pItem->pSwitch->Z : pItem->Z);

						float distSq = X * X + Y * Y + Z * Z;
						itemMap[distSq].Type = GO_GroundType;
						itemMap[distSq].pGroundItem = pItem;
					}

					pItem = pItem->pNext;
				}
			}

			// lets see if there are any objects that match as well:
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

			for (EQPlacedItem* pObj = pPIM.Top; pObj != nullptr; pObj = pObj->pNext)
			{
				const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(
					pObj->RealEstateID, pObj->RealEstateItemID);
				if (!pRealEstateItem)
					continue;

				CONTENTS* pCont = pRealEstateItem->Object.pItemBase.get();
				if (!pCont)
					continue;

				ITEMINFO* pItem = pCont->GetItemDefinition();
				if (!pItem)
					continue;

				if (ci_find_substr(pItem->Name, szIndex) != -1)
				{
					float X = pSpawn->X - pObj->X;
					float Y = pSpawn->Y - pObj->Y;
					float Z = pSpawn->Z - pObj->Z;

					float distSq = X * X + Y * Y + Z * Z;
					itemMap[distSq].Type = GO_ObjectType;
					itemMap[distSq].ObjPtr = pObj;
				}
			}
		}

		// we got some objects return the closest
		if (!itemMap.empty())
		{
			// FIXME: Don't copy with memcpy
			memcpy(&GroundObject, &itemMap.begin()->second, sizeof(MQGroundObject));
			Ret.Ptr = &GroundObject;
			Ret.Type = pGroundType;
			return true;
		}
	}
	else if (GroundObject.Type != GO_None) // they already did /itemtarget so return that.
	{
		Ret.Ptr = &GroundObject;
		Ret.Type = pGroundType;
		return true;
	}

	// well they didn't specify a name and they have not done /itemtarget
	// so we just return first closest entry found
	float groundDist = 100000.0f;
	float objectDist = 100000.0f;

	if (EQGroundItem* pItem = pItemList->Top)
	{
		float X = pSpawn->X - pItem->X;
		float Y = pSpawn->Y - pItem->Y;
		float Z = pSpawn->Z - (pItem->pSwitch ? pItem->pSwitch->Z : pItem->Z);

		groundDist = sqrtf(X * X + Y * Y + Z * Z);
		GroundObject.pGroundItem = pItem;
		GroundObject.Type = GO_GroundType;
	}

	EQPlacedItemManager& pPIM = EQPlacedItemManager::Instance();

	if (EQPlacedItem* top = pPIM.Top)
	{
		float X = pSpawn->X - top->X;
		float Y = pSpawn->Y - top->Y;
		float Z = pSpawn->Z - top->Z;

		objectDist = sqrtf(X * X + Y * Y + Z * Z);
		GroundObject.ObjPtr = (void*)top;
		GroundObject.Type = GO_ObjectType;
	}

	if (GroundObject.Type != GO_None)
	{
		GroundObject.Type = objectDist > groundDist ? GO_GroundType : GO_ObjectType;

		Ret.Ptr = &GroundObject;
		Ret.Type = pGroundType;
		return true;
	}

	return false;
}

bool MQ2GroundType::dataGroundItemCount(const char* szIndex, MQTypeVar& Ret)
{
	Ret.DWord = 0;
	Ret.Type = pIntType;
	if (!pItemList)
		return true;

	EQGroundItem* pItem = pItemList->Top;
	if (!pItem)
		return true;

	int Count = 0;

	if (szIndex[0])
	{
		char szName[MAX_STRING] = { 0 };
		while (pItem)
		{
			GetFriendlyNameForGroundItem(pItem, szName, sizeof(szName));

			if (ci_find_substr(szName, szIndex) != -1)
			{
				Count++;
			}

			pItem = pItem->pNext;
		}

		Ret.DWord = Count;
	}
	else
	{
		while (pItem)
		{
			Count++;
			pItem = pItem->pNext;
		}

		Ret.DWord = Count;
	}

	return true;
}

