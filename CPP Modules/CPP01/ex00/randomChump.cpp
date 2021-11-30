#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie stackzombo;

    stackzombo.setName(name);
    stackzombo.announce();
    return;
}