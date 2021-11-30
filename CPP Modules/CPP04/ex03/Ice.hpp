#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice & copy);
		Ice& operator= (const Ice& uguale);
		Ice* clone() const;
		~Ice();
		void use(ICharacter& target);
};



#endif
