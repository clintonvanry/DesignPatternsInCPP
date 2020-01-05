#pragma once
#include "Contact.h"
#include <memory>

class EmployeeFactory
{

public:
    static std::unique_ptr<Contact> NewMainOfficeEmployee(const std::string& name, int suite)
    {
        //static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
        return new_employee(name, suite, main);
    }

    static std::unique_ptr<Contact> NewAuxOfficeEmployee(const std::string& name, int suite)
    {
        return new_employee(name, suite, aux);
    }
	
private:

    inline static Contact main {"",new Address{"123 East Dr", "London", 0}};
    inline static Contact aux{ "",new Address{"123 East Dr", "London", 0} };
	
	static std::unique_ptr<Contact> new_employee(const std::string& name, int suite, const Contact& prototype)
	{
		auto result = std::make_unique<Contact>(prototype);
		result->setName(name);
		result->setSuite(suite);
		return result;
	}
};

