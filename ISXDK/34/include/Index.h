#pragma once
#ifndef __INDEX_H__
#define __INDEX_H__
#include <malloc.h>
//#include <afxmt.h>
#define foreach(variable,counter,index) for (size_t counter=0 ; counter < index.Size ; counter++) if (variable=index[counter])
#define foreachp(variable,counter,index) for (size_t counter=0 ; counter < index->Size ; counter++) if (variable=(*index)[counter])

template <class Any>
class CIndex
{
public:
	CIndex()
	{
		Size=0;
		List=0;
	}

	CIndex(size_t InitialSize)
	{
		Size=0;
		List=0;
		Resize(InitialSize);
	}

	~CIndex()
	{// user is responsible for managing elements
		CLock(&CS,true);
		if (List)
			Free(List);
		List=0;
		Size=0;
	}

	void Clear()
	{
		CLock(&CS,true);
		for (size_t i = 0 ; i < Size ; i++)
		{
			if (List[i])
			{
				List[i]=0;
			}
		}
	}

	void Cleanup()
	{
		CLock(&CS,true);
		for (size_t i = 0 ; i < Size ; i++)
		{
			if (List[i])
			{
				delete List[i];
				List[i]=0;
			}
		}
	}

	void Resize(size_t NewSize)
	{
		CLock(&CS,true);
		if (List)
		{
			if (NewSize>Size)
			{
				// because we want to zero out the unused portions, we wont use realloc
				Any *NewList=(Any*)Malloc(NewSize*sizeof(Any));
				memset(NewList,0,NewSize*sizeof(Any));
				memcpy(NewList,List,Size*sizeof(Any));
				Free(List);
				List=NewList;
				Size=NewSize;
			}
		}
		else
		{
			List=(Any*)Malloc(NewSize*sizeof(Any));
			memset(List,0,NewSize*sizeof(Any));
			Size=NewSize;
		}
	}

	// gets the next unused index, resizing if necessary
	inline size_t GetUnused()
	{
		CLock(&CS,true);
		size_t i;
		for ( i = 0 ; i < Size ; i++)
		{
			if (!List[i])
				return i;
		}
		Resize(Size+10);
		return i;
	}

	size_t Count()
	{
		CLock(&CS,true);
		size_t ret=0;
		for (size_t i = 0 ; i < Size ; i++)
		{
			if (List[i])
				ret++;
		}
		return ret;
	}

	virtual void *Malloc(size_t Size)
	{
		return malloc(Size);
	}
	virtual void Free(const void *mem)
	{
		free((void*)mem);
	}

	size_t Size;
	Any *List;

	inline Any& operator+=(Any& Value){return List[GetUnused()]=Value;}
	inline Any& operator[](size_t Index){return List[Index];}
	CSemaphore CS;
};




#endif

