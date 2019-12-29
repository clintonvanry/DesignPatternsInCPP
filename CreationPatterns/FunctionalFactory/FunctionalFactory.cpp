
#include <iostream>
#include "DrinkWithVolumeFactory.h"

int main()
{
    std::cout << "Hello World!\n";
	DrinkWithVolumeFactory fac;
	auto drink = fac.make_drink("tea");

	return 0;
}
