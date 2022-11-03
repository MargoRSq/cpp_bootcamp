#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
public:
      AForm(std::string const &name, std::string const &target,
            int toSign, int toExecute);
      AForm(const AForm &copy);
      virtual AForm &operator=(const AForm &copy);
      virtual ~AForm();

      const std::string &getName(void) const;
      const std::string &getTarget(void) const;
	const int &getExecuteGrade(void) const;
	const int &getSignGrade(void) const;

      void setSigned(bool flag);

	bool isSigned(void) const;
	bool beSigned(Bureaucrat const &bur);
      virtual bool execute(Bureaucrat const &executor) const = 0;

      class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
      public:
		virtual const char* what() const throw();
	};

private:
      bool m_signed;
      const int m_signGrade;
      const int m_executeGrade;
      const std::string m_name;
      const std::string m_target;
};

std::ostream &operator<<(std::ostream &o, AForm const &copy);
