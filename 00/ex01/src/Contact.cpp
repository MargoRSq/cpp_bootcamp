#include <Contact.hpp>

void	Contact::setFirstName(std::string value)
{
    _firstName = value;
}

void	Contact::setLastName(std::string value)
{
    _firstName = value;
}

void	Contact::setNickname(std::string value)
{
    _firstName = value;
}

void	Contact::setPhoneNumber(std::string value)
{
    _firstName = value;
}

void	Contact::setSecret(std::string value)
{
    _firstName = value;
	// this->_darkestSecret = value;
}

std::string	Contact::getFirstName()
{
	return this->_firstName;
}

std::string	Contact::getLastName()
{
	return this->_lastName;
}
std::string	Contact::getNickname()
{
	return this->_firstName;
}
std::string	Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}
std::string	Contact::getSecret()
{
	return this->_darkestSecret;
}