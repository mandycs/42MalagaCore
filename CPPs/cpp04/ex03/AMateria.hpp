#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string type;

public:
    AMateria(const std::string& type);
    virtual ~AMateria();

    const std::string& getType() const; // Devuelve el tipo de materia

    virtual AMateria* clone() const = 0; // Método puro para clonar
    virtual void use(ICharacter& target); // Usar la materia
};

#endif
