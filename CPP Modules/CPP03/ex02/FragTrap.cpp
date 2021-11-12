#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    std::cout << "Character: " << name << " has been created!" << std::endl;
    this->_name = name;
    this->_energypoints = 100;
    this->_hitpoints = 100;
    this->_atckdamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << "\033[0m has vanished." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "HEY HEY I'm " << this->_name << "! Wanna high five? C'mon hi-five me bro.. pls.. No one?" << std::endl;
}