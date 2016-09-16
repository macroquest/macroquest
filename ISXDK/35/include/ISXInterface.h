#pragma once

typedef struct _ISXSCRIPTENGINECAPS
{
	unsigned int Sizeof;	// set by the caller before calling GetCaps, to sizeof(ISXSCRIPTENGINECAPS)
	// use Sizeof to fill in the caps structure only up to the correct size

	bool bPreprocessor;		// engine has a preprocessor (e.g. #define, #include, etc)
	bool bPersistent;		// can run persistent scripts
	bool bMultipleScripts;	// can run multiple scripts
} ISXSCRIPTENGINECAPS, *PISXSCRIPTENGINECAPS;

class ISXScriptEngine
{
public:
	virtual const char *GetName()=0; // unix name if possible, e.g. #!/usr/bin/perl would be "perl"
	virtual const char *GetVersion()=0;	// used by extensions. implement however you want
	virtual bool GetCaps(ISXSCRIPTENGINECAPS &Dest)=0; // used by extensions to retrieve engine capabilities
	
	virtual void Pulse()=0; // for persistent scripts, use this to process microthreads, etc.

	virtual bool ExecuteScript(const char *FullFilename, int argc, char *argv[])=0; // used by RunScript command
	virtual bool EndScript(const char *Name)=0; // used by EndScript

	virtual bool IsScript(const char *FullFilename) {return true;}
};

class ISXSoftwareCursorInterface
{
public:
	virtual bool CursorEnabled()=0;
	virtual bool GetPosition(int &X, int &Y)=0;

	virtual bool SetPosition(int X, int Y)=0;

	virtual bool DrawCursor() {return false;}
};

class ISXInterface
{
public:
	virtual unsigned int GetVersion();

	virtual bool Initialize(ISInterface *pISInterface)=0;
	virtual void Shutdown()=0;

	virtual bool RequestShutdown()
	{
		// return false if you must handle asynchronous shutdown behaviors first
		// doing so will require an additional unload request.
		return true;
	}

};
