#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void basicTest() {
    std::cout << "\n=== Basic Test ===\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void fullInventoryTest() {
    std::cout << "\n=== Full Inventory Test ===\n";
    ICharacter* hero = new Character("Hero");

    // Crear materias
    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* extra = new Ice();

    // Llenar inventario
    hero->equip(ice1);
    hero->equip(ice2);
    hero->equip(cure1);
    hero->equip(cure2);

    // Intentar equipar una materia adicional
    std::cout << "Attempting to equip extra materia:\n";
    hero->equip(extra); // Esto no debe afectar el inventario

    // Usar todas las materias
    for (int i = 0; i < 4; ++i) {
        hero->use(i, *hero);
    }

    // Limpiar memoria
    delete hero;
    delete extra; // Asegurarse de eliminar el extra no equipado
}

void unequipTest() {
    std::cout << "\n=== Unequip Test ===\n";
    ICharacter* mage = new Character("Mage");

    // Equipar materias
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    mage->equip(ice);
    mage->equip(cure);

    // Usar materias antes de unequip
    std::cout << "Before unequip:\n";
    mage->use(0, *mage);
    mage->use(1, *mage);

    // Des-equipar materias
    mage->unequip(0);
    mage->unequip(1);

    // Intentar usar materias después de unequip
    std::cout << "After unequip:\n";
    mage->use(0, *mage);
    mage->use(1, *mage);

    // Limpiar memoria manualmente después de unequip
    delete ice;
    delete cure;
    delete mage;
}

void deepCopyTest() {
    std::cout << "\n=== Deep Copy Test ===\n";
    Character* original = new Character("Original");
    original->equip(new Ice());
    original->equip(new Cure());

    // Crear una copia profunda
    Character* copy = new Character(*original);

    // Usar materias en ambos personajes
    std::cout << "Using materias in original:\n";
    original->use(0, *original);
    original->use(1, *original);

    std::cout << "Using materias in copy:\n";
    copy->use(0, *copy);
    copy->use(1, *copy);

    // Destruir ambos personajes
    delete original;
    delete copy;
}

void invalidMateriaTest() {
    std::cout << "\n=== Invalid Materia Test ===\n";
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    // Intentar crear una materia no aprendida
    AMateria* invalid = src->createMateria("fire");
    if (!invalid) {
        std::cout << "Failed to create materia of type 'fire' (as expected).\n";
    }

    delete src;
}

int main() {
    basicTest();
    fullInventoryTest();
    unequipTest();
    deepCopyTest();
    invalidMateriaTest();

    return 0;
}
