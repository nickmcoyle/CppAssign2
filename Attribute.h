#pragma once
#include <string>
#include <list>

namespace VG {

	class Attribute {
	private:
		
	public:
		Attribute();
		Attribute(std::string const& attributeName, std::string const& attributeValue);

		Attribute(const Attribute& other) = default;
		Attribute(Attribute&& other) = default;

		Attribute & operator=(const Attribute&) = default;
		Attribute & operator=(Attribute&&) = default;

		std::string const& getAttributeName() const;	
		std::string const& getAttributeValue() const;

		bool empty();
		
		bool operator==(const Attribute& rhs);
		bool operator!=(const Attribute& rhs);

	private:
		std::string attributeName;
		std::string attributeValue;		
	};

	
}