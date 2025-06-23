#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cout << "Examples:" << std::endl;
        std::cout << "  " << argv[0] << " 'c'" << std::endl;
        std::cout << "  " << argv[0] << " 42" << std::endl;
        std::cout << "  " << argv[0] << " 42.0f" << std::endl;
        std::cout << "  " << argv[0] << " 42.0" << std::endl;
        std::cout << "  " << argv[0] << " nan" << std::endl;
        std::cout << "  " << argv[0] << " +inff" << std::endl;
        return 1;
    }

    std::string literal = argv[1];
    ScalarConverter::convert(literal);

    return 0;
}