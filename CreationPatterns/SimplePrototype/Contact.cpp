#include "Contact.h"
#include <ostream>

Contact::Contact(): m_address(nullptr)
{
}

Contact::~Contact()
{
	if (m_address != nullptr) 
	{
		delete m_address; //causes a memory leak
		m_address = nullptr;
	}
}

Contact::Contact(const Contact& src)
{
	m_name = src.m_name;
	m_address = src.m_address;
}

Contact& Contact::operator=(const Contact& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	auto contact(rhs);
	swap(*this, contact);
	return *this;
}

Contact::Contact(Contact&& src) noexcept
{
	swap(*this, src);
}

Contact& Contact::operator=(Contact&& rhs) noexcept
{
	auto tmp(std::move(rhs));
	swap(*this, tmp);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	os << "Name: " << contact.m_name << std::endl << "Address: " << *contact.m_address << std::endl;
	return os;
	
}
