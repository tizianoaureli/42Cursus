#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *heapzombo = new Zombie;

    heapzombo->setName(name);
    return (heapzombo);
}