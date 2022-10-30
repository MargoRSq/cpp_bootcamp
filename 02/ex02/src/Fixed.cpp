#include "Fixed.hpp"

//Конструктор по умолчанию
Fixed::Fixed(){this->m_fixed_int_value = 0;}

//Конструктор, принимающий INT
Fixed::Fixed(int const value){this->m_fixed_int_value = (value << this->m_frac_bits);}

//Конструктор, принимающий Float
Fixed::Fixed(float const value){this->m_fixed_int_value = roundf(value * (1 << this->m_frac_bits));}

//Конструктор с копированием другого значения
Fixed::Fixed(const Fixed &copy){*this = copy;}

//Деструктор
Fixed::~Fixed(){}

//Оператор присваивания
Fixed &Fixed::operator=(const Fixed &copy){this->m_fixed_int_value = copy.getRawBits(); return (*this);}

//Назначение значения переменной
void Fixed::setRawBits(int const raw){this->m_fixed_int_value = raw;}

//Извлечение значения переменной
int Fixed::getRawBits(void) const{return (this->m_fixed_int_value);}

//Преобразование Fixed в Float
float Fixed::toFloat(void) const{return ((float)this->m_fixed_int_value / (float)(1 << this->m_frac_bits));}

//Преобразование Fixed в Int
int Fixed::toInt(void) const{return (this->m_fixed_int_value >> this->m_frac_bits);}

//Операторы сравнения
bool Fixed::operator>(const Fixed &value) const{return (this->m_fixed_int_value > value.getRawBits());}
bool Fixed::operator<(const Fixed &value) const{return (this->m_fixed_int_value < value.getRawBits());}
bool Fixed::operator>=(const Fixed &value) const{return (this->m_fixed_int_value >= value.getRawBits());}
bool Fixed::operator<=(const Fixed &value) const{return (this->m_fixed_int_value <= value.getRawBits());}
bool Fixed::operator==(const Fixed &value) const{return (this->m_fixed_int_value == value.getRawBits());}
bool Fixed::operator!=(const Fixed &value) const{return (this->m_fixed_int_value != value.getRawBits());}

//Математические операторы
Fixed Fixed::operator+(const Fixed &value){return Fixed(this->toFloat() + value.toFloat());}
Fixed Fixed::operator-(const Fixed &value){return Fixed(this->toFloat() - value.toFloat());}
Fixed Fixed::operator*(Fixed const &value){return Fixed(this->toFloat() * value.toFloat());}
Fixed Fixed::operator/(Fixed const &value)
{
	if (value.toFloat() > 0.0){return Fixed(this->toFloat() / value.toFloat());}
	else {throw std::runtime_error("Cannot divide by zero");}
}
Fixed Fixed::operator++(void){this->m_fixed_int_value++; return (*this);}
Fixed Fixed::operator--(void){this->m_fixed_int_value--; return (*this);}
Fixed Fixed::operator++(int){Fixed ret = *this; this->m_fixed_int_value++; return(ret);}
Fixed Fixed::operator--(int){Fixed ret = *this; this->m_fixed_int_value--; return(ret);}

//Методы MAX и MIN
Fixed &Fixed::min(Fixed &value1, Fixed &value2) {

	if (value1 < value2){return value1;}
	else {return value2;}
}
Fixed &Fixed::max(Fixed &value1, Fixed &value2)
{
	if (value1 > value2){return value1;}
	else {return value2;}
}
Fixed const &Fixed::min(const Fixed &value1, const Fixed &value2)
{
	if (value1 < value2){return value1;}
	else {return value2;}
}
Fixed const &Fixed::max(const Fixed &value1, const Fixed &value2)
{
	if (value1 > value2){return value1;}
	else {return value2;}
}

//Вывод Fixed в поток в формате Float
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return (out);
}
