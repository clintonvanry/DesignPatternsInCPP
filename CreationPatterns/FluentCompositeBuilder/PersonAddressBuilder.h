#pragma once
#include "PersonBuilderBase.h"
class PersonAddressBuilder : public PersonBuilderBase
{
public:
	PersonAddressBuilder(Person& person);

	PersonAddressBuilder& at(std::string street_address);
	PersonAddressBuilder& with_postcode(std::string post_code);
	PersonAddressBuilder& in(std::string city);
};

