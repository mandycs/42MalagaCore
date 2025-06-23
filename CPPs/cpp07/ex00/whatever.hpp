#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Template function swap: intercambia los valores de dos parámetros
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Template function min: retorna el menor de dos valores
// Si son iguales, retorna el segundo
template <typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// Template function max: retorna el mayor de dos valores
// Si son iguales, retorna el segundo
template <typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif