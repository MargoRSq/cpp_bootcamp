#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
public:
      Cat();
      Cat(const Cat &copy);
      Cat &operator=(const Cat &copy);
      ~Cat();

      Brain* getBrain(void);

      void makeSound() const;

private:
      Brain* m_brain;

};
