#include "Bureaucrat.hpp"

void testBasicFunctionality() {
    std::cout << "\n=== Testing Basic Functionality ===" << std::endl;
    
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        
        std::cout << "Name: " << bob.getName() << std::endl;
        std::cout << "Grade: " << bob.getGrade() << std::endl;
        
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testGradeTooHigh() {
    std::cout << "\n=== Testing Grade Too High Exception ===" << std::endl;
    
    try {
        Bureaucrat alice("Alice", 0); // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught during construction: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat charlie("Charlie", 1);
        std::cout << "Created: " << charlie << std::endl;
        charlie.incrementGrade(); // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught during increment: " << e.what() << std::endl;
    }
}

void testGradeTooLow() {
    std::cout << "\n=== Testing Grade Too Low Exception ===" << std::endl;
    
    try {
        Bureaucrat dave("Dave", 151); // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught during construction: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat eve("Eve", 150);
        std::cout << "Created: " << eve << std::endl;
        eve.decrementGrade(); // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught during decrement: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment() {
    std::cout << "\n=== Testing Copy Constructor and Assignment ===" << std::endl;
    
    try {
        Bureaucrat original("Original", 42);
        std::cout << "Original: " << original << std::endl;
        
        // Test copy constructor
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        // Test assignment operator
        Bureaucrat assigned("Assigned", 100);
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
        Bureaucrat highest("Highest", 1);
        std::cout << "Highest grade: " << highest << std::endl;
        
        Bureaucrat lowest("Lowest", 150);
        std::cout << "Lowest grade: " << lowest << std::endl;
        
        // Test incrementing from 2 to 1
        Bureaucrat almostHighest("AlmostHighest", 2);
        std::cout << "Before increment: " << almostHighest << std::endl;
        almostHighest.incrementGrade();
        std::cout << "After increment: " << almostHighest << std::endl;
        
        // Test decrementing from 149 to 150
        Bureaucrat almostLowest("AlmostLowest", 149);
        std::cout << "Before decrement: " << almostLowest << std::endl;
        almostLowest.decrementGrade();
        std::cout << "After decrement: " << almostLowest << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== BUREAUCRAT TESTING PROGRAM ===" << std::endl;
    
    testBasicFunctionality();
    testGradeTooHigh();
    testGradeTooLow();
    testCopyAndAssignment();
    testBoundaryValues();
    
    std::cout << "\n=== END OF TESTS ===" << std::endl;
    
    return 0;
}