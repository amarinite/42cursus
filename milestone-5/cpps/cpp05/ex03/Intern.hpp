#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		AForm *createShrubbery(const std::string &target);
		AForm *createRobotomy(const std::string &target);
		AForm *createPardon(const std::string &target);

	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		AForm	*makeForm(std::string formName, std::string target);

};