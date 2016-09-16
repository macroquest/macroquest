#pragma once
#ifdef LGUI_LIBRARY
#define LGUI_API
#else
#ifdef LGUI_EXPORTS
#define LGUI_API __declspec(dllexport)
#else
#define LGUI_API __declspec(dllimport)
#endif
#endif

#include <map>
//#include <string>
#include <set>
using namespace std;

#define LGUI_VERSION 0x12
#define LGUI_VERSIONSTRING	"0.73"

class LGUIPreParse
{
public:
	LGUI_API LGUIPreParse(const char *Text);
	LGUI_API LGUIPreParse();
	LGUI_API ~LGUIPreParse();

	LGUI_API void Clear();
	LGUI_API void PreParse(const char *Text);
	LGUI_API bool RetrieveProcessedText(char *buf, unsigned int buflen);

	inline const char *GetOriginalText()
	{
		return OriginalText;
	}

	inline unsigned int GetID()
	{
		return ID;
	}
protected:
	const char *OriginalText;
	unsigned int ID;
};

class LGUIDataSequence
{
public:
	LGUI_API LGUIDataSequence();
	LGUI_API LGUIDataSequence(const char *DataSequence);
	LGUI_API ~LGUIDataSequence();

	LGUI_API void Clear();
	LGUI_API void PreParse(const char *DataSequence);
	LGUI_API bool RetrieveOriginalText(char *buf, unsigned int buflen);
	LGUI_API bool RetrieveProcessedText(char *buf, unsigned int buflen);
	LGUI_API bool RetrieveProcessedResult(LSOBJECT &Result);

	inline unsigned int GetID()
	{
		return ID;
	}

protected:
	unsigned int ID;
};

#include "LGUIEmbeddedScript.h"
#include "LGUITexture.h"
#include "LGUIFont.h"
#include "LGUIElement.h"
#include "LGUIFrame.h"
#include "LGUIContextMenu.h"
#include "LGUIWindow.h"
#include "LGUIText.h"
#include "LGUITextEntry.h"
#include "LGUITextEdit.h"
#include "LGUICommandEntry.h"
#include "LGUIConsole.h"
#include "LGUIHudElement.h"
#include "LGUIScreen.h"
#include "LGUIButton.h"
#include "LGUICommandButton.h"
#include "LGUICheckBox.h"
#include "LGUICommandCheckBox.h"
#include "LGUISlider.h"
#include "LGUIVariableSlider.h"
#include "LGUIScrollBar.h"
#include "LGUIMessageBox.h"
#include "LGUIGauge.h"
#include "LGUIVariableGauge.h"
#include "LGUIListBox.h"
#include "LGUIComboBox.h"
#include "LGUITabControl.h"
#include "LGUITooltip.h"
#include "LGUITable.h"
#include "LGUIMap.h"
#include "LGUITree.h"
#include "LGUIManager.h"

#define SELECT(possiblevalue,defaultvalue) ((possiblevalue)?(possiblevalue):(defaultvalue))