#pragma once

class ISLavishScriptInterface
{
public:
	// paths
	virtual char *GetCWD(char *buffer, size_t buflen)=0;
	virtual char *SetRoot(const char *Filename, char *Dest)=0;

	virtual bool AddCommand(const char *Command, fLSCommand Function, bool Parse=true, bool Hidden=false)=0;
	virtual bool RemoveCommand(const char *Command)=0;
	virtual bool AddAlias(const char *Replace, const char *With)=0;
	virtual bool RemoveAlias(const char *Replace)=0;
	virtual char *GetArgs(int BeginInclusive, int EndExclusive, char *argv[], char *buf, size_t buflen)=0;
	virtual char *GetArgsQuoted(int BeginInclusive, int EndExclusive, char *argv[], char *buf, size_t buflen)=0;
	virtual char *GetArgsQuotedNF(int BeginInclusive, int EndExclusive, char *argv[], char *buf, size_t buflen)=0;
	virtual void ExecuteTimedCommand(unsigned int DelayMS, const char *Command)=0;
	virtual int ExecuteCommand(const char *Text)=0;
	virtual int DataParse(const char *ToParse, char *buf, size_t buflen)=0;
	virtual bool DataParse(const char *Text, LSOBJECT &Object)=0;
	virtual bool RunScript(const char *Filename)=0;
	virtual bool EndScript(const char *Filename)=0;
	virtual bool RunCommandFile(const char *Filename)=0;
	virtual bool AddTopLevelObject(const char *Name, fLSTopLevelObject Function)=0;
	virtual bool RemoveTopLevelObject(const char *Name)=0;
	virtual bool AddLSTypeDefinition(class LSTypeDefinition &Type)=0;
	virtual bool RemoveLSTypeDefinition(class LSTypeDefinition &Type)=0;
	virtual LSTypeDefinition *FindLSTypeDefinition(const char *Name, char *subtypebuf=0, size_t subtypebuflen=0)=0;
	virtual fLSCommand IsCommand(const char *Name)=0;
	virtual bool IsAlias(const char *Name)=0;
	virtual fLSTopLevelObject IsTopLevelObject(const char *Name)=0;
	virtual bool IsLSTypeDefinition(const char *Name)=0;
	virtual bool ResolveCommand(const char *Text, char *buf,size_t buflen)=0;
	virtual void *GetTempBuffer(unsigned int Size, void *CopyFrom=0)=0;
	virtual void AddTempObject(CTempObject *pObject)=0;
	virtual bool RunScriptFromBuffer(const char *Name, const char *Buffer, size_t buflen, int argc=0, char *argv[]=0, const char *CWD=0)=0;

	// pre-compiled scripts

	// compiled text and data sequences (improve performance of reused text)
	virtual unsigned int PreParseText(const char *Text, bool bDataSequence=false)=0;
	virtual bool RetrieveOriginalText(unsigned int ID, char *buf, size_t buflen)=0;
	virtual bool RetrieveProcessedText(unsigned int ID, char *buf, size_t buflen)=0;
	virtual bool RetrieveProcessedResult(unsigned int ID, LSOBJECT &Result)=0; // data sequence only
	virtual bool FreePreParsed(unsigned int ID)=0;

	// object persistence
	virtual unsigned int RegisterPersistentClass(const char *Name)=0;
	virtual void InvalidatePersistentClass(unsigned int Class)=0;
	virtual void InvalidatePersistentObject(unsigned int Class, unsigned __int64 Value)=0;
	virtual void SetPersistentClass(LSTypeDefinition *pType,unsigned int Class)=0;

	// object queries
	virtual unsigned int CreateQuery(const char *Text)=0;
	virtual bool RetrieveQueryExpression(unsigned int ID,char *buf, size_t buflen)=0;
	virtual bool QueryEvaluate(unsigned int ID,LSOBJECT &Object, bool &bResult)=0;
	virtual bool FreeQuery(unsigned int ID)=0;


	virtual unsigned int PersistObject(LSOBJECT &object)=0;
	virtual bool GetPersistedObject(unsigned int key, LSOBJECT &out_object)=0;

	virtual void ISLavishScriptInterface_06_Reserved() {}
	virtual void ISLavishScriptInterface_07_Reserved() {}
	virtual void ISLavishScriptInterface_08_Reserved() {}
	virtual void ISLavishScriptInterface_09_Reserved() {}
	virtual void ISLavishScriptInterface_10_Reserved() {}
	virtual void ISLavishScriptInterface_11_Reserved() {}
	virtual void ISLavishScriptInterface_12_Reserved() {}
	virtual void ISLavishScriptInterface_13_Reserved() {}
	virtual void ISLavishScriptInterface_14_Reserved() {}
	virtual void ISLavishScriptInterface_15_Reserved() {}



	virtual unsigned int AddGlobalAtom(const char *Buffer, size_t buflen)=0;
	virtual bool RemoveAtom(unsigned int AtomID)=0;
	virtual int ExecuteAtom(unsigned int AtomID,int argc=0, char *argv[]=0, PLSOBJECT pThisLSObject=0, PLSOBJECT pContext=0, char *ReturnBuffer=0, size_t buflen=0)=0;
	virtual int ExecuteAtom(const char *Name,int argc=0, char *argv[]=0, PLSOBJECT pContext=0, char *ReturnBuffer=0, size_t buflen=0)=0;
	virtual int ExecuteAtom(const char *ScriptName, const char *Name,int argc=0, char *argv[]=0, PLSOBJECT pContext=0, char *ReturnBuffer=0, size_t buflen=0)=0;
	virtual unsigned int ResolveAtom(const char *Name)=0;

	// enumerations
	virtual unsigned int EnumAliases(fLSGenericEnumCallback Callback, void *pData)=0;
	virtual unsigned int EnumCommands(fLSGenericEnumCallback Callback, void *pData)=0;
	virtual unsigned int EnumLSTypeDefinitions(fLSGenericEnumCallback Callback, void *pData)=0;
	virtual unsigned int EnumTopLevelObjects(fLSGenericEnumCallback Callback, void *pData)=0;
	virtual unsigned int EnumScripts(fLSGenericEnumCallback Callback, void *pData)=0;

	// scripts
	virtual bool GetCurrentScript(char *buffer, size_t buflen)=0;
	virtual bool GetScriptCWD(const char *ScriptName, char *buffer, size_t buflen)=0;
	virtual bool QueueCommand(const char *ScriptName, const char *Command)=0;
	virtual unsigned int GetScriptRuntime(const char *ScriptName)=0;
	virtual unsigned int PauseScripts()=0;
	virtual unsigned int ResumeScripts()=0;
	virtual unsigned int AddAtom(const char *ScriptName, const char *Buffer, size_t buflen)=0;
	virtual bool ScriptEngineActive()=0;
	virtual void LavishScriptPulse()=0;

	// events
	virtual unsigned int RegisterEvent(const char *Name)=0;
	virtual void UnregisterEvent(unsigned int EventID)=0;
	virtual bool ExecuteEvent(unsigned int EventID,int BeginInclusive=0, int EndExclusive=0, char *argv[]=0, PLSOBJECT pThisLSObject=0)=0;
	virtual bool AttachEventTarget(unsigned int EventID,unsigned int AtomID)=0;
	virtual bool AttachEventTarget(unsigned int EventID,fLSEventTarget fCallback)=0;
	virtual bool DetachEventTarget(unsigned int EventID,unsigned int AtomID)=0;
	virtual bool DetachEventTarget(unsigned int EventID,fLSEventTarget fCallback)=0;

	// misc
	virtual unsigned int GetRuntime()=0;
	virtual char *Escape(const char *text, char *buf, size_t buflen)=0;
	virtual char *EscapeQuotes(const char *text, char *buf, size_t buflen) = 0;
	virtual bool CalculateResult(const char *Formula, double &Result)=0;
	virtual bool CalculateResult(const char *Formula, __int64 &Result)=0;

	virtual void Printf(const char *Format, ...)=0;
	virtual void Print(const char *Text)=0;
	virtual unsigned int GetTerminalWidth()=0;

// inline functions
	inline bool AddLSType(class LSTypeDefinition &Type) { return AddLSTypeDefinition(Type); }
	inline bool RemoveLSType(class LSTypeDefinition &Type) { return RemoveLSTypeDefinition(Type); }
	inline LSTypeDefinition *FindLSType(char *Name) { return FindLSTypeDefinition(Name); }

	inline bool IsLSType(char *Name) {	return IsLSTypeDefinition(Name); }
};

class ISServiceMasterInterface
{
public:
	// service master
	virtual HISXSERVICE RegisterService(ISXInterface *pMaster, const char *Name, fISServiceRequest RequestCallback=0)=0;
	virtual bool ServiceBroadcast(ISXInterface *pMaster, HISXSERVICE hService, unsigned int MSG, void *lpData)=0;
	virtual bool ServiceNotify(ISXInterface *pMaster, HISXSERVICE hService, ISXInterface *pTarget, unsigned int MSG, void *lpData)=0;
	virtual bool ShutdownService(ISXInterface *pMaster, HISXSERVICE hService)=0;
};

class ISServiceClientInterface
{
public:
	// service client
	virtual HISXSERVICE ConnectService(ISXInterface *pClient, const char *ServiceName, fISService NotifyCallback)=0;
	virtual bool ServiceRequest(ISXInterface *pClient, HISXSERVICE hService, unsigned int MSG, void *lpData)=0;
	virtual void DisconnectService(ISXInterface *pClient, HISXSERVICE hService)=0;
};

class ISInputInterface
{
public:
	// input
	virtual bool AddHotkey(const char *Name, const char *Combo, const char *Command, bool Press=false)=0;
	virtual bool IsHotkey(const char *Name)=0;
	virtual bool RemoveHotkey(const char *Name)=0;
	virtual bool MouseTo(int X, int Y)=0;
	virtual bool GetMousePos(int &X, int &Y)=0;

	virtual bool EmulateKeyPress(const char *Combo, bool Hold)=0;
	virtual bool EmulateKeyRelease(const char *Combo)=0;
	virtual bool EmulateTyping(const char *Text)=0;
	virtual bool EmulateMousePress(unsigned int Button, bool Hold)=0;
	virtual bool EmulateMouseRelease(unsigned int Button)=0;

	// disable binds
	virtual unsigned int SetPrintableBindsAllowed(bool bEnable)=0;
	virtual unsigned int GetPrintableBindsAllowedCount()=0;


	virtual void ISInputInterface_00_Reserved() {}
	virtual void ISInputInterface_01_Reserved() {}
	virtual void ISInputInterface_02_Reserved() {}
	virtual void ISInputInterface_03_Reserved() {}
	virtual void ISInputInterface_04_Reserved() {}
	virtual void ISInputInterface_05_Reserved() {}

};

class ISLavishSettingsInterface
{
public:

	/* DEPRECATED, TO BE REMOVED IN NEAR FUTURE ISXDK */
	virtual __declspec(deprecated) bool GetSetting(char *Filename, char *Set, char *Setting, char *buf, size_t buflen)=0;
	virtual __declspec(deprecated) bool SetSetting(char *Filename, char *Set, char *Setting, char *Value)=0;
	virtual __declspec(deprecated) bool GetSettingb(char *Filename, char *Set, char *Setting, bool &bValue)=0;
	virtual __declspec(deprecated) bool GetSettingi(char *Filename, char *Set, char *Setting, int &iValue)=0;
	virtual __declspec(deprecated) bool SetSettingi(char *Filename, char *Set, char *Setting, int iValue)=0;
	virtual __declspec(deprecated) bool GetSettingf(char *Filename, char *Set, char *Setting, float &fValue)=0;
	virtual __declspec(deprecated) bool SetSettingf(char *Filename, char *Set, char *Setting, float fValue)=0;
	virtual __declspec(deprecated) bool IsSet(char *Filename, char *Set)=0;
	virtual __declspec(deprecated) bool CreateSet(char *Filename, char *Set)=0;
	virtual __declspec(deprecated) bool RemoveSet(char *Filename, char *Set)=0;
	virtual __declspec(deprecated) bool RemoveSetting(char *Filename, char *Set, char *Setting)=0;
	virtual __declspec(deprecated) unsigned int EnumSets(char *Filename, fSetEnumCallback Callback, void *pData)=0;
	virtual __declspec(deprecated) unsigned int EnumSettings(char *Filename, char *Set, fSettingEnumCallback Callback, void *pData)=0;

	virtual __declspec(deprecated) bool UnloadSettings(char *Filename)=0; // Use UnloadSet
	virtual __declspec(deprecated) bool SaveSettings(char *Filename)=0; // Use ExportSet

	/* NEW AND IMPROVED! */
	virtual unsigned int OpenSettings(const char *Filename)=0;
	
	virtual unsigned int FindFileSet(const char *Filename)=0;
	virtual unsigned int FindSet(unsigned int &ParentSetGUID, const char *Name)=0;
	virtual bool SaveFileSet(const char *Filename)=0;

	virtual bool ExportSet(unsigned int &SetGUID, const char *Filename)=0;
	virtual bool ImportToSet(unsigned int &SetGUID, const char *Filename)=0;
	virtual bool CopySet(unsigned int &ToSetGUID, unsigned int FromSetGUID)=0;
	virtual bool UnloadSet(unsigned int &SetGUID)=0;
	virtual bool ClearSet(unsigned int &SetGUID)=0;
	virtual bool SortSet(unsigned int &SetGUID)=0;
	virtual unsigned int CreateSet(unsigned int &SetGUID, const char *Name)=0;
	virtual bool GetSetName(unsigned int &SetGUID, char *buf, size_t buflen)=0;
	virtual bool GetSetParent(unsigned int &SetGUID, unsigned int &ParentSetGUID)=0;

	virtual bool RenameSetting(unsigned int &SetGUID, const char *Setting, const char *NewName)=0;
	virtual bool RemoveSetting(unsigned int &SetGUID, const char *Setting)=0;

	virtual bool AssertSetting(unsigned int &SetGUID, const char *Setting, const char *Value)=0;
	virtual bool AssertSetting(unsigned int &SetGUID, const char *Setting, bool &bValue)=0;
	virtual bool AssertSetting(unsigned int &SetGUID, const char *Setting, int iValue)=0;
	virtual bool AssertSetting(unsigned int &SetGUID, const char *Setting, float &fValue)=0;
	virtual bool AssertSetting(unsigned int &SetGUID, const char *Setting, unsigned int &ulValue)=0;
	virtual bool AssertSetting(unsigned int &SetGUID, const char *Setting, __int64 &Value)=0;

	virtual bool GetSetting(unsigned int &SetGUID, const char *Setting, char *buf, size_t buflen)=0;
	virtual bool GetSetting(unsigned int &SetGUID, const char *Setting, bool &bValue)=0;
	virtual bool GetSetting(unsigned int &SetGUID, const char *Setting, int &iValue)=0;
	virtual bool GetSetting(unsigned int &SetGUID, const char *Setting, float &fValue)=0;
	virtual bool GetSetting(unsigned int &SetGUID, const char *Setting, unsigned int &ulValue)=0;
	virtual bool GetSetting(unsigned int &SetGUID, const char *Setting, __int64 &Value)=0;

	virtual bool SetSetting(unsigned int &SetGUID, const char *Setting, const char *Value)=0;
	virtual bool SetSetting(unsigned int &SetGUID, const char *Setting, int iValue)=0;
	virtual bool SetSetting(unsigned int &SetGUID, const char *Setting, unsigned int &ulValue)=0;
	virtual bool SetSetting(unsigned int &SetGUID, const char *Setting, float &fValue)=0;
	virtual bool SetSetting(unsigned int &SetGUID, const char *Setting, __int64 &Value)=0;

	virtual bool CreateComment(unsigned int &SetGUID, const char *Text)=0;

	virtual unsigned int EnumSets(unsigned int &SetGUID, fSetEnumCallback Callback, void *pData)=0;
	virtual unsigned int EnumSettings(unsigned int &SetGUID, fSettingEnumCallback Callback, void *pData)=0;

	virtual void ISLavishSettingsInterface_00_Reserved() {}
	virtual void ISLavishSettingsInterface_01_Reserved() {}
	virtual void ISLavishSettingsInterface_02_Reserved() {}
	virtual void ISLavishSettingsInterface_03_Reserved() {}
	virtual void ISLavishSettingsInterface_04_Reserved() {}
	virtual void ISLavishSettingsInterface_05_Reserved() {}
	virtual void ISLavishSettingsInterface_06_Reserved() {}
	virtual void ISLavishSettingsInterface_07_Reserved() {}
	virtual void ISLavishSettingsInterface_08_Reserved() {}
	virtual void ISLavishSettingsInterface_09_Reserved() {}
	virtual void ISLavishSettingsInterface_10_Reserved() {}
	virtual void ISLavishSettingsInterface_11_Reserved() {}
	virtual void ISLavishSettingsInterface_12_Reserved() {}
	virtual void ISLavishSettingsInterface_13_Reserved() {}
	virtual void ISLavishSettingsInterface_14_Reserved() {}
	virtual void ISLavishSettingsInterface_15_Reserved() {}
	virtual void ISLavishSettingsInterface_16_Reserved() {}
	virtual void ISLavishSettingsInterface_17_Reserved() {}
	virtual void ISLavishSettingsInterface_18_Reserved() {}
	virtual void ISLavishSettingsInterface_19_Reserved() {}
	virtual void ISLavishSettingsInterface_20_Reserved() {}

};

class ISIPCInterface
{
public:
	// inter-process
	virtual void Relay(const char *Session, const char *Command)=0;
	virtual unsigned int GetSessionCount()=0;
	virtual bool GetSessionName(unsigned int nSession, char *buf, size_t buflen) = 0;

	virtual void ISIPCInterface_00_Reserved() {}
	virtual void ISIPCInterface_01_Reserved() {}
	virtual void ISIPCInterface_02_Reserved() {}
	virtual void ISIPCInterface_03_Reserved() {}
	virtual void ISIPCInterface_04_Reserved() {}
	virtual void ISIPCInterface_05_Reserved() {}

};

class ISNavigationInterface
{
public:
	virtual unsigned int LNavAddRegion(unsigned int ParentGUID, const char *Type, const char *Name, int BeginInclusive, int EndExclusive, char *argv[])=0;
	virtual bool LNavRemoveRegion(unsigned int RegionGUID)=0;

	virtual unsigned int LNavAddConnection(unsigned int FromGUID, unsigned int ToGUID, int BeginInclusive, int EndExclusive, char *argv[])=0;
	virtual bool LNavRemoveConnection(unsigned int ConnectionGUID)=0;

	virtual unsigned int LNavResolveFQN(const char *FQN, unsigned int FromGUID=0)=0;

	virtual bool LNavImportXML(unsigned int ParentGUID, const char *Filename)=0;
	virtual bool LNavExportXML(unsigned int RegionGUID, const char *Filename, bool OnlyChildren)=0;

	virtual void ISNavigationInterface_00_Reserved() {}
	virtual void ISNavigationInterface_01_Reserved() {}
	virtual void ISNavigationInterface_02_Reserved() {}
	virtual void ISNavigationInterface_03_Reserved() {}
	virtual void ISNavigationInterface_04_Reserved() {}
	virtual void ISNavigationInterface_05_Reserved() {}
	virtual void ISNavigationInterface_06_Reserved() {}
	virtual void ISNavigationInterface_07_Reserved() {}
	virtual void ISNavigationInterface_08_Reserved() {}
	virtual void ISNavigationInterface_09_Reserved() {}
	virtual void ISNavigationInterface_10_Reserved() {}
	virtual void ISNavigationInterface_11_Reserved() {}
	virtual void ISNavigationInterface_12_Reserved() {}
	virtual void ISNavigationInterface_13_Reserved() {}
	virtual void ISNavigationInterface_14_Reserved() {}
	virtual void ISNavigationInterface_15_Reserved() {}
	virtual void ISNavigationInterface_16_Reserved() {}
	virtual void ISNavigationInterface_17_Reserved() {}
	virtual void ISNavigationInterface_18_Reserved() {}
	virtual void ISNavigationInterface_19_Reserved() {}
	virtual void ISNavigationInterface_20_Reserved() {}

};

class ISDisplayInterface
{
public:
	// display
	virtual bool GetDisplaySize(unsigned int &Height, unsigned int &Width)=0;
	virtual bool GetPixel(int X, int Y, RGBCOLOR &Color)=0;
	virtual bool GetPixels(int X, int Y, unsigned int nRows, unsigned int nColumns, RGBCOLOR **Rows)=0;
	virtual bool GetDisplayRect(enum _D3DXIMAGE_FILEFORMAT format, bool front_buffer, RECT *optional_area, struct ID3DXBuffer **ppScreenshot)=0;

	virtual void ISDisplayInterface_01_Reserved() {}
	virtual void ISDisplayInterface_02_Reserved() {}
	virtual void ISDisplayInterface_03_Reserved() {}
	virtual void ISDisplayInterface_04_Reserved() {}
	virtual void ISDisplayInterface_05_Reserved() {}
	virtual void ISDisplayInterface_06_Reserved() {}
	virtual void ISDisplayInterface_07_Reserved() {}
	virtual void ISDisplayInterface_08_Reserved() {}
	virtual void ISDisplayInterface_09_Reserved() {}
	virtual void ISDisplayInterface_10_Reserved() {}
	virtual void ISDisplayInterface_11_Reserved() {}
	virtual void ISDisplayInterface_12_Reserved() {}
	virtual void ISDisplayInterface_13_Reserved() {}
	virtual void ISDisplayInterface_14_Reserved() {}
	virtual void ISDisplayInterface_15_Reserved() {}
	virtual void ISDisplayInterface_16_Reserved() {}
	virtual void ISDisplayInterface_17_Reserved() {}
	virtual void ISDisplayInterface_18_Reserved() {}
	virtual void ISDisplayInterface_19_Reserved() {}
	virtual void ISDisplayInterface_20_Reserved() {}

};

class ISLavishVMInterface
{
public:
	/* LavishVM */
	virtual bool IsAvailable()=0;
	virtual bool TryInitialize()=0;
	virtual bool RegisterLibrary(const char *Name,fGetAPI)=0;
	virtual bool UnregisterLibrary(const char *Name)=0;
	virtual bool Execute(const char *Domain, const char *AssemblyName, int argc=0, const char *argv[]=0)=0;
	virtual bool UnloadDomain(const char *Name)=0;

	virtual unsigned int EnumDomains(fDomainEnumCallback, void *pData)=0;
	virtual bool IsDomainActive(const char *Name)=0;

	/* Threading (including LavishVM) */
	virtual void FrameLock()=0;
	virtual void FrameUnlock()=0;
	virtual bool FrameTryLock()=0;
	virtual void FrameWait(bool bLock)=0;
};

class ISInterface : public ISLavishScriptInterface, 
	public ISServiceMasterInterface, 
	public ISServiceClientInterface, 
	public ISInputInterface,
	public ISLavishSettingsInterface,
	public ISIPCInterface,
	public ISNavigationInterface,
	public ISDisplayInterface,
	public ISLavishVMInterface
{
public:
	virtual unsigned int GetVersion()=0;
	virtual unsigned int GetBuildNumber()=0;

	virtual unsigned int GetExtensionSetGUID(const char *Extension)=0;
	virtual unsigned int GetScriptSetGUID(const char *Script)=0;
	virtual unsigned int CreateExtensionSet(const char *Extension)=0;
	virtual unsigned int CreateScriptSet(const char *Script)=0;

	virtual unsigned int GetGameSetGUID()=0;
	virtual unsigned int GetProfileSetGUID()=0;

	virtual bool LoadExtension(const char *Filename)=0;
	virtual bool UnloadExtension(const char *Filename, bool &denied_by_extension)=0;
	virtual bool IsExtensionLoaded(const char *Filename)=0;

	// High Stealth is intended for temporarily increasing stealth while an application
	// performs scanning and detection methods
	virtual bool HighStealthEnabled()=0;
	virtual void EnableHighStealth()=0;
	virtual void DisableHighStealth()=0;

	// paths
	virtual char *GetInnerSpacePath(char *buffer, size_t buflen)=0;
	virtual char *GetLogsPath(const char *extension_subdir, char *buffer, size_t buflen) = 0;

	virtual char *GetSettingsPath(char *buffer, size_t buflen) = 0;
	virtual char *GetNETProgramsPath(char *buffer, size_t buflen) = 0;
	virtual char *GetExtensionsPath(char *buffer, size_t buflen) = 0;
	virtual char *GetInterfacePath(char *buffer, size_t buflen) = 0;
	virtual char *GetLavishScriptModulesPath(char *buffer, size_t buflen) = 0;
	virtual char *GetScreenshotsPath(char *buffer, size_t buflen) = 0;
	virtual char *GetScriptsPath(char *buffer, size_t buflen) = 0;

	// hud
	virtual bool AddElement(const char *Name, const char *Data, int X, int Y, unsigned int Color, const char *Group="Default")=0;
	virtual bool RemoveElement(const char *Name)=0;

	// console
	virtual void ClearConsole()=0;

	virtual void EnableStealth()=0;
	virtual bool StealthEnabled()=0;

	virtual void StoreInnerSpaceSettings() {};



	virtual bool GetLavishScript2Environment_(unsigned int LS2MODULE_SDK_VERSION, void **ppEnvironment)=0;
	bool GetLavishScript2Environment(unsigned int LS2MODULE_SDK_VERSION, void **ppEnvironment)
	{
		if (GetBuildNumber()>=5671)
			return GetLavishScript2Environment_(LS2MODULE_SDK_VERSION,ppEnvironment);
		return false;
	}

	virtual void ISInterface_01_Reserved() {}
	virtual void ISInterface_02_Reserved() {}
	virtual void ISInterface_03_Reserved() {}
	virtual void ISInterface_04_Reserved() {}
	virtual void ISInterface_05_Reserved() {}
	virtual void ISInterface_06_Reserved() {}
	virtual void ISInterface_07_Reserved() {}
	virtual void ISInterface_08_Reserved() {}
	virtual void ISInterface_09_Reserved() {}
	virtual void ISInterface_10_Reserved() {}
	virtual void ISInterface_11_Reserved() {}
	virtual void ISInterface_12_Reserved() {}
	virtual void ISInterface_13_Reserved() {}
	virtual void ISInterface_14_Reserved() {}
	virtual void ISInterface_15_Reserved() {}
	virtual void ISInterface_16_Reserved() {}
	virtual void ISInterface_17_Reserved() {}
	virtual void ISInterface_18_Reserved() {}
	virtual void ISInterface_19_Reserved() {}
	virtual void ISInterface_20_Reserved() {}
};

