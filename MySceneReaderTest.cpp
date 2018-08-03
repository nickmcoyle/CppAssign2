#include "XmlReader.h"
#include "Element.h"
#include "Scene.h"
#include "SceneReader.h"
#include "TestHarness.h"

const std::string TestXml = R"(
<Scene height="600">
  <Layer alias="sky">
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <!-- Comment -->
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <!-- Comment -->
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="false">
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
        <!-- etc... -->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";

const std::string TestXmlInvalidLayer = R"(
<Scene width="800" height="600">
  <Layer>
    <PlacedGraphic x="0" y="0">
      <VectorGraphic closed="true">
        <Point x="1" y="2" />
        <!-- Comment -->
        <Point x="3" y="4" />
        <Point x="5" y="6" />
      </VectorGraphic>
    </PlacedGraphic>
    <!-- Comment -->
    <PlacedGraphic x="700" y="0">
      <VectorGraphic closed="false">
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
        <!-- etc... -->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";

const std::string TestXmlInvalidPlacementPoint = R"(
<Scene width="800" height="600">
  <Layer alias="mountains">
    <PlacedGraphic x="sky" y="mountains">
      <VectorGraphic closed="false">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
        <!-- etc... -->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";

const std::string TestXmlInvalidClosedTag = R"(
<Scene width="800" height="600">  
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="flase">
        <Point x="13" y="14" />
        <Point x="15" y="19" />
        <Point x="17" y="18" />
        <!-- etc... -->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";


const std::string TestXmlInvalidPoints = R"(
<Scene width="800" height="600">  
  <Layer alias="mountains">
    <PlacedGraphic x="250" y="250">
      <VectorGraphic closed="false">
        <Point x="" y="O" />
        <Point x="e." y="19" />
        <Point x="17" y="18" />
        <!-- etc... -->
      </VectorGraphic>
    </PlacedGraphic>
  </Layer>
</Scene>)";


TEST(MyReadSceneInvalidWidth, SceneReader)
{
    std::stringstream xmlStream(TestXml);
    auto root = Xml::Reader::loadXml(xmlStream);
	
    auto s = Framework::SceneReader::readScene(*root); //should throw exception

    CHECK_EQUAL(800, s.getWidth());
    CHECK_EQUAL(600, s.getHeight());    
}

TEST(MyReadSceneInvalidLayer, SceneReader)
{
	std::stringstream xmlStream(TestXmlInvalidLayer);
	auto root = Xml::Reader::loadXml(xmlStream);

	auto s = Framework::SceneReader::readScene(*root); //should throw

	CHECK_EQUAL(800, s.getWidth());
	CHECK_EQUAL(600, s.getHeight());

	int numberOfLayers = 0;
	for (auto pos = s.begin(); pos != s.end(); ++numberOfLayers, ++pos)
	{	
	}

	// Expect 2 layers
	CHECK_EQUAL(2, numberOfLayers);
}

TEST(MyReadSceneInvalidPG, SceneReader)
{
	std::stringstream xmlStream(TestXmlInvalidPlacementPoint);
	auto root = Xml::Reader::loadXml(xmlStream);

	auto s = Framework::SceneReader::readScene(*root); //should throw
	
	int numberOfLayers = 0;
	for (auto pos = s.begin(); pos != s.end(); ++numberOfLayers, ++pos)
	{
		auto layer = (*pos);
		if (numberOfLayers == 0)
		{			
			Framework::Layer::PlacedGraphicIterator graphic;
			int iGraphic;
			for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
			{
				if (iGraphic == 0)
				{
					CHECK_EQUAL(VG::Point(0, 0), (*graphic).getPlacementPoint());
					auto vg = (*graphic).getGraphic();
					CHECK_EQUAL(true, vg.isClosed());
					CHECK_EQUAL(3, vg.getPointCount());
					CHECK_EQUAL(VG::Point(1, 2), vg.getPoint(0));
					CHECK_EQUAL(VG::Point(3, 4), vg.getPoint(1));
					CHECK_EQUAL(VG::Point(5, 6), vg.getPoint(2));
				}
				else if (iGraphic == 1)
				{
					CHECK_EQUAL(VG::Point(700, 0), (*graphic).getPlacementPoint());
					auto vg = (*graphic).getGraphic();
					CHECK_EQUAL(false, vg.isClosed());
				}
			}

			CHECK_EQUAL(2, iGraphic);
		}		
	}

}

TEST(MyReadSceneInvalidClosedTag, SceneReader)
{
	std::stringstream xmlStream(TestXmlInvalidClosedTag);
	auto root = Xml::Reader::loadXml(xmlStream);

	auto s = Framework::SceneReader::readScene(*root); //should throw

	int numberOfLayers = 0;
	for (auto pos = s.begin(); pos != s.end(); ++numberOfLayers, ++pos)
	{
		auto layer = (*pos);
		if (numberOfLayers == 0)
		{
			Framework::Layer::PlacedGraphicIterator graphic;
			int iGraphic;
			for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
			{
				if (iGraphic == 0)
				{
					CHECK_EQUAL(VG::Point(0, 0), (*graphic).getPlacementPoint());
					auto vg = (*graphic).getGraphic();
					CHECK_EQUAL(true, vg.isClosed());
					CHECK_EQUAL(3, vg.getPointCount());
					CHECK_EQUAL(VG::Point(1, 2), vg.getPoint(0));
					CHECK_EQUAL(VG::Point(3, 4), vg.getPoint(1));
					CHECK_EQUAL(VG::Point(5, 6), vg.getPoint(2));
				}
				else if (iGraphic == 1)
				{
					CHECK_EQUAL(VG::Point(700, 0), (*graphic).getPlacementPoint());
					auto vg = (*graphic).getGraphic();
					CHECK_EQUAL(false, vg.isClosed());
				}
			}

			CHECK_EQUAL(2, iGraphic);
		}
	}

}

TEST(MyReadSceneInvalidPoints, SceneReader)
{
	std::stringstream xmlStream(TestXmlInvalidPoints);
	auto root = Xml::Reader::loadXml(xmlStream);

	auto s = Framework::SceneReader::readScene(*root); //should throw

	int numberOfLayers = 0;
	for (auto pos = s.begin(); pos != s.end(); ++numberOfLayers, ++pos)
	{
		auto layer = (*pos);
		if (numberOfLayers == 0)
		{
			Framework::Layer::PlacedGraphicIterator graphic;
			int iGraphic;
			for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
			{
				if (iGraphic == 0)
				{
					CHECK_EQUAL(VG::Point(0, 0), (*graphic).getPlacementPoint());
					auto vg = (*graphic).getGraphic();
					CHECK_EQUAL(true, vg.isClosed());
					CHECK_EQUAL(3, vg.getPointCount());
					CHECK_EQUAL(VG::Point(1, 2), vg.getPoint(0));
					CHECK_EQUAL(VG::Point(3, 4), vg.getPoint(1));
					CHECK_EQUAL(VG::Point(5, 6), vg.getPoint(2));
				}
				else if (iGraphic == 1)
				{
					CHECK_EQUAL(VG::Point(700, 0), (*graphic).getPlacementPoint());
					auto vg = (*graphic).getGraphic();
					CHECK_EQUAL(false, vg.isClosed());
				}
			}

			CHECK_EQUAL(2, iGraphic);
		}
	}

}