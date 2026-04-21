#pragma once
#include "AForm.hpp"
#include <fstream>

#define TREE \
"                                   # #### ####\n" \
"                                ### \\/#|### |/####\n" \
"                               ##\\/#/ \\||/##/_/##/_#\n" \
"                             ###  \\/###|/ \\/ # ###\n" \
"                           ##_\\_#\\_\\## | #/###_/_####\n" \
"                          ## #### # \\ #| /  #### ##/##\n" \
"                           __#_--###`  |{,###---###-~\n" \
"                                     \\ }{\n" \
"                                      }}{\n" \
"                                      }}{\n" \
"                                      {{}}\n" \
"                                , -=-~{ .-^- _\n" \
"                                      `}\n" \
"                                       {\n"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

		void executeAction() const;

	public:
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		class FileOpenException: public std::runtime_error
		{
			public:
				FileOpenException(const std::string &msg);
		};
};