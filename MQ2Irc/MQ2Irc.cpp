// PLUGIN_API is only to be used for callbacks. All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use. Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.

// Updated 9/24/04 - Sanity Checks, Window INI Position Saves, fixes, and /istatus
// Updated 1/25/12 by Sym - Added timestamp toggle for mirc style output, /itimestamp on|off. Code borrowed from MQ2TimeStamp.
// Updated 4/17/17 by Sym - Updated for a recent patch
// Updated 8/27/17 by Eqmule - Added Stringsafeness


#pragma comment(lib,"wsock32.lib")
#include "../MQ2Plugin.h"
#include <list>

PreSetup("MQ2Irc");

bool      bStamp;

typedef struct _TIMESTAMP {
   CHAR Server[0x20];
   CHAR Character[0x40];
   BOOL Location;
   CHAR Format[MAX_STRING];
   struct _TIMESTAMP *pNext;
} TIMESTAMP, *PTIMESTAMP;

struct tm   *currentTime;
time_t   long_time;


CHAR szIrcServer[MAX_STRING] = {0};
CHAR szIrcNick[MAX_STRING] = {0};
CHAR szIrcPort[MAX_STRING] = {0};
CHAR szIrcChan[MAX_STRING] = {0};
CHAR IrcServer[MAX_STRING] = {0};
CHAR IrcNick[MAX_STRING] = {0};
CHAR IrcPort[MAX_STRING] = {0};
CHAR IrcChan[MAX_STRING] = {0};
CHAR Version[MAX_STRING] = {0};
CHAR Username[MAX_STRING] = {0};
CHAR Realname[MAX_STRING] = {0};
CHAR UseWnd[MAX_STRING] = {0};
CHAR UseTimeStamp[MAX_STRING] = {0};
CHAR strTimeBuffer[MAX_STRING] = {0};
CHAR szTemp[MAX_STRING] = {0};
CHAR strDefault[MAX_STRING] = {0};

INT         maxLength;
PTIMESTAMP   pTimestamp=0, pCurrentTimestamp=0;

DWORD irctop = 0, ircbottom = 0, ircleft = 0, ircright = 0;

WORD sockVersion;
WSADATA wsaData;
int nret;
LPHOSTENT hostEntry;
SOCKET theSocket;
CHAR *ireadbuf = new CHAR[512];
CHAR buff[512];
std::list<char *> channels;
std::list<char *>::iterator mychan;
void *pchan;


unsigned long IRCChatColor=111111;


CRITICAL_SECTION ConnectCS;
bool bConnecting=false;
bool bTriedConnect=false;
bool bConnected=false;
SOCKADDR_IN serverInfo;
class CIRCWnd;
CIRCWnd *MyWnd=0;
void ircout(char *text);
class CIRCWnd : public CCustomWnd
{
public:
    CIRCWnd(CXStr *Template):CCustomWnd(Template)
    {
        SetWndNotification(CIRCWnd);
        StmlOut = (CStmlWnd *)GetChildItem("CW_ChatOutput");
        OutWnd = (CXWnd*)StmlOut;
        //      OutWnd = GetChildItem("CW_ChatOutput");
        // ^ Retarded monkeys should not code ^
        OutStruct = (_CSIDLWND *)GetChildItem("CW_ChatOutput");

        InputBox=(CTextEntryWnd*)GetChildItem("CW_ChatInput");
        InputBox->WindowStyle|=0x800C0;
        InputBox->CRNormal|=0xFFFFFFFF;
        InputBox->SetMaxChars(512);
        BitOff(WindowStyle,CWS_CLOSE);
    }

    int WndNotification(CXWnd *pWnd, unsigned int Message, void *data)
    {
        if (pWnd==(CXWnd*)InputBox)
        {
            if (Message==XWM_HITENTER)
            {
                char szBuffer[MAX_STRING] = { 0 };
                GetCXStr((PCXSTR)InputBox->InputText,szBuffer,MAX_STRING);
                if (szBuffer[0])
                {
                    if(channels.size()<1) {
                        ircout("\ar#\a-w You are not on any channels.");
                    } else {
                        sprintf_s(buff,"PRIVMSG %s :%s\n\0",*mychan,szBuffer); 
                        send(theSocket,buff,strlen(buff),0); 
                        sprintf_s(buff,"\ag<\aw%s\ag>\a-w %s\0",IrcNick,szBuffer); 
                        ircout(buff);
                    }

                    //               OutputBox->AppendSTML(szBuffer);
                    //               DebugSpew("%s",szBuffer);
                    SetCXStr(&InputBox->InputText,"");
                    //               DoCommand((PSPAWNINFO)pCharSpawn,szBuffer);


                }
                ((CXWnd*)InputBox)->ClrFocus();
            }
            else
                DebugSpew("InputBox message %Xh, value: %Xh",Message,data);
        }
        //      else if (pWnd==(CXWnd*)OutputBox)
        //      {
        //         DebugSpew("OutputBox message %Xh, value: %Xh",Message,data);
        //      }
        else if (pWnd==0)
        {
            if (Message==XWM_CLOSE)
            {
                dShow=1;
                return 0;
                //MyWnd=0;
            }
            else
                DebugSpew("CIRCWnd message %Xh, value: %Xh",Message,data);
        }
        else
        {
            //         DebugSpew("Wnd: 0x%X, Msg: 0x%X, value: %Xh",pWnd,Message,data);
        }
        return CSidlScreenWnd::WndNotification(pWnd,Message,data);
    }

    ~CIRCWnd()
    {
    }

    CTextEntryWnd *InputBox;
    CStmlWnd *StmlOut;
    CXWnd *OutWnd;
    struct _CSIDLWND *OutStruct;
};
void ircout(char *text) {
   if (bStamp)
   {
        time(&long_time);
		localtime_s(currentTime,&long_time);

        strftime(strTimeBuffer, maxLength, strDefault, currentTime);
        strcat_s(strTimeBuffer, text);
        text = strTimeBuffer;
   }


    if(MyWnd && !strcmp(UseWnd,"Yes")) {
        DebugTry(((CXWnd*)MyWnd)->Show(1,1));
        char processed[MAX_STRING];
        StripMQChat(text,processed);
        CheckChatForEvent(processed);
        MQToSTML(text,processed,MAX_STRING);
        strcat_s(processed,"<br>");
        CXStr NewText(processed);
        (MyWnd->StmlOut)->AppendSTML(NewText);
        (MyWnd->OutWnd)->SetVScrollPos(MyWnd->OutStruct->VScrollMax);
    } else {
        WriteChatColor(text,IRCChatColor);
    }
    return;
}
DWORD WINAPI IRCConnectThread(LPVOID lpParam)
{
    EnterCriticalSection(&ConnectCS);
    bConnecting=true;
    nret = connect(theSocket,(LPSOCKADDR)&serverInfo,sizeof(struct sockaddr));
    if (nret == SOCKET_ERROR) {
        bConnected=false;
    }
    else
    {
        unsigned long nonblocking = 1;
        ioctlsocket(theSocket,FIONBIO,&nonblocking);
        Sleep((clock_t)2 * CLOCKS_PER_SEC/2);

        sprintf_s(buff,"NICK %s\n\0",IrcNick);
        send(theSocket,buff,strlen(buff),0);
        sprintf_s(buff,"USER %s %s %s :%s\n\0",Username,IrcNick,IrcNick,Realname);
        send(theSocket,buff,strlen(buff),0);
        sprintf_s(buff,"JOIN %s\n\0",IrcChan);
        send(theSocket,buff,strlen(buff),0);
        bConnected=true;
    }
    bTriedConnect=true;

    bConnecting=false;
    LeaveCriticalSection(&ConnectCS);
    return 0;
}

VOID TimeStampCmd(PSPAWNINFO pChar, PCHAR szLine)
{
   // Get first arg and check command
   GetArg(szTemp, szLine, 1);
   if (_stricmp(szTemp, "on") == 0) {
      bStamp = true;
      WriteChatColor("IRC Timestamp on.");
      WritePrivateProfileString("Settings","UseTimeStamp","Yes",INIFileName);
   } else if (_stricmp(szTemp, "off") == 0) {
      bStamp = false;
      WriteChatColor("IRC Timestamp off.");
      WritePrivateProfileString("Settings","UseTimeStamp","No",INIFileName);
   }
}
VOID IrcStatusCmd(PSPAWNINFO pChar, PCHAR szLine)
{
    if (bConnected) {
        // Connected
        sprintf_s(buff,"\ar#\ax MQ2Irc Status: ONLINE - %s - %s - %s - %s",IrcServer,IrcPort,IrcChan,IrcNick);
        ircout(buff);
    } else {
        // Not Connected
        ircout("\ar#\ax MQ2Irc Status: OFFLINE");
    }

}


VOID IrcConnectCmd(PSPAWNINFO pChar, PCHAR szLine)
{ // /iconnect server port chan nick OR /iconnect inikey
    if (bConnected) {
        ircout("\ar#\ax Already connected. Use /i quit to disconnect first.");
        return;
    }
    if (bConnecting)
    {
        ircout("\ar#\ax Already trying to connect! Hold on a minute there");
        return;
    }
    CHAR Arg1[MAX_STRING] = {0};
    CHAR Arg2[MAX_STRING] = {0};
    CHAR Arg3[MAX_STRING] = {0};
    CHAR Arg4[MAX_STRING] = {0};

    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);
    GetArg(Arg3,szLine,3);
    GetArg(Arg4,szLine,4);
    if (Arg1[0]==0 && Arg2[0]==0 && Arg3[0]==0 && Arg4[0]==0) {
        GetPrivateProfileString("Last Connect","Server","irc.ipdn.org",IrcServer,MAX_STRING,INIFileName);
        GetPrivateProfileString("Last Connect","Port","6667",IrcPort,MAX_STRING,INIFileName);
        GetPrivateProfileString("Last Connect","Chan","#macroquest",IrcChan,MAX_STRING,INIFileName);
        GetPrivateProfileString("Last Connect","Nick","What-Ini",IrcNick,MAX_STRING,INIFileName);
    } else if (Arg2[0]==0 && Arg3[0]==0 && Arg4[0]==0) {
        GetPrivateProfileString(Arg1,"Server","irc.ipdn.org",IrcServer,MAX_STRING,INIFileName);
        GetPrivateProfileString(Arg1,"Port","6667",IrcPort,MAX_STRING,INIFileName);
        GetPrivateProfileString(Arg1,"Chan","#macroquest",IrcChan,MAX_STRING,INIFileName);
        GetPrivateProfileString(Arg1,"Nick","What-Ini",IrcNick,MAX_STRING,INIFileName);
    } else if (Arg3[0]==0 && Arg4[0]==0) {
        sprintf_s(IrcServer,"%s",Arg1);
        sprintf_s(IrcPort,"%s",Arg2);

    } else if (Arg4[0]==0) {
        sprintf_s(IrcServer,"%s",Arg1);
        sprintf_s(IrcPort,"%s",Arg2);
        sprintf_s(IrcChan,"%s",Arg3);
    } else {
        sprintf_s(IrcServer,"%s",Arg1);
        sprintf_s(IrcPort,"%s",Arg2);
        sprintf_s(IrcChan,"%s",Arg3);
        sprintf_s(IrcNick,"%s",Arg4);
    }
    WritePrivateProfileString("Last Connect","Server",IrcServer,INIFileName);
    WritePrivateProfileString("Last Connect","Port",IrcPort,INIFileName);
    WritePrivateProfileString("Last Connect","Chan",IrcChan,INIFileName);
    WritePrivateProfileString("Last Connect","Nick",IrcNick,INIFileName);
    WritePrivateProfileString(IrcServer,"Server",IrcServer,INIFileName);
    WritePrivateProfileString(IrcServer,"Port",IrcPort,INIFileName);
    WritePrivateProfileString(IrcServer,"Chan",IrcChan,INIFileName);
    WritePrivateProfileString(IrcServer,"Nick",IrcNick,INIFileName);
    WritePrivateProfileString("Settings","Version",Version,INIFileName);
    WritePrivateProfileString("Settings","Username",Username,INIFileName);
    WritePrivateProfileString("Settings","Realname",Realname,INIFileName);
    if(MyWnd) {
        sprintf_s(buff,"%s [%s]",IrcChan,IrcServer);
        SetCXStr(&MyWnd->OutStruct->WindowText,buff);
    }
    sockVersion = MAKEWORD(1, 1);
    WSAStartup(sockVersion, &wsaData);
    hostEntry = gethostbyname(IrcServer);
    if (!hostEntry) {
        ircout("\ar#\ax gethostbyname error");
        WSACleanup();
        return;
    }
    theSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (theSocket == INVALID_SOCKET) {
        ircout("\ar#\ax Socket error");
        WSACleanup();
        return;
    }
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_addr = *((LPIN_ADDR)*hostEntry->h_addr_list);
    serverInfo.sin_port = htons(atoi(IrcPort));
    DWORD ThreadId;
    CreateThread(NULL,0,&IRCConnectThread,0,0,&ThreadId);
    return;
}


VOID IrcCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szCmd[MAX_STRING] = { 0 };
	strcpy_s(szCmd, szLine);

    if (!bConnected) {
        ircout("\ar#\ax You are not connected. Please use /iconnect to establish a connection.");
        return;
    }
    //NICK JOIN PART QUIT MSG SAY RAW

    //parse out cmd:
    CHAR *z[2];
    int y;
    z[0] = szLine;
    for (y = 1; *szLine != '\0'; ) {
        if (*szLine == ' ') {
            *szLine = '\0';
            z[y++] = ++szLine;
            break;
        } else {
            szLine++;
        }
    }
	CHAR szArg1[MAX_STRING] = { 0 };
	CHAR szArg2[MAX_STRING] = { 0 };
	strcpy_s(szArg1,z[0]);
	strcpy_s(szArg2,z[1]);
	_strupr_s(szArg1);
    if(!strcmp(szArg1,"NICK")) {
        sprintf_s(buff,"NICK %s\n\0",z[1]);
        send(theSocket,buff,strlen(buff),0);
        WritePrivateProfileString("Last Connect","Nick",IrcNick,INIFileName);
        WritePrivateProfileString(IrcServer,"Nick",IrcNick,INIFileName);
        return;
    } else if(!strcmp(szArg1,"JOIN")) {
        sprintf_s(buff,"JOIN %s\n\0",z[1]);
        send(theSocket,buff,strlen(buff),0);
        WritePrivateProfileString("Last Connect","Chan",IrcChan,INIFileName);
        WritePrivateProfileString(IrcServer,"Chan",IrcChan,INIFileName);
        return;
    } else if(!strcmp(szArg1,"PART")) {
        sprintf_s(buff,"PART %s\n\0",*mychan);
        send(theSocket,buff,strlen(buff),0);
        return;
    } else if(!strcmp(szArg1,"WHOIS")) {
        sprintf_s(buff,"WHOIS %s\n\0",z[1]);
        send(theSocket,buff,strlen(buff),0);
        return;
    } else if(!strcmp(szArg1,"HELP")) {
        sprintf_s(buff,"\ar#\ax Supported Commands:\n\ar#\ax NICK JOIN PART WHOIS MSG SAY RAW QUIT NAMES X HELP");
        ircout(buff);
        return;
    } else if(!strcmp(szArg1,"QUIT")) {
        sprintf_s(buff,"QUIT :%s\n\0",z[1]);
        send(theSocket,buff,strlen(buff),0);
        bConnected=false;
        ircout("\ar#\ax Connection Closed, you can unload MQ2Irc now.");
        return;
    } else if(!strcmp(szArg1,"RAW")) {
        sprintf_s(buff,"%s\n\0",z[1]);
        send(theSocket,buff,strlen(buff),0);
        sprintf_s(buff,"\ab[\a-yraw\ab(\ay%s\ab)]\a-w %s\0", IrcServer, z[1]);
        ircout(buff);
        return;
    } else if(!strcmp(szArg1,"SAY")) {
        if(channels.size()<1) {
            ircout("\ar#\a-w You are not on any channels.");
            return;
        } else {
            sprintf_s(buff,"PRIVMSG %s :%s\n\0",*mychan,z[1]);
            send(theSocket,buff,strlen(buff),0);
            sprintf_s(buff,"\ag<\aw%s\ag>\a-w %s\0",IrcNick,z[1]);
            ircout(buff);
            return;
        }
    } else if(!strcmp(szArg1,"NAMES")) {
        sprintf_s(buff,"NAMES %s\n\0",IrcChan);
        send(theSocket,buff,strlen(buff),0);
        return;
    } else if(!strcmp(szArg1,"X")) {
        mychan++;
        if(mychan == channels.end())
            mychan = channels.begin();
        if(MyWnd) {
            sprintf_s(buff,"%s [%s]",*mychan,IrcServer);
            SetCXStr(&MyWnd->OutStruct->WindowText,buff);
        }
        sprintf_s(buff, "\ar#\a-w Now speaking in \aw%s\a-w.", *mychan);
        ircout(buff);
    } else if(!strcmp(szArg1,"MSG")) {
        for (y = 2; *szLine != '\0'; ) {
            if (*szLine == ' ') {
                *szLine = '\0';
                z[y++] = ++szLine;
                break;
            } else {
                szLine++;
            }
        }
        sprintf_s(buff,"PRIVMSG %s :%s\n\0", z[1],z[2]);
        send(theSocket,buff,strlen(buff),0);
        sprintf_s(buff,"\ab[\a-rmsg\ab(\ar%s\ab)]\a-w %s\0", z[1], z[2]);
        ircout(buff);
        return;
    } else {
        ircout("\ar#\a-w Invalid Command, /i help for a list of commands");
    }
}

CHAR *parse(CHAR *rawmsg) { //take raw irc protocol message and return human readable
    /* The BNF representation for this is:
    <message> ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
    <prefix> ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
    <command> ::= <letter> { <letter> } | <number> <number> <number>
    <SPACE> ::= ' ' { ' ' }
    <params> ::= <SPACE> [ ':' <trailing> | <middle> <params> ]
    <middle> ::= <Any *non-empty* sequence of octets not including SPACE
    or NUL or CR or LF, the first of which may not be ':'>
    <trailing> ::= <Any, possibly *empty*, sequence of octets not including
    NUL or CR or LF>
    <crlf> ::= CR LF
    */
    CHAR Arg1[MAX_STRING] = {0};
    CHAR Arg2[MAX_STRING] = {0};
    CHAR Arg3[MAX_STRING] = {0};
    CHAR Arg4[MAX_STRING] = {0};
    int x = 0,y;
    CHAR *prefix = NULL, *tmp, *tmpb, *param[32], *command, *lnk;
    sprintf_s(buff,"%s",rawmsg); //save a copy of the original

    lnk = strchr(rawmsg, 0x12);
    while(lnk!=NULL) {
        *lnk = ' ';
        lnk = strchr(rawmsg, 0x12);
    }

    tmp = rawmsg; //use a new pointer, leave the original where it was
    if(*tmp == ':') { //is there a prefix on this data?
        tmpb = ++tmp;
        while(1) {
            if(*tmp == ' ') {
                *tmp = '\0';
                break;
            }
            tmp++;
        }
        prefix = tmpb;
        if(strchr(tmpb,'!') != NULL) {
            while(1) {
                tmpb++;
                if(*tmpb == '!') {
                    *tmpb = '\0';
                    break;
                }
            }
        }
        //store the next word as the command
        command = ++tmp;
        while(1) {
            if(*tmp == ' ') {
                *tmp = '\0';
                break;
            }
            tmp++;
        }
    } else { //there is no prefix and the first word is the command
        command = tmp;
        while(1) {
            if(*tmp == ' ') {
                *tmp = '\0';
                break;
            }
            tmp++;
        }
    }
    param[x] = ++tmp; //make the next word the first paramater
    if(*tmp != ':') { //make sure it isnt set to be the last parameter
        for(x = 1; *tmp != '\0'; ) { //keep making each word another paramater
            if(*tmp == ' ') {
                *tmp = '\0';
                tmp++;
                if(*tmp == ':') { //but stop and store the rest of the line as the last
                    //parameter if we get one that starts with a :
                    param[x++] = ++tmp;
                    break;
                } else {
                    param[x++] = tmp++;
                }
            } else {
                tmp++;
            }
        }
    } else { //it was set to be the last one, store it as the only paramater and continue
        param[x++] = ++tmp;
    }
    if(!strcmp(command,"PING")) {
        sprintf_s(buff,"PONG %s\n\0", param[0]);
        send(theSocket,buff,strlen(buff),0);
        return NULL;
    } else if(!strcmp(command,"NICK")) {
        if(!strcmp(IrcNick,prefix)) {
            sprintf_s(IrcNick,"%s\0",param[0]);
            IrcNick[strlen(IrcNick)-1] = '\0';
            WritePrivateProfileString("Last Connect","Nick",IrcNick,INIFileName);
            WritePrivateProfileString(IrcServer,"Nick",IrcNick,INIFileName);
        }
        sprintf_s(buff,"\ar*\a-w %s changed nickname to \aw%s\a-w.\0", prefix, param[0]);
        return buff;
    } else if(!strcmp(command,"JOIN")) {
        if(!strcmp(IrcNick,prefix)) {
            sprintf_s(IrcChan,"%s\0",param[0]);
            IrcChan[strlen(IrcChan)-1] = '\0';
            if(pchan = malloc(sizeof(IrcChan))) {
				sprintf_s((char *)pchan,sizeof(IrcChan), "%s", IrcChan); 
				channels.push_front((char *)pchan); 
				mychan = channels.begin(); 
				if(MyWnd) { 
					sprintf_s(buff,"%s [%s]",*mychan,IrcServer); 
					SetCXStr(&MyWnd->OutStruct->WindowText,buff); 
				} 
				WritePrivateProfileString("Last Connect","Chan",*mychan,INIFileName); 
				WritePrivateProfileString(IrcServer,"Chan",*mychan,INIFileName); 
				sprintf_s(buff,"\ar#\a-w Now speaking in \aw%s\a-w.", *mychan); 
				ircout(buff); 
			}
        }
        sprintf_s(buff,"\ar*\aw %s\a-w joined %s.\0", prefix, param[0]);
        return buff;
    } else if(!strcmp(command,"PART")) {
        param[0][strlen(param[0])-1] = '\0';
        if(!strcmp(IrcNick,prefix)) {
            channels.erase(mychan);
            if(channels.size()<1) {
                if(MyWnd) {
                    sprintf_s(buff,"No Channel [%s]",IrcServer);
                    SetCXStr(&MyWnd->OutStruct->WindowText,buff);
                }
                sprintf_s(buff,"\ar#\a-w No longer on any channels.");
                return buff;
            } else {
                mychan = channels.begin();
                if(MyWnd) {
                    sprintf_s(buff,"%s [%s]",*mychan,IrcServer);
                    SetCXStr(&MyWnd->OutStruct->WindowText,buff);
                }
                WritePrivateProfileString("Last Connect","Chan",*mychan,INIFileName);
                WritePrivateProfileString(IrcServer,"Chan",*mychan,INIFileName);
                sprintf_s(buff,"\ar#\a-w Now speaking in \aw%s\a-w.", *mychan);
                return buff;
            }
        }
        sprintf_s(buff,"\ar*\aw %s\a-w left %s\0", prefix, param[0]);
        return buff;
    } else if(!strcmp(command,"MODE")) {
        sprintf_s(buff,"\ar*\aw %s set mode \"\aw", prefix);
        for(y=1;y<x;) {
            strcat_s(buff,param[y++]);
            strcat_s(buff," ");
        }
        strcat_s(buff,"\" ");
        strcat_s(buff,param[0]);
        return buff;
    } else if(!strcmp(command,"PRIVMSG")) {
        param[1][strlen(param[1])-1] = '\0';
        if(!strcmp(param[1],"\001VERSION\001")) {
            sprintf_s(buff,"NOTICE %s :\001VERSION %s\001\n\0",prefix,Version);
            send(theSocket,buff,strlen(buff),0);
            sprintf_s(buff,"\ab[\ao%s\ab(\a-octcp\ab)]\a-w VERSION", prefix);
            return buff;
        }

        if(!strcmp(IrcNick, param[0])) {
            sprintf_s(buff,"\ab[\ap%s\ab(\a-pmsg\ab)]\a-w %s\0", prefix, param[1]);

            //         sprintf_s(Arg1,"%s tells you, '%s'", prefix, param[1]);
            //         CheckChatForEvent(Arg1);
            return buff;
        } else {
            if(!strcmp(*mychan, param[0])) {
                sprintf_s(buff,"\ag<\a-w%s\ag>\a-w %s\0", prefix, param[1]);
                //            sprintf_s(Arg1,"%s tells the group, '%s'", prefix, param[1]);
                //            CheckChatForEvent(Arg1);
                return buff;
            } else {
                sprintf_s(buff,"\ag<\a-w%s\ag/\a-w%s\ag>\a-w %s\0", prefix, param[0], param[1]);
                return buff;
            }
        }
    } else if(!strcmp(command,"NOTICE")) {
        sprintf_s(buff,"\ab[\ao%s\ab(\a-onotice\ab)]\a-w %s\0", prefix, param[1]);
        return buff;
    } else if(!strcmp(command,"TOPIC")) {
        sprintf_s(buff,"\ar*\aw %s\a-w changed topic on \aw%s\a-w to: %s\0", prefix, param[0], param[1]);
        return buff;
    } else if(!strcmp(command,"KICK")) {
        sprintf_s(buff,"\ar*\aw %s\a-w kicked from %s by \aw%s\a-w (%s)", param[1], param[0], prefix, param[2]);
        return buff;
    } else if(!strcmp(command,"QUIT")) {
        sprintf_s(buff,"\ar*\aw %s\a-w quit IRC (%s)\0", prefix, param[0]);
        return buff;
    } else if(!strcmp(command,"ERROR")) {
        sprintf_s(buff,"\ar#\a-w Server error: %s\0", param[0]);
        return buff;
    } else if(atoi(command) > 0) {
        switch(atoi(command)) {
            //it wasnt one of the above commands, maybe its a numeric
         case 001:
             sprintf_s(buff,"%s\0", param[1]);
             sprintf_s(IrcNick,"%s", param[0]);
             return buff;
         case 002:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 003:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 004:
             return NULL;
         case 005:
             return NULL;
         case 251:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 252:
             sprintf_s(buff,"%s %s\0", param[1], param[2]);
             return buff;
         case 254:
             sprintf_s(buff,"%s %s\0", param[1], param[2]);
             return buff;
         case 255:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 265:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 266:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 250:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 375:
             return NULL;
         case 372:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 376:
             sprintf_s(buff,"%s\0", param[1]);
             return buff;
         case 401:
             sprintf_s(buff,"\ar#\a-w %s: %s\0", param[1], param[2]);
             return buff;
         case 421:
             sprintf_s(buff,"\ar#\a-w Server doesn't recognize command \aw%s\a-w\0", param[1]);
             return buff;
         case 422:
             sprintf_s(buff,"\ar#\a-w Server has no MOTD\0");
             return buff;
         case 311:
             sprintf_s(buff,"\ar#\aw %s\a-w %s@%s (%s)\0", param[1], param[2], param[3], param[5]);
             return buff;
         case 312:
             sprintf_s(buff,"\ar#\aw %s\a-w %s (%s)\0", param[1], param[2], param[3]);
             return buff;
         case 338:
             sprintf_s(buff,"\ar#\aw %s\a-w connecting from %s\0", param[1], param[2]);
             return buff;
         case 317:
             sprintf_s(buff,"\ar#\aw %s\a-w %s seconds idle\0", param[1], param[2]);
             return buff;
         case 318:
             sprintf_s(buff,"\ar#\aw %s\a-w %s\0", param[1], param[2]);
             return buff;
         case 378:
             sprintf_s(buff,"\ar#\a-w %s %s\0", param[1], param[2]);
             return buff;
         case 433:
             sprintf_s(buff,"\ar#\a-w %s %s\0", param[1], param[2]);
             return buff;
         case 451:
             sprintf_s(buff,"\ar#\a-w Not registered with server\0");
             return buff;
         case 319:
             sprintf_s(buff,"\ar#\aw %s\a-w %s\0", param[1], param[2]);
             return buff;
         case 442:
             sprintf_s(buff,"\ar#\a-w %s %s\0", param[1], param[2]);
             return buff;
         case 332:
             sprintf_s(buff,"\ar#\a-w Topic for \aw%s\a-w: %s\0", param[1], param[2]);
             return buff;
         case 333:
             sprintf_s(buff,"\ar#\a-w Set by \aw%s\a-w\0", param[2]);
             return buff;
         case 353:
             sprintf_s(buff,"\ar#\a-w Names on \aw%s\a-w\n\ar#\a-w %s\0", IrcChan, param[3]);
             return buff;
         case 366:
             sprintf_s(buff,"\ar#\a-w End of /names list\0");
             return buff;
         default: //if its not one of those, its a numeric we havnt set up, just
             //dump the raw irc message to the screen
             return buff;
        }
    } else { //wasnt a normal command, and wasnt numeric.. something didnt work right
        ircout("DEBUG Couldnt parse correctly...");
        sprintf_s(buff,"DEBUG: command = %s\0", command);
        for(y = 0; y<x;) {
            sprintf_s(buff,"DEBUG param[%i] = %s\0", y, param[y]);
            ircout(buff);
            y++;
        }
        return buff;
    }
}

class MQ2IrcType *pIrcType=0;

class MQ2IrcType : public MQ2Type
{
public:
    enum IrcMembers
    {
        Server=1,
        Port=2,
        Channel=3,
        Nick=4,
    };

    MQ2IrcType():MQ2Type("irc")
    {
        TypeMember(Server);
        TypeMember(Port);
        TypeMember(Channel);
        TypeMember(Nick);
    }
    ~MQ2IrcType()
    {
    }

	bool MQ2IrcType::GETMEMBER()
	{
        PMQ2TYPEMEMBER pMember=MQ2IrcType::FindMember(Member);
        if (!pMember)
            return false;
        switch((IrcMembers)pMember->ID)
        {
        case Server:
            strcpy_s(DataTypeTemp, IrcServer);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        case Port:
            Dest.Int=atoi(IrcPort);
            Dest.Type=pIntType;
            return true;
        case Channel:
            strcpy_s(DataTypeTemp, IrcChan);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        case Nick:
            strcpy_s(DataTypeTemp, IrcNick);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    }

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination)
    {
        if (bConnected) 
            strcpy_s(Destination,MAX_STRING,"TRUE"); 
        else 
            strcpy_s(Destination,MAX_STRING,"FALSE"); 
        return true; 
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source)
    {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source)
    {
        return false;
    }
};

BOOL dataIrc(PCHAR szName, MQ2TYPEVAR &Dest)
{
    Dest.DWord=1;
    Dest.Type=pIrcType;
    return true;
}
template <unsigned int _Size>LPSTR Safe_itoa_s(int _Value,char(&_Buffer)[_Size], int _Radix)
{
	errno_t err = _itoa_s(_Value, _Buffer, _Radix);
	if (!err) {
		return _Buffer;
	}
	return "";
}
// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    CHAR szTemp[MAX_STRING] = {0};
    strcpy_s(strDefault, "[%H:%M:%S] ");
    maxLength = 20;

    DebugSpewAlways("Initializing MQ2Irc");
    AddCommand("/i",IrcCmd);
    AddCommand("/iconnect",IrcConnectCmd);
    AddCommand("/istatus",IrcStatusCmd);
    AddCommand("/itimestamp",TimeStampCmd);
    AddMQ2Data("Irc",dataIrc);

    pIrcType = new MQ2IrcType;

    ircout("Loading MQ2Irc...");
    ircout("\ar#\ax MQ2Irc loaded, all commands are run with /i <command>");
    ircout("\ar#\ax /i help for a list of commands");
    ircout("\ar#\ax To connect to a server, type /iconnect <server> <port> <channel> <nick>");
    GetPrivateProfileString("Last Connect","Server","irc.ipdn.org",IrcServer,MAX_STRING,INIFileName);
    GetPrivateProfileString("Last Connect","Port","6667",IrcPort,MAX_STRING,INIFileName);
    GetPrivateProfileString("Last Connect","Chan","#macroquest",IrcChan,MAX_STRING,INIFileName);
    GetPrivateProfileString("Last Connect","Nick","What-Ini",IrcNick,MAX_STRING,INIFileName);
    GetPrivateProfileString("Settings","Version","MQ2Irc 120703",Version,MAX_STRING,INIFileName);
    GetPrivateProfileString("Settings","Username","What-Ini",Username,MAX_STRING,INIFileName);
    GetPrivateProfileString("Settings","Realname","mq2irc",Realname,MAX_STRING,INIFileName);
    GetPrivateProfileString("Settings","UseWnd","No",UseWnd,MAX_STRING,INIFileName);
    GetPrivateProfileString("Settings","USeTimeStamp","No",UseTimeStamp,MAX_STRING,INIFileName);

    irctop = GetPrivateProfileInt("Settings", "ChatTop", 0, INIFileName);
    ircbottom = GetPrivateProfileInt("Settings", "ChatBottom", 210, INIFileName);
    ircleft = GetPrivateProfileInt("Settings", "ChatLeft", 0, INIFileName);
    ircright = GetPrivateProfileInt("Settings", "ChatRight", 410, INIFileName);

    WritePrivateProfileString("Settings","Version",Version,INIFileName);
    WritePrivateProfileString("Settings","Username",Username,INIFileName);
    WritePrivateProfileString("Settings","Realname",Realname,INIFileName);
    WritePrivateProfileString("Settings","UseWnd",UseWnd,INIFileName);
    WritePrivateProfileString("Settings","UseTimeStamp",UseTimeStamp,INIFileName);

    WritePrivateProfileString("Settings", "ChatTop", Safe_itoa_s(irctop, szTemp, 10), INIFileName); 
    WritePrivateProfileString("Settings", "ChatBottom", Safe_itoa_s(ircbottom, szTemp, 10), INIFileName); 
    WritePrivateProfileString("Settings", "ChatLeft", Safe_itoa_s(ircleft, szTemp, 10), INIFileName); 
    WritePrivateProfileString("Settings", "ChatRight", Safe_itoa_s(ircright, szTemp, 10), INIFileName); 
    if (_stricmp(UseTimeStamp, "yes") == 0) {
        bStamp = true;
    } else {
        bStamp = false;
    }

    InitializeCriticalSection(&ConnectCS);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2Irc");
    RemoveCommand("/i");
    RemoveCommand("/iconnect");
    RemoveCommand("/istatus");
    RemoveCommand("/itimestamp");
    RemoveMQ2Data("Irc");

    // make sure we're not trying to connect...
    EnterCriticalSection(&ConnectCS);
    LeaveCriticalSection(&ConnectCS);
    DeleteCriticalSection(&ConnectCS);

    delete pIrcType;
}

PLUGIN_API VOID OnPulse(VOID)
{
    char *message;
    int i,err;
    if (bTriedConnect)
    {
        bTriedConnect=false;
        if (bConnected)
        {
            ircout("\ar#\ax Connected!");
        }
        else
        {
            ircout("\ar#\ax Could not connect.");
        }
    }

    // Fill the input buffer with new data, if any.

    for (i=0;i<512;i++) {
        err = recv(theSocket, &ireadbuf[i], 1, 0);
        if ((ireadbuf[i] == '\n') || (err == 0) || (err == SOCKET_ERROR)) {
            if (ireadbuf[i] == '\n') {
                ireadbuf[i] = '\0';
                if((message = parse(ireadbuf)) != NULL) {
                    ircout(message);
                }

            }
            break;
        }
    }
}
PLUGIN_API VOID OnCleanUI(VOID)
{
    CHAR szTemp[MAX_STRING] = {0};

    DebugSpewAlways("MQ2Irc::OnCleanUI()");
    if (MyWnd)
    {
        irctop = MyWnd->Location.top;
        ircbottom = MyWnd->Location.bottom;
        ircleft = MyWnd->Location.left;
        ircright = MyWnd->Location.right;

        WritePrivateProfileString("Settings", "ChatTop", Safe_itoa_s(irctop, szTemp, 10), INIFileName); 
        WritePrivateProfileString("Settings", "ChatBottom", Safe_itoa_s(ircbottom, szTemp, 10), INIFileName); 
        WritePrivateProfileString("Settings", "ChatLeft", Safe_itoa_s(ircleft, szTemp, 10), INIFileName); 
        WritePrivateProfileString("Settings", "ChatRight", Safe_itoa_s(ircright, szTemp, 10), INIFileName); 

        delete MyWnd;
        MyWnd=0;
    }
}
PLUGIN_API VOID SetGameState(DWORD GameState)
{
    //   DebugSpewAlways("MQ2Irc::SetGameState()");
    if (GameState==GAMESTATE_INGAME && !MyWnd)
    {
        //if (pSidlMgr->FindScreenPieceTemplate("ChatWindow"))
        if(!strcmp(UseWnd,"Yes")) {
            class CXStr ChatWnd("ChatWindow");
            MyWnd= new CIRCWnd(&ChatWnd);
            MyWnd->Location.top = irctop;
            MyWnd->Location.bottom = ircbottom;
            MyWnd->Location.left = ircleft;
            MyWnd->Location.right = ircright;
            DebugTry(((CXWnd*)MyWnd)->Show(1,1));
            DebugTry(BitOff(MyWnd->OutStruct->WindowStyle,CWS_CLOSE));
        }
    }
}

PLUGIN_API VOID OnReloadUI()
{
    //   DebugSpewAlways("MQ2Irc::OnReloadUI()");
    if (!MyWnd && !strcmp(UseWnd,"Yes"))
    {
        //if (pSidlMgr->FindScreenPieceTemplate("TestWindow"))
        class CXStr ChatWnd("ChatWindow");
        MyWnd= new CIRCWnd(&ChatWnd);
        MyWnd->Location.top = irctop;
        MyWnd->Location.bottom = ircbottom;
        MyWnd->Location.left = ircleft;
        MyWnd->Location.right = ircright;
        DebugTry(((CXWnd*)MyWnd)->Show(1,1));
        DebugTry(BitOff(MyWnd->OutStruct->WindowStyle,CWS_CLOSE));
    }
}
