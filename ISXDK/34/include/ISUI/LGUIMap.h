#pragma once
class LGUIMapBlip :
	public LGUIFrame
{
public:
	LGUI_API LGUIMapBlip(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIMapBlip(void);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void OnMouseEnter(POINT2I &pt);
	LGUI_API void OnMouseExit(LGUIElement *pNewFocus);

	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void Render();

	LGUI_API bool SetTooltip(LGUITooltip *pTooltip);

	LGUIFont *pFont;
	LGUIEmbeddedScript *pSetTooltip;

	POINT3F Point;
	char *Custom;
	char *Label;
};

class LGUIMapBlipView :
	public LGUIFrame
{
public:
	LGUI_API LGUIMapBlipView(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIMapBlipView(void);
	LGUI_API bool IsTypeOf(char *TestFactory);
//	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void OnMouseEnter(POINT2I &pt);
	LGUI_API void OnMouseExit(LGUIElement *pNewFocus);

	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void UpdateSize();
	LGUI_API void Render();
	LGUI_API bool SetTooltip(LGUITooltip *pTooltip);

	LGUIMapBlip *pBlip;
};

class LGUIMapView;

class LGUIMap :
	public LGUIElement
{
public:
	LGUI_API LGUIMap(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIMap(void);
	LGUI_API bool IsTypeOf(char *TestFactory);
	LGUI_API class LSTypeDefinition *GetLSType();

	LGUI_API void OnCreate();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void Render();

	char BlipFactory[64];
	char *BlipTemplate;

	POINT3F Origin;		// center of Map (player location?)
	float Rotation;		// rotation of Map (player heading?)
	float MapSizeX;		// size of Map box in game units (east-west) - MapSizeY not used if ClipRadius is set.
	float MapSizeY;		// size of Map box in game units (north-south)
	bool bClipRadius;	// use radius clipping instead of box clipping
	bool bClipZ;		// height clipping
	bool bShowLabels;	// show labels?
	bool bRotation;		// Rotate Map around origin?
	bool bClipText;		// Clip text to Map edge?
	POINT2F ZClipping;	// min/max height difference from origin. X = min, Y = max

	LGUI_API virtual void BlipHover(LGUIMapBlip *pBlip, POINT2I &Pos);
	LGUI_API virtual void BlipHoverStop(LGUIMapBlip *pBlip);

// Blip Manipulation
	LGUI_API virtual unsigned int AddBlip(char *Name, POINT3F &Point, unsigned int Size, char *Label=0, char *BlipTemplate=0, char *BlipFactory=0);
	LGUI_API virtual void RemoveBlip(unsigned int ID);
	LGUI_API virtual void ClearBlips();
	LGUI_API virtual void UpdateBlip(unsigned int ID, POINT3F &Point);
	LGUI_API virtual void UpdateBlipLabel(unsigned int ID, char *Label);
	LGUI_API virtual void UpdateBlipSize(unsigned int ID, unsigned int Size);


	LGUI_API virtual LGUIMapBlip *NewBlip(char *Name, char *BlipTemplate=0, char *BlipFactory=0);
	LGUI_API virtual LGUIMapBlip *FindBlip(char *Name);

	LGUI_API virtual void UpdateRadius();
	LGUI_API virtual void UpdateBox();

	map<unsigned int, LGUIMapBlip *> Blips;
	map<utf8string, LGUIMapBlip *> BlipsByName;
	map<unsigned int, LGUIMapView *> Views;

	unsigned int HoverID;
	unsigned int nBlips;

	LGUITooltip *pTooltip;
};

class LGUIMapView :
	public LGUIElement
{
public:
	LGUI_API LGUIMapView(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUIMapView(void);
	LGUI_API bool IsTypeOf(char *TestFactory);
//	LGUI_API class LSTypeDefinition *GetLSType();

//	LGUI_API void ClearBlips();

	LGUI_API void OnCreate();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);

	LGUI_API void Render();

	POINT3F Origin;		// center of Map (player location?)
	float Rotation;		// rotation of Map (player heading?)
	float MapSizeX;		// size of Map box in game units (east-west) - MapSizeY not used if ClipRadius is set.
	float MapSizeY;		// size of Map box in game units (north-south)
	bool bClipRadius;	// use radius clipping instead of box clipping
	bool bClipZ;		// height clipping
	bool bShowLabels;	// show labels?
	bool bRotation;		// Rotate Map around origin?
	bool bClipText;		// Clip text to Map edge?
	POINT2F ZClipping;	// min/max height difference from origin. X = min, Y = max

	LGUI_API virtual void BlipHover(LGUIMapBlipView *pBlip, POINT2I &Pos);
	LGUI_API virtual void BlipHoverStop(LGUIMapBlipView *pBlip);


	LGUI_API virtual void UpdateRadius();
	LGUI_API virtual void UpdateBox();

//	LGUI_API virtual void AddBlipView(LGUIMapBlip *pBlip);
//	LGUI_API virtual void RemoveBlipView(LGUIMapBlip *pBlip);

	map<LGUIMapBlip *, LGUIMapBlipView *> BlipViews;
	LGUIMap *pMap;

	unsigned int HoverID;

	LGUITooltip *pTooltip;
};
