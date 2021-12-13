#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	
	Bureaucrat nic("Nicco", 1);
	Bureaucrat ben("Benjo", 135);
	Bureaucrat tiz("Tiziano", 20);
	Bureaucrat val("Valerio", 150);
	Form *x = new ShrubberyCreationForm("home");
	Form *y = new RobotomyRequestForm("Jesus");
	Form *z = new PresidentialPardonForm("Paoletto");
	std::cout << "|" << z->getName() << "|" << std::endl;
	std::cout << nic << std::endl;
	std::cout << ben << std::endl;
	std::cout << tiz << std::endl;
	std::cout << val << std::endl;
	std::cout << *x << std::endl;
	std::cout << *y << std::endl;
	std::cout << *z << std::endl;
	//Form g("Request", 1, 1);
	try
	{
		val.executeForm(*x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		nic.executeForm(*x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		nic.signForm(*x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		nic.signForm(*y);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		nic.signForm(*z);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		val.executeForm(*x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ben.executeForm(*x);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		ben.executeForm(*y);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{	
		tiz.executeForm(*y);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tiz.executeForm(*z);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		nic.executeForm(*z);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}