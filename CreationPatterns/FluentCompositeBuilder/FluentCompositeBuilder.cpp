#include <iostream>
#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main()
{
	const auto p = Person::create();
	p.lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
		.works().at("PragmaSoft").as_a("Consultant").earning(10e6);

	std::cout << p << std::endl;
	auto c = getchar();
}
