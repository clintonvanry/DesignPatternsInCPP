#include <utility>
#include <ostream>
#include <memory>
#include "HtmlBuilder.h"

HtmlBuilder::HtmlBuilder(std::string& name)
{
	m_root = HtmlElement(name);
}

HtmlBuilder::HtmlBuilder(std::string&& name)
{
	m_root = HtmlElement(name);
}

HtmlBuilder& HtmlBuilder::add_child(std::string name, std::string text)
{
	m_root.add_children(HtmlElement(std::move(name), std::move(text)));
	return *this;
}

HtmlBuilder* HtmlBuilder::add_child2(std::string name, std::string text)
{
	m_root.add_children(HtmlElement(std::move(name), std::move(text)));
	return this;
}

std::ostream& operator<<(std::ostream& out_ostream, const HtmlBuilder& builder)
{
	out_ostream << builder.str() << std::endl;
	return out_ostream;
}
