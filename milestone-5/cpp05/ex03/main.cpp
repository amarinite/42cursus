#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	
	if (rrf)
	{
		try
		{
			Bureaucrat lili("Lili", 20);
			lili.signForm(*rrf);
			lili.executeForm(*rrf);

		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	delete rrf;
}