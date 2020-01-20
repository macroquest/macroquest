#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2CharacterType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CHARINFO* pChar = static_cast<CHARINFO*>(VarPtr.Ptr);
	if (!pChar)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	PlayerClient* pPlayerClient = reinterpret_cast<PlayerClient*>(pChar->pSpawn);

	//------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2CharacterType::FindMethod(Member))
	{
		switch (static_cast<CharacterMethods>(pMethod->ID))
		{
		case Stand:
			pEverQuest->InterpretCmd(pPlayerClient, "/stand on");
			return true;

		case Sit:
			pEverQuest->InterpretCmd(pPlayerClient, "/sit on");
			return true;

		case Dismount:
			pEverQuest->InterpretCmd(pPlayerClient, "/dismount");
			return true;

		case StopCast:
			pEverQuest->InterpretCmd(pPlayerClient, "/stopcast");
			return true;

		default: break;
		}

		return false;
	}

	MQTypeMember* pMember = MQ2CharacterType::FindMember(Member);
	if (!pMember)
	{
		// call into parent
		MQVarPtr data;
		data.Ptr = pLocalPlayer;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<CharacterMembers>(pMember->ID))
	{
	case Name:
		strcpy_s(DataTypeTemp, ((SPAWNINFO*)pLocalPlayer)->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case Origin:
		Dest.Type = pZoneType;
		if (pChar->StartingCity > 0 && pChar->StartingCity < MAX_ZONES)
		{
			Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pChar->StartingCity];
			return true;
		}
		return false;

	case SubscriptionDays:
		Dest.Int = pChar->SubscriptionDays;
		Dest.Type = pIntType;
		return true;

	case Exp:
		Dest.Int64 = pChar->Exp;
		Dest.Type = pInt64Type;
		return true;

	case PctExp:
		Dest.Float = (float)pChar->Exp / 1000.0f;
		Dest.Type = pFloatType;
		return true;

	case PctExpToAA:
		Dest.Int = (int)pChar->PercentEXPtoAA;
		Dest.Type = pIntType;
		return true;

	case PctAAExp:
		Dest.Float = (float)pChar->AAExp / 1000.0f;
		Dest.Type = pFloatType;
		return true;

	case Vitality:
		Dest.Int64 = pChar->Vitality;
		Dest.Type = pInt64Type;
		return true;

	case PctVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int64_t vitality = pChar->Vitality;
		int64_t cap = pInventoryWnd->VitalityCap;
		if (vitality > cap)
			vitality = cap;
		if (cap > 0)
			Dest.Float = (float)vitality * 100 / cap;
		return true;
	}

	case AAVitality:
		Dest.Int = pChar->AAVitality;
		Dest.Type = pIntType;
		return true;

	case PctAAVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int aavitality = pChar->AAVitality;
		int aacap = pInventoryWnd->AAVitalityCap;
		if (aavitality > aacap)
			aavitality = aacap;
		if (aacap > 0)
			Dest.Float = (float)aavitality * 100 / aacap;
		return true;
	}

	case Spawn:
		Dest.Ptr = pLocalPlayer;
		Dest.Type = pSpawnType;
		return true;

	case CurrentHPs:
		Dest.DWord = GetCurHPS();
		Dest.Type = pIntType;
		return true;

	case MaxHPs:
		Dest.Type = pIntType;
		Dest.Int = GetMaxHPS();
		return true;

	case PctHPs: {
		Dest.Int = 0;
		Dest.Type = pIntType;
		LONG maxhp = GetMaxHPS();
		if (maxhp != 0)
			Dest.Int = GetCurHPS() * 100 / maxhp;
		return true;
	}

	case CurrentMana:
		Dest.DWord = pProfile->Mana;
		Dest.Type = pIntType;
		return true;

	case MaxMana:
		Dest.DWord = GetMaxMana();
		Dest.Type = pIntType;
		return true;

	case PctMana:
		if (int maxMana = GetMaxMana())
			Dest.DWord = pProfile->Mana * 100 / maxMana;
		else
			Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case CountBuffs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (buff.SpellID > 0)
			{
				Dest.DWord++;
			}
		}
		return true;

	case CountSongs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->ShortBuff)
		{
			if (buff.SpellID > 0)
			{
				Dest.DWord++;
			}
		}
		return true;

	case BlockedPetBuff:
		// Fall through to BlockedBuff
	case BlockedBuff:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		// TODO:  Move this into a function for both BlockedPetBuff and BlockedBuff
		if (CHARINFONEW* pCharnew = reinterpret_cast<CHARINFONEW*>(GetCharInfo()))
		{
			int iMaxBlockedSpells = (static_cast<CharacterMembers>(pMember->ID) == BlockedBuff ? MAX_BLOCKED_SPELLS : MAX_BLOCKED_SPELLS_PET);
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, iMaxBlockedSpells + 2) - 1;
				if (nBuff < 0)
					nBuff = 0;
				if (nBuff > iMaxBlockedSpells)
					return false;

				if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == BlockedBuff) ? pCharnew->BlockedSpell[nBuff] : pCharnew->BlockedPetSpell[nBuff])
				{
					if (SPELL* pSpell = GetSpellByID(spellId))
					{
						Dest.Ptr = pSpell;
						return true;
					}
				}
			}
			else
			{
				for (auto i = 0; i < iMaxBlockedSpells; ++i)
				{
					if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == BlockedBuff) ? pCharnew->BlockedSpell[i] : pCharnew->BlockedPetSpell[i])
					{
						if (SPELL* pSpell = GetSpellByID(spellId))
						{
							if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
							{
								Dest.Ptr = pSpell;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	// TODO:  Move this to a function for both Buff and Song since code is identical except for Short vs Long Buff.
	case Buff:
		Dest.Type = pBuffType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff >= NUM_LONG_BUFFS)
				return false;
			if (pProfile->Buff[nBuff].SpellID <= 0)
				return false;

			Dest.Ptr = (SPELLBUFF*)&pProfile->Buff[nBuff];
			Dest.HighPart = nBuff;
			return true;
		}

		for (int nBuff = 0; nBuff < NUM_LONG_BUFFS; ++nBuff)
		{
			if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
			{
				if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
				{
					Dest.Ptr = (SPELLBUFF*)&pProfile->Buff[nBuff];
					Dest.HighPart = nBuff;
					return true;
				}
			}
		}
		return false;

	case Song:
		Dest.Type = pBuffType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff >= NUM_SHORT_BUFFS)
				return false;
			if (pProfile->ShortBuff[nBuff].SpellID <= 0)
				return false;

			Dest.Ptr = (SPELLBUFF*)&pProfile->ShortBuff[nBuff];
			Dest.HighPart = nBuff;
			return true;
		}

		for (int nBuff = 0; nBuff < NUM_SHORT_BUFFS; nBuff++)
		{
			if (SPELL* pSpell = GetSpellByID(pProfile->ShortBuff[nBuff].SpellID))
			{
				if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
				{
					Dest.Ptr = (SPELLBUFF*)&pProfile->ShortBuff[nBuff];
					Dest.HighPart = nBuff;
					return true;
				}
			}
		}
		return false;

	case HPBonus:
		Dest.DWord = pChar->HPBonus;
		Dest.Type = pIntType;
		return true;

	case ManaBonus:
		Dest.DWord = pChar->ManaBonus;
		Dest.Type = pIntType;
		return true;

	case EnduranceBonus:
		Dest.DWord = pChar->EnduranceBonus;
		Dest.Type = pIntType;
		return true;

	case CombatEffectsBonus: {
		int CombatEffectsCap = GetModCap(HEROIC_MOD_COMBAT_EFFECTS);
		Dest.DWord = (pChar->CombatEffectsBonus > CombatEffectsCap ? CombatEffectsCap : pChar->CombatEffectsBonus);
		Dest.Type = pIntType;
		return true;
	}

	case ShieldingBonus: {
		int ShieldingCap = GetModCap(HEROIC_MOD_MELEE_SHIELDING);
		Dest.DWord = (pChar->ShieldingBonus > ShieldingCap ? ShieldingCap : pChar->ShieldingBonus);
		Dest.Type = pIntType;
		return true;
	}

	case SpellShieldBonus: {
		int SpellShieldCap = GetModCap(HEROIC_MOD_SPELL_SHIELDING);
		Dest.DWord = (pChar->SpellShieldBonus > SpellShieldCap ? SpellShieldCap : pChar->SpellShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case AvoidanceBonus: {
		int AvoidanceCap = GetModCap(HEROIC_MOD_AVOIDANCE);
		Dest.DWord = (pChar->AvoidanceBonus > AvoidanceCap ? AvoidanceCap : pChar->AvoidanceBonus);
		Dest.Type = pIntType;
		return true;
	}

	case AccuracyBonus: {
		int AccuracyCap = GetModCap(HEROIC_MOD_ACCURACY);
		Dest.DWord = (pChar->AccuracyBonus > AccuracyCap ? AccuracyCap : pChar->AccuracyBonus);
		Dest.Type = pIntType;
		return true;
	}

	case StunResistBonus: {
		int StunResistCap = GetModCap(HEROIC_MOD_STUN_RESIST);
		Dest.DWord = (pChar->StunResistBonus > StunResistCap ? StunResistCap : pChar->StunResistBonus);
		Dest.Type = pIntType;
		return true;
	}

	case StrikeThroughBonus: {
		int StrikeThroughCap = GetModCap(HEROIC_MOD_STRIKETHROUGH);
		Dest.DWord = (pChar->StrikeThroughBonus > StrikeThroughCap ? StrikeThroughCap : pChar->StrikeThroughBonus);
		Dest.Type = pIntType;
		return true;
	}

	case DoTShieldBonus: {
		int DoTShieldCap = GetModCap(HEROIC_MOD_DOT_SHIELDING);
		Dest.DWord = (pChar->DoTShieldBonus > DoTShieldCap ? DoTShieldCap : pChar->DoTShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case AttackBonus:
		Dest.DWord = pChar->AttackBonus;
		Dest.Type = pIntType;
		return true;

	case HPRegenBonus:
		Dest.DWord = pChar->HPRegenBonus;
		Dest.Type = pIntType;
		return true;

	case ManaRegenBonus:
		Dest.DWord = pChar->ManaRegenBonus;
		Dest.Type = pIntType;
		return true;

	case DamageShieldBonus: {
		int DamageShieldCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELDING);
		Dest.DWord = (pChar->DamageShieldBonus > DamageShieldCap ? DamageShieldCap : pChar->DamageShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case DamageShieldMitigationBonus: {
		int DamageShieldMitigationCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELD_MITIG);
		Dest.DWord = (pChar->DamageShieldMitigationBonus > DamageShieldMitigationCap ? DamageShieldMitigationCap : pChar->DamageShieldMitigationBonus);
		Dest.Type = pIntType;
		return true;
	}

	case HeroicSTRBonus:
		Dest.DWord = pChar->HeroicSTRBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicINTBonus:
		Dest.DWord = pChar->HeroicINTBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicWISBonus:
		Dest.DWord = pChar->HeroicWISBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicAGIBonus:
		Dest.DWord = pChar->HeroicAGIBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicDEXBonus:
		Dest.DWord = pChar->HeroicDEXBonus;
		Dest.Type = pIntType;
		return true;

	case HeroicSTABonus:
		Dest.DWord = pChar->HeroicSTABonus;
		Dest.Type = pIntType;
		return true;

	case HeroicCHABonus:
		Dest.DWord = pChar->HeroicCHABonus;
		Dest.Type = pIntType;
		return true;

	case HealAmountBonus:
		Dest.DWord = pChar->HealAmountBonus;
		Dest.Type = pIntType;
		return true;

	case SpellDamageBonus:
		Dest.DWord = pChar->SpellDamageBonus;
		Dest.Type = pIntType;
		return true;

	case ClairvoyanceBonus:
		Dest.DWord = pChar->ClairvoyanceBonus;
		Dest.Type = pIntType;
		return true;

	case EnduranceRegenBonus:
		Dest.DWord = pChar->EnduranceRegenBonus;
		Dest.Type = pIntType;
		return true;

	case AttackSpeed:
		Dest.DWord = pChar->AttackSpeed;
		Dest.Type = pIntType;
		return true;

	case Endurance: // Backwards compat, CurrentEndurance should be used instead.
	case CurrentEndurance:
		Dest.DWord = pProfile->Endurance;
		Dest.Type = pIntType;
		return true;

	case MaxEndurance:
		Dest.DWord = GetMaxEndurance();
		Dest.Type = pIntType;
		return true;

	case PctEndurance:
		if (int maxEndurance = GetMaxEndurance())
			Dest.DWord = pProfile->Endurance * 100 / maxEndurance;
		else
			Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case GukEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_DeepGuk].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case MMEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Mistmoore].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case RujEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Rujarkian].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case TakEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Takish].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case MirEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Miraguls].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case LDoNPoints:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.AdventurePointsAvailable;
		}
		Dest.Type = pIntType;
		return true;

	case CurrentFavor:
		Dest.Int64 = pChar->CurrFavor;
		Dest.Type = pInt64Type;
		return true;

	case CareerFavor:
		Dest.Int64 = pChar->CareerFavor;
		Dest.Type = pInt64Type;
		return true;

	case Inventory:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, NUM_INV_SLOTS);
				if (nSlot < NUM_INV_SLOTS)
				{
					if (pProfile->pInventoryArray && ((Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nSlot])))
					{
						return true;
					}
				}
			}
			else
			{
				for (int nSlot = 0; szItemSlot[nSlot]; nSlot++)
				{
					if (!_stricmp(Index, szItemSlot[nSlot]))
					{
						if (pProfile->pInventoryArray && ((Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nSlot])))
						{
							return true;
						}
					}
				}
			}
		}
		return false;

	case Bank:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0) - 1;
				if (nSlot < 0)
					return false;

				if (nSlot < NUM_BANK_SLOTS)
				{
					if (pChar && pChar->pBankArray)
					{
						if (Dest.Ptr = pChar->pBankArray->Bank[nSlot])
						{
							return true;
						}
					}
				}
				else
				{
					nSlot -= NUM_BANK_SLOTS;
					if (nSlot < NUM_SHAREDBANK_SLOTS)
					{
						if (pChar && pChar->pSharedBankArray)
						{
							if (Dest.Ptr = pChar->pSharedBankArray->SharedBank[nSlot])
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case PlatinumShared:
		Dest.DWord = pChar->BankSharedPlat;
		Dest.Type = pIntType;
		return true;

	case Cash:
		Dest.Int64 = static_cast<uint64_t>(pProfile->Plat) * 1000 + static_cast<uint64_t>(pProfile->Gold) * 100 + static_cast<uint64_t>(pProfile->Silver) * 10 + pProfile->Copper;
		Dest.Type = pInt64Type;
		return true;

	case Platinum:
		Dest.DWord = pProfile->Plat;
		Dest.Type = pIntType;
		return true;

	case CursorPlatinum:
		Dest.DWord = pProfile->CursorPlat;
		Dest.Type = pIntType;
		return true;

	case Gold:
		Dest.DWord = pProfile->Gold;
		Dest.Type = pIntType;
		return true;

	case CursorGold:
		Dest.DWord = pProfile->CursorGold;
		Dest.Type = pIntType;
		return true;

	case Silver:
		Dest.DWord = pProfile->Silver;
		Dest.Type = pIntType;
		return true;

	case CursorSilver:
		Dest.DWord = pProfile->CursorSilver;
		Dest.Type = pIntType;
		return true;

	case Copper:
		Dest.DWord = pProfile->Copper;
		Dest.Type = pIntType;
		return true;

	case CursorCopper:
		Dest.DWord = pProfile->CursorCopper;
		Dest.Type = pIntType;
		return true;

	case CashBank:
		Dest.Int64 = static_cast<uint64_t>(pProfile->Plat) * 1000 + static_cast<uint64_t>(pProfile->Gold) * 100 + static_cast<uint64_t>(pProfile->Silver) * 10 + pProfile->Copper;
		Dest.Type = pInt64Type;
		return true;

	case PlatinumBank:
		Dest.DWord = pChar->BankPlat;
		Dest.Type = pIntType;
		return true;

	case GoldBank:
		Dest.DWord = pChar->BankGold;
		Dest.Type = pIntType;
		return true;

	case SilverBank:
		Dest.DWord = pChar->BankSilver;
		Dest.Type = pIntType;
		return true;

	case CopperBank:
		Dest.DWord = pChar->BankCopper;
		Dest.Type = pIntType;
		return true;

	case AAExp:
		Dest.DWord = pChar->AAExp;
		Dest.Type = pIntType;
		return true;

	case AAPoints:
		Dest.DWord = pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case Combat:
		Dest.DWord = *EQADDR_ATTACK;
		Dest.Type = pBoolType;
		return true;

	case HPRegen:
		Dest.DWord = GetHPRegen();
		Dest.Type = pIntType;
		return true;

	case ManaRegen:
		Dest.DWord = GetManaRegen();
		Dest.Type = pIntType;
		return true;

	case EnduranceRegen:
		Dest.DWord = GetEnduranceRegen();
		Dest.Type = pIntType;
		return true;

	case Grouped:
		Dest.Type = pBoolType;
		if (!pChar->pGroupInfo)
			return false;

		Dest.DWord = pChar->pGroupInfo->pMember[1]
			|| pChar->pGroupInfo->pMember[2]
			|| pChar->pGroupInfo->pMember[3]
			|| pChar->pGroupInfo->pMember[4]
			|| pChar->pGroupInfo->pMember[5];
		return true;

	case GroupList: { // This isn't really working as intended just yet
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo)
			return false;
		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				strcpy_s(DataTypeTemp, pChar->pGroupInfo->pMember[i]->Name.c_str());
				if (i < 5 && pChar->pGroupInfo->pMember[i + 1])
					strcat_s(DataTypeTemp, " ");
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case AmIGroupLeader:
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo) return false;
		if (!pChar->pGroupInfo->pLeader) return false;

		if (!_stricmp(pChar->pGroupInfo->pLeader->Name.c_str(), pChar->Name))
			strcpy_s(DataTypeTemp, "TRUE");
		else
			strcpy_s(DataTypeTemp, "FALSE");
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case MaxBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;
		return true;

	case FreeBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (buff.SpellID > 0)
				Dest.DWord--;
		}
		return true;

	case Gem:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// number
			int nGem = GetIntFromString(Index, 0) - 1;
			if (nGem < 0)
				return false;

			if (nGem < NUM_SPELL_GEMS)
			{
				if (Dest.Ptr = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					Dest.Type = pSpellType;
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.DWord = nGem + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case LanguageSkill: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		int nLang = 0;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			nLang = GetIntFromString(Index, nLang) - 1;
			if (nLang < 0)
				return false;
		}
		else
		{
			nLang = GetLanguageIDByName(Index) - 1;
		}
		if (nLang < 0 || nLang >= 25)
			return false;

		Dest.DWord = pChar->languages[nLang];
		return true;
	}

	case CombatAbility:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			// number
			int abnum = GetIntFromString(Index, 0);
			if (abnum <= 0)
				abnum = 1;
			int nCombatAbility = abnum - 1;
			if (nCombatAbility < NUM_COMBAT_ABILITIES)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						Dest.Ptr = pSpell;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
		}
		else
		{
			// name
			for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						if (!_stricmp(Index, pSpell->Name))
						{
							Dest.DWord = nCombatAbility + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;

	case CombatAbilityTimer:
		Dest.Int = 0;
		Dest.Type = pTicksType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// number
				int nCombatAbility = GetIntFromString(Index, 0) - 1;
				if (nCombatAbility < 0)
					return false;
				if (nCombatAbility < NUM_COMBAT_ABILITIES)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));

							if (pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) > timeNow)
							{
								Dest.Int = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) - timeNow + 6;
								Dest.Int /= 6;
							}

							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (int nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer > timeNow)
								{
									Dest.Int = timer - timeNow + 6;
									Dest.Int /= 6;
								}
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case CombatAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// number
				int nCombatAbility = GetIntFromString(Index, 0) - 1;
				if (nCombatAbility < 0)
					return false;

				if (nCombatAbility < NUM_COMBAT_ABILITIES)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
							uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

							if (timer < timeNow)
							{
								Dest.DWord = 1;
								return true;
							}
						}
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer < timeNow)
								{
									Dest.DWord = 1;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return true;

	case ActiveDisc:
		Dest.Type = pSpellType;

		if (pCombatAbilityWnd)
		{
			if (CXWnd* Child = pCombatAbilityWnd->GetChildItem("CAW_CombatEffectLabel"))
			{
				CXStr name = Child->GetWindowText();
				if (!name.empty())
				{
					if (Dest.Ptr = GetSpellByName(name.c_str()))
					{
						return true;
					}
				}
			}
		}
		return false;

	case Moving:
		Dest.DWord = false;
		if (pCharSpawn && pChar && pChar->pSpawn)
		{
			Dest.DWord =
				((gbMoving
					&& (pChar->pSpawn->SpeedRun == 0.0f)
					&& (pChar->pSpawn->Mount == nullptr))
				|| (fabs(FindSpeed(pChar->pSpawn) > 0.0f)));
		}
		Dest.Type = pBoolType;
		return true;

	case Hunger:
		Dest.DWord = pProfile->hungerlevel;
		Dest.Type = pIntType;
		return true;

	case Thirst:
		Dest.DWord = pProfile->thirstlevel;
		Dest.Type = pIntType;
		return true;

	case AltAbilityTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;

		if (Index[0]) {
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							int reusetimer = 0;
							pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
							if (reusetimer < 0)
							{
								reusetimer = 0;
							}

							Dest.UInt64 = reusetimer * 1000;
							return true;
						}
					}
				}
			}
			else
			{
				// by name so we ned to take level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								int reusetimer = 0;
								pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
								if (reusetimer < 0)
								{
									reusetimer = 0;
								}

								Dest.UInt64 = reusetimer * 1000;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case AltAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							if (pAbility->SpellID != -1)
								Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, nullptr);

							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								if (pAbility->SpellID != -1)
									Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, nullptr);

								return true;
							}
						}
					}
				}
			}
		}
		return true;

	case AltAbility:
		Dest.Type = pAltAbilityType;
		if (Index[0])

		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							Dest.Ptr = pAbility;
							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								Dest.Ptr = pAbility;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case Skill:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pProfile->Skill[nSkill])
				{
					Dest.DWord = GetAdjustedSkill(nSkill);
				}
				return true;
			}
		}
		return false;

	case SkillBase:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pProfile->Skill[nSkill])
				{
					Dest.DWord = GetBaseSkill(nSkill);
				}
				return true;
			}
		}
		return false;

	case SkillCap:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pCharData)
				{
					Dest.DWord = pSkillMgr->GetSkillCap(pCharData, pProfile->Level, pProfile->Class, nSkill, true, true, true);
					return true;
				}
			}
		}
		return false;

	case Ability:
		Dest.Type = pStringType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				if (int nSkill = GetIntFromString(Index, 0))
				{
					if (bool bActivated = pSkillMgr->IsActivatedSkill(nSkill))
					{
						int nToken = pSkillMgr->GetNameToken(nSkill);

						if (const char* thename = pStringTable->getString(nToken))
						{
							strcpy_s(DataTypeTemp, thename);
							Dest.Ptr = &DataTypeTemp[0];
							Dest.Type = pStringType;
							return true;
						}
					}
				}
				return false;
			}

			// name
			for (int i = 0; i < NUM_SKILLS; i++)
			{
				int nToken = pSkillMgr->GetNameToken(i);

				if (const char* thename = pStringTable->getString(nToken))
				{
					if (!_stricmp(Index, thename))
					{
						if (bool bActivated = pSkillMgr->IsActivatedSkill(i))
						{
							Dest.DWord = i;
							Dest.Type = pIntType;
							return true;
						}

						break;
					}
				}
			}
		}
		return false;

	case AbilityReady:
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// numeric
			if (int nSkill = GetIntFromString(Index, 0))
			{
				if (bool bActivated = pSkillMgr->IsActivatedSkill(nSkill))
				{
					Dest.DWord = pSkillMgr->IsAvailable(nSkill);
				}
			}
			return true;
		}

		// name
		for (int i = 0; i < NUM_SKILLS; i++)
		{
			int nToken = pSkillMgr->GetNameToken(i);

			if (const char* thename = pStringTable->getString(nToken))
			{
				if (!_stricmp(Index, thename))
				{
					if (bool bActivated = pSkillMgr->IsActivatedSkill(i))
					{
						Dest.DWord = pSkillMgr->IsAvailable(i);
					}
					break;
				}
			}
		}

		return true;

	case RangedReady:
		Dest.DWord = gbRangedAttackReady;
		Dest.Type = pBoolType;
		return true;

	case AltTimerReady:
		Dest.DWord = 1; // this is broken and should be fixed or removed.
		Dest.Type = pBoolType;
		return true;

	case Book:
		Dest.Type = pSpellType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				int nSpell = GetIntFromString(Index, 0) - 1;
				if (nSpell < 0)
					return false;

				if (nSpell < NUM_BOOK_SLOTS)
				{
					if (Dest.Ptr = GetSpellByID(pProfile->SpellBook[nSpell]))
					{
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
			else
			{
				// name
				for (int nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
				{
					if (pProfile->SpellBook[nSpell] != -1)
					{
						if (!_stricmp(GetSpellNameByID(pProfile->SpellBook[nSpell]), Index))
						{
							Dest.DWord = nSpell + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;

	case Spell:
	{
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// Look for spell in our book by ID
				int spellId = GetIntFromString(Index, 0);

				for (int nSpell : pProfile->SpellBook)
				{
					if (nSpell == spellId)
					{
						Dest.Type = pSpellType;
						Dest.Ptr = GetSpellByID(spellId);
						return true;
					}
				}
			}
			else
			{
				// Look for spell in our book by Name like ${Spell}
				if (PSPELL pSpell = GetSpellByName(Index))
				{
					// If we found a spell check if its in the spellbook
					int spellID = pSpell->ID;

					for (int nSpell : pProfile->SpellBook)
					{
						if (nSpell == spellID)
						{
							Dest.Type = pSpellType;
							Dest.Ptr = pSpell;
							return true;
						}
					}

					// Scan the spell book for spells in the same group that match
					// at the substring level
					for (int nSpell : pProfile->SpellBook)
					{
						if (nSpell != -1)
						{
							if (PSPELL pFoundSpell = GetSpellByID(nSpell))
							{
								if (pFoundSpell->SpellGroup == pSpell->SpellGroup
									&& ci_find_substr(pFoundSpell->Name, pSpell->Name) == 0)
								{
									Dest.Ptr = pFoundSpell;
									Dest.Type = pSpellType;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	}

	case ItemReady: {
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		CONTENTS* pCont = nullptr;

		if (pDisplay && pLocalPlayer && Index[0])
		{
			if (IsNumber(Index))
			{
				pCont = FindItemByID(GetIntFromString(Index, 0));
			}
			else
			{
				if (char* pName = Index)
				{
					bool bExact = false;
					if (*pName == '=')
					{
						bExact = true;
						pName++;
					}

					pCont = FindItemByName(pName, bExact);
				}
			}

			if (pCont)
			{
				if (PITEMINFO pIteminf = GetItemFromContents(pCont))
				{
					if (pIteminf->Clicky.TimerID != -1)
					{
						uint32_t timer = GetItemTimer(pCont);
						if (timer == 0)
							Dest.DWord = 1;
					}
					else if (pIteminf->Clicky.SpellID != -1)
					{
						Dest.DWord = 1; // insta-click or instant recast
					}
				}
			}
		}
		return true;
	}

	case BardSongPlaying:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.DWord = 1;
		}
		return true;

	case SpellReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastingWnd && pCastingWnd->IsVisible())
		{
			return true;
		}

		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.DWord = 1;
			return true;
		}

		if (pDisplay && pLocalPlayer && Index[0])
		{
			CDISPLAY* pDisp = pDisplay;

			if (IsNumber(Index))
			{
				// numeric
				int nGem = GetIntFromString(Index, 0) - 1;
				if (nGem < 0 || nGem > NUM_SPELL_GEMS)
					return false;

				if (GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (pDisp->TimeStamp > pChar->pSpawn->SpellGemETA[nGem]
						&& (int)pDisp->TimeStamp > pChar->pSpawn->GetSpellCooldownETA())
					{
						Dest.DWord = 1;
					}
					return true;
				}
			}
			else
			{
				for (int nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
				{
					if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
					{
						if (!_stricmp(Index, pSpell->Name))
						{
							if (pDisp->TimeStamp > pChar->pSpawn->SpellGemETA[nGem]
								&& (int)pDisp->TimeStamp > pChar->pSpawn->GetSpellCooldownETA())
							{
								Dest.DWord = 1;
							}
							return true;
						}
					}
				}
			}
		}
		return true;

	case PetBuff:
		Dest.Type = pSpellType;
		if (!Index[0] || !pPetInfoWnd)
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff > NUM_BUFF_SLOTS)
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
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case Stunned:
		Dest.DWord = (pChar->Stunned == 1);
		Dest.Type = pBoolType;
		return true;

	case LargestFreeInventory:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray)
		{
			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (CONTENTS* pItem = pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK
						&& GetItemFromContents(pItem)->SizeCapacity > Dest.DWord)
					{
						for (int pslot = 0; pslot < (GetItemFromContents(pItem)->Slots); pslot++)
						{
							if (!pItem->Contents.ContainedItems.pItems || !pItem->GetContent(pslot))
							{
								Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
								break; // break the loop for this pack
							}
						}
					}
				}
				else
				{
					Dest.DWord = 4;
					return true;
				}
			}
		}
		return true;
	}

	case FreeInventory:
	{
		int nSize = 0;
		if (Index[0])
		{
			nSize = GetIntFromString(Index, 0);
			if (nSize > 4)
				nSize = 4;
		}

		Dest.DWord = GetFreeInventory(nSize);
		Dest.Type = pIntType;
		return true;
	}

	case Drunk:
		Dest.DWord = pProfile->Drunkenness;
		Dest.Type = pIntType;
		return true;

	case TargetOfTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer && pChar->pSpawn)
		{
			if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->TargetOfTarget))
			{
				return true;
			}
		}
		return false;

	case RaidAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;

				if (Dest.Ptr = (SPAWNINFO*)GetSpawnByID(GetRaidMainAssistTargetID(index)))
				{
					return true;
				}
			}
		}
		return false;

	case GroupAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			if (Dest.Ptr = (SPAWNINFO*)GetSpawnByID(GetGroupMainAssistTargetID()))
			{
				return true;
			}
		}
		return false;

	case RaidMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;
				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->RaidMarkNPC[index]))
				{
					return true;
				}
			}
		}
		return false;

	case GroupMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;

				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->GroupMarkNPC[index]))
				{
					return true;
				}
			}
		}
		return false;

	case STR:
		Dest.DWord = pChar->STR;
		Dest.Type = pIntType;
		return true;

	case STA:
		Dest.DWord = pChar->STA;
		Dest.Type = pIntType;
		return true;

	case AGI:
		Dest.DWord = pChar->AGI;
		Dest.Type = pIntType;
		return true;

	case DEX:
		Dest.DWord = pChar->DEX;
		Dest.Type = pIntType;
		return true;

	case WIS:
		Dest.DWord = pChar->WIS;
		Dest.Type = pIntType;
		return true;

	case INT:
		Dest.DWord = pChar->INT;
		Dest.Type = pIntType;
		return true;

	case CHA:
		Dest.DWord = pChar->CHA;
		Dest.Type = pIntType;
		return true;

	case LCK:
		Dest.DWord = pChar->LCK;
		Dest.Type = pIntType;
		return true;

	case svMagic:
		Dest.DWord = pChar->SaveMagic;
		Dest.Type = pIntType;
		return true;

	case svFire:
		Dest.DWord = pChar->SaveFire;
		Dest.Type = pIntType;
		return true;

	case svCold:
		Dest.DWord = pChar->SaveCold;
		Dest.Type = pIntType;
		return true;

	case svPoison:
		Dest.DWord = pChar->SavePoison;
		Dest.Type = pIntType;
		return true;

	case svDisease:
		Dest.DWord = pChar->SaveDisease;
		Dest.Type = pIntType;
		return true;

	case CurrentWeight:
		Dest.DWord = pChar->CurrWeight;
		Dest.Type = pIntType;
		return true;

	case AAPointsSpent:
		Dest.DWord = pProfile->AAPointsSpent;
		Dest.Type = pIntType;
		return true;

	case AAPointsTotal:
		Dest.DWord = pProfile->AAPointsSpent + pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case AAPointsAssigned:
		Dest.DWord = pProfile->AAPointsAssigned[0];
		Dest.Type = pIntType;
		return true;

	case TributeActive:
		Dest.DWord = *pTributeActive;
		Dest.Type = pBoolType;
		return true;

	case Running:
		Dest.DWord = (*EQADDR_RUNWALKSTATE);
		Dest.Type = pBoolType;
		return true;

	case GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!pChar->pGroupInfo)
			return false;

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}

		// if we have at least one other group member, count self.
		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case TributeTimer:
		Dest.DWord = pChar->TributeTimer / 60 / 100;
		Dest.Type = pTicksType;
		return true;

	case RadiantCrystals:
		Dest.DWord = pChar->RadiantCrystals;
		Dest.Type = pIntType;
		return true;

	case EbonCrystals:
		Dest.DWord = pChar->EbonCrystals;
		Dest.Type = pIntType;
		return true;

	case Shrouded:
		Dest.DWord = pProfile->Shrouded;
		Dest.Type = pBoolType;
		return true;

	case AutoFire:
		Dest.DWord = gAutoFire;
		Dest.Type = pBoolType;
		return true;

	case Language: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		int nLang = 0;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			nLang = GetIntFromString(Index, 0) - 1;
			if (nLang < 0)
				return false;
			strcpy_s(DataTypeTemp, pEverQuest->GetLangDesc(nLang));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			nLang = GetLanguageIDByName(Index) - 1;
		}

		if (nLang < 0 || nLang >= 25)
			return false;
		Dest.DWord = nLang;
		return true;
	}

	case Aura:
		Dest.Type = pAuraType;

		if (!pAuraMgr)
			return false;

		if (pAuraMgr->Auras.IsEmpty())
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int n = GetIntFromString(Index, pAuraMgr->Auras.GetLength() + 1);
				if (n > pAuraMgr->Auras.GetLength())
					return false;
				n--;
				Dest.Ptr = &pAuraMgr->Auras[n];
				Dest.HighPart = n;
				return true;
			}

			for (int n = 0; n < pAuraMgr->Auras.GetLength(); n++)
			{
				if (!_strnicmp(Index, pAuraMgr->Auras[n].Name, strlen(Index)))
				{
					Dest.Ptr = &pAuraMgr->Auras[n];
					Dest.HighPart = n;
					return true;
				}
			}
		}
		else
		{
			Dest.Ptr = &pAuraMgr->Auras[0];
			Dest.HighPart = 0;
			return true;
		}
		return false;

	case LAMarkNPC:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LANPCHealth:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LADelegateMA:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LADelegateMarkNPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LAInspectBuffs:
		Dest.DWord = 2;
		Dest.Type = pIntType;
		return true;

	case LASpellAwareness:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LAOffenseEnhancement:
		Dest.DWord = 5;
		Dest.Type = pIntType;
		return true;

	case LAManaEnhancement:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LAHealthEnhancement:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LAHealthRegen:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case LAFindPathPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case LAHoTT:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case ActiveFavorCost:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (*pTributeActive)
		{
			Dest.Int = pEQMisc->GetActiveFavorCost();
			return true;
		}
		return false;

	case CombatState:
		Dest.Type = pStringType;
		if (!pPlayerWnd)
			return false;

		switch (pPlayerWnd->CombatState)
		{
		case eCombatState_Combat:
			if (pPlayerWnd->GetChildItem("PW_CombatStateAnim"))
			{
				strcpy_s(DataTypeTemp, "COMBAT");
				break;
			}
			strcpy_s(DataTypeTemp, "NULL");
			break;

		case eCombatState_Debuff:
			strcpy_s(DataTypeTemp, "DEBUFFED");
			break;

		case eCombatState_Timer:
			strcpy_s(DataTypeTemp, "COOLDOWN");
			break;

		case eCombatState_Standing:
			strcpy_s(DataTypeTemp, "ACTIVE");
			break;

		case eCombatState_Regen:
			strcpy_s(DataTypeTemp, "RESTING");
			break;

		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case svCorruption:
		Dest.DWord = pChar->SaveCorruption;
		Dest.Type = pIntType;
		return true;

	case svPrismatic:
		Dest.DWord = (pChar->SaveMagic + pChar->SaveFire + pChar->SaveCold + pChar->SavePoison + pChar->SaveDisease) / 5;
		Dest.Type = pIntType;
		return true;

	case svChromatic: {
		int lowSave;
		lowSave = pChar->SaveMagic;
		if (lowSave > pChar->SaveFire)
			lowSave = pChar->SaveFire;
		if (lowSave > pChar->SaveCold)
			lowSave = pChar->SaveCold;
		if (lowSave > pChar->SavePoison)
			lowSave = pChar->SavePoison;
		if (lowSave > pChar->SaveDisease)
			lowSave = pChar->SaveDisease;

		Dest.Int = lowSave;
		Dest.Type = pIntType;
		return true;
	}

	case Doubloons:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DOUBLOONS);
		Dest.Type = pIntType;
		return true;

	case Orux:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ORUX);
		Dest.Type = pIntType;
		return true;

	case Phosphenes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHENES);
		Dest.Type = pIntType;
		return true;

	case Phosphites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHITES);
		Dest.Type = pIntType;
		return true;

	case Faycites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FAYCITES);
		Dest.Type = pIntType;
		return true;

	case Chronobines:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CHRONOBINES);
		Dest.Type = pIntType;
		return true;

	case Commemoratives:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_COMMEMORATIVE_COINS);
		Dest.Type = pIntType;
		return true;

	case Nobles:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_NOBLES);
		Dest.Type = pIntType;
		return true;

	case Fists:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FISTSOFBAYLE);
		Dest.Type = pIntType;
		return true;

	case EnergyCrystals:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENERGYCRYSTALS);
		Dest.Type = pIntType;
		return true;

	case PiecesofEight:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PIECESOFEIGHT);
		Dest.Type = pIntType;
		return true;

	case SilverTokens:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SILVERTOKENS);
		Dest.Type = pIntType;
		return true;

	case GoldTokens:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_GOLDTOKENS);
		Dest.Type = pIntType;
		return true;

	case McKenzie:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MCKENZIE);
		Dest.Type = pIntType;
		return true;

	case Bayle:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BAYLE);
		Dest.Type = pIntType;
		return true;

	case Reclamation:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_RECLAMATION);
		Dest.Type = pIntType;
		return true;

	case Brellium:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRELLIUM);
		Dest.Type = pIntType;
		return true;

	case Motes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MOTES);
		Dest.Type = pIntType;
		return true;

	case RebellionChits:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REBELLIONCHITS);
		Dest.Type = pIntType;
		return true;

	case DiamondCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DIAMONDCOINS);
		Dest.Type = pIntType;
		return true;

	case BronzeFiats:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRONZEFIATS);
		Dest.Type = pIntType;
		return true;

	case Voucher:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VOUCHER);
		Dest.Type = pIntType;
		return true;

	case VeliumShards:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VELIUMSHARDS);
		Dest.Type = pIntType;
		return true;

	case CrystallizedFear:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDFEAR);
		Dest.Type = pIntType;
		return true;

	case ShadowStones:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SHADOWSTONES);
		Dest.Type = pIntType;
		return true;

	case DreadStones:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DREADSTONES);
		Dest.Type = pIntType;
		return true;

	case MarksOfValor:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MARKSOFVALOR);
		Dest.Type = pIntType;
		return true;

	case MedalsOfHeroism:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MEDALSOFHEROISM);
		Dest.Type = pIntType;
		return true;

	case RemnantOfTranquility:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REMNANTSOFTRANQUILITY);
		Dest.Type = pIntType;
		return true;

	case BifurcatedCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BIFURCATEDCOIN);
		Dest.Type = pIntType;
		return true;

	case AdoptiveCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ADOPTIVE);
		Dest.Type = pIntType;
		return true;

	case SathirsTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SATHIRSTRADEGEMS);
		Dest.Type = pIntType;
		return true;

	case AncientSebilisianCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTSEBILISIANCOINS);
		Dest.Type = pIntType;
		return true;

	case BathezidTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BATHEZIDTRADEGEMS);
		Dest.Type = pIntType;
		return true;

	case AncientDraconicCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTDRACONICCOIN);
		Dest.Type = pIntType;
		return true;

	case FetterredIfritCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FETTERREDIFRITCOINS);
		Dest.Type = pIntType;
		return true;

	case EntwinedDjinnCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENTWINEDDJINNCOINS);
		Dest.Type = pIntType;
		return true;

	case CrystallizedLuck:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDLUCK);
		Dest.Type = pIntType;
		return true;

	case Fellowship:
		Dest.Type = pFellowshipType;
		if (pChar->pSpawn)
		{
			Dest.Ptr = &pChar->pSpawn->Fellowship;
			return true;
		}
		return false;

	case Downtime:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pChar->DowntimeStamp)
			Dest.DWord = ((pChar->Downtime - (GetFastTime() - pChar->DowntimeStamp)) / 6) + 1;
		return true;

		// returns combined number of spell and damage "absorbment"
		// should probably split these into spell vs melee
	case Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (SPELL* pSpell = GetSpellByID(buff.SpellID))
			{
				if (pSpell->SpellType != 0)
				{
					int slots = GetSpellNumEffects(pSpell);

					for (int i = 0; i < slots; i++)
					{
						int attrib = GetSpellAttrib(pSpell, i);

						if (IsDamageAbsorbSPA(attrib))
						{
							for (auto buffData : buff.SlotData)
							{
								if (buffData.Slot == i)
								{
									Dest.DWord += buffData.Value;
								}
							}
						}
					}
				}
			}
		}
		return true;

		// this case adds all resist Counters and returns that, why is this useful?
		// should we split these into 4? one for each debuff?
	case TotalCounters:
		Dest.DWord = GetMyTotalSpellCounters();
		Dest.Type = pIntType;
		return true;

	case CountersDisease:
		Dest.DWord += GetMySpellCounters(SPA_DISEASE);
		Dest.Type = pIntType;
		return true;

	case CountersPoison:
		Dest.DWord = GetMySpellCounters(SPA_POISON);
		Dest.Type = pIntType;
		return true;

	case CountersCurse:
		Dest.DWord = GetMySpellCounters(SPA_CURSE);
		Dest.Type = pIntType;
		return true;

	case CountersCorruption:
		Dest.DWord = GetMySpellCounters(SPA_CORRUPTION);
		Dest.Type = pIntType;
		return true;

	case Mercenary:
		Dest.Type = pMercenaryType;
		if (pMercInfo && pMercInfo->MercSpawnId)
		{
			Dest.Ptr = GetSpawnByID(pMercInfo->MercSpawnId);
			return true;
		}
		else if (pMercInfo)
		{
			// FIXME: Do not ZeroMemory a SPAWNINFO
			ZeroMemory(&MercenarySpawn, sizeof(MercenarySpawn));

			if (pMercInfo->HaveMerc == 1)
			{
				switch (pMercInfo->MercState)
				{
				case 0:
					strcpy_s(MercenarySpawn.Name, "DEAD");
					break;

				case 1:
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					break;

				default:
					strcpy_s(MercenarySpawn.Name, "NULL");
					break;
				}

				Dest.Ptr = &MercenarySpawn;
				return true;
			}
			else
			{
				if (pMercInfo->MercenaryCount >= 1)
				{
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
				else
				{
					strcpy_s(MercenarySpawn.Name, "NULL");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
			}
		}

		return false;

	case XTargetSlots:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			Dest.DWord = xtm->XTargetSlots.Count;
		}
		return true;

	case XTAggroCount:
		Dest.DWord = 0;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			int AggroPct = 100;
			if (IsNumber(Index))
			{
				AggroPct = GetIntFromString(Index, AggroPct);
				if (AggroPct < 1 || AggroPct > 100)
				{
					AggroPct = 100;
				}
			}

			if (pAggroInfo)
			{
				for (int i = 0; i < xtm->XTargetSlots.Count; i++)
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					uint32_t spID = xts.SpawnID;

					if (spID && xts.xTargetType == XTARGET_AUTO_HATER)
					{
						if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
						{
							if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;

							if (pSpawn->Type == SPAWN_NPC)
							{
								uint16_t aggropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;

								if (aggropct < AggroPct)
								{
									Dest.DWord++;
								}
							}
						}
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case XTHaterCount:
		Dest.DWord = 0;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			if (pAggroInfo)
			{
				for (int i = 0; i < xtm->XTargetSlots.Count; i++)
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					uint32_t spID = xts.SpawnID;

					if (spID && xts.xTargetType == XTARGET_AUTO_HATER)
					{
						if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
						{
							if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;

							if (pSpawn->Type == SPAWN_NPC)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case XTarget:
		Dest.DWord = 0;
		Dest.Type = pXTargetType;

		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			if (xtm->XTargetSlots.Count)
			{
				if (Index[0])
				{
					if (IsNumber(Index))
					{
						int index = GetIntFromString(Index, 0) - 1;
						if (index >= 0 && index < (int)xtm->XTargetSlots.Count)
						{
							Dest.DWord = index;
							Dest.Type = pXTargetType;
							return true;
						}
					}
					else
					{
						for (int n = 0; n < xtm->XTargetSlots.Count; n++)
						{
							XTARGETSLOT& xts = xtm->XTargetSlots[n];

							if (xts.xTargetType && xts.XTargetSlotStatus && !_stricmp(Index, xts.Name))
							{
								Dest.DWord = n;
								Dest.Type = pXTargetType;
								return true;
							}
						}
					}
				}
				else
				{
					int count = 0;
					for (int n = 0; n < xtm->XTargetSlots.Count; n++)
					{
						XTARGETSLOT& xts = xtm->XTargetSlots[n];
						if (xts.xTargetType && xts.XTargetSlotStatus)
						{
							count++;
						}
					}

					Dest.DWord = count;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;

	case Haste: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// TODO: Is this GetCharInfo Redundant? Remove if so.
		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			// TODO: Replace magic constant with enum
			Dest.DWord = pCharData->TotalEffect(0xb, true, 0, true, true);
			return true;
		}
		return false;
	}

	case SPA: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// TODO: Is this GetCharInfo Redundant? Remove if so.
			if (CHARINFO* pCharInfo = GetCharInfo())
			{
				if (pCharInfo->vtable2) {
					Dest.DWord = pCharData->TotalEffect(GetIntFromString(Index, 0), true, 0, true, true);
					return true;
				}
			}
		}
		return false;
	}

	case MercenaryStance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (int n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, eMercenaryStanceName));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case GemTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// number
			int nGem = GetIntFromString(Index, 0) - 1;
			if (nGem < 0)
				return false;

			if (nGem < NUM_SPELL_GEMS)
			{
				if (GetMemorizedSpell(nGem) != 0xFFFFFFFF)
				{
					Dest.UInt64 = GetSpellGemTimer(nGem);
					return true;
				}
			}
		}
		else
		{
			// name
			for (int nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.UInt64 = GetSpellGemTimer(nGem);
						return true;
					}
				}
			}
		}
		return false;

	case HaveExpansion:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nExpansion = GetIntFromString(Index, 0);
			if (nExpansion > NUM_EXPANSIONS)
				return true;
			Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(nExpansion);
		}
		else
		{
			for (int n = 0; n < NUM_EXPANSIONS; n++)
			{
				if (!_stricmp(Index, szExpansions[n]))
				{
					Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(n + 1);
					return true;
				}
			}
		}
		return true;

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

	case AggroLock:
		Dest.Type = pSpawnType;
		if (pAggroInfo && pAggroInfo->AggroLockID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroLockID);
			return true;
		}
		return false;

	case ZoneBound:
		Dest.Type = pZoneType;
		if (pProfile->BoundLocations[0].ZoneBoundID)
		{
			Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pProfile->BoundLocations[0].ZoneBoundID];
			return true;
		}
		return false;

	case ZoneBoundX:
		Dest.Type = pFloatType;
		Dest.Float = pProfile->BoundLocations[0].ZoneBoundX;
		return true;

	case ZoneBoundY:
		Dest.Type = pFloatType;
		Dest.Float = pProfile->BoundLocations[0].ZoneBoundY;
		return true;

	case ZoneBoundZ:
		Dest.Type = pFloatType;
		Dest.Float = pProfile->BoundLocations[0].ZoneBoundZ;
		return true;

	case PctMercAAExp:
		// this is how it looks like the client is doing it in the disasm...
		Dest.Float = (float)((pChar->MercAAExp + 5) / 10);
		Dest.Type = pFloatType;
		return true;

	case MercAAExp:
		Dest.Int64 = pChar->MercAAExp;
		Dest.Type = pInt64Type;
		return true;

	case Krono:
		Dest.DWord = pChar->Krono;
		Dest.Type = pIntType;
		return true;

	case Subscription:
		strcpy_s(DataTypeTemp, "UNKNOWN");

		// TODO: Fix this. Its a struct not an int*
		if (EQADDR_SUBSCRIPTIONTYPE && *EQADDR_SUBSCRIPTIONTYPE)
		{
			int dwsubtype = *(int*)EQADDR_SUBSCRIPTIONTYPE;
			if (dwsubtype)
			{
				uint8_t subtype = *(uint8_t*)dwsubtype;
				switch (subtype)
				{
				case MembershipFreeToPlay:
					strcpy_s(DataTypeTemp, "FREE");
					break;
				case MembershipSilver:
					strcpy_s(DataTypeTemp, "SILVER");
					break;
				case MembershipGold:
					strcpy_s(DataTypeTemp, "GOLD");
					break;
				}
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case AltCurrency:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			Dest.DWord = pPlayerPointManager->GetAltCurrency(GetIntFromString(Index, 0));
			return true;
		}
		else
		{
			int nCurrency = GetCurrencyIDByName(Index);
			if (nCurrency < 0)
				return false;
			Dest.DWord = pPlayerPointManager->GetAltCurrency(nCurrency);
			return true;
		}
		return false;

	case Slowed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_HASTE, false)) != -1) // Slowed
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Rooted:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_ROOT, false)) != -1) // Root
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Mezzed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_ENTHRALL, false)) != -1)//Entrall
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Crippled:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Disempowering")) != -1)
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Maloed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage))) != -1)
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Tashed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Resist Debuffs", 1 << Enchanter)) != -1)
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Snared:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_MOVEMENT_RATE, false)) != -1) // Movement Rate
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Hasted:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_HASTE, true)) != -1) // Haste
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case LastZoned:
		Dest.UInt64 = LastEnteredZone;
		Dest.Type = pTimeStampType;
		return true;

	case Zoning: {
		if (LastEnteredZone == 0) // when people reload mq
		{
			LastEnteredZone = MQGetTickCount64();
			OldLastEnteredZone = LastEnteredZone;
		}

		// FIXME: SIDE EFFECTS
		bool bZoning = false;
		if (OldLastEnteredZone != LastEnteredZone)
		{
			OldLastEnteredZone = LastEnteredZone;
			bZoning = true;
		}

		Dest.DWord = bZoning;
		Dest.Type = pBoolType;
		return true;
	}

	case DSed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_DAMAGE_SHIELD, true)) != -1) // Damage Shield
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case RevDSed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_IRONMAIDEN, true)) != -1) // Reverse Damage Shield
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Charmed:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_CHARM, false)) != -1) // Charm
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Aego:
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
				{
					if (IsAegoSpell(pSpell))
					{
						Dest.Type = pBuffType;
						Dest.Ptr = &pProfile->Buff[nBuff];
						return true;
					}
				}
			}
		}
		return false;

	case Skin:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 46)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Focus:
		{
			int nBuff = 0;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Shaman)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 87)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Shaman, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Regen:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_HP, true)) != -1) // HP Regen
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if ((((EQ_Spell*)pSpell)->SpellAffectBase(SPA_HP) > 0) && (!IsSpellUsableForClass(pSpell, 1 << Beastlord)))
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffBySPA(SPA_HP, true, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Diseased:
	case Poisoned:
	case Cursed:
	case Corrupted:
		{
			int spa = 0;
			switch (static_cast<CharacterMembers>(pMember->ID))
			{
			case Diseased: spa = SPA_DISEASE; break;
			case Poisoned: spa = SPA_POISON; break;
			case Cursed: spa = SPA_CURSE; break;
			case Corrupted: spa = SPA_CORRUPTION; break;
			}

			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(spa, false)) != -1)
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
			if ((nBuff = GetSelfShortBuffBySPA(spa, false)) != -1)
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->ShortBuff[nBuff];
				return true;
			}
			return false;
		}

	case Symbol:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Cleric)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 112)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Cleric, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Clarity:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_MANA, true)) != -1) // Mana Regen
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if ((((EQ_Spell*)pSpell)->SpellAffectBase(SPA_MANA) > 0) && (IsSpellUsableForClass(pSpell, 1 << Enchanter)))
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffBySPA(SPA_MANA, true, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Pred:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(95, 1 << Ranger)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 7)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((Dest.Int = GetSelfBuffByCategory(95, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Strength:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 47)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Brells:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Paladin)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 47)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Paladin, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case SV:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 59)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case SE:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 44)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case HybridHP:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 46)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Growth:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 141)
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case Shining:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(125, 1 << Cleric)) != -1)
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pProfile->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 62)
						{
							if (((EQ_Spell*)pSpell)->SpellAffectBase(SPA_MELEE_GUARD))
							{
								Dest.Type = pBuffType;
								Dest.Ptr = &pProfile->Buff[nBuff];
								return true;
							}
						}
					}

					if ((nBuff = GetSelfBuffByCategory(125, 1 << Cleric, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

	case InInstance:
		Dest.DWord = 0;
		if (pChar->pSpawn)
		{
			if (int zoneid = pChar->pSpawn->GetZoneID())
			{
				if (uint16_t instance = HIWORD(zoneid))
					Dest.DWord = 1;
			}
		}
		Dest.Type = pBoolType;
		return true;

	case Instance:
		Dest.DWord = 0;
		if (pChar->pSpawn)
			Dest.DWord = HIWORD(pChar->pSpawn->GetZoneID());
		Dest.Type = pIntType;
		return true;

	case MercListInfo: {
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, pMercInfo->MercenaryCount + 1);
			if (nIndex > pMercInfo->MercenaryCount)
				return false;

			std::map<int, MercDesc> mercDescMap;
			GetAllMercDesc(mercDescMap);

			if (mercDescMap.find(nIndex - 1) != mercDescMap.end())
			{
				strcpy_s(DataTypeTemp, mercDescMap[nIndex - 1].Type.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			std::map<int, MercDesc> descmap;
			GetAllMercDesc(descmap);

			for (auto& [index, desc] : descmap)
			{
				if (!_stricmp(Index, desc.Type.c_str()))
				{
					Dest.DWord = index + 1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}

	case UseAdvancedLooting:
		Dest.DWord = pChar->UseAdvancedLooting;
		Dest.Type = pBoolType;
		return true;

	case SpellInCooldown:
		Dest.DWord = (int)((CDISPLAY*)pDisplay)->TimeStamp <= ((SPAWNINFO*)pLocalPlayer)->GetSpellCooldownETA();
		Dest.Type = pBoolType;
		return true;

	case AssistComplete:
		Dest.DWord = gbAssistComplete == AS_AssistReceived;
		Dest.Type = pBoolType;
		return true;

	case NumGems:
		Dest.DWord = 8;
		if (pCastSpellWnd)
		{
			char szWnd[32] = { 0 };
			for (int i = 8; i < NUM_SPELL_GEMS; i++)
			{
				sprintf_s(szWnd, "CSPW_Spell%d", i);
				if (CXWnd* wnd = pCastSpellWnd->GetChildItem(szWnd))
				{
					if (wnd->IsVisible() == 1)
					{
						Dest.DWord++;
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case GuildID:
		Dest.UInt64 = pChar->GuildID;
		Dest.Type = pInt64Type;
		return true;

	case ExpansionFlags:
		Dest.DWord = pChar->ExpansionFlags;
		Dest.Type = pIntType;
		return true;

	case BoundLocation:
		Dest.DWord = 0;
		Dest.Type = pWorldLocationType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 4)
				index = 4;
			Dest.DWord = index;
			return true;
		}
		return false;

	case AutoSkill:
		Dest.Type = pSkillType;
		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;

			int skillid = gAutoSkill.Skill[index];
			if (skillid > 0 && skillid < NUM_SKILLS)
			{
				Dest.Ptr = &pSkillMgr->pSkill[skillid];
				return true;
			}
		}
		return false;

	case BaseSTR:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseSTR;
		return true;

	case BaseSTA:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseSTA;
		return true;

	case BaseAGI:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseAGI;
		return true;

	case BaseDEX:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseDEX;
		return true;

	case BaseWIS:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseWIS;
		return true;

	case BaseINT:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseINT;
		return true;

	case BaseCHA:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseCHA;
		return true;

	case Beneficial:
		for (int i = 0; i < NUM_BUFF_SLOTS; i++)
		{
			if ((pProfile->Buff[i].SpellID == -1) || (pProfile->Buff[i].SpellID == 0))
				continue;

			if (SPELL* pSpell = GetSpellByID(pProfile->Buff[i].SpellID))
			{
				if (pSpell->SpellType != 0)
				{
					Dest.Int = i;
					Dest.Type = pTargetBuffType;
					return true;
				}
			}
		}
		return false;

	case CursorKrono:
		Dest.DWord = pChar->CursorKrono;
		Dest.Type = pIntType;
		return true;

	case MercAAPoints:
		Dest.DWord = pChar->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case MercAAPointsSpent:
		Dest.DWord = pChar->MercAAPointsSpent;
		Dest.Type = pIntType;
		return true;

	case Bandolier:
		Dest.DWord = 0;
		Dest.Type = pBandolierType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				index = 0;
			if (index > 19)
				index = 19;

			Dest.DWord = index;
			return true;
		}
		else
		{
			for (int index = 0; index < 20; index++)
			{
				if (!_stricmp(Index, pProfile->Bandolier[index].Name))
				{
					Dest.DWord = index;
					return true;
				}
			}
		}
		return false;

	case Feared:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_FEAR, false)) != -1) // Feared
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Silenced:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_SILENCE, false)) != -1) // Silenced
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}
		}
		return false;

	case Invulnerable:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_INVULNERABILITY, false)) != -1) // Invulnerable
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->Buff[nBuff];
				return true;
			}

			if ((nBuff = GetSelfShortBuffBySPA(SPA_INVULNERABILITY, false)) != -1) // Invulnerable
			{
				Dest.Type = pBuffType;
				Dest.Ptr = &pProfile->ShortBuff[nBuff];
				return true;
			}
		}
		return false;

	case Dotted:
		{
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(SPA_HP, false)) != -1) // HP Mod
			{
				int slotnum = nBuff;
				while (slotnum < NUM_BUFF_SLOTS)
				{
					if (SPELL* pSpell = GetSpellByID(pTargetWnd->BuffSpellID[nBuff]))
					{
						if (((EQ_Spell*)pSpell)->IsDetrimentalSpell() && ((EQ_Spell*)pSpell)->IsDoTSpell())
						{
							Dest.Type = pBuffType;
							Dest.Ptr = &pProfile->Buff[nBuff];
							return true;
						}
					}

					if ((nBuff = GetTargetBuffBySPA(SPA_HP, false, ++slotnum)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;

		//end of MQ2CharacterType
	}
	return false;
}


