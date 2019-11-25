#include "PersonAddressBuilder.h"

PersonAddressBuilder::PersonAddressBuilder(Person& person): PersonBuilderBase(person)
{
}

PersonAddressBuilder& PersonAddressBuilder::at(std::string street_address)
{
	m_person.m_street_address = street_address;
	return *this;
}

PersonAddressBuilder& PersonAddressBuilder::with_postcode(std::string post_code)
{
	m_person.m_post_code = post_code;
	return *this;
}

PersonAddressBuilder& PersonAddressBuilder::in(std::string city)
{
	m_person.m_city = city;
	return *this;
}
