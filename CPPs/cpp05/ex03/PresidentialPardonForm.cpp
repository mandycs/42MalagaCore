#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form implementations

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target(target) {
    std::cout << "PresidentialPardonForm constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Getter

const std::string& PresidentialPardonForm::getTarget() const {
    return _target;
}

// Execute implementation

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    checkExecutionRequirements(executor);
    grantPardon();
    std::cout << executor.getName() << " executed " << getName() 
              << " on target: " << _target << std::endl;
}

// Private method to grant pardon

void PresidentialPardonForm::grantPardon() const {
    std::cout << "🏛️  OFFICIAL PRESIDENTIAL DECREE 🏛️" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
    std::cout << "By the power vested in me by the Galactic Constitution," << std::endl;
    std::cout << "and in accordance with the Universal Declaration of" << std::endl;
    std::cout << "Improbable Events, I, Zaphod Beeblebrox, President of" << std::endl;
    std::cout << "the Galaxy, do hereby grant a full and unconditional" << std::endl;
    std::cout << "pardon to:" << std::endl;
    std::cout << std::endl;
    std::cout << "           🌟 " << _target << " 🌟" << std::endl;
    std::cout << std::endl;
    std::cout << "This pardon absolves the recipient of all past, present," << std::endl;
    std::cout << "and future crimes against the Galaxy, including but not" << std::endl;
    std::cout << "limited to: improper use of towels, failure to panic" << std::endl;
    std::cout << "adequately, and possession of illegal probability" << std::endl;
    std::cout << "factors." << std::endl;
    std::cout << std::endl;
    std::cout << "Signed with my second-best pen," << std::endl;
    std::cout << "Zaphod Beeblebrox 🎭" << std::endl;
    std::cout << "President of the Galaxy" << std::endl;
    std::cout << "========================================" << std::endl;
}