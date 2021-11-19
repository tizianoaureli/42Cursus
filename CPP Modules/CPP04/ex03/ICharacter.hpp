#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include <iostream>
#include <string>

class ICharacter
{
private:
    std::string type;
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* materia) = 0;
    virtual void unequip(int indice) = 0;
    virtual void use(int indice, ICharacter& target) = 0;
};

#endif