#include "Parse.h"
#include "TestHarness.h"


TEST(trimSpaceMiddle, Parse)
{
	std::string actual{ "  \tHello Hello" };
	Parse::trim(actual, " \t\n");

	CHECK_EQUAL("Hello Hello", actual);
}

TEST(trimBoundary, Parse)
{
	std::string actual{ "  \tHello<VectorGraphic/> Hello" };
	Parse::trim(actual, " \t\n");

	CHECK_EQUAL("Hello<VectorGraphic/> Hello", actual);
}

TEST(trimBoundaryJunkCharacters, Parse)
{
	std::string actual{ "  \tHello<&&=>=&*)(W#$% Hello" };
	Parse::trim(actual, " \t\n");

	CHECK_EQUAL("Hello<&&=>=&*)(W#$% Hello", actual);
}