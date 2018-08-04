#include "Element.h"
#include "TestHarness.h"


TEST(defaultCtor, Element)
{
	Xml::Element elem;
	
	CHECK_EQUAL("", elem.getName());	
}

TEST(customCtor, Element)
{
	Xml::Element elem("TestElement");	
	elem.addAttribute(Xml::Attribute("test", "attribute"));
	
	std::map<std::string, std::string> attributes = elem.getAttributes();
		
	CHECK_EQUAL("TestElement", elem.getName());
	CHECK_EQUAL(attributes["test"], "attribute");
}

TEST(copyCtor, Element)
{
	Xml::Element elem("TestElement");
	elem.addAttribute(Xml::Attribute("test","attribute"));
	elem.addAttribute(Xml::Attribute("another", "attribute"));		

	Xml::Element elem2(elem);

	std::map<std::string, std::string> attributes = elem.getAttributes();
	std::map<std::string, std::string> attributes2 = elem2.getAttributes();

	CHECK_EQUAL("TestElement", elem.getName());
	CHECK_EQUAL(attributes["test"], "attribute");
	CHECK_EQUAL(attributes["another"], "attribute");

	CHECK_EQUAL("TestElement", elem2.getName());
	CHECK_EQUAL(attributes2["test"], "attribute");
	CHECK_EQUAL(attributes2["another"], "attribute");
}

TEST(moveCtor, Element)
{
	Xml::Element elem("TestElement");
	elem.addAttribute(Xml::Attribute("test", "attribute"));
	elem.addAttribute(Xml::Attribute("another", "attribute"));	
	
	Xml::Element elem2{ std::move(elem) };

	std::map<std::string, std::string> attributes = elem.getAttributes();
	std::map<std::string, std::string> attributes2 = elem2.getAttributes();

	CHECK_EQUAL("", elem.getName());
	CHECK_EQUAL(0, attributes.size());
	
	CHECK_EQUAL("TestElement", elem2.getName());
	CHECK_EQUAL(attributes2["test"], "attribute");
	CHECK_EQUAL(attributes2["another"], "attribute");
	CHECK_EQUAL(2, attributes2.size());
}

TEST(copyAssign, Element)
{
	Xml::Element elem("TestElement");
	elem.addAttribute(Xml::Attribute("test", "attribute"));
	elem.addAttribute(Xml::Attribute("another", "attribute"));	

	Xml::Element elem2;
	elem2 = elem;

	std::map<std::string, std::string> attributes = elem.getAttributes();
	std::map<std::string, std::string> attributes2 = elem2.getAttributes();

	CHECK_EQUAL("TestElement", elem.getName());
	CHECK_EQUAL(attributes["test"], "attribute");
	CHECK_EQUAL(attributes["another"], "attribute");

	CHECK_EQUAL("TestElement", elem2.getName());
	CHECK_EQUAL(attributes2["test"], "attribute");
	CHECK_EQUAL(attributes2["another"], "attribute");
}

TEST(moveAssign, Element)
{
	Xml::Element elem("TestElement");
	elem.addAttribute(Xml::Attribute("test", "attribute"));
	elem.addAttribute(Xml::Attribute("another", "attribute"));	

	Xml::Element elem2;
	elem2 = { std::move(elem) };

	std::map<std::string, std::string> attributes = elem.getAttributes();
	std::map<std::string, std::string> attributes2 = elem2.getAttributes();

	CHECK_EQUAL("", elem.getName());
	CHECK_EQUAL(0, attributes.size());

	CHECK_EQUAL("TestElement", elem2.getName());
	CHECK_EQUAL(attributes2["test"], "attribute");
	CHECK_EQUAL(attributes2["another"], "attribute");
	CHECK_EQUAL(2, attributes2.size());	
}

TEST(getName, Element)
{
	Xml::Element elem("TestElement");	

	CHECK_EQUAL("TestElement", elem.getName());	
}

TEST(addGetChildElementLValue, Element)
{
	Xml::Element root("TestElement");

	Xml::Element::HElement hElement1(new Xml::Element("firstChild"));
	Xml::Element::HElement hElement2(new Xml::Element("secondChild"));
	Xml::Element::HElement hElement3(new Xml::Element("thirdChild"));

	root.addChildElement(hElement1);
	root.addChildElement(hElement2);
	root.addChildElement(hElement3);

	Xml::Element::ElementList children = root.getChildElements();

	CHECK_EQUAL("firstChild", (*children[0]).getName());
	CHECK_EQUAL("secondChild", (*children[1]).getName());
	CHECK_EQUAL("thirdChild", (*children[2]).getName());
	CHECK_EQUAL("TestElement", root.getName());
}

TEST(addGetChildElementRValue, Element)
{
	Xml::Element root("TestElement");

	root.addChildElement(Xml::Element::HElement(new Xml::Element("firstChild")));
	root.addChildElement(Xml::Element::HElement(new Xml::Element("secondChild")));
	root.addChildElement(Xml::Element::HElement(new Xml::Element("thirdChild")));

	Xml::Element::ElementList children = root.getChildElements();

	CHECK_EQUAL("firstChild", (*children[0]).getName());
	CHECK_EQUAL("secondChild", (*children[1]).getName());
	CHECK_EQUAL("thirdChild", (*children[2]).getName());
	CHECK_EQUAL("TestElement", root.getName());
}

TEST(addGetAttribute, Element)
{
	Xml::Element elem("TestElement");
	elem.addAttribute(Xml::Attribute("test", "attribute"));
	elem.addAttribute(Xml::Attribute("another", "attribute"));

	std::map<std::string, std::string> attributes = elem.getAttributes();	

	CHECK_EQUAL("TestElement", elem.getName());
	CHECK_EQUAL(attributes["test"], "attribute");
	CHECK_EQUAL(attributes["another"], "attribute");
	CHECK_EQUAL("TestElement", elem.getName());
}