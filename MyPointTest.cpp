#include "Point.h"
#include "TestHarness.h"


TEST(signedPoint, Point)
{
	CHECK_EQUAL(VG::Point(-1, -1), VG::Point(-1, -1));
}

TEST(signedPointEquality, Point)
{
	CHECK(VG::Point(-1, -1) == VG::Point(-1, -1));
}

TEST(signedPointInEquality, Point)
{
	CHECK(VG::Point(-1, -1) != VG::Point(1, 1));
}

TEST(lowerboundary, Point)
{
	CHECK_EQUAL(VG::Point(00000, 00000), VG::Point(0, 0));
}

TEST(upperboundary, Point)
{
	CHECK_EQUAL(VG::Point(999999999, 999999999), VG::Point(999999999, 999999999));
}

TEST(upperboundaryEquality, Point)
{
	CHECK(VG::Point(999999999, 999999999) == VG::Point(999999999, 999999999));
}

TEST(boundaryInEquality, Point)
{
	CHECK(VG::Point(999999999, 999999999) != VG::Point(0, 0));
}