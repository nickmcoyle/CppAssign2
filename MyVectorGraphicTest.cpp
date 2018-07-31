#include "Parse.h"
#include "VectorGraphic.h"
#include "VectorGraphicStreamer.h"
#include "TestHarness.h"
#include <string>
#include <sstream>
#include <fstream>

TEST(myfromXml, VectorGraphic)
{
	std::stringstream sstr;
	std::ifstream myfile;
	myfile.open("MyVectorGraphicClosed.xml");
	if (myfile.is_open())
	{
		sstr << myfile.rdbuf();
	}
	myfile.close();
	auto vg1 = VG::VectorGraphicStreamer::fromXml(sstr);
	
	VG::VectorGraphic vg2;
	vg2.openShape();
	vg2.addPoint(VG::Point(1, 1));
	vg2.addPoint(VG::Point(2, 2));
	vg2.addPoint(VG::Point(3, 3));

	CHECK(vg1 == vg2);
}

TEST(fromXmlInvalid, VectorGraphic)
{
	std::stringstream sstr;
	std::ifstream myfile;
	myfile.open("MyVectorGraphicInvalid.xml");
	if (myfile.is_open())
	{
		sstr << myfile.rdbuf();
	}
	myfile.close();
	auto vg1 = VG::VectorGraphicStreamer::fromXml(sstr);

	VG::VectorGraphic vg2;
	vg2.addPoint(VG::Point(1, 1));
	vg2.addPoint(VG::Point(2, 2));
	vg2.addPoint(VG::Point(3, 3));

	CHECK(vg1 == vg2);
}

TEST(fromXmlInvalidPointTag, VectorGraphic)
{
	std::stringstream sstr;
	std::ifstream myfile;
	myfile.open("MyVectorGraphicInvalidPointTag.xml");
	if (myfile.is_open())
	{
		sstr << myfile.rdbuf();
	}
	myfile.close();
	auto vg1 = VG::VectorGraphicStreamer::fromXml(sstr);

	VG::VectorGraphic vg2;
	vg2.addPoint(VG::Point(1, 1));
	vg2.addPoint(VG::Point(2, 2));
	vg2.addPoint(VG::Point(3, 3));

	CHECK(vg1 == vg2);
}


TEST(mytoXmlFile, VectorGraphic)
{
	VG::VectorGraphic vg1;
	vg1.addPoint(VG::Point(10, 1));
	vg1.addPoint(VG::Point(2, 20));
	vg1.addPoint(VG::Point(33, 32));

	std::stringstream sstr;
	VG::VectorGraphicStreamer::toXml(vg1, sstr);

	auto vg2 = VG::VectorGraphicStreamer::fromXml(sstr);

	CHECK(vg1 == vg2);
}

TEST(removeInvalidPoint, VectorGraphic)
{
	VG::VectorGraphic vg1;
	vg1.addPoint(VG::Point(10, 1));
	vg1.addPoint(VG::Point(2, 20));
	vg1.addPoint(VG::Point(33, 32));
	vg1.removePoint(VG::Point(77, 32));
	

	CHECK(vg1 == vg1);
}