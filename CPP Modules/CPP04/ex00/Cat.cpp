#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "I'm a meower!" << std::endl;
    this->type = "Cat";
}

Cat::Cat(Cat &copy)
{
    *this = copy;
}

Cat::~Cat()
{
    std::cout << "Feed me and leave me be, meower!" << std::endl;
}

Cat & Cat::operator=(Cat &uguale)
{
    this->type = uguale.type;
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow moew mothaf- *hissing*" << std::endl;
    return ;
}