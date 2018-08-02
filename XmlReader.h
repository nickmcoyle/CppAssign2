#pragma once
#include "Element.h"
#include "Attribute.h"
#include "TinyXML2\Include\tinyxml2.h"
#include <map>
#include <vector>
#include <sstream>

using namespace tinyxml2;

namespace Xml
{
	using HElement = std::shared_ptr<Element>;
	using ElementList = std::vector<HElement>;	
	
	class Reader
	{
	public:
		Reader();
		
		static const Element::HElement loadXml(std::stringstream& xml);			

	private:		
		ElementList elements;
	};	
	
}
