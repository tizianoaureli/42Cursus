#include "ClapTrap.hpp"
#include <cstdlib>

int main()
{
    ClapTrap solaire("Solaire");
    ClapTrap lautrec("Lautrec");

    srand((unsigned int)time(NULL));
    std::cout << solaire.getName() << " challenged " << lautrec.getName() << " to a duel! " << solaire.getName() << " will strike first!" << std::endl;
    solaire.attack(lautrec.getName());
    lautrec.takeDamage(solaire.getAttack());
    lautrec.attack(solaire.getName());
    solaire.takeDamage(lautrec.getAttack());
    return 0;
}