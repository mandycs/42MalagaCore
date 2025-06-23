#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;
    
    // Funciones de utilidad privadas
    bool isValidDate(const std::string& date) const;
    bool isValidValue(double value) const;
    std::string trim(const std::string& str) const;
    double stringToDouble(const std::string& str) const;
    std::string findClosestDate(const std::string& date) const;
    void parseLine(const std::string& line, std::string& date, std::string& valueStr, char delimiter) const;

public:
    // Constructor
    BitcoinExchange();
    
    // Destructor
    ~BitcoinExchange();
    
    // Cargar base de datos desde archivo CSV
    bool loadDatabase(const std::string& filename);
    
    // Procesar archivo de input
    void processInputFile(const std::string& filename) const;
    
    // Obtener el precio de Bitcoin para una fecha específica
    double getBitcoinPrice(const std::string& date) const;
    
    // Funciones de utilidad públicas
    size_t getDatabaseSize() const;
    void printDatabase() const; // Para debugging
};

#endif