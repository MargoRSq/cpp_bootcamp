#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
public:
      Form();
      Form(std::string const &name, int toSign, int toExecute);
      Form(const Form &copy);
      Form &operator=(const Form &copy);
      ~Form();

      std::string getName(void) const;
	const int &getExecuteGrade(void) const;
	const int &getSignGrade(void) const;

	bool isSigned(void) const;
	bool beSigned(Bureaucrat const &bur);

      class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
      public:
		virtual const char* what() const throw();
	};

private:
      const std::string m_name;
      bool m_signed;
      const int m_signGrade;
      const int m_executeGrade;
};

std::ostream &operator<<(std::ostream &o, Form const &copy);
