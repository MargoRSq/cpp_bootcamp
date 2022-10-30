#pragma once

#include <iostream>

class	Fixed {
public:
      Fixed();
      Fixed(const Fixed &copy);
      ~Fixed();

      Fixed &operator=(const Fixed &copy);

      void setRawBits(int const raw);
      int getRawBits(void) const;
private:
      int m_fixed_int_value;
      static const int m_frac_bits = 8;
};
