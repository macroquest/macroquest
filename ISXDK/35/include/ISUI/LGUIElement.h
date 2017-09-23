#pragma once
#include "LGUIManager.h"

#define NOTIFICATION_USER (0x10000000)

#define NOTIFICATION_NULL					0
#define NOTIFICATION_CLICKED				1
//#define NOTIFICATION_CLOSE				2
#define NOTIFICATION_CHANGETEXT				3
#define NOTIFICATION_CHANGENUMBER			4
#define NOTIFICATION_ENTER					5
#define NOTIFICATION_LMOUSEDOWN				6
#define NOTIFICATION_LMOUSEUP				NOTIFICATION_CLICKED
#define NOTIFICATION_RMOUSEDOWN				7
#define NOTIFICATION_RMOUSEUP				8
#define NOTIFICATION_CHANGESELECTION		9
#define NOTIFICATION_LMOUSEDOUBLECLICK		10
#define NOTIFICATION_RMOUSEDOUBLECLICK		11
#define NOTIFICATION_DOUBLECLICKSELECTION	12
#define NOTIFICATION_CHANGEORDER			13
#define NOTIFICATION_MOUSEMOVE				14
#define NOTIFICATION_MOUSEWHEEL				15

#define NOTIFICATION_FONTCHANGED			50
#define NOTIFICATION_DELETING				51


enum eElementPositionType
{
	EPT_FIXED=0,
	EPT_VARIABLE=1,
	EPT_PERCENT=2,
	EPT_REVERSE_FIXED=3,
};

enum eElementFadeState
{
	EFS_NORMAL=0,
	EFS_DELAYING=1,
	EFS_FADING=2,
	EFS_FADED=3,

	EFS_IN_DELAYING=4,
	EFS_IN_FADING=5,
	EFS_IN_FADED=6,
};

struct ElementPosition
{
	eElementPositionType Type;
	union
	{
		unsigned int Size;
		float fSize;
	};
};


class XMLHelper
{
public:
	LGUI_API static bool GetToggle(class XMLNode *pXML, const char *Name, bool Default=0);

	LGUI_API static unsigned int GetIntValue(class XMLNode *pXML, const char *Name, unsigned int Default=0);
	LGUI_API static float GetFloatValue(class XMLNode *pXML, const char *Name, float Default=0.0f);
	LGUI_API static unsigned int GetHexValue(class XMLNode *pXML, const char *Name, unsigned int Default=0);
	LGUI_API static unsigned int GetFactorValue(class XMLNode *pXML, const char *Name, float &FactorResult, unsigned int Default=0);
	LGUI_API static unsigned int GetElementPositionValue(class XMLNode *pXML, const char *Name, ElementPosition &EPResult, unsigned int Default=0);
	LGUI_API static bool GetElementPositionValueEx(class XMLNode *pXML, const char *Name, ElementPosition &EPResult, unsigned int &ulResult);
	LGUI_API static const char *GetStringValue(class XMLNode *pXML, const char *Name, const char *Default = "");

	LGUI_API static class XMLNode *GetChild(class XMLNode *pXML, const char *Name);
	LGUI_API static const char *GetText(class XMLNode *pXML);
	LGUI_API static class XMLNode *GetPrev(class XMLNode *pXML);
	LGUI_API static class XMLNode *GetParent(class XMLNode *pXML);
	LGUI_API static class XMLNode *GetNext(class XMLNode *pXML);
	LGUI_API static class XMLNode *GetFirstChild(class XMLNode *pXML);

	LGUI_API static unsigned int GetIntAttribute(class XMLNode *pXML, const char *Name, unsigned int Default=0);
	LGUI_API static float GetFloatAttribute(class XMLNode *pXML, const char *Name, float Default=0.0f);
	LGUI_API static unsigned int GetHexAttribute(class XMLNode *pXML, const char *Name, unsigned int Default=0);
	LGUI_API static unsigned int GetFactorAttribute(class XMLNode *pXML, const char *Name, float &FactorResult, unsigned int Default=0);
	LGUI_API static unsigned int GetElementPositionAttribute(class XMLNode *pXML, const char *Name, ElementPosition &EPResult, unsigned int Default=0);
	LGUI_API static const char *GetStringAttribute(class XMLNode *pXML, const char *Name, const char *Default="");


	static inline bool GetTemplateToggle(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, bool Default=0)
	{
		Default=GetToggle(pTemplate,Name,Default);
		return GetToggle(pXML,Name,Default);
	}
	static inline unsigned int GetTemplateIntValue(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, unsigned int Default=0)
	{
		Default=GetIntValue(pTemplate,Name,Default);
		return GetIntValue(pXML,Name,Default);
	}
	static inline float GetTemplateFloatValue(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, float Default=0)
	{
		Default=GetFloatValue(pTemplate,Name,Default);
		return GetFloatValue(pXML,Name,Default);
	}
	static inline unsigned int GetTemplateHexValue(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, unsigned int Default=0)
	{
		Default=GetHexValue(pTemplate,Name,Default);
		return GetHexValue(pXML,Name,Default);
	}
	static inline unsigned int GetTemplateFactorValue(class XMLNode *pXML, const char *Name, float &FactorResult, class XMLNode *pTemplate)
	{
		float TempFactorResult;
		unsigned int Default=GetFactorValue(pTemplate,Name,TempFactorResult,0);
		unsigned int Ret=GetFactorValue(pXML,Name,FactorResult,0);
		if (!Ret && !FactorResult)
		{
			FactorResult=TempFactorResult;
			return Default;
		}
		return Ret;
	}
	static inline unsigned int GetTemplateElementPositionValue(class XMLNode *pXML, const char *Name, ElementPosition &EPResult, class XMLNode *pTemplate)
	{
		unsigned int Ret=0;
		if (GetElementPositionValueEx(pXML,Name,EPResult,Ret))
			return Ret;
		return GetElementPositionValue(pTemplate,Name,EPResult,0);
	}
	static inline const char *GetTemplateStringValue(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, const char *Default="")
	{
		Default=GetStringValue(pTemplate,Name,Default);
		return GetStringValue(pXML,Name,Default);
	}

	static inline class XMLNode *GetTemplateChild(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate)
	{
		class XMLNode *pNode=GetChild(pXML,Name);
		if (pNode)
			return pNode;
		return GetChild(pTemplate,Name);
	}

	static inline unsigned int GetTemplateIntAttribute(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, unsigned int Default=0)
	{
		Default=GetIntAttribute(pTemplate,Name,Default);
		return GetIntAttribute(pXML,Name,Default);
	}
	static inline float GetTemplateFloatAttribute(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, float Default=0)
	{
		Default=GetFloatAttribute(pTemplate,Name,Default);
		return GetFloatAttribute(pXML,Name,Default);
	}
	static inline unsigned int GetTemplateHexAttribute(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate,unsigned int Default=0)
	{
		Default=GetHexAttribute(pTemplate,Name,Default);
		return GetHexAttribute(pXML,Name,Default);
	}
	static inline unsigned int GetTemplateFactorAttribute(class XMLNode *pXML, const char *Name, float &FactorResult, class XMLNode *pTemplate)
	{
		float TempFactorResult;
		unsigned int Default=GetFactorAttribute(pTemplate,Name,TempFactorResult,0);
		unsigned int Ret=GetFactorAttribute(pXML,Name,FactorResult,0);
		if (!Ret && !FactorResult)
		{
			FactorResult=TempFactorResult;
			return Default;
		}
		return Ret;
	}
	static inline const char *GetTemplateStringAttribute(class XMLNode *pXML, const char *Name, class XMLNode *pTemplate, const char *Default = "")
	{
		Default=GetStringAttribute(pTemplate,Name,Default);
		return GetStringAttribute(pXML,Name,Default);
	}
};

struct _Line
{
	POINT2I A;
	POINT2I B;
};

/*
struct _TexturedPoint
{
	POINT2I pt;
	LGUITexture *pTexture;
	unsigned int Weight;
};
/**/

struct _CreateElement
{
	int X;
	int Y;
	unsigned int Width;
	unsigned int Height;
	ElementPosition XFactor;
	ElementPosition YFactor;
	ElementPosition HeightFactor;
	ElementPosition WidthFactor;
	bool bVisible;
	char bAlwaysOnTop;
};

struct FullElementPosition
{
	int X;
	ElementPosition XFactor;
	int Y;
	ElementPosition YFactor;
	unsigned int Height;
	ElementPosition HeightFactor;
	unsigned int Width;
	ElementPosition WidthFactor;
};

class LGUIElement
{
public:
	LGUI_API LGUIElement(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API virtual ~LGUIElement();

	LGUI_API void Delete(); // dont call this. use Destroy() instead.

	LGUI_API bool TextureFromArgs(int argc, char *argv[], LGUITexture **ppTexture);

	LGUI_API virtual bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API virtual LGUITexture *TextureFromXML(class XMLNode *pXML, const char *ValueName, class XMLNode *pTemplate = 0);
	LGUI_API virtual LGUIFont *FontFromXML(class XMLNode *pXML, const char *ValueName, class XMLNode *pTemplate = 0);
	LGUI_API virtual LGUIFixedFont *FixedFontFromXML(class XMLNode *pXML, const char *ValueName, class XMLNode *pTemplate = 0);
	LGUI_API virtual LGUIEmbeddedScript *EmbeddedScriptFromXML(class XMLNode *pXML, const char *ValueName, class XMLNode *pTemplate = 0, const char *Parameters = "");

	LGUI_API virtual bool IsTypeOf(char *TestFactory);

	LGUI_API virtual void RecalculateSize(bool RecalculateChildren);
	LGUI_API virtual void RecalculateChildrenSize();
	LGUI_API virtual void SizeRecalculated(bool Changed) {};
	LGUI_API virtual void Render();
	LGUI_API virtual void RenderChildren();
	LGUI_API virtual void Show(bool bShow) {bVisible=bShow;}
	LGUI_API virtual void Center();

	LGUI_API virtual bool OnLMouseUp(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnLMouseDown(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnRMouseUp(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnRMouseDown(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnLMouseDoubleClick(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnRMouseDoubleClick(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnMouseMove(POINT2I &pt);// {return false;}
	LGUI_API virtual bool OnMouseWheel(int Offset);// {return false;};
	LGUI_API virtual bool OnKeyUp(unsigned int VKey);// {return false;}
	LGUI_API virtual bool OnKeyDown(unsigned int VKey);// {return false;}
	LGUI_API virtual void OnNotify(LGUIElement *pElement, unsigned int Notification, UINT_PTR Value) {if (pParent) pParent->OnNotify(pElement,Notification,Value);};
	LGUI_API virtual void OnMouseEnter(POINT2I &pt);// {}
	LGUI_API virtual void OnMouseExit(LGUIElement *pNewFocus);// {}
	LGUI_API virtual void OnKeyboardEnter();// {}
	LGUI_API virtual void OnKeyboardExit(LGUIElement *pNewFocus);// {}
	LGUI_API virtual void OnLMouseDownOther(LGUIElement *pOther) {}
	LGUI_API virtual void OnCreate() {}
	LGUI_API virtual void OnDestroy() {}

	LGUI_API virtual class LSTypeDefinition *GetLSType();

	LGUI_API virtual bool GetStoragePosition(int &StoreX, int &StoreY, unsigned int &StoreWidth, unsigned int &StoreHeight);

	inline LGUIElement *GetParent() {return pParent;}
	inline LGUIElement *GetFirstChild() {return pFirstChild;}
	inline LGUIElement *GetLastChild() {return pLastChild;}
	inline LGUIElement *GetPrev() {return pPrev;}
	inline LGUIElement *GetNext() {return pNext;}

	LGUI_API LGUIElement *Walk(bool bRequireVisible, LGUIElement *pStopAtParent);
	LGUI_API LGUIElement *WalkReverse(bool bRequireVisible, LGUIElement *pStopAtParent);

	inline void SetNext(LGUIElement *pElement) {pNext=pElement;}
	inline void SetPrev(LGUIElement *pElement) {pPrev=pElement;}
	inline void SetLastChild(LGUIElement *pElement) {pLastChild=pElement;}
	inline void SetFirstChild(LGUIElement *pElement) {pFirstChild=pElement;}

	inline bool IsDescendentOf(LGUIElement *pElement)
	{
		LGUIElement *pTest=pParent;
		while(pTest)
		{
			if (pElement==pTest)
				return true;
			pTest=pTest->pParent;
		}
		return false;
	}

	inline char *GetName() {return Name;}
	inline char *GetFullName() {return FullName;}
	inline char *GetFactory() {return Factory;}

	LGUI_API void AddChild(LGUIElement *pElement);
	LGUI_API void DeleteChild(LGUIElement *pElement);

	LGUI_API virtual LGUIElement *FindChild(const char *Name);
	LGUI_API LGUIElement *FindUsableChild(const char *Name, const char *Type);

	inline void SetLeft(int NewValue) {X=NewValue;}
	inline void SetTop(int NewValue) {Y=NewValue;}
	inline void GetXFactor(ElementPosition &EP) {EP=XFactor;}
	inline void GetYFactor(ElementPosition &EP) {EP=YFactor;}
	inline void GetHeightFactor(ElementPosition &EP) {EP=HeightFactor;}
	inline void GetWidthFactor(ElementPosition &EP) {EP=WidthFactor;}
	inline void SetWidth(unsigned int NewValue) {Width=NewValue;}
	inline void SetHeight(unsigned int NewValue) {Height=NewValue;}
	inline int GetRight() {return X+Width;}
	inline int GetBottom() {return Y+Height;}
	inline int GetTop() {return Y;}
	inline int GetLeft() {return X;}
	inline unsigned int GetHeight() {return Height;}
	inline unsigned int GetWidth() {return Width;}
	inline unsigned int GetID() {return ID;}
	inline bool IsVisible() {return bVisible;}
	LGUI_API bool IsReallyVisible();
	inline unsigned char GetAlwaysOnTop() {return bAlwaysOnTop;}
	inline void SetAlwaysOnTop(unsigned char NewValue) { bAlwaysOnTop = NewValue; }
	inline bool GetStorePosition() {return bStorePosition;}
	inline void Destroy() {pParent->DeleteChild(this);}
	inline void GetOriginalPosition(FullElementPosition &Dest) {Dest=OriginalPosition;}

	inline void ResetPosition()
	{
		X=OriginalPosition.X;
		Y=OriginalPosition.Y;
		Height=OriginalPosition.Height;
		Width=OriginalPosition.Width;
		XFactor=OriginalPosition.XFactor;
		YFactor=OriginalPosition.YFactor;
		HeightFactor=OriginalPosition.HeightFactor;
		WidthFactor=OriginalPosition.WidthFactor;
		RecalculateSize(true);
	}

	LGUI_API virtual bool SetFocus();
	LGUI_API virtual bool SetMouseOver();

	LGUI_API bool IsMouseOver();
	LGUI_API bool IsFocus();

	LGUI_API bool FillRect(RECT &r,unsigned int Color);
	LGUI_API bool FillRectBordered(RECT &r,unsigned int Color,unsigned int BorderSize,unsigned int BorderColor);
	LGUI_API bool DrawBorder(RECT &r,unsigned int BorderSize,unsigned int BorderColor);
	
	LGUI_API bool TexturedRect(RECT &r,LGUITexture *pTexture);
	LGUI_API bool TexturedRectBordered(RECT &r,LGUITexture *pTexture, unsigned int BorderSize);
	LGUI_API bool TexturedRects(unsigned int nRects, LGUITexturedRect *pRects);

	LGUI_API bool FillTriangle(LGUITriangle &t,unsigned int Color);
	LGUI_API bool TexturedTriangle(LGUITriangle &t,LGUITexture *pTexture);
	LGUI_API bool TexturedTriangles(unsigned int nTriangles, LGUITexturedTriangle *pTriangles);

	LGUI_API bool DrawLine(_Line &Line, LGUITexture *pTexture, unsigned int Weight=1);
	LGUI_API bool DrawLines(_Line *Lines, unsigned int nLines, LGUITexture *pTexture, unsigned int Weight=1);

	LGUI_API bool DrawLine(_Line &Line, unsigned int Color, unsigned int Weight=1);
	LGUI_API bool DrawLines(_Line *Lines, unsigned int nLines, unsigned int Color, unsigned int Weight=1);
	
	
//	LGUI_API bool DrawPoint(_ColoredPoint &pt);
//	LGUI_API bool DrawPoints(_ColoredPoint *Points, unsigned int nPoints);


	LGUI_API size_t DrawText(LGUIFont *pFont,const char *Text,int X, int Y);
	LGUI_API size_t DrawTextClipped(LGUIFont *pFont,const char *Text,int X, int Y);
	LGUI_API size_t DrawTextCenter(LGUIFont *pFont,const char *Text,int X, int Y);
	LGUI_API size_t DrawTextRight(LGUIFont *pFont,const char *Text,int X, int Y);

	LGUI_API size_t DrawTextClipped(LGUIFont *pFont,const char *Text,int X, int Y, int RightX);
	LGUI_API size_t DrawTextCenter(LGUIFont *pFont,const char *Text,int X, int Y, int RightX);
	LGUI_API size_t DrawTextRight(LGUIFont *pFont,const char *Text,int X, int Y, int RightX);

	LGUI_API size_t DrawColoredText(LGUIFont *pFont,const char *buffer, int X, int Y);
	LGUI_API size_t DrawColoredTextClipped(LGUIFont *pFont,const char *buffer, int X, int Y, int RightX);

	static LGUI_API void StripColor(const char *In, char *Out);
	static LGUI_API size_t ColorStrlen(const char *Text);

	LGUI_API virtual LGUIElement *FindMouseOver(POINT2I &pt, LGUIElement *pStart);
	LGUI_API bool HitTest(POINT2I &pt);

	inline void SetAbsolute(POINT2I &pt) {Absolute=pt;}
	inline void GetAbsolute(POINT2I &pt) {pt=Absolute;}

	inline bool GetLeftClickThru() {return bLeftClickThru;}
	inline bool GetRightClickThru() {return bRightClickThru;}

	inline void SetLeftClickThru(bool Value) {bLeftClickThru=Value;}
	inline void SetRightClickThru(bool Value) {bRightClickThru=Value;}

	inline void SetAbsoluteAlpha(float Value) {AbsoluteAlpha=Value;}
	inline float GetAbsoluteAlpha() {return AbsoluteAlpha;}

	inline void SetAlpha(float Value) {AlphaLevel=Value;}
	inline float GetAlpha() {return AlphaLevel;}

	inline void SetFadeAlpha(float Value) {FadeAlphaLevel=Value;}
	inline float GetFadeAlpha() {return FadeAlphaLevel;}

	inline unsigned int GetFadeDelay() {return FadeDelay;}
	inline void SetFadeDelay(unsigned int Value) {FadeDelay=Value;}

	inline unsigned int GetFadeDuration() {return FadeDuration;}
	inline void SetFadeDuration(unsigned int Value) {FadeDuration=Value;}

	inline void BeginFade() {FadeState=EFS_DELAYING;FadeBegan=g_UIManager.RenderTime;}
	inline void InstantFade() {FadeState=EFS_FADED;} // FadeDelay must be non-zero to fade normally.
	inline void ResetFade() {FadeState=EFS_NORMAL;}
	inline eElementFadeState GetFadeState() {return FadeState;}

	inline void UpdateFadeState()
	{
		if (!FadeDelay)
			return;
		if (FadeState==EFS_NORMAL)
		{
			if (!HitTest(g_UIManager.MousePos))
			{
				BeginFade();
			}
		}
		else
		{
			if (HitTest(g_UIManager.MousePos))
			{
				ResetFade();
			}
		}
	}

	LGUI_API float GetCurrentAlpha();

	inline unsigned char ApplyAlpha(unsigned char Value)
	{
		float fValue=((((float)Value/255.0f)*AbsoluteAlpha)*255.0f);
		if (fValue>255)
			return 255;
		return (unsigned char)fValue;
	}
	inline unsigned int ApplyAlpha(unsigned int &Value)
	{
		RGBCOLOR Color;
		Color.ARGB=Value;
		Color.A=ApplyAlpha(Color.A);
		return Color.ARGB;
	}
	inline float ApplyAlpha(float Value)
	{
		return Value*AbsoluteAlpha;
	}

	inline void ExecuteOnLoad() {if (pOnLoad) pOnLoad->Execute();}
	inline void ExecuteOnRender() {if (pOnRender) pOnRender->Execute();}

	LGUI_API virtual void MoveZUp();
	LGUI_API virtual void MoveZDown();
	LGUI_API virtual void MoveZTop(bool bAncestorsToo=true);
	LGUI_API virtual void MoveZBottom();

	void MoveContainerZTop();

	static void StripSlashes(char *Text);
//	void GetAbsolute();
protected:
	char *Factory;
	unsigned int ID; // globally unique
	char *Name;
	char *FullName;

	LGUIElement *pParent;
	LGUIElement *pPrev;
	LGUIElement *pNext;
	LGUIElement *pFirstChild;
	LGUIElement *pLastChild; // top of Z order

	LGUIEmbeddedScript *pOnLoad;
	LGUIEmbeddedScript *pOnUnload;
	LGUIEmbeddedScript *pOnLeftClick;
	LGUIEmbeddedScript *pOnRightClick;
	LGUIEmbeddedScript *pOnDoubleLeftClick;
	LGUIEmbeddedScript *pOnDoubleRightClick;
	LGUIEmbeddedScript *pOnMouseEnter;
	LGUIEmbeddedScript *pOnMouseExit;
	LGUIEmbeddedScript *pOnMouseMove;
	LGUIEmbeddedScript *pOnMouseWheel;
	LGUIEmbeddedScript *pOnKeyboardEnter;
	LGUIEmbeddedScript *pOnKeyboardExit;
	LGUIEmbeddedScript *pOnKeyUp;
	LGUIEmbeddedScript *pOnKeyDown;
	LGUIEmbeddedScript *pOnLeftDown;
	LGUIEmbeddedScript *pOnRightDown;
	LGUIEmbeddedScript *pOnRender;

	int X;
	ElementPosition XFactor;
	int Y;
	ElementPosition YFactor;
	unsigned int Height;
	ElementPosition HeightFactor;
	unsigned int Width;
	ElementPosition WidthFactor;

	FullElementPosition OriginalPosition;

	bool bStorePosition;

	bool bVisible;
	char bAlwaysOnTop;
	bool bLeftClickThru;
	bool bRightClickThru;

	float AlphaLevel;

	unsigned int FadeBegan;
	unsigned int FadeDelay;
	unsigned int FadeDuration;
	float FadeAlphaLevel;
	eElementFadeState FadeState;

	unsigned int FadeInDelay;
	unsigned int FadeInDuration;

	char *AutoTooltip;

	inline void Create(_CreateElement &CreateInfo)
	{
		X=CreateInfo.X;
		Y=CreateInfo.Y;
		Width=CreateInfo.Width;
		Height=CreateInfo.Height;
		bVisible=CreateInfo.bVisible;
		XFactor=CreateInfo.XFactor;
		YFactor=CreateInfo.YFactor;
		WidthFactor=CreateInfo.WidthFactor;
		HeightFactor=CreateInfo.HeightFactor;
		bAlwaysOnTop=CreateInfo.bAlwaysOnTop;
		MoveZTop();
	}

	float AbsoluteAlpha;
	POINT2I Absolute;
};

class LGUIElementDeleter
{
public:
	virtual void Delete(LGUIElement *pElement)
	{
		pElement->OnDestroy();
		delete pElement;
	}
};

class LGUIElementFactory
{
public:
	LGUIElementFactory(const char *p_Type, unsigned int LGUIVersion)
	{
		Register(p_Type,LGUIVersion);
		pDeleter = new LGUIElementDeleter;
	}
	~LGUIElementFactory()
	{
		if (Type)
		{
			map<LGUIElement*,unsigned int>::iterator i=Elements.begin();
			while(i!=Elements.end())
			{
				map<LGUIElement*,unsigned int>::iterator cur=i;
				i++;

				if (cur->second)
				{
					cur->first->OnDestroy();
					if (cur->first->GetParent())
						cur->first->GetParent()->DeleteChild(cur->first);
					else
					{
//						delete i->first; // fuck it, avoid crashing
					}
				}
			}
		}
		Unregister();
		delete pDeleter;
	}

	LGUI_API void Register(const char *p_Type, unsigned int LGUIVersion);
	LGUI_API void Unregister();

	LGUI_API virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name, class XMLNode *pXML, const char *Template = 0) = 0;
	LGUI_API virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name) = 0;
	virtual void UnregisterUIElement(LGUIElement *pElement)
	{
		Elements.erase(pElement);
	}
	inline const char *GetTypeName()
	{
		return Type;
	}

	map<LGUIElement*,unsigned int> Elements;

	void DeleteUIElement(LGUIElement *pElement)
	{
		//pElement->OnDestroy();
		pDeleter->Delete(pElement);
	}
protected:
	LGUIElementDeleter *pDeleter;
	const char *Type;

};

template<class T>
class LGUIFactory : public LGUIElementFactory
{
public:

	LGUIFactory(const char *p_Type) :LGUIElementFactory(p_Type, LGUI_VERSION)
	{
	}

	~LGUIFactory()
	{
	}

	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name, class XMLNode *pXML, const char *Template = 0)
	{
		T *pElement = new T(Type,pParent,Name);
		
		if (!pElement->FromXML(pXML,g_UIManager.FindTemplate(Template)))
		{
			if (pParent)
				pParent->DeleteChild(pElement);
			else
				delete pElement;
			return 0;
		}
		Elements[pElement]=1;
		return pElement;
	}

	virtual LGUIElement *CreateUIElement(LGUIElement *pParent, const char *Name)
	{
		T *pElement = new T(Type,pParent,Name);
		Elements[pElement]=1;
		return pElement;
	}
};

template<class T>
class DelayedLGUIFactory 
{
public:

	DelayedLGUIFactory(const char *p_Type)
	{
		Type=strdup(p_Type);
		pFactory=0;
	}

	~DelayedLGUIFactory()
	{
		Shutdown();
		free((void*)Type);
	}

	void Initialize()
	{
		if (pFactory)
			return;
		pFactory = new LGUIFactory<T>(Type);
	}

	void Shutdown()
	{
		if (!pFactory)
			return;
		delete pFactory;
		pFactory=0;
	}

	const char *Type;
	LGUIFactory<T> *pFactory;
};
