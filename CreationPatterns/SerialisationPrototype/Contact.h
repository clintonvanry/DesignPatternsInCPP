#pragma once
#include <string>
#include <utility>
#include "Address.h"
#include <boost/serialization/serialization.hpp>

using namespace boost;

class Contact
{
private:
	std::string m_name{ "" };
	Address* m_address{};

	friend class serialization::access;
	
	template <class archive>
	void serialize(archive& ar, const unsigned version) const
	{
		ar & m_name;
		ar & m_address;
	}

public:
	Contact();
	virtual ~Contact();

	Contact(const Contact& src);
	Contact& operator=(const Contact& rhs);

	Contact(Contact&& src) noexcept;
	Contact& operator=(Contact&& rhs) noexcept;

	Contact(std::string name, Address* address) :m_name(std::move(name)), m_address(address)
	{

	}

	friend void swap(Contact& first, Contact& second)
	{
		std::swap(first.m_name, second.m_name);
		std::swap(first.m_address, second.m_address);
	}

	friend std::ostream& operator<< (std::ostream& os, const Contact& contact);

	void setName(const std::string& name)
	{
		m_name = name;
	}
	void setSuite(int suite)
	{
		m_address->setSuite(suite);
	}

};

