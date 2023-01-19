#pragma once

#include <sstream>
#include <iomanip>
#include <limits>
#include <istream>
#include <iostream>
#include <limits.h>

#define T_EMPTY		0
#define T_CHAR		1
#define T_INT		2
#define T_FLOAT		3
#define T_DOUBLE	4
#define T_SPECIAL	5

class Convert {
public:
	Convert();
	Convert(std::string const & str);
	Convert(Convert const & src);
	Convert & operator=(Convert const & rhs);
	~Convert();

	const double & getNumber(void) const;
	const short & getType(void) const;
	const std::string & getStr(void) const;
	const int & getPrec(void) const;
	
	bool isChar(std::string const & str) const;
	bool isInt(std::string const & str) const;
	bool isFloat(std::string const & str) const;
	bool isDouble(std::string const & str) const;
	bool isSpecial(std::string const & str) const;

	void toChar(void);
	void toInt(void);
	void toFloat(void);
	void toDouble(void);

private:
	const double			m_number;
	const short				m_type;
	const std::string		m_str;
	int						m_prec;
};
