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
Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->m_fixed_int_value = (value << this->m_frac_bits); //Побитовый сдвиг влево на 8 позиций битов
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->m_fixed_int_value = roundf(value * (1 << this->m_frac_bits)); //Преобразование значения FLOAT в хранимое INT
}
Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->m_fixed_int_value = original.getRawBits();
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

float Fixed::toFloat(void) const
{
	return ((float)this->m_fixed_int_value / (float)(1 << this->m_frac_bits)); //Преобразует хранимое INT в FLOAT для вывода
}

//Преобразование Fixed в Int
int Fixed::toInt(void) const
{
	return (this->m_fixed_int_value >> this->m_frac_bits); //Побитовый сдвиг вправо на 8 позиций битов
}

//Вывод Fixed в поток в формате Float
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return (out);
}
