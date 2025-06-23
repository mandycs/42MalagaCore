#ifndef ITER_HPP
#define ITER_HPP

// Template function iter: aplica una función a cada elemento de un array
template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

// Versión que maneja arrays const
template <typename T, typename F>
void iter(const T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}

#endif