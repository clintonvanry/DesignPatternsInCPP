#include "HtmlElementAttempt1.h"
#include <sstream>

using namespace std;

std::string HtmlElementAttempt1::str(int indent) const
{
	ostringstream oss;
	const string indentString(indent_size * indent, ' ');

	oss << indentString << "<" << m_name << ">" << endl;
	
	if(!m_text.empty())
	{
		oss << string(indent_size * (indent + 1), ' ') << m_text << endl;
	}

	// print children
	for(const auto& element : m_elements)
	{
		oss << element.str(indent + 1);
	}
	
	oss << indentString << "</" << m_name << ">" << endl;

	return oss.str();
}

void HtmlElementAttempt1::add_children(const HtmlElementAttempt1& element)
{
	m_elements.emplace_back(element);
}
