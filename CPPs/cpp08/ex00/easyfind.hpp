#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

// Función template easyfind: busca la primera ocurrencia de un valor en un contenedor
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator result = std::find(container.begin(), container.end(), value);
    
    if (result == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    
    return result;
}

// Versión const del easyfind
template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator result = std::find(container.begin(), container.end(), value);
    
    if (result == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    
    return result;
}

#endif