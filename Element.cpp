#include "Element.h"


namespace Xml
{

	Element::Element(std::string name)
		:name(name)		
	{}

	std::string const& Element::getName()
	{
		return name;
	}

	void Element::addChildElement(HElement const& element)
	{
		//should we guard against an Element adding itself as a child here?
		children.push_back(element);
	}

	void Element::addChildElement(HElement&& element)
	{
		//should we guard against an Element adding itself as a child here?
		children.emplace_back(std::move(element));
	}

	Element::ElementList const& Element::getChildElements() const
	{		
		return children;
	}		

	std::string const Element::getAttribute(std::string const& attributeName)
	{				
		std::map<std::string, std::string>::iterator it = attributes.find(attributeName);
			
		if (it != attributes.end())
		{
			return attributes[attributeName];
		}
		else return "";
	}

	void Element::addAttribute(const Attribute& attribute)
	{			
		attributes.insert( std::pair<std::string, std::string>(attribute.getAttributeName(), attribute.getAttributeValue()));
	}

	void Element::addAttribute(Attribute&& attribute)
	{
		attributes.emplace(std::move(std::pair<std::string, std::string>(attribute.getAttributeName(), attribute.getAttributeValue())));		
	}
	
	std::map<std::string, std::string> const Element::getAttributes()
	{
		return attributes;
	}

	
}