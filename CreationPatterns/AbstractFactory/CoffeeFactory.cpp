#include "CoffeeFactory.h"
#include "Coffee.h"

std::unique_ptr<IHotDrink> CoffeeFactory::make() const
{
	return std::make_unique<Coffee>();
}
