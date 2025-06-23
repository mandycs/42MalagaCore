#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
    // Data members (must be non-empty as per requirements)
    int id;
    std::string name;
    double value;
    bool isValid;
    
    // Constructor
    Data();
    Data(int id, const std::string& name, double value, bool isValid = true);
    
    // Copy constructor and assignment operator
    Data(const Data& other);
    Data& operator=(const Data& other);
    
    // Destructor
    ~Data();
    
    // Utility methods
    void display() const;
    bool operator==(const Data& other) const;
};

#endif