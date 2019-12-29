#pragma once
#include <map>
#include <string>
#include <memory>
#include <functional>
#include "IHotDrink.h"
#include "Tea.h"

class DrinkWithVolumeFactory 
{
	std::map<std::string, std::function<std::unique_ptr<IHotDrink>()>> factories;
public:
	DrinkWithVolumeFactory()
	{
		factories["tea"] = []
		{
			auto tea = std::make_unique<Tea>();
			tea->prepare(200);
			return tea;
		};
	}

	[[nodiscard]] std::unique_ptr<IHotDrink> make_drink(const std::string& name) 
	{
		return factories[name]();
	}

};

