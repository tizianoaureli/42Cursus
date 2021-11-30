#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string aname);
    ~HumanB();
    
    void        setName(std::string aname);
    std::string getName();
    void        setWeapon(Weapon &thing);
    void        attack();
};

#endif