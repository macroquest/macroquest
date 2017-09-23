#pragma once
#pragma warning( push )
#pragma warning( disable : 4505 )
#ifndef __LSTYPE_H__
#define __LSTYPE_H__
#define TypeMember(name) AddMember((DWORD)name,""#name)
#define TypeMethod(name) AddMethod((DWORD)name,""#name)
#include <math.h>
#include <map>
#include <string>
using namespace std;

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
            BYTE B;
            BYTE G;
            BYTE R;
            BYTE A;
        };
        DWORD ARGB;
	};
} RGBCOLOR, *PRGBCOLOR;

typedef struct _LSVarPtr
{
	_LSVarPtr()
	{
		Int64 = 0;
	}

	union 
	{
		unsigned __int64 UInt64;
		__int64 Int64;
		double Float64;
		unsigned char Array64[8];
		struct 
		{
			union 
			{
				void *Ptr;
				float Float;
				unsigned int DWord;
				unsigned int *DWordPtr;
				int   Int;
				unsigned char Array[4];
				char *CharPtr;
				wchar_t *WCharPtr;
				__int64 *Int64Ptr;
				double *Float64Ptr;
				const void *ConstPtr;
				const char *ConstCharPtr;
				const wchar_t *ConstWCharPtr;
				RGBCOLOR RGB;
			};
			union {
				unsigned int HighDWord;
				unsigned int HighPart;
			};
		};
	};
} LSOBJECTDATA, *PLSOBJECTDATA, LSVARPTR, *PLSVARPTR;

typedef struct _LSTypeVar
{
	_LSTypeVar()
	{
		Type = 0;
		Int64 = 0;
	}

	__inline LSOBJECTDATA &GetObjectData()
	{
		return *(LSOBJECTDATA*)&Int64;
	}

	__inline void SetObjectData(const LSOBJECTDATA &new_data)
	{
		Int64 = new_data.Int64;
	}

	union {
		class LSTypeDefinition *Type;
		class LSTypeDefinition *ObjectType;
	};
	union {
//		LSOBJECTDATA VarPtr;
//		LSOBJECTDATA ObjectData;
		unsigned __int64 UInt64;
		__int64 Int64;
		double Float64;
		unsigned char Array64[8];
		struct
		{
			union
			{
				void *Ptr;
				float Float;
				unsigned int DWord;
				unsigned int *DWordPtr;
				int   Int;
				unsigned char Array[4];
				char *CharPtr;
				wchar_t *WCharPtr;
				__int64 *Int64Ptr;
				double *Float64Ptr;
				const void *ConstPtr;
				const char *ConstCharPtr;
				const wchar_t *ConstWCharPtr;
				RGBCOLOR RGB;
			};
			union {
				unsigned int HighDWord;
				unsigned int HighPart;
			};
		};
	};
} LSOBJECT, *PLSOBJECT, LSTYPEVAR, *PLSTYPEVAR;

typedef bool(__cdecl *fLSTypeMember)(LSTypeDefinition *pType, LSOBJECTDATA, int argc, char *argv[], LSOBJECT &);
typedef bool(__cdecl *fLSTypeMethod)(LSTypeDefinition *pType, LSOBJECTDATA &, int argc, char *argv[]);
typedef void (__cdecl *fLSGenericEnumCallback)(const char *Name, void *pData);

typedef struct _LSTypeMember
{
	unsigned int ID;
	char *Name;
	union {
		fLSTypeMember MemberCallback;
		fLSTypeMethod MethodCallback;
	};
	_LSTypeMember *pPrev;
	_LSTypeMember *pNext;
} LSTYPEMEMBER, *PLSTYPEMEMBER, LSTYPEMETHOD, *PLSTYPEMETHOD;

typedef struct _Point1f
{
	float X;
} POINT1F, *PPOINT1F;

typedef struct _Point2f : public _Point1f
{
	float Y;
} POINT2F, *PPOINT2F;

typedef struct _Point3f : public _Point2f
{
	float Z;
} POINT3F, *PPOINT3F;

typedef struct _Point1i
{
	int X;
} POINT1I, *PPOINT1I;

typedef struct _Point2i : public _Point1i
{
	int Y;
} POINT2I, *PPOINT2I;

typedef struct _Point3i : public _Point2i
{
	int Z;
} POINT3I, *PPOINT3I;

static inline FLOAT GetDistance3D(_Point3f &P1,_Point3f &P2)
{
    FLOAT dX = P1.X - P2.X;
    FLOAT dY = P1.Y - P2.Y;
    FLOAT dZ = P1.Z - P2.Z;
    return sqrtf(dX*dX + dY*dY + dZ*dZ);
}

static inline FLOAT GetDistance3DNoSqrt(_Point3f &P1,_Point3f &P2)
{
    FLOAT dX = P1.X - P2.X;
    FLOAT dY = P1.Y - P2.Y;
    FLOAT dZ = P1.Z - P2.Z;
    return (dX*dX + dY*dY + dZ*dZ);
}

static inline FLOAT GetDistance2D(_Point2f &P1,_Point2f &P2)
{
    FLOAT dX = P1.X - P2.X;
    FLOAT dY = P1.Y - P2.Y;
    return sqrtf(dX*dX + dY*dY);
}

static inline FLOAT GetDistance2DNoSqrt(_Point2f &P1,_Point2f &P2)
{
    FLOAT dX = P1.X - P2.X;
    FLOAT dY = P1.Y - P2.Y;
    return (dX*dX + dY*dY);
}

static inline FLOAT GetDistance2D(_Point2i &P1,_Point2i &P2)
{
    FLOAT dX = (FLOAT)(P1.X - P2.X);
    FLOAT dY = (FLOAT)(P1.Y - P2.Y);
    return sqrtf(dX*dX + dY*dY);
}

static inline FLOAT GetDistance2DNoSqrt(_Point2i &P1,_Point2i &P2)
{
    FLOAT dX = (FLOAT)(P1.X - P2.X);
    FLOAT dY = (FLOAT)(P1.Y - P2.Y);
    return (dX*dX + dY*dY);
}

static bool DistancePointLine(POINT2F &Point,POINT2F &SegmentStart,POINT2F &SegmentEnd,float &Result)
{
    float SegmentLength= GetDistance2D(SegmentStart,SegmentEnd);
    float U= (((Point.X-SegmentStart.X) * (SegmentEnd.X-SegmentStart.X))+
			   ((Point.Y-SegmentStart.Y) * (SegmentEnd.Y-SegmentStart.Y)))/
				(SegmentLength*SegmentLength);
    if (U<0.0f || U>1.0f)
	{
		// no intersection
        return false; 
	}
	// calculate intersection point
	POINT2F Intersection;
    Intersection.X = SegmentStart.X + U * ( SegmentEnd.X - SegmentStart.X );
    Intersection.Y = SegmentStart.Y + U * ( SegmentEnd.Y - SegmentStart.Y );
	// and now the distance from the point to the start of the segment
    Result = GetDistance2D( Point, Intersection );
    return true;
}

extern void RegisterTemporaryObject(class CTempObject *);

class CTempObject
{
public:
	CTempObject()
	{
		RegisterTemporaryObject(this);
	}
	virtual ~CTempObject()
	{
	}
	virtual void Delete()
	{
		delete this;
	}
};

template<typename T>
class CTemporaryObject : public CTempObject
{
public:
	T Object;
};

class LSBinary
{
public:
	LSBinary(size_t InitialSize = 64);
	LSBinary(void *buf, size_t buflen);
	~LSBinary();

	bool Copy(void *buf, size_t buflen);
	size_t Resize(size_t NewSize);
	bool Reset(unsigned char Value);
	bool Reset(unsigned int Begin, size_t Length, unsigned char Value);
	bool Copy(unsigned int Begin, void *buf, size_t buflen);

	inline void *GetBuffer()
	{
		return pBuffer;
	}
	inline size_t GetSize() { return Size; }
	inline size_t GetUsed() { return Used; }

	inline void SetUsed(size_t NewUsed) { Used = NewUsed; }

protected:
	void *pBuffer;
	size_t Size;
	size_t Used;
};

#define INHERITDIRECT(_inherit_) \
	virtual int GetInheritedMember(LSOBJECTDATA ObjectData, char *Member, int argc, char *argv[], LSOBJECT &Dest)\
	{\
		return _inherit_->GetMemberEx(ObjectData,Member,argc,argv,Dest);\
	}\
	virtual int GetInheritedMethod(LSOBJECTDATA &ObjectData, char *Method, int argc, char *argv[])\
	{\
		return _inherit_->GetMethodEx(ObjectData,Method,argc,argv);\
	}\
	virtual int GetInheritedIndex(LSOBJECTDATA &ObjectData, int argc, char *argv[], LSOBJECT &Dest)\
	{\
		return _inherit_->GetIndex(ObjectData,argc,argv,Dest);\
	}

#define INHERITINDIRECT(_inherit_,_convertto_,_convertfrom_) \
	virtual int GetInheritedMember(LSOBJECTDATA ObjectData, char *Member, int argc, char *argv[], LSOBJECT &Dest)\
	{\
		LSOBJECTDATA Temp;\
		_convertto_;\
		return _inherit_->GetMemberEx(Temp,Member,argc,argv,Dest);\
	}\
	virtual int GetInheritedIndex(LSOBJECTDATA ObjectData, int argc, char *argv[], LSOBJECT &Dest)\
	{\
		LSOBJECTDATA Temp;\
		_convertto_;\
		return _inherit_->GetIndex(Temp,argc,argv,Dest);\
	}\
	virtual int GetInheritedMethod(LSOBJECTDATA &ObjectData, char *Method, int argc, char *argv[])\
	{\
		LSOBJECTDATA Temp;\
		_convertto_;\
		int Ret=_inherit_->GetMethodEx(Temp,Method,argc,argv);\
		if (Ret>0)\
		{\
			_convertfrom_;\
		}\
		return Ret;\
	}

class LSTypeDefinition
{
public:
	LSTypeDefinition(char *NewName);

	inline void InitializeMembers(PLSTYPEMEMBER MemberArray)
	{
		for (unsigned int i = 0 ; MemberArray[i].ID ; i++)
		{
			AddMember(MemberArray[i].ID,MemberArray[i].Name);
		}
	}

	virtual ~LSTypeDefinition();

	virtual bool __declspec(deprecated) FromString(LSOBJECTDATA &ObjectData, char *Source)  {return false;}

	virtual bool FromText(LSOBJECTDATA &ObjectData, int argc, char *argv[]);// calls the other FromText by default.

	virtual bool FromText(LSOBJECTDATA &ObjectData, char *Source) 
	{
#pragma warning( push )
#pragma warning( disable : 4996 )
		return FromString(ObjectData,Source);
#pragma warning( pop )
	}

	virtual void InitVariable(LSOBJECTDATA &ObjectData) {ObjectData.Int64=0;}
	virtual bool InitVariable(LSOBJECTDATA &ObjectData, const char *SubType) {if (SubType && SubType[0]) return false; InitVariable(ObjectData); return true;}

	virtual void FreeVariable(LSOBJECTDATA &ObjectData) {}

	virtual bool __declspec(deprecated) GetMember(LSOBJECTDATA ObjectData, char *Member, int argc, char *argv[], LSOBJECT &Dest)
	{
		return false;
	}
	virtual bool __declspec(deprecated) GetMethod(LSOBJECTDATA &ObjectData, char *Method, int argc, char *argv[])
	{
		return false;
	}

	virtual bool GetMember(LSOBJECTDATA ObjectData, PLSTYPEMEMBER pMember, int argc, char *argv[], LSOBJECT &Dest)
	{
#pragma warning( push )
#pragma warning( disable : 4996 )
		return GetMember(ObjectData,pMember->Name,argc,argv,Dest);
#pragma warning( pop )
	}
	virtual bool GetMethod(LSOBJECTDATA &ObjectData, PLSTYPEMETHOD pMethod, int argc, char *argv[])
	{
#pragma warning( push )
#pragma warning( disable : 4996 )
		return GetMethod(ObjectData,pMethod->Name,argc,argv);
#pragma warning( pop )
	}

	virtual int GetIndex(LSOBJECTDATA ObjectData, int argc, char *argv[], LSOBJECT &Dest)
	{
		return GetInheritedIndex(ObjectData,argc,argv,Dest);
/*		// SAMPLE
		// This will let the index automatically access a member called GetIndex
		return GetMemberEx(ObjectData,"GetIndex",argc,argv,Dest);
/**/

	}

	virtual int GetMemberEx(LSOBJECTDATA ObjectData, char *Member, int argc, char *argv[], LSOBJECT &Dest);
	virtual int GetMethodEx(LSOBJECTDATA &ObjectData, char *Method, int argc, char *argv[]);

	virtual int GetInheritedIndex(LSOBJECTDATA ObjectData, int argc, char *argv[], LSOBJECT &Dest)
	{
		return -1;
/*		// SAMPLE
		// convert ObjectData to inherited type
		ObjectData.Ptr=((string*)ObjectData.Ptr)->c_str();
		// try inherited type
		return pStringType->GetIndex(ObjectData,argc,argv,Dest);
/**/
	}


	virtual int GetInheritedMember(LSOBJECTDATA ObjectData, char *Member, int argc, char *argv[], LSOBJECT &Dest)
	{
		return -1;	
/*		// SAMPLE
		// convert ObjectData to inherited type
		ObjectData.Ptr=((string*)ObjectData.Ptr)->c_str();
		// try inherited type
		return pStringType->GetMemberEx(ObjectData,Member,argc,argv,Dest);
/**/
	}
	virtual int GetInheritedMethod(LSOBJECTDATA &ObjectData, char *Method, int argc, char *argv[])
	{
		return -1;
/*		
		// SAMPLE: Direct conversion
		return pStringType->GetMethodEx(ObjectData,argc,argv);

		// SAMPLE: Special conversion required
		// make temporary ObjectData for inherited type
		LSOBJECTDATA Temp;
		Temp.Ptr=((string*)ObjectData.Ptr)->c_str();
		// try inherited type
		int Ret=pStringType->GetMethodEx(Temp,Method,argc,argv);
		if (Ret>0)
		{
			// string changed, replace old string
			((string*)ObjectData.Ptr)->assign(Temp.CharPtr);
		}
		return Ret;
/**/
	}


	virtual bool ToText(LSOBJECTDATA ObjectData, char *buf, unsigned int buflen)
	{
#pragma warning( push )
#pragma warning( disable : 4996 )
		return ToText(ObjectData,buf);
#pragma warning( pop )
	}


	virtual bool __declspec(deprecated) ToText(LSOBJECTDATA ObjectData, char *Destination)
	{
#pragma warning( push )
#pragma warning( disable : 4996 )
		return ToString(ObjectData,Destination);
#pragma warning( pop )
	}

	virtual bool __declspec(deprecated) ToString(LSOBJECTDATA ObjectData, char *Destination)
	{
		return false;
	}

	inline char *GetName() {return &TypeName[0];}
	inline LSTypeDefinition *GetInheritance() {return pInherits;}

	char *GetMemberName(unsigned int ID);
	bool GetMemberID(char *Name, unsigned int &Result);
	PLSTYPEMEMBER FindMember(char *Name);
	virtual bool InheritedMember(char *Name);

	char *GetMethodName(unsigned int ID);
	bool GetMethodID(char *Name, unsigned int &Result);
	PLSTYPEMETHOD FindMethod(char *Name);
	virtual bool InheritedMethod(char *Name);

	virtual LSTypeDefinition *GetVariableType()
	{
		return this;
	}

	void SetInheritance(LSTypeDefinition *pNewInherit);

	unsigned int RegisterVariable(struct _LSTypeVariable *);
	inline struct _LSTypeVariable *GetVariableByID(unsigned int ID)
	{
		map<unsigned int,struct _LSTypeVariable *>::iterator i=Variables.find(ID);
		if (i!=Variables.end())
			return i->second;
		return 0;
	}
	void UnregisterVariable(unsigned int ID);

	virtual bool AddMember(unsigned int ID, char *Name, fLSTypeMember Callback=0);
	virtual bool AddMember(char *Name, fLSTypeMember Callback=0);
	virtual bool RemoveMember(char *Name, fLSTypeMember Callback=0);

	virtual bool AddMethod(unsigned int ID, char *Name, fLSTypeMethod Callback=0);
	virtual bool AddMethod(char *Name, fLSTypeMethod Callback=0);
	virtual bool RemoveMethod(char *Name, fLSTypeMethod Callback=0);

	unsigned int EnumMembers(fLSGenericEnumCallback Callback, void *pData);
	unsigned int EnumMethods(fLSGenericEnumCallback Callback, void *pData);

protected:
	char TypeName[32];
	CIndex<PLSTYPEMEMBER> Members;
	map<string,unsigned int> MemberMap;
	CIndex<PLSTYPEMETHOD> Methods;
	map<string,unsigned int> MethodMap;
	LSTypeDefinition *pInherits;

	unsigned int NextMethodID;
	unsigned int NextMemberID;

	unsigned int NextVariableID;
	map<unsigned int,struct _LSTypeVariable *> Variables;
	bool bShutdown;
};

class CLSObject : public LSOBJECT
{
public:
	CLSObject()
	{
		Int64=0;
		Type=0;
	}
	~CLSObject()
	{
		Reset();
	}
	inline void Reset()
	{
		if (Type)
		{
			Type->FreeVariable(GetObjectData());
			Type=0;
		}
	}
	bool Initialize(LSTypeDefinition *pType, const char *SubType, int argc=0, char *argv[]=0)
	{
		if (Type)
			Reset();
		if (!pType)
			return false;
		pType=pType->GetVariableType();
		if (!pType)
			return false;
		if (!pType->InitVariable(GetObjectData(), SubType))
			return false;
		if (!pType->FromText(GetObjectData(), argc, argv))
		{
			pType->FreeVariable(GetObjectData());
			return false;
		}
		Type=pType;
		return true;
	}
};


#define LSType LSTypeDefinition
#endif
#pragma warning( pop )
