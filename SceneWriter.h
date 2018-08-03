#pragma once
#include "XmlReader.H"
#include "Scene.h"
#include "Point.h"
#include "VectorGraphic.h"

namespace Framework
{

	class SceneWriter
	{
	public:
		SceneWriter();

		static Xml::HElement writeScene(Scene& root);
	};


}