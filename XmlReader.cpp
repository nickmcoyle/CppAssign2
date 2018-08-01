#include "XmlReader.h"

namespace Xml
{
	
	HElement Reader::loadXml(const char* xml)
	{

	XMLDocument xmlDoc; //empty XML document to store the data from the file
	xmlDoc.Parse(xml);	
	XMLNode * rootPtr = xmlDoc.FirstChildElement("Scene");	
	
	HElement el(new VG::Element());

	return el;
	}

	HElement Reader::loadXml(std::stringstream& xml)
	{		 
		XMLDocument myDoc; //empty XML document to store the data from the file
		
		auto result = myDoc.Parse(xml.str().c_str());
			
		auto root = myDoc.RootElement();
		auto attr = root->FirstAttribute();

		HElement hElement(new VG::Element(root->Name()));

		while (attr != nullptr)
		{
			VG::Attribute attribute(attr->Name(), attr->Value());
			(*hElement).addAttribute(attribute);
			attr = attr->Next();
		}	

		//auto 
				
		return hElement;
	}

	/*
	getAttribute()
	{
		if (rootPtr)
		{

			//int width = rootPtr->FirstChild.attribute("width");
			// = rootPtr->FirstChildElement("Layer")->Attribute("alias");
		}

	}
	*/

	Reader::Reader() 
	{}

	std::stringstream& operator>>(std::stringstream& in, XMLNode & base)
	{
		//in >> base;
		return in;
	}
}
