#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
private:
    Bureaucrat();

    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    virtual ~Bureaucrat();

    class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

    Bureaucrat & operator= (const Bureaucrat &uguale);

    std::string const &getName() const;
	int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form) const;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif