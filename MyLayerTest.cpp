#include "Layer.h"
#include "TestHarness.h"


TEST(defaultCtor, Layer)
{
	Framework::Layer layer;
	
	CHECK_EQUAL("", layer.getAlias());	
}

TEST(customCtor, Layer)
{
	Framework::Layer layer("TestLayer");
			
	CHECK_EQUAL("TestLayer", layer.getAlias());	
}

TEST(copyCtor, Layer)
{
	Framework::Layer layer("TestLayer");
	
	Framework::Layer layer2(layer);		
	
	CHECK(layer == layer2);	
}

TEST(moveCtor, Layer)
{
	Framework::Layer layer("TestLayer");

	Framework::Layer layer2{ std::move(layer) };

	CHECK_EQUAL("", layer.getAlias());
	
	CHECK_EQUAL("TestLayer", layer2.getAlias());
	
}

TEST(copyAssign, Layer)
{
	Framework::Layer layer("TestLayer");

	Framework::Layer layer2;
	layer2 = layer;

	CHECK(layer2 == layer);
}

TEST(moveAssign, Layer)
{
	Framework::Layer layer("TestLayer");

	Framework::Layer layer2;
	layer2 = { std::move(layer) };

	CHECK_EQUAL("", layer.getAlias());

	CHECK_EQUAL("TestLayer", layer2.getAlias());	
}

TEST(getSetAlias, Layer)
{
	Framework::Layer layer("TestLayer");

	CHECK_EQUAL("TestLayer", layer.getAlias());

	layer.setAlias("");

	CHECK_EQUAL("", layer.getAlias());

	std::string alias = "lValueAlias";
	layer.setAlias(alias);

	CHECK_EQUAL("lValueAlias", layer.getAlias());
}

TEST(insertRemoveLValue, Layer)
{
	Framework::Layer layer("TestLayer");

	VG::HVectorGraphic vg(new VG::VectorGraphic);
	Framework::PlacedGraphic pg(VG::Point(01, 02), vg);
	
	VG::HVectorGraphic vg2(new VG::VectorGraphic);
	Framework::PlacedGraphic pg2(VG::Point(03, 04), vg);

	layer.insert(pg);
	layer.insert(pg2);

	std::list<Framework::PlacedGraphic> graphics = layer.getPlacedGraphics();
	
	constexpr VG::Point expected(01, 02);
	CHECK_EQUAL(expected, (*graphics.begin()).getPlacementPoint());

	layer.remove(pg);

	std::list<Framework::PlacedGraphic> graphics2 = layer.getPlacedGraphics();
	constexpr VG::Point expected2(03, 04);
	CHECK_EQUAL(expected2, (*graphics2.begin()).getPlacementPoint());
	
}

TEST(insertRemoveRValue, Layer)
{
	Framework::Layer layer("TestLayer");

	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::HVectorGraphic vg2(new VG::VectorGraphic);

	layer.insert(Framework::PlacedGraphic(VG::Point(01, 02), vg));
	layer.insert(Framework::PlacedGraphic(VG::Point(03, 04), vg));

	std::list<Framework::PlacedGraphic> graphics = layer.getPlacedGraphics();

	constexpr VG::Point expected(01, 02);
	CHECK_EQUAL(expected, (*graphics.begin()).getPlacementPoint());

	layer.remove(Framework::PlacedGraphic(VG::Point(01, 02), vg));

	std::list<Framework::PlacedGraphic> graphics2 = layer.getPlacedGraphics();

	constexpr VG::Point expected2(03, 04);
	CHECK_EQUAL(expected2, (*graphics2.begin()).getPlacementPoint());
}

TEST(removeLayerInvalid, Layer)
{
	Framework::Layer layer("TestLayer");

	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::HVectorGraphic vg2(new VG::VectorGraphic);

	layer.insert(Framework::PlacedGraphic(VG::Point(01, 02), vg));
	layer.insert(Framework::PlacedGraphic(VG::Point(03, 04), vg));

	
	layer.remove(Framework::PlacedGraphic(VG::Point(05, 06), vg)); //should throw
	
	std::list<Framework::PlacedGraphic> graphics = layer.getPlacedGraphics();

	CHECK_EQUAL(01, (*graphics.begin()).getGraphic().getPoint(0).getX());
	CHECK_EQUAL(02, (*graphics.begin()).getGraphic().getPoint(0).getY());
}