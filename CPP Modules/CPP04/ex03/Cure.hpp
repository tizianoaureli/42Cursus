#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& copy);
		Cure& operator= (const Cure * uguale);
		Cure* clone() const;
		~Cure();
		void use(ICharacter& target);
};

class Cure
{
private:
	/* data */
public:
	Cure(/* args */);
	~Cure();
};

#endif