#include "PhoneBook.hpp"
#include <iomanip> // Para std::setw y std::right
#include <iostream>

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(const Contact &newContact)
{
	if (this->contactCount < 8)
	{
		this->contacts[this->contactCount] = newContact;
		this->contactCount++;
	}
	else
	{
		this->contacts[this->oldestIndex] = newContact;
		this->oldestIndex = (this->oldestIndex + 1) % 8;
	}
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < this->contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|" << std::setw(10) << truncateField(this->contacts[i].getFirstName()) << "|" << std::setw(10) << truncateField(this->contacts[i].getLastName()) << "|" << std::setw(10) << truncateField(this->contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::searchContact(int index) const
{
	if (index < 0 || index >= this->contactCount)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}

	const Contact &contact = this->contacts[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateField(const std::string &field) const
{
	if (field.length() > 10)
	{
		return (field.substr(0, 9) + ".");
	}
	return (field);
}
