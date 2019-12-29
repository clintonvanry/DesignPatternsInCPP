#pragma once
#include "IHotDrinkFactory.h"
class CoffeeFactory : 	public IHotDrinkFactory
{
public:
	[[nodiscard]] std::unique_ptr<IHotDrink> make() const override;
};

