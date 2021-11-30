#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string weap);
    ~Weapon();

    std::string getType();
    void        setType(std::string thing);
};

#endif