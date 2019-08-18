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

#include "Telnet.h"


#pragma comment(lib, "ws2_32")

class CWinTelnet : public CTelnet
{
public:
    CWinTelnet(void);
    ~CWinTelnet(void);

     bool Connect   (char*, int);
     bool Disconnect(void);

     bool Open (int);
     bool Close(void);

     bool Write(char);
     int  Write(const void*, int);
     int  CWinTelnet::WriteStr(const char* csend);

     bool Read(char*);
     int  Read(void*, int);

     bool isOpen     (void);
     bool isConnected(void);
     long isData     (void);

     SOCKET m_Socket;

private:
//    WSADATA wsa;
    bool Valid;
};
