#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2TargetType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (!VarPtr.Ptr)
		return false;

	MQTypeMember* pMember = MQ2TargetType::FindMember(Member);
	if (!pMember)
	{
		return pSpawnType->GetMember(VarPtr, Member, Index, Dest);
	}

	if (!GetCharInfo())
		return false;

	switch (static_cast<TargetMembers>(pMember->ID))
	{
	case BuffsPopulated:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (gTargetbuffs && pTarget)
			Dest.DWord = gTargetbuffs;
		return true;

	case Buff:
		Dest.Type = pSpellType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID && buffID != -1)
				{
					if (Dest.Ptr = GetSpellByID(buffID))
					{
						Dest.HighPart = nBuff;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
			else
			{
				for (int i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					int buffID = pTargetWnd->BuffSpellID[i];
					if (buffID && ci_starts_with(GetSpellNameByID(buffID), Index))
					{
						if (Dest.Ptr = GetSpellByID(buffID))
						{
							Dest.HighPart = i;
							Dest.Type = pSpellType;
							return true;
						}
					}
				}
			}
		}
		else
		{
			// return first buff
			for (int i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				if (int buffID = pTargetWnd->BuffSpellID[i])
				{
					if (SPELL* pSpell = GetSpellByID(buffID))
					{
						strcpy_s(DataTypeTemp, pSpell->Name);
						Dest.Ptr = &DataTypeTemp[0];
						Dest.Type = pStringType;
						return true;
					}
				}
			}
		}
		return false;

	case MyBuff:
		Dest.Type = pSpellType;
		if (pTargetWnd->Type <= 0)
			return false;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID > 0)
				{
					if (!targetBuffSlotToCasterMap.empty() && targetBuffSlotToCasterMap.find(nBuff) != targetBuffSlotToCasterMap.end())
					{
						if (string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[nBuff]))
						{
							if (Dest.Ptr = GetSpellByID(buffID))
							{
								Dest.HighPart = nBuff;
								Dest.Type = pSpellType;
								return true;
							}
						}
					}

				}
			}
			else
			{
				if (!targetBuffSlotToCasterMap.empty())
				{
					for (int i = 0; i < NUM_BUFF_SLOTS; i++)
					{
						if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
							&& string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[i]))
						{
							int buffID = pTargetWnd->BuffSpellID[i];
							if (buffID && ci_starts_with(GetSpellNameByID(buffID), Index))
							{
								if (Dest.Ptr = GetSpellByID(buffID))
								{
									Dest.HighPart = i;
									Dest.Type = pSpellType;
									return true;
								}
							}
						}
					}
				}
			}
		}
		else
		{
			// return first buff
			if (!targetBuffSlotToCasterMap.empty())
			{
				for (int i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
						&& string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[i]))
					{
						int buffID = pTargetWnd->BuffSpellID[i];
						if (buffID)
						{
							if (SPELL* pSpell = GetSpellByID(buffID))
							{
								strcpy_s(DataTypeTemp, pSpell->Name);
								Dest.Ptr = &DataTypeTemp[0];
								Dest.Type = pStringType;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case BuffCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pTargetWnd->Type <= 0)
			return false;

		for (int i = 0; i < NUM_BUFF_SLOTS; i++)
		{
			if (pTargetWnd->BuffSpellID[i])
				Dest.DWord++;
		}
		return true;

	case MyBuffCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (!targetBuffSlotToCasterMap.empty())
		{
			for (int i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
					&& string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[i]))
				{
					int buffID = pTargetWnd->BuffSpellID[i];
					if (buffID)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;

	case MyBuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID > 0)
				{
					if (!targetBuffSlotToCasterMap.empty()
						&& targetBuffSlotToCasterMap.find(nBuff) != targetBuffSlotToCasterMap.end())
					{
						if (string_equals(GetCharInfo()->Name, targetBuffSlotToCasterMap[nBuff]))
						{
							Dest.UInt64 = pTargetWnd->BuffTimer[nBuff];
							return true;
						}
					}

				}
			}
			else
			{
				if (!targetBuffSlotToCasterMap.empty() && GetCharInfo())
				{
					for (int i = 0; i < NUM_BUFF_SLOTS; i++)
					{
						if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end()
							&& !strcmp(GetCharInfo()->Name, targetBuffSlotToCasterMap[i].c_str()))
						{
							int buffID = pTargetWnd->BuffSpellID[i];
							if (buffID && ci_starts_with(GetSpellNameByID(buffID), Index))
							{
								Dest.UInt64 = pTargetWnd->BuffTimer[i];
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (pTargetWnd->Type <= 0)
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, NUM_BUFF_SLOTS + 1);
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;

				int buffID = pTargetWnd->BuffSpellID[nBuff];
				if (buffID > 0)
				{
					Dest.UInt64 = pTargetWnd->BuffTimer[nBuff];
					return true;
				}
			}
			else
			{
				int duration = 0;
				for (int i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					int buffID = pTargetWnd->BuffSpellID[i];

					// I strncmp them to take ranked buffs into account
					// so if the user specifies ${Target.BuffDuration[Pyromancy]} for example
					// its still gonna work if it finds Pyromancy XV
					if (buffID > 0 && ci_starts_with(GetSpellNameByID(buffID), Index))
					{
						if (pTargetWnd->BuffTimer[i] > duration)
						{
							duration = pTargetWnd->BuffTimer[i];
							// we always want to return the buff with the longest duration
							// cause thats the one that landed last on the mob
							// otherwize we could just break; out of here at this point
							// but anyway thats the reason we keep rolling through all them... -eqmule
						}
					}

					if (duration > 0)
					{
						Dest.UInt64 = duration;
						return true;
					}
				}
			}
		}
		return false;

	case PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;

	case SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;

	case SecondaryAggroPlayer:
		Dest.Type = pSpawnType;

		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;

	case AggroHolder: {
		Dest.Type = pSpawnType;
		// who the Target has the MOST aggro on
		char* pTargetAggroHolder = EQADDR_TARGETAGGROHOLDER;
		if (pTargetAggroHolder[0] != '\0')
		{
			SPAWNINFO* pAggroHolder = (SPAWNINFO*)GetSpawnByName(pTargetAggroHolder);
			if (pAggroHolder)
			{
				Dest.Ptr = pAggroHolder;
				return true;
			}
			else
			{
				// ok no spawn was found for the name given, this can only mean one thing... its a pet or a mercenary
				MQSpawnSearch SearchSpawn;
				ClearSearchSpawn(&SearchSpawn);
				SearchSpawn.FRadius = 999999.0f;
				strcpy_s(SearchSpawn.szName, pTargetAggroHolder);
				pAggroHolder = SearchThroughSpawns(&SearchSpawn, (SPAWNINFO*)pLocalPlayer);
				if (pAggroHolder)
				{
					Dest.Ptr = pAggroHolder;
					return true;
				}
			}
		}
		else
		{
			// it could be me...
			// lets check
			if (pTarget && EQADDR_GROUPAGGRO)
			{
				if (*(DWORD*)(EQADDR_GROUPAGGRO + 0x78) >= 100)
				{
					if (Dest.Ptr = GetSpawnByID(((SPAWNINFO*)pLocalPlayer)->TargetOfTarget))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	case Slowed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_HASTE, 0)) != -1)
		{
			return true;
		}
		return false;

	case Rooted:
		Dest.Int = 0;

		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(SPA_ROOT, 0)) != -1) // Root
		{
			return true;
		}
		return false;

	case Mezzed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_ENTHRALL, 0)) != -1) // Entrall
		{
			return true;
		}
		return false;

	case Crippled:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySubCat("Disempowering")) != -1)
		{
			return true;
		}
		return false;

	case Maloed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage))) != -1)
		{
			return true;
		}
		return false;

	case Tashed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySubCat("Resist Debuffs", 1 << Enchanter)) != -1)
		{
			return true;
		}
		return false;

	case Snared:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_MOVEMENT_RATE, 0)) != -1) // Movement Rate
		{
			return true;
		}
		return false;

	case Hasted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_HASTE, 1)) != -1)
		{
			return true;
		}
		return false;

	case Beneficial:
	{
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if (pTargetWnd->Type <= 0)
			return false;

		for (int i = 0; i < NUM_BUFF_SLOTS; i++)
		{
			if (pTargetWnd->BuffSpellID[i] == -1 || pTargetWnd->BuffSpellID[i] == 0)
				continue;

			if (SPELL * pSpell = GetSpellByID(pTargetWnd->BuffSpellID[i]))
			{
				if (pSpell->SpellType != 0)
				{
					//targetwindow has a leak in it player buffs shows up in it
					//so we need to make sure its not a "leaked buff"
					if (CXStr* str = pTargetWnd->GetBuffCaster(pSpell->ID))
					{
						if (SPAWNINFO* pPlayer = (SPAWNINFO*)GetSpawnByName(str->c_str()))
						{
							if (pPlayer->Type == SPAWN_PLAYER)
							{
								continue;
							}
						}
					}
					Dest.Int = i;
					return true;
				}
			}
		}
		return false;
	}

	case DSed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_DAMAGE_SHIELD, 1)) != -1) // Damage Shield
		{
			return true;
		}
		return false;

	case RevDSed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_IRONMAIDEN, 1)) != -1) // Reverse Damage Shield
		{
			return true;
		}
		return false;

	case Charmed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_CHARM, 0)) != -1) // Charm
		{
			return true;
		}
		return false;

	case Aego:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric)) != -1) // Aegolism Line
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if ((GetSpellSubcategory(pSpell) == 1) || (GetSpellSubcategory(pSpell) == 112))
					{
						if (((EQ_Spell*)pSpell)->SpellAffectBase(SPA_AC))
						{
							return true;
						}
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Skin:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid)) != -1) //
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 46)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Focus:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Shaman)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 87)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Shaman, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Regen:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_HP, 1)) != -1) // HP Regen
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if ((((EQ_Spell*)pSpell)->SpellAffectBase(SPA_HP) > 0) && (!IsSpellUsableForClass(pSpell, 1 << Beastlord)))
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffBySPA(SPA_HP, 1, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Diseased:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_DISEASE, 0)) != -1) // Disease Counter
		{
			return true;
		}
		return false;

	case Poisoned:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_POISON, 0)) != -1) // Poison Counter
		{
			return true;
		}
		return false;

	case Cursed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_CURSE, 0)) != -1) // Curse Counter
		{
			return true;
		}
		return false;

	case Corrupted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_CORRUPTION, 0)) != -1) // Corruption Counter
		{
			return true;
		}
		return false;

	case Symbol:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric)) != -1) //
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 112)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Clarity:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_MANA, 1)) != -1) // Mana Regen
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if ((((EQ_Spell*)pSpell)->SpellAffectBase(SPA_MANA) > 0) && (IsSpellUsableForClass(pSpell, 1 << Enchanter)))
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffBySPA(SPA_MANA, 1, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Pred:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(95, 1 << Ranger)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 7)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(95, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}

		return false;
	case Strength:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 47)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Brells:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Paladin)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 47)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Paladin, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case SV:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 59)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case SE:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 44)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case HybridHP:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 46)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Growth:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 141)
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Shining:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffByCategory(125, 1 << Cleric)) != -1)
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 62)
					{
						if (((EQ_Spell*)pSpell)->SpellAffectBase(SPA_MELEE_GUARD))
						{
							return true;
						}
					}
				}

				if ((Dest.Int = GetTargetBuffByCategory(125, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case Feared:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_FEAR, 0)) != -1) // Feared
		{
			return true;
		}
		return false;

	case Silenced:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_SILENCE, 0)) != -1) // Silenced
		{
			return true;
		}
		return false;

	case Invulnerable:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_INVULNERABILITY, 0)) != -1) // Invulnerable
		{
			return true;
		}
		return false;

	case Dotted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;

		if ((Dest.Int = GetTargetBuffBySPA(SPA_HP, 0)) != -1) // HP Mod
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[Dest.Int]))
				{
					if (((EQ_Spell*)pSpell)->IsDetrimentalSpell() && ((EQ_Spell*)pSpell)->IsDoTSpell())
					{
						return true;
					}
				}

				if ((Dest.Int = GetTargetBuffBySPA(SPA_HP, 0, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;

	case MaxMeleeTo: {
		Dest.Float = get_melee_range(pCharSpawn, pTarget);
		Dest.Type = pFloatType;
		return true;
	}

	default: break;
	}

	return false;
}

