#pragma once
#include <iostream>

class Brain 
{
	public:
		Brain();
		~Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);

		std::string	ideas[100];
};