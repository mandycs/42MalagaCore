#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Static member initialization
const std::string Intern::_formNames[3] = {
    "shrubbery creation",
    "robotomy request", 
    "presidential pardon"
};

const Intern::FormCreator Intern::_formCreators[3] = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

// Orthodox Canonical Form implementations

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other; // Suppress unused parameter warning
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern assignment operator called" << std::endl;
    (void)other; // Suppress unused parameter warning
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

// Factory method implementation

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    int formIndex = getFormIndex(formName);
    
    if (formIndex == -1) {
        std::cout << "Error: Unknown form name '" << formName << "'. ";
        std::cout << "Available forms are: ";
        for (int i = 0; i < 3; i++) {
            std::cout << "'" << _formNames[i] << "'";
            if (i < 2) std::cout << ", ";
        }
        std::cout << "." << std::endl;
        return NULL;
    }
    
    // Use function pointer to create the appropriate form
    AForm* form = (this->*_formCreators[formIndex])(target);
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

// Private helper methods

int Intern::getFormIndex(const std::string& formName) {
    for (int i = 0; i < 3; i++) {
        if (formName == _formNames[i]) {
            return i;
        }
    }
    return -1; // Form not found
}

// Form creation methods

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}