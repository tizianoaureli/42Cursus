#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
}

Cure::Cure(const Cure& copy) : AMateria(copy.getType())
{	
}

Cure& Cure::operator= (const Cure* uguale)
{
	this->type = uguale->getType();
	return *this;
}

Cure* Cure::clone() const
{
	Cure *cure = new Cure(*this);
	return cure;
}

Cure::~Cure()
{
}

void Cure::use(ICharacter& target)
{
	std::cout << target.getName() << "'s wound has been healed" << std::endl;
}