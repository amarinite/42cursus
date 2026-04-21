#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment called" << std::endl;
	if  (this == &other)
		return *this;
	return *this;
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *(Intern::*formCreators[3])(const std::string &) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	std::string formOptions[3] = {
		"shrubbery creation", 
		"robotomy request", 
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formOptions[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	
	std::cout << formName << " is not a valid form name for Intern" << std::endl;
	return NULL;
}