#include "stdafx.h"

#include "Utility/Region3int16.h"
#include "Utility/ExtentsInt32.h"
#include "Reflection/Type.h"
namespace RBX {
	
namespace Reflection
{
	template<>
	const Type& Type::getSingleton<Region3int16>()
	{
		static TType<Region3int16> type("Region3int16");
		return type;
	}
}

}