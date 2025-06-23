#include "Data.hpp"

// Constructors
Data::Data() : id(0), name("default"), value(0.0), isValid(false) {
    std::cout << "Data default constructor called" << std::endl;
}

Data::Data(int id, const std::string& name, double value, bool isValid) 
    : id(id), name(name), value(value), isValid(isValid) {
    std::cout << "Data parameterized constructor called for id: " << id << std::endl;
}

Data::Data(const Data& other) 
    : id(other.id), name(other.name), value(other.value), isValid(other.isValid) {
    std::cout << "Data copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& other) {
    std::cout << "Data assignment operator called" << std::endl;
    if (this != &other) {
        id = other.id;
        name = other.name;
        value = other.value;
        isValid = other.isValid;
    }
    return *this;
}

Data::~Data() {
    std::cout << "Data destructor called for id: " << id << std::endl;
}

// Utility methods
void Data::display() const {
    std::cout << "Data { id: " << id 
              << ", name: \"" << name 
              << "\", value: " << value 
              << ", isValid: " << (isValid ? "true" : "false") 
              << " }" << std::endl;
}

bool Data::operator==(const Data& other) const {
    return (id == other.id && 
            name == other.name && 
            value == other.value && 
            isValid == other.isValid);
}