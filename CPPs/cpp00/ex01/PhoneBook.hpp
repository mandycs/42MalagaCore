#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int oldestIndex;

	std::string truncateField(const std::string &field) const;

public:
	PhoneBook();

	~PhoneBook();

	void addContact(const Contact &newContact);

	void displayContacts() const;

	void searchContact(int index) const;
};

#endif
