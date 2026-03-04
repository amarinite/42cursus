#pragma once
#include "AForm.hpp"

#define PRESIDENT \
"              n__n_\n" \
"             /  = =\\\n" \
"            /   ._Y_)\n" \
"___________/      \"\\____________________________\n" \
"          (_/  (_,  \\                        \n" \
"            \\      ( \\_,--\"\"\"\"--.              \n" \
"      __..-,-`.___,-` )-.______.' \n" \
"    <'     `-,'   `-, )-'    >\n" \
"     `----._/      ( /\"`>.--\"\n" \
"            \"--..___,--\"\n"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		
		void executeAction() const;
	
	public:
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

};
