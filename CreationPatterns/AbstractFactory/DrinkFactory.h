#pragma once
#include "IHotDrinkFactory.h"
#include "IHotDrink.h"
#include <map>
#include <string>
#include "TeaFactory.h"
#include "CoffeeFactory.h"

class DrinkFactory
{
	
	std::map<std::string, std::unique_ptr<IHotDrinkFactory>> hot_factories;
	
public:
	DrinkFactory()
	{
		hot_factories["tea"] = std::make_unique<TeaFactory>();
		hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
	}
	std::unique_ptr<IHotDrink> make_drink(const std::string& name)
	{
		auto drink = hot_factories[name]->make();
		drink->prepare(200);
		return drink;
	}
};

