#include "SceneReader.h"

namespace Framework
{

	SceneReader::SceneReader()
	{}

	Scene SceneReader::readScene(Xml::Element& root)
	{
		Scene scene(atoi(root.getAttribute("width").c_str()), atoi(root.getAttribute("height").c_str()));
	
		Xml::ElementList layers = root.getChildElements();
		//Xml::ElementList placedGraphics =
			//Xml::ElementList vectorGraphics =
			//Xml::ElementList points =
				
		for (int i = 0; i < layers.size(); ++i)
		{			
			Xml::ElementList placedGraphics = (*layers[i]).getChildElements();
			for (int i = 0; i < placedGraphics.size(); ++i)
			{
				int x = atoi((*placedGraphics[i]).getAttribute("x").c_str());
				int y = atoi((*placedGraphics[i]).getAttribute("y").c_str());
			}
			Layer layer((*layers[i]).getAttribute("alias"));

			scene.pushBack(layer);
		}
		int i = 0;
		return scene;
	}

}