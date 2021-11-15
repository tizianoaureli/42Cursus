#include "DiamondTrap.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    DiamondTrap solaire("Solaire");
    DiamondTrap lautrec("Lautrec");
    int random = 0;

    srand((unsigned int)time(NULL));
    std::cout << solaire.getName() << " challenged " << lautrec.getName() << " to a duel! " << solaire.getName() << " will strike first!" << std::endl;
    while(1)
    {
        random = (rand() % 11);
        solaire.setAttack(random);
        std::cout << "\x1B[33m";
        solaire.attack(lautrec.getName());
        std::cout << "\x1B[34m";
        lautrec.takeDamage(random);
        if(lautrec.getHitP() <= 0)
        {
            std::cout << lautrec.getName() << " \x1B[31mhas been vanquished!\033[0m " << solaire.getName() << " has won the duel!" << std::endl;
            break;
        }
        random = (rand() % 11);
        lautrec.setAttack(random);
        std::cout << "\x1B[34m";
        lautrec.attack(solaire.getName());
        std::cout << "\x1B[33m";
        solaire.takeDamage(random);
        if(solaire.getHitP() <= 0)
        {
            std::cout << solaire.getName() << " \x1B[31mhas been vanquished!\033[0m " << lautrec.getName() << " has won the duel!" << std::endl;
            break;
        }
        std::cout << "\x1B[32mIt's time to heal!\033[0m" << std::endl;
        random = (rand() % 11);
        std::cout << "\x1B[33m";
        solaire.beRepaired(random);
        random = (rand() % 11);
        std::cout << "\x1B[34m";
        lautrec.beRepaired(random);
    }
    solaire.highFivesGuys();
    lautrec.highFivesGuys();
    solaire.whoAmI();
    lautrec.whoAmI();
    return 0;
}