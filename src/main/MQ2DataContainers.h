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

#include "mq/base/Traits.h"

// this header is to create containers used for passing data around
// try to make them generic and reusable

namespace mq {

class MQSlotInItem
{
public:
	ItemGlobalIndex GlobalIndex;
	int Slot;
	MQSlotInItem(const ItemGlobalIndex& GlobalIndex, int Slot)
		: GlobalIndex(GlobalIndex), Slot(Slot) {}
};

class MQTransient : public std::enable_shared_from_this<MQTransient>
{
protected:
	bool m_invalidated = false; // let's track if this got invalidated to help troubleshooting things

	template <typename T>
	std::shared_ptr<T> SharedFromBase()
	{
		return std::static_pointer_cast<T>(shared_from_this());
	}

public:
	virtual void Invalidate() = 0;
	virtual operator bool() const = 0;
	virtual bool operator==(void*) const = 0;

	MQTransient() = default;
};

#if defined(COMMENT_UPDATER)

template <typename EQType>
auto EQObjectID(EQType* Object)
{
}

#else

#if _MSVC_LANG > 201703L
template <typename EQType>
auto EQObjectID(EQType* Object) = delete;
#else
template <typename EQType>
auto EQObjectID(EQType* Object)
{
	/*
		This is the base template for EQObjectID. If the user tries to use a type that has not been specialized, then we will get here.
		In order to prevent getting here (which static_asserts always, and will not compile), you need to implement a function
		that returns a unique identifier given an EQType (like PlayerClient or EQGroundItem). An example of what this function should
		look like is as follows:

			inline id_type EQObjectID(EQType* Object) { return Object->ID; }

		where the id_type can be any type (often a DWORD or an int) and EQType must match the type of the EQ Object. The message in the
		error output after the static assert will identify which EQ type is missing. It looks like this:

			1>C:\path\MQ2DataContainers.h(73,16): error C2338: No function found to provide a unique identifier for an EQ type. Please provide a function named EQObjectID that returns a unique identifier for this object type.
			1>C:\path\MQ2DataContainers.h(83): message : see reference to function template instantiation 'auto mq::EQObjectID<EQType>(EQType *)' being compiled
			1>        with
			1>        [
			1>            EQType=eqlib::EQMyType
			1>        ]

		where EQType here is EQMyType, as noted by the EQType=eqlib::EQMyType 
	*/

	static_assert(mq::always_false<EQType>::value,
		"No function found to provide a unique identifier for an EQ type. "
		"Please provide a function named EQObjectID that returns a unique identifier for this object type.");
}
#endif // _MSVC_LANG > 201703L
#endif // defined(COMMENT_UPDATER)

inline auto EQObjectID(EQGroundItem* Object) { return Object->DropID; }
inline auto EQObjectID(EQPlacedItem* Object) { return Object->RealEstateItemID; }
inline auto EQObjectID(PlayerClient* pSpawn) { return pSpawn->SpawnID; }

template <typename EQType>
class MQEQObject : public MQTransient
{
private:
	EQType* m_object; // this is the actual raw pointer pointing to the memory space, we don't control its lifetime
	using ID = decltype(EQObjectID(m_object));
	ID m_ID; // this is a unique identifier for validation checks

	void Validate()
	{
		if (m_invalidated)
			throw std::runtime_error(
				std::string("Tried to dereference nullptr object after an invalidation event (gamestate change). Type: ") + typeid(EQType).name());

		if (m_object == nullptr)
			throw std::runtime_error(
				std::string("Tried to dereference nullptr object. Type: ") + typeid(EQType).name());

		if (EQObjectID(m_object) != m_ID)
			throw std::runtime_error(
				std::string("The underlying object has changed (likely deleted). Type: ") + typeid(EQType).name());
	}

	MQEQObject(EQType* Object) : m_object(Object), m_ID(EQObjectID(Object)) {}

public:
	void Invalidate() override { m_object = nullptr; m_invalidated = true; }

	operator bool() const override
	{
		return m_object != nullptr && !m_invalidated && EQObjectID(m_object) == m_ID;
	}

	bool operator==(void* rhs) const override
	{
		return static_cast<void*>(m_object) == rhs;
	}

	std::shared_ptr<MQEQObject<EQType>> Get() { return SharedFromBase<MQEQObject<EQType>>(); }

	EQType& operator*()
	{
		Validate();
		return *m_object;
	}

	EQType* operator->()
	{
		Validate();
		return m_object;
	}

	EQType* Ptr()
	{
		return m_object;
	}

	template <typename U>
	friend std::shared_ptr<MQEQObject<U>> ObserveEQObject(U*);

	MQEQObject(const MQEQObject&) = delete;
	MQEQObject& operator=(const MQEQObject&) = delete;
};

template <typename T>
using MQEQObjectPtr = std::shared_ptr<MQEQObject<T>>;

template <typename U>
MQEQObjectPtr<U> ObserveEQObject(U* Object)
{
	auto ptr = MQEQObjectPtr<U>(new MQEQObject<U>(Object), [](MQEQObject<U>* ptr) { delete ptr; });
	AddObservedEQObject(ptr);
	return ptr;
}

} // namespace mq
