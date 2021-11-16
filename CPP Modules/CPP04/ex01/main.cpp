#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Dog* dog = new Dog();
	Dog* copy_dog = new Dog(*dog);

	delete dog;

	std::cout << std::endl;
	std::cout << copy_dog->getType() << std::endl;
	copy_dog->makeSound();
	std::cout << std::endl;

	delete copy_dog;

	Animal* animals[5];

	for (int i = 0; i < 5; i++) 
    {
		if (i < 5)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl;
	for (int i = 0; i < 5; i++) 
    {
		std::cout << i << ": " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
		delete animals[i];
    return 0;
}