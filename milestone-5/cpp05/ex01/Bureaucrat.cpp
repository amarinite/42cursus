#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat constructor called for " << getName() <<
	" with grade of " << getGrade() << std::endl;
}


Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException("Grade is too high");
	if (grade > 150)
		throw GradeTooLowException("Grade is too low");
	std::cout << "Bureaucrat constructor called for " << getName() <<
	" with grade of " << getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called"  << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment called" << std::endl;
	if  (this == &other)
		return *this;
	this->_grade = other.getGrade();
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException("Grade is too high");
	if (grade > 150)
		throw GradeTooLowException("Grade is too low");
	_grade = grade;
}

void Bureaucrat::incrementGrade(int increment)
{
	setGrade(_grade - increment);
}

void Bureaucrat::decrementGrade(int decrement)
{
	setGrade(_grade + decrement);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) : std::range_error(msg)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) : std::range_error(msg)
{
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << _name << " couldn't sign " << form.getName() 
			<< " because: " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}
