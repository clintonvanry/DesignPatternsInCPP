#include "Address.h"
#include <ostream>

void swap(Address& first, Address& second) noexcept
{
	std::swap(first.m_street, second.m_street);
	std::swap(first.m_city, second.m_city);
	std::swap(first.m_suit, second.m_suit);
}

std::ostream& operator<<(std::ostream& os, const Address& address)
{
	os << "Street:" << address.m_street << " City:" << address.m_city << " suite:" << address.m_suit << std::endl;
	return os;
}

Address::Address(const Address& src)
{
	m_street = src.m_street;
	m_city = src.m_city;
	m_suit = src.m_suit;
}

Address& Address::operator=(const Address& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	
	auto address(rhs);
	swap(*this, address);
	return *this;
	
}

Address::Address(Address&& src) noexcept
{
	swap(*this, src);
}

Address& Address::operator=(Address&& rhs) noexcept
{
	auto tmp(std::move(rhs));
	swap(*this, tmp);
	return *this;
}

void Address::setSuite(int suite)
{
	m_suit = suite;
}
