#include <Cat.hpp>

Cat::Cat() : Animal("Cat")
{
	std::string ideas[100];

	for (int i = 0; i < 100; i++)
		ideas[i] = "How to eat fish";
	this->m_brain = new Brain(ideas, 100);
	std::cout << "[Cat] Default constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy.getType())
{
	this->m_brain = new Brain;
	this->m_brain->setIdeas(copy.m_brain->getIdeas(), 100);
	std::cout << "[Cat] Copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	setType(copy.getType());
	this->m_brain = new Brain;
	this->m_brain->setIdeas(copy.m_brain->getIdeas(), 100);
	return (*this);
}
Brain* Cat::getBrain(void) { return this->m_brain;  }

Cat::~Cat()
{
	delete this->m_brain;
	std::cout << "[Cat] Destructor called and brain deleted" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meeeoooooowwww..." << std::endl;
}
