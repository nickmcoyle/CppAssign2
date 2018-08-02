#include "XmlWriter.h"

namespace Xml
{
	Writer::Writer()
	{}

	
	const HElement Writer::writeXml(HElement root, std::ostream& stream)
	{
		/*
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

		HElement hElement(new Element(root->Name()));
		auto attr = root->FirstAttribute();
		while (attr != nullptr)
		{
			(*hElement).addAttribute(Attribute(attr->Name(), attr->Value()));
			attr = attr->Next();
		}

		auto layerChild = root->FirstChildElement();

		while (layerChild != nullptr)
		{
			HElement layerElement = getElementAndAttributes(layerChild);
			auto placedGraphicChild = layerChild->FirstChildElement();
			while (placedGraphicChild != nullptr)
			{
				HElement placedGraphicElement = getElementAndAttributes(placedGraphicChild);
				auto vectorGraphicChild = placedGraphicChild->FirstChildElement();
				while (vectorGraphicChild != nullptr)
				{
					HElement vectorGraphicElement = getElementAndAttributes(vectorGraphicChild);
					auto pointChild = vectorGraphicChild->FirstChildElement();
					while (pointChild != nullptr)
					{
						HElement pointElement = getElementAndAttributes(pointChild);
						(*vectorGraphicElement).addChildElement(pointElement);
						pointChild = pointChild->NextSiblingElement();
					}
					(*placedGraphicElement).addChildElement(vectorGraphicElement);
					vectorGraphicChild = vectorGraphicChild->NextSiblingElement();
				}
				(*layerElement).addChildElement(placedGraphicElement);
				placedGraphicChild = placedGraphicChild->NextSiblingElement();
			}
			(*hElement).addChildElement(layerElement);
			layerChild = layerChild->NextSiblingElement();

		}
		*/
		HElement hElement(new Element());
		return hElement;
		
	}


}
