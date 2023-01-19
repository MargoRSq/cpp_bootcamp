#include <Brain.hpp>

Brain::Brain()
{
	std::cout << "[Brain] Only type constructor called" << std::endl;
}
Brain::Brain(std::string *ideas, int ideasLength) { setIdeas(ideas, ideasLength); }
Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->m_ideas[i] = copy.m_ideas[i];
	std::cout << "[Brain] Copy constructor called" << std::endl;
}
Brain &Brain::operator=(const Brain &copy)
{
	if (this == &copy)
		return *this;
	for (int i = 0; i < 100; i++)
		this->m_ideas[i] = copy.m_ideas[i];
	std::cout << "[Brain] Copy assignment operator called" << std::endl;
	return (*this);
}
Brain::~Brain() { std::cout << "[Brain] Destructor called" << std::endl; }

void Brain::setIdeas(std::string ideas[], int ideasLength)
{
	if (ideasLength > 100)
	{
		ideas += (ideasLength - 100);
		std::cout << "[Brain] Only last 100 ideas were remembered" << std::endl;
	}
	else
		std::cout << "[Brain] "<< ideasLength <<" ideas were remembered" << std::endl;
	for (int i = 0; i < 100; i++)
		this->m_ideas[i] = ideas[i];
	this->m_ideasLength = ideasLength;
}

std::string* Brain::getIdeas(void) { return m_ideas; }

void Brain::addIdea(const std::string &idea)
{
	// std::cout << this->m_ideasLength % 100 << std::endl;
	this->m_ideas[this->m_ideasLength % 100] = idea;
	this->m_ideasLength++;
}
