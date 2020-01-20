#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2TargetBuffType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	if (VarPtr.Int == -1)
		return false;

	int buffid = pTargetWnd->BuffSpellID[VarPtr.Int];
	if (buffid <= 0)
		return false;

	MQTypeMember* pMember = MQ2TargetBuffType::FindMember(Member);
	if (!pMember)
	{
		if (SPELL* pSpell = GetSpellByID(buffid))
		{
			return pSpellType->GetMember(*(MQVarPtr*)& pSpell, Member, Index, Dest);
		}
		return false;
	}

	static char Temp[128];
	switch (static_cast<TargetBuffMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = (DWORD)&pTargetWnd->BuffSpellID[VarPtr.Int];
		Dest.Type = pIntType;
		return true;

	case xIndex:
		Dest.Int = VarPtr.Int;
		Dest.Type = pIntType;
		return true;

	case Duration:
		Dest.UInt64 = pTargetWnd->BuffTimer[VarPtr.Int];
		Dest.Type = pTimeStampType;
		return true;
	}

	return false;
}

