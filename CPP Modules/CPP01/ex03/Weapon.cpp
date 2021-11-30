#include "Weapon.hpp"

Weapon::            Weapon(std::string weap)
{
    setType(weap);
    return;
}

Weapon::            ~Weapon()
{
}

void    Weapon::    setType(std::string thing)
{
    this->type = thing;
    return;
}

std::string Weapon::getType()
{
    return(this->type);
}