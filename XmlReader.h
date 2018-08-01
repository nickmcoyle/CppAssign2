#pragma once
#include "Element.h"
#include "Attribute.h"
#include "TinyXML2\Include\tinyxml2.h"
#include <memory>
#include <sstream>
#include <string>

using namespace tinyxml2;

namespace Xml
{		
	using AttributeMap = std::list<VG::Attribute>;
	using ElementList = std::list<VG::Element>;
	using HElement = std::shared_ptr<VG::Element>;

	class Reader
	{	
	public:	
		Reader();

		static HElement loadXml(const char* xml);
		static HElement loadXml(std::stringstream& xml);

		//VG::Attribute operator[](const char* attribute) const;	
			
	private:
		AttributeMap attributes;
		ElementList elements;		
	};

	std::stringstream& operator>>(std::stringstream& in, XMLNode & base);	
}