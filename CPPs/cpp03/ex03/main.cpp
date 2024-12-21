#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Diamondy");

    diamond.attack("Target");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.whoAmI();

    DiamondTrap d;

    d = diamond;
    d.attack("Target");
    d.takeDamage(30);
    d.beRepaired(20);
    d.whoAmI();


    return 0;
}
