#pragma once
#include "LGUItextentry.h"

class LGUICommandEntry :
	public LGUITextEntry
{
public:
	LGUI_API LGUICommandEntry(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUICommandEntry(void);
	LGUI_API bool IsTypeOf(char *TestFactory);
//	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API virtual bool OnKeyDown(unsigned int VKey);
	LGUI_API virtual void HandleEnter();
	LGUI_API virtual void PasteClipboard();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void OnCommand(char *Text);

	//
	char *Console;

	//
	unsigned int CmdHistorySize;
	char **CmdHistory;
	
	int HistoryLine;
	int HistoryView;
	int HistoryLines;

	void InsertCmdHistory(char *Text);
	LGUIEmbeddedScript *pOnCommand;
};
