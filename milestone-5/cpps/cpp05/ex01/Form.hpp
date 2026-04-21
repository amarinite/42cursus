#pragma once
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		Form(const std::string &name, int signGrade, int execGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat &bur);

		class GradeTooLowException: public std::range_error
		{
			public:
				GradeTooLowException(const std::string &msg);
		};
		class GradeTooHighException: public std::range_error
		{
			public:
				GradeTooHighException(const std::string &msg);
		};
		class IsSignedException: public std::logic_error
		{
			public:
				IsSignedException(const std::string &msg);
		};
};
std::ostream& operator<<(std::ostream& os, const Form& form);