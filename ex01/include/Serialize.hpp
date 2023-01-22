#ifndef _SERIALIZE_HPP
#define _SERIALIZE_HPP

#include <string>
#include "Data.hpp"
#include <stdint.h>

class Serialize
{
public:
	Serialize();
	~Serialize();
	Serialize(const Serialize& rSl);
	Serialize& operator=(const Serialize& rSl);
	
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};
#endif

