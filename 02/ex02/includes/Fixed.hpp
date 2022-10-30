#pragma once

#include <iostream>
#include <cmath>

class	Fixed {
public:
      Fixed();
      Fixed(const int value);
      Fixed(const float value);
      Fixed(const Fixed &copy);
      ~Fixed();

      Fixed &operator=(const Fixed &copy);

      void setRawBits(int const raw);
      int getRawBits(void) const;

      float toFloat(void) const;
      int toInt(void) const;	

      //Операторы сравнения (без &, так как выводимый результат (bool) не копируется откуда-либо)
      bool operator>(const Fixed &value) const;
      bool operator<(const Fixed &value) const;
      bool operator>=(const Fixed &value) const;
      bool operator<=(const Fixed &value) const;
      bool operator==(const Fixed &value) const;
      bool operator!=(const Fixed &value) const;
      //Математические операторы (также без &, так как выводимое значение является новым)
      Fixed operator+(const Fixed &value);
      Fixed operator-(const Fixed &value);
      Fixed operator*(const Fixed &value);
      Fixed operator/(const Fixed &value);
      Fixed operator++(void); //Использование перед увеличением
      Fixed operator--(void); //Использование перед уменьшением
      Fixed operator++(int); //Использование после увеличения
      Fixed operator--(int); //Использование после уменьшения
      //Методы MAX и MIN
      static const Fixed &min(const Fixed &value1, const Fixed &value2);
      static const Fixed &max(const Fixed &value1, const Fixed &value2);
      static Fixed &min(Fixed &value1, Fixed &value2);
      static Fixed &max(Fixed &value1, Fixed &value2);
      
private:
      int m_fixed_int_value;
      static const int m_frac_bits = 8;
};

//Перегрузка оператора вставки хранимого значения в выходной поток
std::ostream &operator<<(std::ostream &out, const Fixed &value);