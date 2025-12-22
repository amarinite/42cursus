#include <iostream>

int	main(void)
{
	std::string	stringy("HI THIS IS BRAIN");
	std::string	*stringPTR = &stringy;
	std::string	&stringREF = stringy;

	std::cout << &stringy << '\n';
	std::cout << stringPTR << '\n';
	std::cout << &stringREF << '\n'; 

	std::cout << stringy << '\n';
	std::cout << *stringPTR << '\n';
	std::cout << stringREF << '\n'; 

	return 0;
}