#pragma once

# include <string>

class	Contact
{
	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkSecret;

	public:
		Contact();
		~Contact();
		
		int			getIndex() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkSecret() const;

		void setContact(int idx, const std::string& first, const std::string& last,
			const std::string& nick, const std::string& phone, const std::string& secret);
};