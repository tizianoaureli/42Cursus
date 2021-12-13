#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
    std::string target;
public:
    RobotomyRequestForm(std::string const &target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(RobotomyRequestForm const &copy);

    RobotomyRequestForm &operator=(RobotomyRequestForm const & uguale);
    void                    _execute(Bureaucrat const & executor) const;
};

#endif                