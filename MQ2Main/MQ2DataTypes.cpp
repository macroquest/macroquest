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

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"
#pragma comment(lib, "version.lib")

#ifdef ISXEQ
#define ISINDEX() (argc>0)
#define ISNUMBER() (IsNumber(argv[0]))
#define GETNUMBER() (atoi(argv[0]))
#define GETFIRST()    argv[0]
#else
#define ISINDEX() (Index[0])
#define ISNUMBER() (IsNumber(Index))
#define GETNUMBER() (atoi(Index))
#define GETFIRST() Index
#endif


// Datatype Definitions.
#define DATATYPE(_class_, _var_, _inherits_, _persistentclass_) \
	class _class_ *_var_ = 0;
#include "DataTypeList.h"
#undef DATATYPE


#ifndef ISXEQ

void InitializeMQ2DataTypes()
{
#define DATATYPE(_class_, _var_, _inherits_, _persistentclass_) \
    _var_ = new _class_; \
    if (_inherits_ != nullptr) \
    { \
        _var_->SetInheritance(_inherits_); \
    }
#include "DataTypeList.h"
#undef DATATYPE
}

void ShutdownMQ2DataTypes()
{
#define DATATYPE(_class_, _var_, _inherits_, _persistentclass_) \
	delete _var_;
#include "DataTypeList.h"
#undef DATATYPE
}

bool MQ2TypeType::GETMEMBER()
{
#define pType ((MQ2Type*)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2TypeType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((TypeMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp, pType->GetName());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case TypeMember:
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				// name by number
				if (Dest.Ptr = pType->GetMemberName(GETNUMBER()))
				{
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				// number by name
				if (pType->GetMemberID(Index, Dest.DWord))
				{
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}
	return false;
#undef pType
}

bool MQ2PluginType::GETMEMBER()
{
#define pPlugin ((PMQPLUGIN)VarPtr.Ptr)
	if (!pPlugin)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2PluginType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((PluginMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr = pPlugin->szFilename;
		Dest.Type = pStringType;
		return true;
	case Version:
		Dest.Float = pPlugin->fpVersion;
		Dest.Type = pFloatType;
		return true;
	}
	return false;
#undef pPlugin
}
bool MQ2FloatType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2FloatType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	switch ((FloatMembers)pMember->ID)
	{
	case Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Float);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Float);
		return true;
	case Precision:
		Dest.Type = pStringType;
		if (ISNUMBER())
		{
			sprintf_s(DataTypeTemp, "%.*f", GETNUMBER(), VarPtr.Float);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Raw:
		Dest.Type = pIntType;
		Dest.DWord = VarPtr.DWord;
		return true;
	case Prettify: {
		int digits = 2;
		if (ISNUMBER())
			digits = GETNUMBER();
		sprintf_s(DataTypeTemp, "%f", VarPtr.Float);
		PrettifyNumber(DataTypeTemp, sizeof(DataTypeTemp), digits);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	}
	return false;
}
bool MQ2DoubleType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2DoubleType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	switch ((DoubleMembers)pMember->ID)
	{
	case Deci:
		sprintf_s(DataTypeTemp, "%.1f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Centi:
		sprintf_s(DataTypeTemp, "%.2f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Milli:
		sprintf_s(DataTypeTemp, "%.3f", VarPtr.Double);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Int:
		Dest.Type = pIntType;
		Dest.Int = (int)(VarPtr.Double);
		return true;
	case Precision:
		Dest.Type = pStringType;
		if (ISNUMBER())
		{
			sprintf_s(DataTypeTemp, "%.*f", GETNUMBER(), VarPtr.Double);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Prettify: {
		int digits = 2;
		if (ISNUMBER())
			digits = GETNUMBER();
		sprintf_s(DataTypeTemp, "%f", VarPtr.Float);
		PrettifyNumber(DataTypeTemp, sizeof(DataTypeTemp), digits);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	}
	return false;
}

bool MQ2IntType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2IntType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	switch ((IntMembers)pMember->ID)
	{
	case Float:
		Dest.Float = (FLOAT)1.0f*(VarPtr.Int);
		Dest.Type = pFloatType;
		return true;
	case Double:
		Dest.Double = (DOUBLE)1.0f*(VarPtr.Int);
		Dest.Type = pDoubleType;
		return true;
	case Hex:
		sprintf_s(DataTypeTemp, "0x%X", VarPtr.Int);
		Dest.Ptr = &DataTypeTemp[0],
		Dest.Type = pStringType;
		return true;
	case Reverse:
	{
		Dest.Array[0] = VarPtr.Array[3];
		Dest.Array[1] = VarPtr.Array[2];
		Dest.Array[2] = VarPtr.Array[1];
		Dest.Array[3] = VarPtr.Array[0];
		Dest.Type = pIntType;
		return true;
	}
	case LowPart:
		Dest.DWord = LOWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;
	case HighPart:
		Dest.DWord = HIWORD(VarPtr.DWord);
		Dest.Type = pIntType;
		return true;
	case Prettify: {
		int digits = 0;
		if (ISNUMBER())
			digits = GETNUMBER();
		sprintf_s(DataTypeTemp, "%d", VarPtr.Int);
		PrettifyNumber(DataTypeTemp, sizeof(DataTypeTemp), digits);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	}

	return false;
}
bool MQ2Int64Type::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2Int64Type::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	switch ((Int64Members)pMember->ID)
	{
	case Float:
		Dest.Float = (FLOAT)1.0f*(VarPtr.Int64);
		Dest.Type = pFloatType;
		return true;
	case Double:
		Dest.Double = (DOUBLE)1.0f*(VarPtr.Int64);
		Dest.Type = pDoubleType;
		return true;
	case Hex:
		sprintf_s(DataTypeTemp, "0x%llX", VarPtr.Int64);
		Dest.Ptr = &DataTypeTemp[0],
		Dest.Type = pStringType;
		return true;
	case Reverse:
		Dest.FullArray[0] = VarPtr.FullArray[7];
		Dest.FullArray[1] = VarPtr.FullArray[6];
		Dest.FullArray[2] = VarPtr.FullArray[5];
		Dest.FullArray[3] = VarPtr.FullArray[4];
		Dest.FullArray[4] = VarPtr.FullArray[3];
		Dest.FullArray[5] = VarPtr.FullArray[2];
		Dest.FullArray[6] = VarPtr.FullArray[1];
		Dest.FullArray[7] = VarPtr.FullArray[0];
		Dest.Type = pInt64Type;
		return true;
	case LowPart:
		Dest.DWord = LODWORD(VarPtr.UInt64);
		Dest.Type = pIntType;
		return true;
	case HighPart:
		Dest.DWord = HIDWORD(VarPtr.UInt64);
		Dest.Type = pIntType;
		return true;
	case Prettify: {
		int digits = 0;
		if (ISNUMBER())
			digits = GETNUMBER();
		sprintf_s(DataTypeTemp, "%lld", VarPtr.Int64);
		PrettifyNumber(DataTypeTemp, sizeof(DataTypeTemp), digits);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	}
	return false;
}

bool MQ2StringType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2StringType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	switch ((StringMembers)pMember->ID)
	{
	case Length:
		Dest.DWord = strlen((const char *)VarPtr.Ptr);
		Dest.Type = pIntType;
		return true;
	case Left:
		Dest.Type = pStringType;
		if (!ISINDEX())
			return false;
		{
			int Len = GETNUMBER();
			if (Len == 0)
				return false;
			if (Len > MAX_STRING)
				Len = MAX_STRING;
			if (Len>0)
			{
				unsigned long StrLen = strlen((char *)VarPtr.Ptr);
				if ((unsigned long)Len>StrLen)
					Len = StrLen;
				memmove(DataTypeTemp, (char *)VarPtr.Ptr, Len);
				DataTypeTemp[Len] = 0;
				Dest.Ptr = &DataTypeTemp[0];
			}
			else
			{
				Len = -Len;
				unsigned long StrLen = strlen((char *)VarPtr.Ptr);
				if ((unsigned long)Len >= StrLen)
				{
					strcpy_s(DataTypeTemp, "");
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				memmove(DataTypeTemp, (char *)VarPtr.Ptr, StrLen - Len);
				DataTypeTemp[StrLen - Len] = 0;
				Dest.Ptr = &DataTypeTemp[0];
			}
		}
		return true;
	case Right:
		Dest.Type = pStringType;
		if (!ISINDEX())
			return false;
		{
			int Len = GETNUMBER();
			if (Len == 0)
				return false;
			if (Len<0)
			{
				Len = -Len;
				unsigned long StrLen = strlen((char *)VarPtr.Ptr);
				if ((unsigned long)Len >= StrLen)
				{
					strcpy_s(DataTypeTemp, "");
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
				char *pStart = (char*)VarPtr.Ptr;
				pStart = &pStart[Len];
				Len = StrLen - Len;
				memmove(DataTypeTemp, pStart, Len + 1);
				Dest.Ptr = &DataTypeTemp[0];
			}
			else
			{
				char *pStart = (char*)VarPtr.Ptr;
				pStart = &pStart[strlen(pStart) - Len];
				if (pStart<VarPtr.Ptr)
					pStart = (char*)VarPtr.Ptr;
				memmove(DataTypeTemp, pStart, Len + 1);
				Dest.Ptr = &DataTypeTemp[0];
			}
		}
		return true;
	case Find:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		{
			char A[MAX_STRING] = { 0 };
			char B[MAX_STRING] = { 0 };
			strcpy_s(A, (char*)VarPtr.Ptr);
			strcpy_s(B, (char*)Index);
			_strlwr_s(A);
			_strlwr_s(B);
			if (char *pFound = strstr(A, B))
			{
				Dest.DWord = (pFound - &A[0]) + 1;
				return true;
			}
		}
		return false;
	case Replace:
	{
		Dest.Type = pStringType;
		if (!ISINDEX())
			return false;
		if (PCHAR pComma = strchr(Index, ','))
		{
			std::string subject = (char*)VarPtr.Ptr;
			*pComma = 0;
			const std::string search = (char*)Index;
			*pComma = ',';
			const std::string replace = (char*)&pComma[1];
			if (!subject.size() || !search.size())
				return false;
			size_t pos = 0;
			while((pos = subject.find(search, pos)) != std::string::npos) {
				 subject.replace(pos, search.length(), replace);
				 pos += replace.length();
			}
			strcpy_s(DataTypeTemp,subject.c_str());
			if (Dest.Ptr = DataTypeTemp)
			{
				return true;
			}
		}
		return false;
	}
	case Upper:
		strcpy_s(DataTypeTemp, (char*)VarPtr.Ptr);
		_strupr_s(DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Lower:
		strcpy_s(DataTypeTemp, (char*)VarPtr.Ptr);
		_strlwr_s(DataTypeTemp);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Compare:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			Dest.Int = _stricmp((char*)VarPtr.Ptr, Index);
			return true;
		}
		return false;
	case CompareCS:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			Dest.Int = strcmp((char*)VarPtr.Ptr, Index);
			return true;
		}
		return false;
	case Mid:
		Dest.Type = pStringType;
		if (PCHAR pComma = strchr(Index, ','))
		{
			*pComma = 0;
			pComma++;
			PCHAR pStr = (char *)VarPtr.Ptr;
			int nStart = GETNUMBER() - 1;
			DWORD Len = atoi(pComma);//dont change this to an int we want them to be able to specify max len as -1
			if ((size_t)nStart >= strlen(pStr))
			{
				strcpy_s(DataTypeTemp, "");
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
			pStr += nStart;
			DWORD StrLen = (DWORD)strlen(pStr);
			if (Len>StrLen)
				Len = StrLen;
			memmove(DataTypeTemp, pStr, Len);
			DataTypeTemp[Len] = 0;
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Equal:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			Dest.DWord = (_stricmp((char*)VarPtr.Ptr, Index) == 0);
			return true;
		}
		return false;
	case NotEqual:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			Dest.DWord = (_stricmp((char*)VarPtr.Ptr, Index) != 0);
			return true;
		}
		return false;
	case EqualCS:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			Dest.DWord = (strcmp((char*)VarPtr.Ptr, Index) == 0);
			return true;
		}
		return false;
	case NotEqualCS:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			Dest.DWord = (strcmp((char*)VarPtr.Ptr, Index) != 0);
			return true;
		}
		return false;
	case Count:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			Dest.DWord = 0;
			PCHAR pLast = (PCHAR)VarPtr.Ptr - 1;
			while (pLast = strchr(&pLast[1], Index[0]))
				Dest.DWord++;
			return true;
		}
		return false;
	case Arg:
		Dest.Type = pStringType;
		if (IsNumberToComma(Index))
		{
			CHAR Temp[MAX_STRING] = { 0 };
			strcpy_s(Temp, (char *)VarPtr.Ptr);
			if (PCHAR pComma = strchr(Index, ','))
			{
				*pComma = 0;
				GetArg(DataTypeTemp, Temp, GETNUMBER(), FALSE, FALSE, FALSE, pComma[1]);
				*pComma = ',';
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
			else
			{
				GetArg(DataTypeTemp, Temp, GETNUMBER());
				if (DataTypeTemp[0])
				{
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	case Token:
		Dest.Type = pStringType;
		if (IsNumberToComma(Index))
		{
			DWORD N = GETNUMBER();
			if (!N)
				return false;
			//CHAR Temp[MAX_STRING]={0};
			//strcpy_s(Temp,(char *)VarPtr.Ptr);
			if (PCHAR pComma = strchr(Index, ','))
			{
				*pComma = 0;
				PCHAR pPos = (PCHAR)VarPtr.Ptr;//strchr((char *)VarPtr.Ptr,pComma[1]);
				N--;
				while (N && pPos)
				{
					pPos = strchr(&pPos[1], pComma[1]);
					N--;
				}
				*pComma = ',';
				if (pPos)
				{
					if (pPos != (PCHAR)VarPtr.Ptr)
						pPos++;
					PCHAR pEnd = strchr(&pPos[0], pComma[1]);
					if (pEnd)
					{
						if (pEnd != pPos)
						{
							strncpy_s(DataTypeTemp, pPos, pEnd - pPos);
							DataTypeTemp[pEnd - pPos] = 0;
						}
						else
							DataTypeTemp[0] = 0;
					}
					else
						strcpy_s(DataTypeTemp, pPos);
					// allows empty returned strings
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
bool MQ2ArrayType::GETMEMBER()
{
#define pArray ((CDataArray*)VarPtr.Ptr)
	if (!pArray)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2ArrayType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((ArrayMembers)pMember->ID)
	{
	case Dimensions:
		Dest.DWord = pArray->nExtents;
		Dest.Type = pIntType;
		return true;
	case Size:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			int N = GETNUMBER() - 1;
			if (N<0)
				return false;
			if ((DWORD)N<pArray->nExtents)
			{
				Dest.DWord = pArray->pExtents[N];
				return true;
			}
		}
		else
		{
			Dest.DWord = pArray->TotalElements;
			return true;
		}
		return false;
	}
	return false;
#undef pArray
}
bool MQ2MathType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2MathType::FindMember(Member);
	if (!pMember)
		return false;

	if (!ISINDEX())
		return false;
	DOUBLE CalcResult;
	switch ((MathMembers)pMember->ID)
	{
	case Abs:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (FLOAT)CalcResult;
			if (Dest.Float<0)
				Dest.Float *= -1;
			return true;
		}
		return false;
	case Rand:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (char*Arg = GETFIRST()) {
			CHAR szMin[MAX_STRING] = { 0 };
			CHAR szMax[MAX_STRING] = { 0 };
			int Min = 0;
			int Max = 0;
			if (char*pDest = strchr(Arg, ',')) {
				pDest[0] = '\0';
				Min = atol(Arg);
				pDest++;
				Max = atol(pDest);
			}
			else {
				Max = atol(Arg);
			}
			if (Max == 0 || Max > RAND_MAX)
				return false;
			Dest.DWord = RangeRandom(Min, Max);
			return true;
		}
		return false;
	case Sqrt:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (FLOAT)sqrt(CalcResult);
			return true;
		}
		return false;
	case Calc:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (FLOAT)CalcResult;
			return true;
		}
		return false;
	case Sin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)sin(CalcResult / DegToRad);
			return true;
		}
		return false;
	case Cos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)cos(CalcResult / DegToRad);
			return true;
		}
		return false;
	case Tan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)tan(CalcResult / DegToRad);
			return true;
		}
		return false;
	case Asin:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(asin(CalcResult)*DegToRad);
			return true;
		}
		return false;
	case Acos:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(acos(CalcResult)*DegToRad);
			return true;
		}
		return false;
	case Atan:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (Calculate(Index, CalcResult))
		{
			Dest.Float = (float)(atan(CalcResult)*DegToRad);
			return true;
		}
		return false;
	case Not:
		Dest.DWord = ~atol(Index);
		Dest.Type = pIntType;
		return true;
	case Hex:
		sprintf_s(DataTypeTemp, "0x%X", atol(Index));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Dec:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (sscanf_s(Index, "%x", &Dest.DWord)) {
			return true;
		}
		return false;
    case Clamp:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if( char*Arg = GETFIRST() ) {
            CHAR szMin[MAX_STRING] = { 0 };
            CHAR szN[MAX_STRING] = { 0 };
            CHAR szMax[MAX_STRING] = { 0 };

            GetArg( szN, Arg, 1, 0, 0, 1 );
			GetArg( szMin, Arg, 2, 0, 0, 1);
			GetArg( szMax, Arg, 3, 0, 0, 1 );

            int n = atol( szN );
			int Min = atol(szMin);
			int Max = atol( szMax );

            //WriteChatf( "\Clamp:\ax %s n: %d min: %d max: %d", Arg, n, Min, Max );

            Dest.Int = max( Min, min( n, Max ) );
            return true;
        }
        return false;
	case Distance:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (ISINDEX())
		{
			FLOAT P1[3];
			FLOAT P2[3];
			P1[0] = P2[0] = ((PSPAWNINFO)pCharSpawn)->Y;
			P1[1] = P2[1] = ((PSPAWNINFO)pCharSpawn)->X;
			P1[2] = P2[2] = ((PSPAWNINFO)pCharSpawn)->Z;
			if (PCHAR pColon = strchr(Index, ':'))
			{
				*pColon = 0;
				if (PCHAR pComma = strchr(&pColon[1], ','))
				{
					*pComma = 0;
					P2[0] = (FLOAT)atof(&pColon[1]);
					*pComma = ',';
					if (PCHAR pComma2 = strchr(&pComma[1], ','))
					{
						*pComma2 = 0;
						P2[1] = (FLOAT)atof(&pComma[1]);
						*pComma2 = ',';
						P2[2] = (FLOAT)atof(&pComma2[1]);
					}
					else
					{
						P2[1] = (FLOAT)atof(&pComma[1]);
					}
				}
				else
					P2[0] = (FLOAT)atof(&pColon[1]);
			}


			if (PCHAR pComma = strchr(Index, ','))
			{
				*pComma = 0;
				P1[0] = (FLOAT)atof(Index);
				*pComma = ',';
				if (PCHAR pComma2 = strchr(&pComma[1], ','))
				{
					*pComma2 = 0;
					P1[1] = (FLOAT)atof(&pComma[1]);
					*pComma2 = ',';
					P1[2] = (FLOAT)atof(&pComma2[1]);
				}
				else
				{
					P1[1] = (FLOAT)atof(&pComma[1]);
				}
			}
			else
				P1[0] = (FLOAT)atof(Index);

			//DebugSpewNoFile("GetDistance3D(%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f)", P1[0], P1[1], P1[2], P2[0], P2[1], P2[2]);
			Dest.Float = (FLOAT)GetDistance3D(P1[0], P1[1], P1[2], P2[0], P2[1], P2[2]);
			return true;
		}
		return false;
	}
	return false;
}
bool MQ2MacroType::GETMEMBER()
{
	if (!gMacroStack)
		return false;
	PMQ2TYPEMEMBER pMethod = MQ2MacroType::FindMethod(Member);
	if (pMethod) {
		switch ((MacroMethods)pMethod->ID)
		{
			case Undeclared:
			{
				if (gMacroBlock && !gUndeclaredVars.empty()) {
					WriteChatf("----------- Undeclared Variables (bad) -----------");
					int count = 1;
					for (std::map<std::string, int>::iterator i = gUndeclaredVars.begin(); i != gUndeclaredVars.end(); i++)
					{
						MACROLINE ml = gMacroBlock->Line[i->second];
						WriteChatf("[%d] %s see: %d@%s: %s", count++, i->first.c_str(), ml.LineNumber, ml.SourceFile.c_str(), ml.Command.c_str());
					}
				}
				else {
					WriteChatf("No Undeclared Variables Found. (good)");
				}
				return true;
			}
			default:
				return false;
		}
	}

	PMQ2TYPEMEMBER pMember = MQ2MacroType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((MacroMembers)pMember->ID)
	{
	case Name:
		Dest.Ptr = &gszMacroName[0];
		Dest.Type = pStringType;
		return true;
	case RunTime:
		Dest.UInt64 = ((MQGetTickCount64() - gRunning) / 1000);
		Dest.Type = pInt64Type;
		return true;
	case Paused:
	{
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (PMACROBLOCK pBlock = GetCurrentMacroBlock())
		{
			Dest.DWord = pBlock->Paused;
		}
		return true;
	}
	case Return:
		Dest.Ptr = &DataTypeTemp[0];
		strcpy_s(DataTypeTemp, gMacroStack->Return);
		Dest.Type = pStringType;
		return true;
	case IsTLO:
	{
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (FindMQ2Data(GETFIRST()))
			Dest.DWord = 1;
		return true;
	}
	case IsOuterVariable:
	{
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VariableMap.find(GETFIRST()) != VariableMap.end())
			Dest.DWord = 1;
		return true;
	}
	case StackSize:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		PMACROSTACK pStack = gMacroStack;
		while (pStack) {
			Dest.DWord++;
			pStack = pStack->pNext;
		}
		return true;
	}
	case Params:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		{
			PDATAVAR pVar = gMacroStack->Parameters;
			while (pVar)
			{
				Dest.DWord++;
				pVar = pVar->pNext;
			}
		}
		return true;
		/*
		TypeMember(Param);
		/**/
	case CurLine:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (gMacroBlock) {
			Dest.DWord = gMacroBlock->Line[gMacroBlock->CurrIndex].LineNumber;
			return true;
		}
		break;
	case CurSub:
        if (gMacroBlock) {
			if (PMACROSTACK pMS = gMacroStack)
			{
				GetSubFromLine(pMS->LocationIndex, DataTypeTemp, MAX_STRING);
				Dest.Ptr = DataTypeTemp;
				Dest.Type = pStringType;
				return true;
			}
		}
        return false;
	case CurCommand:
		Dest.Type = pStringType;
		if (gMacroBlock) {
			sprintf_s(DataTypeTemp, "%d@%s -> %s", gMacroBlock->Line[gMacroStack->LocationIndex].LineNumber, gMacroBlock->Line[gMacroStack->LocationIndex].SourceFile.c_str(), gMacroBlock->Line[gMacroStack->LocationIndex].Command.c_str());
			std::string str1 = DataTypeTemp;
			replace(str1.begin(), str1.end(), '$', '#');
			strcpy_s(DataTypeTemp, str1.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		break;
	case FindVariable:
		if (!ISINDEX())
			return false;
		if (PCHAR pIndex = GETFIRST())
		{
			bool bExact = false;
			if (*pIndex == '=') {
				bExact = true;
				pIndex++;
			}
			Dest.Type = pStringType;
			if (PDATAVAR DataVar = FindMQ2DataVariable(pIndex, bExact))
			{
				strcpy_s(DataTypeTemp, DataVar->szName);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		break;
	case MemUse:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		{
			int size = 0;
			if (gMacroStack) {
				PMACROSTACK pStack = gMacroStack;
				while (pStack) {
					size += sizeof(pStack);
					pStack = pStack->pNext;
				}
			}
			if (gMacroBlock) {
				PMACROBLOCK pBlock = gMacroBlock;
				size += sizeof(pBlock);
			}
			if (gEventQueue) {
				PEVENTQUEUE pQueue = gEventQueue;
				while (pQueue) {
					size += sizeof(pQueue);
					pQueue = pQueue->pNext;
				}
			}
			Dest.DWord = size;
			return true;
		}
	}
	return false;
}

#endif

bool MQ2TicksType::GETMEMBER()
{
	//if (!VarPtr.DWord)
	//	return false;
	//DWORD TSeconds = VarPtr.DWord / 1000 / 6;
#define nTicks (VarPtr.DWord)
	PMQ2TYPEMEMBER pMember = FindMember(Member);
	if (!pMember)
		return false;
	switch ((TicksMembers)pMember->ID)
	{
	case Hours:
		Dest.DWord = nTicks / 600;
		Dest.Type = pIntType;
		return true;
	case Minutes:
		Dest.DWord = (nTicks / 10) % 60;
		Dest.Type = pIntType;
		return true;
	case Seconds:
		Dest.DWord = (nTicks * 6) % 60;
		Dest.Type = pIntType;
		return true;
	case TimeHMS:
	{
		Dest.Type = pStringType;
		int Secs = nTicks * 6;
		int Mins = (Secs / 60) % 60;
		int Hrs = (Secs / 3600);
		Secs = Secs % 60;
		if (Secs<0)
			sprintf_s(DataTypeTemp, "Perm");
		else if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02d:%02d", Hrs, Mins, Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02d", Mins, Secs);
		Dest.Ptr = &DataTypeTemp[0];
	}
	return true;
	case Time:
	{
		Dest.Type = pStringType;
		int Secs = nTicks * 6;
		int Mins = (Secs / 60);
		Secs = Secs % 60;
		if (Secs<0)
			sprintf_s(DataTypeTemp, "Perm");
		else
			sprintf_s(DataTypeTemp, "%d:%02d", Mins, Secs);
		Dest.Ptr = &DataTypeTemp[0];
	}
	return true;
	case TotalMinutes:
		Dest.DWord = nTicks / 10;
		Dest.Type = pIntType;
		return true;
	case TotalSeconds:
		Dest.DWord = nTicks * 6;
		Dest.Type = pIntType;
		return true;
	case Ticks:
		Dest.DWord = nTicks;
		Dest.Type = pIntType;
		return true;
	}
	return false;
#undef nTicks
}

bool MQ2TimeStampType::GETMEMBER()
{
#define nTimeStamp (VarPtr.UInt64)
	PMQ2TYPEMEMBER pMember = FindMember(Member);
	if (!pMember)
		return false;
	switch ((TimeStampMembers)pMember->ID)
	{
	case Hours:
		Dest.UInt64 = (nTimeStamp / 1000) / 3600;
		Dest.Type = pInt64Type;
		return true;
	case Minutes:
		Dest.UInt64 = ((nTimeStamp / 1000) / 60) % 60;
		Dest.Type = pInt64Type;
		return true;
	case Seconds:
		Dest.UInt64 = (nTimeStamp / 1000) % 60;
		Dest.Type = pInt64Type;
		return true;
	case TimeHMS:
	{
		Dest.Type = pStringType;
		ULONGLONG Secs = nTimeStamp / 1000;
		ULONGLONG Mins = (Secs / 60) % 60;
		ULONGLONG Hrs = (Secs / 3600);
		Secs = Secs % 60;
		if (Secs<0)
			sprintf_s(DataTypeTemp, "Perm");
		else if (Hrs)
			sprintf_s(DataTypeTemp, "%d:%02u:%02u", (unsigned int)Hrs, (unsigned int)Mins, (unsigned int)Secs);
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
		Dest.Ptr = &DataTypeTemp[0];
	}
	return true;
	case Time:
	{
		Dest.Type = pStringType;
		ULONGLONG Secs = nTimeStamp / 1000;
		ULONGLONG Mins = Secs / 60;
		Secs = Secs % 60;
		if (Secs < 0)
			sprintf_s(DataTypeTemp, "Perm");
		else
			sprintf_s(DataTypeTemp, "%d:%02u", (unsigned int)Mins, (unsigned int)Secs);
		Dest.Ptr = &DataTypeTemp[0];
	}
	return true;
	case TotalMinutes:
		Dest.UInt64 = (nTimeStamp / 1000) / 60;
		Dest.Type = pInt64Type;
		return true;
	case TotalSeconds:
		Dest.UInt64 = nTimeStamp / 1000;
		Dest.Type = pInt64Type;
		return true;
	case Raw:
		Dest.UInt64 = nTimeStamp;
		Dest.Type = pInt64Type;
		return true;
	case Float:
		Dest.Float = (FLOAT)nTimeStamp / 1000;
		Dest.Type = pFloatType;
		return true;
	case Ticks:
		Dest.UInt64 = ((nTimeStamp / 1000) + 5) / 6;
		Dest.Type = pInt64Type;
		return true;
	}
	return false;
#undef nTimeStamp
}


bool MQ2ArgbType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = FindMember(Member);
	if (!pMember)
		return false;
	switch ((ArgbMembers)pMember->ID)
	{
	case A:
		Dest.DWord = VarPtr.Argb.A;
		Dest.Type = pIntType;
		return true;
	case R:
		Dest.DWord = VarPtr.Argb.R;
		Dest.Type = pIntType;
		return true;
	case G:
		Dest.DWord = VarPtr.Argb.G;
		Dest.Type = pIntType;
		return true;
	case B:
		Dest.DWord = VarPtr.Argb.B;
		Dest.Type = pIntType;
		return true;
	case Int:
		Dest.DWord = VarPtr.DWord;
		Dest.Type = pIntType;
		return true;
	}
	return false;
}

bool MQ2SpawnType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	int sizeofActorClient = sizeof(ActorClient);
	PSPAWNINFO pSpawn = (PSPAWNINFO)VarPtr.Ptr;
#ifndef ISXEQ
	PMQ2TYPEMEMBER pMethod = MQ2SpawnType::FindMethod(Member);
	if (pMethod) {
		switch ((SpawnMethods)pMethod->ID)
		{
		case DoTarget:
			pTarget = (EQPlayer *)pSpawn;
			return true;
		case DoFace:
		{
			CHAR szOut[256] = { 0 };
			sprintf_s(szOut, "id %d", pSpawn->SpawnID);
			Face((PSPAWNINFO)pCharSpawn, szOut);
			return true;
		}
		case LeftClick:
			pEverQuest->LeftClickedOnPlayer((EQPlayer *)pSpawn);
			WeDidStuff();
			return true;
		case RightClick:
			pEverQuest->RightClickedOnPlayer((EQPlayer *)pSpawn, 0);
			WeDidStuff();
			return true;
		case DoAssist:
		{
			CHAR szOut[256] = { 0 };
			sprintf_s(szOut, "%s", pSpawn->DisplayedName);
			AssistCmd((PSPAWNINFO)pCharSpawn, szOut);
			return true;
		}
		default:
			return false;
		}
	}
#endif
	PMQ2TYPEMEMBER pMember = MQ2SpawnType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}
	switch ((SpawnMembers)pMember->ID)
	{
	case Address://This is for debugging purposes/correcting struct on patchday, probably not of any use to the end users.
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case Level:
		Dest.DWord = pSpawn->Level;
		Dest.Type = pIntType;
		return true;
	case ID:
		Dest.Type = pIntType;
		Dest.DWord = pSpawn->SpawnID;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Surname:
		strcpy_s(DataTypeTemp, pSpawn->Lastname);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case CleanName:
		strcpy_s(DataTypeTemp, pSpawn->Name);
		CleanupName(DataTypeTemp, sizeof(DataTypeTemp), FALSE, FALSE);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case DisplayName:
		strcpy_s(DataTypeTemp, pSpawn->DisplayedName);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case E:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->X;
		return true;
	case W:
	case X:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->X;
		return true;
	case S:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Y;
		return true;
	case N:
	case Y:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Y;
		return true;
	case D:
		Dest.Type = pFloatType;
		Dest.Float = -pSpawn->Z;
		return true;
	case U:
	case Z:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->Z;
		return true;
	case FloorZ:
		Dest.Type = pFloatType;
		Dest.Float = pSpawn->FloorHeight;
		return true;
	case Next:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pNext)
		{
			return true;
		}
		return false;
	case Prev:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->pPrev)
		{
			return true;
		}
		return false;
	case CurrentHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPCurrent;
		return true;
	case MaxHPs:
		Dest.Type = pInt64Type;
		Dest.Int64 = pSpawn->HPMax;
		return true;
	case PctHPs:
	{
		Dest.Type = pInt64Type;
		Dest.Int64 = 0;
		//fix for a crash that will occur if HPMax is 0
		//we should not divide something by 0... -eqmule
		__int64 maxhp = pSpawn->HPMax;
		if (maxhp != 0)
			Dest.Int64 = pSpawn->HPCurrent * 100 / maxhp;
		return true;
	}
	case AARank:
		Dest.Type = pIntType;
		Dest.Int = 0;
		if (pSpawn->AARank != 0xFF)
			Dest.Int = pSpawn->AARank;
		return true;
	case Speed:
		Dest.Float = FindSpeed(pSpawn);
		Dest.Type = pFloatType;
		return true;
	case Heading:
		Dest.Float = pSpawn->Heading*0.703125f;
		Dest.Type = pHeadingType;
		return true;
	case Pet:
		Dest.Type = pPetType;
		Dest.Ptr = GetSpawnByID(pSpawn->PetID);
		if (!Dest.Ptr)
		{
			ZeroMemory(&PetSpawn, sizeof(PetSpawn));
			strcpy_s(PetSpawn.Name, "NO PET");
			Dest.Ptr = &PetSpawn;
		}
		return true;
	case Master:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->MasterID))
		{
			return true;
		}
		return false;
	case Gender:
		strcpy_s(DataTypeTemp, szGender[pSpawn->mActorClient.Gender]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Race:
		Dest.DWord = pSpawn->mActorClient.Race;
		Dest.Type = pRaceType;
		return true;
	case Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;
		if (GetSpawnType(pSpawn) != AURA && GetSpawnType(pSpawn) != BANNER && GetSpawnType(pSpawn) != CAMPFIRE)
			Dest.DWord = pSpawn->mActorClient.Class;
		else
			if (GetSpawnType(pSpawn) == AURA)
				Dest.DWord = 0xFF;
			else if (GetSpawnType(pSpawn) == BANNER)
				Dest.DWord = 0xFE;
			else
				Dest.DWord = 0xFD;
		return true;
	case Body:
		Dest.DWord = GetBodyType(pSpawn);
		Dest.Type = pBodyType;
		return true;
	case GM:
		Dest.DWord = pSpawn->GM;
		Dest.Type = pBoolType;
		return true;
	case Levitating:
		Dest.DWord = (pSpawn->mPlayerPhysicsClient.Levitate == 2);
		Dest.Type = pBoolType;
		return true;
	case Sneaking:
		Dest.DWord = pSpawn->Sneak;
		Dest.Type = pBoolType;
		return true;
	case Invis:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX() && pCharData1)
		{
			if (ISNUMBER())
			{
				int type = GETNUMBER();
				switch (type)
				{
				case 0://any
					Dest.DWord = pSpawn->HideMode;
					break;
				case 1://regular/normal
					Dest.DWord = ((CharacterZoneClient*)pCharData1)->CalculateInvisLevel(eAll);
					break;
				case 2://undead
					Dest.DWord = ((CharacterZoneClient*)pCharData1)->CalculateInvisLevel(eUndead);
					break;
				case 3://animal
					Dest.DWord = ((CharacterZoneClient*)pCharData1)->CalculateInvisLevel(eAnimal);
					break;
				case 4://sos
					if (PCHARINFO2 pChar2 = GetCharInfo2())
					{
						int skill = pCharData1->GetAdjustedSkill(29);//HIDE
						int hide = pChar2->bHide;
						if ((hide + pCharData1->TotalEffect(SPA_SHROUD_OF_STEALTH) >= 2) && skill>=100)
						{
							Dest.DWord = 1;
						}
					}
					break;
				};
			}
			else {
				if (!_stricmp(GETFIRST(), "ANY"))
				{
					Dest.DWord = pSpawn->HideMode;
				}
				else if (!_stricmp(GETFIRST(), "NORMAL"))
				{
					Dest.DWord = ((CharacterZoneClient*)pCharData1)->CalculateInvisLevel(eAll);
				}
				else if (!_stricmp(GETFIRST(), "UNDEAD"))
				{
					Dest.DWord = ((CharacterZoneClient*)pCharData1)->CalculateInvisLevel(eUndead);
				}
				else if (!_stricmp(GETFIRST(), "ANIMAL"))
				{
					Dest.DWord = ((CharacterZoneClient*)pCharData1)->CalculateInvisLevel(eAnimal);
				}
				else if (!_stricmp(GETFIRST(), "SOS"))
				{
					if (PCHARINFO2 pChar2 = GetCharInfo2())
					{
						int skill = pCharData1->GetAdjustedSkill(29);//HIDE
						int hide = pChar2->bHide;
						if ((hide + pCharData1->TotalEffect(SPA_SHROUD_OF_STEALTH) >= 2) && skill>=100)
						{
							Dest.DWord = 1;
						}
					}
				}
			}
		}
		else
		{
			Dest.DWord = pSpawn->HideMode;
		}
		return true;
	case Height:
		Dest.Float = pSpawn->AvatarHeight;
		Dest.Type = pFloatType;
		return true;
	case MaxRange:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range((EQPlayer*)pSpawn, (EQPlayer*)pSpawn);
			return true;
		}
		return false;
	case MaxRangeTo:
		Dest.Float = 0.0;
		Dest.Type = pFloatType;
		if (GetSpawnType(pSpawn) != ITEM)
		{
			Dest.Float = get_melee_range(pCharSpawn, (EQPlayer*)pSpawn);
			return true;
		}
		return false;
	case Guild:
		Dest.Type = pStringType;
		if (pSpawn->GuildID != -1 && pSpawn->GuildID != 0)
		{
			char *szGuild = GetGuildByID(pSpawn->GuildID);
			if (szGuild)
			{
				strcpy_s(DataTypeTemp, szGuild);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;
#if defined(UFEMU) || defined(ROF2EMU)
	case GuildStatus:
		Dest.Type = pStringType;
		if (pSpawn->GuildID != -1 && pSpawn->GuildID != 0)
		{
			strcpy_s(DataTypeTemp, szGuildStatus[pSpawn->GuildStatus]);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
#endif
	case Type:
		DataTypeTemp[0] = '\0';
		Dest.Type = pStringType;
		switch (GetSpawnType(pSpawn))
		{
		case MOUNT:
			strcpy_s(DataTypeTemp, "Mount");
			break;
		case UNTARGETABLE:
			strcpy_s(DataTypeTemp, "Untargetable");
			break;
		case NPC:
			strcpy_s(DataTypeTemp, "NPC");
			break;
		case PC:
			strcpy_s(DataTypeTemp, "PC");
			break;
		case CHEST:
			strcpy_s(DataTypeTemp, "Chest");
			break;
		case TRAP:
			strcpy_s(DataTypeTemp, "Trap");
			break;
		case TRIGGER:
			strcpy_s(DataTypeTemp, "Trigger");
			break;
		case TIMER:
			strcpy_s(DataTypeTemp, "Timer");
			break;
		case PET:
			strcpy_s(DataTypeTemp, "Pet");
			break;
		case ITEM:
			strcpy_s(DataTypeTemp, "Item");
			break;
		case CORPSE:
			strcpy_s(DataTypeTemp, "Corpse");
			break;
		case AURA:
			strcpy_s(DataTypeTemp, "Aura");
			break;
		case OBJECT:
			strcpy_s(DataTypeTemp, "Object");
			break;
		case BANNER:
			strcpy_s(DataTypeTemp, "Banner");
			break;
		case CAMPFIRE:
			strcpy_s(DataTypeTemp, "Campfire");
			break;
		case MERCENARY:
			strcpy_s(DataTypeTemp, "Mercenary");
			break;
		case FLYER:
			strcpy_s(DataTypeTemp, "Flyer");
			break;
		}
		if (DataTypeTemp[0] != '\0') {
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Light:
		strcpy_s(DataTypeTemp, GetLightForSpawn(pSpawn));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case StandState:
		Dest.Int = pSpawn->StandState;
		Dest.Type = pIntType;
		return true;
	case State:
		DataTypeTemp[0] = '\0';
		Dest.Type = pStringType;
		if ((pSpawn->PlayerState & 0x20) && (pSpawn->StandState != STANDSTATE_DEAD))
		{
			strcpy_s(DataTypeTemp, "STUN");
		}
		else if (pSpawn == (PSPAWNINFO)pLocalPlayer && pSpawn->RespawnTimer)
		{
			strcpy_s(DataTypeTemp, "HOVER");
		}
		else if (pSpawn->Mount)
		{
			strcpy_s(DataTypeTemp, "MOUNT");
		}
		else
			switch (pSpawn->StandState)
			{
			case STANDSTATE_STAND:
				strcpy_s(DataTypeTemp, "STAND");
				break;
			case STANDSTATE_SIT:
				strcpy_s(DataTypeTemp, "SIT");
				break;
			case STANDSTATE_DUCK:
				strcpy_s(DataTypeTemp, "DUCK");
				break;
			case STANDSTATE_BIND:
				strcpy_s(DataTypeTemp, "BIND");
				break;
			case STANDSTATE_FEIGN:
				strcpy_s(DataTypeTemp, "FEIGN");
				break;
			case STANDSTATE_DEAD:
				strcpy_s(DataTypeTemp, "DEAD");
				break;
			default:
				strcpy_s(DataTypeTemp, "UNKNOWN");
				break;
			}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Standing:
		Dest.DWord = pSpawn->StandState == STANDSTATE_STAND;
		Dest.Type = pBoolType;
		return true;
	case Sitting:
		Dest.DWord = pSpawn->StandState == STANDSTATE_SIT;
		Dest.Type = pBoolType;
		return true;
	case TimeBeenDead:
		Dest.DWord = EQGetTime() - pSpawn->RespawnTimer;
		Dest.Type = pTimeStampType;
		return true;
	case IsSummoned://if its a summoned being (pet for example)
		Dest.DWord = pSpawn->bSummoned;
		Dest.Type = pBoolType;
		return true;
	case TargetOfTarget:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = GetSpawnByID(pSpawn->TargetOfTarget)) {
				return true;
			}
		return false;
	case Ducking:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DUCK;
		Dest.Type = pBoolType;
		return true;
	case Feigning:
		Dest.DWord = pSpawn->StandState == STANDSTATE_FEIGN;
		Dest.Type = pBoolType;
		return true;
	case Binding:
		Dest.DWord = pSpawn->StandState == STANDSTATE_BIND;
		Dest.Type = pBoolType;
		return true;
	case Dead:
		Dest.DWord = pSpawn->StandState == STANDSTATE_DEAD;
		Dest.Type = pBoolType;
		return true;
	case Stunned:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x20)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;
	case Aggressive:
		Dest.DWord = false;
		if (pSpawn->PlayerState & 0x4 || pSpawn->PlayerState & 0x8)
			Dest.DWord = true;
		Dest.Type = pBoolType;
		return true;
	case Hovering:
		Dest.DWord = (pSpawn->RespawnTimer);
		Dest.Type = pBoolType;
		return true;
	case Deity:
		Dest.DWord = pSpawn->Deity;
		Dest.Type = pDeityType;
		return true;
	case Distance:
		Dest.Float = GetDistance(pSpawn->X, pSpawn->Y);
		Dest.Type = pFloatType;
		return true;
	case Distance3D:
		Dest.Float = DistanceToSpawn3D((PSPAWNINFO)pCharSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;
	case DistancePredict:
		Dest.Float = EstimatedDistanceToSpawn((PSPAWNINFO)pCharSpawn, pSpawn);
		Dest.Type = pFloatType;
		return true;
	case DistanceW:
	case DistanceX:
		Dest.Float = (FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->X - pSpawn->X);
		Dest.Type = pFloatType;
		return true;
	case DistanceN:
	case DistanceY:
		Dest.Float = (FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Y - pSpawn->Y);
		Dest.Type = pFloatType;
		return true;
	case DistanceU:
	case DistanceZ:
		Dest.Float = (FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Z - pSpawn->Z);
		Dest.Type = pFloatType;
		return true;
	case HeadingTo:
		Dest.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pSpawn->Y, pSpawn->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Dest.Float < 0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;
	case Casting:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pSpawn->CastingData.SpellID))
		{
			return true;
		}
		return false;
	case Mount:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->Mount)
		{
			return true;
		}
		return false;
	case Underwater:
		Dest.DWord = (pSpawn->UnderWater == 5);
		Dest.Type = pBoolType;
		return true;
	case FeetWet:
		Dest.DWord = (pSpawn->FeetWet == 5);
		Dest.Type = pBoolType;
		return true;
	case PlayerState:
		Dest.DWord = pSpawn->PlayerState;
		Dest.Type = pIntType;
		return true;
	case Stuck:
		Dest.DWord = pSpawn->PossiblyStuck;
		Dest.Type = pBoolType;
		return true;
	case Animation:
		Dest.DWord = pSpawn->Animation;
		Dest.Type = pIntType;
		return true;
	case Holding:
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pSpawn->LeftHolding || pSpawn->RightHolding) {
			Dest.DWord = true;
		}
		return true;
	}
	case Look:
		Dest.Float = pSpawn->CameraAngle;
		Dest.Type = pFloatType;
		return true;
	case xConColor:
		Dest.Type = pStringType;
		switch (ConColor(pSpawn))
		{
		case CONCOLOR_GREY:
			strcpy_s(DataTypeTemp, "GREY");
			break;
		case CONCOLOR_GREEN:
			strcpy_s(DataTypeTemp, "GREEN");
			break;
		case CONCOLOR_LIGHTBLUE:
			strcpy_s(DataTypeTemp, "LIGHT BLUE");
			break;
		case CONCOLOR_BLUE:
			strcpy_s(DataTypeTemp, "BLUE");
			break;
		case CONCOLOR_WHITE:
			strcpy_s(DataTypeTemp, "WHITE");
			break;
		case CONCOLOR_YELLOW:
			strcpy_s(DataTypeTemp, "YELLOW");
			break;
		case CONCOLOR_RED:
		default:
			strcpy_s(DataTypeTemp, "RED");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Invited:
		Dest.DWord = (pSpawn->InvitedToGroup);
		Dest.Type = pBoolType;
		return true;
	case Inviter:
		strcpy_s(DataTypeTemp, (PCHAR)__Inviter);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
#ifndef ISXEQ
	case NearestSpawn:
		Dest.Type = pSpawnType;
		if (pSpawn == (PSPAWNINFO)pCharSpawn)
		{
			return (dataNearestSpawn(Index, Dest) != 0);// use top-level object if it's you
		}
		if (ISINDEX())
		{
			PCHAR pSearch;
			unsigned long nth;
			SEARCHSPAWN ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ssSpawn.FRadius = 999999.0f;
			if (pSearch = strchr(Index, ','))
			{
				*pSearch = 0;
				++pSearch;
				ParseSearchSpawn(pSearch, &ssSpawn);
				nth = GETNUMBER();
			}
			else
			{
				if (ISNUMBER())
				{
					nth = GETNUMBER();
				}
				else
				{
					nth = 1;
					ParseSearchSpawn(Index, &ssSpawn);
				}
			}
			if (Dest.Ptr = NthNearestSpawn(&ssSpawn, nth, pSpawn))
			{
				return true;
			}
		}
		return false;
#else
	case NearestSpawn:
		Dest.Type = pSpawnType;
		if (pSpawn == (PSPAWNINFO)pCharSpawn)
		{
			return (dataNearestSpawn(argc, argv, Dest) != 0);// use top-level object if it's you
		}
		if (argc)
		{
			unsigned long nth;
			SEARCHSPAWN ssSpawn;
			ClearSearchSpawn(&ssSpawn);
			ssSpawn.FRadius = 999999.0f;
			if (argc >= 2 || !IsNumber(argv[0]))
			{
				ParseSearchSpawn(1, argc, argv, ssSpawn);
				nth = atoi(argv[0]);
			}
			else
			{
				nth = atoi(argv[0]);
			}
			if (Dest.Ptr = NthNearestSpawn(&ssSpawn, nth, pSpawn))
			{
				return true;
			}
		}
		return false;
#endif
	case Trader:
		Dest.DWord = pSpawn->Trader;
		Dest.Type = pBoolType;
		return true;
	case AFK:
		Dest.DWord = pSpawn->AFK;
		Dest.Type = pBoolType;
		return true;
	case LFG:
		Dest.DWord = pSpawn->LFG;
		Dest.Type = pBoolType;
		return true;
	case Linkdead:
		Dest.DWord = pSpawn->Linkdead;
		Dest.Type = pBoolType;
		return true;
	case AATitle:  // Leaving this in for older macros/etc.."Title" should be used instead.
	case Title:
		strcpy_s(DataTypeTemp, pSpawn->Title);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp;
		return true;
	case Suffix:
		strcpy_s(DataTypeTemp, pSpawn->Suffix);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case xGroupLeader:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (PCHARINFO pCharInfo = GetCharInfo()) {
			if (pCharInfo->pGroupInfo && pCharInfo->pGroupInfo->pLeader) {
				CHAR Name[MAX_STRING] = { 0 };
				GetCXStr(pCharInfo->pGroupInfo->pLeader->pName, Name, MAX_STRING);
				Dest.DWord = (pSpawn->Type == SPAWN_PLAYER && !_stricmp(Name, pSpawn->Name));
				return true;
			}
		}
		return false;
	case Assist:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (gGameState == GAMESTATE_INGAME && pSpawn)
		{
			if (DWORD AssistID = GetGroupMainAssistTargetID()) {
				if (AssistID == pSpawn->SpawnID) {
					Dest.DWord = 1;
					return true;
				}
			}
			for (int nAssist = 0; nAssist < 3; nAssist++) {
				if (DWORD AssistID = GetRaidMainAssistTargetID(nAssist)) {
					if (AssistID == pSpawn->SpawnID) {
						Dest.DWord = 1;
						return true;
					}
				}
			}
		}
		return true;
	case Mark:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer && pSpawn)
		{
			DWORD nMark;
			for (nMark = 0; nMark < 3; nMark++)
			{
				if (((PSPAWNINFO)pLocalPlayer)->RaidMarkNPC[nMark] == pSpawn->SpawnID)
				{
					Dest.DWord = nMark + 1;
					return true;
				}
			}
			for (nMark = 0; nMark < 3; nMark++)
			{
				if (((PSPAWNINFO)pLocalPlayer)->GroupMarkNPC[nMark] == pSpawn->SpawnID)
				{
					Dest.DWord = nMark + 1;
					return true;
				}
			}
		}
		return false;
	case Anonymous:
		Dest.DWord = (pSpawn->Anon == 1);
		Dest.Type = pBoolType;
		return true;
	case Roleplaying:
		Dest.DWord = (pSpawn->Anon == 2);
		Dest.Type = pBoolType;
		return true;
	case xLineOfSight:
		Dest.DWord = pCharSpawn->CanSee((EQPlayer*)pSpawn);
		//Dest.DWord=(LineOfSight(GetCharInfo()->pSpawn,pSpawn));
		Dest.Type = pBoolType;
		return true;
	case HeadingToLoc:
		Dest.Float = 0.0;
		Dest.Type = pHeadingType;
#ifndef ISXEQ
		if (!ISINDEX())
			return false;
		if (PCHAR pComma = strchr(Index, ','))
		{
			*pComma = 0;
			FLOAT Y = (FLOAT)atof(Index);
			*pComma = ',';
			FLOAT X = (FLOAT)atof(&pComma[1]);
#else
		if (!argc)
			return false;
		if (argc == 2)
		{
			FLOAT Y = (FLOAT)atof(argv[0]);
			FLOAT X = (FLOAT)atof(argv[1]);
#endif
			Dest.Float = (FLOAT)(atan2f(pSpawn->Y - Y, X - pSpawn->X) * 180.0f / PI + 90.0f);
			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;
			return true;
		}
		return false;
	case Fleeing:
		Dest.DWord = IsMobFleeing(GetCharInfo()->pSpawn, pSpawn);
		Dest.Type = pBoolType;
		return true;
	case Named:
		Dest.DWord = IsNamed(pSpawn);
		Dest.Type = pBoolType;
		return true;
	case Buyer:
		Dest.DWord = pSpawn->Buyer;
		Dest.Type = pBoolType;
		return true;
	case Moving:
		Dest.DWord = fabs(pSpawn->SpeedRun) > 0.0f;
		Dest.Type = pBoolType;
		return true;
	case CurrentMana:
		Dest.DWord = pSpawn->GetCurrentMana();
		Dest.Type = pIntType;
		return true;
	case MaxMana:
		Dest.DWord = pSpawn->GetMaxMana();
		Dest.Type = pIntType;
		return true;
	case PctMana:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxmana = pSpawn->GetMaxMana())
			Dest.Int = pSpawn->GetCurrentMana() * 100 / maxmana;
		return true;
	case CurrentEndurance:
		Dest.DWord = pSpawn->GetCurrentEndurance();
		Dest.Type = pIntType;
		return true;
	case PctEndurance:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (int maxend = pSpawn->GetMaxEndurance())
			Dest.Int = pSpawn->GetCurrentEndurance() * 100 / maxend;
		return true;
	case MaxEndurance:
		Dest.DWord = pSpawn->GetMaxEndurance();
		Dest.Type = pIntType;
		return true;
	case Loc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case LocYX:
		sprintf_s(DataTypeTemp, "%.0f, %.0f", pSpawn->Y, pSpawn->X);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case LocYXZ:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case EQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->X, pSpawn->Y, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case MQLoc:
		sprintf_s(DataTypeTemp, "%.2f, %.2f, %.2f", pSpawn->Y, pSpawn->X, pSpawn->Z);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Owner:
		Dest.Type = pSpawnType;
		if (pSpawn->Mercenary)
		{
			unsigned int pos = strchr(pSpawn->Lastname, '\'') - &pSpawn->Lastname[0];
			strncpy_s(DataTypeTemp, pSpawn->Lastname, pos);
			DataTypeTemp[pos] = 0;
			if (PSPAWNINFO pOwner = (PSPAWNINFO)GetSpawnByName(DataTypeTemp))
			{
				Dest.Ptr = pOwner;
				return true;
			}
		}
		return false;
	case Following:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pSpawn->WhoFollowing)
		{
			return true;
		}
		return false;
	case MercID:
		Dest.DWord = pSpawn->MercID;
		Dest.Type = pIntType;
		return true;
	case ContractorID:
		Dest.DWord = pSpawn->ContractorID;
		Dest.Type = pIntType;
		return true;
	case Primary:
		Dest.DWord = pSpawn->Equipment.Primary.ID;
		Dest.Type = pIntType;
		return true;
	case Secondary:
		Dest.DWord = pSpawn->Equipment.Offhand.ID;
		Dest.Type = pIntType;
		return true;
	case Equipment:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISINDEX()) {
			if (ISNUMBER()) {
				unsigned long nSlot = GETNUMBER();
				int size = sizeof(_EQUIPMENT) / 4;
				//int size2 = sizeof(szEquipmentSlot);
				//int size3 = sizeof(szEquipmentSlot[])/4;
				if (nSlot < 9) {
					Dest.DWord = pSpawn->Equipment.Item[nSlot].ID;
					return true;
				}
			}
			else {
				for (unsigned long nSlot = 0; szEquipmentSlot[nSlot]; nSlot++) {
					if (!_stricmp(GETFIRST(), szEquipmentSlot[nSlot])) {
						Dest.DWord = pSpawn->Equipment.Item[nSlot].ID;
						return true;
					}
				}
			}
		}
		return false;
	case xTargetable:
		Dest.DWord = pSpawn->Targetable;
		Dest.Type = pBoolType;
		return true;
	case CanSplashLand:
    {
        CVector3 sv3;
        sv3.X = pSpawn->Y;
        sv3.Y = pSpawn->X;
        sv3.Z = pSpawn->Z;
		PZONEINFO pZone = reinterpret_cast<PZONEINFO>(pZoneInfo);
        CDisplay *pDsp = reinterpret_cast<CDisplay*>(pDisplay);
		if (pZone && pDsp) {
			float Z = 0;
			FLOAT curr_z = 0.0f;
			for (float f = pZone->Ceiling; f > pZone->Floor; f -= 1.0f)
			{
				curr_z = pDsp->GetFloorHeight(X, Y, f);
				if (curr_z != ((float)-1.0e27))
				{
					Z = curr_z;
					break;
				}
			}
			if (Z)
			{
				sv3.Z = Z;
			}
		}
        Dest.DWord = pCharSpawn->CanSee(&sv3);
        Dest.Type = pBoolType;
        return true;
    }
	case IsBerserk:
		Dest.DWord = pSpawn->berserker;
		Dest.Type = pIntType;
		return true;
	case pTouchingSwitch:
		Dest.DWord = (DWORD)pSpawn->pTouchingSwitch;
		Dest.Type = pIntType;
		return true;
	case bShowHelm:
		Dest.DWord = pSpawn->bShowHelm;
		Dest.Type = pBoolType;
		return true;
	case CorpseDragCount:
		Dest.DWord = pSpawn->CorpseDragCount;
		Dest.Type = pIntType;
		return true;
	case bBetaBuffed:
		Dest.DWord = pSpawn->bBetaBuffed;
		Dest.Type = pBoolType;
		return true;
	case CombatSkillTicks:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISNUMBER()) {
			int index = GETNUMBER();
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			Dest.DWord = pSpawn->CombatSkillTicks[index];
			return true;
		}
		return false;
	case FD:
		Dest.DWord = pSpawn->FD;
		Dest.Type = pIntType;
		return true;
	case InPvPArea:
		Dest.DWord = pSpawn->InPvPArea;
		Dest.Type = pIntType;
		return true;
	case bAlwaysShowAura:
		Dest.DWord = pSpawn->bAlwaysShowAura;
		Dest.Type = pBoolType;
		return true;
	case GMRank:
		Dest.DWord = pSpawn->GMRank;
		Dest.Type = pIntType;
		return true;
	case WarCry:
		Dest.DWord = pSpawn->WarCry;
		Dest.Type = pIntType;
		return true;
	case IsPassenger:
		Dest.DWord = pSpawn->IsPassenger;
		Dest.Type = pIntType;
		return true;
	case LastCastTime:
		Dest.DWord = pSpawn->LastCastTime;
		Dest.Type = pIntType;
		return true;
	case DragNames:
		Dest.Type = pStringType;
		if (ISNUMBER()) {
			int index = GETNUMBER();
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			strcpy_s(DataTypeTemp, pSpawn->DragNames[index]);
			Dest.Ptr = DataTypeTemp;
			return true;
		}
		return false;
	case DraggingPlayer:
		strcpy_s(DataTypeTemp, pSpawn->DraggingPlayer);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
	case bStationary:
		Dest.DWord = pSpawn->bStationary;
		Dest.Type = pBoolType;
		return true;
	case BearingToTarget:
		Dest.Float = pSpawn->BearingToTarget;
		Dest.Type = pFloatType;
		return true;
	case bTempPet:
		Dest.DWord = pSpawn->bTempPet;
		Dest.Type = pBoolType;
		return true;
	case HoldingAnimation:
		Dest.DWord = pSpawn->HoldingAnimation;
		Dest.Type = pIntType;
		return true;
	case Blind:
		Dest.DWord = pSpawn->Blind;
		Dest.Type = pIntType;
		return true;
	case LastCastNum:
		Dest.DWord = pSpawn->LastCastNum;
		Dest.Type = pIntType;
		return true;
	case CollisionCounter:
		Dest.DWord = pSpawn->CollisionCounter;
		Dest.Type = pIntType;
		return true;
	case CeilingHeightAtCurrLocation:
		Dest.Float = pSpawn->CeilingHeightAtCurrLocation;
		Dest.Type = pFloatType;
		return true;
	case AssistName:
		strcpy_s(DataTypeTemp, pSpawn->AssistName);
		Dest.Ptr = DataTypeTemp;
		Dest.Type = pStringType;
		return true;
	case SeeInvis:
		Dest.DWord = 0;
		Dest.Type = pIntType;
#if !defined(ROF2EMU) && !defined(UFEMU)
		if (ISNUMBER()) {
			int index = GETNUMBER();
			if (index < 0)
				index = 0;
			if (index > 2)
				index = 2;
			Dest.DWord = pSpawn->SeeInvis[index];
			return true;
		}
#endif
		return false;
	case SpawnStatus:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISNUMBER()) {
			int index = GETNUMBER();
			if (index < 0)
				index = 0;
			if (index > 5)
				index = 5;
			Dest.DWord = pSpawn->SpawnStatus[index];
			return true;
		}
		return false;
	case bWaitingForPort:
		Dest.DWord = pSpawn->bWaitingForPort;
		Dest.Type = pBoolType;
		return true;
	case ActorDef:
	{
		strcpy_s(DataTypeTemp, pSpawn->mActorClient.ActorDef);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case CachedBuff:
	{
		Dest.Type = pCachedBuffType;
		lockit lk(ghCachedBuffsLock);
		if (CachedBuffsMap.empty())
			return false;
		DWORD SpellID = 0;
		BOOL bExact = false;
		bool bByName = false;
		bool bBySlot = false;
		bool bByIndex = false;
		bool bByKeyword = false;

		PCHAR pIndex = GETFIRST();
		if (pIndex[0])
		{
			if (ISNUMBER())
			{
				//by spell ID
				SpellID = GETNUMBER();
			}
			else
			{
				if (*pIndex == '=') {
					bExact = true;
					pIndex++;
				}
				if (*pIndex == '#') {
					//by buff slot
					bBySlot = true;
					pIndex++;
				}
				else if (*pIndex == '*') {
					//by buff index
					bByIndex = true;
					pIndex++;
				}
				else if (*pIndex == '^') {
					//by keyword
					bByKeyword = true;
					pIndex++;
				}
				else
				{
					bByName = true;
					if (bExact)
					{
						//by exact spell name
						if (PSPELL pSpell = GetSpellByName(pIndex))
						{
							SpellID = pSpell->ID;
						}
					}
					else
					{
						TruncateSpellRankName(pIndex);
					}
				}
			}
			if (bByName)
			{
				//CHAR szTemp[MAX_STRING];
				std::map<int, std::map<int, cTargetBuff>>::iterator ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					bool bFound = false;
					for (std::map<int, cTargetBuff>::iterator i = ps->second.begin(); i != ps->second.end(); i++)
					{
						if (bExact)
						{
							if (i->first == SpellID)
							{
								bFound = true;
							}
						}
						else
						{
							if (PSPELL pSpell = GetSpellByID(i->first))
							{
								//strcpy_s(szTemp, pSpell->Name);
								if (!_strnicmp(pSpell->Name, pIndex, strlen(pIndex)))
								{
									bFound = true;
								}
							}
						}
						if (bFound)
						{
							strcpy_s(TargetBuffTemp.casterName, i->second.casterName);
							TargetBuffTemp.count = i->second.count;
							TargetBuffTemp.duration = i->second.duration;
							TargetBuffTemp.slot = i->second.slot;
							TargetBuffTemp.spellId = i->second.spellId;
							TargetBuffTemp.timeStamp = i->second.timeStamp;
							Dest.Ptr = &TargetBuffTemp;
							return true;
						}
					}
				}
			}
			else if (bBySlot)
			{
				int idx = atoi(pIndex);
				idx--;
				std::map<int, std::map<int, cTargetBuff>>::iterator ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					std::map<int, cTargetBuff>::iterator i = ps->second.begin();
					if (i != ps->second.end())
					{
						if (idx < 0)
							idx = 0;
						if (idx > NUM_BUFF_SLOTS)//the xml only have 84 slots...
						{
							idx = NUM_BUFF_SLOTS;
						}
						for (std::map<int, cTargetBuff>::iterator i = ps->second.begin(); i != ps->second.end(); i++)
						{
							if (i->second.slot == idx)
							{
								strcpy_s(TargetBuffTemp.casterName, i->second.casterName);
								TargetBuffTemp.count = i->second.count;
								TargetBuffTemp.duration = i->second.duration;
								TargetBuffTemp.slot = i->second.slot;
								TargetBuffTemp.spellId = i->second.spellId;
								TargetBuffTemp.timeStamp = i->second.timeStamp;
								Dest.Ptr = &TargetBuffTemp;
								return true;
							}
						}
					}
				}
			}
			else if (bByIndex)
			{
				int idx = atoi(pIndex);
				idx--;
				std::map<int, std::map<int, cTargetBuff>>::iterator ps = CachedBuffsMap.find(pSpawn->SpawnID);
				if (ps != CachedBuffsMap.end())
				{
					std::map<int, cTargetBuff>::iterator i = ps->second.begin();
					if (i != ps->second.end())
					{
						if (idx < 0)
							idx = 0;
						if (idx >= (int)ps->second.size())
						{
							return false;
							//idx = ps->second.size() - 1;
						}
						std::advance(i, idx);
						if (i != ps->second.end())
						{
							strcpy_s(TargetBuffTemp.casterName, i->second.casterName);
							TargetBuffTemp.count = i->second.count;
							TargetBuffTemp.duration = i->second.duration;
							TargetBuffTemp.slot = i->second.slot;
							TargetBuffTemp.spellId = i->second.spellId;
							TargetBuffTemp.timeStamp = i->second.timeStamp;
							Dest.Ptr = &TargetBuffTemp;
							return true;
						}
					}
				}
			}
			else if (bByKeyword)
			{
				/*Slowed = 8,
				Rooted = 9,
				Mezzed = 10,
				Crippled = 11,
				Maloed = 12,
				Tashed = 13,
				Snared = 14,
				Hasted = 15,
				Aego = 16,
				Skin = 17,
				Focus = 18,
				Regen = 19,
				Symbol = 20,
				Clarity = 21,
				Pred = 22,
				Strength = 23,
				Brells = 24,
				SV = 25,
				SE = 26,
				HybridHP = 27,
				Growth = 28,
				Shining = 29,
				Beneficial = 30,
				DSed = 31,
				RevDSed = 32,
				Charmed = 33,
				Diseased = 34,
				Poisoned = 35,
				Cursed = 36,
				Corrupted
				*/
				int type = -1;
				if (!_stricmp(pIndex, "Slowed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(11, 0, pSpawn,&TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Rooted"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(99, 0, pSpawn,&TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Mezzed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(31, 0, pSpawn,&TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Crippled"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSubCat("Disempowering",pSpawn,&TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Maloed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					//GetTargetBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage));
					if (HasCachedTargetBuffSubCat("Resist Debuffs",pSpawn,&TargetBuffTemp,(1 << Shaman) + (1 << Mage)))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Tashed"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSubCat("Resist Debuffs",pSpawn,&TargetBuffTemp,1 << Enchanter))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Snared"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					if (HasCachedTargetBuffSPA(3, 0, pSpawn, &TargetBuffTemp))
					{
						Dest.Ptr = &TargetBuffTemp;
						return true;
					}
					return false;
				}
				else if (!_stricmp(pIndex, "Beneficial"))
				{
					Dest.Ptr = 0;
					Dest.Type = pCachedBuffType;
					std::map<int, std::map<int, cTargetBuff>>::iterator ps = CachedBuffsMap.find(pSpawn->SpawnID);
					if (ps != CachedBuffsMap.end())
					{
						for (std::map<int, cTargetBuff>::iterator i = ps->second.begin(); i != ps->second.end(); i++)
						{
							if (PSPELL pSpell = GetSpellByID(i->first)) {
								if (pSpell->SpellType != 0)
								{
									//targetwindow has a leak in it player buffs shows up in it
									//so we need to make sure its not a "leaked buff"
									if (PSPAWNINFO pPlayer = (PSPAWNINFO)GetSpawnByName(i->second.casterName)) {
										if (pPlayer->Type == SPAWN_PLAYER) {
											continue;
										}
									}
									strcpy_s(TargetBuffTemp.casterName, i->second.casterName);
									TargetBuffTemp.count = i->second.count;
									TargetBuffTemp.duration = i->second.duration;
									TargetBuffTemp.slot = i->second.slot;
									TargetBuffTemp.spellId = i->second.spellId;
									TargetBuffTemp.timeStamp = i->second.timeStamp;
									Dest.Ptr = &TargetBuffTemp;
									return true;
								}
							}
						}
					}
					return false;
				}
			}
		}
		return false;
	}
	case CachedBuffCount:
	{
		lockit lk(ghCachedBuffsLock);
		Dest.Type = pIntType;
		Dest.DWord = -1;
		std::map<int, std::map<int, cTargetBuff>>::iterator ps = CachedBuffsMap.find(pSpawn->SpawnID);
		if (ps != CachedBuffsMap.end())
		{
			Dest.DWord = ps->second.size();
		}
		return true;
	}
	default:
		return false;
		}
	return false;
	}


bool MQ2BuffType::GETMEMBER()
{
#define pBuff ((PSPELLBUFF)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	if ((int)pBuff->SpellID <= 0)
		return false;
	PMQ2TYPEMEMBER pMethod = MQ2BuffType::FindMethod(Member);
	if (pMethod) {
		switch ((BuffMethods)pMethod->ID)
		{
		case Remove:
			if (PSPELL pSpell = GetSpellByID(pBuff->SpellID)) {
				RemoveBuff((PSPAWNINFO)pLocalPlayer, pSpell->Name);
				return true;
			}
			break;
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2BuffType::FindMember(Member);
	if (!pMember)
	{
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
#ifndef ISXEQ
			return pSpellType->GetMember(*(MQ2VARPTR*)&pSpell, Member, Index, Dest);
#else
			return pSpellType->GetMember(*(LSVARPTR*)&pSpell, Member, argc, argv, Dest);
#endif
		}
		return false;
	}

	static CHAR Temp[128];
	switch ((BuffMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case ID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetBuffID(pBuff, (DWORD&)Dest.DWord))
		{
			return true;
		}
		if (GetShortBuffID(pBuff, (DWORD&)Dest.DWord))
		{
			return true;
		}
		return false;
	case Level:
		Dest.DWord = pBuff->Level;
		Dest.Type = pIntType;
		return true;
	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pBuff->SpellID))
		{
			return true;
		}
		return false;
	case Mod:
		Dest.Float = pBuff->Modifier;
		Dest.Type = pFloatType;
		if (Dest.Float != 1.0f)
		{
			return true;
		}
		return false;
	case Duration:
		Dest.UInt64 = GetSpellBuffTimer(pBuff->SpellID);
		Dest.Type = pTimeStampType;
		return true;
	case Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType != 0)
			{
				LONG slots = GetSpellNumEffects(pSpell);
				for (LONG i = 0; i < slots; i++) {
					LONG attrib = GetSpellAttrib(pSpell, i);
					if (attrib == 55 || attrib == 78 || attrib == 161 || attrib == 162 || attrib == 450 || attrib == 451 || attrib == 452)
						for (LONG j = 0; j < NUM_SLOTDATA; j++) {
							if (pBuff->SlotData[j].Slot == i) {
								Dest.DWord += pBuff->SlotData[j].Value;
							}
						}
				}
				return true;
			}
		}
		return false;
	case TotalCounters:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType == 0) {
				LONG slots = GetSpellNumEffects(pSpell);
				for (LONG i = 0; i < slots; i++) {
					LONG attrib = GetSpellAttrib(pSpell, i);
					if (attrib == 35 || attrib == 36 || attrib == 116 || attrib == 369)
						for (LONG j = 0; j < NUM_SLOTDATA; j++) {
							if (pBuff->SlotData[j].Slot == i) {
								Dest.DWord += pBuff->SlotData[j].Value;
							}
						}
				}
				return true;
			}
		}
		return false;
	case CountersDisease:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType == 0) {
				LONG slots = GetSpellNumEffects(pSpell);
				for (LONG i = 0; i < slots; i++) {
					LONG attrib = GetSpellAttrib(pSpell, i);
					if (attrib == 35)
						for (LONG j = 0; j < NUM_SLOTDATA; j++) {
							if (pBuff->SlotData[j].Slot == i) {
								Dest.DWord += pBuff->SlotData[j].Value;
							}
						}
				}
				return true;
			}
		}
		return false;
	case CountersPoison:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType == 0) {
				LONG slots = GetSpellNumEffects(pSpell);
				for (LONG i = 0; i < slots; i++) {
					LONG attrib = GetSpellAttrib(pSpell, i);
					if (attrib == 36)
						for (LONG j = 0; j < NUM_SLOTDATA; j++) {
							if (pBuff->SlotData[j].Slot == i) {
								Dest.DWord += pBuff->SlotData[j].Value;
							}
						}
				}
				return true;
			}
		}
		return false;
	case CountersCurse:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType == 0) {
				LONG slots = GetSpellNumEffects(pSpell);
				for (LONG i = 0; i < slots; i++) {
					LONG attrib = GetSpellAttrib(pSpell, i);
					if (attrib == 116)
						for (LONG j = 0; j < NUM_SLOTDATA; j++) {
							if (pBuff->SlotData[j].Slot == i) {
								Dest.DWord += pBuff->SlotData[j].Value;
							}
						}
				}
				return true;
			}
		}
		return false;
	case CountersCorruption:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PSPELL pSpell = GetSpellByID(pBuff->SpellID))
		{
			if (pSpell->SpellType == 0) {
				LONG slots = GetSpellNumEffects(pSpell);
				for (LONG i = 0; i < slots; i++) {
					LONG attrib = GetSpellAttrib(pSpell, i);
					if (attrib == 369)
						for (LONG j = 0; j < NUM_SLOTDATA; j++) {
							if (pBuff->SlotData[j].Slot == i) {
								Dest.DWord += pBuff->SlotData[j].Value;
							}
						}
				}
				return true;
			}
		}
		return false;
	case HitCount:
		Dest.DWord = pBuff->HitCount;
		Dest.Type = pIntType;
		return true;
	}
	return false;
#undef pBuff
}

bool MQ2TargetBuffType::GETMEMBER()
{
	//int theindex VarPtr.Int;
	if (VarPtr.Int == -1)
		return false;
	int buffid = ((PCTARGETWND)pTargetWnd)->BuffSpellID[VarPtr.Int];
	if (buffid <= 0)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2TargetBuffType::FindMember(Member);
	if (!pMember)
	{
		if (PSPELL pSpell = GetSpellByID(buffid))
		{
#ifndef ISXEQ
			return pSpellType->GetMember(*(MQ2VARPTR*)&pSpell, Member, Index, Dest);
#else
			return pSpellType->GetMember(*(LSVARPTR*)&pSpell, Member, argc, argv, Dest);
#endif
		}
		return false;
	}

	static CHAR Temp[128];
	switch ((TargetBuffMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)&((PCTARGETWND)pTargetWnd)->BuffSpellID[VarPtr.Int];
		Dest.Type = pIntType;
		return true;
	case xIndex:
		Dest.Int = VarPtr.Int;
		Dest.Type = pIntType;
		return true;
	case Duration:
		Dest.UInt64 = ((PCTARGETWND)pTargetWnd)->BuffTimer[VarPtr.Int];
		Dest.Type = pTimeStampType;
		return true;
	}
	return false;
}
bool MQ2CachedBuffType::GETMEMBER()
{
	PcTargetBuff pcTB = (PcTargetBuff)VarPtr.Ptr;
	if (!pcTB)
		return false;
	int buffid = pcTB->spellId;
	if (buffid <= 0)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2CachedBuffType::FindMember(Member);
	if (!pMember)
	{
		if (PSPELL pSpell = GetSpellByID(buffid))
		{
#ifndef ISXEQ
			return pSpellType->GetMember(*(MQ2VARPTR*)&pSpell, Member, Index, Dest);
#else
			return pSpellType->GetMember(*(LSVARPTR*)&pSpell, Member, argc, argv, Dest);
#endif
		}
		return false;
	}
	switch ((CachedBuffMembers)pMember->ID)
	{
	case CasterName:
		strcpy_s(DataTypeTemp, pcTB->casterName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Count:
		Dest.Int = pcTB->count;
		Dest.Type = pIntType;
		return true;
	case Slot:
		Dest.Int = pcTB->slot;
		Dest.Type = pIntType;
		return true;
	case SpellID:
		Dest.Int = pcTB->spellId;
		Dest.Type = pIntType;
		return true;
	case Duration:
		//int at = pcTB->timeStamp + (pcTB->duration * 6000);
		int calcedduration = (pcTB->timeStamp + (pcTB->duration * 6000)) - EQGetTime();

		if (calcedduration < 0)
			calcedduration = 0;
		Dest.Int = calcedduration;
		Dest.Type = pTimeStampType;
		return true;
	}
	return false;
}
bool MQ2CharacterType::GETMEMBER()
{
	PCHARINFO pChar = ((PCHARINFO)VarPtr.Ptr);
	if (!pChar)
		return false;
	if (!pLocalPlayer)
		return false;
	//do the methods first cause there are so few of them
	PMQ2TYPEMEMBER pMethod = MQ2CharacterType::FindMethod(Member);
	if (pMethod) {
		switch ((CharacterMethods)pMethod->ID)
		{
		case Stand:
			pEverQuest->InterpretCmd((EQPlayer*)pChar->pSpawn, "/stand on");
			return true;
		case Sit:
			pEverQuest->InterpretCmd((EQPlayer*)pChar->pSpawn, "/sit on");
			return true;
		case Dismount:
			pEverQuest->InterpretCmd((EQPlayer*)pChar->pSpawn, "/dismount");
			return true;
		case StopCast:
			pEverQuest->InterpretCmd((EQPlayer*)pChar->pSpawn, "/stopcast");
			return true;
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2CharacterType::FindMember(Member);
	if (!pMember)
	{
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pLocalPlayer, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pLocalPlayer, Member, argc, argv, Dest);
#endif
	}
	switch ((CharacterMembers)pMember->ID)
	{
	case Name:
	{
		strcpy_s(DataTypeTemp, ((PSPAWNINFO)pLocalPlayer)->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}
	case Origin:
		Dest.Type = pZoneType;
		if (pChar->StartingCity > 0 && pChar->StartingCity < MAX_ZONES) {
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pChar->StartingCity];
				return true;
		}
		return false;
	case SubscriptionDays:
		#if !defined(ROF2EMU) && !defined(UFEMU)
		Dest.Int = pChar->SubscriptionDays;
		#else
		Dest.Int = 30;
		#endif
		Dest.Type = pIntType;
		return true;
	case Exp:
		Dest.Int64 = pChar->Exp;
		Dest.Type = pInt64Type;
		return true;
	case PctExp:
		Dest.Float = (float)pChar->Exp / 1000.0f;
		Dest.Type = pFloatType;
		return true;
	case PctExpToAA:
		Dest.Int = (int)pChar->PercentEXPtoAA;
		Dest.Type = pIntType;
		return true;
	case PctAAExp:
		Dest.Float = (float)pChar->AAExp / 1000.0f;
		Dest.Type = pFloatType;
		return true;
	case Vitality:
		Dest.Int64 = pChar->Vitality;
		Dest.Type = pInt64Type;
		return true;
	case PctVitality:
	{
		Dest.Float = 0;
		Dest.Type = pFloatType;
		__int64 vitality = pChar->Vitality;
		__int64 cap = pInventoryWnd->VitalityCap;
		if (vitality > cap)
			vitality = cap;
		if (cap > 0)
			Dest.Float = (float)vitality * 100 / cap;
		return true;
	}
	case AAVitality:
		Dest.Int = pChar->AAVitality;
		Dest.Type = pIntType;
		return true;
	case PctAAVitality:
	{
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int aavitality = pChar->AAVitality;
		int aacap = pInventoryWnd->AAVitalityCap;
		if (aavitality > aacap)
			aavitality = aacap;
		if (aacap > 0)
			Dest.Float = (float)aavitality * 100 / aacap;
		return true;
	}
	case Spawn:
		Dest.Ptr = pLocalPlayer;
		Dest.Type = pSpawnType;
		return true;
	case CurrentHPs:
		Dest.DWord = GetCurHPS();
		Dest.Type = pIntType;
		return true;
	case MaxHPs:
		Dest.Type = pIntType;
		Dest.Int = GetMaxHPS();
		return true;
	case PctHPs:
	{
		Dest.Int = 0;
		Dest.Type = pIntType;
		LONG maxhp = GetMaxHPS();
		if (maxhp != 0)
			Dest.Int = GetCurHPS() * 100 / maxhp;
		return true;
	}
	case CurrentMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Mana;
		}
		return true;
	case MaxMana:
		Dest.DWord = GetMaxMana();
		Dest.Type = pIntType;
		return true;
	case PctMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (unsigned long Temp = GetMaxMana()) {
				Dest.DWord = pChar2->Mana * 100 / Temp;
			}
		}
		return true;
	case CountBuffs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long nBuff = 0; nBuff < NUM_LONG_BUFFS; nBuff++) {
				if (pChar2->Buff[nBuff].SpellID > 0) {
					Dest.DWord++;
				}
			}

		}
		return true;
	case CountSongs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long nBuff = 0; nBuff < NUM_SHORT_BUFFS; nBuff++) {
				if (pChar2->ShortBuff[nBuff].SpellID > 0) {
					Dest.DWord++;
				}
			}
		}
		return true;
	case BlockedPetBuff:
		Dest.Type = pSpellType;
		if (!ISINDEX())
			return false;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			if (ISNUMBER())
			{
				int nBuff = GETNUMBER() - 1;
				if (nBuff < 0)
					nBuff = 0;
				if(nBuff > 0x28)
					return false;
				if (int spellid = pCharnew->BlockedPetSpell[nBuff])
				{
					if (PSPELL pSpell = GetSpellByID(spellid))
					{
						Dest.Ptr = pSpell;
						return true;
					}
				}
			}
			else
			{
				for (unsigned long nBuff = 0; nBuff < 0x28; nBuff++)
				{
					if (int spellid = pCharnew->BlockedPetSpell[nBuff])
					{
						if (PSPELL pSpell = GetSpellByID(spellid))
						{
							if (!_strnicmp(GETFIRST(), pSpell->Name, strlen(GETFIRST())))
							{
								Dest.Ptr = pSpell;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case BlockedBuff:
		Dest.Type = pSpellType;
		if (!ISINDEX())
			return false;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			if (ISNUMBER())
			{
				int nBuff = GETNUMBER() - 1;
				if (nBuff < 0)
					nBuff = 0;
				if(nBuff > NUM_BLOCKED_BUFFS)
					return false;
				if (int spellid = pCharnew->BlockedSpell[nBuff])
				{
					if (PSPELL pSpell = GetSpellByID(spellid))
					{
						Dest.Ptr = pSpell;
						return true;
					}
				}
			}
			else
			{
				for (unsigned long nBuff = 0; nBuff < NUM_BLOCKED_BUFFS; nBuff++)
				{
					if (int spellid = pCharnew->BlockedSpell[nBuff])
					{
						if (PSPELL pSpell = GetSpellByID(spellid))
						{
							if (!_strnicmp(GETFIRST(), pSpell->Name, strlen(GETFIRST())))
							{
								Dest.Ptr = pSpell;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case Buff:
		Dest.Type = pBuffType;
		if (!ISINDEX())
			return false;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (ISNUMBER())
			{
				int nBuff = GETNUMBER() - 1;
				if (nBuff < 0)
					nBuff = 0;
				if (nBuff >= NUM_LONG_BUFFS)
					return false;
				if (pChar2->Buff[nBuff].SpellID <= 0)
					return false;
				Dest.Ptr = &pChar2->Buff[nBuff];
				Dest.HighPart = nBuff;
				return true;
			}
			else
			{
				for (unsigned long nBuff = 0; nBuff < NUM_LONG_BUFFS; nBuff++)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (!_strnicmp(GETFIRST(), pSpell->Name, strlen(GETFIRST())))
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							Dest.HighPart = nBuff;
							return true;
						}
					}
				}
			}
		}
		return false;
	case Song:
		Dest.Type = pBuffType;
		if (!ISINDEX())
			return false;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (ISNUMBER())
			{
				int nBuff = GETNUMBER() - 1;
				if (nBuff < 0)
					return false;
				if (nBuff >= NUM_SHORT_BUFFS)
					return false;
				if (pChar2->ShortBuff[nBuff].SpellID <= 0)
					return false;

				Dest.Ptr = &pChar2->ShortBuff[nBuff];
				Dest.HighPart = nBuff;
				return true;
			}
			else
			{
				for (unsigned long nBuff = 0; nBuff < NUM_SHORT_BUFFS; nBuff++)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->ShortBuff[nBuff].SpellID))
					{
						if (!_strnicmp(GETFIRST(), pSpell->Name, strlen(GETFIRST())))
						{
							Dest.Ptr = &pChar2->ShortBuff[nBuff];
							Dest.HighPart = nBuff;
							return true;
						}
					}
				}
			}
		}
		return false;
	case HPBonus:
		Dest.DWord = pChar->HPBonus;
		Dest.Type = pIntType;
		return true;
	case ManaBonus:
		Dest.DWord = pChar->ManaBonus;
		Dest.Type = pIntType;
		return true;
	case EnduranceBonus:
		Dest.DWord = pChar->EnduranceBonus;
		Dest.Type = pIntType;
		return true;
	case CombatEffectsBonus:
	{
		DWORD CombatEffectsCap = GetModCap(HEROIC_MOD_COMBAT_EFFECTS);
		Dest.DWord = (pChar->CombatEffectsBonus > CombatEffectsCap ? CombatEffectsCap : pChar->CombatEffectsBonus);
		Dest.Type = pIntType;
		return true;
	}
	case ShieldingBonus:
	{
		DWORD ShieldingCap = GetModCap(HEROIC_MOD_MELEE_SHIELDING);
		Dest.DWord = (pChar->ShieldingBonus > ShieldingCap ? ShieldingCap : pChar->ShieldingBonus);
		Dest.Type = pIntType;
		return true;
	}
	case SpellShieldBonus:
	{
		DWORD SpellShieldCap = GetModCap(HEROIC_MOD_SPELL_SHIELDING);
		Dest.DWord = (pChar->SpellShieldBonus > SpellShieldCap ? SpellShieldCap : pChar->SpellShieldBonus);
		Dest.Type = pIntType;
		return true;
	}
	case AvoidanceBonus:
	{
		DWORD AvoidanceCap = GetModCap(HEROIC_MOD_AVOIDANCE);
		Dest.DWord = (pChar->AvoidanceBonus > AvoidanceCap ? AvoidanceCap : pChar->AvoidanceBonus);
		Dest.Type = pIntType;
		return true;
	}
	case AccuracyBonus:
	{
		DWORD AccuracyCap = GetModCap(HEROIC_MOD_ACCURACY);
		Dest.DWord = (pChar->AccuracyBonus > AccuracyCap ? AccuracyCap : pChar->AccuracyBonus);
		Dest.Type = pIntType;
		return true;
	}
	case StunResistBonus:
	{
		DWORD StunResistCap = GetModCap(HEROIC_MOD_STUN_RESIST);
		Dest.DWord = (pChar->StunResistBonus > StunResistCap ? StunResistCap : pChar->StunResistBonus);
		Dest.Type = pIntType;
		return true;
	}
	case StrikeThroughBonus:
	{
		DWORD StrikeThroughCap = GetModCap(HEROIC_MOD_STRIKETHROUGH);
		Dest.DWord = (pChar->StrikeThroughBonus > StrikeThroughCap ? StrikeThroughCap : pChar->StrikeThroughBonus);
		Dest.Type = pIntType;
		return true;
	}
	case DoTShieldBonus:
	{
		DWORD DoTShieldCap = GetModCap(HEROIC_MOD_DOT_SHIELDING);
		Dest.DWord = (pChar->DoTShieldBonus > DoTShieldCap ? DoTShieldCap : pChar->DoTShieldBonus);
		Dest.Type = pIntType;
		return true;
	}
	case AttackBonus:
		Dest.DWord = pChar->AttackBonus;
		Dest.Type = pIntType;
		return true;
	case HPRegenBonus:
		Dest.DWord = pChar->HPRegenBonus;
		Dest.Type = pIntType;
		return true;
	case ManaRegenBonus:
		Dest.DWord = pChar->ManaRegenBonus;
		Dest.Type = pIntType;
		return true;
	case DamageShieldBonus:
	{
		DWORD DamageShieldCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELDING);
		Dest.DWord = (pChar->DamageShieldBonus > DamageShieldCap ? DamageShieldCap : pChar->DamageShieldBonus);
		Dest.Type = pIntType;
		return true;
	}
	case DamageShieldMitigationBonus:
	{
		DWORD DamageShieldMitigationCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELD_MITIG);
		Dest.DWord = (pChar->DamageShieldMitigationBonus > DamageShieldMitigationCap ? DamageShieldMitigationCap : pChar->DamageShieldMitigationBonus);
		Dest.Type = pIntType;
		return true;
	}
	case HeroicSTRBonus:
		Dest.DWord = pChar->HeroicSTRBonus;
		Dest.Type = pIntType;
		return true;
	case HeroicINTBonus:
		Dest.DWord = pChar->HeroicINTBonus;
		Dest.Type = pIntType;
		return true;
	case HeroicWISBonus:
		Dest.DWord = pChar->HeroicWISBonus;
		Dest.Type = pIntType;
		return true;
	case HeroicAGIBonus:
		Dest.DWord = pChar->HeroicAGIBonus;
		Dest.Type = pIntType;
		return true;
	case HeroicDEXBonus:
		Dest.DWord = pChar->HeroicDEXBonus;
		Dest.Type = pIntType;
		return true;
	case HeroicSTABonus:
		Dest.DWord = pChar->HeroicSTABonus;
		Dest.Type = pIntType;
		return true;
	case HeroicCHABonus:
		Dest.DWord = pChar->HeroicCHABonus;
		Dest.Type = pIntType;
		return true;
	case HealAmountBonus:
		Dest.DWord = pChar->HealAmountBonus;
		Dest.Type = pIntType;
		return true;
	case SpellDamageBonus:
		Dest.DWord = pChar->SpellDamageBonus;
		Dest.Type = pIntType;
		return true;
	case ClairvoyanceBonus:
		Dest.DWord = pChar->ClairvoyanceBonus;
		Dest.Type = pIntType;
		return true;
	case EnduranceRegenBonus:
		Dest.DWord = pChar->EnduranceRegenBonus;
		Dest.Type = pIntType;
		return true;
	case AttackSpeed:
		Dest.DWord = pChar->AttackSpeed;
		Dest.Type = pIntType;
		return true;
	case Endurance:  //Grandfathered, CurrentEndurance should be used instead.
	case CurrentEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Endurance;
		}
		return true;
	case MaxEndurance:
		Dest.DWord = GetMaxEndurance();
		Dest.Type = pIntType;
		return true;
	case PctEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (unsigned long Temp = GetMaxEndurance()) {
				Dest.DWord = (pChar2->Endurance * 100) / Temp;
			}
		}
		return true;
	case GukEarned:
		Dest.DWord = 0;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_DeepGuk].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;
	case MMEarned:
		Dest.DWord = 0;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Mistmoore].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;
	case RujEarned:
		Dest.DWord = 0;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Rujarkian].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;
	case TakEarned:
		Dest.DWord = 0;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Takish].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;
	case MirEarned:
		Dest.DWord = 0;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Miraguls].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;
	case LDoNPoints:
		Dest.DWord = 0;
#ifdef NEWCHARINFO
		if (PCHARINFO pCharnew = GetCharInfo()) {
#else
		if (PCHARINFONEW pCharnew = (PCHARINFONEW)GetCharInfo()) {
#endif
			Dest.DWord = pCharnew->AdventureData.AdventurePointsAvailable;
		}
		Dest.Type = pIntType;
		return true;
	case CurrentFavor:
		Dest.Int64 = pChar->CurrFavor;
		Dest.Type = pInt64Type;
		return true;
	case CareerFavor:
		Dest.Int64 = pChar->CareerFavor;
		Dest.Type = pInt64Type;
		return true;
	case Inventory:
		Dest.Type = pItemType;
		if (ISINDEX())
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2()) {
				if (ISNUMBER())
				{
					unsigned long nSlot = GETNUMBER();
					if (nSlot < 33)
					{
						if (pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
							if (Dest.Ptr = pChar2->pInventoryArray->InventoryArray[nSlot])
							{
								return true;
							}
						}
					}
				}
				else
				{
					for (unsigned long nSlot = 0; szItemSlot[nSlot]; nSlot++)
					{
						if (!_stricmp(GETFIRST(), szItemSlot[nSlot]))
						{
							if (pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
								if (Dest.Ptr = pChar2->pInventoryArray->InventoryArray[nSlot])
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	case Bank:
		Dest.Type = pItemType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				int nSlot = GETNUMBER() - 1;
				if (nSlot < 0)
					return false;
				if (nSlot<NUM_BANK_SLOTS)
				{
					if (pChar && pChar->BankItems.Items.Size > (UINT)nSlot) {
						if (Dest.Ptr = pChar->BankItems.Items[nSlot].pObject)
						{
							return true;
						}
					}
				}
				else {
					nSlot -= NUM_BANK_SLOTS;
					if (nSlot<NUM_SHAREDBANK_SLOTS)
					{
						if (pChar && pChar->SharedBankItems.Items.Size > (UINT)nSlot) {
							if (Dest.Ptr = pChar->SharedBankItems.Items[nSlot].pObject)
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case PlatinumShared:
		Dest.DWord = pChar->BankSharedPlat;
		Dest.Type = pIntType;
		return true;
	case Cash:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Plat * 1000 + pChar2->Gold * 100 + pChar2->Silver * 10 + pChar2->Copper;
		}
		Dest.Type = pIntType;
		return true;
	case Platinum:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Plat;
		}
		Dest.Type = pIntType;
		return true;
	case CursorPlatinum:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->CursorPlat;
		}
		Dest.Type = pIntType;
		return true;
	case Gold:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Gold;
		}
		Dest.Type = pIntType;
		return true;
	case CursorGold:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->CursorGold;
		}
		Dest.Type = pIntType;
		return true;
	case Silver:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Silver;
		}
		Dest.Type = pIntType;
		return true;
	case CursorSilver:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->CursorSilver;
		}
		Dest.Type = pIntType;
		return true;
	case Copper:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Copper;
		}
		Dest.Type = pIntType;
		return true;
	case CursorCopper:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->CursorCopper;
		}
		Dest.Type = pIntType;
		return true;
	case CashBank:
		Dest.DWord = pChar->BankPlat * 1000 + pChar->BankGold * 100 + pChar->BankSilver * 10 + pChar->BankCopper;
		Dest.Type = pIntType;
		return true;
	case PlatinumBank:
		Dest.DWord = pChar->BankPlat;
		Dest.Type = pIntType;
		return true;
	case GoldBank:
		Dest.DWord = pChar->BankGold;
		Dest.Type = pIntType;
		return true;
	case SilverBank:
		Dest.DWord = pChar->BankSilver;
		Dest.Type = pIntType;
		return true;
	case CopperBank:
		Dest.DWord = pChar->BankCopper;
		Dest.Type = pIntType;
		return true;
	case AAExp:
		Dest.DWord = pChar->AAExp;
		Dest.Type = pIntType;
		return true;
	case AAPoints:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->AAPoints;
		}
		Dest.Type = pIntType;
		return true;
	case Combat:
		Dest.DWord = *EQADDR_ATTACK;
		Dest.Type = pBoolType;
		return true;
	case HPRegen:
		Dest.DWord = GetHPRegen();
		Dest.Type = pIntType;
		return true;
	case ManaRegen:
		Dest.DWord = GetManaRegen();
		Dest.Type = pIntType;
		return true;
	case EnduranceRegen:
		Dest.DWord = GetEnduranceRegen();
		Dest.Type = pIntType;
		return true;
	case Grouped:
		Dest.Type = pBoolType;
		Dest.DWord = 0;
		if (!pChar->pGroupInfo)
			return true;
		Dest.DWord = pChar->pGroupInfo->pMember[1] ||
			pChar->pGroupInfo->pMember[2] ||
			pChar->pGroupInfo->pMember[3] ||
			pChar->pGroupInfo->pMember[4] ||
			pChar->pGroupInfo->pMember[5];
		return true;
	case GroupList: // This isn't really working as intended just yet
	{
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo) return false;
		for (int i = 1; i < 6; i++)
			if (pChar->pGroupInfo->pMember[i])
			{
				char tmp[MAX_STRING] = { 0 };
				DataTypeTemp[0] = '\0';
				GetCXStr(pChar->pGroupInfo->pMember[i]->pName, tmp, MAX_STRING);
				strcat_s(DataTypeTemp, tmp);
				if (i < 5 && pChar->pGroupInfo->pMember[i + 1])
					strcat_s(DataTypeTemp, " ");
			}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}
	case AmIGroupLeader:
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo) return false;
		if (!pChar->pGroupInfo->pLeader) return false;
		GetCXStr(pChar->pGroupInfo->pLeader->pName, DataTypeTemp, sizeof(DataTypeTemp));
		if (!_stricmp(DataTypeTemp, pChar->Name))
			strcpy_s(DataTypeTemp, "TRUE");
		else
			strcpy_s(DataTypeTemp, "FALSE");
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case MaxBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;
		return true;
	case FreeBuffSlots:
		Dest.DWord = 15;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = GetCharMaxBuffSlots();
			for (int nBuff = 0; nBuff < NUM_LONG_BUFFS; nBuff++)
			{
				if (pChar2->Buff[nBuff].SpellID>0)
					Dest.DWord--;
			}
		}
		Dest.Type = pIntType;
		return true;
	case Gem:
		Dest.Type = pSpellType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			// number
			int nGem = GETNUMBER() - 1;
			if (nGem < 0)
				return false;
			if (nGem<NUM_SPELL_GEMS)
			{
				if (Dest.Ptr = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					Dest.Type = pSpellType;
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (PSPELL pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(GETFIRST(), pSpell->Name))
					{
						Dest.DWord = nGem + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;
	case LanguageSkill:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		int nLang = 0;
		if (!ISINDEX())
			return false;

		if (ISNUMBER()) {
			nLang = GETNUMBER() - 1;
			if (nLang < 0)
				return false;
		}
		else {
			nLang = GetLanguageIDByName(GETFIRST()) - 1;
		}
		if (nLang < 0 || nLang >= 25)
			return false;

		Dest.DWord = pChar->languages[nLang];
		return true;
	}
	case CombatAbility:
		Dest.Type = pSpellType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			// number
			int abnum = GETNUMBER();
			if (abnum <= 0)
				abnum = 1;
			int nCombatAbility = abnum - 1;
			if (nCombatAbility < NUM_COMBAT_ABILITIES) {
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
					if (PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						Dest.Ptr = pSpell;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
		}
		else
		{
			// name
			for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
					if (PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						if (!_stricmp(GETFIRST(), pSpell->Name))
						{
							Dest.DWord = nCombatAbility + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;
	case CombatAbilityTimer:
		Dest.Int = 0;
		Dest.Type = pTicksType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				// number
				int nCombatAbility = GETNUMBER() - 1;
				if (nCombatAbility < 0)
					return false;
				if (nCombatAbility < NUM_COMBAT_ABILITIES) {
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							DWORD timeNow = (DWORD)time(NULL);
							DWORD timer = timeNow;
							#if !defined(ROF2EMU) && !defined(UFEMU)
							timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);
							if (timer > timeNow)
							#else
							if (pSpell->ReuseTimerIndex == -1 || pSpell->ReuseTimerIndex > 20)
							{
								//if we don't check this on emu servers we will crash
								//the fix should happen on the server but no one has fixed it so...
								return true;
							}
							timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex);
							if (timer > timeNow)
							#endif
							{
								Dest.Int = timer - timeNow + 6;
								if(Dest.Int != 0)
									Dest.Int /= 6;
							}
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(GETFIRST(), pSpell->Name))
							{
								DWORD timeNow = (DWORD)time(NULL);
								DWORD timer = timeNow;
								#if !defined(ROF2EMU) && !defined(UFEMU)
								timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);
								if (timer > timeNow)
								#else
								if (pSpell->ReuseTimerIndex == -1 || pSpell->ReuseTimerIndex > 20)
								{
									return true;
								}
								timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex);
								if (timer > timeNow)
								#endif
								{
									Dest.Int = timer - timeNow + 6;
									if(Dest.Int != 0)
										Dest.Int /= 6;
								}
								return true;
							}
						}
					}
				}
			}
		}
		return true;
	case CombatAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			if (ISNUMBER()) {
				// number
				int nCombatAbility = GETNUMBER() - 1;
				if (nCombatAbility<0)
					return false;
				if (nCombatAbility < NUM_COMBAT_ABILITIES) {
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							DWORD timeNow = (DWORD)time(NULL);
							DWORD timer = timeNow;
							#if !defined(ROF2EMU) && !defined(UFEMU)
							timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);
							if (timer < timeNow)
							#else
							if (pSpell->ReuseTimerIndex == -1 || pSpell->ReuseTimerIndex > 20)
							{
								Dest.DWord = 1;
								return true;
							}
							timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex);
							if (timer < timeNow)
							#endif
							{
								Dest.DWord = 1;
								return true;
							}
						}
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(GETFIRST(), pSpell->Name))
							{
								DWORD timeNow = (DWORD)time(NULL);
								DWORD timer = timeNow;
								#if !defined(ROF2EMU) && !defined(UFEMU)
								timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);
								if (timer < timeNow)
								#else
								if (pSpell->ReuseTimerIndex == -1 || pSpell->ReuseTimerIndex > 20)
								{
									Dest.DWord = 1;
									return true;
								}
								timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex);
								if (timer < timeNow)
								#endif
								{
									Dest.DWord = 1;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return true;
	case ActiveDisc:
		Dest.Type = pSpellType;
		if (pCombatAbilityWnd) {
			if (CXWnd *Child = ((CXWnd*)pCombatAbilityWnd)->GetChildItem("CAW_CombatEffectLabel")) {
				CHAR szBuffer[2048] = { 0 };
				if (GetCXStr(Child->CGetWindowText(), szBuffer, MAX_STRING) && szBuffer[0] != '\0') {
					if (Dest.Ptr = GetSpellByName(szBuffer)) {
						return true;
					}
				}
			}
		}
		return false;
	case Moving:
		Dest.DWord = false;
		if (pCharSpawn && pChar && pChar->pSpawn) {
			Dest.DWord = ((((gbMoving) && ((PSPAWNINFO)pCharSpawn)->SpeedRun == 0.0f) && (pChar->pSpawn->Mount == NULL)) || (fabs(FindSpeed((PSPAWNINFO)pCharSpawn)) > 0.0f));
		}
		Dest.Type = pBoolType;
		return true;
	case Hunger:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->hungerlevel;
		}
		Dest.Type = pIntType;
		return true;
	case Thirst:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->thirstlevel;
		}
		Dest.Type = pIntType;
		return true;
	case AltAbilityTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (ISINDEX()) {
			if (ISNUMBER()) {
				//numeric
				for (unsigned long nAbility = 0; nAbility<AA_CHAR_MAX_REAL; nAbility++) {
					if (PALTABILITY pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility))) {
						if (pAbility->ID == GETNUMBER()) {
							int reusetimer = 0;
							pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
							if (reusetimer < 0) {
								reusetimer = 0;
							}
							Dest.UInt64 = reusetimer * 1000;
							return true;
						}
					}
				}
			}
			else {
				// by name so we ned to take level into account
				int level = -1;
				if (PSPAWNINFO pMe = (PSPAWNINFO)pLocalPlayer) {
					level = pMe->Level;
				}
				for (unsigned long nAbility = 0; nAbility<AA_CHAR_MAX_REAL; nAbility++) {
					if (PALTABILITY pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level)) {
						if (PCHAR pName = pCDBStr->GetString(pAbility->nName, 1, NULL)) {
							if (!_stricmp(GETFIRST(), pName)) {
								int reusetimer = 0;
								pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
								if (reusetimer < 0) {
									reusetimer = 0;
								}
								Dest.UInt64 = reusetimer * 1000;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case AltAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (ISINDEX()) {
			if (ISNUMBER()) {
				//numeric
				for (unsigned long nAbility = 0; nAbility<AA_CHAR_MAX_REAL; nAbility++) {
					if (PALTABILITY pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility))) {
						if (pAbility->ID == GETNUMBER()) {
							if (pAbility->SpellID != 0xFFFFFFFF)
								Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, 0);
							return true;
						}
					}
				}
			}
			else {
				// by name so we need to take their level into account
				int level = -1;
				if (PSPAWNINFO pMe = (PSPAWNINFO)pLocalPlayer) {
					level = pMe->Level;
				}
				for (unsigned long nAbility = 0; nAbility<AA_CHAR_MAX_REAL; nAbility++) {
					if (PALTABILITY pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility),level)) {
						if (PCHAR pName = pCDBStr->GetString(pAbility->nName, 1, NULL)) {
							if (!_stricmp(GETFIRST(), pName)) {
								if (pAbility->SpellID != 0xFFFFFFFF)
									Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, 0);
								return true;
							}
						}
					}
				}
			}
		}
		return true;
	case AltAbility:
		Dest.Type = pAltAbilityType;
		if (ISINDEX()) {
			if (ISNUMBER()) {
				//numeric
				for (unsigned long nAbility = 0; nAbility<AA_CHAR_MAX_REAL; nAbility++) {
					if (PALTABILITY pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility))) {
						if (pAbility->ID == GETNUMBER()) {
							Dest.Ptr = pAbility;
							return true;
						}
					}
				}
			}
			else {
				// by name so we need to take their level into account
				int level = -1;
				if (PSPAWNINFO pMe = (PSPAWNINFO)pLocalPlayer) {
					level = pMe->Level;
				}
				for (unsigned long nAbility = 0; nAbility<AA_CHAR_MAX_REAL; nAbility++) {
					if (PALTABILITY pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level)) {
						if (PCHAR pName = pCDBStr->GetString(pAbility->nName, 1, NULL)) {
							if (!_stricmp(GETFIRST(), pName)) {
								Dest.Ptr = pAbility;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case Skill:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2())
			{
				int nSkill = 0;

				if (ISNUMBER())
				{
					// numeric
					nSkill = GETNUMBER() - 1;
					if (nSkill < 0)
						return false;
				}
				else
				{
					// name
					for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
						if (!_stricmp(GETFIRST(), szSkills[nSkill]))
							break;
				}
				if (nSkill < NUM_SKILLS)
				{
					if (pChar2->Skill[nSkill])
					{
						Dest.DWord = GetAdjustedSkill(nSkill);
					}
					return true;
				}
			}
		}
		return false;
	case SkillBase:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2())
			{
				int nSkill = 0;

				if (ISNUMBER())
				{
					// numeric
					nSkill = GETNUMBER() - 1;
					if (nSkill < 0)
						return false;
				}
				else
				{
					// name
					for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
						if (!_stricmp(GETFIRST(), szSkills[nSkill]))
							break;
				}
				if (nSkill < NUM_SKILLS)
				{
					if (pChar2->Skill[nSkill])
					{
						Dest.DWord = GetBaseSkill(nSkill);
					}
					return true;
				}
			}
		}
		return false;
	case SkillCap:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ISINDEX())
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2())
			{
				int nSkill = 0;

				if (ISNUMBER())
				{
					// numeric
					nSkill = GETNUMBER() - 1;
					if (nSkill < 0)
						return false;
				}
				else
				{
					// name
					for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
						if (!_stricmp(GETFIRST(), szSkills[nSkill]))
							break;
				}
				if (nSkill < NUM_SKILLS)
				{
					if (PCHARINFO pCharInfo = GetCharInfo()) {
						Dest.DWord = pCSkillMgr->GetSkillCap((EQ_Character*)pCharInfo, pChar2->Level, pChar2->Class, nSkill, true, true, true);
						return true;
					}
				}
			}
		}
		return false;
	case AbilityTimer:
		Dest.Type = pTimeStampType;
		Dest.Int64 = 0;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				// numeric
				if (unsigned long nSkill = GETNUMBER())
				{
					if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
					{
						int calcedduration = pSkillMgr->SkillTimerDuration[nSkill] - (EQGetTime() - pSkillMgr->SkillLastUsed[nSkill]);
						if (calcedduration < 0)
							calcedduration = 0;
						Dest.Int64 = calcedduration;
						return true;
					}
				}
				return false;
			}
			else
			{
				// name
				for (int nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					DWORD nToken = pCSkillMgr->GetNameToken(nSkill);
					if (char *thename = pStringTable->getString(nToken, 0)) {
						if (!_stricmp(GETFIRST(), thename))
						{
							//bool bAvail = pCSkillMgr->IsAvailable(i);
							if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
							{
								int calcedduration = pSkillMgr->SkillTimerDuration[nSkill] - (EQGetTime() - pSkillMgr->SkillLastUsed[nSkill]);
								if (calcedduration < 0)
									calcedduration = 0;
								Dest.Int64 = calcedduration;
								return true;
							}
							break;;
						}
					}
				}
			}
		}
		return false;
	case Ability:
		Dest.Type = pStringType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				// numeric
				if (unsigned long nSkill = GETNUMBER())
				{
					if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
					{
						//DWORD bAvail = pCSkillMgr->IsAvailable(nSkill);

						DWORD nToken = pCSkillMgr->GetNameToken(nSkill);
						if (char *thename = pStringTable->getString(nToken, 0)) {
							//WriteChatf("[%d] %s bAvail = %d bActivated = %d", nSkill, thename, bAvail, bActivated);
							strcpy_s(DataTypeTemp, thename);
							Dest.Ptr = &DataTypeTemp[0];
							Dest.Type = pStringType;
							return true;
						}
					}
				}
				return false;
			}
			else
			{
				// name
				for(int i=0;i<NUM_SKILLS;i++) {
					DWORD nToken = pCSkillMgr->GetNameToken(i);
					if(char *thename = pStringTable->getString(nToken,0)) {
						if (!_stricmp(GETFIRST(), thename))
						{
							//bool bAvail = pCSkillMgr->IsAvailable(i);
							if (bool bActivated = pCSkillMgr->IsActivatedSkill(i))
							{
								//WriteChatf("[%d] %s Available = %d Activated = %d", i, thename, bAvail, bActivated);
								Dest.DWord = i;
								Dest.Type = pIntType;
								return true;
							}
							break;
						}
					}
				}
			}
		}
		return false;
	case AbilityReady:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				// numeric
				if (unsigned long nSkill = GETNUMBER())
				{
					if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
					{
						Dest.DWord = pCSkillMgr->IsAvailable(nSkill);
					}
				}
				return true;
			}
			else
			{
				// name

				for (int i = 0; i < NUM_SKILLS; i++) {
					DWORD nToken = pCSkillMgr->GetNameToken(i);
					if (char *thename = pStringTable->getString(nToken, 0)) {
						if (!_stricmp(GETFIRST(), thename))
						{
							if (bool bActivated = pCSkillMgr->IsActivatedSkill(i))
							{
								Dest.DWord = pCSkillMgr->IsAvailable(i);
							}
							break;
						}
					}
				}
				return true;
				//i dont think we need all this crap... the above code should be enough... -eqmule
				/*for (DWORD nSkill = 0; szSkills[nSkill]; nSkill++)
				{
					if (!_stricmp(GETFIRST(), szSkills[nSkill]))
					{
						// found name
						//for (DWORD nAbility = 0; nAbility<10; nAbility++)
						{
							//why do we check this? it only has abilites we assigned to hotbuttons in it...
							//so if we don't have for example taunt assigned, a check for it will fail...
							//im commenting it out for now, lets see if problems arise.
							//if (EQADDR_DOABILITYLIST[nAbility] == nSkill)
							{
								// thanks s0rcier!
								if (nSkill<100 || nSkill == 111 || nSkill == 114 || nSkill == 115 || nSkill == 116)
								{
									//if (pSkillMgr->pSkill[nSkill]->AltTimer==2) // this check is included in CSkillMgr::IsAvailable
									//    Dest.DWord=gbAltTimerReady;
									//else
									Dest.DWord = pCSkillMgr->IsAvailable(nSkill);
									//Dest.DWord = pCSkillMgr->IsAvailable(EQADDR_DOABILITYLIST[nAbility]);
									Dest.Type = pBoolType;
									return true;
								}
								//if (nSkill==111) { // this check is included in CSkillMgr::IsAvailable
								//    Dest.DWord=gbAltTimerReady;
								//    Dest.Type=pBoolType;
								//    return true;
								//}
								if (nSkill == 105 || nSkill == 107) {
									Dest.DWord = LoH_HT_Ready();
									Dest.Type = pBoolType;
									return true;
								}
								return false;
							}
						}
					}
				}*/
			}
		}
		return false;
	case RangedReady:
		Dest.DWord = gbRangedAttackReady;
		Dest.Type = pBoolType;
		return true;
	case AltTimerReady:
		Dest.DWord = 1;//this is broken and should be fixed or removed.
		Dest.Type = pBoolType;
		return true;
	case Book:
		Dest.Type = pSpellType;
		if (ISINDEX())
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2()) {
				if (ISNUMBER())
				{
					// numeric
					int nSpell = GETNUMBER() - 1;
					if (nSpell < 0)
						return false;
					if (nSpell < NUM_BOOK_SLOTS)
						if (Dest.Ptr = GetSpellByID(pChar2->SpellBook[nSpell]))
						{
							Dest.Type = pSpellType;
							return true;
						}
				}
				else
				{
					// name
					for (DWORD nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++) {
						if (pChar2->SpellBook[nSpell] != 0xFFFFFFFF)
						{
							if (!_stricmp(GetSpellNameByID(pChar2->SpellBook[nSpell]), GETFIRST()))
							{
								Dest.DWord = nSpell + 1;
								Dest.Type = pIntType;
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case Spell:
	{
		Dest.Type = pSpellType;
		if (ISINDEX())
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2())
			{
				if (ISNUMBER())
				{
					// Look for spell in our book by ID
					LONG spellID = GETNUMBER();
					for (DWORD nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
					{
						if (pChar2->SpellBook[nSpell] == spellID)
						{
							Dest.Ptr = GetSpellByID(spellID);
							return true;
						}
					}
				}
				else
				{
					// Look for spell in our book by Name like ${Spell}
					if (PSPELL pSpell = GetSpellByName(GETFIRST()))
					{
						// If we found a spell check if its in the spellbook
						int spellID = pSpell->ID;

						for (DWORD nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
						{
							if (pChar2->SpellBook[nSpell] == spellID)
							{
								Dest.Ptr = pSpell;
								return true;
							}
						}

						// Ok it is not in the spell book. Lets check for other forms
						// This is similar to the last part of SpellRank.
						for (DWORD nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
						{
							if (pChar2->SpellBook[nSpell] != -1)
							{
								if (PSPELL pFoundSpell = GetSpellByID(pChar2->SpellBook[nSpell]))
								{
									if (pFoundSpell->SpellGroup == pSpell->SpellGroup
										&& !_strnicmp(pSpell->Name, pFoundSpell->Name, strlen(pSpell->Name)))
									{
										Dest.Ptr = pFoundSpell;
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
		return false;
	}

	case ItemReady:
	{
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		PCONTENTS pCont = 0;
		if (pDisplay && pLocalPlayer && ISINDEX()) {
			if (ISNUMBER()) {
				pCont = FindItemByID(GETNUMBER());
			}
			else {
				if (PCHAR pName = GETFIRST()) {
					BOOL bExact = false;
					if (*pName == '=') {
						bExact = true;
						pName++;
					}
					pCont = FindItemByName(pName, bExact);
				}
			}
			if (pCont) {
				if (PITEMINFO pIteminf = GetItemFromContents(pCont)) {
					if (pIteminf->Clicky.TimerID != -1)	{
						DWORD timer = GetItemTimer(pCont);
						if (timer == 0)
							Dest.DWord = 1;
					}
					else if (pIteminf->Clicky.SpellID != -1)
					{
						Dest.DWord = 1; // insta-click or instant recast
					}
				}
			}
		}
		return true;
	}
	case BardSongPlaying:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying()) {
			Dest.DWord = 1;
		}
		return true;
	case SpellReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastingWnd && pCastingWnd->IsVisible()) {
			return true;
		}
		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying()) {
			Dest.DWord = 1;
			return true;
		}
		if (pDisplay && pLocalPlayer && ISINDEX())
		{

			if (ISNUMBER())
			{
				// numeric
				int nGem = GETNUMBER() - 1;
				if (nGem < 0 || nGem > NUM_SPELL_GEMS)
					return false;
				if (GetSpellByID(GetMemorizedSpell(nGem))) {
					if (((PCDISPLAY)pDisplay)->TimeStamp > ((PSPAWNINFO)pLocalPlayer)->SpellGemETA[nGem] && (int)((PCDISPLAY)pDisplay)->TimeStamp > ((PSPAWNINFO)pLocalPlayer)->GetSpellCooldownETA()) {
						Dest.DWord = 1;
					}
					return true;
				}
			}
			else
			{
				for (unsigned long nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
				{
					if (PSPELL pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
					{
						if (!_stricmp(GETFIRST(), pSpell->Name))
						{
							if (((PCDISPLAY)pDisplay)->TimeStamp > ((PSPAWNINFO)pLocalPlayer)->SpellGemETA[nGem] && (int)((PCDISPLAY)pDisplay)->TimeStamp > ((PSPAWNINFO)pLocalPlayer)->GetSpellCooldownETA()) {
								Dest.DWord = 1;
							}
							return true;
						}
					}
				}
			}
		}
		return true;
	case PetBuff:
		Dest.Type = pSpellType;
		if (!ISINDEX() || !pPetInfoWnd)
			return false;
#define pPetInfoWindow ((PEQPETINFOWINDOW)pPetInfoWnd)
		if (ISNUMBER())
		{
			int nBuff = GETNUMBER() - 1;
			if (nBuff < 0)
				return false;
			if (nBuff>NUM_BUFF_SLOTS)
				return false;
			if (pPetInfoWindow->Buff[nBuff] == 0xFFFFFFFF || pPetInfoWindow->Buff[nBuff] == 0)
				return false;
			if (Dest.Ptr = GetSpellByID(pPetInfoWindow->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (unsigned long nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (PSPELL pSpell = GetSpellByID(pPetInfoWindow->Buff[nBuff]))
				{
					if (!_stricmp(GETFIRST(), pSpell->Name))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
#undef pPetInfoWindow
		return false;
	case Stunned:
		Dest.DWord = (pChar->Stunned == 1);
		Dest.Type = pBoolType;
		return true;
	case LargestFreeInventory:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray) {
				for (int slot = BAG_SLOT_START; slot < GetCurrentInvSlots(); slot++)
				{
					if (PCONTENTS pItem = pChar2->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK && GetItemFromContents(pItem)->SizeCapacity>Dest.DWord)
						{
							for (DWORD pslot = 0; pslot < (GetItemFromContents(pItem)->Slots); pslot++)
							{
								if (!pItem->Contents.ContainedItems.pItems || !pItem->GetContent(pslot))
								{
									Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
									break;// break the loop for this pack
								}
							}
						}
					}
					else
					{
						Dest.DWord = 4;
						return true;
					}
				}
			}
		}
		return true;
	}
	case FreeInventory:
	{
		DWORD nSize = 0;
		if (ISINDEX()) {
			DWORD nSize = GETNUMBER();
			if (nSize > 4)
				nSize = 4;
		}
		Dest.DWord = GetFreeInventory(nSize);
		Dest.Type = pIntType;
		return true;
	}
	case Drunk:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Drunkenness;
		}
		Dest.Type = pIntType;
		return true;
	case TargetOfTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer && pChar->pSpawn)
			if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->TargetOfTarget)) {
				return true;
			}
		return false;
	case RaidAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer)
			if (ISINDEX() && ISNUMBER()) {
				int N = GETNUMBER() - 1;
				if (N < 0)
					return false;
				if (N >= 3)
					return false;
				if (Dest.Ptr = (PSPAWNINFO)GetSpawnByID(GetRaidMainAssistTargetID(N))) {
					return true;
				}
			}
		return false;
	case GroupAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			if (Dest.Ptr = (PSPAWNINFO)GetSpawnByID(GetGroupMainAssistTargetID())) {
				return true;
			}
		}
		return false;
	case RaidMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
			if (ISINDEX() && ISNUMBER())
			{
				int N = GETNUMBER() - 1;
				if (N < 0)
					return false;
				if (N >= 3)
					return false;
				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->RaidMarkNPC[N]))
				{
					return true;
				}
			}
		return false;
	case GroupMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
			if (ISINDEX() && ISNUMBER())
			{
				int N = GETNUMBER() - 1;
				if (N < 0)
					return false;
				if (N >= 3)
					return false;
				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->GroupMarkNPC[N]))
				{
					return true;
				}
			}
		return false;
	case STR:
		Dest.DWord = pChar->STR;
		Dest.Type = pIntType;
		return true;
	case STA:
		Dest.DWord = pChar->STA;
		Dest.Type = pIntType;
		return true;
	case AGI:
		Dest.DWord = pChar->AGI;
		Dest.Type = pIntType;
		return true;
	case DEX:
		Dest.DWord = pChar->DEX;
		Dest.Type = pIntType;
		return true;
	case WIS:
		Dest.DWord = pChar->WIS;
		Dest.Type = pIntType;
		return true;
	case INT:
		Dest.DWord = pChar->INT;
		Dest.Type = pIntType;
		return true;
	case CHA:
		Dest.DWord = pChar->CHA;
		Dest.Type = pIntType;
		return true;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case LCK:
		Dest.DWord = pChar->LCK;
		Dest.Type = pIntType;
		return true;
#endif
	case svMagic:
		Dest.DWord = pChar->SaveMagic;
		Dest.Type = pIntType;
		return true;
	case svFire:
		Dest.DWord = pChar->SaveFire;
		Dest.Type = pIntType;
		return true;
	case svCold:
		Dest.DWord = pChar->SaveCold;
		Dest.Type = pIntType;
		return true;
	case svPoison:
		Dest.DWord = pChar->SavePoison;
		Dest.Type = pIntType;
		return true;
	case svDisease:
		Dest.DWord = pChar->SaveDisease;
		Dest.Type = pIntType;
		return true;
	case CurrentWeight:
		Dest.DWord = pChar->CurrWeight;
		Dest.Type = pIntType;
		return true;
	case AAPointsSpent:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->AAPointsSpent;
		}
		Dest.Type = pIntType;
		return true;
	case AAPointsTotal:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->AAPointsSpent + pChar2->AAPoints;
		}
		Dest.Type = pIntType;
		return true;
	case AAPointsAssigned:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->AAPointsAssigned[0];
		}
		Dest.Type = pIntType;
		return true;
	case TributeActive:
		Dest.DWord = *pTributeActive;
		Dest.Type = pBoolType;
		return true;
	case Running:
		Dest.DWord = (*EQADDR_RUNWALKSTATE);
		Dest.Type = pBoolType;
		return true;
	case GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!pChar->pGroupInfo) return false;
		for (int i = 1; i<6; i++)
			if (pChar->pGroupInfo->pMember[i]) Dest.DWord++;
		if (Dest.DWord) Dest.DWord++;
		return true;
	case TributeTimer:
		Dest.DWord = pChar->TributeTimer / 60 / 100;
		Dest.Type = pTicksType;
		return true;
	case RadiantCrystals:
		Dest.DWord = pChar->RadiantCrystals;
		Dest.Type = pIntType;
		return true;
	case EbonCrystals:
		Dest.DWord = pChar->EbonCrystals;
		Dest.Type = pIntType;
		return true;
	case Shrouded:
		Dest.DWord = 0;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->Shrouded;
		}
		Dest.Type = pBoolType;
		return true;
	case AutoFire:
		Dest.DWord = gAutoFire;
		Dest.Type = pBoolType;
		return true;
	case Language:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		int nLang = 0;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			nLang = GETNUMBER() - 1;
			if (nLang < 0)
				return false;
			strcpy_s(DataTypeTemp, pEverQuest->GetLangDesc(nLang));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
			nLang = GetLanguageIDByName(GETFIRST()) - 1;
		if (nLang < 0 || nLang >= 25)
			return false;
		Dest.DWord = nLang;
		return true;
	}
	case Aura:
		Dest.Type = pAuraType;
		if (PAURAMGR pAura = (PAURAMGR)pAuraMgr)
		{
			if (pAura->NumAuras)
			{
				PAURAS pAuras = (PAURAS)(*pAura->pAuraInfo);
				if (ISINDEX())
				{
					DWORD n = 0;
					if (ISNUMBER())
					{
						n = GETNUMBER();
						if (n > pAura->NumAuras)
							return false;
						n--;
						Dest.Ptr = &pAuras->Aura[n];
						Dest.HighPart = n;
						return true;
					}
					else
					{
						for (n = 0; n < pAura->NumAuras; n++)
						{
							if (!_strnicmp(GETFIRST(), pAuras->Aura[n].Name, strlen(GETFIRST())))
							{
								Dest.Ptr = &pAuras->Aura[n];
								Dest.HighPart = n;
								return true;
							}
						}
					}
				}
				else
				{
					Dest.Ptr = &pAuras->Aura[0];
					Dest.HighPart = 0;
					return true;
				}
			}
		}
		return false;
	case LAMarkNPC:
		Dest.DWord = 3;//GetCharInfo()->ActiveAbilities.MarkNPC;
		Dest.Type = pIntType;
		return true;
	case LANPCHealth:
		Dest.DWord = 1;//=GetCharInfo()->ActiveAbilities.NPCHealth;
		Dest.Type = pIntType;
		return true;
	case LADelegateMA:
		Dest.DWord = 1;//GetCharInfo()->ActiveAbilities.DelegateMA;
		Dest.Type = pIntType;
		return true;
	case LADelegateMarkNPC:
		Dest.DWord = 1;//GetCharInfo()->ActiveAbilities.DelegateMarkNPC;
		Dest.Type = pIntType;
		return true;
	case LAInspectBuffs:
		Dest.DWord = 2;//GetCharInfo()->ActiveAbilities.InspectBuffs;
		Dest.Type = pIntType;
		return true;
	case LASpellAwareness:
		Dest.DWord = 1;//GetCharInfo()->ActiveAbilities.SpellAwareness;
		Dest.Type = pIntType;
		return true;
	case LAOffenseEnhancement:
		Dest.DWord = 5;//GetCharInfo()->ActiveAbilities.OffenseEnhancement;
		Dest.Type = pIntType;
		return true;
	case LAManaEnhancement:
		Dest.DWord = 3;//GetCharInfo()->ActiveAbilities.ManaEnhancement;
		Dest.Type = pIntType;
		return true;
	case LAHealthEnhancement:
		Dest.DWord = 3;//GetCharInfo()->ActiveAbilities.HealthEnhancement;
		Dest.Type = pIntType;
		return true;
	case LAHealthRegen:
		Dest.DWord = 3;//GetCharInfo()->ActiveAbilities.HealthRegen;
		Dest.Type = pIntType;
		return true;
	case LAFindPathPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;
	case LAHoTT:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;
	case ActiveFavorCost:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (*pTributeActive)
		{
			Dest.Int = pEQMisc->GetActiveFavorCost();
			return true;
		}
		return false;
	case CombatState:
		Dest.Type = pStringType;
		if (!pPlayerWnd)
			return false;
		switch (((PCPLAYERWND)pPlayerWnd)->CombatState)
		{
		case 0:
			if (((CXWnd*)pPlayerWnd)->GetChildItem("PW_CombatStateAnim"))
			{
				strcpy_s(DataTypeTemp, "COMBAT");
				break;
			}
			strcpy_s(DataTypeTemp, "NULL");
			break;
		case 1:
			strcpy_s(DataTypeTemp, "DEBUFFED");
			break;
		case 2:
			strcpy_s(DataTypeTemp, "COOLDOWN");
			break;
		case 3:
			strcpy_s(DataTypeTemp, "ACTIVE");
			break;
		case 4:
			strcpy_s(DataTypeTemp, "RESTING");
			break;
		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case svCorruption:
		Dest.DWord = pChar->SaveCorruption;
		Dest.Type = pIntType;
		return true;
	case svPrismatic:
		Dest.DWord = (pChar->SaveMagic + pChar->SaveFire + pChar->SaveCold + pChar->SavePoison + pChar->SaveDisease) / 5;
		Dest.Type = pIntType;
		return true;
	case svChromatic:
	{
		unsigned int lowSave;
		lowSave = pChar->SaveMagic;
		if (lowSave > pChar->SaveFire)
			lowSave = pChar->SaveFire;
		if (lowSave > pChar->SaveCold)
			lowSave = pChar->SaveCold;
		if (lowSave > pChar->SavePoison)
			lowSave = pChar->SavePoison;
		if (lowSave > pChar->SaveDisease)
			lowSave = pChar->SaveDisease;
		Dest.DWord = lowSave;
		Dest.Type = pIntType;
		return true;
	}
	case Doubloons:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DOUBLOONS);
		Dest.Type = pIntType;
		return true;
	case Orux:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ORUX);
		Dest.Type = pIntType;
		return true;
	case Phosphenes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHENES);
		Dest.Type = pIntType;
		return true;
	case Phosphites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHITES);
		Dest.Type = pIntType;
		return true;
	case Faycites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FAYCITES);
		Dest.Type = pIntType;
		return true;
	case Chronobines:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CHRONOBINES);
		Dest.Type = pIntType;
		return true;
	case Commemoratives:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_COMMEMORATIVE_COINS);
		Dest.Type = pIntType;
		return true;
	case Nobles:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_NOBLES);
		Dest.Type = pIntType;
		return true;
	case Fists:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FISTSOFBAYLE);
		Dest.Type = pIntType;
		return true;
	case EnergyCrystals:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENERGYCRYSTALS);
		Dest.Type = pIntType;
		return true;
	case PiecesofEight:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PIECESOFEIGHT);
		Dest.Type = pIntType;
		return true;
	case Fellowship:
		Dest.Type = pFellowshipType;
		if (pChar->pSpawn)
		{
			Dest.Ptr = &pChar->pSpawn->Fellowship;
			return true;
		}
		return false;
	case Downtime:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pChar->DowntimeStamp)
			Dest.DWord = ((pChar->Downtime - (GetFastTime() - pChar->DowntimeStamp)) / 6) + 1;
		return true;
	case Dar://returns combined number of spell and damage "absorbment"
		Dest.DWord = 0;//should probably split these into spell vs melee
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long k = 0; k < NUM_LONG_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[k].SpellID)) {
					if (pSpell->SpellType != 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 55 /*Absorb Damage*/ || attrib == 78 /*SpellShield*/
								|| attrib == 161 /*Mitigate Spell Damage*/ || attrib == 162 /*Mitigate Melee Damage*/
								|| attrib == 450 /*DoT Guard*/ || attrib == 451 /*Melee Threshold Guard*/
								|| attrib == 452 /*Spell Threshold Guard*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->Buff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->Buff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;
	case TotalCounters://this case adds all resist Counters and returns that, why is this useful?
		Dest.DWord = 0;//should we split these into 4? one for each debuff?
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long k = 0; k < NUM_LONG_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 35 /*Disease Counter*/ || attrib == 36 /*Poison*/ || attrib == 116 /*Curse*/ || attrib == 369/*Corruption*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->Buff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->Buff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
			for (unsigned long k = 0; k < NUM_SHORT_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->ShortBuff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 35 /*Disease Counter*/ || attrib == 36 /*Poison*/ || attrib == 116 /*Curse*/ || attrib == 369/*Corruption*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->ShortBuff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->ShortBuff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;
	case CountersDisease://this case adds all resist Counters and returns that, why is this useful?
		Dest.DWord = 0;//should we split these into 4? one for each debuff?
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long k = 0; k < NUM_LONG_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 35 /*Disease Counter*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->Buff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->Buff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
			for (unsigned long k = 0; k < NUM_SHORT_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->ShortBuff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 35 /*Disease Counter*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->ShortBuff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->ShortBuff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;
	case CountersPoison://this case adds all resist Counters and returns that, why is this useful?
		Dest.DWord = 0;//should we split these into 4? one for each debuff?
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long k = 0; k < NUM_LONG_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 36 /*Poison*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->Buff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->Buff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
			for (unsigned long k = 0; k < NUM_SHORT_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->ShortBuff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 36 /*Poison*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->ShortBuff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->ShortBuff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;
	case CountersCurse://this case adds all resist Counters and returns that, why is this useful?
		Dest.DWord = 0;//should we split these into 4? one for each debuff?
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long k = 0; k < NUM_LONG_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 116 /*Curse*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->Buff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->Buff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
			for (unsigned long k = 0; k < NUM_SHORT_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->ShortBuff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 116 /*Curse*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->ShortBuff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->ShortBuff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;
	case CountersCorruption://this case adds all resist Counters and returns that, why is this useful?
		Dest.DWord = 0;//should we split these into 4? one for each debuff?
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (unsigned long k = 0; k < NUM_LONG_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 369/*Corruption*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->Buff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->Buff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
			for (unsigned long k = 0; k < NUM_SHORT_BUFFS; k++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->ShortBuff[k].SpellID)) {
					if (pSpell->SpellType == 0) {
						LONG slots = GetSpellNumEffects(pSpell);
						for (LONG i = 0; i < slots; i++) {
							LONG attrib = GetSpellAttrib(pSpell, i);
							if (attrib == 369/*Corruption*/) {
								for (LONG j = 0; j < NUM_SLOTDATA; j++) {
									if (pChar2->ShortBuff[k].SlotData[j].Slot == i) {
										Dest.DWord += pChar2->ShortBuff[k].SlotData[j].Value;
									}
								}
							}
						}
					}
				}
			}
		}
		return true;
	case Mercenary:
		Dest.Type = pMercenaryType;
		if (pMercInfo && pMercInfo->MercSpawnId)
		{
			Dest.Ptr = GetSpawnByID(pMercInfo->MercSpawnId);
			return true;
		}
		else if (pMercInfo) {
			ZeroMemory(&MercenarySpawn, sizeof(MercenarySpawn));
			if (pMercInfo->HaveMerc == 1) {
				switch (pMercInfo->MercState)
				{
				case 0:
					strcpy_s(MercenarySpawn.Name, "DEAD");
					break;
				case 1:
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					break;
				default:
					strcpy_s(MercenarySpawn.Name, "NULL");
					break;
				}
				Dest.Ptr = &MercenarySpawn;
				return true;
			}
			else {
				if (pMercInfo->MercenaryCount >= 1) {
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
				else {
					strcpy_s(MercenarySpawn.Name, "NULL");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
			}
		}
		return false;
	case XTargetSlots:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ExtendedTargetList *xtm = pChar->pXTargetMgr) {
			Dest.DWord = xtm->XTargetSlots.Count;
		}
		return true;
	case XTAggroCount:
		Dest.DWord = 0;
		if (ExtendedTargetList *xtm = pChar->pXTargetMgr) {
			DWORD AggroPct = 100;
			if (ISNUMBER()) {
				AggroPct = GETNUMBER();
				if (AggroPct < 1 || AggroPct > 100) {
					AggroPct = 100;
				}
			}
			if (pAggroInfo) {
				for (int i = 0; i < xtm->XTargetSlots.Count; i++) {
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					DWORD spID = xts.SpawnID;
					if (spID && xts.xTargetType == XTARGET_AUTO_HATER) {
						if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(spID)) {
							if (pTarget && ((PSPAWNINFO)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;
							if (pSpawn->Type == SPAWN_NPC) {
								DWORD aggropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;
								//WriteChatf("Checking aggro on %s its %d",xta->pXTargetData[i].Name,agropct);
								if (aggropct < AggroPct) {
									Dest.DWord++;
								}
							}
						}
					}
				}
			}
		}
		Dest.Type = pIntType;
		return true;
	case XTHaterCount:
		Dest.DWord = 0;
		if (ExtendedTargetList *xtm = pChar->pXTargetMgr) {
			DWORD x = 0;
			if (pAggroInfo) {
				for (int i = 0; i < xtm->XTargetSlots.Count; i++) {
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					DWORD spID = xts.SpawnID;
					if (spID && xts.xTargetType == XTARGET_AUTO_HATER) {
						if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(spID)) {
							if (pTarget && ((PSPAWNINFO)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;
							if (pSpawn->Type == SPAWN_NPC) {
								Dest.DWord++;
							}
						}
					}
				}
			}
		}
		Dest.Type = pIntType;
		return true;
	case XTarget:
		Dest.DWord = 0;
		Dest.Type = pXTargetType;
		if (ExtendedTargetList *xtm = pChar->pXTargetMgr)
		{
			int n = 0;
			if (xtm->XTargetSlots.Count)
			{
				if (ISINDEX())
				{
					if (ISNUMBER())
					{
						int N = GETNUMBER();
						if (N > 0 && N <= (int)xtm->XTargetSlots.Count)
						{
							Dest.DWord = GETNUMBER() - 1;
							Dest.Type = pXTargetType;
							return true;
						}
					}
					else
					{
						for (n = 0; n < xtm->XTargetSlots.Count; n++)
						{
							XTARGETSLOT xts = xtm->XTargetSlots[n];
							if (xts.xTargetType && xts.XTargetSlotStatus && !_stricmp(GETFIRST(), xts.Name))
							{
								Dest.DWord = n;
								Dest.Type = pXTargetType;
								return true;
							}
						}
					}
				}
				else
				{
					DWORD x = 0;
					for (n = 0; n < xtm->XTargetSlots.Count; n++)
					{
						XTARGETSLOT xts = xtm->XTargetSlots[n];
						if (xts.xTargetType && xts.XTargetSlotStatus)
						{
							x++;
						}
					}
					Dest.DWord = x;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	case Haste:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO pCharInfo = GetCharInfo()) {
#ifdef NEWCHARINFO
			if (pCharInfo->PcClient_CharacterZoneClient_vfTable) {
#else
			if (pCharInfo->vtable2) {
#endif
				Dest.DWord = pCharData1->TotalEffect(0xb, true, 0, true, true);
				return true;
			}
		}
		return false;
	}
	case SPA:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			if (PCHARINFO pCharInfo = GetCharInfo()) {
#ifdef NEWCHARINFO
				if (pCharInfo->PcClient_CharacterZoneClient_vfTable) {
#else
				if (pCharInfo->vtable2) {
#endif
					Dest.DWord = pCharData1->TotalEffect(GETNUMBER(), true, 0, true, true);
					return true;
				}
			}
		}
		return false;
	}
	case MercenaryStance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (DWORD n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, 24, 0));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case GemTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			// number
			int nGem = GETNUMBER() - 1;
			if (nGem < 0)
				return false;
			if (nGem < NUM_SPELL_GEMS)
			{
				if (GetMemorizedSpell(nGem) != 0xFFFFFFFF)
				{
					Dest.UInt64 = GetSpellGemTimer(nGem);
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (PSPELL pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(GETFIRST(), pSpell->Name))
					{
						Dest.UInt64 = GetSpellGemTimer(nGem);
						return true;
					}
				}
			}
		}
		return false;
	case HaveExpansion:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			DWORD nExpansion = GETNUMBER();
			if (nExpansion > NUM_EXPANSIONS)
				return true;
			Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(nExpansion);
		}
		else
		{
			for (DWORD n = 0; n < NUM_EXPANSIONS; n++)
			{
				if (!_stricmp(GETFIRST(), szExpansions[n]))
				{
					Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(n + 1);
					return true;
				}
			}
		}
		return true;
	case PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;
	case SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;
	case SecondaryAggroPlayer:
		Dest.Type = pSpawnType;
		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;
	case AggroLock:
		Dest.Type = pSpawnType;
		if (pAggroInfo && pAggroInfo->AggroLockID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroLockID);
			return true;
		}
		return false;
	case ZoneBound:
		Dest.Type = pZoneType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (pChar2->BoundLocations[0].ZoneBoundID) {
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[pChar2->BoundLocations[0].ZoneBoundID];
				return true;
			}
		}
		return false;
	case ZoneBoundX:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.Float = pChar2->BoundLocations[0].ZoneBoundX;
		}
		return true;
	case ZoneBoundY:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.Float = pChar2->BoundLocations[0].ZoneBoundY;
		}
		return true;
	case ZoneBoundZ:
		Dest.Float = 0;
		Dest.Type = pFloatType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.Float = pChar2->BoundLocations[0].ZoneBoundZ;
		}
		return true;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case PctMercAAExp:
		Dest.Float = (float)((pChar->MercAAExp + 5) / 10);//yes this is how it looks like the client is doing it in the disasm...
		Dest.Type = pFloatType;
		return true;
	case MercAAExp:
		Dest.Int64 = pChar->MercAAExp;
		Dest.Type = pInt64Type;
		return true;
#endif
	case Krono:
		Dest.DWord = pChar->Krono;
		Dest.Type = pIntType;
		return true;
	case Subscription:
		strcpy_s(DataTypeTemp, "UNKNOWN");
		if (EQADDR_SUBSCRIPTIONTYPE && *EQADDR_SUBSCRIPTIONTYPE) {
			DWORD dwsubtype = *(DWORD *)EQADDR_SUBSCRIPTIONTYPE;
			if (dwsubtype) {
				BYTE subtype = *(BYTE*)dwsubtype;
				switch (subtype)
				{
				case 0:
					strcpy_s(DataTypeTemp, "FREE");
					break;
				case 1:
					strcpy_s(DataTypeTemp, "SILVER");
					break;
				case 2:
					strcpy_s(DataTypeTemp, "GOLD");
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case AltCurrency:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER()) {
			Dest.DWord = pPlayerPointManager->GetAltCurrency(GETNUMBER());
			return true;
		}
		else {
			int nCurrency = GetCurrencyIDByName(GETFIRST());
			if (nCurrency < 0)
				return false;
			Dest.DWord = pPlayerPointManager->GetAltCurrency(nCurrency);
			return true;
		}
		return false;
	case Slowed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(11, 0)) != -1)//Slowed
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Rooted:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(99, 0)) != -1)//Root
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Mezzed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(31, 0)) != -1)//Entrall
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Crippled:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Disempowering")) != -1)
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Maloed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage))) != -1)
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Tashed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySubCat("Resist Debuffs", 1 << Enchanter)) != -1)
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Snared:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(3, 0)) != -1)//Movement Rate
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Hasted:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(11, 1)) != -1)//Haste
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case LastZoned:
		Dest.UInt64 = LastEnteredZone;
		Dest.Type = pTimeStampType;
		return true;
	case Zoning:
	{
		if (LastEnteredZone == 0)//when people reload mq
		{
			LastEnteredZone = MQGetTickCount64();
			OldLastEnteredZone = LastEnteredZone;
		}
		bool bZoning = false;
		if (OldLastEnteredZone != LastEnteredZone)
		{
			OldLastEnteredZone = LastEnteredZone;
			bZoning = true;
		}
		Dest.DWord = bZoning;
		Dest.Type = pBoolType;
		return true;
	}
	case DSed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(59, 1)) != -1)//Damage Shield
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case RevDSed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(121, 1)) != -1)//Reverse Damage Shield
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Charmed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(22, 0)) != -1)//Charm
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Aego:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++) {
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
				{
					if (IsAegoSpell(pSpell)) {
						Dest.Ptr = &pChar2->Buff[nBuff];
						return true;
					}
				}
			}
		}
		return false;
	case Skin:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 46)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Focus:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = 0;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Shaman)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 87)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Shaman, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Regen:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(0, 1)) != -1)//HP Regen
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if ((((EQ_Spell *)pSpell)->SpellAffectBase(0) > 0) && (!IsSpellUsableForClass(pSpell, 1 << Beastlord)))
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffBySPA(0, 1, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Diseased:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(35, 0)) != -1)//Disease Counter
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
			if ((nBuff = GetSelfShortBuffBySPA(35, 0)) != -1)//Disease Counter
			{
				Dest.Ptr = &pChar2->ShortBuff[nBuff];
				return true;
			}
		}
		return false;
	case Poisoned:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(36, 0)) != -1)//Poison Counter
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
			if ((nBuff = GetSelfShortBuffBySPA(36, 0)) != -1)//Poison Counter
			{
				Dest.Ptr = &pChar2->ShortBuff[nBuff];
				return true;
			}
		}
		return false;
	case Cursed:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(116, 0)) != -1)//Curse Counter
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
			if ((nBuff = GetSelfShortBuffBySPA(116, 0)) != -1)//Curse Counter
			{
				Dest.Ptr = &pChar2->ShortBuff[nBuff];
				return true;
			}
		}
		return false;
	case Corrupted:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(369, 0)) != -1)//Corruption Counter
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
			if ((nBuff = GetSelfShortBuffBySPA(369, 0)) != -1)//Corruption Counter
			{
				Dest.Ptr = &pChar2->ShortBuff[nBuff];
				return true;
			}
		}
		return false;
	case Symbol:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Cleric)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 112)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Cleric, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Clarity:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(15, 1)) != -1)//Mana Regen
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if ((((EQ_Spell *)pSpell)->SpellAffectBase(15) > 0) && (IsSpellUsableForClass(pSpell, 1 << Enchanter)))
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffBySPA(15, 1, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Pred:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(95, 1 << Ranger)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 7)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((Dest.Int = GetSelfBuffByCategory(95, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Strength:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 47)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Brells:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Paladin)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 47)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Paladin, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case SV:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 59)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case SE:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 44)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(79, 1 << Beastlord, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case HybridHP:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 46)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Ranger, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Growth:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 141)
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetSelfBuffByCategory(45, 1 << Druid, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case Shining:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffByCategory(125, 1 << Cleric)) != -1)//
			{
				while (nBuff < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(pChar2->Buff[nBuff].SpellID))
					{
						if (GetSpellSubcategory(pSpell) == 62)
						{
							if (((EQ_Spell *)pSpell)->SpellAffectBase(162))
							{
								Dest.Ptr = &pChar2->Buff[nBuff];
								return true;
							}
						}
					}
					if ((nBuff = GetSelfBuffByCategory(125, 1 << Cleric, ++nBuff)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case InInstance:
		Dest.DWord = false;
		if (pLocalPlayer)
		{
			if (int zoneid = ((PSPAWNINFO)pLocalPlayer)->GetZoneID())
			{
				if (WORD instance = HIWORD(zoneid))
				Dest.DWord = true;
		}
		}
		Dest.Type = pBoolType;
		return true;
	case Instance:
		Dest.DWord = 0;
		if (pLocalPlayer)
			Dest.DWord = HIWORD(((PSPAWNINFO)pLocalPlayer)->GetZoneID());
		Dest.Type = pIntType;
		return true;
	case MercListInfo:
	{
		Dest.Type = pStringType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			DWORD nIndex = GETNUMBER();
			if (nIndex > pMercInfo->MercenaryCount)
				return false;
			std::map<DWORD, MercDesc>descmap;
			GetAllMercDesc(descmap);
			if (descmap.find(nIndex - 1) != descmap.end()) {
				strcpy_s(DataTypeTemp, descmap[nIndex - 1].Type.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			std::map<DWORD, MercDesc>descmap;
			GetAllMercDesc(descmap);
			for (std::map<DWORD, MercDesc>::iterator n = descmap.begin(); n != descmap.end(); n++)
			{
				if (!_stricmp(GETFIRST(), n->second.Type.c_str())) {
					Dest.DWord = n->first + 1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}
	case UseAdvancedLooting:
#if !defined(ROF2EMU) && !defined(UFEMU)
		Dest.DWord = pChar->UseAdvancedLooting;
#else
		Dest.DWord = 0;
#endif
		Dest.Type = pBoolType;
		return true;
	case SpellInCooldown:
		Dest.DWord = (int)((PCDISPLAY)pDisplay)->TimeStamp <= ((PSPAWNINFO)pLocalPlayer)->GetSpellCooldownETA();
		Dest.Type = pBoolType;
		return true;
	case AssistComplete:
		Dest.DWord = gbAssistComplete == 2;
		Dest.Type = pBoolType;
		return true;
	case NumGems:
		Dest.DWord = 8;
		if (pCastSpellWnd) {
			CHAR szWnd[32] = { 0 };
			for (int i = 8; i < NUM_SPELL_GEMS; i++) {
				sprintf_s(szWnd, "CSPW_Spell%d", i);
				if (CXWnd *wnd = (CXWnd *)pCastSpellWnd->GetChildItem(szWnd)) {
					if (wnd->IsVisible()==1) {
						Dest.DWord++;
					}
				}
			}
		}
		Dest.Type = pIntType;
		return true;
	case GuildID:
	{
#ifdef NEWCHARINFO
		Dest.UInt64 = pChar->GuildID.GUID;
#else
		Dest.UInt64 = pChar->GuildID;
#endif
		Dest.Type = pInt64Type;
		return true;
	}
	case ExpansionFlags:
		Dest.DWord = pChar->ExpansionFlags;
		Dest.Type = pIntType;
		return true;
	case BoundLocation:
		Dest.DWord = 0;
		Dest.Type = pWorldLocationType;
		if (ISNUMBER()) {
			int index = GETNUMBER();
			if (index < 0)
				index = 0;
			if (index > 4)
				index = 4;
			Dest.DWord = index;
			return true;
		}
		return false;
	#if !defined(ROF2EMU) && !defined(UFEMU)
	case AutoSkill:
		Dest.Type = pSkillType;
		if (ISNUMBER()) {
			int index = GETNUMBER();
			index--;
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;
			int skillid = gAutoSkill.Skill[index];
			if (skillid > 0 && skillid < NUM_SKILLS) {
				Dest.Ptr = &pSkillMgr->pSkill[skillid];
				return true;
			}
			return false;
		}
		return false;
	#endif
	case BaseSTR:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseSTR;
			return true;
		}
		return false;
	case BaseSTA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseSTA;
			return true;
		}
		return false;
	case BaseAGI:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseAGI;
			return true;
		}
		return false;
	case BaseDEX:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseDEX;
			return true;
		}
		return false;
	case BaseWIS:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseWIS;
			return true;
		}
		return false;
	case BaseINT:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseINT;
			return true;
		}
		return false;
	case BaseCHA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			Dest.DWord = pChar2->BaseCHA;
			return true;
		}
		return false;
	case Beneficial:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			for (int i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				if ((pChar2->Buff[i].SpellID == -1) || (pChar2->Buff[i].SpellID == 0))
					continue;
				if (PSPELL pSpell = GetSpellByID(pChar2->Buff[i].SpellID)) {
					if (pSpell->SpellType != 0)
					{
						Dest.Int = i;
						return true;
					}
				}
			}
		}
		return false;
	case CursorKrono:
		Dest.DWord = pChar->CursorKrono;
		Dest.Type = pIntType;
		return true;
#if !defined(UFEMU) && !defined(ROF2EMU)
	case MercAAPoints:
		Dest.DWord = pChar->MercAAPoints;
		Dest.Type = pIntType;
		return true;
	case MercAAPointsSpent:
		Dest.DWord = pChar->MercAAPointsSpent;
		Dest.Type = pIntType;
		return true;
#endif
#if !defined(UFEMU)
	case Bandolier:
		Dest.DWord = 0;
		Dest.Type = pBandolierType;
		if (PCHARINFO2 pChar2 = GetCharInfo2())
		{
			if (ISNUMBER()) {

				int index = GETNUMBER();
				index--;
				if (index < 0)
					index = 0;
				if (index > 19)
					index = 19;
				Dest.DWord = index;
				return true;
			}
			else
			{
				for (int index = 0; index < 20; index++)
				{
					if (!_stricmp(GETFIRST(), pChar2->Bandolier[index].Name)) {
						Dest.DWord = index;
						return true;
					}
				}
			}
		}
		return false;
#endif
	case Feared:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(23, 0)) != -1)//Feared
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Silenced:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(96, 0)) != -1)//Silenced
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
		}
		return false;
	case Invulnerable:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(40, 0)) != -1)//Invulnerable
			{
				Dest.Ptr = &pChar2->Buff[nBuff];
				return true;
			}
			if ((nBuff = GetSelfShortBuffBySPA(40, 0)) != -1)//Invulnerable
			{
				Dest.Ptr = &pChar2->ShortBuff[nBuff];
				return true;
			}
		}
		return false;
	case Dotted:
		Dest.Type = pBuffType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			int nBuff = -1;
			if ((nBuff = GetSelfBuffBySPA(0, 0)) != -1)//HP Mod
			{
				int slotnum = nBuff;
				while (slotnum < NUM_BUFF_SLOTS)
				{
					if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[nBuff]))
					{
						if (((EQ_Spell *)pSpell)->IsDetrimentalSpell() && ((EQ_Spell *)pSpell)->IsDoTSpell())
						{
							Dest.Ptr = &pChar2->Buff[nBuff];
							return true;
						}
					}
					if ((nBuff = GetTargetBuffBySPA(0, 0, ++slotnum)) == -1)
					{
						break;
					}
				}
			}
		}
		return false;
	case SilverTokens://281,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SILVERTOKENS);
		Dest.Type = pIntType;
		return true;
	case GoldTokens://282,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_GOLDTOKENS);
		Dest.Type = pIntType;
		return true;
	case McKenzie://283,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MCKENZIE);
		Dest.Type = pIntType;
		return true;
	case Bayle://284,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BAYLE);
		Dest.Type = pIntType;
		return true;
	case Reclamation://285,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_RECLAMATION);
		Dest.Type = pIntType;
		return true;
	case Brellium://286,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRELLIUM);
		Dest.Type = pIntType;
		return true;
	case Motes://287,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MOTES);
		Dest.Type = pIntType;
		return true;
	case RebellionChits://288,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REBELLIONCHITS);
		Dest.Type = pIntType;
		return true;
	case DiamondCoins://289,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DIAMONDCOINS);
		Dest.Type = pIntType;
		return true;
	case BronzeFiats://290,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRONZEFIATS);
		Dest.Type = pIntType;
		return true;
	case Voucher://291,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VOUCHER);
		Dest.Type = pIntType;
		return true;
	case VeliumShards://292,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VELIUMSHARDS);
		Dest.Type = pIntType;
		return true;
	case CrystallizedFear://293,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDFEAR);
		Dest.Type = pIntType;
		return true;
	case ShadowStones://294,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SHADOWSTONES);
		Dest.Type = pIntType;
		return true;
	case DreadStones://295,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DREADSTONES);
		Dest.Type = pIntType;
		return true;
	case MarksOfValor://296,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MARKSOFVALOR);
		Dest.Type = pIntType;
		return true;
	case MedalsOfHeroism://297,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MEDALSOFHEROISM);
		Dest.Type = pIntType;
		return true;
	case RemnantOfTranquility://298,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REMNANTSOFTRANQUILITY);
		Dest.Type = pIntType;
		return true;
	case BifurcatedCoin://299,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BIFURCATEDCOIN);
		Dest.Type = pIntType;
		return true;
	case AdoptiveCoin://300,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ADOPTIVE);
		Dest.Type = pIntType;
		return true;
	case SathirsTradeGems://301,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SATHIRSTRADEGEMS);
		Dest.Type = pIntType;
		return true;
	case AncientSebilisianCoins://302,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTSEBILISIANCOINS);
		Dest.Type = pIntType;
		return true;
	case BathezidTradeGems://303,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BATHEZIDTRADEGEMS);
		Dest.Type = pIntType;
		return true;
	case AncientDraconicCoin://304,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTDRACONICCOIN);
		Dest.Type = pIntType;
		return true;
	case FetterredIfritCoins://305,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FETTERREDIFRITCOINS);
		Dest.Type = pIntType;
		return true;
	case EntwinedDjinnCoins://306,
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENTWINEDDJINNCOINS);
		Dest.Type = pIntType;
		return true;
	case CrystallizedLuck://307
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDLUCK);
		Dest.Type = pIntType;
		return true;
	case ParcelStatus://309
		Dest.DWord = pChar->ParcelStatus;
		Dest.Type = pIntType;
		return true;
	case CanMount://310
		if (PlayerZoneClient*pzc = (PlayerZoneClient*)pLocalPlayer)
		{
			Dest.DWord = 0;
			Dest.Type = pBoolType;
			int zid = ((PSPAWNINFO)pLocalPlayer)->GetZoneID() & 0x7FFF;
			if (((PSPAWNINFO)pLocalPlayer)->HeadWet != 0 || ((PSPAWNINFO)pLocalPlayer)->Vehicle != NULL)
			{
				return true;
			}
			int race = ((PSPAWNINFO)pLocalPlayer)->mActorClient.Race;
			if ((!pzc->LegalPlayerRace(-1)) && (race != EQR_SKELETON) && (race != EQR_SKELETON_NEW) && (race != EQR_OEQ_SKELETON) && (race != EQR_SOL_SKELETON))
			{
				return true;
			}
			if (PZONEINFO pthezone = (PZONEINFO)pZoneInfo)
			{
				if (zid == 151 /*bazaar*/ || zid == 152 /*nexus*/)
				{
					Dest.DWord = 1;
					return true;
				}
				if (pthezone->OutDoor == IndoorDungeon || pthezone->OutDoor == IndoorCity ||
					pthezone->OutDoor == DungeonCity)
					return true;
			}
			if (zid < MAX_ZONES)
			{
				if (PZONELIST pZList = ((PWORLDDATA)pWorldData)->ZoneArray[zid])
				{
					if (pZList->ZoneFlags & 0x200)
					{
						return true;
					}
				}
				Dest.DWord = 1;
			}
			return true;
		}
	case SpellRankCap://311
		Dest.DWord = 1;
		Dest.Type = pIntType;
		if (PCHARINFO pChar = GetCharInfo())
		{
			if (CharacterBase *cb = (CharacterBase *)&pChar->CharacterBase_vftable)
			{
				int ret = cb->GetGameFeature(3);
				if (ret == -1 || ret >= 10)
					Dest.DWord = 3;
				else if (ret >= 5)
					Dest.DWord = 2;
			}
		}
		return true;
	case FroststoneDucat://313
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FROSTSTONEDUCAT);
		Dest.Type = pIntType;
		return true;
	case WarlordsSymbol://314
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_WARLORDSSYMBOL);
		Dest.Type = pIntType;
		return true;
	case OverseerTetradrachm://315
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_OVERSEERTETRADRACHM);
		Dest.Type = pIntType;
		return true;
	case WarforgedEmblem://317
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_WARFORGEDEMBLEM);
		Dest.Type = pIntType;
		return true;
	case RestlessMark://318
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_RESTLESSMARK);
		Dest.Type = pIntType;
		return true;
	case CastTimeLeft:
	{
		Dest.Int64 = 0;
		Dest.Type = pTimeStampType;
		int spelleta = ((PSPAWNINFO)pLocalPlayer)->CastingData.SpellETA;
		if (spelleta > 0) {
			Dest.Int64 = ((PSPAWNINFO)pLocalPlayer)->CastingData.SpellETA - ((PSPAWNINFO)pLocalPlayer)->TimeStamp;
			if (Dest.Int64 < 0)
				Dest.Int64 = 0;
		}
		return true;
	}
	}


	//end of MQ2CharacterType
	return false;
//#undef pChar
}

bool MQ2SpellType::GETMEMBER()
{
	PSPELL pSpell = (PSPELL)VarPtr.Ptr;
	if (!VarPtr.Ptr)
		return false;
	if (IsBadReadPtr((void*)pSpell, 4))
		return false;
	PMQ2TYPEMEMBER pMember = MQ2SpellType::FindMember(Member);
	if (!pMember)
		return false;

	switch ((SpellMembers)pMember->ID)
	{
	case ID:
		Dest.DWord = pSpell->ID;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;
	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX() && GetCharInfo()->pSpawn)
		{
			Dest.DWord = pSpell->ClassLevel[GetCharInfo()->pSpawn->mActorClient.Class];
			return true;
		}
		else
		{
			if (ISNUMBER())
			{
				unsigned long nIndex = GETNUMBER();
				Dest.DWord = pSpell->ClassLevel[nIndex];
				return true;
			}
		}
		return false;
	case Mana:
		Dest.DWord = pSpell->ManaCost;
		Dest.Type = pIntType;
		return true;
	case ResistAdj:
		Dest.DWord = pSpell->ResistAdj;
		Dest.Type = pIntType;
		return true;
	case Range:
		Dest.Float = pSpell->Range;
		Dest.Type = pFloatType;
		return true;
	case AERange:
		Dest.Float = pSpell->AERange;
		Dest.Type = pFloatType;
		return true;
	case PushBack:
		Dest.Float = pSpell->PushBack;
		Dest.Type = pFloatType;
		return true;
	case CastTime:
		Dest.UInt64 = pSpell->CastTime;
		Dest.Type = pTimeStampType;
		return true;
	case RecoveryTime:
	case FizzleTime:
		Dest.UInt64 = pSpell->RecoveryTime;
		Dest.Type = pTimeStampType;
		return true;
	case RecastTime:
		Dest.UInt64 = pSpell->RecastTime;
		Dest.Type = pTimeStampType;
		return true;
	case ResistType:
		switch (pSpell->Resist)
		{
		case 9: strcpy_s(DataTypeTemp, "Corruption"); break;
		case 8:	strcpy_s(DataTypeTemp, "Physical"); break;
		case 7: strcpy_s(DataTypeTemp, "Prismatic"); break;
		case 6: strcpy_s(DataTypeTemp, "Chromatic"); break;
		case 5: strcpy_s(DataTypeTemp, "Disease"); break;
		case 4: strcpy_s(DataTypeTemp, "Poison"); break;
		case 3: strcpy_s(DataTypeTemp, "Cold"); break;
		case 2: strcpy_s(DataTypeTemp, "Fire"); break;
		case 1: strcpy_s(DataTypeTemp, "Magic"); break;
		case 0: strcpy_s(DataTypeTemp, "Unresistable"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case SpellType:
		switch (pSpell->SpellType)
		{
		case 2: strcpy_s(DataTypeTemp, "Beneficial(Group)"); break;
		case 1: strcpy_s(DataTypeTemp, "Beneficial"); break;
		case 0: strcpy_s(DataTypeTemp, "Detrimental"); break;
		default: strcpy_s(DataTypeTemp, "Unknown"); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case TargetType:
		switch (pSpell->TargetType)
		{
		case 50: strcpy_s(DataTypeTemp, "Target_AE_No_Players_Pets"); break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
		case 52: strcpy_s(DataTypeTemp, "Single Friendly (or Target's Target"); break; // Introduced in Torment of Velious. Spell affects target if friendly, or target's target if the target is an unfriendly.
		case 47: strcpy_s(DataTypeTemp, "Pet Owner"); break;
		case 46: strcpy_s(DataTypeTemp, "Target of Target"); break;
		case 45: strcpy_s(DataTypeTemp, "Free Target"); break;
		case 44: strcpy_s(DataTypeTemp, "Beam"); break;
		case 43: strcpy_s(DataTypeTemp, "Single in Group"); break;
		case 42: strcpy_s(DataTypeTemp, "Directional AE"); break;
		case 41: strcpy_s(DataTypeTemp, "Group v2"); break;
		case 40: strcpy_s(DataTypeTemp, "AE PC v2"); break;
		case 39: strcpy_s(DataTypeTemp, "No Pets"); break;
		case 38: strcpy_s(DataTypeTemp, "Pet2"); break;
		case 37: strcpy_s(DataTypeTemp, "Caster PB NPC"); break;
		case 36: strcpy_s(DataTypeTemp, "Caster PB PC"); break;
		case 35: strcpy_s(DataTypeTemp, "Special Muramites"); break;
		case 34: strcpy_s(DataTypeTemp, "Chest"); break;
		case 33: strcpy_s(DataTypeTemp, "Hatelist2"); break;
		case 32: strcpy_s(DataTypeTemp, "Hatelist"); break;
		case 25: strcpy_s(DataTypeTemp, "AE Summoned"); break;
		case 24: strcpy_s(DataTypeTemp, "AE Undead"); break;
		case 20: strcpy_s(DataTypeTemp, "Targeted AE Tap"); break;
		case 18: strcpy_s(DataTypeTemp, "Uber Dragons"); break;
		case 17: strcpy_s(DataTypeTemp, "Uber Giants"); break;
		case 16: strcpy_s(DataTypeTemp, "Plant"); break;
		case 15: strcpy_s(DataTypeTemp, "Corpse"); break;
		case 14: strcpy_s(DataTypeTemp, "Pet"); break;
		case 13: strcpy_s(DataTypeTemp, "LifeTap"); break;
		case 11: strcpy_s(DataTypeTemp, "Summoned"); break;
		case 10: strcpy_s(DataTypeTemp, "Undead"); break;
		case  9: strcpy_s(DataTypeTemp, "Animal"); break;
		case  8: strcpy_s(DataTypeTemp, "Targeted AE"); break;
		case  6: strcpy_s(DataTypeTemp, "Self"); break;
		case  5: strcpy_s(DataTypeTemp, "Single"); break;
		case  4: strcpy_s(DataTypeTemp, "PB AE"); break;
		case  3: strcpy_s(DataTypeTemp, "Group v1"); break;
		case  2: strcpy_s(DataTypeTemp, "AE PC v1"); break;
		case  1: strcpy_s(DataTypeTemp, "Line of Sight"); break;
		default: sprintf_s(DataTypeTemp, "Unknown(%d)", pSpell->TargetType); break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Skill:
		strcpy_s(DataTypeTemp, szSkills[pSpell->Skill]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case MyCastTime:
	{
		PSPELL pMySpell = (PSPELL)pSpell;
		__int64 myaacastingtime = (__int64)GetCastingTimeModifier((EQ_Spell*)pMySpell);
		VePointer<CONTENTS>pc;
		int myfocuscastingtime = GetFocusCastingTimeModifier((EQ_Spell*)pMySpell, pc, false);
		__int64 mycasttime = (__int64)pMySpell->CastTime;
		__int64 mct = myaacastingtime + myfocuscastingtime + mycasttime;
		if (pMySpell->CastTime > 0 && mct < (pMySpell->CastTime / 2))
			Dest.UInt64 = pMySpell->CastTime / 2;
		else
			Dest.UInt64 = mct;
		Dest.Type = pTimeStampType;
		return true;
	}
	case Duration:
		Dest.DWord = GetSpellDuration(pSpell, (PSPAWNINFO)pLocalPlayer);
		Dest.Type = pTicksType;
		return true;
	case MyDuration:
	{
		int OrgDuration = EQGetSpellDuration(pSpell, ((PSPAWNINFO)pLocalPlayer)->Level, false);
		int Out1 = 0, Out2 = 0;
		PCONTENTS pContOut = 0;
		int mydur = 0;//todo: see if we can get this working for emu as well.
		#if !defined(ROF2EMU) && !defined(UFEMU)
		mydur = EQGetMySpellDuration(pSpell, &pContOut, (PSPAWNINFO)pLocalPlayer, OrgDuration, &Out1, &Out2);
		#endif
		Dest.DWord = mydur + OrgDuration;
		Dest.Type = pTicksType;
		return true;
	}
	case EQSpellDuration:
		Dest.DWord = EQGetSpellDuration(pSpell, ((PSPAWNINFO)pLocalPlayer)->Level, false);
		Dest.Type = pTicksType;
		return true;
	case CastByMe:
		/*CastByMe,CastByOther,CastOnYou,CastOnAnother,WearOff*/
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (char*str = GetSpellString(pSpell->ID, 0)) {
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case CastByOther:
		/*CastByMe,CastByOther,CastOnYou,CastOnAnother,WearOff*/
		strcpy_s(DataTypeTemp, " casts Unknown Spell.");
		if (char*str = GetSpellString(pSpell->ID, 1)) {
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case CastOnYou:
		strcpy_s(DataTypeTemp, "You feel bogus as an unknown spell accosts you.");
		if (char*str = GetSpellString(pSpell->ID, 2)) {
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case CastOnAnother:
		/*CastByMe,CastByOther,CastOnYou,CastOnAnother,WearOff*/
		strcpy_s(DataTypeTemp, " is the victim of an unknown spell.");
		if (char*str = GetSpellString(pSpell->ID, 3)) {
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case WearOff:
		/*CastByMe,CastByOther,CastOnYou,CastOnAnother,WearOff*/
		strcpy_s(DataTypeTemp, "An unknown spell is gone.");
		if (char*str = GetSpellString(pSpell->ID, 4)) {
			strcpy_s(DataTypeTemp, str);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case CounterType:
	{
		strcpy_s(DataTypeTemp, "None");
		for (int i = 0; i < GetSpellNumEffects(pSpell); i++) {
			switch (GetSpellAttrib(pSpell, i))
			{
			case 35:
				strcpy_s(DataTypeTemp, "Disease");
				break;
			case 36:
				strcpy_s(DataTypeTemp, "Poison");
				break;
			case 116:
				strcpy_s(DataTypeTemp, "Curse");
				break;
			case 369:
				strcpy_s(DataTypeTemp, "Corruption");
				break;
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case CounterNumber:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		int i;
		for (i = 0; i < GetSpellNumEffects(pSpell); i++) {
			if ((GetSpellAttrib(pSpell, i) == 35) || (GetSpellAttrib(pSpell, i) == 36) || (GetSpellAttrib(pSpell, i) == 116) || (GetSpellAttrib(pSpell, i) == 369)) {
				Dest.DWord = (int)GetSpellBase(pSpell, i);
				return true;
			}
		}
		return true;
	}
	case Stacks:
	case NewStacks://stacks on self
	{
		//unsigned long buffduration;
		unsigned long duration = 99999;
		if (ISNUMBER())
			duration = GETNUMBER();
		PSPELL thespell = pSpell;
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pLocalPlayer)
		{
			CharacterZoneClient*pCZC = (CharacterZoneClient*)((PSPAWNINFO)pLocalPlayer)->GetCharacter();
			if (pCZC)
			{
				int SlotIndex = -1;
				EQ_Affect*ret = pCZC->FindAffectSlot(thespell->ID, (PSPAWNINFO)pLocalPlayer, &SlotIndex, true, ((PSPAWNINFO)pLocalPlayer)->Level, NULL, 0);
				if (!ret || SlotIndex==-1)
					Dest.DWord = false;
				else
				{
					Dest.DWord = true;
					/*buffduration = ret->DurationTick;
					DWORD spelldur = GetSpellDuration(thespell, (PSPAWNINFO)pLocalPlayer);
					if ( spelldur >= 0xFFFFFFFE) {
						buffduration = 99999 + 1;
					}
					//WriteChatf("Spell.NewStacks(%d:%d,%d)",thespell->ID,duration,buffduration);
					if (buffduration > duration)
						Dest.DWord = false;*/
				}
			}
		}
		return true;
	}
	case WillStack:
	case StacksWith:
	case NewStacksWith://if a spell stack with another spell
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!ISINDEX())
			return true;
		PSPELL tmpSpell = NULL;
		if (ISNUMBER())
			tmpSpell = GetSpellByID(GETNUMBER());
		else
			tmpSpell = GetSpellByName(GETFIRST());
		if (!tmpSpell)
			return true;
		PSPELL thespell = pSpell;
		if (pLocalPlayer)
		{
			if (CharacterZoneClient*pCZC = (CharacterZoneClient*)((PSPAWNINFO)pLocalPlayer)->GetCharacter())
			{
				EQ_Affect eff = { 0 };
				FIllSlotData(&eff, tmpSpell);
				eff.SpellID = tmpSpell->ID;
				eff.Level = ((PSPAWNINFO)pLocalPlayer)->Level;
				eff.Type = 2;
				eff.Modifier = 1.0;
				int SlotIndex = -1;
				EQ_Affect*ret = pCZC->FindAffectSlot(thespell->ID, (PSPAWNINFO)pLocalPlayer, &SlotIndex, true, ((PSPAWNINFO)pLocalPlayer)->Level, &eff, 1);
				//call below is correct but it always seem to return false when we feed it a &eff so i don't
				//think its useful here... also the call above calls it for us...
				//Dest.DWord = pCZC->IsStackBlocked((EQ_Spell*)thespell, (PSPAWNINFO)pLocalPlayer, &eff, 1);
				if (!ret || SlotIndex==-1)
					Dest.DWord = false;
				else
					Dest.DWord = true;
			}
		}
		return true;
	}
	case StacksSpawn:
	{
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!ISINDEX())
			return true;
		lockit lk(ghCachedBuffsLock);
		if (CachedBuffsMap.empty())
			return true;
		PSPAWNINFO pSpawn = 0;
		if (ISNUMBER())
		{
			pSpawn = (PSPAWNINFO)GetSpawnByID(atoi(GETFIRST()));
		}
		else {
			pSpawn = (PSPAWNINFO)GetSpawnByName(GETFIRST());
		}
		if (pSpawn)
		{
			if(CharacterZoneClient* pCZC = (CharacterZoneClient*)((PSPAWNINFO)pLocalPlayer)->GetCharacter())
			{
				EQ_Affect pAffects[NUM_BUFF_SLOTS] = { 0 };
				int j = 0;

				std::map<int, std::map<int, cTargetBuff>>::iterator i = CachedBuffsMap.find(pSpawn->SpawnID);
				if (i != CachedBuffsMap.end())
				{
					for (std::map<int, cTargetBuff>::iterator k = i->second.begin(); k != i->second.end(); k++)
					{
						if (PSPELL pBuff = GetSpellByID(k->first)) {
							FIllSlotData(&pAffects[j], pBuff);

							pAffects[j].Duration = k->second.duration;
							#if !defined(ROF2EMU) && !defined(UFEMU)
							pAffects[j].InitialDuration = k->second.duration;
							#endif
							pAffects[j].Type = 2;
							pAffects[j].SpellID = pBuff->ID;
							pAffects[j].Activatable = 0;// pBuff->Activated;
							pAffects[j].Level = ((PSPAWNINFO)pLocalPlayer)->Level;
							pAffects[j].Modifier = 1.0;
							j++;
						}
					}
				}
				int SlotIndex = -1;
				EQ_Affect*ret = pCZC->FindAffectSlot(pSpell->ID, (PSPAWNINFO)pLocalPlayer, &SlotIndex, true, ((PSPAWNINFO)pLocalPlayer)->Level, pAffects, j);
				if (!ret || SlotIndex == -1)
					Dest.DWord = false;
				else
					Dest.DWord = true;
			}
		}
		return true;
	}
	case StacksTarget:
	{
		lockit lk(ghCachedBuffsLock);
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pLocalPlayer)
		{
			if(CharacterZoneClient* pCZC = (CharacterZoneClient*)((PSPAWNINFO)pLocalPlayer)->GetCharacter())
			{
				if (pTarget)
				{
				if (PCHARINFO pMe = GetCharInfo())
				{
					EQ_Affect pAffects[NUM_BUFF_SLOTS] = { 0 };
					int j = 0;

						std::map<int, std::map<int, cTargetBuff>>::iterator i = CachedBuffsMap.find(pTarget->Data.SpawnID);
						if (i != CachedBuffsMap.end())
						{
							//lets grab it from the cache so we get songs as well...
							for (std::map<int, cTargetBuff>::iterator k = i->second.begin(); k != i->second.end(); k++)
							{
								if (PSPELL pBuff = GetSpellByID(k->first)) {
									FIllSlotData(&pAffects[j], pBuff);

									pAffects[j].Duration = k->second.duration;
									pAffects[j].Type = 2;
									pAffects[j].SpellID = pBuff->ID;
									pAffects[j].Activatable = 0;// pBuff->Activated;
#if !defined(ROF2EMU) && !defined(UFEMU)
									pAffects[j].InitialDuration = k->second.duration;
									pAffects[j].CasterGuid = pMe->Guid;
#else
									pAffects[j].CasterID = ((PSPAWNINFO)pLocalPlayer)->SpawnID;
#endif
									pAffects[j].Level = ((PSPAWNINFO)pLocalPlayer)->Level;
									pAffects[j].Modifier = 1.0;
									//pAffects[j].
									j++;
								}
							}
						}
						else
						{

							int buffID = 0;
							for (int i = 0; i < NUM_BUFF_SLOTS; i++) {
								if (buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i]) {
									if (PSPELL pBuff = GetSpellByID((DWORD)buffID)) {
										FIllSlotData(&pAffects[j], pBuff);
										pAffects[j].Type = 2;
										pAffects[j].SpellID = pBuff->ID;
										pAffects[j].Activatable = 0;// pBuff->Activated;
#if !defined(ROF2EMU) && !defined(UFEMU)
										pAffects[j].CasterGuid = pMe->Guid;
#else
										pAffects[j].CasterID = ((PSPAWNINFO)pLocalPlayer)->SpawnID;
#endif
										pAffects[j].Level = ((PSPAWNINFO)pLocalPlayer)->Level;
										pAffects[j].Modifier = 1.0;
										j++;
									}
								}
							}
						}
						int SlotIndex = -1;
						EQ_Affect*ret = pCZC->FindAffectSlot(pSpell->ID, (PSPAWNINFO)pLocalPlayer, &SlotIndex, true, ((PSPAWNINFO)pLocalPlayer)->Level, pAffects, j);
						if (!ret || SlotIndex == -1)
							Dest.DWord = false;
						else
							Dest.DWord = true;
					}
				}
			}
		}
		return true;
	}
	case StacksPet:
	{
		//unsigned long petbuffduration;
		unsigned long duration = 99999;
		if (ISNUMBER())
			duration = GETNUMBER();
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (pLocalPlayer)
		{
			if (CharacterZoneClient* pCZC = (CharacterZoneClient*)((PSPAWNINFO)pLocalPlayer)->GetCharacter())
			{
				if (PCHARINFO pMe = GetCharInfo())
				{
					if (PEQPETINFOWINDOW pPet = ((PEQPETINFOWINDOW)pPetInfoWnd))
					{
						EQ_Affect pAffects[NUM_BUFF_SLOTS] = { 0 };
						int buffID = 0;
						int j = 0;
						for (int i = 0; i < NUM_BUFF_SLOTS; i++)
						{
							if (buffID = pPet->Buff[i]) {
								if (PSPELL pBuff = GetSpellByID((DWORD)buffID)) {
									FIllSlotData(&pAffects[j], pBuff);
									pAffects[j].Type = 2;
									pAffects[j].SpellID = pBuff->ID;
									pAffects[j].Activatable = 0;// pBuff->Activated;
#if !defined(ROF2EMU) && !defined(UFEMU)
									pAffects[j].CasterGuid = pMe->Guid;
#else
									pAffects[j].CasterID = ((PSPAWNINFO)pLocalPlayer)->SpawnID;
#endif
									pAffects[j].Level = ((PSPAWNINFO)pLocalPlayer)->Level;
									pAffects[j].Modifier = 1.0;
									j++;
								}
							}
						}
						int SlotIndex = -1;
						EQ_Affect*ret = pCZC->FindAffectSlot(pSpell->ID, (PSPAWNINFO)pLocalPlayer, &SlotIndex, true, ((PSPAWNINFO)pLocalPlayer)->Level, pAffects, j);
						if (!ret || SlotIndex == -1)
							Dest.DWord = false;
						else
							Dest.DWord = true;
					}
				}
			}
		}
		/*for (nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++) {
			if (pPet->Buff[nBuff] > 0 && !(pPet->Buff[nBuff] == 0xFFFFFFFF || pPet->Buff[nBuff] == 0)) {
				if (PSPELL buffSpell = GetSpellByID(pPet->Buff[nBuff])) {
					petbuffduration = ((pPet->PetBuffTimer[nBuff] + 5999) / 1000) / 6;
					if (GetSpellDuration(buffSpell, (PSPAWNINFO)pLocalPlayer) >= 0xFFFFFFFE) {
						petbuffduration = 99999 + 1;
					}
					if (!BuffStackTest(pSpell, buffSpell, TRUE) || ((buffSpell == pSpell) && (petbuffduration > duration))) {
						Dest.DWord = false;
						return true;
					}
				}
			}
		}*/
		return true;
	}
	case MyRange:
	{
		VePointer<CONTENTS> n;
		Dest.Float = pSpell->Range + (float)GetFocusRangeModifier((EQ_Spell*)pSpell, n);
		Dest.Type = pFloatType;
		return true;
	}
	case Address://This is for debugging purposes/correcting struct on patchday, probably not of any use to the end users.
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case EnduranceCost://This is for debugging purposes/correcting struct on patchday, probably not of any use to the end users.
		Dest.DWord = pSpell->EnduranceCost;
		Dest.Type = pIntType;
		return true;
	case MaxLevel:
		Dest.DWord = GetSpellMax(pSpell, 0);
		Dest.Type = pIntType;
		return true;
	case Category:
		strcpy_s(DataTypeTemp, "Unknown");
		if (DWORD cat = GetSpellCategory(pSpell)) {
			if (char * ptr = pCDBStr->GetString(cat, 5, NULL)) {
				strcpy_s(DataTypeTemp, ptr);
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Subcategory:
		strcpy_s(DataTypeTemp, "Unknown");
		if (DWORD cat = GetSpellSubcategory(pSpell)) {
			if (char *ptr = pCDBStr->GetString(cat, 5, NULL)) {
				strcpy_s(DataTypeTemp, ptr);
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Restrictions:
		Dest.Type = pStringType;
		if (!ISINDEX())
			return false;
		strcpy_s(DataTypeTemp, "Unknown");
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			char *ptr = GetSpellRestrictions(pSpell, nIndex, DataTypeTemp, sizeof(DataTypeTemp));
			if (!ptr)
				strcpy_s(DataTypeTemp, "Unknown");
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Base:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = GetSpellBase(pSpell, nIndex);
		}
		return true;
	case Base2:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = GetSpellBase2(pSpell, nIndex);
		}
		return true;
	case Max:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			unsigned long nIndex = GETNUMBER() - 1;
			Dest.DWord = GetSpellMax(pSpell, nIndex);
		}
		return true;
	case Calc:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = GetSpellCalc(pSpell, nIndex);
		}
		return true;
	case Attrib:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = GetSpellAttrib(pSpell, nIndex);
		}
		return true;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case CalcIndex:
		Dest.DWord = pSpell->CalcIndex;
		Dest.Type = pIntType;
		return true;
#endif
	case NumEffects:
		Dest.DWord = GetSpellNumEffects(pSpell);
		Dest.Type = pIntType;
		return true;
	case AutoCast:
		Dest.DWord = pSpell->Autocast;
		Dest.Type = pIntType;
		return true;
	case Extra:
		strcpy_s(DataTypeTemp, pSpell->Extra);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case RecastTimerID:
		Dest.DWord = pSpell->ReuseTimerIndex;
		Dest.Type = pIntType;
		return true;
	case SPA:
		Dest.DWord = pSpell->spaindex;
		Dest.Type = pIntType;
		return true;
	case ReagentID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->ReagentID[nIndex];
		}
		return true;
	case NoExpendReagentID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->NoExpendReagent[nIndex];
		}
		return true;
	case ReagentCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			int nIndex = GETNUMBER() - 1;
			if (nIndex < 0)
				return false;
			Dest.DWord = pSpell->ReagentCount[nIndex];
		}
		return true;
	case TimeOfDay:
		Dest.DWord = pSpell->TimeOfDay;
		Dest.Type = pIntType;
		return true;
	case DurationWindow:
		Dest.DWord = pSpell->DurationWindow;
		Dest.Type = pIntType;
		return true;
	case CanMGB:
		Dest.DWord = pSpell->CanMGB;
		Dest.Type = pBoolType;
		return true;
	case IsSkill:
		Dest.DWord = pSpell->IsSkill;
		Dest.Type = pBoolType;
		return true;
	case Deletable:
		Dest.DWord = pSpell->Deletable;
		Dest.Type = pBoolType;
		return true;
	case BookIcon:
		Dest.DWord = pSpell->BookIcon;
		Dest.Type = pIntType;
		return true;
	case SpellIcon:
		Dest.DWord = pSpell->SpellIcon;
		Dest.Type = pIntType;
		return true;
	case GemIcon:
		Dest.DWord = pSpell->GemIcon;
		Dest.Type = pIntType;
		return true;
	case Target:
		//todo add at some point maybe
		//GetActorTagFromID(DataTypeTemp,pSpell->ActorTagId);
#if defined(ROF2EMU) || defined(UFEMU)
		strcpy_s(DataTypeTemp, pSpell->Target);
#else
		_itoa_s(pSpell->ActorTagId, DataTypeTemp, 10);
#endif
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Description:
		Dest.Type = pStringType;
		if (char *ptr = pCDBStr->GetString(pSpell->DescriptionIndex, 6, NULL))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Caster:
		Dest.Type = pStringType;
		if (targetBuffSlotToCasterMap.size()) {
			if (targetBuffSlotToCasterMap.find(VarPtr.HighPart) != targetBuffSlotToCasterMap.end()) {
				strcpy_s(DataTypeTemp, targetBuffSlotToCasterMap[VarPtr.HighPart].c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;
	case BaseName:
	{
		strcpy_s(DataTypeTemp, pSpell->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;

		DWORD SpellRank = pSpell->SpellRank;

		switch (pSpell->SpellRank)
		{
		case 1://Original
			SpellRank = 1;
			break;
		case 5://Rk. II
			SpellRank = 2;
			break;
		case 10://Rk. III
			SpellRank = 3;
			break;
		}
		if (!SpellRank) {
			SpellRank = GetSpellRankByName(pSpell->Name);
		}
		if (SpellRank > 1) {
			TruncateSpellRankName(DataTypeTemp);
		}
		return true;
	}
	case Rank:
		Dest.DWord = pSpell->SpellRank;//well I haven't checked all spells, but im pretty sure if it's 0 its not a spell a player can scribe/or not intentional, i.e a eq bug, time will tell - eqmule
		Dest.Type = pIntType;
		switch (pSpell->SpellRank)
		{
		case 1://Original
			Dest.DWord = 1;
			break;
		case 5://Rk. II
			Dest.DWord = 2;
			break;
		case 10://Rk. III
			Dest.DWord = 3;
			break;
		}
		if (Dest.DWord == 0) {
			//didn't have a rank, lets see if we can get it from the name
			Dest.DWord = GetSpellRankByName(pSpell->Name);
		}
		return true;
	case RankName:
	{
		Dest.Type = pSpellType;
		int level = -1;
		if (PSPAWNINFO pMe = (PSPAWNINFO)pLocalPlayer) {
			level = pMe->Level;
		}
		PSPELL thespell = pSpell;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			//is it a altability?
			for (unsigned long nAbility = 0; nAbility < NUM_ALT_ABILITIES; nAbility++) {
				if (PALTABILITY pAbility = GetAAByIdWrapper(nAbility, level)) {
					if (char *pName = pCDBStr->GetString(pAbility->nName, 1, NULL)) {
						if (!_strnicmp(thespell->Name, pName, strlen(thespell->Name))) {
							if (pAbility->SpellID != -1) {
								if (PSPELL pFoundSpell = GetSpellByID(pAbility->SpellID)) {
									if (pFoundSpell->SpellGroup == thespell->SpellGroup) {
										Dest.Ptr = pFoundSpell;
										return true;
									}
								}
							}
						}
					}
				}
			}
			//so if we got here we should check if its a combatability
			for (DWORD dwIndex = 0; dwIndex < NUM_COMBAT_ABILITIES; dwIndex++) {
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(dwIndex)) {
					if (PSPELL pFoundSpell = GetSpellByID(pPCData->GetCombatAbility(dwIndex))) {
						if (pFoundSpell->SpellGroup == thespell->SpellGroup && !_strnicmp(thespell->Name, pFoundSpell->Name, strlen(thespell->Name)))
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}
			//well AA should be used first so lets search spells last...
			for (DWORD nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++) {
				if (pChar2->SpellBook[nSpell] != 0xFFFFFFFF)
				{
					if (PSPELL pFoundSpell = GetSpellByID(pChar2->SpellBook[nSpell])) {
						if (pFoundSpell->ID == thespell->ID)
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}
			for (DWORD nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++) {
				if (pChar2->SpellBook[nSpell] != 0xFFFFFFFF)
				{
					if (PSPELL pFoundSpell = GetSpellByID(pChar2->SpellBook[nSpell])) {
						if (pFoundSpell->SpellGroup == thespell->SpellGroup && !_strnicmp(thespell->Name, pFoundSpell->Name, strlen(thespell->Name)))
						{
							Dest.Ptr = pFoundSpell;
							return true;
						}
					}
				}
			}
		}
		Dest.Ptr = thespell;
		return true;
	}
	case SpellGroup:
		Dest.DWord = pSpell->SpellGroup;
		Dest.Type = pIntType;
		return true;
	case SubSpellGroup:
		#if !defined(UFEMU)
		Dest.DWord = pSpell->SpellSubGroup;
		#else
		Dest.DWord = 0;
		#endif
		Dest.Type = pIntType;
		return true;
	case Beneficial:
		Dest.DWord = (pSpell->SpellType) ? true : false;
		Dest.Type = pBoolType;
		return true;
	case xIsActiveAA:
		Dest.DWord = IsActiveAA(pSpell->Name);
		Dest.Type = pBoolType;
		return true;
	case Location:
		Dest.DWord = pSpell->ZoneType;
		Dest.Type = pIntType;
		return true;
	case IsSwarmSpell:
	{
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		LONG slots = GetSpellNumEffects(pSpell);
		for (LONG i = 0; i < slots; i++) {
			LONG attrib = GetSpellAttrib(pSpell, i);
			if (attrib == 152 || attrib == 300) {
				Dest.DWord = 1;
				break;
			}
		}
		return true;
	}
	case DurationValue1:
		Dest.DWord = pSpell->DurationCap;
		Dest.Type = pIntType;
		return true;
	#if !defined(ROF2EMU) && !defined(UFEMU)
	case StacksWithDiscs:
		Dest.DWord = pSpell->bStacksWithDiscs;
		Dest.Type = pBoolType;
		return true;
	case IllusionOkWhenMounted:
		Dest.DWord = true;
		Dest.Type = pBoolType;
		if (BYTE spellindex = ((EQ_Spell*)pSpell)->SpellAffects(SPA_CHANGE_FORM)) {
			if (EQ_Affect *aff = ((EQ_Character*)pCharData1)->GetPCSpellAffect(SPA_SUMMON_MOUNT, NULL)) {
				if (PlayerZoneClient*pzc = (PlayerZoneClient*)pLocalPlayer) {
					for (int i = 0; i < GetSpellNumEffects(pSpell); ++i)
					{
						if (const PSPELLCALCINFO pSpellAffect = ((EQ_Spell*)pSpell)->GetSpellAffectByIndex(i)) {
							if (pSpellAffect->Attrib == SPA_CHANGE_FORM)
							{
								int islegal = pzc->LegalPlayerRace(pSpellAffect->Base);
								#if defined(ROF2EMU) || defined(UFEMU)
								if (!islegal && pSpellAffect->Base != EQR_SKELETON && pSpellAffect->Base != EQR_SKELETON_NEW) {
								#else
								if (!islegal && pSpellAffect->Base != EQR_SKELETON && pSpellAffect->Base != EQR_SKELETON_NEW &&
									pSpellAffect->Base != EQR_OEQ_SKELETON && pSpellAffect->Base != EQR_SOL_SKELETON) {
								#endif
									//can't change into this illusion cause you are on a mount...
									Dest.DWord = false;
									break;
								}
							}
						}
					}
				}
			}
		}
		return true;
#endif
	case HasSPA:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				int spa = GETNUMBER();
				if (IsSPAEffect(pSpell, spa))
				{
					Dest.DWord = true;
				}
			}
		}
		return true;
	case Trigger:
	{
		Dest.Type = pSpellType;
		PSPELL pmyspell = pSpell;
		#if !defined(UFEMU)
		int spafound = 0;
		if(IsSPAEffect(pSpell,SPA_TRIGGER_BEST_SPELL_GROUP))
		{
			spafound = SPA_TRIGGER_BEST_SPELL_GROUP;
		}
		else if(IsSPAEffect(pSpell,374))
		{
			spafound = 374;
		}
		if (pSpellMgr && spafound)
		{
			int index = 0;
			if (ISINDEX())
			{
				if (ISNUMBER())
				{
					index = GETNUMBER();
					if (index > 0)
						index--;
					else
						index = 0;
				}
			}
			int numeffects = GetSpellNumEffects(pSpell);
			if (numeffects > index) {
				PSPELL pTrigger = 0;
				if (int groupid = GetSpellBase2(pmyspell, index)) {
					if (spafound == SPA_TRIGGER_BEST_SPELL_GROUP)
						pTrigger = GetHighestLearnedSpellByGroupID(groupid);
					else if (spafound == 374)
						pTrigger = (PSPELL)pSpellMgr->GetSpellByID(groupid);
					Dest.Ptr = pTrigger;
					return true;
				}
			}
		}
		#else
		return false;
		#endif
		return false;
	}
	case SlowPct:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (long value = GetMeleeSpeedPctFromSpell(pSpell, false)) {
			Dest.Int = value;
		}
		return true;
	case HastePct:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (long value = GetMeleeSpeedPctFromSpell(pSpell, true)) {
			Dest.Int = value;
		}
		return true;
	}
	return false;
}

bool MQ2ItemSpellType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2ItemSpellType::FindMember(Member);
	if (!pMember)
		return false;
	PITEMSPELLS pItemSpell = (PITEMSPELLS)VarPtr.Ptr;
	switch ((ItemSpellMembers)pMember->ID)
	{
		case SpellID:
			Dest.DWord = pItemSpell->SpellID;
			Dest.Type = pIntType;
			return true;
		case RequiredLevel:
			Dest.DWord = pItemSpell->RequiredLevel;
			Dest.Type = pIntType;
			return true;
		case EffectType:
			Dest.DWord = pItemSpell->EffectType;
			Dest.Type = pIntType;
			return true;
		case EffectiveCasterLevel:
			Dest.DWord = pItemSpell->EffectiveCasterLevel;
			Dest.Type = pIntType;
			return true;
		case MaxCharges:
			Dest.DWord = pItemSpell->MaxCharges;
			Dest.Type = pIntType;
			return true;
		case CastTime:
			Dest.DWord = pItemSpell->CastTime;
			Dest.Type = pIntType;
			return true;
		case TimerID:
			Dest.DWord = pItemSpell->TimerID;
			Dest.Type = pIntType;
			return true;
		case RecastType:
			Dest.DWord = pItemSpell->RecastType;
			Dest.Type = pIntType;
			return true;
		case ProcRate:
			Dest.DWord = pItemSpell->ProcRate;
			Dest.Type = pIntType;
			return true;
		case OtherName:
			strcpy_s(DataTypeTemp, pItemSpell->OtherName);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case OtherID:
			Dest.DWord = pItemSpell->OtherID;
			Dest.Type = pIntType;
			return true;
		case Spell:
			Dest.Ptr = GetSpellByID(pItemSpell->SpellID);
			Dest.Type = pSpellType;
			return true;
	}
	return false;
}
bool MQ2ItemType::GETMEMBER()
{
	DWORD N, cmp, tmp;
	PCONTENTS pItem = (PCONTENTS)VarPtr.Ptr;
	if (!pItem)
		return false;
	PITEMINFO pItemInfo = GetItemFromContents(pItem);
	if (!pItemInfo)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2ItemType::FindMember(Member);
	if (!pMember)
		return false;

	switch ((ItemMembers)pMember->ID)
	{
	case ID:
		Dest.DWord = GetItemFromContents(pItem)->ItemNumber;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, GetItemFromContents(pItem)->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Lore:
		Dest.DWord = ((ItemBase *)pItem)->IsLore(false);
		Dest.Type = pBoolType;
		return true;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case LoreEquipped:
		Dest.DWord = ((ItemBase *)pItem)->IsLoreEquipped(false);
		Dest.Type = pBoolType;
		return true;
#endif
	case NoDrop:
	case NoTrade:
		Dest.DWord = !((EQ_Item*)pItem)->CanDrop(0, 1);
		Dest.Type = pBoolType;
		return true;
	case NoRent:
		Dest.DWord = !GetItemFromContents(pItem)->NoRent;
		Dest.Type = pBoolType;
		return true;
	case Magic:
		Dest.DWord = ((GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) && (GetItemFromContents(pItem)->Magic));
		Dest.Type = pBoolType;
		return true;
	case Value:
		Dest.DWord = GetItemFromContents(pItem)->Cost;
		Dest.Type = pIntType;
		return true;
	case Size:
		Dest.DWord = GetItemFromContents(pItem)->Size;
		Dest.Type = pIntType;
		return true;
	case SizeCapacity:
		Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
		Dest.Type = pIntType;
		return true;
	case Weight:
		Dest.DWord = GetItemFromContents(pItem)->Weight;
		Dest.Type = pIntType;
		return true;
	case Stack:
		if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable() != 1))
			Dest.DWord = 1;
		else
			Dest.DWord = pItem->StackCount;
		Dest.Type = pIntType;
		return true;
	case Type:
		DataTypeTemp[0] = '\0';
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL)
		{
			if ((GetItemFromContents(pItem)->ItemType < MAX_ITEMTYPES) && (szItemTypes[GetItemFromContents(pItem)->ItemType] != NULL))
			{
				strcpy_s(DataTypeTemp, szItemTypes[GetItemFromContents(pItem)->ItemType]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownType%d", GetItemFromContents(pItem)->ItemType);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if ((GetItemFromContents(pItem)->Combine < MAX_COMBINES) && (szCombineTypes[GetItemFromContents(pItem)->Combine] != NULL))
			{
				strcpy_s(DataTypeTemp, szCombineTypes[GetItemFromContents(pItem)->Combine]);
			}
			else
			{
				sprintf_s(DataTypeTemp, "*UnknownCombine%d", GetItemFromContents(pItem)->Combine);
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_BOOK)
			strcpy_s(DataTypeTemp, "Book");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Charges:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Charges;
		Dest.Type = pIntType;
		return true;
	case LDoNTheme:
		strcpy_s(DataTypeTemp, GetLDoNTheme(GetItemFromContents(pItem)->LDTheme));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
#if !defined(UFEMU)//todo: check manually for uf
	case DMGBonusType://we go to keep this for backward compatibility
					  //but really it should be called case ElementalFlag:
		strcpy_s(DataTypeTemp, szDmgBonusType[GetItemFromContents(pItem)->ElementalFlag]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
#endif
	case Container:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = GetItemFromContents(pItem)->Slots;
		}
		return true;
	case Open:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			Dest.DWord = pItem->Open;
		}
		return true;
	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
		{
			if (pItem->Contents.ContainedItems.pItems) {
				for (unsigned long N = 0; N < GetItemFromContents(pItem)->Slots; N++) {
					if (pItem->GetContent(N))
						Dest.DWord++;
				}
			}
			return true;
		}
		return false;
	case Clicky:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Clicky;
		Dest.Type = pItemSpellType;
		return true;
	case Proc:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Proc;
		Dest.Type = pItemSpellType;
		return true;
	case Worn:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Worn;
		Dest.Type = pItemSpellType;
		return true;
	case Focus:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Focus;
		Dest.Type = pItemSpellType;
		return true;
	case Scroll:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Scroll;
		Dest.Type = pItemSpellType;
		return true;
	case Focus2:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Focus2;
		Dest.Type = pItemSpellType;
		return true;
	#if !defined(ROF2EMU) && !defined(UFEMU)
	case Mount:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Mount;
		Dest.Type = pItemSpellType;
		return true;
	case Illusion:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Illusion;
		Dest.Type = pItemSpellType;
		return true;
	case Familiar:
		Dest.Ptr = (PVOID)&GetItemFromContents(pItem)->Familiar;
		Dest.Type = pItemSpellType;
		return true;
	#endif
	case Item:
	{
		Dest.Type = pItemType;
		PCONTENTS pCont = (PCONTENTS)pItem;
		if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK && ISNUMBER())
		{
			unsigned long N = GETNUMBER();
			N--;
			if (N < GetItemFromContents(pItem)->Slots)
			{
				if (pItem->Contents.ContainedItems.pItems)
					if (Dest.Ptr = pItem->GetContent(N))
					{
						return true;
					}
			}
		}
		else if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL && ISNUMBER()) {
			unsigned long N = GETNUMBER();
			N--;
			Dest.Ptr = NULL;
			if (pItem->Contents.ContainedItems.pItems)
				switch (N)
				{
				case 0:
					if (GetItemFromContents(pItem)->AugData.Sockets[0].Type)
						Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[N];
					break;
				case 1:
					if (GetItemFromContents(pItem)->AugData.Sockets[1].Type) Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[N];
					break;
				case 2:
					if (GetItemFromContents(pItem)->AugData.Sockets[2].Type) Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[N];
					break;
				case 3:
					if (GetItemFromContents(pItem)->AugData.Sockets[3].Type) Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[N];
					break;
				case 4:
					if (GetItemFromContents(pItem)->AugData.Sockets[4].Type) Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[N];
					break;
				case 5:
					if (GetItemFromContents(pItem)->AugData.Sockets[5].Type) Dest.Ptr = pItem->Contents.ContainedItems.pItems->Item[N];
					break;
				}
			if (Dest.Ptr)
				return true;
		}
		return false;
	}
	case Stackable:
		Dest.DWord = ((EQ_Item*)pItem)->IsStackable();
		Dest.Type = pBoolType;
		return true;
	case InvSlot:
		Dest.Int = FindInvSlotForContents(pItem);
		if (Dest.Int >= 0)
		{
			Dest.Type = pInvSlotType;
			return true;
		}
		return false;
	case ItemSlot:
		Dest.Int = pItem->GetGlobalIndex().Index.Slot1;
		Dest.Type = pIntType;
		return true;
	case ItemSlot2:
		Dest.Int = pItem->GetGlobalIndex().Index.Slot2;
		Dest.Type = pIntType;
		return true;
	case BuyPrice:
		Dest.Int64 = 0;
		Dest.Type = pInt64Type;
		if (pActiveMerchant && pItem->MerchantSlot)
		{
			Dest.Int64 = pItem->Price;
			return true;
		}
		return false;
	case SellPrice:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant)
		{
			Dest.DWord = (DWORD)((FLOAT)GetItemFromContents(pItem)->Cost*(1.0f / ((PEQMERCHWINDOW)pMerchantWnd)->Markup));
			return true;
		}
		return false;
	case WornSlot:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (!Count)
					return false;
				cmp = GetItemFromContents(pItem)->EquipSlots;
				for (N = 0; N < 32; N++)
				{
					if (cmp&(1 << N))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = N;
							Dest.Type = pInvSlotType;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				DWORD nInvSlot = ItemSlotMap[GETFIRST()];
				if ((nInvSlot || !_stricmp(GETFIRST(), "charm")) && nInvSlot<32)
				{
					Dest.DWord = (GetItemFromContents(pItem)->EquipSlots&(1 << nInvSlot));
					Dest.Type = pBoolType;
					return true;
				}
			}
		}
		return false;
	case WornSlots:
		Dest.DWord = 0;
		// count bits
		cmp = GetItemFromContents(pItem)->EquipSlots;
		for (N = 0; N < 32; N++)
		{
			if (cmp&(1 << N))
				Dest.DWord++;
		}
		Dest.Type = pIntType;
		return true;
	case CastTime:
		Dest.UInt64 = GetItemFromContents(pItem)->Clicky.CastTime;
		Dest.Type = pTimeStampType;
		return true;
	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Clicky.SpellID))
		{
			return true;
		}
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Scroll.SpellID))
		{
			return true;
		}
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Proc.SpellID))
		{
			return true;
		}
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Focus.SpellID))
		{
			return true;
		}
		if (Dest.Ptr = GetSpellByID(GetItemFromContents(pItem)->Worn.SpellID))
		{
			return true;
		}
		return false;
	case EffectType:
		Dest.Type = pStringType;
		//0 Proc
		//1 Clickable from inventory (any class)
		//2 Worn effect (haste, cleave)
		//3 Unknown
		//4 Clickable must be worn
		//5 Clickable from inventory (class restricted)
		//6 Focus effect
		//7 Memmable spell scroll
		// This used to return an int type with a case statment, items could have
		// only one effect. For backwards compatibility we return based on a hierarchy.
		// A zero in any field indicates no effect (others will also be zero)
		if (!GetItemFromContents(pItem)->Clicky.SpellID)
		{
			return false;
		}
		else if (GetItemFromContents(pItem)->Scroll.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Spell Scroll");
		}
		else if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			// code to detect must-be-worn etc here
			switch (GetItemFromContents(pItem)->Clicky.EffectType)
			{
			case 4:
				strcpy_s(DataTypeTemp, "Click Worn");
				break;
			case 1:
			case 5:
				strcpy_s(DataTypeTemp, "Click Inventory");
				break;
			default:
				strcpy_s(DataTypeTemp, "Click Unknown");
				break;
			}
		}
		else if (GetItemFromContents(pItem)->Focus.SpellID != -1 || GetItemFromContents(pItem)->Worn.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Worn");
		}
		else if (GetItemFromContents(pItem)->Proc.SpellID != -1)
		{
			strcpy_s(DataTypeTemp, "Combat");
		}
		else
		{
			return false;
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case InstrumentMod:
		Dest.Float = ((FLOAT)GetItemFromContents(pItem)->InstrumentMod) / 10.0f;
		Dest.Type = pFloatType;
		return true;
	case Tribute:
		Dest.DWord = GetItemFromContents(pItem)->Favor;
		Dest.Type = pIntType;
		return true;
	case Attuneable:
		Dest.DWord = GetItemFromContents(pItem)->Attuneable;
		Dest.Type = pBoolType;
		return true;
	case Timer:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != 0xFFFFFFFF)
		{
			Dest.DWord = (GetItemTimer(pItem) + 5) / 6;
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-clicky
			return true;
		}
		return false;
	case Damage:
		Dest.DWord = GetItemFromContents(pItem)->Damage;
		Dest.Type = pIntType;
		return true;
	case ItemDelay:
		Dest.DWord = GetItemFromContents(pItem)->Delay;
		Dest.Type = pIntType;
		return true;
	case TimerReady:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (GetItemFromContents(pItem)->Clicky.TimerID != 0xFFFFFFFF)
		{
			Dest.DWord = GetItemTimer(pItem);
			return true;
		}
		if (GetItemFromContents(pItem)->Clicky.SpellID != -1)
		{
			Dest.DWord = 0; // insta-click or instant recast
			return true;
		}
		return false;
	case StackSize:   //This returns the MAX size of a stack for the item
					  //If this was properly named it should be called MaxStack... but ah well... to late now...
		Dest.DWord = 1; //we know its at least 1
		Dest.Type = pIntType;
		if (pItem) {
			#if !defined(UFEMU)
			if (pItem->punknown) {// since the call to >IsStackable() needs this vtable... we crash if its 0...
			#else
			if (pItem) {
			#endif
			if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable() != 1)) {
					//do nothing
					//Sleep(0);
				}
				else {
					Dest.DWord = GetItemFromContents(pItem)->StackSize;
				}
			}
			else {
				PITEMINFO theitem = GetItemFromContents(pItem);
				if (theitem && theitem->StackSize >= 1) {
					Dest.DWord = theitem->StackSize;
				}
			}
		}
		return true;
	case Stacks:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;
			for (int slot = BAG_SLOT_START; slot < GetCurrentInvSlots(); slot++)
			{
				if (pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray[slot]) {
					if (PCONTENTS pTempItem = pChar2->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (DWORD pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (PCONTENTS pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord++;
										}
									}
								}
							}
						}
						else {
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}
		return true;
	case StackCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (!((EQ_Item*)pItem)->IsStackable())
				return true;
			for (int slot = BAG_SLOT_START; slot < GetCurrentInvSlots(); slot++)
			{
				if (pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray[slot]) {
					if (PCONTENTS pTempItem = pChar2->pInventoryArray->InventoryArray[slot])
					{
						if (GetItemFromContents(pTempItem)->Type == ITEMTYPE_PACK && pTempItem->Contents.ContainedItems.pItems)
						{
							for (DWORD pslot = 0; pslot < (GetItemFromContents(pTempItem)->Slots); pslot++)
							{
								if (pTempItem->Contents.ContainedItems.pItems->Item[pslot])
								{
									if (PCONTENTS pSlotItem = pTempItem->Contents.ContainedItems.pItems->Item[pslot])
									{
										if (GetItemFromContents(pSlotItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
										{
											Dest.DWord += pSlotItem->StackCount;
										}
									}
								}
							}
						}
						else {
							if (GetItemFromContents(pTempItem)->ItemNumber == GetItemFromContents(pItem)->ItemNumber)
							{
								Dest.DWord += pTempItem->StackCount;
							}
						}
					}
				}
			}
		}
		return true;
	case FreeStack:
		Dest.DWord = GetFreeStack(pItem);
		Dest.Type = pIntType;
		return true;
	case MerchQuantity:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pActiveMerchant && pItem->MerchantSlot) {
			Dest.DWord = pItem->MerchantQuantity;
			return true;
		}
		return false;
	case Classes:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		// count bits
		cmp = GetItemFromContents(pItem)->Classes;
		for (N = 0; N < 16; N++)
		{
			if (cmp&(1 << N))
				Dest.DWord++;
		}
		return true;
	case Class:
		Dest.DWord = 0;
		Dest.Type = pClassType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (!Count)
					return false;
				cmp = GetItemFromContents(pItem)->Classes;
				for (N = 0; N < 16; N++)
				{
					if (cmp&(1 << N))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = N + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				cmp = GetItemFromContents(pItem)->Classes;
				for (N = 0; N < 16; N++) {
					if (cmp&(1 << N)) {
						if (!_stricmp(GETFIRST(), GetClassDesc(N + 1)) ||
							!_stricmp(GETFIRST(), pEverQuest->GetClassThreeLetterCode(N + 1))) {
							Dest.DWord = N + 1;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;
	case Races:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		// count bits
		cmp = GetItemFromContents(pItem)->Races;
		for (N = 0; N < NUM_RACES; N++)
		{
			if (cmp&(1 << N))
				Dest.DWord++;
		}
		return true;
	case Race:
		Dest.DWord = 0;
		Dest.Type = pRaceType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (!Count)
					return false;
				cmp = GetItemFromContents(pItem)->Races;
				for (N = 0; N < NUM_RACES; N++)
				{
					if (cmp&(1 << N))
					{
						Count--;
						if (Count == 0) {

							Dest.DWord = N + 1;
							switch (N) {
							case 12:
								Dest.DWord = 128;   // IKS
								break;
							case 13:
								Dest.DWord = 130;   // VAH
								break;
							case 14:
								Dest.DWord = 330;   // FRG
								break;
							case 15:
								Dest.DWord = 522;   // DRK
								break;
							}
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				cmp = GetItemFromContents(pItem)->Races;
				for (N = 0; N < NUM_RACES; N++) {
					if (cmp&(1 << N)) {
						tmp = N + 1;
						switch (N) {
						case 12:
							tmp = 128;   // IKS
							break;
						case 13:
							tmp = 130;   // VAH
							break;
						case 14:
							tmp = 330;   // FRG
							break;
						case 15:
							tmp = 522;   // DRK
							break;
						}
						if (!_stricmp(GETFIRST(), pEverQuest->GetRaceDesc(tmp))) {
							Dest.DWord = tmp;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;
	case Deities:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		// count bits
		cmp = GetItemFromContents(pItem)->Diety;
		for (N = 0; N < NUM_DEITIES; N++)
		{
			if (cmp&(1 << N))
				Dest.DWord++;
		}
		return true;
	case Deity:
		Dest.DWord = 0;
		Dest.Type = pDeityType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (!Count)
					return false;
				cmp = GetItemFromContents(pItem)->Diety;
				for (N = 0; N < NUM_DEITIES; N++)
				{
					if (cmp&(1 << N))
					{
						Count--;
						if (Count == 0)
						{
							Dest.DWord = N + 200;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				cmp = GetItemFromContents(pItem)->Diety;
				for (N = 0; N < NUM_DEITIES; N++) {
					if (cmp&(1 << N)) {
						if (!_stricmp(GETFIRST(), pEverQuest->GetDeityDesc(N + 200))) {
							Dest.DWord = N + 200;
							return true;
						}
					}
				}
				return false;
			}
		}
		return false;
	case RequiredLevel:
		Dest.DWord = GetItemFromContents(pItem)->RequiredLevel;
		Dest.Type = pIntType;
		return true;
	case SkillModValue:
		Dest.DWord = GetItemFromContents(pItem)->SkillModValue;
		Dest.Type = pIntType;
		return true;
	case SkillModMax:
		Dest.DWord = GetItemFromContents(pItem)->SkillModMax;
		Dest.Type = pIntType;
		return true;
	case Evolving:
		Dest.Ptr = pItem;
		Dest.Type = pEvolvingItemType;
		return true;
	case AC:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AC;
		Dest.Type = pIntType;
		return true;
	case HP:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HP;
		Dest.Type = pIntType;
		return true;
	case STR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->STR;
		Dest.Type = pIntType;
		return true;
	case STA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->STA;
		Dest.Type = pIntType;
		return true;
	case AGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->AGI;
		Dest.Type = pIntType;
		return true;
	case DEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->DEX;
		Dest.Type = pIntType;
		return true;
	case CHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->CHA;
		Dest.Type = pIntType;
		return true;
	case INT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->INT;
		Dest.Type = pIntType;
		return true;
	case WIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->WIS;
		Dest.Type = pIntType;
		return true;
	case Mana:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Mana;
		Dest.Type = pIntType;
		return true;
	case ManaRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->ManaRegen;
		Dest.Type = pIntType;
		return true;
	case HPRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HPRegen;
		Dest.Type = pIntType;
		return true;
	case Endurance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Endurance;
		Dest.Type = pIntType;
		return true;
	case Attack:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Attack;
		Dest.Type = pIntType;
		return true;
	case svCold:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->SvCold;
		Dest.Type = pIntType;
		return true;
	case svFire:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->SvFire;
		Dest.Type = pIntType;
		return true;
	case svMagic:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->SvMagic;
		Dest.Type = pIntType;
		return true;
	case svDisease:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->SvDisease;
		Dest.Type = pIntType;
		return true;
	case svPoison:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->SvPoison;
		Dest.Type = pIntType;
		return true;
	case svCorruption:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = (char)GetItemFromContents(pItem)->SvCorruption;
		Dest.Type = pIntType;
		return true;
	case Haste:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Haste;
		Dest.Type = pIntType;
		return true;
	case DamShield:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->DamShield;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case AugType:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugType;
		Dest.Type = pIntType;
		return true;
	case AugRestrictions:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugRestrictions;
		Dest.Type = pIntType;
		return true;
	case AugSlot:
		Dest.DWord = 0;
		Dest.Type = pAugType;
		if (ISNUMBER()) {
			if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) {
				Dest.DWord = 0;
			} else {
				int index = GETNUMBER();
				if (index < 0)
					index = 0;
				if (index > 5)
					index = 5;
				Dest.DWord = index;
				Dest.HighPart = (LONG)pItem;
			}
			return true;
		}
		return false;
	case AugSlot1:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[0].Type;
		Dest.Type = pIntType;
		return true;
	case AugSlot2:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[1].Type;
		Dest.Type = pIntType;
		return true;
	case AugSlot3:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[2].Type;
		Dest.Type = pIntType;
		return true;
	case AugSlot4:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[3].Type;
		Dest.Type = pIntType;
		return true;
	case AugSlot5:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[4].Type;
		Dest.Type = pIntType;
		return true;
	case AugSlot6:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->AugData.Sockets[5].Type;
		Dest.Type = pIntType;
		return true;
	case Power:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = pItem->Power;
		Dest.Type = pIntType;
		return true;
	case PctPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) {
			Dest.Float = 0;
		}
		else {
			if (DWORD maxpower = GetItemFromContents(pItem)->MaxPower) {
				Dest.Float = (float)((pItem->Power * 100) / maxpower);
			}
			else {
				Dest.Float = 0;
			}
		}
		Dest.Type = pFloatType;
		return true;
	case MaxPower:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) {
			Dest.DWord = 0;
		}
		else {
			Dest.DWord = GetItemFromContents(pItem)->MaxPower;
		}
		Dest.Type = pIntType;
		return true;
	case Purity:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Purity;
		Dest.Type = pIntType;
		return true;
	case Range:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Range;
		Dest.Type = pIntType;
		return true;
	case Avoidance:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->Avoidance;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case SpellShield:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->SpellShield;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case StrikeThrough:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->StrikeThrough;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case StunResist:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->StunResist;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case Shielding:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->Shielding;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case Accuracy:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->Accuracy;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case CombatEffects:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->CombatEffects;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case DoTShielding:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->DoTShielding;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case HeroicSTR:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTR;
		Dest.Type = pIntType;
		return true;
	case HeroicINT:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicINT;
		Dest.Type = pIntType;
		return true;
	case HeroicWIS:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicWIS;
		Dest.Type = pIntType;
		return true;
	case HeroicAGI:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicAGI;
		Dest.Type = pIntType;
		return true;
	case HeroicDEX:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicDEX;
		Dest.Type = pIntType;
		return true;
	case HeroicSTA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSTA;
		Dest.Type = pIntType;
		return true;
	case HeroicCHA:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicCHA;
		Dest.Type = pIntType;
		return true;
#if defined(ROF2EMU) || defined(UFEMU)
	case HeroicSvMagic:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSvMagic;
		Dest.Type = pIntType;
		return true;
	case HeroicSvFire:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSvFire;
		Dest.Type = pIntType;
		return true;
	case HeroicSvCold:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSvCold;
		Dest.Type = pIntType;
		return true;
	case HeroicSvDisease:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSvDisease;
		Dest.Type = pIntType;
		return true;
	case HeroicSvPoison:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSvPoison;
		Dest.Type = pIntType;
		return true;
	case HeroicSvCorruption:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HeroicSvCorruption;
		Dest.Type = pIntType;
		return true;
#endif
	case EnduranceRegen:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->EnduranceRegen;
		Dest.Type = pIntType;
		return true;
	case HealAmount:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->HealAmount;
		Dest.Type = pIntType;
		return true;
	case Clairvoyance:
		if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
			Dest.DWord = 0;
		else
			Dest.DWord = GetItemFromContents(pItem)->Clairvoyance;
		Dest.Type = pIntType;
		return true;
	case DamageShieldMitigation:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				//FIX THIS
				#if !defined(ROF2EMU) && !defined(UFEMU)
				Dest.DWord = 0;
                #else
				Dest.DWord = pII->DamageShieldMitigation;
                #endif
			}
		}
		Dest.Type = pIntType;
		return true;
	case SpellDamage:
		Dest.DWord = 0;
		if (PITEMINFO pII = GetItemFromContents(pItem)) {
			if (pII->Type == ITEMTYPE_NORMAL) {
				Dest.DWord = pII->SpellDamage;
			}
		}
		Dest.Type = pIntType;
		return true;
	case Augs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PITEMINFO pitem = GetItemFromContents(pItem)) {
			if (pitem->Type == ITEMTYPE_NORMAL) {
				if (pitem->AugData.Sockets[0].Type >= 0x1 && pitem->AugData.Sockets[0].Type <= 0x13 && pitem->AugData.Sockets[0].bVisible == true) Dest.DWord++;
				if (pitem->AugData.Sockets[1].Type >= 0x1 && pitem->AugData.Sockets[1].Type <= 0x13 && pitem->AugData.Sockets[1].bVisible == true) Dest.DWord++;
				if (pitem->AugData.Sockets[2].Type >= 0x1 && pitem->AugData.Sockets[2].Type <= 0x13 && pitem->AugData.Sockets[2].bVisible == true) Dest.DWord++;
				if (pitem->AugData.Sockets[3].Type >= 0x1 && pitem->AugData.Sockets[3].Type <= 0x13 && pitem->AugData.Sockets[3].bVisible == true) Dest.DWord++;
				if (pitem->AugData.Sockets[4].Type >= 0x1 && pitem->AugData.Sockets[4].Type <= 0x13 && pitem->AugData.Sockets[4].bVisible == true) Dest.DWord++;
				if (pitem->AugData.Sockets[5].Type >= 0x1 && pitem->AugData.Sockets[5].Type <= 0x13 && pitem->AugData.Sockets[5].bVisible == true) Dest.DWord++;
				Dest.Type = pIntType;
			}
		}
		return true;
	case Tradeskills:
		Dest.DWord = GetItemFromContents(pItem)->TradeSkills;
		Dest.Type = pBoolType;
		return true;
	case Address:
		Dest.DWord = (DWORD)GetItemFromContents(pItem);
		Dest.Type = pIntType;
		return true;
	case ContAddress:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;
#if !defined(UFEMU)//todo: check manually for uf
	case Prestige:
		Dest.DWord = GetItemFromContents(pItem)->Prestige;
		Dest.Type = pBoolType;
		return true;
#endif
	case FirstFreeSlot:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		PCONTENTS pTheCont = pItem;
		if (PITEMINFO pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1))//a worldcontainer has its item in Item1
			{
				Dest.DWord = -1;
				if (pTheCont->Contents.ContainedItems.pItems) {
					for (unsigned long N = 0; N < pTheItem->Slots; N++) {
						if (!pTheCont->Contents.ContainedItems.pItems->Item[N]) {
							Dest.DWord = N;
							break;
						}
					}
				}
				return true;
			}
		}
		return false;
	}
	case SlotsUsedByItem:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		PCONTENTS pTheCont = pItem;
		if (PITEMINFO pTheItem = GetItemFromContents(pItem))
		{
			if (pTheItem->Type == ITEMTYPE_PACK || (pTheItem->Type == ITEMTYPE_NORMAL && pTheCont->Item1))
			{
				Dest.DWord = 0;
				BOOL bExact = FALSE;
				PCHAR pName1 = GETFIRST();
				if (*pName1 == '=')
				{
					bExact = TRUE;
					pName1++;
				}
				CHAR szNameTemp[MAX_STRING] = { 0 };
				strcpy_s(szNameTemp, pName1);
				_strlwr_s(szNameTemp);
				if (pTheCont->Contents.ContainedItems.pItems) {
					for (unsigned long N = 0; N < pTheItem->Slots; N++) {
						if (pTheCont->Contents.ContainedItems.pItems->Item[N]) {
							if (PITEMINFO bagitem = GetItemFromContents(pTheCont->Contents.ContainedItems.pItems->Item[N])) {
								strcpy_s(DataTypeTemp, bagitem->Name);
								_strlwr_s(DataTypeTemp);
								if (bExact) {
									if (!_stricmp(DataTypeTemp, szNameTemp)) {
										Dest.DWord++;
									}
								}
								else {
									if (strstr(DataTypeTemp, szNameTemp)) {
										Dest.DWord++;
									}
								}
							}
						}
					}
					return true;
				}
			}
		}
		return false;
	}
#if !defined(UFEMU)//todo: check manually for uf
	case Heirloom:
		Dest.DWord = GetItemFromContents(pItem)->Heirloom;
		Dest.Type = pBoolType;
		return true;
	case Collectible:
		Dest.DWord = GetItemFromContents(pItem)->Collectible;
		Dest.Type = pBoolType;
		return true;
	case NoDestroy:
		Dest.DWord = GetItemFromContents(pItem)->NoDestroy;
		Dest.Type = pBoolType;
		return true;
#endif
	case Quest:
		Dest.DWord = GetItemFromContents(pItem)->QuestItem;
		Dest.Type = pBoolType;
		return true;
	case Expendable:
		Dest.DWord = GetItemFromContents(pItem)->Expendable;
		Dest.Type = pBoolType;
		return true;
	case ItemLink:
		Dest.Type = pStringType;
		if (ISINDEX()) {
			if (!_stricmp(GETFIRST(), "CLICKABLE")) {
				if (GetItemLink(pItem, DataTypeTemp)) {
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		if (GetItemLink(pItem, DataTypeTemp, FALSE)) {
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Icon:
		Dest.DWord = GetItemFromContents(pItem)->IconNumber;
		Dest.Type = pIntType;
		return true;
	#if !defined(UFEMU)
	case OrnamentationIcon:
		Dest.DWord = pItem->OrnamentationIcon;
		Dest.Type = pIntType;
		return true;
	#endif
	case ContentSize:
		Dest.DWord = pItem->Contents.ContentSize;
		Dest.Type = pIntType;
		return true;
	case CanUse:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (PCONTENTS pCont = pItem) {
			Dest.DWord = pCharData1->CanUseItem(&pCont, false, false);
			return true;
		}
		return false;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case Luck:
		Dest.DWord = pItem->Luck;
		Dest.Type = pIntType;
		return true;
	case MinLuck:
		Dest.DWord = GetItemFromContents(pItem)->MinLuck;
		Dest.Type = pIntType;
		return true;
	case MaxLuck:
		Dest.DWord = GetItemFromContents(pItem)->MaxLuck;
		Dest.Type = pIntType;
		return true;
#endif
	}
	return false;
}

bool MQ2WindowType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
#define pWnd ((PCSIDLWND)VarPtr.Ptr)
	PMQ2TYPEMEMBER pMethod = MQ2WindowType::FindMethod(Member);
	if (pMethod) {
		CXWnd *thewindow = (CXWnd *)pWnd;
		switch ((WindowMethods)pMethod->ID)
		{
		case LeftMouseDown:
			SendWndClick2(thewindow, "leftmousedown");
			return true;
		case LeftMouseUp:
			SendWndClick2(thewindow, "leftmouseup");
			return true;
		case LeftMouseHeld:
			SendWndClick2(thewindow, "leftmouseheld");
			return true;
		case LeftMouseHeldUp:
			SendWndClick2(thewindow, "leftmouseheldup");
			return true;
		case RightMouseDown:
			SendWndClick2(thewindow, "rightmousedown");
			return true;
		case RightMouseUp:
			SendWndClick2(thewindow, "rightmouseup");
			return true;
		case RightMouseHeld:
			SendWndClick2(thewindow, "rightmouseheld");
			return true;
		case RightMouseHeldUp:
			SendWndClick2(thewindow, "rightmouseheldup");
			return true;
		case DoOpen:
			((CXWnd*)thewindow)->Show(1, 1);
			//sprintf_s(szBuffer, "Window '%s' is now opened.", thewindow->WindowText ? thewindow->WindowText->Text : "you specified");
			//((CSidlScreenWnd*)thewindow)->StoreIniVis();
			return true;
		case DoClose:
			((CXWnd*)thewindow)->Show(0, 1);
			//sprintf_s(szBuffer, "Window '%s' is now closed.", thewindow->WindowText ? thewindow->WindowText->Text : "you specified");
			//((CSidlScreenWnd*)thewindow)->StoreIniVis();
			return true;
		case Select:
		{
			int ListIndex = atoi(GETFIRST());
			ListIndex--;
			if (ListIndex<0)
				ListIndex = 0;
			if (thewindow->GetType() == UI_Listbox) {
				if (((CListWnd*)thewindow)->ItemsArray.Count<ListIndex)
					return false;
				((CListWnd*)thewindow)->SetCurSel(ListIndex);
				int index = ((CListWnd*)thewindow)->GetCurSel();
				((CListWnd*)thewindow)->EnsureVisible(index);
				CXRect rect = ((CListWnd*)thewindow)->GetItemRect(index, 0);
				CXPoint pt = rect.CenterPoint();
				thewindow->HandleLButtonDown(&pt, 0);
				thewindow->HandleLButtonUp(&pt, 0);
				WeDidStuff();
				return true;
			}
			else if (thewindow->GetType() == UI_Combobox) {
				if (CListWnd*pListWnd = ((CComboWnd*)thewindow)->pListWnd) {
					if (pListWnd->ItemsArray.Count < ListIndex)
						return false;
					CXRect comborect = thewindow->GetScreenRect();
					CXPoint combopt = comborect.CenterPoint();
					((CComboWnd*)thewindow)->SetChoice(ListIndex);
					((CXWnd*)thewindow)->HandleLButtonDown(&combopt, 0);
					int index = pListWnd->GetCurSel();
					CXRect listrect = pListWnd->GetItemRect(index, 0);
					CXPoint listpt = listrect.CenterPoint();
					((CXWnd*)pListWnd)->HandleLButtonDown(&listpt, 0);
					((CXWnd*)pListWnd)->HandleLButtonUp(&listpt, 0);
					WeDidStuff();
					return true;
				}
			}
			break;
		}
		case Move:
			if (ISINDEX())
			{
				if (PCHAR Args = GETFIRST())
				{
					CHAR szLeft[MAX_STRING] = { 0 };
					CHAR szTop[MAX_STRING] = { 0 };
					CHAR szWidth[MAX_STRING] = { 0 };
					CHAR szHeight[MAX_STRING] = { 0 };
					GetArg(szLeft, Args, 1,0,0,0,',');
					GetArg(szTop, Args, 2,0,0,0,',');
					GetArg(szWidth, Args, 3,0,0,0,',');
					GetArg(szHeight, Args, 4,0,0,0,',');
					RECT OrgLoc = ((CXWnd*)thewindow)->GetLocation();
					CXRect rc = { OrgLoc.left,OrgLoc.top,OrgLoc.right,OrgLoc.bottom };
					if(szLeft[0])
						rc.left = atoi(szLeft);
					if(szTop[0])
						rc.top = atoi(szTop);
					if(szWidth[0])
						rc.right = rc.left + atoi(szWidth);
					if(szHeight[0])
						rc.bottom = rc.top + atoi(szHeight);
						
					((CXWnd*)thewindow)->Move(rc, true, true, true, true);
				}
			}
			return true;
		case SetBGColor:
			if (ISINDEX())
			{
				DWORD Color = _httoi_s(GETFIRST(), strlen(GETFIRST()));
				((CXWnd*)thewindow)->SetBGColor(Color);
				((CXWnd*)thewindow)->Refade();
			}
			return true;
		case SetAlpha:
			if (ISINDEX())
			{
				DWORD Alpha = _httoi_s(GETFIRST(), strlen(GETFIRST()));
				((CXWnd*)thewindow)->SetAlpha((BYTE)Alpha);
				((CXWnd*)thewindow)->Refade();
			}
			return true;
		case SetFadeAlpha:
			if (ISINDEX())
			{
				DWORD Alpha = _httoi_s(GETFIRST(), strlen(GETFIRST()));
				((CXWnd*)thewindow)->SetFadeToAlpha((BYTE)Alpha);
				((CXWnd*)thewindow)->Refade();
			}
			return true;
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2WindowType::FindMember(Member);
	if (!pMember)
		return false;

	switch ((WindowMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)pWnd;
		Dest.Type = pIntType;
		return true;
	case Open:
		Dest.DWord = pWnd->IsVisible();
		Dest.Type = pBoolType;
		return true;
	case Child:
		if (Dest.Ptr = ((CSidlScreenWnd*)VarPtr.Ptr)->GetChildItem(GETFIRST()))
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;
	case Parent:
		if (Dest.Ptr = pWnd->GetParentWindow())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;
	case FirstChild:
		if (Dest.Ptr = pWnd->GetFirstChildWnd())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;
	case Next:
		if (Dest.Ptr = pWnd->GetNextSiblingWnd())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;
	case VScrollMax:
		Dest.DWord = pWnd->GetVScrollMax();
		Dest.Type = pIntType;
		return true;
	case VScrollPos:
		Dest.DWord = pWnd->GetVScrollPos();
		Dest.Type = pIntType;
		return true;
	case VScrollPct:
		Dest.DWord = (pWnd->GetVScrollPos() * 100) / pWnd->GetVScrollMax();
		Dest.Type = pIntType;
		return true;
	case HScrollMax:
		Dest.DWord = pWnd->GetHScrollMax();
		Dest.Type = pIntType;
		return true;
	case HScrollPos:
		Dest.DWord = pWnd->GetHScrollPos();
		Dest.Type = pIntType;
		return true;
	case HScrollPct:
		Dest.DWord = (pWnd->GetHScrollPos() * 100) / pWnd->GetHScrollMax();
		Dest.Type = pIntType;
		return true;
	case Children:
		Dest.DWord = (DWORD)pWnd->GetFirstChildWnd();
		Dest.Type = pBoolType;
		return true;
	case Siblings:
		Dest.DWord = (DWORD)pWnd->GetNextSiblingWnd();
		Dest.Type = pBoolType;
		return true;
	case Minimized:
		Dest.DWord = pWnd->IsMinimized();
		Dest.Type = pBoolType;
		return true;
	case MouseOver:
		Dest.DWord = pWnd->IsMouseOver();
		Dest.Type = pBoolType;
		return true;
	case X:
		Dest.DWord = pWnd->GetLocation().left;
		Dest.Type = pIntType;
		return true;
	case Y:
		Dest.DWord = pWnd->GetLocation().top;
		Dest.Type = pIntType;
		return true;
	case Size:
		sprintf_s(DataTypeTemp, "%d,%d", pWnd->GetLocation().bottom - pWnd->GetLocation().top, pWnd->GetLocation().right - pWnd->GetLocation().left);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Width:
		Dest.DWord = pWnd->GetLocation().right - pWnd->GetLocation().left;
		Dest.Type = pIntType;
		return true;
	case Height:
		Dest.DWord = pWnd->GetLocation().bottom - pWnd->GetLocation().top;
		Dest.Type = pIntType;
		return true;
	case BGColor:
		Dest.DWord = pWnd->GetBGColor();
		Dest.Type = pArgbType;
		return true;
	case Text:
		if (((CXWnd*)pWnd)->GetType() == UI_STMLBox) {
			CStmlWnd*cstmlwnd = (CStmlWnd*)pWnd;
			GetCXStr(cstmlwnd->GetSTMLText().Ptr, DataTypeTemp, MAX_STRING);
		}
		else {
			GetCXStr(pWnd->CGetWindowText(), DataTypeTemp, MAX_STRING);
		}
		DataTypeTemp[MAX_STRING - 1] = '\0';
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Tooltip:
		GetCXStr(pWnd->GetTooltip(), DataTypeTemp, MAX_STRING);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Checked:
		Dest.Int = ((CButtonWnd*)pWnd)->Checked;
		Dest.Type = pBoolType;
		return true;
	case Highlighted://if the window in question has focus...
		Dest.Int = false;
		Dest.Type = pBoolType;
		if (PCXWNDMGR pMgr = (PCXWNDMGR)pWndMgr) {
			if ((PCSIDLWND)pWnd == pMgr->FocusWindow)
				Dest.Int = true;
		}
		return true;
	case Enabled:
		Dest.Int = (pWnd->IsEnabled() != 0);
		Dest.Type = pBoolType;
		return true;
	case Style:
		Dest.DWord = pWnd->GetWindowStyle();
		Dest.Type = pIntType;
		return true;
	case List:
	{
		Dest.Type = pStringType;
		int n = 0;
		if (((CXWnd*)pWnd)->GetType() == UI_Combobox) {
			CComboWnd*combownd = (CComboWnd*)pWnd;
			VarPtr.Ptr = combownd->pListWnd;
		}
		else if (((CXWnd*)pWnd)->GetType() != UI_Listbox)
			return false;
#ifndef ISXEQ
		if (PCHAR pComma = strchr(GETFIRST(), ',')) {
			n = atoi(pComma + 1) - 1;
			if (n < 0) n = 0;
			DebugSpew("List: index is %d\n", n);
			*pComma = '\0';
		}
#else
		if (argc == 2)
			n = atoi(argv[1]);
		if (n<0)
			n = 0;
#endif
		if (ISNUMBER())
		{
			unsigned long nIndex = GETNUMBER();
			if (!nIndex)
				return false;
			nIndex--;
			CXStr Str;
			((CListWnd*)pWnd)->GetItemText(&Str, nIndex, n);
			GetCXStr(Str.Ptr, DataTypeTemp, MAX_STRING);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			// name
			BOOL bEqual = false;
			CHAR Name[MAX_STRING] = { 0 };
			if (GETFIRST()[0] == '=')
			{
				bEqual = true;
				strcpy_s(Name, &GETFIRST()[1]);
			}
			else
				strcpy_s(Name, GETFIRST());
			_strlwr_s(Name);
			unsigned long nIndex = 0;
			while (1)
			{
				CXStr Str;
				((CListWnd*)pWnd)->GetItemText(&Str, nIndex, n);
				GetCXStr(Str.Ptr, DataTypeTemp, MAX_STRING);
				if (DataTypeTemp[0] == 0)
					return false;

				if (bEqual)
				{
					if (!_stricmp(DataTypeTemp, Name))
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
				else
				{
					_strlwr_s(DataTypeTemp);
					if (strstr(DataTypeTemp, Name))
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
				nIndex++;
			}
		}
		return false;
	}
	case Name:
		Dest.Type = pStringType;
		if (CXMLData *pXMLData = ((CXWnd*)pWnd)->GetXMLData())
		{
			if (GetCXStr(pXMLData->Name.Ptr, DataTypeTemp, MAX_STRING))
			{
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;
	case ScreenID:
		Dest.Type = pStringType;
		if (CXMLData *pXMLData = ((CXWnd*)pWnd)->GetXMLData())
		{
			if (GetCXStr(pXMLData->ScreenID.Ptr, DataTypeTemp, MAX_STRING))
			{
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;
	case Type:
		Dest.Type = pStringType;
		if (CXMLData *pXMLData = ((CXWnd*)pWnd)->GetXMLData())
		{
			if (GetCXStr(pXMLData->TypeName.Ptr, DataTypeTemp, MAX_STRING))
			{
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;
	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (((CXWnd*)pWnd)->GetType() == UI_Listbox)
		{
			CListWnd*clist = (CListWnd*)pWnd;
			Dest.DWord = clist->ItemsArray.Count;
		}
		else if (((CXWnd*)pWnd)->GetType() == UI_Combobox)
		{
			CComboWnd *ccombo = (CComboWnd*)pWnd;
			if (ccombo->pListWnd) {
				Dest.DWord = ccombo->pListWnd->ItemsArray.Count;
			}
		}
		return true;
	case HisTradeReady:
		Dest.Int = 0;
		Dest.Type = pBoolType;
		if (PEQTRADEWINDOW pTrade = (PEQTRADEWINDOW)pTradeWnd) {
			Dest.Int = pTrade->HisTradeReady;
		}
		return true;
	case MyTradeReady:
		Dest.Int = 0;
		Dest.Type = pBoolType;
		if (PEQTRADEWINDOW pTrade = (PEQTRADEWINDOW)pTradeWnd) {
			Dest.Int = pTrade->MyTradeReady;
		}
		return true;
	case GetCurSel:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (((CXWnd*)pWnd)->GetType() == UI_Combobox) {
			CComboWnd *combo = (CComboWnd*)pWnd;
			VarPtr.Ptr = combo->pListWnd;
		}
		else if (((CXWnd*)pWnd)->GetType() != UI_Listbox)
			return false;
		Dest.DWord = 1 + ((CListWnd *)pWnd)->GetCurSel();
		return true;
	}
	return false;
#undef pWnd
}
bool MQ2MenuType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	CContextMenuManager*pMgr = (CContextMenuManager*)VarPtr.Ptr;
	PMQ2TYPEMEMBER pMethod = MQ2MenuType::FindMethod(Member);
	if (pMethod)
	{
		switch ((MenuMethods)pMethod->ID)
		{
			case Select:
			{
				if (ISINDEX())
				{
					if (pMgr->NumVisibleMenus == 1)
					{
						CHAR szArg[MAX_STRING] = { 0 };
						CHAR szArg2[MAX_STRING] = { 0 };
						strcpy_s(szArg,GETFIRST());
						_strlwr_s(szArg);
						if (pMgr->CurrMenu < 8)
						{
							int currmen = pMgr->CurrMenu;
							if (CContextMenu*menu = pMgr->pCurrMenus[currmen])
							{
								CXStr Str;
								PCXSTR pStr = 0;
								for (int i = 0; i < menu->NumItems; i++)
								{
									((CListWnd*)menu)->GetItemText(&Str, i, 1);
									GetCXStr(Str.Ptr, szArg2);
									if (szArg2[0] != '\0')
									{
										_strlwr_s(szArg2);
										if (strstr(szArg2, szArg))
										{
											WriteChatf("\ay[${Menu.Select}] SUCCESS\ax: Clicking \"%s\" at position %d in the menu.", szArg2, i);
											((CXWnd*)(pMgr))->WndNotification((CXWnd*)menu, XWM_LMOUSEUP, (void*)i);
											Dest.DWord = 1;
											Dest.Type = pBoolType;
											return true;
										}
									}
								}
								WriteChatf("\ar[${Menu.Select}] FAILED\ax: No Menu item was found with the word %s in it", szArg);
							}
						}
					}
				}
				break;
			}
		};
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		return true;
	}
	PMQ2TYPEMEMBER pMember = MQ2MenuType::FindMember(Member);
	if (!pMember)
	{
		if (pMgr->NumVisibleMenus == 1)
		{
			if (CContextMenu*pMenu = pMgr->pCurrMenus[pMgr->CurrMenu])
			{
				return pWindowType->GetMember(*(MQ2VARPTR*)&pMenu, Member, Index, Dest);
			}
		}
		return false;
	}

	switch ((MenuMembers)pMember->ID)
	{
		case Address:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pMgr->NumVisibleMenus == 1)
			{
				if (CContextMenu*pMenu = pMgr->pCurrMenus[pMgr->CurrMenu])
				{
					Dest.DWord = (DWORD)pMenu;
					return true;
				}
			}
			return false;
		case NumVisibleMenus:
			Dest.DWord = pMgr->NumVisibleMenus;
			Dest.Type = pIntType;
			return true;
		case CurrMenu:
			Dest.DWord = pMgr->CurrMenu;
			Dest.Type = pIntType;
			return true;
		case Name:
			Dest.Type = pStringType;
			if (pMgr->NumVisibleMenus == 1)
			{
				if (pMgr->CurrMenu < 8)
				{
					int currmen = pMgr->CurrMenu;
					if (CContextMenu*menu = pMgr->pCurrMenus[currmen])
					{
						CXStr Str;
						((CListWnd*)menu)->GetItemText(&Str, 0, 1);
						GetCXStr(Str.Ptr, DataTypeTemp);
						if (DataTypeTemp[0] != '\0')
						{
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			return false;
		case NumItems:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pMgr->NumVisibleMenus == 1)
			{
				if (pMgr->CurrMenu < 8)
				{
					int currmen = pMgr->CurrMenu;
					if (CContextMenu*menu = pMgr->pCurrMenus[currmen])
					{
						Dest.DWord = menu->NumItems;
						return true;
					}
				}
			}
			return false;
		case Items:
			Dest.Type = pStringType;
			if (ISNUMBER())
			{
				if (pMgr->NumVisibleMenus == 1)
				{
					if (pMgr->CurrMenu < 8)
					{
						int index = GETNUMBER();
						int currmen = pMgr->CurrMenu;
						if (CContextMenu*menu = pMgr->pCurrMenus[currmen])
						{
							if (index < menu->NumItems)
							{
								CXStr Str;
								((CListWnd*)menu)->GetItemText(&Str, index, 1);
								GetCXStr(Str.Ptr, DataTypeTemp);
								Dest.Ptr = &DataTypeTemp[0];
								return true;
							}
						}
					}
				}
			}
			return false;
	}
	return false;
}
bool MQ2CurrentZoneType::GETMEMBER()
{
	PZONEINFO pthezone = (PZONEINFO)pZoneInfo;
#define pZone ((PZONEINFO)pZoneInfo)
	PMQ2TYPEMEMBER pMember = MQ2CurrentZoneType::FindMember(Member);
	if (!pMember)
	{
		int zid = (pZone->ZoneID & 0x7FFF);
		if (zid < MAX_ZONES)
		{
			if (PZONELIST pZList = ((PWORLDDATA)pWorldData)->ZoneArray[zid])
			{
#ifndef ISXEQ
				return pZoneType->GetMember(*(MQ2VARPTR*)&pZList, Member, Index, Dest);
#else
				return pZoneType->GetMember(*(LSVARPTR*)&pZList, Member, argc, argv, Dest);
#endif
			}
		}
		return false;
	}
	switch ((CurrentZoneMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case ID:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (PCHARINFO pChar = GetCharInfo()) {
			Dest.Int = (pChar->zoneId & 0x7FFF);
			Dest.Type = pIntType;
			return true;
		}
		return false;
	case Name:
		strcpy_s(DataTypeTemp, pZone->LongName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case ShortName:
		strcpy_s(DataTypeTemp, pZone->ShortName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;
	case Type:
		Dest.DWord = pZone->OutDoor;
		Dest.Type = pIntType;
		return true;
	case Gravity:
		Dest.Float = pZone->ZoneGravity;
		Dest.Type = pFloatType;
		return true;
	case SkyType:
		Dest.DWord = pZone->SkyType;
		Dest.Type = pIntType;
		return true;
#if 0
	case SafeN:
	case SafeY:
		Dest.Float = pZone->SafeYLoc;
		Dest.Type = pFloatType;
		return true;
	case SafeW:
	case SafeX:
		Dest.Float = pZone->SafeXLoc;
		Dest.Type = pFloatType;
		return true;
	case SafeU:
	case SafeZ:
		Dest.Float = pZone->SafeZLoc;
		Dest.Type = pFloatType;
		return true;
#endif
	case MinClip:
		Dest.Float = pZone->MinClip;
		Dest.Type = pFloatType;
		return true;
	case MaxClip:
		Dest.Float = pZone->MaxClip;
		Dest.Type = pFloatType;
		return true;
	case ZoneType:
		Dest.DWord = (*EQADDR_ZONETYPE);
		Dest.Type = pIntType;
		return true;
	case Dungeon:
	case Indoor:
		Dest.DWord = indoor;
		Dest.Type = pBoolType;
		return true;
	case Outdoor:
		Dest.DWord = outdoor;
		Dest.Type = pBoolType;
		return true;
	case NoBind:
		Dest.DWord = !bindable;
		Dest.Type = pBoolType;
		return true;
	}
	return false;
#undef pZone
}

bool MQ2ZoneType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PZONELIST pZone = (PZONELIST)VarPtr.Ptr;
	PMQ2TYPEMEMBER pMember = MQ2ZoneType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((ZoneMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, pZone->LongName);
		Dest.Ptr = &DataTypeTemp;
		Dest.Type = pStringType;
		return true;
	case ShortName:
		strcpy_s(DataTypeTemp, pZone->ShortName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case ID:
		Dest.Int = pZone->Id & 0x7FFF;
		Dest.Type = pIntType;
		return true;
	case ZoneFlags:
		Dest.UInt64 = pZone->ZoneFlags;
		Dest.Type = pInt64Type;
		return true;
	}
	return false;
}

bool MQ2BodyType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2BodyType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((BodyMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, GetBodyTypeDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	return false;
}
bool MQ2DeityType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2DeityType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((DeityMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, pEverQuest->GetDeityDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Team:
		strcpy_s(DataTypeTemp, szDeityTeam[GetDeityTeamByID(VarPtr.DWord)]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	return false;
}
bool MQ2ClassType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2ClassType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((ClassMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, GetClassDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case ShortName:
		strcpy_s(DataTypeTemp, pEverQuest->GetClassThreeLetterCode(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case CanCast:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].CanCast;
			return true;
		}
		return false;
	case PureCaster:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].PureCaster;
			return true;
		}
		return false;
	case PetClass:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].PetClass;
			return true;
		}
		return false;
	case DruidType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].DruidType;
			return true;
		}
		return false;
	case ShamanType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].ShamanType;
			return true;
		}
		return false;
	case NecromancerType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].NecroType;
			return true;
		}
		return false;
	case ClericType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 16)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].ClericType;
			return true;
		}
		return false;
	case HealerType:
		Dest.DWord = (VarPtr.DWord == 2 || VarPtr.DWord == 6 || VarPtr.DWord == 10);
		Dest.Type = pBoolType;
		return true;
	case MercType:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (VarPtr.DWord <= 17)
		{
			Dest.DWord = ClassInfo[VarPtr.DWord].MercType;
			return true;
		}
		return false;
	}
	return false;
}
bool MQ2RaceType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2RaceType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((RaceMembers)pMember->ID)
	{
	case ID:
		Dest.Ptr = VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(VarPtr.DWord));
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	return false;
}


bool MQ2SwitchType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PDOOR pTheSwitch = ((PDOOR)VarPtr.Ptr);
	PMQ2TYPEMEMBER pMethod = MQ2SwitchType::FindMethod(Member);
	if (pMethod) {
		switch ((SwitchMethods)pMethod->ID)
		{
			case Toggle:
			{
				int KeyID = 0;
				int Skill = 0;
				if(PCHARINFO2 pChar2 = GetCharInfo2()) {
					if (pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor)
					{
						if (PITEMINFO pItem = GetItemFromContents(pChar2->pInventoryArray->Inventory.Cursor))
						{
							if (pItem->Type != ITEMTYPE_NORMAL)
							{
								switch (pItem->Type)
								{
								case 33://EQIC_KEY
									KeyID = pItem->ItemNumber;
									Skill = 0;
									break;
								case 35://EQIC_LOCKPICK
									KeyID = pItem->ItemNumber;
									Skill = GetAdjustedSkill(SKILL_PICKLOCK);
									break;
								default:
									KeyID = pItem->ItemNumber;
									Skill = 0;
									break;
								}
							}
						}
					}
				}
				((EQSwitch *)pTheSwitch->pSwitch)->UseSwitch(((PSPAWNINFO)pLocalPlayer)->SpawnID, KeyID, Skill);
				return true;
			}
			default:
				break;
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2SwitchType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((SwitchMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)VarPtr.Ptr;
		Dest.Type = pIntType;
		return true;
	case ID:
		Dest.DWord = pTheSwitch->ID;
		Dest.Type = pIntType;
		return true;
	case W:
	case X:
		Dest.Float = pTheSwitch->X;
		Dest.Type = pFloatType;
		return true;
	case N:
	case Y:
		Dest.Float = pTheSwitch->Y;
		Dest.Type = pFloatType;
		return true;
	case U:
	case Z:
		Dest.Float = pTheSwitch->Z;
		Dest.Type = pFloatType;
		return true;
	case DefaultW:
	case DefaultX:
		Dest.Float = pTheSwitch->DefaultX;
		Dest.Type = pFloatType;
		return true;
	case DefaultN:
	case DefaultY:
		Dest.Float = pTheSwitch->DefaultY;
		Dest.Type = pFloatType;
		return true;
	case DefaultU:
	case DefaultZ:
		Dest.Float = pTheSwitch->DefaultZ;
		Dest.Type = pFloatType;
		return true;
	case Heading:
		Dest.Float = pTheSwitch->Heading*0.703125f;
		Dest.Type = pHeadingType;
		return true;
	case DefaultHeading:
		Dest.Float = pTheSwitch->DefaultHeading*0.703125f;
		Dest.Type = pHeadingType;
		return true;
	case Open:
		Dest.DWord = (pTheSwitch->State == 1);
		Dest.Type = pBoolType;
		return true;
	case HeadingTo:
		Dest.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pTheSwitch->Y, pTheSwitch->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
		if (Dest.Float<0.0f)
			Dest.Float += 360.0f;
		else if (Dest.Float >= 360.0f)
			Dest.Float -= 360.0f;
		Dest.Type = pHeadingType;
		return true;
	case Name:
		Dest.Ptr = &pTheSwitch->Name[0];
		Dest.Type = pStringType;
		return true;
	case Distance:
	{
		float BoundingRadius = 0;
		if (ActorBase*pBase = (ActorBase*)pTheSwitch->pSwitch) {
			BoundingRadius = pBase->GetBoundingRadius();
		}
		else {
			BoundingRadius = pTheSwitch->ScaleFactor * 0.01f;
		}
		if (BoundingRadius)
		{
			float thedist = GetDistance(pTheSwitch->X, pTheSwitch->Y) - (BoundingRadius / 2);
			if (thedist < 0.0f)
				thedist = 0.0f;
			Dest.Float = thedist;
		} else {
			Dest.Float = GetDistance(pTheSwitch->X, pTheSwitch->Y);
		}
		Dest.Type = pFloatType;
		return true;
	}
	case Distance3D:
	{
		FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pTheSwitch->X;
		FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pTheSwitch->Y;
		FLOAT Z = ((PSPAWNINFO)pCharSpawn)->Z - pTheSwitch->Z;
		float BoundingRadius = 0;
		float thedist = 0;
		if (ActorBase*pBase = (ActorBase*)pTheSwitch->pSwitch) {
			BoundingRadius = pBase->GetBoundingRadius();
		}
		else {
			BoundingRadius = pTheSwitch->ScaleFactor * 0.01f;
		}
		if (BoundingRadius)
		{
			thedist = sqrtf(X*X + Y*Y + Z*Z) - (BoundingRadius / 2);
			if (thedist < 0.0f)
				thedist = 0.0f;
			Dest.Float = thedist;
		} else {
			Dest.Float = sqrtf(X*X + Y*Y + Z*Z);
		}
		Dest.Type = pFloatType;
		return true;
	}
	case xLineOfSight:
		Dest.DWord = (CastRay(GetCharInfo()->pSpawn, pTheSwitch->Y, pTheSwitch->X, pTheSwitch->Z));
		Dest.Type = pBoolType;
		return true;
	}
	return false;
}

bool MQ2GroundType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;

	PGROUNDOBJECT pGroundObject = (PGROUNDOBJECT)VarPtr.Ptr;
	if(pGroundObject->Type==GO_None)
		return false;
	PMQ2TYPEMEMBER pMethod = MQ2GroundType::FindMethod(Member);
	if (pMethod) {
		switch ((GroundMethods)pMethod->ID)
		{
		case Grab:
		{
			Dest.DWord = 0;
			Dest.Type = pBoolType;
			PEQSWITCH pSwitch = 0;
			if (pGroundObject->Type == GO_GroundType)
			{
				pSwitch = (PEQSWITCH)pGroundObject->pGroundItem->pSwitch;
			}
			if (pSwitch) {
				if (PGROUNDITEM pGround = pGroundObject->pGroundItem)
				{
					CHAR szName[256] = { 0 };
					GetFriendlyNameForGroundItem(pGround, szName, sizeof(szName));
					float dist3d = Get3DDistance(((PSPAWNINFO)pCharSpawn)->X, ((PSPAWNINFO)pCharSpawn)->Y, ((PSPAWNINFO)pCharSpawn)->Z, pGround->X, pGround->Y, pGround->Z);
					if (dist3d <= 20.0f) {
						SPAWNINFO tSpawn = { 0 };
						strcpy_s(tSpawn.Name, szName);
						strcpy_s(tSpawn.DisplayedName, szName);
						tSpawn.Y = pGround->Y;
						tSpawn.X = pGround->X;
						tSpawn.Z = pGround->pSwitch->Z;
						tSpawn.Type = SPAWN_NPC;
						tSpawn.HPCurrent = 1;
						tSpawn.HPMax = 1;
						tSpawn.Heading = pGround->Heading;
						tSpawn.mActorClient.Race = pGround->DropID;
						tSpawn.StandState = STANDSTATE_STAND;//im using this for /clicked left item -eqmule
						CopyMemory(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
						pGroundTarget = pGround;
						*((DWORD*)__LMouseHeldTime) = ((PCDISPLAY)pDisplay)->TimeStamp - 0x45;
						pEverQuest->LMouseUp(-10000, -10000);
						ZeroMemory(&EnviroTarget, sizeof(EnviroTarget));
						ZeroMemory(&GroundObject, sizeof(GroundObject));
						pGroundTarget = NULL;
						Dest.DWord = 1;
						return true;
					}
					else {
						MacroError("You are %.2f away from the %s, move within 20 feet of it to Grab it.", dist3d, szName);
					}
				}
			}
			return true;
		}
		case DoTarget:
		{
			CHAR szName[256] = { 0 };
			SPAWNINFO tSpawn = { 0 };
			if (pGroundObject->Type == GO_GroundType)
			{
				GetFriendlyNameForGroundItem(pGroundObject->pGroundItem, szName, sizeof(szName));
				tSpawn.Y = pGroundObject->pGroundItem->Y;
				tSpawn.X = pGroundObject->pGroundItem->X;
				tSpawn.Z = pGroundObject->pGroundItem->Z;
				tSpawn.Heading = pGroundObject->pGroundItem->Heading;
				tSpawn.mActorClient.Race = pGroundObject->pGroundItem->DropID;
				pGroundTarget = pGroundObject->pGroundItem;
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGroundTarget;
			}
			else {
				if (EQPlacedItem*Placed = (EQPlacedItem*)pGroundObject->ObjPtr)
				{
					strcpy_s(szName, Placed->Name);
					tSpawn.Y = Placed->Y;
					tSpawn.X = Placed->X;
					tSpawn.Z = Placed->Z;
					tSpawn.Heading = Placed->Heading;
					tSpawn.mActorClient.Race = Placed->RealEstateItemID;
					GroundObject.Type = GO_ObjectType;
					GroundObject.ObjPtr = (void*)Placed;

					GroundObject.GroundItem.DropID = Placed->RealEstateItemID;
					GroundObject.GroundItem.DropSubID = Placed->RealEstateID;
					GroundObject.GroundItem.Expires = 0;
					GroundObject.GroundItem.Heading = Placed->Heading;
					GroundObject.GroundItem.ID.pObject = NULL;
					strcpy_s(GroundObject.GroundItem.Name, Placed->Name);
					GroundObject.GroundItem.Pitch = Placed->Angle;
					GroundObject.GroundItem.pNext = 0;
					GroundObject.GroundItem.pPrev = 0;
					GroundObject.GroundItem.pSwitch = (PEQSWITCH)Placed->pActor;
					GroundObject.GroundItem.Roll = Placed->Roll;
					GroundObject.GroundItem.Scale = Placed->Scale;
					GroundObject.GroundItem.Weight = 0;
					GroundObject.GroundItem.X = Placed->X;
					GroundObject.GroundItem.Y = Placed->Y;
					GroundObject.GroundItem.Z = Placed->Z;
					GroundObject.GroundItem.ZoneID = ((PSPAWNINFO)pLocalPlayer)->GetZoneID() & 0x7FFF;
					pGroundTarget = &GroundObject.GroundItem;
				}
			}
			strcpy_s(tSpawn.Name, szName);
			strcpy_s(tSpawn.DisplayedName, szName);
			tSpawn.Type = SPAWN_NPC;
			tSpawn.HPCurrent = 1;
			tSpawn.HPMax = 1;
			tSpawn.StandState = STANDSTATE_STAND;//im using this for /clicked left item -eqmule
			CopyMemory(&EnviroTarget, &tSpawn, sizeof(EnviroTarget));
			Dest.Ptr = pGroundObject;
			Dest.Type = pGroundType;
			return true;
		}
		case DoFace:
		{
			float theDistance = 100000.0f;
			if (pGroundObject->Type == GO_GroundType)
			{

				gFaceAngle = (atan2(pGroundObject->pGroundItem->X - ((PSPAWNINFO)pCharSpawn)->X, pGroundObject->pGroundItem->Y - ((PSPAWNINFO)pCharSpawn)->Y) * 256.0f / PI);
				theDistance = Get3DDistance(((PSPAWNINFO)pCharSpawn)->X, ((PSPAWNINFO)pCharSpawn)->Y, ((PSPAWNINFO)pCharSpawn)->Z, pGroundObject->pGroundItem->X, pGroundObject->pGroundItem->Y, pGroundObject->pGroundItem->Z);
				gLookAngle = (atan2(pGroundObject->pGroundItem->Z - ((PSPAWNINFO)pCharSpawn)->Z - ((PSPAWNINFO)pCharSpawn)->AvatarHeight*StateHeightMultiplier(((PSPAWNINFO)pCharSpawn)->StandState), (FLOAT)theDistance) * 256.0f / PI);
			}
			else {
				if (EQPlacedItem*Placed = (EQPlacedItem*)pGroundObject->ObjPtr)
				{
					gFaceAngle = (atan2(Placed->X - ((PSPAWNINFO)pCharSpawn)->X, Placed->Y - ((PSPAWNINFO)pCharSpawn)->Y) * 256.0f / PI);
					theDistance = Get3DDistance(((PSPAWNINFO)pCharSpawn)->X, ((PSPAWNINFO)pCharSpawn)->Y, ((PSPAWNINFO)pCharSpawn)->Z, Placed->X, Placed->Y, Placed->Z);
					gLookAngle = (atan2(Placed->Z - ((PSPAWNINFO)pCharSpawn)->Z - ((PSPAWNINFO)pCharSpawn)->AvatarHeight*StateHeightMultiplier(((PSPAWNINFO)pCharSpawn)->StandState), (FLOAT)theDistance) * 256.0f / PI);
				}
			}
			if (gFaceAngle >= 512.0f)
				gFaceAngle -= 512.0f;
			if (gFaceAngle<0.0f)
				gFaceAngle += 512.0f;
			Dest.Ptr = pGroundObject;
			Dest.Type = pGroundType;
			return true;
		}
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2GroundType::FindMember(Member);
	if (!pMember)
		return false;
	if (pGroundObject->Type == GO_GroundType)
	{
		PGROUNDITEM pGround = pGroundObject->pGroundItem;
		switch ((GroundMembers)pMember->ID)
		{
		case Address:
			Dest.DWord = (DWORD)VarPtr.Ptr;
			Dest.Type = pIntType;
			return true;
		case ID:
			Dest.DWord = pGround->DropID;
			Dest.Type = pIntType;
			return true;
		case SubID:
			Dest.DWord = pGround->DropSubID;
			Dest.Type = pIntType;
			return true;
		case ZoneID:
			Dest.DWord = (pGround->ZoneID & 0x7FFF);
			Dest.Type = pIntType;
			return true;
		case W:
		case X:
			Dest.Float = pGround->X;
			Dest.Type = pFloatType;
			return true;
		case N:
		case Y:
			Dest.Float = pGround->Y;
			Dest.Type = pFloatType;
			return true;
		case U:
		case Z:
			Dest.Float = pGround->Z;
			Dest.Type = pFloatType;
			return true;
		case Name:
			strcpy_s(DataTypeTemp, pGround->Name);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayName:
		{
			DataTypeTemp[0] = '\0';
			GetFriendlyNameForGroundItem(pGround, DataTypeTemp, sizeof(DataTypeTemp));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		case Heading:
			Dest.Float = pGround->Heading*0.703125f;
			Dest.Type = pHeadingType;
			return true;
		case Distance:
			Dest.Float = GetDistance(pGround->X, pGround->Y);
			Dest.Type = pFloatType;
			return true;
		case Distance3D:
		{
			FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pGround->X;
			FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pGround->Y;
			FLOAT Z = 0;
			if (pGround->pSwitch)
				Z = ((PSPAWNINFO)pCharSpawn)->Z - pGround->pSwitch->Z;
			else
				Z = ((PSPAWNINFO)pCharSpawn)->Z - pGround->Z;
			Dest.Float = sqrtf(X*X + Y * Y + Z * Z);
			Dest.Type = pFloatType;
			return true;
		}
		case HeadingTo:
			Dest.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pGround->Y, pGround->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;
			Dest.Type = pHeadingType;
			return true;
		case xLineOfSight:
			Dest.DWord = (CastRay(GetCharInfo()->pSpawn, pGround->Y, pGround->X, pGround->Z));
			Dest.Type = pBoolType;
			return true;
		case First:
			Dest.Type = pGroundType;
			if (PGROUNDITEM pItem = pGround)
			{
				while (pItem->pPrev)
				{
					pItem = pItem->pPrev;
				}
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		case Last:
			Dest.Type = pGroundType;
			if (PGROUNDITEM pItem = pGround)
			{
				while (pItem->pNext)
				{
					pItem = pItem->pNext;
				}
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		case Next:
			Dest.Type = pGroundType;
			if (pGround->pNext)
			{
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGround->pNext;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		case Prev:
			Dest.Type = pGroundType;
			if (pGround->pPrev)
			{
				GroundObject.Type = GO_GroundType;
				GroundObject.pGroundItem = pGround->pPrev;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		}
	}
	else
	{
		EQPlacedItem* pGround = (EQPlacedItem*)pGroundObject->ObjPtr;
		switch ((GroundMembers)pMember->ID)
		{
		case Address:
			Dest.DWord = (DWORD)VarPtr.Ptr;
			Dest.Type = pIntType;
			return true;
		case ID:
			Dest.DWord = pGround->RealEstateItemID;
			Dest.Type = pIntType;
			return true;
		case SubID:
			Dest.DWord = pGround->RealEstateID;
			Dest.Type = pIntType;
			return true;
		case ZoneID:
			Dest.DWord = (((PSPAWNINFO)pLocalPlayer)->GetZoneID() & 0x7FFF);
			Dest.Type = pIntType;
			return true;
		case W:
		case X:
			Dest.Float = pGround->X;
			Dest.Type = pFloatType;
			return true;
		case N:
		case Y:
			Dest.Float = pGround->Y;
			Dest.Type = pFloatType;
			return true;
		case U:
		case Z:
			Dest.Float = pGround->Z;
			Dest.Type = pFloatType;
			return true;
		case Name:
			strcpy_s(DataTypeTemp, pGround->Name);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayName:
		{
			Dest.Type = pStringType;
			RealEstateManagerClient& manager = RealEstateManagerClient::Instance();
			if (&manager)
			{
				const RealEstateItemClient* pRealEstateItem = manager.GetItemByRealEstateAndItemIds(pGround->RealEstateID, pGround->RealEstateItemID);
				if (pRealEstateItem)
				{
					if (PCONTENTS pCont = pRealEstateItem->Object.pItemBase.pObject)
					{
						if (PITEMINFO pItem = GetItemFromContents(pCont))
						{
							strcpy_s(DataTypeTemp, pItem->Name);
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			return false;
		}
		case Heading:
			Dest.Float = pGround->Heading*0.703125f;
			Dest.Type = pHeadingType;
			return true;
		case Distance:
			Dest.Float = GetDistance(pGround->X, pGround->Y);
			Dest.Type = pFloatType;
			return true;
		case Distance3D:
		{
			FLOAT X = ((PSPAWNINFO)pCharSpawn)->X - pGround->X;
			FLOAT Y = ((PSPAWNINFO)pCharSpawn)->Y - pGround->Y;
			FLOAT Z = ((PSPAWNINFO)pCharSpawn)->Z - pGround->Z;
			Dest.Float = sqrtf(X*X + Y * Y + Z * Z);
			Dest.Type = pFloatType;
			return true;
		}
		case HeadingTo:
			Dest.Float = (FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pGround->Y, pGround->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
			if (Dest.Float < 0.0f)
				Dest.Float += 360.0f;
			else if (Dest.Float >= 360.0f)
				Dest.Float -= 360.0f;
			Dest.Type = pHeadingType;
			return true;
		case xLineOfSight:
			Dest.DWord = (CastRay(GetCharInfo()->pSpawn, pGround->Y, pGround->X, pGround->Z));
			Dest.Type = pBoolType;
			return true;
		case First:
			Dest.Type = pGroundType;
			if (EQPlacedItem *pItem = pGround)
			{
				while (pItem->pPrev)
				{
					pItem = pItem->pPrev;
				}
				GroundObject.Type = GO_ObjectType;
				GroundObject.ObjPtr = (void*)pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		case Last:
			Dest.Type = pGroundType;
			if (EQPlacedItem *pItem = pGround)
			{
				while (pItem->pNext)
				{
					pItem = pItem->pNext;
				}
				GroundObject.Type = GO_ObjectType;
				GroundObject.ObjPtr = (void*)pItem;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		case Next:
			Dest.Type = pGroundType;
			if (pGround->pNext)
			{
				GroundObject.Type = GO_ObjectType;
				GroundObject.ObjPtr = (void*)pGround->pNext;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		case Prev:
			Dest.Type = pGroundType;
			if (pGround->pPrev)
			{
				GroundObject.Type = GO_ObjectType;
				GroundObject.ObjPtr = (void*)pGround->pPrev;
				Dest.Ptr = &GroundObject;
				return true;
			}
			return false;
		}
	}
	return false;
}
bool MQ2MacroQuestType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2MacroQuestType::FindMember(Member);
	if (!pMember)
#ifndef ISXEQ
		return pEverQuestType->GetMember(*(MQ2VARPTR*)&VarPtr.Ptr, Member, Index, Dest);
#else
		return pEverQuestType->GetMember(*(LSVARPTR*)&VarPtr.Ptr, Member, argc, argv, Dest);
#endif
	switch ((MacroQuestMembers)pMember->ID)
	{
	case Error:
		if (gszLastNormalError[0])// QUIT SETTING THIS MANUALLY, USE MacroError, FatalError, ETC
		{
			Dest.Ptr = &gszLastNormalError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;
	case SyntaxError:
		if (gszLastSyntaxError[0])
		{
			Dest.Ptr = &gszLastSyntaxError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;
	case MQ2DataError:
		if (gszLastMQ2DataError[0])
		{
			Dest.Ptr = &gszLastMQ2DataError[0];
			Dest.Type = pStringType;
			return true;
		}
		return false;
	case BuildDate:
		SYSTEMTIME st;
		HANDLE hFile;
		WIN32_FIND_DATA FileData;
		CHAR szBuffer[MAX_STRING];
		sprintf_s(szBuffer, "%s\\MQ2Main.dll", gszINIPath);
		hFile = FindFirstFile(szBuffer, &FileData);
		// Convert the creation time time to local time.
		FileTimeToSystemTime(&FileData.ftLastWriteTime, &st);
		FindClose(hFile);
		sprintf_s(DataTypeTemp, "%04d%02d%02d", st.wYear, st.wMonth, st.wDay);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Build:
		Dest.DWord = gBuild;
		Dest.Type = pIntType;
		return true;
	case Path:
		strcpy_s(DataTypeTemp, gszINIPath);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Version:
	{
		DataTypeTemp[0] = '\0';
		HRESULT ret = S_FALSE;
		CHAR    szGetName[256];
		CHAR    szResult[2048];
		LPCSTR   lpVersion;        // String pointer to Item text
		DWORD   dwVerInfoSize;    // Size of version information block
		DWORD   dwVerHnd = 0;        // An 'ignored' parameter, always '0'
		UINT    uVersionLen;
		BOOL    bRetCode;
		HMODULE hMq2Main = 0;// GetModuleHandle("mq2main.dll");
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)&DataTypeTemp, &hMq2Main);
		GetModuleFileName(hMq2Main, szResult, 2048);
		dwVerInfoSize = GetFileVersionInfoSize(szResult, &dwVerHnd);
		if (dwVerInfoSize) {
			LPSTR   lpstrVffInfo;
			HANDLE  hMem;
			hMem = GlobalAlloc(GMEM_MOVEABLE, dwVerInfoSize);
			lpstrVffInfo = (LPSTR)GlobalLock(hMem);
			GetFileVersionInfo(szResult, dwVerHnd, dwVerInfoSize, lpstrVffInfo);

			sprintf_s(szGetName,"%s","\\VarFileInfo\\Translation");
			uVersionLen = 0;
			lpVersion = NULL;
			bRetCode = VerQueryValue((LPVOID)lpstrVffInfo,szGetName,(void **)&lpVersion,(UINT *)&uVersionLen);
			if (bRetCode && uVersionLen && lpVersion) {
				sprintf_s(szResult, "%04x%04x", (WORD)(*((DWORD *)lpVersion)),(WORD)(*((DWORD *)lpVersion) >> 16));
			}
			else {
				sprintf_s(szResult, "%s","041904b0");
			}
			sprintf_s(szGetName, "\\StringFileInfo\\%s\\FileVersion", szResult);
			uVersionLen = 0;
			lpVersion = NULL;
			bRetCode = VerQueryValue((LPVOID)lpstrVffInfo,szGetName,(void **)&lpVersion,(UINT *)&uVersionLen);
			if (bRetCode && uVersionLen && lpVersion) {
				sprintf_s(DataTypeTemp,"%s", lpVersion);
			}
			GlobalFree(hMem);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case InternalName:
	{
		DataTypeTemp[0] = '\0';
		Dest.Type = pStringType;
		HRESULT ret = S_FALSE;
		CHAR    szGetName[256];
		CHAR    szResult[2048];
		LPCSTR   lpVersion;        // String pointer to Item text
		DWORD   dwVerInfoSize;    // Size of version information block
		DWORD   dwVerHnd = 0;        // An 'ignored' parameter, always '0'
		UINT    uVersionLen;
		BOOL    bRetCode;
		HMODULE hMq2Main = 0;// GetModuleHandle("mq2main.dll");
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)&DataTypeTemp, &hMq2Main);
		GetModuleFileName(hMq2Main, szResult, 2048);
		dwVerInfoSize = GetFileVersionInfoSize(szResult, &dwVerHnd);
		if (dwVerInfoSize) {
			LPSTR   lpstrVffInfo;
			HANDLE  hMem;
			hMem = GlobalAlloc(GMEM_MOVEABLE, dwVerInfoSize);
			lpstrVffInfo = (LPSTR)GlobalLock(hMem);
			GetFileVersionInfo(szResult, dwVerHnd, dwVerInfoSize, lpstrVffInfo);

			sprintf_s(szGetName,"%s","\\VarFileInfo\\Translation");
			uVersionLen = 0;
			lpVersion = NULL;
			bRetCode = VerQueryValue((LPVOID)lpstrVffInfo,szGetName,(void **)&lpVersion,(UINT *)&uVersionLen);
			if (bRetCode && uVersionLen && lpVersion) {
				sprintf_s(szResult, "%04x%04x", (WORD)(*((DWORD *)lpVersion)),(WORD)(*((DWORD *)lpVersion) >> 16));
			}
			else {
				sprintf_s(szResult, "%s","041904b0");
			}
			sprintf_s(szGetName, "\\StringFileInfo\\%s\\InternalName", szResult);
			uVersionLen = 0;
			lpVersion = NULL;
			bRetCode = VerQueryValue((LPVOID)lpstrVffInfo,szGetName,(void **)&lpVersion,(UINT *)&uVersionLen);
			if (bRetCode && uVersionLen && lpVersion) {
				sprintf_s(DataTypeTemp,"%s", lpVersion);
			}
			GlobalFree(hMem);
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}
	case Parser:
	{
		Dest.DWord = gdwParserEngineVer;
		Dest.Type = pIntType;
		return true;
	}

	}
	return false;
}
bool MQ2CharSelectListType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2CharSelectListType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((CharSelectListMembers)pMember->ID)
	{
		case Name:
			Dest.Type = pStringType;
			if (pEverQuest && ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
				if (VarPtr.Int < ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
					strcpy_s(DataTypeTemp, ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray[VarPtr.Int].Name);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
			return false;
		case Level:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pEverQuest && ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
				if (VarPtr.Int < ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
					Dest.DWord = ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray[VarPtr.Int].Level;
					return true;
				}
			}
			return false;
		case Class:
			Dest.DWord = 0;
			Dest.Type = pStringType;
			if (pEverQuest && ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
				if (VarPtr.Int < ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
					strcpy_s(DataTypeTemp, GetClassDesc(((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray[VarPtr.Int].Class));
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
			return false;
		case Race:
			Dest.DWord = 0;
			Dest.Type = pStringType;
			if (pEverQuest && ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
				if (VarPtr.Int < ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
					strcpy_s(DataTypeTemp, pEverQuest->GetRaceDesc(((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray[VarPtr.Int].Race));
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
			return false;
		case ZoneID:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pEverQuest && ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
				if (VarPtr.Int < ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
					int zoneid = ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray[VarPtr.Int].CurZoneID;
					Dest.DWord = (zoneid & 0x7FFF);
					return true;
				}
			}
			return false;
		case Count:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pEverQuest && ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count) {
				Dest.DWord = ((PEVERQUEST)pEverQuest)->pCharSelectPlayerArray.Count;
			}
			return true;
	}
	return false;
}
bool MQ2EverQuestType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2EverQuestType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((EverQuestMembers)pMember->ID)
	{
	case xHWND:
	{
		if (EQW_GetDisplayWindow)
			Dest.DWord = (DWORD)EQW_GetDisplayWindow();
		else
			Dest.DWord = *(DWORD*)EQADDR_HWND;
		Dest.Type = pIntType;
		return true;
	}
	case GameState:
		if (gGameState == GAMESTATE_CHARSELECT)
			strcpy_s(DataTypeTemp, "CHARSELECT");
		else if (gGameState == GAMESTATE_INGAME)
			strcpy_s(DataTypeTemp, "INGAME");
		else if (GetGameState() == GAMESTATE_PRECHARSELECT)
			strcpy_s(DataTypeTemp, "PRECHARSELECT");
		else
			strcpy_s(DataTypeTemp, "UNKNOWN");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case LoginName:
		Dest.Type = pStringType;
		if (PCHAR pTemp = GetLoginName())
		{
			strcpy_s(DataTypeTemp, pTemp);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Server:
		Dest.Type = pStringType;
		if (EQADDR_SERVERNAME[0])
		{
				strcpy_s(DataTypeTemp, EQADDR_SERVERNAME);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case LastCommand:
		Dest.Type = pStringType;
		if (szLastCommand[0])
		{
			Dest.Ptr = &szLastCommand[0];
			return true;
		}
		return false;
	case LastTell:
		Dest.Type = pStringType;
		if (EQADDR_LASTTELL[0])
		{
			strcpy_s(DataTypeTemp, EQADDR_LASTTELL);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Running:
		Dest.DWord = (DWORD)clock();
		Dest.Type = pIntType;
		return true;
	case MouseX:
		Dest.DWord = ((PMOUSEINFO)EQADDR_MOUSE)->X;
		Dest.Type = pIntType;
		return true;
	case MouseY:
		Dest.DWord = ((PMOUSEINFO)EQADDR_MOUSE)->Y;
		Dest.Type = pIntType;
		return true;
	case Ping:
		Dest.DWord = pConnection->Last;
		Dest.Type = pIntType;
		return true;
	case ChatChannels:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (((PEVERQUEST)pEverQuest)->ChatService)
		{
			Dest.DWord = ((PEVERQUEST)pEverQuest)->ChatService->ActiveChannels;
			return true;
		}
		return false;
	case ChatChannel:
		Dest.Type = pStringType;
		if (((PEVERQUEST)pEverQuest)->ChatService)
		{
			PCHATSERVICE pChat = ((PEVERQUEST)pEverQuest)->ChatService;
			if (ISNUMBER())
			{
				DWORD index = GETNUMBER();
				if (pChat->ActiveChannels && index && index <= pChat->ActiveChannels)
				{
					strcpy_s(DataTypeTemp, pChat->ChannelList->ChannelName[index - 1]);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else
			{
				CHAR Name[MAX_STRING] = { 0 };
				strcpy_s(Name, GETFIRST());
				for (unsigned int i = 0; i<pChat->ActiveChannels; i++)
				{
					if (!_stricmp(Name, pChat->ChannelList->ChannelName[i]))
					{
						Dest.DWord = 1;
						Dest.Type = pBoolType;
						return true;
					}
				}
			}
		}
		return false;
	case ViewportX:
		Dest.DWord = ScreenX;
		Dest.Type = pIntType;
		return true;
	case ViewportY:
		Dest.DWord = ScreenY;
		Dest.Type = pIntType;
		return true;
	case ViewportXMax:
		Dest.DWord = ScreenXMax;
		Dest.Type = pIntType;
		return true;
	case ViewportYMax:
		Dest.DWord = ScreenYMax;
		Dest.Type = pIntType;
		return true;
	case ViewportXCenter:
		Dest.DWord = ScreenXMax / 2;
		Dest.Type = pIntType;
		return true;
	case ViewportYCenter:
		Dest.DWord = ScreenYMax / 2;
		Dest.Type = pIntType;
		return true;
	case LClickedObject:
		Dest.DWord = gLClickedObject;
		Dest.Type = pBoolType;
		return true;
	case WinTitle:
#ifndef ISXEQ
		DataTypeTemp[0] = '1';
		DataTypeTemp[1] = '\0';
		Dest.Type = pStringType;
		GetWinTitle(GetCharInfo()->pSpawn, DataTypeTemp);
		if (DataTypeTemp[0] != '\0') {
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
#else
		printf("MQ2EverQuestType:WinTitle: Please use ${Display.Window.Text} for this value under Inner Space");
#endif
		return false;
	case PID:
		Dest.DWord = GetCurrentProcessId();
		Dest.Type = pIntType;
		return true;
	case xScreenMode:
		Dest.DWord = ScreenMode;
		Dest.Type = pIntType;
		return true;
	case PPriority:
		strcpy_s(DataTypeTemp,"NORMAL");
		if(HANDLE heqg = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, GetCurrentProcessId())) {
			DWORD prio = GetPriorityClass(heqg);
			switch(prio)
			{
				case IDLE_PRIORITY_CLASS:
					strcpy_s(DataTypeTemp,"LOW");
					break;
				case BELOW_NORMAL_PRIORITY_CLASS:
					strcpy_s(DataTypeTemp,"BELOW NORMAL");
					break;
				case NORMAL_PRIORITY_CLASS:
					prio = NORMAL_PRIORITY_CLASS;
					strcpy_s(DataTypeTemp,"NORMAL");
					break;
				case ABOVE_NORMAL_PRIORITY_CLASS:
					strcpy_s(DataTypeTemp,"ABOVE NORMAL");
					break;
				case HIGH_PRIORITY_CLASS:
					strcpy_s(DataTypeTemp,"HIGH");
					break;
				case REALTIME_PRIORITY_CLASS:
					strcpy_s(DataTypeTemp,"REALTIME");
					break;
				default:
					break;
			}
			CloseHandle(heqg);
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case LayoutCopyInProgress:
		Dest.DWord = *(BYTE*)CSidlScreenWnd__m_layoutCopy;
		Dest.Type = pBoolType;
		return true;
	case LastMouseOver:
		Dest.Type = pWindowType;
		if (PCXWNDMGR pwndmgr = (PCXWNDMGR)pWndMgr) {
			Dest.Ptr = pwndmgr->LastMouseOver;
			Dest.HighPart = 24;
			return true;
		}
		return false;
	case CharSelectList:
		Dest.DWord = 0;
		Dest.Type = pCharSelectListType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				int num = atoi(GETFIRST());
				num--;
				if (num < 0)
					num = 0;
				if (PEVERQUEST pEQ = (PEVERQUEST)pEverQuest) {
					if (num <= (int)pEQ->pCharSelectPlayerArray.Count) {
						Dest.DWord = num;
						return true;
					}
				}
			}
			else {
				if (PCHAR pName = GETFIRST()) {
					CHAR szName[256] = { 0 };
					if (PEVERQUEST pEQ = (PEVERQUEST)pEverQuest) {
						if (pEQ->pCharSelectPlayerArray.Count) {
							for (int i = 0; i < pEQ->pCharSelectPlayerArray.Count; i++) {
								strcpy_s(szName, pEQ->pCharSelectPlayerArray[i].Name);
								if (!_stricmp(pName, szName)) {
									Dest.DWord = i;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	case CurrentUI:
		Dest.Type = pStringType;
		if (PCHARINFO pCharInfo = GetCharInfo()) {
			CHAR szFilename[MAX_STRING] = { 0 };
			sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
			GetPrivateProfileString("Main", "UISkin", "default", DataTypeTemp, MAX_STRING, szFilename);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case IsDefaultUILoaded:
		Dest.DWord = 1;//it is by default...
		Dest.Type = pBoolType;
		if (PCHARINFO pCharInfo = GetCharInfo()) {
			CHAR szFilename[MAX_STRING] = { 0 };
			sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
			GetPrivateProfileString("Main", "UISkin", "default", DataTypeTemp, MAX_STRING, szFilename);
			if (_stricmp(DataTypeTemp, "default")) {
				Dest.DWord = 0;
			}
		}
		return true;
	case Foreground:
		Dest.DWord = gbInForeground;
		Dest.Type = pBoolType;
		return true;
	case ValidLoc://usage /echo ${EverQuest.ValidLoc[123 456 789]}
	{
		CHAR *szLoc = new CHAR[MAX_STRING];
		GetArg(szLoc, Index, 1);
		float X = (float)atof(szLoc);
		GetArg(szLoc, Index, 2);
		float Y = (float)atof(szLoc);
		GetArg(szLoc, Index, 3);
		float Z = (float)atof(szLoc);
		delete szLoc;

		Dest.DWord = pLocalPlayer->IsValidTeleport(Y, X, Z, 0, 0);
		Dest.Type = pBoolType;
		return true;
	}
	case FloorAtLoc://usage /echo ${EverQuest.FloorAtLoc[123 456]} returns 789
	{
		CHAR *szLoc = new CHAR[MAX_STRING];
		GetArg(szLoc, Index, 1);
		float X = (float)atof(szLoc);
		GetArg(szLoc, Index, 2);
		float Y = (float)atof(szLoc);
		delete szLoc;
		float Z = 0;
		PZONEINFO pZone = reinterpret_cast<PZONEINFO>(pZoneInfo);
        CDisplay *pDsp = reinterpret_cast<CDisplay*>(pDisplay);
		if (pZone && pDsp) {
			FLOAT curr_z = 0.0f;
			for (float f = pZone->Ceiling; f > pZone->Floor; f -= 1.0f)
			{
				curr_z = pDsp->GetFloorHeight(X, Y, f);
				if (curr_z != ((float)-1.0e27))
				{
					Z = curr_z;
					break;
				}
			}
			if (Z)
			{
				Dest.Float = Z;
				Dest.Type = pFloatType;
				return true;
			}
		}
		return false;
	}
	}
	return false;
}
#ifndef ISXEQ
bool MQ2TimeType::GETMEMBER()
{
#define pTime ((struct tm *)VarPtr.Ptr)
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2TimeType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((TimeMembers)pMember->ID)
	{
	case Hour:
		Dest.DWord = pTime->tm_hour;
		Dest.Type = pIntType;
		return true;
	case Hour12:
	{
		unsigned long Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;
		sprintf_s(DataTypeTemp, "%d %s", Hour, pTime->tm_hour>12 ? "PM" : "AM");
		Dest.Ptr = &DataTypeTemp[0],
		Dest.Type = pStringType;
		return true;
	}
	case Minute:
		Dest.DWord = pTime->tm_min;
		Dest.Type = pIntType;
		return true;
	case Second:
		Dest.DWord = pTime->tm_sec;
		Dest.Type = pIntType;
		return true;
	case DayOfWeek:
		Dest.DWord = pTime->tm_wday + 1;
		Dest.Type = pIntType;
		return true;
	case Day:
		Dest.DWord = pTime->tm_mday;
		Dest.Type = pIntType;
		return true;
	case Month:
		Dest.DWord = pTime->tm_mon + 1;
		Dest.Type = pIntType;
		return true;
	case Year:
		Dest.DWord = pTime->tm_year + 1900;
		Dest.Type = pIntType;
		return true;
	case Time12:
	{
		unsigned long Hour = pTime->tm_hour % 12;
		if (!Hour)
			Hour = 12;
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", Hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0],
		Dest.Type = pStringType;
		return true;
	}
	case Time24:
		sprintf_s(DataTypeTemp, "%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
		Dest.Ptr = &DataTypeTemp[0],
		Dest.Type = pStringType;
		return true;
	case Date:
		sprintf_s(DataTypeTemp, "%02d/%02d/%04d", pTime->tm_mon + 1, pTime->tm_mday, pTime->tm_year + 1900);
		Dest.Ptr = &DataTypeTemp[0],
		Dest.Type = pStringType;
		return true;
	case Night:
		Dest.DWord = ((pTime->tm_hour<7) || (pTime->tm_hour>20));
		Dest.Type = pBoolType;
		return true;
	case SecondsSinceMidnight:
		Dest.DWord = pTime->tm_hour * 3600 + pTime->tm_min * 60 + pTime->tm_sec;
		Dest.Type = pIntType;
		return true;
	}
	return false;
#undef pTime
}
#endif

bool MQ2HeadingType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2HeadingType::FindMember(Member);
	if (!pMember)
		return false;
	FLOAT Heading = 360.0f - VarPtr.Float;
	switch ((HeadingMembers)pMember->ID)
	{
	case Clock:
		Dest.Int = ((int)Heading) + 15;
		Dest.DWord = ((int)Dest.Int / 30) % 12;
		if (Dest.DWord == 0)
			Dest.DWord = 12;
		Dest.Type = pIntType;
		return true;
	case Degrees:
		Dest.Float = Heading;
		Dest.Type = pFloatType;
		return true;
	case DegreesCCW:
		Dest.Float = VarPtr.Float;
		Dest.Type = pFloatType;
		return true;
	case ShortName:
		strcpy_s(DataTypeTemp, szHeadingNormalShort[(INT)(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, szHeadingNormal[(INT)(Heading / 22.5f + 0.5f) % 16]);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	return false;
}

bool MQ2CorpseType::GETMEMBER()
{
	if (!pActiveCorpse || !pLootWnd)
		return false;
#define pLoot ((PEQLOOTWINDOW)pLootWnd)
	PMQ2TYPEMEMBER pMember = MQ2CorpseType::FindMember(Member);
	if (!pMember)
	{
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveCorpse, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pActiveCorpse, Member, argc, argv, Dest);
#endif
	}

	switch ((CorpseMembers)pMember->ID)
	{
	case Open:
		Dest.DWord = 1; // obviously, since we're this far
		Dest.Type = pBoolType;
		return true;
	case Item:
		Dest.Type = pItemType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				int nIndex = GETNUMBER() - 1;
				if (nIndex < 0)
					return false;
				if (nIndex<33 && pLoot->pInventoryArray)
				{
					if (Dest.Ptr = pLoot->pInventoryArray->InventoryArray[nIndex])
					{
						return true;
					}
				}
			}
			else
			{
				// name
				BOOL bExact = FALSE;
				PCHAR pName1 = GETFIRST();
				if (*pName1 == '=')
				{
					bExact = TRUE;
					pName1++;
				}
				CHAR szNameTemp[MAX_STRING] = { 0 };
				strcpy_s(szNameTemp, pName1);
				_strlwr_s(szNameTemp);
				CHAR Temp[MAX_STRING] = { 0 };
				if (pLoot->pInventoryArray)
					for (unsigned long nIndex = 0; nIndex < 34; nIndex++)
					{
						if (PCONTENTS pContents = pLoot->pInventoryArray->InventoryArray[nIndex])
						{
							if (bExact)
							{
								if (!_stricmp(szNameTemp, GetItemFromContents(pContents)->Name))
								{
									Dest.Ptr = pContents;
									return true;
								}
							}
							else
							{
								strcpy_s(Temp, GetItemFromContents(pContents)->Name);
								_strlwr_s(Temp);
								if (strstr(Temp, szNameTemp))
								{
									Dest.Ptr = pContents;
									return true;
								}
							}
						}
					}

			}
		}
		return false;
	case Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pLoot->pInventoryArray)
			for (unsigned long N = 0; N < 31; N++)
			{
				if (pLoot->pInventoryArray->InventoryArray[N])
					Dest.DWord++;
			}
		return true;
	}
	return false;
#undef pLoot
}

bool MQ2MerchantType::GETMEMBER()
{
	if (!pMerchantWnd)
		return false;
	PEQMERCHWINDOW pMerch = (PEQMERCHWINDOW)pMerchantWnd;
	CMerchantWnd *pCMerch = (CMerchantWnd*)pMerchantWnd;
	PMQ2TYPEMEMBER pMethod = MQ2MerchantType::FindMethod(Member);
	if (pMethod) {
		switch ((MerchantMethods)pMethod->ID)
		{
		case SelectItem:
		{
			if (pMerchantWnd->IsVisible())
			{
				CHAR szTemp[MAX_STRING] = { 0 };
				CHAR szTemp2[MAX_STRING] = { 0 };
				BOOL bExact = FALSE;
				PCHAR pName = GETFIRST();
				if (*pName == '=')
				{
					bExact = TRUE;
					pName++;
				}
				PCONTENTS pCont = 0;
				PITEMINFO pItem = 0;
				bool bFound = false;
				int listindex = 0;
#if !defined(ROF2EMU) && !defined(UFEMU)
				for (int i = 0; i < pCMerch->PageHandlers[0].pObject->ItemContainer.m_length; i++)
				{
					if (pCont = pCMerch->PageHandlers[0].pObject->ItemContainer.m_array[i].pCont)
					{
#else
				for (int i = 0; i < (int)pCMerch->PageHandlers[0].pObject->ItemContainer.Items.Size; i++)
				{
					if (pCont = pCMerch->PageHandlers[0].pObject->ItemContainer.Items[i].pObject)
					{
#endif
						if (pItem = GetItemFromContents(pCont))
						{
							//WriteChatf("[%d] %s %d",i, pItem->Name, pCont->GetGlobalIndex().Index.Slot1);
							if (bExact)
							{
								if (!_stricmp(pName, pItem->Name))
								{
									listindex = i;
									bFound = true;
									break;
								}
							}
							else
							{
								strcpy_s(szTemp, pItem->Name);
								_strlwr_s(szTemp);
								strcpy_s(szTemp2, pName);
								_strlwr_s(szTemp2);
								if (strstr(szTemp,szTemp2)) {
									listindex = i;
									bFound = true;
									break;
								}
							}
						}
					}
				}
				if (bFound)
				{
					ItemGlobalIndex To;
					To.Location = eItemContainerMerchant;
					To.Index.Slot1 = pCont->GetGlobalIndex().Index.Slot1;
					To.Index.Slot2 = pCont->GetGlobalIndex().Index.Slot2;
					To.Index.Slot3 = -1;
					for (int i = 0; i < pCMerch->ItemsList->ItemsArray.Count; i++)
					{
						CXStr Str;
						pCMerch->ItemsList->GetItemText(&Str, i, 1);
						CHAR szOut[MAX_STRING] = { 0 };
						GetCXStr(Str.Ptr, szOut, MAX_STRING);
						if (szOut[0] != '\0') {
							if (!_stricmp(szOut, pItem->Name))
							{
								pCMerch->ItemsList->SetCurSel(i);
								break;
							}
						}
					}
#if !defined(ROF2EMU) && !defined(UFEMU)
					pCMerch->SelectBuySellSlot(&To, listindex);
#else
					pCMerch->SelectBuySellSlot(&To);
#endif
					return true;
				}
			}
			return true;
		}
		case Buy:
		{
			if (pMerchantWnd->IsVisible())
			{
				int Qty = GETNUMBER();
				if (Qty < 1)
					return false;
				if (pCMerch->pSelectedItem.pObject && pCMerch->pSelectedItem.pObject->GetGlobalIndex().Location == eItemContainerMerchant)
				{
					pCMerch->PageHandlers[0].pObject->RequestGetItem(Qty);
					return true;
				}
			}
			return true;
		}
		case Sell:
		{
			if (pMerchantWnd->IsVisible())
			{
				int Qty = GETNUMBER();
				if (Qty < 1)
					return false;
				if (pCMerch->pSelectedItem.pObject && pCMerch->pSelectedItem.pObject->GetGlobalIndex().Location == eItemContainerPossessions)
				{
					pCMerch->PageHandlers[0].pObject->RequestPutItem(Qty);
					return true;
				}
			}
			return true;
		}
		case OpenWindow:
		{
			SEARCHSPAWN SearchSpawn;
			ClearSearchSpawn(&SearchSpawn);
			SearchSpawn.FRadius = 999999.0f;
			SearchSpawn.bMerchant = true;
			if (pTarget && ((PSPAWNINFO)pTarget)->mActorClient.Class == 41)
			{
				pEverQuest->RightClickedOnPlayer(pTarget, 0);
				return true;
			}
			else if (PSPAWNINFO pSpawn = SearchThroughSpawns(&SearchSpawn, (PSPAWNINFO)pLocalPlayer))
			{
				*ppTarget = (EQPlayer*)pSpawn;
				pEverQuest->RightClickedOnPlayer((EQPlayer*)pSpawn, 0);
				return true;
			}
			return true;
		}
		case CloseWindow:
			if (pMerchantWnd->IsVisible())
			{
				//Need to call deactivate here.
				WriteChatf("Not implemented yet");
				return true;
			}
			return true;
		}
		return false;
	}
	if (!pActiveMerchant)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2MerchantType::FindMember(Member);
	if (!pMember)
	{
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveMerchant, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pActiveMerchant, Member, argc, argv, Dest);
#endif
	}

	switch ((MerchantMembers)pMember->ID)
	{
	case Open:
		Dest.DWord = pMerchantWnd->IsVisible();
		Dest.Type = pBoolType;
		return true;
	case ItemsReceived:
		Dest.DWord = gItemsReceived;
		Dest.Type = pBoolType;
		return true;
	case Item://todo: check manually for uf
		Dest.Type = pItemType;
		if (ISINDEX())
		{
			if (pMerch && pMerch->pMerchOther && pMerch->pMerchOther->pMerchData) {
				if (ISNUMBER())
				{
					int nIndex = GETNUMBER() - 1;
					if (nIndex < 0)
						return false;
					if (nIndex < (int)pMerch->pMerchOther->pMerchData->MerchMaxSlots)
					{
#if !defined(ROF2EMU) && !defined(UFEMU)
						if (Dest.Ptr = pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex].pCont)
#else
						if (Dest.Ptr = pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex])
#endif
						{
							return true;
						}
					}
				}
				else
				{
					// name
					BOOL bExact = FALSE;
					PCHAR pName1 = GETFIRST();
					if (*pName1 == '=')
					{
						bExact = TRUE;
						pName1++;
					}
					CHAR szNameTemp[MAX_STRING] = { 0 };
					strcpy_s(szNameTemp, pName1);
					_strlwr_s(szNameTemp);
					CHAR Temp[MAX_STRING] = { 0 };
					for (unsigned long nIndex = 0; nIndex < pMerch->pMerchOther->pMerchData->MerchMaxSlots; nIndex++)
					{
#if !defined(ROF2EMU) && !defined(UFEMU)
						if (PCONTENTS pContents = pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex].pCont)
#else
						if (PCONTENTS pContents = pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex])
#endif
						{
							if (bExact)
							{
								if (!_stricmp(szNameTemp, GetItemFromContents(pContents)->Name))
								{
									Dest.Ptr = pContents;
									return true;
								}
							}
							else
							{
								strcpy_s(Temp, GetItemFromContents(pContents)->Name);
								_strlwr_s(Temp);
								if (strstr(Temp, szNameTemp))
								{
									Dest.Ptr = pContents;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	case Items://todo: check manually for uf
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pMerch && pMerch->pMerchOther && pMerch->pMerchOther->pMerchData) {
			Dest.DWord = pMerch->pMerchOther->pMerchData->MerchMaxSlots;
		}
		return true;
	case SelectedItem:
	if (CMerchantWnd*pm = (CMerchantWnd*)pMerchantWnd)
	{
		Dest.Ptr = pm->pSelectedItem.pObject;
		Dest.Type = pItemType;
		return true;
	}
	case Markup:
		Dest.Float = pMerch->Markup;
		Dest.Type = pFloatType;
		return true;
	case Full://todo: check manually for uf
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pMerch && pMerch->pMerchOther && pMerch->pMerchOther->pMerchData) {
			Dest.DWord = 1;
			if (pMerch->pMerchOther->pMerchData->MerchMaxSlots < 0x80) {
				Dest.DWord = 0;
				return true;
			}
			for (unsigned long N = 0; N < pMerch->pMerchOther->pMerchData->MerchMaxSlots; N++)
			{
#if !defined(ROF2EMU) && !defined(UFEMU)
				if (!pMerch->pMerchOther->pMerchData->pMerchArray->Array[N].pCont)
#else
				if (!pMerch->pMerchOther->pMerchData->pMerchArray->Array[N])
#endif
				{
					Dest.DWord = 0;
					break;
				}
			}
			return true;
		}
		return false;
	}
	return false;
#undef pMerch
}
#if !defined(ROF2EMU) && !defined(UFEMU)
bool MQ2PointMerchantItemType::GETMEMBER()
{
	CMerchantWnd *pMerch = (CMerchantWnd *)pMerchantWnd;
	if (!pMerch)
		return false;
	if (VarPtr.Int < 0 || VarPtr.Int > pMerch->PageHandlers.Begin->pObject->ItemContainer.m_length)
		return false;

	int index = VarPtr.Int;
	PMQ2TYPEMEMBER pMember = MQ2PointMerchantItemType::FindMember(Member);

	if (!pMember)
		return false;
	PITEMINFO pItem = 0;
	PCONTENTS pCont = 0;
	if (pCont = pMerch->PageHandlers.Begin->pObject->ItemContainer.m_array[index].pCont) {
		pItem = GetItemFromContents(pCont);
	}
	switch ((PointMerchantItemMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp, pItem->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case ItemID:
		Dest.Int = pCont->ID;
		Dest.Type = pIntType;
		return true;
	case Price:
		if (pItem->LDTheme)
			Dest.Int64 = pItem->LDCost;
		else
			Dest.Int64 = pCont->Price;
		Dest.Type = pInt64Type;
		return true;
	case ThemeID:
		Dest.Int = pItem->LDTheme;
		Dest.Type = pIntType;
		return true;
	case IsStackable:
		Dest.Int = ((EQ_Item*)pCont)->IsStackable();
		Dest.Type = pBoolType;
		return true;
	case IsLore:
		Dest.Int = pItem->Lore;
		Dest.Type = pBoolType;
		return true;
	case RaceMask:
		Dest.Int = pItem->Races;
		Dest.Type = pIntType;
		return true;
	case ClassMask:
		Dest.Int = pItem->Classes;
		Dest.Type = pIntType;
		return true;
	case CanUse:
		Dest.Int = pCharData1->CanUseItem(&pCont, false, false);
		Dest.Type = pBoolType;
		return true;
	}
	return false;
}
bool MQ2PointMerchantType::GETMEMBER()
{
	if (!pMerchantWnd)
		return false;
	CMerchantWnd *pMercWnd = (CMerchantWnd *)pMerchantWnd;
	PEQMERCHWINDOW peqMercWnd = (PEQMERCHWINDOW)pMerchantWnd;
	int k = 0;
	PCONTENTS pitem = peqMercWnd->pMerchOther->pMerchData->pMerchArray->Array[k].pCont;
	PMQ2TYPEMEMBER pMember = MQ2PointMerchantType::FindMember(Member);
	if (!pMember)
	{
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveMerchant, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pActiveMerchant, Member, argc, argv, Dest);
#endif
	}

	switch ((PointMerchantMembers)pMember->ID)
	{
		//for (unsigned long nIndex = 0; nIndex < pMerch->pMerchOther->pMerchData->MerchSlots; nIndex++)
					//{
						//if (PCONTENTS pContents = pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex])
	case Item:
		Dest.Int = 0;
		Dest.Type = pPointMerchantItemType;
		if (ISNUMBER()) {
			int index = GETNUMBER() - 1;
			if (index >= 0 && index < pMercWnd->PageHandlers.Begin->pObject->ItemContainer.m_length) {
				Dest.Int = index;
				return true;
			}
		}
		else {
			if (GETFIRST()[0] != '\0') {
				for (int i = 0; i < pMercWnd->PageHandlers.Begin->pObject->ItemContainer.m_length; i++) {
					//pMercWnd->PageHandlers.Begin->pObject->Items.Items[i];
					//pMerc->PageHandlers.Begin->pObject->Items.Items.Begin[1].pObject;
					auto name = GetItemFromContents(pMercWnd->PageHandlers.Begin->pObject->ItemContainer.m_array[i].pCont)->Name;
					if (!_stricmp(name, GETFIRST())) {
						Dest.Int = i;
						return true;
					}
				}
			}
		}
	}
	return false;
}
#else
bool MQ2PointMerchantItemType::GETMEMBER()
{
	PointMerchantWnd *pPointWnd = (PointMerchantWnd *)pPointMerchantWnd;
	if (!pPointWnd)
		return false;

	if (VarPtr.Int < 0 || VarPtr.Int > pPointWnd->ItemList->ItemsArray.Count)
		return false;

	int index = VarPtr.Int;
	PMQ2TYPEMEMBER pMember = MQ2PointMerchantItemType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((PointMerchantItemMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp, pPointWnd->Items[index]->ItemName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case ItemID:
		Dest.Int = pPointWnd->Items[index]->ItemID;
		Dest.Type = pIntType;
		return true;
	case Price:
		Dest.Int = pPointWnd->Items[index]->Price;
		Dest.Type = pIntType;
		return true;
	case ThemeID:
		Dest.Int = pPointWnd->Items[index]->ThemeID;
		Dest.Type = pIntType;
		return true;
	case IsStackable:
		Dest.Int = pPointWnd->Items[index]->IsStackable;
		Dest.Type = pBoolType;
		return true;
	case IsLore:
		Dest.Int = pPointWnd->Items[index]->IsLore;
		Dest.Type = pBoolType;
		return true;
	case RaceMask:
		Dest.Int = pPointWnd->Items[index]->RaceMask;
		Dest.Type = pIntType;
		return true;
	case ClassMask:
		Dest.Int = pPointWnd->Items[index]->ClassMask;
		Dest.Type = pIntType;
		return true;
	case CanUse:
		Dest.Int = pPointWnd->Items[index]->bCanUse;
		Dest.Type = pBoolType;
		return true;
	}
	return false;
}
bool MQ2PointMerchantType::GETMEMBER()
{
	if (!pPointMerchantWnd)
		return false;
	PointMerchantWnd *pPointWnd = (PointMerchantWnd *)pPointMerchantWnd;
	PMQ2TYPEMEMBER pMember = MQ2PointMerchantType::FindMember(Member);
	if (!pMember)
	{
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pPointMerchantWnd->ActiveMerchant, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pPointMerchantWnd->ActiveMerchant, Member, argc, argv, Dest);
#endif
	}

	switch ((PointMerchantMembers)pMember->ID)
	{
	case Item:
		Dest.Int = 0;
		Dest.Type = pPointMerchantItemType;
		if (ISNUMBER()) {
			int index = GETNUMBER() - 1;
			if (index >= 0 && index < pPointWnd->NumItems) {
				Dest.Int = index;
				return true;
			}
		}
		else {
			if (GETFIRST()[0] != '\0') {
				for (int i = 0; i < pPointWnd->NumItems; i++) {
					if (!_stricmp(pPointWnd->Items[i]->ItemName, GETFIRST())) {
						Dest.Int = i;
						return true;
					}
				}
			}
		}
	}
	return false;
}
#endif
bool MQ2MercenaryType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PSPAWNINFO pSpawn = (PSPAWNINFO)VarPtr.Ptr;
	PMQ2TYPEMEMBER pMember = MQ2MercenaryType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&VarPtr.Ptr, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&VarPtr.Ptr, Member, argc, argv, Dest);
#endif
	}
	switch ((MercenaryMembers)pMember->ID)
	{
	case AAPoints:
#if !defined(ROF2EMU) && !defined(UFEMU)
		Dest.DWord = GetCharInfo()->MercAAPoints;
#else
		Dest.DWord = 0;
#endif
		Dest.Type = pIntType;
		return true;
	case Stance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (DWORD n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, 24, 0));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case State:
		switch (pMercInfo->MercState)
		{
		case 0:
			strcpy_s(DataTypeTemp, "DEAD");
			break;
		case 1:
			strcpy_s(DataTypeTemp, "SUSPENDED");
			break;
		case 5:
		{
			if (pMercInfo->HaveMerc) {
				strcpy_s(DataTypeTemp, "ACTIVE");
			}
			else {
				strcpy_s(DataTypeTemp, "NOMERC");
			}
			break;
		}
		default:
			strcpy_s(DataTypeTemp, "UNKNOWN");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case StateID:
		Dest.DWord = pMercInfo->MercState;
		Dest.Type = pIntType;
		return true;
	case xIndex:
		Dest.DWord = pMercInfo->CurrentMercIndex + 1;
		Dest.Type = pIntType;
		return true;
#ifdef MULETESTING
		//work in progress -eqmule Aug 03 2015
	case CurrentHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CurrHP;
			return true;
		}
		return false;
	case MaxHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxHP;
			return true;
		}
		return false;
	case PctHPs:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			LONG maxhp = pStats->MaxHP;
			if (maxhp != 0)
				Dest.Int = pStats->CurrHP * 100 / maxhp;
			return true;
		}
		return false;
	case CurrentMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->CurrMana;
			return true;
		}
		return false;
	case MaxMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxMana;
			return true;
		}
		return false;
	case PctMana:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			if (unsigned long Temp = pStats->MaxMana) {
				Dest.Int = pStats->CurrMana * 100 / Temp;
				return true;
			}
		}
		return false;
	case AC:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->AC;
			return true;
		}
		return false;
	case AGI:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->AGI;
			return true;
		}
		return false;
	case Attack:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->Attack;
			return true;
		}
		return false;
	case CHA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CHA;
			return true;
		}
		return false;
	case CombatEnduranceRegen:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CombatEnduranceRegen;
			return true;
		}
		return false;
	case CombatHPRegen:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.DWord = pStats->CombatHPRegen;
			return true;
		}
		return false;
	case CurrentEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->CurrEndurance;
			return true;
		}
		return false;
	case MaxEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->MaxEndurance;
			return true;
		}
		return false;
	case PctEndurance:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			if (unsigned long Temp = pStats->MaxEndurance)
				Dest.Int = (pStats->CurrEndurance * 100) / Temp;
			return true;
		}
		return false;
	case DEX:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->DEX;
			return true;
		}
		return false;
	case Haste:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->Haste;
			return true;
		}
		return false;
	case HealAmount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->HealAmount;
			return true;
		}
		return false;
	case INT:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->INT;
			return true;
		}
		return false;
	case SpellDamage:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->SpellDamage;
			return true;
		}
		return false;
	case STA:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->STA;
			return true;
		}
		return false;
	case STR:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->STR;
			return true;
		}
		return false;
	case WIS:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (PMERCENARYSTATS pStats = (PMERCENARYSTATS)pinstMercenaryStats) {
			Dest.Int = pStats->WIS;
			return true;
		}
		return false;
#endif
	}
	return false;
}
bool MQ2PetType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PSPAWNINFO pSpawn = (PSPAWNINFO)VarPtr.Ptr;
	PMQ2TYPEMEMBER pMember = MQ2PetType::FindMember(Member);
	if (!pMember)
	{
		if (!pSpawn->SpawnID)
			return false;
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&VarPtr.Ptr, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&VarPtr.Ptr, Member, argc, argv, Dest);
		//return pSpawnType->GetMember(*(LSVARPTR*)&VarPtr.Ptr,Member,argc,argv,Dest);
#endif
	}
#define pPetInfoWindow ((PEQPETINFOWINDOW)pPetInfoWnd)
	PEQPETINFOWINDOW pinfo = (PEQPETINFOWINDOW)pPetInfoWnd;
	if (!pPetInfoWindow)
		return false;
	switch ((PetMembers)pMember->ID)
	{
	case Buff:
		Dest.Type = pSpellType;
		if (!ISINDEX() || !pPetInfoWindow)
			return false;
		if (ISNUMBER())
		{
			int nBuff = GETNUMBER() - 1;
			if (nBuff < 0)
				return false;
			if (nBuff >= NUM_BUFF_SLOTS)
				return false;
			if (pPetInfoWindow->Buff[nBuff] == 0xFFFFFFFF || pPetInfoWindow->Buff[nBuff] == 0)
				return false;
			if (Dest.Ptr = GetSpellByID(pPetInfoWindow->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (unsigned long nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (PSPELL pSpell = GetSpellByID(pPetInfoWindow->Buff[nBuff]))
				{
					if (!_strnicmp(GETFIRST(), pSpell->Name, strlen(GETFIRST())))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;
	case BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!ISINDEX() || !pPetInfoWindow)
			return false;
		if (ISNUMBER())
		{
			int nBuff = GETNUMBER() - 1;
			if (nBuff < 0)
				return false;
			if (nBuff >= NUM_BUFF_SLOTS)
				return false;
			if (pPetInfoWindow->Buff[nBuff] == 0xFFFFFFFF || pPetInfoWindow->Buff[nBuff] == 0)
				return false;
			Dest.UInt64 = pPetInfoWindow->PetBuffTimer[nBuff];
			return true;
		}
		else
		{
			for (unsigned long nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (PSPELL pSpell = GetSpellByID(pPetInfoWindow->Buff[nBuff]))
				{
					if (!_strnicmp(GETFIRST(), pSpell->Name, strlen(GETFIRST())))
					{
						Dest.UInt64 = pPetInfoWindow->PetBuffTimer[nBuff];
						return true;
					}
				}
			}
		}
		return false;
	case Combat:
		Dest.DWord = (pSpawn && pSpawn->WhoFollowing);
		/*
		if (pSpawn && pSpawn->WhoFollowing)
		{
			Dest.DWord = TRUE;
		}
		else {
			Dest.DWord = FALSE;
		}
		*/
		Dest.Type = pBoolType;
		return true;
	case GHold:
		Dest.DWord = (pPetInfoWindow && pPetInfoWindow->GHold);
		/*
		if (pPetInfoWindow && pPetInfoWindow->GHold)
		{
			Dest.DWord = TRUE;
		}
		else {
			Dest.DWord = FALSE;
		}
		*/
		Dest.Type = pBoolType;
		return true;
	case Hold:
		Dest.DWord = (pPetInfoWindow && pPetInfoWindow->Hold);
		/*
		if (pPetInfoWindow && pPetInfoWindow->Hold)
		{
			Dest.DWord = TRUE;
		}
		else {
			Dest.DWord = FALSE;
		}
		*/
		Dest.Type = pBoolType;
		return true;
	case ReGroup:
		Dest.DWord = (pPetInfoWindow && pPetInfoWindow->ReGroup);
		/*
		if (pPetInfoWindow && pPetInfoWindow->ReGroup)
		{
			Dest.DWord = TRUE;
		}
		else {
			Dest.DWord = FALSE;
		}
		*/
		Dest.Type = pBoolType;
		return true;
	case Stance:
		if (pPetInfoWindow && pPetInfoWindow->Follow)
			strcpy_s(DataTypeTemp, "FOLLOW");
		else
			strcpy_s(DataTypeTemp, "GUARD");
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Stop:
		Dest.DWord = (pPetInfoWindow && pPetInfoWindow->Stop);
		/*
		if (pPetInfoWindow && pPetInfoWindow->Stop)
		{
			Dest.DWord = TRUE;
		}
		else {
			Dest.DWord = FALSE;
		}
		*/
		Dest.Type = pBoolType;
		return true;
	case Target:
		Dest.Type = pSpawnType;
		if(pSpawn) {
			if (Dest.Ptr = pSpawn->WhoFollowing)
			{
				return true;
			}
		}
		return false;
	case Taunt:
		Dest.DWord = (pPetInfoWindow && pPetInfoWindow->Taunt);
		/*
		if (pPetInfoWindow && pPetInfoWindow->Taunt)
		{
			Dest.DWord = TRUE;
		}
		else {
			Dest.DWord = FALSE;
		}
		*/
		Dest.Type = pBoolType;
		return true;
	}
#undef pPetInfoWindow
	return false;
}
// item slots:
// 2000-2015 bank window
// 2500-2503 shared bank
// 5000-5031 loot window
// 3000-3015 trade window (including npc) 3000-3007 are your slots, 3008-3015 are other character's slots
// 4000-4010 world container window
// 6000-6080 merchant window
// 7000-7080 bazaar window
// 8000-8031 inspect window
bool MQ2InvSlotType::GETMEMBER()
{
	int nInvSlot = VarPtr.Int;
	PMQ2TYPEMEMBER pMember = MQ2InvSlotType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((InvSlotMembers)pMember->ID)
	{
	case ID:
		Dest.DWord = VarPtr.Int;
		Dest.Type = pIntType;
		return true;
	case Item:
		Dest.Type = pItemType;
		if (PCHARINFO2 pChar2 = GetCharInfo2()) {
			if (pChar2->pInventoryArray && nInvSlot >= 0) {
				if (nInvSlot < (int)GetCurrentInvSlots())
				{
					if (Dest.Ptr = pChar2->pInventoryArray->InventoryArray[nInvSlot])
					{
						return true;
					}
				}
				else
				{
					if (PCHARINFO pCharInfo = GetCharInfo()) {
						if (nInvSlot >= 262 && nInvSlot < 342)
						{
							unsigned long nPack = (nInvSlot - 262) / 10;
							unsigned long nSlot = (nInvSlot - 262) % 10;
							if (PCONTENTS pPack = pChar2->pInventoryArray->Inventory.Pack[nPack])
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
								}
						}
						else if (nInvSlot >= 2032 && nInvSlot < 2272)
						{
							unsigned long nPack = (nInvSlot - 2032) / 10;
							unsigned long nSlot = (nInvSlot - 2) % 10;
							PCONTENTS pPack = NULL;
							if (pCharInfo && pCharInfo->BankItems.Items.Size > nPack)
								pPack = pCharInfo->BankItems.Items[nPack].pObject;
							if (pPack)
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
								}
						}
						else if (nInvSlot >= 2532 && nInvSlot < 2552)
						{
							unsigned long nPack = 23 + ((nInvSlot - 2532) / 10);
							unsigned long nSlot = (nInvSlot - 2) % 10;
							PCONTENTS pPack = NULL;
							if (pCharInfo && pCharInfo->BankItems.Items.Size > nPack)
								pPack = pCharInfo->BankItems.Items[nPack].pObject;
							if (pPack)
								if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && nSlot < GetItemFromContents(pPack)->Slots)
								{
									if (pPack->Contents.ContainedItems.pItems)
										if (Dest.Ptr = pPack->Contents.ContainedItems.pItems->Item[nSlot])
										{
											return true;
										}
								}
						}
						else if (nInvSlot >= 2000 && nInvSlot < 2024)
						{
							if (pCharInfo && pCharInfo->BankItems.Items.Size > (UINT)nInvSlot - 2000) {
								if (Dest.Ptr = pCharInfo->BankItems.Items[nInvSlot - 2000].pObject)
								{
									return true;
								}
							}
						}
						else if (nInvSlot == 2500 || nInvSlot == 2501)
						{
							if (pCharInfo && pCharInfo->BankItems.Items.Size > (UINT)nInvSlot - 2500 + 22) {
								if (Dest.Ptr = pCharInfo->BankItems.Items[nInvSlot - 2500 + 22].pObject)
									if (Dest.Ptr)
									{
										return true;
									}
							}
						}
						else if (nInvSlot > 2999 && nInvSlot < 3016)
						{
							CInvSlotWnd *pInvslotwnd = 0;
							if (pGiveWnd && pGiveWnd->IsVisible()) {
								CGiveWnd *pWnd = (CGiveWnd*)pGiveWnd;
								switch (nInvSlot)
								{
								case 3001:
									pInvslotwnd = pWnd->pInvSlotWnd[1];
									break;
								case 3002:
									pInvslotwnd = pWnd->pInvSlotWnd[2];
									break;
								case 3003:
									pInvslotwnd = pWnd->pInvSlotWnd[3];
									break;
								default:
									pInvslotwnd = pWnd->pInvSlotWnd[0];
									break;
								}
							}
							else if (pTradeWnd && pTradeWnd->IsVisible()) {
								CTradeWnd *pWnd = (CTradeWnd*)pTradeWnd;
								switch (nInvSlot)
								{
								case 3001:
									pInvslotwnd = pWnd->pInvSlotWnd[1];
									break;
								case 3002:
									pInvslotwnd = pWnd->pInvSlotWnd[2];
									break;
								case 3003:
									pInvslotwnd = pWnd->pInvSlotWnd[3];
									break;
								case 3004:
									pInvslotwnd = pWnd->pInvSlotWnd[4];
									break;
								case 3005:
									pInvslotwnd = pWnd->pInvSlotWnd[5];
									break;
								case 3006:
									pInvslotwnd = pWnd->pInvSlotWnd[6];
									break;
								case 3007:
									pInvslotwnd = pWnd->pInvSlotWnd[7];
									break;
								case 3008:
									pInvslotwnd = pWnd->pInvSlotWnd[8];
									break;
								case 3009:
									pInvslotwnd = pWnd->pInvSlotWnd[9];
									break;
								case 3010:
									pInvslotwnd = pWnd->pInvSlotWnd[10];
									break;
								case 3011:
									pInvslotwnd = pWnd->pInvSlotWnd[11];
									break;
								case 3012:
									pInvslotwnd = pWnd->pInvSlotWnd[12];
									break;
								case 3013:
									pInvslotwnd = pWnd->pInvSlotWnd[13];
									break;
								case 3014:
									pInvslotwnd = pWnd->pInvSlotWnd[14];
									break;
								case 3015:
									pInvslotwnd = pWnd->pInvSlotWnd[15];
									break;
								default:
									pInvslotwnd = pWnd->pInvSlotWnd[0];
									break;
								}
							}
							if (pInvslotwnd) {
								if (CInvSlot*pcinvslot = pInvslotwnd->pEQInvSlot) {
									struct _CONTENTS *pC = NULL;
									pcinvslot->GetItemBase(&pC);
									if (pC) {
										Dest.Ptr = pC;
										return true;
									}
								}
							}
						}
						else if (nInvSlot > 3999 && nInvSlot < 4011)//enviro slots
						{
							if (CContainerMgr*pWnd = pContainerMgr)
							{
								int index = nInvSlot - 4000;
								if (pWnd->pWorldContainer.pObject) {
									if (index < (int)pWnd->pWorldContainer.pObject->Contents.ContainedItems.Size && pWnd->pWorldContainer.pObject->Contents.ContainedItems.pItems)
									{
										Dest.Ptr = pWnd->pWorldContainer.pObject->Contents.ContainedItems.pItems->Item[index];
										return true;
									}
								}
							}
						}
						else if (nInvSlot == 4100)//enviro
						{
							if (CContainerMgr*pWnd = pContainerMgr)
							{
								if (pWnd->pWorldContainer.pObject) {
									Dest.Ptr = pWnd->pWorldContainer.pObject;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	case Pack:
		Dest.DWord = 0;
		Dest.Type = pInvSlotType;
		if (nInvSlot >= 262 && nInvSlot<342)
		{
			Dest.DWord = ((nInvSlot - 262) / 10) + BAG_SLOT_START;
			return true;
		}
		else if (nInvSlot >= 2032 && nInvSlot<2272)
		{
			Dest.DWord = ((nInvSlot - 2032) / 10) + 2000;
			return true;
		}
		else if (nInvSlot >= 2532 && nInvSlot<2552)
		{
			Dest.DWord = ((nInvSlot - 2532) / 10) + 2500;
			return true;
		}
		return false;
	case Slot:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (nInvSlot >= 262 && nInvSlot<342)
		{
			Dest.DWord = (nInvSlot - 262) % 10;
			return true;
		}
		else if (nInvSlot >= 2032 && nInvSlot<2272)
		{
			Dest.DWord = (nInvSlot - 2032) % 10;
			return true;
		}
		else if (nInvSlot >= 2532 && nInvSlot<2552)
		{
			Dest.DWord = (nInvSlot - 2532) % 10;
			return true;
		}
		return false;
	case Name:
		Dest.Type = pStringType;
		if (nInvSlot >= 0 && nInvSlot<(int)GetCurrentInvSlots())
		{
			strcpy_s(DataTypeTemp, szItemSlot[nInvSlot]);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		if (nInvSlot >= BAG_SLOT_START && nInvSlot<(int)GetCurrentInvSlots())
		{
			sprintf_s(DataTypeTemp, "pack%d", nInvSlot - 21);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 2000 && nInvSlot<2024)
		{
			sprintf_s(DataTypeTemp, "bank%d", nInvSlot - 1999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 2500 && nInvSlot<2502)
		{
			sprintf_s(DataTypeTemp, "sharedbank%d", nInvSlot - 2499);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 5000 && nInvSlot<5032)
		{
			sprintf_s(DataTypeTemp, "loot%d", nInvSlot - 4999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 3000 && nInvSlot<3009)
		{
			sprintf_s(DataTypeTemp, "trade%d", nInvSlot - 2999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 4000 && nInvSlot<4009)
		{
			sprintf_s(DataTypeTemp, "enviro%d", nInvSlot - 3999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot == 4100)//its the worldcontainer
		{
			if (CContainerMgr *pContmgr = pContainerMgr)
			{
				if (PITEMINFO pIteminf = GetItemFromContents(pContmgr->pWorldContainer.pObject))
				{
					strcpy_s(DataTypeTemp, pIteminf->Name);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		else if (nInvSlot >= 6000 && nInvSlot<6080)
		{
			sprintf_s(DataTypeTemp, "merchant%d", nInvSlot - 5999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 7000 && nInvSlot<7089)
		{
			sprintf_s(DataTypeTemp, "bazaar%d", nInvSlot - 6999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		else if (nInvSlot >= 8000 && nInvSlot<8031)
		{
			sprintf_s(DataTypeTemp, "inspect%d", nInvSlot - 7999);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	}

	return false;
}



bool MQ2TimerType::GETMEMBER()
{
#define pTimer ((PMQTIMER)VarPtr.Ptr)
	if (!pTimer)
		return false;
	PMQ2TYPEMEMBER pMethod = MQ2TimerType::FindMethod(Member);
	if (pMethod) {
		switch ((TimerMethods)pMethod->ID)
		{
		case Expire:
			pTimer->Current = 0;
			return true;
		case Reset:
			pTimer->Current = pTimer->Original;
			return true;
		case Set:
		{
			FromString(VarPtr, GETFIRST());
			return true;
		}
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2TimerType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((TimerMembers)pMember->ID)
	{
	case Value:
		Dest.DWord = pTimer->Current;
		Dest.Type = pIntType;
		return true;
	case OriginalValue:
		Dest.DWord = pTimer->Original;
		Dest.Type = pIntType;
		return true;
	}
	return false;
#undef pTimer
}


bool MQ2SkillType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PSKILL pSkill = *(PSKILL*)VarPtr.Ptr;
	if (!pSkill)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2SkillType::FindMember(Member);
	if (!pMember)
		return false;
	if (PCHARINFO2 pChar2 = GetCharInfo2()) {
		DWORD nIndex = pChar2->Class;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				// class by number
				nIndex = GETNUMBER();
			}
			else
			{
				// class by name or shortname
				for (int N = 1; N < 17; N++)
				{
					if (
						!_stricmp(GETFIRST(), GetClassDesc(N)) ||
						!_stricmp(GETFIRST(), pEverQuest->GetClassThreeLetterCode(N))
						)
					{
						nIndex = N;
						break;
					}
				}
			}
		}

		switch ((SkillMembers)pMember->ID)
		{
		case Name:
			Dest.Type = pStringType;
			if (char *ptr = pStringTable->getString(pSkill->nName, 0))
			{
				strcpy_s(DataTypeTemp, ptr);
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
			return false;
		case ID:
			Dest.DWord = GetSkillIDFromName(pStringTable->getString(pSkill->nName, 0));
			Dest.Type = pIntType;
			return true;
		case ReuseTime:
			Dest.DWord = pSkill->ReuseTimer;
			Dest.Type = pIntType;
			return true;
		case MinLevel:
			Dest.DWord = pSkill->MinLevel[nIndex];
			Dest.Type = pIntType;
			return true;
		case SkillCap:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (PCHARINFO pCharInfo = GetCharInfo()) {
				DWORD i = GetSkillIDFromName(pStringTable->getString(pSkill->nName, 0));
				Dest.DWord = pCSkillMgr->GetSkillCap((EQ_Character*)pCharInfo, pChar2->Level, pChar2->Class, i, true, true, true);
				return true;
			}
			return false;
		case AltTimer:
			Dest.DWord = pSkill->SkillCombatType;
			Dest.Type = pIntType;
			return true;
		case Activated:
			Dest.DWord = pSkill->Activated;
			Dest.Type = pBoolType;
			return true;
		#if !defined(ROF2EMU) && !defined(UFEMU)
		case Auto://return a bool representing if a skill has /autoskill on or off.
			Dest.DWord = false;
			Dest.Type = pBoolType;
			int id = GetSkillIDFromName(pStringTable->getString(pSkill->nName, 0));
			if (gAutoSkill.Skill[0] == id || gAutoSkill.Skill[1] == id) {
				Dest.DWord = true;
			}
			return true;
		#endif
		}
	}
	return false;
}

bool MQ2AltAbilityType::ToString(MQ2VARPTR VarPtr, PCHAR Destination)
{
	if (!VarPtr.Ptr)
		return false;
	PALTABILITY pAbility = (PALTABILITY)VarPtr.Ptr;
	_itoa_s(pAbility->ID, Destination,MAX_STRING, 10);
	return true;
}

bool MQ2AltAbilityType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PALTABILITY pAbility = (PALTABILITY)VarPtr.Ptr;

	PMQ2TYPEMEMBER pMember = MQ2AltAbilityType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((AltAbilityMembers)pMember->ID)
	{
	case Name:
		Dest.Type = pStringType;
		if (char *ptr = pCDBStr->GetString(pAbility->nName, 1, NULL))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case ShortName:
		//what is this even for? need to check -eqmule
		Dest.Type = pStringType;
		//if (char *ptr = pStringTable->getString(pAbility->nShortName,0))
		if (char *ptr = pCDBStr->GetString(pAbility->nName, 2, NULL))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case Description:
		Dest.Type = pStringType;
		if (char *ptr = pCDBStr->GetString(pAbility->nName, 4, NULL))
		{
			strcpy_s(DataTypeTemp, ptr);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case ID:
		Dest.DWord = pAbility->ID;
		Dest.Type = pIntType;
		return true;
	case ReuseTime:
		Dest.DWord = pAbility->ReuseTimer;
		Dest.Type = pIntType;
		return true;
	case MyReuseTime:
		Dest.DWord = pAltAdvManager->GetCalculatedTimer(pPCData, pAbility);
		Dest.Type = pIntType;
		return true;
	case MinLevel:
		Dest.DWord = pAbility->MinLevel;
		Dest.Type = pIntType;
		return true;
	case Cost:
		Dest.DWord = pAbility->Cost;
		Dest.Type = pIntType;
		return true;
	case Spell:
		Dest.Type = pSpellType;
		if (Dest.Ptr = GetSpellByID(pAbility->SpellID))
		{
			return true;
		}
		return false;
	case RequiresAbility:
		Dest.Type = pAltAbilityType;
		if (pAbility->RequiredGroupLevels && *pAbility->RequiredGroupLevels>0)
		{
			for (unsigned long nAbility = 0; nAbility<NUM_ALT_ABILITIES; nAbility++)
			{
				if (PALTABILITY tmppAbility = GetAAByIdWrapper(nAbility))
				{
					if (tmppAbility->ID == *pAbility->RequiredGroupLevels)
					{
						Dest.Ptr = tmppAbility;
						return true;
					}
				}
			}
		}
		if (pAbility)
			DebugSpew("ability %d not found\n", pAbility->RequiredGroupLevels);
		return false;
	case RequiresAbilityPoints:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAbility->RequiresAbilityPoints) {
			Dest.DWord = *pAbility->RequiresAbilityPoints;
			return true;
		}
		return false;
	case MaxRank:
		Dest.DWord = pAbility->MaxRank;
		Dest.Type = pIntType;
		return true;
	case Rank://th current rank...
	case AARankRequired://kept this for legacy reasons...
	{
		int CurrentRank = pAbility->CurrentRank - 1;
		#if !defined(ROF2EMU) && !defined(UFEMU)
		if (((PcZoneClient*)pPCData)->HasAlternateAbility(pAbility->Index,NULL,false,false))
		#else
		if (((PcZoneClient*)pPCData)->HasAlternateAbility(pAbility->Index,NULL,false))
		#endif
		{
			CurrentRank++;
		}
		Dest.DWord = CurrentRank;
		Dest.Type = pIntType;
		return true;
	}
	case Type:
		Dest.DWord = pAbility->Type;
		Dest.Type = pIntType;
		return true;
	case Flags:
		Dest.DWord = (DWORD)&pAbility->bShowInAbilityWindow;
		Dest.Type = pIntType;
		return true;
	case Expansion:
		Dest.DWord = pAbility->Expansion;
		Dest.Type = pIntType;
		return true;
	case Passive:
		Dest.DWord = 1;
		Dest.Type = pBoolType;
		if (pAbility->SpellID != 0xFFFFFFFF)
			Dest.DWord = 0;
		return true;
	case PointsSpent:
		Dest.DWord = pAbility->TotalPoints;
		Dest.Type = pIntType;
		return true;
	case xIndex:
		Dest.DWord = pAbility->Index;
		Dest.Type = pIntType;
		return true;
	case CanTrain:
	{
		if (PALTABILITY pNextAbility = GetAAByIdWrapper(pAbility->NextGroupAbilityId))
			pAbility = pNextAbility;
		Dest.DWord = pAltAdvManager->CanTrainAbility((PcZoneClient*)pPCData, (CAltAbilityData*)pAbility, 0, 0, 0);
		Dest.Type = pBoolType;
		return true;
	}
	case NextIndex:
		Dest.DWord = pAbility->NextGroupAbilityId;
		Dest.Type = pIntType;
		return true;
	}
	return false;
}

bool MQ2GroupType::ToString(MQ2VARPTR VarPtr, PCHAR Destination)
{
	int nMembers = 0;
	PCHARINFO pChar = GetCharInfo();
	if (!pChar->pGroupInfo) return false;
	for (int index = 1; index<6; index++)
	{
		if (pChar->pGroupInfo->pMember[index])
			nMembers++;
	}
	_itoa_s(nMembers, Destination,MAX_STRING, 10);
	return true;
}

bool MQ2GroupType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2GroupType::FindMember(Member);
	PCHARINFO pChar = GetCharInfo();
	int i;
	if (!pMember || !pChar->pGroupInfo)
		return false;
	switch ((GroupMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)pChar->pGroupInfo;
		Dest.Type = pIntType;
		return true;
	case xMember:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			// by number
			Dest.DWord = GETNUMBER();
			return true;
		}
		else
		{
			if (pChar->pSpawn)
			{
				Dest.DWord = 0;
				if (!_stricmp(pChar->pSpawn->Name, GETFIRST())) {
					Dest.DWord = 0;
					return true;
				}
				for (i = 1; i < 6; i++)
				{
					if (pChar->pGroupInfo->pMember[i])
					{
						Dest.DWord++;
						CHAR Name[MAX_STRING] = { 0 };
						GetCXStr(pChar->pGroupInfo->pMember[i]->pName, Name, MAX_STRING);
						CleanupName(Name, sizeof(Name), FALSE, FALSE);//we do this to fix the mercenaryname bug
						if (GETFIRST()[0] != '\0' && !_stricmp(Name, GETFIRST()))
						{
							return true;
						}
					}
				}
			}
			return false;
		}
		return false;
	case Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (i = 1; i < 6; i++)
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		return true;
	case Leader:
	{
		Dest.Type = pGroupMemberType;
		if (!pChar->pGroupInfo->pLeader || !pChar->pSpawn)
			return false;
		CHAR LeaderName[MAX_STRING] = { 0 };
		GetCXStr(pChar->pGroupInfo->pLeader->pName, LeaderName, MAX_STRING);
		Dest.DWord = 0;
		if (!_stricmp(pChar->pSpawn->Name, LeaderName))
		{
			return true;
		}
		for (i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				CHAR Name[MAX_STRING] = { 0 };
				GetCXStr(pChar->pGroupInfo->pMember[i]->pName, Name, MAX_STRING);
				if (!_stricmp(Name, LeaderName))
				{
					return true;
				}
			}
		}
		if (!Dest.DWord)
		{
			// group has no members
			return true;
		}
		return false;
	}
	case GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (i = 1; i<6; i++)
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		if (Dest.DWord) Dest.DWord++;
		return true;
	case MainTank:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (pChar->pGroupInfo->pMember[0]->MainTank)
		{
			return true;
		}
		for (i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MainTank)
				{
					return true;
				}
			}
		}
		return false;
	case MainAssist:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (pChar->pGroupInfo->pMember[0]->MainAssist)
		{
			return true;
		}
		for (i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MainAssist)
				{
					return true;
				}
			}
		}
		return false;
	case Puller:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (pChar->pGroupInfo->pMember[0]->Puller)
		{
			return true;
		}
		for (i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->Puller)
				{
					return true;
				}
			}
		}
		return false;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case MarkNpc:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (pChar->pGroupInfo->pMember[0]->MarkNpc)
		{
			return true;
		}
		for (i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MarkNpc)
				{
					return true;
				}
			}
		}
		return false;
	case MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (pChar->pGroupInfo->pMember[0]->MasterLooter)
		{
			return true;
		}
		for (i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				Dest.DWord++;
				if (pChar->pGroupInfo->pMember[i]->MasterLooter)
				{
					return true;
				}
			}
		}
		return false;
#endif
	case AnyoneMissing:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		for (i = 1; i<6; i++) {
			if (pChar->pGroupInfo->pMember[i] && (pChar->pGroupInfo->pMember[i]->Offline || (pChar->pGroupInfo->pMember[i]->Offline == 0 && pChar->pGroupInfo->pMember[i]->pSpawn == 0) || (pChar->pGroupInfo->pMember[i]->pSpawn && pChar->pGroupInfo->pMember[i]->pSpawn->Type == SPAWN_CORPSE))) {
				Dest.DWord = 1;
				break;
			}
		}
		return true;
	case Present:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (i = 1; i<6; i++) {
			if (pChar->pGroupInfo->pMember[i] && pChar->pGroupInfo->pMember[i]->pSpawn && pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE) {
				Dest.DWord++;
			}
		}
		return true;
	case MercenaryCount:
		Dest.DWord = GetGroupMercenaryCount(AllClassesMASK);
		Dest.Type = pIntType;
		return true;
	case TankMercCount:
		Dest.DWord = GetGroupMercenaryCount(WarriorMASK);
		Dest.Type = pIntType;
		return true;
	case HealerMercCount:
		Dest.DWord = GetGroupMercenaryCount(ClericMASK);
		Dest.Type = pIntType;
		return true;
	case MeleeMercCount:
		Dest.DWord = GetGroupMercenaryCount(RogueMASK);
		Dest.Type = pIntType;
		return true;
	case CasterMercCount:
		Dest.DWord = GetGroupMercenaryCount(WizardMASK);
		Dest.Type = pIntType;
		return true;
	case AvgHPs:
	{
		Dest.DWord = 100;
		Dest.Type = pIntType;
		int nummembers = 1;

		__int64 hps = 0;
		if (pChar->pSpawn && pChar->pSpawn->HPCurrent && pChar->pSpawn->HPMax)
		{
			hps = (pChar->pSpawn->HPCurrent / pChar->pSpawn->HPMax) * 100;
		}
		for (i = 1; i < 6; i++) {
			if (pChar->pGroupInfo->pMember[i] && pChar->pGroupInfo->pMember[i]->pSpawn && pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE) {
				hps += pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
				nummembers++;
			}
		}
		if (hps != 0 && nummembers != 0) {
			Dest.Int64 = hps / nummembers;
		}
		return true;
	}
	case Injured:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (int threshold = GETNUMBER()) {
			__int64 hps = 0;
			for (i = 0; i < 6; i++) {
				if (pChar->pGroupInfo->pMember[i] && pChar->pGroupInfo->pMember[i]->pSpawn && pChar->pGroupInfo->pMember[i]->pSpawn->Type != SPAWN_CORPSE && pChar->pGroupInfo->pMember[i]->Offline == 0) {
					if (i == 0) {
						if (pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent && pChar->pGroupInfo->pMember[i]->pSpawn->HPMax) {
							float fhpc = (float)pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
							float fhpm = (float)pChar->pGroupInfo->pMember[i]->pSpawn->HPMax;
							hps = (int)((fhpc / fhpm) * 100);
						}
					}
					else {
						hps = pChar->pGroupInfo->pMember[i]->pSpawn->HPCurrent;
					}
					if (hps > 0 && hps < threshold) {
						Dest.DWord++;
					}
				}
			}

		}
		return true;
	case XCleric:
		Dest.Ptr = 0;
		Dest.Type = pSpawnType;
		for (i = 0; i < 6; i++) {
			if (pChar->pGroupInfo->pMember[i] && pChar->pGroupInfo->pMember[i]->Mercenary==0 && pChar->pGroupInfo->pMember[i]->pSpawn && pChar->pGroupInfo->pMember[i]->pSpawn->GetClass()==Cleric) {
				Dest.Ptr = pChar->pGroupInfo->pMember[i]->pSpawn;
				return true;
			}
		}
		return false;
	case MouseOver:
		Dest.DWord = 0;
		Dest.Type = pGroupMemberType;
		if (PCXWNDMGR pwndmgr = (PCXWNDMGR)pWndMgr) {
			if (CXWnd*pWnd = (CXWnd*)pwndmgr->LastMouseOver) {
				if (CXMLData *pXMLData = ((CXWnd*)pWnd)->GetXMLData()) {
					CHAR szName[MAX_STRING] = { 0 };
					GetCXStr(pXMLData->Name.Ptr, szName, MAX_STRING);
					if (szName[0] != '\0') {
						if (!_strnicmp(szName, "gw_gauge", 8)) {
							//ok they are actually hovering a groupmember, but which one?
							if (char *memnum = &szName[8]) {
								int i = atoi(memnum);
								if (pChar->pGroupInfo->pMember[i])
								{
									Dest.DWord = i;
									return true;
								}
							}
						} else if (!_strnicmp(szName, "player_hp", 9)) {
							//ok they are actually hovering myself
							Dest.DWord = 0;
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	return false;
}

bool MQ2GroupMemberType::ToString(MQ2VARPTR VarPtr, PCHAR Destination)
{
	int i;
	if (unsigned long N = VarPtr.DWord)
	{
		if (N>5)
			return false;
		PCHARINFO pChar = GetCharInfo();
		if (!pChar->pGroupInfo) return false;
		for (i = 1; i<6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				N--;
				if (N == 0)
				{
					CHAR Name[MAX_STRING] = { 0 };
					GetCXStr(pChar->pGroupInfo->pMember[i]->pName, Name, MAX_STRING);
					strcpy_s(Destination,MAX_STRING, CleanupName(Name, MAX_STRING, FALSE, FALSE));
					return true;
				}
			}
		}
	}
	else
	{
		//CleanupName(strcpy_s(Destination,MAX_STRING,GetCharInfo()->pSpawn->Name),FALSE,FALSE);
		strcpy_s(Destination,MAX_STRING, GetCharInfo()->pSpawn->DisplayedName);
		return true;
	}
	return false;
}

bool MQ2GroupMemberType::GETMEMBER()
{
	CHAR MemberName[MAX_STRING] = { 0 };
	CHAR LeaderName[MAX_STRING] = { 0 };
	PSPAWNINFO pGroupMember = 0;
	PCHARINFO pChar = GetCharInfo();
	PGROUPMEMBER pGroupMemberData = 0;
	int i;
	DWORD nMember = VarPtr.DWord;
	if (!pChar->pGroupInfo) return false;
	if (unsigned long N = nMember)
	{
		if (N>5)
			return false;
		for (i = 1; i<6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				N--;
				if (N == 0)
				{
					GetCXStr(pChar->pGroupInfo->pMember[i]->pName, MemberName, MAX_STRING);
					if (pChar->pGroupInfo->pMember[i]->pSpawn) {
						pGroupMember = pChar->pGroupInfo->pMember[i]->pSpawn;
					}
					pGroupMemberData = pChar->pGroupInfo->pMember[i];
					break;
				}
			}
		}
		if (!MemberName)
			return false;
	}
	else
	{
		if (pGroupMember = pChar->pSpawn) {
			strcpy_s(MemberName, pGroupMember->Name);
		}
		pGroupMemberData = pChar->pGroupInfo->pMember[0];
	}
	PMQ2TYPEMEMBER pMember = MQ2GroupMemberType::FindMember(Member);
	if (!pMember)
	{
		if (!pGroupMember)
			return false;
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pGroupMember, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pGroupMember, Member, argc, argv, Dest);
#endif
	}

	switch ((GroupMemberMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)pGroupMemberData;
		Dest.Type = pIntType;
		return true;
	case Name:
		strcpy_s(DataTypeTemp, CleanupName(MemberName,sizeof(MemberName), FALSE, FALSE));
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	case Leader:
		Dest.Type = pBoolType;
		if (!pChar->pGroupInfo->pLeader) return false;
		GetCXStr(pChar->pGroupInfo->pLeader->pName, LeaderName, MAX_STRING);
		Dest.DWord = !_stricmp(MemberName, LeaderName);
		return true;
	case Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = pGroupMember)
		{
			return true;
		}
		return false;
	case Level:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pGroupMember)
		{
			Dest.DWord = pGroupMember->Level;
			return true;
		}
		else if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Level;
			return true;
		}
		return false;
	case MainTank:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MainTank;
			return true;
		}
		return false;
	case MainAssist:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MainAssist;
			return true;
		}
		return false;
#if !defined(ROF2EMU) && !defined(UFEMU)
	case MarkNpc:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MarkNpc;
			return true;
		}
		return false;
	case MasterLooter:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->MasterLooter;
			return true;
		}
		return false;
#endif
	case Puller:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Puller;
			return true;
		}
		return false;
	case Mercenary:
		Dest.Type = pBoolType;
		if (pGroupMemberData)
		{
			Dest.DWord = pGroupMemberData->Mercenary;
			return true;
		}
		return false;
	case PctAggro:
		Dest.Type = pIntType;
		if (PGROUPAGGRO pAggrp = (PGROUPAGGRO)EQADDR_GROUPAGGRO) {
//		PGROUPAGGRO pAggrp = (PGROUPAGGRO)EQADDR_GROUPAGGRO;
//		if (pAggrp)
//		{
			if (nMember == 0)//Player is always nMember 0 but in the GroupMemberAggro struct its always 5...
				Dest.DWord = pAggrp->GroupMemberAggro[5];
			else
				Dest.DWord = pAggrp->GroupMemberAggro[nMember - 1];
			return true;
		}
		return false;
	case xIndex:
		Dest.DWord = nMember;
		Dest.Type = pIntType;
		return true;
	case Offline:
		Dest.Type = pBoolType;
		if (pGroupMemberData) {
			Dest.DWord = pGroupMemberData->Offline;
			return true;
		}
		return false;
	case Present:
		Dest.Type = pBoolType;
		if (pGroupMemberData) {
			Dest.DWord = pGroupMemberData->pSpawn ? 1 : 0;
			Dest.Type = pBoolType;
			return true;
		}
		return false;
	case OtherZone:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pGroupMemberData && pGroupMemberData->Offline == 0 && pGroupMemberData->pSpawn == 0)
			Dest.DWord = 1;
		return true;
	}
	return false;
}

bool MQ2RaidType::GETMEMBER()
{
	int i;
	if (!pRaid)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2RaidType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((RaidMembers)pMember->ID)
	{
	case Locked:
		Dest.DWord = pRaid->Locked;
		Dest.Type = pBoolType;
		return true;
	case Invited:
		Dest.DWord = pRaid->Invited == 2;
		Dest.Type = pBoolType;
		return true;
	case xMember:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (!Count || Count>pRaid->RaidMemberCount)
					return false;
				for (DWORD nMember = 0; nMember < 72; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember])
					{
						Count--;
						if (!Count)
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (DWORD nMember = 0; nMember < 72; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && !_stricmp(pRaid->RaidMember[nMember].Name, GETFIRST()))
					{
						Dest.DWord = nMember + 1;
						return true;
					}
				}
			}
		}
		return false;
	case Members:
		Dest.DWord = pRaid->RaidMemberCount;
		Dest.Type = pIntType;
		return true;
	case Target:
		Dest.DWord = pRaid->RaidTarget + 1;
		Dest.Type = pRaidMemberType;
		return true;
	case Leader:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (DWORD nMember = 0; nMember < 72; nMember++)
		{
			if (pRaid->RaidMemberUsed[nMember] && !_stricmp(pRaid->RaidMember[nMember].Name, pRaid->RaidLeaderName))
			{
				Dest.DWord = nMember + 1;
				return true;
			}
		}
		return false;
	case TotalLevels:
		Dest.DWord = pRaid->TotalRaidMemberLevels;
		Dest.Type = pIntType;
		return true;
	case AverageLevel:
		Dest.Float = (FLOAT)pRaid->TotalRaidMemberLevels / (FLOAT)pRaid->RaidMemberCount;
		Dest.Type = pFloatType;
		return true;
	case LootType:
		Dest.DWord = pRaid->LootType;
		Dest.Type = pIntType;
		return true;
	case Looters:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (unsigned long N = 0; N < 0x13; N++)
		{
			if (pRaid->RaidLooters[N][0])
				Dest.DWord++;
		}
		return true;
	case Looter:
		Dest.Type = pStringType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (!Count)
					return 0;
				for (DWORD nLooter = 0; nLooter<0x13; nLooter++)
				{
					if (pRaid->RaidLooters[nLooter][0])
					{
						Count--;
						if (Count == 0)
						{
							strcpy_s(DataTypeTemp, pRaid->RaidLooters[nLooter]);
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			// by name?
		}
		return false;
	case MainAssist:
	{
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;

		PCHARINFO pCharInfo = GetCharInfo();
		if (!pCharInfo)
			return false;

		CharacterBase* cb = (CharacterBase*)&pCharInfo->CharacterBase_vftable;
		if (!cb)
			return false;

		RaidData* rd = &cb->raidData;
		if (!rd)
			return false;

		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (Count < 1 || Count > 3)
					return false;

				//This matches what EQ says the RA at this index is.
				char* RAName = rd->MainAssistNames[Count - 1];
				if (!strlen(RAName))
					return false;

				for (int nMember = 0; nMember < 72; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && pRaid->RaidMember[nMember].RaidMainAssist)
					{
						if (!strcmp(pRaid->RaidMember[nMember].Name, RAName))
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (DWORD nMember = 0; nMember < 72; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && pRaid->RaidMember[nMember].RaidMainAssist)
					{
						if (!_stricmp(pRaid->RaidMember[nMember].Name, GETFIRST()))
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
		}
		else {//no index provided. return first RA found.
			for (i = 0; i < 72; i++)
			{
				if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].RaidMainAssist)
				{
					Dest.DWord = i + 1;
					return true;
				}
			}
		}
		return false;
	}
#if !defined(ROF2EMU) && !defined(UFEMU)
	case MasterLooter:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;
		for (i = 0; i < 72; i++)
		{
			if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].MasterLooter)
			{
				Dest.DWord = i + 1;
				return true;
			}
		}
		return false;
	case MarkNPC:
		Dest.DWord = 0;
		Dest.Type = pRaidMemberType;

		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD Count = GETNUMBER();
				if (Count < 1 || Count > 3)
					return false;

				for (int nMember = 0; nMember < 72; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && pRaid->RaidMember[nMember].RaidMarker)
					{
						Count--;
						if (Count)
							continue;

						Dest.DWord = nMember + 1;
						return true;
					}
				}
			}
			else
			{
				// by name
				for (DWORD nMember = 0; nMember < 72; nMember++)
				{
					if (pRaid->RaidMemberUsed[nMember] && pRaid->RaidMember[nMember].RaidMarker)
					{
						if (!_stricmp(pRaid->RaidMember[nMember].Name, GETFIRST()))
						{
							Dest.DWord = nMember + 1;
							return true;
						}
					}
				}
			}
		}
		else {//no index provided. return first RA found.
			for (i = 0; i < 72; i++)
			{
				if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].RaidMarker)
				{
					Dest.DWord = i + 1;
					return true;
				}
			}
		}
		return false;
#endif
	}
	/**/
	return false;
}

bool MQ2RaidMemberType::GETMEMBER()
{
	DWORD nRaidMember = VarPtr.DWord - 1;
	if (VarPtr.DWord >= 72)
		return false;
	if (!pRaid->RaidMemberUsed[nRaidMember])
		return false;
	PEQRAIDMEMBER pRaidMember = &pRaid->RaidMember[nRaidMember];
	PMQ2TYPEMEMBER pMember = MQ2RaidMemberType::FindMember(Member);
	if (!pMember)
	{
		PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByName(pRaidMember->Name);
		if (!pSpawn)
			return false;
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&pSpawn, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&pSpawn, Member, argc, argv, Dest);
#endif
	}

	switch ((RaidMemberMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp,  pRaidMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Group:
		Dest.DWord = pRaidMember->GroupNumber + 1;
		Dest.Type = pIntType;
		return true;
	case GroupLeader:
		Dest.DWord = pRaidMember->GroupLeader;
		Dest.Type = pBoolType;
		return true;
	case RaidLeader:
		Dest.DWord = pRaidMember->RaidLeader;
		Dest.Type = pBoolType;
		return true;
	case Looter:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pRaidMember->RaidLeader)
		{
			Dest.DWord = 1;
			return true;
		}
		if (pRaid->LootType == 2)
		{
			Dest.DWord = pRaidMember->GroupLeader;
			return true;
		}
		if (pRaid->LootType == 3)
		{
			for (DWORD N = 0; N < 0x13; N++)
			{
				if (!_stricmp(pRaid->RaidLooters[N], pRaidMember->Name))
				{
					Dest.DWord = 1;
					return true;
				}
			}
		}
		return true;
	case Spawn:
		Dest.Type = pSpawnType;
		if (Dest.Ptr = (PSPAWNINFO)GetSpawnByName(pRaidMember->Name))
		{
			return true;
		}
		return false;
	case Level:
		Dest.DWord = pRaidMember->nLevel;
		Dest.Type = pIntType;
		return true;
	case Class:
		Dest.DWord = pRaidMember->nClass;
		Dest.Type = pClassType;
		return true;
		/*
		{
		if (PSPAWNINFO pSpawn=(PSPAWNINFO)GetSpawnByName(pRaidMember->Name))
		{
		Dest.DWord=pSpawn->mActorClient.Class;
		Dest.Type=pIntType;
		return true;
		}
		pCharData->KunarkClass(0,0,0x18C,1);
		}
		return false;
		/**/
	}
	return false;
}

bool MQ2EvolvingItemType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PCONTENTS pItem = (PCONTENTS)VarPtr.Ptr;
	PMQ2TYPEMEMBER pMember = MQ2EvolvingItemType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((EvolvingItemMembers)pMember->ID)
	{
	case ExpOn:
	#if defined(ROF2EMU) || defined(UFEMU)
		Dest.DWord = pItem->EvolvingExpOn;
	#else
		Dest.DWord = true;//its always on after 2019-02-14 test patch
	#endif
		Dest.Type = pBoolType;
		return true;
#if defined(ROF2EMU) || defined(UFMU)
	case ExpPct:
		Dest.Float = (FLOAT)pItem->EvolvingExpPct;
		Dest.Type = pFloatType;
		return true;
	case Level:
		Dest.DWord = pItem->EvolvingCurrentLevel;
		Dest.Type = pIntType;
		return true;
	case MaxLevel:
		Dest.DWord = pItem->EvolvingMaxLevel;
		Dest.Type = pIntType;
		return true;
#else
	case ExpPct:
		if (pItem->pEvolutionData)
		{
			Dest.Float = (FLOAT)pItem->pEvolutionData->EvolvingExpPct;
			Dest.Type = pFloatType;
			return true;
		}
		break;
	case Level:
		if (pItem->pEvolutionData)
		{
			Dest.DWord = pItem->pEvolutionData->EvolvingCurrentLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;
	case MaxLevel:
		if (pItem->pEvolutionData)
		{
			Dest.DWord = pItem->pEvolutionData->EvolvingMaxLevel;
			Dest.Type = pIntType;
			return true;
		}
		break;
#endif
	}
	return false;
}

bool MQ2DynamicZoneType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2DynamicZoneType::FindMember(Member);
	if (!pMember)
		return false;

	if (!pDZMember && (DynamicZoneMembers)pMember->ID != LeaderFlagged)
		return false;
	switch ((DynamicZoneMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp,  pDynamicZone->DZName);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Members:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;
		PDZMEMBER pDynamicZoneMember = pDynamicZone->pFirstMember;
		while (pDynamicZoneMember)
		{
			Dest.DWord++;
			pDynamicZoneMember = pDynamicZoneMember->pNext;
		}
		return true;
	}
	case LeaderFlagged:
		Dest.DWord = 0;
		if (pDynamicZone && pDynamicZone->pFirstMember)
		{
			Dest.DWord = pDynamicZone->pFirstMember->bFlagged;
		}
		Dest.Type = pBoolType;
		return true;
	case MaxMembers:
		Dest.DWord = pDynamicZone->MaxPlayers;
		Dest.Type = pIntType;
		return true;
	case xMember:
		Dest.Type = pDZMemberType;
		if (ISINDEX())
		{
			PDZMEMBER pDynamicZoneMember = pDynamicZone->pFirstMember;
			if (ISNUMBER())
			{
				int Count = GETNUMBER();
				if (!Count || Count>pDynamicZone->MaxPlayers)
					return false;
				Count--;
				for (DWORD i = 0; pDynamicZoneMember != 0; i++)
				{
					if (i == Count)
					{
						Dest.Ptr = pDynamicZoneMember;
						return true;
					}
					pDynamicZoneMember = pDynamicZoneMember->pNext;
				}
			}
			else
			{
				while (pDynamicZoneMember)
				{
					if (!_stricmp(pDynamicZoneMember->Name, GETFIRST()))
					{
						Dest.Ptr = pDynamicZoneMember;
						return true;
					}
					pDynamicZoneMember = pDynamicZoneMember->pNext;
				}
			}
		}
		return false;
	case Leader:
	{
		Dest.Type = pDZMemberType;
		PDZMEMBER pDynamicZoneMember = pDynamicZone->pFirstMember;
		for (int i = 0; i<pDynamicZone->MaxPlayers && pDynamicZoneMember; i++)
		{
			if (!strcmp(pDynamicZoneMember->Name, (char*)instExpeditionLeader))
			{
				Dest.Ptr = pDynamicZoneMember;
				return true;
			}
			pDynamicZoneMember = pDynamicZoneMember->pNext;
		}
		return false;
	}
	case InRaid:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pDynamicZone && pDynamicZone->LeaderName[0]) {
			Dest.DWord = 1;
		}
		return true;
	}
	return false;
}

bool MQ2DZMemberType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2DZMemberType::FindMember(Member);
	if (!pMember)
		return false;
	PDZMEMBER pDynamicZoneMember = (PDZMEMBER)VarPtr.Ptr;
	switch ((DZMemberTypeMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp, pDynamicZoneMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Flagged:
		Dest.DWord = pDynamicZoneMember->bFlagged;
		Dest.Type = pBoolType;
		return true;
	case Status:
		strcpy_s(DataTypeTemp, "Unknown");
		switch (pDynamicZoneMember->Status)
		{
		case 0:
			strcpy_s(DataTypeTemp, "Unknown");
			break;
		case 1:
			strcpy_s(DataTypeTemp, "Online");
			break;
		case 2:
			strcpy_s(DataTypeTemp, "Offline");
			break;
		case 3:
			strcpy_s(DataTypeTemp, "In Dynamic Zone");
			break;
		case 4:
			strcpy_s(DataTypeTemp, "Link Dead");
			break;
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	return false;
}

bool MQ2FellowshipType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2FellowshipType::FindMember(Member);
	if (!pMember)
		return false;
	PFELLOWSHIPINFO pFellowship = (PFELLOWSHIPINFO)VarPtr.Ptr;
	switch ((FellowshipTypeMembers)pMember->ID)
	{
	case ID:
		Dest.DWord = pFellowship->FellowshipID;
		Dest.Type = pIntType;
		return true;
	case Leader:
		strcpy_s(DataTypeTemp, pFellowship->Leader);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case MotD:
		strcpy_s(DataTypeTemp, pFellowship->MotD);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Members:
		Dest.DWord = pFellowship->Members;
		Dest.Type = pIntType;
		return true;
	case xMember:
		Dest.Type = pFellowshipMemberType;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				int i = GETNUMBER();
				if (!i || i>pFellowship->Members)
					return false;
				Dest.Ptr = &pFellowship->FellowshipMember[--i];
				return true;
			}
			else
			{
				for (int i = 0; i<pFellowship->Members; i++)
				{
					if (!_stricmp(pFellowship->FellowshipMember[i].Name, GETFIRST()))
					{
						Dest.Ptr = &pFellowship->FellowshipMember[i];
						return true;
					}
				}
			}
		}
		return false;
	case CampfireDuration:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (((PSPAWNINFO)pLocalPlayer)->CampfireTimestamp)
		{
			Dest.DWord = (((PSPAWNINFO)pLocalPlayer)->CampfireTimestamp - GetFastTime()) / 6;
			return true;
		}
		return false;
	case CampfireY:
		Dest.Float = ((PSPAWNINFO)pLocalPlayer)->CampfireY;
		Dest.Type = pFloatType;
		return true;
	case CampfireX:
		Dest.Float = ((PSPAWNINFO)pLocalPlayer)->CampfireX;
		Dest.Type = pFloatType;
		return true;
	case CampfireZ:
		Dest.Float = ((PSPAWNINFO)pLocalPlayer)->CampfireZ;
		Dest.Type = pFloatType;
		return true;
	case CampfireZone:
		Dest.Type = pZoneType;
		if (DWORD zoneID = (((PSPAWNINFO)pLocalPlayer)->CampfireZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData) {
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zoneID];
				return true;
			}
		}
		return false;
	case Campfire:
		Dest.Int = ((PSPAWNINFO)pLocalPlayer)->Campfire;
		Dest.Type = pBoolType;
		return true;
	case Sharing:
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				int i = GETNUMBER();
				i--;
				if (i < 0)
					i = 0;
				if (i > pFellowship->Members)
					return false;
				Dest.DWord = pFellowship->bExpSharingEnabled[i];
				Dest.Type = pBoolType;
				return true;
			}
		}
		return false;
	}
	return false;
}

bool MQ2FellowshipMemberType::GETMEMBER()
{
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2FellowshipMemberType::FindMember(Member);
	if (!pMember)
		return false;
	PFELLOWSHIPMEMBER pFellowshipMember = (PFELLOWSHIPMEMBER)VarPtr.Ptr;
	switch ((FMTypeMembers)pMember->ID)
	{
	case Zone:
		if (DWORD zoneID = (pFellowshipMember->ZoneID & 0x7FFF))
		{
			if (zoneID < MAX_ZONES && pWorldData)
			{
				Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zoneID];
				Dest.Type = pZoneType;
				return true;
			}
		}
		return false;
	case Level:
		Dest.DWord = pFellowshipMember->Level;
		Dest.Type = pIntType;
		return true;
	case Class:
		Dest.DWord = pFellowshipMember->Class;
		Dest.Type = pClassType;
		return true;
	case LastOn:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pFellowshipMember->LastOn)
		{
			Dest.DWord = (GetFastTime() - pFellowshipMember->LastOn) / 6;
			return true;
		}
		return false;
	case Name:
		strcpy_s(DataTypeTemp, pFellowshipMember->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	return false;
}

bool MQ2FriendsType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2FriendsType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((FriendsMembers)pMember->ID)
	{
	case xFriend:
		Dest.Type = pStringType;
		if (ISINDEX() && ((PEVERQUEST)pEverQuest)->ChatService) {
			class CChatService *pChat = (class CChatService *) ((PEVERQUEST)pEverQuest)->ChatService;
			int i;
			if (ISNUMBER()) {
				i = GETNUMBER();
				if (i > pChat->GetNumberOfFriends())
					return false;
				if (char *ptr = pChat->GetFriendName(i - 1)) {
					strcpy_s(DataTypeTemp, ptr);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				}
			}
			else {
				for (i = 0; i<pChat->GetNumberOfFriends(); i++) {
					if (!_stricmp(pChat->GetFriendName(i), GETFIRST())) {
						Dest.DWord = 1;
						Dest.Type = pBoolType;
						return true;
					}
				}
				return false;
			}
		}
		return false;
	default:
		return false;
	};
}

bool MQ2TargetType::GETMEMBER()
{
	int buffID = 0;
	DWORD i;
	if (!VarPtr.Ptr)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2TargetType::FindMember(Member);
	if (!pMember)
	{
#ifndef ISXEQ
		return pSpawnType->GetMember(*(MQ2VARPTR*)&VarPtr.Ptr, Member, Index, Dest);
#else
		return pSpawnType->GetMember(*(LSVARPTR*)&VarPtr.Ptr, Member, argc, argv, Dest);
#endif
	}
	switch ((TargetMembers)pMember->ID)
	{
	case BuffsPopulated:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (gTargetbuffs && pTarget)
			Dest.DWord = gTargetbuffs;
		return true;
	case Buff:
		Dest.Type = pSpellType;
		if (!(((PCTARGETWND)pTargetWnd)->Type > 0))
			return false;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD nBuff = GETNUMBER();
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;
				buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[nBuff];
				if (buffID && buffID != -1) {
					if (Dest.Ptr = GetSpellByID((DWORD)buffID)) {
						Dest.HighPart = nBuff;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
			else
			{
				for (i = 0; i < NUM_BUFF_SLOTS; i++)
				{
					buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
					if (buffID && !_strnicmp(GETFIRST(), GetSpellNameByID(buffID), strlen(GETFIRST())))
					{
						if (Dest.Ptr = GetSpellByID((DWORD)buffID)) {
							Dest.HighPart = i;
							Dest.Type = pSpellType;
							return true;
						}
					}
				}
			}
		}
		else
		{
			// return first buff
			for (i = 0; i < NUM_BUFF_SLOTS; i++)
			{
				buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
				if (buffID)
				{
					if (PSPELL pSpell = GetSpellByID(buffID))
					{
						strcpy_s(DataTypeTemp, pSpell->Name);
						Dest.Ptr = &DataTypeTemp[0];
						Dest.Type = pStringType;
						return true;
					}
				}
			}
		}
		return false;
    case MyBuff:
		Dest.Type = pSpellType;
		if( !(((PCTARGETWND)pTargetWnd)->Type > 0) )
            return false;
        if( ISINDEX() )
        {
            if( ISNUMBER() )
            {
                DWORD nBuff = GETNUMBER();
                if( nBuff > NUM_BUFF_SLOTS )
                    return false;
                if( nBuff >= 1 )
                    nBuff--;
                buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[nBuff];
                if( GetCharInfo() && buffID && buffID != -1 ) {
                    if( targetBuffSlotToCasterMap.size() && targetBuffSlotToCasterMap.find( nBuff ) != targetBuffSlotToCasterMap.end() ) {
                        if( !strcmp( GetCharInfo()->Name, targetBuffSlotToCasterMap[nBuff].c_str() ) ) {
                            if( Dest.Ptr = GetSpellByID( (DWORD)buffID ) ) {
                                Dest.HighPart = nBuff;
                                Dest.Type = pSpellType;
                                return true;
                            }
                        }
                    }

                }
            }
            else
            {
                if( targetBuffSlotToCasterMap.size() && GetCharInfo() ) {
                    for( i = 0; i < NUM_BUFF_SLOTS; i++ )
                    {
                        if( targetBuffSlotToCasterMap.find( i ) != targetBuffSlotToCasterMap.end() && !strcmp( GetCharInfo()->Name, targetBuffSlotToCasterMap[i].c_str() ) ) {
                            buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                            if( buffID && !_strnicmp( GETFIRST(), GetSpellNameByID( buffID ), strlen( GETFIRST() ) ) ) {
                                if( Dest.Ptr = GetSpellByID( (DWORD)buffID ) ) {
                                    Dest.HighPart = i;
                                    Dest.Type = pSpellType;
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            // return first buff
            if( targetBuffSlotToCasterMap.size() && GetCharInfo() ) {
                for( i = 0; i < NUM_BUFF_SLOTS; i++ )
                {
                    if( targetBuffSlotToCasterMap.find( i ) != targetBuffSlotToCasterMap.end() && !strcmp( GetCharInfo()->Name, targetBuffSlotToCasterMap[i].c_str() ) ) {
                        buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                        if( buffID )
                        {
                            if( PSPELL pSpell = GetSpellByID( buffID ) )
                            {
                                strcpy_s( DataTypeTemp, pSpell->Name );
                                Dest.Ptr = &DataTypeTemp[0];
                                Dest.Type = pStringType;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
	case BuffCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!(((PCTARGETWND)pTargetWnd)->Type > 0))
			return false;
		for (i = 0; i < NUM_BUFF_SLOTS; i++)
			if (((PCTARGETWND)pTargetWnd)->BuffSpellID[i])
				Dest.DWord++;
		return true;
    case MyBuffCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if( !(((PCTARGETWND)pTargetWnd)->Type > 0) )
            return false;
        if( targetBuffSlotToCasterMap.size() && GetCharInfo() ) {
            for( i = 0; i < NUM_BUFF_SLOTS; i++ )
            {
                if( targetBuffSlotToCasterMap.find( i ) != targetBuffSlotToCasterMap.end() && !strcmp( GetCharInfo()->Name, targetBuffSlotToCasterMap[i].c_str() ) ) {
                    buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                    if( buffID )
                    {
                        Dest.DWord++;
                    }
                }
            }
        }
        return true;
	case MyBuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!(((PCTARGETWND)pTargetWnd)->Type > 0))
			return false;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				DWORD nBuff = GETNUMBER();
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;
				buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[nBuff];
				if (GetCharInfo() && buffID && buffID != -1) {
					if (targetBuffSlotToCasterMap.size() && targetBuffSlotToCasterMap.find(nBuff) != targetBuffSlotToCasterMap.end()) {
						if (!strcmp(GetCharInfo()->Name, targetBuffSlotToCasterMap[nBuff].c_str())) {
							Dest.UInt64 = ((PCTARGETWND)pTargetWnd)->BuffTimer[nBuff];
							return true;
						}
					}

				}
			}
			else
			{
				if (targetBuffSlotToCasterMap.size() && GetCharInfo()) {
					for (i = 0; i < NUM_BUFF_SLOTS; i++)
					{
						if (targetBuffSlotToCasterMap.find(i) != targetBuffSlotToCasterMap.end() && !strcmp(GetCharInfo()->Name, targetBuffSlotToCasterMap[i].c_str())) {
							buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
							if (buffID && !_strnicmp(GETFIRST(), GetSpellNameByID(buffID), strlen(GETFIRST()))) {
								Dest.UInt64 = ((PCTARGETWND)pTargetWnd)->BuffTimer[i];
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	case BuffDuration:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!(((PCTARGETWND)pTargetWnd)->Type > 0))
			return false;
		if (ISINDEX())
		{
			if (ISNUMBER())
			{
				//for some reason we indulged the users by letting them specify 1 based indexes, that
				// was probably a bad idea in a macrolanguage since its pseudo coding anyway...
				// and it would actually be a good way to educate users in how to program...
				// but it is what it is, so ill just nBuff--; and get it over with... -eqmule
				DWORD nBuff = GETNUMBER();
				if (nBuff > NUM_BUFF_SLOTS)
					return false;
				if (nBuff >= 1)
					nBuff--;
				buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[nBuff];
				if (buffID && buffID != -1) {
					//Dest.DWord = ((((PCTARGETWND)pTargetWnd)->BuffTimer[nBuff] / 1000) + 6) / 6;
					Dest.UInt64 = ((PCTARGETWND)pTargetWnd)->BuffTimer[nBuff];
					return true;
				}
			}
			else {
				DWORD duration = 0;
				for (i = 0; i < NUM_BUFF_SLOTS; i++) {
					buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
					//I strncmp them to take ranked buffs into account
					//so if the user specifies ${Target.BuffDuration[Pyromancy]} for exxample
					//its still gonna work if it finds Pyromancy XV
					if (buffID && buffID != -1 && !_strnicmp(GETFIRST(), GetSpellNameByID(buffID), strlen(GETFIRST()))) {
						if (((PCTARGETWND)pTargetWnd)->BuffTimer[i]>duration) {
							duration = ((PCTARGETWND)pTargetWnd)->BuffTimer[i];
							//we always want to return the buff with the longest duration
							//cause thats the one that landed last on the mob
							//otherwize we could just break; out of here at this point
							//but anyway thats the reason we keep rolling through all them... -eqmule
						}
					}
					if (duration>0) {
						Dest.UInt64 = duration;
						return true;
					}
				}
			}
		}
		return false;
	case PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;
	case SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;
	case SecondaryAggroPlayer:
		Dest.Type = pSpawnType;
		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;
	case AggroHolder:
	{
		Dest.Type = pSpawnType;
		//who the Target has the MOST aggro on
		PCHAR pTargetAggroHolder = EQADDR_TARGETAGGROHOLDER;
		if (pTargetAggroHolder[0] != '\0')
		{
			PSPAWNINFO pAggroHolder = (PSPAWNINFO)GetSpawnByName(pTargetAggroHolder);
			if (pAggroHolder)
			{
				Dest.Ptr = pAggroHolder;
				return true;
			}
			else {
				//ok no spawn was found for the name given, this can only mean one thing... its a pet or a mercenary
				SEARCHSPAWN SearchSpawn;
				ClearSearchSpawn(&SearchSpawn);
				SearchSpawn.FRadius = 999999.0f;
				strcpy_s(SearchSpawn.szName, pTargetAggroHolder);
				pAggroHolder = SearchThroughSpawns(&SearchSpawn, (PSPAWNINFO)pLocalPlayer);
				if (pAggroHolder)
				{
					Dest.Ptr = pAggroHolder;
					return true;
				}
			}
		}
		else {
			//it could be me...
			//lets check
			if (pTarget && EQADDR_GROUPAGGRO) {
				if (*(DWORD*)(EQADDR_GROUPAGGRO + 0x78) >= 100) {
					if (Dest.Ptr = GetSpawnByID(((PSPAWNINFO)pLocalPlayer)->TargetOfTarget))
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	case Slowed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(11, 0)) != -1)
		{
			return true;
		}
		return false;
	case Rooted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(99, 0)) != -1)//Root
		{
			return true;
		}
		return false;
	case Mezzed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(31, 0)) != -1)//Entrall
		{
			return true;
		}
		return false;
	case Crippled:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySubCat("Disempowering")) != -1)
		{
			return true;
		}
		return false;
	case Maloed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySubCat("Resist Debuffs", (1 << Shaman) + (1 << Mage))) != -1)
		{
			return true;
		}
		return false;
	case Tashed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySubCat("Resist Debuffs", 1 << Enchanter)) != -1)
		{
			return true;
		}
		return false;
	case Snared:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(3, 0)) != -1)//Movement Rate
		{
			return true;
		}
		return false;
	case Hasted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(11, 1)) != -1)
		{
			return true;
		}
		return false;
	case Beneficial:
	{
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((((PCTARGETWND)pTargetWnd)->Type <= 0))
			return false;
		CHAR szBuffer[MAX_STRING] = { 0 };
		for (i = 0; i < NUM_BUFF_SLOTS; i++)
		{
			if (((PCTARGETWND)pTargetWnd)->BuffSpellID[i] == -1 || ((PCTARGETWND)pTargetWnd)->BuffSpellID[i] == 0)
				continue;
			if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[i])) {
				if (pSpell->SpellType != 0)
				{
					//targetwindow has a leak in it player buffs shows up in it
					//so we need to make sure its not a "leaked buff"
					if (CXStr *ptr = pTargetWnd->GetBuffCaster(pSpell->ID))
					{
						if (GetCXStr(ptr->Ptr, szBuffer, MAX_STRING)) {
							if (PSPAWNINFO pPlayer = (PSPAWNINFO)GetSpawnByName(szBuffer)) {
								if (pPlayer->Type == SPAWN_PLAYER) {
									continue;
								}
							}
						}
					}
					Dest.Int = i;
					return true;
				}
			}
		}
		return false;
	}
	case DSed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(59, 1)) != -1)//Damage Shield
		{
			return true;
		}
		return false;
	case RevDSed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(121, 1)) != -1)//Reverse Damage Shield
		{
			return true;
		}
		return false;
	case Charmed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(22, 0)) != -1)//Charm
		{
			return true;
		}
		return false;
	case Aego:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric)) != -1)//Aegolism Line
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if ((GetSpellSubcategory(pSpell) == 1) || (GetSpellSubcategory(pSpell) == 112))
					{
						if (((EQ_Spell *)pSpell)->SpellAffectBase(1))
						{
							return true;
						}
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Skin:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 46)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Focus:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Shaman)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 87)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Shaman, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Regen:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(0, 1)) != -1)//HP Regen
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if ((((EQ_Spell *)pSpell)->SpellAffectBase(0) > 0) && (!IsSpellUsableForClass(pSpell, 1 << Beastlord)))
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffBySPA(0, 1, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Diseased:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(35, 0)) != -1)//Disease Counter
		{
			return true;
		}
		return false;
	case Poisoned:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(36, 0)) != -1)//Poison Counter
		{
			return true;
		}
		return false;
	case Cursed:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(116, 0)) != -1)//Curse Counter
		{
			return true;
		}
		return false;
	case Corrupted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(369, 0)) != -1)//Corruption Counter
		{
			return true;
		}
		return false;
	case Symbol:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 112)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Clarity:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(15, 1)) != -1)//Mana Regen
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if ((((EQ_Spell *)pSpell)->SpellAffectBase(15) > 0) && (IsSpellUsableForClass(pSpell, 1 << Enchanter)))
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffBySPA(15, 1, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Pred:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(95, 1 << Ranger)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 7)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(95, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Strength:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 47)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Brells:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Paladin)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 47)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Paladin, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case SV:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 59)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case SE:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 44)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(79, 1 << Beastlord, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case HybridHP:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 46)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Ranger, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Growth:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 141)
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(45, 1 << Druid, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Shining:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffByCategory(125, 1 << Cleric)) != -1)//
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (GetSpellSubcategory(pSpell) == 62)
					{
						if (((EQ_Spell *)pSpell)->SpellAffectBase(162))
						{
							return true;
						}
					}
				}
				if ((Dest.Int = GetTargetBuffByCategory(125, 1 << Cleric, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case Feared:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(23, 0)) != -1)//Feared
		{
			return true;
		}
		return false;
	case Silenced:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(96, 0)) != -1)//Silenced
		{
			return true;
		}
		return false;
	case Invulnerable:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(40, 0)) != -1)//Invulnerable
		{
			return true;
		}
		return false;
	case Dotted:
		Dest.Int = 0;
		Dest.Type = pTargetBuffType;
		if ((Dest.Int = GetTargetBuffBySPA(0, 0)) != -1)//HP Mod
		{
			int slotnum = Dest.Int;
			while (slotnum < NUM_BUFF_SLOTS)
			{
				if (PSPELL pSpell = GetSpellByID(((PCTARGETWND)pTargetWnd)->BuffSpellID[Dest.Int]))
				{
					if (((EQ_Spell *)pSpell)->IsDetrimentalSpell() && ((EQ_Spell *)pSpell)->IsDoTSpell())
					{
						return true;
					}
				}
				if ((Dest.Int = GetTargetBuffBySPA(0, 0, ++slotnum)) == -1)
				{
					break;
				}
			}
		}
		return false;
	case MaxMeleeTo:
		{
			Dest.Float = get_melee_range(pCharSpawn, pTarget);
			Dest.Type = pFloatType;
			return true;
		}
		break;

	}
	return false;
}
/*
else {
for(;pTaskmember;pTaskmember=pTaskmember->pNext) {
if(!_stricmp(pTaskmember->Name,GETFIRST())) {
strcpy_s(DataTypeTemp, pTaskmember->Name);
Dest.Ptr=&DataTypeTemp[0];
}
}
}
*/

bool MQ2TaskObjectiveType::GETMEMBER()
{
	int Elementindex = VarPtr.HighPart;
	if (Elementindex == -1)
		return false;
	CTaskManager*tm = ppTaskManager;
	if (!tm)
		return false;
	if (VarPtr.Int == -1)
		return false;
	int index = HIWORD(VarPtr.DWord);
	if (index == -1)
		return false;
	int type = LOWORD(VarPtr.DWord);
	PMQ2TYPEMEMBER pMember = MQ2TaskObjectiveType::FindMember(Member);
	if (!pMember)
		return false;

	PCTaskStatus*ts = 0;
	CTaskEntry * entry = 0;
	switch (type)
	{
	case TST_SoloQuest:
		ts = tm->GetTaskStatus((PcClient *)pPCData, index, TST_SoloQuest);
		entry = &tm->QuestEntries[index];
		break;
	case TST_SharedQuest:
		ts = tm->GetTaskStatus((PcClient *)pPCData, 0, TST_SharedQuest);
		entry = &tm->SharedTaskEntries[0];
		break;
	};
	CHAR szOut[MAX_STRING] = { 0 };
		switch ((TaskObjectiveTypeMembers)pMember->ID)
		{
		case Instruction:
		{
			tm->GetElementDescription(&entry->Elements[Elementindex], szOut);
			break;
		}
		case Status:
			if (ts->CurrentCounts[Elementindex]==entry->Elements[Elementindex].RequiredCount) {
				strcpy_s(szOut,"Done");
			}
			else {
				sprintf_s(szOut, "%d/%d", ts->CurrentCounts[Elementindex], entry->Elements[Elementindex].RequiredCount);
			}
			break;
		case Zone:
		{
			int zid = atoi(entry->Elements[Elementindex].TargetZoneID) & 0x7FFF;
			//int zid = tmpzid & 0x7FFF;
			if (zid == 0)
			{
				strcpy_s(szOut, "ALL");
			}
			else
			{
				if (zid < MAX_ZONES)
				{
					if (PZONELIST pZList = ((PWORLDDATA)pWorldData)->ZoneArray[zid])
					{
						Dest.Type = pZoneType;
						Dest.Ptr = pZList;
						return true;
					}
				}
			}
			break;
		}
		case xIndex:
			Dest.Int = Elementindex+1;
			Dest.Type = pIntType;
			return true;
		case Type:
		{
			switch (entry->Elements[Elementindex].Type)
			{
				case TT_Unknown:
					strcpy_s(DataTypeTemp, "Unknown");
					break;
				case TT_None:
					strcpy_s(DataTypeTemp, "None");
					break;
				case TT_Deliver:
					strcpy_s(DataTypeTemp, "Deliver");
					break;
				case TT_Kill:
					strcpy_s(DataTypeTemp, "Kill");
					break;
				case TT_Loot:
					strcpy_s(DataTypeTemp, "Loot");
					break;
				case TT_Hail:
					strcpy_s(DataTypeTemp, "Hail");
					break;
				case TT_Explore:
					strcpy_s(DataTypeTemp, "Explore");
					break;
				case TT_Tradeskill:
					strcpy_s(DataTypeTemp, "Tradeskill");
					break;
				case TT_Fishing:
					strcpy_s(DataTypeTemp, "Fishing");
					break;
				case TT_Foraging:
					strcpy_s(DataTypeTemp, "Foraging");
					break;
				case TT_Cast:
					strcpy_s(DataTypeTemp, "Cast");
					break;
				case TT_UseSkill:
					strcpy_s(DataTypeTemp, "UseSkill");
					break;
				case TT_DZSwitch:
					strcpy_s(DataTypeTemp, "DZSwitch");
					break;
				case TT_DestroyObject:
					strcpy_s(DataTypeTemp, "DestroyObject");
					break;
				case TT_Collect:
					strcpy_s(DataTypeTemp, "Collect");
					break;
				case TT_Dialogue:
					strcpy_s(DataTypeTemp, "Dialogue");
					break;
				default:
					strcpy_s(DataTypeTemp, "NULL");
					break;
			};
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		case CurrentCount:
			Dest.Int = ts->CurrentCounts[Elementindex];
			Dest.Type = pIntType;
			return true;
		case RequiredCount:
			Dest.Int = entry->Elements[Elementindex].RequiredCount;
			Dest.Type = pIntType;
			return true;
		case Optional:
			Dest.DWord = entry->Elements[Elementindex].bOptional;
			Dest.Type = pBoolType;
			return true;
		case RequiredItem:
		{
			GetCXStr(entry->Elements[Elementindex].ItemNameList, szOut);
			break;
		}
		case RequiredSkill:
		{
			GetCXStr(entry->Elements[Elementindex].SkillIDList, szOut);
			break;
		}
		case RequiredSpell:
		{
			GetCXStr(entry->Elements[Elementindex].SpellIDList, szOut);
			break;
		}
		case DZSwitchID:
			Dest.DWord = entry->Elements[Elementindex].DZSwitchID;
			Dest.Type = pIntType;
			return true;
		}
		if (szOut[0] != '\0') {
			strcpy_s(DataTypeTemp, szOut);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
	return false;
}
bool MQ2TaskMemberType::GETMEMBER()
{
	PTASKMEMBER pTaskMemberData = (PTASKMEMBER)VarPtr.Ptr;
	if (!pTaskMemberData)
		return false;
	DataTypeTemp[0] = '\0';
	PMQ2TYPEMEMBER pMember = MQ2TaskMemberType::FindMember(Member);
	if (!pMember)
	{
		return false;
	}

	switch ((TaskMemberTypeMembers)pMember->ID)
	{
	case Name:
		strcpy_s(DataTypeTemp, pTaskMemberData->Name);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	case Leader:
		Dest.Type = pBoolType;
		if (pTaskMemberData->IsLeader) {
			return true;
		}
		return false;
	case xIndex:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		PTASKMEMBER pTaskmember = pTaskMember;
		for (int i = 1; pTaskmember; pTaskmember = pTaskmember->pNext, i++) {
			if (!_stricmp(pTaskmember->Name, pTaskMemberData->Name)) {
				Dest.DWord = i;
				return true;
			}
		}
		return false;
	}
	return false;
}

bool MQ2TaskType::GETMEMBER()
{
	CTaskManager*tm = ppTaskManager;
	if (!tm)
		return false;
	if (!pTaskWnd)
		return false;
	int index = HIWORD(VarPtr.DWord);
	if (index == -1)
		return false;
	int type = LOWORD(VarPtr.DWord);
	PMQ2TYPEMEMBER pMethod = MQ2TaskType::FindMethod(Member);
	if (pMethod) {
		switch ((TaskMethods)pMethod->ID)
		{
			case Select:
			{
				Dest.DWord = 0;
				Dest.Type = pBoolType;
				CHAR szTask[MAX_STRING] = { 0 };
				switch (type)
				{
					case TST_SoloQuest:
						if (CTaskEntry *entry = &tm->QuestEntries[index])
						{
							strcpy_s(szTask, entry->TaskTitle);
						}
						break;
					case TST_SharedQuest:
						if (CTaskEntry *entry = &tm->SharedTaskEntries[0])
						{
							strcpy_s(szTask, entry->TaskTitle);
						}
						break;
				};
				if (szTask[0])
				{
					CHAR szOut[MAX_STRING] = { 0 };
					if (CListWnd *clist = (CListWnd *)pTaskWnd->GetChildItem("TASK_TaskList")) {
						CXStr str;
						for (int i = 0; i < clist->ItemsArray.Count; i++)
						{
							clist->GetItemText(&str, i, 2);
							GetCXStr(str.Ptr, szOut);
							if (!_stricmp(szTask, szOut))
							{
								if (SendListSelect2((CXWnd*)clist, i)) {
									Dest.DWord = 1;
								}
							}
						}
					}
					return true;
				}
			};
		}
		return false;
	}
	PMQ2TYPEMEMBER pMember = MQ2TaskType::FindMember(Member);
	if (!pMember)
		return false;
	PTASKMEMBER pTaskmember = (PTASKMEMBER)pTaskMember;
	switch ((TaskTypeMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)pTaskmember;
		Dest.Type = pIntType;
		return true;
	case Type:
	{
		Dest.Type = pStringType;
			switch (type)
			{
			case TST_SoloQuest:
				strcpy_s(DataTypeTemp, "Quest");
				Dest.Ptr = &DataTypeTemp[0];
				break;
			case TST_SharedQuest:
				strcpy_s(DataTypeTemp, "Shared");
				Dest.Ptr = &DataTypeTemp[0];
				break;
			default:
				strcpy_s(DataTypeTemp, "Unknown");
				Dest.Ptr = &DataTypeTemp[0];
				break;
			};
				return true;
			}
	case xIndex:
		Dest.Int = index+1;//hate this but the users are used to indexes starting at 1... so we got to continue that...
		Dest.Type = pIntType;
		return true;
	case WindowIndex:
	{
		CHAR szTask[MAX_STRING] = { 0 };
		switch (type)
		{
			case TST_SoloQuest:
				if (CTaskEntry *entry = &tm->QuestEntries[index])
				{
					strcpy_s(szTask, entry->TaskTitle);
			}
				break;
			case TST_SharedQuest:
				if (CTaskEntry *entry = &tm->SharedTaskEntries[0])
				{
					strcpy_s(szTask, entry->TaskTitle);
				}
				break;
		};
		CHAR szOut[MAX_STRING] = { 0 };
		if (CListWnd *clist = (CListWnd *)pTaskWnd->GetChildItem("TASK_TaskList")) {
			CXStr str;
			for (int i = 0; i < clist->ItemsArray.Count; i++)
			{
				clist->GetItemText(&str, i, 2);
				GetCXStr(str.Ptr, szOut);
				if (!_stricmp(szTask, szOut))
				{
					Dest.DWord = i+1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}
	case Leader:
	{
		strcpy_s(DataTypeTemp, "NULL");
		for (int i = 1; pTaskmember && i<7; pTaskmember = pTaskmember->pNext, i++) {
			if (pTaskmember->IsLeader) {
				strcpy_s(DataTypeTemp, pTaskmember->Name);
				break;
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case Title:
	{
		strcpy_s(DataTypeTemp, "NULL");
		switch (type)
		{
			case TST_SoloQuest:
				if (CTaskEntry *entry = &tm->QuestEntries[index])
				{
					strcpy_s(DataTypeTemp, entry->TaskTitle);
			}
				break;
			case TST_SharedQuest:
				if (CTaskEntry *entry = &tm->SharedTaskEntries[0])
				{
					strcpy_s(DataTypeTemp, entry->TaskTitle);
				}
				break;
		};
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;
	}
	case Timer:
	{
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
			PCTaskStatus*ts = 0;
			CTaskEntry * entry = 0;
			switch (type)
			{
			case TST_SoloQuest:
				ts = tm->GetTaskStatus((PcClient *)pPCData, index, TST_SoloQuest);
				entry = &tm->QuestEntries[index];
				break;
			case TST_SharedQuest:
				ts = tm->GetTaskStatus((PcClient *)pPCData, 0, TST_SharedQuest);
				entry = &tm->SharedTaskEntries[0];
				break;
			};
			if (ts && entry)
			{
				DWORD ft = GetFastTime();
				int timer = 0;
				if (((DWORD)ts->MovingStartTime + (DWORD)entry->DurationSeconds) > ft)
				{
					timer = (ts->MovingStartTime + entry->DurationSeconds) - ft;
				}
				Dest.UInt64 = timer * 1000;
					return true;
				}
				return false;
			}
	case xMember:
		Dest.Type = pTaskMemberType;
		if (!ISINDEX())
			return false;
		if (ISNUMBER())
		{
			for (int i = 1; pTaskmember && i<7; pTaskmember = pTaskmember->pNext, i++) {
				if (i == GETNUMBER()) {
					Dest.Ptr = pTaskmember;
					return true;
				}
			}
		}
		else {
			for (; pTaskmember; pTaskmember = pTaskmember->pNext) {
				if (!_stricmp(pTaskmember->Name, GETFIRST())) {
					Dest.Ptr = pTaskmember;
					return true;
				}
			}
		}
		return false;
	case Members:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		for (; pTaskmember && Dest.DWord<6; pTaskmember = pTaskmember->pNext, Dest.DWord++) {
		}
		return true;
		case ID:
	{
		Dest.Int = 0;
			Dest.Type = pIntType;
			CTaskEntry * entry = 0;
			switch (type)
			{
			case TST_SoloQuest:
				entry = &tm->QuestEntries[index];
				break;
			case TST_SharedQuest:
				entry = &tm->SharedTaskEntries[0];
				break;
			};
			if (entry)
			{
				Dest.Int = entry->TaskID;
			}
			return true;
		}
		case Objective:
		{
			Dest.Int = 0;
			Dest.Type = pTaskObjectiveType;
			PCTaskStatus*ts = 0;
			CTaskEntry * entry = 0;
			switch (type)
			{
			case TST_SoloQuest:
				ts = tm->GetTaskStatus((PcClient *)pPCData, index, TST_SoloQuest);
				entry = &tm->QuestEntries[index];
				break;
			case TST_SharedQuest:
				ts = tm->GetTaskStatus((PcClient *)pPCData, 0, TST_SharedQuest);
				entry = &tm->SharedTaskEntries[0];
				break;
			};
			if (ts && entry)
			{
			int stepindex = -1;
			if (ISNUMBER()) {
				stepindex = GETNUMBER();
				stepindex--;
				if (stepindex < 0) {
					stepindex = 0;
				}
					if (stepindex > 19) {
						stepindex = 19;
					}
			}
			else {
				CHAR szOut[MAX_STRING] = { 0 };
				CHAR szTemp[MAX_STRING] = { 0 };
				strcpy_s(szTemp, GETFIRST());
				_strlwr_s(szTemp);
					for (int i = 0; i < 20; i++) {
						tm->GetElementDescription(&entry->Elements[i], szOut);
					_strlwr_s(szOut);
					if (strstr(szOut, szTemp)) {
						stepindex = i;
						break;
					}
				}
			}
				Dest.DWord = (int)MAKELPARAM(type, index);
				Dest.HighPart = stepindex;
			return true;
		}
		return false;
	}
	case Step://gets the first step thats not Done in the task objective.
	{
		Dest.Int = 0;
		Dest.Type = pTaskObjectiveType;
			PCTaskStatus*ts = 0;
			CTaskEntry * entry = 0;
			switch (type)
			{
			case TST_SoloQuest:
				ts = tm->GetTaskStatus((PcClient *)pPCData, index, TST_SoloQuest);
				entry = &tm->QuestEntries[index];
				break;
			case TST_SharedQuest:
				ts = tm->GetTaskStatus((PcClient *)pPCData, 0, TST_SharedQuest);
				entry = &tm->SharedTaskEntries[0];
				break;
			};
			if (ts && entry)
			{
				int reqcount = 0;
				int currcount = 0;
				for (int i = 0; i < 20; i++)
				{
					reqcount = entry->Elements[i].RequiredCount;
					currcount = ts->CurrentCounts[i];
					if (currcount < reqcount && entry->Elements[i].bOptional==false)
					{
						Dest.DWord = (int)MAKELPARAM(type, index);
						Dest.HighPart = i;
					return true;
				}
			}
		}
		return false;
	}
	}
	return false;
}

bool MQ2XTargetType::GETMEMBER()
{
	if (!GetCharInfo() || !GetCharInfo()->pXTargetMgr || VarPtr.DWord > 23)
		return false;
	if (VarPtr.DWord > (DWORD)GetCharInfo()->pXTargetMgr->XTargetSlots.Count)
		return false;
	if (PMQ2TYPEMEMBER pMember = MQ2XTargetType::FindMember(Member))
	{
		//XTARGETDATA xtd = GetCharInfo()->pXTargetMgr->pXTargetArray->pXTargetData[VarPtr.DWord];
		XTARGETSLOT xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];
		switch ((xTargetMembers)pMember->ID)
		{
		case xAddress:
			Dest.DWord = (DWORD)GetCharInfo()->pXTargetMgr;
			Dest.Type = pIntType;
			return true;
		case TargetType:
			if (char *ptr = GetXtargetType(xts.xTargetType))
				strcpy_s(DataTypeTemp, ptr);
			else
				strcpy_s(DataTypeTemp, "UNKNOWN");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case ID:
			Dest.DWord = xts.SpawnID;
			Dest.Type = pIntType;
			return true;
		case Name:
			if(xts.Name[0]!='\0')
				strcpy_s(DataTypeTemp, xts.Name);
			else
				strcpy_s(DataTypeTemp, "NULL");
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case PctAggro:
			Dest.DWord = 0;
			Dest.Type = pIntType;
			if (pAggroInfo)
			{
				Dest.DWord = pAggroInfo->aggroData[AD_xTarget1 + VarPtr.DWord].AggroPct;
				return true;
			}
			return false;
		}
	}
	else {
		XTARGETSLOT xts = GetCharInfo()->pXTargetMgr->XTargetSlots[VarPtr.DWord];
		PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(xts.SpawnID);
		if (pSpawn) {
#ifndef ISXEQ
			return pSpawnType->GetMember(*(MQ2VARPTR*)&pSpawn, Member, Index, Dest);
#else
			return pSpawnType->GetMember(*(LSVARPTR*)&pSpawn, Member, argc, argv, Dest);
#endif
		}
	}
	return false;
};

bool MQ2KeyRingType::GETMEMBER()
{
	PMQ2TYPEMEMBER pMember = MQ2KeyRingType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((KeyRingTypeMembers)pMember->ID)
	{
	case xIndex:
	{
		DWORD n = LOWORD(VarPtr.DWord);
		Dest.DWord = n + 1;
		Dest.Type = pIntType;
		return true;
	}
	case Name:
		Dest.Type = pStringType;
		if (CXWnd *krwnd = FindMQ2Window(KeyRingWindowParent)) {
			CListWnd *clist = 0;
			DWORD n = LOWORD(VarPtr.DWord);
			DWORD type = HIWORD(VarPtr.DWord);
			if (type == 2)
				clist = (CListWnd *)krwnd->GetChildItem(FamiliarWindowList);
			else if (type == 1)
				clist = (CListWnd *)krwnd->GetChildItem(IllusionWindowList);
			else
				clist = (CListWnd *)krwnd->GetChildItem(MountWindowList);

			if (clist) {
				CXStr Str;
				clist->GetItemText(&Str, n, 2);
				CHAR szOut[MAX_STRING] = { 0 };
				GetCXStr(Str.Ptr, szOut, MAX_STRING);
				if (szOut[0] != '\0') {
					strcpy_s(DataTypeTemp, szOut);
					Dest.Ptr = &DataTypeTemp[0];
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
#if !defined(ROF2EMU) && !defined(UFEMU)
bool MQ2ItemFilterDataType::GETMEMBER()
{
	PItemFilterData pItem = (PItemFilterData)VarPtr.Ptr;
	if (!pItem)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2ItemFilterDataType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((ItemFilterDataMembers)pMember->ID)
	{
	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0]) {
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case ID:
		Dest.DWord = pItem->ID;
		Dest.Type = pIntType;
		return true;
	case AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			bool bAutoRoll = ( pItem->Types & ( 1<<0 ) ) != 0;
			Dest.DWord = bAutoRoll;
		}
		return true;
	case Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			bool bNeed = ( pItem->Types & ( 1<<1 ) ) != 0;
			Dest.DWord = bNeed;
		}
		return true;
	case Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			bool bGreed = ( pItem->Types & ( 1<<2 ) ) != 0;
			Dest.DWord = bGreed;
		}
		return true;
	case Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			bool bNever = ( pItem->Types & ( 1<<3 ) ) != 0;
			Dest.DWord = bNever;
		}
		return true;
	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem) {
			Dest.DWord = pItem->Icon;
			return true;
		}
		return false;
	case Types:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem) {
			Dest.DWord = pItem->Types;
			return true;
		}
		return false;
	}
	return false;
}
bool MQ2AdvLootItemType::GETMEMBER()
{
	PLOOTITEM pItem = (PLOOTITEM)VarPtr.Ptr;
	if (!pItem)
		return false;
	PMQ2TYPEMEMBER pMember = MQ2AdvLootItemType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((AdvLootItemMembers)pMember->ID)
	{
	case Address:
		Dest.DWord = (DWORD)pItem;
		Dest.Type = pIntType;
		return true;
	case xIndex:
		#ifdef ISXEQ
		Dest.DWord = VarPtr.HighDWord;
		#else
		Dest.DWord = VarPtr.HighPart;
		#endif
		Dest.Type = pIntType;
		return true;
	case Name:
		Dest.Type = pStringType;
		if (pItem && pItem->Name[0]) {
			strcpy_s(DataTypeTemp, pItem->Name);
			Dest.Ptr = &DataTypeTemp[0];
			return true;
		}
		return false;
	case ID:
		Dest.Int64 = pItem->ItemID;
		Dest.Type = pInt64Type;
		return true;
	case StackSize:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		EQArray<LOOTDETAILS>ploot = pItem->LootDetails;
		if (pItem && pItem->LootDetails.m_length && pItem->LootDetails.m_array[0].StackCount>=1) {
			Dest.DWord = pItem->LootDetails.m_array[0].StackCount;
		}
		return true;
	case Corpse:
		Dest.Type = pSpawnType;
		if (pItem && pItem->LootDetails.m_length) {
			if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(pItem->LootDetails.m_array[0].CorpseID)) {
				Dest.Ptr = pSpawn;
				return true;
			}
		}
		return false;
	case AutoRoll:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->AutoRoll;
		}
		return true;
	case Need:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->Need;
		}
		return true;
	case Greed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->Greed;
		}
		return true;
	case No:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->No;
		}
		return true;
	case AlwaysNeed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->AlwaysNeed;
		}
		return true;
	case AlwaysGreed:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->AlwaysGreed;
		}
		return true;
	case Never:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->Never;
		}
		return true;
	case IconID:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pItem) {
			Dest.DWord = pItem->IconID;
			return true;
		}
		return false;
	case xNoDrop:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pItem) {
			Dest.DWord = pItem->NoDrop;
		}
		return true;
	}
	return false;
}
bool MQ2AdvLootType::GETMEMBER()
{
	PEQADVLOOTWND pAdvLoot = (PEQADVLOOTWND)pAdvancedLootWnd;
	if (!pAdvLoot)
		return FALSE;
	PMQ2TYPEMEMBER pMember = MQ2AdvLootType::FindMember(Member);
	if (!pMember)
		return false;
	switch ((AdvLootTypeMembers)pMember->ID)
	{
	case PCount:
		Dest.Int = pAdvLoot->pPLootList->ListSize;
		Dest.Type = pIntType;
		return true;
	case PList:
		Dest.Type = pAdvLootItemType;
		if (LONG index = atoi(GETFIRST())) {
			index--;
			if(index < 0)
				index = 0;
			if (CListWnd *clist = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_PLLList")) {
				int listindex = (int)clist->GetItemData(index);
				if (pAdvLoot->pPLootList && listindex!=-1) {
					DWORD addr = (DWORD)pAdvLoot->pPLootList->pLootItem;
					PLOOTITEM pitem = (PLOOTITEM)(addr + (sizeof(LOOTITEM)*listindex));
					Dest.Ptr = pitem;
					#ifdef ISXEQ
					Dest.HighDWord = listindex;
					#else
					Dest.HighPart = listindex;
					#endif
					return true;
				}
			}
		}
		return false;
	case SCount:
		Dest.Int = pAdvLoot->pCLootList->ListSize;
		Dest.Type = pIntType;
		return true;
	case SList:
		Dest.Type = pAdvLootItemType;
		if (LONG index = atoi(GETFIRST())) {
			index--;
			if(index < 0)
				index = 0;
			if (CListWnd *clist = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_CLLList")) {
				int listindex = (int)clist->GetItemData(index);
				if (pAdvLoot->pCLootList && listindex!=-1) {
					DWORD addr = (DWORD)pAdvLoot->pCLootList->pLootItem;
					PLOOTITEM pitem = (PLOOTITEM)(addr + (sizeof(LOOTITEM)*listindex));
					Dest.Ptr = pitem;
					#ifdef ISXEQ
					Dest.HighDWord = listindex;
					#else
					Dest.HighPart = listindex;
					#endif
					return true;
				}
			}
		}
		return false;
	case PWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (CListWnd *clist = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_PLLList")) {
			for (LONG i = 0; i < clist->ItemsArray.Count; i++) {
				int listindex = (int)clist->GetItemData(i);
				if (pAdvLoot->pPLootList && listindex != -1) {
					DWORD addr = (DWORD)pAdvLoot->pPLootList->pLootItem;
					if (PLOOTITEM pitem = (PLOOTITEM)(addr + (sizeof(LOOTITEM)*listindex))) {
						if (pitem->AlwaysNeed || pitem->AlwaysGreed || pitem->Need || pitem->Greed) {
							Dest.DWord++;
						}
					}
				}
			}
		}
		return true;
	case SWantCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (CListWnd *clist = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_CLLList")) {
			for (LONG i = 0; i < clist->ItemsArray.Count; i++) {
				int listindex = (int)clist->GetItemData(i);
				if (pAdvLoot->pCLootList && listindex != -1) {
					DWORD addr = (DWORD)pAdvLoot->pCLootList->pLootItem;
					if (PLOOTITEM pitem = (PLOOTITEM)(addr + (sizeof(LOOTITEM)*listindex))) {
						if (pitem->AlwaysNeed || pitem->AlwaysGreed || pitem->Need || pitem->Greed) {
							Dest.DWord++;
						}
					}
				}
			}
		}
		return true;
	case xLootInProgress:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (CListWnd *pPersonalList = (CListWnd *)pAdvancedLootWnd->GetChildItem("ADLW_PLLList")) {
			CListWnd *pSharedList = 0;
			if (pAdvLoot->pCLootList) {
				pSharedList = (CListWnd *)pAdvLoot->pCLootList->SharedLootList;
				Dest.DWord = LootInProgress(pAdvLoot, pPersonalList, pSharedList);
			}
		}
		return true;
	case Filter:
		Dest.Type = pItemFilterDataType;
		if (pLootFiltersManager) {
			if (int id = GETNUMBER()) {
				if (const PItemFilterData pifd = pLootFiltersManager->GetItemFilterData(id)) {
					Dest.Ptr = pifd;
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
#endif
// /echo ${Alert[a].List[b].bGM}
// /echo ${Alert[a].Size}
// /echo ${Alert}
bool MQ2AlertType::GETMEMBER()
{
	try {
		if (!CAlerts.AlertExist(VarPtr.DWord))
			return false;
		PMQ2TYPEMEMBER pMember = MQ2AlertType::FindMember(Member);
		if (!pMember)
			return false;
		switch ((AlertTypeMembers)pMember->ID)
		{
		case List:
		{
			if (ISNUMBER()) {
				Dest.DWord = MAKELONG(VarPtr.DWord, GETNUMBER());
				Dest.Type = pAlertListType;
				return true;
			}
			break;
		}
		case Size:
		{
			Dest.DWord = 0;
			Dest.Type = pIntType;
			std::list<SEARCHSPAWN>ss;
			if (CAlerts.GetAlert(VarPtr.DWord, ss)) {
				Dest.DWord = ss.size();
			}
			return true;
		}
		}
	}
	catch (...) {
		//todo: add some error handling here to explain whats going on
		MessageBox(NULL, "CRAP! in Alert", "An exception occured", MB_OK);
		//anyway at least we wont crash eqgame for the user...
		Sleep(0);
	}
	return false;
}

bool MQ2AlertListType::GETMEMBER()
{
	try {
		DWORD theindex = LOWORD(VarPtr.DWord);
		DWORD theitem = HIWORD(VarPtr.DWord);
		PMQ2TYPEMEMBER pMember = MQ2AlertListType::FindMember(Member);
		if (!pMember)
			return false;

		std::list<SEARCHSPAWN>ss;
		if (CAlerts.GetAlert(theindex, ss)) {
			auto si = ss.begin();
			if (ss.size()>theitem) {
				std::advance(si, theitem);

				switch ((AlertListTypeMembers)pMember->ID)
				{
				case MinLevel:
					Dest.DWord = (*si).MinLevel;
					Dest.Type = pIntType;
					return true;
				case MaxLevel:
					Dest.DWord = (*si).MaxLevel;
					Dest.Type = pIntType;
					return true;
				case SpawnType:
					Dest.DWord = (*si).SpawnType;
					Dest.Type = pIntType;
					return true;
				case SpawnID:
					Dest.DWord = (*si).SpawnID;
					Dest.Type = pIntType;
					return true;
				case FromSpawnID:
					Dest.DWord = (*si).FromSpawnID;
					Dest.Type = pIntType;
					return true;
				case Radius:
					Dest.Float = (*si).Radius;
					Dest.Type = pFloatType;
					return true;
				case Name:
					Dest.Type = pStringType;
					strcpy_s(DataTypeTemp, (*si).szName);
					if (DataTypeTemp[0]) {
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
					return false;
				case BodyType:
					Dest.Type = pStringType;
					strcpy_s(DataTypeTemp, (*si).szBodyType);
					if (DataTypeTemp[0]) {
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
					return false;
				case Race:
					Dest.Type = pStringType;
					strcpy_s(DataTypeTemp, (*si).szRace);
					if (DataTypeTemp[0]) {
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
					return false;
				case Class:
					Dest.Type = pStringType;
					strcpy_s(DataTypeTemp, (*si).szClass);
					if (DataTypeTemp[0]) {
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
					return false;
				case Light:
					Dest.Type = pStringType;
					strcpy_s(DataTypeTemp, (*si).szLight);
					if (DataTypeTemp[0]) {
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
					return false;
				case GuildID:
					Dest.UInt64 = (*si).GuildID;
					Dest.Type = pInt64Type;
					return true;
				case bSpawnID:
					Dest.DWord = (*si).bSpawnID;
					Dest.Type = pBoolType;
					return true;
				case bNotNearAlert:
					Dest.DWord = (*si).bNotNearAlert;
					Dest.Type = pBoolType;
					return true;
				case bNearAlert:
					Dest.DWord = (*si).bNearAlert;
					Dest.Type = pBoolType;
					return true;
				case bNoAlert:
					Dest.DWord = (*si).bNoAlert;
					Dest.Type = pBoolType;
					return true;
				case bAlert:
					Dest.DWord = (*si).bAlert;
					Dest.Type = pBoolType;
					return true;
				case bLFG:
					Dest.DWord = (*si).bLFG;
					Dest.Type = pBoolType;
					return true;
				case bTrader:
					Dest.DWord = (*si).bTrader;
					Dest.Type = pBoolType;
					return true;
				case bLight:
					Dest.DWord = (*si).bLight;
					Dest.Type = pBoolType;
					return true;
				case bTargNext:
					Dest.DWord = (*si).bTargNext;
					Dest.Type = pBoolType;
					return true;
				case bTargPrev:
					Dest.DWord = (*si).bTargPrev;
					Dest.Type = pBoolType;
					return true;
				case bGroup:
					Dest.DWord = (*si).bGroup;
					Dest.Type = pBoolType;
					return true;
				case bFellowship:
					Dest.DWord = (*si).bFellowship;
					Dest.Type = pBoolType;
					return true;
				case bNoGroup:
					Dest.DWord = (*si).bNoGroup;
					Dest.Type = pBoolType;
					return true;
				case bRaid:
					Dest.DWord = (*si).bRaid;
					Dest.Type = pBoolType;
					return true;
				case bGM:
					Dest.DWord = (*si).bGM;
					Dest.Type = pBoolType;
					return true;
				case bNamed:
					Dest.DWord = (*si).bNamed;
					Dest.Type = pBoolType;
					return true;
				case bMerchant:
					Dest.DWord = (*si).bMerchant;
					Dest.Type = pBoolType;
					return true;
				case bBanker:
					Dest.DWord = (*si).bBanker;
					Dest.Type = pBoolType;
					return true;
				case bTributeMaster:
					Dest.DWord = (*si).bTributeMaster;
					Dest.Type = pBoolType;
					return true;
				case bKnight:
					Dest.DWord = (*si).bKnight;
					Dest.Type = pBoolType;
					return true;
				case bTank:
					Dest.DWord = (*si).bTank;
					Dest.Type = pBoolType;
					return true;
				case bHealer:
					Dest.DWord = (*si).bHealer;
					Dest.Type = pBoolType;
					return true;
				case bDps:
					Dest.DWord = (*si).bDps;
					Dest.Type = pBoolType;
					return true;
				case bSlower:
					Dest.DWord = (*si).bSlower;
					Dest.Type = pBoolType;
					return true;
				case bAura:
					Dest.DWord = (*si).bAura;
					Dest.Type = pBoolType;
					return true;
				case bBanner:
					Dest.DWord = (*si).bBanner;
					Dest.Type = pBoolType;
					return true;
				case bCampfire:
					Dest.DWord = (*si).bCampfire;
					Dest.Type = pBoolType;
					return true;
				case NotID:
					Dest.DWord = (*si).NotID;
					Dest.Type = pIntType;
					return true;
				case NotNearAlertList:
					Dest.DWord = (*si).NotNearAlertList;
					Dest.Type = pIntType;
					return true;
				case NearAlertList:
					Dest.DWord = (*si).NearAlertList;
					Dest.Type = pIntType;
					return true;
				case NoAlertList:
					Dest.DWord = (*si).NoAlertList;
					Dest.Type = pIntType;
					return true;
				case AlertList:
					Dest.DWord = (*si).AlertList;
					Dest.Type = pIntType;
					return true;
#ifndef ISXEQ
				case ZRadius:
					Dest.Double = (*si).ZRadius;
					Dest.Type = pDoubleType;
					return true;
				case FRadius:
					Dest.Double = (*si).FRadius;
					Dest.Type = pDoubleType;
					return true;
#else
				case ZRadius:
					Dest.Float = (float)(*si).ZRadius;
					Dest.Type = pFloatType;
					return true;
				case FRadius:
					Dest.Float = (float)(*si).FRadius;
					Dest.Type = pFloatType;
					return true;
#endif
				case xLoc:
					Dest.Float = (*si).xLoc;
					Dest.Type = pFloatType;
					return true;
				case yLoc:
					Dest.Float = (*si).yLoc;
					Dest.Type = pFloatType;
					return true;
				case bKnownLocation:
					Dest.DWord = (*si).bKnownLocation;
					Dest.Type = pBoolType;
					return true;
				case bNoPet:
					Dest.DWord = (*si).bNoPet;
					Dest.Type = pBoolType;
					return true;
				case SortBy:
					Dest.DWord = (*si).SortBy;
					Dest.Type = pIntType;
					return true;
				case bNoGuild:
					Dest.DWord = (*si).bNoGuild;
					Dest.Type = pBoolType;
					return true;
				case bLoS:
					Dest.DWord = (*si).bLoS;
					Dest.Type = pBoolType;
					return true;
				case bExactName:
					Dest.DWord = (*si).bExactName;
					Dest.Type = pBoolType;
					return true;
				case bTargetable:
					Dest.DWord = (*si).bTargetable;
					Dest.Type = pBoolType;
					return true;
				case PlayerState:
					Dest.DWord = (*si).PlayerState;
					Dest.Type = pIntType;
					return true;
				case Spawn:
					Dest.Type = pSpawnType;
					if (DWORD spawnid = (*si).SpawnID) {
//					DWORD spawnid = (*si).SpawnID;
//					if (spawnid) {
						if (PSPAWNINFO psp = (PSPAWNINFO)GetSpawnByID(spawnid)) {
							Dest.Ptr = psp;
							return true;
						}
					}
					if ((*si).szName[0]) {
						if (PSPAWNINFO psp = (PSPAWNINFO)GetSpawnByName((*si).szName)) {
							Dest.Ptr = psp;
							return true;
						}
					}
					return false;
				case bSeeInvis:
					Dest.DWord = (*si).bSeeInvis;
					Dest.Type = pBoolType;
					return true;
				case bSeeSOS:
					Dest.DWord = (*si).bSeeSOS;
					Dest.Type = pBoolType;
					return true;
				case bSeeIVU:
					Dest.DWord = (*si).bSeeIVU;
					Dest.Type = pBoolType;
					return true;
				}
			}
		}
	}
	catch (...) {
		MessageBox(NULL, "CRAP! in AlertType", "An exception occured", MB_OK);
	}
	return false;
}

bool MQ2WorldLocationType::GETMEMBER()
{
	try {
		DWORD index = VarPtr.DWord;
		PMQ2TYPEMEMBER pMember = MQ2WorldLocationType::FindMember(Member);
		if (!pMember)
			return false;
		PCHARINFO2 pChar2 = GetCharInfo2();
		if (!pChar2)
			return false;

		switch ((WorldLocationTypeMembers)pMember->ID)
		{
			case ID:
			{
				int zindex = pChar2->BoundLocations[index].ZoneBoundID;
				Dest.DWord = zindex;
				Dest.Type = pIntType;
				return true;
			}
			case Zone:
			{
				Dest.Type = pZoneType;
				int zindex = pChar2->BoundLocations[index].ZoneBoundID & 0x7FFF;
				if (zindex < MAX_ZONES)
				{
					Dest.Ptr = ((PWORLDDATA)pWorldData)->ZoneArray[zindex];
				}
				if (!Dest.Ptr)
					return false;
				return true;
			}
			case Y:
				Dest.Float = pChar2->BoundLocations[index].ZoneBoundY;
				Dest.Type = pFloatType;
				return true;
			case X:
				Dest.Float = pChar2->BoundLocations[index].ZoneBoundX;
				Dest.Type = pFloatType;
				return true;
			case Z:
				Dest.Float = pChar2->BoundLocations[index].ZoneBoundZ;
				Dest.Type = pFloatType;
				return true;
			case Heading:
				Dest.Float = pChar2->BoundLocations[index].ZoneBoundHeading;
				Dest.Type = pFloatType;
				return true;
			default:
				return false;
		};
	}
	catch (...) {
		MessageBox(NULL, "CRAP! in MQ2WorldLocationType", "An exception occured", MB_OK);
	}
	return false;
}

bool MQ2SolventType::GETMEMBER()
{
	try {
		DWORD itemid = VarPtr.DWord;
		if (itemid == -1)
			itemid = 52023;
		PMQ2TYPEMEMBER pMember = MQ2SolventType::FindMember(Member);
		if (!pMember)
			return false;
		switch ((SolventTypeMembers)pMember->ID)
		{
			case Name:
				strcpy_s(DataTypeTemp, GetAugmentNameByID(itemid));
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case ID:
				Dest.DWord = itemid;
				Dest.Type = pIntType;
				return true;
			case Item://do we have this solvent?
				Dest.Type = pItemType;
				if (PCONTENTS pItem = FindItemByID(itemid))
				{
					Dest.Ptr = pItem;
					return true;
				}
				return false;
			case Count://do we have this solvent and if so how many?
				Dest.DWord = 0;
				Dest.Type = pIntType;
				if (PCONTENTS pCont= FindItemByID(itemid))
				{
					if (PITEMINFO pItem = GetItemFromContents(pCont))
					{
						Dest.DWord = FindItemCountByName(pItem->Name);
					}
				}
				return true;
			default:
				return false;
		};
	}
	catch (...) {
		MessageBox(NULL, "CRAP! in SolventType", "An exception occured", MB_OK);
	}
	return false;
}
bool MQ2AugType::GETMEMBER()
{
	try {
		DWORD index = VarPtr.DWord;
		PCONTENTS pCont = (PCONTENTS)VarPtr.HighPart;
		if (!pCont)
			return false;
		PITEMINFO pItem = GetItemFromContents(pCont);
		if (!pItem)
			return false;

		PMQ2TYPEMEMBER pMember = MQ2AugType::FindMember(Member);
		if (!pMember)
			return false;
		switch ((AugTypeMembers)pMember->ID)
		{
			case Slot:
				Dest.DWord = index+1;
				Dest.Type = pIntType;
				return true;
			case Type:
				Dest.DWord = pItem->AugData.Sockets[index].Type;
				Dest.Type = pIntType;
				return true;
			case Visible:
				Dest.DWord = pItem->AugData.Sockets[index].bVisible;
				Dest.Type = pBoolType;
				return true;
			case Infusable:
				Dest.DWord = pItem->AugData.Sockets[index].bInfusible;
				Dest.Type = pBoolType;
				return true;
			case Empty:
				Dest.DWord = true;
				Dest.Type = pBoolType;
				if (PCONTENTS pCret = pCont->GetContent(index)) {
					Dest.DWord = false;
				}
				return true;
			case Name:
				Dest.Type = pStringType;
				if (PCONTENTS pCret = pCont->GetContent(index)) {
					if (PITEMINFO pAug = GetItemFromContents(pCret)) {
						strcpy_s(DataTypeTemp, pAug->Name);
						Dest.Ptr = DataTypeTemp;
						return true;
					}
				}
				return false;
			case Item:
				Dest.Type = pItemType;
				if (PCONTENTS pCret = pCont->GetContent(index)) {
					Dest.Ptr = pCret;
					return true;
				}
				return false;
#if !defined(UFEMU)//todo: check manually for uf
			case Solvent:
				Dest.DWord = 0;
				Dest.Type = pSolventType;
				if (PCONTENTS pCret = pCont->GetContent(index)) {
					if (PITEMINFO ptheAug = GetItemFromContents(pCret)) {
						Dest.DWord = ptheAug->SolventItemID;
						return true;
					}
				}
				return false;
#endif
			default:
				return false;
		};
	}
	catch (...) {
		MessageBox(NULL, "CRAP! in AugType", "An exception occured", MB_OK);
	}
	return false;
}
bool MQ2RangeType::GETMEMBER()
{
	int P1, P2, P3;
	PMQ2TYPEMEMBER pMember = MQ2RangeType::FindMember(Member);
	if (!pMember)
		return false;
	if (!ISINDEX())
		return false;
	switch ((RangeMembers)pMember->ID) {
	case Inside:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		P1 = 0;
		P2 = 0;
		P3 = 0;
		if (ISINDEX()) {
			if (PCHAR pColon = strchr(GETFIRST(), ':')) {
				*pColon = 0;
				P3 = atoi(&pColon[1]);
				if (PCHAR pComma = strchr(GETFIRST(), ',')) {
					*pComma = 0;
					P2 = atoi(&pComma[1]);
					P1 = atoi(GETFIRST());
					//WriteChatf("Range.Inside(%d,%d:%d)",P1,P2,P3);
					if (P3>P1 && P3<P2) {
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;
	case Between:
		Dest.DWord = false;
		Dest.Type = pBoolType;
		P1 = 0;
		P2 = 0;
		P3 = 0;
		if (ISINDEX()) {
			if (PCHAR pColon = strchr(GETFIRST(), ':')) {
				*pColon = 0;
				P3 = atoi(&pColon[1]);
				if (PCHAR pComma = strchr(GETFIRST(), ',')) {
					*pComma = 0;
					P2 = atoi(&pComma[1]);
					P1 = atoi(GETFIRST());
					//WriteChatf("Range.Between(%d,%d:%d)",P1,P2,P3);
					if (P3 >= P1 && P3 <= P2) {
						Dest.DWord = true;
						return true;
					}
				}
			}
		}
		return true;
	}
	return false;
}

bool MQ2AuraType::GETMEMBER()
{
	try {
		int index = VarPtr.HighPart;
		PAURAINFO pAura = (PAURAINFO)VarPtr.Ptr;
		if (!pAura)
			return false;

		PMQ2TYPEMEMBER pMember = MQ2AuraType::FindMember(Member);
		if (pMember) {
			switch ((AuraTypeMembers)pMember->ID)
			{
			case ID:
				Dest.DWord = index + 1;
				Dest.Type = pIntType;
				return true;
			case Find:
			{
				Dest.DWord = 0;
				Dest.Type = pIntType;
				if (!ISINDEX())
					return false;
				char A[MAX_STRING] = { 0 };
				char B[MAX_STRING] = { 0 };
				strcpy_s(A, (char*)pAura->Name);
				strcpy_s(B, (char*)Index);
				_strlwr_s(A);
				_strlwr_s(B);
				if (char *pFound = strstr(A, B))
				{
					Dest.DWord = (pFound - &A[0]) + 1;
					return true;
				}
				return false;
			}
			case Name:
				strcpy_s(DataTypeTemp, pAura->Name);
				Dest.Ptr = DataTypeTemp;
				Dest.Type = pStringType;
				return true;
			case SpawnID:
				Dest.DWord = pAura->SpawnID;
				Dest.Type = pIntType;
				return true;
			default:
				return false;
			};
		}

		PMQ2TYPEMEMBER pMethod = MQ2AuraType::FindMethod(Member);
		if (pMethod) {
			switch ((AuraTypeMethods)pMethod->ID)
			{
				case Remove:
				if (!pAuraWnd)
					break;
				if (CListWnd*clist = (CListWnd*)pAuraWnd->GetChildItem("AuraList")) {
					if (index > clist->ItemsArray.Count)
						break;
					clist->SetCurSel(index);
					((CXWnd*)pAuraWnd)->WndNotification((CXWnd*)clist, XWM_MENUSELECT, (PVOID)1);
					return true;
				}
				break;
			}
			return false;
		}
	}
	catch (...) {
		MessageBox(NULL, "CRAP! in AuraType", "An exception occured", MB_OK);
	}
	return false;
}
#if !defined(UFEMU)
bool MQ2BandolierItemType::GETMEMBER()
{
	if (BandolierItemInfo *ptr = (BandolierItemInfo *)VarPtr.Ptr)
	{
		PMQ2TYPEMEMBER pMember = MQ2BandolierItemType::FindMember(Member);
		if (pMember) {
			switch ((BandolierItemTypeMembers)pMember->ID)
			{
				case xIndex:
					Dest.DWord = VarPtr.HighPart;
					Dest.Type = pIntType;
					return true;
				case IconID:
					Dest.DWord = ptr->IconID;
					Dest.Type = pIntType;
					return true;
				case ID:
					Dest.DWord = ptr->ItemID;
					Dest.Type = pIntType;
					return true;
				case Name:
					strcpy_s(DataTypeTemp, ptr->Name);
					Dest.Ptr = &DataTypeTemp[0];
					Dest.Type = pStringType;
					return true;
				default:
					return false;
			};
		}
	}
	return false;
}
bool MQ2BandolierType::GETMEMBER()
{
	try {
		if (PCHARINFO2 pChar2 = GetCharInfo2())
		{
			int index = VarPtr.DWord;
			if (index < 0)
				index = 0;
			if (index > 19)
				index = 19;
			if (BandolierSet *pBand = &pChar2->Bandolier[index])
			{
				if (!pBand->Name[0])
					return false;

				PMQ2TYPEMEMBER pMember = MQ2BandolierType::FindMember(Member);
				if (pMember) {
					switch ((BandolierTypeMembers)pMember->ID)
					{
					case Active:
						Dest.DWord = 0;
						Dest.Type = pBoolType;
						if (pChar2->pInventoryArray)
						{
							if (pBand->Items[0].ItemID)
							{
								if (pChar2->pInventoryArray->Inventory.Primary)
								{
									if (pChar2->pInventoryArray->Inventory.Primary->ID != pBand->Items[0].ItemID)
									{
										return true;
									}
								}
								else {
									return true;
								}
							}
							else if (pChar2->pInventoryArray->Inventory.Primary)
							{
								return true;
							}
							if (pBand->Items[1].ItemID)
							{
								if (pChar2->pInventoryArray->Inventory.Secondary)
								{
									if (pChar2->pInventoryArray->Inventory.Secondary->ID != pBand->Items[1].ItemID)
									{
										return true;
									}
								}
								else {
									return true;
								}
							}
							else if (pChar2->pInventoryArray->Inventory.Secondary)
							{
								return true;
							}
							if (pBand->Items[2].ItemID)
							{
								if (pChar2->pInventoryArray->Inventory.Range)
								{
									if (pChar2->pInventoryArray->Inventory.Range->ID != pBand->Items[2].ItemID)
									{
										return true;
									}
								}
								else {
									return true;
								}
							}
							else if (pChar2->pInventoryArray->Inventory.Range)
							{
								return true;
							}
							if (pBand->Items[3].ItemID)
							{
								if (pChar2->pInventoryArray->Inventory.Ammo)
								{
									if (pChar2->pInventoryArray->Inventory.Ammo->ID != pBand->Items[3].ItemID)
									{
										return true;
									}
								}
								else
								{
									return true;
								}
							}
							else if (pChar2->pInventoryArray->Inventory.Ammo)
							{
								return true;
							}
							Dest.DWord = 1;
						}
						return true;
					case xIndex:
						Dest.DWord = index + 1;
						Dest.Type = pIntType;
						return true;
					case Item:
					{
						Dest.Type = pBandolierItemType;
						if (!ISINDEX())
							return false;
						int index = GETNUMBER();
						index--;
						if (index < 0)
							index = 0;
						if (index > 3)
							index = 3;
						Dest.HighPart = index;
						Dest.Ptr = (PVOID)&pBand->Items[index];
						return true;
					}
					case Name:
						strcpy_s(DataTypeTemp, pBand->Name);
						Dest.Ptr = DataTypeTemp;
						Dest.Type = pStringType;
						return true;
					default:
						return false;
					};
				}

				PMQ2TYPEMEMBER pMethod = MQ2BandolierType::FindMethod(Member);
				if (pMethod) {
					switch ((BandolierTypeMethods)pMethod->ID)
					{
					case Activate:
						((PcZoneClient*)pPCData)->BandolierSwap(index);
						if (CBandolierWnd *pWnd = pBandolierWnd)
						{
							if (pWnd->pWeaponSetList)
							{
								pWnd->pWeaponSetList->SetCurSel(index);
							}
						}
						Dest.DWord = 1;
						Dest.Type = pBoolType;
						return true;
					}
					return false;
				}
			}
		}
	}
	catch (...) {
		MessageBox(NULL, "CRAP! in MQ2BandolierType", "An exception occured", MB_OK);
	}
	return false;
}
#endif
