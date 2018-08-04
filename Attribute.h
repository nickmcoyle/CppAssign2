#pragma once
#include <string>

namespace Xml
{

	class Attribute {
	private:
		
	public:
		Attribute() = default;
		Attribute(std::string const& attributeName, std::string const& attributeValue);

		Attribute(const Attribute& other) = default;
		Attribute(Attribute&& other) = default;

		Attribute & operator=(const Attribute&) = default;
		Attribute & operator=(Attribute&&) = default;

		std::string const& getAttributeName() const;	
		std::string const& getAttributeValue() const;

		bool empty();		

	private:
		std::string attributeName;
		std::string attributeValue;				
	};

	
}