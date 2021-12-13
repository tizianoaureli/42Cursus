#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    std::cout << "FragTrap Character: " << name << " has been created!" << std::endl;
    this->_name = name;
    this->_energypoints = 100;
    this->_hitpoints = 100;
    this->_atckdamage = 30;
}

FragTrap::FragTrap(FragTrap & copy)
{
	*this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << "\033[0m has vanished." << std::endl;
}

FragTrap & FragTrap::operator= (FragTrap &uguale)
{
	this->_name = uguale._name;
	this->_hitpoints = uguale._hitpoints;
	this->_energypoints = uguale._energypoints;
	this->_atckdamage = uguale._atckdamage;

	return(*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "HEY HEY I'm " << this->_name << "! Wanna high five? C'mon hi-five me bro.. pls.. No one?" << std::endl;
}

void	FragTrap::attack(std::string target)
{
	std::cout << "FragTrap" << _name << " attacks " << target << ", dealing " << this->_atckdamage << " points of damage." << std::endl;
}