#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration to avoid circular dependency
class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm(); // Virtual destructor for inheritance
    
    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    // Form signing
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Pure virtual function - makes this class abstract
    virtual void execute(const Bureaucrat& executor) const = 0;
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
protected:
    void validateGrade(int grade);
    void checkExecutionRequirements(const Bureaucrat& executor) const;
};

// Overload insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif