#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4]; // Máximo 4 materias

public:
    Character(const std::string& name);
    Character(const Character& other);
    ~Character();

    Character& operator=(const Character& other);

    const std::string& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
