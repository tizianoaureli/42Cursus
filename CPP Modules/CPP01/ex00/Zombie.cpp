#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << getName() << " has been killed" << std::endl;
}

std::string Zombie::getName()
{
    return (this->name);
}

void Zombie::setName(std::string str)
{
    this->name = str;
    return;
}

void Zombie::announce()
{
    std::cout << getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}