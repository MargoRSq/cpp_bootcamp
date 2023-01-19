#include <iomanip>

#include "Phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->m_count = 0;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::addСontact(void)
{
	this->mp_book[m_count % 8].setAttributes();
	this->m_count += 1;
}

bool isNumber(std::string str)
{
	int		i = 0;

	while (str[i])
	{
		if (std::isdigit(str.at(i++)) == 0)
			return false;
	}
	return true;
}

void printColumn(const std::string value )
{
	std::string		pipe = "|";

	if (value.length() <= 10)
		std::cout << pipe << std::setw(10) << value;
	else
		std::cout <<pipe << value.substr(0,9) << ".";
}



void PhoneBook::searchСontact(void)
{
	int				i = 0;
	std::string		input;
	std::string		separator = "+----------+----------+----------+----------+";
	std::string		pipe = "|";

	if (this->m_count == 0)
	{
		std::cout << "The PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << separator << std::endl;
	std::cout << "| INDEX    | F.NAME   | L.NAME   | NICKNAME |" << std::endl;
	std::cout << separator << std::endl;

	while (i < this->m_count && i < 8)
	{
		std::cout << std::left << pipe << std::setw(10) << (i + 1);
		printColumn(this->mp_book[i].getFirstName());
		printColumn(this->mp_book[i].getLastName());
		printColumn(this->mp_book[i].getNickname());
		std::cout << pipe << std::endl;
		i++;
	}
	std::cout << separator << std::endl;
	std::cout << "Please, enter index number: ";
	std::getline(std::cin, input);
	if (isNumber(input) == false)
	{
		std::cout	<< "The number should be from 1 to ";
		if (getСount() < 8)
			std::cout << getСount() << std::endl;
		else
			std::cout << "8" << std::endl;
	}
	else
	{
		i = std::stoi(input) - 1;
		if (i >= 0 && i < getСount() && i < 8)
		{
			std::cout << separator << std::endl;
			std::cout	<< std::left
						<< std::setw(18) << "First name:" << this->mp_book[i].getFirstName() << std::endl
						<< std::setw(18) << "Last name:" << this->mp_book[i].getLastName() << std::endl
						<< std::setw(18) << "Nickname:" << this->mp_book[i].getNickname() << std::endl
						<< std::setw(18) << "Phone Number:" << this->mp_book[i].getPhoneNumber() << std::endl
						<< std::setw(18) << "Darkest Secret:" << this->mp_book[i].getSecret()
						<< std::endl;
			std::cout << separator << std::endl;
		}
		else
		{
			std::cout	<< "The number should be from 1 to ";
			if (getСount() < 8)
				std::cout << getСount();
			else
				std::cout << "8";
			std::cout << std::endl;
		}
	}
}


int	PhoneBook::getСount(void)
{
	return this->m_count;
}