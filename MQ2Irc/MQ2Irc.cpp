// MQ2Irc.cpp : Defines the entry point for the DLL application. 
// 

// PLUGIN_API is only to be used for callbacks. All existing callbacks at this time 
// are shown below. Remove the ones your plugin does not use. Always use Initialize 
// and Shutdown for setup and cleanup, do NOT do it in DllMain. 

// Updated 9/24/04 - Sanity Checks, Window INI Position Saves, fixes, and /istatus 


#pragma comment(lib,"wsock32.lib") 
#include "../MQ2Plugin.h" 
#include <list> 

PreSetup("MQ2Irc"); 

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
        StmlOut = (CStmlWnd *)GetChildItem("CWChatOutput"); 
        OutWnd = (CXWnd*)StmlOut; 
        //      OutWnd = GetChildItem("CWChatOutput"); 
        // ^ Retarded monkeys should not code ^ 
        OutStruct = (_CSIDLWND *)GetChildItem("CWChatOutput"); 

        InputBox=(CTextEntryWnd*)GetChildItem("CWChatInput"); 
        InputBox->WindowStyle|=0x800C0; 
        InputBox->UnknownCW|=0xFFFFFFFF; 
        InputBox->SetMaxChars(512); 
        BitOff(WindowStyle,CWS_CLOSE); 
    } 

    int WndNotification(CXWnd *pWnd, unsigned int Message, void *data) 
    { 
        if (pWnd==(CXWnd*)InputBox) 
        { 
            if (Message==XWM_HITENTER) 
            { 
                char szBuffer[2048]; 
                GetCXStr((PCXSTR)InputBox->InputText,szBuffer,2047); 
                if (szBuffer[0]) 
                { 
                    if(channels.size()<1) { 
                        ircout("\ar#\a-w You are not on any channels."); 
                    } else { 
                        sprintf(buff,"PRIVMSG %s :%s\n\0",*mychan,szBuffer); 
                        send(theSocket,buff,strlen(buff),0); 
                        sprintf(buff,"\ag<\aw%s\ag>\a-w %s\0",IrcNick,szBuffer); 
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
    if(MyWnd && !strcmp(UseWnd,"Yes")) { 
        DebugTry(((CXWnd*)MyWnd)->Show(1,1)); 
        char processed[MAX_STRING]; 
        StripMQChat(text,processed); 
        CheckChatForEvent(processed); 
        MQToSTML(text,processed,MAX_STRING); 
        strcat(processed,"<br>"); 
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

        sprintf(buff,"NICK %s\n\0",IrcNick); 
        send(theSocket,buff,strlen(buff),0); 
        sprintf(buff,"USER %s %s %s :%s\n\0",Username,IrcNick,IrcNick,Realname); 
        send(theSocket,buff,strlen(buff),0); 
        sprintf(buff,"JOIN %s\n\0",IrcChan); 
        send(theSocket,buff,strlen(buff),0); 
        bConnected=true; 
    } 
    bTriedConnect=true; 

    bConnecting=false; 
    LeaveCriticalSection(&ConnectCS); 
    return 0; 
} 


VOID IrcStatusCmd(PSPAWNINFO pChar, PCHAR szLine) 
{ 
    if (bConnected) { 
        // Connected 
        sprintf(buff,"\ar#\ax MQ2Irc Status: ONLINE - %s - %s - %s - %s",IrcServer,IrcPort,IrcChan,IrcNick); 
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
        sprintf(IrcServer,"%s",Arg1); 
        sprintf(IrcPort,"%s",Arg2); 

    } else if (Arg4[0]==0) { 
        sprintf(IrcServer,"%s",Arg1); 
        sprintf(IrcPort,"%s",Arg2); 
        sprintf(IrcChan,"%s",Arg3); 
    } else { 
        sprintf(IrcServer,"%s",Arg1); 
        sprintf(IrcPort,"%s",Arg2); 
        sprintf(IrcChan,"%s",Arg3); 
        sprintf(IrcNick,"%s",Arg4); 
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
        sprintf(buff,"%s [%s]",IrcChan,IrcServer); 
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
    if(!strcmp(strupr(z[0]),"NICK")) { 
        sprintf(buff,"NICK %s\n\0",z[1]); 
        send(theSocket,buff,strlen(buff),0); 
        WritePrivateProfileString("Last Connect","Nick",IrcNick,INIFileName); 
        WritePrivateProfileString(IrcServer,"Nick",IrcNick,INIFileName); 
        return; 
    } else if(!strcmp(strupr(z[0]),"JOIN")) { 
        sprintf(buff,"JOIN %s\n\0",z[1]); 
        send(theSocket,buff,strlen(buff),0); 
        WritePrivateProfileString("Last Connect","Chan",IrcChan,INIFileName); 
        WritePrivateProfileString(IrcServer,"Chan",IrcChan,INIFileName); 
        return; 
    } else if(!strcmp(strupr(z[0]),"PART")) { 
        sprintf(buff,"PART %s\n\0",*mychan); 
        send(theSocket,buff,strlen(buff),0); 
        return; 
    } else if(!strcmp(strupr(z[0]),"WHOIS")) { 
        sprintf(buff,"WHOIS %s\n\0",z[1]); 
        send(theSocket,buff,strlen(buff),0); 
        return; 
    } else if(!strcmp(strupr(z[0]),"HELP")) { 
        sprintf(buff,"\ar#\ax Supported Commands:\n\ar#\ax NICK JOIN PART WHOIS MSG SAY RAW QUIT NAMES X HELP"); 
        ircout(buff); 
        return; 
    } else if(!strcmp(strupr(z[0]),"QUIT")) { 
        sprintf(buff,"QUIT :%s\n\0",z[1]); 
        send(theSocket,buff,strlen(buff),0); 
        bConnected=false; 
        ircout("\ar#\ax Connection Closed, you can unload MQ2Irc now."); 
        return; 
    } else if(!strcmp(strupr(z[0]),"RAW")) { 
        sprintf(buff,"%s\n\0",z[1]); 
        send(theSocket,buff,strlen(buff),0); 
        sprintf(buff,"\ab[\a-yraw\ab(\ay%s\ab)]\a-w %s\0", IrcServer, z[1]); 
        ircout(buff); 
        return; 
    } else if(!strcmp(strupr(z[0]),"SAY")) { 
        if(channels.size()<1) { 
            ircout("\ar#\a-w You are not on any channels."); 
            return; 
        } else { 
            sprintf(buff,"PRIVMSG %s :%s\n\0",*mychan,z[1]); 
            send(theSocket,buff,strlen(buff),0); 
            sprintf(buff,"\ag<\aw%s\ag>\a-w %s\0",IrcNick,z[1]); 
            ircout(buff); 
            return; 
        } 
    } else if(!strcmp(strupr(z[0]),"NAMES")) { 
        sprintf(buff,"NAMES %s\n\0",IrcChan); 
        send(theSocket,buff,strlen(buff),0); 
        return; 
    } else if(!strcmp(strupr(z[0]),"X")) { 
        mychan++; 
        if(mychan == channels.end()) 
            mychan = channels.begin(); 
        if(MyWnd) { 
            sprintf(buff,"%s [%s]",*mychan,IrcServer); 
            SetCXStr(&MyWnd->OutStruct->WindowText,buff); 
        } 
        sprintf(buff, "\ar#\a-w Now speaking in \aw%s\a-w.", *mychan); 
        ircout(buff); 
    } else if(!strcmp(strupr(z[0]),"MSG")) { 
        for (y = 2; *szLine != '\0'; ) { 
            if (*szLine == ' ') { 
                *szLine = '\0'; 
                z[y++] = ++szLine; 
                break; 
            } else { 
                szLine++; 
            } 
        } 
        sprintf(buff,"PRIVMSG %s :%s\n\0", z[1],z[2]); 
        send(theSocket,buff,strlen(buff),0); 
        sprintf(buff,"\ab[\a-rmsg\ab(\ar%s\ab)]\a-w %s\0", z[1], z[2]); 
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
    sprintf(buff,"%s",rawmsg); //save a copy of the original 

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
        sprintf(buff,"PONG %s\n\0", param[0]); 
        send(theSocket,buff,strlen(buff),0); 
        return NULL; 
    } else if(!strcmp(command,"NICK")) { 
        if(!strcmp(IrcNick,prefix)) { 
            sprintf(IrcNick,"%s\0",param[0]); 
            IrcNick[strlen(IrcNick)-1] = '\0'; 
            WritePrivateProfileString("Last Connect","Nick",IrcNick,INIFileName); 
            WritePrivateProfileString(IrcServer,"Nick",IrcNick,INIFileName); 
        } 
        sprintf(buff,"\ar*\a-w %s changed nickname to \aw%s\a-w.\0", prefix, param[0]); 
        return buff; 
    } else if(!strcmp(command,"JOIN")) { 
        if(!strcmp(IrcNick,prefix)) { 
            sprintf(IrcChan,"%s\0",param[0]); 
            IrcChan[strlen(IrcChan)-1] = '\0'; 
            pchan = malloc(sizeof(IrcChan)); 
            sprintf((char *)pchan, "%s", IrcChan); 
            channels.push_front((char *)pchan); 
            mychan = channels.begin(); 
            if(MyWnd) { 
                sprintf(buff,"%s [%s]",*mychan,IrcServer); 
                SetCXStr(&MyWnd->OutStruct->WindowText,buff); 
            } 
            WritePrivateProfileString("Last Connect","Chan",*mychan,INIFileName); 
            WritePrivateProfileString(IrcServer,"Chan",*mychan,INIFileName); 
            sprintf(buff,"\ar#\a-w Now speaking in \aw%s\a-w.", *mychan); 
            ircout(buff); 
        } 
        sprintf(buff,"\ar*\aw %s\a-w joined %s.\0", prefix, param[0]); 
        return buff; 
    } else if(!strcmp(command,"PART")) { 
        param[0][strlen(param[0])-1] = '\0'; 
        if(!strcmp(IrcNick,prefix)) { 
            channels.erase(mychan); 
            if(channels.size()<1) { 
                if(MyWnd) { 
                    sprintf(buff,"No Channel [%s]",IrcServer); 
                    SetCXStr(&MyWnd->OutStruct->WindowText,buff); 
                } 
                sprintf(buff,"\ar#\a-w No longer on any channels."); 
                return buff; 
            } else { 
                mychan = channels.begin(); 
                if(MyWnd) { 
                    sprintf(buff,"%s [%s]",*mychan,IrcServer); 
                    SetCXStr(&MyWnd->OutStruct->WindowText,buff); 
                } 
                WritePrivateProfileString("Last Connect","Chan",*mychan,INIFileName); 
                WritePrivateProfileString(IrcServer,"Chan",*mychan,INIFileName); 
                sprintf(buff,"\ar#\a-w Now speaking in \aw%s\a-w.", *mychan); 
                return buff; 
            } 
        } 
        sprintf(buff,"\ar*\aw %s\a-w left %s\0", prefix, param[0]); 
        return buff; 
    } else if(!strcmp(command,"MODE")) { 
        sprintf(buff,"\ar*\aw %s set mode \"\aw", prefix); 
        for(y=1;y<x;) { 
            strcat(buff,param[y++]); 
            strcat(buff," "); 
        } 
        strcat(buff,"\" "); 
        strcat(buff,param[0]); 
        return buff; 
    } else if(!strcmp(command,"PRIVMSG")) { 
        param[1][strlen(param[1])-1] = '\0'; 
        if(!strcmp(param[1],"\001VERSION\001")) { 
            sprintf(buff,"NOTICE %s :\001VERSION %s\001\n\0",prefix,Version); 
            send(theSocket,buff,strlen(buff),0); 
            sprintf(buff,"\ab[\ao%s\ab(\a-octcp\ab)]\a-w VERSION", prefix); 
            return buff; 
        } 

        if(!strcmp(IrcNick, param[0])) { 
            sprintf(buff,"\ab[\ap%s\ab(\a-pmsg\ab)]\a-w %s\0", prefix, param[1]); 

            //         sprintf(Arg1,"%s tells you, '%s'", prefix, param[1]); 
            //         CheckChatForEvent(Arg1); 
            return buff; 
        } else { 
            if(!strcmp(*mychan, param[0])) { 
                sprintf(buff,"\ag<\a-w%s\ag>\a-w %s\0", prefix, param[1]); 
                //            sprintf(Arg1,"%s tells the group, '%s'", prefix, param[1]); 
                //            CheckChatForEvent(Arg1); 
                return buff; 
            } else { 
                sprintf(buff,"\ag<\a-w%s\ag/\a-w%s\ag>\a-w %s\0", prefix, param[0], param[1]); 
                return buff; 
            } 
        } 
    } else if(!strcmp(command,"NOTICE")) { 
        sprintf(buff,"\ab[\ao%s\ab(\a-onotice\ab)]\a-w %s\0", prefix, param[1]); 
        return buff; 
    } else if(!strcmp(command,"TOPIC")) { 
        sprintf(buff,"\ar*\aw %s\a-w changed topic on \aw%s\a-w to: %s\0", prefix, param[0], param[1]); 
        return buff; 
    } else if(!strcmp(command,"KICK")) { 
        sprintf(buff,"\ar*\aw %s\a-w kicked from %s by \aw%s\a-w (%s)", param[1], param[0], prefix, param[2]); 
        return buff; 
    } else if(!strcmp(command,"QUIT")) { 
        sprintf(buff,"\ar*\aw %s\a-w quit IRC (%s)\0", prefix, param[0]); 
        return buff; 
    } else if(!strcmp(command,"ERROR")) { 
        sprintf(buff,"\ar#\a-w Server error: %s\0", param[0]); 
        return buff; 
    } else if(atoi(command) > 0) { 
        switch(atoi(command)) { 
            //it wasnt one of the above commands, maybe its a numeric 
         case 001: 
             sprintf(buff,"%s\0", param[1]); 
             sprintf(IrcNick,"%s", param[0]); 
             return buff; 
         case 002: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 003: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 004: 
             return NULL; 
         case 005: 
             return NULL; 
         case 251: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 252: 
             sprintf(buff,"%s %s\0", param[1], param[2]); 
             return buff; 
         case 254: 
             sprintf(buff,"%s %s\0", param[1], param[2]); 
             return buff; 
         case 255: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 265: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 266: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 250: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 375: 
             return NULL; 
         case 372: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 376: 
             sprintf(buff,"%s\0", param[1]); 
             return buff; 
         case 401: 
             sprintf(buff,"\ar#\a-w %s: %s\0", param[1], param[2]); 
             return buff; 
         case 421: 
             sprintf(buff,"\ar#\a-w Server doesn't recognize command \aw%s\a-w\0", param[1]); 
             return buff; 
         case 422: 
             sprintf(buff,"\ar#\a-w Server has no MOTD\0"); 
             return buff; 
         case 311: 
             sprintf(buff,"\ar#\aw %s\a-w %s@%s (%s)\0", param[1], param[2], param[3], param[5]); 
             return buff; 
         case 312: 
             sprintf(buff,"\ar#\aw %s\a-w %s (%s)\0", param[1], param[2], param[3]); 
             return buff; 
         case 338: 
             sprintf(buff,"\ar#\aw %s\a-w connecting from %s\0", param[1], param[2]); 
             return buff; 
         case 317: 
             sprintf(buff,"\ar#\aw %s\a-w %s seconds idle\0", param[1], param[2]); 
             return buff; 
         case 318: 
             sprintf(buff,"\ar#\aw %s\a-w %s\0", param[1], param[2]); 
             return buff; 
         case 378: 
             sprintf(buff,"\ar#\a-w %s %s\0", param[1], param[2]); 
             return buff; 
         case 433: 
             sprintf(buff,"\ar#\a-w %s %s\0", param[1], param[2]); 
             return buff; 
         case 451: 
             sprintf(buff,"\ar#\a-w Not registered with server\0"); 
             return buff; 
         case 319: 
             sprintf(buff,"\ar#\aw %s\a-w %s\0", param[1], param[2]); 
             return buff; 
         case 442: 
             sprintf(buff,"\ar#\a-w %s %s\0", param[1], param[2]); 
             return buff; 
         case 332: 
             sprintf(buff,"\ar#\a-w Topic for \aw%s\a-w: %s\0", param[1], param[2]); 
             return buff; 
         case 333: 
             sprintf(buff,"\ar#\a-w Set by \aw%s\a-w\0", param[2]); 
             return buff; 
         case 353: 
             sprintf(buff,"\ar#\a-w Names on \aw%s\a-w\n\ar#\a-w %s\0", IrcChan, param[3]); 
             return buff; 
         case 366: 
             sprintf(buff,"\ar#\a-w End of /names list\0"); 
             return buff; 
         default: //if its not one of those, its a numeric we havnt set up, just 
             //dump the raw irc message to the screen 
             return buff; 
        } 
    } else { //wasnt a normal command, and wasnt numeric.. something didnt work right 
        ircout("DEBUG Couldnt parse correctly..."); 
        sprintf(buff,"DEBUG: command = %s\0", command); 
        for(y = 0; y<x;) { 
            sprintf(buff,"DEBUG param[%i] = %s\0", y, param[y]); 
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

    bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) 
    { 
        PMQ2TYPEMEMBER pMember=MQ2IrcType::FindMember(Member); 
        if (!pMember) 
            return false; 
        switch((IrcMembers)pMember->ID)
        {
        case Server: 
            strcpy(DataTypeTemp, IrcServer); 
            Dest.Ptr=DataTypeTemp; 
            Dest.Type=pStringType; 
            return true; 
        case Port: 
            Dest.Int=atoi(IrcPort); 
            Dest.Type=pIntType; 
            return true; 
        case Channel: 
            strcpy(DataTypeTemp, IrcChan); 
            Dest.Ptr=DataTypeTemp; 
            Dest.Type=pStringType; 
            return true; 
        case Nick: 
            strcpy(DataTypeTemp, IrcNick); 
            Dest.Ptr=DataTypeTemp; 
            Dest.Type=pStringType; 
            return true; 
        }
        return false; 
    } 

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination) 
    { 
        if (bConnected) 
            strcpy(Destination,"TRUE"); 
        else 
            strcpy(Destination,"FALSE"); 
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

// Called once, when the plugin is to initialize 
PLUGIN_API VOID InitializePlugin(VOID) 
{ 
    CHAR szTemp[MAX_STRING] = {0}; 

    DebugSpewAlways("Initializing MQ2Irc"); 
    AddCommand("/i",IrcCmd); 
    AddCommand("/iconnect",IrcConnectCmd); 
    AddCommand("/istatus",IrcStatusCmd); 
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

    irctop = GetPrivateProfileInt("Settings", "ChatTop", 0, INIFileName); 
    ircbottom = GetPrivateProfileInt("Settings", "ChatBottom", 210, INIFileName); 
    ircleft = GetPrivateProfileInt("Settings", "ChatLeft", 0, INIFileName); 
    ircright = GetPrivateProfileInt("Settings", "ChatRight", 410, INIFileName); 

    WritePrivateProfileString("Settings","Version",Version,INIFileName); 
    WritePrivateProfileString("Settings","Username",Username,INIFileName); 
    WritePrivateProfileString("Settings","Realname",Realname,INIFileName); 
    WritePrivateProfileString("Settings","UseWnd",UseWnd,INIFileName); 

    WritePrivateProfileString("Settings", "ChatTop", itoa(irctop, szTemp, 10), INIFileName); 
    WritePrivateProfileString("Settings", "ChatBottom", itoa(ircbottom, szTemp, 10), INIFileName); 
    WritePrivateProfileString("Settings", "ChatLeft", itoa(ircleft, szTemp, 10), INIFileName); 
    WritePrivateProfileString("Settings", "ChatRight", itoa(ircright, szTemp, 10), INIFileName); 

    InitializeCriticalSection(&ConnectCS); 
} 

// Called once, when the plugin is to shutdown 
PLUGIN_API VOID ShutdownPlugin(VOID) 
{ 
    DebugSpewAlways("Shutting down MQ2Irc"); 
    RemoveCommand("/i"); 
    RemoveCommand("/iconnect"); 
    RemoveCommand("/istatus"); 
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

        WritePrivateProfileString("Settings", "ChatTop", itoa(irctop, szTemp, 10), INIFileName); 
        WritePrivateProfileString("Settings", "ChatBottom", itoa(ircbottom, szTemp, 10), INIFileName); 
        WritePrivateProfileString("Settings", "ChatLeft", itoa(ircleft, szTemp, 10), INIFileName); 
        WritePrivateProfileString("Settings", "ChatRight", itoa(ircright, szTemp, 10), INIFileName); 

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
