#include "Element.h"
#include <algorithm>

namespace VG {

	Element::Element() 
	{}

	Element::Element(std::stringstream const& xmlStream)
	{}

	Element::ElementCollection const& Element::getChildElements() const
	{
		//elements.push_back("");
		return elements;
	}

	std::string const& Element::getName()
	{
		return tagName;
	}		
	
	Xml::AttributeMap const& Element::getAttributes() const
	{
		//scan for attributes?
		Xml::AttributeMap attrMap( new Xml::AttributeMap() );
		return attrMap;
	}
	
	Attribute Element::getAttribute(std::string const& attributeName)
	{		
		Attribute attr(attributeName, "");
		return attr;
	}
			
}