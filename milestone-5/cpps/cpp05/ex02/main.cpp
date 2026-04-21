#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat juan("Juan", 140);
	ShrubberyCreationForm eliteTree("Elite Tree");
	RobotomyRequestForm eliteRobot("Elite Robot");
	PresidentialPardonForm eliteBeaver("Elite Beaver");

	// EXECUTING FORM WITHOUT SIGNING
	std::cout << YELLOW << "\nTesting executing without signing the form" << RESET << std::endl;
	juan.executeForm(eliteTree);
	juan.executeForm(eliteRobot);
	juan.executeForm(eliteBeaver);

	// EXECUTE GRADE ABOVE BUREAUCRAT'S GRADE

	std::cout << YELLOW << "\nTesting an execution level above bureaucrat's level" << RESET << std::endl;
	juan.signForm(eliteTree);
	juan.executeForm(eliteTree);

	juan.setGrade(60);
	juan.signForm(eliteRobot);
	juan.executeForm(eliteRobot);

	juan.setGrade(10);
	juan.signForm(eliteBeaver);
	juan.executeForm(eliteBeaver);

	std::cout << YELLOW << "\nTesting signing a form again" << RESET << std::endl;
	juan.signForm(eliteBeaver);

	// SUCCESSFUL FORM
	try
	{
		std::cout << YELLOW << "\nTesting a successful form: Shrubbery Creation" << RESET << std::endl;
		Bureaucrat lili("Lili", 80);
		ShrubberyCreationForm goodTree("Treetus");
		lili.signForm(goodTree);
		lili.executeForm(goodTree);

		std::cout << YELLOW << "\nTesting a successful form: Robotomy Request" << RESET << std::endl;
		lili.setGrade(30);
		RobotomyRequestForm clanker("Clanker");
		lili.signForm(clanker);
		lili.executeForm(clanker);

		std::cout << YELLOW << "\nTesting a successful form: Presidential Pardon" << RESET << std::endl;
		lili.setGrade(2);
		PresidentialPardonForm beaver("Beaver");
		lili.signForm(beaver);
		lili.executeForm(beaver);
		
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << GREEN << "We don't reach here" << RESET << std::endl;
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
	
}