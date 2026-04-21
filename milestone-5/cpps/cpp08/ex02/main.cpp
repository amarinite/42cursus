#include <iostream>
#include <list>
#include "MutantStack.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main()
{
	MutantStack<int> mstack;

	std::cout << YELLOW << "[MutantStack Test]" << RESET << std::endl;


	std::cout << YELLOW << "Pushing 6, 17" << RESET << std::endl;
	mstack.push(6);
	mstack.push(17);
	std::cout << GREEN << "Top: " << RESET << mstack.top() << std::endl;

	std::cout << YELLOW << "Pop top element: " << RESET << std::endl;
	mstack.pop();

	std::cout << GREEN << "Size after pop: " << RESET << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Pushing 3, 5, 737, 0" << RESET << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << YELLOW << "Iterating through MutantStack:" << RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
        std::cout << GREEN << *it << RESET << std::endl;
		++it;
	}
	
	std::cout << std::endl;
    std::cout << YELLOW << "Constructing stack from MutantStack..." << RESET << std::endl;
    std::stack<int> s(mstack);
    std::cout << GREEN << "stack size: " << RESET << s.size() << std::endl;

	std::cout << std::endl;

	std::cout << YELLOW << "[List Test]" << RESET << std::endl;

	std::list<int> lst;
	std::cout << YELLOW << "Pushing 6j, 17" << RESET << std::endl;
    lst.push_back(6);
    lst.push_back(17);
	std::cout << GREEN << "Top: " << RESET << lst.back() << std::endl;

    lst.pop_back();
	std::cout << GREEN << "Size after pop: " << RESET << lst.size() << std::endl;

	std::cout << YELLOW << "Pushing 3, 5, 737, 0" << RESET << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it_lst = lst.begin();
    std::list<int>::iterator ite_lst = lst.end();
    ++it_lst;
    --it_lst;

    std::cout << YELLOW << "Iterating thorugh list:" << RESET << std::endl;
    while (it_lst != ite_lst)
    {
        std::cout << GREEN << *it_lst << RESET << std::endl;
        ++it_lst;
    }


	return 0;
}