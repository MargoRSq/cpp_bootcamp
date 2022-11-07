#include <iostream>
#include "iter.hpp"

int main( void )
{
	float arr_float[] = {0.2, 0.3, 0.5};
	int arr_int[] = {1, 2, 3, 5, 7};
	std::string arr_string[] = {"kek", "kik"};
	unsigned int len;

	len = 3;
	::iter(arr_float, len, ::print);
	std::cout << std::endl;

	len = 5;
	::iter(arr_int, len, ::print);
	std::cout << std::endl;

	len = 2;
	::iter(arr_string, len, ::print);
	std::cout << std::endl;

	return 0;
}