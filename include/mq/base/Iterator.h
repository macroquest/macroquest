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

#pragma once

namespace mq {

template <typename IteratorType>
struct IteratorRange
{
	IteratorType i1, i2;

	IteratorType begin() { return i1; }
	IteratorType end() { return i2; }
};

template <typename IteratorType>
IteratorRange<IteratorType> make_iterator_range(IteratorType i1, IteratorType i2)
{
	return IteratorRange<IteratorType>{ i1, i2 };
}

} // namespace mq
