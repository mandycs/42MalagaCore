#include "ScalarConverter.hpp"

// Main conversion method
void ScalarConverter::convert(const std::string& literal) {
    LiteralType type = detectType(literal);
    
    switch (type) {
        case CHAR_TYPE: {
            char c = literal[1]; // literal[0] is ', literal[1] is the char
            convertFromChar(c);
            break;
        }
        case INT_TYPE: {
            std::stringstream ss(literal);
            int value;
            ss >> value;
            convertFromInt(value);
            break;
        }
        case FLOAT_TYPE: {
            if (isSpecialFloat(literal)) {
                double value;
                if (literal == "nanf") {
                    value = std::numeric_limits<double>::quiet_NaN();
                } else if (literal == "+inff") {
                    value = std::numeric_limits<double>::infinity();
                } else if (literal == "-inff") {
                    value = -std::numeric_limits<double>::infinity();
                } else {
                    value = 0; // fallback
                }
                convertFromDouble(value);
            } else {
                std::stringstream ss(literal);
                float value;
                ss >> value;
                convertFromFloat(value);
            }
            break;
        }
        case DOUBLE_TYPE: {
            if (isSpecialDouble(literal)) {
                double value;
                if (literal == "nan") {
                    value = std::numeric_limits<double>::quiet_NaN();
                } else if (literal == "+inf") {
                    value = std::numeric_limits<double>::infinity();
                } else if (literal == "-inf") {
                    value = -std::numeric_limits<double>::infinity();
                } else {
                    value = 0; // fallback
                }
                convertFromDouble(value);
            } else {
                std::stringstream ss(literal);
                double value;
                ss >> value;
                convertFromDouble(value);
            }
            break;
        }
        default:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}

// Type detection
ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal) {
    if (isChar(literal))
        return CHAR_TYPE;
    if (isSpecialFloat(literal))
        return FLOAT_TYPE;
    if (isSpecialDouble(literal))
        return DOUBLE_TYPE;
    if (isFloat(literal))
        return FLOAT_TYPE;
    if (isDouble(literal))
        return DOUBLE_TYPE;
    if (isInt(literal))
        return INT_TYPE;
    return INVALID_TYPE;
}

bool ScalarConverter::isChar(const std::string& literal) {
    if (literal.length() != 3) return false;
    if (literal[0] != '\'' || literal[2] != '\'') return false;
    
    char c = literal[1];
    // Check if character is in printable ASCII range (32-126)
    return (c >= 32 && c <= 126);
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-') start = 1;
    if (start >= literal.length()) return false;
    
    for (size_t i = start; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    
    // Check for overflow
    std::stringstream ss(literal);
    long long value;
    ss >> value;
    return (value >= std::numeric_limits<int>::min() && 
            value <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty() || literal[literal.length() - 1] != 'f') return false;
    
    std::string without_f = literal.substr(0, literal.length() - 1);
    if (without_f.empty()) return false;
    
    size_t start = 0;
    if (without_f[0] == '+' || without_f[0] == '-') start = 1;
    if (start >= without_f.length()) return false;
    
    bool has_dot = false;
    for (size_t i = start; i < without_f.length(); i++) {
        if (without_f[i] == '.') {
            if (has_dot) return false; // Multiple dots
            has_dot = true;
        } else if (!std::isdigit(without_f[i])) {
            return false;
        }
    }
    
    return has_dot; // Must have a decimal point for float
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-') start = 1;
    if (start >= literal.length()) return false;
    
    bool has_dot = false;
    for (size_t i = start; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (has_dot) return false; // Multiple dots
            has_dot = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    
    return has_dot; // Must have a decimal point for double
}

bool ScalarConverter::isSpecialFloat(const std::string& literal) {
    return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isSpecialDouble(const std::string& literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

// Conversion methods
void ScalarConverter::convertFromChar(char c) {
    double value = static_cast<double>(c);
    displayChar(value);
    displayInt(value);
    displayFloat(value);
    displayDouble(value);
}

void ScalarConverter::convertFromInt(int value) {
    double d_value = static_cast<double>(value);
    displayChar(d_value);
    displayInt(d_value);
    displayFloat(d_value);
    displayDouble(d_value);
}

void ScalarConverter::convertFromFloat(float value) {
    double d_value = static_cast<double>(value);
    displayChar(d_value);
    displayInt(d_value);
    displayFloat(d_value);
    displayDouble(d_value);
}

void ScalarConverter::convertFromDouble(double value) {
    displayChar(value);
    displayInt(value);
    displayFloat(value);
    displayDouble(value);
}

// Display methods
void ScalarConverter::displayChar(double value) {
    std::cout << "char: ";
    if (isNaN(value) || isInf(value)) {
        std::cout << "impossible";
    } else if (value < 0 || value > 127) {
        std::cout << "impossible";
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'";
    }
    std::cout << std::endl;
}

void ScalarConverter::displayInt(double value) {
    std::cout << "int: ";
    if (isNaN(value) || isInf(value)) {
        std::cout << "impossible";
    } else if (value < std::numeric_limits<int>::min() || 
               value > std::numeric_limits<int>::max()) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(value);
    }
    std::cout << std::endl;
}

void ScalarConverter::displayFloat(double value) {
    std::cout << "float: ";
    float f_value = static_cast<float>(value);
    
    if (isNaN(value)) {
        std::cout << "nanf";
    } else if (isInf(value)) {
        if (value > 0) std::cout << "+inff";
        else std::cout << "-inff";
    } else {
        std::cout << std::fixed << std::setprecision(1) << f_value << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::displayDouble(double value) {
    std::cout << "double: ";
    
    if (isNaN(value)) {
        std::cout << "nan";
    } else if (isInf(value)) {
        if (value > 0) std::cout << "+inf";
        else std::cout << "-inf";
    } else {
        std::cout << std::fixed << std::setprecision(1) << value;
    }
    std::cout << std::endl;
}

// Special value detection
bool ScalarConverter::isNaN(double value) {
    return std::isnan(value);
}

bool ScalarConverter::isInf(double value) {
    return std::isinf(value);
}