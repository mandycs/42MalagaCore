#include "A.hpp"
#include <iostream>

A::A() {
    std::cout << "A constructor called" << std::endl;
}

A::~A() {
    std::cout << "A destructor called" << std::endl;
}