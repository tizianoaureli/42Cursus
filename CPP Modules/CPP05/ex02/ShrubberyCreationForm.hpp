#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "fstream"

class ShrubberyCreationForm: public Form
{
private:
    std::string target;
public:
    ShrubberyCreationForm(std::string const &target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &copy);

    ShrubberyCreationForm   &operator=(ShrubberyCreationForm & uguale);
    void                    _execute(Bureaucrat const & executor);
};

#endif