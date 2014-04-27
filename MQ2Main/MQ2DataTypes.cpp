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


#ifndef ISXEQ
class MQ2FloatType *pFloatType=0;
class MQ2IntType *pIntType=0;
class MQ2ByteType *pByteType=0;
class MQ2BoolType *pBoolType=0;
class MQ2StringType *pStringType=0;
class MQ2MathType *pMathType=0;
class MQ2TimeType *pTimeType=0;
class MQ2ArrayType *pArrayType=0;
#endif
class MQ2SpawnType *pSpawnType=0;
class MQ2BuffType *pBuffType=0;
class MQ2SpellType *pSpellType=0;
class MQ2TicksType *pTicksType=0;
class MQ2CharacterType *pCharacterType=0;
class MQ2ClassType *pClassType=0;
class MQ2RaceType *pRaceType=0;
class MQ2BodyType *pBodyType=0;
class MQ2SkillType *pSkillType=0;
class MQ2AltAbilityType *pAltAbilityType=0;
class MQ2GroundType *pGroundType=0;
class MQ2SwitchType *pSwitchType=0;
class MQ2CorpseType *pCorpseType=0;
class MQ2MacroType *pMacroType=0;
class MQ2MacroQuestType *pMacroQuestType=0;
class MQ2WindowType *pWindowType=0;
class MQ2MerchantType *pMerchantType=0;
class MQ2ZoneType *pZoneType=0;
class MQ2CurrentZoneType *pCurrentZoneType=0;
class MQ2ItemType *pItemType=0;
class MQ2DeityType *pDeityType=0;
class MQ2ArgbType *pArgbType=0;
class MQ2TypeType *pTypeType=0;
class MQ2HeadingType *pHeadingType=0;
class MQ2InvSlotType *pInvSlotType=0;
class MQ2TimerType *pTimerType=0;
class MQ2PluginType *pPluginType=0;
class MQ2RaidType *pRaidType=0;
class MQ2RaidMemberType *pRaidMemberType=0;
class MQ2GroupType *pGroupType=0;
class MQ2GroupMemberType *pGroupMemberType=0;
class MQ2EvolvingItemType *pEvolvingItemType=0;
class MQ2DynamicZoneType *pDynamicZoneType=0;
class MQ2DZMemberType *pDZMemberType=0;
class MQ2FellowshipType *pFellowshipType=0;
class MQ2FellowshipMemberType *pFellowshipMemberType=0;
class MQ2FriendsType *pFriendsType=0;
class MQ2TargetType *pTargetType=0;
class MQ2XTargetType *pXTargetType=0;

#ifndef ISXEQ

void InitializeMQ2DataTypes()
{    
    pFloatType = new MQ2FloatType;
    pIntType = new MQ2IntType;
    pByteType = new MQ2ByteType;
    pStringType = new MQ2StringType;
    pSpawnType = new MQ2SpawnType;
    pSpellType = new MQ2SpellType;
    pBuffType = new MQ2BuffType;
    pTicksType = new MQ2TicksType;
    pCharacterType = new MQ2CharacterType;
    pClassType=new MQ2ClassType;
    pRaceType=new MQ2RaceType;
    pGroundType = new MQ2GroundType;
    pSwitchType = new MQ2SwitchType;
    pMacroType = new MQ2MacroType;
    pMacroQuestType = new MQ2MacroQuestType;
    pMathType = new MQ2MathType;
    pWindowType = new MQ2WindowType;
    pMerchantType = new MQ2MerchantType;
    pZoneType = new MQ2ZoneType;
    pItemType = new MQ2ItemType;
    pBoolType = new MQ2BoolType;
    pBodyType = new MQ2BodyType;
    pDeityType = new MQ2DeityType;
    pArgbType = new MQ2ArgbType;
    pCorpseType = new MQ2CorpseType;
    pCurrentZoneType = new MQ2CurrentZoneType;
    pTypeType = new MQ2TypeType;
    pTimeType = new MQ2TimeType;
    pHeadingType = new MQ2HeadingType;
    pInvSlotType = new MQ2InvSlotType;
    pArrayType = new MQ2ArrayType;
    pTimerType = new MQ2TimerType;
    pPluginType = new MQ2PluginType;
    pSkillType = new MQ2SkillType;
    pAltAbilityType = new MQ2AltAbilityType;
    pRaidType = new MQ2RaidType;
    pRaidMemberType = new MQ2RaidMemberType;
    pGroupType = new MQ2GroupType;
    pGroupMemberType = new MQ2GroupMemberType;
    pGroupMemberType->SetInheritance(pSpawnType);
    pEvolvingItemType=new MQ2EvolvingItemType;
    pDynamicZoneType=new MQ2DynamicZoneType;
    pDZMemberType=new MQ2DZMemberType;
    pFellowshipType=new MQ2FellowshipType;
    pFellowshipMemberType=new MQ2FellowshipMemberType;
    pFriendsType = new MQ2FriendsType;
    pTargetType = new MQ2TargetType;
    pXTargetType = new MQ2XTargetType;

    // NOTE: SetInheritance does NOT make it inherit, just notifies the syntax checker...
    pCharacterType->SetInheritance(pSpawnType);
    pBuffType->SetInheritance(pSpellType);
    //pCurrentZoneType->SetInheritance(pZoneType);
    pRaidMemberType->SetInheritance(pSpawnType);
    pTargetType->SetInheritance(pSpawnType);
}

void ShutdownMQ2DataTypes()
{
    delete pSpawnType;
    delete pFloatType;
    delete pIntType;
    delete pByteType;
    delete pStringType;
    delete pBuffType;
    delete pSpellType;
    delete pTicksType;
    delete pCharacterType;
    delete pClassType;
    delete pRaceType;
    delete pGroundType;
    delete pSwitchType;
    delete pMacroType;
    delete pMacroQuestType;
    delete pMathType;
    delete pWindowType;
    delete pMerchantType;
    delete pZoneType;
    delete pItemType;
    delete pBoolType;
    delete pBodyType;
    delete pDeityType;
    delete pArgbType;
    delete pCorpseType;
    delete pCurrentZoneType;
    delete pTypeType;
    delete pTimeType;
    delete pHeadingType;
    delete pArrayType;
    delete pTimerType;
    delete pPluginType;
    delete pSkillType;
    delete pAltAbilityType;
    delete pRaidType;
    delete pRaidMemberType;
    delete pGroupType;
    delete pGroupMemberType;
    delete pEvolvingItemType;
    delete pDynamicZoneType;
    delete pFriendsType;
    delete pTargetType;
    delete pXTargetType;
}

bool MQ2TypeType::GETMEMBER()
{
#define pType ((MQ2Type*)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2TypeType::FindMember(Member);
    if (!pMember)
        return false;
    switch((TypeMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=pType->GetName();
        Dest.Type=pStringType;
        return true;
    case TypeMember:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                // name by number
                if (Dest.Ptr=pType->GetMemberName(GETNUMBER()))
                {
                    Dest.Type=pStringType;
                    return true;
                }
            }
            else
            {
                // number by name
                if (pType->GetMemberID(Index,Dest.DWord))
                {
                    Dest.Type=pIntType;
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
    PMQ2TYPEMEMBER pMember=MQ2PluginType::FindMember(Member);
    if (!pMember)
        return false;
    switch((PluginMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=pPlugin->szFilename;
        Dest.Type=pStringType;
        return true;
    case Version:
        Dest.Float=pPlugin->fpVersion;
        Dest.Type=pFloatType;
        return true;
    }
    return false;
#undef pPlugin
}
bool MQ2FloatType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2FloatType::FindMember(Member);
    if (!pMember)
    {
        return false;
    }

    switch((FloatMembers)pMember->ID)
    {
    case Deci:
        sprintf(DataTypeTemp,"%.1f",VarPtr.Float);
        Dest.Type=pStringType;
        Dest.Ptr=&DataTypeTemp[0];
        return true;
    case Centi:
        sprintf(DataTypeTemp,"%.2f",VarPtr.Float);
        Dest.Type=pStringType;
        Dest.Ptr=&DataTypeTemp[0];
        return true;
    case Milli:
        sprintf(DataTypeTemp,"%.3f",VarPtr.Float);
        Dest.Type=pStringType;
        Dest.Ptr=&DataTypeTemp[0];
        return true;
    case Int:
        Dest.Type=pIntType;
        Dest.Int=(int)(VarPtr.Float);
        return true;
    case Precision:
        if (ISNUMBER())
        {
            sprintf(DataTypeTemp,"%.*f",GETNUMBER(),VarPtr.Float);
            Dest.Type=pStringType;
            Dest.Ptr=&DataTypeTemp[0];
            return true;
        }
        return false;
    }
    return false;
}

bool MQ2IntType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2IntType::FindMember(Member);
    if (!pMember)
    {
        return false;
    }

    switch((IntMembers)pMember->ID)
    {
    case Float:
        Dest.Float=(FLOAT)1.0f*(VarPtr.Int);
        Dest.Type=pFloatType;
        return true;
    case Hex:
        sprintf(DataTypeTemp,"%x",VarPtr.Int);
        Dest.Ptr=&DataTypeTemp[0],
            Dest.Type=pStringType;
        return true;
    case Reverse:
        {
            Dest.Array[0]=VarPtr.Array[3];
            Dest.Array[1]=VarPtr.Array[2];
            Dest.Array[2]=VarPtr.Array[1];
            Dest.Array[3]=VarPtr.Array[0];
            Dest.Type=pIntType;
        }
        return true;
    }
    return false;
}
bool MQ2StringType::GETMEMBER()
{
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2StringType::FindMember(Member);
    if (!pMember)
    {
        return false;
    }

    switch((StringMembers)pMember->ID)
    {
    case Length:
        Dest.DWord=strlen((const char *)VarPtr.Ptr);
        Dest.Type=pIntType;
        return true;
    case Left:
        if (!ISINDEX())
            return false;
        {
            int Len=GETNUMBER();
            if (Len==0)
                return false;
            if (Len>0)
            {
                unsigned long StrLen=strlen((char *)VarPtr.Ptr);
                if ((unsigned long)Len>StrLen)
                    Len=StrLen;
                memmove(DataTypeTemp,(char *)VarPtr.Ptr,Len);
                DataTypeTemp[Len]=0;
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
            }
            else
            {
                Len=-Len;
                unsigned long StrLen=strlen((char *)VarPtr.Ptr);
                if ((unsigned long)Len>=StrLen)
                {
                    Dest.Ptr="";
                    Dest.Type=pStringType;
                    return true;
                }
                memmove(DataTypeTemp,(char *)VarPtr.Ptr,StrLen-Len);
                DataTypeTemp[StrLen-Len]=0;
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
            }
        }
        return true;
    case Right:
        if (!ISINDEX())
            return false;
        {    
            int Len=GETNUMBER();
            if (Len==0)
                return false;
            if (Len<0)
            {
                Len=-Len;
                unsigned long StrLen=strlen((char *)VarPtr.Ptr);
                if ((unsigned long)Len>=StrLen)
                {
                    Dest.Ptr="";
                    Dest.Type=pStringType;
                    return true;
                }
                char *pStart=(char*)VarPtr.Ptr;
                pStart=&pStart[Len];
                Len=StrLen-Len;
                memmove(DataTypeTemp,pStart,Len+1);
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
            }
            else
            {
                char *pStart=(char*)VarPtr.Ptr;
                pStart=&pStart[strlen(pStart)-Len];
                if (pStart<VarPtr.Ptr)
                    pStart=(char*)VarPtr.Ptr;
                memmove(DataTypeTemp,pStart,Len+1);
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
            }
        }
        return true;
    case Find:
        if (!ISINDEX())
            return false;
        {
            char A[MAX_STRING]={0};
            char B[MAX_STRING]={0};
            strcpy(A,(char*)VarPtr.Ptr);
            strcpy(B,(char*)Index);
            strlwr(A);
            strlwr(B);
            if (char *pFound=strstr(A,B))
            {
                Dest.DWord=(pFound-&A[0])+1;
                Dest.Type=pIntType;
                return true;
            }
        }
        return false;
    case Replace:
        if (!ISINDEX())
            return false;
        {
            char A[MAX_STRING]={0};
            char B[MAX_STRING]={0};
            char C[MAX_STRING]={0};
            char *pos;
            if (!ISINDEX()) 
                return false; 
            if (PCHAR pComma=strchr(Index,',')) 
            { 
                strcpy(A,(char*)VarPtr.Ptr);
                *pComma=0; 
                strcpy(B,(char*)Index);
                *pComma=','; 
                strcpy(C,(char*)&pComma[1]);
                if (!A || !B || !C)
                    return false;
                while( ( pos = strstr( A , B ) ) != NULL )  /* if -> while */ 
                { 
                    DataTypeTemp[0] = '\0' ; 
                    strncat( DataTypeTemp , A , pos - A ) ; 
                    strcat( DataTypeTemp , C ) ; 
                    strcat( DataTypeTemp , pos + strlen( B ) ) ; 
                    strcpy( A, DataTypeTemp); /* added */
                }
                if (Dest.Ptr = DataTypeTemp)
                {
                    Dest.Type = pStringType;
                    return true;
                }
            }
        }
    case Upper:
        strcpy(DataTypeTemp,(char*)VarPtr.Ptr);
        strupr(DataTypeTemp);
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case Lower:
        strcpy(DataTypeTemp,(char*)VarPtr.Ptr);
        strlwr(DataTypeTemp);
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case Compare:
        if (ISINDEX())
        {
            Dest.Int=stricmp((char*)VarPtr.Ptr,Index);
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case CompareCS:
        if (ISINDEX())
        {
            Dest.Int=strcmp((char*)VarPtr.Ptr,Index);
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case Mid:
        {
            if (PCHAR pComma=strchr(Index,','))
            {
                *pComma=0;
                pComma++;
                PCHAR pStr=(char *)VarPtr.Ptr;
                unsigned long nStart=GETNUMBER()-1;
                unsigned long Len=atoi(pComma);
                if (nStart>=strlen(pStr))
                {
                    Dest.Ptr="";
                    Dest.Type=pStringType;
                    return true;
                }
                pStr+=nStart;
                unsigned long StrLen=strlen(pStr);
                if (Len>StrLen)
                    Len=StrLen;
                memmove(DataTypeTemp,pStr,Len);
                DataTypeTemp[Len]=0;
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
                return true;
            }
        }
        return false;
    case Equal:
        if (ISINDEX())
        {
            Dest.DWord=(stricmp((char*)VarPtr.Ptr,Index)==0);
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case NotEqual:
        if (ISINDEX())
        {
            Dest.DWord=(stricmp((char*)VarPtr.Ptr,Index)!=0);
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case EqualCS:
        if (ISINDEX())
        {
            Dest.DWord=(strcmp((char*)VarPtr.Ptr,Index)==0);
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case NotEqualCS:
        if (ISINDEX())
        {
            Dest.DWord=(strcmp((char*)VarPtr.Ptr,Index)!=0);
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case Count:
        if (ISINDEX())
        {
            Dest.DWord=0;
            PCHAR pLast=(PCHAR)VarPtr.Ptr-1;
            while(pLast=strchr(&pLast[1],Index[0]))
                Dest.DWord++;
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case Arg:
        if (IsNumberToComma(Index))
        {
            CHAR Temp[MAX_STRING]={0};
            strcpy(Temp,(char *)VarPtr.Ptr);
            if (PCHAR pComma=strchr(Index,','))
            {
                *pComma=0;
                GetArg(DataTypeTemp,Temp,GETNUMBER(),FALSE,FALSE,FALSE,pComma[1]);
                *pComma=',';
                if (DataTypeTemp[0])
                {
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
                    return true;
                }
            }
            else
            {
                GetArg(DataTypeTemp,Temp,GETNUMBER());
                if (DataTypeTemp[0])
                {
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
                    return true;
                }
            }
        }
        return false;
    case Token:
        if (IsNumberToComma(Index))
        {
            DWORD N=GETNUMBER();
            if (!N)
                return false;
            //CHAR Temp[MAX_STRING]={0};
            //strcpy(Temp,(char *)VarPtr.Ptr);
            if (PCHAR pComma=strchr(Index,','))
            {
                *pComma=0;
                PCHAR pPos=(PCHAR)VarPtr.Ptr;//strchr((char *)VarPtr.Ptr,pComma[1]);
                N--;
                while(N && pPos)
                {
                    pPos=strchr(&pPos[1],pComma[1]);
                    N--;
                }
                *pComma=',';
                if (pPos)
                {
                    if (pPos!=(PCHAR)VarPtr.Ptr)
                        pPos++;
                    PCHAR pEnd=strchr(&pPos[0],pComma[1]);
                    if (pEnd)
                    {
                        if (pEnd!=pPos)
                        {
                            strncpy(DataTypeTemp,pPos,pEnd-pPos);
                            DataTypeTemp[pEnd-pPos]=0;
                        }
                        else
                            DataTypeTemp[0]=0;
                    }
                    else
                        strcpy(DataTypeTemp,pPos);
                    // allows empty returned strings
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
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
    PMQ2TYPEMEMBER pMember=MQ2ArrayType::FindMember(Member);
    if (!pMember)
        return false;
    switch((ArrayMembers)pMember->ID)
    {
    case Dimensions:
        Dest.DWord=pArray->nExtents;
        Dest.Type=pIntType;
        return true;
    case Size:
        if (ISINDEX())
        {
            DWORD N=GETNUMBER()-1;
            if (N<pArray->nExtents)
            {
                Dest.DWord=pArray->pExtents[N];
                Dest.Type=pIntType;
                return true;
            }
        }
        else
        {
            Dest.DWord=pArray->TotalElements;
            Dest.Type=pIntType;
            return true;
        }
        return false;
    }
    return false;
#undef pArray
}
bool MQ2MathType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2MathType::FindMember(Member);
    if (!pMember)
        return false;

    if (!ISINDEX())
        return false;
    DOUBLE CalcResult;
    switch((MathMembers)pMember->ID)
    {
    case Abs:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(FLOAT)CalcResult;
            if (Dest.Float<0)
                Dest.Float*=-1;
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Rand:
        Dest.DWord=atol(Index);
        if (Dest.DWord==0 || Dest.DWord==0xFFFFFFFF)
            return false;
        Dest.DWord=rand() % Dest.DWord;
        Dest.Type=pIntType;
        return true;
    case Sqrt:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(FLOAT)sqrt(CalcResult);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Calc:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(FLOAT)CalcResult;
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Sin:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(float)sin(CalcResult/DegToRad);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Cos:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(float)cos(CalcResult/DegToRad);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Tan:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(float)tan(CalcResult/DegToRad);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Asin:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(float)(asin(CalcResult)*DegToRad);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Acos:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(float)(acos(CalcResult)*DegToRad);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Atan:
        if (Calculate(Index,CalcResult))
        {
            Dest.Float=(float)(atan(CalcResult)*DegToRad);
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Not:
        Dest.DWord=~atol(Index);
        Dest.Type=pIntType;
        return true;
    case Hex:
        sprintf(DataTypeTemp,"%x",atol(Index));
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case Dec:
        sscanf(Index,"%x",&Dest.DWord);
        Dest.Type=pIntType;
        return true;
    case Distance:
        if (ISINDEX())
        {
            FLOAT P1[3];
            FLOAT P2[3];
            P1[0]=P2[0]=((PSPAWNINFO)pCharSpawn)->Y;
            P1[1]=P2[1]=((PSPAWNINFO)pCharSpawn)->X;
            P1[2]=P2[2]=((PSPAWNINFO)pCharSpawn)->Z;
            if (PCHAR pColon=strchr(Index,':'))
            {
                *pColon=0;
                if (PCHAR pComma=strchr(&pColon[1],','))
                {
                    *pComma=0;
                    P2[0]=(FLOAT)atof(&pColon[1]);
                    *pComma=',';
                    if (PCHAR pComma2=strchr(&pComma[1],','))
                    {
                        *pComma2=0;
                        P2[1]=(FLOAT)atof(&pComma[1]);
                        *pComma2=',';
                        P2[2]=(FLOAT)atof(&pComma2[1]);
                    }
                    else
                    {
                        P2[1]=(FLOAT)atof(&pComma[1]);
                    }
                }
                else
                    P2[0]=(FLOAT)atof(&pColon[1]);
            }


            if (PCHAR pComma=strchr(Index,','))
            {
                *pComma=0;
                P1[0]=(FLOAT)atof(Index);
                *pComma=',';
                if (PCHAR pComma2=strchr(&pComma[1],','))
                {
                    *pComma2=0;
                    P1[1]=(FLOAT)atof(&pComma[1]);
                    *pComma2=',';
                    P1[2]=(FLOAT)atof(&pComma2[1]);
                }
                else
                {
                    P1[1]=(FLOAT)atof(&pComma[1]);
                }
            }
            else
                P1[0]=(FLOAT)atof(Index);

            DebugSpew("GetDistance3D(%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f)",P1[0],P1[1],P1[2],P2[0],P2[1],P2[2]);
            Dest.Float=(FLOAT)GetDistance3D(P1[0],P1[1],P1[2],P2[0],P2[1],P2[2]);
            Dest.Type=pFloatType;
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
    PMQ2TYPEMEMBER pMember=MQ2MacroType::FindMember(Member);
    if (!pMember)
        return false;
    switch((MacroMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=&gszMacroName[0];
        Dest.Type=pStringType;
        return true;
    case RunTime:
        Dest.DWord=(DWORD)((GetTickCount()-gRunning)/1000);
        Dest.Type=pIntType;
        return true;
    case Paused:
        Dest.DWord=gMacroPause;
        Dest.Type=pBoolType;
        return true;
    case Return:
        Dest.Ptr=&DataTypeTemp[0];
        strcpy(DataTypeTemp,gMacroStack->Return);
        Dest.Type=pStringType;
        return true;
    case Params:
        Dest.DWord=0;
        {
            PDATAVAR pVar=gMacroStack->Parameters;
            while(pVar)
            {
                Dest.DWord++;
                pVar=pVar->pNext;
            }
        }
        Dest.Type=pIntType;
        return true;
        /*
        TypeMember(Param);
        /**/
    }
    return false;
}

#endif

bool MQ2TicksType::GETMEMBER()
{
#define nTicks (VarPtr.DWord)
    unsigned long N=MemberMap[Member];
    if (!N)
        return false;
    N--;
    PMQ2TYPEMEMBER pMember=Members[N];
    if (!pMember)
        return false;
    switch((TicksMembers)pMember->ID)
    {
    case Hours:
        Dest.DWord=nTicks/600;
        Dest.Type=pIntType;
        return true;
    case Minutes:
        Dest.DWord=(nTicks/10)%60;
        Dest.Type=pIntType;
        return true;
    case Seconds:
        Dest.DWord=(nTicks*6)%60;
        Dest.Type=pIntType;
        return true;
    case TimeHMS:
        {
            int Secs=nTicks*6;
            int Mins=(Secs/60)%60;
            int Hrs=(Secs/3600);
            Secs=Secs%60;
            if (Secs<0)
                sprintf(DataTypeTemp,"Perm");
            else if (Hrs)
                sprintf(DataTypeTemp,"%d:%02d:%02d",Hrs,Mins,Secs);
            else
                sprintf(DataTypeTemp,"%d:%02d",Mins,Secs);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
        }
        return true;
    case Time:
        {
            int Secs=nTicks*6;
            int Mins=(Secs/60);
            Secs=Secs%60;
            if (Secs<0)
                sprintf(DataTypeTemp,"Perm");
            else
                sprintf(DataTypeTemp,"%d:%02d",Mins,Secs);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
        }
        return true;
    case TotalMinutes:
        Dest.DWord=nTicks/10;
        Dest.Type=pIntType;
        return true;
    case TotalSeconds:
        Dest.DWord=nTicks*6;
        Dest.Type=pIntType;
        return true;
    case Ticks:
        Dest.DWord=nTicks;
        Dest.Type=pIntType;
        return true;
    }        
    return false;
#undef nTicks
}

bool MQ2ArgbType::GETMEMBER()
{
    unsigned long N=MemberMap[Member];
    if (!N)
        return false;
    N--;
    PMQ2TYPEMEMBER pMember=Members[N];
    if (!pMember)
        return false;
    switch((ArgbMembers)pMember->ID)
    {
    case A:
        Dest.DWord=VarPtr.Argb.A;
        Dest.Type=pIntType;
        return true;
    case R:
        Dest.DWord=VarPtr.Argb.R;
        Dest.Type=pIntType;
        return true;
    case G:
        Dest.DWord=VarPtr.Argb.G;
        Dest.Type=pIntType;
        return true;
    case B:
        Dest.DWord=VarPtr.Argb.B;
        Dest.Type=pIntType;
        return true;
    case Int:
        Dest.DWord=VarPtr.DWord;
        Dest.Type=pIntType;
        return true;
    }
    return false;
}

bool MQ2SpawnType::GETMEMBER()
{
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2SpawnType::FindMember(Member);
    if (!pMember)
    {
        return false;
    }
    PSPAWNINFO pSpawn=(PSPAWNINFO)VarPtr.Ptr;
    switch((SpawnMembers)pMember->ID)
    {
    case Level:
        Dest.DWord=pSpawn->Level;
        Dest.Type=pIntType;
        return true;
    case ID:
        Dest.Type=pIntPtrType;
        INTPTR(pSpawn->SpawnID);
        return true;
    case Name:
        Dest.Type=pStringType;
        Dest.Ptr=&pSpawn->Name[0];
        return true;
    case Surname:
        Dest.Type=pStringType;
        Dest.Ptr=&pSpawn->Lastname[0];
        return true;
    case CleanName:
        strcpy(DataTypeTemp,pSpawn->Name);
        CleanupName(DataTypeTemp,FALSE,FALSE);
        Dest.Type=pStringType;
        Dest.Ptr=&DataTypeTemp[0];
        return true;
    case DisplayName:
        Dest.Ptr=&pSpawn->DisplayedName[0];
        Dest.Type=pStringType;
        return true;
    case E:
        Dest.Type=pFloatType;
        Dest.Float=-pSpawn->X;
        return true;
    case W:
    case X:
        Dest.Type=pFloatPtrType;
        FLOATPTR(pSpawn->X); 
        return true;
    case S:
        Dest.Type=pFloatType;
        Dest.Float=-pSpawn->Y;
        return true;
    case N:
    case Y:
        Dest.Type=pFloatPtrType;
        FLOATPTR(pSpawn->Y); 
        return true;
    case D:
        Dest.Type=pFloatType;
        Dest.Float=-pSpawn->Z;
        return true;
    case U:
    case Z:
        Dest.Type=pFloatPtrType;
        FLOATPTR(pSpawn->Z);
        return true;
    case Next:
        if (Dest.Ptr=pSpawn->pNext)
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case Prev:
        if (Dest.Ptr=pSpawn->pPrev)
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case CurrentHPs:
        Dest.Type=pIntType;
        Dest.Int=pSpawn->HPCurrent;
        return true;
    case MaxHPs:
        Dest.Type=pIntType;
        Dest.Int=pSpawn->HPMax;
        return true;
    case PctHPs:
        Dest.Type=pIntType;
        Dest.Int=pSpawn->HPCurrent*100/pSpawn->HPMax;
        return true;
    case AARank:
        if (pSpawn->AARank!=0xFF)
            Dest.Int=pSpawn->AARank;
        else
            Dest.Int=0;
        Dest.Type=pIntType;
        return true;
    case Speed:
        Dest.Float=FindSpeed(pSpawn);
        Dest.Type=pFloatType;
        return true;
    case Heading:
        Dest.Float=pSpawn->Heading*0.703125f;
        Dest.Type=pHeadingType;
        return true;
    case Pet:
        if (Dest.Ptr=GetSpawnByID(pSpawn->PetID))
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case Master:
        if (Dest.Ptr=GetSpawnByID(pSpawn->MasterID))
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case Gender:
        Dest.Ptr=szGender[pSpawn->Gender];
        Dest.Type=pStringType;
        return true;
    case Race:
        Dest.DWord=pSpawn->Race;
        Dest.Type=pRaceType;
        return true;
    case Class:
        if (GetSpawnType(pSpawn)!=AURA && GetSpawnType(pSpawn)!=BANNER && GetSpawnType(pSpawn)!=CAMPFIRE)
            Dest.DWord=pSpawn->Class;
        else
            if (GetSpawnType(pSpawn)==AURA)
                Dest.DWord=0xFF;
            else if (GetSpawnType(pSpawn)==BANNER)
                Dest.DWord=0xFE;
            else
                Dest.DWord=0xFD;
            Dest.Type=pClassType;
            return true;
    case Body:
        Dest.DWord=GetBodyType(pSpawn);
        Dest.Type=pBodyType;
        return true;
    case GM:
        Dest.DWord=pSpawn->GM;
        Dest.Type=pBoolType;
        return true;
    case Levitating:
        Dest.DWord=(pSpawn->Levitate==2);
        Dest.Type=pBoolType;
        return true;
    case Sneaking:
        Dest.DWord=pSpawn->Sneak;
        Dest.Type=pBoolType;
        return true;
    case Invis:
        Dest.DWord=pSpawn->HideMode;
        Dest.Type=pBoolType;
        return true;
    case Height:
        Dest.Float=pSpawn->AvatarHeight;
        Dest.Type=pFloatType;
        return true;
    case MaxRange:
        if (GetSpawnType(pSpawn)!=ITEM)
        {
            Dest.Float=get_melee_range((EQPlayer*)pSpawn,(EQPlayer*)pSpawn); 
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case MaxRangeTo:
        if (GetSpawnType(pSpawn)!=ITEM)
        {
            Dest.Float=get_melee_range(pLocalPlayer,(EQPlayer*)pSpawn); 
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Guild:
        if (pSpawn->GuildID != 0xFFFFFFFF)
        {
            if(char *szGuild = GetGuildByID(pSpawn->GuildID))
            {
                Dest.Ptr=szGuild;
                Dest.Type=pStringType;
                return true;
            }
        }
        return false;
    case GuildStatus:
        if (pSpawn->GuildID != 0xFFFFFFFF)
        {
            Dest.Ptr=szGuildStatus[pSpawn->GuildStatus];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case Type:
        switch(GetSpawnType(pSpawn))
        {
        case MOUNT:
            Dest.Ptr="Mount";
            Dest.Type=pStringType;
            return true;
        case UNTARGETABLE:
            Dest.Ptr="Untargetable";
            Dest.Type=pStringType;
            return true;
        case NPC:
            Dest.Ptr="NPC";
            Dest.Type=pStringType;
            return true;
        case PC:
            Dest.Ptr="PC";
            Dest.Type=pStringType;
            return true;
        case CHEST:
            Dest.Ptr="Chest";
            Dest.Type=pStringType;
            return true;
        case TRAP:
            Dest.Ptr="Trap";
            Dest.Type=pStringType;
            return true;
        case TRIGGER:
            Dest.Ptr="Trigger";
            Dest.Type=pStringType;
            return true;
        case TIMER:
            Dest.Ptr="Timer";
            Dest.Type=pStringType;
            return true;
        case PET:
            Dest.Ptr="Pet";
            Dest.Type=pStringType;
            return true;
        case ITEM:
            Dest.Ptr="Item";
            Dest.Type=pStringType;
            return true;
        case CORPSE:
            Dest.Ptr="Corpse";
            Dest.Type=pStringType;
            return true;
        case AURA:
            Dest.Ptr="Aura";
            Dest.Type=pStringType;
            return true;
        case OBJECT:
            Dest.Ptr="Object";
            Dest.Type=pStringType;
            return true;
        case BANNER:
            Dest.Ptr="Banner";
            Dest.Type=pStringType;
            return true;
        case CAMPFIRE:
            Dest.Ptr="Campfire";
            Dest.Type=pStringType;
            return true;
        case MERCENARY:
            Dest.Ptr="Mercenary";
            Dest.Type=pStringType;
            return true;
        case FLYER:
            Dest.Ptr="Flyer";
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case Light:
        Dest.Ptr=GetLightForSpawn(pSpawn);
        Dest.Type=pStringType;
        return true;
    case StandState:
        Dest.Int=pSpawn->StandState;
        Dest.Type=pIntType;
        return true;
    case State:
        if (GetCharInfo() && GetCharInfo()->Stunned==1)
        {
            Dest.Ptr="STUN";
        }
        else if(pSpawn == (PSPAWNINFO)pLocalPlayer && pSpawn->RespawnTimer)
        {
            Dest.Ptr="HOVER";
        }
        else if(pSpawn->Mount)
        {
            Dest.Ptr="MOUNT";
        }
        else
            switch (pSpawn->StandState)
        {
            case STANDSTATE_STAND:
                Dest.Ptr="STAND";
                break;
            case STANDSTATE_SIT:
                Dest.Ptr="SIT";
                break;
            case STANDSTATE_DUCK:
                Dest.Ptr="DUCK";
                break;
            case STANDSTATE_BIND:
                Dest.Ptr="BIND";
                break;
            case STANDSTATE_FEIGN:
                Dest.Ptr="FEIGN";
                break;
            case STANDSTATE_DEAD:
                Dest.Ptr="DEAD";
                break;
            default:
                Dest.Ptr="UNKNOWN";
                break;
        }
        Dest.Type=pStringType;
        return true;
    case Standing:
        Dest.DWord=pSpawn->StandState==STANDSTATE_STAND;
        Dest.Type=pBoolType;
        return true;
    case Sitting:
        Dest.DWord=pSpawn->StandState==STANDSTATE_SIT;
        Dest.Type=pBoolType;
        return true;
    case Ducking:
        Dest.DWord=pSpawn->StandState==STANDSTATE_DUCK;
        Dest.Type=pBoolType;
        return true;
    case Feigning:
        Dest.DWord=pSpawn->StandState==STANDSTATE_FEIGN;
        Dest.Type=pBoolType;
        return true;
    case Binding:
        Dest.DWord=pSpawn->StandState==STANDSTATE_BIND;
        Dest.Type=pBoolType;
        return true;
    case Dead:
        Dest.DWord=pSpawn->StandState==STANDSTATE_DEAD;
        Dest.Type=pBoolType;
        return true;
    case Stunned:
        Dest.DWord=(GetCharInfo() && GetCharInfo()->Stunned==1);
        Dest.Type=pBoolType;
        return true;
    case Hovering:
        Dest.DWord=(pSpawn->RespawnTimer);
        Dest.Type=pBoolType;
        return true;
    case Deity:
        Dest.DWord=pSpawn->Deity;
        Dest.Type=pDeityType;
        return true;
    case Distance:
        Dest.Float=GetDistance(pSpawn->X,pSpawn->Y);
        Dest.Type=pFloatType;
        return true;
    case Distance3D:
        Dest.Float=DistanceToSpawn3D((PSPAWNINFO)pCharSpawn,pSpawn);
        Dest.Type=pFloatType;
        return true;
    case DistancePredict:
        Dest.Float=EstimatedDistanceToSpawn((PSPAWNINFO)pCharSpawn,pSpawn);
        Dest.Type=pFloatType;
        return true;
    case DistanceW:
    case DistanceX:
        Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->X-pSpawn->X);
        Dest.Type=pFloatType;
        return true;
    case DistanceN:
    case DistanceY:
        Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Y-pSpawn->Y);
        Dest.Type=pFloatType;
        return true;
    case DistanceU:
    case DistanceZ:
        Dest.Float=(FLOAT)fabs(((PSPAWNINFO)pCharSpawn)->Z-pSpawn->Z);
        Dest.Type=pFloatType;
        return true;
    case HeadingTo:
        Dest.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pSpawn->Y, pSpawn->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Dest.Float<0.0f) 
            Dest.Float += 360.0f;
        else if (Dest.Float>=360.0f) 
            Dest.Float -= 360.0f;
        Dest.Type=pHeadingType;
        return true;
    case Casting:
        if (Dest.Ptr=GetSpellByID(pSpawn->CastingData.SpellID))
        {
            Dest.Type=pSpellType;
            return true;
        }
        return false;
    case Mount:
        if (Dest.Ptr=pSpawn->Mount)
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case Underwater:
        Dest.DWord=(pSpawn->UnderWater==5);
        Dest.Type=pBoolType;
        return true;
    case FeetWet:
        Dest.DWord=(pSpawn->FeetWet==5);
        Dest.Type=pBoolType;
        return true;
    case Animation:
        Dest.DWord=pSpawn->Animation;
        Dest.Type=pIntType;
        return true;
    case Holding:
        Dest.DWord=pSpawn->Holding;
        Dest.Type=pIntType;
        return true;
    case Look:
        Dest.Float=pSpawn->CameraAngle;
        Dest.Type=pFloatType;
        return true;
    case xConColor:
        switch(ConColor(pSpawn))
        {
        case CONCOLOR_GREY:
            Dest.Ptr="GREY";
            break;
        case CONCOLOR_GREEN:
            Dest.Ptr="GREEN";
            break;
        case CONCOLOR_LIGHTBLUE:
            Dest.Ptr="LIGHT BLUE";
            break;
        case CONCOLOR_BLUE:
            Dest.Ptr="BLUE";
            break;
        case CONCOLOR_WHITE:
            Dest.Ptr="WHITE";
            break;
        case CONCOLOR_YELLOW:
            Dest.Ptr="YELLOW";
            break;
        case CONCOLOR_RED:
        default:
            Dest.Ptr="RED";
            break;
        }
        Dest.Type=pStringType;
        return true;
    case Invited:
        Dest.DWord=(pSpawn->InvitedToGroup);
        Dest.Type=pBoolType;
        return true;
#ifndef ISXEQ
    case NearestSpawn:
        if (pSpawn==(PSPAWNINFO)pCharSpawn)
        {
            return (dataNearestSpawn(Index,Dest)!=0);// use top-level object if it's you
        }
        if (ISINDEX())
        {
            PCHAR pSearch;
            unsigned long nth;
            SEARCHSPAWN ssSpawn;
            ClearSearchSpawn(&ssSpawn);
            ssSpawn.FRadius=999999.0f;
            if (pSearch=strchr(Index,','))
            {
                *pSearch=0;
                ++pSearch;
                ParseSearchSpawn(pSearch,&ssSpawn);
                nth=GETNUMBER();
            }
            else
            {
                if (ISNUMBER())
                {
                    nth=GETNUMBER();
                }
                else
                {
                    nth=1;
                    ParseSearchSpawn(Index,&ssSpawn);
                }
            }
            if (Dest.Ptr=NthNearestSpawn(&ssSpawn,nth,pSpawn))
            {
                Dest.Type=pSpawnType;
                return true;
            }
        }
        return false;
#else
    case NearestSpawn:
        if (pSpawn==(PSPAWNINFO)pCharSpawn)
        {
            return (dataNearestSpawn(argc,argv,Dest)!=0);// use top-level object if it's you
        }
        if (argc)
        {
            unsigned long nth;
            SEARCHSPAWN ssSpawn;
            ClearSearchSpawn(&ssSpawn);
            ssSpawn.FRadius=999999.0f;
            if (argc>=2 || !IsNumber(argv[0]))
            {
                ParseSearchSpawn(1,argc,argv,ssSpawn);
                nth=atoi(argv[0]);
            }
            else
            {
                nth=atoi(argv[0]);
            }
            if (Dest.Ptr=NthNearestSpawn(&ssSpawn,nth,pSpawn))
            {
                Dest.Type=pSpawnType;
                return true;
            }
        }
        return false;
#endif
    case Trader:
        Dest.DWord=pSpawn->Trader;
        Dest.Type=pBoolType;
        return true;
    case AFK:
        Dest.DWord=pSpawn->AFK;
        Dest.Type=pBoolType;
        return true;
    case LFG:
        Dest.DWord=pSpawn->LFG;
        Dest.Type=pBoolType;
        return true;
    case Linkdead:
        Dest.DWord=pSpawn->Linkdead;
        Dest.Type=pBoolType;
        return true;
    case AATitle:  // Leaving this in for older macros/etc.."Title" should be used instead.
        Dest.Type=pStringType;
        Dest.Ptr=&pSpawn->Title[0];
        return true;
    case Title:
        Dest.Type=pStringType;
        Dest.Ptr=&pSpawn->Title[0];
        return true;
    case Suffix: 
        Dest.Type=pStringType; 
        Dest.Ptr=&pSpawn->Suffix[0]; 
        return true; 
    case xGroupLeader:
        if (GetCharInfo()->pGroupInfo && GetCharInfo()->pGroupInfo->pLeader)
        {
            CHAR Name[MAX_STRING]={0};
            GetCXStr(GetCharInfo()->pGroupInfo->pLeader->pName,Name,MAX_STRING);
            Dest.DWord=(pSpawn->Type==SPAWN_PLAYER && !stricmp(Name,pSpawn->Name));
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case Assist:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn && pSpawn)
        {
            DWORD nAssist;
            {
                if (GetCharInfo()->pSpawn->GroupAssistNPC[0]==pSpawn->SpawnID)
                {
                    Dest.DWord=1;
                    Dest.Type=pBoolType;
                    return true;
                }
            }
            for (nAssist=0 ; nAssist < 3 ; nAssist++)
            {
                if (GetCharInfo()->pSpawn->RaidAssistNPC[nAssist]==pSpawn->SpawnID)
                {
                    Dest.DWord=1;
                    Dest.Type=pBoolType;
                    return true;
                }
            }
        }
        Dest.DWord=0;
        Dest.Type=pBoolType;
        return true;
    case Mark:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn && pSpawn)
        {
            DWORD nMark;
            for (nMark=0 ; nMark < 3 ; nMark++)
            {
                if (GetCharInfo()->pSpawn->RaidMarkNPC[nMark]==pSpawn->SpawnID)
                {
                    Dest.DWord=nMark+1;
                    Dest.Type=pIntType;
                    return true;
                }
            }
            for (nMark=0 ; nMark < 3 ; nMark++)
            {
                if (GetCharInfo()->pSpawn->GroupMarkNPC[nMark]==pSpawn->SpawnID)
                {
                    Dest.DWord=nMark+1;
                    Dest.Type=pIntType;
                    return true;
                }
            }
        }
        return false;
    case Anonymous:
        Dest.DWord=(pSpawn->Anon==1);
        Dest.Type=pBoolType;
        return true;
    case Roleplaying:
        Dest.DWord=(pSpawn->Anon==2);
        Dest.Type=pBoolType;
        return true;
    case xLineOfSight:
        Dest.DWord=(LineOfSight(GetCharInfo()->pSpawn,pSpawn));
        Dest.Type=pBoolType;
        return true;
    case HeadingToLoc: 
#ifndef ISXEQ
        if (!ISINDEX()) 
            return false; 
        if (PCHAR pComma=strchr(Index,',')) 
        { 
            *pComma=0; 
            FLOAT Y=(FLOAT)atof(Index); 
            *pComma=','; 
            FLOAT X=(FLOAT)atof(&pComma[1]); 
#else
        if (!argc) 
            return false; 
        if (argc==2) 
        { 
            FLOAT Y=(FLOAT)atof(argv[0]); 
            FLOAT X=(FLOAT)atof(argv[1]); 
#endif
            Dest.Float=(FLOAT)(atan2f(pSpawn->Y - Y, X - pSpawn->X) * 180.0f / PI + 90.0f); 
            if (Dest.Float<0.0f) 
                Dest.Float += 360.0f; 
            else if (Dest.Float>=360.0f) 
                Dest.Float -= 360.0f; 
            Dest.Type=pHeadingType; 
            return true; 
        } 
        return false;
    case Fleeing:
        Dest.DWord=IsMobFleeing(GetCharInfo()->pSpawn,pSpawn);
        Dest.Type=pBoolType;
        return true;
    case Named:
        Dest.DWord=IsNamed(pSpawn);
        Dest.Type=pBoolType;
        return true;
    case Buyer:
        Dest.DWord=pSpawn->Buyer;
        Dest.Type=pBoolType;
        return true;
    case Moving:
        Dest.DWord=fabs(pSpawn->SpeedRun)>0.0f;
        Dest.Type=pBoolType;
        return true;
    case CurrentMana:
        Dest.DWord=pSpawn->ManaCurrent;
        Dest.Type=pIntType;
        return true;
    case MaxMana:
        Dest.DWord=pSpawn->ManaMax;
        Dest.Type=pIntType;
        return true;
    case CurrentEndurance:
        Dest.DWord=pSpawn->EnduranceCurrent;
        Dest.Type=pIntType;
        return true;
    case MaxEndurance:
        Dest.DWord=pSpawn->EnduranceMax;
        Dest.Type=pIntType;
        return true;
    case Loc:
        sprintf(DataTypeTemp,"%.2f, %.2f",pSpawn->Y,pSpawn->X);
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case LocYX:
        sprintf(DataTypeTemp,"%.0f, %.0f",pSpawn->Y,pSpawn->X);
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case Owner:
        if(pSpawn->Mercenary)
        {
            unsigned int pos = strchr(pSpawn->Lastname, '\'') - &pSpawn->Lastname[0];
            strncpy(DataTypeTemp, pSpawn->Lastname, pos);
            DataTypeTemp[pos] = 0;
            if(PSPAWNINFO pOwner = (PSPAWNINFO)GetSpawnByName(DataTypeTemp))
            {
                Dest.Ptr = pOwner;
                Dest.Type = pSpawnType;
                return true;
            }
            return false;
        }
        return false;
    case Following:
        if(Dest.Ptr = pSpawn->WhoFollowing)
        {
            Dest.Type = pSpawnType;
            return true;
        }
    }
    return false;
}


bool MQ2BuffType::GETMEMBER()
{
#define pBuff ((PSPELLBUFF)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    if ((int)pBuff->SpellID<=0)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2BuffType::FindMember(Member);
    if (!pMember)
    {
        if (PSPELL pSpell=GetSpellByID(pBuff->SpellID))
        {
#ifndef ISXEQ 
            return pSpellType->GetMember(*(MQ2VARPTR*)&pSpell,Member,Index,Dest);
#else
            return pSpellType->GetMember(*(LSVARPTR*)&pSpell,Member,argc,argv,Dest);
#endif
        }
        return false;
    }

    static CHAR Temp[128];
    switch((BuffMembers)pMember->ID)
    {
    case ID:
        {
            if (GetBuffID(pBuff,(DWORD&)Dest.DWord))
            {
                Dest.Type=pIntType;
                return true;
            }
            if (GetShortBuffID(pBuff,(DWORD&)Dest.DWord))
            {
                Dest.Type=pIntType;
                return true;
            }
        }
        return false;
    case Level:
        Dest.DWord=pBuff->Level;
        Dest.Type=pIntType;
        return true;
    case Spell:
        if (Dest.Ptr=GetSpellByID(pBuff->SpellID))
        {
            Dest.Type=pSpellType;
            return true;
        }
        return false;
    case Mod:
        Dest.Float=(((float)pBuff->Modifier)/10.0f);
        if (Dest.Float!=1.0f)
        {
            Dest.Type=pFloatType;
            return true;
        }
        return false;
    case Duration:
        Dest.DWord=pBuff->Duration+1;// 0 is actually 6 seconds ;)
        Dest.Type=pTicksType;
        return true;
    case Dar:
#if 0
        if(PSPELL pSpell = GetSpellByID(pBuff->SpellID))
        {
            if(pSpell->SpellType != 0)
            {
                Dest.DWord=pBuff->DamageAbsorbRemaining;
                Dest.Type=pIntType;
                return true;
            }
        }
#endif
        return false;
    case Counters:
#if 0
        if(GetSpellByID(pBuff->SpellID)->SpellType == 0)
        {
            Dest.DWord=pBuff->Counters;
            Dest.Type=pIntType;
            return true;
        }
#endif
        return false;
    }
    return false;
#undef pBuff
}


bool MQ2CharacterType::GETMEMBER()
{
#define pChar ((PCHARINFO)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2CharacterType::FindMember(Member);
    if (!pMember)
    {
#ifndef ISXEQ
        return pSpawnType->GetMember(*(MQ2VARPTR*)&pChar->pSpawn,Member,Index,Dest);
#else
        return pSpawnType->GetMember(*(LSVARPTR*)&pChar->pSpawn,Member,argc,argv,Dest);
#endif
    }

    int nLang = 0;
    char buf[MAX_STRING]  = {0};
    unsigned long nBuff;
    char buf2[MAX_STRING] = {0};

    switch((CharacterMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=pChar->pSpawn->SpawnID;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=&pChar->Name[0];
        Dest.Type=pStringType;
        return true;
    case Surname:
        Dest.Ptr=&pChar->Lastname[0];
        Dest.Type=pStringType;
        return true;
    case Level:
        Dest.DWord=GetCharInfo2()->Level;
        Dest.Type=pIntType;
        return true;
    case Exp:
        Dest.DWord=pChar->Exp;
        Dest.Type=pIntType;
        return true;
    case PctExp:
        Dest.Float=(float)pChar->Exp/3.30f;
        Dest.Type=pFloatType;
        return true;
    case PctAAExp:
        Dest.Float=(float)pChar->AAExp/3.30f;
        Dest.Type=pFloatType;
        return true;
    case Spawn:
        Dest.Ptr=pChar->pSpawn;
        Dest.Type=pSpawnType;
        return true;
    case CurrentHPs:
        Dest.DWord=GetCurHPS();
        Dest.Type=pIntType;
        return true;
    case MaxHPs:
        Dest.Type=pIntType;
        Dest.Int=GetMaxHPS();
        return true;
    case PctHPs:
        Dest.Type=pIntType;
        Dest.Int=GetCurHPS()*100/GetMaxHPS();
        return true;
    case CurrentMana:
        Dest.DWord=GetCharInfo2()->Mana;
        Dest.Type=pIntType;
        return true;
    case MaxMana:
        Dest.DWord=GetMaxMana();
        Dest.Type=pIntType;
        return true;
    case PctMana:
        {
            if (unsigned long Temp=GetMaxMana())
                Dest.DWord=GetCharInfo2()->Mana*100/Temp;
            else
                Dest.DWord=0;
            Dest.Type=pIntType;
        }
        return true;
    case CountBuffs:
        Dest.DWord=0;
        {
            for (unsigned long nBuff=0 ; nBuff<NUM_LONG_BUFFS ; nBuff++)
            {
                if (GetCharInfo2()->Buff[nBuff].SpellID>0)
                    Dest.DWord++;
            }
            Dest.Type=pIntType;
        }
        return true;
    case Buff:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            unsigned long nBuff=GETNUMBER()-1;
            if (nBuff>=NUM_LONG_BUFFS)
                return false;
            if (GetCharInfo2()->Buff[nBuff].SpellID<=0)
                return false;
            Dest.Ptr=&GetCharInfo2()->Buff[nBuff];
            Dest.Type=pBuffType;
            return true;
        }
        else
        {
            for (unsigned long nBuff=0 ; nBuff < NUM_LONG_BUFFS ; nBuff++)
            {
                if (PSPELL pSpell=GetSpellByID(GetCharInfo2()->Buff[nBuff].SpellID))
                {
                    if (!stricmp(GETFIRST(),pSpell->Name))
                    {
                        Dest.Ptr=&GetCharInfo2()->Buff[nBuff];
                        Dest.Type=pBuffType;
                        return true;
                    }
                }
            }
        }
        return false;
    case Song:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            unsigned long nBuff=GETNUMBER()-1;
            if (nBuff>=NUM_SHORT_BUFFS)
                return false;
            if (GetCharInfo2()->ShortBuff[nBuff].SpellID<=0)
                return false;

            Dest.Ptr=&GetCharInfo2()->ShortBuff[nBuff];
            Dest.Type=pBuffType;
            return true;
        }
        else
        {
            for (unsigned long nBuff=0 ; nBuff < 35 ; nBuff++)
            {
                if (PSPELL pSpell=GetSpellByID(GetCharInfo2()->ShortBuff[nBuff].SpellID))
                {
                    if (!stricmp(GETFIRST(),pSpell->Name))
                    {
                        Dest.Ptr=&GetCharInfo2()->ShortBuff[nBuff];
                        Dest.Type=pBuffType;
                        return true;
                    }
                }
            }
        }
        return false;
    case HPBonus:
        Dest.DWord=pChar->HPBonus;
        Dest.Type=pIntType;
        return true;
    case ManaBonus:
        Dest.DWord=pChar->ManaBonus;
        Dest.Type=pIntType;
        return true;
    case EnduranceBonus:
        Dest.DWord=pChar->EnduranceBonus;
        Dest.Type=pIntType;
        return true;
    case CombatEffectsBonus:
        Dest.DWord=(pChar->CombatEffectsBonus > pChar->CombatEffectsCap ? pChar->CombatEffectsCap : pChar->CombatEffectsBonus);
        Dest.Type=pIntType;
        return true;
    case ShieldingBonus:
        Dest.DWord=(pChar->ShieldingBonus > pChar->ShieldingCap ? pChar->ShieldingCap : pChar->ShieldingBonus);
        Dest.Type=pIntType;
        return true;
    case SpellShieldBonus:
        Dest.DWord=(pChar->SpellShieldBonus > pChar->SpellShieldCap ? pChar->SpellShieldCap : pChar->SpellShieldBonus);
        Dest.Type=pIntType;
        return true;
    case AvoidanceBonus:
        Dest.DWord=(pChar->AvoidanceBonus > pChar->AvoidanceCap ? pChar->AvoidanceCap : pChar->AvoidanceBonus);
        Dest.Type=pIntType;
        return true;
    case AccuracyBonus:
        Dest.DWord=(pChar->AccuracyBonus > pChar->AccuracyCap ? pChar->AccuracyCap : pChar->AccuracyBonus);
        Dest.Type=pIntType;
        return true;
    case StunResistBonus:
        Dest.DWord=(pChar->StunResistBonus > pChar->StunResistCap ? pChar->StunResistCap : pChar->StunResistBonus);
        Dest.Type=pIntType;
        return true;
    case StrikeThroughBonus:
        Dest.DWord=(pChar->StrikeThroughBonus > pChar->StrikeThroughCap ? pChar->StrikeThroughCap : pChar->StrikeThroughBonus);
        Dest.Type=pIntType;
        return true;
    case DoTShieldBonus:
        Dest.DWord=(pChar->DoTShieldBonus > pChar->DoTShieldCap ? pChar->DoTShieldCap : pChar->DoTShieldBonus);
        Dest.Type=pIntType;
        return true;
    case AttackBonus:
        Dest.DWord=pChar->AttackBonus;
        Dest.Type=pIntType;
        return true;
    case HPRegenBonus:
        Dest.DWord=pChar->HPRegenBonus;
        Dest.Type=pIntType;
        return true;
    case ManaRegenBonus:
        Dest.DWord=pChar->ManaRegenBonus;
        Dest.Type=pIntType;
        return true;
    case DamageShieldBonus:
        Dest.DWord=(pChar->DamageShieldBonus > pChar->DamageShieldCap ? pChar->DamageShieldCap : pChar->DamageShieldBonus);
        Dest.Type=pIntType;
        return true;
    case DamageShieldMitigationBonus:
        Dest.DWord=(pChar->DamageShieldMitigationBonus > pChar->DamageShieldMitigationCap ? pChar->DamageShieldMitigationCap : pChar->DamageShieldMitigationBonus);
        Dest.Type=pIntType;
        return true;
    case HeroicSTRBonus:
        Dest.DWord=pChar->HeroicSTRBonus;
        Dest.Type=pIntType;
        return true;
    case HeroicINTBonus:
        Dest.DWord=pChar->HeroicINTBonus;
        Dest.Type=pIntType;
        return true;
    case HeroicWISBonus:
        Dest.DWord=pChar->HeroicWISBonus;
        Dest.Type=pIntType;
        return true;
    case HeroicAGIBonus:
        Dest.DWord=pChar->HeroicAGIBonus;
        Dest.Type=pIntType;
        return true;
    case HeroicDEXBonus:
        Dest.DWord=pChar->HeroicDEXBonus;
        Dest.Type=pIntType;
        return true;
    case HeroicSTABonus:
        Dest.DWord=pChar->HeroicSTABonus;
        Dest.Type=pIntType;
        return true;
    case HeroicCHABonus:
        Dest.DWord=pChar->HeroicCHABonus;
        Dest.Type=pIntType;
        return true;
    case HealAmountBonus:
        Dest.DWord=pChar->HealAmountBonus;
        Dest.Type=pIntType;
        return true;
    case SpellDamageBonus:
        Dest.DWord=pChar->SpellDamageBonus;
        Dest.Type=pIntType;
        return true;
    case ClairvoyanceBonus:
        Dest.DWord=pChar->ClairvoyanceBonus;
        Dest.Type=pIntType;
        return true;
    case EnduranceRegenBonus:
        Dest.DWord=pChar->EnduranceRegenBonus;
        Dest.Type=pIntType;
        return true; 
    case AttackSpeed:
        Dest.DWord=pChar->AttackSpeed;
        Dest.Type=pIntType;
        return true;
    case Endurance:  //Grandfathered, CurrentEndurance should be used instead.
        Dest.DWord=GetCharInfo2()->Endurance;
        Dest.Type=pIntType;
        return true;
    case CurrentEndurance: 
        Dest.DWord=GetCharInfo2()->Endurance; 
        Dest.Type=pIntType; 
        return true;
    case MaxEndurance:
        Dest.DWord=GetMaxEndurance();
        Dest.Type=pIntType;
        return true;
    case PctEndurance:
        {
            if (unsigned long Temp=GetMaxEndurance())
                Dest.DWord=(GetCharInfo2()->Endurance*100)/Temp;
            else
                Dest.DWord=0;
            Dest.Type=pIntType;
        }
        return true;
    case GukEarned:
        return false;//TODO
        //Dest.DWord=pChar->GukEarned;
        Dest.Type=pIntType;
        return true;
    case MMEarned:
        return false;//TODO
        //Dest.DWord=pChar->MMEarned;
        Dest.Type=pIntType;
        return true;
    case RujEarned:
        return false;//TODO
        //Dest.DWord=pChar->RujEarned;
        Dest.Type=pIntType;
        return true;
    case TakEarned:
        return false;//TODO
        //Dest.DWord=pChar->TakEarned;
        Dest.Type=pIntType;
        return true;
    case MirEarned:
        return false;//TODO
        //Dest.DWord=pChar->MirEarned;
        Dest.Type=pIntType;
        return true;
    case LDoNPoints:
        return false;//TODO
        //Dest.DWord=pChar->LDoNPoints;
        Dest.Type=pIntType;
        return true;
    case CurrentFavor:
        Dest.DWord=pChar->CurrFavor;
        Dest.Type=pIntType;
        return true;
    case CareerFavor:
        Dest.DWord=pChar->CareerFavor;
        Dest.Type=pIntType;
        return true;
    case Inventory:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                unsigned long nSlot=GETNUMBER();
                if (nSlot<0x800)
                {
                    if (Dest.Ptr=GetCharInfo2()->pInventoryArray->InventoryArray[nSlot])
                    {
                        Dest.Type=pItemType;
                        return true;
                    }
                }
            }
            else
            {
                for (unsigned long nSlot=0 ; szItemSlot[nSlot] ; nSlot++)
                {
                    if (!stricmp(GETFIRST(),szItemSlot[nSlot]))
                    {
                        if (Dest.Ptr=GetCharInfo2()->pInventoryArray->InventoryArray[nSlot])
                        {
                            Dest.Type=pItemType;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    case Bank:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                unsigned long nSlot=GETNUMBER()-1;
                if (nSlot<NUM_BANK_SLOTS)
                {
                    if (Dest.Ptr=pChar->pBankArray->Bank[nSlot])
                    {
                        Dest.Type=pItemType;
                        return true;
                    }
                } else {
                    nSlot -= NUM_BANK_SLOTS;
                    if (nSlot<NUM_SHAREDBANK_SLOTS)
                    {
                        if (Dest.Ptr=pChar->pSharedBankArray->SharedBank[nSlot])
                        {
                            Dest.Type=pItemType;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    case PlatinumShared:
        Dest.DWord=pChar->BankSharedPlat;
        Dest.Type=pIntType;
        return true;
    case Cash:
        Dest.DWord=GetCharInfo2()->Plat*1000+GetCharInfo2()->Gold*100+GetCharInfo2()->Silver*10+GetCharInfo2()->Copper;
        Dest.Type=pIntType;
        return true;
    case Platinum:
        Dest.DWord=GetCharInfo2()->Plat;
        Dest.Type=pIntType;
        return true;
    case Gold:
        Dest.DWord=GetCharInfo2()->Gold;
        Dest.Type=pIntType;
        return true;
    case Silver:
        Dest.DWord=GetCharInfo2()->Silver;
        Dest.Type=pIntType;
        return true;
    case Copper:
        Dest.DWord=GetCharInfo2()->Copper;
        Dest.Type=pIntType;
        return true;
    case CashBank:
        Dest.DWord=pChar->BankPlat*1000+pChar->BankGold*100+pChar->BankSilver*10+pChar->BankCopper;
        Dest.Type=pIntType;
        return true;
    case PlatinumBank:
        Dest.DWord=pChar->BankPlat;
        Dest.Type=pIntType;
        return true;
    case GoldBank:
        Dest.DWord=pChar->BankGold;
        Dest.Type=pIntType;
        return true;
    case SilverBank:
        Dest.DWord=pChar->BankSilver;
        Dest.Type=pIntType;
        return true;
    case CopperBank:
        Dest.DWord=pChar->BankCopper;
        Dest.Type=pIntType;
        return true;
    case AAExp:
        Dest.DWord=pChar->AAExp;
        Dest.Type=pIntType;
        return true;
    case AAPoints:
        Dest.DWord=GetCharInfo2()->AAPoints;
        Dest.Type=pIntType;
        return true;
    case Combat:
        Dest.DWord=*EQADDR_ATTACK;
        Dest.Type=pBoolType;
        return true;
    case HPRegen:
        Dest.DWord=HealthGained;
        Dest.Type=pIntType;
        return true;
    case ManaRegen:
        Dest.DWord=ManaGained;
        Dest.Type=pIntType;
        return true;
    case EnduranceRegen: 
        Dest.DWord=EnduranceGained; 
        Dest.Type=pIntType; 
        return true;
    case Dar:
#if 0
        Dest.DWord=0;
        {
            for (unsigned long k=0; k<NUM_LONG_BUFFS ; k++)
                if(PSPELL pSpell = GetSpellByID(GetCharInfo2()->Buff[k].SpellID))
                    if(pSpell->SpellType != 0)
                        if(GetCharInfo2()->Buff[k].DamageAbsorbRemaining)
                            Dest.DWord+=GetCharInfo2()->Buff[k].DamageAbsorbRemaining;
                        else if(GetCharInfo2()->Buff[k].DamageAbsorbRemaining2)
                            Dest.DWord+=GetCharInfo2()->Buff[k].DamageAbsorbRemaining2;
                        else if(GetCharInfo2()->Buff[k].DamageAbsorbRemaining3)
                            Dest.DWord+=GetCharInfo2()->Buff[k].DamageAbsorbRemaining3;
        }
        Dest.Type=pIntType;
        return true;
#endif 
        return false;
    case Grouped:
        if(!pChar->pGroupInfo) return false;
        Dest.DWord= pChar->pGroupInfo->pMember[1] ||
            pChar->pGroupInfo->pMember[2] ||
            pChar->pGroupInfo->pMember[3] ||
            pChar->pGroupInfo->pMember[4] ||
            pChar->pGroupInfo->pMember[5];
        Dest.Type=pBoolType;
        return true;    
    case GroupList: // This isn't really working as intended just yet
        {
            if(!pChar->pGroupInfo) return false;
            for(int i=1; i<6; i++)
                if(pChar->pGroupInfo->pMember[i])
                {
                    char tmp[MAX_STRING];
                    GetCXStr(pChar->pGroupInfo->pMember[i]->pName, tmp, sizeof(tmp));
                    strcat(buf, tmp);
                    if(i<5 && pChar->pGroupInfo->pMember[i+1])
                        strcat(buf, " ");
                }
        }
        Dest.Ptr=&buf[0];
        Dest.Type=pStringType;
        return true;
    case AmIGroupLeader:
        if (!pChar->pGroupInfo) return false;
        if (!pChar->pGroupInfo->pLeader) return false;
        GetCXStr(pChar->pGroupInfo->pLeader->pName, buf, sizeof(buf));
        if(!stricmp(buf, pChar->Name))
            Dest.Ptr="TRUE";
        else
            Dest.Ptr="FALSE";
        Dest.Type=pStringType;
        return true;
    case FreeBuffSlots: 
        Dest.DWord=GetAAIndexByName("mystical attuning"); 
        if (PlayerHasAAAbility(Dest.DWord)) 
        { 
            for (unsigned int j=0; j < AA_CHAR_MAX_REAL; j++) 
            { 
                if ( pPCData->GetAltAbilityIndex(j) == Dest.DWord) 
                { 
                    Dest.DWord=15+(GetCharInfo2()->AAList[j].PointsSpent/5); 
                    break; 
                } 
            } 
        } else Dest.DWord = 15; 
        if(GetAAIndexByName("Embrace of the Dark Reign")) Dest.DWord++;
        if(GetAAIndexByName("Embrace of the Keepers")) Dest.DWord++; 
        if(GetCharInfo()->pSpawn->Level > 71) Dest.DWord++;
        if(GetCharInfo()->pSpawn->Level > 74) Dest.DWord++;

        for (nBuff=0 ; nBuff<NUM_LONG_BUFFS ; nBuff++) 
        { 
            if (GetCharInfo2()->Buff[nBuff].SpellID>0) 
                Dest.DWord--; 
        } 
        Dest.Type = pIntType; 
        return true; 
    case Gem:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            // number
            unsigned long nGem=GETNUMBER()-1;
            if (nGem<NUM_SPELL_GEMS)
            {
                if (Dest.Ptr=GetSpellByID(GetCharInfo2()->MemorizedSpells[nGem]))
                {
                    Dest.Type=pSpellType;
                    return true;
                }
            }
        }
        else
        {
            // name
            for (unsigned long nGem=0 ; nGem < NUM_SPELL_GEMS ; nGem++)
            {
                if (PSPELL pSpell=GetSpellByID(GetCharInfo2()->MemorizedSpells[nGem]))
                {
                    if (!stricmp(GETFIRST(),pSpell->Name))
                    {
                        Dest.DWord=nGem+1;
                        Dest.Type=pIntType;
                        return true;
                    }
                }
            }
        }
        return false;
    case LanguageSkill: 
        if (!ISINDEX()) 
            return false; 

        if (ISNUMBER())
            nLang=GETNUMBER()-1;
        else 
            nLang=GetLanguageIDByName(GETFIRST())-1;

        if (nLang < 0 || nLang >= 25 )
            return false;

        Dest.DWord=pChar->languages[nLang]; 
        Dest.Type=pIntType; 
        return true; 
    case CombatAbility:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            // number
            unsigned long nCombatAbility=GETNUMBER()-1;
            if ( PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)) )
            { 
                Dest.Ptr=pSpell;
                Dest.Type=pSpellType;
                return true;
            }
        }
        else
        {
            // name
            for (unsigned long nCombatAbility=0 ; nCombatAbility < NUM_COMBAT_ABILITIES ; nCombatAbility++)
            {
                if ( PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)) )
                {
                    if (!stricmp(GETFIRST(),pSpell->Name))
                    {
                        Dest.DWord=nCombatAbility+1;
                        Dest.Type=pIntType;
                        return true;
                    }
                }
            }
        }
        return false;
    case CombatAbilityTimer: 
        if (ISINDEX()) 
        { 
            if (ISNUMBER()) 
            { 
                // number 
                unsigned long nCombatAbility=GETNUMBER()-1; 
                if ( PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)) )
                { 
                    DWORD timeNow = (DWORD)time(NULL);
                    if (pSpell->CARecastTimerID != -1 && pPCData->GetCombatAbilityTimer(pSpell->CARecastTimerID) > timeNow)
                    {
                        Dest.Int=pPCData->GetCombatAbilityTimer(pSpell->CARecastTimerID)-timeNow+6;
                        Dest.Int/=6;
                    }
                    else Dest.Int=0;
                    Dest.Type=pTicksType;
                    return true;
                } 
            } 
            else 
            { 
                // by name 
                for (unsigned long nCombatAbility=0 ; nCombatAbility < NUM_COMBAT_ABILITIES ; nCombatAbility++) 
                {
                    if ( PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)) )
                    { 
                        if (!stricmp(GETFIRST(),pSpell->Name)) 
                        { 
                            DWORD timeNow = (DWORD)time(NULL);
                            if (pSpell->CARecastTimerID != -1 && pPCData->GetCombatAbilityTimer(pSpell->CARecastTimerID) > timeNow)
                            {
                                Dest.Int=pPCData->GetCombatAbilityTimer(pSpell->CARecastTimerID)-timeNow+6;
                                Dest.Int/=6;
                            }
                            else Dest.Int=0;
                            Dest.Type=pTicksType;
                            return true;
                        } 
                    } 
                } 
            } 
        } 
        return false; 
    case CombatAbilityReady: 
        Dest.DWord=0; 
        Dest.Type=pBoolType; 
        if (ISINDEX()) 
        { 
            if (ISNUMBER() && GETNUMBER()-1 < NUM_COMBAT_ABILITIES) 
            { 
                // number 
                unsigned long nCombatAbility=GETNUMBER()-1; 
                if ( PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)) )
                { 
                    DWORD timeNow = (DWORD)time(NULL);
                    if (pSpell->CARecastTimerID != -1 && pPCData->GetCombatAbilityTimer(pSpell->CARecastTimerID) < timeNow)
                    {
                        Dest.DWord=1;
                        return true;
                    } 
                } 
            } 
            else 
            { 
                // by name 
                for (unsigned long nCombatAbility=0 ; nCombatAbility < NUM_COMBAT_ABILITIES ; nCombatAbility++) 
                { 
                    if ( PSPELL pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)) )
                    { 
                        if (!stricmp(GETFIRST(),pSpell->Name)) 
                        { 
                            DWORD timeNow = (DWORD)time(NULL);
                            if (pSpell->CARecastTimerID != -1 && pPCData->GetCombatAbilityTimer(pSpell->CARecastTimerID) < timeNow)
                            {
                                Dest.DWord=1;
                                return true;
                            }
                        } 
                    } 
                } 
            } 
        } 
        return true; 
    case Moving:
        Dest.DWord=((((gbMoving) && ((PSPAWNINFO)pCharSpawn)->SpeedRun==0.0f) && (pChar->pSpawn->Mount ==  NULL )) || (fabs(FindSpeed((PSPAWNINFO)pCharSpawn)) > 0.0f ));
        Dest.Type=pBoolType;
        return true;
    case Hunger:
        Dest.DWord=GetCharInfo2()->hungerlevel;
        Dest.Type=pIntType;
        return true;
    case Thirst:
        Dest.DWord=GetCharInfo2()->thirstlevel;
        Dest.Type=pIntType;
        return true;
    case AltAbilityTimer:
        if (ISINDEX()) {
            if (ISNUMBER()) {
                //numeric
                for (unsigned long nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
                    if ( PALTABILITY pAbility=pAltAdvManager->GetAltAbility(pPCData->GetAltAbilityIndex(nAbility)) ) {
                        if (pAbility->ID == GETNUMBER() ) {
                            pAltAdvManager->IsAbilityReady(pPCData,pAbility,&Dest.Int);
                            if (Dest.Int<0)
                                return false;
                            Dest.Int/=6;
                            Dest.Type=pTicksType;
                            return true;
                        }
                    }
                }
            } else {
                // by name
                for (unsigned long nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
                    if ( PALTABILITY pAbility=pAltAdvManager->GetAltAbility(pPCData->GetAltAbilityIndex(nAbility)) ) {
                        if (PCHAR pName=pCDBStr->GetString(pAbility->nName, 1, NULL)) {
                            if (!stricmp(GETFIRST(),pName)) {
                                pAltAdvManager->IsAbilityReady(pPCData,pAbility,&Dest.Int);
                                if (Dest.Int<0)
                                    return false;
                                Dest.Int/=6;
                                Dest.Type=pTicksType;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    case AltAbilityReady:
        if (ISINDEX()) {
            if (ISNUMBER()) {
                //numeric
                for (unsigned long nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
                    if ( PALTABILITY pAbility=pAltAdvManager->GetAltAbility(pPCData->GetAltAbilityIndex(nAbility)) ) {
                        if (pAbility->ID == GETNUMBER()) {
                            Dest.DWord=pAltAdvManager->IsAbilityReady(pPCData,pAbility,0);
                            Dest.Type=pBoolType;
                            return true;
                        }
                    }
                }
            } else {
                // by name
                for (unsigned long nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
                    if ( PALTABILITY pAbility=pAltAdvManager->GetAltAbility(pPCData->GetAltAbilityIndex(nAbility)) ) {
                        if (PCHAR pName=pCDBStr->GetString(pAbility->nName, 1, NULL)) {
                            if (!stricmp(GETFIRST(),pName)) {
                                Dest.DWord=pAltAdvManager->IsAbilityReady(pPCData,pAbility,0);
                                Dest.Type=pBoolType;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    case AltAbility:
        if (ISINDEX()) {
            if (ISNUMBER()) {
                //numeric
                for (unsigned long nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
                    if ( PALTABILITY pAbility=pAltAdvManager->GetAltAbility(pPCData->GetAltAbilityIndex(nAbility)) ) {
                        if (pAbility->ID == GETNUMBER()) {
                            Dest.Ptr = pAbility;
                            Dest.Type = pAltAbilityType;
                            return true;
                        }
                    }
                }
            } else {
                // by name
                for (unsigned long nAbility=0 ; nAbility<AA_CHAR_MAX_REAL ; nAbility++) {
                    if ( PALTABILITY pAbility=pAltAdvManager->GetAltAbility(pPCData->GetAltAbilityIndex(nAbility)) ) {
                        if (PCHAR pName=pCDBStr->GetString(pAbility->nName, 1, NULL)) {
                            if (!stricmp(GETFIRST(),pName)) {
                                Dest.Ptr = pAbility;
                                Dest.Type = pAltAbilityType;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    case Skill:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                // numeric
                unsigned long nSkill=GETNUMBER()-1;
                if (nSkill<NUM_SKILLS)
                {
                    Dest.DWord=GetCharInfo2()->Skill[nSkill];
                    Dest.Type=pIntType;
                    if (!Dest.DWord) {
                        if(pSkillMgr->pSkill[nSkill]->Activated) {
                            for(int btn=0; !Dest.DWord && btn<10; btn++) {
                                if(EQADDR_DOABILITYLIST[btn]==nSkill) Dest.DWord=1;
                            }
                        }
                    }
                    return true;
                }
            }
            else
            {
                // name
                for (DWORD nSkill=0;nSkill<NUM_SKILLS;nSkill++)
                    if (!stricmp(GETFIRST(),szSkills[nSkill]))
                    {
                        Dest.DWord=GetCharInfo2()->Skill[nSkill];
                        Dest.Type=pIntType;
                        // note: this change fixes the problem where ${Me.Skill[Forage]} returns
                        // 0 even if you have bought the aa for cultural forage...
                        if (!Dest.DWord) {
                            if(pSkillMgr->pSkill[nSkill]->Activated) {
                                for(int btn=0; !Dest.DWord && btn<10; btn++) {
                                    if(EQADDR_DOABILITYLIST[btn]==nSkill) Dest.DWord=1;
                                }
                            }
                        }
                        return true;
                    }
            }
        }
        return false;

    case SkillCap:
        if (ISINDEX()) {
            class PcZoneClient *p = (PcZoneClient *)GetCharInfo();
            unsigned long nSkill = 0;

            if (ISNUMBER()) {
                // numeric
                nSkill=GETNUMBER()-1;
            } else {
                for (nSkill=0;nSkill<NUM_SKILLS;nSkill++)
                    if (!stricmp(GETFIRST(),szSkills[nSkill]))
                        break;
            }
            if (nSkill < NUM_SKILLS) {
                Dest.Type=pIntType;
                Dest.DWord = p->GetPcSkillLimit(nSkill);
                return true;
            }
        }
        return false;

    case Ability:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                // numeric
                if (unsigned long nSkill=GETNUMBER())
                {
                    if (nSkill<7)
                    {
                        nSkill+=3;
                    }
                    else if (nSkill<11)
                    {
                        nSkill-=7;
                    }
                    else
                        return false;
                    if (EQADDR_DOABILITYLIST[nSkill]!=0xFFFFFFFF)
                    {
                        Dest.Ptr=szSkills[EQADDR_DOABILITYLIST[nSkill]];
                        Dest.Type=pStringType;
                        return true;
                    }
                }
            }
            else
            {
                // name
                for (DWORD nSkill=0;szSkills[nSkill];nSkill++)
                    if (!stricmp(GETFIRST(),szSkills[nSkill]))
                    {
                        // found name
                        for (DWORD nAbility=0;nAbility<10;nAbility++)
                            if (EQADDR_DOABILITYLIST[nAbility] == nSkill) 
                            {
                                if (nAbility<4)
                                    nAbility+=7;
                                else
                                    nAbility-=3;
                                Dest.DWord=nAbility;
                                Dest.Type=pIntType;
                                return true;
                            }
                    }
            }
        }
        return false;
    case AbilityReady:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                // numeric
                if (unsigned long nSkill=GETNUMBER())
                {
                    if (nSkill<7)
                    {
                        nSkill+=3;
                    }
                    else if (nSkill<11)
                    {
                        nSkill-=7;
                    }
                    else
                        return false;
                    /**/
                    if (EQADDR_DOABILITYLIST[nSkill]!=0xFFFFFFFF)
                    {
                        //if (pSkillMgr->pSkill[EQADDR_DOABILITYLIST[nSkill]]->AltTimer==2)
                        //    Dest.DWord=gbAltTimerReady;
                        //else
                        Dest.DWord=pCSkillMgr->IsAvailable(EQADDR_DOABILITYLIST[nSkill]);
                        Dest.Type=pBoolType;
                        return true;
                    }
                }
            }
            else
            {
                // name
                for (DWORD nSkill=0;szSkills[nSkill];nSkill++)
                {
                    if (!stricmp(GETFIRST(),szSkills[nSkill]))
                    {
                        // found name
                        for (DWORD nAbility=0;nAbility<10;nAbility++)
                        {
                            if (EQADDR_DOABILITYLIST[nAbility] == nSkill) 
                            {
                                // thanks s0rcier!
                                if (nSkill<100 || nSkill == 111 || nSkill == 114 || nSkill == 115 || nSkill == 116)
                                {
                                    //if (pSkillMgr->pSkill[nSkill]->AltTimer==2) // this check is included in CSkillMgr::IsAvailable
                                    //    Dest.DWord=gbAltTimerReady;
                                    //else
                                    Dest.DWord=pCSkillMgr->IsAvailable(EQADDR_DOABILITYLIST[nAbility]);
                                    Dest.Type=pBoolType;
                                    return true;
                                }
                                //if (nSkill==111) { // this check is included in CSkillMgr::IsAvailable
                                //    Dest.DWord=gbAltTimerReady;
                                //    Dest.Type=pBoolType;
                                //    return true;
                                //}
                                if (nSkill==105 || nSkill==107) {
                                    Dest.DWord=LoH_HT_Ready();
                                    Dest.Type=pBoolType;
                                    return true;
                                }
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return false;
    case RangedReady:
        Dest.DWord=gbRangedAttackReady;
        Dest.Type=pBoolType;
        return true;
    case AltTimerReady:
        Dest.DWord=gbAltTimerReady;
        Dest.Type=pBoolType;
        return true;
    case Book:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                // numeric
                unsigned long nSpell=GETNUMBER()-1;
                if (nSpell<NUM_BOOK_SLOTS)
                    if (Dest.Ptr=GetSpellByID(GetCharInfo2()->SpellBook[nSpell]))
                    {
                        Dest.Type=pSpellType;
                        return true;
                    }
            }
            else
            {
                // name
                for (DWORD nSpell=0 ; nSpell < NUM_BOOK_SLOTS ; nSpell++)
                    if (GetCharInfo2()->SpellBook[nSpell] != 0xFFFFFFFF)
                    {
                        if (!stricmp(GetSpellNameByID(GetCharInfo2()->SpellBook[nSpell]),GETFIRST()))
                        {
                            Dest.DWord=nSpell+1;
                            Dest.Type=pIntType;
                            return true;
                        }
                    }
            }
        }
        return false;
    case SpellReady: 
        if (pCastSpellWnd && ISINDEX()) 
        { 
            if (ISNUMBER()) 
            { 
                // numeric 
                unsigned long nGem=GETNUMBER()-1; 
                if (nGem<NUM_SPELL_GEMS) 
                { 
                    if (!((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem]) 
                        Dest.DWord=0; 
                    else 
                        Dest.DWord = (((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem]->spellstate!=1); 
                    Dest.Type=pBoolType; 
                    return true; 
                } 
            } 
            else 
            { 
                for (unsigned long nGem=0 ; nGem < NUM_SPELL_GEMS ; nGem++) 
                { 
                    if (PSPELL pSpell=GetSpellByID(GetCharInfo2()->MemorizedSpells[nGem])) 
                    { 
                        if (!stricmp(GETFIRST(),pSpell->Name)) 
                        { 
                            if (!((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem]) 
                                Dest.DWord=0; 
                            else 
                                Dest.DWord = (((PEQCASTSPELLWINDOW)pCastSpellWnd)->SpellSlots[nGem]->spellstate!=1); 
                            Dest.Type=pBoolType; 
                            return true; 
                        } 
                    } 
                } 
            } 
        } 
        return false; 
    case PetBuff:
        if (!ISINDEX() || !pPetInfoWnd)
            return false;
#define pPetInfoWindow ((PEQPETINFOWINDOW)pPetInfoWnd)
        if (ISNUMBER())
        {
            unsigned long nBuff=GETNUMBER()-1;
            if (nBuff>NUM_BUFF_SLOTS)
                return false;
            if (pPetInfoWindow->Buff[nBuff]==0xFFFFFFFF || pPetInfoWindow->Buff[nBuff]==0)
                return false;
            if (Dest.Ptr=GetSpellByID(pPetInfoWindow->Buff[nBuff]))
            {
                Dest.Type=pSpellType;
                return true;
            }
        }
        else
        {
            for (unsigned long nBuff=0 ; nBuff < NUM_BUFF_SLOTS ; nBuff++)
            {
                if (PSPELL pSpell=GetSpellByID(pPetInfoWindow->Buff[nBuff]))
                {
                    if (!stricmp(GETFIRST(),pSpell->Name))
                    {
                        Dest.DWord=nBuff+1;
                        Dest.Type=pIntType;
                        return true;
                    }
                }
            }
        }
#undef pPetInfoWindow
        return false;
    case GroupLeaderExp:
        Dest.Float=(FLOAT)pChar->GroupLeadershipExp;
        Dest.Type=pFloatType;
        return true;
    case RaidLeaderExp:
        Dest.Float=(FLOAT)pChar->RaidLeadershipExp;
        Dest.Type=pFloatType;
        return true;
    case PctGroupLeaderExp:
        Dest.Float=(float)pChar->GroupLeadershipExp/10.0f;
        Dest.Type=pFloatType;
        return true;
    case PctRaidLeaderExp:
        Dest.Float=(float)pChar->RaidLeadershipExp/10.0f;
        Dest.Type=pFloatType;
        return true;
    case GroupLeaderPoints:
        Dest.DWord=pChar->GroupLeadershipPoints;
        Dest.Type=pIntType;
        return true;
    case RaidLeaderPoints:
        Dest.DWord=pChar->RaidLeadershipPoints;
        Dest.Type=pIntType;
        return true;
    case Stunned:
        Dest.DWord=(pChar->Stunned==1);
        Dest.Type=pBoolType;
        return true;
    case LargestFreeInventory:
        {
            Dest.DWord=0;
            Dest.Type=pIntType;
            for (DWORD slot=BAG_SLOT_START;slot<NUM_INV_SLOTS;slot++) 
            {
                if (PCONTENTS pItem = GetCharInfo2()->pInventoryArray->InventoryArray[slot])
                {
                    if (GetItemFromContents(pItem)->Type==ITEMTYPE_PACK && GetItemFromContents(pItem)->SizeCapacity>Dest.DWord) 
                    {
                        for (DWORD pslot=0;pslot<(GetItemFromContents(pItem)->Slots);pslot++) 
                        {
                            if (!pItem->pContentsArray || !pItem->pContentsArray->Contents[pslot])
                            {
                                Dest.DWord=GetItemFromContents(pItem)->SizeCapacity;
                                break;// break the loop for this pack
                            }
                        }
                    }
                } 
                else 
                {
                    Dest.DWord=4;
                    return true;
                }
            }
        }
        return true;
    case FreeInventory:
        if (ISINDEX())
        {
            DWORD nSize=GETNUMBER();
            if (nSize>4)
                nSize=4;
            Dest.DWord=0;
            for (DWORD slot=BAG_SLOT_START;slot<NUM_INV_SLOTS;slot++) 
            {
                if (PCONTENTS pItem = GetCharInfo2()->pInventoryArray->InventoryArray[slot]) 
                {
                    if (GetItemFromContents(pItem)->Type==ITEMTYPE_PACK && GetItemFromContents(pItem)->SizeCapacity>=nSize) 
                    {
                        if (!pItem->pContentsArray) {
                            Dest.DWord+= GetItemFromContents(pItem)->Slots;
                        } else {
                            for (DWORD pslot=0;pslot<(GetItemFromContents(pItem)->Slots);pslot++) 
                            {
                                if (!pItem->pContentsArray->Contents[pslot]) 
                                    Dest.DWord++;
                            }
                        }
                    }
                } 
                else 
                {
                    Dest.DWord++;
                }
            }
            Dest.Type=pIntType; 
            return true;
        }
        else
        {
            Dest.DWord=0;
            for (DWORD slot=BAG_SLOT_START;slot<NUM_INV_SLOTS;slot++) 
            {
                if(!HasExpansion(EXPANSION_HoT) && slot > 30)
                    break;
                if (PCONTENTS pItem = GetCharInfo2()->pInventoryArray->InventoryArray[slot]) 
                {
                    if (GetItemFromContents(pItem)->Type==ITEMTYPE_PACK) 
                    {
                        if (!pItem->pContentsArray) {
                            Dest.DWord+= GetItemFromContents(pItem)->Slots;
                        } else {
                            for (DWORD pslot=0;pslot<(GetItemFromContents(pItem)->Slots);pslot++) 
                            {
                                if (!pItem->pContentsArray->Contents[pslot]) 
                                    Dest.DWord++;
                            }
                        }
                    }
                } 
                else 
                {
                    Dest.DWord++;
                }
            }
            Dest.Type=pIntType; 
            return true;
        }
    case Drunk:
        Dest.DWord=GetCharInfo2()->Drunkenness;
        Dest.Type=pIntType;
        return true;
    case TargetOfTarget:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
            if (Dest.Ptr=GetSpawnByID(pChar->pSpawn->TargetOfTarget))
            {
                Dest.Type=pSpawnType;
                return true;
            }
            return false;
    case RaidAssistTarget:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
            if (ISINDEX() && ISNUMBER())
            {
                DWORD N=GETNUMBER()-1;
                if (N>=3)
                    return false;
                if (Dest.Ptr=GetSpawnByID(pChar->pSpawn->RaidAssistNPC[N]))
                {
                    Dest.Type=pSpawnType;
                    return true;
                }
            }
            return false;
    case GroupAssistTarget:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
        {
            if (Dest.Ptr=GetSpawnByID(pChar->pSpawn->GroupAssistNPC[0]))
            {
                Dest.Type=pSpawnType;
                return true;
            }
        }
        return false;
    case RaidMarkNPC:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
            if (ISINDEX() && ISNUMBER())
            {
                DWORD N=GETNUMBER()-1;
                if (N>=3)
                    return false;
                if (Dest.Ptr=GetSpawnByID(pChar->pSpawn->RaidMarkNPC[N]))
                {
                    Dest.Type=pSpawnType;
                    return true;
                }
            }
            return false;
    case GroupMarkNPC:
        if (gGameState==GAMESTATE_INGAME && GetCharInfo()->pSpawn)
            if (ISINDEX() && ISNUMBER())
            {
                DWORD N=GETNUMBER()-1;
                if (N>=3)
                    return false;
                if (Dest.Ptr=GetSpawnByID(pChar->pSpawn->GroupMarkNPC[N]))
                {
                    Dest.Type=pSpawnType;
                    return true;
                }
            }
            return false;
    case STR: 
        Dest.DWord=pChar->STR; 
        Dest.Type=pIntType; 
        return true; 
    case STA: 
        Dest.DWord=pChar->STA; 
        Dest.Type=pIntType; 
        return true; 
    case AGI: 
        Dest.DWord=pChar->AGI; 
        Dest.Type=pIntType; 
        return true; 
    case DEX: 
        Dest.DWord=pChar->DEX; 
        Dest.Type=pIntType; 
        return true; 
    case WIS: 
        Dest.DWord=pChar->WIS; 
        Dest.Type=pIntType; 
        return true; 
    case INT: 
        Dest.DWord=pChar->INT; 
        Dest.Type=pIntType; 
        return true; 
    case CHA: 
        Dest.DWord=pChar->CHA; 
        Dest.Type=pIntType; 
        return true; 
    case svMagic: 
        Dest.DWord=pChar->SaveMagic; 
        Dest.Type=pIntType; 
        return true; 
    case svFire: 
        Dest.DWord=pChar->SaveFire; 
        Dest.Type=pIntType; 
        return true; 
    case svCold: 
        Dest.DWord=pChar->SaveCold; 
        Dest.Type=pIntType; 
        return true; 
    case svPoison: 
        Dest.DWord=pChar->SavePoison; 
        Dest.Type=pIntType; 
        return true; 
    case svDisease: 
        Dest.DWord=pChar->SaveDisease; 
        Dest.Type=pIntType; 
        return true; 
    case CurrentWeight: 
        Dest.DWord=pChar->CurrWeight; 
        Dest.Type=pIntType; 
        return true; 
    case AAPointsSpent:
        Dest.DWord=GetCharInfo2()->AAPointsSpent;
        Dest.Type=pIntType;
        return true;
    case AAPointsTotal:
        Dest.DWord=GetCharInfo2()->AAPointsSpent+GetCharInfo2()->AAPoints;
        Dest.Type=pIntType;
        return true;
    case TributeActive:
        Dest.DWord=*pTributeActive;
        Dest.Type=pBoolType;
        return true; 
    case Running: 
        Dest.DWord=(*EQADDR_RUNWALKSTATE); 
        Dest.Type=pBoolType; 
        return true;
    case GroupSize:
        Dest.DWord= 0;
        {
            if(!pChar->pGroupInfo) return false;
            for(int i=1; i<6; i++)
                if (pChar->pGroupInfo->pMember[i]) Dest.DWord++;
            if (Dest.DWord) Dest.DWord++;
        }
        Dest.Type=pIntType;
        return true;    
    case TributeTimer:
        Dest.DWord=pChar->TributeTimer/60/100;
        Dest.Type=pTicksType;
        return true;
    case RadiantCrystals:
        Dest.DWord=pChar->RadiantCrystals;
        Dest.Type=pIntType;
        return true;
    case EbonCrystals:
        Dest.DWord=pChar->EbonCrystals;
        Dest.Type=pIntType;
        return true;
    case Shrouded:
        Dest.DWord=GetCharInfo2()->Shrouded;
        Dest.Type=pBoolType;
        return true;
    case AutoFire:
        Dest.DWord=gAutoFire;
        Dest.Type=pBoolType;
        return true;
    case Language:
        if(!ISINDEX()) 
            return false; 
        if(ISNUMBER())
        {
            nLang=GETNUMBER()-1;
            Dest.Ptr=pEverQuest->GetLangDesc(nLang);
            Dest.Type=pStringType;
            return true;
        }
        else
            nLang=GetLanguageIDByName(GETFIRST())-1;
        if(nLang<0 || nLang>=25)
            return false;
        Dest.DWord=nLang; 
        Dest.Type=pIntType; 
        return true; 
    case Aura:
        if(PAURAMGR pAura=(PAURAMGR)pAuraMgr)
        {
            if(pAura->NumAuras)
            {
                DataTypeTemp[0] = 0;
                PAURAS pAuras = (PAURAS)(*pAura->pAuraInfo);
                if(ISINDEX())
                {
                    DWORD n = 0;
                    if(ISNUMBER())
                    {
                        n = GETNUMBER();
                        if(n > pAura->NumAuras)
                            return false;
                        n--;
                        strcpy(DataTypeTemp, pAuras->Aura[n].Name);
                    }
                    else
                    {
                        for(n = 0; n < pAura->NumAuras; n++)
                        {
                            if(!stricmp(GETFIRST(), pAuras->Aura[n].Name))
                            {
                                strcpy(DataTypeTemp, pAuras->Aura[n].Name);
                            }
                        }
                    }
                }
                else
                {
                    strcpy(DataTypeTemp, pAuras->Aura[0].Name);
                }
                if(DataTypeTemp[0])
                {
                    Dest.Ptr = DataTypeTemp;
                    Dest.Type = pStringType;
                    return true;
                }
            }
        }
        return false;
    case LAMarkNPC:
        Dest.DWord=GetCharInfo()->ActiveAbilities.MarkNPC;
        Dest.Type=pIntType;
        return true;
    case LANPCHealth:
        Dest.DWord=GetCharInfo()->ActiveAbilities.NPCHealth;
        Dest.Type=pIntType;
        return true;
    case LADelegateMA:
        Dest.DWord=GetCharInfo()->ActiveAbilities.DelegateMA;
        Dest.Type=pIntType;
        return true;
    case LADelegateMarkNPC:
        Dest.DWord=GetCharInfo()->ActiveAbilities.DelegateMarkNPC;
        Dest.Type=pIntType;
        return true;
    case LAInspectBuffs:
        Dest.DWord=GetCharInfo()->ActiveAbilities.InspectBuffs;
        Dest.Type=pIntType;
        return true;
    case LASpellAwareness:
        Dest.DWord=GetCharInfo()->ActiveAbilities.SpellAwareness;
        Dest.Type=pIntType;
        return true;
    case LAOffenseEnhancement:
        Dest.DWord=GetCharInfo()->ActiveAbilities.OffenseEnhancement;
        Dest.Type=pIntType;
        return true;
    case LAManaEnhancement:
        Dest.DWord=GetCharInfo()->ActiveAbilities.ManaEnhancement;
        Dest.Type=pIntType;
        return true;
    case LAHealthEnhancement:
        Dest.DWord=GetCharInfo()->ActiveAbilities.HealthEnhancement;
        Dest.Type=pIntType;
        return true;
    case LAHealthRegen:
        Dest.DWord=GetCharInfo()->ActiveAbilities.HealthRegen;
        Dest.Type=pIntType;
        return true;
    case LAFindPathPC:
        Dest.DWord=GetCharInfo()->ActiveAbilities.FindPathPC;
        Dest.Type=pIntType;
        return true;
    case LAHoTT:
        Dest.DWord=GetCharInfo()->ActiveAbilities.HoTT;
        Dest.Type=pIntType;
        return true;
    case ActiveFavorCost:
        if(*pTributeActive)
        {
            Dest.Int=pEQMisc->GetActiveFavorCost();
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case CombatState:        
        switch(((PCPLAYERWND)pPlayerWnd)->CombatState)
        {
        case 0:
            if(((CXWnd*)pPlayerWnd)->GetChildItem("PW_CombatStateAnim"))
            {
                Dest.Ptr="COMBAT";
                break;
            }
            Dest.Ptr="NULL";
            break;
        case 1:
            Dest.Ptr="DEBUFFED";
            break;
        case 2:
            Dest.Ptr="COOLDOWN";
            break;
        case 3:
            Dest.Ptr="ACTIVE";
            break;
        case 4:
            Dest.Ptr="RESTING";
            break;
        default:
            Dest.Ptr="UNKNOWN";
            break;
        }
        Dest.Type=pStringType;
        return true;
    case svCorruption:
        Dest.DWord=pChar->SaveCorruption; 
        Dest.Type=pIntType; 
        return true;
    case svPrismatic:
        Dest.DWord=(pChar->SaveMagic + pChar->SaveFire + pChar->SaveCold + pChar->SavePoison + pChar->SaveDisease)/5;
        Dest.Type=pIntType;
        return true;
    case svChromatic:
        {
            unsigned int lowSave;
            lowSave = pChar->SaveMagic;
            if(lowSave > pChar->SaveFire)
                lowSave = pChar->SaveFire;
            if(lowSave > pChar->SaveCold)
                lowSave = pChar->SaveCold;
            if(lowSave > pChar->SavePoison)
                lowSave = pChar->SavePoison;
            if(lowSave > pChar->SaveDisease)
                lowSave = pChar->SaveDisease;
            Dest.DWord=lowSave;
            Dest.Type=pIntType;
            return true; 
        }
    case Doubloons:
        Dest.DWord=pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DOUBLOONS);
        Dest.Type=pIntType;
        return true;
    case Orux:
        Dest.DWord=pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ORUX);
        Dest.Type=pIntType;
        return true;
    case Phosphenes:
        Dest.DWord=pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHENES);
        Dest.Type=pIntType;
        return true;
    case Phosphites:
        Dest.DWord=pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHITES);
        Dest.Type=pIntType;
        return true;
    case Faycites:
        Dest.DWord=pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FAYCITES);
        Dest.Type=pIntType;
        return true;
    case Chronobines:
        Dest.DWord=pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CHRONOBINES);
        Dest.Type=pIntType;
        return true;
    case Fellowship:
        Dest.Ptr=&pChar->pSpawn->Fellowship;
        Dest.Type=pFellowshipType;
        return true;
    case Downtime:
        if(pChar->DowntimeStamp)
            Dest.DWord=((pChar->Downtime-(GetFastTime()-pChar->DowntimeStamp))/6)+1;
        else
            Dest.DWord=0;
        Dest.Type=pTicksType;
        return true;
    case Counters:
#if 0
        Dest.DWord=0;
        {
            for (unsigned long k=0; k<NUM_LONG_BUFFS ; k++)
                if(PSPELL pSpell = GetSpellByID(GetCharInfo2()->Buff[k].SpellID))
                    if(pSpell->SpellType == 0 && GetCharInfo2()->Buff[k].DamageAbsorbRemaining)
                        Dest.DWord += GetCharInfo2()->Buff[k].DamageAbsorbRemaining;
        }
        Dest.Type=pIntType;
        return true;
#endif
        return false;
    case Mercenary:
        if(pMercInfo->HaveMerc)
        {
            if(pMercInfo->MercState == 1)
                Dest.Ptr = "SUSPENDED";
            else if(pMercInfo->MercState == 5)
                Dest.Ptr = "ACTIVE";
            else
                Dest.Ptr = "UNKNOWN";
        }
        else
            Dest.Ptr = "NULL";
        Dest.Type = pStringType;
        return true;
    case XTarget:
        if(PXTARGETMGR xtm = pChar->pXTargetMgr)
        {
            DWORD n = 0;
            if(PXTARGETARRAY xta = xtm->pXTargetArray)
            {
                if(ISINDEX())
                {
                    if(ISNUMBER())
                    {
                        if(GETNUMBER() > 0 && GETNUMBER() <= (int)xtm->TargetSlots)
                        {
                            Dest.DWord = GETNUMBER() - 1;
                            Dest.Type = pXTargetType;
                            return true;
                        }
                    }
                    else
                    {
                        for(n = 0; n < xtm->TargetSlots; n++)
                        {
                            if(xta->pXTargetData[n].xTargetType && xta->pXTargetData[n].Unknown0x4 && !stricmp(GETFIRST(), xta->pXTargetData[n].Name))
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
                    for(n = 0; n < xtm->TargetSlots; n++)
                    {
                        if(xta->pXTargetData[n].xTargetType && xta->pXTargetData[n].Unknown0x4)
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
        Dest.DWord = pCharData1->TotalEffect(0xb, 1, 0, 1, 1);
        Dest.Type = pIntType;
        return true;
    case MercenaryStance:
        Dest.Ptr = "NULL";
        if(pMercInfo->HaveMerc)
        {
            for(DWORD n = 0; n < pMercInfo->NumStances; n++)
            {
                if(pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
                {
                    Dest.Ptr = pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, 24, 0);
                    break;
                }
            }
        }
        Dest.Type = pStringType;
        return true;
    case GemTimer:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            // number
            unsigned long nGem=GETNUMBER()-1;
            if (nGem<NUM_SPELL_GEMS)
            {
                if(GetCharInfo2()->MemorizedSpells[nGem] != 0xFFFFFFFF)
                {
                    Dest.DWord = (((GetSpellGemTimer(nGem) / 1000) + 5) / 6);
                    Dest.Type = pTicksType;
                    return true;
                }
            }
        }
        else
        {
            // name
            for (unsigned long nGem=0 ; nGem < NUM_SPELL_GEMS ; nGem++)
            {
                if (PSPELL pSpell=GetSpellByID(GetCharInfo2()->MemorizedSpells[nGem]))
                {
                    if (!stricmp(GETFIRST(),pSpell->Name))
                    {
                        Dest.DWord = (((GetSpellGemTimer(nGem) / 1000) + 5) / 6);
                        Dest.Type = pTicksType;
                        return true;
                    }
                }
            }
        }
        return false;
    case HaveExpansion:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            DWORD nExpansion = GETNUMBER();
            if (nExpansion > NUM_EXPANSIONS)
                return false;
            Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(nExpansion);
            Dest.Type = pBoolType;
            return true;
        }
        else
        {
            for (DWORD n = 0; n < NUM_EXPANSIONS; n++)
            {
                if (!stricmp(GETFIRST(), szExpansions[n]))
                {
                    Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(n + 1);
                    Dest.Type = pBoolType;
                    return true;
                }
            }
        }
        return false;
    case PctAggro:
        if(pAggroInfo)
        {
            Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
            Dest.Type = pIntType;
            return true;
        }
        return false;
    case SecondaryPctAggro:
        if(pAggroInfo)
        {
            Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
            Dest.Type = pIntType;
            return true;
        }
        return false;
    case SecondaryAggroPlayer:
        if(pAggroInfo && pAggroInfo->AggroSecondaryID)
        {
            Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
            Dest.Type = pSpawnType;
            return true;
        }
        return false;
    case AggroLock:
        if(pAggroInfo && pAggroInfo->AggroLockID)
        {
            Dest.Ptr = GetSpawnByID(pAggroInfo->AggroLockID);
            Dest.Type = pSpawnType;
            return true;
        }
    }
    return false;
#undef pChar
}

bool MQ2SpellType::GETMEMBER()
{
#define pSpell ((PSPELL)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2SpellType::FindMember(Member);
    if (!pMember)
        return false;

    switch((SpellMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=pSpell->ID;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=&pSpell->Name[0];
        Dest.Type=pStringType;
        return true;
    case Level:
        if (!ISINDEX() && GetCharInfo()->pSpawn)
        {
            Dest.DWord=pSpell->Level[GetCharInfo()->pSpawn->Class-1];
            Dest.Type=pIntType;
            return true;
        }
        else
        {
            if (ISNUMBER())
            {
                unsigned long nIndex=GETNUMBER()-1;
                Dest.DWord=pSpell->Level[nIndex];
                Dest.Type=pIntType;
                return true;
            }
        }
        return false;
    case Mana:
        Dest.DWord=pSpell->Mana;
        Dest.Type=pIntType;
        return true;
    case ResistAdj:
        Dest.DWord=pSpell->ResistAdj;
        Dest.Type=pIntType;
        return true;
    case Range:
        Dest.Float=pSpell->Range;
        Dest.Type=pFloatType;
        return true;
    case AERange:
        Dest.Float=pSpell->AERange;
        Dest.Type=pFloatType;
        return true;
    case PushBack:
        Dest.Float=pSpell->PushBack;
        Dest.Type=pFloatType;
        return true;
    case CastTime:
        Dest.Float=(FLOAT)pSpell->CastTime/1000;
        Dest.Type=pFloatType;
        return true;
    case RecoveryTime:
    case FizzleTime:
        Dest.Float=(FLOAT)pSpell->FizzleTime/1000;
        Dest.Type=pFloatType;
        return true;
    case RecastTime:
        Dest.Float=(FLOAT)pSpell->RecastTime/1000;
        Dest.Type=pFloatType;
        return true;
    case ResistType:
        switch(pSpell->Resist)
        {
        case 9:  Dest.Ptr="Corruption"; break;
        case 7:  Dest.Ptr="Prismatic"; break;
        case 6:    Dest.Ptr="Chromatic"; break;
        case 5:    Dest.Ptr="Disease"; break;
        case 4:    Dest.Ptr="Poison"; break;
        case 3:    Dest.Ptr="Cold"; break;
        case 2:    Dest.Ptr="Fire"; break;
        case 1:    Dest.Ptr="Magic"; break;
        case 0:    Dest.Ptr="Unresistable"; break;
        default: Dest.Ptr="Unknown"; break;
        }
        Dest.Type=pStringType;
        return true;
    case SpellType:
        switch(pSpell->SpellType)
        {
        case 2: Dest.Ptr="Beneficial(Group)"; break;
        case 1: Dest.Ptr="Beneficial"; break;
        case 0: Dest.Ptr="Detrimental"; break;
        default: Dest.Ptr="Unknown"; break;
        }
        Dest.Type=pStringType;
        return true;
    case TargetType:
        switch(pSpell->TargetType)
        {
        case 41: Dest.Ptr="Group v2"; break;
        case 40: Dest.Ptr="AE PC v2"; break;
        case 25: Dest.Ptr="AE Summoned"; break;
        case 24: Dest.Ptr="AE Undead"; break;
        case 20: Dest.Ptr="Targeted AE Tap"; break;
        case 18: Dest.Ptr="Uber Dragons"; break;
        case 17: Dest.Ptr="Uber Giants"; break;
        case 16: Dest.Ptr="Plant"; break;
        case 15: Dest.Ptr="Corpse"; break;
        case 14: Dest.Ptr="Pet"; break;
        case 13: Dest.Ptr="LifeTap"; break;
        case 11: Dest.Ptr="Summoned"; break;
        case 10: Dest.Ptr="Undead"; break;
        case  9: Dest.Ptr="Animal"; break;
        case  8: Dest.Ptr="Targeted AE"; break;
        case  6: Dest.Ptr="Self"; break;
        case  5: Dest.Ptr="Single"; break;
        case  4: Dest.Ptr="PB AE"; break;
        case  3: Dest.Ptr="Group v1"; break;
        case  2: Dest.Ptr="AE PC v1"; break;
        case  1: Dest.Ptr="Line of Sight"; break;
        default: Dest.Ptr="Unknown"; break;
        }
        Dest.Type=pStringType;
        return true;
    case Skill:
        Dest.Ptr=szSkills[pSpell->Skill];
        Dest.Type=pStringType;
        return true;
    case MyCastTime: 
        {
            DWORD n = 0;
            float mct = (FLOAT)(pCharData1->GetAACastingTimeModifier((EQ_Spell*)pSpell)+pCharData1->GetFocusCastingTimeModifier((EQ_Spell*)pSpell,(EQ_Equipment**)&n,0)+pSpell->CastTime)/1000.0f;
            if (mct < 0.50 * pSpell->CastTime/1000.0f)
                Dest.Float=(FLOAT)0.50 * (pSpell->CastTime/1000.0f);
            else
                Dest.Float=(FLOAT) mct;
        }
        Dest.Type=pFloatType; 
        return true;
    case Duration:
        Dest.DWord=GetSpellDuration(pSpell,(PSPAWNINFO)pCharSpawn);
        Dest.Type=pTicksType;
        return true;
    case CastOnYou: 
        Dest.Ptr=pSpell->CastOnYou; 
        Dest.Type=pStringType; 
        return true; 
    case CastOnAnother: 
        Dest.Ptr=pSpell->CastOnAnother; 
        Dest.Type=pStringType; 
        return true; 
    case WearOff: 
        Dest.Ptr=pSpell->WearOff; 
        Dest.Type=pStringType; 
        return true; 
    case CounterType:
        {
            Dest.Type=pStringType;
            int i;
            for (i=0; i<=11; i++){
                switch(pSpell->Attrib[i])
                {
                case 35:   
                    Dest.Ptr="Disease";
                    return true;
                case 36:
                    Dest.Ptr="Poison";
                    return true;
                case 116: 
                    Dest.Ptr="Curse";
                    return true;
                case 369: 
                    Dest.Ptr="Corruption"; 
                    return true;                
                }
            }
            Dest.Ptr="None";
            return true;
        }
    case CounterNumber:
        {
            Dest.Type=pIntType;
            int i;
            for (i=0; i<=11; i++){
                if ((pSpell->Attrib[i] == 35) || (pSpell->Attrib[i] == 36) || (pSpell->Attrib[i] == 116) || (pSpell->Attrib[i] == 369)){
                    Dest.DWord = (int)pSpell->Base[i];
                    return true;
                }
            }
            Dest.DWord = 0;
            return true;
        }
    case Stacks:
        {
            unsigned long buffduration;
            unsigned long duration=99999;
            if (ISNUMBER())
                duration=GETNUMBER();
            unsigned long nBuff;
            PCHARINFO2 pChar = GetCharInfo2();
            Dest.DWord = true;      
            Dest.Type = pBoolType;
            for (nBuff=0; nBuff<NUM_LONG_BUFFS; nBuff++){
                if (pChar->Buff[nBuff].SpellID>0) {
                    PSPELL tmpSpell = GetSpellByID(pChar->Buff[nBuff].SpellID);
                    buffduration = pChar->Buff[nBuff].Duration;
                    if (GetSpellDuration(tmpSpell,(PSPAWNINFO)pCharSpawn)>=0xFFFFFFFE) buffduration = 99999+1;
                    if (!BuffStackTest(pSpell, tmpSpell) || ((pSpell==tmpSpell) && (buffduration>duration))){
                        Dest.DWord = false;
                        return true;
                    }
                }
            }
            return true;
        }
    case StacksPet:
        {
            unsigned long petbuffduration;
            unsigned long duration=99999;
            if (ISNUMBER())
                duration=GETNUMBER();
            unsigned long nBuff;
            Dest.DWord = true;      
            Dest.Type = pBoolType;
            PEQPETINFOWINDOW pPet = ((PEQPETINFOWINDOW)pPetInfoWnd);
            for (nBuff=0; nBuff<NUM_BUFF_SLOTS; nBuff++){
                if (pPet->Buff[nBuff]>0 && !(pPet->Buff[nBuff]==0xFFFFFFFF || pPet->Buff[nBuff]==0)) {
                    PSPELL tmpSpell = GetSpellByID(pPet->Buff[nBuff]);
                    petbuffduration = ((pPet->BuffFadeETA[nBuff]+5999)/1000)/6;
                    if (GetSpellDuration(tmpSpell,(PSPAWNINFO)pCharSpawn)>=0xFFFFFFFE) petbuffduration = 99999+1;
                    if (!BuffStackTest(pSpell, tmpSpell) || ((pSpell==tmpSpell) && (petbuffduration>duration))){
                        Dest.DWord = false;
                        return true;
                    }
                }
            }
            return true;
        }
    case WillStack:
        {
            if (!ISINDEX()) 
                return false;
            PSPELL tmpSpell = NULL;
            if (ISNUMBER())   
                tmpSpell = GetSpellByID(GETNUMBER());
            else 
                tmpSpell = GetSpellByName(GETFIRST());
            if (!tmpSpell) 
                return false;
            Dest.Type = pBoolType;
            Dest.DWord = BuffStackTest(pSpell, tmpSpell);
            return true;
        }
    case MyRange:
        DWORD n = 0;
        Dest.Float=pSpell->Range+(float)pCharData1->GetFocusRangeModifier((EQ_Spell*)pSpell,(EQ_Equipment**)&n);
        Dest.Type=pFloatType;
        return true;
    }
    return false;
#undef pSpell
}

bool MQ2ItemType::GETMEMBER()
{
    DWORD N, cmp, tmp;
#define pItem ((PCONTENTS)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2ItemType::FindMember(Member);
    if (!pMember)
        return false;

    switch((ItemMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=GetItemFromContents(pItem)->ItemNumber;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=&GetItemFromContents(pItem)->Name[0];
        Dest.Type=pStringType;
        return true;
    case Lore:
        Dest.DWord=GetItemFromContents(pItem)->Lore;
        Dest.Type=pBoolType;
        return true;
    case NoDrop:
        Dest.DWord=!((EQ_Item*)pItem)->CanDrop(0,1);
        Dest.Type=pBoolType;
        return true;
    case NoRent:
        Dest.DWord=!GetItemFromContents(pItem)->NoRent;
        Dest.Type=pBoolType;
        return true;
    case Magic:
        Dest.DWord=((GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) && (GetItemFromContents(pItem)->Magic));
        Dest.Type=pBoolType;
        return true;
    case Value:
        Dest.DWord=GetItemFromContents(pItem)->Cost;
        Dest.Type=pIntType;
        return true;
    case Size:
        Dest.DWord=GetItemFromContents(pItem)->Size;
        Dest.Type=pIntType;
        return true;
    case SizeCapacity:
        Dest.DWord=GetItemFromContents(pItem)->SizeCapacity;
        Dest.Type=pIntType;
        return true;
    case Weight:
        Dest.DWord=GetItemFromContents(pItem)->Weight;
        Dest.Type=pIntType;
        return true;
    case Stack:
        if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable()!=1))
            Dest.DWord=1;
        else
            Dest.DWord=pItem->StackCount;
        Dest.Type=pIntType;
        return true;
    case Type:
        if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) 
        {
            if ((GetItemFromContents(pItem)->ItemType < MAX_ITEMTYPES) && (szItemTypes[GetItemFromContents(pItem)->ItemType] != NULL)) 
            {
                Dest.Ptr=szItemTypes[GetItemFromContents(pItem)->ItemType];
            } 
            else 
            {
                Dest.Ptr=&DataTypeTemp[0];
                sprintf(DataTypeTemp,"*UnknownType%d",GetItemFromContents(pItem)->ItemType);
            }
        }
        else if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK) 
        {
            if ((GetItemFromContents(pItem)->Combine < MAX_COMBINES) && (szCombineTypes[GetItemFromContents(pItem)->Combine] != NULL)) 
            {
                Dest.Ptr=szCombineTypes[GetItemFromContents(pItem)->Combine];
            } 
            else 
            {
                Dest.Ptr=&DataTypeTemp[0];
                sprintf(DataTypeTemp,"*UnknownCombine%d",GetItemFromContents(pItem)->Combine);
            }
        }
        else if (GetItemFromContents(pItem)->Type == ITEMTYPE_BOOK)
            Dest.Ptr="Book";
        Dest.Type=pStringType;
        return true;
    case Charges:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=pItem->Charges;
        Dest.Type=pIntType;
        return true;
    case LDoNTheme:
        Dest.Ptr=GetLDoNTheme(GetItemFromContents(pItem)->LDTheme);
        Dest.Type=pStringType;
        return true;
    case DMGBonusType:
        Dest.Ptr=szDmgBonusType[GetItemFromContents(pItem)->DmgBonusType];
        Dest.Type=pStringType;
        return true;
    case Container:
        if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
        {
            Dest.DWord=GetItemFromContents(pItem)->Slots;
        }
        else
            Dest.DWord=0;
        Dest.Type=pIntType;
        return true;
    case Items:
        if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK)
        {
            Dest.DWord=0;
            if (pItem->pContentsArray) {
                for (unsigned long N=0 ; N < GetItemFromContents(pItem)->Slots ; N++) {
                    if (pItem->pContentsArray->Contents[N])
                        Dest.DWord++;
                }
            }
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case Item:
        if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK && ISNUMBER())
        {
            unsigned long N=GETNUMBER();
            N--;
            if (N<GetItemFromContents(pItem)->Slots)
            {
                if (pItem->pContentsArray)
                if (Dest.Ptr=pItem->pContentsArray->Contents[N])
                {
                    Dest.Type=pItemType;
                    return true;
                }
            }
        } else if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL && ISNUMBER()) {
            unsigned long N=GETNUMBER();
            N--;
            Dest.Ptr=NULL;
            if (pItem->pContentsArray)
            switch (N)
            {
            case 0: 
                if (GetItemFromContents(pItem)->AugSlot1) Dest.Ptr=pItem->pContentsArray->Contents[N];   
                break;
            case 1: 
                if (GetItemFromContents(pItem)->AugSlot2) Dest.Ptr=pItem->pContentsArray->Contents[N];   
                break;
            case 2: 
                if (GetItemFromContents(pItem)->AugSlot3) Dest.Ptr=pItem->pContentsArray->Contents[N];   
                break;
            case 3: 
                if (GetItemFromContents(pItem)->AugSlot4) Dest.Ptr=pItem->pContentsArray->Contents[N];   
                break;
            case 4: 
                if (GetItemFromContents(pItem)->AugSlot5) Dest.Ptr=pItem->pContentsArray->Contents[N];   
                break;
            }
            if (Dest.Ptr) return true; 
        }
        return false;
    case Stackable:
        Dest.DWord=((EQ_Item*)pItem)->IsStackable();
        Dest.Type=pBoolType;
        return true;
    case InvSlot:
        Dest.Int=FindInvSlotForContents(pItem);
        if (Dest.Int>=0)
        {
            Dest.Type=pInvSlotType;
            return true;
        }
        return false;
    case BuyPrice:
        if (pActiveMerchant && pItem->MerchantSlot)
        {
            Dest.DWord=pItem->Price;
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case SellPrice:
        if (pActiveMerchant)
        {
            Dest.DWord=(DWORD)((FLOAT)GetItemFromContents(pItem)->Cost*(1.0f/((PEQMERCHWINDOW)pMerchantWnd)->Markup));
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case WornSlot:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count)
                    return false;
                cmp=GetItemFromContents(pItem)->EquipSlots;
                for (N = 0 ; N < 32 ; N++)
                {
                    if (cmp&(1<<N))
                    {
                        Count--;
                        if (Count==0)
                        {
                            Dest.DWord=N;
                            Dest.Type=pInvSlotType;
                            return true;
                        }
                    }
                }
            }
            else
            {
                // by name
                DWORD nInvSlot=ItemSlotMap[GETFIRST()];
                if ((nInvSlot || !stricmp(GETFIRST(),"charm")) && nInvSlot<32)
                {
                    Dest.DWord=(GetItemFromContents(pItem)->EquipSlots&(1<<nInvSlot));
                    Dest.Type=pBoolType;
                    return true;
                }
            }
        }
        return false;
    case WornSlots:
        {
            Dest.DWord=0;
            // count bits
            cmp=GetItemFromContents(pItem)->EquipSlots;
            for (N = 0 ; N < 32 ; N++)
            {
                if (cmp&(1<<N))
                    Dest.DWord++;
            }
            Dest.Type=pIntType;
            return true;
        }
    case CastTime:
        Dest.Float=(FLOAT)GetItemFromContents(pItem)->Clicky.CastTime/1000;
        Dest.Type=pFloatType;
        return true;
    case Spell: 
        if (Dest.Ptr=GetSpellByID(GetItemFromContents(pItem)->Clicky.SpellID)) 
        { 
            Dest.Type=pSpellType; 
            return true; 
        } 
        if (Dest.Ptr=GetSpellByID(GetItemFromContents(pItem)->Scroll.SpellID)) 
        { 
            Dest.Type=pSpellType; 
            return true; 
        } 
        if (Dest.Ptr=GetSpellByID(GetItemFromContents(pItem)->Proc.SpellID)) 
        { 
            Dest.Type=pSpellType; 
            return true; 
        } 
        if (Dest.Ptr=GetSpellByID(GetItemFromContents(pItem)->Focus.SpellID)) 
        { 
            Dest.Type=pSpellType; 
            return true; 
        } 
        if (Dest.Ptr=GetSpellByID(GetItemFromContents(pItem)->Worn.SpellID)) 
        { 
            Dest.Type=pSpellType; 
            return true; 
        } 
        return false; 
    case EffectType:
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
        else if (GetItemFromContents(pItem)->Scroll.SpellID!=-1) 
        { 
            Dest.Ptr="Spell Scroll"; 
        } 
        else if (GetItemFromContents(pItem)->Clicky.SpellID!=-1) 
        { 
            // code to detect must-be-worn etc here 
            switch (GetItemFromContents(pItem)->Clicky.EffectType) 
            { 
            case 4: 
                Dest.Ptr="Click Worn"; 
                break; 
            case 1: 
            case 5: 
                Dest.Ptr="Click Inventory"; 
                break; 
            default: 
                Dest.Ptr="Click Unknown"; 
            } 
        } 
        else if (GetItemFromContents(pItem)->Focus.SpellID!=-1 || GetItemFromContents(pItem)->Worn.SpellID!=-1) 
        { 
            Dest.Ptr="Worn"; 
        } 
        else if (GetItemFromContents(pItem)->Proc.SpellID!=-1) 
        { 
            Dest.Ptr="Combat"; 
        } 
        else 
        { 
            return false; 
        } 
        Dest.Type=pStringType; 
        return true; 
    case InstrumentMod:
        Dest.Float=((FLOAT)GetItemFromContents(pItem)->InstrumentMod)/10.0f;
        Dest.Type=pFloatType;
        return true;
    case Tribute:
        Dest.DWord=GetItemFromContents(pItem)->Favor;
        Dest.Type=pIntType;
        return true;
    case Attuneable:
        Dest.DWord=GetItemFromContents(pItem)->Attuneable;
        Dest.Type=pBoolType;
        return true;
    case Timer:
        if(GetItemFromContents(pItem)->Clicky.TimerID!=0xFFFFFFFF)
        {
            Dest.DWord=(GetItemTimer(pItem)+5)/6;
            Dest.Type=pTicksType;
            return true;
        }
        if (GetItemFromContents(pItem)->Clicky.SpellID!=-1)
        {
            Dest.DWord=0; // insta-clicky
            Dest.Type=pTicksType;
            return true;
        }
        return false;
    case ItemDelay:
        Dest.DWord=GetItemFromContents(pItem)->Delay;
        Dest.Type=pIntType;
        return true;
    case TimerReady:
        if(GetItemFromContents(pItem)->Clicky.TimerID!=0xFFFFFFFF)
        {
            Dest.DWord=GetItemTimer(pItem);
            Dest.Type=pIntType;
            return true;
        }
        if (GetItemFromContents(pItem)->Clicky.SpellID!=-1)
        {
            Dest.DWord=0; // insta-click or instant recast
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case StackSize:
        if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable()!=1))
            Dest.DWord=1;
        else
            Dest.DWord=GetItemFromContents(pItem)->StackSize;
        Dest.Type=pIntType;
        return true;
    case Stacks:
        {
            Dest.DWord=0;
            Dest.Type=pIntType;
            if (!((EQ_Item*)pItem)->IsStackable()) return true;
            for (DWORD slot=BAG_SLOT_START;slot<NUM_INV_SLOTS;slot++) 
            {
                if (PCONTENTS pTempItem = GetCharInfo2()->pInventoryArray->InventoryArray[slot])
                {
                    if (GetItemFromContents(pTempItem)->Type==ITEMTYPE_PACK && pTempItem->pContentsArray) 
                    {
                        for (DWORD pslot=0;pslot<(GetItemFromContents(pTempItem)->Slots);pslot++) 
                        {
                            if (pTempItem->pContentsArray->Contents[pslot])
                            {
                                if (PCONTENTS pSlotItem = pTempItem->pContentsArray->Contents[pslot])
                                {
                                    if (GetItemFromContents(pSlotItem)->ItemNumber==GetItemFromContents(pItem)->ItemNumber)
                                    {
                                        Dest.DWord++;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        if (GetItemFromContents(pTempItem)->ItemNumber==GetItemFromContents(pItem)->ItemNumber)
                        {
                            Dest.DWord++;
                        }
                    }
                }
            }
            return true;
        }
    case StackCount:
        {
            Dest.DWord=0;
            Dest.Type=pIntType;
            if (!((EQ_Item*)pItem)->IsStackable()) return true;
            for (DWORD slot=BAG_SLOT_START;slot<NUM_INV_SLOTS;slot++) 
            {
                if (PCONTENTS pTempItem = GetCharInfo2()->pInventoryArray->InventoryArray[slot])
                {
                    if (GetItemFromContents(pTempItem)->Type==ITEMTYPE_PACK && pTempItem->pContentsArray) 
                    {
                        for (DWORD pslot=0;pslot<(GetItemFromContents(pTempItem)->Slots);pslot++) 
                        {
                            if (pTempItem->pContentsArray->Contents[pslot])
                            {
                                if (PCONTENTS pSlotItem = pTempItem->pContentsArray->Contents[pslot])
                                {
                                    if (GetItemFromContents(pSlotItem)->ItemNumber==GetItemFromContents(pItem)->ItemNumber)
                                    {
                                        Dest.DWord+=pSlotItem->StackCount;
                                    }
                                }
                            }
                        }
                    }
                    else {
                        if (GetItemFromContents(pTempItem)->ItemNumber==GetItemFromContents(pItem)->ItemNumber)
                        {
                            Dest.DWord+=pTempItem->StackCount;
                        }
                    }
                }
            }
            return true;
        }
    case FreeStack:
        {
            Dest.DWord=0;
            Dest.Type=pIntType;
            if (!((EQ_Item*)pItem)->IsStackable()) return true;
            for (DWORD slot=BAG_SLOT_START;slot<NUM_INV_SLOTS;slot++)
            {
                if (PCONTENTS pTempItem = GetCharInfo2()->pInventoryArray->InventoryArray[slot])
                {
                    if (GetItemFromContents(pTempItem)->Type==ITEMTYPE_PACK && pTempItem->pContentsArray)
                    {
                        for (DWORD pslot=0;pslot<(GetItemFromContents(pTempItem)->Slots);pslot++) 
                        {
                            if (pTempItem->pContentsArray->Contents[pslot])
                            {
                                if (PCONTENTS pSlotItem = pTempItem->pContentsArray->Contents[pslot])
                                {
                                    if (GetItemFromContents(pSlotItem)->ItemNumber==GetItemFromContents(pItem)->ItemNumber)
                                    {
                                        Dest.DWord+=(GetItemFromContents(pSlotItem)->StackSize-pSlotItem->StackCount);
                                    }
                                }
                            }
                        }
                    }
                    else {
                        if (GetItemFromContents(pTempItem)->ItemNumber==GetItemFromContents(pItem)->ItemNumber)
                        {
                            Dest.DWord+=(GetItemFromContents(pTempItem)->StackSize-pTempItem->StackCount);
                        }
                    }
                }
            }
            return true;
        }
    case MerchQuantity:
        if (pActiveMerchant && pItem->MerchantSlot) {
            Dest.DWord=pItem->MerchantQuantity;
            Dest.Type=pIntType;
            return true;
        }
        return false;

    case Classes:
        Dest.DWord=0;
        // count bits
        cmp=GetItemFromContents(pItem)->Classes;
        for (N = 0 ; N < 16 ; N++)
        {
            if (cmp&(1<<N))
                Dest.DWord++;
        }
        Dest.Type=pIntType;
        return true;
    case Class:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count)
                    return false;
                cmp=GetItemFromContents(pItem)->Classes;
                for (N = 0 ; N < 16 ; N++)
                {
                    if (cmp&(1<<N))
                    {
                        Count--;
                        if (Count==0)
                        {
                            Dest.DWord=N+1;
                            Dest.Type=pClassType;
                            return true;
                        }
                    }
                }
            }
            else
            {
                // by name
                cmp=GetItemFromContents(pItem)->Classes;
                for (N = 0 ; N < 16 ; N++) {
                    if (cmp&(1<<N)) {
                        if (!stricmp(GETFIRST(), GetClassDesc(N+1)) ||
                            !stricmp(GETFIRST(), pEverQuest->GetClassThreeLetterCode(N+1))) {
                                Dest.DWord=N+1;
                                Dest.Type=pClassType;
                                return true;
                        }
                    }
                }
                return false;
            }
        }
        return false;
    case Races:
        Dest.DWord=0;
        // count bits
        cmp=GetItemFromContents(pItem)->Races;
        for (N = 0 ; N < 17 ; N++)
        {
            if (cmp&(1<<N))
                Dest.DWord++;
        }
        Dest.Type=pIntType;
        return true;
    case Race:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count)
                    return false;
                cmp=GetItemFromContents(pItem)->Races;
                for (N = 0 ; N < 17 ; N++)
                {
                    if (cmp&(1<<N))
                    {
                        Count--;
                        if (Count==0) {

                            Dest.DWord=N+1;
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
                            }
                            Dest.Type=pRaceType;
                            return true;
                        }
                    }
                }
            }
            else
            {
                // by name
                cmp=GetItemFromContents(pItem)->Races;
                for (N = 0 ; N < 17 ; N++) {
                    if (cmp&(1<<N)) {
                        tmp = N+1;
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
                        }
                        if (!stricmp(GETFIRST(), pEverQuest->GetRaceDesc(tmp))) {
                            Dest.DWord=tmp;
                            Dest.Type=pRaceType;
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return false;
    case Deities:
        Dest.DWord=0;
        // count bits
        cmp=GetItemFromContents(pItem)->Diety;
        for (N = 0 ; N < 15 ; N++)
        {
            if (cmp&(1<<N))
                Dest.DWord++;
        }
        Dest.Type=pIntType;
        return true;
    case Deity:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count)
                    return false;
                cmp=GetItemFromContents(pItem)->Diety;
                for (N = 0 ; N < 15 ; N++)
                {
                    if (cmp&(1<<N))
                    {
                        Count--;
                        if (Count==0)
                        {
                            Dest.DWord=N+200;
                            Dest.Type=pDeityType;
                            return true;
                        }
                    }
                }
            }
            else
            {
                // by name
                cmp=GetItemFromContents(pItem)->Diety;
                for (N = 0 ; N < 16 ; N++) {
                    if (cmp&(1<<N)) {
                        if (!stricmp(GETFIRST(), pEverQuest->GetDeityDesc(N+200))) {
                            Dest.DWord=N+200;
                            Dest.Type=pDeityType;
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return false;
    case RequiredLevel:
        Dest.DWord=GetItemFromContents(pItem)->RequiredLevel;
        Dest.Type=pIntType;
        return true;
    case Evolving:
        Dest.Ptr=pItem;
        Dest.Type=pEvolvingItemType;
        return true;
    case AC:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AC;
        Dest.Type=pIntType;
        return true;
    case HP:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HP;
        Dest.Type=pIntType;
        return true;
    case STR:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->STR;
        Dest.Type=pIntType;
        return true;
    case STA:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->STA;
        Dest.Type=pIntType;
        return true;
    case AGI:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->AGI;
        Dest.Type=pIntType;
        return true;
    case DEX:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->DEX;
        Dest.Type=pIntType;
        return true;
    case CHA:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->CHA;
        Dest.Type=pIntType;
        return true;
    case INT:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->INT;
        Dest.Type=pIntType;
        return true;
    case WIS:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->WIS;
        Dest.Type=pIntType;
        return true;
    case Mana:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->Mana;
        Dest.Type=pIntType;
        return true;
    case ManaRegen:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->ManaRegen;
        Dest.Type=pIntType;
        return true;
    case HPRegen:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HPRegen;
        Dest.Type=pIntType;
        return true;
    case Attack:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->Attack;
        Dest.Type=pIntType;
        return true;
    case svCold:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SvCold;
        Dest.Type=pIntType;
        return true;
    case svFire:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SvFire;
        Dest.Type=pIntType;
        return true;
    case svMagic:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SvMagic;
        Dest.Type=pIntType;
        return true;
    case svDisease:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SvDisease;
        Dest.Type=pIntType;
        return true;
    case svPoison:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SvPoison;
        Dest.Type=pIntType;
        return true;
    case svCorruption:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SvCorruption;
        Dest.Type=pIntType;
        return true;
    case Haste:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->Haste;
        Dest.Type=pIntType;
        return true;
    case DamShield:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->DamShield;
        Dest.Type=pIntType;
        return true;
    case AugType:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugType;
        Dest.Type=pIntType;
        return true;
    case AugRestrictions:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugRestrictions;
        Dest.Type=pIntType;
        return true;
    case AugSlot1:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugSlot1;
        Dest.Type=pIntType;
        return true;
    case AugSlot2:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugSlot2;
        Dest.Type=pIntType;
        return true;
    case AugSlot3:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugSlot3;
        Dest.Type=pIntType;
        return true;
    case AugSlot4:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugSlot4;
        Dest.Type=pIntType;
        return true;
    case AugSlot5:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->AugSlot5;
        Dest.Type=pIntType;
        return true;
    case Power:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=pItem->Power;
        Dest.Type=pIntType;
        return true;
    case MaxPower:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->MaxPower;
        Dest.Type=pIntType;
        return true;
    case Purity:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->Purity;
        Dest.Type=pIntType;
        return true;
    case Avoidance:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->Avoidance;
        Dest.Type=pIntType;
        return true;
    case SpellShield:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->SpellShield;
        Dest.Type=pIntType;
        return true;
    case StrikeThrough:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->StrikeThrough;
        Dest.Type=pIntType;
        return true;
    case StunResist:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->StunResist;
        Dest.Type=pIntType;
        return true;
    case Shielding:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->Shielding;
        Dest.Type=pIntType;
        return true;      
    case Accuracy:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->Accuracy;
        Dest.Type=pIntType;
        return true;
    case CombatEffects:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->CombatEffects;
        Dest.Type=pIntType;
        return true;
    case DoTShielding:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=(char)GetItemFromContents(pItem)->DoTShielding;
        Dest.Type=pIntType;
        return true;
    case HeroicSTR:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSTR;
        Dest.Type=pIntType;
        return true;
    case HeroicINT:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicINT;
        Dest.Type=pIntType;
        return true;
    case HeroicWIS:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicWIS;
        Dest.Type=pIntType;
        return true;
    case HeroicAGI:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicAGI;
        Dest.Type=pIntType;
        return true;
    case HeroicDEX:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicDEX;
        Dest.Type=pIntType;
        return true;
    case HeroicSTA:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSTA;
        Dest.Type=pIntType;
        return true;
    case HeroicCHA:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicCHA;
        Dest.Type=pIntType;
        return true;
    case HeroicSvMagic:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSvMagic;
        Dest.Type=pIntType;
        return true;
    case HeroicSvFire:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSvFire;
        Dest.Type=pIntType;
        return true;
    case HeroicSvCold:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSvCold;
        Dest.Type=pIntType;
        return true;
    case HeroicSvDisease:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSvDisease;
        Dest.Type=pIntType;
        return true;
    case HeroicSvPoison:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSvPoison;
        Dest.Type=pIntType;
        return true;
    case HeroicSvCorruption:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HeroicSvCorruption;
        Dest.Type=pIntType;
        return true;
    case EnduranceRegen:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->EnduranceRegen;
        Dest.Type=pIntType;
        return true;
    case HealAmount:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->HealAmount;
        Dest.Type=pIntType;
        return true;
    case Clairvoyance:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->Clairvoyance;
        Dest.Type=pIntType;
        return true;
    case DamageShieldMitigation:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->DamageShieldMitigation;
        Dest.Type=pIntType;
        return true;
    case SpellDamage:
        if (GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
            Dest.DWord=0;
        else
            Dest.DWord=GetItemFromContents(pItem)->SpellDamage;
        Dest.Type=pIntType;
        return true;
    case Augs:
        Dest.DWord = 0;
        Dest.Type=pIntType;
        if (GetItemFromContents(pItem)->Type == ITEMTYPE_NORMAL) {
            if (GetItemFromContents(pItem)->AugSlot5) Dest.DWord++;
            if (GetItemFromContents(pItem)->AugSlot4) Dest.DWord++;
            if (GetItemFromContents(pItem)->AugSlot3) Dest.DWord++;
            if (GetItemFromContents(pItem)->AugSlot2) Dest.DWord++;
            if (GetItemFromContents(pItem)->AugSlot1) Dest.DWord++;
            Dest.Type=pIntType;
        }
        return true;
    case Tradeskills:
        Dest.DWord=GetItemFromContents(pItem)->TradeSkills;
        Dest.Type=pBoolType;
        return true;

    }
    return false;
#undef pItem
}

bool MQ2WindowType::GETMEMBER()
{
#define pWnd ((PCSIDLWND)VarPtr.Ptr)
    PMQ2TYPEMEMBER pMember=MQ2WindowType::FindMember(Member);
    if (!pMember)
        return false;

    switch((WindowMembers)pMember->ID)
    {
    case Open:
        Dest.DWord=pWnd->dShow;
        Dest.Type=pBoolType;
        return true;
    case Child:
        if (Dest.Ptr=((CSidlScreenWnd*)VarPtr.Ptr)->GetChildItem(GETFIRST()))
        {
            Dest.Type=pWindowType;
            return true;
        }
        Dest.DWord=0;
        Dest.Type=pIntType;
        return true;
    case Parent:
        if (Dest.Ptr=pWnd->pParentWindow)
        {
            Dest.Type=pWindowType;
            return true;
        }
        Dest.DWord=0;
        Dest.Type=pIntType;
        return true;
    case FirstChild:
        if (Dest.Ptr=pWnd->pFirstChildWnd)
        {
            Dest.Type=pWindowType;
            return true;
        }
        Dest.DWord=0;
        Dest.Type=pIntType;
        return true;
    case Next:
        if (Dest.Ptr=pWnd->pNextSiblingWnd)
        {
            Dest.Type=pWindowType;
            return true;
        }
        Dest.DWord=0;
        Dest.Type=pIntType;
        return true;
    case VScrollMax:
        Dest.DWord=pWnd->VScrollMax;
        Dest.Type=pIntType;
        return true;
    case VScrollPos:
        Dest.DWord=pWnd->VScrollPos;
        Dest.Type=pIntType;
        return true;
    case VScrollPct:
        Dest.DWord=(pWnd->VScrollPos*100)/pWnd->VScrollMax;
        Dest.Type=pIntType;
        return true;
    case HScrollMax:
        Dest.DWord=pWnd->HScrollMax;
        Dest.Type=pIntType;
        return true;
    case HScrollPos:
        Dest.DWord=pWnd->HScrollPos;
        Dest.Type=pIntType;
        return true;
    case HScrollPct:
        Dest.DWord=(pWnd->HScrollPos*100)/pWnd->HScrollMax;
        Dest.Type=pIntType;
        return true;
    case Children:
        Dest.DWord=(DWORD)pWnd->pFirstChildWnd;
        Dest.Type=pBoolType;
        return true;
    case Siblings:
        Dest.DWord=(DWORD)pWnd->pNextSiblingWnd;
        Dest.Type=pBoolType;
        return true;
    case Minimized:
        Dest.DWord=pWnd->Minimized;
        Dest.Type=pBoolType;
        return true;
    case MouseOver:
        Dest.DWord=pWnd->MouseOver;
        Dest.Type=pBoolType;
        return true;
    case X:
        Dest.DWord=pWnd->Location.left;
        Dest.Type=pIntType;
        return true;
    case Y:
        Dest.DWord=pWnd->Location.top;
        Dest.Type=pIntType;
        return true;
    case Width:
        Dest.DWord=pWnd->Location.right-pWnd->Location.left;
        Dest.Type=pIntType;
        return true;
    case Height:
        Dest.DWord=pWnd->Location.bottom-pWnd->Location.top;
        Dest.Type=pIntType;
        return true;
    case BGColor:
        Dest.DWord=pWnd->BGColor.ARGB;
        Dest.Type=pArgbType;
        return true;
    case Text:
        if(((CXWnd*)pWnd)->GetType()==UI_STMLBox)
            GetCXStr(pWnd->SidlText,DataTypeTemp,MAX_STRING-1);
        else
            GetCXStr(pWnd->WindowText,DataTypeTemp,MAX_STRING-1);
        DataTypeTemp[MAX_STRING-1]='\0';
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case Tooltip:
        GetCXStr(pWnd->Tooltip,DataTypeTemp,MAX_STRING);
        Dest.Ptr=&DataTypeTemp[0];
        Dest.Type=pStringType;
        return true;
    case Checked:
        Dest.Int=pWnd->Checked;
        Dest.Type=pBoolType;
        return true;
    case Highlighted:
        Dest.Int=pWnd->Highlighted;
        Dest.Type=pBoolType;
        return true;
    case Enabled:
        Dest.Int=(pWnd->Enabled!=0);
        Dest.Type=pBoolType;
        return true;
    case Style:
        Dest.DWord=pWnd->WindowStyle;
        Dest.Type=pIntType;
        return true;
    case List:
        {
            int n = 0;
            if (((CXWnd*)pWnd)->GetType()==UI_Combobox)
                VarPtr.Ptr=pWnd->SidlText;
            else if (((CXWnd*)pWnd)->GetType()!=UI_Listbox)
                return false;
#ifndef ISXEQ
            if (PCHAR pComma=strchr(Index,',')) {
                n = atoi(pComma+1) - 1;
                if (n < 0) n=0;
                DebugSpew("List: index is %d\n", n);
                *pComma = '\0';
            }
#else
            if (argc==2) 
                n=atoi(argv[1]); 
            if (n<0) 
                n=0; 
#endif
            if (ISNUMBER())
            {
                unsigned long nIndex=GETNUMBER();
                if (!nIndex)
                    return false;
                nIndex--;
                CXStr Str;
                ((CListWnd*)pWnd)->GetItemText(&Str, nIndex, n);
                GetCXStr(Str.Ptr,DataTypeTemp,MAX_STRING);
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
                return true;
            }
            else
            {
                // name
                BOOL bEqual=false;
                CHAR Name[MAX_STRING]={0};
                if (GETFIRST()[0]=='=')
                {
                    bEqual=true;
                    strcpy(Name,&GETFIRST()[1]);
                }
                else
                    strcpy(Name,GETFIRST());
                strlwr(Name);
                unsigned long nIndex=0;
                while(1)
                {
                    CXStr Str;
                    ((CListWnd*)pWnd)->GetItemText(&Str, nIndex,n);
                    GetCXStr(Str.Ptr,DataTypeTemp,MAX_STRING);
                    if (DataTypeTemp[0]==0)
                        return false;

                    if (bEqual)
                    {
                        if (!stricmp(DataTypeTemp,Name))
                        {
                            Dest.DWord=nIndex+1;
                            Dest.Type=pIntType;
                            return true;
                        }
                    }
                    else
                    {
                        strlwr(DataTypeTemp);
                        if (strstr(DataTypeTemp,Name))
                        {
                            Dest.DWord=nIndex+1;
                            Dest.Type=pIntType;
                            return true;
                        }
                    }
                    nIndex++;
                } 
            }
            return false;
        }
    case Name:
        {
            if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
            {
                if (GetCXStr(pXMLData->Name.Ptr,DataTypeTemp,MAX_STRING))
                {
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
                    return true;
                }
            }
        }
        return false;
    case ScreenID:
        {
            if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
            {
                if (GetCXStr(pXMLData->ScreenID.Ptr,DataTypeTemp,MAX_STRING))
                {
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
                    return true;
                }
            }
        }
        return false;
    case Type:
        {
            if (CXMLData *pXMLData=((CXWnd*)pWnd)->GetXMLData())
            {
                if (GetCXStr(pXMLData->TypeName.Ptr,DataTypeTemp,MAX_STRING))
                {
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
                    return true;
                }
            }
        }
        return false;
    case Items:
        if (((CXWnd*)pWnd)->GetType()==UI_Listbox)
        {
            Dest.DWord=((CSidlScreenWnd*)pWnd)->Items;
            Dest.Type=pIntType;
        }
        else if (((CXWnd*)pWnd)->GetType()==UI_Combobox)
        {
            Dest.DWord=((CSidlScreenWnd*)pWnd->SidlText)->Items;
            Dest.Type=pIntType;
        }
        return true;
    case HisTradeReady:
        if(PTRADEWINDOW pTrade=(PTRADEWINDOW)pTradeWnd) {
            Dest.Int=pTrade->HisTradeReady;
            Dest.Type=pBoolType;
            return true;
        }
    case MyTradeReady:
        if(PTRADEWINDOW pTrade=(PTRADEWINDOW)pTradeWnd) {
            Dest.Int=pTrade->MyTradeReady;
            Dest.Type=pBoolType;
            return true;
        } 
    }

    return false;
#undef pWnd
}
bool MQ2CurrentZoneType::GETMEMBER()
{
#define pZone ((PZONEINFO)pZoneInfo)
    PMQ2TYPEMEMBER pMember=MQ2CurrentZoneType::FindMember(Member);
    if (!pMember)
        return false;

    //return pZoneType->GetMember(*(MQ2VARPTR*)&((PWORLDDATA)pWorldData)->ZoneArray[GetCharInfo()->zoneId],Member,Index,Dest);
    switch((CurrentZoneMembers)pMember->ID)
    {
    case ID:
        Dest.Int = GetCharInfo()->zoneId;
        Dest.Type=pIntType;
        return true; 
    case Name:
        Dest.Ptr=&pZone->LongName[0];
        Dest.Type=pStringType;
        return true;
    case ShortName:
        Dest.Ptr=&pZone->ShortName[0];
        Dest.Type=pStringType;
        return true;
    case Type:
        Dest.DWord=pZone->ZoneType;
        Dest.Type=pIntType;
        return true;
    case Gravity:
        Dest.Float=pZone->ZoneGravity;
        Dest.Type=pFloatType;
        return true;
    case SkyType:
        Dest.DWord=pZone->SkyType;
        Dest.Type=pIntType;
        return true;
#if 0
    case SafeN:
    case SafeY:
        Dest.Float=pZone->SafeYLoc;
        Dest.Type=pFloatType;
        return true;
    case SafeW:
    case SafeX:
        Dest.Float=pZone->SafeXLoc;
        Dest.Type=pFloatType;
        return true;
    case SafeU:
    case SafeZ:
        Dest.Float=pZone->SafeZLoc;
        Dest.Type=pFloatType;
        return true;
#endif
    case MinClip:
        Dest.Float=pZone->MinClip;
        Dest.Type=pFloatType;
        return true;
    case MaxClip:
        Dest.Float=pZone->MaxClip;
        Dest.Type=pFloatType;
        return true;
    }
    return false;
#undef pZone
}

bool MQ2ZoneType::GETMEMBER()
{
#define pZone ((PZONELIST)VarPtr.Ptr)
    PMQ2TYPEMEMBER pMember=MQ2ZoneType::FindMember(Member);
    if (!pMember)
        return false;
    switch((ZoneMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=&pZone->LongName[0];
        Dest.Type=pStringType;
        return true;
    case ShortName:
        Dest.Ptr=&pZone->ShortName[0];
        Dest.Type=pStringType;
        return true;
    case ID:
        Dest.Int=pZone->Id;
        Dest.Type=pIntType;
        return true;
    }
    return false;
#undef pZone
} 

bool MQ2BodyType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2BodyType::FindMember(Member);
    if (!pMember)
        return false;
    switch((BodyMembers)pMember->ID)
    {
    case ID:
        Dest.Ptr=VarPtr.Ptr;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=GetBodyTypeDesc(VarPtr.DWord);
        Dest.Type=pStringType;
        return true;
    }
    return false;
}
bool MQ2DeityType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2DeityType::FindMember(Member);
    if (!pMember)
        return false;
    switch((DeityMembers)pMember->ID)
    {
    case ID:
        Dest.Ptr=VarPtr.Ptr;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=pEverQuest->GetDeityDesc(VarPtr.DWord);
        Dest.Type=pStringType;
        return true;
    case Team:
        Dest.Ptr=szDeityTeam[GetDeityTeamByID(VarPtr.DWord)];
        Dest.Type=pStringType;
        return true;
    }
    return false;
}
bool MQ2ClassType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2ClassType::FindMember(Member);
    if (!pMember)
        return false;
    switch((ClassMembers)pMember->ID)
    {
    case ID:
        Dest.Ptr=VarPtr.Ptr;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=GetClassDesc(VarPtr.DWord);
        Dest.Type=pStringType;
        return true;
    case ShortName:
        Dest.Ptr=pEverQuest->GetClassThreeLetterCode(VarPtr.DWord);
        Dest.Type=pStringType;
        return true;
    case CanCast:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].CanCast;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case PureCaster:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].PureCaster;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case PetClass:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].PetClass;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case DruidType:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].DruidType;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case ShamanType:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].ShamanType;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case NecromancerType:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].NecroType;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case ClericType:
        if (VarPtr.DWord<=16)
        {
            Dest.DWord=ClassInfo[VarPtr.DWord].ClericType;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case HealerType:
        Dest.DWord=(VarPtr.DWord==2 || VarPtr.DWord==6 || VarPtr.DWord==10);
        Dest.Type=pBoolType;
        return true;
    }
    return false;
}
bool MQ2RaceType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2RaceType::FindMember(Member);
    if (!pMember)
        return false;
    switch((RaceMembers)pMember->ID)
    {
    case ID:
        Dest.Ptr=VarPtr.Ptr;
        Dest.Type=pIntType;
        return true;
    case Name:
        Dest.Ptr=pEverQuest->GetRaceDesc(VarPtr.DWord);
        Dest.Type=pStringType;
        return true;
    }
    return false;
}


bool MQ2SwitchType::GETMEMBER()
{
#define pSwitch ((PDOOR)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2SwitchType::FindMember(Member);
    if (!pMember)
        return false;
    switch((SwitchMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=pSwitch->ID;
        Dest.Type=pIntType;
        return true;
    case W:
    case X:
        Dest.Float=pSwitch->X;
        Dest.Type=pFloatType;
        return true;
    case N:
    case Y:
        Dest.Float=pSwitch->Y;
        Dest.Type=pFloatType;
        return true;
    case U:
    case Z:
        Dest.Float=pSwitch->Z;
        Dest.Type=pFloatType;
        return true;
    case DefaultW:
    case DefaultX:
        Dest.Float=pSwitch->DefaultX;
        Dest.Type=pFloatType;
        return true;
    case DefaultN:
    case DefaultY:
        Dest.Float=pSwitch->DefaultY;
        Dest.Type=pFloatType;
        return true;
    case DefaultU:
    case DefaultZ:
        Dest.Float=pSwitch->DefaultZ;
        Dest.Type=pFloatType;
        return true;
    case Heading:
        Dest.Float=pSwitch->Heading*0.703125f;
        Dest.Type=pHeadingType;
        return true;
    case DefaultHeading:
        Dest.Float=pSwitch->DefaultHeading*0.703125f;
        Dest.Type=pHeadingType;
        return true;
    case Open:
        Dest.DWord=((pSwitch->DefaultHeading != pSwitch->Heading) ||
            (pSwitch->DefaultZ != pSwitch->Z));
        Dest.Type=pBoolType;
        return true;
    case HeadingTo:
        Dest.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pSwitch->Y, pSwitch->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Dest.Float<0.0f) 
            Dest.Float += 360.0f;
        else if (Dest.Float>=360.0f) 
            Dest.Float -= 360.0f;
        Dest.Type=pHeadingType;
        return true;
    case Name:
        Dest.Ptr=&pSwitch->Name[0];
        Dest.Type=pStringType;
        return true;
    case Distance:
        Dest.Float=GetDistance(pSwitch->X,pSwitch->Y);
        Dest.Type=pFloatType;
        return true;
    case xLineOfSight:
        Dest.DWord=(CastRay(GetCharInfo()->pSpawn,pSwitch->Y,pSwitch->X,pSwitch->Z));
        Dest.Type=pBoolType;
        return true;
    }
    return false;
#undef pSwitch
}

bool MQ2GroundType::GETMEMBER()
{
#define pGround ((PGROUNDITEM)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2GroundType::FindMember(Member);
    if (!pMember)
        return false;
    switch((GroundMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=pGround->DropID;
        Dest.Type=pIntType;
        return true;
    case W:
    case X:
        Dest.Float=pGround->X;
        Dest.Type=pFloatType;
        return true;
    case N:
    case Y:
        Dest.Float=pGround->Y;
        Dest.Type=pFloatType;
        return true;
    case U:
    case Z:
        Dest.Float=pGround->Z;
        Dest.Type=pFloatType;
        return true;
    case Name:
        Dest.Ptr=&pGround->Name[0];
        Dest.Type=pStringType;
        return true;
    case Heading:
        Dest.Float=pGround->Heading*0.703125f;
        Dest.Type=pHeadingType;
        return true;
    case Distance:
        Dest.Float=GetDistance(pGround->X,pGround->Y);
        Dest.Type=pFloatType;
        return true;
    case HeadingTo:
        Dest.Float=(FLOAT)(atan2f(((PSPAWNINFO)pCharSpawn)->Y - pGround->Y, pGround->X - ((PSPAWNINFO)pCharSpawn)->X) * 180.0f / PI + 90.0f);
        if (Dest.Float<0.0f) 
            Dest.Float += 360.0f;
        else if (Dest.Float>=360.0f) 
            Dest.Float -= 360.0f;
        Dest.Type=pHeadingType;
        return true;
    case xLineOfSight:
        Dest.DWord=(CastRay(GetCharInfo()->pSpawn,pGround->Y,pGround->X,pGround->Z));
        Dest.Type=pBoolType;
        return true;
    }
    return false;
#undef pGround
}
bool MQ2MacroQuestType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2MacroQuestType::FindMember(Member);
    if (!pMember)
        return false;
    switch((MacroQuestMembers)pMember->ID)
    {
    case GameState:
        if (gGameState==GAMESTATE_CHARSELECT)
            Dest.Ptr="CHARSELECT";
        else if (gGameState==GAMESTATE_INGAME)
            Dest.Ptr="INGAME";
        else
            Dest.Ptr="UNKNOWN";
        Dest.Type=pStringType;
        return true;
    case LoginName:
        {
            if (PCHAR pTemp=GetLoginName())
            {
                strcpy(DataTypeTemp,pTemp);
                free(pTemp);
                Dest.Ptr=&DataTypeTemp[0];
                Dest.Type=pStringType;
                return true;
            }
        }
        return false;
    case Server:
        if (EQADDR_SERVERNAME[0])
        {
            Dest.Ptr=EQADDR_SERVERNAME;
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case LastCommand:
        if (szLastCommand[0])
        {
            Dest.Ptr=&szLastCommand[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case LastTell:
        if (EQADDR_LASTTELL[0])
        {
            Dest.Ptr=&EQADDR_LASTTELL[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case Error:
        if (gszLastNormalError[0])// QUIT SETTING THIS MANUALLY, USE MacroError, FatalError, ETC
        {
            Dest.Ptr=&gszLastNormalError[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case SyntaxError:
        if (gszLastSyntaxError[0])
        {
            Dest.Ptr=&gszLastSyntaxError[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case MQ2DataError:
        if (gszLastMQ2DataError[0])
        {
            Dest.Ptr=&gszLastMQ2DataError[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case Running:
        Dest.DWord=(DWORD)clock();
        Dest.Type=pIntType;
        return true;
    case MouseX:
        Dest.DWord=((PMOUSEINFO)EQADDR_MOUSE)->X;
        Dest.Type=pIntType;
        return true;
    case MouseY:
        Dest.DWord=((PMOUSEINFO)EQADDR_MOUSE)->Y;
        Dest.Type=pIntType;
        return true;
    case BuildDate: 
        SYSTEMTIME st; 
        HANDLE hFile; 
        WIN32_FIND_DATA FileData; 
        CHAR szBuffer[MAX_STRING]; 
        sprintf(szBuffer,"%s\\MQ2Main.dll", gszINIPath); 
        hFile = FindFirstFile(szBuffer, &FileData); 
        // Convert the creation time time to local time. 
        FileTimeToSystemTime(&FileData.ftLastWriteTime, &st); 
        FindClose(hFile); 
        sprintf(DataTypeTemp, "%d%d%d",st.wYear,st.wMonth,st.wDay); 
        Dest.Ptr=&DataTypeTemp[0]; 
        Dest.Type=pStringType; 
        return true; 
    case Ping:
        Dest.DWord=pConnection->Last;
        Dest.Type=pIntType;
        return true; 
    case ChatChannels:
        if(((PEVERQUEST)pEverQuest)->ChatService)
        {
            Dest.DWord=((PEVERQUEST)pEverQuest)->ChatService->ActiveChannels;
            Dest.Type=pIntType;
            return true;
        }
    case ChatChannel:
        if(((PEVERQUEST)pEverQuest)->ChatService)
        {
            PCHATSERVICE pChat=((PEVERQUEST)pEverQuest)->ChatService;
            if(ISNUMBER())
            {
                DWORD index=GETNUMBER();
                if(pChat->ActiveChannels && index && index<=pChat->ActiveChannels)
                {
                    strcpy(DataTypeTemp,pChat->ChannelList->ChannelName[index-1]);
                    Dest.Ptr=&DataTypeTemp[0];
                    Dest.Type=pStringType;
                    return true;
                }
            }
            else
            {
                CHAR Name[MAX_STRING]={0};
                strcpy(Name,GETFIRST());
                for(unsigned int i=0; i<pChat->ActiveChannels; i++)
                {
                    if(!stricmp(Name,pChat->ChannelList->ChannelName[i]))
                    {
                        Dest.DWord=1;
                        Dest.Type=pBoolType;
                        return true;
                    }
                }
            }
        }
    case ViewportX:
        Dest.DWord=ScreenX;
        Dest.Type=pIntType;
        return true;
    case ViewportY:
        Dest.DWord=ScreenY;
        Dest.Type=pIntType;
        return true;
    case ViewportXMax:
        Dest.DWord=ScreenXMax;
        Dest.Type=pIntType;
        return true;
    case ViewportYMax:
        Dest.DWord=ScreenYMax;
        Dest.Type=pIntType;
        return true;
    case ViewportXCenter:
        Dest.DWord=ScreenXMax/2;
        Dest.Type=pIntType;
        return true;
    case ViewportYCenter:
        Dest.DWord=ScreenYMax/2;
        Dest.Type=pIntType;
        return true;
    case LClickedObject:
        Dest.DWord=gLClickedObject;
        Dest.Type=pBoolType;
        return true;
    }
    return false;
}
#ifndef ISXEQ
bool MQ2TimeType::GETMEMBER()
{
#define pTime ((struct tm *)VarPtr.Ptr)
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2TimeType::FindMember(Member);
    if (!pMember)
        return false;
    switch((TimeMembers)pMember->ID)
    {
    case Hour:
        Dest.DWord=pTime->tm_hour;
        Dest.Type=pIntType;
        return true;
    case Minute:
        Dest.DWord=pTime->tm_min;
        Dest.Type=pIntType;
        return true;
    case Second:
        Dest.DWord=pTime->tm_sec;
        Dest.Type=pIntType;
        return true;
    case DayOfWeek:
        Dest.DWord=pTime->tm_wday+1;
        Dest.Type=pIntType;
        return true;
    case Day:
        Dest.DWord=pTime->tm_mday;
        Dest.Type=pIntType;
        return true;
    case Month:
        Dest.DWord=pTime->tm_mon+1;
        Dest.Type=pIntType;
        return true;
    case Year:
        Dest.DWord=pTime->tm_year+1900;
        Dest.Type=pIntType;
        return true;
    case Time12:
        {
            unsigned long Hour=pTime->tm_hour%12;
            if (!Hour)
                Hour=12;
            sprintf(DataTypeTemp,"%02d:%02d:%02d",Hour,pTime->tm_min, pTime->tm_sec);
            Dest.Ptr=&DataTypeTemp[0],
                Dest.Type=pStringType; 
        }
        return true;
    case Time24:
        sprintf(DataTypeTemp,"%02d:%02d:%02d",pTime->tm_hour,pTime->tm_min, pTime->tm_sec);
        Dest.Ptr=&DataTypeTemp[0],
            Dest.Type=pStringType; 
        return true;
    case Date:
        sprintf(DataTypeTemp,"%02d/%02d/%04d",pTime->tm_mon+1,pTime->tm_mday, pTime->tm_year+1900);
        Dest.Ptr=&DataTypeTemp[0],
            Dest.Type=pStringType; 
        return true;
    case Night:
        Dest.DWord=((pTime->tm_hour<7) || (pTime->tm_hour>18));
        Dest.Type=pBoolType;
        return true;
    case SecondsSinceMidnight:
        Dest.DWord=pTime->tm_hour*3600+pTime->tm_min*60+pTime->tm_sec;
        Dest.Type=pIntType;
        return true;
    }
    return false;
#undef pTime
}
#endif

bool MQ2HeadingType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2HeadingType::FindMember(Member);
    if (!pMember)
        return false;
    FLOAT Heading=360.0f-VarPtr.Float;
    switch((HeadingMembers)pMember->ID)
    {
    case Clock:
        {
            Dest.Int=((int)Heading)+15;
            Dest.DWord=((int)Dest.Int/30)%12;
            if (Dest.DWord==0)
                Dest.DWord=12;
            Dest.Type=pIntType;
            return true;
        }
    case Degrees:
        Dest.Float=Heading;
        Dest.Type=pFloatType;
        return true;
    case DegreesCCW:
        Dest.Float=VarPtr.Float;
        Dest.Type=pFloatType;
        return true;
    case ShortName:
        Dest.Ptr=szHeadingNormalShort[(INT)(Heading/ 22.5f + 0.5f)%16];
        Dest.Type=pStringType;
        return true;
    case Name:
        Dest.Ptr=szHeadingNormal[(INT)(Heading/ 22.5f + 0.5f)%16];
        Dest.Type=pStringType;
        return true;
    }
    return false;
}

bool MQ2CorpseType::GETMEMBER()
{
    if (!pActiveCorpse || !pLootWnd)
        return false;
#define pLoot ((PEQLOOTWINDOW)pLootWnd)
    PMQ2TYPEMEMBER pMember=MQ2CorpseType::FindMember(Member);
    if (!pMember)
    {
#ifndef ISXEQ
        return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveCorpse,Member,Index,Dest);
#else
        return pSpawnType->GetMember(*(LSVARPTR*)&pActiveCorpse,Member,argc,argv,Dest);
#endif
    }

    switch((CorpseMembers)pMember->ID)
    {
    case Open:
        Dest.DWord=1; // obviously, since we're this far 
        Dest.Type=pBoolType;
        return true;
    case Item:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                unsigned long nIndex=GETNUMBER()-1;
                if (nIndex<34 && pLoot->pInventoryArray)
                {
                    if (Dest.Ptr=pLoot->pInventoryArray->InventoryArray[nIndex])
                    {
                        Dest.Type=pItemType;
                        return true;
                    }
                }
            }
            else
            {
                // name
                BOOL bExact=FALSE;
                PCHAR pName=GETFIRST();
                if (*pName=='=')
                {
                    bExact=TRUE;
                    pName++;
                }
                strlwr(pName);
                CHAR Temp[MAX_STRING]={0};
                if (pLoot->pInventoryArray)
                for (unsigned long nIndex = 0 ; nIndex < 34 ; nIndex++)
                {
                    if (PCONTENTS pContents=pLoot->pInventoryArray->InventoryArray[nIndex])
                    {
                        if (bExact)
                        {
                            if (!stricmp(pName,GetItemFromContents(pContents)->Name))
                            {
                                Dest.Ptr=pContents;
                                Dest.Type=pItemType;
                                return true;
                            }
                        }
                        else
                        {
                            if(strstr(strlwr(strcpy(Temp,GetItemFromContents(pContents)->Name)),pName))
                            {
                                Dest.Ptr=pContents;
                                Dest.Type=pItemType;
                                return true;
                            }
                        }
                    }
                }

            }
        }
        return false;
    case Items:
        {
            Dest.DWord=0;
            if (pLoot->pInventoryArray)
            for (unsigned long N = 0 ; N < 31 ; N++)
            {
                if (pLoot->pInventoryArray->InventoryArray[N])
                    Dest.DWord++;
            }
            Dest.Type=pIntType;
            return true;
        }
    }
    return false;
#undef pLoot
}

bool MQ2MerchantType::GETMEMBER()
{
    if (!pActiveMerchant || !pMerchantWnd)
        return false;
#define pMerch ((PEQMERCHWINDOW)pMerchantWnd)
    PMQ2TYPEMEMBER pMember=MQ2MerchantType::FindMember(Member);
    if (!pMember)
    {
#ifndef ISXEQ
        return pSpawnType->GetMember(*(MQ2VARPTR*)&pActiveMerchant,Member,Index,Dest);
#else
        return pSpawnType->GetMember(*(LSVARPTR*)&pActiveMerchant,Member,argc,argv,Dest);
#endif
    }

    switch((MerchantMembers)pMember->ID)
    {
    case Open:
        Dest.DWord=1; // obviously, since we're this far ;)
        Dest.Type=pBoolType;
        return true;
    case Item:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                unsigned long nIndex=GETNUMBER()-1;
                if(!pMerch->pMerchOther->pMerchData->pMerchArray)
                    return false;
                if (nIndex < pMerch->pMerchOther->pMerchData->MerchSlots)
                {
                    if (Dest.Ptr=pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex])
                    {
                        Dest.Type=pItemType;
                        return true;
                    }
                }
            }
            else
            {
                // name
                BOOL bExact=FALSE;
                PCHAR pName=GETFIRST();
                if (*pName=='=')
                {
                    bExact=TRUE;
                    pName++;
                }
                strlwr(pName);
                CHAR Temp[MAX_STRING]={0};
                if(!pMerch->pMerchOther->pMerchData->pMerchArray)
                    return false;
                for (unsigned long nIndex = 0 ; nIndex < pMerch->pMerchOther->pMerchData->MerchSlots ; nIndex++)
                {
                    if (PCONTENTS pContents=pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex])
                    {
                        if (bExact)
                        {
                            if (!stricmp(pName,GetItemFromContents(pContents)->Name))
                            {
                                Dest.Ptr=pContents;
                                Dest.Type=pItemType;
                                return true;
                            }
                        }
                        else
                        {
                            if(strstr(strlwr(strcpy(Temp,GetItemFromContents(pContents)->Name)),pName))
                            {
                                Dest.Ptr=pContents;
                                Dest.Type=pItemType;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    case Items:
        {
            Dest.DWord=0;
            if(!pMerch->pMerchOther->pMerchData->pMerchArray)
                return false;
            for (unsigned long nIndex = 0 ; nIndex < pMerch->pMerchOther->pMerchData->MerchSlots ; nIndex++)
                if (pMerch->pMerchOther->pMerchData->pMerchArray->Array[nIndex])
                    Dest.DWord++;

            Dest.Type=pIntType;
            return true;
        }
    case Markup:
        Dest.Float=pMerch->Markup;
        Dest.Type=pFloatType;
        return true;
    case Full:
        {
            if(!pMerch->pMerchOther->pMerchData->pMerchArray)
                return false;
            Dest.DWord=1;
            if (pMerch->pMerchOther->pMerchData->MerchSlots < 0x80)  {
                Dest.DWord=0;
                Dest.Type=pBoolType;
                return true;
            }
            for (unsigned long N = 0 ; N < pMerch->pMerchOther->pMerchData->MerchSlots ; N++)
            {
                if (!pMerch->pMerchOther->pMerchData->pMerchArray->Array[N])
                {
                    Dest.DWord=0;
                    break;
                }
            }
            Dest.Type=pBoolType;
            return true;
        }
    }
    return false;
#undef pMerch
}

bool MQ2InvSlotType::GETMEMBER()
{
#define nInvSlot (VarPtr.Int)
    PMQ2TYPEMEMBER pMember=MQ2InvSlotType::FindMember(Member);
    if (!pMember)
        return false;
    switch((InvSlotMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=VarPtr.Int;
        Dest.Type=pIntType;
        return true;
    case Item:
#if 0
        if (CInvSlot *pSlot=pInvSlotMgr->FindInvSlot(nInvSlot))
        {
            if (((PEQINVSLOT)pSlot)->ppContents)
            {
                if (Dest.Ptr=*((PEQINVSLOT)pSlot)->ppContents)
                {
                    Dest.Type=pItemType;
                    return true;
                }
            }
        }
#endif
        if(Dest.Ptr = GetCharInfo2()->pInventoryArray->InventoryArray[nInvSlot])
        {
            Dest.Type = pItemType;
            return true;
        }
        else
        {
            PCHARINFO pCharInfo=(PCHARINFO)pCharData;
            if (nInvSlot>=262 && nInvSlot<342)
            {
                unsigned long nPack=(nInvSlot-262)/10;
                unsigned long nSlot=(nInvSlot-262)%10;
                if (PCONTENTS pPack=GetCharInfo2()->pInventoryArray->Inventory.Pack[nPack])
                    if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && nSlot<GetItemFromContents(pPack)->Slots)
                    {
                        if (pPack->pContentsArray)
                        if (Dest.Ptr=pPack->pContentsArray->Contents[nSlot])
                        {
                            Dest.Type=pItemType;
                            return true;
                        }
                    }
            } 
            else if (nInvSlot>=2032 && nInvSlot<2272)
            {
                unsigned long nPack=(nInvSlot-2032)/10;
                unsigned long nSlot=(nInvSlot-2)%10;
                if (PCONTENTS pPack=pCharInfo->pBankArray->Bank[nPack])
                    if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && nSlot<GetItemFromContents(pPack)->Slots)
                    {
                        if (pPack->pContentsArray)
                        if (Dest.Ptr=pPack->pContentsArray->Contents[nSlot])
                        {
                            Dest.Type=pItemType;
                            return true;
                        }
                    }
            }
            else if (nInvSlot>=2532 && nInvSlot<2552)
            {
                unsigned long nPack=24+((nInvSlot-2532)/10);
                unsigned long nSlot=(nInvSlot-2)%10;
                if (PCONTENTS pPack=pCharInfo->pBankArray->Bank[nPack])
                    if (GetItemFromContents(pPack)->Type==ITEMTYPE_PACK && nSlot<GetItemFromContents(pPack)->Slots)
                    {
                        if (pPack->pContentsArray)
                        if (Dest.Ptr=pPack->pContentsArray->Contents[nSlot])
                        {
                            Dest.Type=pItemType;
                            return true;
                        }
                    }
            }
            else if (nInvSlot>=2000 && nInvSlot<2024)
            {
                if (Dest.Ptr=pCharInfo->pBankArray->Bank[nInvSlot-2000])
                {
                    Dest.Type=pItemType;
                    return true;
                }
            }
            else if (nInvSlot==2500 || nInvSlot==2501)
            {
                if (Dest.Ptr=pCharInfo->pBankArray->Bank[nInvSlot-2500+24])
                {
                    Dest.Type=pItemType;
                    return true;
                }
            }
        }
        return false;
    case Pack:
        if (nInvSlot>=262 && nInvSlot<342)
        {
            Dest.DWord=((nInvSlot-262)/10)+BAG_SLOT_START;
            Dest.Type=pInvSlotType;
            return true;
        }
        else if (nInvSlot>=2032 && nInvSlot<2272)
        {
            Dest.DWord=((nInvSlot-2032)/10)+2000;
            Dest.Type=pInvSlotType;
            return true;
        }
        else if (nInvSlot>=2532 && nInvSlot<2552)
        {
            Dest.DWord=((nInvSlot-2532)/10)+2500;
            Dest.Type=pInvSlotType;
            return true;
        }
        return false;
    case Slot:
        {
            if (nInvSlot>=262 && nInvSlot<342)
            {
                Dest.DWord=(nInvSlot-262)%10;
                Dest.Type=pIntType;
                return true;
            }
            else if (nInvSlot>=2032 && nInvSlot<2272)
            {
                Dest.DWord=(nInvSlot-2032)%10;
                Dest.Type=pIntType;
                return true;
            }
            else if (nInvSlot>=2532 && nInvSlot<2552)
            {
                Dest.DWord=(nInvSlot-2532)%10;
                Dest.Type=pIntType;
                return true;
            }            
        }
        return false;
    case Name:
        if (nInvSlot>=0 && nInvSlot<NUM_INV_SLOTS) 
        {
            Dest.Ptr=szItemSlot[nInvSlot];
            Dest.Type=pStringType;
            return true;
        }
        if (nInvSlot>=BAG_SLOT_START && nInvSlot<NUM_INV_SLOTS)
        {
            sprintf(DataTypeTemp,"pack%d",nInvSlot-21);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=2000 && nInvSlot<2024)
        {
            sprintf(DataTypeTemp,"bank%d",nInvSlot-1999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=2500 && nInvSlot<2502)
        {
            sprintf(DataTypeTemp,"sharedbank%d",nInvSlot-2499);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=5000 && nInvSlot<5032)
        {
            sprintf(DataTypeTemp,"loot%d",nInvSlot-4999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=3000 && nInvSlot<3009)
        {
            sprintf(DataTypeTemp,"trade%d",nInvSlot-2999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=4000 && nInvSlot<4009)
        {
            sprintf(DataTypeTemp,"enviro%d",nInvSlot-3999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=6000 && nInvSlot<6080)
        {
            sprintf(DataTypeTemp,"merchant%d",nInvSlot-5999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=7000 && nInvSlot<7089)
        {
            sprintf(DataTypeTemp,"bazaar%d",nInvSlot-6999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        else if (nInvSlot>=8000 && nInvSlot<8031)
        {
            sprintf(DataTypeTemp,"inspect%d",nInvSlot-7999);
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }
        return false;
    }

    return false;
#undef nInvSlot
}



bool MQ2TimerType::GETMEMBER()
{
#define pTimer ((PMQTIMER)VarPtr.Ptr)
    if (!pTimer)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2TimerType::FindMember(Member);
    if (!pMember)
        return false;
    switch((TimerMembers)pMember->ID)
    {
    case Value:
        Dest.DWord=pTimer->Current;
        Dest.Type=pIntType;
        return true;
    case OriginalValue:
        Dest.DWord=pTimer->Original;
        Dest.Type=pIntType;
        return true;
    }
    return false;
#undef pTimer
}


bool MQ2SkillType::GETMEMBER()
{
    if (!VarPtr.Ptr)
        return false;
    PSKILL pSkill=*(PSKILL*)VarPtr.Ptr;
    if (!pSkill)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2SkillType::FindMember(Member);
    if (!pMember)
        return false;
    unsigned long nIndex=GetCharInfo2()->Class; 
    if(ISINDEX()) 
    { 
        if(ISNUMBER()) 
        { 
            // class by number 
            nIndex=GETNUMBER(); 
        } 
        else 
        { 
            // class by name or shortname 
            for (int N=1 ; N<17 ; N++) 
            { 
                if(
                    !stricmp(GETFIRST(), GetClassDesc(N)) ||
                    !stricmp(GETFIRST(), pEverQuest->GetClassThreeLetterCode(N))
                    ) 
                { 
                    nIndex=N; 
                    break; 
                } 
            } 
        } 
    } 

    switch((SkillMembers)pMember->ID)
    {
    case Name:
        if (Dest.Ptr=pStringTable->getString(pSkill->nName,0))
        {
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case ID:
        Dest.DWord=GetSkillIDFromName(pStringTable->getString(pSkill->nName,0));
        Dest.Type=pIntType;
        return true;
    case ReuseTime:
        Dest.DWord=pSkill->ReuseTimer;
        Dest.Type=pIntType;
        return true;
    case MinLevel:
        Dest.DWord=pSkill->MinLevel[nIndex]; 
        Dest.Type=pIntType;
        return true;
    case SkillCap:
        {
            DWORD i=GetSkillIDFromName(pStringTable->getString(pSkill->nName,0));
            Dest.DWord=pCSkillMgr->GetSkillCap((EQ_Character*)GetCharInfo(),GetCharInfo2()->Level,GetCharInfo2()->Class,i,true,true,true);
            Dest.Type=pIntType;
            return true;
        }
    case AltTimer:
        Dest.DWord=pSkill->AltTimer;
        Dest.Type=pIntType;
        return true;
    case Activated: 
        Dest.DWord=pSkill->Activated; 
        Dest.Type=pBoolType; 
        return true; 
    }
    return false;
}

bool MQ2AltAbilityType::ToString(MQ2VARPTR VarPtr, PCHAR Destination)
{
    if (!VarPtr.Ptr)
        return false;
    PALTABILITY pAbility=(PALTABILITY)VarPtr.Ptr;
    itoa(pAbility->PointsSpent, Destination,10);
    return true;
}

bool MQ2AltAbilityType::GETMEMBER()
{
    if (!VarPtr.Ptr)
        return false;
    PALTABILITY pAbility=(PALTABILITY)VarPtr.Ptr;

    PMQ2TYPEMEMBER pMember=MQ2AltAbilityType::FindMember(Member);
    if (!pMember)
        return false;
    switch((AltAbilityMembers)pMember->ID)
    { 
    case Name:
        if (Dest.Ptr= pCDBStr->GetString(pAbility->nName, 1, NULL)) 
        {
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case ShortName:
        if (Dest.Ptr=pStringTable->getString(pAbility->nShortName,0))
        {
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case Description:
        if (Dest.Ptr= pCDBStr->GetString(pAbility->nName, 4, NULL)) 
        {
            Dest.Type=pStringType;
            return true;
        }
        return false;
    case ID:
        Dest.DWord=pAbility->ID;
        Dest.Type=pIntType;
        return true;
    case ReuseTime:
        Dest.DWord=pAbility->ReuseTimer;
        Dest.Type=pIntType;
        return true;
    case MyReuseTime:
        Dest.DWord=pAltAdvManager->GetCalculatedTimer(pPCData,pAbility);
        Dest.Type=pIntType;
        return true;
    case MinLevel:
        Dest.DWord=pAbility->MinLevel;
        Dest.Type=pIntType;
        return true;
    case Cost:
        Dest.DWord=pAbility->Cost;
        Dest.Type=pIntType;
        return true;
    case Spell:
        if (Dest.Ptr=GetSpellByID(pAbility->SpellID))
        {
            Dest.Type=pSpellType;
            return true;
        }
        return false;
    case RequiresAbility:
        if (pAbility->RequiresAbility && *pAbility->RequiresAbility>0)
        {
            for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
            {
                if ( PALTABILITY tmppAbility=pAltAdvManager->GetAltAbility(nAbility))
                {
                    if (tmppAbility->ID == *pAbility->RequiresAbility )
                    {
                        Dest.Ptr=tmppAbility;
                        Dest.Type=pAltAbilityType;
                        return true;
                    }
                }
            }
        }
        DebugSpew("ability %d not found\n", *pAbility->RequiresAbility);
        return false;
    case RequiresAbilityPoints:
        if (pAbility->RequiresAbilityPoints) {
            Dest.DWord=*pAbility->RequiresAbilityPoints;
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case MaxRank:
        Dest.DWord=pAbility->MaxRank;
        Dest.Type=pIntType;
        return true;
    case AARankRequired:
        Dest.DWord=pAbility->AARankRequired;
        Dest.Type=pIntType;
        return true;
    case Type:
        Dest.DWord=pAbility->Type;
        Dest.Type=pIntType;
        return true;
    }
    return false;
}

bool MQ2GroupType::ToString(MQ2VARPTR VarPtr, PCHAR Destination)
{
    int nMembers=0;
    PCHARINFO pChar=GetCharInfo();
    if (!pChar->pGroupInfo) return false;
    for (int index=1;index<6;index++)
    {
        if (pChar->pGroupInfo->pMember[index])
            nMembers++;
    }
    itoa(nMembers,Destination,10);
    return true;
}

bool MQ2GroupType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2GroupType::FindMember(Member);
    PCHARINFO pChar=GetCharInfo();
    int i;
    if (!pMember || !pChar->pGroupInfo)
        return false;
    switch((GroupMembers)pMember->ID)
    {
    case xMember:
        if (!ISINDEX())
            return false;
        if (ISNUMBER())
        {
            // by number
            Dest.DWord=GETNUMBER();
            Dest.Type=pGroupMemberType;
            return true;
        }
        else
        {
            Dest.DWord=0;
            for (i=1;i<6;i++) 
                if (pChar->pGroupInfo->pMember[i])
                {
                    Dest.DWord++;
                    CHAR Name[MAX_STRING]={0};
                    GetCXStr(pChar->pGroupInfo->pMember[i]->pName,Name,MAX_STRING);
                    if (!stricmp(Name,GETFIRST()))
                    {
                        Dest.Type=pIntType;
                        return true;
                    }
                }
                if (!stricmp(pChar->pSpawn->Name,GETFIRST())) {
                    Dest.DWord=0;
                    Dest.Type=pIntType;
                    return true;
                }
                return false;
        }
        break;
    case Members:
        {
            Dest.DWord=0;
            for (i=1;i<6;i++) 
                if (pChar->pGroupInfo->pMember[i])
                    Dest.DWord++;
            Dest.Type=pIntType;
        }
        return true;
    case Leader:
        {
            if (!pChar->pGroupInfo->pLeader) return false;
            CHAR LeaderName[MAX_STRING]={0};
            GetCXStr(pChar->pGroupInfo->pLeader->pName,LeaderName,MAX_STRING);
            Dest.DWord=0;
            if (!stricmp(pChar->pSpawn->Name,LeaderName))
            {
                Dest.Type=pGroupMemberType;
                return true;
            }
            for (i=1;i<6;i++) 
            {
                if (pChar->pGroupInfo->pMember[i])
                {
                    Dest.DWord++;
                    CHAR Name[MAX_STRING]={0};
                    GetCXStr(pChar->pGroupInfo->pMember[i]->pName,Name,MAX_STRING);
                    if (!stricmp(Name,LeaderName))
                    {
                        Dest.Type=pGroupMemberType;
                        return true;
                    }
                }
            }
            if (!Dest.DWord)
            {
                // group has no members
                Dest.Type=pGroupMemberType;
                return true;
            }
        }
        break;
    case GroupSize:
        {
            Dest.DWord=0;
            for (i=1;i<6;i++) 
                if (pChar->pGroupInfo->pMember[i])
                    Dest.DWord++;
            if (Dest.DWord) Dest.DWord++;
            Dest.Type=pIntType;
        }
        return true;
    case MainTank:
        {
            Dest.DWord = 0;
            if(pChar->pGroupInfo->pMember[0]->MainTank)
            {
                Dest.Type = pGroupMemberType;
                return true;
            }
            for(i = 1; i < 6; i++)
            {
                if(pChar->pGroupInfo->pMember[i])
                {
                    Dest.DWord++;
                    if(pChar->pGroupInfo->pMember[i]->MainTank)
                    {
                        Dest.Type = pGroupMemberType;
                        return true;
                    }
                }
            }
        }
        return false;
    case MainAssist:
        {
            Dest.DWord = 0;
            if(pChar->pGroupInfo->pMember[0]->MainAssist)
            {
                Dest.Type = pGroupMemberType;
                return true;
            }
            for(i = 1; i < 6; i++)
            {
                if(pChar->pGroupInfo->pMember[i])
                {
                    Dest.DWord++;
                    if(pChar->pGroupInfo->pMember[i]->MainAssist)
                    {
                        Dest.Type = pGroupMemberType;
                        return true;
                    }
                }
            }
        }
        return false;
    case Puller:
        {
            Dest.DWord = 0;
            if(pChar->pGroupInfo->pMember[0]->Puller)
            {
                Dest.Type = pGroupMemberType;
                return true;
            }
            for(i = 1; i < 6; i++)
            {
                if(pChar->pGroupInfo->pMember[i])
                {
                    Dest.DWord++;
                    if(pChar->pGroupInfo->pMember[i]->Puller)
                    {
                        Dest.Type = pGroupMemberType;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool MQ2GroupMemberType::ToString(MQ2VARPTR VarPtr, PCHAR Destination)
{
    int i;
    if (unsigned long N=VarPtr.DWord)
    {
        if (N>5)
            return false;
        PCHARINFO pChar=GetCharInfo();
        if (!pChar->pGroupInfo) return false;
        for (i=1; i<6 ; i++)
        {
            if (pChar->pGroupInfo->pMember[i])
            {
                N--;
                if (N==0)
                {
                    CHAR Name[MAX_STRING]={0};
                    GetCXStr(pChar->pGroupInfo->pMember[i]->pName,Name,MAX_STRING);
                    strcpy(Destination,CleanupName(Name));
                    return true;
                }
            }
        }
    }
    else
    {
        strcpy(Destination,CleanupName(GetCharInfo()->pSpawn->Name));
        return true;
    }
    return false;
}

bool MQ2GroupMemberType::GETMEMBER()
{
    CHAR MemberName[MAX_STRING]={0};
    CHAR LeaderName[MAX_STRING]={0};
    PSPAWNINFO pGroupMember=0;
    PCHARINFO pChar=GetCharInfo();
    PGROUPMEMBER pGroupMemberData=0;
    int i;
    DWORD nMember = VarPtr.DWord;
    if (!pChar->pGroupInfo) return false;
    if (unsigned long N=nMember)
    {
        if (N>5)
            return false;
        for (i=1; i<6 ; i++)
        {
            if (pChar->pGroupInfo->pMember[i])
            {
                N--;
                if (N==0)
                {
                    GetCXStr(pChar->pGroupInfo->pMember[i]->pName,MemberName,MAX_STRING);
                    pGroupMember=pChar->pGroupInfo->pMember[i]->pSpawn;
                    pGroupMemberData=pChar->pGroupInfo->pMember[i];
                    break;
                }
            }
        }
        if (!MemberName)
            return false;
    }
    else
    {
        pGroupMember=pChar->pSpawn;
        strcpy(MemberName,pGroupMember->Name);
        pGroupMemberData=pChar->pGroupInfo->pMember[0];
    }
    PMQ2TYPEMEMBER pMember=MQ2GroupMemberType::FindMember(Member);
    if (!pMember)
    {
        if (!pGroupMember)
            return false;
#ifndef ISXEQ
        return pSpawnType->GetMember(*(MQ2VARPTR*)&pGroupMember,Member,Index,Dest);
#else
        return pSpawnType->GetMember(*(LSVARPTR*)&pGroupMember,Member,argc,argv,Dest);
#endif
    }

    switch((GroupMemberMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=CleanupName(MemberName);
        Dest.Type=pStringType;
        return true;
    case Leader:
        if (!pChar->pGroupInfo->pLeader) return false;
        GetCXStr(pChar->pGroupInfo->pLeader->pName,LeaderName,MAX_STRING);
        Dest.DWord=!stricmp(MemberName,LeaderName);
        Dest.Type=pBoolType;
        return true;
    case Spawn:
        if (Dest.Ptr=pGroupMember)
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case Level:
        if (pGroupMember)
        {
            Dest.DWord=pGroupMember->Level;
        Dest.Type=pIntType;
        return true;
        }
        else if (pGroupMemberData)
        {
            Dest.DWord=pGroupMemberData->Level;
            Dest.Type=pIntType;
            return true;
        }
        return false;
    case MainTank:
        if(pGroupMemberData)
        {
            Dest.DWord=pGroupMemberData->MainTank;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case MainAssist:
        if(pGroupMemberData)
        {
            Dest.DWord=pGroupMemberData->MainAssist;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case Puller:
        if(pGroupMemberData)
        {
            Dest.DWord=pGroupMemberData->Puller;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case Mercenary:
        if(pGroupMemberData)
        {
            Dest.DWord=pGroupMemberData->Mercenary;
            Dest.Type=pBoolType;
            return true;
        }
        return false;
    case PctAggro:
        if(pAggroInfo)
        {
            Dest.DWord = pAggroInfo->aggroData[nMember + 1].AggroPct;
            Dest.Type = pIntType;
            return true;
        }
    }
    return false;
}

bool MQ2RaidType::GETMEMBER()
{
    int i;
    if (!pRaid)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2RaidType::FindMember(Member);
    if (!pMember)
        return false;
    switch((RaidMembers)pMember->ID)
    {
    case Locked: 
        Dest.DWord=pRaid->Locked; 
        Dest.Type=pBoolType; 
        return true; 
    case Invited: 
        Dest.DWord=pRaid->Invited == 2; 
        Dest.Type=pBoolType; 
        return true; 
    case xMember:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count || Count>pRaid->RaidMemberCount)
                    return false;
                for (DWORD nMember = 0 ; nMember < 72 ; nMember++)
                {
                    if (pRaid->RaidMemberUsed[nMember])
                    {
                        Count--;
                        if (!Count)
                        {
                            Dest.DWord=nMember+1;
                            Dest.Type=pRaidMemberType;
                            return true;
                        }
                    }
                }
            }
            else
            {
                // by name
                for (DWORD nMember=0 ; nMember < 72 ; nMember++)
                {
                    if (pRaid->RaidMemberUsed[nMember] && !stricmp(pRaid->RaidMember[nMember].Name,GETFIRST()))
                    {
                        Dest.DWord=nMember+1;
                        Dest.Type=pRaidMemberType;
                        return true;
                    }
                }
            }
        }
        return false;
    case Members:
        Dest.DWord=pRaid->RaidMemberCount;
        Dest.Type=pIntType;
        return true;
    case Target:
        Dest.DWord=pRaid->RaidTarget+1;
        Dest.Type=pRaidMemberType;
        return true;
    case Leader:
        {
            for (DWORD nMember=0 ; nMember < 72 ; nMember++)
            {
                if (pRaid->RaidMemberUsed[nMember] && !stricmp(pRaid->RaidMember[nMember].Name,pRaid->RaidLeaderName))
                {
                    Dest.DWord=nMember+1;
                    Dest.Type=pRaidMemberType;
                    return true;
                }
            }
        }
        return false;
    case TotalLevels:
        Dest.DWord=pRaid->TotalRaidMemberLevels;
        Dest.Type=pIntType;
        return true;
    case AverageLevel:
        Dest.Float=(FLOAT)pRaid->TotalRaidMemberLevels/(FLOAT)pRaid->RaidMemberCount;
        Dest.Type=pFloatType;
        return true;
    case LootType:
        Dest.DWord=pRaid->LootType;
        Dest.Type=pIntType;
        return true;
    case Looters:
        {
            Dest.DWord=0;
            for (unsigned long N = 0 ; N < 0x13 ; N++)
            {
                if (pRaid->RaidLooters[N][0])
                    Dest.DWord++;
            }
            Dest.Type=pIntType;
            return true;
        }
    case Looter:
        if (ISINDEX())
        {
            if (ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count)
                    return 0;
                for (DWORD nLooter=0; nLooter<0x13 ; nLooter++)
                {
                    if (pRaid->RaidLooters[nLooter][0])
                    {
                        Count--;
                        if (Count==0)
                        {
                            Dest.Ptr=&pRaid->RaidLooters[nLooter][0];
                            Dest.Type=pStringType;
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
            for (i=0; i < 72; i++)
            {
                if (pRaid->RaidMemberUsed[i] && pRaid->RaidMember[i].RaidMainAssist)
                {
                    Dest.DWord=i+1;
                    Dest.Type=pRaidMemberType;
                    return true;
                }
            }
        }
        return false;
    }
    /**/
    return false;
}

bool MQ2RaidMemberType::GETMEMBER()
{
    DWORD nRaidMember=VarPtr.DWord-1;
    if (VarPtr.DWord>=72)
        return false;
    if (!pRaid->RaidMemberUsed[nRaidMember])
        return false;
    PEQRAIDMEMBER pRaidMember=&pRaid->RaidMember[nRaidMember];
    PMQ2TYPEMEMBER pMember=MQ2RaidMemberType::FindMember(Member);
    if (!pMember)
    {
        if(!GetSpawnByName(pRaidMember->Name))
            return false;
#ifndef ISXEQ
        return pSpawnType->GetMember(*(MQ2VARPTR*)GetSpawnByName(pRaidMember->Name),Member,Index,Dest);
#else
        return pSpawnType->GetMember(*(LSVARPTR*)GetSpawnByName(pRaidMember->Name),Member,argc,argv,Dest);
#endif
    }

    switch((RaidMemberMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=pRaidMember->Name;
        Dest.Type=pStringType;
        return true;
    case Group:
        Dest.DWord=pRaidMember->GroupNumber+1;
        Dest.Type=pIntType;
        return true;
    case GroupLeader:
        Dest.DWord=pRaidMember->GroupLeader;
        Dest.Type=pBoolType;
        return true;
    case RaidLeader:
        Dest.DWord=pRaidMember->RaidLeader;
        Dest.Type=pBoolType;
        return true;
    case Looter:
        if (pRaidMember->RaidLeader)
        {
            Dest.DWord=1;
            Dest.Type=pBoolType;
            return true;
        }
        if (pRaid->LootType==2)
        {
            Dest.DWord=pRaidMember->GroupLeader;
            Dest.Type=pBoolType;
            return true;
        }
        if (pRaid->LootType==3)
        {
            for (DWORD N = 0 ; N < 0x13 ; N++)
            {
                if (!stricmp(pRaid->RaidLooters[N],pRaidMember->Name))
                {
                    Dest.DWord=1;
                    Dest.Type=pBoolType;
                    return true;
                }
            }
        }
        Dest.DWord=0;
        Dest.Type=pBoolType;
        return true;
    case Spawn:
        if (Dest.Ptr=(PSPAWNINFO)GetSpawnByName(pRaidMember->Name))
        {
            Dest.Type=pSpawnType;
            return true;
        }
        return false;
    case Level:
        Dest.DWord=pRaidMember->nLevel;
        Dest.Type=pIntType;
        return true;
    case Class:
        Dest.DWord=pRaidMember->nClass;
        Dest.Type=pClassType;
        return true;
        /*
        {
        if (PSPAWNINFO pSpawn=(PSPAWNINFO)GetSpawnByName(pRaidMember->Name))
        {
        Dest.DWord=pSpawn->Class;
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
    PCONTENTS pItem=(PCONTENTS)VarPtr.Ptr;
    PMQ2TYPEMEMBER pMember=MQ2EvolvingItemType::FindMember(Member);
    if (!pMember)
        return false;
    switch((EvolvingItemMembers)pMember->ID)
    { 
    case ExpPct:
        Dest.Float=(FLOAT)pItem->EvolvingExpPct;
        Dest.Type=pFloatType;
        return true;
    case ExpOn:
        Dest.DWord=pItem->EvolvingExpOn;
        Dest.Type=pBoolType;
        return true;
    case Level:
        Dest.DWord=pItem->EvolvingCurrentLevel;
        Dest.Type=pIntType;
        return true;
    case MaxLevel:
        Dest.DWord=pItem->EvolvingMaxLevel;
        Dest.Type=pIntType;
        return true;
    }
    return false;
}

bool MQ2DynamicZoneType::GETMEMBER()
{
    if(!pDZMember)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2DynamicZoneType::FindMember(Member);
    if(!pMember)
        return false;
    switch((DynamicZoneMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=pDynamicZone->ExpeditionName;
        Dest.Type=pStringType;
        return true;
    case Members:
        {
            Dest.DWord=0;
            PDZMEMBER pDynamicZoneMember=pDynamicZone->pMemberList;
            while(pDynamicZoneMember)
            {
                Dest.DWord++;
                pDynamicZoneMember=pDynamicZoneMember->pNext;
            }
        }
        Dest.Type=pIntType;
        return true;
    case MaxMembers:
        Dest.DWord=pDynamicZone->MaxPlayers;
        Dest.Type=pIntType;
        return true;
    case xMember:
        if(ISINDEX())
        {
            PDZMEMBER pDynamicZoneMember=pDynamicZone->pMemberList;
            if(ISNUMBER())
            {
                DWORD Count=GETNUMBER();
                if (!Count || Count>pDynamicZone->MaxPlayers)
                    return false;
                Count--;
                for(DWORD i=0; pDynamicZoneMember!=0; i++)
                {
                    if(i==Count)
                    {
                        Dest.Ptr=pDynamicZoneMember;
                        Dest.Type=pDZMemberType;
                        return true;
                    }
                    pDynamicZoneMember=pDynamicZoneMember->pNext;
                }
            }
            else
            {
                while(pDynamicZoneMember)
                {
                    if(!stricmp(pDynamicZoneMember->Name,GETFIRST()))
                    {
                        Dest.Ptr=pDynamicZoneMember;
                        Dest.Type=pDZMemberType;
                        return true;
                    }
                    pDynamicZoneMember=pDynamicZoneMember->pNext;
                }
            }
        }
        return false;
    case Leader:
        {
            PDZMEMBER pDynamicZoneMember=pDynamicZone->pMemberList;
            for(DWORD i=0; i<pDynamicZone->MaxPlayers; i++)
            {
                if(!strcmp(pDynamicZoneMember->Name,(char*)instExpeditionLeader))
                {
                    Dest.Ptr=pDynamicZoneMember;
                    Dest.Type=pDZMemberType;
                    return true;
                }
                pDynamicZoneMember=pDynamicZoneMember->pNext;
            }
        }
    }
    return false;
}

bool MQ2DZMemberType::GETMEMBER()
{
    if(!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2DZMemberType::FindMember(Member);
    if(!pMember)
        return false;
    PDZMEMBER pDynamicZoneMember=(PDZMEMBER)VarPtr.Ptr;
    switch((DZMemberTypeMembers)pMember->ID)
    {
    case Name:
        Dest.Ptr=pDynamicZoneMember->Name;
        Dest.Type=pStringType;
        return true;
    case Status:
        switch(pDynamicZoneMember->Status)
        {
        case 0:
            Dest.Ptr="Unknown";
            break;
        case 1:
            Dest.Ptr="Online";
            break;
        case 2:
            Dest.Ptr="Offline";
            break;
        case 3:
            Dest.Ptr="In Dynamic Zone";
            break;
        case 4:
            Dest.Ptr="Link Dead";
            break;
        }
        Dest.Type=pStringType;
        return true;
    }
    return false;
}

bool MQ2FellowshipType::GETMEMBER()
{
    if(!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2FellowshipType::FindMember(Member);
    if(!pMember)
        return false;
    PFELLOWSHIPINFO pFellowship=(PFELLOWSHIPINFO)VarPtr.Ptr;
    switch((FellowshipTypeMembers)pMember->ID)
    {
    case ID:
        Dest.DWord=pFellowship->FellowshipID;
        Dest.Type=pIntType;
        return true;
    case Leader:
        Dest.Ptr=pFellowship->Leader;
        Dest.Type=pStringType;
        return true;
    case MotD:
        Dest.Ptr=pFellowship->MotD;
        Dest.Type=pStringType;
        return true;
    case Members:
        Dest.DWord=pFellowship->Members;
        Dest.Type=pIntType;
        return true;
    case xMember:
        if(ISINDEX())
        {
            if(ISNUMBER())
            {
                DWORD i=GETNUMBER();
                if(!i || i>pFellowship->Members)
                    return false;
                Dest.Ptr=&pFellowship->FellowshipMember[--i];
                Dest.Type=pFellowshipMemberType;
                return true;
            }
            else
            {
                for(DWORD i=0; i<pFellowship->Members; i++)
                {
                    if(!stricmp(pFellowship->FellowshipMember[i].Name,GETFIRST()))
                    {
                        Dest.Ptr=&pFellowship->FellowshipMember[i];
                        Dest.Type=pFellowshipMemberType;
                        return true;
                    }
                }
            }
        }
        return false;
    case CampfireDuration:
        if(((PSPAWNINFO)pCharSpawn)->CampfireTimestamp)
        {
            Dest.DWord=(((PSPAWNINFO)pCharSpawn)->CampfireTimestamp-GetFastTime())/6;
            Dest.Type=pTicksType;
            return true;
        }
        return false;
    case CampfireY:
        Dest.Float=((PSPAWNINFO)pCharSpawn)->CampfireY;
        Dest.Type=pFloatType;
        return true;
    case CampfireX:
        Dest.Float=((PSPAWNINFO)pCharSpawn)->CampfireX;
        Dest.Type=pFloatType;
        return true;
    case CampfireZ:
        Dest.Float=((PSPAWNINFO)pCharSpawn)->CampfireZ;
        Dest.Type=pFloatType;
        return true;
    case CampfireZone:
        if(((PSPAWNINFO)pCharSpawn)->CampfireZoneID)
        {
            Dest.Ptr=((PWORLDDATA)pWorldData)->ZoneArray[((PSPAWNINFO)pCharSpawn)->CampfireZoneID];
            Dest.Type=pZoneType;
            return true;
        }
        return false;
    case Campfire:
        Dest.Int=((PSPAWNINFO)pCharSpawn)->Campfire;
        Dest.Type=pBoolType;
        return true;
    }
    return false;
}

bool MQ2FellowshipMemberType::GETMEMBER()
{
    if(!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2FellowshipMemberType::FindMember(Member);
    if(!pMember)
        return false;
    PFELLOWSHIPMEMBER pFellowshipMember=(PFELLOWSHIPMEMBER)VarPtr.Ptr;
    switch((FMTypeMembers)pMember->ID)
    {
    case Zone:
        if(pFellowshipMember->ZoneID)
        {
            Dest.Ptr=((PWORLDDATA)pWorldData)->ZoneArray[pFellowshipMember->ZoneID];
            Dest.Type=pZoneType;
            return true;
        }
        return false;
    case Level:
        Dest.DWord=pFellowshipMember->Level;
        Dest.Type=pIntType;
        return true;
    case Class:
        Dest.DWord=pFellowshipMember->Class;
        Dest.Type=pClassType;
        return true;
    case LastOn:
        if(pFellowshipMember->LastOn)
        {
            Dest.DWord=(GetFastTime()-pFellowshipMember->LastOn)/6;
            Dest.Type=pTicksType;
            return true;
        }
        return false;
    case Name:
        Dest.Ptr=pFellowshipMember->Name;
        Dest.Type=pStringType;
        return true;
    }
    return false;
}

bool MQ2FriendsType::GETMEMBER()
{
    PMQ2TYPEMEMBER pMember=MQ2FriendsType::FindMember(Member);
    if (!pMember)
        return false;
    switch((FriendsMembers)pMember->ID)
    {
    case xFriend:
        if(ISINDEX() && ((PEVERQUEST)pEverQuest)->ChatService) {
            class CChatService *pChat=(class CChatService *) ((PEVERQUEST)pEverQuest)->ChatService;
            int i;
            if(ISNUMBER()) {
                i=GETNUMBER();
                if (i > pChat->GetNumberOfFriends())
                    return false;

                if (Dest.Ptr=pChat->GetFriendName(i-1)) {
                    Dest.Type=pStringType;
                    return true;
                }
            } else {
                for(i=0; i<pChat->GetNumberOfFriends(); i++) {
                    if(!stricmp(pChat->GetFriendName(i),GETFIRST())) {
                        Dest.DWord=1;
                        Dest.Type=pBoolType;
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
    DWORD i,j;
    if (!VarPtr.Ptr)
        return false;
    PMQ2TYPEMEMBER pMember=MQ2TargetType::FindMember(Member);
    if (!pMember)
    {
#ifndef ISXEQ
        return pSpawnType->GetMember(*(MQ2VARPTR*)&VarPtr.Ptr,Member,Index,Dest);
#else
        return pSpawnType->GetMember(*(LSVARPTR*)&VarPtr.Ptr,Member,argc,argv,Dest);
#endif
    }
    switch((TargetMembers)pMember->ID)
    {
    case Buff:
        if(!(((PCTARGETWND)pTargetWnd)->Type > 0))
            return false;
        if(ISINDEX())
        {
            if(ISNUMBER())
            {
                DWORD nBuff = GETNUMBER();
                if (!nBuff || nBuff >= NUM_BUFF_SLOTS)
                    return false;
                j = 0;
                for(i = 0; i < NUM_BUFF_SLOTS; i++)
                {
                    buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                    if(buffID && nBuff == ++j)
                    {
                        Dest.Ptr = GetSpellByID((DWORD)buffID);
                        Dest.Type = pSpellType;
                        return true;
                    }
                }
            }
            else
            {
                for(i = 0; i < NUM_BUFF_SLOTS; i++)
                {
                    buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                    if(buffID && !stricmp(GETFIRST(), GetSpellNameByID(buffID)))
                    {
                        Dest.Ptr = GetSpellByID((DWORD)buffID);
                        Dest.Type = pSpellType;
                        return true;
                    }
                }
            }
        }
        else
        {
            // return first buff
            for(i = 0; i < NUM_BUFF_SLOTS; i++)
            {
                buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                if(buffID)
                {
                    if(PSPELL pSpell = GetSpellByID(buffID))
                    {
                        strcpy(DataTypeTemp, pSpell->Name);
                        Dest.Ptr = &DataTypeTemp[0];
                        Dest.Type = pStringType;
                        return true;
                    }
                }
            }
        }
        return false;
    case BuffCount:
        if(!(((PCTARGETWND)pTargetWnd)->Type > 0))
            return false;
        Dest.DWord = 0;
        for(i = 0; i < NUM_BUFF_SLOTS; i++)
            if(((PCTARGETWND)pTargetWnd)->BuffSpellID[i])
                Dest.DWord++;
        Dest.Type = pIntType;
        return true;
    case BuffDuration:
        if(!(((PCTARGETWND)pTargetWnd)->Type > 0))
            return false;
        if(ISINDEX())
        {
            if(ISNUMBER())
            {
                DWORD nBuff = GETNUMBER();
                if (!nBuff || nBuff >= NUM_BUFF_SLOTS)
                    return false;
                j = 0;
                for(i = 0; i < NUM_BUFF_SLOTS; i++)
                {
                    buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                    if(buffID && nBuff == ++j)
                    {
                        Dest.DWord = ((((PCTARGETWND)pTargetWnd)->BuffTimer[i] / 1000) + 6) / 6;
                        Dest.Type = pTicksType;
                        return true;
                    }
                }
            }
            else
            {
                for(i = 0; i < NUM_BUFF_SLOTS; i++)
                {
                    buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                    if(buffID && !stricmp(GETFIRST(), GetSpellNameByID(buffID)))
                    {
                        Dest.DWord = ((((PCTARGETWND)pTargetWnd)->BuffTimer[i] / 1000) + 6) / 6;
                        Dest.Type = pTicksType;
                        return true;
                    }
                }
            }
        }
        else
        {
            // return first buff
            for(i = 0; i < NUM_BUFF_SLOTS; i++)
            {
                buffID = ((PCTARGETWND)pTargetWnd)->BuffSpellID[i];
                if(buffID)
                {
                    Dest.DWord = ((((PCTARGETWND)pTargetWnd)->BuffTimer[i] / 1000) + 6) / 6;
                    Dest.Type = pTicksType;
                    return true;
                }
            }
        }
        return false;
    case PctAggro:
        if(pAggroInfo)
        {
            Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
            Dest.Type = pIntType;
            return true;
        }
        return false;
    case SecondaryPctAggro:
        if(pAggroInfo)
        {
            Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
            Dest.Type = pIntType;
            return true;
        }
        return false;
    case SecondaryAggroPlayer:
        if(pAggroInfo && pAggroInfo->AggroSecondaryID)
        {
            Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
            Dest.Type = pSpawnType;
            return true;
        }
    }
    return false;
}

bool MQ2XTargetType::GETMEMBER()
{
    if(!GetCharInfo() || !GetCharInfo()->pXTargetMgr)
        return false;
    if(PMQ2TYPEMEMBER pMember=MQ2XTargetType::FindMember(Member))
    {
        XTARGETDATA xtd = GetCharInfo()->pXTargetMgr->pXTargetArray->pXTargetData[VarPtr.DWord];
        switch((xTargetMembers)pMember->ID)
        {
        case Type:
            {
                char *pType = GetXtargetType(xtd.xTargetType);
                Dest.Ptr = pType ? pType : "UNKNOWN";
                Dest.Type = pStringType;
                return true;
            }
        case ID:
            Dest.DWord = xtd.SpawnID;
            Dest.Type = pIntType;
            return true;
        case Name:
            Dest.Ptr = xtd.Name[0] ? xtd.Name : "NULL";
            Dest.Type = pStringType;
            return true;
        case PctAggro:
            if(pAggroInfo)
            {
                Dest.DWord = pAggroInfo->aggroData[AD_xTarget1 + VarPtr.DWord].AggroPct;
                Dest.Type = pIntType;
                return true;
            }
        }
    }
    return false;
};
            
