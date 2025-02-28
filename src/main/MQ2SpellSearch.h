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

/*
 * This header includes two specific things. It has operator overloads to chain spell attributes
 * in c++, and it has all the attribute definitions needed to create the exposed spell/buff search
 * DSLs
 */

#include "MQ2MainBase.h"

using namespace eqlib;

namespace mq {

class CachedBuff;

template <typename T>
struct SpellAttribute
{
	const T& get() const { return static_cast<T const&>(*this); }

	template <typename Buff>
	bool operator()(const Buff& buff) const { return get().operator()(buff); }
};

// these are compile time, which we can conveniently use for operator overloads in c++, but aren't so useful at runtime
template <typename P1, typename P2>
class BuffHasBoth : public SpellAttribute<BuffHasBoth<P1, P2>>
{
	const P1& m_p1;
	const P2& m_p2;

public:
	BuffHasBoth(const P1& p1, const P2& p2) : m_p1(p1), m_p2(p2) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const
	{
		return m_p1(buff) && m_p2(buff);
	}
};

template <typename P1, typename P2>
BuffHasBoth<P1, P2> operator&& (const SpellAttribute<P1>& p1, const SpellAttribute<P2>& p2)
{
	return BuffHasBoth(p1.get(), p2.get());
}

template <typename P1, typename P2>
class BuffHasEither : public SpellAttribute<BuffHasEither<P1, P2>>
{
	const P1& m_p1;
	const P2& m_p2;

public:
	BuffHasEither(const P1& p1, const P2& p2) : m_p1(p1), m_p2(p2) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const
	{
		return m_p1(buff) || m_p2(buff);
	}
};

template <typename P1, typename P2>
BuffHasEither<P1, P2> operator|| (const SpellAttribute<P1>& p1, const SpellAttribute<P2>& p2)
{
	return BuffHasEither(p1.get(), p2.get());
}

template <typename P>
class BuffHasNot : public SpellAttribute<BuffHasNot<P>>
{
	const P& m_p;

public:
	BuffHasNot(const P& p) : m_p(p) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const
	{
		return !m_p(buff);
	}
};

template <typename P>
BuffHasNot<P> operator!(const SpellAttribute<P>& p)
{
	return BuffHasNot(p.get());
}

// ----------------------------------- DSL Helpers -----------------------------------

template <typename T>
struct SpellAttributeValue
{
	T Value;
	SpellAttributeValue(T value) : Value(value) {}
	operator int() const { return Value; }
	operator T() const { return Value; }
};

// this is here to be able to strongly type the enum while still allowing easy integral values for eqgame functions
struct SpellAffect : public SpellAttribute<SpellAffect>, SpellAttributeValue<eEQSPA>
{
	bool Increase;
	SpellAffect(eEQSPA value, bool increase = true) : SpellAttributeValue(value), Increase(increase) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return HasSPA(buff, Value, Increase); }
};

// both category and subcategory can take the same enumeration, so this allows us to separate the types
struct SpellCategory : public SpellAttribute<SpellCategory>, SpellAttributeValue<eEQSPELLCAT>
{
	SpellCategory(eEQSPELLCAT value) : SpellAttributeValue(value) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return GetSpellCategory(buff) == Value; }
};

struct SpellSubCat : public SpellAttribute<SpellSubCat>, SpellAttributeValue<eEQSPELLCAT>
{
	SpellSubCat(eEQSPELLCAT value) : SpellAttributeValue(value) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return GetSpellSubcategory(buff) == Value; }
};

struct SpellClassMask : public SpellAttribute<SpellClassMask>, SpellAttributeValue<unsigned int>
{
	template <typename... Classes>
	SpellClassMask(Classes... classes) : SpellAttributeValue(((1 << classes) + ...)) {}
	SpellClassMask& operator! ()
	{
		Value = ~Value;
		return *this;
	}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return IsSpellUsableForClass(buff, Value); }
};

struct SpellCasterAttribute : public SpellAttribute<SpellCasterAttribute>, SpellAttributeValue<std::string_view>
{
	SpellCasterAttribute(std::string_view value) : SpellAttributeValue(value) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return MaybeExactCompare(GetSpellCaster(buff), Value); }
};

struct PetSpellCasterAttribute : public SpellAttribute<PetSpellCasterAttribute>, SpellAttributeValue<std::string_view>
{
	PetSpellCasterAttribute(std::string_view value) : SpellAttributeValue(value) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return MaybeExactCompare(GetPetSpellCaster(buff), Value); }
};

struct SpellClass : public SpellAttribute<SpellClass>, SpellAttributeValue<unsigned int>
{
	SpellClass(unsigned int classNum) : SpellAttributeValue(1 << classNum) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return IsSpellUsableForClass(buff, Value); }
};

struct SpellIDAttribute : public SpellAttribute<SpellIDAttribute>, SpellAttributeValue<DWORD>
{
	SpellIDAttribute(DWORD value) : SpellAttributeValue(value) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return GetSpellID(buff) == Value; }
};

struct SpellNameAttribute : public SpellAttribute<SpellNameAttribute>, SpellAttributeValue<std::string_view>
{
	SpellNameAttribute(std::string_view value) : SpellAttributeValue(value) {}

	template <typename Buff>
	bool operator()(const Buff& buff) const { return MaybeExactCompare(GetSpellName(buff), Value); }
};

// ---------------------------------- DSL Reducers -----------------------------------

template <typename Buff>
using SpellAttributePredicate = std::function<bool(const Buff&)>;

template <typename Buff>
struct BothSpellAttribute : public SpellAttribute<BothSpellAttribute<Buff>>
{
private:
	SpellAttributePredicate<Buff> m_a, m_b;

public:
	BothSpellAttribute(SpellAttributePredicate<Buff>&& a, SpellAttributePredicate<Buff>&& b)
		: m_a(std::move(a))
		, m_b(std::move(b))
	{}

	bool operator()(const Buff& buff) const { return m_a(buff) && m_b(buff); }
};

template <typename Buff>
struct EitherSpellAttribute : public SpellAttribute<EitherSpellAttribute<Buff>>
{
private:
	SpellAttributePredicate<Buff> m_a, m_b;

public:
	EitherSpellAttribute(SpellAttributePredicate<Buff>&& a, SpellAttributePredicate<Buff>&& b)
		: m_a(std::move(a))
		, m_b(std::move(b))
	{}

	bool operator()(const Buff& buff) const { return m_a(buff) || m_b(buff); }
};

template <typename Buff>
struct NotSpellAttribute : public SpellAttribute<NotSpellAttribute<Buff>>
{
private:
	SpellAttributePredicate<Buff> m_a;

public:
	NotSpellAttribute(SpellAttributePredicate<Buff>&& a)
		: m_a(std::move(a))
	{}

	bool operator()(const Buff& buff) const { return !m_a(buff); }
};

// -----------------------------------------------------------------------------------
// These are buff getters that use spell attributes defined in this file, it is better
// they stay here because anyone that wants to use them will need to include this
// file anyway to create the predicates

template <typename T>
int GetCachedBuff(PlayerClient* pSpawn, const SpellAttribute<T>& fPredicate)
{
	return GetCachedBuff(pSpawn, [&fPredicate](const CachedBuff& buff) { return fPredicate(buff); });
}

template <typename T>
int GetCachedBuffAt(PlayerClient* pSpawn, size_t index, const SpellAttribute<T>& fPredicate)
{
	return GetCachedBuffAt(pSpawn, index, [&fPredicate](const CachedBuff& buff) { return fPredicate(buff); });
}

template <typename T>
int FilterCachedBuffs(PlayerClient* pSpawn, const SpellAttribute<T>& fPredicate)
{
	return FilterCachedBuffs(pSpawn, [&fPredicate](const CachedBuff& buff) { return fPredicate(buff); });
}

template <typename T>
int GetCachedBuffCount(PlayerClient* pSpawn, const SpellAttribute<T>& fPredicate)
{
	return GetCachedBuffCount(pSpawn, [&fPredicate](const CachedBuff& buff) { return fPredicate(buff); });
}

template <typename T>
int GetSelfBuff(const SpellAttribute<T>& fPredicate, int minSlot = 0, int maxSlot = -1)
{
	return GetSelfBuff([&fPredicate](const EQ_Affect& buff) { return fPredicate(buff); }, minSlot, maxSlot);
}

MQLIB_OBJECT SpellAttributePredicate<EQ_Affect> EvaluateBuffPredicate(std::string_view dsl);
MQLIB_OBJECT SpellAttributePredicate<EQ_Affect> EvaluatePetBuffPredicate(std::string_view dsl);
MQLIB_OBJECT SpellAttributePredicate<CachedBuff> EvaluateCachedBuffPredicate(std::string_view dsl);

} // namespace mq
