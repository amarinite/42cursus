#pragma once

# include <iostream>
# include <sstream>
# include "Contact.hpp"
# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10
# define NUM_COLUMNS 4
# define NUM_SEPARATORS 3
# define LINE_WIDTH ((COLUMN_WIDTH * NUM_COLUMNS) + NUM_SEPARATORS)
# define CLEAR_SCREEN "\033[2J\033[1;1H"

class	PhoneBook
{
	private:
		Contact		*contacts[MAX_CONTACTS];
		int			contactCount; 

		std::string	formatColumn(const std::string& text) const;
		void		displayTableHeader() const;
		void		displayContactRow(int index) const;
		std::string	intToString(int value) const;
		bool		isValidInteger(const std::string& str) const;
		const		Contact* getContact(int index) const;
		void		displayContacts() const;
		void		displayContacts(int index) const;
		std::string	getValidatedInput(const std::string& prompt);

	public:
		PhoneBook();
		~PhoneBook();

		void	phoneBookAction(std::string action);
		void	addContact(const Contact& contact);
		void	searchContact() const;

};