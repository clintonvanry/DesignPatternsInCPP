#pragma once
#include "IHotDrink.h"
class Coffee :	public IHotDrink
{
public:
    Coffee() = default;
    virtual ~Coffee() = default;
    Coffee(Coffee&&) = default;
    Coffee& operator=(Coffee&&) = default;
    Coffee(const Coffee&) = default;
    Coffee& operator=(const Coffee&) = default;

	
	void prepare(int volume) override;
};

