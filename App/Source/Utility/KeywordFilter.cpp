#include "stdafx.h"

#include "Utility/KeywordFilter.h"
#include "Reflection/EnumConverter.h"

namespace RBX 
{
	namespace Reflection
	{
		template<>
		Reflection::EnumDesc<KeywordFilterType>::EnumDesc()
			:RBX::Reflection::EnumDescriptor("KeywordFilterType")
		{
			addPair(INCLUDE_KEYWORDS,"Include");
			addPair(EXCLUDE_KEYWORDS,"Exclude");
		}
	}
}
