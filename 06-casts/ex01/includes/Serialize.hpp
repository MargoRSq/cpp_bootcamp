#pragma once

#include <iostream>
struct Data
{
	std::string		name;
	std::string		type;
	int				age;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
