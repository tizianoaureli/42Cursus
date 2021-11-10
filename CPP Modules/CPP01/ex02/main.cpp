#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "Memory address of the string str: " << &str << std::endl;
    std::cout << "Memory address of the string using the pointer: " << &stringPTR << std::endl;
    std::cout << "Memory address of the string using the reference: " << &stringREF << std::endl;
    std::cout << "Content of the string using the pointer: " << *stringPTR << std::endl;
    std::cout << "Content of the string using the reference: " << stringREF << std::endl;

    return 0;
}