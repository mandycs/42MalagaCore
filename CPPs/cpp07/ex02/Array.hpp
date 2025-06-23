#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    // Constructor por defecto - crea un array vacío
    Array() : _elements(NULL), _size(0) {
        std::cout << "Array default constructor called" << std::endl;
    }
    
    // Constructor con parámetro n - crea un array de n elementos inicializados por defecto
    Array(unsigned int n) : _elements(NULL), _size(n) {
        std::cout << "Array constructor with size " << n << " called" << std::endl;
        if (n > 0) {
            _elements = new T[n]();  // () inicializa por defecto
        }
    }
    
    // Constructor de copia
    Array(const Array& other) : _elements(NULL), _size(other._size) {
        std::cout << "Array copy constructor called" << std::endl;
        if (_size > 0) {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
    }
    
    // Operador de asignación
    Array& operator=(const Array& other) {
        std::cout << "Array assignment operator called" << std::endl;
        if (this != &other) {
            // Liberar memoria existente
            delete[] _elements;
            
            // Copiar nueva información
            _size = other._size;
            if (_size > 0) {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _elements[i] = other._elements[i];
                }
            } else {
                _elements = NULL;
            }
        }
        return *this;
    }
    
    // Destructor
    ~Array() {
        std::cout << "Array destructor called" << std::endl;
        delete[] _elements;
    }
    
    // Operador de subíndice (versión no const)
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    // Operador de subíndice (versión const)
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }
    
    // Función miembro size()
    unsigned int size() const {
        return _size;
    }
};

#endif