#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;
    int         _hitpoints;
    int         _energypoints;
    int         _attkdamage;
public:
    DiamondTrap();
    DiamondTrap(std::string aname);
    DiamondTrap(DiamondTrap &copy);
    ~DiamondTrap();

    void whoAmI();
    void attack(std::string target);
    DiamondTrap &operator= (DiamondTrap & uguale);
};

#endif