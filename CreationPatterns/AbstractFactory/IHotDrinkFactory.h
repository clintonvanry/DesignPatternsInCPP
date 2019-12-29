#pragma once
#include <memory>
#include "IHotDrink.h"

// this is abstract factory
class IHotDrinkFactory 
{
public:
    IHotDrinkFactory() = default;
    virtual ~IHotDrinkFactory() = default;
    IHotDrinkFactory(IHotDrinkFactory&&) = default;
    IHotDrinkFactory& operator=(IHotDrinkFactory&&) = default;
    IHotDrinkFactory(const IHotDrinkFactory&) = default;
    IHotDrinkFactory& operator=(const IHotDrinkFactory&) = default;
	
	virtual std::unique_ptr<IHotDrink> make() const = 0;
};
