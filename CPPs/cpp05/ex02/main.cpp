#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

// Helper function for C++98 compatibility
std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void testShrubberyCreationForm() {
    std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
    
    try {
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        
        Bureaucrat gardener("Gardener", 100); // High enough to sign and execute
        Bureaucrat intern("Intern", 150);     // Can sign but not execute
        
        std::cout << "\n--- Signing phase ---" << std::endl;
        gardener.signForm(shrub);
        
        std::cout << "\n--- Execution phase ---" << std::endl;
        gardener.executeForm(shrub);
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm() {
    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    
    try {
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        Bureaucrat engineer("Engineer", 40); // High enough for both
        Bureaucrat assistant("Assistant", 70); // Can sign but not execute
        
        std::cout << "\n--- Signing phase ---" << std::endl;
        engineer.signForm(robotomy);
        
        std::cout << "\n--- Execution phase ---" << std::endl;
        engineer.executeForm(robotomy);
        
        std::cout << "\n--- Testing with insufficient grade ---" << std::endl;
        assistant.executeForm(robotomy); // Should fail
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm() {
    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        
        Bureaucrat president("President", 1); // Highest grade
        Bureaucrat minister("Minister", 20);  // Can sign but not execute
        
        std::cout << "\n--- Signing phase ---" << std::endl;
        minister.signForm(pardon);
        
        std::cout << "\n--- Execution phase ---" << std::endl;
        president.executeForm(pardon);
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testExecutionWithoutSigning() {
    std::cout << "\n=== Testing Execution Without Signing ===" << std::endl;
    
    try {
        ShrubberyCreationForm unsignedForm("garden");
        Bureaucrat executor("Executor", 1);
        
        std::cout << "Attempting to execute unsigned form:" << std::endl;
        executor.executeForm(unsignedForm); // Should fail
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testGradeRequirements() {
    std::cout << "\n=== Testing Grade Requirements ===" << std::endl;
    
    try {
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("C3PO");
        PresidentialPardonForm pardon("Ford Prefect");
        
        Bureaucrat lowGrade("LowGrade", 150);
        Bureaucrat midGrade("MidGrade", 75);
        Bureaucrat highGrade("HighGrade", 1);
        
        std::cout << "\n--- Low grade bureaucrat (150) ---" << std::endl;
        lowGrade.signForm(shrub);    // Should succeed (needs 145)
        lowGrade.signForm(robot);    // Should fail (needs 72)
        lowGrade.signForm(pardon);   // Should fail (needs 25)
        
        std::cout << "\n--- Mid grade bureaucrat (75) ---" << std::endl;
        midGrade.signForm(shrub);    // Should succeed
        midGrade.signForm(robot);    // Should fail (needs 72)
        midGrade.signForm(pardon);   // Should fail (needs 25)
        
        std::cout << "\n--- High grade bureaucrat (1) ---" << std::endl;
        highGrade.signForm(shrub);   // Should succeed
        highGrade.signForm(robot);   // Should succeed
        highGrade.signForm(pardon);  // Should succeed
        
        std::cout << "\n--- Execution attempts ---" << std::endl;
        highGrade.executeForm(shrub);  // Should succeed
        highGrade.executeForm(robot);  // Should succeed
        highGrade.executeForm(pardon); // Should succeed
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testPolymorphism() {
    std::cout << "\n=== Testing Polymorphism ===" << std::endl;
    
    try {
        Bureaucrat ceo("CEO", 1);
        
        // Array of AForm pointers - demonstrates polymorphism
        AForm* forms[] = {
            new ShrubberyCreationForm("park"),
            new RobotomyRequestForm("Marvin"),
            new PresidentialPardonForm("Trillian")
        };
        
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Form " << i + 1 << " ---" << std::endl;
            std::cout << *forms[i] << std::endl;
            
            // Sign forms manually using beSigned (since signForm expects Form&)
            try {
                forms[i]->beSigned(ceo);
                std::cout << ceo.getName() << " signed " << forms[i]->getName() << std::endl;
            } catch (std::exception& e) {
                std::cout << ceo.getName() << " couldn't sign " << forms[i]->getName() 
                          << " because " << e.what() << std::endl;
            }
            
            // Execute using polymorphism
            ceo.executeForm(*forms[i]);
        }
        
        // Clean up
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testCopyConstructors() {
    std::cout << "\n=== Testing Copy Constructors ===" << std::endl;
    
    try {
        ShrubberyCreationForm original("original");
        Bureaucrat signer("Signer", 100);
        
        signer.signForm(original);
        std::cout << "Original: " << original << std::endl;
        
        ShrubberyCreationForm copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        signer.executeForm(copy); // Should work since it's signed
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testMultipleRobotomies() {
    std::cout << "\n=== Testing Multiple Robotomies (50% success rate) ===" << std::endl;
    
    try {
        Bureaucrat roboticist("Roboticist", 40);
        
        for (int i = 1; i <= 5; i++) {
            std::cout << "\n--- Robotomy attempt " << i << " ---" << std::endl;
            RobotomyRequestForm robot("Target_" + intToString(i));
            roboticist.signForm(robot);
            roboticist.executeForm(robot);
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== AFORM AND CONCRETE FORMS TESTING PROGRAM ===" << std::endl;
    
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testExecutionWithoutSigning();
    testGradeRequirements();
    testPolymorphism();
    testCopyConstructors();
    testMultipleRobotomies();
    
    std::cout << "\n=== END OF TESTS ===" << std::endl;
    std::cout << "\nCheck for generated *_shrubbery files in the directory!" << std::endl;
    
    return 0;
}