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