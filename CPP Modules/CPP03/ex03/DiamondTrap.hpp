#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
    int         _hitpoints;
    int         _energypoints;
    int         _attkdamage;
public:
    DiamondTrap();
    DiamondTrap(std::string aname);
    ~DiamondTrap();

    void whoAmI();
};

#endif