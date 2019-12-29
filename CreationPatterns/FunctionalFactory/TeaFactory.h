#pragma once
#include "IHotDrinkFactory.h"
class TeaFactory : public IHotDrinkFactory
{
public:
	[[nodiscard]] std::unique_ptr<IHotDrink> make() const override;
};

