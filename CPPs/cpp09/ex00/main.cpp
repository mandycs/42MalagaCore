#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    // Verificar argumentos
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    
    // Crear instancia del exchange
    BitcoinExchange exchange;
    
    // Cargar base de datos (buscar data.csv en directorio actual)
    if (!exchange.loadDatabase("data.csv")) {
        std::cerr << "Error: could not load database file 'data.csv'" << std::endl;
        return 1;
    }
    
    // Procesar archivo de input
    exchange.processInputFile(argv[1]);
    
    return 0;
}