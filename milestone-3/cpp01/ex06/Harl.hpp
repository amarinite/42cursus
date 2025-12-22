#pragma once

#include <iostream>

#define NC		"\e[0m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define CYAN	"\e[36m"

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		~Harl();
		void complain( std::string level );
};