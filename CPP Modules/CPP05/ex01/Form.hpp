#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
class Form;
#include "Bureaucrat.hpp"

class Form
{
private:
    Form();

    std::string const   &_name;
    int const           _gradeToSign;
    int const           _gradeToExec;
    bool                _signed;
public:
    Form(const std::string &name, int const gradeToSign, int const gradeToExec);
    Form(Form const &copy);
    virtual ~Form();

    class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
    class FormAlreadySignedException: public std::exception {
        virtual const char* what() const throw();
    };

    Form & operator=(const Form &uguale);

    std::string const   &getName() const;
	int                 getGradeSign() const;
    int                 getGradeExec() const;
    bool                getSigned() const;
    void                beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif