#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
    std::string target;
public:
    PresidentialPardonForm(std::string const &target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &copy);

    PresidentialPardonForm  &operator=(PresidentialPardonForm const & uguale);
    void                    _execute(Bureaucrat const & executor) const;
    std::string             getNameTarg();
};

#endif