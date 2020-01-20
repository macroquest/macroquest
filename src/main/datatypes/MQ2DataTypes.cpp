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

#include "pch.h"
#include "MQ2DataTypes.h"

namespace mq::datatypes {
//----------------------------------------------------------------------------
// Datatype Definitions

#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
			Class* Var = nullptr;
#include "DataTypeList.h"
#undef DATATYPE

//----------------------------------------------------------------------------
// DataType Initializations
void InitializeMQ2DataTypes()
{
#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
			Var = new Class();                                               \
			if (Inherits != nullptr) {                                       \
				Var->SetInheritance(Inherits);                               \
			}
#include "DataTypeList.h"
#undef DATATYPE
}

//----------------------------------------------------------------------------
// DataType Shutdown
void ShutdownMQ2DataTypes()
{
#define DATATYPE(Class, Var, Inherits, PersistentClass)              \
			delete Var;
#include "DataTypeList.h"
#undef DATATYPE
}
}