#pragma once
#pragma pack(push)
#pragma pack(8)
//
// Inner Space Extension Library
// (c) 2004-2014 Lavish Software, LLC
//

#define ISXDK_VERSION 0x0034
#pragma warning( push )
#pragma warning( disable : 4996 )

//#include <tchar.h>
#include <windows.h>
#include <map>
#include <string>
#include "utf8string.h"
#include <algorithm>
#include <math.h>
#include "WinThreading.h"
#include "Index.h"
#include "Queue.h"
#include "FileList.h"
#ifndef ISXDK_NOLAVISHSCRIPT
#include "LavishScript/LavishScript.h"
#else
#define LSType unsigned int
#define fLSCommand unsigned int
#define fLSTopLevelObject unsigned int
#define PLSOBJECT unsigned int
#define CTempObject unsigned int
#define CNavPath unsigned int
#define RGBCOLOR unsigned int
//#define fLSEventTarget unsigned int

struct POINT2I
{
	int X;
	int Y;
};

struct POINT2F
{
	float X;
	float Y;
};
struct POINT3F : public POINT2F
{
	float Z;
};
#endif

#ifndef ISXDK_NOLAVISHSCRIPT
typedef void (__cdecl *fLSEventTarget)(int argc, char *argv[], PLSOBJECT);
#else
typedef void (__cdecl *fLSEventTarget)(int argc, char *argv[], void *);
typedef void (__cdecl *fLSGenericEnumCallback)(const char *Name, void *pData);

#ifdef RGBCOLOR
#undef RGBCOLOR
#endif

typedef struct _RGBColor
{
	union {
		unsigned int ulColor;
		struct {
			unsigned char Red;
			unsigned char Green;
			unsigned char Blue;
			unsigned char Reserved;
		};
        struct {
            unsigned char B;
            unsigned char G;
            unsigned char R;
            unsigned char A;
        };
        unsigned int ARGB;
	};
} RGBCOLOR, *PRGBCOLOR;
#endif

#ifndef ISXDK_NOISUI
#pragma comment(lib,"ISUI.lib")
#include "ISUI/LGUI.h"
#endif
using namespace std;
#define MakeLower(yourstring) transform (yourstring.begin(),yourstring.end(), yourstring.begin(), tolower);


// from Blech.h
#ifndef BLECHVERSION
typedef struct _BLECHVALUE {
	char *Name;
	char *Value;
	struct _BLECHVALUE *pNext;
} BLECHVALUE, *PBLECHVALUE;

typedef unsigned int   (__stdcall *fBlechVariableValue)(char *VarName, char *Value);
typedef void (__stdcall *fBlechCallback)(unsigned int ID, void *pData, PBLECHVALUE pValues);
#endif

#ifndef FUNCTION_AT_ADDRESS
#define FUNCTION_AT_ADDRESS(function,offset) __declspec(naked) function\
{\
	__asm{mov eax, offset};\
	__asm{jmp eax};\
}
#endif

#ifndef FUNCTION_AT_VARIABLE_ADDRESS
#define FUNCTION_AT_VARIABLE_ADDRESS(function,variable) __declspec(naked) function\
{\
	__asm{mov eax, [variable]};\
	__asm{jmp eax};\
}
#endif

#ifndef FUNCTION_AT_VIRTUAL_ADDRESS
#define FUNCTION_AT_VIRTUAL_ADDRESS(function,virtualoffset) __declspec(naked) function\
{\
	__asm{mov eax, [ecx]};\
	__asm{lea eax, [eax+virtualoffset]};\
	__asm{mov eax, [eax]};\
	__asm{jmp eax};\
}
#endif

#ifndef DETOUR_TRAMPOLINE_EMPTY
#define DETOUR_TRAMPOLINE_EMPTY(trampoline) \
__declspec(naked) trampoline \
{ \
    __asm { nop };\
    __asm { nop };\
    __asm { xor eax, eax };\
    __asm { mov eax, [eax] };\
    __asm { ret };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
    __asm { nop };\
}
#endif

#ifndef ISXDK_NOLAVISHSCRIPT
struct NamedPoint
{
	char Name[128];
	POINT3F pt;
};

class CNavPath
{
public:
	CNavPath()
	{
		nPoints=0;
	}

	~CNavPath()
	{
		Reset();
	}

	void Reset()
	{
		Points.Cleanup();
		nPoints=0;
	}

	void RemoveLast()
	{
		if (nPoints)
		{
			nPoints--;
			delete Points[nPoints];
			Points[nPoints]=0;
		}
	}

	void AddPoint(POINT3F &pt, char *Name=0)
	{
		NamedPoint *pPoint=new NamedPoint;
		pPoint->pt=pt;
		if (Name)
		{
			strncpy(pPoint->Name,Name,128);
			pPoint->Name[127]=0;
		}
		else
			pPoint->Name[0]=0;
		Points+=pPoint;
		nPoints++;
	}

	void Reverse()
	{
		if (nPoints)
		{
			CLock L(&Points.CS,1);
			unsigned int Mid=nPoints/2;
			unsigned int nPointsLess1=nPoints-1;
			for (unsigned int i = 0 ; i < Mid ; i++)
			{
				unsigned int Second=nPointsLess1-i;
				NamedPoint* Temp=Points[i];
				Points[i]=Points[Second];
				Points[Second]=Temp;
			}
		}
	}

	unsigned int nPoints;
	CIndex<NamedPoint*> Points;
};

class CPixelMap
{
public:
	CPixelMap(unsigned int nRows, unsigned int nColumns)
	{
		Rows=(RGBCOLOR**)malloc(nRows*sizeof(RGBCOLOR**));
		unsigned int BufferSize=nRows*nColumns*sizeof(RGBCOLOR);
		Buffer=(RGBCOLOR*)malloc(BufferSize);
		ZeroMemory(Buffer,BufferSize);
		for (unsigned int i = 0 ; i < nRows ; i++)
		{
			Rows[i]=&Buffer[nColumns*i];
		}
	}
	~CPixelMap()
	{
		free(Rows);
		free(Buffer);
	};
	RGBCOLOR **Rows;
private:
	RGBCOLOR *Buffer;
};

static inline bool IsNumber(const char *String)
{
	if (*String==0)
		return false;
	if (*String=='-')
		String++;
	while(*String)
	{
		if (!((*String>='0' && *String<='9') || *String=='.'))
			return false;
		++String;
	}
	return true;
}

static inline bool IsHex(const char *String)
{
	if (*String==0)
		return false;
	while(*String)
	{
		if ((*String<'0' || *String>'9') &&
			(*String<'a' || *String>'f') &&
			(*String<'A' || *String>'F')
			)
			return false;
		++String;
	}
	return true;
}
#endif

static inline bool IsAbsolutePath(const char *String)
{
	if (!String)
		return false;
	if (String[0]=='\\' || String[0]=='/')
		return true;
	if (strchr(String,':'))
		return true;
	return false;
}

static inline bool IsAbsolutePath(const wchar_t *String)
{
	if (!String)
		return false;
	if (String[0]=='\\' || String[0]=='/')
		return true;
	if (wcschr(String,':'))
		return true;
	return false;
}

#ifndef FOPEN_UTF8
#define FOPEN_UTF8
static inline FILE *fopen_utf8(const char *filename, const char *mode)
{
	WCHAR wFilename[512];
	wFilename[0]=0;
	MultiByteToWideChar(CP_UTF8,0,filename,-1,wFilename,512);
	wFilename[511]=0;
	WCHAR wMode[512];
#pragma warning( push )
#pragma warning( disable : 4996 )
		swprintf(wMode,L"%S",mode);
	return _wfopen(wFilename,wMode);
#pragma warning( pop )
}
#endif

#ifndef FEXISTS_UTF8
#define FEXISTS_UTF8
static inline bool fexists_utf8(const char *filename)
{
	WCHAR wFilename[512];
	wFilename[0]=0;
	MultiByteToWideChar(CP_UTF8,0,filename,-1,wFilename,512);
	wFilename[511]=0;
	return (_waccess( wFilename, 0 )) != -1;
}
#endif

#ifndef WFEXISTS
#define WFEXISTS
static inline bool _wfexists(const wchar_t *wFilename)
{
	return (_waccess( wFilename, 0 )) != -1;
}
#endif

typedef unsigned int HISXSERVICE;

class ISXInterface;
#ifndef LVM_TYPEDEFS
#define LVM_TYPEDEFS
typedef void (__stdcall *fDomainEnumCallback)(const char *Name, void *pData);
typedef void * (__stdcall *fGetAPI)(const char *Name, unsigned int Version);
#endif

typedef void (__cdecl *fISService)(bool Broadcast, unsigned int MSG, void *lpData);
typedef void (__cdecl *fISServiceRequest)(ISXInterface *pClient, unsigned int MSG, void *lpData);
typedef ISXInterface *(__cdecl *fCreateISXInterface)(unsigned int);

typedef void (__cdecl *fSetEnumCallback)(const char *Name, void *pData);
typedef void (__cdecl *fNavWorldEnumCallback)(const char *Name, void *pData);
typedef void (__cdecl *fSettingEnumCallback)(const char *Name, const char *Value, void *pData);

#include "ISInterface.h"
#include "ISXInterface.h"
#include "ColumnRenderer.h"
#include "Services.h"

class ISXPreParse
{
public:
	inline ISXPreParse(class ISInterface *pInterface, const char *Text)
	{
		ID=pInterface->PreParseText(Text);
	}
	inline ~ISXPreParse()
	{
		pInterface->FreePreParsed(ID);
	}

	inline bool RetrieveOriginalText(char *buf, size_t buflen)
	{
		return pInterface->RetrieveOriginalText(ID,buf,buflen);
	}
	inline bool RetrieveProcessedText(char *buf, size_t buflen)
	{
		return pInterface->RetrieveProcessedText(ID,buf,buflen);
	}

	unsigned int ID;
	ISInterface *pInterface;
};

class ISXDataSequence
{
public:
	inline ISXDataSequence(class ISInterface *pInterface, const char *DataSequence)
	{
		ID=pInterface->PreParseText(DataSequence,true);
	}
	inline ~ISXDataSequence()
	{
		pInterface->FreePreParsed(ID);
	}

	inline bool RetrieveOriginalText(char *buf, unsigned int buflen)
	{
		return pInterface->RetrieveOriginalText(ID,buf,buflen);
	}
	inline bool RetrieveProcessedText(char *buf, unsigned int buflen)
	{
		return pInterface->RetrieveProcessedText(ID,buf,buflen);
	}
	inline bool RetrieveProcessedResult(LSOBJECT &Result)
	{
		return pInterface->RetrieveProcessedResult(ID,Result);
	}

	unsigned int ID;
	ISInterface *pInterface;
};


#define ISXDllMain(_name_,_class_) \
	BOOL APIENTRY DllMain(HANDLE hModule, \
	DWORD  ul_reason_for_call, \
	LPVOID lpReserved \
	) \
{ \
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) \
	{ \
		g_hModule = (HMODULE)hModule; \
		DWORD ResultLen = GetModuleFileName((HMODULE)hModule, ModulePath, sizeof(ModulePath)); \
		memcpy(ActualModulePath, ModulePath, ResultLen + 1); \
		if (char *pSlash = strrchr(ModulePath, '\\')) \
		{ \
			*pSlash = 0; \
			ModuleFileName = &pSlash[1]; \
		}\
		else \
		{\
			ModuleFileName = ActualModulePath; \
			ModulePath[0] = '.'; \
			ModulePath[1] = 0; \
		}\
		sprintf_s(INIFileName, "%s\\%s.ini", ModulePath, _name_); \
		sprintf_s(XMLFileName, "%s.xml", _name_); \
		sprintf_s(PluginLog, "%s\\%s.log", ModulePath, _name_); \
	}\
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)\
	{\
		if (pExtension)\
		{\
			delete pExtension; \
			pExtension = 0; \
		}\
	}\
	return TRUE; \
}

#define ISXDKDependencies(_name_,_class_) \
class LSTypeDefinition * FindLSTypeDefinition(const char *Name)\
{\
	return pISInterface->FindLSTypeDefinition(Name); \
}\
void *GetTempBuffer(size_t Size, const void *Copy)\
{\
	return pISInterface->GetTempBuffer((unsigned int)Size, (void*)Copy); \
}\
void RegisterTemporaryObject(class CTempObject *pObject)\
{\
	pISInterface->AddTempObject(pObject); \
}\
void InvalidatePersistentObject(unsigned int persistentClass, unsigned __int64 persistedValue)\
{\
	pISInterface->InvalidatePersistentObject(persistentClass, persistedValue); \
}\
unsigned int RegisterPersistentClass(const char *name)\
{\
	return pISInterface->RegisterPersistentClass(name); \
}

#define ISXExports(_name_,_class_) \
extern "C" __declspec(dllexport) ISXInterface * __cdecl CreateISXInterface(unsigned int ISInterfaceVersion) \
{\
	if (pExtension || ISInterfaceVersion != ISXDK_VERSION) \
		return 0; \
	pExtension = new _class_; \
	return pExtension; \
}\
extern void __cdecl InitializeISXDK(void *); \
extern "C" __declspec(dllexport) ISXInterface * __cdecl CreateISXInterfaceEx(void *p) \
{\
	if (pExtension)\
		return 0; \
	InitializeISXDK(p); \
	pExtension = new _class_; \
	return pExtension; \
}\
extern "C" __declspec(dllexport) unsigned int ISXDK_Version = ISXDK_VERSION; \
extern "C" __declspec(dllexport) unsigned int LGUI_Version = LGUI_VERSION;

#define ISXVariables(_name_,_class_) \
	char ActualModulePath[MAX_PATH] = { 0 }; \
	char ModulePath[MAX_PATH] = { 0 }; \
	char PluginLog[MAX_PATH] = { 0 }; \
	char INIFileName[MAX_PATH] = { 0 }; \
	char XMLFileName[MAX_PATH] = { 0 }; \
	const char *ModuleFileName = 0; \
	_class_ *pExtension = 0; \
	HMODULE g_hModule = 0;

#define ISXPreSetup(_name_,_class_) \
	ISXVariables(_name_, _class_) \
	ISXDllMain(_name_, _class_); \
	ISXExports(_name_, _class_); \
	ISXDKDependencies(_name_, _class_);

#pragma warning(pop)
#pragma pack(pop)
