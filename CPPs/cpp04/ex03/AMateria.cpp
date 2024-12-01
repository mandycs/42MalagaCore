#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "Using materia on " << target.getName() << std::endl;
}
