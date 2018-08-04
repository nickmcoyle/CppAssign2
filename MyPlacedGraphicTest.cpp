#include "PlacedGraphic.h"
#include "TestHarness.h"


TEST(customCtorLValueRef, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	constexpr VG::Point expected(1, 2);
	CHECK_EQUAL(expected, pg.getPlacementPoint());
	CHECK_EQUAL(vg.get(), &pg.getGraphic());   
}


TEST(customCtorRValues, PlacedGraphic)
{	
	Framework::PlacedGraphic pg(VG::Point(01, 02), VG::HVectorGraphic (new VG::VectorGraphic));
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	constexpr VG::Point expected(1, 2);
	CHECK_EQUAL(expected, pg.getPlacementPoint());	
}

TEST(customCtorMixed1, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	Framework::PlacedGraphic pg(VG::Point(01, 02), vg);
	
	constexpr VG::Point expected(1, 2);
	CHECK_EQUAL(expected, pg.getPlacementPoint());	
	CHECK_EQUAL(vg.get(), &pg.getGraphic());
}

TEST(customCtorMixed2, PlacedGraphic)
{	
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, VG::HVectorGraphic(new VG::VectorGraphic));
	
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	constexpr VG::Point expected(1, 2);	
	CHECK_EQUAL(expected, pg.getPlacementPoint());	
}

TEST(copyCtor, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	Framework::PlacedGraphic pg2(pg);

	CHECK_EQUAL(pg.getPlacementPoint(), pg2.getPlacementPoint());
	CHECK_EQUAL(&pg.getGraphic(), &pg2.getGraphic());	
}

TEST(moveCtor, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	Framework::PlacedGraphic pg2{ std::move(pg) };

	constexpr VG::Point expected(1, 2);
	CHECK_EQUAL(expected, pg2.getPlacementPoint());
	CHECK_EQUAL(vg.get(), &pg2.getGraphic());	
}

TEST(copyAssign, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	Framework::PlacedGraphic pg2;
	pg2 = pg;

	CHECK_EQUAL(pg.getPlacementPoint(), pg2.getPlacementPoint());
	CHECK_EQUAL(&pg.getGraphic(), &pg2.getGraphic());	
}

TEST(moveAssign, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	Framework::PlacedGraphic pg2;

	pg2 = { std::move(pg) };
	
	constexpr VG::Point expected(1, 2);
	CHECK_EQUAL(expected, pg2.getPlacementPoint());
	CHECK_EQUAL(vg.get(), &pg2.getGraphic());	
}

TEST(getSetPlacementPoint, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	CHECK_EQUAL(pp, pg.getPlacementPoint());

	VG::Point newPP(100, 101);

	pg.setPlacementPoint(newPP);
	
	CHECK_EQUAL(newPP, pg.getPlacementPoint());	
}

TEST(getSetPlacementPointRValue, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	CHECK_EQUAL(pp, pg.getPlacementPoint());

	VG::Point newPP(100, 101);

	pg.setPlacementPoint(VG::Point (100, 101));
	
	constexpr VG::Point expected(100, 101);
	CHECK_EQUAL(expected, pg.getPlacementPoint());
}

TEST(getSetGraphic, PlacedGraphic)
{
	VG::HVectorGraphic vg(new VG::VectorGraphic);
	VG::Point pp(01, 02);
	Framework::PlacedGraphic pg(pp, vg);

	CHECK_EQUAL(vg.get(), &pg.getGraphic());

	VG::HVectorGraphic newVG(new VG::VectorGraphic);
	
	pg.setGraphic(newVG);

	CHECK_EQUAL(newVG.get(), &pg.getGraphic());
}
