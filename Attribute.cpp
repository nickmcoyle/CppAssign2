#include "Attribute.h"

namespace VG
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

	bool operator==(const Attribute& lhs, const Attribute& rhs)
	{
		return (lhs.getAttributeName() == rhs.getAttributeName() && lhs.getAttributeValue == rhs.getAttributeValue());
	}

	bool operator!=(const Attribute& lhs, const Attribute& rhs)
	{
		return !(lhs == rhs);
	}

}
