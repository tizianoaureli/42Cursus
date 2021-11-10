#include "Zombie.hpp"

int main()
{
    Zombie *zombo;

    zombo = newZombie("Gustavo");
    zombo->announce();
    randomChump("Lamazza");
    delete (zombo);
    return (0);
}