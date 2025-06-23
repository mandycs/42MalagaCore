#include "C.hpp"
#include <iostream>

C::C() {
    std::cout << "C constructor called" << std::endl;
}

C::~C() {
    std::cout << "C destructor called" << std::endl;
}