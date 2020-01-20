#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2SpellType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPELL* pSpell = static_cast<SPELL*>(VarPtr.Ptr);
	if (!pSpell)
		return false;

	// FIXME: Remove this!! We shouldn't ever need it!!!
	if (IsBadReadPtr((void*)pSpell, 4))
		return false;

	MQTypeMember* pMember = MQ2SpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SpellMembers>(pMember->ID))
	{
	case ID:
		Dest.DWord = pSpell->ID;
		Dest.Type = pIntType;
		return true;

	case Name:
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;

	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0] && GetCharInfo()->pSpawn)
		{
			Dest.DWord = pSpell->ClassLevel[GetCharInfo()->pSpawn->mActorClient.Class];
			return true;
		}
		else
		{
			if (IsNumber(Index))
			{
				unsigned long nIndex = GetIntFromString(Index, 0);
				Dest.DWord = pSpell->ClassLevel[nIndex];
				return true;
			}
		}
		return false;

	case Mana:
		Dest.DWord = pSpell->ManaCost;
		Dest.Type = pIntType;
		return true;

	case ResistAdj:
		Dest.DWord = pSpell->ResistAdj;
		Dest.Type = pIntType;
		return true;

	case Range:
		Dest.Float = pSpell->Range;
		Dest.Type = pFloatType;
		return true;

	case AERange:
		Dest.Float = pSpell->AERange;
		Dest.Type = pFloatType;
		return true;

	case PushBack:
		Dest.Float = pSpell->PushBack;
		Dest.Type = pFloatType;
		return true;

	case CastTime:
		Dest.UInt64 = pSpell->CastTime;
		Dest.Type = pTimeStampType;
		return true;

	case RecoveryTime:
	case FizzleTime:
		Dest.UInt64 = pSpell->RecoveryTime;
		Dest.Type = pTimeStampType;
		return true;

	case RecastTime:
		Dest.UInt64 = pSpell->RecastTime;
		Dest.Type = pTimeStampType;
		return true;

	case ResistType:
		switch (pSpell->Resist)
		{
		case ResistType_Corruption: strcpy_s(DataTypeTemp, "Corruption"); break;
		case ResistType_Physical:	strcpy_s(DataTypeTemp, "Physical"); break;
		case ResistType_Prismatic: strcpy_s(DataTypeTemp, "Prismatic"); break;
		case ResistType_Chromatic: strcpy_s(DataTypeTemp, "Chromatic"); break;
		case ResistType_Disease: strcpy_s(DataTypeTemp, "Disease"); break;
		case ResistType_Poison: strcpy_s(DataTypeTemp, "Poison"); break;
		case ResistType_Cold: strcpy_s(DataTypeTemp, "Cold"); break;
		case ResistType_Fire: strcpy_s(DataTypeTemp, "Fire"); break;
		case ResistType_Magic: strcpy_s(DataTypeTemp, "Magic"); break;
		case ResistType_None: strcpy_s(DataTypeTemp, "Unresistable"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SpellType:
		switch (pSpell->SpellType)
		{
		case SpellType_BeneficialGroupOnly: strcpy_s(DataTypeTemp, "Beneficial(Group)"); break;
		case SpellType_Beneficial: strcpy_s(DataTypeTemp, "Beneficial"); break;
		case SpellType_Detrimental: strcpy_s(DataTypeTemp, "Detrimental"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case TargetType:
		switch (pSpell->TargetType)
		{
		case 50: strcpy_s(DataTypeTemp, "Target_AE_No_Players_Pets"); break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
		case 52: strcpy_s(DataTypeTemp, "Single Friendly (or Target's Target"); break; // Introduced in Torment of Velious. Spell affects target if friendly, or target's target if the target is an unfriendly.
		case 47: strcpy_s(DataTypeTemp, "Pet Owner"); break;
		case 46: strcpy_s(DataTypeTemp, "Target of Target"); break;
		case 45: strcpy_s(DataTypeTemp, "Free Target"); break;
		case 44: strcpy_s(DataTypeTemp, "Beam"); break;
		case 43: strcpy_s(DataTypeTemp, "Single in Group"); break;
		case 42: strcpy_s(DataTypeTemp, "Directional AE"); break;
		case 41: strcpy_s(DataTypeTemp, "Group v2"); break;
		case 40: strcpy_s(DataTypeTemp, "AE PC v2"); break;
		case 39: strcpy_s(DataTypeTemp, "No Pets"); break;
		case 38: strcpy_s(DataTypeTemp, "Pet2"); break;
		case 37: strcpy_s(DataTypeTemp, "Caster PB NPC"); break;
		case 36: strcpy_s(DataTypeTemp, "Caster PB PC"); break;
		case 35: strcpy_s(DataTypeTemp, "Special Muramites"); break;
		case 34: strcpy_s(DataTypeTemp, "Chest"); break;
		case 33: strcpy_s(DataTypeTemp, "Hatelist2"); break;
		case 32: strcpy_s(DataTypeTemp, "Hatelist"); break;
		case 25: strcpy_s(DataTypeTemp, "AE Summoned"); break;
		case 24: strcpy_s(DataTypeTemp, "AE Undead"); break;
		case 20: strcpy_s(DataTypeTemp, "Targeted AE Tap"); break;
		case 18: strcpy_s(DataTypeTemp, "Uber Dragons"); break;
		case 17: strcpy_s(DataTypeTemp, "Uber Giants"); break;
		case 16: strcpy_s(DataTypeTemp, "Plant"); break;
		case 15: strcpy_s(DataTypeTemp, "Corpse"); break;
		case 14: strcpy_s(DataTypeTemp, "Pet"); break;
		case 13: strcpy_s(DataTypeTemp, "LifeTap"); break;
		case 11: strcpy_s(DataTypeTemp, "Summoned"); break;
		case 10: strcpy_s(DataTypeTemp, "Undead"); break;
		case  9: strcpy_s(DataTypeTemp, "Animal"); break;
		case  8: strcpy_s(DataTypeTemp, "Targeted AE"); break;
		case  6: strcpy_s(DataTypeTemp, "Self"); break;
		case  5: strcpy_s(DataTypeTemp, "Single"); break;
		case  4: strcpy_s(DataTypeTemp, "PB AE"); break;
		case  3: strcpy_s(DataTypeTemp, "Group v1"); break;
		case  2: strcpy_s(DataTypeTemp, "AE PC v1"); break;
		case  1: strcpy_s(DataTypeTemp, "Line of Sight"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Skill:
		strcpy_s(DataTypeTemp, szSkills[pSpell->Skill]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case MyCastTime: {
		int64_t myaacastingtime = (int64_t)GetCastingTimeModifier((EQ_Spell*)pSpell);

		VePointer<CONTENTS> pc;
		int myfocuscastingtime = GetFocusCastingTimeModifier((EQ_Spell*)pSpell, pc, false);

		int64_t mycasttime = (int64_t)pSpell->CastTime;
		int64_t mct = myaacastingtime + myfocuscastingtime + mycasttime;

		if (pSpell->CastTime > 0 && mct < (pSpell->CastTime / 2))
			Dest.UInt64 = pSpell->CastTime / 2;
		else
			Dest.UInt64 = mct;

		Dest.Type = pTimeStampType;
		return true;
	}

	case Duration:
		Dest.DWord = GetSpellDuration(pSpell, (SPAWNINFO*)pLocalPlayer);
		Dest.Type = pTicksType;
		return true;

	case EQSpellDuration:
		Dest.DWord = EQGetSpellDuration(pSpell, NULL, false);
		Dest.Type = pTicksType;
		return true;

	case CastByMe:
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastByMe))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CastByOther:
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastByOther))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CastOnYou:
		strcpy_s(DataTypeTemp, "You feel bogus as an unknown spell accosts you.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastOnYou))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CastOnAnother:
		strcpy_s(DataTypeTemp, " is the victim of an unknown spell.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringCastOnAnother))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WearOff:
		strcpy_s(DataTypeTemp, "An unknown spell is gone.");
		if (const char* str = GetSpellString(pSpell->ID, SpellStringWearOff))
		{
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CounterType:
		strcpy_s(DataTypeTemp, "None");
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
		{
			switch (GetSpellAttrib(pSpell, i))
			{
			case SPA_DISEASE:
				strcpy_s(DataTypeTemp, "Disease");
				break;
			case SPA_POISON:
				strcpy_s(DataTypeTemp, "Poison");
				break;
			case SPA_CURSE:
				strcpy_s(DataTypeTemp, "Curse");
				break;
			case SPA_CORRUPTION:
				strcpy_s(DataTypeTemp, "Corruption");
				break;
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CounterNumber:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
		{
			int attrib = GetSpellAttrib(pSpell, i);

			if (IsSpellCountersSPA(attrib))
			{
				Dest.DWord = GetSpellBase(pSpell, i);
				return true;
			}
		}
		return true;

	case Stacks:
	case NewStacks: // stacks on self
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!pLocalPlayer)
			return false;

		auto pPc = pLocalPlayer->GetPcClient();

		int SlotIndex = -1;
		EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, pLocalPlayer, &SlotIndex, true, pLocalPlayer->Level);

		Dest.DWord = ret &&
			SlotIndex != -1 &&
			GetSpellDuration(pSpell, pLocalPlayer) >= -1 &&
			ret->Duration <= GetIntFromString(Index, 0);

		return true;
	}

	case StacksPet: {
		int duration = 99999;
		duration = GetIntFromString(Index, duration);

		Dest.DWord = true;
		Dest.Type = pBoolType;

		if (!pPetInfoWnd || !pLocalPlayer)
			return false;

		for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
		{
			auto pBuffSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]);
			if (!pBuffSpell)
				continue;

			// if we have less duration than the duration argument, then this "will stack" so we need to keep checking
			if (!WillStackWith(pSpell, pBuffSpell) && (
				GetSpellDuration(pBuffSpell, pLocalPlayer) < -1 ||
				ceil(pPetInfoWnd->PetBuffTimer[nBuff] / 6000) > GetIntFromString(Index, 0)))
			{
				Dest.DWord = false;
				return true;
			}
		}

		return true;
	}

	case WillStack:
	case StacksWith:
	case NewStacksWith: // if a spell stack with another spell
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0] || !pLocalPlayer)
			return false;

		SPELL* tmpSpell = IsNumber(Index) ?
			GetSpellByID(GetIntFromString(Index, 0)) :
			GetSpellByName(Index);

		if (!tmpSpell)
			return false;

		Dest.DWord = WillStackWith(pSpell, tmpSpell);
		return true;
	}

	case StacksSpawn:
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return true;
		if (CachedBuffsMap.empty())
			return true;

		SPAWNINFO* pSpawn = (SPAWNINFO*)(IsNumber(Index) ? GetSpawnByID(GetIntFromString(Index, 0)) : GetSpawnByName(Index));

		if (pSpawn)
		{
			SPAWNINFO* pPlayer = (SPAWNINFO*)pLocalPlayer;
			PcClient* pPc = pSpawn->GetPcClient();
			if (pPc)
			{
				EQ_Affect pAffects[NUM_BUFF_SLOTS];
				int j = 0;

				auto i = CachedBuffsMap.find(pSpawn->SpawnID);
				if (i != CachedBuffsMap.end())
				{
					for (auto k = i->second.begin(); k != i->second.end(); k++)
					{
						if (SPELL* pBuff = GetSpellByID(k->first))
						{
							pAffects[j].Type = 2;
							pAffects[j].SpellID = pBuff->ID;
							pAffects[j].Activatable = 0; // pBuff->Activated;
							pAffects[j].Level = pPlayer->Level;
							pAffects[j].Modifier = 1.0;
							j++;
						}
					}
				}

				int SlotIndex = -1;
				EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, pPlayer, &SlotIndex, true, pPlayer->Level, pAffects, j, false);
				if (!ret || SlotIndex == -1)
					Dest.DWord = false;
				else
					Dest.DWord = true;
			}
		}
		return true;
	}

	case StacksTarget:
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (pLocalPlayer)
		{
			SPAWNINFO* pPlayer = (SPAWNINFO*)pLocalPlayer;
			PcClient* pPc = pPlayer->GetPcClient();
			if (pPc)
			{
				if (pTarget)
				{
					if (CHARINFO* pMe = GetCharInfo())
					{
						EQ_Affect pAffects[NUM_BUFF_SLOTS];
						int j = 0;

						auto i = CachedBuffsMap.find(pTarget->SpawnID);
						if (i != CachedBuffsMap.end())
						{
							// lets grab it from the cache so we get songs as well...
							for (auto& k : i->second)
							{
								if (SPELL* pBuff = GetSpellByID(k.first))
								{
									pAffects[j].Type = 2;
									pAffects[j].SpellID = pBuff->ID;
									pAffects[j].CasterGuid = pMe->Guid;
									pAffects[j].Level = ((SPAWNINFO*)pLocalPlayer)->Level;
									pAffects[j].Modifier = 1.0;
									j++;
								}
							}
						}
						else
						{
							int buffID = 0;
							for (int i = 0; i < NUM_BUFF_SLOTS; i++)
							{
								if (buffID = pTargetWnd->BuffSpellID[i])
								{
									if (SPELL* pBuff = GetSpellByID((DWORD)buffID))
									{
										pAffects[j].Type = 2;
										pAffects[j].SpellID = pBuff->ID;
										pAffects[j].CasterGuid = pMe->Guid;
										pAffects[j].Level = ((SPAWNINFO*)pLocalPlayer)->Level;
										pAffects[j].Modifier = 1.0;
										j++;
									}
								}
							}
						}

						int SlotIndex = -1;
						EQ_Affect* ret = pPc->FindAffectSlot(pSpell->ID, (SPAWNINFO*)pLocalPlayer, &SlotIndex, true, ((SPAWNINFO*)pLocalPlayer)->Level, pAffects, j, false);
						if (!ret || SlotIndex == -1)
							Dest.DWord = false;
						else
							Dest.DWord = true;
					}
				}
			}
		}
		return true;
	}

	case MyRange: {
		VePointer<CONTENTS> n;
		Dest.Float = pSpell->Range + (float)GetFocusRangeModifier((EQ_Spell*)pSpell, n);
		Dest.Type = pFloatType;
		return true;
	}

		// This is for debugging purposes/correcting struct on patchday
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case EnduranceCost:
		Dest.DWord = pSpell->EnduranceCost;
		Dest.Type = pIntType;
		return true;

	case MaxLevel:
		Dest.DWord = GetSpellMax(pSpell, 0);
		Dest.Type = pIntType;
		return true;

	case Category:
		strcpy_s(DataTypeTemp, "Unknown");
		if (int cat = GetSpellCategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Subcategory:
		strcpy_s(DataTypeTemp, "Unknown");
		if (int cat = GetSpellSubcategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				strcpy_s(DataTypeTemp, ptr);
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Restrictions:
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		strcpy_s(DataTypeTemp, "Unknown");
		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;

			char* ptr = GetSpellRestrictions(pSpell, nIndex, DataTypeTemp, sizeof(DataTypeTemp));
			if (!ptr)
				strcpy_s(DataTypeTemp, "Unknown");
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Base:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellBase(pSpell, nIndex);
		}
		return true;

	case Base2:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellBase2(pSpell, nIndex);
		}
		return true;

	case Max:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			Dest.Int = GetSpellMax(pSpell, nIndex);
		}
		return true;

	case Calc:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellCalc(pSpell, nIndex);
		}
		return true;

	case Attrib:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.Int = GetSpellAttrib(pSpell, nIndex);
		}
		return true;

	case CalcIndex:
		Dest.Int = pSpell->CalcIndex;
		Dest.Type = pIntType;
		return true;

	case NumEffects:
		Dest.Int = GetSpellNumEffects(pSpell);
		Dest.Type = pIntType;
		return true;

	case AutoCast:
		Dest.DWord = pSpell->Autocast;
		Dest.Type = pIntType;
		return true;

	case Extra:
		strcpy_s(DataTypeTemp, pSpell->Extra);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case RecastTimerID:
		Dest.DWord = pSpell->ReuseTimerIndex;
		Dest.Type = pIntType;
		return true;

	case SPA:
		Dest.DWord = pSpell->spaindex;
		Dest.Type = pIntType;
		return true;

	case ReagentID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->ReagentID[nIndex];
		}
		return true;

	case NoExpendReagentID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->NoExpendReagent[nIndex];
		}
		return true;

	case ReagentCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->ReagentCount[nIndex];
		}
		return true;

	case TimeOfDay:
		Dest.DWord = pSpell->TimeOfDay;
		Dest.Type = pIntType;
		return true;

	case DurationWindow:
		Dest.DWord = pSpell->DurationWindow;
		Dest.Type = pIntType;
		return true;

	case CanMGB:
		Dest.DWord = pSpell->CanMGB;
		Dest.Type = pBoolType;
		return true;

	case IsSkill:
		Dest.DWord = pSpell->IsSkill;
		Dest.Type = pBoolType;
		return true;

	case Deletable:
		Dest.DWord = pSpell->Deletable;
		Dest.Type = pBoolType;
		return true;

	case BookIcon:
		Dest.DWord = pSpell->BookIcon;
		Dest.Type = pIntType;
		return true;

	case SpellIcon:
		Dest.DWord = pSpell->SpellIcon;
		Dest.Type = pIntType;
		return true;

	case GemIcon:
		Dest.DWord = pSpell->GemIcon;
		Dest.Type = pIntType;
		return true;

	case Target:
		strcpy_s(DataTypeTemp, pSpell->Target);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case Description:
		Dest.Type = pStringType;
		if (const char* ptr = pCDBStr->GetString(pSpell->DescriptionIndex, eSpellDescription))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;

	case Caster: {
		Dest.Type = pStringType;
		auto iter = targetBuffSlotToCasterMap.find(VarPtr.HighPart);
		if (iter != targetBuffSlotToCasterMap.end())
		{
			strcpy_s(DataTypeTemp, iter->second.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	}

	case BaseName:
	{
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;

		int SpellRank = pSpell->SpellRank;

		switch (pSpell->SpellRank)
		{
		case 1: // Original
			SpellRank = 1;
			break;
		case 5: // Rk. II
			SpellRank = 2;
			break;
		case 10: // Rk. III
			SpellRank = 3;
			break;
		}

		if (!SpellRank)
		{
			SpellRank = GetSpellRankByName(pSpell->Name);
		}

		if (SpellRank > 1)
		{
			TruncateSpellRankName(DataTypeTemp);
		}
		return true;
	}

	case Rank:
		// well I haven't checked all spells, but im pretty sure if it's 0 its not a spell a
		// player can scribe/or not intentional, i.e a eq bug, time will tell - eqmule

		Dest.DWord = pSpell->SpellRank;
		Dest.Type = pIntType;

		switch (pSpell->SpellRank)
		{
		case 1: // Original
			Dest.DWord = 1;
			break;
		case 5: // Rk. II
			Dest.DWord = 2;
			break;
		case 10: // Rk. III
			Dest.DWord = 3;
			break;
		}

		if (Dest.DWord == 0)
		{
			// didn't have a rank, lets see if we can get it from the name
			Dest.DWord = GetSpellRankByName(pSpell->Name);
		}

		return true;

	case RankName: {
		Dest.Type = pSpellType;

		int level = -1;
		if (SPAWNINFO* pMe = (SPAWNINFO*)pLocalPlayer)
		{
			level = pMe->Level;
		}

		SPELL* thespell = pSpell;
		if (PcProfile* pProfile = GetPcProfile())
		{
			// is it a altability?
			for (int nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++)
			{
				if (ALTABILITY* pAbility = GetAAByIdWrapper(nAbility, level))
				{
					if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
					{
						if (!_strnicmp(thespell->Name, pName, strlen(thespell->Name)))
						{
							if (pAbility->SpellID != -1)
							{
								if (SPELL* pFoundSpell = GetSpellByID(pAbility->SpellID))
								{
									if (pFoundSpell->SpellGroup == thespell->SpellGroup)
									{
										Dest.Ptr = pFoundSpell;
										return true;
									}
								}
							}
						}
					}
				}
			}

			// so if we got here we should check if its a combatability
			for (DWORD dwIndex = 0; dwIndex < NUM_COMBAT_ABILITIES; dwIndex++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(dwIndex))
				{
					if (SPELL* pFoundSpell = GetSpellByID(pPCData->GetCombatAbility(dwIndex)))
					{
						if (pFoundSpell->SpellGroup == thespell->SpellGroup
							&& !_strnicmp(thespell->Name, pFoundSpell->Name, strlen(thespell->Name)))
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}

			// well AA should be used first so lets search spells last...
			for (int nSpell : pProfile->SpellBook)
			{
				if (nSpell != -1)
				{
					if (SPELL* pFoundSpell = GetSpellByID(nSpell))
					{
						if (pFoundSpell->ID == thespell->ID)
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}

			for (int nSpell : pProfile->SpellBook)
			{
				if (nSpell != -1)
				{
					if (SPELL* pFoundSpell = GetSpellByID(nSpell))
					{
						if (pFoundSpell->SpellGroup == thespell->SpellGroup
							&& !_strnicmp(thespell->Name, pFoundSpell->Name, strlen(thespell->Name)))
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}
		}
		Dest.Ptr = thespell;
		return true;
	}

	case SpellGroup:
		Dest.DWord = pSpell->SpellGroup;
		Dest.Type = pIntType;
		return true;

	case SubSpellGroup:
		Dest.DWord = pSpell->SpellSubGroup;
		Dest.Type = pIntType;
		return true;

	case Beneficial:
		Dest.DWord = pSpell->SpellType != 0;
		Dest.Type = pBoolType;
		return true;

	case xIsActiveAA:
		Dest.DWord = IsActiveAA(pSpell->Name);
		Dest.Type = pBoolType;
		return true;

	case Location:
		Dest.DWord = pSpell->ZoneType;
		Dest.Type = pIntType;
		return true;

	case IsSwarmSpell: {
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		int slots = GetSpellNumEffects(pSpell);

		for (int i = 0; i < slots; i++)
		{
			int attrib = GetSpellAttrib(pSpell, i);
			if (attrib == SPA_PET_SWARM || attrib == SPA_DOPPELGANGER)
			{
				Dest.DWord = 1;
				break;
			}
		}
		return true;
	}

	case DurationValue1:
		Dest.DWord = pSpell->DurationCap;
		Dest.Type = pIntType;
		return true;

	case StacksWithDiscs:
		Dest.DWord = pSpell->bStacksWithDiscs;
		Dest.Type = pBoolType;
		return true;

	case IllusionOkWhenMounted:
		Dest.DWord = true;
		Dest.Type = pBoolType;

		if (uint8_t spellIndex = ((EQ_Spell*)pSpell)->SpellAffects(SPA_CHANGE_FORM))
		{
			if (EQ_Affect* aff = pCharData->GetPCSpellAffect(SPA_SUMMON_MOUNT, nullptr))
			{
				if (PlayerClient* pc = pLocalPlayer)
				{
					for (int i = 0; i < GetSpellNumEffects(pSpell); ++i)
					{
						if (const SpellAffectData* pSpellAffect = ((EQ_Spell*)pSpell)->GetSpellAffectByIndex(i))
						{
							if (pSpellAffect->Attrib == SPA_CHANGE_FORM)
							{
								int islegal = pc->LegalPlayerRace(pSpellAffect->Base);

								if (!islegal && pSpellAffect->Base != EQR_SKELETON
									&& pSpellAffect->Base != EQR_SKELETON_NEW
									&& pSpellAffect->Base != EQR_OEQ_SKELETON
									&& pSpellAffect->Base != EQR_SOL_SKELETON)
								{
									// can't change into this illusion cause you are on a mount...
									Dest.DWord = false;
									break;
								}
							}
						}
					}
				}
			}
		}
		return true;

	case HasSPA:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int spa = GetIntFromString(Index, 0);
				if (IsSPAEffect(pSpell, spa))
				{
					Dest.DWord = true;
				}
			}
		}
		return true;

	case Trigger:
	{
		Dest.Type = pSpellType;

		int spaFound = GetTriggerSPA(pSpell);
		if (pSpellMgr && spaFound)
		{
			int index = std::max(0, GetIntFromString(Index, 0) - 1);
			int numEffects = GetSpellNumEffects(pSpell);
			if (index >= numEffects)
				return false;

			int spellOrGroupId = GetSpellBase2(pSpell, index);
			if (!spellOrGroupId)
				return false;

			SPELL* pTrigger = nullptr;

			switch (spaFound)
			{
			case SPA_TRIGGER_BEST_IN_SPELL_GROUP:
				pTrigger = GetHighestLearnedSpellByGroupID(spellOrGroupId);
				break;

			case SPA_TRIGGER_SPELL:
				pTrigger = pSpellMgr->GetSpellByID(spellOrGroupId);
				break;

			default: break; // should not be reachable if we handled everything GetTriggerSPA returns
			}

			if (pTrigger)
			{
				Dest.Ptr = pTrigger;
				return true;
			}
		}
		return false;
	}

	case SlowPct:
		Dest.Int = GetMeleeSpeedPctFromSpell(pSpell, false);
		Dest.Type = pIntType;
		return true;

	case HastePct:
		Dest.Int = GetMeleeSpeedPctFromSpell(pSpell, true);
		Dest.Type = pIntType;
		return true;
	}

	return false;
}

