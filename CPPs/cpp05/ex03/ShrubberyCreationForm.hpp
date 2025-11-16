#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
    
    static const int GRADE_TO_SIGN = 145;
    static const int GRADE_TO_EXECUTE = 137;

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();
    
    // Getter
    const std::string& getTarget() const;
    
    // Implementation of pure virtual function
    virtual void execute(const Bureaucrat& executor) const;

private:
    void createShrubberyFile() const;
};

#endif