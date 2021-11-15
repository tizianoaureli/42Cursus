#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &copy);
    ~ScavTrap();

    void guardGate();
    void attack(std::string target);
	ScavTrap &operator= (ScavTrap & uguale);
};

#endif