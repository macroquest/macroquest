#pragma once
#pragma pack(push)
#pragma pack(8)
#include <isxdk.h>
#pragma pack(pop)


class ISXEQLabels :
	public ISXInterface
{
public:

	virtual bool Initialize(ISInterface *p_ISInterface);
	virtual void Shutdown();

	void LoadSettings();
	void ConnectServices();
	void RegisterCommands();
	void RegisterAliases();
	void RegisterDataTypes();
	void RegisterTopLevelObjects();
	void RegisterServices();

	void DisconnectServices();
	void UnRegisterCommands();
	void UnRegisterAliases();
	void UnRegisterDataTypes();
	void UnRegisterTopLevelObjects();
	void UnRegisterServices();

};

extern ISInterface *pISInterface;
extern HISXSERVICE hPulseService;
extern HISXSERVICE hMemoryService;
extern HISXSERVICE hServicesService;

extern HISXSERVICE hEQChatService;
extern HISXSERVICE hEQUIService;
extern HISXSERVICE hEQGamestateService;
extern HISXSERVICE hEQSpawnService;
extern HISXSERVICE hEQZoneService;

extern ISXEQLabels *pExtension;
#define printf pISInterface->Printf

#define EzDetour(Address, Detour, Trampoline) IS_Detour(pExtension,pISInterface,hMemoryService,(unsigned int)Address,Detour,Trampoline)
#define EzUnDetour(Address) IS_UnDetour(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzModify(Address,NewData,Length,Reverse) Memory_Modify(pExtension,pISInterface,hMemoryService,(unsigned int)Address,NewData,Length,Reverse)
#define EzUnModify(Address) Memory_UnModify(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzHttpRequest(_URL_,_pData_) IS_HttpRequest(pExtension,pISInterface,hHTTPService,_URL_,_pData_)

extern LSType *pStringType;
extern LSType *pIntType;
extern LSType *pBoolType;
extern LSType *pFloatType;
extern LSType *pTimeType;
extern LSType *pByteType;
