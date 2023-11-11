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

#pragma once

namespace mq {

class ProtoMessage;
using ProtoMessagePtr = std::unique_ptr<ProtoMessage>;

namespace postoffice {
	class Dropbox;

	struct Address
	{
		std::optional<uint32_t> PID;
		std::optional<std::string> Name;
		std::optional<std::string> Mailbox;
		std::optional<std::string> Account;
		std::optional<std::string> Server;
		std::optional<std::string> Character;
		bool Explicit = false;
	};

	struct DropboxAPI
	{
		Dropbox* Dropbox;

		template <typename ID, typename T>
		void Post(const Address& address, ID messageId, const T& obj)
		{
			PostData(address, static_cast<uint16_t>(messageId), obj.SerializeAsString());
		}

		template <typename ID>
		void Post(const Address& address, ID messageId, const std::string& obj)
		{
			PostData(address, static_cast<uint16_t>(messageId), obj);
		}

		void PostData(const Address& address, uint16_t messageId, const std::string& data);
		void Remove();
	};

using ReceiveCallback = std::function<void(ProtoMessagePtr&&)>;

DropboxAPI AddActor(ReceiveCallback&& receive);
DropboxAPI AddActor(const char* localAddress, ReceiveCallback&& receive);

} // namespace postoffice

} // namespace mq
