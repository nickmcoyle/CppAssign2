#include "Attribute.h"

namespace Xml
{

	Attribute::Attribute()
	{
	}

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
		
	bool Attribute::operator==(const Attribute& rhs)
	{
		//return (&lhs.getAttributeName() == &rhs.getAttributeName() && &lhs.getAttributeValue == &rhs.getAttributeValue());
		return true;
	}

	bool Attribute::operator!=(const Attribute& rhs)
	{
		return !(*this == rhs);
	}
	
}
