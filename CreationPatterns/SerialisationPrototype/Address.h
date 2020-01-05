#pragma once
#include <string>
#include <utility>

class Address
{
private:
	std::string m_street, m_city;
	int m_suit = 0;

public:
	Address() = default;
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
