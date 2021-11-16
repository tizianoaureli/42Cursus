#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
    
public:
    WrongCat();
    WrongCat(WrongCat &copy);
    ~WrongCat();

    WrongCat    &operator= (WrongCat & uguale);
    void        makeSound() const;
};

#endif