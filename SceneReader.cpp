#include "SceneReader.h"


namespace Framework
{

	SceneReader::SceneReader()
	{}

	Scene SceneReader::readScene(Xml::Element& root)
	{
		int sceneWidth = atoi(root.getAttribute("width").c_str());
		int sceneHeight = atoi(root.getAttribute("height").c_str());
		if (!sceneWidth || !sceneHeight)
		{
			throw std::invalid_argument("the scene is missing a valid width or height.");
		}

		Scene myScene(sceneWidth,sceneHeight);
	
		Xml::ElementList layers = root.getChildElements();		
				
		for (const auto& layer : layers)
		{				
			std::string layerAlias = (*layer).getAttribute("alias");
			
			if (layerAlias == "") 
			{
				throw std::invalid_argument("scene is missing valid layer tags.");
			}
			Layer myLayer(layerAlias);

			Xml::ElementList placedGraphics = (*layer).getChildElements(); //get all placed graphics of this layer
			
			for (const auto& placedGraphic : placedGraphics)
			{	
				int x = std::stoi((*placedGraphic).getAttribute("x"));				
				int y = std::stoi((*placedGraphic).getAttribute("y"));				
				if(x < 0 || y < 0)
				{					
					throw std::invalid_argument("the placedgraphic is missing a valid x and y placement point.");
				}
				VG::Point placementPoint(x, y);
				
				Xml::ElementList vectorGraphics = (*placedGraphic).getChildElements(); //get all vector graphics inside placed graphic
				
				HVectorGraphic myVG(new VG::VectorGraphic);				

					for (const auto& vectorGraphic : vectorGraphics)
					{
						std::string openClosed = (*vectorGraphic).getAttribute("closed");						 
						if (openClosed.compare("true") != 0 && openClosed.compare("false") != 0 )
						{
							throw std::invalid_argument("the vectorgraphic is missing a valid shapestyle tag.");
						}

						(openClosed.compare("true") == 0) ? (*myVG).closeShape() : (*myVG).openShape();

						Xml::ElementList points = (*vectorGraphic).getChildElements(); //get all points inside vector graphic				 						
						
						for (const auto& point : points)
						{		
							int x = std::stoi((*point).getAttribute("x"));
							int y = std::stoi((*point).getAttribute("y"));							
							if (x < 0 || y < 0)
							{
								throw std::invalid_argument("the point is missing a valid x and y coordinate.");
							}
							(*myVG).addPoint(Point(x, y));
						}									
					}	
				PlacedGraphic myPG(placementPoint, myVG);
				myLayer.insert(myPG);
			}
			myScene.pushBack(myLayer);
		}		
		return myScene;
	}

}