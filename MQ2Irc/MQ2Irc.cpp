// MQ2Irc.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks. All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use. Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#pragma comment(lib,"wsock32.lib")
#include "../MQ2Plugin.h"
#include "../MQ2Main/MQ2Globals.h"

PreSetup("MQ2Irc");

CHAR szIrcServer[MAX_STRING] = {0};
CHAR szIrcNick[MAX_STRING] = {0};
CHAR szIrcPort[MAX_STRING] = {0};
CHAR szIrcChan[MAX_STRING] = {0};
CHAR IrcServer[MAX_STRING] = {0};
CHAR IrcNick[MAX_STRING] = {0};
CHAR IrcPort[MAX_STRING] = {0};
CHAR IrcChan[MAX_STRING] = {0};
WORD sockVersion;
WSADATA wsaData;
int nret;
LPHOSTENT hostEntry;
SOCKET theSocket;
CHAR *ireadbuf = new CHAR[512];
CHAR buffz[512];
CHAR buff[512];
char version[] = "MQ2Irc 11262003";

unsigned long IRCChatColor=111111;


CRITICAL_SECTION ConnectCS;
bool bConnecting=false;
bool bTriedConnect=false;
bool bConnected=false;
SOCKADDR_IN serverInfo;
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

		sprintf(buffz,"NICK %s\n\0",szIrcNick);
		send(theSocket,buffz,strlen(buffz),0);
		sprintf(buffz,"USER %s %s %s %s\n\0",szIrcNick,szIrcNick,szIrcNick,szIrcNick);
		send(theSocket,buffz,strlen(buffz),0);
		sprintf(buffz,"JOIN %s\n\0",IrcChan);
		send(theSocket,buffz,strlen(buffz),0);
		bConnected=true;
	}
	bTriedConnect=true;

	bConnecting=false;
	LeaveCriticalSection(&ConnectCS);
	return 0;
}


VOID IrcConnect(PSPAWNINFO pChar, PCHAR szLine)
{ // /iconnect server port chan nick OR /iconnect inikey
	if (bConnecting)
	{
		WriteChatColor("\ar#\ax Already trying to connect! Hold on a minute there",IRCChatColor);
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
		GetPrivateProfileString("Last Connect","Server","irc.forever-hacking.net",szIrcServer,MAX_STRING,INIFileName);
		GetPrivateProfileString("Last Connect","Port","6667",szIrcPort,MAX_STRING,INIFileName);
		GetPrivateProfileString("Last Connect","Chan","MyChan",szIrcChan,MAX_STRING,INIFileName);
		GetPrivateProfileString("Last Connect","Nick","What-Ini",szIrcNick,MAX_STRING,INIFileName);
		sprintf(IrcServer,"%s",szIrcServer);
		sprintf(IrcPort,"%s",szIrcPort);
		sprintf(IrcChan,"%s",szIrcChan);
		sprintf(IrcNick,"%s",szIrcNick);
	} else if (Arg2[0]==0 && Arg3[0]==0 && Arg4[0]==0) {
		GetPrivateProfileString(Arg1,"Server","irc.forever-hacking.net",szIrcServer,MAX_STRING,INIFileName);
		GetPrivateProfileString(Arg1,"Port","6667",szIrcPort,MAX_STRING,INIFileName);
		GetPrivateProfileString(Arg1,"Chan","MyChan",szIrcChan,MAX_STRING,INIFileName);
		GetPrivateProfileString(Arg1,"Nick","What-Ini",szIrcNick,MAX_STRING,INIFileName);
		sprintf(IrcServer,"%s",szIrcServer);
		sprintf(IrcPort,"%s",szIrcPort);
		sprintf(IrcChan,"%s",szIrcChan);
		sprintf(IrcNick,"%s",szIrcNick);
	} else if (Arg3[0]==0 && Arg4[0]==0) {
		sprintf(IrcServer,"%s",Arg1);
		sprintf(IrcPort,"%s",Arg2);
		sprintf(IrcChan,"%s",szIrcChan);
		sprintf(IrcNick,"%s",szIrcNick);
	} else if (Arg4[0]==0) {
		sprintf(IrcServer,"%s",Arg1);
		sprintf(IrcPort,"%s",Arg2);
		sprintf(IrcChan,"%s",Arg3);
		sprintf(IrcNick,"%s",szIrcNick);
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
	sockVersion = MAKEWORD(1, 1);
	WSAStartup(sockVersion, &wsaData);
	hostEntry = gethostbyname(IrcServer);
	if (!hostEntry) {
		WriteChatColor("\ar#\ax gethostbyname error",IRCChatColor);
		WSACleanup();
		return;
	}
	theSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (theSocket == INVALID_SOCKET) {
		WriteChatColor("\ar#\ax Socket error",IRCChatColor);
		WSACleanup();
		return;
	}
//	SOCKADDR_IN serverInfo;
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_addr = *((LPIN_ADDR)*hostEntry->h_addr_list);
	serverInfo.sin_port = htons(atoi(IrcPort));
	DWORD ThreadId; 
	CreateThread(NULL,0,&IRCConnectThread,0,0,&ThreadId); 
/*
	nret = connect(theSocket,(LPSOCKADDR)&serverInfo,sizeof(struct sockaddr));
	if (nret == SOCKET_ERROR) {
		WriteChatColor("\ar#\ax Couldnt Connect!",IRCChatColor);
		WSACleanup();
		return;
	}
	unsigned long nonblocking = 1;
	ioctlsocket(theSocket,FIONBIO,&nonblocking);
	Sleep((clock_t)2 * CLOCKS_PER_SEC/2);

	sprintf(buffz,"NICK %s\n\0",IrcNick);
	send(theSocket,buffz,strlen(buffz),0);
	sprintf(buffz,"USER %s %s %s %s\n\0",IrcNick,IrcNick,IrcNick,IrcNick);
	send(theSocket,buffz,strlen(buffz),0);
	WriteChatColor("\ar#\ax Connected!",IRCChatColor);
	sprintf(buffz,"JOIN %s\n\0",IrcChan);
	send(theSocket,buffz,strlen(buffz),0);
/**/
	return;
}


VOID IrcCmd(PSPAWNINFO pChar, PCHAR szLine)
{
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
		sprintf(buffz,"NICK %s\n\0",z[1]);
		send(theSocket,buffz,strlen(buffz),0);
		WritePrivateProfileString("Last Connect","Nick",IrcNick,INIFileName);
		WritePrivateProfileString(IrcServer,"Nick",IrcNick,INIFileName);
		return;
	} else if(!strcmp(strupr(z[0]),"JOIN")) {
		sprintf(buff,"PART %s\n\0",IrcChan);
		send(theSocket,buff,strlen(buff),0);
		sprintf(buffz,"JOIN %s\n\0",z[1]);
		send(theSocket,buffz,strlen(buffz),0);
		WritePrivateProfileString("Last Connect","Chan",IrcChan,INIFileName);
		WritePrivateProfileString(IrcServer,"Chan",IrcChan,INIFileName);
		return;
	} else if(!strcmp(strupr(z[0]),"PART")) {
		sprintf(buffz,"PART %s\n\0",IrcChan);
		send(theSocket,buffz,strlen(buffz),0);
		return;
	} else if(!strcmp(strupr(z[0]),"WHOIS")) {
		sprintf(buffz,"WHOIS %s\n\0",z[1]);
		send(theSocket,buffz,strlen(buffz),0);
		return;
	} else if(!strcmp(strupr(z[0]),"HELP")) {
		sprintf(buffz,"\ar#\ax Supported Commands:\n\ar#\ax NICK JOIN PART WHOIS MSG SAY RAW QUIT NAMES HELP");
		WriteChatColor(buffz,IRCChatColor);
		return;
	} else if(!strcmp(strupr(z[0]),"QUIT")) {
		sprintf(buffz,"QUIT :%s\n\0",z[1]);
		send(theSocket,buffz,strlen(buffz),0);
		WriteChatColor("\ar#\ax Connection Closed, you can unload MQ2Irc now.",IRCChatColor);
		return;
	} else if(!strcmp(strupr(z[0]),"RAW")) {
		sprintf(buffz,"%s\n\0",z[1]);
		sprintf(buff,"\ab[\a-yraw\ab(\ay%s\ab)]\a-w %s\0", IrcServer, z[1]);
		WriteChatColor(buff,IRCChatColor);
		send(theSocket,buffz,strlen(buffz),0);
		return;
	} else if(!strcmp(strupr(z[0]),"SAY")) {
		sprintf(buffz,"PRIVMSG %s :%s\n\0",IrcChan,z[1]);
		send(theSocket,buffz,strlen(buffz),0);
		sprintf(buffz,"\ag<\aw%s\ag>\a-w %s\0",IrcNick,z[1]);
		WriteChatColor(buffz,IRCChatColor);
		return;
	} else if(!strcmp(strupr(z[0]),"NAMES")) {
		sprintf(buffz,"NAMES %s\n\0",IrcChan);
		send(theSocket,buffz,strlen(buffz),0);
		return;
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
		sprintf(buffz,"PRIVMSG %s :%s\n\0", z[1],z[2]);
		send(theSocket,buffz,strlen(buffz),0);
		sprintf(buffz,"\ab[\a-rmsg\ab(\ar%s\ab)]\a-w %s\0", z[1], z[2]);
		WriteChatColor(buffz,IRCChatColor);
		return;
	} else {
		WriteChatColor("\ar#\a-w Invalid Command, /i help for a list of commands",IRCChatColor);
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
	CHAR *prefix, *tmp, *tmpb, *param[32], *command, *lnk;
	prefix = IrcNick; // temporary fix for CTD on connect
	sprintf(buffz,"%s",rawmsg); //save a copy of the original

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
		}
		sprintf(buff,"\ar*\a-w %s changed nickname to \aw%s\a-w.\0", prefix, param[0]);
		return buff;
	} else if(!strcmp(command,"JOIN")) {
		if(!strcmp(IrcNick,prefix)) {
			sprintf(IrcChan,"%s\0",param[0]);
			IrcChan[strlen(IrcChan)-1] = '\0';
		}
		sprintf(buff,"\ar*\aw %s\a-w joined %s.\0", prefix, param[0]);
		return buff;
	} else if(!strcmp(command,"PART")) {
		sprintf(buff,"\ar*\aw %s\a-w left %s\0", prefix, param[0]);
		return buff;
	} else if(!strcmp(command,"MODE")) {
		if(x<3)
			sprintf(buff,"\ar*\aw %s\a-w set mode \"\aw%s\a-w\" %s\0", prefix, param[1], param[0]);
		else
			sprintf(buff,"\ar*\aw %s\a-w set mode \"\aw%s\a-w\" \aw%s\a-w on %s\0", prefix, param[1], param[2], param[0]);
		return buff;
	} else if(!strcmp(command,"PRIVMSG")) {
		param[1][strlen(param[1])-1] = '\0';
		if(!strcmp(param[1],"\001VERSION\001")) {
			sprintf(buff,"NOTICE %s :\001VERSION %s\001\n\0",prefix,version);
			send(theSocket,buff,strlen(buff),0);
			sprintf(buff,"\ab[\ao%s\ab(\a-octcp\ab)]\a-w VERSION", prefix);
			return buff;
		}
		if(!strcmp(IrcNick, param[0])) {
			sprintf(buff,"\ab[\ap%s\ab(\a-pmsg\ab)]\a-w %s\0", prefix, param[1]);

			sprintf(Arg1,"%s tells the group, '%s'", prefix, param[1]);
			CheckChatForEvent(Arg1);
			return buff;
		} else {
			sprintf(buff,"\ag<\a-w%s\ag>\a-w %s\0", prefix, param[1]);
			sprintf(Arg1,"%s tells the group, '%s'", prefix, param[1]);
			CheckChatForEvent(Arg1);
			return buff;
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
	return buffz;
		}
	} else { //wasnt a normal command, and wasnt numeric.. something didnt work right
		WriteChatColor("DEBUG Couldnt parse correctly...",IRCChatColor);
		sprintf(buff,"DEBUG: command = %s\0", command);
		WriteChatColor(buff,IRCChatColor);
		for(y = 0; y<x;) {
			sprintf(buff,"DEBUG param[%i] = %s\0", y, param[y]);
			WriteChatColor(buff,IRCChatColor);
			y++;
		}
		return buffz;
	}
}


// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2Irc");
	AddCommand("/i",IrcCmd);
	AddCommand("/iconnect",IrcConnect);
	WriteChatColor("Loading MQ2Irc...",IRCChatColor);

	WriteChatColor("\ar#\ax MQ2Irc loaded, all commands are run with /i <command>",IRCChatColor);
	WriteChatColor("\ar#\ax /i help for a list of commands",IRCChatColor);
	WriteChatColor("\ar#\ax To connect to a server, type /iconnect <server> <port> <channel> <nick>",IRCChatColor);
	GetPrivateProfileString("Last Connect","Server","irc.forever-hacking.net",szIrcServer,MAX_STRING,INIFileName);
	GetPrivateProfileString("Last Connect","Port","6667",szIrcPort,MAX_STRING,INIFileName);
	GetPrivateProfileString("Last Connect","Chan","MyChan",szIrcChan,MAX_STRING,INIFileName);
	GetPrivateProfileString("Last Connect","Nick","What-Ini",szIrcNick,MAX_STRING,INIFileName);
	InitializeCriticalSection(&ConnectCS);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2Irc");
	RemoveCommand("/i");
	RemoveCommand("/iconnect");

	// make sure we're not trying to connect...
	EnterCriticalSection(&ConnectCS);
	LeaveCriticalSection(&ConnectCS);
	DeleteCriticalSection(&ConnectCS);
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
			WriteChatColor("\ar#\ax Connected!",IRCChatColor);
		}
		else
		{
			WriteChatColor("\ar#\ax Could not connect.",IRCChatColor);
		}
	}

	// Fill the input buffer with new data, if any.

	for (i=0;i<512;i++) {
		err = recv(theSocket, &ireadbuf[i], 1, 0);
		if ((ireadbuf[i] == '\n') || (err == 0) || (err == SOCKET_ERROR)) {
			if (ireadbuf[i] == '\n') {
				ireadbuf[i] = '\0';
				if((message = parse(ireadbuf)) != NULL) {
					WriteChatColor(message,IRCChatColor);
				}

			}
			break;
		}
	}
}