
#include <iostream>
#include "Contact.h"
#include "EmployeeFactory.h"

int main()
{
    std::cout << "Hello World!\n";

	//Contact john{"John Doe", new Address{"123 East Dr","London",10}};
	////Contact jane{ "Jane Smith", new Address{"123 East Dr","London",20} };
 //   auto jane = john;
	//jane.setName("Jane Smith");
	//jane.setSuite(15);

	auto john = EmployeeFactory::NewMainOfficeEmployee("John Doe", 10);
	auto jane = EmployeeFactory::NewAuxOfficeEmployee("Jane Smith", 15);

	
	std::cout << *john << std::endl;

	std::cout << *jane << std::endl;
}
