#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN {
private:
    std::stack<double> _stack;
    
    // Funciones privadas de utilidad
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    double stringToDouble(const std::string& str) const;
    void performOperation(const std::string& op);
    std::string trim(const std::string& str) const;

public:
    // Constructor
    RPN();
    
    // Destructor
    ~RPN();
    
    // Evaluar expresión RPN
    double evaluate(const std::string& expression);
    
    // Función para debugging
    void printStack() const;
    
    // Limpiar el stack
    void clear();
    
    // Verificar si el stack está vacío
    bool empty() const;
    
    // Obtener el tamaño del stack
    size_t size() const;
};

#endif