#include "HtmlElementAttempt2.h"
#include <sstream>
#include <iostream>

using namespace std;


HtmlElementAttempt2::~HtmlElementAttempt2()
{
	m_elements.clear();
}

HtmlElementAttempt2::HtmlElementAttempt2()
{
	cout << "constructor";
}


HtmlElementAttempt2::HtmlElementAttempt2(const HtmlElementAttempt2& src) 
{
	cout << "Copy constructor";
	m_elements = src.m_elements;
	m_name = src.m_name;
	m_text = src.m_text;
}

HtmlElementAttempt2& HtmlElementAttempt2::operator=(const HtmlElementAttempt2& rhs)
{
	cout << "Assignment constructor";
	if(this == &rhs)
	{
		return *this;
	}

	auto html(rhs);
	swap(*this, html);
	return *this;

}

HtmlElementAttempt2::HtmlElementAttempt2(HtmlElementAttempt2&& src) noexcept
{
	cout << "move copy";
	swap(*this, src);
}

HtmlElementAttempt2& HtmlElementAttempt2::operator=(HtmlElementAttempt2&& rhs)
{
	cout << "move assignment";
	auto tmp(std::move(rhs));
	swap(*this, tmp);
	return *this;
}

std::string HtmlElementAttempt2::str(int indent) const
{
	std::ostringstream oss;
	const std::string indentString(indent_size * indent, ' ');

	oss << indentString << "<" << m_name << ">" << std::endl;

	if (!m_text.empty())
	{
		oss << std::string(indent_size * (indent + 1), ' ') << m_text << std::endl;
	}

	// print children
	for (const auto& element : m_elements)
	{
		oss << element.str(indent + 1);
	}

	oss << indentString << "</" << m_name << ">" << std::endl;

	return oss.str();
}

void HtmlElementAttempt2::add_children(const HtmlElementAttempt2& element)
{
	m_elements.emplace_back(element);
}
