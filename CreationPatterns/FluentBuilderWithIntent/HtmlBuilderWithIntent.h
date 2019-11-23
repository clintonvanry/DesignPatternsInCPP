#ifndef HtmlBuilderWithIntent_FILE
#define HtmlBuilderWithIntent_FILE
#ifdef _MSC_VER
#pragma once
#endif
#include <string>
#include <memory>

class HtmlElementWithIntent;

class HtmlBuilderWithIntent
{
public:
	HtmlBuilderWithIntent(std::string& name);
	explicit  HtmlBuilderWithIntent(std::string&& name);
	virtual ~HtmlBuilderWithIntent();

	HtmlBuilderWithIntent* add_child(std::string name, std::string text);
	[[nodiscard]] std::string str() const;
	
	friend  std::ostream& operator<<(std::ostream& out_ostream, const  HtmlBuilderWithIntent& builder);
protected:
private:
	HtmlElementWithIntent* m_root;
	
};


#endif

