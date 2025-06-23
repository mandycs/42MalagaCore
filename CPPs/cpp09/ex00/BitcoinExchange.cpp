#include "BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange() {
}

// Destructor
BitcoinExchange::~BitcoinExchange() {
}

// Función para eliminar espacios en blanco
std::string BitcoinExchange::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

// Convertir string a double con manejo de errores
double BitcoinExchange::stringToDouble(const std::string& str) const {
    char* endptr;
    double value = std::strtod(str.c_str(), &endptr);
    
    // Verificar si la conversión fue exitosa
    if (*endptr != '\0' || endptr == str.c_str()) {
        throw std::invalid_argument("Invalid number format");
    }
    
    return value;
}

// Validar formato de fecha YYYY-MM-DD
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    // Verificar que todos los caracteres apropiados sean dígitos
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue; // Saltar los guiones
        if (!std::isdigit(date[i])) return false;
    }
    
    // Validación básica de rangos
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 1000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    return true;
}

// Validar que el valor esté en el rango permitido
bool BitcoinExchange::isValidValue(double value) const {
    return value >= 0.0 && value <= 1000.0;
}

// Parsear una línea con el delimitador especificado
void BitcoinExchange::parseLine(const std::string& line, std::string& date, std::string& valueStr, char delimiter) const {
    size_t delimiterPos = line.find(delimiter);
    if (delimiterPos == std::string::npos) {
        throw std::invalid_argument("No delimiter found");
    }
    
    date = trim(line.substr(0, delimiterPos));
    valueStr = trim(line.substr(delimiterPos + 1));
}

// Cargar base de datos desde archivo CSV
bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue; // Saltar header
        }
        
        if (line.empty()) continue;
        
        try {
            std::string date, valueStr;
            parseLine(line, date, valueStr, ',');
            
            if (!isValidDate(date)) {
                std::cerr << "Warning: invalid date in database: " << date << std::endl;
                continue;
            }
            
            double value = stringToDouble(valueStr);
            _database[date] = value;
            
        } catch (const std::exception& e) {
            std::cerr << "Warning: error parsing database line: " << line << std::endl;
        }
    }
    
    file.close();
    return !_database.empty();
}

// Encontrar la fecha más cercana (menor o igual)
std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    if (_database.empty()) {
        throw std::runtime_error("Database is empty");
    }
    
    // Buscar la fecha exacta o la inmediatamente anterior
    std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
    
    if (it == _database.begin()) {
        // La fecha es anterior a la primera fecha en la base de datos
        throw std::runtime_error("Date is too early");
    }
    
    --it; // Retroceder al elemento anterior (menor o igual)
    return it->first;
}

// Obtener el precio de Bitcoin para una fecha específica
double BitcoinExchange::getBitcoinPrice(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _database.find(date);
    
    if (it != _database.end()) {
        return it->second;
    }
    
    // Si no se encuentra la fecha exacta, buscar la más cercana
    std::string closestDate = findClosestDate(date);
    return _database.find(closestDate)->second;
}

// Procesar archivo de input
void BitcoinExchange::processInputFile(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue; // Saltar header "date | value"
        }
        
        if (line.empty()) continue;
        
        try {
            std::string date, valueStr;
            parseLine(line, date, valueStr, '|');
            
            // Validar fecha
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            
            // Validar y convertir valor
            double value;
            try {
                value = stringToDouble(valueStr);
            } catch (const std::exception&) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            // Validar rango de valor
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            
            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            
            // Obtener precio de Bitcoin y calcular resultado
            try {
                double btcPrice = getBitcoinPrice(date);
                double result = value * btcPrice;
                
                std::cout << date << " => " << value << " = " << result << std::endl;
                
            } catch (const std::exception&) {
                std::cerr << "Error: date not found in database => " << date << std::endl;
            }
            
        } catch (const std::exception&) {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    
    file.close();
}

// Funciones de utilidad
size_t BitcoinExchange::getDatabaseSize() const {
    return _database.size();
}

void BitcoinExchange::printDatabase() const {
    for (std::map<std::string, double>::const_iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}