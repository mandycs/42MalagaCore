#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form implementations

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Getter

const std::string& ShrubberyCreationForm::getTarget() const {
    return _target;
}

// Execute implementation

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecutionRequirements(executor);
    createShrubberyFile();
    std::cout << executor.getName() << " executed " << getName() 
              << " on target: " << _target << std::endl;
}

// Private method to create the file

void ShrubberyCreationForm::createShrubberyFile() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cout << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file << std::endl;
    file << "      /~\\" << std::endl;
    file << "     (   )" << std::endl;
    file << "    ( o o )" << std::endl;
    file << "     > ^ <" << std::endl;
    file << "    /     \\" << std::endl;
    file << "   /       \\" << std::endl;
    file << "  /         \\" << std::endl;
    file << " /___________ \\" << std::endl;
    file << "      | |" << std::endl;
    file << "      | |" << std::endl;
    file << "      |_|" << std::endl;
    file << std::endl;
    file << "    ^  ^  ^  ^  ^  ^" << std::endl;
    file << "   /|\\/|\\/|\\/|\\/|\\/|\\" << std::endl;
    file << "  /                 \\" << std::endl;
    file << " /    ASCII Trees    \\" << std::endl;
    file << "/                     \\" << std::endl;
    file << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    
    file.close();
    std::cout << "Shrubbery file created: " << filename << std::endl;
}