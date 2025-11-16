#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form implementations

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "AForm parameterized constructor called for " << name << std::endl;
    validateGrade(gradeToSign);
    validateGrade(gradeToExecute);
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        // Note: _name, _gradeToSign, _gradeToExecute are const, so we can't assign them
        // We can only assign the signing status
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called for " << _name << std::endl;
}

// Getters

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Form signing method

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// Protected methods for derived classes

void AForm::validateGrade(int grade) {
    if (grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
}

void AForm::checkExecutionRequirements(const Bureaucrat& executor) const {
    if (!_isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
}

// Exception implementations

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high! Must be between 1 and 150.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low! Must be between 1 and 150.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed! Cannot execute unsigned form.";
}

// Overloaded insertion operator

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm '" << form.getName() << "', signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign() 
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}