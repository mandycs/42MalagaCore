#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "Complaining at DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nComplaining at INFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nComplaining at WARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nComplaining at ERROR level:" << std::endl;
    harl.complain("ERROR");

    return 0;
}
