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

#include <type_traits>

// -----------------------------------------------------------------------------
// Traits for treating enums like flags with bitwise operations

template <typename E, typename = std::enable_if_t<std::is_enum<E>::value>>
constexpr bool has_bitwise_operations(E) { return false; }

// -----------------------------------------------------------------------------
// bitwise OR

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr E& operator|=(E& a, E b)
{
	using UT = std::underlying_type_t<E>;
	return a = static_cast<E>(static_cast<UT>(a) | static_cast<UT>(b));
}

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr E operator|(E a, E b)
{
	return a |= b;
}

// -----------------------------------------------------------------------------
// bitwise AND

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr E& operator&=(E& a, E b)
{
	using UT = std::underlying_type_t<E>;
	return a = static_cast<E>(static_cast<UT>(a) & static_cast<UT>(b));
}

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr E operator&(E a, E b)
{
	return a &= b;
}

// -----------------------------------------------------------------------------
// bitwise XOR

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr E& operator^=(E& a, E b)
{
	using UT = std::underlying_type_t<E>;
	return a = static_cast<E>(static_cast<UT>(a) ^ static_cast<UT>(b));
}

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr E operator^(E a, E b)
{
	return a ^= b;
}

// -----------------------------------------------------------------------------
// bitwise NOT

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{}) >>
	constexpr E operator~(E a)
{
	using UT = std::underlying_type_t<E>;
	return static_cast<E>(~static_cast<UT>(a));
}

// -----------------------------------------------------------------------------
// convenient conversions to bool or underlying integral type (and thence 
// implicitly to bool)

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr bool operator!(E a)
{
	return a == E{};
}

template <typename E, typename = std::enable_if_t<has_bitwise_operations(E{})>>
constexpr std::underlying_type_t<E> operator+(E a)
{
	using UT = std::underlying_type_t<E>;
	return static_cast<UT>(a);
}
