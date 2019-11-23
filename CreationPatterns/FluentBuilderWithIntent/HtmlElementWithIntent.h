#ifndef HtmlElementWithIntent_FILE
#define HtmlElementWithIntent_FILE
#ifdef _MSC_VER
#pragma once
#endif
#include <string>
#include <vector>
#include "HtmlBuilderWithIntent.h"
#include <memory>

class HtmlElementWithIntent
{
public:
	
	virtual ~HtmlElementWithIntent();

	HtmlElementWithIntent(const HtmlElementWithIntent& src);
	HtmlElementWithIntent& operator=(const HtmlElementWithIntent& rhs);

	HtmlElementWithIntent(HtmlElementWithIntent&& src) noexcept;
	HtmlElementWithIntent& operator=(HtmlElementWithIntent&& rhs) noexcept;

	explicit HtmlElementWithIntent(std::string name, std::string text = "");

	[[nodiscard]] std::string str(int indent = 0) const;

	void add_children(const HtmlElementWithIntent& element);
	static std::unique_ptr<HtmlBuilderWithIntent> builder(std::string name);
	
protected:
	HtmlElementWithIntent() = default;

	

	friend void swap(HtmlElementWithIntent& first, HtmlElementWithIntent& second) noexcept;
private:
	std::vector<HtmlElementWithIntent> m_elements;
	std::string m_name, m_text;
	const size_t indent_size = 2;
};
#endif

