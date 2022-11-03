#pragma once

#include <iostream>
#include <AForm.hpp>

class AForm;

class	Bureaucrat {
public:
      Bureaucrat();
      Bureaucrat(std::string const &name, int number);
      Bureaucrat(const Bureaucrat &copy);
      Bureaucrat &operator=(const Bureaucrat &copy);
      ~Bureaucrat();

      std::string getName(void) const;
      int getGrade(void) const;

      void incrementGrade(int points);
	void decrementGrade(int points);
      void signForm(AForm &f);
      void executeForm(AForm const &f);

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
      int m_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
