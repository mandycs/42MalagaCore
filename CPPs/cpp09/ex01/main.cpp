#include <iostream>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
    // Verificar argumentos
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"" << std::endl;
        return 1;
    }
    
    // Crear calculadora RPN
    RPN calculator;
    
    try {
        // Evaluar la expresión
        double result = calculator.evaluate(argv[1]);
        
        // Mostrar el resultado
        std::cout << result << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}