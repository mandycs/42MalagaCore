
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form implementations

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", GRADE_TO_SIGN, GRADE_TO_EXECUTE), _target(target) {
    std::cout << "RobotomyRequestForm constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Getter

const std::string& RobotomyRequestForm::getTarget() const {
    return _target;
}

// Execute implementation

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecutionRequirements(executor);
    performRobotomy();
    std::cout << executor.getName() << " executed " << getName() 
              << " on target: " << _target << std::endl;
}

// Private method to perform robotomy

void RobotomyRequestForm::performRobotomy() const {
    std::cout << "BZZZZT! WHIRRR! CLANK! DRILLING NOISES!" << std::endl;
    std::cout << "🤖 Attempting robotomization of " << _target << "..." << std::endl;
    
    // Seed random number generator (should be done once, but this is simple)
    std::srand(std::time(NULL));
    
    // 50% chance of success
    if (std::rand() % 2) {
        std::cout << "SUCCESS! " << _target << " has been robotomized successfully! 🎉" << std::endl;
        std::cout << _target << " is now 100% compatible with galactic standards." << std::endl;
    } else {
        std::cout << "FAILURE! Robotomy of " << _target << " failed! 💥" << std::endl;
        std::cout << _target << " remains stubbornly biological." << std::endl;
    }
}