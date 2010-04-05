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
