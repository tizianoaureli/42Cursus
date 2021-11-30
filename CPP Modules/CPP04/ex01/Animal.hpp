#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal &copy);
		virtual ~Animal();

		Animal          &operator= (Animal & uguale);
		virtual void    makeSound() const;
		std::string     getType()   const;
};

#endif