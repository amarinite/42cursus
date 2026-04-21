#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Form constructor called for " << getName() <<
	" with sign grade of " << getSignGrade() << 
	" and execution grade of " << getExecGrade() << std::endl;
}


Form::Form(const std::string &name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException("Sign grade is too high");
	if (signGrade > 150)
		throw GradeTooLowException("Sign grade is too low");
	if (execGrade < 1)
		throw GradeTooHighException("Execution grade is too high");
	if (execGrade > 150)
		throw GradeTooLowException("Execution grade is too low");
	std::cout << "Form constructor called for " << getName() <<
	" with sign grade of " << getSignGrade() << 
	" and execution grade of " << getExecGrade() << std::endl;
}

Form::~Form()
{
	std::cout << "Form default destructor called"  << std::endl;
}

Form::Form(const Form &other): _name(other.getName()),
	_signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	_isSigned = other.getIsSigned();
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &obj)
{
	std::cout << "Form copy assignment called" << std::endl;
	if (this == &obj)
		return *this;
	_isSigned = obj.getIsSigned();
	return *this;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(Bureaucrat &bur)
{
	if (_isSigned)
		throw IsSignedException("Form is already signed");
	if (bur.getGrade() > _signGrade)
		throw GradeTooLowException("Bureaucrat " + bur.getName() + "\'s grade is too low to sign form " + _name);
	_isSigned = true;
}

Form::GradeTooLowException::GradeTooLowException(const std::string &msg) : std::range_error(msg)
{
}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg) : std::range_error(msg)
{
}

Form::IsSignedException::IsSignedException(const std::string &msg) : std::logic_error(msg)
{
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", form with sign grade of " << form.getSignGrade() << 
	" and execution grade of " << std::endl;
	return (os);
}
