#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Orthodox Canonical Form implementations

Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    validateGrade(grade);
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        // Note: _name is const, so we can't assign it
        // We can only assign the grade
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called for " << _name << std::endl;
}

// Getters

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Grade modification methods

void Bureaucrat::incrementGrade() {
    validateGrade(_grade - 1); // Remember: lower number = higher grade
    _grade--;
}

void Bureaucrat::decrementGrade() {
    validateGrade(_grade + 1); // Higher number = lower grade
    _grade++;
}

// Form signing and execution methods

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// Private validation method

void Bureaucrat::validateGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

// Exception implementations

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! Must be between 1 and 150.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! Must be between 1 and 150.";
}

// Overloaded insertion operator

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}