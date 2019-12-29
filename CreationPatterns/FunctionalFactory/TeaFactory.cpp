#include "TeaFactory.h"
#include "Tea.h"

std::unique_ptr<IHotDrink> TeaFactory::make() const
{
	return std::make_unique<Tea>();
}
