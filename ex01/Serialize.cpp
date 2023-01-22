#include "Serialize.hpp"
#include <iostream>

Serialize::Serialize()
{
	std::cout << "Serialize Default Constructor Called\n";
}

Serialize::~Serialize()
{
	std::cout << "Seralize Destructor Called\n";
}
	
Serialize::Serialize(const Serialize& rSl)
{
	std::cout << "Seralize Copy Constructor Called\n";
	static_cast<void>(rSl);
}
	
Serialize& Serialize::operator=(const Serialize& rSl)
{
	std::cout << "Serialize Copy Operator Called\n";
	static_cast<void>(rSl);
	return (*this);
}
	
	
uintptr_t Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr)); 
}
	

Data* Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
