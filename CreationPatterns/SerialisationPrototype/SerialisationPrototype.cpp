
#include <iostream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <sstream>
#include "Contact.h"

int main()
{
	
    std::cout << "Hello World!\n";

    auto clone = [](const Contact& c)
    {
        // 1. Serialize the contact
        std::ostringstream oss;
        boost::archive::text_oarchive oa(oss);
        oa << c;
        std::string s = oss.str();
        std::cout << "Serialised string: " << s << std::endl;

        // 2. Deserialize the contact
        std::istringstream iss(oss.str());
        boost::archive::text_iarchive ia(iss);
        Contact result;
        ia >> result;
        return result;
    };

    Contact john{ "John Doe", new Address{"123 East Dr","London",10} };
    auto jane = clone(john);
    jane.setSuite(35);
	
    std::cout << john << std::endl;

    std::cout << jane << std::endl;

	return 0;
}
