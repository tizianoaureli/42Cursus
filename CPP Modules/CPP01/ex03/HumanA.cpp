#include "HumanA.hpp"

HumanA::HumanA(std::string aname, Weapon &weap) : weapon(weap)
{
    this->weapon = weap;
    this->name = aname;
    return;
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
    return;
}