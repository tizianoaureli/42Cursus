#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ST Character: " << this->getName() << " has been created!" << std::endl;
    this->_name = this->getName();
    this->_energypoints = 50;
    this->_hitpoints = 100;
    this->_atckdamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ST Character: " << this->getName() << " has been created!" << std::endl;
    this->_name = name;
    this->_energypoints = 50;
    this->_hitpoints = 100;
    this->_atckdamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
	*this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << "\033[0m has vanished." << std::endl;
}

ScavTrap & ScavTrap::operator= (ScavTrap &uguale)
{
	this->_name = uguale._name;
	this->_hitpoints = uguale._hitpoints;
	this->_energypoints = uguale._energypoints;
	this->_atckdamage = uguale._atckdamage;

	return(*this);
}

void ScavTrap::attack(std::string target)
{
	std::cout << "ScavTrap " << _name << " attacks " << target << " dealing " << _atckdamage << " points of damage." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode." << std::endl;
}