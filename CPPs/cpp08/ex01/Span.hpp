#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructor
    Span(unsigned int N);
    
    // Constructor de copia
    Span(const Span& other);
    
    // Operador de asignación
    Span& operator=(const Span& other);
    
    // Destructor
    ~Span();
    
    // Añadir un solo número
    void addNumber(int number);
    
    // Añadir múltiples números usando un rango de iterators
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    // Encontrar la distancia más corta entre números
    unsigned int shortestSpan() const;
    
    // Encontrar la distancia más larga entre números
    unsigned int longestSpan() const;
    
    // Funciones de utilidad
    unsigned int size() const;
    unsigned int maxSize() const;
    bool empty() const;
    bool full() const;
    
    // Excepciones personalizadas
    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class RangeTooBigException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Implementación de la función template en el header
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    // Calcular la distancia del rango
    size_t distance = std::distance(begin, end);
    
    // Verificar si hay espacio suficiente
    if (_numbers.size() + distance > _maxSize) {
        throw RangeTooBigException();
    }
    
    // Añadir los elementos al vector
    _numbers.insert(_numbers.end(), begin, end);
}

#endif