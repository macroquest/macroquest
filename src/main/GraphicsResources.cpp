/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#include "pch.h"
#include "GraphicsResources.h"

#include "MQ2Main.h"

#include "eqlib/graphics/GraphicsEngine.h"
#include "eqlib/graphics/ResourceManagerInterface.h"
#include "mq/api/Textures.h"

namespace mq {

//============================================================================

static std::vector<MQTexture*> s_textures;
static bool s_shutdown = false;

static int s_renderCallbacksId = -1;

//============================================================================

MQTexture* CreateTexture(std::string_view filename)
{
	MQTexture* newTexture = nullptr;

	if (pGraphicsEngine && pGraphicsEngine->pResourceManager)
	{
		newTexture = new MQTexture(filename);
		if (!newTexture->IsValid())
		{
			delete newTexture;
			newTexture = nullptr;
		}
	}

	return newTexture;
}

MQTexture* GetTexture(std::string_view filename)
{
	auto findIter = std::find_if(begin(s_textures), end(s_textures),
		[&filename](MQTexture* texture) { return texture->GetFilename() == filename; });

	return findIter == end(s_textures) ? nullptr : *findIter;
}

void DestroyTexture(MQTexture* texture)
{
	delete texture;
}

MQTexturePtr CreateTexturePtr(std::string_view filename)
{
	return std::shared_ptr<MQTexture>(CreateTexture(filename), [](MQTexture* tex) { DestroyTexture(tex); });
}

//============================================================================

MQTexture::MQTexture(std::string_view name)
	: m_name(name)
{
	AcquireTexture();

	if (m_bmi)
	{
		m_bmi->Name = m_name.c_str();
		m_bmi->pBmp->m_nTrackingType = 2; // EQG

		s_textures.push_back(this);
	}
}

MQTexture::~MQTexture()
{
	if (pGraphicsEngine && pGraphicsEngine->pResourceManager)
	{
		ReleaseTexture();
	}

	if (!s_shutdown)
	{
		s_textures.erase(std::remove(begin(s_textures), end(s_textures), this), end(s_textures));
	}
}

void MQTexture::AcquireTexture()
{
	if (m_bmi == nullptr)
	{
		BMI* bmi = pGraphicsEngine->pResourceManager->CreateBMI(m_name.c_str(), m_name.c_str(),
			nullptr, eMemoryPoolManagerTypePersistent);

		if (!bmi->pBmp)
		{
			pGraphicsEngine->pResourceManager->DestroyBMI(bmi);
		}
		else
		{
			if (bmi->pBmp->GetD3DTexture() == nullptr)
			{
				pGraphicsEngine->pResourceManager->DestroyBMI(bmi);
			}
			else
			{
				m_bmi = bmi;
			}
		}
	}
}

void MQTexture::ReleaseTexture()
{
	if (m_bmi != nullptr)
	{
		pGraphicsEngine->pResourceManager->DestroyBMI(m_bmi);
		m_bmi = nullptr;
	}
}

ImTextureID MQTexture::GetTextureID() const
{
	if (m_bmi && m_bmi->pBmp)
	{
#if HAS_DIRECTX_11
		return m_bmi->pBmp;
#else
		return m_bmi->pBmp->GetTexture();
#endif
	}
	
	return nullptr;
}

CXSize MQTexture::GetTextureSize() const
{
	if (m_bmi && m_bmi->pBmp)
	{
		return CXSize(m_bmi->pBmp->m_uWidth, m_bmi->pBmp->m_uHeight);
	}

	return CXSize();
}

//============================================================================

static void GraphicsResources_CreateDeviceObjects()
{
	if (pGraphicsEngine && pGraphicsEngine->pResourceManager)
	{
		for (MQTexture* texture : s_textures)
		{
			texture->AcquireTexture();
		}
	}
}

static void GraphicsResources_InvalidateDeviceObjects()
{
	if (pGraphicsEngine && pGraphicsEngine->pResourceManager)
	{
		for (MQTexture* texture : s_textures)
		{
			texture->ReleaseTexture();
		}
	}
}

void GraphicsResources_Initialize()
{
	MQRenderCallbacks callbacks;
	callbacks.CreateDeviceObjects = GraphicsResources_CreateDeviceObjects;
	callbacks.InvalidateDeviceObjects = GraphicsResources_InvalidateDeviceObjects;

	s_renderCallbacksId = AddRenderCallbacks(callbacks);
}

void GraphicsResources_Shutdown()
{
	s_shutdown = true;

	if (pGraphicsEngine && pGraphicsEngine->pResourceManager)
	{
		for (MQTexture* texture : s_textures)
		{
			texture->ReleaseTexture();
		}
	}

	s_textures.clear();

	RemoveRenderCallbacks(s_renderCallbacksId);
}

//============================================================================

} // namespace mq
