#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Default constructor
    Fixed();
    // Constructor from integera
    Fixed(int value);
    // Constructor from float
    Fixed(float value);
    // Copy constructor
    Fixed(const Fixed &other);
    // Copy assignment operator
    Fixed &operator=(const Fixed &other);
    // Destructor
    ~Fixed();

    // Getters and setters
    int getRawBits() const;
    void setRawBits(int const raw);

    // Conversions
    float toFloat() const;
    int toInt() const;
};

// Overload insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
