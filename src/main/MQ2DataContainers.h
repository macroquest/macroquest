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

class MQ2EQObjectBase
{
public:
	virtual void Invalidate() = 0;
	virtual operator bool() const = 0;
};

template <typename T>
class MQ2EQObject : public MQ2EQObjectBase
{
private:
	T* m_object; // this is the actual raw pointer pointing to the memory space, we don't control its lifetime
	bool m_invalidated; // let's track if this got invalidated to help troubleshooting things

	void Validate()
	{
		if (m_invalidated)
			throw std::runtime_error("Tried to dereference nullptr object after an invalidation event (gamestate change).");

		if (m_object == nullptr)
			throw std::runtime_error("Tried to dereference nullptr object.");
	}

public:
	MQ2EQObject(T* Object) : m_object(Object), m_invalidated(false) {}

	void Invalidate() override { m_object = nullptr; m_invalidated = true; }

	T& operator*() const
	{
		Validate();
		return *m_object;
	}

	T* operator->() const
	{
		Validate();
		return m_object;
	}

	operator bool() const override { return m_object != nullptr && !m_invalidated; }

	static std::shared_ptr<MQ2EQObject<T>> Get(const std::shared_ptr<MQ2EQObjectBase>& Base)
	{
		return std::static_pointer_cast<MQ2EQObject<T>>(Base);
	}
};

template <typename T> static std::shared_ptr<MQ2EQObject<T>> ObserveEQObject(T* Object)
{
	auto ptr = std::make_shared<MQ2EQObject<T>>(Object);
	AddObservedEQObject(ptr);
	return ptr;
}

}

