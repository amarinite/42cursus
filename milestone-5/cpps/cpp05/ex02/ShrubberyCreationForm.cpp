#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for target " << _target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
	std::fstream fd;
	std::string name;

	name = _target + "_shrubbery";
	fd.open(name.c_str(), std::fstream::out);
	if (!fd.is_open())
		throw FileOpenException("Failed to create file: " + name);
	fd << TREE << std::endl;
	fd.close();
}

ShrubberyCreationForm::FileOpenException::FileOpenException(const std::string &msg) : std::runtime_error(msg)
{
}