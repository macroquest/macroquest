#pragma once
#include "LGUIelement.h"

class CTextEditLine
{
public:
	CTextEditLine(const char *p_Text, size_t p_nLine)
	{
		nLine=p_nLine;
		pPrev=0;
		pNext=0;
		if (p_Text)
		{
			Used=strlen(p_Text);
			Allocated=Used+1;
			Text=(char*)malloc(Allocated);
			memcpy(Text,p_Text,Allocated);
		}
		else
		{
			Text=_strdup("");
			Used=0;
			Allocated=1;
		}
	}
	~CTextEditLine()
	{
		free(Text);
	}

	bool InsertText(size_t Position, const char *Insert, size_t InsertSize)
	{
		if (!InsertSize)
			return true;
		if (Position>Used)
			return false;
		if (Used+InsertSize>Allocated)
		{
			Text=(char*)realloc(Text,Used+InsertSize+7);
		}
		
		if (Position!=Used+1)
		{
			// shift to the right
			memmove(&Text[Position+InsertSize],&Text[Position],(Used+1-Position)+InsertSize);
		}
		else
			Text[Position+Used+1]=0;
		Used+=InsertSize;
		memcpy(&Text[Position],Insert,InsertSize);
		return true;
	}

	bool InsertCharacter(size_t Position, char C)
	{
		if (Position>Used)
			return false;
		if (Used+2>=Allocated)
		{
			Text=(char*)realloc(Text,Used+7);
		}

		if (Position!=Used+1)
		{
			// shift to the right
			memmove(&Text[Position+1],&Text[Position],(Used+1-Position)+1);
		}
		else
			Text[Position+1]=0;
		Used++;
		Text[Position]=C;

		return true;
	}
	bool OverwriteCharacter(size_t Position, char C)
	{
		if (Position>Used)
			return false;
		
		if (Position==Used)
		{
			if (Used+1>=Allocated)
			{
				Text=(char*)realloc(Text,Used+7);
			}
			Used++;
			Text[Position+1]=0;
		}
		Text[Position]=C;
	}
	inline bool DeleteCharacter(size_t Position)
	{
		if (Position>=Used)
			return false;

		memmove(&Text[Position],&Text[Position+1],(Used+1-Position));
		Used--;
		return true;
	}
	inline bool Truncate(size_t Position)
	{
		if (Position>Used)
			return false;
		Text[Position]=0;
		Used=Position;
		return true;
	}


	char *Text;
	size_t Allocated;
	size_t Used;

	size_t nLine;

	CTextEditLine *pPrev;
	CTextEditLine *pNext;
};

struct TextEditPos
{
	CTextEditLine *pLine;
	size_t Position;

	bool operator==(const TextEditPos& other ) const
	{
		return pLine==other.pLine && Position==other.Position;
	}
	bool operator!=(const TextEditPos& other ) const
	{
		return pLine!=other.pLine || Position!=other.Position;
	}
	bool operator<(const TextEditPos& other ) const
	{
		if (pLine==other.pLine)
			return Position<other.Position;
		else
			return pLine->nLine<other.pLine->nLine;
	}
	bool operator>(const TextEditPos& other ) const
	{
		if (pLine==other.pLine)
			return Position>other.Position;
		else
			return pLine->nLine>other.pLine->nLine;
	}
	bool operator<=(const TextEditPos& other ) const
	{
		if (pLine==other.pLine)
			return Position<=other.Position;
		else
			return pLine->nLine<=other.pLine->nLine;
	}
	bool operator>=(const TextEditPos& other ) const
	{
		if (pLine==other.pLine)
			return Position>=other.Position;
		else
			return pLine->nLine>=other.pLine->nLine;
	}
};

class LGUITextEdit :
	public LGUIFrame
{
public:
	LGUI_API LGUITextEdit(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITextEdit(void);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	LGUI_API virtual void SetText(const char *NewValue);
	LGUI_API virtual void AddText(const char *Text);
	LGUI_API virtual void AddLine(const char *Text);

	LGUI_API virtual void InsertText(TextEditPos &Pos, const char *Text);
	LGUI_API virtual CTextEditLine *InsertLineAfter(CTextEditLine *pLine, const char *Text);
	LGUI_API virtual void RemoveLine(CTextEditLine *pLine, bool bReverseCursor=false);

	LGUI_API virtual bool OnKeyUp(unsigned int VKey);
	LGUI_API virtual bool OnKeyDown(unsigned int VKey);
	LGUI_API virtual bool OnLMouseDown(POINT2I &pt);
	LGUI_API virtual bool OnLMouseUp(POINT2I &pt);
	LGUI_API virtual bool OnMouseMove(POINT2I &pt);

	LGUI_API virtual void InsertCharacter(char C);
	LGUI_API virtual void HandleBackspace();
	LGUI_API virtual void HandleDelete();
	LGUI_API virtual void HandleEnter();
	
	LGUI_API virtual void HandleUp(unsigned int Count=1);
	LGUI_API virtual void HandleDown(unsigned int Count=1);
	LGUI_API virtual void HandleLeft();
	LGUI_API virtual void HandleRight();
	LGUI_API virtual void HandlePageUp();
	LGUI_API virtual void HandlePageDown();
	LGUI_API virtual void HandleHome();
	LGUI_API virtual void HandleEnd();

	LGUI_API virtual void HandleCtrlHome();
	LGUI_API virtual void HandleCtrlEnd();

	LGUI_API virtual void PasteClipboard();
	LGUI_API virtual void CopySelection();

	LGUI_API virtual void GetPositionFromPoint(POINT2I &pt, TextEditPos &Position);
	LGUI_API virtual bool OnMouseWheel(int Offset);
	LGUI_API virtual void OnNotify(LGUIElement *pElement, unsigned int Notification, unsigned int Value);

	bool IsSelected(CTextEditLine *pLine, POINT2I &Selected);
	void ClearSelection();
	void UpdateSelection();

	// -- XML PROPERTIES --
	LGUIFixedFont *pFont;
	unsigned int SelectionColor;
	unsigned int CaretOuterColor;
	unsigned int CaretInnerColor;

	LGUITexture *pTextureCaret;
	LGUITexture *pTextureCaretOverwrite;
	//---------------------


	CTextEditLine *pFirstLine;
	CTextEditLine *pLastLine;


	bool InsertMode;
	size_t MaxLines;
	size_t CharactersWide;

	TextEditPos SelectionBegin;
	TextEditPos SelectionEnd;

	TextEditPos Position;

	TextEditPos UpperLeft;
	TextEditPos LowerLeft;

	unsigned int LastVKey;
	unsigned int LastVKeyTimer;

	size_t VisibleLines;

	class LGUIScrollBar *pVerticalScrollbar;
	class LGUIScrollBar *pHorizontalScrollbar;

	size_t nLines;

	bool bDragging;
protected:
	LGUI_API virtual void Clear();

};
