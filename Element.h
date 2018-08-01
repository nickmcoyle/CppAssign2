#pragma once
#include "Attribute.h"
#include <string>
#include <list>
#include "XmlReader.h"

namespace VG {

	class Element {
	private:

		
		typedef std::list <Element> ElementCollection;

	public:
		Element();
		Element(std::stringstream const& xmlStream);

		Element(const Element& other) = default;
		Element(Element&& other) = default;

		Element & operator=(const Element&) = default;
		Element & operator=(Element&&) = default;

		ElementCollection const& getChildElements() const;		

		Xml::AttributeMap const& getAttributes() const;

		std::string const& getName();		
		
		Attribute getAttribute(std::string const& attributeName);
		

	private:		
		ElementCollection elements;
		std::string tagName;
	};
	
}