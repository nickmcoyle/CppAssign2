#include "XmlReader.h"

namespace Xml
{
	
	HElement Reader::loadXml(const char* xml)
	{

	XMLDocument xmlDoc; //empty XML document to store the data from the file
	xmlDoc.Parse(xml);
	//XMLError eResult = xmlDoc.LoadFile("MyVectorGraphic.xml");

	XMLNode * rootPtr = xmlDoc.FirstChild();
	//if (rootPtr == nullptr)
		//return XML_ERROR_FILE_READ_ERROR;	

	XMLElement* elementPtr = xmlDoc.FirstChildElement("Layer");
	const char* layerAlias = elementPtr->GetText();	

	//return XML_SUCCESS;
	HElement el(new VG::Element);

	return el;
	}

	HElement Reader::loadXml(std::stringstream& xml)
	{
		XMLDocument xmlDoc; //empty XML document to store the data from the file
		xml >> xmlDoc;
		
		/*
		const char* xmlChar;
		xml << xmlChar;
		xmlDoc.Parse(xmlChar);
		*/
		
		//return XML_SUCCESS;
		HElement el(new VG::Element);
		return el;
	}

	Reader::Reader() 
	{}

	std::stringstream& operator>>(std::stringstream& in, XMLNode & base)
	{
		//in >> base;
		return in;
	}
}
