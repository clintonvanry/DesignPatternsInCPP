#pragma once

#include <string>
#include "HtmlElementAttempt2.h"

class HtmlBuilderAttemp2
{
public:
	HtmlBuilderAttemp2(std::string& name);
	explicit HtmlBuilderAttemp2(std::string&& name);
	void add_child(std::string child_name, std::string child_text);
	[[nodiscard]] std::string str() const { return m_root.str(); }
private:
	HtmlElementAttempt2 m_root;
};

