#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << "--- Subject tests" << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	{
		std::cout << "--- My tests" << std::endl;
		Array<int>				nums(5);
		Array<std::string>		cities1(5);
		Array<std::string>		cities2(5);

		int						vals[] = {1, 2, 3, 4, 5};
		std::string				citiesUk[] = {"London", "Liverpool", "Manchester", "Sheffield", "Bristol"};
		std::string				citiesSpain[] = {"Madrid", "Valencia", "Cordoba", "Sevilla", "Barcelona"};

		std::cout << "--- Check cities1" << std::endl;
		for (unsigned int i = 0; i < cities1.size(); i++) {
			std::cout << "cities1[" << i << "] = " << cities1[i] << std::endl;
		}

		std::cout << "--- Set values for cities 1 and nums" << std::endl;
		for (unsigned int i = 0; i < cities1.size(); i++) {
			cities1[i] = citiesUk[i];
			nums[i] = vals[i];
			std::cout << "cities1[" << i << "] = " << cities1[i] << std::endl;
		}
		std::cout << "--- Copy cities1 to cities2" << std::endl;
		cities2 = cities1;

		std::cout << "--- Update values for cities2" << std::endl;
		for (unsigned int i = 0; i < cities2.size(); i++) {
			cities2[i] = citiesSpain[i];
			std::cout << "cities2[" << i << "] = " << cities2[i] << std::endl;
		}

		std::cout << "--- Check cities1" << std::endl;
		for (unsigned int i = 0; i < cities1.size(); i++) {
			std::cout << "cities1[" << i << "] = " << cities1[i] << std::endl;
		}
		std::cout << "--- Check out of bounds" << std::endl;
		try {
			std::cout << "nums size is " << nums.size() << std::endl;
			std::cout << "nums[5] is " << nums[5] << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
		try {
			std::cout << "nums[-1] is " << nums[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << ">> Exception caught: " << e.what() << '\n';
		}
		std::cout << "--- Tests finished" << std::endl;
	}
	return 0;
}