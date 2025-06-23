#include "B.hpp"
#include <iostream>

B::B() {
    std::cout << "B constructor called" << std::endl;
}

B::~B() {
    std::cout << "B destructor called" << std::endl;
}