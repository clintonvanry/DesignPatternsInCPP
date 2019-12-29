
#include <iostream>
#include <memory>
#include "Tea.h"
#include "Coffee.h"
#include "DrinkFactory.h"

// this is one way but it is not using the factories
std::unique_ptr<IHotDrink> make_drink(std::string type)
{
	std::unique_ptr<IHotDrink> drink;
	if(type =="tea")
	{
		drink = std::make_unique<Tea>();
		drink->prepare(200);
	}
	else
	{
		drink = std::make_unique<Coffee>();
		drink->prepare(50);
	}

	return drink;
}

int main()
{
    std::cout << "Hello World!\n";

	DrinkFactory df;
	auto drink = df.make_drink("tea");
	
	return 0;

}
