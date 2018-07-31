#pragma once
#include <string>

namespace VG {

	class Attribute {
	public:
		Attribute();
		Attribute(std::string const& attributeName, std::string const& attributeValue);

		Attribute(const Attribute& other) = default;
		Attribute(Attribute&& other) = default;

		Attribute & operator=(const Attribute&) = default;
		Attribute & operator=(Attribute&&) = default;

		std::string const& getAttributeName() const;	
		std::string const& getAttributeValue() const;		

	private:
		std::string attributeName;
		std::string attributeValue;
	};

	bool operator==(const Attribute& lhs, const Attribute& rhs);
	bool operator!=(const Attribute& lhs, const Attribute& rhs);

	
}