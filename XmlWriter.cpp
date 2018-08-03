#include "XmlWriter.h"

namespace Xml
{
	Writer::Writer()
	{}

	void Writer::writeXml(HElement root)
	{	
		XMLDocument myDoc;

		auto sceneElem = myDoc.NewElement("Scene");
		sceneElem->SetAttribute("width", 1);
		sceneElem->SetText("Some text");
		myDoc.InsertEndChild(sceneElem);

		myDoc.SaveFile("output.xml");
		
	}

	std::ostream& Writer::writeXml(HElement root, std::ostream& stream)
	{
		XMLDocument myDoc;

		auto hScene = (*root);
		auto sceneElem = myDoc.NewElement("Scene");			
		sceneElem->SetAttribute("width", hScene.getAttribute("width").c_str());
		sceneElem->SetAttribute("height", hScene.getAttribute("height").c_str());
		myDoc.InsertFirstChild(sceneElem);

		auto hLayers = (*root).getChildElements();

		for (const auto& layer : hLayers)
		{
			auto layerElem = myDoc.NewElement("Layer");
			layerElem->SetAttribute("alias", (*layer).getAttribute("alias").c_str());
			if(myDoc.FirstChildElement("Scene")->FirstChildElement("Layer") != nullptr)
			{
				myDoc.FirstChildElement("Scene")->LastChildElement("Layer")->InsertFirstChild(layerElem);
			}
			else {
				myDoc.FirstChildElement("Scene")->InsertFirstChild(layerElem);
			}

				auto hPlacedGraphics = (*layer).getChildElements();
				for (const auto& placedGraphic : hPlacedGraphics)
				{
					auto placedGraphicElem = myDoc.NewElement("PlacedGraphic");
					placedGraphicElem->SetAttribute("x", (*placedGraphic).getAttribute("x").c_str());
					placedGraphicElem->SetAttribute("y", (*placedGraphic).getAttribute("y").c_str());
					myDoc.FirstChildElement("Scene")->LastChildElement("Layer")->InsertFirstChild(placedGraphicElem);

					auto hVectorGraphics = (*placedGraphic).getChildElements();
					for (const auto& vectorGraphic : hVectorGraphics)
					{
						auto vectorGraphicElem = myDoc.NewElement("VectorGraphic");
						vectorGraphicElem->SetAttribute("closed", (*vectorGraphic).getAttribute("closed").c_str());
						myDoc.FirstChildElement("Scene")->FirstChildElement("Layer")->FirstChildElement("PlacedGraphic")->InsertFirstChild(vectorGraphicElem);

							auto hPoints = (*vectorGraphic).getChildElements();
							for (const auto& point : hPoints)
							{
								auto pointElem = myDoc.NewElement("Point");
								pointElem->SetAttribute("x", (*point).getAttribute("x").c_str());
								pointElem->SetAttribute("y", (*point).getAttribute("y").c_str());
								myDoc.FirstChildElement("Scene")->FirstChildElement("Layer")->FirstChildElement("PlacedGraphic")->FirstChildElement("VectorGraphic")->InsertEndChild(pointElem);
							}
							
					}
					
				}
				
				
		}		
		
		int i = 0;
		//myDoc.Print(stream);
		//tinyxml2::dump_to_stdout(&mydoc);
		myDoc.SaveFile("output.xml");
		return stream;
	}


}
