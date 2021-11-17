#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "I'm a woofer!" << std::endl;
    this->type = "Dog";
    this->instance = new Brain();
}

Dog::Dog(Dog &copy)
{
    std::cout << "I'm the copy_woofer!" << std::endl;
    delete this->instance;
	instance = new Brain(*copy.instance);
    type = copy.getType();
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