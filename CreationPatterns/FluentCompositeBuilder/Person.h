#ifndef PersonBuilder_PAGE
#define PersonBuilder_PAGE
#ifdef _MSC_VER
#pragma once
#endif
#include <string>

class PersonBuilder;

class Person
{
public:
	Person();
	virtual ~Person();
	
	// copy and assignment
	// copy
	Person(const Person& src);
	// assignment
	Person& operator=(const Person& rhs);

	
	// move and assignment
	// copy
	Person(Person&& src) noexcept;
	// assignment
	Person& operator=(Person&& rhs) noexcept;
	
	// friend for swap
	friend  void swap(Person& first, Person& second) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	
	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;
	
	static PersonBuilder create();
	
private:
	// address
	std::string m_street_address, m_post_code, m_city;

	// employment
	std::string m_company_name, m_position;
	int m_annual_income{ 0 };

	
};
#endif
