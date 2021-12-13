#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Character: " << name << " has been created! (ClapTrap Constructor)" << std::endl;
    this->_name = name;
    this->_energypoints = 10;
    this->_hitpoints = 10;
    this->_atckdamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	*this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << this->_name << "\033[0m has vanished. (ClapTrap destructor)" << std::endl;
}

ClapTrap & ClapTrap::operator= (ClapTrap &uguale)
{
	this->_name = uguale._name;
	this->_hitpoints = uguale._hitpoints;
	this->_energypoints = uguale._energypoints;
	this->_atckdamage = uguale._atckdamage;

	return(*this);
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
    else if(amount >= 8 && amount <= 9)
        std::cout << "ClapTrap " << this->_name << "\033[0m has taken " << amount << " points of damage! GAWD! HE NEED SOME MILK!" << std::endl;
    else if(amount == 10)
        std::cout << "ClapTrap " << this->_name << "\033[0m has taken " << amount << " points of damage! GAWD! HE DED!" << std::endl;
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