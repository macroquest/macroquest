#pragma once
#include <map>
#include <set>
using namespace std;
#include <utf8string.h>
extern void InvalidatePersistentObject(unsigned int persistentClass, unsigned __int64 persistedValue);
extern unsigned int RegisterPersistentClass(const char *name);

// Symbiotic base class (e.g. iterator <-> iterator target)
class LSSym
{
public:
	virtual void RegisterSym(LSSym*)=0;
	virtual void UnregisterSym(LSSym*)=0;
};

class LSIterator : public LSSym
{
public:
	LSIterator(class LSIteratable *p_pIteratable, bool b_Reversible, bool b_Const, bool b_RandomAccess);
	virtual ~LSIterator();

	virtual void RegisterSym(LSSym*) {};
	virtual void UnregisterSym(LSSym*) {pIteratable=0;};

	virtual bool IsValid()=0;

	virtual bool First()=0;
	virtual bool Last()=0;
	virtual bool GetKey(LSOBJECT &Object)=0;
	virtual bool GetValue(LSOBJECT &Object)=0;
	virtual bool SetValue(int argc, char *argv[])=0;
	virtual bool Jump(int argc, char *argv[])=0;
	virtual bool Next()=0;
	virtual bool Previous()=0;


	virtual void Delete();

	virtual class LSIteratable *GetIteratable() {return (class LSIteratable *)pIteratable;}
	inline bool IsReversible() {return bReversible;}
	inline bool IsConstant() {return bConst;}
	inline bool IsRandomAccess() {return bRandomAccess;}
protected:
	LSSym *pIteratable;
	bool bReversible;
	bool bConst;
	bool bRandomAccess;
};

class LSIteratable : public LSSym
{
public:
	LSIteratable(const char *p_IteratableType);
	virtual ~LSIteratable();

	virtual void RegisterSym(LSSym* pSym)
	{
		Iterators.insert((LSIterator*)pSym);
	}
	virtual void UnregisterSym(LSSym* pSym)
	{
		Iterators.erase((LSIterator*)pSym);
	}

	virtual LSIterator *NewIterator(void *PassAlong)=0;

	bool NewIterator(LSOBJECT &Dest);

	inline const char *GetIteratableType() {return IteratableType;}

protected:
	set<LSIterator*> Iterators;
	const char *IteratableType;
};

class LSContainer : public LSIteratable
{
public:
	LSContainer(const char *p_IteratableType):LSIteratable(p_IteratableType)
	{
		RegisterContainer();
	}
	~LSContainer()
	{
		UnregisterContainer();
		InvalidatePersistentObject(RegisterPersistentClass("internal_pointer"), (unsigned __int64)this);
	}

	virtual bool Clear()=0;
	virtual size_t GetContainerSize() = 0;
	virtual size_t GetContainerUsed() = 0;

	virtual void OnRemoveType(class LSTypeDefinition *pType)=0;

	void RegisterContainer();
	void UnregisterContainer();
};

/* QUEUE */
struct LSQueueNode
{
	LSOBJECT Object;
	LSQueueNode *pNext;
};

class LSQueueIterator : public LSIterator
{
public:
	LSQueueIterator(class LSQueue *p_pQueue);

	virtual bool First();
	virtual bool Last();
	virtual bool IsValid();
	virtual bool GetKey(LSOBJECT &Object);
	virtual bool GetValue(LSOBJECT &Object);
	virtual bool SetValue(int argc, char *argv[]);
	virtual bool Jump(int argc, char *argv[]) {return false;}
	virtual bool Next();
	virtual bool Previous();

	LSQueueNode *pNode;
};

class LSQueue : public LSContainer
{
public:
	LSQueue(LSTypeDefinition *p_pType, const char *p_SubType) : LSContainer("queue")
	{
		Count=0;
		pHead=0;
		pTail=0;
		pType=p_pType;
		SubType=strdup(p_SubType);

	}
	virtual ~LSQueue()
	{
		Clear();		
		free((void*)SubType);
	}

	virtual bool Clear()
	{
		CLock L(&S,1);
		Count=0;

		for (set<LSIterator*>::iterator i = Iterators.begin() ; i!=Iterators.end() ; i++)
		{
			LSQueueIterator *pIterator=(LSQueueIterator *)(*i);
			pIterator->pNode=0;
		}

		while(pHead)
		{
			LSQueueNode *pNext=pHead->pNext;
			pType->FreeVariable(pHead->Object.GetObjectData());
			delete pHead;
			pHead=pNext;
		}
		pTail=0;
		return true;
	}

	virtual bool Queue(int argc, char *argv[])
	{
		CLock L(&S,1);
		LSOBJECTDATA Val;
		if (!pType->InitVariable(Val,SubType))
			return false;
		if (!pType->FromText(Val,argc,argv))
		{
			pType->FreeVariable(Val);
			return false;
		}
		LSQueueNode *pNode=new LSQueueNode;
		pNode->pNext=0;
		pNode->Object.SetObjectData(Val);
		pNode->Object.Type=pType;
		if (pTail)
		{
			pTail->pNext=pNode;
			pTail=pNode;
		}
		else
		{
			pHead=pTail=pNode;
		}
		Count++;
		return true;
	}

	virtual bool Dequeue()
	{
		CLock L(&S,1);
		if (!pHead)
			return false;

		for (set<LSIterator*>::iterator i = Iterators.begin() ; i!=Iterators.end() ; i++)
		{
			LSQueueIterator *pIterator=(LSQueueIterator *)(*i);
			if (pIterator->pNode==pHead)
				pIterator->pNode=0;
		}

		LSQueueNode *pNext=pHead->pNext;
		pType->FreeVariable(pHead->Object.GetObjectData());
		delete pHead;
		pHead=pNext;
		if (!pHead)
			pTail=0;
		Count--;
		return true;
	}

	virtual bool Peek(LSOBJECT &Object)
	{
		CLock L(&S,1);
		if (!pHead)
			return 0;
		Object.Ptr=&pHead->Object;
		Object.Type=GetLSVariableType();
		return true;
	}
	LSTypeDefinition *GetLSVariableType();

	inline size_t GetCount()	{ return Count; }

	virtual LSIterator *NewIterator(void *PassAlong);

	inline LSQueueNode *GetHead() { return pHead; }
	inline LSQueueNode *GetTail() {return pTail; }
	inline LSType *GetType() {return pType; }
	inline const char *GetSubType() {return SubType; }

	virtual size_t GetContainerSize() { return Count; }
	virtual size_t GetContainerUsed() { return Count; }
	virtual void OnRemoveType(class LSTypeDefinition *pType);

protected:
	LSType *pType;
	const char *SubType;

	LSQueueNode *pHead;
	LSQueueNode *pTail;

	size_t Count;
	CSemaphore S;
};

/* STACK */
struct LSStackNode
{
	LSOBJECT Object;
	LSStackNode *pNext;
};

class LSStackIterator : public LSIterator
{
public:
	LSStackIterator(class LSStack *p_pStack);

	virtual bool First();
	virtual bool Last();
	virtual bool IsValid();
	virtual bool GetKey(LSOBJECT &Object);
	virtual bool GetValue(LSOBJECT &Object);
	virtual bool SetValue(int argc, char *argv[]);
	virtual bool Jump(int argc, char *argv[]) {return false;}
	virtual bool Next();
	virtual bool Previous();

	LSStackNode *pNode;
};

class LSStack : public LSContainer
{
public:
	LSStack(LSTypeDefinition *p_pType, const char *p_SubType) : LSContainer("stack")
	{
		Count=0;
		pTop=0;
		pType=p_pType;
		SubType=strdup(p_SubType);

	}
	virtual ~LSStack()
	{
		Clear();	
		free((void*)SubType);
	}

	virtual bool Clear()
	{
		CLock L(&S,1);
		Count=0;
		for (set<LSIterator*>::iterator i = Iterators.begin() ; i!=Iterators.end() ; i++)
		{
			LSStackIterator *pIterator=(LSStackIterator *)(*i);
			pIterator->pNode=0;
		}


		while(pTop)
		{
			LSStackNode *pNext=pTop->pNext;
			pType->FreeVariable(pTop->Object.GetObjectData());
			delete pTop;
			pTop=pNext;
		}
		return true;
	}

	virtual bool Push(int argc, char *argv[])
	{
		CLock L(&S,1);
		LSOBJECTDATA Val;
		if (!pType->InitVariable(Val,SubType))
			return false;
		if (!pType->FromText(Val,argc,argv))
		{
			pType->FreeVariable(Val);
			return false;
		}
		LSStackNode *pNode=new LSStackNode;
		pNode->pNext=pTop;
		pNode->Object.SetObjectData(Val);
		pNode->Object.Type=pType;
		pTop=pNode;
		Count++;
		return true;
	}

	virtual bool Pop()
	{
		CLock L(&S,1);
		if (!pTop)
			return false;

		for (set<LSIterator*>::iterator i = Iterators.begin() ; i!=Iterators.end() ; i++)
		{
			LSStackIterator *pIterator=(LSStackIterator *)(*i);
			if (pIterator->pNode==pTop)
				pIterator->pNode=0;
		}

		LSStackNode *pNext=pTop->pNext;
		pType->FreeVariable(pTop->Object.GetObjectData());
		delete pTop;
		pTop=pNext;
		Count--;
		return true;
	}

	virtual bool Top(LSOBJECT &Object)
	{
		CLock L(&S,1);
		if (!pTop)
			return 0;
		Object.Ptr=&pTop->Object;
		Object.Type=GetLSVariableType();
		return true;
	}

	LSTypeDefinition *GetLSVariableType();


	inline size_t GetCount()	{ return Count; }

	virtual LSIterator *NewIterator(void *PassAlong);

	inline LSStackNode *GetTop() { return pTop; }
	inline LSType *GetType() {return pType; }
	inline const char *GetSubType() {return SubType; }

	virtual size_t GetContainerSize() { return Count; }
	virtual size_t GetContainerUsed() { return Count; }
	virtual void OnRemoveType(class LSTypeDefinition *pType);

protected:
	LSType *pType;
	const char *SubType;

	LSStackNode *pTop;

	size_t Count;
	CSemaphore S;


};

class LSObjectCollectionIterator;

/* COLLECTION (map) */
class LSObjectCollection : public LSContainer
{
public:
	LSObjectCollection(LSTypeDefinition *p_pType, const char *p_SubType): LSContainer("collection")
	{
		pType=p_pType;
		SubType=strdup(p_SubType);
	}
	virtual ~LSObjectCollection()
	{
		CLock L(&S,1);
		free((void*)SubType);
		map<utf8stringnocase,PLSOBJECT>::iterator i;
		for (i = Map.begin() ; i!=Map.end() ; i++)
		{
			pType->FreeVariable(i->second->GetObjectData());
			delete i->second;
		}
	}

	virtual bool Clear()
	{
		CLock L(&S,1);
		map<utf8stringnocase,PLSOBJECT>::iterator i;
		for (i = Map.begin() ; i!=Map.end() ; i++)
		{
			pType->FreeVariable(i->second->GetObjectData());
			delete i->second;
		}
		Map.clear();
		Iterator=Map.end();
		return true;
	}

	virtual bool GetFirstItem(LSOBJECT &Dest)
	{
		CLock L(&S,1);
		Iterator=Map.begin();
		if (Iterator!=Map.end())
		{
			Dest.Type=GetLSVariableType();
			Dest.Ptr=Iterator->second;
			return true;
		}
		return false;
	}

	virtual bool GetCurrentItem(LSOBJECT &Dest)
	{
		CLock L(&S,1);
		if (Iterator!=Map.end())
		{
			Dest.Type=GetLSVariableType();
			Dest.Ptr=Iterator->second;
			return true;
		}
		return false;
	}

	virtual bool GetNextItem(LSOBJECT &Dest)
	{
		CLock L(&S,1);
		Iterator++;
		if (Iterator!=Map.end())
		{
			Dest.Type=GetLSVariableType();
			Dest.Ptr=Iterator->second;
			return true;
		}
		return false;
	}

	virtual const char *GetFirstKey()
	{
		CLock L(&S,1);
		Iterator=Map.begin();
		if (Iterator!=Map.end())
		{
			return Iterator->first.c_str();
		}
		return false;
	}

	virtual const char * GetCurrentKey()
	{
		CLock L(&S,1);
		if (Iterator!=Map.end())
		{
			return Iterator->first.c_str();
		}
		return false;
	}

	virtual const char *GetNextKey()
	{
		CLock L(&S,1);
		Iterator++;
		if (Iterator!=Map.end())
		{
			return Iterator->first.c_str();
		}
		return false;
	}

	virtual bool GetItem(const char *Key, LSOBJECT &Dest)
	{
		CLock L(&S,1);
		map<utf8stringnocase,PLSOBJECT>::iterator i=Map.find(Key);
		if (i==Map.end())
			return false;
		Dest.Type=GetLSVariableType();
		Dest.Ptr=i->second;
		return true;
	}

/*
	bool CreateItem(const char *Key)
	{
		CLock L(&S,1);
		map<utf8stringnocase,PLSOBJECT>::iterator i=Map.find(Key);
		if (i==Map.end())
		{
			LSOBJECTDATA Val;
			if (pType->InitVariable(Val,SubType))
			{
				PLSOBJECT pObject=new LSOBJECT;
				pObject->VarPtr=Val;
				pObject->Type=pType;
				Map[Key]=pObject;
				return true;
			}
		}
		return false;
	}
/**/

	virtual void SetItem(const char *Key, LSOBJECTDATA &ObjectData)
	{
		CLock L(&S,1);
		map<utf8stringnocase,PLSOBJECT>::iterator i=Map.find(Key);
		if (i!=Map.end())
		{
			// existing
			PLSOBJECTDATA pVal = &i->second->GetObjectData();
			pType->FreeVariable(*pVal);

			i->second->SetObjectData(ObjectData);
		}
		else
		{
			PLSOBJECT pObject=new LSOBJECT;
			pObject->SetObjectData(ObjectData);
			pObject->Type=pType;
			Map[Key]=pObject;
		}
	}

	virtual void SetItem(const char *Key, int argc, char *argv[])
	{
		CLock L(&S,1);
		map<utf8stringnocase,PLSOBJECT>::iterator i=Map.find(Key);
		if (i!=Map.end())
		{
			// existing
			PLSOBJECTDATA pVal = &i->second->GetObjectData();
			pType->FreeVariable(*pVal);
			if (!pType->InitVariable(*pVal,SubType))
			{
				delete i->second;
				Map.erase(Key);
				return;
			}
			if (!pType->FromText(*pVal,argc,argv))
			{
				pType->FreeVariable(*pVal);
				delete i->second;
				Map.erase(Key);
				return;
			}
		}
		else
		{
			LSOBJECTDATA Val;
			if (!pType->InitVariable(Val,SubType))
				return;
			if (!pType->FromText(Val,argc,argv))
			{
				pType->FreeVariable(Val);
				return;
			}
			PLSOBJECT pObject=new LSOBJECT;
			pObject->SetObjectData(Val);
			pObject->Type=pType;
			Map[Key]=pObject;
		}
	}

	virtual void RemoveItem(const char *Key)
	{
		CLock L(&S,1);

		map<utf8stringnocase,PLSOBJECT>::iterator i=Map.find(Key);
		if (i!=Map.end())
		{
			InvalidateIterators(i);

			// delete existing
			pType->FreeVariable(i->second->GetObjectData());
			delete i->second;
			Map.erase(Key);
			Iterator=Map.end();
		}
	}

	LSTypeDefinition *GetLSVariableType();
	inline size_t GetCount() {return Map.size();}
	inline LSType *GetType() {return pType;}
	inline const char *GetSubType() {return SubType;}
	virtual LSIterator *NewIterator(void *PassAlong);
	void InvalidateIterators(map<utf8stringnocase,PLSOBJECT>::iterator &erasing);

	inline map<utf8stringnocase,PLSOBJECT> *GetMap() {return &Map;}

	virtual size_t GetContainerSize() {return GetCount();}
	virtual size_t GetContainerUsed() { return GetCount(); }
	virtual void OnRemoveType(class LSTypeDefinition *pType);

	unsigned int RemoveItemsByQuery(unsigned int ID, bool remove_MATCHES);// false removes NON-MATCHES

protected:
	LSType *pType;
	const char *SubType;
	map<utf8stringnocase,PLSOBJECT> Map;
	map<utf8stringnocase,PLSOBJECT>::iterator Iterator;
	CSemaphore S;
};

class LSObjectCollectionIterator : public LSIterator
{
public:
	LSObjectCollectionIterator(class LSObjectCollection *p_pCollection);

	virtual bool First();
	virtual bool Last();
	virtual bool IsValid();
	virtual bool GetKey(LSOBJECT &Object);
	virtual bool GetValue(LSOBJECT &Object);
	virtual bool SetValue(int argc, char *argv[]);
	virtual bool Jump(int argc, char *argv[]);
	virtual bool Next();
	virtual bool Previous();

	map<utf8stringnocase,PLSOBJECT>::iterator Iterator;
};


class LSSetIterator : public LSIterator
{
public:
	LSSetIterator(class LSSet *p_pCollection);

	virtual bool First();
	virtual bool Last();
	virtual bool IsValid();
	virtual bool GetKey(LSOBJECT &Object);
	virtual bool GetValue(LSOBJECT &Object);
	virtual bool SetValue(int argc, char *argv[]);
	virtual bool Jump(int argc, char *argv[]);
	virtual bool Next();
	virtual bool Previous();

	set<utf8stringnocase>::iterator Iterator;
};

/* SET */
class LSSet : public LSContainer
{
public:
	LSSet(): LSContainer("set")
	{
	}
	virtual ~LSSet()
	{
		CLock L(&S,1);
	}

	virtual bool Clear()
	{
		CLock L(&S,1);
		Set.clear();
		return true;
	}

	virtual bool Contains(const char *Key)
	{
		CLock L(&S,1);
		set<utf8stringnocase>::iterator i=Set.find(Key);
		return i!=Set.end();
	}

	virtual bool GetFirstKey(utf8string &Dest)
	{
		CLock L(&S,1);
		Iterator=Set.begin();
		if (Iterator!=Set.end())
		{
			Dest=*Iterator;
			return true;
		}
		return false;
	}

	virtual bool GetCurrentKey(utf8string &Dest)
	{
		CLock L(&S,1);
		if (Iterator!=Set.end())
		{
			Dest=*Iterator;
			return true;
		}
		return false;
	}

	virtual bool GetNextKey(utf8string &Dest)
	{
		CLock L(&S,1);
		Iterator++;
		if (Iterator!=Set.end())
		{
			Dest=*Iterator;
			return true;
		}
		return false;
	}

	virtual void AddItem(const char *Key)
	{
		CLock L(&S,1);
		Set.insert(Key);
	}

	virtual void RemoveItem(const char *Key)
	{
		CLock L(&S,1);
		Set.erase(Key);
	}

	inline size_t GetCount() {return Set.size();}
	virtual LSIterator *NewIterator(void *PassAlong);

	virtual size_t GetContainerSize() { return GetCount(); }
	virtual size_t GetContainerUsed() { return GetCount(); }
	virtual void OnRemoveType(class LSTypeDefinition *pType);

	inline set<utf8stringnocase> *GetSet() {return &Set;}

protected:
	set<utf8stringnocase> Set;
	set<utf8stringnocase>::iterator Iterator;
	CSemaphore S;
};

class LSIndexIterator : public LSIterator
{
public:
	LSIndexIterator(class LSIndex *p_pIndex);

	bool AdvanceToValid();
	bool ReverseToValid();

	virtual bool First();
	virtual bool Last();
	virtual bool IsValid();
	virtual bool GetKey(LSOBJECT &Object);
	virtual bool GetValue(LSOBJECT &Object);
	virtual bool SetValue(int argc, char *argv[]);
	virtual bool Jump(int argc, char *argv[]);
	virtual bool Next();
	virtual bool Previous();

	size_t N;
};

class LSIndex : public LSContainer
{
public:
	LSIndex(class LSTypeDefinition *p_pType, const char *p_SubType);
	virtual ~LSIndex();

	virtual unsigned int AddItem(int argc, char *argv[]);
	virtual bool SetItem(size_t N, int argc, char *argv[]);
	virtual bool DeleteItem(size_t N);
	virtual unsigned int GetNextItem(size_t N);

	virtual bool Resize(size_t NewSize);
	virtual bool Swap(size_t A, size_t B);
	virtual bool Move(size_t From, size_t To);

	virtual bool Clear();
	virtual void Collapse();
	bool ShiftUp(size_t From, size_t count);

	virtual PLSOBJECT GetItem(size_t N);

	inline class LSTypeDefinition *GetType()
	{
		return pType;
	}
	inline const char *GetSubType()
	{
		return SubType;
	}

	inline unsigned int AddItem(const char *value)
	{
		char *argv[]={(char*)value};
		return AddItem(1,argv);
	}
	unsigned int AddItem(LSOBJECTDATA &value);// to be used only for types that do not require allocation of memory (e.g. int)
	inline size_t GetUsed()
	{
		return Count;
	}
	inline size_t GetAllocated()
	{
		return Index.Size;
	}
	inline bool IsConstant()
	{
		return bConstant;
	}
	inline void SetConstant(bool p_bConstant) {bConstant=p_bConstant;}

	virtual size_t GetContainerSize() { return GetAllocated(); }
	virtual size_t GetContainerUsed() { return GetUsed(); }
	virtual LSIterator *NewIterator(void *PassAlong);
	virtual void OnRemoveType(class LSTypeDefinition *pType);

	unsigned int DeleteItemsByQuery(unsigned int ID, bool remove_MATCHES);// false removes NON-MATCHES
	CIndex<PLSOBJECT> *GetIndex() {return &Index;}

protected:
	CIndex<PLSOBJECT> Index;
	class LSTypeDefinition *pType;
	const char *SubType;
	size_t Count;
	bool bConstant;
};

extern bool InitializeIterator(LSIteratable *pIteratable,void *PassAlong,LSOBJECT &Object);