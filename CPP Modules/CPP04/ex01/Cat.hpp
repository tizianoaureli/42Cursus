#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain* instance;
    public:
        Cat();
        Cat(Cat &copy);
        virtual ~Cat();

        Cat             &operator= (Cat & uguale);
		void            makeSound() const;
};

#endif