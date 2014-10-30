/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#pragma once
#pragma pack(push)
#pragma pack(8)
#include <isxdk.h>
#pragma pack(pop)
#pragma warning(disable: 4996)
class EQProtected
{
public:
   EQProtected(unsigned int p_Address, unsigned int p_Size, const void *OriginalData)
   {
      Address=p_Address;
      Size=p_Size;
	  EndAddress=Address+Size;
      Array=(unsigned char*)malloc(p_Size);
	  if (OriginalData)
		memcpy(Array,OriginalData, p_Size);
	  else
		memcpy(Array,(char *)p_Address, p_Size);
   }

   ~EQProtected()
   {
      free(Array);
   }

   inline bool Contains(unsigned int TestAddress)
   {
      return (TestAddress>=Address && TestAddress<Address+Size);
   }
   
   unsigned int Address;
   unsigned int EndAddress;
   unsigned int Size;
   unsigned char *Array;
}; 

class CISXEQ :
	public ISXInterface
{
public:
	CISXEQ(void);
	~CISXEQ(void);

	virtual bool Initialize(ISInterface *p_ISInterface);
	virtual void Shutdown();

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

	bool Memcpy_Clean(unsigned int BeginAddress, unsigned char *buf, unsigned int buflen);
	 VOID HookMemChecker(BOOL Patch); 
	bool Protect(unsigned int Address, unsigned int Size, const void *OriginalData); 
	 bool UnProtect(unsigned int Address); 
	map<unsigned int, EQProtected*> ProtectedMap; 
};

extern ISInterface *pISInterface;
extern HISXSERVICE hPulseService;
extern HISXSERVICE hMemoryService;
extern HISXSERVICE hHTTPService;
extern HISXSERVICE hTriggerService;

extern CISXEQ *pExtension;
#define printf pISInterface->Printf

extern unsigned int ChatEventID;
extern HISXSERVICE hChatService;
extern HISXSERVICE hUIService;
extern HISXSERVICE hGamestateService;
extern HISXSERVICE hSpawnService;
extern HISXSERVICE hZoneService;

extern unsigned int PersistentPointerClass;

#define EzDetour(Address, Detour, Trampoline) IS_Detour(pExtension,pISInterface,hMemoryService,(unsigned int)Address,Detour,Trampoline)
#define EzUnDetour(Address) IS_UnDetour(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzModify(Address,NewData,Length) Memory_Modify(pExtension,pISInterface,hMemoryService,(unsigned int)Address,NewData,Length,false)
#define EzUnModify(Address) Memory_UnModify(pExtension,pISInterface,hMemoryService,(unsigned int)Address)

#define EzHttpRequest(_URL_,_pData_) IS_HttpRequest(pExtension,pISInterface,hHTTPService,_URL_,_pData_)

extern LSTypeDefinition *pMutableStringType;
extern LSTypeDefinition *pWStringType;
extern LSTypeDefinition *pUniStringType;
extern LSTypeDefinition *pIntType;
extern LSTypeDefinition *pUIntType;
extern LSTypeDefinition *pInt64Type;
extern LSTypeDefinition *pInt64PtrType;
extern LSTypeDefinition *pBoolType;
extern LSTypeDefinition *pFloatType;
extern LSTypeDefinition *pTimeType;
extern LSTypeDefinition *pByteType;
extern LSTypeDefinition *pIntPtrType;
extern LSTypeDefinition *pBoolPtrType;
extern LSTypeDefinition *pFloatPtrType;
extern LSTypeDefinition *pFloat64PtrType;
extern LSTypeDefinition *pBytePtrType;
extern LSTypeDefinition *pPoint3fType;
extern LSTypeDefinition *pIndexType;
extern LSTypeDefinition *pVectorType;
extern LSTypeDefinition *pMapType;
extern LSTypeDefinition *pSetType;
extern LSTypeDefinition *pStringType;