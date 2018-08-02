#pragma once
#include "Element.h"
#include "Attribute.h"
#include "TinyXML2\Include\tinyxml2.h"
#include <map>
#include <vector>
#include <iostream>

using namespace tinyxml2;

namespace Xml
{
	using HElement = std::shared_ptr<Element>;
	using ElementList = std::vector<HElement>;

	class Writer
	{
	public:
		Writer();

		static const Element::HElement writeXml(HElement root, std::ostream& stream);

	private:
		ElementList elements;
	};

}
