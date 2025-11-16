
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
    
    static const int GRADE_TO_SIGN = 72;
    static const int GRADE_TO_EXECUTE = 45;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();
    
    // Getter
    const std::string& getTarget() const;
    
    // Implementation of pure virtual function
    virtual void execute(const Bureaucrat& executor) const;

private:
    void performRobotomy() const;
};

#endif