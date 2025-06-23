#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Function to randomly instantiate A, B, or C and return as Base pointer
Base* generate(void) {
    // Seed random number generator (in real usage, this would be done once)
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    int random = std::rand() % 3; // 0, 1, or 2
    
    switch (random) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return NULL; // Should never happen
    }
}

// Identify actual type using pointer - can use dynamic_cast
void identify(Base* p) {
    std::cout << "Identify by pointer: ";
    
    if (p == NULL) {
        std::cout << "NULL pointer" << std::endl;
        return;
    }
    
    // Try to cast to each derived type using dynamic_cast
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// Identify actual type using reference - cannot use pointers inside
void identify(Base& p) {
    std::cout << "Identify by reference: ";
    
    // Since we can't use pointers, we use dynamic_cast with references
    // If the cast fails, it throws std::bad_cast exception
    
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a; // Suppress unused variable warning
        return;
    } catch (std::exception&) {
        // Cast failed, try next type
    }
    
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b; // Suppress unused variable warning
        return;
    } catch (std::exception&) {
        // Cast failed, try next type
    }
    
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c; // Suppress unused variable warning
        return;
    } catch (std::exception&) {
        // Cast failed, unknown type
        std::cout << "Unknown type" << std::endl;
    }
}

void testSingleGeneration() {
    std::cout << "\n=== Single Generation Test ===" << std::endl;
    
    Base* obj = generate();
    
    std::cout << "Object created at address: " << obj << std::endl;
    
    identify(obj);
    identify(*obj);
    
    std::cout << "Deleting object..." << std::endl;
    delete obj;
}

void testMultipleGenerations() {
    std::cout << "\n=== Multiple Generations Test ===" << std::endl;
    
    const int count = 5;
    Base* objects[count];
    
    // Generate multiple objects
    std::cout << "Generating " << count << " objects:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "Object " << i + 1 << ": ";
        objects[i] = generate();
    }
    
    std::cout << "\nIdentifying all objects:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << "\nObject " << i + 1 << ":" << std::endl;
        identify(objects[i]);
        identify(*objects[i]);
    }
    
    std::cout << "\nCleaning up..." << std::endl;
    for (int i = 0; i < count; i++) {
        delete objects[i];
    }
}

void testSpecificTypes() {
    std::cout << "\n=== Specific Types Test ===" << std::endl;
    
    // Create one of each type directly
    std::cout << "Creating A directly:" << std::endl;
    Base* a = new A();
    identify(a);
    identify(*a);
    delete a;
    
    std::cout << "\nCreating B directly:" << std::endl;
    Base* b = new B();
    identify(b);
    identify(*b);
    delete b;
    
    std::cout << "\nCreating C directly:" << std::endl;
    Base* c = new C();
    identify(c);
    identify(*c);
    delete c;
}

void testNullPointer() {
    std::cout << "\n=== NULL Pointer Test ===" << std::endl;
    
    Base* nullPtr = NULL;
    identify(nullPtr);
    
    // Note: We can't test identify(Base&) with NULL because 
    // dereferencing NULL would cause undefined behavior
}

int main() {
    std::cout << "=== TYPE IDENTIFICATION TESTING PROGRAM ===" << std::endl;
    
    testSingleGeneration();
    testMultipleGenerations();
    testSpecificTypes();
    testNullPointer();
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    
    return 0;
}