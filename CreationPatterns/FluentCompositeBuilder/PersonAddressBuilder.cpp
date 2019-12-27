#include "PersonAddressBuilder.h"
#include <utility>

PersonAddressBuilder::PersonAddressBuilder(Person& person): PersonBuilderBase(person)
{
}

PersonAddressBuilder& PersonAddressBuilder::at(std::string street_address)
{
	m_person.m_street_address = std::move(street_address);
	return *this;
}

PersonAddressBuilder& PersonAddressBuilder::with_postcode(std::string post_code)
{
	m_person.m_post_code = std::move(post_code);
	return *this;
}

PersonAddressBuilder& PersonAddressBuilder::in(std::string city)
{
	m_person.m_city = std::move(city);
	return *this;
}
