#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria& AMateria::operator= (const AMateria& uguale)
{
	this->type = uguale.type;
	return(*this);
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}