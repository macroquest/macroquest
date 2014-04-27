#pragma once
#pragma pack(push)
#pragma pack(8)
#include <isxdk.h>
#pragma pack(pop)

class ISXEQChatWnd : public ISXInterface
{
public:
    virtual bool Initialize(ISInterface *p_ISInterface);
    virtual void Shutdown();
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

extern ISXEQChatWnd *pExtension;

#define printf pISInterface->Printf

#define EzDetour(Address, Detour, Trampoline) IS_Detour(pExtension,pISInterface,hMemoryService,(unsigned int)Address,Detour,Trampoline)
#define EzUnDetour(Address) IS_UnDetour(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzModify(Address,NewData,Length,Reverse) Memory_Modify(pExtension,pISInterface,hMemoryService,(unsigned int)Address,NewData,Length,Reverse)
#define EzUnModify(Address) Memory_UnModify(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzHttpRequest(_URL_,_pData_) IS_HttpRequest(pExtension,pISInterface,hHTTPService,_URL_,_pData_)
