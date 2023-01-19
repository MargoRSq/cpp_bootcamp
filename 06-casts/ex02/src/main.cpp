#include <iostream>
#include <iomanip>
#include "Base.hpp"


int main(void)
{
	{
		Base *		a = new A();
		Base *		b = new B();
		Base *		c = new C();

		std::cout << "--- Create "<< std::endl;

		identify(a);
		identify(*a);
		identify(b);
		identify(*b);
		identify(c);
		identify(*c);

		std::cout << "--- Destroy "<< std::endl;

		delete a;
		delete b;
		delete c;
	}
	{
		Base *		a[10];
		std::cout << "--- Check by ptr* "<< std::endl;

		for (size_t i = 0; i < 10; i++) {
			a[i] = generate();
			identify(a[i]);
		}
		std::cout << "--- Check by ref& "<< std::endl;
		for (size_t i = 0; i < 10; i++) {
			identify(a[i]);
		}

		std::cout << "--- Destroy "<< std::endl;

		for (size_t i = 0; i < 10; i++) {
			delete a[i];
		}
	}
	return 0;
}