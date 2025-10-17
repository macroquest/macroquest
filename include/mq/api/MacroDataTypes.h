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

#include "mq/base/Common.h"
#include "mq/base/Deprecation.h"
#include "mq/base/PluginHandle.h"

#include "eqlib/game/Color.h"
#include "eqlib/game/CXStr.h"
#include "eqlib/game/Items.h"

#include <functional>
#include <memory>
#include <mutex>
#include <optional>
#include <string_view>
#include <variant>

#define TypeMember(name) AddMember(static_cast<int>(name), #name)
#define ScopedTypeMember(scope, name) AddMember(static_cast<int>(scope::name), #name)
#define TypeMethod(name) AddMethod(static_cast<int>(name), #name)
#define ScopedTypeMethod(scope, name) AddMethod(static_cast<int>(scope::name), #name)


namespace mq {

namespace datatypes {
	class MQ2Type;
}
using datatypes::MQ2Type;
struct MQTypeVar;

template <typename T>
static constexpr auto type_name() noexcept;

namespace detail {

	template <typename T>
	constexpr bool is_shared_ptr = false;

	template <typename T>
	constexpr bool is_shared_ptr<std::shared_ptr<T>> = true;

	template <typename T>
	struct shared_ptr_element_type { using type = T; };

	template <typename T>
	struct shared_ptr_element_type<std::shared_ptr<T>> { using type = typename std::shared_ptr<T>::element_type;  };

	MQLIB_OBJECT void PrintMacroDataConversionError(const char* fromType, const char* toType);

	template <typename From, typename To>
	static void ConvertData(const From& input, std::optional<To>& output)
	{
		if constexpr (std::is_convertible_v<From, To>)
			output = static_cast<To>(input);
		else
		{
			PrintMacroDataConversionError(type_name<From>().c_str(), type_name<To>().c_str());
		}
	}
}

template <typename T>
static constexpr auto type_name() noexcept
{
	std::string_view name = __FUNCSIG__
		, prefix = "auto __cdecl mq::type_name<"
		, suffix = ">(void) noexcept";

	name.remove_prefix(prefix.size());
	name.remove_suffix(suffix.size());
	return std::string(name);
}

struct MQVarPtr
{
	using MQVariant = std::variant<
		void*,
		bool,
		float,
		double,
		uint64_t,
		std::shared_ptr<void>,
		eqlib::CXStr,
		eqlib::ItemPtr
	>;

	MQVariant Data;

	// HighPart is slightly more complicated, but only just. We just save off the HighPart in this member variable unless
	// the underlying data is uint64_t -- and we will prefer to store the uint32_t variant when setting
	uint32_t HighPart_ = 0;

	enum class VariantIdx
	{
		Ptr = 0,
		Bool,
		Float,
		Double,
		UInt64,
		ComplexObject,
		String,
		Item,
	};

	bool IsType(VariantIdx Index) const { return Data.index() == static_cast<size_t>(Index); }
	VariantIdx GetType() const { return static_cast<VariantIdx>(Data.index()); }

	bool operator==(const MQVarPtr& other) const
	{
		// this is a strict equals check, will be false if the underlying data type is not the same
		// if you want to compare unlike types, you will need to first actualize the variant
		return this->Data == other.Data;
	}

	template <typename T>
	T Cast() const
	{
		// These type aliases will mask the underlying type in diagnostic messages.
		//using ToType = T;
		//using FromType = ;

		std::optional<T> to;

		auto visitor = [&to, this](const auto& from)
		{
			detail::ConvertData<std::decay_t<decltype(from)>, T>(from, to);
		};

		std::visit(visitor, Data);
		return to.value_or(T());
	}

	template <typename T>
	struct ReturnType {
		using type = std::conditional_t<detail::is_shared_ptr<T>, T, std::shared_ptr<T>>;
		using value_type = typename detail::shared_ptr_element_type<T>::type;
	};

	template <typename T>
	typename ReturnType<T>::type Set(T Object)
	{
		return std::static_pointer_cast<T>(std::get<std::shared_ptr<void>>(Data = std::shared_ptr<T>(new T(std::move(Object)),
			[](T* ptr) { if constexpr (std::is_array_v<T>) delete[] ptr; else delete ptr; })));
	}

	template <typename T>
	typename ReturnType<T>::type Set(std::shared_ptr<T> Object)
	{
		return std::static_pointer_cast<T>(std::get<std::shared_ptr<void>>(Data = std::move(Object)));
	}

	template <typename T>
	typename ReturnType<T>::type Get() const
	{
		using value_type = ReturnType<T>::value_type;
		using return_type = ReturnType<T>::type;

		if (Data.index() != static_cast<size_t>(VariantIdx::ComplexObject))
			return return_type();

		return std::static_pointer_cast<value_type>(std::get<std::shared_ptr<void>>(Data));
	}

	template <> struct ReturnType<eqlib::CXStr> { using type = eqlib::CXStr; };

	template <>
	eqlib::CXStr Set<eqlib::CXStr>(eqlib::CXStr string)
	{
		return std::get<eqlib::CXStr>(Data = std::move(string));
	}

	// this function is special to allow us to set a CXStr from a string_view without needing extra allocations
	eqlib::CXStr SetString(std::string_view string)
	{
		return std::get<eqlib::CXStr>(Data = eqlib::CXStr(string));
	}

	template <>
	eqlib::CXStr Get<eqlib::CXStr>() const
	{
		if (Data.index() != static_cast<size_t>(VariantIdx::String))
			return eqlib::CXStr();

		return std::get<eqlib::CXStr>(Data);
	}

	template <> struct ReturnType<eqlib::ItemPtr> { using type = eqlib::ItemPtr; };

	template <>
	eqlib::ItemPtr Set<eqlib::ItemPtr>(eqlib::ItemPtr pItem)
	{
		return std::get<eqlib::ItemPtr>(Data = std::move(pItem));
	}

	template <>
	eqlib::ItemPtr Get<eqlib::ItemPtr>() const
	{
		if (Data.index() != static_cast<size_t>(VariantIdx::Item))
			return eqlib::ItemPtr();

		return std::get<eqlib::ItemPtr>(Data);
	}

	// Specializations for integer types
#define MQVARPTR_INTSPECIALIZE(Type) \
	template <> struct ReturnType<Type> { using type = Type; }; \
	template <> Type Set<Type>(Type Val) { return static_cast<Type>(std::get<uint64_t>(Data = static_cast<uint64_t>(Val))); } \
	template <> Type Get<Type>() const { return static_cast<Type>(Cast<uint64_t>()); }
	MQVARPTR_INTSPECIALIZE(int8_t);
	MQVARPTR_INTSPECIALIZE(uint8_t);
	MQVARPTR_INTSPECIALIZE(int16_t);
	MQVARPTR_INTSPECIALIZE(uint16_t);
	MQVARPTR_INTSPECIALIZE(int32_t);
	MQVARPTR_INTSPECIALIZE(uint32_t);
	MQVARPTR_INTSPECIALIZE(int64_t);
#undef MQVARPTR_INTSPECIALIZE

#define MQVARPTR_SPECIALIZE(Type) \
	template<> struct ReturnType<Type> { using type = Type; }; \
	template<> Type Set<Type>(Type Val) { return std::get<Type>(Data = Val); } \
	template<> Type Get<Type>() const { return Cast<Type>(); }
	MQVARPTR_SPECIALIZE(void*);
	MQVARPTR_SPECIALIZE(bool);
	MQVARPTR_SPECIALIZE(float);
	MQVARPTR_SPECIALIZE(double);
	MQVARPTR_SPECIALIZE(uint64_t);
#undef MQVARPTR_SPECIALIZE

#define MQVARPTR_PROPERTIES(Type, Prop) \
	Type set_##Prop(Type Val) { return Set<Type>(Val); } \
	Type get_##Prop() const { return Get<Type>(); } \
	__declspec(property(get = get_##Prop, put = set_##Prop)) Type Prop;
	// TODO: Future work -- deprecate all of these in favor of Get/Set
	MQVARPTR_PROPERTIES(void*, Ptr);
	MQVARPTR_PROPERTIES(float, Float);
	MQVARPTR_PROPERTIES(int32_t, Int);
	MQVARPTR_PROPERTIES(uint32_t, DWord);
	MQVARPTR_PROPERTIES(double, Double);
	MQVARPTR_PROPERTIES(int64_t, Int64);
	MQVARPTR_PROPERTIES(uint64_t, UInt64);
	MQVARPTR_PROPERTIES(eqlib::ItemPtr, Item);
#undef MQVARPTR_PROPERTIES

	// TODO: Future work -- uncomment the deprecates and refactor all uses of high/low part
	// these are here only to support deprecated functionality where some types rely on storing ints in low and high parts
	//DEPRECATE("Use Get<uint32_t>() instead of LowPart. For data needing High and Low part, create a data structure instead.")
	uint32_t get_LowPart() const { return Get<uint32_t>(); }

	//DEPRECATE("Use Set<uint32_t>(v) instead of LowPart. For data needing High and Low part, create a data structure instead.")
	uint32_t set_LowPart(uint32_t Val)
	{
		// we can assume that if the user wanted to also set HighPart, they did it explicitly either before or after setting
		// LowPart, which falls into 2 cases. Either the underlying data was set before the 64-bit, or it wasn't (either the
		// the default or an explicit 32-bit/pointer value).

		// first check if we have 64-bit Data -- we only need to worry about unsigned because this trick wouldn't work with signed
		// data without some explicit or implicit casting to unsigned
		if (Data.index() == static_cast<size_t>(VariantIdx::UInt64))
		{
			// if so, we need to save the HighPart off before setting the low part, then retain the data type in the variant
			ULARGE_INTEGER i;
			i.QuadPart = Get<uint64_t>();
			i.LowPart = Val;
			Set<uint64_t>(i.QuadPart);
			return i.LowPart;
		}

		// if we get here, we don't have 64-bit data, so HighPart is either unset, or set in the convenience variable above
		// we can just set the LowPart as uint32_t
		return Set<uint32_t>(Val);
	}

#pragma warning(suppress: 4996)
	__declspec(property(get = get_LowPart, put = set_LowPart)) uint32_t LowPart;

	//DEPRECATE("For data needing High and Low part, create a data structure instead.")
	uint32_t get_HighPart() const
	{
		// this data is only stored in Data if the type of variant is UInt64
		if (Data.index() == static_cast<size_t>(VariantIdx::UInt64))
		{
			ULARGE_INTEGER i;
			i.QuadPart = Get<uint64_t>();
			return i.HighPart;
		}

		// otherwise, just return the extra storage information
		return HighPart_;
	}

	//DEPRECATE("For data needing High and Low part, create a data structure instead.")
	uint32_t set_HighPart(uint32_t Val)
	{
		// again, check if we  have already set the underlying data type to uint64_t
		if (Data.index() == static_cast<size_t>(VariantIdx::UInt64))
		{
			ULARGE_INTEGER i;
			i.QuadPart = Get<uint64_t>();
			i.HighPart = Val;
			Set<uint64_t>(i.QuadPart);
			return i.HighPart;
		}

		// otherwise, just set the extra storage information and move on
		HighPart_ = Val;
		return HighPart_;
	}

#pragma warning(suppress: 4996)
	__declspec(property(get = get_HighPart, put = set_HighPart)) uint32_t HighPart;

	eqlib::ARGBCOLOR get_Argb() const
	{
		auto ptr = Get<eqlib::ARGBCOLOR>();
		if (ptr != nullptr)
			return *ptr;

		return {};
	}

	eqlib::ARGBCOLOR set_Argb(eqlib::ARGBCOLOR Val)
	{
		// this is a bit of a cowboy deref, but we are guaranteed that Set constructs a new shared pointer
		return *Set<eqlib::ARGBCOLOR>(Val);
	}

	__declspec(property(get = get_Argb, put = set_Argb)) eqlib::ARGBCOLOR Argb;

	MQVarPtr() = default;

	MQVarPtr(const MQVarPtr& other)
		: Data(other.Data)
		, HighPart_(other.HighPart_)
	{
	}

	MQVarPtr(MQVarPtr&& other)
		: Data(std::move(other.Data))
		, HighPart_(other.HighPart_)
	{
	}

	MQVarPtr& operator=(MQVarPtr&& other)
	{
		Data = std::move(other.Data);
		HighPart_ = other.HighPart_;

		return *this;
	}

	MQVarPtr& operator=(const MQVarPtr& other)
	{
		Data = other.Data;
		HighPart_ = other.HighPart_;

		return *this;
	}

	template <typename T>
	static MQVarPtr Create(T&& Data)
	{
		MQVarPtr VarPtr;
		VarPtr.Set(std::forward<T>(Data));
		return VarPtr;
	}
};

struct MQTypeVar : public MQVarPtr
{
	MQ2Type* Type = nullptr;

	bool operator==(const MQTypeVar& other) const
	{
		return Type == other.Type && this->MQVarPtr::operator==(other);
	}

	MQVarPtr& GetVarPtr() { return *this; }
	const MQVarPtr& GetVarPtr() const { return *this; }

	MQVarPtr& SetVarPtr(const MQVarPtr& VarPtr) { static_cast<MQVarPtr&>(*this) = VarPtr; return *this; }
	__declspec(property(get = GetVarPtr, put = SetVarPtr)) MQVarPtr VarPtr;
};

struct MQTypeMember
{
	int          ID;
	uint32_t     Type;
	const char* Name;

	MQTypeMember(int ID, const char* Name)
		: ID(ID), Name(Name), Type(0) {}
	MQTypeMember(int ID, const char* Name, uint32_t Type)
		: ID(ID), Name(Name), Type(Type) {}
};

//============================================================================

namespace datatypes {

class MQ2Type
{
public:
	MQLIB_OBJECT MQ2Type(std::string_view typeName, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	MQLIB_OBJECT virtual ~MQ2Type();

	MQLIB_OBJECT void InitializeMembers(MQTypeMember* MemberArray);

	virtual bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source) { return false; }
	virtual bool FromString(MQVarPtr& VarPtr, const char* Source) { return false; }

	virtual void InitVariable(MQVarPtr& VarPtr)
	{
		VarPtr.Ptr = nullptr;
	}

	virtual void FreeVariable(MQVarPtr& VarPtr) {}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) = 0;

	virtual bool ToString(MQVarPtr VarPtr, char* Destination)
	{
		strcpy_s(Destination, MAX_STRING, m_typeName.c_str());
		return true;
	}

	MQLIB_OBJECT const char* GetName() const;
	MQLIB_OBJECT const char* GetMemberName(int ID) const;

	MQLIB_OBJECT bool GetMemberID(const char* Name, int& Result) const;

	MQLIB_OBJECT MQTypeMember* FindMember(const char* Name);
	MQLIB_OBJECT MQTypeMember* FindMember(const std::string& Name);
	MQLIB_OBJECT MQTypeMember* FindMethod(const char* Name);
	MQLIB_OBJECT MQTypeMember* FindMethod(const std::string& Name);

	MQLIB_OBJECT bool CanEvaluateMethodOrMember(const std::string& Name);

	inline bool InheritsFrom(MQ2Type* testType)
	{
		MQ2Type* parentType = m_parent;
		int limit = 10; // arbitrary limit to avoid infinite looping with cyclical references
		while (parentType)
		{
			if (parentType == testType)
				return true;

			if (--limit == 0)
				return false;
			parentType = parentType->m_parent;
		}
		return false;
	}

	inline bool InheritedMember(const char* Name) { return m_parent && m_parent->FindMember(Name); }
	inline bool InheritedMember(const std::string& Name) { return m_parent && m_parent->FindMember(Name); }

	inline void SetInheritance(MQ2Type* pNewInherit)
	{
		m_parent = pNewInherit;
	}
	inline  MQ2Type* GetParent() const { return m_parent; }

	// Override this function to convert this type to the requested type. Return true if the conversion is successful. The
	// Result should be placed in VarPtr and its type should match that of toType.
	virtual bool Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType) { return false; }

	//----------------------------------------------------------------------------
	// deprecated virtual functions

	// If you encounter an error here, you've derived from MQ2Type using a non-const Source. Change
	// your FromString function to take a const char* as the second parameter.
	virtual bool FromString(MQVarPtr& VarPtr, char* Source) final {
		return FromString(VarPtr, (const char*)Source);
	}

	// If you encounter an error here, you've derived from MQ2Type and implemented GetMember using a non-const Member. Change
	// your GetMember function to take a const char* as the second parameter.
	virtual bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) final {
		return GetMember(VarPtr, (const char*)Member, Index, Dest);
	}

	// If you encounter an error here, you've derived from MQ2Type and implemented FromData using a non-const Source. Change
	// your FromData function to take a const MQTypeVar& as the second parameter.
	virtual bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) final {
		return FromData(VarPtr, (const MQTypeVar&)Source);
	}

	// There used to exist an old macro that would turn GETMEMBER into an actual function signature. This has been removed,
	// so you need to update your signature yourself.
	// It should be of the form:
	// virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	virtual bool GETMEMBER() final {
		return false;
	}

protected:
	MQLIB_OBJECT bool AddMember(int id, const char* Name);
	MQLIB_OBJECT bool RemoveMember(const char* Name);
	MQLIB_OBJECT bool AddMethod(int ID, const char* Name);
	MQLIB_OBJECT bool RemoveMethod(const char* Name);

	std::string m_typeName;
	bool m_owned = false;
	bool m_initialized = false;
	MQ2Type* m_parent = nullptr;
	mutable std::mutex m_mutex;

private:
	std::vector<std::unique_ptr<MQTypeMember>> Members;
	std::vector<std::unique_ptr<MQTypeMember>> Methods;
	std::unordered_map<std::string, int> MemberMap;
	std::unordered_map<std::string, int> MethodMap;
};

} // namespace datatypes

//----------------------------------------------------------------------------

inline namespace deprecated
{
	using MQ2TYPEVAR DEPRECATE("Use MQTypeVar instead of MQ2TYPEVAR") = MQTypeVar;
	using PMQ2TYPEVAR DEPRECATE("Use MQTypeVar* instead of PMQ2TYPEVAR") = MQTypeVar;

	using MQ2VARPTR DEPRECATE("Use MQVarPtr instead of MQ2VARPTR.") = MQVarPtr;
	using PMQ2VARPTR DEPRECATE("Use MQVarPtr* instead of PMQ2VARPTR.") = MQVarPtr*;

	using MQ2TYPEMEMBER DEPRECATE("Use MQTypeMember instead of MQ2TYPEMEMBER") = MQTypeMember;
	using PMQ2TYPEMEMBER DEPRECATE("Use MQTypeMember* instead of PMQ2TYPEMEMBER") = MQTypeMember*;
}

} // namespace mq
