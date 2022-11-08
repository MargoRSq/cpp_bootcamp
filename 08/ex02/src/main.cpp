#include "MutantStack.hpp"

int main(void) {
	{
		std::cout << "--- MutantStack " << std::endl;
		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
		// 5, 7
		std::cout << "mstack.top() " << mstack.top() << std::endl;
		mstack.pop();
		// 5
		std::cout << "mstack.size() " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		// 5, 3, 5, 737, 0
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		std::cout << "Iterater Incremented: " << *it << std::endl;
		--it;
		std::cout << "Iterater Decremented: " << *it << std::endl;
		int i = 1;
		while (it != ite)
		{
			std::cout << i++ << ": " << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	return 0;
}