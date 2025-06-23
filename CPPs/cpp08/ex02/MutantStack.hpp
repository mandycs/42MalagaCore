#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Tipos de iterators - usando el contenedor subyacente
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Constructor por defecto
    MutantStack() : std::stack<T>() {}
    
    // Constructor de copia
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    
    // Operador de asignación
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }
    
    // Destructor
    ~MutantStack() {}
    
    // Iterators - acceso al contenedor subyacente
    iterator begin() {
        return this->c.begin();
    }
    
    iterator end() {
        return this->c.end();
    }
    
    const_iterator begin() const {
        return this->c.begin();
    }
    
    const_iterator end() const {
        return this->c.end();
    }
    
    // Reverse iterators
    reverse_iterator rbegin() {
        return this->c.rbegin();
    }
    
    reverse_iterator rend() {
        return this->c.rend();
    }
    
    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    
    const_reverse_iterator rend() const {
        return this->c.rend();
    }
};

#endif