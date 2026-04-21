#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

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
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);

		class GradeTooHighException : public std::range_error
		{
			public:
				GradeTooHighException(const std::string &msg);
		};

		class GradeTooLowException : public std::range_error
		{
			public:
				GradeTooLowException(const std::string &msg);
		};
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);