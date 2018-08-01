#pragma once
#include "TinyXML2\Include\tinyxml2.h"
#include "Element.h"
#include "Attribute.h"
#include <memory>
#include <sstream>
#include <string>

using namespace tinyxml2;

namespace Xml
{
	typedef std::shared_ptr<VG::Element> HElement;
	using HElement = std::shared_ptr<VG::Element>;
	typedef std::list<VG::Attribute> AttributeMap;
	typedef std::list<VG::Element> ElementList;

	class Reader
	{
	public:	
		static HElement loadXml(const char* xml);
		static HElement loadXml(std::stringstream& xml);

		Reader();
		//VG::Attribute operator[](const char* attribute) const;	
			
	private:
		AttributeMap attributes;
		ElementList elements;
	};

	std::stringstream& operator>>(std::stringstream& in, XMLNode & base);
	
}