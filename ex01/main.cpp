#include "Data.hpp"
#include "Serialize.hpp"
#include <iostream>


int	main(void)
{
	Data	customer2("kyolee", "010-xxx-xxxx", 1, 0);
	Data	*p;

	Serialize s;

	p =  s.deserialize(s.serialize(&customer2));
	std::cout << "before serialize pointer : " << &customer2 << std::endl;
	std::cout << "deserialize result pointer : " << p << std::endl;
	
	p->showInfo();
	return (0);
}
