/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "Common.h"
#include "CXStr.h"

namespace eqlib {

class CXMLSOMDocument;

class CParam
{
public:
	EQLIB_OBJECT CParam& operator=(const CParam&);

	// virtual
	EQLIB_OBJECT ~CParam();
};

class CParamButton
{
public:
	EQLIB_OBJECT CParamButton();
	EQLIB_OBJECT CParamButton& operator=(const CParamButton&);

	// virtual
	EQLIB_OBJECT ~CParamButton();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamButtonDrawTemplate
{
public:
	EQLIB_OBJECT CParamButtonDrawTemplate();
	EQLIB_OBJECT CParamButtonDrawTemplate& operator=(const CParamButtonDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamButtonDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamClass
{
public:
	EQLIB_OBJECT CParamClass();
	EQLIB_OBJECT CParamClass& operator=(const CParamClass&);

	// virtual
	EQLIB_OBJECT ~CParamClass();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamCombobox
{
public:
	EQLIB_OBJECT CParamCombobox();
	EQLIB_OBJECT CParamCombobox& operator=(const CParamCombobox&);

	// virtual
	EQLIB_OBJECT ~CParamCombobox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamControl
{
public:
	EQLIB_OBJECT CParamControl();
	EQLIB_OBJECT CParamControl& operator=(const CParamControl&);

	// virtual
	EQLIB_OBJECT ~CParamControl();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamEditbox
{
public:
	EQLIB_OBJECT CParamEditbox();
	EQLIB_OBJECT CParamEditbox& operator=(const CParamEditbox&);

	// virtual
	EQLIB_OBJECT ~CParamEditbox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamFrame
{
public:
	EQLIB_OBJECT CParamFrame();

	// virtual
	EQLIB_OBJECT ~CParamFrame();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamFrameTemplate
{
public:
	EQLIB_OBJECT CParamFrameTemplate();
	EQLIB_OBJECT CParamFrameTemplate& operator=(const CParamFrameTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamFrameTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamGauge
{
public:
	EQLIB_OBJECT CParamGauge();
	EQLIB_OBJECT CParamGauge& operator=(const CParamGauge&);

	// virtual
	EQLIB_OBJECT ~CParamGauge();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamGaugeDrawTemplate
{
public:
	EQLIB_OBJECT CParamGaugeDrawTemplate();
	EQLIB_OBJECT CParamGaugeDrawTemplate& operator=(const CParamGaugeDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamGaugeDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamInvSlot
{
public:
	EQLIB_OBJECT CParamInvSlot();
	EQLIB_OBJECT CParamInvSlot& operator=(const CParamInvSlot&);

	// virtual
	EQLIB_OBJECT ~CParamInvSlot();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamLabel
{
public:
	EQLIB_OBJECT CParamLabel();
	EQLIB_OBJECT CParamLabel& operator=(const CParamLabel&);

	// virtual
	EQLIB_OBJECT ~CParamLabel();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamListbox
{
public:
	EQLIB_OBJECT CParamListbox();
	EQLIB_OBJECT CParamListbox& operator=(const CParamListbox&);

	// virtual
	EQLIB_OBJECT ~CParamListbox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamListboxColumn
{
public:
	EQLIB_OBJECT CParamListboxColumn();
	EQLIB_OBJECT CParamListboxColumn& operator=(const CParamListboxColumn&);

	// virtual
	EQLIB_OBJECT ~CParamListboxColumn();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamPage
{
public:
	EQLIB_OBJECT CParamPage();
	EQLIB_OBJECT CParamPage& operator=(const CParamPage&);

	// virtual
	EQLIB_OBJECT ~CParamPage();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamPoint
{
public:
	EQLIB_OBJECT CParamPoint();
	EQLIB_OBJECT CParamPoint& operator=(const CParamPoint&);

	// virtual
	EQLIB_OBJECT ~CParamPoint();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamRGB
{
public:
	EQLIB_OBJECT CParamRGB();
	EQLIB_OBJECT CParamRGB& operator=(const CParamRGB&);

	// virtual
	EQLIB_OBJECT ~CParamRGB();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamScreen
{
public:
	EQLIB_OBJECT CParamScreen();
	EQLIB_OBJECT CParamScreen& operator=(const CParamScreen&);

	// virtual
	EQLIB_OBJECT ~CParamScreen();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamScreenPiece
{
public:
	EQLIB_OBJECT CParamScreenPiece();
	EQLIB_OBJECT CParamScreenPiece& operator=(const CParamScreenPiece&);

	// virtual
	EQLIB_OBJECT ~CParamScreenPiece();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamLayoutStrategy;

class CParamScrollbarDrawTemplate
{
public:
	EQLIB_OBJECT CParamScrollbarDrawTemplate();
	EQLIB_OBJECT CParamScrollbarDrawTemplate& operator=(const CParamScrollbarDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamScrollbarDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSize
{
public:
	EQLIB_OBJECT CParamSize();
	EQLIB_OBJECT CParamSize& operator=(const CParamSize&);

	// virtual
	EQLIB_OBJECT ~CParamSize();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSlider
{
public:
	EQLIB_OBJECT CParamSlider();
	EQLIB_OBJECT CParamSlider& operator=(const CParamSlider&);

	// virtual
	EQLIB_OBJECT ~CParamSlider();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSliderDrawTemplate
{
public:
	EQLIB_OBJECT CParamSliderDrawTemplate();
	EQLIB_OBJECT CParamSliderDrawTemplate& operator=(const CParamSliderDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamSliderDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSpellGem
{
public:
	EQLIB_OBJECT CParamSpellGem();
	EQLIB_OBJECT CParamSpellGem& operator=(const CParamSpellGem&);

	// virtual
	EQLIB_OBJECT ~CParamSpellGem();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSpellGemDrawTemplate
{
public:
	EQLIB_OBJECT CParamSpellGemDrawTemplate();
	EQLIB_OBJECT CParamSpellGemDrawTemplate& operator=(const CParamSpellGemDrawTemplate&);

	// virtual
	EQLIB_OBJECT ~CParamSpellGemDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticAnimation
{
public:
	EQLIB_OBJECT CParamStaticAnimation();
	EQLIB_OBJECT CParamStaticAnimation& operator=(const CParamStaticAnimation&);

	// virtual
	EQLIB_OBJECT ~CParamStaticAnimation();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticFrame
{
public:
	EQLIB_OBJECT CParamStaticFrame();
	EQLIB_OBJECT CParamStaticFrame& operator=(const CParamStaticFrame&);

	// virtual
	EQLIB_OBJECT ~CParamStaticFrame();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticHeader
{
public:
	EQLIB_OBJECT CParamStaticHeader();
	EQLIB_OBJECT CParamStaticHeader& operator=(const CParamStaticHeader&);

	// virtual
	EQLIB_OBJECT ~CParamStaticHeader();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticScreenPiece
{
public:
	EQLIB_OBJECT CParamStaticScreenPiece();

	// virtual
	EQLIB_OBJECT ~CParamStaticScreenPiece();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamStaticText
{
public:
	EQLIB_OBJECT CParamStaticText();
	EQLIB_OBJECT CParamStaticText& operator=(const CParamStaticText&);

	// virtual
	EQLIB_OBJECT ~CParamStaticText();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSTMLbox
{
public:
	EQLIB_OBJECT CParamSTMLbox();

	// virtual
	EQLIB_OBJECT ~CParamSTMLbox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamSuiteDefaults
{
public:
	EQLIB_OBJECT CParamSuiteDefaults();
	EQLIB_OBJECT CParamSuiteDefaults& operator=(const CParamSuiteDefaults&);

	// virtual
	EQLIB_OBJECT ~CParamSuiteDefaults();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamTabBox
{
public:
	EQLIB_OBJECT CParamTabBox();
	EQLIB_OBJECT CParamTabBox& operator=(const CParamTabBox&);


	// virtual
	EQLIB_OBJECT ~CParamTabBox();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamTextureInfo
{
public:
	EQLIB_OBJECT CParamTextureInfo();

	// virtual
	EQLIB_OBJECT ~CParamTextureInfo();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamUi2DAnimation
{
public:
	EQLIB_OBJECT CParamUi2DAnimation();

	// virtual
	EQLIB_OBJECT ~CParamUi2DAnimation();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};

class CParamWindowDrawTemplate
{
public:
	EQLIB_OBJECT CParamWindowDrawTemplate();

	// virtual
	EQLIB_OBJECT ~CParamWindowDrawTemplate();
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT bool WriteToXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);
};


} // namespace eqlib

using namespace eqlib;
