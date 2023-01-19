#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "# Subject Test #" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "#Full Test#" << std::endl;
	Fixed arg1(1);
	Fixed arg2(2);
	Fixed arg3(3);
	Fixed arg4(4);
	Fixed arg101(1.01f);
	Fixed arg201(2.01f);
	Fixed arg301(3.01f);
	Fixed arg401(4.01f);
	std::cout << "arg1 = " << arg1 << std::endl;
	std::cout << "arg2 = " << arg2 << std::endl;
	std::cout << "arg3 = " << arg3 << std::endl;
	std::cout << "arg4 = " << arg4 << std::endl;
	std::cout << "arg101 = " << arg101 << std::endl;
	std::cout << "arg201 = " << arg201 << std::endl;
	std::cout << "arg301 = " << arg301 << std::endl;
	std::cout << "arg401 = " << arg401 << std::endl;
	if (arg1 > arg2){std::cout << "arg1 > arg2" << std::endl;}
	if (arg1 < arg2){std::cout << "arg1 < arg2" << std::endl;}
	if (arg1 > arg101){std::cout << "arg1 > arg101" << std::endl;}
	if (arg1 < arg101){std::cout << "arg1 < arg101" << std::endl;}
	if (arg3 >= arg4){std::cout << "arg3 >= arg4" << std::endl;}
	if (arg3 <= arg4){std::cout << "arg3 <= arg4" << std::endl;}
	if (arg3 >= arg301){std::cout << "arg3 >= arg301" << std::endl;}
	if (arg3 <= arg301){std::cout << "arg3 <= arg301" << std::endl;}
	if (arg1 == arg2){std::cout << "arg1 == arg2" << std::endl;}
	if (arg1 != arg2){std::cout << "arg1 != arg2" << std::endl;}
	if (arg1 == arg101){std::cout << "arg1 == arg101" << std::endl;}
	if (arg1 != arg101){std::cout << "arg1 != arg101" << std::endl;}
	if (arg1 == arg1){std::cout << "arg1 == arg1" << std::endl;}
	if (arg1 != arg1){std::cout << "arg1 != arg1" << std::endl;}
	if (arg101 == arg101){std::cout << "arg101 == arg101" << std::endl;}
	if (arg101 != arg101){std::cout << "arg101 != arg101" << std::endl;}
	std::cout << "arg1 + arg2 = " << (arg1 + arg2) << std::endl;
	std::cout << "arg1 + arg101 = " << (arg1 + arg101) << std::endl;
	std::cout << "arg3 - arg4 = " << (arg3 - arg4) << std::endl;
	std::cout << "arg3 - arg401 = " << (arg3 - arg401) << std::endl;
	std::cout << "arg1 * arg2 = " << (arg1 * arg2) << std::endl;
	std::cout << "arg1 * arg101 = " << (arg1 * arg101) << std::endl;
	std::cout << "arg3 / arg4 = " << (arg3 / arg4) << std::endl;
	std::cout << "arg3 / arg401 = " << (arg3 / arg401) << std::endl;
	std::cout << "min(arg1, arg2) = " << Fixed::min(arg1, arg2) << std::endl;
	std::cout << "min(arg3, arg301) = " << Fixed::min(arg3, arg301) << std::endl;
	std::cout << "max(arg3, arg301) = " << Fixed::max(arg3, arg301) << std::endl;
	std::cout << "max(arg301, arg401) = " << Fixed::max(arg301, arg401) << std::endl;
	std::cout << "arg1++ = " << arg1++ << std::endl;
	std::cout << "arg1 = " << arg1 << std::endl;
	std::cout << "++arg1 = " << ++arg1 << std::endl;
	std::cout << "arg1 = " << arg1 << std::endl;
	std::cout << "arg101++ = " << arg101++ << std::endl;
	std::cout << "arg101 = " << arg101 << std::endl;
	std::cout << "++arg101 = " << ++arg101 << std::endl;
	std::cout << "arg101 = " << arg101 << std::endl;
	std::cout << "arg2-- = " << arg2-- << std::endl;
	std::cout << "arg2 = " << arg2 << std::endl;
	std::cout << "--arg2 = " << --arg2 << std::endl;
	std::cout << "arg2 = " << arg2 << std::endl;
	std::cout << "arg201-- = " << arg201-- << std::endl;
	std::cout << "arg201 = " << arg201 << std::endl;
	std::cout << "--arg201 = " << --arg201 << std::endl;
	std::cout << "arg201 = " << arg201 << std::endl;

	return (0);
}