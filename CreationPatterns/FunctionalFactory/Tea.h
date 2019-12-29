#pragma once
#include "IHotDrink.h"
class Tea : public IHotDrink
{
public:
    Tea() = default;
    virtual ~Tea() = default;
    Tea(Tea&&) = default;
    Tea& operator=(Tea&&) = default;
    Tea(const Tea&) = default;
    Tea& operator=(const Tea&) = default;

    void prepare(int volume) override;
};

