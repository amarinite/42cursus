#include "Bureaucrat.hpp"

int main()
{
	/*
	// INVALID CONSTRUCTION PARAMETERS
	try
	{
		std::cout << YELLOW << "Testing an invalid form in construction" << RESET << std::endl;
		Bureaucrat juan("Juan", 13);
		Form wrongform("bug", 156, 12);
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	// SIGN GRADE ABOVE BUREAUCRAT'S GRADE
*/
{
	std::cout << YELLOW << "\nTesting a sign grade above bureaucrat's grade" << RESET << std::endl;
	Bureaucrat sofia("Sofia", 140);
	Form highLevel("Top Secret", 3, 2);
	sofia.signForm(highLevel);
}
	
	// SUCCESSFUL FORM
	try
	{
		std::cout << YELLOW << "\nTesting a successful form" << RESET << std::endl;
		Bureaucrat lili("Lili", 20);
		Form commonForm("Paperwork", 144, 120);
		lili.signForm(commonForm);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
}