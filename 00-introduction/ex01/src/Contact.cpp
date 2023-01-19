#include <Contact.hpp>

Contact::Contact( void )
{
	return;
}

Contact::~Contact( void )
{
	return;
}

void Contact::setAttributes(void)
{
	std::cout << "First name: ";
	std::cin >> this->m_firstName;
	std::cout << "Last name: ";
	std::cin >> this->m_lastName;
	std::cout << "Nickname: ";
	std::cin >> this->m_nickname;
	std::cout << "Phone Number: ";
	std::cin >> this->m_phoneNumber;
	std::cout << "Darkest Secret: ";
	std::cin >> this->m_darkestSecret;
	std::cout << "Contact " << this->m_nickname << " created" << std::endl;
}


void	Contact::setFirstName(std::string value)
{
    m_firstName = value;
}

void	Contact::setLastName(std::string value)
{
    m_lastName = value;
}

void	Contact::setNickname(std::string value)
{
    m_nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
    m_phoneNumber = value;
}

void	Contact::setSecret(std::string value)
{
    m_darkestSecret = value;
}

std::string	Contact::getFirstName()
{
	return this->m_firstName;
}

std::string	Contact::getLastName()
{
	return this->m_lastName;
}
std::string	Contact::getNickname()
{
	return this->m_nickname;
}
std::string	Contact::getPhoneNumber()
{
	return this->m_phoneNumber;
}
std::string	Contact::getSecret()
{
	return this->m_darkestSecret;
}