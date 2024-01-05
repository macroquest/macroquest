
#include "pch.h"

#include <sol/sol.hpp>
#include <cstdint>

namespace mq::lua::bindings {

static uint32_t band32(uint32_t a, sol::variadic_args va)
{
	for (auto v : va)
	{
		int value = v;

		a &= value;
	}

	return a;
}

static uint32_t bor32(uint32_t a, sol::variadic_args va)
{
	for (auto v : va)
	{
		int value = v;

		a |= value;
	}

	return a;
}

static uint32_t bxor32(uint32_t a, sol::variadic_args va)
{
	for (auto v : va)
	{
		int value = v;

		a ^= value;
	}

	return a;
}

static uint32_t rotl32(uint32_t n, uint32_t c)
{
	const unsigned int mask = (CHAR_BIT * sizeof(n) - 1);  // assumes width is a power of 2.

	// assert ( (c<=mask) &&"rotate by type width or more");
	c &= mask;
	return (n << c) | (n >> ((-(int)c) & mask));
}

static uint32_t rotr32(uint32_t n, uint32_t c)
{
	const unsigned int mask = (CHAR_BIT * sizeof(n) - 1);

	// assert ( (c<=mask) &&"rotate by type width or more");
	c &= mask;
	return (n >> c) | (n << ((-(int)c) & mask));
}

void RegisterBindings_Bit32(sol::state_view state)
{
	sol::table bit = state.create_table();

	bit["bnot"] = [](uint32_t a) -> uint32_t { return ~a; };
	bit["band"] = band32;
	bit["bor"] = bor32;
	bit["bxor"] = bxor32;
	bit["lshift"] = [](uint32_t a, uint32_t b) -> uint32_t { return a << b; };
	bit["rshift"] = [](uint32_t a, uint32_t b) -> uint32_t { return a >> b; };
	bit["rol"] = rotl32;
	bit["ror"] = rotr32;

	bit["setflag"] = [](uint32_t a, uint32_t b, bool enable) -> uint32_t {
		if (enable)
			return a | b;
		else
			return a & ~b;
	};

	state["bit32"] = bit;
}

} // namespace mq::lua::bindings
