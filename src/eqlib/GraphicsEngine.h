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
#include <d3d9.h>

namespace eqlib {

class CRender;

// The graphics engine holds pointers to all the components
struct SGraphicsEngine
{
public:
	CFastFileInterface*        pFastFile;
	CResourceManagerInterface* pResourceManager;
	CSceneGraphInterface*      pSceneGraph;
	CRender*                   pRender;
	CParticleSystemInterface*  pParticleSystem;
	CCollisionInterface*       pCollision;
	CMathInterface*            pMath;
	CThickLineSystemInterface* pThickLineSystem;
	CDebugDrawInterface*       pDebugDraw;
	CPropertySet*              pProperties;
	CTerrainSystemInterface*   pTerrainSystem;
};

class CRenderInterface
{
public:
	// Give us a vftable
	virtual void Placeholder() {}
};

class [[offsetcomments]] CRender : public CRenderInterface
{
public:
/*0x0000*/ //vftable
/*0x0004*/ uint8_t                   Unknown0x04[0xEBC];
/*0x0ec0*/ HWND                      hWnd;
/*0x0ec4*/ IDirect3D9*               pDirect3D;             // "CRender::InitDevice: Direct3DCreate9 failed.\n"
/*0x0ec8*/ IDirect3DDevice9*         pD3DDevice;            // "Failed to create device with error %X.\n"
/*0x0ecc*/ IDirect3DSurface9*        pD3DBackBuffer;
/*0x0ed0*/ D3DVIEWPORT9              D3DViewPort;
/*0x0ee8*/ D3DCAPS9                  D3DDeviceCaps;
/*0x1018*/ float                     GammaLevel;
/*0x101c*/ IDirect3DSwapChain9*      pD3DSwapChain;
/*0x1020*/
// ... much more
};


} // namespace eqlib

