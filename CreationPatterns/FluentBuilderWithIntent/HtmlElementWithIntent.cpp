#include "HtmlElementWithIntent.h"
#include <sstream>
#include <iostream>

HtmlElementWithIntent::~HtmlElementWithIntent()
{
	m_elements.clear();
}

HtmlElementWithIntent::HtmlElementWithIntent(const HtmlElementWithIntent& src)
{
	m_elements = src.m_elements;
	m_name = src.m_name;
	m_text = src.m_text;
}

HtmlElementWithIntent& HtmlElementWithIntent::operator=(const HtmlElementWithIntent& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	auto html(rhs);
	swap(*this, html);
	return *this;
}

HtmlElementWithIntent::HtmlElementWithIntent(HtmlElementWithIntent&& src) noexcept
{
	swap(*this, src);
}

HtmlElementWithIntent& HtmlElementWithIntent::operator=(HtmlElementWithIntent&& rhs) noexcept
{
	auto tmp(std::move(rhs));
	swap(*this, tmp);
	return *this;
}

HtmlElementWithIntent::HtmlElementWithIntent(std::string name, std::string text) :m_name(std::move(name)), m_text(std::move(text))
{
	
}

std::string HtmlElementWithIntent::str(int indent) const
{
	std::ostringstream oss;
	const std::string indentString(indent_size * indent, ' ');

	oss << indentString << "<" << m_name << ">" << std::endl;

	if (!m_text.empty())
	{
		oss << std::string(indent_size * (static_cast<__int64>(indent) + 1), ' ') << m_text << std::endl;
	}

	// print children
	for (const auto& element : m_elements)
	{
		oss << element.str(indent + 1);
	}

	oss << indentString << "</" << m_name << ">" << std::endl;

	return oss.str();
}

void HtmlElementWithIntent::add_children(const HtmlElementWithIntent& element)
{
	m_elements.emplace_back(element);
}

std::unique_ptr<HtmlBuilderWithIntent> HtmlElementWithIntent::builder(std::string name)
{
	return std::make_unique<HtmlBuilderWithIntent>(std::move(name));
}

void swap(HtmlElementWithIntent& first, HtmlElementWithIntent& second) noexcept
{
	std::swap(first.m_name, second.m_name);
	std::swap(first.m_text, second.m_text);
	std::swap(first.m_elements, second.m_elements);
}
