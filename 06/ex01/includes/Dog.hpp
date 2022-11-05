#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
public:
      Dog();
      Dog(const Dog &copy);
      Dog &operator=(const Dog &copy);
      ~Dog();

      Brain* getBrain(void);

      void makeSound() const;

private:
      Brain* m_brain;

};
