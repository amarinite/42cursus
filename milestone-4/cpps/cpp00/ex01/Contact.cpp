#include "Contact.hpp"

Contact::Contact()
	: index(0), firstName(""), lastName(""), 
		nickname(""), phoneNumber(""), darkSecret("")
{
}

Contact::~Contact()
{
}

int	Contact::getIndex() const
{
	return index;
}

std::string	Contact::getFirstName() const
{
	return firstName;
}

std::string	Contact::getLastName() const
{
	return lastName;
}

std::string	Contact::getNickname() const
{
	return nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string	Contact::getDarkSecret() const
{
	return darkSecret;
}

void	Contact::setContact(int idx, const std::string& first, const std::string& last,
	const std::string& nick, const std::string& phone, const std::string& secret)
{
	index = idx;
	firstName = first;
	lastName = last;
	nickname = nick;
	phoneNumber = phone;
	darkSecret = secret;
}