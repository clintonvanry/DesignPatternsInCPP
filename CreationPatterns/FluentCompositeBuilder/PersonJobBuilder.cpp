#include "PersonJobBuilder.h"
#include <utility>

PersonJobBuilder::PersonJobBuilder(Person& person) : PersonBuilderBase(person)
{
}

PersonJobBuilder& PersonJobBuilder::at(std::string company_name)
{
	m_person.m_company_name = std::move(company_name);
	return *this;
}

PersonJobBuilder& PersonJobBuilder::as_a(std::string position)
{
	m_person.m_position = std::move(position);
	return *this;
}

PersonJobBuilder& PersonJobBuilder::earning(int annual_income)
{
	m_person.m_annual_income = annual_income;
	return *this;
}
