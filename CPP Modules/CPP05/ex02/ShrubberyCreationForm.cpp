#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("Shrubbery", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): Form(copy), target(copy.target)
{
}

void ShrubberyCreationForm::_execute(Bureaucrat const & executor)
{
    std::ofstream treeFile;

    if(executor.getGrade() > this->_gradeToExec)
        std::cout << "Cannot execute form, grade too low" << std::endl;
    else
    {
        treeFile.open(this->target + "_shrubbery");
        if(treeFile.is_open())
        {
            treeFile << "          &&& &&  & &&" << std::endl;
            treeFile << "      && &\/&\|& ()|/ @, &&" << std::endl;
            treeFile << "      &\/(/&/&||/& /_/)_&/_&" << std::endl;
            treeFile << "   &() &\/&|()|/&\/ '%' & ()" << std::endl;
            treeFile << "  &_\_&&_\ |& |&&/&__%_/_& &&" << std::endl;
            treeFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
            treeFile << " ()&_---()&\&\|&&-&&--%---()~" << std::endl;
            treeFile << "     &&     \|||" << std::endl;
            treeFile << "             |||" << std::endl;
            treeFile << "             |||" << std::endl;
            treeFile << "             |||" << std::endl;
            treeFile << "       , -=-~  .-^- _" << std::endl;
        }
        else
            std::cout << "Cannot open file" << std::endl;
    }
}
