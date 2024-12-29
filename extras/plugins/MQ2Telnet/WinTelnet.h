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

#include "Telnet.h"

class CWinTelnet : public CTelnet
{
public:
	CWinTelnet();
	~CWinTelnet();

	virtual bool Connect(char*, int) override;
	virtual bool Disconnect() override;

	virtual bool Open(int) override;
	virtual bool Close() override;

	bool Write(char) override;

	int Write(const void*, int) override;
	int CWinTelnet::WriteStr(const char* csend);

	bool Read(char*) override;
	int Read(void*, int) override;

	bool isOpen() override;
	bool isConnected() override;
	long isData() override;

	SOCKET m_Socket;

private:
	bool m_valid;
};
