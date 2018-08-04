#include "XmlWriter.h"
#include "XmlReader.h"
#include "VectorGraphic.h"
#include "TestHarness.h"


#define STR(a) #a

const char* const SceneXml = STR(
<Scene width="800" height="600">
  <Layer alias="sky">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="true">
        <Point x="7" y="8" />
        <Point x="9" y="10" />
        <Point x="11" y="12" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>);


TEST(writeXml, XmlWriter)
{	
    std::stringstream xmlStream(SceneXml);
	std::stringstream returnXmlStream;
    Xml::HElement root = Xml::Reader::loadXml(xmlStream);
    //Xml::Writer::writeXml(root, std::cout);
	Xml::Writer::writeXml(root, returnXmlStream);

	// TODO: find a good automated way to verify instead of looking at cout.
	// Strings don't have to be equal, so string comparison wouldn't work well.
	/*
	my solution is to write the HElement to a stringstream using XmlWriter and then read that stringstream back to an HElement using XmlReader
	then I can run automated tests on it
	*/
	Xml::HElement returned = Xml::Reader::loadXml(returnXmlStream);

	CHECK_EQUAL("Scene", returned->getName());
	CHECK_EQUAL("800", returned->getAttribute("width"));
	CHECK_EQUAL("600", returned->getAttribute("height"));
	CHECK(returned->getAttribute("depth").empty());

	Xml::ElementList children = returned->getChildElements();
	CHECK(!children.empty());
	CHECK_EQUAL(2, children.size());


	Xml::HElement layer0 = children[0];
	CHECK_EQUAL("Layer", layer0->getName());
	Xml::AttributeMap attributes = layer0->getAttributes();
	CHECK(!attributes.empty());
	CHECK_EQUAL(1, attributes.size());
	CHECK_EQUAL("sky", layer0->getAttribute("alias"));



	Xml::ElementList layerChildren = layer0->getChildElements();
	CHECK(!layerChildren.empty());
	CHECK_EQUAL(2, layerChildren.size());
	Xml::HElement placedGraphic = layerChildren[0];
	CHECK_EQUAL("PlacedGraphic", placedGraphic->getName());
	attributes = placedGraphic->getAttributes();
	CHECK(!attributes.empty());
	CHECK_EQUAL(2, attributes.size());
	CHECK_EQUAL("0", placedGraphic->getAttribute("x"));
	CHECK_EQUAL("0", placedGraphic->getAttribute("y"));    
    
}