#pragma once
#include "Attribute.h"
#include <string>

namespace VG {

	class Element {
	private:

		typedef std::list<Attribute> AttributeCollection;

	public:
		Element();
		Element(std::stringstream xmlStream);

		Element(const Element& other) = default;
		Element(Element&& other) = default;

		Element & operator=(const Element&) = default;
		Element & operator=(Element&&) = default;

		Element const& getElementChildren() const;

		bool hasTagName(std::string const& possibleTagName);

		Attribute const& getAttribute() const;
		
		std::string const& getAttributeName(std::string const& attributeName);
		std::string const& getAttributeValue(std::string const& attributeName);

	private:
		AttributeCollection attributes;
		std::string tagName;
	};

}