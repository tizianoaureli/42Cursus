#include "Zombie.hpp"

int main()
{
    int numZomb = 0;
    Zombie *horde;

    std::cout << "Number of zombies: ";
    std::cin >> numZomb;
    horde = zombieHorde(numZomb, "Dalisia");
    for(int i = 0; i < numZomb; i++)
        horde[i].announce();
    delete[] horde;
}