#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
    if(this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): name(copy.name), grade(copy.grade)
{
    if(this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
	*this = copy;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "BureaucratException: Grade too High.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "BureaucratException: Grade too Low.";
}

const char* Bureaucrat::GradeLowExecException::what() const throw()
{
    return "BureaucratException: Grade too Low to Execute form.";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &uguale)
{
	this->grade = uguale.grade;
	return (*this);
}

std::string const &Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "Bureaucrat " << bureaucrat.getName() << " (Grade " << bureaucrat.getGrade() << ")";
	return (out);
}

void Bureaucrat::signForm(Form &form) const
{
	if(form.getSigned())
		std::cout << *this << " cannot sign " << form << " because the form is already signed." << std::endl;
	else if (this->grade > form.getGradeSign())
		std::cout << *this << " cannot sign " << form << " because the grade is too low." << std::endl;
	else
		std::cout << *this << " signs " << form << std::endl;
	form.beSigned(*this);
}
void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form._execute(*this);
		std::cout << this->getName() + " executes the form " + form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << getName() << " cannot execute form, because " << e.what() << '\n';
	}
}