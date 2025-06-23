#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testBasicInternFunctionality() {
    std::cout << "\n=== Testing Basic Intern Functionality ===" << std::endl;
    
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        std::cout << "\n--- Creating robotomy request form ---" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << "Form created successfully: " << *rrf << std::endl;
            delete rrf;
        } else {
            std::cout << "Form creation failed!" << std::endl;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testAllFormTypes() {
    std::cout << "\n=== Testing All Form Types ===" << std::endl;
    
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1); // Can sign and execute everything
        
        std::string formNames[] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"
        };
        
        std::string targets[] = {
            "garden",
            "Marvin",
            "Arthur Dent"
        };
        
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Creating and processing " << formNames[i] << " ---" << std::endl;
            
            AForm* form = intern.makeForm(formNames[i], targets[i]);
            
            if (form) {
                std::cout << "Form details: " << *form << std::endl;
                
                boss.signForm(*form);
                boss.executeForm(*form);
                
                delete form;
            }
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInvalidFormNames() {
    std::cout << "\n=== Testing Invalid Form Names ===" << std::endl;
    
    try {
        Intern intern;
        
        std::string invalidNames[] = {
            "coffee making",
            "lunch break",
            "vacation request", 
            "ROBOTOMY REQUEST", // Case sensitive
            "presidential_pardon", // Wrong format
            ""
        };
        
        for (int i = 0; i < 6; i++) {
            std::cout << "\n--- Attempting to create: '" << invalidNames[i] << "' ---" << std::endl;
            AForm* form = intern.makeForm(invalidNames[i], "target");
            
            if (form) {
                std::cout << "Unexpected success: " << *form << std::endl;
                delete form;
            } else {
                std::cout << "Form creation failed as expected." << std::endl;
            }
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testFormWorkflow() {
    std::cout << "\n=== Testing Complete Form Workflow ===" << std::endl;
    
    try {
        Intern intern;
        Bureaucrat employee("Employee", 50);
        Bureaucrat manager("Manager", 20);
        Bureaucrat ceo("CEO", 1);
        
        std::cout << "\n--- Employee tries to create and process forms ---" << std::endl;
        
        // Employee can only sign shrubbery forms
        AForm* shrub = intern.makeForm("shrubbery creation", "office_plants");
        if (shrub) {
            employee.signForm(*shrub);
            employee.executeForm(*shrub);
            delete shrub;
        }
        
        std::cout << "\n--- Manager tries robotomy ---" << std::endl;
        AForm* robot = intern.makeForm("robotomy request", "Old_Computer");
        if (robot) {
            manager.signForm(*robot);
            manager.executeForm(*robot); // Should fail - needs grade 45
            delete robot;
        }
        
        std::cout << "\n--- CEO handles presidential pardon ---" << std::endl;
        AForm* pardon = intern.makeForm("presidential pardon", "Rebel_Leader");
        if (pardon) {
            ceo.signForm(*pardon);
            ceo.executeForm(*pardon);
            delete pardon;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternCopyAndAssignment() {
    std::cout << "\n=== Testing Intern Copy and Assignment ===" << std::endl;
    
    try {
        Intern original;
        
        std::cout << "\n--- Testing copy constructor ---" << std::endl;
        Intern copy(original);
        
        std::cout << "\n--- Testing assignment operator ---" << std::endl;
        Intern assigned;
        assigned = original;
        
        std::cout << "\n--- Testing functionality of copied interns ---" << std::endl;
        AForm* form1 = copy.makeForm("shrubbery creation", "copy_test");
        AForm* form2 = assigned.makeForm("robotomy request", "assign_test");
        
        if (form1) {
            std::cout << "Copy created: " << *form1 << std::endl;
            delete form1;
        }
        
        if (form2) {
            std::cout << "Assigned created: " << *form2 << std::endl;
            delete form2;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testMemoryManagement() {
    std::cout << "\n=== Testing Memory Management ===" << std::endl;
    
    try {
        Intern intern;
        
        std::cout << "\n--- Creating multiple forms ---" << std::endl;
        AForm* forms[5];
        
        forms[0] = intern.makeForm("shrubbery creation", "test1");
        forms[1] = intern.makeForm("robotomy request", "test2");
        forms[2] = intern.makeForm("presidential pardon", "test3");
        forms[3] = intern.makeForm("shrubbery creation", "test4");
        forms[4] = intern.makeForm("invalid form", "test5"); // Should be NULL
        
        std::cout << "\n--- Processing valid forms ---" << std::endl;
        for (int i = 0; i < 5; i++) {
            if (forms[i]) {
                std::cout << "Form " << i << ": " << *forms[i] << std::endl;
            } else {
                std::cout << "Form " << i << ": NULL (creation failed)" << std::endl;
            }
        }
        
        std::cout << "\n--- Cleaning up ---" << std::endl;
        for (int i = 0; i < 5; i++) {
            if (forms[i]) {
                delete forms[i];
                forms[i] = NULL;
            }
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testCaseSensitivity() {
    std::cout << "\n=== Testing Case Sensitivity ===" << std::endl;
    
    try {
        Intern intern;
        
        std::string variations[] = {
            "shrubbery creation",      // Correct
            "Shrubbery Creation",      // Wrong case
            "SHRUBBERY CREATION",      // Wrong case
            "shrubbery Creation",      // Mixed case
            "robotomy request",        // Correct
            "Robotomy Request",        // Wrong case
            "presidential pardon",     // Correct
            "Presidential Pardon"      // Wrong case
        };
        
        for (int i = 0; i < 8; i++) {
            std::cout << "\n--- Testing: '" << variations[i] << "' ---" << std::endl;
            AForm* form = intern.makeForm(variations[i], "test");
            
            if (form) {
                std::cout << "SUCCESS: " << *form << std::endl;
                delete form;
            } else {
                std::cout << "FAILED: Form not created" << std::endl;
            }
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== INTERN FACTORY TESTING PROGRAM ===" << std::endl;
    
    testBasicInternFunctionality();
    testAllFormTypes();
    testInvalidFormNames();
    testFormWorkflow();
    testInternCopyAndAssignment();
    testMemoryManagement();
    testCaseSensitivity();
    
    std::cout << "\n=== END OF TESTS ===" << std::endl;
    std::cout << "\nCheck for generated *_shrubbery files in the directory!" << std::endl;
    
    return 0;
}