#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    try {
        PmergeMe sorter;
        sorter.processArguments(argc, argv);
        
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}