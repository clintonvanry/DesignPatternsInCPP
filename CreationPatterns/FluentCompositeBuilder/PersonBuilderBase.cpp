#include "PersonBuilderBase.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonBuilderBase::operator Person() const
{
	return  std::move(m_person);
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
	return PersonAddressBuilder{ m_person };
}

PersonJobBuilder PersonBuilderBase::works() const
{
	return PersonJobBuilder(m_person);
}

PersonBuilderBase::PersonBuilderBase(Person& person): m_person(person)
{
	
}
