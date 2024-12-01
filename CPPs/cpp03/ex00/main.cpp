#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Clappy");

    robot.attack("Target");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.attack("Another Target");
    robot.takeDamage(10);
    robot.beRepaired(5);

    return 0;
}
