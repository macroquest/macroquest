//#define DEBUG_TRY

#include <winsock2.h>
#include "WinTelnet.h"
#include "../MQ2Plugin.h"
#include "telnetserver.h"

CRITICAL_SECTION ProcessingCS;
CRITICAL_SECTION ListCS;
CRITICAL_SECTION BufferCS;
CRITICAL_SECTION CommandCS;
_TELNET *Connections;
SOCKET Listener;
bool bListening;
bool bKillThread;
bool bThreading;
PCHATBUF Sends;
PCHATBUF Commands;
BOOL LocalOnly=true;
BOOL ANSI=true;
CHAR TelnetLoginPrompt[MAX_STRING]={0};
CHAR TelnetPasswordPrompt[MAX_STRING]={0};
CHAR TelnetWelcome[MAX_STRING]={0};


DWORD WINAPI ProcessingThread(LPVOID lpParam)
{
    CTelnetServer *server=(CTelnetServer*)lpParam;
    EnterCriticalSection(&ProcessingCS);
    bThreading=true;
    char Buffer[4096];
    SOCKET incoming;
    while(!bKillThread)
    {
        // process new connections
        if (bListening)
        {
            incoming = accept(Listener,NULL,NULL);
            if (incoming != INVALID_SOCKET) {
                int ret=0;
                sockaddr_in addr;
                if (LocalOnly) {
                    int namesize = sizeof(addr);
                    int ret;
                    ret = getpeername(incoming,(sockaddr*)&addr,&namesize);
                }
                if ((bKillThread) || (ret==SOCKET_ERROR) || (LocalOnly && !strcmp("127.0.0.1",inet_ntoa(addr.sin_addr)))) {
                    DebugSpewAlways("ListenThread: Closing new connection...");
                    closesocket(incoming);
                    continue;
                }
                EnterCriticalSection(&ListCS);
                _TELNET *NewConn = new _TELNET;
                memset(NewConn,0,sizeof(_TELNET));
                CWinTelnet *telnet = new CWinTelnet;
                telnet->m_Socket=incoming;
                unsigned long nonblocking = 1;
                ioctlsocket(incoming,FIONBIO,&nonblocking);
                NewConn->connection=telnet;
                NewConn->pNext=Connections;
                if (Connections)
                    Connections->pLast=NewConn;
                Connections=NewConn;

                LeaveCriticalSection(&ListCS);
            }
        }

        // process sends
        EnterCriticalSection(&BufferCS);
        _TELNET *Conn=Connections;
        CHAR szText[MAX_STRING*25] = {0};
        PCHATBUF pBuff=Sends;
        while(pBuff)
        {
            PCHATBUF NextChat=pBuff->pNext;
            strcat(szText,pBuff->szText);
            strcat(szText,"\r\n");
            free(pBuff);
            pBuff=NextChat;
        }
        Sends=0;
        LeaveCriticalSection(&BufferCS);

        EnterCriticalSection(&ListCS);
        while(Conn)
        {
            if (!Conn->connection->isConnected())
            {
                // remove connection...
                _TELNET *Next=Conn->pNext;
                while(Conn->Received)
                {
                    PCHATBUF rNext=Conn->Received->pNext;
                    free(Conn->Received);
                    Conn->Received=rNext;
                }
                if (Conn->pLast)
                    Conn->pLast->pNext=Conn->pNext;
                else
                    Connections=Conn->pNext;
                if (Conn->pNext)
                    Conn->pNext->pLast=Conn->pLast;

                delete Conn->connection;
                delete Conn;
                Conn=Next;
                continue;
            }

            switch(Conn->State)
            {
            case TS_MAININPUT:
                Conn->connection->WriteStr(szText);
                break;
            case TS_SENDLOGIN:
                Conn->connection->WriteStr(TelnetLoginPrompt);
                Conn->State=TS_GETLOGIN;
                break;
            case TS_SENDPASSWORD:
                Conn->connection->WriteStr(TelnetPasswordPrompt);
                Conn->State=TS_GETPASSWORD;
                break;
            }
            Conn=Conn->pNext;
        }

        // process receives
        Conn=Connections;
        while(Conn)
        {
            // update receive buffer for this connection
            int isize=0;
            if (isize=Conn->connection->isData())
            {
                memset(Buffer,0,4096);
                if (isize>2047) isize=2047;
                strcpy(Buffer,Conn->Buffer);
                isize=Conn->connection->Read(&Buffer[strlen(Buffer)],isize);
                int begin=0;
                for (int i = 0 ; Buffer[i] ; i++)
                {
                    if (Buffer[i]==0x0a || Buffer[i]==0x0d || (i-begin>250))
                    {
                        // carriage return, see if we have a length
                        if (i-begin)
                        {
                            // we do. make a command out of it.
                            PCHATBUF newcmd = (PCHATBUF)malloc(sizeof(CHATBUF));
                            if (newcmd) {
                                DebugSpew("MQ2Telnet processing input");
                                memset(newcmd,0,sizeof(CHATBUF));
                                memcpy(newcmd->szText,&Buffer[begin],i-begin);
                                DebugSpew("MQ2Telnet: received '%s'",newcmd->szText);
                                newcmd->pNext = NULL;
                                if (!Conn->Received) {
                                    Conn->Received = newcmd;
                                } else {
                                    PCHATBUF pCurrent;
                                    for (pCurrent = Conn->Received;pCurrent->pNext;pCurrent=pCurrent->pNext);
                                    pCurrent->pNext = newcmd;
                                }
                            }
                        }
                        begin=i+1;
                    }
                }
                strcpy(Conn->Buffer,&Buffer[begin]);
            }


            while(Conn->Received)
            {
                if (Conn->State==TS_MAININPUT)
                {
                    EnterCriticalSection(&CommandCS);
                    // Add command to list

                    PCHATBUF pChat = (PCHATBUF)malloc(sizeof(CHATBUF));
                    if (pChat) {
                        strcpy(pChat->szText,Conn->Received->szText);
                        pChat->pNext = NULL;
                        if (!Commands) {
                            Commands = pChat;
                        } else {
                            PCHATBUF pCurrent;
                            for (pCurrent = Commands;pCurrent->pNext;pCurrent=pCurrent->pNext);
                            pCurrent->pNext = pChat;
                        }
                    }

                    LeaveCriticalSection(&CommandCS);
                }
                else if (Conn->State==TS_GETLOGIN)
                {
                    // process user name
                    char pwd[32]={0};
                    if (server->IsValidUser(Conn->Received->szText,pwd))
                    {
                        Conn->State=TS_SENDPASSWORD; // send password prompt
                        strcpy(Conn->Username,Conn->Received->szText);
                        strcpy(Conn->Password,pwd);
                    }
                    else
                    {
                        Conn->connection->WriteStr("invalid\r\n");
                        Conn->State=TS_SENDLOGIN;
                    }
                }
                else if (Conn->State==TS_GETPASSWORD)
                {
                    // process password
                    if (!strcmp(Conn->Password,Conn->Received->szText))
                    {
                        Conn->connection->WriteStr(TelnetWelcome);
                        Conn->connection->WriteStr("\r\n");
                        Conn->State=TS_MAININPUT;
                    }
                    else
                    {
                        Conn->connection->WriteStr("invalid\r\n");
                        if (++Conn->PasswordTries>=3)
                        {
                            Conn->connection->WriteStr("3 strikes, you're out. later.\r\n");
                            Conn->connection->Disconnect();
                        }
                        Conn->State=TS_SENDPASSWORD;
                    }
                }
                else
                    break;
                PCHATBUF Next=Conn->Received->pNext;
                free(Conn->Received);
                Conn->Received=Next;
            }

            Conn=Conn->pNext;
        }
        LeaveCriticalSection(&ListCS);

        Sleep(10);
    }
    LeaveCriticalSection(&ProcessingCS);
    DebugSpew("MQ2Telnet processing thread ending");
    bThreading=false;
    return 0;
}

CTelnetServer::CTelnetServer(void)
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,0),&wsa) || (HIBYTE(wsa.wVersion) != 0) || (LOBYTE(wsa.wVersion) != 2))
    {
        // failed...
    }

    Sends=0;
    Commands=0;
    Connections=0;
    bListening=false;
    bKillThread=false;
    LocalOnly=false;
    bThreading=false;
    InitializeCriticalSection(&ProcessingCS);
    InitializeCriticalSection(&ListCS);
    InitializeCriticalSection(&BufferCS);
    InitializeCriticalSection(&CommandCS);
    DWORD ThreadId; 
    CreateThread(NULL,0,&ProcessingThread,this,0,&ThreadId); 

}

CTelnetServer::~CTelnetServer(void)
{
    DebugTry(Shutdown());
    DebugTry(DeleteCriticalSection(&ProcessingCS));
    DebugTry(DeleteCriticalSection(&ListCS));
    DebugTry(DeleteCriticalSection(&BufferCS));
    DebugTry(DeleteCriticalSection(&CommandCS));
    // DONT WSACleanup(?)
}


void CTelnetServer::ShutdownListener()
{
    if (bListening)
    {
        bListening=false;
        shutdown(Listener,SD_BOTH);
        closesocket(Listener);
        Listener=INVALID_SOCKET;
    }
}

bool CTelnetServer::Listen(int Port)
{
    if (bListening)
        ShutdownListener();
    Listener = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (Listener == INVALID_SOCKET) {
        DebugSpewAlways("SetupServer: Unable to build socket");
        return false;
    }
    SOCKADDR_IN saServer;
    Port--;
    do {
        saServer.sin_family = AF_INET;
        saServer.sin_addr.s_addr = INADDR_ANY;
        saServer.sin_port = htons(++Port);

    } while (SOCKET_ERROR == bind(Listener,(LPSOCKADDR)&saServer,sizeof(struct sockaddr)));

    if (SOCKET_ERROR == listen(Listener,SOMAXCONN)) {
        DebugSpewAlways("SetupServer: Unable to listen on port %d",Port);
        closesocket(Listener);
        return false;
    }
    unsigned long nonblocking = 1;
    ioctlsocket(Listener,FIONBIO,&nonblocking);
    bListening=true;
    return true;
}

void CTelnetServer::Broadcast(char *String)
{
    EnterCriticalSection(&BufferCS);
    PCHATBUF pChat = (PCHATBUF)malloc(sizeof(CHATBUF));
    if (pChat) {
        strcpy(pChat->szText,String);
        pChat->pNext = NULL;
        if (!Sends) {
            Sends = pChat;
        } else {
            PCHATBUF pCurrent;
            for (pCurrent = Sends;pCurrent->pNext;pCurrent=pCurrent->pNext);
            pCurrent->pNext = pChat;
        }
    }

    LeaveCriticalSection(&BufferCS);
}

void CTelnetServer::Shutdown()
{
    // close listener
    DebugTry(ShutdownListener());
    bKillThread=true;
    while(bThreading) Sleep(20);

    // the critical section wasnt holding for some reason..
    //EnterCriticalSection(&ProcessingCS); // wait until thread shuts down..
    EnterCriticalSection(&CommandCS);

    // close all connections
    while(Connections)
    {
        // remove connection...
        _TELNET *Next=Connections->pNext;
        while(Connections->Received)
        {
            PCHATBUF rNext=Connections->Received->pNext;
            free(Connections->Received);
            Connections->Received=rNext;
        }

        delete Connections->connection;
        delete Connections;
        Connections=Next;
    }

    // delete all extra shit
    while(Sends)
    {
        PCHATBUF pNext=Sends->pNext;
        free(Sends);
        Sends=pNext;
    }
    while(Commands)
    {
        PCHATBUF pNext=Commands->pNext;
        free(Commands);
        Commands=pNext;
    }
    LeaveCriticalSection(&CommandCS);

    //DebugTry(LeaveCriticalSection(&ProcessingCS));
}

bool CTelnetServer::IsValidUser(char *user, char *pwdest)
{
    if (!GetPrivateProfileString("Users",user,NULL,pwdest,31,INIFileName))
        return false;
    pwdest[31]=0;
    return true;
}

void CTelnetServer::ProcessIncoming()
{
    EnterCriticalSection(&CommandCS);
    if(Commands) // process only 1 per pulse, no loop.
    {
        PCHARINFO pCharInfo=GetCharInfo();
        PSPAWNINFO pSpawn=(PSPAWNINFO)pCharSpawn;
        if (pCharInfo) pSpawn=pCharInfo->pSpawn;
        PCHATBUF Next=Commands->pNext;
        DoCommand(pSpawn,Commands->szText);
        free(Commands);
        Commands=Next;
    }

    LeaveCriticalSection(&CommandCS);
}
