#pragma once
#include "Attribute.h"
#include <string>
#include <list>

namespace VG 
{
	
	class Element {
		
	private:		
		using ElementCollection = std::list <Element>;
		using AttributeCollection = std::list <Attribute>;

	public:
		Element();		
		Element(std::string name);

		Element(const Element& other) = default;
		Element(Element&& other) = default;

		Element & operator=(const Element&) = default;
		Element & operator=(Element&&) = default;

		ElementCollection const& getChildElements() const;		
		
		//Xml::AttributeMap const& getAttributes() const;

		std::string const& getName();		
		
		std::string const getAttribute(std::string const& attributeName);

		void addAttribute(Attribute const& attribute);
		

	private:		
		ElementCollection childElements;
		AttributeCollection attributes;
		std::string name;
	};
	
}