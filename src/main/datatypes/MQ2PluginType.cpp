#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2PluginType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	MQPlugin* pPlugin = reinterpret_cast<MQPlugin*>(VarPtr.Ptr);
	if (!pPlugin)
		return false;

	MQTypeMember* pMember = MQ2PluginType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<PluginMembers>(pMember->ID))
	{
	case Name:
		Dest.Ptr = pPlugin->szFilename;
		Dest.Type = pStringType;
		return true;

	case Version:
		Dest.Float = pPlugin->fpVersion;
		Dest.Type = pFloatType;
		return true;

	default: break;
	}

	return false;
}
