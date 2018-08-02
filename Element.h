#pragma once
#include "Attribute.h"
#include <map>
#include <string>
#include <list>
#include <memory>
#include <vector>

namespace Xml
{
	
	class Element {		
	public:
		using HElement = std::shared_ptr<Element>;
		using ElementList = std::vector<HElement>;

	private:
		using AttributeCollection = std::list <Attribute>;	

	public:
		Element();		
		Element(std::string name);

		Element(const Element& other) = default;
		Element(Element&& other) = default;

		Element & operator=(const Element&) = default;
		Element & operator=(Element&&) = default;

		void addChildElement(HElement const& element);

		ElementList const& getChildElements() const;		
		
	    std::map<std::string, std::string> const getAttributes();

		std::string const& getName();		
		
		void addAttribute(Attribute const& attribute);
		std::string const getAttribute(std::string const& attributeName);		
		

	private:				
		ElementList children;
		AttributeCollection attributes;
		std::string name;
	};
	
	
}