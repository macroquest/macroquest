#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2PetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPAWNINFO* pSpawn = reinterpret_cast<SPAWNINFO*>(VarPtr.Ptr);
	if (!pSpawn)
		return false;

	MQTypeMember* pMember = MQ2PetType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;

		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	if (!pPetInfoWnd)
		return false;

	switch (static_cast<PetMembers>(pMember->ID))
	{
	case Buff:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;

			if (nBuff >= NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			if (Dest.Ptr = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;

			if (nBuff >= NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			Dest.UInt64 = pPetInfoWnd->PetBuffTimer[nBuff];
			return true;
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
					{
						Dest.UInt64 = pPetInfoWnd->PetBuffTimer[nBuff];
						return true;
					}
				}
			}
		}
		return false;

	case Combat:
		Dest.DWord = pSpawn->WhoFollowing != nullptr;
		Dest.Type = pBoolType;
		return true;

	case GHold:
		Dest.DWord = pPetInfoWnd->GHold;
		Dest.Type = pBoolType;
		return true;

	case Hold:
		Dest.DWord = pPetInfoWnd->Hold;
		Dest.Type = pBoolType;
		return true;

	case ReGroup:
		Dest.DWord = pPetInfoWnd->ReGroup;
		Dest.Type = pBoolType;
		return true;

	case Stance:
		if (pPetInfoWnd->Follow)
			strcpy_s(DataTypeTemp, "FOLLOW");
		else
			strcpy_s(DataTypeTemp, "GUARD");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Stop:
		Dest.DWord = pPetInfoWnd->Stop;
		Dest.Type = pBoolType;
		return true;

	case Target:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;

	case Taunt:
		Dest.DWord = pPetInfoWnd->Taunt;
		Dest.Type = pBoolType;
		return true;
	}

	return false;
}

