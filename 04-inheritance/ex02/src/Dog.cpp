#include <Dog.hpp>

Dog::Dog() : AAnimal("Dog")
{
	std::string ideas[100];

	for (int i = 0; i < 100; i++)
		ideas[i] = "How to eat meat";
	this->m_brain = new Brain(ideas, 100);
	std::cout << "[Dog] Default constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : AAnimal(copy.getType())
{
	this->m_brain = new Brain;
	this->m_brain->setIdeas(copy.m_brain->getIdeas(), 100);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	setType(copy.getType());
	this->m_brain = new Brain;
	this->m_brain->setIdeas(copy.m_brain->getIdeas(), 100);
	return (*this);
}
Brain* Dog::getBrain(void) { return this->m_brain; }

Dog::~Dog()
{
	delete this->m_brain;
	std::cout << "[Dog] Destructor called and brain deleted" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Bark bark bark..." << std::endl;
}
