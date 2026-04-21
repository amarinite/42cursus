#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Form constructor called for " << getName() <<
	" with sign grade of " << getSignGrade() << 
	" and execution grade of " << getExecGrade() << std::endl;
}


AForm::AForm(const std::string &name, int signGrade, int execGrade)
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

AForm::~AForm()
{
	std::cout << "Form default destructor called"  << std::endl;
}

AForm::AForm(const AForm &other): _name(other.getName()),
	_signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	_isSigned = other.getIsSigned();
	std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &obj)
{
	std::cout << "Form copy assignment called" << std::endl;
	if (this == &obj)
		return *this;
	_isSigned = obj.getIsSigned();
	return *this;
}


const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (_isSigned)
		throw IsSignedException("Form is already signed");
	if (bur.getGrade() > _signGrade)
		throw GradeTooLowException("Bureaucrat " + bur.getName() + "\'s grade is too low to sign form " + _name);
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw IsSignedException("Form is not signed");
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException("Bureaucrat's grade is too low to execute form");
	
	executeAction();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &msg) : std::range_error(msg)
{
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &msg) : std::range_error(msg)
{
}

AForm::IsSignedException::IsSignedException(const std::string &msg) : std::logic_error(msg)
{
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ", form with sign grade of " << form.getSignGrade() << 
	" and execution grade of " << form.getExecGrade() << std::endl;
	return (os);
}
