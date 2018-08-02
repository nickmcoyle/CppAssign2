#pragma once
#include "Attribute.h"
#include <map>
#include <string>
#include <list>
#include <memory>

namespace VG 
{
	
	class Element {
		
	private:
		using HElement = std::shared_ptr<Element>;
		using ElementCollection = std::list <HElement>;
		using AttributeCollection = std::list <Attribute>;

	public:
		Element();		
		Element(std::string name);

		Element(const Element& other) = default;
		Element(Element&& other) = default;

		Element & operator=(const Element&) = default;
		Element & operator=(Element&&) = default;

		void addChildElement(HElement const& element);

		ElementCollection const& getChildElements() const;		
		
	    std::map<std::string, std::string> const getAttributes();

		std::string const& getName();		
		
		void addAttribute(Attribute const& attribute);
		std::string const getAttribute(std::string const& attributeName);		
		

	private:				
		ElementCollection childElements;
		AttributeCollection attributes;
		std::string name;
	};
	
	
}