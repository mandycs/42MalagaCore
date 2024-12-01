#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    ~Ice();

    AMateria* clone() const; // Clonar un objeto Ice
    void use(ICharacter& target); // Usar Ice
};

#endif
