#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();

    virtual void makeSound() const = 0; // Método virtual puro
    std::string getType() const;
};

#endif
