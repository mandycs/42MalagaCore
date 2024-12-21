#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("Fraggy")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "FragTrap " << name << " launches an explosive attack on " << target
                << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << name << " cannot attack, insufficient energy or hit points!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
}
