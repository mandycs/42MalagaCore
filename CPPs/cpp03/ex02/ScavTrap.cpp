#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << "ScavTrap " << name << " fiercely attacks " << target
                << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ScavTrap " << name << " cannot attack, insufficient energy or hit points!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
