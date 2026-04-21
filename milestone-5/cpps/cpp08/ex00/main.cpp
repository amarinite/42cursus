#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

template <typename T>
void	printContainer(T &cont)
{
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void runEasyfindTest(T &cont, int value, const char *label)
{
	std::cout << label << " (searching for " << value << "):" << std::endl;
	try
	{
		typename T::const_iterator it = easyfind(cont, value);
		std::cout << GREEN << "Found: " << *it << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);

	std::list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	std::cout << YELLOW << "Vector elements:" << RESET << std::endl;
	printContainer(vec);
	runEasyfindTest(vec, 8, "easyfind vector");
	runEasyfindTest(vec, 1, "easyfind vector");

	std::cout << std::endl;

	std::cout << YELLOW << "List elements:" << RESET << std::endl;
	printContainer(li);
	runEasyfindTest(li, 2, "easyfind list");
	runEasyfindTest(li, 8, "easyfind list");

	return 0;
}