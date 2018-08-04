#include "Attribute.h"

namespace Xml
{

	Attribute::Attribute(std::string const& attributeName, std::string const& attributeValue)
		: attributeName(attributeName),
		attributeValue(attributeValue)
	{
	}

	std::string const& Attribute::getAttributeName() const
	{
		return attributeName;
	}

	std::string const& Attribute::getAttributeValue() const
	{
		return  attributeValue;
	}

	bool Attribute::empty()
	{
		return !(attributeName.length() > 0);
	}
	
}
