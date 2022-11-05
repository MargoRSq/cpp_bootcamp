#include <iostream>
#include <iomanip>
#include "Serialize.hpp"

int main(void) {
	Data		*cat = new Data;
	uintptr_t	raw;

	std::cout << "--- Create " << std::endl;
	cat->name = "Sam";
	cat->type = "cat";
	cat->age = 4;

	std::cout	<< "ptr: " << cat << std::endl;
	std::cout	<< cat->name << " is a " << cat->type
				<< " he is " << cat->age << " years old." << std::endl;

	std::cout << "--- Serialize " << std::endl;
	raw = serialize(cat);
	std::cout	<< "raw: " << raw << "["
				<< std::hex << raw << std::dec << "]" << std::endl;
	// std::cout	<< raw->name << " is a " << raw->type
	// 			<< " he is " << raw->age << " years old." << std::endl;
	std::cout	<< reinterpret_cast<Data *>(raw)->name << " is a " << reinterpret_cast<Data *>(raw)->type
				<< " he is " << reinterpret_cast<Data *>(raw)->age << " years old." << std::endl;

	std::cout << "--- Deserialize " << std::endl;
	Data *dog = deserialize(raw);
	std::cout	<< "ptr: " << dog << std::endl;
	std::cout	<< dog->name << " is a " << dog->type
				<< " he is " << dog->age << " years old." << std::endl;

	std::cout << "--- Finished " << std::endl;
	std::cout	<< "uintptr_t size = " << sizeof(raw) << std::endl;
	std::cout	<< "Data* size = " << sizeof(cat) << std::endl;
	std::cout	<< "Cat size = " << sizeof(*cat) << std::endl;

	delete dog;
	return 0;
}