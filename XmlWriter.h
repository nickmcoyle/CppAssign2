#pragma once
#include "Element.h"
#include "Attribute.h"
#include "TinyXML2\Include\tinyxml2.h"
#include "XmlReader.h"
#include <map>
#include <vector>
#include <iostream>

using namespace tinyxml2;

namespace Xml
{
	class Writer
	{
	public:
		Writer();

		static void writeXml(HElement root);
		static std::ostream& writeXml(HElement root, std::ostream& stream);

	private:
	
	};

}
