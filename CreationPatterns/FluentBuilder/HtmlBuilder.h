#pragma once
#include <string>
#include <memory>

#include "HtmlElement.h"


class HtmlBuilder
{
public:
	HtmlBuilder(std::string& name);
	explicit HtmlBuilder(std::string&& name);

	HtmlBuilder& add_child(std::string name, std::string text);
	HtmlBuilder* add_child2(std::string name, std::string text);

	[[nodiscard]] std::string str() const { return m_root.str(); }

	friend  std::ostream& operator<<(std::ostream& out_ostream, const HtmlBuilder& builder);

	static std::unique_ptr<HtmlBuilder> builder(std::string name)
	{
		return std::make_unique<HtmlBuilder>(std::move(name));
	}
private:
	HtmlElement m_root;
};

