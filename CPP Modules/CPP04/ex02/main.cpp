#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //Animal a; 			//Since it's an absrtact class, it cannot be instanciated
	Cat c;
	Dog d;

	std::cout << "There are 2 animals in here: the " << d.getType() << " and the " << c.getType() << std::endl;
	d.makeSound();
	c.makeSound();
}