// mq2telnet.cpp

#include "../MQ2Plugin.h"

// ***************************************************************************
// Some global variable settings
// ***************************************************************************
DWORD gTelnetServer = 0;
DWORD gTelnetLocal = 1;
u_short gTelnetPort = 0;
SOCKET gTelnetSocket;
PCONNECTION gTelnetConnection = NULL;
CHAR gTelnetPassword[MAX_STRING] = {0};
CHAR gTelnetWelcome[MAX_STRING] = {0};
PCHATBUF gTelnetRecv = NULL;
PCHATBUF gTelnetSend = NULL;
DWORD gTelnet_LockCount = 0;
CRITICAL_SECTION gTelnet_CS_Recv;
CRITICAL_SECTION gTelnet_CS_Connection;
CRITICAL_SECTION gTelnet_CS_Send;
CRITICAL_SECTION gTelnet_CS_Lock;
BOOL gTelnet_Unload = 0;
//CRITICAL_SECTION gDoCommand_Lock;


VOID SetupServer();
VOID CloseServer();
VOID TelnetServer_Write(CHAR *szLine);
VOID ProcessServer();


PreSetup("MQ2Telnet");

PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing mq2telnet");
//    InitializeCriticalSection(&gDoCommand_Lock);
    InitializeCriticalSection(&gTelnet_CS_Connection);
    InitializeCriticalSection(&gTelnet_CS_Lock);
    InitializeCriticalSection(&gTelnet_CS_Recv);
    InitializeCriticalSection(&gTelnet_CS_Send);
    DebugTry(SetupServer());
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down mq2telnet");
    DebugTry(CloseServer());
    DeleteCriticalSection(&gTelnet_CS_Connection);
    DeleteCriticalSection(&gTelnet_CS_Lock);
    DeleteCriticalSection(&gTelnet_CS_Send);
    DeleteCriticalSection(&gTelnet_CS_Recv);
//    DeleteCriticalSection(&gDoCommand_Lock);
}

PLUGIN_API VOID OnPulse(VOID)
{
    ProcessServer();
}

PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
    CHAR Stripped[MAX_STRING];
    if (gFilterMacro == FILTERMACRO_NONE) return 0;

    StripMQChat(Line,Stripped);
    DebugSpewAlways("OnWriteChatColor: <%s>", Stripped);
    TelnetServer_Write(Stripped);

    return 0;
}

PLUGIN_API DWORD OnIncomingChat(PCHAR Line, DWORD Color)
{
    CHAR Stripped[MAX_STRING];
    StripMQChat(Line,Stripped);
    DebugSpewAlways("OnIncomingChat: <%s>", Stripped);
    TelnetServer_Write(Stripped);
    return 0;
}



// ***************************************************************************
// Description: Telnet Server functions...
// ***************************************************************************

VOID TelnetLock(DWORD inc)
{
    EnterCriticalSection(&gTelnet_CS_Lock);
    gTelnet_LockCount += inc;
    LeaveCriticalSection(&gTelnet_CS_Lock);
}

VOID TelnetServer_AddToChatQueue(CHAR *szCommand) {
    EnterCriticalSection(&gTelnet_CS_Recv);
    PCHATBUF pChat = (PCHATBUF)malloc(sizeof(CHATBUF));
    if (pChat) {
        strcpy(pChat->szText,szCommand);
        pChat->pNext = NULL;
        if (!gTelnetRecv) {
            gTelnetRecv = pChat;
        } else {
            PCHATBUF pCurrent;
            for (pCurrent = gTelnetRecv;pCurrent->pNext;pCurrent=pCurrent->pNext);
            pCurrent->pNext = pChat;
        }
    }
    LeaveCriticalSection(&gTelnet_CS_Recv);
}

BOOL WSAOpen()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;

    wVersionRequested = MAKEWORD( 1, 1 );

    err = WSAStartup( wVersionRequested, &wsaData );
    if ( err != 0 ) {
        return FALSE;
    }

    if ( LOBYTE( wsaData.wVersion ) != 1 ||
            HIBYTE( wsaData.wVersion ) != 1 ) {
        WSACleanup( );
        return FALSE;
    }
    return TRUE;

}

VOID TelnetServer_Write(CHAR *szLine)
{
    // Add to output during CChat::Detour()...
    PCHATBUF ChatBuff = (PCHATBUF)malloc(sizeof(CHATBUF));
    strcpy(ChatBuff->szText,szLine);
    ChatBuff->pNext = NULL;
    EnterCriticalSection(&gTelnet_CS_Send);
    if (gTelnetSend) {
        PCHATBUF Chat=gTelnetSend;
        while (Chat->pNext) Chat=Chat->pNext;
        Chat->pNext = ChatBuff;
    } else {
        gTelnetSend = ChatBuff;
    }
    LeaveCriticalSection(&gTelnet_CS_Send);
}

VOID TelnetServer_Send(VOID)
{
    PCONNECTION NextConn = NULL, Connection;
    PCHATBUF NextChat = NULL;
    CHAR szText[MAX_STRING*25] = {0};
    EnterCriticalSection(&gTelnet_CS_Send);
    while (gTelnetSend) {
        NextChat=gTelnetSend->pNext;
        strcat(szText,gTelnetSend->szText);
        strcat(szText,"\r\n");
        free(gTelnetSend);
        gTelnetSend = NextChat;
    }
    LeaveCriticalSection(&gTelnet_CS_Send);

DebugSpewAlways("TelnetServer_Send: <%s>\n", szText);

    EnterCriticalSection(&gTelnet_CS_Connection);
    Connection = gTelnetConnection;
    while (Connection) {
        NextConn = Connection->pNext;
        if (Connection->Auth) send(Connection->socket,szText,strlen(szText),0);
        Connection = NextConn;
    }
    LeaveCriticalSection(&gTelnet_CS_Connection);
}

int TelnetServer_Recv(PCONNECTION Connection)
{
    CHAR szText[MAX_STRING] = {0};
    int pos = 0;
    int ret = recv(Connection->socket,szText,MAX_STRING,0);
    if ((SOCKET_ERROR != ret) && (ret>0)) {
        for (pos=0;pos<ret;pos++) {
            if ((szText[pos]==10) || (szText[pos]==13)) szText[pos]=0;
        }
        pos=0;
        while (pos<ret && ret!=SOCKET_ERROR) {
            if (szText[pos]>0) {
                if (Connection->Auth) {
                    TelnetServer_AddToChatQueue(szText+pos);
                } else {
                    if (!strcmp(gTelnetPassword,szText+pos)) {
                        Connection->Auth = TRUE;
                        send(Connection->socket,"Connected.\r\n",12,0);
                    } else {
                        send(Connection->socket,"Invalid password!\r\n",19,0);
                        ret=SOCKET_ERROR;
                    }
                }
            }
            pos += strlen(szText+pos);
            while (pos<ret && szText[pos]==0) pos++;
        }
        if (ret!=SOCKET_ERROR) ret = 0;
    }
    return ret;
}

VOID RemoveFromList(PCONNECTION Connection)
{
    EnterCriticalSection(&gTelnet_CS_Connection);
    if (gTelnetConnection == Connection) {
        gTelnetConnection = gTelnetConnection->pNext;
    } else {
        PCONNECTION LookConn = gTelnetConnection;
        while (LookConn->pNext) {
            if (LookConn->pNext = Connection) {
                LookConn->pNext = LookConn->pNext->pNext;
                LeaveCriticalSection(&gTelnet_CS_Connection);
                return;
            }
            LookConn = LookConn->pNext;
        }
    }
    LeaveCriticalSection(&gTelnet_CS_Connection);
}

DWORD WINAPI RecvThread(LPVOID lpParam)
{
    TelnetLock(1);
    PCONNECTION Connection = (PCONNECTION)lpParam;
    while (!gTelnet_Unload && Connection) {
        DebugTry(int ret = TelnetServer_Recv(Connection));
        if (ret == SOCKET_ERROR) {
            DebugSpewAlways("RecvThread: Socket error, closing connection.");
            closesocket(Connection->socket);
            RemoveFromList(Connection);
            free(Connection);
            Connection = NULL;
        } else {
            Sleep(500);
        }
    }
    if (Connection) {
        closesocket(Connection->socket);
        RemoveFromList(Connection);
        free(Connection);
        Connection=NULL;
    }
    TelnetLock(-1);
    return 0;
}

DWORD WINAPI ListenThread(LPVOID lpParam)
{
    SOCKET incoming;
    TelnetLock(1);
    while (!gTelnet_Unload) {
        DebugTry(incoming = accept(gTelnetSocket,NULL,NULL));
        if (incoming != INVALID_SOCKET) {
            int ret=0;
            sockaddr_in addr;
            if (gTelnetLocal) {
                int namesize = sizeof(addr);
                int ret;
                ret = getpeername(incoming,(sockaddr*)&addr,&namesize);
            }
            if ((gTelnet_Unload) || (ret==SOCKET_ERROR) || (gTelnetLocal && !strcmp("127.0.0.1",inet_ntoa(addr.sin_addr)))) {
                DebugSpewAlways("ListenThread: Closing new connection...");
                closesocket(incoming);
                continue;
            }
            EnterCriticalSection(&gTelnet_CS_Connection);
            DebugSpewAlways("ListenThread: New connection");
            PCONNECTION NewConn = (PCONNECTION)malloc(sizeof(CONNECTION));
            NewConn->socket = incoming;
            NewConn->Auth = FALSE;
            NewConn->pNext = gTelnetConnection;
            gTelnetConnection = NewConn;
            send(incoming,gTelnetWelcome,strlen(gTelnetWelcome),0);
            send(incoming,"\r\nPassword: ",12,0);
            DWORD ThreadId; 
            CreateThread(NULL,0,&RecvThread,(LPVOID)NewConn,0,&ThreadId); 
            LeaveCriticalSection(&gTelnet_CS_Connection);
        }
        Sleep(500);
    }
    TelnetLock(-1);
    return 0;
}

DWORD WINAPI SendThread(LPVOID lpParam)
{
    TelnetLock(1);
    while (!gTelnet_Unload) {
        if (gTelnetConnection && gTelnetSend) 
		{
			DebugTry(TelnetServer_Send());
		};
        Sleep(500);
    }
    TelnetLock(-1);
    return 0;
}

VOID SetupServer()
{
	gTelnet_Unload=0;
    SOCKADDR_IN saServer;
    gTelnetConnection = NULL;
    gTelnetPort = GetPrivateProfileInt("Telnet Server","Port",23,INIFileName);
	if (!gTelnetPort)
	{
		DebugSpewAlways("SetupServer: Port 0 specified, disabling mq2telnet");
	}
    gTelnetLocal = GetPrivateProfileInt("Telnet Server","LocalOnly",1,INIFileName);
    GetPrivateProfileString("Telnet Server","Welcome","MacroQuest telnet server",gTelnetWelcome,MAX_STRING,INIFileName);
    GetPrivateProfileString("Telnet Server","Password","macroquest",gTelnetPassword,MAX_STRING,INIFileName);
    if (!WSAOpen()) {
        DebugSpewAlways("SetupServer: Unable to start WSA");
        gTelnetServer=0;
        return;
    }
    gTelnetSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (gTelnetSocket == INVALID_SOCKET) {
        DebugSpewAlways("SetupServer: Unable to build socket");
        gTelnetServer=0;
        return;
    }

    gTelnetPort--;
    do {
        saServer.sin_family = AF_INET;
        saServer.sin_addr.s_addr = INADDR_ANY;
        saServer.sin_port = htons(++gTelnetPort);

    } while (SOCKET_ERROR == bind(gTelnetSocket,(LPSOCKADDR)&saServer,sizeof(struct sockaddr)));

    if (SOCKET_ERROR == listen(gTelnetSocket,SOMAXCONN)) {
        DebugSpewAlways("SetupServer: Unable to listen on port %d",gTelnetPort);
        closesocket(gTelnetSocket);
        gTelnetServer=0;
        return;
    }
    DWORD ThreadId; 
    CreateThread(NULL,0,&ListenThread,NULL,0,&ThreadId);
    CreateThread(NULL,0,&SendThread,NULL,0,&ThreadId);
    DebugSpewAlways("SetupServer: Telnet server is up and running on port %d",gTelnetPort);
}

VOID CloseServer()
{
	gTelnet_Unload=1;
    DWORD Locks = 1;
    closesocket(gTelnetSocket);
    while (Locks>0) {
        EnterCriticalSection(&gTelnet_CS_Lock);
        Locks = gTelnet_LockCount;
        LeaveCriticalSection(&gTelnet_CS_Lock);
        if (Locks>0) Sleep(500);
    }
//    DeleteCriticalSection(&gTelnet_CS_Lock);
//    DeleteCriticalSection(&gTelnet_CS_Connection);

    PCHATBUF NextQueue = NULL;
    PCONNECTION NextConn = NULL;
    while (gTelnetSend) {
        NextQueue = gTelnetSend->pNext;
        free(gTelnetSend);
        gTelnetSend = NextQueue;
    }
    while (gTelnetRecv) {
        NextQueue = gTelnetRecv->pNext;
        free(gTelnetRecv);
        gTelnetRecv = NextQueue;
    }
    while (gTelnetConnection) {
        NextConn = gTelnetConnection->pNext;
        free(gTelnetConnection);
        gTelnetConnection = NextConn;
    }
    WSACleanup();
}

VOID ListConnections(PSPAWNINFO pChar, CHAR *szLine)
{
    sockaddr_in addr;
    PCONNECTION NextConn = NULL, Connection;
    DWORD count = 0;
    int namesize;
    CHAR szTemp[MAX_STRING] = {0};
    //if (gFilterMacro==FILTERMACRO_NONE) return;
    if (!gTelnetServer) {
        WriteChatColor("Telnet server isn't running.",USERCOLOR_DEFAULT);
        return;
    }
    sprintf(szTemp,"Listing telnet connections for port %d:",gTelnetPort);
    WriteChatColor(szTemp,USERCOLOR_DEFAULT);
    EnterCriticalSection(&gTelnet_CS_Connection);
    Connection = gTelnetConnection;
    while (Connection) {
        NextConn = Connection->pNext;
        namesize = sizeof(addr);
        if (SOCKET_ERROR != getpeername(Connection->socket,(sockaddr*)&addr,&namesize)) {
            count++;
            sprintf(szTemp,"   %s",inet_ntoa(addr.sin_addr));
            WriteChatColor(szTemp,USERCOLOR_DEFAULT);
        }
        Connection = NextConn;
    }
    LeaveCriticalSection(&gTelnet_CS_Connection);
    sprintf(szTemp,"%d connections listed.",count);
    WriteChatColor(szTemp,USERCOLOR_DEFAULT);
}

VOID ProcessServer()
{
    // Handle input queue during Pulse()...
    EnterCriticalSection(&gTelnet_CS_Recv);
    if (gTelnetRecv) {
        CHATBUF RecvBuf;
        memcpy(&RecvBuf, gTelnetRecv, sizeof(CHATBUF));
        free(gTelnetRecv);
        gTelnetRecv = RecvBuf.pNext;
        LeaveCriticalSection(&gTelnet_CS_Recv);
        PCHARINFO pCharInfo = GetCharInfo();
        if (pCharInfo) DoCommand(pCharInfo->pSpawn,RecvBuf.szText);
    } else {
        LeaveCriticalSection(&gTelnet_CS_Recv);
    }

}
