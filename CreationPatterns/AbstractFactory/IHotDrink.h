#pragma once

class IHotDrink
{
public:
	IHotDrink() = default;
	virtual ~IHotDrink() = default;
    IHotDrink(IHotDrink&&) = default;
    IHotDrink& operator=(IHotDrink&&) = default;
    IHotDrink(const IHotDrink&) = default;
    IHotDrink& operator=(const IHotDrink&) = default;
	
	virtual void prepare(int volume) = 0;
};
