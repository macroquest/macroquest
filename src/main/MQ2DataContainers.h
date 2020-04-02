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

// this header is to create containers used for passing data around
// try to make them generic and reusable

namespace mq {

class MQ2SlotInItem
{
public:
	ItemGlobalIndex GlobalIndex;
	int Slot;
	MQ2SlotInItem(const ItemGlobalIndex& GlobalIndex, int Slot)
		: GlobalIndex(GlobalIndex), Slot(Slot) {}
};

class MQ2Transient : public std::enable_shared_from_this<MQ2Transient>
{
protected:
	bool m_invalidated; // let's track if this got invalidated to help troubleshooting things

	template <typename T>
	std::shared_ptr<T> SharedFromBase()
	{
		return std::static_pointer_cast<T>(shared_from_this());
	}

public:
	virtual void Invalidate() = 0;
	virtual operator bool() const = 0;

	MQ2Transient() : m_invalidated(false) {}
};

template <typename T>
class MQ2EQObject : public MQ2Transient
{
private:
	T* m_object; // this is the actual raw pointer pointing to the memory space, we don't control its lifetime

	void Validate()
	{
		if (m_invalidated)
			throw std::runtime_error("Tried to dereference nullptr object after an invalidation event (gamestate change).");

		if (m_object == nullptr)
			throw std::runtime_error("Tried to dereference nullptr object.");
	}

	MQ2EQObject(T* Object) : m_object(Object) {}

public:
	void Invalidate() override { m_object = nullptr; m_invalidated = true; }

	operator bool() const override { return m_object != nullptr && !m_invalidated; }

	std::shared_ptr<MQ2EQObject<T>> Get() { return SharedFromBase<MQ2EQObject<T>>(); }

	T& operator*()
	{
		Validate();
		return *m_object;
	}

	T* operator->()
	{
		Validate();
		return m_object;
	}

	T* Ptr()
	{
		Validate();
		return m_object;
	}

	template <typename U>
	friend std::shared_ptr<MQ2EQObject<U>> ObserveEQObject(U*);
};

template <typename U>
std::shared_ptr<MQ2EQObject<U>> ObserveEQObject(U* Object)
{
	auto ptr = std::shared_ptr<MQ2EQObject<U>>(new MQ2EQObject<U>(Object),
		[](MQ2EQObject<U>* ptr) { delete ptr; });
	AddObservedEQObject(ptr);
	return ptr;
}
}

