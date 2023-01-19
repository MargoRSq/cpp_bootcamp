#include "Span.hpp"

Span::Span(const unsigned int& max_size) : m_size(max_size) {}
Span::Span(const Span& copy) : m_size(copy.getSize()) {}
Span& Span::operator=(const Span& copy)
{
    this->m_size = copy.getSize();
    this->m_arr = copy.getArr();
    return *this;
}
Span::~Span() {}

void Span::setSize(const unsigned int& value) { this->m_size = value; }
unsigned int Span::getSize(void) const { return this->m_size; }
std::vector<int> Span::getArr(void) const { return this->m_arr; }

void Span::addNumber(int value)
{
    if (this->m_arr.size() < this->m_size)
    {
        this->m_arr.push_back(value);
        std::cout << value << " added to the back" << std::endl;
    }
    else
        throw std::length_error("Span is full");
}
void Span::addRange(v_it a, v_it z)
{
	unsigned int	num = std::distance(a, z);

	if (this->m_size < num)
		throw std::overflow_error("Not enough space to insert the range");
	copy(a, z, std::back_inserter(this->m_arr));
}

unsigned int Span::longestSpan() const
{
	v_cit min = std::min_element(this->m_arr.begin(), this->m_arr.end());
	v_cit max = std::max_element(this->m_arr.begin(), this->m_arr.end());

	if (this->m_arr.size() < 2)
		throw std::logic_error("The span has less than 2 elements");
	return (*max - *min);
}

unsigned int Span::shortestSpan() const
{
	std::vector<int>	tmp = this->m_arr;
	int					result;

	if (this->m_arr.size() < 2)
		throw std::logic_error("The span has less than 2 elements");
	sort(tmp.begin(), tmp.end());
	result = *(tmp.begin() + 1) - *tmp.begin();
	v_cit iter = tmp.begin() + 1;
	v_cit last = tmp.end() - 1;
	while (iter != last && result != 0)
    {
		if ((*(iter + 1) - *iter) < result)
			result = *(iter + 1) - *iter;
		iter++;
	}
	return result;
}

v_it Span::begin(void) { return this->m_arr.begin(); }
v_it Span::end(void) { return this->m_arr.end(); }

std::ostream	&operator<<(std::ostream &out, Span &elem)
{
	if (elem.getSize() == 0)
		return out;
	v_it current = elem.begin();
	v_it last = elem.end();

	while (current != last)
    {
		out << "| " << *current << std::endl;
        current++;
    }
	return out;
}