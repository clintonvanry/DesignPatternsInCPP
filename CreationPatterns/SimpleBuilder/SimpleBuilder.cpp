#include <iostream>
#include <string>
#include <sstream>
#include "HtmlElementAttempt1.h"
#include "HtmlBuilderAttemp2.h"


using namespace std;

void basic_html_helloworld();
void basic_html_helloworld_simplebuilder1();
void basic_html_helloworld_simplebuilder2();

int main()
{
	// this is not a flexible approach in the event you want to change bullet list to a numbered list
	cout << " A simple scenario to print html elements for hello world" << endl;
	basic_html_helloworld();
	
	cout << endl << "Attempt 1 wth simple builder" << endl;
	basic_html_helloworld_simplebuilder1();

	cout << endl << "Attempt 2 wth simple builder" << endl;
	basic_html_helloworld_simplebuilder2();
	
	getchar();
	
}

void basic_html_helloworld()
{
	
	string words[]{ "Hello", "World" };

	ostringstream oss;

	oss << "<ul>";

	for (const auto& word : words)
	{
		oss << "<li>" << word << "</li>";
	}
	oss << "</ul>";

	printf_s(oss.str().c_str());

}
void basic_html_helloworld_simplebuilder1()
{
	string words[]{ "Hello", "World" };

	HtmlElementAttempt1 html_element{ "ul","" };
	html_element.add_children(HtmlElementAttempt1("li", "Hello"));
	html_element.add_children(HtmlElementAttempt1("li", "World"));

	printf_s(html_element.str().c_str());
}
void basic_html_helloworld_simplebuilder2()
{
	string words[]{ "Hello", "World" };
	HtmlBuilderAttemp2 builder{ "ul" };
	builder.add_child("li", "Hello");
	builder.add_child("li", "World");

	printf_s(builder.str().c_str());
}

