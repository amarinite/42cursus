#include "Bureaucrat.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main()
{
	// INVALID CONSTRUCTION PARAMETERS
	try
	{
		std::cout << YELLOW << "Testing an invalid grade in construction (above 1)" << RESET << std::endl;
		Bureaucrat tooHigh("NoName", -2);
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << YELLOW << "Testing an invalid grade in construction (under 150)" << RESET << std::endl;
		Bureaucrat tooLow("NoName", 225);
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// VALID CONSTRUCTION PARAMETERS
	try
	{
		std::cout << YELLOW << "\nTesting valid bureaucrat" << RESET << std::endl;
		Bureaucrat valid("Helga", 50);
		std::cout << GREEN << valid << RESET;

		valid.decrementGrade(3);
		std::cout << GREEN << valid << RESET;
		valid.incrementGrade(20);
		std::cout << GREEN << valid << RESET;
	}
	catch(const std::exception& e)
	{
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// INVALID DECREMENT
		try
	{
		std::cout << YELLOW << "\nTesting decreasing too much" << RESET << std::endl;
		Bureaucrat dec("Mari", 147);
		std::cout << GREEN << dec << RESET;

		dec.decrementGrade(15);
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	// INVALID INCREMENT
		try
	{
		std::cout << YELLOW << "\nTesting increasing too much" << RESET << std::endl;
		Bureaucrat inc("Isa", 2);
		std::cout << GREEN << inc << RESET;

		inc.incrementGrade(24);
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}