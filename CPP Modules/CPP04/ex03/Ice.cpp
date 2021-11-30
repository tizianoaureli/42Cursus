#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
}

Ice::Ice(const Ice& copy) : AMateria(copy.getType())
{	
}

Ice& Ice::operator= (const Ice& uguale)
{
	this->type = uguale.getType();
	return *this;
}

Ice* Ice::clone() const
{
	Ice *ice = new Ice(*this);
	return ice;
}

Ice::~Ice()
{
}

void Ice::use(ICharacter& target)
{
	std::cout << "A snowball has been thrown at " + target.getName() << std::endl;
}