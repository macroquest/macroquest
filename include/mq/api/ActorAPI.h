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

namespace postoffice {
	class Dropbox;
} // namespace postoffice

class ProtoMessage;
using ProtoMessagePtr = std::unique_ptr<ProtoMessage>;

using ReceiveCallback = std::function<void(ProtoMessagePtr&&)>;
using MailboxMutator = std::function<std::string(const std::string&)>;

postoffice::Dropbox* AddActor(ReceiveCallback&& receive);
postoffice::Dropbox* AddActor(const char* localAddress, ReceiveCallback&& receive);
void RemoveActor(postoffice::Dropbox*& dropbox);

} // namespace mq
