/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "pch.h"
#include "MQ2Main.h"

#include "MQActorAPI.h"

#include "routing/Routing.h"
#include "routing/PostOffice.h"

namespace mq {
using namespace postoffice;

MQActorAPI* pActorAPI = nullptr;

postoffice::Dropbox* MQActorAPI::AddActor(const char* localAddress, ReceiveCallback&& receive)
{
	auto dropbox = std::make_unique<Dropbox>(GetPostOffice().RegisterAddress(localAddress, std::move(receive)));

	// return even if it's invalid so users don't have to null check
	return m_dropboxes.emplace_back(std::move(dropbox)).get();
}

void MQActorAPI::RemoveActor(postoffice::Dropbox*& dropbox)
{
	if (dropbox != nullptr)
	{
		dropbox->Remove();
		auto iter = std::find_if(m_dropboxes.begin(), m_dropboxes.end(),
			[dropbox](const std::unique_ptr<postoffice::Dropbox>& ptr) { return ptr.get() == dropbox; });

		dropbox = nullptr;
	}
}

} // namespace mq
