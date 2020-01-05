#pragma once
#include <string>
#include <utility>
#include <boost/serialization/serialization.hpp>

using namespace boost;


class Address
{
private:
	std::string m_street, m_city;
	int m_suit = 0;

	friend class serialization::access;

	template <class archive>
	void serialize(archive& ar, const unsigned version) const
	{
		ar & m_street;
		ar & m_city;
		ar & m_suit;
	}

public:
	Address();
	
	virtual ~Address() = default;

	Address(const Address& src);
	Address& operator=(const Address& rhs);

	Address(Address&& src) noexcept;
	Address& operator=(Address&& rhs) noexcept;

	Address(std::string street, std::string city, const int& suit) : m_street(std::move(street)), m_city(std::move(city)), m_suit(suit)
	{

	}

	friend void swap(Address& first, Address& second) noexcept;
	friend std::ostream& operator<<(std::ostream& os, const Address& address);

	void setSuite(int suite);

};
