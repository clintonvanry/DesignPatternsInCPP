#pragma once
#include "PersonBuilderBase.h"
class PersonJobBuilder : public PersonBuilderBase
{
public:
	PersonJobBuilder(Person& person);

	PersonJobBuilder& at(std::string company_name);
	PersonJobBuilder& as_a(std::string position);
	PersonJobBuilder& earning(int annual_income);
};

