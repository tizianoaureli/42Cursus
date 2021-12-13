#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): Form("Robotomy", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): Form(copy), target(copy.target)
{
    *this = copy;
}

void RobotomyRequestForm::_execute(Bureaucrat const & executor) const
{
    int random = 0;
    srand((unsigned int)time(NULL));

    if(executor.getGrade() < this->getGradeExec())
    {
        random = (rand()%2 + 1);
        std::cout << "bzz bzz bzzzZZZZZ bz bz BZZZZZZZ" << std::endl;
        if(random == 1)
            std::cout << this->target << " has been successfully robotomized." << std::endl;
        else
            std::cout << this->target << " robotomization has been a failure." << std::endl;
    }
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & uguale)
{
    Form::operator=(uguale);
	this->_signed = uguale._signed;
	return (*this);
}