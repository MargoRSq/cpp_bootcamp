#include <Fixed.hpp>

Fixed::Fixed()
{
   	std::cout << "Default constructor called" << std::endl; 
    this->m_fixed_int_value = 0;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->m_fixed_int_value = copy.getRawBits(); //Вариант с прямым назначением значения переменной
	//*this = copy; //Вариант с использованием оператора присваивания
}
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->m_fixed_int_value = copy.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->m_fixed_int_value = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->m_fixed_int_value);
}
