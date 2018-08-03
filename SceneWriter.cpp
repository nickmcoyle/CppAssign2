#include "SceneWriter.h"


namespace Framework
{
	SceneWriter::SceneWriter()
	{}

	Xml::HElement SceneWriter::writeScene(Scene& root)
	{
		Xml::HElement hElement(new Xml::Element(("Scene")));
		(*hElement).addAttribute(Xml::Attribute("width", std::to_string(root.getWidth())));
		(*hElement).addAttribute(Xml::Attribute("height", std::to_string(root.getHeight())));

		auto layerCollection = root.getLayers();
		for (const auto& layer : layerCollection)
		{
			Xml::HElement layerElement(new Xml::Element("Layer"));
			(*layerElement).addAttribute(Xml::Attribute("alias", layer.getAlias()));
			
			auto placedGraphicCollection = layer.getPlacedGraphics();
			for (const auto& placedGraphic : placedGraphicCollection)
			{
				PlacedGraphic myPG = placedGraphic;
				Xml::HElement placedGraphicElement(new Xml::Element("PlacedGraphic"));
				(*placedGraphicElement).getAttribute("PlacementPoint");
				Point placementPoint(myPG.getPlacementPoint());
				Xml::Attribute attrPPX("x", std::to_string(placementPoint.getX()));
				Xml::Attribute attrPPY("y", std::to_string(placementPoint.getY()));
				(*placedGraphicElement).addAttribute(attrPPX);
				(*placedGraphicElement).addAttribute(attrPPY);

				VG::VectorGraphic myVG = placedGraphic.getGraphic();

				Xml::HElement vectorGraphicElement(new Xml::Element("VectorGraphic"));
				std::string closed;
				(myVG.isClosed() == true)? closed = "true" : closed = "false";
				(*vectorGraphicElement).addAttribute(Xml::Attribute("closed", closed));

				for (const auto& point : myVG.getPoints())
				{					
					Xml::HElement pointElement(new Xml::Element("Point"));					
					(*pointElement).addAttribute(Xml::Attribute("x", std::to_string(point.getX())));
					(*pointElement).addAttribute(Xml::Attribute("y", std::to_string(point.getY())));
					(*vectorGraphicElement).addChildElement(pointElement);								
				}
				(*placedGraphicElement).addChildElement(vectorGraphicElement);				
				(*layerElement).addChildElement(placedGraphicElement);
			}			
			(*hElement).addChildElement(layerElement);			
		}
		int i = 0;
		return hElement;
	}
}