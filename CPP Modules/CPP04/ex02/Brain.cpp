#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &copy)
{
    for(int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "Brain copy" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain &uguale)
{
    if (this == &uguale)
		return (*this);
	for(int i = 0; i < 100; i++)
		ideas[i] = uguale.ideas[i];
	std::cout << "Brain operator" << std::endl;
	return(*this);
}