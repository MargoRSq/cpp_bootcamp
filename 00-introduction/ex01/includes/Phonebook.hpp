#pragma once

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	mp_book[8];
	int		m_count;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addСontact(void);
	void searchСontact(void);
	int getСount(void);
};
