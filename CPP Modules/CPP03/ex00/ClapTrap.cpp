#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap has been called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap has been destroyed." << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
    std::cout << "Claptrap " << this->_name << "\033[0m attacks " << target << ", causing " << this->_atckdamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount >= 1 && amount <= 3)
        std::cout << "ClapTrap " << this->_name << "\033[0m has taken " << amount << " points of damage! 'Tis but a scratch!" << std::endl;
    else if(amount >= 4 && amount <= 7)
        std::cout << "ClapTrap " << this->_name << "\033[0m has taken " << amount << " points of damage! Ouch, it hurts!" << std::endl;
    else if(amount >= 8 && amount <= 10)
        std::cout << "ClapTrap " << this->_name << "\033[0m has taken " << amount << " points of damage! GAWD! HE NEED SOME MILK!" << std::endl;
    else if(amount == 0)
        std::cout << "ClapTrap " << this->_name << "\033[0m dodged the attack!" << std::endl;
    this->_hitpoints -= amount;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hitpoints += amount;
    if(this->_hitpoints > 10)
        this->_hitpoints = 10;
    std::cout << "Claptrap " << this->_name << "\033[0m is drinking an \x1B[32mestus\033[0m! His hitpoints are now at " << this->_hitpoints << " points!" << std::endl;
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