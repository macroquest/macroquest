#pragma once
class CColumnRenderer;

#ifndef __CColumnRenderer_h__
#define __CColumnRenderer_h__

struct _ColumnRendererItem
{
	char *Text;
	size_t Length;
};

class CColumnRenderer
{
public:
	CColumnRenderer()
	{
		LongestItem=0;
		ItemCount=0;
	}

	~CColumnRenderer()
	{
		foreach(_ColumnRendererItem* pItem,i,Items)
		{
			free(pItem->Text);
		}
	}

	void AddItem(const char *Text)
	{
		if (!Text || !Text[0])
			return;
		_ColumnRendererItem *pItem = new _ColumnRendererItem;
		pItem->Text=strdup(Text);
		size_t NewLength=strlen(Text);
		if (const char *pColor=(const char *)strchr(Text,'\a'))
		{
			do
			{
				if (pColor[1]=='-')
					NewLength--;
				NewLength-=2;
			}
			while(pColor=strchr(&pColor[1],'\a'));
		}
		pItem->Length=NewLength;
		if (NewLength>LongestItem)
			LongestItem=NewLength;
		Items+=pItem;
		ItemCount++;
	}

	void Render(class ISInterface *pISInterface)
	{
		if (!LongestItem) 
			return; // wtf.
		size_t Width = pISInterface->GetTerminalWidth();
		size_t Columns = (Width - LongestItem) / LongestItem;
		size_t ColumnWidth;
		if (Columns<1)
		{
			Columns=1;
			ColumnWidth=Width;
		}
		else if (Columns>10)
		{
			Columns=10;
			ColumnWidth=Width/10;
		}
		else
			ColumnWidth=Width/Columns;
		char Row[1024];
		char *pColumn=Row;

		size_t Rows = (ItemCount / Columns) + 1;

		size_t ItemNumber = 0;

		//pISInterface->Printf("Items: %d. Rows: %d. Columns: %d.",ItemCount,Rows,Columns);
		for (size_t i = 0; i < Rows; i++)
		{
			ItemNumber=i;
			for (size_t Column = 0; Column < Columns; Column++)
			{
				if (ItemNumber<ItemCount)
				{
					if (_ColumnRendererItem* pItem=Items[ItemNumber])
					{
						pColumn+=sprintf(pColumn,"%-*s",ColumnWidth,pItem->Text);
					}
				}
				
				ItemNumber+=Rows;
			}
			pISInterface->Printf("%s",Row);
			pColumn=Row;
			Row[0]=0;

		}
	}

	void RenderLeftToRight(class ISInterface *pISInterface)
	{
		if (!LongestItem) 
			return; // wtf.
		size_t Width = pISInterface->GetTerminalWidth();
		char Row[1024];
		size_t Columns = (Width - LongestItem) / LongestItem;
		size_t ColumnWidth;
		//pISInterface->Printf("Longest Item: %d. Width: %d. ColWidth: %d. Columns: %d.",LongestItem,Width,ColumnWidth,Columns);
		if (Columns<1)
		{
			Columns=1;
			ColumnWidth=Width;
		}
		else if (Columns>10)
		{
			Columns=10;
			ColumnWidth=Width/10;
		}
		else
			ColumnWidth=Width/Columns;
		size_t Column = 0;
		char *pColumn=Row;

		foreach(_ColumnRendererItem* pItem,i,Items)
		{
			pColumn+=sprintf(pColumn,"%-*s",ColumnWidth,pItem->Text);
			Column++;
			if (Column>=Columns)
			{
				pISInterface->Printf("%s",Row);
				Column=0;
				pColumn=Row;
				Row[0]=0;
			}
		}
		if (Row[0])
			pISInterface->Printf("%s",Row);
	}


protected:
	unsigned int ItemCount;
	size_t LongestItem;
	CIndex<_ColumnRendererItem *> Items;
	size_t Widest;
};


#endif

