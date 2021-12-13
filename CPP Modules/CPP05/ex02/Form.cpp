#include "Form.hpp"

Form::Form(const std::string &name, int const gradeToSign, int const gradeToExec): _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    this->_signed = false;
    if(gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    else if(gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(Form const & copy): _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec), _signed(copy._signed)
{
    this->_signed = false;
    if(_gradeToSign < 1 || _gradeToExec < 1)
        throw Form::GradeTooHighException();
    else if(_gradeToSign > 150 || _gradeToExec > 150)
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "FormException: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "FormException: Grade too Low";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "FormException: The Form is already signed";
}

Form &Form::operator=(Form const &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string const &Form::getName() const
{
    return(this->_name);
}

bool Form::getSigned() const
{
    return(this->_signed);
}

int Form::getGradeSign() const
{
    return(this->_gradeToSign);
}

int Form::getGradeExec() const
{
    return(this->_gradeToExec);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if(bureaucrat.getGrade() > this->getGradeSign())
        throw Form::GradeTooLowException();
    else if(this->_signed)
        throw Form::FormAlreadySignedException();
    this->_signed = true;
}

std::ostream& operator<<(std::ostream & os, Form const & i)
{
	return(os << i.getName() + ", level needed to execute: " << i.getGradeExec() << ", level needed to sign: " << i.getGradeSign() << " Signed: " << i.getSigned());
}