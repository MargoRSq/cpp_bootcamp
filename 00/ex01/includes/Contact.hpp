#pragma once

#include <iostream>

class Contact {
public:
      Contact();
      // Contact(const Contact &contact);
      ~Contact();
      // Contact & operator = (const Contact &contact);

      void setFirstName(std::string value);
      void setLastName(std::string value);
      void setNickname(std::string value);
      void setPhoneNumber(std::string value);
      void setSecret(std::string value);
      std::string getFirstName(void);
      std::string getLastName(void);
      std::string getNickname(void);
      std::string getPhoneNumber(void);
      std::string getSecret(void);

      void setAttributes();

private:
      std::string m_firstName;
      std::string m_lastName;
      std::string m_nickname;
      std::string m_phoneNumber;
      std::string m_darkestSecret;
};
