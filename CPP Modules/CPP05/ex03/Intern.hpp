#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

enum tipoForm
{
    Shrubbery,
    Robotomy,
    Presidential,
    DEFAULT
};

class Intern
{
private:
    tipoForm tipo;
    std::string arr[3];
public:
    Intern();
    ~Intern();

    void getCase(std::string formCase);
    Form* makeForm(std::string formName, std::string const target);
    class FormNotFound : public std::exception
    {
        virtual const char* what() const throw();
    };
};
