#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "I'm a meower!" << std::endl;
    this->type = "Cat";
    this->instance = new Brain();
}

Cat::Cat(Cat &copy)
{
    std::cout << "I'm the copy_meower!" << std::endl;
    delete this->instance;
	instance = new Brain(*copy.instance);
    type = copy.getType();
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