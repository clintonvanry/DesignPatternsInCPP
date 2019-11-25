#ifndef PersonBuilderBase_PAGE
#define PersonBuilderBase_PAGE
#ifdef _MSC_VER
#pragma once
#endif

#include <iostream>
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase
{

protected:
	Person& m_person;
	explicit PersonBuilderBase(Person& person);
public:
	operator Person() const;
	
	PersonAddressBuilder lives() const;
	PersonJobBuilder works() const;
};

class PersonBuilder : public PersonBuilderBase
{
	Person person;
public:
	PersonBuilder() :PersonBuilderBase{ person }
	{
		
	}

	friend std::ostream& operator<<(std::ostream& os, const PersonBuilder& personBuilder)
	{
		return os << personBuilder.person;
			
	}
};
#endif

