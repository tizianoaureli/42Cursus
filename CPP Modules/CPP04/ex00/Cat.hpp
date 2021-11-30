#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(Cat &copy);
        ~Cat();

        Cat             &operator= (Cat & uguale);
		void            makeSound() const;
};

#endif