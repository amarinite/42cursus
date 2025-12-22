#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	action;

	std::cout << CLEAR_SCREEN;
	while (true)
	{
		std::cout << "Choose an action: ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, action))
			break;

		if (action == "EXIT")
			break;

		phoneBook.phoneBookAction(action);
	}
	return (0);
}