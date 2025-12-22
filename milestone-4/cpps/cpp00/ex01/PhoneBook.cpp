#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: contactCount(0)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = NULL;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i])
			delete contacts[i];
	}
}

std::string	PhoneBook::formatColumn(const std::string& text) const
{
	if (text.length() > 10)
		return text.substr(0, 9) + ".";
	else
		return std::string(10 - text.length(), ' ') + text;
}

void	PhoneBook::displayTableHeader() const
{
	std::cout << std::string(LINE_WIDTH, '-') << std::endl;
	std::cout << formatColumn("Index") << "|"
		<< formatColumn("First Name") << "|"
		<< formatColumn("Last Name") << "|"
		<< formatColumn("Nickname") << std::endl;
	std::cout << std::string(LINE_WIDTH, '-') << std::endl;
}

std::string	PhoneBook::intToString(int value) const
{
	std::stringstream stringResult;;
	stringResult << value;
	return stringResult.str();
}

bool PhoneBook::isValidInteger(const std::string& str) const
{
	if (str.empty())
		return false;

	std::stringstream ss(str);
	int num;
	char c;

	if (!(ss >> num) || (ss >> c))
		return false;

	return true;
}

void	PhoneBook::addContact(const Contact& contact)
{
	int index = contactCount % MAX_CONTACTS;

	if (contacts[index])
		delete contacts[index];

	contacts[index] = new Contact(contact);
	contactCount++;
}

const Contact	*PhoneBook::getContact(int index) const
{
	if (contacts[index] && index >= 0 && index < contactCount)
		return contacts[index];
	else
	{
		std::cerr << "Invalid contact index" << std::endl;
		return NULL;
	}
}

void	PhoneBook::displayContactRow(int index) const
{
	if (contacts[index])
	{
		std::cout << formatColumn(intToString(contacts[index]->getIndex() + 1)) << "|"
			<< formatColumn(contacts[index]->getFirstName()) << "|"
			<< formatColumn(contacts[index]->getLastName()) << "|"
			<< formatColumn(contacts[index]->getNickname()) << std::endl;
	}
}

void	PhoneBook::displayContacts() const
{
	std::cout << CLEAR_SCREEN;
	displayTableHeader();

	for (int i = 0; i < MAX_CONTACTS; i++)
		displayContactRow(i);

	std::cout << std::string(LINE_WIDTH, '-') << std::endl;
}

void	PhoneBook::displayContacts(int index) const
{
	if (contacts[index] && index >= 0 && index < MAX_CONTACTS)
	{
		std::cout << CLEAR_SCREEN;
		displayTableHeader();
		displayContactRow(index);
		std::cout << std::string(LINE_WIDTH, '-') << std::endl;
	}
	else
	{
		std::cout << CLEAR_SCREEN;
		std::cout << "Invalid index or contact not found." << std::endl;	
	}
}

std::string	PhoneBook::getValidatedInput(const std::string& prompt)
{
	std::string input;
	std::cout << prompt;
	if (!(std::getline(std::cin, input)) || input.empty())
	{
		std::cout << "Fields cannot be empty" << std::endl;
		return "";
	}
	return input;
}

void	PhoneBook::searchContact() const
{
	displayContacts();

	std::string input;
	std::cout << "Enter contact index to display: ";
	std::getline(std::cin, input);

	if (!isValidInteger(input))
	{
		std::cout << CLEAR_SCREEN;
		std::cout << "Invalid input. Please enter a valid number." << std::endl;
		return;
	}

	std::stringstream ss(input);
	int index;
	ss >> index;

	index = index - 1;

	if (index < 0 || index >= MAX_CONTACTS)
	{
		std::cout << CLEAR_SCREEN;
		std::cout << "Index out of range. Please enter a number between 1 and " 
			<< MAX_CONTACTS << "." << std::endl;
		return;
	}

	displayContacts(index);
}

void	PhoneBook::phoneBookAction(std::string action)
{
	std::cout << CLEAR_SCREEN;
	if (action == "ADD")
	{
		Contact newContact;

		std::string firstName, lastName, nickname, phoneNumber, darkSecret;

		firstName = getValidatedInput("Enter first name: ");
		if (firstName.empty())
			return;

		lastName = getValidatedInput("Enter last name: ");
		if (lastName.empty())
			return;

		nickname = getValidatedInput("Enter nickname: ");
		if (nickname.empty())
			return;

		phoneNumber = getValidatedInput("Enter phone number: ");
		if (phoneNumber.empty())
			return;

		darkSecret = getValidatedInput("Enter dark secret: ");
		if (darkSecret.empty())
			return;

		newContact.setContact(contactCount % MAX_CONTACTS, firstName, lastName, nickname, phoneNumber, darkSecret);
		addContact(newContact);
		std::cout << CLEAR_SCREEN;
	}
	else if (action == "SEARCH")
	{
		if (contactCount == 0)
			std::cout << "No contacts available. Please add a contact first." << std::endl;
		else
			searchContact();
	}
}
