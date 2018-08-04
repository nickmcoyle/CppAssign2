#include "Scene.h"
#include "TestHarness.h"


TEST(defaultCtor, Scene)
{
	Framework::Scene scene;

	std::list<Framework::Layer> layers = scene.getLayers();

	CHECK_EQUAL(0, scene.getWidth());
	CHECK_EQUAL(0, scene.getHeight());
	CHECK_EQUAL(0, layers.size());
}

TEST(customCtor, Scene)
{
	Framework::Scene scene(1024, 768);	

	scene.pushBack(Framework::Layer("testlayer"));

	std::list<Framework::Layer> layers = scene.getLayers();

	CHECK_EQUAL(1024, scene.getWidth());
	CHECK_EQUAL(768, scene.getHeight());
	CHECK_EQUAL(1, layers.size());

	CHECK_EQUAL("testlayer", (*layers.begin()).getAlias());	
}

TEST(copyCtor, Scene)
{
	Framework::Scene scene(1024, 768);
	scene.pushBack(Framework::Layer("testlayer"));

	Framework::Scene scene2(scene);

	std::list<Framework::Layer> layers = scene.getLayers();
	std::list<Framework::Layer> layers2 = scene2.getLayers();

	CHECK_EQUAL(1024, scene.getWidth());
	CHECK_EQUAL(768, scene.getHeight());
	CHECK_EQUAL(1, layers.size());

	CHECK_EQUAL("testlayer", (*layers.begin()).getAlias());

	CHECK_EQUAL(1024, scene2.getWidth());
	CHECK_EQUAL(768, scene2.getHeight());
	CHECK_EQUAL(1, layers2.size());

	CHECK_EQUAL("testlayer", (*layers2.begin()).getAlias());
}

TEST(moveCtor, Scene)
{
	Framework::Scene scene(1024, 768);
	scene.pushBack(Framework::Layer("testlayer"));	
		
	Framework::Scene scene2{ std::move(scene) };

	std::list<Framework::Layer> layers = scene.getLayers();
	std::list<Framework::Layer> layers2 = scene2.getLayers();	
	
	CHECK_EQUAL(0, layers.size());

	CHECK_EQUAL("testlayer", (*layers2.begin()).getAlias());
	CHECK_EQUAL(1024, scene2.getWidth());
	CHECK_EQUAL(768, scene2.getHeight());
	CHECK_EQUAL(1, layers2.size());
}

TEST(copyAssign, Scene)
{
	Framework::Scene scene(1024, 768);
	scene.pushBack(Framework::Layer("testlayer"));

	Framework::Scene scene2;
	scene2 = scene;

	std::list<Framework::Layer> layers = scene.getLayers();
	std::list<Framework::Layer> layers2 = scene2.getLayers();

	CHECK_EQUAL(1024, scene.getWidth());
	CHECK_EQUAL(768, scene.getHeight());
	CHECK_EQUAL(1, layers.size());

	CHECK_EQUAL("testlayer", (*layers.begin()).getAlias());

	CHECK_EQUAL(1024, scene2.getWidth());
	CHECK_EQUAL(768, scene2.getHeight());
	CHECK_EQUAL(1, layers2.size());

	CHECK_EQUAL("testlayer", (*layers2.begin()).getAlias());
}

TEST(moveAssign, Scene)
{
	Framework::Scene scene(1024, 768);
	scene.pushBack(Framework::Layer("testlayer"));

	Framework::Scene scene2;
	scene2 = { std::move(scene) };

	std::list<Framework::Layer> layers = scene.getLayers();
	std::list<Framework::Layer> layers2 = scene2.getLayers();
		
	CHECK_EQUAL(0, layers.size());

	CHECK_EQUAL("testlayer", (*layers2.begin()).getAlias());
	CHECK_EQUAL(1024, scene2.getWidth());
	CHECK_EQUAL(768, scene2.getHeight());
	CHECK_EQUAL(1, layers2.size());	
}

TEST(pushBacklValue, Scene)
{
	Framework::Scene scene(1024, 768);
	Framework::Layer myLayer("testlayer");
	scene.pushBack(myLayer);

	std::list<Framework::Layer> layers = scene.getLayers();

	CHECK_EQUAL(1, layers.size());
	CHECK_EQUAL("testlayer", (*layers.begin()).getAlias());
}

TEST(pushBackRValue, Scene)
{
	Framework::Scene scene(1024, 768);

	scene.pushBack(Framework::Layer("testlayer1"));
	scene.pushBack(Framework::Layer("testlayer2"));	

	std::list<Framework::Layer> layers = scene.getLayers();	
	
	CHECK_EQUAL(2, layers.size());
	CHECK_EQUAL("testlayer1", (*layers.begin()).getAlias());	
}

TEST(myRemove, Scene)
{
	Framework::Scene scene(1024, 768);
	Framework::Layer myLayer("testlayer");
	scene.pushBack(myLayer);

	std::list<Framework::Layer> layers = scene.getLayers();

	CHECK_EQUAL(1, layers.size());
	CHECK_EQUAL("testlayer", (*layers.begin()).getAlias());

	scene.remove(myLayer);

	std::list<Framework::Layer> layersafter = scene.getLayers();

	CHECK_EQUAL(0, layersafter.size());
}

TEST(removeInvalid, Scene)
{
	Framework::Scene scene(1024, 768);
	Framework::Layer myLayer("testlayer");
	Framework::Layer invalidLayer("notInScene");
	scene.pushBack(myLayer);

	std::list<Framework::Layer> layers = scene.getLayers();

	CHECK_EQUAL(1, layers.size());
	CHECK_EQUAL("testlayer", (*layers.begin()).getAlias());

	scene.remove(invalidLayer); //should throw

	std::list<Framework::Layer> layersafter = scene.getLayers();

	CHECK_EQUAL(0, layersafter.size());
}

TEST(getSetWidthHeight, Scene)
{
	Framework::Scene scene;	
	scene.setWidth(1920);
	scene.setHeight(1080);

	CHECK_EQUAL(1920, scene.getWidth());
	CHECK_EQUAL(1080, scene.getHeight());
}

TEST(setWidthInvalid, Scene)
{
	Framework::Scene scene;
	scene.setWidth(-1920);
	scene.setHeight(-1080);

	CHECK_EQUAL(-1920, scene.getWidth());
	CHECK_EQUAL(-1080, scene.getHeight());
}

TEST(setHeightInvalid, Scene)
{
	Framework::Scene scene;
	scene.setWidth(1920);
	scene.setHeight(-1080);

	CHECK_EQUAL(1920, scene.getWidth());
	CHECK_EQUAL(-1080, scene.getHeight());
}