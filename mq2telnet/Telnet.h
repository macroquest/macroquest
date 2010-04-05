#pragma once

#include <string>

#define mstring std::string

// the options we want to keep track of for each side
struct TelnetOptions
{
    bool Echo;
    bool SuppressGoAhead;
};

// this is an artificial size used for our buffer...
#define TELNET_MAXCOMMANDSIZE 128 

#define TELNET_IAC 255
#define TELNET_WILL 251
#define TELNET_WONT 252
#define TELNET_DO   253
#define TELNET_DONT 254
#define TELNET_ECHO 1
#define TELNET_SUPPRESSGOAHEAD 3
#define TELNET_STATUS 5
#define TELNET_TIMING 6
#define TELNET_TTYPE 24
#define TELNET_WINDOWSIZE 31
#define TELNET_TERMINALSPEED 32
#define TELNET_REMOTEFLOWCONTROL 33
#define TELNET_LINEMODE 34
#define TELNET_VARIABLES 36

#define TELNET_SB 250
#define TELNET_SE 240
#define TELNET_NOP 241
#define TELNET_DM 242
#define TELNET_BRK 243
#define TELNET_IP 244
#define TELNET_AO 245
#define TELNET_AYT 246
#define TELNET_EC 247
#define TELNET_EL 248
#define TELNET_GA 249

/*
SE 240 End of subnegotiation parameters.  
NOP 241 No operation  
DM 242 Data mark. Indicates the position of a Synch event within the data stream. This should always be accompanied by a TCP urgent notification.  
BRK 243 Break. Indicates that the "break" or "attention" key was hit.  
IP 244 Suspend, interrupt or abort the process to which the NVT is connected.  
AO 245 Abort output. Allows the current process to run to completion but do not send its output to the user.  
AYT 246 Are you there. Send back to the NVT some visible evidence that the AYT was received.  
EC 247 Erase character. The receiver should delete the last preceding undeleted character from the data stream.  
EL 248 Erase line. Delete characters from the data stream back to but not including the previous CRLF.  
GA 249 Go ahead. Used, under certain circumstances, to tell the other end that it can transmit.  
/**/

class CTelnet
{
public:
    CTelnet()
    {
        TCPos=0;
        Remote.Echo=false;
        Remote.SuppressGoAhead=false;
        Local.Echo=false;
        Local.SuppressGoAhead=true;
    };
    ~CTelnet()
    {
    };
    virtual bool Connect   (char*, int) = 0;
    virtual bool Disconnect(void)       = 0;

    virtual bool Open (int)  = 0;
    virtual bool Close(void) = 0;

    virtual bool Write(char)       = 0;
    virtual int  Write(const void*, int) = 0;

    virtual bool Read(char*)      = 0;
    virtual int  Read(void*, int) = 0;

    virtual bool isOpen     (void) = 0;
    virtual bool isConnected(void) = 0;
    virtual long isData     (void) = 0;


    void SetEcho(bool bEcho = true)
    {
        unsigned char out[3];
        out[0]=TELNET_IAC;
        out[1]=TELNET_DONT-(2*bEcho);
        out[2]=TELNET_ECHO;
        Write(&out[0],3);
    };

    void SetSuppGoAhead(bool bSuppGoAhead = true)
    {
        unsigned char out[3];
        out[0]=TELNET_IAC;
        out[1]=TELNET_DONT-(2*bSuppGoAhead);
        out[2]=TELNET_SUPPRESSGOAHEAD;
        Write(&out[0],3);
    };

    static mstring Wont(unsigned char  Option)
    {
        unsigned char out[4];
        out[0]=TELNET_IAC;
        out[1]=TELNET_WONT;
        out[2]=Option;
        out[3]=0;
        return (char*)&out[0];
    };

    static mstring Will(unsigned char  Option)
    {
        unsigned char out[4];
        out[0]=TELNET_IAC;
        out[1]=TELNET_WILL;
        out[2]=Option;
        out[3]=0;
        return (char*)&out[0];
    };
    static mstring Do(unsigned char Option)
    {
        unsigned char out[4];
        out[0]=TELNET_IAC;
        out[1]=TELNET_DO;
        out[2]=Option;
        out[3]=0;
        return (char*)&out[0];
    };
    static mstring Dont(unsigned char Option)
    {
        unsigned char out[4];
        out[0]=TELNET_IAC;
        out[1]=TELNET_DONT;
        out[2]=Option;
        out[3]=0;
        return (char*)&out[0];
    };
    static mstring TelnetCommand(unsigned char Option)
    {
        unsigned char out[3];
        out[0]=TELNET_IAC;
        out[1]=Option;
        out[2]=0;
        return (char*)&out[0];
    };

    // interprets incoming telnet commands and sends appropriate response
    // used by StripTelnet()
    void InterpretTelnet(unsigned char *buffer, int size)
    {
        if (!buffer || size<=1 || buffer[0]!=TELNET_IAC)
            return;
        /*

        #define TELNET_IAC 255
        #define TELNET_WILL 251
        #define TELNET_WONT 252
        #define TELNET_DO   253
        #define TELNET_DONT 254
        #define TELNET_ECHO 1
        #define TELNET_SUPPRESSGOAHEAD 3
        #define TELNET_STATUS 5
        #define TELNET_TIMING 6
        #define TELNET_TTYPE 24
        #define TELNET_WINDOWSIZE 31
        #define TELNET_TERMINALSPEED 32
        #define TELNET_REMOTEFLOWCONTROL 33
        #define TELNET_LINEMODE 34
        #define TELNET_VARIABLES 36
        */
        switch(buffer[1]) // command
        {
        case TELNET_WILL:
            switch(buffer[2])
            {
            case TELNET_ECHO:
                Remote.Echo=true;
                break;
            case TELNET_SUPPRESSGOAHEAD:
                Remote.SuppressGoAhead=true;
                break;
            }
            break;
        case TELNET_WONT:
            switch(buffer[2])
            {
            case TELNET_ECHO:
                Remote.Echo=false;
                break;
            case TELNET_SUPPRESSGOAHEAD:
                Remote.SuppressGoAhead=false;
                break;
            }
            break;
        case TELNET_DO:
        case TELNET_DONT:
            switch(buffer[2])
            {
            case TELNET_ECHO:
                //Local.Echo=false;
                // respond with IAC WONT ECHO
                {
                    mstring rsp=Wont(TELNET_ECHO);
                    Write(&rsp[0],(int)strlen(&rsp[0]));
                }
                break;
            case TELNET_SUPPRESSGOAHEAD:
                //Local.SuppressGoAhead=true;
                // respond with IAC WILL SGA
                {
                    mstring rsp=Will(TELNET_SUPPRESSGOAHEAD);
                    Write(&rsp[0],(int)strlen(&rsp[0]));
                }
                break;
            }
            break;
        case TELNET_NOP:
            break;
        case TELNET_DM:
            break;
        case TELNET_BRK:
            break;
        case TELNET_IP:
            break;
        case TELNET_AO:
            break;
        case TELNET_AYT:
            {
                // lets send IAC NOP to show yes we're here
                unsigned char out[2];
                out[0]=TELNET_IAC;
                out[1]=TELNET_NOP;
                Write(&out[0],2);
            }
            break;
        case TELNET_EC:
            break;
        case TELNET_EL:
            break;
        case TELNET_GA:
            break;
        case TELNET_SB:
            break;
        }
    };

    // strips and interprets incoming telnet commands from read buffer
    // gives new size for buffer without telnet stuff, and modifies
    // buffer...  even with incompleted telnet commands from previous
    // read...
    // suggested use:
    // int Read(void* buffer, int maxsize)
    // {
    // // ...
    //   size = recv(..., buffer,maxsize)
    // // ... error checking/whatever
    //   return StripTelnet(buffer,size)
    // }
    // 
    int StripTelnet(unsigned char *buffer,int &size)
    {
        char *out=(char*)malloc(size);
        int opos=0;
        for (int i = 0 ; i < size ; i++)
        {
            if (TCPos)
            {
                // telnet command
                TelnetCarry[TCPos++]=buffer[i];
                if (TCPos==2 && (unsigned char)TelnetCarry[1]<250)
                {
                    // done getting the command, lets execute
                    InterpretTelnet((unsigned char*)&TelnetCarry[0],TCPos);
                    TCPos=0; // clear it
                    continue;
                }
                if (TCPos==3 && (unsigned char)TelnetCarry[1]!=TELNET_SB)
                {
                    InterpretTelnet((unsigned char*)&TelnetCarry[0],TCPos);
                    TCPos=0;
                    continue;
                }
                if ((unsigned char)TelnetCarry[1]==TELNET_SB && (unsigned char)buffer[i]==TELNET_SE)
                {
                    InterpretTelnet((unsigned char*)&TelnetCarry[0],TCPos);
                    TCPos=0;
                    continue;
                }
                //if (TCPos>=TELNET_MAXCOMMANDSIZE)
                //{
                //    // ... problem.
                //}
                continue;
            }
            // not inside telnet command, check for IAC
            if (buffer[i]==TELNET_IAC)
            {
                // new incoming telnet command
                TelnetCarry[TCPos++]=(char)TELNET_IAC;
                continue;
            }
            // not IAC, add to buffer
            out[opos++]=buffer[i];
        }
        memcpy(&buffer[0],&out[0],opos);
        free(out);
        return size=opos;
    };

    // options
    TelnetOptions Remote;
    TelnetOptions Local;

private:
    char TelnetCarry[TELNET_MAXCOMMANDSIZE];
    int TCPos;

};
