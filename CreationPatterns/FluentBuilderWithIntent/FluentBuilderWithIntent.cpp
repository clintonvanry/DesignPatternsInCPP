// FluentBuilderWithIntent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "HtmlBuilderWithIntent.h"
#include "HtmlElementWithIntent.h"

int main()
{

	auto builder = HtmlElementWithIntent::builder("ul");
	builder->add_child("li", "hello")->add_child("li", "world");
	std::cout << builder << std::endl;
	auto c  = getchar();
}
