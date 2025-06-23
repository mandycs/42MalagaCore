#include "RPN.hpp"

// Constructor
RPN::RPN() {
}

// Destructor
RPN::~RPN() {
}

// Función para eliminar espacios en blanco
std::string RPN::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

// Convertir string a double con manejo de errores
double RPN::stringToDouble(const std::string& str) const {
    char* endptr;
    double value = std::strtod(str.c_str(), &endptr);
    
    // Verificar si la conversión fue exitosa
    if (*endptr != '\0' || endptr == str.c_str()) {
        throw std::invalid_argument("Invalid number format");
    }
    
    return value;
}

// Verificar si un token es un operador válido
bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Verificar si un token es un número válido
bool RPN::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    
    try {
        stringToDouble(token);
        return true;
    } catch (const std::exception&) {
        return false;
    }
}

// Realizar una operación aritmética
void RPN::performOperation(const std::string& op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error: insufficient operands for operation");
    }
    
    // Obtener los dos operandos (el orden importa para - y /)
    double b = _stack.top(); _stack.pop();
    double a = _stack.top(); _stack.pop();
    
    double result;
    
    if (op == "+") {
        result = a + b;
    } else if (op == "-") {
        result = a - b;
    } else if (op == "*") {
        result = a * b;
    } else if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Error: division by zero");
        }
        result = a / b;
    } else {
        throw std::runtime_error("Error: unknown operator");
    }
    
    _stack.push(result);
}

// Evaluar expresión RPN
double RPN::evaluate(const std::string& expression) {
    // Limpiar el stack antes de empezar
    clear();
    
    // Verificar que la expresión no esté vacía
    if (expression.empty()) {
        throw std::runtime_error("Error: empty expression");
    }
    
    // Verificar que no haya paréntesis (prohibidos según el PDF)
    if (expression.find('(') != std::string::npos || expression.find(')') != std::string::npos) {
        throw std::runtime_error("Error");
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        token = trim(token);
        
        if (token.empty()) continue;
        
        if (isNumber(token)) {
            double number = stringToDouble(token);
            
            // Verificar que el número sea menor que 10 (según PDF)
            if (number >= 10 || number < 0) {
                throw std::runtime_error("Error: numbers must be less than 10 and positive");
            }
            
            _stack.push(number);
        } else if (isOperator(token)) {
            performOperation(token);
        } else {
            throw std::runtime_error("Error");
        }
    }
    
    // Verificar que quede exactamente un resultado
    if (_stack.empty()) {
        throw std::runtime_error("Error: no result");
    } else if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }
    
    return _stack.top();
}

// Funciones de utilidad
void RPN::printStack() const {
    std::stack<double> temp = _stack;
    std::cout << "Stack (top to bottom): ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

void RPN::clear() {
    while (!_stack.empty()) {
        _stack.pop();
    }
}

bool RPN::empty() const {
    return _stack.empty();
}

size_t RPN::size() const {
    return _stack.size();
}