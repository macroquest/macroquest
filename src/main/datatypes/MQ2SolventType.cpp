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

enum class SolventTypeMembers
{
	Name = 1,
	ID,
	Item,
	Count,
};

MQ2SolventType::MQ2SolventType() : MQ2Type("solventtype")
{
	ScopedTypeMember(SolventTypeMembers, Name);
	ScopedTypeMember(SolventTypeMembers, ID);
	ScopedTypeMember(SolventTypeMembers, Item);
	ScopedTypeMember(SolventTypeMembers, Count);
}

// FIXME: Move this stuff to common location for items
static std::string to_roman(uint32_t value)
{
	struct romandata_t { unsigned int value; char const* numeral; };
	static const struct romandata_t romandata[] =
	{
		{ 1000, "M"}, { 900, "CM"},
		{  500, "D"}, { 400, "CD"},
		{  100, "C"}, {  90, "XC"},
		{   50, "L"}, {  40, "XL"},
		{   10, "X"}, {   9, "IX"},
		{    5, "V"}, {   4, "IV"},
		{    1, "I"},
		{    0, nullptr} // end marker
	};

	std::string result;
	for (const romandata_t* current = romandata; current->value > 0; ++current)
	{
		while (value >= current->value)
		{
			result += current->numeral;
			value -= current->value;
		}
	}
	return result;
}

static std::string GetAugmentDistillerNameByRank(int rank)
{
	if (rank < 0)
		return "Perfected Augmentation Distiller";

	return fmt::format("Class {} Augmentation Distiller", to_roman(rank));
}

constexpr int PerfectedAugmentationDistillerID = 52023;

// This information can be collected from ItemDistillerDefs.txt in the Resources
// folder of the EverQuest install directory
static std::pair<int, int> ItemDistillerDefs[] = {
	{ 47001, 1 },
	{ 47002, 2 },
	{ 47003, 3 },
	{ 47004, 4 },
	{ 47005, 5 },
	{ 47006, 6 },
	{ 47007, 7 },
	{ 47008, 8 },
	{ 47009, 9 },
	{ 47010, 10 },
	{ 47011, 11 },
	{ 47012, 12 },
	{ 47013, 13 },
	{ 47014, 14 },
	{ 47015, 15 },
	{ 47016, 16 },
	{ 47017, 17 },
	{ 47018, 18 },
	{ 47019, 19 },
	{ 47020, 20 },
	{ 47021, 21 },
	{ PerfectedAugmentationDistillerID, -1 },
};


bool MQ2SolventType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	int rank = VarPtr.DWord;
	int itemid = PerfectedAugmentationDistillerID;

	if (rank != -1)
	{
		auto iter = std::find_if(std::begin(ItemDistillerDefs), std::end(ItemDistillerDefs),
			[rank](const std::pair<int, int>& value) { return value.second == rank; });
		if (iter != std::end(ItemDistillerDefs)) itemid = iter->first;
	}

	MQTypeMember* pMember = MQ2SolventType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<SolventTypeMembers>(pMember->ID))
	{
	case SolventTypeMembers::Name:
		strcpy_s(DataTypeTemp, GetAugmentDistillerNameByRank(rank).c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case SolventTypeMembers::ID:
		Dest.DWord = itemid;
		Dest.Type = pIntType;
		return true;

	case SolventTypeMembers::Item: // do we have this solvent?
		Dest = pItemType->MakeTypeVar(FindItemByID(itemid));
		return true;

	case SolventTypeMembers::Count: // do we have this solvent and if so how many?
		Dest.DWord = FindItemCountByID(itemid);
		Dest.Type = pIntType;
		return true;

	default: break;
	};

	return false;
}

bool MQ2SolventType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(DataTypeTemp, GetAugmentDistillerNameByRank(VarPtr.DWord).c_str());
	return true;
}

} // namespace mq::datatypes
