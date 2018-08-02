#pragma once
#include "XmlReader.H"
#include "Scene.h"

namespace Framework 
{
	
	class SceneReader 
	{
	public:
		SceneReader();

		static Scene readScene(Xml::Element& root);
	};
	

}
