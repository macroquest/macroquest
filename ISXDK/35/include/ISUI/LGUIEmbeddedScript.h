#pragma once

class LGUIEmbeddedScript
{
public:
	LGUIEmbeddedScript(unsigned int AtomID, class LGUIElement *pThis);
	virtual ~LGUIEmbeddedScript();

	LGUI_API static LGUIEmbeddedScript *New(class LGUIElement *pThis, const char *Buffer, const char *Parameters);
	LGUI_API virtual void Delete();

	LGUI_API virtual int Execute(int argc=0, char *argv[]=0);
	LGUI_API virtual int Execute(class LGUIElement *pThis, int argc=0, char *argv[]=0);

protected:
	unsigned int AtomID;
	class LGUIElement *pThis;
	unsigned int RefCount;
};

