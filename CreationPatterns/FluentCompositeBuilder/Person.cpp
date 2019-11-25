#include "Person.h"
#include "PersonBuilderBase.h"
#include <iostream>

Person::Person()
{
}

Person::~Person()
{
}

Person::Person(const Person& src)
{
	m_street_address = src.m_street_address;
	m_post_code = src.m_post_code;
	m_city = src.m_city;
	m_company_name = src.m_company_name;
	m_position = src.m_position;
	m_annual_income = src.m_annual_income;
}

Person& Person::operator=(const Person& rhs)
{
	if(this ==&rhs)
	{
		return *this;
	}

	auto tmp(rhs);
	swap(*this, tmp);
	return *this;
}

Person::Person(Person&& src) noexcept
{
	swap(*this, src);
}

Person& Person::operator=(Person&& rhs) noexcept
{
	auto tmp(std::move(rhs));
	swap(*this, tmp);
	return *this;
}

PersonBuilder Person::create()
{
	return PersonBuilder();
}

void swap(Person& first, Person& second) noexcept
{
	std::swap(first.m_street_address, second.m_street_address);
	std::swap(first.m_post_code, second.m_post_code);
	std::swap(first.m_city, second.m_city);
	std::swap(first.m_company_name, second.m_company_name);
	std::swap(first.m_position, second.m_position);
	std::swap(first.m_annual_income, second.m_annual_income);
	
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	return os
		<< "street_address: " << person.m_street_address << std::endl
		<< " post_code: " << person.m_post_code << std::endl
		<< " city: " << person.m_city << std::endl
		<< " company_name: " << person.m_company_name << std::endl
		<< " position: " << person.m_position << std::endl
		<< " annual_income: " << person.m_annual_income << std::endl;
}
