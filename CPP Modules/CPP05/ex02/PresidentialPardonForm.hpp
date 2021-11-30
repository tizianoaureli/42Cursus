#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &copy);

    PresidentialPardonForm  &operator=(PresidentialPardonForm & uguale);
    void                    _execute(Bureaucrat const & executor);
};

#endif