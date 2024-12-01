#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure& other);
    ~Cure();

    Cure& operator=(const Cure& other);

    AMateria* clone() const; // Clonar un objeto Cure
    void use(ICharacter& target); // Usar Cure
};

#endif
