#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include "easyfind.hpp"

void testVector() {
    std::cout << "=== Testing std::vector ===" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(100);
    vec.push_back(42); // Duplicate value
    
    std::cout << "Vector contents: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::vector<int>::iterator result = easyfind(vec, 42);
        std::cout << "Found 42 at position: " << std::distance(vec.begin(), result) << std::endl;
        std::cout << "Value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::vector<int>::iterator result = easyfind(vec, 999);
        std::cout << "Found 999 at position: " << std::distance(vec.begin(), result) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error searching for 999: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testList() {
    std::cout << "=== Testing std::list ===" << std::endl;
    
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::list<int>::iterator result = easyfind(lst, 30);
        std::cout << "Found 30 in list!" << std::endl;
        std::cout << "Value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        easyfind(lst, 99);
        std::cout << "Found 99 in list!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error searching for 99: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testDeque() {
    std::cout << "=== Testing std::deque ===" << std::endl;
    
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_front(15);
    deq.push_back(25);
    deq.push_front(35);
    
    std::cout << "Deque contents: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::deque<int>::iterator result = easyfind(deq, 25);
        std::cout << "Found 25 at position: " << std::distance(deq.begin(), result) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testConstContainer() {
    std::cout << "=== Testing const container ===" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    
    const std::vector<int>& constVec = vec;
    
    std::cout << "Const vector contents: ";
    for (std::vector<int>::const_iterator it = constVec.begin(); it != constVec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        std::vector<int>::const_iterator result = easyfind(constVec, 200);
        std::cout << "Found 200 in const vector!" << std::endl;
        std::cout << "Value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testEmptyContainer() {
    std::cout << "=== Testing empty container ===" << std::endl;
    
    std::vector<int> emptyVec;
    
    try {
        easyfind(emptyVec, 42);
        std::cout << "Found 42 in empty vector!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error searching in empty container: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

int main() {
    std::cout << "=== EASYFIND FUNCTION TEMPLATE TESTS ===" << std::endl << std::endl;
    
    testVector();
    testList();
    testDeque();
    testConstContainer();
    testEmptyContainer();
    
    std::cout << "=== All tests completed! ===" << std::endl;
    
    return 0;
}