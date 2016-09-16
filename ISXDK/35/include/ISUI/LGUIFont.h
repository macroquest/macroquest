#pragma once

struct _CreateFont
{
	char *Name;
	unsigned char Height;
	unsigned int Color;
	bool Bold;
	bool Fixed;
};

class LGUIFont
{
public:
	LGUIFont(LGUIElement *pParent, const char *Face, unsigned char Height, bool Fixed, bool Bold);
	LGUIFont(LGUIElement *pParent, const LGUIFont&);
	LGUIFont(LGUIElement *pParent, _CreateFont &CreateFont, XMLNode *pTemplate);
	virtual ~LGUIFont();

//	LGUI_API virtual bool FromXML(class XMLNode *pXML, char *Template="");

	LGUI_API static LGUIFont *New(LGUIElement *pParent,const char *Face, unsigned char Height, bool Fixed, bool Bold);
	LGUI_API static LGUIFont *New(LGUIElement *pParent,_CreateFont &CreateFont, class XMLNode *pTemplate=0);
	LGUI_API static LGUIFont *New(LGUIElement *pParent,const LGUIFont&);
	LGUI_API virtual void Delete();
	LGUI_API virtual bool Prepare();
	LGUI_API void Release();

	LGUI_API bool IsFixedFont();
//	LGUI_API float GetBaseHeight();
	LGUI_API size_t Draw(const char *Text, int X, int Y, size_t ClipLength = 0);
	LGUI_API size_t DrawCenter(const char *Text, int X, int Y, size_t ClipLength);
	LGUI_API size_t DrawRight(const char *Text, int X, int Y, size_t ClipLength);
	LGUI_API size_t GetTextWidth(const char *Text);
	LGUI_API size_t GetTextWidth(const char *Text, size_t Length);
//	LGUI_API unsigned int GetCharWidth(unsigned int c);
	LGUI_API unsigned int GetCharByOffset(const char *Text, size_t Offset);

	LGUI_API void SetName(const char *p_Name);
	LGUI_API void SetBold(bool Bold);

	inline char *GetName() {return Name;}
	inline unsigned int GetColor() {return Color;}
	inline unsigned char GetHeight() {return Height;}
	inline bool GetBold() {return Bold;}

	LGUI_API void SetHeight(unsigned char NewHeight);
	inline void SetColor(unsigned int NewColor) {Color=NewColor;}

protected:
	unsigned int FontID;

	char *Name;
	unsigned char Height;
	unsigned int Color;
	bool Bold;
	bool Fixed;

	LGUIElement *pParent;
};

class LGUIFixedFont : public LGUIFont
{
public:
	LGUIFixedFont(LGUIElement *pParent, const char *Face, unsigned char Height, bool Bold);
	LGUIFixedFont(LGUIElement *pParent,const LGUIFixedFont&);
	LGUIFixedFont(LGUIElement *pParent,_CreateFont &CreateFont, class XMLNode *pTemplate);
	~LGUIFixedFont();

	LGUI_API static LGUIFixedFont *New(LGUIElement *pParent, const char *Face, unsigned char Height, bool Bold);
	LGUI_API static LGUIFixedFont *New(LGUIElement *pParent,const LGUIFixedFont&);
	LGUI_API static LGUIFixedFont *New(LGUIElement *pParent,_CreateFont &CreateFont, class XMLNode *pTemplate=0);
	LGUI_API virtual void Delete();

	LGUI_API virtual bool Prepare();
	LGUI_API size_t GetCharWidth();
/*
protected:
	inline class CLavishFontFixed *GetFixedFont()
	{
		return (class CLavishFontFixed *)pFont;
	}
/**/
};
