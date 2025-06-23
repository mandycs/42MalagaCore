#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;
    
    static const int GRADE_TO_SIGN = 25;
    static const int GRADE_TO_EXECUTE = 5;

public:
    // Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();
    
    // Getter
    const std::string& getTarget() const;
    
    // Implementation of pure virtual function
    virtual void execute(const Bureaucrat& executor) const;

private:
    void grantPardon() const;
};

#endif