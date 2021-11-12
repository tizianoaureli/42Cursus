#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    this->_name = "Magaduscio";
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energypoints = ScavTrap::_energypoints;
    this->_attkdamage = FragTrap::_atckdamage;
}

DiamondTrap::DiamondTrap(std::string aname) : ScavTrap(), FragTrap()
{
    this->_name = aname;
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energypoints = ScavTrap::_energypoints;
    this->_attkdamage = FragTrap::_atckdamage;
}

DiamondTrap::~DiamondTrap()
{
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is: " << this->_name << " and my ClapTrap name is " << this->_name + " "<< std::endl;
}
