#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("Presidential", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): Form(copy), target(copy.target)
{
    *this = copy;
}

std::string PresidentialPardonForm::getNameTarg()
{
    return(this->target);
}

void PresidentialPardonForm::_execute(Bureaucrat const & target) const
{
    if(target.getGrade() < this->getGradeExec())
    {
        std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    }
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & uguale)
{
    Form::operator=(uguale);
	this->_signed = uguale._signed;
	return (*this);
}