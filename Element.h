#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include "Attribute.h"

namespace Xml
{

	using AttributeMap = std::map<std::string, std::string>;

	class Element {	

	public:
		using HElement = std::shared_ptr<Element>;
		using ElementList = std::vector<HElement>;	
	
		Element() = default;
		Element(std::string name);

		Element(const Element& other) = default;
		Element(Element&& other) = default;		

		Element & operator=(const Element&) = default;
		Element & operator=(Element&&) = default;

		std::string const& getName();

		void addChildElement(const HElement& element);
		void addChildElement(HElement&& element);

		ElementList const& getChildElements() const;			    	
		
		void addAttribute(const Attribute& attribute);		
		void addAttribute(Attribute&& attribute);		
		std::string const getAttribute(std::string const& attributeName);	

		std::map<std::string, std::string> const getAttributes();			

	private:				
		ElementList children;		
		AttributeMap attributes;
		std::string name;
	};
	
	
}