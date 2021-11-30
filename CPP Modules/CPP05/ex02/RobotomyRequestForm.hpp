#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &copy);

    RobotomyRequestForm &operator=(RobotomyRequestForm & uguale);
    void                    _execute(Bureaucrat const & executor);
};

#endif                