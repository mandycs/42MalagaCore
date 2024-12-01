#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : _fixedPointValue(0) {}
Fixed::Fixed(const int value) { _fixedPointValue = value << _fractionalBits; }
Fixed::Fixed(const float value) { _fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits))); }
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed::~Fixed() {}

// Operator Overloads
Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) _fixedPointValue = other._fixedPointValue;
    return *this;
}

// Comparison Operators
bool Fixed::operator>(const Fixed &other) const { return _fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed &other) const { return _fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed &other) const { return _fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed &other) const { return _fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed &other) const { return _fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed &other) const { return _fixedPointValue != other._fixedPointValue; }

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

// Increment/Decrement Operators
Fixed &Fixed::operator++() { _fixedPointValue++; return *this; }
Fixed Fixed::operator++(int) { Fixed temp(*this); _fixedPointValue++; return temp; }
Fixed &Fixed::operator--() { _fixedPointValue--; return *this; }
Fixed Fixed::operator--(int) { Fixed temp(*this); _fixedPointValue--; return temp; }

// Member functions
int Fixed::getRawBits() const { return _fixedPointValue; }
void Fixed::setRawBits(int const raw) { _fixedPointValue = raw; }
float Fixed::toFloat() const { return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits); }
int Fixed::toInt() const { return _fixedPointValue >> _fractionalBits; }

// Static functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

// Overload insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
