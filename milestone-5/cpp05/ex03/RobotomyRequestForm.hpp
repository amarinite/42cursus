#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

#define ROBOT_SUCCESS \
"     \\_\\\n" \
"   (_**)\n" \
"  __) #_\n" \
" ( )...()\n" \
" || | |I|\n" \
" || | |()__/\n" \
" /\\(___)\n" \
"_-\"\"\"\"\"\"\"-_\"\"-_\n" \
"-,,,,,,,,- ,,\n" \
"✅✅✅✅✅✅\n"

#define ROBOT_FAILURE \
"     \\_\\\n" \
"   (_**)\n" \
"  __) #_\n" \
" ( )...()\n" \
" || | |I|\n" \
" || | |()__/\n" \
" /\\(___)\n" \
"_-\"\"\"\"\"\"\"-_\"\"-_\n" \
"-,,,,,,,,- ,,\n" \
"❌❌❌❌❌❌\n"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

		void executeAction() const;
	
	public:
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		
};