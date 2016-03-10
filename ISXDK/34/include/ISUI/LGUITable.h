#pragma once

class LGUITableCell :
	public LGUIFrame
{
public:
	LGUI_API LGUITableCell(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITableCell(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

//	LGUI_API void Render();
	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	// -- XML Properties  --
	unsigned int RowSpan;

	unsigned int ColSpan;
	// ----------------------
	unsigned int Row;
	unsigned int Column;
};

class LGUITable :
	public LGUIFrame
{
public:
	LGUI_API LGUITable(const char *p_Factory, LGUIElement *p_pParent, const char *p_Name);
	LGUI_API ~LGUITable(void);
//	LGUI_API class LSTypeDefinition *GetLSType();

//	LGUI_API void Render();
	LGUI_API virtual void RecalculateSize(bool RecalculateChildren);
	LGUI_API virtual void SizeRecalculated(bool Changed);


	LGUI_API bool FromXML(class XMLNode *pXML, class XMLNode *pTemplate=0);
	LGUI_API bool IsTypeOf(char *TestFactory);

	// -- XML Properties  --

	char *CellTemplate;
	//unsigned int CellSpacing; // TODO

	// ----------------------

	LGUITableCell **Cell;
	ElementPosition *ColumnWidth;
	ElementPosition *RowHeight;

	unsigned int nRows;
	unsigned int nColumns;
	
};