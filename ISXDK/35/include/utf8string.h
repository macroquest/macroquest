//////////////////////////////////////////////////////////////////////////////////////////////
// utf8string is designed for Win32.  Under POSIX, this will simply be an ascii string, but still
// otherwise work.  
//
//////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2005 Lavish Software, LLC
// www.lavishsoft.com
//
// LICENSE INFORMATION
// This source file may be used and distributed, commercially or non-commercially, as long as 
// this original copyright and license information is left in tact in this source file.
///////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __LAVISH_UTF8STRING__
#define __LAVISH_UTF8STRING__

#ifdef ISXDK_VERSION
#ifndef WIN32
#define WIN32
#endif
#endif

#ifdef WIN32
//#include <mbstring.h>
//#include <tchar.h>
#include <malloc.h>
#else
#define strdup strdup
#define strcpy	strcpy
#define strncpy strncpy
#define _vstprintf vsprintf
#define _stprintf sprintf
#define strcmp strcmp
#define stricmp strcasecmp
#define strrchr strrchr
#define strlwr strlwr
#define strchr strchr
#endif

#ifdef __MINGW32_VERSION
#define MINGW_SUCKS
#undef strnbcnt
#define strnbcnt(x,y) _mbsnbcnt((const unsigned char *)x,y)
#undef strnccnt
#define strnccnt(x,y) _mbsnccnt((const unsigned char *)x,y)
#else
#endif

//#define strlen(utf8) strnbcnt(utf8,0x7fffffff)
#define strbytes strlen

#define UTF8STRING_INLINE inline
//#define UTF8STRING_INLINE

#ifdef UTF8STRING_POLYMORPH
#define UTF8STRING_VIRTUAL virtual
#define UTF8STRING_INHERIT : public utf8stringbase
#else
#define UTF8STRING_VIRTUAL UTF8STRING_INLINE
#define UTF8STRING_INHERITBASE
#endif

#ifdef UTF8STRING_FAST
#error Fast utf8string not yet implemented
#else

#ifdef UTF8STRING_POLYMORPH
class utf8stringbase
{
public:
	virtual unsigned int Bytes()=0;
	virtual unsigned int Characters()=0;
	virtual int Compare(const char *utf8)=0;
	virtual int CompareNoCase(const char *utf8)=0;
	virtual const char *Copy(const char *utf8)=0;
	virtual const char *GetString()=0;

	UTF8STRING_INLINE const char *c_str()
	{
		return GetString();
	}

	UTF8STRING_INLINE char *unsafe_str()
	{
		return (char*)GetString();
	}
};
#endif

class utf8stringcharholder UTF8STRING_INHERITBASE
{
public:
	UTF8STRING_INLINE char *GetProtectedText() const
	{
		return Text;
	}
protected:

	char *Text;
};

class constutf8string UTF8STRING_INHERITBASE
{
public:
	static size_t ByteCount(const char *utf8)
	{
		return strlen(utf8);
	}

	UTF8STRING_INLINE constutf8string(const char *utf8)
	{
		Initialize(utf8);
	}
	UTF8STRING_INLINE constutf8string(const constutf8string &utf8)
	{
		Initialize(utf8.GetString());
	}
	/* utf8stringbase */
	UTF8STRING_VIRTUAL size_t Bytes()
	{
		if (!nBytes)
			nBytes=strlen(Text);
		return nBytes;
	}
	UTF8STRING_VIRTUAL size_t Characters()
	{
		if (!nCharacters)
			nCharacters=strlen(Text);
		return nCharacters;
	}
	UTF8STRING_VIRTUAL int Compare(const char *utf8)
	{
		return strcmp(Text,utf8);
	}
	UTF8STRING_VIRTUAL int CompareNoCase(const char *utf8)
	{
		return _stricmp(Text,utf8);
	}
	UTF8STRING_VIRTUAL const char *Copy(const char *utf8)
	{
		Initialize(utf8);
		return utf8;
	}
	UTF8STRING_VIRTUAL const char *GetString() const
	{
		return Text;
	}
	
	/* operators */
	constutf8string& operator=(const constutf8string& utf8)
	{
		Text=utf8.GetText();
		nBytes=utf8.GetBytes();
		nCharacters=utf8.GetCharacters();
		return *this;
	}
	constutf8string& operator=(const char* utf8)
	{
		Initialize(utf8);
		return *this;
	}

	bool operator!( ) const
	{
		return false;
	}

	bool operator==(const utf8stringcharholder& str ) const
	{
		return _stricmp(Text,str.GetProtectedText())==0;
	}
	bool operator!=(const utf8stringcharholder& str ) const
	{
		return _stricmp(Text,str.GetProtectedText())!=0;
	}
	bool operator<(const utf8stringcharholder& str ) const
	{
		return _stricmp(Text,str.GetProtectedText())<0;
	}
	bool operator>(const utf8stringcharholder& str ) const
	{
		return _stricmp(Text,str.GetProtectedText())>0;
	}
	bool operator<=(const utf8stringcharholder& str ) const
	{
		return _stricmp(Text,str.GetProtectedText())<=0;
	}
	bool operator>=(const utf8stringcharholder& str ) const
	{
		return _stricmp(Text,str.GetProtectedText())>=0;
	}

	bool operator==(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())==0;
	}
	bool operator!=(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())!=0;
	}
	bool operator<(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())<0;
	}
	bool operator>(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())>0;
	}
	bool operator<=(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())<=0;
	}
	bool operator>=(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())>=0;
	}


	UTF8STRING_INLINE const char *c_str() const
	{
		return GetString();
	}

	UTF8STRING_INLINE char *unsafe_str() const
	{
		return (char*)GetString();
	}
protected:
	UTF8STRING_INLINE void Initialize(const char *utf8)
	{
		Text=utf8;
		nBytes=0;
		nCharacters=0;
	}
	UTF8STRING_INLINE const char *GetText() const
	{
		return Text;
	}
	UTF8STRING_INLINE size_t GetBytes() const
	{
		return nBytes;
	}
	UTF8STRING_INLINE size_t GetCharacters() const
	{
		return nCharacters;
	}
	const char *Text;
	size_t nBytes;
	size_t nCharacters;
};

class utf8string : public utf8stringcharholder
{
public:
	virtual void *Realloc(void *Block, size_t Size)
	{
		return realloc(Block,Size);
	}
	virtual void *Malloc(size_t Size)
	{
		return malloc(Size);
	}
	virtual void Free(void *Block)
	{
		free(Block);
	}

	static size_t ByteCount(const char *utf8)
	{
		return strlen(utf8);
	}

	UTF8STRING_INLINE utf8string()
	{
		InitializeEmpty();
	}
	UTF8STRING_INLINE utf8string(const char *utf8)
	{
		Initialize(utf8);
	}
	UTF8STRING_INLINE utf8string(const utf8string &utf8)
	{
		Initialize(utf8.GetString());
	}

	virtual ~utf8string()
	{
		ClearText();
	}

	/* utf8stringbase */
	UTF8STRING_VIRTUAL size_t Bytes() const
	{
		return nBytes;
	}
	UTF8STRING_VIRTUAL size_t Characters() const
	{
		return nCharacters;
	}
	UTF8STRING_VIRTUAL int Compare(const char *utf8)
	{
		return strcmp(Text,utf8);
	}
	UTF8STRING_VIRTUAL int CompareNoCase(const char *utf8)
	{
		return _stricmp(Text,utf8);
	}
	UTF8STRING_VIRTUAL const char *Copy(const char *utf8)
	{
		ClearText();
		Initialize(utf8);
		return Text;
	}
	UTF8STRING_VIRTUAL const char *GetString() const
	{
		return Text;
	}

	/* operators */
	utf8string& operator=(const utf8string& utf8)
	{
		Set(utf8);
		return *this;
	}
	utf8string& operator=(const char* utf8)
	{
		Set(utf8);
		return *this;
	}

	utf8string& operator+=(const char *utf8)
	{
		Append(utf8);
		return *this;
	}

	UTF8STRING_INLINE void Set(const utf8string& utf8)
	{
		size_t NewSize=utf8.nBytes+1;
		if (nAllocated<NewSize)
		{
			Resize(NewSize*2);
		}
		memcpy(Text,utf8.Text,NewSize);
		nBytes=utf8.nBytes;
		nCharacters=utf8.nCharacters;
	}

	UTF8STRING_INLINE void Set(const char *utf8)
	{
		nBytes=strlen(utf8);
		size_t NewSize=nBytes+1;
		if (nAllocated<NewSize)
		{
			Resize(NewSize*2);
		}
		nCharacters=nBytes;//strnccnt(utf8,0x7fffffff);
		memcpy(Text,utf8,NewSize);
	}

	UTF8STRING_INLINE void SetFromACP(const char *local)
	{
		int wclen=MultiByteToWideChar(CP_ACP,0,local,-1,0,0);
		if (wclen<=0)
		{
			Set("");
			return;
		}
		wchar_t *Temp=(wchar_t*)alloca(wclen*sizeof(wchar_t));
		MultiByteToWideChar(CP_ACP,0,local,-1,Temp,wclen);
		
		size_t NewSize=WideCharToMultiByte(CP_UTF8,0,Temp,-1,0,0,0,0);
		nBytes=NewSize-1;
		if (nAllocated<NewSize)
		{
			Resize(NewSize*2);
		}
		nCharacters=nBytes;
		WideCharToMultiByte(CP_UTF8,0,Temp,-1,Text,(int)nAllocated,0,0);
	}


	UTF8STRING_INLINE void Append(const utf8string& utf8)
	{
		size_t NewSize=nBytes+utf8.nBytes+1;
		if (nAllocated<NewSize)
		{
			Resize(NewSize*2);
		}
		memcpy(&Text[nBytes],utf8.Text,utf8.nBytes+1);
		nCharacters+=utf8.nCharacters;
		nBytes+=utf8.nBytes;
	}

	UTF8STRING_INLINE void Append(const char *utf8)
	{
		size_t AddBytes=strlen(utf8);
		size_t NewSize=nBytes+AddBytes+1;
		if (nAllocated<NewSize)
		{
			Resize(NewSize*2);
		}
		memcpy(&Text[nBytes],utf8,AddBytes+1);
		nCharacters+=strlen(utf8);
		nBytes+=AddBytes;
	}

	bool operator!( ) const
	{
		return false;
	}
	bool operator==(const utf8string& str ) const
	{
		return strcmp(Text,str.GetString())==0;
	}
	bool operator!=(const utf8string& str ) const
	{
		return strcmp(Text,str.GetString())!=0;
	}
	bool operator<(const utf8string& str ) const
	{
		return strcmp(Text,str.GetString())<0;
	}
	bool operator>(const utf8string& str ) const
	{
		return strcmp(Text,str.GetString())>0;
	}
	bool operator<=(const utf8string& str ) const
	{
		return strcmp(Text,str.GetString())<=0;
	}
	bool operator>=(const utf8string& str ) const
	{
		return strcmp(Text,str.GetString())>=0;
	}

	bool operator==(const constutf8string& str ) const
	{
		return strcmp(Text,str.GetString())==0;
	}
	bool operator!=(const constutf8string& str ) const
	{
		return strcmp(Text,str.GetString())!=0;
	}
	bool operator<(const constutf8string& str ) const
	{
		return strcmp(Text,str.GetString())<0;
	}
	bool operator>(const constutf8string& str ) const
	{
		return strcmp(Text,str.GetString())>0;
	}
	bool operator<=(const constutf8string& str ) const
	{
		return strcmp(Text,str.GetString())<=0;
	}
	bool operator>=(const constutf8string& str ) const
	{
		return strcmp(Text,str.GetString())>=0;
	}
	UTF8STRING_INLINE const char *c_str() const
	{
		return GetString();
	}

	UTF8STRING_INLINE char *unsafe_str() const
	{
		return (char*)GetString();
	}
protected:
	UTF8STRING_INLINE void ClearText()
	{
		Free(Text);
	}
	UTF8STRING_INLINE void Clear()
	{
		ClearText();
		nAllocated=0;
		nBytes=0;
		nCharacters=0;
	}
	UTF8STRING_INLINE void InitializeEmpty()
	{
		Text=(char*)Malloc(10);
		*(unsigned int*)Text=0;
//		Text[0]=0;
//		Text[1]=0;
		nAllocated=10;
		nBytes=0;
		nCharacters=0;
	}

	UTF8STRING_INLINE void Initialize(const char *utf8)
	{
		if (!utf8)
			utf8="";
		nCharacters=strlen(utf8);
		nBytes=nCharacters;
		//nBytes=strlen(utf8);
		nAllocated=nBytes+1;
		Text=(char*)Malloc(nAllocated);
		memcpy(Text,utf8,nAllocated);
	}

	UTF8STRING_INLINE void Resize(size_t newsize)
	{
		if (newsize>nAllocated)
		{
			Text=(char*)Realloc(Text,newsize);
			nAllocated=newsize;
		}
	}

	UTF8STRING_INLINE const char *GetText() const
	{
		return Text;
	}
	UTF8STRING_INLINE size_t GetAllocated() const
	{
		return nAllocated;
	}
	UTF8STRING_INLINE size_t GetBytes() const
	{
		return nBytes;
	}
	UTF8STRING_INLINE size_t GetCharacters() const
	{
		return nCharacters;
	}


	size_t nAllocated;
	size_t nBytes;
	size_t nCharacters;
};

class utf8stringnocase : public utf8string
{
public:
	UTF8STRING_INLINE utf8stringnocase():utf8string()
	{
	}
	UTF8STRING_INLINE utf8stringnocase(const char *utf8):utf8string(utf8)
	{
	}
	UTF8STRING_INLINE utf8stringnocase(const utf8stringnocase &utf8):utf8string(utf8.GetString())
	{
	}

	bool operator!( ) const
	{
		return false;
	}

	bool operator==(const utf8string& str ) const
	{
		return _stricmp(Text,str.GetString())==0;
	}
	bool operator!=(const utf8string& str ) const
	{
		return _stricmp(Text,str.GetString())!=0;
	}
	bool operator<(const utf8string& str ) const
	{
		return _stricmp(Text,str.GetString())<0;
	}
	bool operator>(const utf8string& str ) const
	{
		return _stricmp(Text,str.GetString())>0;
	}
	bool operator<=(const utf8string& str ) const
	{
		return _stricmp(Text,str.GetString())<=0;
	}
	bool operator>=(const utf8string& str ) const
	{
		return _stricmp(Text,str.GetString())>=0;
	}

	bool operator==(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())==0;
	}
	bool operator!=(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())!=0;
	}
	bool operator<(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())<0;
	}
	bool operator>(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())>0;
	}
	bool operator<=(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())<=0;
	}
	bool operator>=(const constutf8string& str ) const
	{
		return _stricmp(Text,str.GetString())>=0;
	}
/*
	UTF8STRING_INLINE const char *c_str() const
	{
		return GetString();
	}

	UTF8STRING_INLINE char *unsafe_str() const
	{
		return (char*)GetString();
	}
	/**/
};


#endif

#endif /* __LAVISH_UTF8STRING__ */
