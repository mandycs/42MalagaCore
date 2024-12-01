#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");

    clap.attack("Target A");
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.attack("Target B");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    return 0;
}
