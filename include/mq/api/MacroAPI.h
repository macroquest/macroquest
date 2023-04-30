/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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
#include "mq/base/Deprecation.h"

#include <functional>

namespace mq {

namespace datatypes {
	class MQ2Type;
}
struct MQDataItem;
struct MQDataVar;
struct MQTypeVar;


//
// MacroQuest DataTypes
//

/**
 * Add a new datatype with the Macro type system. The caller is expected
 * to create an instance of the datatype, and keep the instance alive until
 * RemoveMQ2Type is called.
 * 
 * @param type Reference to the instance of the datatype to register.
 * @return Whether the type was successfully added.
 */
MQLIB_API bool AddMQ2Type(datatypes::MQ2Type& type);

/**
 * Remove a previously registered datatype from the Macro type system. This
 * should be the same instance of an object that was passed to AddMQ2Type.
 * 
 * @param type A reference to the type that was previously registered.
 * @return Whether the type was successfully removed.
 */
MQLIB_API bool RemoveMQ2Type(datatypes::MQ2Type& type);

/**
 * Find and return a previously added datatype instance by name.
 * 
 * @param name The name of the datatype to find.
 * @return A pointer to the datatype if found, otherwise nullptr.
 */
MQLIB_API datatypes::MQ2Type* FindMQ2DataType(const char* name);

/**
 * Adds a datatype extension to another datatype. The other datatype
 * does not need to exist at the time of invocation, however the extension
 * will have no effect until it does.
 * 
 * An extension will extend another datatype by adding additional data members
 * and methods.
 * 
 * @param typeName The name of the datatype to extend.
 * @param extension A pointer to the datatype that serves as the extension.
 * @return True if the extension was added successfully.
 */
MQLIB_API bool AddMQ2TypeExtension(const char* typeName, datatypes::MQ2Type* extension);

/**
 * Removes a previously added datatype extension. Requires the same parameters that
 * were passed to AddMQ2TypeExtension
 * 
 * @param typeName The name of the datatype that the extension was registered to.
 * @param extension A pointer to the extension to be removed.
 * @return True if the extension was removed successfully.
 */
MQLIB_API bool RemoveMQ2TypeExtension(const char* typeName, datatypes::MQ2Type* extension);


//
// Top Level Objects
//

// Function signature for TLO callbacks
using MQTopLevelObjectFunction = std::function<bool(const char*, MQTypeVar&)>;

/**
 * Adds a new Top Level Object to the macro environment.
 * 
 * @param name The name of the TLO
 * @param callback The function to be invoked when the TLO is accessed.
 * 
 * @return True if the TLO was added successfully.
 */
MQLIB_OBJECT bool AddMQ2Data(const char* name, MQTopLevelObjectFunction callback);

/**
 * Removes a Top Level Object that was previously added by AddMQ2Data.
 * 
 * @param name The name of the TLO to removed.
 * @return True if the TLO was removed successfully.
 */
MQLIB_API bool RemoveMQ2Data(const char* name);

/**
 * Find and return a pointer to the MQDataItem structure representing a registered TLO.
 * 
 * @param name The name of the TLO to find.
 * @return A pointer to the registered MQDataItem if it exists, otherwise nullptr.
 */
MQLIB_API MQDataItem* FindMQ2Data(const char* name);

//----------------------------------------------------------------------------
// Compatibility shims

using fMQData = bool(*)(const char*, MQTypeVar&);

MQLIB_API bool AddMQ2Data(const char* szName, fMQData Function);

//----------------------------------------------------------------------------
// Deprecated functions

inline namespace deprecated
{
	using fMQDataOld = int(*)(char*, MQTypeVar&);

	DEPRECATE("The data function's signature must be updated to bool functionName(const char* szIndex, MQTypeVar& ret)")
	inline bool AddMQ2Data(const char* szName, fMQDataOld Function)
	{
		// This cast is safe only due to the fact that the function signature is equivalent with the key difference
		// being we're adding a const to a param.
#pragma warning(suppress: 4191)
		return AddMQ2Data(szName, (fMQData)Function);
	}
}

} // namespace mq
