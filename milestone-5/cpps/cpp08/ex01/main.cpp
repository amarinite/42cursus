#include "Span.hpp"
#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << YELLOW << "Current span: " << RESET << sp << std::endl;
	std::cout << YELLOW << "Current capacity: " << RESET << sp.getMaxCapacity() << std::endl;

	std::cout << std::endl;

	try
	{
		std::cout << YELLOW << "Trying to add one extra number..." << RESET << std::endl;
		sp.addNumber(999);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Could not add number: " << e.what() << RESET << std::endl;
	}
	
	std::cout << std::endl;

	std::cout << GREEN << "shortestSpan = " << RESET << sp.shortestSpan() << std::endl;
	std::cout << GREEN << "longestSpan = " << RESET << sp.longestSpan() << std::endl;

	std::cout << std::endl << YELLOW << "Testing addNumberRange..." << RESET << std::endl;

	Span spRange(10);
	std::vector<int> rangeOk;
	rangeOk.push_back(1);
	rangeOk.push_back(4);
	rangeOk.push_back(7);
	rangeOk.push_back(10);


	std::cout << YELLOW << "Adding valid range: " << RESET << std::endl;
	spRange.addNumberRange(rangeOk);
	std::cout << GREEN << "Range added. spRange: " << RESET << spRange << std::endl;
	std::cout << GREEN << "shortestSpan = " << RESET << spRange.shortestSpan() << std::endl;
	std::cout << GREEN << "longestSpan = " << RESET << spRange.longestSpan() << std::endl;

	std::vector<int> rangeTooBig;
	rangeTooBig.push_back(1);
	rangeTooBig.push_back(2);
	rangeTooBig.push_back(3);
	rangeTooBig.push_back(4);
	rangeTooBig.push_back(5);
	rangeTooBig.push_back(6);
	rangeTooBig.push_back(7);

	try
	{
		std::cout << YELLOW << "Trying to add oversized range..." << RESET << std::endl;
		spRange.addNumberRange(rangeTooBig);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Could not add range of numbers: " << e.what() << RESET << std::endl;
	}

	return 0;
}