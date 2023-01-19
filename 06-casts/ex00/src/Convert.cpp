#include "Convert.hpp"

Convert::Convert(): m_number(0), m_type(0), m_str("Error"), m_prec(0) {}
Convert::Convert(std::string const & str): m_number(0), m_type(0), m_str(str), m_prec(1)
{
	if (isInt(str)) {const_cast<short &>(m_type) = T_INT; }
	else if (isSpecial(str)) {const_cast<short &>(m_type) = T_SPECIAL; }
	else if (isChar(str)) {const_cast<short &>(m_type) = T_CHAR; }
	else if (isFloat(str)) {const_cast<short &>(m_type) = T_FLOAT; }
	else if (isDouble(str)) {const_cast<short &>(m_type) = T_DOUBLE; }

	if (m_type == T_CHAR)
		const_cast<double &>(this->m_number) = str.at(0);
	if (m_type  == T_INT || m_type == T_FLOAT || m_type == T_DOUBLE)
	{
		const_cast<double &>(this->m_number) = std::stod(str);
		size_t pos = 0;
		if ((pos = str.find(".")) != std::string::npos)
		{
			this->m_prec = str.length() - ++pos;
			if (m_type == T_FLOAT)
				this->m_prec -= 1;
			if (this->m_prec == 0)
				this->m_prec = 1;
		}
	}
}
Convert::Convert(Convert const & copy) : m_number(copy.getNumber()), m_type(copy.getType()),
	m_str(copy.getStr()), m_prec(copy.getPrec()) {}
Convert & Convert::operator=(Convert const & copy) {
	const_cast<double &>(m_number) = copy.getNumber();
	const_cast<short &>(m_type) = copy.getType();
	return *this;
}
Convert::~Convert() {}

const double & Convert::getNumber(void) const { return this->m_number; }
const short & Convert::getType(void) const { return this->m_type; }
const std::string & Convert::getStr(void) const {return this->m_str; }
const int & Convert::getPrec(void) const { return this->m_prec; }
	
bool Convert::isChar(std::string const & str) const
{
	return (str.length() == 1 && std::isprint(str[0]));
}

bool Convert::isInt(std::string const & str) const
{
	std::stringstream 	ss(str);
	int num;

	ss >> num;
	return (ss.eof() == 1 && ss.fail() == 0);
}

static bool isFloatNumber(const std::string& str)
{
	std::string::const_iterator i = str.begin();
	bool decimalPoint = false;
	if (str.size() > 0 && (str[0] == '-' || str[0] == '+'))
		i++;
	while (i != str.end())
	{
		if (*i == '.')
		{
			if (!decimalPoint)
				decimalPoint = true;
			else
				break;
		}
		else if (!std::isdigit(*i) && ((*i != 'f') || (i + 1) != str.end()))
			break;
		i++;
	}
	return (i == str.end());
}

bool Convert::isFloat(std::string const & str) const
{
	try {
		float num = std::stof(str);
		(void) num;
	}
	catch(const std::exception& e) {
		return false;
	}
	if (isFloatNumber(str) && str.at(str.length() - 1) == 'f')
		return true;
	return false;
}

bool Convert::isDouble(std::string const & str) const
{
	std::stringstream 	ss(str);
	double				num;

	ss >> num;
	return (ss.eof() == 1 && ss.fail() == 0);
}

bool Convert::isSpecial(std::string const & str) const
{
	std::stringstream 	ss("nan nanf -inff +inff -inf +inf inff inf");
	std::string			current;

	while (ss.eof() != 1)
	{
		ss >> current;
		if (current == str)
			return true;
	}
	return (false);
}

void Convert::toChar(void)
{
	std::cout << "char: ";
	if (this->m_type == T_EMPTY)
		std::cout << "Error";
	else if (this->m_type == T_SPECIAL)
		std::cout << "Impossible";
	else if (this->m_number < 0.0 || this->m_number > 255.0)
		std::cout << "Outside boundaries";
	else if (std::isprint(static_cast<char>(this->m_number)))
		std::cout << "\'"
		<< static_cast<char>(this->m_number) << "\'";
	else if (this->m_str == " ")
		std::cout << "\' \'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}
void Convert::toInt(void)
{
	std::cout << "int: ";
	if (this->m_type == T_EMPTY)
		std::cout << "Error";
	else if (this->m_type == T_SPECIAL)
		std::cout << "Impossible";
	else if (this->m_number < static_cast<double>(INT_MIN) || this->m_number > static_cast<double>(INT_MAX))
		std::cout << "Overflow";
	else
		std::cout << static_cast<int>(this->m_number);
	std::cout << std::endl;
}

void Convert::toFloat(void)
{
	std::cout << "float: ";
	if (this->m_type == T_EMPTY)
		std::cout << "Error";
	else if (this->m_type == T_SPECIAL)
	{
		if (this->m_str == "inff" || this->m_str == "-inff" 
			|| this->m_str == "+inff" || this->m_str == "nanf")
			std::cout << this->m_str;
		else
			std::cout << this->m_str << 'f';
	}
	else
		std::cout	<< std::fixed << std::setprecision(this->m_prec)
					<< static_cast<float>(this->m_number) << 'f';
	std::cout << std::endl;
}

void Convert::toDouble(void)
{
	std::cout << "double: ";
	if (this->m_type == T_EMPTY)
		std::cout << "Error";
	else if (this->m_type == T_SPECIAL)
	{
		if (this->m_str == "inff" || this->m_str == "-inff"
			|| this->m_str == "+inff" || this->m_str == "nanf")
			std::cout << this->m_str.substr(0, this->m_str.length() - 1);
		else
			std::cout << this->m_str;
	}
	else
		std::cout	<< std::fixed << std::setprecision(this->m_prec)
					<< this->m_number;
	std::cout << std::endl;
}
