#pragma once

#define TR_TEXTURERECT		1
#define TR_ALPHA			2
#define TR_COLORMASK		4
#define TR_NOSIZE			8
#define TR_TEXTURETRIANGLE	16

struct LGUITexturedRect
{
public:
	class LGUITexture *pTexture;
	
	RECT Rect;

	DWORD Flags;
	RECT TextureRect;
	unsigned char Alpha;
	unsigned int ColorMask;
	unsigned char Orientation;
};

struct LGUITriangle
{
	POINT2F Point[3];
};

struct LGUITexturedTriangle
{
public:
	class LGUITexture *pTexture;
	
	LGUITriangle Triangle;

	DWORD Flags;
	LGUITriangle TextureTriangle;
	unsigned char Alpha;
	unsigned int ColorMask;
	unsigned char Orientation;
};

class LGUITexture
{
public:
	LGUITexture(const char *p_Name);
	LGUITexture(const LGUITexture&);
	~LGUITexture();

	void CopyFrom(const LGUITexture &other);

	LGUI_API static LGUITexture *New(const char *p_Name);
	LGUI_API static LGUITexture *New(const LGUITexture&);
	LGUI_API void Delete();
	LGUI_API bool Prepare();
	LGUI_API bool GetSize();
	LGUI_API bool FromXML(class XMLNode *pXML);
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate);

	LGUI_API void Set(const char *Filename, unsigned int ColorKey=0);
	LGUI_API void SetFrom(const LGUITexture& other);

	char *Name;
	unsigned int TextureID;
	unsigned int ColorKey;

	DWORD Flags;
	RECT TextureRect;
	LGUITriangle TextureTriangle;

	float Alpha;
	unsigned int ColorMask;
	unsigned int Border;
	unsigned char Orientation;
};

