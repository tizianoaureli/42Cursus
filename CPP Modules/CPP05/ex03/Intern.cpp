#include "Intern.hpp"

Intern::Intern()
{
	this->arr[0] = "shrubbery";
	this->arr[1] = "robotomy";
	this->arr[2] = "presidential";
}

Intern::~Intern()
{
}

void Intern::getCase(std::string caso)
{
    std::string toComp;
    toComp = caso;
    for(int i = 0; i < (int)toComp.size(); i++)
        tolower(toComp[i]);
	int i = 0;
	for ( ; i < 3; i++)
    {
        size_t found = toComp.find(this->arr[i]);
		if (found != std::string::npos)
			break;
    }
	switch (i)
	{
	case 0:
		this->tipo = Shrubbery;
		break;
	case 1:
		this->tipo = Robotomy;
		break;
	case 2:
		this->tipo = Presidential;
		break;
	default:
		this->tipo = DEFAULT;
		break;
	}
}

Form * Intern::makeForm(std::string formName, std::string target)
{
	getCase(formName);
	switch (tipo)
	{
	case Shrubbery:
		std::cout << "Intern create a Shrubbery" << std::endl;
		return(new ShrubberyCreationForm(target));
	case Robotomy:
		std::cout << "Intern create a Robotomy" << std::endl;
		return(new RobotomyRequestForm(target));
	case Presidential:
		std::cout << "Intern create a Pardon" << std::endl;
		return(new PresidentialPardonForm(target));
	case DEFAULT:
		throw FormNotFound();
	}
}

const char* Intern::FormNotFound::what() const throw()
{
	return "Form not found";
}

