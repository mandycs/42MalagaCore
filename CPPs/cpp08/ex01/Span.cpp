#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N); // Optimización: reservar memoria
}

// Constructor de copia
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

// Operador de asignación
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructor
Span::~Span() {
}

// Añadir un solo número
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

// Encontrar la distancia más corta entre números
unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    // Crear una copia ordenada del vector
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = UINT_MAX;
    
    // Encontrar la diferencia mínima entre elementos consecutivos
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }
    
    return minSpan;
}

// Encontrar la distancia más larga entre números
unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    // Encontrar el mínimo y máximo usando algoritmos STL
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(*maxIt - *minIt);
}

// Funciones de utilidad
unsigned int Span::size() const {
    return _numbers.size();
}

unsigned int Span::maxSize() const {
    return _maxSize;
}

bool Span::empty() const {
    return _numbers.empty();
}

bool Span::full() const {
    return _numbers.size() >= _maxSize;
}

// Implementación de excepciones
const char* Span::SpanFullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Cannot calculate span with less than 2 numbers";
}

const char* Span::RangeTooBigException::what() const throw() {
    return "Range is too big to fit in the remaining space";
}