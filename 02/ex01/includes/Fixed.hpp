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
      
private:
      int m_fixed_int_value;
      static const int m_frac_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);