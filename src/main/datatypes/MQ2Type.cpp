#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;
MQ2Type::MQ2Type(const char* newName)
{
	strcpy_s(TypeName, newName);
	m_owned = AddMQ2Type(*this);
}

MQ2Type::~MQ2Type()
{
	if (m_owned)
	{
		RemoveMQ2Type(*this);
	}
}

void MQ2Type::InitializeMembers(MQTypeMember* memberArray)
{
	for (int i = 0; memberArray[i].ID; i++)
	{
		AddMember(memberArray[i].ID, memberArray[i].Name);
	}
}

const char* MQ2Type::GetName() const
{
	if (TypeName)
		return &TypeName[0];

	return nullptr;
}

const char* MQ2Type::GetMemberName(int ID) const
{
	for (const auto& pMember : Members)
	{
		if (pMember && pMember->ID == ID)
		{
			return &pMember->Name[0];
		}
	}

	return nullptr;
}

bool MQ2Type::GetMemberID(const char* Name, int& result) const
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return false;

	int index = iter->second;
	result = Members[index]->ID;
	return true;
}

mq::MQTypeMember* MQ2Type::FindMember(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return nullptr;

	int index = MemberMap[Name];
	return Members[index].get();
}

mq::MQTypeMember* MQ2Type::FindMethod(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return nullptr;

	int index = iter->second;
	return Methods[index].get();
}

bool MQ2Type::AddMember(int id, const char* Name)
{
	std::scoped_lock lock(m_mutex);

	if (MemberMap.find(Name) != MemberMap.end())
		return false;

	// find an unused index from members.
	int index = -1;
	for (size_t i = 0; i < Members.size(); ++i)
	{
		if (Members[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		Members.emplace_back();
		index = Members.size() - 1;
	}

	auto pMember = std::make_unique<MQTypeMember>();
	pMember->Name = Name;
	pMember->ID = id;
	pMember->Type = 0;
	Members[index] = std::move(pMember);
	MemberMap[Name] = index;
	return true;
}

bool MQ2Type::RemoveMember(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MemberMap.find(Name);
	if (iter == MemberMap.end())
		return false;

	int index = iter->second;
	MemberMap.erase(iter);

	if (index < 0)
		return false;
	Members[index].reset();
	return true;
}

bool MQ2Type::AddMethod(int ID, const char* Name)
{
	std::scoped_lock lock(m_mutex);

	if (MethodMap.find(Name) != MethodMap.end())
		return false;

	// find an unused index from members.
	int index = -1;
	for (size_t i = 0; i < Methods.size(); ++i)
	{
		if (Methods[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		Methods.emplace_back();
		index = Methods.size() - 1;
	}

	auto pMethod = std::make_unique<MQTypeMember>();
	pMethod->Name = Name;
	pMethod->ID = ID;
	pMethod->Type = 1;
	Methods[index] = std::move(pMethod);
	MethodMap[Name] = index;
	return true;
}

bool MQ2Type::RemoveMethod(const char* Name)
{
	std::scoped_lock lock(m_mutex);

	auto iter = MethodMap.find(Name);
	if (iter == MethodMap.end())
		return false;

	int index = iter->second;
	MethodMap.erase(iter);

	if (index < 0)
		return false;
	Methods[index].reset();
	return true;
}