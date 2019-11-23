#include "HtmlBuilderWithIntent.h"
#include "HtmlElementWithIntent.h"
#include <ostream>

HtmlBuilderWithIntent::HtmlBuilderWithIntent(std::string& name)
{
	m_root = new HtmlElementWithIntent(name);
}

HtmlBuilderWithIntent::HtmlBuilderWithIntent(std::string&& name)
{
	m_root = new HtmlElementWithIntent(name);
}

HtmlBuilderWithIntent::~HtmlBuilderWithIntent()
{
	delete m_root;
}

HtmlBuilderWithIntent* HtmlBuilderWithIntent::add_child(std::string name, std::string text)
{
	m_root->add_children(HtmlElementWithIntent(std::move(name), std::move(text)));
	return  this;
}

std::string HtmlBuilderWithIntent::str() const
{
	return m_root->str();
}

std::ostream& operator<<(std::ostream& out_ostream, const HtmlBuilderWithIntent& builder)
{
	out_ostream << builder.str() << std::endl;
	return out_ostream;
}
