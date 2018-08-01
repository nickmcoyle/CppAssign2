#include "Element.h"
#include <algorithm>

namespace VG 
{

	Element::Element() 
	{}

	Element::Element(std::string name)
		:name(name)		
	{}

	Element::ElementCollection const& Element::getChildElements() const
	{
		//elements.push_back("");
		return childElements;
	}

	std::string const& Element::getName()
	{
		return name;
	}		
	/*
	Xml::AttributeMap const& Element::getAttributes() const
	{
		//scan for attributes?
		Xml::AttributeMap AttributeMap(new Xml::AttributeMap());
		return attrMap;
	}
	*/
	std::string const Element::getAttribute(std::string const& attributeName)
	{		
		AttributeCollection::iterator it = attributes.begin();
		while (it != attributes.end())
		{
			if ((*it).getAttributeName() == attributeName)
			{
				return (*it).getAttributeValue();
			}
			++it;
		}		
		return "";
	}

	void Element::addAttribute(Attribute const& attribute)
	{
		attributes.push_back(attribute);
	}
			
}