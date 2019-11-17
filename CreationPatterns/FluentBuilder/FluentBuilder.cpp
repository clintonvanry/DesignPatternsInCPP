// FluentBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include  "HtmlBuilder.h"
#include <memory>

void fluentbuilderRef();
void fluentbuilderPtr();
void fluentbuilderPtr2();

int main()
{
    std::cout << "use of a fluent builder\n";
	fluentbuilderRef();
	fluentbuilderPtr();
	fluentbuilderPtr2();
	getchar();
}

void fluentbuilderRef()
{
	HtmlBuilder builder("ul");
	builder.add_child("li", "Hello").add_child("li", "World");
	std::cout << builder;
}
void fluentbuilderPtr()
{
	auto builder = HtmlBuilder::builder("ul");
	builder->add_child2("li", "Hello")->add_child2("li", "World");
	std::cout << *builder;
	
}
void fluentbuilderPtr2()
{
	auto builder = std::make_unique<HtmlBuilder>("ul");
	builder->add_child2("li", "Hello")->add_child2("li", "World");
	std::cout << *builder;
}
