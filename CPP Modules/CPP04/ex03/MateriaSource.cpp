#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		arr[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &copy)
{
	*this = copy;
}

MateriaSource& MateriaSource::operator= (MateriaSource& uguale)
{
	for(int i = 0; i < 4; i++)
		arr[i] = uguale.arr[i]->clone();
	return(*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for(int i = 0; i < 4; i++)
	{
		if(!arr[i])
		{
			arr[i] = materia->clone();
			std::cout << "Materia " + materia->getType() + " has been learned at index: " << i << std::endl;
			if (materia)
				delete materia;
			return;
		}
	}
	if (materia)
		delete materia;
	std::cout << "Full slots" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if(arr[i] != NULL)
			if(arr[i]->getType() == type)
				return (arr[i]->clone());
	}
	std::cout << "Materia not found\n";
	return NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if(arr[i])
			delete arr[i];
	}
}