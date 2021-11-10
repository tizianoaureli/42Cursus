#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Character: " << name << " has been created!" << std::endl;
    this->_name = name;
    this->_energypoints = 50;
    this->_hitpoints = 100;
    this->_atckdamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << "\033[0m has vanished." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode." << std::endl;
}