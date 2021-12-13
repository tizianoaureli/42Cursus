#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "*Some undistinguished noises* I'm an animal. *BLURFG*" << std::endl;
    this->type = "Animal";
}

Animal::Animal(Animal &copy)
{
    *this = copy;
}

Animal::~Animal()
{
    std::cout << "I have no wings but I know that, with the power of friendship, I can achieve the impossible! *Animal hits the ground at mach 7 velocity, he ded*" << std::endl;
}

Animal & Animal::operator=(Animal &uguale)
{
    this->type = uguale.type;
    return(*this);
}

std::string Animal::getType() const
{
    return(this->type);
}