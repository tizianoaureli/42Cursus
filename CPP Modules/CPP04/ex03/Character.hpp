#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventario[4];
	public:
		Character(const std::string &name);
		Character(Character& copy);
		Character& operator= (Character& uguale);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* materia);
		void unequip(int indice);
		void use(int indice, ICharacter& target);
};

#endif