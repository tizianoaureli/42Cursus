#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* instance;
	public:
		Dog();
		Dog(Dog &copy);
		virtual ~Dog();

		Dog             &operator= (Dog & uguale);
		void            makeSound() const;
};

#endif