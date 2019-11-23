#include <sstream>
#include <iostream>
#include "HtmlElement.h"

HtmlElement::~HtmlElement()
{
	m_elements.clear();
}

HtmlElement::HtmlElement(const HtmlElement& src)
{
	m_elements = src.m_elements;
	m_name = src.m_name;
	m_text = src.m_text;
}

HtmlElement& HtmlElement::operator=(const HtmlElement& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}

	auto html(rhs);
	swap(*this, html);
	return *this;
}

HtmlElement::HtmlElement(HtmlElement&& src) noexcept
{
	swap(*this, src);
}

HtmlElement& HtmlElement::operator=(HtmlElement&& rhs) noexcept
{
	auto tmp(std::move(rhs));
	swap(*this, tmp);
	return *this;
}

HtmlElement::HtmlElement(std::string name, std::string text):m_name(std::move(name)), m_text(std::move(text))
{
}

std::string HtmlElement::str(int indent) const
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
