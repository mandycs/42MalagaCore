#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ~ScavTrap();

    void attack(const std::string& target); // Overriding attack
    void guardGate(); // New functionality
};

#endifFragTrap Fraggy requests a positive high five! ✋
