#pragma once
#include "TinyXML2\Include\tinyxml2.h"
#include "XmlReader.h"

using namespace tinyxml2;

namespace Xml
{
	class Writer
	{
	public:
		Writer();
				
		static void writeXml(HElement root, std::stringstream& stream);

	private:
	
	};

}
