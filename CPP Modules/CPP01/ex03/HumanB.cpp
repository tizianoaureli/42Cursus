#include "HumanB.hpp"

HumanB::HumanB(std::string aname)
{
    setName(aname);
    return;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon &thing)
{
    this->weapon = &thing; 
}

void    HumanB::setName(std::string aname)
{
    this->name = aname;
}

std::string HumanB::getName()
{
    return(this->name);
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with" << this->weapon->getType() << std::endl;
    return;
}