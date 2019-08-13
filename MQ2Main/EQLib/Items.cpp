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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "Items.h"

namespace eqlib {

//============================================================================
// new form
//============================================================================

ItemClient* ItemClient::GetContent(uint32_t index)
{
	if (Contents.ContainedItems.pItems && Contents.ContainedItems.Capacity)
	{
		if (index < Contents.ContainedItems.Capacity)
		{
			// TODO: Convert CONTENTS to ItemClient
			return (ItemClient*)Contents.ContainedItems.pItems->Item[index];
		}
	}

	return nullptr;
}

ItemGlobalIndex ItemClient::GetGlobalIndex() const
{
	return this->GlobalIndex;
}

//============================================================================
// old form
//============================================================================

CONTENTS* CONTENTS::GetContent(unsigned int index)
{
	if (Contents.ContainedItems.pItems && Contents.ContainedItems.Capacity)
	{
		if (index < Contents.ContainedItems.Capacity)
		{
			return Contents.ContainedItems.pItems->Item[index];
		}
	}

	return nullptr;
}

ItemGlobalIndex CONTENTS::GetGlobalIndex() const
{
	return this->GlobalIndex;
}

} // namespace eqlib