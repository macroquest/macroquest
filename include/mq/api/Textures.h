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

#pragma once

#include "mq/base/Common.h"

#include "eqlib/game/UITypes.h"
#include "imgui/imconfig.h"

#include <string_view>
#include <string>

namespace eqlib {
	struct BMI;
}

namespace mq {

class MQTexture
{
public:
	explicit MQTexture(std::string_view name);
	MQLIB_OBJECT ~MQTexture();

	MQTexture(const MQTexture&) = delete;
	MQTexture& operator=(const MQTexture&) = delete;

	bool IsValid() const { return m_bmi != nullptr; }
	const std::string& GetFilename() const { return m_name; }

	MQLIB_OBJECT ImTextureID GetTextureID() const;
	MQLIB_OBJECT eqlib::CXSize GetTextureSize() const;

	void ReleaseTexture();
	void AcquireTexture();

private:
	std::string m_name;
	eqlib::BMI* m_bmi = nullptr;
};

using MQTexturePtr = std::shared_ptr<MQTexture>;

// Creates a texture with a path to an image file. If the texture cannot be created, this
// will return nullptr. The caller is responsible for calling DestroyTexture.
MQLIB_OBJECT MQTexture* CreateTexture(std::string_view filename);

// Destroy a texture that was previously created with CreateTexture
MQLIB_OBJECT void DestroyTexture(MQTexture* texture);

// Create a shared pointer that manages the lifetime of a texture. This is a convenient function
// that wraps CreateTexture/DestroyTexture in a shared_ptr.
MQLIB_OBJECT MQTexturePtr CreateTexturePtr(std::string_view filename);

} // namespace mq

