#pragma once
#include "XmlReader.H"
#include "Scene.h"
#include "Point.h"
#include "VectorGraphic.h"
#include <iostream>

namespace Framework 
{
	
	class SceneReader 
	{
	public:
		SceneReader();

		static Scene readScene(Xml::Element& root);
	};
	

}
