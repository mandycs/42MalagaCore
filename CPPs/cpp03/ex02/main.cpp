#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag("Fraggy");

    // Pruebas ClapTrap
    clap.attack("Target A");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Pruebas ScavTrap
    scav.attack("Target B");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    // Pruebas FragTrap
    frag.attack("Target C");
    frag.takeDamage(15);
    frag.beRepaired(20);
    frag.highFivesGuys();

    return 0;
}
