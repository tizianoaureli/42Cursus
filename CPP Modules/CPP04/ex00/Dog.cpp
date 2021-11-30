#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "I'm a woofer!" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog &copy)
{
    *this = copy;
}

Dog::~Dog()
{
    std::cout << "See ya, woof!" << std::endl;
}

Dog & Dog::operator=(Dog &uguale)
{
    this->type = uguale.type;
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;
    return ;
}