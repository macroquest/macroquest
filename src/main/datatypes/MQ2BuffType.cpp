#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2BuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	SPELLBUFF* pBuff = static_cast<SPELLBUFF*>(VarPtr.Ptr);
	if (!pBuff)
		return false;
	if (pBuff->SpellID <= 0)
		return false;

	//----------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2BuffType::FindMethod(Member))
	{
		switch (static_cast<BuffMethods>(pMethod->ID))
		{
		case Remove:
			if (SPELL* pSpell = GetSpellByID(pBuff->SpellID))
			{
				RemoveBuff((SPAWNINFO*)pLocalPlayer, pSpell->Name);
				return true;
			}
			break;
		}
		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2BuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(pBuff->SpellID))
		{
			MQVarPtr data;
			data.Ptr = pSpell;

			return pSpellType->GetMember(data, Member, Index, Dest);
		}

		return false;
	}

	static char Temp[128];
	switch (static_cast<BuffMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;

	case ID:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (GetBuffID(pBuff, Dest.Int))
			return true;
		if (GetShortBuffID(pBuff, Dest.Int))
			return true;

		return false;

	case Level:
		Dest.DWord = pBuff->Level;
		Dest.Type = pIntType;
		return true;

	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pBuff->SpellID))
		{
			return true;
		}
		return false;

	case Mod:
		Dest.Float = pBuff->Modifier;
		Dest.Type = pFloatType;
		if (Dest.Float != 1.0f)
		{
			return true;
		}
		return false;

	case Duration:
		Dest.UInt64 = GetSpellBuffTimer(pBuff->SpellID);
		Dest.Type = pTimeStampType;
		return true;

	case Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (SPELL* pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType != 0)
			{
				int slots = GetSpellNumEffects(pSpell);
				for (int i = 0; i < slots; i++)
				{
					int attrib = GetSpellAttrib(pSpell, i);

					if (IsDamageAbsorbSPA(attrib))
					{
						for (auto& slotData : pBuff->SlotData)
						{
							if (slotData.Slot == i)
							{
								Dest.DWord += slotData.Value;
							}
						}
					}
				}
				return true;
			}
		}
		return false;

	case TotalCounters:
		Dest.DWord = GetTotalSpellCounters(pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersDisease:
		Dest.DWord = GetSpellCounters(SPA_DISEASE, pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersPoison:
		Dest.DWord = GetSpellCounters(SPA_POISON, pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersCurse:
		Dest.DWord = GetSpellCounters(SPA_CURSE, pBuff);
		Dest.Type = pIntType;
		return true;

	case CountersCorruption:
		Dest.DWord = GetSpellCounters(SPA_CURSE, pBuff);
		Dest.Type = pIntType;
		return true;

	case HitCount:
		Dest.DWord = pBuff->HitCount;
		Dest.Type = pIntType;
		return true;

	default: break;
	}

	return false;
}

