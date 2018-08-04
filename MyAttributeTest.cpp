#include "Attribute.h"
#include "TestHarness.h"


TEST(defaultCtor, Attribute)
{
	Xml::Attribute attr;

	CHECK_EQUAL(true, attr.empty());	
	CHECK_EQUAL("", attr.getAttributeName());
	CHECK_EQUAL("", attr.getAttributeValue());
}

TEST(customCtor, Attribute)
{
	Xml::Attribute attr("test", "attribute");

	CHECK_EQUAL(false, attr.empty());
	CHECK_EQUAL("test", attr.getAttributeName());
	CHECK_EQUAL("attribute", attr.getAttributeValue());
}

TEST(copyCtor, Attribute)
{
	Xml::Attribute attr("test", "attribute");
	Xml::Attribute attr2(attr);
	
	CHECK_EQUAL(false, attr.empty());
	CHECK_EQUAL("test", attr.getAttributeName());
	CHECK_EQUAL("attribute", attr.getAttributeValue());

	CHECK_EQUAL(false, attr2.empty());
	CHECK_EQUAL("test", attr2.getAttributeName());
	CHECK_EQUAL("attribute", attr2.getAttributeValue());
}

TEST(moveCtor, Attribute)
{
	Xml::Attribute attr("test", "attribute");	

	Xml::Attribute attr2{ std::move(attr) };

	CHECK_EQUAL(true, attr.empty());

	CHECK_EQUAL(false, attr2.empty());
	CHECK_EQUAL("test", attr2.getAttributeName());
	CHECK_EQUAL("attribute", attr2.getAttributeValue());
}

TEST(copyAssign, Attribute)
{
	Xml::Attribute attr("test", "attribute");
	
	Xml::Attribute attr2;
	attr2 = attr;

	CHECK_EQUAL(false, attr.empty());
	CHECK_EQUAL("test", attr.getAttributeName());
	CHECK_EQUAL("attribute", attr.getAttributeValue());

	CHECK_EQUAL(false, attr2.empty());
	CHECK_EQUAL("test", attr2.getAttributeName());
	CHECK_EQUAL("attribute", attr2.getAttributeValue());
}

TEST(moveAssign, Attribute)
{
	Xml::Attribute attr("test", "attribute");
	
	Xml::Attribute attr2;
	attr2 = std::move(attr);

	CHECK_EQUAL(true, attr.empty());

	CHECK_EQUAL(false, attr2.empty());
	CHECK_EQUAL("test", attr2.getAttributeName());
	CHECK_EQUAL("attribute", attr2.getAttributeValue());
}

TEST(getNameValue, Attribute)
{
	Xml::Attribute attr("test", "attribute");
	
	Xml::Attribute attr2;
	
	CHECK_EQUAL("test", attr.getAttributeName());
	CHECK_EQUAL("attribute", attr.getAttributeValue());

	CHECK_EQUAL("", attr2.getAttributeName());
	CHECK_EQUAL("", attr2.getAttributeValue());
}

TEST(empty, Attribute)
{
	Xml::Attribute attr("test", "attribute");
	Xml::Attribute attr2;

	CHECK_EQUAL(false, attr.empty());
	CHECK_EQUAL(true, attr2.empty());
}