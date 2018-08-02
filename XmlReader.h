#pragma once
#include "Element.h"
#include "Attribute.h"
#include "TinyXML2\Include\tinyxml2.h"
#include <memory>
#include <map>
#include <sstream>
#include <string>

using namespace tinyxml2;

namespace Xml
{
	using HElement = std::shared_ptr<VG::Element>;
	using ElementList = std::list<HElement>;
	using AttributeMap = std::map<std::string, std::string>;
	
	class Reader
	{
	public:
		Reader();

		static HElement loadXml(const char* xml);
		static HElement loadXml(std::stringstream& xml);			

		//HElement const& operator[](int index);

	private:
		AttributeMap attributes;
		ElementList children;	
		
	};	
	
}
