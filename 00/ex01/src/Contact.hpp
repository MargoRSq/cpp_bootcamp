#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
public:
      Contact() = default;
      Contact(const Contact &contact);
      ~Contact();
      Contact & operator = (const Contact &contact);

      void setFirstName(std::string value);
      void setLastName(std::string value);
      void setNickname(std::string value);
      void setPhoneNumber(std::string value);
      void setSecret(std::string value);
      std::string getFirstName();
      std::string getLastName();
      std::string getNickname();
      std::string getPhoneNumber();
      std::string getSecret();

private:
   std::string _firstName;
   std::string _lastName;
   std::string _nickname;
   std::string _phoneNumber;
   std::string _darkestSecret;
};

#endif