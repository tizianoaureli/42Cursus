#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        int         _hitpoints;
        int         _energypoints;
        int         _atckdamage;
    public:
        ClapTrap();
        ClapTrap(const std::string name);
        ClapTrap(ClapTrap &copy);
        ~ClapTrap();

        ClapTrap &operator= (ClapTrap & uguale);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void setAttack(int amount);
        int getAttack();
        int getHitP();
        int getEnergyH();
        std::string getName();
};

#endif