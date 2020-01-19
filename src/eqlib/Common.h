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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include <limits>

#include "../common/Common.h"
#include "OffsetUtils.h"

#pragma warning(disable : 5030) // Single pragma seems to suffice for the entire codebase

#if !defined(_USE_32BIT_TIME_T)
#define _USE_32BIT_TIME_T
#endif

#if !defined(NOMINMAX)
#define NOMINMAX
#endif

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#undef GetWindowText
#undef FindWindow

#include <cstdlib>
#include <cstdint>

#ifdef EQLIB_EXPORTS
#define EQLIB_API extern "C" __declspec(dllexport)
#define EQLIB_VAR extern "C" __declspec(dllexport)
#define EQLIB_OBJECT __declspec(dllexport)
#else
#define EQLIB_API extern "C" __declspec(dllimport)
#define EQLIB_VAR extern "C" __declspec(dllimport)
#define EQLIB_OBJECT __declspec(dllimport)
#endif

// these macros do nothing but indicate to the reader that the function is actually in AssemblyFunctions.asm
#define CONSTRUCTOR_AT_ADDRESS(function, offset)
#define DESTRUCTOR_AT_ADDRESS(function, offset)

#define FUNCTION_AT_ADDRESS(Function, Offset)                                            \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		__asm mov eax, Offset                                                            \
		__asm jmp eax                                                                    \
	}

#define FUNCTION_AT_VARIABLE_ADDRESS(Function, Variable)                                 \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		__asm mov eax, [Variable]                                                        \
		__asm jmp eax                                                                    \
	}

#define FUNCTION_AT_VIRTUAL_ADDRESS(Function, VirtualOffset)                             \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		__asm mov eax, [ecx]                                                             \
		__asm lea eax, [eax+VirtualOffset]                                               \
		__asm mov eax, [eax]                                                             \
		__asm jmp eax                                                                    \
	}

#define FORWARD_FUNCTION_TO_VTABLE(Function, Class, Member)                              \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		using VFT = Class::VirtualFunctionTable;                                         \
		__asm mov eax, [Class::sm_vftable]                                               \
		__asm jmp dword ptr [eax]VFT.Member                                              \
	}

#define FORWARD_FUNCTION_TO_VTABLE2(Function, Class, Base, Member)                       \
	__declspec(naked) Function                                                           \
	{                                                                                    \
		using VFT = Base::VirtualFunctionTable;                                          \
		__asm mov eax, [Class::sm_vftable]                                               \
		__asm jmp dword ptr [eax]VFT.Member                                              \
	}


#define PreserveRegisters(code)                                                          \
{                                                                                        \
	__asm push eax                                                                       \
	__asm push ebx                                                                       \
	__asm push ecx                                                                       \
	__asm push edx                                                                       \
	__asm push esi                                                                       \
	__asm push edi                                                                       \
	code;                                                                                \
	__asm pop edi                                                                        \
    __asm pop esi                                                                        \
	__asm pop edx                                                                        \
	__asm pop ecx                                                                        \
	__asm pop ebx                                                                        \
	__asm pop eax                                                                        \
}

 // Define access to a member with another name (and type if you so will it)
#define ALT_MEMBER_GETTER(type, orig, name) \
    type& getter_ ## name() { return (*reinterpret_cast<type*>(&orig)); } \
    __declspec(property(get=getter_ ## name)) type name;

#define ALT_MEMBER_GETTER_ARRAY(type, size, orig, name) \
    type (&getter_ ## name())[size] { return (*reinterpret_cast<type(*)[size]>(&orig)); } \
    __declspec(property(get=getter_ ## name)) type (&name)[size];

#define ALT_MEMBER_GETTER_COPY(type, orig, name) \
    type getter_ ## name() { return (type)(orig); } \
    __declspec(property(get=getter_ ## name)) type name;

#if defined(DEPRECATE)
#undef (DEPRECATE)
#endif

#if defined(COMMENT_UPDATER)
#define DEPRECATE(x)
#else
#define DEPRECATE(x) [[deprecated(x)]]
#endif

#define ALT_MEMBER_GETTER_DEPRECATED(type, orig, name) \
    decltype(auto) getter_ ## name() { return (orig); } \
    __declspec(property(get=getter_ ## name)) type name;

namespace eqlib {

class CXSize;

class EQLIB_OBJECT CXPoint
{
public:
	CXPoint() = default;
	CXPoint(int x_, int y_) : x(x_), y(y_) {}
	CXPoint(const CXPoint& other) : x(other.x), y(other.y) {}
	explicit CXPoint(const CXSize& other);

	CXPoint& operator=(const CXPoint& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	bool operator==(const CXPoint& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const CXPoint& other)
	{
		return !(*this == other);
	}

	int x = 0, y = 0;
};

// Literally the same as CXPoint, but the variable names are cx and cy...
class EQLIB_OBJECT CXSize
{
public:
	CXSize() = default;
	CXSize(int x_, int y_) : cx(x_), cy(y_) {}
	CXSize(const CXSize& other) : cx(other.cx), cy(other.cy) {}
	explicit CXSize(const CXPoint& other);

	CXSize& operator=(const CXSize& other)
	{
		cx = other.cx;
		cy = other.cy;

		return *this;
	}

	bool operator==(const CXSize& other)
	{
		return cx == other.cx && cy == other.cy;
	}

	bool operator!=(const CXSize& other)
	{
		return !(*this == other);
	}

	int cx = 0, cy = 0;
};

class EQLIB_OBJECT CXRect
{
public:
	CXRect() = default;
	CXRect(int left_, int top_, int right_, int bottom_)
		: left(left_), top(top_), right(right_), bottom(bottom_) {}
	CXRect(const CXPoint& pt, const CXSize& size)
		: left(pt.x), top(pt.y), right(pt.x + size.cx), bottom(pt.y + size.cy) {}
	CXRect(const CXPoint& pt1, const CXPoint& pt2)
		: left(pt1.x), top(pt1.y), right(pt2.x), bottom(pt2.y) {}
	CXRect(const CXRect& other)
		: left(other.left), top(other.top), right(other.right), bottom(other.bottom) {}

	CXRect& operator=(const CXRect& other)
	{
		left = other.left;
		top = other.top;
		right = other.right;
		bottom = other.bottom;

		return *this;
	}

	bool operator==(const CXRect& other)
	{
		return left == other.left
			&& top == other.top
			&& right == other.right
			&& bottom == other.bottom;
	}

	bool operator!=(const CXRect& other)
	{
		return !(*this == other);
	}

	int GetWidth() const { return right - left; }
	int GetHeight() const { return bottom - top; }

	CXSize GetSize() const { return CXSize{ GetWidth(), GetHeight() }; }

	bool IsEmpty() const { return GetWidth() == 0 && GetHeight() == 0; }
	bool IsAbnormal() const { return GetWidth() < 0 && GetHeight() < 0; }

	CXPoint CenterPoint() const
	{
		return CXPoint{ left + (GetWidth() / 2), top + (GetHeight() / 2) };
	}

	CXPoint TopLeft() const { return CXPoint{ left, top }; }
	CXPoint TopRight() const { return CXPoint{ right, top }; }
	CXPoint BottomLeft() const { return CXPoint{ left, bottom }; }
	CXPoint BottomRight() const { return CXPoint{ right, bottom }; }

	int left = 0;
	int top = 0;
	int right = 0;
	int bottom = 0;
};

inline CXPoint::CXPoint(const CXSize& other)
{
	x = other.cx;
	y = other.cy;
}

inline CXSize::CXSize(const CXPoint& other)
{
	cx = other.x;
	cy= other.y;
}

class CVector2
{
public:
	float X, Y;
};

class CVector3
{
public:
	EQLIB_OBJECT CVector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
	EQLIB_OBJECT CVector3() {}

	// float GetLength() const;
	EQLIB_OBJECT float NormalizeAndReturnLength();
	EQLIB_OBJECT void Normalize();

	void Set(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	inline CVector3& operator-=(const CVector3& vec)
	{
		X -= vec.X;
		Y -= vec.Y;
		Z -= vec.Z;
		return *this;
	}

	inline CVector3& operator+=(const CVector3& vec)
	{
		X += vec.X;
		Y += vec.Y;
		Z += vec.Z;
		return *this;
	}

	inline void Scale(float val)
	{
		X *= val;
		Y *= val;
		Z *= val;
	}

	inline CVector3 operator*(float val) const
	{
		CVector3 ret = *this;
		ret.Scale(val);

		return ret;
	}

	void SetMax()
	{
		X = Y = Z = std::numeric_limits<float>::max();
	}

	float GetLengthSquared() const
	{
		return (X * X) + (Y * Y) + (Z * Z);
	}

	float GetLength() const
	{
		return sqrtf(GetLengthSquared());
	}

	CVector3 operator-() const
	{
		CVector3 res;
		res.Set(-X, -Y, -Z);

		return res;
	}

	CVector3 operator-(const CVector3 & vec) const
	{
		CVector3 res;
		res.Set(X - vec.X, Y - vec.Y, Z - vec.Z);

		return res;
	}

	CVector3 operator+(const CVector3 & vec) const
	{
		CVector3 res;
		res.Set(vec.X + X, vec.Y + Y, vec.Z + Z);

		return res;
	}

	float GetDistanceSquared(const CVector3 & vec) const
	{
		CVector3 Delta = *this - vec;
		return Delta.GetLengthSquared();
	}

	float X = 0.f;
	float Y = 0.f;
	float Z = 0.f;
};

union RGB
{
	struct
	{
		unsigned char Blue;
		unsigned char Green;
		unsigned char Red;
		unsigned char Alpha;
	};
	unsigned long ARGB;
};

struct EQRGB
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

struct ARGBCOLOR
{
	union
	{
		struct
		{
			BYTE B;
			BYTE G;
			BYTE R;
			BYTE A;
		};

		DWORD ARGB;
	};
};
using PARGBCOLOR = ARGBCOLOR *;

struct EQLOC
{
	float x;
	float y;
	float z;
};

enum UIType;

enum EQExpansion
{
	EQExpansionNone                    = 0,
	EQExpansionKunark                  = 1,
	EQExpansionVelious                 = 2,
	EQExpansionLuclin                  = 3,
	EQExpansionPOP                     = 4,
	EQExpansionYkesha                  = 5,
	EQExpansionLDON                    = 6,
	EQExpansionGates                   = 7,
	EQExpansionOOW                     = 8,
	EQExpansionDON                     = 9,
	EQExpansionDODH                    = 10,
	EQExpansionPOR                     = 11,
	EQExpansionTSS                     = 12,
	EQExpansionTBS                     = 13,
	EQExpansionSOF                     = 14,
	EQExpansionSOD                     = 15,
	EQExpansionUF                      = 16,
	EQExpansionHOT                     = 17,
	EQExpansionVOA                     = 18,
	EQExpansionROF                     = 19,
	EQExpansionCOTF                    = 20,
	EQExpansionTDS                     = 21,
	EQExpansionTBM                     = 22,
	EQExpansionEOK                     = 23,
	EQExpansionROS                     = 24,
	EQExpansionTBL                     = 25,
};

enum EQExpansionOwned
{
	EQExpansionNoneOwned               = 0x00000000,
	EQExpansionKunarkOwned             = 0x00000001,
	EQExpansionVeliousOwned            = 0x00000002,
	EQExpansionLuclinOwned             = 0x00000004,
	EQExpansionPOPOwned                = 0x00000008,
	EQExpansionYkeshaOwned             = 0x00000010,
	EQExpansionLDONOwned               = 0x00000020,
	EQExpansionGatesOwned              = 0x00000040,
	EQExpansionOOWOwned                = 0x00000080,
	EQExpansionDONOwned                = 0x00000100,
	EQExpansionDODHOwned               = 0x00000200,
	EQExpansionPOROwned                = 0x00000400,
	EQExpansionTSSOwned                = 0x00000800,
	EQExpansionTBSOwned                = 0x00001000,
	EQExpansionSOFOwned                = 0x00002000,
	EQExpansionSODOwned                = 0x00004000,
	EQExpansionUFOwned                 = 0x00008000,
	EQExpansionHOTOwned                = 0x00010000,
	EQExpansionVOAOwned                = 0x00020000,
	EQExpansionROFOwned                = 0x00040000,
	EQExpansionCOTFOwned               = 0x00080000,
	EQExpansionTDSOwned                = 0x00100000,
	EQExpansionTBMOwned                = 0x00200000,
	EQExpansionEOKOwned                = 0x00400000,
	EQExpansionROSOwned                = 0x00800000,
	EQExpansionTBLOwned                = 0x01000000,

	EQExpansionAllOwned                = 0x01ffffff,
};

// TODO: Find a common place to put constants
constexpr int MAX_BANDOLIER_SLOTS = 4;


enum PlayerClass
{
	Unknown = 0,
	Warrior = 1,
	Cleric = 2,
	Paladin = 3,
	Ranger = 4,
	Shadowknight = 5,
	Druid = 6,
	Monk = 7,
	Bard = 8,
	Rogue = 9,
	Shaman = 10,
	Necromancer = 11,
	Wizard = 12,
	Mage = 13,
	Enchanter = 14,
	Beastlord = 15,
	Berserker = 16,


	Mercenary = 17,

	GM_Warrior = 20,
	GM_Cleric = 21,
	GM_Paladin = 22,
	GM_Ranger = 23,
	GM_Shadowknight = 24,
	GM_Druid = 25,
	GM_Monk = 26,
	GM_Bard = 27,
	GM_Rogue = 28,
	GM_Shaman = 29,
	GM_Necromancer = 30,
	GM_Wizard = 31,
	GM_Magician = 32,
	GM_Enchanter = 33,
	GM_Beastlord = 34,
	GM_Berserker = 35,

	Class_Banker = 40,
	Class_Merchant = 41,
	Class_TaskMerchant = 58,
	Class_PvPMerchant = 59,
	Class_Adventure = 60,
	Class_AdventureMerchant = 61,
	Class_Object = 62,
	Class_TributeMaster = 63,
	Class_GuildTributeMaster = 64,

	Class_GuildBanker = 66,
	Class_GoodPointMerchant = 67,
	Class_EvilPointMerchant = 68,
	Class_FellowshipMaster = 69,
	Class_PointMerchant = 70,
	Class_MercenaryMerchant = 71,
	Class_RealEstateMrchant = 72,
	Class_LoyaltyMerchant = 73,

	TotalPlayerClasses = Berserker,
	TotalClasses = TotalPlayerClasses + 1,
};

constexpr int MAX_PLAYER_CLASSES = Berserker;
constexpr int MAX_CLASSES = GM_Berserker;

#if defined (_DEBUG)
#define FORCE_SYMBOLS __declspec(dllexport) const void* __force_symbol_generation__() const { return this; }
#else
#define FORCE_SYMBOLS
#endif

} // namespace eqlib

#include "ForwardDecls.h"
