#pragma once
#include <string>
#include <utility>
#include <vector>

class HtmlElementAttempt2
{
public:
	HtmlElementAttempt2();
	virtual ~HtmlElementAttempt2();

	HtmlElementAttempt2(const HtmlElementAttempt2& src);
	HtmlElementAttempt2& operator=(const HtmlElementAttempt2& rhs);

	HtmlElementAttempt2(HtmlElementAttempt2&& src) noexcept; // = delete;
	HtmlElementAttempt2& operator=(HtmlElementAttempt2&& rhs); // = delete;

	
	HtmlElementAttempt2(std::string name, std::string text = "") : m_name(std::move(name)), m_text(std::move(text))
	{

	}
	std::string str(int indent = 0) const;
	void add_children(const HtmlElementAttempt2& element);

	friend void swap(HtmlElementAttempt2& first, HtmlElementAttempt2& second)
	{
		std::swap(first.m_name, second.m_name);
		std::swap(first.m_text, second.m_text);
		std::swap(first.m_elements, second.m_elements);
	}
	
private:
	std::string m_name, m_text;
	std::vector<HtmlElementAttempt2> m_elements;
	const size_t indent_size = 2;
};

