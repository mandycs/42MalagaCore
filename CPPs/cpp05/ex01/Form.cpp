#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form implementations

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Form parameterized constructor called" << std::endl;
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other) {
        // Note: _name, _gradeToSign, _gradeToExecute are const, so we can't assign them
        // We can only assign the signing status
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called for " << _name << std::endl;
}

// Getters

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Form signing method

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// Private validation method

void Form::validateGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

// Exception implementations

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! Must be between 1 and 150.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! Must be between 1 and 150.";
}

// Overloaded insertion operator

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form '" << form.getName() << "', signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign() 
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}