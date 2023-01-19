#pragma once

#include <iostream>

class	Brain {
public:
      Brain();
      Brain(std::string *ideas, int ideasLength);
      Brain(const Brain &copy);
      Brain &operator=(const Brain &copy);
      ~Brain();

      void setIdeas(std::string* values, int ideasLength);
      std::string* getIdeas(void);

      void addIdea(const std::string &idea);

private:
      std::string m_ideas[100];
      int         m_ideasLength;
};
