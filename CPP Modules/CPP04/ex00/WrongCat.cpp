#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "I'm a meower!" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &copy)
{
    *this = copy;
}

WrongCat::~WrongCat()
{
    std::cout << "Feed me and leave me be, meower!" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat &uguale)
{
    this->type = uguale.type;
    return(*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Meow moew mothaf- *hissing*" << std::endl;
    return ;
}