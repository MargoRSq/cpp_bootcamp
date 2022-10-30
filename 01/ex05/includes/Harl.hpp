#pragma once

#include <iostream>

class Harl {
public:
      Harl();
      Harl(const Harl &Harl);
      Harl(const std::string &name);
      ~Harl();

	void complain(std::string level);

private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
    
};
