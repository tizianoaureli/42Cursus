#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "*Some undistinguished noises* I'm an WrongAnimal. *BLURFG*" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
    *this = copy;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "I'm not allowed to live anymore, bye." << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal &uguale)
{
    this->type = uguale.type;
    return(*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "*Angry WrongAnimal screeching*" << std::endl;
    return ;
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}