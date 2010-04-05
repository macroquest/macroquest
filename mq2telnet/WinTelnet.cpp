#include <winsock2.h>
#include "wintelnet.h"

CWinTelnet::CWinTelnet(void)
{
    Valid=true;
    //if (WSAStartup(MAKEWORD(2,0),&wsa) || (HIBYTE(wsa.wVersion) != 0) || (LOBYTE(wsa.wVersion) != 2))
    //{
    //    Valid=false;
    //}
    m_Socket=INVALID_SOCKET;    // init socket to invalid
}

CWinTelnet::~CWinTelnet(void)
{
    if (m_Socket!=INVALID_SOCKET)
    {
        // non-graceful disconnect
        shutdown(m_Socket,SD_BOTH);
        closesocket(m_Socket);
        m_Socket=INVALID_SOCKET;
    }
    //WSACleanup();
}

bool CWinTelnet::Connect(char* addr , int port)
{
    if (m_Socket==INVALID_SOCKET)
        return false; // If it's an invalid socket, get out of here
    SOCKADDR_IN sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));

    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr(addr);     // check if address is x.x.x.x format
    if (sockAddr.sin_addr.s_addr == INADDR_NONE)                // if not, we resolve hostname
    {
        LPHOSTENT lphost;
        lphost = gethostbyname(addr);
        if (lphost != NULL)
            sockAddr.sin_addr.s_addr = ((LPIN_ADDR)lphost->h_addr)->s_addr;
        else
        {
            return FALSE;
        }
    }

    sockAddr.sin_port = htons((u_short)port);

    if (int ret=WSAConnect(m_Socket, (SOCKADDR*)&sockAddr, sizeof(sockAddr),NULL,NULL,NULL,NULL)==SOCKET_ERROR)
    {
        ret=WSAGetLastError();
        if (ret==WSAEISCONN)
            return true;
        if (ret!=WSAEWOULDBLOCK)
        {
            return false;
        }
    }
    return true;

    /*
    int ret=0;
    int n=0;
    do
    {
    if (ret=WSAConnect(m_Socket, (SOCKADDR*)&sockAddr, sizeof(sockAddr),NULL,NULL,NULL,NULL)==SOCKET_ERROR)
    {
    ret=WSAGetLastError();
    if (ret==WSAEISCONN)
    return true;
    if (ret!=WSAEWOULDBLOCK)
    {
    //
    //                char buffer[128];
    //                strcpy(buffer,ErrorName(ret));
    return false;
    }
    if (n++<10)
    {            
    return false;
    }
    }
    Sleep(10);

    } while(ret==WSAEWOULDBLOCK);

    return true;
    /**/
}
bool CWinTelnet::Disconnect(void)
{
    if (m_Socket==INVALID_SOCKET)
        return false;
    return (shutdown(m_Socket,SD_BOTH)==0);
}
bool CWinTelnet::Open (int nPort)
{
    if (!Valid)
        return false;
    if (m_Socket == INVALID_SOCKET)
    {
        // If the socket is invalid, we are allowed to make a new socket

        m_Socket = WSASocket(PF_INET, SOCK_STREAM, 0,NULL,0,0);
        if (m_Socket == INVALID_SOCKET)
            return false; // If it's still invalid.. uhh.. umm...
    }

    // Make sure blocking mode is turned OFF!
    unsigned long falsifyblocking=1;
    if (ioctlsocket(m_Socket,FIONBIO,&falsifyblocking)==SOCKET_ERROR)
        return false;
    SOCKADDR_IN sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));

    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = INADDR_ANY;
    sockAddr.sin_port = htons((u_short)nPort);

    if (bind(m_Socket,((SOCKADDR*)&sockAddr),sizeof(SOCKADDR))!=0)
        return false;


    return true;
}
bool CWinTelnet::Close(void)
{
    if (m_Socket!=INVALID_SOCKET)
        closesocket(m_Socket);
    m_Socket=INVALID_SOCKET;
    return true;
}
bool CWinTelnet::Write(char csend)
{
    if (m_Socket==INVALID_SOCKET)
        return false;
    return (send(m_Socket,&csend,sizeof(char),0)==1);
}
int  CWinTelnet::Write(const void* csend, int length)
{
    if (m_Socket==INVALID_SOCKET)
        return 0;
    int ret = send(m_Socket,(char*)csend,length,0);
    if (ret==SOCKET_ERROR)
        return 0;
    return ret;
}

int  CWinTelnet::WriteStr(const char* csend)
{
    if (m_Socket==INVALID_SOCKET)
        return 0;
    int ret = send(m_Socket,(char*)csend,strlen(csend),0);
    if (ret==SOCKET_ERROR)
        return 0;
    return ret;
}
bool CWinTelnet::Read(char* crecv)
{
    if (m_Socket==INVALID_SOCKET)
        return false;
    return (recv(m_Socket,crecv,1,0)==1);
}
int  CWinTelnet::Read(void* crecv, int length)
{
    if (m_Socket==INVALID_SOCKET)
        return 0;
    int ret = recv(m_Socket,(char*)crecv,length,0);
    if (ret==SOCKET_ERROR)
        return 0;
    return StripTelnet((unsigned char*)crecv,ret);
}
bool CWinTelnet::isOpen(void)
{
    return (m_Socket!=INVALID_SOCKET);
}
bool CWinTelnet::isConnected(void)
{
    if (m_Socket==INVALID_SOCKET)
        return false;
    char szBuffer[1]="";
    int err = recv(m_Socket,szBuffer,1,MSG_PEEK);
    if (err==1)
        return true;
    if (err==0)
        return false;
    err=WSAGetLastError();
    if (err==WSAECONNRESET 
        || err==WSAENOTCONN
        || err==WSAENETRESET
        || err==WSAENOTSOCK
        || err==WSAESHUTDOWN
        || err==WSAEINVAL
        || err==WSAECONNABORTED
        )
        return false;
    return true;
}
long CWinTelnet::isData(void)
{
    unsigned long result;
    if (ioctlsocket(m_Socket,FIONREAD,&result)!=0)
        return 0;
    return result;
}
