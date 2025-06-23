#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;
    
    static const int HIGHEST_GRADE = 1;
    static const int LOWEST_GRADE = 150;

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    
    // Getters
    const std::string& getName() const;
    int getGrade() const;
    
    // Grade modification
    void incrementGrade();
    void decrementGrade();
    
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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif