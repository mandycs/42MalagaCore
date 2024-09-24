#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            Contact newContact;
            std::string input;

            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            newContact.setFirstName(input);

            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            newContact.setLastName(input);

            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            newContact.setNickname(input);

            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            newContact.setPhoneNumber(input);

            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);

            phonebook.addContact(newContact);

        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            std::cout << "Enter the index of the contact to display: ";
            int index;
            std::cin >> index;
            std::cin.ignore();  // Ignorar el salto de línea
            phonebook.searchContact(index);

        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
