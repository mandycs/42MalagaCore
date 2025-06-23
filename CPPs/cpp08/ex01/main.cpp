#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void testBasicExample() {
    std::cout << "=== Testing Basic Example from PDF ===" << std::endl;
    
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testExceptions() {
    std::cout << "=== Testing Exception Handling ===" << std::endl;
    
    // Test SpanFullException
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << "Added 3 numbers to span of size 3" << std::endl;
        sp.addNumber(4); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    // Test NoSpanException with empty span
    try {
        Span sp(5);
        sp.shortestSpan(); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Expected exception (empty): " << e.what() << std::endl;
    }
    
    // Test NoSpanException with one element
    try {
        Span sp(5);
        sp.addNumber(42);
        sp.longestSpan(); // Should throw
    } catch (const std::exception& e) {
        std::cout << "Expected exception (one element): " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testLargeNumbers() {
    std::cout << "=== Testing with 10,000+ numbers ===" << std::endl;
    
    try {
        const unsigned int SIZE = 15000;
        Span sp(SIZE);
        
        std::cout << "Adding " << SIZE << " random numbers..." << std::endl;
        
        srand(time(NULL));
        for (unsigned int i = 0; i < SIZE; ++i) {
            sp.addNumber(rand() % 100000);
        }
        
        std::cout << "Numbers added: " << sp.size() << "/" << sp.maxSize() << std::endl;
        std::cout << "Calculating spans..." << std::endl;
        
        unsigned int shortest = sp.shortestSpan();
        unsigned int longest = sp.longestSpan();
        
        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testRangeInsertion() {
    std::cout << "=== Testing Range Insertion ===" << std::endl;
    
    // Test with vector
    try {
        std::vector<int> vec;
        vec.push_back(100);
        vec.push_back(200);
        vec.push_back(300);
        vec.push_back(400);
        
        Span sp(10);
        sp.addNumber(50); // Add one manually first
        
        std::cout << "Adding range from vector..." << std::endl;
        sp.addNumbers(vec.begin(), vec.end());
        
        std::cout << "Total numbers: " << sp.size() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test with list
    try {
        std::list<int> lst;
        lst.push_back(1000);
        lst.push_back(2000);
        lst.push_back(3000);
        
        Span sp(5);
        std::cout << "Adding range from list..." << std::endl;
        sp.addNumbers(lst.begin(), lst.end());
        
        std::cout << "Total numbers: " << sp.size() << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test range too big exception
    try {
        std::vector<int> bigVec(100, 42); // 100 elements
        Span sp(50); // Only space for 50
        
        std::cout << "Trying to add 100 elements to span of size 50..." << std::endl;
        sp.addNumbers(bigVec.begin(), bigVec.end()); // Should throw
        
    } catch (const std::exception& e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "=== Testing Edge Cases ===" << std::endl;
    
    // Test with identical numbers
    try {
        Span sp(5);
        sp.addNumber(42);
        sp.addNumber(42);
        sp.addNumber(42);
        
        std::cout << "With identical numbers:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test with negative numbers
    try {
        Span sp(4);
        sp.addNumber(-100);
        sp.addNumber(-50);
        sp.addNumber(0);
        sp.addNumber(50);
        
        std::cout << "With negative numbers:" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "=== Testing Copy Constructor and Assignment ===" << std::endl;
    
    try {
        // Original span
        Span original(5);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);
        
        // Copy constructor
        Span copied(original);
        std::cout << "Copied span size: " << copied.size() << std::endl;
        std::cout << "Copied shortest span: " << copied.shortestSpan() << std::endl;
        
        // Assignment operator
        Span assigned(10);
        assigned = original;
        std::cout << "Assigned span size: " << assigned.size() << std::endl;
        std::cout << "Assigned longest span: " << assigned.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

int main() {
    std::cout << "=== SPAN CLASS COMPREHENSIVE TESTS ===" << std::endl << std::endl;
    
    testBasicExample();
    testExceptions();
    testLargeNumbers();
    testRangeInsertion();
    testEdgeCases();
    testCopyAndAssignment();
    
    std::cout << "=== All tests completed! ===" << std::endl;
    
    return 0;
}