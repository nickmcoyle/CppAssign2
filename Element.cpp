#include "Element.h"
#include <algorithm>

namespace VG 
{

	Element::Element() 
	{}

	Element::Element(std::string name)
		:name(name)		
	{}

	void Element::addChildElement(HElement const& element)
	{
		childElements.push_back(element);
	}

	Element::ElementCollection const& Element::getChildElements() const
	{		
		return childElements;
	}

	std::string const& Element::getName()
	{
		return name;
	}		
	
	std::map<std::string, std::string> const Element::getAttributes()
	{
		std::map<std::string, std::string> attributeMap;
		AttributeCollection::iterator it = attributes.begin();

		while (it != attributes.end())
		{
			attributeMap.emplace((*it).getAttributeName(), (*it).getAttributeValue());
			++it;
		}
		return attributeMap;
	}
	
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
	/*
	HElement& Element::operator[](int index)
	{
		if (index >= children.size() || index < 0)
		{
			throw std::runtime_error{ "Index out of range: attempt to access ElementList" };
		}
		ElementList::iterator it = children.begin();
		for (int i = 0; i < index; ++i)
		{
			++it;
		}
		return (*it);
	}
		*/	
}