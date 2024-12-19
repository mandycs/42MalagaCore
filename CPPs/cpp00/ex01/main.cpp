#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);

        if (command == "ADD") {
            Contact newContact;
            std::string input;

            try {
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
            } catch (const std::invalid_argument &e) {
                std::cout << e.what() << "\n";
            }

        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            std::cout << "Enter the index of the contact to display: ";
            int index;
            if (!(std::cin >> index)) {
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            phonebook.searchContact(index);

        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
