#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

class ScalarConverter {
private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // Type detection enumeration
    enum LiteralType {
        CHAR_TYPE,
        INT_TYPE, 
        FLOAT_TYPE,
        DOUBLE_TYPE,
        INVALID_TYPE
    };

    // Helper methods for type detection
    static LiteralType detectType(const std::string& literal);
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isSpecialFloat(const std::string& literal);
    static bool isSpecialDouble(const std::string& literal);

    // Conversion helper methods
    static void convertFromChar(char c);
    static void convertFromInt(int value);
    static void convertFromFloat(float value);
    static void convertFromDouble(double value);

    // Display helper methods
    static void displayChar(double value);
    static void displayInt(double value);
    static void displayFloat(double value);
    static void displayDouble(double value);

    // Special values handling
    static bool isNaN(double value);
    static bool isInf(double value);

public:
    // Main conversion method
    static void convert(const std::string& literal);
};

#endif