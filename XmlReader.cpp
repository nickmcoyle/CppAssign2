#include "XmlReader.h"

namespace Xml
{
	Reader::Reader()
	{}

	XMLElement* getChildren(XMLElement* sibling)
	{
		//HElement hChildElement(new VG::Element(sibling->Name()));
		
		auto attr = sibling->FirstAttribute();
		while (attr != nullptr)
		{
			VG::Attribute attribute(attr->Name(), attr->Value());
			(*hChildElement).addAttribute(attribute);
			attr = attr->Next();
		}
		return 
	}

	HElement Reader::loadXml(const char* xml)
	{
		HElement el(new VG::Element());
		return el;
	}

	HElement Reader::loadXml(std::stringstream& xml)
	{		 
		/*
		start with root element and create a new hElement from it
		iterate through and add all its attributes (easy)
		iterate until end tag adding each child element to a collection of childElements
		also iterate through each of those children creating a new hElement from them and getting their attributes
		*/
		XMLDocument myDoc; //empty XML document to store the data from the file
		
		auto result = myDoc.Parse(xml.str().c_str());
		if (result != XML_SUCCESS)
		{
			throw std::runtime_error{ "Could not load xml: file read error" };
		}

		auto root = myDoc.RootElement();
		if (root == nullptr)
		{
			throw std::runtime_error{ "Invalid xml: cannot find root element" };
		}

		auto attr = root->FirstAttribute();
		HElement hElement(new VG::Element(root->Name()));

		while (attr != nullptr) //gets the attributes
		{
			VG::Attribute attribute(attr->Name(), attr->Value());
			(*hElement).addAttribute(attribute);
			attr = attr->Next();
		}

		auto sibling = root->FirstChildElement(); //gets the child elements
		
		while (sibling != nullptr)
		{
			HElement hChildElement(new VG::Element(sibling->Name()));
			auto attr = sibling->FirstAttribute();
			while (attr != nullptr)
			{
				VG::Attribute attribute(attr->Name(), attr->Value());
				(*hChildElement).addAttribute(attribute);
				attr = attr->Next();
			}
			(*hElement).addChildElement(hChildElement);
			sibling = sibling->NextSiblingElement();
		}		
		

		return hElement;
	}

	

	/*
	HElement& Reader::operator[](int index)
	{
		if (index >= children.size() || index < 0)
		{
			throw std::runtime_error{ "Index out of range: attempt to access ElementList" };
		}
		ElementList::iterator it = children.begin();
		for (int i = 0; i < index; ++i)
		{
			++it;
		}
		return (*it);
	}
	*/
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
	
}
