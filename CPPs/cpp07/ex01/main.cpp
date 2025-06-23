#include <iostream>
#include <string>
#include "iter.hpp"

// Función template para mostrar un elemento
template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

// Función para incrementar un número
void increment(int& x) {
    x++;
}

// Función para convertir a mayúsculas (solo para char)
void toUpper(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

int main() {
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test 1: Array de enteros
    std::cout << "\nTest 1: Array de enteros" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numbersSize = 5;
    
    std::cout << "Original: ";
    iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    // Test 2: Incrementando valores
    iter(numbers, numbersSize, increment);
    std::cout << "Incrementados: ";
    iter(numbers, numbersSize, print<int>);
    std::cout << std::endl;
    
    // Test 3: Array de caracteres
    std::cout << "\nTest 2: Array de caracteres" << std::endl;
    char letters[] = {'h', 'e', 'l', 'l', 'o'};
    size_t lettersSize = 5;
    
    std::cout << "Original: ";
    iter(letters, lettersSize, print<char>);
    std::cout << std::endl;
    
    iter(letters, lettersSize, toUpper);
    std::cout << "Mayúsculas: ";
    iter(letters, lettersSize, print<char>);
    std::cout << std::endl;
    
    // Test 4: Array de strings
    std::cout << "\nTest 3: Array de strings" << std::endl;
    std::string words[] = {"Hello", "World", "42"};
    size_t wordsSize = 3;
    
    std::cout << "Strings: ";
    iter(words, wordsSize, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}