#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "MutantStack.hpp"

void testPDFExample() {
    std::cout << "=== Testing PDF Example with MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "Stack contents (using iterators): ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::stack<int> s(mstack);
    std::cout << "Converted to std::stack successfully!" << std::endl;
    
    std::cout << std::endl;
}

void testWithList() {
    std::cout << "=== Testing Same Logic with std::list ===" << std::endl;
    
    std::list<int> mstack;
    
    mstack.push_back(5);
    mstack.push_back(17);
    
    std::cout << "Back: " << mstack.back() << std::endl;
    
    mstack.pop_back();
    
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    std::cout << "List contents (using iterators): ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testIteratorFeatures() {
    std::cout << "=== Testing Iterator Features ===" << std::endl;
    
    MutantStack<int> mstack;
    
    // Llenar el stack
    for (int i = 1; i <= 10; ++i) {
        mstack.push(i);
    }
    
    std::cout << "Stack size: " << mstack.size() << std::endl;
    
    // Test forward iterators
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test reverse iterators
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test const iterators
    const MutantStack<int>& constStack = mstack;
    std::cout << "Const iteration: ";
    for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testSTLAlgorithms() {
    std::cout << "=== Testing STL Algorithms with MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    // Añadir algunos números
    mstack.push(42);
    mstack.push(7);
    mstack.push(99);
    mstack.push(13);
    mstack.push(56);
    
    std::cout << "Original stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Usar std::find
    MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 99);
    if (found != mstack.end()) {
        std::cout << "Found 99 in the stack!" << std::endl;
    }
    
    // Usar std::count
    int count = std::count(mstack.begin(), mstack.end(), 7);
    std::cout << "Number 7 appears " << count << " times" << std::endl;
    
    // Usar std::for_each para modificar elementos
    std::cout << "Doubling all values..." << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        *it *= 2;
    }
    
    std::cout << "Modified stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "=== Testing Copy Constructor and Assignment ===" << std::endl;
    
    MutantStack<int> original;
    original.push(100);
    original.push(200);
    original.push(300);
    
    // Copy constructor
    MutantStack<int> copied(original);
    std::cout << "Copied stack size: " << copied.size() << std::endl;
    std::cout << "Copied stack top: " << copied.top() << std::endl;
    
    // Assignment operator
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "Assigned stack size: " << assigned.size() << std::endl;
    
    // Verify independence
    original.push(400);
    std::cout << "After adding to original:" << std::endl;
    std::cout << "Original size: " << original.size() << std::endl;
    std::cout << "Copied size: " << copied.size() << std::endl;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    
    std::cout << std::endl;
}

void testDifferentTypes() {
    std::cout << "=== Testing Different Types ===" << std::endl;
    
    // Test with strings
    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("42");
    
    std::cout << "String stack: ";
    for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it) {
        std::cout << "\"" << *it << "\" ";
    }
    std::cout << std::endl;
    
    // Test with chars
    MutantStack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    
    std::cout << "Char stack: ";
    for (MutantStack<char>::iterator it = charStack.begin(); it != charStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

int main() {
    std::cout << "=== MUTANTSTACK COMPREHENSIVE TESTS ===" << std::endl << std::endl;
    
    testPDFExample();
    testWithList();
    testIteratorFeatures();
    testSTLAlgorithms();
    testCopyAndAssignment();
    testDifferentTypes();
    
    std::cout << "=== All tests completed! ===" << std::endl;
    std::cout << "MutantStack behaves like std::list but with stack interface!" << std::endl;
    
    return 0;
}