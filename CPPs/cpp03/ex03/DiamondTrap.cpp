#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    hitPoints = FragTrap::hitPoints; // Hit points de FragTrap
    energyPoints = ScavTrap::energyPoints; // Energy points de ScavTrap
    attackDamage = FragTrap::attackDamage; // Attack damage de FragTrap
    std::cout << "DiamondTrap " << this->name << " has been created!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name
            << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
