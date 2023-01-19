#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Cat cat;
	Dog* dog = new Dog;

	cat.getBrain()->addIdea("How to ruin the furniture");
	cat.getBrain()->addIdea("How to eat something");
	std::cout << cat.getBrain()->getIdeas()[0] << std::endl;
	std::cout << cat.getBrain()->getIdeas()[1] << std::endl;
	std::cout << cat.getBrain()->getIdeas()[84] << std::endl;

	dog->getBrain()->addIdea("How to eat owner");
	std::cout << dog->getBrain()->getIdeas()[0] << std::endl;
	std::cout << dog->getBrain()->getIdeas()[1] << std::endl;
	std::cout << dog->getBrain()->getIdeas()[54] << std::endl;
	delete dog;

	std::cout << "-- subject test --" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	j->makeSound();
	i->makeSound();
	delete j;//should not create a leak
	delete i;
	std::cout << "-- subject test --" << std::endl;
	return 0;
}