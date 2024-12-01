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

    return 0;
}
