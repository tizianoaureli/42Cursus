#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    this->_name = "Magaduscio";
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energypoints = ScavTrap::_energypoints;
    this->_atckdamage = FragTrap::_atckdamage;
    std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string aname) : ScavTrap(aname), FragTrap(aname)
{
    this->_name = aname;
    this->_hitpoints = FragTrap::_hitpoints;
    this->_energypoints = ScavTrap::_energypoints;
    this->_atckdamage = FragTrap::_atckdamage;
    std::cout << "DiamondTrap " << this->_name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &copy)
{
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " has vanished" << std::endl;
}

void DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}

DiamondTrap & DiamondTrap::operator= (DiamondTrap &uguale)
{
	this->_name = uguale._name;
	this->_hitpoints = uguale._hitpoints;
	this->_energypoints = uguale._energypoints;
	this->_atckdamage = uguale._atckdamage;

	return(*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is: " << this->_name << " and my ClapTrap name is " << this->getName() + "_clap_name" << std::endl;
}
