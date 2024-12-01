#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Constructor with two float arguments
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

// Copy assignment operator
Point &Point::operator=(const Point &other) {
    // Since _x and _y are const, we cannot assign to them
    // Assignment operator doesn't make sense here; we can leave it empty or handle appropriately
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {}

// Getters
Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}
