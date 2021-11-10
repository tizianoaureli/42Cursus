#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Character: " << name << " has been created!" << std::endl;
    this->_name = name;
    this->_energypoints = 10;
    this->_hitpoints = 10;
    this->_atckdamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << " has vanished." << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing " << this->_atckdamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount >= 1 && amount <= 3)
        std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage! 'Tis but a scratch!" << std::endl;
    else if(amount >= 4 && amount <= 7)
        std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage! Ouch, it hurts!" << std::endl;
    else if(amount >= 8 && amount <= 10)
        std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage! GAWD! HE NEED SOME MILK!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitpoints += amount;
    if(this->_hitpoints > 10)
        this->_hitpoints = 10;
    std::cout << "Claptrap " << this->_name << " is drinking a potion! His hitpoints are now at " << this->_hitpoints << " points!" << std::endl;
}

void ClapTrap::setAttack(int amount)
{
    this->_atckdamage = amount;
}

int ClapTrap::getAttack()
{
    return(this->_atckdamage);
}

int ClapTrap::getHitP()
{
    return(this->_hitpoints);
}

int ClapTrap::getEnergyH()
{
    return(this->_energypoints);
}

std::string ClapTrap::getName()
{
    return(this->_name);
}