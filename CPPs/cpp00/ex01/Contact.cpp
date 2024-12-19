#include "Contact.hpp"
#include <cctype> // Para std::isspace
#include <stdexcept> // Para std::invalid_argument

Contact::Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}

Contact::~Contact() {}

// Validación de campos vacíos
bool Contact::isNotEmpty(const std::string &input) const {
    for (std::string::size_type i = 0; i < input.length(); ++i) {
        if (!std::isspace(input[i])) {
            return true; // Hay al menos un carácter que no es espacio
        }
    }
    return false; // Solo contiene espacios o está vacío
}

// Setters con validación
void Contact::setFirstName(const std::string &firstName) {
    if (!isNotEmpty(firstName)) {
        throw std::invalid_argument("First name cannot be empty.");
    }
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    if (!isNotEmpty(lastName)) {
        throw std::invalid_argument("Last name cannot be empty.");
    }
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    if (!isNotEmpty(nickname)) {
        throw std::invalid_argument("Nickname cannot be empty.");
    }
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    if (!isNotEmpty(phoneNumber)) {
        throw std::invalid_argument("Phone number cannot be empty.");
    }
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    if (!isNotEmpty(darkestSecret)) {
        throw std::invalid_argument("Darkest secret cannot be empty.");
    }
    this->darkestSecret = darkestSecret;
}

// Getters
std::string Contact::getFirstName() const {
    return this->firstName;
}

std::string Contact::getLastName() const {
    return this->lastName;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestSecret;
}
