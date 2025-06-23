#include "Bureaucrat.hpp"
#include "Form.hpp"

void testBasicFormFunctionality() {
    std::cout << "\n=== Testing Basic Form Functionality ===" << std::endl;
    
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
        
        std::cout << "Name: " << taxForm.getName() << std::endl;
        std::cout << "Is signed: " << (taxForm.getIsSigned() ? "yes" : "no") << std::endl;
        std::cout << "Grade to sign: " << taxForm.getGradeToSign() << std::endl;
        std::cout << "Grade to execute: " << taxForm.getGradeToExecute() << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testFormExceptions() {
    std::cout << "\n=== Testing Form Exceptions ===" << std::endl;
    
    try {
        Form invalidForm1("Invalid High", 0, 50); // Should throw
    } catch (std::exception& e) {
        std::cout << "Exception caught (grade too high): " << e.what() << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid Low", 50, 151); // Should throw
    } catch (std::exception& e) {
        std::cout << "Exception caught (grade too low): " << e.what() << std::endl;
    }
}

void testFormSigning() {
    std::cout << "\n=== Testing Form Signing ===" << std::endl;
    
    try {
        Form permit("Building Permit", 30, 20);
        std::cout << "Created: " << permit << std::endl;
        
        Bureaucrat alice("Alice", 25); // High enough grade
        std::cout << "Created: " << alice << std::endl;
        
        alice.signForm(permit);
        std::cout << "After signing: " << permit << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testFormSigningFailure() {
    std::cout << "\n=== Testing Form Signing Failure ===" << std::endl;
    
    try {
        Form vipPass("VIP Pass", 10, 5);
        std::cout << "Created: " << vipPass << std::endl;
        
        Bureaucrat bob("Bob", 50); // Grade too low
        std::cout << "Created: " << bob << std::endl;
        
        bob.signForm(vipPass); // Should fail
        std::cout << "After signing attempt: " << vipPass << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testMultipleBureaucrats() {
    std::cout << "\n=== Testing Multiple Bureaucrats ===" << std::endl;
    
    try {
        Form contract("Contract", 40, 30);
        std::cout << "Created: " << contract << std::endl;
        
        Bureaucrat charlie("Charlie", 45); // Too low
        Bureaucrat diana("Diana", 35);     // High enough
        
        std::cout << "Charlie tries to sign:" << std::endl;
        charlie.signForm(contract);
        
        std::cout << "Diana tries to sign:" << std::endl;
        diana.signForm(contract);
        
        std::cout << "Final form state: " << contract << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testFormCopyAndAssignment() {
    std::cout << "\n=== Testing Form Copy and Assignment ===" << std::endl;
    
    try {
        Form original("Original Form", 60, 40);
        Bureaucrat signer("Signer", 50);
        
        std::cout << "Original before signing: " << original << std::endl;
        signer.signForm(original);
        std::cout << "Original after signing: " << original << std::endl;
        
        // Test copy constructor
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        // Test assignment operator
        Form assigned("Assigned Form", 100, 80);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testBoundaryValues() {
    std::cout << "\n=== Testing Boundary Values ===" << std::endl;
    
    try {
        Form strictForm("Strict Form", 1, 1);     // Highest grades
        Form lenientForm("Lenient Form", 150, 150); // Lowest grades
        
        std::cout << "Strict form: " << strictForm << std::endl;
        std::cout << "Lenient form: " << lenientForm << std::endl;
        
        Bureaucrat topBureaucrat("Top", 1);
        Bureaucrat bottomBureaucrat("Bottom", 150);
        
        topBureaucrat.signForm(strictForm);
        topBureaucrat.signForm(lenientForm);
        
        bottomBureaucrat.signForm(lenientForm);
        bottomBureaucrat.signForm(strictForm); // Should fail
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== FORM AND BUREAUCRAT TESTING PROGRAM ===" << std::endl;
    
    testBasicFormFunctionality();
    testFormExceptions();
    testFormSigning();
    testFormSigningFailure();
    testMultipleBureaucrats();
    testFormCopyAndAssignment();
    testBoundaryValues();
    
    std::cout << "\n=== END OF TESTS ===" << std::endl;
    
    return 0;
}