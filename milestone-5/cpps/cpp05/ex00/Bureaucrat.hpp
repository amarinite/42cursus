#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		
		const std::string	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);
		void				incrementGrade(int increment);
		void				decrementGrade(int decrement);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);