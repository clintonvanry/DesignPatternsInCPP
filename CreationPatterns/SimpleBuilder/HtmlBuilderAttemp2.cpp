#include "HtmlBuilderAttemp2.h"

HtmlBuilderAttemp2::HtmlBuilderAttemp2(std::string& name)
{
	m_root = HtmlElementAttempt2(name);
}

HtmlBuilderAttemp2::HtmlBuilderAttemp2(std::string&& name)
{
	m_root = HtmlElementAttempt2(std::move(name));
}

void HtmlBuilderAttemp2::add_child(std::string child_name, std::string child_text)
{
	const HtmlElementAttempt2 element{ child_name,child_text };
	m_root.add_children(element);
}
