#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration to avoid circular dependency
class Bureaucrat;

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    
    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    // Form signing
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
private:
    void validateGrade(int grade);
};

// Overload insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif