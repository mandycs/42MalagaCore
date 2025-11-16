#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
public:
    // Orthodox Canonical Form
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    
    // Factory method
    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    // Form creation methods
    AForm* createShrubberyCreationForm(const std::string& target);
    AForm* createRobotomyRequestForm(const std::string& target);
    AForm* createPresidentialPardonForm(const std::string& target);
    
    // Helper method to find form index
    int getFormIndex(const std::string& formName);
    
    // Static arrays for form names and creation functions
    static const std::string _formNames[3];
    typedef AForm* (Intern::*FormCreator)(const std::string&);
    static const FormCreator _formCreators[3];
};

#endif