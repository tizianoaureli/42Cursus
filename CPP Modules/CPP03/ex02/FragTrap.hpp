#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap & copy);
    ~FragTrap();

    FragTrap &operator= (FragTrap & uguale);

    void highFivesGuys(void);
    void attack(std::string target);
};

#endif