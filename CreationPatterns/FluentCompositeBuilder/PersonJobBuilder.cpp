#include "PersonJobBuilder.h"

PersonJobBuilder::PersonJobBuilder(Person& person) : PersonBuilderBase(person)
{
}

PersonJobBuilder& PersonJobBuilder::at(std::string company_name)
{
	m_person.m_company_name = company_name;
	return *this;
}

PersonJobBuilder& PersonJobBuilder::as_a(std::string position)
{
	m_person.m_position = position;
	return *this;
}

PersonJobBuilder& PersonJobBuilder::earning(int annual_income)
{
	m_person.m_annual_income = annual_income;
	return *this;
}
