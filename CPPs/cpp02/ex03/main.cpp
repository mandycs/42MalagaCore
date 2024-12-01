#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point insidePoint(5.0f, 5.0f);
    Point outsidePoint(15.0f, 5.0f);
    Point edgePoint(5.0f, 0.0f);

    std::cout << "Is insidePoint inside the triangle? " << (bsp(a, b, c, insidePoint) ? "Yes" : "No") << std::endl;
    std::cout << "Is outsidePoint inside the triangle? " << (bsp(a, b, c, outsidePoint) ? "Yes" : "No") << std::endl;
    std::cout << "Is edgePoint inside the triangle? " << (bsp(a, b, c, edgePoint) ? "Yes" : "No") << std::endl;

    return 0;
}
