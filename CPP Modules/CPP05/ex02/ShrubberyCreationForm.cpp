#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("Shrubbery", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): Form(copy), target(copy.target)
{
    *this = copy;
}

const char* ShrubberyCreationForm::TargetFileOpenException::what() const throw()
{
	return "ShrubberyCreationFormException: Cannot open file";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & uguale)
{
    Form::operator=(uguale);
	this->_signed = uguale._signed;
	return (*this);
}

void ShrubberyCreationForm::_execute(Bureaucrat const & executor) const
{
    std::ofstream treeFile;

    if(executor.getGrade() < this->getGradeExec())
    {
        treeFile.open(this->target + "_shrubbery");
        if(treeFile.is_open())
        {
            treeFile << "          &&& &&  & &&" << std::endl;
            treeFile << "      && & /& |& ()|/ @, &&" << std::endl;
            treeFile << "      & /(/&/&||/& /_/)_&/_&" << std::endl;
            treeFile << "   &() & /&|()|/& / '%' & ()" << std::endl;
            treeFile << "  &_ _&&_  |& |&&/&__%_/_& &&" << std::endl;
            treeFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
            treeFile << " ()&_---()& & |&&-&&--%---()~" << std::endl;
            treeFile << "     &&      |||" << std::endl;
            treeFile << "             |||" << std::endl;
            treeFile << "             |||" << std::endl;
            treeFile << "             |||" << std::endl;
            treeFile << "       , -=-~  .-^- _" << std::endl;
        }
        else
            throw TargetFileOpenException();
        treeFile.close();
    }
}
