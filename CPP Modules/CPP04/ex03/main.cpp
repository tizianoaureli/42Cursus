#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Me");
	AMateria* tmp;
	tmp = src->createMateria("Maurice");
	tmp = src->createMateria("Ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("Cure");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("Ice");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("Cure");
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("Cure");
	me->equip(tmp);
	delete tmp;
	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	ICharacter* ben(me);
	ben->use(0, *me);
	me->unequip(2);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}