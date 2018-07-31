#pragma once
#include <iostream>
#include <exception>

class Exception : public std::exception
{
public:

	Exception() throw();
	Exception(const Exception&) throw();
	Exception& operator=(const Exception&) throw();
	virtual ~Exception();

	virtual const char* what() const throw() = 0; //a very brief description of the exception, the derived classes should override this method

};


class VectorGraphicEmpty : public Exception
{
public:
	VectorGraphicEmpty() {};
	const char* what() const throw();

};
inline const char* VectorGraphicEmpty::what() const throw()
{
	return "Error: VectorGraphic is Empty";
}

class VectorGraphicFull : public Exception
{
public:
	VectorGraphicFull() {};
	const char* what() const throw();

};
inline const char* VectorGraphicFull::what() const throw()
{
	return "Error: VectorGraphic is Full";
}

class InvalidPointRemoval : public Exception
{
public:
	InvalidPointRemoval() {};
	const char* what() const throw();

};
inline const char* InvalidPointRemoval::what() const throw()
{
	return "Error: Attempt to remove an invalid point";
}

class IndexOutofRange : public Exception
{
public:
	IndexOutofRange() {};
	const char* what() const throw();

};
inline const char* IndexOutofRange::what() const throw()
{
	return "Error: Index Out of Range";
}

class InvalidIndex : public Exception
{
public:
	InvalidIndex() {};
	const char* what() const throw();

};
inline const char* InvalidIndex::what() const throw()
{
	return "Error: Invalid Index";
}

class InvalidCast : public Exception
{
public:
	InvalidCast() {};
	const char* what() const throw();

};
inline const char* InvalidCast::what() const throw()
{
	return "Error: Invalid Cast";
}

class InvalidClosedProperty : public Exception
{
public:
	InvalidClosedProperty() {};
	const char* what() const throw();

};
inline const char* InvalidClosedProperty::what() const throw()
{
	return "Error: Closed property is either missing or misspelled in the opening XML tag";
}

class InvalidClosedTag : public Exception
{
public:
	InvalidClosedTag() {};
	const char* what() const throw();

};
inline const char* InvalidClosedTag::what() const throw()
{
	return "Error: closing XML tag is either invalid or missing";
}

class InvalidPointTag : public Exception
{
public:
	InvalidPointTag() {};
	const char* what() const throw();

};
inline const char* InvalidPointTag::what() const throw()
{
	return "Error: Invalid VectorGraphic XML, Points are missing or invalid";
}


class InvalidXML : public Exception
{
public:
	InvalidXML() {};
	const char* what() const throw();

};
inline const char* InvalidXML::what() const throw()
{
	return "Error: Invalid VectorGraphic XML";
}

class Invalid : public Exception
{
public:
	Invalid() {};
	const char* what() const throw();

};
inline const char* Invalid::what() const throw()
{
	return "Error: Invalid Cast";
}
