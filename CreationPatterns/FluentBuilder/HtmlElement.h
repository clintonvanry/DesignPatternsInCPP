#pragma once
#include <string>
#include <vector>

class HtmlElement
{
public:
	HtmlElement() = default;
	virtual ~HtmlElement();
	
	HtmlElement(const HtmlElement& src);
	HtmlElement& operator=(const HtmlElement& rhs);

	HtmlElement(HtmlElement&& src) noexcept;
	HtmlElement& operator=(HtmlElement&& rhs) noexcept;

	friend void swap(HtmlElement& first, HtmlElement& second) noexcept
	{
		std::swap(first.m_name, second.m_name);
		std::swap(first.m_text, second.m_text);
		std::swap(first.m_elements, second.m_elements);
	
	}

	explicit HtmlElement(std::string name, std::string text = "");

	[[nodiscard]] std::string str(int indent = 0) const;

	void add_children(const HtmlElement& element)
	{
		m_elements.emplace_back(element);
	}

private:
	std::vector<HtmlElement> m_elements;
	std::string m_name, m_text;
	const int indent_size = 2;
};

