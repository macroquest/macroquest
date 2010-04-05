#pragma once

class ISXEQLegacyEngine    :
    public ISXScriptEngine
{
public:
    ISXEQLegacyEngine(void);
    ~ISXEQLegacyEngine(void);

    virtual const char *GetName() 
    {
        return "LegacyMQ2";
    }
    virtual const char *GetVersion()    // used by extensions. implement however you want
    {
        return "1.00";
    }
    virtual bool GetCaps(ISXSCRIPTENGINECAPS &Dest); // used by extensions to retrieve engine capabilities

    virtual void Pulse(); // for persistent scripts, use this to process microthreads, etc.

    virtual bool ExecuteScript(const char *FullFilename, int argc, char *argv[]); // used by RunScript command
    virtual bool EndScript(const char *Name); // used by EndScript
};

