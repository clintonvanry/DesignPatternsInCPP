#pragma once
#include <string>
#include <utility>
#include <vector>

class HtmlElementAttempt1
{
public:
	HtmlElementAttempt1() = default;
	HtmlElementAttempt1(std::string name, std::string text): m_name(std::move(name)), m_text(std::move(text))
	{
		
	}
	std::string str(int indent = 0) const;
	void add_children(const HtmlElementAttempt1& element);
	
private:
	std::string m_name, m_text;
	std::vector<HtmlElementAttempt1> m_elements;
	const size_t indent_size = 2;
};

