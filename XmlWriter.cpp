#include "XmlWriter.h"

namespace Xml
{
	Writer::Writer()
	{}	
		
	void Writer::writeXml(HElement root, std::stringstream& stream)
	{
		XMLDocument myDoc;

		auto hScene = (*root);
		auto sceneElem = myDoc.NewElement("Scene");			
		sceneElem->SetAttribute("width", hScene.getAttribute("width").c_str());
		sceneElem->SetAttribute("height", hScene.getAttribute("height").c_str());
		myDoc.InsertFirstChild(sceneElem);

		auto hLayers = (*root).getChildElements();		
		for(Xml::ElementList::reverse_iterator it = hLayers.rbegin(); it != hLayers.rend(); ++it)
		{
			auto layer = (*it);
			auto layerElem = myDoc.NewElement("Layer");
			layerElem->SetAttribute("alias", (*layer).getAttribute("alias").c_str());			
			myDoc.FirstChildElement("Scene")->InsertFirstChild(layerElem);

				auto hPlacedGraphics = (*layer).getChildElements();				
				for (Xml::ElementList::reverse_iterator it = hPlacedGraphics.rbegin(); it != hPlacedGraphics.rend(); ++it)
				{
					auto placedGraphic = (*it);
					auto placedGraphicElem = myDoc.NewElement("PlacedGraphic");
					placedGraphicElem->SetAttribute("x", (*placedGraphic).getAttribute("x").c_str());
					placedGraphicElem->SetAttribute("y", (*placedGraphic).getAttribute("y").c_str());
					myDoc.FirstChildElement("Scene")->FirstChildElement("Layer")->InsertFirstChild(placedGraphicElem);

					auto hVectorGraphics = (*placedGraphic).getChildElements();					
					for (Xml::ElementList::reverse_iterator it = hVectorGraphics.rbegin(); it != hVectorGraphics.rend(); ++it)
					{
						auto vectorGraphic = (*it);
						auto vectorGraphicElem = myDoc.NewElement("VectorGraphic");
						vectorGraphicElem->SetAttribute("closed", (*vectorGraphic).getAttribute("closed").c_str());
						myDoc.FirstChildElement("Scene")->FirstChildElement("Layer")->FirstChildElement("PlacedGraphic")->InsertFirstChild(vectorGraphicElem);

							auto hPoints = (*vectorGraphic).getChildElements();							
							for (Xml::ElementList::iterator it = hPoints.begin(); it != hPoints.end(); ++it)
							{
								auto point = (*it);
								auto pointElem = myDoc.NewElement("Point");
								pointElem->SetAttribute("x", (*point).getAttribute("x").c_str());
								pointElem->SetAttribute("y", (*point).getAttribute("y").c_str());
								myDoc.FirstChildElement("Scene")->FirstChildElement("Layer")->FirstChildElement("PlacedGraphic")->FirstChildElement("VectorGraphic")->InsertEndChild(pointElem);
							}							
					}					
				}								
		}		
		XMLPrinter printer(0, true, 0);
		myDoc.Print(&printer);		
		stream << printer.CStr();		

		//myDoc.SaveFile("output.xml");	
	}


}
